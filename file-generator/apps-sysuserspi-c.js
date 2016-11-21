/**
 * Created by li.shengze on 2015/1/31.
 */

var fs = require('fs');
var hereDoc = require('../lib/tool-function.js').hereDoc;
var ftdContent = require("../lib/FTD.json");
var sysContent = require("../lib/sysuserapi.json");

var ftdFuncs = ftdContent.FTD.packages[0].package;
var ftdField = ftdContent.FTD.fields[0].fieldDefine;
var sysFuncs = sysContent.sysuserapi.ftdpackage;
var tabSpace = ["","    ", "        ", "            ", "                ","                    "];

var fileData = hereDoc(function () {
/*#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory.h>
#include "sysuserspi.h"
#include "v8-transform-data.h"
#include "tool-function.h"
#include <fstream>
#include <queue>
#include <map>
#include <vector>
using std::queue;
using std::map;
using std::vector;
using std::fstream;
using std::cin;
using std::cout;
using std::endl;
 
extern fstream g_RunningResult_File;
 
void SysUserSpi::OnFrontConnected () {
    OutputCallbackMessage("\n************SysUserSpi::OnFrontConnected() START! ************", g_RunningResult_File);

    void** paramArray = new void*[1];
    if (NULL == paramArray) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for paramArray", g_RunningResult_File);
        OutputCallbackMessage("****** SysUserSpi:: OnFrontConnected: END! ******\n", g_RunningResult_File);
        return;
    }

    Nan::Persistent<v8::Object>* pSpiObj = new Nan::Persistent<v8::Object>;
    if (NULL == pSpiObj) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pSpiObj", g_RunningResult_File);
        OutputCallbackMessage("****** SysUserSpi:: OnFrontConnected: END! ******\n", g_RunningResult_File);
        return;        
    }           
    memcpy(pSpiObj, &(this->m_spiobj), sizeof(Nan::Persistent<v8::Object>));
    
    paramArray[0] = (void*)pSpiObj; 
        
    uv_mutex_lock(&g_FrontConnected_mutex);
    vector<FRONT_ID>::iterator it ;
    for(it = g_FrontConnected_IOUser_vec.begin();
        it != g_FrontConnected_IOUser_vec.end(); it++ ) {
        if (*it == this->m_frontid){
             break;
        }       
    }            
    if (it ==  g_FrontConnected_IOUser_vec.end()) {
        g_FrontConnected_IOUser_vec.push_back(this->m_frontid);
    }  
    g_FrontConnected_Data_map[this->m_frontid].push((void**)(&paramArray[0]));
    uv_mutex_unlock(&g_FrontConnected_mutex);

    uv_async_send(&g_FrontConnected_async);

    OutputCallbackMessage("************SysUserSpi::OnFrontConnected() END! ************\n", g_RunningResult_File);
}

void SysUserSpi::OnFrontDisConnected (int nReason) {
    OutputCallbackMessage("\n************SysUserSpi::OnFrontDisConnected() START! ************", g_RunningResult_File);

    void** paramArray = new void*[2];
    if (NULL == paramArray) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for paramArray", g_RunningResult_File);
        OutputCallbackMessage("****** SysUserSpi:: OnFrontConnected: END! ******\n", g_RunningResult_File);
        return;
    }

    Nan::Persistent<v8::Object>* pSpiObj = new Nan::Persistent<v8::Object>;
    if (NULL == pSpiObj) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pSpiObj", g_RunningResult_File);
        OutputCallbackMessage("****** SysUserSpi:: OnFrontConnected: END! ******\n", g_RunningResult_File);
        return;        
    }           
    memcpy(pSpiObj, &(this->m_spiobj), sizeof(Nan::Persistent<v8::Object>));
    
    int* pReason = new int;
    if (NULL == pReason){
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pReason", g_RunningResult_File);
        OutputCallbackMessage("****** SysUserSpi:: OnFrontConnected: END! ******\n", g_RunningResult_File);
        return;           
    }
    *pReason = nReason;
    
    paramArray[0] = (void*)pSpiObj; 
    paramArray[1] = (void*)pReason;
    
    uv_mutex_lock(&g_FrontDisconnected_mutex);
    vector<FRONT_ID>::iterator it ;
    for(it = g_FrontDisconnected_IOUser_vec.begin();
        it != g_FrontDisconnected_IOUser_vec.end(); it++ ) {
        if (*it == this->m_frontid){
             break;
        }       
    }            
    if (it ==  g_FrontDisconnected_IOUser_vec.end()) {
        g_FrontDisconnected_IOUser_vec.push_back(this->m_frontid);
    }      
    g_FrontDisconnected_Data_map[this->m_frontid].push((void**)(&paramArray[0]));
    uv_mutex_unlock(&g_FrontDisconnected_mutex);
    
    uv_async_send(&g_FrontDisconnected_async);
   
    OutputCallbackMessage("************SysUserSpi::OnFrontDisConnected() END! ************\n", g_RunningResult_File);
}
    
 
void SysUserSpi::OnHeartBeatWarning (int nTimeLapse) { 
    OutputCallbackMessage("\n************SysUserSpi::OnHeartBeatWarning() START! ************", g_RunningResult_File);

    void** paramArray = new void*[2];
    if (NULL == paramArray) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for paramArray", g_RunningResult_File);
        OutputCallbackMessage("****** SysUserSpi:: OnHeartBeatWarning: END! ******\n", g_RunningResult_File);
        return;
    }

    Nan::Persistent<v8::Object>* pSpiObj = new Nan::Persistent<v8::Object>;
    if (NULL == pSpiObj) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pSpiObj", g_RunningResult_File);
        OutputCallbackMessage("****** SysUserSpi:: OnHeartBeatWarning: END! ******\n", g_RunningResult_File);
        return;        
    }           
    memcpy(pSpiObj, &(this->m_spiobj), sizeof(Nan::Persistent<v8::Object>));
    
    int* pTimeLapse = new int;
    if (NULL == pTimeLapse){
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pReason", g_RunningResult_File);
        OutputCallbackMessage("****** SysUserSpi:: OnHeartBeatWarning: END! ******\n", g_RunningResult_File);
        return;           
    }
    *pTimeLapse = nTimeLapse;

    paramArray[0] = (void*)pSpiObj; 
    paramArray[1] = (void*)pTimeLapse; 
        
    uv_mutex_lock(&g_HeartBeatWarning_mutex);
    vector<FRONT_ID>::iterator it ;
    for(it = g_HeartBeatWarning_IOUser_vec.begin();
        it != g_HeartBeatWarning_IOUser_vec.end(); it++ ) {
        if (*it == this->m_frontid){
             break;
        }       
    }            
    if (it ==  g_HeartBeatWarning_IOUser_vec.end()) {
        g_HeartBeatWarning_IOUser_vec.push_back(this->m_frontid);
    }    
    g_HeartBeatWarning_Data_map[this->m_frontid].push((void**)(&paramArray[0]));
    
    uv_mutex_unlock(&g_HeartBeatWarning_mutex);

    uv_async_send(&g_HeartBeatWarning_async);

    OutputCallbackMessage("************SysUserSpi::OnHeartBeatWarning() END! ************\n", g_RunningResult_File);
}

*/});

