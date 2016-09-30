var fs               = require('fs');
var path             = require('path');
var spi              = require("./communication.js");
//var addon            = require("./addon");
var events           = require("./events.js");
var EVENTS           = new events.EVENTS();
var SysUserApiStruct = require ('./SysUserApiStruct.js');
var toolFunc         = require("./tool-function.js");
var OutputMessage    = toolFunc.OutputMessage;
var getSubString     = toolFunc.getSubString;
var MinusTime        = toolFunc.MinusTime;
var transID          = toolFunc.transID;

var userConnection   = [];
var userSocket       = [];
var userLoginedIn    = [];
var userSocketioId   = [];
var userCount        = 0;
var isHttps          = true;
var idNumber         = 1000;

if (true === isHttps) {
	var options = {
		key:  fs.readFileSync("sfit.key"),
		cert: fs.readFileSync("sfit.cert"),
	};
	var app  = require('https').createServer(options,onRequest);
	var io   = require('socket.io')(app)
	var port = 8000;
	app.listen(port);
} else {
	var app  = require('http').createServer(onRequest);
	var io   = require('socket.io')(app);
	var port = 80;
	app.listen(port);
}

function onRequest(request, response){
	try {
			response.writeHead(200, {'Content-Type':'text/plain'});
			response.write('Hello Socket.io');
			response.end();
	}catch (err) {
			console.error(err);
	}
}

var getIdArray = function(idNumber) {
	var array = new Array(idNumber);
	for (var i = 0; i < idNumber; ++i) {
		array[i] = i;
	}
	return array;
}

var showCurProcessThreads = function () {
    var path = require('path');
    var spawn = require('child_process').spawn;
    var dir = path.join('/proc', process.pid.toString(), 'task');
    var ls = spawn('ls', [dir]);
    console.log('process.pid: ' + process.pid);
    ls.stdout.on('data', function(data){
        console.log('Time:'+Date.now()+'\nThreads: \n'+ data);
    });
}

// showCurProcessThreads();

var realTimeSystemPath  = "tcp://172.1.128.165:18841";
var innerTestSystemPath = "tcp://172.1.128.111:18842";

console.log("Before rootSocket!");
console.log('process.pid: ' + process.pid);

