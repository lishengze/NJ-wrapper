/**
 * 作者: 李晟泽
 * 日期：2016.11.17
 * 作用：自动生成v8转换所需数据的头文件。
 *      转换的数据主要用在应答与订阅消息中，所以只需从ApiData.json中获取应答与订阅的信息即可。
 * 手动添加部分：声明日志文件句柄， 声明初始化与释放nodejs转换所需数据的函数。
 * 自动添加部分：声明应答与订阅用到的转换数据。
 */

var fs = require('fs');
var hereDoc = require('../lib/tool-function.js').hereDoc;
var jsonContent = require("../lib/ApiData.json");
var FuncCol = jsonContent.FTD.packages[0].package;

var tabSpace = ["","    ", "        ", "            ", "                ","                    "];
var spiFuncName = [];

for (var i = 0; i < FuncCol.length; ++i) {
    var funcName = FuncCol[i].$.name;
	var funcType = funcName.substring(0, 3);
    if (funcType === "Rsp" || funcType === "Rtn") {
        tmpSpiFuncName = funcName;    
        spiFuncName.push(funcName);   
    }
    if (funcType === "Spi") {
        spiFuncName.push(FuncCol[i].field[1].$.name);   
    }
}

var fileData = hereDoc(function () {
/*#ifndef _V8_TRANSFORM_DATA_H_
#define _V8_TRANSFORM_DATA_H_

#include <queue>
#include <map>
#include <vector>
#include "tool-function.h"
#include "id-func.h"
#include <nan.h>
#include <fstream>
using std::fstream;
using std::queue;
using std::map;
using std::vector;

extern fstream g_RunningResult_File;

void InitV8Transformdata (); 
 
void DeInitV8Transformdata ();

*/});
console.log (spiFuncName.length)

for (var i = 0; i < spiFuncName.length; ++i) {
    fileData += 'extern uv_mutex_t   ' + 'g_' + spiFuncName[i] + '_mutex' + ';\n';
    fileData += 'extern uv_async_t   ' + 'g_' + spiFuncName[i] + '_async' + ';\n';     
    fileData += 'extern vector<FRONT_ID>    ' + 'g_' + spiFuncName[i] + '_IOUser_vec' + ';\n';  
    fileData += 'extern map<FRONT_ID, queue<void**> >   ' + 'g_' + spiFuncName[i] + '_Data_map' + ';\n\n'; 
}

fileData += "#endif\n\n";

var pathName = '../new file/';
var fileName = 'v8-transform-data.h';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {
        console.log('Succeed in saving ' + pathName + fileName);
    }

});