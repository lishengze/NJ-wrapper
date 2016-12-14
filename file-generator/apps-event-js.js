var fs = require('fs');
var hereDoc = require('../lib/tool-function.js').hereDoc;
var serverName = process.argv[2];
var pathName = '../lib/' + serverName + '/';
var ftdContent = require(pathName + "FTD.json");
var sysContent = require(pathName + "sysuserapi.json");

var ftdFuncs = ftdContent.FTD.packages[0].package;
var ftdField = ftdContent.FTD.fields[0].fieldDefine;
var sysFuncs = sysContent.sysuserapi.ftdpackage;
var tabSpace = ["","    ", "        ", "            ", "                ","                    "];

var fileData = hereDoc(function () {
/*var events = function () {
    // child process events
    this.ChildProcessBeforeExit = 'ChildProcessBeforeExit',
    this.ChildProcessExit = 'ChildProcessExit',
    this.ChildProcessUncaughtException = 'ChildProcessUncaughtException',

    this.ConnectServer = "ConnectServer",
    this.RspQyrUserLoginSucceed = "RspQyrUserLoginSucceed",
    
    // server connect events-ManualGenerate
    this.New = "New",
    this.Release = "Release",
    this.Init =  "Init",
    this.Join =  "Join",
    this.ReqUserLogin = "ReqUserLogin",
    this.GetTradingDay =  "GetTradingDay",
    this.RegisterFront =  "RegisterFront",
    this.RegisterSpi =  "RegisterSpi",
    this.SubscribeMarketDataTopic =  "SubscribeMarketDataTopic",
    this.SubscribePartAccount =  "SubscribePartAccount",

    // server connect events-AutoGenerate
*/});

for (var i = 0; i < sysFuncs.length; ++i) {
    var funcName = sysFuncs[i].$.name;
	var funcType = funcName.substring(0, 3);
    if (funcType === "Req") {
        fileData += tabSpace[1] + "this."+ funcName + " = " + "\"" + funcName + "\",\n";
        fileData += tabSpace[1] + "this."+ funcName + "Failed = " + "\"" + funcName + "Failed\",\n";
    }
}

fileData += "\n";

fileData += hereDoc(function () {
/*     this.FrontConnected = "FrontConnected CallbackData",
    this.FrontDisConnected = "FrontDisConnected CallbackData",
    this.HeartBeatWarning =  "HeartBeatWarning CallbackData",

*/});

for (var i = 0; i < sysFuncs.length; ++i) {
    var funcName = sysFuncs[i].$.name;
	var funcType = funcName.substring(0, 3);
    if (funcType === "Rsp" || funcType === "Rtn") {
        fileData += tabSpace[1] + "this."+ funcName+" = " + "\"" + funcName + " CallbackData\",\n"; 
    }
}

fileData += tabSpace[1] + "this.END = \"END\"\n";
fileData += "};\n\n";
fileData += "module.exports = new events();\n"

var pathName = '../new-file/';
var fileName = 'Events.js';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {
        console.log('Succeed in saving ' + pathName + fileName);
    }
});