for (var i = 0; i < sysFuncs.length; ++i) {
    var funcName = sysFuncs[i].$.name;
	var funcType = funcName.substring(0, 3);
    if (funcType === "Rsp" || funcType === "Rtn") {
        for (var j = 0; j < ftdFuncs.length; ++j) {
            if (ftdFuncs[j].$.name === funcName) {                
                var fieldName = ftdFuncs[j].field[0].$.name;
                var queueName  = 'g_' + funcName + '_Data_map';
                var vectorname = 'g_' + funcName + '_IOUser_vec';
                var mutexName  = 'g_' + funcName + '_mutex';
                var asyncName  = 'g_' + funcName + '_async';
                var valueTypeName = "CShfeFtdc" + fieldName + "Field";
                var pValueName = "p" + fieldName;
                var pNewValueName = "pNew" + fieldName;
                
                if (funcType === "Rsp") {
                    fileData += "void SysUserSpi::On" + funcName + "("+ valueTypeName + "* " + pValueName 
                        + ", CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {\n";
                } else {
                    fileData += "void SysUserSpi::On" + funcName + "("+ valueTypeName + "* " + pValueName + "){ \n";
                }        

                fileData += tabSpace[1] + "OutputCallbackMessage(\"\\n****** SysUserSpi:: "+ funcName + ": START! ******\", g_RunningResult_File);\n\n"

                // 数据转换;
                if (funcType === "Rsp") {  
                    fileData += tabSpace[1] + "void** paramArray = new void*[5];\n"              
                } else {
                    fileData += tabSpace[1] + "void** paramArray = new void*[2];\n"
                }
                fileData += tabSpace[1] + "if (NULL == paramArray) {\n"
                          + tabSpace[2] + "OutputCallbackMessage(\"SysUserSpi:: Faild in allocating memory for paramArray\", g_RunningResult_File);\n"
                          + tabSpace[2] + "OutputCallbackMessage(\"****** SysUserSpi:: "+ funcName + ": END! ******\\n\", g_RunningResult_File);\n"
                          + tabSpace[2] + "return; \n"
                          + tabSpace[1] + "} \n\n"

                fileData += tabSpace[1] + "Nan::Persistent<v8::Object>* pSpiObj = new Nan::Persistent<v8::Object>; \n"
                          + tabSpace[1] + "if (NULL == pSpiObj) { \n"
                          + tabSpace[2] + "OutputCallbackMessage(\"SysUserSpi:: Faild in allocating memory for pSpiObj\", g_RunningResult_File);\n"
                          + tabSpace[2] + "OutputCallbackMessage(\"****** SysUserSpi:: "+ funcName + ": END! ******\\n\", g_RunningResult_File);\n"
                          + tabSpace[2] + "return; \n"
                          + tabSpace[1] + "}\n"
                          + tabSpace[1] + "memcpy(pSpiObj, &(this->m_spiobj), sizeof(Nan::Persistent<v8::Object>)); \n\n"
                          + tabSpace[1] + valueTypeName + "* "+ pNewValueName + " = NULL;\n"     
                          + tabSpace[1] + "if (NULL != "+ pValueName +") { \n"
                          + tabSpace[2] + pNewValueName + " = new "+valueTypeName + ";\n"
                          + tabSpace[2] + "if (NULL == "+ pNewValueName+") {\n"
                          + tabSpace[3] + "OutputCallbackMessage(\"SysUserSpi:: Faild in allocating memory for " + pNewValueName + "\", g_RunningResult_File);\n"
                          + tabSpace[3] + "return;\n"
                          + tabSpace[2] + "}\n"
                          + tabSpace[2] + "memcpy ("+pNewValueName+"," + pValueName+", sizeof("+ valueTypeName +"));\n"
                          + tabSpace[1] + "}\n\n"
            
                if ("Rsp" == funcType) {
                    fileData += tabSpace[1] + "CShfeFtdcRspInfoField* pRspInfoNew = NULL; \n"
                            + tabSpace[1] + "if (NULL != pRspInfo){ \n"
                            + tabSpace[2] + "pRspInfoNew = new CShfeFtdcRspInfoField;\n"
                            + tabSpace[2] + "if (NULL == pRspInfo) {\n"
                            + tabSpace[3] + "OutputCallbackMessage(\"SysUserSpi:: Faild in allocating memory for pRspInfo\", g_RunningResult_File);\n"
                            + tabSpace[3] + "return; \n"
                            + tabSpace[2] + "} \n"
                            + tabSpace[2] + "memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));\n"
                            + tabSpace[1] + "} \n\n"
                            + tabSpace[1] + "int*  pId = new int(nRequestID); \n"
                            + tabSpace[1] + "if (NULL == pId) { \n"
                            + tabSpace[2] + "OutputCallbackMessage(\"SysUserSpi:: Faild in allocating memory for pId\", g_RunningResult_File);\n"
                            + tabSpace[2] + "return;\n"
                            + tabSpace[1] + "} \n\n"
                            + tabSpace[1] + "bool* bIsLastNew = new bool(bIsLast); \n"
                            + tabSpace[1] + "if (NULL == bIsLastNew) { \n"
                            + tabSpace[2] + "OutputCallbackMessage(\"SysUserSpi:: Faild in allocating memory for bIsLastNew\", g_RunningResult_File); \n"
                            + tabSpace[2] + "return; \n"
                            + tabSpace[1] + "} \n\n"		
                }
	
                fileData += tabSpace[1] + "paramArray[0] = (void*)pSpiObj;\n";
                fileData += tabSpace[1] + "paramArray[1] = (void*)" + pNewValueName + ";\n";
                if ("Rsp" == funcType) {
                    fileData += tabSpace[1] + "paramArray[2] = (void*)pRspInfoNew; \n"
                              + tabSpace[1] + "paramArray[3] = (void*)pId; \n"
                              + tabSpace[1] + "paramArray[4] = (void*)bIsLastNew; \n";	
                }	     		
                
                fileData += "\n";

                // 输出日志信息;
                fileData += tabSpace[1] + "if (NULL == "+ pValueName +") { \n";
                        fileData += tabSpace[2] + "OutputCallbackMessage(\"SysUserSpi::"+ pValueName +" is NULL\" , g_RunningResult_File); \n"    
                fileData += tabSpace[1] + "} else {\n";      

                for (var fieldIndex = 0; fieldIndex < ftdField.length; ++fieldIndex) {
                    if (ftdField[fieldIndex].$.name === fieldName) {
                        for (var itemIndex = 0; itemIndex < ftdField[fieldIndex].item.length; ++itemIndex) {
                            var itemName = ftdField[fieldIndex].item[itemIndex].$.name;
                            fileData += tabSpace[2] + "OutputCallbackMessage(\"" + pValueName+"->"+itemName + ": \", " 
                                      + pValueName + "->" + itemName + ", g_RunningResult_File);\n";
                        }
                    }
                } 
                
                fileData += tabSpace[1] + "}\n";
            
                if (funcType === "Rsp") {
                    fileData += tabSpace[1] + "OutputCallbackMessage(\"pRspInfo:\", pRspInfo, g_RunningResult_File);\n"
                              + tabSpace[1] + "OutputCallbackMessage(\"nRequestID:\", nRequestID, g_RunningResult_File);\n"
                              + tabSpace[1] + "OutputCallbackMessage(\"bIsLast:\", bIsLast, g_RunningResult_File);\n"      
                }      
                
                // 将数据传输到V8转换线程中;
                fileData += "\n";                  
                fileData += tabSpace[1] + "uv_mutex_lock (&" + mutexName + ");\n"
                          + tabSpace[1] + "vector<FRONT_ID>::iterator it ;\n"
                          + tabSpace[1] + "for(it = " + vectorname + ".begin();\n"
                          + tabSpace[2] + "it != " + vectorname + ".end(); it++ ) {\n"
                          + tabSpace[2] + "if (*it == this->m_frontid) break;     \n"
                          + tabSpace[1] + "}\n"
                          + tabSpace[1] + "if (it == " + vectorname + ".end()) {\n"
                          + tabSpace[2] +  vectorname + ".push_back(this->m_frontid);\n"
                          + tabSpace[1] + "}\n"
                          + tabSpace[1] + queueName + "[this->m_frontid].push ((void**)&paramArray[0]);\n"
                          + tabSpace[1] + "uv_mutex_unlock (&" + mutexName + ");\n\n"
                          + tabSpace[1] + "uv_async_send(&" + asyncName+");\n\n"
            
                fileData += tabSpace[1] + "OutputCallbackMessage(\"****** SysUserSpi:: "+ funcName + ": END! ******\\n\", g_RunningResult_File);\n";
                
                fileData += "}\n\n";                
            }
        }
    }
}

