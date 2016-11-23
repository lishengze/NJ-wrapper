/**
 * 作者： 李晟泽
 * 时间： 2016.11.09.
 * 作用:
 * 		自动生成用于本地测试的addon文件。
 * 结构：
 *    1. 生成FtdcSysUserApi_Wrapper类, 提供ReqQry接口。
 *    2. FtdcSysUserApi_Wrapper中定义Spi回调对象，由RegisterSpi注册的Spi赋值。
 *    3. 每个ReqQry接口调用Spi对象对应回调函数。
 */
var fs = require('fs');
function hereDoc(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}
var fileData = hereDoc(function () {
/*var EVENTS  = require("./Events.js");

var FtdcSysUserApi_Wrapper = function(){
    
    this.user = {};    
    
    this.OnFrontConnected = function () {
        var data = {};
        data.message = EVENTS.FrontConnected;
        data.callbackData = {};
        process.send(data);
    }
    
    this.OnFrontDisConnected = function (nReason) {
        var data = {};
        data.message = EVENTS.FrontDisConnected;
        data.callbackData = nReason;
        process.send(data);  
    }
    
    this.OnHeartBeatWarning = function (nTimeLapse) {
        var data = {};
        data.message = EVENTS.HeartBeatWarning;
        data.callbackData = nTimeLapse;
        process.send(data);      
    }         
          
*/});
var jsonContent=require("./package.json");

var tabSpace = ["","    ", "        ", "            ", "                ","                    "];
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
    var funcName = jsonContent.FTD.packages[0].package[i].$.name;
	var fieldName = jsonContent.FTD.packages[0].package[i].field[0].$.name;
    var funcType = funcName.substring(0,3);
    if(funcType === "Rsp" || funcType === "Rtn"){
        var pValueName = "p" + fieldName;

				if (funcType === "Rsp") {
						fileData += tabSpace[1] + "this.On" + funcName + " = function (" + pValueName  + ", pRspInfo, nRequestID, bIsLast) {\n";
				} else {
						fileData += tabSpace[1] + "this.On" + funcName + " = function (" + pValueName + "){ \n" 
				}

				fileData += tabSpace[2] + "var data = {};\n"
									+ tabSpace[2] + "data.message = EVENTS." +funcName+"; \n"						    

        if (funcType === "Rsp") {
            fileData += tabSpace[2] + "data.callbackData = {}; \n"
						          + tabSpace[2] + "data.callbackData." + pValueName + " = " + pValueName + ";\n"
                      + tabSpace[2] + "data.callbackData.pRspInfo = pRspInfo;\n"
                      + tabSpace[2] + "data.callbackData.nRequestID = nRequestID;\n"
                      + tabSpace[2] + "data.callbackData.bIsLast = bIsLast;\n"
                       
        } else {
            
             fileData += tabSpace[2] + "data.callbackData = " + pValueName + ";\n"

        }  

				fileData += tabSpace[2] + "process.send(data); \n"
        fileData += tabSpace[1] + "}\n\n";
    }
}
fileData += tabSpace[0] + "}\n\n";
fileData += "exports.FtdcSysUserApi_Wrapper = FtdcSysUserApi_Wrapper;\n";

var pathName = '../new file/';
var fileName = 'addon.js';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {            
        console.log('Succeed in saving ' + pathName + fileName);
    }

});