// ---------------------Variables Globales---------------------
let intervalID_g = null;
let paddleA_g, paddleB_g, ball_g, game_g, scoreAElement_g, scoreBElement_g;
let gameWidth_g, gameHeight_g;
let ballX_g, ballY_g;
let paddleAX_g, paddleAY_g, paddleBX_g, paddleBY_g;
let ballSpeedX_g, ballSpeedY_g;
let scoreA_g = 0, scoreB_g = 0;
let paddleSpeed_g;
const maxScore_g = 5; 
let isGameRunning_g = false;
let winner_g;
let opponent_g = "Botty";
let loginUser_g = "Hugo";
let finalScore_g;
let victory_g = false;
let paddleHeight_g;
let paddleWidth_g;
let ballSize_g = 10;
let ballSpeedIncrease_g = 1.06;

// ---------------------Variables IA---------------------
let ballTouchedByPaddleA_g = false;
let ballTouchedByPaddleB_g = false;
let futureBallToPosition_g = 0;
let updatesCountB_g = 0;
let totalUpdatesB_g = 0;
let movingPaddleB_g = false;
let movePerUpdate_g = 0;
let adjustmentPixel_g = 0;
let maxBallSpeed_g = 10;
let hitActions_g = ["hitTop", "hitMiddle", "hitBottom"];
let epsilon_g;
let learningRate_g = 0.6;
let iterationCount_g = 0; // Compteur d'itérations
const initialEpsilon_g = 0.25; // Taux d'apprentissage initial
let discountFactor_g = 0.93;
let hitActionWhenActionEffectued_g;
let futureBallToPositionWhenActionEffectued_g = (gameHeight_g - ballSize_g) / 2;
let paddleAYWhenActionEffectued_g = (gameHeight_g - paddleHeight_g) / 2;
let paddleBYWhenActionEffectued_g = (gameHeight_g - paddleHeight_g) / 2;

// ---------------------Paramètres de la balle et des raquettes---------------------
const ballSpeedXPercent_g = 0.004; 
const ballSpeedYPercent_g = 0.003;
const paddleSpeedPercent_g = 0.008;
const ballSizePercent_g = 0.015;
const paddleHeightPercent_g = 0.2;
const ballSpeedYRatio_g = 0.005; 

let keys_g = {ArrowUp: false,
              ArrowDown: false, };
let isGamePaused_g = true;

// ---------------------Paramètres Graphiques---------------------
let echangesParPartie_g = 0;
let boolupdateGraphs_g = true;

// ---------------------Initialisation et Configuration du Jeu---------------------
function initGame_g() {
  gameWidth_g = game_g.offsetWidth;
  gameHeight_g = game_g.offsetHeight;

  scoreAElement_g.textContent = scoreA_g;
  scoreBElement_g.textContent = scoreB_g;

  // Mise à jour des dimensions et positions des paddles
  paddleHeight_g = gameHeight_g * paddleHeightPercent_g;
  paddleA_g.style.height = `${paddleHeight_g}px`;
  paddleB_g.style.height = `${paddleHeight_g}px`;
  paddleAY_g = (gameHeight_g - paddleHeight_g) / 2;
  paddleBY_g = (gameHeight_g - paddleHeight_g) / 2;
  paddleAX_g = 0;
  paddleBX_g = gameWidth_g - paddleB_g.offsetWidth;

  // Mise à jour de la taille et position de la balle
  ballSize_g = ballSizePercent_g * gameWidth_g;
  ball_g.style.width = `${ballSize_g}px`;
  ball_g.style.height = `${ballSize_g}px`;
  ballX_g = gameWidth_g / 2 - ballSize_g / 2;
  ballY_g = gameHeight_g / 2 - ballSize_g / 2;

  // Mise à jour des vitesses
  paddleSpeed_g = paddleSpeedPercent_g * gameHeight_g;
  ballSpeedX_g = ballSpeedXPercent_g * gameWidth_g;
  ballSpeedY_g = ballSpeedYPercent_g * gameHeight_g;

  ball_g.style.left = `${ballX_g}px`;
  ball_g.style.top = `${ballY_g}px`;
  paddleA_g.style.top = `${paddleAY_g}px`;
  paddleB_g.style.top = `${paddleBY_g}px`;
}

