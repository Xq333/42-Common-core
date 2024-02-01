let ws;
let wsMatchmaking;
let eventRandomNavHandler = new Map();
let eventSocketHandlers = {
  navLinks: new Map(),
  beforeUnload: null,
  popState: null,
};

async function socketMatchmaking() {
  let url = `wss://${window.location.host}/ws/matchmaking`;

  const id = getMyId();
  await updateStatus(id, "in game");
  const backBtn = document.getElementById('go-back-button');
  const username = localStorage.getItem('username');
  wsMatchmaking = new WebSocket(url);

  if (backBtn) {
    backBtn.addEventListener('click', function () {
      updateStatus(id, "online");
      if (wsMatchmaking.readyState == WebSocket.OPEN) {
        wsMatchmaking.send(JSON.stringify({
          'message': 'disconnect_request',
        }));
      }
      removeMatchmakingListeners();
      const artificialEvent = { preventDefault: () => { } };
      navigate(artificialEvent, '/game');
    });
  }

  wsMatchmaking.onmessage = function (e) {
    var data = JSON.parse(e.data);
    if (data['message'] == 'username') {
      wsMatchmaking.send(JSON.stringify({
        'message': 'username',
        'username': username,
      }));
    }
    else if (data['message'] == 'ready') {
      players = data['players'];
      user1 = players.player1;
      user2 = players.player2;
      wsMatchmaking.send(JSON.stringify({
        'message': 'disconnect_request',
      }));
      removeMatchmakingListeners();
      acceptFightRequest(user1, user2);
    }
  }
  // Listeners Popstate/ backButton et navLinks beforeunload
  window.addEventListener('beforeunload', handlerRandomBeforeUnload);
  window.addEventListener('popstate', handlerRandomPopstate);
  const navLinks = document.querySelectorAll('.nav-link');
  navLinks.forEach((navLink) => {
    const handler = (event) => handlerRandomNavLinkClick(event);
    eventRandomNavHandler.set(navLink, handler);
    navLink.addEventListener('click', handler);
  });
}

async function removeMatchmakingListeners() {
  const navLinks = document.querySelectorAll('.nav-link');
  navLinks.forEach((navLink) => {
    const handler = eventRandomNavHandler.get(navLink);
    if (handler) {
      navLink.removeEventListener('click', handler);
      eventRandomNavHandler.delete(navLink);
    }
  });
  window.removeEventListener('beforeunload', handlerRandomBeforeUnload);
  window.removeEventListener('popstate', handlerRandomPopstate);
}


async function handlerRandomNavLinkClick(event) {
  const clickedElement = event.currentTarget;
  if (clickedElement) {
    if (clickedElement.classList.contains('exclude-click')) {
      return;
    }
  }
  if (wsMatchmaking.readyState == WebSocket.OPEN) {
    const id = getMyId();
    updateStatus(id, "online");
    removeMatchmakingListeners();
    wsMatchmaking.send(JSON.stringify({
      'message': 'disconnect_request',
    }));
  }
}

async function handlerRandomBeforeUnload() {
  if (wsMatchmaking.readyState == WebSocket.OPEN) {
    removeMatchmakingListeners();
    const id = getMyId();
    updateStatus(id, "online");
    wsMatchmaking.send(JSON.stringify({
      'message': 'disconnect_request',
    }));
  }
}

async function handlerRandomPopstate() {
  if (wsMatchmaking.readyState == WebSocket.OPEN) {
    removeMatchmakingListeners();
    const id = getMyId();
    updateStatus(id, "online");
    wsMatchmaking.send(JSON.stringify({
      'message': 'disconnect_request',
    }));
  }
}

