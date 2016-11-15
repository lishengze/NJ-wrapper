/**
 * Created by li.shengze on 2016/2/24.
 */
var fs = require('fs');
function hereDoc(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}
var fileData = "";
var jsonContent = require("./ApiData.json");

var tabSpace = ["","    ", "        ", "            ", "                ","                    "];

console.log ("func.numb:       " + jsonContent.FTD.packages[0].package.length)
console.log ("dataStruct.numb: " + jsonContent.FTD.fields[0].fieldDefine.length)
console.log ('dataType.numb:   ' + jsonContent.FTD.types.length)

var ReqFuncNumb = 0;
var RspFuncNumb = 0;
var RtnFuncNumb = 0;
var ConFuncNumb = 0;
var FuncCol = jsonContent.FTD.packages[0].package;

for (var i = 0; i < FuncCol.length; ++i) {
	var funcType = FuncCol[i].$.name.substring(0, 3);
	switch (funcType) {
		case "Req": ++ReqFuncNumb; break;
		case "Rsp": ++RspFuncNumb; break;
		case "Rtn": ++RtnFuncNumb; break;
		default: ++ConFuncNumb; break;
	}
}

console.log ("ReqFuncNumb: " + ReqFuncNumb);
console.log ("RspFuncNumb: " + RspFuncNumb);
console.log ("RtnFuncNumb: " + RtnFuncNumb);
console.log ("ConFuncNumb: " + ConFuncNumb);
console.log ("FuncNumb:    " + (ReqFuncNumb + RspFuncNumb + RtnFuncNumb + ConFuncNumb));


// var beforeRspQryTopCpuInfoTopic=0;
// while(jsonContent.FTD.packages[0].package[beforeRspQryTopCpuInfoTopic].$.name!=="RspQryTopCpuInfoTopic"){
//     beforeRspQryTopCpuInfoTopic++;
// }
// var AfterRtnNetNonPartyLinkInfoTopic=0;
// while(jsonContent.FTD.packages[0].package[AfterRtnNetNonPartyLinkInfoTopic].$.name!=="RtnNetNonPartyLinkInfoTopic"){
//     AfterRtnNetNonPartyLinkInfoTopic++;
// }
// AfterRtnNetNonPartyLinkInfoTopic++;
// for(var i=beforeRspQryTopCpuInfoTopic;i<AfterRtnNetNonPartyLinkInfoTopic;i++) {
//     var funcName  = jsonContent.FTD.packages[0].package[i].$.name;
//     var funcType  = funcName.substring(0,3);

//     if (funcType === "Req" &&
//         funcName.substring(funcName.length - 5, funcName.length) == "Topic" &&
//         funcName!=="ReqQryNetMemberSDHLineInfoTopic"&&
//         funcName!=="ReqQryVMInfoTopic"&&
//         funcName!=="ReqQryTradeDayChangeTopic"&&
//         funcName!=="ReqQryPropertyInfoTopic"&&funcName!=="ReqQryMemPoolInfoTopic"&&
//         funcName!=="ReqQryFileContentInfoTopic"&&
//         funcName!=="ReqQryConnectionInfoTopic"&& funcName!=="ReqQryConnectorInfoTopic"&&
//         funcName!=="ReqQryNetFuncAreaTopic"&& funcName!=="ReqQryNetMonitorCommandTypeTopic"&&
//         funcName!=="ReqQryNetMonitorActionGroupTopic"&& funcName!=="ReqQryNetEventExprTopic"&&
//         funcName!=="ReqQryNetEventTypeTopic"&& funcName!=="ReqQryNetSubEventTypeTopic"&&
//         funcName!=="ReqQryNetEventLevelTopic"&& funcName!=="ReqSysServerExitTopic"&&
//         funcName!=="ReqQryNetMonitorTaskInstAttrsTopic"&& funcName!=="ReqQryNetBaseLineTaskTopic"&&
//         funcName!=="ReqQryNetMemberSDHLineInfoTopic"&& funcName!=="ReqQryNetDDNLinkInfoTopic"&&
//         funcName!=="ReqQryNetPseudMemberLinkInfoTopic"&& funcName!=="ReqQryOuterDeviceInfTopic"&&
//         funcName!=="ReqQrySysInternalTopologyTopic"&& funcName!=="ReqQryMemberLinkCostTopic"&&
//         funcName!=="ReqQryNetPartylinkMonthlyRentTopic"&&fileData!="ReqQryClientLoginTopic"&&
//         funcName!=="ReqQryClientLoginTopic"&&funcName!=="ReqQryCPUUsageTopic"&&
//         funcName!=="ReqQryMemoryUsageTopic"&&funcName!=="ReqQryDiskUsageTopic"&&
//         funcName!=="ReqQryKeyFileInfoTopic"&&funcName!=="ReqQryHostMonitorCfgTopic"&&
//         funcName!=="ReqQryAppMonitorCfgTopic"
//         ) {
//             fileData += tabSpace[1] + "this."+ funcName + " = " + "\"" + funcName + "\",\n";
//             fileData += tabSpace[1] + "this."+ funcName + "Failed = " + "\"" + funcName + "Failed\",\n";
//         }

// }

// fileData += "\n";
// fileData += hereDoc(function () {
// /*     this.FrontConnected = "FrontConnected CallbackData",
//     this.FrontDisConnected = "FrontDisConnected CallbackData",
//     this.HeartBeatWarning =  "HeartBeatWarning CallbackData",

// */});
// for(var i=beforeRspQryTopCpuInfoTopic;i<AfterRtnNetNonPartyLinkInfoTopic;i++){
//     var funcName = jsonContent.FTD.packages[0].package[i].$.name;
//     var funcType = funcName.substring(0,3);
//     if(funcType === "Rsp" || funcType === "Rtn"){
//         fileData += tabSpace[1] + "this."+ funcName+" = " + "\"" + funcName + " CallbackData\",\n";
//     }
// }

// fileData += tabSpace[1] + "this.END = \"END\"\n";
// fileData += "};\n\n";
// fileData += "exports.EVENTS = events;\n"

// var pathName = '../new file/';
// var fileName = 'events.js';
// fs.writeFile(pathName + fileName, fileData, function (err) {
//     if (err) {
//         console.log(err);
//     } else {
//         console.log('Succeed in saving ' + pathName + fileName);
//     }

// });
