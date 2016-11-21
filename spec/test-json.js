var fs = require('fs');
var ftdContent = require("../lib/FTD.json");
var sysContent= require("../lib/sysuserapi.json");

var ftdFuncs = ftdContent.FTD.packages[0].package;
var sysFuncs = sysContent.sysuserapi.ftdpackage;

var outputData = "";
outputData += "ftdFuncs.length: " + ftdFuncs.length + "\n"
            + "sysFuncs.length: " + sysFuncs.length + "\n";

var ReqFuncNumb = 0;
var RspFuncNumb = 0;
var RtnFuncNumb = 0;

for (var i = 0; i < sysFuncs.length; ++i) {
	var funcType = sysFuncs[i].$.name.substring(0, 3);
	switch (funcType) {
		case "Req": ++ReqFuncNumb; break;
		case "Rsp": ++RspFuncNumb; break;
		case "Rtn": ++RtnFuncNumb; break;
		default:  break;
	}
}

outputData += "ReqFuncNumb:     " + ReqFuncNumb + "\n"
            + "RspFuncNumb:     " + RspFuncNumb + "\n"
						+ "RtnFuncNumb:     " + RtnFuncNumb + "\n"
						+ "FuncNumb:        " + (ReqFuncNumb + RspFuncNumb + RtnFuncNumb);

console.log (outputData);
