from django.shortcuts import render, redirect
from .forms import RegisterForm
from django.http import JsonResponse, HttpResponse
from django.contrib.auth import authenticate
from .models import User
from friends.models import Notification
from .services import get_nb_trophies, get_trophies_images, get_match_history, save_user_avatar_from_url, username_ends_with_42
from django.conf import settings
import urllib
import json
from django.views.decorators.csrf import csrf_exempt
from django.views.decorators.csrf import csrf_protect
from django.http import HttpResponseNotFound

# Cybersecurity
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework.permissions import IsAuthenticated
from rest_framework.decorators import api_view, permission_classes
from rest_framework_simplejwt.tokens import RefreshToken
from django_otp.plugins.otp_totp.models import TOTPDevice
import qrcode
from io import BytesIO
import base64
import binascii


def index(request):
    notification_count = 0
    if request.user.is_authenticated:
        notification_count = Notification.objects.filter(
            receiver=request.user).count()
    return render(request, 'index.html', {'notification_count': notification_count})


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def socket(request, p1, p2):
    userp1 = User.objects.get(username=p1)
    userp2 = User.objects.get(username=p2)
    context = {
        'p1': userp1,
        'p2': userp2,
    }
    if userp1.anonymous_mode is True:
        context['p1'].pseudo = 'Anonyme'
    if userp2.anonymous_mode is True:
        context['p2'].pseudo = 'Anonyme'
    return render(request, 'socket.html', context)


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def lobbySocket(request):
    return render(request, 'matchqueue.html')


@api_view(['GET', 'POST', 'PUT'])
def updateStatus(request, user_id):
    data = json.loads(request.body)
    if request.method == 'PUT':
        user = User.objects.get(id=user_id)
        user.status = data.get('status')
        user.save()
        user = User.objects.get(id=user_id)
        return JsonResponse({'status': 'success', 'message': 'Status updated!'})
    return JsonResponse({'status': 'fail', 'message': 'Invalid request...'})


@api_view(['GET', 'POST', 'PUT'])
@csrf_exempt
def registerView(request):
    if request.method == 'POST':
        form = RegisterForm(request.POST)
        if form.is_valid():
            User.objects.create_user(username=form.cleaned_data['username'],
                                     pseudo=form.cleaned_data['pseudo'],
                                     email=form.cleaned_data['email'],
                                     password=form.cleaned_data['password'])
        else:
            errors = {field: error.get_json_data()[0]['message']
                      for field, error in form.errors.items()}
            return JsonResponse({'status': 'fail', 'message': 'Invalid registration', 'errors': errors})
        return JsonResponse({'status': 'success', 'message': 'You successfully registered!'})
    return JsonResponse({'status': 'fail', 'message': 'Invalid request...'})


@api_view(['POST', 'GET'])
@csrf_exempt
def loginView(request):
    username = request.data.get('username')
    password = request.data.get('password')

    user = authenticate(username=username, password=password)

    if user is not None:
        if TOTPDevice.objects.filter(user=user, confirmed=True).exists():
            return Response({
                'status': 'two_factor_required',
                'message': 'OTP required for login.',
                'user_id': user.id,
                'username': user.username
            })
        else:
            refresh = RefreshToken.for_user(user)
            user.status = 'online'
            user.save()
            return Response({
                'status': 'success',
                'message': 'You successfully logged in!',
                'refresh': str(refresh),
                'access': str(refresh.access_token),
                'user_id': user.id,
                'username': user.username
            })
    else:
        return Response({'status': 'fail', 'message': 'Invalid credentials...'}, status=401)


@api_view(['GET', 'POST', 'PUT', 'DELETE'])
@permission_classes([IsAuthenticated])
def logoutView(request):
    request.user.status = 'offline'
    request.user.save()
    return JsonResponse({'status': 'success', 'message': 'Logged out successfully.'})


@csrf_exempt
def logoutBeacon(request):
    data = json.loads(request.body)
    user = User.objects.get(id=data)
    user.status = 'offline'
    user.save()
    return JsonResponse({'status': 'success', 'message': 'Logged out successfully.'})


@api_view(['POST'])
@permission_classes([IsAuthenticated])
def anonymize(request):
    user = request.user
    if request.method == 'POST':
        if not user.anonymous_mode:
            user.anonymous_mode = True
        else:
            user.anonymous_mode = False
        user.save()
        return JsonResponse({'status': 'success', 'message': 'Mode anonyme mis à jour.'})
    else:
        return JsonResponse({'status': 'error', 'message': 'Invalid request'}, status=400)


