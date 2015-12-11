var addon = require("./build/Release/addon");
var structJs = require("./SysUserApiStruct_JS.js");
var fs = require('fs');
var Spi = function(){};

var userApi = new addon.FtdcSysUserApi_Wrapper();
userApi.RegisterFront("tcp://172.1.128.111:18842");       // 内部测试环境;
userApi.RegisterSpi(new Spi());
userApi.Init();

var loginReqNumbers      = 0;
var memReqNumbers        = 0;
var netMonitorReqNumbers = 1;
var bSubRtnObjectAttrTopic = true;
var bunSubRtnObjectAttrTopic = false;
var fileData;
var fileName = 'result-server.txt';
var pathName = './';
var nRequestID = 1;


process.on('beforeExit', function (code) {
	console.log('Nodejs, beforeExit: ' + code.toString());
});

process.on('exit', function (code) {
	console.log('Nodejs, exit: ' + code.toString());
});


Spi.prototype.OnFrontConnected=function(){
	console.log("FrontConnected!");
};

/*************************************************************  请求登陆 ********************************************************/

exports.ReqQrySysUserLoginTopic = function (socket) {	
	var loginField       = new structJs.CShfeFtdcReqQrySysUserLoginField();
	loginField.UserID    = "admin";
	loginField.Password  = "admin";
	loginField.VersionID = "2.0.0.0";
	var rspQrySysUserLoginTopicCalledTime = 0;	
	var ReqQrySysUserLoginTopicCallbackData = [];
	
	Spi.prototype.OnRspQrySysUserLoginTopic = function(pRspQrySysUserLogin,pRspInfo,nRequestID,bIsLast)
	{
		console.log("\n" + "++++++++++++++++ JS OnRspQrySysUserLoginTopic: START! ++++++++++++++++++")
		
		if (pRspQrySysUserLogin instanceof Object) {
			console.log("LoginTime in JS is:                 " + pRspQrySysUserLogin.LoginTime); 
			console.log("UserID in JS is:                    " + pRspQrySysUserLogin.UserID);
			console.log("Privilege in JS is:                 " + pRspQrySysUserLogin.Privilege);
			console.log("TradingDay in JS is:                " + pRspQrySysUserLogin.TradingDay);
			console.log("VersionFlag in JS is:               " + pRspQrySysUserLogin.VersionFlag);	
			console.log("rspQrySysUserLoginTopicCalledTime in JS is:     " + rspQrySysUserLoginTopicCalledTime++);	
			
			ReqQrySysUserLoginTopicCallbackData.push(pRspQrySysUserLogin);			
		}
		
		if (true === bIsLast) {

			socket.emit("ReqQrySysUserLoginTopic CallbackData", ReqQrySysUserLoginTopicCallbackData);	
			
			var pathName = "./";
			var fileName = "ReqQrySysUserLoginTopic-Server-CallbackData.txt";
			fs.writeFile(pathName + fileName, ReqQrySysUserLoginTopicCallbackData, function(err) {
				if (err) {
					console.log(err);
				} else {
					console.log('Succeed in saving ' + pathName + fileName);
				}	
			});
						
			ReqQrySysUserLoginTopicCallbackData = [];		
		}
		
		if(pRspInfo instanceof Object){
		console.log("ErrorID in JS is: "+pRspInfo.ErrorID);
		console.log("ErrorMsg in JS is: "+pRspInfo.ErrorMsg);
		}
		else{
			console.log("datatype of pRspInfo is: "+typeof(pRspInfo));
			console.log("pRspInfo is: "+pRspInfo);		
		}
		
		console.log("nRequestID in JS is: "+nRequestID);
		console.log("nIsLastNew in JS is: "+bIsLast);
		console.log("************** OnRspQrySysUserLoginTopic: END! *************" + "\n");
	}				
	
	Spi.prototype.OnRtnNetLocalPingResultInfoTopic = function(pRtnNetLocalPingResultInfo) {
		console.log("\n" + "++++++++++++++++++++++ JS: OnRtnNetLocalPingResultInfoTopic: START! ++++++++++++++++")
		
		if(pRtnNetLocalPingResultInfo instanceof Object){
			console.log("pRtnNetLocalPingResultInfo->OperationType: ", pRtnNetLocalPingResultInfo.OperationType);
			console.log("pRtnNetLocalPingResultInfo->ID: ", pRtnNetLocalPingResultInfo.ID);
			console.log("pRtnNetLocalPingResultInfo->SouIPADDR: ", pRtnNetLocalPingResultInfo.SouIPADDR);
			console.log("pRtnNetLocalPingResultInfo->SouNAME: ", pRtnNetLocalPingResultInfo.SouNAME);
			console.log("pRtnNetLocalPingResultInfo->TarIPADDR: ", pRtnNetLocalPingResultInfo.TarIPADDR);
			console.log("pRtnNetLocalPingResultInfo->TarNAME: ", pRtnNetLocalPingResultInfo.TarNAME);
			console.log("pRtnNetLocalPingResultInfo->PDateSta: ", pRtnNetLocalPingResultInfo.PDateSta);
			console.log("pRtnNetLocalPingResultInfo->PTimeSta: ", pRtnNetLocalPingResultInfo.PTimeSta);
			console.log("pRtnNetLocalPingResultInfo->ConnRate: ", pRtnNetLocalPingResultInfo.ConnRate);
			
			socket.emit("RtnNetLocalPingResultInfoTopic CallbackData", pRtnNetLocalPingResultInfo);	
		}
		else{
			console.log("datatype of pRspInfo is: " + typeof(pRtnNetLocalPingResultInfo));
			console.log("pRtnNetLocalPingResultInfo is: " + pRtnNetLocalPingResultInfo);		
		}

		console.log("++++++++++++++++++++++ JS:  OnRtnNetLocalPingResultInfoTopic: END! ++++++++++++++++++++++ " + "\n");				
	}
	
	Spi.prototype.OnRtnSysTimeSyncTopic = function(pRtnSysTimeSync) {
		console.log("\n" + "++++++++++++++++++++++ JS: OnRtnSysTimeSyncTopic: START! ++++++++++++++++")
		
		if(pRtnSysTimeSync instanceof Object){
			console.log("pRtnSysTimeSync->MonDate: ", pRtnSysTimeSync.MonDate);
			console.log("pRtnSysTimeSync->MonTime: ", pRtnSysTimeSync.MonTime);  
			
			socket.emit("RtnSysTimeSyncTopic CallbackData", pRtnSysTimeSync);	
		}
		else{
			console.log("datatype of pRspInfo is: " + typeof(pRtnSysTimeSync));
			console.log("pRtnNetLocalPingResultInfo is: " + pRtnSysTimeSync);		
		}
		console.log("++++++++++++++++++++++ JS:  OnRtnSysTimeSyncTopic: END! ++++++++++++++++++++++ " + "\n");				
	}	
			
	console.log("ReqLogin result:" + userApi.ReqQrySysUserLoginTopic(loginField, nRequestID) + "\n");			
}

