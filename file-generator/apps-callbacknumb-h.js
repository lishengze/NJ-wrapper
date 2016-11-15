var fs = require('fs');
function hereDoc(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}
var fileData = hereDoc(function () {
/*#ifndef _CALLBACK_NUMB_H_
#define _CALLBACK_NUMB_H_

extern int  g_FrontConnected_spi_callbackNumb;
extern int  g_FrontConnected_trans_callbackNumb;
extern int  g_FrontConnected_trans_dataNumb;

extern int  g_FrontDisconnected_spi_callbackNumb;
extern int  g_FrontDisconnected_trans_callbackNumb;
extern int  g_FrontDisconnected_trans_dataNumb;

extern int  g_HeartBeatWarning_spi_callbackNumb;
extern int  g_HeartBeatWarning_trans_callbackNumb;
extern int  g_HeartBeatWarning_trans_dataNumb;

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
        fileData += 'extern int  ' + 'g_' + funcName + '_spi_callbackNumb;\n'
        fileData += 'extern int  ' + 'g_' + funcName + '_trans_callbackNumb;\n'
        fileData += 'extern int  ' + 'g_' + funcName + '_trans_dataNumb;\n\n'

    }
}


fileData += "\n#endif\n\n";

var pathName = '../new file/';
var fileName = 'callbakc-numb.h';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {
        console.log('Succeed in saving ' + pathName + fileName);
    }

});