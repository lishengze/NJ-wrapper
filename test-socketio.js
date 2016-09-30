var io       						= require('socket.io-client');
var events   						= require("./events.js");
var path    						= require('path');
var fs       						= require('fs');
var SysUserApiStruct    = require("./SysUserApiStruct.js");

var EVENTS   = new events.EVENTS();
var isHttps  = true;
var isLocal  = false;
var userSocket;
var userServer;
var userInfo;

var localUrl;
var serverUrl;
var port;
var curUrl;
var rootSocket;

var connectServer = function (reqData) {
  if (true === isHttps) {
  	localUrl   = 'https://localhost';
  	serverUrl  = 'https://172.1.128.172';
    // serverUrl  = 'https://192.168.159.128';
  	port       = 8000;
    if (true === isLocal) {
      curUrl = localUrl;
    } else {
      curUrl = serverUrl;
    }
  	curUrl     += ':' + port.toString();
  	rootSocket = io.connect(curUrl,{secure:true});
  } else {
  	localUrl   = 'http://localhost';
    serverUrl  = 'http://172.1.128.172';
    // serverUrl  = 'http://192.168.159.128';
    if (true === isLocal) {
      curUrl = localUrl;
    } else {
      curUrl = serverUrl;
    }
  	rootSocket = io.connect(curUrl);
  }
};

connectServer({});

userInfo                = {};
userInfo.UserID         = "admin"
userInfo.Password       = "admin"
userInfo.VersionID      = "2.0.0.0"
loginReqField           = {}
loginReqField.reqObject = userInfo
loginReqField.RequestId = 1

var rspUserLoginCallNumb  = 1;
var rspMonitorObjCallNumb = 0;
var rtnObjectAttrCallNumb = 0;

var g_output_info = "";
var g_RtnObjectAttrTopic_spi_callbackNumb = 0;
var g_startTime = 0;
var g_endTime = 0;

var g_sec = 1
var g_min = 1
var g_stopusec = g_sec * g_min * 1000;

var g_testTimeIndex = 0;
var g_sec_array = [1,5,30,60,60,60,60];
var g_min_array = [1,1,1, 1, 5, 30,60];
var test_numb = 7;

var g_reqNumb = 1;
var g_rtn_over = false;

var g_sec_rtnSendNumber;
var g_sec_rtnSendFreq;
var g_rtn_callback_onesec;

var g_isRealTime;

var testfileName;

var g_curDate = "";
var g_stop = false;
var g_isFirst = true;
var g_isTestFirst = true;

var g_testStartTime;

var GetCurrTime = function() {
myDate = new Date()
return myDate;
}

var resetReqQrySubscriber = function()
{
		if (g_reqNumb ==  6)
		{
				g_testTimeIndex++;

				if (g_testTimeIndex >= test_numb)
				{
					process.exit(0);
				}

				g_sec = g_sec_array[g_testTimeIndex];
				g_min = g_min_array[g_testTimeIndex];
				g_stopusec = g_sec * g_min * 1000;

				g_output_info = "\n----------- Reset Test Time! ----------" + '\n';
				g_output_info += "g_sec: " + g_sec + "    ";
				g_output_info += "g_min: " + g_min + '\n';
				g_output_info += "g_testTimeIndex:  " + g_testTimeIndex + '\n';

				fs.appendFileSync(testfileName, g_output_info);
				console.log (g_output_info);
				g_reqNumb = 1;
		}

		// g_curDate = GetCurrTime();
		// g_startTime = g_curDate.getTime();
		// g_output_info = '\n' + 'StartTime:     ' + g_curDate + '\n';
		// fs.appendFileSync (testfileName,  g_output_info);
		// console.log (g_output_info);
		g_isFirst = true;
		g_rtn_over = false;
		g_RtnObjectAttrTopic_spi_callbackNumb = 0;
}

