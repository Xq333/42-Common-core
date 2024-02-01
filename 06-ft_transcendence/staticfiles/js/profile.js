function loadProfile() {
  const jwt_token = localStorage.getItem("jwt_token");
  fetch("/profile/", {
    headers: {
      'X-Requested-With': 'XMLHttpRequest',
      "Authorization": "Bearer " + jwt_token,
    },
  })
  .then(response => response.text())
  .then(html => {
    document.getElementById('content').innerHTML = html;
  });
}

function loadProfileEdit(path) {
  let urlForm = path.slice(1);
  const jwt_token = localStorage.getItem("jwt_token");
  fetch(urlForm, {
    headers: {
      'X-Requested-With': 'XMLHttpRequest',
      "Authorization": "Bearer " + jwt_token,
    },
  })
    .then((response) => response.text())
    .then((html) => {
      document.getElementById("content").innerHTML = html;
    });
}

function submitProfileForms(event, formId) {
  const form = document.getElementById(formId);
  event.preventDefault(); // Empêche la soumission standard du formulaire
  const jwt_token = localStorage.getItem("jwt_token");
  const formData = new FormData(form);
  const csrftoken = getCookie("csrftoken");
  fetch(form.action, {
    method: "POST",
    body: formData,
    headers: {
      "X-CSRFToken": csrftoken,
      'X-Requested-With': 'XMLHttpRequest',
      "Authorization": "Bearer " + jwt_token,
    },
  })
    .then((response) => response.json())
    .then((data) => {
      printFlashMessage(data.message);
      navigate(event, "/profile");
    })
    .catch((error) => {
      console.error("Error:", error);
    });
}

function loadTwoFAForm() {
  const jwt_token = localStorage.getItem("jwt_token");
  fetch("twoFAForm", {
    headers: {
      'X-Requested-With': 'XMLHttpRequest',
      "Authorization": "Bearer " + jwt_token,
    },
  })
    .then((response) => response.text())
    .then((html) => {
      document.getElementById("content").innerHTML = html;
    })
    .catch((error) => console.error("Error:", error));
}

// function update2FAButton(is2FAEnabled) {
//   const twoFABtn = document.getElementById('toggle-2fa-btn');
//
//   if (twoFABtn) {
//     if (is2FAEnabled) {
//       twoFABtn.textContent = '2FA Enabled';
//       twoFABtn.classList.remove('fadisabled');
//       twoFABtn.classList.add('faenabled');
//       twoFABtn.setAttribute('onclick', "navigate(event, '/disableTwoFAForm')");
//     } else {
//       twoFABtn.textContent = '2FA Disabled';
//       twoFABtn.classList.remove('faenabled');
//       twoFABtn.classList.add('fadisabled');
//       twoFABtn.setAttribute('onclick', "navigate(event, '/twoFAForm')");
//     }
//   }
// }

function update2FAStatus() {
  const jwt_token = localStorage.getItem("jwt_token");
  fetch("/api/2fa_status/", {
    headers: {
      'X-Requested-With': 'XMLHttpRequest',
      "Authorization": "Bearer " + jwt_token,
    },
  })
    .then((response) => {
      if (!response.ok) {
        throw new Error("Network response was not ok " + response.statusText);
      }
      return response.json();
    })
    .then((data) => {
      update2FAButton(data.is_2fa_enabled);
    })
    .catch((error) => console.error("Error:", error));
}

function loadDisableTwoFAForm() {
  const jwt_token = localStorage.getItem("jwt_token");
  fetch("disableTwoFAForm/", {
    headers: {
      'X-Requested-With': 'XMLHttpRequest',
      "Authorization": "Bearer " + jwt_token,
    },
  })
    .then((response) => response.text())
    .then((html) => {
      document.getElementById("content").innerHTML = html;
    })
    .catch((error) => console.error("Error:", error));
}

function deactivate2FA() {
  const jwt_token = localStorage.getItem("jwt_token");
  const otpToken = document.querySelector('input[name="otp_token"]').value;

  fetch("/api/deactivate-2fa/", {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      'X-Requested-With': 'XMLHttpRequest',
      "Authorization": "Bearer " + jwt_token,
    },
    body: JSON.stringify({ otp_token: otpToken }),
  })
    .then((response) => response.json())
    .then((data) => {
      if (data.status === "success") {
        printFlashMessage("2FA deactivated successfully");
        loadProfile();
      } else {
        const msg = "Failed to deactivate 2FA: " + data.message;
        printFlashMessage(msg);
      }
    })
    .catch((error) => console.error("Error:", error));
}

function deleteAccount() {
    if (confirm('Voulez-vous vraiment supprimer votre compte?')) {
        const jwt_token = localStorage.getItem('jwt_token');
        fetch('/deleteAccount/', {
            method: 'POST',
            headers: {
                'Authorization': 'Bearer ' + jwt_token,
                'X-Requested-With': 'XMLHttpRequest',
                'X-CSRFToken': getCookie('csrftoken')
            },
        })
        .then(response => {
            if (response.ok) {
                localStorage.removeItem('jwt_token');
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
                            const artificialEvent = { preventDefault: () => {} };
                            navigate(artificialEvent, '/');
                            });
            } else {
                console.error('La suppression du compte a échoué');
            }
        })
        .catch(error => console.error('Erreur:', error));
    }
}
