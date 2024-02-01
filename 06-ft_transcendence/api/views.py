from django.http import JsonResponse
from index.forms import ProfileForm, PassForm, AvatarForm
from index.models import User, Match
from friends.models import Notification, Friendship
from django.contrib.auth import update_session_auth_hash
# from django.views.decorators.csrf import csrf_protect
from django.db.models import Q

# Cybersecurity
# from rest_framework.views import APIView
# from rest_framework.response import Response
from rest_framework.permissions import IsAuthenticated
from rest_framework.decorators import api_view, permission_classes
# from rest_framework_simplejwt.tokens import RefreshToken


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def all_users(request):
    users = User.objects.all()
    users_data = [
        {
            'username': user.username,
            'pseudo': user.pseudo,
            'id': user.id,
            'avatar': user.avatar.url,
        }
        for user in users
    ]
    return JsonResponse(users_data, safe=False)


@api_view(['GET'])
@permission_classes([IsAuthenticated])
def user_data_by_username(request, user_username):
    user = User.objects.get(username=user_username)
    data = {
        'username': user.username,
        'pseudo': user.pseudo,
        'id': user.id,
        'avatar': user.avatar.url,
        'nb_match': user.nb_match,
        'nb_victory': user.nb_victory,
        'tournament_win': user.tournament_win,
    }
    return JsonResponse(data)


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def all_friendships(request):
    friendships = Friendship.objects.filter(user=request.user)
    friendships_data = [
        {
            'username': request.user.username,
            'friend': friendship.friend.username,
            'id': friendship.id,
        }
        for friendship in friendships
    ]
    return JsonResponse(friendships_data, safe=False)


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def all_notifications(request):
    notifs = Notification.objects.filter(
        Q(receiver=request.user) | Q(sender=request.user))
    notifs_data = [
        {
            'sender': notif.sender.username,
            'receiver': notif.receiver.username,
            'message': notif.message,
            'notification_type': notif.notification_type,
            'status': notif.status,
            'id': notif.id,
        }
        for notif in notifs
    ]
    return JsonResponse(notifs_data, safe=False)


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def apropos_data(request):
    data = {
        'title': 'À Propos de Nous',
        'content': [
            'The "ft_transcendence" project is an ambitious and multifaceted web development project focused on creating a unique online Pong game platform. ',
            'The project\'s primary goal is to enable users to play Pong in real-time multiplayer mode, enhancing their gaming experience with a visually appealing user interface.',
            'Here\'s a brief summary of the project\'s key components and requirements: Core Functionality, Technical Constraints, Modules, Security, Docker Use',
        ]
    }
    return JsonResponse(data)


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def contact_data(request):
    data = {
        'title': 'Contact us',
        'content': [
            'Veuillez prendre rendez-vous au xx-xx-xx-xx',
        ]
    }
    return JsonResponse(data)


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def profile_data(request):
    data = {
        'title': 'Who am I?',
        'content': [
            request.user.username,
            request.user.pseudo,
            request.user.email,
            request.user.avatar.url,
            request.user.nb_match,  # 4
            request.user.nb_victory,
            request.user.tournament_win,
            request.user.id,  # DEPLACEZ JAMAIS CA BANDE DE ZOB
        ]
    }
    return JsonResponse(data)


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def submit_profile(request):
    if request.method == 'POST':
        form = ProfileForm(request.POST, instance=request.user)
        if form.is_valid():
            user = form.save(commit=False)
            user.save()
            data = {'message': 'Profile updated with success.'}
            return JsonResponse(data)
        else:
            data = form.errors.as_text()
            return JsonResponse({'message': data})
    return JsonResponse({'status': 'error'})


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def submit_pass(request):
    if request.method == 'POST':
        form = PassForm(request.POST, user=request.user)
        if form.is_valid():
            user = request.user
            new_password = form.cleaned_data.get('new_password')
            user.set_password(new_password)
            user.save()
            update_session_auth_hash(request, user)
            return JsonResponse({'message': 'Password updated with success.'})
        else:
            data = form.errors.as_text()
            return JsonResponse({'message': data})
    return JsonResponse({'status': 'error'})


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def submit_avatar(request):
    if request.method == 'POST':
        form = AvatarForm(request.POST, request.FILES)
        if form.is_valid():
            user = request.user
            user.avatar = form.cleaned_data.get('avatar')
            user.save()
            return JsonResponse({'message': 'Avatar updated with success.'})
        else:
            data = form.errors.as_text()
            return JsonResponse({'message': data})
    return JsonResponse({'status': 'error'})


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def match_history(request):
    match_qs = Match.objects.filter(user=request.user).order_by('-date')
    match_list = [
        {
            'score': match.score,
            'opponent': match.opponent,
            'date': match.date.strftime("%d/%m/%Y %H:%M"),
            'victory': match.victory
        }
        for match in match_qs
    ]
    data = {
        'title': 'Historique des matchs',
        'content': match_list,
        'winrate': request.user.winrate,
    }
    return JsonResponse(data)
