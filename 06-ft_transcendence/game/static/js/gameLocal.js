class LocalGame {
    constructor() {
        this.ball = null;
        this.game = null;
        this.scoreAElement = null;
        this.scoreBElement = null;
        this.gameWidth = null;
        this.gameHeight = null;
        this.ballX = null;
        this.ballY = null;
        this.paddleA = {x: 0, y: 0};
        this.paddleB = {x: 0, y: 0};
        this.ballSpeedX = null;
        this.ballSpeedY = null;
        this.lastUpdateTime = null;
        this.accelerationFactor = 1.1;
        this.scoreA = 0;
        this.scoreB = 0;
        this.paddleSpeed;
        this.maxScore = 3;
        this.intervalID = null;
        this.winner = null;
        this.leftPlayer = "Player 1";
        this.rightPlayer = "Player 2";
        this.finalScore = null;
        this.victory = false;
        this.paddleId = null;
        this.displacement = null;
        this.isGamePaused_l = false;
        this.keys = {
            e: false,
            d: false,
            ArrowUp: false,
            ArrowDown: false,
        };
    
    }


}

const localGame = new LocalGame();
let intervalID = null;

function startLocalGame() {
    audio = new Audio('/static/assets/KarolPiczak-LesChampsEtoiles.mp3');
    audio.loop = true;
    audio.play();
    
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
    rulesText.innerHTML = "To move the paddles:<br><strong>'E'</strong> - Move left paddle up<br><strong>'D'</strong> - Move left paddle down<br><strong>Up Arrow</strong> &#x2B06; - Move right paddle up<br><strong>Down Arrow</strong> &#x2B07; - Move right paddle down.<br><br>Press <strong>Space</strong> to pause the game.";
    rulesText.addEventListener('animationend', () => {
      rulesText.style.display = 'none';
    });

    pong.appendChild(paddleAA);
    pong.appendChild(paddleBB);
    pong.appendChild(balll);
    pong.appendChild(scoreAA);
    pong.appendChild(scoreBB);
    pong.appendChild(rulesText);
    
    document.getElementById('content').innerHTML = ''
    document.getElementById('content').appendChild(pong);
    
    localGame.paddleA = document.getElementById('paddleA');
    localGame.paddleB = document.getElementById('paddleB');
    localGame.ball = document.getElementById('ball');
    localGame.game = document.getElementById('pong');
    localGame.scoreAElement = document.getElementById('scoreA');
    localGame.scoreBElement = document.getElementById('scoreB');
    
    window.addEventListener('keydown', handleLocalKeyDown);
    window.addEventListener('keyup', handleLocalKeyUp);
    window.addEventListener('resize', resizeLocalGame);
    window.addEventListener('keydown', handleKeySpace);
    window.addEventListener('popstate', handleLocalPopstate);
    
    initLocalGame();
    const myId = getMyId();
    updateStatus(myId, "in game");
    intervalID = setInterval(function () {
        updateLocal();
    }, 10);
}

function updateScoreAndAnimate(scoreElement) {
  scoreElement.classList.add('pulse'); // Ajoute la classe pulse
  setTimeout(() => {
    scoreElement.classList.remove('pulse'); // Retire la classe après 1 seconde
  }, 1000);
}

function checkLocalGoal() {
  const ballXgoalPercent =
    ((localGame.ballX - (localGame.ball.offsetWidth / 2)) /
      localGame.gameWidth) * 100;
  const ballXrightPercent =
    ((localGame.ballX + (localGame.ball.offsetWidth / 2)) /
      localGame.gameWidth) * 100;

  if (ballXgoalPercent <= 0.1) {
    localGame.scoreB++;
    localGame.scoreBElement.textContent = localGame.scoreB;
    updateScoreAndAnimate(localGame.scoreBElement);
    resetLocalBall("A");
  } else if (ballXrightPercent >= 99.9) {
    localGame.scoreA++;
    localGame.scoreAElement.textContent = localGame.scoreA;
    updateScoreAndAnimate(localGame.scoreAElement);
    resetLocalBall("B");
  }
}

