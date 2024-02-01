from django.forms import ModelForm
from django import forms
from django.contrib.auth.hashers import check_password
from django.core.exceptions import ValidationError
from .models import User


class ValidUserformFormat(ModelForm):
    def clean_username(self):
        username = self.cleaned_data['username']
        if User.objects.filter(username=username).exists():
            raise ValidationError('Username already in use.')
        if username.endswith('_42'):
            raise ValidationError('Username cannot end with _42.')
        return username

    def clean_pseudo(self):
        pseudo = self.cleaned_data['pseudo']
        if User.objects.filter(pseudo=pseudo).exists():
            raise ValidationError('Pseudo already in use.')
        if pseudo.endswith('_42'):
            raise ValidationError('Pseudo cannot end with _42.')
        return pseudo

    def clean_email(self):
        email = self.cleaned_data['email']
        if User.objects.filter(email=email).exists():
            raise ValidationError('Email already in use.')
        if email.endswith('@student.42nice.fr'):
            raise ValidationError('Email cannot be a 42 student mail.')
        return email

    def clean_password(self):
        password = self.cleaned_data['password']
        if len(password) < 8:
            raise ValidationError(
                'Password must be at least 8 characters long.')

        if not any(char.isdigit() for char in password):
            raise ValidationError(
                'Password must contain at least one digit.')

        if not any(char.isupper() for char in password):
            raise ValidationError(
                'Password must contain at least one uppercase letter.')

        if not any(char.islower() for char in password):
            raise ValidationError(
                'Password must contain at least one lowercase letter.')

        special_characters = "[~\!@#\$%\^&\*\(\)_\+{}\":;'<>?,./]"
        if not any(char in special_characters for char in password):
            raise ValidationError(
                'Password must contain at least one special character.')
        return password


class RegisterForm(ValidUserformFormat):
    class Meta:
        model = User
        fields = ['username', 'pseudo', 'email', 'password']


class LoginForm(ModelForm):
    class Meta:
        model = User
        fields = ['username', 'password']


class ProfileForm(forms.ModelForm):
    class Meta:
        model = User
        fields = ['username', 'pseudo', 'email']

    def clean_username(self):
        username = self.cleaned_data['username']
        if username != self.instance.username:  # Check if the username has been changed
            # Check if the new username already exists
            if User.objects.filter(username=username).exists():
                raise ValidationError(
                    "This username is already taken. Please choose another.")
        return username

    def clean_pseudo(self):
        pseudo = self.cleaned_data['pseudo']
        if pseudo != self.instance.pseudo:  # Check if the username has been changed
            # Check if the new username already exists
            if User.objects.filter(pseudo=pseudo).exists():
                raise ValidationError(
                    "This pseudo is already taken. Please choose another.")
        return pseudo

    def clean_email(self):
        email = self.cleaned_data['email']
        if email != self.instance.email:  # Check if the email has been changed
            # Check if the new email already exists
            if User.objects.filter(email=email).exists():
                raise ValidationError(
                    "This email is already in use/or the format is wrong. Please choose another.")
        return email

    def clean(self):
        cleaned_data = super().clean()
        # Additional custom validation can go here
        return cleaned_data


class PassForm(forms.Form):
    password = forms.CharField(widget=forms.PasswordInput())
    new_password = forms.CharField(widget=forms.PasswordInput())
    confirm_password = forms.CharField(widget=forms.PasswordInput())

    def __init__(self, *args, **kwargs):
        self.user = kwargs.pop('user', None)
        super(PassForm, self).__init__(*args, **kwargs)

    def clean(self):
        cleaned_data = super().clean()
        password = cleaned_data.get('password')
        new_password = cleaned_data.get('new_password')
        confirm_password = cleaned_data.get('confirm_password')

        if not check_password(password, self.user.password):
            self.add_error('password', "Old password incorrect.")

        if password == new_password:
            self.add_error(
                'new_password', "The new password must be different from the old one.")

        if new_password != confirm_password:
            self.add_error('confirm_password',
                           "The passwords do not match.")
        if len(password) < 8:
            raise ValidationError(
                'Password must be at least 8 characters long.')

        if not any(char.isdigit() for char in password):
            raise ValidationError(
                'Password must contain at least one digit.')

        if not any(char.isupper() for char in password):
            raise ValidationError(
                'Password must contain at least one uppercase letter.')

        if not any(char.islower() for char in password):
            raise ValidationError(
                'Password must contain at least one lowercase letter.')

        special_characters = "[~\!@#\$%\^&\*\(\)_\+{}\":;'<>?,./]"
        if not any(char in special_characters for char in password):
            raise ValidationError(
                'Password must contain at least one special character.')
        return cleaned_data


class AvatarForm(ModelForm):
    class Meta:
        model = User
        fields = ['avatar']

    def clean_avatar(self):
        avatar = self.cleaned_data.get('avatar')
        if avatar:
            if not avatar.name.lower().endswith(('.jpg', '.png', '.jpeg')):
                raise forms.ValidationError("The file is not an image.")
        return avatar
