var fs = require('fs');
var hereDoc = require('../lib/tool-function.js').hereDoc;
var ftdContent = require("../lib/FTD.json");
var sysContent = require("../lib/sysuserapi.json");

var ftdFuncs = ftdContent.FTD.packages[0].package;
var ftdField = ftdContent.FTD.fields[0].fieldDefine;
var sysFuncs = sysContent.sysuserapi.ftdpackage;
var tabSpace = ["","    ", "        ", "            ", "                ","                    "];

var fileData = hereDoc(function () {
/*#include "v8-transform-data.h"
#include "v8-transform-func.h"
#include "FtdcSysUserApiStruct.h"
#include "tool-function.h"
#include "id-func.h"
#include <fstream>
#include <queue>
#include <map>
#include <vector>
#include <iostream>
using std::queue;
using std::map;
using std::vector;
using std::fstream;
using std::cin;
using std::cout;
using std::endl;
using std::dec;	


using namespace v8;

#ifdef linux
#include "charset-convert-linux.h"
#endif

#ifdef __WINDOWS_
#include "charset-convert-windows.h"
#endif

#ifdef _WIN32
#include "charset-convert-windows.h"
#endif

extern fstream g_RunningResult_File;
*/});

fileData += hereDoc(function(){/*
void OnFrontConnected(uv_async_t *handle)
{   
    OutputCallbackMessage ("\n****** v8-transform-func:: OnFrontConnected: START! ******", g_RunningResult_File);
    uv_mutex_lock(&g_FrontConnected_mutex);
    
    int ioUserNumb = g_FrontConnected_IOUser_vec.size();
    queue<void**>* pReceivedData = new queue<void**>[ioUserNumb];
    
    if (NULL == pReceivedData) {
          OutputCallbackMessage ("v8-transform-func::pReceivedData is NULL", g_RunningResult_File);
          OutputCallbackMessage ("****** v8-transform-func:: OnFrontConnected: END! ******\n", g_RunningResult_File);
          return;       
    }
     
    int i = 0;
    for(vector<FRONT_ID>::iterator it = g_FrontConnected_IOUser_vec.begin();
        it != g_FrontConnected_IOUser_vec.end(); it++ , i++) {
        int dataNumb = g_FrontConnected_Data_map[*it].size();
        OutputCallbackMessage("dataNumb in this queue is: ",  dataNumb, g_RunningResult_File);        
        while (!g_FrontConnected_Data_map[*it].empty()) {
            pReceivedData[i].push(g_FrontConnected_Data_map[*it].front());
            g_FrontConnected_Data_map[*it].pop();
        }
    }
    g_FrontConnected_IOUser_vec.clear();
    
    uv_mutex_unlock(&g_FrontConnected_mutex);
    
    for (int i = 0; i < ioUserNumb; ++i) {
        while ( !pReceivedData[i].empty() ) { 
            void** paramArray = pReceivedData[i].front();
            pReceivedData[i].pop();
        
            if (NULL == paramArray ) {
                OutputCallbackMessage ("v8-transform-func::Delivered OnFrontConnected paramArray is NULL", g_RunningResult_File);
                OutputCallbackMessage ("****** v8-transform-func:: OnFrontConnected: END! ******\n", g_RunningResult_File);
                return;
            }
        
            Nan::HandleScope scope;
            Nan::Persistent<v8::Object>* pSpiObj = (Nan::Persistent<v8::Object>*)paramArray[0];
        
            if (pSpiObj->IsEmpty()) {
                OutputCallbackMessage ("v8-transform-func::pSpiObj is NULL", g_RunningResult_File);
                OutputCallbackMessage ("****** v8-transform-func:: OnFrontConnected: END! ******\n", g_RunningResult_File);
                return;
            }
            
            v8::Local<v8::Object> localSpiObj = Nan::New<v8::Object>(*pSpiObj);
            v8::Local<v8::Value> OnFrontConnected = localSpiObj->Get(Nan::New<v8::String>("OnFrontConnected").ToLocalChecked());
            if(OnFrontConnected->IsFunction())
            {
                v8::Local<v8::Function> function=v8::Local<v8::Function>::Cast(OnFrontConnected);
                Nan::Callback callback(function);
                callback.Call(localSpiObj, 0, 0);
            } else {
                cout << "OnFrontConnected is not function!" << endl;
                OutputCallbackMessage ("OnFrontConnected is not function!", g_RunningResult_File);
            }
        
            if(NULL != pSpiObj) {
                delete pSpiObj;
                pSpiObj = NULL;
            }            
        }                    
    }
    
    if (NULL != pReceivedData) {
        delete[] pReceivedData;
        pReceivedData = NULL;
    }

    OutputCallbackMessage ("****** v8-transform-func:: OnFrontConnected: END! ******\n", g_RunningResult_File);
}

void OnFrontDisconnected(uv_async_t *handle) {
    OutputCallbackMessage ("\n****** v8-transform-func:: OnFrontDisconnected: START! ******", g_RunningResult_File);
   
    uv_mutex_lock(&g_FrontDisconnected_mutex);
    int ioUserNumb = g_FrontDisconnected_IOUser_vec.size();
    queue<void**>* pReceivedData = new queue<void**>[ioUserNumb];
    
    if (NULL == pReceivedData) {
          OutputCallbackMessage ("v8-transform-func::pReceivedData is NULL", g_RunningResult_File);
          OutputCallbackMessage ("****** v8-transform-func:: OnFrontDisconnected: END! ******\n", g_RunningResult_File);
          return;       
    }
     
    int i = 0;
    for(vector<FRONT_ID>::iterator it = g_FrontDisconnected_IOUser_vec.begin();
        it != g_FrontDisconnected_IOUser_vec.end(); it++ , i++) {
        int dataNumb = g_FrontDisconnected_Data_map[*it].size();
        OutputCallbackMessage("dataNumb in this queue is: ",  dataNumb, g_RunningResult_File);        
        while (!g_FrontDisconnected_Data_map[*it].empty()) {
            pReceivedData[i].push(g_FrontDisconnected_Data_map[*it].front());
            g_FrontDisconnected_Data_map[*it].pop();
        }
        ReAllocateID(*it);
    }
    g_FrontDisconnected_IOUser_vec.clear();
    
    uv_mutex_unlock(&g_FrontDisconnected_mutex);
    
    for (int i = 0; i < ioUserNumb; ++i) {
        while ( !pReceivedData[i].empty() ) { 
            void** paramArray = pReceivedData[i].front();
            pReceivedData[i].pop();
            
            if (NULL == paramArray ) {
                OutputCallbackMessage ("v8-transform-func::Delivered OnFrontDisconnected paramArray is NULL", g_RunningResult_File);
                OutputCallbackMessage ("****** v8-transform-func:: OnFrontDisconnected: END! ******\n", g_RunningResult_File);
                return;
            }
        
            Nan::HandleScope scope;
            Nan::Persistent<v8::Object>* pSpiObj = (Nan::Persistent<v8::Object>*)paramArray[0];
            if (pSpiObj->IsEmpty()) {
                OutputCallbackMessage ("v8-transform-func::pSpiObj is NULL", g_RunningResult_File);
                OutputCallbackMessage ("****** v8-transform-func:: OnFrontDisconnected: END! ******\n", g_RunningResult_File);
                return;
            }
            
            v8::Local<v8::Object> localSpiObj = Nan::New<v8::Object>(*pSpiObj);
            v8::Local<v8::Value> OnFrontDisconnected = localSpiObj->Get(Nan::New<v8::String>("OnFrontDisconnected").ToLocalChecked());
            
            int* pnReason = (int*)paramArray[1];
            if(OnFrontDisconnected->IsFunction())
            {
                v8::Local<v8::Function> function=v8::Local<v8::Function>::Cast(OnFrontDisconnected);
                Nan::Callback callback(function);          
                
                v8::Local<v8::Integer> nReasonJS=Nan::New<v8::Integer>(*pnReason);
                v8::Local<v8::Value> param[1];
                param[0]=Local<v8::Value>(nReasonJS);
                    
                callback.Call(localSpiObj, 1, param);
            } else {
                OutputCallbackMessage ("OnFrontDisconnected is not function!", g_RunningResult_File);
            }
        
            if(NULL != pSpiObj) {
                delete pSpiObj;
                pSpiObj = NULL;
            }
            
            if (NULL != pnReason) {
                delete pnReason;
                pnReason = NULL;
            }
        
        }
            
    }
    
    if (NULL != pReceivedData) {
        delete[] pReceivedData;
        pReceivedData = NULL;
    }      
    
    OutputCallbackMessage ("****** v8-transform-func:: OnFrontDisconnected: END! ******\n", g_RunningResult_File);
}

void OnHeartBeatWarning(uv_async_t *handle)
{
    OutputCallbackMessage ("\n****** v8-transform-func:: OnHeartBeatWarning: START! ******", g_RunningResult_File);
    
    uv_mutex_lock(&g_HeartBeatWarning_mutex);
    int ioUserNumb = g_HeartBeatWarning_IOUser_vec.size();
    queue<void**>* pReceivedData = new queue<void**>[ioUserNumb];
    
    if (NULL == pReceivedData) {
          OutputCallbackMessage ("v8-transform-func::pReceivedData is NULL", g_RunningResult_File);
          OutputCallbackMessage ("****** v8-transform-func:: OnHeartBeatWarning: END! ******\n", g_RunningResult_File);
          return;       
    }
     
    int i = 0;
    for(vector<FRONT_ID>::iterator it = g_HeartBeatWarning_IOUser_vec.begin();
        it != g_HeartBeatWarning_IOUser_vec.end(); it++ , i++) {
        int dataNumb = g_HeartBeatWarning_Data_map[*it].size();
        OutputCallbackMessage("dataNumb in this queue is: ",  dataNumb, g_RunningResult_File);        
        while (!g_HeartBeatWarning_Data_map[*it].empty()) {
            pReceivedData[i].push(g_HeartBeatWarning_Data_map[*it].front());
            g_HeartBeatWarning_Data_map[*it].pop();
        }
    }
    g_HeartBeatWarning_IOUser_vec.clear();
    
    uv_mutex_unlock(&g_HeartBeatWarning_mutex);
    
    for (int i = 0; i < ioUserNumb; ++i) {
        while ( !pReceivedData[i].empty() ) { 
            void** paramArray = pReceivedData[i].front();
            pReceivedData[i].pop();       

            if (NULL == paramArray ) {
                OutputCallbackMessage ("v8-transform-func::Delivered OnHeartBeatWarning paramArray is NULL", g_RunningResult_File);
                OutputCallbackMessage ("****** v8-transform-func:: OnHeartBeatWarning: END! ******\n", g_RunningResult_File);
                return;
            }
        
            Nan::HandleScope scope;
            Nan::Persistent<v8::Object>* pSpiObj = (Nan::Persistent<v8::Object>*)paramArray[0];
            if (pSpiObj->IsEmpty()) {
                OutputCallbackMessage ("v8-transform-func::pSpiObj is NULL", g_RunningResult_File);
                OutputCallbackMessage ("****** v8-transform-func:: OnHeartBeatWarning: END! ******\n", g_RunningResult_File);
                return;
            }
            
            v8::Local<v8::Object> localSpiObj = Nan::New<v8::Object>(*pSpiObj);
            v8::Local<v8::Value> OnHeartBeatWarning = localSpiObj->Get(Nan::New<v8::String>("OnHeartBeatWarning").ToLocalChecked());
            
            int* pnTimeLapse = (int*)paramArray[1];
            if(OnHeartBeatWarning->IsFunction())
            {
                v8::Local<v8::Function> function=v8::Local<v8::Function>::Cast(OnHeartBeatWarning);
                Nan::Callback callback(function);          
                
                v8::Local<v8::Integer> nTimeLapseJS=Nan::New<v8::Integer>(*pnTimeLapse);
                v8::Local<v8::Value> param[1];
                param[0]=Local<v8::Value>(nTimeLapseJS);
                    
                callback.Call(localSpiObj, 1, param);
            } else {
                OutputCallbackMessage ("localSpi OnHeartBeatWarning is not function!", g_RunningResult_File);
            }
        
            if(NULL != pSpiObj) {
                delete pSpiObj;
                pSpiObj = NULL;
            }
            
            if (NULL != pnTimeLapse) {
                delete pnTimeLapse;
                pnTimeLapse = NULL;
            }            
        }       
    }
    
    if (NULL != pReceivedData) {
        delete[] pReceivedData;
        pReceivedData = NULL;
    }
    
    OutputCallbackMessage ("****** v8-transform-func:: OnHeartBeatWarning: END! ******\n", g_RunningResult_File);   
}

*/});

