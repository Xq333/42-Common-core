from django.shortcuts import render, get_object_or_404
from django.http import JsonResponse
from index.models import User
from friends.models import Notification, Friendship
import json
from django.db.models import Q
from django.core.exceptions import ObjectDoesNotExist
# Cybersecurity
from rest_framework.permissions import IsAuthenticated
from rest_framework.decorators import api_view, permission_classes


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def friends(request):
    return render(request, 'friendlist.html')


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def friendProfile(request, user_id):
    user = get_object_or_404(User, pk=user_id)
    pseudo = user.pseudo
    if user.anonymous_mode is True:
        pseudo = "Anonymous"
    data = {
        "avatar": user.avatar.url,
        "pseudo": pseudo,
        "nb_match": user.nb_match,
        "winrate": user.winrate,
    }
    return JsonResponse(data, safe=False)


@api_view(['GET', 'POST', 'PUT', 'DELETE'])
@permission_classes([IsAuthenticated])
def friendRequestView(request, user_id):
    data = json.loads(request.body)
    if request.method == 'POST':
        receiver = User.objects.get(pk=user_id)
        Notification.objects.create(
            sender=request.user,
            receiver=receiver,
            message=data.get('message'),
            notification_type=data.get('notificationType'),
        )
        return JsonResponse({'status': 'success'})

    elif request.method == 'PUT':
        notification_id = data.get('notificationId')
        notification = Notification.objects.get(pk=notification_id)
        notification.status = data.get('status')
        notification.message = data.get('message')
        notification.sender = notification.receiver
        notification.receiver = User.objects.get(pk=user_id)
        notification.save()
        if notification.status == 'accepted':
            Friendship.objects.create(
                user=notification.sender,
                friend=notification.receiver
            )
            Friendship.objects.create(
                user=notification.receiver,
                friend=notification.sender
            )
        elif notification.status == 'rejected':
            notification.delete()
        return JsonResponse({'status': 'success'})

    elif request.method == 'DELETE':
        notification_id = data.get('notificationId')
        try:
            notification = Notification.objects.get(pk=notification_id)
            if notification is not None:
                notification.delete()
                return JsonResponse({'status': 'success'})
        except ObjectDoesNotExist:
            return JsonResponse({'status': 'NoNotif'})
        return JsonResponse({'status': 'error'}, status=405)


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def fightRequestView(request, user_id):
    data = json.loads(request.body)
    if request.method == 'POST':
        receiver = User.objects.get(pk=user_id)
        Notification.objects.create(
            sender=request.user,
            receiver=receiver,
            message=data.get('message'),
            notification_type=data.get('notificationType'),
        )
    return JsonResponse({'status': 'success'})


@api_view(['GET', 'POST', 'DELETE'])
@permission_classes([IsAuthenticated])
def deleteNotificationView(request, notification_id):
    if request.method == 'DELETE':
        try:
            notification = Notification.objects.get(pk=notification_id)
            if notification is not None:
                notification.delete()
                return JsonResponse({'status': 'success'})
        except ObjectDoesNotExist:
            return JsonResponse({'status': 'NoNotif'})
    else:
        return JsonResponse({'status': 'error'}, status=405)


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def notificationsView(request):
    if request.method == 'GET':
        notifications = Notification.objects.filter(
            receiver=request.user).order_by('-updated_at')
        data = [{"sender": notification.sender.username,
                 "notification_type": notification.notification_type,
                 "status": notification.status,
                 "message": notification.message,
                 "id": notification.id} for notification in notifications]
        return JsonResponse(data, safe=False)
    else:
        return JsonResponse({'status': 'error'}, status=405)


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def listFriendsView(request, user_id):

    user = get_object_or_404(User, pk=user_id)

    friends_as_user = user.friendships.all()

    all_friends = set()
    for friendship in friends_as_user:
        all_friends.add(friendship.friend)

    friends_data = [{"username": friend.username,
                     "status": friend.status} for friend in all_friends]
    return JsonResponse(friends_data, safe=False)


@api_view(['GET', 'POST', 'DELETE'])
@permission_classes([IsAuthenticated])
def deleteFriendView(request, user_id):
    if request.method == 'DELETE':
        friend = User.objects.get(pk=user_id)
        friendship = Friendship.objects.filter(
            Q(user=request.user, friend=friend)
            | Q(user=friend, friend=request.user))
        friendship.delete()
        return JsonResponse({'status': 'success'})
    else:
        return JsonResponse({'status': 'error'}, status=405)