fileData += "\n\n";
var pathName = '../new-file/';
var fileName = 'sysuserspi.cpp';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {
        console.log('Succeed in saving ' + pathName + fileName);
    }

});


// var firstParaDataStructName = "";
// var firstParaDataName = "";
// var pNewValueName = "";
// var funcName = "";
// var bHasNoPara = false;

// for (var i = 0; i < FuncCol.length; ++i) {
// 	var funcType = FuncCol[i].$.name.substring(0, 3);
//     var funcCore = FuncCol[i].field[0].$.name;
//     bHasNoPara = false;
//     if(funcType === "Rsp" || funcType === "Rtn" || funcType === "Spi") {
//         if (funcType === "Spi") {
//             funcName = FuncCol[i].field[1].$.name;
//         } else {
//             funcName = FuncCol[i].$.name;
//         }
//         var queueName  = 'g_' + funcName + '_Data_map';
//         var vectorname = 'g_' + funcName + '_IOUser_vec';
//         var mutexName  = 'g_' + funcName + '_mutex';
//         var asyncName  = 'g_' + funcName + '_async';
//         if (funcType === "Rsp" || funcType === "Rtn") {
//             firstParaDataStructName = "CShfeFtdc" + funcCore + "Field";
//             firstParaDataName = "p" + funcCore;
//             pNewValueName = "pNew" + funcCore;
//         } else {
//             if (FuncCol[i].field.length > 2) {
//                 firstParaDataStructName =  FuncCol[i].field[2].$.name;
//                 firstParaDataName = FuncCol[i].field[3].$.name;
//                 pNewValueName = "pNew" + FuncCol[i].field[3].$.name;
//             } else {
//                 bHasNoPara = true;
//             }
//         }        
        