for (var sysFuncsIndex = 0; sysFuncsIndex < sysFuncs.length; ++sysFuncsIndex) {
    var funcName = sysFuncs[sysFuncsIndex].$.name;
	var funcType = funcName.substring(0, 3);
    if (funcType === "Rsp" || funcType === "Rtn") {
        for (var ftdFuncsIndex = 0; ftdFuncsIndex < ftdFuncs.length; ++ftdFuncsIndex) {
            if (ftdFuncs[ftdFuncsIndex].$.name === funcName) {  
                var fieldName = ftdFuncs[ftdFuncsIndex].field[0].$.name;
                var mapName = 'g_' + funcName + '_Data_map';
                var mutexName = 'g_' + funcName + '_mutex';
                var vectorName = 'g_' + funcName + '_IOUser_vec';
                var valueTypeName  = "CShfeFtdc" + fieldName + "Field";
                var pValueName = "p" + fieldName;
                var varNumb = 0;
                var callbackNumbName = 'g_' + funcName + '_trans_callbackNumb';
                var dataNumbName = 'g_' + funcName + '_trans_dataNumb';
                
                if(funcType === "Rsp" || funcType === "Rtn"){
                    if (funcType === "Rsp") {
                        varNumb = 4;
                    } else {
                        varNumb = 1;
                    }

                    fileData += "void On" + funcName + " (uv_async_t *handle)" + " { \n";
                    fileData += tabSpace[1] + "OutputCallbackMessage(\"\\n****** v8-transform-func:: "+ funcName + ": START! ******\", g_RunningResult_File);\n";

                    // 从全局队列中提取数据， vector 存储forntID信息;
                    // map以map<FRONT_ID, queue<void**> >存储数据， queue<void**>记录当前线程的所有回调数据;
                    // 每次申请新的空间存储指向回调数据区域的指针。
                    fileData += tabSpace[1] + "queue<void**>* pReceivedData;" + "\n";
                    fileData += tabSpace[1] + "uv_mutex_lock (&" + mutexName + ");" + "\n\n"
                            + tabSpace[1] + "int ioUserNumb = " + vectorName + ".size();\n"
                            + tabSpace[1] + "pReceivedData = new queue<void**>[ioUserNumb];\n"
                            + tabSpace[1] + "int i = 0;\n"
                            + tabSpace[1] + "for(vector<FRONT_ID>::iterator it = " + vectorName + ".begin();\n"
                            + tabSpace[2] + "it != " + vectorName + ".end(); it++ , i++) {\n"
                            + tabSpace[2] + "int dataNumb = " + mapName + "[*it].size();\n"
                            + tabSpace[2] + "OutputCallbackMessage(\"dataNumb in this queue is: \",  dataNumb, g_RunningResult_File);\n"
                            + tabSpace[2] + "while (!" + mapName + "[*it].empty()) {" + "\n"
                            + tabSpace[3] + "pReceivedData[i].push (" + mapName + "[*it].front());" + "\n"
                            + tabSpace[3] +  mapName + "[*it].pop();" + "\n"
                            + tabSpace[2] + "}" + "\n"
                            + tabSpace[1] + "}" + "\n"
                            + tabSpace[1] + vectorName + ".clear();\n\n"
                            + tabSpace[1] + "uv_mutex_unlock (&" + mutexName + ");"  + "\n\n";
                    
                    fileData += tabSpace[1] + "for (int i = 0; i < ioUserNumb; ++i) {\n"          
                            + tabSpace[2] + "while ( !pReceivedData[i].empty() ) {"  + "\n"      
                            + tabSpace[3] + "void** paramArray = pReceivedData[i].front();" + "\n"
                            + tabSpace[3] + "pReceivedData[i].pop();" + "\n\n"
                            + tabSpace[3] + "if (NULL == paramArray ) {" + "\n"
                            + tabSpace[4] + "OutputCallbackMessage (\"v8-transform-func::Delivered " + funcName + " paramArray is NULL\", g_RunningResult_File);" + "\n"
                            + tabSpace[4] + "OutputCallbackMessage (\"****** v8-transform-func:: "+ funcName + ": END! ******\\n\", g_RunningResult_File);\n"
                            + tabSpace[4] + "return;" + "\n"
                            + tabSpace[3] + "}" + "\n";        
                
                    // 转换回调数据, C++ -->> V8;
                    // Rsp 回调数据有五个部分，Rtn回调数据有两个部分。
                    // 公共的部分是负责调用JS回调的SpiObj对象与传输查询信息的pfuncNameObj;
                    fileData += tabSpace[3] + "Nan::HandleScope scope; \n"
                            + tabSpace[3] + "Nan::Persistent<v8::Object>* pSpiObj = (Nan::Persistent<v8::Object>*)paramArray[0]; \n"
                            + tabSpace[3] + "if (pSpiObj->IsEmpty()) { \n"
                            + tabSpace[4] + "OutputCallbackMessage (\"v8-transform-func::pSpiObj is NULL\", g_RunningResult_File); \n"
                            + tabSpace[4] + "return; \n"
                            + tabSpace[3] + "} \n"
                            + tabSpace[3] + "v8::Local<v8::Object> localSpiObj = Nan::New<v8::Object>(*pSpiObj); \n"

                    fileData += tabSpace[3] + valueTypeName + "* " + pValueName + " = (" + valueTypeName+"*)(paramArray[1]);" + "\n"
                    if (funcType === "Rsp" ) {
                        fileData += tabSpace[3] + "CShfeFtdcRspInfoField *pRspInfo = (CShfeFtdcRspInfoField *)(paramArray[2]);" + "\n"
                                + tabSpace[3] + "int* pRequestID = (int*)paramArray[3];" + "\n"
                                + tabSpace[3] + "bool* pIsLastNew = (bool*)paramArray[4];" + "\n\n"
                    }
                    fileData += tabSpace[3] + "v8::Local<v8::Value> On" + funcName + " = localSpiObj->Get(Nan::New<v8::String>(\"On" + funcName + "\").ToLocalChecked());\n"	
                    fileData += tabSpace[3] + "if (On" + funcName + "->IsFunction()) {" + "\n";
                    fileData += tabSpace[4] + "v8::Local<v8::Function> function = v8::Local<v8::Function>::Cast(On" + funcName + ");" + "\n";
                    fileData += tabSpace[4] + "Nan::Callback callback(function);" + "\n\n";
                    
                    var pJsValueName = pValueName + "JS";
                    fileData += tabSpace[4] + "v8::Local<v8::Object> "+ pJsValueName +" = Nan::New<v8::Object>();\n";		
                    if (funcType === "Rsp") {
                        fileData += tabSpace[4] + "v8::Local<v8::Object> pRspInfoJS = Nan::New<v8::Object>();\n";
                        fileData += tabSpace[4] + "v8::Local<v8::Integer> nRequestIDJS = Nan::New<v8::Integer>(*pRequestID);\n";
                        fileData += tabSpace[4] + "v8::Local<v8::Boolean> nIsLastNewJS = Nan::New<v8::Boolean>(*pIsLastNew);\n";
                    }
                    fileData += tabSpace[4] + "\n";
                    fileData += tabSpace[4] + "if (NULL != " + pValueName + ") { \n";
                    fileData += tabSpace[5] + "string utf8string;\n";
                    
                    for(var fieldIndex = 0; fieldIndex < ftdField.length; fieldIndex++) {			
                        if ( ftdField[fieldIndex].$.name === fieldName) {
                            var itemlength = ftdField[fieldIndex].item.length;
                            
                            for(var itemIndex = 0; itemIndex < itemlength; itemIndex++) {

                                var itemName = ftdField[fieldIndex].item[itemIndex].$.name;
                                var itemType = ftdField[fieldIndex].item[itemIndex].$.type.substring(1, ftdField[fieldIndex].item[itemIndex].$.type.length - 4);

                                fileData += tabSpace[5] + "v8::Local<v8::String> " + itemName
                                        + " = Nan::New<v8::String> (\"" + itemName + "\").ToLocalChecked();" + "\n";

                                var itemValueName = itemName + "Value";
                                var IntTypeLength = ftdContent.FTD.types[0].Int.length;
                                var isString = true;

                                for(var w = 0; w < IntTypeLength; w++) {//Int ,int type
                                    if(itemType === ftdContent.FTD.types[0].Int[w].$.typename)
                                    {
                                        isString = false;
                                        fileData += tabSpace[5] + "v8::Local<v8::Integer> "+ itemValueName + " = Nan::New<v8::Integer> ("
                                                + pValueName + "->"+itemName+");\n";
                                        break;
                                    }
                                }
                                
                                var RangeIntLength = ftdContent.FTD.types[0].RangeInt.length;
                                for(var w = 0;w<RangeIntLength;w++){//RangeInt , int type
                                    if(itemType===ftdContent.FTD.types[0].RangeInt[w].$.typename)
                                    {
                                        isString = false;
                                        fileData +=  tabSpace[5] + "v8::Local<v8::Integer> "+ itemValueName + " = Nan::New<v8::Integer> ("
                                                + pValueName + "->"+itemName+");\n";
                                        break;
                                    }
                                }                    

                                var CharLength=ftdContent.FTD.types[0].Char.length;
                                for(var w=0;w<CharLength;w++){//Char , int type
                                    if(itemType===ftdContent.FTD.types[0].Char[w].$.typename)
                                    {
                                        isString = false;
                                        fileData += tabSpace[5] + "v8::Local<v8::Integer> "+ itemValueName + " = Nan::New<v8::Integer> ("
                                                + pValueName + "->"+itemName+");\n";
                                        break;
                                    }
                                }

                                var EnumCharLength=ftdContent.FTD.types[0].EnumChar.length;
                                for(var w=0;w<EnumCharLength;w++){//Enumchar , int type
                                    if(itemType===ftdContent.FTD.types[0].EnumChar[w].$.typename)
                                    {
                                        isString = false;
                                        fileData += tabSpace[5] + "v8::Local<v8::Integer> "+ itemValueName + " = Nan::New<v8::Integer> ("
                                                + pValueName + "->"+itemName+");\n";
                                        break;
                                    }
                                }

                                var WordLength=ftdContent.FTD.types[0].Word.length;
                                for(var w=0;w<WordLength;w++){//Word , int type
                                    if(itemType===ftdContent.FTD.types[0].Word[w].$.typename)
                                    {
                                        isString = false;
                                        fileData += tabSpace[5] + "v8::Local<v8::Integer> "+ itemValueName + " = Nan::New<v8::Integer> ("
                                                + pValueName + "->"+itemName+");\n";
                                        break;
                                    }
                                }
                                
                                var Floatlength=ftdContent.FTD.types[0].Float.length;
                                for(var w=0;w<Floatlength;w++){//Float , int type
                                    if(itemType===ftdContent.FTD.types[0].Float[w].$.typename)
                                    {
                                        isString = false;
                                        fileData += tabSpace[5] + "v8::Local<v8::Number> " + itemValueName + " = Nan::New<v8::Number> ("
                                                + pValueName + "->"+itemName+");\n";
                                        break;
                                    }
                                }
                                                    
                                var QWordLength = ftdContent.FTD.types[0].QWord.length;
                                for(var w=0;w<QWordLength;w++){ //QWord , int type
                                    if(itemType===ftdContent.FTD.types[0].QWord[w].$.typename)
                                    {
                                        isString = false;
                                        fileData += tabSpace[5] + "v8::Local<v8::Number> " + itemValueName+ " = Nan::New<v8::Number> ("
                                                + pValueName + "->"+itemName+");\n";
                                        break;
                                    }
                                }

                                var fixNumberLength=ftdContent.FTD.types[0].FixNumber.length;
                                for(var w=0;w<fixNumberLength;w++){//FixNumber , int type
                                    if(itemType === ftdContent.FTD.types[0].FixNumber[w].$.typename)
                                    {
                                        isString = false;
                                        fileData += tabSpace[5] + "v8::Local<v8::Number> " + itemValueName + " = Nan::New<v8::Number> ("
                                                + pValueName + "->"+itemName+");\n";
                                        break;
                                    }
                                }
                                
                                if(isString === true) {//String、Array、VString , string type
                                                            
                                    fileData += tabSpace[5] + "Gb2312ToUtf8("+ pValueName + "->"+itemName +", utf8string);\n"
                                            + tabSpace[5] + "v8::Local<v8::String> "+ itemValueName + " = Nan::New<v8::String> (utf8string.c_str()).ToLocalChecked();\n";
                                }
                                // 绑定JS value;
                                fileData += tabSpace[5] + pJsValueName + "->Set(Local<v8::Value> ("+itemName+"), Local<v8::Value>("+itemValueName+"));\n\n";
                            }
                        }
                    }        
                    fileData += tabSpace[4] + "}\n"
                    
                    if (funcType =="Rsp") {	
                        fileData += tabSpace[4] + "if (NULL != pRspInfo) { \n"
                                + tabSpace[5] + "string utf8string; \n"
                                + tabSpace[5] + "v8::Local<v8::String>  ErrorID = Nan::New<v8::String>(\"ErrorID\").ToLocalChecked(); \n"
                                + tabSpace[5] + "v8::Local<v8::Integer> ErrorIDValue = Nan::New<v8::Integer>(pRspInfo->ErrorID); \n"
                                + tabSpace[5] + "pRspInfoJS->Set(Local<v8::Value>(ErrorID),Local<v8::Value>(ErrorIDValue)); \n\n"
                                + tabSpace[5] + "v8::Local<v8::String>  ErrorMsg = Nan::New<v8::String>(\"ErrorMsg\").ToLocalChecked(); \n"
                                + tabSpace[5] + "Gb2312ToUtf8(pRspInfo->ErrorMsg, utf8string); \n"
                                + tabSpace[5] + "v8::Local<v8::String>  ErrorMsggValue = Nan::New(utf8string.c_str()).ToLocalChecked(); \n"
                                + tabSpace[5] + "pRspInfoJS->Set(Local<v8::Value>(ErrorMsg),Local<v8::Value>(ErrorMsggValue)); \n"
                                + tabSpace[4] + "} \n\n"
                    }		
                        
                    // 设置JS回调参数;
                    if (funcType =="Rsp") {
                        fileData += tabSpace[4] + "v8::Local<v8::Value> params[4];" + "\n";
                    } else {
                        fileData += tabSpace[4] + "v8::Local<v8::Value> params[1];" + "\n";
                    }
                    
                    fileData += tabSpace[4] + "if (NULL != " + pValueName + ") { \n"
                            + tabSpace[5] + "params[0] = Local<v8::Value>(" + pJsValueName + ");\n"
                            + tabSpace[4] + "} else { \n"
                            + tabSpace[5] + "params[0] = Local<v8::Value>(Nan::Undefined());\n"
                            + tabSpace[4] + "};\n"
                    
                    if ("Rsp" === funcType) {
                        fileData += tabSpace[4] + "if (NULL != pRspInfo) { \n"
                                + tabSpace[5] + "params[1] = Local<v8::Value>(pRspInfoJS); \n"
                                + tabSpace[4] + "} else { \n"
                                + tabSpace[5] + "params[1] = Local<v8::Value>(Nan::Undefined()); \n"
                                + tabSpace[4] + "}\n"
                                + tabSpace[4] + "params[2] = Local<v8::Value>(nRequestIDJS); \n"
                                + tabSpace[4] + "params[3] = Local<v8::Value>(nIsLastNewJS); \n\n"
                                + tabSpace[4] + "callback.Call(localSpiObj, 4, params); \n"
                                + tabSpace[3] + "} \n"           
                    } else {
                        fileData += tabSpace[4] + "callback.Call(localSpiObj, 1, params); \n"
                                + tabSpace[3] + "} \n\n"
                    }
                    
                    // 释放资源;
                    fileData += tabSpace[3] + "if(NULL != pSpiObj) { \n"
                            + tabSpace[4] + "delete pSpiObj; \n"
                            + tabSpace[4] + "pSpiObj = NULL; \n"
                            + tabSpace[3] + "} \n"

                    fileData += tabSpace[3] + "if (NULL != "+ pValueName +") { \n"
                            + tabSpace[4] + "delete " + pValueName + "; \n"
                            + tabSpace[4] + pValueName + " = NULL; \n"
                            + tabSpace[3] + "} \n"
                    
                    if ("Rsp" === funcType) {
                        fileData += tabSpace[3] + "if (NULL != pRspInfo) { \n"
                                + tabSpace[4] + "delete pRspInfo; \n"
                                + tabSpace[4] + "pRspInfo = NULL; \n"
                                + tabSpace[3] + "} \n"
                                + tabSpace[3] + "if (NULL != pRequestID) { \n"
                                + tabSpace[4] + "delete pRequestID; \n"
                                + tabSpace[4] + "pRequestID = NULL; \n"
                                + tabSpace[3] + "} \n"
                                + tabSpace[3] + "if (NULL != pIsLastNew) {\n"
                                + tabSpace[4] + "delete pIsLastNew; \n"
                                + tabSpace[3] + "pIsLastNew = NULL; \n"
                                + tabSpace[3] + "} \n"
                    }	
                        
                    fileData += tabSpace[3] + "if (NULL != paramArray) { \n"
                            + tabSpace[4] + "delete []paramArray; \n"
                            + tabSpace[4] + "paramArray = NULL; \n"
                            + tabSpace[3] + "} \n"
                            + tabSpace[2] + "} \n"
                            + tabSpace[1] + "} \n"
                            + tabSpace[1] + "if (NULL != pReceivedData) { \n"
                            + tabSpace[2] + "delete[] pReceivedData; \n"
                            + tabSpace[2] + "pReceivedData = NULL; \n"
                            + tabSpace[1] + "} \n\n"
                
                    fileData += tabSpace[1] + "OutputCallbackMessage(\"****** v8-transform-func:: "+ funcName + ": END! ******\\n\", g_RunningResult_File);\n";
                    fileData += "}\n\n";
                }  // end if ("Rsp" || "Rtn")
            }
        }
    }
} // end for


