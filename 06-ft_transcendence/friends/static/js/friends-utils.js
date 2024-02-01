function getColor(friendStatus) {
  if (friendStatus === "online") {
    return `<font color="green">Online</font>`;
  } else if (friendStatus === "offline"){
    return `<font color="red">Offline</font>`;
  } else {
    return `<font color="orange">In game</font>`;
  }
}

function toggleSearchFriendBar() {
  const searchFriendBar = document.getElementById("search-friend-bar");
  if (searchFriendBar.style.display === "none") {
    searchFriendBar.style.display = "block";
  } else {
    document.getElementById("search-friend-input").value = "";
    document.getElementById("search-friend-results-list").innerHTML = "";
    searchFriendBar.style.display = "none";
  }
}

 function alreadyFriend(friendUsername, allFriendsData, userUsername) {
  let alreadyFriend = false;
  allFriendsData.forEach((friend) => {
    if (
      (friend.username === friendUsername && friend.friend === userUsername)
      || (friend.username === userUsername && friend.friend === friendUsername)
    ) {
      alreadyFriend = true;
    }
  });
  return alreadyFriend;
}

function alreadyNotified(friendUsername, userUsername, allNotificationsData) {
  let alreadyNotified = false;
  allNotificationsData.forEach((notification) => {
    if (
     notification.sender === userUsername
      && notification.receiver === friendUsername
      && notification.status !== "accepted"
    ) {
      alreadyNotified = true;
    }
  });
  return alreadyNotified;
}
