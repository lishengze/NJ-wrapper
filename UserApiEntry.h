
#ifndef __USERAPIENTRY_H__
#define __USERAPIENTRY_H__

#pragma once
#include "..\DataUtils.h"

class CSysApiDataEntry
{
public:
	CSysApiDataEntry(void);
	~CSysApiDataEntry(void);
	
public:
	enum
	{
		DEFAULT_OBJECTNUM = 3
	};

public:
	virtual void OnFrontConnected(){};
	virtual void OnFrontDisconnected(int nReason){};
	
	///CPUӦ��
	virtual void OnRspQryTopCpuInfoTopic(CShfeFtdcRspQryTopCpuInfoField *pRspQryTopCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///MemӦ��
	virtual void OnRspQryTopMemInfoTopic(CShfeFtdcRspQryTopMemInfoField *pRspQryTopMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///processӦ��
	virtual void OnRspQryTopProcessInfoTopic(CShfeFtdcRspQryTopProcessInfoField *pRspQryTopProcessInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///filesystemӦ��
	virtual void OnRspQryFileSystemInfoTopic(CShfeFtdcRspQryFileSystemInfoField *pRspQryFileSystemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///networkӦ��
	virtual void OnRspQryNetworkInfoTopic(CShfeFtdcRspQryNetworkInfoField *pRspQryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///����������ϢӦ��
	virtual void OnRspQryHostEnvTopic(CShfeFtdcRspQryHostEnvCommonField *pRspQryHostEnvCommon, CShfeFtdcRspQryHostEnvLanField *pRspQryHostEnvLan, CShfeFtdcRspQryHostEnvStorageField *pRspQryHostEnvStorage, CShfeFtdcRspQryHostEnvIOField *pRspQryHostEnvIO, CShfeFtdcRspQryHostEnvFSField *pRspQryHostEnvFS, CShfeFtdcRspQryHostEnvSwapField *pRspQryHostEnvSwap, CShfeFtdcRspQryHostEnvLanCfgField *pRspQryHostEnvLanCfg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��ü�ض�����ϢӦ��
	virtual void OnRspQryMonitorObjectTopic(CShfeFtdcRspQryMonitorObjectField *pRspQryMonitorObject, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///���ҵ����̺������Ķ�Ӧ��ϵӦ��
	virtual void OnRspQryObjectRationalTopic(CShfeFtdcRspQryObjectRationalField *pRspQryObjectRational, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��־�ļ�����Ӧ��
	virtual void OnRspQrySyslogInfoTopic(CShfeFtdcRspQrySyslogInfoField *pRspQrySyslogInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///������ݶ���Ӧ��
	virtual void OnRspQrySubscriberTopic(CShfeFtdcRspQrySubscriberField *pRspQrySubscriber, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�����ϵ��ѯӦ��
	virtual void OnRspQryOidRelationTopic(CShfeFtdcRspQryOidRelationField *pRspQryOidRelation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�û���Ϣ��ѯ����Ӧ��
	virtual void OnRspQryUserInfoTopic(CShfeFtdcRspQryUserInfoField *pRspQryUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�����û���Ϣ��ѯ����Ӧ��
	virtual void OnRspQryOnlineUserInfoTopic(CShfeFtdcRspQryOnlineUserInfoField *pRspQryOnlineUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�澯�¼���ѯ����Ӧ��
	virtual void OnRspQryWarningEventTopic(CShfeFtdcRspQryWarningEventField *pRspQryWarningEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///����״ָ̬���ѯӦ��
	virtual void OnRspQryObjectAttrTopic(CShfeFtdcRspQryObjectAttrField *pRspQryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��Ч������ѯӦ��
	virtual void OnRspQryInvalidateOrderTopic(CShfeFtdcRspQryInvalidateOrderField *pRspQryInvalidateOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///����״̬��ѯӦ��
	virtual void OnRspQryOrderStatusTopic(CShfeFtdcRspQryOrderStatusField *pRspQryOrderStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�����ɽ���ѯӦ��
	virtual void OnRspQryBargainOrderTopic(CShfeFtdcRspQryBargainOrderField *pRspQryBargainOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��Լ�������Բ�ѯӦ��
	virtual void OnRspQryInstPropertyTopic(CShfeFtdcRspQryInstPropertyField *pRspQryInstProperty, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��Լ��֤���ʲ�ѯӦ��
	virtual void OnRspQryMarginRateTopic(CShfeFtdcRspQryMarginRateField *pRspQryMarginRate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��Լ�ǵ�ͣ���ѯӦ��
	virtual void OnRspQryPriceLimitTopic(CShfeFtdcRspQryPriceLimitField *pRspQryPriceLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��Ա�޲ֲ�ѯӦ��
	virtual void OnRspQryPartPosiLimitTopic(CShfeFtdcRspQryPartPosiLimitField *pRspQryPartPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�ͻ��޲ֲ�ѯӦ��
	virtual void OnRspQryClientPosiLimitTopic(CShfeFtdcRspQryClientPosiLimitField *pRspQryClientPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///����ͻ��޲ֲ�ѯӦ��
	virtual void OnRspQrySpecialPosiLimitTopic(CShfeFtdcRspQrySpecialPosiLimitField *pRspQrySpecialPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�˻�������ѯӦ��
	virtual void OnRspQryTransactionChgTopic(CShfeFtdcRspQryTransactionChgField *pRspQryTransactionChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�ͻ����ݱ䶯��ѯӦ��
	virtual void OnRspQryClientChgTopic(CShfeFtdcRspQryClientChgField *pRspQryClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��Ա�ͻ����ձ䶯��ѯӦ��
	virtual void OnRspQryPartClientChgTopic(CShfeFtdcRspQryPartClientChgField *pRspQryPartClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�޲����ݱ䶯��ѯӦ��
	virtual void OnRspQryPosiLimitChgTopic(CShfeFtdcRspQryPosiLimitChgField *pRspQryPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��ֵ��ȱ䶯��ѯӦ��
	virtual void OnRspQryHedgeDetailChgTopic(CShfeFtdcRspQryHedgeDetailChgField *pRspQryHedgeDetailChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��Ա�䶯��ѯӦ��
	virtual void OnRspQryParticipantChgTopic(CShfeFtdcRspQryParticipantChgField *pRspQryParticipantChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��֤���ʱ䶯��ѯӦ��
	virtual void OnRspQryMarginRateChgTopic(CShfeFtdcRspQryMarginRateChgField *pRspQryMarginRateChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///IP��ַ�䶯��ѯӦ��
	virtual void OnRspQryUserIpChgTopic(CShfeFtdcRspQryUserIpChgField *pRspQryUserIpChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�޲����ݱ䶯��ѯӦ��
	virtual void OnRspQryClientPosiLimitChgTopic(CShfeFtdcRspQryClientPosiLimitChgField *pRspQryClientPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�޲����ݱ䶯��ѯӦ��
	virtual void OnRspQrySpecPosiLimitChgTopic(CShfeFtdcRspQrySpecPosiLimitChgField *pRspQrySpecPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��ʷ����״ָ̬���ѯӦ��
	virtual void OnRspQryHistoryObjectAttrTopic(CShfeFtdcRspQryHistoryObjectAttrField *pRspQryHistoryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///ǰ����Ӧ��Ϣ��ѯӦ��
	virtual void OnRspQryFrontInfoTopic(CShfeFtdcRspQryFrontInfoField *pRspQryFrontInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�û���¼Ӧ��
	virtual void OnRspQrySysUserLoginTopic(CShfeFtdcRspQrySysUserLoginField *pRspQrySysUserLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�û��ǳ�Ӧ��
	virtual void OnRspQrySysUserLogoutTopic(CShfeFtdcRspQrySysUserLogoutField *pRspQrySysUserLogout, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�û��޸�����Ӧ��
	virtual void OnRspQrySysUserPasswordUpdateTopic(CShfeFtdcRspQrySysUserPasswordUpdateField *pRspQrySysUserPasswordUpdate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///ע���û�Ӧ��
	virtual void OnRspQrySysUserRegisterTopic(CShfeFtdcRspQrySysUserRegisterField *pRspQrySysUserRegister, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///ɾ���û�Ӧ��
	virtual void OnRspQrySysUserDeleteTopic(CShfeFtdcRspQrySysUserDeleteField *pRspQrySysUserDelete, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��Ա��ʼ��Ӧ��
	virtual void OnRspQryParticipantInitTopic(CShfeFtdcRspQryParticipantInitField *pRspQryParticipantInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��ϯ��ʼ��Ӧ��
	virtual void OnRspQryUserInitTopic(CShfeFtdcRspQryUserInitField *pRspQryUserInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�ͻ���ʼ��Ӧ��
	virtual void OnRspQryClientInitTopic(CShfeFtdcRspQryClientInitField *pRspQryClientInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///������־��ѯӦ��
	virtual void OnRspQryTradeLogTopic(CShfeFtdcRspQryTradeLogField *pRspQryTradeLog, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///����ϵͳ��¼��Ϣ
	virtual void OnRspQryTradeUserLoginInfoTopic(CShfeFtdcRspQryTradeUserLoginInfoField *pRspQryTradeUserLoginInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��Ա���ײ�ѯӦ��
	virtual void OnRspQryPartTradeTopic(CShfeFtdcRspQryPartTradeField *pRspQryPartTrade, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///���׷�ֵ��ѯӦ��
	virtual void OnRspQryTradepeakTopic(CShfeFtdcRspQryTradepeakField *pRspQryTradepeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///
	virtual void OnRspQryHistoryCpuInfoTopic(CShfeFtdcRspQryHistoryCpuInfoField *pRspQryHistoryCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///
	virtual void OnRspQryHistoryMemInfoTopic(CShfeFtdcRspQryHistoryMemInfoField *pRspQryHistoryMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///
	virtual void OnRspQryHistoryNetworkInfoTopic(CShfeFtdcRspQryHistoryNetworkInfoField *pRspQryHistoryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///���ϵͳ�����û�Ӧ��
	virtual void OnRspQryMonitorOnlineUser(CShfeFtdcRspQryMonitorOnlineUserField *pRspQryMonitorOnlineUser, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///����ϵͳǰ��ͳ��Ӧ��
	virtual void OnRspQryFrontStat(CShfeFtdcRspQryFrontStatField *pRspQryFrontStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��ʷ��ֵ��ѯӦ��
	virtual void OnRspQryHistoryTradePeakTopic(CShfeFtdcRspQryHistoryTradePeakField *pRspQryHistoryTradePeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��־�¼���ѯӦ��
	virtual void OnRspQrySyslogEventTopic(CShfeFtdcRspQrySyslogEventField *pRspQrySyslogEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///WebӦ����Ϣ
	virtual void OnRspQryWebAppInfoTopic(CShfeFtdcRspQryWebAppInfoField *pRspQryWebAppInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///Ӧ��servlet��Ϣ
	virtual void OnRspQryServletInfoTopic(CShfeFtdcRspQryServletInfoField *pRspQryServletInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�ļ���Ϣ
	virtual void OnRspQryFileInfoTopic(CShfeFtdcRspQryFileInfoField *pRspQryFileInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///Ӧ�ûỰ��Ϣ
	virtual void OnRspQrySessionInfoTopic(CShfeFtdcRspQrySessionInfoField *pRspQrySessionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///JDBC��Ϣ
	virtual void OnRspQryJDBCInfoTopic(CShfeFtdcRspQryJDBCInfoField *pRspQryJDBCInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�߳���Ϣ
	virtual void OnRspQryThreadInfoTopic(CShfeFtdcRspQryThreadInfoField *pRspQryThreadInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�������Ϣ
	virtual void OnRspQryVMInfoTopic(CShfeFtdcRspQryVMInfoField *pRspQryVMInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///ϵͳ������Ϣ
	virtual void OnRspQryPropertyInfoTopic(CShfeFtdcRspQryPropertyInfoField *pRspQryPropertyInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///ϵͳ�ڴ����Ϣ
	virtual void OnRspQryMemPoolInfoTopic(CShfeFtdcRspQryMemPoolInfoField *pRspQryMemPoolInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�ļ�������Ϣ
	virtual void OnRspQryFileContentInfoTopic(CShfeFtdcRspQryFileContentInfoField *pRspQryFileContentInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///������Ϣ
	virtual void OnRspQryConnectionInfoTopic(CShfeFtdcRspQryConnectionInfoField *pRspQryConnectionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��������Ϣ
	virtual void OnRspQryConnectorInfoTopic(CShfeFtdcRspQryConnectorInfoField *pRspQryConnectorInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///���ݿ��ѯӦ��
	virtual void OnRspQryDBQueryTopic(CShfeFtdcRspQryDBQueryField *pRspQryDBQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///ͨ�÷���Ӧ��
	virtual void OnRspQryGeneralFieldTopic(CShfeFtdcSysGeneralFieldField *pSysGeneralField, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�ļ�����Ӧ��
	virtual void OnRspQryGetFileTopic(CShfeFtdcRspQryGetFileField *pRspQryGetFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�澯��ϸ
	virtual void OnRspQryWarningQueryTopic(CShfeFtdcRspQryWarningQueryField *pRspQryWarningQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///ͨ�ò���
	virtual void OnRspQryGeneralOperateTopic(CShfeFtdcRspQryGeneralOperateField *pRspQryGeneralOperate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�����豸���ӹ�ϵ
	virtual void OnRspQryNetDeviceLinkedTopic(CShfeFtdcRspQryNetDeviceLinkedField *pRspQryNetDeviceLinked, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///����ϵͳ��¼��Ϣ
	virtual void OnRspQryTradeUserLoginStatTopic(CShfeFtdcRspQryTradeUserLoginStatField *pRspQryTradeUserLoginStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///����ϵͳǰ�ñ�����Ӧ��Ϣ
	virtual void OnRspQryTradeFrontOrderRttStatTopic(CShfeFtdcRspQryTradeFrontOrderRttStatField *pRspQryTradeFrontOrderRttStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��Աϯλ����״̬
	virtual void OnRspQryParticTradeOrderStatesTopic(CShfeFtdcRspQryParticTradeOrderStatesField *pRspQryParticTradeOrderStates, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///ϵͳ·����Ϣ
	virtual void OnRspQryRouterInfoTopic(CShfeFtdcRspQryRouterInfoField *pRspQryRouterInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///����I/O��Ϣ
	virtual void OnRspQryDiskIOTopic(CShfeFtdcRspQryDiskIOField *pRspQryDiskIO, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///ϵͳ״̬��Ϣ
	virtual void OnRspQryStatInfoTopic(CShfeFtdcRspQryStatInfoField *pRspQryStatInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///����ϵͳǰ�ñ����ֲ�����
	virtual void OnRspQryTradeOrderRttCutLineTopic(CShfeFtdcRspQryTradeOrderRttCutLineField *pRspQryTradeOrderRttCutLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��Ա�ͻ���Ϣ
	virtual void OnRspQryClientInfoTopic(CShfeFtdcRspQryClientInfoField *pRspQryClientInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///Ӧ���¼�����
	virtual void OnRspQryEventDescriptionTopic(CShfeFtdcRspQryEventDescriptionField *pRspQryEventDescription, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///Ӧ��ǰ��ΨһID��Ϣ
	virtual void OnRspQryFrontUniqueIDTopic(CShfeFtdcRspQryFrontUniqueIDField *pRspQryFrontUniqueID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��Ա��·��ַ�����Ӧ
	virtual void OnRspQryNetPartyLinkAddrChangeTopic(CShfeFtdcRspQryNetPartyLinkAddrChangeField *pRspQryNetPartyLinkAddrChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///Ӧ����ɾ����Ա�б���Ϣ
	virtual void OnRspQryNetDelPartyLinkInfoTopic(CShfeFtdcRspQryNetDelPartyLinkInfoField *pRspQryNetDelPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///����������������
	virtual void OnRspQryPerformanceTopTopic(CShfeFtdcRspQryPerformanceTopField *pRspQryPerformanceTop, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///����Լ״̬�л�����
	virtual void OnRspQryInstrumentStatusTopic(CShfeFtdcRspQryInstrumentStatusField *pRspQryInstrumentStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///���غ�Լ���׽���Ϣ
	virtual void OnRspQryCurrTradingSegmentAttrTopic(CShfeFtdcRspQryCurrTradingSegmentAttrField *pRspQryCurrTradingSegmentAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�����������Ӧ��
	virtual void OnRspQryNetAreaTopic(CShfeFtdcRspQryNetAreaField *pRspQryNetArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��������Ӧ��
	virtual void OnRspQryNetSubAreaTopic(CShfeFtdcRspQryNetSubAreaField *pRspQryNetSubArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��������IPӦ��
	virtual void OnRspQryNetSubAreaIPTopic(CShfeFtdcRspQryNetSubAreaIPField *pRspQryNetSubAreaIP, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�����豸
	virtual void OnRspQryNetDeviceTopic(CShfeFtdcRspQryNetDeviceField *pRspQryNetDevice, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�����豸̽������Ӧ��
	virtual void OnRspQryNetDeviceDetectTopic(CShfeFtdcRspQryNetDeviceDetectField *pRspQryNetDeviceDetect, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��¥
	virtual void OnRspQryNetBuildingTopic(CShfeFtdcRspQryNetBuildingField *pRspQryNetBuilding, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///����
	virtual void OnRspQryNetRoomTopic(CShfeFtdcRspQryNetRoomField *pRspQryNetRoom, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///����
	virtual void OnRspQryNetCabinetsTopic(CShfeFtdcRspQryNetCabinetsField *pRspQryNetCabinets, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///OID
	virtual void OnRspQryNetOIDTopic(CShfeFtdcRspQryNetOIDField *pRspQryNetOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///ʱ�����
	virtual void OnRspQryNetTimePolicyTopic(CShfeFtdcRspQryNetTimePolicyField *pRspQryNetTimePolicy, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�ɼ�����
	virtual void OnRspQryNetGatherTaskTopic(CShfeFtdcRspQryNetGatherTaskField *pRspQryNetGatherTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�豸���
	virtual void OnRspQryNetDeviceChgTopic(CShfeFtdcRspQryNetDeviceChgField *pRspQryNetDeviceChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�����豸�ͺ�
	virtual void OnRspQryNetDeviceTypeTopic(CShfeFtdcRspQryNetDeviceTypeField *pRspQryNetDeviceType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�����豸���
	virtual void OnRspQryNetDeviceCategoryTopic(CShfeFtdcRspQryNetDeviceCategoryField *pRspQryNetDeviceCategory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�豸����
	virtual void OnRspQryNetManufactoryTopic(CShfeFtdcRspQryNetManufactoryField *pRspQryNetManufactory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�豸��ͬ��
	virtual void OnRspQryNetCommunityTopic(CShfeFtdcRspQryNetCommunityField *pRspQryNetCommunity, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�˿�����
	virtual void OnRspQryNetPortTypeTopic(CShfeFtdcRspQryNetPortTypeField *pRspQryNetPortType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��Ա����ص�
	virtual void OnRspQryNetPartAccessSpotTopic(CShfeFtdcRspQryNetPartAccessSpotField *pRspQryNetPartAccessSpot, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�˿�
	virtual void OnRspQryNetInterfaceTopic(CShfeFtdcRspQryNetInterfaceField *pRspQryNetInterface, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///GeneralOID
	virtual void OnRspQryNetGeneralOIDTopic(CShfeFtdcRspQryNetGeneralOIDField *pRspQryNetGeneralOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��ض������
	virtual void OnRspQryNetMonitorTypeTopic(CShfeFtdcRspQryNetMonitorTypeField *pRspQryNetMonitorType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///ָ��ͳ��
	virtual void OnRspQryNetMonitorAttrScopeTopic(CShfeFtdcRspQryNetMonitorAttrScopeField *pRspQryNetMonitorAttrScope, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///���ָ���
	virtual void OnRspQryNetMonitorAttrTypeTopic(CShfeFtdcRspQryNetMonitorAttrTypeField *pRspQryNetMonitorAttrType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��ض���ָ���
	virtual void OnRspQryNetMonitorObjectAttrTopic(CShfeFtdcRspQryNetMonitorObjectAttrField *pRspQryNetMonitorObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�豸�������
	virtual void OnRspQryNetMonitorDeviceGroupTopic(CShfeFtdcRspQryNetMonitorDeviceGroupField *pRspQryNetMonitorDeviceGroup, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///������Ϣ��
	virtual void OnRspQryNetMonitorTaskInfoTopic(CShfeFtdcRspQryNetMonitorTaskInfoField *pRspQryNetMonitorTaskInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��������
	virtual void OnRspQryNetMonitorTaskResultTopic(CShfeFtdcRspQryNetMonitorTaskResultField *pRspQryNetMonitorTaskResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�������
	virtual void OnRspQryNetMonitorTaskObjectSetTopic(CShfeFtdcRspQryNetMonitorTaskObjectSetField *pRspQryNetMonitorTaskObjectSet, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��Ա��·��Ϣ��
	virtual void OnRspQryNetPartyLinkInfoTopic(CShfeFtdcRspQryNetPartyLinkInfoField *pRspQryNetPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��ض���ָ����ձ�
	virtual void OnRspQryNetMonitorActionAttrTopic(CShfeFtdcRspQryNetMonitorActionAttrField *pRspQryNetMonitorActionAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///ģ��
	virtual void OnRspQryNetModuleTopic(CShfeFtdcRspQryNetModuleField *pRspQryNetModule, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///������״̬��
	virtual void OnRspQryNetMonitorTaskStatusResultTopic(CShfeFtdcRspQryNetMonitorTaskStatusResultField *pRspQryNetMonitorTaskStatusResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�豸���ñ�
	virtual void OnRspQryNetCfgFileTopic(CShfeFtdcRspQryNetCfgFileField *pRspQryNetCfgFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///���������������
	virtual void OnRspQryNetMonitorDeviceTaskTopic(CShfeFtdcRspQryNetMonitorDeviceTaskField *pRspQryNetMonitorDeviceTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�ļ�ͨ�ò���
	virtual void OnRspQryFileGeneralOperTopic(CShfeFtdcRspQryFileGeneralOperField *pRspQryFileGeneralOper, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///���߱�
	virtual void OnRspQryNetBaseLineTopic(CShfeFtdcRspQryNetBaseLineField *pRspQryNetBaseLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///���߽����
	virtual void OnRspQryNetBaseLineResultTopic(CShfeFtdcRspQryNetBaseLineResultField *pRspQryNetBaseLineResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��Ա��·״̬��Ϣ��
	virtual void OnRspQryNetPartyLinkStatusInfoTopic(CShfeFtdcRspQryNetPartyLinkStatusInfoField *pRspQryNetPartyLinkStatusInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///����ping���
	virtual void OnRspQryNetLocalPingResultInfoTopic(CShfeFtdcRspQryNetLocalPingResultInfoField *pRspQryNetLocalPingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///Զ��ping���
	virtual void OnRspQryNetRomotePingResultInfoTopic(CShfeFtdcRspQryNetRomotePingResultInfoField *pRspQryNetRomotePingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///���ػ�Ա��·���ñ�
	virtual void OnRspQryMemberLinkCostTopic(CShfeFtdcRspQryMemberLinkCostField *pRspQryMemberLinkCost, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///���طǻ�Ա��·����Ϣ
	virtual void OnRspQryNetNonPartyLinkInfoTopic(CShfeFtdcRspQryNetNonPartyLinkInfoField *pRspQryNetNonPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};



	///CPUӦ��
	virtual void OnRtnTopCpuInfoTopic(CShfeFtdcRtnTopCpuInfoField *pRtnTopCpuInfo){};

	///MemӦ��
	virtual void OnRtnTopMemInfoTopic(CShfeFtdcRtnTopMemInfoField *pRtnTopMemInfo){};

	///processӦ��
	virtual void OnRtnTopProcessInfoTopic(CShfeFtdcRtnTopProcessInfoField *pRtnTopProcessInfo){};

	///filesystemӦ��
	virtual void OnRtnFileSystemInfoTopic(CShfeFtdcRtnFileSystemInfoField *pRtnFileSystemInfo){};

	///networkӦ��
	virtual void OnRtnNetworkInfoTopic(CShfeFtdcRtnNetworkInfoField *pRtnNetworkInfo){};

	///����������ϢӦ��
	virtual void OnRtnHostEnvTopic(CShfeFtdcRspQryHostEnvCommonField *pRspQryHostEnvCommon, CShfeFtdcRspQryHostEnvLanField *pRspQryHostEnvLan, CShfeFtdcRspQryHostEnvStorageField *pRspQryHostEnvStorage, CShfeFtdcRspQryHostEnvIOField *pRspQryHostEnvIO, CShfeFtdcRspQryHostEnvFSField *pRspQryHostEnvFS, CShfeFtdcRspQryHostEnvSwapField *pRspQryHostEnvSwap, CShfeFtdcRspQryHostEnvLanCfgField *pRspQryHostEnvLanCfg, CShfeFtdcRspInfoField *pRspInfo){};

	///��ü�ض�����ϢӦ��
	virtual void OnRtnMonitorObjectTopic(CShfeFtdcRtnMonitorObjectField *pRtnMonitorObject){};

	///���ҵ����̺������Ķ�Ӧ��ϵӦ��
	virtual void OnRtnObjectRationalTopic(CShfeFtdcRtnObjectRationalField *pRtnObjectRational){};

	///��־�ļ�����Ӧ��
	virtual void OnRtnSyslogInfoTopic(CShfeFtdcRtnSyslogInfoField *pRtnSyslogInfo){};

	///�����ϵ��ѯӦ��
	virtual void OnRtnOidRelationTopic(CShfeFtdcRtnOidRelationField *pRtnOidRelation){};

	///�û���Ϣ��ѯ����Ӧ��
	virtual void OnRtnUserInfoTopic(CShfeFtdcRtnUserInfoField *pRtnUserInfo){};

	///�����û���Ϣ��ѯ����Ӧ��
	virtual void OnRtnOnlineUserInfoTopic(CShfeFtdcRtnOnlineUserInfoField *pRtnOnlineUserInfo){};

	///�澯�¼���ѯ����Ӧ��
	virtual void OnRtnWarningEventTopic(CShfeFtdcRtnWarningEventField *pRtnWarningEvent){};

	///����״ָ̬���ѯӦ��
	virtual void OnRtnObjectAttrTopic(CShfeFtdcRtnObjectAttrField *pRtnObjectAttr){};

	///��Ч������ѯӦ��
	virtual void OnRtnInvalidateOrderTopic(CShfeFtdcRtnInvalidateOrderField *pRtnInvalidateOrder){};

	///����״̬��ѯӦ��
	virtual void OnRtnOrderStatusTopic(CShfeFtdcRtnOrderStatusField *pRtnOrderStatus){};

	///�����ɽ���ѯӦ��
	virtual void OnRtnBargainOrderTopic(CShfeFtdcRtnBargainOrderField *pRtnBargainOrder){};

	///��Լ�������Բ�ѯӦ��
	virtual void OnRtnInstPropertyTopic(CShfeFtdcRtnInstPropertyField *pRtnInstProperty){};

	///��Լ��֤���ʲ�ѯӦ��
	virtual void OnRtnMarginRateTopic(CShfeFtdcRtnMarginRateField *pRtnMarginRate){};

	///��Լ�ǵ�ͣ���ѯӦ��
	virtual void OnRtnPriceLimitTopic(CShfeFtdcRtnPriceLimitField *pRtnPriceLimit){};

	///��Ա�޲ֲ�ѯӦ��
	virtual void OnRtnPartPosiLimitTopic(CShfeFtdcRtnPartPosiLimitField *pRtnPartPosiLimit){};

	///�ͻ��޲ֲ�ѯӦ��
	virtual void OnRtnClientPosiLimitTopic(CShfeFtdcRtnClientPosiLimitField *pRtnClientPosiLimit){};

	///����ͻ��޲ֲ�ѯӦ��
	virtual void OnRtnSpecialPosiLimitTopic(CShfeFtdcRtnSpecialPosiLimitField *pRtnSpecialPosiLimit){};

	///�˻�������ѯӦ��
	virtual void OnRtnTransactionChgTopic(CShfeFtdcRtnTransactionChgField *pRtnTransactionChg){};

	///�ͻ����ݱ䶯��ѯӦ��
	virtual void OnRtnClientChgTopic(CShfeFtdcRtnClientChgField *pRtnClientChg){};

	///��Ա�ͻ����ձ䶯��ѯӦ��
	virtual void OnRtnPartClientChgTopic(CShfeFtdcRtnPartClientChgField *pRtnPartClientChg){};

	///�޲����ݱ䶯��ѯӦ��
	virtual void OnRtnPosiLimitChgTopic(CShfeFtdcRtnPosiLimitChgField *pRtnPosiLimitChg){};

	///��ֵ��ȱ䶯��ѯӦ��
	virtual void OnRtnHedgeDetailChgTopic(CShfeFtdcRtnHedgeDetailChgField *pRtnHedgeDetailChg){};

	///��Ա�䶯��ѯӦ��
	virtual void OnRtnParticipantChgTopic(CShfeFtdcRtnParticipantChgField *pRtnParticipantChg){};

	///��֤���ʱ䶯��ѯӦ��
	virtual void OnRtnMarginRateChgTopic(CShfeFtdcRtnMarginRateChgField *pRtnMarginRateChg){};

	///IP��ַ�䶯��ѯӦ��
	virtual void OnRtnUserIpChgTopic(CShfeFtdcRtnUserIpChgField *pRtnUserIpChg){};

	///�޲����ݱ䶯��ѯӦ��
	virtual void OnRtnClientPosiLimitChgTopic(CShfeFtdcRtnClientPosiLimitChgField *pRtnClientPosiLimitChg){};

	///�޲����ݱ䶯��ѯӦ��
	virtual void OnRtnSpecPosiLimitChgTopic(CShfeFtdcRtnSpecPosiLimitChgField *pRtnSpecPosiLimitChg){};

	///��ʷ����״ָ̬���ѯӦ��
	virtual void OnRtnHistoryObjectAttrTopic(CShfeFtdcRtnHistoryObjectAttrField *pRtnHistoryObjectAttr){};

	///ǰ����Ӧ��Ϣ��ѯӦ��
	virtual void OnRtnFrontInfoTopic(CShfeFtdcRtnFrontInfoField *pRtnFrontInfo){};

	///��Ա��ʼ��Ӧ��
	virtual void OnRtnParticipantInitTopic(CShfeFtdcRtnParticipantInitField *pRtnParticipantInit){};

	///��ϯ��ʼ��Ӧ��
	virtual void OnRtnUserInitTopic(CShfeFtdcRtnUserInitField *pRtnUserInit){};

	///�ͻ���ʼ��Ӧ��
	virtual void OnRtnClientInitTopic(CShfeFtdcRtnClientInitField *pRtnClientInit){};

	///������־��ѯӦ��
	virtual void OnRtnTradeLogTopic(CShfeFtdcRtnTradeLogField *pRtnTradeLog){};

	///����ϵͳ��¼��Ϣ
	virtual void OnRtnTradeUserLoginInfoTopic(CShfeFtdcRtnTradeUserLoginInfoField *pRtnTradeUserLoginInfo){};

	///
	virtual void OnRtnUpdateSysConfigTopic(CShfeFtdcRtnUpdateSysConfigField *pRtnUpdateSysConfig){};

	///
	virtual void OnRtnSysUser(CShfeFtdcRtnSysUserField *pRtnSysUser){};

	///���ϵͳʱ��ͬ��
	virtual void OnRtnSysTimeSyncTopic(CShfeFtdcRtnSysTimeSyncField *pRtnSysTimeSync){};

	///���������л�֪ͨ
	virtual void OnRtnDataCenterChgTopic(CShfeFtdcRtnDataCenterChgField *pRtnDataCenterChg){};

	///��־�¼�Ӧ��
	virtual void OnRtnSyslogEventTopic(CShfeFtdcRtnSyslogEventField *pRtnSyslogEvent){};

	///WebӦ����Ϣ
	virtual void OnRtnWebAppInfoTopic(CShfeFtdcRtnWebAppInfoField *pRtnWebAppInfo){};

	///Ӧ��servlet��Ϣ
	virtual void OnRtnServletInfoTopic(CShfeFtdcRtnServletInfoField *pRtnServletInfo){};

	///�ļ���Ϣ
	virtual void OnRtnFileInfoTopic(CShfeFtdcRtnFileInfoField *pRtnFileInfo){};

	///Ӧ�ûỰ��Ϣ
	virtual void OnRtnSessionInfoTopic(CShfeFtdcRtnSessionInfoField *pRtnSessionInfo){};

	///JDBC��Ϣ
	virtual void OnRtnJDBCInfoTopic(CShfeFtdcRtnJDBCInfoField *pRtnJDBCInfo){};

	///�߳���Ϣ
	virtual void OnRtnThreadInfoTopic(CShfeFtdcRtnThreadInfoField *pRtnThreadInfo){};

	///�������Ϣ
	virtual void OnRtnVMInfoTopic(CShfeFtdcRtnVMInfoField *pRtnVMInfo){};

	///ϵͳ������Ϣ
	virtual void OnRtnPropertyInfoTopic(CShfeFtdcRtnPropertyInfoField *pRtnPropertyInfo){};

	///ϵͳ�ڴ����Ϣ
	virtual void OnRtnMemPoolInfoTopic(CShfeFtdcRtnMemPoolInfoField *pRtnMemPoolInfo){};

	///�ļ�������Ϣ
	virtual void OnRtnFileContentInfoTopic(CShfeFtdcRtnFileContentInfoField *pRtnFileContentInfo){};

	///������Ϣ
	virtual void OnRtnConnectionInfoTopic(CShfeFtdcRtnConnectionInfoField *pRtnConnectionInfo){};

	///��������Ϣ
	virtual void OnRtnConnectorInfoTopic(CShfeFtdcRtnConnectorInfoField *pRtnConnectorInfo){};

	///���ݿ��ѯӦ��
	virtual void OnRtnDBQueryTopic(CShfeFtdcRtnDBQueryField *pRtnDBQuery){};

	///ͨ�÷���Ӧ��
	virtual void OnRtnGeneralFieldTopic(CShfeFtdcSysGeneralFieldField *pSysGeneralField){};

	///�澯������
	virtual void OnRtnWarningActiveChange(CShfeFtdcRtnWarningActiveChangeField *pRtnWarningActiveChange){};

	///ͨ�ò���
	virtual void OnRtnGeneralOperateTopic(CShfeFtdcRtnGeneralOperateField *pRtnGeneralOperate){};

	///�����豸���ӹ�ϵ
	virtual void OnRtnNetDeviceLinkedTopic(CShfeFtdcRtnNetDeviceLinkedField *pRtnNetDeviceLinked){};

	///����ϵͳǰ�ñ�����Ӧ��Ϣ
	virtual void OnRtnTradeFrontOrderRttStatTopic(CShfeFtdcRtnTradeFrontOrderRttStatField *pRtnTradeFrontOrderRttStat){};

	///��Աϯλ����״̬
	virtual void OnRtnParticTradeOrderStatesTopic(CShfeFtdcRtnParticTradeOrderStatesField *pRtnParticTradeOrderStates){};

	///ϵͳ·����Ϣ
	virtual void OnRtnRouterInfoTopic(CShfeFtdcRtnRouterInfoField *pRtnRouterInfo){};

	///����I/O��Ϣ
	virtual void OnRtnDiskIOTopic(CShfeFtdcRtnDiskIOField *pRtnDiskIO){};

	///ϵͳ״̬��Ϣ
	virtual void OnRtnStatInfoTopic(CShfeFtdcRtnStatInfoField *pRtnStatInfo){};

	///����ϵͳǰ�ñ����ֲ�����
	virtual void OnRtnTradeOrderRttCutLineTopic(CShfeFtdcRtnTradeOrderRttCutLineField *pRtnTradeOrderRttCutLine){};

	///��Ա�ͻ���Ϣ
	virtual void OnRtnClientInfoTopic(CShfeFtdcRtnClientInfoField *pRtnClientInfo){};

	///�����¼�����
	virtual void OnRtnEventDescriptionTopic(CShfeFtdcRtnEventDescriptionField *pRtnEventDescription){};

	///����ǰ��ΨһID��Ϣ
	virtual void OnRtnFrontUniqueIDTopic(CShfeFtdcRtnFrontUniqueIDField *pRtnFrontUniqueID){};

	///���Ļ�Ա��·��ַ�����Ϣ
	virtual void OnRtnNetPartyLinkAddrChangeTopic(CShfeFtdcRtnNetPartyLinkAddrChangeField *pRtnNetPartyLinkAddrChange){};

	///������ɾ����Ա�б���Ϣ
	virtual void OnRtnNetDelPartyLinkInfoTopic(CShfeFtdcRtnNetDelPartyLinkInfoField *pRtnNetDelPartyLinkInfo){};

	///����������������
	virtual void OnRtnPerformanceTopTopic(CShfeFtdcRtnPerformanceTopField *pRtnPerformanceTop){};

	///����Լ״̬�л�����
	virtual void OnRtnInstrumentStatusTopic(CShfeFtdcRtnInstrumentStatusField *pRtnInstrumentStatus){};

	///���ĺ�Լ���׽���Ϣ
	virtual void OnRtnCurrTradingSegmentAttrTopic(CShfeFtdcRtnCurrTradingSegmentAttrField *pRtnCurrTradingSegmentAttr){};

	///�����������Ӧ��
	virtual void OnRtnNetAreaTopic(CShfeFtdcRtnNetAreaField *pRtnNetArea){};

	///��������Ӧ��
	virtual void OnRtnNetSubAreaTopic(CShfeFtdcRtnNetSubAreaField *pRtnNetSubArea){};

	///��������IPӦ��
	virtual void OnRtnNetSubAreaIPTopic(CShfeFtdcRtnNetSubAreaIPField *pRtnNetSubAreaIP){};

	///�����豸
	virtual void OnRtnNetDeviceTopic(CShfeFtdcRtnNetDeviceField *pRtnNetDevice){};

	///��¥
	virtual void OnRtnNetBuildingTopic(CShfeFtdcRtnNetBuildingField *pRtnNetBuilding){};

	///����
	virtual void OnRtnNetRoomTopic(CShfeFtdcRtnNetRoomField *pRtnNetRoom){};

	///����
	virtual void OnRtnNetCabinetsTopic(CShfeFtdcRtnNetCabinetsField *pRtnNetCabinets){};

	///OID
	virtual void OnRtnNetOIDTopic(CShfeFtdcRtnNetOIDField *pRtnNetOID){};

	///ʱ�����
	virtual void OnRtnNetTimePolicyTopic(CShfeFtdcRtnNetTimePolicyField *pRtnNetTimePolicy){};

	///�ɼ�����
	virtual void OnRtnNetGatherTaskTopic(CShfeFtdcRtnNetGatherTaskField *pRtnNetGatherTask){};

	///�豸���
	virtual void OnRtnNetDeviceChgTopic(CShfeFtdcRtnNetDeviceChgField *pRtnNetDeviceChg){};

	///�����豸�ͺ�
	virtual void OnRtnNetDeviceTypeTopic(CShfeFtdcRtnNetDeviceTypeField *pRtnNetDeviceType){};

	///�����豸���
	virtual void OnRtnNetDeviceCategoryTopic(CShfeFtdcRtnNetDeviceCategoryField *pRtnNetDeviceCategory){};

	///�豸����
	virtual void OnRtnNetManufactoryTopic(CShfeFtdcRtnNetManufactoryField *pRtnNetManufactory){};

	///�豸��ͬ��
	virtual void OnRtnNetCommunityTopic(CShfeFtdcRtnNetCommunityField *pRtnNetCommunity){};

	///�˿�����
	virtual void OnRtnNetPortTypeTopic(CShfeFtdcRtnNetPortTypeField *pRtnNetPortType){};

	///��Ա����ص�
	virtual void OnRtnNetPartAccessSpotTopic(CShfeFtdcRtnNetPartAccessSpotField *pRtnNetPartAccessSpot){};

	///�˿�
	virtual void OnRtnNetInterfaceTopic(CShfeFtdcRtnNetInterfaceField *pRtnNetInterface){};

	///GeneralOID
	virtual void OnRtnNetGeneralOIDTopic(CShfeFtdcRtnNetGeneralOIDField *pRtnNetGeneralOID){};

	///��ض������
	virtual void OnRtnNetMonitorTypeTopic(CShfeFtdcRtnNetMonitorTypeField *pRtnNetMonitorType){};

	///ָ��ͳ��
	virtual void OnRtnNetMonitorAttrScopeTopic(CShfeFtdcRtnNetMonitorAttrScopeField *pRtnNetMonitorAttrScope){};

	///���ָ���
	virtual void OnRtnNetMonitorAttrTypeTopic(CShfeFtdcRtnNetMonitorAttrTypeField *pRtnNetMonitorAttrType){};

	///��ض���ָ���
	virtual void OnRtnNetMonitorObjectAttrTopic(CShfeFtdcRtnNetMonitorObjectAttrField *pRtnNetMonitorObjectAttr){};

	///�豸�������
	virtual void OnRtnNetMonitorDeviceGroupTopic(CShfeFtdcRtnNetMonitorDeviceGroupField *pRtnNetMonitorDeviceGroup){};

	///������Ϣ��
	virtual void OnRtnNetMonitorTaskInfoTopic(CShfeFtdcRtnNetMonitorTaskInfoField *pRtnNetMonitorTaskInfo){};

	///��������
	virtual void OnRtnNetMonitorTaskResultTopic(CShfeFtdcRtnNetMonitorTaskResultField *pRtnNetMonitorTaskResult){};

	///�������
	virtual void OnRtnNetMonitorTaskObjectSetTopic(CShfeFtdcRtnNetMonitorTaskObjectSetField *pRtnNetMonitorTaskObjectSet){};

	///��Ա��·��Ϣ��
	virtual void OnRtnNetPartyLinkInfoTopic(CShfeFtdcRtnNetPartyLinkInfoField *pRtnNetPartyLinkInfo){};

	///ģ��
	virtual void OnRtnNetModuleTopic(CShfeFtdcRtnNetModuleField *pRtnNetModule){};

	///������״̬��
	virtual void OnRtnNetMonitorTaskStatusResultTopic(CShfeFtdcRtnNetMonitorTaskStatusResultField *pRtnNetMonitorTaskStatusResult){};

	///�豸���ñ�
	virtual void OnRtnNetCfgFileTopic(CShfeFtdcRtnNetCfgFileField *pRtnNetCfgFile){};

	///���������������
	virtual void OnRtnNetMonitorDeviceTaskTopic(CShfeFtdcRtnNetMonitorDeviceTaskField *pRtnNetMonitorDeviceTask){};

	///�ļ�ͨ�ò���
	virtual void OnRtnFileGeneralOperTopic(CShfeFtdcRtnFileGeneralOperField *pRtnFileGeneralOper){};

	///���߱�
	virtual void OnRtnNetBaseLineTopic(CShfeFtdcRtnNetBaseLineField *pRtnNetBaseLine){};

	///���߽����
	virtual void OnRtnNetBaseLineResultTopic(CShfeFtdcRtnNetBaseLineResultField *pRtnNetBaseLineResult){};

	///��Ա��·״̬��Ϣ��
	virtual void OnRtnNetPartyLinkStatusInfoTopic(CShfeFtdcRtnNetPartyLinkStatusInfoField *pRtnNetPartyLinkStatusInfo){};

	///����ping���
	virtual void OnRtnNetLocalPingResultInfoTopic(CShfeFtdcRtnNetLocalPingResultInfoField *pRtnNetLocalPingResultInfo){};

	///Զ��ping���
	virtual void OnRtnNetRomotePingResultInfoTopic(CShfeFtdcRtnNetRomotePingResultInfoField *pRtnNetRomotePingResultInfo){};

	///���Ļ�Ա��·���ñ�
	virtual void OnRtnMemberLinkCostTopic(CShfeFtdcRtnMemberLinkCostField *pRtnMemberLinkCost){};

	///���ķǻ�Ա��·����Ϣ
	virtual void OnRtnNetNonPartyLinkInfoTopic(CShfeFtdcRtnNetNonPartyLinkInfoField *pRtnNetNonPartyLinkInfo){};


	///CPU��ѯ
	virtual BOOL ReqQryTopCpuInfoTopic(CShfeFtdcReqQryTopCpuInfoField *pReqQryTopCpuInfo, int nRequestID = 0);
	
	///Mem��ѯ
	virtual BOOL ReqQryTopMemInfoTopic(CShfeFtdcReqQryTopMemInfoField *pReqQryTopMemInfo, int nRequestID = 0);
	
	///process��ѯ
	virtual BOOL ReqQryTopProcessInfoTopic(CShfeFtdcReqQryTopProcessInfoField *pReqQryTopProcessInfo, int nRequestID = 0);
	
	///filesystem��ѯ
	virtual BOOL ReqQryFileSystemInfoTopic(CShfeFtdcReqQryFileSystemInfoField *pReqQryFileSystemInfo, int nRequestID = 0);
	
	///network��ѯ
	virtual BOOL ReqQryNetworkInfoTopic(CShfeFtdcReqQryNetworkInfoField *pReqQryNetworkInfo, int nRequestID = 0);
	
	///����������Ϣ��ѯ
	virtual BOOL ReqQryHostEnvTopic(CShfeFtdcReqQryHostEnvField *pReqQryHostEnv, int nRequestID = 0);
	
	///��ü�ض�����Ϣ��ѯ
	virtual BOOL ReqQryMonitorObjectTopic(CShfeFtdcReqQryMonitorObjectField *pReqQryMonitorObject, int nRequestID = 0);
	
	///���ҵ����̺������Ķ�Ӧ��ϵ��ѯ
	virtual BOOL ReqQryObjectRationalTopic(CShfeFtdcReqQryObjectRationalField *pReqQryObjectRational, int nRequestID = 0);
	
	///��־�ļ����ݲ�ѯ
	virtual BOOL ReqQrySyslogInfoTopic(CShfeFtdcReqQrySyslogInfoField *pReqQrySyslogInfo, int nRequestID = 0);
	
	///������ݶ�������
	virtual BOOL ReqQrySubscriberTopic(CShfeFtdcReqQrySubscriberField *pReqQrySubscriber, int nRequestID = 0);
	
	///�����ϵ��ѯ
	virtual BOOL ReqQryOidRelationTopic(CShfeFtdcReqQryOidRelationField *pReqQryOidRelation, int nRequestID = 0);
	
	///�û���Ϣ��ѯ����
	virtual BOOL ReqQryUserInfoTopic(CShfeFtdcReqQryUserInfoField *pReqQryUserInfo, int nRequestID = 0);
	
	///�����û���Ϣ��ѯ����
	virtual BOOL ReqQryOnlineUserInfoTopic(CShfeFtdcReqQryOnlineUserInfoField *pReqQryOnlineUserInfo, int nRequestID = 0);
	
	///�澯�¼���ѯ����
	virtual BOOL ReqQryWarningEventTopic(CShfeFtdcReqQryWarningEventField *pReqQryWarningEvent, int nRequestID = 0);
	
	///����״ָ̬���ѯ
	virtual BOOL ReqQryObjectAttrTopic(CShfeFtdcReqQryObjectAttrField *pReqQryObjectAttr, int nRequestID = 0);
	
	///��Ч������ѯ
	virtual BOOL ReqQryInvalidateOrderTopic(CShfeFtdcReqQryInvalidateOrderField *pReqQryInvalidateOrder, int nRequestID = 0);
	
	///����״̬��ѯ
	virtual BOOL ReqQryOrderStatusTopic(CShfeFtdcReqQryOrderStatusField *pReqQryOrderStatus, int nRequestID = 0);
	
	///�����ɽ���ѯ
	virtual BOOL ReqQryBargainOrderTopic(CShfeFtdcReqQryBargainOrderField *pReqQryBargainOrder, int nRequestID = 0);
	
	///��Լ�������Բ�ѯ
	virtual BOOL ReqQryInstPropertyTopic(CShfeFtdcReqQryInstPropertyField *pReqQryInstProperty, int nRequestID = 0);
	
	///��Լ��֤���ʲ�ѯ
	virtual BOOL ReqQryMarginRateTopic(CShfeFtdcReqQryMarginRateField *pReqQryMarginRate, int nRequestID = 0);
	
	///��Լ�ǵ�ͣ���ѯ
	virtual BOOL ReqQryPriceLimitTopic(CShfeFtdcReqQryPriceLimitField *pReqQryPriceLimit, int nRequestID = 0);
	
	///��Ա�޲ֲ�ѯ
	virtual BOOL ReqQryPartPosiLimitTopic(CShfeFtdcReqQryPartPosiLimitField *pReqQryPartPosiLimit, int nRequestID = 0);
	
	///�ͻ��޲ֲ�ѯ
	virtual BOOL ReqQryClientPosiLimitTopic(CShfeFtdcReqQryClientPosiLimitField *pReqQryClientPosiLimit, int nRequestID = 0);
	
	///����ͻ��޲ֲ�ѯ
	virtual BOOL ReqQrySpecialPosiLimitTopic(CShfeFtdcReqQrySpecialPosiLimitField *pReqQrySpecialPosiLimit, int nRequestID = 0);
	
	///�˻�������ѯ
	virtual BOOL ReqQryTransactionChgTopic(CShfeFtdcReqQryTransactionChgField *pReqQryTransactionChg, int nRequestID = 0);
	
	///�ͻ����ݱ䶯��ѯ
	virtual BOOL ReqQryClientChgTopic(CShfeFtdcReqQryClientChgField *pReqQryClientChg, int nRequestID = 0);
	
	///��Ա�ͻ����ձ䶯��ѯ
	virtual BOOL ReqQryPartClientChgTopic(CShfeFtdcReqQryPartClientChgField *pReqQryPartClientChg, int nRequestID = 0);
	
	///�޲����ݱ䶯��ѯ
	virtual BOOL ReqQryPosiLimitChgTopic(CShfeFtdcReqQryPosiLimitChgField *pReqQryPosiLimitChg, int nRequestID = 0);
	
	///��ֵ��ȱ䶯��ѯ
	virtual BOOL ReqQryHedgeDetailChgTopic(CShfeFtdcReqQryHedgeDetailChgField *pReqQryHedgeDetailChg, int nRequestID = 0);
	
	///��Ա�䶯��ѯ
	virtual BOOL ReqQryParticipantChgTopic(CShfeFtdcReqQryParticipantChgField *pReqQryParticipantChg, int nRequestID = 0);
	
	///��֤���ʱ䶯��ѯ
	virtual BOOL ReqQryMarginRateChgTopic(CShfeFtdcReqQryMarginRateChgField *pReqQryMarginRateChg, int nRequestID = 0);
	
	///IP��ַ�䶯��ѯ
	virtual BOOL ReqQryUserIpChgTopic(CShfeFtdcReqQryUserIpChgField *pReqQryUserIpChg, int nRequestID = 0);
	
	///�޲����ݱ䶯��ѯ
	virtual BOOL ReqQryClientPosiLimitChgTopic(CShfeFtdcReqQryClientPosiLimitChgField *pReqQryClientPosiLimitChg, int nRequestID = 0);
	
	///�޲����ݱ䶯��ѯ
	virtual BOOL ReqQrySpecPosiLimitChgTopic(CShfeFtdcReqQrySpecPosiLimitChgField *pReqQrySpecPosiLimitChg, int nRequestID = 0);
	
	///��ʷ����״ָ̬���ѯ
	virtual BOOL ReqQryHistoryObjectAttrTopic(CShfeFtdcReqQryHistoryObjectAttrField *pReqQryHistoryObjectAttr, int nRequestID = 0);
	
	///ǰ����Ӧ��Ϣ��ѯ
	virtual BOOL ReqQryFrontInfoTopic(CShfeFtdcReqQryFrontInfoField *pReqQryFrontInfo, int nRequestID = 0);
	
	///�û���¼
	virtual BOOL ReqQrySysUserLoginTopic(CShfeFtdcReqQrySysUserLoginField *pReqQrySysUserLogin, int nRequestID = 0);
	
	///�û��ǳ�
	virtual BOOL ReqQrySysUserLogoutTopic(CShfeFtdcReqQrySysUserLogoutField *pReqQrySysUserLogout, int nRequestID = 0);
	
	///�û��޸�����
	virtual BOOL ReqQrySysUserPasswordUpdateTopic(CShfeFtdcReqQrySysUserPasswordUpdateField *pReqQrySysUserPasswordUpdate, int nRequestID = 0);
	
	///ע���û�
	virtual BOOL ReqQrySysUserRegisterTopic(CShfeFtdcReqQrySysUserRegisterField *pReqQrySysUserRegister, int nRequestID = 0);
	
	///ɾ���û�
	virtual BOOL ReqQrySysUserDeleteTopic(CShfeFtdcReqQrySysUserDeleteField *pReqQrySysUserDelete, int nRequestID = 0);
	
	///������־��ѯ
	virtual BOOL ReqQryTradeLogTopic(CShfeFtdcReqQryTradeLogField *pReqQryTradeLog, int nRequestID = 0);
	
	///�澯�¼��޸�
	virtual BOOL ReqQryWarningEventUpdateTopic(CShfeFtdcReqQryWarningEventUpdateField *pReqQryWarningEventUpdate, int nRequestID = 0);
	
	///����ϵͳ��¼��Ϣ��ѯ
	virtual BOOL ReqQryTradeUserLoginInfoTopic(CShfeFtdcReqQryTradeUserLoginInfoField *pReqQryTradeUserLoginInfo, int nRequestID = 0);
	
	///��Ա���ײ�ѯ
	virtual BOOL ReqQryPartTradeTopic(CShfeFtdcReqQryPartTradeField *pReqQryPartTrade, int nRequestID = 0);
	
	///���׷�ֵ��ѯ
	virtual BOOL ReqQryTradepeakTopic(CShfeFtdcReqQryTradepeakField *pReqQryTradepeak, int nRequestID = 0);
	
	///����ƽ̨��ʼ����Ϣ��ѯ
	virtual BOOL ReqQryParticipantInitTopic(CShfeFtdcReqQryParticipantInitField *pReqQryParticipantInit, int nRequestID = 0);
	
	///����ƽ̨��ʼ����Ϣ��ѯ
	virtual BOOL ReqQryUserInitTopic(CShfeFtdcReqQryUserInitField *pReqQryUserInit, int nRequestID = 0);
	
	///
	virtual BOOL ReqQryHistoryCpuInfoTopic(CShfeFtdcReqQryHistoryCpuInfoField *pReqQryHistoryCpuInfo, int nRequestID = 0);
	
	///
	virtual BOOL ReqQryHistoryMemInfoTopic(CShfeFtdcReqQryHistoryMemInfoField *pReqQryHistoryMemInfo, int nRequestID = 0);
	
	///
	virtual BOOL ReqQryHistoryNetworkInfoTopic(CShfeFtdcReqQryHistoryNetworkInfoField *pReqQryHistoryNetworkInfo, int nRequestID = 0);
	
	///���ϵͳ�����û���ѯ
	virtual BOOL ReqQryMonitorOnlineUser(CShfeFtdcReqQryMonitorOnlineUserField *pReqQryMonitorOnlineUser, int nRequestID = 0);
	
	///����ϵͳǰ��ͳ�Ʋ�ѯ
	virtual BOOL ReqQryFrontStat(CShfeFtdcReqQryFrontStatField *pReqQryFrontStat, int nRequestID = 0);
	
	///��ʷ��ֵ��ѯ
	virtual BOOL ReqQryHistoryTradePeakTopic(CShfeFtdcReqQryHistoryTradePeakField *pReqQryHistoryTradePeak, int nRequestID = 0);
	
	///��־�¼���ѯ
	virtual BOOL ReqQrySyslogEventTopic(CShfeFtdcReqQrySyslogEventField *pReqQrySyslogEvent, int nRequestID = 0);
	
	///��־�¼���������
	virtual BOOL ReqQrySyslogEventSubcriberTopic(CShfeFtdcReqQrySyslogEventSubcriberField *pReqQrySyslogEventSubcriber, int nRequestID = 0);
	
	///tomcat��Ϣ��ѯ
	virtual BOOL ReqQryTomcatInfoTopic(CShfeFtdcReqQryTomcatInfoField *pReqQryTomcatInfo, int nRequestID = 0);
	
	///���ݿ��ѯ
	virtual BOOL ReqQryDBQueryTopic(CShfeFtdcReqQryDBQueryField *pReqQryDBQuery, int nRequestID = 0);
	
	///�ļ���������
	virtual BOOL ReqQryGetFileTopic(CShfeFtdcReqQryGetFileField *pReqQryGetFile, int nRequestID = 0);
	
	///��־�¼��޸�����
	virtual BOOL ReqQrySyslogEventUpdateTopic(CShfeFtdcReqQrySyslogEventUpdateField *pReqQrySyslogEventUpdate, int nRequestID = 0);
	
	///�澯��ϸ��ѯ
	virtual BOOL ReqQryWarningQueryTopic(CShfeFtdcReqQryWarningQueryField *pReqQryWarningQuery, int nRequestID = 0);
	
	///��վ���ʲ�ѯ
	virtual BOOL ReqQryWebVisitTopic(CShfeFtdcReqQryWebVisitField *pReqQryWebVisit, int nRequestID = 0);
	
	///�澯������
	virtual BOOL ReqQryWarningActiveChange(CShfeFtdcReqQryWarningActiveChangeField *pReqQryWarningActiveChange, int nRequestID = 0);
	
	///ͨ�ò���
	virtual BOOL ReqQryGeneralOperateTopic(CShfeFtdcReqQryGeneralOperateField *pReqQryGeneralOperate, int nRequestID = 0);
	
	///�����豸���ӹ�ϵ����
	virtual BOOL ReqQryNetDeviceLinkedTopic(CShfeFtdcReqQryNetDeviceLinkedField *pReqQryNetDeviceLinked, int nRequestID = 0);
	
	///����ϵͳ��¼��Ϣ����
	virtual BOOL ReqQryTradeUserLoginStatTopic(CShfeFtdcReqQryTradeUserLoginStatField *pReqQryTradeUserLoginStat, int nRequestID = 0);
	
	///����ϵͳǰ�ñ�����Ӧ��Ϣ
	virtual BOOL ReqQryTradeFrontOrderRttStatTopic(CShfeFtdcReqQryTradeFrontOrderRttStatField *pReqQryTradeFrontOrderRttStat, int nRequestID = 0);
	
	///��Աϯλ����״̬
	virtual BOOL ReqQryParticTradeOrderStatesTopic(CShfeFtdcReqQryParticTradeOrderStatesField *pReqQryParticTradeOrderStates, int nRequestID = 0);
	
	///ϵͳ·����Ϣ
	virtual BOOL ReqQryRouterInfoTopic(CShfeFtdcReqQryRouterInfoField *pReqQryRouterInfo, int nRequestID = 0);
	
	///����I/O��Ϣ
	virtual BOOL ReqQryDiskIOTopic(CShfeFtdcReqQryDiskIOField *pReqQryDiskIO, int nRequestID = 0);
	
	///ϵͳ״̬��Ϣ
	virtual BOOL ReqQryStatInfoTopic(CShfeFtdcReqQryStatInfoField *pReqQryStatInfo, int nRequestID = 0);
	
	///����ϵͳǰ�ñ����ֲ�����
	virtual BOOL ReqQryTradeOrderRttCutLineTopic(CShfeFtdcReqQryTradeOrderRttCutLineField *pReqQryTradeOrderRttCutLine, int nRequestID = 0);
	
	///��Ա�ͻ���Ϣ
	virtual BOOL ReqQryClientInfoTopic(CShfeFtdcReqQryClientInfoField *pReqQryClientInfo, int nRequestID = 0);
	
	///�����¼�����
	virtual BOOL ReqQryEventDescriptionTopic(CShfeFtdcReqQryEventDescriptionField *pReqQryEventDescription, int nRequestID = 0);
	
	///����ǰ��ΨһID��Ϣ
	virtual BOOL ReqQryFrontUniqueIDTopic(CShfeFtdcReqQryFrontUniqueIDField *pReqQryFrontUniqueID, int nRequestID = 0);
	
	///��Ա��·��ַ�������
	virtual BOOL ReqQryNetPartyLinkAddrChangeTopic(CShfeFtdcReqQryNetPartyLinkAddrChangeField *pReqQryNetPartyLinkAddrChange, int nRequestID = 0);
	
	///������ɾ����Ա�б���Ϣ
	virtual BOOL ReqQryNetDelPartyLinkInfoTopic(CShfeFtdcReqQryNetDelPartyLinkInfoField *pReqQryNetDelPartyLinkInfo, int nRequestID = 0);
	
	///����������������
	virtual BOOL ReqQryPerformanceTopTopic(CShfeFtdcReqQryPerformanceTopField *pReqQryPerformanceTop, int nRequestID = 0);
	
	///����Լ״̬�л�����
	virtual BOOL ReqQryInstrumentStatusTopic(CShfeFtdcReqQryInstrumentStatusField *pReqQryInstrumentStatus, int nRequestID = 0);
	
	///�����Լ���׽���Ϣ
	virtual BOOL ReqQryCurrTradingSegmentAttrTopic(CShfeFtdcReqQryCurrTradingSegmentAttrField *pReqQryCurrTradingSegmentAttr, int nRequestID = 0);
	
	///��������ָ���ѯ
	virtual BOOL ReqQryRealTimeNetObjectAttrTopic(CShfeFtdcReqQryRealTimeNetObjectAttrField *pReqQryRealTimeNetObjectAttr, int nRequestID = 0);
	
	///����������ֲ�ѯ
	virtual BOOL ReqQryNetAreaTopic(CShfeFtdcReqQryNetAreaField *pReqQryNetArea, int nRequestID = 0);
	
	///����������ѯ
	virtual BOOL ReqQryNetSubAreaTopic(CShfeFtdcReqQryNetSubAreaField *pReqQryNetSubArea, int nRequestID = 0);
	
	///��������IP��ѯ
	virtual BOOL ReqQryNetSubAreaIPTopic(CShfeFtdcReqQryNetSubAreaIPField *pReqQryNetSubAreaIP, int nRequestID = 0);
	
	///�����豸̽������
	virtual BOOL ReqQryNetDeviceDetectTopic(CShfeFtdcReqQryNetDeviceDetectField *pReqQryNetDeviceDetect, int nRequestID = 0);
	
	///�����豸��ѯ����
	virtual BOOL ReqQryNetDeviceRequestTopic(CShfeFtdcReqQryNetDeviceRequestField *pReqQryNetDeviceRequest, int nRequestID = 0);
	
	///��¥��ѯ
	virtual BOOL ReqQryNetBuildingTopic(CShfeFtdcReqQryNetBuildingField *pReqQryNetBuilding, int nRequestID = 0);
	
	///������ѯ
	virtual BOOL ReqQryNetRoomTopic(CShfeFtdcReqQryNetRoomField *pReqQryNetRoom, int nRequestID = 0);
	
	///�����ѯ
	virtual BOOL ReqQryNetCabinetsTopic(CShfeFtdcReqQryNetCabinetsField *pReqQryNetCabinets, int nRequestID = 0);
	
	///OID
	virtual BOOL ReqQryNetOIDTopic(CShfeFtdcReqQryNetOIDField *pReqQryNetOID, int nRequestID = 0);
	
	///ʱ�����
	virtual BOOL ReqQryNetTimePolicyTopic(CShfeFtdcReqQryNetTimePolicyField *pReqQryNetTimePolicy, int nRequestID = 0);
	
	///�ɼ������ѯ
	virtual BOOL ReqQryNetGatherTaskTopic(CShfeFtdcReqQryNetGatherTaskField *pReqQryNetGatherTask, int nRequestID = 0);
	
	///�豸�������
	virtual BOOL ReqQryNetDeviceChgTopic(CShfeFtdcReqQryNetDeviceChgField *pReqQryNetDeviceChg, int nRequestID = 0);
	
	///�����豸�ͺ�����
	virtual BOOL ReqQryNetDeviceTypeTopic(CShfeFtdcReqQryNetDeviceTypeField *pReqQryNetDeviceType, int nRequestID = 0);
	
	///�����豸�������
	virtual BOOL ReqQryNetDeviceCategoryTopic(CShfeFtdcReqQryNetDeviceCategoryField *pReqQryNetDeviceCategory, int nRequestID = 0);
	
	///�豸��������
	virtual BOOL ReqQryNetManufactoryTopic(CShfeFtdcReqQryNetManufactoryField *pReqQryNetManufactory, int nRequestID = 0);
	
	///�豸��ͬ������
	virtual BOOL ReqQryNetCommunityTopic(CShfeFtdcReqQryNetCommunityField *pReqQryNetCommunity, int nRequestID = 0);
	
	///�˿���������
	virtual BOOL ReqQryNetPortTypeTopic(CShfeFtdcReqQryNetPortTypeField *pReqQryNetPortType, int nRequestID = 0);
	
	///��Ա����ص�����
	virtual BOOL ReqQryNetPartAccessSpotTopic(CShfeFtdcReqQryNetPartAccessSpotField *pReqQryNetPartAccessSpot, int nRequestID = 0);
	
	///�˿�����
	virtual BOOL ReqQryNetInterfaceTopic(CShfeFtdcReqQryNetInterfaceField *pReqQryNetInterface, int nRequestID = 0);
	
	///GeneralOID����
	virtual BOOL ReqQryNetGeneralOIDTopic(CShfeFtdcReqQryNetGeneralOIDField *pReqQryNetGeneralOID, int nRequestID = 0);
	
	///��ض������
	virtual BOOL ReqQryNetMonitorTypeTopic(CShfeFtdcReqQryNetMonitorTypeField *pReqQryNetMonitorType, int nRequestID = 0);
	
	///ָ��ͳ��
	virtual BOOL ReqQryNetMonitorAttrScopeTopic(CShfeFtdcReqQryNetMonitorAttrScopeField *pReqQryNetMonitorAttrScope, int nRequestID = 0);
	
	///���ָ���
	virtual BOOL ReqQryNetMonitorAttrTypeTopic(CShfeFtdcReqQryNetMonitorAttrTypeField *pReqQryNetMonitorAttrType, int nRequestID = 0);
	
	///��ض���ָ���
	virtual BOOL ReqQryNetMonitorObjectAttrTopic(CShfeFtdcReqQryNetMonitorObjectAttrField *pReqQryNetMonitorObjectAttr, int nRequestID = 0);
	
	///�豸�������
	virtual BOOL ReqQryNetMonitorDeviceGroupTopic(CShfeFtdcReqQryNetMonitorDeviceGroupField *pReqQryNetMonitorDeviceGroup, int nRequestID = 0);
	
	///������Ϣ��
	virtual BOOL ReqQryNetMonitorTaskInfoTopic(CShfeFtdcReqQryNetMonitorTaskInfoField *pReqQryNetMonitorTaskInfo, int nRequestID = 0);
	
	///��������
	virtual BOOL ReqQryNetMonitorTaskResultTopic(CShfeFtdcReqQryNetMonitorTaskResultField *pReqQryNetMonitorTaskResult, int nRequestID = 0);
	
	///�������
	virtual BOOL ReqQryNetMonitorTaskObjectSetTopic(CShfeFtdcReqQryNetMonitorTaskObjectSetField *pReqQryNetMonitorTaskObjectSet, int nRequestID = 0);
	
	///��Ա��·��Ϣ��
	virtual BOOL ReqQryNetPartyLinkInfoTopic(CShfeFtdcReqQryNetPartyLinkInfoField *pReqQryNetPartyLinkInfo, int nRequestID = 0);
	
	///��ض���ָ����ձ�
	virtual BOOL ReqQryNetMonitorActionAttrTopic(CShfeFtdcReqQryNetMonitorActionAttrField *pReqQryNetMonitorActionAttr, int nRequestID = 0);
	
	///ģ��
	virtual BOOL ReqQryNetModuleTopic(CShfeFtdcReqQryNetModuleField *pReqQryNetModule, int nRequestID = 0);
	
	///������״̬��
	virtual BOOL ReqQryNetMonitorTaskStatusResultTopic(CShfeFtdcReqQryNetMonitorTaskStatusResultField *pReqQryNetMonitorTaskStatusResult, int nRequestID = 0);
	
	///�豸���ñ�
	virtual BOOL ReqQryNetCfgFileTopic(CShfeFtdcReqQryNetCfgFileField *pReqQryNetCfgFile, int nRequestID = 0);
	
	///���������������
	virtual BOOL ReqQryNetMonitorDeviceTaskTopic(CShfeFtdcReqQryNetMonitorDeviceTaskField *pReqQryNetMonitorDeviceTask, int nRequestID = 0);
	
	///�ļ�ͨ�ò���
	virtual BOOL ReqQryFileGeneralOperTopic(CShfeFtdcReqQryFileGeneralOperField *pReqQryFileGeneralOper, int nRequestID = 0);
	
	///���߱�
	virtual BOOL ReqQryNetBaseLineTopic(CShfeFtdcReqQryNetBaseLineField *pReqQryNetBaseLine, int nRequestID = 0);
	
	///���߽����
	virtual BOOL ReqQryNetBaseLineResultTopic(CShfeFtdcReqQryNetBaseLineResultField *pReqQryNetBaseLineResult, int nRequestID = 0);
	
	///��Ա��·״̬��Ϣ��
	virtual BOOL ReqQryNetPartyLinkStatusInfoTopic(CShfeFtdcReqQryNetPartyLinkStatusInfoField *pReqQryNetPartyLinkStatusInfo, int nRequestID = 0);
	
	///����ping���
	virtual BOOL ReqQryNetLocalPingResultInfoTopic(CShfeFtdcReqQryNetLocalPingResultInfoField *pReqQryNetLocalPingResultInfo, int nRequestID = 0);
	
	///Զ��ping���
	virtual BOOL ReqQryNetRomotePingResultInfoTopic(CShfeFtdcReqQryNetRomotePingResultInfoField *pReqQryNetRomotePingResultInfo, int nRequestID = 0);
	
	///����ǻ�Ա��·����Ϣ
	virtual BOOL ReqQryNetNonPartyLinkInfoTopic(CShfeFtdcReqQryNetNonPartyLinkInfoField *pReqQryNetNonPartyLinkInfo, int nRequestID = 0);
	

	///����CPUӦ��
	virtual BOOL SubRtnTopCpuInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������CPUӦ��
	virtual BOOL UnsubRtnTopCpuInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����MemӦ��
	virtual BOOL SubRtnTopMemInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������MemӦ��
	virtual BOOL UnsubRtnTopMemInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����processӦ��
	virtual BOOL SubRtnTopProcessInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������processӦ��
	virtual BOOL UnsubRtnTopProcessInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����filesystemӦ��
	virtual BOOL SubRtnFileSystemInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������filesystemӦ��
	virtual BOOL UnsubRtnFileSystemInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����networkӦ��
	virtual BOOL SubRtnNetworkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������networkӦ��
	virtual BOOL UnsubRtnNetworkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///��������������ϢӦ��
	virtual BOOL SubRtnHostEnvTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ����������������ϢӦ��
	virtual BOOL UnsubRtnHostEnvTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ļ�ü�ض�����ϢӦ��
	virtual BOOL SubRtnMonitorObjectTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ļ�ü�ض�����ϢӦ��
	virtual BOOL UnsubRtnMonitorObjectTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ļ��ҵ����̺������Ķ�Ӧ��ϵӦ��
	virtual BOOL SubRtnObjectRationalTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ļ��ҵ����̺������Ķ�Ӧ��ϵӦ��
	virtual BOOL UnsubRtnObjectRationalTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///������־�ļ�����Ӧ��
	virtual BOOL SubRtnSyslogInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ��������־�ļ�����Ӧ��
	virtual BOOL UnsubRtnSyslogInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ķ����ϵ��ѯӦ��
	virtual BOOL SubRtnOidRelationTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ķ����ϵ��ѯӦ��
	virtual BOOL UnsubRtnOidRelationTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�����û���Ϣ��ѯ����Ӧ��
	virtual BOOL SubRtnUserInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�������û���Ϣ��ѯ����Ӧ��
	virtual BOOL UnsubRtnUserInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���������û���Ϣ��ѯ����Ӧ��
	virtual BOOL SubRtnOnlineUserInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����������û���Ϣ��ѯ����Ӧ��
	virtual BOOL UnsubRtnOnlineUserInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���ĸ澯�¼���ѯ����Ӧ��
	virtual BOOL SubRtnWarningEventTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����ĸ澯�¼���ѯ����Ӧ��
	virtual BOOL UnsubRtnWarningEventTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ķ���״ָ̬���ѯӦ��
	virtual BOOL SubRtnObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ķ���״ָ̬���ѯӦ��
	virtual BOOL UnsubRtnObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///������Ч������ѯӦ��
	virtual BOOL SubRtnInvalidateOrderTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ��������Ч������ѯӦ��
	virtual BOOL UnsubRtnInvalidateOrderTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���ı���״̬��ѯӦ��
	virtual BOOL SubRtnOrderStatusTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����ı���״̬��ѯӦ��
	virtual BOOL UnsubRtnOrderStatusTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���ı����ɽ���ѯӦ��
	virtual BOOL SubRtnBargainOrderTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����ı����ɽ���ѯӦ��
	virtual BOOL UnsubRtnBargainOrderTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���ĺ�Լ�������Բ�ѯӦ��
	virtual BOOL SubRtnInstPropertyTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����ĺ�Լ�������Բ�ѯӦ��
	virtual BOOL UnsubRtnInstPropertyTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���ĺ�Լ��֤���ʲ�ѯӦ��
	virtual BOOL SubRtnMarginRateTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����ĺ�Լ��֤���ʲ�ѯӦ��
	virtual BOOL UnsubRtnMarginRateTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���ĺ�Լ�ǵ�ͣ���ѯӦ��
	virtual BOOL SubRtnPriceLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����ĺ�Լ�ǵ�ͣ���ѯӦ��
	virtual BOOL UnsubRtnPriceLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ļ�Ա�޲ֲ�ѯӦ��
	virtual BOOL SubRtnPartPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ļ�Ա�޲ֲ�ѯӦ��
	virtual BOOL UnsubRtnPartPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ŀͻ��޲ֲ�ѯӦ��
	virtual BOOL SubRtnClientPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ŀͻ��޲ֲ�ѯӦ��
	virtual BOOL UnsubRtnClientPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///��������ͻ��޲ֲ�ѯӦ��
	virtual BOOL SubRtnSpecialPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ����������ͻ��޲ֲ�ѯӦ��
	virtual BOOL UnsubRtnSpecialPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�����˻�������ѯӦ��
	virtual BOOL SubRtnTransactionChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�������˻�������ѯӦ��
	virtual BOOL UnsubRtnTransactionChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ŀͻ����ݱ䶯��ѯӦ��
	virtual BOOL SubRtnClientChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ŀͻ����ݱ䶯��ѯӦ��
	virtual BOOL UnsubRtnClientChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ļ�Ա�ͻ����ձ䶯��ѯӦ��
	virtual BOOL SubRtnPartClientChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ļ�Ա�ͻ����ձ䶯��ѯӦ��
	virtual BOOL UnsubRtnPartClientChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�����޲����ݱ䶯��ѯӦ��
	virtual BOOL SubRtnPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�������޲����ݱ䶯��ѯӦ��
	virtual BOOL UnsubRtnPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���ı�ֵ��ȱ䶯��ѯӦ��
	virtual BOOL SubRtnHedgeDetailChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����ı�ֵ��ȱ䶯��ѯӦ��
	virtual BOOL UnsubRtnHedgeDetailChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ļ�Ա�䶯��ѯӦ��
	virtual BOOL SubRtnParticipantChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ļ�Ա�䶯��ѯӦ��
	virtual BOOL UnsubRtnParticipantChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���ı�֤���ʱ䶯��ѯӦ��
	virtual BOOL SubRtnMarginRateChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����ı�֤���ʱ䶯��ѯӦ��
	virtual BOOL UnsubRtnMarginRateChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����IP��ַ�䶯��ѯӦ��
	virtual BOOL SubRtnUserIpChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������IP��ַ�䶯��ѯӦ��
	virtual BOOL UnsubRtnUserIpChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�����޲����ݱ䶯��ѯӦ��
	virtual BOOL SubRtnClientPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�������޲����ݱ䶯��ѯӦ��
	virtual BOOL UnsubRtnClientPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�����޲����ݱ䶯��ѯӦ��
	virtual BOOL SubRtnSpecPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�������޲����ݱ䶯��ѯӦ��
	virtual BOOL UnsubRtnSpecPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///������ʷ����״ָ̬���ѯӦ��
	virtual BOOL SubRtnHistoryObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ��������ʷ����״ָ̬���ѯӦ��
	virtual BOOL UnsubRtnHistoryObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����ǰ����Ӧ��Ϣ��ѯӦ��
	virtual BOOL SubRtnFrontInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������ǰ����Ӧ��Ϣ��ѯӦ��
	virtual BOOL UnsubRtnFrontInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ļ�Ա��ʼ��Ӧ��
	virtual BOOL SubRtnParticipantInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ļ�Ա��ʼ��Ӧ��
	virtual BOOL UnsubRtnParticipantInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///������ϯ��ʼ��Ӧ��
	virtual BOOL SubRtnUserInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ��������ϯ��ʼ��Ӧ��
	virtual BOOL UnsubRtnUserInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ŀͻ���ʼ��Ӧ��
	virtual BOOL SubRtnClientInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ŀͻ���ʼ��Ӧ��
	virtual BOOL UnsubRtnClientInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ľ�����־��ѯӦ��
	virtual BOOL SubRtnTradeLogTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ľ�����־��ѯӦ��
	virtual BOOL UnsubRtnTradeLogTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ľ���ϵͳ��¼��Ϣ
	virtual BOOL SubRtnTradeUserLoginInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ľ���ϵͳ��¼��Ϣ
	virtual BOOL UnsubRtnTradeUserLoginInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����
	virtual BOOL SubRtnUpdateSysConfigTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������
	virtual BOOL UnsubRtnUpdateSysConfigTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����
	virtual BOOL SubRtnSysUser(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������
	virtual BOOL UnsubRtnSysUser(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���ļ��ϵͳʱ��ͬ��
	virtual BOOL SubRtnSysTimeSyncTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����ļ��ϵͳʱ��ͬ��
	virtual BOOL UnsubRtnSysTimeSyncTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�������������л�֪ͨ
	virtual BOOL SubRtnDataCenterChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ���������������л�֪ͨ
	virtual BOOL UnsubRtnDataCenterChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///������־�¼�Ӧ��
	virtual BOOL SubRtnSyslogEventTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ��������־�¼�Ӧ��
	virtual BOOL UnsubRtnSyslogEventTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����WebӦ����Ϣ
	virtual BOOL SubRtnWebAppInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������WebӦ����Ϣ
	virtual BOOL UnsubRtnWebAppInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����Ӧ��servlet��Ϣ
	virtual BOOL SubRtnServletInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������Ӧ��servlet��Ϣ
	virtual BOOL UnsubRtnServletInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�����ļ���Ϣ
	virtual BOOL SubRtnFileInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�������ļ���Ϣ
	virtual BOOL UnsubRtnFileInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����Ӧ�ûỰ��Ϣ
	virtual BOOL SubRtnSessionInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������Ӧ�ûỰ��Ϣ
	virtual BOOL UnsubRtnSessionInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����JDBC��Ϣ
	virtual BOOL SubRtnJDBCInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������JDBC��Ϣ
	virtual BOOL UnsubRtnJDBCInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�����߳���Ϣ
	virtual BOOL SubRtnThreadInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�������߳���Ϣ
	virtual BOOL UnsubRtnThreadInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�����������Ϣ
	virtual BOOL SubRtnVMInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�������������Ϣ
	virtual BOOL UnsubRtnVMInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����ϵͳ������Ϣ
	virtual BOOL SubRtnPropertyInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������ϵͳ������Ϣ
	virtual BOOL UnsubRtnPropertyInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����ϵͳ�ڴ����Ϣ
	virtual BOOL SubRtnMemPoolInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������ϵͳ�ڴ����Ϣ
	virtual BOOL UnsubRtnMemPoolInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�����ļ�������Ϣ
	virtual BOOL SubRtnFileContentInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�������ļ�������Ϣ
	virtual BOOL UnsubRtnFileContentInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����������Ϣ
	virtual BOOL SubRtnConnectionInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������������Ϣ
	virtual BOOL UnsubRtnConnectionInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///������������Ϣ
	virtual BOOL SubRtnConnectorInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ��������������Ϣ
	virtual BOOL UnsubRtnConnectorInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�������ݿ��ѯӦ��
	virtual BOOL SubRtnDBQueryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ���������ݿ��ѯӦ��
	virtual BOOL UnsubRtnDBQueryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����ͨ�÷���Ӧ��
	virtual BOOL SubRtnGeneralFieldTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������ͨ�÷���Ӧ��
	virtual BOOL UnsubRtnGeneralFieldTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���ĸ澯������
	virtual BOOL SubRtnWarningActiveChange(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����ĸ澯������
	virtual BOOL UnsubRtnWarningActiveChange(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����ͨ�ò���
	virtual BOOL SubRtnGeneralOperateTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������ͨ�ò���
	virtual BOOL UnsubRtnGeneralOperateTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���������豸���ӹ�ϵ
	virtual BOOL SubRtnNetDeviceLinkedTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����������豸���ӹ�ϵ
	virtual BOOL UnsubRtnNetDeviceLinkedTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ľ���ϵͳǰ�ñ�����Ӧ��Ϣ
	virtual BOOL SubRtnTradeFrontOrderRttStatTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ľ���ϵͳǰ�ñ�����Ӧ��Ϣ
	virtual BOOL UnsubRtnTradeFrontOrderRttStatTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ļ�Աϯλ����״̬
	virtual BOOL SubRtnParticTradeOrderStatesTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ļ�Աϯλ����״̬
	virtual BOOL UnsubRtnParticTradeOrderStatesTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����ϵͳ·����Ϣ
	virtual BOOL SubRtnRouterInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������ϵͳ·����Ϣ
	virtual BOOL UnsubRtnRouterInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ĵ���I/O��Ϣ
	virtual BOOL SubRtnDiskIOTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ĵ���I/O��Ϣ
	virtual BOOL UnsubRtnDiskIOTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����ϵͳ״̬��Ϣ
	virtual BOOL SubRtnStatInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������ϵͳ״̬��Ϣ
	virtual BOOL UnsubRtnStatInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ľ���ϵͳǰ�ñ����ֲ�����
	virtual BOOL SubRtnTradeOrderRttCutLineTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ľ���ϵͳǰ�ñ����ֲ�����
	virtual BOOL UnsubRtnTradeOrderRttCutLineTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ļ�Ա�ͻ���Ϣ
	virtual BOOL SubRtnClientInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ļ�Ա�ͻ���Ϣ
	virtual BOOL UnsubRtnClientInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ķ����¼�����
	virtual BOOL SubRtnEventDescriptionTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ķ����¼�����
	virtual BOOL UnsubRtnEventDescriptionTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ķ���ǰ��ΨһID��Ϣ
	virtual BOOL SubRtnFrontUniqueIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ķ���ǰ��ΨһID��Ϣ
	virtual BOOL UnsubRtnFrontUniqueIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ķ��Ļ�Ա��·��ַ�����Ϣ
	virtual BOOL SubRtnNetPartyLinkAddrChangeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ķ��Ļ�Ա��·��ַ�����Ϣ
	virtual BOOL UnsubRtnNetPartyLinkAddrChangeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ķ�����ɾ����Ա�б���Ϣ
	virtual BOOL SubRtnNetDelPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ķ�����ɾ����Ա�б���Ϣ
	virtual BOOL UnsubRtnNetDelPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ķ���������������
	virtual BOOL SubRtnPerformanceTopTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ķ���������������
	virtual BOOL UnsubRtnPerformanceTopTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ķ���Լ״̬�л�����
	virtual BOOL SubRtnInstrumentStatusTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ķ���Լ״̬�л�����
	virtual BOOL UnsubRtnInstrumentStatusTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ķ��ĺ�Լ���׽���Ϣ
	virtual BOOL SubRtnCurrTradingSegmentAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ķ��ĺ�Լ���׽���Ϣ
	virtual BOOL UnsubRtnCurrTradingSegmentAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���������������Ӧ��
	virtual BOOL SubRtnNetAreaTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����������������Ӧ��
	virtual BOOL UnsubRtnNetAreaTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///������������Ӧ��
	virtual BOOL SubRtnNetSubAreaTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ��������������Ӧ��
	virtual BOOL UnsubRtnNetSubAreaTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///������������IPӦ��
	virtual BOOL SubRtnNetSubAreaIPTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ��������������IPӦ��
	virtual BOOL UnsubRtnNetSubAreaIPTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���������豸
	virtual BOOL SubRtnNetDeviceTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����������豸
	virtual BOOL UnsubRtnNetDeviceTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ĵ�¥
	virtual BOOL SubRtnNetBuildingTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ĵ�¥
	virtual BOOL UnsubRtnNetBuildingTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ļ���
	virtual BOOL SubRtnNetRoomTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ļ���
	virtual BOOL UnsubRtnNetRoomTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ļ���
	virtual BOOL SubRtnNetCabinetsTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ļ���
	virtual BOOL UnsubRtnNetCabinetsTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����OID
	virtual BOOL SubRtnNetOIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������OID
	virtual BOOL UnsubRtnNetOIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����ʱ�����
	virtual BOOL SubRtnNetTimePolicyTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������ʱ�����
	virtual BOOL UnsubRtnNetTimePolicyTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ĳɼ�����
	virtual BOOL SubRtnNetGatherTaskTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ĳɼ�����
	virtual BOOL UnsubRtnNetGatherTaskTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�����豸���
	virtual BOOL SubRtnNetDeviceChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�������豸���
	virtual BOOL UnsubRtnNetDeviceChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���ĳ����豸�ͺ�
	virtual BOOL SubRtnNetDeviceTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����ĳ����豸�ͺ�
	virtual BOOL UnsubRtnNetDeviceTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���ĳ����豸���
	virtual BOOL SubRtnNetDeviceCategoryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����ĳ����豸���
	virtual BOOL UnsubRtnNetDeviceCategoryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�����豸����
	virtual BOOL SubRtnNetManufactoryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�������豸����
	virtual BOOL UnsubRtnNetManufactoryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�����豸��ͬ��
	virtual BOOL SubRtnNetCommunityTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�������豸��ͬ��
	virtual BOOL UnsubRtnNetCommunityTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ķ˿�����
	virtual BOOL SubRtnNetPortTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ķ˿�����
	virtual BOOL UnsubRtnNetPortTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ļ�Ա����ص�
	virtual BOOL SubRtnNetPartAccessSpotTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ļ�Ա����ص�
	virtual BOOL UnsubRtnNetPartAccessSpotTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ķ˿�
	virtual BOOL SubRtnNetInterfaceTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ķ˿�
	virtual BOOL UnsubRtnNetInterfaceTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����GeneralOID
	virtual BOOL SubRtnNetGeneralOIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������GeneralOID
	virtual BOOL UnsubRtnNetGeneralOIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���ļ�ض������
	virtual BOOL SubRtnNetMonitorTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����ļ�ض������
	virtual BOOL UnsubRtnNetMonitorTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����ָ��ͳ��
	virtual BOOL SubRtnNetMonitorAttrScopeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������ָ��ͳ��
	virtual BOOL UnsubRtnNetMonitorAttrScopeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���ļ��ָ���
	virtual BOOL SubRtnNetMonitorAttrTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����ļ��ָ���
	virtual BOOL UnsubRtnNetMonitorAttrTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���ļ�ض���ָ���
	virtual BOOL SubRtnNetMonitorObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����ļ�ض���ָ���
	virtual BOOL UnsubRtnNetMonitorObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�����豸�������
	virtual BOOL SubRtnNetMonitorDeviceGroupTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�������豸�������
	virtual BOOL UnsubRtnNetMonitorDeviceGroupTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����������Ϣ��
	virtual BOOL SubRtnNetMonitorTaskInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������������Ϣ��
	virtual BOOL UnsubRtnNetMonitorTaskInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///������������
	virtual BOOL SubRtnNetMonitorTaskResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ��������������
	virtual BOOL UnsubRtnNetMonitorTaskResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�����������
	virtual BOOL SubRtnNetMonitorTaskObjectSetTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�������������
	virtual BOOL UnsubRtnNetMonitorTaskObjectSetTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ļ�Ա��·��Ϣ��
	virtual BOOL SubRtnNetPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ļ�Ա��·��Ϣ��
	virtual BOOL UnsubRtnNetPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����ģ��
	virtual BOOL SubRtnNetModuleTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������ģ��
	virtual BOOL UnsubRtnNetModuleTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����������״̬��
	virtual BOOL SubRtnNetMonitorTaskStatusResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������������״̬��
	virtual BOOL UnsubRtnNetMonitorTaskStatusResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�����豸���ñ�
	virtual BOOL SubRtnNetCfgFileTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�������豸���ñ�
	virtual BOOL UnsubRtnNetCfgFileTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�������������������
	virtual BOOL SubRtnNetMonitorDeviceTaskTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ���������������������
	virtual BOOL UnsubRtnNetMonitorDeviceTaskTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///�����ļ�ͨ�ò���
	virtual BOOL SubRtnFileGeneralOperTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�������ļ�ͨ�ò���
	virtual BOOL UnsubRtnFileGeneralOperTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ļ��߱�
	virtual BOOL SubRtnNetBaseLineTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ļ��߱�
	virtual BOOL UnsubRtnNetBaseLineTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ļ��߽����
	virtual BOOL SubRtnNetBaseLineResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ļ��߽����
	virtual BOOL UnsubRtnNetBaseLineResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ļ�Ա��·״̬��Ϣ��
	virtual BOOL SubRtnNetPartyLinkStatusInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ļ�Ա��·״̬��Ϣ��
	virtual BOOL UnsubRtnNetPartyLinkStatusInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���ı���ping���
	virtual BOOL SubRtnNetLocalPingResultInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����ı���ping���
	virtual BOOL UnsubRtnNetLocalPingResultInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///����Զ��ping���
	virtual BOOL SubRtnNetRomotePingResultInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ������Զ��ping���
	virtual BOOL UnsubRtnNetRomotePingResultInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ķ��Ļ�Ա��·���ñ�
	virtual BOOL SubRtnMemberLinkCostTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ķ��Ļ�Ա��·���ñ�
	virtual BOOL UnsubRtnMemberLinkCostTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///���Ķ��ķǻ�Ա��·����Ϣ
	virtual BOOL SubRtnNetNonPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///ȡ�����Ķ��ķǻ�Ա��·����Ϣ
	virtual BOOL UnsubRtnNetNonPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	
private:
	BOOL SubscriberTopic(TShfeFtdcTypeSubcriberObjectIDType ObjectID,   TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum ,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID);
	BOOL UnsubscriberTopic(TShfeFtdcTypeSubcriberObjectIDType ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID);
};


#endif
