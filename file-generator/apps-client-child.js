/**
 * Created by li.shengze on 2016/2/24.
 */
var fs = require('fs');
var hereDoc = require('../lib/tool-function.js').hereDoc;
var serverName = process.argv[2];
var pathName = '../lib/' + serverName + '/';
var ftdContent = require(pathName + "FTD.json");
var sysContent = require(pathName + "sysuserapi.json");

var sysFuncs = sysContent.sysuserapi.ftdpackage;
var tabSpace = ["","    ", "        ", "            ", "                ","                    "];

var fileData = hereDoc(function () {
/*var addon             = require("./addon");
var spi               = require("./server-spi.js");
var EVENTS            = require("./Events.js");
var SysUserApiStruct  = require("./SysUserApiStruct.js");
var path              = require('path');
var fs                = require('fs');

var realTimeSystemPath  = "tcp://172.1.128.151:19840";
var innerTestSystemPath = "tcp://172.1.128.111:18842";

var fileName = path.join (__dirname, './client-child.txt');
var fileData = "Child Process Pid: " + process.pid + '\n';
var user = {};

// 注册父进程发送到子进程的请求处理函数.
var ReqFunc = [];

var ConnectServer = function (connectReqField) {
    var userWorkDirName = 'usr/' + connectReqField.userID;
    var spawn = require('child_process').spawn('mkdir', [userWorkDirName]);
    userWorkDirName += "/";

    user.emitter  = connectReqField.infoEmitter;
    user.userApi  = new addon.FtdcSysUserApi_Wrapper(userWorkDirName);
    user.Spi      = new spi.Spi();
    user.Spi.user = user;

    user.userApi.RegisterFront(realTimeSystemPath);
    user.userApi.RegisterSpi(user.Spi);
    user.userApi.Init();
}
    
*/});

for (var i = 0; i < sysFuncs.length; ++i) {
    var funcName = sysFuncs[i].$.name;
	var funcType = funcName.substring(0, 3);
    if (funcType === "Req") {
        fileData += "var " + funcName + " = function (reqField){	\n"
                  + tabSpace[1] + "user.userApi." + funcName + "(reqField.reqObject, reqField.RequestId);\n"
                  + "}\n";
    }
}

fileData += "\nReqFunc[EVENTS.ConnectServer] = ConnectServer; \n"
for (var i = 0; i < sysFuncs.length; ++i) {
    var funcName = sysFuncs[i].$.name;
	var funcType = funcName.substring(0, 3);
    if (funcType === "Req") {
        var eventMessageName = "EVENTS." + funcName;
        fileData += "ReqFunc[" + eventMessageName + "] = " + funcName + "; \n"
    }
}

fileData += hereDoc(function () {
/*
process.on ('message', function(data) {
    fileData += "reqData.event: " + data.event + '\n';
    fs.writeFile(fileName, fileData, function (err) {
        if (err) throw err;
    });
    var curReqFunc = ReqFunc[data.event];
    curReqFunc(data.reqField);
});

process.on('beforeExit', function (code) {
    
});

process.on('exit', function (code) {
    
});
*/});

var pathName = '../new-file/';
var fileName = 'client-child.js';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {            
        console.log('Succeed in saving ' + pathName + fileName);
    }

});