function startGamebot() {
  loadQTable()
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
  rulesText.innerHTML = "To move the paddle:<br><strong>Up Arrow</strong> &#x2B06; - for moving up<br><strong>Down Arrow</strong> &#x2B07; - for moving down.<br><br>Press <strong>Space</strong> to pause the game.<br><br>Press <strong>Enter</strong> to start the game !";
  // Écouteur pour la fin de l'animation
  rulesText.addEventListener('animationend', () => {
    rulesText.style.display = 'none';
  });

  pong.appendChild(paddleAA);
  pong.appendChild(paddleBB);
  pong.appendChild(balll);
  pong.appendChild(scoreAA);
  pong.appendChild(scoreBB);
  pong.appendChild(rulesText);

  document.getElementById('content').innerHTML = '';
  document.getElementById('content').appendChild(pong);

  paddleA_g = document.getElementById('paddleA');
  paddleB_g = document.getElementById('paddleB');
  ball_g = document.getElementById('ball');
  game_g = document.getElementById('pong');
  scoreAElement_g = document.getElementById('scoreA');
  scoreBElement_g = document.getElementById('scoreB');
  rulesText_g = document.getElementById('rulesText');

  window.addEventListener('keydown', handleKeyDown_g);
  window.addEventListener('keyup', handleKeyUp_g);
  window.addEventListener('resize', resizeGame_g);
  window.addEventListener('keydown', handleKeySpace_g);
  //touh enter
  window.addEventListener('keydown', handleKeyEnter_g);
  window.addEventListener('popstate', handleLocalPopstate_g);
  

  if (boolupdateGraphs_g) {
      createAndAddGraphs_g();
  }
  initGame_g();
  const myId_g = getMyId();
  updateStatus(myId_g, "in_game");
  isGameRunning_g = true;
  intervalID_g = setInterval(update_g, 10);
  
}

//---------------------Fonctions de création et de mise à jour des graphiques---------------------
function createAndAddGraphs_g() {
  const graphContainer = document.createElement("div");
  graphContainer.id = "graphContainer";

  const echangesTitle = document.createElement("h3");
  echangesTitle.textContent = "Point exchanges";
  echangesTitle.className = "echangesTitle";
  graphContainer.appendChild(echangesTitle);

  const echangesGraph = createBarGraph_g();
  graphContainer.appendChild(echangesGraph);

  const victoiresTitle = document.createElement("h3");
  victoiresTitle.textContent = "Win/Loss distribution";
  victoiresTitle.className = "victoiresTitle";
  graphContainer.appendChild(victoiresTitle);

  const victoiresContainer = document.createElement("div");
  victoiresContainer.id = "victoiresContainer";
  victoiresContainer.appendChild(createPieChart_g());
  victoiresContainer.appendChild(createVictoiresLegend_g());
  graphContainer.appendChild(victoiresContainer);

  document.getElementById('content').appendChild(graphContainer);
}

function createPieChart_g() {
  const victoiresGraph = document.createElement("div");
  victoiresGraph.id = "victoiresGraph";
  victoiresGraph.style.width = "100px";
  victoiresGraph.style.height = "100px";
  victoiresGraph.style.borderRadius = "50%";
  victoiresGraph.style.backgroundImage = "conic-gradient(rgba(0, 186, 188, 0.5) 0deg 50%, rgba(0, 0, 0, 0.5) 50deg 100%)";
  return victoiresGraph;
}

function createVictoiresLegend_g() {
  const victoiresLegend = document.createElement("div");
  victoiresLegend.id = "victoiresLegend";
  victoiresLegend.innerHTML = `
      <div class="legend-item">
          <div class="legend-color legend-color-joueur"></div>
          <span class="legend-text">Bot</span>
      </div>
      <div class="legend-item">
          <div class="legend-color legend-color-bot"></div>
          <span class="legend-text">Player</span>
      </div>
  `;
  return victoiresLegend;
}

function createBarGraph_g() {
  const echangesGraph = document.createElement("div");
  echangesGraph.id = "echangesGraph";
  return echangesGraph;
}

function updateGraphs_g() {
  if (!boolupdateGraphs_g) {
      return;
  }
  updateBarGraph_g(echangesParPartie_g);
  updatePieChart_g();
  echangesParPartie_g = 0;
}

