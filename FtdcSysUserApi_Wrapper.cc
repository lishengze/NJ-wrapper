
 #include "FtdcSysUserApi_Wrapper.h"
 #include <nan.h>
 #include "SysUserSpi.h"
 #include "SpiCFunc.h"
 #include "FtdcSysUserApiStruct.h"
 #include <iostream>
 #include <string.h>
 #include "CCrypto.h"

 using namespace v8;

 Nan::Persistent<Function> FtdcSysUserApi_Wrapper::constructor;

 FtdcSysUserApi_Wrapper::FtdcSysUserApi_Wrapper(const char *pszFlowPath)
 {
 _userApi=CShfeFtdcSysUserApi::CreateFtdcSysUserApi(pszFlowPath);
 _spi=new SysUserSpi();
 }

 FtdcSysUserApi_Wrapper::~FtdcSysUserApi_Wrapper() {
 _userApi->Release();
 delete _spi;
 uv_close((uv_handle_t*) &async, NULL);
    uv_close((uv_handle_t*) &asyncOnRspQryTopCpuInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnTopCpuInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryTopMemInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnTopMemInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryTopProcessInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnTopProcessInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryFileSystemInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnFileSystemInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetworkInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetworkInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryClientLoginTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryMonitorObjectTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnMonitorObjectTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryObjectRationalTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnObjectRationalTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQrySyslogInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnSyslogInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQrySubscriberTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryOidRelationTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnOidRelationTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryUserInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnUserInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryOnlineUserInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnOnlineUserInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryWarningEventTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnWarningEventTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryCPUUsageTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnCPUUsageTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryMemoryUsageTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnMemoryUsageTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryDiskUsageTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnDiskUsageTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryObjectAttrTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnObjectAttrTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryInvalidateOrderTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnInvalidateOrderTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryOrderStatusTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnOrderStatusTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryBargainOrderTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnBargainOrderTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryInstPropertyTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnInstPropertyTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryMarginRateTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnMarginRateTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryPriceLimitTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnPriceLimitTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryPartPosiLimitTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnPartPosiLimitTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryClientPosiLimitTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnClientPosiLimitTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQrySpecialPosiLimitTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnSpecialPosiLimitTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryTransactionChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnTransactionChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryClientChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnClientChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryPartClientChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnPartClientChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryPosiLimitChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnPosiLimitChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryHedgeDetailChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnHedgeDetailChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryParticipantChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnParticipantChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryMarginRateChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnMarginRateChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryUserIpChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnUserIpChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryClientPosiLimitChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnClientPosiLimitChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQrySpecPosiLimitChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnSpecPosiLimitChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryHistoryObjectAttrTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnHistoryObjectAttrTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryFrontInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnFrontInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQrySysUserLoginTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQrySysUserLogoutTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQrySysUserPasswordUpdateTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQrySysUserRegisterTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQrySysUserDeleteTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryParticipantInitTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnParticipantInitTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryUserInitTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnUserInitTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryClientInitTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnClientInitTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryTradeLogTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnTradeLogTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryTradeUserLoginInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnTradeUserLoginInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryPartTradeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryTradepeakTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnUpdateSysConfigTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnSysUser,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnPriceLimitChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryHistoryCpuInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryHistoryMemInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryHistoryNetworkInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryMonitorOnlineUser,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryFrontStat,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnSysTimeSyncTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnDataCenterChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryHistoryTradePeakTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnHistoryTradePeakTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQrySyslogEventTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnSyslogEventTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryTradeDayChangeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryWebAppInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnWebAppInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryServletInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnServletInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryFileInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnFileInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQrySessionInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnSessionInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryJDBCInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnJDBCInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryThreadInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnThreadInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryVMInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnVMInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryPropertyInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnPropertyInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryMemPoolInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnMemPoolInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryFileContentInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnFileContentInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryConnectionInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnConnectionInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryConnectorInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnConnectorInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryDBQueryTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnDBQueryTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryGeneralFieldTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnGeneralFieldTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryGetFileTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryWarningQueryTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnWarningQueryTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnHostConfig,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryGeneralOperateTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnGeneralOperateTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetDeviceLinkedTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetDeviceLinkedTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryTradeUserLoginStatTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryTradeFrontOrderRttStatTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnTradeFrontOrderRttStatTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryParticTradeOrderStatesTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnParticTradeOrderStatesTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryRouterInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnRouterInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryDiskIOTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnDiskIOTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryStatInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnStatInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryTradeOrderRttCutLineTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnTradeOrderRttCutLineTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryClientInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnClientInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryEventDescriptionTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnEventDescriptionTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryFrontUniqueIDTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnFrontUniqueIDTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetPartyLinkAddrChangeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetPartyLinkAddrChangeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetDelPartyLinkInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetDelPartyLinkInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryPerformanceTopTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnPerformanceTopTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryInstrumentStatusTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnInstrumentStatusTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryCurrTradingSegmentAttrTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnCurrTradingSegmentAttrTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetAreaTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetAreaTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetSubAreaTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetSubAreaTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetSubAreaIPTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetSubAreaIPTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetDeviceTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetDeviceTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetDeviceDetectTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetBuildingTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetBuildingTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetRoomTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetRoomTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetCabinetsTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetCabinetsTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetOIDTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetOIDTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetTimePolicyTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetTimePolicyTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetGatherTaskTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetGatherTaskTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetDeviceChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetDeviceChgTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetDeviceTypeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetDeviceTypeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetDeviceCategoryTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetDeviceCategoryTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetManufactoryTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetManufactoryTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetCommunityTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetCommunityTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetPortTypeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetPortTypeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetPartAccessSpotTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetPartAccessSpotTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetInterfaceTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetInterfaceTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetGeneralOIDTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetGeneralOIDTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetMonitorTypeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetMonitorTypeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetMonitorAttrScopeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetMonitorAttrScopeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetMonitorAttrTypeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetMonitorAttrTypeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetMonitorObjectAttrTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetMonitorObjectAttrTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetFuncAreaTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetFuncAreaTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetMonitorCommandTypeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetMonitorCommandTypeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetMonitorActionGroupTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetMonitorActionGroupTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetMonitorDeviceGroupTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetMonitorDeviceGroupTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetMonitorTaskInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetMonitorTaskInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetMonitorTaskResultTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetMonitorTaskResultTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetMonitorTaskObjectSetTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetMonitorTaskObjectSetTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetPartyLinkInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetPartyLinkInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetMonitorActionAttrTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetMonitorActionAttrTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetModuleTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetModuleTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetEventExprTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetEventExprTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetEventTypeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetEventTypeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetSubEventTypeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetSubEventTypeTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetEventLevelTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetEventLevelTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetMonitorTaskStatusResultTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetMonitorTaskStatusResultTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetCfgFileTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetCfgFileTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetMonitorDeviceTaskTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetMonitorDeviceTaskTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetMonitorTaskInstAttrsTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetMonitorTaskInstAttrsTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryFileGeneralOperTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnFileGeneralOperTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetBaseLineTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetBaseLineTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetBaseLineTaskTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetBaseLineTaskTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetBaseLineResultTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetBaseLineResultTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetPartyLinkStatusInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetPartyLinkStatusInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetMemberSDHLineInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetMemberSDHLineInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetDDNLinkInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetDDNLinkInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetPseudMemberLinkInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetPseudMemberLinkInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryOuterDeviceInfTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetOuterDeviceInfTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetLocalPingResultInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetLocalPingResultInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetRomotePingResultInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetRomotePingResultInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnMonitorTopProcessInfo,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQrySysInternalTopologyTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnSysInternalTopologyTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryMemberLinkCostTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnMemberLinkCostTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetPartylinkMonthlyRentTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetPartylinkMonthlyRentTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRspQryNetNonPartyLinkInfoTopic,NULL);
   uv_close((uv_handle_t*) &asyncOnRtnNetNonPartyLinkInfoTopic,NULL);
}

 void FtdcSysUserApi_Wrapper::InitExports(Handle<Object> exports) {
 Nan::HandleScope scope;

 // Prepare constructor template
 Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
 tpl->SetClassName(Nan::New<v8::String>("FtdcSysUserApi_Wrapper").ToLocalChecked());
 tpl->InstanceTemplate()->SetInternalFieldCount(1);

 // Prototype
 //NODE_SET_PROTOTYPE_METHOD(tpl, "Init", Init);
 Nan::SetPrototypeMethod(tpl,"Release",Release);
 Nan::SetPrototypeMethod(tpl,"Init",Init);
 Nan::SetPrototypeMethod(tpl,"Join",Join);
 Nan::SetPrototypeMethod(tpl,"GetTradingDay",GetTradingDay);
 Nan::SetPrototypeMethod(tpl,"RegisterFront",RegisterFront);
 Nan::SetPrototypeMethod(tpl,"RegisterSpi",RegisterSpi);
 Nan::SetPrototypeMethod(tpl,"ReqQrySysUserLoginTopic",ReqQrySysUserLoginTopic);

  Nan::SetPrototypeMethod(tpl,"ReqQryTopMemInfoTopic",ReqQryTopMemInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryTopProcessInfoTopic",ReqQryTopProcessInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryFileSystemInfoTopic",ReqQryFileSystemInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetworkInfoTopic",ReqQryNetworkInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryMonitorObjectTopic",ReqQryMonitorObjectTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryObjectRationalTopic",ReqQryObjectRationalTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQrySyslogInfoTopic",ReqQrySyslogInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQrySubscriberTopic",ReqQrySubscriberTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryOidRelationTopic",ReqQryOidRelationTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryUserInfoTopic",ReqQryUserInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryOnlineUserInfoTopic",ReqQryOnlineUserInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryWarningEventTopic",ReqQryWarningEventTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryObjectAttrTopic",ReqQryObjectAttrTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryInvalidateOrderTopic",ReqQryInvalidateOrderTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryOrderStatusTopic",ReqQryOrderStatusTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryBargainOrderTopic",ReqQryBargainOrderTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryInstPropertyTopic",ReqQryInstPropertyTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryMarginRateTopic",ReqQryMarginRateTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryPriceLimitTopic",ReqQryPriceLimitTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryPartPosiLimitTopic",ReqQryPartPosiLimitTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryClientPosiLimitTopic",ReqQryClientPosiLimitTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQrySpecialPosiLimitTopic",ReqQrySpecialPosiLimitTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryTransactionChgTopic",ReqQryTransactionChgTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryClientChgTopic",ReqQryClientChgTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryPartClientChgTopic",ReqQryPartClientChgTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryPosiLimitChgTopic",ReqQryPosiLimitChgTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryHedgeDetailChgTopic",ReqQryHedgeDetailChgTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryParticipantChgTopic",ReqQryParticipantChgTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryMarginRateChgTopic",ReqQryMarginRateChgTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryUserIpChgTopic",ReqQryUserIpChgTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryClientPosiLimitChgTopic",ReqQryClientPosiLimitChgTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQrySpecPosiLimitChgTopic",ReqQrySpecPosiLimitChgTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryHistoryObjectAttrTopic",ReqQryHistoryObjectAttrTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryFrontInfoTopic",ReqQryFrontInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQrySysUserLogoutTopic",ReqQrySysUserLogoutTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQrySysUserPasswordUpdateTopic",ReqQrySysUserPasswordUpdateTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQrySysUserRegisterTopic",ReqQrySysUserRegisterTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQrySysUserDeleteTopic",ReqQrySysUserDeleteTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryTradeLogTopic",ReqQryTradeLogTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryWarningEventUpdateTopic",ReqQryWarningEventUpdateTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryTradeUserLoginInfoTopic",ReqQryTradeUserLoginInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryPartTradeTopic",ReqQryPartTradeTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryTradepeakTopic",ReqQryTradepeakTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryParticipantInitTopic",ReqQryParticipantInitTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryUserInitTopic",ReqQryUserInitTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryHistoryCpuInfoTopic",ReqQryHistoryCpuInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryHistoryMemInfoTopic",ReqQryHistoryMemInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryHistoryNetworkInfoTopic",ReqQryHistoryNetworkInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryHistoryTradePeakTopic",ReqQryHistoryTradePeakTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQrySyslogEventTopic",ReqQrySyslogEventTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQrySyslogEventSubcriberTopic",ReqQrySyslogEventSubcriberTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryTomcatInfoTopic",ReqQryTomcatInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryDBQueryTopic",ReqQryDBQueryTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryGetFileTopic",ReqQryGetFileTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQrySyslogEventUpdateTopic",ReqQrySyslogEventUpdateTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryWarningQueryTopic",ReqQryWarningQueryTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryWebVisitTopic",ReqQryWebVisitTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryGeneralOperateTopic",ReqQryGeneralOperateTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetDeviceLinkedTopic",ReqQryNetDeviceLinkedTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryTradeUserLoginStatTopic",ReqQryTradeUserLoginStatTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryTradeFrontOrderRttStatTopic",ReqQryTradeFrontOrderRttStatTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryParticTradeOrderStatesTopic",ReqQryParticTradeOrderStatesTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryRouterInfoTopic",ReqQryRouterInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryDiskIOTopic",ReqQryDiskIOTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryStatInfoTopic",ReqQryStatInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryTradeOrderRttCutLineTopic",ReqQryTradeOrderRttCutLineTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryClientInfoTopic",ReqQryClientInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryEventDescriptionTopic",ReqQryEventDescriptionTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryFrontUniqueIDTopic",ReqQryFrontUniqueIDTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetPartyLinkAddrChangeTopic",ReqQryNetPartyLinkAddrChangeTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetDelPartyLinkInfoTopic",ReqQryNetDelPartyLinkInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryPerformanceTopTopic",ReqQryPerformanceTopTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryInstrumentStatusTopic",ReqQryInstrumentStatusTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryCurrTradingSegmentAttrTopic",ReqQryCurrTradingSegmentAttrTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryRealTimeNetObjectAttrTopic",ReqQryRealTimeNetObjectAttrTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetAreaTopic",ReqQryNetAreaTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetSubAreaTopic",ReqQryNetSubAreaTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetSubAreaIPTopic",ReqQryNetSubAreaIPTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetDeviceDetectTopic",ReqQryNetDeviceDetectTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetDeviceRequestTopic",ReqQryNetDeviceRequestTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetBuildingTopic",ReqQryNetBuildingTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetRoomTopic",ReqQryNetRoomTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetCabinetsTopic",ReqQryNetCabinetsTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetOIDTopic",ReqQryNetOIDTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetTimePolicyTopic",ReqQryNetTimePolicyTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetGatherTaskTopic",ReqQryNetGatherTaskTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetDeviceChgTopic",ReqQryNetDeviceChgTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetDeviceTypeTopic",ReqQryNetDeviceTypeTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetDeviceCategoryTopic",ReqQryNetDeviceCategoryTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetManufactoryTopic",ReqQryNetManufactoryTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetCommunityTopic",ReqQryNetCommunityTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetPortTypeTopic",ReqQryNetPortTypeTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetPartAccessSpotTopic",ReqQryNetPartAccessSpotTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetInterfaceTopic",ReqQryNetInterfaceTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetGeneralOIDTopic",ReqQryNetGeneralOIDTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorTypeTopic",ReqQryNetMonitorTypeTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorAttrScopeTopic",ReqQryNetMonitorAttrScopeTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorAttrTypeTopic",ReqQryNetMonitorAttrTypeTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorObjectAttrTopic",ReqQryNetMonitorObjectAttrTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorDeviceGroupTopic",ReqQryNetMonitorDeviceGroupTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorTaskInfoTopic",ReqQryNetMonitorTaskInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorTaskResultTopic",ReqQryNetMonitorTaskResultTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorTaskObjectSetTopic",ReqQryNetMonitorTaskObjectSetTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetPartyLinkInfoTopic",ReqQryNetPartyLinkInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorActionAttrTopic",ReqQryNetMonitorActionAttrTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetModuleTopic",ReqQryNetModuleTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorTaskStatusResultTopic",ReqQryNetMonitorTaskStatusResultTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetCfgFileTopic",ReqQryNetCfgFileTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorDeviceTaskTopic",ReqQryNetMonitorDeviceTaskTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryFileGeneralOperTopic",ReqQryFileGeneralOperTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetBaseLineTopic",ReqQryNetBaseLineTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetBaseLineResultTopic",ReqQryNetBaseLineResultTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetPartyLinkStatusInfoTopic",ReqQryNetPartyLinkStatusInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetLocalPingResultInfoTopic",ReqQryNetLocalPingResultInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetRomotePingResultInfoTopic",ReqQryNetRomotePingResultInfoTopic);
 Nan::SetPrototypeMethod(tpl,"ReqQryNetNonPartyLinkInfoTopic",ReqQryNetNonPartyLinkInfoTopic);

 constructor.Reset(tpl->GetFunction());
 //NanAssignPersistent(constructor, tpl->GetFunction());
 exports->Set(Nan::New("FtdcSysUserApi_Wrapper").ToLocalChecked(), tpl->GetFunction());
}

NAN_METHOD(FtdcSysUserApi_Wrapper::New) {
    if (info.IsConstructCall()) {
        // Invoked as constructor: `new FtdcSysUserApi_Wrapper(...)`
        Local<String> str = info[0]->IsUndefined() ? Nan::EmptyString()  : info[0]->ToString();
        String::Utf8Value utf8Str(str);
        FtdcSysUserApi_Wrapper* obj = new FtdcSysUserApi_Wrapper(*utf8Str);
        obj->Wrap(info.This());
        info.GetReturnValue().Set(info.This());
    } else {
        // Invoked as plain function `FtdcSysUserApi_Wrapper(...)`, turn into construct call.
        const int argc = 1;
        Local<Value> argv[argc] = { info[0] };
        Local<Function> cons = Nan::New<Function>(constructor);
        info.GetReturnValue().Set(cons->NewInstance(argc, argv));
    }
}