io.on('connection', function(rootSocket) {
    var spawn = require('child_process').spawn('mkdir', ['usr']);

    OutputMessage("\nProxy-Server: root connect complete!");
    //showCurProcessThreads();

    rootSocket.on('disconnect', function(data) {
    	// showCurProcessThreads();
			console.log('\nProxy-Server: rootSocket disconnect!');
		});

		rootSocket.on('Test-Connect', function(){
			console.log('Proxy-Server: Test-Connect');
		})

		rootSocket.on(EVENTS.SocketIONewUserCome, function(userInfo) {

				if (undefined === userSocketioId[userInfo.UserID]) {
					userSocketioId[userInfo.UserID] = getIdArray(idNumber);
				}
				// console.log (userSocketioId[userInfo.UserID]);

				var curNumberId = userSocketioId[userInfo.UserID].shift();
				OutputMessage("Proxy-Server: user: " + userInfo.UserID + " , numberid:        " + curNumberId);

				CurUserSocketioId = userInfo.UserID + curNumberId;
				userLoginedIn[CurUserSocketioId] = {}
				userLoginedIn[CurUserSocketioId].numbId = curNumberId;
				userLoginedIn[CurUserSocketioId].userId = userInfo.UserID;

        if (undefined === userConnection[CurUserSocketioId])
        {
            // console.log(CurUserSocketioId + ' first time!');

            userConnection[CurUserSocketioId] = {};
            userConnection[CurUserSocketioId].socket = io.of('/' + CurUserSocketioId);
            userConnection[CurUserSocketioId].userInfo = userInfo;
            var userWorkDirName = 'usr/' + CurUserSocketioId;
            var spawn = require('child_process').spawn('mkdir', [userWorkDirName]);

            userConnection[CurUserSocketioId].socket.on ('connection', function (curSocket) {

                var currUserID = curSocket.nsp.name.slice(1);
                var userWorkDirName = 'usr/' + currUserID + '/';

                curSocket.on('disconnect', function(data) {
  								originalUserId = userLoginedIn[currUserID].userId;
  								userSocketioId[originalUserId].push(userLoginedIn[currUserID].numbId);
                  // userSocket[currUserID] = {};
    		          OutputMessage("Proxy-Server: user " + currUserID + " disconnected!");
    	          });

                OutputMessage("Proxy-Server: new user " + currUserID + " connect completed!");

                // userSocket[currUserID]           = {};
                // userSocket[currUserID].socket    = curSocket;
                // userSocket[currUserID].userApi   = new addon.FtdcSysUserApi_Wrapper(userWorkDirName);
                // userSocket[currUserID].Spi       = new spi.Spi();
                // userSocket[currUserID].Spi.user  = userSocket[currUserID];

                curSocket.emit(EVENTS.SocketIONewUserConnectComplete, {});

								var timeInterval = 1 * 1000;
								var rtnSendNumber = 18000;
								var g_rtn_callback_onesec = rtnSendNumber *(1000/timeInterval);

								var testValue = "AAAA";
								var g_isRealTime = true;

                curSocket.on(EVENTS.RegisterFront, function() {
    								// OutputMessage('Proxy-Server: Connect Front!');
                    // userSocket[currUserID].userApi.RegisterFront(realTimeSystemPath);
                    // userSocket[currUserID].userApi.RegisterSpi(userSocket[currUserID].Spi);
                    // userSocket[currUserID].userApi.Init();
                    //curSocket.emit("Test Front", 'succeed!');
										var testObject = {};
										testObject.g_isRealTime  = g_isRealTime;
										testObject.rtnSendFreq  = 1000/timeInterval;
										testObject.rtnSendNumber = rtnSendNumber;
                    curSocket.emit(EVENTS.FrontConnected, testObject);
    			      });

								var GetCurrTime = function() {
									myDate = new Date()
									return myDate;
								}

								// man5
								curSocket.on(EVENTS.ReqQrySubscriberTopic, function(reqField) {
										var callbackData = {}
										callbackData = new SysUserApiStruct.CShfeFtdcRtnObjectAttrField();
										callbackData.ObjectID  = testValue;
										callbackData.AttrType  = testValue;
										callbackData.AttrValue = testValue;
										callbackData.ValueType = testValue;
										callbackData.MonDate   = testValue;
										callbackData.MonTime   = testValue;

										if (true === g_isRealTime) {
											var messageProp = "-realTime";
										} else {
											var messageProp = "-nonrealTime";
										}
										var testfileName = path.join (__dirname, './test-memory-redhat-socketio-'+ g_rtn_callback_onesec + messageProp);
										var testfileNameRss = testfileName + '-rss.txt';
										var testfileNameHeapTotal = testfileName + '-heapTotal.txt';
										var testfileNameHeapUsed = testfileName + '-heapUsed.txt';

										fs.writeFileSync (testfileNameRss, '----------- Rss: ' + g_rtn_callback_onesec + messageProp + '-----------\n');
										fs.writeFileSync (testfileNameHeapTotal, '----------- heapTotal: ' + g_rtn_callback_onesec + messageProp + '-----------\n');
										fs.writeFileSync (testfileNameHeapUsed, '----------- heapUsed: ' + g_rtn_callback_onesec + messageProp + '-----------\n');

										var recordNumber = 8;
										var recordNumberIndex = 1;
										function sendData() {
											var g_curDate = GetCurrTime();
											var starttime = g_curDate.getTime();

											for (var i = 0; i < rtnSendNumber; ++i) {
												curSocket.emit(EVENTS.RtnObjectAttrTopic, callbackData);
											}

											var g_curDate = GetCurrTime();
											var endtime = g_curDate.getTime();
											var costtime = endtime - starttime;
											// console.log ('costtime: ' + costtime + 'ms  pack per sec: ' + rtnSendNumber * timeInterval / costtime);
											// curSocket.emit('AveSendNumberInOneSecond',  rtnSendNumber * timeInterval / costtime);

											var memmoryUsed = process.memoryUsage();
											memmoryUsed.rss = memmoryUsed.rss / 1024/1024;
											memmoryUsed.heapTotal = memmoryUsed.heapTotal / 1024/1024;
											memmoryUsed.heapUsed = memmoryUsed.heapUsed / 1024/1024;
											var g_output_info = 'rss: ' + memmoryUsed.rss + ' MB    heapTotal: ' + memmoryUsed.heapTotal
											                  + ' MB    heapUsed:'  + memmoryUsed.heapUsed+ ' MB' + '\n';

											fs.appendFileSync (testfileNameRss, memmoryUsed.rss + ', ');
											fs.appendFileSync (testfileNameHeapTotal, memmoryUsed.heapTotal + ', ');
											fs.appendFileSync (testfileNameHeapUsed, memmoryUsed.heapUsed + ', ');

											if (recordNumberIndex++ === recordNumber) {
												fs.appendFileSync (testfileNameRss, '\n');
												fs.appendFileSync (testfileNameHeapTotal, '\n');
												fs.appendFileSync (testfileNameHeapUsed, '\n');
												recordNumberIndex = 1;
											}

											console.log (g_output_info);

											testValue = "BBBB";
											callbackData.AttrValue = testValue;
										}
										if (true === g_isRealTime) {
											setInterval(sendData, timeInterval);
										} else {
											sendData();
										}

								});

                curSocket.on(EVENTS.ReqQryTopMemInfoTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryTopMemInfo = new SysUserApiStruct.CShfeFtdcRspQryTopMemInfoField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryTopMemInfoTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryTopProcessInfoTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryTopProcessInfo = new SysUserApiStruct.CShfeFtdcRspQryTopProcessInfoField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryTopProcessInfoTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryFileSystemInfoTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryFileSystemInfo = new SysUserApiStruct.CShfeFtdcRspQryFileSystemInfoField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryFileSystemInfoTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryNetworkInfoTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryNetworkInfo = new SysUserApiStruct.CShfeFtdcRspQryNetworkInfoField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryNetworkInfoTopic, callbackData);
                });

								// Man2 TreeView Data:
                curSocket.on(EVENTS.ReqQryMonitorObjectTopic, function(reqField) {
									  console.log('\n');
										console.log(reqField);
									  var ObjectIDArrray = ["A", "A.a", "B", "B.b"];
										var ObjectNameArray = ["A", "a", "B", "b"]
                    var callbackData = []
										for (var i = 0; i < ObjectIDArrray.length; ++i) {
											callbackData[i] = {}
											callbackData[i].pRspQryMonitorObject = new SysUserApiStruct.CShfeFtdcRspQryMonitorObjectField();
											callbackData[i].pRspQryMonitorObject.ObjectID = ObjectIDArrray[i];
											callbackData[i].pRspQryMonitorObject.ObjectName = ObjectNameArray[i];
											callbackData[i].pRspQryMonitorObject.WarningActive = 0;
											callbackData[i].nRequestID = reqField.RequestId;
											if (i === ObjectIDArrray.length-1) {
												callbackData[i].bIsLast = true;
											} else {
												callbackData[i].bIsLast = false;
											}
											// console.log (callbackData[i]);
											curSocket.emit(EVENTS.RspQryMonitorObjectTopic, callbackData[i]);
										}
                });

                curSocket.on(EVENTS.ReqQryObjectRationalTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryObjectRational = new SysUserApiStruct.CShfeFtdcRspQryObjectRationalField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryObjectRationalTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQrySyslogInfoTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQrySyslogInfo = new SysUserApiStruct.CShfeFtdcRspQrySyslogInfoField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQrySyslogInfoTopic, callbackData);
                });




                // // Man4, Subscriber
                // curSocket.on(EVENTS.ReqQrySubscriberTopic, function(reqField) {
                //     console.log('\n');
								// 		console.log(reqField);
								//
                //     var unRealTimeDataNumber = 100;
                //     var timeInterval = 3;
								//
                //     var transObject = transID(reqField.reqObject.ObjectID);
                //     var callbackData = {}
                //     callbackData = new SysUserApiStruct.CShfeFtdcRtnObjectAttrField();
                //     callbackData.ObjectID = transObject.ObjectID;
                //     callbackData.AttrType = transObject.AttrType;
                //     var curWholeTime = (new Date()).toLocaleString();
                //     var curDate = (curWholeTime.substring(0,11)).replace(/-/g, '');
                //     var curTime = curWholeTime.substring(11);
								//
                //     console.log(curWholeTime);
                //     console.log(curDate);
                //     console.log(curTime);
								//
                //     for (var i =0; i<unRealTimeDataNumber; ++i) {
                //          callbackData.AttrValue = ((5 * Math.random())).toString();
                //          callbackData.MonDate = curDate;
                //          callbackData.MonTime = MinusTime(curTime, timeInterval*(unRealTimeDataNumber-i-1));
                //         //  console.log (callbackData.MonTime );
                //          curSocket.emit(EVENTS.RtnObjectAttrTopic, callbackData);
                //     }
								//
                //     console.log ('\nReal Time:');
								//
                //     setInterval(function(){
                //         callbackData.AttrValue = ((5 * Math.random())).toString();
                //         var wholeTime = (new Date()).toLocaleString();
                //         callbackData.MonDate = (wholeTime.substring(0,11)).replace(/-/g, '');
                //         callbackData.MonTime = wholeTime.substring(11);
                //         curSocket.emit(EVENTS.RtnObjectAttrTopic, callbackData);
                //         // console.log (callbackData.MonTime);
                //     }, timeInterval*1000)
								//
                //     curSocket.emit(EVENTS.RtnObjectAttrTopic, callbackData);
                // });

                {
                    // callbackData.pRspQrySubscriber = new SysUserApiStruct.CShfeFtdcRspQrySubscriberField();
                    // callbackData.nRequestID = reqField.RequestId;
                    // callbackData.bIsLast = true;
                    // curSocket.emit(EVENTS.RspQrySubscriberTopic, callbackData);
                }
								//Man3 Grid Data
                curSocket.on(EVENTS.ReqQryOidRelationTopic, function(reqField) {
                    console.log('\n');
                    console.log(reqField);
                    if (reqField.reqObject.ObjectID === "A.a") {
                        var HoldObjectIDArray = ["Active", "TopMemory", "TopCPU", "TopProcess","Network"]
                        // var HoldObjectIDArray = ["TopMemory"]
                    } else {
                        var HoldObjectIDArray = ["Active", "HandleRelayLogin", "HandleRelayLoginError", "HandleNotification","MBLSize"]
                        // var HoldObjectIDArray = ["HandleRelayLogin"]

                    }
                    var callbackData = []
                    for (var i = 0; i < HoldObjectIDArray.length; ++i) {
                        callbackData[i] = {};
                        callbackData[i].pRspQryOidRelation = new SysUserApiStruct.CShfeFtdcRspQryOidRelationField();
                        callbackData[i].pRspQryOidRelation.ObjectID = reqField.reqObject.ObjectID;
                        callbackData[i].pRspQryOidRelation.HoldObjectID = HoldObjectIDArray[i];
                        callbackData[i].nRequestID = reqField.RequestId;

                        if (i === HoldObjectIDArray.length-1) {
                            callbackData[i].bIsLast = true;
                        } else {
                            callbackData[i].bIsLast = false;
                        }

                        curSocket.emit(EVENTS.RspQryOidRelationTopic, callbackData[i]);
                    }

                });

                curSocket.on(EVENTS.ReqQryUserInfoTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryUserInfo = new SysUserApiStruct.CShfeFtdcRspQryUserInfoField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryUserInfoTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryOnlineUserInfoTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryOnlineUserInfo = new SysUserApiStruct.CShfeFtdcRspQryOnlineUserInfoField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryOnlineUserInfoTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryWarningEventTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryWarningEvent = new SysUserApiStruct.CShfeFtdcRspQryWarningEventField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryWarningEventTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryObjectAttrTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryObjectAttr = new SysUserApiStruct.CShfeFtdcRspQryObjectAttrField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryObjectAttrTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryInvalidateOrderTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryInvalidateOrder = new SysUserApiStruct.CShfeFtdcRspQryInvalidateOrderField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryInvalidateOrderTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryOrderStatusTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryOrderStatus = new SysUserApiStruct.CShfeFtdcRspQryOrderStatusField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryOrderStatusTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryBargainOrderTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryBargainOrder = new SysUserApiStruct.CShfeFtdcRspQryBargainOrderField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryBargainOrderTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryInstPropertyTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryInstProperty = new SysUserApiStruct.CShfeFtdcRspQryInstPropertyField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryInstPropertyTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryMarginRateTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryMarginRate = new SysUserApiStruct.CShfeFtdcRspQryMarginRateField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryMarginRateTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryPriceLimitTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryPriceLimit = new SysUserApiStruct.CShfeFtdcRspQryPriceLimitField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryPriceLimitTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryPartPosiLimitTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryPartPosiLimit = new SysUserApiStruct.CShfeFtdcRspQryPartPosiLimitField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryPartPosiLimitTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryClientPosiLimitTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryClientPosiLimit = new SysUserApiStruct.CShfeFtdcRspQryClientPosiLimitField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryClientPosiLimitTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQrySpecialPosiLimitTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQrySpecialPosiLimit = new SysUserApiStruct.CShfeFtdcRspQrySpecialPosiLimitField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQrySpecialPosiLimitTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryTransactionChgTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryTransactionChg = new SysUserApiStruct.CShfeFtdcRspQryTransactionChgField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryTransactionChgTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryClientChgTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryClientChg = new SysUserApiStruct.CShfeFtdcRspQryClientChgField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryClientChgTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryPartClientChgTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryPartClientChg = new SysUserApiStruct.CShfeFtdcRspQryPartClientChgField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryPartClientChgTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryPosiLimitChgTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryPosiLimitChg = new SysUserApiStruct.CShfeFtdcRspQryPosiLimitChgField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryPosiLimitChgTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryHedgeDetailChgTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryHedgeDetailChg = new SysUserApiStruct.CShfeFtdcRspQryHedgeDetailChgField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryHedgeDetailChgTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryParticipantChgTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryParticipantChg = new SysUserApiStruct.CShfeFtdcRspQryParticipantChgField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryParticipantChgTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryMarginRateChgTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryMarginRateChg = new SysUserApiStruct.CShfeFtdcRspQryMarginRateChgField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryMarginRateChgTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryUserIpChgTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryUserIpChg = new SysUserApiStruct.CShfeFtdcRspQryUserIpChgField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryUserIpChgTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryClientPosiLimitChgTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryClientPosiLimitChg = new SysUserApiStruct.CShfeFtdcRspQryClientPosiLimitChgField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryClientPosiLimitChgTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQrySpecPosiLimitChgTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQrySpecPosiLimitChg = new SysUserApiStruct.CShfeFtdcRspQrySpecPosiLimitChgField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQrySpecPosiLimitChgTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryHistoryObjectAttrTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryHistoryObjectAttr = new SysUserApiStruct.CShfeFtdcRspQryHistoryObjectAttrField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryHistoryObjectAttrTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryFrontInfoTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryFrontInfo = new SysUserApiStruct.CShfeFtdcRspQryFrontInfoField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryFrontInfoTopic, callbackData);
                });

								// Man1 Login Data
                curSocket.on(EVENTS.ReqQrySysUserLoginTopic, function(reqField) {
									  console.log('\n');
										console.log(reqField);
                    var callbackData = {}
                    callbackData.pRspQrySysUserLogin = new SysUserApiStruct.CShfeFtdcRspQrySysUserLoginField();
										callbackData.pRspQrySysUserLogin.UserID = reqField.reqObject.UserID;
										callbackData.pRspQrySysUserLogin.TradingDay ="10";
										callbackData.pRspQrySysUserLogin.LoginTime = "12";
										callbackData.pRspQrySysUserLogin.Privilege = 63;
										callbackData.pRspQrySysUserLogin.VersionFlag = 2;

                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQrySysUserLoginTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQrySysUserLogoutTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQrySysUserLogout = new SysUserApiStruct.CShfeFtdcRspQrySysUserLogoutField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQrySysUserLogoutTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQrySysUserPasswordUpdateTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQrySysUserPasswordUpdate = new SysUserApiStruct.CShfeFtdcRspQrySysUserPasswordUpdateField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQrySysUserPasswordUpdateTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQrySysUserRegisterTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQrySysUserRegister = new SysUserApiStruct.CShfeFtdcRspQrySysUserRegisterField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQrySysUserRegisterTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQrySysUserDeleteTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQrySysUserDelete = new SysUserApiStruct.CShfeFtdcRspQrySysUserDeleteField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQrySysUserDeleteTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryTradeLogTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryTradeLog = new SysUserApiStruct.CShfeFtdcRspQryTradeLogField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryTradeLogTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryWarningEventUpdateTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryWarningEventUpdate = new SysUserApiStruct.CShfeFtdcRspQryWarningEventUpdateField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryWarningEventUpdateTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryTradeUserLoginInfoTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryTradeUserLoginInfo = new SysUserApiStruct.CShfeFtdcRspQryTradeUserLoginInfoField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryTradeUserLoginInfoTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryPartTradeTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryPartTrade = new SysUserApiStruct.CShfeFtdcRspQryPartTradeField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryPartTradeTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryTradepeakTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryTradepeak = new SysUserApiStruct.CShfeFtdcRspQryTradepeakField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryTradepeakTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryParticipantInitTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryParticipantInit = new SysUserApiStruct.CShfeFtdcRspQryParticipantInitField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryParticipantInitTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryUserInitTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryUserInit = new SysUserApiStruct.CShfeFtdcRspQryUserInitField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryUserInitTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryHistoryCpuInfoTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryHistoryCpuInfo = new SysUserApiStruct.CShfeFtdcRspQryHistoryCpuInfoField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryHistoryCpuInfoTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryHistoryMemInfoTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryHistoryMemInfo = new SysUserApiStruct.CShfeFtdcRspQryHistoryMemInfoField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryHistoryMemInfoTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryHistoryNetworkInfoTopic, function(reqField) {
                    var callbackData = {}
                    callbackData.pRspQryHistoryNetworkInfo = new SysUserApiStruct.CShfeFtdcRspQryHistoryNetworkInfoField();
                    callbackData.nRequestID = reqField.RequestId;
                    callbackData.bIsLast = true;
                    curSocket.emit(EVENTS.RspQryHistoryNetworkInfoTopic, callbackData);
                });

                curSocket.on(EVENTS.ReqQryHistoryTradePeakTopic, function(reqField) {
                    var callbackData = {}
                   