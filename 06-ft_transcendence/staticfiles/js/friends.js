// LOAD AND LIST

async function loadFriendsPage() {
  try {
    const jwt_token = localStorage.getItem("jwt_token");
    const friendResponse = await fetch("friends/", {
      headers: {
        'X-Requested-With': 'XMLHttpRequest',
        "Authorization": "Bearer " + jwt_token,
      },
    });
    const friendData = await friendResponse.text();
    document.getElementById("content").innerHTML = friendData;

    searchButtonEvent();
    await listFriends();
    removeAndFightFriendListeners();
  } catch (error) {
    console.error("Error:", error);
  }
}

async function showProfile(username) {
  const userId = await getIdByUsernameFromApi(username);
  const route = "/friends/profile/" + userId;
  const jwt_token = localStorage.getItem("jwt_token");
  const response = await fetch(route, {
    headers: {
      'X-Requested-With': 'XMLHttpRequest',
      "Authorization": "Bearer " + jwt_token,
    },
  });
  const data = await response.json();
  const profileContainer = document.getElementById("profile-container");
  profileContainer.innerHTML = `
  
    <div id="profile" class = "statfriend">
      <div id="profile-avatar"><img class= "trophies" src="${data.avatar}"</div>
      <div id="profile-pseudo">Pseudo: ${data.pseudo}</div>
      <div id="profile-match">Games played: ${data.nb_match}</div>
      <div id="profile-winrate">Winrate: ${data.winrate}%</div>
      <p></p>
      <a class="cancelbtn" onclick="navigate(event,'/friends')">go back</a>
    </div>
    `;
}

async function listFriends() {
  try {
    const userId = getMyId();
    const route = "/friends/" + userId + '/';
    const jwt_token = localStorage.getItem("jwt_token");
    const friendlistResponse = await fetch(route, {
      headers: {
        'X-Requested-With': 'XMLHttpRequest',
        "Authorization": "Bearer " + jwt_token,
      },
    });
    const friendlistData = await friendlistResponse.json();
    let htmlContent = "";
    for (const friend of friendlistData) {
      let userAvatar = await getAvatarByUsernameFromApi(friend.username);
      let statusOutput = getColor(friend.status);

      htmlContent += `
        <div class= "cardfriend">
          <div id="${friend.username}-profile" onclick="showProfile('${friend.username}')"><img class= "trophies" src="${userAvatar}"> ${friend.username} : ${statusOutput}
            <button class="cancelfriendbtn" type="submit" id="remove-${friend.username}"><abbr title="Remove">
              <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-x-circle" viewBox="0 0 16 16">
              <path d="M8 15A7 7 0 1 1 8 1a7 7 0 0 1 0 14m0 1A8 8 0 1 0 8 0a8 8 0 0 0 0 16"/>
              <path d="M4.646 4.646a.5.5 0 0 1 .708 0L8 7.293l2.646-2.647a.5.5 0 0 1 .708.708L8.707 8l2.647 2.646a.5.5 0 0 1-.708.708L8 8.707l-2.646 2.647a.5.5 0 0 1-.708-.708"/>
              </svg></abbr>
            </button>
        `;
      if (friend.status === "online") {
        htmlContent += `
            <button class="addfriendbtn" type="submit" id="fight-${friend.username}"><abbr title="Battle">
            <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-joystick" viewBox="0 0 16 16">
              <path d="M10 2a2 2 0 0 1-1.5 1.937v5.087c.863.083 1.5.377 1.5.726 0 .414-.895.75-2 .75s-2-.336-2-.75c0-.35.637-.643 1.5-.726V3.937A2 2 0 1 1 10 2"/>
              <path d="M0 9.665v1.717a1 1 0 0 0 .553.894l6.553 3.277a2 2 0 0 0 1.788 0l6.553-3.277a1 1 0 0 0 .553-.894V9.665c0-.1-.06-.19-.152-.23L9.5 6.715v.993l5.227 2.178a.125.125 0 0 1 .001.23l-5.94 2.546a2 2 0 0 1-1.576 0l-5.94-2.546a.125.125 0 0 1 .001-.23L6.5 7.708l-.013-.988L.152 9.435a.25.25 0 0 0-.152.23z"/>
            </svg></abbr>
            </button>
          `;
      }
      htmlContent += `</div></div>`;
    }
    document.getElementById("user-friendlist").innerHTML = htmlContent;
  } catch (error) {
    console.error("Error:", error);
  }
}

// EVENTS

async function searchButtonEvent() {
  try {
    const addFriendButton = document.getElementById("add-friend-button");
    addFriendButton.addEventListener("click", function (e) {
      e.preventDefault();
      e.stopPropagation();
      toggleSearchFriendBar();
      searchFriendEvent();
    });
  } catch (error) {
    console.error("Error:", error);
  }
}