@api_view(['POST', 'DELETE'])
@csrf_protect
@permission_classes([IsAuthenticated])
def deleteAccount(request):
    user = request.user
    user.delete()
    return JsonResponse({'status': 'success', 'message': 'Account deleted successfully'})


def get_42keys(request):
    return JsonResponse({'clientkey': settings.SOCIAL_AUTH_42_KEY, 'ruri': settings.SOCIAL_AUTH_42_RURI})


def auth_42(request):
    code = request.GET.get('code')
    token_url = "https://api.intra.42.fr/oauth/token/"
    token_data = {
        "client_id": settings.SOCIAL_AUTH_42_KEY,
        "client_secret": settings.SOCIAL_AUTH_42_SECRET,
        "code": code,
        "redirect_uri": settings.SOCIAL_AUTH_42_RURI,
        "grant_type": "authorization_code",
    }
    data = urllib.parse.urlencode(token_data).encode()
    req = urllib.request.Request(token_url, data=data, method='POST')
    with urllib.request.urlopen(req) as response:
        response_body = response.read()
        access_token_data = json.loads(response_body.decode('utf-8'))
        access_token = access_token_data.get("access_token")

        def get_user_info(access_token):
            api_url = "https://api.intra.42.fr/v2/me"
            headers = {"Authorization": f"Bearer {access_token}"}
            req = urllib.request.Request(api_url, headers=headers)
            try:
                with urllib.request.urlopen(req) as response:
                    if response.status == 200:
                        user_info = json.loads(response.read().decode('utf-8'))
                        return user_info
            except urllib.error.URLError as e:
                print(
                    f"Error getting user info: {e}")
            return None

    user_info = get_user_info(access_token)
    if user_info is not None:
        if User.objects.filter(username=user_info['login'] + "_42").exists():
            user = User.objects.get(username=user_info['login'] + "_42")
            refresh = RefreshToken.for_user(user)
            user.status = 'online'
            user.save()
            jwt_token = str(refresh.access_token).replace(
                '\'', '\\\'').replace('\"', '\\\"')
            return HttpResponse(f"""
                <!DOCTYPE html>
                <html>
                    <body>
                        <script>
                            localStorage.setItem('jwt_token', '{jwt_token}');
                            localStorage.setItem("userId", '{user.id}');
                            localStorage.setItem("username", '{user.username}');
                            localStorage.setItem("42", "42");
                            window.location.href = '/';
                        </script>
                    </body>
                </html>
            """)
        else:
            user = User.objects.create_user(username=user_info['login'] + "_42",
                                            pseudo=user_info['login'] + "_42",
                                            email=user_info['email'])
            save_user_avatar_from_url(
                user, user_info['image']['versions']['medium'])
            refresh = RefreshToken.for_user(user)
            user.status = 'online'
            user.save()
            jwt_token = str(refresh.access_token).replace(
                '\'', '\\\'').replace('\"', '\\\"')
            return HttpResponse(f"""
                <html>
                    <body>
                        <script>
                           localStorage.setItem('jwt_token', '{jwt_token}');
                            localStorage.setItem("userId", '{user.id}');
                            localStorage.setItem("username", '{user.username}');
                            localStorage.setItem("42", "42");
                            window.location.href = '/';
                        </script>
                    </body>
                </html>
            """)
    else:
        print("Error getting user info")
    return redirect('/')


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def loadProfile(request):
    user = request.user
    is_2fa_enabled = TOTPDevice.objects.filter(
        user=user, confirmed=True).exists()

    context = {
        'user': user,
        'image_url': user.avatar.url,
        'trophees': get_nb_trophies(user),
        'trophies_images': get_trophies_images(user),
        'match_history': get_match_history(user),
        'username_ends_with_42': username_ends_with_42(user.username),
        'is_2fa_enabled': is_2fa_enabled
    }
    return render(request, 'profile.html', context)


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def profileForm(request):
    context = {'user': request.user}
    return render(request, 'profileForm.html', context)


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def passForm(request):
    context = {'user': request.user}
    return render(request, 'passwordForm.html', context)


