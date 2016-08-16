var fs = require('fs');
function hereDoc(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}

var fileData = hereDoc(function () {
/*#include "callback-numb.h"

int  g_FrontConnected_spi_callbackNumb = 0;
int  g_FrontConnected_trans_callbackNumb = 0;
int  g_FrontConnected_trans_dataNumb = 0;

int  g_FrontDisconnected_spi_callbackNumb = 0;
int  g_FrontDisconnected_trans_callbackNumb = 0;
int  g_FrontDisconnected_trans_dataNumb = 0;

int  g_HeartBeatWarning_spi_callbackNumb = 0;
int  g_HeartBeatWarning_trans_callbackNumb = 0;
int  g_HeartBeatWarning_trans_dataNumb = 0;
    
*/});

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
        fileData += 'int  ' + 'g_' + funcName + '_spi_callbackNumb   = 0;\n'
        fileData += 'int  ' + 'g_' + funcName + '_trans_callbackNumb = 0;\n'
        fileData += 'int  ' + 'g_' + funcName + '_trans_dataNumb     = 0;\n\n'
    }
}

fileData += "\n\n";
var pathName = '../new file/';
var fileName = 'callbakc-numb.cpp';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {
        console.log('Succeed in saving ' + pathName + fileName);
    }

});