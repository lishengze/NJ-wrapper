
var addon = require("./build/Release/addon");
var structJs = require("./SysUserApiStruct_JS.js");
var fs = require('fs');
var Spi = function(){};
Spi.prototype.OnFrontConnected=function(){
	console.log("FrontConnected!");
};

var userApi = new addon.FtdcSysUserApi_Wrapper();
//userApi.RegisterFront("tcp://172.1.128.165:18841");
userApi.RegisterFront("tcp://172.1.128.111:18842");       // 内部测试环境;
userApi.RegisterSpi(new Spi());
userApi.Init();

var loginReqNumbers      = 1;
var memReqNumbers        = 0;
var netMonitorReqNumbers = 0;

process.on('beforeExit', function (code) {
	console.log('Nodejs, beforeExit: ' + code.toString());
});

process.on('exit', function (code) {
	console.log('Nodejs, exit: ' + code.toString());
});

/*************************************************************  请求登陆 ********************************************************/
var outSizeLoginTopic = "outSizeLoginTopic";

Spi.prototype.OnRspQrySysUserLoginTopic=function(pRspQrySysUserLogin,pRspInfo,nRequestID,bIsLast)
{
	console.log("\n" + "**************Test JS Api: START! ***********");
	console.log("LoginTime in JS is:                 " + pRspQrySysUserLogin.LoginTime); 
	console.log("UserID in JS is:                    " + pRspQrySysUserLogin.UserID);
	console.log("Privilege in JS is:                 " + pRspQrySysUserLogin.Privilege);
	console.log("TradingDay in JS is:                " + pRspQrySysUserLogin.TradingDay);
	console.log("VersionFlag in JS is:               " + pRspQrySysUserLogin.VersionFlag);
	console.log("datatype of pRspQrySysUserLogin is: " + typeof(pRspQrySysUserLogin));
	
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
	console.log("**************Test JS Api: END! *************" + "\n");
	console.log("******--------- " + outSizeLoginTopic + "-----------**********");
}

var nRequestID=1;
var loginField       = new structJs.CShfeFtdcReqQrySysUserLoginField();
loginField.UserID    = "admin";
loginField.Password  = "admin";
loginField.VersionID = "2.0.0.0";

for (var i = 0; i < loginReqNumbers; ++i) {
	console.log("ReqLogin result:" + userApi.ReqQrySysUserLoginTopic(loginField, nRequestID) + "\n");		
}


/************************************************ NetMonitorAttr *************************************************/ 
var netMonitorAttrerScopeField           = new structJs.CShfeFtdcReqQryNetMonitorAttrScopeField;
netMonitorAttrerScopeField.OperationType = 0;
netMonitorAttrerScopeField.ID            = 0;
netMonitorAttrerScopeField.CName         = " ";
netMonitorAttrerScopeField.EName         = " ";
netMonitorAttrerScopeField.Comments      = " ";
var netMonitorReqCalledTime              = 0;

Spi.prototype.OnRspQryNetMonitorAttrScopeTopic = function (pRspQryNetMonitorAttrScope, pRspInfo, nRequestID, bIsLast) {
	console.log("\n************ JS::RspNetMonitorAttrScopeTopic: START! ***********");
	var str = "OperationType in JS is:  " + pRspQryNetMonitorAttrScope.OperationType + "\n" + 
			  "ID in JS is:             " + pRspQryNetMonitorAttrScope.ID + "\n" + 
			  "CName in JS is:          " + pRspQryNetMonitorAttrScope.CName + "\n" + 
			  "EName in JS is:          " + pRspQryNetMonitorAttrScope.EName + "\n" + 
			  "Comments in JS is:       " + pRspQryNetMonitorAttrScope.Comments + "\n" ;
			  
	str += netMonitorReqCalledTime.toString() +  "\n\n";
    str += "#endif";
   // fs.writeFileSync('testAsync.txt', str, function (err) {
   // 	if (err) throw err;
   // });
	
	console.log("OperationType in JS is:  " + pRspQryNetMonitorAttrScope.OperationType.toString() + "\n" + 
			    "ID in JS is:             " + pRspQryNetMonitorAttrScope.ID.toString() + "\n" + 
			    "CName in JS is:          " + pRspQryNetMonitorAttrScope.CName.toString() + "\n" + 
			    "EName in JS is:          " + pRspQryNetMonitorAttrScope.EName.toString() + "\n" + 
			    "Comments in JS is:       " + pRspQryNetMonitorAttrScope.Comments.toString() + "\n" +
				"netMonitorReqCalledTime: " + netMonitorReqCalledTime.toString());
				
    console.log("************ JS::RspNetMonitorAttrScopeTopic: END! *********** \n");				
	netMonitorReqCalledTime++;
}