function updateBarGraph_g(echanges) {

  const echangesGraph = document.getElementById('echangesGraph');
  const graphWidth = echangesGraph.offsetWidth;
  const numberOfBars = echangesGraph.children.length;
  const maxBarWidth = 160; // Largeur maximale de la barre en pixels
  const minBarWidth = 40; // Largeur minimale de la barre en pixels
  const barSpacing = 10; // Espace entre les barres en pixels
  const availableWidth = graphWidth - numberOfBars * barSpacing;

  const barWidth = Math.max(minBarWidth, Math.min(maxBarWidth, availableWidth / numberOfBars));

  // Création d'une nouvelle barre pour la partie actuelle
  const bar = document.createElement("div");
  bar.style.width = `${barWidth}px`;
  bar.style.height = `${Math.min(echanges, 100)}%`; // Hauteur basée sur le nombre d'échanges
  bar.style.backgroundColor = "#00babc";
  bar.style.margin = "0 5px";
  bar.style.position = "relative"; // Pour positionner le texte

  // Création du texte pour le nombre d'échanges
  const echangesNumber = document.createElement("span");
  echangesNumber.textContent = echanges;
  echangesNumber.style.textAlign = "center";
  echangesNumber.style.position = "absolute";
  echangesNumber.style.width = "100%";
  echangesNumber.style.bottom = "100%"; // Positionner au-dessus de la barre
  echangesNumber.style.color = "#fff";
  echangesNumber.style.fontSize = "12px";

  bar.appendChild(echangesNumber);
  echangesGraph.appendChild(bar);
}

function updatePieChart_g() {
  const total = scoreA_g + scoreB_g;
  const victoiresGraph = document.getElementById('victoiresGraph');
  const victoiresPct = total > 0 ? Math.round(scoreA_g / total * 100) : 0;
  const defaitesPct = 100 - victoiresPct;

  victoiresGraph.style.backgroundImage = `conic-gradient(
      rgba(0, 186, 188, 0.5) 0deg ${victoiresPct}%,
      rgba(0, 0, 0, 0.5) ${victoiresPct}deg 100%
  )`;
}

//---------------------Fonctions de mise à jour du jeu et de gestion des événements---------------------
function resetGameState_g() {
  gameWidth_g = game_g.offsetWidth;
  gameHeight_g = game_g.offsetHeight;
  scoreA_g = 0;
  scoreB_g = 0;
  ballX_g = gameWidth_g / 2 - ballSize_g / 2;
  ballY_g = gameHeight_g / 2 - ballSize_g / 2;
  paddleAY_g = (gameHeight_g - paddleHeight_g) / 2;
  paddleBY_g = (gameHeight_g - paddleHeight_g) / 2;
  paddleAX_g = 0;
  paddleBX_g = gameWidth_g - paddleB_g.offsetWidth;
  ballSpeedX_g = ballSpeedXPercent_g * gameWidth_g;
  ballSpeedY_g = ballSpeedYPercent_g * gameHeight_g;
  paddleSpeed_g = paddleSpeedPercent_g * gameHeight_g;
  scoreAElement_g.textContent = scoreA_g;
  scoreBElement_g.textContent = scoreB_g;



  ball_g.style.left = ballX_g + 'px';
  ball_g.style.top = ballY_g + 'px';
  paddleA_g.style.top = paddleAY_g + 'px';
  paddleB_g.style.top = paddleBY_g + 'px';


  isGamePaused_g = true;
}

function resetBall_g(winner) {
  ballSpeedX_g = ballSpeedXPercent_g * gameWidth_g;
  ballSpeedY_g = ballSpeedYPercent_g * gameHeight_g;
  ballX_g = gameWidth_g / 2 - ballSize_g / 2;
  ballY_g = gameHeight_g / 2 - ballSize_g / 2;
  ballSpeedX_g = winner === 'A' ? -ballSpeedX_g : ballSpeedX_g;
  ballSpeedY_g = (Math.random() > 0.5 ? 1 : -1) * ballSpeedY_g;

  ball_g.style.left = `${ballX_g}px`;
  ball_g.style.top = `${ballY_g}px`;
}


function resizeGame_g() {
  // Sauvegarde des ratios de position actuels de la balle et des raquettes
  let relativeBallX_g = ballX_g / gameWidth_g;
  let relativeBallY_g = ballY_g / gameHeight_g;
  let relativePaddleAY_g = paddleAY_g / gameHeight_g;
  let relativePaddleBY_g = paddleBY_g / gameHeight_g;

  // Mise à jour des dimensions de la zone de jeu
  gameWidth_g = game_g.offsetWidth;
  gameHeight_g = game_g.offsetHeight;

  // Recalcul des vitesses et des tailles en fonction des nouvelles dimensions
  let directionX_g = ballSpeedX_g / Math.abs(ballSpeedX_g); // -1 pour gauche, 1 pour droite
  ballSpeedX_g = ballSpeedXPercent_g * gameWidth_g * directionX_g;
  let directionY_g = ballSpeedY_g / Math.abs(ballSpeedY_g);
  ballSpeedY_g = ballSpeedYPercent_g * gameHeight_g * directionY_g;
  paddleSpeed_g = paddleSpeedPercent_g * gameHeight_g;
  paddleHeight_g = paddleHeightPercent_g * gameHeight_g;

  // Mise à jour de la taille des raquettes et de la balle
  paddleA_g.style.height = `${paddleHeight_g}px`;
  paddleB_g.style.height = `${paddleHeight_g}px`;
  ballSize_g = ballSizePercent_g * gameWidth_g;
  ball_g.style.width = `${ballSize_g}px`;
  ball_g.style.height = `${ballSize_g}px`;

  // Recalcul des positions en utilisant les ratios sauvegardés
  ballX_g = relativeBallX_g * gameWidth_g;
  ballY_g = relativeBallY_g * gameHeight_g;
  paddleAY_g = relativePaddleAY_g * gameHeight_g;
  paddleBY_g = relativePaddleBY_g * gameHeight_g;

  // Assurez-vous que la balle reste dans la zone de jeu
  ballX_g = Math.max(0, Math.min(gameWidth_g - ball_g.offsetWidth, ballX_g));
  ballY_g = Math.max(0, Math.min(gameHeight_g - ball_g.offsetHeight, ballY_g));

  // Mise à jour des positions des éléments
  ball_g.style.left = `${ballX_g}px`;
  ball_g.style.top = `${ballY_g}px`;
  paddleA_g.style.top = `${paddleAY_g}px`;
  paddleB_g.style.top = `${paddleBY_g}px`;
}


