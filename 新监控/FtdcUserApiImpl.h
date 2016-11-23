/////////////////////////////////////////////////////////////////////////
///@system ��һ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file FtdcUserApiImpl.h
///@brief �����˿ͻ��˽ӿ�ʵ��
///@history 
///20060106	�Ժ��		�������ļ�
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCUSERAPIIMPL_H)
#define _FTDCUSERAPIIMPL_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FtdcUserApiImplBase.h"

class CFtdcUserApiImpl : public CFtdcUserApiImplBase
{
public:	
	CFtdcUserApiImpl(const char *pszFlowPath, const char *pszUserApiType, CSelectReactor *pReactor);
	virtual void HandleResponse(CFTDCPackage *pMessage, WORD nSequenceSeries);

	///�û��˳�����
	virtual int ReqUserLogout(CShfeFtdcReqUserLogoutField *pReqUserLogout, int nRequestID);

	///����¼������
	virtual int ReqOrderInsert(CShfeFtdcInputOrderField *pInputOrder, int nRequestID);

	///������������
	virtual int ReqOrderAction(CShfeFtdcOrderActionField *pOrderAction, int nRequestID);

	///����¼������
	virtual int ReqQuoteInsert(CShfeFtdcInputQuoteField *pInputQuote, int nRequestID);

	///���۲�������
	virtual int ReqQuoteAction(CShfeFtdcQuoteActionField *pQuoteAction, int nRequestID);

	///OTC����¼������
	virtual int ReqOTCOrderInsert(CShfeFtdcOTCOrderField *pOTCOrder, int nRequestID);

	///�û������޸�����
	virtual int ReqUserPasswordUpdate(CShfeFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID);

	///ִ������¼������
	virtual int ReqExecOrderInsert(CShfeFtdcInputExecOrderField *pInputExecOrder, int nRequestID);

	///ִ�������������
	virtual int ReqExecOrderAction(CShfeFtdcExecOrderActionField *pExecOrderAction, int nRequestID);

	///������¼������
	virtual int ReqAdminOrderInsert(CShfeFtdcInputAdminOrderField *pInputAdminOrder, int nRequestID);

	///�Ǳ���ϱ���¼������
	virtual int ReqCombOrderInsert(CShfeFtdcInputCombOrderField *pInputCombOrder, int nRequestID);

	///������������
	virtual int ReqSubscribeTopic(CShfeFtdcDisseminationField *pDissemination, int nRequestID);

	///��������������
	virtual int ReqBulletin(CShfeFtdcBulletinField *pBulletin, int nRequestID);

	///��������Ϣ����
	virtual int ReqInformation(CShfeFtdcInformationField *pInformation, int nRequestID);

	///��Լ����״̬�ı�����
	virtual int ReqInstrumentStatusUpdate(CShfeFtdcInstrumentStatusField *pInstrumentStatus, int nRequestID);

	///ǿ���û��˳�����
	virtual int ReqForceUserExit(CShfeFtdcForceUserExitField *pForceUserExit, int nRequestID);

	///�û��Ựɾ������
	virtual int ReqForceUserLogout(CShfeFtdcForceUserExitField *pForceUserExit, int nRequestID);

	///����������ͬ��״̬�ı�����
	virtual int ReqExchangeDataSyncStatusUpdate(CShfeFtdcExchangeDataSyncStatusField *pExchangeDataSyncStatus, int nRequestID);

	///����������ͬ��״̬�ı�����
	virtual int ReqSGDataSyncStatusUpdate(CShfeFtdcSGDataSyncStatusField *pSGDataSyncStatus, int nRequestID);

	///��Ա�ʽ��ѯ����
	virtual int ReqQryPartAccount(CShfeFtdcQryPartAccountField *pQryPartAccount, int nRequestID);

	///������ѯ����
	virtual int ReqQryOrder(CShfeFtdcQryOrderField *pQryOrder, int nRequestID);

	///���۲�ѯ����
	virtual int ReqQryQuote(CShfeFtdcQryQuoteField *pQryQuote, int nRequestID);

	///�ɽ�����ѯ����
	virtual int ReqQryTrade(CShfeFtdcQryTradeField *pQryTrade, int nRequestID);

	///��Ա�ͻ���ѯ����
	virtual int ReqQryClient(CShfeFtdcQryClientField *pQryClient, int nRequestID);

	///��Ա�ֲֲ�ѯ����
	virtual int ReqQryPartPosition(CShfeFtdcQryPartPositionField *pQryPartPosition, int nRequestID);

	///�ͻ��ֲֲ�ѯ����
	virtual int ReqQryClientPosition(CShfeFtdcQryClientPositionField *pQryClientPosition, int nRequestID);

	///��Լ��ѯ����
	virtual int ReqQryInstrument(CShfeFtdcQryInstrumentField *pQryInstrument, int nRequestID);

	///��Լ����״̬��ѯ����
	virtual int ReqQryInstrumentStatus(CShfeFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID);

	///������״̬��ѯ����
	virtual int ReqQrySGDataSyncStatus(CShfeFtdcQrySGDataSyncStatusField *pQrySGDataSyncStatus, int nRequestID);

	///��ֵ��Ȳ�ѯ
	virtual int ReqQryHedgeVolume(CShfeFtdcQryHedgeVolumeField *pQryHedgeVolume, int nRequestID);

	///�����޶��ѯ����
	virtual int ReqQryCreditLimit(CShfeFtdcQryCreditLimitField *pQryCreditLimit, int nRequestID);

	///�Ǳ���ϱ�����ѯ����
	virtual int ReqQryCombOrder(CShfeFtdcQryCombOrderField *pQryCombOrder, int nRequestID);

	///ִ�������ѯ����
	virtual int ReqQryExecOrder(CShfeFtdcQryExecOrderField *pQryExecOrder, int nRequestID);

	///��ͨ�����ѯ����
	virtual int ReqQryMarketData(CShfeFtdcQryMarketDataField *pQryMarketData, int nRequestID);

	///�����������ѯ����
	virtual int ReqQryBulletin(CShfeFtdcQryBulletinField *pQryBulletin, int nRequestID);

	///�����ѯ����
	virtual int ReqQryTopic(CShfeFtdcDisseminationField *pDissemination, int nRequestID);

	///�û����߲�ѯ����
	virtual int ReqQryUserSession(CShfeFtdcQryUserSessionField *pQryUserSession, int nRequestID);

	///�û���ѯ����
	virtual int ReqQryUser(CShfeFtdcQryUserField *pQryUser, int nRequestID);

	///��Ա��ѯ����
	virtual int ReqQryParticipant(CShfeFtdcQryParticipantField *pQryParticipant, int nRequestID);

	///��Լ��λ��ѯ
	virtual int ReqQryMBLMarketData(CShfeFtdcQryMBLMarketDataField *pQryMBLMarketData, int nRequestID);

	///��Ϣ��ѯ
	virtual int ReqQryInformation(CShfeFtdcQryInformationField *pQryInformation, int nRequestID);

	///�ͻ��ֲֲ�ѯ����
	virtual int ReqQryClientPositionV1(CShfeFtdcQryClientPositionV1Field *pQryClientPositionV1, int nRequestID);

	///���ʲ�ѯ����
	virtual int ReqQryExchangeRate(CShfeFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID);

	///CPU��ѯ
	virtual int ReqQryTopCpuInfoTopic(CShfeFtdcReqQryTopCpuInfoField *pReqQryTopCpuInfo, int nRequestID);

	///Mem��ѯ
	virtual int ReqQryTopMemInfoTopic(CShfeFtdcReqQryTopMemInfoField *pReqQryTopMemInfo, int nRequestID);

	///process��ѯ
	virtual int ReqQryTopProcessInfoTopic(CShfeFtdcReqQryTopProcessInfoField *pReqQryTopProcessInfo, int nRequestID);

	///filesystem��ѯ
	virtual int ReqQryFileSystemInfoTopic(CShfeFtdcReqQryFileSystemInfoField *pReqQryFileSystemInfo, int nRequestID);

	///network��ѯ
	virtual int ReqQryNetworkInfoTopic(CShfeFtdcReqQryNetworkInfoField *pReqQryNetworkInfo, int nRequestID);

	///����������Ϣ��ѯ
	virtual int ReqQryHostEnvTopic(CShfeFtdcReqQryHostEnvField *pReqQryHostEnv, int nRequestID);

	///�ͻ��˵�¼��ѯ
	virtual int ReqQryClientLoginTopic(CShfeFtdcReqQryClientLoginField *pReqQryClientLogin, int nRequestID);

	///��ü�ض�����Ϣ��ѯ
	virtual int ReqQryMonitorObjectTopic(CShfeFtdcReqQryMonitorObjectField *pReqQryMonitorObject, int nRequestID);

	///���ҵ����̺������Ķ�Ӧ��ϵ��ѯ
	virtual int ReqQryObjectRationalTopic(CShfeFtdcReqQryObjectRationalField *pReqQryObjectRational, int nRequestID);

	///��־�ļ����ݲ�ѯ
	virtual int ReqQrySyslogInfoTopic(CShfeFtdcReqQrySyslogInfoField *pReqQrySyslogInfo, int nRequestID);

	///������ݶ�������
	virtual int ReqQrySubscriberTopic(CShfeFtdcReqQrySubscriberField *pReqQrySubscriber, int nRequestID);

	///�����ϵ��ѯ
	virtual int ReqQryOidRelationTopic(CShfeFtdcReqQryOidRelationField *pReqQryOidRelation, int nRequestID);

	///�û���Ϣ��ѯ����
	virtual int ReqQryUserInfoTopic(CShfeFtdcReqQryUserInfoField *pReqQryUserInfo, int nRequestID);

