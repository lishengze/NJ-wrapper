#ifndef _SYSUSERSPI_H_
 #define _SYSUSERSPI_H_

 #include "FtdcUserApi.h"
 #include "tool-function.h"
 #include "id-func.h"
 #include "nan.h"

 class SysUserSpi: public CShfeFtdcUserSpi
 {
    public:
        Nan::Persistent<v8::Object> m_spiobj;
        FRONT_ID m_frontid;
        
    public:
        virtual ~SysUserSpi() {}
        
        virtual void OnFrontConnected();
        
        virtual void OnFrontDisConnected(int nReason);
        
        virtual void OnHeartBeatWarning(int nTimeLapse);
        
        virtual void OnRspQryTopCpuInfoTopic(CShfeFtdcRspQryTopCpuInfoField *pRspQryTopCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnTopCpuInfoTopic(CShfeFtdcRtnTopCpuInfoField *pRtnTopCpuInfo);

        virtual void OnRspQryTopMemInfoTopic(CShfeFtdcRspQryTopMemInfoField *pRspQryTopMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnTopMemInfoTopic(CShfeFtdcRtnTopMemInfoField *pRtnTopMemInfo);

        virtual void OnRspQryTopProcessInfoTopic(CShfeFtdcRspQryTopProcessInfoField *pRspQryTopProcessInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnTopProcessInfoTopic(CShfeFtdcRtnTopProcessInfoField *pRtnTopProcessInfo);

        virtual void OnRspQryFileSystemInfoTopic(CShfeFtdcRspQryFileSystemInfoField *pRspQryFileSystemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnFileSystemInfoTopic(CShfeFtdcRtnFileSystemInfoField *pRtnFileSystemInfo);

        virtual void OnRspQryNetworkInfoTopic(CShfeFtdcRspQryNetworkInfoField *pRspQryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetworkInfoTopic(CShfeFtdcRtnNetworkInfoField *pRtnNetworkInfo);

        virtual void OnRspQryMonitorObjectTopic(CShfeFtdcRspQryMonitorObjectField *pRspQryMonitorObject, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonitorObjectTopic(CShfeFtdcRtnMonitorObjectField *pRtnMonitorObject);

        virtual void OnRspQryObjectRationalTopic(CShfeFtdcRspQryObjectRationalField *pRspQryObjectRational, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnObjectRationalTopic(CShfeFtdcRtnObjectRationalField *pRtnObjectRational);

        virtual void OnRspQrySyslogInfoTopic(CShfeFtdcRspQrySyslogInfoField *pRspQrySyslogInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnSyslogInfoTopic(CShfeFtdcRtnSyslogInfoField *pRtnSyslogInfo);

        virtual void OnRspQrySubscriberTopic(CShfeFtdcRspQrySubscriberField *pRspQrySubscriber, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryOidRelationTopic(CShfeFtdcRspQryOidRelationField *pRspQryOidRelation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnOidRelationTopic(CShfeFtdcRtnOidRelationField *pRtnOidRelation);

        virtual void OnRspQryUserInfoTopic(CShfeFtdcRspQryUserInfoField *pRspQryUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnUserInfoTopic(CShfeFtdcRtnUserInfoField *pRtnUserInfo);

        virtual void OnRspQryOnlineUserInfoTopic(CShfeFtdcRspQryOnlineUserInfoField *pRspQryOnlineUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnOnlineUserInfoTopic(CShfeFtdcRtnOnlineUserInfoField *pRtnOnlineUserInfo);

        virtual void OnRspQryWarningEventTopic(CShfeFtdcRspQryWarningEventField *pRspQryWarningEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnWarningEventTopic(CShfeFtdcRtnWarningEventField *pRtnWarningEvent);

        virtual void OnRspQrySyslogEventTopic(CShfeFtdcRspQrySyslogEventField *pRspQrySyslogEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnSyslogEventTopic(CShfeFtdcRtnSyslogEventField *pRtnSyslogEvent);

        virtual void OnRspQryObjectAttrTopic(CShfeFtdcRspQryObjectAttrField *pRspQryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnObjectAttrTopic(CShfeFtdcRtnObjectAttrField *pRtnObjectAttr);

        virtual void OnRspQryInvalidateOrderTopic(CShfeFtdcRspQryInvalidateOrderField *pRspQryInvalidateOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnInvalidateOrderTopic(CShfeFtdcRtnInvalidateOrderField *pRtnInvalidateOrder);

        virtual void OnRspQryOrderStatusTopic(CShfeFtdcRspQryOrderStatusField *pRspQryOrderStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnOrderStatusTopic(CShfeFtdcRtnOrderStatusField *pRtnOrderStatus);

        virtual void OnRspQryBargainOrderTopic(CShfeFtdcRspQryBargainOrderField *pRspQryBargainOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnBargainOrderTopic(CShfeFtdcRtnBargainOrderField *pRtnBargainOrder);

        virtual void OnRspQryInstPropertyTopic(CShfeFtdcRspQryInstPropertyField *pRspQryInstProperty, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnInstPropertyTopic(CShfeFtdcRtnInstPropertyField *pRtnInstProperty);

        virtual void OnRspQryMarginRateTopic(CShfeFtdcRspQryMarginRateField *pRspQryMarginRate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMarginRateTopic(CShfeFtdcRtnMarginRateField *pRtnMarginRate);

        virtual void OnRspQryPriceLimitTopic(CShfeFtdcRspQryPriceLimitField *pRspQryPriceLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnPriceLimitTopic(CShfeFtdcRtnPriceLimitField *pRtnPriceLimit);

        virtual void OnRspQryPartPosiLimitTopic(CShfeFtdcRspQryPartPosiLimitField *pRspQryPartPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnPartPosiLimitTopic(CShfeFtdcRtnPartPosiLimitField *pRtnPartPosiLimit);

        virtual void OnRspQryClientPosiLimitTopic(CShfeFtdcRspQryClientPosiLimitField *pRspQryClientPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnClientPosiLimitTopic(CShfeFtdcRtnClientPosiLimitField *pRtnClientPosiLimit);

        virtual void OnRspQrySpecialPosiLimitTopic(CShfeFtdcRspQrySpecialPosiLimitField *pRspQrySpecialPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnSpecialPosiLimitTopic(CShfeFtdcRtnSpecialPosiLimitField *pRtnSpecialPosiLimit);

        virtual void OnRspQryTransactionChgTopic(CShfeFtdcRspQryTransactionChgField *pRspQryTransactionChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnTransactionChgTopic(CShfeFtdcRtnTransactionChgField *pRtnTransactionChg);

        virtual void OnRspQryClientChgTopic(CShfeFtdcRspQryClientChgField *pRspQryClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnClientChgTopic(CShfeFtdcRtnClientChgField *pRtnClientChg);

        virtual void OnRspQryPartClientChgTopic(CShfeFtdcRspQryPartClientChgField *pRspQryPartClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnPartClientChgTopic(CShfeFtdcRtnPartClientChgField *pRtnPartClientChg);

        virtual void OnRspQryPosiLimitChgTopic(CShfeFtdcRspQryPosiLimitChgField *pRspQryPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnPosiLimitChgTopic(CShfeFtdcRtnPosiLimitChgField *pRtnPosiLimitChg);

        virtual void OnRspQryClientPosiLimitChgTopic(CShfeFtdcRspQryClientPosiLimitChgField *pRspQryClientPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnClientPosiLimitChgTopic(CShfeFtdcRtnClientPosiLimitChgField *pRtnClientPosiLimitChg);

        virtual void OnRspQrySpecPosiLimitChgTopic(CShfeFtdcRspQrySpecPosiLimitChgField *pRspQrySpecPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnSpecPosiLimitChgTopic(CShfeFtdcRtnSpecPosiLimitChgField *pRtnSpecPosiLimitChg);

        virtual void OnRspQryHedgeDetailChgTopic(CShfeFtdcRspQryHedgeDetailChgField *pRspQryHedgeDetailChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnHedgeDetailChgTopic(CShfeFtdcRtnHedgeDetailChgField *pRtnHedgeDetailChg);

        virtual void OnRspQryParticipantChgTopic(CShfeFtdcRspQryParticipantChgField *pRspQryParticipantChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnParticipantChgTopic(CShfeFtdcRtnParticipantChgField *pRtnParticipantChg);

        virtual void OnRspQryMarginRateChgTopic(CShfeFtdcRspQryMarginRateChgField *pRspQryMarginRateChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMarginRateChgTopic(CShfeFtdcRtnMarginRateChgField *pRtnMarginRateChg);

        virtual void OnRspQryUserIpChgTopic(CShfeFtdcRspQryUserIpChgField *pRspQryUserIpChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnUserIpChgTopic(CShfeFtdcRtnUserIpChgField *pRtnUserIpChg);

        virtual void OnRspQryHistoryObjectAttrTopic(CShfeFtdcRspQryHistoryObjectAttrField *pRspQryHistoryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnHistoryObjectAttrTopic(CShfeFtdcRtnHistoryObjectAttrField *pRtnHistoryObjectAttr);

        virtual void OnRspQryFrontInfoTopic(CShfeFtdcRspQryFrontInfoField *pRspQryFrontInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnFrontInfoTopic(CShfeFtdcRtnFrontInfoField *pRtnFrontInfo);

        virtual void OnRspQrySysUserLoginTopic(CShfeFtdcRspQrySysUserLoginField *pRspQrySysUserLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQrySysUserLogoutTopic(CShfeFtdcRspQrySysUserLogoutField *pRspQrySysUserLogout, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQrySysUserPasswordUpdateTopic(CShfeFtdcRspQrySysUserPasswordUpdateField *pRspQrySysUserPasswordUpdate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQrySysUserRegisterTopic(CShfeFtdcRspQrySysUserRegisterField *pRspQrySysUserRegister, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQrySysUserDeleteTopic(CShfeFtdcRspQrySysUserDeleteField *pRspQrySysUserDelete, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryTradeLogTopic(CShfeFtdcRspQryTradeLogField *pRspQryTradeLog, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnTradeLogTopic(CShfeFtdcRtnTradeLogField *pRtnTradeLog);

        virtual void OnRspQryParticipantInitTopic(CShfeFtdcRspQryParticipantInitField *pRspQryParticipantInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnParticipantInitTopic(CShfeFtdcRtnParticipantInitField *pRtnParticipantInit);

        virtual void OnRspQryUserInitTopic(CShfeFtdcRspQryUserInitField *pRspQryUserInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnUserInitTopic(CShfeFtdcRtnUserInitField *pRtnUserInit);

        virtual void OnRspQryClientInitTopic(CShfeFtdcRspQryClientInitField *pRspQryClientInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnClientInitTopic(CShfeFtdcRtnClientInitField *pRtnClientInit);

        virtual void OnRspQryTradeUserLoginInfoTopic(CShfeFtdcRspQryTradeUserLoginInfoField *pRspQryTradeUserLoginInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnTradeUserLoginInfoTopic(CShfeFtdcRtnTradeUserLoginInfoField *pRtnTradeUserLoginInfo);

        virtual void OnRspQryPartTradeTopic(CShfeFtdcRspQryPartTradeField *pRspQryPartTrade, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryTradepeakTopic(CShfeFtdcRspQryTradepeakField *pRspQryTradepeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnUpdateSysConfigTopic(CShfeFtdcRtnUpdateSysConfigField *pRtnUpdateSysConfig);

        virtual void OnRtnSysUser(CShfeFtdcRtnSysUserField *pRtnSysUser);

        virtual void OnRspQryHistoryCpuInfoTopic(CShfeFtdcRspQryHistoryCpuInfoField *pRspQryHistoryCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryHistoryMemInfoTopic(CShfeFtdcRspQryHistoryMemInfoField *pRspQryHistoryMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryHistoryNetworkInfoTopic(CShfeFtdcRspQryHistoryNetworkInfoField *pRspQryHistoryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryMonitorOnlineUser(CShfeFtdcRspQryMonitorOnlineUserField *pRspQryMonitorOnlineUser, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryFrontStatTopic(CShfeFtdcRspQryFrontStatField *pRspQryFrontStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnSysTimeSyncTopic(CShfeFtdcRtnSysTimeSyncField *pRtnSysTimeSync);

        virtual void OnRtnDataCenterChgTopic(CShfeFtdcRtnDataCenterChgField *pRtnDataCenterChg);

        virtual void OnRspQryHistoryTradePeakTopic(CShfeFtdcRspQryHistoryTradePeakField *pRspQryHistoryTradePeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryJDBCInfoTopic(CShfeFtdcRspQryJDBCInfoField *pRspQryJDBCInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryThreadInfoTopic(CShfeFtdcRspQryThreadInfoField *pRspQryThreadInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQrySessionInfoTopic(CShfeFtdcRspQrySessionInfoField *pRspQrySessionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryServletInfoTopic(CShfeFtdcRspQryServletInfoField *pRspQryServletInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryFileInfoTopic(CShfeFtdcRspQryFileInfoField *pRspQryFileInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryWebAppInfoTopic(CShfeFtdcRspQryWebAppInfoField *pRspQryWebAppInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryVMInfoTopic(CShfeFtdcRspQryVMInfoField *pRspQryVMInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryPropertyInfoTopic(CShfeFtdcRspQryPropertyInfoField *pRspQryPropertyInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryMemPoolInfoTopic(CShfeFtdcRspQryMemPoolInfoField *pRspQryMemPoolInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryFileContentInfoTopic(CShfeFtdcRspQryFileContentInfoField *pRspQryFileContentInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryConnectionInfoTopic(CShfeFtdcRspQryConnectionInfoField *pRspQryConnectionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryConnectorInfoTopic(CShfeFtdcRspQryConnectorInfoField *pRspQryConnectorInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnVMInfoTopic(CShfeFtdcRtnVMInfoField *pRtnVMInfo);

        virtual void OnRtnPropertyInfoTopic(CShfeFtdcRtnPropertyInfoField *pRtnPropertyInfo);

        virtual void OnRtnMemPoolInfoTopic(CShfeFtdcRtnMemPoolInfoField *pRtnMemPoolInfo);

        virtual void OnRtnFileContentInfoTopic(CShfeFtdcRtnFileContentInfoField *pRtnFileContentInfo);

        virtual void OnRtnConnectionInfoTopic(CShfeFtdcRtnConnectionInfoField *pRtnConnectionInfo);

        virtual void OnRtnConnectorInfoTopic(CShfeFtdcRtnConnectorInfoField *pRtnConnectorInfo);

        virtual void OnRtnJDBCInfoTopic(CShfeFtdcRtnJDBCInfoField *pRtnJDBCInfo);

        virtual void OnRtnThreadInfoTopic(CShfeFtdcRtnThreadInfoField *pRtnThreadInfo);

        virtual void OnRtnSessionInfoTopic(CShfeFtdcRtnSessionInfoField *pRtnSessionInfo);

        virtual void OnRtnServletInfoTopic(CShfeFtdcRtnServletInfoField *pRtnServletInfo);

        virtual void OnRtnFileInfoTopic(CShfeFtdcRtnFileInfoField *pRtnFileInfo);

        virtual void OnRtnWebAppInfoTopic(CShfeFtdcRtnWebAppInfoField *pRtnWebAppInfo);

        virtual void OnRspQryDBQueryTopic(CShfeFtdcRspQryDBQueryField *pRspQryDBQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnDBQueryTopic(CShfeFtdcRtnDBQueryField *pRtnDBQuery);

        virtual void OnRspQryGeneralFieldTopic(CShfeFtdcSysGeneralFieldField *pSysGeneralField, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnGeneralFieldTopic(CShfeFtdcSysGeneralFieldField *pSysGeneralField);

        virtual void OnRspQryGetFileTopic(CShfeFtdcRspQryGetFileField *pRspQryGetFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryWarningQueryTopic(CShfeFtdcRspQryWarningQueryField *pRspQryWarningQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnWarningActiveChange(CShfeFtdcRtnWarningActiveChangeField *pRtnWarningActiveChange);

        virtual void OnRspQryTradeUserLoginStatTopic(CShfeFtdcRspQryTradeUserLoginStatField *pRspQryTradeUserLoginStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryGeneralOperateTopic(CShfeFtdcRspQryGeneralOperateField *pRspQryGeneralOperate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnGeneralOperateTopic(CShfeFtdcRtnGeneralOperateField *pRtnGeneralOperate);

        virtual void OnRspQryNetDeviceLinkedTopic(CShfeFtdcRspQryNetDeviceLinkedField *pRspQryNetDeviceLinked, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetDeviceLinkedTopic(CShfeFtdcRtnNetDeviceLinkedField *pRtnNetDeviceLinked);

        virtual void OnRspQryNetAreaTopic(CShfeFtdcRspQryNetAreaField *pRspQryNetArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetAreaTopic(CShfeFtdcRtnNetAreaField *pRtnNetArea);

        virtual void OnRspQryNetSubAreaTopic(CShfeFtdcRspQryNetSubAreaField *pRspQryNetSubArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetSubAreaTopic(CShfeFtdcRtnNetSubAreaField *pRtnNetSubArea);

        virtual void OnRspQryNetSubAreaIPTopic(CShfeFtdcRspQryNetSubAreaIPField *pRspQryNetSubAreaIP, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetSubAreaIPTopic(CShfeFtdcRtnNetSubAreaIPField *pRtnNetSubAreaIP);

        virtual void OnRspQryNetDeviceDetectTopic(CShfeFtdcRspQryNetDeviceDetectField *pRspQryNetDeviceDetect, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetDeviceTopic(CShfeFtdcRtnNetDeviceField *pRtnNetDevice);

        virtual void OnRspQryNetDeviceTopic(CShfeFtdcRspQryNetDeviceField *pRspQryNetDevice, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryNetBuildingTopic(CShfeFtdcRspQryNetBuildingField *pRspQryNetBuilding, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetBuildingTopic(CShfeFtdcRtnNetBuildingField *pRtnNetBuilding);

        virtual void OnRspQryNetRoomTopic(CShfeFtdcRspQryNetRoomField *pRspQryNetRoom, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetRoomTopic(CShfeFtdcRtnNetRoomField *pRtnNetRoom);

        virtual void OnRspQryNetCabinetsTopic(CShfeFtdcRspQryNetCabinetsField *pRspQryNetCabinets, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetCabinetsTopic(CShfeFtdcRtnNetCabinetsField *pRtnNetCabinets);

        virtual void OnRspQryNetOIDTopic(CShfeFtdcRspQryNetOIDField *pRspQryNetOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetOIDTopic(CShfeFtdcRtnNetOIDField *pRtnNetOID);

        virtual void OnRspQryNetTimePolicyTopic(CShfeFtdcRspQryNetTimePolicyField *pRspQryNetTimePolicy, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetTimePolicyTopic(CShfeFtdcRtnNetTimePolicyField *pRtnNetTimePolicy);

        virtual void OnRspQryNetGatherTaskTopic(CShfeFtdcRspQryNetGatherTaskField *pRspQryNetGatherTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetGatherTaskTopic(CShfeFtdcRtnNetGatherTaskField *pRtnNetGatherTask);

        virtual void OnRspQryNetDeviceChgTopic(CShfeFtdcRspQryNetDeviceChgField *pRspQryNetDeviceChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetDeviceChgTopic(CShfeFtdcRtnNetDeviceChgField *pRtnNetDeviceChg);

        virtual void OnRspQryNetDeviceTypeTopic(CShfeFtdcRspQryNetDeviceTypeField *pRspQryNetDeviceType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetDeviceTypeTopic(CShfeFtdcRtnNetDeviceTypeField *pRtnNetDeviceType);

        virtual void OnRspQryNetDeviceCategoryTopic(CShfeFtdcRspQryNetDeviceCategoryField *pRspQryNetDeviceCategory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetDeviceCategoryTopic(CShfeFtdcRtnNetDeviceCategoryField *pRtnNetDeviceCategory);

        virtual void OnRspQryNetManufactoryTopic(CShfeFtdcRspQryNetManufactoryField *pRspQryNetManufactory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetManufactoryTopic(CShfeFtdcRtnNetManufactoryField *pRtnNetManufactory);

        virtual void OnRspQryNetCommunityTopic(CShfeFtdcRspQryNetCommunityField *pRspQryNetCommunity, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetCommunityTopic(CShfeFtdcRtnNetCommunityField *pRtnNetCommunity);

        virtual void OnRspQryNetPortTypeTopic(CShfeFtdcRspQryNetPortTypeField *pRspQryNetPortType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetPortTypeTopic(CShfeFtdcRtnNetPortTypeField *pRtnNetPortType);

        virtual void OnRspQryNetPartAccessSpotTopic(CShfeFtdcRspQryNetPartAccessSpotField *pRspQryNetPartAccessSpot, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetPartAccessSpotTopic(CShfeFtdcRtnNetPartAccessSpotField *pRtnNetPartAccessSpot);

        virtual void OnRspQryNetInterfaceTopic(CShfeFtdcRspQryNetInterfaceField *pRspQryNetInterface, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetInterfaceTopic(CShfeFtdcRtnNetInterfaceField *pRtnNetInterface);

        virtual void OnRspQryNetGeneralOIDTopic(CShfeFtdcRspQryNetGeneralOIDField *pRspQryNetGeneralOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetGeneralOIDTopic(CShfeFtdcRtnNetGeneralOIDField *pRtnNetGeneralOID);

        virtual void OnRspQryNetMonitorTypeTopic(CShfeFtdcRspQryNetMonitorTypeField *pRspQryNetMonitorType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetMonitorTypeTopic(CShfeFtdcRtnNetMonitorTypeField *pRtnNetMonitorType);

        virtual void OnRspQryNetMonitorAttrScopeTopic(CShfeFtdcRspQryNetMonitorAttrScopeField *pRspQryNetMonitorAttrScope, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetMonitorAttrScopeTopic(CShfeFtdcRtnNetMonitorAttrScopeField *pRtnNetMonitorAttrScope);

        virtual void OnRspQryNetMonitorAttrTypeTopic(CShfeFtdcRspQryNetMonitorAttrTypeField *pRspQryNetMonitorAttrType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetMonitorAttrTypeTopic(CShfeFtdcRtnNetMonitorAttrTypeField *pRtnNetMonitorAttrType);

        virtual void OnRspQryNetMonitorObjectAttrTopic(CShfeFtdcRspQryNetMonitorObjectAttrField *pRspQryNetMonitorObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetMonitorObjectAttrTopic(CShfeFtdcRtnNetMonitorObjectAttrField *pRtnNetMonitorObjectAttr);

        virtual void OnRspQryNetMonitorTaskResultTopic(CShfeFtdcRspQryNetMonitorTaskResultField *pRspQryNetMonitorTaskResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetMonitorTaskResultTopic(CShfeFtdcRtnNetMonitorTaskResultField *pRtnNetMonitorTaskResult);

        virtual void OnRspQryNetMonitorDeviceGroupTopic(CShfeFtdcRspQryNetMonitorDeviceGroupField *pRspQryNetMonitorDeviceGroup, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetMonitorDeviceGroupTopic(CShfeFtdcRtnNetMonitorDeviceGroupField *pRtnNetMonitorDeviceGroup);

        virtual void OnRspQryNetMonitorTaskObjectSetTopic(CShfeFtdcRspQryNetMonitorTaskObjectSetField *pRspQryNetMonitorTaskObjectSet, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetMonitorTaskObjectSetTopic(CShfeFtdcRtnNetMonitorTaskObjectSetField *pRtnNetMonitorTaskObjectSet);

        virtual void OnRspQryNetMonitorTaskInfoTopic(CShfeFtdcRspQryNetMonitorTaskInfoField *pRspQryNetMonitorTaskInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetMonitorTaskInfoTopic(CShfeFtdcRtnNetMonitorTaskInfoField *pRtnNetMonitorTaskInfo);

        virtual void OnRspQryNetPartyLinkInfoTopic(CShfeFtdcRspQryNetPartyLinkInfoField *pRspQryNetPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetPartyLinkInfoTopic(CShfeFtdcRtnNetPartyLinkInfoField *pRtnNetPartyLinkInfo);

        virtual void OnRspQryNetMonitorActionAttrTopic(CShfeFtdcRspQryNetMonitorActionAttrField *pRspQryNetMonitorActionAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetMonitorActionAttrTopic(CShfeFtdcRtnNetMonitorActionAttrField *pRtnNetMonitorActionAttr);

        virtual void OnRspQryNetModuleTopic(CShfeFtdcRspQryNetModuleField *pRspQryNetModule, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetModuleTopic(CShfeFtdcRtnNetModuleField *pRtnNetModule);

        virtual void OnRspQryNetMonitorTaskStatusResultTopic(CShfeFtdcRspQryNetMonitorTaskStatusResultField *pRspQryNetMonitorTaskStatusResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetMonitorTaskStatusResultTopic(CShfeFtdcRtnNetMonitorTaskStatusResultField *pRtnNetMonitorTaskStatusResult);

        virtual void OnRspQryNetCfgFileTopic(CShfeFtdcRspQryNetCfgFileField *pRspQryNetCfgFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetCfgFileTopic(CShfeFtdcRtnNetCfgFileField *pRtnNetCfgFile);

        virtual void OnRspQryFileGeneralOperTopic(CShfeFtdcRspQryFileGeneralOperField *pRspQryFileGeneralOper, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnFileGeneralOperTopic(CShfeFtdcRtnFileGeneralOperField *pRtnFileGeneralOper);

        virtual void OnRspQryNetPartyLinkStatusInfoTopic(CShfeFtdcRspQryNetPartyLinkStatusInfoField *pRspQryNetPartyLinkStatusInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetPartyLinkStatusInfoTopic(CShfeFtdcRtnNetPartyLinkStatusInfoField *pRtnNetPartyLinkStatusInfo);

        virtual void OnRspQryNetBaseLineTopic(CShfeFtdcRspQryNetBaseLineField *pRspQryNetBaseLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetBaseLineTopic(CShfeFtdcRtnNetBaseLineField *pRtnNetBaseLine);

        virtual void OnRspQryNetBaseLineResultTopic(CShfeFtdcRspQryNetBaseLineResultField *pRspQryNetBaseLineResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetBaseLineResultTopic(CShfeFtdcRtnNetBaseLineResultField *pRtnNetBaseLineResult);

        virtual void OnRspQryNetMonitorDeviceTaskTopic(CShfeFtdcRspQryNetMonitorDeviceTaskField *pRspQryNetMonitorDeviceTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetMonitorDeviceTaskTopic(CShfeFtdcRtnNetMonitorDeviceTaskField *pRtnNetMonitorDeviceTask);

        virtual void OnRspQryNetLocalPingResultInfoTopic(CShfeFtdcRspQryNetLocalPingResultInfoField *pRspQryNetLocalPingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetLocalPingResultInfoTopic(CShfeFtdcRtnNetLocalPingResultInfoField *pRtnNetLocalPingResultInfo);

        virtual void OnRspQryNetRomotePingResultInfoTopic(CShfeFtdcRspQryNetRomotePingResultInfoField *pRspQryNetRomotePingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetRomotePingResultInfoTopic(CShfeFtdcRtnNetRomotePingResultInfoField *pRtnNetRomotePingResultInfo);

        virtual void OnRspQryTradeFrontOrderRttStatTopic(CShfeFtdcRspQryTradeFrontOrderRttStatField *pRspQryTradeFrontOrderRttStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnTradeFrontOrderRttStatTopic(CShfeFtdcRtnTradeFrontOrderRttStatField *pRtnTradeFrontOrderRttStat);

        virtual void OnRspQryDiskIOTopic(CShfeFtdcRspQryDiskIOField *pRspQryDiskIO, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnDiskIOTopic(CShfeFtdcRtnDiskIOField *pRtnDiskIO);

        virtual void OnRspQryRouterInfoTopic(CShfeFtdcRspQryRouterInfoField *pRspQryRouterInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnRouterInfoTopic(CShfeFtdcRtnRouterInfoField *pRtnRouterInfo);

        virtual void OnRspQryStatInfoTopic(CShfeFtdcRspQryStatInfoField *pRspQryStatInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnStatInfoTopic(CShfeFtdcRtnStatInfoField *pRtnStatInfo);

        virtual void OnRspQryClientInfoTopic(CShfeFtdcRspQryClientInfoField *pRspQryClientInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnClientInfoTopic(CShfeFtdcRtnClientInfoField *pRtnClientInfo);

        virtual void OnRspQryParticTradeOrderStatesTopic(CShfeFtdcRspQryParticTradeOrderStatesField *pRspQryParticTradeOrderStates, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnParticTradeOrderStatesTopic(CShfeFtdcRtnParticTradeOrderStatesField *pRtnParticTradeOrderStates);

        virtual void OnRspQryTradeOrderRttCutLineTopic(CShfeFtdcRspQryTradeOrderRttCutLineField *pRspQryTradeOrderRttCutLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnTradeOrderRttCutLineTopic(CShfeFtdcRtnTradeOrderRttCutLineField *pRtnTradeOrderRttCutLine);

        virtual void OnRspQryEventDescriptionTopic(CShfeFtdcRspQryEventDescriptionField *pRspQryEventDescription, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnEventDescriptionTopic(CShfeFtdcRtnEventDescriptionField *pRtnEventDescription);

        virtual void OnRspQryFrontUniqueIDTopic(CShfeFtdcRspQryFrontUniqueIDField *pRspQryFrontUniqueID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnFrontUniqueIDTopic(CShfeFtdcRtnFrontUniqueIDField *pRtnFrontUniqueID);

        virtual void OnRspQryNetPartyLinkAddrChangeTopic(CShfeFtdcRspQryNetPartyLinkAddrChangeField *pRspQryNetPartyLinkAddrChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetPartyLinkAddrChangeTopic(CShfeFtdcRtnNetPartyLinkAddrChangeField *pRtnNetPartyLinkAddrChange);

        virtual void OnRspQryNetDelPartyLinkInfoTopic(CShfeFtdcRspQryNetDelPartyLinkInfoField *pRspQryNetDelPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetDelPartyLinkInfoTopic(CShfeFtdcRtnNetDelPartyLinkInfoField *pRtnNetDelPartyLinkInfo);

        virtual void OnRspQryInstrumentStatusTopic(CShfeFtdcRspQryInstrumentStatusField *pRspQryInstrumentStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnInstrumentStatusTopic(CShfeFtdcRtnInstrumentStatusField *pRtnInstrumentStatus);

        virtual void OnRspQryCurrTradingSegmentAttrTopic(CShfeFtdcRspQryCurrTradingSegmentAttrField *pRspQryCurrTradingSegmentAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnCurrTradingSegmentAttrTopic(CShfeFtdcRtnCurrTradingSegmentAttrField *pRtnCurrTradingSegmentAttr);

        virtual void OnRspQryPerformanceTopTopic(CShfeFtdcRspQryPerformanceTopField *pRspQryPerformanceTop, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnPerformanceTopTopic(CShfeFtdcRtnPerformanceTopField *pRtnPerformanceTop);

        virtual void OnRspQryNetNonPartyLinkInfoTopic(CShfeFtdcRspQryNetNonPartyLinkInfoField *pRspQryNetNonPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnNetNonPartyLinkInfoTopic(CShfeFtdcRtnNetNonPartyLinkInfoField *pRtnNetNonPartyLinkInfo);

        virtual void OnRspQryMonConfigInfo(CShfeFtdcRspQryMonConfigInfoField *pRspQryMonConfigInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonConfigInfo(CShfeFtdcRtnMonConfigInfoField *pRtnMonConfigInfo);

        virtual void OnRtnMonitorDayInfo(CShfeFtdcMonitorDayInfoField *pMonitorDayInfo);

        virtual void OnRtnTradingDayInfo(CShfeFtdcTradingDayInfoField *pTradingDayInfo);

        virtual void OnRtnSectionFinish(CShfeFtdcMonitorSectionField *pMonitorSection);

        virtual void OnRtnSectionChange(CShfeFtdcMonitorSectionField *pMonitorSection);

        virtual void OnRspMonServiceConnect(CShfeFtdcRspMonServiceConnectField *pRspMonServiceConnect, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonProxyConfig(CShfeFtdcRtnMonProxyConfigField *pRtnMonProxyConfig);

        virtual void OnRspQryMonServiceStatus(CShfeFtdcRspQryMonServiceStatusField *pRspQryMonServiceStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonServiceStatus(CShfeFtdcRtnMonServiceStatusField *pRtnMonServiceStatus);

        virtual void OnRtnMonDataCenterRole(CShfeFtdcRtnMonDataCenterRoleField *pRtnMonDataCenterRole);

        virtual void OnRspQryMonProbeTask(CShfeFtdcRspQryMonProbeTaskField *pRspQryMonProbeTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonProbeTask(CShfeFtdcRtnMonProbeTaskField *pRtnMonProbeTask);

        virtual void OnRspQryMonObjectAttr(CShfeFtdcRspQryMonObjectAttrField *pRspQryMonObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonObjectAttr(CShfeFtdcRtnMonObjectAttrField *pRtnMonObjectAttr);

        virtual void OnRspQryMonSyslogEvent(CShfeFtdcRspQryMonSyslogEventField *pRspQryMonSyslogEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonSyslogEvent(CShfeFtdcRtnMonSyslogEventField *pRtnMonSyslogEvent);

        virtual void OnRspQryMonFileOffset(CShfeFtdcRspQryMonFileOffsetField *pRspQryMonFileOffset, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonFileOffset(CShfeFtdcRtnMonFileOffsetField *pRtnMonFileOffset);

        virtual void OnRspQryMonFileContent(CShfeFtdcRspQryMonFileContentField *pRspQryMonFileContent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonFileContent(CShfeFtdcRtnMonFileContentField *pRtnMonFileContent);

        virtual void OnRspQryMonHostCPUAttr(CShfeFtdcRspQryMonHostCPUAttrField *pRspQryMonHostCPUAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonHostCPUAttr(CShfeFtdcRtnMonHostCPUAttrField *pRtnMonHostCPUAttr);

        virtual void OnRspQryMonHostMemAttr(CShfeFtdcRspQryMonHostMemAttrField *pRspQryMonHostMemAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonHostMemAttr(CShfeFtdcRtnMonHostMemAttrField *pRtnMonHostMemAttr);

        virtual void OnRtnMonHostFileSystemAttr(CShfeFtdcRtnMonHostFileSystemAttrField *pRtnMonHostFileSystemAttr);

        virtual void OnRtnMonHostUserInfo(CShfeFtdcRtnMonHostUserInfoField *pRtnMonHostUserInfo);

        virtual void OnRtnMonHostOnlineUserInfo(CShfeFtdcRtnMonHostOnlineUserInfoField *pRtnMonHostOnlineUserInfo);

        virtual void OnRspQryMonHostNetworkAttr(CShfeFtdcRspQryMonHostNetworkAttrField *pRspQryMonHostNetworkAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonHostNetworkAttr(CShfeFtdcRtnMonHostNetworkAttrField *pRtnMonHostNetworkAttr);

        virtual void OnRspQryMonHostStatInfo(CShfeFtdcRspQryMonHostStatInfoField *pRspQryMonHostStatInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonHostStatInfo(CShfeFtdcRtnMonHostStatInfoField *pRtnMonHostStatInfo);

        virtual void OnRtnMonHostDiskIOAttr(CShfeFtdcRtnMonHostDiskIOAttrField *pRtnMonHostDiskIOAttr);

        virtual void OnRspQryMonHostRouterInfo(CShfeFtdcRspQryMonHostRouterInfoField *pRspQryMonHostRouterInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonHostRouterInfo(CShfeFtdcRtnMonHostRouterInfoField *pRtnMonHostRouterInfo);

        virtual void OnRspQryMonHostProcessInfo(CShfeFtdcRspQryMonHostProcessInfoField *pRspQryMonHostProcessInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonHostProcessInfo(CShfeFtdcRtnMonHostProcessInfoField *pRtnMonHostProcessInfo);

        virtual void OnRtnMonDBQuery(CShfeFtdcRtnMonDBQueryField *pRtnMonDBQuery);

        virtual void OnRspQryMonSPQuery(CShfeFtdcRtnMonDBQueryField *pRtnMonDBQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspServiceVersion(CShfeFtdcRspServiceVersionField *pRspServiceVersion, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspServiceProgram(CShfeFtdcRspServiceProgramField *pRspServiceProgram, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspUpdateState(CShfeFtdcRspUpdateStateField *pRspUpdateState, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRspQryMonHostBasicEnv(CShfeFtdcRspQryMonHostBasicEnvField *pRspQryMonHostBasicEnv, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonHostBasicEnv(CShfeFtdcRtnMonHostBasicEnvField *pRtnMonHostBasicEnv);

        virtual void OnRspQryMonHostNetworkEnv(CShfeFtdcRspQryMonHostNetworkEnvField *pRspQryMonHostNetworkEnv, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonHostNetworkEnv(CShfeFtdcRtnMonHostNetworkEnvField *pRtnMonHostNetworkEnv);

        virtual void OnRspQryMonHostFileSysEnv(CShfeFtdcRspQryMonHostFileSysEnvField *pRspQryMonHostFileSysEnv, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonHostFileSysEnv(CShfeFtdcRtnMonHostFileSysEnvField *pRtnMonHostFileSysEnv);

        virtual void OnRspQryMonHostSwapEnv(CShfeFtdcRspQryMonHostSwapEnvField *pRspQryMonHostSwapEnv, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonHostSwapEnv(CShfeFtdcRtnMonHostSwapEnvField *pRtnMonHostSwapEnv);

        virtual void OnRspQryMonitor2ObjectTopic(CShfeFtdcRspQryMonitor2ObjectField *pRspQryMonitor2Object, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonitor2ObjectTopic(CShfeFtdcRtnMonitor2ObjectField *pRtnMonitor2Object);

        virtual void OnRspQryMonHostCommonEnvTopic(CShfeFtdcRspQryMonHostCommonEnvField *pRspQryMonHostCommonEnv, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonHostCommonEnvTopic(CShfeFtdcRtnMonHostCommonEnvField *pRtnMonHostCommonEnv);

        virtual void OnRspQryMonOidHostRationalTopic(CShfeFtdcRspQryMonOidHostRationalField *pRspQryMonOidHostRational, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonOidHostRationalTopic(CShfeFtdcRtnMonOidHostRationalField *pRtnMonOidHostRational);

        virtual void OnRspQryMonOidRelationTopic(CShfeFtdcRspQryMonOidRelationField *pRspQryMonOidRelation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

        virtual void OnRtnMonOidRelationTopic(CShfeFtdcRtnMonOidRelationField *pRtnMonOidRelation);

}; 

#endif