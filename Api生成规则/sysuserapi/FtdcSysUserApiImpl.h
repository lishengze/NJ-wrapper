/////////////////////////////////////////////////////////////////////////
///@system ��һ��������ϵͳ���ռ��ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file FtdcSysUserApiImpl.h
///@brief �����˿ͻ��˽ӿ�ʵ��
///@history 
///20070207 zhangjie		�������ļ�
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCSYSUSERAPIIMPL_H)
#define _FTDCSYSUSERAPIIMPL_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//#include "FtdcSysUserApi.h"

#include "FtdcSysUserApiImplBase.h"

///SysUserApi�ӿ�ʵ��
class CFtdcSysUserApiImpl : public CFtdcSysUserApiImplBase
{
public:	
	CFtdcSysUserApiImpl(const char *pszFlowPath, CSelectReactor *pReactor);
	virtual void HandleResponse(CFTDCPackage *pMessage, WORD nSequenceSeries);
	

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

	///����״ָ̬���ѯ
	virtual int ReqQryObjectAttrTopic(CShfeFtdcReqQryObjectAttrField *pReqQryObjectAttr, int nRequestID);

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

	///����ϵͳ��¼��Ϣ��ѯ
	virtual int ReqQryTradeUserLoginInfoTopic(CShfeFtdcReqQryTradeUserLoginInfoField *pReqQryTradeUserLoginInfo, int nRequestID);

	///��Ա���ײ�ѯ
	virtual int ReqQryPartTradeTopic(CShfeFtdcReqQryPartTradeField *pReqQryPartTrade, int nRequestID);

	///���׷�ֵ��ѯ
	virtual int ReqQryTradepeakTopic(CShfeFtdcReqQryTradepeakField *pReqQryTradepeak, int nRequestID);

	///����ƽ̨��ʼ����Ϣ��ѯ
	virtual int ReqQryParticipantInitTopic(CShfeFtdcReqQryParticipantInitField *pReqQryParticipantInit, int nRequestID);

	///����ƽ̨��ʼ����Ϣ��ѯ
	virtual int ReqQryUserInitTopic(CShfeFtdcReqQryUserInitField *pReqQryUserInit, int nRequestID);

	///
	virtual int ReqQryHistoryCpuInfoTopic(CShfeFtdcReqQryHistoryCpuInfoField *pReqQryHistoryCpuInfo, int nRequestID);

	///
	virtual int ReqQryHistoryMemInfoTopic(CShfeFtdcReqQryHistoryMemInfoField *pReqQryHistoryMemInfo, int nRequestID);

	///
	virtual int ReqQryHistoryNetworkInfoTopic(CShfeFtdcReqQryHistoryNetworkInfoField *pReqQryHistoryNetworkInfo, int nRequestID);

	///���ϵͳ�����û���ѯ
	virtual int ReqQryMonitorOnlineUser(CShfeFtdcReqQryMonitorOnlineUserField *pReqQryMonitorOnlineUser, int nRequestID);

	///����ϵͳǰ��ͳ�Ʋ�ѯ
	virtual int ReqQryFrontStat(CShfeFtdcReqQryFrontStatField *pReqQryFrontStat, int nRequestID);

	///��ʷ��ֵ��ѯ
	virtual int ReqQryHistoryTradePeakTopic(CShfeFtdcReqQryHistoryTradePeakField *pReqQryHistoryTradePeak, int nRequestID);

	///��־�¼���ѯ
	virtual int ReqQrySyslogEventTopic(CShfeFtdcReqQrySyslogEventField *pReqQrySyslogEvent, int nRequestID);

	///��־�¼���������
	virtual int ReqQrySyslogEventSubcriberTopic(CShfeFtdcReqQrySyslogEventSubcriberField *pReqQrySyslogEventSubcriber, int nRequestID);

	///tomcat��Ϣ��ѯ
	virtual int ReqQryTomcatInfoTopic(CShfeFtdcReqQryTomcatInfoField *pReqQryTomcatInfo, int nRequestID);

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

	///��Աϯλ����״̬
	virtual int ReqQryParticTradeOrderStatesTopic(CShfeFtdcReqQryParticTradeOrderStatesField *pReqQryParticTradeOrderStates, int nRequestID);

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

	///����Լ״̬�л�����
	virtual int ReqQryInstrumentStatusTopic(CShfeFtdcReqQryInstrumentStatusField *pReqQryInstrumentStatus, int nRequestID);

	///�����Լ���׽���Ϣ
	virtual int ReqQryCurrTradingSegmentAttrTopic(CShfeFtdcReqQryCurrTradingSegmentAttrField *pReqQryCurrTradingSegmentAttr, int nRequestID);

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

	///������״̬��
	virtual int ReqQryNetMonitorTaskStatusResultTopic(CShfeFtdcReqQryNetMonitorTaskStatusResultField *pReqQryNetMonitorTaskStatusResult, int nRequestID);

	///�豸���ñ�
	virtual int ReqQryNetCfgFileTopic(CShfeFtdcReqQryNetCfgFileField *pReqQryNetCfgFile, int nRequestID);

	///���������������
	virtual int ReqQryNetMonitorDeviceTaskTopic(CShfeFtdcReqQryNetMonitorDeviceTaskField *pReqQryNetMonitorDeviceTask, int nRequestID);

	///�ļ�ͨ�ò���
	virtual int ReqQryFileGeneralOperTopic(CShfeFtdcReqQryFileGeneralOperField *pReqQryFileGeneralOper, int nRequestID);

