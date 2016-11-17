/**
 * Created by li.xiankui on 2015/8/21.
 */
var fs = require('fs');
var hereDoc = require('../lib/tool-function.js').hereDoc;
var jsonContent = require("../lib/ApiData.json");
var FuncCol = jsonContent.FTD.packages[0].package;

var tabSpace = ["","    ", "        ", "            ", "                ","                    "];


var fileData = hereDoc(function () {
 /*#ifndef _SYSUSERSPI_H_
 #define _SYSUSERSPI_H_

 #include "FtdcSysUserApi.h"
 #include "tool-function.h"
 #include "id-func.h"
 #include "nan.h"

 class SysUserSpi: public CShfeFtdcSysUserSpi
 {
    public:
        Nan::Persistent<v8::Object> m_spiobj;
        FRONT_ID m_frontid;
        
    public:
        virtual ~SysUserSpi() {}

*/});

var spiFuncName = [];
for (var i = 0; i < FuncCol.length; ++i) {
    var funcName = FuncCol[i].$.name;
	var funcType = funcName.substring(0, 3);

    if (funcType === "Rsp" || funcType === "Rtn") {
        var funcCore = FuncCol[i].field[0].$.name;
        var firstParaDataStructName = "CShfeFtdc"+ funcCore + "Field *";
        var firstParaName = "p" + funcCore;
        fileData += tabSpace[2] + "virtual void On"+ funcName +"(" + firstParaDataStructName + firstParaName;
        if (funcType === "Rsp" ) {
            fileData +=  ", CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast";
        } 
        fileData += ");\n\n"

    }
    if (funcType === "Spi") {
        var returnValueName = FuncCol[i].field[0].$.name;
        funcName = FuncCol[i].field[1].$.name;
        fileData += tabSpace[2] + "virtual " + returnValueName + " On" + funcName + "(";
        for (var paraIndex = 2; paraIndex < FuncCol[i].field.length; ++paraIndex) {
            if (paraIndex != 2) {
                fileData += ", ";
            }
            fileData += FuncCol[i].field[paraIndex].$.name + " " + FuncCol[i].field[++paraIndex].$.name;
        }
        fileData += ");\n\n"
    }
}

fileData += "}; \n\n";
fileData += "#endif";
var pathName = '../new file/';
var fileName = 'sysuserspi.h';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {            
        console.log('Succeed in saving ' + pathName + fileName);
    }

});