/**
 * Created by li.shengze on 2015/11/30.
 * 自动生成 addon.cpp 文件 用于生成供JS调用的.node文件;
 * InitAll(): 初始化async, mutex全局变量;
 *             
*/
var fs = require('fs');
function hereDoc(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}
var fileData = hereDoc(function () {/*
 #include <nan.h>
 #include "FtdcSysUserApi_Wrapper.h"
 #include "SpiCFunc.h"

 using namespace v8;

 void InitAll(Handle<Object> exports) {
        
   FtdcSysUserApi_Wrapper::InitExports(exports);
   
   uv_async_init(uv_default_loop(), &async, print_progress);
   uv_async_init(uv_default_loop(), &asyncOnFrontDisconnected, OnFrontDisconnected);
   uv_async_init(uv_default_loop(), &asyncOnHeartBeatWarning, OnHeartBeatWarning);

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

var oneTabSpace = "   ";
for (var i = beforeRspQryTopCpuInfoTopic; i < AfterRtnNetNonPartyLinkInfoTopic; i++) {
    var funcName = jsonContent.FTD.packages[0].package[i].$.name;
    
    if (funcName.substring(0,3) ==="Rsp" || funcName.substring(0,3) ==="Rtn") {        
        var asyncVarName = "g_" + funcName + "_async";
        fileData += oneTabSpace + "uv_async_init(uv_default_loop(), &" + asyncVarName +");\n";
    }
}

fileData += "};\n\n";
fileData += "NODE_MODULE(addon, InitAll);";
var pathName = '../new file/';
var fileName = 'addon.cpp';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {            
        console.log('It\'s saved!');
        console.log('package length is:'+Packagelength);
    }

});