async function searchFriendEvent() {
  const jwt_token = localStorage.getItem("jwt_token");
  try {
    const userUsername = getMyUsername();
    const allUsersResponse = await fetch("/api/all-users", {
      headers: {
        'X-Requested-With': 'XMLHttpRequest',
        "Authorization": "Bearer " + jwt_token,
      },
    });
    const allUsersData = await allUsersResponse.json();
    const allFriendsResponse = await fetch("/api/all-friendships", {
      headers: {
        'X-Requested-With': 'XMLHttpRequest',
        "Authorization": "Bearer " + jwt_token,
      },
    });
    const allFriendsData = await allFriendsResponse.json();

    searchFriendInputListener(allUsersData, allFriendsData, userUsername);
  } catch (error) {
    console.error("Error:", error);
  }
}

async function searchFriendInputListener(
  allUsersData,
  allFriendsData,
  userUsername,
) {
  let debounceTimer;
  const searchFriendInput = document.getElementById("search-friend-input");

  searchFriendInput.addEventListener("input", async function (e) {
    e.preventDefault();
    e.stopPropagation();
    clearTimeout(debounceTimer);
    const jwt_token = localStorage.getItem("jwt_token");
    debounceTimer = setTimeout(async () => {
      const allNotificationsResponse = await fetch("/api/all-notifications", {
        headers: {
          'X-Requested-With': 'XMLHttpRequest',
          "Authorization": "Bearer " + jwt_token,
        },
      });
      const allNotificationsData = await allNotificationsResponse.json();
      const searchFriendUsername = searchFriendInput.value;
      const showdrop = document.getElementById("show-droppout");
      if (searchFriendUsername === "") {
        document.getElementById("search-friend-results-list").innerHTML = "";
        showdrop.style.display = "none";
        return;
      }

      let htmlContent = "";
      allUsersData.forEach((user) => {
        if (
          user.username !== userUsername &&
          !alreadyFriend(user.username, allFriendsData, userUsername) &&
          user.username.toLowerCase().includes(
            searchFriendUsername.toLowerCase(),
          )
        ) {
          showdrop.style.display = "block";
          htmlContent += `<div class= "listfriendsli">
                <li onclick="showProfile('${user.username}')">Username: ${user.username}: `;
          if (
            alreadyNotified(user.username, userUsername, allNotificationsData)
          ) {
            htmlContent += ` pending...</li>`;
          } else {
            htmlContent +=
              `<button class=addfriendbtn type=submit id=${user.username}-button><abbr title="Add"><svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-person-fill-add" viewBox="0 0 16 16">
                <path d="M12.5 16a3.5 3.5 0 1 0 0-7 3.5 3.5 0 0 0 0 7m.5-5v1h1a.5.5 0 0 1 0 1h-1v1a.5.5 0 0 1-1 0v-1h-1a.5.5 0 0 1 0-1h1v-1a.5.5 0 0 1 1 0m-2-6a3 3 0 1 1-6 0 3 3 0 0 1 6 0"/>
                <path d="M2 13c0 1 1 1 1 1h5.256A4.493 4.493 0 0 1 8 12.5a4.49 4.49 0 0 1 1.544-3.393C9.077 9.038 8.564 9 8 9c-5 0-6 3-6 4"/>
                </svg></abbr></button></li>`;
          }
          htmlContent += `</div>`;
        }
      });
      document.getElementById("search-friend-results-list").innerHTML =
        htmlContent;
      setTimeout(() => addFriendListeners(allUsersData, userUsername), 0);
    }, 500);
  });
}

async function addFriendListeners(data, senderUsername) {
  data.forEach((user) => {
    const button = document.getElementById(`${user.username}-button`);
    if (button) {
      button.addEventListener("click", function () {
        document.getElementById("flash-message").innerHTML =
          `<p>Asking ${user.username} to become your friend</p>`;
        document.getElementById("flash-message").style.display = "block";
        sendFriendRequest(senderUsername, user.username);
        toggleSearchFriendBar();
      });
    }
  });
}

function removeConfirmation(userUsername, friendUsername) {
  const flashMessage = document.getElementById("flash-message");
  flashMessage.innerHTML = 
  `
    <div class = flash-message2>
      <div>Are you sure you want to remove ${friendUsername} from your friends?</div>
      <div>
        <button class="btn btn-primary" id="confirm-remove-${friendUsername}">Yes</button>
        <button class="btn btn-danger" id="cancel-remove">No</button>
      </div>
    </div>
    `;
  const overlay = document.getElementById("flash-overlay");
  overlay.style.display = "flex";
  flashMessage.style.display = "block";
  const cancelRemove = document.getElementById("cancel-remove");
  cancelRemove.addEventListener("click", function () {
    flashMessage.innerHTML = "";
    overlay.style.display = "none";
  });
  const confirmRemove = document.getElementById(
    `confirm-remove-${friendUsername}`,
  );
  confirmRemove.addEventListener("click", function () {
    removeFriend(userUsername, friendUsername);
    flashMessage.innerHTML = "";
    overlay.style.display = "none";
  });
}

