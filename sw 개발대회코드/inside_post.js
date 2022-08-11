// Created by J. Yun, SCH Univ., yun@sch.ac.kr
// Need to install node-fetch
// $ npm i node-fetch --save


const fetch = require("node-fetch");

var myHeaders = new fetch.Headers();
myHeaders.append("Accept", "application/json");
myHeaders.append("X-M2M-RI", "12345");
myHeaders.append("X-M2M-Origin", "SY7-GBHxEQhd"); // change to your aei
myHeaders.append("Content-Type", "application/vnd.onem2m-res+json; ty=4");

var fs = require('fs');
var enc_str = fs.readFileSync('./inside-001.png', {encoding: 'base64'});
var raw = "{\"m2m:cin\": {\"con\": \"" + enc_str + "\"}}";

var requestOptions = {
  method: 'POST',
  headers: myHeaders,
  body: raw,
  redirect: 'follow'
};

fetch("http://203.253.128.177:7579/Mobius/svm/insideimg", requestOptions)
  .then(
    function(response) {
      if (response.status !== 201) {
        console.log('There was a problem. Status Code: ' +
          response.status);
        return;
      }

      response.json().then(function(data) {
        console.log(data);
        console.log(data['m2m:cin']["con"]);
      });
    }
  )
  .catch(function(err) {
    console.log('Fetch Error :-S', err);

  });

