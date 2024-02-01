function closeNotifications() {
  const currentNotifications = document.getElementById("notification");
  if (currentNotifications.style.display === "block") {
    currentNotifications.style.display = "none";
  }
}

async function loadNotifications() {
  const currentNotifications = document.getElementById("notification");
  if (currentNotifications.style.display === "block") {
    currentNotifications.style.display = "none";
  } else {
    try {
      currentNotifications.style.display = "block";
      const route = "/friends/notifications";
    const jwt_token = localStorage.getItem('jwt_token');
      const response = await fetch(route, {
                headers: {
                  'X-Requested-With': 'XMLHttpRequest',
                  'Authorization': 'Bearer ' + jwt_token
        },
    });
      const data = await response.json();
      htmlContent = await listNotifications(data);

      if (document.getElementById("notification") === null) {
        let notifElement = createAppendUlElement("notification", htmlContent);
      } else {
        document.getElementById("notification").innerHTML = htmlContent;
      }
      acceptDeclineOkListeners();
    } catch (error) {
      console.error("Error:", error);
    }
  }
}

async function createAppendUlElement(id, htmlContent) {
    let notifElement = document.createElement('ul');
    notifElement.id = id;
    notifElement.innerHTML = htmlContent;
    const cover = document.getElementById("cover");
    cover.appendChild(notifElement);
}

async function listNotifications(data) {
  try {
    let htmlContent = "";
    data.forEach((notification) => {
      if (notification.notification_type === "Match Request") {
        htmlContent += `
        <div class="notification-item">
          <span class="notification-text">${notification.sender}: ${notification.message}
          </span>
          <div class="notification-buttons">
            <button id=fight-${notification.id}-${notification.sender}>Accept</button>
            <button id=run-${notification.id}-${notification.sender}>Decline</button>
          </div>
        </div>
          `;
      }
      if (notification.notification_type === "Friend Request") {
        if (notification.status !== "sent") {
          htmlContent += `
          <div class="notification-item">
            <span class="notification-text">${notification.sender} ${notification.message}
            </span>
            <div class="notification-buttons">
              <button id=ok-${notification.id}-${notification.sender}>OK</button>
            </div>
          </div>
            `;
        } else {
        htmlContent += `
        <div class="notification-item">
          <span class="notification-text">${notification.message}: ${notification.sender}
          </span>
          <div class="notification-buttons">
            <button id=accept-${notification.id}-${notification.sender}>Accept</button>
            <button id=decline-${notification.id}-${notification.sender}>Decline</button>
          </div>
        </div>
          `;
        }
      }
    });
    if (htmlContent === "")
      htmlContent = "You have no new notifications";
    return htmlContent;
  } catch (error) {
    console.error("Error:", error);
  }
}

async function getNotifById(id) {
    const jwt_token = localStorage.getItem('jwt_token');
  const allNotifications = await fetch("/api/all-notifications", {
                headers: {
                  'X-Requested-With': 'XMLHttpRequest',
                  'Authorization': 'Bearer ' + jwt_token
        },
    });
  const data = await allNotifications.json();
  for(const notification of data) {
    if (notification.id == id) {
      return notification;
    }
  };
}

async function getNotifByNames(senderUsername, receiverUsername) {
    const jwt_token = localStorage.getItem('jwt_token');
  const allNotifications = await fetch("/api/all-notifications", {
                headers: {
                  'X-Requested-With': 'XMLHttpRequest',
                  'Authorization': 'Bearer ' + jwt_token
        },
    });
  const data = await allNotifications.json();
  for(const notification of data) {
    if (
      (notification.sender == senderUsername && notification.receiver == receiverUsername)
      || (notification.sender == receiverUsername && notification.receiver == senderUsername)
      ) {
      return notification;
    }
  };
}


async function acceptFightRequest(userUsername, friendUsername) {
  const route = "/ws/game/" + userUsername + "/" + friendUsername;
  const jwt_token = localStorage.getItem('jwt_token');
  const room = await fetch(route, {
                headers: {
                  'X-Requested-With': 'XMLHttpRequest',
                  'Authorization': 'Bearer ' + jwt_token
        },
    });
  const data = await room.text();
  const newBodyHtml = data;
  document.getElementById("content").innerHTML = newBodyHtml;
  await socketUtils(userUsername, friendUsername);
}

async function deleteNotification(notificationId) {
  try {
    const csrfToken = getCookie("csrftoken");
    const route = "friends/delete-notification/" + notificationId;
    const jwt_token = localStorage.getItem('jwt_token');
    const response = await fetch(route, {
      method: "DELETE",
      headers: {
        "Content-Type": "application/json",
        'X-Requested-With': 'XMLHttpRequest',
        "X-CSRFToken": csrfToken,
        'Authorization': 'Bearer ' + jwt_token,
      },
    });
    const data = await response.json();
  } catch (error) {
    console.error("Error:", error);
  }
}

