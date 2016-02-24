var fs               = require('fs');
var spi              = require("./communication.js");
var addon            = require("./build/Release/addon");
var EVENTS           = require('./events.json');
var user             = [];
var userCount        = 0;
var isHttps          = false;

if (true === isHttps) {
	var options = {
		key:  fs.readFileSync("9249652-www.sfit.shfe.com.cn.key"),
		cert: fs.readFileSync("9249652-www.sfit.shfe.com.cn.cert"),
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

var OutputMessage = function (info) {
    console.log(info);
}

var realTimeSystemPath  = "tcp://172.1.128.165:18841";
var innerTestSystemPath = "tcp://172.1.128.111:18842";

io.on('connection', function(rootSocket) {	
	OutputMessage('\nrootSocket connected!\n');	
	rootSocket.on('new user', function(newUserName) {				
		for (var i = 0; i < userCount; ++i)
		{
			if (user[i].username === newUserName) {				
				OutputMessage(newUserName + ' is already in.');
				return;
			}			
		}
        
        var curUserIndex = userCount;
        userCount++
		user[curUserIndex] = {};         
        user[curUserIndex].username = newUserName;
        user[curUserIndex].socket = io.of('/' + newUserName);
        
        user[curUserIndex].socket.on ('connection', function (curSocket) {
                            
            user[curUserIndex].userApi = new addon.FtdcSysUserApi_Wrapper();        
            user[curUserIndex].Spi = new spi.Spi();
            user[curUserIndex].Spi.user.socket = curSocket;
            user[curUserIndex].RequestID = 1;
            
            curSocket.on(EVENTS.RegisterFront, function(data) {
				OutputMessage('Connect Front!');
                user[curUserIndex].userApi.RegisterFront(realTimeSystemPath);   
                user[curUserIndex].userApi.RegisterSpi(user[i].Spi);
                user[curUserIndex].userApi.Init();   				
			});
        
            curSocket.on(EVENTS.ReqQryTopMemInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryTopMemInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryTopProcessInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryTopProcessInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryFileSystemInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryFileSystemInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetworkInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetworkInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryMonitorObjectTopic, function(data) {
                user[curUserIndex].userApi.ReqQryMonitorObjectTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryObjectRationalTopic, function(data) {
                user[curUserIndex].userApi.ReqQryObjectRationalTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQrySyslogInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQrySyslogInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQrySubscriberTopic, function(data) {
                user[curUserIndex].userApi.ReqQrySubscriberTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryOidRelationTopic, function(data) {
                user[curUserIndex].userApi.ReqQryOidRelationTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryUserInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryUserInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryOnlineUserInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryOnlineUserInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryWarningEventTopic, function(data) {
                user[curUserIndex].userApi.ReqQryWarningEventTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryObjectAttrTopic, function(data) {
                user[curUserIndex].userApi.ReqQryObjectAttrTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryInvalidateOrderTopic, function(data) {
                user[curUserIndex].userApi.ReqQryInvalidateOrderTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryOrderStatusTopic, function(data) {
                user[curUserIndex].userApi.ReqQryOrderStatusTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryBargainOrderTopic, function(data) {
                user[curUserIndex].userApi.ReqQryBargainOrderTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryInstPropertyTopic, function(data) {
                user[curUserIndex].userApi.ReqQryInstPropertyTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryMarginRateTopic, function(data) {
                user[curUserIndex].userApi.ReqQryMarginRateTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryPriceLimitTopic, function(data) {
                user[curUserIndex].userApi.ReqQryPriceLimitTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryPartPosiLimitTopic, function(data) {
                user[curUserIndex].userApi.ReqQryPartPosiLimitTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryClientPosiLimitTopic, function(data) {
                user[curUserIndex].userApi.ReqQryClientPosiLimitTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQrySpecialPosiLimitTopic, function(data) {
                user[curUserIndex].userApi.ReqQrySpecialPosiLimitTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryTransactionChgTopic, function(data) {
                user[curUserIndex].userApi.ReqQryTransactionChgTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryClientChgTopic, function(data) {
                user[curUserIndex].userApi.ReqQryClientChgTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryPartClientChgTopic, function(data) {
                user[curUserIndex].userApi.ReqQryPartClientChgTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryPosiLimitChgTopic, function(data) {
                user[curUserIndex].userApi.ReqQryPosiLimitChgTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryHedgeDetailChgTopic, function(data) {
                user[curUserIndex].userApi.ReqQryHedgeDetailChgTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryParticipantChgTopic, function(data) {
                user[curUserIndex].userApi.ReqQryParticipantChgTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryMarginRateChgTopic, function(data) {
                user[curUserIndex].userApi.ReqQryMarginRateChgTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryUserIpChgTopic, function(data) {
                user[curUserIndex].userApi.ReqQryUserIpChgTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryClientPosiLimitChgTopic, function(data) {
                user[curUserIndex].userApi.ReqQryClientPosiLimitChgTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQrySpecPosiLimitChgTopic, function(data) {
                user[curUserIndex].userApi.ReqQrySpecPosiLimitChgTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryHistoryObjectAttrTopic, function(data) {
                user[curUserIndex].userApi.ReqQryHistoryObjectAttrTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryFrontInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryFrontInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQrySysUserLoginTopic, function(data) {
                user[curUserIndex].userApi.ReqQrySysUserLoginTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQrySysUserLogoutTopic, function(data) {
                user[curUserIndex].userApi.ReqQrySysUserLogoutTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQrySysUserPasswordUpdateTopic, function(data) {
                user[curUserIndex].userApi.ReqQrySysUserPasswordUpdateTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQrySysUserRegisterTopic, function(data) {
                user[curUserIndex].userApi.ReqQrySysUserRegisterTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQrySysUserDeleteTopic, function(data) {
                user[curUserIndex].userApi.ReqQrySysUserDeleteTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryTradeLogTopic, function(data) {
                user[curUserIndex].userApi.ReqQryTradeLogTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryWarningEventUpdateTopic, function(data) {
                user[curUserIndex].userApi.ReqQryWarningEventUpdateTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryTradeUserLoginInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryTradeUserLoginInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryPartTradeTopic, function(data) {
                user[curUserIndex].userApi.ReqQryPartTradeTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryTradepeakTopic, function(data) {
                user[curUserIndex].userApi.ReqQryTradepeakTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryParticipantInitTopic, function(data) {
                user[curUserIndex].userApi.ReqQryParticipantInitTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryUserInitTopic, function(data) {
                user[curUserIndex].userApi.ReqQryUserInitTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryHistoryCpuInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryHistoryCpuInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryHistoryMemInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryHistoryMemInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryHistoryNetworkInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryHistoryNetworkInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryHistoryTradePeakTopic, function(data) {
                user[curUserIndex].userApi.ReqQryHistoryTradePeakTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQrySyslogEventTopic, function(data) {
                user[curUserIndex].userApi.ReqQrySyslogEventTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQrySyslogEventSubcriberTopic, function(data) {
                user[curUserIndex].userApi.ReqQrySyslogEventSubcriberTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryTomcatInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryTomcatInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryDBQueryTopic, function(data) {
                user[curUserIndex].userApi.ReqQryDBQueryTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryGetFileTopic, function(data) {
                user[curUserIndex].userApi.ReqQryGetFileTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQrySyslogEventUpdateTopic, function(data) {
                user[curUserIndex].userApi.ReqQrySyslogEventUpdateTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryWarningQueryTopic, function(data) {
                user[curUserIndex].userApi.ReqQryWarningQueryTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryWebVisitTopic, function(data) {
                user[curUserIndex].userApi.ReqQryWebVisitTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryGeneralOperateTopic, function(data) {
                user[curUserIndex].userApi.ReqQryGeneralOperateTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetDeviceLinkedTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetDeviceLinkedTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryTradeUserLoginStatTopic, function(data) {
                user[curUserIndex].userApi.ReqQryTradeUserLoginStatTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryTradeFrontOrderRttStatTopic, function(data) {
                user[curUserIndex].userApi.ReqQryTradeFrontOrderRttStatTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryParticTradeOrderStatesTopic, function(data) {
                user[curUserIndex].userApi.ReqQryParticTradeOrderStatesTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryRouterInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryRouterInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryDiskIOTopic, function(data) {
                user[curUserIndex].userApi.ReqQryDiskIOTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryStatInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryStatInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryTradeOrderRttCutLineTopic, function(data) {
                user[curUserIndex].userApi.ReqQryTradeOrderRttCutLineTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryClientInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryClientInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryEventDescriptionTopic, function(data) {
                user[curUserIndex].userApi.ReqQryEventDescriptionTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryFrontUniqueIDTopic, function(data) {
                user[curUserIndex].userApi.ReqQryFrontUniqueIDTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetPartyLinkAddrChangeTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetPartyLinkAddrChangeTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetDelPartyLinkInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetDelPartyLinkInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryPerformanceTopTopic, function(data) {
                user[curUserIndex].userApi.ReqQryPerformanceTopTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryInstrumentStatusTopic, function(data) {
                user[curUserIndex].userApi.ReqQryInstrumentStatusTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryCurrTradingSegmentAttrTopic, function(data) {
                user[curUserIndex].userApi.ReqQryCurrTradingSegmentAttrTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryRealTimeNetObjectAttrTopic, function(data) {
                user[curUserIndex].userApi.ReqQryRealTimeNetObjectAttrTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetAreaTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetAreaTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetSubAreaTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetSubAreaTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetSubAreaIPTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetSubAreaIPTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetDeviceDetectTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetDeviceDetectTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetDeviceRequestTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetDeviceRequestTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetBuildingTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetBuildingTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetRoomTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetRoomTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetCabinetsTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetCabinetsTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetOIDTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetOIDTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetTimePolicyTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetTimePolicyTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetGatherTaskTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetGatherTaskTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetDeviceChgTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetDeviceChgTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetDeviceTypeTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetDeviceTypeTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetDeviceCategoryTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetDeviceCategoryTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetManufactoryTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetManufactoryTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetCommunityTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetCommunityTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetPortTypeTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetPortTypeTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetPartAccessSpotTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetPartAccessSpotTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetInterfaceTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetInterfaceTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetGeneralOIDTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetGeneralOIDTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetMonitorTypeTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetMonitorTypeTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetMonitorAttrScopeTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetMonitorAttrScopeTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetMonitorAttrTypeTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetMonitorAttrTypeTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetMonitorObjectAttrTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetMonitorObjectAttrTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetMonitorDeviceGroupTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetMonitorDeviceGroupTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetMonitorTaskInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetMonitorTaskInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetMonitorTaskResultTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetMonitorTaskResultTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetMonitorTaskObjectSetTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetMonitorTaskObjectSetTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetPartyLinkInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetPartyLinkInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetMonitorActionAttrTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetMonitorActionAttrTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetModuleTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetModuleTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetMonitorTaskStatusResultTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetMonitorTaskStatusResultTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetCfgFileTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetCfgFileTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetMonitorDeviceTaskTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetMonitorDeviceTaskTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryFileGeneralOperTopic, function(data) {
                user[curUserIndex].userApi.ReqQryFileGeneralOperTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetBaseLineTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetBaseLineTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetBaseLineResultTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetBaseLineResultTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetPartyLinkStatusInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetPartyLinkStatusInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetLocalPingResultInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetLocalPingResultInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetRomotePingResultInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetRomotePingResultInfoTopic(data, user[curUserIndex].RequestID++);
            });

            curSocket.on(EVENTS.ReqQryNetNonPartyLinkInfoTopic, function(data) {
                user[curUserIndex].userApi.ReqQryNetNonPartyLinkInfoTopic(data, user[curUserIndex].RequestID++);
            });

       rootSocket.emit('new user ready to establish connect', newUserName);	  
	   console.log('\nnew user: ' + newUserName + ' arrived');		
       									
	}); // rootSocket.on('new user', function(newUserName) end!	
}); // io.on('connection', function(rootSocket)) end!