	///�����û���Ϣ��ѯ����
	virtual int ReqQryOnlineUserInfoTopic(CShfeFtdcReqQryOnlineUserInfoField *pReqQryOnlineUserInfo, int nRequestID);

	///�澯�¼���ѯ����
	virtual int ReqQryWarningEventTopic(CShfeFtdcReqQryWarningEventField *pReqQryWarningEvent, int nRequestID);

	///CPUʹ���ʲ�ѯ����
	virtual int ReqQryCPUUsageTopic(CShfeFtdcReqQryCPUUsageField *pReqQryCPUUsage, int nRequestID);

	///�ڴ�ʹ���ʲ�ѯ����
	virtual int ReqQryMemoryUsageTopic(CShfeFtdcReqQryMemoryUsageField *pReqQryMemoryUsage, int nRequestID);

	///Ӳ��ʹ���ʲ�ѯ����
	virtual int ReqQryDiskUsageTopic(CShfeFtdcReqQryDiskUsageField *pReqQryDiskUsage, int nRequestID);

	///����״ָ̬���ѯ
	virtual int ReqQryObjectAttrTopic(CShfeFtdcReqQryObjectAttrField *pReqQryObjectAttr, int nRequestID);

	///KeyFile��ѯ����
	virtual int ReqQryKeyFileInfoTopic(CShfeFtdcReqQryKeyFileInfoField *pReqQryKeyFileInfo, int nRequestID);

	///HostMonitorCfg��ѯ����
	virtual int ReqQryHostMonitorCfgTopic(CShfeFtdcReqQryHostMonitorCfgField *pReqQryHostMonitorCfg, int nRequestID);

	///AppMonitorCfg��ѯ����
	virtual int ReqQryAppMonitorCfgTopic(CShfeFtdcReqQryAppMonitorCfgField *pReqQryAppMonitorCfg, int nRequestID);

	///HostConfig��ѯ����
	virtual int ReqQryHostConfigTopic(CShfeFtdcReqQryHostConfigField *pReqQryHostConfig, int nRequestID);

	///��ʷ����״ָ̬���ѯ
	virtual int ReqQryHistoryObjectAttrTopic(CShfeFtdcReqQryHistoryObjectAttrField *pReqQryHistoryObjectAttr, int nRequestID);

	///ǰ����Ӧ��Ϣ��ѯ
	virtual int ReqQryFrontInfoTopic(CShfeFtdcReqQryFrontInfoField *pReqQryFrontInfo, int nRequestID);

	///�û���¼
	virtual int ReqQrySysUserLoginTopic(CShfeFtdcReqQrySysUserLoginField *pReqQrySysUserLogin, int nRequestID);

	///�û��ǳ�
	virtual int ReqQrySysUserLogoutTopic(CShfeFtdcReqQrySysUserLogoutField *pReqQrySysUserLogout, int nRequestID);

	///�û��޸�����
	virtual int ReqQrySysUserPasswordUpdateTopic(CShfeFtdcReqQrySysUserPasswordUpdateField *pReqQrySysUserPasswordUpdate, int nRequestID);

	///ע���û�
	virtual int ReqQrySysUserRegisterTopic(CShfeFtdcReqQrySysUserRegisterField *pReqQrySysUserRegister, int nRequestID);

	///ɾ���û�
	virtual int ReqQrySysUserDeleteTopic(CShfeFtdcReqQrySysUserDeleteField *pReqQrySysUserDelete, int nRequestID);

	///������־��ѯ
	virtual int ReqQryTradeLogTopic(CShfeFtdcReqQryTradeLogField *pReqQryTradeLog, int nRequestID);

	///�澯�¼��޸�
	virtual int ReqQryWarningEventUpdateTopic(CShfeFtdcReqQryWarningEventUpdateField *pReqQryWarningEventUpdate, int nRequestID);

	///���׷�ֵ��ѯ
	virtual int ReqQryTradepeakTopic(CShfeFtdcReqQryTradepeakField *pReqQryTradepeak, int nRequestID);

	///
	virtual int ReqQryHistoryCpuInfoTopic(CShfeFtdcReqQryHistoryCpuInfoField *pReqQryHistoryCpuInfo, int nRequestID);

	///
	virtual int ReqQryHistoryMemInfoTopic(CShfeFtdcReqQryHistoryMemInfoField *pReqQryHistoryMemInfo, int nRequestID);

	///
	virtual int ReqQryHistoryNetworkInfoTopic(CShfeFtdcReqQryHistoryNetworkInfoField *pReqQryHistoryNetworkInfo, int nRequestID);

	///���ϵͳ�����û���ѯ
	virtual int ReqQryMonitorOnlineUser(CShfeFtdcReqQryMonitorOnlineUserField *pReqQryMonitorOnlineUser, int nRequestID);

	///��ʷ��ֵ��ѯ
	virtual int ReqQryHistoryTradePeakTopic(CShfeFtdcReqQryHistoryTradePeakField *pReqQryHistoryTradePeak, int nRequestID);

	///��־�¼���ѯ
	virtual int ReqQrySyslogEventTopic(CShfeFtdcReqQrySyslogEventField *pReqQrySyslogEvent, int nRequestID);

	///��־�¼���������
	virtual int ReqQrySyslogEventSubcriberTopic(CShfeFtdcReqQrySyslogEventSubcriberField *pReqQrySyslogEventSubcriber, int nRequestID);

	///�������л�֪ͨ
	virtual int ReqQryTradeDayChangeTopic(CShfeFtdcReqQryTradeDayChangeField *pReqQryTradeDayChange, int nRequestID);

	///tomcat��Ϣ��ѯ
	virtual int ReqQryTomcatInfoTopic(CShfeFtdcReqQryTomcatInfoField *pReqQryTomcatInfo, int nRequestID);

	///�������Ϣ��ѯ
	virtual int ReqQryVMInfoTopic(CShfeFtdcReqQryVMInfoField *pReqQryVMInfo, int nRequestID);

	///ϵͳ������Ϣ��ѯ
	virtual int ReqQryPropertyInfoTopic(CShfeFtdcReqQryPropertyInfoField *pReqQryPropertyInfo, int nRequestID);

	///ϵͳ�ڴ����Ϣ��ѯ
	virtual int ReqQryMemPoolInfoTopic(CShfeFtdcReqQryMemPoolInfoField *pReqQryMemPoolInfo, int nRequestID);

	///�ļ�������Ϣ��ѯ
	virtual int ReqQryFileContentInfoTopic(CShfeFtdcReqQryFileContentInfoField *pReqQryFileContentInfo, int nRequestID);

	///������Ϣ��ѯ
	virtual int ReqQryConnectionInfoTopic(CShfeFtdcReqQryConnectionInfoField *pReqQryConnectionInfo, int nRequestID);

	///��������Ϣ��ѯ
	virtual int ReqQryConnectorInfoTopic(CShfeFtdcReqQryConnectorInfoField *pReqQryConnectorInfo, int nRequestID);

	///���ݿ��ѯ
	virtual int ReqQryDBQueryTopic(CShfeFtdcReqQryDBQueryField *pReqQryDBQuery, int nRequestID);

	///�ļ���������
	virtual int ReqQryGetFileTopic(CShfeFtdcReqQryGetFileField *pReqQryGetFile, int nRequestID);

	///��־�¼��޸�����
	virtual int ReqQrySyslogEventUpdateTopic(CShfeFtdcReqQrySyslogEventUpdateField *pReqQrySyslogEventUpdate, int nRequestID);

	///�澯��ϸ��ѯ
	virtual int ReqQryWarningQueryTopic(CShfeFtdcReqQryWarningQueryField *pReqQryWarningQuery, int nRequestID);

	///��վ���ʲ�ѯ
	virtual int ReqQryWebVisitTopic(CShfeFtdcReqQryWebVisitField *pReqQryWebVisit, int nRequestID);

	///�澯������
	virtual int ReqQryWarningActiveChange(CShfeFtdcReqQryWarningActiveChangeField *pReqQryWarningActiveChange, int nRequestID);

	///ͨ�ò���
	virtual int ReqQryGeneralOperateTopic(CShfeFtdcReqQryGeneralOperateField *pReqQryGeneralOperate, int nRequestID);

	///�����豸���ӹ�ϵ����
	virtual int ReqQryNetDeviceLinkedTopic(CShfeFtdcReqQryNetDeviceLinkedField *pReqQryNetDeviceLinked, int nRequestID);

	///����ϵͳ��¼��Ϣ����
	virtual int ReqQryTradeUserLoginStatTopic(CShfeFtdcReqQryTradeUserLoginStatField *pReqQryTradeUserLoginStat, int nRequestID);

	///����ϵͳǰ�ñ�����Ӧ��Ϣ
	virtual int ReqQryTradeFrontOrderRttStatTopic(CShfeFtdcReqQryTradeFrontOrderRttStatField *pReqQryTradeFrontOrderRttStat, int nRequestID);

	///ϵͳ·����Ϣ
	virtual int ReqQryRouterInfoTopic(CShfeFtdcReqQryRouterInfoField *pReqQryRouterInfo, int nRequestID);

	///����I/O��Ϣ
	virtual int ReqQryDiskIOTopic(CShfeFtdcReqQryDiskIOField *pReqQryDiskIO, int nRequestID);

	///ϵͳ״̬��Ϣ
	virtual int ReqQryStatInfoTopic(CShfeFtdcReqQryStatInfoField *pReqQryStatInfo, int nRequestID);

