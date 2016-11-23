var client = require('./client-main.js');
var SysUserApiStruct = require ('./SysUserApiStruct.js');
var EVENTS = require("./Events.js");

var testConnectServer = function (userApi) {
    var userinfo       = new SysUserApiStruct.CShfeFtdcReqQrySysUserLoginField();
    userinfo.UserID    = 'admin'
    userinfo.Password  = 'admin'
    userinfo.VersionID = "2.0.0.0"
    var ReqQrySysUserLoginTopicRequestID = 0;    
    var loginReqField       = {}
    loginReqField.reqObject = userinfo
    loginReqField.RequestId = ++ReqQrySysUserLoginTopicRequestID;
    loginReqField.message   = EVENTS.RspQrySysUserLoginTopic + loginReqField.RequestId

    var connectReqField = {};
    connectReqField.userID = userinfo.UserID;
    connectReqField.infoEmitter = userApi.emitter;

    var monitorObjectInfo  = new SysUserApiStruct.CShfeFtdcReqQryMonitorObjectField();
    var ReqQryMonitorObjectTopicRequestID = 0;
    var monitorObjectField       = {}
    monitorObjectField.reqObject = monitorObjectInfo
    monitorObjectField.RequestId = ++ReqQryMonitorObjectTopicRequestID;
    monitorObjectField.message   = EVENTS.RspQryMonitorObjectTopic + monitorObjectField.RequestId

    userApi.emitter.on (EVENTS.FrontConnected, function(data) {
        console.log ('Step2: ReqQrySysUserLoginTopic.\n');
        userApi.emitter.emit(EVENTS.ReqQrySysUserLoginTopic, loginReqField);
    });

    userApi.emitter.on (loginReqField.message, function(data) {
        console.log ('Step3: ReqQryMonitorObjectTopic.\n');
        userApi.emitter.emit(EVENTS.ReqQryMonitorObjectTopic, monitorObjectField);
    });

    userApi.emitter.on (monitorObjectField.message, function(data) {
        console.log (monitorObjectField.message);    
        console.log (data);    
    });

    console.log ('Step1: ConnectServer.\n');
    userApi.emitter.emit(EVENTS.ConnectServer, connectReqField);

}

testConnectServer(client);
