// Created by J. Yun, SCH Univ., yun@sch.ac.kr
// Need to install node-fetch
// $ npm i node-fetch --save

const fetch = require("node-fetch");

var myHeaders = new fetch.Headers();
myHeaders.append("Accept", "application/json");
myHeaders.append("X-M2M-RI", "12345");
myHeaders.append("X-M2M-Origin", "justin");

var requestOptions = {
  method: 'GET',
  headers: myHeaders,
  redirect: 'follow'
};

fetch("http://203.253.128.177:7579/Mobius/svm/outsideimg/la", requestOptions)
  .then(
    function(response) {
      if (response.status !== 200) {
        console.log('There was a problem. Status Code: ' +
          response.status);
        return;
      }

      response.json().then(function(data) {
        require('fs').writeFile('./outsideimg_to_save.png', data['m2m:cin']["con"], {encoding: 'base64'}, function(err) {console.log('File created')});        
      });
    }
  )
  .catch(function(err) {
    console.log('Fetch Error :-S', err);
  });