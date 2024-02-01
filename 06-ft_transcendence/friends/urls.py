# create url patterns for the app

from django.urls import path
from . import views

urlpatterns = [
    path('', views.friends, name='testons'),
    path('profile/<int:user_id>', views.friendProfile, name='profile'),

    path('<int:user_id>/', views.listFriendsView, name='listFriends'),
    path('friend-request/<int:user_id>',
         views.friendRequestView, name='friend-request'),
    path('delete-friend/<int:user_id>',
         views.deleteFriendView, name='delete-friend'),

    path('fight-request/<int:user_id>',
         views.fightRequestView, name='fight-request'),

    path('notifications/', views.notificationsView, name='notifications'),
    path('delete-notification/<int:notification_id>',
         views.deleteNotificationView, name='delete-notification'),

    # path('heartbeat/', views.heartbeat, name='heartbeat'),
]
