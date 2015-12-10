/**
 * Created by li.xiankui on 2015/8/25.
 */
//生成SysUserSpi.cc文件。
//结果比原文件多出一些。。
var fs = require('fs');
function hereDoc(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}
var fileData = hereDoc(function () {
/*#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory.h>
#include "sysuserspi.h"
#include "spi-transform.h"
#include "tool-function.h"
using std::cin;
using std::cout;
using std::endl;
 
extern fstream g_RunningResult_File;
 
void SysUserSpi::OnFrontConnected(){
    OutputCallbackMessage("SysUserSpi::OnFrontConnected()", g_RunningResult_File);
    uv_async_send(&g_FrontConnected_async);
}
 
void SysUserSpi::OnFrontDisConnected(int nReason){
   OutputCallbackMessage("SysUserSpi::OnFrontDisConnected()!", g_RunningResult_File);    
   uv_mutex_lock(&g_FrontDisconnected_mutex);
   g_FrontDisconnected_queue.push(nReason);
   uv_mutex_unlock(&g_FrontDisconnected_mutex);
    
   uv_async_send(&g_FrontDisconnected_async);
}
 
void SysUserSpi::OnHeartBeatWarning(int nTimeLapse){     
   OutputCallbackMessage("SysUserSpi::OnHeartBeatWarning()!", g_RunningResult_File);
    
   uv_mutex_lock(&g_HeartBeatWarning_mutex);
   g_HeartBeatWarning_queue.push(nTimeLapse);
   uv_mutex_unlock(&g_HeartBeatWarning_mutex);

   uv_async_send(&g_HeartBeatWarning_async);
}
 
 //以下自动生成
*/});

var tabSpace = ["","    ", "        ", "            ", "                ","                    "];

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

for(var i = beforeRspQryTopCpuInfoTopic;i < AfterRtnNetNonPartyLinkInfoTopic;i++) {
    var funcName = jsonContent.FTD.packages[0].package[i].$.name;
    if (funcName.substring(0,3) ==="Rsp" || funcName.substring(0,3) ==="Rtn") {
        fileData += 'int ' + 'g_' + funcName + '_spi_callbackNumb = 0;\n'
    }
}

fileData += "\n";

