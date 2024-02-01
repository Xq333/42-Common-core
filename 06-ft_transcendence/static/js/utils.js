function routageInit() {
  for (const link of document.querySelectorAll("a")) {
    const href = link.getAttribute("href");
    if (href && href.startsWith("/")) {
      link.addEventListener(
        "click",
        (event) => navigate(event, link.getAttribute("href")),
      );
    }
  }
}

function sleep(milliseconds) {
  return new Promise((resolve) => setTimeout(resolve, milliseconds));
}

function getCookie(name) {
  let cookieValue = null;
  if (document.cookie && document.cookie !== "") {
    const cookies = document.cookie.split(";");
    for (let i = 0; i < cookies.length; i++) {
      const cookie = cookies[i].trim();
      if (cookie.substring(0, name.length + 1) === (name + "=")) {
        cookieValue = decodeURIComponent(cookie.substring(name.length + 1));
        break;
      }
    }
  }
  return cookieValue;
}

// API
function getMyId() {
    return localStorage.getItem('userId');
}

function getMyId() {
  return localStorage.getItem("userId");
}

function getMyUsername() {
  return localStorage.getItem("username");
}

async function getIdByUsernameFromApi(username) {
  const jwt_token = localStorage.getItem("jwt_token");
  try {
    const route = "/api/user-data-username/" + username;
    const response = await fetch(route, {
      headers: {
        'X-Requested-With': 'XMLHttpRequest',
        "Authorization": "Bearer " + jwt_token,
      },
    });
    const data = await response.json();
    return data.id;
  } catch (error) {
    console.error("Error:", error);
  }
}

async function getAvatarByUsernameFromApi(username) {
  const jwt_token = localStorage.getItem("jwt_token");
  try {
    const route = "/api/user-data-username/" + username;
    const response = await fetch(route, {
      headers: {
        'X-Requested-With': 'XMLHttpRequest',
        "Authorization": "Bearer " + jwt_token,
      },
    });
    const data = await response.json();
    return data.avatar;
  } catch (error) {
    console.error("Error:", error);
  }
}

// EVENTS

function printFlashMessage(message) {
  const flashMessage = document.getElementById("flash-message");
  let htmlContent = "";
  htmlContent +=  `<div class = "flash-message2">`;
  htmlContent += message;
  htmlContent += `<button id="okButton">OK</button>`;
  htmlContent +=  `</div>`;
  flashMessage.innerHTML = htmlContent;


  document.getElementById("flash-overlay").style.display = "block";
  flashMessage.style.display = "block";
  okButton.addEventListener("click", () => {
    removeFlashMessage();
  });
}

function removeFlashMessage() {
  const flashMessage = document.getElementById("flash-message");
  flashMessage.innerHTML = "";
  document.getElementById("flash-overlay").style.display = "none";
  flashMessage.style.display = "none";
}