/************************************************ NetMonitorAttr *************************************************/ 
exports.ReqNetMonitorAttrScope = function(socket) {
	var netMonitorAttrerScopeField           = new structJs.CShfeFtdcReqQryNetMonitorAttrScopeField;
	netMonitorAttrerScopeField.OperationType = 0;
	netMonitorAttrerScopeField.ID            = 0;
	netMonitorAttrerScopeField.CName         = " ";
	netMonitorAttrerScopeField.EName         = " ";
	netMonitorAttrerScopeField.Comments      = " ";
	var netMonitorReqCalledTime              = 0;
	var nRequestID                           = 1;
	var ReqNetMonitorAttrScopeCallbackData   = [];
	
	Spi.prototype.OnRspQryNetMonitorAttrScopeTopic = function (pRspQryNetMonitorAttrScope, pRspInfo, nRequestID, bIsLast) {
		
		OutputMessage("\n************ JS::RspNetMonitorAttrScopeTopic: START! ***********"," ", fileData);
		
		if (pRspQryNetMonitorAttrScope instanceof Object) {
		    console.log("OperationType in JS is:  " + pRspQryNetMonitorAttrScope.OperationType.toString() + "\n" + 
							"ID in JS is:             " + pRspQryNetMonitorAttrScope.ID.toString() + "\n" + 
							"CName in JS is:          " + pRspQryNetMonitorAttrScope.CName.toString() + "\n" + 
							"EName in JS is:          " + pRspQryNetMonitorAttrScope.EName.toString() + "\n" + 
							"Comments in JS is:       " + pRspQryNetMonitorAttrScope.Comments.toString() + "\n");											
			ReqNetMonitorAttrScopeCallbackData.push(pRspQryNetMonitorAttrScope);	
			netMonitorReqCalledTime++;			
		}
		
		if (true === bIsLast) {					
		
			socket.emit("ReqNetMonitorAttrScope CallbackData", ReqNetMonitorAttrScopeCallbackData);
			
			console.log("***************** Test ReqNetMonitorAttrScopeCallbackData *************** \n" 
			            + ReqNetMonitorAttrScopeCallbackData[netMonitorReqCalledTime-2].ID);
						
			netMonitorReqCalledTime = 0;		
			var pathName = "./";
			var fileName = "ReqNetMonitorAttrScope-Server-CallbackData.txt";	
			fs.writeFile(pathName + fileName, ReqNetMonitorAttrScopeCallbackData, function(err) {
				if (err) {
					console.log(err);
				} else {
					console.log('Succeed in saving ' + pathName + fileName);
				}	
			});
			
			ReqNetMonitorAttrScopeCallbackData = [];
			OutputMessage("pRspQryNetMonitorAttrScope  is NULL;\n"," ", fileData);
		}
				
		OutputMessage("bIsLast in JS is:        " , bIsLast, fileData);
		OutputMessage("JS-netMonitorReqCalledTime: " ,  netMonitorReqCalledTime, fileData);
		OutputMessage("************ JS::RspNetMonitorAttrScopeTopic: END! *********** \n", " ",fileData);		
	}	
	console.log("ReqNetMonitorAttrScope result:" +  userApi.ReqQryNetMonitorAttrScopeTopic (netMonitorAttrerScopeField, nRequestID) + "\n");
}