//         if (funcType === "Rsp") {
//             fileData += "void SysUserSpi::On" + funcName + "("+ firstParaDataStructName + "* " + firstParaDataName 
//                   + ", CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {\n";
//         } else if (funcType === "Rtn"){
//             fileData += "void SysUserSpi::On" + funcName + "("+ firstParaDataStructName + "* " + firstParaDataName + "){ \n";
//         } else {
//             fileData += "void SysUserSpi::On" + funcName + "("+ firstParaDataStructName + " " + firstParaDataName + "){ \n";
//         } 

//         fileData += tabSpace[1] + "OutputCallbackMessage(\"\\n****** SysUserSpi:: "+ funcName + ": START! ******\", g_RunningResult_File);\n"
//                   + tabSpace[1] + "Nan::Persistent<v8::Object>* pSpiObj = new Nan::Persistent<v8::Object>; \n"
//                   + tabSpace[1] + "if (NULL == pSpiObj) { \n"
//                   + tabSpace[2] + "OutputCallbackMessage(\"SysUserSpi:: Faild in allocating memory for pSpiObj\", g_RunningResult_File);\n"
//                   + tabSpace[2] + "OutputCallbackMessage(\"****** SysUserSpi:: "+ funcName + ": END! ******\\n\", g_RunningResult_File);\n"
//                   + tabSpace[1] + "}\n"
//                   + tabSpace[1] + "memcpy(pSpiObj, &(this->m_spiobj), sizeof(Nan::Persistent<v8::Object>)); \n\n";

