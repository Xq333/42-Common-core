from django.db import models
from django.conf import settings
from index.models import User


class Friendship(models.Model):
    user = models.ForeignKey(
        settings.AUTH_USER_MODEL, related_name='friendships',
        on_delete=models.CASCADE)
    friend = models.ForeignKey(
        settings.AUTH_USER_MODEL, related_name='friends',
        on_delete=models.CASCADE)

    created = models.DateTimeField(auto_now_add=True)

    class Meta:
        unique_together = ('user', 'friend')

    def __str__(self):
        return f"{self.user} est ami avec {self.friend}"


class Notification(models.Model):
    TYPE_CHOICES = (
        ('friend_request', 'Friend Request'),
        ('friend_accept', 'Friend Accept'),
        ('friend_decline', 'Friend Decline'),
        ('match_request', 'Match Request'),
        ('achievement', 'Achievement'),
    )

    STATUS_CHOICES = (
        ('sent', 'Sent'),
        ('pending', 'Pending'),
        ('accepted', 'Accepted'),
        ('declined', 'Declined'),
    )

    notification_type = models.CharField(max_length=50, choices=TYPE_CHOICES)
    sender = models.ForeignKey(
        User, related_name='sent_notifications', on_delete=models.CASCADE)
    receiver = models.ForeignKey(
        User, related_name='received_notifications', on_delete=models.CASCADE)
    status = models.CharField(
        max_length=50, choices=STATUS_CHOICES, default='sent')
    message = models.TextField(blank=True, null=True)
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)

    def __str__(self):
        return f"{self.sender} a envoyé une notification à {self.receiver}"
