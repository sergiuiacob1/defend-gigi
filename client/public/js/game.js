var game = new Phaser.Game(1300, 700, Phaser.AUTO, 'phaser-example', { preload: preload, create: create, update: update, render: render });

function preload() {
  game.load.image('phaser', 'assets/dude2.png');
  game.load.image('ballImage', 'assets/ball.png');
}

var socket // Socket connection
var dude;
var ball;
var dudeName;
var style;

var upKey;
var downKey;
var leftKey;
var rightKey;

var nbEnemies = 10;
var enemies = [];
var nrBalls = 20;
var balls = [];

function render(){
  game.debug.text(game.time.fps, 2, 14, "#00ff00");
}

function create() {
  game.world.setBounds(0, 0, 1920, 1920);

  dudeName = prompt("Please enter your name", "Player Name");
  socket = io.connect();

  game.stage.backgroundColor = '#736357';
  dude = game.add.sprite(300, 300, 'phaser');

  style = { font: "15px Arial", fill: "#ffffff" };
  dude.name = dude.game.add.text (0, -10, "<" + dudeName + ">", style); 
  dude.addChild(dude.name);

  ball = game.add.sprite (10, 10, 'ballImage');
  ball.scale.setTo (0.05, 0.05);

  game.camera.follow (dude);
  game.time.advancedTiming = true;

  /*game.physics.startSystem(Phaser.Physics.ARCADE);
  game.physics.enable([dude,ball], Phaser.Physics.ARCADE);
  dude.body.immovable = true;
  ball.body.collideWorldBounds = true;
  ball.body.velocity.setTo(200, 200);
  ball.body.bounce.setTo(1, 1);*/

  for (var i = 0; i < nbEnemies; ++i){
    enemies.push(game.add.sprite(2000, 2000, 'phaser'));
  }

  for (var i = 0; i < nrBalls; ++i){
    balls.push(game.add.sprite (10, 10, 'ballImage'));
    balls[i].scale.setTo (0.05, 0.05);
  }

  upKey = game.input.keyboard.addKey(Phaser.Keyboard.UP);
  downKey = game.input.keyboard.addKey(Phaser.Keyboard.DOWN);
  leftKey = game.input.keyboard.addKey(Phaser.Keyboard.LEFT);
  rightKey = game.input.keyboard.addKey(Phaser.Keyboard.RIGHT);

  style = { font: "32px Arial", fill: "#ffffff", align: "center", backgroundColor: "#000000" };

  text = game.add.text(0, 0, "Score: 0", style);
  text.fixedToCamera = true;
  text.cameraOffset.setTo(0,0);

  setEventHandlers();
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

  var curr = 0;
  for (var i = 0; i < data.players.length; ++i){
    if (data.players[i].id != this.id) {
      if (curr < nbEnemies){
        enemies[curr].x = data.players[i].x;
        enemies[curr].y = data.players[i].y;
        ++curr;
      }
    }
    else {
      dude.x = data.players[i].x;
      dude.y = data.players[i].y;
      text.setText("Score: " + data.score + "\nHp: " + data.hp);
    }
  }

  for (; curr < nbEnemies; ++curr){
    enemies[curr].x = 2000;
    enemies[curr].y = 2000;
  }

  for (var i = 0; i < data.balls.length; ++i){
    balls[i].x = data.balls[i].x;
    balls[i].y = data.balls[i].y;
  }
}

// Socket connected
function onSocketConnected () {
  console.log('Connected to socket server');
  console.log(this.id);

  // Send local player data to the game server
  socket.emit('new player', {});
}

// Socket disconnected
function onSocketDisconnect () {
  console.log('Disconnected from socket server')
}

function update() {
  //game.physics.arcade.collide(dude, ball);

  var move = "none";
  if (upKey.isDown){
    move = "up";
  } else if (downKey.isDown){
    move = "down";
  }

  if (leftKey.isDown){
    move = "left";
  } else if (rightKey.isDown){
    move = "right";
  }

  //if (move != "none")
    //setTimeout(function(){dude.x +=3;}, 1000/10);
  socket.emit('move player', move);
}
