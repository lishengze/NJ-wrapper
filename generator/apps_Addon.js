/**
 * Created by li.xiankui on 2015/8/23.
 */
// 在命令行中输入node apps_Addon.js
//生成SpiCFunc.h文件。
//结果比原文件多出一些。。
var fs = require('fs');
function hereDoc(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}
var str = hereDoc(function () {/*
 #include <nan.h>
 #include "FtdcSysUserApi_Wrapper.h"
 #include "SpiCFunc.h"

 using namespace v8;

 void InitAll(Handle<Object> exports) {
   FtdcSysUserApi_Wrapper::InitExports(exports);

   uv_async_init(uv_default_loop(), &async, print_progress);
   uv_async_init(uv_default_loop(), &asyncOnFrontDisconnected, OnFrontDisconnected);
   uv_async_init(uv_default_loop(), &asyncOnHeartBeatWarning, OnHeartBeatWarning);


 /////以下为自动生成///////////////////

*/});
var jsonContent=require("./package.json");
var Packagelength=jsonContent.FTD.packages[0].package.length;
var beforeRspQryTopCpuInfoTopic=0;
while(jsonContent.FTD.packages[0].package[beforeRspQryTopCpuInfoTopic].$.name!=="RspQryTopCpuInfoTopic"){
    beforeRspQryTopCpuInfoTopic++;
}
var AfterRtnNetNonPartyLinkInfoTopic=0;
while(jsonContent.FTD.packages[0].package[AfterRtnNetNonPartyLinkInfoTopic].$.name!=="RtnNetNonPartyLinkInfoTopic"){
    AfterRtnNetNonPartyLinkInfoTopic++;
}
AfterRtnNetNonPartyLinkInfoTopic++;

for(var i=beforeRspQryTopCpuInfoTopic;i<AfterRtnNetNonPartyLinkInfoTopic;i++){
    var strName = jsonContent.FTD.packages[0].package[i].$.name;
    if(jsonContent.FTD.packages[0].package[i].$.name.substring(0,3)==="Rsp"||jsonContent.FTD.packages[0].package[i].$.name.substring(0,3)==="Rtn"){
        str+="   uv_async_init(uv_default_loop(), &asyncOn"+jsonContent.FTD.packages[0].package[i].$.name
            +",On"+jsonContent.FTD.packages[0].package[i].$.name+");\n";
    }
}
str+="};\n\n";
str+="NODE_MODULE(addon, InitAll);";
fs.writeFile('../Addon.cc', str, function (err) {
    if (err) throw err;
    console.log('It\'s saved!');
    console.log('package length is:'+Packagelength);
});