// --------------------- Fonction de Mise à Jour du Jeu ---------------------
function update_g() {
  // Vérification si le jeu est terminé
  checkGameOver_g();
  if (!isGameRunning_g) {
    stopGame_g();
    return;
  }
  if (isGamePaused_g) {
    return; // Arrêter la mise à jour si le jeu est en pause
  }
  // Mise à jour de la position de la balle
  ballX_g += ballSpeedX_g;
  ballY_g += ballSpeedY_g;

  // Gestion des rebonds sur les bords supérieur et inférieur
  if (ballY_g <= 0) {
      ballSpeedY_g *= -1; // Inverser la direction verticale
      ballY_g = 1;        // Empêcher la balle de rester collée en haut
  } else if (ballY_g >= gameHeight_g - ball_g.offsetHeight) {
      ballSpeedY_g *= -1; // Inverser la direction verticale
      ballY_g = gameHeight_g - ball_g.offsetHeight - 1; // Empêcher la balle de rester collée en bas
  }

  // Gestion des points marqués par les joueurs
  if (ballX_g <= 0) {
    scoreB_g++;
    if (boolupdateGraphs_g === true){
      updateGraphs_g();
    }
    resetBall_g('B');
    updateScoreAndAnimate(scoreBElement_g); // Appliquer l'animation au score B
  } else if (ballX_g >= gameWidth_g - ball_g.offsetWidth) {
    scoreA_g++;
    if (boolupdateGraphs_g === true){
      updateGraphs_g();
    }
    resetBall_g('A');
    updateScoreAndAnimate(scoreAElement_g); // Appliquer l'animation au score A
  }

  // Vérification des collisions avec les raquettes
  checkPaddleCollision_g();
  checkIfBallHitPaddleB_g();

  // Action spécifique si la balle touche la raquette B
  if (ballSpeedX_g > 0 && !movingPaddleB_g) {
      executeAction_g();
  }

  // Mise à jour de la position des raquettes
  // updatePaddleA_g();
  if (keys_g.ArrowUp && paddleAY_g > 0) paddleAY_g -= paddleSpeed_g;
  if (keys_g.ArrowDown && paddleAY_g < gameHeight_g - paddleB_g.offsetHeight) paddleAY_g += paddleSpeed_g;
  updatePaddleB_g();

  // Affichage des scores
  scoreAElement_g.textContent = scoreA_g;
  scoreBElement_g.textContent = scoreB_g;

  // Mise à jour de la position de la balle et des raquettes sur l'interface
  ball_g.style.left = `${ballX_g}px`;
  ball_g.style.top = `${ballY_g}px`;
  paddleA_g.style.top = `${paddleAY_g}px`;
  paddleB_g.style.top = `${paddleBY_g}px`;
}

// --------------------- Mise à jour de la Raquette A ---------------------
function updatePaddleA_g() {
  // Calcul de la position centrale de la balle
  let ballCenterY_g = ballY_g + ball_g.offsetHeight / 2;

  // Ajout d'un décalage aléatoire pour simuler un comportement de jeu plus réaliste
  let randomOffset_g = (Math.random() - 0.5) * paddleA_g.offsetHeight * 2;
  ballCenterY_g += randomOffset_g;

  // Calcul de la position centrale de la raquette A
  let paddleCenterY_g = paddleAY_g + paddleA_g.offsetHeight / 2;

  // Détermination du mouvement nécessaire pour aligner la raquette avec la balle
  let diff_g = ballCenterY_g - paddleCenterY_g;
  let move_g = Math.max(-paddleSpeed_g, Math.min(paddleSpeed_g, diff_g));

  // Mise à jour de la position de la raquette A
  paddleAY_g += move_g;
  paddleAY_g = Math.max(0, Math.min(gameHeight_g - paddleA_g.offsetHeight, paddleAY_g));

  // Application de la nouvelle position de la raquette A
  paddleA_g.style.top = `${paddleAY_g}px`;
}

