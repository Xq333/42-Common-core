from django.shortcuts import render
from django.http import JsonResponse
from index.models import Match, User, Tournament
from django.views.decorators.csrf import csrf_protect
from django.shortcuts import get_object_or_404
from django.db.models import Q
from django.http import Http404
import uuid
import json

# Cybersecurity
from rest_framework.permissions import IsAuthenticated
from rest_framework.decorators import api_view, permission_classes


def load_menu(request):
    return render(request, 'menu.html')


def tournament_menu(request):
    return render(request, 'tournament.html')


@csrf_protect
@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def add_match(request):
    if request.method == 'POST':
        data = json.loads(request.body)
        if data.get('opponent') is None:
            return JsonResponse({'status': 'failed', 'message': 'Missing opponent'})
        check_user = User.objects.get(username=data.get('opponent'))
        if check_user is None or check_user. anonymous_mode is True:
            tmpopponent = "Anonymous"
        else:
            tmpopponent = data.get('opponent')
        match = Match(
            user=request.user,
            score=data.get('score'),
            opponent=tmpopponent,
            victory=data.get('victory'),
        )
    match.save()
    request.user.nb_match = request.user.nb_match + 1
    if match.victory:
        request.user.nb_victory = request.user.nb_victory + 1
    request.user.winrate = request.user.nb_victory / request.user.nb_match * 100
    request.user.save()
    user_matches = Match.objects.filter(user=request.user).order_by('date')
    if user_matches.count() > 7:
        oldest_match = user_matches.first()

        oldest_match.delete()
    return JsonResponse({'message': 'Match ajouté avec succès.'})


@csrf_protect
@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def check_or_create_tournament(request):
    tournaments = Tournament.objects.filter(
        Q(player1__isnull=True) |
        Q(player2__isnull=True) |
        Q(player3__isnull=True) |
        Q(player4__isnull=True),
        status='filling'
    )

    if tournaments.exists():
        tournament = tournaments.first()
        return JsonResponse({
            'status': 'success',
            'message': 'Tournament found with available space.',
            'tournament_id': tournament.name
        })

    new_tournament = Tournament.objects.create(
        name=f"Tournament-{uuid.uuid4()}",
        status='filling'
    )
    if new_tournament is None:
        return JsonResponse({
            'status': 'failed',
            'message': 'Failed to create new tournament.'
        })
    return JsonResponse({
        'status': 'success',
        'message': 'New tournament created.',
        'tournament_id': new_tournament.name
    })


@csrf_protect
@api_view(['POST'])
@permission_classes([IsAuthenticated])
def join_tournament(request):
    data = json.loads(request.body)
    tournament_id = data.get('tournament_id')
    tournament = get_object_or_404(Tournament, name=tournament_id)

    if tournament.player1 and tournament.player2 and tournament.player3 and tournament.player4:
        return JsonResponse({'status': 'failed', 'message': 'Tournament is full'})

    user = request.user
    if not tournament.player1:
        tournament.player1 = user
        player_id = 1
    elif not tournament.player2:
        tournament.player2 = user
        player_id = 2
    elif not tournament.player3:
        tournament.player3 = user
        player_id = 3
    elif not tournament.player4:
        tournament.player4 = user
        player_id = 4
        tournament.status = 'ready'
    else:
        return JsonResponse({'status': 'failed', 'message': 'No free space found'})

    tournament.save()

    return JsonResponse({'status': 'success', 'player_id': player_id, 'message': 'User successfully joined the tournament'})


@csrf_protect
@api_view(['PUT'])
@permission_classes([IsAuthenticated])
def leave_tournament(request):
    data = json.loads(request.body)
    tournament_id = data.get('tournament_id')
    user = request.user
    tournament = get_object_or_404(Tournament, name=tournament_id)

    if tournament.player1 == user:
        tournament.player1 = None
    elif tournament.player2 == user:
        tournament.player2 = None
    elif tournament.player3 == user:
        tournament.player3 = None
    elif tournament.player4 == user:
        tournament.player4 = None
    else:
        return JsonResponse({'status': 'failed', 'message': 'User not found in tournament'})

    if tournament.status == "ready" and user != tournament.winner1 and user != tournament.winner2:
        tournament.losers += 1
    tournament.save()
    return JsonResponse({'status': 'success', 'message': 'User successfully left the tournament'})


@csrf_protect
@api_view(['PUT'])
@permission_classes([IsAuthenticated])
def check_winners(request):
    data = json.loads(request.body)
    tournament_id = data.get('tournament_id')
    tournament = get_object_or_404(Tournament, name=tournament_id)
    if tournament is None:
        return JsonResponse({'status': 'failed', 'message': 'Tournament not found'})
    return JsonResponse({
        'status': 'success',
        'winners': tournament.winners,
        'losers': tournament.losers,
        'winner1': tournament.winner1,
        'winner2': tournament.winner2,
        'message': 'Found the tournament'})


@csrf_protect
@api_view(['PUT'])
@permission_classes([IsAuthenticated])
def add_winner(request):
    data = json.loads(request.body)
    tournament_id = data.get('tournament_id')
    tournament = get_object_or_404(Tournament, name=tournament_id)
    tournament.winners += 1
    if tournament.winners == 1:
        tournament.winner1 = request.user.username
    elif tournament.winners == 2:
        tournament.winner2 = request.user.username
    else:
        return JsonResponse({'status': 'error', 'message': 'Send goes wrong'})
    tournament.save()
    return JsonResponse({'status': 'success', 'message': 'Tournament updated'})


@csrf_protect
@api_view(['PUT'])
@permission_classes([IsAuthenticated])
def tournament_win(request):
    data = json.loads(request.body)
    tournament_id = data.get('tournament_id')
    tournament = get_object_or_404(Tournament, name=tournament_id)
    tournament.status = "finished"
    tournament.save()
    user = request.user
    user.tournament_win += 1
    user.save()
    return JsonResponse({'status': 'success', 'message': 'Tournament finished'})


@csrf_protect
@api_view(['PUT'])
@permission_classes([IsAuthenticated])
def flash_message_tournament(request):
    try:
        data = json.loads(request.body)
        tournament_id = data.get('tournament_id')
        tournament = get_object_or_404(Tournament, name=tournament_id)
        user1 = User.objects.get(username=tournament.player1)
        if user1.is_anonymous:
            user1.pseudo = "Anonymous"
        user2 = User.objects.get(username=tournament.player2)
        if user2.is_anonymous:
            user2.pseudo = "Anonymous"
        user3 = User.objects.get(username=tournament.player3)
        if user3.is_anonymous:
            user3.pseudo = "Anonymous"
        user4 = User.objects.get(username=tournament.player4)
        if user4.is_anonymous:
            user4.pseudo = "Anonymous"

        return render(request, 'flash_message_tournament.html', {'player1': user1, 'player2': user2, 'player3': user3, 'player4': user4})
    except Http404:
        return JsonResponse({'status': 'failed', 'message': 'Tournament not found'})