// var intervalTime = 5;
// setInterval(function(){
// 	var i = 0;
// 	console.log("-------------ReqMem result: " 
// 				+ userApi.ReqQryNetMonitorAttrScopeTopic (netMonitorAttrerScopeField, nRequestID) 
// 				+ "----------------\n");	
// 	console.log("+++++++++++++++++++++++++ I: " + i.toString() + " ++++++++++++++++++++++");
// 	i++;	
// } , intervalTime);
/****************************************** RtnNetLocalPingResultInfoTopic:*******************************/

/******************************************* 订阅请求 *****************************************************/
/*
//监控内容订阅请求
struct CShfeFtdcReqQrySubscriberField
{
	///订阅对象名
	TShfeFtdcTypeSubcriberObjectIDType	ObjectID;
	///初次返回对象数, 默认为0;
	TShfeFtdcVolumeType	ObjectNum;
	///持续订阅标记, 1 订阅， 2 取消订阅;
	TShfeFtdcTypeKeepAliveType	KeepAlive;
	///返回的初始日期 默认为空
	TShfeFtdcDateType	MonDate;
	///返回的初始时间 默认为空;
	TShfeFtdcTimeType	MonTime;
};

TShfeFtdcTypeSubcriberObjectIDType szObjID;
CString strTest = _T("PuDian.Test.T-MN3750-B1_1B2_1-2M501.cpmCPUTotal1minRev");
lstrcpyA(szObjID, CT2A(strTest));
SubRtnObjectAttrTopic(szObjID);

*/

// RtnObjectAttrTopic: 对象状态指标查询应答;
exports.SubRtnObjectAttrTopic = function () {
	var reqQrySubscriberField = new structJs.CShfeFtdcReqQrySubscriberField;
	reqQrySubscriberField.TShfeFtdcTypeSubcriberObjectIDType = "PuDian.Test.T-MN3750-B1_1B2_1-2M501.cpmCPUTotal1minRev";
	reqQrySubscriberField.ObjectNum = 3;
	reqQrySubscriberField.MonDate   = "";
	reqQrySubscriberField.MonTime   = "";
	
	if (true === bSubRtnObjectAttrTopic) {
		reqQrySubscriberField.KeepAlive = 1;	
		console.log("SubRtnObjectAttrTopic result:" + userApi.ReqQrySubscriberTopic (reqQrySubscriberField, nRequestID) + "\n");
	}
	
	if (true === bunSubRtnObjectAttrTopic) {
		reqQrySubscriberField.KeepAlive = 0;	
		console.log("unSubRtnObjectAttrTopic result:" + userApi.ReqQrySubscriberTopic (reqQrySubscriberField, nRequestID) + "\n");
	}
}

/***************************************************** 订阅请求 ************************************************************/

var OutputMessage = function (varName, varData,  fileData) {			
	console.log(varName + varData.toString());
}

