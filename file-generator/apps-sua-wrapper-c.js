/**
 * Created by li.xiankui on 2015/8/24.
 */
//生成FtdcSysUserApi_Wrapper.cc文件
var fs = require('fs');
var hereDoc = require('../lib/tool-function.js').hereDoc;
var ftdContent = require("../lib/FTD.json");
var sysContent = require("../lib/sysuserapi.json");

var ftdFuncs = ftdContent.FTD.packages[0].package;
var ftdField = ftdContent.FTD.fields[0].fieldDefine;
var sysFuncs = sysContent.sysuserapi.ftdpackage;
var tabSpace = ["","    ", "        ", "            ", "                ","                    "];

// 添加文件头部信息;
var fileData= hereDoc(function () {
/*#include <nan.h>
#include "ftdcsysuserapi-wrapper.h"
#include "FtdcSysUserApiStruct.h"
#include "sysuserspi.h"
#include "tool-function.h"
#include "id-func.h"
#include "CCrypto.h"
#include <string.h>

using namespace v8;

extern fstream g_RunningResult_File;

Nan::Persistent<Function> FtdcSysUserApi_Wrapper::constructor;

FtdcSysUserApi_Wrapper::FtdcSysUserApi_Wrapper(const char *pszFlowPath)
{
    m_userApi = CShfeFtdcSysUserApi::CreateFtdcSysUserApi(pszFlowPath);
    m_spi = new SysUserSpi();
    if (NULL == m_spi) {
       OutputCallbackMessage("FtdcSysUserApi_Wrapper::FtdcSysUserApi_Wrapper:: m_spi is NULL", g_RunningResult_File);
       return;
    }
}

FtdcSysUserApi_Wrapper::~FtdcSysUserApi_Wrapper() {
    m_userApi->Release();
    
    if (NULL != m_spi) {
        delete m_spi;
        m_spi = NULL;
    }
    
    g_RunningResult_File.close();
}
*/
});
    

// 设置类型的原型链;
fileData += hereDoc(function(){
/*
void FtdcSysUserApi_Wrapper::InitExports(Handle<Object> exports) {
    Nan::HandleScope scope;

    // Prepare constructor template
    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
    tpl->SetClassName(Nan::New<v8::String>("FtdcSysUserApi_Wrapper").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    //NODE_SET_PROTOTYPE_METHOD(tpl, "Init", Init);
    Nan::SetPrototypeMethod(tpl,"Release",Release);
    Nan::SetPrototypeMethod(tpl,"Init",Init);
    Nan::SetPrototypeMethod(tpl,"Join",Join);
    Nan::SetPrototypeMethod(tpl,"GetTradingDay",GetTradingDay);
    Nan::SetPrototypeMethod(tpl,"RegisterFront",RegisterFront);
    Nan::SetPrototypeMethod(tpl,"RegisterSpi",RegisterSpi);
    Nan::SetPrototypeMethod(tpl,"ReqQrySysUserLoginTopic",ReqQrySysUserLoginTopic);

*/});

for (var i = 0; i < sysFuncs.length; ++i) {
    var funcName = sysFuncs[i].$.name;
	var funcType = funcName.substring(0, 3);
    if (funcType === "Req") {
        fileData += tabSpace[1] + 'Nan::SetPrototypeMethod(tpl,"'+ funcName +'",'+ funcName +');\n';
    }
}
fileData += tabSpace[1] + "constructor.Reset(tpl->GetFunction());\n"
          + tabSpace[1] + "exports->Set(Nan::New(\"FtdcSysUserApi_Wrapper\").ToLocalChecked(), tpl->GetFunction());\n"
          + "}\n";