for(var i = beforeRspQryTopCpuInfoTopic; i < AfterRtnNetNonPartyLinkInfoTopic; i++){
    var fieldName = jsonContent.FTD.packages[0].package[i].field[0].$.name;
    var funcName = jsonContent.FTD.packages[0].package[i].$.name;
    var funcType = funcName.substring(0,3);

    if(funcType === "Rsp" || funcType === "Rtn") {
        var queueName = 'g_' + funcName + '_queue';
        var mutexName = 'g_' + funcName + '_mutex';
        var asyncName = 'g_' + funcName + '_async';
        var valueTypeName = "CShfeFtdc" + fieldName + "Field";
        var pValueName = "p" + fieldName;
        var pNewValueName = "pNew" + fieldName;
        var callbackNumbName = 'g_' + funcName + '_spi_callbackNumb';
        
        if (funcType === "Rsp") {
            fileData += "void SysUserSpi::On" + funcName + "("+ valueTypeName + "* " + pValueName 
                  + ", CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {\n";
        } else {
            fileData += "void SysUserSpi::On" + funcName + "("+ valueTypeName + "* " + pValueName + "){ \n";
        }        

        fileData += tabSpace[1] + "OutputCallbackMessage(\"\\n****** SysUserSpi:: "+ funcName + ": START! ******\", g_RunningResult_File);\n"
        fileData += tabSpace[1] + "OutputCallbackMessage(\""+ callbackNumbName+": \", "+callbackNumbName+"++, g_RunningResult_File);\n\n"
        
        if (funcType === "Rsp") {  
            fileData += tabSpace[1] + "void** paramArray = new void*[4];\n";              
        } else {
            fileData += tabSpace[1] + "void** paramArray = new void*[1];\n";
        }

        fileData += tabSpace[1] + "if (NULL == paramArray) {\n";
        fileData += tabSpace[2] + "OutputCallbackMessage(\"SysUserSpi:: Faild in allocating memory for paramArray\", g_RunningResult_File);\n";
        fileData += tabSpace[2] + "OutputCallbackMessage(\"****** SysUserSpi:: "+ funcName + ": END! ******\\n\", g_RunningResult_File);\n";
        fileData += tabSpace[2] + "return; \n";
        fileData += tabSpace[1] + "} \n\n";
                                
		fileData += tabSpace[1] + valueTypeName + "* "+ pNewValueName + " = NULL;\n";     
        fileData += tabSpace[1] + "if (NULL != "+ pValueName +") { \n";
		fileData += tabSpace[2] + pNewValueName + " = new "+valueTypeName + ";\n";
		fileData += tabSpace[2] + "if (NULL == "+ pNewValueName+") {\n";
		fileData += tabSpace[3] + "OutputCallbackMessage(\"SysUserSpi:: Faild in allocating memory for " + pNewValueName + "\", g_RunningResult_File);\n";
		fileData += tabSpace[3] + "return;\n";
		fileData += tabSpace[2] + "}\n";
		fileData += tabSpace[2] + "memcpy ("+pNewValueName+"," + pValueName+", sizeof("+ valueTypeName +"));\n";
        fileData += tabSpace[1] + "}\n";
	   
		if ("Rsp" == funcType) {
			fileData += hereDoc(function(){/*
	CShfeFtdcRspInfoField* pRspInfoNew = NULL;
    if (NULL != pRspInfo){        
        pRspInfoNew = new CShfeFtdcRspInfoField;        
        if (NULL == pRspInfo) {
            OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pRspInfo", g_RunningResult_File);
            return;            
        }        
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));        
    }	
	
    int*  pId = new int(nRequestID);
    if (NULL == pId) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pId", g_RunningResult_File);
        return;
    }
    
    bool* bIsLastNew = new bool(bIsLast);
    if (NULL == bIsLastNew) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for bIsLastNew", g_RunningResult_File);
        return;
    }  	
*/
            });			
		}
	   

		fileData += "\n";	
		fileData += tabSpace[1] + "paramArray[0] = (void*)" + pNewValueName + ";";
		if ("Rsp" == funcType) {
			fileData += hereDoc(function(){/*
	paramArray[1] = (void*)pRspInfoNew;		
	paramArray[2] = (void*)pId;
    paramArray[3] = (void*)bIsLastNew;			
			*/});
		}        		
        // 输出回调信息;
        fileData += "\n";
        fileData += tabSpace[1] + "if (NULL == "+ pValueName +") { \n";
		fileData += tabSpace[2] + "OutputCallbackMessage(\"SysUserSpi::"+ pValueName +" is NULL\" , g_RunningResult_File); \n"    
        fileData += tabSpace[1] + "} else {\n";              
        for(var j=0;j<lengthField;j++){
            if(jsonContent.FTD.fields[0].fieldDefine[j].$.name===fieldName) {
                var itemlength=jsonContent.FTD.fields[0].fieldDefine[j].item.length;
                for(var k = 0; k<itemlength; k++){
                    var itemName = jsonContent.FTD.fields[0].fieldDefine[j].item[k].$.name;
                    fileData += tabSpace[2] + "OutputCallbackMessage(\"" + pValueName+"->"+itemName + ": \", " 
                              + pValueName + "->" + itemName + ", g_RunningResult_File);\n";
                }
            }
        } 
		
        fileData += tabSpace[1] + "}\n";
      
        if (funcType === "Rsp") {
            fileData += tabSpace[1] + "OutputCallbackMessage(\"pRspInfo:\", pRspInfo, g_RunningResult_File);\n"
                      + tabSpace[1] + "OutputCallbackMessage(\"nRequestID:\", nRequestID, g_RunningResult_File);\n"
                      + tabSpace[1] + "OutputCallbackMessage(\"bIsLast:\", bIsLast, g_RunningResult_File);\n";      
        }                            
		fileData += "\n";
        fileData += tabSpace[1] + "uv_mutex_lock (&" + mutexName + ");\n";
        fileData += tabSpace[1] + queueName + ".push ((void**)&paramArray[0]);\n";
        fileData += tabSpace[1] + "uv_mutex_unlock (&" + mutexName + ");\n";
		fileData += "\n";
        fileData += tabSpace[1] + "uv_async_send(&" + asyncName+");\n";
        
        fileData += tabSpace[1] + "OutputCallbackMessage(\"****** SysUserSpi:: "+ funcName + ": END! ******\\n\", g_RunningResult_File);\n";
        
        fileData += "}\n\n";                
    }
}

fileData += "\n\n";
var pathName = '../new file/';
var fileName = 'sysuserspi.cpp';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {
        console.log('Succeed in saving ' + pathName + fileName);
    }

});