//         if (funcType === "Rsp") {  
//             fileData += tabSpace[1] + "void** paramArray = new void*[5];\n";              
//         } else if (firstParaDataStructName !== ""){
//             fileData += tabSpace[1] + "void** paramArray = new void*[2];\n";
//         } else {
//             fileData += tabSpace[1] + "void** paramArray = new void*[1];\n";
//         }
//         fileData += tabSpace[1] + "if (NULL == paramArray) {\n";
//                   + tabSpace[2] + "OutputCallbackMessage(\"SysUserSpi:: Faild in allocating memory for paramArray\", g_RunningResult_File);\n"
//                   + tabSpace[2] + "OutputCallbackMessage(\"****** SysUserSpi:: "+ funcName + ": END! ******\\n\", g_RunningResult_File);\n"
//                   + tabSpace[2] + "return; \n"
//                   + tabSpace[1] + "} \n\n"

//         if (bHasNoPara === false) {
//             fileData += tabSpace[1] + firstParaDataStructName + "* "+ pNewValueName + " = NULL;\n"    
//                       + tabSpace[1] + "if (NULL != "+ firstParaDataName +") { \n"
//                       + tabSpace[2] + pNewValueName + " = new "+firstParaDataStructName + ";\n"
//                       + tabSpace[2] + "if (NULL == "+ pNewValueName+") {\n"
//                       + tabSpace[3] + "OutputCallbackMessage(\"SysUserSpi:: Faild in allocating memory for " + pNewValueName + "\", g_RunningResult_File);\n"
//                       + tabSpace[3] + "return;\n"
//                       + tabSpace[2] + "}\n"
//             if (funcType === "Spi") {
//                 fileData += tabSpace[2] + "memcpy ("+pNewValueName+", &" + firstParaDataName+", sizeof("+ firstParaDataStructName +"));\n";                
//             } else {
//                 fileData += tabSpace[2] + "memcpy ("+pNewValueName+"," + firstParaDataName+", sizeof("+ firstParaDataStructName +"));\n";                
//             }
//             fileData += tabSpace[1] + "}\n";
//         }                                
	   