for (var i = 0; i < netMonitorReqNumbers; ++i) {
	console.log("ReqMem "+i.toString() +" result:" + 
	            userApi.ReqQryNetMonitorAttrScopeTopic (netMonitorAttrerScopeField, nRequestID) + "\n");
}

/********************************************* 请求内存信息 *******************************************************/
var memoryReqCalledTime = 1;
Spi.prototype.OnRspQryTopMemInfoTopic = function (pRspQryTopMemInfo, pRspInfo, nRequestID, bIsLast) {
	
	console.log("\nhaha!");
	var str = "HostName in JS is:      " + pRspQryTopMemInfo.HostName + "\n" + 
			  "MonDate in JS is:       " + pRspQryTopMemInfo.MonDate + "\n" + 
			  "MonTime in JS is:       " + pRspQryTopMemInfo.MonTime + "\n" + 
			  "TOTALREAL in JS is:     " + pRspQryTopMemInfo.TOTALREAL + "\n" + 
			  "ACTIVEREAL in JS is:    " + pRspQryTopMemInfo.ACTIVEREAL + "\n" + 
			  "TOTALVIRTUAL in JS is:  " + pRspQryTopMemInfo.TOTALVIRTUAL + "\n" + 
			  "ACTIVEVIRTUAL in JS is: " + pRspQryTopMemInfo.ACTIVEVIRTUAL + "\n" + 
			  "FREE in JS is:          " + pRspQryTopMemInfo.FREE  + "\n";			 
	
	str+= memoryReqCalledTime.toString() +  "\n\n";
    str+="#endif";
    // fs.writeFileSync('testAsync.txt', str, function (err) {
    // 	if (err) throw err;
	// });
	
	console.log("HostName in JS is:      " + pRspQryTopMemInfo.HostName.toString() + "\n" + 
			    "MonDate in JS is:       " + pRspQryTopMemInfo.MonDate.toString() + "\n" + 
			    "MonTime in JS is:       " + pRspQryTopMemInfo.MonTime.toString() + "\n" + 
			    "TOTALREAL in JS is:     " + pRspQryTopMemInfo.TOTALREAL.toString() + "\n" + 
			    "ACTIVEREAL in JS is:    " + pRspQryTopMemInfo.ACTIVEREAL.toString() + "\n" + 
			    "TOTALVIRTUAL in JS is:  " + pRspQryTopMemInfo.TOTALVIRTUAL.toString() + "\n" + 
			    "ACTIVEVIRTUAL in JS is: " + pRspQryTopMemInfo.ACTIVEVIRTUAL.toString() + "\n" + 
			    "FREE in JS is:          " + pRspQryTopMemInfo.FREE.toString()  + "\n" + 
				"memoryReqCalledTime :   " + memoryReqCalledTime.toString());
				
	memoryReqCalledTime++;
}

var memField       = new structJs.CShfeFtdcReqQryTopMemInfoField ();
memField.HostName  = "TRADE2.PuDian.os.tserver1_pd3";
memField.StartDate = " ";
memField.StartTime = " ";
memField.EndDate   = " ";
memField.EndTime   = " ";
memField.KeepAlive = 1;

