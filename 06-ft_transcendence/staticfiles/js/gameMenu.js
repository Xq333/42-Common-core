function loadMenuPage() {
    fetch('/game/game-menu')
    .then(response => response.text())
	.then(html => {
		  document.getElementById('content').innerHTML = html;
	});
}

async function matchmakingQueue() {
    const csrfToken = getCookie('csrftoken');
    const jwt_token = localStorage.getItem('jwt_token');
    const response = await fetch('/ws/matchmaking', {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      "X-CSRFToken": csrfToken,
      'Authorization': 'Bearer ' + jwt_token,
    },
    });
    const data = await response.text();
    const newBodyHtml = data;
    document.getElementById("content").innerHTML = newBodyHtml;
    socketMatchmaking();
}

function oneVsOneButtons() {
    document.getElementById('game-buttons').innerHTML = `
    <button id="onevsrandom" href="/onevsrandom-choice" onclick="matchmakingQueue()" class="cancelbtn">Play vs a Random Player</button>
    <button id="onevsfriend" href="/onevsfriend-choice" onclick="navigate(event, '/friends')"  class="cancelbtn">Play vs a Friend</button>
    <button id="retourmenu" href="/game" onclick="loadMenuPage()" class="cancelbtn">Back to Game Menu</button>
    `
}

function tournamentMenu() {
    fetch('/game/tournament-menu')
    .then(response => response.text())
	.then(html => {
		  document.getElementById('content').innerHTML = html;
	});
}