// 		if ("Rsp" == funcType) {
//             fileData += tabSpace[1] + "CShfeFtdcRspInfoField* pRspInfoNew = NULL; \n"
//                       + tabSpace[1] + "if (NULL != pRspInfo){ \n"
//                       + tabSpace[2] + "pRspInfoNew = new CShfeFtdcRspInfoField;\n"
//                       + tabSpace[2] + "if (NULL == pRspInfo) {\n"
//                       + tabSpace[3] + "OutputCallbackMessage(\"SysUserSpi:: Faild in allocating memory for pRspInfo\", g_RunningResult_File);\n"
//                       + tabSpace[3] + "return; \n"
//                       + tabSpace[2] + "} \n"
//                       + tabSpace[2] + "memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));\n"
//                       + tabSpace[1] + "} \n\n"
//                       + tabSpace[1] + "int*  pId = new int(nRequestID); \n"
//                       + tabSpace[1] + "if (NULL == pId) { \n"
//                       + tabSpace[2] + "OutputCallbackMessage(\"SysUserSpi:: Faild in allocating memory for pId\", g_RunningResult_File);\n"
//                       + tabSpace[2] + "return;\n"
//                       + tabSpace[1] + "} \n\n"
//                       + tabSpace[1] + "bool* bIsLastNew = new bool(bIsLast); \n"
//                       + tabSpace[1] + "if (NULL == bIsLastNew) { \n"
//                       + tabSpace[2] + "OutputCallbackMessage(\"SysUserSpi:: Faild in allocating memory for bIsLastNew\", g_RunningResult_File); \n"
//                       + tabSpace[2] + "return; \n"
//                       + tabSpace[1] + "} \n"		
// 		}	   

// 		fileData += "\n";	
//         fileData += tabSpace[1] + "paramArray[0] = (void*)pSpiObj;\n";
//         if (bHasNoPara === false) { 
//             fileData += tabSpace[1] + "paramArray[1] = (void*)" + pNewValueName + ";";
//         }
		
// 		if ("Rsp" == funcType) {
//             fileData += tabSpace[1] + "paramArray[2] = (void*)pRspInfoNew; \n"
//                       + tabSpace[1] + "paramArray[3] = (void*)pId; \n"
//                       + tabSpace[1] + "paramArray[4] = (void*)bIsLastNew; \n\n";	
//         }	
        
