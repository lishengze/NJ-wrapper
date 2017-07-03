// var addon    = require("./addon.node");
// var addon    = require("./build/Release/addon-node.node");
var addon    = require("./build/Release/addon.node");
var spi      = require("./test-spi.js");
var SysUserApiStruct    = require("./SysUserApiStruct.js");
var bNewServer = true;

if (true === bNewServer) {
	// var realTimeSystemPath = "tcp://172.1.128.151:19840";
	var realTimeSystemPath = "tcp://172.1.128.160:19840";
} else {
	var realTimeSystemPath = "tcp://172.1.128.165:18841";
}
// var realTimeSystemPath  = "tcp://172.1.128.172:19943";
// var realTimeSystemPath = "tcp://192.168.100.1:19943";
var innerTestSystemPath = "tcp://172.1.128.111:18842";


var sysUserLoginField       = new SysUserApiStruct.CShfeFtdcReqQrySysUserLoginField();
sysUserLoginField.UserID    = "admin";
sysUserLoginField.Password  = "admin";
sysUserLoginField.VersionID = "2.0.0.0";

var monitor2ObjectField  = new SysUserApiStruct.CShfeFtdcReqQryMonitor2ObjectField();

var subscriberField = new SysUserApiStruct.CShfeFtdcReqQrySubscriberField();
subscriberField.ObjectID  = "TMS.PuDian.app.sysprobe.1"+'.'+"CPUUsage";
subscriberField.ObjectNum = -1;
subscriberField.KeepAlive = 1;

var subscribeField = new SysUserApiStruct.CShfeFtdcReqSubscribeField();
subscribeField.ObjectID = 72434628689922;  // "BM.TMS.ZhangJ.app.monproxy.1",72434628689922
subscribeField.AttrType = 124; 						 // "CPUUsage", 124

var monConfigInfoField = new SysUserApiStruct.CShfeFtdcReqQryMonConfigInfoField();
monConfigInfoField.ConfigName = "AttrName"; // ObjectIDNS, DomainNS, AttrName,

// var monConfigInfoFieldArray = new Array(3);
// for (var i = 0; i < 3; ++i) {
// 	monConfigInfoFieldArray[]
// }

var user = {};
user.userApi = new addon.FtdcSysUserApi_Wrapper("");
user.bTestSysUserLogin   = true;
user.bTestMonConfigInfo  = false;
user.bTestSubscriberData = false;
user.bTestSubscribe      = false;
user.bTestMonitor2Object = false;

user.sysUserLoginField   = sysUserLoginField;
user.monitor2ObjectField = monitor2ObjectField;
user.monConfigInfoField  = monConfigInfoField;
user.subscribeField      = subscribeField;
user.subscriberField     = subscriberField;
user.Spi                 = new spi.Spi();
user.Spi.user            = user;

reqAllMonConfigDatra();

user.userApi.RegisterFront(realTimeSystemPath);
user.userApi.RegisterSpi(user.Spi);
user.userApi.Init();

function reqAllMonConfigDatra () {
	var monConfigInfoFieldArray = new Array(3);
	for (var i = 0; i < 3; ++i) {
		monConfigInfoFieldArray[i] = new SysUserApiStruct.CShfeFtdcReqQryMonConfigInfoField();
	}
	monConfigInfoFieldArray[0].ConfigName = "ObjectIDNS";
	monConfigInfoFieldArray[1].ConfigName = "DomainNS";
	monConfigInfoFieldArray[2].ConfigName = "AttrName";
	user.monConfigInfoFieldArray = monConfigInfoFieldArray;
	user.bTestAllMonConfigInfo = true;
}

process.on('beforeExit', function (code) {
	console.log('Nodejs, beforeExit: ' + code.toString());
});

process.on('exit', function (code) {
	console.log('Nodejs, exit: ' + code.toString());
});


// var userWorkDirName = 'usr/' + sysUserLoginField.UserID;
// var spawn = require('child_process').spawn('mkdir', [userWorkDirName]);
// userWorkDirName += "/";