fileData += hereDoc(function(){
/*
NAN_METHOD (FtdcSysUserApi_Wrapper::New) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: New: START! ******", g_RunningResult_File);
    if (info.IsConstructCall()) {
        // Invoked as constructor: `new FtdcSysUserApi_Wrapper(...)`
        Local<String> fileData= info[0]->IsUndefined() ? Nan::EmptyString()  : info[0]->ToString();
        String::Utf8Value utf8Str(fileData);
        FtdcSysUserApi_Wrapper* obj = new FtdcSysUserApi_Wrapper(*utf8Str);
        obj->Wrap(info.This());
        info.GetReturnValue().Set(info.This());
    } else {
        // Invoked as plain function `FtdcSysUserApi_Wrapper(...)`, turn into construct call.
        const int argc = 1;
        Local<Value> argv[argc] = { info[0] };
        Local<Function> cons = Nan::New<Function>(constructor);
        info.GetReturnValue().Set(cons->NewInstance(argc, argv));
    }
    OutputCallbackMessage("\n****** FtdApi-wrapper: New: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::Release) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    obj->m_userApi->Release();
    info.GetReturnValue().SetUndefined();
}

NAN_METHOD (FtdcSysUserApi_Wrapper::Init) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: Init: START! ******", g_RunningResult_File);
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    obj->m_userApi->Init();
    info.GetReturnValue().SetUndefined();
    OutputCallbackMessage("\n****** FtdApi-wrapper: Init: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::Join) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    int result=obj->m_userApi->Join();
    info.GetReturnValue().Set(Nan::New<v8::Int32>(result));
}

NAN_METHOD (FtdcSysUserApi_Wrapper::GetTradingDay) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    const char* result=obj->m_userApi->GetTradingDay();
    info.GetReturnValue().Set(Nan::New<v8::String>(result).ToLocalChecked());
}

NAN_METHOD (FtdcSysUserApi_Wrapper::RegisterFront) {
    Local<String> fileData= info[0]->IsUndefined() ? Nan::EmptyString()  : info[0]->ToString();
    String::Utf8Value utf8Str(fileData);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());

    obj->m_userApi->RegisterFront(*utf8Str);

    info.GetReturnValue().SetUndefined();
}

int g_idnumb = 0;
NAN_METHOD (FtdcSysUserApi_Wrapper::RegisterSpi) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: RegisterSpi: START! ******", g_RunningResult_File);
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(info[0]->IsObject())
    {
        //obj->m_spi=new SysUserSpi(Nan::To<v8::Object>(info[0]).ToLocalChecked());
        //obj->m_userApi->RegisterSpi(obj->m_spi);
        
        obj->m_spi->m_spiobj.Reset(Nan::To<v8::Object>(info[0]).ToLocalChecked());
        obj->m_spi->m_frontid = GetFrontID();
        obj->m_userApi->RegisterSpi(obj->m_spi);
    }
    info.GetReturnValue().SetUndefined();
    OutputCallbackMessage("\n****** FtdApi-wrapper: RegisterSpi: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqUserLogin) {
     std::cout<<"ReqUserLogin Called!"<<std::endl;
     FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
     if(!(info[0]->IsObject() && info[1]->IsNumber()))
     {
     Nan::ThrowError("wrong parameter!");
     }
     //convert parameter one
     v8::Local<v8::Object> paraValue=Nan::To<v8::Object>(info[0]).ToLocalChecked();
     CShfeFtdcReqUserLoginField field;
     //TradingDay
     v8::Local<v8::Object> paramOneTradingDayObj=Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("TradingDay").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneTradingDayStr(Nan::To<v8::String>(paramOneTradingDayObj).ToLocalChecked());
     // strcpy_s(field.TradingDay, 9, *paramOneTradingDayStr);
     strncpy(field.TradingDay, *paramOneTradingDayStr,9);
     //UserID
     v8::Local<v8::Object> paramOneUserIDObj=Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneUserIDStr(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
     // strcpy_s(field.UserID, 16, *paramOneUserIDStr);
     strncpy(field.UserID, *paramOneUserIDStr, 16);
     //ParticipantID
     v8::Local<v8::Object> paramOneParticipantIDObj=Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("ParticipantID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneParticipantIDStr(Nan::To<v8::String>(paramOneParticipantIDObj).ToLocalChecked());
     // strcpy_s(field.ParticipantID, 11, *paramOneUserIDStr);
     strncpy(field.ParticipantID, *paramOneUserIDStr, 11);
     //Password
     v8::Local<v8::Object> paramOnePasswordObj=Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("Password").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOnePasswordStr(Nan::To<v8::String>(paramOnePasswordObj).ToLocalChecked());
     // strcpy_s(field.Password, 41, *paramOnePasswordStr);
     strncpy(field.Password, *paramOnePasswordStr, 41);
     //convert parameter two
     v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
     int nRequestID = (int)paramTwo->Value();

     //call natvie method
     double returnValue= obj->m_userApi->ReqUserLogin(&field, nRequestID);

     info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
     
// NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQrySysUserLoginTopic) {
//      std::cout<<"ReqQrySysUserLoginTopic Called!"<<std::endl;
//      FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
//      if(!(info[0]->IsObject() && info[1]->IsNumber()))
//      {
//      Nan::ThrowError("wrong parameter!");
//      }

//      v8::Local<v8::Object> paraValue=Nan::To<v8::Object>(info[0]).ToLocalChecked();
//      CShfeFtdcReqQrySysUserLoginField field;

//      v8::Local<v8::Object> paramOneUserIDObj=Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
//      v8::String::Utf8Value paramOneUserIDStr(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
//      strncpy(field.UserID, *paramOneUserIDStr, 16);

//      v8::Local<v8::Object> paramOnePasswordObj=Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("Password").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
//      v8::String::Utf8Value paramOnePasswordStr(Nan::To<v8::String>(paramOnePasswordObj).ToLocalChecked());
//      CDesEncryptAlgorithm DesEncrypt;
//      DesEncrypt.SetPassword("monitor");
//      char encryptedPassword[256] = {0};
//      DesEncrypt.Encrypt(*paramOnePasswordStr, encryptedPassword);
//      strncpy(field.Password, encryptedPassword, 41);

//      v8::Local<v8::Object> paramOneVersionIDObj=Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("VersionID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
//      v8::String::Utf8Value paramOneVersionIDStr(Nan::To<v8::String>(paramOneVersionIDObj).ToLocalChecked());
//      strncpy(field.VersionID, *paramOneVersionIDStr, 17);

//      v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
//      int nRequestID=(int)paramTwo->Value();

//      double returnValue= obj->m_userApi->ReqQrySysUserLoginTopic(&field, nRequestID);

//      info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
// }

*/
});

