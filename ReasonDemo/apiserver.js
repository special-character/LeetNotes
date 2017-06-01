var express = require('express');
var app = express();
var fs = require("fs");


app.use(function (req, res, next){
    res.setHeader('Access-Control-Allow-Origin', 'http://localhost:8080');

    res.setHeader('Access-Conrol-Allow-Methods', 'GET');

    res.setHeader('Access-Control-Allow-Headers', 'X-Requested-With,content-type');

    next();
});

app.get('/listUsers', function (req, res) {

    res.setHeader('Access-Control-Allow-Origin', 'http://localhost:8080');

    res.setHeader('Access-Conrol-Allow-Methods', 'GET');

    res.setHeader('Access-Control-Allow-Headers', 'X-Requested-With,content-type');

    res.setHeader('Access-Control-Allow-Credentials', true);

    var result = {"id" : "chris",
                  "content" : `An h2 header
------------

Here's a numbered list:

 1. first item
 2. second item
 3. third item
`
                 }
    res.end(JSON.stringify(result));
})

var server = app.listen(8081, function () {

  var host = server.address().address
  var port = server.address().port

  console.log("Example app listening at http://%s:%s", host, port)

})