let wsTournament;
let tournamentGameID = null;
let tmpTournamentID = null;
let eventTournamentNavHandler = new Map();


async function socketTournament(tournamentID, playerID, status) {
    const url = `wss://${window.location.host}/ws/tournament/${tournamentID}`;
    const username = localStorage.getItem('username');
    const finalcheck = null;
    const id = getMyId();
    await updateStatus(id, "in game");
    initTournamentListerners();
    if (!wsTournament)
        wsTournament = new WebSocket(url);
    if (status == "Finals")
        checkWinners(tournamentID);
    const backBtn = document.getElementById("go-back-btn");
    if (backBtn != null) {
        backBtn.addEventListener("click", function () {
            updateStatus(id, "online");
            removeTournamentListeners();
            leaveTournament(tmpTournamentID);
            const artificialEvent = { preventDefault: () => { } };
            navigate(artificialEvent, '/game');
        });
    }
    if (tournamentGameID != null) {
        wsTournament.send(JSON.stringify({
            'message': 'winner',
        }));
    }
    wsTournament.onmessage = function (e) {
        var data = JSON.parse(e.data);
        if (data['message'] == "username") {
            wsTournament.send(JSON.stringify({
                'message': 'username',
                'username': username,
                'player_id': playerID,
            }));
        }
        else if (data['message'] == "ready") {
            let players = data['players'];
            tournamentGameID = tournamentID;
            removeTournamentListeners();
            if (playerID < 3)
                acceptFightRequest(players[1], players[2]);
            else
                acceptFightRequest(players[3], players[4]);
        }
        else if (data['message'] == "check-winners" && tournamentGameID != "Finals") {
            checkWinners(tournamentID);
        }
        else if (data['message'] == "finals") {
            if (tournamentGameID != "Finals") {
                if (finalcheck == null) {
                    finalcheck == "ok";
                    const winner1 = data['winner1'];
                    const winner2 = data['winner2'];
                    tmpTournamentID = tournamentGameID;
                    tournamentGameID = "Finals";
                    removeTournamentListeners();
                    acceptFightRequest(winner1, winner2);
                }
            }
        }
    };
}

async function initTournamentListerners() {
    const navLinks = document.querySelectorAll('.nav-link');
    navLinks.forEach((navLink) => {
        const handler = handlerTournamentNavLinkClick;
        navLink.addEventListener('click', handler);
        eventTournamentNavHandler.set(navLink, handler);
    });
    window.addEventListener('beforeunload', handlerTournamentBeforeUnload);
    window.addEventListener('popstate', handlerTournamentPopstate);
}

async function removeTournamentListeners() {
    const navLinks = document.querySelectorAll('.nav-link');
    navLinks.forEach((navLink) => {
        const handler = eventTournamentNavHandler.get(navLink);
        if (handler) {
            navLink.removeEventListener('click', handler);
            eventTournamentNavHandler.delete(navLink);
        }
    });
    window.removeEventListener('beforeunload', handlerTournamentBeforeUnload);
    window.removeEventListener('popstate', handlerTournamentPopstate);
}


async function handlerTournamentNavLinkClick(event) {
    const clickedElement = event.currentTarget;
    if (clickedElement) {
        if (clickedElement.classList.contains('exclude-click')) {
            return;
        }
    }
    if (wsTournament && wsTournament.readyState == WebSocket.OPEN) {
        const id = getMyId();
        updateStatus(id, "online");
        leaveTournament(tmpTournamentID);
    }
    removeTournamentListeners();
}

async function handlerTournamentBeforeUnload() {
    if (wsTournament && wsTournament.readyState == WebSocket.OPEN) {
        const id = getMyId();
        updateStatus(id, "online");
        leaveTournament(tmpTournamentID);
        removeTournamentListeners();
    }
}

async function handlerTournamentPopstate() {
    if (wsTournament && wsTournament.readyState == WebSocket.OPEN) {
        const id = getMyId();
        updateStatus(id, "online");
        leaveTournament(tmpTournamentID);
        removeTournamentListeners();
    }
}

// Init au moment de l'éntrée dans le socket puis retrait a l'entrée en game et ensuite reinit au retour dans le tournoi si winner.
