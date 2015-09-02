/**
 * Created by li.xiankui on 2015/8/25.
 */
//生成SysUserSpi.cc文件。
//结果比原文件多出一些。。
var fs = require('fs');
function hereDoc(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}
var str = hereDoc(function () {/*
 #include "SysUserSpi.h"
 #include <iostream>
 #include "SpiCFunc.h"
 #include <vector>
 #include <string>
 #include <sstream>
 #include <memory.h>
 using namespace std;
 void SysUserSpi::OnFrontConnected(){
     std::cout<<"SysUserSpi::OnFrontConnected()"<<std::endl;
     uv_async_send(&async);
 void SysUserSpi::OnFrontDisConnected(int nReason){
    std::cout<<"SysUserSpi::OnFrontDisConnected()!"<<std::endl;
    asyncOnFrontDisconnected.data=(void*)nReason;
    uv_async_send(&asyncOnFrontDisconnected);
 }
 void SysUserSpi::OnHeartBeatWarning(int nTimeLapse){
    std::cout<<"SysUserSpi::OnHeartBeatWarning()!"<<std::endl;
    asyncOnHeartBeatWarning.data=(void*)nTimeLapse;
    uv_async_send(&asyncOnHeartBeatWarning);
 }
 }
 //以下自动生成
*/});
var jsonContent=require("./package.json");
var Packagelength=jsonContent.FTD.packages[0].package.length;
var lengthField=jsonContent.FTD.fields[0].fieldDefine.length;
var beforeRspQryTopCpuInfoTopic=0;
var AfterRtnNetNonPartyLinkInfoTopic=0;

while(jsonContent.FTD.packages[0].package[beforeRspQryTopCpuInfoTopic].$.name!=="RspQryTopCpuInfoTopic"){
    beforeRspQryTopCpuInfoTopic++;
}
while(jsonContent.FTD.packages[0].package[AfterRtnNetNonPartyLinkInfoTopic].$.name!=="RtnNetNonPartyLinkInfoTopic"){
    AfterRtnNetNonPartyLinkInfoTopic++;
}
AfterRtnNetNonPartyLinkInfoTopic++;

for(var i=beforeRspQryTopCpuInfoTopic;i<AfterRtnNetNonPartyLinkInfoTopic;i++){
    var fieldName=jsonContent.FTD.packages[0].package[i].field[0].$.name;
    var packageName=jsonContent.FTD.packages[0].package[i].$.name;
    if(jsonContent.FTD.packages[0].package[i].$.name.substring(0,3)==="Rsp"){
        str+="void SysUserSpi::On"+jsonContent.FTD.packages[0].package[i].$.name+"(CShfeFtdc"+
          fieldName+"Field *p"+fieldName+", CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)\n";
        str+="{\n";
        str+="  std::cout<<\"ok\"<<std::endl;\n";
        for(var j=0;j<lengthField;j++){
            if(jsonContent.FTD.fields[0].fieldDefine[j].$.name===fieldName) {
                var itemlength=jsonContent.FTD.fields[0].fieldDefine[j].item.length;
                for(k=0;k<itemlength;k++){
                    var itemName = jsonContent.FTD.fields[0].fieldDefine[j].item[k].$.name;
                    str += "  std::cout<<\"on p" + fieldName+"->"+itemName + ":\"<<p" + fieldName + "->" + itemName + "<<std::endl;\n";
                }
            }
        }
        str+="  std::cout<<\"on pRspInfo:\"<<pRspInfo<<std::endl;\n";
        str+="  std::cout<<\"on nRequestID:\"<<nRequestID<<std::endl;\n";
        str+="  std::cout<<\"on bIsLast:\"<<bIsLast<<std::endl;\n";
        str+="  CShfeFtdc"+fieldName+"Field* pNew"+fieldName+" =new CShfeFtdc"+fieldName+"Field;\n";
        str+="  memcpy(pNew"+fieldName+",p"+fieldName+",sizeof(CShfeFtdc"+fieldName+"Field));\n";
        str+="  int *pId=new int(nRequestID);\n";
        str+="  bool *bIsLastNew=new bool(bIsLast);\n";
        str+="  void** paramArray=new void*[4];\n";
        str+="  paramArray[0]=(void*)pNew"+fieldName+";\n";
        str+=hereDoc(function(){/*
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
*/})
        str+="  asyncOn"+packageName+".data=(void*)&paramArray[0];\n";
        str+="  uv_async_send(&asyncOn"+packageName+");\n";
        str+="  std::cout<<\"end send \"<<std::endl;\n";
        str+="}\n";

    }

    if(jsonContent.FTD.packages[0].package[i].$.name.substring(0,3)==="Rtn"){
        str+="void SysUserSpi::On"+jsonContent.FTD.packages[0].package[i].$.name+"(CShfeFtdc"+
            fieldName+"Field *p"+fieldName+")\n";
        str+="{\n";
        str+="  std::cout<<\"ok\"<<std::endl;\n";
        for(var j=0;j<lengthField;j++){
            if(jsonContent.FTD.fields[0].fieldDefine[j].$.name===fieldName) {
                var itemlength=jsonContent.FTD.fields[0].fieldDefine[j].item.length;
                for(k=0;k<itemlength;k++){
                    var itemName = jsonContent.FTD.fields[0].fieldDefine[j].item[k].$.name;
                    str += "  std::cout<<\"on p" + fieldName+"->"+itemName + ":\"<<p" + fieldName + "->" + itemName + "<<std::endl;\n";
                }
            }
        }
        str+="  CShfeFtdc"+fieldName+"Field* pNew"+fieldName+" =new CShfeFtdc"+fieldName+"Field;\n";
        str+="  memcpy(pNew"+fieldName+",p"+fieldName+",sizeof(CShfeFtdc"+fieldName+"Field));\n";
        str+="  void** paramArray=new void*[4];\n";
        str+="  paramArray[0]=(void*)pNew"+fieldName+";\n";
        str+="  asyncOn"+packageName+".data=(void*)&paramArray[0];\n";
        str+="  uv_async_send(&asyncOn"+packageName+");\n";
        str+="  std::cout<<\"end send \"<<std::endl;\n";
        str+="}\n";

    }
}
str+="\n\n";
fs.writeFile('SysUserSpi.cc', str, function (err) {
    if (err) throw err;
    console.log('It\'s saved!');
    console.log('package length is:'+Packagelength);
});