NAN_METHOD(FtdcSysUserApi_Wrapper::Release) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    obj->_userApi->Release();
    info.GetReturnValue().SetUndefined();
}

NAN_METHOD(FtdcSysUserApi_Wrapper::Init) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    obj->_userApi->Init();
    info.GetReturnValue().SetUndefined();
}

NAN_METHOD(FtdcSysUserApi_Wrapper::Join) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    int result=obj->_userApi->Join();
    info.GetReturnValue().Set(Nan::New<v8::Int32>(result));
}

NAN_METHOD(FtdcSysUserApi_Wrapper::GetTradingDay) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    const char* result=obj->_userApi->GetTradingDay();
    info.GetReturnValue().Set(Nan::New<v8::String>(result).ToLocalChecked());
}

NAN_METHOD(FtdcSysUserApi_Wrapper::RegisterFront) {
    Local<String> str = info[0]->IsUndefined() ? Nan::EmptyString()  : info[0]->ToString();
    String::Utf8Value utf8Str(str);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());

    obj->_userApi->RegisterFront(*utf8Str);

    info.GetReturnValue().SetUndefined();
}

NAN_METHOD(FtdcSysUserApi_Wrapper::RegisterSpi) {
    std::cout<<"RegisterSpi Called!"<<std::endl;
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(info[0]->IsObject())
    {
        //obj->_spi=new SysUserSpi(Nan::To<v8::Object>(info[0]).ToLocalChecked());
        //obj->_userApi->RegisterSpi(obj->_spi);
        SpiObj.Reset(Nan::To<v8::Object>(info[0]).ToLocalChecked());
        obj->_userApi->RegisterSpi(obj->_spi);
    }
    info.GetReturnValue().SetUndefined();
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqUserLogin) {
     std::cout<<"ReqUserLogin Called!"<<std::endl;
     FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
     if(!(info[0]->IsObject() && info[1]->IsNumber()))
     {
     Nan::ThrowError("wrong parameter!");
     }
     //convert parameter one
     v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
     CShfeFtdcReqUserLoginField field;
     //TradingDay
     v8::Local<v8::Object> paramOneTradingDayObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TradingDay").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneTradingDayStr(Nan::To<v8::String>(paramOneTradingDayObj).ToLocalChecked());
     strcpy_s(field.TradingDay, 9, *paramOneTradingDayStr);
     //UserID
     v8::Local<v8::Object> paramOneUserIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneUserIDStr(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
     strcpy_s(field.UserID, 16, *paramOneUserIDStr);
     //ParticipantID
     v8::Local<v8::Object> paramOneParticipantIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ParticipantID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneParticipantIDStr(Nan::To<v8::String>(paramOneParticipantIDObj).ToLocalChecked());
     strcpy_s(field.ParticipantID, 11, *paramOneUserIDStr);
     //Password
     v8::Local<v8::Object> paramOnePasswordObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Password").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOnePasswordStr(Nan::To<v8::String>(paramOnePasswordObj).ToLocalChecked());
     strcpy_s(field.Password, 41, *paramOnePasswordStr);
     //convert parameter two
     v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
     int64_t nRequestID=paramTwo->Value();

     //call natvie method
     double returnValue= obj->_userApi->ReqUserLogin(&field, nRequestID);

     info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
     }
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQrySysUserLoginTopic) {
     std::cout<<"ReqQrySysUserLoginTopic Called!"<<std::endl;
     FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
     if(!(info[0]->IsObject() && info[1]->IsNumber()))
     {
     Nan::ThrowError("wrong parameter!");
     }
     //convert parameter one
     v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
     CShfeFtdcReqQrySysUserLoginField field;
     //UserID
     v8::Local<v8::Object> paramOneUserIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneUserIDStr(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
     strcpy_s(field.UserID, 16, *paramOneUserIDStr);
     std::cout<<*paramOneUserIDStr<<std::endl;
     //Password
     v8::Local<v8::Object> paramOnePasswordObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Password").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOnePasswordStr(Nan::To<v8::String>(paramOnePasswordObj).ToLocalChecked());
     //encrypt password
     CDesEncryptAlgorithm DesEncrypt;
     DesEncrypt.SetPassword("monitor");
     char encryptedPassword[256] = {0};
     DesEncrypt.Encrypt(*paramOnePasswordStr, encryptedPassword);
     strcpy_s(field.Password, 41, encryptedPassword);
     std::cout<<encryptedPassword<<std::endl;
     //VersionID
     v8::Local<v8::Object> paramOneVersionIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("VersionID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneVersionIDStr(Nan::To<v8::String>(paramOneVersionIDObj).ToLocalChecked());
     strcpy_s(field.VersionID, 17, *paramOneVersionIDStr);
     std::cout<<*paramOneVersionIDStr<<std::endl;
     //convert parameter two
     v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
     int64_t nRequestID=paramTwo->Value();

     //call natvie method
     double returnValue= obj->_userApi->ReqQrySysUserLoginTopic(&field, nRequestID);

     info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
 }
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryTopMemInfoTopic){
  std::cout<<"ReqQryTopMemInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryTopMemInfoField field;

 //HostName
  v8::Local<v8::Object> paramOneHostNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHostNameStr(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNameStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAliveStr=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAliveStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryTopMemInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryTopProcessInfoTopic){
  std::cout<<"ReqQryTopProcessInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryTopProcessInfoField field;

 //HostName
  v8::Local<v8::Object> paramOneHostNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHostNameStr(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNameStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAliveStr=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAliveStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryTopProcessInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryFileSystemInfoTopic){
  std::cout<<"ReqQryFileSystemInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryFileSystemInfoField field;

 //HostName
  v8::Local<v8::Object> paramOneHostNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHostNameStr(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNameStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAliveStr=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAliveStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryFileSystemInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetworkInfoTopic){
  std::cout<<"ReqQryNetworkInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetworkInfoField field;

 //HostName
  v8::Local<v8::Object> paramOneHostNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHostNameStr(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNameStr);

 //LANNAME
  v8::Local<v8::Object> paramOneLANNAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("LANNAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneLANNAMEStr(Nan::To<v8::String>(paramOneLANNAMEObj).ToLocalChecked());
  strcpy_s(field.LANNAME,101,*paramOneLANNAMEStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAliveStr=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAliveStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetworkInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryMonitorObjectTopic){
  std::cout<<"ReqQryMonitorObjectTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryMonitorObjectField field;

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAliveStr=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAliveStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryMonitorObjectTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryObjectRationalTopic){
  std::cout<<"ReqQryObjectRationalTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryObjectRationalField field;

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAliveStr=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAliveStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryObjectRationalTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQrySyslogInfoTopic){
  std::cout<<"ReqQrySyslogInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQrySyslogInfoField field;

 //FileName
  v8::Local<v8::Object> paramOneFileNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FileName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFileNameStr(Nan::To<v8::String>(paramOneFileNameObj).ToLocalChecked());
  strcpy_s(field.FileName,641,*paramOneFileNameStr);

 //subFileName
  v8::Local<v8::Object> paramOnesubFileNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("subFileName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnesubFileNameStr(Nan::To<v8::String>(paramOnesubFileNameObj).ToLocalChecked());
  strcpy_s(field.subFileName,641,*paramOnesubFileNameStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQrySyslogInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQrySubscriberTopic){
  std::cout<<"ReqQrySubscriberTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQrySubscriberField field;

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,5121,*paramOneObjectIDStr);

 //ObjectNum
  v8::Local<v8::Object> paramOneObjectNumObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectNum").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneObjectNumStr=Nan::To<v8::Integer>( paramOneObjectNumObj).ToLocalChecked();
  field.ObjectNum=paramOneObjectNumStr->Value();

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAliveStr=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAliveStr->Value();

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDateStr(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDateStr);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimeStr(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQrySubscriberTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryOidRelationTopic){
  std::cout<<"ReqQryOidRelationTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryOidRelationField field;

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryOidRelationTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryUserInfoTopic){
  std::cout<<"ReqQryUserInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryUserInfoField field;

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryUserInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryOnlineUserInfoTopic){
  std::cout<<"ReqQryOnlineUserInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryOnlineUserInfoField field;

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryOnlineUserInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryWarningEventTopic){
  std::cout<<"ReqQryWarningEventTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryWarningEventField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

 //WarningLevel
  v8::Local<v8::Object> paramOneWarningLevelObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("WarningLevel").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneWarningLevelStr(Nan::To<v8::String>(paramOneWarningLevelObj).ToLocalChecked());
  strcpy_s(field.WarningLevel,101,*paramOneWarningLevelStr);

 //EventType
  v8::Local<v8::Object> paramOneEventTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEventTypeStr=Nan::To<v8::Integer>( paramOneEventTypeObj).ToLocalChecked();
  field.EventType=paramOneEventTypeStr->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,2561,*paramOneObjectIDStr);

 //EventName
  v8::Local<v8::Object> paramOneEventNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventNameStr(Nan::To<v8::String>(paramOneEventNameObj).ToLocalChecked());
  strcpy_s(field.EventName,641,*paramOneEventNameStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryWarningEventTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryObjectAttrTopic){
  std::cout<<"ReqQryObjectAttrTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryObjectAttrField field;

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDStr);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypeStr(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,2561,*paramOneAttrTypeStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryObjectAttrTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryInvalidateOrderTopic){
  std::cout<<"ReqQryInvalidateOrderTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryInvalidateOrderField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryInvalidateOrderTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryOrderStatusTopic){
  std::cout<<"ReqQryOrderStatusTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryOrderStatusField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryOrderStatusTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryBargainOrderTopic){
  std::cout<<"ReqQryBargainOrderTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryBargainOrderField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryBargainOrderTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryInstPropertyTopic){
  std::cout<<"ReqQryInstPropertyTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryInstPropertyField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryInstPropertyTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryMarginRateTopic){
  std::cout<<"ReqQryMarginRateTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryMarginRateField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryMarginRateTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryPriceLimitTopic){
  std::cout<<"ReqQryPriceLimitTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryPriceLimitField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryPriceLimitTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryPartPosiLimitTopic){
  std::cout<<"ReqQryPartPosiLimitTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryPartPosiLimitField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryPartPosiLimitTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryClientPosiLimitTopic){
  std::cout<<"ReqQryClientPosiLimitTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryClientPosiLimitField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryClientPosiLimitTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQrySpecialPosiLimitTopic){
  std::cout<<"ReqQrySpecialPosiLimitTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQrySpecialPosiLimitField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQrySpecialPosiLimitTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryTransactionChgTopic){
  std::cout<<"ReqQryTransactionChgTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryTransactionChgField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryTransactionChgTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryClientChgTopic){
  std::cout<<"ReqQryClientChgTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryClientChgField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryClientChgTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryPartClientChgTopic){
  std::cout<<"ReqQryPartClientChgTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryPartClientChgField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryPartClientChgTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryPosiLimitChgTopic){
  std::cout<<"ReqQryPosiLimitChgTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryPosiLimitChgField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryPosiLimitChgTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryHedgeDetailChgTopic){
  std::cout<<"ReqQryHedgeDetailChgTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryHedgeDetailChgField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryHedgeDetailChgTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryParticipantChgTopic){
  std::cout<<"ReqQryParticipantChgTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryParticipantChgField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryParticipantChgTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryMarginRateChgTopic){
  std::cout<<"ReqQryMarginRateChgTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryMarginRateChgField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryMarginRateChgTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryUserIpChgTopic){
  std::cout<<"ReqQryUserIpChgTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryUserIpChgField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryUserIpChgTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryClientPosiLimitChgTopic){
  std::cout<<"ReqQryClientPosiLimitChgTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryClientPosiLimitChgField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryClientPosiLimitChgTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQrySpecPosiLimitChgTopic){
  std::cout<<"ReqQrySpecPosiLimitChgTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQrySpecPosiLimitChgField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQrySpecPosiLimitChgTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryHistoryObjectAttrTopic){
  std::cout<<"ReqQryHistoryObjectAttrTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryHistoryObjectAttrField field;

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDStr);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypeStr(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,2561,*paramOneAttrTypeStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryHistoryObjectAttrTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryFrontInfoTopic){
  std::cout<<"ReqQryFrontInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryFrontInfoField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryFrontInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQrySysUserLogoutTopic){
  std::cout<<"ReqQrySysUserLogoutTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQrySysUserLogoutField field;

 //UserID
  v8::Local<v8::Object> paramOneUserIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUserIDStr(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
  strcpy_s(field.UserID,151,*paramOneUserIDStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQrySysUserLogoutTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQrySysUserPasswordUpdateTopic){
  std::cout<<"ReqQrySysUserPasswordUpdateTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQrySysUserPasswordUpdateField field;

 //UserID
  v8::Local<v8::Object> paramOneUserIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUserIDStr(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
  strcpy_s(field.UserID,151,*paramOneUserIDStr);

 //OldPassword
  v8::Local<v8::Object> paramOneOldPasswordObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OldPassword").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOldPasswordStr(Nan::To<v8::String>(paramOneOldPasswordObj).ToLocalChecked());
  strcpy_s(field.OldPassword,401,*paramOneOldPasswordStr);

 //NewPassword
  v8::Local<v8::Object> paramOneNewPasswordObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("NewPassword").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneNewPasswordStr(Nan::To<v8::String>(paramOneNewPasswordObj).ToLocalChecked());
  strcpy_s(field.NewPassword,401,*paramOneNewPasswordStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQrySysUserPasswordUpdateTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQrySysUserRegisterTopic){
  std::cout<<"ReqQrySysUserRegisterTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQrySysUserRegisterField field;

 //UserID
  v8::Local<v8::Object> paramOneUserIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUserIDStr(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
  strcpy_s(field.UserID,151,*paramOneUserIDStr);

 //UserName
  v8::Local<v8::Object> paramOneUserNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUserNameStr(Nan::To<v8::String>(paramOneUserNameObj).ToLocalChecked());
  strcpy_s(field.UserName,151,*paramOneUserNameStr);

 //UserInfo
  v8::Local<v8::Object> paramOneUserInfoObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserInfo").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUserInfoStr(Nan::To<v8::String>(paramOneUserInfoObj).ToLocalChecked());
  strcpy_s(field.UserInfo,991,*paramOneUserInfoStr);

 //Password
  v8::Local<v8::Object> paramOnePasswordObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Password").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePasswordStr(Nan::To<v8::String>(paramOnePasswordObj).ToLocalChecked());
  strcpy_s(field.Password,401,*paramOnePasswordStr);

 //Privilege
  v8::Local<v8::Object> paramOnePrivilegeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Privilege").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOnePrivilegeStr=Nan::To<v8::Integer>( paramOnePrivilegeObj).ToLocalChecked();
  field.Privilege=paramOnePrivilegeStr->Value();

 //EMail
  v8::Local<v8::Object> paramOneEMailObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EMail").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEMailStr(Nan::To<v8::String>(paramOneEMailObj).ToLocalChecked());
  strcpy_s(field.EMail,501,*paramOneEMailStr);

 //EMailFlag
  v8::Local<v8::Object> paramOneEMailFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EMailFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEMailFlagStr=Nan::To<v8::Integer>( paramOneEMailFlagObj).ToLocalChecked();
  field.EMailFlag=paramOneEMailFlagStr->Value();

 //HomePhone
  v8::Local<v8::Object> paramOneHomePhoneObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HomePhone").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHomePhoneStr(Nan::To<v8::String>(paramOneHomePhoneObj).ToLocalChecked());
  strcpy_s(field.HomePhone,301,*paramOneHomePhoneStr);

 //HomePhoneFlag
  v8::Local<v8::Object> paramOneHomePhoneFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HomePhoneFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneHomePhoneFlagStr=Nan::To<v8::Integer>( paramOneHomePhoneFlagObj).ToLocalChecked();
  field.HomePhoneFlag=paramOneHomePhoneFlagStr->Value();

 //MobilePhone
  v8::Local<v8::Object> paramOneMobilePhoneObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MobilePhone").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMobilePhoneStr(Nan::To<v8::String>(paramOneMobilePhoneObj).ToLocalChecked());
  strcpy_s(field.MobilePhone,301,*paramOneMobilePhoneStr);

 //MobilePhoneFlag
  v8::Local<v8::Object> paramOneMobilePhoneFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MobilePhoneFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneMobilePhoneFlagStr=Nan::To<v8::Integer>( paramOneMobilePhoneFlagObj).ToLocalChecked();
  field.MobilePhoneFlag=paramOneMobilePhoneFlagStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQrySysUserRegisterTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQrySysUserDeleteTopic){
  std::cout<<"ReqQrySysUserDeleteTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQrySysUserDeleteField field;

 //UserID
  v8::Local<v8::Object> paramOneUserIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUserIDStr(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
  strcpy_s(field.UserID,151,*paramOneUserIDStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQrySysUserDeleteTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryTradeLogTopic){
  std::cout<<"ReqQryTradeLogTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryTradeLogField field;

 //TradingDay
  v8::Local<v8::Object> paramOneTradingDayObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TradingDay").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTradingDayStr(Nan::To<v8::String>(paramOneTradingDayObj).ToLocalChecked());
  strcpy_s(field.TradingDay,81,*paramOneTradingDayStr);

 //IPAddress
  v8::Local<v8::Object> paramOneIPAddressObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPAddress").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPAddressStr(Nan::To<v8::String>(paramOneIPAddressObj).ToLocalChecked());
  strcpy_s(field.IPAddress,151,*paramOneIPAddressStr);

 //FrontID
  v8::Local<v8::Object> paramOneFrontIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FrontID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFrontIDStr(Nan::To<v8::String>(paramOneFrontIDObj).ToLocalChecked());
  strcpy_s(field.FrontID,81,*paramOneFrontIDStr);

 //StartParticipant
  v8::Local<v8::Object> paramOneStartParticipantObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartParticipant").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartParticipantStr(Nan::To<v8::String>(paramOneStartParticipantObj).ToLocalChecked());
  strcpy_s(field.StartParticipant,101,*paramOneStartParticipantStr);

 //EndParticipant
  v8::Local<v8::Object> paramOneEndParticipantObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndParticipant").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndParticipantStr(Nan::To<v8::String>(paramOneEndParticipantObj).ToLocalChecked());
  strcpy_s(field.EndParticipant,101,*paramOneEndParticipantStr);

 //StartUser
  v8::Local<v8::Object> paramOneStartUserObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartUser").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartUserStr(Nan::To<v8::String>(paramOneStartUserObj).ToLocalChecked());
  strcpy_s(field.StartUser,151,*paramOneStartUserStr);

 //EndUser
  v8::Local<v8::Object> paramOneEndUserObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndUser").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndUserStr(Nan::To<v8::String>(paramOneEndUserObj).ToLocalChecked());
  strcpy_s(field.EndUser,151,*paramOneEndUserStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

 //StartSessionID
  v8::Local<v8::Object> paramOneStartSessionIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartSessionID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartSessionIDStr(Nan::To<v8::String>(paramOneStartSessionIDObj).ToLocalChecked());
  strcpy_s(field.StartSessionID,81,*paramOneStartSessionIDStr);

 //EndSessionID
  v8::Local<v8::Object> paramOneEndSessionIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndSessionID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndSessionIDStr(Nan::To<v8::String>(paramOneEndSessionIDObj).ToLocalChecked());
  strcpy_s(field.EndSessionID,81,*paramOneEndSessionIDStr);

 //IPFlag
  v8::Local<v8::Object> paramOneIPFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIPFlagStr=Nan::To<v8::Integer>( paramOneIPFlagObj).ToLocalChecked();
  field.IPFlag=paramOneIPFlagStr->Value();

 //PartFlag
  v8::Local<v8::Object> paramOnePartFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PartFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOnePartFlagStr=Nan::To<v8::Integer>( paramOnePartFlagObj).ToLocalChecked();
  field.PartFlag=paramOnePartFlagStr->Value();

 //UserIDFlag
  v8::Local<v8::Object> paramOneUserIDFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserIDFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneUserIDFlagStr=Nan::To<v8::Integer>( paramOneUserIDFlagObj).ToLocalChecked();
  field.UserIDFlag=paramOneUserIDFlagStr->Value();

 //TimeFlag
  v8::Local<v8::Object> paramOneTimeFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TimeFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTimeFlagStr=Nan::To<v8::Integer>( paramOneTimeFlagObj).ToLocalChecked();
  field.TimeFlag=paramOneTimeFlagStr->Value();

 //FrontFlag
  v8::Local<v8::Object> paramOneFrontFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FrontFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneFrontFlagStr=Nan::To<v8::Integer>( paramOneFrontFlagObj).ToLocalChecked();
  field.FrontFlag=paramOneFrontFlagStr->Value();

 //SessionFlag
  v8::Local<v8::Object> paramOneSessionFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SessionFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSessionFlagStr=Nan::To<v8::Integer>( paramOneSessionFlagObj).ToLocalChecked();
  field.SessionFlag=paramOneSessionFlagStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryTradeLogTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryWarningEventUpdateTopic){
  std::cout<<"ReqQryWarningEventUpdateTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryWarningEventUpdateField field;

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDateStr(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDateStr);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimeStr(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimeStr);

 //OccurDate
  v8::Local<v8::Object> paramOneOccurDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OccurDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOccurDateStr(Nan::To<v8::String>(paramOneOccurDateObj).ToLocalChecked());
  strcpy_s(field.OccurDate,81,*paramOneOccurDateStr);

 //OccurTime
  v8::Local<v8::Object> paramOneOccurTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OccurTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOccurTimeStr(Nan::To<v8::String>(paramOneOccurTimeObj).ToLocalChecked());
  strcpy_s(field.OccurTime,81,*paramOneOccurTimeStr);

 //EvendID
  v8::Local<v8::Object> paramOneEvendIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EvendID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEvendIDStr=Nan::To<v8::Integer>( paramOneEvendIDObj).ToLocalChecked();
  field.EvendID=paramOneEvendIDStr->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,2561,*paramOneObjectIDStr);

 //IPAddress
  v8::Local<v8::Object> paramOneIPAddressObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPAddress").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPAddressStr(Nan::To<v8::String>(paramOneIPAddressObj).ToLocalChecked());
  strcpy_s(field.IPAddress,151,*paramOneIPAddressStr);

 //EventName
  v8::Local<v8::Object> paramOneEventNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventNameStr(Nan::To<v8::String>(paramOneEventNameObj).ToLocalChecked());
  strcpy_s(field.EventName,641,*paramOneEventNameStr);

 //EventNum
  v8::Local<v8::Object> paramOneEventNumObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventNum").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEventNumStr=Nan::To<v8::Integer>( paramOneEventNumObj).ToLocalChecked();
  field.EventNum=paramOneEventNumStr->Value();

 //EventType
  v8::Local<v8::Object> paramOneEventTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEventTypeStr=Nan::To<v8::Integer>( paramOneEventTypeObj).ToLocalChecked();
  field.EventType=paramOneEventTypeStr->Value();

 //EventDes
  v8::Local<v8::Object> paramOneEventDesObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventDes").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventDesStr(Nan::To<v8::String>(paramOneEventDesObj).ToLocalChecked());
  strcpy_s(field.EventDes,5121,*paramOneEventDesStr);

 //ProcessFlag
  v8::Local<v8::Object> paramOneProcessFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ProcessFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneProcessFlagStr(Nan::To<v8::String>(paramOneProcessFlagObj).ToLocalChecked());
  strcpy_s(field.ProcessFlag,11,*paramOneProcessFlagStr);

 //WarningLevel
  v8::Local<v8::Object> paramOneWarningLevelObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("WarningLevel").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneWarningLevelStr(Nan::To<v8::String>(paramOneWarningLevelObj).ToLocalChecked());
  strcpy_s(field.WarningLevel,101,*paramOneWarningLevelStr);

 //ActiveDate
  v8::Local<v8::Object> paramOneActiveDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ActiveDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneActiveDateStr(Nan::To<v8::String>(paramOneActiveDateObj).ToLocalChecked());
  strcpy_s(field.ActiveDate,81,*paramOneActiveDateStr);

 //ActiveTime
  v8::Local<v8::Object> paramOneActiveTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ActiveTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneActiveTimeStr(Nan::To<v8::String>(paramOneActiveTimeObj).ToLocalChecked());
  strcpy_s(field.ActiveTime,81,*paramOneActiveTimeStr);

 //EventDealDes
  v8::Local<v8::Object> paramOneEventDealDesObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventDealDes").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventDealDesStr(Nan::To<v8::String>(paramOneEventDealDesObj).ToLocalChecked());
  strcpy_s(field.EventDealDes,641,*paramOneEventDealDesStr);

 //FullEventName
  v8::Local<v8::Object> paramOneFullEventNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FullEventName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFullEventNameStr(Nan::To<v8::String>(paramOneFullEventNameObj).ToLocalChecked());
  strcpy_s(field.FullEventName,2561,*paramOneFullEventNameStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryWarningEventUpdateTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryTradeUserLoginInfoTopic){
  std::cout<<"ReqQryTradeUserLoginInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryTradeUserLoginInfoField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryTradeUserLoginInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryPartTradeTopic){
  std::cout<<"ReqQryPartTradeTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryPartTradeField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryPartTradeTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryTradepeakTopic){
  std::cout<<"ReqQryTradepeakTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryTradepeakField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

 //TradepeakFlag
  v8::Local<v8::Object> paramOneTradepeakFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TradepeakFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTradepeakFlagStr=Nan::To<v8::Integer>( paramOneTradepeakFlagObj).ToLocalChecked();
  field.TradepeakFlag=paramOneTradepeakFlagStr->Value()-48;

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryTradepeakTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryParticipantInitTopic){
  std::cout<<"ReqQryParticipantInitTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryParticipantInitField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryParticipantInitTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryUserInitTopic){
  std::cout<<"ReqQryUserInitTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryUserInitField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryUserInitTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryHistoryCpuInfoTopic){
  std::cout<<"ReqQryHistoryCpuInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryHistoryCpuInfoField field;

 //HostName
  v8::Local<v8::Object> paramOneHostNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHostNameStr(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNameStr);

 //CPU
  v8::Local<v8::Object> paramOneCPUObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CPU").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCPUStr(Nan::To<v8::String>(paramOneCPUObj).ToLocalChecked());
  strcpy_s(field.CPU,51,*paramOneCPUStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAliveStr=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAliveStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryHistoryCpuInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryHistoryMemInfoTopic){
  std::cout<<"ReqQryHistoryMemInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryHistoryMemInfoField field;

 //HostName
  v8::Local<v8::Object> paramOneHostNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHostNameStr(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNameStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAliveStr=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAliveStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryHistoryMemInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryHistoryNetworkInfoTopic){
  std::cout<<"ReqQryHistoryNetworkInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryHistoryNetworkInfoField field;

 //HostName
  v8::Local<v8::Object> paramOneHostNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHostNameStr(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNameStr);

 //LANNAME
  v8::Local<v8::Object> paramOneLANNAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("LANNAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneLANNAMEStr(Nan::To<v8::String>(paramOneLANNAMEObj).ToLocalChecked());
  strcpy_s(field.LANNAME,101,*paramOneLANNAMEStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAliveStr=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAliveStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryHistoryNetworkInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryHistoryTradePeakTopic){
  std::cout<<"ReqQryHistoryTradePeakTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryHistoryTradePeakField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryHistoryTradePeakTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQrySyslogEventTopic){
  std::cout<<"ReqQrySyslogEventTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQrySyslogEventField field;

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

 //EventType
  v8::Local<v8::Object> paramOneEventTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEventTypeStr=Nan::To<v8::Integer>( paramOneEventTypeObj).ToLocalChecked();
  field.EventType=paramOneEventTypeStr->Value();

 //WarningLevel
  v8::Local<v8::Object> paramOneWarningLevelObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("WarningLevel").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneWarningLevelStr(Nan::To<v8::String>(paramOneWarningLevelObj).ToLocalChecked());
  strcpy_s(field.WarningLevel,101,*paramOneWarningLevelStr);

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,2561,*paramOneObjectIDStr);

 //EventName
  v8::Local<v8::Object> paramOneEventNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventNameStr(Nan::To<v8::String>(paramOneEventNameObj).ToLocalChecked());
  strcpy_s(field.EventName,641,*paramOneEventNameStr);

 //IPAddress
  v8::Local<v8::Object> paramOneIPAddressObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPAddress").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPAddressStr(Nan::To<v8::String>(paramOneIPAddressObj).ToLocalChecked());
  strcpy_s(field.IPAddress,151,*paramOneIPAddressStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQrySyslogEventTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQrySyslogEventSubcriberTopic){
  std::cout<<"ReqQrySyslogEventSubcriberTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQrySyslogEventSubcriberField field;

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,2561,*paramOneObjectIDStr);

 //EventName
  v8::Local<v8::Object> paramOneEventNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventNameStr(Nan::To<v8::String>(paramOneEventNameObj).ToLocalChecked());
  strcpy_s(field.EventName,641,*paramOneEventNameStr);

 //WarningLevel
  v8::Local<v8::Object> paramOneWarningLevelObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("WarningLevel").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneWarningLevelStr(Nan::To<v8::String>(paramOneWarningLevelObj).ToLocalChecked());
  strcpy_s(field.WarningLevel,101,*paramOneWarningLevelStr);

 //filter
  v8::Local<v8::Object> paramOnefilterObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("filter").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnefilterStr(Nan::To<v8::String>(paramOnefilterObj).ToLocalChecked());
  strcpy_s(field.filter,5121,*paramOnefilterStr);

 //antifilter
  v8::Local<v8::Object> paramOneantifilterObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("antifilter").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneantifilterStr(Nan::To<v8::String>(paramOneantifilterObj).ToLocalChecked());
  strcpy_s(field.antifilter,5121,*paramOneantifilterStr);

 //ObjectNum
  v8::Local<v8::Object> paramOneObjectNumObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectNum").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneObjectNumStr=Nan::To<v8::Integer>( paramOneObjectNumObj).ToLocalChecked();
  field.ObjectNum=paramOneObjectNumStr->Value();

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAliveStr=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAliveStr->Value();

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDateStr(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDateStr);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimeStr(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimeStr);

 //ProcessFlag
  v8::Local<v8::Object> paramOneProcessFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ProcessFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneProcessFlagStr(Nan::To<v8::String>(paramOneProcessFlagObj).ToLocalChecked());
  strcpy_s(field.ProcessFlag,11,*paramOneProcessFlagStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQrySyslogEventSubcriberTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryTomcatInfoTopic){
  std::cout<<"ReqQryTomcatInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryTomcatInfoField field;

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDStr);

 //SubObjectID
  v8::Local<v8::Object> paramOneSubObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SubObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSubObjectIDStr(Nan::To<v8::String>(paramOneSubObjectIDObj).ToLocalChecked());
  strcpy_s(field.SubObjectID,641,*paramOneSubObjectIDStr);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypeStr(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,2561,*paramOneAttrTypeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryTomcatInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryDBQueryTopic){
  std::cout<<"ReqQryDBQueryTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryDBQueryField field;

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDStr);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypeStr(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,641,*paramOneAttrTypeStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryDBQueryTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryGetFileTopic){
  std::cout<<"ReqQryGetFileTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryGetFileField field;

 //FileName
  v8::Local<v8::Object> paramOneFileNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FileName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFileNameStr(Nan::To<v8::String>(paramOneFileNameObj).ToLocalChecked());
  strcpy_s(field.FileName,2561,*paramOneFileNameStr);

 //Version
  v8::Local<v8::Object> paramOneVersionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Version").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneVersionStr(Nan::To<v8::String>(paramOneVersionObj).ToLocalChecked());
  strcpy_s(field.Version,161,*paramOneVersionStr);

 //Offset
  v8::Local<v8::Object> paramOneOffsetObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Offset").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOffsetStr=Nan::To<v8::Integer>( paramOneOffsetObj).ToLocalChecked();
  field.Offset=paramOneOffsetStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryGetFileTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQrySyslogEventUpdateTopic){
  std::cout<<"ReqQrySyslogEventUpdateTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQrySyslogEventUpdateField field;

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDateStr(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDateStr);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimeStr(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimeStr);

 //OccurDate
  v8::Local<v8::Object> paramOneOccurDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OccurDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOccurDateStr(Nan::To<v8::String>(paramOneOccurDateObj).ToLocalChecked());
  strcpy_s(field.OccurDate,81,*paramOneOccurDateStr);

 //OccurTime
  v8::Local<v8::Object> paramOneOccurTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OccurTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOccurTimeStr(Nan::To<v8::String>(paramOneOccurTimeObj).ToLocalChecked());
  strcpy_s(field.OccurTime,81,*paramOneOccurTimeStr);

 //EvendID
  v8::Local<v8::Object> paramOneEvendIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EvendID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEvendIDStr=Nan::To<v8::Integer>( paramOneEvendIDObj).ToLocalChecked();
  field.EvendID=paramOneEvendIDStr->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,2561,*paramOneObjectIDStr);

 //IPAddress
  v8::Local<v8::Object> paramOneIPAddressObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPAddress").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPAddressStr(Nan::To<v8::String>(paramOneIPAddressObj).ToLocalChecked());
  strcpy_s(field.IPAddress,151,*paramOneIPAddressStr);

 //EventName
  v8::Local<v8::Object> paramOneEventNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventNameStr(Nan::To<v8::String>(paramOneEventNameObj).ToLocalChecked());
  strcpy_s(field.EventName,641,*paramOneEventNameStr);

 //EventNum
  v8::Local<v8::Object> paramOneEventNumObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventNum").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEventNumStr=Nan::To<v8::Integer>( paramOneEventNumObj).ToLocalChecked();
  field.EventNum=paramOneEventNumStr->Value();

 //EventType
  v8::Local<v8::Object> paramOneEventTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEventTypeStr=Nan::To<v8::Integer>( paramOneEventTypeObj).ToLocalChecked();
  field.EventType=paramOneEventTypeStr->Value();

 //EventDes
  v8::Local<v8::Object> paramOneEventDesObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventDes").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventDesStr(Nan::To<v8::String>(paramOneEventDesObj).ToLocalChecked());
  strcpy_s(field.EventDes,5121,*paramOneEventDesStr);

 //ProcessFlag
  v8::Local<v8::Object> paramOneProcessFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ProcessFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneProcessFlagStr(Nan::To<v8::String>(paramOneProcessFlagObj).ToLocalChecked());
  strcpy_s(field.ProcessFlag,11,*paramOneProcessFlagStr);

 //WarningLevel
  v8::Local<v8::Object> paramOneWarningLevelObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("WarningLevel").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneWarningLevelStr(Nan::To<v8::String>(paramOneWarningLevelObj).ToLocalChecked());
  strcpy_s(field.WarningLevel,101,*paramOneWarningLevelStr);

 //EventDealDes
  v8::Local<v8::Object> paramOneEventDealDesObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventDealDes").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventDealDesStr(Nan::To<v8::String>(paramOneEventDealDesObj).ToLocalChecked());
  strcpy_s(field.EventDealDes,641,*paramOneEventDealDesStr);

 //FullEventName
  v8::Local<v8::Object> paramOneFullEventNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FullEventName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFullEventNameStr(Nan::To<v8::String>(paramOneFullEventNameObj).ToLocalChecked());
  strcpy_s(field.FullEventName,2561,*paramOneFullEventNameStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQrySyslogEventUpdateTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryWarningQueryTopic){
  std::cout<<"ReqQryWarningQueryTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryWarningQueryField field;

 //EvendID
  v8::Local<v8::Object> paramOneEvendIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EvendID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEvendIDStr=Nan::To<v8::Integer>( paramOneEvendIDObj).ToLocalChecked();
  field.EvendID=paramOneEvendIDStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryWarningQueryTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryWebVisitTopic){
  std::cout<<"ReqQryWebVisitTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryWebVisitField field;

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDStr);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypeStr(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,2561,*paramOneAttrTypeStr);

 //BeginDate
  v8::Local<v8::Object> paramOneBeginDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("BeginDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneBeginDateStr(Nan::To<v8::String>(paramOneBeginDateObj).ToLocalChecked());
  strcpy_s(field.BeginDate,81,*paramOneBeginDateStr);

 //BeginTime
  v8::Local<v8::Object> paramOneBeginTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("BeginTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneBeginTimeStr(Nan::To<v8::String>(paramOneBeginTimeObj).ToLocalChecked());
  strcpy_s(field.BeginTime,81,*paramOneBeginTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryWebVisitTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryGeneralOperateTopic){
  std::cout<<"ReqQryGeneralOperateTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryGeneralOperateField field;

 //GeneralOperateType
  v8::Local<v8::Object> paramOneGeneralOperateTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("GeneralOperateType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneGeneralOperateTypeStr=Nan::To<v8::Integer>( paramOneGeneralOperateTypeObj).ToLocalChecked();
  field.GeneralOperateType=paramOneGeneralOperateTypeStr->Value()-48;

 //GeneralOperateTable
  v8::Local<v8::Object> paramOneGeneralOperateTableObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("GeneralOperateTable").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneGeneralOperateTableStr(Nan::To<v8::String>(paramOneGeneralOperateTableObj).ToLocalChecked());
  strcpy_s(field.GeneralOperateTable,1281,*paramOneGeneralOperateTableStr);

 //GeneralOperateOption
  v8::Local<v8::Object> paramOneGeneralOperateOptionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("GeneralOperateOption").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneGeneralOperateOptionStr(Nan::To<v8::String>(paramOneGeneralOperateOptionObj).ToLocalChecked());
  strcpy_s(field.GeneralOperateOption,8001,*paramOneGeneralOperateOptionStr);

 //GeneralOperateSet
  v8::Local<v8::Object> paramOneGeneralOperateSetObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("GeneralOperateSet").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneGeneralOperateSetStr(Nan::To<v8::String>(paramOneGeneralOperateSetObj).ToLocalChecked());
  strcpy_s(field.GeneralOperateSet,30001,*paramOneGeneralOperateSetStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryGeneralOperateTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetDeviceLinkedTopic){
  std::cout<<"ReqQryNetDeviceLinkedTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetDeviceLinkedField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //SysNetSubAreaID
  v8::Local<v8::Object> paramOneSysNetSubAreaIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetSubAreaID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetSubAreaIDStr=Nan::To<v8::Integer>( paramOneSysNetSubAreaIDObj).ToLocalChecked();
  field.SysNetSubAreaID=paramOneSysNetSubAreaIDStr->Value();

 //FuctionArea
  v8::Local<v8::Object> paramOneFuctionAreaObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FuctionArea").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFuctionAreaStr(Nan::To<v8::String>(paramOneFuctionAreaObj).ToLocalChecked());
  strcpy_s(field.FuctionArea,641,*paramOneFuctionAreaStr);

 //IPDECODE
  v8::Local<v8::Object> paramOneIPDECODEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPDECODE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIPDECODEStr=Nan::To<v8::Integer>( paramOneIPDECODEObj).ToLocalChecked();
  field.IPDECODE=paramOneIPDECODEStr->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetDeviceLinkedTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryTradeUserLoginStatTopic){
  std::cout<<"ReqQryTradeUserLoginStatTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryTradeUserLoginStatField field;

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryTradeUserLoginStatTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryTradeFrontOrderRttStatTopic){
  std::cout<<"ReqQryTradeFrontOrderRttStatTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryTradeFrontOrderRttStatField field;

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDStr);

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDateStr(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDateStr);

 //MonStartTime
  v8::Local<v8::Object> paramOneMonStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonStartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonStartTimeStr(Nan::To<v8::String>(paramOneMonStartTimeObj).ToLocalChecked());
  strcpy_s(field.MonStartTime,81,*paramOneMonStartTimeStr);

 //MonEndTime
  v8::Local<v8::Object> paramOneMonEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonEndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonEndTimeStr(Nan::To<v8::String>(paramOneMonEndTimeObj).ToLocalChecked());
  strcpy_s(field.MonEndTime,81,*paramOneMonEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryTradeFrontOrderRttStatTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryParticTradeOrderStatesTopic){
  std::cout<<"ReqQryParticTradeOrderStatesTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryParticTradeOrderStatesField field;

 //ParticipantID
  v8::Local<v8::Object> paramOneParticipantIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ParticipantID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneParticipantIDStr(Nan::To<v8::String>(paramOneParticipantIDObj).ToLocalChecked());
  strcpy_s(field.ParticipantID,101,*paramOneParticipantIDStr);

 //UserID
  v8::Local<v8::Object> paramOneUserIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUserIDStr(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
  strcpy_s(field.UserID,151,*paramOneUserIDStr);

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDateStr(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDateStr);

 //MonStartTime
  v8::Local<v8::Object> paramOneMonStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonStartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonStartTimeStr(Nan::To<v8::String>(paramOneMonStartTimeObj).ToLocalChecked());
  strcpy_s(field.MonStartTime,81,*paramOneMonStartTimeStr);

 //MonEndTime
  v8::Local<v8::Object> paramOneMonEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonEndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonEndTimeStr(Nan::To<v8::String>(paramOneMonEndTimeObj).ToLocalChecked());
  strcpy_s(field.MonEndTime,81,*paramOneMonEndTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryParticTradeOrderStatesTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryRouterInfoTopic){
  std::cout<<"ReqQryRouterInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryRouterInfoField field;

 //HostName
  v8::Local<v8::Object> paramOneHostNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHostNameStr(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNameStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAliveStr=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAliveStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryRouterInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryDiskIOTopic){
  std::cout<<"ReqQryDiskIOTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryDiskIOField field;

 //HostName
  v8::Local<v8::Object> paramOneHostNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHostNameStr(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNameStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAliveStr=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAliveStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryDiskIOTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryStatInfoTopic){
  std::cout<<"ReqQryStatInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryStatInfoField field;

 //HostName
  v8::Local<v8::Object> paramOneHostNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHostNameStr(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNameStr);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDateStr(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDateStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDateStr(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDateStr);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimeStr(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimeStr);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAliveStr=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAliveStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryStatInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryTradeOrderRttCutLineTopic){
  std::cout<<"ReqQryTradeOrderRttCutLineTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryTradeOrderRttCutLineField field;

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDateStr(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDateStr);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimeStr(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimeStr);

 //UserName
  v8::Local<v8::Object> paramOneUserNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUserNameStr(Nan::To<v8::String>(paramOneUserNameObj).ToLocalChecked());
  strcpy_s(field.UserName,641,*paramOneUserNameStr);

 //OrderRttCutLine
  v8::Local<v8::Object> paramOneOrderRttCutLineObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OrderRttCutLine").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOrderRttCutLineStr(Nan::To<v8::String>(paramOneOrderRttCutLineObj).ToLocalChecked());
  strcpy_s(field.OrderRttCutLine,1281,*paramOneOrderRttCutLineStr);

 //OrderRttWidth
  v8::Local<v8::Object> paramOneOrderRttWidthObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OrderRttWidth").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOrderRttWidthStr=Nan::To<v8::Integer>( paramOneOrderRttWidthObj).ToLocalChecked();
  field.OrderRttWidth=paramOneOrderRttWidthStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryTradeOrderRttCutLineTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryClientInfoTopic){
  std::cout<<"ReqQryClientInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryClientInfoField field;

 //ClientID
  v8::Local<v8::Object> paramOneClientIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ClientID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneClientIDStr(Nan::To<v8::String>(paramOneClientIDObj).ToLocalChecked());
  strcpy_s(field.ClientID,101,*paramOneClientIDStr);

 //ClientName
  v8::Local<v8::Object> paramOneClientNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ClientName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneClientNameStr(Nan::To<v8::String>(paramOneClientNameObj).ToLocalChecked());
  strcpy_s(field.ClientName,801,*paramOneClientNameStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryClientInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryEventDescriptionTopic){
  std::cout<<"ReqQryEventDescriptionTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryEventDescriptionField field;

 //EventDesID
  v8::Local<v8::Object> paramOneEventDesIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventDesID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventDesIDStr(Nan::To<v8::String>(paramOneEventDesIDObj).ToLocalChecked());
  strcpy_s(field.EventDesID,121,*paramOneEventDesIDStr);

 //UserName
  v8::Local<v8::Object> paramOneUserNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUserNameStr(Nan::To<v8::String>(paramOneUserNameObj).ToLocalChecked());
  strcpy_s(field.UserName,641,*paramOneUserNameStr);

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDateStr(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDateStr);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimeStr(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimeStr);

 //EventDes
  v8::Local<v8::Object> paramOneEventDesObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventDes").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventDesStr(Nan::To<v8::String>(paramOneEventDesObj).ToLocalChecked());
  strcpy_s(field.EventDes,4001,*paramOneEventDesStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryEventDescriptionTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryFrontUniqueIDTopic){
  std::cout<<"ReqQryFrontUniqueIDTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryFrontUniqueIDField field;

 //FrontID
  v8::Local<v8::Object> paramOneFrontIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FrontID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneFrontIDStr=Nan::To<v8::Integer>( paramOneFrontIDObj).ToLocalChecked();
  field.FrontID=paramOneFrontIDStr->Value();

 //FrontName
  v8::Local<v8::Object> paramOneFrontNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FrontName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFrontNameStr(Nan::To<v8::String>(paramOneFrontNameObj).ToLocalChecked());
  strcpy_s(field.FrontName,501,*paramOneFrontNameStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryFrontUniqueIDTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetPartyLinkAddrChangeTopic){
  std::cout<<"ReqQryNetPartyLinkAddrChangeTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetPartyLinkAddrChangeField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //RelationID
  v8::Local<v8::Object> paramOneRelationIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("RelationID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneRelationIDStr=Nan::To<v8::Integer>( paramOneRelationIDObj).ToLocalChecked();
  field.RelationID=paramOneRelationIDStr->Value();

 //OLDADDRESS
  v8::Local<v8::Object> paramOneOLDADDRESSObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OLDADDRESS").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOLDADDRESSStr(Nan::To<v8::String>(paramOneOLDADDRESSObj).ToLocalChecked());
  strcpy_s(field.OLDADDRESS,2561,*paramOneOLDADDRESSStr);

 //NEWADDRESS
  v8::Local<v8::Object> paramOneNEWADDRESSObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("NEWADDRESS").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneNEWADDRESSStr(Nan::To<v8::String>(paramOneNEWADDRESSObj).ToLocalChecked());
  strcpy_s(field.NEWADDRESS,2561,*paramOneNEWADDRESSStr);

 //OPERATOR
  v8::Local<v8::Object> paramOneOPERATORObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OPERATOR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOPERATORStr(Nan::To<v8::String>(paramOneOPERATORObj).ToLocalChecked());
  strcpy_s(field.OPERATOR,321,*paramOneOPERATORStr);

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDateStr(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDateStr);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimeStr(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetPartyLinkAddrChangeTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetDelPartyLinkInfoTopic){
  std::cout<<"ReqQryNetDelPartyLinkInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetDelPartyLinkInfoField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //MEMBER_NO
  v8::Local<v8::Object> paramOneMEMBER_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MEMBER_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMEMBER_NOStr(Nan::To<v8::String>(paramOneMEMBER_NOObj).ToLocalChecked());
  strcpy_s(field.MEMBER_NO,321,*paramOneMEMBER_NOStr);

 //MEMBER_NAME
  v8::Local<v8::Object> paramOneMEMBER_NAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MEMBER_NAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMEMBER_NAMEStr(Nan::To<v8::String>(paramOneMEMBER_NAMEObj).ToLocalChecked());
  strcpy_s(field.MEMBER_NAME,641,*paramOneMEMBER_NAMEStr);

 //REMOTE_ADDR
  v8::Local<v8::Object> paramOneREMOTE_ADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("REMOTE_ADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneREMOTE_ADDRStr(Nan::To<v8::String>(paramOneREMOTE_ADDRObj).ToLocalChecked());
  strcpy_s(field.REMOTE_ADDR,641,*paramOneREMOTE_ADDRStr);

 //LOCAL_ADDR
  v8::Local<v8::Object> paramOneLOCAL_ADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("LOCAL_ADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneLOCAL_ADDRStr(Nan::To<v8::String>(paramOneLOCAL_ADDRObj).ToLocalChecked());
  strcpy_s(field.LOCAL_ADDR,641,*paramOneLOCAL_ADDRStr);

 //ADDRESS
  v8::Local<v8::Object> paramOneADDRESSObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ADDRESS").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneADDRESSStr(Nan::To<v8::String>(paramOneADDRESSObj).ToLocalChecked());
  strcpy_s(field.ADDRESS,2561,*paramOneADDRESSStr);

 //LINE_STATUS
  v8::Local<v8::Object> paramOneLINE_STATUSObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("LINE_STATUS").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneLINE_STATUSStr(Nan::To<v8::String>(paramOneLINE_STATUSObj).ToLocalChecked());
  strcpy_s(field.LINE_STATUS,321,*paramOneLINE_STATUSStr);

 //CONTACT
  v8::Local<v8::Object> paramOneCONTACTObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CONTACT").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCONTACTStr(Nan::To<v8::String>(paramOneCONTACTObj).ToLocalChecked());
  strcpy_s(field.CONTACT,321,*paramOneCONTACTStr);

 //TELEPHONE
  v8::Local<v8::Object> paramOneTELEPHONEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TELEPHONE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTELEPHONEStr(Nan::To<v8::String>(paramOneTELEPHONEObj).ToLocalChecked());
  strcpy_s(field.TELEPHONE,641,*paramOneTELEPHONEStr);

 //MOBILEPHONE
  v8::Local<v8::Object> paramOneMOBILEPHONEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MOBILEPHONE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMOBILEPHONEStr(Nan::To<v8::String>(paramOneMOBILEPHONEObj).ToLocalChecked());
  strcpy_s(field.MOBILEPHONE,641,*paramOneMOBILEPHONEStr);

 //EMAIL
  v8::Local<v8::Object> paramOneEMAILObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EMAIL").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEMAILStr(Nan::To<v8::String>(paramOneEMAILObj).ToLocalChecked());
  strcpy_s(field.EMAIL,641,*paramOneEMAILStr);

 //FAX
  v8::Local<v8::Object> paramOneFAXObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FAX").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFAXStr(Nan::To<v8::String>(paramOneFAXObj).ToLocalChecked());
  strcpy_s(field.FAX,641,*paramOneFAXStr);

 //PROVINCE
  v8::Local<v8::Object> paramOnePROVINCEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PROVINCE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePROVINCEStr(Nan::To<v8::String>(paramOnePROVINCEObj).ToLocalChecked());
  strcpy_s(field.PROVINCE,321,*paramOnePROVINCEStr);

 //DDN_NO
  v8::Local<v8::Object> paramOneDDN_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DDN_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDDN_NOStr(Nan::To<v8::String>(paramOneDDN_NOObj).ToLocalChecked());
  strcpy_s(field.DDN_NO,641,*paramOneDDN_NOStr);

 //IN_MODE
  v8::Local<v8::Object> paramOneIN_MODEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IN_MODE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIN_MODEStr(Nan::To<v8::String>(paramOneIN_MODEObj).ToLocalChecked());
  strcpy_s(field.IN_MODE,641,*paramOneIN_MODEStr);

 //IP_WAN
  v8::Local<v8::Object> paramOneIP_WANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IP_WAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIP_WANStr(Nan::To<v8::String>(paramOneIP_WANObj).ToLocalChecked());
  strcpy_s(field.IP_WAN,641,*paramOneIP_WANStr);

 //IP_LAN
  v8::Local<v8::Object> paramOneIP_LANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IP_LAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIP_LANStr(Nan::To<v8::String>(paramOneIP_LANObj).ToLocalChecked());
  strcpy_s(field.IP_LAN,641,*paramOneIP_LANStr);

 //IPADDR
  v8::Local<v8::Object> paramOneIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPADDRStr(Nan::To<v8::String>(paramOneIPADDRObj).ToLocalChecked());
  strcpy_s(field.IPADDR,641,*paramOneIPADDRStr);

 //Interface
  v8::Local<v8::Object> paramOneInterfaceObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Interface").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInterfaceStr(Nan::To<v8::String>(paramOneInterfaceObj).ToLocalChecked());
  strcpy_s(field.Interface,641,*paramOneInterfaceStr);

 //INTERFACE_DATE
  v8::Local<v8::Object> paramOneINTERFACE_DATEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("INTERFACE_DATE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneINTERFACE_DATEStr(Nan::To<v8::String>(paramOneINTERFACE_DATEObj).ToLocalChecked());
  strcpy_s(field.INTERFACE_DATE,321,*paramOneINTERFACE_DATEStr);

 //SOFTWARE
  v8::Local<v8::Object> paramOneSOFTWAREObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SOFTWARE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSOFTWAREStr(Nan::To<v8::String>(paramOneSOFTWAREObj).ToLocalChecked());
  strcpy_s(field.SOFTWARE,321,*paramOneSOFTWAREStr);

 //FEE_TYPE
  v8::Local<v8::Object> paramOneFEE_TYPEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FEE_TYPE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFEE_TYPEStr(Nan::To<v8::String>(paramOneFEE_TYPEObj).ToLocalChecked());
  strcpy_s(field.FEE_TYPE,321,*paramOneFEE_TYPEStr);

 //SERVICEPROVIDER
  v8::Local<v8::Object> paramOneSERVICEPROVIDERObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SERVICEPROVIDER").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSERVICEPROVIDERStr(Nan::To<v8::String>(paramOneSERVICEPROVIDERObj).ToLocalChecked());
  strcpy_s(field.SERVICEPROVIDER,321,*paramOneSERVICEPROVIDERStr);

 //IF_ZIYING
  v8::Local<v8::Object> paramOneIF_ZIYINGObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IF_ZIYING").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIF_ZIYINGStr(Nan::To<v8::String>(paramOneIF_ZIYINGObj).ToLocalChecked());
  strcpy_s(field.IF_ZIYING,321,*paramOneIF_ZIYINGStr);

 //IF_TUOGUAN
  v8::Local<v8::Object> paramOneIF_TUOGUANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IF_TUOGUAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIF_TUOGUANStr(Nan::To<v8::String>(paramOneIF_TUOGUANObj).ToLocalChecked());
  strcpy_s(field.IF_TUOGUAN,321,*paramOneIF_TUOGUANStr);

 //HASOTHER
  v8::Local<v8::Object> paramOneHASOTHERObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HASOTHER").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHASOTHERStr(Nan::To<v8::String>(paramOneHASOTHERObj).ToLocalChecked());
  strcpy_s(field.HASOTHER,321,*paramOneHASOTHERStr);

 //SEAT_NO
  v8::Local<v8::Object> paramOneSEAT_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SEAT_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSEAT_NOStr(Nan::To<v8::String>(paramOneSEAT_NOObj).ToLocalChecked());
  strcpy_s(field.SEAT_NO,10241,*paramOneSEAT_NOStr);

 //PRO
  v8::Local<v8::Object> paramOnePROObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PRO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePROStr(Nan::To<v8::String>(paramOnePROObj).ToLocalChecked());
  strcpy_s(field.PRO,5121,*paramOnePROStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetDelPartyLinkInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryPerformanceTopTopic){
  std::cout<<"ReqQryPerformanceTopTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryPerformanceTopField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypeStr(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,641,*paramOneAttrTypeStr);

 //NetArea
  v8::Local<v8::Object> paramOneNetAreaObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("NetArea").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneNetAreaStr=Nan::To<v8::Integer>( paramOneNetAreaObj).ToLocalChecked();
  field.NetArea=paramOneNetAreaStr->Value();

 //NetSubArea
  v8::Local<v8::Object> paramOneNetSubAreaObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("NetSubArea").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneNetSubAreaStr(Nan::To<v8::String>(paramOneNetSubAreaObj).ToLocalChecked());
  strcpy_s(field.NetSubArea,641,*paramOneNetSubAreaStr);

 //KeyWord
  v8::Local<v8::Object> paramOneKeyWordObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeyWord").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneKeyWordStr(Nan::To<v8::String>(paramOneKeyWordObj).ToLocalChecked());
  strcpy_s(field.KeyWord,1001,*paramOneKeyWordStr);

 //SortValue
  v8::Local<v8::Object> paramOneSortValueObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SortValue").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSortValueStr=Nan::To<v8::Integer>( paramOneSortValueObj).ToLocalChecked();
  field.SortValue=paramOneSortValueStr->Value();

 //SortType
  v8::Local<v8::Object> paramOneSortTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SortType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSortTypeStr=Nan::To<v8::Integer>( paramOneSortTypeObj).ToLocalChecked();
  field.SortType=paramOneSortTypeStr->Value();

 //DuringTimeType
  v8::Local<v8::Object> paramOneDuringTimeTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DuringTimeType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDuringTimeTypeStr=Nan::To<v8::Integer>( paramOneDuringTimeTypeObj).ToLocalChecked();
  field.DuringTimeType=paramOneDuringTimeTypeStr->Value();

 //DuringTimeValue
  v8::Local<v8::Object> paramOneDuringTimeValueObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DuringTimeValue").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDuringTimeValueStr=Nan::To<v8::Integer>( paramOneDuringTimeValueObj).ToLocalChecked();
  field.DuringTimeValue=paramOneDuringTimeValueStr->Value();

 //TopN
  v8::Local<v8::Object> paramOneTopNObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TopN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTopNStr=Nan::To<v8::Integer>( paramOneTopNObj).ToLocalChecked();
  field.TopN=paramOneTopNStr->Value();

 //TopResult
  v8::Local<v8::Object> paramOneTopResultObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TopResult").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTopResultStr(Nan::To<v8::String>(paramOneTopResultObj).ToLocalChecked());
  strcpy_s(field.TopResult,2561,*paramOneTopResultStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryPerformanceTopTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryInstrumentStatusTopic){
  std::cout<<"ReqQryInstrumentStatusTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryInstrumentStatusField field;

 //SettlementGroupID
  v8::Local<v8::Object> paramOneSettlementGroupIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SettlementGroupID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSettlementGroupIDStr(Nan::To<v8::String>(paramOneSettlementGroupIDObj).ToLocalChecked());
  strcpy_s(field.SettlementGroupID,81,*paramOneSettlementGroupIDStr);

 //InstrumentID
  v8::Local<v8::Object> paramOneInstrumentIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("InstrumentID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInstrumentIDStr(Nan::To<v8::String>(paramOneInstrumentIDObj).ToLocalChecked());
  strcpy_s(field.InstrumentID,301,*paramOneInstrumentIDStr);

 //InstrumentStatus
  v8::Local<v8::Object> paramOneInstrumentStatusObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("InstrumentStatus").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneInstrumentStatusStr=Nan::To<v8::Integer>( paramOneInstrumentStatusObj).ToLocalChecked();
  field.InstrumentStatus=paramOneInstrumentStatusStr->Value()-48;

 //TradingSegmentSN
  v8::Local<v8::Object> paramOneTradingSegmentSNObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TradingSegmentSN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTradingSegmentSNStr=Nan::To<v8::Integer>( paramOneTradingSegmentSNObj).ToLocalChecked();
  field.TradingSegmentSN=paramOneTradingSegmentSNStr->Value();

 //EnterTime
  v8::Local<v8::Object> paramOneEnterTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EnterTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEnterTimeStr(Nan::To<v8::String>(paramOneEnterTimeObj).ToLocalChecked());
  strcpy_s(field.EnterTime,81,*paramOneEnterTimeStr);

 //EnterReason
  v8::Local<v8::Object> paramOneEnterReasonObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EnterReason").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEnterReasonStr=Nan::To<v8::Integer>( paramOneEnterReasonObj).ToLocalChecked();
  field.EnterReason=paramOneEnterReasonStr->Value()-48;

 //EnterDate
  v8::Local<v8::Object> paramOneEnterDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EnterDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEnterDateStr(Nan::To<v8::String>(paramOneEnterDateObj).ToLocalChecked());
  strcpy_s(field.EnterDate,81,*paramOneEnterDateStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryInstrumentStatusTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryCurrTradingSegmentAttrTopic){
  std::cout<<"ReqQryCurrTradingSegmentAttrTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryCurrTradingSegmentAttrField field;

 //SettlementGroupID
  v8::Local<v8::Object> paramOneSettlementGroupIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SettlementGroupID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSettlementGroupIDStr(Nan::To<v8::String>(paramOneSettlementGroupIDObj).ToLocalChecked());
  strcpy_s(field.SettlementGroupID,81,*paramOneSettlementGroupIDStr);

 //TradingSegmentSN
  v8::Local<v8::Object> paramOneTradingSegmentSNObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TradingSegmentSN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTradingSegmentSNStr=Nan::To<v8::Integer>( paramOneTradingSegmentSNObj).ToLocalChecked();
  field.TradingSegmentSN=paramOneTradingSegmentSNStr->Value();

 //TradingSegmentName
  v8::Local<v8::Object> paramOneTradingSegmentNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TradingSegmentName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTradingSegmentNameStr(Nan::To<v8::String>(paramOneTradingSegmentNameObj).ToLocalChecked());
  strcpy_s(field.TradingSegmentName,201,*paramOneTradingSegmentNameStr);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimeStr(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimeStr);

 //InstrumentStatus
  v8::Local<v8::Object> paramOneInstrumentStatusObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("InstrumentStatus").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneInstrumentStatusStr=Nan::To<v8::Integer>( paramOneInstrumentStatusObj).ToLocalChecked();
  field.InstrumentStatus=paramOneInstrumentStatusStr->Value()-48;

 //InstrumentID
  v8::Local<v8::Object> paramOneInstrumentIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("InstrumentID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInstrumentIDStr(Nan::To<v8::String>(paramOneInstrumentIDObj).ToLocalChecked());
  strcpy_s(field.InstrumentID,301,*paramOneInstrumentIDStr);

 //AdvanceDays
  v8::Local<v8::Object> paramOneAdvanceDaysObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AdvanceDays").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneAdvanceDaysStr=Nan::To<v8::Integer>( paramOneAdvanceDaysObj).ToLocalChecked();
  field.AdvanceDays=paramOneAdvanceDaysStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryCurrTradingSegmentAttrTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryRealTimeNetObjectAttrTopic){
  std::cout<<"ReqQryRealTimeNetObjectAttrTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryRealTimeNetObjectAttrField field;

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDStr);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypeStr(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,2561,*paramOneAttrTypeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryRealTimeNetObjectAttrTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetAreaTopic){
  std::cout<<"ReqQryNetAreaTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetAreaField field;

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetAreaTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetSubAreaTopic){
  std::cout<<"ReqQryNetSubAreaTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetSubAreaField field;

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //SysNetAreaID
  v8::Local<v8::Object> paramOneSysNetAreaIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetAreaID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetAreaIDStr=Nan::To<v8::Integer>( paramOneSysNetAreaIDObj).ToLocalChecked();
  field.SysNetAreaID=paramOneSysNetAreaIDStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetSubAreaTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetSubAreaIPTopic){
  std::cout<<"ReqQryNetSubAreaIPTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetSubAreaIPField field;

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //SysNetAreaID
  v8::Local<v8::Object> paramOneSysNetAreaIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetAreaID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetAreaIDStr=Nan::To<v8::Integer>( paramOneSysNetAreaIDObj).ToLocalChecked();
  field.SysNetAreaID=paramOneSysNetAreaIDStr->Value();

 //SysNetSubAreaID
  v8::Local<v8::Object> paramOneSysNetSubAreaIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetSubAreaID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetSubAreaIDStr=Nan::To<v8::Integer>( paramOneSysNetSubAreaIDObj).ToLocalChecked();
  field.SysNetSubAreaID=paramOneSysNetSubAreaIDStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetSubAreaIPTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetDeviceDetectTopic){
  std::cout<<"ReqQryNetDeviceDetectTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetDeviceDetectField field;

 //SysNetAreaID
  v8::Local<v8::Object> paramOneSysNetAreaIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetAreaID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetAreaIDStr=Nan::To<v8::Integer>( paramOneSysNetAreaIDObj).ToLocalChecked();
  field.SysNetAreaID=paramOneSysNetAreaIDStr->Value();

 //SysNetSubAreaID
  v8::Local<v8::Object> paramOneSysNetSubAreaIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetSubAreaID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetSubAreaIDStr=Nan::To<v8::Integer>( paramOneSysNetSubAreaIDObj).ToLocalChecked();
  field.SysNetSubAreaID=paramOneSysNetSubAreaIDStr->Value();

 //IP
  v8::Local<v8::Object> paramOneIPObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IP").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPStr(Nan::To<v8::String>(paramOneIPObj).ToLocalChecked());
  strcpy_s(field.IP,151,*paramOneIPStr);

 //Mask
  v8::Local<v8::Object> paramOneMaskObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Mask").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMaskStr(Nan::To<v8::String>(paramOneMaskObj).ToLocalChecked());
  strcpy_s(field.Mask,151,*paramOneMaskStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetDeviceDetectTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetDeviceRequestTopic){
  std::cout<<"ReqQryNetDeviceRequestTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetDeviceRequestField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //SysNetSubAreaID
  v8::Local<v8::Object> paramOneSysNetSubAreaIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetSubAreaID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetSubAreaIDStr=Nan::To<v8::Integer>( paramOneSysNetSubAreaIDObj).ToLocalChecked();
  field.SysNetSubAreaID=paramOneSysNetSubAreaIDStr->Value();

 //FuctionArea
  v8::Local<v8::Object> paramOneFuctionAreaObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FuctionArea").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFuctionAreaStr(Nan::To<v8::String>(paramOneFuctionAreaObj).ToLocalChecked());
  strcpy_s(field.FuctionArea,641,*paramOneFuctionAreaStr);

 //IPDECODE
  v8::Local<v8::Object> paramOneIPDECODEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPDECODE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIPDECODEStr=Nan::To<v8::Integer>( paramOneIPDECODEObj).ToLocalChecked();
  field.IPDECODE=paramOneIPDECODEStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetDeviceRequestTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetBuildingTopic){
  std::cout<<"ReqQryNetBuildingTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetBuildingField field;

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetBuildingTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetRoomTopic){
  std::cout<<"ReqQryNetRoomTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetRoomField field;

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //SysNetBuildingID
  v8::Local<v8::Object> paramOneSysNetBuildingIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetBuildingID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetBuildingIDStr=Nan::To<v8::Integer>( paramOneSysNetBuildingIDObj).ToLocalChecked();
  field.SysNetBuildingID=paramOneSysNetBuildingIDStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetRoomTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetCabinetsTopic){
  std::cout<<"ReqQryNetCabinetsTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetCabinetsField field;

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //SysNetRoomID
  v8::Local<v8::Object> paramOneSysNetRoomIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetRoomID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetRoomIDStr=Nan::To<v8::Integer>( paramOneSysNetRoomIDObj).ToLocalChecked();
  field.SysNetRoomID=paramOneSysNetRoomIDStr->Value();

 //SysNetBuildingID
  v8::Local<v8::Object> paramOneSysNetBuildingIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetBuildingID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetBuildingIDStr=Nan::To<v8::Integer>( paramOneSysNetBuildingIDObj).ToLocalChecked();
  field.SysNetBuildingID=paramOneSysNetBuildingIDStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetCabinetsTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetOIDTopic){
  std::cout<<"ReqQryNetOIDTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetOIDField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //Manufactory
  v8::Local<v8::Object> paramOneManufactoryObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Manufactory").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneManufactoryStr(Nan::To<v8::String>(paramOneManufactoryObj).ToLocalChecked());
  strcpy_s(field.Manufactory,641,*paramOneManufactoryStr);

 //DeviceType
  v8::Local<v8::Object> paramOneDeviceTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDeviceTypeStr(Nan::To<v8::String>(paramOneDeviceTypeObj).ToLocalChecked());
  strcpy_s(field.DeviceType,641,*paramOneDeviceTypeStr);

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNameStr(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNameStr);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENameStr(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENameStr);

 //OID
  v8::Local<v8::Object> paramOneOIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOIDStr(Nan::To<v8::String>(paramOneOIDObj).ToLocalChecked());
  strcpy_s(field.OID,641,*paramOneOIDStr);

 //Unit
  v8::Local<v8::Object> paramOneUnitObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Unit").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUnitStr(Nan::To<v8::String>(paramOneUnitObj).ToLocalChecked());
  strcpy_s(field.Unit,641,*paramOneUnitStr);

 //isTheTable
  v8::Local<v8::Object> paramOneisTheTableObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("isTheTable").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneisTheTableStr=Nan::To<v8::Integer>( paramOneisTheTableObj).ToLocalChecked();
  field.isTheTable=paramOneisTheTableStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetOIDTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetTimePolicyTopic){
  std::cout<<"ReqQryNetTimePolicyTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetTimePolicyField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNameStr(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNameStr);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENameStr(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENameStr);

 //PolicyType
  v8::Local<v8::Object> paramOnePolicyTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PolicyType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOnePolicyTypeStr=Nan::To<v8::Integer>( paramOnePolicyTypeObj).ToLocalChecked();
  field.PolicyType=paramOnePolicyTypeStr->Value();

 //PolicyString
  v8::Local<v8::Object> paramOnePolicyStringObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PolicyString").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePolicyStringStr(Nan::To<v8::String>(paramOnePolicyStringObj).ToLocalChecked());
  strcpy_s(field.PolicyString,5121,*paramOnePolicyStringStr);

 //TradingDay
  v8::Local<v8::Object> paramOneTradingDayObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TradingDay").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTradingDayStr=Nan::To<v8::Integer>( paramOneTradingDayObj).ToLocalChecked();
  field.TradingDay=paramOneTradingDayStr->Value();

 //Description
  v8::Local<v8::Object> paramOneDescriptionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Description").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDescriptionStr(Nan::To<v8::String>(paramOneDescriptionObj).ToLocalChecked());
  strcpy_s(field.Description,2561,*paramOneDescriptionStr);

 //Operation
  v8::Local<v8::Object> paramOneOperationObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Operation").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationStr=Nan::To<v8::Integer>( paramOneOperationObj).ToLocalChecked();
  field.Operation=paramOneOperationStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetTimePolicyTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetGatherTaskTopic){
  std::cout<<"ReqQryNetGatherTaskTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetGatherTaskField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDStr);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypeStr(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,2561,*paramOneAttrTypeStr);

 //PolicyTypeID
  v8::Local<v8::Object> paramOnePolicyTypeIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PolicyTypeID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOnePolicyTypeIDStr=Nan::To<v8::Integer>( paramOnePolicyTypeIDObj).ToLocalChecked();
  field.PolicyTypeID=paramOnePolicyTypeIDStr->Value();

 //DataType
  v8::Local<v8::Object> paramOneDataTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DataType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDataTypeStr=Nan::To<v8::Integer>( paramOneDataTypeObj).ToLocalChecked();
  field.DataType=paramOneDataTypeStr->Value();

 //TypeFlag
  v8::Local<v8::Object> paramOneTypeFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TypeFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTypeFlagStr=Nan::To<v8::Integer>( paramOneTypeFlagObj).ToLocalChecked();
  field.TypeFlag=paramOneTypeFlagStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetGatherTaskTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetDeviceChgTopic){
  std::cout<<"ReqQryNetDeviceChgTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetDeviceChgField field;

 //DeviceID
  v8::Local<v8::Object> paramOneDeviceIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDeviceIDStr=Nan::To<v8::Integer>( paramOneDeviceIDObj).ToLocalChecked();
  field.DeviceID=paramOneDeviceIDStr->Value();

 //SysNetSubAreaID
  v8::Local<v8::Object> paramOneSysNetSubAreaIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetSubAreaID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetSubAreaIDStr=Nan::To<v8::Integer>( paramOneSysNetSubAreaIDObj).ToLocalChecked();
  field.SysNetSubAreaID=paramOneSysNetSubAreaIDStr->Value();

 //OldObjectID
  v8::Local<v8::Object> paramOneOldObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OldObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOldObjectIDStr(Nan::To<v8::String>(paramOneOldObjectIDObj).ToLocalChecked());
  strcpy_s(field.OldObjectID,1281,*paramOneOldObjectIDStr);

 //NewObjectID
  v8::Local<v8::Object> paramOneNewObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("NewObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneNewObjectIDStr(Nan::To<v8::String>(paramOneNewObjectIDObj).ToLocalChecked());
  strcpy_s(field.NewObjectID,1281,*paramOneNewObjectIDStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetDeviceChgTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetDeviceTypeTopic){
  std::cout<<"ReqQryNetDeviceTypeTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetDeviceTypeField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //Manufactory
  v8::Local<v8::Object> paramOneManufactoryObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Manufactory").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneManufactoryStr(Nan::To<v8::String>(paramOneManufactoryObj).ToLocalChecked());
  strcpy_s(field.Manufactory,641,*paramOneManufactoryStr);

 //DeviceType
  v8::Local<v8::Object> paramOneDeviceTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDeviceTypeStr(Nan::To<v8::String>(paramOneDeviceTypeObj).ToLocalChecked());
  strcpy_s(field.DeviceType,641,*paramOneDeviceTypeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetDeviceTypeTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetDeviceCategoryTopic){
  std::cout<<"ReqQryNetDeviceCategoryTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetDeviceCategoryField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNameStr(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNameStr);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENameStr(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENameStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetDeviceCategoryTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetManufactoryTopic){
  std::cout<<"ReqQryNetManufactoryTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetManufactoryField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNameStr(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNameStr);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENameStr(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENameStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetManufactoryTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetCommunityTopic){
  std::cout<<"ReqQryNetCommunityTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetCommunityField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //IPADDR
  v8::Local<v8::Object> paramOneIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPADDRStr(Nan::To<v8::String>(paramOneIPADDRObj).ToLocalChecked());
  strcpy_s(field.IPADDR,151,*paramOneIPADDRStr);

 //COMMUNITY
  v8::Local<v8::Object> paramOneCOMMUNITYObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("COMMUNITY").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCOMMUNITYStr(Nan::To<v8::String>(paramOneCOMMUNITYObj).ToLocalChecked());
  strcpy_s(field.COMMUNITY,641,*paramOneCOMMUNITYStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetCommunityTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetPortTypeTopic){
  std::cout<<"ReqQryNetPortTypeTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetPortTypeField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNameStr(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNameStr);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENameStr(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENameStr);

 //Description
  v8::Local<v8::Object> paramOneDescriptionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Description").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDescriptionStr(Nan::To<v8::String>(paramOneDescriptionObj).ToLocalChecked());
  strcpy_s(field.Description,641,*paramOneDescriptionStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetPortTypeTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetPartAccessSpotTopic){
  std::cout<<"ReqQryNetPartAccessSpotTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetPartAccessSpotField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNameStr(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNameStr);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENameStr(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENameStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetPartAccessSpotTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetInterfaceTopic){
  std::cout<<"ReqQryNetInterfaceTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetInterfaceField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDStr);

 //MonitorType_ID
  v8::Local<v8::Object> paramOneMonitorType_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonitorType_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneMonitorType_IDStr=Nan::To<v8::Integer>( paramOneMonitorType_IDObj).ToLocalChecked();
  field.MonitorType_ID=paramOneMonitorType_IDStr->Value();

 //IfType
  v8::Local<v8::Object> paramOneIfTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IfType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIfTypeStr=Nan::To<v8::Integer>( paramOneIfTypeObj).ToLocalChecked();
  field.IfType=paramOneIfTypeStr->Value();

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENameStr(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENameStr);

 //IpAddress
  v8::Local<v8::Object> paramOneIpAddressObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IpAddress").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIpAddressStr(Nan::To<v8::String>(paramOneIpAddressObj).ToLocalChecked());
  strcpy_s(field.IpAddress,151,*paramOneIpAddressStr);

 //IpMask
  v8::Local<v8::Object> paramOneIpMaskObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IpMask").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIpMaskStr(Nan::To<v8::String>(paramOneIpMaskObj).ToLocalChecked());
  strcpy_s(field.IpMask,151,*paramOneIpMaskStr);

 //IfStatus
  v8::Local<v8::Object> paramOneIfStatusObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IfStatus").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIfStatusStr=Nan::To<v8::Integer>( paramOneIfStatusObj).ToLocalChecked();
  field.IfStatus=paramOneIfStatusStr->Value();

 //MAC
  v8::Local<v8::Object> paramOneMACObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MAC").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMACStr(Nan::To<v8::String>(paramOneMACObj).ToLocalChecked());
  strcpy_s(field.MAC,641,*paramOneMACStr);

 //DeviceID
  v8::Local<v8::Object> paramOneDeviceIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDeviceIDStr=Nan::To<v8::Integer>( paramOneDeviceIDObj).ToLocalChecked();
  field.DeviceID=paramOneDeviceIDStr->Value();

 //DeviceObjectID
  v8::Local<v8::Object> paramOneDeviceObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDeviceObjectIDStr(Nan::To<v8::String>(paramOneDeviceObjectIDObj).ToLocalChecked());
  strcpy_s(field.DeviceObjectID,1281,*paramOneDeviceObjectIDStr);

 //DeviceIndex
  v8::Local<v8::Object> paramOneDeviceIndexObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceIndex").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDeviceIndexStr(Nan::To<v8::String>(paramOneDeviceIndexObj).ToLocalChecked());
  strcpy_s(field.DeviceIndex,161,*paramOneDeviceIndexStr);

 //isPolling
  v8::Local<v8::Object> paramOneisPollingObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("isPolling").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneisPollingStr=Nan::To<v8::Integer>( paramOneisPollingObj).ToLocalChecked();
  field.isPolling=paramOneisPollingStr->Value();

 //Description
  v8::Local<v8::Object> paramOneDescriptionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Description").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDescriptionStr(Nan::To<v8::String>(paramOneDescriptionObj).ToLocalChecked());
  strcpy_s(field.Description,641,*paramOneDescriptionStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetInterfaceTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetGeneralOIDTopic){
  std::cout<<"ReqQryNetGeneralOIDTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetGeneralOIDField field;

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetGeneralOIDTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetMonitorTypeTopic){
  std::cout<<"ReqQryNetMonitorTypeTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetMonitorTypeField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNameStr(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNameStr);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENameStr(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENameStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetMonitorTypeTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetMonitorAttrScopeTopic){
  std::cout<<"ReqQryNetMonitorAttrScopeTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetMonitorAttrScopeField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNameStr(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,2561,*paramOneCNameStr);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENameStr(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,2561,*paramOneENameStr);

 //Comments
  v8::Local<v8::Object> paramOneCommentsObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Comments").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCommentsStr(Nan::To<v8::String>(paramOneCommentsObj).ToLocalChecked());
  strcpy_s(field.Comments,2561,*paramOneCommentsStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetMonitorAttrScopeTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetMonitorAttrTypeTopic){
  std::cout<<"ReqQryNetMonitorAttrTypeTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetMonitorAttrTypeField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //MANUFACTORY_ID
  v8::Local<v8::Object> paramOneMANUFACTORY_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MANUFACTORY_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneMANUFACTORY_IDStr=Nan::To<v8::Integer>( paramOneMANUFACTORY_IDObj).ToLocalChecked();
  field.MANUFACTORY_ID=paramOneMANUFACTORY_IDStr->Value();

 //MonitorType_ID
  v8::Local<v8::Object> paramOneMonitorType_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonitorType_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneMonitorType_IDStr=Nan::To<v8::Integer>( paramOneMonitorType_IDObj).ToLocalChecked();
  field.MonitorType_ID=paramOneMonitorType_IDStr->Value();

 //AttrType_ID
  v8::Local<v8::Object> paramOneAttrType_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneAttrType_IDStr=Nan::To<v8::Integer>( paramOneAttrType_IDObj).ToLocalChecked();
  field.AttrType_ID=paramOneAttrType_IDStr->Value();

 //MANUFACTORY
  v8::Local<v8::Object> paramOneMANUFACTORYObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MANUFACTORY").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMANUFACTORYStr(Nan::To<v8::String>(paramOneMANUFACTORYObj).ToLocalChecked());
  strcpy_s(field.MANUFACTORY,641,*paramOneMANUFACTORYStr);

 //MonitorType
  v8::Local<v8::Object> paramOneMonitorTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonitorType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonitorTypeStr(Nan::To<v8::String>(paramOneMonitorTypeObj).ToLocalChecked());
  strcpy_s(field.MonitorType,641,*paramOneMonitorTypeStr);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypeStr(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,2561,*paramOneAttrTypeStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetMonitorAttrTypeTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetMonitorObjectAttrTopic){
  std::cout<<"ReqQryNetMonitorObjectAttrTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetMonitorObjectAttrField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDStr);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypeStr(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,2561,*paramOneAttrTypeStr);

 //PolicyTypeID
  v8::Local<v8::Object> paramOnePolicyTypeIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PolicyTypeID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOnePolicyTypeIDStr=Nan::To<v8::Integer>( paramOnePolicyTypeIDObj).ToLocalChecked();
  field.PolicyTypeID=paramOnePolicyTypeIDStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetMonitorObjectAttrTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetMonitorDeviceGroupTopic){
  std::cout<<"ReqQryNetMonitorDeviceGroupTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetMonitorDeviceGroupField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNameStr(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNameStr);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENameStr(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENameStr);

 //Condition
  v8::Local<v8::Object> paramOneConditionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Condition").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneConditionStr(Nan::To<v8::String>(paramOneConditionObj).ToLocalChecked());
  strcpy_s(field.Condition,5121,*paramOneConditionStr);

 //Comments
  v8::Local<v8::Object> paramOneCommentsObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Comments").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCommentsStr(Nan::To<v8::String>(paramOneCommentsObj).ToLocalChecked());
  strcpy_s(field.Comments,2561,*paramOneCommentsStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetMonitorDeviceGroupTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetMonitorTaskInfoTopic){
  std::cout<<"ReqQryNetMonitorTaskInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetMonitorTaskInfoField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNameStr(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNameStr);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENameStr(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENameStr);

 //DeviceGroup_ID
  v8::Local<v8::Object> paramOneDeviceGroup_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceGroup_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDeviceGroup_IDStr=Nan::To<v8::Integer>( paramOneDeviceGroup_IDObj).ToLocalChecked();
  field.DeviceGroup_ID=paramOneDeviceGroup_IDStr->Value();

 //ManagerGroup_ID
  v8::Local<v8::Object> paramOneManagerGroup_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ManagerGroup_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneManagerGroup_IDStr=Nan::To<v8::Integer>( paramOneManagerGroup_IDObj).ToLocalChecked();
  field.ManagerGroup_ID=paramOneManagerGroup_IDStr->Value();

 //TimePolicy_ID
  v8::Local<v8::Object> paramOneTimePolicy_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TimePolicy_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTimePolicy_IDStr=Nan::To<v8::Integer>( paramOneTimePolicy_IDObj).ToLocalChecked();
  field.TimePolicy_ID=paramOneTimePolicy_IDStr->Value();

 //TaskPriority_ID
  v8::Local<v8::Object> paramOneTaskPriority_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TaskPriority_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTaskPriority_IDStr=Nan::To<v8::Integer>( paramOneTaskPriority_IDObj).ToLocalChecked();
  field.TaskPriority_ID=paramOneTaskPriority_IDStr->Value();

 //OutputPolicy_ID
  v8::Local<v8::Object> paramOneOutputPolicy_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OutputPolicy_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOutputPolicy_IDStr=Nan::To<v8::Integer>( paramOneOutputPolicy_IDObj).ToLocalChecked();
  field.OutputPolicy_ID=paramOneOutputPolicy_IDStr->Value();

 //ActionGroup_ID
  v8::Local<v8::Object> paramOneActionGroup_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ActionGroup_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneActionGroup_IDStr=Nan::To<v8::Integer>( paramOneActionGroup_IDObj).ToLocalChecked();
  field.ActionGroup_ID=paramOneActionGroup_IDStr->Value();

 //EventExprStr
  v8::Local<v8::Object> paramOneEventExprStrObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventExprStr").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventExprStrStr(Nan::To<v8::String>(paramOneEventExprStrObj).ToLocalChecked());
  strcpy_s(field.EventExprStr,10241,*paramOneEventExprStrStr);

 //DeviceGroup
  v8::Local<v8::Object> paramOneDeviceGroupObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceGroup").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDeviceGroupStr(Nan::To<v8::String>(paramOneDeviceGroupObj).ToLocalChecked());
  strcpy_s(field.DeviceGroup,641,*paramOneDeviceGroupStr);

 //ManagerGroup
  v8::Local<v8::Object> paramOneManagerGroupObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ManagerGroup").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneManagerGroupStr(Nan::To<v8::String>(paramOneManagerGroupObj).ToLocalChecked());
  strcpy_s(field.ManagerGroup,641,*paramOneManagerGroupStr);

 //TimePolicy
  v8::Local<v8::Object> paramOneTimePolicyObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TimePolicy").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTimePolicyStr(Nan::To<v8::String>(paramOneTimePolicyObj).ToLocalChecked());
  strcpy_s(field.TimePolicy,641,*paramOneTimePolicyStr);

 //TaskPriority
  v8::Local<v8::Object> paramOneTaskPriorityObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TaskPriority").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTaskPriorityStr(Nan::To<v8::String>(paramOneTaskPriorityObj).ToLocalChecked());
  strcpy_s(field.TaskPriority,641,*paramOneTaskPriorityStr);

 //OutputPolicy
  v8::Local<v8::Object> paramOneOutputPolicyObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OutputPolicy").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOutputPolicyStr(Nan::To<v8::String>(paramOneOutputPolicyObj).ToLocalChecked());
  strcpy_s(field.OutputPolicy,641,*paramOneOutputPolicyStr);

 //ActionGroup
  v8::Local<v8::Object> paramOneActionGroupObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ActionGroup").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneActionGroupStr(Nan::To<v8::String>(paramOneActionGroupObj).ToLocalChecked());
  strcpy_s(field.ActionGroup,641,*paramOneActionGroupStr);

 //ValidFlag
  v8::Local<v8::Object> paramOneValidFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ValidFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneValidFlagStr=Nan::To<v8::Integer>( paramOneValidFlagObj).ToLocalChecked();
  field.ValidFlag=paramOneValidFlagStr->Value();

 //TaskStatus
  v8::Local<v8::Object> paramOneTaskStatusObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TaskStatus").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTaskStatusStr=Nan::To<v8::Integer>( paramOneTaskStatusObj).ToLocalChecked();
  field.TaskStatus=paramOneTaskStatusStr->Value();

 //Comments
  v8::Local<v8::Object> paramOneCommentsObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Comments").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCommentsStr(Nan::To<v8::String>(paramOneCommentsObj).ToLocalChecked());
  strcpy_s(field.Comments,2561,*paramOneCommentsStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetMonitorTaskInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetMonitorTaskResultTopic){
  std::cout<<"ReqQryNetMonitorTaskResultTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetMonitorTaskResultField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDStr);

 //Task_ID
  v8::Local<v8::Object> paramOneTask_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Task_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTask_IDStr=Nan::To<v8::Integer>( paramOneTask_IDObj).ToLocalChecked();
  field.Task_ID=paramOneTask_IDStr->Value();

 //OperateTime
  v8::Local<v8::Object> paramOneOperateTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperateTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperateTimeStr=Nan::To<v8::Integer>( paramOneOperateTimeObj).ToLocalChecked();
  field.OperateTime=paramOneOperateTimeStr->Value();

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDateStr(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDateStr);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimeStr(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimeStr);

 //InstructChain
  v8::Local<v8::Object> paramOneInstructChainObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("InstructChain").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInstructChainStr(Nan::To<v8::String>(paramOneInstructChainObj).ToLocalChecked());
  strcpy_s(field.InstructChain,2561,*paramOneInstructChainStr);

 //ResultChain
  v8::Local<v8::Object> paramOneResultChainObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ResultChain").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneResultChainStr(Nan::To<v8::String>(paramOneResultChainObj).ToLocalChecked());
  strcpy_s(field.ResultChain,10241,*paramOneResultChainStr);

 //Flag
  v8::Local<v8::Object> paramOneFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Flag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneFlagStr=Nan::To<v8::Integer>( paramOneFlagObj).ToLocalChecked();
  field.Flag=paramOneFlagStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetMonitorTaskResultTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetMonitorTaskObjectSetTopic){
  std::cout<<"ReqQryNetMonitorTaskObjectSetTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetMonitorTaskObjectSetField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //DeviceGroup_ID
  v8::Local<v8::Object> paramOneDeviceGroup_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceGroup_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDeviceGroup_IDStr=Nan::To<v8::Integer>( paramOneDeviceGroup_IDObj).ToLocalChecked();
  field.DeviceGroup_ID=paramOneDeviceGroup_IDStr->Value();

 //Device_ID
  v8::Local<v8::Object> paramOneDevice_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Device_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDevice_IDStr=Nan::To<v8::Integer>( paramOneDevice_IDObj).ToLocalChecked();
  field.Device_ID=paramOneDevice_IDStr->Value();

 //DataCenter
  v8::Local<v8::Object> paramOneDataCenterObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DataCenter").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDataCenterStr=Nan::To<v8::Integer>( paramOneDataCenterObj).ToLocalChecked();
  field.DataCenter=paramOneDataCenterStr->Value()-48;

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetMonitorTaskObjectSetTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetPartyLinkInfoTopic){
  std::cout<<"ReqQryNetPartyLinkInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetPartyLinkInfoField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //MEMBER_NO
  v8::Local<v8::Object> paramOneMEMBER_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MEMBER_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMEMBER_NOStr(Nan::To<v8::String>(paramOneMEMBER_NOObj).ToLocalChecked());
  strcpy_s(field.MEMBER_NO,321,*paramOneMEMBER_NOStr);

 //MEMBER_NAME
  v8::Local<v8::Object> paramOneMEMBER_NAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MEMBER_NAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMEMBER_NAMEStr(Nan::To<v8::String>(paramOneMEMBER_NAMEObj).ToLocalChecked());
  strcpy_s(field.MEMBER_NAME,641,*paramOneMEMBER_NAMEStr);

 //REMOTE_ADDR
  v8::Local<v8::Object> paramOneREMOTE_ADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("REMOTE_ADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneREMOTE_ADDRStr(Nan::To<v8::String>(paramOneREMOTE_ADDRObj).ToLocalChecked());
  strcpy_s(field.REMOTE_ADDR,641,*paramOneREMOTE_ADDRStr);

 //LOCAL_ADDR
  v8::Local<v8::Object> paramOneLOCAL_ADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("LOCAL_ADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneLOCAL_ADDRStr(Nan::To<v8::String>(paramOneLOCAL_ADDRObj).ToLocalChecked());
  strcpy_s(field.LOCAL_ADDR,641,*paramOneLOCAL_ADDRStr);

 //ADDRESS
  v8::Local<v8::Object> paramOneADDRESSObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ADDRESS").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneADDRESSStr(Nan::To<v8::String>(paramOneADDRESSObj).ToLocalChecked());
  strcpy_s(field.ADDRESS,2561,*paramOneADDRESSStr);

 //LINE_STATUS
  v8::Local<v8::Object> paramOneLINE_STATUSObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("LINE_STATUS").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneLINE_STATUSStr(Nan::To<v8::String>(paramOneLINE_STATUSObj).ToLocalChecked());
  strcpy_s(field.LINE_STATUS,321,*paramOneLINE_STATUSStr);

 //CONTACT
  v8::Local<v8::Object> paramOneCONTACTObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CONTACT").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCONTACTStr(Nan::To<v8::String>(paramOneCONTACTObj).ToLocalChecked());
  strcpy_s(field.CONTACT,321,*paramOneCONTACTStr);

 //TELEPHONE
  v8::Local<v8::Object> paramOneTELEPHONEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TELEPHONE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTELEPHONEStr(Nan::To<v8::String>(paramOneTELEPHONEObj).ToLocalChecked());
  strcpy_s(field.TELEPHONE,641,*paramOneTELEPHONEStr);

 //MOBILEPHONE
  v8::Local<v8::Object> paramOneMOBILEPHONEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MOBILEPHONE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMOBILEPHONEStr(Nan::To<v8::String>(paramOneMOBILEPHONEObj).ToLocalChecked());
  strcpy_s(field.MOBILEPHONE,641,*paramOneMOBILEPHONEStr);

 //EMAIL
  v8::Local<v8::Object> paramOneEMAILObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EMAIL").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEMAILStr(Nan::To<v8::String>(paramOneEMAILObj).ToLocalChecked());
  strcpy_s(field.EMAIL,641,*paramOneEMAILStr);

 //FAX
  v8::Local<v8::Object> paramOneFAXObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FAX").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFAXStr(Nan::To<v8::String>(paramOneFAXObj).ToLocalChecked());
  strcpy_s(field.FAX,641,*paramOneFAXStr);

 //PROVINCE
  v8::Local<v8::Object> paramOnePROVINCEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PROVINCE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePROVINCEStr(Nan::To<v8::String>(paramOnePROVINCEObj).ToLocalChecked());
  strcpy_s(field.PROVINCE,321,*paramOnePROVINCEStr);

 //DDN_NO
  v8::Local<v8::Object> paramOneDDN_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DDN_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDDN_NOStr(Nan::To<v8::String>(paramOneDDN_NOObj).ToLocalChecked());
  strcpy_s(field.DDN_NO,641,*paramOneDDN_NOStr);

 //IN_MODE
  v8::Local<v8::Object> paramOneIN_MODEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IN_MODE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIN_MODEStr(Nan::To<v8::String>(paramOneIN_MODEObj).ToLocalChecked());
  strcpy_s(field.IN_MODE,641,*paramOneIN_MODEStr);

 //IP_WAN
  v8::Local<v8::Object> paramOneIP_WANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IP_WAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIP_WANStr(Nan::To<v8::String>(paramOneIP_WANObj).ToLocalChecked());
  strcpy_s(field.IP_WAN,641,*paramOneIP_WANStr);

 //IP_LAN
  v8::Local<v8::Object> paramOneIP_LANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IP_LAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIP_LANStr(Nan::To<v8::String>(paramOneIP_LANObj).ToLocalChecked());
  strcpy_s(field.IP_LAN,641,*paramOneIP_LANStr);

 //IPADDR
  v8::Local<v8::Object> paramOneIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPADDRStr(Nan::To<v8::String>(paramOneIPADDRObj).ToLocalChecked());
  strcpy_s(field.IPADDR,641,*paramOneIPADDRStr);

 //Interface
  v8::Local<v8::Object> paramOneInterfaceObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Interface").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInterfaceStr(Nan::To<v8::String>(paramOneInterfaceObj).ToLocalChecked());
  strcpy_s(field.Interface,641,*paramOneInterfaceStr);

 //INTERFACE_DATE
  v8::Local<v8::Object> paramOneINTERFACE_DATEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("INTERFACE_DATE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneINTERFACE_DATEStr(Nan::To<v8::String>(paramOneINTERFACE_DATEObj).ToLocalChecked());
  strcpy_s(field.INTERFACE_DATE,321,*paramOneINTERFACE_DATEStr);

 //SOFTWARE
  v8::Local<v8::Object> paramOneSOFTWAREObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SOFTWARE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSOFTWAREStr(Nan::To<v8::String>(paramOneSOFTWAREObj).ToLocalChecked());
  strcpy_s(field.SOFTWARE,321,*paramOneSOFTWAREStr);

 //FEE_TYPE
  v8::Local<v8::Object> paramOneFEE_TYPEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FEE_TYPE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFEE_TYPEStr(Nan::To<v8::String>(paramOneFEE_TYPEObj).ToLocalChecked());
  strcpy_s(field.FEE_TYPE,321,*paramOneFEE_TYPEStr);

 //SERVICEPROVIDER
  v8::Local<v8::Object> paramOneSERVICEPROVIDERObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SERVICEPROVIDER").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSERVICEPROVIDERStr(Nan::To<v8::String>(paramOneSERVICEPROVIDERObj).ToLocalChecked());
  strcpy_s(field.SERVICEPROVIDER,321,*paramOneSERVICEPROVIDERStr);

 //IF_ZIYING
  v8::Local<v8::Object> paramOneIF_ZIYINGObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IF_ZIYING").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIF_ZIYINGStr(Nan::To<v8::String>(paramOneIF_ZIYINGObj).ToLocalChecked());
  strcpy_s(field.IF_ZIYING,321,*paramOneIF_ZIYINGStr);

 //IF_TUOGUAN
  v8::Local<v8::Object> paramOneIF_TUOGUANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IF_TUOGUAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIF_TUOGUANStr(Nan::To<v8::String>(paramOneIF_TUOGUANObj).ToLocalChecked());
  strcpy_s(field.IF_TUOGUAN,321,*paramOneIF_TUOGUANStr);

 //HASOTHER
  v8::Local<v8::Object> paramOneHASOTHERObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HASOTHER").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHASOTHERStr(Nan::To<v8::String>(paramOneHASOTHERObj).ToLocalChecked());
  strcpy_s(field.HASOTHER,321,*paramOneHASOTHERStr);

 //SEAT_NO
  v8::Local<v8::Object> paramOneSEAT_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SEAT_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSEAT_NOStr(Nan::To<v8::String>(paramOneSEAT_NOObj).ToLocalChecked());
  strcpy_s(field.SEAT_NO,10241,*paramOneSEAT_NOStr);

 //PRO
  v8::Local<v8::Object> paramOnePROObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PRO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePROStr(Nan::To<v8::String>(paramOnePROObj).ToLocalChecked());
  strcpy_s(field.PRO,5121,*paramOnePROStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetPartyLinkInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetMonitorActionAttrTopic){
  std::cout<<"ReqQryNetMonitorActionAttrTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetMonitorActionAttrField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //ActionGroup_ID
  v8::Local<v8::Object> paramOneActionGroup_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ActionGroup_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneActionGroup_IDStr=Nan::To<v8::Integer>( paramOneActionGroup_IDObj).ToLocalChecked();
  field.ActionGroup_ID=paramOneActionGroup_IDStr->Value();

 //MonitorAttr_ID
  v8::Local<v8::Object> paramOneMonitorAttr_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonitorAttr_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneMonitorAttr_IDStr=Nan::To<v8::Integer>( paramOneMonitorAttr_IDObj).ToLocalChecked();
  field.MonitorAttr_ID=paramOneMonitorAttr_IDStr->Value();

 //MonitorAttrName
  v8::Local<v8::Object> paramOneMonitorAttrNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonitorAttrName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonitorAttrNameStr(Nan::To<v8::String>(paramOneMonitorAttrNameObj).ToLocalChecked());
  strcpy_s(field.MonitorAttrName,2561,*paramOneMonitorAttrNameStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetMonitorActionAttrTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetModuleTopic){
  std::cout<<"ReqQryNetModuleTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetModuleField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDStr);

 //MonitorType_ID
  v8::Local<v8::Object> paramOneMonitorType_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonitorType_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneMonitorType_IDStr=Nan::To<v8::Integer>( paramOneMonitorType_IDObj).ToLocalChecked();
  field.MonitorType_ID=paramOneMonitorType_IDStr->Value();

 //DeviceID
  v8::Local<v8::Object> paramOneDeviceIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDeviceIDStr=Nan::To<v8::Integer>( paramOneDeviceIDObj).ToLocalChecked();
  field.DeviceID=paramOneDeviceIDStr->Value();

 //DeviceObjectID
  v8::Local<v8::Object> paramOneDeviceObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDeviceObjectIDStr(Nan::To<v8::String>(paramOneDeviceObjectIDObj).ToLocalChecked());
  strcpy_s(field.DeviceObjectID,1281,*paramOneDeviceObjectIDStr);

 //Name
  v8::Local<v8::Object> paramOneNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Name").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneNameStr(Nan::To<v8::String>(paramOneNameObj).ToLocalChecked());
  strcpy_s(field.Name,641,*paramOneNameStr);

 //Description
  v8::Local<v8::Object> paramOneDescriptionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Description").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDescriptionStr(Nan::To<v8::String>(paramOneDescriptionObj).ToLocalChecked());
  strcpy_s(field.Description,1281,*paramOneDescriptionStr);

 //ModuleIndex
  v8::Local<v8::Object> paramOneModuleIndexObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ModuleIndex").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneModuleIndexStr=Nan::To<v8::Integer>( paramOneModuleIndexObj).ToLocalChecked();
  field.ModuleIndex=paramOneModuleIndexStr->Value();

 //EntPhyIndex
  v8::Local<v8::Object> paramOneEntPhyIndexObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EntPhyIndex").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEntPhyIndexStr=Nan::To<v8::Integer>( paramOneEntPhyIndexObj).ToLocalChecked();
  field.EntPhyIndex=paramOneEntPhyIndexStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetModuleTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetMonitorTaskStatusResultTopic){
  std::cout<<"ReqQryNetMonitorTaskStatusResultTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetMonitorTaskStatusResultField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDStr);

 //Task_ID
  v8::Local<v8::Object> paramOneTask_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Task_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTask_IDStr=Nan::To<v8::Integer>( paramOneTask_IDObj).ToLocalChecked();
  field.Task_ID=paramOneTask_IDStr->Value();

 //OperateTime
  v8::Local<v8::Object> paramOneOperateTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperateTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperateTimeStr=Nan::To<v8::Integer>( paramOneOperateTimeObj).ToLocalChecked();
  field.OperateTime=paramOneOperateTimeStr->Value();

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDateStr(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDateStr);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimeStr(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimeStr);

 //Flag
  v8::Local<v8::Object> paramOneFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Flag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneFlagStr=Nan::To<v8::Integer>( paramOneFlagObj).ToLocalChecked();
  field.Flag=paramOneFlagStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetMonitorTaskStatusResultTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetCfgFileTopic){
  std::cout<<"ReqQryNetCfgFileTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetCfgFileField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDStr);

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDateStr(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDateStr);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimeStr(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimeStr);

 //CfgFileName
  v8::Local<v8::Object> paramOneCfgFileNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CfgFileName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCfgFileNameStr(Nan::To<v8::String>(paramOneCfgFileNameObj).ToLocalChecked());
  strcpy_s(field.CfgFileName,2561,*paramOneCfgFileNameStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetCfgFileTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetMonitorDeviceTaskTopic){
  std::cout<<"ReqQryNetMonitorDeviceTaskTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetMonitorDeviceTaskField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDStr(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDStr);

 //IPAddress
  v8::Local<v8::Object> paramOneIPAddressObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPAddress").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPAddressStr(Nan::To<v8::String>(paramOneIPAddressObj).ToLocalChecked());
  strcpy_s(field.IPAddress,151,*paramOneIPAddressStr);

 //Manufactory_ID
  v8::Local<v8::Object> paramOneManufactory_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Manufactory_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneManufactory_IDStr=Nan::To<v8::Integer>( paramOneManufactory_IDObj).ToLocalChecked();
  field.Manufactory_ID=paramOneManufactory_IDStr->Value();

 //InstructChain
  v8::Local<v8::Object> paramOneInstructChainObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("InstructChain").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInstructChainStr(Nan::To<v8::String>(paramOneInstructChainObj).ToLocalChecked());
  strcpy_s(field.InstructChain,2561,*paramOneInstructChainStr);

 //InstructAlias
  v8::Local<v8::Object> paramOneInstructAliasObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("InstructAlias").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInstructAliasStr(Nan::To<v8::String>(paramOneInstructAliasObj).ToLocalChecked());
  strcpy_s(field.InstructAlias,1281,*paramOneInstructAliasStr);

 //InstructArgs
  v8::Local<v8::Object> paramOneInstructArgsObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("InstructArgs").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInstructArgsStr(Nan::To<v8::String>(paramOneInstructArgsObj).ToLocalChecked());
  strcpy_s(field.InstructArgs,2561,*paramOneInstructArgsStr);

 //DefParamChain
  v8::Local<v8::Object> paramOneDefParamChainObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DefParamChain").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDefParamChainStr(Nan::To<v8::String>(paramOneDefParamChainObj).ToLocalChecked());
  strcpy_s(field.DefParamChain,20001,*paramOneDefParamChainStr);

 //Flag
  v8::Local<v8::Object> paramOneFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Flag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneFlagStr=Nan::To<v8::Integer>( paramOneFlagObj).ToLocalChecked();
  field.Flag=paramOneFlagStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetMonitorDeviceTaskTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryFileGeneralOperTopic){
  std::cout<<"ReqQryFileGeneralOperTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryFileGeneralOperField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //FileName
  v8::Local<v8::Object> paramOneFileNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FileName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFileNameStr(Nan::To<v8::String>(paramOneFileNameObj).ToLocalChecked());
  strcpy_s(field.FileName,2561,*paramOneFileNameStr);

 //Version
  v8::Local<v8::Object> paramOneVersionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Version").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneVersionStr(Nan::To<v8::String>(paramOneVersionObj).ToLocalChecked());
  strcpy_s(field.Version,161,*paramOneVersionStr);

 //SubVersion
  v8::Local<v8::Object> paramOneSubVersionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SubVersion").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSubVersionStr=Nan::To<v8::Integer>( paramOneSubVersionObj).ToLocalChecked();
  field.SubVersion=paramOneSubVersionStr->Value();

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDateStr(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDateStr);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimeStr(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimeStr);

 //UserName
  v8::Local<v8::Object> paramOneUserNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUserNameStr(Nan::To<v8::String>(paramOneUserNameObj).ToLocalChecked());
  strcpy_s(field.UserName,201,*paramOneUserNameStr);

 //OperType
  v8::Local<v8::Object> paramOneOperTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperTypeStr=Nan::To<v8::Integer>( paramOneOperTypeObj).ToLocalChecked();
  field.OperType=paramOneOperTypeStr->Value();

 //OperResult
  v8::Local<v8::Object> paramOneOperResultObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperResult").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperResultStr=Nan::To<v8::Integer>( paramOneOperResultObj).ToLocalChecked();
  field.OperResult=paramOneOperResultStr->Value();

 //Comments
  v8::Local<v8::Object> paramOneCommentsObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Comments").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCommentsStr(Nan::To<v8::String>(paramOneCommentsObj).ToLocalChecked());
  strcpy_s(field.Comments,2561,*paramOneCommentsStr);

 //Offset
  v8::Local<v8::Object> paramOneOffsetObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Offset").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOffsetStr=Nan::To<v8::Integer>( paramOneOffsetObj).ToLocalChecked();
  field.Offset=paramOneOffsetStr->Value();

 //Length
  v8::Local<v8::Object> paramOneLengthObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Length").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneLengthStr=Nan::To<v8::Integer>( paramOneLengthObj).ToLocalChecked();
  field.Length=paramOneLengthStr->Value();

 //FileContent
  v8::Local<v8::Object> paramOneFileContentObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FileContent").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFileContentStr(Nan::To<v8::String>(paramOneFileContentObj).ToLocalChecked());
  strcpy_s(field.FileContent,30001,*paramOneFileContentStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryFileGeneralOperTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetBaseLineTopic){
  std::cout<<"ReqQryNetBaseLineTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetBaseLineField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //MANUFACTORY_ID
  v8::Local<v8::Object> paramOneMANUFACTORY_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MANUFACTORY_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneMANUFACTORY_IDStr=Nan::To<v8::Integer>( paramOneMANUFACTORY_IDObj).ToLocalChecked();
  field.MANUFACTORY_ID=paramOneMANUFACTORY_IDStr->Value();

 //Name
  v8::Local<v8::Object> paramOneNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Name").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneNameStr(Nan::To<v8::String>(paramOneNameObj).ToLocalChecked());
  strcpy_s(field.Name,1281,*paramOneNameStr);

 //SerialUsed
  v8::Local<v8::Object> paramOneSerialUsedObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SerialUsed").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSerialUsedStr(Nan::To<v8::String>(paramOneSerialUsedObj).ToLocalChecked());
  strcpy_s(field.SerialUsed,1281,*paramOneSerialUsedStr);

 //data
  v8::Local<v8::Object> paramOnedataObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("data").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnedataStr(Nan::To<v8::String>(paramOnedataObj).ToLocalChecked());
  strcpy_s(field.data,20001,*paramOnedataStr);

 //memo
  v8::Local<v8::Object> paramOnememoObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("memo").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnememoStr(Nan::To<v8::String>(paramOnememoObj).ToLocalChecked());
  strcpy_s(field.memo,2561,*paramOnememoStr);

 //Flag
  v8::Local<v8::Object> paramOneFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Flag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneFlagStr=Nan::To<v8::Integer>( paramOneFlagObj).ToLocalChecked();
  field.Flag=paramOneFlagStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetBaseLineTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetBaseLineResultTopic){
  std::cout<<"ReqQryNetBaseLineResultTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetBaseLineResultField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //BaseLineName
  v8::Local<v8::Object> paramOneBaseLineNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("BaseLineName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneBaseLineNameStr(Nan::To<v8::String>(paramOneBaseLineNameObj).ToLocalChecked());
  strcpy_s(field.BaseLineName,1281,*paramOneBaseLineNameStr);

 //DeviceObjID
  v8::Local<v8::Object> paramOneDeviceObjIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceObjID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDeviceObjIDStr(Nan::To<v8::String>(paramOneDeviceObjIDObj).ToLocalChecked());
  strcpy_s(field.DeviceObjID,1281,*paramOneDeviceObjIDStr);

 //DeviceIP
  v8::Local<v8::Object> paramOneDeviceIPObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceIP").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDeviceIPStr(Nan::To<v8::String>(paramOneDeviceIPObj).ToLocalChecked());
  strcpy_s(field.DeviceIP,151,*paramOneDeviceIPStr);

 //Result
  v8::Local<v8::Object> paramOneResultObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Result").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneResultStr(Nan::To<v8::String>(paramOneResultObj).ToLocalChecked());
  strcpy_s(field.Result,30001,*paramOneResultStr);

 //GenDate
  v8::Local<v8::Object> paramOneGenDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("GenDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneGenDateStr(Nan::To<v8::String>(paramOneGenDateObj).ToLocalChecked());
  strcpy_s(field.GenDate,81,*paramOneGenDateStr);

 //GenTime
  v8::Local<v8::Object> paramOneGenTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("GenTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneGenTimeStr(Nan::To<v8::String>(paramOneGenTimeObj).ToLocalChecked());
  strcpy_s(field.GenTime,81,*paramOneGenTimeStr);

 //GenUser
  v8::Local<v8::Object> paramOneGenUserObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("GenUser").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneGenUserStr(Nan::To<v8::String>(paramOneGenUserObj).ToLocalChecked());
  strcpy_s(field.GenUser,201,*paramOneGenUserStr);

 //Flag
  v8::Local<v8::Object> paramOneFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Flag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneFlagStr=Nan::To<v8::Integer>( paramOneFlagObj).ToLocalChecked();
  field.Flag=paramOneFlagStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetBaseLineResultTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetPartyLinkStatusInfoTopic){
  std::cout<<"ReqQryNetPartyLinkStatusInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetPartyLinkStatusInfoField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //KeyCompare
  v8::Local<v8::Object> paramOneKeyCompareObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeyCompare").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeyCompareStr=Nan::To<v8::Integer>( paramOneKeyCompareObj).ToLocalChecked();
  field.KeyCompare=paramOneKeyCompareStr->Value()-48;

 //KeyName
  v8::Local<v8::Object> paramOneKeyNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeyName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneKeyNameStr(Nan::To<v8::String>(paramOneKeyNameObj).ToLocalChecked());
  strcpy_s(field.KeyName,2561,*paramOneKeyNameStr);

 //KeyValue
  v8::Local<v8::Object> paramOneKeyValueObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeyValue").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneKeyValueStr(Nan::To<v8::String>(paramOneKeyValueObj).ToLocalChecked());
  strcpy_s(field.KeyValue,2561,*paramOneKeyValueStr);

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDateStr(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDateStr);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimeStr(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimeStr);

 //SEAT_NO
  v8::Local<v8::Object> paramOneSEAT_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SEAT_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSEAT_NOStr(Nan::To<v8::String>(paramOneSEAT_NOObj).ToLocalChecked());
  strcpy_s(field.SEAT_NO,321,*paramOneSEAT_NOStr);

 //IPADDR
  v8::Local<v8::Object> paramOneIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPADDRStr(Nan::To<v8::String>(paramOneIPADDRObj).ToLocalChecked());
  strcpy_s(field.IPADDR,641,*paramOneIPADDRStr);

 //Interface
  v8::Local<v8::Object> paramOneInterfaceObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Interface").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInterfaceStr(Nan::To<v8::String>(paramOneInterfaceObj).ToLocalChecked());
  strcpy_s(field.Interface,641,*paramOneInterfaceStr);

 //status
  v8::Local<v8::Object> paramOnestatusObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("status").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnestatusStr(Nan::To<v8::String>(paramOnestatusObj).ToLocalChecked());
  strcpy_s(field.status,641,*paramOnestatusStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetPartyLinkStatusInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetLocalPingResultInfoTopic){
  std::cout<<"ReqQryNetLocalPingResultInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetLocalPingResultInfoField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //SouIPADDR
  v8::Local<v8::Object> paramOneSouIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SouIPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSouIPADDRStr(Nan::To<v8::String>(paramOneSouIPADDRObj).ToLocalChecked());
  strcpy_s(field.SouIPADDR,151,*paramOneSouIPADDRStr);

 //SouNAME
  v8::Local<v8::Object> paramOneSouNAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SouNAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSouNAMEStr(Nan::To<v8::String>(paramOneSouNAMEObj).ToLocalChecked());
  strcpy_s(field.SouNAME,1281,*paramOneSouNAMEStr);

 //TarIPADDR
  v8::Local<v8::Object> paramOneTarIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TarIPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTarIPADDRStr(Nan::To<v8::String>(paramOneTarIPADDRObj).ToLocalChecked());
  strcpy_s(field.TarIPADDR,151,*paramOneTarIPADDRStr);

 //TarNAME
  v8::Local<v8::Object> paramOneTarNAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TarNAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTarNAMEStr(Nan::To<v8::String>(paramOneTarNAMEObj).ToLocalChecked());
  strcpy_s(field.TarNAME,1281,*paramOneTarNAMEStr);

 //PDateSta
  v8::Local<v8::Object> paramOnePDateStaObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PDateSta").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePDateStaStr(Nan::To<v8::String>(paramOnePDateStaObj).ToLocalChecked());
  strcpy_s(field.PDateSta,81,*paramOnePDateStaStr);

 //PTimeSta
  v8::Local<v8::Object> paramOnePTimeStaObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PTimeSta").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePTimeStaStr(Nan::To<v8::String>(paramOnePTimeStaObj).ToLocalChecked());
  strcpy_s(field.PTimeSta,81,*paramOnePTimeStaStr);

 //ConnRate
  v8::Local<v8::Object> paramOneConnRateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ConnRate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneConnRateStr=Nan::To<v8::Integer>( paramOneConnRateObj).ToLocalChecked();
  field.ConnRate=paramOneConnRateStr->Value();

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetLocalPingResultInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetRomotePingResultInfoTopic){
  std::cout<<"ReqQryNetRomotePingResultInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetRomotePingResultInfoField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //SouIPADDR
  v8::Local<v8::Object> paramOneSouIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SouIPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSouIPADDRStr(Nan::To<v8::String>(paramOneSouIPADDRObj).ToLocalChecked());
  strcpy_s(field.SouIPADDR,151,*paramOneSouIPADDRStr);

 //SouNAME
  v8::Local<v8::Object> paramOneSouNAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SouNAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSouNAMEStr(Nan::To<v8::String>(paramOneSouNAMEObj).ToLocalChecked());
  strcpy_s(field.SouNAME,1281,*paramOneSouNAMEStr);

 //TarIPADDR
  v8::Local<v8::Object> paramOneTarIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TarIPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTarIPADDRStr(Nan::To<v8::String>(paramOneTarIPADDRObj).ToLocalChecked());
  strcpy_s(field.TarIPADDR,151,*paramOneTarIPADDRStr);

 //TarNAME
  v8::Local<v8::Object> paramOneTarNAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TarNAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTarNAMEStr(Nan::To<v8::String>(paramOneTarNAMEObj).ToLocalChecked());
  strcpy_s(field.TarNAME,1281,*paramOneTarNAMEStr);

 //PDateSta
  v8::Local<v8::Object> paramOnePDateStaObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PDateSta").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePDateStaStr(Nan::To<v8::String>(paramOnePDateStaObj).ToLocalChecked());
  strcpy_s(field.PDateSta,81,*paramOnePDateStaStr);

 //PTimeSta
  v8::Local<v8::Object> paramOnePTimeStaObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PTimeSta").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePTimeStaStr(Nan::To<v8::String>(paramOnePTimeStaObj).ToLocalChecked());
  strcpy_s(field.PTimeSta,81,*paramOnePTimeStaStr);

 //ConnRate
  v8::Local<v8::Object> paramOneConnRateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ConnRate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneConnRateStr=Nan::To<v8::Integer>( paramOneConnRateObj).ToLocalChecked();
  field.ConnRate=paramOneConnRateStr->Value();

 //TimeDlyMin
  v8::Local<v8::Object> paramOneTimeDlyMinObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TimeDlyMin").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTimeDlyMinStr(Nan::To<v8::String>(paramOneTimeDlyMinObj).ToLocalChecked());
  strcpy_s(field.TimeDlyMin,1281,*paramOneTimeDlyMinStr);

 //TimeDlyMax
  v8::Local<v8::Object> paramOneTimeDlyMaxObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TimeDlyMax").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTimeDlyMaxStr(Nan::To<v8::String>(paramOneTimeDlyMaxObj).ToLocalChecked());
  strcpy_s(field.TimeDlyMax,1281,*paramOneTimeDlyMaxStr);

 //TimeDlyAvg
  v8::Local<v8::Object> paramOneTimeDlyAvgObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TimeDlyAvg").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTimeDlyAvgStr(Nan::To<v8::String>(paramOneTimeDlyAvgObj).ToLocalChecked());
  strcpy_s(field.TimeDlyAvg,1281,*paramOneTimeDlyAvgStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetRomotePingResultInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
NAN_METHOD(FtdcSysUserApi_Wrapper::ReqQryNetNonPartyLinkInfoTopic){
  std::cout<<"ReqQryNetNonPartyLinkInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }
  //convert parameter one
  v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryNetNonPartyLinkInfoField field;

 //OperationType
  v8::Local<v8::Object> paramOneOperationTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationTypeStr=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypeStr->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDStr=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDStr->Value();

 //MEMBER_NO
  v8::Local<v8::Object> paramOneMEMBER_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MEMBER_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMEMBER_NOStr(Nan::To<v8::String>(paramOneMEMBER_NOObj).ToLocalChecked());
  strcpy_s(field.MEMBER_NO,321,*paramOneMEMBER_NOStr);

 //MEMBER_NAME
  v8::Local<v8::Object> paramOneMEMBER_NAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MEMBER_NAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMEMBER_NAMEStr(Nan::To<v8::String>(paramOneMEMBER_NAMEObj).ToLocalChecked());
  strcpy_s(field.MEMBER_NAME,641,*paramOneMEMBER_NAMEStr);

 //REMOTE_ADDR
  v8::Local<v8::Object> paramOneREMOTE_ADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("REMOTE_ADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneREMOTE_ADDRStr(Nan::To<v8::String>(paramOneREMOTE_ADDRObj).ToLocalChecked());
  strcpy_s(field.REMOTE_ADDR,641,*paramOneREMOTE_ADDRStr);

 //LOCAL_ADDR
  v8::Local<v8::Object> paramOneLOCAL_ADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("LOCAL_ADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneLOCAL_ADDRStr(Nan::To<v8::String>(paramOneLOCAL_ADDRObj).ToLocalChecked());
  strcpy_s(field.LOCAL_ADDR,641,*paramOneLOCAL_ADDRStr);

 //ADDRESS
  v8::Local<v8::Object> paramOneADDRESSObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ADDRESS").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneADDRESSStr(Nan::To<v8::String>(paramOneADDRESSObj).ToLocalChecked());
  strcpy_s(field.ADDRESS,2561,*paramOneADDRESSStr);

 //LINE_STATUS
  v8::Local<v8::Object> paramOneLINE_STATUSObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("LINE_STATUS").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneLINE_STATUSStr(Nan::To<v8::String>(paramOneLINE_STATUSObj).ToLocalChecked());
  strcpy_s(field.LINE_STATUS,321,*paramOneLINE_STATUSStr);

 //CONTACT
  v8::Local<v8::Object> paramOneCONTACTObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CONTACT").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCONTACTStr(Nan::To<v8::String>(paramOneCONTACTObj).ToLocalChecked());
  strcpy_s(field.CONTACT,321,*paramOneCONTACTStr);

 //TELEPHONE
  v8::Local<v8::Object> paramOneTELEPHONEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TELEPHONE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTELEPHONEStr(Nan::To<v8::String>(paramOneTELEPHONEObj).ToLocalChecked());
  strcpy_s(field.TELEPHONE,641,*paramOneTELEPHONEStr);

 //MOBILEPHONE
  v8::Local<v8::Object> paramOneMOBILEPHONEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MOBILEPHONE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMOBILEPHONEStr(Nan::To<v8::String>(paramOneMOBILEPHONEObj).ToLocalChecked());
  strcpy_s(field.MOBILEPHONE,641,*paramOneMOBILEPHONEStr);

 //EMAIL
  v8::Local<v8::Object> paramOneEMAILObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EMAIL").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEMAILStr(Nan::To<v8::String>(paramOneEMAILObj).ToLocalChecked());
  strcpy_s(field.EMAIL,641,*paramOneEMAILStr);

 //FAX
  v8::Local<v8::Object> paramOneFAXObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FAX").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFAXStr(Nan::To<v8::String>(paramOneFAXObj).ToLocalChecked());
  strcpy_s(field.FAX,641,*paramOneFAXStr);

 //PROVINCE
  v8::Local<v8::Object> paramOnePROVINCEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PROVINCE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePROVINCEStr(Nan::To<v8::String>(paramOnePROVINCEObj).ToLocalChecked());
  strcpy_s(field.PROVINCE,321,*paramOnePROVINCEStr);

 //DDN_NO
  v8::Local<v8::Object> paramOneDDN_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DDN_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDDN_NOStr(Nan::To<v8::String>(paramOneDDN_NOObj).ToLocalChecked());
  strcpy_s(field.DDN_NO,641,*paramOneDDN_NOStr);

 //IN_MODE
  v8::Local<v8::Object> paramOneIN_MODEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IN_MODE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIN_MODEStr(Nan::To<v8::String>(paramOneIN_MODEObj).ToLocalChecked());
  strcpy_s(field.IN_MODE,641,*paramOneIN_MODEStr);

 //IP_WAN
  v8::Local<v8::Object> paramOneIP_WANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IP_WAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIP_WANStr(Nan::To<v8::String>(paramOneIP_WANObj).ToLocalChecked());
  strcpy_s(field.IP_WAN,641,*paramOneIP_WANStr);

 //IP_LAN
  v8::Local<v8::Object> paramOneIP_LANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IP_LAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIP_LANStr(Nan::To<v8::String>(paramOneIP_LANObj).ToLocalChecked());
  strcpy_s(field.IP_LAN,641,*paramOneIP_LANStr);

 //IPADDR
  v8::Local<v8::Object> paramOneIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPADDRStr(Nan::To<v8::String>(paramOneIPADDRObj).ToLocalChecked());
  strcpy_s(field.IPADDR,641,*paramOneIPADDRStr);

 //Interface
  v8::Local<v8::Object> paramOneInterfaceObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Interface").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInterfaceStr(Nan::To<v8::String>(paramOneInterfaceObj).ToLocalChecked());
  strcpy_s(field.Interface,641,*paramOneInterfaceStr);

 //INTERFACE_DATE
  v8::Local<v8::Object> paramOneINTERFACE_DATEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("INTERFACE_DATE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneINTERFACE_DATEStr(Nan::To<v8::String>(paramOneINTERFACE_DATEObj).ToLocalChecked());
  strcpy_s(field.INTERFACE_DATE,321,*paramOneINTERFACE_DATEStr);

 //SOFTWARE
  v8::Local<v8::Object> paramOneSOFTWAREObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SOFTWARE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSOFTWAREStr(Nan::To<v8::String>(paramOneSOFTWAREObj).ToLocalChecked());
  strcpy_s(field.SOFTWARE,321,*paramOneSOFTWAREStr);

 //FEE_TYPE
  v8::Local<v8::Object> paramOneFEE_TYPEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FEE_TYPE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFEE_TYPEStr(Nan::To<v8::String>(paramOneFEE_TYPEObj).ToLocalChecked());
  strcpy_s(field.FEE_TYPE,321,*paramOneFEE_TYPEStr);

 //SERVICEPROVIDER
  v8::Local<v8::Object> paramOneSERVICEPROVIDERObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SERVICEPROVIDER").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSERVICEPROVIDERStr(Nan::To<v8::String>(paramOneSERVICEPROVIDERObj).ToLocalChecked());
  strcpy_s(field.SERVICEPROVIDER,321,*paramOneSERVICEPROVIDERStr);

 //IF_ZIYING
  v8::Local<v8::Object> paramOneIF_ZIYINGObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IF_ZIYING").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIF_ZIYINGStr(Nan::To<v8::String>(paramOneIF_ZIYINGObj).ToLocalChecked());
  strcpy_s(field.IF_ZIYING,321,*paramOneIF_ZIYINGStr);

 //IF_TUOGUAN
  v8::Local<v8::Object> paramOneIF_TUOGUANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IF_TUOGUAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIF_TUOGUANStr(Nan::To<v8::String>(paramOneIF_TUOGUANObj).ToLocalChecked());
  strcpy_s(field.IF_TUOGUAN,321,*paramOneIF_TUOGUANStr);

 //HASOTHER
  v8::Local<v8::Object> paramOneHASOTHERObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HASOTHER").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHASOTHERStr(Nan::To<v8::String>(paramOneHASOTHERObj).ToLocalChecked());
  strcpy_s(field.HASOTHER,321,*paramOneHASOTHERStr);

 //SEAT_NO
  v8::Local<v8::Object> paramOneSEAT_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SEAT_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSEAT_NOStr(Nan::To<v8::String>(paramOneSEAT_NOObj).ToLocalChecked());
  strcpy_s(field.SEAT_NO,10241,*paramOneSEAT_NOStr);

 //PRO
  v8::Local<v8::Object> paramOnePROObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PRO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePROStr(Nan::To<v8::String>(paramOnePROObj).ToLocalChecked());
  strcpy_s(field.PRO,5121,*paramOnePROStr);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetNonPartyLinkInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
