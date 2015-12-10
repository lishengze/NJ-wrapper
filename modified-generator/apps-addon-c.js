/**
 * Created by li.shengze on 2015/11/30.
 * 自动生成 addon.cpp 文件 用于生成供JS调用的.node文件;
 * hereDoc: 将注释范围内的内容转换成对应的字符串;
 *             
*/
var fs = require('fs');
function hereDoc(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}
var fileData = hereDoc(function () {
/*#include <nan.h>
#include "ftdcsysuserapi-wrapper.h"
#include "spi-transform.h"
#include "tool-function.h"
#include <fstream>
using std::fstream;

extern fstream g_RunningResult_File;

using namespace v8;

void InitAll(Handle<Object> exports) {
        
    FtdcSysUserApi_Wrapper::InitExports (exports);
    
    g_RunningResult_File.open("running-result.txt",ios::out);
    
    if (!g_RunningResult_File) {
        OutputCallbackMessage("Failed to open running-message.txt", g_RunningResult_File);
        g_RunningResult_File.close();
    }
   
    uv_async_init (uv_default_loop(), &g_FrontConnected_async, OnFrontConnected);
    
    uv_async_init (uv_default_loop(), &g_FrontDisconnected_async, OnFrontDisconnected);
    uv_mutex_init (&g_FrontDisconnected_mutex);
    
    uv_async_init (uv_default_loop(), &g_HeartBeatWarning_async, OnHeartBeatWarning);
    uv_mutex_init (&g_HeartBeatWarning_mutex);
   
    // 以下为自动生成
*/
});


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

var tabSpace = ["","    ", "        ", "            ", "                ","                    "];
for (var i = beforeRspQryTopCpuInfoTopic; i < AfterRtnNetNonPartyLinkInfoTopic; i++) {
    var funcName = jsonContent.FTD.packages[0].package[i].$.name;    
    if (funcName.substring(0,3) ==="Rsp" || funcName.substring(0,3) ==="Rtn") {        
        fileData += tabSpace[1] + "uv_async_init (uv_default_loop(), &" + "g_" + funcName + "_async" +", On" + funcName +");\n";
        fileData += tabSpace[1] + "uv_mutex_init (&" + 'g_' + funcName + '_mutex' + ");\n\n";
    }
}

fileData += "};\n\n";
fileData += "NODE_MODULE (addon, InitAll);";

var fileName = 'addon.cpp';
var pathName = '../new file/';
//var pathName = ['../new file/', '../'];
// for (var i = 0; i<2; ++i) {
//     fs.writeFile(pathName[i] + fileName, fileData, function (err) {
//         if (err) {
//             console.log(err);
//         } else {            
//             console.log('Succeed in saving ' + pathName[i] + fileName);
//         }
    
//     });    
// }

    fs.writeFile(pathName + fileName, fileData, function (err) {
        if (err) {
            console.log(err);
        } else {            
            console.log('Succeed in saving ' + pathName + fileName);
        }
    
    });    