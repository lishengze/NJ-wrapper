// 创建者 李晟泽， 2016.6.30.
// 用来生成client-main.js
// 主要自动生成的部分是，client-main 中对各种请求消息监听的定义。

var fs = require('fs');
var hereDoc = require('../lib/tool-function.js').hereDoc;
var serverName = process.argv[2];
var pathName = '../lib/' + serverName + '/';
var ftdContent = require(pathName + "FTD.json");
var sysContent = require(pathName + "sysuserapi.json");

var sysFuncs = sysContent.sysuserapi.ftdpackage;
var tabSpace = ["","    ", "        ", "            ", "                ","                    "];

var fileData = hereDoc(function () {
/*var EventEmitter = require ('events').EventEmitter;
var fork         = require ('child_process').fork;
var path         = require ('path');
var EVENTS       = require("./Events.js");
var childprocess = [];

var ClientMain = function () {
   this.emitter = new EventEmitter;
   this.childFilePath = path.join( __dirname, 'client-child.js');
   this.childProcess = fork (this.childFilePath, ['Hello client-child!']);
   childprocess[this.childProcess.pid] = this.childProcess;

   this.RestartFunc = (function(_this){
     return function() {
       _this.childProcess = fork (_this.childFilePath, ['Hello client-child!']);
       delete childprocess[_this.childProcess.pid];
       childprocess[_this.childProcess.pid] = _this.childProcess;
     };
   }(this));

   this.childProcess.on ('message', (function(_this) {
     return function(data) {
       if (data.callbackData.hasOwnProperty("nRequestID")){
          data.message = data.message + data.callbackData.nRequestID;
      }
      _this.emitter.emit(data.message, data.callbackData);
    };
   })(this));

   // 手动添加的请求事件。
   this.emitter.on(EVENTS.ConnectServer,  (function(_this) {
     return function(reqData) {
       var data={};
       data.event = EVENTS.ConnectServer;
       data.reqField = reqData;       
       console.log (data)
       _this.childProcess.send(data);
     };
   })(this));

*/});

for (var i = 0; i < sysFuncs.length; ++i) {
  var funcName = sysFuncs[i].$.name;
	var funcType = funcName.substring(0, 3);
  if (funcType === "Req") {
      fileData += tabSpace[1] + "this.emitter.on(EVENTS." + funcName + ",  (function(_this) {" + "\n"
                + tabSpace[2] + "return function(reqData) { " + "\n"
                + tabSpace[3] + "var data={};" + "\n"
                + tabSpace[3] + "data.event = EVENTS." + funcName+ ";" +"\n"
                + tabSpace[3] + "data.reqField = reqData;" + "\n"
                + tabSpace[3] + "_this.childProcess.send(data);" + "\n"
                + tabSpace[2] + "};" + "\n"
                + tabSpace[1] + "})(this));" + "\n\n";
  }
}

fileData += hereDoc(function () {/*
   this.childProcess.on('exit',  (function(_this) {
     return function() {
       _this.emitter.emit('childprocess exit', {});
       console.log ("child_process exit!");
     };
   })(this));

   this.childProcess.on('beforeExit',  (function(_this) {
     return function() {
       _this.emitter.emit('childprocess exit', {});
       console.log ("child_process beforeExit!");
     };
   })(this));

   this.childProcess.on('uncaughtException',  (function(_this) {
     return function() {
       _this.emitter.emit('childprocess exit', {});
       console.log ("child_process uncaughtException!");
     };
   })(this));

};

var ExitFunc = function() {
  for (var pid in childprocess) {
    childprocess[pid].kill();
  }
};

process.on('uncaughtException', function(){
  ExitFunc();
});

process.on('exit', function(){
  ExitFunc();
});

module.exports = new ClientMain();

*/});

fileData += "\n\n";
var pathName = '../new-file/';
var fileName = 'client-main.js';

fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {
        console.log('Succeed in saving ' + pathName + fileName);
    }

});
