/**
 * Created by li.shengze on 2015/1/28.
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
/*#include "v8-transform-data.h"
#include "v8-transform-func.h"
#include "FtdcSysUserApiStruct.h"
#include "tool-function.h"
#include "id-func.h"
#include <fstream>
using std::fstream;

using namespace v8;

fstream g_RunningResult_File;

*/});

fileData += "void InitV8Transformdata () {\n";
for (var i = 0; i < spiFuncName.length; ++i) {
    fileData += tabSpace[1] + "uv_async_init (uv_default_loop(), &" + "g_" + spiFuncName[i] + "_async" +", On" + spiFuncName[i] +");\n";
    fileData += tabSpace[1] + "uv_mutex_init (&" + 'g_' + spiFuncName[i] + '_mutex' + ");\n\n";
}
fileData += "}\n\n";

fileData += "void DeInitV8Transformdata () {\n";
for (var i = 0; i < spiFuncName.length; ++i) {
    fileData += tabSpace[1] + "uv_close ((uv_handle_t*) &g_" + spiFuncName[i]  + "_async" +",NULL);\n\n";
}
fileData += "}\n\n";

for (var i = 0; i < spiFuncName.length; ++i) {
    fileData += 'uv_mutex_t   ' + 'g_' + spiFuncName[i] + '_mutex' + ';\n';
    fileData += 'uv_async_t   ' + 'g_' + spiFuncName[i] + '_async' + ';\n';     
    fileData += 'vector<FRONT_ID>    ' + 'g_' + spiFuncName[i] + '_IOUser_vec' + ';\n';  
    fileData += 'map<FRONT_ID, queue<void**> >   ' + 'g_' + spiFuncName[i] + '_Data_map' + ';\n\n'; 
}


// fileData += hereDoc(function () {        
// /*
// uv_mutex_t   g_FrontConnected_mutex;
// uv_async_t   g_FrontConnected_async;
// vector<FRONT_ID>   g_FrontConnected_IOUser_vec;
// map<FRONT_ID, queue<void**> >   g_FrontConnected_Data_map;

// uv_mutex_t   g_FrontDisconnected_mutex;
// uv_async_t   g_FrontDisconnected_async;
// vector<FRONT_ID>   g_FrontDisconnected_IOUser_vec;
// map<FRONT_ID, queue<void**> >   g_FrontDisconnected_Data_map;

// uv_mutex_t   g_HeartBeatWarning_mutex;
// uv_async_t   g_HeartBeatWarning_async;
// vector<FRONT_ID>   g_HeartBeatWarning_IOUser_vec;
// map<FRONT_ID, queue<void**> >  g_HeartBeatWarning_Data_map;
                
// */});

// for(var i = beforeRspQryTopCpuInfoTopic;i < AfterRtnNetNonPartyLinkInfoTopic;i++) {
//     var funcName = jsonContent.FTD.packages[0].package[i].$.name;
//     if (funcName.substring(0,3) ==="Rsp" || funcName.substring(0,3) ==="Rtn") {           
//         fileData += 'uv_mutex_t   ' + 'g_' + funcName + '_mutex' + ';\n';
//         fileData += 'uv_async_t   ' + 'g_' + funcName + '_async' + ';\n';     
//         fileData += 'vector<FRONT_ID>    ' + 'g_' + funcName + '_IOUser_vec' + ';\n';  
//         fileData += 'map<FRONT_ID, queue<void**> >   ' + 'g_' + funcName + '_Data_map' + ';\n\n';
//     }
// }
    


var pathName = '../new file/';
var fileName = 'v8-transform-data.cpp';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {
        console.log('Succeed in saving ' + pathName + fileName);
    }

});