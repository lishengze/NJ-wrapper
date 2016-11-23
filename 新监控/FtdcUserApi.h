/////////////////////////////////////////////////////////////////////////
///@system ��һ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file FtdcUserApi.h
///@brief �����˿ͻ��˽ӿ�
///@history 
///20060106	�Ժ��		�������ļ�
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCUSERAPI_H)
#define _FTDCUSERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FtdcUserApiStruct.h"

#if defined(USERAPI_IS_LIB) && defined(WIN32)
#ifdef LIB_USER_API_EXPORT
#define USER_API_EXPORT __declspec(dllexport)
#else
#define USER_API_EXPORT __declspec(dllimport)
#endif
#else
#define USER_API_EXPORT 
#endif


class CShfeFtdcUserSpi
{
public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected(){};
	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason){};
		
	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse){};
	
	///���Ļص���ʼ֪ͨ����API�յ�һ�����ĺ����ȵ��ñ�������Ȼ���Ǹ�������Ļص�������Ǳ��Ļص�����֪ͨ��
	///@param nTopicID ������루��˽���������������������ȣ�
	///@param nSequenceNo �������
	virtual void OnPackageStart(int nTopicID, int nSequenceNo){};
	
	///���Ļص�����֪ͨ����API�յ�һ�����ĺ����ȵ��ñ��Ļص���ʼ֪ͨ��Ȼ���Ǹ�������Ļص��������ñ�������
	///@param nTopicID ������루��˽���������������������ȣ�
	///@param nSequenceNo �������
	virtual void OnPackageEnd(int nTopicID, int nSequenceNo){};
	

	///����Ӧ��
	virtual void OnRspError(CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û���¼Ӧ��
	virtual void OnRspUserLogin(CShfeFtdcRspUserLoginField *pRspUserLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û��˳�Ӧ��
	virtual void OnRspUserLogout(CShfeFtdcRspUserLogoutField *pRspUserLogout, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����¼��Ӧ��
	virtual void OnRspOrderInsert(CShfeFtdcInputOrderField *pInputOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ӧ��
	virtual void OnRspOrderAction(CShfeFtdcOrderActionField *pOrderAction, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����¼��Ӧ��
	virtual void OnRspQuoteInsert(CShfeFtdcInputQuoteField *pInputQuote, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���۲���Ӧ��
	virtual void OnRspQuoteAction(CShfeFtdcQuoteActionField *pQuoteAction, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///OTC����¼��Ӧ��
	virtual void OnRspOTCOrderInsert(CShfeFtdcOTCOrderField *pOTCOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û������޸�Ӧ��
	virtual void OnRspUserPasswordUpdate(CShfeFtdcUserPasswordUpdateField *pUserPasswordUpdate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ִ������¼��Ӧ��
	virtual void OnRspExecOrderInsert(CShfeFtdcInputExecOrderField *pInputExecOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ִ���������Ӧ��
	virtual void OnRspExecOrderAction(CShfeFtdcExecOrderActionField *pExecOrderAction, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������¼��Ӧ��
	virtual void OnRspAdminOrderInsert(CShfeFtdcInputAdminOrderField *pInputAdminOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�Ǳ���ϱ���¼��Ӧ��
	virtual void OnRspCombOrderInsert(CShfeFtdcInputCombOrderField *pInputCombOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ӧ��
	virtual void OnRspSubscribeTopic(CShfeFtdcDisseminationField *pDissemination, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������������Ӧ��
	virtual void OnRspBulletin(CShfeFtdcBulletinField *pBulletin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������������ϢӦ��
	virtual void OnRspInformation(CShfeFtdcInformationField *pInformation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ����״̬�ı�Ӧ��
	virtual void OnRspInstrumentStatusUpdate(CShfeFtdcInstrumentStatusField *pInstrumentStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ǿ���û��˳�Ӧ��
	virtual void OnRspForceUserExit(CShfeFtdcForceUserExitField *pForceUserExit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û��Ựɾ��Ӧ��
	virtual void OnRspForceUserLogout(CShfeFtdcForceUserExitField *pForceUserExit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����������ͬ��״̬�ı�Ӧ��
	virtual void OnRspExchangeDataSyncStatusUpdate(CShfeFtdcExchangeDataSyncStatusField *pExchangeDataSyncStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����������ͬ��״̬�ı�Ӧ��
	virtual void OnRspSGDataSyncStatusUpdate(CShfeFtdcSGDataSyncStatusField *pSGDataSyncStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա�ʽ��ѯӦ��
	virtual void OnRspQryPartAccount(CShfeFtdcRspPartAccountField *pRspPartAccount, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������ѯӦ��
	virtual void OnRspQryOrder(CShfeFtdcOrderField *pOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���۲�ѯӦ��
	virtual void OnRspQryQuote(CShfeFtdcQuoteField *pQuote, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ɽ�����ѯӦ��
	virtual void OnRspQryTrade(CShfeFtdcTradeField *pTrade, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա�ͻ���ѯӦ��
	virtual void OnRspQryClient(CShfeFtdcRspClientField *pRspClient, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա�ֲֲ�ѯӦ��
	virtual void OnRspQryPartPosition(CShfeFtdcRspPartPositionField *pRspPartPosition, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ͻ��ֲֲ�ѯӦ��
	virtual void OnRspQryClientPosition(CShfeFtdcRspClientPositionField *pRspClientPosition, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ��ѯӦ��
	virtual void OnRspQryInstrument(CShfeFtdcRspInstrumentField *pRspInstrument, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ����״̬��ѯӦ��
	virtual void OnRspQryInstrumentStatus(CShfeFtdcInstrumentStatusField *pInstrumentStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������״̬��ѯӦ��
	virtual void OnRspQrySGDataSyncStatus(CShfeFtdcSGDataSyncStatusField *pSGDataSyncStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ֵ���Ӧ��
	virtual void OnRspQryHedgeVolume(CShfeFtdcHedgeVolumeField *pHedgeVolume, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����޶��ѯӦ��
	virtual void OnRspQryCreditLimit(CShfeFtdcCreditLimitField *pCreditLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�Ǳ���ϱ�����ѯӦ��
	virtual void OnRspQryCombOrder(CShfeFtdcCombOrderField *pCombOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ִ�������ѯӦ��
	virtual void OnRspQryExecOrder(CShfeFtdcExecOrderField *pExecOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ͨ�����ѯӦ��
	virtual void OnRspQryMarketData(CShfeFtdcMarketDataField *pMarketData, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����������ѯ����Ӧ��
	virtual void OnRspQryBulletin(CShfeFtdcBulletinField *pBulletin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯӦ��
	virtual void OnRspQryTopic(CShfeFtdcDisseminationField *pDissemination, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û����߲�ѯӦ��
	virtual void OnRspQryUserSession(CShfeFtdcUserSessionField *pUserSession, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û���ѯӦ��
	virtual void OnRspQryUser(CShfeFtdcUserField *pUser, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա��ѯӦ��
	virtual void OnRspQryParticipant(CShfeFtdcParticipantField *pParticipant, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ��λ��ѯӦ��
	virtual void OnRspQryMBLMarketData(CShfeFtdcMBLMarketDataField *pMBLMarketData, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ϣ��ѯӦ��
	virtual void OnRspQryInformation(CShfeFtdcInformationField *pInformation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ɽ��ر�
	virtual void OnRtnTrade(CShfeFtdcTradeField *pTrade) {};

	///�����ر�
	virtual void OnRtnOrder(CShfeFtdcOrderField *pOrder) {};

	///ִ������ر�
	virtual void OnRtnExecOrder(CShfeFtdcExecOrderField *pExecOrder) {};

	///���ۻر�
	virtual void OnRtnQuote(CShfeFtdcQuoteField *pQuote) {};

	///�Ǳ���ϱ����ر�
	virtual void OnRtnCombOrder(CShfeFtdcCombOrderField *pCombOrder) {};

	///��Լ����״̬֪ͨ
	virtual void OnRtnInstrumentStatus(CShfeFtdcInstrumentStatusField *pInstrumentStatus) {};

	///���Ӻ�Լ֪ͨ
	virtual void OnRtnInsInstrument(CShfeFtdcInstrumentField *pInstrument) {};

	///ɾ����Լ֪ͨ
	virtual void OnRtnDelInstrument(CShfeFtdcInstrumentField *pInstrument) {};

	///���Ӻ�Լ����֪ͨ
	virtual void OnRtnInsCombinationLeg(CShfeFtdcCombinationLegField *pCombinationLeg) {};

	///ɾ����Լ����֪ͨ
	virtual void OnRtnDelCombinationLeg(CShfeFtdcCombinationLegField *pCombinationLeg) {};

	///��������֪ͨ
	virtual void OnRtnAliasDefine(CShfeFtdcAliasDefineField *pAliasDefine) {};

	///����������֪ͨ
	virtual void OnRtnFlowMessageCancel(CShfeFtdcFlowMessageCancelField *pFlowMessageCancel) {};

	///����֪ͨ
	virtual void OnRtnBulletin(CShfeFtdcBulletinField *pBulletin) {};

	///��ͨ����֪ͨ
	virtual void OnRtnMarketData(CShfeFtdcMarketDataField *pMarketData) {};

	///�������֪ͨ
	virtual void OnRtnDepthMarketData(CShfeFtdcDepthMarketDataField *pDepthMarketData) {};

	///������֪ͨ
	virtual void OnRtnAdminOrder(CShfeFtdcAdminOrderField *pAdminOrder) {};

	///����¼�����ر�
	virtual void OnErrRtnOrderInsert(CShfeFtdcInputOrderField *pInputOrder, CShfeFtdcRspInfoField *pRspInfo) {};

	///������������ر�
	virtual void OnErrRtnOrderAction(CShfeFtdcOrderActionField *pOrderAction, CShfeFtdcRspInfoField *pRspInfo) {};

	///����¼�����ر�
	virtual void OnErrRtnQuoteInsert(CShfeFtdcInputQuoteField *pInputQuote, CShfeFtdcRspInfoField *pRspInfo) {};

	///���۲�������ر�
	virtual void OnErrRtnQuoteAction(CShfeFtdcQuoteActionField *pQuoteAction, CShfeFtdcRspInfoField *pRspInfo) {};

	///ִ������¼�����ر�
	virtual void OnErrRtnExecOrderInsert(CShfeFtdcInputExecOrderField *pInputExecOrder, CShfeFtdcRspInfoField *pRspInfo) {};

	///ִ�������������ر�
	virtual void OnErrRtnExecOrderAction(CShfeFtdcExecOrderActionField *pExecOrderAction, CShfeFtdcRspInfoField *pRspInfo) {};

	///�Ǳ���ϱ���¼�����ر�
	virtual void OnErrRtnCombOrderInsert(CShfeFtdcInputCombOrderField *pInputCombOrder, CShfeFtdcRspInfoField *pRspInfo) {};

	///���ʲ�ѯӦ��
	virtual void OnRspQryExchangeRate(CShfeFtdcRspExchangeRateField *pRspExchangeRate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///CPUӦ��
	virtual void OnRspQryTopCpuInfoTopic(CShfeFtdcRspQryTopCpuInfoField *pRspQryTopCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///CPUӦ��
	virtual void OnRtnTopCpuInfoTopic(CShfeFtdcRtnTopCpuInfoField *pRtnTopCpuInfo) {};

	///MemӦ��
	virtual void OnRspQryTopMemInfoTopic(CShfeFtdcRspQryTopMemInfoField *pRspQryTopMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///MemӦ��
	virtual void OnRtnTopMemInfoTopic(CShfeFtdcRtnTopMemInfoField *pRtnTopMemInfo) {};

	///processӦ��
	virtual void OnRspQryTopProcessInfoTopic(CShfeFtdcRspQryTopProcessInfoField *pRspQryTopProcessInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///processӦ��
	virtual void OnRtnTopProcessInfoTopic(CShfeFtdcRtnTopProcessInfoField *pRtnTopProcessInfo) {};

	///filesystemӦ��
	virtual void OnRspQryFileSystemInfoTopic(CShfeFtdcRspQryFileSystemInfoField *pRspQryFileSystemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///filesystemӦ��
	virtual void OnRtnFileSystemInfoTopic(CShfeFtdcRtnFileSystemInfoField *pRtnFileSystemInfo) {};

	///networkӦ��
	virtual void OnRspQryNetworkInfoTopic(CShfeFtdcRspQryNetworkInfoField *pRspQryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///networkӦ��
	virtual void OnRtnNetworkInfoTopic(CShfeFtdcRtnNetworkInfoField *pRtnNetworkInfo) {};

	///�ͻ��˵�¼Ӧ��
	virtual void OnRspQryClientLoginTopic(CShfeFtdcRspQryClientLoginField *pRspQryClientLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ü�ض�����ϢӦ��
	virtual void OnRspQryMonitorObjectTopic(CShfeFtdcRspQryMonitorObjectField *pRspQryMonitorObject, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ü�ض�����ϢӦ��
	virtual void OnRtnMonitorObjectTopic(CShfeFtdcRtnMonitorObjectField *pRtnMonitorObject) {};

	///���ҵ����̺������Ķ�Ӧ��ϵӦ��
	virtual void OnRspQryObjectRationalTopic(CShfeFtdcRspQryObjectRationalField *pRspQryObjectRational, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ҵ����̺������Ķ�Ӧ��ϵӦ��
	virtual void OnRtnObjectRationalTopic(CShfeFtdcRtnObjectRationalField *pRtnObjectRational) {};

	///��־�ļ�����Ӧ��
	virtual void OnRspQrySyslogInfoTopic(CShfeFtdcRspQrySyslogInfoField *pRspQrySyslogInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��־�ļ�����Ӧ��
	virtual void OnRtnSyslogInfoTopic(CShfeFtdcRtnSyslogInfoField *pRtnSyslogInfo) {};

	///������ݶ���Ӧ��
	virtual void OnRspQrySubscriberTopic(CShfeFtdcRspQrySubscriberField *pRspQrySubscriber, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ϵ��ѯӦ��
	virtual void OnRspQryOidRelationTopic(CShfeFtdcRspQryOidRelationField *pRspQryOidRelation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ϵ��ѯӦ��
	virtual void OnRtnOidRelationTopic(CShfeFtdcRtnOidRelationField *pRtnOidRelation) {};

	///�û���Ϣ��ѯ����Ӧ��
	virtual void OnRspQryUserInfoTopic(CShfeFtdcRspQryUserInfoField *pRspQryUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û���Ϣ��ѯ����Ӧ��
	virtual void OnRtnUserInfoTopic(CShfeFtdcRtnUserInfoField *pRtnUserInfo) {};

	///�����û���Ϣ��ѯ����Ӧ��
	virtual void OnRspQryOnlineUserInfoTopic(CShfeFtdcRspQryOnlineUserInfoField *pRspQryOnlineUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����û���Ϣ��ѯ����Ӧ��
	virtual void OnRtnOnlineUserInfoTopic(CShfeFtdcRtnOnlineUserInfoField *pRtnOnlineUserInfo) {};

	///�澯�¼���ѯ����Ӧ��
	virtual void OnRspQryWarningEventTopic(CShfeFtdcRspQryWarningEventField *pRspQryWarningEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�澯�¼���ѯ����Ӧ��
	virtual void OnRtnWarningEventTopic(CShfeFtdcRtnWarningEventField *pRtnWarningEvent) {};

	///CPUʹ���ʲ�ѯ����Ӧ��
	virtual void OnRspQryCPUUsageTopic(CShfeFtdcRspQryCPUUsageField *pRspQryCPUUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///CPUʹ���ʲ�ѯ����Ӧ��
	virtual void OnRtnCPUUsageTopic(CShfeFtdcRtnCPUUsageField *pRtnCPUUsage) {};

	///�ڴ�ʹ���ʲ�ѯ����Ӧ��
	virtual void OnRspQryMemoryUsageTopic(CShfeFtdcRspQryMemoryUsageField *pRspQryMemoryUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ڴ�ʹ���ʲ�ѯ����Ӧ��
	virtual void OnRtnMemoryUsageTopic(CShfeFtdcRtnMemoryUsageField *pRtnMemoryUsage) {};

	///Ӳ��ʹ���ʲ�ѯ����Ӧ��
	virtual void OnRspQryDiskUsageTopic(CShfeFtdcRspQryDiskUsageField *pRspQryDiskUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ӳ��ʹ���ʲ�ѯ����Ӧ��
	virtual void OnRtnDiskUsageTopic(CShfeFtdcRtnDiskUsageField *pRtnDiskUsage) {};

	///����״ָ̬���ѯӦ��
	virtual void OnRspQryObjectAttrTopic(CShfeFtdcRspQryObjectAttrField *pRspQryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����״ָ̬���ѯӦ��
	virtual void OnRtnObjectAttrTopic(CShfeFtdcRtnObjectAttrField *pRtnObjectAttr) {};

	///��ʷ����״ָ̬���ѯӦ��
	virtual void OnRspQryHistoryObjectAttrTopic(CShfeFtdcRspQryHistoryObjectAttrField *pRspQryHistoryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ʷ����״ָ̬���ѯӦ��
	virtual void OnRtnHistoryObjectAttrTopic(CShfeFtdcRtnHistoryObjectAttrField *pRtnHistoryObjectAttr) {};

	///ǰ����Ӧ��Ϣ��ѯӦ��
	virtual void OnRspQryFrontInfoTopic(CShfeFtdcRspQryFrontInfoField *pRspQryFrontInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ǰ����Ӧ��Ϣ��ѯӦ��
	virtual void OnRtnFrontInfoTopic(CShfeFtdcRtnFrontInfoField *pRtnFrontInfo) {};

	///�û���¼Ӧ��
	virtual void OnRspQrySysUserLoginTopic(CShfeFtdcRspQrySysUserLoginField *pRspQrySysUserLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û��ǳ�Ӧ��
	virtual void OnRspQrySysUserLogoutTopic(CShfeFtdcRspQrySysUserLogoutField *pRspQrySysUserLogout, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û��޸�����Ӧ��
	virtual void OnRspQrySysUserPasswordUpdateTopic(CShfeFtdcRspQrySysUserPasswordUpdateField *pRspQrySysUserPasswordUpdate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ע���û�Ӧ��
	virtual void OnRspQrySysUserRegisterTopic(CShfeFtdcRspQrySysUserRegisterField *pRspQrySysUserRegister, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ɾ���û�Ӧ��
	virtual void OnRspQrySysUserDeleteTopic(CShfeFtdcRspQrySysUserDeleteField *pRspQrySysUserDelete, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ͻ���ʼ��Ӧ��
	virtual void OnRspQryClientInitTopic(CShfeFtdcRspQryClientInitField *pRspQryClientInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ͻ���ʼ��Ӧ��
	virtual void OnRtnClientInitTopic(CShfeFtdcRtnClientInitField *pRtnClientInit) {};

	///������־��ѯӦ��
	virtual void OnRspQryTradeLogTopic(CShfeFtdcRspQryTradeLogField *pRspQryTradeLog, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������־��ѯӦ��
	virtual void OnRtnTradeLogTopic(CShfeFtdcRtnTradeLogField *pRtnTradeLog) {};

	///���׷�ֵ��ѯӦ��
	virtual void OnRspQryTradepeakTopic(CShfeFtdcRspQryTradepeakField *pRspQryTradepeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///
	virtual void OnRtnUpdateSysConfigTopic(CShfeFtdcRtnUpdateSysConfigField *pRtnUpdateSysConfig) {};

	///
	virtual void OnRtnSysUser(CShfeFtdcRtnSysUserField *pRtnSysUser) {};

	///
	virtual void OnRtnPriceLimitChgTopic(CShfeFtdcRtnPriceLimitChgField *pRtnPriceLimitChg) {};

	///
	virtual void OnRspQryHistoryCpuInfoTopic(CShfeFtdcRspQryHistoryCpuInfoField *pRspQryHistoryCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///
	virtual void OnRspQryHistoryMemInfoTopic(CShfeFtdcRspQryHistoryMemInfoField *pRspQryHistoryMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///
	virtual void OnRspQryHistoryNetworkInfoTopic(CShfeFtdcRspQryHistoryNetworkInfoField *pRspQryHistoryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///HostConfig��ѯ����Ӧ��
	virtual void OnRspQryHostConfig(CShfeFtdcRspQryHostConfigField *pRspQryHostConfig, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ϵͳ�����û�Ӧ��
	virtual void OnRspQryMonitorOnlineUser(CShfeFtdcRspQryMonitorOnlineUserField *pRspQryMonitorOnlineUser, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ϵͳʱ��ͬ��
	virtual void OnRtnSysTimeSyncTopic(CShfeFtdcRtnSysTimeSyncField *pRtnSysTimeSync) {};

	///���������л�֪ͨ
	virtual void OnRtnDataCenterChgTopic(CShfeFtdcRtnDataCenterChgField *pRtnDataCenterChg) {};

	///��ʷ��ֵ��ѯӦ��
	virtual void OnRspQryHistoryTradePeakTopic(CShfeFtdcRspQryHistoryTradePeakField *pRspQryHistoryTradePeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ʷ��ֵ��ѯӦ��
	virtual void OnRtnHistoryTradePeakTopic(CShfeFtdcRtnHistoryTradePeakField *pRtnHistoryTradePeak) {};

	///��־�¼���ѯӦ��
	virtual void OnRspQrySyslogEventTopic(CShfeFtdcRspQrySyslogEventField *pRspQrySyslogEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��־�¼�Ӧ��
	virtual void OnRtnSyslogEventTopic(CShfeFtdcRtnSyslogEventField *pRtnSyslogEvent) {};

	///�������л�֪ͨ
	virtual void OnRspQryTradeDayChangeTopic(CShfeFtdcRspQryTradeDayChangeField *pRspQryTradeDayChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///WebӦ����Ϣ
	virtual void OnRspQryWebAppInfoTopic(CShfeFtdcRspQryWebAppInfoField *pRspQryWebAppInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///WebӦ����Ϣ
	virtual void OnRtnWebAppInfoTopic(CShfeFtdcRtnWebAppInfoField *pRtnWebAppInfo) {};

	///Ӧ��servlet��Ϣ
	virtual void OnRspQryServletInfoTopic(CShfeFtdcRspQryServletInfoField *pRspQryServletInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ӧ��servlet��Ϣ
	virtual void OnRtnServletInfoTopic(CShfeFtdcRtnServletInfoField *pRtnServletInfo) {};

	///�ļ���Ϣ
	virtual void OnRspQryFileInfoTopic(CShfeFtdcRspQryFileInfoField *pRspQryFileInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ļ���Ϣ
	virtual void OnRtnFileInfoTopic(CShfeFtdcRtnFileInfoField *pRtnFileInfo) {};

	///Ӧ�ûỰ��Ϣ
	virtual void OnRspQrySessionInfoTopic(CShfeFtdcRspQrySessionInfoField *pRspQrySessionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ӧ�ûỰ��Ϣ
	virtual void OnRtnSessionInfoTopic(CShfeFtdcRtnSessionInfoField *pRtnSessionInfo) {};

	///JDBC��Ϣ
	virtual void OnRspQryJDBCInfoTopic(CShfeFtdcRspQryJDBCInfoField *pRspQryJDBCInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///JDBC��Ϣ
	virtual void OnRtnJDBCInfoTopic(CShfeFtdcRtnJDBCInfoField *pRtnJDBCInfo) {};

	///�߳���Ϣ
	virtual void OnRspQryThreadInfoTopic(CShfeFtdcRspQryThreadInfoField *pRspQryThreadInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�߳���Ϣ
	virtual void OnRtnThreadInfoTopic(CShfeFtdcRtnThreadInfoField *pRtnThreadInfo) {};

	///�������Ϣ
	virtual void OnRspQryVMInfoTopic(CShfeFtdcRspQryVMInfoField *pRspQryVMInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������Ϣ
	virtual void OnRtnVMInfoTopic(CShfeFtdcRtnVMInfoField *pRtnVMInfo) {};

	///ϵͳ������Ϣ
	virtual void OnRspQryPropertyInfoTopic(CShfeFtdcRspQryPropertyInfoField *pRspQryPropertyInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ϵͳ������Ϣ
	virtual void OnRtnPropertyInfoTopic(CShfeFtdcRtnPropertyInfoField *pRtnPropertyInfo) {};

	///ϵͳ�ڴ����Ϣ
	virtual void OnRspQryMemPoolInfoTopic(CShfeFtdcRspQryMemPoolInfoField *pRspQryMemPoolInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ϵͳ�ڴ����Ϣ
	virtual void OnRtnMemPoolInfoTopic(CShfeFtdcRtnMemPoolInfoField *pRtnMemPoolInfo) {};

	///�ļ�������Ϣ
	virtual void OnRspQryFileContentInfoTopic(CShfeFtdcRspQryFileContentInfoField *pRspQryFileContentInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ļ�������Ϣ
	virtual void OnRtnFileContentInfoTopic(CShfeFtdcRtnFileContentInfoField *pRtnFileContentInfo) {};

	///������Ϣ
	virtual void OnRspQryConnectionInfoTopic(CShfeFtdcRspQryConnectionInfoField *pRspQryConnectionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������Ϣ
	virtual void OnRtnConnectionInfoTopic(CShfeFtdcRtnConnectionInfoField *pRtnConnectionInfo) {};

	///��������Ϣ
	virtual void OnRspQryConnectorInfoTopic(CShfeFtdcRspQryConnectorInfoField *pRspQryConnectorInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ϣ
	virtual void OnRtnConnectorInfoTopic(CShfeFtdcRtnConnectorInfoField *pRtnConnectorInfo) {};

	///���ݿ��ѯӦ��
	virtual void OnRspQryDBQueryTopic(CShfeFtdcRspQryDBQueryField *pRspQryDBQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ݿ��ѯӦ��
	virtual void OnRtnDBQueryTopic(CShfeFtdcRtnDBQueryField *pRtnDBQuery) {};

	///ͨ�÷���Ӧ��
	virtual void OnRspQryGeneralFieldTopic(CShfeFtdcSysGeneralFieldField *pSysGeneralField, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ͨ�÷���Ӧ��
	virtual void OnRtnGeneralFieldTopic(CShfeFtdcSysGeneralFieldField *pSysGeneralField) {};

	///�ļ�����Ӧ��
	virtual void OnRspQryGetFileTopic(CShfeFtdcRspQryGetFileField *pRspQryGetFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�澯��ϸ
	virtual void OnRspQryWarningQueryTopic(CShfeFtdcRspQryWarningQueryField *pRspQryWarningQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�澯��ϸ
	virtual void OnRtnWarningQueryTopic(CShfeFtdcRtnWarningQueryField *pRtnWarningQuery) {};

	///HostConfig����Ӧ��
	virtual void OnRtnHostConfig(CShfeFtdcRtnHostConfigField *pRtnHostConfig) {};

	///�澯������
	virtual void OnRspQryWarningActiveChange(CShfeFtdcRspQryWarningActiveChangeField *pRspQryWarningActiveChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�澯������
	virtual void OnRtnWarningActiveChange(CShfeFtdcRtnWarningActiveChangeField *pRtnWarningActiveChange) {};

	///ͨ�ò���
	virtual void OnRspQryGeneralOperateTopic(CShfeFtdcRspQryGeneralOperateField *pRspQryGeneralOperate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ͨ�ò���
	virtual void OnRtnGeneralOperateTopic(CShfeFtdcRtnGeneralOperateField *pRtnGeneralOperate) {};

	///�����豸���ӹ�ϵ
	virtual void OnRspQryNetDeviceLinkedTopic(CShfeFtdcRspQryNetDeviceLinkedField *pRspQryNetDeviceLinked, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����豸���ӹ�ϵ
	virtual void OnRtnNetDeviceLinkedTopic(CShfeFtdcRtnNetDeviceLinkedField *pRtnNetDeviceLinked) {};

	///����ϵͳ��¼��Ϣ
	virtual void OnRspQryTradeUserLoginStatTopic(CShfeFtdcRspQryTradeUserLoginStatField *pRspQryTradeUserLoginStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ϵͳǰ�ñ�����Ӧ��Ϣ
	virtual void OnRspQryTradeFrontOrderRttStatTopic(CShfeFtdcRspQryTradeFrontOrderRttStatField *pRspQryTradeFrontOrderRttStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ϵͳǰ�ñ�����Ӧ��Ϣ
	virtual void OnRtnTradeFrontOrderRttStatTopic(CShfeFtdcRtnTradeFrontOrderRttStatField *pRtnTradeFrontOrderRttStat) {};

	///ϵͳ·����Ϣ
	virtual void OnRspQryRouterInfoTopic(CShfeFtdcRspQryRouterInfoField *pRspQryRouterInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ϵͳ·����Ϣ
	virtual void OnRtnRouterInfoTopic(CShfeFtdcRtnRouterInfoField *pRtnRouterInfo) {};

	///����I/O��Ϣ
	virtual void OnRspQryDiskIOTopic(CShfeFtdcRspQryDiskIOField *pRspQryDiskIO, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����I/O��Ϣ
	virtual void OnRtnDiskIOTopic(CShfeFtdcRtnDiskIOField *pRtnDiskIO) {};

	///ϵͳ״̬��Ϣ
	virtual void OnRspQryStatInfoTopic(CShfeFtdcRspQryStatInfoField *pRspQryStatInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ϵͳ״̬��Ϣ
	virtual void OnRtnStatInfoTopic(CShfeFtdcRtnStatInfoField *pRtnStatInfo) {};

	///����ϵͳǰ�ñ����ֲ�����
	virtual void OnRspQryTradeOrderRttCutLineTopic(CShfeFtdcRspQryTradeOrderRttCutLineField *pRspQryTradeOrderRttCutLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ϵͳǰ�ñ����ֲ�����
	virtual void OnRtnTradeOrderRttCutLineTopic(CShfeFtdcRtnTradeOrderRttCutLineField *pRtnTradeOrderRttCutLine) {};

	///��Ա�ͻ���Ϣ
	virtual void OnRspQryClientInfoTopic(CShfeFtdcRspQryClientInfoField *pRspQryClientInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա�ͻ���Ϣ
	virtual void OnRtnClientInfoTopic(CShfeFtdcRtnClientInfoField *pRtnClientInfo) {};

	///Ӧ���¼�����
	virtual void OnRspQryEventDescriptionTopic(CShfeFtdcRspQryEventDescriptionField *pRspQryEventDescription, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����¼�����
	virtual void OnRtnEventDescriptionTopic(CShfeFtdcRtnEventDescriptionField *pRtnEventDescription) {};

	///Ӧ��ǰ��ΨһID��Ϣ
	virtual void OnRspQryFrontUniqueIDTopic(CShfeFtdcRspQryFrontUniqueIDField *pRspQryFrontUniqueID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ǰ��ΨһID��Ϣ
	virtual void OnRtnFrontUniqueIDTopic(CShfeFtdcRtnFrontUniqueIDField *pRtnFrontUniqueID) {};

	///��Ա��·��ַ�����Ӧ
	virtual void OnRspQryNetPartyLinkAddrChangeTopic(CShfeFtdcRspQryNetPartyLinkAddrChangeField *pRspQryNetPartyLinkAddrChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���Ļ�Ա��·��ַ�����Ϣ
	virtual void OnRtnNetPartyLinkAddrChangeTopic(CShfeFtdcRtnNetPartyLinkAddrChangeField *pRtnNetPartyLinkAddrChange) {};

	///Ӧ����ɾ����Ա�б���Ϣ
	virtual void OnRspQryNetDelPartyLinkInfoTopic(CShfeFtdcRspQryNetDelPartyLinkInfoField *pRspQryNetDelPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������ɾ����Ա�б���Ϣ
	virtual void OnRtnNetDelPartyLinkInfoTopic(CShfeFtdcRtnNetDelPartyLinkInfoField *pRtnNetDelPartyLinkInfo) {};

	///����������������
	virtual void OnRspQryPerformanceTopTopic(CShfeFtdcRspQryPerformanceTopField *pRspQryPerformanceTop, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����������������
	virtual void OnRtnPerformanceTopTopic(CShfeFtdcRtnPerformanceTopField *pRtnPerformanceTop) {};

	///�����������Ӧ��
	virtual void OnRspQryNetAreaTopic(CShfeFtdcRspQryNetAreaField *pRspQryNetArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����������Ӧ��
	virtual void OnRtnNetAreaTopic(CShfeFtdcRtnNetAreaField *pRtnNetArea) {};

	///��������Ӧ��
	virtual void OnRspQryNetSubAreaTopic(CShfeFtdcRspQryNetSubAreaField *pRspQryNetSubArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ӧ��
	virtual void OnRtnNetSubAreaTopic(CShfeFtdcRtnNetSubAreaField *pRtnNetSubArea) {};

	///��������IPӦ��
	virtual void OnRspQryNetSubAreaIPTopic(CShfeFtdcRspQryNetSubAreaIPField *pRspQryNetSubAreaIP, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������IPӦ��
	virtual void OnRtnNetSubAreaIPTopic(CShfeFtdcRtnNetSubAreaIPField *pRtnNetSubAreaIP) {};

	///�����豸
	virtual void OnRspQryNetDeviceTopic(CShfeFtdcRspQryNetDeviceField *pRspQryNetDevice, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����豸
	virtual void OnRtnNetDeviceTopic(CShfeFtdcRtnNetDeviceField *pRtnNetDevice) {};

	///�����豸̽������Ӧ��
	virtual void OnRspQryNetDeviceDetectTopic(CShfeFtdcRspQryNetDeviceDetectField *pRspQryNetDeviceDetect, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��¥
	virtual void OnRspQryNetBuildingTopic(CShfeFtdcRspQryNetBuildingField *pRspQryNetBuilding, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��¥
	virtual void OnRtnNetBuildingTopic(CShfeFtdcRtnNetBuildingField *pRtnNetBuilding) {};

	///����
	virtual void OnRspQryNetRoomTopic(CShfeFtdcRspQryNetRoomField *pRspQryNetRoom, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����
	virtual void OnRtnNetRoomTopic(CShfeFtdcRtnNetRoomField *pRtnNetRoom) {};

	///����
	virtual void OnRspQryNetCabinetsTopic(CShfeFtdcRspQryNetCabinetsField *pRspQryNetCabinets, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����
	virtual void OnRtnNetCabinetsTopic(CShfeFtdcRtnNetCabinetsField *pRtnNetCabinets) {};

	///OID
	virtual void OnRspQryNetOIDTopic(CShfeFtdcRspQryNetOIDField *pRspQryNetOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///OID
	virtual void OnRtnNetOIDTopic(CShfeFtdcRtnNetOIDField *pRtnNetOID) {};

	///ʱ�����
	virtual void OnRspQryNetTimePolicyTopic(CShfeFtdcRspQryNetTimePolicyField *pRspQryNetTimePolicy, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ʱ�����
	virtual void OnRtnNetTimePolicyTopic(CShfeFtdcRtnNetTimePolicyField *pRtnNetTimePolicy) {};

	///�ɼ�����
	virtual void OnRspQryNetGatherTaskTopic(CShfeFtdcRspQryNetGatherTaskField *pRspQryNetGatherTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ɼ�����
	virtual void OnRtnNetGatherTaskTopic(CShfeFtdcRtnNetGatherTaskField *pRtnNetGatherTask) {};

	///�豸���
	virtual void OnRspQryNetDeviceChgTopic(CShfeFtdcRspQryNetDeviceChgField *pRspQryNetDeviceChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�豸���
	virtual void OnRtnNetDeviceChgTopic(CShfeFtdcRtnNetDeviceChgField *pRtnNetDeviceChg) {};

	///�����豸�ͺ�
	virtual void OnRspQryNetDeviceTypeTopic(CShfeFtdcRspQryNetDeviceTypeField *pRspQryNetDeviceType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����豸�ͺ�
	virtual void OnRtnNetDeviceTypeTopic(CShfeFtdcRtnNetDeviceTypeField *pRtnNetDeviceType) {};

	///�����豸���
	virtual void OnRspQryNetDeviceCategoryTopic(CShfeFtdcRspQryNetDeviceCategoryField *pRspQryNetDeviceCategory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����豸���
	virtual void OnRtnNetDeviceCategoryTopic(CShfeFtdcRtnNetDeviceCategoryField *pRtnNetDeviceCategory) {};

	///�豸����
	virtual void OnRspQryNetManufactoryTopic(CShfeFtdcRspQryNetManufactoryField *pRspQryNetManufactory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�豸����
	virtual void OnRtnNetManufactoryTopic(CShfeFtdcRtnNetManufactoryField *pRtnNetManufactory) {};

	///�豸��ͬ��
	virtual void OnRspQryNetCommunityTopic(CShfeFtdcRspQryNetCommunityField *pRspQryNetCommunity, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�豸��ͬ��
	virtual void OnRtnNetCommunityTopic(CShfeFtdcRtnNetCommunityField *pRtnNetCommunity) {};

	///�˿�����
	virtual void OnRspQryNetPortTypeTopic(CShfeFtdcRspQryNetPortTypeField *pRspQryNetPortType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�˿�����
	virtual void OnRtnNetPortTypeTopic(CShfeFtdcRtnNetPortTypeField *pRtnNetPortType) {};

	///��Ա����ص�
	virtual void OnRspQryNetPartAccessSpotTopic(CShfeFtdcRspQryNetPartAccessSpotField *pRspQryNetPartAccessSpot, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա����ص�
	virtual void OnRtnNetPartAccessSpotTopic(CShfeFtdcRtnNetPartAccessSpotField *pRtnNetPartAccessSpot) {};

	///�˿�
	virtual void OnRspQryNetInterfaceTopic(CShfeFtdcRspQryNetInterfaceField *pRspQryNetInterface, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�˿�
	virtual void OnRtnNetInterfaceTopic(CShfeFtdcRtnNetInterfaceField *pRtnNetInterface) {};

	///GeneralOID
	virtual void OnRspQryNetGeneralOIDTopic(CShfeFtdcRspQryNetGeneralOIDField *pRspQryNetGeneralOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///GeneralOID
	virtual void OnRtnNetGeneralOIDTopic(CShfeFtdcRtnNetGeneralOIDField *pRtnNetGeneralOID) {};

	///��ض������
	virtual void OnRspQryNetMonitorTypeTopic(CShfeFtdcRspQryNetMonitorTypeField *pRspQryNetMonitorType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ض������
	virtual void OnRtnNetMonitorTypeTopic(CShfeFtdcRtnNetMonitorTypeField *pRtnNetMonitorType) {};

	///ָ��ͳ��
	virtual void OnRspQryNetMonitorAttrScopeTopic(CShfeFtdcRspQryNetMonitorAttrScopeField *pRspQryNetMonitorAttrScope, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ָ��ͳ��
	virtual void OnRtnNetMonitorAttrScopeTopic(CShfeFtdcRtnNetMonitorAttrScopeField *pRtnNetMonitorAttrScope) {};

	///���ָ���
	virtual void OnRspQryNetMonitorAttrTypeTopic(CShfeFtdcRspQryNetMonitorAttrTypeField *pRspQryNetMonitorAttrType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ָ���
	virtual void OnRtnNetMonitorAttrTypeTopic(CShfeFtdcRtnNetMonitorAttrTypeField *pRtnNetMonitorAttrType) {};

	///��ض���ָ���
	virtual void OnRspQryNetMonitorObjectAttrTopic(CShfeFtdcRspQryNetMonitorObjectAttrField *pRspQryNetMonitorObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ض���ָ���
	virtual void OnRtnNetMonitorObjectAttrTopic(CShfeFtdcRtnNetMonitorObjectAttrField *pRtnNetMonitorObjectAttr) {};

	///ְ����
	virtual void OnRspQryNetFuncAreaTopic(CShfeFtdcRspQryNetFuncAreaField *pRspQryNetFuncArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ְ����
	virtual void OnRtnNetFuncAreaTopic(CShfeFtdcRtnNetFuncAreaField *pRtnNetFuncArea) {};

	///���ָ���
	virtual void OnRspQryNetMonitorCommandTypeTopic(CShfeFtdcRspQryNetMonitorCommandTypeField *pRspQryNetMonitorCommandType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ָ���
	virtual void OnRtnNetMonitorCommandTypeTopic(CShfeFtdcRtnNetMonitorCommandTypeField *pRtnNetMonitorCommandType) {};

	///�������
	virtual void OnRspQryNetMonitorActionGroupTopic(CShfeFtdcRspQryNetMonitorActionGroupField *pRspQryNetMonitorActionGroup, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������
	virtual void OnRtnNetMonitorActionGroupTopic(CShfeFtdcRtnNetMonitorActionGroupField *pRtnNetMonitorActionGroup) {};

	///�豸�������
	virtual void OnRspQryNetMonitorDeviceGroupTopic(CShfeFtdcRspQryNetMonitorDeviceGroupField *pRspQryNetMonitorDeviceGroup, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�豸�������
	virtual void OnRtnNetMonitorDeviceGroupTopic(CShfeFtdcRtnNetMonitorDeviceGroupField *pRtnNetMonitorDeviceGroup) {};

	///������Ϣ��
	virtual void OnRspQryNetMonitorTaskInfoTopic(CShfeFtdcRspQryNetMonitorTaskInfoField *pRspQryNetMonitorTaskInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������Ϣ��
	virtual void OnRtnNetMonitorTaskInfoTopic(CShfeFtdcRtnNetMonitorTaskInfoField *pRtnNetMonitorTaskInfo) {};

	///��������
	virtual void OnRspQryNetMonitorTaskResultTopic(CShfeFtdcRspQryNetMonitorTaskResultField *pRspQryNetMonitorTaskResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������
	virtual void OnRtnNetMonitorTaskResultTopic(CShfeFtdcRtnNetMonitorTaskResultField *pRtnNetMonitorTaskResult) {};

	///�������
	virtual void OnRspQryNetMonitorTaskObjectSetTopic(CShfeFtdcRspQryNetMonitorTaskObjectSetField *pRspQryNetMonitorTaskObjectSet, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������
	virtual void OnRtnNetMonitorTaskObjectSetTopic(CShfeFtdcRtnNetMonitorTaskObjectSetField *pRtnNetMonitorTaskObjectSet) {};

	///��Ա��·��Ϣ��
	virtual void OnRspQryNetPartyLinkInfoTopic(CShfeFtdcRspQryNetPartyLinkInfoField *pRspQryNetPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա��·��Ϣ��
	virtual void OnRtnNetPartyLinkInfoTopic(CShfeFtdcRtnNetPartyLinkInfoField *pRtnNetPartyLinkInfo) {};

	///��ض���ָ����ձ�
	virtual void OnRspQryNetMonitorActionAttrTopic(CShfeFtdcRspQryNetMonitorActionAttrField *pRspQryNetMonitorActionAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ض���ָ����ձ�
	virtual void OnRtnNetMonitorActionAttrTopic(CShfeFtdcRtnNetMonitorActionAttrField *pRtnNetMonitorActionAttr) {};

	///ģ��
	virtual void OnRspQryNetModuleTopic(CShfeFtdcRspQryNetModuleField *pRspQryNetModule, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ģ��
	virtual void OnRtnNetModuleTopic(CShfeFtdcRtnNetModuleField *pRtnNetModule) {};

	///�澯���ʽ��Ϣ��
	virtual void OnRspQryNetEventExprTopic(CShfeFtdcRspQryNetEventExprField *pRspQryNetEventExpr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�澯���ʽ��Ϣ��
	virtual void OnRtnNetEventExprTopic(CShfeFtdcRtnNetEventExprField *pRtnNetEventExpr) {};

	///�¼�����
	virtual void OnRspQryNetEventTypeTopic(CShfeFtdcRspQryNetEventTypeField *pRspQryNetEventType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�¼�����
	virtual void OnRtnNetEventTypeTopic(CShfeFtdcRtnNetEventTypeField *pRtnNetEventType) {};

	///�¼�������
	virtual void OnRspQryNetSubEventTypeTopic(CShfeFtdcRspQryNetSubEventTypeField *pRspQryNetSubEventType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�¼�������
	virtual void OnRtnNetSubEventTypeTopic(CShfeFtdcRtnNetSubEventTypeField *pRtnNetSubEventType) {};

	///�¼�����
	virtual void OnRspQryNetEventLevelTopic(CShfeFtdcRspQryNetEventLevelField *pRspQryNetEventLevel, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�¼�����
	virtual void OnRtnNetEventLevelTopic(CShfeFtdcRtnNetEventLevelField *pRtnNetEventLevel) {};

	///������״̬��
	virtual void OnRspQryNetMonitorTaskStatusResultTopic(CShfeFtdcRspQryNetMonitorTaskStatusResultField *pRspQryNetMonitorTaskStatusResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������״̬��
	virtual void OnRtnNetMonitorTaskStatusResultTopic(CShfeFtdcRtnNetMonitorTaskStatusResultField *pRtnNetMonitorTaskStatusResult) {};

	///���÷���Ե�½����Ӧ
	virtual void OnRspConfigLoginTopic(CShfeFtdcRspQryConfigLoginField *pRspQryConfigLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�Ե�ǰ��¼���õķ����ɫ����Ӧ
	virtual void OnRspServerTypeTopic(CShfeFtdcRspServerTypeField *pRspServerType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�豸���ñ�
	virtual void OnRspQryNetCfgFileTopic(CShfeFtdcRspQryNetCfgFileField *pRspQryNetCfgFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�豸���ñ�
	virtual void OnRtnNetCfgFileTopic(CShfeFtdcRtnNetCfgFileField *pRtnNetCfgFile) {};

	///���������������
	virtual void OnRspQryNetMonitorDeviceTaskTopic(CShfeFtdcRspQryNetMonitorDeviceTaskField *pRspQryNetMonitorDeviceTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���������������
	virtual void OnRtnNetMonitorDeviceTaskTopic(CShfeFtdcRtnNetMonitorDeviceTaskField *pRtnNetMonitorDeviceTask) {};

	///����ָ��ָ�꼯��
	virtual void OnRspQryNetMonitorTaskInstAttrsTopic(CShfeFtdcRspQryNetMonitorTaskInstAttrsField *pRspQryNetMonitorTaskInstAttrs, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ָ��ָ�꼯��
	virtual void OnRtnNetMonitorTaskInstAttrsTopic(CShfeFtdcRtnNetMonitorTaskInstAttrsField *pRtnNetMonitorTaskInstAttrs) {};

	///�ļ�ͨ�ò���
	virtual void OnRspQryFileGeneralOperTopic(CShfeFtdcRspQryFileGeneralOperField *pRspQryFileGeneralOper, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ļ�ͨ�ò���
	virtual void OnRtnFileGeneralOperTopic(CShfeFtdcRtnFileGeneralOperField *pRtnFileGeneralOper) {};

	///���߱�
	virtual void OnRspQryNetBaseLineTopic(CShfeFtdcRspQryNetBaseLineField *pRspQryNetBaseLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���߱�
	virtual void OnRtnNetBaseLineTopic(CShfeFtdcRtnNetBaseLineField *pRtnNetBaseLine) {};

	///���������
	virtual void OnRspQryNetBaseLineTaskTopic(CShfeFtdcRspQryNetBaseLineTaskField *pRspQryNetBaseLineTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���������
	virtual void OnRtnNetBaseLineTaskTopic(CShfeFtdcRtnNetBaseLineTaskField *pRtnNetBaseLineTask) {};

	///���߽����
	virtual void OnRspQryNetBaseLineResultTopic(CShfeFtdcRspQryNetBaseLineResultField *pRspQryNetBaseLineResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���߽����
	virtual void OnRtnNetBaseLineResultTopic(CShfeFtdcRtnNetBaseLineResultField *pRtnNetBaseLineResult) {};

	///��Ա��·״̬��Ϣ��
	virtual void OnRspQryNetPartyLinkStatusInfoTopic(CShfeFtdcRspQryNetPartyLinkStatusInfoField *pRspQryNetPartyLinkStatusInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա��·״̬��Ϣ��
	virtual void OnRtnNetPartyLinkStatusInfoTopic(CShfeFtdcRtnNetPartyLinkStatusInfoField *pRtnNetPartyLinkStatusInfo) {};

	///��ԱSDH��·��ϸ��
	virtual void OnRspQryNetMemberSDHLineInfoTopic(CShfeFtdcRspQryNetMemberSDHLineInfoField *pRspQryNetMemberSDHLineInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ԱSDH��·��ϸ��
	virtual void OnRtnNetMemberSDHLineInfoTopic(CShfeFtdcRtnNetMemberSDHLineInfoField *pRtnNetMemberSDHLineInfo) {};

	///DDN��·��Ϣ��
	virtual void OnRspQryNetDDNLinkInfoTopic(CShfeFtdcRspQryNetDDNLinkInfoField *pRspQryNetDDNLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///DDN��·��Ϣ��
	virtual void OnRtnNetDDNLinkInfoTopic(CShfeFtdcRtnNetDDNLinkInfoField *pRtnNetDDNLinkInfo) {};

	///�ǻ�Ա��·ʹ����Ϣ
	virtual void OnRspQryNetPseudMemberLinkInfoTopic(CShfeFtdcRspQryNetPseudMemberLinkInfoField *pRspQryNetPseudMemberLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ǻ�Ա��·ʹ����Ϣ
	virtual void OnRtnNetPseudMemberLinkInfoTopic(CShfeFtdcRtnNetPseudMemberLinkInfoField *pRtnNetPseudMemberLinkInfo) {};

	///Զ���豸��Ϣ
	virtual void OnRspQryOuterDeviceInfTopic(CShfeFtdcRspQryOuterDeviceInfField *pRspQryOuterDeviceInf, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Զ���豸��Ϣ
	virtual void OnRtnNetOuterDeviceInfTopic(CShfeFtdcRtnNetOuterDeviceInfField *pRtnNetOuterDeviceInf) {};

	///����ping���
	virtual void OnRspQryNetLocalPingResultInfoTopic(CShfeFtdcRspQryNetLocalPingResultInfoField *pRspQryNetLocalPingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ping���
	virtual void OnRtnNetLocalPingResultInfoTopic(CShfeFtdcRtnNetLocalPingResultInfoField *pRtnNetLocalPingResultInfo) {};

	///Զ��ping���
	virtual void OnRspQryNetRomotePingResultInfoTopic(CShfeFtdcRspQryNetRomotePingResultInfoField *pRspQryNetRomotePingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Զ��ping���
	virtual void OnRtnNetRomotePingResultInfoTopic(CShfeFtdcRtnNetRomotePingResultInfoField *pRtnNetRomotePingResultInfo) {};

	///������Ϣ���ݿ�ר��
	virtual void OnRtnMonitorTopProcessInfo(CShfeFtdcRtnMonitorTopProcessInfoField *pRtnMonitorTopProcessInfo) {};

	///ϵͳ�ڲ�������ϵ
	virtual void OnRspQrySysInternalTopologyTopic(CShfeFtdcRspQrySysInternalTopologyField *pRspQrySysInternalTopology, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ϵͳ�ڲ�������ϵ
	virtual void OnRtnSysInternalTopologyTopic(CShfeFtdcRtnSysInternalTopologyField *pRtnSysInternalTopology) {};

	///���ػ�Ա��·���ñ�
	virtual void OnRspQryMemberLinkCostTopic(CShfeFtdcRspQryMemberLinkCostField *pRspQryMemberLinkCost, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���Ļ�Ա��·���ñ�
	virtual void OnRtnMemberLinkCostTopic(CShfeFtdcRtnMemberLinkCostField *pRtnMemberLinkCost) {};

	///���ػ�Ա��·�����
	virtual void OnRspQryNetPartylinkMonthlyRentTopic(CShfeFtdcRspQryNetPartylinkMonthlyRentField *pRspQryNetPartylinkMonthlyRent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���Ļ�Ա��·�����
	virtual void OnRtnNetPartylinkMonthlyRentTopic(CShfeFtdcRtnNetPartylinkMonthlyRentField *pRtnNetPartylinkMonthlyRent) {};

	///���طǻ�Ա��·����Ϣ
	virtual void OnRspQryNetNonPartyLinkInfoTopic(CShfeFtdcRspQryNetNonPartyLinkInfoField *pRspQryNetNonPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ķǻ�Ա��·����Ϣ
	virtual void OnRtnNetNonPartyLinkInfoTopic(CShfeFtdcRtnNetNonPartyLinkInfoField *pRtnNetNonPartyLinkInfo) {};

	///Ӧ��������Ϣ
	virtual void OnRspQryMonConfigInfo(CShfeFtdcRspQryMonConfigInfoField *pRspQryMonConfigInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ӧ��������Ϣ
	virtual void OnRtnMonConfigInfo(CShfeFtdcRtnMonConfigInfoField *pRtnMonConfigInfo) {};

	///֪ͨ�������Ϣ
	virtual void OnRtnMonitorDayInfo(CShfeFtdcMonitorDayInfoField *pMonitorDayInfo) {};

	///֪ͨ��������Ϣ
	virtual void OnRtnTradingDayInfo(CShfeFtdcTradingDayInfoField *pTradingDayInfo) {};

	///��ؽ׶ν���
	virtual void OnRtnSectionFinish(CShfeFtdcMonitorSectionField *pMonitorSection) {};

	///��ؽ׶��л�
	virtual void OnRtnSectionChange(CShfeFtdcMonitorSectionField *pMonitorSection) {};

	///����������Ӧ
	virtual void OnRspMonServiceConnect(CShfeFtdcRspMonServiceConnectField *pRspMonServiceConnect, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Proxy��̽����������
	virtual void OnRtnMonProxyConfig(CShfeFtdcRtnMonProxyConfigField *pRtnMonProxyConfig) {};

	///����ĵ�ǰ״̬��Ӧ
	virtual void OnRspQryMonServiceStatus(CShfeFtdcRspQryMonServiceStatusField *pRspQryMonServiceStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ĵ�ǰ״̬����
	virtual void OnRtnMonServiceStatus(CShfeFtdcRtnMonServiceStatusField *pRtnMonServiceStatus) {};

	///��ǰ�������Ľ�ɫ
	virtual void OnRtnMonDataCenterRole(CShfeFtdcRtnMonDataCenterRoleField *pRtnMonDataCenterRole) {};

	///̽���������ò�ѯ��Ӧ
	virtual void OnRspQryMonProbeTask(CShfeFtdcRspQryMonProbeTaskField *pRspQryMonProbeTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///̽��������������
	virtual void OnRtnMonProbeTask(CShfeFtdcRtnMonProbeTaskField *pRtnMonProbeTask) {};

	///���ϵͳָ���ѯӦ��
	virtual void OnRspQryMonObjectAttr(CShfeFtdcRspQryMonObjectAttrField *pRspQryMonObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ϵͳָ���ѯ����
	virtual void OnRtnMonObjectAttr(CShfeFtdcRtnMonObjectAttrField *pRtnMonObjectAttr) {};

	///���ϵͳSyslog�¼���ѯӦ��
	virtual void OnRspQryMonSyslogEvent(CShfeFtdcRspQryMonSyslogEventField *pRspQryMonSyslogEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ϵͳSyslog�¼���ѯ����
	virtual void OnRtnMonSyslogEvent(CShfeFtdcRtnMonSyslogEventField *pRtnMonSyslogEvent) {};

	///�ļ���ȡƫ������ѯӦ��
	virtual void OnRspQryMonFileOffset(CShfeFtdcRspQryMonFileOffsetField *pRspQryMonFileOffset, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ļ���ȡƫ������ѯ����
	virtual void OnRtnMonFileOffset(CShfeFtdcRtnMonFileOffsetField *pRtnMonFileOffset) {};

	///�ļ����ݲ�ѯӦ��
	virtual void OnRspQryMonFileContent(CShfeFtdcRspQryMonFileContentField *pRspQryMonFileContent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ļ�����ͨ��
	virtual void OnRtnMonFileContent(CShfeFtdcRtnMonFileContentField *pRtnMonFileContent) {};

	///��������������ϢӦ��
	virtual void OnRspQryMonHostBasicEnv(CShfeFtdcRspQryMonHostBasicEnvField *pRspQryMonHostBasicEnv, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������������ϢӦ��
	virtual void OnRtnMonHostBasicEnv(CShfeFtdcRtnMonHostBasicEnvField *pRtnMonHostBasicEnv) {};

	///��������������ϢӦ��
	virtual void OnRspQryMonHostNetworkEnv(CShfeFtdcRspQryMonHostNetworkEnvField *pRspQryMonHostNetworkEnv, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������������Ϣͨ��
	virtual void OnRtnMonHostNetworkEnv(CShfeFtdcRtnMonHostNetworkEnvField *pRtnMonHostNetworkEnv) {};

	///�����ļ�ϵͳ��ϢӦ��
	virtual void OnRspQryMonHostFileSysEnv(CShfeFtdcRspQryMonHostFileSysEnvField *pRspQryMonHostFileSysEnv, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ļ�ϵͳ��Ϣͨ��
	virtual void OnRtnMonHostFileSysEnv(CShfeFtdcRtnMonHostFileSysEnvField *pRtnMonHostFileSysEnv) {};

	///��������������ϢӦ��
	virtual void OnRspQryMonHostSwapEnv(CShfeFtdcRspQryMonHostSwapEnvField *pRspQryMonHostSwapEnv, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������������Ϣͨ��
	virtual void OnRtnMonHostSwapEnv(CShfeFtdcRtnMonHostSwapEnvField *pRtnMonHostSwapEnv) {};

	///������CPU��Ϣָ����ϢӦ��
	virtual void OnRspQryMonHostCPUAttr(CShfeFtdcRspQryMonHostCPUAttrField *pRspQryMonHostCPUAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������CPU��Ϣָ����Ϣ
	virtual void OnRtnMonHostCPUAttr(CShfeFtdcRtnMonHostCPUAttrField *pRtnMonHostCPUAttr) {};

	///������Memoryʹ����ϢӦ��
	virtual void OnRspQryMonHostMemAttr(CShfeFtdcRspQryMonHostMemAttrField *pRspQryMonHostMemAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������Memoryʹ����Ϣ
	virtual void OnRtnMonHostMemAttr(CShfeFtdcRtnMonHostMemAttrField *pRtnMonHostMemAttr) {};

	///������FileSystemʹ����ϢӦ��
	virtual void OnRspQryMonHostFileSystemAttr(CShfeFtdcRspQryMonHostFileSystemAttrField *pRspQryMonHostFileSystemAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������FileSystemʹ����Ϣ
	virtual void OnRtnMonHostFileSystemAttr(CShfeFtdcRtnMonHostFileSystemAttrField *pRtnMonHostFileSystemAttr) {};

	///�������û���ϢӦ��
	virtual void OnRspQryMonHostUserInfo(CShfeFtdcRspQryMonHostUserInfoField *pRspQryMonHostUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������û���Ϣ
	virtual void OnRtnMonHostUserInfo(CShfeFtdcRtnMonHostUserInfoField *pRtnMonHostUserInfo) {};

	///�����������û���ϢӦ��
	virtual void OnRspQryMonHostOnlineUserInfo(CShfeFtdcRspQryMonHostOnlineUserInfoField *pRspQryMonHostOnlineUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����������û���Ϣ
	virtual void OnRtnMonHostOnlineUserInfo(CShfeFtdcRtnMonHostOnlineUserInfoField *pRtnMonHostOnlineUserInfo) {};

	///������networkʹ����ϢӦ��
	virtual void OnRspQryMonHostNetworkAttr(CShfeFtdcRspQryMonHostNetworkAttrField *pRspQryMonHostNetworkAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������networkʹ����Ϣ
	virtual void OnRtnMonHostNetworkAttr(CShfeFtdcRtnMonHostNetworkAttrField *pRtnMonHostNetworkAttr) {};

	///������ϵͳ״̬��ϢӦ��
	virtual void OnRspQryMonHostStatInfo(CShfeFtdcRspQryMonHostStatInfoField *pRspQryMonHostStatInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������ϵͳ״̬��Ϣ
	virtual void OnRtnMonHostStatInfo(CShfeFtdcRtnMonHostStatInfoField *pRtnMonHostStatInfo) {};

	///�����Ĵ���IO��ϢӦ��
	virtual void OnRspQryMonHostDiskIOAttr(CShfeFtdcRspQryMonHostDiskIOAttrField *pRspQryMonHostDiskIOAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����Ĵ���IO��Ϣ
	virtual void OnRtnMonHostDiskIOAttr(CShfeFtdcRtnMonHostDiskIOAttrField *pRtnMonHostDiskIOAttr) {};

	///������·����ϢӦ��
	virtual void OnRspQryMonHostRouterInfo(CShfeFtdcRspQryMonHostRouterInfoField *pRspQryMonHostRouterInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������·����Ϣ
	virtual void OnRtnMonHostRouterInfo(CShfeFtdcRtnMonHostRouterInfoField *pRtnMonHostRouterInfo) {};

	///�����Ľ�����ϢӦ��
	virtual void OnRspQryMonHostProcessInfo(CShfeFtdcRspQryMonHostProcessInfoField *pRspQryMonHostProcessInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����Ľ�����Ϣ
	virtual void OnRtnMonHostProcessInfo(CShfeFtdcRtnMonHostProcessInfoField *pRtnMonHostProcessInfo) {};

	///���ݿ�ɼ������ͱ��ģ�������SP��DBLog��DBAttr
	virtual void OnRtnMonDBQuery(CShfeFtdcRtnMonDBQueryField *pRtnMonDBQuery) {};

	///��Ӧ�ͻ�����ʱSP��ѯ����
	virtual void OnRspQryMonSPQuery(CShfeFtdcRtnMonDBQueryField *pRtnMonDBQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����汾��Ϣ��Ӧ
	virtual void OnRspServiceVersion(CShfeFtdcRspServiceVersionField *pRspServiceVersion, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����Ӧ�ó�����Ӧ
	virtual void OnRspServiceProgram(CShfeFtdcRspServiceProgramField *pRspServiceProgram, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���������ȡ״̬��Ӧ
	virtual void OnRspUpdateState(CShfeFtdcRspUpdateStateField *pRspUpdateState, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ӧ��
	virtual void OnRspSubscribe(CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///֪ͨĿ������ļ��ѳɹ�����
	virtual void OnRspFileSendSuccess(CShfeFtdcRspFileSendSuccessField *pRspFileSendSuccess, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����֪ͨĿ������ļ��ѷ��ͳɹ�
	virtual void OnRtnFileSendSuccess(CShfeFtdcRtnFileSendSuccessField *pRtnFileSendSuccess) {};

	///tomcat��ϢӦ��
	virtual void OnRspQryMonTomcatInfo(CShfeFtdcRspQryMonTomcatInfoField *pRspQryMonTomcatInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///tomcat��Ϣ����
	virtual void OnRtnMonTomcatInfo(CShfeFtdcRtnMonTomcatInfoField *pRtnMonTomcatInfo) {};

	///WebӦ����Ϣ
	virtual void OnRspQryMonWebAppInfo(CShfeFtdcRspQryMonWebAppInfoField *pRspQryMonWebAppInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///WebӦ����Ϣ
	virtual void OnRtnMonWebAppInfo(CShfeFtdcRtnMonWebAppInfoField *pRtnMonWebAppInfo) {};

	///Ӧ��servlet��Ϣ
	virtual void OnRspQryMonServletInfo(CShfeFtdcRspQryMonServletInfoField *pRspQryMonServletInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ӧ��servlet��Ϣ
	virtual void OnRtnMonServletInfo(CShfeFtdcRtnMonServletInfoField *pRtnMonServletInfo) {};

	///�ļ���Ϣ
	virtual void OnRspQryMonFileInfo(CShfeFtdcRspQryMonFileInfoField *pRspQryMonFileInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ļ���Ϣ
	virtual void OnRtnMonFileInfo(CShfeFtdcRtnMonFileInfoField *pRtnMonFileInfo) {};

	///Ӧ�ûỰ��ϢӦ��
	virtual void OnRspQryMonSessionInfo(CShfeFtdcRspQryMonSessionInfoField *pRspQryMonSessionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ӧ�ûỰ��Ϣ����
	virtual void OnRtnMonSessionInfo(CShfeFtdcRtnMonSessionInfoField *pRtnMonSessionInfo) {};

	///JDBC��Ϣ
	virtual void OnRspQryMonJDBCInfo(CShfeFtdcRspQryMonJDBCInfoField *pRspQryMonJDBCInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///JDBC��Ϣ
	virtual void OnRtnMonJDBCInfo(CShfeFtdcRtnMonJDBCInfoField *pRtnMonJDBCInfo) {};

	///�߳���Ϣ
	virtual void OnRspQryMonThreadInfo(CShfeFtdcRspQryMonThreadInfoField *pRspQryMonThreadInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�߳���Ϣ
	virtual void OnRtnMonThreadInfo(CShfeFtdcRtnMonThreadInfoField *pRtnMonThreadInfo) {};

	///�������Ϣ
	virtual void OnRspQryMonVMInfo(CShfeFtdcRspQryMonVMInfoField *pRspQryMonVMInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������Ϣ
	virtual void OnRtnMonVMInfo(CShfeFtdcRtnMonVMInfoField *pRtnMonVMInfo) {};

	///ϵͳ������Ϣ
	virtual void OnRspQryMonPropertyInfo(CShfeFtdcRspQryMonPropertyInfoField *pRspQryMonPropertyInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ϵͳ������Ϣ
	virtual void OnRtnMonPropertyInfo(CShfeFtdcRtnMonPropertyInfoField *pRtnMonPropertyInfo) {};

	///ϵͳ�ڴ����Ϣ
	virtual void OnRspQryMonMemPoolInfo(CShfeFtdcRspQryMonMemPoolInfoField *pRspQryMonMemPoolInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ϵͳ�ڴ����Ϣ
	virtual void OnRtnMonMemPoolInfo(CShfeFtdcRtnMonMemPoolInfoField *pRtnMonMemPoolInfo) {};

	///������Ϣ
	virtual void OnRspQryMonConnectionInfo(CShfeFtdcRspQryMonConnectionInfoField *pRspQryMonConnectionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������Ϣ
	virtual void OnRtnMonConnectionInfo(CShfeFtdcRtnMonConnectionInfoField *pRtnMonConnectionInfo) {};

	///��Ч������ѯӦ��
	virtual void OnRspQryInvalidateOrderTopic(CShfeFtdcRspQryInvalidateOrderField *pRspQryInvalidateOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ч������ѯӦ��
	virtual void OnRtnInvalidateOrderTopic(CShfeFtdcRtnInvalidateOrderField *pRtnInvalidateOrder) {};

	///����״̬��ѯӦ��
	virtual void OnRspQryOrderStatusTopic(CShfeFtdcRspQryOrderStatusField *pRspQryOrderStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����״̬��ѯӦ��
	virtual void OnRtnOrderStatusTopic(CShfeFtdcRtnOrderStatusField *pRtnOrderStatus) {};

	///�����ɽ���ѯӦ��
	virtual void OnRspQryBargainOrderTopic(CShfeFtdcRspQryBargainOrderField *pRspQryBargainOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ɽ���ѯӦ��
	virtual void OnRtnBargainOrderTopic(CShfeFtdcRtnBargainOrderField *pRtnBargainOrder) {};

	///��Լ�������Բ�ѯӦ��
	virtual void OnRspQryInstPropertyTopic(CShfeFtdcRspQryInstPropertyField *pRspQryInstProperty, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ�������Բ�ѯӦ��
	virtual void OnRtnInstPropertyTopic(CShfeFtdcRtnInstPropertyField *pRtnInstProperty) {};

	///��Լ��֤���ʲ�ѯӦ��
	virtual void OnRspQryMarginRateTopic(CShfeFtdcRspQryMarginRateField *pRspQryMarginRate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ��֤���ʲ�ѯӦ��
	virtual void OnRtnMarginRateTopic(CShfeFtdcRtnMarginRateField *pRtnMarginRate) {};

	///��Լ�ǵ�ͣ���ѯӦ��
	virtual void OnRspQryPriceLimitTopic(CShfeFtdcRspQryPriceLimitField *pRspQryPriceLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ�ǵ�ͣ���ѯӦ��
	virtual void OnRtnPriceLimitTopic(CShfeFtdcRtnPriceLimitField *pRtnPriceLimit) {};

	///��Ա�޲ֲ�ѯӦ��
	virtual void OnRspQryPartPosiLimitTopic(CShfeFtdcRspQryPartPosiLimitField *pRspQryPartPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա�޲ֲ�ѯӦ��
	virtual void OnRtnPartPosiLimitTopic(CShfeFtdcRtnPartPosiLimitField *pRtnPartPosiLimit) {};

	///�ͻ��޲ֲ�ѯӦ��
	virtual void OnRspQryClientPosiLimitTopic(CShfeFtdcRspQryClientPosiLimitField *pRspQryClientPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ͻ��޲ֲ�ѯӦ��
	virtual void OnRtnClientPosiLimitTopic(CShfeFtdcRtnClientPosiLimitField *pRtnClientPosiLimit) {};

	///����ͻ��޲ֲ�ѯӦ��
	virtual void OnRspQrySpecialPosiLimitTopic(CShfeFtdcRspQrySpecialPosiLimitField *pRspQrySpecialPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ͻ��޲ֲ�ѯӦ��
	virtual void OnRtnSpecialPosiLimitTopic(CShfeFtdcRtnSpecialPosiLimitField *pRtnSpecialPosiLimit) {};

	///�˻�������ѯӦ��
	virtual void OnRspQryTransactionChgTopic(CShfeFtdcRspQryTransactionChgField *pRspQryTransactionChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�˻�������ѯӦ��
	virtual void OnRtnTransactionChgTopic(CShfeFtdcRtnTransactionChgField *pRtnTransactionChg) {};

	///�ͻ����ݱ䶯��ѯӦ��
	virtual void OnRspQryClientChgTopic(CShfeFtdcRspQryClientChgField *pRspQryClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ͻ����ݱ䶯��ѯӦ��
	virtual void OnRtnClientChgTopic(CShfeFtdcRtnClientChgField *pRtnClientChg) {};

	///��Ա�ͻ����ձ䶯��ѯӦ��
	virtual void OnRspQryPartClientChgTopic(CShfeFtdcRspQryPartClientChgField *pRspQryPartClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա�ͻ����ձ䶯��ѯӦ��
	virtual void OnRtnPartClientChgTopic(CShfeFtdcRtnPartClientChgField *pRtnPartClientChg) {};

	///�޲����ݱ䶯��ѯӦ��
	virtual void OnRspQryPosiLimitChgTopic(CShfeFtdcRspQryPosiLimitChgField *pRspQryPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�޲����ݱ䶯��ѯӦ��
	virtual void OnRtnPosiLimitChgTopic(CShfeFtdcRtnPosiLimitChgField *pRtnPosiLimitChg) {};

	///��ֵ��ȱ䶯��ѯӦ��
	virtual void OnRspQryHedgeDetailChgTopic(CShfeFtdcRspQryHedgeDetailChgField *pRspQryHedgeDetailChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ֵ��ȱ䶯��ѯӦ��
	virtual void OnRtnHedgeDetailChgTopic(CShfeFtdcRtnHedgeDetailChgField *pRtnHedgeDetailChg) {};

	///��Ա�䶯��ѯӦ��
	virtual void OnRspQryParticipantChgTopic(CShfeFtdcRspQryParticipantChgField *pRspQryParticipantChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա�䶯��ѯӦ��
	virtual void OnRtnParticipantChgTopic(CShfeFtdcRtnParticipantChgField *pRtnParticipantChg) {};

	///��֤���ʱ䶯��ѯӦ��
	virtual void OnRspQryMarginRateChgTopic(CShfeFtdcRspQryMarginRateChgField *pRspQryMarginRateChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��֤���ʱ䶯��ѯӦ��
	virtual void OnRtnMarginRateChgTopic(CShfeFtdcRtnMarginRateChgField *pRtnMarginRateChg) {};

	///IP��ַ�䶯��ѯӦ��
	virtual void OnRspQryUserIpChgTopic(CShfeFtdcRspQryUserIpChgField *pRspQryUserIpChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///IP��ַ�䶯��ѯӦ��
	virtual void OnRtnUserIpChgTopic(CShfeFtdcRtnUserIpChgField *pRtnUserIpChg) {};

	///�޲����ݱ䶯��ѯӦ��
	virtual void OnRspQryClientPosiLimitChgTopic(CShfeFtdcRspQryClientPosiLimitChgField *pRspQryClientPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�޲����ݱ䶯��ѯӦ��
	virtual void OnRtnClientPosiLimitChgTopic(CShfeFtdcRtnClientPosiLimitChgField *pRtnClientPosiLimitChg) {};

	///�޲����ݱ䶯��ѯӦ��
	virtual void OnRspQrySpecPosiLimitChgTopic(CShfeFtdcRspQrySpecPosiLimitChgField *pRspQrySpecPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�޲����ݱ䶯��ѯӦ��
	virtual void OnRtnSpecPosiLimitChgTopic(CShfeFtdcRtnSpecPosiLimitChgField *pRtnSpecPosiLimitChg) {};

	///����ϵͳǰ��ͳ��Ӧ��
	virtual void OnRspQryFrontStatTopic(CShfeFtdcRspQryFrontStatField *pRspQryFrontStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա��ʼ��Ӧ��
	virtual void OnRspQryParticipantInitTopic(CShfeFtdcRspQryParticipantInitField *pRspQryParticipantInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ա��ʼ��Ӧ��
	virtual void OnRtnParticipantInitTopic(CShfeFtdcRtnParticipantInitField *pRtnParticipantInit) {};

	///��ϯ��ʼ��Ӧ��
	virtual void OnRspQryUserInitTopic(CShfeFtdcRspQryUserInitField *pRspQryUserInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ϯ��ʼ��Ӧ��
	virtual void OnRtnUserInitTopic(CShfeFtdcRtnUserInitField *pRtnUserInit) {};

	///����Լ״̬�л�����
	virtual void OnRspQryInstrumentStatusTopic(CShfeFtdcRspQryInstrumentStatusField *pRspQryInstrumentStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����Լ״̬�л�����
	virtual void OnRtnInstrumentStatusTopic(CShfeFtdcRtnInstrumentStatusField *pRtnInstrumentStatus) {};

	///���غ�Լ���׽���Ϣ
	virtual void OnRspQryCurrTradingSegmentAttrTopic(CShfeFtdcRspQryCurrTradingSegmentAttrField *pRspQryCurrTradingSegmentAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ĺ�Լ���׽���Ϣ
	virtual void OnRtnCurrTradingSegmentAttrTopic(CShfeFtdcRtnCurrTradingSegmentAttrField *pRtnCurrTradingSegmentAttr) {};

	///����ϵͳ��¼��Ϣ
	virtual void OnRspQryTradeUserLoginInfoTopic(CShfeFtdcRspQryTradeUserLoginInfoField *pRspQryTradeUserLoginInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ϵͳ��¼��Ϣ
	virtual void OnRtnTradeUserLoginInfoTopic(CShfeFtdcRtnTradeUserLoginInfoField *pRtnTradeUserLoginInfo) {};

	///��Ա���ײ�ѯӦ��
	virtual void OnRspQryPartTradeTopic(CShfeFtdcRspQryPartTradeField *pRspQryPartTrade, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Աϯλ����״̬
	virtual void OnRspQryParticTradeOrderStatesTopic(CShfeFtdcRspQryParticTradeOrderStatesField *pRspQryParticTradeOrderStates, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Աϯλ����״̬
	virtual void OnRtnParticTradeOrderStatesTopic(CShfeFtdcRtnParticTradeOrderStatesField *pRtnParticTradeOrderStates) {};

	///��ü�ض�����ϢӦ��
	virtual void OnRspQryMonitor2ObjectTopic(CShfeFtdcRspQryMonitor2ObjectField *pRspQryMonitor2Object, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ü�ض�����ϢӦ��
	virtual void OnRtnMonitor2ObjectTopic(CShfeFtdcRtnMonitor2ObjectField *pRtnMonitor2Object) {};

	///����������ϢӦ��
	virtual void OnRspQryMonHostCommonEnvTopic(CShfeFtdcRspQryMonHostCommonEnvField *pRspQryMonHostCommonEnv, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����������ϢӦ��
	virtual void OnRtnMonHostCommonEnvTopic(CShfeFtdcRtnMonHostCommonEnvField *pRtnMonHostCommonEnv) {};

	///Ӧ��ҵ����̺�������ϵ
	virtual void OnRspQryMonOidHostRationalTopic(CShfeFtdcRspQryMonOidHostRationalField *pRspQryMonOidHostRational, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ҵ����̺�������ϵ
	virtual void OnRtnMonOidHostRationalTopic(CShfeFtdcRtnMonOidHostRationalField *pRtnMonOidHostRational) {};

	///�����ϵ��ѯӦ��
	virtual void OnRspQryMonOidRelationTopic(CShfeFtdcRspQryMonOidRelationField *pRspQryMonOidRelation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ϵ��ѯӦ��
	virtual void OnRtnMonOidRelationTopic(CShfeFtdcRtnMonOidRelationField *pRtnMonOidRelation) {};
};

class USER_API_EXPORT CShfeFtdcUserApi
{
public:
	///����UserApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	///@param pszUserApiType UserAPI����
	///@return ��������UserApi
	static CShfeFtdcUserApi *CreateFtdcUserApi(const char *pszFlowPath = "",
											const char *pszUserApiType = "");
	
	///��ȡϵͳ�汾��
	///@param nMajorVersion ���汾��
	///@param nMinorVersion �Ӱ汾��
	///@return ϵͳ��ʶ�ַ���
	static const char *GetVersion(int &nMajorVersion, int &nMinorVersion);
	
	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release() = 0;
	
	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	virtual void Init() = 0;
	
	///�ȴ��ӿ��߳̽�������
	///@return �߳��˳�����
	virtual int Join() = 0;
	
	///��ȡ��ǰ������
	///@retrun ��ȡ���Ľ�����
	///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
	virtual const char *GetTradingDay() = 0;
	
	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	
	///ע�����ַ����������ַ
	///@param pszNsAddress�����ַ����������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:12001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����12001������������˿ںš�
	///@remark RegisterFront������RegisterNameServer
	virtual void RegisterNameServer(char *pszNsAddress) = 0;
	
	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CShfeFtdcUserSpi *pSpi) = 0;
	
	///����֤��
	///@param pszCertFileName �û�֤���ļ���
	///@param pszKeyFileName �û�˽Կ�ļ���
	///@param pszCaFileName ������CA֤���ļ���
	///@param pszKeyFilePassword �û�˽Կ�ļ�����
	///@return 0 �����ɹ�
	///@return -1 ������CA֤������ʧ��
	///@return -2 �û�֤������ʧ��
	///@return -3 �û�˽Կ����ʧ��	
	///@return -4 �û�֤��У��ʧ��
	virtual int RegisterCertificateFile(const char *pszCertFileName, const char *pszKeyFileName, 
		const char *pszCaFileName, const char *pszKeyFilePassword) = 0;
	
	///�����г����顣
	///@param nTopicID �г���������  
	///@param nResumeType �г������ش���ʽ  
	///        TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        TERT_RESUME:���ϴ��յ�������
	///        TERT_QUICK:�ȴ��͵�ǰ�������,�ٴ��͵�¼���г����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
	virtual void SubscribeMarketDataTopic(int nTopicID, TE_RESUME_TYPE nResumeType) = 0;

	///����˽������
	///@param nResumeType ˽�����ش���ʽ  
	///        TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        TERT_RESUME:���ϴ��յ�������
	///        TERT_QUICK:ֻ���͵�¼��˽����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
	virtual void SubscribePrivateTopic(TE_RESUME_TYPE nResumeType) = 0;
	
	///���Ĺ�������
	///@param nResumeType �������ش���ʽ  
	///        TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        TERT_RESUME:���ϴ��յ�������
	///        TERT_QUICK:ֻ���͵�¼�󹫹���������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ������������ݡ�
	virtual void SubscribePublicTopic(TE_RESUME_TYPE nResumeType) = 0;
	
	///���Ľ���Ա����
	///@param nResumeType ����Ա���ش���ʽ  
	///        TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        TERT_RESUME:���ϴ��յ�������
	///        TERT_QUICK:ֻ���͵�¼����Ա��������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�����Ա�������ݡ�
	virtual void SubscribeUserTopic(TE_RESUME_TYPE nResumeType) = 0;
	
	///����������ʱʱ�䡣
	///@param timeout ������ʱʱ��(��)  
	virtual void SetHeartbeatTimeout(unsigned int timeout) = 0;
	
	///��������־�ļ�
	///@param pszReqLogFileName ������־�ļ���  
	///@return 0 �����ɹ�
	///@return -1 ����־�ļ�ʧ��
	virtual int OpenRequestLog(const char *pszReqLogFileName) = 0;

	///��Ӧ����־�ļ�
	///@param pszRspLogFileName Ӧ����־�ļ���  
	///@return 0 �����ɹ�
	///@return -1 ����־�ļ�ʧ��
	virtual int OpenResponseLog(const char *pszRspLogFileName) = 0;
	
	///�û���¼����
	virtual int ReqUserLogin(CShfeFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;

	///�û��˳�����
	virtual int ReqUserLogout(CShfeFtdcReqUserLogoutField *pReqUserLogout, int nRequestID) = 0;

	///����¼������
	virtual int ReqOrderInsert(CShfeFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	///������������
	virtual int ReqOrderAction(CShfeFtdcOrderActionField *pOrderAction, int nRequestID) = 0;

	///����¼������
	virtual int ReqQuoteInsert(CShfeFtdcInputQuoteField *pInputQuote, int nRequestID) = 0;

	///���۲�������
	virtual int ReqQuoteAction(CShfeFtdcQuoteActionField *pQuoteAction, int nRequestID) = 0;

	///OTC����¼������
	virtual int ReqOTCOrderInsert(CShfeFtdcOTCOrderField *pOTCOrder, int nRequestID) = 0;

	///�û������޸�����
	virtual int ReqUserPasswordUpdate(CShfeFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

	///ִ������¼������
	virtual int ReqExecOrderInsert(CShfeFtdcInputExecOrderField *pInputExecOrder, int nRequestID) = 0;

	///ִ�������������
	virtual int ReqExecOrderAction(CShfeFtdcExecOrderActionField *pExecOrderAction, int nRequestID) = 0;

	///������¼������
	virtual int ReqAdminOrderInsert(CShfeFtdcInputAdminOrderField *pInputAdminOrder, int nRequestID) = 0;

	///�Ǳ���ϱ���¼������
	virtual int ReqCombOrderInsert(CShfeFtdcInputCombOrderField *pInputCombOrder, int nRequestID) = 0;

	///������������
	virtual int ReqSubscribeTopic(CShfeFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///��������������
	virtual int ReqBulletin(CShfeFtdcBulletinField *pBulletin, int nRequestID) = 0;

	///��������Ϣ����
	virtual int ReqInformation(CShfeFtdcInformationField *pInformation, int nRequestID) = 0;

	///��Լ����״̬�ı�����
	virtual int ReqInstrumentStatusUpdate(CShfeFtdcInstrumentStatusField *pInstrumentStatus, int nRequestID) = 0;

	///ǿ���û��˳�����
	virtual int ReqForceUserExit(CShfeFtdcForceUserExitField *pForceUserExit, int nRequestID) = 0;

	///�û��Ựɾ������
	virtual int ReqForceUserLogout(CShfeFtdcForceUserExitField *pForceUserExit, int nRequestID) = 0;

	///����������ͬ��״̬�ı�����
	virtual int ReqExchangeDataSyncStatusUpdate(CShfeFtdcExchangeDataSyncStatusField *pExchangeDataSyncStatus, int nRequestID) = 0;

	///����������ͬ��״̬�ı�����
	virtual int ReqSGDataSyncStatusUpdate(CShfeFtdcSGDataSyncStatusField *pSGDataSyncStatus, int nRequestID) = 0;

	///��Ա�ʽ��ѯ����
	virtual int ReqQryPartAccount(CShfeFtdcQryPartAccountField *pQryPartAccount, int nRequestID) = 0;

	///������ѯ����
	virtual int ReqQryOrder(CShfeFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///���۲�ѯ����
	virtual int ReqQryQuote(CShfeFtdcQryQuoteField *pQryQuote, int nRequestID) = 0;

	///�ɽ�����ѯ����
	virtual int ReqQryTrade(CShfeFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///��Ա�ͻ���ѯ����
	virtual int ReqQryClient(CShfeFtdcQryClientField *pQryClient, int nRequestID) = 0;

	///��Ա�ֲֲ�ѯ����
	virtual int ReqQryPartPosition(CShfeFtdcQryPartPositionField *pQryPartPosition, int nRequestID) = 0;

	///�ͻ��ֲֲ�ѯ����
	virtual int ReqQryClientPosition(CShfeFtdcQryClientPositionField *pQryClientPosition, int nRequestID) = 0;

	///��Լ��ѯ����
	virtual int ReqQryInstrument(CShfeFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///��Լ����״̬��ѯ����
	virtual int ReqQryInstrumentStatus(CShfeFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID) = 0;

	///������״̬��ѯ����
	virtual int ReqQrySGDataSyncStatus(CShfeFtdcQrySGDataSyncStatusField *pQrySGDataSyncStatus, int nRequestID) = 0;

	///��ֵ��Ȳ�ѯ
	virtual int ReqQryHedgeVolume(CShfeFtdcQryHedgeVolumeField *pQryHedgeVolume, int nRequestID) = 0;

	///�����޶��ѯ����
	virtual int ReqQryCreditLimit(CShfeFtdcQryCreditLimitField *pQryCreditLimit, int nRequestID) = 0;

	///�Ǳ���ϱ�����ѯ����
	virtual int ReqQryCombOrder(CShfeFtdcQryCombOrderField *pQryCombOrder, int nRequestID) = 0;

	///ִ�������ѯ����
	virtual int ReqQryExecOrder(CShfeFtdcQryExecOrderField *pQryExecOrder, int nRequestID) = 0;

	///��ͨ�����ѯ����
	virtual int ReqQryMarketData(CShfeFtdcQryMarketDataField *pQryMarketData, int nRequestID) = 0;

	///�����������ѯ����
	virtual int ReqQryBulletin(CShfeFtdcQryBulletinField *pQryBulletin, int nRequestID) = 0;

	///�����ѯ����
	virtual int ReqQryTopic(CShfeFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///�û����߲�ѯ����
	virtual int ReqQryUserSession(CShfeFtdcQryUserSessionField *pQryUserSession, int nRequestID) = 0;

	///�û���ѯ����
	virtual int ReqQryUser(CShfeFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///��Ա��ѯ����
	virtual int ReqQryParticipant(CShfeFtdcQryParticipantField *pQryParticipant, int nRequestID) = 0;

	///��Լ��λ��ѯ
	virtual int ReqQryMBLMarketData(CShfeFtdcQryMBLMarketDataField *pQryMBLMarketData, int nRequestID) = 0;

	///��Ϣ��ѯ
	virtual int ReqQryInformation(CShfeFtdcQryInformationField *pQryInformation, int nRequestID) = 0;

	///�ͻ��ֲֲ�ѯ����
	virtual int ReqQryClientPositionV1(CShfeFtdcQryClientPositionV1Field *pQryClientPositionV1, int nRequestID) = 0;

	///���ʲ�ѯ����
	virtual int ReqQryExchangeRate(CShfeFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID) = 0;

	///CPU��ѯ
	virtual int ReqQryTopCpuInfoTopic(CShfeFtdcReqQryTopCpuInfoField *pReqQryTopCpuInfo, int nRequestID) = 0;

	///Mem��ѯ
	virtual int ReqQryTopMemInfoTopic(CShfeFtdcReqQryTopMemInfoField *pReqQryTopMemInfo, int nRequestID) = 0;

	///process��ѯ
	virtual int ReqQryTopProcessInfoTopic(CShfeFtdcReqQryTopProcessInfoField *pReqQryTopProcessInfo, int nRequestID) = 0;

	///filesystem��ѯ
	virtual int ReqQryFileSystemInfoTopic(CShfeFtdcReqQryFileSystemInfoField *pReqQryFileSystemInfo, int nRequestID) = 0;

	///network��ѯ
	virtual int ReqQryNetworkInfoTopic(CShfeFtdcReqQryNetworkInfoField *pReqQryNetworkInfo, int nRequestID) = 0;

	///����������Ϣ��ѯ
	virtual int ReqQryHostEnvTopic(CShfeFtdcReqQryHostEnvField *pReqQryHostEnv, int nRequestID) = 0;

	///�ͻ��˵�¼��ѯ
	virtual int ReqQryClientLoginTopic(CShfeFtdcReqQryClientLoginField *pReqQryClientLogin, int nRequestID) = 0;

	///��ü�ض�����Ϣ��ѯ
	virtual int ReqQryMonitorObjectTopic(CShfeFtdcReqQryMonitorObjectField *pReqQryMonitorObject, int nRequestID) = 0;

	///���ҵ����̺������Ķ�Ӧ��ϵ��ѯ
	virtual int ReqQryObjectRationalTopic(CShfeFtdcReqQryObjectRationalField *pReqQryObjectRational, int nRequestID) = 0;

	///��־�ļ����ݲ�ѯ
	virtual int ReqQrySyslogInfoTopic(CShfeFtdcReqQrySyslogInfoField *pReqQrySyslogInfo, int nRequestID) = 0;

	///������ݶ�������
	virtual int ReqQrySubscriberTopic(CShfeFtdcReqQrySubscriberField *pReqQrySubscriber, int nRequestID) = 0;

	///�����ϵ��ѯ
	virtual int ReqQryOidRelationTopic(CShfeFtdcReqQryOidRelationField *pReqQryOidRelation, int nRequestID) = 0;

	///�û���Ϣ��ѯ����
	virtual int ReqQryUserInfoTopic(CShfeFtdcReqQryUserInfoField *pReqQryUserInfo, int nRequestID) = 0;

	///�����û���Ϣ��ѯ����
	virtual int ReqQryOnlineUserInfoTopic(CShfeFtdcReqQryOnlineUserInfoField *pReqQryOnlineUserInfo, int nRequestID) = 0;

	///�澯�¼���ѯ����
	virtual int ReqQryWarningEventTopic(CShfeFtdcReqQryWarningEventField *pReqQryWarningEvent, int nRequestID) = 0;

	///CPUʹ���ʲ�ѯ����
	virtual int ReqQryCPUUsageTopic(CShfeFtdcReqQryCPUUsageField *pReqQryCPUUsage, int nRequestID) = 0;

	///�ڴ�ʹ���ʲ�ѯ����
	virtual int ReqQryMemoryUsageTopic(CShfeFtdcReqQryMemoryUsageField *pReqQryMemoryUsage, int nRequestID) = 0;

	///Ӳ��ʹ���ʲ�ѯ����
	virtual int ReqQryDiskUsageTopic(CShfeFtdcReqQryDiskUsageField *pReqQryDiskUsage, int nRequestID) = 0;

	///����״ָ̬���ѯ
	virtual int ReqQryObjectAttrTopic(CShfeFtdcReqQryObjectAttrField *pReqQryObjectAttr, int nRequestID) = 0;

	///KeyFile��ѯ����
	virtual int ReqQryKeyFileInfoTopic(CShfeFtdcReqQryKeyFileInfoField *pReqQryKeyFileInfo, int nRequestID) = 0;

	///HostMonitorCfg��ѯ����
	virtual int ReqQryHostMonitorCfgTopic(CShfeFtdcReqQryHostMonitorCfgField *pReqQryHostMonitorCfg, int nRequestID) = 0;

	///AppMonitorCfg��ѯ����
	virtual int ReqQryAppMonitorCfgTopic(CShfeFtdcReqQryAppMonitorCfgField *pReqQryAppMonitorCfg, int nRequestID) = 0;

	///HostConfig��ѯ����
	virtual int ReqQryHostConfigTopic(CShfeFtdcReqQryHostConfigField *pReqQryHostConfig, int nRequestID) = 0;

	///��ʷ����״ָ̬���ѯ
	virtual int ReqQryHistoryObjectAttrTopic(CShfeFtdcReqQryHistoryObjectAttrField *pReqQryHistoryObjectAttr, int nRequestID) = 0;

	///ǰ����Ӧ��Ϣ��ѯ
	virtual int ReqQryFrontInfoTopic(CShfeFtdcReqQryFrontInfoField *pReqQryFrontInfo, int nRequestID) = 0;

	///�û���¼
	virtual int ReqQrySysUserLoginTopic(CShfeFtdcReqQrySysUserLoginField *pReqQrySysUserLogin, int nRequestID) = 0;

	///�û��ǳ�
	virtual int ReqQrySysUserLogoutTopic(CShfeFtdcReqQrySysUserLogoutField *pReqQrySysUserLogout, int nRequestID) = 0;

	///�û��޸�����
	virtual int ReqQrySysUserPasswordUpdateTopic(CShfeFtdcReqQrySysUserPasswordUpdateField *pReqQrySysUserPasswordUpdate, int nRequestID) = 0;

	///ע���û�
	virtual int ReqQrySysUserRegisterTopic(CShfeFtdcReqQrySysUserRegisterField *pReqQrySysUserRegister, int nRequestID) = 0;

	///ɾ���û�
	virtual int ReqQrySysUserDeleteTopic(CShfeFtdcReqQrySysUserDeleteField *pReqQrySysUserDelete, int nRequestID) = 0;

	///������־��ѯ
	virtual int ReqQryTradeLogTopic(CShfeFtdcReqQryTradeLogField *pReqQryTradeLog, int nRequestID) = 0;

	///�澯�¼��޸�
	virtual int ReqQryWarningEventUpdateTopic(CShfeFtdcReqQryWarningEventUpdateField *pReqQryWarningEventUpdate, int nRequestID) = 0;

	///���׷�ֵ��ѯ
	virtual int ReqQryTradepeakTopic(CShfeFtdcReqQryTradepeakField *pReqQryTradepeak, int nRequestID) = 0;

	///
	virtual int ReqQryHistoryCpuInfoTopic(CShfeFtdcReqQryHistoryCpuInfoField *pReqQryHistoryCpuInfo, int nRequestID) = 0;

	///
	virtual int ReqQryHistoryMemInfoTopic(CShfeFtdcReqQryHistoryMemInfoField *pReqQryHistoryMemInfo, int nRequestID) = 0;

	///
	virtual int ReqQryHistoryNetworkInfoTopic(CShfeFtdcReqQryHistoryNetworkInfoField *pReqQryHistoryNetworkInfo, int nRequestID) = 0;

	///���ϵͳ�����û���ѯ
	virtual int ReqQryMonitorOnlineUser(CShfeFtdcReqQryMonitorOnlineUserField *pReqQryMonitorOnlineUser, int nRequestID) = 0;

	///��ʷ��ֵ��ѯ
	virtual int ReqQryHistoryTradePeakTopic(CShfeFtdcReqQryHistoryTradePeakField *pReqQryHistoryTradePeak, int nRequestID) = 0;

	///��־�¼���ѯ
	virtual int ReqQrySyslogEventTopic(CShfeFtdcReqQrySyslogEventField *pReqQrySyslogEvent, int nRequestID) = 0;

	///��־�¼���������
	virtual int ReqQrySyslogEventSubcriberTopic(CShfeFtdcReqQrySyslogEventSubcriberField *pReqQrySyslogEventSubcriber, int nRequestID) = 0;

	///�������л�֪ͨ
	virtual int ReqQryTradeDayChangeTopic(CShfeFtdcReqQryTradeDayChangeField *pReqQryTradeDayChange, int nRequestID) = 0;

	///tomcat��Ϣ��ѯ
	virtual int ReqQryTomcatInfoTopic(CShfeFtdcReqQryTomcatInfoField *pReqQryTomcatInfo, int nRequestID) = 0;

	///�������Ϣ��ѯ
	virtual int ReqQryVMInfoTopic(CShfeFtdcReqQryVMInfoField *pReqQryVMInfo, int nRequestID) = 0;

	///ϵͳ������Ϣ��ѯ
	virtual int ReqQryPropertyInfoTopic(CShfeFtdcReqQryPropertyInfoField *pReqQryPropertyInfo, int nRequestID) = 0;

	///ϵͳ�ڴ����Ϣ��ѯ
	virtual int ReqQryMemPoolInfoTopic(CShfeFtdcReqQryMemPoolInfoField *pReqQryMemPoolInfo, int nRequestID) = 0;

	///�ļ�������Ϣ��ѯ
	virtual int ReqQryFileContentInfoTopic(CShfeFtdcReqQryFileContentInfoField *pReqQryFileContentInfo, int nRequestID) = 0;

	///������Ϣ��ѯ
	virtual int ReqQryConnectionInfoTopic(CShfeFtdcReqQryConnectionInfoField *pReqQryConnectionInfo, int nRequestID) = 0;

	///��������Ϣ��ѯ
	virtual int ReqQryConnectorInfoTopic(CShfeFtdcReqQryConnectorInfoField *pReqQryConnectorInfo, int nRequestID) = 0;

	///���ݿ��ѯ
	virtual int ReqQryDBQueryTopic(CShfeFtdcReqQryDBQueryField *pReqQryDBQuery, int nRequestID) = 0;

	///�ļ���������
	virtual int ReqQryGetFileTopic(CShfeFtdcReqQryGetFileField *pReqQryGetFile, int nRequestID) = 0;

	///��־�¼��޸�����
	virtual int ReqQrySyslogEventUpdateTopic(CShfeFtdcReqQrySyslogEventUpdateField *pReqQrySyslogEventUpdate, int nRequestID) = 0;

	///�澯��ϸ��ѯ
	virtual int ReqQryWarningQueryTopic(CShfeFtdcReqQryWarningQueryField *pReqQryWarningQuery, int nRequestID) = 0;

	///��վ���ʲ�ѯ
	virtual int ReqQryWebVisitTopic(CShfeFtdcReqQryWebVisitField *pReqQryWebVisit, int nRequestID) = 0;

	///�澯������
	virtual int ReqQryWarningActiveChange(CShfeFtdcReqQryWarningActiveChangeField *pReqQryWarningActiveChange, int nRequestID) = 0;

	///ͨ�ò���
	virtual int ReqQryGeneralOperateTopic(CShfeFtdcReqQryGeneralOperateField *pReqQryGeneralOperate, int nRequestID) = 0;

	///�����豸���ӹ�ϵ����
	virtual int ReqQryNetDeviceLinkedTopic(CShfeFtdcReqQryNetDeviceLinkedField *pReqQryNetDeviceLinked, int nRequestID) = 0;

	///����ϵͳ��¼��Ϣ����
	virtual int ReqQryTradeUserLoginStatTopic(CShfeFtdcReqQryTradeUserLoginStatField *pReqQryTradeUserLoginStat, int nRequestID) = 0;

	///����ϵͳǰ�ñ�����Ӧ��Ϣ
	virtual int ReqQryTradeFrontOrderRttStatTopic(CShfeFtdcReqQryTradeFrontOrderRttStatField *pReqQryTradeFrontOrderRttStat, int nRequestID) = 0;

	///ϵͳ·����Ϣ
	virtual int ReqQryRouterInfoTopic(CShfeFtdcReqQryRouterInfoField *pReqQryRouterInfo, int nRequestID) = 0;

	///����I/O��Ϣ
	virtual int ReqQryDiskIOTopic(CShfeFtdcReqQryDiskIOField *pReqQryDiskIO, int nRequestID) = 0;

	///ϵͳ״̬��Ϣ
	virtual int ReqQryStatInfoTopic(CShfeFtdcReqQryStatInfoField *pReqQryStatInfo, int nRequestID) = 0;

	///����ϵͳǰ�ñ����ֲ�����
	virtual int ReqQryTradeOrderRttCutLineTopic(CShfeFtdcReqQryTradeOrderRttCutLineField *pReqQryTradeOrderRttCutLine, int nRequestID) = 0;

	///��Ա�ͻ���Ϣ
	virtual int ReqQryClientInfoTopic(CShfeFtdcReqQryClientInfoField *pReqQryClientInfo, int nRequestID) = 0;

	///�����¼�����
	virtual int ReqQryEventDescriptionTopic(CShfeFtdcReqQryEventDescriptionField *pReqQryEventDescription, int nRequestID) = 0;

	///����ǰ��ΨһID��Ϣ
	virtual int ReqQryFrontUniqueIDTopic(CShfeFtdcReqQryFrontUniqueIDField *pReqQryFrontUniqueID, int nRequestID) = 0;

	///��Ա��·��ַ�������
	virtual int ReqQryNetPartyLinkAddrChangeTopic(CShfeFtdcReqQryNetPartyLinkAddrChangeField *pReqQryNetPartyLinkAddrChange, int nRequestID) = 0;

	///������ɾ����Ա�б���Ϣ
	virtual int ReqQryNetDelPartyLinkInfoTopic(CShfeFtdcReqQryNetDelPartyLinkInfoField *pReqQryNetDelPartyLinkInfo, int nRequestID) = 0;

	///����������������
	virtual int ReqQryPerformanceTopTopic(CShfeFtdcReqQryPerformanceTopField *pReqQryPerformanceTop, int nRequestID) = 0;

	///��������ָ���ѯ
	virtual int ReqQryRealTimeNetObjectAttrTopic(CShfeFtdcReqQryRealTimeNetObjectAttrField *pReqQryRealTimeNetObjectAttr, int nRequestID) = 0;

	///����������ֲ�ѯ
	virtual int ReqQryNetAreaTopic(CShfeFtdcReqQryNetAreaField *pReqQryNetArea, int nRequestID) = 0;

	///����������ѯ
	virtual int ReqQryNetSubAreaTopic(CShfeFtdcReqQryNetSubAreaField *pReqQryNetSubArea, int nRequestID) = 0;

	///��������IP��ѯ
	virtual int ReqQryNetSubAreaIPTopic(CShfeFtdcReqQryNetSubAreaIPField *pReqQryNetSubAreaIP, int nRequestID) = 0;

	///�����豸̽������
	virtual int ReqQryNetDeviceDetectTopic(CShfeFtdcReqQryNetDeviceDetectField *pReqQryNetDeviceDetect, int nRequestID) = 0;

	///�����豸��ѯ����
	virtual int ReqQryNetDeviceRequestTopic(CShfeFtdcReqQryNetDeviceRequestField *pReqQryNetDeviceRequest, int nRequestID) = 0;

	///��¥��ѯ
	virtual int ReqQryNetBuildingTopic(CShfeFtdcReqQryNetBuildingField *pReqQryNetBuilding, int nRequestID) = 0;

	///������ѯ
	virtual int ReqQryNetRoomTopic(CShfeFtdcReqQryNetRoomField *pReqQryNetRoom, int nRequestID) = 0;

	///�����ѯ
	virtual int ReqQryNetCabinetsTopic(CShfeFtdcReqQryNetCabinetsField *pReqQryNetCabinets, int nRequestID) = 0;

	///OID
	virtual int ReqQryNetOIDTopic(CShfeFtdcReqQryNetOIDField *pReqQryNetOID, int nRequestID) = 0;

	///ʱ�����
	virtual int ReqQryNetTimePolicyTopic(CShfeFtdcReqQryNetTimePolicyField *pReqQryNetTimePolicy, int nRequestID) = 0;

	///�ɼ������ѯ
	virtual int ReqQryNetGatherTaskTopic(CShfeFtdcReqQryNetGatherTaskField *pReqQryNetGatherTask, int nRequestID) = 0;

	///�豸�������
	virtual int ReqQryNetDeviceChgTopic(CShfeFtdcReqQryNetDeviceChgField *pReqQryNetDeviceChg, int nRequestID) = 0;

	///�����豸�ͺ�����
	virtual int ReqQryNetDeviceTypeTopic(CShfeFtdcReqQryNetDeviceTypeField *pReqQryNetDeviceType, int nRequestID) = 0;

	///�����豸�������
	virtual int ReqQryNetDeviceCategoryTopic(CShfeFtdcReqQryNetDeviceCategoryField *pReqQryNetDeviceCategory, int nRequestID) = 0;

	///�豸��������
	virtual int ReqQryNetManufactoryTopic(CShfeFtdcReqQryNetManufactoryField *pReqQryNetManufactory, int nRequestID) = 0;

	///�豸��ͬ������
	virtual int ReqQryNetCommunityTopic(CShfeFtdcReqQryNetCommunityField *pReqQryNetCommunity, int nRequestID) = 0;

	///�˿���������
	virtual int ReqQryNetPortTypeTopic(CShfeFtdcReqQryNetPortTypeField *pReqQryNetPortType, int nRequestID) = 0;

	///��Ա����ص�����
	virtual int ReqQryNetPartAccessSpotTopic(CShfeFtdcReqQryNetPartAccessSpotField *pReqQryNetPartAccessSpot, int nRequestID) = 0;

	///�˿�����
	virtual int ReqQryNetInterfaceTopic(CShfeFtdcReqQryNetInterfaceField *pReqQryNetInterface, int nRequestID) = 0;

	///GeneralOID����
	virtual int ReqQryNetGeneralOIDTopic(CShfeFtdcReqQryNetGeneralOIDField *pReqQryNetGeneralOID, int nRequestID) = 0;

	///��ض������
	virtual int ReqQryNetMonitorTypeTopic(CShfeFtdcReqQryNetMonitorTypeField *pReqQryNetMonitorType, int nRequestID) = 0;

	///ָ��ͳ��
	virtual int ReqQryNetMonitorAttrScopeTopic(CShfeFtdcReqQryNetMonitorAttrScopeField *pReqQryNetMonitorAttrScope, int nRequestID) = 0;

	///���ָ���
	virtual int ReqQryNetMonitorAttrTypeTopic(CShfeFtdcReqQryNetMonitorAttrTypeField *pReqQryNetMonitorAttrType, int nRequestID) = 0;

	///��ض���ָ���
	virtual int ReqQryNetMonitorObjectAttrTopic(CShfeFtdcReqQryNetMonitorObjectAttrField *pReqQryNetMonitorObjectAttr, int nRequestID) = 0;

	///ְ����
	virtual int ReqQryNetFuncAreaTopic(CShfeFtdcReqQryNetFuncAreaField *pReqQryNetFuncArea, int nRequestID) = 0;

	///���ָ���
	virtual int ReqQryNetMonitorCommandTypeTopic(CShfeFtdcReqQryNetMonitorCommandTypeField *pReqQryNetMonitorCommandType, int nRequestID) = 0;

	///�������
	virtual int ReqQryNetMonitorActionGroupTopic(CShfeFtdcReqQryNetMonitorActionGroupField *pReqQryNetMonitorActionGroup, int nRequestID) = 0;

	///�豸�������
	virtual int ReqQryNetMonitorDeviceGroupTopic(CShfeFtdcReqQryNetMonitorDeviceGroupField *pReqQryNetMonitorDeviceGroup, int nRequestID) = 0;

	///������Ϣ��
	virtual int ReqQryNetMonitorTaskInfoTopic(CShfeFtdcReqQryNetMonitorTaskInfoField *pReqQryNetMonitorTaskInfo, int nRequestID) = 0;

	///��������
	virtual int ReqQryNetMonitorTaskResultTopic(CShfeFtdcReqQryNetMonitorTaskResultField *pReqQryNetMonitorTaskResult, int nRequestID) = 0;

	///�������
	virtual int ReqQryNetMonitorTaskObjectSetTopic(CShfeFtdcReqQryNetMonitorTaskObjectSetField *pReqQryNetMonitorTaskObjectSet, int nRequestID) = 0;

	///��Ա��·��Ϣ��
	virtual int ReqQryNetPartyLinkInfoTopic(CShfeFtdcReqQryNetPartyLinkInfoField *pReqQryNetPartyLinkInfo, int nRequestID) = 0;

	///��ض���ָ����ձ�
	virtual int ReqQryNetMonitorActionAttrTopic(CShfeFtdcReqQryNetMonitorActionAttrField *pReqQryNetMonitorActionAttr, int nRequestID) = 0;

	///ģ��
	virtual int ReqQryNetModuleTopic(CShfeFtdcReqQryNetModuleField *pReqQryNetModule, int nRequestID) = 0;

	///�澯���ʽ��Ϣ��
	virtual int ReqQryNetEventExprTopic(CShfeFtdcReqQryNetEventExprField *pReqQryNetEventExpr, int nRequestID) = 0;

	///�¼�����
	virtual int ReqQryNetEventTypeTopic(CShfeFtdcReqQryNetEventTypeField *pReqQryNetEventType, int nRequestID) = 0;

	///�¼�������
	virtual int ReqQryNetSubEventTypeTopic(CShfeFtdcReqQryNetSubEventTypeField *pReqQryNetSubEventType, int nRequestID) = 0;

	///�¼�����
	virtual int ReqQryNetEventLevelTopic(CShfeFtdcReqQryNetEventLevelField *pReqQryNetEventLevel, int nRequestID) = 0;

	///������״̬��
	virtual int ReqQryNetMonitorTaskStatusResultTopic(CShfeFtdcReqQryNetMonitorTaskStatusResultField *pReqQryNetMonitorTaskStatusResult, int nRequestID) = 0;

	///��½���÷��������
	virtual int ReqConfigLoginTopic(CShfeFtdcReqConfigLoginField *pReqConfigLogin, int nRequestID) = 0;

	///��֪���������˳�
	virtual int ReqSysServerExitTopic(CShfeFtdcReqSysServerExitField *pReqSysServerExit, int nRequestID) = 0;

	///�豸���ñ�
	virtual int ReqQryNetCfgFileTopic(CShfeFtdcReqQryNetCfgFileField *pReqQryNetCfgFile, int nRequestID) = 0;

	///���������������
	virtual int ReqQryNetMonitorDeviceTaskTopic(CShfeFtdcReqQryNetMonitorDeviceTaskField *pReqQryNetMonitorDeviceTask, int nRequestID) = 0;

	///����ָ��ָ�꼯��
	virtual int ReqQryNetMonitorTaskInstAttrsTopic(CShfeFtdcReqQryNetMonitorTaskInstAttrsField *pReqQryNetMonitorTaskInstAttrs, int nRequestID) = 0;

	///�ļ�ͨ�ò���
	virtual int ReqQryFileGeneralOperTopic(CShfeFtdcReqQryFileGeneralOperField *pReqQryFileGeneralOper, int nRequestID) = 0;

	///���߱�
	virtual int ReqQryNetBaseLineTopic(CShfeFtdcReqQryNetBaseLineField *pReqQryNetBaseLine, int nRequestID) = 0;

	///���������
	virtual int ReqQryNetBaseLineTaskTopic(CShfeFtdcReqQryNetBaseLineTaskField *pReqQryNetBaseLineTask, int nRequestID) = 0;

	///���߽����
	virtual int ReqQryNetBaseLineResultTopic(CShfeFtdcReqQryNetBaseLineResultField *pReqQryNetBaseLineResult, int nRequestID) = 0;

	///��Ա��·״̬��Ϣ��
	virtual int ReqQryNetPartyLinkStatusInfoTopic(CShfeFtdcReqQryNetPartyLinkStatusInfoField *pReqQryNetPartyLinkStatusInfo, int nRequestID) = 0;

	///��ԱSDH��·��ϸ��
	virtual int ReqQryNetMemberSDHLineInfoTopic(CShfeFtdcReqQryNetMemberSDHLineInfoField *pReqQryNetMemberSDHLineInfo, int nRequestID) = 0;

	///DDN��·��Ϣ��
	virtual int ReqQryNetDDNLinkInfoTopic(CShfeFtdcReqQryNetDDNLinkInfoField *pReqQryNetDDNLinkInfo, int nRequestID) = 0;

	///�ǻ�Ա��·ʹ����Ϣ
	virtual int ReqQryNetPseudMemberLinkInfoTopic(CShfeFtdcReqQryNetPseudMemberLinkInfoField *pReqQryNetPseudMemberLinkInfo, int nRequestID) = 0;

	///Զ���豸��Ϣ
	virtual int ReqQryOuterDeviceInfTopic(CShfeFtdcReqQryOuterDeviceInfField *pReqQryOuterDeviceInf, int nRequestID) = 0;

	///����ping���
	virtual int ReqQryNetLocalPingResultInfoTopic(CShfeFtdcReqQryNetLocalPingResultInfoField *pReqQryNetLocalPingResultInfo, int nRequestID) = 0;

	///Զ��ping���
	virtual int ReqQryNetRomotePingResultInfoTopic(CShfeFtdcReqQryNetRomotePingResultInfoField *pReqQryNetRomotePingResultInfo, int nRequestID) = 0;

	///ϵͳ�ڲ�������ϵ
	virtual int ReqQrySysInternalTopologyTopic(CShfeFtdcReqQrySysInternalTopologyField *pReqQrySysInternalTopology, int nRequestID) = 0;

	///�����Ա��·���ñ�
	virtual int ReqQryMemberLinkCostTopic(CShfeFtdcReqQryMemberLinkCostField *pReqQryMemberLinkCost, int nRequestID) = 0;

	///�����Ա��·�����
	virtual int ReqQryNetPartylinkMonthlyRentTopic(CShfeFtdcReqQryNetPartylinkMonthlyRentField *pReqQryNetPartylinkMonthlyRent, int nRequestID) = 0;

	///����ǻ�Ա��·����Ϣ
	virtual int ReqQryNetNonPartyLinkInfoTopic(CShfeFtdcReqQryNetNonPartyLinkInfoField *pReqQryNetNonPartyLinkInfo, int nRequestID) = 0;

	///����������Ϣ
	virtual int ReqQryMonConfigInfo(CShfeFtdcReqQryMonConfigInfoField *pReqQryMonConfigInfo, int nRequestID) = 0;

	///������������
	virtual int ReqMonServiceConnect(CShfeFtdcReqMonServiceConnectField *pReqMonServiceConnect, int nRequestID) = 0;

	///����ĵ�ǰ״̬��ѯ
	virtual int ReqQryMonServiceStatus(CShfeFtdcReqQryMonServiceStatusField *pReqQryMonServiceStatus, int nRequestID) = 0;

	///̽���������ò�ѯ����
	virtual int ReqQryMonProbeTask(CShfeFtdcReqQryMonProbeTaskField *pReqQryMonProbeTask, int nRequestID) = 0;

	///���ϵͳָ���ѯ����
	virtual int ReqQryMonObjectAttr(CShfeFtdcReqQryMonObjectAttrField *pReqQryMonObjectAttr, int nRequestID) = 0;

	///���ϵͳSyslog�¼���ѯ����
	virtual int ReqQryMonSyslogEvent(CShfeFtdcReqQryMonSyslogEventField *pReqQryMonSyslogEvent, int nRequestID) = 0;

	///�ļ���ȡƫ������ѯ����
	virtual int ReqQryMonFileOffset(CShfeFtdcReqQryMonFileOffsetField *pReqQryMonFileOffset, int nRequestID) = 0;

	///�ļ����ݲ�ѯ����
	virtual int ReqQryMonFileContent(CShfeFtdcReqQryMonFileContentField *pReqQryMonFileContent, int nRequestID) = 0;

	///��������������Ϣ��ѯ����
	virtual int ReqQryMonHostBasicEnv(CShfeFtdcReqQryMonHostBasicEnvField *pReqQryMonHostBasicEnv, int nRequestID) = 0;

	///��������������Ϣ��ѯ
	virtual int ReqQryMonHostNetworkEnv(CShfeFtdcReqQryMonHostNetworkEnvField *pReqQryMonHostNetworkEnv, int nRequestID) = 0;

	///�����ļ�ϵͳ��Ϣ��ѯ
	virtual int ReqQryMonHostFileSysEnv(CShfeFtdcReqQryMonHostFileSysEnvField *pReqQryMonHostFileSysEnv, int nRequestID) = 0;

	///��������������Ϣ��ѯ
	virtual int ReqQryMonHostSwapEnv(CShfeFtdcReqQryMonHostSwapEnvField *pReqQryMonHostSwapEnv, int nRequestID) = 0;

	///������CPU��Ϣָ����Ϣ����
	virtual int ReqQryMonHostCPUAttr(CShfeFtdcReqQryMonHostCPUAttrField *pReqQryMonHostCPUAttr, int nRequestID) = 0;

	///������Memoryʹ����Ϣ����
	virtual int ReqQryMonHostMemAttr(CShfeFtdcReqQryMonHostMemAttrField *pReqQryMonHostMemAttr, int nRequestID) = 0;

	///������FileSystemʹ����Ϣ����
	virtual int ReqQryMonHostFileSystemAttr(CShfeFtdcReqQryMonHostFileSystemAttrField *pReqQryMonHostFileSystemAttr, int nRequestID) = 0;

	///�������û���Ϣ����
	virtual int ReqQryMonHostUserInfo(CShfeFtdcReqQryMonHostUserInfoField *pReqQryMonHostUserInfo, int nRequestID) = 0;

	///�����������û���Ϣ����
	virtual int ReqQryMonHostOnlineUserInfo(CShfeFtdcReqQryMonHostOnlineUserInfoField *pReqQryMonHostOnlineUserInfo, int nRequestID) = 0;

	///������networkʹ����Ϣ����
	virtual int ReqQryMonHostNetworkAttr(CShfeFtdcReqQryMonHostNetworkAttrField *pReqQryMonHostNetworkAttr, int nRequestID) = 0;

	///������ϵͳ״̬��Ϣ����
	virtual int ReqQryMonHostStatInfo(CShfeFtdcReqQryMonHostStatInfoField *pReqQryMonHostStatInfo, int nRequestID) = 0;

	///�����Ĵ���IO��Ϣ����
	virtual int ReqQryMonHostDiskIOAttr(CShfeFtdcReqQryMonHostDiskIOAttrField *pReqQryMonHostDiskIOAttr, int nRequestID) = 0;

	///������·����Ϣ����
	virtual int ReqQryMonHostRouterInfo(CShfeFtdcReqQryMonHostRouterInfoField *pReqQryMonHostRouterInfo, int nRequestID) = 0;

	///�����Ľ�����Ϣ����
	virtual int ReqQryMonHostProcessInfo(CShfeFtdcReqQryMonHostProcessInfoField *pReqQryMonHostProcessInfo, int nRequestID) = 0;

	///�ͻ�����ʱSP��ѯ����
	virtual int ReqQryMonSPQuery(CShfeFtdcReqQryMonSPQueryField *pReqQryMonSPQuery, int nRequestID) = 0;

	///����汾��Ϣ����
	virtual int ReqServiceVersion(CShfeFtdcReqServiceVersionField *pReqServiceVersion, int nRequestID) = 0;

	///����Ӧ�ó�������
	virtual int ReqServiceProgram(CShfeFtdcReqServiceProgramField *pReqServiceProgram, int nRequestID) = 0;

	///���������ȡ״̬
	virtual int ReqUpdateState(CShfeFtdcReqUpdateStateField *pReqUpdateState, int nRequestID) = 0;

	///��������
	virtual int ReqSubscribe(CShfeFtdcReqSubscribeField *pReqSubscribe, int nRequestID) = 0;

	///ȡ����������
	virtual int ReqCancelSubscribe(CShfeFtdcReqSubscribeField *pReqSubscribe, int nRequestID) = 0;

	///����֪ͨĿ������ļ��ѷ��ͳɹ�
	virtual int ReqFileSendSuccess(CShfeFtdcReqFileSendSuccessField *pReqFileSendSuccess, int nRequestID) = 0;

	///tomcat��Ϣ��ѯ
	virtual int ReqQryMonTomcatInfo(CShfeFtdcReqQryMonTomcatInfoField *pReqQryMonTomcatInfo, int nRequestID) = 0;

	///�������Ϣ��ѯ
	virtual int ReqQryMonVMInfo(CShfeFtdcReqQryMonVMInfoField *pReqQryMonVMInfo, int nRequestID) = 0;

	///ϵͳ������Ϣ��ѯ
	virtual int ReqQryMonPropertyInfo(CShfeFtdcReqQryMonPropertyInfoField *pReqQryMonPropertyInfo, int nRequestID) = 0;

	///ϵͳ�ڴ����Ϣ��ѯ
	virtual int ReqQryMonMemPoolInfo(CShfeFtdcReqQryMonMemPoolInfoField *pReqQryMonMemPoolInfo, int nRequestID) = 0;

	///������Ϣ��ѯ
	virtual int ReqQryMonConnectionInfo(CShfeFtdcReqQryMonConnectionInfoField *pReqQryMonConnectionInfo, int nRequestID) = 0;

	///��Ч������ѯ
	virtual int ReqQryInvalidateOrderTopic(CShfeFtdcReqQryInvalidateOrderField *pReqQryInvalidateOrder, int nRequestID) = 0;

	///����״̬��ѯ
	virtual int ReqQryOrderStatusTopic(CShfeFtdcReqQryOrderStatusField *pReqQryOrderStatus, int nRequestID) = 0;

	///�����ɽ���ѯ
	virtual int ReqQryBargainOrderTopic(CShfeFtdcReqQryBargainOrderField *pReqQryBargainOrder, int nRequestID) = 0;

	///��Լ�������Բ�ѯ
	virtual int ReqQryInstPropertyTopic(CShfeFtdcReqQryInstPropertyField *pReqQryInstProperty, int nRequestID) = 0;

	///��Լ��֤���ʲ�ѯ
	virtual int ReqQryMarginRateTopic(CShfeFtdcReqQryMarginRateField *pReqQryMarginRate, int nRequestID) = 0;

	///��Լ�ǵ�ͣ���ѯ
	virtual int ReqQryPriceLimitTopic(CShfeFtdcReqQryPriceLimitField *pReqQryPriceLimit, int nRequestID) = 0;

	///��Ա�޲ֲ�ѯ
	virtual int ReqQryPartPosiLimitTopic(CShfeFtdcReqQryPartPosiLimitField *pReqQryPartPosiLimit, int nRequestID) = 0;

	///�ͻ��޲ֲ�ѯ
	virtual int ReqQryClientPosiLimitTopic(CShfeFtdcReqQryClientPosiLimitField *pReqQryClientPosiLimit, int nRequestID) = 0;

	///����ͻ��޲ֲ�ѯ
	virtual int ReqQrySpecialPosiLimitTopic(CShfeFtdcReqQrySpecialPosiLimitField *pReqQrySpecialPosiLimit, int nRequestID) = 0;

	///�˻�������ѯ
	virtual int ReqQryTransactionChgTopic(CShfeFtdcReqQryTransactionChgField *pReqQryTransactionChg, int nRequestID) = 0;

	///�ͻ����ݱ䶯��ѯ
	virtual int ReqQryClientChgTopic(CShfeFtdcReqQryClientChgField *pReqQryClientChg, int nRequestID) = 0;

	///��Ա�ͻ����ձ䶯��ѯ
	virtual int ReqQryPartClientChgTopic(CShfeFtdcReqQryPartClientChgField *pReqQryPartClientChg, int nRequestID) = 0;

	///�޲����ݱ䶯��ѯ
	virtual int ReqQryPosiLimitChgTopic(CShfeFtdcReqQryPosiLimitChgField *pReqQryPosiLimitChg, int nRequestID) = 0;

	///��ֵ��ȱ䶯��ѯ
	virtual int ReqQryHedgeDetailChgTopic(CShfeFtdcReqQryHedgeDetailChgField *pReqQryHedgeDetailChg, int nRequestID) = 0;

	///��Ա�䶯��ѯ
	virtual int ReqQryParticipantChgTopic(CShfeFtdcReqQryParticipantChgField *pReqQryParticipantChg, int nRequestID) = 0;

	///��֤���ʱ䶯��ѯ
	virtual int ReqQryMarginRateChgTopic(CShfeFtdcReqQryMarginRateChgField *pReqQryMarginRateChg, int nRequestID) = 0;

	///IP��ַ�䶯��ѯ
	virtual int ReqQryUserIpChgTopic(CShfeFtdcReqQryUserIpChgField *pReqQryUserIpChg, int nRequestID) = 0;

	///�޲����ݱ䶯��ѯ
	virtual int ReqQryClientPosiLimitChgTopic(CShfeFtdcReqQryClientPosiLimitChgField *pReqQryClientPosiLimitChg, int nRequestID) = 0;

	///�޲����ݱ䶯��ѯ
	virtual int ReqQrySpecPosiLimitChgTopic(CShfeFtdcReqQrySpecPosiLimitChgField *pReqQrySpecPosiLimitChg, int nRequestID) = 0;

	///����ϵͳǰ��ͳ�Ʋ�ѯ
	virtual int ReqQryFrontStatTopic(CShfeFtdcReqQryFrontStatField *pReqQryFrontStat, int nRequestID) = 0;

	///����ƽ̨��ʼ����Ϣ��ѯ
	virtual int ReqQryParticipantInitTopic(CShfeFtdcReqQryParticipantInitField *pReqQryParticipantInit, int nRequestID) = 0;

	///����ƽ̨��ʼ����Ϣ��ѯ
	virtual int ReqQryUserInitTopic(CShfeFtdcReqQryUserInitField *pReqQryUserInit, int nRequestID) = 0;

	///����Լ״̬�л�����
	virtual int ReqQryInstrumentStatusTopic(CShfeFtdcReqQryInstrumentStatusField *pReqQryInstrumentStatus, int nRequestID) = 0;

	///�����Լ���׽���Ϣ
	virtual int ReqQryCurrTradingSegmentAttrTopic(CShfeFtdcReqQryCurrTradingSegmentAttrField *pReqQryCurrTradingSegmentAttr, int nRequestID) = 0;

	///����ϵͳ��¼��Ϣ��ѯ
	virtual int ReqQryTradeUserLoginInfoTopic(CShfeFtdcReqQryTradeUserLoginInfoField *pReqQryTradeUserLoginInfo, int nRequestID) = 0;

	///��Ա���ײ�ѯ
	virtual int ReqQryPartTradeTopic(CShfeFtdcReqQryPartTradeField *pReqQryPartTrade, int nRequestID) = 0;

	///��Աϯλ����״̬
	virtual int ReqQryParticTradeOrderStatesTopic(CShfeFtdcReqQryParticTradeOrderStatesField *pReqQryParticTradeOrderStates, int nRequestID) = 0;

	///��ü�ض�����Ϣ��ѯ
	virtual int ReqQryMonitor2ObjectTopic(CShfeFtdcReqQryMonitor2ObjectField *pReqQryMonitor2Object, int nRequestID) = 0;

	///����������Ϣ��ѯ
	virtual int ReqQryMonHostCommonEnvTopic(CShfeFtdcReqQryMonHostCommonEnvField *pReqQryMonHostCommonEnv, int nRequestID) = 0;

	///��ȡҵ����̺�������ϵ
	virtual int ReqQryMonOidHostRationalTopic(CShfeFtdcReqQryMonOidHostRationalField *pReqQryMonOidHostRational, int nRequestID) = 0;

	///�����ϵ��ѯ
	virtual int ReqQryMonOidRelationTopic(CShfeFtdcReqQryMonOidRelationField *pReqQryMonOidRelation, int nRequestID) = 0;
protected:
	~CShfeFtdcUserApi(){};
};

#endif
