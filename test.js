var addon    = require("./build/Release/addon");
var structJs = require("./SysUserApiStruct_JS.js");
var spi      = require("./test-spi.js");

var realTimeSystemPath  = "tcp://172.1.128.165:18841";
var innerTestSystemPath = "tcp://172.1.128.111:18842";
var user = {};

var loginField = [];
loginField[0]           = new structJs.CShfeFtdcReqQrySysUserLoginField();
loginField[0].UserID    = "admin";
loginField[0].Password  = "admin";
loginField[0].VersionID = "2.0.0.0";

var monitorObjectField  = new structJs.CShfeFtdcReqQryMonitorObjectField();

var objectID = "TMS.PuDian.app.sysprobe.1";
var attrType = "CPUUsage";
var reqQrySubscriberData = new structJs.CShfeFtdcReqQrySubscriberField();
reqQrySubscriberData.ObjectID = objectID+'.'+attrType;
reqQrySubscriberData.ObjectNum = -1;
reqQrySubscriberData.KeepAlive = 1;

var userWorkDirName = 'usr/' + loginField[0].UserID + '/';

user.userApi = new addon.FtdcSysUserApi_Wrapper(userWorkDirName);
user.loginReqNumbers                   = 1;
user.monitorObjectReqNumbers           = 1;
user.ReqQrySysUserRegisterTopicNumbers = 0;
user.ReqQrySubscriberNumbers           = 1;

user.loginField           = loginField;
user.monitorObjectField   = monitorObjectField;
user.reqQrySubscriberData = reqQrySubscriberData;
user.Spi                  = new spi.Spi();
user.Spi.user             = user;

user.userApi.RegisterFront(realTimeSystemPath);    
user.userApi.RegisterSpi(user.Spi);
user.userApi.Init();

process.on('beforeExit', function (code) {
	console.log('Nodejs, beforeExit: ' + code.toString());
});

process.on('exit', function (code) {
	console.log('Nodejs, exit: ' + code.toString());
});
