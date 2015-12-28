/**
 * Created by li.xiankui on 2015/8/25.
 */

var fs = require('fs');
function hereDoc(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}
var fileData = hereDoc(function () {
/*#include "spi-transform.h"
#include "FtdcSysUserApiStruct.h"
#include "tool-function.h"
#include "charset-convert.h"
using namespace v8;

// 添加对 queue， mutex, async 全局变量的定义

fstream g_RunningResult_File;
Nan::Persistent<v8::Object> SpiObj;

uv_async_t    g_FrontConnected_async;

queue<int>    g_FrontDisconnected_queue;
uv_mutex_t    g_FrontDisconnected_mutex;
uv_async_t    g_FrontDisconnected_async;

queue<int>    g_HeartBeatWarning_queue;
uv_mutex_t    g_HeartBeatWarning_mutex;
uv_async_t    g_HeartBeatWarning_async;

//以下自动生成
*/});


// 定义queue， mutex, async 全局变量;
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
        fileData += 'queue<void**> ' + 'g_' + funcName + '_queue' + ';\n';
        fileData += 'uv_mutex_t    ' + 'g_' + funcName + '_mutex' + ';\n';
        fileData += 'uv_async_t    ' + 'g_' + funcName + '_async' + ';\n';
        fileData += 'int           ' + 'g_' + funcName + '_trans_callbackNumb = 0;\n'
        fileData += 'int           ' + 'g_' + funcName + '_trans_dataNumb     = 0;\n\n'
    }
}

fileData += '\n';

// 定义无法复用的 OnFrontConnected, OnFrontDisconnected, OnHeartBeatWarning;
fileData += hereDoc(function(){/*
void OnFrontConnected(uv_async_t *handle)
{   
    Nan::HandleScope scope;

    if(SpiObj.IsEmpty()){
        return;
    }

    v8::Local<v8::Object> localSpiObj = Nan::New<v8::Object>(SpiObj);
    v8::Local<v8::Value> OnFrontConnected = localSpiObj->Get(Nan::New<v8::String>("OnFrontConnected").ToLocalChecked());
    if(OnFrontConnected->IsFunction())
    {
        v8::Local<v8::Function> function=v8::Local<v8::Function>::Cast(OnFrontConnected);
        Nan::Callback callback(function);
        callback.Call(0, 0);
    }
}

void OnFrontDisconnected(uv_async_t *handle) {

    queue<int> receivedData;
    uv_mutex_lock(&g_FrontDisconnected_mutex);
    while (!g_FrontDisconnected_queue.empty()) {
      receivedData.push(g_FrontDisconnected_queue.front());
      g_FrontDisconnected_queue.pop();
    }
    uv_mutex_unlock(&g_FrontDisconnected_mutex);

    while( !receivedData.empty() ) {
        int nReason = receivedData.front();
        receivedData.pop();

        v8::Local<v8::Object> localSpiObj = Nan::New<v8::Object>(SpiObj);
        v8::Local<v8::Value> OnFrontConnected = localSpiObj->Get(Nan::New<v8::String>("OnRspQryTopCpuInfoTopic").ToLocalChecked());

        if(!OnFrontConnected->IsFunction()){
            OutputCallbackMessage("Disconnect reason: ", nReason, g_RunningResult_File);
            v8::Local<v8::Function> function=v8::Local<v8::Function>::Cast(OnFrontConnected);
            Nan::Callback callback(function);
            int nReason=(int)handle->data;
            v8::Local<v8::Integer> nReasonJS=Nan::New<v8::Integer>(nReason);
            v8::Local<v8::Value> param[1];
            param[0]=Local<v8::Value>(nReasonJS);
            callback.Call(1, param);
        }
    }
}

void OnHeartBeatWarning(uv_async_t *handle)
{
    queue<int> receivedData;
    uv_mutex_lock(&g_HeartBeatWarning_mutex);
    while (!g_HeartBeatWarning_queue.empty()) {
      receivedData.push(g_HeartBeatWarning_queue.front());
      g_HeartBeatWarning_queue.pop();
    }
    uv_mutex_unlock(&g_HeartBeatWarning_mutex);

    while( !receivedData.empty() ) {
        int nTimeLapse = receivedData.front();
        receivedData.pop();

        v8::Local<v8::Object> localSpiObj = Nan::New<v8::Object>(SpiObj);
        v8::Local<v8::Value> OnFrontConnected = localSpiObj->Get(Nan::New<v8::String>("OnRspQryTopCpuInfoTopic").ToLocalChecked());

        if(OnFrontConnected->IsFunction()){
                v8::Local<v8::Function> function = v8::Local<v8::Function>::Cast(OnFrontConnected);
                Nan::Callback callback(function);
                v8::Local<v8::Integer> nTimeLapseJS = Nan::New<v8::Integer>(nTimeLapse);
                v8::Local<v8::Value> param[1];
                param[0] = Local<v8::Value>(nTimeLapseJS);
                callback.Call(1, param);
         }
    }

}

 */});