var maxTypeLength = 0;
                
var NoneType=0;

for (var i = 0; i < sysFuncs.length; ++i) {
    var funcName = sysFuncs[i].$.name;
	var funcType = funcName.substring(0, 3);
    if (funcType === "Req") {
        for (var ftdFuncIndex = 0; ftdFuncIndex < ftdFuncs.length; ++ftdFuncIndex) {
            if (ftdFuncs[ftdFuncIndex].$.name === funcName) { 

                fileData+= "\nNAN_METHOD (FtdcSysUserApi_Wrapper::" + funcName + ") {\n"
                         + tabSpace[1] + "OutputCallbackMessage(\"\\n****** FtdApi-wrapper: "+ funcName + ": START! ******\", g_RunningResult_File);\n\n"
                         + tabSpace[1] + "FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());\n"
                         + tabSpace[1] + "if(!(info[0]->IsObject() && info[1]->IsNumber()))\n"
                         + tabSpace[1] + "{\n"
                         + tabSpace[2] + 'Nan::ThrowError("wrong parameter!");\n'
                         + tabSpace[1] + "}\n"

                fileData+= tabSpace[1] + "v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();\n"
                         + tabSpace[1] + "CShfeFtdc" + ftdFuncs[ftdFuncIndex].field[0].$.name + "Field field;\n\n"                

                for(var fieldIndex = 0; fieldIndex < ftdField.length; fieldIndex++) {	
                    if (ftdField[fieldIndex].$.name === ftdFuncs[ftdFuncIndex].field[0].$.name) {
                        for (var itemIndex = 0; itemIndex < ftdField[fieldIndex].item.length; itemIndex++) {
                            var itemName = ftdField[fieldIndex].item[itemIndex].$.name;
                            var itemType = ftdField[fieldIndex].item[itemIndex].$.type.substring(1, ftdField[fieldIndex].item[itemIndex].$.type.length - 4);
                            var itemClassType = getItemClassType(itemType); 
                            // console.log (itemType);
                            // console.log (itemClassType);
                            var itemDataName = itemName + "Data";
                            var itemObjName  = itemName + "Obj";

                            fileData += tabSpace[1] + 'v8::Local<v8::Object> ' + itemObjName + " = "
                                      + 'Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("'+ itemName +'").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();\n'
                            
                            if ("String" === itemClassType.Name) {
                                fileData += tabSpace[1] + 'v8::String::Utf8Value ' + itemDataName + '(Nan::To<v8::String>('+ itemObjName +').ToLocalChecked());\n'
                                          + tabSpace[1] + "strncpy(field." + itemName + ", *" + itemDataName + ", " + itemClassType.Length + ");\n\n"                             
                            } else {
                                fileData += tabSpace[1] + "v8::Local<v8::"+ itemClassType.Name +"> " + itemDataName + " = Nan::To<v8::"+ itemClassType.Name +">("+ itemObjName +").ToLocalChecked();\n"
                                          + tabSpace[1] + "field." + itemName + " = "+ itemDataName +"->Value();\n\n"
                            }                           
                        }
                        fileData+= tabSpace[1] + "v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();\n"
                                 + tabSpace[1] + "int nRequestID = (int)paramTwo->Value();\n\n"
                                 + tabSpace[1] + "double returnValue= obj->m_userApi->" + funcName + "(&field, nRequestID);\n\n"
                                 + tabSpace[1] + "info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));\n\n"
                                 + tabSpace[1] + "OutputCallbackMessage(\"\\n****** FtdApi-wrapper: "+ funcName + ": END! ******\", g_RunningResult_File);\n"
                                 + tabSpace[0] + "}\n"
                    }
                }
            }
        }
    }
}

