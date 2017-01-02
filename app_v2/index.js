(() => {
  'use strict';

  const exec = require('child_process').exec;
  const obj = {type: "test"};
  const string = JSON.stringify(obj);
  exec(`./cpp_app/build/output '${string}'`, (error, stdout, stderr) => {
    if (error) {
      console.error(`exec error: ${error}`);
      return;
    }
    console.log(`stdout: ${stdout}`);
    console.log(`stderr: ${stderr}`);
  });

})();
