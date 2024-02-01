let ball, game, scoreAElement, scoreBElement;
let gameWidth, gameHeight;
let ballX, ballY;
let paddleA = { x: 0, y: 0 };
let paddleB = { x: 0, y: 0 };
let ballSpeedX, ballSpeedY;
let lastUpdateTime;
let accelerationFactor = 1.1;

let scoreA = 0, scoreB = 0;
let paddleSpeed;
const maxScore = 10;
let intervalMultiID = null;
let winner;
let rightPlayer;
let leftPlayer;
let opponentPlayer;
let finalScore;
let victory = false;
let paddleId;
let displacement;
let keys = {
  e: false,
  d: false,
  ArrowUp: false,
  ArrowDown: false,
};
let currentPaddle = {x: 0, y: 0};
let opponentPaddle = {x: 0, y: 0};

let audio;


function startGame(ws) {
    audio = new Audio('/static/assets/KarolPiczak-LesChampsEtoiles.mp3');
    audio.loop = true;
    audio.play();
    ws.send(JSON.stringify({
        'message': 'player',
    }));



  const pong = document.createElement("div");
  pong.id = "pong";

  const paddleAA = document.createElement("div");
  paddleAA.id = "paddleA";
  paddleAA.classList.add("paddle");

  const paddleBB = document.createElement("div");
  paddleBB.id = "paddleB";
  paddleBB.classList.add("paddle");

  const balll = document.createElement("div");
  balll.id = "ball";

  const scoreAA = document.createElement("div");
  scoreAA.id = "scoreA";
  scoreAA.classList.add("score");
  scoreAA.textContent = "0";

  const scoreBB = document.createElement("div");
  scoreBB.id = "scoreB";
  scoreBB.classList.add("score");
  scoreBB.textContent = "0";

  const rulesText = document.createElement("div");
  rulesText.id = "rulesText";
  rulesText.style.display = 'block';
  rulesText.innerHTML = "To move the paddle:<br><strong>E</strong> &#x2B06; - for moving up<br><strong>D</strong> &#x2B07; - for moving down";
  rulesText.addEventListener('animationend', () => {
    rulesText.style.display = 'none';
  });

  pong.appendChild(paddleAA);
  pong.appendChild(paddleBB);
  pong.appendChild(balll);
  pong.appendChild(scoreAA);
  pong.appendChild(scoreBB);
  pong.appendChild(rulesText);

  document.getElementById("content").innerHTML = "";
  document.getElementById("content").appendChild(pong);

  paddleA = document.getElementById("paddleA");
  paddleB = document.getElementById("paddleB");
  ball = document.getElementById("ball");
  game = document.getElementById("pong");
  scoreAElement = document.getElementById("scoreA");
  scoreBElement = document.getElementById("scoreB");

  window.addEventListener("keydown", handleKeyDown);
  window.addEventListener("keyup", handleKeyUp);
  window.addEventListener("resize", resizeGame);

    initGame();
    ws.onmessage = function (e) {
        if (e.data) {
            const data = JSON.parse(e.data);
            // Mettre à jour le paddle approprié
            if (data['message'] == 'init_paddle') {
                leftPlayer = data['player1'];
                rightPlayer = data['player2'];
                paddleId = data['paddle_id'];
                intervalMultiID = setInterval(function () {
                        update(ws);
                    }, 10);
                if (paddleId == 'paddle1'){
                    opponentPlayer = rightPlayer;
                    currentPaddle = paddleA;
                    opponentPaddle = paddleB;
                }
                else if (paddleId == 'paddle2'){
                    opponentPlayer = leftPlayer;
                    currentPaddle = paddleB;
                    opponentPaddle = paddleA;
                }
                
            }
            else if (data['message'] == 'paddle_move') {
                if (paddleId != data['paddle_id']) {
                    const test = data['movement'];
                    updateOpponentPaddle(test);
                }
            }
            else if (data['message'] == 'goal') {
                let ballMessage = data['ball'];
                let pointA = data['scoreA'];
                let pointB = data['scoreB'];
                if (ballMessage < 50) {
                    if (pointB != scoreB)
                        scoreB = pointB;
                    resetBall('A');
                }
                else {
                    if (pointA != scoreA)
                        scoreA = pointA;
                    resetBall('B');
                }
                scoreAElement.textContent = scoreA;
                scoreBElement.textContent = scoreB;
            }
            else if (data['message'] == 'paddle') {
                let ballMessageX = data['ballX'];
                let ballMessageY = data['ballY'];
                updateBall(ballMessageX, ballMessageY);
            }
        }
    };
}

