/**
 * Created by li.xiankui on 2015/8/24.
 */
//生成FtdcSysUserApi_Wrapper.cc文件
var fs = require('fs');
function hereDoc(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}
var str = hereDoc(function () {/*
 #include "FtdcSysUserApi_Wrapper.h"
 #include <nan.h>
 #include "SysUserSpi.h"
 #include "SpiCFunc.h"
 #include "FtdcSysUserApiStruct.h"
 #include <iostream>
 #include <string.h>
 #include "CCrypto.h"

 using namespace v8;

 Nan::Persistent<Function> FtdcSysUserApi_Wrapper::constructor;

 FtdcSysUserApi_Wrapper::FtdcSysUserApi_Wrapper(const char *pszFlowPath)
 {
 _userApi=CShfeFtdcSysUserApi::CreateFtdcSysUserApi(pszFlowPath);
 _spi=new SysUserSpi();
 }

 FtdcSysUserApi_Wrapper::~FtdcSysUserApi_Wrapper() {
 _userApi->Release();
 delete _spi;
 uv_close((uv_handle_t*) &async, NULL);
 uv_close((uv_handle_t*) &asyncOnRspQrySysUserLoginTopic, NULL);
 }

 void FtdcSysUserApi_Wrapper::InitExports(Handle<Object> exports) {
 Nan::HandleScope scope;

 // Prepare constructor template
 Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
 tpl->SetClassName(Nan::New<v8::String>("FtdcSysUserApi_Wrapper").ToLocalChecked());
 tpl->InstanceTemplate()->SetInternalFieldCount(1);

 // Prototype
 //NODE_SET_PROTOTYPE_METHOD(tpl, "Init", Init);
 Nan::SetPrototypeMethod(tpl,"Release",Release);
 Nan::SetPrototypeMethod(tpl,"Init",Init);
 Nan::SetPrototypeMethod(tpl,"Join",Join);
 Nan::SetPrototypeMethod(tpl,"GetTradingDay",GetTradingDay);
 Nan::SetPrototypeMethod(tpl,"RegisterFront",RegisterFront);
 Nan::SetPrototypeMethod(tpl,"RegisterSpi",RegisterSpi);
 Nan::SetPrototypeMethod(tpl,"ReqQrySysUserLoginTopic",ReqQrySysUserLoginTopic);

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
var IntLength=jsonContent.FTD.types[0].Int.length;
var stringLength=jsonContent.FTD.types[0].String.length;
var vstringLength=jsonContent.FTD.types[0].VString.length;
var RangeIntLength=jsonContent.FTD.types[0].RangeInt.length;
var EnumCharLength=jsonContent.FTD.types[0].EnumChar.length;
var fixNumberLength=jsonContent.FTD.types[0].FixNumber.length;
var ArrayLength=jsonContent.FTD.types[0].Array.length;
var Floatlength=jsonContent.FTD.types[0].Float.length;
var CharLength=jsonContent.FTD.types[0].Char.length;
var WordLength=jsonContent.FTD.types[0].Word.length;
var QWordLength=jsonContent.FTD.types[0].QWord.length;
for(var i=beforeRspQryTopCpuInfoTopic;i<AfterRtnNetNonPartyLinkInfoTopic;i++) {
    var strName = jsonContent.FTD.packages[0].package[i].$.name;
    if (strName !== "ReqQrySysUserLoginTopic"&&strName.substring(0, 3) === "Req" &&
        strName.substring(strName.length - 5, strName.length) == "Topic" &&
        strName!=="ReqQryNetMemberSDHLineInfoTopic"&&
        strName!=="ReqQryVMInfoTopic"&&
        strName!=="ReqQryTradeDayChangeTopic"&&
        strName!=="ReqQryPropertyInfoTopic"&&strName!=="ReqQryMemPoolInfoTopic"&&
        strName!=="ReqQryFileContentInfoTopic"&&
        strName!=="ReqQryConnectionInfoTopic"&& strName!=="ReqQryConnectorInfoTopic"&&
        strName!=="ReqQryNetFuncAreaTopic"&& strName!=="ReqQryNetMonitorCommandTypeTopic"&&
        strName!=="ReqQryNetMonitorActionGroupTopic"&& strName!=="ReqQryNetEventExprTopic"&&
        strName!=="ReqQryNetEventTypeTopic"&& strName!=="ReqQryNetSubEventTypeTopic"&&
        strName!=="ReqQryNetEventLevelTopic"&& strName!=="ReqSysServerExitTopic"&&
        strName!=="ReqQryNetMonitorTaskInstAttrsTopic"&& strName!=="ReqQryNetBaseLineTaskTopic"&&
        strName!=="ReqQryNetMemberSDHLineInfoTopic"&& strName!=="ReqQryNetDDNLinkInfoTopic"&&
        strName!=="ReqQryNetPseudMemberLinkInfoTopic"&& strName!=="ReqQryOuterDeviceInfTopic"&&
        strName!=="ReqQrySysInternalTopologyTopic"&& strName!=="ReqQryMemberLinkCostTopic"&&
        strName!=="ReqQryNetPartylinkMonthlyRentTopic"&&str!="ReqQryClientLoginTopic"&&
        strName!=="ReqQryClientLoginTopic"&&strName!=="ReqQryCPUUsageTopic"&&
        strName!=="ReqQryMemoryUsageTopic"&&strName!=="ReqQryDiskUsageTopic"&&
        strName!=="ReqQryKeyFileInfoTopic"&&strName!=="ReqQryHostMonitorCfgTopic"&&
        strName!=="ReqQryAppMonitorCfgTopic"
        )
        str+=' Nan::SetPrototypeMethod(tpl,"'+jsonContent.FTD.packages[0].package[i].$.name+'",'+jsonContent.FTD.packages[0].package[i].$.name+');\n';
}
str+=hereDoc(function(){/*
 constructor.Reset(tpl->GetFunction());
 //NanAssignPersistent(constructor, tpl->GetFunction());
 exports->Set(Nan::New("FtdcSysUserApi_Wrapper").ToLocalChecked(), tpl->GetFunction());
}

NAN_METHOD(FtdcSysUserApi_Wrapper::New) {
    if (info.IsConstructCall()) {
        // Invoked as constructor: `new FtdcSysUserApi_Wrapper(...)`
        Local<String> str = info[0]->IsUndefined() ? Nan::EmptyString()  : info[0]->ToString();
        String::Utf8Value utf8Str(str);
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
}

NAN_METHOD(FtdcSysUserApi_Wrapper::Release) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    obj->_userApi->Release();
    info.GetReturnValue().SetUndefined();
}

NAN_METHOD(FtdcSysUserApi_Wrapper::Init) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    obj->_userApi->Init();
    info.GetReturnValue().SetUndefined();
}

NAN_METHOD(FtdcSysUserApi_Wrapper::Join) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    int result=obj->_userApi->Join();
    info.GetReturnValue().Set(Nan::New<v8::Int32>(result));
}

NAN_METHOD(FtdcSysUserApi_Wrapper::GetTradingDay) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    const char* result=obj->_userApi->GetTradingDay();
    info.GetReturnValue().Set(Nan::New<v8::String>(result).ToLocalChecked());
}

NAN_METHOD(FtdcSysUserApi_Wrapper::RegisterFront) {
    Local<String> str = info[0]->IsUndefined() ? Nan::EmptyString()  : info[0]->ToString();
    String::Utf8Value utf8Str(str);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());

    obj->_userApi->RegisterFront(*utf8Str);

    info.GetReturnValue().SetUndefined();
}

NAN_METHOD(FtdcSysUserApi_Wrapper::RegisterSpi) {
    std::cout<<"RegisterSpi Called!"<<std::endl;
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(info[0]->IsObject())
    {
        //obj->_spi=new SysUserSpi(Nan::To<v8::Object>(info[0]).ToLocalChecked());
        //obj->_userApi->RegisterSpi(obj->_spi);
        SpiObj.Reset(Nan::To<v8::Object>(info[0]).ToLocalChecked());
        obj->_userApi->RegisterSpi(obj->_spi);
    }
    info.GetReturnValue().SetUndefined();
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqUserLogin) {
     std::cout<<"ReqUserLogin Called!"<<std::endl;
     FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
     if(!(info[0]->IsObject() && info[1]->IsNumber()))
     {
     Nan::ThrowError("wrong parameter!");
     }
     //convert parameter one
     v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
     CShfeFtdcReqUserLoginField field;
     //TradingDay
     v8::Local<v8::Object> paramOneTradingDayObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TradingDay").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneTradingDayStr(Nan::To<v8::String>(paramOneTradingDayObj).ToLocalChecked());
     strcpy_s(field.TradingDay, 9, *paramOneTradingDayStr);
     //UserID
     v8::Local<v8::Object> paramOneUserIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneUserIDStr(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
     strcpy_s(field.UserID, 16, *paramOneUserIDStr);
     //ParticipantID
     v8::Local<v8::Object> paramOneParticipantIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ParticipantID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneParticipantIDStr(Nan::To<v8::String>(paramOneParticipantIDObj).ToLocalChecked());
     strcpy_s(field.ParticipantID, 11, *paramOneUserIDStr);
     //Password
     v8::Local<v8::Object> paramOnePasswordObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Password").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOnePasswordStr(Nan::To<v8::String>(paramOnePasswordObj).ToLocalChecked());
     strcpy_s(field.Password, 41, *paramOnePasswordStr);
     //convert parameter two
     v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
     int64_t nRequestID=paramTwo->Value();

     //call natvie method
     double returnValue= obj->_userApi->ReqUserLogin(&field, nRequestID);

     info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
     }
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQrySysUserLoginTopic) {
     std::cout<<"ReqQrySysUserLoginTopic Called!"<<std::endl;
     FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
     if(!(info[0]->IsObject() && info[1]->IsNumber()))
     {
     Nan::ThrowError("wrong parameter!");
     }
     //convert parameter one
     v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
     CShfeFtdcReqQrySysUserLoginField field;
     //UserID
     v8::Local<v8::Object> paramOneUserIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneUserIDStr(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
     strcpy_s(field.UserID, 16, *paramOneUserIDStr);
     std::cout<<*paramOneUserIDStr<<std::endl;
     //Password
     v8::Local<v8::Object> paramOnePasswordObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Password").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOnePasswordStr(Nan::To<v8::String>(paramOnePasswordObj).ToLocalChecked());
     //encrypt password
     CDesEncryptAlgorithm DesEncrypt;
     DesEncrypt.SetPassword("monitor");
     char encryptedPassword[256] = {0};
     DesEncrypt.Encrypt(*paramOnePasswordStr, encryptedPassword);
     strcpy_s(field.Password, 41, encryptedPassword);
     std::cout<<encryptedPassword<<std::endl;
     //VersionID
     v8::Local<v8::Object> paramOneVersionIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("VersionID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneVersionIDStr(Nan::To<v8::String>(paramOneVersionIDObj).ToLocalChecked());
     strcpy_s(field.VersionID, 17, *paramOneVersionIDStr);
     std::cout<<*paramOneVersionIDStr<<std::endl;
     //convert parameter two
     v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
     int64_t nRequestID=paramTwo->Value();

     //call natvie method
     double returnValue= obj->_userApi->ReqQrySysUserLoginTopic(&field, nRequestID);

     info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
 }
*/
});
var NoneType=0;//测试无类型数量
for(var i=beforeRspQryTopCpuInfoTopic;i<AfterRtnNetNonPartyLinkInfoTopic;i++) {
    var strName = jsonContent.FTD.packages[0].package[i].$.name;
    if (strName !== "ReqQrySysUserLoginTopic"&&strName.substring(0, 3) === "Req" &&
        strName.substring(strName.length - 5, strName.length) == "Topic" &&
        strName!=="ReqQryNetMemberSDHLineInfoTopic"&&
        strName!=="ReqQryVMInfoTopic"&&
        strName!=="ReqQryTradeDayChangeTopic"&&
        strName!=="ReqQryPropertyInfoTopic"&&strName!=="ReqQryMemPoolInfoTopic"&&
        strName!=="ReqQryFileContentInfoTopic"&&
        strName!=="ReqQryConnectionInfoTopic"&& strName!=="ReqQryConnectorInfoTopic"&&
        strName!=="ReqQryNetFuncAreaTopic"&& strName!=="ReqQryNetMonitorCommandTypeTopic"&&
        strName!=="ReqQryNetMonitorActionGroupTopic"&& strName!=="ReqQryNetEventExprTopic"&&
        strName!=="ReqQryNetEventTypeTopic"&& strName!=="ReqQryNetSubEventTypeTopic"&&
        strName!=="ReqQryNetEventLevelTopic"&& strName!=="ReqSysServerExitTopic"&&
        strName!=="ReqQryNetMonitorTaskInstAttrsTopic"&& strName!=="ReqQryNetBaseLineTaskTopic"&&
        strName!=="ReqQryNetMemberSDHLineInfoTopic"&& strName!=="ReqQryNetDDNLinkInfoTopic"&&
        strName!=="ReqQryNetPseudMemberLinkInfoTopic"&& strName!=="ReqQryOuterDeviceInfTopic"&&
        strName!=="ReqQrySysInternalTopologyTopic"&& strName!=="ReqQryMemberLinkCostTopic"&&
        strName!=="ReqQryNetPartylinkMonthlyRentTopic"&&str!="ReqQryClientLoginTopic"&&
        strName!=="ReqQryClientLoginTopic"&&strName!=="ReqQryCPUUsageTopic"&&
        strName!=="ReqQryMemoryUsageTopic"&&strName!=="ReqQryDiskUsageTopic"&&
        strName!=="ReqQryKeyFileInfoTopic"&&strName!=="ReqQryHostMonitorCfgTopic"&&
        strName!=="ReqQryAppMonitorCfgTopic"
        ) {//取开头为Req结尾为Topic的package

        str += "NAN_METHOD(FtdcSysUserApi_Wrapper::" + jsonContent.FTD.packages[0].package[i].$.name + "){\n";
        str += '  std::cout<<"' + jsonContent.FTD.packages[0].package[i].$.name + ' Called!"<<std::endl;\n';
        str += "  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());\n";
        str += "  if(!(info[0]->IsObject() && info[1]->IsNumber()))\n";
        str += "  {\n";
        str += '   Nan::ThrowError("wrong parameter!");\n';
        str += "  }\n";
        str += "  //convert parameter one\n";
        str += "  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();\n";
        str += "  CShfeFtdc" + jsonContent.FTD.packages[0].package[i].field[0].$.name + "Field field;\n\n";
        var fieldDefineLength = jsonContent.FTD.fields[0].fieldDefine.length;
        for (var j = 0; j < fieldDefineLength; j++) {
            if (jsonContent.FTD.fields[0].fieldDefine[j].$.name === jsonContent.FTD.packages[0].package[i].field[0].$.name) {
                var itemLength = jsonContent.FTD.fields[0].fieldDefine[j].item.length;
                for (var k = 0; k < itemLength; k++) {
                    var itemName = jsonContent.FTD.fields[0].fieldDefine[j].item[k].$.name;
                    var itemType = jsonContent.FTD.fields[0].fieldDefine[j].item[k].$.type.substring(1, jsonContent.FTD.fields[0].fieldDefine[j].item[k].$.type.length - 4);
                    str += " //" + itemName + "\n";
                    var TypeLength = 0;

                    for (var w = 0; w < IntLength; w++) {
                        if (jsonContent.FTD.types[0].Int[w].$.typename === itemType) {
                            str += '  v8::Local<v8::Object> paramOne' + itemName +
                                'Obj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("' +
                                itemName + '").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();\n';
                            str += "  v8::Local<v8::Integer> paramOne" + itemName + "Str=Nan::To<v8::Integer>( paramOne"+itemName+"Obj).ToLocalChecked();\n";
                            str += "  field." + itemName + "=paramOne" + itemName + "Str->Value();\n\n";
                        }
                    }
                    for (var w = 0; w < stringLength; w++) {
                        if (jsonContent.FTD.types[0].String[w].$.typename === itemType) {
                            str += '  v8::Local<v8::Object> paramOne' + itemName +
                                'Obj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("' +
                                itemName + '").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();\n';
                            str += '  v8::String::Utf8Value paramOne' + itemName + 'Str(Nan::To<v8::String>(paramOne' + itemName +
                                'Obj).ToLocalChecked());\n';
                            TypeLength = jsonContent.FTD.types[0].String[w].$.length + 1;
                            str += "  strcpy_s(field." + itemName + "," + TypeLength + ",*paramOne" + itemName + "Str);\n\n";

                        }
                    }
                    for (var w = 0; w < vstringLength; w++) {
                        if (jsonContent.FTD.types[0].VString[w].$.typename === itemType) {
                            str += '  v8::Local<v8::Object> paramOne' + itemName +
                                'Obj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("' +
                                itemName + '").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();\n';
                            str += '  v8::String::Utf8Value paramOne' + itemName + 'Str(Nan::To<v8::String>(paramOne' + itemName +
                                'Obj).ToLocalChecked());\n';
                            TypeLength = jsonContent.FTD.types[0].VString[w].$.length + 1;
                            str += "  strcpy_s(field." + itemName + "," + TypeLength + ",*paramOne" + itemName + "Str);\n\n";

                        }
                    }

                    for (var w = 0; w < RangeIntLength; w++) {
                        if (jsonContent.FTD.types[0].RangeInt[w].$.typename === itemType) {
                            str += '  v8::Local<v8::Object> paramOne' + itemName +
                                'Obj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("' +
                                itemName + '").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();\n';
                            str += "  v8::Local<v8::Integer> paramOne" + itemName + "Str=Nan::To<v8::Integer>( paramOne"+itemName+"Obj).ToLocalChecked();\n";
                            str += "  field." + itemName + "=paramOne" + itemName + "Str->Value();\n\n";
                        }
                    }
                    for (var w = 0; w < EnumCharLength; w++) {
                        if (jsonContent.FTD.types[0].EnumChar[w].$.typename === itemType) {
                            str += '  v8::Local<v8::Object> paramOne' + itemName +
                                'Obj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("' +
                                itemName + '").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();\n';
                            str += "  v8::Local<v8::Integer> paramOne" + itemName + "Str=Nan::To<v8::Integer>( paramOne"+itemName+"Obj).ToLocalChecked();\n";
                            str += "  field." + itemName + "=paramOne" + itemName + "Str->Value()-48;\n\n";
                        }
                    }
                    for (var w = 0; w < fixNumberLength; w++) {
                        if (jsonContent.FTD.types[0].FixNumber[w].$.typename === itemType) {
                            str += '  v8::Local<v8::Object> paramOne' + itemName +
                                'Obj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("' +
                                itemName + '").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();\n';
                            str += "  v8::Local<v8::Number> paramOne" + itemName + "Str=Nan::To<v8::Number>( paramOne"+itemName+"Obj).ToLocalChecked();\n";
                            str += "  field." + itemName + "=paramOne" + itemName + "Str->Value();\n\n";
                        }
                    }
                    for (var w = 0; w < ArrayLength; w++) {
                        if (jsonContent.FTD.types[0].Array[w].$.typename === itemType) {
                            str += '  v8::Local<v8::Object> paramOne' + itemName +
                                'Obj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("' +
                                itemName + '").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();\n';
                            str += '  v8::String::Utf8Value paramOne' + itemName + 'Str(Nan::To<v8::String>(paramOne' + itemName +
                                'Obj).ToLocalChecked());\n';
                            TypeLength = jsonContent.FTD.types[0].Array[w].$.length + 1;
                            str += "  strcpy_s(field." + itemName + "," + TypeLength + ",*paramOne" + itemName + "Str);\n\n";
                        }
                    }
                    for (var w = 0; w < Floatlength; w++) {
                        if (jsonContent.FTD.types[0].Float[w].$.typename === itemType) {
                            str += '  v8::Local<v8::Object> paramOne' + itemName +
                                'Obj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("' +
                                itemName + '").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();\n';
                            str += "  v8::Local<v8::Number> paramOne" + itemName + "Str=Nan::To<v8::Number>( paramOne"+itemName+"Obj).ToLocalChecked();\n";
                            str += "  field." + itemName + "=paramOne" + itemName + "Str->Value();\n\n";
                        }
                    }
                    for (var w = 0; w < CharLength; w++) {
                        if (jsonContent.FTD.types[0].Char[w].$.typename === itemType) {
                            str += '  v8::Local<v8::Object> paramOne' + itemName +
                                'Obj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("' +
                                itemName + '").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();\n';
                            str += "  v8::Local<v8::Integer> paramOne" + itemName + "Str=Nan::To<v8::Integer>( paramOne"+itemName+"Obj).ToLocalChecked();\n";
                            str += "  field." + itemName + "=paramOne" + itemName + "Str->Value()-48;\n\n";
                        }
                    }
                    for (var w = 0; w < WordLength; w++) {
                        if (jsonContent.FTD.types[0].Word[w].$.typename === itemType) {
                            str += '  v8::Local<v8::Object> paramOne' + itemName +
                                'Obj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("' +
                                itemName + '").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();\n';
                            str += "  v8::Local<v8::Integer> paramOne" + itemName + "Str=Nan::To<v8::Integer>( paramOne"+itemName+"Obj).ToLocalChecked();\n";
                            str += "  field." + itemName + "=paramOne" + itemName + "Str->Value();\n\n";
                        }
                    }
                    for (var w = 0; w < QWordLength; w++) {
                        if (jsonContent.FTD.types[0].QWord[w].$.typename === itemType) {
                            str += '  v8::Local<v8::Object> paramOne' + itemName +
                                'Obj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("' +
                                itemName + '").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();\n';
                            str += "  v8::Local<v8::Integer> paramOne" + itemName + "Str=Nan::To<v8::Integer>( paramOne"+itemName+"Obj).ToLocalChecked();\n";
                            str += "  field." + itemName + "=paramOne" + itemName + "Str->Value();\n\n";
                        }
                    }
                   }

                    str += "  //convert parameter two\n";
                    str += "  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();\n";
                    str += "  int64_t nRequestID=paramTwo->Value();\n\n";
                    str += "  //call native method\n";
                    str += "  double returnValue= obj->_userApi->" + jsonContent.FTD.packages[0].package[i].$.name +
                        "(&field, nRequestID);\n\n";
                    str += "  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));\n";
                    str += "}\n";
                }//end name==
            }//end j
        }//end ="Req"

}

