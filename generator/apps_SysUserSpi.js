/**
 * Created by li.xiankui on 2015/8/21.
 */
// 在命令行中输入node aas_SUA_Wrapper.js
// 生成SysUserSpi.h文件。
var fs = require('fs');
function hereDoc(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}
var str = hereDoc(function () {/*
 #ifndef SYSUSERSPI_H
 #define SYSUSERSPI_H

 #include "FtdcSysUserApi.h"
 #include "nan.h"

 class SysUserSpi: public CShfeFtdcSysUserSpi
 {
   public:

    virtual void OnFrontConnected();
    virtual void OnFrontDisConnected(int nReason);
    virtual void OnHeartBeatWarning(int nTimeLapse);
 /////以下为自动生成///////////////////

*/});
//var jsonContent=require("./package.json");
//var Packagelength=jsonContent.FTD.packages[0].package.length;
//for(var i=0;i<Packagelength;i++){
//    if(jsonContent.FTD.packages[0].package[i].$.name.substring(0,3)==="Req")
//        str+="     static NAN_METHOD("+jsonContent.FTD.packages[0].package[i].$.name+");\n";
//}
var jsonContent=require("./package.json");
var Packagelength=jsonContent.FTD.packages[0].package.length;
var lengthField=jsonContent.FTD.fields[0].fieldDefine.length;
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
    var fieldName=jsonContent.FTD.packages[0].package[i].field[0].$.name;
    if(jsonContent.FTD.packages[0].package[i].$.name.substring(0,3)==="Rsp"){
        str+="    virtual void On"+jsonContent.FTD.packages[0].package[i].$.name+"(CShfeFtdc"+
            fieldName+"Field *p"+fieldName+", CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);\n\n";

        }

    if(jsonContent.FTD.packages[0].package[i].$.name.substring(0,3)==="Rtn"){
        str+="    virtual void On"+jsonContent.FTD.packages[0].package[i].$.name+"(CShfeFtdc"+
            fieldName+"Field *p"+fieldName+");\n\n";
           }
}

str+="};\n\n";
str+="#endif";
fs.writeFile('SysUserSpi.h', str, function (err) {
    if (err) throw err;
    console.log('It\'s saved!');
  //console.log('package length is:'+Packagelength);
});