for (var i = 0; i < memReqNumbers; ++i) {
	console.log("ReqMem "+i.toString() +" result:" + 
	            userApi.ReqQryTopMemInfoTopic (memField, nRequestID) + "\n");
}

	

/********************************************  请求 Subscriber 信息 **********************************************/
// var subscriberReqCalledTime = 1;
// Spi.prototype.OnRspQrySubscriberTopic = function (pRspQrySubscriber, pRspInfo, nRequestID, bIsLast) {
	
// 	console.log("\n********************JS OnRspQrySubscriberTopic: START! ****************");
// 	var str = "ErrorID in JS is:        " + pRspQrySubscriber.ErrorID + "\n" + 
// 			  "ErrorMsg in JS is:       " + pRspQrySubscriber.ErrorMsg + "\n" + 
// 			  "ObjectID in JS is:       " + pRspQrySubscriber.ObjectID + "\n";		 
	
// 	str+= subscriberReqCalledTime.toString() +  "\n\n";
//     str+="#endif";
//     fs.writeFileSync('testAsync.txt', str, function (err) {
//     	if (err) throw err;
// 	});
	
// 	console.log("ErrorID in JS is:        " + pRspQrySubscriber.ErrorID.toString());
// 	console.log("ErrorMsg in JS is:       " + pRspQrySubscriber.ErrorMsg.toString());
// 	console.log("ObjectID in JS is:       " + pRspQrySubscriber.ObjectID.toString());
// 	console.log("subscriberReqCalledTime: " + subscriberReqCalledTime.toString());
	
// 	subscriberReqCalledTime++;	
// 	console.log("********************JS OnRspQrySubscriberTopic: END! ****************\n");
// }

// var subscriberFiled       = new structJs.CShfeFtdcReqQrySubscriberField ();
// subscriberFiled.ObjectID  = "QHA.SYS01.os";
// subscriberFiled.ObjectNum = 0;
// subscriberFiled.KeepAlive = 1;
// var subscriberReqNumbers  = 1;

// for (var i = 1; i < subscriberReqNumbers; ++i) {
// 	console.log("subReqMem " + i.toString() +" result:" + 
// 	            userApi.ReqQrySubscriberTopic (subscriberFiled, nRequestID) + "\n");	
// }


// 
// var timeInterval   = 1;
// for (var i = 0; i < reqNumbers; ++i) {	
// 	// setInterval (console.log("ReqMem result: " +  userApi.ReqQryTopMemInfoTopic(memField, nRequestID) + "\n"), 
// 	// 			timeInterval);	
// 	console.log("ReqMem result: " +  userApi.ReqQryTopMemInfoTopic(memField, nRequestID) + "\n");
// }

///////////////////////////////////////////////////////////////////////////////////////////
// ///用户登录应答
// struct CShfeFtdcRspQrySysUserLoginField-->pRspQrySysUserLogin
// {
// 	///用户代码
// 	TShfeFtdcUserIDType	UserID;
// 	///交易日
// 	TShfeFtdcDateType	TradingDay;
// 	///登录成功时间
// 	TShfeFtdcTimeType	LoginTime;
// 	///用户权限
// 	TShfeFtdcPrivilegeType	Privilege;
// 	///版本匹配标识
// 	TShfeFtdcVersionFlagType	VersionFlag;
// };
// struct CShfeFtdcRspInfoField-->pRspInfo
// {
// 	///错误代码
// 	TShfeFtdcErrorIDType	ErrorID;
// 	///错误信息
// 	TShfeFtdcErrorMsgType	ErrorMsg;
// };
//Spi.prototype.OnRspQrySysUserLoginTopic=function(pRspQrySysUserLogin,pRspInfo,nRequestID,bIsLast)

// var process = require('process');
// var http = require('http');
// var util = require('util');