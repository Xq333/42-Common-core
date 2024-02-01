from django.urls import path
from . import views

urlpatterns = [
    # autres routes...
    path('apropos-data', views.apropos_data, name='apropos-data'),
    path('contact-data', views.contact_data, name='contact-data'),

    path('profile-data', views.profile_data, name='profile-data'),
    path('submit-profile', views.submit_profile, name='submit-profile'),
    path('submit-pass', views.submit_pass, name='submit-pass'),
    path('submit-avatar', views.submit_avatar, name='submit-avatar'),
    path('match-history', views.match_history, name='match-history'),

    path('all-users', views.all_users, name='all-users'),
    path('user-data-username/<str:user_username>',
         views.user_data_by_username, name='user-data-username'),
    path('all-friendships', views.all_friendships, name='all-frienships'),
    path('all-notifications', views.all_notifications,
         name='all-notifications'),
]
