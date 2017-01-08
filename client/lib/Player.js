/* ************************************************
** GAME PLAYER CLASS
************************************************ */
var Player = function (startX, startY, startAngle) {
  var x = startX
  var y = startY
  var angle = startAngle
  var id

  // Getters and setters
  var getX = function () {
    return x
  }

  var getY = function () {
    return y
  }

  var getAngle = function () {
    return angle
  }

  var setX = function (newX) {
    x = newX
  }

  var setY = function (newY) {
    y = newY
  }

  var setAngle = function (newAngle) {
    angle = newAngle
  }

  const moveX = (mx) => {
    x += mx;
  };

  const moveY = (my) => {
    y += my;
  };
  // Define which variables and methods can be accessed
  return {
    getX: getX,
    getY: getY,
    setX: setX,
    setY: setY,
    id: id,
    setAngle: setAngle,
    getAngle: getAngle,
    moveX: moveX,
    moveY: moveY
  }
}

// Export the Player class so you can use it in
// other files by using require("Player")
module.exports = Player
