module.exports = (() => {
  'use strict';
  const fetch = require("node-fetch");

  const get = (url) => {
    return fetch(url, {
      method: "get",
      headers: {
        "Content-Type": "application/json",
      }
    });
  };

  const post = (url, body) => {
    return fetch(url, {
      method: "post",
      headers: {
        "Content-Type": "application/json",
      }
    });
  };

  return {
    get,
    post,
  };
})();