function updateLocalBallPosition(timeElapsed) {
  // Calculer le déplacement en pourcentage de la largeur et de la hauteur du jeu
  const xDisplacementPercent = localGame.ballSpeedX * timeElapsed; // ballSpeedX est en %/s
  const yDisplacementPercent = localGame.ballSpeedY * timeElapsed; // ballSpeedY est en %/s

  // Convertir le déplacement en pourcentage en pixels
  const xDisplacementPixels = (xDisplacementPercent / 100) *
    localGame.gameWidth;
  const yDisplacementPixels = (yDisplacementPercent / 100) *
    localGame.gameHeight;

  // Mettre à jour les positions de la balle
  localGame.ballX += xDisplacementPixels;
  localGame.ballY += yDisplacementPixels;
}

function updateLocal() {
  checkLocalGameOver();
  const currentTime = Date.now();
  if (this.isGamePaused_l) {
    localGame.lastUpdateTime = currentTime; // Réinitialiser le temps de mise à jour après la pause
    return; // Arrêter la mise à jour si le jeu est en pause
  }
  const timeElapsed = (currentTime - localGame.lastUpdateTime) / 1000;
  localGame.lastUpdateTime = currentTime;
  // Calculer le déplacement en fonction du temps écoulé
  updateLocalBallPosition(timeElapsed);

  if (localGame.keys.e && localGame.paddleA.y > 0) {
    localGame.paddleA.y -= localGame.paddleSpeed;
  }
  if (
    localGame.keys.d &&
    localGame.paddleA.y < localGame.gameHeight - localGame.paddleA.offsetHeight
  ) {
    localGame.paddleA.y += localGame.paddleSpeed;
  }
  if (localGame.keys.ArrowUp && localGame.paddleB.y > 0) {
    localGame.paddleB.y -= localGame.paddleSpeed;
  }
  if (
    localGame.keys.ArrowDown &&
    localGame.paddleB.y < localGame.gameHeight - localGame.paddleB.offsetHeight
  ) {
    localGame.paddleB.y += localGame.paddleSpeed;
  }

  // Collision avec les murs verticaux
  if (localGame.ballY <= 0 + localGame.ball.offsetHeight) {
    localGame.ballY = 0 + localGame.ball.offsetHeight; // Réinitialiser la position de la balle
    localGame.ballSpeedY *= -1;
  } else if (
    localGame.ballY >= localGame.gameHeight - localGame.ball.offsetHeight
  ) {
    localGame.ballY = localGame.gameHeight - localGame.ball.offsetHeight; // Réinitialiser la position de la balle
    localGame.ballSpeedY *= -1;
  }

  checkLocalCollisionWithPaddleA();
  checkLocalCollisionWithPaddleB();
  checkLocalGoal();

  // Mise à jour de la position de la balle
  let ballLeft = (localGame.ballX - (localGame.ball.offsetWidth / 2)) /
    localGame.gameWidth * 100;
  let ballTop = (localGame.ballY - (localGame.ball.offsetHeight / 2)) /
    localGame.gameHeight * 100;
  localGame.ball.style.left = `${ballLeft}%`;
  localGame.ball.style.top = `${ballTop}%`;

  // Mise à jour de la position des paddles
  let paddleAtop = localGame.paddleA.y / localGame.gameHeight * 100;
  let paddleBtop = localGame.paddleB.y / localGame.gameHeight * 100;
  localGame.paddleA.style.top = `${paddleAtop}%`;
  localGame.paddleB.style.top = `${paddleBtop}%`;
}

function checkLocalCollisionWithPaddleA() {
  // Convertir les positions absolues en pourcentages
  if (localGame.ballSpeedX < 0) {
    const ballXPercent = ((localGame.ballX - (localGame.ball.offsetWidth / 2)) /
      localGame.gameWidth) * 100;
    const ballYPercent = (localGame.ballY / localGame.gameHeight) * 100;

    // Taille de la balle en pourcentage
    const ballHeightPercent =
      ((localGame.ball.offsetHeight / 2) / localGame.gameHeight) * 100;

    // Position du paddleA en pourcentage
    const paddleALeftEdgePercent =
      (localGame.paddleA.offsetWidth / localGame.gameWidth) * 100; // PaddleA est positionné à gauche
    const paddleAYPercent = (localGame.paddleA.y / localGame.gameHeight) * 100;

    // Vérifier la collision avec paddleA
    if (
      ballXPercent <= paddleALeftEdgePercent &&
      ballYPercent <=
        paddleAYPercent +
          ((localGame.paddleA.offsetHeight / localGame.gameHeight) * 100) &&
      ballYPercent + ballHeightPercent >= paddleAYPercent
    ) {
      localGame.ballSpeedX *= -1 * localGame.accelerationFactor;
      localGame.ballSpeedY *= localGame.accelerationFactor;
      return;
    }
  }
}

