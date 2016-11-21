/**
 * Created by li.shengze on 2015/1/28.
 */
var fs = require('fs');
var hereDoc = require('../lib/tool-function.js').hereDoc;
var ftdContent = require("../lib/FTD.json");
var sysContent = require("../lib/sysuserapi.json");

var sysFuncs = sysContent.sysuserapi.ftdpackage;
var tabSpace = ["","    ", "        ", "            ", "                ","                    "];

var fileData = hereDoc(function () {
/*#include "v8-transform-data.h"
#include "v8-transform-func.h"
#include "FtdcSysUserApiStruct.h"
#include "tool-function.h"
#include "id-func.h"
#include <fstream>
using std::fstream;

using namespace v8;

fstream g_RunningResult_File;

void InitV8Transformdata () {
    
    uv_async_init (uv_default_loop(), &g_FrontConnected_async, OnFrontConnected);
    uv_mutex_init (&g_FrontConnected_mutex);

    uv_async_init (uv_default_loop(), &g_FrontDisconnected_async, OnFrontDisconnected);
    uv_mutex_init (&g_FrontDisconnected_mutex);

    uv_async_init (uv_default_loop(), &g_HeartBeatWarning_async, OnHeartBeatWarning);
    uv_mutex_init (&g_HeartBeatWarning_mutex);
            
*/});
for (var i = 0; i < sysFuncs.length; ++i) {
    var funcName = sysFuncs[i].$.name;
	var funcType = funcName.substring(0, 3);
    if (funcType === "Rsp" || funcType === "Rtn") {
        fileData += tabSpace[1] + "uv_async_init (uv_default_loop(), &" + "g_" + funcName + "_async" +", On" + funcName +");\n";
        fileData += tabSpace[1] + "uv_mutex_init (&" + 'g_' + funcName+ '_mutex' + ");\n\n";
    }
}

fileData += "}\n";

fileData += hereDoc(function () {
/*
void DeInitV8Transformdata () {
    
    uv_close ((uv_handle_t*)&g_FrontConnected_async, NULL);

    uv_close ((uv_handle_t*)&g_FrontDisconnected_async, NULL);

    uv_close ((uv_handle_t*)&g_HeartBeatWarning_async, NULL);
            
*/});

for (var i = 0; i < sysFuncs.length; ++i) {
    var funcName = sysFuncs[i].$.name;
	var funcType = funcName.substring(0, 3);
    if (funcType === "Rsp" || funcType === "Rtn") {
        fileData += tabSpace[1] + "uv_close ((uv_handle_t*) &g_" + funcName + "_async" +",NULL);\n\n";
    }
}
fileData += "}\n";

fileData += hereDoc(function () {        
/*
uv_mutex_t   g_FrontConnected_mutex;
uv_async_t   g_FrontConnected_async;
vector<FRONT_ID>   g_FrontConnected_IOUser_vec;
map<FRONT_ID, queue<void**> >   g_FrontConnected_Data_map;

uv_mutex_t   g_FrontDisconnected_mutex;
uv_async_t   g_FrontDisconnected_async;
vector<FRONT_ID>   g_FrontDisconnected_IOUser_vec;
map<FRONT_ID, queue<void**> >   g_FrontDisconnected_Data_map;

uv_mutex_t   g_HeartBeatWarning_mutex;
uv_async_t   g_HeartBeatWarning_async;
vector<FRONT_ID>   g_HeartBeatWarning_IOUser_vec;
map<FRONT_ID, queue<void**> >  g_HeartBeatWarning_Data_map;
                
*/});

for (var i = 0; i < sysFuncs.length; ++i) {
    var funcName = sysFuncs[i].$.name;
	var funcType = funcName.substring(0, 3);
    if (funcType === "Rsp" || funcType === "Rtn") {
        fileData += 'uv_mutex_t   ' + 'g_' + funcName + '_mutex' + ';\n';
        fileData += 'uv_async_t   ' + 'g_' + funcName + '_async' + ';\n';     
        fileData += 'vector<FRONT_ID>    ' + 'g_' + funcName + '_IOUser_vec' + ';\n';  
        fileData += 'map<FRONT_ID, queue<void**> >   ' + 'g_' + funcName + '_Data_map' + ';\n\n'; 
    }
}

var pathName = '../new-file/';
var fileName = 'v8-transform-data.cpp';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {
        console.log('Succeed in saving ' + pathName + fileName);
    }

});