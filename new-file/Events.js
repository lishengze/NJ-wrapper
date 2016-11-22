var events = function () {
    // child process events
    this.ChildProcessBeforeExit = 'ChildProcessBeforeExit',
    this.ChildProcessExit = 'ChildProcessExit',
    this.ChildProcessUncaughtException = 'ChildProcessUncaughtException',

    this.ConnectServer = "ConnectServer",

    // server connect events-ManualGenerate
    this.New = "New",
    this.Release = "Release",
    this.Init =  "Init",
    this.Join =  "Join",
    this.ReqUserLogin = "ReqUserLogin",
    this.GetTradingDay =  "GetTradingDay",
    this.RegisterFront =  "RegisterFront",
    this.RegisterSpi =  "RegisterSpi",
    this.SubscribeMarketDataTopic =  "SubscribeMarketDataTopic",
    this.SubscribePartAccount =  "SubscribePartAccount",

    // server connect events-AutoGenerate
    this.ReqQryTopCpuInfoTopic = "ReqQryTopCpuInfoTopic",
    this.ReqQryTopCpuInfoTopicFailed = "ReqQryTopCpuInfoTopicFailed",
    this.ReqQryTopMemInfoTopic = "ReqQryTopMemInfoTopic",
    this.ReqQryTopMemInfoTopicFailed = "ReqQryTopMemInfoTopicFailed",
    this.ReqQryTopProcessInfoTopic = "ReqQryTopProcessInfoTopic",
    this.ReqQryTopProcessInfoTopicFailed = "ReqQryTopProcessInfoTopicFailed",
    this.ReqQryFileSystemInfoTopic = "ReqQryFileSystemInfoTopic",
    this.ReqQryFileSystemInfoTopicFailed = "ReqQryFileSystemInfoTopicFailed",
    this.ReqQryNetworkInfoTopic = "ReqQryNetworkInfoTopic",
    this.ReqQryNetworkInfoTopicFailed = "ReqQryNetworkInfoTopicFailed",
    this.ReqQryMonitorObjectTopic = "ReqQryMonitorObjectTopic",
    this.ReqQryMonitorObjectTopicFailed = "ReqQryMonitorObjectTopicFailed",
    this.ReqQryObjectRationalTopic = "ReqQryObjectRationalTopic",
    this.ReqQryObjectRationalTopicFailed = "ReqQryObjectRationalTopicFailed",
    this.ReqQrySyslogInfoTopic = "ReqQrySyslogInfoTopic",
    this.ReqQrySyslogInfoTopicFailed = "ReqQrySyslogInfoTopicFailed",
    this.ReqQrySubscriberTopic = "ReqQrySubscriberTopic",
    this.ReqQrySubscriberTopicFailed = "ReqQrySubscriberTopicFailed",
    this.ReqQryOidRelationTopic = "ReqQryOidRelationTopic",
    this.ReqQryOidRelationTopicFailed = "ReqQryOidRelationTopicFailed",
    this.ReqQryUserInfoTopic = "ReqQryUserInfoTopic",
    this.ReqQryUserInfoTopicFailed = "ReqQryUserInfoTopicFailed",
    this.ReqQryOnlineUserInfoTopic = "ReqQryOnlineUserInfoTopic",
    this.ReqQryOnlineUserInfoTopicFailed = "ReqQryOnlineUserInfoTopicFailed",
    this.ReqQryWarningEventTopic = "ReqQryWarningEventTopic",
    this.ReqQryWarningEventTopicFailed = "ReqQryWarningEventTopicFailed",
    this.ReqQrySyslogEventTopic = "ReqQrySyslogEventTopic",
    this.ReqQrySyslogEventTopicFailed = "ReqQrySyslogEventTopicFailed",
    this.ReqQrySyslogEventSubcriberTopic = "ReqQrySyslogEventSubcriberTopic",
    this.ReqQrySyslogEventSubcriberTopicFailed = "ReqQrySyslogEventSubcriberTopicFailed",
    this.ReqQryObjectAttrTopic = "ReqQryObjectAttrTopic",
    this.ReqQryObjectAttrTopicFailed = "ReqQryObjectAttrTopicFailed",
    this.ReqQryInvalidateOrderTopic = "ReqQryInvalidateOrderTopic",
    this.ReqQryInvalidateOrderTopicFailed = "ReqQryInvalidateOrderTopicFailed",
    this.ReqQryOrderStatusTopic = "ReqQryOrderStatusTopic",
    this.ReqQryOrderStatusTopicFailed = "ReqQryOrderStatusTopicFailed",
    this.ReqQryBargainOrderTopic = "ReqQryBargainOrderTopic",
    this.ReqQryBargainOrderTopicFailed = "ReqQryBargainOrderTopicFailed",
    this.ReqQryInstPropertyTopic = "ReqQryInstPropertyTopic",
    this.ReqQryInstPropertyTopicFailed = "ReqQryInstPropertyTopicFailed",
    this.ReqQryMarginRateTopic = "ReqQryMarginRateTopic",
    this.ReqQryMarginRateTopicFailed = "ReqQryMarginRateTopicFailed",
    this.ReqQryPriceLimitTopic = "ReqQryPriceLimitTopic",
    this.ReqQryPriceLimitTopicFailed = "ReqQryPriceLimitTopicFailed",
    this.ReqQryPartPosiLimitTopic = "ReqQryPartPosiLimitTopic",
    this.ReqQryPartPosiLimitTopicFailed = "ReqQryPartPosiLimitTopicFailed",
    this.ReqQryClientPosiLimitTopic = "ReqQryClientPosiLimitTopic",
    this.ReqQryClientPosiLimitTopicFailed = "ReqQryClientPosiLimitTopicFailed",
    this.ReqQrySpecialPosiLimitTopic = "ReqQrySpecialPosiLimitTopic",
    this.ReqQrySpecialPosiLimitTopicFailed = "ReqQrySpecialPosiLimitTopicFailed",
    this.ReqQryTransactionChgTopic = "ReqQryTransactionChgTopic",
    this.ReqQryTransactionChgTopicFailed = "ReqQryTransactionChgTopicFailed",
    this.ReqQryClientChgTopic = "ReqQryClientChgTopic",
    this.ReqQryClientChgTopicFailed = "ReqQryClientChgTopicFailed",
    this.ReqQryPartClientChgTopic = "ReqQryPartClientChgTopic",
    this.ReqQryPartClientChgTopicFailed = "ReqQryPartClientChgTopicFailed",
    this.ReqQryPosiLimitChgTopic = "ReqQryPosiLimitChgTopic",
    this.ReqQryPosiLimitChgTopicFailed = "ReqQryPosiLimitChgTopicFailed",
    this.ReqQryClientPosiLimitChgTopic = "ReqQryClientPosiLimitChgTopic",
    this.ReqQryClientPosiLimitChgTopicFailed = "ReqQryClientPosiLimitChgTopicFailed",
    this.ReqQrySpecPosiLimitChgTopic = "ReqQrySpecPosiLimitChgTopic",
    this.ReqQrySpecPosiLimitChgTopicFailed = "ReqQrySpecPosiLimitChgTopicFailed",
    this.ReqQryHedgeDetailChgTopic = "ReqQryHedgeDetailChgTopic",
    this.ReqQryHedgeDetailChgTopicFailed = "ReqQryHedgeDetailChgTopicFailed",
    this.ReqQryParticipantChgTopic = "ReqQryParticipantChgTopic",
    this.ReqQryParticipantChgTopicFailed = "ReqQryParticipantChgTopicFailed",
    this.ReqQryMarginRateChgTopic = "ReqQryMarginRateChgTopic",
    this.ReqQryMarginRateChgTopicFailed = "ReqQryMarginRateChgTopicFailed",
    this.ReqQryUserIpChgTopic = "ReqQryUserIpChgTopic",
    this.ReqQryUserIpChgTopicFailed = "ReqQryUserIpChgTopicFailed",
    this.ReqQryHistoryObjectAttrTopic = "ReqQryHistoryObjectAttrTopic",
    this.ReqQryHistoryObjectAttrTopicFailed = "ReqQryHistoryObjectAttrTopicFailed",
    this.ReqQryFrontInfoTopic = "ReqQryFrontInfoTopic",
    this.ReqQryFrontInfoTopicFailed = "ReqQryFrontInfoTopicFailed",
    this.ReqQrySysUserLoginTopic = "ReqQrySysUserLoginTopic",
    this.ReqQrySysUserLoginTopicFailed = "ReqQrySysUserLoginTopicFailed",
    this.ReqQrySysUserLogoutTopic = "ReqQrySysUserLogoutTopic",
    this.ReqQrySysUserLogoutTopicFailed = "ReqQrySysUserLogoutTopicFailed",
    this.ReqQrySysUserPasswordUpdateTopic = "ReqQrySysUserPasswordUpdateTopic",
    this.ReqQrySysUserPasswordUpdateTopicFailed = "ReqQrySysUserPasswordUpdateTopicFailed",
    this.ReqQrySysUserRegisterTopic = "ReqQrySysUserRegisterTopic",
    this.ReqQrySysUserRegisterTopicFailed = "ReqQrySysUserRegisterTopicFailed",
    this.ReqQrySysUserDeleteTopic = "ReqQrySysUserDeleteTopic",
    this.ReqQrySysUserDeleteTopicFailed = "ReqQrySysUserDeleteTopicFailed",
    this.ReqQryTradeLogTopic = "ReqQryTradeLogTopic",
    this.ReqQryTradeLogTopicFailed = "ReqQryTradeLogTopicFailed",
    this.ReqQryParticipantInitTopic = "ReqQryParticipantInitTopic",
    this.ReqQryParticipantInitTopicFailed = "ReqQryParticipantInitTopicFailed",
    this.ReqQryUserInitTopic = "ReqQryUserInitTopic",
    this.ReqQryUserInitTopicFailed = "ReqQryUserInitTopicFailed",
    this.ReqQryWarningEventUpdateTopic = "ReqQryWarningEventUpdateTopic",
    this.ReqQryWarningEventUpdateTopicFailed = "ReqQryWarningEventUpdateTopicFailed",
    this.ReqQryTradeUserLoginInfoTopic = "ReqQryTradeUserLoginInfoTopic",
    this.ReqQryTradeUserLoginInfoTopicFailed = "ReqQryTradeUserLoginInfoTopicFailed",
    this.ReqQryPartTradeTopic = "ReqQryPartTradeTopic",
    this.ReqQryPartTradeTopicFailed = "ReqQryPartTradeTopicFailed",
    this.ReqQryTradepeakTopic = "ReqQryTradepeakTopic",
    this.ReqQryTradepeakTopicFailed = "ReqQryTradepeakTopicFailed",
    this.ReqQryHistoryCpuInfoTopic = "ReqQryHistoryCpuInfoTopic",
    this.ReqQryHistoryCpuInfoTopicFailed = "ReqQryHistoryCpuInfoTopicFailed",
    this.ReqQryHistoryMemInfoTopic = "ReqQryHistoryMemInfoTopic",
    this.ReqQryHistoryMemInfoTopicFailed = "ReqQryHistoryMemInfoTopicFailed",
    this.ReqQryHistoryNetworkInfoTopic = "ReqQryHistoryNetworkInfoTopic",
    this.ReqQryHistoryNetworkInfoTopicFailed = "ReqQryHistoryNetworkInfoTopicFailed",
    this.ReqQryMonitorOnlineUser = "ReqQryMonitorOnlineUser",
    this.ReqQryMonitorOnlineUserFailed = "ReqQryMonitorOnlineUserFailed",
    this.ReqQryFrontStat = "ReqQryFrontStat",
    this.ReqQryFrontStatFailed = "ReqQryFrontStatFailed",
    this.ReqQryHistoryTradePeakTopic = "ReqQryHistoryTradePeakTopic",
    this.ReqQryHistoryTradePeakTopicFailed = "ReqQryHistoryTradePeakTopicFailed",
    this.ReqQryTomcatInfoTopic = "ReqQryTomcatInfoTopic",
    this.ReqQryTomcatInfoTopicFailed = "ReqQryTomcatInfoTopicFailed",
    this.ReqQryDBQueryTopic = "ReqQryDBQueryTopic",
    this.ReqQryDBQueryTopicFailed = "ReqQryDBQueryTopicFailed",
    this.ReqQryGetFileTopic = "ReqQryGetFileTopic",
    this.ReqQryGetFileTopicFailed = "ReqQryGetFileTopicFailed",
    this.ReqQrySyslogEventUpdateTopic = "ReqQrySyslogEventUpdateTopic",
    this.ReqQrySyslogEventUpdateTopicFailed = "ReqQrySyslogEventUpdateTopicFailed",
    this.ReqQryWarningQueryTopic = "ReqQryWarningQueryTopic",
    this.ReqQryWarningQueryTopicFailed = "ReqQryWarningQueryTopicFailed",
    this.ReqQryWebVisitTopic = "ReqQryWebVisitTopic",
    this.ReqQryWebVisitTopicFailed = "ReqQryWebVisitTopicFailed",
    this.ReqQryWarningActiveChange = "ReqQryWarningActiveChange",
    this.ReqQryWarningActiveChangeFailed = "ReqQryWarningActiveChangeFailed",
    this.ReqQryTradeUserLoginStatTopic = "ReqQryTradeUserLoginStatTopic",
    this.ReqQryTradeUserLoginStatTopicFailed = "ReqQryTradeUserLoginStatTopicFailed",
    this.ReqQryGeneralOperateTopic = "ReqQryGeneralOperateTopic",
    this.ReqQryGeneralOperateTopicFailed = "ReqQryGeneralOperateTopicFailed",
    this.ReqQryNetDeviceLinkedTopic = "ReqQryNetDeviceLinkedTopic",
    this.ReqQryNetDeviceLinkedTopicFailed = "ReqQryNetDeviceLinkedTopicFailed",
    this.ReqQryRealTimeNetObjectAttrTopic = "ReqQryRealTimeNetObjectAttrTopic",
    this.ReqQryRealTimeNetObjectAttrTopicFailed = "ReqQryRealTimeNetObjectAttrTopicFailed",
    this.ReqQryNetAreaTopic = "ReqQryNetAreaTopic",
    this.ReqQryNetAreaTopicFailed = "ReqQryNetAreaTopicFailed",
    this.ReqQryNetSubAreaTopic = "ReqQryNetSubAreaTopic",
    this.ReqQryNetSubAreaTopicFailed = "ReqQryNetSubAreaTopicFailed",
    this.ReqQryNetSubAreaIPTopic = "ReqQryNetSubAreaIPTopic",
    this.ReqQryNetSubAreaIPTopicFailed = "ReqQryNetSubAreaIPTopicFailed",
    this.ReqQryNetDeviceDetectTopic = "ReqQryNetDeviceDetectTopic",
    this.ReqQryNetDeviceDetectTopicFailed = "ReqQryNetDeviceDetectTopicFailed",
    this.ReqQryNetDeviceRequestTopic = "ReqQryNetDeviceRequestTopic",
    this.ReqQryNetDeviceRequestTopicFailed = "ReqQryNetDeviceRequestTopicFailed",
    this.ReqQryNetBuildingTopic = "ReqQryNetBuildingTopic",
    this.ReqQryNetBuildingTopicFailed = "ReqQryNetBuildingTopicFailed",
    this.ReqQryNetRoomTopic = "ReqQryNetRoomTopic",
    this.ReqQryNetRoomTopicFailed = "ReqQryNetRoomTopicFailed",
    this.ReqQryNetCabinetsTopic = "ReqQryNetCabinetsTopic",
    this.ReqQryNetCabinetsTopicFailed = "ReqQryNetCabinetsTopicFailed",
    this.ReqQryNetOIDTopic = "ReqQryNetOIDTopic",
    this.ReqQryNetOIDTopicFailed = "ReqQryNetOIDTopicFailed",
    this.ReqQryNetTimePolicyTopic = "ReqQryNetTimePolicyTopic",
    this.ReqQryNetTimePolicyTopicFailed = "ReqQryNetTimePolicyTopicFailed",
    this.ReqQryNetGatherTaskTopic = "ReqQryNetGatherTaskTopic",
    this.ReqQryNetGatherTaskTopicFailed = "ReqQryNetGatherTaskTopicFailed",
    this.ReqQryNetDeviceChgTopic = "ReqQryNetDeviceChgTopic",
    this.ReqQryNetDeviceChgTopicFailed = "ReqQryNetDeviceChgTopicFailed",
    this.ReqQryNetDeviceTypeTopic = "ReqQryNetDeviceTypeTopic",
    this.ReqQryNetDeviceTypeTopicFailed = "ReqQryNetDeviceTypeTopicFailed",
    this.ReqQryNetDeviceCategoryTopic = "ReqQryNetDeviceCategoryTopic",
    this.ReqQryNetDeviceCategoryTopicFailed = "ReqQryNetDeviceCategoryTopicFailed",
    this.ReqQryNetManufactoryTopic = "ReqQryNetManufactoryTopic",
    this.ReqQryNetManufactoryTopicFailed = "ReqQryNetManufactoryTopicFailed",
    this.ReqQryNetCommunityTopic = "ReqQryNetCommunityTopic",
    this.ReqQryNetCommunityTopicFailed = "ReqQryNetCommunityTopicFailed",
    this.ReqQryNetPortTypeTopic = "ReqQryNetPortTypeTopic",
    this.ReqQryNetPortTypeTopicFailed = "ReqQryNetPortTypeTopicFailed",
    this.ReqQryNetPartAccessSpotTopic = "ReqQryNetPartAccessSpotTopic",
    this.ReqQryNetPartAccessSpotTopicFailed = "ReqQryNetPartAccessSpotTopicFailed",
    this.ReqQryNetInterfaceTopic = "ReqQryNetInterfaceTopic",
    this.ReqQryNetInterfaceTopicFailed = "ReqQryNetInterfaceTopicFailed",
    this.ReqQryNetGeneralOIDTopic = "ReqQryNetGeneralOIDTopic",
    this.ReqQryNetGeneralOIDTopicFailed = "ReqQryNetGeneralOIDTopicFailed",
    this.ReqQryNetMonitorTypeTopic = "ReqQryNetMonitorTypeTopic",
    this.ReqQryNetMonitorTypeTopicFailed = "ReqQryNetMonitorTypeTopicFailed",
    this.ReqQryNetMonitorAttrScopeTopic = "ReqQryNetMonitorAttrScopeTopic",
    this.ReqQryNetMonitorAttrScopeTopicFailed = "ReqQryNetMonitorAttrScopeTopicFailed",
    this.ReqQryNetMonitorAttrTypeTopic = "ReqQryNetMonitorAttrTypeTopic",
    this.ReqQryNetMonitorAttrTypeTopicFailed = "ReqQryNetMonitorAttrTypeTopicFailed",
    this.ReqQryNetMonitorObjectAttrTopic = "ReqQryNetMonitorObjectAttrTopic",
    this.ReqQryNetMonitorObjectAttrTopicFailed = "ReqQryNetMonitorObjectAttrTopicFailed",
    this.ReqQryNetMonitorTaskResultTopic = "ReqQryNetMonitorTaskResultTopic",
    this.ReqQryNetMonitorTaskResultTopicFailed = "ReqQryNetMonitorTaskResultTopicFailed",
    this.ReqQryNetMonitorDeviceGroupTopic = "ReqQryNetMonitorDeviceGroupTopic",
    this.ReqQryNetMonitorDeviceGroupTopicFailed = "ReqQryNetMonitorDeviceGroupTopicFailed",
    this.ReqQryNetMonitorTaskObjectSetTopic = "ReqQryNetMonitorTaskObjectSetTopic",
    this.ReqQryNetMonitorTaskObjectSetTopicFailed = "ReqQryNetMonitorTaskObjectSetTopicFailed",
    this.ReqQryNetMonitorTaskInfoTopic = "ReqQryNetMonitorTaskInfoTopic",
    this.ReqQryNetMonitorTaskInfoTopicFailed = "ReqQryNetMonitorTaskInfoTopicFailed",
    this.ReqQryNetPartyLinkInfoTopic = "ReqQryNetPartyLinkInfoTopic",
    this.ReqQryNetPartyLinkInfoTopicFailed = "ReqQryNetPartyLinkInfoTopicFailed",
    this.ReqQryNetMonitorActionAttrTopic = "ReqQryNetMonitorActionAttrTopic",
    this.ReqQryNetMonitorActionAttrTopicFailed = "ReqQryNetMonitorActionAttrTopicFailed",
    this.ReqQryNetModuleTopic = "ReqQryNetModuleTopic",
    this.ReqQryNetModuleTopicFailed = "ReqQryNetModuleTopicFailed",
    this.ReqQryNetMonitorTaskStatusResultTopic = "ReqQryNetMonitorTaskStatusResultTopic",
    this.ReqQryNetMonitorTaskStatusResultTopicFailed = "ReqQryNetMonitorTaskStatusResultTopicFailed",
    this.ReqQryNetCfgFileTopic = "ReqQryNetCfgFileTopic",
    this.ReqQryNetCfgFileTopicFailed = "ReqQryNetCfgFileTopicFailed",
    this.ReqQryFileGeneralOperTopic = "ReqQryFileGeneralOperTopic",
    this.ReqQryFileGeneralOperTopicFailed = "ReqQryFileGeneralOperTopicFailed",
    this.ReqQryNetPartyLinkStatusInfoTopic = "ReqQryNetPartyLinkStatusInfoTopic",
    this.ReqQryNetPartyLinkStatusInfoTopicFailed = "ReqQryNetPartyLinkStatusInfoTopicFailed",
    this.ReqQryNetBaseLineTopic = "ReqQryNetBaseLineTopic",
    this.ReqQryNetBaseLineTopicFailed = "ReqQryNetBaseLineTopicFailed",
    this.ReqQryNetBaseLineResultTopic = "ReqQryNetBaseLineResultTopic",
    this.ReqQryNetBaseLineResultTopicFailed = "ReqQryNetBaseLineResultTopicFailed",
    this.ReqQryNetMonitorDeviceTaskTopic = "ReqQryNetMonitorDeviceTaskTopic",
    this.ReqQryNetMonitorDeviceTaskTopicFailed = "ReqQryNetMonitorDeviceTaskTopicFailed",
    this.ReqQryNetLocalPingResultInfoTopic = "ReqQryNetLocalPingResultInfoTopic",
    this.ReqQryNetLocalPingResultInfoTopicFailed = "ReqQryNetLocalPingResultInfoTopicFailed",
    this.ReqQryNetRomotePingResultInfoTopic = "ReqQryNetRomotePingResultInfoTopic",
    this.ReqQryNetRomotePingResultInfoTopicFailed = "ReqQryNetRomotePingResultInfoTopicFailed",
    this.ReqQryTradeFrontOrderRttStatTopic = "ReqQryTradeFrontOrderRttStatTopic",
    this.ReqQryTradeFrontOrderRttStatTopicFailed = "ReqQryTradeFrontOrderRttStatTopicFailed",
    this.ReqQryDiskIOTopic = "ReqQryDiskIOTopic",
    this.ReqQryDiskIOTopicFailed = "ReqQryDiskIOTopicFailed",
    this.ReqQryRouterInfoTopic = "ReqQryRouterInfoTopic",
    this.ReqQryRouterInfoTopicFailed = "ReqQryRouterInfoTopicFailed",
    this.ReqQryStatInfoTopic = "ReqQryStatInfoTopic",
    this.ReqQryStatInfoTopicFailed = "ReqQryStatInfoTopicFailed",
    this.ReqQryClientInfoTopic = "ReqQryClientInfoTopic",
    this.ReqQryClientInfoTopicFailed = "ReqQryClientInfoTopicFailed",
    this.ReqQryParticTradeOrderStatesTopic = "ReqQryParticTradeOrderStatesTopic",
    this.ReqQryParticTradeOrderStatesTopicFailed = "ReqQryParticTradeOrderStatesTopicFailed",
    this.ReqQryTradeOrderRttCutLineTopic = "ReqQryTradeOrderRttCutLineTopic",
    this.ReqQryTradeOrderRttCutLineTopicFailed = "ReqQryTradeOrderRttCutLineTopicFailed",
    this.ReqQryEventDescriptionTopic = "ReqQryEventDescriptionTopic",
    this.ReqQryEventDescriptionTopicFailed = "ReqQryEventDescriptionTopicFailed",
    this.ReqQryFrontUniqueIDTopic = "ReqQryFrontUniqueIDTopic",
    this.ReqQryFrontUniqueIDTopicFailed = "ReqQryFrontUniqueIDTopicFailed",
    this.ReqQryNetPartyLinkAddrChangeTopic = "ReqQryNetPartyLinkAddrChangeTopic",
    this.ReqQryNetPartyLinkAddrChangeTopicFailed = "ReqQryNetPartyLinkAddrChangeTopicFailed",
    this.ReqQryNetDelPartyLinkInfoTopic = "ReqQryNetDelPartyLinkInfoTopic",
    this.ReqQryNetDelPartyLinkInfoTopicFailed = "ReqQryNetDelPartyLinkInfoTopicFailed",
    this.ReqQryInstrumentStatusTopic = "ReqQryInstrumentStatusTopic",
    this.ReqQryInstrumentStatusTopicFailed = "ReqQryInstrumentStatusTopicFailed",
    this.ReqQryCurrTradingSegmentAttrTopic = "ReqQryCurrTradingSegmentAttrTopic",
    this.ReqQryCurrTradingSegmentAttrTopicFailed = "ReqQryCurrTradingSegmentAttrTopicFailed",
    this.ReqQryPerformanceTopTopic = "ReqQryPerformanceTopTopic",
    this.ReqQryPerformanceTopTopicFailed = "ReqQryPerformanceTopTopicFailed",

    this.FrontConnected = "FrontConnected CallbackData",
    this.FrontDisConnected = "FrontDisConnected CallbackData",
    this.HeartBeatWarning =  "HeartBeatWarning CallbackData",

    this.RspQryTopCpuInfoTopic = "RspQryTopCpuInfoTopic CallbackData",
    this.RtnTopCpuInfoTopic = "RtnTopCpuInfoTopic CallbackData",
    this.RspQryTopMemInfoTopic = "RspQryTopMemInfoTopic CallbackData",
    this.RtnTopMemInfoTopic = "RtnTopMemInfoTopic CallbackData",
    this.RspQryTopProcessInfoTopic = "RspQryTopProcessInfoTopic CallbackData",
    this.RtnTopProcessInfoTopic = "RtnTopProcessInfoTopic CallbackData",
    this.RspQryFileSystemInfoTopic = "RspQryFileSystemInfoTopic CallbackData",
    this.RtnFileSystemInfoTopic = "RtnFileSystemInfoTopic CallbackData",
    this.RspQryNetworkInfoTopic = "RspQryNetworkInfoTopic CallbackData",
    this.RtnNetworkInfoTopic = "RtnNetworkInfoTopic CallbackData",
    this.RspQryMonitorObjectTopic = "RspQryMonitorObjectTopic CallbackData",
    this.RtnMonitorObjectTopic = "RtnMonitorObjectTopic CallbackData",
    this.RspQryObjectRationalTopic = "RspQryObjectRationalTopic CallbackData",
    this.RtnObjectRationalTopic = "RtnObjectRationalTopic CallbackData",
    this.RspQrySyslogInfoTopic = "RspQrySyslogInfoTopic CallbackData",
    this.RtnSyslogInfoTopic = "RtnSyslogInfoTopic CallbackData",
    this.RspQrySubscriberTopic = "RspQrySubscriberTopic CallbackData",
    this.RspQryOidRelationTopic = "RspQryOidRelationTopic CallbackData",
    this.RtnOidRelationTopic = "RtnOidRelationTopic CallbackData",
    this.RspQryUserInfoTopic = "RspQryUserInfoTopic CallbackData",
    this.RtnUserInfoTopic = "RtnUserInfoTopic CallbackData",
    this.RspQryOnlineUserInfoTopic = "RspQryOnlineUserInfoTopic CallbackData",
    this.RtnOnlineUserInfoTopic = "RtnOnlineUserInfoTopic CallbackData",
    this.RspQryWarningEventTopic = "RspQryWarningEventTopic CallbackData",
    this.RtnWarningEventTopic = "RtnWarningEventTopic CallbackData",
    this.RspQrySyslogEventTopic = "RspQrySyslogEventTopic CallbackData",
    this.RtnSyslogEventTopic = "RtnSyslogEventTopic CallbackData",
    this.RspQryObjectAttrTopic = "RspQryObjectAttrTopic CallbackData",
    this.RtnObjectAttrTopic = "RtnObjectAttrTopic CallbackData",
    this.RspQryInvalidateOrderTopic = "RspQryInvalidateOrderTopic CallbackData",
    this.RtnInvalidateOrderTopic = "RtnInvalidateOrderTopic CallbackData",
    this.RspQryOrderStatusTopic = "RspQryOrderStatusTopic CallbackData",
    this.RtnOrderStatusTopic = "RtnOrderStatusTopic CallbackData",
    this.RspQryBargainOrderTopic = "RspQryBargainOrderTopic CallbackData",
    this.RtnBargainOrderTopic = "RtnBargainOrderTopic CallbackData",
    this.RspQryInstPropertyTopic = "RspQryInstPropertyTopic CallbackData",
    this.RtnInstPropertyTopic = "RtnInstPropertyTopic CallbackData",
    this.RspQryMarginRateTopic = "RspQryMarginRateTopic CallbackData",
    this.RtnMarginRateTopic = "RtnMarginRateTopic CallbackData",
    this.RspQryPriceLimitTopic = "RspQryPriceLimitTopic CallbackData",
    this.RtnPriceLimitTopic = "RtnPriceLimitTopic CallbackData",
    this.RspQryPartPosiLimitTopic = "RspQryPartPosiLimitTopic CallbackData",
    this.RtnPartPosiLimitTopic = "RtnPartPosiLimitTopic CallbackData",
    this.RspQryClientPosiLimitTopic = "RspQryClientPosiLimitTopic CallbackData",
    this.RtnClientPosiLimitTopic = "RtnClientPosiLimitTopic CallbackData",
    this.RspQrySpecialPosiLimitTopic = "RspQrySpecialPosiLimitTopic CallbackData",
    this.RtnSpecialPosiLimitTopic = "RtnSpecialPosiLimitTopic CallbackData",
    this.RspQryTransactionChgTopic = "RspQryTransactionChgTopic CallbackData",
    this.RtnTransactionChgTopic = "RtnTransactionChgTopic CallbackData",
    this.RspQryClientChgTopic = "RspQryClientChgTopic CallbackData",
    this.RtnClientChgTopic = "RtnClientChgTopic CallbackData",
    this.RspQryPartClientChgTopic = "RspQryPartClientChgTopic CallbackData",
    this.RtnPartClientChgTopic = "RtnPartClientChgTopic CallbackData",
    this.RspQryPosiLimitChgTopic = "RspQryPosiLimitChgTopic CallbackData",
    this.RtnPosiLimitChgTopic = "RtnPosiLimitChgTopic CallbackData",
    this.RspQryClientPosiLimitChgTopic = "RspQryClientPosiLimitChgTopic CallbackData",
    this.RtnClientPosiLimitChgTopic = "RtnClientPosiLimitChgTopic CallbackData",
    this.RspQrySpecPosiLimitChgTopic = "RspQrySpecPosiLimitChgTopic CallbackData",
    this.RtnSpecPosiLimitChgTopic = "RtnSpecPosiLimitChgTopic CallbackData",
    this.RspQryHedgeDetailChgTopic = "RspQryHedgeDetailChgTopic CallbackData",
    this.RtnHedgeDetailChgTopic = "RtnHedgeDetailChgTopic CallbackData",
    this.RspQryParticipantChgTopic = "RspQryParticipantChgTopic CallbackData",
    this.RtnParticipantChgTopic = "RtnParticipantChgTopic CallbackData",
    this.RspQryMarginRateChgTopic = "RspQryMarginRateChgTopic CallbackData",
    this.RtnMarginRateChgTopic = "RtnMarginRateChgTopic CallbackData",
    this.RspQryUserIpChgTopic = "RspQryUserIpChgTopic CallbackData",
    this.RtnUserIpChgTopic = "RtnUserIpChgTopic CallbackData",
    this.RspQryHistoryObjectAttrTopic = "RspQryHistoryObjectAttrTopic CallbackData",
    this.RtnHistoryObjectAttrTopic = "RtnHistoryObjectAttrTopic CallbackData",
    this.RspQryFrontInfoTopic = "RspQryFrontInfoTopic CallbackData",
    this.RtnFrontInfoTopic = "RtnFrontInfoTopic CallbackData",
    this.RspQrySysUserLoginTopic = "RspQrySysUserLoginTopic CallbackData",
    this.RspQrySysUserLogoutTopic = "RspQrySysUserLogoutTopic CallbackData",
    this.RspQrySysUserPasswordUpdateTopic = "RspQrySysUserPasswordUpdateTopic CallbackData",
    this.RspQrySysUserRegisterTopic = "RspQrySysUserRegisterTopic CallbackData",
    this.RspQrySysUserDeleteTopic = "RspQrySysUserDeleteTopic CallbackData",
    this.RspQryTradeLogTopic = "RspQryTradeLogTopic CallbackData",
    this.RtnTradeLogTopic = "RtnTradeLogTopic CallbackData",
    this.RspQryParticipantInitTopic = "RspQryParticipantInitTopic CallbackData",
    this.RtnParticipantInitTopic = "RtnParticipantInitTopic CallbackData",
    this.RspQryUserInitTopic = "RspQryUserInitTopic CallbackData",
    this.RtnUserInitTopic = "RtnUserInitTopic CallbackData",
    this.RspQryClientInitTopic = "RspQryClientInitTopic CallbackData",
    this.RtnClientInitTopic = "RtnClientInitTopic CallbackData",
    this.RspQryTradeUserLoginInfoTopic = "RspQryTradeUserLoginInfoTopic CallbackData",
    this.RtnTradeUserLoginInfoTopic = "RtnTradeUserLoginInfoTopic CallbackData",
    this.RspQryPartTradeTopic = "RspQryPartTradeTopic CallbackData",
    this.RspQryTradepeakTopic = "RspQryTradepeakTopic CallbackData",
    this.RtnUpdateSysConfigTopic = "RtnUpdateSysConfigTopic CallbackData",
    this.RtnSysUser = "RtnSysUser CallbackData",
    this.RspQryHistoryCpuInfoTopic = "RspQryHistoryCpuInfoTopic CallbackData",
    this.RspQryHistoryMemInfoTopic = "RspQryHistoryMemInfoTopic CallbackData",
    this.RspQryHistoryNetworkInfoTopic = "RspQryHistoryNetworkInfoTopic CallbackData",
    this.RspQryMonitorOnlineUser = "RspQryMonitorOnlineUser CallbackData",
    this.RspQryFrontStat = "RspQryFrontStat CallbackData",
    this.RtnSysTimeSyncTopic = "RtnSysTimeSyncTopic CallbackData",
    this.RtnDataCenterChgTopic = "RtnDataCenterChgTopic CallbackData",
    this.RspQryHistoryTradePeakTopic = "RspQryHistoryTradePeakTopic CallbackData",
    this.RspQryJDBCInfoTopic = "RspQryJDBCInfoTopic CallbackData",
    this.RspQryThreadInfoTopic = "RspQryThreadInfoTopic CallbackData",
    this.RspQrySessionInfoTopic = "RspQrySessionInfoTopic CallbackData",
    this.RspQryServletInfoTopic = "RspQryServletInfoTopic CallbackData",
    this.RspQryFileInfoTopic = "RspQryFileInfoTopic CallbackData",
    this.RspQryWebAppInfoTopic = "RspQryWebAppInfoTopic CallbackData",
    this.RspQryVMInfoTopic = "RspQryVMInfoTopic CallbackData",
    this.RspQryPropertyInfoTopic = "RspQryPropertyInfoTopic CallbackData",
    this.RspQryMemPoolInfoTopic = "RspQryMemPoolInfoTopic CallbackData",
    this.RspQryFileContentInfoTopic = "RspQryFileContentInfoTopic CallbackData",
    this.RspQryConnectionInfoTopic = "RspQryConnectionInfoTopic CallbackData",
    this.RspQryConnectorInfoTopic = "RspQryConnectorInfoTopic CallbackData",
    this.RtnVMInfoTopic = "RtnVMInfoTopic CallbackData",
    this.RtnPropertyInfoTopic = "RtnPropertyInfoTopic CallbackData",
    this.RtnMemPoolInfoTopic = "RtnMemPoolInfoTopic CallbackData",
    this.RtnFileContentInfoTopic = "RtnFileContentInfoTopic CallbackData",
    this.RtnConnectionInfoTopic = "RtnConnectionInfoTopic CallbackData",
    this.RtnConnectorInfoTopic = "RtnConnectorInfoTopic CallbackData",
    this.RtnJDBCInfoTopic = "RtnJDBCInfoTopic CallbackData",
    this.RtnThreadInfoTopic = "RtnThreadInfoTopic CallbackData",
    this.RtnSessionInfoTopic = "RtnSessionInfoTopic CallbackData",
    this.RtnServletInfoTopic = "RtnServletInfoTopic CallbackData",
    this.RtnFileInfoTopic = "RtnFileInfoTopic CallbackData",
    this.RtnWebAppInfoTopic = "RtnWebAppInfoTopic CallbackData",
    this.RspQryDBQueryTopic = "RspQryDBQueryTopic CallbackData",
    this.RtnDBQueryTopic = "RtnDBQueryTopic CallbackData",
    this.RspQryGeneralFieldTopic = "RspQryGeneralFieldTopic CallbackData",
    this.RtnGeneralFieldTopic = "RtnGeneralFieldTopic CallbackData",
    this.RspQryGetFileTopic = "RspQryGetFileTopic CallbackData",
    this.RspQryWarningQueryTopic = "RspQryWarningQueryTopic CallbackData",
    this.RtnWarningActiveChange = "RtnWarningActiveChange CallbackData",
    this.RspQryTradeUserLoginStatTopic = "RspQryTradeUserLoginStatTopic CallbackData",
    this.RspQryGeneralOperateTopic = "RspQryGeneralOperateTopic CallbackData",
    this.RtnGeneralOperateTopic = "RtnGeneralOperateTopic CallbackData",
    this.RspQryNetDeviceLinkedTopic = "RspQryNetDeviceLinkedTopic CallbackData",
    this.RtnNetDeviceLinkedTopic = "RtnNetDeviceLinkedTopic CallbackData",
    this.RspQryNetAreaTopic = "RspQryNetAreaTopic CallbackData",
    this.RtnNetAreaTopic = "RtnNetAreaTopic CallbackData",
    this.RspQryNetSubAreaTopic = "RspQryNetSubAreaTopic CallbackData",
    this.RtnNetSubAreaTopic = "RtnNetSubAreaTopic CallbackData",
    this.RspQryNetSubAreaIPTopic = "RspQryNetSubAreaIPTopic CallbackData",
    this.RtnNetSubAreaIPTopic = "RtnNetSubAreaIPTopic CallbackData",
    this.RspQryNetDeviceDetectTopic = "RspQryNetDeviceDetectTopic CallbackData",
    this.RtnNetDeviceTopic = "RtnNetDeviceTopic CallbackData",
    this.RspQryNetDeviceTopic = "RspQryNetDeviceTopic CallbackData",
    this.RspQryNetBuildingTopic = "RspQryNetBuildingTopic CallbackData",
    this.RtnNetBuildingTopic = "RtnNetBuildingTopic CallbackData",
    this.RspQryNetRoomTopic = "RspQryNetRoomTopic CallbackData",
    this.RtnNetRoomTopic = "RtnNetRoomTopic CallbackData",
    this.RspQryNetCabinetsTopic = "RspQryNetCabinetsTopic CallbackData",
    this.RtnNetCabinetsTopic = "RtnNetCabinetsTopic CallbackData",
    this.RspQryNetOIDTopic = "RspQryNetOIDTopic CallbackData",
    this.RtnNetOIDTopic = "RtnNetOIDTopic CallbackData",
    this.RspQryNetTimePolicyTopic = "RspQryNetTimePolicyTopic CallbackData",
    this.RtnNetTimePolicyTopic = "RtnNetTimePolicyTopic CallbackData",
    this.RspQryNetGatherTaskTopic = "RspQryNetGatherTaskTopic CallbackData",
    this.RtnNetGatherTaskTopic = "RtnNetGatherTaskTopic CallbackData",
    this.RspQryNetDeviceChgTopic = "RspQryNetDeviceChgTopic CallbackData",
    this.RtnNetDeviceChgTopic = "RtnNetDeviceChgTopic CallbackData",
    this.RspQryNetDeviceTypeTopic = "RspQryNetDeviceTypeTopic CallbackData",
    this.RtnNetDeviceTypeTopic = "RtnNetDeviceTypeTopic CallbackData",
    this.RspQryNetDeviceCategoryTopic = "RspQryNetDeviceCategoryTopic CallbackData",
    this.RtnNetDeviceCategoryTopic = "RtnNetDeviceCategoryTopic CallbackData",
    this.RspQryNetManufactoryTopic = "RspQryNetManufactoryTopic CallbackData",
    this.RtnNetManufactoryTopic = "RtnNetManufactoryTopic CallbackData",
    this.RspQryNetCommunityTopic = "RspQryNetCommunityTopic CallbackData",
    this.RtnNetCommunityTopic = "RtnNetCommunityTopic CallbackData",
    this.RspQryNetPortTypeTopic = "RspQryNetPortTypeTopic CallbackData",
    this.RtnNetPortTypeTopic = "RtnNetPortTypeTopic CallbackData",
    this.RspQryNetPartAccessSpotTopic = "RspQryNetPartAccessSpotTopic CallbackData",
    this.RtnNetPartAccessSpotTopic = "RtnNetPartAccessSpotTopic CallbackData",
    this.RspQryNetInterfaceTopic = "RspQryNetInterfaceTopic CallbackData",
    this.RtnNetInterfaceTopic = "RtnNetInterfaceTopic CallbackData",
    this.RspQryNetGeneralOIDTopic = "RspQryNetGeneralOIDTopic CallbackData",
    this.RtnNetGeneralOIDTopic = "RtnNetGeneralOIDTopic CallbackData",
    this.RspQryNetMonitorTypeTopic = "RspQryNetMonitorTypeTopic CallbackData",
    this.RtnNetMonitorTypeTopic = "RtnNetMonitorTypeTopic CallbackData",
    this.RspQryNetMonitorAttrScopeTopic = "RspQryNetMonitorAttrScopeTopic CallbackData",
    this.RtnNetMonitorAttrScopeTopic = "RtnNetMonitorAttrScopeTopic CallbackData",
    this.RspQryNetMonitorAttrTypeTopic = "RspQryNetMonitorAttrTypeTopic CallbackData",
    this.RtnNetMonitorAttrTypeTopic = "RtnNetMonitorAttrTypeTopic CallbackData",
    this.RspQryNetMonitorObjectAttrTopic = "RspQryNetMonitorObjectAttrTopic CallbackData",
    this.RtnNetMonitorObjectAttrTopic = "RtnNetMonitorObjectAttrTopic CallbackData",
    this.RspQryNetMonitorTaskResultTopic = "RspQryNetMonitorTaskResultTopic CallbackData",
    this.RtnNetMonitorTaskResultTopic = "RtnNetMonitorTaskResultTopic CallbackData",
    this.RspQryNetMonitorDeviceGroupTopic = "RspQryNetMonitorDeviceGroupTopic CallbackData",
    this.RtnNetMonitorDeviceGroupTopic = "RtnNetMonitorDeviceGroupTopic CallbackData",
    this.RspQryNetMonitorTaskObjectSetTopic = "RspQryNetMonitorTaskObjectSetTopic CallbackData",
    this.RtnNetMonitorTaskObjectSetTopic = "RtnNetMonitorTaskObjectSetTopic CallbackData",
    this.RspQryNetMonitorTaskInfoTopic = "RspQryNetMonitorTaskInfoTopic CallbackData",
    this.RtnNetMonitorTaskInfoTopic = "RtnNetMonitorTaskInfoTopic CallbackData",
    this.RspQryNetPartyLinkInfoTopic = "RspQryNetPartyLinkInfoTopic CallbackData",
    this.RtnNetPartyLinkInfoTopic = "RtnNetPartyLinkInfoTopic CallbackData",
    this.RspQryNetMonitorActionAttrTopic = "RspQryNetMonitorActionAttrTopic CallbackData",
    this.RtnNetMonitorActionAttrTopic = "RtnNetMonitorActionAttrTopic CallbackData",
    this.RspQryNetModuleTopic = "RspQryNetModuleTopic CallbackData",
    this.RtnNetModuleTopic = "RtnNetModuleTopic CallbackData",
    this.RspQryNetMonitorTaskStatusResultTopic = "RspQryNetMonitorTaskStatusResultTopic CallbackData",
    this.RtnNetMonitorTaskStatusResultTopic = "RtnNetMonitorTaskStatusResultTopic CallbackData",
    this.RspQryNetCfgFileTopic = "RspQryNetCfgFileTopic CallbackData",
    this.RtnNetCfgFileTopic = "RtnNetCfgFileTopic CallbackData",
    this.RspQryFileGeneralOperTopic = "RspQryFileGeneralOperTopic CallbackData",
    this.RtnFileGeneralOperTopic = "RtnFileGeneralOperTopic CallbackData",
    this.RspQryNetPartyLinkStatusInfoTopic = "RspQryNetPartyLinkStatusInfoTopic CallbackData",
    this.RtnNetPartyLinkStatusInfoTopic = "RtnNetPartyLinkStatusInfoTopic CallbackData",
    this.RspQryNetBaseLineTopic = "RspQryNetBaseLineTopic CallbackData",
    this.RtnNetBaseLineTopic = "RtnNetBaseLineTopic CallbackData",
    this.RspQryNetBaseLineResultTopic = "RspQryNetBaseLineResultTopic CallbackData",
    this.RtnNetBaseLineResultTopic = "RtnNetBaseLineResultTopic CallbackData",
    this.RspQryNetMonitorDeviceTaskTopic = "RspQryNetMonitorDeviceTaskTopic CallbackData",
    this.RtnNetMonitorDeviceTaskTopic = "RtnNetMonitorDeviceTaskTopic CallbackData",
    this.RspQryNetLocalPingResultInfoTopic = "RspQryNetLocalPingResultInfoTopic CallbackData",
    this.RtnNetLocalPingResultInfoTopic = "RtnNetLocalPingResultInfoTopic CallbackData",
    this.RspQryNetRomotePingResultInfoTopic = "RspQryNetRomotePingResultInfoTopic CallbackData",
    this.RtnNetRomotePingResultInfoTopic = "RtnNetRomotePingResultInfoTopic CallbackData",
    this.RspQryTradeFrontOrderRttStatTopic = "RspQryTradeFrontOrderRttStatTopic CallbackData",
    this.RtnTradeFrontOrderRttStatTopic = "RtnTradeFrontOrderRttStatTopic CallbackData",
    this.RspQryDiskIOTopic = "RspQryDiskIOTopic CallbackData",
    this.RtnDiskIOTopic = "RtnDiskIOTopic CallbackData",
    this.RspQryRouterInfoTopic = "RspQryRouterInfoTopic CallbackData",
    this.RtnRouterInfoTopic = "RtnRouterInfoTopic CallbackData",
    this.RspQryStatInfoTopic = "RspQryStatInfoTopic CallbackData",
    this.RtnStatInfoTopic = "RtnStatInfoTopic CallbackData",
    this.RspQryClientInfoTopic = "RspQryClientInfoTopic CallbackData",
    this.RtnClientInfoTopic = "RtnClientInfoTopic CallbackData",
    this.RspQryParticTradeOrderStatesTopic = "RspQryParticTradeOrderStatesTopic CallbackData",
    this.RtnParticTradeOrderStatesTopic = "RtnParticTradeOrderStatesTopic CallbackData",
    this.RspQryTradeOrderRttCutLineTopic = "RspQryTradeOrderRttCutLineTopic CallbackData",
    this.RtnTradeOrderRttCutLineTopic = "RtnTradeOrderRttCutLineTopic CallbackData",
    this.RspQryEventDescriptionTopic = "RspQryEventDescriptionTopic CallbackData",
    this.RtnEventDescriptionTopic = "RtnEventDescriptionTopic CallbackData",
    this.RspQryFrontUniqueIDTopic = "RspQryFrontUniqueIDTopic CallbackData",
    this.RtnFrontUniqueIDTopic = "RtnFrontUniqueIDTopic CallbackData",
    this.RspQryNetPartyLinkAddrChangeTopic = "RspQryNetPartyLinkAddrChangeTopic CallbackData",
    this.RtnNetPartyLinkAddrChangeTopic = "RtnNetPartyLinkAddrChangeTopic CallbackData",
    this.RspQryNetDelPartyLinkInfoTopic = "RspQryNetDelPartyLinkInfoTopic CallbackData",
    this.RtnNetDelPartyLinkInfoTopic = "RtnNetDelPartyLinkInfoTopic CallbackData",
    this.RspQryInstrumentStatusTopic = "RspQryInstrumentStatusTopic CallbackData",
    this.RtnInstrumentStatusTopic = "RtnInstrumentStatusTopic CallbackData",
    this.RspQryCurrTradingSegmentAttrTopic = "RspQryCurrTradingSegmentAttrTopic CallbackData",
    this.RtnCurrTradingSegmentAttrTopic = "RtnCurrTradingSegmentAttrTopic CallbackData",
    this.RspQryPerformanceTopTopic = "RspQryPerformanceTopTopic CallbackData",
    this.RtnPerformanceTopTopic = "RtnPerformanceTopTopic CallbackData",
    this.END = "END"
};

module.exports = new events();