	///����ϵͳǰ�ñ����ֲ�����
	virtual int ReqQryTradeOrderRttCutLineTopic(CShfeFtdcReqQryTradeOrderRttCutLineField *pReqQryTradeOrderRttCutLine, int nRequestID);

	///��Ա�ͻ���Ϣ
	virtual int ReqQryClientInfoTopic(CShfeFtdcReqQryClientInfoField *pReqQryClientInfo, int nRequestID);

	///�����¼�����
	virtual int ReqQryEventDescriptionTopic(CShfeFtdcReqQryEventDescriptionField *pReqQryEventDescription, int nRequestID);

	///����ǰ��ΨһID��Ϣ
	virtual int ReqQryFrontUniqueIDTopic(CShfeFtdcReqQryFrontUniqueIDField *pReqQryFrontUniqueID, int nRequestID);

	///��Ա��·��ַ�������
	virtual int ReqQryNetPartyLinkAddrChangeTopic(CShfeFtdcReqQryNetPartyLinkAddrChangeField *pReqQryNetPartyLinkAddrChange, int nRequestID);

	///������ɾ����Ա�б���Ϣ
	virtual int ReqQryNetDelPartyLinkInfoTopic(CShfeFtdcReqQryNetDelPartyLinkInfoField *pReqQryNetDelPartyLinkInfo, int nRequestID);

	///����������������
	virtual int ReqQryPerformanceTopTopic(CShfeFtdcReqQryPerformanceTopField *pReqQryPerformanceTop, int nRequestID);

	///��������ָ���ѯ
	virtual int ReqQryRealTimeNetObjectAttrTopic(CShfeFtdcReqQryRealTimeNetObjectAttrField *pReqQryRealTimeNetObjectAttr, int nRequestID);

	///����������ֲ�ѯ
	virtual int ReqQryNetAreaTopic(CShfeFtdcReqQryNetAreaField *pReqQryNetArea, int nRequestID);

	///����������ѯ
	virtual int ReqQryNetSubAreaTopic(CShfeFtdcReqQryNetSubAreaField *pReqQryNetSubArea, int nRequestID);

	///��������IP��ѯ
	virtual int ReqQryNetSubAreaIPTopic(CShfeFtdcReqQryNetSubAreaIPField *pReqQryNetSubAreaIP, int nRequestID);

	///�����豸̽������
	virtual int ReqQryNetDeviceDetectTopic(CShfeFtdcReqQryNetDeviceDetectField *pReqQryNetDeviceDetect, int nRequestID);

	///�����豸��ѯ����
	virtual int ReqQryNetDeviceRequestTopic(CShfeFtdcReqQryNetDeviceRequestField *pReqQryNetDeviceRequest, int nRequestID);

	///��¥��ѯ
	virtual int ReqQryNetBuildingTopic(CShfeFtdcReqQryNetBuildingField *pReqQryNetBuilding, int nRequestID);

	///������ѯ
	virtual int ReqQryNetRoomTopic(CShfeFtdcReqQryNetRoomField *pReqQryNetRoom, int nRequestID);

	///�����ѯ
	virtual int ReqQryNetCabinetsTopic(CShfeFtdcReqQryNetCabinetsField *pReqQryNetCabinets, int nRequestID);

	///OID
	virtual int ReqQryNetOIDTopic(CShfeFtdcReqQryNetOIDField *pReqQryNetOID, int nRequestID);

	///ʱ�����
	virtual int ReqQryNetTimePolicyTopic(CShfeFtdcReqQryNetTimePolicyField *pReqQryNetTimePolicy, int nRequestID);

	///�ɼ������ѯ
	virtual int ReqQryNetGatherTaskTopic(CShfeFtdcReqQryNetGatherTaskField *pReqQryNetGatherTask, int nRequestID);

	///�豸�������
	virtual int ReqQryNetDeviceChgTopic(CShfeFtdcReqQryNetDeviceChgField *pReqQryNetDeviceChg, int nRequestID);

	///�����豸�ͺ�����
	virtual int ReqQryNetDeviceTypeTopic(CShfeFtdcReqQryNetDeviceTypeField *pReqQryNetDeviceType, int nRequestID);

	///�����豸�������
	virtual int ReqQryNetDeviceCategoryTopic(CShfeFtdcReqQryNetDeviceCategoryField *pReqQryNetDeviceCategory, int nRequestID);

	///�豸��������
	virtual int ReqQryNetManufactoryTopic(CShfeFtdcReqQryNetManufactoryField *pReqQryNetManufactory, int nRequestID);

	///�豸��ͬ������
	virtual int ReqQryNetCommunityTopic(CShfeFtdcReqQryNetCommunityField *pReqQryNetCommunity, int nRequestID);

	///�˿���������
	virtual int ReqQryNetPortTypeTopic(CShfeFtdcReqQryNetPortTypeField *pReqQryNetPortType, int nRequestID);

	///��Ա����ص�����
	virtual int ReqQryNetPartAccessSpotTopic(CShfeFtdcReqQryNetPartAccessSpotField *pReqQryNetPartAccessSpot, int nRequestID);

	///�˿�����
	virtual int ReqQryNetInterfaceTopic(CShfeFtdcReqQryNetInterfaceField *pReqQryNetInterface, int nRequestID);

	///GeneralOID����
	virtual int ReqQryNetGeneralOIDTopic(CShfeFtdcReqQryNetGeneralOIDField *pReqQryNetGeneralOID, int nRequestID);

	///��ض������
	virtual int ReqQryNetMonitorTypeTopic(CShfeFtdcReqQryNetMonitorTypeField *pReqQryNetMonitorType, int nRequestID);

	///ָ��ͳ��
	virtual int ReqQryNetMonitorAttrScopeTopic(CShfeFtdcReqQryNetMonitorAttrScopeField *pReqQryNetMonitorAttrScope, int nRequestID);

	///���ָ���
	virtual int ReqQryNetMonitorAttrTypeTopic(CShfeFtdcReqQryNetMonitorAttrTypeField *pReqQryNetMonitorAttrType, int nRequestID);

	///��ض���ָ���
	virtual int ReqQryNetMonitorObjectAttrTopic(CShfeFtdcReqQryNetMonitorObjectAttrField *pReqQryNetMonitorObjectAttr, int nRequestID);

	///ְ����
	virtual int ReqQryNetFuncAreaTopic(CShfeFtdcReqQryNetFuncAreaField *pReqQryNetFuncArea, int nRequestID);

	///���ָ���
	virtual int ReqQryNetMonitorCommandTypeTopic(CShfeFtdcReqQryNetMonitorCommandTypeField *pReqQryNetMonitorCommandType, int nRequestID);

	///�������
	virtual int ReqQryNetMonitorActionGroupTopic(CShfeFtdcReqQryNetMonitorActionGroupField *pReqQryNetMonitorActionGroup, int nRequestID);

	///�豸�������
	virtual int ReqQryNetMonitorDeviceGroupTopic(CShfeFtdcReqQryNetMonitorDeviceGroupField *pReqQryNetMonitorDeviceGroup, int nRequestID);

	///������Ϣ��
	virtual int ReqQryNetMonitorTaskInfoTopic(CShfeFtdcReqQryNetMonitorTaskInfoField *pReqQryNetMonitorTaskInfo, int nRequestID);

	///��������
	virtual int ReqQryNetMonitorTaskResultTopic(CShfeFtdcReqQryNetMonitorTaskResultField *pReqQryNetMonitorTaskResult, int nRequestID);

	///�������
	virtual int ReqQryNetMonitorTaskObjectSetTopic(CShfeFtdcReqQryNetMonitorTaskObjectSetField *pReqQryNetMonitorTaskObjectSet, int nRequestID);

	///��Ա��·��Ϣ��
	virtual int ReqQryNetPartyLinkInfoTopic(CShfeFtdcReqQryNetPartyLinkInfoField *pReqQryNetPartyLinkInfo, int nRequestID);

	///��ض���ָ����ձ�
	virtual int ReqQryNetMonitorActionAttrTopic(CShfeFtdcReqQryNetMonitorActionAttrField *pReqQryNetMonitorActionAttr, int nRequestID);

	///ģ��
	virtual int ReqQryNetModuleTopic(CShfeFtdcReqQryNetModuleField *pReqQryNetModule, int nRequestID);

	///�澯���ʽ��Ϣ��
	virtual int ReqQryNetEventExprTopic(CShfeFtdcReqQryNetEventExprField *pReqQryNetEventExpr, int nRequestID);

	///�¼�����
	virtual int ReqQryNetEventTypeTopic(CShfeFtdcReqQryNetEventTypeField *pReqQryNetEventType, int nRequestID);

	///�¼�������
	virtual int ReqQryNetSubEventTypeTopic(CShfeFtdcReqQryNetSubEventTypeField *pReqQryNetSubEventType, int nRequestID);

	///�¼�����
	virtual int ReqQryNetEventLevelTopic(CShfeFtdcReqQryNetEventLevelField *pReqQryNetEventLevel, int nRequestID);

	///������״̬��
	virtual int ReqQryNetMonitorTaskStatusResultTopic(CShfeFtdcReqQryNetMonitorTaskStatusResultField *pReqQryNetMonitorTaskStatusResult, int nRequestID);

	///��½���÷��������
	virtual int ReqConfigLoginTopic(CShfeFtdcReqConfigLoginField *pReqConfigLogin, int nRequestID);

	///��֪���������˳�
	virtual int ReqSysServerExitTopic(CShfeFtdcReqSysServerExitField *pReqSysServerExit, int nRequestID);

	///�豸���ñ�
	virtual int ReqQryNetCfgFileTopic(CShfeFtdcReqQryNetCfgFileField *pReqQryNetCfgFile, int nRequestID);