// --------------------- Vérification des Collisions avec les Raquettes ---------------------
function checkPaddleCollision_g() {
  // Collision avec la raquette A
  if (ballX_g <= paddleA_g.offsetWidth) {
      if (ballY_g + ball_g.offsetHeight > paddleAY_g && 
          ballY_g < paddleAY_g + paddleA_g.offsetHeight) {
          ballSpeedX_g *= -1;
          let angle_g = calculateBounceAngle_g(paddleAY_g, paddleA_g.offsetHeight);
          ballSpeedY_g = ballSpeedYRatio_g * gameWidth_g * Math.sin(angle_g);
          ballX_g = paddleA_g.offsetWidth;
          ballTouchedByPaddleA_g = true;
          applySquashEffect();
          updateBallSpeed_g();
          echangesParPartie_g++;
      }
  }

  // Collision avec la raquette B
  if (ballX_g + ball_g.offsetWidth >= gameWidth_g - paddleB_g.offsetWidth) {
      if (ballY_g + ball_g.offsetHeight > paddleBY_g && 
          ballY_g < paddleBY_g + paddleB_g.offsetHeight) {
          ballSpeedX_g *= -1;
          let angle_g = calculateBounceAngle_g(paddleBY_g, paddleB_g.offsetHeight);
          ballSpeedY_g = ballSpeedYRatio_g * gameWidth_g * Math.sin(angle_g);
          ballX_g = gameWidth_g - paddleB_g.offsetWidth - ball_g.offsetWidth;
          ballTouchedByPaddleB_g = true;
          applySquashEffect();
          updateBallSpeed_g();
          echangesParPartie_g++;
      }
  }
}

// --------------------- Création d'un Identifiant d'État pour l'IA ---------------------
function createStateIdentifier_g() {
  let relativePaddleAY_g = paddleAYWhenActionEffectued_g / gameHeight_g;
  let relativeFutureBallY_g = futureBallToPositionWhenActionEffectued_g / gameHeight_g;
  let normalizedBallSpeedX_g = (ballSpeedX_g + maxBallSpeed_g) / (2 * maxBallSpeed_g); // normalisation
  let normalizedBallSpeedY_g = (ballSpeedY_g + maxBallSpeed_g) / (2 * maxBallSpeed_g); // normalisation
  return `paddleAY-${relativePaddleAY_g.toFixed(2)}-futureBallY-${relativeFutureBallY_g.toFixed(2)}-speedX-${normalizedBallSpeedX_g.toFixed(2)}-speedY-${normalizedBallSpeedY_g.toFixed(2)}`;
}


// --------------------- Obtention de l'État Actuel pour l'IA ---------------------
function getCurrentHitState_g() {
  let predictedFutureBallY_g = calculateFutureBallPosition_g(ballX_g, ballY_g, ballSpeedX_g, ballSpeedY_g) / gameHeight_g;
  let relativePaddleAY_g = paddleAY_g / gameHeight_g;
  let normalizedBallSpeedX_g = (ballSpeedX_g + maxBallSpeed_g) / (2 * maxBallSpeed_g); // normalisation
  let normalizedBallSpeedY_g = (ballSpeedY_g + maxBallSpeed_g) / (2 * maxBallSpeed_g); // normalisation
  return `paddleAY-${relativePaddleAY_g.toFixed(2)}-futureBallY-${predictedFutureBallY_g.toFixed(2)}-speedX-${normalizedBallSpeedX_g.toFixed(2)}-speedY-${normalizedBallSpeedY_g.toFixed(2)}`;
}

// --------------------- Vérification si la Balle a Touché la Raquette B ---------------------
function checkIfBallHitPaddleB_g() {
  if (ballTouchedByPaddleB_g) {
      let oldState_g = createStateIdentifier_g();
      let reward_g = calculateReward_g();
      let nextState_g = getCurrentHitState_g();
      updateQTable_g(oldState_g, hitActionWhenActionEffectued_g, reward_g, nextState_g);
      ballTouchedByPaddleB_g = false;
  }
}

