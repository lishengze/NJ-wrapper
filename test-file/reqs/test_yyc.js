var path = require('path')
var spawn = require('child_process').spawn;
var addon = require("./build/Release/addon");
var structJs = require("./SysUserApiStruct_JS.js");
var fs = require('fs');

var Spi = function(){};

// var logThreadNum = function(cb) {
// 	var dir = path.join('/proc',process.pid.toString(),'task');
// 	const ls = spawn('ls', [dir]);
// 	ls.stdout.on('data', function(data){
// 	  console.log('Time:'+Date.now()+' threads:'+data);
// 		if(cb) cb();
// 	});
// };

// var interval = setInterval(logThreadNum, 2000);

// clearInterval(interval);

var reqID = 1;
Spi.prototype.OnFrontConnected=function(){
	console.log("+++++++++++++++++++++++++++ JS haha FrontConnected! +++++++++++++++++++++++");
	console.log("ReqQrySysUserLoginTopic  result:" + userApi.ReqQrySysUserLoginTopic(loginField[0], reqID++) );

    // console.log("MonitorObjectTopic result:" + userApi.ReqQryMonitorObjectTopic(monitorObjectField, 1) + "\n");
    
	// logThreadNum(function(){
	// 	userApi.ReqQryNetMonitorAttrScopeTopic (netMonitorAttrerScopeField, reqID++)
	// });
	// console.log("my ReqLogin result:" + userApi.ReqQrySysUserLoginTopic(loginField[0], 1) + "\n");
};
Spi.prototype.OnRspQrySysUserLoginTopic = function(pRspQrySysUserLogin,pRspInfo,nRequestID,bIsLast)
{
		console.log("++++++++++++++++++++++++++ JS OnRspQrySysUserLoginTopic ++++++++++++++++++++++++");
		userApi.ReqQryNetMonitorAttrScopeTopic (netMonitorAttrerScopeField, nRequestID++);
};
Spi.prototype.OnRspQryNetMonitorAttrScopeTopic = function (pRspQryNetMonitorAttrScope, pRspInfo, nRequestID, bIsLast) {
	console.log("JS::RspNetMonitorAttrScopeTopic");
};

var userApi = new addon.FtdcSysUserApi_Wrapper();
var realTimeSystemPath = "tcp://172.1.128.165:18841";
var innerTestSystemPath = "tcp://172.1.128.111:18842";

userApi.RegisterFront(realTimeSystemPath);
userApi.RegisterSpi(new Spi());
userApi.Init();


var loginField = [];

loginField[0]           = new structJs.CShfeFtdcReqQrySysUserLoginField();
loginField[0].UserID    = "admin";
loginField[0].Password  = "admin";
loginField[0].VersionID = "2.0.0.0";

/************************************************ NetMonitorAttr *************************************************/
var netMonitorAttrerScopeField           = new structJs.CShfeFtdcReqQryNetMonitorAttrScopeField;
netMonitorAttrerScopeField.OperationType = 0;
netMonitorAttrerScopeField.ID            = 0;
netMonitorAttrerScopeField.CName         = "t";
netMonitorAttrerScopeField.EName         = "t";
netMonitorAttrerScopeField.Comments      = "t";
var netMonitorReqCalledTime              = 0;
var rspQryNetMonitorAttrScopeTopicFileData = "";

/*************************************    ReqQryMonitorObjectTopic   **************************************/
var monitorObjectField       = new structJs.CShfeFtdcReqQryMonitorObjectField;
monitorObjectField.ObjectID  = " ";
monitorObjectField.StartDate = " ";
monitorObjectField.StartTime = " ";
monitorObjectField.EndDate   = " ";
monitorObjectField.EndTime   = " ";
monitorObjectField.KeepAlive = 0;