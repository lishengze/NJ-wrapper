var addon = require("./build/Release/addon");
var structJs = require("./SysUserApiStruct_JS.js");
var fs = require('fs');
var Spi = function(){};

Spi.prototype.OnFrontConnected=function(){
	console.log("haha FrontConnected!");
	console.log("my ReqLogin result:" + userApi.ReqQrySysUserLoginTopic(loginField[0], 1) + "\n");
};
Spi.prototype.OnRspQrySysUserLoginTopic = function(pRspQrySysUserLogin,pRspInfo,nRequestID,bIsLast)
{
		console.log("++++++++++++++++ JS OnRspQrySysUserLoginTopic ++++++++++++++++++");
		userApi.ReqQryNetMonitorAttrScopeTopic (netMonitorAttrerScopeField, nRequestID++);
};
Spi.prototype.OnRspQryNetMonitorAttrScopeTopic = function (pRspQryNetMonitorAttrScope, pRspInfo, nRequestID, bIsLast) {
	console.log("++++++++++++++++ JS::RspNetMonitorAttrScopeTopic ++++++++++++++++");
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


loginField[1]           = new structJs.CShfeFtdcReqQrySysUserLoginField();
loginField[1].UserID    = "test3333";
loginField[1].Password  = "123456";
loginField[1].VersionID = "2.0.0.0";



/************************************************ NetMonitorAttr *************************************************/
var netMonitorAttrerScopeField           = new structJs.CShfeFtdcReqQryNetMonitorAttrScopeField;
netMonitorAttrerScopeField.OperationType = 0;
netMonitorAttrerScopeField.ID            = 0;
netMonitorAttrerScopeField.CName         = " ";
netMonitorAttrerScopeField.EName         = " ";
netMonitorAttrerScopeField.Comments      = " ";
var netMonitorReqCalledTime              = 0;
var rspQryNetMonitorAttrScopeTopicFileData = "";