async function acceptDeclineOkListeners() {
  try {
    const userUsername = getMyUsername();
    const acceptButtons = document.querySelectorAll("[id^=accept]");
    const declineButtons = document.querySelectorAll("[id^=decline]");
    const okButtons = document.querySelectorAll("[id^=ok]");
    const fightButtons = document.querySelectorAll("[id^=fight]");  
    const runButtons = document.querySelectorAll("[id^=run]");
    fightButtons.forEach((button) => {
      button.addEventListener("click", function () {
        const notificationId = button.id.split("-")[1];
        const senderUsername = button.id.split("-")[2];
        deleteNotification(notificationId);
        const id = getMyId();
        updateStatus(id, "in game");
        acceptFightRequest(senderUsername, userUsername);
        document.getElementById("notification").removeChild(button.parentNode.parentNode);
      });
    });
    runButtons.forEach((button) => {
      button.addEventListener("click", function () {
        const notificationId = button.id.split("-")[1];
        // const senderUsername = button.id.split("-")[2];
        deleteNotification(notificationId);
        //TODO: send a message to the sender in the socket room that the friend refused
        document.getElementById("notification").removeChild(button.parentNode.parentNode);
      });
    });
    acceptButtons.forEach((button) => {
      button.addEventListener("click", function () {
        const notificationId = button.id.split("-")[1];
        const senderUsername = button.id.split("-")[2];
        acceptFriendRequest(notificationId, senderUsername);
        document.getElementById("notification").removeChild(button.parentNode.parentNode);
      });
    });
    declineButtons.forEach((button) => {
      button.addEventListener("click", function () {
        const notificationId = button.id.split("-")[1];
        const senderUsername = button.id.split("-")[2];
        declineFriendRequest(notificationId, senderUsername);
        document.getElementById("notification").removeChild(button.parentNode.parentNode);
      });
    });
    okButtons.forEach((button) => {
      button.addEventListener("click", function () {
        const notificationId = button.id.split("-")[1];
        const senderUsername = button.id.split("-")[2];
        okFriendRequest(notificationId, senderUsername);
        document.getElementById("notification").removeChild(button.parentNode.parentNode);
      });
    });
  } catch (error) {
    console.error("Error:", error);
  }
}

async function okFriendRequest(notificationId, senderUsername) {
  try {
    const senderId = await getIdByUsernameFromApi(senderUsername);
    const csrfToken = getCookie("csrftoken");
    const route = "friends/friend-request/" + senderId;
    const jwt_token = localStorage.getItem('jwt_token');
    const response = await fetch(route, {
      method: "DELETE",
      headers: {
        "Content-Type": "application/json",
        'X-Requested-With': 'XMLHttpRequest',
        "X-CSRFToken": csrfToken,
        'Authorization': 'Bearer ' + jwt_token,
      },
      body: JSON.stringify({
        notificationId: notificationId,
      }),
    });
    const data = await response.json();
  } catch (error) {
    console.error("Error:", error);
  }
}

async function acceptFriendRequest(notificationId, senderUsername) {
  try {
    const senderId = await getIdByUsernameFromApi(senderUsername);
    const csrfToken = getCookie("csrftoken");
    const route = "friends/friend-request/" + senderId;
    const jwt_token = localStorage.getItem('jwt_token');
    const response = await fetch(route, {
      method: "PUT",
      headers: {
        "Content-Type": "application/json",
        'X-Requested-With': 'XMLHttpRequest',
        "X-CSRFToken": csrfToken,
        'Authorization': 'Bearer ' + jwt_token,
      },
      body: JSON.stringify({
        status: "accepted",
        message: "accepted your friend request",
        notificationId: notificationId,
      }),
    });
    const data = await response.json();
  } catch (error) {
    console.error("Error:", error);
  }
}

async function declineFriendRequest(notificationId, senderUsername) {
  try {
    const senderId = await getIdByUsernameFromApi(senderUsername);
    const csrfToken = getCookie("csrftoken");
    const route = "friends/friend-request/" + senderId;
    const jwt_token = localStorage.getItem('jwt_token');
    const response = await fetch(route, {
      method: "PUT",
      headers: {
        "Content-Type": "application/json",
        'X-Requested-With': 'XMLHttpRequest',
        "X-CSRFToken": csrfToken,
        'Authorization': 'Bearer ' + jwt_token,
      },
      body: JSON.stringify({
        status: "declined",
        message: "rejected your friend request",
        notificationId: notificationId,
      }),
    });
    const data = await response.json();
  } catch (error) {
    console.error("Error:", error);
  }
}
