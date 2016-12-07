var fs = require('fs');
var hereDoc = require('../lib/tool-function.js').hereDoc;
var serverName = process.argv[2];
var pathName = '../lib/' + serverName + '/';
var ftdContent = require(pathName + "FTD.json");
var sysContent = require(pathName + "sysuserapi.json");

var ftdFuncs = ftdContent.FTD.packages[0].package;
var sysFuncs = sysContent.sysuserapi.ftdpackage;
var tabSpace = ["","    ", "        ", "            ", "                ","                    "];

var fileData = hereDoc(function () {
/*var EVENTS       = require("./Events.js");
var Spi = function(){
    
    this.user = {};    
    
    this.OnFrontConnected = function () {
        var data = {};
        data.message = EVENTS.FrontConnected;
        data.callbackData = {};
        process.send(data);
    }
    
    this.OnFrontDisConnected = function (nReason) {
        var data = {};
        data.message = EVENTS.FrontDisConnected;
        data.callbackData = nReason;
        process.send(data);  
    }
    
    this.OnHeartBeatWarning = function (nTimeLapse) {
        var data = {};
        data.message = EVENTS.HeartBeatWarning;
        data.callbackData = nTimeLapse;
        process.send(data);      
    }         
          
*/});

for (var i = 0; i < sysFuncs.length; ++i) {
    var funcName = sysFuncs[i].$.name;
	var funcType = funcName.substring(0, 3);
    if (funcType === "Rsp" || funcType === "Rtn") {
        for (var j = 0; j < ftdFuncs.length; ++j) {
            if (ftdFuncs[j].$.name === funcName) {

                var pValueName = "p" + ftdFuncs[j].field[0].$.name;
                if (funcType === "Rsp") {
                        fileData += tabSpace[1] + "this.On" + funcName + " = function (" + pValueName  + ", pRspInfo, nRequestID, bIsLast) {\n";
                } else {
                        fileData += tabSpace[1] + "this.On" + funcName + " = function (" + pValueName + "){ \n" 
                }
                fileData += tabSpace[2] + "var data = {};\n"
                          + tabSpace[2] + "data.message = EVENTS." +funcName+"; \n"						    

                if (funcType === "Rsp") {
                    fileData += tabSpace[2] + "data.callbackData = {}; \n"
                                        + tabSpace[2] + "data.callbackData." + pValueName + " = " + pValueName + ";\n"
                            + tabSpace[2] + "data.callbackData.pRspInfo = pRspInfo;\n"
                            + tabSpace[2] + "data.callbackData.nRequestID = nRequestID;\n"
                            + tabSpace[2] + "data.callbackData.bIsLast = bIsLast;\n"                            
                } else {
                    
                    fileData += tabSpace[2] + "data.callbackData = " + pValueName + ";\n"
                }  
                fileData += tabSpace[2] + "process.send(data); \n"
                fileData += tabSpace[1] + "}\n\n";
            }
        }
    }
}

fileData += tabSpace[0] + "}\n\n";
fileData += "exports.Spi = Spi;\n";

var pathName = '../new-file/';
var fileName = 'server-spi.js';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {            
        console.log('Succeed in saving ' + pathName + fileName);
    }

});