/******/ (function(modules) { // webpackBootstrap
/******/ 	// The module cache
/******/ 	var installedModules = {};

/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {

/******/ 		// Check if module is in cache
/******/ 		if(installedModules[moduleId])
/******/ 			return installedModules[moduleId].exports;

/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = installedModules[moduleId] = {
/******/ 			exports: {},
/******/ 			id: moduleId,
/******/ 			loaded: false
/******/ 		};

/******/ 		// Execute the module function
/******/ 		modules[moduleId].call(module.exports, module, module.exports, __webpack_require__);

/******/ 		// Flag the module as loaded
/******/ 		module.loaded = true;

/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}


/******/ 	// expose the modules object (__webpack_modules__)
/******/ 	__webpack_require__.m = modules;

/******/ 	// expose the module cache
/******/ 	__webpack_require__.c = installedModules;

/******/ 	// __webpack_public_path__
/******/ 	__webpack_require__.p = "";

/******/ 	// Load entry module and return exports
/******/ 	return __webpack_require__(0);
/******/ })
/************************************************************************/
/******/ ([
/* 0 */
/***/ function(module, exports, __webpack_require__) {

	'use strict';

	(function () {
	    'use strict';

	    var _require = __webpack_require__(1),
	        get = _require.get,
	        post = _require.post;

	    var KEYCODE_LEFT = 37,
	        KEYCODE_RIGHT = 39,
	        KEYCODE_UP = 38,
	        KEYCODE_DOWN = 40;
	    var stage = void 0;
	    var asteroid = void 0;

	    function keyPressed(event) {
	        switch (event.keyCode) {
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

	    var init = function init() {
	        var name = prompt("Please enter your name if you know it", "");
	        /*console.log(name);
	        const ip = `http://0.0.0.0:9098/api/startgame?name=${name}`;
	        console.log(ip);
	        post(ip, {}).then((res) => {
	          console.log(res);
	        });*/

	        var ip = 'http://0.0.0.0:9098/api/getarenainfo?id=0&userid=0';
	        get(ip).then(function (res) {
	            console.log(res);
	        });
	    };

	    window.onload = init;
	})();

/***/ },
/* 1 */
/***/ function(module, exports, __webpack_require__) {

	"use strict";

	module.exports = function () {
	  'use strict';

	  var fetch = __webpack_require__(!(function webpackMissingModule() { var e = new Error("Cannot find module \"node-fetch\""); e.code = 'MODULE_NOT_FOUND'; throw e; }()));

	  var get = function get(url) {
	    return fetch(url, {
	      method: "get",
	      headers: {
	        "Content-Type": "application/json"
	      }
	    });
	  };

	  var post = function post(url, body) {
	    return fetch(url, {
	      method: "post",
	      headers: {
	        "Content-Type": "application/json"
	      }
	    });
	  };

	  return {
	    get: get,
	    post: post
	  };
	}();

/***/ }
/******/ ]);