async function socketUtils(userUsername, friendUsername) {
  const button1 = document.getElementById('start1');
  const button2 = document.getElementById('start2');
  const backBtn1 = document.getElementById('go-back-button1');
  const backBtn2 = document.getElementById('go-back-button2');

  const player1Info = document.getElementById('p1-info');
  const player1waiting = document.getElementById('p1-waiting');
  const player2Info = document.getElementById('p2-info');
  const player2waiting = document.getElementById('p2-waiting');

  const p1Id = await getIdByUsernameFromApi(userUsername);
  const p2Id = await getIdByUsernameFromApi(friendUsername);
  const notif = await getNotifByNames(userUsername, friendUsername);
  const myUsername = localStorage.getItem('username');
  if (tournamentGameID != null && tournamentGameID != "Finals")
    flashMessageTournament(tournamentGameID);
  let url = `wss://${window.location.host}/ws/game/${userUsername}/${friendUsername}`;
  ws = new WebSocket(url);

  ws.onopen = function (e) {
    ws.send(JSON.stringify({
      'message': 'connexion',
      'player': myUsername,
    }));
  }

  if (backBtn1) {
    backBtn1.addEventListener('click', function () {
        if (tournamentGameID)
        {
          let tmp = tournamentGameID;
          if (tmp == "Finals")
            tmp = tmpTournamentID;
          leaveTournament(tmp);
          tournamentGameID = null;
        }
        updateStatus(p1Id, "online");
        if (ws.readyState == WebSocket.OPEN) {
          ws.send(JSON.stringify({
            'message': 'disconnect_request',
          }));
        }
        const artificialEvent = { preventDefault: () => { } };
        navigate(artificialEvent, '/game');
      });
  }

  if (backBtn2) {
    backBtn2.addEventListener('click', function () {
      if (tournamentGameID)
      {
        let tmp = tournamentGameID;
        if (tmp == "Finals")
          tmp = tmpTournamentID;
        leaveTournament(tmp);
        tournamentGameID = null;
      }
      updateStatus(p2Id, "online");
      if (ws.readyState == WebSocket.OPEN) {
        ws.send(JSON.stringify({
          'message': 'disconnect_request',
        }));
      }
      const artificialEvent = { preventDefault: () => { } };
      navigate(artificialEvent, '/game');
    });
  }

  if (button1) {
    button1.addEventListener('click', function () {
      if (button1.classList.contains('active')) {
        button1.classList.remove('active');
        button1.innerHTML = 'Set ready';
        button1.style.backgroundColor = 'rgba(0,0,0,0.4)';
        button1.style.color = 'rgba(0,186,188,0.7)';
        ws.send(JSON.stringify({
          'player': 'p1',
          'message': 'not_ready'
        }));
      } else {
        button1.classList.add('active');
        button1.style.backgroundColor = '#80ffb0';
        button1.innerHTML = 'Ready!';
        button1.style.color = 'white';
        ws.send(JSON.stringify({
          'player': 'p1',
          'message': 'ready'
        }));
      }
    });
  }

  if (button2) {
    button2.addEventListener('click', function () {
      if (button2.classList.contains('active')) {
        button2.classList.remove('active');
        button2.innerHTML = 'Set ready';
        button2.style.backgroundColor = 'rgba(0,0,0,0.4)';
        button2.style.color = 'rgba(0,186,188,0.7)';
        ws.send(JSON.stringify({
          'player': 'p2',
          'message': 'not_ready'
        }));
      } else {
        button2.classList.add('active');
        button2.style.backgroundColor = '#80ffb0';
        button2.innerHTML = 'Ready!';
        button2.style.color = 'white';
        ws.send(JSON.stringify({
          'player': 'p2',
          'message': 'ready'
        }));
      }
    });
  }

  ws.onmessage = function (e) {
    var data = JSON.parse(e.data);
    if (data.message == 'player ready' || data.message == 'player not ready') {
      let player = data.playerId.player;
      if (data.message == 'player not ready')
        player = data.playerId
      if (player == "p1")
        player = "player1";
      else
        player = "player2";
      const playerReadyStatusElement = document.getElementById(player + '-ready-status');
      // if (playerReadyStatusElement) {
      //   playerReadyStatusElement.textContent = player + ' is ' + (data.message == 'player ready' ? 'ready!' : 'not ready');
      // }
      if (playerReadyStatusElement) {
        if (data.message === 'player ready') {
          playerReadyStatusElement.innerHTML = player + ' is <span style="color:#80ffb0; font-weight:bold;">ready!</span>';
        } else {
          playerReadyStatusElement.innerHTML = player + ' is <span style="color:#ff8559; font-weight:bold;">not ready</span>';
        }
      }
    }
    else if (data.message == 'player ready' || data.message == 'player not ready') {
      let player = data.playerId.player;
      if (data.message == 'player not ready')
        player = data.playerId
      if (player == "p1")
        player = "player1";
      else
        player = "player2";
      const playerReadyStatusElement = document.getElementById(player + '-ready-status');
      // if (playerReadyStatusElement) {
      //   playerReadyStatusElement.textContent = player + ' is ' + (data.message == 'player ready' ? 'ready!' : 'not ready');
      // }
      if (playerReadyStatusElement) {
        if (data.message === 'player ready') {
          playerReadyStatusElement.innerHTML = player + ' is <span style="color:#80ffb0; font-weight:bold;">ready!</span>';
        } else {
          playerReadyStatusElement.innerHTML = player + ' is <span style="color:#ff8559; font-weight:bold;">not ready</span>';
        }
      }
    }
    else if (data.message == 'joined') {
      if (data.players && data.players['paddle1']) {
        player1waiting.style.display = 'none';
        player1Info.style.display = 'block';
        if (data.len == 2) {
          player2waiting.style.display = 'none';
          player2Info.style.display = 'block';
        }
      }
      if (data.players && data.players['paddle2']) {
        if (data.len == 2) {
          player1waiting.style.display = 'none';
          player1Info.style.display = 'block';
        }
        ws.send(JSON.stringify({
          'message': 'add_player',
          'player': 'p2',
        }));
        player2waiting.style.display = 'none';
        player2Info.style.display = 'block';
      }
    }
    if (data.message == 'left') {
      if (data.player == 'paddle1') {
        const play1div = document.getElementById("p1-content");
        play1div.innerHTML = `<h1>Player 1 Left, you can leave the game</h1>`;
        if (tournamentGameID != null) {
          play1div.innerHTML = `<h1>Opponent left, waiting for the other match to finish`;
          const play2div = document.getElementById("p2-content");
          play2div.innerHTML = `<h1>Player 1 Left</h1>, waiting for the other match to finish`;
          if (tournamentGameID != "Finals") {
            addWinner(tournamentGameID);
            backToTournament();
          }
          else if (tournamentGameID == "Finals" && intervalMultiID == null) {
            tournamentWin(tmpTournamentID);
            leaveTournament(tmpTournamentID);
            const artificialEvent = { preventDefault: () => { } };
            navigate(artificialEvent, '/game');
          }
        }
      }
      else if (data.player == 'paddle2') {
        const play2div = document.getElementById("p2-content");
        play2div.innerHTML = `<h1>Player 2 Left, you can leave the game</h1>`;
        if (tournamentGameID != null) {
          play2div.innerHTML = `<h1>Opponent left, waiting for the other match to finish`;
          const play1div = document.getElementById("p1-content");
          play1div.innerHTML = `<h1>Player 2 Left, waiting for the other match to finish</h1>`;
          if (tournamentGameID != "Finals") {
            addWinner(tournamentGameID);
            backToTournament();
          }
          else if (tournamentGameID == "Finals" && intervalMultiID == null) {
            tournamentWin(tmpTournamentID);
            leaveTournament(tmpTournamentID);
            const artificialEvent = { preventDefault: () => { } };
            navigate(artificialEvent, '/game');
          }
        }
      }
    }
    if (data['message'] == 'game will start') {
      startGame(ws);
    }
  }

  eventSocketHandlers.beforeUnload = (event) => handleBeforeUnload(notif, event);
  eventSocketHandlers.popState = (event) => handlePopState(notif, event);
  // Listeners to handle leaving while in the game  
  window.addEventListener('beforeunload', eventSocketHandlers.beforeUnload);
  window.addEventListener('popstate', eventSocketHandlers.popState);
  const navLinks = document.querySelectorAll('.nav-link');
  navLinks.forEach((navLink) => {
    const handler = (event) => navLinkClickHandler(notif, event);
    eventSocketHandlers.navLinks.set(navLink, handler);
    navLink.addEventListener('click', handler);
  });
}

