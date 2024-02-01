# create url patterns for the app

from django.urls import path
from . import views

# Cybersecurity
from rest_framework_simplejwt.views import (
    TokenObtainPairView,
    TokenRefreshView,
)

urlpatterns = [
    path('', views.index, name='index'),
    path('register/', views.registerView, name='register'),
    path('login/', views.loginView, name='login'),
    path('logout/', views.logoutView, name='logout'),
    path('logout-beacon/', views.logoutBeacon, name='logout-beacon'),

    path('update-status/<int:user_id>',
         views.updateStatus, name='update-status'),

    path('auth/42/callback/', views.auth_42, name='auth-42'),
    path('get-42keys/', views.get_42keys, name='get-42keys'),

    path('profile/', views.loadProfile, name='profile'),
    path('profileForm/', views.profileForm, name='profileForm'),
    path('passForm/', views.passForm, name='passForm'),
    path('avatarForm/', views.avatarForm, name='avatarForm'),


    path('ws/game/<str:p1>/<str:p2>', views.socket, name='socket'),
    path('ws/matchmaking', views.lobbySocket, name='lobbySocket'),

    # Cybersecurity : JWT Auth endpoints.
    path('api/token/', TokenObtainPairView.as_view(), name='token_obtain_pair'),
    path('api/token/refresh/', TokenRefreshView.as_view(), name='token_refresh'),
    path('secure-jwt/', views.secure_jwt_view, name='secure-jwt-view'),

    path('twoFAForm/', views.twoFAForm, name='twoFAForm'),
    path('disableTwoFAForm/', views.disableTwoFAForm, name='disableTwoFAForm'),
    path('verify-otp/', views.verify_otp_view, name='verify-otp'),
    path('activate-2fa/', views.activate_2fa, name='activate-2fa'),
    path('api/2fa_status/', views.two_fa_status, name='two_fa_status'),
    path('api/deactivate-2fa/', views.deactivate_2fa, name='deactivate-2fa'),
    path('deleteAccount/', views.deleteAccount, name='deleteAccount'),
    path('anonymize/', views.anonymize, name='anonymize'),
]