var fieldLength = jsonContent.FTD.fields[0].fieldDefine.length;
var beforeRspQryTopCpuInfoTopic=0;
while(jsonContent.FTD.packages[0].package[beforeRspQryTopCpuInfoTopic].$.name!=="RspQryTopCpuInfoTopic"){
    beforeRspQryTopCpuInfoTopic++;
}
var AfterRtnNetNonPartyLinkInfoTopic=0;
while(jsonContent.FTD.packages[0].package[AfterRtnNetNonPartyLinkInfoTopic].$.name!=="RtnNetNonPartyLinkInfoTopic"){
    AfterRtnNetNonPartyLinkInfoTopic++;
}
AfterRtnNetNonPartyLinkInfoTopic++;

var tabSpace = ["","    ", "        ", "            ", "                ","                    "];

/**
 * Rsp 与 Rtn 回调的区别
 * Rsp 有四个参数, 所以在V8转换时要对paraArray[4](三个简洁参数)进行操作(赋值，释放空间);
 * Rtn 只有一个参数;
 *  */
for(var i = beforeRspQryTopCpuInfoTopic; i<AfterRtnNetNonPartyLinkInfoTopic; i++) {
    var fieldName = jsonContent.FTD.packages[0].package[i].field[0].$.name;
    var funcName  = jsonContent.FTD.packages[0].package[i].$.name;
    var funcType  = funcName.substring(0,3);
    var queueName = 'g_' + funcName + '_queue';
    var mutexName = 'g_' + funcName + '_mutex';
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

        fileData += "void On" + funcName + " (uv_async_t *handle)" + "\n";
        fileData += "{" + "\n";
        fileData += tabSpace[1] + "OutputCallbackMessage(\"\\n****** spi-transform:: "+ funcName + ": START! ******\", g_RunningResult_File);\n";
        fileData += tabSpace[1] + "OutputCallbackMessage(\""+ callbackNumbName+": \", "+callbackNumbName+"++, g_RunningResult_File);\n\n"
        fileData += tabSpace[1] + "// 将全局队列数据转存到 receivedData 进行处理;" + "\n";
        fileData += tabSpace[1] + "queue<void**> receivedData;" + "\n";
        fileData += tabSpace[1] + "uv_mutex_lock (&" + mutexName + ");" + "\n\n";
        fileData += tabSpace[1] + "int dataNumb = " + queueName + ".size();\n";
        fileData += tabSpace[1] + "OutputCallbackMessage(\"dataNumb in this queue is: \",  dataNumb, g_RunningResult_File);\n";
        fileData += tabSpace[1] + dataNumbName + " += dataNumb;\n";
        fileData += tabSpace[1] + "OutputCallbackMessage(\""+dataNumbName+": \", "+ dataNumbName +", g_RunningResult_File);\n\n";
        fileData += tabSpace[1] + "while (!" + queueName + ".empty()) {" + "\n";
        fileData += tabSpace[2] + "receivedData.push (" + queueName + ".front());" + "\n";
        fileData += tabSpace[2] + queueName + ".pop();" + "\n";
        fileData += tabSpace[1] + "}" + "\n";
        fileData += tabSpace[1] + "uv_mutex_unlock (&" + mutexName + ");"  + "\n\n";
        fileData += tabSpace[1] + "while ( !receivedData.empty() ) {"  + "\n";            // 数据处理部分;
        fileData += tabSpace[2] + "void** paramArray = receivedData.front();" + "\n";
        fileData += tabSpace[2] + "receivedData.pop();" + "\n\n";
        fileData += tabSpace[2] + "// 检测队列中的数据是否为空!" + "\n";
		
        fileData += tabSpace[2] + "if (NULL == paramArray ) {" + "\n";
        fileData += tabSpace[3] + "OutputCallbackMessage (\"spi-transform::Delivered " + funcName + " paramArray is NULL\", g_RunningResult_File);" + "\n";
        fileData += tabSpace[3] + "OutputCallbackMessage (\"****** spi-transform:: "+ funcName + ": END! ******\\n\", g_RunningResult_File);\n";        
        fileData += tabSpace[3] + "return;" + "\n";
        fileData += tabSpace[2] + "}" + "\n\n";        
        
        fileData += tabSpace[2] + "Nan::HandleScope scope;" + "\n";
		
        fileData += tabSpace[2] + "if (SpiObj.IsEmpty()) {" + "\n";
        fileData += tabSpace[3] + "OutputCallbackMessage (\"spi-transform::" + funcName + "SpiObi is Empty\", g_RunningResult_File);" + "\n";
        fileData += tabSpace[3] + "OutputCallbackMessage (\"****** spi-transform:: "+ funcName + ": END! ******\\n\", g_RunningResult_File);\n";
        fileData += tabSpace[3] + "return;" + "\n";
        fileData += tabSpace[2] + "}" + "\n\n";
		
        fileData += tabSpace[2] + "v8::Local<v8::Object> localSpiObj = Nan::New<v8::Object>(SpiObj);" + "\n";
        fileData += tabSpace[2] + "v8::Local<v8::Value> OnFrontConnected = localSpiObj->Get (Nan::New<v8::String> (\"On" + funcName +"\").ToLocalChecked());" + "\n\n";
		
        fileData += tabSpace[2] + "if (OnFrontConnected->IsFunction()) {" + "\n\n";
        fileData += tabSpace[3] + "v8::Local<v8::Function> function = v8::Local<v8::Function>::Cast(OnFrontConnected);" + "\n";
        fileData += tabSpace[3] + "Nan::Callback callback(function);" + "\n\n";

	    fileData += tabSpace[3] + valueTypeName + "* " + pValueName + " = (" + valueTypeName+"*)(paramArray[0]);" + "\n";
        if (funcType === "Rsp" ) {
            fileData += tabSpace[3] + "CShfeFtdcRspInfoField *pRspInfo = (CShfeFtdcRspInfoField *)(paramArray[1]);" + "\n";
            fileData += tabSpace[3] + "int nRequestID = *(int*)paramArray[2];" + "\n";
            fileData += tabSpace[3] + "bool nIsLastNew = *(bool*)paramArray[3];" + "\n\n";
		}
		
		var pJsValueName = pValueName + "JS";
		fileData += tabSpace[3] + "v8::Local<v8::Object> "+ pJsValueName +" = Nan::New<v8::Object>();\n";		
		if (funcType === "Rsp") {
			fileData += tabSpace[3] + "v8::Local<v8::Object> pRspInfoJS = Nan::New<v8::Object>();\n";
			fileData += tabSpace[3] + "v8::Local<v8::Integer> nRequestIDJS = Nan::New<v8::Integer>(nRequestID);\n";
			fileData += tabSpace[3] + "v8::Local<v8::Boolean> nIsLastNewJS = Nan::New<v8::Boolean>(nIsLastNew);\n";
		}
		fileData += tabSpace[3] + "\n";
        fileData += tabSpace[3] + "if (NULL != " + pValueName + ") { \n";
		fileData += tabSpace[4] + "string utf8string;\n";
         
        // 绑定p"+fieldName+"JS对象的属性和键值\n";
        for(var j = 0; j < fieldLength; j++) {			
            var tmpFieldDefine = jsonContent.FTD.fields[0].fieldDefine[j];
            if ( tmpFieldDefine.$.name === fieldName) {
                var itemlength = tmpFieldDefine.item.length;
                
                for(var k = 0; k < itemlength; k++) {

                    //获取每个field的item对象, itemType;
                    var itemName = tmpFieldDefine.item[k].$.name;
                    var itemType = tmpFieldDefine.item[k].$.type.substring(1, tmpFieldDefine.item[k].$.type.length - 4);

                    fileData += tabSpace[4] + "v8::Local<v8::String> " + itemName
                              + " = Nan::New<v8::String> (\"" + itemName + "\").ToLocalChecked();" + "\n";
                    /**
                     * 将itemType 与 V8 中的类型对应;
                     * 遍历给定的types ,如果itemType与某个相同边用V8中对应的类型进行转换;
                     * V8::Integer: Int, RangInt,
                     * V8::Number: QWord, FixNumber,
                     *  */

                    var itemValueName = itemName + "Value";

                    var IntTypeLength = jsonContent.FTD.types[0].Int.length;
                    var isString = true;

                    for(var w = 0; w < IntTypeLength; w++) {//Int ,int type
                        if(itemType === jsonContent.FTD.types[0].Int[w].$.typename)
                        {
                            isString = false;
                            fileData += tabSpace[4] + "v8::Local<v8::Integer> "+ itemValueName + " = Nan::New<v8::Integer> ("
                                      + pValueName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    
                    var RangeIntLength = jsonContent.FTD.types[0].RangeInt.length;
                    for(var w = 0;w<RangeIntLength;w++){//RangeInt , int type
                        if(itemType===jsonContent.FTD.types[0].RangeInt[w].$.typename)
                        {
                            isString = false;
                            fileData +=  tabSpace[4] + "v8::Local<v8::Integer> "+ itemValueName + " = Nan::New<v8::Integer> ("
                                      + pValueName + "->"+itemName+");\n";
                            break;
                        }
                    }                    

                    var CharLength=jsonContent.FTD.types[0].Char.length;
                    for(var w=0;w<CharLength;w++){//Char , int type
                        if(itemType===jsonContent.FTD.types[0].Char[w].$.typename)
                        {
                            isString = false;
                            fileData += tabSpace[4] + "v8::Local<v8::Integer> "+ itemValueName + " = Nan::New<v8::Integer> ("
                                      + pValueName + "->"+itemName+");\n";
                            break;
                        }
                    }

                    var EnumCharLength=jsonContent.FTD.types[0].EnumChar.length;
                    for(var w=0;w<EnumCharLength;w++){//Enumchar , int type
                        if(itemType===jsonContent.FTD.types[0].EnumChar[w].$.typename)
                        {
                            isString = false;
                            fileData += tabSpace[4] + "v8::Local<v8::Integer> "+ itemValueName + " = Nan::New<v8::Integer> ("
                                      + pValueName + "->"+itemName+");\n";
                            break;
                        }
                    }

                    var WordLength=jsonContent.FTD.types[0].Word.length;
                    for(var w=0;w<WordLength;w++){//Word , int type
                        if(itemType===jsonContent.FTD.types[0].Word[w].$.typename)
                        {
                            isString = false;
                            fileData += tabSpace[4] + "v8::Local<v8::Integer> "+ itemValueName + " = Nan::New<v8::Integer> ("
                                      + pValueName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    
                    var Floatlength=jsonContent.FTD.types[0].Float.length;
                    for(var w=0;w<Floatlength;w++){//Float , int type
                        if(itemType===jsonContent.FTD.types[0].Float[w].$.typename)
                        {
                            isString = false;
                            fileData += tabSpace[4] + "v8::Local<v8::Number> " + itemValueName + " = Nan::New<v8::Number> ("
                                      + pValueName + "->"+itemName+");\n";
                            break;
                        }
                    }
                                        
                    var QWordLength = jsonContent.FTD.types[0].QWord.length;
                    for(var w=0;w<QWordLength;w++){ //QWord , int type
                        if(itemType===jsonContent.FTD.types[0].QWord[w].$.typename)
                        {
                            isString = false;
                            fileData += tabSpace[4] + "v8::Local<v8::Number> " + itemValueName+ " = Nan::New<v8::Number> ("
                                      + pValueName + "->"+itemName+");\n";
                            break;
                        }
                    }

                    var fixNumberLength=jsonContent.FTD.types[0].FixNumber.length;
                    for(var w=0;w<fixNumberLength;w++){//FixNumber , int type
                        if(itemType === jsonContent.FTD.types[0].FixNumber[w].$.typename)
                        {
                            isString = false;
                            fileData += tabSpace[4] + "v8::Local<v8::Number> " + itemValueName + " = Nan::New<v8::Number> ("
                                      + pValueName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    
                    if(isString === true) {//String、Array、VString , string type
                    //     fileData += tabSpace[4] + "string& utf8string;\n";
                        fileData += tabSpace[4] + "Gb2312ToUtf8("+ pValueName + "->"+itemName +", utf8string);\n";
                        fileData += tabSpace[4] + "v8::Local<v8::String> "+ itemValueName + " = Nan::New<v8::String> (utf8string.c_str()).ToLocalChecked();\n";
                    }

                    // 绑定JS value;
                    fileData += tabSpace[4] + pJsValueName + "->Set(Local<v8::Value> ("+itemName+"), Local<v8::Value>("+itemValueName+"));\n\n";

                }
            }
        }
        
		fileData += tabSpace[3] + "};\n";
		
		if (funcType =="Rsp") {	
			fileData += hereDoc(function(){/*
			if (NULL != pRspInfo){
				v8::Local<v8::String>  ErrorID = Nan::New<v8::String>("ErrorID").ToLocalChecked();
				v8::Local<v8::Integer> ErrorIDValue = Nan::New<v8::Integer>(pRspInfo->ErrorID);
				pRspInfoJS->Set(Local<v8::Value>(ErrorID),Local<v8::Value>(ErrorIDValue));
					
				v8::Local<v8::String>  ErrorMsg = Nan::New<v8::String>("ErrorMsg").ToLocalChecked();
				v8::Local<v8::String>  ErrorMsggValue = Nan::New(pRspInfo->ErrorMsg).ToLocalChecked();                                
				pRspInfoJS->Set(Local<v8::Value>(ErrorMsg),Local<v8::Value>(ErrorMsggValue));
			}*/
				});
		}		
		fileData += tabSpace[3] + "\n\n";
			
		if (funcType =="Rsp") {
			fileData += tabSpace[3] + "v8::Local<v8::Value> params[4];" + "\n";
		} else {
			fileData += tabSpace[3] + "v8::Local<v8::Value> params[1];" + "\n";
		}
        
		fileData += tabSpace[3] + "if (NULL != " + pValueName + ") { \n";
		fileData += tabSpace[4] + "params[0] = Local<v8::Value>(" + pJsValueName + ");\n";
		fileData += tabSpace[3] + "} else { \n";
		fileData += tabSpace[4] + "params[0] = Local<v8::Value>(Nan::Undefined());\n";
		fileData += tabSpace[3] + "};\n";
		
		if ("Rsp" == funcType) {
			fileData += hereDoc(function(){/*
            if (NULL != pRspInfo) {
                params[1] = Local<v8::Value>(pRspInfoJS);
            } else {
                params[1] = Local<v8::Value>(Nan::Undefined());
            }
            params[2] = Local<v8::Value>(nRequestIDJS);
            params[3] = Local<v8::Value>(nIsLastNewJS);
			
            callback.Call(4, params);

        } // OnFrontConnected->IsFunction() end!

        for(int i = 0;i < 4; i++){
            if (NULL != paramArray[i]) {
                delete []paramArray[i];
                paramArray[i] = NULL;
            }
        }*/ });
		} else {
            fileData += hereDoc(function(){/*
			callback.Call(1, params);
			
        } // OnFrontConnected->IsFunction() end!

        for(int i = 0;i < 1; i ++){
            if (NULL != paramArray[i]) {
                delete []paramArray[i];
                paramArray[i] = NULL;
            }
        }*/});   

		}
		
        fileData += hereDoc(function(){/*
        if (NULL != paramArray) {
           delete []paramArray;
           paramArray = NULL;
        }       
    } // while() end!;
*/});      
        fileData += tabSpace[1] + "OutputCallbackMessage(\"****** spi-transform:: "+ funcName + ": END! ******\\n\", g_RunningResult_File);\n";
        fileData += "}\n\n";
    }  // end if ("Rsp" || "Rtn")
} // end for


var pathName = '../new file/';
var fileName = 'spi-transform.cpp';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {
        console.log('Succeed in saving ' + pathName + fileName);
    }

});
