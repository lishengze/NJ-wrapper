/////////////////////////////////////////////////////////////////////////
///@system ��һ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file FtdcUserApiImpl.h
///@brief �����˿ͻ��˽ӿ�ʵ��
///@history 
///20060106	�Ժ�� �������ļ�
///20061012	�Ժ�� ���Ӷ�SSL���У���֧��
///20070216	�½�   ���tradeapi���ص�Ԥ����ֵ��
///20070806	�Ժ�� ���ӷ�����
///                SubscribeUserTopic ���Ľ���Ա����
///                SetHeartbeatTimeout ����������ʱʱ�䡣
///                OpenRequestLog ��������־�ļ�
///                OpenResponseLog ��Ӧ����־�ļ�
///20070924 �Ժ�� �����̳й�ϵ����֧��nameserver
// 20080727 �Ժ�� NT-0048:��չCSessionFactory::CreateSession���������ڴ���
//                 �Ựʱ���ֲ�ͬ������
// 20090504 �Ժ�� NT-0072:����UserAPI�����̲߳���ȫ����
// 20090505 �Ժ�� NT-0073:����UserAPI�������������������
//                         �����Ի����������������
//                         �汾��Ϣ������������ʱ���ʾ��С�汾��
///20110509 ����   NT-0131 UserAPI�������ƣ����û���Ƶ����¼��������
///20120730 ��Ң��	NT-0170 �����غ���־��������
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCUSERAPIIMPLBASE_H)
#define _FTDCUSERAPIIMPLBASE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Flow.h"
#include "Mutex.h"
#include "FtdcUserApiMacro.h"
#include FTDCUSERAPI_H
#include "NsSessionFactory.h"
#include "SelectReactor.h"
#include "FTDCSubscriber.h"
#include "FtdPackageDesc.h"
#include "FTDCSession.h"
#include "Storage.h"

// ��С��¼��������룩
#define MINLOGINTIMESPAN 1000

///tradeapi���ص�Ԥ����ֵ
#define MAXQUERYUNFINISHED	1
#define MAXQUERYPERSECOND		1

#define MAXDIALOGUNFINISHED	1
#define MAXDIALOGPERSECOND	1

class CFtdcUserApiImplBase;
class CFtdcUserSubscriber : public CFTDCSubscriber
{
public:
	CFtdcUserSubscriber(CFtdcUserApiImplBase *pUserApiImplBase,
		CFlow *pFlow, WORD wSequenceSeries);
	virtual ~CFtdcUserSubscriber();
	virtual void SetCommPhaseNo(WORD wCommPhaseNo);
	virtual WORD GetSequenceSeries();
	virtual DWORD GetReceivedCount();
	virtual void HandleMessage(CFTDCPackage *pMessage);
	TE_RESUME_TYPE GetResumeType();
	WORD GetCommPhaseNo();
	void SetResumeType(TE_RESUME_TYPE nResumeType);
	void MoveTo(int nOffset);

	void CleanControl(void);

	int AddOneToFlow(void);
	void DequeueRequest(CFTDCPackage *pResponse);
	void SetTradeMaxCommFlux(int nMaxCommFlux);
	void SetTradeMaxOnWayCommFlux(int nMaxOnWayCommFlux);
	void SetQueryMaxCommFlux(int nMaxCommFlux);
	void SetQueryMaxOnWayCommFlux(int nMaxOnWayCommFlux);

private:
	CFlow *m_pFlow;
	WORD m_wSequenceSeries;
	DWORD m_nCount;					/**< �Ѿ����ڵİ����� */
	WORD m_wCommPhaseNo;			/**< ͨѶ�׶α��*/
	CFtdcUserApiImplBase *m_pUserApiImplBase;
	TE_RESUME_TYPE m_nResumeType;

	// flow control by zhangjie
	unsigned int m_nMaxUnfinished;
	unsigned int m_nMaxPerSecond;
	unsigned int m_nTimeoutForQueryFlow;

	list<time_t> m_nUnfinished;
	unsigned int m_nCntPerSecond;
	time_t m_lastTime;
	CMutex m_mutexFlowControl;
};
/////////////////////////////////////////////////////////////////////////

class CMarketDataFlowManager
{
public:
	CMarketDataFlowManager(const char *pszFlowPath);
	~CMarketDataFlowManager();
	CFlow *GetFlow(DWORD nTopicID);
	bool RegisterTopic(DWORD nTopicID);
private:
	typedef CHashMap<DWORD, CFlow *, HashInt> CFlowMap;
	CFlowMap m_mapFlow;
	string m_strFlowPath;
};

struct CTopicDepthMarketDataField : public CFTDDepthMarketDataField
{
	WORD SequenceSeries;
};

