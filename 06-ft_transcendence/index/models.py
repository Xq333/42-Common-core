from django.db import models
from django.contrib.auth.models import AbstractUser
from django.conf import settings


class User(AbstractUser):
    status = models.CharField(max_length=50, null=True, default='offline')
    last_seen = models.DateTimeField(null=True, blank=True)
    avatar = models.ImageField(
        upload_to='avatars/', default='avatars/default.jpeg')
    pseudo = models.CharField(max_length=128, verbose_name="pseudo",
                              null=False, unique=True, default="Undefined by me")
    # match_history = models.ManyToManyField(
        # 'Match', blank=True, related_name='users')
    email = models.EmailField(max_length=254, verbose_name='email address',
                              unique=True, default="Ihavenoemail@gmail.com")
    winrate = models.IntegerField(default=0)
    nb_match = models.IntegerField(default=0)
    nb_victory = models.IntegerField(default=0)
    tournament_win = models.IntegerField(default=0)
    anonymous_mode = models.BooleanField(default=False)


# USERNAME_FIELD specifies the unique identifier for the User model.
    USERNAME_FIELD = 'username'
# REQUIRED_FIELDS specifies a list of the required fields when creating a user via the createsuperuser command.
    REQUIRED_FIELDS = []

    def __str__(self):
        return self.username


class Match(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE, related_name='matches', default=1)
    score = models.CharField(default="10-0")
    opponent = models.CharField(max_length=200, null=True)
    date = models.DateTimeField(auto_now_add=True)
    victory = models.BooleanField(default=False)

    def __str__(self):
        return f"Me vs {self.opponent} - {self.score} - {self.date}"


class Tournament(models.Model):
    name = models.CharField(max_length=200, null=False)
    status = models.CharField(max_length=50, null=True, default='filling')
    player1 = models.ForeignKey(settings.AUTH_USER_MODEL, related_name='player1', on_delete=models.CASCADE, null=True)
    player2 = models.ForeignKey(settings.AUTH_USER_MODEL, related_name='player2', on_delete=models.CASCADE, null=True)
    player3 = models.ForeignKey(settings.AUTH_USER_MODEL, related_name='player3', on_delete=models.CASCADE, null=True)
    player4 = models.ForeignKey(settings.AUTH_USER_MODEL, related_name='player4', on_delete=models.CASCADE, null=True)
    winners = models.IntegerField(default=0)
    losers = models.IntegerField(default=0)
    winner1 = models.CharField(max_length=200, null=True)
    winner2 = models.CharField(max_length=200, null=True)