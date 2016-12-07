// 创建者 李晟泽， 2016.12.05.
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

var fileData = "";
for (var i = 0; i < sysFuncs.length; ++i) {
    var funcName = sysFuncs[i].$.name;
	var funcType = funcName.substring(0, 3);
    if (funcType === "Req") {
        fileData += "" + funcName + "RequestID = 0;" + "\n\n";
    }
}

fileData += "\n\n";
var pathName = '../new-file/';
var fileName = 'window-requestid.js';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {
        console.log('Succeed in saving ' + pathName + fileName);
    }

});