	///���������������
	virtual int ReqQryNetMonitorDeviceTaskTopic(CShfeFtdcReqQryNetMonitorDeviceTaskField *pReqQryNetMonitorDeviceTask, int nRequestID);

	///����ָ��ָ�꼯��
	virtual int ReqQryNetMonitorTaskInstAttrsTopic(CShfeFtdcReqQryNetMonitorTaskInstAttrsField *pReqQryNetMonitorTaskInstAttrs, int nRequestID);

	///�ļ�ͨ�ò���
	virtual int ReqQryFileGeneralOperTopic(CShfeFtdcReqQryFileGeneralOperField *pReqQryFileGeneralOper, int nRequestID);

	///���߱�
	virtual int ReqQryNetBaseLineTopic(CShfeFtdcReqQryNetBaseLineField *pReqQryNetBaseLine, int nRequestID);

	///���������
	virtual int ReqQryNetBaseLineTaskTopic(CShfeFtdcReqQryNetBaseLineTaskField *pReqQryNetBaseLineTask, int nRequestID);

	///���߽����
	virtual int ReqQryNetBaseLineResultTopic(CShfeFtdcReqQryNetBaseLineResultField *pReqQryNetBaseLineResult, int nRequestID);

	///��Ա��·״̬��Ϣ��
	virtual int ReqQryNetPartyLinkStatusInfoTopic(CShfeFtdcReqQryNetPartyLinkStatusInfoField *pReqQryNetPartyLinkStatusInfo, int nRequestID);

	///��ԱSDH��·��ϸ��
	virtual int ReqQryNetMemberSDHLineInfoTopic(CShfeFtdcReqQryNetMemberSDHLineInfoField *pReqQryNetMemberSDHLineInfo, int nRequestID);

	///DDN��·��Ϣ��
	virtual int ReqQryNetDDNLinkInfoTopic(CShfeFtdcReqQryNetDDNLinkInfoField *pReqQryNetDDNLinkInfo, int nRequestID);

	///�ǻ�Ա��·ʹ����Ϣ
	virtual int ReqQryNetPseudMemberLinkInfoTopic(CShfeFtdcReqQryNetPseudMemberLinkInfoField *pReqQryNetPseudMemberLinkInfo, int nRequestID);

	///Զ���豸��Ϣ
	virtual int ReqQryOuterDeviceInfTopic(CShfeFtdcReqQryOuterDeviceInfField *pReqQryOuterDeviceInf, int nRequestID);

	///����ping���
	virtual int ReqQryNetLocalPingResultInfoTopic(CShfeFtdcReqQryNetLocalPingResultInfoField *pReqQryNetLocalPingResultInfo, int nRequestID);

	///Զ��ping���
	virtual int ReqQryNetRomotePingResultInfoTopic(CShfeFtdcReqQryNetRomotePingResultInfoField *pReqQryNetRomotePingResultInfo, int nRequestID);

	///ϵͳ�ڲ�������ϵ
	virtual int ReqQrySysInternalTopologyTopic(CShfeFtdcReqQrySysInternalTopologyField *pReqQrySysInternalTopology, int nRequestID);

	///�����Ա��·���ñ�
	virtual int ReqQryMemberLinkCostTopic(CShfeFtdcReqQryMemberLinkCostField *pReqQryMemberLinkCost, int nRequestID);

	///�����Ա��·�����
	virtual int ReqQryNetPartylinkMonthlyRentTopic(CShfeFtdcReqQryNetPartylinkMonthlyRentField *pReqQryNetPartylinkMonthlyRent, int nRequestID);

	///����ǻ�Ա��·����Ϣ
	virtual int ReqQryNetNonPartyLinkInfoTopic(CShfeFtdcReqQryNetNonPartyLinkInfoField *pReqQryNetNonPartyLinkInfo, int nRequestID);

	///����������Ϣ
	virtual int ReqQryMonConfigInfo(CShfeFtdcReqQryMonConfigInfoField *pReqQryMonConfigInfo, int nRequestID);

	///������������
	virtual int ReqMonServiceConnect(CShfeFtdcReqMonServiceConnectField *pReqMonServiceConnect, int nRequestID);

	///����ĵ�ǰ״̬��ѯ
	virtual int ReqQryMonServiceStatus(CShfeFtdcReqQryMonServiceStatusField *pReqQryMonServiceStatus, int nRequestID);

	///̽���������ò�ѯ����
	virtual int ReqQryMonProbeTask(CShfeFtdcReqQryMonProbeTaskField *pReqQryMonProbeTask, int nRequestID);

	///���ϵͳָ���ѯ����
	virtual int ReqQryMonObjectAttr(CShfeFtdcReqQryMonObjectAttrField *pReqQryMonObjectAttr, int nRequestID);

	///���ϵͳSyslog�¼���ѯ����
	virtual int ReqQryMonSyslogEvent(CShfeFtdcReqQryMonSyslogEventField *pReqQryMonSyslogEvent, int nRequestID);

	///�ļ���ȡƫ������ѯ����
	virtual int ReqQryMonFileOffset(CShfeFtdcReqQryMonFileOffsetField *pReqQryMonFileOffset, int nRequestID);

	///�ļ����ݲ�ѯ����
	virtual int ReqQryMonFileContent(CShfeFtdcReqQryMonFileContentField *pReqQryMonFileContent, int nRequestID);

	///��������������Ϣ��ѯ����
	virtual int ReqQryMonHostBasicEnv(CShfeFtdcReqQryMonHostBasicEnvField *pReqQryMonHostBasicEnv, int nRequestID);

	///��������������Ϣ��ѯ
	virtual int ReqQryMonHostNetworkEnv(CShfeFtdcReqQryMonHostNetworkEnvField *pReqQryMonHostNetworkEnv, int nRequestID);

	///�����ļ�ϵͳ��Ϣ��ѯ
	virtual int ReqQryMonHostFileSysEnv(CShfeFtdcReqQryMonHostFileSysEnvField *pReqQryMonHostFileSysEnv, int nRequestID);

	///��������������Ϣ��ѯ
	virtual int ReqQryMonHostSwapEnv(CShfeFtdcReqQryMonHostSwapEnvField *pReqQryMonHostSwapEnv, int nRequestID);

	///������CPU��Ϣָ����Ϣ����
	virtual int ReqQryMonHostCPUAttr(CShfeFtdcReqQryMonHostCPUAttrField *pReqQryMonHostCPUAttr, int nRequestID);

	///������Memoryʹ����Ϣ����
	virtual int ReqQryMonHostMemAttr(CShfeFtdcReqQryMonHostMemAttrField *pReqQryMonHostMemAttr, int nRequestID);

	///������FileSystemʹ����Ϣ����
	virtual int ReqQryMonHostFileSystemAttr(CShfeFtdcReqQryMonHostFileSystemAttrField *pReqQryMonHostFileSystemAttr, int nRequestID);

	///�������û���Ϣ����
	virtual int ReqQryMonHostUserInfo(CShfeFtdcReqQryMonHostUserInfoField *pReqQryMonHostUserInfo, int nRequestID);

	///�����������û���Ϣ����
	virtual int ReqQryMonHostOnlineUserInfo(CShfeFtdcReqQryMonHostOnlineUserInfoField *pReqQryMonHostOnlineUserInfo, int nRequestID);

	///������networkʹ����Ϣ����
	virtual int ReqQryMonHostNetworkAttr(CShfeFtdcReqQryMonHostNetworkAttrField *pReqQryMonHostNetworkAttr, int nRequestID);

	///������ϵͳ״̬��Ϣ����
	virtual int ReqQryMonHostStatInfo(CShfeFtdcReqQryMonHostStatInfoField *pReqQryMonHostStatInfo, int nRequestID);

	///�����Ĵ���IO��Ϣ����
	virtual int ReqQryMonHostDiskIOAttr(CShfeFtdcReqQryMonHostDiskIOAttrField *pReqQryMonHostDiskIOAttr, int nRequestID);

	///������·����Ϣ����
	virtual int ReqQryMonHostRouterInfo(CShfeFtdcReqQryMonHostRouterInfoField *pReqQryMonHostRouterInfo, int nRequestID);

	///�����Ľ�����Ϣ����
	virtual int ReqQryMonHostProcessInfo(CShfeFtdcReqQryMonHostProcessInfoField *pReqQryMonHostProcessInfo, int nRequestID);

	///�ͻ�����ʱSP��ѯ����
	virtual int ReqQryMonSPQuery(CShfeFtdcReqQryMonSPQueryField *pReqQryMonSPQuery, int nRequestID);

	///����汾��Ϣ����
	virtual int ReqServiceVersion(CShfeFtdcReqServiceVersionField *pReqServiceVersion, int nRequestID);

	///����Ӧ�ó�������
	virtual int ReqServiceProgram(CShfeFtdcReqServiceProgramField *pReqServiceProgram, int nRequestID);

	///���������ȡ״̬
	virtual int ReqUpdateState(CShfeFtdcReqUpdateStateField *pReqUpdateState, int nRequestID);

	///��������
	virtual int ReqSubscribe(CShfeFtdcReqSubscribeField *pReqSubscribe, int nRequestID);

	///ȡ����������
	virtual int ReqCancelSubscribe(CShfeFtdcReqSubscribeField *pReqSubscribe, int nRequestID);

	///����֪ͨĿ������ļ��ѷ��ͳɹ�
	virtual int ReqFileSendSuccess(CShfeFtdcReqFileSendSuccessField *pReqFileSendSuccess, int nRequestID);

