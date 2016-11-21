/**
 * Created by li.shengze on 2015/1/28.
 */

var fs = require('fs');
var hereDoc = require('../lib/tool-function.js').hereDoc;
var ftdContent = require("../lib/FTD.json");
var sysContent = require("../lib/sysuserapi.json");

var ftdFuncs = ftdContent.FTD.packages[0].package;
var sysFuncs = sysContent.sysuserapi.ftdpackage;
var tabSpace = ["","    ", "        ", "            ", "                ","                    "];

var fileData = hereDoc(function () {
/*#ifndef _V8_TRANSFORM_FUNC_H_
#define _V8_TRANSFORM_FUNC_H_
#include <nan.h>
 
void   OnFrontConnected (uv_async_t *handle);

void   OnFrontDisconnected (uv_async_t *handle);

void   OnHeartBeatWarning (uv_async_t *handle);
             
*/});

for (var i = 0; i < sysFuncs.length; ++i) {
    var funcName = sysFuncs[i].$.name;
	var funcType = funcName.substring(0, 3);
    if (funcType === "Rsp" || funcType === "Rtn") {
        fileData += "void   On" + funcName + " (uv_async_t *handle);\n\n";   
    }
}        

fileData += "#endif\n\n";

var pathName = '../new-file/';
var fileName = 'v8-transform-func.h';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {
        console.log('Succeed in saving ' + pathName + fileName);
    }

});