// 类型对应规则:
// Int, RangeInt, EnumChar, Char, Word, QWord -->> Integer;
// FixNumber, Float -->> Number;
// String, VString, Array -->> String;
function getItemClassType (itemType) {
    var itemClassType = {};
    itemClassType.Name = "";
    itemClassType.Length = 0;

    for (var typeIndex = 0; typeIndex < ftdContent.FTD.types[0].Int.length; typeIndex++) {
        if (ftdContent.FTD.types[0].Int[typeIndex].$.typename === itemType) {
            itemClassType.Name = "Integer";
            return itemClassType;
        }
    }
    for (var typeIndex = 0; typeIndex < ftdContent.FTD.types[0].String.length; typeIndex++) {
        if (ftdContent.FTD.types[0].String[typeIndex].$.typename === itemType) {
            itemClassType.Length = parseInt(ftdContent.FTD.types[0].String[typeIndex].$.length) + 1;
            itemClassType.Name   = "String";
            return itemClassType;
        }
    }
    for (var typeIndex = 0; typeIndex < ftdContent.FTD.types[0].VString.length; typeIndex++) {
        if (ftdContent.FTD.types[0].VString[typeIndex].$.typename === itemType) {
            itemClassType.Length = parseInt(ftdContent.FTD.types[0].VString[typeIndex].$.length) + 1;
            itemClassType.Name   = "String";
            return itemClassType;
        }
    }
    for (var typeIndex = 0; typeIndex < ftdContent.FTD.types[0].RangeInt.length; typeIndex++) {
        if (ftdContent.FTD.types[0].RangeInt[typeIndex].$.typename === itemType) {
            itemClassType.Name = "Integer";
            return itemClassType;
        }
    }
    for (var typeIndex = 0; typeIndex < ftdContent.FTD.types[0].EnumChar.length; typeIndex++) {
        if (ftdContent.FTD.types[0].EnumChar[typeIndex].$.typename === itemType) {
            itemClassType.Name = "Integer";
            return itemClassType;
        }
    }
    for (var typeIndex = 0; typeIndex < ftdContent.FTD.types[0].FixNumber.length; typeIndex++) {
        if (ftdContent.FTD.types[0].FixNumber[typeIndex].$.typename === itemType) {
            itemClassType.Name = "Number";
            return itemClassType;
        }
    }
    for (var typeIndex = 0; typeIndex < ftdContent.FTD.types[0].Array.length; typeIndex++) {
        if (ftdContent.FTD.types[0].Array[typeIndex].$.typename === itemType) {
            itemClassType.Length = parseInt(ftdContent.FTD.types[0].Array[typeIndex].$.length) + 1;
            itemClassType.Name   = "String";
            return itemClassType;
        }
    }
    for (var typeIndex = 0; typeIndex < ftdContent.FTD.types[0].Float.length; typeIndex++) {
        if (ftdContent.FTD.types[0].Float[typeIndex].$.typename === itemType) {
            itemClassType.Name = "Number";
            return itemClassType;
        }
    }
    for (var typeIndex = 0; typeIndex < ftdContent.FTD.types[0].Char.length; typeIndex++) {
        if (ftdContent.FTD.types[0].Char[typeIndex].$.typename === itemType) {
            itemClassType.Name = "Integer";
            return itemClassType;
        }
    }
    for (var typeIndex = 0; typeIndex < ftdContent.FTD.types[0].Word.length; typeIndex++) {
        if (ftdContent.FTD.types[0].Word[typeIndex].$.typename === itemType) {
            itemClassType.Name = "Integer";
            return itemClassType;
        }
    }
    for (var typeIndex = 0; typeIndex < ftdContent.FTD.types[0].QWord.length; typeIndex++) {
        if (ftdContent.FTD.types[0].QWord[typeIndex].$.typename === itemType) {
            itemClassType.Name = "Integer";
            return itemClassType;
        }
    }    
}

var pathName = '../new-file/';
var fileName = 'ftdcsysuserapi-wrapper.cpp';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {
        console.log('Succeed in saving ' + pathName + fileName);
    }

});

function InitializeHeadInfo (fileData) {

}

function AddClassFunc (fileData) {

}

function AddPublicFunc (fileData) {

}

function AddAutoGeneFunc (fileData) {

}