	///tomcat��Ϣ��ѯ
	virtual int ReqQryMonTomcatInfo(CShfeFtdcReqQryMonTomcatInfoField *pReqQryMonTomcatInfo, int nRequestID);

	///�������Ϣ��ѯ
	virtual int ReqQryMonVMInfo(CShfeFtdcReqQryMonVMInfoField *pReqQryMonVMInfo, int nRequestID);

	///ϵͳ������Ϣ��ѯ
	virtual int ReqQryMonPropertyInfo(CShfeFtdcReqQryMonPropertyInfoField *pReqQryMonPropertyInfo, int nRequestID);

	///ϵͳ�ڴ����Ϣ��ѯ
	virtual int ReqQryMonMemPoolInfo(CShfeFtdcReqQryMonMemPoolInfoField *pReqQryMonMemPoolInfo, int nRequestID);

	///������Ϣ��ѯ
	virtual int ReqQryMonConnectionInfo(CShfeFtdcReqQryMonConnectionInfoField *pReqQryMonConnectionInfo, int nRequestID);

	///��Ч������ѯ
	virtual int ReqQryInvalidateOrderTopic(CShfeFtdcReqQryInvalidateOrderField *pReqQryInvalidateOrder, int nRequestID);

	///����״̬��ѯ
	virtual int ReqQryOrderStatusTopic(CShfeFtdcReqQryOrderStatusField *pReqQryOrderStatus, int nRequestID);

	///�����ɽ���ѯ
	virtual int ReqQryBargainOrderTopic(CShfeFtdcReqQryBargainOrderField *pReqQryBargainOrder, int nRequestID);

	///��Լ�������Բ�ѯ
	virtual int ReqQryInstPropertyTopic(CShfeFtdcReqQryInstPropertyField *pReqQryInstProperty, int nRequestID);

	///��Լ��֤���ʲ�ѯ
	virtual int ReqQryMarginRateTopic(CShfeFtdcReqQryMarginRateField *pReqQryMarginRate, int nRequestID);

	///��Լ�ǵ�ͣ���ѯ
	virtual int ReqQryPriceLimitTopic(CShfeFtdcReqQryPriceLimitField *pReqQryPriceLimit, int nRequestID);

	///��Ա�޲ֲ�ѯ
	virtual int ReqQryPartPosiLimitTopic(CShfeFtdcReqQryPartPosiLimitField *pReqQryPartPosiLimit, int nRequestID);

	///�ͻ��޲ֲ�ѯ
	virtual int ReqQryClientPosiLimitTopic(CShfeFtdcReqQryClientPosiLimitField *pReqQryClientPosiLimit, int nRequestID);

	///����ͻ��޲ֲ�ѯ
	virtual int ReqQrySpecialPosiLimitTopic(CShfeFtdcReqQrySpecialPosiLimitField *pReqQrySpecialPosiLimit, int nRequestID);

	///�˻�������ѯ
	virtual int ReqQryTransactionChgTopic(CShfeFtdcReqQryTransactionChgField *pReqQryTransactionChg, int nRequestID);

	///�ͻ����ݱ䶯��ѯ
	virtual int ReqQryClientChgTopic(CShfeFtdcReqQryClientChgField *pReqQryClientChg, int nRequestID);

	///��Ա�ͻ����ձ䶯��ѯ
	virtual int ReqQryPartClientChgTopic(CShfeFtdcReqQryPartClientChgField *pReqQryPartClientChg, int nRequestID);

	///�޲����ݱ䶯��ѯ
	virtual int ReqQryPosiLimitChgTopic(CShfeFtdcReqQryPosiLimitChgField *pReqQryPosiLimitChg, int nRequestID);

	///��ֵ��ȱ䶯��ѯ
	virtual int ReqQryHedgeDetailChgTopic(CShfeFtdcReqQryHedgeDetailChgField *pReqQryHedgeDetailChg, int nRequestID);

	///��Ա�䶯��ѯ
	virtual int ReqQryParticipantChgTopic(CShfeFtdcReqQryParticipantChgField *pReqQryParticipantChg, int nRequestID);

	///��֤���ʱ䶯��ѯ
	virtual int ReqQryMarginRateChgTopic(CShfeFtdcReqQryMarginRateChgField *pReqQryMarginRateChg, int nRequestID);

	///IP��ַ�䶯��ѯ
	virtual int ReqQryUserIpChgTopic(CShfeFtdcReqQryUserIpChgField *pReqQryUserIpChg, int nRequestID);

	///�޲����ݱ䶯��ѯ
	virtual int ReqQryClientPosiLimitChgTopic(CShfeFtdcReqQryClientPosiLimitChgField *pReqQryClientPosiLimitChg, int nRequestID);

	///�޲����ݱ䶯��ѯ
	virtual int ReqQrySpecPosiLimitChgTopic(CShfeFtdcReqQrySpecPosiLimitChgField *pReqQrySpecPosiLimitChg, int nRequestID);

	///����ϵͳǰ��ͳ�Ʋ�ѯ
	virtual int ReqQryFrontStatTopic(CShfeFtdcReqQryFrontStatField *pReqQryFrontStat, int nRequestID);

	///����ƽ̨��ʼ����Ϣ��ѯ
	virtual int ReqQryParticipantInitTopic(CShfeFtdcReqQryParticipantInitField *pReqQryParticipantInit, int nRequestID);

	///����ƽ̨��ʼ����Ϣ��ѯ
	virtual int ReqQryUserInitTopic(CShfeFtdcReqQryUserInitField *pReqQryUserInit, int nRequestID);

	///����Լ״̬�л�����
	virtual int ReqQryInstrumentStatusTopic(CShfeFtdcReqQryInstrumentStatusField *pReqQryInstrumentStatus, int nRequestID);

	///�����Լ���׽���Ϣ
	virtual int ReqQryCurrTradingSegmentAttrTopic(CShfeFtdcReqQryCurrTradingSegmentAttrField *pReqQryCurrTradingSegmentAttr, int nRequestID);

	///����ϵͳ��¼��Ϣ��ѯ
	virtual int ReqQryTradeUserLoginInfoTopic(CShfeFtdcReqQryTradeUserLoginInfoField *pReqQryTradeUserLoginInfo, int nRequestID);

	///��Ա���ײ�ѯ
	virtual int ReqQryPartTradeTopic(CShfeFtdcReqQryPartTradeField *pReqQryPartTrade, int nRequestID);

	///��Աϯλ����״̬
	virtual int ReqQryParticTradeOrderStatesTopic(CShfeFtdcReqQryParticTradeOrderStatesField *pReqQryParticTradeOrderStates, int nRequestID);

	///��ü�ض�����Ϣ��ѯ
	virtual int ReqQryMonitor2ObjectTopic(CShfeFtdcReqQryMonitor2ObjectField *pReqQryMonitor2Object, int nRequestID);

	///����������Ϣ��ѯ
	virtual int ReqQryMonHostCommonEnvTopic(CShfeFtdcReqQryMonHostCommonEnvField *pReqQryMonHostCommonEnv, int nRequestID);

	///��ȡҵ����̺�������ϵ
	virtual int ReqQryMonOidHostRationalTopic(CShfeFtdcReqQryMonOidHostRationalField *pReqQryMonOidHostRational, int nRequestID);

