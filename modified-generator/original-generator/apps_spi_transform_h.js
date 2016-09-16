/**
 * Created by li.xiankui on 2015/8/21.
 */
// 在命令行中输入node aas_SpiCFunc.js
//生成SpiCFunc.h文件。
//结果比原文件多出一些。。
var fs = require('fs');
function hereDoc(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}
var str = hereDoc(function () {/*
 #ifndef SPICFUNC_H
 #define SPICFUNC_H


 #include "nan.h"

 extern Nan::Persistent<v8::Object> SpiObj;

 extern uv_async_t async;
 void print_progress(uv_async_t *handle);

 //////这些为手工添加///////////////

 extern uv_async_t asyncOnFrontDisconnected;
 void OnFrontDisconnected(uv_async_t *handle);

 extern uv_async_t asyncOnHeartBeatWarning;
 void OnHeartBeatWarning(uv_async_t *handle);

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
    if(jsonContent.FTD.packages[0].package[i].$.name.substring(0,3)==="Rsp"||jsonContent.FTD.packages[0].package[i].$.name.substring(0,3)==="Rtn"){
        str+=" extern uv_async_t asyncOn"+jsonContent.FTD.packages[0].package[i].$.name+";\n";
        str+=" void On"+jsonContent.FTD.packages[0].package[i].$.name+"(uv_async_t *handle);\n\n";
    }
}
str+="\n\n";
str+="#endif";
fs.writeFile('../SpiCFunc.h', str, function (err) {
    if (err) throw err;
    console.log('It\'s saved!');
    console.log('package length is:'+Packagelength);
});