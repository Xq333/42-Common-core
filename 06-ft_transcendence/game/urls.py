from django.urls import path
from . import views

urlpatterns = [
    path('add-match', views.add_match, name='add-match'),
    path('game-menu', views.load_menu, name='game-menu'),
    path('tournament-menu', views.tournament_menu, name='tournament-menu'),
    path('check-tournament', views.check_or_create_tournament, name='check-tournament'),
    path('join-tournament', views.join_tournament, name='join-tournament'),
    path('leave-tournament', views.leave_tournament, name='leave-tournament'),
    path('check-winners', views.check_winners, name='check-winners'),
    path('add-winner', views.add_winner, name='add-winner'),
    path('tournament-win', views.tournament_win, name='tournament-win'),
    path('flash-message-tournament', views.flash_message_tournament, name='flash-message-tournament'),
]