	///�����ϵ��ѯ
	virtual int ReqQryMonOidRelationTopic(CShfeFtdcReqQryMonOidRelationField *pReqQryMonOidRelation, int nRequestID);
private:
	///����Ӧ��
	void OnRspError(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û���¼Ӧ��
	void OnRspUserLogin(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û��˳�Ӧ��
	void OnRspUserLogout(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����¼��Ӧ��
	void OnRspOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������Ӧ��
	void OnRspOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����¼��Ӧ��
	void OnRspQuoteInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���۲���Ӧ��
	void OnRspQuoteAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///OTC����¼��Ӧ��
	void OnRspOTCOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û������޸�Ӧ��
	void OnRspUserPasswordUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ִ������¼��Ӧ��
	void OnRspExecOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ִ���������Ӧ��
	void OnRspExecOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������¼��Ӧ��
	void OnRspAdminOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�Ǳ���ϱ���¼��Ӧ��
	void OnRspCombOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������Ӧ��
	void OnRspSubscribeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������������Ӧ��
	void OnRspBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������������ϢӦ��
	void OnRspInformation(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Լ����״̬�ı�Ӧ��
	void OnRspInstrumentStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ǿ���û��˳�Ӧ��
	void OnRspForceUserExit(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û��Ựɾ��Ӧ��
	void OnRspForceUserLogout(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����������ͬ��״̬�ı�Ӧ��
	void OnRspExchangeDataSyncStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����������ͬ��״̬�ı�Ӧ��
	void OnRspSGDataSyncStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա�ʽ��ѯӦ��
	void OnRspQryPartAccount(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������ѯӦ��
	void OnRspQryOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���۲�ѯӦ��
	void OnRspQryQuote(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ɽ�����ѯӦ��
	void OnRspQryTrade(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա�ͻ���ѯӦ��
	void OnRspQryClient(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա�ֲֲ�ѯӦ��
	void OnRspQryPartPosition(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ͻ��ֲֲ�ѯӦ��
	void OnRspQryClientPosition(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Լ��ѯӦ��
	void OnRspQryInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Լ����״̬��ѯӦ��
	void OnRspQryInstrumentStatus(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������״̬��ѯӦ��
	void OnRspQrySGDataSyncStatus(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ֵ���Ӧ��
	void OnRspQryHedgeVolume(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����޶��ѯӦ��
	void OnRspQryCreditLimit(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�Ǳ���ϱ�����ѯӦ��
	void OnRspQryCombOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ִ�������ѯӦ��
	void OnRspQryExecOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ͨ�����ѯӦ��
	void OnRspQryMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����������ѯ����Ӧ��
	void OnRspQryBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����ѯӦ��
	void OnRspQryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û����߲�ѯӦ��
	void OnRspQryUserSession(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û���ѯӦ��
	void OnRspQryUser(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա��ѯӦ��
	void OnRspQryParticipant(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Լ��λ��ѯӦ��
	void OnRspQryMBLMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ϣ��ѯӦ��
	void OnRspQryInformation(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ɽ��ر�
	void OnRtnTrade(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����ر�
	void OnRtnOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ִ������ر�
	void OnRtnExecOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ۻر�
	void OnRtnQuote(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�Ǳ���ϱ����ر�
	void OnRtnCombOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Լ����״̬֪ͨ
	void OnRtnInstrumentStatus(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���Ӻ�Լ֪ͨ
	void OnRtnInsInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ɾ����Լ֪ͨ
	void OnRtnDelInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���Ӻ�Լ����֪ͨ
	void OnRtnInsCombinationLeg(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ɾ����Լ����֪ͨ
	void OnRtnDelCombinationLeg(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������֪ͨ
	void OnRtnAliasDefine(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����������֪ͨ
	void OnRtnFlowMessageCancel(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����֪ͨ
	void OnRtnBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ͨ����֪ͨ
	void OnRtnMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�������֪ͨ
	void OnRtnDepthMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������֪ͨ
	void OnRtnAdminOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����¼�����ر�
	void OnErrRtnOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������������ر�
	void OnErrRtnOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����¼�����ر�
	void OnErrRtnQuoteInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���۲�������ر�
	void OnErrRtnQuoteAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ִ������¼�����ر�
	void OnErrRtnExecOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ִ�������������ر�
	void OnErrRtnExecOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�Ǳ���ϱ���¼�����ر�
	void OnErrRtnCombOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ʲ�ѯӦ��
	void OnRspQryExchangeRate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///CPUӦ��
	void OnRspQryTopCpuInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///CPUӦ��
	void OnRtnTopCpuInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///MemӦ��
	void OnRspQryTopMemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///MemӦ��
	void OnRtnTopMemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///processӦ��
	void OnRspQryTopProcessInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///processӦ��
	void OnRtnTopProcessInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///filesystemӦ��
	void OnRspQryFileSystemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///filesystemӦ��
	void OnRtnFileSystemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///networkӦ��
	void OnRspQryNetworkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///networkӦ��
	void OnRtnNetworkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ͻ��˵�¼Ӧ��
	void OnRspQryClientLoginTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ü�ض�����ϢӦ��
	void OnRspQryMonitorObjectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ü�ض�����ϢӦ��
	void OnRtnMonitorObjectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ҵ����̺������Ķ�Ӧ��ϵӦ��
	void OnRspQryObjectRationalTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ҵ����̺������Ķ�Ӧ��ϵӦ��
	void OnRtnObjectRationalTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��־�ļ�����Ӧ��
	void OnRspQrySyslogInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��־�ļ�����Ӧ��
	void OnRtnSyslogInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������ݶ���Ӧ��
	void OnRspQrySubscriberTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����ϵ��ѯӦ��
	void OnRspQryOidRelationTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����ϵ��ѯӦ��
	void OnRtnOidRelationTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û���Ϣ��ѯ����Ӧ��
	void OnRspQryUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û���Ϣ��ѯ����Ӧ��
	void OnRtnUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����û���Ϣ��ѯ����Ӧ��
	void OnRspQryOnlineUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����û���Ϣ��ѯ����Ӧ��
	void OnRtnOnlineUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�澯�¼���ѯ����Ӧ��
	void OnRspQryWarningEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�澯�¼���ѯ����Ӧ��
	void OnRtnWarningEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///CPUʹ���ʲ�ѯ����Ӧ��
	void OnRspQryCPUUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///CPUʹ���ʲ�ѯ����Ӧ��
	void OnRtnCPUUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ڴ�ʹ���ʲ�ѯ����Ӧ��
	void OnRspQryMemoryUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ڴ�ʹ���ʲ�ѯ����Ӧ��
	void OnRtnMemoryUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Ӳ��ʹ���ʲ�ѯ����Ӧ��
	void OnRspQryDiskUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Ӳ��ʹ���ʲ�ѯ����Ӧ��
	void OnRtnDiskUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����״ָ̬���ѯӦ��
	void OnRspQryObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����״ָ̬���ѯӦ��
	void OnRtnObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ʷ����״ָ̬���ѯӦ��
	void OnRspQryHistoryObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ʷ����״ָ̬���ѯӦ��
	void OnRtnHistoryObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ǰ����Ӧ��Ϣ��ѯӦ��
	void OnRspQryFrontInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ǰ����Ӧ��Ϣ��ѯӦ��
	void OnRtnFrontInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û���¼Ӧ��
	void OnRspQrySysUserLoginTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û��ǳ�Ӧ��
	void OnRspQrySysUserLogoutTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�û��޸�����Ӧ��
	void OnRspQrySysUserPasswordUpdateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ע���û�Ӧ��
	void OnRspQrySysUserRegisterTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ɾ���û�Ӧ��
	void OnRspQrySysUserDeleteTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ͻ���ʼ��Ӧ��
	void OnRspQryClientInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ͻ���ʼ��Ӧ��
	void OnRtnClientInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������־��ѯӦ��
	void OnRspQryTradeLogTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������־��ѯӦ��
	void OnRtnTradeLogTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���׷�ֵ��ѯӦ��
	void OnRspQryTradepeakTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///
	void OnRtnUpdateSysConfigTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///
	void OnRtnSysUser(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///
	void OnRtnPriceLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///
	void OnRspQryHistoryCpuInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///
	void OnRspQryHistoryMemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///
	void OnRspQryHistoryNetworkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///HostConfig��ѯ����Ӧ��
	void OnRspQryHostConfig(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ϵͳ�����û�Ӧ��
	void OnRspQryMonitorOnlineUser(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ϵͳʱ��ͬ��
	void OnRtnSysTimeSyncTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���������л�֪ͨ
	void OnRtnDataCenterChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ʷ��ֵ��ѯӦ��
	void OnRspQryHistoryTradePeakTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ʷ��ֵ��ѯӦ��
	void OnRtnHistoryTradePeakTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��־�¼���ѯӦ��
	void OnRspQrySyslogEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��־�¼�Ӧ��
	void OnRtnSyslogEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�������л�֪ͨ
	void OnRspQryTradeDayChangeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///WebӦ����Ϣ
	void OnRspQryWebAppInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///WebӦ����Ϣ
	void OnRtnWebAppInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Ӧ��servlet��Ϣ
	void OnRspQryServletInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Ӧ��servlet��Ϣ
	void OnRtnServletInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ļ���Ϣ
	void OnRspQryFileInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ļ���Ϣ
	void OnRtnFileInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Ӧ�ûỰ��Ϣ
	void OnRspQrySessionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Ӧ�ûỰ��Ϣ
	void OnRtnSessionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///JDBC��Ϣ
	void OnRspQryJDBCInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///JDBC��Ϣ
	void OnRtnJDBCInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�߳���Ϣ
	void OnRspQryThreadInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�߳���Ϣ
	void OnRtnThreadInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�������Ϣ
	void OnRspQryVMInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�������Ϣ
	void OnRtnVMInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ϵͳ������Ϣ
	void OnRspQryPropertyInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ϵͳ������Ϣ
	void OnRtnPropertyInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ϵͳ�ڴ����Ϣ
	void OnRspQryMemPoolInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ϵͳ�ڴ����Ϣ
	void OnRtnMemPoolInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ļ�������Ϣ
	void OnRspQryFileContentInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ļ�������Ϣ
	void OnRtnFileContentInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������Ϣ
	void OnRspQryConnectionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������Ϣ
	void OnRtnConnectionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������Ϣ
	void OnRspQryConnectorInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������Ϣ
	void OnRtnConnectorInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ݿ��ѯӦ��
	void OnRspQryDBQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ݿ��ѯӦ��
	void OnRtnDBQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ͨ�÷���Ӧ��
	void OnRspQryGeneralFieldTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ͨ�÷���Ӧ��
	void OnRtnGeneralFieldTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ļ�����Ӧ��
	void OnRspQryGetFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�澯��ϸ
	void OnRspQryWarningQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�澯��ϸ
	void OnRtnWarningQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///HostConfig����Ӧ��
	void OnRtnHostConfig(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�澯������
	void OnRspQryWarningActiveChange(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�澯������
	void OnRtnWarningActiveChange(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ͨ�ò���
	void OnRspQryGeneralOperateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ͨ�ò���
	void OnRtnGeneralOperateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����豸���ӹ�ϵ
	void OnRspQryNetDeviceLinkedTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����豸���ӹ�ϵ
	void OnRtnNetDeviceLinkedTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ϵͳ��¼��Ϣ
	void OnRspQryTradeUserLoginStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ϵͳǰ�ñ�����Ӧ��Ϣ
	void OnRspQryTradeFrontOrderRttStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ϵͳǰ�ñ�����Ӧ��Ϣ
	void OnRtnTradeFrontOrderRttStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ϵͳ·����Ϣ
	void OnRspQryRouterInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ϵͳ·����Ϣ
	void OnRtnRouterInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����I/O��Ϣ
	void OnRspQryDiskIOTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����I/O��Ϣ
	void OnRtnDiskIOTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ϵͳ״̬��Ϣ
	void OnRspQryStatInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ϵͳ״̬��Ϣ
	void OnRtnStatInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ϵͳǰ�ñ����ֲ�����
	void OnRspQryTradeOrderRttCutLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ϵͳǰ�ñ����ֲ�����
	void OnRtnTradeOrderRttCutLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա�ͻ���Ϣ
	void OnRspQryClientInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա�ͻ���Ϣ
	void OnRtnClientInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Ӧ���¼�����
	void OnRspQryEventDescriptionTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����¼�����
	void OnRtnEventDescriptionTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Ӧ��ǰ��ΨһID��Ϣ
	void OnRspQryFrontUniqueIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ǰ��ΨһID��Ϣ
	void OnRtnFrontUniqueIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա��·��ַ�����Ӧ
	void OnRspQryNetPartyLinkAddrChangeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���Ļ�Ա��·��ַ�����Ϣ
	void OnRtnNetPartyLinkAddrChangeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Ӧ����ɾ����Ա�б���Ϣ
	void OnRspQryNetDelPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������ɾ����Ա�б���Ϣ
	void OnRtnNetDelPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����������������
	void OnRspQryPerformanceTopTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����������������
	void OnRtnPerformanceTopTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����������Ӧ��
	void OnRspQryNetAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����������Ӧ��
	void OnRtnNetAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������Ӧ��
	void OnRspQryNetSubAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������Ӧ��
	void OnRtnNetSubAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������IPӦ��
	void OnRspQryNetSubAreaIPTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������IPӦ��
	void OnRtnNetSubAreaIPTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����豸
	void OnRspQryNetDeviceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����豸
	void OnRtnNetDeviceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����豸̽������Ӧ��
	void OnRspQryNetDeviceDetectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��¥
	void OnRspQryNetBuildingTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��¥
	void OnRtnNetBuildingTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����
	void OnRspQryNetRoomTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����
	void OnRtnNetRoomTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����
	void OnRspQryNetCabinetsTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����
	void OnRtnNetCabinetsTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///OID
	void OnRspQryNetOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///OID
	void OnRtnNetOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ʱ�����
	void OnRspQryNetTimePolicyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ʱ�����
	void OnRtnNetTimePolicyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ɼ�����
	void OnRspQryNetGatherTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ɼ�����
	void OnRtnNetGatherTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�豸���
	void OnRspQryNetDeviceChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�豸���
	void OnRtnNetDeviceChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����豸�ͺ�
	void OnRspQryNetDeviceTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����豸�ͺ�
	void OnRtnNetDeviceTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����豸���
	void OnRspQryNetDeviceCategoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����豸���
	void OnRtnNetDeviceCategoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�豸����
	void OnRspQryNetManufactoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�豸����
	void OnRtnNetManufactoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�豸��ͬ��
	void OnRspQryNetCommunityTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�豸��ͬ��
	void OnRtnNetCommunityTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�˿�����
	void OnRspQryNetPortTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�˿�����
	void OnRtnNetPortTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա����ص�
	void OnRspQryNetPartAccessSpotTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա����ص�
	void OnRtnNetPartAccessSpotTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�˿�
	void OnRspQryNetInterfaceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�˿�
	void OnRtnNetInterfaceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///GeneralOID
	void OnRspQryNetGeneralOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///GeneralOID
	void OnRtnNetGeneralOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ض������
	void OnRspQryNetMonitorTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ض������
	void OnRtnNetMonitorTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ָ��ͳ��
	void OnRspQryNetMonitorAttrScopeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ָ��ͳ��
	void OnRtnNetMonitorAttrScopeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ָ���
	void OnRspQryNetMonitorAttrTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ָ���
	void OnRtnNetMonitorAttrTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ض���ָ���
	void OnRspQryNetMonitorObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ض���ָ���
	void OnRtnNetMonitorObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ְ����
	void OnRspQryNetFuncAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ְ����
	void OnRtnNetFuncAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ָ���
	void OnRspQryNetMonitorCommandTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ָ���
	void OnRtnNetMonitorCommandTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�������
	void OnRspQryNetMonitorActionGroupTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�������
	void OnRtnNetMonitorActionGroupTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�豸�������
	void OnRspQryNetMonitorDeviceGroupTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�豸�������
	void OnRtnNetMonitorDeviceGroupTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������Ϣ��
	void OnRspQryNetMonitorTaskInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������Ϣ��
	void OnRtnNetMonitorTaskInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������
	void OnRspQryNetMonitorTaskResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������
	void OnRtnNetMonitorTaskResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�������
	void OnRspQryNetMonitorTaskObjectSetTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�������
	void OnRtnNetMonitorTaskObjectSetTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա��·��Ϣ��
	void OnRspQryNetPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա��·��Ϣ��
	void OnRtnNetPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ض���ָ����ձ�
	void OnRspQryNetMonitorActionAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ض���ָ����ձ�
	void OnRtnNetMonitorActionAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ģ��
	void OnRspQryNetModuleTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ģ��
	void OnRtnNetModuleTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�澯���ʽ��Ϣ��
	void OnRspQryNetEventExprTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�澯���ʽ��Ϣ��
	void OnRtnNetEventExprTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�¼�����
	void OnRspQryNetEventTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�¼�����
	void OnRtnNetEventTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�¼�������
	void OnRspQryNetSubEventTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�¼�������
	void OnRtnNetSubEventTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�¼�����
	void OnRspQryNetEventLevelTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�¼�����
	void OnRtnNetEventLevelTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������״̬��
	void OnRspQryNetMonitorTaskStatusResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������״̬��
	void OnRtnNetMonitorTaskStatusResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���÷���Ե�½����Ӧ
	void OnRspConfigLoginTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�Ե�ǰ��¼���õķ����ɫ����Ӧ
	void OnRspServerTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�豸���ñ�
	void OnRspQryNetCfgFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�豸���ñ�
	void OnRtnNetCfgFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���������������
	void OnRspQryNetMonitorDeviceTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���������������
	void OnRtnNetMonitorDeviceTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ָ��ָ�꼯��
	void OnRspQryNetMonitorTaskInstAttrsTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ָ��ָ�꼯��
	void OnRtnNetMonitorTaskInstAttrsTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ļ�ͨ�ò���
	void OnRspQryFileGeneralOperTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ļ�ͨ�ò���
	void OnRtnFileGeneralOperTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���߱�
	void OnRspQryNetBaseLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���߱�
	void OnRtnNetBaseLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���������
	void OnRspQryNetBaseLineTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���������
	void OnRtnNetBaseLineTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���߽����
	void OnRspQryNetBaseLineResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���߽����
	void OnRtnNetBaseLineResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա��·״̬��Ϣ��
	void OnRspQryNetPartyLinkStatusInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա��·״̬��Ϣ��
	void OnRtnNetPartyLinkStatusInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ԱSDH��·��ϸ��
	void OnRspQryNetMemberSDHLineInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ԱSDH��·��ϸ��
	void OnRtnNetMemberSDHLineInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///DDN��·��Ϣ��
	void OnRspQryNetDDNLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///DDN��·��Ϣ��
	void OnRtnNetDDNLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ǻ�Ա��·ʹ����Ϣ
	void OnRspQryNetPseudMemberLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ǻ�Ա��·ʹ����Ϣ
	void OnRtnNetPseudMemberLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Զ���豸��Ϣ
	void OnRspQryOuterDeviceInfTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Զ���豸��Ϣ
	void OnRtnNetOuterDeviceInfTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ping���
	void OnRspQryNetLocalPingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ping���
	void OnRtnNetLocalPingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Զ��ping���
	void OnRspQryNetRomotePingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Զ��ping���
	void OnRtnNetRomotePingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������Ϣ���ݿ�ר��
	void OnRtnMonitorTopProcessInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ϵͳ�ڲ�������ϵ
	void OnRspQrySysInternalTopologyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ϵͳ�ڲ�������ϵ
	void OnRtnSysInternalTopologyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ػ�Ա��·���ñ�
	void OnRspQryMemberLinkCostTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���Ļ�Ա��·���ñ�
	void OnRtnMemberLinkCostTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ػ�Ա��·�����
	void OnRspQryNetPartylinkMonthlyRentTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���Ļ�Ա��·�����
	void OnRtnNetPartylinkMonthlyRentTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���طǻ�Ա��·����Ϣ
	void OnRspQryNetNonPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ķǻ�Ա��·����Ϣ
	void OnRtnNetNonPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Ӧ��������Ϣ
	void OnRspQryMonConfigInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Ӧ��������Ϣ
	void OnRtnMonConfigInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///֪ͨ�������Ϣ
	void OnRtnMonitorDayInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///֪ͨ��������Ϣ
	void OnRtnTradingDayInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ؽ׶ν���
	void OnRtnSectionFinish(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ؽ׶��л�
	void OnRtnSectionChange(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����������Ӧ
	void OnRspMonServiceConnect(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Proxy��̽����������
	void OnRtnMonProxyConfig(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ĵ�ǰ״̬��Ӧ
	void OnRspQryMonServiceStatus(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ĵ�ǰ״̬����
	void OnRtnMonServiceStatus(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ǰ�������Ľ�ɫ
	void OnRtnMonDataCenterRole(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///̽���������ò�ѯ��Ӧ
	void OnRspQryMonProbeTask(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///̽��������������
	void OnRtnMonProbeTask(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ϵͳָ���ѯӦ��
	void OnRspQryMonObjectAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ϵͳָ���ѯ����
	void OnRtnMonObjectAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ϵͳSyslog�¼���ѯӦ��
	void OnRspQryMonSyslogEvent(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ϵͳSyslog�¼���ѯ����
	void OnRtnMonSyslogEvent(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ļ���ȡƫ������ѯӦ��
	void OnRspQryMonFileOffset(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ļ���ȡƫ������ѯ����
	void OnRtnMonFileOffset(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ļ����ݲ�ѯӦ��
	void OnRspQryMonFileContent(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ļ�����ͨ��
	void OnRtnMonFileContent(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������������ϢӦ��
	void OnRspQryMonHostBasicEnv(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������������ϢӦ��
	void OnRtnMonHostBasicEnv(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������������ϢӦ��
	void OnRspQryMonHostNetworkEnv(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������������Ϣͨ��
	void OnRtnMonHostNetworkEnv(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����ļ�ϵͳ��ϢӦ��
	void OnRspQryMonHostFileSysEnv(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����ļ�ϵͳ��Ϣͨ��
	void OnRtnMonHostFileSysEnv(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������������ϢӦ��
	void OnRspQryMonHostSwapEnv(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������������Ϣͨ��
	void OnRtnMonHostSwapEnv(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������CPU��Ϣָ����ϢӦ��
	void OnRspQryMonHostCPUAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������CPU��Ϣָ����Ϣ
	void OnRtnMonHostCPUAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������Memoryʹ����ϢӦ��
	void OnRspQryMonHostMemAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������Memoryʹ����Ϣ
	void OnRtnMonHostMemAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������FileSystemʹ����ϢӦ��
	void OnRspQryMonHostFileSystemAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������FileSystemʹ����Ϣ
	void OnRtnMonHostFileSystemAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�������û���ϢӦ��
	void OnRspQryMonHostUserInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�������û���Ϣ
	void OnRtnMonHostUserInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����������û���ϢӦ��
	void OnRspQryMonHostOnlineUserInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����������û���Ϣ
	void OnRtnMonHostOnlineUserInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������networkʹ����ϢӦ��
	void OnRspQryMonHostNetworkAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������networkʹ����Ϣ
	void OnRtnMonHostNetworkAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������ϵͳ״̬��ϢӦ��
	void OnRspQryMonHostStatInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������ϵͳ״̬��Ϣ
	void OnRtnMonHostStatInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����Ĵ���IO��ϢӦ��
	void OnRspQryMonHostDiskIOAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����Ĵ���IO��Ϣ
	void OnRtnMonHostDiskIOAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������·����ϢӦ��
	void OnRspQryMonHostRouterInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������·����Ϣ
	void OnRtnMonHostRouterInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����Ľ�����ϢӦ��
	void OnRspQryMonHostProcessInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����Ľ�����Ϣ
	void OnRtnMonHostProcessInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ݿ�ɼ������ͱ��ģ�������SP��DBLog��DBAttr
	void OnRtnMonDBQuery(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ӧ�ͻ�����ʱSP��ѯ����
	void OnRspQryMonSPQuery(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����汾��Ϣ��Ӧ
	void OnRspServiceVersion(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����Ӧ�ó�����Ӧ
	void OnRspServiceProgram(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���������ȡ״̬��Ӧ
	void OnRspUpdateState(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��������Ӧ��
	void OnRspSubscribe(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///֪ͨĿ������ļ��ѳɹ�����
	void OnRspFileSendSuccess(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����֪ͨĿ������ļ��ѷ��ͳɹ�
	void OnRtnFileSendSuccess(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///tomcat��ϢӦ��
	void OnRspQryMonTomcatInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///tomcat��Ϣ����
	void OnRtnMonTomcatInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///WebӦ����Ϣ
	void OnRspQryMonWebAppInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///WebӦ����Ϣ
	void OnRtnMonWebAppInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Ӧ��servlet��Ϣ
	void OnRspQryMonServletInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Ӧ��servlet��Ϣ
	void OnRtnMonServletInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ļ���Ϣ
	void OnRspQryMonFileInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ļ���Ϣ
	void OnRtnMonFileInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Ӧ�ûỰ��ϢӦ��
	void OnRspQryMonSessionInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Ӧ�ûỰ��Ϣ����
	void OnRtnMonSessionInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///JDBC��Ϣ
	void OnRspQryMonJDBCInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///JDBC��Ϣ
	void OnRtnMonJDBCInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�߳���Ϣ
	void OnRspQryMonThreadInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�߳���Ϣ
	void OnRtnMonThreadInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�������Ϣ
	void OnRspQryMonVMInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�������Ϣ
	void OnRtnMonVMInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ϵͳ������Ϣ
	void OnRspQryMonPropertyInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ϵͳ������Ϣ
	void OnRtnMonPropertyInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ϵͳ�ڴ����Ϣ
	void OnRspQryMonMemPoolInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ϵͳ�ڴ����Ϣ
	void OnRtnMonMemPoolInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������Ϣ
	void OnRspQryMonConnectionInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������Ϣ
	void OnRtnMonConnectionInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ч������ѯӦ��
	void OnRspQryInvalidateOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ч������ѯӦ��
	void OnRtnInvalidateOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����״̬��ѯӦ��
	void OnRspQryOrderStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����״̬��ѯӦ��
	void OnRtnOrderStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����ɽ���ѯӦ��
	void OnRspQryBargainOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����ɽ���ѯӦ��
	void OnRtnBargainOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Լ�������Բ�ѯӦ��
	void OnRspQryInstPropertyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Լ�������Բ�ѯӦ��
	void OnRtnInstPropertyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Լ��֤���ʲ�ѯӦ��
	void OnRspQryMarginRateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Լ��֤���ʲ�ѯӦ��
	void OnRtnMarginRateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Լ�ǵ�ͣ���ѯӦ��
	void OnRspQryPriceLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Լ�ǵ�ͣ���ѯӦ��
	void OnRtnPriceLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա�޲ֲ�ѯӦ��
	void OnRspQryPartPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա�޲ֲ�ѯӦ��
	void OnRtnPartPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ͻ��޲ֲ�ѯӦ��
	void OnRspQryClientPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ͻ��޲ֲ�ѯӦ��
	void OnRtnClientPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ͻ��޲ֲ�ѯӦ��
	void OnRspQrySpecialPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ͻ��޲ֲ�ѯӦ��
	void OnRtnSpecialPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�˻�������ѯӦ��
	void OnRspQryTransactionChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�˻�������ѯӦ��
	void OnRtnTransactionChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ͻ����ݱ䶯��ѯӦ��
	void OnRspQryClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ͻ����ݱ䶯��ѯӦ��
	void OnRtnClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա�ͻ����ձ䶯��ѯӦ��
	void OnRspQryPartClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա�ͻ����ձ䶯��ѯӦ��
	void OnRtnPartClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�޲����ݱ䶯��ѯӦ��
	void OnRspQryPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�޲����ݱ䶯��ѯӦ��
	void OnRtnPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ֵ��ȱ䶯��ѯӦ��
	void OnRspQryHedgeDetailChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ֵ��ȱ䶯��ѯӦ��
	void OnRtnHedgeDetailChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա�䶯��ѯӦ��
	void OnRspQryParticipantChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա�䶯��ѯӦ��
	void OnRtnParticipantChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��֤���ʱ䶯��ѯӦ��
	void OnRspQryMarginRateChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��֤���ʱ䶯��ѯӦ��
	void OnRtnMarginRateChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///IP��ַ�䶯��ѯӦ��
	void OnRspQryUserIpChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///IP��ַ�䶯��ѯӦ��
	void OnRtnUserIpChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�޲����ݱ䶯��ѯӦ��
	void OnRspQryClientPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�޲����ݱ䶯��ѯӦ��
	void OnRtnClientPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�޲����ݱ䶯��ѯӦ��
	void OnRspQrySpecPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�޲����ݱ䶯��ѯӦ��
	void OnRtnSpecPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ϵͳǰ��ͳ��Ӧ��
	void OnRspQryFrontStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա��ʼ��Ӧ��
	void OnRspQryParticipantInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա��ʼ��Ӧ��
	void OnRtnParticipantInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ϯ��ʼ��Ӧ��
	void OnRspQryUserInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ϯ��ʼ��Ӧ��
	void OnRtnUserInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����Լ״̬�л�����
	void OnRspQryInstrumentStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����Լ״̬�л�����
	void OnRtnInstrumentStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���غ�Լ���׽���Ϣ
	void OnRspQryCurrTradingSegmentAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ĺ�Լ���׽���Ϣ
	void OnRtnCurrTradingSegmentAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ϵͳ��¼��Ϣ
	void OnRspQryTradeUserLoginInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ϵͳ��¼��Ϣ
	void OnRtnTradeUserLoginInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա���ײ�ѯӦ��
	void OnRspQryPartTradeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Աϯλ����״̬
	void OnRspQryParticTradeOrderStatesTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Աϯλ����״̬
	void OnRtnParticTradeOrderStatesTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ü�ض�����ϢӦ��
	void OnRspQryMonitor2ObjectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ü�ض�����ϢӦ��
	void OnRtnMonitor2ObjectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����������ϢӦ��
	void OnRspQryMonHostCommonEnvTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����������ϢӦ��
	void OnRtnMonHostCommonEnvTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Ӧ��ҵ����̺�������ϵ
	void OnRspQryMonOidHostRationalTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ҵ����̺�������ϵ
	void OnRtnMonOidHostRationalTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����ϵ��ѯӦ��
	void OnRspQryMonOidRelationTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�����ϵ��ѯӦ��
	void OnRtnMonOidRelationTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
};

#endif
