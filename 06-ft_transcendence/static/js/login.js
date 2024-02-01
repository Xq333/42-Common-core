function loadLoginPage() {
    const switchToRegister = document.getElementById("registerswitch");
  
    if (switchToRegister === null) {
      return;
    }
    switchToRegister.addEventListener("click", function (e) {
      e.preventDefault();
      e.stopPropagation();
      document.getElementById("registerFormular").style.display = "block";
      document.getElementById("loginFormular").style.display = "none";
      return;
    });
  }
  
  
function loadRegisterPage() {
    const navbar = document.getElementById("bar");
    if (navbar)
      navbar.style.display = 'none';
    const switchToLogin = document.getElementById("loginswitch");
  
    if (switchToLogin === null) {
      return;
    }
    switchToLogin.addEventListener("click", function (e) {
      e.preventDefault();
      e.stopPropagation();
      document.getElementById("loginFormular").style.display = "block";
      document.getElementById('show').style.display = 'block';
      document.getElementById('otp-field').style.display = 'none';
      document.getElementById("registerFormular").style.display = "none";
      return;
    });
}

function loadLogoutPage() {

const flashMessage = document.getElementById("flash-message");
flashMessage.innerHTML = `
<div class = "flash-message2">
  <div>
    Are you sure you want to logout ?
  </div>
  <div>
    <button id="logout-button">Yes</button>
    <button id="stay-button">Cancel</button>
  </div>
</div>
  `;
const overlay = document.getElementById("flash-overlay");
overlay.style.display = "flex";
flashMessage.style.display = "block";
document.getElementById("logout-button").addEventListener("click", processLogout);
document.getElementById("stay-button").addEventListener("click", function () {
  flashMessage.innerHTML = "";
  overlay.style.display = "none";
});
}

async function processLogout() {
try {
  const jwt_token = localStorage.getItem('jwt_token');
  const response = await fetch("/logout/", {
    method: "POST",
    headers: {
      'X-Requested-With': 'XMLHttpRequest',
      'Authorization': 'Bearer ' + jwt_token
    },
  });
  const data = await response.json();
  if (data.status !== "fail") {
    const flashMessage = document.getElementById("flash-message");
    flashMessage.innerHTML = "";
    flashMessage.display = "none";
    const overlay = document.getElementById("flash-overlay");
    overlay.style.display = "none";
    localStorage.removeItem('jwt_token');
    localStorage.clear();
    fetch("/")
      .then((response) => response.text())
      .then(html => {
        const parser = new DOMParser();
        const doc = parser.parseFromString(html, 'text/html');

        const newBodyHtml = doc.querySelector('body').innerHTML;
        document.body.innerHTML = newBodyHtml;

        document.getElementById("logout").style.display = "none";

          for (const link of document.querySelectorAll('a')) {
            if (link.getAttribute('href').startsWith('/')) {
              link.addEventListener('click', (event) => navigate(event, link.getAttribute('href')));
            }
          }
          const artificialEvent = { preventDefault: () => { } };
          navigate(artificialEvent, '/');
        });
    }
  } catch (error) {
    console.error("Error:", error);
  }
}
