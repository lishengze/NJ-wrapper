var fs = require('fs');
var hereDoc = require('../lib/tool-function.js').hereDoc;
var sysContent = require("../lib/sysuserapi.json");

var sysFuncs = sysContent.sysuserapi.ftdpackage;
var tabSpace = ["","    ", "        ", "            ", "                ","                    "];

var fileData = hereDoc(function () {
/*#ifndef _FTDCSYSUSERAPI_WRAPPER_H_
#define _FTDCSYSUSERAPI_WRAPPER_H_

#include <nan.h>
#include "FtdcSysUserApi.h"
#include "sysuserspi.h"

class FtdcSysUserApi_Wrapper : public Nan::ObjectWrap {
public:
    static void InitExports(v8::Handle<v8::Object> exports);

public:
    explicit FtdcSysUserApi_Wrapper(const char *pszFlowPath);
    ~FtdcSysUserApi_Wrapper();
  
    static Nan::Persistent<v8::Function> constructor;
    CShfeFtdcSysUserApi* m_userApi;
    SysUserSpi* m_spi;

    static NAN_METHOD(New);
    static NAN_METHOD(Release);
    static NAN_METHOD(Init);
    static NAN_METHOD(Join);

    static NAN_METHOD(ReqUserLogin);
    static NAN_METHOD(GetTradingDay);
    static NAN_METHOD(RegisterFront);
    static NAN_METHOD(RegisterSpi);
    static NAN_METHOD(SubscribeMarketDataTopic);
    static NAN_METHOD(SubscribePartAccount);

*/});

for (var i = 0; i < sysFuncs.length; ++i) {
    var funcName = sysFuncs[i].$.name;
	var funcType = funcName.substring(0, 3);
    if (funcType === "Req") {
        fileData += tabSpace[1] + "static NAN_METHOD(" + funcName + ");\n";
    }
}

fileData+="};\n\n";

fileData+="#endif";

var pathName = '../new-file/';
var fileName = 'ftdcsysuserapi-wrapper.h';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {            
        console.log('Succeed in saving ' + pathName + fileName);
    }

});