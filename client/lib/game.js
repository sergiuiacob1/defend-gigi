(() => {
  'use strict';
  const util = require('util');
  const http = require('http');
  const path = require('path');
  const ecstatic = require('ecstatic');
  const io = require('socket.io');
  const {get, post} = require('./request.js');

  const Player = require('./Player');

  const port = process.env.PORT || 8080;

  /* ************************************************
  ** GAME VARIABLES
  ************************************************ */
  let socket;	// Socket controller
  let players;	// Array of connected players

  /* ************************************************
  ** GAME INITIALISATION
  ************************************************ */

  // Create and start the http server
  const server = http.createServer(
      ecstatic({ root: path.resolve(__dirname, '../public') })
    ).listen(port, function (err) {
    if (err) {
      throw err;
    }

    init();
  });

  const init = () => {
    // Attach Socket.IO to server
    socket = io.listen(server);

    // Start listening for events
    setEventHandlers();
  };

  /* ************************************************
  ** GAME EVENT HANDLERS
  ************************************************ */
  const setEventHandlers = () => {
    // Socket.IO
    socket.sockets.on('connection', onSocketConnection);
  };

  /*const initi = () => {
      const name = "costel";
      console.log(name);
      const ip = `http://192.168.0.139:9098/api/startgame?name=${name}`;
      console.log(ip);

      post(ip).then((res) => {
        console.log(res);
      });
    };
  */
    //initi();
  //

  const ipUpdate = `http://192.168.0.139:9098/api/get_arena_info?id=0&userid=0`;

  const update = () => {
    //console.log(ip);
    //console.log(socket.sockets);

    get(ipUpdate).then((res) => {
      socket.sockets.emit('update arena', res);
    });
  };

  const fps = 24
  setInterval(update, 1000/fps);

  // New socket connection
  const onSocketConnection = (client) => {
    //console.log(client);
    console.log('New player has connected: ' + client.id);

    // Listen for client disconnected
    client.on('disconnect', () => onClientDisconnect(client));

    // Listen for new player message
    client.on('new player', (e) => onNewPlayer(e, client));

    // Listen for move player message
    client.on('move player', (e) => onMovePlayer(e, client));
  };

  // Socket client has disconnected
  const onClientDisconnect =  (client) => {
    util.log('Player has disconnected: ' + client.id);

    const ip = `http://192.168.0.139:9098/api/endgame?id=${client.id}`;
    console.log(ip);

    post(ip).then((res) => {
      console.log(res);
    });
    //var removePlayer = playerById(client.id);
  };

  // New player has joined
  const onNewPlayer = (data, client) => {
    console.log(data);
    // Create a new player
    //newPlayer.id = client.id;

    // Send existing players to the new player
      //client.emit('new player', {id: existingPlayer.id, x: existingPlayer.getX(), y: existingPlayer.getY(), angle: existingPlayer.getAngle()});
    const name = "costel";
    const ip = `http://192.168.0.139:9098/api/startgame?name=${name}&id=${client.id}`;
    //console.log(ip);

    post(ip).then((res) => {
      console.log(res);
    });

  };

  // Player has moved
  const onMovePlayer = (move, client) => {
    //client.broadcast.emit('move player', {id: movePlayer.id, x: movePlayer.getX(), y: movePlayer.getY(), angle: movePlayer.getAngle()});
    //post to the c++ server
    console.log(move);
    const ip = `http://192.168.0.139:9098/api/update_arena_info?arenaid=0&userid=${client.id}&move=${move}`;

    post(ip).then((res) => {
      console.log(res);
    });
  };

  /* ************************************************
  ** GAME HELPER FUNCTIONS
  ************************************************ */
  // Find player by ID
  const playerById = (id) => {
    var i;
    for (i = 0; i < players.length; i++) {
      if (players[i].id === id) {
        return players[i];
      }
    }

    return false;
  };
})();
