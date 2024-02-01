from django.contrib import admin
from django.urls import path, include
from django.conf import settings
from django.conf.urls.static import static

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', include('index.urls')),
    path('friends/', include('friends.urls')),
    path('api/', include('api.urls')),
    path('game/', include('game.urls')),

]

handler404 = 'index.views.custom_404'

# Cette configuration permet à Django de servir les fichiers médias durant le développement.
# En production, il est recommandé de laisser un serveur web comme Nginx ou Apache servir ces fichiers.
if settings.DEBUG:
    urlpatterns += static(settings.MEDIA_URL,
                          document_root=settings.MEDIA_ROOT)
