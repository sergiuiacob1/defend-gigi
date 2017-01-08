module.exports = (() => {
  'use strict';
  const fetch = require("node-fetch");

  const get = (url) => {
    return fetch(url)
    .then((res) => {
      return res.text();
    }).then((res) => {
      //console.log(res);
      let str = res.substring(11, res.length - 2);
      console.log(str);
      return JSON.parse(str);
    }).catch((e) =>{
      console.log(e);
      return {};
    });
  };

  const post = (url) => {
    return fetch(url, {
      method: "post",
    }).then((res) => {
      return res.text();
    }).then((res) => {
      //console.log(res);
      let str = res.substring(11, res.length - 2);
      console.log(str);
      return JSON.parse(str);
    }).catch((e) =>{
      console.log(e);
      return {};
    });
  };

  return {
    get,
    post,
  };
})();