var pathName = '../new-file/';
var fileName = 'v8-transform-func.cpp';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {
        console.log('Succeed in saving ' + pathName + fileName);
    }

});

        // fileData += tabSpace[5] + "const int utf8dataLen = 4096 * 12;\n";
        // fileData += tabSpace[5] + "int gb2312dataLen;\n"
        // fileData += tabSpace[5] + "char utf8data[utf8dataLen];\n\n";

                                //  fileData += tabSpace[5] + "gb2312dataLen = strlen("+ pValueName + "->"+itemName +");\n";
                        //  fileData += tabSpace[5] + "Gb2312ToUtf8("+ pValueName + "->"+itemName +", gb2312dataLen, utf8data, utf8dataLen);\n";
                        //  fileData += tabSpace[5] + "v8::Local<v8::String> "+ itemValueName 
                        //                          + " = Nan::New<v8::String> (utf8data).ToLocalChecked();\n";

            // fileData += hereDoc(function(){/*
            //     callback.Call(localSpiObj, 1, params);
                
            // } // OnFrontConnected->IsFunction() end!*/});   

            
			// fileData += hereDoc(function(){/*
            //     if (NULL != pRspInfo) {
            //         params[1] = Local<v8::Value>(pRspInfoJS);
            //     } else {
            //         params[1] = Local<v8::Value>(Nan::Undefined());
            //     }
            //     params[2] = Local<v8::Value>(nRequestIDJS);
            //     params[3] = Local<v8::Value>(nIsLastNewJS);
                
            //     callback.Call(localSpiObj, 4, params);

            // } // OnFrontConnected->IsFunction() end!*/ });         