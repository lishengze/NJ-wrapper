var spi      = require("./test-spi.js");
var addon    = require("./build/Release/addon.node");
var SysUserApiStruct    = require("./SysUserApiStruct.js");
var bNewServer = true;

if (true === bNewServer) {
	var realTimeSystemPath  = "tcp://172.1.128.151:19840";
} else {
	var realTimeSystemPath  = "tcp://172.1.128.165:18841";
}

// var realTimeSystemPath  = "tcp://172.1.128.172:19943";
// var realTimeSystemPath = "tcp://192.168.100.1:19943";
var innerTestSystemPath = "tcp://172.1.128.111:18842";
var user = {};

var loginField       = new SysUserApiStruct.CShfeFtdcReqQrySysUserLoginField();
loginField.UserID    = "admin";
loginField.Password  = "admin";
loginField.VersionID = "2.0.0.0";

var monitorObjectField  = new SysUserApiStruct.CShfeFtdcReqQryMonitorObjectField();

var objectID = "TMS.PuDian.app.sysprobe.1";
var attrType = "CPUUsage";
var reqQrySubscriberData = new SysUserApiStruct.CShfeFtdcReqQrySubscriberField();
reqQrySubscriberData.ObjectID = objectID+'.'+attrType;
reqQrySubscriberData.ObjectNum = -1;
reqQrySubscriberData.KeepAlive = 1;

var userWorkDirName = 'usr/' + loginField.UserID;
var spawn = require('child_process').spawn('mkdir', [userWorkDirName]);
userWorkDirName += "/";

// console.log (userWorkDirName)

user.userApi = new addon.FtdcSysUserApi_Wrapper("");
user.loginReqNumbers                   = 0;
user.monitorObjectReqNumbers           = 0;
user.ReqQrySysUserRegisterTopicNumbers = 0;
user.ReqQrySubscriberNumbers           = 0;

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
