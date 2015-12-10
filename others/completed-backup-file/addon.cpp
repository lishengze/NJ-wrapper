
#include <nan.h>
#include "FtdcSysUserApi_Wrapper.h"
#include "SpiCFunc.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
        
    FtdcSysUserApi_Wrapper::InitExports (exports);
   
    uv_async_init (uv_default_loop(), &g_FrontConnected_async, OnFrontConnected);
    
    uv_async_init (uv_default_loop(), &g_FrontDisconnected_async, OnFrontDisconnected);
    uv_mutex_init (&g_FrontDisconnected_mutex);
    
    uv_async_init (uv_default_loop(), &g_HeartBeatWarning_async, OnHeartBeatWarning);
    uv_mutex_init (&g_HeartBeatWarning_mutex);
   
    // 以下为自动生成
    uv_async_init (uv_default_loop(), &g_RspQryTopCpuInfoTopic_async, OnRspQryTopCpuInfoTopic);
    uv_mutex_init (&g_RspQryTopCpuInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnTopCpuInfoTopic_async, OnRtnTopCpuInfoTopic);
    uv_mutex_init (&g_RtnTopCpuInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryTopMemInfoTopic_async, OnRspQryTopMemInfoTopic);
    uv_mutex_init (&g_RspQryTopMemInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnTopMemInfoTopic_async, OnRtnTopMemInfoTopic);
    uv_mutex_init (&g_RtnTopMemInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryTopProcessInfoTopic_async, OnRspQryTopProcessInfoTopic);
    uv_mutex_init (&g_RspQryTopProcessInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnTopProcessInfoTopic_async, OnRtnTopProcessInfoTopic);
    uv_mutex_init (&g_RtnTopProcessInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryFileSystemInfoTopic_async, OnRspQryFileSystemInfoTopic);
    uv_mutex_init (&g_RspQryFileSystemInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnFileSystemInfoTopic_async, OnRtnFileSystemInfoTopic);
    uv_mutex_init (&g_RtnFileSystemInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetworkInfoTopic_async, OnRspQryNetworkInfoTopic);
    uv_mutex_init (&g_RspQryNetworkInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetworkInfoTopic_async, OnRtnNetworkInfoTopic);
    uv_mutex_init (&g_RtnNetworkInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryClientLoginTopic_async, OnRspQryClientLoginTopic);
    uv_mutex_init (&g_RspQryClientLoginTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryMonitorObjectTopic_async, OnRspQryMonitorObjectTopic);
    uv_mutex_init (&g_RspQryMonitorObjectTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnMonitorObjectTopic_async, OnRtnMonitorObjectTopic);
    uv_mutex_init (&g_RtnMonitorObjectTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryObjectRationalTopic_async, OnRspQryObjectRationalTopic);
    uv_mutex_init (&g_RspQryObjectRationalTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnObjectRationalTopic_async, OnRtnObjectRationalTopic);
    uv_mutex_init (&g_RtnObjectRationalTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQrySyslogInfoTopic_async, OnRspQrySyslogInfoTopic);
    uv_mutex_init (&g_RspQrySyslogInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnSyslogInfoTopic_async, OnRtnSyslogInfoTopic);
    uv_mutex_init (&g_RtnSyslogInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQrySubscriberTopic_async, OnRspQrySubscriberTopic);
    uv_mutex_init (&g_RspQrySubscriberTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryOidRelationTopic_async, OnRspQryOidRelationTopic);
    uv_mutex_init (&g_RspQryOidRelationTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnOidRelationTopic_async, OnRtnOidRelationTopic);
    uv_mutex_init (&g_RtnOidRelationTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryUserInfoTopic_async, OnRspQryUserInfoTopic);
    uv_mutex_init (&g_RspQryUserInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnUserInfoTopic_async, OnRtnUserInfoTopic);
    uv_mutex_init (&g_RtnUserInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryOnlineUserInfoTopic_async, OnRspQryOnlineUserInfoTopic);
    uv_mutex_init (&g_RspQryOnlineUserInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnOnlineUserInfoTopic_async, OnRtnOnlineUserInfoTopic);
    uv_mutex_init (&g_RtnOnlineUserInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryWarningEventTopic_async, OnRspQryWarningEventTopic);
    uv_mutex_init (&g_RspQryWarningEventTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnWarningEventTopic_async, OnRtnWarningEventTopic);
    uv_mutex_init (&g_RtnWarningEventTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryCPUUsageTopic_async, OnRspQryCPUUsageTopic);
    uv_mutex_init (&g_RspQryCPUUsageTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnCPUUsageTopic_async, OnRtnCPUUsageTopic);
    uv_mutex_init (&g_RtnCPUUsageTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryMemoryUsageTopic_async, OnRspQryMemoryUsageTopic);
    uv_mutex_init (&g_RspQryMemoryUsageTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnMemoryUsageTopic_async, OnRtnMemoryUsageTopic);
    uv_mutex_init (&g_RtnMemoryUsageTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryDiskUsageTopic_async, OnRspQryDiskUsageTopic);
    uv_mutex_init (&g_RspQryDiskUsageTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnDiskUsageTopic_async, OnRtnDiskUsageTopic);
    uv_mutex_init (&g_RtnDiskUsageTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryObjectAttrTopic_async, OnRspQryObjectAttrTopic);
    uv_mutex_init (&g_RspQryObjectAttrTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnObjectAttrTopic_async, OnRtnObjectAttrTopic);
    uv_mutex_init (&g_RtnObjectAttrTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryInvalidateOrderTopic_async, OnRspQryInvalidateOrderTopic);
    uv_mutex_init (&g_RspQryInvalidateOrderTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnInvalidateOrderTopic_async, OnRtnInvalidateOrderTopic);
    uv_mutex_init (&g_RtnInvalidateOrderTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryOrderStatusTopic_async, OnRspQryOrderStatusTopic);
    uv_mutex_init (&g_RspQryOrderStatusTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnOrderStatusTopic_async, OnRtnOrderStatusTopic);
    uv_mutex_init (&g_RtnOrderStatusTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryBargainOrderTopic_async, OnRspQryBargainOrderTopic);
    uv_mutex_init (&g_RspQryBargainOrderTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnBargainOrderTopic_async, OnRtnBargainOrderTopic);
    uv_mutex_init (&g_RtnBargainOrderTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryInstPropertyTopic_async, OnRspQryInstPropertyTopic);
    uv_mutex_init (&g_RspQryInstPropertyTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnInstPropertyTopic_async, OnRtnInstPropertyTopic);
    uv_mutex_init (&g_RtnInstPropertyTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryMarginRateTopic_async, OnRspQryMarginRateTopic);
    uv_mutex_init (&g_RspQryMarginRateTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnMarginRateTopic_async, OnRtnMarginRateTopic);
    uv_mutex_init (&g_RtnMarginRateTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryPriceLimitTopic_async, OnRspQryPriceLimitTopic);
    uv_mutex_init (&g_RspQryPriceLimitTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnPriceLimitTopic_async, OnRtnPriceLimitTopic);
    uv_mutex_init (&g_RtnPriceLimitTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryPartPosiLimitTopic_async, OnRspQryPartPosiLimitTopic);
    uv_mutex_init (&g_RspQryPartPosiLimitTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnPartPosiLimitTopic_async, OnRtnPartPosiLimitTopic);
    uv_mutex_init (&g_RtnPartPosiLimitTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryClientPosiLimitTopic_async, OnRspQryClientPosiLimitTopic);
    uv_mutex_init (&g_RspQryClientPosiLimitTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnClientPosiLimitTopic_async, OnRtnClientPosiLimitTopic);
    uv_mutex_init (&g_RtnClientPosiLimitTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQrySpecialPosiLimitTopic_async, OnRspQrySpecialPosiLimitTopic);
    uv_mutex_init (&g_RspQrySpecialPosiLimitTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnSpecialPosiLimitTopic_async, OnRtnSpecialPosiLimitTopic);
    uv_mutex_init (&g_RtnSpecialPosiLimitTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryTransactionChgTopic_async, OnRspQryTransactionChgTopic);
    uv_mutex_init (&g_RspQryTransactionChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnTransactionChgTopic_async, OnRtnTransactionChgTopic);
    uv_mutex_init (&g_RtnTransactionChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryClientChgTopic_async, OnRspQryClientChgTopic);
    uv_mutex_init (&g_RspQryClientChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnClientChgTopic_async, OnRtnClientChgTopic);
    uv_mutex_init (&g_RtnClientChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryPartClientChgTopic_async, OnRspQryPartClientChgTopic);
    uv_mutex_init (&g_RspQryPartClientChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnPartClientChgTopic_async, OnRtnPartClientChgTopic);
    uv_mutex_init (&g_RtnPartClientChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryPosiLimitChgTopic_async, OnRspQryPosiLimitChgTopic);
    uv_mutex_init (&g_RspQryPosiLimitChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnPosiLimitChgTopic_async, OnRtnPosiLimitChgTopic);
    uv_mutex_init (&g_RtnPosiLimitChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryHedgeDetailChgTopic_async, OnRspQryHedgeDetailChgTopic);
    uv_mutex_init (&g_RspQryHedgeDetailChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnHedgeDetailChgTopic_async, OnRtnHedgeDetailChgTopic);
    uv_mutex_init (&g_RtnHedgeDetailChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryParticipantChgTopic_async, OnRspQryParticipantChgTopic);
    uv_mutex_init (&g_RspQryParticipantChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnParticipantChgTopic_async, OnRtnParticipantChgTopic);
    uv_mutex_init (&g_RtnParticipantChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryMarginRateChgTopic_async, OnRspQryMarginRateChgTopic);
    uv_mutex_init (&g_RspQryMarginRateChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnMarginRateChgTopic_async, OnRtnMarginRateChgTopic);
    uv_mutex_init (&g_RtnMarginRateChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryUserIpChgTopic_async, OnRspQryUserIpChgTopic);
    uv_mutex_init (&g_RspQryUserIpChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnUserIpChgTopic_async, OnRtnUserIpChgTopic);
    uv_mutex_init (&g_RtnUserIpChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryClientPosiLimitChgTopic_async, OnRspQryClientPosiLimitChgTopic);
    uv_mutex_init (&g_RspQryClientPosiLimitChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnClientPosiLimitChgTopic_async, OnRtnClientPosiLimitChgTopic);
    uv_mutex_init (&g_RtnClientPosiLimitChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQrySpecPosiLimitChgTopic_async, OnRspQrySpecPosiLimitChgTopic);
    uv_mutex_init (&g_RspQrySpecPosiLimitChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnSpecPosiLimitChgTopic_async, OnRtnSpecPosiLimitChgTopic);
    uv_mutex_init (&g_RtnSpecPosiLimitChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryHistoryObjectAttrTopic_async, OnRspQryHistoryObjectAttrTopic);
    uv_mutex_init (&g_RspQryHistoryObjectAttrTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnHistoryObjectAttrTopic_async, OnRtnHistoryObjectAttrTopic);
    uv_mutex_init (&g_RtnHistoryObjectAttrTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryFrontInfoTopic_async, OnRspQryFrontInfoTopic);
    uv_mutex_init (&g_RspQryFrontInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnFrontInfoTopic_async, OnRtnFrontInfoTopic);
    uv_mutex_init (&g_RtnFrontInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQrySysUserLoginTopic_async, OnRspQrySysUserLoginTopic);
    uv_mutex_init (&g_RspQrySysUserLoginTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQrySysUserLogoutTopic_async, OnRspQrySysUserLogoutTopic);
    uv_mutex_init (&g_RspQrySysUserLogoutTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQrySysUserPasswordUpdateTopic_async, OnRspQrySysUserPasswordUpdateTopic);
    uv_mutex_init (&g_RspQrySysUserPasswordUpdateTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQrySysUserRegisterTopic_async, OnRspQrySysUserRegisterTopic);
    uv_mutex_init (&g_RspQrySysUserRegisterTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQrySysUserDeleteTopic_async, OnRspQrySysUserDeleteTopic);
    uv_mutex_init (&g_RspQrySysUserDeleteTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryParticipantInitTopic_async, OnRspQryParticipantInitTopic);
    uv_mutex_init (&g_RspQryParticipantInitTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnParticipantInitTopic_async, OnRtnParticipantInitTopic);
    uv_mutex_init (&g_RtnParticipantInitTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryUserInitTopic_async, OnRspQryUserInitTopic);
    uv_mutex_init (&g_RspQryUserInitTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnUserInitTopic_async, OnRtnUserInitTopic);
    uv_mutex_init (&g_RtnUserInitTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryClientInitTopic_async, OnRspQryClientInitTopic);
    uv_mutex_init (&g_RspQryClientInitTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnClientInitTopic_async, OnRtnClientInitTopic);
    uv_mutex_init (&g_RtnClientInitTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryTradeLogTopic_async, OnRspQryTradeLogTopic);
    uv_mutex_init (&g_RspQryTradeLogTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnTradeLogTopic_async, OnRtnTradeLogTopic);
    uv_mutex_init (&g_RtnTradeLogTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryTradeUserLoginInfoTopic_async, OnRspQryTradeUserLoginInfoTopic);
    uv_mutex_init (&g_RspQryTradeUserLoginInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnTradeUserLoginInfoTopic_async, OnRtnTradeUserLoginInfoTopic);
    uv_mutex_init (&g_RtnTradeUserLoginInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryPartTradeTopic_async, OnRspQryPartTradeTopic);
    uv_mutex_init (&g_RspQryPartTradeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryTradepeakTopic_async, OnRspQryTradepeakTopic);
    uv_mutex_init (&g_RspQryTradepeakTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnUpdateSysConfigTopic_async, OnRtnUpdateSysConfigTopic);
    uv_mutex_init (&g_RtnUpdateSysConfigTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnSysUser_async, OnRtnSysUser);
    uv_mutex_init (&g_RtnSysUser_mutex);

    uv_async_init (uv_default_loop(), &g_RtnPriceLimitChgTopic_async, OnRtnPriceLimitChgTopic);
    uv_mutex_init (&g_RtnPriceLimitChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryHistoryCpuInfoTopic_async, OnRspQryHistoryCpuInfoTopic);
    uv_mutex_init (&g_RspQryHistoryCpuInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryHistoryMemInfoTopic_async, OnRspQryHistoryMemInfoTopic);
    uv_mutex_init (&g_RspQryHistoryMemInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryHistoryNetworkInfoTopic_async, OnRspQryHistoryNetworkInfoTopic);
    uv_mutex_init (&g_RspQryHistoryNetworkInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryMonitorOnlineUser_async, OnRspQryMonitorOnlineUser);
    uv_mutex_init (&g_RspQryMonitorOnlineUser_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryFrontStat_async, OnRspQryFrontStat);
    uv_mutex_init (&g_RspQryFrontStat_mutex);

    uv_async_init (uv_default_loop(), &g_RtnSysTimeSyncTopic_async, OnRtnSysTimeSyncTopic);
    uv_mutex_init (&g_RtnSysTimeSyncTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnDataCenterChgTopic_async, OnRtnDataCenterChgTopic);
    uv_mutex_init (&g_RtnDataCenterChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryHistoryTradePeakTopic_async, OnRspQryHistoryTradePeakTopic);
    uv_mutex_init (&g_RspQryHistoryTradePeakTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnHistoryTradePeakTopic_async, OnRtnHistoryTradePeakTopic);
    uv_mutex_init (&g_RtnHistoryTradePeakTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQrySyslogEventTopic_async, OnRspQrySyslogEventTopic);
    uv_mutex_init (&g_RspQrySyslogEventTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnSyslogEventTopic_async, OnRtnSyslogEventTopic);
    uv_mutex_init (&g_RtnSyslogEventTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryTradeDayChangeTopic_async, OnRspQryTradeDayChangeTopic);
    uv_mutex_init (&g_RspQryTradeDayChangeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryWebAppInfoTopic_async, OnRspQryWebAppInfoTopic);
    uv_mutex_init (&g_RspQryWebAppInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnWebAppInfoTopic_async, OnRtnWebAppInfoTopic);
    uv_mutex_init (&g_RtnWebAppInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryServletInfoTopic_async, OnRspQryServletInfoTopic);
    uv_mutex_init (&g_RspQryServletInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnServletInfoTopic_async, OnRtnServletInfoTopic);
    uv_mutex_init (&g_RtnServletInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryFileInfoTopic_async, OnRspQryFileInfoTopic);
    uv_mutex_init (&g_RspQryFileInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnFileInfoTopic_async, OnRtnFileInfoTopic);
    uv_mutex_init (&g_RtnFileInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQrySessionInfoTopic_async, OnRspQrySessionInfoTopic);
    uv_mutex_init (&g_RspQrySessionInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnSessionInfoTopic_async, OnRtnSessionInfoTopic);
    uv_mutex_init (&g_RtnSessionInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryJDBCInfoTopic_async, OnRspQryJDBCInfoTopic);
    uv_mutex_init (&g_RspQryJDBCInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnJDBCInfoTopic_async, OnRtnJDBCInfoTopic);
    uv_mutex_init (&g_RtnJDBCInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryThreadInfoTopic_async, OnRspQryThreadInfoTopic);
    uv_mutex_init (&g_RspQryThreadInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnThreadInfoTopic_async, OnRtnThreadInfoTopic);
    uv_mutex_init (&g_RtnThreadInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryVMInfoTopic_async, OnRspQryVMInfoTopic);
    uv_mutex_init (&g_RspQryVMInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnVMInfoTopic_async, OnRtnVMInfoTopic);
    uv_mutex_init (&g_RtnVMInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryPropertyInfoTopic_async, OnRspQryPropertyInfoTopic);
    uv_mutex_init (&g_RspQryPropertyInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnPropertyInfoTopic_async, OnRtnPropertyInfoTopic);
    uv_mutex_init (&g_RtnPropertyInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryMemPoolInfoTopic_async, OnRspQryMemPoolInfoTopic);
    uv_mutex_init (&g_RspQryMemPoolInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnMemPoolInfoTopic_async, OnRtnMemPoolInfoTopic);
    uv_mutex_init (&g_RtnMemPoolInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryFileContentInfoTopic_async, OnRspQryFileContentInfoTopic);
    uv_mutex_init (&g_RspQryFileContentInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnFileContentInfoTopic_async, OnRtnFileContentInfoTopic);
    uv_mutex_init (&g_RtnFileContentInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryConnectionInfoTopic_async, OnRspQryConnectionInfoTopic);
    uv_mutex_init (&g_RspQryConnectionInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnConnectionInfoTopic_async, OnRtnConnectionInfoTopic);
    uv_mutex_init (&g_RtnConnectionInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryConnectorInfoTopic_async, OnRspQryConnectorInfoTopic);
    uv_mutex_init (&g_RspQryConnectorInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnConnectorInfoTopic_async, OnRtnConnectorInfoTopic);
    uv_mutex_init (&g_RtnConnectorInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryDBQueryTopic_async, OnRspQryDBQueryTopic);
    uv_mutex_init (&g_RspQryDBQueryTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnDBQueryTopic_async, OnRtnDBQueryTopic);
    uv_mutex_init (&g_RtnDBQueryTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryGeneralFieldTopic_async, OnRspQryGeneralFieldTopic);
    uv_mutex_init (&g_RspQryGeneralFieldTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnGeneralFieldTopic_async, OnRtnGeneralFieldTopic);
    uv_mutex_init (&g_RtnGeneralFieldTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryGetFileTopic_async, OnRspQryGetFileTopic);
    uv_mutex_init (&g_RspQryGetFileTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryWarningQueryTopic_async, OnRspQryWarningQueryTopic);
    uv_mutex_init (&g_RspQryWarningQueryTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnWarningQueryTopic_async, OnRtnWarningQueryTopic);
    uv_mutex_init (&g_RtnWarningQueryTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnHostConfig_async, OnRtnHostConfig);
    uv_mutex_init (&g_RtnHostConfig_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryGeneralOperateTopic_async, OnRspQryGeneralOperateTopic);
    uv_mutex_init (&g_RspQryGeneralOperateTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnGeneralOperateTopic_async, OnRtnGeneralOperateTopic);
    uv_mutex_init (&g_RtnGeneralOperateTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetDeviceLinkedTopic_async, OnRspQryNetDeviceLinkedTopic);
    uv_mutex_init (&g_RspQryNetDeviceLinkedTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetDeviceLinkedTopic_async, OnRtnNetDeviceLinkedTopic);
    uv_mutex_init (&g_RtnNetDeviceLinkedTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryTradeUserLoginStatTopic_async, OnRspQryTradeUserLoginStatTopic);
    uv_mutex_init (&g_RspQryTradeUserLoginStatTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryTradeFrontOrderRttStatTopic_async, OnRspQryTradeFrontOrderRttStatTopic);
    uv_mutex_init (&g_RspQryTradeFrontOrderRttStatTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnTradeFrontOrderRttStatTopic_async, OnRtnTradeFrontOrderRttStatTopic);
    uv_mutex_init (&g_RtnTradeFrontOrderRttStatTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryParticTradeOrderStatesTopic_async, OnRspQryParticTradeOrderStatesTopic);
    uv_mutex_init (&g_RspQryParticTradeOrderStatesTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnParticTradeOrderStatesTopic_async, OnRtnParticTradeOrderStatesTopic);
    uv_mutex_init (&g_RtnParticTradeOrderStatesTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryRouterInfoTopic_async, OnRspQryRouterInfoTopic);
    uv_mutex_init (&g_RspQryRouterInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnRouterInfoTopic_async, OnRtnRouterInfoTopic);
    uv_mutex_init (&g_RtnRouterInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryDiskIOTopic_async, OnRspQryDiskIOTopic);
    uv_mutex_init (&g_RspQryDiskIOTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnDiskIOTopic_async, OnRtnDiskIOTopic);
    uv_mutex_init (&g_RtnDiskIOTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryStatInfoTopic_async, OnRspQryStatInfoTopic);
    uv_mutex_init (&g_RspQryStatInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnStatInfoTopic_async, OnRtnStatInfoTopic);
    uv_mutex_init (&g_RtnStatInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryTradeOrderRttCutLineTopic_async, OnRspQryTradeOrderRttCutLineTopic);
    uv_mutex_init (&g_RspQryTradeOrderRttCutLineTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnTradeOrderRttCutLineTopic_async, OnRtnTradeOrderRttCutLineTopic);
    uv_mutex_init (&g_RtnTradeOrderRttCutLineTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryClientInfoTopic_async, OnRspQryClientInfoTopic);
    uv_mutex_init (&g_RspQryClientInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnClientInfoTopic_async, OnRtnClientInfoTopic);
    uv_mutex_init (&g_RtnClientInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryEventDescriptionTopic_async, OnRspQryEventDescriptionTopic);
    uv_mutex_init (&g_RspQryEventDescriptionTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnEventDescriptionTopic_async, OnRtnEventDescriptionTopic);
    uv_mutex_init (&g_RtnEventDescriptionTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryFrontUniqueIDTopic_async, OnRspQryFrontUniqueIDTopic);
    uv_mutex_init (&g_RspQryFrontUniqueIDTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnFrontUniqueIDTopic_async, OnRtnFrontUniqueIDTopic);
    uv_mutex_init (&g_RtnFrontUniqueIDTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetPartyLinkAddrChangeTopic_async, OnRspQryNetPartyLinkAddrChangeTopic);
    uv_mutex_init (&g_RspQryNetPartyLinkAddrChangeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetPartyLinkAddrChangeTopic_async, OnRtnNetPartyLinkAddrChangeTopic);
    uv_mutex_init (&g_RtnNetPartyLinkAddrChangeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetDelPartyLinkInfoTopic_async, OnRspQryNetDelPartyLinkInfoTopic);
    uv_mutex_init (&g_RspQryNetDelPartyLinkInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetDelPartyLinkInfoTopic_async, OnRtnNetDelPartyLinkInfoTopic);
    uv_mutex_init (&g_RtnNetDelPartyLinkInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryPerformanceTopTopic_async, OnRspQryPerformanceTopTopic);
    uv_mutex_init (&g_RspQryPerformanceTopTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnPerformanceTopTopic_async, OnRtnPerformanceTopTopic);
    uv_mutex_init (&g_RtnPerformanceTopTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryInstrumentStatusTopic_async, OnRspQryInstrumentStatusTopic);
    uv_mutex_init (&g_RspQryInstrumentStatusTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnInstrumentStatusTopic_async, OnRtnInstrumentStatusTopic);
    uv_mutex_init (&g_RtnInstrumentStatusTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryCurrTradingSegmentAttrTopic_async, OnRspQryCurrTradingSegmentAttrTopic);
    uv_mutex_init (&g_RspQryCurrTradingSegmentAttrTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnCurrTradingSegmentAttrTopic_async, OnRtnCurrTradingSegmentAttrTopic);
    uv_mutex_init (&g_RtnCurrTradingSegmentAttrTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetAreaTopic_async, OnRspQryNetAreaTopic);
    uv_mutex_init (&g_RspQryNetAreaTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetAreaTopic_async, OnRtnNetAreaTopic);
    uv_mutex_init (&g_RtnNetAreaTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetSubAreaTopic_async, OnRspQryNetSubAreaTopic);
    uv_mutex_init (&g_RspQryNetSubAreaTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetSubAreaTopic_async, OnRtnNetSubAreaTopic);
    uv_mutex_init (&g_RtnNetSubAreaTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetSubAreaIPTopic_async, OnRspQryNetSubAreaIPTopic);
    uv_mutex_init (&g_RspQryNetSubAreaIPTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetSubAreaIPTopic_async, OnRtnNetSubAreaIPTopic);
    uv_mutex_init (&g_RtnNetSubAreaIPTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetDeviceTopic_async, OnRspQryNetDeviceTopic);
    uv_mutex_init (&g_RspQryNetDeviceTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetDeviceTopic_async, OnRtnNetDeviceTopic);
    uv_mutex_init (&g_RtnNetDeviceTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetDeviceDetectTopic_async, OnRspQryNetDeviceDetectTopic);
    uv_mutex_init (&g_RspQryNetDeviceDetectTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetBuildingTopic_async, OnRspQryNetBuildingTopic);
    uv_mutex_init (&g_RspQryNetBuildingTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetBuildingTopic_async, OnRtnNetBuildingTopic);
    uv_mutex_init (&g_RtnNetBuildingTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetRoomTopic_async, OnRspQryNetRoomTopic);
    uv_mutex_init (&g_RspQryNetRoomTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetRoomTopic_async, OnRtnNetRoomTopic);
    uv_mutex_init (&g_RtnNetRoomTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetCabinetsTopic_async, OnRspQryNetCabinetsTopic);
    uv_mutex_init (&g_RspQryNetCabinetsTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetCabinetsTopic_async, OnRtnNetCabinetsTopic);
    uv_mutex_init (&g_RtnNetCabinetsTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetOIDTopic_async, OnRspQryNetOIDTopic);
    uv_mutex_init (&g_RspQryNetOIDTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetOIDTopic_async, OnRtnNetOIDTopic);
    uv_mutex_init (&g_RtnNetOIDTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetTimePolicyTopic_async, OnRspQryNetTimePolicyTopic);
    uv_mutex_init (&g_RspQryNetTimePolicyTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetTimePolicyTopic_async, OnRtnNetTimePolicyTopic);
    uv_mutex_init (&g_RtnNetTimePolicyTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetGatherTaskTopic_async, OnRspQryNetGatherTaskTopic);
    uv_mutex_init (&g_RspQryNetGatherTaskTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetGatherTaskTopic_async, OnRtnNetGatherTaskTopic);
    uv_mutex_init (&g_RtnNetGatherTaskTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetDeviceChgTopic_async, OnRspQryNetDeviceChgTopic);
    uv_mutex_init (&g_RspQryNetDeviceChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetDeviceChgTopic_async, OnRtnNetDeviceChgTopic);
    uv_mutex_init (&g_RtnNetDeviceChgTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetDeviceTypeTopic_async, OnRspQryNetDeviceTypeTopic);
    uv_mutex_init (&g_RspQryNetDeviceTypeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetDeviceTypeTopic_async, OnRtnNetDeviceTypeTopic);
    uv_mutex_init (&g_RtnNetDeviceTypeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetDeviceCategoryTopic_async, OnRspQryNetDeviceCategoryTopic);
    uv_mutex_init (&g_RspQryNetDeviceCategoryTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetDeviceCategoryTopic_async, OnRtnNetDeviceCategoryTopic);
    uv_mutex_init (&g_RtnNetDeviceCategoryTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetManufactoryTopic_async, OnRspQryNetManufactoryTopic);
    uv_mutex_init (&g_RspQryNetManufactoryTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetManufactoryTopic_async, OnRtnNetManufactoryTopic);
    uv_mutex_init (&g_RtnNetManufactoryTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetCommunityTopic_async, OnRspQryNetCommunityTopic);
    uv_mutex_init (&g_RspQryNetCommunityTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetCommunityTopic_async, OnRtnNetCommunityTopic);
    uv_mutex_init (&g_RtnNetCommunityTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetPortTypeTopic_async, OnRspQryNetPortTypeTopic);
    uv_mutex_init (&g_RspQryNetPortTypeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetPortTypeTopic_async, OnRtnNetPortTypeTopic);
    uv_mutex_init (&g_RtnNetPortTypeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetPartAccessSpotTopic_async, OnRspQryNetPartAccessSpotTopic);
    uv_mutex_init (&g_RspQryNetPartAccessSpotTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetPartAccessSpotTopic_async, OnRtnNetPartAccessSpotTopic);
    uv_mutex_init (&g_RtnNetPartAccessSpotTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetInterfaceTopic_async, OnRspQryNetInterfaceTopic);
    uv_mutex_init (&g_RspQryNetInterfaceTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetInterfaceTopic_async, OnRtnNetInterfaceTopic);
    uv_mutex_init (&g_RtnNetInterfaceTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetGeneralOIDTopic_async, OnRspQryNetGeneralOIDTopic);
    uv_mutex_init (&g_RspQryNetGeneralOIDTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetGeneralOIDTopic_async, OnRtnNetGeneralOIDTopic);
    uv_mutex_init (&g_RtnNetGeneralOIDTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorTypeTopic_async, OnRspQryNetMonitorTypeTopic);
    uv_mutex_init (&g_RspQryNetMonitorTypeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorTypeTopic_async, OnRtnNetMonitorTypeTopic);
    uv_mutex_init (&g_RtnNetMonitorTypeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorAttrScopeTopic_async, OnRspQryNetMonitorAttrScopeTopic);
    uv_mutex_init (&g_RspQryNetMonitorAttrScopeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorAttrScopeTopic_async, OnRtnNetMonitorAttrScopeTopic);
    uv_mutex_init (&g_RtnNetMonitorAttrScopeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorAttrTypeTopic_async, OnRspQryNetMonitorAttrTypeTopic);
    uv_mutex_init (&g_RspQryNetMonitorAttrTypeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorAttrTypeTopic_async, OnRtnNetMonitorAttrTypeTopic);
    uv_mutex_init (&g_RtnNetMonitorAttrTypeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorObjectAttrTopic_async, OnRspQryNetMonitorObjectAttrTopic);
    uv_mutex_init (&g_RspQryNetMonitorObjectAttrTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorObjectAttrTopic_async, OnRtnNetMonitorObjectAttrTopic);
    uv_mutex_init (&g_RtnNetMonitorObjectAttrTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetFuncAreaTopic_async, OnRspQryNetFuncAreaTopic);
    uv_mutex_init (&g_RspQryNetFuncAreaTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetFuncAreaTopic_async, OnRtnNetFuncAreaTopic);
    uv_mutex_init (&g_RtnNetFuncAreaTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorCommandTypeTopic_async, OnRspQryNetMonitorCommandTypeTopic);
    uv_mutex_init (&g_RspQryNetMonitorCommandTypeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorCommandTypeTopic_async, OnRtnNetMonitorCommandTypeTopic);
    uv_mutex_init (&g_RtnNetMonitorCommandTypeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorActionGroupTopic_async, OnRspQryNetMonitorActionGroupTopic);
    uv_mutex_init (&g_RspQryNetMonitorActionGroupTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorActionGroupTopic_async, OnRtnNetMonitorActionGroupTopic);
    uv_mutex_init (&g_RtnNetMonitorActionGroupTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorDeviceGroupTopic_async, OnRspQryNetMonitorDeviceGroupTopic);
    uv_mutex_init (&g_RspQryNetMonitorDeviceGroupTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorDeviceGroupTopic_async, OnRtnNetMonitorDeviceGroupTopic);
    uv_mutex_init (&g_RtnNetMonitorDeviceGroupTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorTaskInfoTopic_async, OnRspQryNetMonitorTaskInfoTopic);
    uv_mutex_init (&g_RspQryNetMonitorTaskInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorTaskInfoTopic_async, OnRtnNetMonitorTaskInfoTopic);
    uv_mutex_init (&g_RtnNetMonitorTaskInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorTaskResultTopic_async, OnRspQryNetMonitorTaskResultTopic);
    uv_mutex_init (&g_RspQryNetMonitorTaskResultTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorTaskResultTopic_async, OnRtnNetMonitorTaskResultTopic);
    uv_mutex_init (&g_RtnNetMonitorTaskResultTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorTaskObjectSetTopic_async, OnRspQryNetMonitorTaskObjectSetTopic);
    uv_mutex_init (&g_RspQryNetMonitorTaskObjectSetTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorTaskObjectSetTopic_async, OnRtnNetMonitorTaskObjectSetTopic);
    uv_mutex_init (&g_RtnNetMonitorTaskObjectSetTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetPartyLinkInfoTopic_async, OnRspQryNetPartyLinkInfoTopic);
    uv_mutex_init (&g_RspQryNetPartyLinkInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetPartyLinkInfoTopic_async, OnRtnNetPartyLinkInfoTopic);
    uv_mutex_init (&g_RtnNetPartyLinkInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorActionAttrTopic_async, OnRspQryNetMonitorActionAttrTopic);
    uv_mutex_init (&g_RspQryNetMonitorActionAttrTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorActionAttrTopic_async, OnRtnNetMonitorActionAttrTopic);
    uv_mutex_init (&g_RtnNetMonitorActionAttrTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetModuleTopic_async, OnRspQryNetModuleTopic);
    uv_mutex_init (&g_RspQryNetModuleTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetModuleTopic_async, OnRtnNetModuleTopic);
    uv_mutex_init (&g_RtnNetModuleTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetEventExprTopic_async, OnRspQryNetEventExprTopic);
    uv_mutex_init (&g_RspQryNetEventExprTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetEventExprTopic_async, OnRtnNetEventExprTopic);
    uv_mutex_init (&g_RtnNetEventExprTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetEventTypeTopic_async, OnRspQryNetEventTypeTopic);
    uv_mutex_init (&g_RspQryNetEventTypeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetEventTypeTopic_async, OnRtnNetEventTypeTopic);
    uv_mutex_init (&g_RtnNetEventTypeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetSubEventTypeTopic_async, OnRspQryNetSubEventTypeTopic);
    uv_mutex_init (&g_RspQryNetSubEventTypeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetSubEventTypeTopic_async, OnRtnNetSubEventTypeTopic);
    uv_mutex_init (&g_RtnNetSubEventTypeTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetEventLevelTopic_async, OnRspQryNetEventLevelTopic);
    uv_mutex_init (&g_RspQryNetEventLevelTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetEventLevelTopic_async, OnRtnNetEventLevelTopic);
    uv_mutex_init (&g_RtnNetEventLevelTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorTaskStatusResultTopic_async, OnRspQryNetMonitorTaskStatusResultTopic);
    uv_mutex_init (&g_RspQryNetMonitorTaskStatusResultTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorTaskStatusResultTopic_async, OnRtnNetMonitorTaskStatusResultTopic);
    uv_mutex_init (&g_RtnNetMonitorTaskStatusResultTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetCfgFileTopic_async, OnRspQryNetCfgFileTopic);
    uv_mutex_init (&g_RspQryNetCfgFileTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetCfgFileTopic_async, OnRtnNetCfgFileTopic);
    uv_mutex_init (&g_RtnNetCfgFileTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorDeviceTaskTopic_async, OnRspQryNetMonitorDeviceTaskTopic);
    uv_mutex_init (&g_RspQryNetMonitorDeviceTaskTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorDeviceTaskTopic_async, OnRtnNetMonitorDeviceTaskTopic);
    uv_mutex_init (&g_RtnNetMonitorDeviceTaskTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorTaskInstAttrsTopic_async, OnRspQryNetMonitorTaskInstAttrsTopic);
    uv_mutex_init (&g_RspQryNetMonitorTaskInstAttrsTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorTaskInstAttrsTopic_async, OnRtnNetMonitorTaskInstAttrsTopic);
    uv_mutex_init (&g_RtnNetMonitorTaskInstAttrsTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryFileGeneralOperTopic_async, OnRspQryFileGeneralOperTopic);
    uv_mutex_init (&g_RspQryFileGeneralOperTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnFileGeneralOperTopic_async, OnRtnFileGeneralOperTopic);
    uv_mutex_init (&g_RtnFileGeneralOperTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetBaseLineTopic_async, OnRspQryNetBaseLineTopic);
    uv_mutex_init (&g_RspQryNetBaseLineTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetBaseLineTopic_async, OnRtnNetBaseLineTopic);
    uv_mutex_init (&g_RtnNetBaseLineTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetBaseLineTaskTopic_async, OnRspQryNetBaseLineTaskTopic);
    uv_mutex_init (&g_RspQryNetBaseLineTaskTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetBaseLineTaskTopic_async, OnRtnNetBaseLineTaskTopic);
    uv_mutex_init (&g_RtnNetBaseLineTaskTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetBaseLineResultTopic_async, OnRspQryNetBaseLineResultTopic);
    uv_mutex_init (&g_RspQryNetBaseLineResultTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetBaseLineResultTopic_async, OnRtnNetBaseLineResultTopic);
    uv_mutex_init (&g_RtnNetBaseLineResultTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetPartyLinkStatusInfoTopic_async, OnRspQryNetPartyLinkStatusInfoTopic);
    uv_mutex_init (&g_RspQryNetPartyLinkStatusInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetPartyLinkStatusInfoTopic_async, OnRtnNetPartyLinkStatusInfoTopic);
    uv_mutex_init (&g_RtnNetPartyLinkStatusInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetMemberSDHLineInfoTopic_async, OnRspQryNetMemberSDHLineInfoTopic);
    uv_mutex_init (&g_RspQryNetMemberSDHLineInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetMemberSDHLineInfoTopic_async, OnRtnNetMemberSDHLineInfoTopic);
    uv_mutex_init (&g_RtnNetMemberSDHLineInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetDDNLinkInfoTopic_async, OnRspQryNetDDNLinkInfoTopic);
    uv_mutex_init (&g_RspQryNetDDNLinkInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetDDNLinkInfoTopic_async, OnRtnNetDDNLinkInfoTopic);
    uv_mutex_init (&g_RtnNetDDNLinkInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetPseudMemberLinkInfoTopic_async, OnRspQryNetPseudMemberLinkInfoTopic);
    uv_mutex_init (&g_RspQryNetPseudMemberLinkInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetPseudMemberLinkInfoTopic_async, OnRtnNetPseudMemberLinkInfoTopic);
    uv_mutex_init (&g_RtnNetPseudMemberLinkInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryOuterDeviceInfTopic_async, OnRspQryOuterDeviceInfTopic);
    uv_mutex_init (&g_RspQryOuterDeviceInfTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetOuterDeviceInfTopic_async, OnRtnNetOuterDeviceInfTopic);
    uv_mutex_init (&g_RtnNetOuterDeviceInfTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetLocalPingResultInfoTopic_async, OnRspQryNetLocalPingResultInfoTopic);
    uv_mutex_init (&g_RspQryNetLocalPingResultInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetLocalPingResultInfoTopic_async, OnRtnNetLocalPingResultInfoTopic);
    uv_mutex_init (&g_RtnNetLocalPingResultInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetRomotePingResultInfoTopic_async, OnRspQryNetRomotePingResultInfoTopic);
    uv_mutex_init (&g_RspQryNetRomotePingResultInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetRomotePingResultInfoTopic_async, OnRtnNetRomotePingResultInfoTopic);
    uv_mutex_init (&g_RtnNetRomotePingResultInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnMonitorTopProcessInfo_async, OnRtnMonitorTopProcessInfo);
    uv_mutex_init (&g_RtnMonitorTopProcessInfo_mutex);

    uv_async_init (uv_default_loop(), &g_RspQrySysInternalTopologyTopic_async, OnRspQrySysInternalTopologyTopic);
    uv_mutex_init (&g_RspQrySysInternalTopologyTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnSysInternalTopologyTopic_async, OnRtnSysInternalTopologyTopic);
    uv_mutex_init (&g_RtnSysInternalTopologyTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryMemberLinkCostTopic_async, OnRspQryMemberLinkCostTopic);
    uv_mutex_init (&g_RspQryMemberLinkCostTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnMemberLinkCostTopic_async, OnRtnMemberLinkCostTopic);
    uv_mutex_init (&g_RtnMemberLinkCostTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetPartylinkMonthlyRentTopic_async, OnRspQryNetPartylinkMonthlyRentTopic);
    uv_mutex_init (&g_RspQryNetPartylinkMonthlyRentTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetPartylinkMonthlyRentTopic_async, OnRtnNetPartylinkMonthlyRentTopic);
    uv_mutex_init (&g_RtnNetPartylinkMonthlyRentTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RspQryNetNonPartyLinkInfoTopic_async, OnRspQryNetNonPartyLinkInfoTopic);
    uv_mutex_init (&g_RspQryNetNonPartyLinkInfoTopic_mutex);

    uv_async_init (uv_default_loop(), &g_RtnNetNonPartyLinkInfoTopic_async, OnRtnNetNonPartyLinkInfoTopic);
    uv_mutex_init (&g_RtnNetNonPartyLinkInfoTopic_mutex);

};

NODE_MODULE (addon, InitAll);