// --------------------- Exécution Action pour la Raquette B ---------------------
function executeAction_g() {
  let time_g = calculateTimeToOppositeWall_g(ballX_g, ballSpeedX_g);

  // Vérifier si le temps pour atteindre le mur opposé est trop long
  if (time_g * 1.9 > 1000) {
      optimalMove_g = Math.random() * 2 - 1;
      movePerUpdate_g = Math.max(-paddleSpeed_g, Math.min(paddleSpeed_g, optimalMove_g / time_g));
      updatesCountB_g = 0;
      totalUpdatesB_g = Math.ceil(time_g);
      movingPaddleB_g = true;
      return;
  }

  // Calcul de la position future de la balle
  futureBallToPosition_g = calculateFutureBallPosition_g(ballX_g, ballY_g, ballSpeedX_g, ballSpeedY_g);

  // Calcul du mouvement optimal
  let optimalMove_g = futureBallToPosition_g - (paddleBY_g + paddleB_g.offsetHeight / 2);
  let totalMove_g = optimalMove_g + adjustmentPixel_g;

  if (Math.abs(ballSpeedX_g) > 7 && Math.random() < 0.5) { // 50% de chance
    totalMove_g += (Math.random() < 0.5 ? 1 : -1) * paddleHeight_g / 3;
}

  movePerUpdate_g = Math.max(-paddleSpeed_g, Math.min(paddleSpeed_g, totalMove_g / time_g));

  // Mise à jour de la position de la raquette B
  let futurePaddleY_g = paddleBY_g + movePerUpdate_g * time_g;
  futurePaddleY_g = Math.max(0, Math.min(gameHeight_g - paddleHeight_g, futurePaddleY_g));

  updatesCountB_g = 0;
  totalUpdatesB_g = Math.ceil(time_g);
  movingPaddleB_g = true;
}

// --------------------- Choix de l'Action pour l'IA ---------------------
function chooseHitAction_g() {
    if (!QTable_g[hitActionWhenActionEffectued_g]) {
        QTable_g[hitActionWhenActionEffectued_g] = {};
        hitActions_g.forEach(action => QTable_g[hitActionWhenActionEffectued_g][action] = 0);
    }

    if (Math.random() < epsilon_g) {
        return hitActions_g[Math.floor(Math.random() * hitActions_g.length)];
    } else {
        let maxQValue = Math.max(...Object.values(QTable_g[hitActionWhenActionEffectued_g]));
        let bestActions = hitActions_g.filter(action => QTable_g[hitActionWhenActionEffectued_g][action] === maxQValue);
        return bestActions[Math.floor(Math.random() * bestActions.length)];
    }
}

// --------------------- Exécution de l'Action Choisi pour l'IA ---------------------
function executeHitAction_g(hitAction) {
  adjustmentPixel_g = 0;
  let tmpPaddleBY_g = paddleBY_g;

  switch (hitAction) {
      case "hitTop":
          if (tmpPaddleBY_g > 0) {
              adjustmentPixel_g = paddleHeight_g / 3;
          }
          break;
      case "hitMiddle":
          break; // Pas de changement pour "hitMiddle"
      case "hitBottom":
          if (tmpPaddleBY_g < gameHeight_g - paddleB_g.offsetHeight) {
              adjustmentPixel_g = -paddleHeight_g / 3;
          }
          break;
  }

  tmpPaddleBY_g += adjustmentPixel_g;
  if (tmpPaddleBY_g < 0 || tmpPaddleBY_g > gameHeight_g - paddleB_g.offsetHeight) {
      adjustmentPixel_g = 0;
  }
}

// --------------------- Mise à jour de la Raquette B ---------------------
function updatePaddleB_g() {
  if (movingPaddleB_g) {
      paddleBY_g = Math.max(0, Math.min(gameHeight_g - paddleB_g.offsetHeight, paddleBY_g + movePerUpdate_g));
      updatesCountB_g++;
      if (updatesCountB_g >= totalUpdatesB_g) {
          movingPaddleB_g = false;
      }
  }

  if (ballTouchedByPaddleA_g) {
      hitActionWhenActionEffectued_g = chooseHitAction_g();
      executeHitAction_g(hitActionWhenActionEffectued_g);
      paddleBYWhenActionEffectued_g = paddleBY_g;
      paddleAYWhenActionEffectued_g = paddleAY_g;
      futureBallToPositionWhenActionEffectued_g = calculateFutureBallPosition_g(ballX_g, ballY_g, ballSpeedX_g, ballSpeedY_g);
      executeAction_g();
      ballTouchedByPaddleA_g = false;
  }
}

//Fonctions Auxiliaires

