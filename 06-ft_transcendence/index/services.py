import urllib.request
from django.core.files.base import ContentFile
from index.models import Match


def username_ends_with_42(username):
    return username.endswith('_42')


def save_user_avatar_from_url(user, url):
    parsed_url = urllib.parse.urlparse(url)
    if parsed_url.path.lower().endswith(('.png', '.jpg', '.jpeg')):
        with urllib.request.urlopen(url) as response:
            image_content = response.read()
            user.avatar.save(user.username + "_avatar.jpg",
                             ContentFile(image_content), save=True)
    else:
        print("Wrong URL")


def get_nb_trophies(user):
    trophees = 0

    if user.nb_victory >= 1:
        trophees += 1
    if user.nb_victory >= 10:
        trophees += 1
    if user.nb_victory >= 100:
        trophees += 1

    if user.tournament_win >= 1:
        trophees += 1
    if user.tournament_win >= 10:
        trophees += 1

    if user.nb_match >= 1:
        trophees += 1
    if user.nb_match >= 10:
        trophees += 1
    if user.nb_match >= 100:
        trophees += 1

    percentage = (100 / 8) * trophees
    return percentage


def get_trophies_images(user):
    imageT1played = "/static/assets/TrophieBlocked.png" if user.nb_match < 1 else "/static/assets/BronzeTrophie.png"
    imageT10played = "/static/assets/TrophieBlocked.png" if user.nb_match < 10 else "/static/assets/SilverTrophie.png"
    imageT100played = "/static/assets/TrophieBlocked.png" if user.nb_match < 100 else "/static/assets/GoldenTrophie.png"
    imageT1win = "/static/assets/TrophieBlocked.png" if user.nb_victory < 1 else "/static/assets/BronzeTrophie.png"
    imageT10win = "/static/assets/TrophieBlocked.png" if user.nb_victory < 10 else "/static/assets/SilverTrophie.png"
    imageT100win = "/static/assets/TrophieBlocked.png" if user.nb_victory < 100 else "/static/assets/GoldenTrophie.png"
    imageT1tournament = "/static/assets/TrophieBlocked.png" if user.tournament_win < 1 else "/static/assets/SilverTrophie.png"
    imageT10tournament = "/static/assets/TrophieBlocked.png" if user.tournament_win < 10 else "/static/assets/GoldenTrophie.png"
    return {
        'imageT1played': imageT1played,
        'imageT10played': imageT10played,
        'imageT100played': imageT100played,
        'imageT1win': imageT1win,
        'imageT10win': imageT10win,
        'imageT100win': imageT100win,
        'imageT1tournament': imageT1tournament,
        'imageT10tournament': imageT10tournament
    }


def get_match_history(user):
    match_qs = Match.objects.filter(user=user).order_by('-date')
    display_text = ""

    for match in match_qs:
        if match.victory:
            class_victory = "class-victory"
            win_or_lose = "You WON !!!"
        else:
            class_victory = "class-lost"
            win_or_lose = "You LOST ..."

        display_text += f'<div class= "cardhistory"><p class="{class_victory}"> Score: {match.score}, Adversaire: {match.opponent}, <strong>{win_or_lose}</strong> time: {match.date.strftime("%Y-%m-%d %H:%M")}</p></div>'

    data = {
        'title': 'Historique des matchs',
        'content': display_text,
        'winrate': user.winrate,
    }
    return data