async function removeAndFightFriendListeners() {
  try {
    const jwt_token = localStorage.getItem("jwt_token");
    const allFriendsResponse = await fetch("/api/all-friendships", {
      headers: {
        'X-Requested-With': 'XMLHttpRequest',
        "Authorization": "Bearer " + jwt_token,
      },
    });
    const allFriendsData = await allFriendsResponse.json();

    allFriendsData.forEach((friend) => {
      const rmButton = document.getElementById(`remove-${friend.friend}`);
      if (rmButton) {
        rmButton.addEventListener("click", function () {
          removeConfirmation(friend.username, friend.friend);
        });
      }
      const fightButton = document.getElementById(`fight-${friend.friend}`);
      if (fightButton) {
        fightButton.addEventListener("click", function () {
          fightFriend(friend.username, friend.friend);
        });
      }
    });
  } catch (error) {
    console.error("Error:", error);
  }
}

// FIGHT

async function updateStatus(userId, status) {
  try {
    const csrfToken = getCookie("csrftoken");
    const route = "/update-status/" + userId;
    const response = await fetch(route, {
      method: "PUT",
      headers: {
        "Content-Type": "application/json",
        'X-Requested-With': 'XMLHttpRequest',
        "X-CSRFToken": csrfToken,
      },
      body: JSON.stringify({ status: status }),
    });
    data = await response.json();
  } catch (error) {
    console.error("Error:", error);
  }
}

async function fightFriend(userUsername, friendUsername) {
  const jwt_token = localStorage.getItem("jwt_token");
  const allNotificationsResponse = await fetch("/api/all-notifications", {
    headers: {
      'X-Requested-With': 'XMLHttpRequest',
      "Authorization": "Bearer " + jwt_token,
    },
  });
  const allNotificationsData = await allNotificationsResponse.json();
  if (alreadyNotified(userUsername, friendUsername, allNotificationsData)) {
    printFlashMessage("You already asked this friend to fight");
    return;
  }
  try {
    const senderId = getMyId();
    const receiverId = await getIdByUsernameFromApi(friendUsername);
    const csrfToken = getCookie("csrftoken");
    const route = "friends/fight-request/" + receiverId;
    const jwt_token = localStorage.getItem("jwt_token");
    const response = await fetch(route, {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
        'X-Requested-With': 'XMLHttpRequest',
        "X-CSRFToken": csrfToken,
        "Authorization": "Bearer " + jwt_token,
      },
      body: JSON.stringify({
        sender: senderId,
        receiver: receiverId,
        notificationType: "Match Request",
        message: "wants to fight you!",
      }),
    });
    const data = await response.json();
    if (data.status === "error") {
      printFlashMessage(data.message);
      return;
    }
    updateStatus(senderId, "in game");
    acceptFightRequest(userUsername, friendUsername);
  } catch (error) {
    console.error("Error:", error);
  }
}

// ADD AND REMOVE

async function sendFriendRequest(senderUsername, receiverUsername) {
  try {
    const senderId = getMyId();
    const receiverId = await getIdByUsernameFromApi(receiverUsername);
    const csrfToken = getCookie("csrftoken");
    const route = "friends/friend-request/" + receiverId;
    const jwt_token = localStorage.getItem("jwt_token");
    const response = await fetch(route, {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
        'X-Requested-With': 'XMLHttpRequest',
        "X-CSRFToken": csrfToken,
        "Authorization": "Bearer " + jwt_token,
      },
      body: JSON.stringify({
        sender: senderId,
        receiver: receiverId,
        notificationType: "Friend Request",
        message: "You have a new friend request",
      }),
    });
    const data = await response.json();
    if (data.status === "error") {
      printFlashMessage(data.message);
      return;
    }
  } catch (error) {
    console.error("Error:", error);
  }
}

async function removeFriend(userUsername, friendUsername) {
  const friendId = await getIdByUsernameFromApi(friendUsername);
  const token = await getCookie("csrftoken");
  const jwt_token = localStorage.getItem("jwt_token");
  const route = "/friends/delete-friend/" + friendId;
  fetch(route, {
    method: "DELETE",
    headers: {
      "Content-Type": "application/json",
      'X-Requested-With': 'XMLHttpRequest',
      "X-CSRFToken": token,
      "Authorization": "Bearer " + jwt_token,
    },
  })
    .then((response) => response.json())
    .then((data) => {
      loadFriendsPage();
    })
    .catch((error) => {
      console.error("Error:", error);
    });
}
