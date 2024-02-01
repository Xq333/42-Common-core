import os
from django.core.asgi import get_asgi_application
from channels.routing import ProtocolTypeRouter, URLRouter
from channels.auth import AuthMiddlewareStack
from game.routing import websocket_urlpatterns

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'ft_transcendence.settings')

# application = get_asgi_application()

# ProtocolTypeRouter est le point d'entrée de Channels.
# Il permet de définir quel type de connexion est utilisé.
# http pour les requêtes HTTP classiques et websocket pour les connexions websocket.
# AuthMiddlewareStack permet d'accéder aux informations de l'utilisateur connecté dans les consumers.

application = ProtocolTypeRouter({
    "http": get_asgi_application(),
    "websocket": AuthMiddlewareStack(
        URLRouter(
            websocket_urlpatterns
        )
    ),
})

# envoi en direct : paddle
# envoi quand points : score