function removeGameListeners() {
  clearInterval(intervalMultiID);
  intervalMultiID = null;
  window.removeEventListener("keydown", handleKeyDown);
  window.removeEventListener("keyup", handleKeyUp);
  window.removeEventListener("resize", resizeGame);
  const id = getMyId();
}

function updateBall(receivedPositionX, receivedPositionY) {
  const absolutePositionX = (receivedPositionX / 100) * gameWidth;
  const absolutePositionY = (receivedPositionY / 100) * gameHeight;
  ballX = absolutePositionX;
  ballY = absolutePositionY;

  let ballLeft = ballX - (ball.offsetWidth / 2);
  let ballTop = ballY - (ball.offsetHeight / 2);
  ball.style.left = ballLeft + "px";
  ball.style.top = ballTop + "px";
}

function updateOpponentPaddle(receivedPosition) {
  const absolutePosition = (receivedPosition / 100) * gameHeight;
  opponentPaddle.y = absolutePosition;
  if (opponentPaddle && opponentPaddle.style) {
    opponentPaddle.style.top = `${receivedPosition}%`;
  }
}

function checkGoal(ws) {
  const ballXgoalPercent = ((ballX - (ball.offsetWidth / 2)) / gameWidth) * 100;
  const ballXrightPercent = ((ballX + (ball.offsetWidth / 2)) / gameWidth) *
    100;

  if (ballXgoalPercent <= 0.1) {
    scoreB++;
    ws.send(JSON.stringify({
      "message": "collision",
      "kind": "goal",
      "ballX": (ballX / gameWidth) * 100,
      "ballY": (ballY / gameHeight) * 100,
      "scoreA": scoreA,
      "scoreB": scoreB,
    }));
    ballX = gameWidth / 2;
    ballY = gameHeight / 2;
    return;
  } else if (ballXrightPercent >= 99.9) {
    scoreA++;
    ws.send(JSON.stringify({
      "message": "collision",
      "kind": "goal",
      "ballX": (ballX / gameWidth) * 100,
      "ballY": (ballY / gameHeight) * 100,
      "scoreA": scoreA,
      "scoreB": scoreB,
    }));
    ballX = gameWidth / 2;
    ballY = gameHeight / 2;
    return;
  }
}

function updateBallPosition(timeElapsed) {
  const xDisplacementPercent = ballSpeedX * timeElapsed;
  const yDisplacementPercent = ballSpeedY * timeElapsed;

  const xDisplacementPixels = (xDisplacementPercent / 100) * gameWidth;
  const yDisplacementPixels = (yDisplacementPercent / 100) * gameHeight;

  ballX += xDisplacementPixels;
  ballY += yDisplacementPixels;
}

function update(ws) {
  checkGameOver(ws);
  const currentTime = Date.now();
  const timeElapsed = (currentTime - lastUpdateTime) / 1000;
  lastUpdateTime = currentTime;

  updateBallPosition(timeElapsed);

  if (keys.e && currentPaddle.y > 0) {
    currentPaddle.y -= paddleSpeed;
  }
  if (keys.d && currentPaddle.y < gameHeight - currentPaddle.offsetHeight) {
    currentPaddle.y += paddleSpeed;
  }
  const relativePaddlePosition = (currentPaddle.y / gameHeight) * 100;
  ws.send(JSON.stringify({
    "message": "movement",
    "position": relativePaddlePosition,
  }));

  if (ballY <= 0 + ball.offsetHeight) {
    ballY = 0 + ball.offsetHeight;
    ballSpeedY *= -1;
  } else if (ballY >= gameHeight - ball.offsetHeight) {
    ballY = gameHeight - ball.offsetHeight;
    ballSpeedY *= -1;
  }

  checkCollisionWithPaddleA(ws);
  checkCollisionWithPaddleB(ws);
  checkGoal(ws);

  let ballLeft = (ballX - (ball.offsetWidth / 2)) / gameWidth * 100;
  let ballTop = (ballY - (ball.offsetHeight / 2)) / gameHeight * 100;
  ball.style.left = `${ballLeft}%`;
  ball.style.top = `${ballTop}%`;

  let paddleAtop = currentPaddle.y / gameHeight * 100;
  let paddleBtop = opponentPaddle.y / gameHeight * 100;
  currentPaddle.style.top = `${paddleAtop}%`;
  opponentPaddle.style.top = `${paddleBtop}%`;
}