function loginSubmitEvent() {
  document.body.addEventListener("submit", async function (e) {
    e.preventDefault();

    if (
      e.target.id === "profileForm" || e.target.id === "passForm" ||
      e.target.id === "avatarForm"
    ) {
      submitProfileForms(e, e.target.id);
    }

    if (e.target.id === "loginFormular") {
      const formData = new FormData(e.target);
      document.getElementById("submit-login").disabled = true;
      const response = await fetch("login/", {
        method: "POST",
        headers: {
          "X-Requested-With": "XMLHttpRequest",
        },
        body: formData,
      });
      const data = await response.json();
      try {
        if (data.status === "two_factor_required") {
          document.getElementById("otp-field").style.display = "block";
          document.getElementById("show").style.display = "none";
          localStorage.setItem("2fa_user", data.user_id);
        } else if (data.status === "success") {
          localStorage.setItem("jwt_token", data.access);
          document.getElementById("logout").style.display = "block";
          printFlashMessage(data.message);
          history.pushState(null, "", "/accueil");
          const navBar = document.getElementById("bar");
          if (navBar)
            navBar.style.display = 'block';
          loadHomePage();
          localStorage.setItem("userId", data.user_id);
          localStorage.setItem("username", data.username);
        } else {
          document.getElementById("submit-login").disabled = false;
          printFlashMessage(data.message);
        }
      } catch (error) {
        document.getElementById("submit-login").disabled = false;
        console.error("Error:", error);
      }
    }
    if (e.target.id === "registerFormular") {
      const data = new FormData(e.target);
      if (data.get("password") !== data.get("password2")) {
        printFlashMessage("Les mots de passe ne correspondent pas");
        return;
      }
      document.getElementById("submit-register").disabled = true;
      fetch("register/", {
        method: "POST",
        headers: {
          "X-Requested-With": "XMLHttpRequest",
        },
        body: data,
      })
        .then((response) => response.json())
        .then((data) => {
          if (data.status !== "fail") {
            document.getElementById("registerFormular").style.display = "none";
            printFlashMessage(data.message);
            document.getElementById("loginFormular").style.display = "block";
            document.getElementById("register-switch").style.display = "none";
          } else {
            let errorMessage = `<p>${data.message} :</p>`;
            for (const [key, value] of Object.entries(data.errors)) {
              errorMessage += `<p>${key}: ${value}</p>`;
            }
            document.getElementById("submit-register").disabled = false;
            printFlashMessage(errorMessage);
          }
        })
        .catch((error) => console.error("Error:", error));
    }
  });
}

function submitOTP() {
  const otpToken = document.querySelector('input[name="otp"]').value;
  const userId = localStorage.getItem("2fa_user");
  fetch("/verify-otp/", {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      "X-Requested-With": "XMLHttpRequest",
    },
    body: JSON.stringify({ user_id: userId, otp_token: otpToken }),
  })
    .then((response) => response.json())
    .then((data) => {
      if (data.status === "success") {
        localStorage.setItem("jwt_token", data.access);
        document.getElementById("logout").style.display = "block";
        printFlashMessage("OTP verification successful.");
        loadHomePage();
      } else {
        printFlashMessage("Incorrect OTP, please try again.");
      }
    })
    .catch((error) => console.error("Error:", error));
}

function confirm2FA() {
  const otpToken = document.querySelector('input[name="otp_token"]').value;
  fetch("/activate-2fa/", {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      "X-Requested-With": "XMLHttpRequest",
      "Authorization": "Bearer " + localStorage.getItem("jwt_token"),
    },
    body: JSON.stringify({ otp_token: otpToken }),
  })
    .then((response) => response.json())
    .then((data) => {
      if (data.status === "success") {
        printFlashMessage("2FA activated successfully.");
        loadProfile();
      } else {
        printFlashMessage(
          "Failed to activate 2FA. Please check the OTP and try again.",
        );
      }
    })
    .catch((error) => console.error("Error:", error));
}

function togglePrivacyPolicy() {
  var content = document.getElementById("privacyPolicyContent");
  if (content.style.display === "none" || content.style.display === "") {
    content.style.display = "block";
  } else {
    content.style.display = "none";
  }
  for (const link of document.querySelectorAll("a")) {
    if (link.getAttribute("href") == null) {
      continue;
    }
    if (link.getAttribute("href").startsWith("/")) {
      link.addEventListener(
        "click",
        (event) => navigate(event, link.getAttribute("href")),
      );
    }
  }
}

function anonymize() {
    const jwt_token = localStorage.getItem('jwt_token');

    fetch('/anonymize/', { 
        method: 'POST',
        headers: { 
            'X-CSRFToken': getCookie('csrftoken'),
            'Authorization': 'Bearer ' + jwt_token,
            'X-Requested-With': 'XMLHttpRequest',
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ anonymize: true }) 
    })
    .then(response => response.json())
    .then(data => {
        if (data.status === 'success') {
            alert(data.message);
            loadProfile();
        } else {
            alert('Error: ' + data.message);
        }
    })
    .catch(error => {
        console.error('Error:', error);
    });
}
