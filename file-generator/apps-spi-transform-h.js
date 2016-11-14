/**
 * Created by li.shengze on 2015/12/1.
 */

var fs = require('fs');
function hereDoc(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}
var fileData = hereDoc(function () {
/*#ifndef _SPI_TRANSFORM_H_
#define _SPI_TRANSFORM_H_

#include <queue>
#include <nan.h>
#include <fstream>
using std::fstream;
using std::queue;

extern Nan::Persistent<v8::Object> SpiObj;

extern fstream g_RunningResult_File;

void   OnFrontConnected(uv_async_t *handle);

void   OnFrontDisconnected (uv_async_t *handle);

void   OnHeartBeatWarning (uv_async_t *handle);

*/});

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
        fileData += "void   On" + funcName + " (uv_async_t *handle);\n\n";
    }
}

fileData += "#endif";
var pathName = '../new file/';
var fileName = 'spi-transform.h';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {            
        console.log('Succeed in saving ' + pathName + fileName);
    }

});