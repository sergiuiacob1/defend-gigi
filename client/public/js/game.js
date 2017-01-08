var game = new Phaser.Game(800, 600, Phaser.AUTO, 'phaser-example', { preload: preload, create: create, update: update });

function preload() {
  game.load.image('phaser', 'assets/dude2.png');
}

var socket // Socket connection
var sprite;

var upKey;
var downKey;
var leftKey;
var rightKey;

var nbEnemies = 10;
var enemies = [];

function create() {
  socket = io.connect();
  game.stage.backgroundColor = '#736357';
  sprite = game.add.sprite(300, 300, 'phaser');

  for (var i = 0; i < nbEnemies; ++i)
    enemies.push(game.add.sprite(300, 300, 'phaser'));
  //  In this example we'll create 4 specific keys (up, down, left, right) and monitor them in our update function

  upKey = game.input.keyboard.addKey(Phaser.Keyboard.UP);
  downKey = game.input.keyboard.addKey(Phaser.Keyboard.DOWN);
  leftKey = game.input.keyboard.addKey(Phaser.Keyboard.LEFT);
  rightKey = game.input.keyboard.addKey(Phaser.Keyboard.RIGHT);

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
      sprite.x = data.players[i].x;
      sprite.y = data.players[i].y;
    }
  }

  for (; curr < nbEnemies; ++curr){
    enemies[curr].x = 1000;
    enemies[curr].y = 1000;
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
  var move;
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
  socket.emit('move player', move);
}