class CTopicDepthMarketDataStorage :public CStorage<CTopicDepthMarketDataField>
{
public:
	DEFINE_INDEX_FUNC_2(0, WORD, SequenceSeries, const char *, InstrumentID);
	CTopicDepthMarketDataStorage()
	{
		CREATE_INDEX_2(SequenceSeries, InstrumentID);
	}
};

class CFtdcUserResumeInfo
{
public:
	CFtdcUserResumeInfo(const char *pszPath, const char *pszUserApiType,
		const char *pszFileName);
	~CFtdcUserResumeInfo();
	const CDateType &GetTradingDay();
	const CDataCenterIDType &GetDataCenterID();
	bool Update(const CDateType &TradingDay, CDataCenterIDType &DataCenterID);
public:
	bool SerializeLoad();
	bool SerializeStore();
private:
	void InitResumeInfo();
private:
	enum{
		FILE_VERSION = 1
	};
private:
	string m_strFullFileName;
	int m_nFileVersion;
	CDateType m_TradingDay;
	CDataCenterIDType m_DataCenterID;
};

class CFtdcUserApiImplBase : public FTDCUSERAPI, public CNsSessionFactory, public CFTDCSessionCallback
{
public:
	CFtdcUserApiImplBase(const char *pszFlowPath, const char *pszUserApiType,
		CSelectReactor *pReactor);
	
	~CFtdcUserApiImplBase();

	virtual void Init();
	
	virtual int Join();
	
	virtual void Release();

	virtual const char *GetTradingDay();
	
	virtual void RegisterNameServer(char *pszFrontAddress);
	
	virtual void RegisterFront(char *pszFrontAddress);
	
	virtual void RegisterSpi(FTDCUSERSPI *pSpi);
	
	virtual int RegisterCertificateFile(const char *pszCertFileName, const char *pszKeyFileName, 
		const char *pszCaFileName, const char *pszKeyFilePassword);
		
	virtual void SubscribeMarketDataTopic(int nTopicID, TE_RESUME_TYPE nResume);

	virtual void SubscribePrivateTopic(TE_RESUME_TYPE nResumeType);
	
	virtual void SubscribePublicTopic(TE_RESUME_TYPE nResumeType);

	virtual void SubscribeUserTopic(TE_RESUME_TYPE nResumeType);
	
	virtual void SetHeartbeatTimeout(unsigned int timeout);

	virtual int OpenRequestLog(const char *pszReqLogFileName);

	virtual int OpenResponseLog(const char *pszRspLogFileName);
	
	virtual int ReqUserLogin(FTDCREQUSERLOGINFIELD *pReqUserLoginField, int nRequestID);
	
	virtual void HandleResponse(CFTDCPackage *pMessage, WORD wSequenceSeries) = 0;

	virtual int HandlePackage(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);
protected:
	virtual CSession *CreateSession(CChannel *pChannel, DWORD);
	virtual void OnSessionConnected(CSession *pSession);
	virtual void OnSessionDisconnected(CSession *pSession, int nReason);
	virtual void OnSessionWarning(CSession *pSession, int nReason, int nParam);	

	int RequestToDialogFlow();
	int RequestToQueryFlow();
	int RequestDirectly();
	
	void OnIntlRtnDepthMarketData(CFTDCPackage *pMessage, WORD wSequenceSeries);
	void OnIntlRtnDissemination(CFTDCPackage *pMessage, WORD wSequenceSeries);

	void OnRtnDepthMarketData(CFTDDepthMarketDataField *pMarketData, WORD wSequenceSeries);

private:
	void CreateDialogFlow();
	void RemoveDialogFlow();
	void CreateQueryFlow();
	void RemoveQueryFlow();
	void CreateSubscriber(int nTopicID, CFlow *pFlow, TE_RESUME_TYPE nResumeType);

protected:
	FTDCUSERSPI *m_pSpi;
	CFTDCPackage m_reqPackage;
	CMutex m_mutexAction;
	FILE *m_fpRequstDump;
	FILE *m_fpResponseDump;
	typedef map<WORD, CFtdcUserSubscriber *> CUserSubscriberMap;
	CUserSubscriberMap m_mapSubscriber;

private:
	CFlow *m_pDialogReqFlow;
	CFlow *m_pQueryReqFlow;
	CFlow *m_pPrivateFlow;
	CFlow *m_pUserFlow;
	CFlow *m_pPublicFlow;

	CMarketDataFlowManager *m_pMarketDataFlowManager;
	DWORD m_nSessionID;
	string m_strFlowPath;
	DWORD m_dwHeartbeatTimeout;

	CTopicDepthMarketDataStorage m_storageTopicDepthMarketData;
	CFtdcUserResumeInfo m_ResumeInfo;
	bool m_bManagedResume;
	string m_strUserApiType;

	// ���һ�ε�¼ʱ��
	DWORD m_LastLoginTime;
};

#endif
