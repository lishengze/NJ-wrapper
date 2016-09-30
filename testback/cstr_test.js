var addon    = require("./build/Release/addon");
var structJs = require("./SysUserApiStruct_JS.js");
var spi      = require("./cstr_spi.js");

var realTimeSystemPath  = "tcp://172.1.128.165:18841";
var innerTestSystemPath = "tcp://172.1.128.111:18842";
var user = {};

user.userApi = new addon.FtdcSysUserApi_Wrapper();
user.loginReqNumbers                   = 0;
user.netMonitorReqNumbers              = 0;
user.monitorObjectReqNumbers           = 1;
user.ReqQrySysUserRegisterTopicNumbers = 0;

/*
NewUserIDE_0-499,
NewUserIDG_0-499.
NewUserIDI_0-1299.
NewUserIDJ_0-3569.
*/

var loginField = [];
loginField[0]           = new structJs.CShfeFtdcReqQrySysUserLoginField();
loginField[0].UserID    = "admin";
loginField[0].Password  = "admin";
loginField[0].VersionID = "2.0.0.0";

var monitorObjectField       = new structJs.CShfeFtdcReqQryMonitorObjectField;
monitorObjectField.ObjectID  = " ";
monitorObjectField.StartDate = " ";
monitorObjectField.StartTime = " ";
monitorObjectField.EndDate   = " ";
monitorObjectField.EndTime   = " ";
monitorObjectField.KeepAlive = 0;

user.loginField = loginField;
user.monitorObjectField = monitorObjectField;
user.Spi = new spi.Spi();
user.Spi.user = user;

// user.Spi.HelloSpi();

user.userApi.RegisterFront(realTimeSystemPath);   
// user.userApi.RegisterFront(innerTestSystemPath);   
user.userApi.RegisterSpi(user.Spi);
user.userApi.Init();

process.on('beforeExit', function (code) {
	console.log('Nodejs, beforeExit: ' + code.toString());
});

process.on('exit', function (code) {
	console.log('Nodejs, exit: ' + code.toString());
});
