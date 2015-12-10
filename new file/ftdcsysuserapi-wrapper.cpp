#include <nan.h>
#include "ftdcsysuserapi-wrapper.h"
#include "FtdcSysUserApiStruct.h"
#include "spi-transform.h"
#include "sysuserspi.h"
#include "tool-function.h"
#include "CCrypto.h"

using namespace v8;

extern fstream g_RunningResult_File;

Nan::Persistent<Function> FtdcSysUserApi_Wrapper::constructor;

FtdcSysUserApi_Wrapper::FtdcSysUserApi_Wrapper(const char *pszFlowPath)
{
    _userApi = CShfeFtdcSysUserApi::CreateFtdcSysUserApi(pszFlowPath);
    _spi = new SysUserSpi();
    if (NULL == _spi) {
       OutputCallbackMessage("FtdcSysUserApi_Wrapper::FtdcSysUserApi_Wrapper:: _spi is NULL", g_RunningResult_File);
       return;
    }
}

FtdcSysUserApi_Wrapper::~FtdcSysUserApi_Wrapper() {
    _userApi->Release();
    
    if (NULL != _spi) {
        delete _spi;
        _spi = NULL;
    }
    
    g_RunningResult_File.close();
    
    uv_close((uv_handle_t*) &g_FrontConnected_async, NULL);
    uv_close((uv_handle_t*) &g_FrontDisconnected_async, NULL);
    uv_close((uv_handle_t*) &g_HeartBeatWarning_async, NULL);    
    uv_close((uv_handle_t*) &g_RspQryTopCpuInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnTopCpuInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryTopMemInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnTopMemInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryTopProcessInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnTopProcessInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryFileSystemInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnFileSystemInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetworkInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetworkInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryClientLoginTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryMonitorObjectTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnMonitorObjectTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryObjectRationalTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnObjectRationalTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQrySyslogInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnSyslogInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQrySubscriberTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryOidRelationTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnOidRelationTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryUserInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnUserInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryOnlineUserInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnOnlineUserInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryWarningEventTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnWarningEventTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryCPUUsageTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnCPUUsageTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryMemoryUsageTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnMemoryUsageTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryDiskUsageTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnDiskUsageTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryObjectAttrTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnObjectAttrTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryInvalidateOrderTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnInvalidateOrderTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryOrderStatusTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnOrderStatusTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryBargainOrderTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnBargainOrderTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryInstPropertyTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnInstPropertyTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryMarginRateTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnMarginRateTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryPriceLimitTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnPriceLimitTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryPartPosiLimitTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnPartPosiLimitTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryClientPosiLimitTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnClientPosiLimitTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQrySpecialPosiLimitTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnSpecialPosiLimitTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryTransactionChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnTransactionChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryClientChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnClientChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryPartClientChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnPartClientChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryPosiLimitChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnPosiLimitChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryHedgeDetailChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnHedgeDetailChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryParticipantChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnParticipantChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryMarginRateChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnMarginRateChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryUserIpChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnUserIpChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryClientPosiLimitChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnClientPosiLimitChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQrySpecPosiLimitChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnSpecPosiLimitChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryHistoryObjectAttrTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnHistoryObjectAttrTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryFrontInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnFrontInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQrySysUserLoginTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQrySysUserLogoutTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQrySysUserPasswordUpdateTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQrySysUserRegisterTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQrySysUserDeleteTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryParticipantInitTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnParticipantInitTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryUserInitTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnUserInitTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryClientInitTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnClientInitTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryTradeLogTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnTradeLogTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryTradeUserLoginInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnTradeUserLoginInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryPartTradeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryTradepeakTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnUpdateSysConfigTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnSysUser_async,NULL);
    uv_close((uv_handle_t*) &g_RtnPriceLimitChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryHistoryCpuInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryHistoryMemInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryHistoryNetworkInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryMonitorOnlineUser_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryFrontStat_async,NULL);
    uv_close((uv_handle_t*) &g_RtnSysTimeSyncTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnDataCenterChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryHistoryTradePeakTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnHistoryTradePeakTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQrySyslogEventTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnSyslogEventTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryTradeDayChangeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryWebAppInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnWebAppInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryServletInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnServletInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryFileInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnFileInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQrySessionInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnSessionInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryJDBCInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnJDBCInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryThreadInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnThreadInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryVMInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnVMInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryPropertyInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnPropertyInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryMemPoolInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnMemPoolInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryFileContentInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnFileContentInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryConnectionInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnConnectionInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryConnectorInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnConnectorInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryDBQueryTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnDBQueryTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryGeneralFieldTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnGeneralFieldTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryGetFileTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryWarningQueryTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnWarningQueryTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnHostConfig_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryGeneralOperateTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnGeneralOperateTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetDeviceLinkedTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetDeviceLinkedTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryTradeUserLoginStatTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryTradeFrontOrderRttStatTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnTradeFrontOrderRttStatTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryParticTradeOrderStatesTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnParticTradeOrderStatesTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryRouterInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnRouterInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryDiskIOTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnDiskIOTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryStatInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnStatInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryTradeOrderRttCutLineTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnTradeOrderRttCutLineTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryClientInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnClientInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryEventDescriptionTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnEventDescriptionTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryFrontUniqueIDTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnFrontUniqueIDTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetPartyLinkAddrChangeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetPartyLinkAddrChangeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetDelPartyLinkInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetDelPartyLinkInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryPerformanceTopTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnPerformanceTopTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryInstrumentStatusTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnInstrumentStatusTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryCurrTradingSegmentAttrTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnCurrTradingSegmentAttrTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetAreaTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetAreaTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetSubAreaTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetSubAreaTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetSubAreaIPTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetSubAreaIPTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetDeviceTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetDeviceTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetDeviceDetectTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetBuildingTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetBuildingTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetRoomTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetRoomTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetCabinetsTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetCabinetsTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetOIDTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetOIDTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetTimePolicyTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetTimePolicyTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetGatherTaskTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetGatherTaskTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetDeviceChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetDeviceChgTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetDeviceTypeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetDeviceTypeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetDeviceCategoryTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetDeviceCategoryTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetManufactoryTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetManufactoryTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetCommunityTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetCommunityTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetPortTypeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetPortTypeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetPartAccessSpotTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetPartAccessSpotTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetInterfaceTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetInterfaceTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetGeneralOIDTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetGeneralOIDTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetMonitorTypeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetMonitorTypeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetMonitorAttrScopeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetMonitorAttrScopeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetMonitorAttrTypeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetMonitorAttrTypeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetMonitorObjectAttrTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetMonitorObjectAttrTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetFuncAreaTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetFuncAreaTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetMonitorCommandTypeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetMonitorCommandTypeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetMonitorActionGroupTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetMonitorActionGroupTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetMonitorDeviceGroupTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetMonitorDeviceGroupTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetMonitorTaskInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetMonitorTaskInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetMonitorTaskResultTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetMonitorTaskResultTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetMonitorTaskObjectSetTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetMonitorTaskObjectSetTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetPartyLinkInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetPartyLinkInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetMonitorActionAttrTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetMonitorActionAttrTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetModuleTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetModuleTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetEventExprTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetEventExprTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetEventTypeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetEventTypeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetSubEventTypeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetSubEventTypeTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetEventLevelTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetEventLevelTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetMonitorTaskStatusResultTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetMonitorTaskStatusResultTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetCfgFileTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetCfgFileTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetMonitorDeviceTaskTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetMonitorDeviceTaskTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetMonitorTaskInstAttrsTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetMonitorTaskInstAttrsTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryFileGeneralOperTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnFileGeneralOperTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetBaseLineTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetBaseLineTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetBaseLineTaskTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetBaseLineTaskTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetBaseLineResultTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetBaseLineResultTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetPartyLinkStatusInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetPartyLinkStatusInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetMemberSDHLineInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetMemberSDHLineInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetDDNLinkInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetDDNLinkInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetPseudMemberLinkInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetPseudMemberLinkInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryOuterDeviceInfTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetOuterDeviceInfTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetLocalPingResultInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetLocalPingResultInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetRomotePingResultInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetRomotePingResultInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnMonitorTopProcessInfo_async,NULL);
    uv_close((uv_handle_t*) &g_RspQrySysInternalTopologyTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnSysInternalTopologyTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryMemberLinkCostTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnMemberLinkCostTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetPartylinkMonthlyRentTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetPartylinkMonthlyRentTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RspQryNetNonPartyLinkInfoTopic_async,NULL);
    uv_close((uv_handle_t*) &g_RtnNetNonPartyLinkInfoTopic_async,NULL);
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
        Local<String> fileData= info[0]->IsUndefined() ? Nan::EmptyString()  : info[0]->ToString();
        String::Utf8Value utf8Str(fileData);
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
    Local<String> fileData= info[0]->IsUndefined() ? Nan::EmptyString()  : info[0]->ToString();
    String::Utf8Value utf8Str(fileData);

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
  v8::String::Utf8Value paramOneHostNamefileData(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNamefileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAlivefileData=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAlivefileData->Value();

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
  v8::String::Utf8Value paramOneHostNamefileData(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNamefileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAlivefileData=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAlivefileData->Value();

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
  v8::String::Utf8Value paramOneHostNamefileData(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNamefileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAlivefileData=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAlivefileData->Value();

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
  v8::String::Utf8Value paramOneHostNamefileData(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNamefileData);

 //LANNAME
  v8::Local<v8::Object> paramOneLANNAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("LANNAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneLANNAMEfileData(Nan::To<v8::String>(paramOneLANNAMEObj).ToLocalChecked());
  strcpy_s(field.LANNAME,101,*paramOneLANNAMEfileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAlivefileData=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAlivefileData->Value();

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
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDfileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAlivefileData=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAlivefileData->Value();

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
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDfileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAlivefileData=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAlivefileData->Value();

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
  v8::String::Utf8Value paramOneFileNamefileData(Nan::To<v8::String>(paramOneFileNameObj).ToLocalChecked());
  strcpy_s(field.FileName,641,*paramOneFileNamefileData);

 //subFileName
  v8::Local<v8::Object> paramOnesubFileNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("subFileName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnesubFileNamefileData(Nan::To<v8::String>(paramOnesubFileNameObj).ToLocalChecked());
  strcpy_s(field.subFileName,641,*paramOnesubFileNamefileData);

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
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,5121,*paramOneObjectIDfileData);

 //ObjectNum
  v8::Local<v8::Object> paramOneObjectNumObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectNum").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneObjectNumfileData=Nan::To<v8::Integer>( paramOneObjectNumObj).ToLocalChecked();
  field.ObjectNum=paramOneObjectNumfileData->Value();

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAlivefileData=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAlivefileData->Value();

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDatefileData(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDatefileData);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimefileData(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimefileData);

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
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDfileData);

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
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDfileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDfileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

 //WarningLevel
  v8::Local<v8::Object> paramOneWarningLevelObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("WarningLevel").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneWarningLevelfileData(Nan::To<v8::String>(paramOneWarningLevelObj).ToLocalChecked());
  strcpy_s(field.WarningLevel,101,*paramOneWarningLevelfileData);

 //EventType
  v8::Local<v8::Object> paramOneEventTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEventTypefileData=Nan::To<v8::Integer>( paramOneEventTypeObj).ToLocalChecked();
  field.EventType=paramOneEventTypefileData->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,2561,*paramOneObjectIDfileData);

 //EventName
  v8::Local<v8::Object> paramOneEventNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventNamefileData(Nan::To<v8::String>(paramOneEventNameObj).ToLocalChecked());
  strcpy_s(field.EventName,641,*paramOneEventNamefileData);

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
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDfileData);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypefileData(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,2561,*paramOneAttrTypefileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDfileData);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypefileData(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,2561,*paramOneAttrTypefileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneUserIDfileData(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
  strcpy_s(field.UserID,151,*paramOneUserIDfileData);

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
  v8::String::Utf8Value paramOneUserIDfileData(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
  strcpy_s(field.UserID,151,*paramOneUserIDfileData);

 //OldPassword
  v8::Local<v8::Object> paramOneOldPasswordObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OldPassword").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOldPasswordfileData(Nan::To<v8::String>(paramOneOldPasswordObj).ToLocalChecked());
  strcpy_s(field.OldPassword,401,*paramOneOldPasswordfileData);

 //NewPassword
  v8::Local<v8::Object> paramOneNewPasswordObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("NewPassword").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneNewPasswordfileData(Nan::To<v8::String>(paramOneNewPasswordObj).ToLocalChecked());
  strcpy_s(field.NewPassword,401,*paramOneNewPasswordfileData);

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
  v8::String::Utf8Value paramOneUserIDfileData(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
  strcpy_s(field.UserID,151,*paramOneUserIDfileData);

 //UserName
  v8::Local<v8::Object> paramOneUserNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUserNamefileData(Nan::To<v8::String>(paramOneUserNameObj).ToLocalChecked());
  strcpy_s(field.UserName,151,*paramOneUserNamefileData);

 //UserInfo
  v8::Local<v8::Object> paramOneUserInfoObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserInfo").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUserInfofileData(Nan::To<v8::String>(paramOneUserInfoObj).ToLocalChecked());
  strcpy_s(field.UserInfo,991,*paramOneUserInfofileData);

 //Password
  v8::Local<v8::Object> paramOnePasswordObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Password").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePasswordfileData(Nan::To<v8::String>(paramOnePasswordObj).ToLocalChecked());
  strcpy_s(field.Password,401,*paramOnePasswordfileData);

 //Privilege
  v8::Local<v8::Object> paramOnePrivilegeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Privilege").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOnePrivilegefileData=Nan::To<v8::Integer>( paramOnePrivilegeObj).ToLocalChecked();
  field.Privilege=paramOnePrivilegefileData->Value();

 //EMail
  v8::Local<v8::Object> paramOneEMailObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EMail").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEMailfileData(Nan::To<v8::String>(paramOneEMailObj).ToLocalChecked());
  strcpy_s(field.EMail,501,*paramOneEMailfileData);

 //EMailFlag
  v8::Local<v8::Object> paramOneEMailFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EMailFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEMailFlagfileData=Nan::To<v8::Integer>( paramOneEMailFlagObj).ToLocalChecked();
  field.EMailFlag=paramOneEMailFlagfileData->Value();

 //HomePhone
  v8::Local<v8::Object> paramOneHomePhoneObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HomePhone").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHomePhonefileData(Nan::To<v8::String>(paramOneHomePhoneObj).ToLocalChecked());
  strcpy_s(field.HomePhone,301,*paramOneHomePhonefileData);

 //HomePhoneFlag
  v8::Local<v8::Object> paramOneHomePhoneFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HomePhoneFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneHomePhoneFlagfileData=Nan::To<v8::Integer>( paramOneHomePhoneFlagObj).ToLocalChecked();
  field.HomePhoneFlag=paramOneHomePhoneFlagfileData->Value();

 //MobilePhone
  v8::Local<v8::Object> paramOneMobilePhoneObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MobilePhone").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMobilePhonefileData(Nan::To<v8::String>(paramOneMobilePhoneObj).ToLocalChecked());
  strcpy_s(field.MobilePhone,301,*paramOneMobilePhonefileData);

 //MobilePhoneFlag
  v8::Local<v8::Object> paramOneMobilePhoneFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MobilePhoneFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneMobilePhoneFlagfileData=Nan::To<v8::Integer>( paramOneMobilePhoneFlagObj).ToLocalChecked();
  field.MobilePhoneFlag=paramOneMobilePhoneFlagfileData->Value();

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
  v8::String::Utf8Value paramOneUserIDfileData(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
  strcpy_s(field.UserID,151,*paramOneUserIDfileData);

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
  v8::String::Utf8Value paramOneTradingDayfileData(Nan::To<v8::String>(paramOneTradingDayObj).ToLocalChecked());
  strcpy_s(field.TradingDay,81,*paramOneTradingDayfileData);

 //IPAddress
  v8::Local<v8::Object> paramOneIPAddressObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPAddress").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPAddressfileData(Nan::To<v8::String>(paramOneIPAddressObj).ToLocalChecked());
  strcpy_s(field.IPAddress,151,*paramOneIPAddressfileData);

 //FrontID
  v8::Local<v8::Object> paramOneFrontIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FrontID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFrontIDfileData(Nan::To<v8::String>(paramOneFrontIDObj).ToLocalChecked());
  strcpy_s(field.FrontID,81,*paramOneFrontIDfileData);

 //StartParticipant
  v8::Local<v8::Object> paramOneStartParticipantObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartParticipant").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartParticipantfileData(Nan::To<v8::String>(paramOneStartParticipantObj).ToLocalChecked());
  strcpy_s(field.StartParticipant,101,*paramOneStartParticipantfileData);

 //EndParticipant
  v8::Local<v8::Object> paramOneEndParticipantObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndParticipant").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndParticipantfileData(Nan::To<v8::String>(paramOneEndParticipantObj).ToLocalChecked());
  strcpy_s(field.EndParticipant,101,*paramOneEndParticipantfileData);

 //StartUser
  v8::Local<v8::Object> paramOneStartUserObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartUser").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartUserfileData(Nan::To<v8::String>(paramOneStartUserObj).ToLocalChecked());
  strcpy_s(field.StartUser,151,*paramOneStartUserfileData);

 //EndUser
  v8::Local<v8::Object> paramOneEndUserObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndUser").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndUserfileData(Nan::To<v8::String>(paramOneEndUserObj).ToLocalChecked());
  strcpy_s(field.EndUser,151,*paramOneEndUserfileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

 //StartSessionID
  v8::Local<v8::Object> paramOneStartSessionIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartSessionID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartSessionIDfileData(Nan::To<v8::String>(paramOneStartSessionIDObj).ToLocalChecked());
  strcpy_s(field.StartSessionID,81,*paramOneStartSessionIDfileData);

 //EndSessionID
  v8::Local<v8::Object> paramOneEndSessionIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndSessionID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndSessionIDfileData(Nan::To<v8::String>(paramOneEndSessionIDObj).ToLocalChecked());
  strcpy_s(field.EndSessionID,81,*paramOneEndSessionIDfileData);

 //IPFlag
  v8::Local<v8::Object> paramOneIPFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIPFlagfileData=Nan::To<v8::Integer>( paramOneIPFlagObj).ToLocalChecked();
  field.IPFlag=paramOneIPFlagfileData->Value();

 //PartFlag
  v8::Local<v8::Object> paramOnePartFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PartFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOnePartFlagfileData=Nan::To<v8::Integer>( paramOnePartFlagObj).ToLocalChecked();
  field.PartFlag=paramOnePartFlagfileData->Value();

 //UserIDFlag
  v8::Local<v8::Object> paramOneUserIDFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserIDFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneUserIDFlagfileData=Nan::To<v8::Integer>( paramOneUserIDFlagObj).ToLocalChecked();
  field.UserIDFlag=paramOneUserIDFlagfileData->Value();

 //TimeFlag
  v8::Local<v8::Object> paramOneTimeFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TimeFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTimeFlagfileData=Nan::To<v8::Integer>( paramOneTimeFlagObj).ToLocalChecked();
  field.TimeFlag=paramOneTimeFlagfileData->Value();

 //FrontFlag
  v8::Local<v8::Object> paramOneFrontFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FrontFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneFrontFlagfileData=Nan::To<v8::Integer>( paramOneFrontFlagObj).ToLocalChecked();
  field.FrontFlag=paramOneFrontFlagfileData->Value();

 //SessionFlag
  v8::Local<v8::Object> paramOneSessionFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SessionFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSessionFlagfileData=Nan::To<v8::Integer>( paramOneSessionFlagObj).ToLocalChecked();
  field.SessionFlag=paramOneSessionFlagfileData->Value();

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
  v8::String::Utf8Value paramOneMonDatefileData(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDatefileData);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimefileData(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimefileData);

 //OccurDate
  v8::Local<v8::Object> paramOneOccurDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OccurDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOccurDatefileData(Nan::To<v8::String>(paramOneOccurDateObj).ToLocalChecked());
  strcpy_s(field.OccurDate,81,*paramOneOccurDatefileData);

 //OccurTime
  v8::Local<v8::Object> paramOneOccurTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OccurTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOccurTimefileData(Nan::To<v8::String>(paramOneOccurTimeObj).ToLocalChecked());
  strcpy_s(field.OccurTime,81,*paramOneOccurTimefileData);

 //EvendID
  v8::Local<v8::Object> paramOneEvendIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EvendID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEvendIDfileData=Nan::To<v8::Integer>( paramOneEvendIDObj).ToLocalChecked();
  field.EvendID=paramOneEvendIDfileData->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,2561,*paramOneObjectIDfileData);

 //IPAddress
  v8::Local<v8::Object> paramOneIPAddressObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPAddress").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPAddressfileData(Nan::To<v8::String>(paramOneIPAddressObj).ToLocalChecked());
  strcpy_s(field.IPAddress,151,*paramOneIPAddressfileData);

 //EventName
  v8::Local<v8::Object> paramOneEventNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventNamefileData(Nan::To<v8::String>(paramOneEventNameObj).ToLocalChecked());
  strcpy_s(field.EventName,641,*paramOneEventNamefileData);

 //EventNum
  v8::Local<v8::Object> paramOneEventNumObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventNum").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEventNumfileData=Nan::To<v8::Integer>( paramOneEventNumObj).ToLocalChecked();
  field.EventNum=paramOneEventNumfileData->Value();

 //EventType
  v8::Local<v8::Object> paramOneEventTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEventTypefileData=Nan::To<v8::Integer>( paramOneEventTypeObj).ToLocalChecked();
  field.EventType=paramOneEventTypefileData->Value();

 //EventDes
  v8::Local<v8::Object> paramOneEventDesObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventDes").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventDesfileData(Nan::To<v8::String>(paramOneEventDesObj).ToLocalChecked());
  strcpy_s(field.EventDes,5121,*paramOneEventDesfileData);

 //ProcessFlag
  v8::Local<v8::Object> paramOneProcessFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ProcessFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneProcessFlagfileData(Nan::To<v8::String>(paramOneProcessFlagObj).ToLocalChecked());
  strcpy_s(field.ProcessFlag,11,*paramOneProcessFlagfileData);

 //WarningLevel
  v8::Local<v8::Object> paramOneWarningLevelObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("WarningLevel").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneWarningLevelfileData(Nan::To<v8::String>(paramOneWarningLevelObj).ToLocalChecked());
  strcpy_s(field.WarningLevel,101,*paramOneWarningLevelfileData);

 //ActiveDate
  v8::Local<v8::Object> paramOneActiveDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ActiveDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneActiveDatefileData(Nan::To<v8::String>(paramOneActiveDateObj).ToLocalChecked());
  strcpy_s(field.ActiveDate,81,*paramOneActiveDatefileData);

 //ActiveTime
  v8::Local<v8::Object> paramOneActiveTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ActiveTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneActiveTimefileData(Nan::To<v8::String>(paramOneActiveTimeObj).ToLocalChecked());
  strcpy_s(field.ActiveTime,81,*paramOneActiveTimefileData);

 //EventDealDes
  v8::Local<v8::Object> paramOneEventDealDesObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventDealDes").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventDealDesfileData(Nan::To<v8::String>(paramOneEventDealDesObj).ToLocalChecked());
  strcpy_s(field.EventDealDes,641,*paramOneEventDealDesfileData);

 //FullEventName
  v8::Local<v8::Object> paramOneFullEventNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FullEventName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFullEventNamefileData(Nan::To<v8::String>(paramOneFullEventNameObj).ToLocalChecked());
  strcpy_s(field.FullEventName,2561,*paramOneFullEventNamefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

 //TradepeakFlag
  v8::Local<v8::Object> paramOneTradepeakFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TradepeakFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTradepeakFlagfileData=Nan::To<v8::Integer>( paramOneTradepeakFlagObj).ToLocalChecked();
  field.TradepeakFlag=paramOneTradepeakFlagfileData->Value()-48;

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneHostNamefileData(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNamefileData);

 //CPU
  v8::Local<v8::Object> paramOneCPUObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CPU").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCPUfileData(Nan::To<v8::String>(paramOneCPUObj).ToLocalChecked());
  strcpy_s(field.CPU,51,*paramOneCPUfileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAlivefileData=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAlivefileData->Value();

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
  v8::String::Utf8Value paramOneHostNamefileData(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNamefileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAlivefileData=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAlivefileData->Value();

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
  v8::String::Utf8Value paramOneHostNamefileData(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNamefileData);

 //LANNAME
  v8::Local<v8::Object> paramOneLANNAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("LANNAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneLANNAMEfileData(Nan::To<v8::String>(paramOneLANNAMEObj).ToLocalChecked());
  strcpy_s(field.LANNAME,101,*paramOneLANNAMEfileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAlivefileData=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAlivefileData->Value();

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

 //EventType
  v8::Local<v8::Object> paramOneEventTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEventTypefileData=Nan::To<v8::Integer>( paramOneEventTypeObj).ToLocalChecked();
  field.EventType=paramOneEventTypefileData->Value();

 //WarningLevel
  v8::Local<v8::Object> paramOneWarningLevelObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("WarningLevel").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneWarningLevelfileData(Nan::To<v8::String>(paramOneWarningLevelObj).ToLocalChecked());
  strcpy_s(field.WarningLevel,101,*paramOneWarningLevelfileData);

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,2561,*paramOneObjectIDfileData);

 //EventName
  v8::Local<v8::Object> paramOneEventNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventNamefileData(Nan::To<v8::String>(paramOneEventNameObj).ToLocalChecked());
  strcpy_s(field.EventName,641,*paramOneEventNamefileData);

 //IPAddress
  v8::Local<v8::Object> paramOneIPAddressObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPAddress").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPAddressfileData(Nan::To<v8::String>(paramOneIPAddressObj).ToLocalChecked());
  strcpy_s(field.IPAddress,151,*paramOneIPAddressfileData);

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
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,2561,*paramOneObjectIDfileData);

 //EventName
  v8::Local<v8::Object> paramOneEventNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventNamefileData(Nan::To<v8::String>(paramOneEventNameObj).ToLocalChecked());
  strcpy_s(field.EventName,641,*paramOneEventNamefileData);

 //WarningLevel
  v8::Local<v8::Object> paramOneWarningLevelObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("WarningLevel").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneWarningLevelfileData(Nan::To<v8::String>(paramOneWarningLevelObj).ToLocalChecked());
  strcpy_s(field.WarningLevel,101,*paramOneWarningLevelfileData);

 //filter
  v8::Local<v8::Object> paramOnefilterObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("filter").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnefilterfileData(Nan::To<v8::String>(paramOnefilterObj).ToLocalChecked());
  strcpy_s(field.filter,5121,*paramOnefilterfileData);

 //antifilter
  v8::Local<v8::Object> paramOneantifilterObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("antifilter").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneantifilterfileData(Nan::To<v8::String>(paramOneantifilterObj).ToLocalChecked());
  strcpy_s(field.antifilter,5121,*paramOneantifilterfileData);

 //ObjectNum
  v8::Local<v8::Object> paramOneObjectNumObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectNum").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneObjectNumfileData=Nan::To<v8::Integer>( paramOneObjectNumObj).ToLocalChecked();
  field.ObjectNum=paramOneObjectNumfileData->Value();

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAlivefileData=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAlivefileData->Value();

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDatefileData(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDatefileData);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimefileData(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimefileData);

 //ProcessFlag
  v8::Local<v8::Object> paramOneProcessFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ProcessFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneProcessFlagfileData(Nan::To<v8::String>(paramOneProcessFlagObj).ToLocalChecked());
  strcpy_s(field.ProcessFlag,11,*paramOneProcessFlagfileData);

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
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDfileData);

 //SubObjectID
  v8::Local<v8::Object> paramOneSubObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SubObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSubObjectIDfileData(Nan::To<v8::String>(paramOneSubObjectIDObj).ToLocalChecked());
  strcpy_s(field.SubObjectID,641,*paramOneSubObjectIDfileData);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypefileData(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,2561,*paramOneAttrTypefileData);

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
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDfileData);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypefileData(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,641,*paramOneAttrTypefileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::String::Utf8Value paramOneFileNamefileData(Nan::To<v8::String>(paramOneFileNameObj).ToLocalChecked());
  strcpy_s(field.FileName,2561,*paramOneFileNamefileData);

 //Version
  v8::Local<v8::Object> paramOneVersionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Version").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneVersionfileData(Nan::To<v8::String>(paramOneVersionObj).ToLocalChecked());
  strcpy_s(field.Version,161,*paramOneVersionfileData);

 //Offset
  v8::Local<v8::Object> paramOneOffsetObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Offset").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOffsetfileData=Nan::To<v8::Integer>( paramOneOffsetObj).ToLocalChecked();
  field.Offset=paramOneOffsetfileData->Value();

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
  v8::String::Utf8Value paramOneMonDatefileData(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDatefileData);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimefileData(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimefileData);

 //OccurDate
  v8::Local<v8::Object> paramOneOccurDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OccurDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOccurDatefileData(Nan::To<v8::String>(paramOneOccurDateObj).ToLocalChecked());
  strcpy_s(field.OccurDate,81,*paramOneOccurDatefileData);

 //OccurTime
  v8::Local<v8::Object> paramOneOccurTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OccurTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOccurTimefileData(Nan::To<v8::String>(paramOneOccurTimeObj).ToLocalChecked());
  strcpy_s(field.OccurTime,81,*paramOneOccurTimefileData);

 //EvendID
  v8::Local<v8::Object> paramOneEvendIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EvendID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEvendIDfileData=Nan::To<v8::Integer>( paramOneEvendIDObj).ToLocalChecked();
  field.EvendID=paramOneEvendIDfileData->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,2561,*paramOneObjectIDfileData);

 //IPAddress
  v8::Local<v8::Object> paramOneIPAddressObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPAddress").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPAddressfileData(Nan::To<v8::String>(paramOneIPAddressObj).ToLocalChecked());
  strcpy_s(field.IPAddress,151,*paramOneIPAddressfileData);

 //EventName
  v8::Local<v8::Object> paramOneEventNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventNamefileData(Nan::To<v8::String>(paramOneEventNameObj).ToLocalChecked());
  strcpy_s(field.EventName,641,*paramOneEventNamefileData);

 //EventNum
  v8::Local<v8::Object> paramOneEventNumObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventNum").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEventNumfileData=Nan::To<v8::Integer>( paramOneEventNumObj).ToLocalChecked();
  field.EventNum=paramOneEventNumfileData->Value();

 //EventType
  v8::Local<v8::Object> paramOneEventTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEventTypefileData=Nan::To<v8::Integer>( paramOneEventTypeObj).ToLocalChecked();
  field.EventType=paramOneEventTypefileData->Value();

 //EventDes
  v8::Local<v8::Object> paramOneEventDesObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventDes").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventDesfileData(Nan::To<v8::String>(paramOneEventDesObj).ToLocalChecked());
  strcpy_s(field.EventDes,5121,*paramOneEventDesfileData);

 //ProcessFlag
  v8::Local<v8::Object> paramOneProcessFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ProcessFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneProcessFlagfileData(Nan::To<v8::String>(paramOneProcessFlagObj).ToLocalChecked());
  strcpy_s(field.ProcessFlag,11,*paramOneProcessFlagfileData);

 //WarningLevel
  v8::Local<v8::Object> paramOneWarningLevelObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("WarningLevel").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneWarningLevelfileData(Nan::To<v8::String>(paramOneWarningLevelObj).ToLocalChecked());
  strcpy_s(field.WarningLevel,101,*paramOneWarningLevelfileData);

 //EventDealDes
  v8::Local<v8::Object> paramOneEventDealDesObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventDealDes").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventDealDesfileData(Nan::To<v8::String>(paramOneEventDealDesObj).ToLocalChecked());
  strcpy_s(field.EventDealDes,641,*paramOneEventDealDesfileData);

 //FullEventName
  v8::Local<v8::Object> paramOneFullEventNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FullEventName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFullEventNamefileData(Nan::To<v8::String>(paramOneFullEventNameObj).ToLocalChecked());
  strcpy_s(field.FullEventName,2561,*paramOneFullEventNamefileData);

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
  v8::Local<v8::Integer> paramOneEvendIDfileData=Nan::To<v8::Integer>( paramOneEvendIDObj).ToLocalChecked();
  field.EvendID=paramOneEvendIDfileData->Value();

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
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDfileData);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypefileData(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,2561,*paramOneAttrTypefileData);

 //BeginDate
  v8::Local<v8::Object> paramOneBeginDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("BeginDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneBeginDatefileData(Nan::To<v8::String>(paramOneBeginDateObj).ToLocalChecked());
  strcpy_s(field.BeginDate,81,*paramOneBeginDatefileData);

 //BeginTime
  v8::Local<v8::Object> paramOneBeginTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("BeginTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneBeginTimefileData(Nan::To<v8::String>(paramOneBeginTimeObj).ToLocalChecked());
  strcpy_s(field.BeginTime,81,*paramOneBeginTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

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
  v8::Local<v8::Integer> paramOneGeneralOperateTypefileData=Nan::To<v8::Integer>( paramOneGeneralOperateTypeObj).ToLocalChecked();
  field.GeneralOperateType=paramOneGeneralOperateTypefileData->Value()-48;

 //GeneralOperateTable
  v8::Local<v8::Object> paramOneGeneralOperateTableObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("GeneralOperateTable").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneGeneralOperateTablefileData(Nan::To<v8::String>(paramOneGeneralOperateTableObj).ToLocalChecked());
  strcpy_s(field.GeneralOperateTable,1281,*paramOneGeneralOperateTablefileData);

 //GeneralOperateOption
  v8::Local<v8::Object> paramOneGeneralOperateOptionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("GeneralOperateOption").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneGeneralOperateOptionfileData(Nan::To<v8::String>(paramOneGeneralOperateOptionObj).ToLocalChecked());
  strcpy_s(field.GeneralOperateOption,8001,*paramOneGeneralOperateOptionfileData);

 //GeneralOperateSet
  v8::Local<v8::Object> paramOneGeneralOperateSetObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("GeneralOperateSet").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneGeneralOperateSetfileData(Nan::To<v8::String>(paramOneGeneralOperateSetObj).ToLocalChecked());
  strcpy_s(field.GeneralOperateSet,30001,*paramOneGeneralOperateSetfileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //SysNetSubAreaID
  v8::Local<v8::Object> paramOneSysNetSubAreaIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetSubAreaID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetSubAreaIDfileData=Nan::To<v8::Integer>( paramOneSysNetSubAreaIDObj).ToLocalChecked();
  field.SysNetSubAreaID=paramOneSysNetSubAreaIDfileData->Value();

 //FuctionArea
  v8::Local<v8::Object> paramOneFuctionAreaObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FuctionArea").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFuctionAreafileData(Nan::To<v8::String>(paramOneFuctionAreaObj).ToLocalChecked());
  strcpy_s(field.FuctionArea,641,*paramOneFuctionAreafileData);

 //IPDECODE
  v8::Local<v8::Object> paramOneIPDECODEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPDECODE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIPDECODEfileData=Nan::To<v8::Integer>( paramOneIPDECODEObj).ToLocalChecked();
  field.IPDECODE=paramOneIPDECODEfileData->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDfileData);

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
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDfileData);

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
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,641,*paramOneObjectIDfileData);

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDatefileData(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDatefileData);

 //MonStartTime
  v8::Local<v8::Object> paramOneMonStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonStartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonStartTimefileData(Nan::To<v8::String>(paramOneMonStartTimeObj).ToLocalChecked());
  strcpy_s(field.MonStartTime,81,*paramOneMonStartTimefileData);

 //MonEndTime
  v8::Local<v8::Object> paramOneMonEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonEndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonEndTimefileData(Nan::To<v8::String>(paramOneMonEndTimeObj).ToLocalChecked());
  strcpy_s(field.MonEndTime,81,*paramOneMonEndTimefileData);

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
  v8::String::Utf8Value paramOneParticipantIDfileData(Nan::To<v8::String>(paramOneParticipantIDObj).ToLocalChecked());
  strcpy_s(field.ParticipantID,101,*paramOneParticipantIDfileData);

 //UserID
  v8::Local<v8::Object> paramOneUserIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUserIDfileData(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
  strcpy_s(field.UserID,151,*paramOneUserIDfileData);

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDatefileData(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDatefileData);

 //MonStartTime
  v8::Local<v8::Object> paramOneMonStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonStartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonStartTimefileData(Nan::To<v8::String>(paramOneMonStartTimeObj).ToLocalChecked());
  strcpy_s(field.MonStartTime,81,*paramOneMonStartTimefileData);

 //MonEndTime
  v8::Local<v8::Object> paramOneMonEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonEndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonEndTimefileData(Nan::To<v8::String>(paramOneMonEndTimeObj).ToLocalChecked());
  strcpy_s(field.MonEndTime,81,*paramOneMonEndTimefileData);

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
  v8::String::Utf8Value paramOneHostNamefileData(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNamefileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAlivefileData=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAlivefileData->Value();

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
  v8::String::Utf8Value paramOneHostNamefileData(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNamefileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAlivefileData=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAlivefileData->Value();

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
  v8::String::Utf8Value paramOneHostNamefileData(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strcpy_s(field.HostName,641,*paramOneHostNamefileData);

 //StartDate
  v8::Local<v8::Object> paramOneStartDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strcpy_s(field.StartDate,81,*paramOneStartDatefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //EndDate
  v8::Local<v8::Object> paramOneEndDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strcpy_s(field.EndDate,81,*paramOneEndDatefileData);

 //EndTime
  v8::Local<v8::Object> paramOneEndTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strcpy_s(field.EndTime,81,*paramOneEndTimefileData);

 //KeepAlive
  v8::Local<v8::Object> paramOneKeepAliveObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAlivefileData=Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive=paramOneKeepAlivefileData->Value();

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
  v8::String::Utf8Value paramOneMonDatefileData(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDatefileData);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimefileData(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimefileData);

 //UserName
  v8::Local<v8::Object> paramOneUserNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUserNamefileData(Nan::To<v8::String>(paramOneUserNameObj).ToLocalChecked());
  strcpy_s(field.UserName,641,*paramOneUserNamefileData);

 //OrderRttCutLine
  v8::Local<v8::Object> paramOneOrderRttCutLineObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OrderRttCutLine").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOrderRttCutLinefileData(Nan::To<v8::String>(paramOneOrderRttCutLineObj).ToLocalChecked());
  strcpy_s(field.OrderRttCutLine,1281,*paramOneOrderRttCutLinefileData);

 //OrderRttWidth
  v8::Local<v8::Object> paramOneOrderRttWidthObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OrderRttWidth").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOrderRttWidthfileData=Nan::To<v8::Integer>( paramOneOrderRttWidthObj).ToLocalChecked();
  field.OrderRttWidth=paramOneOrderRttWidthfileData->Value();

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
  v8::String::Utf8Value paramOneClientIDfileData(Nan::To<v8::String>(paramOneClientIDObj).ToLocalChecked());
  strcpy_s(field.ClientID,101,*paramOneClientIDfileData);

 //ClientName
  v8::Local<v8::Object> paramOneClientNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ClientName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneClientNamefileData(Nan::To<v8::String>(paramOneClientNameObj).ToLocalChecked());
  strcpy_s(field.ClientName,801,*paramOneClientNamefileData);

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
  v8::String::Utf8Value paramOneEventDesIDfileData(Nan::To<v8::String>(paramOneEventDesIDObj).ToLocalChecked());
  strcpy_s(field.EventDesID,121,*paramOneEventDesIDfileData);

 //UserName
  v8::Local<v8::Object> paramOneUserNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUserNamefileData(Nan::To<v8::String>(paramOneUserNameObj).ToLocalChecked());
  strcpy_s(field.UserName,641,*paramOneUserNamefileData);

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDatefileData(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDatefileData);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimefileData(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimefileData);

 //EventDes
  v8::Local<v8::Object> paramOneEventDesObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventDes").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventDesfileData(Nan::To<v8::String>(paramOneEventDesObj).ToLocalChecked());
  strcpy_s(field.EventDes,4001,*paramOneEventDesfileData);

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
  v8::Local<v8::Integer> paramOneFrontIDfileData=Nan::To<v8::Integer>( paramOneFrontIDObj).ToLocalChecked();
  field.FrontID=paramOneFrontIDfileData->Value();

 //FrontName
  v8::Local<v8::Object> paramOneFrontNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FrontName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFrontNamefileData(Nan::To<v8::String>(paramOneFrontNameObj).ToLocalChecked());
  strcpy_s(field.FrontName,501,*paramOneFrontNamefileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //RelationID
  v8::Local<v8::Object> paramOneRelationIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("RelationID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneRelationIDfileData=Nan::To<v8::Integer>( paramOneRelationIDObj).ToLocalChecked();
  field.RelationID=paramOneRelationIDfileData->Value();

 //OLDADDRESS
  v8::Local<v8::Object> paramOneOLDADDRESSObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OLDADDRESS").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOLDADDRESSfileData(Nan::To<v8::String>(paramOneOLDADDRESSObj).ToLocalChecked());
  strcpy_s(field.OLDADDRESS,2561,*paramOneOLDADDRESSfileData);

 //NEWADDRESS
  v8::Local<v8::Object> paramOneNEWADDRESSObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("NEWADDRESS").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneNEWADDRESSfileData(Nan::To<v8::String>(paramOneNEWADDRESSObj).ToLocalChecked());
  strcpy_s(field.NEWADDRESS,2561,*paramOneNEWADDRESSfileData);

 //OPERATOR
  v8::Local<v8::Object> paramOneOPERATORObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OPERATOR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOPERATORfileData(Nan::To<v8::String>(paramOneOPERATORObj).ToLocalChecked());
  strcpy_s(field.OPERATOR,321,*paramOneOPERATORfileData);

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDatefileData(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDatefileData);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimefileData(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimefileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //MEMBER_NO
  v8::Local<v8::Object> paramOneMEMBER_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MEMBER_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMEMBER_NOfileData(Nan::To<v8::String>(paramOneMEMBER_NOObj).ToLocalChecked());
  strcpy_s(field.MEMBER_NO,321,*paramOneMEMBER_NOfileData);

 //MEMBER_NAME
  v8::Local<v8::Object> paramOneMEMBER_NAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MEMBER_NAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMEMBER_NAMEfileData(Nan::To<v8::String>(paramOneMEMBER_NAMEObj).ToLocalChecked());
  strcpy_s(field.MEMBER_NAME,641,*paramOneMEMBER_NAMEfileData);

 //REMOTE_ADDR
  v8::Local<v8::Object> paramOneREMOTE_ADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("REMOTE_ADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneREMOTE_ADDRfileData(Nan::To<v8::String>(paramOneREMOTE_ADDRObj).ToLocalChecked());
  strcpy_s(field.REMOTE_ADDR,641,*paramOneREMOTE_ADDRfileData);

 //LOCAL_ADDR
  v8::Local<v8::Object> paramOneLOCAL_ADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("LOCAL_ADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneLOCAL_ADDRfileData(Nan::To<v8::String>(paramOneLOCAL_ADDRObj).ToLocalChecked());
  strcpy_s(field.LOCAL_ADDR,641,*paramOneLOCAL_ADDRfileData);

 //ADDRESS
  v8::Local<v8::Object> paramOneADDRESSObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ADDRESS").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneADDRESSfileData(Nan::To<v8::String>(paramOneADDRESSObj).ToLocalChecked());
  strcpy_s(field.ADDRESS,2561,*paramOneADDRESSfileData);

 //LINE_STATUS
  v8::Local<v8::Object> paramOneLINE_STATUSObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("LINE_STATUS").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneLINE_STATUSfileData(Nan::To<v8::String>(paramOneLINE_STATUSObj).ToLocalChecked());
  strcpy_s(field.LINE_STATUS,321,*paramOneLINE_STATUSfileData);

 //CONTACT
  v8::Local<v8::Object> paramOneCONTACTObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CONTACT").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCONTACTfileData(Nan::To<v8::String>(paramOneCONTACTObj).ToLocalChecked());
  strcpy_s(field.CONTACT,321,*paramOneCONTACTfileData);

 //TELEPHONE
  v8::Local<v8::Object> paramOneTELEPHONEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TELEPHONE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTELEPHONEfileData(Nan::To<v8::String>(paramOneTELEPHONEObj).ToLocalChecked());
  strcpy_s(field.TELEPHONE,641,*paramOneTELEPHONEfileData);

 //MOBILEPHONE
  v8::Local<v8::Object> paramOneMOBILEPHONEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MOBILEPHONE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMOBILEPHONEfileData(Nan::To<v8::String>(paramOneMOBILEPHONEObj).ToLocalChecked());
  strcpy_s(field.MOBILEPHONE,641,*paramOneMOBILEPHONEfileData);

 //EMAIL
  v8::Local<v8::Object> paramOneEMAILObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EMAIL").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEMAILfileData(Nan::To<v8::String>(paramOneEMAILObj).ToLocalChecked());
  strcpy_s(field.EMAIL,641,*paramOneEMAILfileData);

 //FAX
  v8::Local<v8::Object> paramOneFAXObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FAX").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFAXfileData(Nan::To<v8::String>(paramOneFAXObj).ToLocalChecked());
  strcpy_s(field.FAX,641,*paramOneFAXfileData);

 //PROVINCE
  v8::Local<v8::Object> paramOnePROVINCEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PROVINCE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePROVINCEfileData(Nan::To<v8::String>(paramOnePROVINCEObj).ToLocalChecked());
  strcpy_s(field.PROVINCE,321,*paramOnePROVINCEfileData);

 //DDN_NO
  v8::Local<v8::Object> paramOneDDN_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DDN_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDDN_NOfileData(Nan::To<v8::String>(paramOneDDN_NOObj).ToLocalChecked());
  strcpy_s(field.DDN_NO,641,*paramOneDDN_NOfileData);

 //IN_MODE
  v8::Local<v8::Object> paramOneIN_MODEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IN_MODE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIN_MODEfileData(Nan::To<v8::String>(paramOneIN_MODEObj).ToLocalChecked());
  strcpy_s(field.IN_MODE,641,*paramOneIN_MODEfileData);

 //IP_WAN
  v8::Local<v8::Object> paramOneIP_WANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IP_WAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIP_WANfileData(Nan::To<v8::String>(paramOneIP_WANObj).ToLocalChecked());
  strcpy_s(field.IP_WAN,641,*paramOneIP_WANfileData);

 //IP_LAN
  v8::Local<v8::Object> paramOneIP_LANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IP_LAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIP_LANfileData(Nan::To<v8::String>(paramOneIP_LANObj).ToLocalChecked());
  strcpy_s(field.IP_LAN,641,*paramOneIP_LANfileData);

 //IPADDR
  v8::Local<v8::Object> paramOneIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPADDRfileData(Nan::To<v8::String>(paramOneIPADDRObj).ToLocalChecked());
  strcpy_s(field.IPADDR,641,*paramOneIPADDRfileData);

 //Interface
  v8::Local<v8::Object> paramOneInterfaceObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Interface").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInterfacefileData(Nan::To<v8::String>(paramOneInterfaceObj).ToLocalChecked());
  strcpy_s(field.Interface,641,*paramOneInterfacefileData);

 //INTERFACE_DATE
  v8::Local<v8::Object> paramOneINTERFACE_DATEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("INTERFACE_DATE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneINTERFACE_DATEfileData(Nan::To<v8::String>(paramOneINTERFACE_DATEObj).ToLocalChecked());
  strcpy_s(field.INTERFACE_DATE,321,*paramOneINTERFACE_DATEfileData);

 //SOFTWARE
  v8::Local<v8::Object> paramOneSOFTWAREObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SOFTWARE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSOFTWAREfileData(Nan::To<v8::String>(paramOneSOFTWAREObj).ToLocalChecked());
  strcpy_s(field.SOFTWARE,321,*paramOneSOFTWAREfileData);

 //FEE_TYPE
  v8::Local<v8::Object> paramOneFEE_TYPEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FEE_TYPE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFEE_TYPEfileData(Nan::To<v8::String>(paramOneFEE_TYPEObj).ToLocalChecked());
  strcpy_s(field.FEE_TYPE,321,*paramOneFEE_TYPEfileData);

 //SERVICEPROVIDER
  v8::Local<v8::Object> paramOneSERVICEPROVIDERObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SERVICEPROVIDER").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSERVICEPROVIDERfileData(Nan::To<v8::String>(paramOneSERVICEPROVIDERObj).ToLocalChecked());
  strcpy_s(field.SERVICEPROVIDER,321,*paramOneSERVICEPROVIDERfileData);

 //IF_ZIYING
  v8::Local<v8::Object> paramOneIF_ZIYINGObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IF_ZIYING").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIF_ZIYINGfileData(Nan::To<v8::String>(paramOneIF_ZIYINGObj).ToLocalChecked());
  strcpy_s(field.IF_ZIYING,321,*paramOneIF_ZIYINGfileData);

 //IF_TUOGUAN
  v8::Local<v8::Object> paramOneIF_TUOGUANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IF_TUOGUAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIF_TUOGUANfileData(Nan::To<v8::String>(paramOneIF_TUOGUANObj).ToLocalChecked());
  strcpy_s(field.IF_TUOGUAN,321,*paramOneIF_TUOGUANfileData);

 //HASOTHER
  v8::Local<v8::Object> paramOneHASOTHERObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HASOTHER").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHASOTHERfileData(Nan::To<v8::String>(paramOneHASOTHERObj).ToLocalChecked());
  strcpy_s(field.HASOTHER,321,*paramOneHASOTHERfileData);

 //SEAT_NO
  v8::Local<v8::Object> paramOneSEAT_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SEAT_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSEAT_NOfileData(Nan::To<v8::String>(paramOneSEAT_NOObj).ToLocalChecked());
  strcpy_s(field.SEAT_NO,10241,*paramOneSEAT_NOfileData);

 //PRO
  v8::Local<v8::Object> paramOnePROObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PRO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePROfileData(Nan::To<v8::String>(paramOnePROObj).ToLocalChecked());
  strcpy_s(field.PRO,5121,*paramOnePROfileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypefileData(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,641,*paramOneAttrTypefileData);

 //NetArea
  v8::Local<v8::Object> paramOneNetAreaObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("NetArea").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneNetAreafileData=Nan::To<v8::Integer>( paramOneNetAreaObj).ToLocalChecked();
  field.NetArea=paramOneNetAreafileData->Value();

 //NetSubArea
  v8::Local<v8::Object> paramOneNetSubAreaObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("NetSubArea").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneNetSubAreafileData(Nan::To<v8::String>(paramOneNetSubAreaObj).ToLocalChecked());
  strcpy_s(field.NetSubArea,641,*paramOneNetSubAreafileData);

 //KeyWord
  v8::Local<v8::Object> paramOneKeyWordObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeyWord").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneKeyWordfileData(Nan::To<v8::String>(paramOneKeyWordObj).ToLocalChecked());
  strcpy_s(field.KeyWord,1001,*paramOneKeyWordfileData);

 //SortValue
  v8::Local<v8::Object> paramOneSortValueObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SortValue").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSortValuefileData=Nan::To<v8::Integer>( paramOneSortValueObj).ToLocalChecked();
  field.SortValue=paramOneSortValuefileData->Value();

 //SortType
  v8::Local<v8::Object> paramOneSortTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SortType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSortTypefileData=Nan::To<v8::Integer>( paramOneSortTypeObj).ToLocalChecked();
  field.SortType=paramOneSortTypefileData->Value();

 //DuringTimeType
  v8::Local<v8::Object> paramOneDuringTimeTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DuringTimeType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDuringTimeTypefileData=Nan::To<v8::Integer>( paramOneDuringTimeTypeObj).ToLocalChecked();
  field.DuringTimeType=paramOneDuringTimeTypefileData->Value();

 //DuringTimeValue
  v8::Local<v8::Object> paramOneDuringTimeValueObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DuringTimeValue").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDuringTimeValuefileData=Nan::To<v8::Integer>( paramOneDuringTimeValueObj).ToLocalChecked();
  field.DuringTimeValue=paramOneDuringTimeValuefileData->Value();

 //TopN
  v8::Local<v8::Object> paramOneTopNObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TopN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTopNfileData=Nan::To<v8::Integer>( paramOneTopNObj).ToLocalChecked();
  field.TopN=paramOneTopNfileData->Value();

 //TopResult
  v8::Local<v8::Object> paramOneTopResultObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TopResult").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTopResultfileData(Nan::To<v8::String>(paramOneTopResultObj).ToLocalChecked());
  strcpy_s(field.TopResult,2561,*paramOneTopResultfileData);

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
  v8::String::Utf8Value paramOneSettlementGroupIDfileData(Nan::To<v8::String>(paramOneSettlementGroupIDObj).ToLocalChecked());
  strcpy_s(field.SettlementGroupID,81,*paramOneSettlementGroupIDfileData);

 //InstrumentID
  v8::Local<v8::Object> paramOneInstrumentIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("InstrumentID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInstrumentIDfileData(Nan::To<v8::String>(paramOneInstrumentIDObj).ToLocalChecked());
  strcpy_s(field.InstrumentID,301,*paramOneInstrumentIDfileData);

 //InstrumentStatus
  v8::Local<v8::Object> paramOneInstrumentStatusObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("InstrumentStatus").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneInstrumentStatusfileData=Nan::To<v8::Integer>( paramOneInstrumentStatusObj).ToLocalChecked();
  field.InstrumentStatus=paramOneInstrumentStatusfileData->Value()-48;

 //TradingSegmentSN
  v8::Local<v8::Object> paramOneTradingSegmentSNObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TradingSegmentSN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTradingSegmentSNfileData=Nan::To<v8::Integer>( paramOneTradingSegmentSNObj).ToLocalChecked();
  field.TradingSegmentSN=paramOneTradingSegmentSNfileData->Value();

 //EnterTime
  v8::Local<v8::Object> paramOneEnterTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EnterTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEnterTimefileData(Nan::To<v8::String>(paramOneEnterTimeObj).ToLocalChecked());
  strcpy_s(field.EnterTime,81,*paramOneEnterTimefileData);

 //EnterReason
  v8::Local<v8::Object> paramOneEnterReasonObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EnterReason").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEnterReasonfileData=Nan::To<v8::Integer>( paramOneEnterReasonObj).ToLocalChecked();
  field.EnterReason=paramOneEnterReasonfileData->Value()-48;

 //EnterDate
  v8::Local<v8::Object> paramOneEnterDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EnterDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEnterDatefileData(Nan::To<v8::String>(paramOneEnterDateObj).ToLocalChecked());
  strcpy_s(field.EnterDate,81,*paramOneEnterDatefileData);

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
  v8::String::Utf8Value paramOneSettlementGroupIDfileData(Nan::To<v8::String>(paramOneSettlementGroupIDObj).ToLocalChecked());
  strcpy_s(field.SettlementGroupID,81,*paramOneSettlementGroupIDfileData);

 //TradingSegmentSN
  v8::Local<v8::Object> paramOneTradingSegmentSNObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TradingSegmentSN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTradingSegmentSNfileData=Nan::To<v8::Integer>( paramOneTradingSegmentSNObj).ToLocalChecked();
  field.TradingSegmentSN=paramOneTradingSegmentSNfileData->Value();

 //TradingSegmentName
  v8::Local<v8::Object> paramOneTradingSegmentNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TradingSegmentName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTradingSegmentNamefileData(Nan::To<v8::String>(paramOneTradingSegmentNameObj).ToLocalChecked());
  strcpy_s(field.TradingSegmentName,201,*paramOneTradingSegmentNamefileData);

 //StartTime
  v8::Local<v8::Object> paramOneStartTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strcpy_s(field.StartTime,81,*paramOneStartTimefileData);

 //InstrumentStatus
  v8::Local<v8::Object> paramOneInstrumentStatusObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("InstrumentStatus").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneInstrumentStatusfileData=Nan::To<v8::Integer>( paramOneInstrumentStatusObj).ToLocalChecked();
  field.InstrumentStatus=paramOneInstrumentStatusfileData->Value()-48;

 //InstrumentID
  v8::Local<v8::Object> paramOneInstrumentIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("InstrumentID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInstrumentIDfileData(Nan::To<v8::String>(paramOneInstrumentIDObj).ToLocalChecked());
  strcpy_s(field.InstrumentID,301,*paramOneInstrumentIDfileData);

 //AdvanceDays
  v8::Local<v8::Object> paramOneAdvanceDaysObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AdvanceDays").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneAdvanceDaysfileData=Nan::To<v8::Integer>( paramOneAdvanceDaysObj).ToLocalChecked();
  field.AdvanceDays=paramOneAdvanceDaysfileData->Value();

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
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDfileData);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypefileData(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,2561,*paramOneAttrTypefileData);

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
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

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
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //SysNetAreaID
  v8::Local<v8::Object> paramOneSysNetAreaIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetAreaID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetAreaIDfileData=Nan::To<v8::Integer>( paramOneSysNetAreaIDObj).ToLocalChecked();
  field.SysNetAreaID=paramOneSysNetAreaIDfileData->Value();

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
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //SysNetAreaID
  v8::Local<v8::Object> paramOneSysNetAreaIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetAreaID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetAreaIDfileData=Nan::To<v8::Integer>( paramOneSysNetAreaIDObj).ToLocalChecked();
  field.SysNetAreaID=paramOneSysNetAreaIDfileData->Value();

 //SysNetSubAreaID
  v8::Local<v8::Object> paramOneSysNetSubAreaIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetSubAreaID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetSubAreaIDfileData=Nan::To<v8::Integer>( paramOneSysNetSubAreaIDObj).ToLocalChecked();
  field.SysNetSubAreaID=paramOneSysNetSubAreaIDfileData->Value();

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
  v8::Local<v8::Integer> paramOneSysNetAreaIDfileData=Nan::To<v8::Integer>( paramOneSysNetAreaIDObj).ToLocalChecked();
  field.SysNetAreaID=paramOneSysNetAreaIDfileData->Value();

 //SysNetSubAreaID
  v8::Local<v8::Object> paramOneSysNetSubAreaIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetSubAreaID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetSubAreaIDfileData=Nan::To<v8::Integer>( paramOneSysNetSubAreaIDObj).ToLocalChecked();
  field.SysNetSubAreaID=paramOneSysNetSubAreaIDfileData->Value();

 //IP
  v8::Local<v8::Object> paramOneIPObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IP").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPfileData(Nan::To<v8::String>(paramOneIPObj).ToLocalChecked());
  strcpy_s(field.IP,151,*paramOneIPfileData);

 //Mask
  v8::Local<v8::Object> paramOneMaskObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Mask").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMaskfileData(Nan::To<v8::String>(paramOneMaskObj).ToLocalChecked());
  strcpy_s(field.Mask,151,*paramOneMaskfileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //SysNetSubAreaID
  v8::Local<v8::Object> paramOneSysNetSubAreaIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetSubAreaID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetSubAreaIDfileData=Nan::To<v8::Integer>( paramOneSysNetSubAreaIDObj).ToLocalChecked();
  field.SysNetSubAreaID=paramOneSysNetSubAreaIDfileData->Value();

 //FuctionArea
  v8::Local<v8::Object> paramOneFuctionAreaObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FuctionArea").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFuctionAreafileData(Nan::To<v8::String>(paramOneFuctionAreaObj).ToLocalChecked());
  strcpy_s(field.FuctionArea,641,*paramOneFuctionAreafileData);

 //IPDECODE
  v8::Local<v8::Object> paramOneIPDECODEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPDECODE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIPDECODEfileData=Nan::To<v8::Integer>( paramOneIPDECODEObj).ToLocalChecked();
  field.IPDECODE=paramOneIPDECODEfileData->Value();

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
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

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
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //SysNetBuildingID
  v8::Local<v8::Object> paramOneSysNetBuildingIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetBuildingID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetBuildingIDfileData=Nan::To<v8::Integer>( paramOneSysNetBuildingIDObj).ToLocalChecked();
  field.SysNetBuildingID=paramOneSysNetBuildingIDfileData->Value();

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
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //SysNetRoomID
  v8::Local<v8::Object> paramOneSysNetRoomIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetRoomID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetRoomIDfileData=Nan::To<v8::Integer>( paramOneSysNetRoomIDObj).ToLocalChecked();
  field.SysNetRoomID=paramOneSysNetRoomIDfileData->Value();

 //SysNetBuildingID
  v8::Local<v8::Object> paramOneSysNetBuildingIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetBuildingID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetBuildingIDfileData=Nan::To<v8::Integer>( paramOneSysNetBuildingIDObj).ToLocalChecked();
  field.SysNetBuildingID=paramOneSysNetBuildingIDfileData->Value();

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //Manufactory
  v8::Local<v8::Object> paramOneManufactoryObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Manufactory").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneManufactoryfileData(Nan::To<v8::String>(paramOneManufactoryObj).ToLocalChecked());
  strcpy_s(field.Manufactory,641,*paramOneManufactoryfileData);

 //DeviceType
  v8::Local<v8::Object> paramOneDeviceTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDeviceTypefileData(Nan::To<v8::String>(paramOneDeviceTypeObj).ToLocalChecked());
  strcpy_s(field.DeviceType,641,*paramOneDeviceTypefileData);

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNamefileData(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNamefileData);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENamefileData(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENamefileData);

 //OID
  v8::Local<v8::Object> paramOneOIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOIDfileData(Nan::To<v8::String>(paramOneOIDObj).ToLocalChecked());
  strcpy_s(field.OID,641,*paramOneOIDfileData);

 //Unit
  v8::Local<v8::Object> paramOneUnitObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Unit").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUnitfileData(Nan::To<v8::String>(paramOneUnitObj).ToLocalChecked());
  strcpy_s(field.Unit,641,*paramOneUnitfileData);

 //isTheTable
  v8::Local<v8::Object> paramOneisTheTableObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("isTheTable").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneisTheTablefileData=Nan::To<v8::Integer>( paramOneisTheTableObj).ToLocalChecked();
  field.isTheTable=paramOneisTheTablefileData->Value();

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNamefileData(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNamefileData);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENamefileData(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENamefileData);

 //PolicyType
  v8::Local<v8::Object> paramOnePolicyTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PolicyType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOnePolicyTypefileData=Nan::To<v8::Integer>( paramOnePolicyTypeObj).ToLocalChecked();
  field.PolicyType=paramOnePolicyTypefileData->Value();

 //PolicyString
  v8::Local<v8::Object> paramOnePolicyStringObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PolicyString").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePolicyStringfileData(Nan::To<v8::String>(paramOnePolicyStringObj).ToLocalChecked());
  strcpy_s(field.PolicyString,5121,*paramOnePolicyStringfileData);

 //TradingDay
  v8::Local<v8::Object> paramOneTradingDayObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TradingDay").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTradingDayfileData=Nan::To<v8::Integer>( paramOneTradingDayObj).ToLocalChecked();
  field.TradingDay=paramOneTradingDayfileData->Value();

 //Description
  v8::Local<v8::Object> paramOneDescriptionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Description").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDescriptionfileData(Nan::To<v8::String>(paramOneDescriptionObj).ToLocalChecked());
  strcpy_s(field.Description,2561,*paramOneDescriptionfileData);

 //Operation
  v8::Local<v8::Object> paramOneOperationObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Operation").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperationfileData=Nan::To<v8::Integer>( paramOneOperationObj).ToLocalChecked();
  field.Operation=paramOneOperationfileData->Value();

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDfileData);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypefileData(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,2561,*paramOneAttrTypefileData);

 //PolicyTypeID
  v8::Local<v8::Object> paramOnePolicyTypeIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PolicyTypeID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOnePolicyTypeIDfileData=Nan::To<v8::Integer>( paramOnePolicyTypeIDObj).ToLocalChecked();
  field.PolicyTypeID=paramOnePolicyTypeIDfileData->Value();

 //DataType
  v8::Local<v8::Object> paramOneDataTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DataType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDataTypefileData=Nan::To<v8::Integer>( paramOneDataTypeObj).ToLocalChecked();
  field.DataType=paramOneDataTypefileData->Value();

 //TypeFlag
  v8::Local<v8::Object> paramOneTypeFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TypeFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTypeFlagfileData=Nan::To<v8::Integer>( paramOneTypeFlagObj).ToLocalChecked();
  field.TypeFlag=paramOneTypeFlagfileData->Value();

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
  v8::Local<v8::Integer> paramOneDeviceIDfileData=Nan::To<v8::Integer>( paramOneDeviceIDObj).ToLocalChecked();
  field.DeviceID=paramOneDeviceIDfileData->Value();

 //SysNetSubAreaID
  v8::Local<v8::Object> paramOneSysNetSubAreaIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SysNetSubAreaID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSysNetSubAreaIDfileData=Nan::To<v8::Integer>( paramOneSysNetSubAreaIDObj).ToLocalChecked();
  field.SysNetSubAreaID=paramOneSysNetSubAreaIDfileData->Value();

 //OldObjectID
  v8::Local<v8::Object> paramOneOldObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OldObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOldObjectIDfileData(Nan::To<v8::String>(paramOneOldObjectIDObj).ToLocalChecked());
  strcpy_s(field.OldObjectID,1281,*paramOneOldObjectIDfileData);

 //NewObjectID
  v8::Local<v8::Object> paramOneNewObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("NewObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneNewObjectIDfileData(Nan::To<v8::String>(paramOneNewObjectIDObj).ToLocalChecked());
  strcpy_s(field.NewObjectID,1281,*paramOneNewObjectIDfileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //Manufactory
  v8::Local<v8::Object> paramOneManufactoryObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Manufactory").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneManufactoryfileData(Nan::To<v8::String>(paramOneManufactoryObj).ToLocalChecked());
  strcpy_s(field.Manufactory,641,*paramOneManufactoryfileData);

 //DeviceType
  v8::Local<v8::Object> paramOneDeviceTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDeviceTypefileData(Nan::To<v8::String>(paramOneDeviceTypeObj).ToLocalChecked());
  strcpy_s(field.DeviceType,641,*paramOneDeviceTypefileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNamefileData(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNamefileData);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENamefileData(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENamefileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNamefileData(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNamefileData);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENamefileData(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENamefileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //IPADDR
  v8::Local<v8::Object> paramOneIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPADDRfileData(Nan::To<v8::String>(paramOneIPADDRObj).ToLocalChecked());
  strcpy_s(field.IPADDR,151,*paramOneIPADDRfileData);

 //COMMUNITY
  v8::Local<v8::Object> paramOneCOMMUNITYObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("COMMUNITY").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCOMMUNITYfileData(Nan::To<v8::String>(paramOneCOMMUNITYObj).ToLocalChecked());
  strcpy_s(field.COMMUNITY,641,*paramOneCOMMUNITYfileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNamefileData(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNamefileData);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENamefileData(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENamefileData);

 //Description
  v8::Local<v8::Object> paramOneDescriptionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Description").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDescriptionfileData(Nan::To<v8::String>(paramOneDescriptionObj).ToLocalChecked());
  strcpy_s(field.Description,641,*paramOneDescriptionfileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNamefileData(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNamefileData);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENamefileData(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENamefileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDfileData);

 //MonitorType_ID
  v8::Local<v8::Object> paramOneMonitorType_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonitorType_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneMonitorType_IDfileData=Nan::To<v8::Integer>( paramOneMonitorType_IDObj).ToLocalChecked();
  field.MonitorType_ID=paramOneMonitorType_IDfileData->Value();

 //IfType
  v8::Local<v8::Object> paramOneIfTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IfType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIfTypefileData=Nan::To<v8::Integer>( paramOneIfTypeObj).ToLocalChecked();
  field.IfType=paramOneIfTypefileData->Value();

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENamefileData(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENamefileData);

 //IpAddress
  v8::Local<v8::Object> paramOneIpAddressObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IpAddress").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIpAddressfileData(Nan::To<v8::String>(paramOneIpAddressObj).ToLocalChecked());
  strcpy_s(field.IpAddress,151,*paramOneIpAddressfileData);

 //IpMask
  v8::Local<v8::Object> paramOneIpMaskObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IpMask").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIpMaskfileData(Nan::To<v8::String>(paramOneIpMaskObj).ToLocalChecked());
  strcpy_s(field.IpMask,151,*paramOneIpMaskfileData);

 //IfStatus
  v8::Local<v8::Object> paramOneIfStatusObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IfStatus").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIfStatusfileData=Nan::To<v8::Integer>( paramOneIfStatusObj).ToLocalChecked();
  field.IfStatus=paramOneIfStatusfileData->Value();

 //MAC
  v8::Local<v8::Object> paramOneMACObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MAC").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMACfileData(Nan::To<v8::String>(paramOneMACObj).ToLocalChecked());
  strcpy_s(field.MAC,641,*paramOneMACfileData);

 //DeviceID
  v8::Local<v8::Object> paramOneDeviceIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDeviceIDfileData=Nan::To<v8::Integer>( paramOneDeviceIDObj).ToLocalChecked();
  field.DeviceID=paramOneDeviceIDfileData->Value();

 //DeviceObjectID
  v8::Local<v8::Object> paramOneDeviceObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDeviceObjectIDfileData(Nan::To<v8::String>(paramOneDeviceObjectIDObj).ToLocalChecked());
  strcpy_s(field.DeviceObjectID,1281,*paramOneDeviceObjectIDfileData);

 //DeviceIndex
  v8::Local<v8::Object> paramOneDeviceIndexObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceIndex").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDeviceIndexfileData(Nan::To<v8::String>(paramOneDeviceIndexObj).ToLocalChecked());
  strcpy_s(field.DeviceIndex,161,*paramOneDeviceIndexfileData);

 //isPolling
  v8::Local<v8::Object> paramOneisPollingObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("isPolling").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneisPollingfileData=Nan::To<v8::Integer>( paramOneisPollingObj).ToLocalChecked();
  field.isPolling=paramOneisPollingfileData->Value();

 //Description
  v8::Local<v8::Object> paramOneDescriptionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Description").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDescriptionfileData(Nan::To<v8::String>(paramOneDescriptionObj).ToLocalChecked());
  strcpy_s(field.Description,641,*paramOneDescriptionfileData);

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
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNamefileData(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNamefileData);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENamefileData(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENamefileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNamefileData(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,2561,*paramOneCNamefileData);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENamefileData(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,2561,*paramOneENamefileData);

 //Comments
  v8::Local<v8::Object> paramOneCommentsObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Comments").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCommentsfileData(Nan::To<v8::String>(paramOneCommentsObj).ToLocalChecked());
  strcpy_s(field.Comments,2561,*paramOneCommentsfileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //MANUFACTORY_ID
  v8::Local<v8::Object> paramOneMANUFACTORY_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MANUFACTORY_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneMANUFACTORY_IDfileData=Nan::To<v8::Integer>( paramOneMANUFACTORY_IDObj).ToLocalChecked();
  field.MANUFACTORY_ID=paramOneMANUFACTORY_IDfileData->Value();

 //MonitorType_ID
  v8::Local<v8::Object> paramOneMonitorType_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonitorType_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneMonitorType_IDfileData=Nan::To<v8::Integer>( paramOneMonitorType_IDObj).ToLocalChecked();
  field.MonitorType_ID=paramOneMonitorType_IDfileData->Value();

 //AttrType_ID
  v8::Local<v8::Object> paramOneAttrType_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneAttrType_IDfileData=Nan::To<v8::Integer>( paramOneAttrType_IDObj).ToLocalChecked();
  field.AttrType_ID=paramOneAttrType_IDfileData->Value();

 //MANUFACTORY
  v8::Local<v8::Object> paramOneMANUFACTORYObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MANUFACTORY").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMANUFACTORYfileData(Nan::To<v8::String>(paramOneMANUFACTORYObj).ToLocalChecked());
  strcpy_s(field.MANUFACTORY,641,*paramOneMANUFACTORYfileData);

 //MonitorType
  v8::Local<v8::Object> paramOneMonitorTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonitorType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonitorTypefileData(Nan::To<v8::String>(paramOneMonitorTypeObj).ToLocalChecked());
  strcpy_s(field.MonitorType,641,*paramOneMonitorTypefileData);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypefileData(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,2561,*paramOneAttrTypefileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDfileData);

 //AttrType
  v8::Local<v8::Object> paramOneAttrTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneAttrTypefileData(Nan::To<v8::String>(paramOneAttrTypeObj).ToLocalChecked());
  strcpy_s(field.AttrType,2561,*paramOneAttrTypefileData);

 //PolicyTypeID
  v8::Local<v8::Object> paramOnePolicyTypeIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PolicyTypeID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOnePolicyTypeIDfileData=Nan::To<v8::Integer>( paramOnePolicyTypeIDObj).ToLocalChecked();
  field.PolicyTypeID=paramOnePolicyTypeIDfileData->Value();

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNamefileData(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNamefileData);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENamefileData(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENamefileData);

 //Condition
  v8::Local<v8::Object> paramOneConditionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Condition").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneConditionfileData(Nan::To<v8::String>(paramOneConditionObj).ToLocalChecked());
  strcpy_s(field.Condition,5121,*paramOneConditionfileData);

 //Comments
  v8::Local<v8::Object> paramOneCommentsObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Comments").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCommentsfileData(Nan::To<v8::String>(paramOneCommentsObj).ToLocalChecked());
  strcpy_s(field.Comments,2561,*paramOneCommentsfileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //CName
  v8::Local<v8::Object> paramOneCNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCNamefileData(Nan::To<v8::String>(paramOneCNameObj).ToLocalChecked());
  strcpy_s(field.CName,641,*paramOneCNamefileData);

 //EName
  v8::Local<v8::Object> paramOneENameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneENamefileData(Nan::To<v8::String>(paramOneENameObj).ToLocalChecked());
  strcpy_s(field.EName,641,*paramOneENamefileData);

 //DeviceGroup_ID
  v8::Local<v8::Object> paramOneDeviceGroup_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceGroup_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDeviceGroup_IDfileData=Nan::To<v8::Integer>( paramOneDeviceGroup_IDObj).ToLocalChecked();
  field.DeviceGroup_ID=paramOneDeviceGroup_IDfileData->Value();

 //ManagerGroup_ID
  v8::Local<v8::Object> paramOneManagerGroup_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ManagerGroup_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneManagerGroup_IDfileData=Nan::To<v8::Integer>( paramOneManagerGroup_IDObj).ToLocalChecked();
  field.ManagerGroup_ID=paramOneManagerGroup_IDfileData->Value();

 //TimePolicy_ID
  v8::Local<v8::Object> paramOneTimePolicy_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TimePolicy_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTimePolicy_IDfileData=Nan::To<v8::Integer>( paramOneTimePolicy_IDObj).ToLocalChecked();
  field.TimePolicy_ID=paramOneTimePolicy_IDfileData->Value();

 //TaskPriority_ID
  v8::Local<v8::Object> paramOneTaskPriority_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TaskPriority_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTaskPriority_IDfileData=Nan::To<v8::Integer>( paramOneTaskPriority_IDObj).ToLocalChecked();
  field.TaskPriority_ID=paramOneTaskPriority_IDfileData->Value();

 //OutputPolicy_ID
  v8::Local<v8::Object> paramOneOutputPolicy_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OutputPolicy_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOutputPolicy_IDfileData=Nan::To<v8::Integer>( paramOneOutputPolicy_IDObj).ToLocalChecked();
  field.OutputPolicy_ID=paramOneOutputPolicy_IDfileData->Value();

 //ActionGroup_ID
  v8::Local<v8::Object> paramOneActionGroup_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ActionGroup_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneActionGroup_IDfileData=Nan::To<v8::Integer>( paramOneActionGroup_IDObj).ToLocalChecked();
  field.ActionGroup_ID=paramOneActionGroup_IDfileData->Value();

 //EventExprStr
  v8::Local<v8::Object> paramOneEventExprStrObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EventExprStr").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEventExprStrfileData(Nan::To<v8::String>(paramOneEventExprStrObj).ToLocalChecked());
  strcpy_s(field.EventExprStr,10241,*paramOneEventExprStrfileData);

 //DeviceGroup
  v8::Local<v8::Object> paramOneDeviceGroupObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceGroup").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDeviceGroupfileData(Nan::To<v8::String>(paramOneDeviceGroupObj).ToLocalChecked());
  strcpy_s(field.DeviceGroup,641,*paramOneDeviceGroupfileData);

 //ManagerGroup
  v8::Local<v8::Object> paramOneManagerGroupObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ManagerGroup").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneManagerGroupfileData(Nan::To<v8::String>(paramOneManagerGroupObj).ToLocalChecked());
  strcpy_s(field.ManagerGroup,641,*paramOneManagerGroupfileData);

 //TimePolicy
  v8::Local<v8::Object> paramOneTimePolicyObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TimePolicy").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTimePolicyfileData(Nan::To<v8::String>(paramOneTimePolicyObj).ToLocalChecked());
  strcpy_s(field.TimePolicy,641,*paramOneTimePolicyfileData);

 //TaskPriority
  v8::Local<v8::Object> paramOneTaskPriorityObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TaskPriority").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTaskPriorityfileData(Nan::To<v8::String>(paramOneTaskPriorityObj).ToLocalChecked());
  strcpy_s(field.TaskPriority,641,*paramOneTaskPriorityfileData);

 //OutputPolicy
  v8::Local<v8::Object> paramOneOutputPolicyObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OutputPolicy").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneOutputPolicyfileData(Nan::To<v8::String>(paramOneOutputPolicyObj).ToLocalChecked());
  strcpy_s(field.OutputPolicy,641,*paramOneOutputPolicyfileData);

 //ActionGroup
  v8::Local<v8::Object> paramOneActionGroupObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ActionGroup").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneActionGroupfileData(Nan::To<v8::String>(paramOneActionGroupObj).ToLocalChecked());
  strcpy_s(field.ActionGroup,641,*paramOneActionGroupfileData);

 //ValidFlag
  v8::Local<v8::Object> paramOneValidFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ValidFlag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneValidFlagfileData=Nan::To<v8::Integer>( paramOneValidFlagObj).ToLocalChecked();
  field.ValidFlag=paramOneValidFlagfileData->Value();

 //TaskStatus
  v8::Local<v8::Object> paramOneTaskStatusObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TaskStatus").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTaskStatusfileData=Nan::To<v8::Integer>( paramOneTaskStatusObj).ToLocalChecked();
  field.TaskStatus=paramOneTaskStatusfileData->Value();

 //Comments
  v8::Local<v8::Object> paramOneCommentsObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Comments").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCommentsfileData(Nan::To<v8::String>(paramOneCommentsObj).ToLocalChecked());
  strcpy_s(field.Comments,2561,*paramOneCommentsfileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDfileData);

 //Task_ID
  v8::Local<v8::Object> paramOneTask_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Task_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTask_IDfileData=Nan::To<v8::Integer>( paramOneTask_IDObj).ToLocalChecked();
  field.Task_ID=paramOneTask_IDfileData->Value();

 //OperateTime
  v8::Local<v8::Object> paramOneOperateTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperateTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperateTimefileData=Nan::To<v8::Integer>( paramOneOperateTimeObj).ToLocalChecked();
  field.OperateTime=paramOneOperateTimefileData->Value();

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDatefileData(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDatefileData);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimefileData(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimefileData);

 //InstructChain
  v8::Local<v8::Object> paramOneInstructChainObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("InstructChain").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInstructChainfileData(Nan::To<v8::String>(paramOneInstructChainObj).ToLocalChecked());
  strcpy_s(field.InstructChain,2561,*paramOneInstructChainfileData);

 //ResultChain
  v8::Local<v8::Object> paramOneResultChainObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ResultChain").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneResultChainfileData(Nan::To<v8::String>(paramOneResultChainObj).ToLocalChecked());
  strcpy_s(field.ResultChain,10241,*paramOneResultChainfileData);

 //Flag
  v8::Local<v8::Object> paramOneFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Flag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneFlagfileData=Nan::To<v8::Integer>( paramOneFlagObj).ToLocalChecked();
  field.Flag=paramOneFlagfileData->Value();

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //DeviceGroup_ID
  v8::Local<v8::Object> paramOneDeviceGroup_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceGroup_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDeviceGroup_IDfileData=Nan::To<v8::Integer>( paramOneDeviceGroup_IDObj).ToLocalChecked();
  field.DeviceGroup_ID=paramOneDeviceGroup_IDfileData->Value();

 //Device_ID
  v8::Local<v8::Object> paramOneDevice_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Device_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDevice_IDfileData=Nan::To<v8::Integer>( paramOneDevice_IDObj).ToLocalChecked();
  field.Device_ID=paramOneDevice_IDfileData->Value();

 //DataCenter
  v8::Local<v8::Object> paramOneDataCenterObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DataCenter").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDataCenterfileData=Nan::To<v8::Integer>( paramOneDataCenterObj).ToLocalChecked();
  field.DataCenter=paramOneDataCenterfileData->Value()-48;

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //MEMBER_NO
  v8::Local<v8::Object> paramOneMEMBER_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MEMBER_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMEMBER_NOfileData(Nan::To<v8::String>(paramOneMEMBER_NOObj).ToLocalChecked());
  strcpy_s(field.MEMBER_NO,321,*paramOneMEMBER_NOfileData);

 //MEMBER_NAME
  v8::Local<v8::Object> paramOneMEMBER_NAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MEMBER_NAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMEMBER_NAMEfileData(Nan::To<v8::String>(paramOneMEMBER_NAMEObj).ToLocalChecked());
  strcpy_s(field.MEMBER_NAME,641,*paramOneMEMBER_NAMEfileData);

 //REMOTE_ADDR
  v8::Local<v8::Object> paramOneREMOTE_ADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("REMOTE_ADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneREMOTE_ADDRfileData(Nan::To<v8::String>(paramOneREMOTE_ADDRObj).ToLocalChecked());
  strcpy_s(field.REMOTE_ADDR,641,*paramOneREMOTE_ADDRfileData);

 //LOCAL_ADDR
  v8::Local<v8::Object> paramOneLOCAL_ADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("LOCAL_ADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneLOCAL_ADDRfileData(Nan::To<v8::String>(paramOneLOCAL_ADDRObj).ToLocalChecked());
  strcpy_s(field.LOCAL_ADDR,641,*paramOneLOCAL_ADDRfileData);

 //ADDRESS
  v8::Local<v8::Object> paramOneADDRESSObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ADDRESS").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneADDRESSfileData(Nan::To<v8::String>(paramOneADDRESSObj).ToLocalChecked());
  strcpy_s(field.ADDRESS,2561,*paramOneADDRESSfileData);

 //LINE_STATUS
  v8::Local<v8::Object> paramOneLINE_STATUSObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("LINE_STATUS").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneLINE_STATUSfileData(Nan::To<v8::String>(paramOneLINE_STATUSObj).ToLocalChecked());
  strcpy_s(field.LINE_STATUS,321,*paramOneLINE_STATUSfileData);

 //CONTACT
  v8::Local<v8::Object> paramOneCONTACTObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CONTACT").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCONTACTfileData(Nan::To<v8::String>(paramOneCONTACTObj).ToLocalChecked());
  strcpy_s(field.CONTACT,321,*paramOneCONTACTfileData);

 //TELEPHONE
  v8::Local<v8::Object> paramOneTELEPHONEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TELEPHONE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTELEPHONEfileData(Nan::To<v8::String>(paramOneTELEPHONEObj).ToLocalChecked());
  strcpy_s(field.TELEPHONE,641,*paramOneTELEPHONEfileData);

 //MOBILEPHONE
  v8::Local<v8::Object> paramOneMOBILEPHONEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MOBILEPHONE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMOBILEPHONEfileData(Nan::To<v8::String>(paramOneMOBILEPHONEObj).ToLocalChecked());
  strcpy_s(field.MOBILEPHONE,641,*paramOneMOBILEPHONEfileData);

 //EMAIL
  v8::Local<v8::Object> paramOneEMAILObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EMAIL").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEMAILfileData(Nan::To<v8::String>(paramOneEMAILObj).ToLocalChecked());
  strcpy_s(field.EMAIL,641,*paramOneEMAILfileData);

 //FAX
  v8::Local<v8::Object> paramOneFAXObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FAX").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFAXfileData(Nan::To<v8::String>(paramOneFAXObj).ToLocalChecked());
  strcpy_s(field.FAX,641,*paramOneFAXfileData);

 //PROVINCE
  v8::Local<v8::Object> paramOnePROVINCEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PROVINCE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePROVINCEfileData(Nan::To<v8::String>(paramOnePROVINCEObj).ToLocalChecked());
  strcpy_s(field.PROVINCE,321,*paramOnePROVINCEfileData);

 //DDN_NO
  v8::Local<v8::Object> paramOneDDN_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DDN_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDDN_NOfileData(Nan::To<v8::String>(paramOneDDN_NOObj).ToLocalChecked());
  strcpy_s(field.DDN_NO,641,*paramOneDDN_NOfileData);

 //IN_MODE
  v8::Local<v8::Object> paramOneIN_MODEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IN_MODE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIN_MODEfileData(Nan::To<v8::String>(paramOneIN_MODEObj).ToLocalChecked());
  strcpy_s(field.IN_MODE,641,*paramOneIN_MODEfileData);

 //IP_WAN
  v8::Local<v8::Object> paramOneIP_WANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IP_WAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIP_WANfileData(Nan::To<v8::String>(paramOneIP_WANObj).ToLocalChecked());
  strcpy_s(field.IP_WAN,641,*paramOneIP_WANfileData);

 //IP_LAN
  v8::Local<v8::Object> paramOneIP_LANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IP_LAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIP_LANfileData(Nan::To<v8::String>(paramOneIP_LANObj).ToLocalChecked());
  strcpy_s(field.IP_LAN,641,*paramOneIP_LANfileData);

 //IPADDR
  v8::Local<v8::Object> paramOneIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPADDRfileData(Nan::To<v8::String>(paramOneIPADDRObj).ToLocalChecked());
  strcpy_s(field.IPADDR,641,*paramOneIPADDRfileData);

 //Interface
  v8::Local<v8::Object> paramOneInterfaceObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Interface").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInterfacefileData(Nan::To<v8::String>(paramOneInterfaceObj).ToLocalChecked());
  strcpy_s(field.Interface,641,*paramOneInterfacefileData);

 //INTERFACE_DATE
  v8::Local<v8::Object> paramOneINTERFACE_DATEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("INTERFACE_DATE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneINTERFACE_DATEfileData(Nan::To<v8::String>(paramOneINTERFACE_DATEObj).ToLocalChecked());
  strcpy_s(field.INTERFACE_DATE,321,*paramOneINTERFACE_DATEfileData);

 //SOFTWARE
  v8::Local<v8::Object> paramOneSOFTWAREObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SOFTWARE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSOFTWAREfileData(Nan::To<v8::String>(paramOneSOFTWAREObj).ToLocalChecked());
  strcpy_s(field.SOFTWARE,321,*paramOneSOFTWAREfileData);

 //FEE_TYPE
  v8::Local<v8::Object> paramOneFEE_TYPEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FEE_TYPE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFEE_TYPEfileData(Nan::To<v8::String>(paramOneFEE_TYPEObj).ToLocalChecked());
  strcpy_s(field.FEE_TYPE,321,*paramOneFEE_TYPEfileData);

 //SERVICEPROVIDER
  v8::Local<v8::Object> paramOneSERVICEPROVIDERObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SERVICEPROVIDER").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSERVICEPROVIDERfileData(Nan::To<v8::String>(paramOneSERVICEPROVIDERObj).ToLocalChecked());
  strcpy_s(field.SERVICEPROVIDER,321,*paramOneSERVICEPROVIDERfileData);

 //IF_ZIYING
  v8::Local<v8::Object> paramOneIF_ZIYINGObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IF_ZIYING").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIF_ZIYINGfileData(Nan::To<v8::String>(paramOneIF_ZIYINGObj).ToLocalChecked());
  strcpy_s(field.IF_ZIYING,321,*paramOneIF_ZIYINGfileData);

 //IF_TUOGUAN
  v8::Local<v8::Object> paramOneIF_TUOGUANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IF_TUOGUAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIF_TUOGUANfileData(Nan::To<v8::String>(paramOneIF_TUOGUANObj).ToLocalChecked());
  strcpy_s(field.IF_TUOGUAN,321,*paramOneIF_TUOGUANfileData);

 //HASOTHER
  v8::Local<v8::Object> paramOneHASOTHERObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HASOTHER").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHASOTHERfileData(Nan::To<v8::String>(paramOneHASOTHERObj).ToLocalChecked());
  strcpy_s(field.HASOTHER,321,*paramOneHASOTHERfileData);

 //SEAT_NO
  v8::Local<v8::Object> paramOneSEAT_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SEAT_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSEAT_NOfileData(Nan::To<v8::String>(paramOneSEAT_NOObj).ToLocalChecked());
  strcpy_s(field.SEAT_NO,10241,*paramOneSEAT_NOfileData);

 //PRO
  v8::Local<v8::Object> paramOnePROObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PRO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePROfileData(Nan::To<v8::String>(paramOnePROObj).ToLocalChecked());
  strcpy_s(field.PRO,5121,*paramOnePROfileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //ActionGroup_ID
  v8::Local<v8::Object> paramOneActionGroup_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ActionGroup_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneActionGroup_IDfileData=Nan::To<v8::Integer>( paramOneActionGroup_IDObj).ToLocalChecked();
  field.ActionGroup_ID=paramOneActionGroup_IDfileData->Value();

 //MonitorAttr_ID
  v8::Local<v8::Object> paramOneMonitorAttr_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonitorAttr_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneMonitorAttr_IDfileData=Nan::To<v8::Integer>( paramOneMonitorAttr_IDObj).ToLocalChecked();
  field.MonitorAttr_ID=paramOneMonitorAttr_IDfileData->Value();

 //MonitorAttrName
  v8::Local<v8::Object> paramOneMonitorAttrNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonitorAttrName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonitorAttrNamefileData(Nan::To<v8::String>(paramOneMonitorAttrNameObj).ToLocalChecked());
  strcpy_s(field.MonitorAttrName,2561,*paramOneMonitorAttrNamefileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDfileData);

 //MonitorType_ID
  v8::Local<v8::Object> paramOneMonitorType_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonitorType_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneMonitorType_IDfileData=Nan::To<v8::Integer>( paramOneMonitorType_IDObj).ToLocalChecked();
  field.MonitorType_ID=paramOneMonitorType_IDfileData->Value();

 //DeviceID
  v8::Local<v8::Object> paramOneDeviceIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneDeviceIDfileData=Nan::To<v8::Integer>( paramOneDeviceIDObj).ToLocalChecked();
  field.DeviceID=paramOneDeviceIDfileData->Value();

 //DeviceObjectID
  v8::Local<v8::Object> paramOneDeviceObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDeviceObjectIDfileData(Nan::To<v8::String>(paramOneDeviceObjectIDObj).ToLocalChecked());
  strcpy_s(field.DeviceObjectID,1281,*paramOneDeviceObjectIDfileData);

 //Name
  v8::Local<v8::Object> paramOneNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Name").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneNamefileData(Nan::To<v8::String>(paramOneNameObj).ToLocalChecked());
  strcpy_s(field.Name,641,*paramOneNamefileData);

 //Description
  v8::Local<v8::Object> paramOneDescriptionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Description").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDescriptionfileData(Nan::To<v8::String>(paramOneDescriptionObj).ToLocalChecked());
  strcpy_s(field.Description,1281,*paramOneDescriptionfileData);

 //ModuleIndex
  v8::Local<v8::Object> paramOneModuleIndexObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ModuleIndex").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneModuleIndexfileData=Nan::To<v8::Integer>( paramOneModuleIndexObj).ToLocalChecked();
  field.ModuleIndex=paramOneModuleIndexfileData->Value();

 //EntPhyIndex
  v8::Local<v8::Object> paramOneEntPhyIndexObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EntPhyIndex").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneEntPhyIndexfileData=Nan::To<v8::Integer>( paramOneEntPhyIndexObj).ToLocalChecked();
  field.EntPhyIndex=paramOneEntPhyIndexfileData->Value();

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDfileData);

 //Task_ID
  v8::Local<v8::Object> paramOneTask_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Task_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneTask_IDfileData=Nan::To<v8::Integer>( paramOneTask_IDObj).ToLocalChecked();
  field.Task_ID=paramOneTask_IDfileData->Value();

 //OperateTime
  v8::Local<v8::Object> paramOneOperateTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperateTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperateTimefileData=Nan::To<v8::Integer>( paramOneOperateTimeObj).ToLocalChecked();
  field.OperateTime=paramOneOperateTimefileData->Value();

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDatefileData(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDatefileData);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimefileData(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimefileData);

 //Flag
  v8::Local<v8::Object> paramOneFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Flag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneFlagfileData=Nan::To<v8::Integer>( paramOneFlagObj).ToLocalChecked();
  field.Flag=paramOneFlagfileData->Value();

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDfileData);

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDatefileData(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDatefileData);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimefileData(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimefileData);

 //CfgFileName
  v8::Local<v8::Object> paramOneCfgFileNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CfgFileName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCfgFileNamefileData(Nan::To<v8::String>(paramOneCfgFileNameObj).ToLocalChecked());
  strcpy_s(field.CfgFileName,2561,*paramOneCfgFileNamefileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //ObjectID
  v8::Local<v8::Object> paramOneObjectIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneObjectIDfileData(Nan::To<v8::String>(paramOneObjectIDObj).ToLocalChecked());
  strcpy_s(field.ObjectID,1281,*paramOneObjectIDfileData);

 //IPAddress
  v8::Local<v8::Object> paramOneIPAddressObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPAddress").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPAddressfileData(Nan::To<v8::String>(paramOneIPAddressObj).ToLocalChecked());
  strcpy_s(field.IPAddress,151,*paramOneIPAddressfileData);

 //Manufactory_ID
  v8::Local<v8::Object> paramOneManufactory_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Manufactory_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneManufactory_IDfileData=Nan::To<v8::Integer>( paramOneManufactory_IDObj).ToLocalChecked();
  field.Manufactory_ID=paramOneManufactory_IDfileData->Value();

 //InstructChain
  v8::Local<v8::Object> paramOneInstructChainObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("InstructChain").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInstructChainfileData(Nan::To<v8::String>(paramOneInstructChainObj).ToLocalChecked());
  strcpy_s(field.InstructChain,2561,*paramOneInstructChainfileData);

 //InstructAlias
  v8::Local<v8::Object> paramOneInstructAliasObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("InstructAlias").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInstructAliasfileData(Nan::To<v8::String>(paramOneInstructAliasObj).ToLocalChecked());
  strcpy_s(field.InstructAlias,1281,*paramOneInstructAliasfileData);

 //InstructArgs
  v8::Local<v8::Object> paramOneInstructArgsObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("InstructArgs").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInstructArgsfileData(Nan::To<v8::String>(paramOneInstructArgsObj).ToLocalChecked());
  strcpy_s(field.InstructArgs,2561,*paramOneInstructArgsfileData);

 //DefParamChain
  v8::Local<v8::Object> paramOneDefParamChainObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DefParamChain").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDefParamChainfileData(Nan::To<v8::String>(paramOneDefParamChainObj).ToLocalChecked());
  strcpy_s(field.DefParamChain,20001,*paramOneDefParamChainfileData);

 //Flag
  v8::Local<v8::Object> paramOneFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Flag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneFlagfileData=Nan::To<v8::Integer>( paramOneFlagObj).ToLocalChecked();
  field.Flag=paramOneFlagfileData->Value();

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //FileName
  v8::Local<v8::Object> paramOneFileNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FileName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFileNamefileData(Nan::To<v8::String>(paramOneFileNameObj).ToLocalChecked());
  strcpy_s(field.FileName,2561,*paramOneFileNamefileData);

 //Version
  v8::Local<v8::Object> paramOneVersionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Version").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneVersionfileData(Nan::To<v8::String>(paramOneVersionObj).ToLocalChecked());
  strcpy_s(field.Version,161,*paramOneVersionfileData);

 //SubVersion
  v8::Local<v8::Object> paramOneSubVersionObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SubVersion").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneSubVersionfileData=Nan::To<v8::Integer>( paramOneSubVersionObj).ToLocalChecked();
  field.SubVersion=paramOneSubVersionfileData->Value();

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDatefileData(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDatefileData);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimefileData(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimefileData);

 //UserName
  v8::Local<v8::Object> paramOneUserNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneUserNamefileData(Nan::To<v8::String>(paramOneUserNameObj).ToLocalChecked());
  strcpy_s(field.UserName,201,*paramOneUserNamefileData);

 //OperType
  v8::Local<v8::Object> paramOneOperTypeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperType").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperTypefileData=Nan::To<v8::Integer>( paramOneOperTypeObj).ToLocalChecked();
  field.OperType=paramOneOperTypefileData->Value();

 //OperResult
  v8::Local<v8::Object> paramOneOperResultObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("OperResult").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOperResultfileData=Nan::To<v8::Integer>( paramOneOperResultObj).ToLocalChecked();
  field.OperResult=paramOneOperResultfileData->Value();

 //Comments
  v8::Local<v8::Object> paramOneCommentsObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Comments").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCommentsfileData(Nan::To<v8::String>(paramOneCommentsObj).ToLocalChecked());
  strcpy_s(field.Comments,2561,*paramOneCommentsfileData);

 //Offset
  v8::Local<v8::Object> paramOneOffsetObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Offset").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneOffsetfileData=Nan::To<v8::Integer>( paramOneOffsetObj).ToLocalChecked();
  field.Offset=paramOneOffsetfileData->Value();

 //Length
  v8::Local<v8::Object> paramOneLengthObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Length").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneLengthfileData=Nan::To<v8::Integer>( paramOneLengthObj).ToLocalChecked();
  field.Length=paramOneLengthfileData->Value();

 //FileContent
  v8::Local<v8::Object> paramOneFileContentObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FileContent").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFileContentfileData(Nan::To<v8::String>(paramOneFileContentObj).ToLocalChecked());
  strcpy_s(field.FileContent,30001,*paramOneFileContentfileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //MANUFACTORY_ID
  v8::Local<v8::Object> paramOneMANUFACTORY_IDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MANUFACTORY_ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneMANUFACTORY_IDfileData=Nan::To<v8::Integer>( paramOneMANUFACTORY_IDObj).ToLocalChecked();
  field.MANUFACTORY_ID=paramOneMANUFACTORY_IDfileData->Value();

 //Name
  v8::Local<v8::Object> paramOneNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Name").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneNamefileData(Nan::To<v8::String>(paramOneNameObj).ToLocalChecked());
  strcpy_s(field.Name,1281,*paramOneNamefileData);

 //SerialUsed
  v8::Local<v8::Object> paramOneSerialUsedObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SerialUsed").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSerialUsedfileData(Nan::To<v8::String>(paramOneSerialUsedObj).ToLocalChecked());
  strcpy_s(field.SerialUsed,1281,*paramOneSerialUsedfileData);

 //data
  v8::Local<v8::Object> paramOnedataObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("data").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnedatafileData(Nan::To<v8::String>(paramOnedataObj).ToLocalChecked());
  strcpy_s(field.data,20001,*paramOnedatafileData);

 //memo
  v8::Local<v8::Object> paramOnememoObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("memo").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnememofileData(Nan::To<v8::String>(paramOnememoObj).ToLocalChecked());
  strcpy_s(field.memo,2561,*paramOnememofileData);

 //Flag
  v8::Local<v8::Object> paramOneFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Flag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneFlagfileData=Nan::To<v8::Integer>( paramOneFlagObj).ToLocalChecked();
  field.Flag=paramOneFlagfileData->Value();

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //BaseLineName
  v8::Local<v8::Object> paramOneBaseLineNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("BaseLineName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneBaseLineNamefileData(Nan::To<v8::String>(paramOneBaseLineNameObj).ToLocalChecked());
  strcpy_s(field.BaseLineName,1281,*paramOneBaseLineNamefileData);

 //DeviceObjID
  v8::Local<v8::Object> paramOneDeviceObjIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceObjID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDeviceObjIDfileData(Nan::To<v8::String>(paramOneDeviceObjIDObj).ToLocalChecked());
  strcpy_s(field.DeviceObjID,1281,*paramOneDeviceObjIDfileData);

 //DeviceIP
  v8::Local<v8::Object> paramOneDeviceIPObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DeviceIP").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDeviceIPfileData(Nan::To<v8::String>(paramOneDeviceIPObj).ToLocalChecked());
  strcpy_s(field.DeviceIP,151,*paramOneDeviceIPfileData);

 //Result
  v8::Local<v8::Object> paramOneResultObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Result").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneResultfileData(Nan::To<v8::String>(paramOneResultObj).ToLocalChecked());
  strcpy_s(field.Result,30001,*paramOneResultfileData);

 //GenDate
  v8::Local<v8::Object> paramOneGenDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("GenDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneGenDatefileData(Nan::To<v8::String>(paramOneGenDateObj).ToLocalChecked());
  strcpy_s(field.GenDate,81,*paramOneGenDatefileData);

 //GenTime
  v8::Local<v8::Object> paramOneGenTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("GenTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneGenTimefileData(Nan::To<v8::String>(paramOneGenTimeObj).ToLocalChecked());
  strcpy_s(field.GenTime,81,*paramOneGenTimefileData);

 //GenUser
  v8::Local<v8::Object> paramOneGenUserObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("GenUser").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneGenUserfileData(Nan::To<v8::String>(paramOneGenUserObj).ToLocalChecked());
  strcpy_s(field.GenUser,201,*paramOneGenUserfileData);

 //Flag
  v8::Local<v8::Object> paramOneFlagObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Flag").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneFlagfileData=Nan::To<v8::Integer>( paramOneFlagObj).ToLocalChecked();
  field.Flag=paramOneFlagfileData->Value();

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //KeyCompare
  v8::Local<v8::Object> paramOneKeyCompareObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeyCompare").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeyComparefileData=Nan::To<v8::Integer>( paramOneKeyCompareObj).ToLocalChecked();
  field.KeyCompare=paramOneKeyComparefileData->Value()-48;

 //KeyName
  v8::Local<v8::Object> paramOneKeyNameObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeyName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneKeyNamefileData(Nan::To<v8::String>(paramOneKeyNameObj).ToLocalChecked());
  strcpy_s(field.KeyName,2561,*paramOneKeyNamefileData);

 //KeyValue
  v8::Local<v8::Object> paramOneKeyValueObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("KeyValue").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneKeyValuefileData(Nan::To<v8::String>(paramOneKeyValueObj).ToLocalChecked());
  strcpy_s(field.KeyValue,2561,*paramOneKeyValuefileData);

 //MonDate
  v8::Local<v8::Object> paramOneMonDateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonDatefileData(Nan::To<v8::String>(paramOneMonDateObj).ToLocalChecked());
  strcpy_s(field.MonDate,81,*paramOneMonDatefileData);

 //MonTime
  v8::Local<v8::Object> paramOneMonTimeObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMonTimefileData(Nan::To<v8::String>(paramOneMonTimeObj).ToLocalChecked());
  strcpy_s(field.MonTime,81,*paramOneMonTimefileData);

 //SEAT_NO
  v8::Local<v8::Object> paramOneSEAT_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SEAT_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSEAT_NOfileData(Nan::To<v8::String>(paramOneSEAT_NOObj).ToLocalChecked());
  strcpy_s(field.SEAT_NO,321,*paramOneSEAT_NOfileData);

 //IPADDR
  v8::Local<v8::Object> paramOneIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPADDRfileData(Nan::To<v8::String>(paramOneIPADDRObj).ToLocalChecked());
  strcpy_s(field.IPADDR,641,*paramOneIPADDRfileData);

 //Interface
  v8::Local<v8::Object> paramOneInterfaceObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Interface").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInterfacefileData(Nan::To<v8::String>(paramOneInterfaceObj).ToLocalChecked());
  strcpy_s(field.Interface,641,*paramOneInterfacefileData);

 //status
  v8::Local<v8::Object> paramOnestatusObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("status").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnestatusfileData(Nan::To<v8::String>(paramOnestatusObj).ToLocalChecked());
  strcpy_s(field.status,641,*paramOnestatusfileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //SouIPADDR
  v8::Local<v8::Object> paramOneSouIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SouIPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSouIPADDRfileData(Nan::To<v8::String>(paramOneSouIPADDRObj).ToLocalChecked());
  strcpy_s(field.SouIPADDR,151,*paramOneSouIPADDRfileData);

 //SouNAME
  v8::Local<v8::Object> paramOneSouNAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SouNAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSouNAMEfileData(Nan::To<v8::String>(paramOneSouNAMEObj).ToLocalChecked());
  strcpy_s(field.SouNAME,1281,*paramOneSouNAMEfileData);

 //TarIPADDR
  v8::Local<v8::Object> paramOneTarIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TarIPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTarIPADDRfileData(Nan::To<v8::String>(paramOneTarIPADDRObj).ToLocalChecked());
  strcpy_s(field.TarIPADDR,151,*paramOneTarIPADDRfileData);

 //TarNAME
  v8::Local<v8::Object> paramOneTarNAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TarNAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTarNAMEfileData(Nan::To<v8::String>(paramOneTarNAMEObj).ToLocalChecked());
  strcpy_s(field.TarNAME,1281,*paramOneTarNAMEfileData);

 //PDateSta
  v8::Local<v8::Object> paramOnePDateStaObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PDateSta").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePDateStafileData(Nan::To<v8::String>(paramOnePDateStaObj).ToLocalChecked());
  strcpy_s(field.PDateSta,81,*paramOnePDateStafileData);

 //PTimeSta
  v8::Local<v8::Object> paramOnePTimeStaObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PTimeSta").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePTimeStafileData(Nan::To<v8::String>(paramOnePTimeStaObj).ToLocalChecked());
  strcpy_s(field.PTimeSta,81,*paramOnePTimeStafileData);

 //ConnRate
  v8::Local<v8::Object> paramOneConnRateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ConnRate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneConnRatefileData=Nan::To<v8::Integer>( paramOneConnRateObj).ToLocalChecked();
  field.ConnRate=paramOneConnRatefileData->Value();

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //SouIPADDR
  v8::Local<v8::Object> paramOneSouIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SouIPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSouIPADDRfileData(Nan::To<v8::String>(paramOneSouIPADDRObj).ToLocalChecked());
  strcpy_s(field.SouIPADDR,151,*paramOneSouIPADDRfileData);

 //SouNAME
  v8::Local<v8::Object> paramOneSouNAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SouNAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSouNAMEfileData(Nan::To<v8::String>(paramOneSouNAMEObj).ToLocalChecked());
  strcpy_s(field.SouNAME,1281,*paramOneSouNAMEfileData);

 //TarIPADDR
  v8::Local<v8::Object> paramOneTarIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TarIPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTarIPADDRfileData(Nan::To<v8::String>(paramOneTarIPADDRObj).ToLocalChecked());
  strcpy_s(field.TarIPADDR,151,*paramOneTarIPADDRfileData);

 //TarNAME
  v8::Local<v8::Object> paramOneTarNAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TarNAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTarNAMEfileData(Nan::To<v8::String>(paramOneTarNAMEObj).ToLocalChecked());
  strcpy_s(field.TarNAME,1281,*paramOneTarNAMEfileData);

 //PDateSta
  v8::Local<v8::Object> paramOnePDateStaObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PDateSta").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePDateStafileData(Nan::To<v8::String>(paramOnePDateStaObj).ToLocalChecked());
  strcpy_s(field.PDateSta,81,*paramOnePDateStafileData);

 //PTimeSta
  v8::Local<v8::Object> paramOnePTimeStaObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PTimeSta").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePTimeStafileData(Nan::To<v8::String>(paramOnePTimeStaObj).ToLocalChecked());
  strcpy_s(field.PTimeSta,81,*paramOnePTimeStafileData);

 //ConnRate
  v8::Local<v8::Object> paramOneConnRateObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ConnRate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneConnRatefileData=Nan::To<v8::Integer>( paramOneConnRateObj).ToLocalChecked();
  field.ConnRate=paramOneConnRatefileData->Value();

 //TimeDlyMin
  v8::Local<v8::Object> paramOneTimeDlyMinObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TimeDlyMin").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTimeDlyMinfileData(Nan::To<v8::String>(paramOneTimeDlyMinObj).ToLocalChecked());
  strcpy_s(field.TimeDlyMin,1281,*paramOneTimeDlyMinfileData);

 //TimeDlyMax
  v8::Local<v8::Object> paramOneTimeDlyMaxObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TimeDlyMax").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTimeDlyMaxfileData(Nan::To<v8::String>(paramOneTimeDlyMaxObj).ToLocalChecked());
  strcpy_s(field.TimeDlyMax,1281,*paramOneTimeDlyMaxfileData);

 //TimeDlyAvg
  v8::Local<v8::Object> paramOneTimeDlyAvgObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TimeDlyAvg").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTimeDlyAvgfileData(Nan::To<v8::String>(paramOneTimeDlyAvgObj).ToLocalChecked());
  strcpy_s(field.TimeDlyAvg,1281,*paramOneTimeDlyAvgfileData);

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
  v8::Local<v8::Integer> paramOneOperationTypefileData=Nan::To<v8::Integer>( paramOneOperationTypeObj).ToLocalChecked();
  field.OperationType=paramOneOperationTypefileData->Value();

 //ID
  v8::Local<v8::Object> paramOneIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneIDfileData=Nan::To<v8::Integer>( paramOneIDObj).ToLocalChecked();
  field.ID=paramOneIDfileData->Value();

 //MEMBER_NO
  v8::Local<v8::Object> paramOneMEMBER_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MEMBER_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMEMBER_NOfileData(Nan::To<v8::String>(paramOneMEMBER_NOObj).ToLocalChecked());
  strcpy_s(field.MEMBER_NO,321,*paramOneMEMBER_NOfileData);

 //MEMBER_NAME
  v8::Local<v8::Object> paramOneMEMBER_NAMEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MEMBER_NAME").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMEMBER_NAMEfileData(Nan::To<v8::String>(paramOneMEMBER_NAMEObj).ToLocalChecked());
  strcpy_s(field.MEMBER_NAME,641,*paramOneMEMBER_NAMEfileData);

 //REMOTE_ADDR
  v8::Local<v8::Object> paramOneREMOTE_ADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("REMOTE_ADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneREMOTE_ADDRfileData(Nan::To<v8::String>(paramOneREMOTE_ADDRObj).ToLocalChecked());
  strcpy_s(field.REMOTE_ADDR,641,*paramOneREMOTE_ADDRfileData);

 //LOCAL_ADDR
  v8::Local<v8::Object> paramOneLOCAL_ADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("LOCAL_ADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneLOCAL_ADDRfileData(Nan::To<v8::String>(paramOneLOCAL_ADDRObj).ToLocalChecked());
  strcpy_s(field.LOCAL_ADDR,641,*paramOneLOCAL_ADDRfileData);

 //ADDRESS
  v8::Local<v8::Object> paramOneADDRESSObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("ADDRESS").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneADDRESSfileData(Nan::To<v8::String>(paramOneADDRESSObj).ToLocalChecked());
  strcpy_s(field.ADDRESS,2561,*paramOneADDRESSfileData);

 //LINE_STATUS
  v8::Local<v8::Object> paramOneLINE_STATUSObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("LINE_STATUS").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneLINE_STATUSfileData(Nan::To<v8::String>(paramOneLINE_STATUSObj).ToLocalChecked());
  strcpy_s(field.LINE_STATUS,321,*paramOneLINE_STATUSfileData);

 //CONTACT
  v8::Local<v8::Object> paramOneCONTACTObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("CONTACT").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneCONTACTfileData(Nan::To<v8::String>(paramOneCONTACTObj).ToLocalChecked());
  strcpy_s(field.CONTACT,321,*paramOneCONTACTfileData);

 //TELEPHONE
  v8::Local<v8::Object> paramOneTELEPHONEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("TELEPHONE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneTELEPHONEfileData(Nan::To<v8::String>(paramOneTELEPHONEObj).ToLocalChecked());
  strcpy_s(field.TELEPHONE,641,*paramOneTELEPHONEfileData);

 //MOBILEPHONE
  v8::Local<v8::Object> paramOneMOBILEPHONEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("MOBILEPHONE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneMOBILEPHONEfileData(Nan::To<v8::String>(paramOneMOBILEPHONEObj).ToLocalChecked());
  strcpy_s(field.MOBILEPHONE,641,*paramOneMOBILEPHONEfileData);

 //EMAIL
  v8::Local<v8::Object> paramOneEMAILObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("EMAIL").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEMAILfileData(Nan::To<v8::String>(paramOneEMAILObj).ToLocalChecked());
  strcpy_s(field.EMAIL,641,*paramOneEMAILfileData);

 //FAX
  v8::Local<v8::Object> paramOneFAXObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FAX").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFAXfileData(Nan::To<v8::String>(paramOneFAXObj).ToLocalChecked());
  strcpy_s(field.FAX,641,*paramOneFAXfileData);

 //PROVINCE
  v8::Local<v8::Object> paramOnePROVINCEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PROVINCE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePROVINCEfileData(Nan::To<v8::String>(paramOnePROVINCEObj).ToLocalChecked());
  strcpy_s(field.PROVINCE,321,*paramOnePROVINCEfileData);

 //DDN_NO
  v8::Local<v8::Object> paramOneDDN_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("DDN_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneDDN_NOfileData(Nan::To<v8::String>(paramOneDDN_NOObj).ToLocalChecked());
  strcpy_s(field.DDN_NO,641,*paramOneDDN_NOfileData);

 //IN_MODE
  v8::Local<v8::Object> paramOneIN_MODEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IN_MODE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIN_MODEfileData(Nan::To<v8::String>(paramOneIN_MODEObj).ToLocalChecked());
  strcpy_s(field.IN_MODE,641,*paramOneIN_MODEfileData);

 //IP_WAN
  v8::Local<v8::Object> paramOneIP_WANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IP_WAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIP_WANfileData(Nan::To<v8::String>(paramOneIP_WANObj).ToLocalChecked());
  strcpy_s(field.IP_WAN,641,*paramOneIP_WANfileData);

 //IP_LAN
  v8::Local<v8::Object> paramOneIP_LANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IP_LAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIP_LANfileData(Nan::To<v8::String>(paramOneIP_LANObj).ToLocalChecked());
  strcpy_s(field.IP_LAN,641,*paramOneIP_LANfileData);

 //IPADDR
  v8::Local<v8::Object> paramOneIPADDRObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IPADDR").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIPADDRfileData(Nan::To<v8::String>(paramOneIPADDRObj).ToLocalChecked());
  strcpy_s(field.IPADDR,641,*paramOneIPADDRfileData);

 //Interface
  v8::Local<v8::Object> paramOneInterfaceObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Interface").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneInterfacefileData(Nan::To<v8::String>(paramOneInterfaceObj).ToLocalChecked());
  strcpy_s(field.Interface,641,*paramOneInterfacefileData);

 //INTERFACE_DATE
  v8::Local<v8::Object> paramOneINTERFACE_DATEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("INTERFACE_DATE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneINTERFACE_DATEfileData(Nan::To<v8::String>(paramOneINTERFACE_DATEObj).ToLocalChecked());
  strcpy_s(field.INTERFACE_DATE,321,*paramOneINTERFACE_DATEfileData);

 //SOFTWARE
  v8::Local<v8::Object> paramOneSOFTWAREObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SOFTWARE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSOFTWAREfileData(Nan::To<v8::String>(paramOneSOFTWAREObj).ToLocalChecked());
  strcpy_s(field.SOFTWARE,321,*paramOneSOFTWAREfileData);

 //FEE_TYPE
  v8::Local<v8::Object> paramOneFEE_TYPEObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("FEE_TYPE").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneFEE_TYPEfileData(Nan::To<v8::String>(paramOneFEE_TYPEObj).ToLocalChecked());
  strcpy_s(field.FEE_TYPE,321,*paramOneFEE_TYPEfileData);

 //SERVICEPROVIDER
  v8::Local<v8::Object> paramOneSERVICEPROVIDERObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SERVICEPROVIDER").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSERVICEPROVIDERfileData(Nan::To<v8::String>(paramOneSERVICEPROVIDERObj).ToLocalChecked());
  strcpy_s(field.SERVICEPROVIDER,321,*paramOneSERVICEPROVIDERfileData);

 //IF_ZIYING
  v8::Local<v8::Object> paramOneIF_ZIYINGObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IF_ZIYING").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIF_ZIYINGfileData(Nan::To<v8::String>(paramOneIF_ZIYINGObj).ToLocalChecked());
  strcpy_s(field.IF_ZIYING,321,*paramOneIF_ZIYINGfileData);

 //IF_TUOGUAN
  v8::Local<v8::Object> paramOneIF_TUOGUANObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("IF_TUOGUAN").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneIF_TUOGUANfileData(Nan::To<v8::String>(paramOneIF_TUOGUANObj).ToLocalChecked());
  strcpy_s(field.IF_TUOGUAN,321,*paramOneIF_TUOGUANfileData);

 //HASOTHER
  v8::Local<v8::Object> paramOneHASOTHERObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("HASOTHER").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHASOTHERfileData(Nan::To<v8::String>(paramOneHASOTHERObj).ToLocalChecked());
  strcpy_s(field.HASOTHER,321,*paramOneHASOTHERfileData);

 //SEAT_NO
  v8::Local<v8::Object> paramOneSEAT_NOObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("SEAT_NO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneSEAT_NOfileData(Nan::To<v8::String>(paramOneSEAT_NOObj).ToLocalChecked());
  strcpy_s(field.SEAT_NO,10241,*paramOneSEAT_NOfileData);

 //PRO
  v8::Local<v8::Object> paramOnePROObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("PRO").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOnePROfileData(Nan::To<v8::String>(paramOnePROObj).ToLocalChecked());
  strcpy_s(field.PRO,5121,*paramOnePROfileData);

  //convert parameter two
  v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int64_t nRequestID=paramTwo->Value();

  //call native method
  double returnValue= obj->_userApi->ReqQryNetNonPartyLinkInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