rootSocket.on(EVENTS.SocketIONewUserReady, function(CurUserSocketioId){

    console.log("Client: CurUserSocketioId " + CurUserSocketioId + " ready!");
  	userSocket = io.connect(curUrl + '/' + CurUserSocketioId);

    userSocket.on(EVENTS.SocketIONewUserConnectComplete, function(data){
       console.log("Client: " + CurUserSocketioId + "  connect completed!");
       userSocket.emit(EVENTS.RegisterFront, {});
	  });

		userSocket.on(EVENTS.FrontConnected, function(testObject){

				g_sec_rtnSendNumber   = testObject.rtnSendNumber;
				g_sec_rtnSendFreq     = testObject.rtnSendFreq;
				g_isRealTime          = testObject.g_isRealTime;
				g_rtn_callback_onesec = g_sec_rtnSendNumber * g_sec_rtnSendFreq;
				console.log (testObject);
				if (true === g_isRealTime) {
					var messageProp = "-realTime";
				} else {
					var messageProp = "-nonrealTime";
				}
				testfileName = path.join (__dirname, './testResult/test-com-redhat-socketio-'+ g_rtn_callback_onesec + messageProp +'.txt');

        // 开始用于测试的订阅请求
        var reqQrySubscriberData = new SysUserApiStruct.CShfeFtdcReqQrySubscriberField();
        reqQrySubscriberData.ObjectID  = "TMS.PuDian.app.sysprobe.1.CPUUsage";
        reqQrySubscriberData.ObjectNum = -1;
        reqQrySubscriberData.KeepAlive = 1;
        var reqQrySubscriberField = {}
        reqQrySubscriberField.reqObject  = reqQrySubscriberData;
        reqQrySubscriberField.RequestId  = 1;
        reqQrySubscriberField.rtnMessage = reqQrySubscriberData.ObjectID;

        userSocket.emit(EVENTS.ReqQrySubscriberTopic, reqQrySubscriberField);

        g_output_info = '\n*******************  Test Start *****************' + '\n'
                      + "g_rtn_callback_onesec: " + g_rtn_callback_onesec + "\n\n";

        fs.writeFileSync (testfileName, g_output_info);
				console.log (g_output_info);

        var reqMonitorObjectTopicData = new SysUserApiStruct.CShfeFtdcReqQryMonitorObjectField()
        ReqQryMonitorObjectTopicField = {}
        ReqQryMonitorObjectTopicField.reqObject  = reqMonitorObjectTopicData
        ReqQryMonitorObjectTopicField.RequestId  = 1
        ReqQryMonitorObjectTopicField.rspMessage =  EVENTS.RspQryMonitorObjectTopic + ReqQryMonitorObjectTopicField.RequestId


        var g_time = 30;
        // for (var i = 0; i < 300 * g_time; ++i) {
        //     userSocket.emit(EVENTS.ReqQryMonitorObjectTopic, ReqQryMonitorObjectTopicField);
        // }

        // userApi.emitter.emit(EVENTS.ReqQrySubscriberTopic, reqQrySubscriberField);
        // userSocket.emit(EVENTS.ReqQrySysUserLoginTopic, reqField);
		});

		var testNumber = 0;

		userSocket.on('AveSendNumberInOneSecond', function(callbackData){
				g_output_info =  'AveSendNumberInOneSecond:  ' + callbackData;
				fs.appendFileSync (testfileName, g_output_info + '\n');
				console.log (g_output_info);
		});

    userSocket.on(EVENTS.RtnObjectAttrTopic, function(callbackData){
				var data = {};
				data.message = EVENTS.RtnObjectAttrTopic;
				data.callbackData = callbackData;
				// process.send(data);

				g_curDate = GetCurrTime();
				if (true === g_isFirst) {
					g_startTime = g_curDate.getTime();

					if (true === g_isTestFirst) {
						g_testStartTime = g_startTime;
						g_isTestFirst = false;
					}

					g_output_info = '\n' + 'StartTime:     ' + g_curDate + '\n';
					fs.appendFileSync (testfileName, g_output_info);
					console.log (g_output_info);
					g_isFirst = false;
				}

				if (callbackData.AttrValue === "AAAA") {
						testNumber++;
						if (testNumber === g_rtn_callback_onesec) {
								g_output_info =  'Get all the data sended in the first second cost ' + (g_curDate.getTime() - g_testStartTime) + ' ms\n';
								fs.appendFileSync (testfileName, g_output_info + '\n');
								console.log (g_output_info);
						}
				}

				if (g_rtn_over === true) return

				++g_RtnObjectAttrTopic_spi_callbackNumb;

				if ((g_curDate.getTime() - g_startTime) > g_stopusec)
				{
					g_output_info =  'TestTime :     ' + g_stopusec/1000 + 's\n'
					g_output_info += 'SumCallbkNumb: ' + g_RtnObjectAttrTopic_spi_callbackNumb + '\n'
					g_output_info += 'AveCallbkNumb: ' + g_RtnObjectAttrTopic_spi_callbackNumb / (g_stopusec/1000) + '\n'
					g_output_info += 'BandWidth:     ' + g_RtnObjectAttrTopic_spi_callbackNumb * 55 / g_stopusec * 1000 / 1024/1024 + 'M/s\n'
					g_output_info += 'g_reqNumb:     ' + g_reqNumb++ + '\n';
					g_output_info += 'EndTime:       ' + g_curDate + '\n';

					fs.appendFileSync (testfileName, g_output_info + '\n');
					console.log (g_output_info);
					g_rtn_over = true;
					resetReqQrySubscriber();
				}
    });

});

rootSocket.on('connect', function(errorObj){
  console.log ("rootSocket connect!");
  rootSocket.emit(EVENTS.SocketIONewUserCome, userInfo);
});

rootSocket.on('error', function(error){
  console.log ('error: ');
  console.log (error);
  console.log ("rootSocket error");
});

rootSocket.on('disconnect', function(){
  console.log ("rootSocket disconnect");
});

rootSocket.on('reconnect', function(Number){
  console.log('rootSocket reconnect, number: ' + Number);
});

rootSocket.on('reconnect_attempt', function(){
  console.log('rootSocket reconnect_attempt!');
});

rootSocket.on('reconnecting', function(Number){
  console.log('rootSocket reconnecting, number: ' + Number);
});

rootSocket.on('reconnect_error', function(Object){
  console.log('Object: ');
  console.log(Object);
  console.log('rootSocket reconnect_error!');
});

rootSocket.on('reconnect_failed', function(){
  console.log('rootSocket reconnect_failed!');
});
