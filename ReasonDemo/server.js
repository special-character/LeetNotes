var express = require("express");
var path = require("path");

var app = express()
app.use(express.static(path.join(__dirname, "./build")));
app.listen(8080, function(){
    console.log(__dirname);
    console.log("Started listening on port", 8080, "at ", new Date(),
    " from ", path.join(__dirname, "./build"));
});