function removeMultiListeners() {
  stopAudio();
  const navLinks = document.querySelectorAll('.nav-link');
  navLinks.forEach((navLink) => {
    const handler = eventSocketHandlers.navLinks.get(navLink);
    if (handler) {
      navLink.removeEventListener('click', handler);
      eventSocketHandlers.navLinks.delete(navLink);  // Retirer la référence
    }
  });
  window.removeEventListener('beforeunload', eventSocketHandlers.beforeUnload);
  eventSocketHandlers.beforeUnload = null;
  window.removeEventListener('popstate', eventSocketHandlers.popState);
  eventSocketHandlers.popState = null;
}

async function handleBeforeUnload(notif, event) {
  const id = getMyId();
  await updateStatus(id, "offline");
  if (notif) {
    deleteNotification(notif.id);
  }
  if (intervalMultiID != null) {
    removeGameListeners();
    sendLeaveData();
  }
  else if (tournamentGameID != null) {
    sendLeaveData();
  }
  if (ws.readyState == WebSocket.OPEN) {
    ws.send(JSON.stringify({
      'message': 'disconnect_request',
    }));
  }
  removeMultiListeners();
  return;
}

async function handlePopState(notif, event) {
  const id = getMyId();
  await updateStatus(id, "online");
  if (notif) {
    deleteNotification(notif.id);
  }
  if (intervalMultiID != null) {
    removeGameListeners();
    sendLeaveData();
  }
  else if (tournamentGameID != null) {
    sendLeaveData();
  }
  if (ws.readyState == WebSocket.OPEN) {
    ws.send(JSON.stringify({
      'message': 'disconnect_request',
    }));
  }
  removeMultiListeners();
}

async function navLinkClickHandler(notif, event) {
  const id = getMyId();
  await updateStatus(id, "online");
  const clickedElement = event.currentTarget;
  if (clickedElement) {
    if (clickedElement.classList.contains('exclude-click')) {
      return;
    }
  }
  if (notif) {
    deleteNotification(notif.id);
  }
  if (intervalMultiID != null) {
    removeGameListeners();
    sendLeaveData();
  }
  else if (tournamentGameID != null) {
    sendLeaveData();
  }
  if (ws.readyState == WebSocket.OPEN) {
    ws.send(JSON.stringify({
      'message': 'disconnect_request',
    }));
  }
  removeMultiListeners();
}
