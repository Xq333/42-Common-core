# Generated by Django 4.2.8 on 2023-12-06 10:57

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Friendship',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('created', models.DateTimeField(auto_now_add=True)),
            ],
        ),
        migrations.CreateModel(
            name='Notification',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('notification_type', models.CharField(choices=[('friend_request', 'Friend Request'), ('friend_accept', 'Friend Accept'), ('friend_decline', 'Friend Decline'), ('match_request', 'Match Request'), ('achievement', 'Achievement')], max_length=50)),
                ('status', models.CharField(choices=[('sent', 'Sent'), ('pending', 'Pending'), ('accepted', 'Accepted'), ('declined', 'Declined')], default='sent', max_length=50)),
                ('message', models.TextField(blank=True, null=True)),
                ('created_at', models.DateTimeField(auto_now_add=True)),
                ('updated_at', models.DateTimeField(auto_now=True)),
            ],
        ),
    ]