	///���߱�
	virtual int ReqQryNetBaseLineTopic(CShfeFtdcReqQryNetBaseLineField *pReqQryNetBaseLine, int nRequestID);

	///���߽����
	virtual int ReqQryNetBaseLineResultTopic(CShfeFtdcReqQryNetBaseLineResultField *pReqQryNetBaseLineResult, int nRequestID);

	///��Ա��·״̬��Ϣ��
	virtual int ReqQryNetPartyLinkStatusInfoTopic(CShfeFtdcReqQryNetPartyLinkStatusInfoField *pReqQryNetPartyLinkStatusInfo, int nRequestID);

	///����ping���
	virtual int ReqQryNetLocalPingResultInfoTopic(CShfeFtdcReqQryNetLocalPingResultInfoField *pReqQryNetLocalPingResultInfo, int nRequestID);

	///Զ��ping���
	virtual int ReqQryNetRomotePingResultInfoTopic(CShfeFtdcReqQryNetRomotePingResultInfoField *pReqQryNetRomotePingResultInfo, int nRequestID);

	///����ǻ�Ա��·����Ϣ
	virtual int ReqQryNetNonPartyLinkInfoTopic(CShfeFtdcReqQryNetNonPartyLinkInfoField *pReqQryNetNonPartyLinkInfo, int nRequestID);

private:
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
	
	///����״ָ̬���ѯӦ��
	void OnRspQryObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����״ָ̬���ѯӦ��
	void OnRtnObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
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
	
	///��Ա��ʼ��Ӧ��
	void OnRspQryParticipantInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա��ʼ��Ӧ��
	void OnRtnParticipantInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ϯ��ʼ��Ӧ��
	void OnRspQryUserInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ϯ��ʼ��Ӧ��
	void OnRtnUserInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ͻ���ʼ��Ӧ��
	void OnRspQryClientInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ͻ���ʼ��Ӧ��
	void OnRtnClientInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������־��ѯӦ��
	void OnRspQryTradeLogTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������־��ѯӦ��
	void OnRtnTradeLogTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ϵͳ��¼��Ϣ
	void OnRspQryTradeUserLoginInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ϵͳ��¼��Ϣ
	void OnRtnTradeUserLoginInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա���ײ�ѯӦ��
	void OnRspQryPartTradeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���׷�ֵ��ѯӦ��
	void OnRspQryTradepeakTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///
	void OnRtnUpdateSysConfigTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///
	void OnRtnSysUser(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///
	void OnRspQryHistoryCpuInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///
	void OnRspQryHistoryMemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///
	void OnRspQryHistoryNetworkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ϵͳ�����û�Ӧ��
	void OnRspQryMonitorOnlineUser(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ϵͳǰ��ͳ��Ӧ��
	void OnRspQryFrontStat(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ϵͳʱ��ͬ��
	void OnRtnSysTimeSyncTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���������л�֪ͨ
	void OnRtnDataCenterChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��ʷ��ֵ��ѯӦ��
	void OnRspQryHistoryTradePeakTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��־�¼���ѯӦ��
	void OnRspQrySyslogEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��־�¼�Ӧ��
	void OnRtnSyslogEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
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
	
	///��Աϯλ����״̬
	void OnRspQryParticTradeOrderStatesTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Աϯλ����״̬
	void OnRtnParticTradeOrderStatesTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
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
	
	///����Լ״̬�л�����
	void OnRspQryInstrumentStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����Լ״̬�л�����
	void OnRtnInstrumentStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���غ�Լ���׽���Ϣ
	void OnRspQryCurrTradingSegmentAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ĺ�Լ���׽���Ϣ
	void OnRtnCurrTradingSegmentAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
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
	
	///ģ��
	void OnRspQryNetModuleTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///ģ��
	void OnRtnNetModuleTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������״̬��
	void OnRspQryNetMonitorTaskStatusResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///������״̬��
	void OnRtnNetMonitorTaskStatusResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�豸���ñ�
	void OnRspQryNetCfgFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�豸���ñ�
	void OnRtnNetCfgFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���������������
	void OnRspQryNetMonitorDeviceTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���������������
	void OnRtnNetMonitorDeviceTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ļ�ͨ�ò���
	void OnRspQryFileGeneralOperTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///�ļ�ͨ�ò���
	void OnRtnFileGeneralOperTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���߱�
	void OnRspQryNetBaseLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���߱�
	void OnRtnNetBaseLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���߽����
	void OnRspQryNetBaseLineResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���߽����
	void OnRtnNetBaseLineResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա��·״̬��Ϣ��
	void OnRspQryNetPartyLinkStatusInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///��Ա��·״̬��Ϣ��
	void OnRtnNetPartyLinkStatusInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ping���
	void OnRspQryNetLocalPingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///����ping���
	void OnRtnNetLocalPingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Զ��ping���
	void OnRspQryNetRomotePingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Զ��ping���
	void OnRtnNetRomotePingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ػ�Ա��·���ñ�
	void OnRspQryMemberLinkCostTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���Ļ�Ա��·���ñ�
	void OnRtnMemberLinkCostTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���طǻ�Ա��·����Ϣ
	void OnRspQryNetNonPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///���ķǻ�Ա��·����Ϣ
	void OnRtnNetNonPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	

};


#endif
