// Fonction pour gérer la navigation sans rechargement et ajouter l'URL dans l'historique du navigateur

function navigate(event, path) {
  event.preventDefault();
  if (intervalID !== null && path !== "/notifs")
    removeLocalGameListeners();
  if (intervalID_g !== null && path !== "/notifs")
  {
    resetGameState_g();
    removeLocalGameListeners_g();
  }
  if (path !== "/notifs"
    && path !== "/login"
    && path !== "/register") {
    history.pushState(null, "", path);
  } else if (path === "/notifs") {
    loadNotifications();
    return;
  } else if (path === "/login") {
    loadLoginPage();
    return;
  } else if (path === "/register") {
    loadRegisterPage();
    return;
  }
  route();
}

// Gestion des différentes routes

function route() {
  const path = window.location.pathname;
  if (!localStorage.getItem('jwt_token') && path != '/' && path != '/login') {
    history.pushState(null, "", "/");
    window.location.href = '/'; // Rediriger vers la page de connexion
  }
  switch (path) {
    case "/apropos":
      closeNotifications();
    	loadAproposPage();
    	break;
    case "/login":
      closeNotifications();
    	loadLoginPage();
    	break;
    case "/logout":
      closeNotifications();
    	loadLogoutPage();
    	break;
    case "/register":
      closeNotifications();
    	loadRegisterPage();
    	break;
    case "/profile":
      closeNotifications();
      loadProfile();
      break;
    case "/passForm":
    case "/profileForm":
    case "/avatarForm":
      closeNotifications();
      loadProfileEdit(path);
      break;
    case "/twoFAForm":
      loadTwoFAForm();
      break;
    case "/disableTwoFAForm":
      loadDisableTwoFAForm();
      break;
    case "/accueil":
      closeNotifications();
      loadHomePage();
      break;
    case "/friends":
      loadFriendsPage();
      break;
    case "/game":
      closeNotifications();
      loadMenuPage();
      break;
    default:
      loadRegisterPage();
      break;
  }
}

// Differents submits pour les formulaires de l'index

// Fonctions pour charger le contenu spécifique de chaque page
function loadHomePage() {
  document.getElementById("content").innerHTML = 
  `
    <div class="background-accueil" class="py-5 bg-image-full" id="cover">
      <div class="logo-center2">
        <h1 class="h1accueil outlined-text" >Project <br> ft_transcendence 42</h1>
        <h2 class="text-white outlined-text" >Project by the group of Edouard, Hugo, Pedro, Felix and Lucas</h2>
        <p></p>
        <a class="startbtn no-transparency" onclick="navigate(event,'/game')">Get Started</a>
      </div>
    </div>
  `;
}

function loadAproposPage() {
  const jwt_token = localStorage.getItem('jwt_token');
  fetch("/api/apropos-data", {
                headers: {
                    'X-Requested-With': 'XMLHttpRequest',
                    'Authorization': 'Bearer ' + jwt_token
        },
    })
    .then((response) => response.json())
    .then((data) => {
      document.getElementById("content").innerHTML =
        `
        <div class="background-propos" id="cover">
          <div id ="popup-overlay" class = open>
            <div class="popup-content">
                <h1> About us</h1>
                <p>${data.content}</p>
            </div>
          </div>
        </div>
        `;
    })
    .catch((error) => {
      console.error("Error:", error);
    });
}

function loadContactPage() {
  document.getElementById("content").innerHTML = 
  `
  <div class="background-contact" id="cover">
    <div id ="popup-overlay" class = open>
      <div class="popup-content">
        <h1>Contact</h1><p>Contact us.</p>
        <div class="mb-3">
          <label for="exampleFormControlInput1" class="form-label">Email address</label>
          <input type="email" class="form-control" id="exampleFormControlInput1" placeholder="name@example.com">
        </div>
        <div class="mb-3">
          <label for="exampleFormControlTextarea1" class="form-label">Message</label>
          <textarea class="form-control" id="exampleFormControlTextarea1" placeholder="Ask for help." rows="6"></textarea>
        </div>
      </div>
    </div>
  </div>
  `;
}

// Gestion de l'événement popstate pour les boutons précédent/suivant du navigateur

document.addEventListener("DOMContentLoaded", (event) => {
  window.addEventListener("popstate", route);
  loginSubmitEvent();
  window.addEventListener('beforeunload', function(event) {
      if (localStorage.getItem('jwt_token'))
      {
          const iD = getMyId();
          localStorage.clear();
          navigator.sendBeacon('/logout-beacon/', iD);
      }
  });
  routageInit();
  route();
});

function auth42() {
  const jwt_token = localStorage.getItem('jwt_token');
  fetch("/get-42keys/", {
    method: 'GET',
    headers: {
      'Authorization': 'Bearer ' + jwt_token,
      'X-Requested-With': 'XMLHttpRequest',
      'X-CSRFToken': getCookie('csrftoken')
    },
  })
  .then((response) => response.json())
  .then((data) => {
    const clientId = data.clientkey;
    const redirectUri = encodeURIComponent(data.ruri);
    const authUrl = `https://api.intra.42.fr/oauth/authorize?client_id=${clientId}&redirect_uri=${redirectUri}&response_type=code&scope=public`;
    window.location.href = authUrl;
  })
  .catch((error) => {
    console.error("Error:", error);
  });
}
