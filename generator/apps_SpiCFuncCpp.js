/**
 * Created by li.xiankui on 2015/8/25.
 */
// 在命令行中输入node aas_SpiCFuncCpp.js
//生成SpiCFunc.cc文件。
//结果比原文件多出一些。。
var fs = require('fs');
function hereDoc(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}
var str = hereDoc(function () {/*
 #include "SpiCFunc.h"
 #include "FtdcSysUserApiStruct.h"
 #include <iostream>
 using namespace v8;
 Nan::Persistent<v8::Object> SpiObj;
 uv_async_t async;
 uv_async_t asyncOnFrontDisconnected;
 uv_async_t asyncOnHeartBeatWarning;
 //以下自动生成
*/});
var jsonContent=require("./package.json");
var Packagelength=jsonContent.FTD.packages[0].package.length;
for(var i=0;i<Packagelength;i++){
    if(jsonContent.FTD.packages[0].package[i].$.name.substring(0,3)==="Rsp"||jsonContent.FTD.packages[0].package[i].$.name.substring(0,3)==="Rtn"){
        str+=" uv_async_t asyncOn"+jsonContent.FTD.packages[0].package[i].$.name+";\n";
    }
}
str+= hereDoc(function(){/*
void print_progress(uv_async_t *handle)
{
    Nan::HandleScope scope;

    if(SpiObj.IsEmpty())
    {
        return;
    }

    v8::Local<v8::Object> localSpiObj=Nan::New<v8::Object>(SpiObj);
    v8::Local<v8::Value> OnFrontConnected=localSpiObj->Get(Nan::New<v8::String>("OnFrontConnected").ToLocalChecked());
    if(OnFrontConnected->IsFunction())
    {
        v8::Local<v8::Function> function=v8::Local<v8::Function>::Cast(OnFrontConnected);
        Nan::Callback callback(function);
        callback.Call(0, 0);
    }
}
void OnFrontDisconnected(uv_async_t *handle)
 {
 v8::Local<v8::Object> localSpiObj=Nan::New<v8::Object>(SpiObj);
 v8::Local<v8::Value> OnFrontConnected=localSpiObj->Get(Nan::New<v8::String>("OnRspQryTopCpuInfoTopic").ToLocalChecked());
 if(!OnFrontConnected->IsFunction()){
        int nReason=(int)handle->data;
        std::cout<<" DisConnect reason:"<<nReason<<std::endl;

//        Nan::Callback callback(function);
//        int nReason=(int)handle->data;
//        v8::Local<v8::Integer> nReasonJS=Nan::New<v8::Integer>(nReason);
//        v8::Local<v8::Value> param[1];
//        param[0]=Local<v8::Value>(nReasonJS);
//        callback.Call(1, param);
    }
 }
 void OnHeartBeatWarning(uv_async_t *handle)
 {
   v8::Local<v8::Object> localSpiObj=Nan::New<v8::Object>(SpiObj);
   v8::Local<v8::Value> OnFrontConnected=localSpiObj->Get(Nan::New<v8::String>("OnRspQryTopCpuInfoTopic").ToLocalChecked());
   if(OnFrontConnected->IsFunction()){
        v8::Local<v8::Function> function=v8::Local<v8::Function>::Cast(OnFrontConnected);
        Nan::Callback callback(function);
        int nTimeLapse=(int)handle->data;
        v8::Local<v8::Integer> nTimeLapseJS=Nan::New<v8::Integer>(nTimeLapse);
        v8::Local<v8::Value> param[1];
        param[0]=Local<v8::Value>(nTimeLapseJS);
        callback.Call(1, param);
    }

}

 */});
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
        str+="void On"+jsonContent.FTD.packages[0].package[i].$.name+"(uv_async_t *handle)\n";
        str+="{\n";
        str+="    void**paramArrayNew=new void*[4];\n";
        str+="    paramArrayNew = (void**)handle->data;\n";
        str+="    Nan::HandleScope scope;\n";
        str+="    if(SpiObj.IsEmpty())\n";
        str+="    {\n";
        str+="      std::cout<<\" IsEmpty()\"<<std::endl;\n";
        str+="      return;\n";
        str+="    }\n";
        str+="    v8::Local<v8::Object> localSpiObj=Nan::New<v8::Object>(SpiObj);\n"
        str+="    v8::Local<v8::Value> OnFrontConnected=localSpiObj->Get(Nan::New<v8::String>(\"On"+jsonContent.FTD.packages[0].package[i].$.name+"\").ToLocalChecked());\n";
        str+="    if(OnFrontConnected->IsFunction())\n";
        str+="    {\n";
        str+="      v8::Local<v8::Function> function=v8::Local<v8::Function>::Cast(OnFrontConnected);\n";
        str+="      Nan::Callback callback(function); \n";
        str+="      CShfeFtdc"+fieldName+"Field *p"+fieldName+" =(CShfeFtdc"+
               fieldName+"Field *)(paramArrayNew[0]);\n";
        str+="      CShfeFtdcRspInfoField *pRspInfo =(CShfeFtdcRspInfoField *)(paramArrayNew[1]);\n";
        str+="      int nRequestID =*(int*)paramArrayNew[2];\n";
        str+="      bool nIsLastNew=*(bool*)paramArrayNew[3];\n";
        str+="      ///////////////////////////////////output message///////////////////////// \n";
        str+="      if(pRspInfo!=NULL){\n";
        str+="        std::cout<<\"ErrorMsg:\"<<pRspInfo->ErrorMsg<<std::endl; \n";
        str+="      }\n";
        str+="      else if(pRspInfo==NULL){\n";
        str+="      std::cout<<\"pRspInfo: \"<<\"NULL\"<<std::endl;\n";
        str+="      }\n";
        str+="      std::cout<<\"nRequestID: \"<<nRequestID<<std::endl;\n";
        str+="      std::cout<<\"nIsLastNew: \"<<nIsLastNew<<std::endl;\n";
       // str+="      // 设定p"+fieldName+"JS对象的属性和键值\n";
        for(var j=0;j<lengthField;j++){
            if(jsonContent.FTD.fields[0].fieldDefine[j].$.name===fieldName){
                var itemlength=jsonContent.FTD.fields[0].fieldDefine[j].item.length;
                for(k=0;k<itemlength;k++){//获取每个field的item对象
                    var itemName=jsonContent.FTD.fields[0].fieldDefine[j].item[k].$.name;
                    var itemType = jsonContent.FTD.fields[0].fieldDefine[j].item[k].$.type.substring(1, jsonContent.FTD.fields[0].fieldDefine[j].item[k].$.type.length - 4);
                    str+="     v8::Local<v8::String> "+itemName+"=Nan::New<v8::String>(\""+itemName+"\").ToLocalChecked();\n";
                    var IntTypeLength=jsonContent.FTD.types[0].Int.length;
                    var num=0;
                    for(var w=0;w<IntTypeLength;w++){//Int ,int type
                        if(itemType===jsonContent.FTD.types[0].Int[w].$.typename)
                        {
                            num++;
                            str += "     v8::Local<v8::Integer> "+itemName+"Value=Nan::New<v8::Integer>(p" +
                                fieldName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    var QWordLength=jsonContent.FTD.types[0].QWord.length;
                    for(var w=0;w<QWordLength;w++){//QWord , int type
                        if(itemType===jsonContent.FTD.types[0].QWord[w].$.typename)
                        {
                            num++;
                            str += "     v8::Local<v8::Number> "+itemName+"Value=Nan::New<v8::Number>(p" +
                                fieldName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    var RangeIntLength=jsonContent.FTD.types[0].RangeInt.length;

                    for(var w=0;w<RangeIntLength;w++){//RangeInt , int type
                        if(itemType===jsonContent.FTD.types[0].RangeInt[w].$.typename)
                        {
                            num++;
                            str += "     v8::Local<v8::Integer> "+itemName+"Value=Nan::New<v8::Integer>(p" +
                                fieldName + "->"+itemName+");\n";
                            break;
                        }
                    }

                    var fixNumberLength=jsonContent.FTD.types[0].FixNumber.length;
                    for(var w=0;w<fixNumberLength;w++){//FixNumber , int type
                        if(itemType===jsonContent.FTD.types[0].FixNumber[w].$.typename)
                        {
                            num++;
                            str += "     v8::Local<v8::Number> "+itemName+"Value=Nan::New<v8::Number>(p" +
                                fieldName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    var Floatlength=jsonContent.FTD.types[0].Float.length;
                    for(var w=0;w<Floatlength;w++){//Float , int type
                        if(itemType===jsonContent.FTD.types[0].Float[w].$.typename)
                        {
                            num++;
                            str += "     v8::Local<v8::Number> "+itemName+"Value=Nan::New<v8::Number>(p" +
                                fieldName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    var CharLength=jsonContent.FTD.types[0].Char.length;
                    for(var w=0;w<CharLength;w++){//Char , int type
                        if(itemType===jsonContent.FTD.types[0].Char[w].$.typename)
                        {
                            num++;
                            str += "     v8::Local<v8::Integer> "+itemName+"Value=Nan::New<v8::Integer>(p" +
                                fieldName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    var EnumCharLength=jsonContent.FTD.types[0].EnumChar.length;
                    for(var w=0;w<EnumCharLength;w++){//Enumchar , int type
                        if(itemType===jsonContent.FTD.types[0].EnumChar[w].$.typename)
                        {
                            num++;
                            str += "     v8::Local<v8::Integer> "+itemName+"Value=Nan::New<v8::Integer>(p" +
                                fieldName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    var WordLength=jsonContent.FTD.types[0].Word.length;
                    for(var w=0;w<WordLength;w++){//Word , int type
                        if(itemType===jsonContent.FTD.types[0].Word[w].$.typename)
                        {
                            num++;
                            str += "     v8::Local<v8::Integer> "+itemName+"Value=Nan::New<v8::Integer>(p" +
                                fieldName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    if(num===0) {//String、Array、VString , string type
                        str += "     v8::Local<v8::String> "+itemName+"Value=Nan::New(p" +
                            fieldName + "->"+itemName+").ToLocalChecked();\n";
                    }

                }
            }
        }
        //str+="     //绑定p"+fieldName+"JS对象的属性和键值\n";
        str+="     v8::Local<v8::Object> p"+fieldName+"JS=Nan::New<v8::Object>();\n";
        for(var j=0;j<lengthField;j++){
            if(jsonContent.FTD.fields[0].fieldDefine[j].$.name===fieldName){
                var itemlength=jsonContent.FTD.fields[0].fieldDefine[j].item.length;
                for(k=0;k<itemlength;k++){
                    var itemName=jsonContent.FTD.fields[0].fieldDefine[j].item[k].$.name;
                    str+="     p"+fieldName+"JS->Set(Local<v8::Value>("+itemName+"),Local<v8::Value>("+itemName+"Value));\n";
                }
            }
        }
         str+=hereDoc(function(){/*
      v8::Local<v8::Object> pRspInfoJS=Nan::New<v8::Object>();
      if(pRspInfo!=NULL){
          v8::Local<v8::String> ErrorID=Nan::New<v8::String>("ErrorID").ToLocalChecked();
          v8::Local<v8::Integer> ErrorIDValue=Nan::New<v8::Integer>(pRspInfo->ErrorID);
          v8::Local<v8::String> ErrorMsg=Nan::New<v8::String>("ErrorMsg").ToLocalChecked();
          v8::Local<v8::String> ErrorMsggValue=Nan::New(pRspInfo->ErrorMsg).ToLocalChecked();

           v8::Local<v8::Object> pRspInfoJS=Nan::New<v8::Object>();
          pRspInfoJS->Set(Local<v8::Value>(ErrorID),Local<v8::Value>(ErrorIDValue));
          pRspInfoJS->Set(Local<v8::Value>(ErrorMsg),Local<v8::Value>(ErrorMsggValue));
      }
      std::cout<<"pRspInfo==NULL"<<std::endl;
      // v8::Local<v8::String> pRspInfoJSS=Nan::New<v8::String>("test").ToLocalChecked();
      v8::Local<v8::Integer> nRequestIDJS=Nan::New<v8::Integer>(nRequestID);
      v8::Local<v8::Boolean> nIsLastNewJS=Nan::New<v8::Boolean>(nIsLastNew);

      v8::Local<v8::Value> params[4];
    */});
        str+="     params[0]=Local<v8::Value>(p"+fieldName+"JS);\n";
        str+=hereDoc(function(){/*
        if(pRspInfo!=NULL)
            params[1]=Local<v8::Value>(pRspInfoJS);
        else
            params[1]=Local<v8::Value>( Nan::Undefined());
        params[2]=Local<v8::Value>(nRequestIDJS);
        params[3]=Local<v8::Value>(nIsLastNewJS);
        callback.Call(4, params);
    }
    std::cout<<"end1"<<std::endl;
    for(int i=0;i<4;i++){
        delete []paramArrayNew[i];
    }
    delete []paramArrayNew;
        */})
      str+="\n}\n";
    }

    if(jsonContent.FTD.packages[0].package[i].$.name.substring(0,3)==="Rtn"){
        str+="void On"+jsonContent.FTD.packages[0].package[i].$.name+"(uv_async_t *handle)\n";
        str+="{\n";
        str+="    void**paramArrayNew=new void*[4];\n";
        str+="    paramArrayNew = (void**)handle->data;\n";
        str+="    Nan::HandleScope scope;\n";
        str+="    if(SpiObj.IsEmpty())\n";
        str+="    {\n";
        str+="      std::cout<<\" IsEmpty()\"<<std::endl;\n";
        str+="      return;\n";
        str+="    }\n";
        str+="    v8::Local<v8::Object> localSpiObj=Nan::New<v8::Object>(SpiObj);\n"
        str+="    v8::Local<v8::Value> OnFrontConnected=localSpiObj->Get(Nan::New<v8::String>(\"On"+jsonContent.FTD.packages[0].package[i].$.name+"\").ToLocalChecked());\n";
        str+="    if(OnFrontConnected->IsFunction())\n";
        str+="    {\n";
        str+="      v8::Local<v8::Function> function=v8::Local<v8::Function>::Cast(OnFrontConnected);\n";
        str+="      Nan::Callback callback(function); \n";
        str+="      CShfeFtdc"+fieldName+"Field *p"+fieldName+" =(CShfeFtdc"+
            fieldName+"Field *)(paramArrayNew[0]);\n\n";
       // str+="      // 设定p"+fieldName+"JS对象的属性和键值\n";
        for(var j=0;j<lengthField;j++){
            if(jsonContent.FTD.fields[0].fieldDefine[j].$.name===fieldName){
                var itemlength=jsonContent.FTD.fields[0].fieldDefine[j].item.length;
                for(k=0;k<itemlength;k++){//获取每个field的item对象
                    var itemName=jsonContent.FTD.fields[0].fieldDefine[j].item[k].$.name;
                    var itemType = jsonContent.FTD.fields[0].fieldDefine[j].item[k].$.type.substring(1, jsonContent.FTD.fields[0].fieldDefine[j].item[k].$.type.length - 4);
                    str+="     v8::Local<v8::String> "+itemName+"=Nan::New<v8::String>(\""+itemName+"\").ToLocalChecked();\n";
                    var IntTypeLength=jsonContent.FTD.types[0].Int.length;
                    var num=0;
                    for(var w=0;w<IntTypeLength;w++){//int type
                        if(itemType===jsonContent.FTD.types[0].Int[w].$.typename)
                        {
                            num++;
                            str += "     v8::Local<v8::Integer> "+itemName+"Value=Nan::New<v8::Integer>(p" +
                                fieldName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    var QWordLength=jsonContent.FTD.types[0].QWord.length;
                    for(var w=0;w<QWordLength;w++){//int type
                        if(itemType===jsonContent.FTD.types[0].QWord[w].$.typename)
                        {
                            num++;
                            str += "     v8::Local<v8::Number> "+itemName+"Value=Nan::New<v8::Number>(p" +
                                fieldName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    var fixNumberLength=jsonContent.FTD.types[0].FixNumber.length;
                    for(var w=0;w<fixNumberLength;w++){//int type
                        if(itemType===jsonContent.FTD.types[0].FixNumber[w].$.typename)
                        {
                            num++;
                            str += "     v8::Local<v8::Number> "+itemName+"Value=Nan::New<v8::Number>(p" +
                                fieldName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    var RangeIntLength=jsonContent.FTD.types[0].RangeInt.length;
                    for(var w=0;w<RangeIntLength;w++){//int type
                        if(itemType===jsonContent.FTD.types[0].RangeInt[w].$.typename)
                        {
                            num++;
                            str += "     v8::Local<v8::Integer> "+itemName+"Value=Nan::New<v8::Integer>(p" +
                                fieldName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    var Floatlength=jsonContent.FTD.types[0].Float.length;
                    for(var w=0;w<Floatlength;w++){//int type
                        if(itemType===jsonContent.FTD.types[0].Float[w].$.typename)
                        {
                            num++;
                            str += "     v8::Local<v8::Number> "+itemName+"Value=Nan::New<v8::Number>(p" +
                                fieldName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    var WordLength=jsonContent.FTD.types[0].Word.length;
                    for(var w=0;w<WordLength;w++){//int type
                        if(itemType===jsonContent.FTD.types[0].Word[w].$.typename)
                        {
                            num++;
                            str += "     v8::Local<v8::Integer> "+itemName+"Value=Nan::New<v8::Integer>(p" +
                                fieldName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    var CharLength=jsonContent.FTD.types[0].Char.length;
                    for(var w=0;w<CharLength;w++){//int type
                        if(itemType===jsonContent.FTD.types[0].Char[w].$.typename)
                        {
                            num++;
                            str += "     v8::Local<v8::Integer> "+itemName+"Value=Nan::New<v8::Integer>(p" +
                                fieldName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    var EnumCharLength=jsonContent.FTD.types[0].EnumChar.length;
                    for(var w=0;w<EnumCharLength;w++){//int type
                        if(itemType===jsonContent.FTD.types[0].EnumChar[w].$.typename)
                        {
                            num++;
                            str += "     v8::Local<v8::Integer> "+itemName+"Value=Nan::New<v8::Integer>(p" +
                                fieldName + "->"+itemName+");\n";
                            break;
                        }
                    }
                    if(num===0) {//string type
                        str += "     v8::Local<v8::String> "+itemName+"Value=Nan::New(p" +
                            fieldName + "->"+itemName+").ToLocalChecked();\n";
                    }

                }

            }
        }
       // str+="     //绑定p"+fieldName+"JS对象的属性和键值\n";
        str+="\n     v8::Local<v8::Object> p"+fieldName+"JS=Nan::New<v8::Object>();\n";
        for(var j=0;j<lengthField;j++){
            if(jsonContent.FTD.fields[0].fieldDefine[j].$.name===fieldName){
                var itemlength=jsonContent.FTD.fields[0].fieldDefine[j].item.length;
                for(k=0;k<itemlength;k++){
                    var itemName=jsonContent.FTD.fields[0].fieldDefine[j].item[k].$.name;
                    str+="     p"+fieldName+"JS->Set(Local<v8::Value>("+itemName+"),Local<v8::Value>("+itemName+"Value));\n";
                }
            }
        }
       // str+="      //设定pRspInfoJS对象的属性和键值\n";
        str+="\n     v8::Local<v8::Value> param[1];\n"
        str+="     param[0]=Local<v8::Value>(p"+fieldName+"JS);\n";
        str+=hereDoc(function(){/*
     callback.Call(1, param);
     }
     std::cout<<"end1"<<std::endl;
     for(int i=0;i<4;i++){
     delete []paramArrayNew[i];
     }
     delete []paramArrayNew;
     */})
        str+="\n}\n";

    }
}
fs.writeFile('../SpiCFunc.cc', str, function (err) {
    if (err) throw err;
    console.log('It\'s saved!');
    console.log('package length is:'+Packagelength);
});