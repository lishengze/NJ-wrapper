
 #ifndef SPICFUNC_H
 #define SPICFUNC_H


 #include "nan.h"

 extern Nan::Persistent<v8::Object> SpiObj;

 extern uv_async_t async;
 void print_progress(uv_async_t *handle);

 //////这些为手工添加///////////////

 extern uv_async_t asyncOnFrontDisconnected;
 void OnFrontDisconnected(uv_async_t *handle);

 extern uv_async_t asyncOnHeartBeatWarning;
 void OnHeartBeatWarning(uv_async_t *handle);

 /////以下为自动生成///////////////////

 extern uv_async_t asyncOnRspQryTopCpuInfoTopic;
 void OnRspQryTopCpuInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnTopCpuInfoTopic;
 void OnRtnTopCpuInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryTopMemInfoTopic;
 void OnRspQryTopMemInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnTopMemInfoTopic;
 void OnRtnTopMemInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryTopProcessInfoTopic;
 void OnRspQryTopProcessInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnTopProcessInfoTopic;
 void OnRtnTopProcessInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryFileSystemInfoTopic;
 void OnRspQryFileSystemInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnFileSystemInfoTopic;
 void OnRtnFileSystemInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetworkInfoTopic;
 void OnRspQryNetworkInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetworkInfoTopic;
 void OnRtnNetworkInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryClientLoginTopic;
 void OnRspQryClientLoginTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryMonitorObjectTopic;
 void OnRspQryMonitorObjectTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnMonitorObjectTopic;
 void OnRtnMonitorObjectTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryObjectRationalTopic;
 void OnRspQryObjectRationalTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnObjectRationalTopic;
 void OnRtnObjectRationalTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQrySyslogInfoTopic;
 void OnRspQrySyslogInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnSyslogInfoTopic;
 void OnRtnSyslogInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQrySubscriberTopic;
 void OnRspQrySubscriberTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryOidRelationTopic;
 void OnRspQryOidRelationTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnOidRelationTopic;
 void OnRtnOidRelationTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryUserInfoTopic;
 void OnRspQryUserInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnUserInfoTopic;
 void OnRtnUserInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryOnlineUserInfoTopic;
 void OnRspQryOnlineUserInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnOnlineUserInfoTopic;
 void OnRtnOnlineUserInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryWarningEventTopic;
 void OnRspQryWarningEventTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnWarningEventTopic;
 void OnRtnWarningEventTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryCPUUsageTopic;
 void OnRspQryCPUUsageTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnCPUUsageTopic;
 void OnRtnCPUUsageTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryMemoryUsageTopic;
 void OnRspQryMemoryUsageTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnMemoryUsageTopic;
 void OnRtnMemoryUsageTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryDiskUsageTopic;
 void OnRspQryDiskUsageTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnDiskUsageTopic;
 void OnRtnDiskUsageTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryObjectAttrTopic;
 void OnRspQryObjectAttrTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnObjectAttrTopic;
 void OnRtnObjectAttrTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryInvalidateOrderTopic;
 void OnRspQryInvalidateOrderTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnInvalidateOrderTopic;
 void OnRtnInvalidateOrderTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryOrderStatusTopic;
 void OnRspQryOrderStatusTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnOrderStatusTopic;
 void OnRtnOrderStatusTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryBargainOrderTopic;
 void OnRspQryBargainOrderTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnBargainOrderTopic;
 void OnRtnBargainOrderTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryInstPropertyTopic;
 void OnRspQryInstPropertyTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnInstPropertyTopic;
 void OnRtnInstPropertyTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryMarginRateTopic;
 void OnRspQryMarginRateTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnMarginRateTopic;
 void OnRtnMarginRateTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryPriceLimitTopic;
 void OnRspQryPriceLimitTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnPriceLimitTopic;
 void OnRtnPriceLimitTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryPartPosiLimitTopic;
 void OnRspQryPartPosiLimitTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnPartPosiLimitTopic;
 void OnRtnPartPosiLimitTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryClientPosiLimitTopic;
 void OnRspQryClientPosiLimitTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnClientPosiLimitTopic;
 void OnRtnClientPosiLimitTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQrySpecialPosiLimitTopic;
 void OnRspQrySpecialPosiLimitTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnSpecialPosiLimitTopic;
 void OnRtnSpecialPosiLimitTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryTransactionChgTopic;
 void OnRspQryTransactionChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnTransactionChgTopic;
 void OnRtnTransactionChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryClientChgTopic;
 void OnRspQryClientChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnClientChgTopic;
 void OnRtnClientChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryPartClientChgTopic;
 void OnRspQryPartClientChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnPartClientChgTopic;
 void OnRtnPartClientChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryPosiLimitChgTopic;
 void OnRspQryPosiLimitChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnPosiLimitChgTopic;
 void OnRtnPosiLimitChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryHedgeDetailChgTopic;
 void OnRspQryHedgeDetailChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnHedgeDetailChgTopic;
 void OnRtnHedgeDetailChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryParticipantChgTopic;
 void OnRspQryParticipantChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnParticipantChgTopic;
 void OnRtnParticipantChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryMarginRateChgTopic;
 void OnRspQryMarginRateChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnMarginRateChgTopic;
 void OnRtnMarginRateChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryUserIpChgTopic;
 void OnRspQryUserIpChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnUserIpChgTopic;
 void OnRtnUserIpChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryClientPosiLimitChgTopic;
 void OnRspQryClientPosiLimitChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnClientPosiLimitChgTopic;
 void OnRtnClientPosiLimitChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQrySpecPosiLimitChgTopic;
 void OnRspQrySpecPosiLimitChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnSpecPosiLimitChgTopic;
 void OnRtnSpecPosiLimitChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryHistoryObjectAttrTopic;
 void OnRspQryHistoryObjectAttrTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnHistoryObjectAttrTopic;
 void OnRtnHistoryObjectAttrTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryFrontInfoTopic;
 void OnRspQryFrontInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnFrontInfoTopic;
 void OnRtnFrontInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQrySysUserLoginTopic;
 void OnRspQrySysUserLoginTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQrySysUserLogoutTopic;
 void OnRspQrySysUserLogoutTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQrySysUserPasswordUpdateTopic;
 void OnRspQrySysUserPasswordUpdateTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQrySysUserRegisterTopic;
 void OnRspQrySysUserRegisterTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQrySysUserDeleteTopic;
 void OnRspQrySysUserDeleteTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryParticipantInitTopic;
 void OnRspQryParticipantInitTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnParticipantInitTopic;
 void OnRtnParticipantInitTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryUserInitTopic;
 void OnRspQryUserInitTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnUserInitTopic;
 void OnRtnUserInitTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryClientInitTopic;
 void OnRspQryClientInitTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnClientInitTopic;
 void OnRtnClientInitTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryTradeLogTopic;
 void OnRspQryTradeLogTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnTradeLogTopic;
 void OnRtnTradeLogTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryTradeUserLoginInfoTopic;
 void OnRspQryTradeUserLoginInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnTradeUserLoginInfoTopic;
 void OnRtnTradeUserLoginInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryPartTradeTopic;
 void OnRspQryPartTradeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryTradepeakTopic;
 void OnRspQryTradepeakTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnUpdateSysConfigTopic;
 void OnRtnUpdateSysConfigTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnSysUser;
 void OnRtnSysUser(uv_async_t *handle);

 extern uv_async_t asyncOnRtnPriceLimitChgTopic;
 void OnRtnPriceLimitChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryHistoryCpuInfoTopic;
 void OnRspQryHistoryCpuInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryHistoryMemInfoTopic;
 void OnRspQryHistoryMemInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryHistoryNetworkInfoTopic;
 void OnRspQryHistoryNetworkInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryMonitorOnlineUser;
 void OnRspQryMonitorOnlineUser(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryFrontStat;
 void OnRspQryFrontStat(uv_async_t *handle);

 extern uv_async_t asyncOnRtnSysTimeSyncTopic;
 void OnRtnSysTimeSyncTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnDataCenterChgTopic;
 void OnRtnDataCenterChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryHistoryTradePeakTopic;
 void OnRspQryHistoryTradePeakTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnHistoryTradePeakTopic;
 void OnRtnHistoryTradePeakTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQrySyslogEventTopic;
 void OnRspQrySyslogEventTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnSyslogEventTopic;
 void OnRtnSyslogEventTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryTradeDayChangeTopic;
 void OnRspQryTradeDayChangeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryWebAppInfoTopic;
 void OnRspQryWebAppInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnWebAppInfoTopic;
 void OnRtnWebAppInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryServletInfoTopic;
 void OnRspQryServletInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnServletInfoTopic;
 void OnRtnServletInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryFileInfoTopic;
 void OnRspQryFileInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnFileInfoTopic;
 void OnRtnFileInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQrySessionInfoTopic;
 void OnRspQrySessionInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnSessionInfoTopic;
 void OnRtnSessionInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryJDBCInfoTopic;
 void OnRspQryJDBCInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnJDBCInfoTopic;
 void OnRtnJDBCInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryThreadInfoTopic;
 void OnRspQryThreadInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnThreadInfoTopic;
 void OnRtnThreadInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryVMInfoTopic;
 void OnRspQryVMInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnVMInfoTopic;
 void OnRtnVMInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryPropertyInfoTopic;
 void OnRspQryPropertyInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnPropertyInfoTopic;
 void OnRtnPropertyInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryMemPoolInfoTopic;
 void OnRspQryMemPoolInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnMemPoolInfoTopic;
 void OnRtnMemPoolInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryFileContentInfoTopic;
 void OnRspQryFileContentInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnFileContentInfoTopic;
 void OnRtnFileContentInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryConnectionInfoTopic;
 void OnRspQryConnectionInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnConnectionInfoTopic;
 void OnRtnConnectionInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryConnectorInfoTopic;
 void OnRspQryConnectorInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnConnectorInfoTopic;
 void OnRtnConnectorInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryDBQueryTopic;
 void OnRspQryDBQueryTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnDBQueryTopic;
 void OnRtnDBQueryTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryGeneralFieldTopic;
 void OnRspQryGeneralFieldTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnGeneralFieldTopic;
 void OnRtnGeneralFieldTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryGetFileTopic;
 void OnRspQryGetFileTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryWarningQueryTopic;
 void OnRspQryWarningQueryTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnWarningQueryTopic;
 void OnRtnWarningQueryTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnHostConfig;
 void OnRtnHostConfig(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryGeneralOperateTopic;
 void OnRspQryGeneralOperateTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnGeneralOperateTopic;
 void OnRtnGeneralOperateTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetDeviceLinkedTopic;
 void OnRspQryNetDeviceLinkedTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetDeviceLinkedTopic;
 void OnRtnNetDeviceLinkedTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryTradeUserLoginStatTopic;
 void OnRspQryTradeUserLoginStatTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryTradeFrontOrderRttStatTopic;
 void OnRspQryTradeFrontOrderRttStatTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnTradeFrontOrderRttStatTopic;
 void OnRtnTradeFrontOrderRttStatTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryParticTradeOrderStatesTopic;
 void OnRspQryParticTradeOrderStatesTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnParticTradeOrderStatesTopic;
 void OnRtnParticTradeOrderStatesTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryRouterInfoTopic;
 void OnRspQryRouterInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnRouterInfoTopic;
 void OnRtnRouterInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryDiskIOTopic;
 void OnRspQryDiskIOTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnDiskIOTopic;
 void OnRtnDiskIOTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryStatInfoTopic;
 void OnRspQryStatInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnStatInfoTopic;
 void OnRtnStatInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryTradeOrderRttCutLineTopic;
 void OnRspQryTradeOrderRttCutLineTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnTradeOrderRttCutLineTopic;
 void OnRtnTradeOrderRttCutLineTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryClientInfoTopic;
 void OnRspQryClientInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnClientInfoTopic;
 void OnRtnClientInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryEventDescriptionTopic;
 void OnRspQryEventDescriptionTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnEventDescriptionTopic;
 void OnRtnEventDescriptionTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryFrontUniqueIDTopic;
 void OnRspQryFrontUniqueIDTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnFrontUniqueIDTopic;
 void OnRtnFrontUniqueIDTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetPartyLinkAddrChangeTopic;
 void OnRspQryNetPartyLinkAddrChangeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetPartyLinkAddrChangeTopic;
 void OnRtnNetPartyLinkAddrChangeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetDelPartyLinkInfoTopic;
 void OnRspQryNetDelPartyLinkInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetDelPartyLinkInfoTopic;
 void OnRtnNetDelPartyLinkInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryPerformanceTopTopic;
 void OnRspQryPerformanceTopTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnPerformanceTopTopic;
 void OnRtnPerformanceTopTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryInstrumentStatusTopic;
 void OnRspQryInstrumentStatusTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnInstrumentStatusTopic;
 void OnRtnInstrumentStatusTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryCurrTradingSegmentAttrTopic;
 void OnRspQryCurrTradingSegmentAttrTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnCurrTradingSegmentAttrTopic;
 void OnRtnCurrTradingSegmentAttrTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetAreaTopic;
 void OnRspQryNetAreaTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetAreaTopic;
 void OnRtnNetAreaTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetSubAreaTopic;
 void OnRspQryNetSubAreaTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetSubAreaTopic;
 void OnRtnNetSubAreaTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetSubAreaIPTopic;
 void OnRspQryNetSubAreaIPTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetSubAreaIPTopic;
 void OnRtnNetSubAreaIPTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetDeviceTopic;
 void OnRspQryNetDeviceTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetDeviceTopic;
 void OnRtnNetDeviceTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetDeviceDetectTopic;
 void OnRspQryNetDeviceDetectTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetBuildingTopic;
 void OnRspQryNetBuildingTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetBuildingTopic;
 void OnRtnNetBuildingTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetRoomTopic;
 void OnRspQryNetRoomTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetRoomTopic;
 void OnRtnNetRoomTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetCabinetsTopic;
 void OnRspQryNetCabinetsTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetCabinetsTopic;
 void OnRtnNetCabinetsTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetOIDTopic;
 void OnRspQryNetOIDTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetOIDTopic;
 void OnRtnNetOIDTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetTimePolicyTopic;
 void OnRspQryNetTimePolicyTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetTimePolicyTopic;
 void OnRtnNetTimePolicyTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetGatherTaskTopic;
 void OnRspQryNetGatherTaskTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetGatherTaskTopic;
 void OnRtnNetGatherTaskTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetDeviceChgTopic;
 void OnRspQryNetDeviceChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetDeviceChgTopic;
 void OnRtnNetDeviceChgTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetDeviceTypeTopic;
 void OnRspQryNetDeviceTypeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetDeviceTypeTopic;
 void OnRtnNetDeviceTypeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetDeviceCategoryTopic;
 void OnRspQryNetDeviceCategoryTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetDeviceCategoryTopic;
 void OnRtnNetDeviceCategoryTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetManufactoryTopic;
 void OnRspQryNetManufactoryTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetManufactoryTopic;
 void OnRtnNetManufactoryTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetCommunityTopic;
 void OnRspQryNetCommunityTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetCommunityTopic;
 void OnRtnNetCommunityTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetPortTypeTopic;
 void OnRspQryNetPortTypeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetPortTypeTopic;
 void OnRtnNetPortTypeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetPartAccessSpotTopic;
 void OnRspQryNetPartAccessSpotTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetPartAccessSpotTopic;
 void OnRtnNetPartAccessSpotTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetInterfaceTopic;
 void OnRspQryNetInterfaceTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetInterfaceTopic;
 void OnRtnNetInterfaceTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetGeneralOIDTopic;
 void OnRspQryNetGeneralOIDTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetGeneralOIDTopic;
 void OnRtnNetGeneralOIDTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetMonitorTypeTopic;
 void OnRspQryNetMonitorTypeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetMonitorTypeTopic;
 void OnRtnNetMonitorTypeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetMonitorAttrScopeTopic;
 void OnRspQryNetMonitorAttrScopeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetMonitorAttrScopeTopic;
 void OnRtnNetMonitorAttrScopeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetMonitorAttrTypeTopic;
 void OnRspQryNetMonitorAttrTypeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetMonitorAttrTypeTopic;
 void OnRtnNetMonitorAttrTypeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetMonitorObjectAttrTopic;
 void OnRspQryNetMonitorObjectAttrTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetMonitorObjectAttrTopic;
 void OnRtnNetMonitorObjectAttrTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetFuncAreaTopic;
 void OnRspQryNetFuncAreaTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetFuncAreaTopic;
 void OnRtnNetFuncAreaTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetMonitorCommandTypeTopic;
 void OnRspQryNetMonitorCommandTypeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetMonitorCommandTypeTopic;
 void OnRtnNetMonitorCommandTypeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetMonitorActionGroupTopic;
 void OnRspQryNetMonitorActionGroupTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetMonitorActionGroupTopic;
 void OnRtnNetMonitorActionGroupTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetMonitorDeviceGroupTopic;
 void OnRspQryNetMonitorDeviceGroupTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetMonitorDeviceGroupTopic;
 void OnRtnNetMonitorDeviceGroupTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetMonitorTaskInfoTopic;
 void OnRspQryNetMonitorTaskInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetMonitorTaskInfoTopic;
 void OnRtnNetMonitorTaskInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetMonitorTaskResultTopic;
 void OnRspQryNetMonitorTaskResultTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetMonitorTaskResultTopic;
 void OnRtnNetMonitorTaskResultTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetMonitorTaskObjectSetTopic;
 void OnRspQryNetMonitorTaskObjectSetTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetMonitorTaskObjectSetTopic;
 void OnRtnNetMonitorTaskObjectSetTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetPartyLinkInfoTopic;
 void OnRspQryNetPartyLinkInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetPartyLinkInfoTopic;
 void OnRtnNetPartyLinkInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetMonitorActionAttrTopic;
 void OnRspQryNetMonitorActionAttrTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetMonitorActionAttrTopic;
 void OnRtnNetMonitorActionAttrTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetModuleTopic;
 void OnRspQryNetModuleTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetModuleTopic;
 void OnRtnNetModuleTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetEventExprTopic;
 void OnRspQryNetEventExprTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetEventExprTopic;
 void OnRtnNetEventExprTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetEventTypeTopic;
 void OnRspQryNetEventTypeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetEventTypeTopic;
 void OnRtnNetEventTypeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetSubEventTypeTopic;
 void OnRspQryNetSubEventTypeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetSubEventTypeTopic;
 void OnRtnNetSubEventTypeTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetEventLevelTopic;
 void OnRspQryNetEventLevelTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetEventLevelTopic;
 void OnRtnNetEventLevelTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetMonitorTaskStatusResultTopic;
 void OnRspQryNetMonitorTaskStatusResultTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetMonitorTaskStatusResultTopic;
 void OnRtnNetMonitorTaskStatusResultTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetCfgFileTopic;
 void OnRspQryNetCfgFileTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetCfgFileTopic;
 void OnRtnNetCfgFileTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetMonitorDeviceTaskTopic;
 void OnRspQryNetMonitorDeviceTaskTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetMonitorDeviceTaskTopic;
 void OnRtnNetMonitorDeviceTaskTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetMonitorTaskInstAttrsTopic;
 void OnRspQryNetMonitorTaskInstAttrsTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetMonitorTaskInstAttrsTopic;
 void OnRtnNetMonitorTaskInstAttrsTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryFileGeneralOperTopic;
 void OnRspQryFileGeneralOperTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnFileGeneralOperTopic;
 void OnRtnFileGeneralOperTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetBaseLineTopic;
 void OnRspQryNetBaseLineTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetBaseLineTopic;
 void OnRtnNetBaseLineTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetBaseLineTaskTopic;
 void OnRspQryNetBaseLineTaskTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetBaseLineTaskTopic;
 void OnRtnNetBaseLineTaskTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetBaseLineResultTopic;
 void OnRspQryNetBaseLineResultTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetBaseLineResultTopic;
 void OnRtnNetBaseLineResultTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetPartyLinkStatusInfoTopic;
 void OnRspQryNetPartyLinkStatusInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetPartyLinkStatusInfoTopic;
 void OnRtnNetPartyLinkStatusInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetMemberSDHLineInfoTopic;
 void OnRspQryNetMemberSDHLineInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetMemberSDHLineInfoTopic;
 void OnRtnNetMemberSDHLineInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetDDNLinkInfoTopic;
 void OnRspQryNetDDNLinkInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetDDNLinkInfoTopic;
 void OnRtnNetDDNLinkInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetPseudMemberLinkInfoTopic;
 void OnRspQryNetPseudMemberLinkInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetPseudMemberLinkInfoTopic;
 void OnRtnNetPseudMemberLinkInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryOuterDeviceInfTopic;
 void OnRspQryOuterDeviceInfTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetOuterDeviceInfTopic;
 void OnRtnNetOuterDeviceInfTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetLocalPingResultInfoTopic;
 void OnRspQryNetLocalPingResultInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetLocalPingResultInfoTopic;
 void OnRtnNetLocalPingResultInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetRomotePingResultInfoTopic;
 void OnRspQryNetRomotePingResultInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetRomotePingResultInfoTopic;
 void OnRtnNetRomotePingResultInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnMonitorTopProcessInfo;
 void OnRtnMonitorTopProcessInfo(uv_async_t *handle);

 extern uv_async_t asyncOnRspQrySysInternalTopologyTopic;
 void OnRspQrySysInternalTopologyTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnSysInternalTopologyTopic;
 void OnRtnSysInternalTopologyTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryMemberLinkCostTopic;
 void OnRspQryMemberLinkCostTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnMemberLinkCostTopic;
 void OnRtnMemberLinkCostTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetPartylinkMonthlyRentTopic;
 void OnRspQryNetPartylinkMonthlyRentTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetPartylinkMonthlyRentTopic;
 void OnRtnNetPartylinkMonthlyRentTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRspQryNetNonPartyLinkInfoTopic;
 void OnRspQryNetNonPartyLinkInfoTopic(uv_async_t *handle);

 extern uv_async_t asyncOnRtnNetNonPartyLinkInfoTopic;
 void OnRtnNetNonPartyLinkInfoTopic(uv_async_t *handle);



#endif