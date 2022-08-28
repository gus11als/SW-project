


const fetch = require("node-fetch");

var myHeaders = new fetch.Headers();
myHeaders.append("Accept", "application/json");
myHeaders.append("X-M2M-RI", "12345");
myHeaders.append("X-M2M-Origin", "SY7-GBHxEQhd"); // change to your aei
myHeaders.append("Content-Type", "application/vnd.onem2m-res+json; ty=4");


var fs = require('fs');
var enc_str = fs.readFileSync('1.jpeg', {encoding: 'base64'});
var raw = "{\"m2m:cin\": {\"con\": \"" + enc_str + "\"}}";

var requestOptions = {
  method: 'POST',
  headers: myHeaders,
  body: raw,
  redirect: 'follow'

};


fetch("http://203.253.128.177:7579/Mobius/svm/outsideimg", requestOptions)
  .then(
    function(response) {
      if (response.status !== 201) {
        console.log('There was a problem. Status Code: ' +
          response.status);
        return 0;
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

