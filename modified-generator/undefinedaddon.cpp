
#include <nan.h>
#include "FtdcSysUserApi_Wrapper.h"
#include "spi-transform.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
        
    FtdcSysUserApi_Wrapper::InitExports (exports);
   
    uv_async_init (uv_default_loop(), &g_async, print_progress);
    
    uv_async_init (uv_default_loop(), &g_FrontDisconnected_async, OnFrontDisconnected);
    uv_mutex_init (g_FrontDisconnected_mutex);
    
    uv_async_init (uv_default_loop(), &g_HeartBeatWarning_async, OnHeartBeatWarning);
    uv_mutex_init (g_HeartBeatWarning_mutex);
   
    // 以下为自动生成
    uv_async_init (uv_default_loop(), &g_RspQryTopCpuInfoTopic_async);
    uv_mutex_init (&g_RspQryTopCpuInfoTopic_mutex, OnRspQryTopCpuInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnTopCpuInfoTopic_async);
    uv_mutex_init (&g_RtnTopCpuInfoTopic_mutex, OnRtnTopCpuInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryTopMemInfoTopic_async);
    uv_mutex_init (&g_RspQryTopMemInfoTopic_mutex, OnRspQryTopMemInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnTopMemInfoTopic_async);
    uv_mutex_init (&g_RtnTopMemInfoTopic_mutex, OnRtnTopMemInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryTopProcessInfoTopic_async);
    uv_mutex_init (&g_RspQryTopProcessInfoTopic_mutex, OnRspQryTopProcessInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnTopProcessInfoTopic_async);
    uv_mutex_init (&g_RtnTopProcessInfoTopic_mutex, OnRtnTopProcessInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryFileSystemInfoTopic_async);
    uv_mutex_init (&g_RspQryFileSystemInfoTopic_mutex, OnRspQryFileSystemInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnFileSystemInfoTopic_async);
    uv_mutex_init (&g_RtnFileSystemInfoTopic_mutex, OnRtnFileSystemInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetworkInfoTopic_async);
    uv_mutex_init (&g_RspQryNetworkInfoTopic_mutex, OnRspQryNetworkInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetworkInfoTopic_async);
    uv_mutex_init (&g_RtnNetworkInfoTopic_mutex, OnRtnNetworkInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryClientLoginTopic_async);
    uv_mutex_init (&g_RspQryClientLoginTopic_mutex, OnRspQryClientLoginTopic);

    uv_async_init (uv_default_loop(), &g_RspQryMonitorObjectTopic_async);
    uv_mutex_init (&g_RspQryMonitorObjectTopic_mutex, OnRspQryMonitorObjectTopic);

    uv_async_init (uv_default_loop(), &g_RtnMonitorObjectTopic_async);
    uv_mutex_init (&g_RtnMonitorObjectTopic_mutex, OnRtnMonitorObjectTopic);

    uv_async_init (uv_default_loop(), &g_RspQryObjectRationalTopic_async);
    uv_mutex_init (&g_RspQryObjectRationalTopic_mutex, OnRspQryObjectRationalTopic);

    uv_async_init (uv_default_loop(), &g_RtnObjectRationalTopic_async);
    uv_mutex_init (&g_RtnObjectRationalTopic_mutex, OnRtnObjectRationalTopic);

    uv_async_init (uv_default_loop(), &g_RspQrySyslogInfoTopic_async);
    uv_mutex_init (&g_RspQrySyslogInfoTopic_mutex, OnRspQrySyslogInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnSyslogInfoTopic_async);
    uv_mutex_init (&g_RtnSyslogInfoTopic_mutex, OnRtnSyslogInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQrySubscriberTopic_async);
    uv_mutex_init (&g_RspQrySubscriberTopic_mutex, OnRspQrySubscriberTopic);

    uv_async_init (uv_default_loop(), &g_RspQryOidRelationTopic_async);
    uv_mutex_init (&g_RspQryOidRelationTopic_mutex, OnRspQryOidRelationTopic);

    uv_async_init (uv_default_loop(), &g_RtnOidRelationTopic_async);
    uv_mutex_init (&g_RtnOidRelationTopic_mutex, OnRtnOidRelationTopic);

    uv_async_init (uv_default_loop(), &g_RspQryUserInfoTopic_async);
    uv_mutex_init (&g_RspQryUserInfoTopic_mutex, OnRspQryUserInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnUserInfoTopic_async);
    uv_mutex_init (&g_RtnUserInfoTopic_mutex, OnRtnUserInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryOnlineUserInfoTopic_async);
    uv_mutex_init (&g_RspQryOnlineUserInfoTopic_mutex, OnRspQryOnlineUserInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnOnlineUserInfoTopic_async);
    uv_mutex_init (&g_RtnOnlineUserInfoTopic_mutex, OnRtnOnlineUserInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryWarningEventTopic_async);
    uv_mutex_init (&g_RspQryWarningEventTopic_mutex, OnRspQryWarningEventTopic);

    uv_async_init (uv_default_loop(), &g_RtnWarningEventTopic_async);
    uv_mutex_init (&g_RtnWarningEventTopic_mutex, OnRtnWarningEventTopic);

    uv_async_init (uv_default_loop(), &g_RspQryCPUUsageTopic_async);
    uv_mutex_init (&g_RspQryCPUUsageTopic_mutex, OnRspQryCPUUsageTopic);

    uv_async_init (uv_default_loop(), &g_RtnCPUUsageTopic_async);
    uv_mutex_init (&g_RtnCPUUsageTopic_mutex, OnRtnCPUUsageTopic);

    uv_async_init (uv_default_loop(), &g_RspQryMemoryUsageTopic_async);
    uv_mutex_init (&g_RspQryMemoryUsageTopic_mutex, OnRspQryMemoryUsageTopic);

    uv_async_init (uv_default_loop(), &g_RtnMemoryUsageTopic_async);
    uv_mutex_init (&g_RtnMemoryUsageTopic_mutex, OnRtnMemoryUsageTopic);

    uv_async_init (uv_default_loop(), &g_RspQryDiskUsageTopic_async);
    uv_mutex_init (&g_RspQryDiskUsageTopic_mutex, OnRspQryDiskUsageTopic);

    uv_async_init (uv_default_loop(), &g_RtnDiskUsageTopic_async);
    uv_mutex_init (&g_RtnDiskUsageTopic_mutex, OnRtnDiskUsageTopic);

    uv_async_init (uv_default_loop(), &g_RspQryObjectAttrTopic_async);
    uv_mutex_init (&g_RspQryObjectAttrTopic_mutex, OnRspQryObjectAttrTopic);

    uv_async_init (uv_default_loop(), &g_RtnObjectAttrTopic_async);
    uv_mutex_init (&g_RtnObjectAttrTopic_mutex, OnRtnObjectAttrTopic);

    uv_async_init (uv_default_loop(), &g_RspQryInvalidateOrderTopic_async);
    uv_mutex_init (&g_RspQryInvalidateOrderTopic_mutex, OnRspQryInvalidateOrderTopic);

    uv_async_init (uv_default_loop(), &g_RtnInvalidateOrderTopic_async);
    uv_mutex_init (&g_RtnInvalidateOrderTopic_mutex, OnRtnInvalidateOrderTopic);

    uv_async_init (uv_default_loop(), &g_RspQryOrderStatusTopic_async);
    uv_mutex_init (&g_RspQryOrderStatusTopic_mutex, OnRspQryOrderStatusTopic);

    uv_async_init (uv_default_loop(), &g_RtnOrderStatusTopic_async);
    uv_mutex_init (&g_RtnOrderStatusTopic_mutex, OnRtnOrderStatusTopic);

    uv_async_init (uv_default_loop(), &g_RspQryBargainOrderTopic_async);
    uv_mutex_init (&g_RspQryBargainOrderTopic_mutex, OnRspQryBargainOrderTopic);

    uv_async_init (uv_default_loop(), &g_RtnBargainOrderTopic_async);
    uv_mutex_init (&g_RtnBargainOrderTopic_mutex, OnRtnBargainOrderTopic);

    uv_async_init (uv_default_loop(), &g_RspQryInstPropertyTopic_async);
    uv_mutex_init (&g_RspQryInstPropertyTopic_mutex, OnRspQryInstPropertyTopic);

    uv_async_init (uv_default_loop(), &g_RtnInstPropertyTopic_async);
    uv_mutex_init (&g_RtnInstPropertyTopic_mutex, OnRtnInstPropertyTopic);

    uv_async_init (uv_default_loop(), &g_RspQryMarginRateTopic_async);
    uv_mutex_init (&g_RspQryMarginRateTopic_mutex, OnRspQryMarginRateTopic);

    uv_async_init (uv_default_loop(), &g_RtnMarginRateTopic_async);
    uv_mutex_init (&g_RtnMarginRateTopic_mutex, OnRtnMarginRateTopic);

    uv_async_init (uv_default_loop(), &g_RspQryPriceLimitTopic_async);
    uv_mutex_init (&g_RspQryPriceLimitTopic_mutex, OnRspQryPriceLimitTopic);

    uv_async_init (uv_default_loop(), &g_RtnPriceLimitTopic_async);
    uv_mutex_init (&g_RtnPriceLimitTopic_mutex, OnRtnPriceLimitTopic);

    uv_async_init (uv_default_loop(), &g_RspQryPartPosiLimitTopic_async);
    uv_mutex_init (&g_RspQryPartPosiLimitTopic_mutex, OnRspQryPartPosiLimitTopic);

    uv_async_init (uv_default_loop(), &g_RtnPartPosiLimitTopic_async);
    uv_mutex_init (&g_RtnPartPosiLimitTopic_mutex, OnRtnPartPosiLimitTopic);

    uv_async_init (uv_default_loop(), &g_RspQryClientPosiLimitTopic_async);
    uv_mutex_init (&g_RspQryClientPosiLimitTopic_mutex, OnRspQryClientPosiLimitTopic);

    uv_async_init (uv_default_loop(), &g_RtnClientPosiLimitTopic_async);
    uv_mutex_init (&g_RtnClientPosiLimitTopic_mutex, OnRtnClientPosiLimitTopic);

    uv_async_init (uv_default_loop(), &g_RspQrySpecialPosiLimitTopic_async);
    uv_mutex_init (&g_RspQrySpecialPosiLimitTopic_mutex, OnRspQrySpecialPosiLimitTopic);

    uv_async_init (uv_default_loop(), &g_RtnSpecialPosiLimitTopic_async);
    uv_mutex_init (&g_RtnSpecialPosiLimitTopic_mutex, OnRtnSpecialPosiLimitTopic);

    uv_async_init (uv_default_loop(), &g_RspQryTransactionChgTopic_async);
    uv_mutex_init (&g_RspQryTransactionChgTopic_mutex, OnRspQryTransactionChgTopic);

    uv_async_init (uv_default_loop(), &g_RtnTransactionChgTopic_async);
    uv_mutex_init (&g_RtnTransactionChgTopic_mutex, OnRtnTransactionChgTopic);

    uv_async_init (uv_default_loop(), &g_RspQryClientChgTopic_async);
    uv_mutex_init (&g_RspQryClientChgTopic_mutex, OnRspQryClientChgTopic);

    uv_async_init (uv_default_loop(), &g_RtnClientChgTopic_async);
    uv_mutex_init (&g_RtnClientChgTopic_mutex, OnRtnClientChgTopic);

    uv_async_init (uv_default_loop(), &g_RspQryPartClientChgTopic_async);
    uv_mutex_init (&g_RspQryPartClientChgTopic_mutex, OnRspQryPartClientChgTopic);

    uv_async_init (uv_default_loop(), &g_RtnPartClientChgTopic_async);
    uv_mutex_init (&g_RtnPartClientChgTopic_mutex, OnRtnPartClientChgTopic);

    uv_async_init (uv_default_loop(), &g_RspQryPosiLimitChgTopic_async);
    uv_mutex_init (&g_RspQryPosiLimitChgTopic_mutex, OnRspQryPosiLimitChgTopic);

    uv_async_init (uv_default_loop(), &g_RtnPosiLimitChgTopic_async);
    uv_mutex_init (&g_RtnPosiLimitChgTopic_mutex, OnRtnPosiLimitChgTopic);

    uv_async_init (uv_default_loop(), &g_RspQryHedgeDetailChgTopic_async);
    uv_mutex_init (&g_RspQryHedgeDetailChgTopic_mutex, OnRspQryHedgeDetailChgTopic);

    uv_async_init (uv_default_loop(), &g_RtnHedgeDetailChgTopic_async);
    uv_mutex_init (&g_RtnHedgeDetailChgTopic_mutex, OnRtnHedgeDetailChgTopic);

    uv_async_init (uv_default_loop(), &g_RspQryParticipantChgTopic_async);
    uv_mutex_init (&g_RspQryParticipantChgTopic_mutex, OnRspQryParticipantChgTopic);

    uv_async_init (uv_default_loop(), &g_RtnParticipantChgTopic_async);
    uv_mutex_init (&g_RtnParticipantChgTopic_mutex, OnRtnParticipantChgTopic);

    uv_async_init (uv_default_loop(), &g_RspQryMarginRateChgTopic_async);
    uv_mutex_init (&g_RspQryMarginRateChgTopic_mutex, OnRspQryMarginRateChgTopic);

    uv_async_init (uv_default_loop(), &g_RtnMarginRateChgTopic_async);
    uv_mutex_init (&g_RtnMarginRateChgTopic_mutex, OnRtnMarginRateChgTopic);

    uv_async_init (uv_default_loop(), &g_RspQryUserIpChgTopic_async);
    uv_mutex_init (&g_RspQryUserIpChgTopic_mutex, OnRspQryUserIpChgTopic);

    uv_async_init (uv_default_loop(), &g_RtnUserIpChgTopic_async);
    uv_mutex_init (&g_RtnUserIpChgTopic_mutex, OnRtnUserIpChgTopic);

    uv_async_init (uv_default_loop(), &g_RspQryClientPosiLimitChgTopic_async);
    uv_mutex_init (&g_RspQryClientPosiLimitChgTopic_mutex, OnRspQryClientPosiLimitChgTopic);

    uv_async_init (uv_default_loop(), &g_RtnClientPosiLimitChgTopic_async);
    uv_mutex_init (&g_RtnClientPosiLimitChgTopic_mutex, OnRtnClientPosiLimitChgTopic);

    uv_async_init (uv_default_loop(), &g_RspQrySpecPosiLimitChgTopic_async);
    uv_mutex_init (&g_RspQrySpecPosiLimitChgTopic_mutex, OnRspQrySpecPosiLimitChgTopic);

    uv_async_init (uv_default_loop(), &g_RtnSpecPosiLimitChgTopic_async);
    uv_mutex_init (&g_RtnSpecPosiLimitChgTopic_mutex, OnRtnSpecPosiLimitChgTopic);

    uv_async_init (uv_default_loop(), &g_RspQryHistoryObjectAttrTopic_async);
    uv_mutex_init (&g_RspQryHistoryObjectAttrTopic_mutex, OnRspQryHistoryObjectAttrTopic);

    uv_async_init (uv_default_loop(), &g_RtnHistoryObjectAttrTopic_async);
    uv_mutex_init (&g_RtnHistoryObjectAttrTopic_mutex, OnRtnHistoryObjectAttrTopic);

    uv_async_init (uv_default_loop(), &g_RspQryFrontInfoTopic_async);
    uv_mutex_init (&g_RspQryFrontInfoTopic_mutex, OnRspQryFrontInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnFrontInfoTopic_async);
    uv_mutex_init (&g_RtnFrontInfoTopic_mutex, OnRtnFrontInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQrySysUserLoginTopic_async);
    uv_mutex_init (&g_RspQrySysUserLoginTopic_mutex, OnRspQrySysUserLoginTopic);

    uv_async_init (uv_default_loop(), &g_RspQrySysUserLogoutTopic_async);
    uv_mutex_init (&g_RspQrySysUserLogoutTopic_mutex, OnRspQrySysUserLogoutTopic);

    uv_async_init (uv_default_loop(), &g_RspQrySysUserPasswordUpdateTopic_async);
    uv_mutex_init (&g_RspQrySysUserPasswordUpdateTopic_mutex, OnRspQrySysUserPasswordUpdateTopic);

    uv_async_init (uv_default_loop(), &g_RspQrySysUserRegisterTopic_async);
    uv_mutex_init (&g_RspQrySysUserRegisterTopic_mutex, OnRspQrySysUserRegisterTopic);

    uv_async_init (uv_default_loop(), &g_RspQrySysUserDeleteTopic_async);
    uv_mutex_init (&g_RspQrySysUserDeleteTopic_mutex, OnRspQrySysUserDeleteTopic);

    uv_async_init (uv_default_loop(), &g_RspQryParticipantInitTopic_async);
    uv_mutex_init (&g_RspQryParticipantInitTopic_mutex, OnRspQryParticipantInitTopic);

    uv_async_init (uv_default_loop(), &g_RtnParticipantInitTopic_async);
    uv_mutex_init (&g_RtnParticipantInitTopic_mutex, OnRtnParticipantInitTopic);

    uv_async_init (uv_default_loop(), &g_RspQryUserInitTopic_async);
    uv_mutex_init (&g_RspQryUserInitTopic_mutex, OnRspQryUserInitTopic);

    uv_async_init (uv_default_loop(), &g_RtnUserInitTopic_async);
    uv_mutex_init (&g_RtnUserInitTopic_mutex, OnRtnUserInitTopic);

    uv_async_init (uv_default_loop(), &g_RspQryClientInitTopic_async);
    uv_mutex_init (&g_RspQryClientInitTopic_mutex, OnRspQryClientInitTopic);

    uv_async_init (uv_default_loop(), &g_RtnClientInitTopic_async);
    uv_mutex_init (&g_RtnClientInitTopic_mutex, OnRtnClientInitTopic);

    uv_async_init (uv_default_loop(), &g_RspQryTradeLogTopic_async);
    uv_mutex_init (&g_RspQryTradeLogTopic_mutex, OnRspQryTradeLogTopic);

    uv_async_init (uv_default_loop(), &g_RtnTradeLogTopic_async);
    uv_mutex_init (&g_RtnTradeLogTopic_mutex, OnRtnTradeLogTopic);

    uv_async_init (uv_default_loop(), &g_RspQryTradeUserLoginInfoTopic_async);
    uv_mutex_init (&g_RspQryTradeUserLoginInfoTopic_mutex, OnRspQryTradeUserLoginInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnTradeUserLoginInfoTopic_async);
    uv_mutex_init (&g_RtnTradeUserLoginInfoTopic_mutex, OnRtnTradeUserLoginInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryPartTradeTopic_async);
    uv_mutex_init (&g_RspQryPartTradeTopic_mutex, OnRspQryPartTradeTopic);

    uv_async_init (uv_default_loop(), &g_RspQryTradepeakTopic_async);
    uv_mutex_init (&g_RspQryTradepeakTopic_mutex, OnRspQryTradepeakTopic);

    uv_async_init (uv_default_loop(), &g_RtnUpdateSysConfigTopic_async);
    uv_mutex_init (&g_RtnUpdateSysConfigTopic_mutex, OnRtnUpdateSysConfigTopic);

    uv_async_init (uv_default_loop(), &g_RtnSysUser_async);
    uv_mutex_init (&g_RtnSysUser_mutex, OnRtnSysUser);

    uv_async_init (uv_default_loop(), &g_RtnPriceLimitChgTopic_async);
    uv_mutex_init (&g_RtnPriceLimitChgTopic_mutex, OnRtnPriceLimitChgTopic);

    uv_async_init (uv_default_loop(), &g_RspQryHistoryCpuInfoTopic_async);
    uv_mutex_init (&g_RspQryHistoryCpuInfoTopic_mutex, OnRspQryHistoryCpuInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryHistoryMemInfoTopic_async);
    uv_mutex_init (&g_RspQryHistoryMemInfoTopic_mutex, OnRspQryHistoryMemInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryHistoryNetworkInfoTopic_async);
    uv_mutex_init (&g_RspQryHistoryNetworkInfoTopic_mutex, OnRspQryHistoryNetworkInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryMonitorOnlineUser_async);
    uv_mutex_init (&g_RspQryMonitorOnlineUser_mutex, OnRspQryMonitorOnlineUser);

    uv_async_init (uv_default_loop(), &g_RspQryFrontStat_async);
    uv_mutex_init (&g_RspQryFrontStat_mutex, OnRspQryFrontStat);

    uv_async_init (uv_default_loop(), &g_RtnSysTimeSyncTopic_async);
    uv_mutex_init (&g_RtnSysTimeSyncTopic_mutex, OnRtnSysTimeSyncTopic);

    uv_async_init (uv_default_loop(), &g_RtnDataCenterChgTopic_async);
    uv_mutex_init (&g_RtnDataCenterChgTopic_mutex, OnRtnDataCenterChgTopic);

    uv_async_init (uv_default_loop(), &g_RspQryHistoryTradePeakTopic_async);
    uv_mutex_init (&g_RspQryHistoryTradePeakTopic_mutex, OnRspQryHistoryTradePeakTopic);

    uv_async_init (uv_default_loop(), &g_RtnHistoryTradePeakTopic_async);
    uv_mutex_init (&g_RtnHistoryTradePeakTopic_mutex, OnRtnHistoryTradePeakTopic);

    uv_async_init (uv_default_loop(), &g_RspQrySyslogEventTopic_async);
    uv_mutex_init (&g_RspQrySyslogEventTopic_mutex, OnRspQrySyslogEventTopic);

    uv_async_init (uv_default_loop(), &g_RtnSyslogEventTopic_async);
    uv_mutex_init (&g_RtnSyslogEventTopic_mutex, OnRtnSyslogEventTopic);

    uv_async_init (uv_default_loop(), &g_RspQryTradeDayChangeTopic_async);
    uv_mutex_init (&g_RspQryTradeDayChangeTopic_mutex, OnRspQryTradeDayChangeTopic);

    uv_async_init (uv_default_loop(), &g_RspQryWebAppInfoTopic_async);
    uv_mutex_init (&g_RspQryWebAppInfoTopic_mutex, OnRspQryWebAppInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnWebAppInfoTopic_async);
    uv_mutex_init (&g_RtnWebAppInfoTopic_mutex, OnRtnWebAppInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryServletInfoTopic_async);
    uv_mutex_init (&g_RspQryServletInfoTopic_mutex, OnRspQryServletInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnServletInfoTopic_async);
    uv_mutex_init (&g_RtnServletInfoTopic_mutex, OnRtnServletInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryFileInfoTopic_async);
    uv_mutex_init (&g_RspQryFileInfoTopic_mutex, OnRspQryFileInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnFileInfoTopic_async);
    uv_mutex_init (&g_RtnFileInfoTopic_mutex, OnRtnFileInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQrySessionInfoTopic_async);
    uv_mutex_init (&g_RspQrySessionInfoTopic_mutex, OnRspQrySessionInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnSessionInfoTopic_async);
    uv_mutex_init (&g_RtnSessionInfoTopic_mutex, OnRtnSessionInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryJDBCInfoTopic_async);
    uv_mutex_init (&g_RspQryJDBCInfoTopic_mutex, OnRspQryJDBCInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnJDBCInfoTopic_async);
    uv_mutex_init (&g_RtnJDBCInfoTopic_mutex, OnRtnJDBCInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryThreadInfoTopic_async);
    uv_mutex_init (&g_RspQryThreadInfoTopic_mutex, OnRspQryThreadInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnThreadInfoTopic_async);
    uv_mutex_init (&g_RtnThreadInfoTopic_mutex, OnRtnThreadInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryVMInfoTopic_async);
    uv_mutex_init (&g_RspQryVMInfoTopic_mutex, OnRspQryVMInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnVMInfoTopic_async);
    uv_mutex_init (&g_RtnVMInfoTopic_mutex, OnRtnVMInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryPropertyInfoTopic_async);
    uv_mutex_init (&g_RspQryPropertyInfoTopic_mutex, OnRspQryPropertyInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnPropertyInfoTopic_async);
    uv_mutex_init (&g_RtnPropertyInfoTopic_mutex, OnRtnPropertyInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryMemPoolInfoTopic_async);
    uv_mutex_init (&g_RspQryMemPoolInfoTopic_mutex, OnRspQryMemPoolInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnMemPoolInfoTopic_async);
    uv_mutex_init (&g_RtnMemPoolInfoTopic_mutex, OnRtnMemPoolInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryFileContentInfoTopic_async);
    uv_mutex_init (&g_RspQryFileContentInfoTopic_mutex, OnRspQryFileContentInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnFileContentInfoTopic_async);
    uv_mutex_init (&g_RtnFileContentInfoTopic_mutex, OnRtnFileContentInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryConnectionInfoTopic_async);
    uv_mutex_init (&g_RspQryConnectionInfoTopic_mutex, OnRspQryConnectionInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnConnectionInfoTopic_async);
    uv_mutex_init (&g_RtnConnectionInfoTopic_mutex, OnRtnConnectionInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryConnectorInfoTopic_async);
    uv_mutex_init (&g_RspQryConnectorInfoTopic_mutex, OnRspQryConnectorInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnConnectorInfoTopic_async);
    uv_mutex_init (&g_RtnConnectorInfoTopic_mutex, OnRtnConnectorInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryDBQueryTopic_async);
    uv_mutex_init (&g_RspQryDBQueryTopic_mutex, OnRspQryDBQueryTopic);

    uv_async_init (uv_default_loop(), &g_RtnDBQueryTopic_async);
    uv_mutex_init (&g_RtnDBQueryTopic_mutex, OnRtnDBQueryTopic);

    uv_async_init (uv_default_loop(), &g_RspQryGeneralFieldTopic_async);
    uv_mutex_init (&g_RspQryGeneralFieldTopic_mutex, OnRspQryGeneralFieldTopic);

    uv_async_init (uv_default_loop(), &g_RtnGeneralFieldTopic_async);
    uv_mutex_init (&g_RtnGeneralFieldTopic_mutex, OnRtnGeneralFieldTopic);

    uv_async_init (uv_default_loop(), &g_RspQryGetFileTopic_async);
    uv_mutex_init (&g_RspQryGetFileTopic_mutex, OnRspQryGetFileTopic);

    uv_async_init (uv_default_loop(), &g_RspQryWarningQueryTopic_async);
    uv_mutex_init (&g_RspQryWarningQueryTopic_mutex, OnRspQryWarningQueryTopic);

    uv_async_init (uv_default_loop(), &g_RtnWarningQueryTopic_async);
    uv_mutex_init (&g_RtnWarningQueryTopic_mutex, OnRtnWarningQueryTopic);

    uv_async_init (uv_default_loop(), &g_RtnHostConfig_async);
    uv_mutex_init (&g_RtnHostConfig_mutex, OnRtnHostConfig);

    uv_async_init (uv_default_loop(), &g_RspQryGeneralOperateTopic_async);
    uv_mutex_init (&g_RspQryGeneralOperateTopic_mutex, OnRspQryGeneralOperateTopic);

    uv_async_init (uv_default_loop(), &g_RtnGeneralOperateTopic_async);
    uv_mutex_init (&g_RtnGeneralOperateTopic_mutex, OnRtnGeneralOperateTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetDeviceLinkedTopic_async);
    uv_mutex_init (&g_RspQryNetDeviceLinkedTopic_mutex, OnRspQryNetDeviceLinkedTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetDeviceLinkedTopic_async);
    uv_mutex_init (&g_RtnNetDeviceLinkedTopic_mutex, OnRtnNetDeviceLinkedTopic);

    uv_async_init (uv_default_loop(), &g_RspQryTradeUserLoginStatTopic_async);
    uv_mutex_init (&g_RspQryTradeUserLoginStatTopic_mutex, OnRspQryTradeUserLoginStatTopic);

    uv_async_init (uv_default_loop(), &g_RspQryTradeFrontOrderRttStatTopic_async);
    uv_mutex_init (&g_RspQryTradeFrontOrderRttStatTopic_mutex, OnRspQryTradeFrontOrderRttStatTopic);

    uv_async_init (uv_default_loop(), &g_RtnTradeFrontOrderRttStatTopic_async);
    uv_mutex_init (&g_RtnTradeFrontOrderRttStatTopic_mutex, OnRtnTradeFrontOrderRttStatTopic);

    uv_async_init (uv_default_loop(), &g_RspQryParticTradeOrderStatesTopic_async);
    uv_mutex_init (&g_RspQryParticTradeOrderStatesTopic_mutex, OnRspQryParticTradeOrderStatesTopic);

    uv_async_init (uv_default_loop(), &g_RtnParticTradeOrderStatesTopic_async);
    uv_mutex_init (&g_RtnParticTradeOrderStatesTopic_mutex, OnRtnParticTradeOrderStatesTopic);

    uv_async_init (uv_default_loop(), &g_RspQryRouterInfoTopic_async);
    uv_mutex_init (&g_RspQryRouterInfoTopic_mutex, OnRspQryRouterInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnRouterInfoTopic_async);
    uv_mutex_init (&g_RtnRouterInfoTopic_mutex, OnRtnRouterInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryDiskIOTopic_async);
    uv_mutex_init (&g_RspQryDiskIOTopic_mutex, OnRspQryDiskIOTopic);

    uv_async_init (uv_default_loop(), &g_RtnDiskIOTopic_async);
    uv_mutex_init (&g_RtnDiskIOTopic_mutex, OnRtnDiskIOTopic);

    uv_async_init (uv_default_loop(), &g_RspQryStatInfoTopic_async);
    uv_mutex_init (&g_RspQryStatInfoTopic_mutex, OnRspQryStatInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnStatInfoTopic_async);
    uv_mutex_init (&g_RtnStatInfoTopic_mutex, OnRtnStatInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryTradeOrderRttCutLineTopic_async);
    uv_mutex_init (&g_RspQryTradeOrderRttCutLineTopic_mutex, OnRspQryTradeOrderRttCutLineTopic);

    uv_async_init (uv_default_loop(), &g_RtnTradeOrderRttCutLineTopic_async);
    uv_mutex_init (&g_RtnTradeOrderRttCutLineTopic_mutex, OnRtnTradeOrderRttCutLineTopic);

    uv_async_init (uv_default_loop(), &g_RspQryClientInfoTopic_async);
    uv_mutex_init (&g_RspQryClientInfoTopic_mutex, OnRspQryClientInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnClientInfoTopic_async);
    uv_mutex_init (&g_RtnClientInfoTopic_mutex, OnRtnClientInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryEventDescriptionTopic_async);
    uv_mutex_init (&g_RspQryEventDescriptionTopic_mutex, OnRspQryEventDescriptionTopic);

    uv_async_init (uv_default_loop(), &g_RtnEventDescriptionTopic_async);
    uv_mutex_init (&g_RtnEventDescriptionTopic_mutex, OnRtnEventDescriptionTopic);

    uv_async_init (uv_default_loop(), &g_RspQryFrontUniqueIDTopic_async);
    uv_mutex_init (&g_RspQryFrontUniqueIDTopic_mutex, OnRspQryFrontUniqueIDTopic);

    uv_async_init (uv_default_loop(), &g_RtnFrontUniqueIDTopic_async);
    uv_mutex_init (&g_RtnFrontUniqueIDTopic_mutex, OnRtnFrontUniqueIDTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetPartyLinkAddrChangeTopic_async);
    uv_mutex_init (&g_RspQryNetPartyLinkAddrChangeTopic_mutex, OnRspQryNetPartyLinkAddrChangeTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetPartyLinkAddrChangeTopic_async);
    uv_mutex_init (&g_RtnNetPartyLinkAddrChangeTopic_mutex, OnRtnNetPartyLinkAddrChangeTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetDelPartyLinkInfoTopic_async);
    uv_mutex_init (&g_RspQryNetDelPartyLinkInfoTopic_mutex, OnRspQryNetDelPartyLinkInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetDelPartyLinkInfoTopic_async);
    uv_mutex_init (&g_RtnNetDelPartyLinkInfoTopic_mutex, OnRtnNetDelPartyLinkInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryPerformanceTopTopic_async);
    uv_mutex_init (&g_RspQryPerformanceTopTopic_mutex, OnRspQryPerformanceTopTopic);

    uv_async_init (uv_default_loop(), &g_RtnPerformanceTopTopic_async);
    uv_mutex_init (&g_RtnPerformanceTopTopic_mutex, OnRtnPerformanceTopTopic);

    uv_async_init (uv_default_loop(), &g_RspQryInstrumentStatusTopic_async);
    uv_mutex_init (&g_RspQryInstrumentStatusTopic_mutex, OnRspQryInstrumentStatusTopic);

    uv_async_init (uv_default_loop(), &g_RtnInstrumentStatusTopic_async);
    uv_mutex_init (&g_RtnInstrumentStatusTopic_mutex, OnRtnInstrumentStatusTopic);

    uv_async_init (uv_default_loop(), &g_RspQryCurrTradingSegmentAttrTopic_async);
    uv_mutex_init (&g_RspQryCurrTradingSegmentAttrTopic_mutex, OnRspQryCurrTradingSegmentAttrTopic);

    uv_async_init (uv_default_loop(), &g_RtnCurrTradingSegmentAttrTopic_async);
    uv_mutex_init (&g_RtnCurrTradingSegmentAttrTopic_mutex, OnRtnCurrTradingSegmentAttrTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetAreaTopic_async);
    uv_mutex_init (&g_RspQryNetAreaTopic_mutex, OnRspQryNetAreaTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetAreaTopic_async);
    uv_mutex_init (&g_RtnNetAreaTopic_mutex, OnRtnNetAreaTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetSubAreaTopic_async);
    uv_mutex_init (&g_RspQryNetSubAreaTopic_mutex, OnRspQryNetSubAreaTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetSubAreaTopic_async);
    uv_mutex_init (&g_RtnNetSubAreaTopic_mutex, OnRtnNetSubAreaTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetSubAreaIPTopic_async);
    uv_mutex_init (&g_RspQryNetSubAreaIPTopic_mutex, OnRspQryNetSubAreaIPTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetSubAreaIPTopic_async);
    uv_mutex_init (&g_RtnNetSubAreaIPTopic_mutex, OnRtnNetSubAreaIPTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetDeviceTopic_async);
    uv_mutex_init (&g_RspQryNetDeviceTopic_mutex, OnRspQryNetDeviceTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetDeviceTopic_async);
    uv_mutex_init (&g_RtnNetDeviceTopic_mutex, OnRtnNetDeviceTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetDeviceDetectTopic_async);
    uv_mutex_init (&g_RspQryNetDeviceDetectTopic_mutex, OnRspQryNetDeviceDetectTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetBuildingTopic_async);
    uv_mutex_init (&g_RspQryNetBuildingTopic_mutex, OnRspQryNetBuildingTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetBuildingTopic_async);
    uv_mutex_init (&g_RtnNetBuildingTopic_mutex, OnRtnNetBuildingTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetRoomTopic_async);
    uv_mutex_init (&g_RspQryNetRoomTopic_mutex, OnRspQryNetRoomTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetRoomTopic_async);
    uv_mutex_init (&g_RtnNetRoomTopic_mutex, OnRtnNetRoomTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetCabinetsTopic_async);
    uv_mutex_init (&g_RspQryNetCabinetsTopic_mutex, OnRspQryNetCabinetsTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetCabinetsTopic_async);
    uv_mutex_init (&g_RtnNetCabinetsTopic_mutex, OnRtnNetCabinetsTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetOIDTopic_async);
    uv_mutex_init (&g_RspQryNetOIDTopic_mutex, OnRspQryNetOIDTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetOIDTopic_async);
    uv_mutex_init (&g_RtnNetOIDTopic_mutex, OnRtnNetOIDTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetTimePolicyTopic_async);
    uv_mutex_init (&g_RspQryNetTimePolicyTopic_mutex, OnRspQryNetTimePolicyTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetTimePolicyTopic_async);
    uv_mutex_init (&g_RtnNetTimePolicyTopic_mutex, OnRtnNetTimePolicyTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetGatherTaskTopic_async);
    uv_mutex_init (&g_RspQryNetGatherTaskTopic_mutex, OnRspQryNetGatherTaskTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetGatherTaskTopic_async);
    uv_mutex_init (&g_RtnNetGatherTaskTopic_mutex, OnRtnNetGatherTaskTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetDeviceChgTopic_async);
    uv_mutex_init (&g_RspQryNetDeviceChgTopic_mutex, OnRspQryNetDeviceChgTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetDeviceChgTopic_async);
    uv_mutex_init (&g_RtnNetDeviceChgTopic_mutex, OnRtnNetDeviceChgTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetDeviceTypeTopic_async);
    uv_mutex_init (&g_RspQryNetDeviceTypeTopic_mutex, OnRspQryNetDeviceTypeTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetDeviceTypeTopic_async);
    uv_mutex_init (&g_RtnNetDeviceTypeTopic_mutex, OnRtnNetDeviceTypeTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetDeviceCategoryTopic_async);
    uv_mutex_init (&g_RspQryNetDeviceCategoryTopic_mutex, OnRspQryNetDeviceCategoryTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetDeviceCategoryTopic_async);
    uv_mutex_init (&g_RtnNetDeviceCategoryTopic_mutex, OnRtnNetDeviceCategoryTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetManufactoryTopic_async);
    uv_mutex_init (&g_RspQryNetManufactoryTopic_mutex, OnRspQryNetManufactoryTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetManufactoryTopic_async);
    uv_mutex_init (&g_RtnNetManufactoryTopic_mutex, OnRtnNetManufactoryTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetCommunityTopic_async);
    uv_mutex_init (&g_RspQryNetCommunityTopic_mutex, OnRspQryNetCommunityTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetCommunityTopic_async);
    uv_mutex_init (&g_RtnNetCommunityTopic_mutex, OnRtnNetCommunityTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetPortTypeTopic_async);
    uv_mutex_init (&g_RspQryNetPortTypeTopic_mutex, OnRspQryNetPortTypeTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetPortTypeTopic_async);
    uv_mutex_init (&g_RtnNetPortTypeTopic_mutex, OnRtnNetPortTypeTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetPartAccessSpotTopic_async);
    uv_mutex_init (&g_RspQryNetPartAccessSpotTopic_mutex, OnRspQryNetPartAccessSpotTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetPartAccessSpotTopic_async);
    uv_mutex_init (&g_RtnNetPartAccessSpotTopic_mutex, OnRtnNetPartAccessSpotTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetInterfaceTopic_async);
    uv_mutex_init (&g_RspQryNetInterfaceTopic_mutex, OnRspQryNetInterfaceTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetInterfaceTopic_async);
    uv_mutex_init (&g_RtnNetInterfaceTopic_mutex, OnRtnNetInterfaceTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetGeneralOIDTopic_async);
    uv_mutex_init (&g_RspQryNetGeneralOIDTopic_mutex, OnRspQryNetGeneralOIDTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetGeneralOIDTopic_async);
    uv_mutex_init (&g_RtnNetGeneralOIDTopic_mutex, OnRtnNetGeneralOIDTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorTypeTopic_async);
    uv_mutex_init (&g_RspQryNetMonitorTypeTopic_mutex, OnRspQryNetMonitorTypeTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorTypeTopic_async);
    uv_mutex_init (&g_RtnNetMonitorTypeTopic_mutex, OnRtnNetMonitorTypeTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorAttrScopeTopic_async);
    uv_mutex_init (&g_RspQryNetMonitorAttrScopeTopic_mutex, OnRspQryNetMonitorAttrScopeTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorAttrScopeTopic_async);
    uv_mutex_init (&g_RtnNetMonitorAttrScopeTopic_mutex, OnRtnNetMonitorAttrScopeTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorAttrTypeTopic_async);
    uv_mutex_init (&g_RspQryNetMonitorAttrTypeTopic_mutex, OnRspQryNetMonitorAttrTypeTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorAttrTypeTopic_async);
    uv_mutex_init (&g_RtnNetMonitorAttrTypeTopic_mutex, OnRtnNetMonitorAttrTypeTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorObjectAttrTopic_async);
    uv_mutex_init (&g_RspQryNetMonitorObjectAttrTopic_mutex, OnRspQryNetMonitorObjectAttrTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorObjectAttrTopic_async);
    uv_mutex_init (&g_RtnNetMonitorObjectAttrTopic_mutex, OnRtnNetMonitorObjectAttrTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetFuncAreaTopic_async);
    uv_mutex_init (&g_RspQryNetFuncAreaTopic_mutex, OnRspQryNetFuncAreaTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetFuncAreaTopic_async);
    uv_mutex_init (&g_RtnNetFuncAreaTopic_mutex, OnRtnNetFuncAreaTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorCommandTypeTopic_async);
    uv_mutex_init (&g_RspQryNetMonitorCommandTypeTopic_mutex, OnRspQryNetMonitorCommandTypeTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorCommandTypeTopic_async);
    uv_mutex_init (&g_RtnNetMonitorCommandTypeTopic_mutex, OnRtnNetMonitorCommandTypeTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorActionGroupTopic_async);
    uv_mutex_init (&g_RspQryNetMonitorActionGroupTopic_mutex, OnRspQryNetMonitorActionGroupTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorActionGroupTopic_async);
    uv_mutex_init (&g_RtnNetMonitorActionGroupTopic_mutex, OnRtnNetMonitorActionGroupTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorDeviceGroupTopic_async);
    uv_mutex_init (&g_RspQryNetMonitorDeviceGroupTopic_mutex, OnRspQryNetMonitorDeviceGroupTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorDeviceGroupTopic_async);
    uv_mutex_init (&g_RtnNetMonitorDeviceGroupTopic_mutex, OnRtnNetMonitorDeviceGroupTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorTaskInfoTopic_async);
    uv_mutex_init (&g_RspQryNetMonitorTaskInfoTopic_mutex, OnRspQryNetMonitorTaskInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorTaskInfoTopic_async);
    uv_mutex_init (&g_RtnNetMonitorTaskInfoTopic_mutex, OnRtnNetMonitorTaskInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorTaskResultTopic_async);
    uv_mutex_init (&g_RspQryNetMonitorTaskResultTopic_mutex, OnRspQryNetMonitorTaskResultTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorTaskResultTopic_async);
    uv_mutex_init (&g_RtnNetMonitorTaskResultTopic_mutex, OnRtnNetMonitorTaskResultTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorTaskObjectSetTopic_async);
    uv_mutex_init (&g_RspQryNetMonitorTaskObjectSetTopic_mutex, OnRspQryNetMonitorTaskObjectSetTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorTaskObjectSetTopic_async);
    uv_mutex_init (&g_RtnNetMonitorTaskObjectSetTopic_mutex, OnRtnNetMonitorTaskObjectSetTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetPartyLinkInfoTopic_async);
    uv_mutex_init (&g_RspQryNetPartyLinkInfoTopic_mutex, OnRspQryNetPartyLinkInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetPartyLinkInfoTopic_async);
    uv_mutex_init (&g_RtnNetPartyLinkInfoTopic_mutex, OnRtnNetPartyLinkInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorActionAttrTopic_async);
    uv_mutex_init (&g_RspQryNetMonitorActionAttrTopic_mutex, OnRspQryNetMonitorActionAttrTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorActionAttrTopic_async);
    uv_mutex_init (&g_RtnNetMonitorActionAttrTopic_mutex, OnRtnNetMonitorActionAttrTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetModuleTopic_async);
    uv_mutex_init (&g_RspQryNetModuleTopic_mutex, OnRspQryNetModuleTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetModuleTopic_async);
    uv_mutex_init (&g_RtnNetModuleTopic_mutex, OnRtnNetModuleTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetEventExprTopic_async);
    uv_mutex_init (&g_RspQryNetEventExprTopic_mutex, OnRspQryNetEventExprTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetEventExprTopic_async);
    uv_mutex_init (&g_RtnNetEventExprTopic_mutex, OnRtnNetEventExprTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetEventTypeTopic_async);
    uv_mutex_init (&g_RspQryNetEventTypeTopic_mutex, OnRspQryNetEventTypeTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetEventTypeTopic_async);
    uv_mutex_init (&g_RtnNetEventTypeTopic_mutex, OnRtnNetEventTypeTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetSubEventTypeTopic_async);
    uv_mutex_init (&g_RspQryNetSubEventTypeTopic_mutex, OnRspQryNetSubEventTypeTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetSubEventTypeTopic_async);
    uv_mutex_init (&g_RtnNetSubEventTypeTopic_mutex, OnRtnNetSubEventTypeTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetEventLevelTopic_async);
    uv_mutex_init (&g_RspQryNetEventLevelTopic_mutex, OnRspQryNetEventLevelTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetEventLevelTopic_async);
    uv_mutex_init (&g_RtnNetEventLevelTopic_mutex, OnRtnNetEventLevelTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorTaskStatusResultTopic_async);
    uv_mutex_init (&g_RspQryNetMonitorTaskStatusResultTopic_mutex, OnRspQryNetMonitorTaskStatusResultTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorTaskStatusResultTopic_async);
    uv_mutex_init (&g_RtnNetMonitorTaskStatusResultTopic_mutex, OnRtnNetMonitorTaskStatusResultTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetCfgFileTopic_async);
    uv_mutex_init (&g_RspQryNetCfgFileTopic_mutex, OnRspQryNetCfgFileTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetCfgFileTopic_async);
    uv_mutex_init (&g_RtnNetCfgFileTopic_mutex, OnRtnNetCfgFileTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorDeviceTaskTopic_async);
    uv_mutex_init (&g_RspQryNetMonitorDeviceTaskTopic_mutex, OnRspQryNetMonitorDeviceTaskTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorDeviceTaskTopic_async);
    uv_mutex_init (&g_RtnNetMonitorDeviceTaskTopic_mutex, OnRtnNetMonitorDeviceTaskTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetMonitorTaskInstAttrsTopic_async);
    uv_mutex_init (&g_RspQryNetMonitorTaskInstAttrsTopic_mutex, OnRspQryNetMonitorTaskInstAttrsTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetMonitorTaskInstAttrsTopic_async);
    uv_mutex_init (&g_RtnNetMonitorTaskInstAttrsTopic_mutex, OnRtnNetMonitorTaskInstAttrsTopic);

    uv_async_init (uv_default_loop(), &g_RspQryFileGeneralOperTopic_async);
    uv_mutex_init (&g_RspQryFileGeneralOperTopic_mutex, OnRspQryFileGeneralOperTopic);

    uv_async_init (uv_default_loop(), &g_RtnFileGeneralOperTopic_async);
    uv_mutex_init (&g_RtnFileGeneralOperTopic_mutex, OnRtnFileGeneralOperTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetBaseLineTopic_async);
    uv_mutex_init (&g_RspQryNetBaseLineTopic_mutex, OnRspQryNetBaseLineTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetBaseLineTopic_async);
    uv_mutex_init (&g_RtnNetBaseLineTopic_mutex, OnRtnNetBaseLineTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetBaseLineTaskTopic_async);
    uv_mutex_init (&g_RspQryNetBaseLineTaskTopic_mutex, OnRspQryNetBaseLineTaskTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetBaseLineTaskTopic_async);
    uv_mutex_init (&g_RtnNetBaseLineTaskTopic_mutex, OnRtnNetBaseLineTaskTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetBaseLineResultTopic_async);
    uv_mutex_init (&g_RspQryNetBaseLineResultTopic_mutex, OnRspQryNetBaseLineResultTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetBaseLineResultTopic_async);
    uv_mutex_init (&g_RtnNetBaseLineResultTopic_mutex, OnRtnNetBaseLineResultTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetPartyLinkStatusInfoTopic_async);
    uv_mutex_init (&g_RspQryNetPartyLinkStatusInfoTopic_mutex, OnRspQryNetPartyLinkStatusInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetPartyLinkStatusInfoTopic_async);
    uv_mutex_init (&g_RtnNetPartyLinkStatusInfoTopic_mutex, OnRtnNetPartyLinkStatusInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetMemberSDHLineInfoTopic_async);
    uv_mutex_init (&g_RspQryNetMemberSDHLineInfoTopic_mutex, OnRspQryNetMemberSDHLineInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetMemberSDHLineInfoTopic_async);
    uv_mutex_init (&g_RtnNetMemberSDHLineInfoTopic_mutex, OnRtnNetMemberSDHLineInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetDDNLinkInfoTopic_async);
    uv_mutex_init (&g_RspQryNetDDNLinkInfoTopic_mutex, OnRspQryNetDDNLinkInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetDDNLinkInfoTopic_async);
    uv_mutex_init (&g_RtnNetDDNLinkInfoTopic_mutex, OnRtnNetDDNLinkInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetPseudMemberLinkInfoTopic_async);
    uv_mutex_init (&g_RspQryNetPseudMemberLinkInfoTopic_mutex, OnRspQryNetPseudMemberLinkInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetPseudMemberLinkInfoTopic_async);
    uv_mutex_init (&g_RtnNetPseudMemberLinkInfoTopic_mutex, OnRtnNetPseudMemberLinkInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryOuterDeviceInfTopic_async);
    uv_mutex_init (&g_RspQryOuterDeviceInfTopic_mutex, OnRspQryOuterDeviceInfTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetOuterDeviceInfTopic_async);
    uv_mutex_init (&g_RtnNetOuterDeviceInfTopic_mutex, OnRtnNetOuterDeviceInfTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetLocalPingResultInfoTopic_async);
    uv_mutex_init (&g_RspQryNetLocalPingResultInfoTopic_mutex, OnRspQryNetLocalPingResultInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetLocalPingResultInfoTopic_async);
    uv_mutex_init (&g_RtnNetLocalPingResultInfoTopic_mutex, OnRtnNetLocalPingResultInfoTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetRomotePingResultInfoTopic_async);
    uv_mutex_init (&g_RspQryNetRomotePingResultInfoTopic_mutex, OnRspQryNetRomotePingResultInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetRomotePingResultInfoTopic_async);
    uv_mutex_init (&g_RtnNetRomotePingResultInfoTopic_mutex, OnRtnNetRomotePingResultInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnMonitorTopProcessInfo_async);
    uv_mutex_init (&g_RtnMonitorTopProcessInfo_mutex, OnRtnMonitorTopProcessInfo);

    uv_async_init (uv_default_loop(), &g_RspQrySysInternalTopologyTopic_async);
    uv_mutex_init (&g_RspQrySysInternalTopologyTopic_mutex, OnRspQrySysInternalTopologyTopic);

    uv_async_init (uv_default_loop(), &g_RtnSysInternalTopologyTopic_async);
    uv_mutex_init (&g_RtnSysInternalTopologyTopic_mutex, OnRtnSysInternalTopologyTopic);

    uv_async_init (uv_default_loop(), &g_RspQryMemberLinkCostTopic_async);
    uv_mutex_init (&g_RspQryMemberLinkCostTopic_mutex, OnRspQryMemberLinkCostTopic);

    uv_async_init (uv_default_loop(), &g_RtnMemberLinkCostTopic_async);
    uv_mutex_init (&g_RtnMemberLinkCostTopic_mutex, OnRtnMemberLinkCostTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetPartylinkMonthlyRentTopic_async);
    uv_mutex_init (&g_RspQryNetPartylinkMonthlyRentTopic_mutex, OnRspQryNetPartylinkMonthlyRentTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetPartylinkMonthlyRentTopic_async);
    uv_mutex_init (&g_RtnNetPartylinkMonthlyRentTopic_mutex, OnRtnNetPartylinkMonthlyRentTopic);

    uv_async_init (uv_default_loop(), &g_RspQryNetNonPartyLinkInfoTopic_async);
    uv_mutex_init (&g_RspQryNetNonPartyLinkInfoTopic_mutex, OnRspQryNetNonPartyLinkInfoTopic);

    uv_async_init (uv_default_loop(), &g_RtnNetNonPartyLinkInfoTopic_async);
    uv_mutex_init (&g_RtnNetNonPartyLinkInfoTopic_mutex, OnRtnNetNonPartyLinkInfoTopic);

};

NODE_MODULE (addon, InitAll);