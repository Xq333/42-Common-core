async function checkTournament() {
    const csrfToken = getCookie('csrftoken');
    const jwt_token = localStorage.getItem('jwt_token');
    const response = await fetch('/game/check-tournament', {
        method: "POST",
        headers: {
            "Content-Type": "application/json",
            "X-CSRFToken": csrfToken,
            'Authorization': 'Bearer ' + jwt_token,
        },
    });
    const data = await response.json();
    const tournamentID = data.tournament_id;
    if (tournamentID != null) {
        document.getElementById("content").innerHTML = `
        <div id="popup-overlay" class=open>
            <div class="popup-content">
                <div class= "clearfix">
                    <h1>Waiting for 4 players to join...</h1>
                    <p><div class="spinner-border text-primary" style="width: 3rem; height: 3rem;" role="status">
                        <span class="visually-hidden">Loading...</span>
                    </div></p>
                    <button class="cancelbtn" id="go-back-btn" href="/game">Back to Menu</button>
                </div>
            </div>
        </div>`;
        await joinTournament(tournamentID);
    } else {
        console.log("Tournament ID is null");
    }
}

async function joinTournament(tournamentID) {
    const csrfToken = getCookie('csrftoken');
    const jwt_token = localStorage.getItem('jwt_token');
    const response = await fetch('/game/join-tournament', {
        method: "POST",
        headers: {
            "Content-Type": "application/json",
            "X-CSRFToken": csrfToken,
            'Authorization': 'Bearer ' + jwt_token,
        },
        body: JSON.stringify({
            tournament_id: tournamentID,
        }),
    });
    const data = await response.json();
    if (data.status == "success") {
        tmpTournamentID = tournamentID;
        socketTournament(tournamentID, data.player_id, "demi");
    }
    else {
        console.log("Failed to join tournament");
    }
}

async function addWinner(tournamentID) {
    const csrfToken = getCookie('csrftoken');
    const jwt_token = localStorage.getItem('jwt_token');
    const response = await fetch('/game/add-winner', {
        method: "PUT",
        headers: {
            "Content-Type": "application/json",
            "X-CSRFToken": csrfToken,
            'Authorization': 'Bearer ' + jwt_token,
        },
        body: JSON.stringify({
            tournament_id: tournamentID,
        }),
    });
    const data = await response.json();
    if (data.status != 'success')
        console.log("Error something wrong happend");
}

async function checkWinners(tournamentID) {
    if (wsTournament == null && intervalMultiID != null)
        return;
    const csrfToken = getCookie('csrftoken');
    const jwt_token = localStorage.getItem('jwt_token');
    const response = await fetch('/game/check-winners', {
        method: "PUT",
        headers: {
            "Content-Type": "application/json",
            "X-CSRFToken": csrfToken,
            'Authorization': 'Bearer ' + jwt_token,
        },
        body: JSON.stringify({
            tournament_id: tournamentID,
        }),
    });
    const data = await response.json();
    if (data.status == "success") {
        if (data.winners == 2 && data.losers == 2) {
            if (wsTournament != null && wsTournament.readyState == WebSocket.OPEN) {
                wsTournament.send(JSON.stringify({
                    'message': 'finals',
                    'winner1': data.winner1,
                    'winner2': data.winner2,
                }));
            }
        }
        else if (data.winners == 1 && data.losers == 3)
        {   
            if (intervalMultiID != null)
                return;
            await tournamentWin(tournamentID);
            leaveTournament(tournamentID);
            const artificialEvent = { preventDefault: () => { } };
            navigate(artificialEvent, '/game');
            printFlashMessage("You win the tournament, the opponents left");
        }
        else if (data.winners == 3)
            await tournamentWin(tournamentID);
        else if (data.winners == 2 && data.losers == 3) {
            if (intervalMultiID != null)
                return;
            await tournamentWin(tournamentID);
            leaveTournament(tournamentID);
            const artificialEvent = { preventDefault: () => { } };
            navigate(artificialEvent, '/game');
            printFlashMessage("You win the tournament");
        }
    }
    else {
        console.log("Fail check winners");
        // error 404
    }
}

async function tournamentWin(tournamentID) {
    const csrfToken = getCookie('csrftoken');
    const jwt_token = localStorage.getItem('jwt_token');
    const response = await fetch('/game/tournament-win', {
        method: "PUT",
        headers: {
            "Content-Type": "application/json",
            "X-CSRFToken": csrfToken,
            'Authorization': 'Bearer ' + jwt_token,
        },
        body: JSON.stringify({
            tournament_id: tournamentID,
        }),
    });
    const data = await response.json();
    if (data.status != "success") {
        console.log("Fail to fetch tournament win");
        // error 404
    }
}

async function leaveTournament(tournamentID) {
    const csrfToken = getCookie('csrftoken');
    const jwt_token = localStorage.getItem('jwt_token');
    const response = await fetch('/game/leave-tournament', {
        method: "PUT",
        headers: {
            "Content-Type": "application/json",
            "X-CSRFToken": csrfToken,
            'Authorization': 'Bearer ' + jwt_token,
        },
        body: JSON.stringify({
            tournament_id: tournamentID,
        }),
    });
    const data = await response.json();
    if (data.status == "success") {
        if (tournamentGameID == "Finals") {
            wsTournament.send(JSON.stringify({
                'message': 'disconnect_request',
            }));
            tournamentGameID = null;
            wsTournament = null;
        }
        else {
            if (wsTournament != null && wsTournament.readyState == WebSocket.OPEN)
            {    
                wsTournament.send(JSON.stringify({
                    'message': 'match_done',
                }));
                tournamentGameID = null;
                wsTournament = null;
            }
        }
    }
    else {
        console.log("User already deleted");
        return;
    }
}


async function flashMessageTournament(tournamentID) {
    const csrfToken = getCookie('csrftoken');
    const jwt_token = localStorage.getItem('jwt_token');
    const response = await fetch('/game/flash-message-tournament', {
        method: "PUT",
        headers: {
            "Content-Type": "application/json",
            "X-CSRFToken": csrfToken,
            'Authorization': 'Bearer ' + jwt_token,
        },
        body: JSON.stringify({
            tournament_id: tournamentID,
        }),
    });
    const data = await response.text();
    if (data.status == "failed")
        console.log("Failed to get flash message");
    else {
        const flashMessage = document.getElementById("tournament-overlay");
        flashMessage.innerHTML = data;
        console.log(data);
    }
}