function checkLocalCollisionWithPaddleB() {
  // Convertir les positions absolues en pourcentages
  if (localGame.ballSpeedX > 0) {
    const ballXPercent = ((localGame.ballX + (localGame.ball.offsetWidth / 2)) /
      localGame.gameWidth) * 100;
    const ballYPercent = (localGame.ballY / localGame.gameHeight) * 100;

    const ballHeightPercent =
      ((localGame.ball.offsetHeight / 2) / localGame.gameHeight) * 100;

    // Position du paddleB en pourcentage
    const paddleBRightEdgePercent = 100 -
      ((localGame.paddleB.offsetWidth / localGame.gameWidth) * 100); // PaddleB est positionné à droite
    const paddleBYPercent = (localGame.paddleB.y / localGame.gameHeight) * 100;

    // Vérifier la collision avec paddleB
    if (
      ballXPercent >= paddleBRightEdgePercent &&
      ballYPercent <=
        paddleBYPercent +
          ((localGame.paddleB.offsetHeight / localGame.gameHeight) * 100) &&
      ballYPercent + ballHeightPercent >= paddleBYPercent
    ) {
      localGame.ballSpeedX *= -1 * localGame.accelerationFactor;
      localGame.ballSpeedY *= localGame.accelerationFactor;
      return;
    }
  }
}

function initLocalGame() {
  localGame.gameWidth = localGame.game.offsetWidth;
  localGame.gameHeight = localGame.game.offsetHeight;

  // Mise à jour de la hauteur des paddles en fonction de la hauteur de la zone de jeu
  const paddleHeight = localGame.gameHeight * 0.2; // 20% de la hauteur de la zone de jeu

  localGame.paddleA.style.height = `${paddleHeight}px`;
  localGame.paddleB.style.height = `${paddleHeight}px`;

  // Positionnement des paddles
  localGame.paddleA.y = (localGame.gameHeight - paddleHeight) / 2;
  localGame.paddleB.y = (localGame.gameHeight - paddleHeight) / 2;

  localGame.paddleA.style.top = `${localGame.paddleA.y}px`;
  localGame.paddleB.style.top = `${localGame.paddleB.y}px`;
  localGame.paddleSpeed = 0.008 * localGame.gameHeight;

  // Position et taille initiales de la balle
  const ballSize = localGame.gameWidth * 0.015; // 1.5% de la largeur de la zone de jeu pour la taille de la balle
  localGame.ballX = localGame.gameWidth / 2;
  localGame.ballY = localGame.gameHeight / 2;
  localGame.ball.style.width = `${ballSize}px`;
  localGame.ball.style.height = `${ballSize}px`;
  localGame.ball.style.left =
    (localGame.ballX - localGame.ball.offsetWidth / 2) + "px";
  localGame.ball.style.top =
    (localGame.ballY - localGame.ball.offsetHeight / 2) + "px";
  // Vitesse de la balle
  localGame.ballSpeedX = 30;
  localGame.ballSpeedY = (30 / localGame.gameWidth) * localGame.gameHeight;

  localGame.scoreA = 0;
  localGame.scoreB = 0;
  localGame.scoreAElement.textContent = localGame.scoreA;
  localGame.scoreBElement.textContent = localGame.scoreB;
  localGame.lastUpdateTime = Date.now();

  this.isGamePaused_l = false; 
}

function handleLocalKeyDown(e) {
  if (localGame.keys.hasOwnProperty(e.key)) {
    e.preventDefault()
    localGame.keys[e.key] = true;
  }
}

function handleLocalKeyUp(e) {
  if (localGame.keys.hasOwnProperty(e.key)) {
    e.preventDefault()
    localGame.keys[e.key] = false;
  }
}