@api_view(['GET'])
@permission_classes([IsAuthenticated])
def twoFAForm(request):
    device, created = TOTPDevice.objects.get_or_create(
        user=request.user,
        defaults={'name': 'default', 'confirmed': False}
    )
    totp_uri = device.config_url

    qr = qrcode.QRCode(
        version=1,
        error_correction=qrcode.constants.ERROR_CORRECT_L,
        box_size=10,
        border=4,
    )
    qr.add_data(totp_uri)
    qr.make(fit=True)
    img = qr.make_image(fill_color="black", back_color="white")

    buffered = BytesIO()
    img.save(buffered, format="PNG")
    img_str = base64.b64encode(buffered.getvalue()).decode()

    hex_key = device.key
    byte_key = binascii.unhexlify(hex_key)
    secret_key = base64.b32encode(byte_key).decode()
    context = {'qr_code': img_str,
               'user': request.user, 'secret_key': secret_key}

    return render(request, 'twoFAForm.html', context)


@api_view(['GET'])
@permission_classes([IsAuthenticated])
def disableTwoFAForm(request):
    return render(request, 'disableTwoFAForm.html')


@api_view(['GET', 'POST'])
@permission_classes([IsAuthenticated])
def avatarForm(request):
    context = {'user': request.user}
    return render(request, 'avatarForm.html', context)


class SecureAPIView(APIView):
    permission_classes = [IsAuthenticated]

    def get(self, request):
        return Response({"message": "This endpoint is secure and requires a valid JWT token."})


@api_view(['GET'])
@permission_classes([IsAuthenticated])
def secure_jwt_view(request):
    return Response({"message": "This endpoint is secure."})


@api_view(['POST'])
@permission_classes([IsAuthenticated])
def create_totp_device(user, name='default'):
    if not TOTPDevice.objects.filter(user=user, name=name).exists():
        device = TOTPDevice.objects.create(
            user=user, name=name, confirmed=False)
        return device
    return None


@api_view(['GET'])
@permission_classes([IsAuthenticated])
def get_totp_uri(device):
    return device.config_url()


@api_view(['POST'])
@permission_classes([IsAuthenticated])
def verify_otp(user, token):
    device = TOTPDevice.objects.filter(user=user, confirmed=True).first()
    if device:
        return device.verify_token(token)
    return False


@api_view(['POST'])
@permission_classes([IsAuthenticated])
def confirm_device(user):
    device = TOTPDevice.objects.filter(user=user, confirmed=False).first()
    if device:
        device.confirmed = True
        device.save()


@api_view(['POST'])
def verify_otp_view(request):
    user_id = request.data.get('user_id')
    otp_token = request.data.get('otp_token')
    user = User.objects.get(id=user_id)

    if user is not None and user.is_active:
        device = TOTPDevice.objects.filter(user=user, confirmed=True).first()
        if device and device.verify_token(otp_token):
            refresh = RefreshToken.for_user(user)
            user.status = 'online'
            user.save()
            return Response({
                'status': 'success',
                'message': '2FA verification successful.',
                'refresh': str(refresh),
                'access': str(refresh.access_token),
            })
        else:
            return Response({'status': 'fail', 'message': 'Invalid OTP.'}, status=400)


@api_view(['POST'])
@permission_classes([IsAuthenticated])
def activate_2fa(request):
    user = request.user

    try:
        otp_token = request.data.get('otp_token')
        if user is not None and user.is_active:
            device = TOTPDevice.objects.filter(
                user=user, confirmed=False).first()
            if device and device.verify_token(otp_token):
                device.confirmed = True
                device.save()
                return Response({'status': 'success', 'message': '2FA activated successfully.'})
            else:
                return Response({'status': 'fail', 'message': 'Invalid OTP.'}, status=400)
    except Exception as e:
        return Response({'status': 'fail', 'message': str(e)}, status=500)


@api_view(['GET'])
@permission_classes([IsAuthenticated])
def two_fa_status(request):
    is_2fa_enabled = TOTPDevice.objects.filter(
        user=request.user, confirmed=True).exists()
    return Response({'is_2fa_enabled': is_2fa_enabled})


@api_view(['POST'])
@permission_classes([IsAuthenticated])
def deactivate_2fa(request):
    user = request.user
    otp_token = request.data.get('otp_token')

    device = TOTPDevice.objects.filter(user=user, confirmed=True).first()
    if device and device.verify_token(otp_token):
        device.confirmed = False
        device.save()
        return Response({'status': 'success', 'message': '2FA deactivated successfully.'})
    return Response({'status': 'fail', 'message': 'Invalid OTP.'}, status=400)


def custom_404(request, exception):
    with open('static/assets/error404.png', 'rb') as image:
        return HttpResponseNotFound(image.read(), content_type='image/png')
