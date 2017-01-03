(() => {
	'use strict';

  const {get, post} = require('./request.js');

    let KEYCODE_LEFT = 37,
        KEYCODE_RIGHT = 39,
        KEYCODE_UP = 38,
        KEYCODE_DOWN = 40;
    let stage;
    let asteroid;

    function keyPressed(event) {
        switch(event.keyCode) {
            case KEYCODE_LEFT:
                asteroid.x -= 50;
                break;
            case KEYCODE_RIGHT:
                asteroid.x += 50;
                break;
            case KEYCODE_UP:
                asteroid.y -= 50;
                break;
            case KEYCODE_DOWN:
                asteroid.y += 50;
                break;
        }
        stage.update();
    }

    function start() {
        asteroid = new createjs.Shape();
        asteroid.graphics.beginFill("DeepSkyBlue").drawCircle(0, 0, 50);
        asteroid.x = asteroid.y = 200;

        stage = new createjs.Stage(document.getElementById("arenaCanvas"));
        stage.addChild(asteroid);
        stage.update();

        document.onkeydown = keyPressed;
    }

  const init = () => {
    const name = prompt("Please enter your name if you know it", "");
    /*console.log(name);
    const ip = `http://0.0.0.0:9098/api/startgame?name=${name}`;
    console.log(ip);
    post(ip, {}).then((res) => {
      console.log(res);
    });*/


    const ip = `http://0.0.0.0:9098/api/getarenainfo?id=0&userid=0`;
    get(ip).then((res) => {
      console.log(res);
    });
  };

  window.onload = init;

})();
