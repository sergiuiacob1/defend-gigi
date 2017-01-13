var game = new Phaser.Game(window.innerWidth, window.innerHeight, Phaser.AUTO, 'phaser-example', { preload: preload, create: create, update: update, render: render });

function preload() {
  game.load.image('phaser', 'assets/dude2.png');
  game.load.image('ballImage', 'assets/ball.png');
  game.load.image('grid', 'assets/map.png');
  game.load.image ('gameover', 'assets/gameover.png');
}

var socket // Socket connection
var dude;
var ball;
var land;
var dudeName;
var texture;
var style;
var scoreboard;
var gameover;
var dudeIsDead;

var upKey;
var downKey;
var leftKey;
var rightKey;

var nbEnemies = 10;
var enemies = [];
var nrBalls = 90;
var MAX_BALLS = 90;
var balls = [];

function render(){
  game.debug.text(game.time.fps, 2, 14, "#00ff00");
}

function create() {
  game.physics.startSystem(Phaser.Physics.ARCADE);

  game.world.setBounds(0, 0, 1920, 1920);
  game.add.sprite(0, 0, 'grid');

  dudeName = prompt("Please enter your name", "Player Name");
  socket = io.connect();

  //game.stage.backgroundColor = '#736357';
  dude = game.add.sprite(300, 300, 'phaser');


  style = { font: "15px Arial", fill: "#ffffff" };
  dude.name = dude.game.add.text (0, -10, "<" + dudeName + ">", style);
  dude.addChild(dude.name);
  if (dude.width < dude.name.width)
    dude.name.x = -(dude.name.width/2 - dude.width/2)
    else
    dude.name.x = dude.width/2 - dude.name.width/2;


  game.camera.follow (dude);
  game.time.advancedTiming = true;

  for (var i = 0; i < nbEnemies; ++i){
    enemies.push(game.add.sprite(2000, 2000, 'phaser'));
    enemies[i].name = enemies[i].game.add.text (0, -10, "noname", style);
    enemies[i].addChild(enemies[i].name);

    if (enemies[i].width < enemies[i].name.width)
      enemies[i].name.x = -(enemies[i].name.width/2 - enemies[i].width/2);
      else
      enemies[i].name.x = enemies[i].width/2 - enemies[i].name.width/2;
  }

  for (var i = 0; i < MAX_BALLS; ++i){
    balls.push(game.add.sprite (2000, 20000, 'ballImage'));
    balls[i].scale.setTo (1, 1);
  }

  upKey = game.input.keyboard.addKey(Phaser.Keyboard.W);
  downKey = game.input.keyboard.addKey(Phaser.Keyboard.S);
  leftKey = game.input.keyboard.addKey(Phaser.Keyboard.A);
  rightKey = game.input.keyboard.addKey(Phaser.Keyboard.D);

  style = { font: "32px Arial", fill: "#000000", align: "center"};

  text = game.add.text(0, 0, "Score: 0", style);
  text.fixedToCamera = true;
  text.cameraOffset.setTo(0,0);

  scoreboard = game.add.text (500, 500, "Scoreboard\n", style);
  scoreboard.fixedToCamera = true;
  scoreboard.cameraOffset.setTo (window.innerWidth - scoreboard.width, 0);
  scoreboard.players = [];

  /*for (var i = 0; i < 5; ++i){
    scoreboard.players[i] = game.add.text (0, 10 * (i+1), "player1", style);
    //scoreboard.addChild (scoreboard.players[i]);
}*/

  setEventHandlers();
  game.input.onDown.add(fireBall, this);
}

function fireBall(pointer){
  console.log(pointer);
  var x = pointer.x + game.camera.x;
  var y = pointer.y + game.camera.y;
  console.log(x);
  console.log(y);
  socket.emit('fire', {x: x, y: y});
}

var setEventHandlers = function () {
  // Socket connection successful
  socket.on('connect', onSocketConnected);

  // Socket disconnection
  socket.on('disconnect', onSocketDisconnect);

  //updateInfo
  socket.on('update arena', onUpdateArena);
};

function onUpdateArena(data) {
  //console.log("data");
  //console.log(data);

  if (data.players == undefined)
    return;

  var i;
  var curr = 0;
  dudeIsDead = true;
  for (i = 0; i < data.players.length; ++i){
    if (data.players[i].id != this.id) {
      if (curr < nbEnemies){
        enemies[curr].x = data.players[i].x;
        enemies[curr].y = data.players[i].y;
        enemies[curr].name.setText("<" + data.players[i].name + ">");
        ++curr;
      }
    }
    else {
      dude.x = data.players[i].x;
      dude.y = data.players[i].y;
      dudeIsDead = false;
      //console.log(data.players[i]);
      text.setText("Score: " + data.players[i].score + "\nHp: " + data.players[i].hp);
    }
  }

  var concatenatedString = "Scoreboard\n";
  for (i = 0; i < data.scoreboard.length - 1; ++i){
    concatenatedString += data.scoreboard[i].name + ": " + data.scoreboard[i].score + "\n";
  }
  concatenatedString += data.scoreboard[i].name + ": " + data.scoreboard[i].score;

  scoreboard.setText (concatenatedString);
  scoreboard.cameraOffset.setTo (window.innerWidth - scoreboard.width, 0);

  for (; curr < nbEnemies; ++curr){
    enemies[curr].x = 2000;
    enemies[curr].y = 2000;
  }

  for (i = 0; i < data.balls.length && i < MAX_BALLS; ++i){
    balls[i].x = data.balls[i].x;
    balls[i].y = data.balls[i].y;
  }

  for (i = data.balls.length; i < MAX_BALLS; ++i){
    balls[i].x = 2000;
    balls[i].y = 2000;
  }

  gameover = game.add.sprite (dude.x, dude.y,'gameover');

  if (!dudeIsDead)
      gameover.destroy();
}

// Socket connected
function onSocketConnected () {
  console.log('Connected to socket server');
  console.log(this.id);

  // Send local player data to the game server
  socket.emit('new player', {name: dudeName});
}

// Socket disconnected
function onSocketDisconnect () {
  console.log('Disconnected from socket server')
}

function update() {
  dude.rotation = game.physics.arcade.angleToPointer(dude);

  var move = "";
  if (upKey.isDown){
    move += "up";
  } else if (downKey.isDown){
    move += "down";
  }

  if (leftKey.isDown){
    move += "left";
  } else if (rightKey.isDown){
    move += "right";
  }

  if (move == "")
    move = "none";

  //console.log(move);

  //if (move != "none")
    //setTimeout(function(){dude.x +=3;}, 1000/10);
  socket.emit('move player', move);
}