function handleLocalPopstate() {
  removeLocalGameListeners();
}

function resizeLocalGame() {
  let tmpPaddleA = localGame.paddleA.y / localGame.gameHeight;
  let tmpPaddleB = localGame.paddleB.y / localGame.gameHeight;
  let tmpSpeedY = localGame.ballSpeedY;
  let tmpBallX = localGame.ballX / localGame.gameWidth;
  let tmpBallY = localGame.ballY / localGame.gameHeight;

  localGame.gameWidth = localGame.game.offsetWidth;
  localGame.gameHeight = localGame.game.offsetHeight;

  localGame.ballSpeedY = (30 / localGame.gameWidth) * localGame.gameHeight;
  if (tmpSpeedY < 0) {
    localGame.ballSpeedY *= -1;
  }

  const paddleHeight = localGame.gameHeight * 0.2; // 20% de la hauteur de la zone de jeu

  localGame.paddleA.style.height = `${paddleHeight}px`;
  localGame.paddleB.style.height = `${paddleHeight}px`;

  localGame.paddleA.y = tmpPaddleA * localGame.gameHeight;
  localGame.paddleB.y = tmpPaddleB * localGame.gameHeight;

  localGame.paddleA.style.top = `${tmpPaddleA * 100}%`;
  localGame.paddleB.style.top = `${tmpPaddleB * 100}%`;
  localGame.paddleSpeed = 0.008 * localGame.gameHeight;

  const ballSize = localGame.gameWidth * 0.015; // 1.5% de la largeur de la zone de jeu pour la taille de la balle
  localGame.ball.style.width = `${ballSize}px`;
  localGame.ball.style.height = `${ballSize}px`;
  localGame.ballX = tmpBallX * localGame.gameWidth;
  localGame.ballY = tmpBallY * localGame.gameHeight;
  localGame.ball.style.left = `${
    (localGame.ballX - localGame.ball.offsetWidth) / localGame.gameWidth * 100
  }%`;
  localGame.ball.style.top = `${
    (localGame.ballY - localGame.ball.offsetHeight) / localGame.gameHeight * 100
  }%`;
}

function resetLocalBall(winner) {
  localGame.ballX = localGame.gameWidth / 2;
  localGame.ballY = localGame.gameHeight / 2;

  localGame.ballSpeedX = 30;
  localGame.ballSpeedY = (30 / localGame.gameWidth) * localGame.gameHeight;

  localGame.ball.style.left =
    (localGame.ballX - localGame.ball.offsetWidth / 2) + "px";
  localGame.ball.style.top =
    (localGame.ballY - localGame.ball.offsetHeight / 2) + "px";
  if (winner === "B") {
    localGame.ballSpeedX = localGame.ballSpeedX * -1;
  }
}

function backToLocalMenu() {
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
      const artificialEvent = { preventDefault: () => {} };
      navigate(artificialEvent, "/game");
      printFlashMessage(`Game done.`);
    });
}

function checkLocalGameOver() {
  if (localGame.scoreA >= maxScore || localGame.scoreB >= maxScore) {
    localGame.winner = localGame.scoreA > localGame.scoreB
      ? localGame.leftPlayer
      : localGame.rightPlayer;
    localGame.finalScore = localGame.scoreA + " - " + localGame.scoreB;
    removeLocalGameListeners();
    backToLocalMenu();
  }
}

function removeLocalGameListeners() {
  clearInterval(intervalID);
  stopAudio();
  intervalID = null;
  window.removeEventListener("keydown", handleLocalKeyDown);
  window.removeEventListener("keyup", handleLocalKeyUp);
  window.removeEventListener("resize", resizeLocalGame);
  window.removeEventListener('keydown', handleKeySpace);
  window.removeEventListener('popstate', handleLocalPopstate);
  const id = getMyId();
  updateStatus(id, "online");
}
// --------------------- Fonction de Pause ---------------------

function togglePause() {
  this.isGamePaused_l = !this.isGamePaused_l;
}

function handleKeySpace(e) {
  if (e.key === ' ' || e.key === 'Spacebar') { // Vérifie si la touche espace est appuyée
    e.preventDefault(); // Empêche le comportement par défaut (défilement de la page)
    togglePause();
  }
}