// --------------------- Calcul de la Position Future de la Balle ---------------------
function calculateFutureBallPosition_g(currentBallX, currentBallY, speedX, speedY) {
    // Calcul de la position future de la balle pour prédire son mouvement
    let futureBallX = currentBallX;
    let futureBallY = currentBallY;

    while (futureBallX + ballSize_g < gameWidth_g) {
        futureBallX += speedX;
        futureBallY += speedY;

        if (futureBallY <= 0 || futureBallY >= gameHeight_g - ballSize_g) {
            speedY = -speedY;
        }

        if (futureBallX <= 0) {
            speedX = -speedX;
        }
    }
    return futureBallY;
}
// --------------------- Calcul du Temps pour Atteindre le Mur Opposé ---------------------
function calculateTimeToOppositeWall_g(currentBallX_g, speedX_g) {
  let distanceToWall_g = gameWidth_g - currentBallX_g - ballSize_g;
  let time_g = 0;

  if (speedX_g !== 0) {
      time_g = distanceToWall_g / Math.abs(speedX_g);
  }

  return time_g;
}

// --------------------- Mise à Jour de la Vitesse de la Balle ---------------------
function updateBallSpeed_g() {
  if (Math.abs(ballSpeedX_g) < maxBallSpeed_g) {
      ballSpeedX_g *= ballSpeedIncrease_g;
      ballSpeedY_g *= ballSpeedIncrease_g;
  }
}

// --------------------- Augmentation de la Vitesse ---------------------
function increaseSpeed_g(speed_g) {
  let newSpeed_g = speed_g * 1.20;
  return newSpeed_g > 20 ? 20 : newSpeed_g;
}

// --------------------- Calcul de l'Angle de Rebond ---------------------
function calculateBounceAngle_g(paddleY_g, paddleHeight_g) {
  let hitPoint_g = (ballY_g + ball_g.offsetHeight / 2) - (paddleY_g + paddleHeight_g / 2);
  let normalizedHitPoint_g = hitPoint_g / (paddleHeight_g / 2);
  let maxBounceAngle_g = Math.PI / 4;
  let angle_g = normalizedHitPoint_g * maxBounceAngle_g;
  return angle_g;
}

// --------------------- Prédiction de la Position de la Balle Après le Rebond ---------------------
function calculateFutureBallPositionLeft_g(currentBallX_g, currentBallY_g, speedX_g, speedY_g) {
  let futureBallX_g = currentBallX_g;
  let futureBallY_g = currentBallY_g;

  while (futureBallX_g - ballSize_g > 0) {
      futureBallX_g += speedX_g;
      futureBallY_g += speedY_g;

      if (futureBallY_g <= 0 || futureBallY_g >= gameHeight_g - ballSize_g) {
          speedY_g = -speedY_g;
      }

      if (futureBallX_g >= gameWidth_g - ballSize_g) {
          speedX_g = -speedX_g;
      }
  }
  return futureBallY_g;
}

// --------------------- Calcul de la Récompense pour l'IA ---------------------
function calculateReward_g() {
  let predictedLandingPosition_g = calculateFutureBallPositionLeft_g(ballX_g, ballY_g, ballSpeedX_g, ballSpeedY_g);
  let distanceToPaddleA_g = Math.abs(predictedLandingPosition_g - paddleAYWhenActionEffectued_g);
  let reward_g = distanceToPaddleA_g / gameHeight_g;

  if (distanceToPaddleA_g < paddleA_g.offsetHeight) {
      reward_g = -1;
  }
  updateEpsilon_g();
  return reward_g;
}

// --------------------- Mise à Jour du Taux d'Apprentissage (Epsilon) pour l'IA ---------------------
function updateEpsilon_g() {
  const decayRate_g = 0.00005;
  iterationCount_g++;
  epsilon_g = initialEpsilon_g * Math.exp(-decayRate_g * iterationCount_g);
}

// --------------------- Gestion des Entrées Clavier ---------------------
function handleKeyDown_g(e) {
  if (keys_g.hasOwnProperty(e.key)) {
      e.preventDefault()
      keys_g[e.key] = true;
  }
}

function handleKeyUp_g(e) {
  if (keys_g.hasOwnProperty(e.key)) {
      e.preventDefault()
      keys_g[e.key] = false;
  }
}

function handleLocalPopstate_g() {
  removeLocalGameListeners_g();
}
// --------------------- Envoi des Données de Jeu ---------------------
async function sendData_g() {
  try {
      let data_g = {
          score: finalScore_g,
          victory: victory_g,
          opponent: opponent_g,
      };
      const response = await fetch('/game/add-match', {
          method: 'POST',
          headers: {
              'Content-Type': 'application/json',
              'X-Requested-With': 'XMLHttpRequest',
              'X-CSRFToken': getCookie('csrftoken'),
          },
          body: JSON.stringify(data_g),
      });
      const json = await response.json();
  } catch (error) {
      console.error('Error:', error);
  }
}


