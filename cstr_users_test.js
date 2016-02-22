var addon    = require("./build/Release/addon");
var structJs = require("./SysUserApiStruct_JS.js");
var spi      = require("./cstr_spi.js");

var realTimeSystemPath  = "tcp://172.1.128.165:18841";
var innerTestSystemPath = "tcp://172.1.128.111:18842";
var userNumbers = 30;
var user = [];

for (var i = 0; i<userNumbers; ++i) {
    
    user[i] = {};
    user[i].userApi = new addon.FtdcSysUserApi_Wrapper();
    user[i].loginReqNumbers                   = 1;
    user[i].netMonitorReqNumbers              = 0;
    user[i].monitorObjectReqNumbers           = 1;
    user[i].ReqQrySysUserRegisterTopicNumbers = 0;
    
    // NewUserIDJ_0-3569.    
    var loginField = [];
    loginField[0]           = new structJs.CShfeFtdcReqQrySysUserLoginField();
    loginField[0].UserID    = "NewUserID_" + i;
    loginField[0].Password  = "1234567";
    loginField[0].VersionID = "2.0.0.0";

    var monitorObjectField       = new structJs.CShfeFtdcReqQryMonitorObjectField;
    monitorObjectField.ObjectID  = " ";
    monitorObjectField.StartDate = " ";
    monitorObjectField.StartTime = " ";
    monitorObjectField.EndDate   = " ";
    monitorObjectField.EndTime   = " ";
    monitorObjectField.KeepAlive = 0;

    user[i].loginField = loginField;
    user[i].monitorObjectField = monitorObjectField;

    user[i].Spi = new spi.Spi();
    user[i].Spi.user = user[i];
    
    user[i].userApi.RegisterFront(realTimeSystemPath);   
    // user[i].userApi.RegisterFront(innerTestSystemPath);   
    user[i].userApi.RegisterSpi(user[i].Spi);
    user[i].userApi.Init();   
    
    //console.log("user[" + i + "].loginField: " + loginField[0]);
}



process.on('beforeExit', function (code) {
	console.log('Nodejs, beforeExit: ' + code.toString());
});

process.on('exit', function (code) {
	console.log('Nodejs, exit: ' + code.toString());
});