function checkCollisionWithPaddleA(ws) {
  if (ballSpeedX < 0) {
    const ballXPercent = ((ballX - (ball.offsetWidth / 2)) / gameWidth) * 100;
    const ballYPercent = (ballY / gameHeight) * 100;

    const ballHeightPercent = ((ball.offsetHeight / 2) / gameHeight) * 100;

    const paddleALeftEdgePercent = (paddleA.offsetWidth / gameWidth) * 100;
    const paddleAYPercent = (paddleA.y / gameHeight) * 100;

    if (ballXPercent <= paddleALeftEdgePercent &&
        ballYPercent <= paddleAYPercent + ((paddleA.offsetHeight / gameHeight) * 100) &&
        ballYPercent + ballHeightPercent >= paddleAYPercent) {
    
        ballSpeedX *= -1  * accelerationFactor;
        ballSpeedY *= accelerationFactor;
        ws.send(JSON.stringify({
            'message': 'collision',
            'kind': 'paddle',
            'ballX': (ballX / gameWidth) * 100,
            'ballY': (ballY / gameHeight) * 100,
            'scoreA': scoreA,
            'scoreB': scoreB,
        }));
        return;
    }
  }
}

function checkCollisionWithPaddleB(ws) {
  if (ballSpeedX > 0) {
    const ballXPercent = ((ballX + (ball.offsetWidth / 2)) / gameWidth) * 100;
    const ballYPercent = (ballY / gameHeight) * 100;

    const ballHeightPercent = ((ball.offsetHeight / 2) / gameHeight) * 100;

    const paddleBRightEdgePercent = 100 -
      ((paddleB.offsetWidth / gameWidth) * 100); // PaddleB est positionné à droite
    const paddleBYPercent = (paddleB.y / gameHeight) * 100;

        if (ballXPercent >= paddleBRightEdgePercent && 
            ballYPercent <= paddleBYPercent + ((paddleB.offsetHeight / gameHeight) * 100) &&
            ballYPercent + ballHeightPercent >= paddleBYPercent) {

            ballSpeedX *= -1  * accelerationFactor;
            ballSpeedY *= accelerationFactor;
            ws.send(JSON.stringify({
                'message': 'collision',
                'kind': 'paddle',
                'ballX': (ballX / gameWidth) * 100,
                'ballY': (ballY / gameHeight) * 100,
                'scoreA': scoreA,
                'scoreB': scoreB,
            }));
            return;
        }
    }
}

function initGame() {
  gameWidth = game.offsetWidth;
  gameHeight = game.offsetHeight;

  const paddleHeight = gameHeight * 0.2;

  paddleA.style.height = `${paddleHeight}px`;
  paddleB.style.height = `${paddleHeight}px`;

  paddleA.y = (gameHeight - paddleHeight) / 2;
  paddleB.y = (gameHeight - paddleHeight) / 2;

  paddleA.style.top = `${paddleA.y}px`;
  paddleB.style.top = `${paddleB.y}px`;

  paddleSpeed = 0.008 * gameHeight;

  const ballSize = gameWidth * 0.015;
  ballX = gameWidth / 2;
  ballY = gameHeight / 2;
  ball.style.width = `${ballSize}px`;
  ball.style.height = `${ballSize}px`;
  ball.style.left = (ballX - ball.offsetWidth / 2) + "px";
  ball.style.top = (ballY - ball.offsetHeight / 2) + "px";

  ballSpeedX = 30;
  ballSpeedY = (30 / gameWidth) * gameHeight;

  scoreA = 0;
  scoreB = 0;
  scoreAElement.textContent = scoreA;
  scoreBElement.textContent = scoreB;
  lastUpdateTime = Date.now();
}

function handleKeyDown(e) {
  if (keys.hasOwnProperty(e.key)) {
    keys[e.key] = true;
  }
}

function handleKeyUp(e) {
  if (keys.hasOwnProperty(e.key)) {
    keys[e.key] = false;
  }
}

function resizeGame() {
  let tmpPaddleA = paddleA.y / gameHeight;
  let tmpPaddleB = paddleB.y / gameHeight;
  let tmpSpeedY = ballSpeedY;
  let tmpBallX = ballX / gameWidth;
  let tmpBallY = ballY / gameHeight;

  gameWidth = game.offsetWidth;
  gameHeight = game.offsetHeight;

  ballSpeedY = (30 / gameWidth) * gameHeight;
  if (tmpSpeedY < 0) {
    ballSpeedY *= -1;
  }

  const paddleHeight = gameHeight * 0.2;

  paddleA.style.height = `${paddleHeight}px`;
  paddleB.style.height = `${paddleHeight}px`;

  paddleA.y = tmpPaddleA * gameHeight;
  paddleB.y = tmpPaddleB * gameHeight;

  paddleA.style.top = `${tmpPaddleA * 100}%`;
  paddleB.style.top = `${tmpPaddleB * 100}%`;

  paddleSpeed = 0.008 * gameHeight;

  const ballSize = gameWidth * 0.015;
  ball.style.width = `${ballSize}px`;
  ball.style.height = `${ballSize}px`;
  ballX = tmpBallX * gameWidth;
  ballY = tmpBallY * gameHeight;
  ball.style.left = `${(ballX - ball.offsetWidth) / gameWidth * 100}%`;
  ball.style.top = `${(ballY - ball.offsetHeight) / gameHeight * 100}%`;
}

