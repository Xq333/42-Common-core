# Generated by Django 4.2.8 on 2023-12-28 08:58

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('index', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='user',
            name='anonymous_mode',
            field=models.BooleanField(default=False),
        ),
    ]