function getTypeLength(itemType){
//    var IntLength=jsonContent.FTD.types[0].Int.length;
//    var stringLength=jsonContent.FTD.types[0].String.length;
//    var vstringLength=jsonContent.FTD.types[0].VString.length;
//    var RangeIntLength=jsonContent.FTD.types[0].RangeInt.length;
//    var EnumCharLength=jsonContent.FTD.types[0].EnumChar.length;
//    var fixNumberLength=jsonContent.FTD.types[0].FixNumber.length;
//    var ArrayLength=jsonContent.FTD.types[0].Array.length;
//    var Floatlength=jsonContent.FTD.types[0].Float.length;
//    var CharLength=jsonContent.FTD.types[0].Char.length;
//    var WordLength=jsonContent.FTD.types[0].Word.length;
//    var QWordLength=jsonContent.FTD.types[0].QWord.length;
    for(var i=0;i<IntLength;i++) {
        if (jsonContent.FTD.types[0].Int[i].$.typename === itemType) {
          return 1;
        }
    }
    for(var i=0;i<stringLength;i++) {
        if (jsonContent.FTD.types[0].String[i].$.typename === itemType) {
            return jsonContent.FTD.types[0].String[i].$.length+1;
        }
    }
    for(var i=0;i<vstringLength;i++) {
        if (jsonContent.FTD.types[0].VString[i].$.typename === itemType) {
            return jsonContent.FTD.types[0].VString[i].$.length+1;
        }
    }

    for(var i=0;i<RangeIntLength;i++) {
        if (jsonContent.FTD.types[0].RangeInt[i].$.typename === itemType) {
            return jsonContent.FTD.types[0].RangeInt[i].$.length+1;
        }
    }
    for(var i=0;i<EnumCharLength;i++) {
        if (jsonContent.FTD.types[0].EnumChar[i].$.typename === itemType) {
            return 1;
        }
    }
    for(var i=0;i<fixNumberLength;i++) {
        if (jsonContent.FTD.types[0].FixNumber[i].$.typename === itemType) {
            return 1;
        }
    }
    for(var i=0;i<ArrayLength;i++) {
        if (jsonContent.FTD.types[0].Array[i].$.typename === itemType) {
            return jsonContent.FTD.types[0].Array[i].$.length+1;
        }
    }
    for(var i=0;i<Floatlength;i++) {
        if (jsonContent.FTD.types[0].Float[i].$.typename === itemType) {
            return 1;
        }
    }
    for(var i=0;i<CharLength;i++) {
        if (jsonContent.FTD.types[0].Char[i].$.typename === itemType) {
            return 1;
        }
    }
    for(var i=0;i<WordLength;i++) {
        if (jsonContent.FTD.types[0].Word[i].$.typename === itemType) {
            return 1;
        }
    }
    for(var i=0;i<QWordLength;i++) {
        if (jsonContent.FTD.types[0].QWord[i].$.typename === itemType) {
            return 1;
        }
    }
    NoneType++;
    return 100;

}
function getTypeLength(itemType){
    var IntLength=jsonContent.FTD.types[0].Int.length;
    var stringLength=jsonContent.FTD.types[0].String.length;
    var vstringLength=jsonContent.FTD.types[0].VString.length;
    var RangeIntLength=jsonContent.FTD.types[0].RangeInt.length;
    var EnumCharLength=jsonContent.FTD.types[0].EnumChar.length;
    var fixNumberLength=jsonContent.FTD.types[0].FixNumber.length;
    var ArrayLength=jsonContent.FTD.types[0].Array.length;
    var Floatlength=jsonContent.FTD.types[0].Float.length;
    var CharLength=jsonContent.FTD.types[0].Char.length;
    var WordLength=jsonContent.FTD.types[0].Word.length;
    var QWordLength=jsonContent.FTD.types[0].QWord.length;
    for(var i=0;i<IntLength;i++) {
        if (jsonContent.FTD.types[0].Int[i].$.typename === itemType) {
            return 1;
        }
    }
    for(var i=0;i<stringLength;i++) {
        if (jsonContent.FTD.types[0].String[i].$.typename === itemType) {
            return jsonContent.FTD.types[0].String[i].$.length+1;
        }
    }
    for(var i=0;i<vstringLength;i++) {
        if (jsonContent.FTD.types[0].VString[i].$.typename === itemType) {
            return jsonContent.FTD.types[0].VString[i].$.length+1;
        }
    }

    for(var i=0;i<RangeIntLength;i++) {
        if (jsonContent.FTD.types[0].RangeInt[i].$.typename === itemType) {
            return jsonContent.FTD.types[0].RangeInt[i].$.length+1;
        }
    }
    for(var i=0;i<EnumCharLength;i++) {
        if (jsonContent.FTD.types[0].EnumChar[i].$.typename === itemType) {
            return 1;
        }
    }
    for(var i=0;i<fixNumberLength;i++) {
        if (jsonContent.FTD.types[0].FixNumber[i].$.typename === itemType) {
            return 1;
        }
    }
    for(var i=0;i<ArrayLength;i++) {
        if (jsonContent.FTD.types[0].Array[i].$.typename === itemType) {
            return jsonContent.FTD.types[0].Array[i].$.length+1;
        }
    }
    for(var i=0;i<Floatlength;i++) {
        if (jsonContent.FTD.types[0].Float[i].$.typename === itemType) {
            return 1;
        }
    }
    for(var i=0;i<CharLength;i++) {
        if (jsonContent.FTD.types[0].Char[i].$.typename === itemType) {
            return 1;
        }
    }
    for(var i=0;i<WordLength;i++) {
        if (jsonContent.FTD.types[0].Word[i].$.typename === itemType) {
            return 1;
        }
    }
    for(var i=0;i<QWordLength;i++) {
        if (jsonContent.FTD.types[0].QWord[i].$.typename === itemType) {
            return 1;
        }
    }
    NoneType++;
    return 100;

}
fs.writeFile('../FtdcSysUserApi_Wrapper.cc', str, function (err) {
    if (err) throw err;
    console.log('It\'s saved!');
    console.log('package length is:'+Packagelength);
    console.log('Nonetype is:'+ NoneType);
});