// --------------------- Vérification de la Fin de Jeu ---------------------

function checkGameOver_g() {
  if (scoreA_g >= maxScore_g || scoreB_g >= maxScore_g) {
      victory_g = scoreA_g > scoreB_g;
      winner_g = scoreA_g > scoreB_g ? loginUser_g : opponent_g;
      finalScore_g = `${scoreA_g} - ${scoreB_g}`;
      resetGameState_g();
      isGameRunning_g = false;
      removeLocalGameListeners_g();
      backToMenu_g();
  }
}

function stopGame_g() {
  resetGameState_g();
  isGameRunning_g = false;
  removeLocalGameListeners_g();
}

// --------------------- Retour au Menu Principal ---------------------
function backToMenu_g() {
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
  });
  printFlashMessage(`Game done.`);
}

function removeLocalGameListeners_g() {
  clearInterval(intervalID_g);
  intervalID_g = null;
  window.removeEventListener("keydown", handleLocalKeyDown);
  window.removeEventListener("keyup", handleLocalKeyUp);
  window.removeEventListener("resize", resizeGame_g);
  window.removeEventListener("keydown", handleKeySpace_g);
  window.removeEventListener("keydown", handleKeyEnter_g);
  window.removeEventListener("popstate", handleLocalPopstate_g);

  const id = getMyId();
  updateStatus(id, "online");
}

// --------------------- Mise à Jour de la Table Q pour l'IA ---------------------
function updateQTable_g(state_g, action_g, reward_g, nextState_g) {
  // Initialisation de l'état et de l'action dans la table Q si nécessaire
  if (!QTable_g[state_g]) {
      QTable_g[state_g] = {};
      hitActions_g.forEach(a => QTable_g[state_g][a] = 0);
  }

  // Mise à jour de la valeur Q en utilisant l'équation de Bellman
  let oldQValue_g = QTable_g[state_g][action_g];
  let maxFutureQ_g = nextState_g in QTable_g ? Math.max(...Object.values(QTable_g[nextState_g])) : 0;
  let newQValue_g = oldQValue_g + learningRate_g * (reward_g + discountFactor_g * maxFutureQ_g - oldQValue_g);
  QTable_g[state_g][action_g] = newQValue_g;
}

// --------------------- Fonction de Téléchargement de Fichiers ---------------------
function download_g(data_g, filename_g, type_g) {
  let dataToWrite_g = data_g.replace(/},/g, "},\n"); // Ajout d'un saut de ligne après chaque ligne
  var file_g = new Blob([dataToWrite_g], {type: type_g});

  if (window.navigator.msSaveOrOpenBlob) {
      window.navigator.msSaveOrOpenBlob(file_g, filename_g);
  } else {
      var a = document.createElement("a"),
          url_g = URL.createObjectURL(file_g);
      a.href = url_g;
      a.download = filename_g;
      document.body.appendChild(a);
      a.click();
      setTimeout(function() {
          document.body.removeChild(a);
          window.URL.revokeObjectURL(url_g); 
      }, 0); 
  }
}

// --------------------- Chargement de la Table Q ---------------------
async function loadQTable() {
  try {
      const response = await fetch('static/js/tableQ.json');
      if (!response.ok) {
          throw new Error('Network response was not ok.');
      }
      QTable_g = await response.json();
  } catch (error) {
      QTable_g = {}; // Création d'une nouvelle table Q vide si nécessaire
  }
}

function updateScoreAndAnimate(scoreElement) {
  scoreElement.classList.add('pulse'); // Ajoute la classe pulse
  setTimeout(() => {
    scoreElement.classList.remove('pulse'); // Retire la classe après 1 seconde
  }, 1000);
}

function applySquashEffect() {
  ball_g.classList.add("squash");
  setTimeout(() => {
    ball_g.classList.remove("squash");
  }, 200); // Correspond à la durée de l'animation
}

// --------------------- Fonction de Pause ---------------------

function togglePause_g() {
  isGamePaused_g = !isGamePaused_g;
}

function handleKeySpace_g(e) {
  if (e.key === ' ' || e.key === 'Spacebar') { // Vérifie si la touche espace est appuyée
    e.preventDefault(); // Empêche le comportement par défaut (défilement de la page)
    togglePause_g();
  }
}

function handleKeyEnter_g(e) {
  if (e.key === 'Enter') {
    e.preventDefault();
    togglePause_g();
  }
}