//         // 输出日志信息;
//         if(bHasNoPara === false) {
//             fileData += "\n";
//             fileData += tabSpace[1] + "if (NULL == "+ firstParaDataName +") { \n";
//             fileData += tabSpace[2] + "OutputCallbackMessage(\"SysUserSpi::"+ firstParaDataName +" is NULL\" , g_RunningResult_File); \n"    
//             fileData += tabSpace[1] + "} else {\n";  
//             if (funcType === "Rsp" || funcType === "Rtn") {
//                 for(var j=0;j<jsonContent.FTD.fields[0].fieldDefine.length;j++){
//                     if(jsonContent.FTD.fields[0].fieldDefine[j].$.name===funcCore) {
//                         var itemlength=jsonContent.FTD.fields[0].fieldDefine[j].item.length;
//                         for(var k = 0; k<itemlength; k++){
//                             var itemName = jsonContent.FTD.fields[0].fieldDefine[j].item[k].$.name;
//                             fileData += tabSpace[2] + "OutputCallbackMessage(\"" + firstParaDataName+"->"+itemName + ": \", " 
//                                     + firstParaDataName + "->" + itemName + ", g_RunningResult_File);\n";
//                         }
//                     }
//                 } 
//             } else {
//                 fileData += tabSpace[2] + "OutputCallbackMessage(\"" + firstParaDataName+":\", "
//                           + firstParaDataName + ", g_RunningResult_File);\n";                
//             }    
            
//             fileData += tabSpace[1] + "}\n";
//         }

//         if (funcType === "Rsp") {
//             fileData += tabSpace[1] + "OutputCallbackMessage(\"pRspInfo:\", pRspInfo, g_RunningResult_File);\n"
//                       + tabSpace[1] + "OutputCallbackMessage(\"nRequestID:\", nRequestID, g_RunningResult_File);\n"
//                       + tabSpace[1] + "OutputCallbackMessage(\"bIsLast:\", bIsLast, g_RunningResult_File);\n";      
//         }      
        
//         // 将数据传输到V8转换线程中;
//         fileData += "\n";                  
//         fileData += tabSpace[1] + "uv_mutex_lock (&" + mutexName + ");\n";
//         fileData += tabSpace[1] + "vector<FRONT_ID>::iterator it ;\n";
//         fileData += tabSpace[1] + "for(it = " + vectorname + ".begin();\n";
//         fileData += tabSpace[2] + "it != " + vectorname + ".end(); it++ ) {\n";
//         fileData += tabSpace[2] + "if (*it == this->m_frontid) break;     \n";
//         fileData += tabSpace[1] + "}\n";
//         fileData += tabSpace[1] + "if (it == " + vectorname + ".end()) {\n";
//         fileData += tabSpace[2] +  vectorname + ".push_back(this->m_frontid);\n";
//         fileData += tabSpace[1] + "}\n";
//         fileData += tabSpace[1] + queueName + "[this->m_frontid].push ((void**)&paramArray[0]);\n";
//         fileData += tabSpace[1] + "uv_mutex_unlock (&" + mutexName + ");\n\n";
//         fileData += tabSpace[1] + "uv_async_send(&" + asyncName+");\n";
        
//         fileData += tabSpace[1] + "OutputCallbackMessage(\"****** SysUserSpi:: "+ funcName + ": END! ******\\n\", g_RunningResult_File);\n";
        
//         fileData += "}\n\n";                
//     }
// }

//         fileData += hereDoc(function () {/*
//     Nan::Persistent<v8::Object>* pSpiObj = new Nan::Persistent<v8::Object>;
//     if (NULL == pSpiObj) {
//         OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pSpiObj", g_RunningResult_File);
//         OutputCallbackMessage("****** SysUserSpi:: OnFrontConnected: END! ******\n", g_RunningResult_File);
//         return;        
//     }           
//     memcpy(pSpiObj, &(this->m_spiobj), sizeof(Nan::Persistent<v8::Object>));
          
// */});

// 			fileData += hereDoc(function(){/*
// 	CShfeFtdcRspInfoField* pRspInfoNew = NULL;
//     if (NULL != pRspInfo){        
//         pRspInfoNew = new CShfeFtdcRspInfoField;        
//         if (NULL == pRspInfo) {
//             OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pRspInfo", g_RunningResult_File);
//             return;            
//         }        
//         memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));        
//     }	
	
//     int*  pId = new int(nRequestID);
//     if (NULL == pId) {
//         OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pId", g_RunningResult_File);
//         return;
//     }
    
//     bool* bIsLastNew = new bool(bIsLast);
//     if (NULL == bIsLastNew) {
//         OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for bIsLastNew", g_RunningResult_File);
//         return;
//     }  	
// */
//             });	
