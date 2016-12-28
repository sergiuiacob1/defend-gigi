(() => {
	'use strict';

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

    window.onload = start;

    /*() game = {};
    let KEYCODE_LEFT = 37, 
        KEYCODE_RIGHT = 39,
        KEYCODE_UP = 38, 
        KEYCODE_DOWN = 40;

    window.onload = () => {
        console.log("window on load processing");

        let stage = new createjs.Stage("arenaCanvas");
        let circle = new createjs.Shape();
        circle.graphics.beginFill("DeepSkyBlue").drawCircle(0, 0, 50);
        circle.x = 100;
        circle.y = 100;
        circle.id="myCircle";
        stage.addChild(circle);
        stage.update();

        console.log("window loaded");
    };

    createjs.Ticker.addEventListener("tick", tick);
    function tick() { console.log("Tick!"); }

    function keyPressed(event) {
        switch(event.keyCode) {
            case KEYCODE_LEFT:  
                myCircle.x -= 5;
                break;
            case KEYCODE_RIGHT: 
                myCircle.x += 5; 
                break;
            case KEYCODE_UP: 
                myCircle.y -= 5;
                break;
            case KEYCODE_DOWN: 
                myCircle.y += 5;
                break;
        }
        stage.update();
    }

    document.onkeydown = keyPressed;       




    game.loop = () => {

    };

    game.update = () => {

    };

    game.draw = () => {

    };*/

})();