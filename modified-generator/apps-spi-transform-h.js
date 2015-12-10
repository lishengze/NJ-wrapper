/**
 * Created by li.shengze on 2015/12/1.
 */

var fs = require('fs');
function hereDoc(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}
var fileData = hereDoc(function () {
/*#ifndef _SPI_TRANSFORM_H_
#define _SPI_TRANSFORM_H_

// 对全局 queue, mutex, async 变量进行声明，相应的定义在spi-transform.cpp里
// 声明V8转换的函数, 定义实现也在spi-transform.cpp里;

#include <queue>
#include <nan.h>
#include <fstream>

using std::fstream;
using std::queue;

extern Nan::Persistent<v8::Object> SpiObj;

extern fstream g_RunningResult_File;
 
extern uv_async_t g_FrontConnected_async;
void   OnFrontConnected(uv_async_t *handle);

// 这些为手工添加

extern queue<int>    g_FrontDisconnected_queue;
extern uv_mutex_t    g_FrontDisconnected_mutex;
extern uv_async_t    g_FrontDisconnected_async;
void   OnFrontDisconnected (uv_async_t *handle);

extern queue<int>    g_HeartBeatWarning_queue;
extern uv_mutex_t    g_HeartBeatWarning_mutex;
extern uv_async_t    g_HeartBeatWarning_async;
void   OnHeartBeatWarning (uv_async_t *handle);

// 以下为自动生成

*/});

var jsonContent = require("./package.json");
var Packagelength = jsonContent.FTD.packages[0].package.length;
var beforeRspQryTopCpuInfoTopic = 0;
var AfterRtnNetNonPartyLinkInfoTopic = 0;

while(jsonContent.FTD.packages[0].package[beforeRspQryTopCpuInfoTopic].$.name!=="RspQryTopCpuInfoTopic"){
    beforeRspQryTopCpuInfoTopic++;
}

while(jsonContent.FTD.packages[0].package[AfterRtnNetNonPartyLinkInfoTopic].$.name!=="RtnNetNonPartyLinkInfoTopic"){
    AfterRtnNetNonPartyLinkInfoTopic++;
}
AfterRtnNetNonPartyLinkInfoTopic++;

for(var i = beforeRspQryTopCpuInfoTopic;i < AfterRtnNetNonPartyLinkInfoTopic;i++) {
    var funcName = jsonContent.FTD.packages[0].package[i].$.name;
    if (funcName.substring(0,3) ==="Rsp" || funcName.substring(0,3) ==="Rtn") {
        fileData += 'extern queue<void**> ' + 'g_' + funcName + '_queue' + ';\n';
        fileData += 'extern uv_mutex_t    ' + 'g_' + funcName + '_mutex' + ';\n';        
        fileData += 'extern uv_async_t    ' + 'g_' + funcName + '_async' + ';\n';        
        fileData += "void   On" + funcName + " (uv_async_t *handle);\n\n";
    }
}

fileData += "\n\n";
fileData += "#endif";
var pathName = '../new file/';
var fileName = 'spi-transform.h';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {            
        console.log('Succeed in saving ' + pathName + fileName);
    }

});