function resetBall(winner) {
  ballX = gameWidth / 2;
  ballY = gameHeight / 2;

  ballSpeedX = 30;
  ballSpeedY = (30 / gameWidth) * gameHeight;

  ball.style.left = (ballX - ball.offsetWidth / 2) + "px";
  ball.style.top = (ballY - ball.offsetHeight / 2) + "px";
  if (winner === "B") {
    ballSpeedX = ballSpeedX * -1;
  }
}

function backToMenu(ws) {
    fetch('/')
        .then(response => response.text())
        .then(html => {
            const parser = new DOMParser();
            const doc = parser.parseFromString(html, 'text/html');

      const newBodyHtml = doc.querySelector("body").innerHTML;
      document.body.innerHTML = newBodyHtml;

      document.getElementById("logout").style.display = "block";
      document.getElementById("registerFormular").style.display = "none";
      document.getElementById("loginFormular").style.display = "none";
      for (const link of document.querySelectorAll("a")) {
        if (link.getAttribute("href").startsWith("/")) {
          link.addEventListener(
            "click",
            (event) => navigate(event, link.getAttribute("href")),
          );
        }
      }
      const id = getMyId();
      updateStatus(id, "online");
      removeGameListeners();
      removeMultiListeners();
      ws.send(JSON.stringify({
        "message": "disconnect_request",
      }));
      const artificialEvent = { preventDefault: () => {} };
      navigate(artificialEvent, "/game");
      printFlashMessage(`Game done.`);
    });
}

function checkGameOver(ws) {
    if (scoreA >= maxScore || scoreB >= maxScore) {
        winner = scoreA > scoreB ? leftPlayer : rightPlayer;
        if (winner == opponentPlayer)
            victory = false;
        else
            victory = true;
        finalScore = scoreA + " - " + scoreB;
        clearInterval(intervalMultiID);
        intervalMultiID = null;
        sendData();
        if (tournamentGameID != null && tournamentGameID != "Finals") {
            addWinner(tournamentGameID);
            backToTournament();
          }
        else    
            backToMenu(ws);
    }
}
async function backToTournament() {
    removeGameListeners();
    removeMultiListeners();
    ws.send(JSON.stringify({
        'message': 'disconnect_request',
    }));
    document.getElementById("content").innerHTML = `
    <div id="popup-overlay" class=open>
      <div class="popup-content">
        <div class= "clearfix">
        <h1>Waiting for the other players to finish...</h1>
        <p><div class="spinner-border text-primary" style="width: 3rem; height: 3rem;" role="status">
          <span class="visually-hidden">Loading...</span>
        </div></p>
      </div>
    </div>`;
    socketTournament(tournamentGameID, getMyId(), "Finals");

}
async function sendData() {
    const jwt_token = localStorage.getItem('jwt_token');
    try {
        let data = {
            score: finalScore,
            victory: victory,
            opponent: opponentPlayer,
        };
        if ((victory == false && tournamentGameID != null)  || (tournamentGameID == "Finals" && victory == true)) {
            let tmp = tournamentGameID;
            if (tournamentGameID == "Finals")
              tmp = tmpTournamentID;
            if (tournamentGameID == "Finals" && victory == true)
            {    
              tournamentGameID = null;
              tmpTournamentID = null;
              await tournamentWin(tmp);
            }
            else
              tournamentGameID = null;
            leaveTournament(tmp);
        }
        const response = await fetch('/game/add-match', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
                'X-CSRFToken': getCookie('csrftoken'),
                'Authorization': 'Bearer ' + jwt_token
            },
            body: JSON.stringify(data),
        })
        const json = await response.json();
    }
    catch (error) {
        console.error('Error:', error);
    }
}

async function sendLeaveData() {
    const jwt_token = localStorage.getItem('jwt_token');
    try {
        let data = {
            score: "Match leaved",
            victory: false,
            opponent: opponentPlayer,
        };
        if (tournamentGameID != null)
        {
            leaveTournament(tmpTournamentID);
        }
        const response = await fetch('/game/add-match', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
                'X-CSRFToken': getCookie('csrftoken'),
                'Authorization': 'Bearer ' + jwt_token
            },
            body: JSON.stringify(data),
        })
        const json = await response.json();
    }
    catch (error) {
        console.error('Error:', error);
    }
}

function stopAudio() {
    if (audio) {
        audio.pause();
        audio.currentTime = 0;
    }
}
