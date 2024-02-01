from django.contrib import admin

# Register your models here.

from .models import User, Match, Tournament

admin.site.register(User)
admin.site.register(Match)
admin.site.register(Tournament)
