# from channels.routing import ProtocolTypeRouter, URLRouter
from django.urls import path
from . import consumers

websocket_urlpatterns = [
    path('ws/tournament/<str:room_name>', consumers.tournamentConsumer.as_asgi()),
    path('ws/game/<str:p1>/<str:p2>', consumers.gameConsumer.as_asgi()),
    path('ws/matchmaking', consumers.lobbyConsumer.as_asgi()),
]
