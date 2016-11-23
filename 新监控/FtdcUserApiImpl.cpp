/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file FtdcUserApiImpl.cpp
///@brief 实现了客户端接口
///@history 
///20060106	赵鸿昊		创建该文件
// 20110624 江鹏        NT-0139 加快响应时间
// 20120726 江鹏        对于不安全函数进行了对应安全版本的封装：localtime
// 20120807 孙尧宇      NT-0170 对流控和日志进行完善
/////////////////////////////////////////////////////////////////////////

#include "public.h"
#include "FtdcUserApiImpl.h"
CFtdcUserApiImpl::CFtdcUserApiImpl(const char *pszFlowPath, const char *pszUserApiType, CSelectReactor *pReactor)
:CFtdcUserApiImplBase(pszFlowPath, pszUserApiType, pReactor)
{
}

///用户退出请求
int CFtdcUserApiImpl::ReqUserLogout(CShfeFtdcReqUserLogoutField *pReqUserLogout, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqUserLogout, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqUserLogoutField ReqUserLogoutField;
	memcpy(&ReqUserLogoutField, pReqUserLogout, sizeof(CFTDReqUserLogoutField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqUserLogoutField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqUserLogout,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pReqUserLogout, &CFTDReqUserLogoutField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///报单录入请求
int CFtdcUserApiImpl::ReqOrderInsert(CShfeFtdcInputOrderField *pInputOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqOrderInsert, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDInputOrderField InputOrderField;
	memcpy(&InputOrderField, pInputOrder, sizeof(CFTDInputOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &InputOrderField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqOrderInsert,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pInputOrder, &CFTDInputOrderField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///报单操作请求
int CFtdcUserApiImpl::ReqOrderAction(CShfeFtdcOrderActionField *pOrderAction, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqOrderAction, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDOrderActionField OrderActionField;
	memcpy(&OrderActionField, pOrderAction, sizeof(CFTDOrderActionField));
	FTDC_ADD_FIELD(&m_reqPackage, &OrderActionField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqOrderAction,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pOrderAction, &CFTDOrderActionField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///报价录入请求
int CFtdcUserApiImpl::ReqQuoteInsert(CShfeFtdcInputQuoteField *pInputQuote, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQuoteInsert, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDInputQuoteField InputQuoteField;
	memcpy(&InputQuoteField, pInputQuote, sizeof(CFTDInputQuoteField));
	FTDC_ADD_FIELD(&m_reqPackage, &InputQuoteField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqQuoteInsert,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pInputQuote, &CFTDInputQuoteField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///报价操作请求
int CFtdcUserApiImpl::ReqQuoteAction(CShfeFtdcQuoteActionField *pQuoteAction, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQuoteAction, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQuoteActionField QuoteActionField;
	memcpy(&QuoteActionField, pQuoteAction, sizeof(CFTDQuoteActionField));
	FTDC_ADD_FIELD(&m_reqPackage, &QuoteActionField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqQuoteAction,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pQuoteAction, &CFTDQuoteActionField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///OTC报单录入请求
int CFtdcUserApiImpl::ReqOTCOrderInsert(CShfeFtdcOTCOrderField *pOTCOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqOTCOrderInsert, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDOTCOrderField OTCOrderField;
	memcpy(&OTCOrderField, pOTCOrder, sizeof(CFTDOTCOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &OTCOrderField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqOTCOrderInsert,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pOTCOrder, &CFTDOTCOrderField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///用户密码修改请求
int CFtdcUserApiImpl::ReqUserPasswordUpdate(CShfeFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqUserPasswordUpdate, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDUserPasswordUpdateField UserPasswordUpdateField;
	memcpy(&UserPasswordUpdateField, pUserPasswordUpdate, sizeof(CFTDUserPasswordUpdateField));
	FTDC_ADD_FIELD(&m_reqPackage, &UserPasswordUpdateField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqUserPasswordUpdate,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pUserPasswordUpdate, &CFTDUserPasswordUpdateField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///执行宣告录入请求
int CFtdcUserApiImpl::ReqExecOrderInsert(CShfeFtdcInputExecOrderField *pInputExecOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqExecOrderInsert, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDInputExecOrderField InputExecOrderField;
	memcpy(&InputExecOrderField, pInputExecOrder, sizeof(CFTDInputExecOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &InputExecOrderField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqExecOrderInsert,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pInputExecOrder, &CFTDInputExecOrderField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///执行宣告操作请求
int CFtdcUserApiImpl::ReqExecOrderAction(CShfeFtdcExecOrderActionField *pExecOrderAction, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqExecOrderAction, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDExecOrderActionField ExecOrderActionField;
	memcpy(&ExecOrderActionField, pExecOrderAction, sizeof(CFTDExecOrderActionField));
	FTDC_ADD_FIELD(&m_reqPackage, &ExecOrderActionField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqExecOrderAction,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pExecOrderAction, &CFTDExecOrderActionField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///管理报单录入请求
int CFtdcUserApiImpl::ReqAdminOrderInsert(CShfeFtdcInputAdminOrderField *pInputAdminOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqAdminOrderInsert, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDInputAdminOrderField InputAdminOrderField;
	memcpy(&InputAdminOrderField, pInputAdminOrder, sizeof(CFTDInputAdminOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &InputAdminOrderField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqAdminOrderInsert,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pInputAdminOrder, &CFTDInputAdminOrderField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///非标组合报单录入请求
int CFtdcUserApiImpl::ReqCombOrderInsert(CShfeFtdcInputCombOrderField *pInputCombOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqCombOrderInsert, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDInputCombOrderField InputCombOrderField;
	memcpy(&InputCombOrderField, pInputCombOrder, sizeof(CFTDInputCombOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &InputCombOrderField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqCombOrderInsert,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pInputCombOrder, &CFTDInputCombOrderField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///订阅主题请求
int CFtdcUserApiImpl::ReqSubscribeTopic(CShfeFtdcDisseminationField *pDissemination, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqSubscribeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDDisseminationField DisseminationField;
	memcpy(&DisseminationField, pDissemination, sizeof(CFTDDisseminationField));
	FTDC_ADD_FIELD(&m_reqPackage, &DisseminationField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqSubscribeTopic,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pDissemination, &CFTDDisseminationField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易所公告请求
int CFtdcUserApiImpl::ReqBulletin(CShfeFtdcBulletinField *pBulletin, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqBulletin, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDBulletinField BulletinField;
	memcpy(&BulletinField, pBulletin, sizeof(CFTDBulletinField));
	FTDC_ADD_FIELD(&m_reqPackage, &BulletinField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqBulletin,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pBulletin, &CFTDBulletinField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易所信息请求
int CFtdcUserApiImpl::ReqInformation(CShfeFtdcInformationField *pInformation, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqInformation, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDInformationField InformationField;
	memcpy(&InformationField, pInformation, sizeof(CFTDInformationField));
	FTDC_ADD_FIELD(&m_reqPackage, &InformationField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqInformation,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pInformation, &CFTDInformationField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///合约交易状态改变请求
int CFtdcUserApiImpl::ReqInstrumentStatusUpdate(CShfeFtdcInstrumentStatusField *pInstrumentStatus, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqInstrumentStatusUpdate, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDInstrumentStatusField InstrumentStatusField;
	memcpy(&InstrumentStatusField, pInstrumentStatus, sizeof(CFTDInstrumentStatusField));
	FTDC_ADD_FIELD(&m_reqPackage, &InstrumentStatusField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqInstrumentStatusUpdate,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pInstrumentStatus, &CFTDInstrumentStatusField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///强制用户退出请求
int CFtdcUserApiImpl::ReqForceUserExit(CShfeFtdcForceUserExitField *pForceUserExit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqForceUserExit, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDForceUserExitField ForceUserExitField;
	memcpy(&ForceUserExitField, pForceUserExit, sizeof(CFTDForceUserExitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ForceUserExitField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqForceUserExit,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pForceUserExit, &CFTDForceUserExitField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///用户会话删除请求
int CFtdcUserApiImpl::ReqForceUserLogout(CShfeFtdcForceUserExitField *pForceUserExit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqForceUserLogout, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDForceUserExitField ForceUserExitField;
	memcpy(&ForceUserExitField, pForceUserExit, sizeof(CFTDForceUserExitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ForceUserExitField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqForceUserLogout,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pForceUserExit, &CFTDForceUserExitField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易所数据同步状态改变请求
int CFtdcUserApiImpl::ReqExchangeDataSyncStatusUpdate(CShfeFtdcExchangeDataSyncStatusField *pExchangeDataSyncStatus, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqExchangeDataSyncStatusUpdate, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDExchangeDataSyncStatusField ExchangeDataSyncStatusField;
	memcpy(&ExchangeDataSyncStatusField, pExchangeDataSyncStatus, sizeof(CFTDExchangeDataSyncStatusField));
	FTDC_ADD_FIELD(&m_reqPackage, &ExchangeDataSyncStatusField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqExchangeDataSyncStatusUpdate,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pExchangeDataSyncStatus, &CFTDExchangeDataSyncStatusField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///结算组数据同步状态改变请求
int CFtdcUserApiImpl::ReqSGDataSyncStatusUpdate(CShfeFtdcSGDataSyncStatusField *pSGDataSyncStatus, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqSGDataSyncStatusUpdate, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDSGDataSyncStatusField SGDataSyncStatusField;
	memcpy(&SGDataSyncStatusField, pSGDataSyncStatus, sizeof(CFTDSGDataSyncStatusField));
	FTDC_ADD_FIELD(&m_reqPackage, &SGDataSyncStatusField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqSGDataSyncStatusUpdate,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pSGDataSyncStatus, &CFTDSGDataSyncStatusField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员资金查询请求
int CFtdcUserApiImpl::ReqQryPartAccount(CShfeFtdcQryPartAccountField *pQryPartAccount, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPartAccount, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryPartAccountField QryPartAccountField;
	memcpy(&QryPartAccountField, pQryPartAccount, sizeof(CFTDQryPartAccountField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryPartAccountField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///报单查询请求
int CFtdcUserApiImpl::ReqQryOrder(CShfeFtdcQryOrderField *pQryOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryOrder, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryOrderField QryOrderField;
	memcpy(&QryOrderField, pQryOrder, sizeof(CFTDQryOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryOrderField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///报价查询请求
int CFtdcUserApiImpl::ReqQryQuote(CShfeFtdcQryQuoteField *pQryQuote, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryQuote, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryQuoteField QryQuoteField;
	memcpy(&QryQuoteField, pQryQuote, sizeof(CFTDQryQuoteField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryQuoteField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///成交单查询请求
int CFtdcUserApiImpl::ReqQryTrade(CShfeFtdcQryTradeField *pQryTrade, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTrade, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryTradeField QryTradeField;
	memcpy(&QryTradeField, pQryTrade, sizeof(CFTDQryTradeField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryTradeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员客户查询请求
int CFtdcUserApiImpl::ReqQryClient(CShfeFtdcQryClientField *pQryClient, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryClient, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryClientField QryClientField;
	memcpy(&QryClientField, pQryClient, sizeof(CFTDQryClientField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryClientField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员持仓查询请求
int CFtdcUserApiImpl::ReqQryPartPosition(CShfeFtdcQryPartPositionField *pQryPartPosition, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPartPosition, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryPartPositionField QryPartPositionField;
	memcpy(&QryPartPositionField, pQryPartPosition, sizeof(CFTDQryPartPositionField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryPartPositionField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///客户持仓查询请求
int CFtdcUserApiImpl::ReqQryClientPosition(CShfeFtdcQryClientPositionField *pQryClientPosition, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryClientPosition, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryClientPositionField QryClientPositionField;
	memcpy(&QryClientPositionField, pQryClientPosition, sizeof(CFTDQryClientPositionField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryClientPositionField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///合约查询请求
int CFtdcUserApiImpl::ReqQryInstrument(CShfeFtdcQryInstrumentField *pQryInstrument, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryInstrument, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryInstrumentField QryInstrumentField;
	memcpy(&QryInstrumentField, pQryInstrument, sizeof(CFTDQryInstrumentField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryInstrumentField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///合约交易状态查询请求
int CFtdcUserApiImpl::ReqQryInstrumentStatus(CShfeFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryInstrumentStatus, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryInstrumentStatusField QryInstrumentStatusField;
	memcpy(&QryInstrumentStatusField, pQryInstrumentStatus, sizeof(CFTDQryInstrumentStatusField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryInstrumentStatusField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///结算组状态查询请求
int CFtdcUserApiImpl::ReqQrySGDataSyncStatus(CShfeFtdcQrySGDataSyncStatusField *pQrySGDataSyncStatus, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySGDataSyncStatus, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQrySGDataSyncStatusField QrySGDataSyncStatusField;
	memcpy(&QrySGDataSyncStatusField, pQrySGDataSyncStatus, sizeof(CFTDQrySGDataSyncStatusField));
	FTDC_ADD_FIELD(&m_reqPackage, &QrySGDataSyncStatusField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///保值额度查询
int CFtdcUserApiImpl::ReqQryHedgeVolume(CShfeFtdcQryHedgeVolumeField *pQryHedgeVolume, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHedgeVolume, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryHedgeVolumeField QryHedgeVolumeField;
	memcpy(&QryHedgeVolumeField, pQryHedgeVolume, sizeof(CFTDQryHedgeVolumeField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryHedgeVolumeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///信用限额查询请求
int CFtdcUserApiImpl::ReqQryCreditLimit(CShfeFtdcQryCreditLimitField *pQryCreditLimit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryCreditLimit, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryCreditLimitField QryCreditLimitField;
	memcpy(&QryCreditLimitField, pQryCreditLimit, sizeof(CFTDQryCreditLimitField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryCreditLimitField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///非标组合报单查询请求
int CFtdcUserApiImpl::ReqQryCombOrder(CShfeFtdcQryCombOrderField *pQryCombOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryCombOrder, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryCombOrderField QryCombOrderField;
	memcpy(&QryCombOrderField, pQryCombOrder, sizeof(CFTDQryCombOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryCombOrderField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///执行宣告查询请求
int CFtdcUserApiImpl::ReqQryExecOrder(CShfeFtdcQryExecOrderField *pQryExecOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryExecOrder, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryExecOrderField QryExecOrderField;
	memcpy(&QryExecOrderField, pQryExecOrder, sizeof(CFTDQryExecOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryExecOrderField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///普通行情查询请求
int CFtdcUserApiImpl::ReqQryMarketData(CShfeFtdcQryMarketDataField *pQryMarketData, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMarketData, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryMarketDataField QryMarketDataField;
	memcpy(&QryMarketDataField, pQryMarketData, sizeof(CFTDQryMarketDataField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryMarketDataField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易所公告查询请求
int CFtdcUserApiImpl::ReqQryBulletin(CShfeFtdcQryBulletinField *pQryBulletin, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryBulletin, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryBulletinField QryBulletinField;
	memcpy(&QryBulletinField, pQryBulletin, sizeof(CFTDQryBulletinField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryBulletinField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主题查询请求
int CFtdcUserApiImpl::ReqQryTopic(CShfeFtdcDisseminationField *pDissemination, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDDisseminationField DisseminationField;
	memcpy(&DisseminationField, pDissemination, sizeof(CFTDDisseminationField));
	FTDC_ADD_FIELD(&m_reqPackage, &DisseminationField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///用户在线查询请求
int CFtdcUserApiImpl::ReqQryUserSession(CShfeFtdcQryUserSessionField *pQryUserSession, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryUserSession, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryUserSessionField QryUserSessionField;
	memcpy(&QryUserSessionField, pQryUserSession, sizeof(CFTDQryUserSessionField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryUserSessionField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///用户查询请求
int CFtdcUserApiImpl::ReqQryUser(CShfeFtdcQryUserField *pQryUser, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryUser, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryUserField QryUserField;
	memcpy(&QryUserField, pQryUser, sizeof(CFTDQryUserField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryUserField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员查询请求
int CFtdcUserApiImpl::ReqQryParticipant(CShfeFtdcQryParticipantField *pQryParticipant, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryParticipant, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryParticipantField QryParticipantField;
	memcpy(&QryParticipantField, pQryParticipant, sizeof(CFTDQryParticipantField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryParticipantField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///合约价位查询
int CFtdcUserApiImpl::ReqQryMBLMarketData(CShfeFtdcQryMBLMarketDataField *pQryMBLMarketData, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMBLMarketData, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryMBLMarketDataField QryMBLMarketDataField;
	memcpy(&QryMBLMarketDataField, pQryMBLMarketData, sizeof(CFTDQryMBLMarketDataField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryMBLMarketDataField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///信息查询
int CFtdcUserApiImpl::ReqQryInformation(CShfeFtdcQryInformationField *pQryInformation, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryInformation, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryInformationField QryInformationField;
	memcpy(&QryInformationField, pQryInformation, sizeof(CFTDQryInformationField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryInformationField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///客户持仓查询请求
int CFtdcUserApiImpl::ReqQryClientPositionV1(CShfeFtdcQryClientPositionV1Field *pQryClientPositionV1, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryClientPositionV1, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryClientPositionV1Field QryClientPositionV1Field;
	memcpy(&QryClientPositionV1Field, pQryClientPositionV1, sizeof(CFTDQryClientPositionV1Field));
	FTDC_ADD_FIELD(&m_reqPackage, &QryClientPositionV1Field);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///汇率查询请求
int CFtdcUserApiImpl::ReqQryExchangeRate(CShfeFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryExchangeRate, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDQryExchangeRateField QryExchangeRateField;
	memcpy(&QryExchangeRateField, pQryExchangeRate, sizeof(CFTDQryExchangeRateField));
	FTDC_ADD_FIELD(&m_reqPackage, &QryExchangeRateField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///CPU查询
int CFtdcUserApiImpl::ReqQryTopCpuInfoTopic(CShfeFtdcReqQryTopCpuInfoField *pReqQryTopCpuInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTopCpuInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTopCpuInfoField ReqQryTopCpuInfoField;
	memcpy(&ReqQryTopCpuInfoField, pReqQryTopCpuInfo, sizeof(CFTDReqQryTopCpuInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTopCpuInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///Mem查询
int CFtdcUserApiImpl::ReqQryTopMemInfoTopic(CShfeFtdcReqQryTopMemInfoField *pReqQryTopMemInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTopMemInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTopMemInfoField ReqQryTopMemInfoField;
	memcpy(&ReqQryTopMemInfoField, pReqQryTopMemInfo, sizeof(CFTDReqQryTopMemInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTopMemInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///process查询
int CFtdcUserApiImpl::ReqQryTopProcessInfoTopic(CShfeFtdcReqQryTopProcessInfoField *pReqQryTopProcessInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTopProcessInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTopProcessInfoField ReqQryTopProcessInfoField;
	memcpy(&ReqQryTopProcessInfoField, pReqQryTopProcessInfo, sizeof(CFTDReqQryTopProcessInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTopProcessInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///filesystem查询
int CFtdcUserApiImpl::ReqQryFileSystemInfoTopic(CShfeFtdcReqQryFileSystemInfoField *pReqQryFileSystemInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryFileSystemInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryFileSystemInfoField ReqQryFileSystemInfoField;
	memcpy(&ReqQryFileSystemInfoField, pReqQryFileSystemInfo, sizeof(CFTDReqQryFileSystemInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryFileSystemInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///network查询
int CFtdcUserApiImpl::ReqQryNetworkInfoTopic(CShfeFtdcReqQryNetworkInfoField *pReqQryNetworkInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetworkInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetworkInfoField ReqQryNetworkInfoField;
	memcpy(&ReqQryNetworkInfoField, pReqQryNetworkInfo, sizeof(CFTDReqQryNetworkInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetworkInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机环境信息查询
int CFtdcUserApiImpl::ReqQryHostEnvTopic(CShfeFtdcReqQryHostEnvField *pReqQryHostEnv, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHostEnvTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryHostEnvField ReqQryHostEnvField;
	memcpy(&ReqQryHostEnvField, pReqQryHostEnv, sizeof(CFTDReqQryHostEnvField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryHostEnvField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///客户端登录查询
int CFtdcUserApiImpl::ReqQryClientLoginTopic(CShfeFtdcReqQryClientLoginField *pReqQryClientLogin, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryClientLoginTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryClientLoginField ReqQryClientLoginField;
	memcpy(&ReqQryClientLoginField, pReqQryClientLogin, sizeof(CFTDReqQryClientLoginField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryClientLoginField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///获得监控对象信息查询
int CFtdcUserApiImpl::ReqQryMonitorObjectTopic(CShfeFtdcReqQryMonitorObjectField *pReqQryMonitorObject, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonitorObjectTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonitorObjectField ReqQryMonitorObjectField;
	memcpy(&ReqQryMonitorObjectField, pReqQryMonitorObject, sizeof(CFTDReqQryMonitorObjectField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonitorObjectField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///获得业务进程和主机的对应关系查询
int CFtdcUserApiImpl::ReqQryObjectRationalTopic(CShfeFtdcReqQryObjectRationalField *pReqQryObjectRational, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryObjectRationalTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryObjectRationalField ReqQryObjectRationalField;
	memcpy(&ReqQryObjectRationalField, pReqQryObjectRational, sizeof(CFTDReqQryObjectRationalField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryObjectRationalField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///日志文件内容查询
int CFtdcUserApiImpl::ReqQrySyslogInfoTopic(CShfeFtdcReqQrySyslogInfoField *pReqQrySyslogInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySyslogInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySyslogInfoField ReqQrySyslogInfoField;
	memcpy(&ReqQrySyslogInfoField, pReqQrySyslogInfo, sizeof(CFTDReqQrySyslogInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySyslogInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///监控内容订阅请求
int CFtdcUserApiImpl::ReqQrySubscriberTopic(CShfeFtdcReqQrySubscriberField *pReqQrySubscriber, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySubscriberTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySubscriberField ReqQrySubscriberField;
	memcpy(&ReqQrySubscriberField, pReqQrySubscriber, sizeof(CFTDReqQrySubscriberField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySubscriberField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///对象关系查询
int CFtdcUserApiImpl::ReqQryOidRelationTopic(CShfeFtdcReqQryOidRelationField *pReqQryOidRelation, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryOidRelationTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryOidRelationField ReqQryOidRelationField;
	memcpy(&ReqQryOidRelationField, pReqQryOidRelation, sizeof(CFTDReqQryOidRelationField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryOidRelationField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///用户信息查询请求
int CFtdcUserApiImpl::ReqQryUserInfoTopic(CShfeFtdcReqQryUserInfoField *pReqQryUserInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryUserInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryUserInfoField ReqQryUserInfoField;
	memcpy(&ReqQryUserInfoField, pReqQryUserInfo, sizeof(CFTDReqQryUserInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryUserInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///在线用户信息查询请求
int CFtdcUserApiImpl::ReqQryOnlineUserInfoTopic(CShfeFtdcReqQryOnlineUserInfoField *pReqQryOnlineUserInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryOnlineUserInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryOnlineUserInfoField ReqQryOnlineUserInfoField;
	memcpy(&ReqQryOnlineUserInfoField, pReqQryOnlineUserInfo, sizeof(CFTDReqQryOnlineUserInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryOnlineUserInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///告警事件查询请求
int CFtdcUserApiImpl::ReqQryWarningEventTopic(CShfeFtdcReqQryWarningEventField *pReqQryWarningEvent, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryWarningEventTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryWarningEventField ReqQryWarningEventField;
	memcpy(&ReqQryWarningEventField, pReqQryWarningEvent, sizeof(CFTDReqQryWarningEventField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryWarningEventField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///CPU使用率查询请求
int CFtdcUserApiImpl::ReqQryCPUUsageTopic(CShfeFtdcReqQryCPUUsageField *pReqQryCPUUsage, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryCPUUsageTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryCPUUsageField ReqQryCPUUsageField;
	memcpy(&ReqQryCPUUsageField, pReqQryCPUUsage, sizeof(CFTDReqQryCPUUsageField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryCPUUsageField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///内存使用率查询请求
int CFtdcUserApiImpl::ReqQryMemoryUsageTopic(CShfeFtdcReqQryMemoryUsageField *pReqQryMemoryUsage, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMemoryUsageTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMemoryUsageField ReqQryMemoryUsageField;
	memcpy(&ReqQryMemoryUsageField, pReqQryMemoryUsage, sizeof(CFTDReqQryMemoryUsageField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMemoryUsageField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///硬盘使用率查询请求
int CFtdcUserApiImpl::ReqQryDiskUsageTopic(CShfeFtdcReqQryDiskUsageField *pReqQryDiskUsage, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryDiskUsageTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryDiskUsageField ReqQryDiskUsageField;
	memcpy(&ReqQryDiskUsageField, pReqQryDiskUsage, sizeof(CFTDReqQryDiskUsageField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryDiskUsageField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///对象状态指标查询
int CFtdcUserApiImpl::ReqQryObjectAttrTopic(CShfeFtdcReqQryObjectAttrField *pReqQryObjectAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryObjectAttrTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryObjectAttrField ReqQryObjectAttrField;
	memcpy(&ReqQryObjectAttrField, pReqQryObjectAttr, sizeof(CFTDReqQryObjectAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryObjectAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///KeyFile查询请求
int CFtdcUserApiImpl::ReqQryKeyFileInfoTopic(CShfeFtdcReqQryKeyFileInfoField *pReqQryKeyFileInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryKeyFileInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryKeyFileInfoField ReqQryKeyFileInfoField;
	memcpy(&ReqQryKeyFileInfoField, pReqQryKeyFileInfo, sizeof(CFTDReqQryKeyFileInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryKeyFileInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///HostMonitorCfg查询请求
int CFtdcUserApiImpl::ReqQryHostMonitorCfgTopic(CShfeFtdcReqQryHostMonitorCfgField *pReqQryHostMonitorCfg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHostMonitorCfgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryHostMonitorCfgField ReqQryHostMonitorCfgField;
	memcpy(&ReqQryHostMonitorCfgField, pReqQryHostMonitorCfg, sizeof(CFTDReqQryHostMonitorCfgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryHostMonitorCfgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///AppMonitorCfg查询请求
int CFtdcUserApiImpl::ReqQryAppMonitorCfgTopic(CShfeFtdcReqQryAppMonitorCfgField *pReqQryAppMonitorCfg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryAppMonitorCfgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryAppMonitorCfgField ReqQryAppMonitorCfgField;
	memcpy(&ReqQryAppMonitorCfgField, pReqQryAppMonitorCfg, sizeof(CFTDReqQryAppMonitorCfgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryAppMonitorCfgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///HostConfig查询请求
int CFtdcUserApiImpl::ReqQryHostConfigTopic(CShfeFtdcReqQryHostConfigField *pReqQryHostConfig, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHostConfigTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryHostConfigField ReqQryHostConfigField;
	memcpy(&ReqQryHostConfigField, pReqQryHostConfig, sizeof(CFTDReqQryHostConfigField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryHostConfigField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///历史对象状态指标查询
int CFtdcUserApiImpl::ReqQryHistoryObjectAttrTopic(CShfeFtdcReqQryHistoryObjectAttrField *pReqQryHistoryObjectAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHistoryObjectAttrTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryHistoryObjectAttrField ReqQryHistoryObjectAttrField;
	memcpy(&ReqQryHistoryObjectAttrField, pReqQryHistoryObjectAttr, sizeof(CFTDReqQryHistoryObjectAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryHistoryObjectAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///前置响应信息查询
int CFtdcUserApiImpl::ReqQryFrontInfoTopic(CShfeFtdcReqQryFrontInfoField *pReqQryFrontInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryFrontInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryFrontInfoField ReqQryFrontInfoField;
	memcpy(&ReqQryFrontInfoField, pReqQryFrontInfo, sizeof(CFTDReqQryFrontInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryFrontInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///用户登录
int CFtdcUserApiImpl::ReqQrySysUserLoginTopic(CShfeFtdcReqQrySysUserLoginField *pReqQrySysUserLogin, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySysUserLoginTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySysUserLoginField ReqQrySysUserLoginField;
	memcpy(&ReqQrySysUserLoginField, pReqQrySysUserLogin, sizeof(CFTDReqQrySysUserLoginField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySysUserLoginField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///用户登出
int CFtdcUserApiImpl::ReqQrySysUserLogoutTopic(CShfeFtdcReqQrySysUserLogoutField *pReqQrySysUserLogout, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySysUserLogoutTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySysUserLogoutField ReqQrySysUserLogoutField;
	memcpy(&ReqQrySysUserLogoutField, pReqQrySysUserLogout, sizeof(CFTDReqQrySysUserLogoutField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySysUserLogoutField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///用户修改密码
int CFtdcUserApiImpl::ReqQrySysUserPasswordUpdateTopic(CShfeFtdcReqQrySysUserPasswordUpdateField *pReqQrySysUserPasswordUpdate, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySysUserPasswordUpdateTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySysUserPasswordUpdateField ReqQrySysUserPasswordUpdateField;
	memcpy(&ReqQrySysUserPasswordUpdateField, pReqQrySysUserPasswordUpdate, sizeof(CFTDReqQrySysUserPasswordUpdateField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySysUserPasswordUpdateField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///注册用户
int CFtdcUserApiImpl::ReqQrySysUserRegisterTopic(CShfeFtdcReqQrySysUserRegisterField *pReqQrySysUserRegister, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySysUserRegisterTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySysUserRegisterField ReqQrySysUserRegisterField;
	memcpy(&ReqQrySysUserRegisterField, pReqQrySysUserRegister, sizeof(CFTDReqQrySysUserRegisterField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySysUserRegisterField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///删除用户
int CFtdcUserApiImpl::ReqQrySysUserDeleteTopic(CShfeFtdcReqQrySysUserDeleteField *pReqQrySysUserDelete, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySysUserDeleteTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySysUserDeleteField ReqQrySysUserDeleteField;
	memcpy(&ReqQrySysUserDeleteField, pReqQrySysUserDelete, sizeof(CFTDReqQrySysUserDeleteField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySysUserDeleteField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易日志查询
int CFtdcUserApiImpl::ReqQryTradeLogTopic(CShfeFtdcReqQryTradeLogField *pReqQryTradeLog, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTradeLogTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTradeLogField ReqQryTradeLogField;
	memcpy(&ReqQryTradeLogField, pReqQryTradeLog, sizeof(CFTDReqQryTradeLogField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTradeLogField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///告警事件修改
int CFtdcUserApiImpl::ReqQryWarningEventUpdateTopic(CShfeFtdcReqQryWarningEventUpdateField *pReqQryWarningEventUpdate, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryWarningEventUpdateTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryWarningEventUpdateField ReqQryWarningEventUpdateField;
	memcpy(&ReqQryWarningEventUpdateField, pReqQryWarningEventUpdate, sizeof(CFTDReqQryWarningEventUpdateField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryWarningEventUpdateField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易峰值查询
int CFtdcUserApiImpl::ReqQryTradepeakTopic(CShfeFtdcReqQryTradepeakField *pReqQryTradepeak, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTradepeakTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTradepeakField ReqQryTradepeakField;
	memcpy(&ReqQryTradepeakField, pReqQryTradepeak, sizeof(CFTDReqQryTradepeakField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTradepeakField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///
int CFtdcUserApiImpl::ReqQryHistoryCpuInfoTopic(CShfeFtdcReqQryHistoryCpuInfoField *pReqQryHistoryCpuInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHistoryCpuInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryHistoryCpuInfoField ReqQryHistoryCpuInfoField;
	memcpy(&ReqQryHistoryCpuInfoField, pReqQryHistoryCpuInfo, sizeof(CFTDReqQryHistoryCpuInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryHistoryCpuInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///
int CFtdcUserApiImpl::ReqQryHistoryMemInfoTopic(CShfeFtdcReqQryHistoryMemInfoField *pReqQryHistoryMemInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHistoryMemInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryHistoryMemInfoField ReqQryHistoryMemInfoField;
	memcpy(&ReqQryHistoryMemInfoField, pReqQryHistoryMemInfo, sizeof(CFTDReqQryHistoryMemInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryHistoryMemInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///
int CFtdcUserApiImpl::ReqQryHistoryNetworkInfoTopic(CShfeFtdcReqQryHistoryNetworkInfoField *pReqQryHistoryNetworkInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHistoryNetworkInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryHistoryNetworkInfoField ReqQryHistoryNetworkInfoField;
	memcpy(&ReqQryHistoryNetworkInfoField, pReqQryHistoryNetworkInfo, sizeof(CFTDReqQryHistoryNetworkInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryHistoryNetworkInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///监控系统在线用户查询
int CFtdcUserApiImpl::ReqQryMonitorOnlineUser(CShfeFtdcReqQryMonitorOnlineUserField *pReqQryMonitorOnlineUser, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonitorOnlineUser, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonitorOnlineUserField ReqQryMonitorOnlineUserField;
	memcpy(&ReqQryMonitorOnlineUserField, pReqQryMonitorOnlineUser, sizeof(CFTDReqQryMonitorOnlineUserField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonitorOnlineUserField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///历史峰值查询
int CFtdcUserApiImpl::ReqQryHistoryTradePeakTopic(CShfeFtdcReqQryHistoryTradePeakField *pReqQryHistoryTradePeak, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHistoryTradePeakTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryHistoryTradePeakField ReqQryHistoryTradePeakField;
	memcpy(&ReqQryHistoryTradePeakField, pReqQryHistoryTradePeak, sizeof(CFTDReqQryHistoryTradePeakField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryHistoryTradePeakField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///日志事件查询
int CFtdcUserApiImpl::ReqQrySyslogEventTopic(CShfeFtdcReqQrySyslogEventField *pReqQrySyslogEvent, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySyslogEventTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySyslogEventField ReqQrySyslogEventField;
	memcpy(&ReqQrySyslogEventField, pReqQrySyslogEvent, sizeof(CFTDReqQrySyslogEventField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySyslogEventField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///日志事件订阅请求
int CFtdcUserApiImpl::ReqQrySyslogEventSubcriberTopic(CShfeFtdcReqQrySyslogEventSubcriberField *pReqQrySyslogEventSubcriber, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySyslogEventSubcriberTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySyslogEventSubcriberField ReqQrySyslogEventSubcriberField;
	memcpy(&ReqQrySyslogEventSubcriberField, pReqQrySyslogEventSubcriber, sizeof(CFTDReqQrySyslogEventSubcriberField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySyslogEventSubcriberField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易日切换通知
int CFtdcUserApiImpl::ReqQryTradeDayChangeTopic(CShfeFtdcReqQryTradeDayChangeField *pReqQryTradeDayChange, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTradeDayChangeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTradeDayChangeField ReqQryTradeDayChangeField;
	memcpy(&ReqQryTradeDayChangeField, pReqQryTradeDayChange, sizeof(CFTDReqQryTradeDayChangeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTradeDayChangeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///tomcat信息查询
int CFtdcUserApiImpl::ReqQryTomcatInfoTopic(CShfeFtdcReqQryTomcatInfoField *pReqQryTomcatInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTomcatInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTomcatInfoField ReqQryTomcatInfoField;
	memcpy(&ReqQryTomcatInfoField, pReqQryTomcatInfo, sizeof(CFTDReqQryTomcatInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTomcatInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///虚拟机信息查询
int CFtdcUserApiImpl::ReqQryVMInfoTopic(CShfeFtdcReqQryVMInfoField *pReqQryVMInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryVMInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryVMInfoField ReqQryVMInfoField;
	memcpy(&ReqQryVMInfoField, pReqQryVMInfo, sizeof(CFTDReqQryVMInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryVMInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///系统属性信息查询
int CFtdcUserApiImpl::ReqQryPropertyInfoTopic(CShfeFtdcReqQryPropertyInfoField *pReqQryPropertyInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPropertyInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryPropertyInfoField ReqQryPropertyInfoField;
	memcpy(&ReqQryPropertyInfoField, pReqQryPropertyInfo, sizeof(CFTDReqQryPropertyInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryPropertyInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///系统内存池信息查询
int CFtdcUserApiImpl::ReqQryMemPoolInfoTopic(CShfeFtdcReqQryMemPoolInfoField *pReqQryMemPoolInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMemPoolInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMemPoolInfoField ReqQryMemPoolInfoField;
	memcpy(&ReqQryMemPoolInfoField, pReqQryMemPoolInfo, sizeof(CFTDReqQryMemPoolInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMemPoolInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///文件内容信息查询
int CFtdcUserApiImpl::ReqQryFileContentInfoTopic(CShfeFtdcReqQryFileContentInfoField *pReqQryFileContentInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryFileContentInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryFileContentInfoField ReqQryFileContentInfoField;
	memcpy(&ReqQryFileContentInfoField, pReqQryFileContentInfo, sizeof(CFTDReqQryFileContentInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryFileContentInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///连接信息查询
int CFtdcUserApiImpl::ReqQryConnectionInfoTopic(CShfeFtdcReqQryConnectionInfoField *pReqQryConnectionInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryConnectionInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryConnectionInfoField ReqQryConnectionInfoField;
	memcpy(&ReqQryConnectionInfoField, pReqQryConnectionInfo, sizeof(CFTDReqQryConnectionInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryConnectionInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///连接器信息查询
int CFtdcUserApiImpl::ReqQryConnectorInfoTopic(CShfeFtdcReqQryConnectorInfoField *pReqQryConnectorInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryConnectorInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryConnectorInfoField ReqQryConnectorInfoField;
	memcpy(&ReqQryConnectorInfoField, pReqQryConnectorInfo, sizeof(CFTDReqQryConnectorInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryConnectorInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///数据库查询
int CFtdcUserApiImpl::ReqQryDBQueryTopic(CShfeFtdcReqQryDBQueryField *pReqQryDBQuery, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryDBQueryTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryDBQueryField ReqQryDBQueryField;
	memcpy(&ReqQryDBQueryField, pReqQryDBQuery, sizeof(CFTDReqQryDBQueryField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryDBQueryField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///文件传输请求
int CFtdcUserApiImpl::ReqQryGetFileTopic(CShfeFtdcReqQryGetFileField *pReqQryGetFile, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryGetFileTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryGetFileField ReqQryGetFileField;
	memcpy(&ReqQryGetFileField, pReqQryGetFile, sizeof(CFTDReqQryGetFileField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryGetFileField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///日志事件修改请求
int CFtdcUserApiImpl::ReqQrySyslogEventUpdateTopic(CShfeFtdcReqQrySyslogEventUpdateField *pReqQrySyslogEventUpdate, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySyslogEventUpdateTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySyslogEventUpdateField ReqQrySyslogEventUpdateField;
	memcpy(&ReqQrySyslogEventUpdateField, pReqQrySyslogEventUpdate, sizeof(CFTDReqQrySyslogEventUpdateField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySyslogEventUpdateField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///告警明细查询
int CFtdcUserApiImpl::ReqQryWarningQueryTopic(CShfeFtdcReqQryWarningQueryField *pReqQryWarningQuery, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryWarningQueryTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryWarningQueryField ReqQryWarningQueryField;
	memcpy(&ReqQryWarningQueryField, pReqQryWarningQuery, sizeof(CFTDReqQryWarningQueryField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryWarningQueryField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///网站访问查询
int CFtdcUserApiImpl::ReqQryWebVisitTopic(CShfeFtdcReqQryWebVisitField *pReqQryWebVisit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryWebVisitTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryWebVisitField ReqQryWebVisitField;
	memcpy(&ReqQryWebVisitField, pReqQryWebVisit, sizeof(CFTDReqQryWebVisitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryWebVisitField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///告警激活变更
int CFtdcUserApiImpl::ReqQryWarningActiveChange(CShfeFtdcReqQryWarningActiveChangeField *pReqQryWarningActiveChange, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryWarningActiveChange, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryWarningActiveChangeField ReqQryWarningActiveChangeField;
	memcpy(&ReqQryWarningActiveChangeField, pReqQryWarningActiveChange, sizeof(CFTDReqQryWarningActiveChangeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryWarningActiveChangeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///通用操作
int CFtdcUserApiImpl::ReqQryGeneralOperateTopic(CShfeFtdcReqQryGeneralOperateField *pReqQryGeneralOperate, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryGeneralOperateTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryGeneralOperateField ReqQryGeneralOperateField;
	memcpy(&ReqQryGeneralOperateField, pReqQryGeneralOperate, sizeof(CFTDReqQryGeneralOperateField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryGeneralOperateField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///网络设备连接关系请求
int CFtdcUserApiImpl::ReqQryNetDeviceLinkedTopic(CShfeFtdcReqQryNetDeviceLinkedField *pReqQryNetDeviceLinked, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetDeviceLinkedTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetDeviceLinkedField ReqQryNetDeviceLinkedField;
	memcpy(&ReqQryNetDeviceLinkedField, pReqQryNetDeviceLinked, sizeof(CFTDReqQryNetDeviceLinkedField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetDeviceLinkedField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易系统登录信息请求
int CFtdcUserApiImpl::ReqQryTradeUserLoginStatTopic(CShfeFtdcReqQryTradeUserLoginStatField *pReqQryTradeUserLoginStat, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTradeUserLoginStatTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTradeUserLoginStatField ReqQryTradeUserLoginStatField;
	memcpy(&ReqQryTradeUserLoginStatField, pReqQryTradeUserLoginStat, sizeof(CFTDReqQryTradeUserLoginStatField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTradeUserLoginStatField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易系统前置报单响应信息
int CFtdcUserApiImpl::ReqQryTradeFrontOrderRttStatTopic(CShfeFtdcReqQryTradeFrontOrderRttStatField *pReqQryTradeFrontOrderRttStat, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTradeFrontOrderRttStatTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTradeFrontOrderRttStatField ReqQryTradeFrontOrderRttStatField;
	memcpy(&ReqQryTradeFrontOrderRttStatField, pReqQryTradeFrontOrderRttStat, sizeof(CFTDReqQryTradeFrontOrderRttStatField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTradeFrontOrderRttStatField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///系统路由信息
int CFtdcUserApiImpl::ReqQryRouterInfoTopic(CShfeFtdcReqQryRouterInfoField *pReqQryRouterInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryRouterInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryRouterInfoField ReqQryRouterInfoField;
	memcpy(&ReqQryRouterInfoField, pReqQryRouterInfo, sizeof(CFTDReqQryRouterInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryRouterInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///磁盘I/O信息
int CFtdcUserApiImpl::ReqQryDiskIOTopic(CShfeFtdcReqQryDiskIOField *pReqQryDiskIO, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryDiskIOTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryDiskIOField ReqQryDiskIOField;
	memcpy(&ReqQryDiskIOField, pReqQryDiskIO, sizeof(CFTDReqQryDiskIOField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryDiskIOField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///系统状态信息
int CFtdcUserApiImpl::ReqQryStatInfoTopic(CShfeFtdcReqQryStatInfoField *pReqQryStatInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryStatInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryStatInfoField ReqQryStatInfoField;
	memcpy(&ReqQryStatInfoField, pReqQryStatInfo, sizeof(CFTDReqQryStatInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryStatInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易系统前置报单分布区间
int CFtdcUserApiImpl::ReqQryTradeOrderRttCutLineTopic(CShfeFtdcReqQryTradeOrderRttCutLineField *pReqQryTradeOrderRttCutLine, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTradeOrderRttCutLineTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTradeOrderRttCutLineField ReqQryTradeOrderRttCutLineField;
	memcpy(&ReqQryTradeOrderRttCutLineField, pReqQryTradeOrderRttCutLine, sizeof(CFTDReqQryTradeOrderRttCutLineField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTradeOrderRttCutLineField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员客户信息
int CFtdcUserApiImpl::ReqQryClientInfoTopic(CShfeFtdcReqQryClientInfoField *pReqQryClientInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryClientInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryClientInfoField ReqQryClientInfoField;
	memcpy(&ReqQryClientInfoField, pReqQryClientInfo, sizeof(CFTDReqQryClientInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryClientInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///请求事件描述
int CFtdcUserApiImpl::ReqQryEventDescriptionTopic(CShfeFtdcReqQryEventDescriptionField *pReqQryEventDescription, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryEventDescriptionTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryEventDescriptionField ReqQryEventDescriptionField;
	memcpy(&ReqQryEventDescriptionField, pReqQryEventDescription, sizeof(CFTDReqQryEventDescriptionField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryEventDescriptionField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///订阅前置唯一ID信息
int CFtdcUserApiImpl::ReqQryFrontUniqueIDTopic(CShfeFtdcReqQryFrontUniqueIDField *pReqQryFrontUniqueID, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryFrontUniqueIDTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryFrontUniqueIDField ReqQryFrontUniqueIDField;
	memcpy(&ReqQryFrontUniqueIDField, pReqQryFrontUniqueID, sizeof(CFTDReqQryFrontUniqueIDField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryFrontUniqueIDField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员线路地址变更请求
int CFtdcUserApiImpl::ReqQryNetPartyLinkAddrChangeTopic(CShfeFtdcReqQryNetPartyLinkAddrChangeField *pReqQryNetPartyLinkAddrChange, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetPartyLinkAddrChangeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetPartyLinkAddrChangeField ReqQryNetPartyLinkAddrChangeField;
	memcpy(&ReqQryNetPartyLinkAddrChangeField, pReqQryNetPartyLinkAddrChange, sizeof(CFTDReqQryNetPartyLinkAddrChangeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetPartyLinkAddrChangeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///请求已删除会员列表信息
int CFtdcUserApiImpl::ReqQryNetDelPartyLinkInfoTopic(CShfeFtdcReqQryNetDelPartyLinkInfoField *pReqQryNetDelPartyLinkInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetDelPartyLinkInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetDelPartyLinkInfoField ReqQryNetDelPartyLinkInfoField;
	memcpy(&ReqQryNetDelPartyLinkInfoField, pReqQryNetDelPartyLinkInfo, sizeof(CFTDReqQryNetDelPartyLinkInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetDelPartyLinkInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///请求网络性能排序
int CFtdcUserApiImpl::ReqQryPerformanceTopTopic(CShfeFtdcReqQryPerformanceTopField *pReqQryPerformanceTop, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPerformanceTopTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryPerformanceTopField ReqQryPerformanceTopField;
	memcpy(&ReqQryPerformanceTopField, pReqQryPerformanceTop, sizeof(CFTDReqQryPerformanceTopField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryPerformanceTopField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///最新网络指标查询
int CFtdcUserApiImpl::ReqQryRealTimeNetObjectAttrTopic(CShfeFtdcReqQryRealTimeNetObjectAttrField *pReqQryRealTimeNetObjectAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryRealTimeNetObjectAttrTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryRealTimeNetObjectAttrField ReqQryRealTimeNetObjectAttrField;
	memcpy(&ReqQryRealTimeNetObjectAttrField, pReqQryRealTimeNetObjectAttr, sizeof(CFTDReqQryRealTimeNetObjectAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryRealTimeNetObjectAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///网络大区划分查询
int CFtdcUserApiImpl::ReqQryNetAreaTopic(CShfeFtdcReqQryNetAreaField *pReqQryNetArea, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetAreaTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetAreaField ReqQryNetAreaField;
	memcpy(&ReqQryNetAreaField, pReqQryNetArea, sizeof(CFTDReqQryNetAreaField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetAreaField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///网络子区查询
int CFtdcUserApiImpl::ReqQryNetSubAreaTopic(CShfeFtdcReqQryNetSubAreaField *pReqQryNetSubArea, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetSubAreaTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetSubAreaField ReqQryNetSubAreaField;
	memcpy(&ReqQryNetSubAreaField, pReqQryNetSubArea, sizeof(CFTDReqQryNetSubAreaField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetSubAreaField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///网络子区IP查询
int CFtdcUserApiImpl::ReqQryNetSubAreaIPTopic(CShfeFtdcReqQryNetSubAreaIPField *pReqQryNetSubAreaIP, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetSubAreaIPTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetSubAreaIPField ReqQryNetSubAreaIPField;
	memcpy(&ReqQryNetSubAreaIPField, pReqQryNetSubAreaIP, sizeof(CFTDReqQryNetSubAreaIPField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetSubAreaIPField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///网络设备探测请求
int CFtdcUserApiImpl::ReqQryNetDeviceDetectTopic(CShfeFtdcReqQryNetDeviceDetectField *pReqQryNetDeviceDetect, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetDeviceDetectTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetDeviceDetectField ReqQryNetDeviceDetectField;
	memcpy(&ReqQryNetDeviceDetectField, pReqQryNetDeviceDetect, sizeof(CFTDReqQryNetDeviceDetectField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetDeviceDetectField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///网络设备查询请求
int CFtdcUserApiImpl::ReqQryNetDeviceRequestTopic(CShfeFtdcReqQryNetDeviceRequestField *pReqQryNetDeviceRequest, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetDeviceRequestTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetDeviceRequestField ReqQryNetDeviceRequestField;
	memcpy(&ReqQryNetDeviceRequestField, pReqQryNetDeviceRequest, sizeof(CFTDReqQryNetDeviceRequestField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetDeviceRequestField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///大楼查询
int CFtdcUserApiImpl::ReqQryNetBuildingTopic(CShfeFtdcReqQryNetBuildingField *pReqQryNetBuilding, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetBuildingTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetBuildingField ReqQryNetBuildingField;
	memcpy(&ReqQryNetBuildingField, pReqQryNetBuilding, sizeof(CFTDReqQryNetBuildingField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetBuildingField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///机房查询
int CFtdcUserApiImpl::ReqQryNetRoomTopic(CShfeFtdcReqQryNetRoomField *pReqQryNetRoom, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetRoomTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetRoomField ReqQryNetRoomField;
	memcpy(&ReqQryNetRoomField, pReqQryNetRoom, sizeof(CFTDReqQryNetRoomField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetRoomField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///机柜查询
int CFtdcUserApiImpl::ReqQryNetCabinetsTopic(CShfeFtdcReqQryNetCabinetsField *pReqQryNetCabinets, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetCabinetsTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetCabinetsField ReqQryNetCabinetsField;
	memcpy(&ReqQryNetCabinetsField, pReqQryNetCabinets, sizeof(CFTDReqQryNetCabinetsField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetCabinetsField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///OID
int CFtdcUserApiImpl::ReqQryNetOIDTopic(CShfeFtdcReqQryNetOIDField *pReqQryNetOID, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetOIDTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetOIDField ReqQryNetOIDField;
	memcpy(&ReqQryNetOIDField, pReqQryNetOID, sizeof(CFTDReqQryNetOIDField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetOIDField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///时间策略
int CFtdcUserApiImpl::ReqQryNetTimePolicyTopic(CShfeFtdcReqQryNetTimePolicyField *pReqQryNetTimePolicy, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetTimePolicyTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetTimePolicyField ReqQryNetTimePolicyField;
	memcpy(&ReqQryNetTimePolicyField, pReqQryNetTimePolicy, sizeof(CFTDReqQryNetTimePolicyField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetTimePolicyField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///采集任务查询
int CFtdcUserApiImpl::ReqQryNetGatherTaskTopic(CShfeFtdcReqQryNetGatherTaskField *pReqQryNetGatherTask, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetGatherTaskTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetGatherTaskField ReqQryNetGatherTaskField;
	memcpy(&ReqQryNetGatherTaskField, pReqQryNetGatherTask, sizeof(CFTDReqQryNetGatherTaskField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetGatherTaskField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///设备变更请求
int CFtdcUserApiImpl::ReqQryNetDeviceChgTopic(CShfeFtdcReqQryNetDeviceChgField *pReqQryNetDeviceChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetDeviceChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetDeviceChgField ReqQryNetDeviceChgField;
	memcpy(&ReqQryNetDeviceChgField, pReqQryNetDeviceChg, sizeof(CFTDReqQryNetDeviceChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetDeviceChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///常用设备型号请求
int CFtdcUserApiImpl::ReqQryNetDeviceTypeTopic(CShfeFtdcReqQryNetDeviceTypeField *pReqQryNetDeviceType, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetDeviceTypeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetDeviceTypeField ReqQryNetDeviceTypeField;
	memcpy(&ReqQryNetDeviceTypeField, pReqQryNetDeviceType, sizeof(CFTDReqQryNetDeviceTypeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetDeviceTypeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///常用设备类别请求
int CFtdcUserApiImpl::ReqQryNetDeviceCategoryTopic(CShfeFtdcReqQryNetDeviceCategoryField *pReqQryNetDeviceCategory, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetDeviceCategoryTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetDeviceCategoryField ReqQryNetDeviceCategoryField;
	memcpy(&ReqQryNetDeviceCategoryField, pReqQryNetDeviceCategory, sizeof(CFTDReqQryNetDeviceCategoryField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetDeviceCategoryField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///设备厂商请求
int CFtdcUserApiImpl::ReqQryNetManufactoryTopic(CShfeFtdcReqQryNetManufactoryField *pReqQryNetManufactory, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetManufactoryTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetManufactoryField ReqQryNetManufactoryField;
	memcpy(&ReqQryNetManufactoryField, pReqQryNetManufactory, sizeof(CFTDReqQryNetManufactoryField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetManufactoryField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///设备共同体请求
int CFtdcUserApiImpl::ReqQryNetCommunityTopic(CShfeFtdcReqQryNetCommunityField *pReqQryNetCommunity, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetCommunityTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetCommunityField ReqQryNetCommunityField;
	memcpy(&ReqQryNetCommunityField, pReqQryNetCommunity, sizeof(CFTDReqQryNetCommunityField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetCommunityField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///端口类型请求
int CFtdcUserApiImpl::ReqQryNetPortTypeTopic(CShfeFtdcReqQryNetPortTypeField *pReqQryNetPortType, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetPortTypeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetPortTypeField ReqQryNetPortTypeField;
	memcpy(&ReqQryNetPortTypeField, pReqQryNetPortType, sizeof(CFTDReqQryNetPortTypeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetPortTypeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员接入地点请求
int CFtdcUserApiImpl::ReqQryNetPartAccessSpotTopic(CShfeFtdcReqQryNetPartAccessSpotField *pReqQryNetPartAccessSpot, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetPartAccessSpotTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetPartAccessSpotField ReqQryNetPartAccessSpotField;
	memcpy(&ReqQryNetPartAccessSpotField, pReqQryNetPartAccessSpot, sizeof(CFTDReqQryNetPartAccessSpotField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetPartAccessSpotField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///端口请求
int CFtdcUserApiImpl::ReqQryNetInterfaceTopic(CShfeFtdcReqQryNetInterfaceField *pReqQryNetInterface, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetInterfaceTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetInterfaceField ReqQryNetInterfaceField;
	memcpy(&ReqQryNetInterfaceField, pReqQryNetInterface, sizeof(CFTDReqQryNetInterfaceField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetInterfaceField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///GeneralOID请求
int CFtdcUserApiImpl::ReqQryNetGeneralOIDTopic(CShfeFtdcReqQryNetGeneralOIDField *pReqQryNetGeneralOID, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetGeneralOIDTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetGeneralOIDField ReqQryNetGeneralOIDField;
	memcpy(&ReqQryNetGeneralOIDField, pReqQryNetGeneralOID, sizeof(CFTDReqQryNetGeneralOIDField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetGeneralOIDField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///监控对象类别
int CFtdcUserApiImpl::ReqQryNetMonitorTypeTopic(CShfeFtdcReqQryNetMonitorTypeField *pReqQryNetMonitorType, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorTypeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorTypeField ReqQryNetMonitorTypeField;
	memcpy(&ReqQryNetMonitorTypeField, pReqQryNetMonitorType, sizeof(CFTDReqQryNetMonitorTypeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorTypeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///指标统表
int CFtdcUserApiImpl::ReqQryNetMonitorAttrScopeTopic(CShfeFtdcReqQryNetMonitorAttrScopeField *pReqQryNetMonitorAttrScope, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorAttrScopeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorAttrScopeField ReqQryNetMonitorAttrScopeField;
	memcpy(&ReqQryNetMonitorAttrScopeField, pReqQryNetMonitorAttrScope, sizeof(CFTDReqQryNetMonitorAttrScopeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorAttrScopeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///监控指标表
int CFtdcUserApiImpl::ReqQryNetMonitorAttrTypeTopic(CShfeFtdcReqQryNetMonitorAttrTypeField *pReqQryNetMonitorAttrType, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorAttrTypeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorAttrTypeField ReqQryNetMonitorAttrTypeField;
	memcpy(&ReqQryNetMonitorAttrTypeField, pReqQryNetMonitorAttrType, sizeof(CFTDReqQryNetMonitorAttrTypeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorAttrTypeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///监控对象指标表
int CFtdcUserApiImpl::ReqQryNetMonitorObjectAttrTopic(CShfeFtdcReqQryNetMonitorObjectAttrField *pReqQryNetMonitorObjectAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorObjectAttrTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorObjectAttrField ReqQryNetMonitorObjectAttrField;
	memcpy(&ReqQryNetMonitorObjectAttrField, pReqQryNetMonitorObjectAttr, sizeof(CFTDReqQryNetMonitorObjectAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorObjectAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///职能区
int CFtdcUserApiImpl::ReqQryNetFuncAreaTopic(CShfeFtdcReqQryNetFuncAreaField *pReqQryNetFuncArea, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetFuncAreaTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetFuncAreaField ReqQryNetFuncAreaField;
	memcpy(&ReqQryNetFuncAreaField, pReqQryNetFuncArea, sizeof(CFTDReqQryNetFuncAreaField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetFuncAreaField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///监控指令表
int CFtdcUserApiImpl::ReqQryNetMonitorCommandTypeTopic(CShfeFtdcReqQryNetMonitorCommandTypeField *pReqQryNetMonitorCommandType, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorCommandTypeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorCommandTypeField ReqQryNetMonitorCommandTypeField;
	memcpy(&ReqQryNetMonitorCommandTypeField, pReqQryNetMonitorCommandType, sizeof(CFTDReqQryNetMonitorCommandTypeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorCommandTypeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///动作族表
int CFtdcUserApiImpl::ReqQryNetMonitorActionGroupTopic(CShfeFtdcReqQryNetMonitorActionGroupField *pReqQryNetMonitorActionGroup, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorActionGroupTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorActionGroupField ReqQryNetMonitorActionGroupField;
	memcpy(&ReqQryNetMonitorActionGroupField, pReqQryNetMonitorActionGroup, sizeof(CFTDReqQryNetMonitorActionGroupField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorActionGroupField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///设备对象组表
int CFtdcUserApiImpl::ReqQryNetMonitorDeviceGroupTopic(CShfeFtdcReqQryNetMonitorDeviceGroupField *pReqQryNetMonitorDeviceGroup, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorDeviceGroupTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorDeviceGroupField ReqQryNetMonitorDeviceGroupField;
	memcpy(&ReqQryNetMonitorDeviceGroupField, pReqQryNetMonitorDeviceGroup, sizeof(CFTDReqQryNetMonitorDeviceGroupField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorDeviceGroupField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///任务信息表
int CFtdcUserApiImpl::ReqQryNetMonitorTaskInfoTopic(CShfeFtdcReqQryNetMonitorTaskInfoField *pReqQryNetMonitorTaskInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorTaskInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorTaskInfoField ReqQryNetMonitorTaskInfoField;
	memcpy(&ReqQryNetMonitorTaskInfoField, pReqQryNetMonitorTaskInfo, sizeof(CFTDReqQryNetMonitorTaskInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorTaskInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///任务结果表
int CFtdcUserApiImpl::ReqQryNetMonitorTaskResultTopic(CShfeFtdcReqQryNetMonitorTaskResultField *pReqQryNetMonitorTaskResult, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorTaskResultTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorTaskResultField ReqQryNetMonitorTaskResultField;
	memcpy(&ReqQryNetMonitorTaskResultField, pReqQryNetMonitorTaskResult, sizeof(CFTDReqQryNetMonitorTaskResultField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorTaskResultField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///任务对象集
int CFtdcUserApiImpl::ReqQryNetMonitorTaskObjectSetTopic(CShfeFtdcReqQryNetMonitorTaskObjectSetField *pReqQryNetMonitorTaskObjectSet, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorTaskObjectSetTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorTaskObjectSetField ReqQryNetMonitorTaskObjectSetField;
	memcpy(&ReqQryNetMonitorTaskObjectSetField, pReqQryNetMonitorTaskObjectSet, sizeof(CFTDReqQryNetMonitorTaskObjectSetField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorTaskObjectSetField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员链路信息表
int CFtdcUserApiImpl::ReqQryNetPartyLinkInfoTopic(CShfeFtdcReqQryNetPartyLinkInfoField *pReqQryNetPartyLinkInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetPartyLinkInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetPartyLinkInfoField ReqQryNetPartyLinkInfoField;
	memcpy(&ReqQryNetPartyLinkInfoField, pReqQryNetPartyLinkInfo, sizeof(CFTDReqQryNetPartyLinkInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetPartyLinkInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///监控动作指标对照表
int CFtdcUserApiImpl::ReqQryNetMonitorActionAttrTopic(CShfeFtdcReqQryNetMonitorActionAttrField *pReqQryNetMonitorActionAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorActionAttrTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorActionAttrField ReqQryNetMonitorActionAttrField;
	memcpy(&ReqQryNetMonitorActionAttrField, pReqQryNetMonitorActionAttr, sizeof(CFTDReqQryNetMonitorActionAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorActionAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///模块
int CFtdcUserApiImpl::ReqQryNetModuleTopic(CShfeFtdcReqQryNetModuleField *pReqQryNetModule, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetModuleTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetModuleField ReqQryNetModuleField;
	memcpy(&ReqQryNetModuleField, pReqQryNetModule, sizeof(CFTDReqQryNetModuleField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetModuleField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///告警表达式信息表
int CFtdcUserApiImpl::ReqQryNetEventExprTopic(CShfeFtdcReqQryNetEventExprField *pReqQryNetEventExpr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetEventExprTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetEventExprField ReqQryNetEventExprField;
	memcpy(&ReqQryNetEventExprField, pReqQryNetEventExpr, sizeof(CFTDReqQryNetEventExprField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetEventExprField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///事件类型
int CFtdcUserApiImpl::ReqQryNetEventTypeTopic(CShfeFtdcReqQryNetEventTypeField *pReqQryNetEventType, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetEventTypeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetEventTypeField ReqQryNetEventTypeField;
	memcpy(&ReqQryNetEventTypeField, pReqQryNetEventType, sizeof(CFTDReqQryNetEventTypeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetEventTypeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///事件子类型
int CFtdcUserApiImpl::ReqQryNetSubEventTypeTopic(CShfeFtdcReqQryNetSubEventTypeField *pReqQryNetSubEventType, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetSubEventTypeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetSubEventTypeField ReqQryNetSubEventTypeField;
	memcpy(&ReqQryNetSubEventTypeField, pReqQryNetSubEventType, sizeof(CFTDReqQryNetSubEventTypeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetSubEventTypeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///事件级别
int CFtdcUserApiImpl::ReqQryNetEventLevelTopic(CShfeFtdcReqQryNetEventLevelField *pReqQryNetEventLevel, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetEventLevelTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetEventLevelField ReqQryNetEventLevelField;
	memcpy(&ReqQryNetEventLevelField, pReqQryNetEventLevel, sizeof(CFTDReqQryNetEventLevelField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetEventLevelField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///任务结果状态表
int CFtdcUserApiImpl::ReqQryNetMonitorTaskStatusResultTopic(CShfeFtdcReqQryNetMonitorTaskStatusResultField *pReqQryNetMonitorTaskStatusResult, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorTaskStatusResultTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorTaskStatusResultField ReqQryNetMonitorTaskStatusResultField;
	memcpy(&ReqQryNetMonitorTaskStatusResultField, pReqQryNetMonitorTaskStatusResult, sizeof(CFTDReqQryNetMonitorTaskStatusResultField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorTaskStatusResultField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///登陆配置服务的请求
int CFtdcUserApiImpl::ReqConfigLoginTopic(CShfeFtdcReqConfigLoginField *pReqConfigLogin, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqConfigLoginTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqConfigLoginField ReqConfigLoginField;
	memcpy(&ReqConfigLoginField, pReqConfigLogin, sizeof(CFTDReqConfigLoginField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqConfigLoginField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqConfigLoginTopic,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pReqConfigLogin, &CFTDReqConfigLoginField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///告知服务，让其退出
int CFtdcUserApiImpl::ReqSysServerExitTopic(CShfeFtdcReqSysServerExitField *pReqSysServerExit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqSysServerExitTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqSysServerExitField ReqSysServerExitField;
	memcpy(&ReqSysServerExitField, pReqSysServerExit, sizeof(CFTDReqSysServerExitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqSysServerExitField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqSysServerExitTopic,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pReqSysServerExit, &CFTDReqSysServerExitField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///设备配置表
int CFtdcUserApiImpl::ReqQryNetCfgFileTopic(CShfeFtdcReqQryNetCfgFileField *pReqQryNetCfgFile, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetCfgFileTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetCfgFileField ReqQryNetCfgFileField;
	memcpy(&ReqQryNetCfgFileField, pReqQryNetCfgFile, sizeof(CFTDReqQryNetCfgFileField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetCfgFileField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///任务结果规则分析表
int CFtdcUserApiImpl::ReqQryNetMonitorDeviceTaskTopic(CShfeFtdcReqQryNetMonitorDeviceTaskField *pReqQryNetMonitorDeviceTask, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorDeviceTaskTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorDeviceTaskField ReqQryNetMonitorDeviceTaskField;
	memcpy(&ReqQryNetMonitorDeviceTaskField, pReqQryNetMonitorDeviceTask, sizeof(CFTDReqQryNetMonitorDeviceTaskField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorDeviceTaskField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///任务指令指标集表
int CFtdcUserApiImpl::ReqQryNetMonitorTaskInstAttrsTopic(CShfeFtdcReqQryNetMonitorTaskInstAttrsField *pReqQryNetMonitorTaskInstAttrs, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorTaskInstAttrsTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorTaskInstAttrsField ReqQryNetMonitorTaskInstAttrsField;
	memcpy(&ReqQryNetMonitorTaskInstAttrsField, pReqQryNetMonitorTaskInstAttrs, sizeof(CFTDReqQryNetMonitorTaskInstAttrsField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorTaskInstAttrsField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///文件通用操作
int CFtdcUserApiImpl::ReqQryFileGeneralOperTopic(CShfeFtdcReqQryFileGeneralOperField *pReqQryFileGeneralOper, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryFileGeneralOperTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryFileGeneralOperField ReqQryFileGeneralOperField;
	memcpy(&ReqQryFileGeneralOperField, pReqQryFileGeneralOper, sizeof(CFTDReqQryFileGeneralOperField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryFileGeneralOperField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///基线表
int CFtdcUserApiImpl::ReqQryNetBaseLineTopic(CShfeFtdcReqQryNetBaseLineField *pReqQryNetBaseLine, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetBaseLineTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetBaseLineField ReqQryNetBaseLineField;
	memcpy(&ReqQryNetBaseLineField, pReqQryNetBaseLine, sizeof(CFTDReqQryNetBaseLineField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetBaseLineField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///基线任务表
int CFtdcUserApiImpl::ReqQryNetBaseLineTaskTopic(CShfeFtdcReqQryNetBaseLineTaskField *pReqQryNetBaseLineTask, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetBaseLineTaskTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetBaseLineTaskField ReqQryNetBaseLineTaskField;
	memcpy(&ReqQryNetBaseLineTaskField, pReqQryNetBaseLineTask, sizeof(CFTDReqQryNetBaseLineTaskField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetBaseLineTaskField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///基线结果表
int CFtdcUserApiImpl::ReqQryNetBaseLineResultTopic(CShfeFtdcReqQryNetBaseLineResultField *pReqQryNetBaseLineResult, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetBaseLineResultTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetBaseLineResultField ReqQryNetBaseLineResultField;
	memcpy(&ReqQryNetBaseLineResultField, pReqQryNetBaseLineResult, sizeof(CFTDReqQryNetBaseLineResultField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetBaseLineResultField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员链路状态信息表
int CFtdcUserApiImpl::ReqQryNetPartyLinkStatusInfoTopic(CShfeFtdcReqQryNetPartyLinkStatusInfoField *pReqQryNetPartyLinkStatusInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetPartyLinkStatusInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetPartyLinkStatusInfoField ReqQryNetPartyLinkStatusInfoField;
	memcpy(&ReqQryNetPartyLinkStatusInfoField, pReqQryNetPartyLinkStatusInfo, sizeof(CFTDReqQryNetPartyLinkStatusInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetPartyLinkStatusInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员SDH线路明细表
int CFtdcUserApiImpl::ReqQryNetMemberSDHLineInfoTopic(CShfeFtdcReqQryNetMemberSDHLineInfoField *pReqQryNetMemberSDHLineInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMemberSDHLineInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMemberSDHLineInfoField ReqQryNetMemberSDHLineInfoField;
	memcpy(&ReqQryNetMemberSDHLineInfoField, pReqQryNetMemberSDHLineInfo, sizeof(CFTDReqQryNetMemberSDHLineInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMemberSDHLineInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///DDN链路信息表
int CFtdcUserApiImpl::ReqQryNetDDNLinkInfoTopic(CShfeFtdcReqQryNetDDNLinkInfoField *pReqQryNetDDNLinkInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetDDNLinkInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetDDNLinkInfoField ReqQryNetDDNLinkInfoField;
	memcpy(&ReqQryNetDDNLinkInfoField, pReqQryNetDDNLinkInfo, sizeof(CFTDReqQryNetDDNLinkInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetDDNLinkInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///非会员线路使用信息
int CFtdcUserApiImpl::ReqQryNetPseudMemberLinkInfoTopic(CShfeFtdcReqQryNetPseudMemberLinkInfoField *pReqQryNetPseudMemberLinkInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetPseudMemberLinkInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetPseudMemberLinkInfoField ReqQryNetPseudMemberLinkInfoField;
	memcpy(&ReqQryNetPseudMemberLinkInfoField, pReqQryNetPseudMemberLinkInfo, sizeof(CFTDReqQryNetPseudMemberLinkInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetPseudMemberLinkInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///远端设备信息
int CFtdcUserApiImpl::ReqQryOuterDeviceInfTopic(CShfeFtdcReqQryOuterDeviceInfField *pReqQryOuterDeviceInf, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryOuterDeviceInfTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryOuterDeviceInfField ReqQryOuterDeviceInfField;
	memcpy(&ReqQryOuterDeviceInfField, pReqQryOuterDeviceInf, sizeof(CFTDReqQryOuterDeviceInfField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryOuterDeviceInfField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///本地ping结果
int CFtdcUserApiImpl::ReqQryNetLocalPingResultInfoTopic(CShfeFtdcReqQryNetLocalPingResultInfoField *pReqQryNetLocalPingResultInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetLocalPingResultInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetLocalPingResultInfoField ReqQryNetLocalPingResultInfoField;
	memcpy(&ReqQryNetLocalPingResultInfoField, pReqQryNetLocalPingResultInfo, sizeof(CFTDReqQryNetLocalPingResultInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetLocalPingResultInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///远程ping结果
int CFtdcUserApiImpl::ReqQryNetRomotePingResultInfoTopic(CShfeFtdcReqQryNetRomotePingResultInfoField *pReqQryNetRomotePingResultInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetRomotePingResultInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetRomotePingResultInfoField ReqQryNetRomotePingResultInfoField;
	memcpy(&ReqQryNetRomotePingResultInfoField, pReqQryNetRomotePingResultInfo, sizeof(CFTDReqQryNetRomotePingResultInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetRomotePingResultInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///系统内部级联关系
int CFtdcUserApiImpl::ReqQrySysInternalTopologyTopic(CShfeFtdcReqQrySysInternalTopologyField *pReqQrySysInternalTopology, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySysInternalTopologyTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySysInternalTopologyField ReqQrySysInternalTopologyField;
	memcpy(&ReqQrySysInternalTopologyField, pReqQrySysInternalTopology, sizeof(CFTDReqQrySysInternalTopologyField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySysInternalTopologyField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///请求会员链路费用表
int CFtdcUserApiImpl::ReqQryMemberLinkCostTopic(CShfeFtdcReqQryMemberLinkCostField *pReqQryMemberLinkCost, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMemberLinkCostTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMemberLinkCostField ReqQryMemberLinkCostField;
	memcpy(&ReqQryMemberLinkCostField, pReqQryMemberLinkCost, sizeof(CFTDReqQryMemberLinkCostField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMemberLinkCostField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///请求会员链路月租表
int CFtdcUserApiImpl::ReqQryNetPartylinkMonthlyRentTopic(CShfeFtdcReqQryNetPartylinkMonthlyRentField *pReqQryNetPartylinkMonthlyRent, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetPartylinkMonthlyRentTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetPartylinkMonthlyRentField ReqQryNetPartylinkMonthlyRentField;
	memcpy(&ReqQryNetPartylinkMonthlyRentField, pReqQryNetPartylinkMonthlyRent, sizeof(CFTDReqQryNetPartylinkMonthlyRentField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetPartylinkMonthlyRentField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///请求非会员链路表信息
int CFtdcUserApiImpl::ReqQryNetNonPartyLinkInfoTopic(CShfeFtdcReqQryNetNonPartyLinkInfoField *pReqQryNetNonPartyLinkInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetNonPartyLinkInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetNonPartyLinkInfoField ReqQryNetNonPartyLinkInfoField;
	memcpy(&ReqQryNetNonPartyLinkInfoField, pReqQryNetNonPartyLinkInfo, sizeof(CFTDReqQryNetNonPartyLinkInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetNonPartyLinkInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///请求配置信息
int CFtdcUserApiImpl::ReqQryMonConfigInfo(CShfeFtdcReqQryMonConfigInfoField *pReqQryMonConfigInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonConfigInfo, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonConfigInfoField ReqQryMonConfigInfoField;
	memcpy(&ReqQryMonConfigInfoField, pReqQryMonConfigInfo, sizeof(CFTDReqQryMonConfigInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonConfigInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///服务连接请求
int CFtdcUserApiImpl::ReqMonServiceConnect(CShfeFtdcReqMonServiceConnectField *pReqMonServiceConnect, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqMonServiceConnect, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqMonServiceConnectField ReqMonServiceConnectField;
	memcpy(&ReqMonServiceConnectField, pReqMonServiceConnect, sizeof(CFTDReqMonServiceConnectField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqMonServiceConnectField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqMonServiceConnect,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pReqMonServiceConnect, &CFTDReqMonServiceConnectField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///服务的当前状态查询
int CFtdcUserApiImpl::ReqQryMonServiceStatus(CShfeFtdcReqQryMonServiceStatusField *pReqQryMonServiceStatus, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonServiceStatus, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonServiceStatusField ReqQryMonServiceStatusField;
	memcpy(&ReqQryMonServiceStatusField, pReqQryMonServiceStatus, sizeof(CFTDReqQryMonServiceStatusField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonServiceStatusField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///探针任务配置查询请求
int CFtdcUserApiImpl::ReqQryMonProbeTask(CShfeFtdcReqQryMonProbeTaskField *pReqQryMonProbeTask, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonProbeTask, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonProbeTaskField ReqQryMonProbeTaskField;
	memcpy(&ReqQryMonProbeTaskField, pReqQryMonProbeTask, sizeof(CFTDReqQryMonProbeTaskField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonProbeTaskField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///监控系统指标查询请求
int CFtdcUserApiImpl::ReqQryMonObjectAttr(CShfeFtdcReqQryMonObjectAttrField *pReqQryMonObjectAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonObjectAttr, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonObjectAttrField ReqQryMonObjectAttrField;
	memcpy(&ReqQryMonObjectAttrField, pReqQryMonObjectAttr, sizeof(CFTDReqQryMonObjectAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonObjectAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///监控系统Syslog事件查询请求
int CFtdcUserApiImpl::ReqQryMonSyslogEvent(CShfeFtdcReqQryMonSyslogEventField *pReqQryMonSyslogEvent, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonSyslogEvent, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonSyslogEventField ReqQryMonSyslogEventField;
	memcpy(&ReqQryMonSyslogEventField, pReqQryMonSyslogEvent, sizeof(CFTDReqQryMonSyslogEventField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonSyslogEventField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///文件读取偏移量查询请求
int CFtdcUserApiImpl::ReqQryMonFileOffset(CShfeFtdcReqQryMonFileOffsetField *pReqQryMonFileOffset, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonFileOffset, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonFileOffsetField ReqQryMonFileOffsetField;
	memcpy(&ReqQryMonFileOffsetField, pReqQryMonFileOffset, sizeof(CFTDReqQryMonFileOffsetField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonFileOffsetField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///文件内容查询请求
int CFtdcUserApiImpl::ReqQryMonFileContent(CShfeFtdcReqQryMonFileContentField *pReqQryMonFileContent, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonFileContent, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonFileContentField ReqQryMonFileContentField;
	memcpy(&ReqQryMonFileContentField, pReqQryMonFileContent, sizeof(CFTDReqQryMonFileContentField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonFileContentField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机基础环境信息查询请求
int CFtdcUserApiImpl::ReqQryMonHostBasicEnv(CShfeFtdcReqQryMonHostBasicEnvField *pReqQryMonHostBasicEnv, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonHostBasicEnv, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonHostBasicEnvField ReqQryMonHostBasicEnvField;
	memcpy(&ReqQryMonHostBasicEnvField, pReqQryMonHostBasicEnv, sizeof(CFTDReqQryMonHostBasicEnvField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonHostBasicEnvField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机基础网络信息查询
int CFtdcUserApiImpl::ReqQryMonHostNetworkEnv(CShfeFtdcReqQryMonHostNetworkEnvField *pReqQryMonHostNetworkEnv, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonHostNetworkEnv, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonHostNetworkEnvField ReqQryMonHostNetworkEnvField;
	memcpy(&ReqQryMonHostNetworkEnvField, pReqQryMonHostNetworkEnv, sizeof(CFTDReqQryMonHostNetworkEnvField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonHostNetworkEnvField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机文件系统信息查询
int CFtdcUserApiImpl::ReqQryMonHostFileSysEnv(CShfeFtdcReqQryMonHostFileSysEnvField *pReqQryMonHostFileSysEnv, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonHostFileSysEnv, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonHostFileSysEnvField ReqQryMonHostFileSysEnvField;
	memcpy(&ReqQryMonHostFileSysEnvField, pReqQryMonHostFileSysEnv, sizeof(CFTDReqQryMonHostFileSysEnvField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonHostFileSysEnvField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机交换分区信息查询
int CFtdcUserApiImpl::ReqQryMonHostSwapEnv(CShfeFtdcReqQryMonHostSwapEnvField *pReqQryMonHostSwapEnv, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonHostSwapEnv, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonHostSwapEnvField ReqQryMonHostSwapEnvField;
	memcpy(&ReqQryMonHostSwapEnvField, pReqQryMonHostSwapEnv, sizeof(CFTDReqQryMonHostSwapEnvField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonHostSwapEnvField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机的CPU信息指标信息请求
int CFtdcUserApiImpl::ReqQryMonHostCPUAttr(CShfeFtdcReqQryMonHostCPUAttrField *pReqQryMonHostCPUAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonHostCPUAttr, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonHostCPUAttrField ReqQryMonHostCPUAttrField;
	memcpy(&ReqQryMonHostCPUAttrField, pReqQryMonHostCPUAttr, sizeof(CFTDReqQryMonHostCPUAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonHostCPUAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机的Memory使用信息请求
int CFtdcUserApiImpl::ReqQryMonHostMemAttr(CShfeFtdcReqQryMonHostMemAttrField *pReqQryMonHostMemAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonHostMemAttr, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonHostMemAttrField ReqQryMonHostMemAttrField;
	memcpy(&ReqQryMonHostMemAttrField, pReqQryMonHostMemAttr, sizeof(CFTDReqQryMonHostMemAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonHostMemAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机的FileSystem使用信息请求
int CFtdcUserApiImpl::ReqQryMonHostFileSystemAttr(CShfeFtdcReqQryMonHostFileSystemAttrField *pReqQryMonHostFileSystemAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonHostFileSystemAttr, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonHostFileSystemAttrField ReqQryMonHostFileSystemAttrField;
	memcpy(&ReqQryMonHostFileSystemAttrField, pReqQryMonHostFileSystemAttr, sizeof(CFTDReqQryMonHostFileSystemAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonHostFileSystemAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机的用户信息请求
int CFtdcUserApiImpl::ReqQryMonHostUserInfo(CShfeFtdcReqQryMonHostUserInfoField *pReqQryMonHostUserInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonHostUserInfo, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonHostUserInfoField ReqQryMonHostUserInfoField;
	memcpy(&ReqQryMonHostUserInfoField, pReqQryMonHostUserInfo, sizeof(CFTDReqQryMonHostUserInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonHostUserInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机的在线用户信息请求
int CFtdcUserApiImpl::ReqQryMonHostOnlineUserInfo(CShfeFtdcReqQryMonHostOnlineUserInfoField *pReqQryMonHostOnlineUserInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonHostOnlineUserInfo, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonHostOnlineUserInfoField ReqQryMonHostOnlineUserInfoField;
	memcpy(&ReqQryMonHostOnlineUserInfoField, pReqQryMonHostOnlineUserInfo, sizeof(CFTDReqQryMonHostOnlineUserInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonHostOnlineUserInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机的network使用信息请求
int CFtdcUserApiImpl::ReqQryMonHostNetworkAttr(CShfeFtdcReqQryMonHostNetworkAttrField *pReqQryMonHostNetworkAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonHostNetworkAttr, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonHostNetworkAttrField ReqQryMonHostNetworkAttrField;
	memcpy(&ReqQryMonHostNetworkAttrField, pReqQryMonHostNetworkAttr, sizeof(CFTDReqQryMonHostNetworkAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonHostNetworkAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机的系统状态信息请求
int CFtdcUserApiImpl::ReqQryMonHostStatInfo(CShfeFtdcReqQryMonHostStatInfoField *pReqQryMonHostStatInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonHostStatInfo, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonHostStatInfoField ReqQryMonHostStatInfoField;
	memcpy(&ReqQryMonHostStatInfoField, pReqQryMonHostStatInfo, sizeof(CFTDReqQryMonHostStatInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonHostStatInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机的磁盘IO信息请求
int CFtdcUserApiImpl::ReqQryMonHostDiskIOAttr(CShfeFtdcReqQryMonHostDiskIOAttrField *pReqQryMonHostDiskIOAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonHostDiskIOAttr, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonHostDiskIOAttrField ReqQryMonHostDiskIOAttrField;
	memcpy(&ReqQryMonHostDiskIOAttrField, pReqQryMonHostDiskIOAttr, sizeof(CFTDReqQryMonHostDiskIOAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonHostDiskIOAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机的路由信息请求
int CFtdcUserApiImpl::ReqQryMonHostRouterInfo(CShfeFtdcReqQryMonHostRouterInfoField *pReqQryMonHostRouterInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonHostRouterInfo, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonHostRouterInfoField ReqQryMonHostRouterInfoField;
	memcpy(&ReqQryMonHostRouterInfoField, pReqQryMonHostRouterInfo, sizeof(CFTDReqQryMonHostRouterInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonHostRouterInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机的进程信息请求
int CFtdcUserApiImpl::ReqQryMonHostProcessInfo(CShfeFtdcReqQryMonHostProcessInfoField *pReqQryMonHostProcessInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonHostProcessInfo, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonHostProcessInfoField ReqQryMonHostProcessInfoField;
	memcpy(&ReqQryMonHostProcessInfoField, pReqQryMonHostProcessInfo, sizeof(CFTDReqQryMonHostProcessInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonHostProcessInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///客户端临时SP查询请求
int CFtdcUserApiImpl::ReqQryMonSPQuery(CShfeFtdcReqQryMonSPQueryField *pReqQryMonSPQuery, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonSPQuery, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonSPQueryField ReqQryMonSPQueryField;
	memcpy(&ReqQryMonSPQueryField, pReqQryMonSPQuery, sizeof(CFTDReqQryMonSPQueryField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonSPQueryField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///服务版本信息请求
int CFtdcUserApiImpl::ReqServiceVersion(CShfeFtdcReqServiceVersionField *pReqServiceVersion, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqServiceVersion, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqServiceVersionField ReqServiceVersionField;
	memcpy(&ReqServiceVersionField, pReqServiceVersion, sizeof(CFTDReqServiceVersionField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqServiceVersionField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqServiceVersion,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pReqServiceVersion, &CFTDReqServiceVersionField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///服务应用程序请求
int CFtdcUserApiImpl::ReqServiceProgram(CShfeFtdcReqServiceProgramField *pReqServiceProgram, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqServiceProgram, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqServiceProgramField ReqServiceProgramField;
	memcpy(&ReqServiceProgramField, pReqServiceProgram, sizeof(CFTDReqServiceProgramField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqServiceProgramField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqServiceProgram,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pReqServiceProgram, &CFTDReqServiceProgramField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///升级服务获取状态
int CFtdcUserApiImpl::ReqUpdateState(CShfeFtdcReqUpdateStateField *pReqUpdateState, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqUpdateState, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqUpdateStateField ReqUpdateStateField;
	memcpy(&ReqUpdateStateField, pReqUpdateState, sizeof(CFTDReqUpdateStateField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqUpdateStateField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqUpdateState,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pReqUpdateState, &CFTDReqUpdateStateField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///订阅请求
int CFtdcUserApiImpl::ReqSubscribe(CShfeFtdcReqSubscribeField *pReqSubscribe, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqSubscribe, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqSubscribeField ReqSubscribeField;
	memcpy(&ReqSubscribeField, pReqSubscribe, sizeof(CFTDReqSubscribeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqSubscribeField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqSubscribe,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pReqSubscribe, &CFTDReqSubscribeField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///取消订阅请求
int CFtdcUserApiImpl::ReqCancelSubscribe(CShfeFtdcReqSubscribeField *pReqSubscribe, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqCancelSubscribe, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqSubscribeField ReqSubscribeField;
	memcpy(&ReqSubscribeField, pReqSubscribe, sizeof(CFTDReqSubscribeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqSubscribeField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqCancelSubscribe,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pReqSubscribe, &CFTDReqSubscribeField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///用于通知目标服务文件已发送成功
int CFtdcUserApiImpl::ReqFileSendSuccess(CShfeFtdcReqFileSendSuccessField *pReqFileSendSuccess, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqFileSendSuccess, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqFileSendSuccessField ReqFileSendSuccessField;
	memcpy(&ReqFileSendSuccessField, pReqFileSendSuccess, sizeof(CFTDReqFileSendSuccessField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqFileSendSuccessField);

	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,ReqFileSendSuccess,%d,", szTimeBuffer, nRet);
		FIELD_TO_STRING((char *)pReqFileSendSuccess, &CFTDReqFileSendSuccessField::m_Describe, m_fpRequstDump);
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
	m_mutexAction.UnLock();
	
	return nRet;
}
///tomcat信息查询
int CFtdcUserApiImpl::ReqQryMonTomcatInfo(CShfeFtdcReqQryMonTomcatInfoField *pReqQryMonTomcatInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonTomcatInfo, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonTomcatInfoField ReqQryMonTomcatInfoField;
	memcpy(&ReqQryMonTomcatInfoField, pReqQryMonTomcatInfo, sizeof(CFTDReqQryMonTomcatInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonTomcatInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///虚拟机信息查询
int CFtdcUserApiImpl::ReqQryMonVMInfo(CShfeFtdcReqQryMonVMInfoField *pReqQryMonVMInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonVMInfo, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonVMInfoField ReqQryMonVMInfoField;
	memcpy(&ReqQryMonVMInfoField, pReqQryMonVMInfo, sizeof(CFTDReqQryMonVMInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonVMInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///系统属性信息查询
int CFtdcUserApiImpl::ReqQryMonPropertyInfo(CShfeFtdcReqQryMonPropertyInfoField *pReqQryMonPropertyInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonPropertyInfo, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonPropertyInfoField ReqQryMonPropertyInfoField;
	memcpy(&ReqQryMonPropertyInfoField, pReqQryMonPropertyInfo, sizeof(CFTDReqQryMonPropertyInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonPropertyInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///系统内存池信息查询
int CFtdcUserApiImpl::ReqQryMonMemPoolInfo(CShfeFtdcReqQryMonMemPoolInfoField *pReqQryMonMemPoolInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonMemPoolInfo, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonMemPoolInfoField ReqQryMonMemPoolInfoField;
	memcpy(&ReqQryMonMemPoolInfoField, pReqQryMonMemPoolInfo, sizeof(CFTDReqQryMonMemPoolInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonMemPoolInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///连接信息查询
int CFtdcUserApiImpl::ReqQryMonConnectionInfo(CShfeFtdcReqQryMonConnectionInfoField *pReqQryMonConnectionInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonConnectionInfo, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonConnectionInfoField ReqQryMonConnectionInfoField;
	memcpy(&ReqQryMonConnectionInfoField, pReqQryMonConnectionInfo, sizeof(CFTDReqQryMonConnectionInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonConnectionInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///无效报单查询
int CFtdcUserApiImpl::ReqQryInvalidateOrderTopic(CShfeFtdcReqQryInvalidateOrderField *pReqQryInvalidateOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryInvalidateOrderTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryInvalidateOrderField ReqQryInvalidateOrderField;
	memcpy(&ReqQryInvalidateOrderField, pReqQryInvalidateOrder, sizeof(CFTDReqQryInvalidateOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryInvalidateOrderField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///报单状态查询
int CFtdcUserApiImpl::ReqQryOrderStatusTopic(CShfeFtdcReqQryOrderStatusField *pReqQryOrderStatus, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryOrderStatusTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryOrderStatusField ReqQryOrderStatusField;
	memcpy(&ReqQryOrderStatusField, pReqQryOrderStatus, sizeof(CFTDReqQryOrderStatusField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryOrderStatusField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///报单成交查询
int CFtdcUserApiImpl::ReqQryBargainOrderTopic(CShfeFtdcReqQryBargainOrderField *pReqQryBargainOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryBargainOrderTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryBargainOrderField ReqQryBargainOrderField;
	memcpy(&ReqQryBargainOrderField, pReqQryBargainOrder, sizeof(CFTDReqQryBargainOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryBargainOrderField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///合约基本属性查询
int CFtdcUserApiImpl::ReqQryInstPropertyTopic(CShfeFtdcReqQryInstPropertyField *pReqQryInstProperty, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryInstPropertyTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryInstPropertyField ReqQryInstPropertyField;
	memcpy(&ReqQryInstPropertyField, pReqQryInstProperty, sizeof(CFTDReqQryInstPropertyField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryInstPropertyField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///合约保证金率查询
int CFtdcUserApiImpl::ReqQryMarginRateTopic(CShfeFtdcReqQryMarginRateField *pReqQryMarginRate, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMarginRateTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMarginRateField ReqQryMarginRateField;
	memcpy(&ReqQryMarginRateField, pReqQryMarginRate, sizeof(CFTDReqQryMarginRateField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMarginRateField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///合约涨跌停板查询
int CFtdcUserApiImpl::ReqQryPriceLimitTopic(CShfeFtdcReqQryPriceLimitField *pReqQryPriceLimit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPriceLimitTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryPriceLimitField ReqQryPriceLimitField;
	memcpy(&ReqQryPriceLimitField, pReqQryPriceLimit, sizeof(CFTDReqQryPriceLimitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryPriceLimitField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员限仓查询
int CFtdcUserApiImpl::ReqQryPartPosiLimitTopic(CShfeFtdcReqQryPartPosiLimitField *pReqQryPartPosiLimit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPartPosiLimitTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryPartPosiLimitField ReqQryPartPosiLimitField;
	memcpy(&ReqQryPartPosiLimitField, pReqQryPartPosiLimit, sizeof(CFTDReqQryPartPosiLimitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryPartPosiLimitField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///客户限仓查询
int CFtdcUserApiImpl::ReqQryClientPosiLimitTopic(CShfeFtdcReqQryClientPosiLimitField *pReqQryClientPosiLimit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryClientPosiLimitTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryClientPosiLimitField ReqQryClientPosiLimitField;
	memcpy(&ReqQryClientPosiLimitField, pReqQryClientPosiLimit, sizeof(CFTDReqQryClientPosiLimitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryClientPosiLimitField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///特殊客户限仓查询
int CFtdcUserApiImpl::ReqQrySpecialPosiLimitTopic(CShfeFtdcReqQrySpecialPosiLimitField *pReqQrySpecialPosiLimit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySpecialPosiLimitTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySpecialPosiLimitField ReqQrySpecialPosiLimitField;
	memcpy(&ReqQrySpecialPosiLimitField, pReqQrySpecialPosiLimit, sizeof(CFTDReqQrySpecialPosiLimitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySpecialPosiLimitField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///账户出入金查询
int CFtdcUserApiImpl::ReqQryTransactionChgTopic(CShfeFtdcReqQryTransactionChgField *pReqQryTransactionChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTransactionChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTransactionChgField ReqQryTransactionChgField;
	memcpy(&ReqQryTransactionChgField, pReqQryTransactionChg, sizeof(CFTDReqQryTransactionChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTransactionChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///客户数据变动查询
int CFtdcUserApiImpl::ReqQryClientChgTopic(CShfeFtdcReqQryClientChgField *pReqQryClientChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryClientChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryClientChgField ReqQryClientChgField;
	memcpy(&ReqQryClientChgField, pReqQryClientChg, sizeof(CFTDReqQryClientChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryClientChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员客户对照变动查询
int CFtdcUserApiImpl::ReqQryPartClientChgTopic(CShfeFtdcReqQryPartClientChgField *pReqQryPartClientChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPartClientChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryPartClientChgField ReqQryPartClientChgField;
	memcpy(&ReqQryPartClientChgField, pReqQryPartClientChg, sizeof(CFTDReqQryPartClientChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryPartClientChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///限仓数据变动查询
int CFtdcUserApiImpl::ReqQryPosiLimitChgTopic(CShfeFtdcReqQryPosiLimitChgField *pReqQryPosiLimitChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPosiLimitChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryPosiLimitChgField ReqQryPosiLimitChgField;
	memcpy(&ReqQryPosiLimitChgField, pReqQryPosiLimitChg, sizeof(CFTDReqQryPosiLimitChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryPosiLimitChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///保值额度变动查询
int CFtdcUserApiImpl::ReqQryHedgeDetailChgTopic(CShfeFtdcReqQryHedgeDetailChgField *pReqQryHedgeDetailChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHedgeDetailChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryHedgeDetailChgField ReqQryHedgeDetailChgField;
	memcpy(&ReqQryHedgeDetailChgField, pReqQryHedgeDetailChg, sizeof(CFTDReqQryHedgeDetailChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryHedgeDetailChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员变动查询
int CFtdcUserApiImpl::ReqQryParticipantChgTopic(CShfeFtdcReqQryParticipantChgField *pReqQryParticipantChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryParticipantChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryParticipantChgField ReqQryParticipantChgField;
	memcpy(&ReqQryParticipantChgField, pReqQryParticipantChg, sizeof(CFTDReqQryParticipantChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryParticipantChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///保证金率变动查询
int CFtdcUserApiImpl::ReqQryMarginRateChgTopic(CShfeFtdcReqQryMarginRateChgField *pReqQryMarginRateChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMarginRateChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMarginRateChgField ReqQryMarginRateChgField;
	memcpy(&ReqQryMarginRateChgField, pReqQryMarginRateChg, sizeof(CFTDReqQryMarginRateChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMarginRateChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///IP地址变动查询
int CFtdcUserApiImpl::ReqQryUserIpChgTopic(CShfeFtdcReqQryUserIpChgField *pReqQryUserIpChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryUserIpChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryUserIpChgField ReqQryUserIpChgField;
	memcpy(&ReqQryUserIpChgField, pReqQryUserIpChg, sizeof(CFTDReqQryUserIpChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryUserIpChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///限仓数据变动查询
int CFtdcUserApiImpl::ReqQryClientPosiLimitChgTopic(CShfeFtdcReqQryClientPosiLimitChgField *pReqQryClientPosiLimitChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryClientPosiLimitChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryClientPosiLimitChgField ReqQryClientPosiLimitChgField;
	memcpy(&ReqQryClientPosiLimitChgField, pReqQryClientPosiLimitChg, sizeof(CFTDReqQryClientPosiLimitChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryClientPosiLimitChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///限仓数据变动查询
int CFtdcUserApiImpl::ReqQrySpecPosiLimitChgTopic(CShfeFtdcReqQrySpecPosiLimitChgField *pReqQrySpecPosiLimitChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySpecPosiLimitChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySpecPosiLimitChgField ReqQrySpecPosiLimitChgField;
	memcpy(&ReqQrySpecPosiLimitChgField, pReqQrySpecPosiLimitChg, sizeof(CFTDReqQrySpecPosiLimitChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySpecPosiLimitChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易系统前置统计查询
int CFtdcUserApiImpl::ReqQryFrontStatTopic(CShfeFtdcReqQryFrontStatField *pReqQryFrontStat, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryFrontStatTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryFrontStatField ReqQryFrontStatField;
	memcpy(&ReqQryFrontStatField, pReqQryFrontStat, sizeof(CFTDReqQryFrontStatField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryFrontStatField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///管理平台初始化信息查询
int CFtdcUserApiImpl::ReqQryParticipantInitTopic(CShfeFtdcReqQryParticipantInitField *pReqQryParticipantInit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryParticipantInitTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryParticipantInitField ReqQryParticipantInitField;
	memcpy(&ReqQryParticipantInitField, pReqQryParticipantInit, sizeof(CFTDReqQryParticipantInitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryParticipantInitField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///管理平台初始化信息查询
int CFtdcUserApiImpl::ReqQryUserInitTopic(CShfeFtdcReqQryUserInitField *pReqQryUserInit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryUserInitTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryUserInitField ReqQryUserInitField;
	memcpy(&ReqQryUserInitField, pReqQryUserInit, sizeof(CFTDReqQryUserInitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryUserInitField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///请求约状态切换数据
int CFtdcUserApiImpl::ReqQryInstrumentStatusTopic(CShfeFtdcReqQryInstrumentStatusField *pReqQryInstrumentStatus, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryInstrumentStatusTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryInstrumentStatusField ReqQryInstrumentStatusField;
	memcpy(&ReqQryInstrumentStatusField, pReqQryInstrumentStatus, sizeof(CFTDReqQryInstrumentStatusField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryInstrumentStatusField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///请求合约交易节信息
int CFtdcUserApiImpl::ReqQryCurrTradingSegmentAttrTopic(CShfeFtdcReqQryCurrTradingSegmentAttrField *pReqQryCurrTradingSegmentAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryCurrTradingSegmentAttrTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryCurrTradingSegmentAttrField ReqQryCurrTradingSegmentAttrField;
	memcpy(&ReqQryCurrTradingSegmentAttrField, pReqQryCurrTradingSegmentAttr, sizeof(CFTDReqQryCurrTradingSegmentAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryCurrTradingSegmentAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易系统登录信息查询
int CFtdcUserApiImpl::ReqQryTradeUserLoginInfoTopic(CShfeFtdcReqQryTradeUserLoginInfoField *pReqQryTradeUserLoginInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTradeUserLoginInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTradeUserLoginInfoField ReqQryTradeUserLoginInfoField;
	memcpy(&ReqQryTradeUserLoginInfoField, pReqQryTradeUserLoginInfo, sizeof(CFTDReqQryTradeUserLoginInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTradeUserLoginInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员交易查询
int CFtdcUserApiImpl::ReqQryPartTradeTopic(CShfeFtdcReqQryPartTradeField *pReqQryPartTrade, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPartTradeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryPartTradeField ReqQryPartTradeField;
	memcpy(&ReqQryPartTradeField, pReqQryPartTrade, sizeof(CFTDReqQryPartTradeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryPartTradeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员席位交易状态
int CFtdcUserApiImpl::ReqQryParticTradeOrderStatesTopic(CShfeFtdcReqQryParticTradeOrderStatesField *pReqQryParticTradeOrderStates, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryParticTradeOrderStatesTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryParticTradeOrderStatesField ReqQryParticTradeOrderStatesField;
	memcpy(&ReqQryParticTradeOrderStatesField, pReqQryParticTradeOrderStates, sizeof(CFTDReqQryParticTradeOrderStatesField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryParticTradeOrderStatesField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///获得监控对象信息查询
int CFtdcUserApiImpl::ReqQryMonitor2ObjectTopic(CShfeFtdcReqQryMonitor2ObjectField *pReqQryMonitor2Object, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonitor2ObjectTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonitor2ObjectField ReqQryMonitor2ObjectField;
	memcpy(&ReqQryMonitor2ObjectField, pReqQryMonitor2Object, sizeof(CFTDReqQryMonitor2ObjectField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonitor2ObjectField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机环境信息查询
int CFtdcUserApiImpl::ReqQryMonHostCommonEnvTopic(CShfeFtdcReqQryMonHostCommonEnvField *pReqQryMonHostCommonEnv, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonHostCommonEnvTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonHostCommonEnvField ReqQryMonHostCommonEnvField;
	memcpy(&ReqQryMonHostCommonEnvField, pReqQryMonHostCommonEnv, sizeof(CFTDReqQryMonHostCommonEnvField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonHostCommonEnvField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///获取业务进程和主机关系
int CFtdcUserApiImpl::ReqQryMonOidHostRationalTopic(CShfeFtdcReqQryMonOidHostRationalField *pReqQryMonOidHostRational, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonOidHostRationalTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonOidHostRationalField ReqQryMonOidHostRationalField;
	memcpy(&ReqQryMonOidHostRationalField, pReqQryMonOidHostRational, sizeof(CFTDReqQryMonOidHostRationalField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonOidHostRationalField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///对象关系查询
int CFtdcUserApiImpl::ReqQryMonOidRelationTopic(CShfeFtdcReqQryMonOidRelationField *pReqQryMonOidRelation, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonOidRelationTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonOidRelationField ReqQryMonOidRelationField;
	memcpy(&ReqQryMonOidRelationField, pReqQryMonOidRelation, sizeof(CFTDReqQryMonOidRelationField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonOidRelationField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}

void CFtdcUserApiImpl::HandleResponse(CFTDCPackage *pMessage, WORD nSequenceSeries)
{

	switch(pMessage->GetTID()) {
	///错误应答
	case FTD_TID_RspError:
		OnRspError(pMessage, nSequenceSeries);
		break;
	///用户登录应答
	case FTD_TID_RspUserLogin:
		OnRspUserLogin(pMessage, nSequenceSeries);
		break;
	///用户退出应答
	case FTD_TID_RspUserLogout:
		OnRspUserLogout(pMessage, nSequenceSeries);
		break;
	///报单录入应答
	case FTD_TID_RspOrderInsert:
		OnRspOrderInsert(pMessage, nSequenceSeries);
		break;
	///报单操作应答
	case FTD_TID_RspOrderAction:
		OnRspOrderAction(pMessage, nSequenceSeries);
		break;
	///报价录入应答
	case FTD_TID_RspQuoteInsert:
		OnRspQuoteInsert(pMessage, nSequenceSeries);
		break;
	///报价操作应答
	case FTD_TID_RspQuoteAction:
		OnRspQuoteAction(pMessage, nSequenceSeries);
		break;
	///OTC报单录入应答
	case FTD_TID_RspOTCOrderInsert:
		OnRspOTCOrderInsert(pMessage, nSequenceSeries);
		break;
	///用户密码修改应答
	case FTD_TID_RspUserPasswordUpdate:
		OnRspUserPasswordUpdate(pMessage, nSequenceSeries);
		break;
	///执行宣告录入应答
	case FTD_TID_RspExecOrderInsert:
		OnRspExecOrderInsert(pMessage, nSequenceSeries);
		break;
	///执行宣告操作应答
	case FTD_TID_RspExecOrderAction:
		OnRspExecOrderAction(pMessage, nSequenceSeries);
		break;
	///管理报单录入应答
	case FTD_TID_RspAdminOrderInsert:
		OnRspAdminOrderInsert(pMessage, nSequenceSeries);
		break;
	///非标组合报单录入应答
	case FTD_TID_RspCombOrderInsert:
		OnRspCombOrderInsert(pMessage, nSequenceSeries);
		break;
	///订阅主题应答
	case FTD_TID_RspSubscribeTopic:
		OnRspSubscribeTopic(pMessage, nSequenceSeries);
		break;
	///交易所公告请求应答
	case FTD_TID_RspBulletin:
		OnRspBulletin(pMessage, nSequenceSeries);
		break;
	///交易所公告信息应答
	case FTD_TID_RspInformation:
		OnRspInformation(pMessage, nSequenceSeries);
		break;
	///合约交易状态改变应答
	case FTD_TID_RspInstrumentStatusUpdate:
		OnRspInstrumentStatusUpdate(pMessage, nSequenceSeries);
		break;
	///强制用户退出应答
	case FTD_TID_RspForceUserExit:
		OnRspForceUserExit(pMessage, nSequenceSeries);
		break;
	///用户会话删除应答
	case FTD_TID_RspForceUserLogout:
		OnRspForceUserLogout(pMessage, nSequenceSeries);
		break;
	///交易所数据同步状态改变应答
	case FTD_TID_RspExchangeDataSyncStatusUpdate:
		OnRspExchangeDataSyncStatusUpdate(pMessage, nSequenceSeries);
		break;
	///结算组数据同步状态改变应答
	case FTD_TID_RspSGDataSyncStatusUpdate:
		OnRspSGDataSyncStatusUpdate(pMessage, nSequenceSeries);
		break;
	///会员资金查询应答
	case FTD_TID_RspQryPartAccount:
		OnRspQryPartAccount(pMessage, nSequenceSeries);
		break;
	///报单查询应答
	case FTD_TID_RspQryOrder:
		OnRspQryOrder(pMessage, nSequenceSeries);
		break;
	///报价查询应答
	case FTD_TID_RspQryQuote:
		OnRspQryQuote(pMessage, nSequenceSeries);
		break;
	///成交单查询应答
	case FTD_TID_RspQryTrade:
		OnRspQryTrade(pMessage, nSequenceSeries);
		break;
	///会员客户查询应答
	case FTD_TID_RspQryClient:
		OnRspQryClient(pMessage, nSequenceSeries);
		break;
	///会员持仓查询应答
	case FTD_TID_RspQryPartPosition:
		OnRspQryPartPosition(pMessage, nSequenceSeries);
		break;
	///客户持仓查询应答
	case FTD_TID_RspQryClientPosition:
		OnRspQryClientPosition(pMessage, nSequenceSeries);
		break;
	///合约查询应答
	case FTD_TID_RspQryInstrument:
		OnRspQryInstrument(pMessage, nSequenceSeries);
		break;
	///合约交易状态查询应答
	case FTD_TID_RspQryInstrumentStatus:
		OnRspQryInstrumentStatus(pMessage, nSequenceSeries);
		break;
	///结算组状态查询应答
	case FTD_TID_RspQrySGDataSyncStatus:
		OnRspQrySGDataSyncStatus(pMessage, nSequenceSeries);
		break;
	///保值额度应答
	case FTD_TID_RspQryHedgeVolume:
		OnRspQryHedgeVolume(pMessage, nSequenceSeries);
		break;
	///信用限额查询应答
	case FTD_TID_RspQryCreditLimit:
		OnRspQryCreditLimit(pMessage, nSequenceSeries);
		break;
	///非标组合报单查询应答
	case FTD_TID_RspQryCombOrder:
		OnRspQryCombOrder(pMessage, nSequenceSeries);
		break;
	///执行宣告查询应答
	case FTD_TID_RspQryExecOrder:
		OnRspQryExecOrder(pMessage, nSequenceSeries);
		break;
	///普通行情查询应答
	case FTD_TID_RspQryMarketData:
		OnRspQryMarketData(pMessage, nSequenceSeries);
		break;
	///交易所公告查询请求应答
	case FTD_TID_RspQryBulletin:
		OnRspQryBulletin(pMessage, nSequenceSeries);
		break;
	///主题查询应答
	case FTD_TID_RspQryTopic:
		OnRspQryTopic(pMessage, nSequenceSeries);
		break;
	///用户在线查询应答
	case FTD_TID_RspQryUserSession:
		OnRspQryUserSession(pMessage, nSequenceSeries);
		break;
	///用户查询应答
	case FTD_TID_RspQryUser:
		OnRspQryUser(pMessage, nSequenceSeries);
		break;
	///会员查询应答
	case FTD_TID_RspQryParticipant:
		OnRspQryParticipant(pMessage, nSequenceSeries);
		break;
	///合约价位查询应答
	case FTD_TID_RspQryMBLMarketData:
		OnRspQryMBLMarketData(pMessage, nSequenceSeries);
		break;
	///信息查询应答
	case FTD_TID_RspQryInformation:
		OnRspQryInformation(pMessage, nSequenceSeries);
		break;
	///成交回报
	case FTD_TID_RtnTrade:
		OnRtnTrade(pMessage, nSequenceSeries);
		break;
	///报单回报
	case FTD_TID_RtnOrder:
		OnRtnOrder(pMessage, nSequenceSeries);
		break;
	///执行宣告回报
	case FTD_TID_RtnExecOrder:
		OnRtnExecOrder(pMessage, nSequenceSeries);
		break;
	///报价回报
	case FTD_TID_RtnQuote:
		OnRtnQuote(pMessage, nSequenceSeries);
		break;
	///非标组合报单回报
	case FTD_TID_RtnCombOrder:
		OnRtnCombOrder(pMessage, nSequenceSeries);
		break;
	///合约交易状态通知
	case FTD_TID_RtnInstrumentStatus:
		OnRtnInstrumentStatus(pMessage, nSequenceSeries);
		break;
	///增加合约通知
	case FTD_TID_RtnInsInstrument:
		OnRtnInsInstrument(pMessage, nSequenceSeries);
		break;
	///删除合约通知
	case FTD_TID_RtnDelInstrument:
		OnRtnDelInstrument(pMessage, nSequenceSeries);
		break;
	///增加合约单腿通知
	case FTD_TID_RtnInsCombinationLeg:
		OnRtnInsCombinationLeg(pMessage, nSequenceSeries);
		break;
	///删除合约单腿通知
	case FTD_TID_RtnDelCombinationLeg:
		OnRtnDelCombinationLeg(pMessage, nSequenceSeries);
		break;
	///别名定义通知
	case FTD_TID_RtnAliasDefine:
		OnRtnAliasDefine(pMessage, nSequenceSeries);
		break;
	///数据流回退通知
	case FTD_TID_RtnFlowMessageCancel:
		OnRtnFlowMessageCancel(pMessage, nSequenceSeries);
		break;
	///公告通知
	case FTD_TID_RtnBulletin:
		OnRtnBulletin(pMessage, nSequenceSeries);
		break;
	///普通行情通知
	case FTD_TID_RtnMarketData:
		OnRtnMarketData(pMessage, nSequenceSeries);
		break;
	///深度行情通知
	case FTD_TID_RtnDepthMarketData:
		OnRtnDepthMarketData(pMessage, nSequenceSeries);
		break;
	///内部分发信息通知
	case FTD_TID_IntlRtnDissemination:
		OnIntlRtnDissemination(pMessage, nSequenceSeries);
		break;
	///内部深度行情通知
	case FTD_TID_IntlRtnDepthMarketData:
		OnIntlRtnDepthMarketData(pMessage, nSequenceSeries);
		break;
	///管理报单通知
	case FTD_TID_RtnAdminOrder:
		OnRtnAdminOrder(pMessage, nSequenceSeries);
		break;
	///报单录入错误回报
	case FTD_TID_ErrRtnOrderInsert:
		OnErrRtnOrderInsert(pMessage, nSequenceSeries);
		break;
	///报单操作错误回报
	case FTD_TID_ErrRtnOrderAction:
		OnErrRtnOrderAction(pMessage, nSequenceSeries);
		break;
	///报价录入错误回报
	case FTD_TID_ErrRtnQuoteInsert:
		OnErrRtnQuoteInsert(pMessage, nSequenceSeries);
		break;
	///报价操作错误回报
	case FTD_TID_ErrRtnQuoteAction:
		OnErrRtnQuoteAction(pMessage, nSequenceSeries);
		break;
	///执行宣告录入错误回报
	case FTD_TID_ErrRtnExecOrderInsert:
		OnErrRtnExecOrderInsert(pMessage, nSequenceSeries);
		break;
	///执行宣告操作错误回报
	case FTD_TID_ErrRtnExecOrderAction:
		OnErrRtnExecOrderAction(pMessage, nSequenceSeries);
		break;
	///非标组合报单录入错误回报
	case FTD_TID_ErrRtnCombOrderInsert:
		OnErrRtnCombOrderInsert(pMessage, nSequenceSeries);
		break;
	///汇率查询应答
	case FTD_TID_RspQryExchangeRate:
		OnRspQryExchangeRate(pMessage, nSequenceSeries);
		break;
	///CPU应答
	case FTD_TID_RspQryTopCpuInfoTopic:
		OnRspQryTopCpuInfoTopic(pMessage, nSequenceSeries);
		break;
	///CPU应答
	case FTD_TID_RtnTopCpuInfoTopic:
		OnRtnTopCpuInfoTopic(pMessage, nSequenceSeries);
		break;
	///Mem应答
	case FTD_TID_RspQryTopMemInfoTopic:
		OnRspQryTopMemInfoTopic(pMessage, nSequenceSeries);
		break;
	///Mem应答
	case FTD_TID_RtnTopMemInfoTopic:
		OnRtnTopMemInfoTopic(pMessage, nSequenceSeries);
		break;
	///process应答
	case FTD_TID_RspQryTopProcessInfoTopic:
		OnRspQryTopProcessInfoTopic(pMessage, nSequenceSeries);
		break;
	///process应答
	case FTD_TID_RtnTopProcessInfoTopic:
		OnRtnTopProcessInfoTopic(pMessage, nSequenceSeries);
		break;
	///filesystem应答
	case FTD_TID_RspQryFileSystemInfoTopic:
		OnRspQryFileSystemInfoTopic(pMessage, nSequenceSeries);
		break;
	///filesystem应答
	case FTD_TID_RtnFileSystemInfoTopic:
		OnRtnFileSystemInfoTopic(pMessage, nSequenceSeries);
		break;
	///network应答
	case FTD_TID_RspQryNetworkInfoTopic:
		OnRspQryNetworkInfoTopic(pMessage, nSequenceSeries);
		break;
	///network应答
	case FTD_TID_RtnNetworkInfoTopic:
		OnRtnNetworkInfoTopic(pMessage, nSequenceSeries);
		break;
	///客户端登录应答
	case FTD_TID_RspQryClientLoginTopic:
		OnRspQryClientLoginTopic(pMessage, nSequenceSeries);
		break;
	///获得监控对象信息应答
	case FTD_TID_RspQryMonitorObjectTopic:
		OnRspQryMonitorObjectTopic(pMessage, nSequenceSeries);
		break;
	///获得监控对象信息应答
	case FTD_TID_RtnMonitorObjectTopic:
		OnRtnMonitorObjectTopic(pMessage, nSequenceSeries);
		break;
	///获得业务进程和主机的对应关系应答
	case FTD_TID_RspQryObjectRationalTopic:
		OnRspQryObjectRationalTopic(pMessage, nSequenceSeries);
		break;
	///获得业务进程和主机的对应关系应答
	case FTD_TID_RtnObjectRationalTopic:
		OnRtnObjectRationalTopic(pMessage, nSequenceSeries);
		break;
	///日志文件内容应答
	case FTD_TID_RspQrySyslogInfoTopic:
		OnRspQrySyslogInfoTopic(pMessage, nSequenceSeries);
		break;
	///日志文件内容应答
	case FTD_TID_RtnSyslogInfoTopic:
		OnRtnSyslogInfoTopic(pMessage, nSequenceSeries);
		break;
	///监控内容订阅应答
	case FTD_TID_RspQrySubscriberTopic:
		OnRspQrySubscriberTopic(pMessage, nSequenceSeries);
		break;
	///对象关系查询应答
	case FTD_TID_RspQryOidRelationTopic:
		OnRspQryOidRelationTopic(pMessage, nSequenceSeries);
		break;
	///对象关系查询应答
	case FTD_TID_RtnOidRelationTopic:
		OnRtnOidRelationTopic(pMessage, nSequenceSeries);
		break;
	///用户信息查询请求应答
	case FTD_TID_RspQryUserInfoTopic:
		OnRspQryUserInfoTopic(pMessage, nSequenceSeries);
		break;
	///用户信息查询请求应答
	case FTD_TID_RtnUserInfoTopic:
		OnRtnUserInfoTopic(pMessage, nSequenceSeries);
		break;
	///在线用户信息查询请求应答
	case FTD_TID_RspQryOnlineUserInfoTopic:
		OnRspQryOnlineUserInfoTopic(pMessage, nSequenceSeries);
		break;
	///在线用户信息查询请求应答
	case FTD_TID_RtnOnlineUserInfoTopic:
		OnRtnOnlineUserInfoTopic(pMessage, nSequenceSeries);
		break;
	///告警事件查询请求应答
	case FTD_TID_RspQryWarningEventTopic:
		OnRspQryWarningEventTopic(pMessage, nSequenceSeries);
		break;
	///告警事件查询请求应答
	case FTD_TID_RtnWarningEventTopic:
		OnRtnWarningEventTopic(pMessage, nSequenceSeries);
		break;
	///CPU使用率查询请求应答
	case FTD_TID_RspQryCPUUsageTopic:
		OnRspQryCPUUsageTopic(pMessage, nSequenceSeries);
		break;
	///CPU使用率查询请求应答
	case FTD_TID_RtnCPUUsageTopic:
		OnRtnCPUUsageTopic(pMessage, nSequenceSeries);
		break;
	///内存使用率查询请求应答
	case FTD_TID_RspQryMemoryUsageTopic:
		OnRspQryMemoryUsageTopic(pMessage, nSequenceSeries);
		break;
	///内存使用率查询请求应答
	case FTD_TID_RtnMemoryUsageTopic:
		OnRtnMemoryUsageTopic(pMessage, nSequenceSeries);
		break;
	///硬盘使用率查询请求应答
	case FTD_TID_RspQryDiskUsageTopic:
		OnRspQryDiskUsageTopic(pMessage, nSequenceSeries);
		break;
	///硬盘使用率查询请求应答
	case FTD_TID_RtnDiskUsageTopic:
		OnRtnDiskUsageTopic(pMessage, nSequenceSeries);
		break;
	///对象状态指标查询应答
	case FTD_TID_RspQryObjectAttrTopic:
		OnRspQryObjectAttrTopic(pMessage, nSequenceSeries);
		break;
	///对象状态指标查询应答
	case FTD_TID_RtnObjectAttrTopic:
		OnRtnObjectAttrTopic(pMessage, nSequenceSeries);
		break;
	///历史对象状态指标查询应答
	case FTD_TID_RspQryHistoryObjectAttrTopic:
		OnRspQryHistoryObjectAttrTopic(pMessage, nSequenceSeries);
		break;
	///历史对象状态指标查询应答
	case FTD_TID_RtnHistoryObjectAttrTopic:
		OnRtnHistoryObjectAttrTopic(pMessage, nSequenceSeries);
		break;
	///前置响应信息查询应答
	case FTD_TID_RspQryFrontInfoTopic:
		OnRspQryFrontInfoTopic(pMessage, nSequenceSeries);
		break;
	///前置响应信息查询应答
	case FTD_TID_RtnFrontInfoTopic:
		OnRtnFrontInfoTopic(pMessage, nSequenceSeries);
		break;
	///用户登录应答
	case FTD_TID_RspQrySysUserLoginTopic:
		OnRspQrySysUserLoginTopic(pMessage, nSequenceSeries);
		break;
	///用户登出应答
	case FTD_TID_RspQrySysUserLogoutTopic:
		OnRspQrySysUserLogoutTopic(pMessage, nSequenceSeries);
		break;
	///用户修改密码应答
	case FTD_TID_RspQrySysUserPasswordUpdateTopic:
		OnRspQrySysUserPasswordUpdateTopic(pMessage, nSequenceSeries);
		break;
	///注册用户应答
	case FTD_TID_RspQrySysUserRegisterTopic:
		OnRspQrySysUserRegisterTopic(pMessage, nSequenceSeries);
		break;
	///删除用户应答
	case FTD_TID_RspQrySysUserDeleteTopic:
		OnRspQrySysUserDeleteTopic(pMessage, nSequenceSeries);
		break;
	///客户初始化应答
	case FTD_TID_RspQryClientInitTopic:
		OnRspQryClientInitTopic(pMessage, nSequenceSeries);
		break;
	///客户初始化应答
	case FTD_TID_RtnClientInitTopic:
		OnRtnClientInitTopic(pMessage, nSequenceSeries);
		break;
	///交易日志查询应答
	case FTD_TID_RspQryTradeLogTopic:
		OnRspQryTradeLogTopic(pMessage, nSequenceSeries);
		break;
	///交易日志查询应答
	case FTD_TID_RtnTradeLogTopic:
		OnRtnTradeLogTopic(pMessage, nSequenceSeries);
		break;
	///交易峰值查询应答
	case FTD_TID_RspQryTradepeakTopic:
		OnRspQryTradepeakTopic(pMessage, nSequenceSeries);
		break;
	///
	case FTD_TID_RtnUpdateSysConfigTopic:
		OnRtnUpdateSysConfigTopic(pMessage, nSequenceSeries);
		break;
	///
	case FTD_TID_RtnSysUser:
		OnRtnSysUser(pMessage, nSequenceSeries);
		break;
	///
	case FTD_TID_RtnPriceLimitChgTopic:
		OnRtnPriceLimitChgTopic(pMessage, nSequenceSeries);
		break;
	///
	case FTD_TID_RspQryHistoryCpuInfoTopic:
		OnRspQryHistoryCpuInfoTopic(pMessage, nSequenceSeries);
		break;
	///
	case FTD_TID_RspQryHistoryMemInfoTopic:
		OnRspQryHistoryMemInfoTopic(pMessage, nSequenceSeries);
		break;
	///
	case FTD_TID_RspQryHistoryNetworkInfoTopic:
		OnRspQryHistoryNetworkInfoTopic(pMessage, nSequenceSeries);
		break;
	///HostConfig查询请求应答
	case FTD_TID_RspQryHostConfig:
		OnRspQryHostConfig(pMessage, nSequenceSeries);
		break;
	///监控系统在线用户应答
	case FTD_TID_RspQryMonitorOnlineUser:
		OnRspQryMonitorOnlineUser(pMessage, nSequenceSeries);
		break;
	///监控系统时钟同步
	case FTD_TID_RtnSysTimeSyncTopic:
		OnRtnSysTimeSyncTopic(pMessage, nSequenceSeries);
		break;
	///数据中心切换通知
	case FTD_TID_RtnDataCenterChgTopic:
		OnRtnDataCenterChgTopic(pMessage, nSequenceSeries);
		break;
	///历史峰值查询应答
	case FTD_TID_RspQryHistoryTradePeakTopic:
		OnRspQryHistoryTradePeakTopic(pMessage, nSequenceSeries);
		break;
	///历史峰值查询应答
	case FTD_TID_RtnHistoryTradePeakTopic:
		OnRtnHistoryTradePeakTopic(pMessage, nSequenceSeries);
		break;
	///日志事件查询应答
	case FTD_TID_RspQrySyslogEventTopic:
		OnRspQrySyslogEventTopic(pMessage, nSequenceSeries);
		break;
	///日志事件应答
	case FTD_TID_RtnSyslogEventTopic:
		OnRtnSyslogEventTopic(pMessage, nSequenceSeries);
		break;
	///交易日切换通知
	case FTD_TID_RspQryTradeDayChangeTopic:
		OnRspQryTradeDayChangeTopic(pMessage, nSequenceSeries);
		break;
	///Web应用信息
	case FTD_TID_RspQryWebAppInfoTopic:
		OnRspQryWebAppInfoTopic(pMessage, nSequenceSeries);
		break;
	///Web应用信息
	case FTD_TID_RtnWebAppInfoTopic:
		OnRtnWebAppInfoTopic(pMessage, nSequenceSeries);
		break;
	///应用servlet信息
	case FTD_TID_RspQryServletInfoTopic:
		OnRspQryServletInfoTopic(pMessage, nSequenceSeries);
		break;
	///应用servlet信息
	case FTD_TID_RtnServletInfoTopic:
		OnRtnServletInfoTopic(pMessage, nSequenceSeries);
		break;
	///文件信息
	case FTD_TID_RspQryFileInfoTopic:
		OnRspQryFileInfoTopic(pMessage, nSequenceSeries);
		break;
	///文件信息
	case FTD_TID_RtnFileInfoTopic:
		OnRtnFileInfoTopic(pMessage, nSequenceSeries);
		break;
	///应用会话信息
	case FTD_TID_RspQrySessionInfoTopic:
		OnRspQrySessionInfoTopic(pMessage, nSequenceSeries);
		break;
	///应用会话信息
	case FTD_TID_RtnSessionInfoTopic:
		OnRtnSessionInfoTopic(pMessage, nSequenceSeries);
		break;
	///JDBC信息
	case FTD_TID_RspQryJDBCInfoTopic:
		OnRspQryJDBCInfoTopic(pMessage, nSequenceSeries);
		break;
	///JDBC信息
	case FTD_TID_RtnJDBCInfoTopic:
		OnRtnJDBCInfoTopic(pMessage, nSequenceSeries);
		break;
	///线程信息
	case FTD_TID_RspQryThreadInfoTopic:
		OnRspQryThreadInfoTopic(pMessage, nSequenceSeries);
		break;
	///线程信息
	case FTD_TID_RtnThreadInfoTopic:
		OnRtnThreadInfoTopic(pMessage, nSequenceSeries);
		break;
	///虚拟机信息
	case FTD_TID_RspQryVMInfoTopic:
		OnRspQryVMInfoTopic(pMessage, nSequenceSeries);
		break;
	///虚拟机信息
	case FTD_TID_RtnVMInfoTopic:
		OnRtnVMInfoTopic(pMessage, nSequenceSeries);
		break;
	///系统属性信息
	case FTD_TID_RspQryPropertyInfoTopic:
		OnRspQryPropertyInfoTopic(pMessage, nSequenceSeries);
		break;
	///系统属性信息
	case FTD_TID_RtnPropertyInfoTopic:
		OnRtnPropertyInfoTopic(pMessage, nSequenceSeries);
		break;
	///系统内存池信息
	case FTD_TID_RspQryMemPoolInfoTopic:
		OnRspQryMemPoolInfoTopic(pMessage, nSequenceSeries);
		break;
	///系统内存池信息
	case FTD_TID_RtnMemPoolInfoTopic:
		OnRtnMemPoolInfoTopic(pMessage, nSequenceSeries);
		break;
	///文件内容信息
	case FTD_TID_RspQryFileContentInfoTopic:
		OnRspQryFileContentInfoTopic(pMessage, nSequenceSeries);
		break;
	///文件内容信息
	case FTD_TID_RtnFileContentInfoTopic:
		OnRtnFileContentInfoTopic(pMessage, nSequenceSeries);
		break;
	///连接信息
	case FTD_TID_RspQryConnectionInfoTopic:
		OnRspQryConnectionInfoTopic(pMessage, nSequenceSeries);
		break;
	///连接信息
	case FTD_TID_RtnConnectionInfoTopic:
		OnRtnConnectionInfoTopic(pMessage, nSequenceSeries);
		break;
	///连接器信息
	case FTD_TID_RspQryConnectorInfoTopic:
		OnRspQryConnectorInfoTopic(pMessage, nSequenceSeries);
		break;
	///连接器信息
	case FTD_TID_RtnConnectorInfoTopic:
		OnRtnConnectorInfoTopic(pMessage, nSequenceSeries);
		break;
	///数据库查询应答
	case FTD_TID_RspQryDBQueryTopic:
		OnRspQryDBQueryTopic(pMessage, nSequenceSeries);
		break;
	///数据库查询应答
	case FTD_TID_RtnDBQueryTopic:
		OnRtnDBQueryTopic(pMessage, nSequenceSeries);
		break;
	///通用返回应答
	case FTD_TID_RspQryGeneralFieldTopic:
		OnRspQryGeneralFieldTopic(pMessage, nSequenceSeries);
		break;
	///通用返回应答
	case FTD_TID_RtnGeneralFieldTopic:
		OnRtnGeneralFieldTopic(pMessage, nSequenceSeries);
		break;
	///文件传输应答
	case FTD_TID_RspQryGetFileTopic:
		OnRspQryGetFileTopic(pMessage, nSequenceSeries);
		break;
	///告警明细
	case FTD_TID_RspQryWarningQueryTopic:
		OnRspQryWarningQueryTopic(pMessage, nSequenceSeries);
		break;
	///告警明细
	case FTD_TID_RtnWarningQueryTopic:
		OnRtnWarningQueryTopic(pMessage, nSequenceSeries);
		break;
	///HostConfig订阅应答
	case FTD_TID_RtnHostConfig:
		OnRtnHostConfig(pMessage, nSequenceSeries);
		break;
	///告警激活变更
	case FTD_TID_RspQryWarningActiveChange:
		OnRspQryWarningActiveChange(pMessage, nSequenceSeries);
		break;
	///告警激活变更
	case FTD_TID_RtnWarningActiveChange:
		OnRtnWarningActiveChange(pMessage, nSequenceSeries);
		break;
	///通用操作
	case FTD_TID_RspQryGeneralOperateTopic:
		OnRspQryGeneralOperateTopic(pMessage, nSequenceSeries);
		break;
	///通用操作
	case FTD_TID_RtnGeneralOperateTopic:
		OnRtnGeneralOperateTopic(pMessage, nSequenceSeries);
		break;
	///网络设备连接关系
	case FTD_TID_RspQryNetDeviceLinkedTopic:
		OnRspQryNetDeviceLinkedTopic(pMessage, nSequenceSeries);
		break;
	///网络设备连接关系
	case FTD_TID_RtnNetDeviceLinkedTopic:
		OnRtnNetDeviceLinkedTopic(pMessage, nSequenceSeries);
		break;
	///交易系统登录信息
	case FTD_TID_RspQryTradeUserLoginStatTopic:
		OnRspQryTradeUserLoginStatTopic(pMessage, nSequenceSeries);
		break;
	///交易系统前置报单响应信息
	case FTD_TID_RspQryTradeFrontOrderRttStatTopic:
		OnRspQryTradeFrontOrderRttStatTopic(pMessage, nSequenceSeries);
		break;
	///交易系统前置报单响应信息
	case FTD_TID_RtnTradeFrontOrderRttStatTopic:
		OnRtnTradeFrontOrderRttStatTopic(pMessage, nSequenceSeries);
		break;
	///系统路由信息
	case FTD_TID_RspQryRouterInfoTopic:
		OnRspQryRouterInfoTopic(pMessage, nSequenceSeries);
		break;
	///系统路由信息
	case FTD_TID_RtnRouterInfoTopic:
		OnRtnRouterInfoTopic(pMessage, nSequenceSeries);
		break;
	///磁盘I/O信息
	case FTD_TID_RspQryDiskIOTopic:
		OnRspQryDiskIOTopic(pMessage, nSequenceSeries);
		break;
	///磁盘I/O信息
	case FTD_TID_RtnDiskIOTopic:
		OnRtnDiskIOTopic(pMessage, nSequenceSeries);
		break;
	///系统状态信息
	case FTD_TID_RspQryStatInfoTopic:
		OnRspQryStatInfoTopic(pMessage, nSequenceSeries);
		break;
	///系统状态信息
	case FTD_TID_RtnStatInfoTopic:
		OnRtnStatInfoTopic(pMessage, nSequenceSeries);
		break;
	///交易系统前置报单分布区间
	case FTD_TID_RspQryTradeOrderRttCutLineTopic:
		OnRspQryTradeOrderRttCutLineTopic(pMessage, nSequenceSeries);
		break;
	///交易系统前置报单分布区间
	case FTD_TID_RtnTradeOrderRttCutLineTopic:
		OnRtnTradeOrderRttCutLineTopic(pMessage, nSequenceSeries);
		break;
	///会员客户信息
	case FTD_TID_RspQryClientInfoTopic:
		OnRspQryClientInfoTopic(pMessage, nSequenceSeries);
		break;
	///会员客户信息
	case FTD_TID_RtnClientInfoTopic:
		OnRtnClientInfoTopic(pMessage, nSequenceSeries);
		break;
	///应答事件描述
	case FTD_TID_RspQryEventDescriptionTopic:
		OnRspQryEventDescriptionTopic(pMessage, nSequenceSeries);
		break;
	///订阅事件描述
	case FTD_TID_RtnEventDescriptionTopic:
		OnRtnEventDescriptionTopic(pMessage, nSequenceSeries);
		break;
	///应答前置唯一ID信息
	case FTD_TID_RspQryFrontUniqueIDTopic:
		OnRspQryFrontUniqueIDTopic(pMessage, nSequenceSeries);
		break;
	///订阅前置唯一ID信息
	case FTD_TID_RtnFrontUniqueIDTopic:
		OnRtnFrontUniqueIDTopic(pMessage, nSequenceSeries);
		break;
	///会员线路地址变更回应
	case FTD_TID_RspQryNetPartyLinkAddrChangeTopic:
		OnRspQryNetPartyLinkAddrChangeTopic(pMessage, nSequenceSeries);
		break;
	///订阅会员线路地址变更信息
	case FTD_TID_RtnNetPartyLinkAddrChangeTopic:
		OnRtnNetPartyLinkAddrChangeTopic(pMessage, nSequenceSeries);
		break;
	///应答已删除会员列表信息
	case FTD_TID_RspQryNetDelPartyLinkInfoTopic:
		OnRspQryNetDelPartyLinkInfoTopic(pMessage, nSequenceSeries);
		break;
	///订阅已删除会员列表信息
	case FTD_TID_RtnNetDelPartyLinkInfoTopic:
		OnRtnNetDelPartyLinkInfoTopic(pMessage, nSequenceSeries);
		break;
	///返回网络性能排序
	case FTD_TID_RspQryPerformanceTopTopic:
		OnRspQryPerformanceTopTopic(pMessage, nSequenceSeries);
		break;
	///订阅网络性能排序
	case FTD_TID_RtnPerformanceTopTopic:
		OnRtnPerformanceTopTopic(pMessage, nSequenceSeries);
		break;
	///网络大区划分应答
	case FTD_TID_RspQryNetAreaTopic:
		OnRspQryNetAreaTopic(pMessage, nSequenceSeries);
		break;
	///网络大区划分应答
	case FTD_TID_RtnNetAreaTopic:
		OnRtnNetAreaTopic(pMessage, nSequenceSeries);
		break;
	///网络子区应答
	case FTD_TID_RspQryNetSubAreaTopic:
		OnRspQryNetSubAreaTopic(pMessage, nSequenceSeries);
		break;
	///网络子区应答
	case FTD_TID_RtnNetSubAreaTopic:
		OnRtnNetSubAreaTopic(pMessage, nSequenceSeries);
		break;
	///网络子区IP应答
	case FTD_TID_RspQryNetSubAreaIPTopic:
		OnRspQryNetSubAreaIPTopic(pMessage, nSequenceSeries);
		break;
	///网络子区IP应答
	case FTD_TID_RtnNetSubAreaIPTopic:
		OnRtnNetSubAreaIPTopic(pMessage, nSequenceSeries);
		break;
	///网络设备
	case FTD_TID_RspQryNetDeviceTopic:
		OnRspQryNetDeviceTopic(pMessage, nSequenceSeries);
		break;
	///网络设备
	case FTD_TID_RtnNetDeviceTopic:
		OnRtnNetDeviceTopic(pMessage, nSequenceSeries);
		break;
	///网络设备探测请求应答
	case FTD_TID_RspQryNetDeviceDetectTopic:
		OnRspQryNetDeviceDetectTopic(pMessage, nSequenceSeries);
		break;
	///大楼
	case FTD_TID_RspQryNetBuildingTopic:
		OnRspQryNetBuildingTopic(pMessage, nSequenceSeries);
		break;
	///大楼
	case FTD_TID_RtnNetBuildingTopic:
		OnRtnNetBuildingTopic(pMessage, nSequenceSeries);
		break;
	///机房
	case FTD_TID_RspQryNetRoomTopic:
		OnRspQryNetRoomTopic(pMessage, nSequenceSeries);
		break;
	///机房
	case FTD_TID_RtnNetRoomTopic:
		OnRtnNetRoomTopic(pMessage, nSequenceSeries);
		break;
	///机柜
	case FTD_TID_RspQryNetCabinetsTopic:
		OnRspQryNetCabinetsTopic(pMessage, nSequenceSeries);
		break;
	///机柜
	case FTD_TID_RtnNetCabinetsTopic:
		OnRtnNetCabinetsTopic(pMessage, nSequenceSeries);
		break;
	///OID
	case FTD_TID_RspQryNetOIDTopic:
		OnRspQryNetOIDTopic(pMessage, nSequenceSeries);
		break;
	///OID
	case FTD_TID_RtnNetOIDTopic:
		OnRtnNetOIDTopic(pMessage, nSequenceSeries);
		break;
	///时间策略
	case FTD_TID_RspQryNetTimePolicyTopic:
		OnRspQryNetTimePolicyTopic(pMessage, nSequenceSeries);
		break;
	///时间策略
	case FTD_TID_RtnNetTimePolicyTopic:
		OnRtnNetTimePolicyTopic(pMessage, nSequenceSeries);
		break;
	///采集任务
	case FTD_TID_RspQryNetGatherTaskTopic:
		OnRspQryNetGatherTaskTopic(pMessage, nSequenceSeries);
		break;
	///采集任务
	case FTD_TID_RtnNetGatherTaskTopic:
		OnRtnNetGatherTaskTopic(pMessage, nSequenceSeries);
		break;
	///设备变更
	case FTD_TID_RspQryNetDeviceChgTopic:
		OnRspQryNetDeviceChgTopic(pMessage, nSequenceSeries);
		break;
	///设备变更
	case FTD_TID_RtnNetDeviceChgTopic:
		OnRtnNetDeviceChgTopic(pMessage, nSequenceSeries);
		break;
	///常用设备型号
	case FTD_TID_RspQryNetDeviceTypeTopic:
		OnRspQryNetDeviceTypeTopic(pMessage, nSequenceSeries);
		break;
	///常用设备型号
	case FTD_TID_RtnNetDeviceTypeTopic:
		OnRtnNetDeviceTypeTopic(pMessage, nSequenceSeries);
		break;
	///常用设备类别
	case FTD_TID_RspQryNetDeviceCategoryTopic:
		OnRspQryNetDeviceCategoryTopic(pMessage, nSequenceSeries);
		break;
	///常用设备类别
	case FTD_TID_RtnNetDeviceCategoryTopic:
		OnRtnNetDeviceCategoryTopic(pMessage, nSequenceSeries);
		break;
	///设备厂商
	case FTD_TID_RspQryNetManufactoryTopic:
		OnRspQryNetManufactoryTopic(pMessage, nSequenceSeries);
		break;
	///设备厂商
	case FTD_TID_RtnNetManufactoryTopic:
		OnRtnNetManufactoryTopic(pMessage, nSequenceSeries);
		break;
	///设备共同体
	case FTD_TID_RspQryNetCommunityTopic:
		OnRspQryNetCommunityTopic(pMessage, nSequenceSeries);
		break;
	///设备共同体
	case FTD_TID_RtnNetCommunityTopic:
		OnRtnNetCommunityTopic(pMessage, nSequenceSeries);
		break;
	///端口类型
	case FTD_TID_RspQryNetPortTypeTopic:
		OnRspQryNetPortTypeTopic(pMessage, nSequenceSeries);
		break;
	///端口类型
	case FTD_TID_RtnNetPortTypeTopic:
		OnRtnNetPortTypeTopic(pMessage, nSequenceSeries);
		break;
	///会员接入地点
	case FTD_TID_RspQryNetPartAccessSpotTopic:
		OnRspQryNetPartAccessSpotTopic(pMessage, nSequenceSeries);
		break;
	///会员接入地点
	case FTD_TID_RtnNetPartAccessSpotTopic:
		OnRtnNetPartAccessSpotTopic(pMessage, nSequenceSeries);
		break;
	///端口
	case FTD_TID_RspQryNetInterfaceTopic:
		OnRspQryNetInterfaceTopic(pMessage, nSequenceSeries);
		break;
	///端口
	case FTD_TID_RtnNetInterfaceTopic:
		OnRtnNetInterfaceTopic(pMessage, nSequenceSeries);
		break;
	///GeneralOID
	case FTD_TID_RspQryNetGeneralOIDTopic:
		OnRspQryNetGeneralOIDTopic(pMessage, nSequenceSeries);
		break;
	///GeneralOID
	case FTD_TID_RtnNetGeneralOIDTopic:
		OnRtnNetGeneralOIDTopic(pMessage, nSequenceSeries);
		break;
	///监控对象类别
	case FTD_TID_RspQryNetMonitorTypeTopic:
		OnRspQryNetMonitorTypeTopic(pMessage, nSequenceSeries);
		break;
	///监控对象类别
	case FTD_TID_RtnNetMonitorTypeTopic:
		OnRtnNetMonitorTypeTopic(pMessage, nSequenceSeries);
		break;
	///指标统表
	case FTD_TID_RspQryNetMonitorAttrScopeTopic:
		OnRspQryNetMonitorAttrScopeTopic(pMessage, nSequenceSeries);
		break;
	///指标统表
	case FTD_TID_RtnNetMonitorAttrScopeTopic:
		OnRtnNetMonitorAttrScopeTopic(pMessage, nSequenceSeries);
		break;
	///监控指标表
	case FTD_TID_RspQryNetMonitorAttrTypeTopic:
		OnRspQryNetMonitorAttrTypeTopic(pMessage, nSequenceSeries);
		break;
	///监控指标表
	case FTD_TID_RtnNetMonitorAttrTypeTopic:
		OnRtnNetMonitorAttrTypeTopic(pMessage, nSequenceSeries);
		break;
	///监控对象指标表
	case FTD_TID_RspQryNetMonitorObjectAttrTopic:
		OnRspQryNetMonitorObjectAttrTopic(pMessage, nSequenceSeries);
		break;
	///监控对象指标表
	case FTD_TID_RtnNetMonitorObjectAttrTopic:
		OnRtnNetMonitorObjectAttrTopic(pMessage, nSequenceSeries);
		break;
	///职能区
	case FTD_TID_RspQryNetFuncAreaTopic:
		OnRspQryNetFuncAreaTopic(pMessage, nSequenceSeries);
		break;
	///职能区
	case FTD_TID_RtnNetFuncAreaTopic:
		OnRtnNetFuncAreaTopic(pMessage, nSequenceSeries);
		break;
	///监控指令表
	case FTD_TID_RspQryNetMonitorCommandTypeTopic:
		OnRspQryNetMonitorCommandTypeTopic(pMessage, nSequenceSeries);
		break;
	///监控指令表
	case FTD_TID_RtnNetMonitorCommandTypeTopic:
		OnRtnNetMonitorCommandTypeTopic(pMessage, nSequenceSeries);
		break;
	///动作族表
	case FTD_TID_RspQryNetMonitorActionGroupTopic:
		OnRspQryNetMonitorActionGroupTopic(pMessage, nSequenceSeries);
		break;
	///动作族表
	case FTD_TID_RtnNetMonitorActionGroupTopic:
		OnRtnNetMonitorActionGroupTopic(pMessage, nSequenceSeries);
		break;
	///设备对象组表
	case FTD_TID_RspQryNetMonitorDeviceGroupTopic:
		OnRspQryNetMonitorDeviceGroupTopic(pMessage, nSequenceSeries);
		break;
	///设备对象组表
	case FTD_TID_RtnNetMonitorDeviceGroupTopic:
		OnRtnNetMonitorDeviceGroupTopic(pMessage, nSequenceSeries);
		break;
	///任务信息表
	case FTD_TID_RspQryNetMonitorTaskInfoTopic:
		OnRspQryNetMonitorTaskInfoTopic(pMessage, nSequenceSeries);
		break;
	///任务信息表
	case FTD_TID_RtnNetMonitorTaskInfoTopic:
		OnRtnNetMonitorTaskInfoTopic(pMessage, nSequenceSeries);
		break;
	///任务结果表
	case FTD_TID_RspQryNetMonitorTaskResultTopic:
		OnRspQryNetMonitorTaskResultTopic(pMessage, nSequenceSeries);
		break;
	///任务结果表
	case FTD_TID_RtnNetMonitorTaskResultTopic:
		OnRtnNetMonitorTaskResultTopic(pMessage, nSequenceSeries);
		break;
	///任务对象集
	case FTD_TID_RspQryNetMonitorTaskObjectSetTopic:
		OnRspQryNetMonitorTaskObjectSetTopic(pMessage, nSequenceSeries);
		break;
	///任务对象集
	case FTD_TID_RtnNetMonitorTaskObjectSetTopic:
		OnRtnNetMonitorTaskObjectSetTopic(pMessage, nSequenceSeries);
		break;
	///会员链路信息表
	case FTD_TID_RspQryNetPartyLinkInfoTopic:
		OnRspQryNetPartyLinkInfoTopic(pMessage, nSequenceSeries);
		break;
	///会员链路信息表
	case FTD_TID_RtnNetPartyLinkInfoTopic:
		OnRtnNetPartyLinkInfoTopic(pMessage, nSequenceSeries);
		break;
	///监控动作指标对照表
	case FTD_TID_RspQryNetMonitorActionAttrTopic:
		OnRspQryNetMonitorActionAttrTopic(pMessage, nSequenceSeries);
		break;
	///监控动作指标对照表
	case FTD_TID_RtnNetMonitorActionAttrTopic:
		OnRtnNetMonitorActionAttrTopic(pMessage, nSequenceSeries);
		break;
	///模块
	case FTD_TID_RspQryNetModuleTopic:
		OnRspQryNetModuleTopic(pMessage, nSequenceSeries);
		break;
	///模块
	case FTD_TID_RtnNetModuleTopic:
		OnRtnNetModuleTopic(pMessage, nSequenceSeries);
		break;
	///告警表达式信息表
	case FTD_TID_RspQryNetEventExprTopic:
		OnRspQryNetEventExprTopic(pMessage, nSequenceSeries);
		break;
	///告警表达式信息表
	case FTD_TID_RtnNetEventExprTopic:
		OnRtnNetEventExprTopic(pMessage, nSequenceSeries);
		break;
	///事件类型
	case FTD_TID_RspQryNetEventTypeTopic:
		OnRspQryNetEventTypeTopic(pMessage, nSequenceSeries);
		break;
	///事件类型
	case FTD_TID_RtnNetEventTypeTopic:
		OnRtnNetEventTypeTopic(pMessage, nSequenceSeries);
		break;
	///事件子类型
	case FTD_TID_RspQryNetSubEventTypeTopic:
		OnRspQryNetSubEventTypeTopic(pMessage, nSequenceSeries);
		break;
	///事件子类型
	case FTD_TID_RtnNetSubEventTypeTopic:
		OnRtnNetSubEventTypeTopic(pMessage, nSequenceSeries);
		break;
	///事件级别
	case FTD_TID_RspQryNetEventLevelTopic:
		OnRspQryNetEventLevelTopic(pMessage, nSequenceSeries);
		break;
	///事件级别
	case FTD_TID_RtnNetEventLevelTopic:
		OnRtnNetEventLevelTopic(pMessage, nSequenceSeries);
		break;
	///任务结果状态表
	case FTD_TID_RspQryNetMonitorTaskStatusResultTopic:
		OnRspQryNetMonitorTaskStatusResultTopic(pMessage, nSequenceSeries);
		break;
	///任务结果状态表
	case FTD_TID_RtnNetMonitorTaskStatusResultTopic:
		OnRtnNetMonitorTaskStatusResultTopic(pMessage, nSequenceSeries);
		break;
	///配置服务对登陆的响应
	case FTD_TID_RspConfigLoginTopic:
		OnRspConfigLoginTopic(pMessage, nSequenceSeries);
		break;
	///对当前登录配置的服务角色的响应
	case FTD_TID_RspServerTypeTopic:
		OnRspServerTypeTopic(pMessage, nSequenceSeries);
		break;
	///设备配置表
	case FTD_TID_RspQryNetCfgFileTopic:
		OnRspQryNetCfgFileTopic(pMessage, nSequenceSeries);
		break;
	///设备配置表
	case FTD_TID_RtnNetCfgFileTopic:
		OnRtnNetCfgFileTopic(pMessage, nSequenceSeries);
		break;
	///任务结果规则分析表
	case FTD_TID_RspQryNetMonitorDeviceTaskTopic:
		OnRspQryNetMonitorDeviceTaskTopic(pMessage, nSequenceSeries);
		break;
	///任务结果规则分析表
	case FTD_TID_RtnNetMonitorDeviceTaskTopic:
		OnRtnNetMonitorDeviceTaskTopic(pMessage, nSequenceSeries);
		break;
	///任务指令指标集表
	case FTD_TID_RspQryNetMonitorTaskInstAttrsTopic:
		OnRspQryNetMonitorTaskInstAttrsTopic(pMessage, nSequenceSeries);
		break;
	///任务指令指标集表
	case FTD_TID_RtnNetMonitorTaskInstAttrsTopic:
		OnRtnNetMonitorTaskInstAttrsTopic(pMessage, nSequenceSeries);
		break;
	///文件通用操作
	case FTD_TID_RspQryFileGeneralOperTopic:
		OnRspQryFileGeneralOperTopic(pMessage, nSequenceSeries);
		break;
	///文件通用操作
	case FTD_TID_RtnFileGeneralOperTopic:
		OnRtnFileGeneralOperTopic(pMessage, nSequenceSeries);
		break;
	///基线表
	case FTD_TID_RspQryNetBaseLineTopic:
		OnRspQryNetBaseLineTopic(pMessage, nSequenceSeries);
		break;
	///基线表
	case FTD_TID_RtnNetBaseLineTopic:
		OnRtnNetBaseLineTopic(pMessage, nSequenceSeries);
		break;
	///基线任务表
	case FTD_TID_RspQryNetBaseLineTaskTopic:
		OnRspQryNetBaseLineTaskTopic(pMessage, nSequenceSeries);
		break;
	///基线任务表
	case FTD_TID_RtnNetBaseLineTaskTopic:
		OnRtnNetBaseLineTaskTopic(pMessage, nSequenceSeries);
		break;
	///基线结果表
	case FTD_TID_RspQryNetBaseLineResultTopic:
		OnRspQryNetBaseLineResultTopic(pMessage, nSequenceSeries);
		break;
	///基线结果表
	case FTD_TID_RtnNetBaseLineResultTopic:
		OnRtnNetBaseLineResultTopic(pMessage, nSequenceSeries);
		break;
	///会员链路状态信息表
	case FTD_TID_RspQryNetPartyLinkStatusInfoTopic:
		OnRspQryNetPartyLinkStatusInfoTopic(pMessage, nSequenceSeries);
		break;
	///会员链路状态信息表
	case FTD_TID_RtnNetPartyLinkStatusInfoTopic:
		OnRtnNetPartyLinkStatusInfoTopic(pMessage, nSequenceSeries);
		break;
	///会员SDH线路明细表
	case FTD_TID_RspQryNetMemberSDHLineInfoTopic:
		OnRspQryNetMemberSDHLineInfoTopic(pMessage, nSequenceSeries);
		break;
	///会员SDH线路明细表
	case FTD_TID_RtnNetMemberSDHLineInfoTopic:
		OnRtnNetMemberSDHLineInfoTopic(pMessage, nSequenceSeries);
		break;
	///DDN链路信息表
	case FTD_TID_RspQryNetDDNLinkInfoTopic:
		OnRspQryNetDDNLinkInfoTopic(pMessage, nSequenceSeries);
		break;
	///DDN链路信息表
	case FTD_TID_RtnNetDDNLinkInfoTopic:
		OnRtnNetDDNLinkInfoTopic(pMessage, nSequenceSeries);
		break;
	///非会员线路使用信息
	case FTD_TID_RspQryNetPseudMemberLinkInfoTopic:
		OnRspQryNetPseudMemberLinkInfoTopic(pMessage, nSequenceSeries);
		break;
	///非会员线路使用信息
	case FTD_TID_RtnNetPseudMemberLinkInfoTopic:
		OnRtnNetPseudMemberLinkInfoTopic(pMessage, nSequenceSeries);
		break;
	///远端设备信息
	case FTD_TID_RspQryOuterDeviceInfTopic:
		OnRspQryOuterDeviceInfTopic(pMessage, nSequenceSeries);
		break;
	///远端设备信息
	case FTD_TID_RtnNetOuterDeviceInfTopic:
		OnRtnNetOuterDeviceInfTopic(pMessage, nSequenceSeries);
		break;
	///本地ping结果
	case FTD_TID_RspQryNetLocalPingResultInfoTopic:
		OnRspQryNetLocalPingResultInfoTopic(pMessage, nSequenceSeries);
		break;
	///本地ping结果
	case FTD_TID_RtnNetLocalPingResultInfoTopic:
		OnRtnNetLocalPingResultInfoTopic(pMessage, nSequenceSeries);
		break;
	///远程ping结果
	case FTD_TID_RspQryNetRomotePingResultInfoTopic:
		OnRspQryNetRomotePingResultInfoTopic(pMessage, nSequenceSeries);
		break;
	///远程ping结果
	case FTD_TID_RtnNetRomotePingResultInfoTopic:
		OnRtnNetRomotePingResultInfoTopic(pMessage, nSequenceSeries);
		break;
	///进程信息数据库专用
	case FTD_TID_RtnMonitorTopProcessInfo:
		OnRtnMonitorTopProcessInfo(pMessage, nSequenceSeries);
		break;
	///系统内部级联关系
	case FTD_TID_RspQrySysInternalTopologyTopic:
		OnRspQrySysInternalTopologyTopic(pMessage, nSequenceSeries);
		break;
	///系统内部级联关系
	case FTD_TID_RtnSysInternalTopologyTopic:
		OnRtnSysInternalTopologyTopic(pMessage, nSequenceSeries);
		break;
	///返回会员链路费用表
	case FTD_TID_RspQryMemberLinkCostTopic:
		OnRspQryMemberLinkCostTopic(pMessage, nSequenceSeries);
		break;
	///订阅会员链路费用表
	case FTD_TID_RtnMemberLinkCostTopic:
		OnRtnMemberLinkCostTopic(pMessage, nSequenceSeries);
		break;
	///返回会员链路月租表
	case FTD_TID_RspQryNetPartylinkMonthlyRentTopic:
		OnRspQryNetPartylinkMonthlyRentTopic(pMessage, nSequenceSeries);
		break;
	///订阅会员链路月租表
	case FTD_TID_RtnNetPartylinkMonthlyRentTopic:
		OnRtnNetPartylinkMonthlyRentTopic(pMessage, nSequenceSeries);
		break;
	///返回非会员链路表信息
	case FTD_TID_RspQryNetNonPartyLinkInfoTopic:
		OnRspQryNetNonPartyLinkInfoTopic(pMessage, nSequenceSeries);
		break;
	///订阅非会员链路表信息
	case FTD_TID_RtnNetNonPartyLinkInfoTopic:
		OnRtnNetNonPartyLinkInfoTopic(pMessage, nSequenceSeries);
		break;
	///应答配置信息
	case FTD_TID_RspQryMonConfigInfo:
		OnRspQryMonConfigInfo(pMessage, nSequenceSeries);
		break;
	///应答配置信息
	case FTD_TID_RtnMonConfigInfo:
		OnRtnMonConfigInfo(pMessage, nSequenceSeries);
		break;
	///通知监控日信息
	case FTD_TID_RtnMonitorDayInfo:
		OnRtnMonitorDayInfo(pMessage, nSequenceSeries);
		break;
	///通知交易日信息
	case FTD_TID_RtnTradingDayInfo:
		OnRtnTradingDayInfo(pMessage, nSequenceSeries);
		break;
	///监控阶段结束
	case FTD_TID_RtnSectionFinish:
		OnRtnSectionFinish(pMessage, nSequenceSeries);
		break;
	///监控阶段切换
	case FTD_TID_RtnSectionChange:
		OnRtnSectionChange(pMessage, nSequenceSeries);
		break;
	///服务连接响应
	case FTD_TID_RspMonServiceConnect:
		OnRspMonServiceConnect(pMessage, nSequenceSeries);
		break;
	///Proxy或探针名称配置
	case FTD_TID_RtnMonProxyConfig:
		OnRtnMonProxyConfig(pMessage, nSequenceSeries);
		break;
	///服务的当前状态响应
	case FTD_TID_RspQryMonServiceStatus:
		OnRspQryMonServiceStatus(pMessage, nSequenceSeries);
		break;
	///服务的当前状态推送
	case FTD_TID_RtnMonServiceStatus:
		OnRtnMonServiceStatus(pMessage, nSequenceSeries);
		break;
	///当前数据中心角色
	case FTD_TID_RtnMonDataCenterRole:
		OnRtnMonDataCenterRole(pMessage, nSequenceSeries);
		break;
	///探针任务配置查询响应
	case FTD_TID_RspQryMonProbeTask:
		OnRspQryMonProbeTask(pMessage, nSequenceSeries);
		break;
	///探针任务配置推送
	case FTD_TID_RtnMonProbeTask:
		OnRtnMonProbeTask(pMessage, nSequenceSeries);
		break;
	///监控系统指标查询应答
	case FTD_TID_RspQryMonObjectAttr:
		OnRspQryMonObjectAttr(pMessage, nSequenceSeries);
		break;
	///监控系统指标查询推送
	case FTD_TID_RtnMonObjectAttr:
		OnRtnMonObjectAttr(pMessage, nSequenceSeries);
		break;
	///监控系统Syslog事件查询应答
	case FTD_TID_RspQryMonSyslogEvent:
		OnRspQryMonSyslogEvent(pMessage, nSequenceSeries);
		break;
	///监控系统Syslog事件查询推送
	case FTD_TID_RtnMonSyslogEvent:
		OnRtnMonSyslogEvent(pMessage, nSequenceSeries);
		break;
	///文件读取偏移量查询应答
	case FTD_TID_RspQryMonFileOffset:
		OnRspQryMonFileOffset(pMessage, nSequenceSeries);
		break;
	///文件读取偏移量查询推送
	case FTD_TID_RtnMonFileOffset:
		OnRtnMonFileOffset(pMessage, nSequenceSeries);
		break;
	///文件内容查询应答
	case FTD_TID_RspQryMonFileContent:
		OnRspQryMonFileContent(pMessage, nSequenceSeries);
		break;
	///文件内容通告
	case FTD_TID_RtnMonFileContent:
		OnRtnMonFileContent(pMessage, nSequenceSeries);
		break;
	///主机基础环境信息应答
	case FTD_TID_RspQryMonHostBasicEnv:
		OnRspQryMonHostBasicEnv(pMessage, nSequenceSeries);
		break;
	///主机基础环境信息应答
	case FTD_TID_RtnMonHostBasicEnv:
		OnRtnMonHostBasicEnv(pMessage, nSequenceSeries);
		break;
	///主机基础网络信息应答
	case FTD_TID_RspQryMonHostNetworkEnv:
		OnRspQryMonHostNetworkEnv(pMessage, nSequenceSeries);
		break;
	///主机基础网络信息通告
	case FTD_TID_RtnMonHostNetworkEnv:
		OnRtnMonHostNetworkEnv(pMessage, nSequenceSeries);
		break;
	///主机文件系统信息应答
	case FTD_TID_RspQryMonHostFileSysEnv:
		OnRspQryMonHostFileSysEnv(pMessage, nSequenceSeries);
		break;
	///主机文件系统信息通告
	case FTD_TID_RtnMonHostFileSysEnv:
		OnRtnMonHostFileSysEnv(pMessage, nSequenceSeries);
		break;
	///主机交换分区信息应答
	case FTD_TID_RspQryMonHostSwapEnv:
		OnRspQryMonHostSwapEnv(pMessage, nSequenceSeries);
		break;
	///主机交换分区信息通告
	case FTD_TID_RtnMonHostSwapEnv:
		OnRtnMonHostSwapEnv(pMessage, nSequenceSeries);
		break;
	///主机的CPU信息指标信息应答
	case FTD_TID_RspQryMonHostCPUAttr:
		OnRspQryMonHostCPUAttr(pMessage, nSequenceSeries);
		break;
	///主机的CPU信息指标信息
	case FTD_TID_RtnMonHostCPUAttr:
		OnRtnMonHostCPUAttr(pMessage, nSequenceSeries);
		break;
	///主机的Memory使用信息应答
	case FTD_TID_RspQryMonHostMemAttr:
		OnRspQryMonHostMemAttr(pMessage, nSequenceSeries);
		break;
	///主机的Memory使用信息
	case FTD_TID_RtnMonHostMemAttr:
		OnRtnMonHostMemAttr(pMessage, nSequenceSeries);
		break;
	///主机的FileSystem使用信息应答
	case FTD_TID_RspQryMonHostFileSystemAttr:
		OnRspQryMonHostFileSystemAttr(pMessage, nSequenceSeries);
		break;
	///主机的FileSystem使用信息
	case FTD_TID_RtnMonHostFileSystemAttr:
		OnRtnMonHostFileSystemAttr(pMessage, nSequenceSeries);
		break;
	///主机的用户信息应答
	case FTD_TID_RspQryMonHostUserInfo:
		OnRspQryMonHostUserInfo(pMessage, nSequenceSeries);
		break;
	///主机的用户信息
	case FTD_TID_RtnMonHostUserInfo:
		OnRtnMonHostUserInfo(pMessage, nSequenceSeries);
		break;
	///主机的在线用户信息应答
	case FTD_TID_RspQryMonHostOnlineUserInfo:
		OnRspQryMonHostOnlineUserInfo(pMessage, nSequenceSeries);
		break;
	///主机的在线用户信息
	case FTD_TID_RtnMonHostOnlineUserInfo:
		OnRtnMonHostOnlineUserInfo(pMessage, nSequenceSeries);
		break;
	///主机的network使用信息应答
	case FTD_TID_RspQryMonHostNetworkAttr:
		OnRspQryMonHostNetworkAttr(pMessage, nSequenceSeries);
		break;
	///主机的network使用信息
	case FTD_TID_RtnMonHostNetworkAttr:
		OnRtnMonHostNetworkAttr(pMessage, nSequenceSeries);
		break;
	///主机的系统状态信息应答
	case FTD_TID_RspQryMonHostStatInfo:
		OnRspQryMonHostStatInfo(pMessage, nSequenceSeries);
		break;
	///主机的系统状态信息
	case FTD_TID_RtnMonHostStatInfo:
		OnRtnMonHostStatInfo(pMessage, nSequenceSeries);
		break;
	///主机的磁盘IO信息应答
	case FTD_TID_RspQryMonHostDiskIOAttr:
		OnRspQryMonHostDiskIOAttr(pMessage, nSequenceSeries);
		break;
	///主机的磁盘IO信息
	case FTD_TID_RtnMonHostDiskIOAttr:
		OnRtnMonHostDiskIOAttr(pMessage, nSequenceSeries);
		break;
	///主机的路由信息应答
	case FTD_TID_RspQryMonHostRouterInfo:
		OnRspQryMonHostRouterInfo(pMessage, nSequenceSeries);
		break;
	///主机的路由信息
	case FTD_TID_RtnMonHostRouterInfo:
		OnRtnMonHostRouterInfo(pMessage, nSequenceSeries);
		break;
	///主机的进程信息应答
	case FTD_TID_RspQryMonHostProcessInfo:
		OnRspQryMonHostProcessInfo(pMessage, nSequenceSeries);
		break;
	///主机的进程信息
	case FTD_TID_RtnMonHostProcessInfo:
		OnRtnMonHostProcessInfo(pMessage, nSequenceSeries);
		break;
	///数据库采集的推送报文，包括了SP，DBLog，DBAttr
	case FTD_TID_RtnMonDBQuery:
		OnRtnMonDBQuery(pMessage, nSequenceSeries);
		break;
	///响应客户端临时SP查询请求
	case FTD_TID_RspQryMonSPQuery:
		OnRspQryMonSPQuery(pMessage, nSequenceSeries);
		break;
	///服务版本信息响应
	case FTD_TID_RspServiceVersion:
		OnRspServiceVersion(pMessage, nSequenceSeries);
		break;
	///服务应用程序响应
	case FTD_TID_RspServiceProgram:
		OnRspServiceProgram(pMessage, nSequenceSeries);
		break;
	///升级服务获取状态响应
	case FTD_TID_RspUpdateState:
		OnRspUpdateState(pMessage, nSequenceSeries);
		break;
	///订阅请求应答
	case FTD_TID_RspSubscribe:
		OnRspSubscribe(pMessage, nSequenceSeries);
		break;
	///通知目标服务文件已成功接收
	case FTD_TID_RspFileSendSuccess:
		OnRspFileSendSuccess(pMessage, nSequenceSeries);
		break;
	///用于通知目标服务文件已发送成功
	case FTD_TID_RtnFileSendSuccess:
		OnRtnFileSendSuccess(pMessage, nSequenceSeries);
		break;
	///tomcat信息应答
	case FTD_TID_RspQryMonTomcatInfo:
		OnRspQryMonTomcatInfo(pMessage, nSequenceSeries);
		break;
	///tomcat信息推送
	case FTD_TID_RtnMonTomcatInfo:
		OnRtnMonTomcatInfo(pMessage, nSequenceSeries);
		break;
	///Web应用信息
	case FTD_TID_RspQryMonWebAppInfo:
		OnRspQryMonWebAppInfo(pMessage, nSequenceSeries);
		break;
	///Web应用信息
	case FTD_TID_RtnMonWebAppInfo:
		OnRtnMonWebAppInfo(pMessage, nSequenceSeries);
		break;
	///应用servlet信息
	case FTD_TID_RspQryMonServletInfo:
		OnRspQryMonServletInfo(pMessage, nSequenceSeries);
		break;
	///应用servlet信息
	case FTD_TID_RtnMonServletInfo:
		OnRtnMonServletInfo(pMessage, nSequenceSeries);
		break;
	///文件信息
	case FTD_TID_RspQryMonFileInfo:
		OnRspQryMonFileInfo(pMessage, nSequenceSeries);
		break;
	///文件信息
	case FTD_TID_RtnMonFileInfo:
		OnRtnMonFileInfo(pMessage, nSequenceSeries);
		break;
	///应用会话信息应答
	case FTD_TID_RspQryMonSessionInfo:
		OnRspQryMonSessionInfo(pMessage, nSequenceSeries);
		break;
	///应用会话信息推送
	case FTD_TID_RtnMonSessionInfo:
		OnRtnMonSessionInfo(pMessage, nSequenceSeries);
		break;
	///JDBC信息
	case FTD_TID_RspQryMonJDBCInfo:
		OnRspQryMonJDBCInfo(pMessage, nSequenceSeries);
		break;
	///JDBC信息
	case FTD_TID_RtnMonJDBCInfo:
		OnRtnMonJDBCInfo(pMessage, nSequenceSeries);
		break;
	///线程信息
	case FTD_TID_RspQryMonThreadInfo:
		OnRspQryMonThreadInfo(pMessage, nSequenceSeries);
		break;
	///线程信息
	case FTD_TID_RtnMonThreadInfo:
		OnRtnMonThreadInfo(pMessage, nSequenceSeries);
		break;
	///虚拟机信息
	case FTD_TID_RspQryMonVMInfo:
		OnRspQryMonVMInfo(pMessage, nSequenceSeries);
		break;
	///虚拟机信息
	case FTD_TID_RtnMonVMInfo:
		OnRtnMonVMInfo(pMessage, nSequenceSeries);
		break;
	///系统属性信息
	case FTD_TID_RspQryMonPropertyInfo:
		OnRspQryMonPropertyInfo(pMessage, nSequenceSeries);
		break;
	///系统属性信息
	case FTD_TID_RtnMonPropertyInfo:
		OnRtnMonPropertyInfo(pMessage, nSequenceSeries);
		break;
	///系统内存池信息
	case FTD_TID_RspQryMonMemPoolInfo:
		OnRspQryMonMemPoolInfo(pMessage, nSequenceSeries);
		break;
	///系统内存池信息
	case FTD_TID_RtnMonMemPoolInfo:
		OnRtnMonMemPoolInfo(pMessage, nSequenceSeries);
		break;
	///连接信息
	case FTD_TID_RspQryMonConnectionInfo:
		OnRspQryMonConnectionInfo(pMessage, nSequenceSeries);
		break;
	///连接信息
	case FTD_TID_RtnMonConnectionInfo:
		OnRtnMonConnectionInfo(pMessage, nSequenceSeries);
		break;
	///无效报单查询应答
	case FTD_TID_RspQryInvalidateOrderTopic:
		OnRspQryInvalidateOrderTopic(pMessage, nSequenceSeries);
		break;
	///无效报单查询应答
	case FTD_TID_RtnInvalidateOrderTopic:
		OnRtnInvalidateOrderTopic(pMessage, nSequenceSeries);
		break;
	///报单状态查询应答
	case FTD_TID_RspQryOrderStatusTopic:
		OnRspQryOrderStatusTopic(pMessage, nSequenceSeries);
		break;
	///报单状态查询应答
	case FTD_TID_RtnOrderStatusTopic:
		OnRtnOrderStatusTopic(pMessage, nSequenceSeries);
		break;
	///报单成交查询应答
	case FTD_TID_RspQryBargainOrderTopic:
		OnRspQryBargainOrderTopic(pMessage, nSequenceSeries);
		break;
	///报单成交查询应答
	case FTD_TID_RtnBargainOrderTopic:
		OnRtnBargainOrderTopic(pMessage, nSequenceSeries);
		break;
	///合约基本属性查询应答
	case FTD_TID_RspQryInstPropertyTopic:
		OnRspQryInstPropertyTopic(pMessage, nSequenceSeries);
		break;
	///合约基本属性查询应答
	case FTD_TID_RtnInstPropertyTopic:
		OnRtnInstPropertyTopic(pMessage, nSequenceSeries);
		break;
	///合约保证金率查询应答
	case FTD_TID_RspQryMarginRateTopic:
		OnRspQryMarginRateTopic(pMessage, nSequenceSeries);
		break;
	///合约保证金率查询应答
	case FTD_TID_RtnMarginRateTopic:
		OnRtnMarginRateTopic(pMessage, nSequenceSeries);
		break;
	///合约涨跌停板查询应答
	case FTD_TID_RspQryPriceLimitTopic:
		OnRspQryPriceLimitTopic(pMessage, nSequenceSeries);
		break;
	///合约涨跌停板查询应答
	case FTD_TID_RtnPriceLimitTopic:
		OnRtnPriceLimitTopic(pMessage, nSequenceSeries);
		break;
	///会员限仓查询应答
	case FTD_TID_RspQryPartPosiLimitTopic:
		OnRspQryPartPosiLimitTopic(pMessage, nSequenceSeries);
		break;
	///会员限仓查询应答
	case FTD_TID_RtnPartPosiLimitTopic:
		OnRtnPartPosiLimitTopic(pMessage, nSequenceSeries);
		break;
	///客户限仓查询应答
	case FTD_TID_RspQryClientPosiLimitTopic:
		OnRspQryClientPosiLimitTopic(pMessage, nSequenceSeries);
		break;
	///客户限仓查询应答
	case FTD_TID_RtnClientPosiLimitTopic:
		OnRtnClientPosiLimitTopic(pMessage, nSequenceSeries);
		break;
	///特殊客户限仓查询应答
	case FTD_TID_RspQrySpecialPosiLimitTopic:
		OnRspQrySpecialPosiLimitTopic(pMessage, nSequenceSeries);
		break;
	///特殊客户限仓查询应答
	case FTD_TID_RtnSpecialPosiLimitTopic:
		OnRtnSpecialPosiLimitTopic(pMessage, nSequenceSeries);
		break;
	///账户出入金查询应答
	case FTD_TID_RspQryTransactionChgTopic:
		OnRspQryTransactionChgTopic(pMessage, nSequenceSeries);
		break;
	///账户出入金查询应答
	case FTD_TID_RtnTransactionChgTopic:
		OnRtnTransactionChgTopic(pMessage, nSequenceSeries);
		break;
	///客户数据变动查询应答
	case FTD_TID_RspQryClientChgTopic:
		OnRspQryClientChgTopic(pMessage, nSequenceSeries);
		break;
	///客户数据变动查询应答
	case FTD_TID_RtnClientChgTopic:
		OnRtnClientChgTopic(pMessage, nSequenceSeries);
		break;
	///会员客户对照变动查询应答
	case FTD_TID_RspQryPartClientChgTopic:
		OnRspQryPartClientChgTopic(pMessage, nSequenceSeries);
		break;
	///会员客户对照变动查询应答
	case FTD_TID_RtnPartClientChgTopic:
		OnRtnPartClientChgTopic(pMessage, nSequenceSeries);
		break;
	///限仓数据变动查询应答
	case FTD_TID_RspQryPosiLimitChgTopic:
		OnRspQryPosiLimitChgTopic(pMessage, nSequenceSeries);
		break;
	///限仓数据变动查询应答
	case FTD_TID_RtnPosiLimitChgTopic:
		OnRtnPosiLimitChgTopic(pMessage, nSequenceSeries);
		break;
	///保值额度变动查询应答
	case FTD_TID_RspQryHedgeDetailChgTopic:
		OnRspQryHedgeDetailChgTopic(pMessage, nSequenceSeries);
		break;
	///保值额度变动查询应答
	case FTD_TID_RtnHedgeDetailChgTopic:
		OnRtnHedgeDetailChgTopic(pMessage, nSequenceSeries);
		break;
	///会员变动查询应答
	case FTD_TID_RspQryParticipantChgTopic:
		OnRspQryParticipantChgTopic(pMessage, nSequenceSeries);
		break;
	///会员变动查询应答
	case FTD_TID_RtnParticipantChgTopic:
		OnRtnParticipantChgTopic(pMessage, nSequenceSeries);
		break;
	///保证金率变动查询应答
	case FTD_TID_RspQryMarginRateChgTopic:
		OnRspQryMarginRateChgTopic(pMessage, nSequenceSeries);
		break;
	///保证金率变动查询应答
	case FTD_TID_RtnMarginRateChgTopic:
		OnRtnMarginRateChgTopic(pMessage, nSequenceSeries);
		break;
	///IP地址变动查询应答
	case FTD_TID_RspQryUserIpChgTopic:
		OnRspQryUserIpChgTopic(pMessage, nSequenceSeries);
		break;
	///IP地址变动查询应答
	case FTD_TID_RtnUserIpChgTopic:
		OnRtnUserIpChgTopic(pMessage, nSequenceSeries);
		break;
	///限仓数据变动查询应答
	case FTD_TID_RspQryClientPosiLimitChgTopic:
		OnRspQryClientPosiLimitChgTopic(pMessage, nSequenceSeries);
		break;
	///限仓数据变动查询应答
	case FTD_TID_RtnClientPosiLimitChgTopic:
		OnRtnClientPosiLimitChgTopic(pMessage, nSequenceSeries);
		break;
	///限仓数据变动查询应答
	case FTD_TID_RspQrySpecPosiLimitChgTopic:
		OnRspQrySpecPosiLimitChgTopic(pMessage, nSequenceSeries);
		break;
	///限仓数据变动查询应答
	case FTD_TID_RtnSpecPosiLimitChgTopic:
		OnRtnSpecPosiLimitChgTopic(pMessage, nSequenceSeries);
		break;
	///交易系统前置统计应答
	case FTD_TID_RspQryFrontStatTopic:
		OnRspQryFrontStatTopic(pMessage, nSequenceSeries);
		break;
	///会员初始化应答
	case FTD_TID_RspQryParticipantInitTopic:
		OnRspQryParticipantInitTopic(pMessage, nSequenceSeries);
		break;
	///会员初始化应答
	case FTD_TID_RtnParticipantInitTopic:
		OnRtnParticipantInitTopic(pMessage, nSequenceSeries);
		break;
	///座席初始化应答
	case FTD_TID_RspQryUserInitTopic:
		OnRspQryUserInitTopic(pMessage, nSequenceSeries);
		break;
	///座席初始化应答
	case FTD_TID_RtnUserInitTopic:
		OnRtnUserInitTopic(pMessage, nSequenceSeries);
		break;
	///返回约状态切换数据
	case FTD_TID_RspQryInstrumentStatusTopic:
		OnRspQryInstrumentStatusTopic(pMessage, nSequenceSeries);
		break;
	///订阅约状态切换数据
	case FTD_TID_RtnInstrumentStatusTopic:
		OnRtnInstrumentStatusTopic(pMessage, nSequenceSeries);
		break;
	///返回合约交易节信息
	case FTD_TID_RspQryCurrTradingSegmentAttrTopic:
		OnRspQryCurrTradingSegmentAttrTopic(pMessage, nSequenceSeries);
		break;
	///订阅合约交易节信息
	case FTD_TID_RtnCurrTradingSegmentAttrTopic:
		OnRtnCurrTradingSegmentAttrTopic(pMessage, nSequenceSeries);
		break;
	///交易系统登录信息
	case FTD_TID_RspQryTradeUserLoginInfoTopic:
		OnRspQryTradeUserLoginInfoTopic(pMessage, nSequenceSeries);
		break;
	///交易系统登录信息
	case FTD_TID_RtnTradeUserLoginInfoTopic:
		OnRtnTradeUserLoginInfoTopic(pMessage, nSequenceSeries);
		break;
	///会员交易查询应答
	case FTD_TID_RspQryPartTradeTopic:
		OnRspQryPartTradeTopic(pMessage, nSequenceSeries);
		break;
	///会员席位交易状态
	case FTD_TID_RspQryParticTradeOrderStatesTopic:
		OnRspQryParticTradeOrderStatesTopic(pMessage, nSequenceSeries);
		break;
	///会员席位交易状态
	case FTD_TID_RtnParticTradeOrderStatesTopic:
		OnRtnParticTradeOrderStatesTopic(pMessage, nSequenceSeries);
		break;
	///获得监控对象信息应答
	case FTD_TID_RspQryMonitor2ObjectTopic:
		OnRspQryMonitor2ObjectTopic(pMessage, nSequenceSeries);
		break;
	///获得监控对象信息应答
	case FTD_TID_RtnMonitor2ObjectTopic:
		OnRtnMonitor2ObjectTopic(pMessage, nSequenceSeries);
		break;
	///主机环境信息应答
	case FTD_TID_RspQryMonHostCommonEnvTopic:
		OnRspQryMonHostCommonEnvTopic(pMessage, nSequenceSeries);
		break;
	///主机环境信息应答
	case FTD_TID_RtnMonHostCommonEnvTopic:
		OnRtnMonHostCommonEnvTopic(pMessage, nSequenceSeries);
		break;
	///应答业务进程和主机关系
	case FTD_TID_RspQryMonOidHostRationalTopic:
		OnRspQryMonOidHostRationalTopic(pMessage, nSequenceSeries);
		break;
	///推送业务进程和主机关系
	case FTD_TID_RtnMonOidHostRationalTopic:
		OnRtnMonOidHostRationalTopic(pMessage, nSequenceSeries);
		break;
	///对象关系查询应答
	case FTD_TID_RspQryMonOidRelationTopic:
		OnRspQryMonOidRelationTopic(pMessage, nSequenceSeries);
		break;
	///对象关系查询应答
	case FTD_TID_RtnMonOidRelationTopic:
		OnRtnMonOidRelationTopic(pMessage, nSequenceSeries);
		break;
	default:
		break;
	}
}

CShfeFtdcUserApi *CShfeFtdcUserApi::CreateFtdcUserApi(const char *pszFlowPath,
													const char *pszUserApiType)
{
	return new CFtdcUserApiImpl(pszFlowPath, pszUserApiType, new CSelectReactor(true));
}

const char *CShfeFtdcUserApi::GetVersion(int &nMajorVersion, int &nMinorVersion)
{
		nMajorVersion = atoi(MAJOR_VERSION);
		nMinorVersion = atoi(MINOR_VERSION);
		return "SHFE User Api V"MAJOR_VERSION"."MINOR_VERSION" Build "__DATE__" "__TIME__" "SUFFIX_STR;
}


///错误应答
void CFtdcUserApiImpl::OnRspError(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnRspError(pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户登录应答
void CFtdcUserApiImpl::OnRspUserLogin(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CUserSubscriberMap::iterator it;
	CFTDUserCommFluxControlField UserCommFluxControlField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &UserCommFluxControlField) > 0)
	{
		CShfeFtdcUserCommFluxControlField *pUserCommFluxControlField = (CShfeFtdcUserCommFluxControlField *)&UserCommFluxControlField;
		if(pUserCommFluxControlField!=NULL)
		{
			CFtdcUserSubscriber *pFtdcUserSubscriber=NULL;
			for(it=m_mapSubscriber.begin();it!=m_mapSubscriber.end();it++)
			{
				pFtdcUserSubscriber=(CFtdcUserSubscriber *)it->second;
				if(pUserCommFluxControlField->MaxTradeCommFlux>0&&pFtdcUserSubscriber->GetSequenceSeries()==TSS_DIALOG)
				{
					pFtdcUserSubscriber->SetTradeMaxCommFlux(pUserCommFluxControlField->MaxTradeCommFlux);
				}
				if(pUserCommFluxControlField->MaxTradeOnWayCommFlux>0&&pFtdcUserSubscriber->GetSequenceSeries()==TSS_DIALOG)
				{
					pFtdcUserSubscriber->SetTradeMaxOnWayCommFlux(pUserCommFluxControlField->MaxTradeOnWayCommFlux);
				}
				if(pUserCommFluxControlField->MaxQueryCommFlux>0&&pFtdcUserSubscriber->GetSequenceSeries()==TSS_QUERY)
				{
					pFtdcUserSubscriber->SetQueryMaxCommFlux(pUserCommFluxControlField->MaxQueryCommFlux);
				}
				if(pUserCommFluxControlField->MaxQueryOnWayCommFlux>0&&pFtdcUserSubscriber->GetSequenceSeries()==TSS_QUERY)
				{
					pFtdcUserSubscriber->SetQueryMaxOnWayCommFlux(pUserCommFluxControlField->MaxQueryOnWayCommFlux);
				}
			}
		}
	}
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspUserLoginField RspUserLogin;
	CShfeFtdcRspUserLoginField *pRspUserLogin = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspUserLoginField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspUserLogin);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspUserLogin = (CShfeFtdcRspUserLoginField *)&RspUserLogin;
			m_pSpi->OnRspUserLogin(pRspUserLogin, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspUserLogin == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspUserLogin(pRspUserLogin, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户退出应答
void CFtdcUserApiImpl::OnRspUserLogout(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspUserLogoutField RspUserLogout;
	CShfeFtdcRspUserLogoutField *pRspUserLogout = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspUserLogoutField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspUserLogout);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspUserLogout = (CShfeFtdcRspUserLogoutField *)&RspUserLogout;
			m_pSpi->OnRspUserLogout(pRspUserLogout, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspUserLogout == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspUserLogout(pRspUserLogout, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///报单录入应答
void CFtdcUserApiImpl::OnRspOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputOrderField InputOrder;
	CShfeFtdcInputOrderField *pInputOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputOrder = (CShfeFtdcInputOrderField *)&InputOrder;
			m_pSpi->OnRspOrderInsert(pInputOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspOrderInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputOrder, &CFTDInputOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInputOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspOrderInsert(pInputOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///报单操作应答
void CFtdcUserApiImpl::OnRspOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDOrderActionField OrderAction;
	CShfeFtdcOrderActionField *pOrderAction = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDOrderActionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&OrderAction);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pOrderAction = (CShfeFtdcOrderActionField *)&OrderAction;
			m_pSpi->OnRspOrderAction(pOrderAction, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspOrderAction,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&OrderAction, &CFTDOrderActionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pOrderAction == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspOrderAction(pOrderAction, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///报价录入应答
void CFtdcUserApiImpl::OnRspQuoteInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputQuoteField InputQuote;
	CShfeFtdcInputQuoteField *pInputQuote = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputQuoteField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputQuote);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputQuote = (CShfeFtdcInputQuoteField *)&InputQuote;
			m_pSpi->OnRspQuoteInsert(pInputQuote, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQuoteInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputQuote, &CFTDInputQuoteField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInputQuote == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQuoteInsert(pInputQuote, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///报价操作应答
void CFtdcUserApiImpl::OnRspQuoteAction(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDQuoteActionField QuoteAction;
	CShfeFtdcQuoteActionField *pQuoteAction = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDQuoteActionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&QuoteAction);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pQuoteAction = (CShfeFtdcQuoteActionField *)&QuoteAction;
			m_pSpi->OnRspQuoteAction(pQuoteAction, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQuoteAction,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&QuoteAction, &CFTDQuoteActionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pQuoteAction == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQuoteAction(pQuoteAction, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///OTC报单录入应答
void CFtdcUserApiImpl::OnRspOTCOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDOTCOrderField OTCOrder;
	CShfeFtdcOTCOrderField *pOTCOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDOTCOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&OTCOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pOTCOrder = (CShfeFtdcOTCOrderField *)&OTCOrder;
			m_pSpi->OnRspOTCOrderInsert(pOTCOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspOTCOrderInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&OTCOrder, &CFTDOTCOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pOTCOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspOTCOrderInsert(pOTCOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户密码修改应答
void CFtdcUserApiImpl::OnRspUserPasswordUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDUserPasswordUpdateField UserPasswordUpdate;
	CShfeFtdcUserPasswordUpdateField *pUserPasswordUpdate = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDUserPasswordUpdateField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&UserPasswordUpdate);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pUserPasswordUpdate = (CShfeFtdcUserPasswordUpdateField *)&UserPasswordUpdate;
			m_pSpi->OnRspUserPasswordUpdate(pUserPasswordUpdate, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspUserPasswordUpdate,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&UserPasswordUpdate, &CFTDUserPasswordUpdateField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pUserPasswordUpdate == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspUserPasswordUpdate(pUserPasswordUpdate, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///执行宣告录入应答
void CFtdcUserApiImpl::OnRspExecOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputExecOrderField InputExecOrder;
	CShfeFtdcInputExecOrderField *pInputExecOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputExecOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputExecOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputExecOrder = (CShfeFtdcInputExecOrderField *)&InputExecOrder;
			m_pSpi->OnRspExecOrderInsert(pInputExecOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspExecOrderInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputExecOrder, &CFTDInputExecOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInputExecOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspExecOrderInsert(pInputExecOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///执行宣告操作应答
void CFtdcUserApiImpl::OnRspExecOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDExecOrderActionField ExecOrderAction;
	CShfeFtdcExecOrderActionField *pExecOrderAction = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDExecOrderActionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&ExecOrderAction);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pExecOrderAction = (CShfeFtdcExecOrderActionField *)&ExecOrderAction;
			m_pSpi->OnRspExecOrderAction(pExecOrderAction, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspExecOrderAction,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&ExecOrderAction, &CFTDExecOrderActionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pExecOrderAction == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspExecOrderAction(pExecOrderAction, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///管理报单录入应答
void CFtdcUserApiImpl::OnRspAdminOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputAdminOrderField InputAdminOrder;
	CShfeFtdcInputAdminOrderField *pInputAdminOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputAdminOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputAdminOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputAdminOrder = (CShfeFtdcInputAdminOrderField *)&InputAdminOrder;
			m_pSpi->OnRspAdminOrderInsert(pInputAdminOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspAdminOrderInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputAdminOrder, &CFTDInputAdminOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInputAdminOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspAdminOrderInsert(pInputAdminOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///非标组合报单录入应答
void CFtdcUserApiImpl::OnRspCombOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputCombOrderField InputCombOrder;
	CShfeFtdcInputCombOrderField *pInputCombOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputCombOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputCombOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputCombOrder = (CShfeFtdcInputCombOrderField *)&InputCombOrder;
			m_pSpi->OnRspCombOrderInsert(pInputCombOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspCombOrderInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputCombOrder, &CFTDInputCombOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInputCombOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspCombOrderInsert(pInputCombOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅主题应答
void CFtdcUserApiImpl::OnRspSubscribeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDDisseminationField Dissemination;
	CShfeFtdcDisseminationField *pDissemination = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDDisseminationField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Dissemination);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pDissemination = (CShfeFtdcDisseminationField *)&Dissemination;
			m_pSpi->OnRspSubscribeTopic(pDissemination, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspSubscribeTopic,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Dissemination, &CFTDDisseminationField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pDissemination == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspSubscribeTopic(pDissemination, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易所公告请求应答
void CFtdcUserApiImpl::OnRspBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDBulletinField Bulletin;
	CShfeFtdcBulletinField *pBulletin = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDBulletinField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Bulletin);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pBulletin = (CShfeFtdcBulletinField *)&Bulletin;
			m_pSpi->OnRspBulletin(pBulletin, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspBulletin,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Bulletin, &CFTDBulletinField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pBulletin == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspBulletin(pBulletin, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易所公告信息应答
void CFtdcUserApiImpl::OnRspInformation(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInformationField Information;
	CShfeFtdcInformationField *pInformation = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInformationField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Information);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInformation = (CShfeFtdcInformationField *)&Information;
			m_pSpi->OnRspInformation(pInformation, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspInformation,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Information, &CFTDInformationField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInformation == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspInformation(pInformation, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///合约交易状态改变应答
void CFtdcUserApiImpl::OnRspInstrumentStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInstrumentStatusField InstrumentStatus;
	CShfeFtdcInstrumentStatusField *pInstrumentStatus = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInstrumentStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InstrumentStatus);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInstrumentStatus = (CShfeFtdcInstrumentStatusField *)&InstrumentStatus;
			m_pSpi->OnRspInstrumentStatusUpdate(pInstrumentStatus, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspInstrumentStatusUpdate,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InstrumentStatus, &CFTDInstrumentStatusField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInstrumentStatus == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspInstrumentStatusUpdate(pInstrumentStatus, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///强制用户退出应答
void CFtdcUserApiImpl::OnRspForceUserExit(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDForceUserExitField ForceUserExit;
	CShfeFtdcForceUserExitField *pForceUserExit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDForceUserExitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&ForceUserExit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pForceUserExit = (CShfeFtdcForceUserExitField *)&ForceUserExit;
			m_pSpi->OnRspForceUserExit(pForceUserExit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspForceUserExit,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&ForceUserExit, &CFTDForceUserExitField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pForceUserExit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspForceUserExit(pForceUserExit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户会话删除应答
void CFtdcUserApiImpl::OnRspForceUserLogout(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDForceUserExitField ForceUserExit;
	CShfeFtdcForceUserExitField *pForceUserExit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDForceUserExitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&ForceUserExit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pForceUserExit = (CShfeFtdcForceUserExitField *)&ForceUserExit;
			m_pSpi->OnRspForceUserLogout(pForceUserExit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspForceUserLogout,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&ForceUserExit, &CFTDForceUserExitField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pForceUserExit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspForceUserLogout(pForceUserExit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易所数据同步状态改变应答
void CFtdcUserApiImpl::OnRspExchangeDataSyncStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDExchangeDataSyncStatusField ExchangeDataSyncStatus;
	CShfeFtdcExchangeDataSyncStatusField *pExchangeDataSyncStatus = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDExchangeDataSyncStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&ExchangeDataSyncStatus);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pExchangeDataSyncStatus = (CShfeFtdcExchangeDataSyncStatusField *)&ExchangeDataSyncStatus;
			m_pSpi->OnRspExchangeDataSyncStatusUpdate(pExchangeDataSyncStatus, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspExchangeDataSyncStatusUpdate,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&ExchangeDataSyncStatus, &CFTDExchangeDataSyncStatusField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pExchangeDataSyncStatus == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspExchangeDataSyncStatusUpdate(pExchangeDataSyncStatus, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///结算组数据同步状态改变应答
void CFtdcUserApiImpl::OnRspSGDataSyncStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDSGDataSyncStatusField SGDataSyncStatus;
	CShfeFtdcSGDataSyncStatusField *pSGDataSyncStatus = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDSGDataSyncStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&SGDataSyncStatus);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pSGDataSyncStatus = (CShfeFtdcSGDataSyncStatusField *)&SGDataSyncStatus;
			m_pSpi->OnRspSGDataSyncStatusUpdate(pSGDataSyncStatus, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspSGDataSyncStatusUpdate,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&SGDataSyncStatus, &CFTDSGDataSyncStatusField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pSGDataSyncStatus == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspSGDataSyncStatusUpdate(pSGDataSyncStatus, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员资金查询应答
void CFtdcUserApiImpl::OnRspQryPartAccount(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspPartAccountField RspPartAccount;
	CShfeFtdcRspPartAccountField *pRspPartAccount = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspPartAccountField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspPartAccount);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspPartAccount = (CShfeFtdcRspPartAccountField *)&RspPartAccount;
			m_pSpi->OnRspQryPartAccount(pRspPartAccount, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryPartAccount,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspPartAccount, &CFTDRspPartAccountField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspPartAccount == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPartAccount(pRspPartAccount, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///报单查询应答
void CFtdcUserApiImpl::OnRspQryOrder(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDOrderField Order;
	CShfeFtdcOrderField *pOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Order);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pOrder = (CShfeFtdcOrderField *)&Order;
			m_pSpi->OnRspQryOrder(pOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryOrder,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Order, &CFTDOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryOrder(pOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///报价查询应答
void CFtdcUserApiImpl::OnRspQryQuote(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDQuoteField Quote;
	CShfeFtdcQuoteField *pQuote = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDQuoteField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Quote);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pQuote = (CShfeFtdcQuoteField *)&Quote;
			m_pSpi->OnRspQryQuote(pQuote, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryQuote,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Quote, &CFTDQuoteField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pQuote == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryQuote(pQuote, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///成交单查询应答
void CFtdcUserApiImpl::OnRspQryTrade(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDTradeField Trade;
	CShfeFtdcTradeField *pTrade = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDTradeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Trade);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pTrade = (CShfeFtdcTradeField *)&Trade;
			m_pSpi->OnRspQryTrade(pTrade, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryTrade,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Trade, &CFTDTradeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pTrade == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTrade(pTrade, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员客户查询应答
void CFtdcUserApiImpl::OnRspQryClient(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspClientField RspClient;
	CShfeFtdcRspClientField *pRspClient = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspClientField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspClient);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspClient = (CShfeFtdcRspClientField *)&RspClient;
			m_pSpi->OnRspQryClient(pRspClient, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryClient,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspClient, &CFTDRspClientField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspClient == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryClient(pRspClient, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员持仓查询应答
void CFtdcUserApiImpl::OnRspQryPartPosition(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspPartPositionField RspPartPosition;
	CShfeFtdcRspPartPositionField *pRspPartPosition = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspPartPositionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspPartPosition);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspPartPosition = (CShfeFtdcRspPartPositionField *)&RspPartPosition;
			m_pSpi->OnRspQryPartPosition(pRspPartPosition, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryPartPosition,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspPartPosition, &CFTDRspPartPositionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspPartPosition == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPartPosition(pRspPartPosition, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///客户持仓查询应答
void CFtdcUserApiImpl::OnRspQryClientPosition(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspClientPositionField RspClientPosition;
	CShfeFtdcRspClientPositionField *pRspClientPosition = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspClientPositionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspClientPosition);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspClientPosition = (CShfeFtdcRspClientPositionField *)&RspClientPosition;
			m_pSpi->OnRspQryClientPosition(pRspClientPosition, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryClientPosition,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspClientPosition, &CFTDRspClientPositionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspClientPosition == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryClientPosition(pRspClientPosition, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///合约查询应答
void CFtdcUserApiImpl::OnRspQryInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspInstrumentField RspInstrument;
	CShfeFtdcRspInstrumentField *pRspInstrument = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspInstrumentField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspInstrument);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspInstrument = (CShfeFtdcRspInstrumentField *)&RspInstrument;
			m_pSpi->OnRspQryInstrument(pRspInstrument, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryInstrument,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspInstrument, &CFTDRspInstrumentField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspInstrument == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryInstrument(pRspInstrument, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///合约交易状态查询应答
void CFtdcUserApiImpl::OnRspQryInstrumentStatus(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInstrumentStatusField InstrumentStatus;
	CShfeFtdcInstrumentStatusField *pInstrumentStatus = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInstrumentStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InstrumentStatus);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInstrumentStatus = (CShfeFtdcInstrumentStatusField *)&InstrumentStatus;
			m_pSpi->OnRspQryInstrumentStatus(pInstrumentStatus, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryInstrumentStatus,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InstrumentStatus, &CFTDInstrumentStatusField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInstrumentStatus == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryInstrumentStatus(pInstrumentStatus, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///结算组状态查询应答
void CFtdcUserApiImpl::OnRspQrySGDataSyncStatus(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDSGDataSyncStatusField SGDataSyncStatus;
	CShfeFtdcSGDataSyncStatusField *pSGDataSyncStatus = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDSGDataSyncStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&SGDataSyncStatus);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pSGDataSyncStatus = (CShfeFtdcSGDataSyncStatusField *)&SGDataSyncStatus;
			m_pSpi->OnRspQrySGDataSyncStatus(pSGDataSyncStatus, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQrySGDataSyncStatus,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&SGDataSyncStatus, &CFTDSGDataSyncStatusField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pSGDataSyncStatus == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySGDataSyncStatus(pSGDataSyncStatus, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///保值额度应答
void CFtdcUserApiImpl::OnRspQryHedgeVolume(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDHedgeVolumeField HedgeVolume;
	CShfeFtdcHedgeVolumeField *pHedgeVolume = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDHedgeVolumeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&HedgeVolume);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pHedgeVolume = (CShfeFtdcHedgeVolumeField *)&HedgeVolume;
			m_pSpi->OnRspQryHedgeVolume(pHedgeVolume, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryHedgeVolume,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&HedgeVolume, &CFTDHedgeVolumeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pHedgeVolume == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryHedgeVolume(pHedgeVolume, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///信用限额查询应答
void CFtdcUserApiImpl::OnRspQryCreditLimit(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDCreditLimitField CreditLimit;
	CShfeFtdcCreditLimitField *pCreditLimit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDCreditLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&CreditLimit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pCreditLimit = (CShfeFtdcCreditLimitField *)&CreditLimit;
			m_pSpi->OnRspQryCreditLimit(pCreditLimit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryCreditLimit,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&CreditLimit, &CFTDCreditLimitField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pCreditLimit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryCreditLimit(pCreditLimit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///非标组合报单查询应答
void CFtdcUserApiImpl::OnRspQryCombOrder(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDCombOrderField CombOrder;
	CShfeFtdcCombOrderField *pCombOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDCombOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&CombOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pCombOrder = (CShfeFtdcCombOrderField *)&CombOrder;
			m_pSpi->OnRspQryCombOrder(pCombOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryCombOrder,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&CombOrder, &CFTDCombOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pCombOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryCombOrder(pCombOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///执行宣告查询应答
void CFtdcUserApiImpl::OnRspQryExecOrder(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDExecOrderField ExecOrder;
	CShfeFtdcExecOrderField *pExecOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDExecOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&ExecOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pExecOrder = (CShfeFtdcExecOrderField *)&ExecOrder;
			m_pSpi->OnRspQryExecOrder(pExecOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryExecOrder,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&ExecOrder, &CFTDExecOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pExecOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryExecOrder(pExecOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///普通行情查询应答
void CFtdcUserApiImpl::OnRspQryMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDMarketDataField MarketData;
	CShfeFtdcMarketDataField *pMarketData = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDMarketDataField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&MarketData);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pMarketData = (CShfeFtdcMarketDataField *)&MarketData;
			m_pSpi->OnRspQryMarketData(pMarketData, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryMarketData,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&MarketData, &CFTDMarketDataField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pMarketData == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMarketData(pMarketData, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易所公告查询请求应答
void CFtdcUserApiImpl::OnRspQryBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDBulletinField Bulletin;
	CShfeFtdcBulletinField *pBulletin = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDBulletinField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Bulletin);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pBulletin = (CShfeFtdcBulletinField *)&Bulletin;
			m_pSpi->OnRspQryBulletin(pBulletin, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryBulletin,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Bulletin, &CFTDBulletinField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pBulletin == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryBulletin(pBulletin, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主题查询应答
void CFtdcUserApiImpl::OnRspQryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDDisseminationField Dissemination;
	CShfeFtdcDisseminationField *pDissemination = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDDisseminationField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Dissemination);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pDissemination = (CShfeFtdcDisseminationField *)&Dissemination;
			m_pSpi->OnRspQryTopic(pDissemination, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryTopic,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Dissemination, &CFTDDisseminationField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pDissemination == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTopic(pDissemination, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户在线查询应答
void CFtdcUserApiImpl::OnRspQryUserSession(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDUserSessionField UserSession;
	CShfeFtdcUserSessionField *pUserSession = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDUserSessionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&UserSession);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pUserSession = (CShfeFtdcUserSessionField *)&UserSession;
			m_pSpi->OnRspQryUserSession(pUserSession, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryUserSession,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&UserSession, &CFTDUserSessionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pUserSession == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryUserSession(pUserSession, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户查询应答
void CFtdcUserApiImpl::OnRspQryUser(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDUserField User;
	CShfeFtdcUserField *pUser = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDUserField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&User);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pUser = (CShfeFtdcUserField *)&User;
			m_pSpi->OnRspQryUser(pUser, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryUser,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&User, &CFTDUserField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pUser == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryUser(pUser, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员查询应答
void CFtdcUserApiImpl::OnRspQryParticipant(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDParticipantField Participant;
	CShfeFtdcParticipantField *pParticipant = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDParticipantField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Participant);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pParticipant = (CShfeFtdcParticipantField *)&Participant;
			m_pSpi->OnRspQryParticipant(pParticipant, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryParticipant,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Participant, &CFTDParticipantField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pParticipant == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryParticipant(pParticipant, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///合约价位查询应答
void CFtdcUserApiImpl::OnRspQryMBLMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDMBLMarketDataField MBLMarketData;
	CShfeFtdcMBLMarketDataField *pMBLMarketData = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDMBLMarketDataField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&MBLMarketData);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pMBLMarketData = (CShfeFtdcMBLMarketDataField *)&MBLMarketData;
			m_pSpi->OnRspQryMBLMarketData(pMBLMarketData, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryMBLMarketData,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&MBLMarketData, &CFTDMBLMarketDataField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pMBLMarketData == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMBLMarketData(pMBLMarketData, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///信息查询应答
void CFtdcUserApiImpl::OnRspQryInformation(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInformationField Information;
	CShfeFtdcInformationField *pInformation = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInformationField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Information);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInformation = (CShfeFtdcInformationField *)&Information;
			m_pSpi->OnRspQryInformation(pInformation, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryInformation,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&Information, &CFTDInformationField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pInformation == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryInformation(pInformation, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///成交回报
void CFtdcUserApiImpl::OnRtnTrade(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDTradeField Trade;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDTradeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Trade);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnTrade,", szTimeBuffer);
			FIELD_TO_STRING((char *)&Trade, &CFTDTradeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTrade((CShfeFtdcTradeField *)&Trade);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///报单回报
void CFtdcUserApiImpl::OnRtnOrder(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDOrderField Order;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Order);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnOrder,", szTimeBuffer);
			FIELD_TO_STRING((char *)&Order, &CFTDOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnOrder((CShfeFtdcOrderField *)&Order);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///执行宣告回报
void CFtdcUserApiImpl::OnRtnExecOrder(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDExecOrderField ExecOrder;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDExecOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&ExecOrder);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnExecOrder,", szTimeBuffer);
			FIELD_TO_STRING((char *)&ExecOrder, &CFTDExecOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnExecOrder((CShfeFtdcExecOrderField *)&ExecOrder);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///报价回报
void CFtdcUserApiImpl::OnRtnQuote(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDQuoteField Quote;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDQuoteField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Quote);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnQuote,", szTimeBuffer);
			FIELD_TO_STRING((char *)&Quote, &CFTDQuoteField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnQuote((CShfeFtdcQuoteField *)&Quote);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///非标组合报单回报
void CFtdcUserApiImpl::OnRtnCombOrder(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDCombOrderField CombOrder;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDCombOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&CombOrder);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnCombOrder,", szTimeBuffer);
			FIELD_TO_STRING((char *)&CombOrder, &CFTDCombOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnCombOrder((CShfeFtdcCombOrderField *)&CombOrder);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///合约交易状态通知
void CFtdcUserApiImpl::OnRtnInstrumentStatus(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDInstrumentStatusField InstrumentStatus;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInstrumentStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InstrumentStatus);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnInstrumentStatus,", szTimeBuffer);
			FIELD_TO_STRING((char *)&InstrumentStatus, &CFTDInstrumentStatusField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnInstrumentStatus((CShfeFtdcInstrumentStatusField *)&InstrumentStatus);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///增加合约通知
void CFtdcUserApiImpl::OnRtnInsInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDInstrumentField Instrument;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInstrumentField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Instrument);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnInsInstrument,", szTimeBuffer);
			FIELD_TO_STRING((char *)&Instrument, &CFTDInstrumentField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnInsInstrument((CShfeFtdcInstrumentField *)&Instrument);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///删除合约通知
void CFtdcUserApiImpl::OnRtnDelInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDInstrumentField Instrument;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInstrumentField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Instrument);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnDelInstrument,", szTimeBuffer);
			FIELD_TO_STRING((char *)&Instrument, &CFTDInstrumentField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnDelInstrument((CShfeFtdcInstrumentField *)&Instrument);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///增加合约单腿通知
void CFtdcUserApiImpl::OnRtnInsCombinationLeg(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDCombinationLegField CombinationLeg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDCombinationLegField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&CombinationLeg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnInsCombinationLeg,", szTimeBuffer);
			FIELD_TO_STRING((char *)&CombinationLeg, &CFTDCombinationLegField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnInsCombinationLeg((CShfeFtdcCombinationLegField *)&CombinationLeg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///删除合约单腿通知
void CFtdcUserApiImpl::OnRtnDelCombinationLeg(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDCombinationLegField CombinationLeg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDCombinationLegField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&CombinationLeg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnDelCombinationLeg,", szTimeBuffer);
			FIELD_TO_STRING((char *)&CombinationLeg, &CFTDCombinationLegField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnDelCombinationLeg((CShfeFtdcCombinationLegField *)&CombinationLeg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///别名定义通知
void CFtdcUserApiImpl::OnRtnAliasDefine(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDAliasDefineField AliasDefine;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDAliasDefineField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&AliasDefine);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnAliasDefine,", szTimeBuffer);
			FIELD_TO_STRING((char *)&AliasDefine, &CFTDAliasDefineField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnAliasDefine((CShfeFtdcAliasDefineField *)&AliasDefine);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///数据流回退通知
void CFtdcUserApiImpl::OnRtnFlowMessageCancel(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDFlowMessageCancelField FlowMessageCancel;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDFlowMessageCancelField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&FlowMessageCancel);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnFlowMessageCancel,", szTimeBuffer);
			FIELD_TO_STRING((char *)&FlowMessageCancel, &CFTDFlowMessageCancelField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnFlowMessageCancel((CShfeFtdcFlowMessageCancelField *)&FlowMessageCancel);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///公告通知
void CFtdcUserApiImpl::OnRtnBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDBulletinField Bulletin;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDBulletinField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&Bulletin);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnBulletin,", szTimeBuffer);
			FIELD_TO_STRING((char *)&Bulletin, &CFTDBulletinField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnBulletin((CShfeFtdcBulletinField *)&Bulletin);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///普通行情通知
void CFtdcUserApiImpl::OnRtnMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDMarketDataField MarketData;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDMarketDataField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&MarketData);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMarketData,", szTimeBuffer);
			FIELD_TO_STRING((char *)&MarketData, &CFTDMarketDataField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMarketData((CShfeFtdcMarketDataField *)&MarketData);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///深度行情通知
void CFtdcUserApiImpl::OnRtnDepthMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDDepthMarketDataField DepthMarketData;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDDepthMarketDataField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&DepthMarketData);
		CFtdcUserApiImplBase::OnRtnDepthMarketData(&DepthMarketData, nSequenceSeries);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnDepthMarketData,", szTimeBuffer);
			FIELD_TO_STRING((char *)&DepthMarketData, &CFTDDepthMarketDataField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnDepthMarketData((CShfeFtdcDepthMarketDataField *)&DepthMarketData);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///管理报单通知
void CFtdcUserApiImpl::OnRtnAdminOrder(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDAdminOrderField AdminOrder;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDAdminOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&AdminOrder);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnAdminOrder,", szTimeBuffer);
			FIELD_TO_STRING((char *)&AdminOrder, &CFTDAdminOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnAdminOrder((CShfeFtdcAdminOrderField *)&AdminOrder);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///报单录入错误回报
void CFtdcUserApiImpl::OnErrRtnOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputOrderField InputOrder;
	CShfeFtdcInputOrderField *pInputOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputOrder);
		itor.Next();
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnErrRtnOrderInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputOrder, &CFTDInputOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputOrder = (CShfeFtdcInputOrderField *)&InputOrder;
			m_pSpi->OnErrRtnOrderInsert(pInputOrder, pRspInfoField);
		}
	}
	
	if (pInputOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnErrRtnOrderInsert(pInputOrder, pRspInfoField);
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///报单操作错误回报
void CFtdcUserApiImpl::OnErrRtnOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDOrderActionField OrderAction;
	CShfeFtdcOrderActionField *pOrderAction = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDOrderActionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&OrderAction);
		itor.Next();
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnErrRtnOrderAction,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&OrderAction, &CFTDOrderActionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pOrderAction = (CShfeFtdcOrderActionField *)&OrderAction;
			m_pSpi->OnErrRtnOrderAction(pOrderAction, pRspInfoField);
		}
	}
	
	if (pOrderAction == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnErrRtnOrderAction(pOrderAction, pRspInfoField);
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///报价录入错误回报
void CFtdcUserApiImpl::OnErrRtnQuoteInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputQuoteField InputQuote;
	CShfeFtdcInputQuoteField *pInputQuote = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputQuoteField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputQuote);
		itor.Next();
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnErrRtnQuoteInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputQuote, &CFTDInputQuoteField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputQuote = (CShfeFtdcInputQuoteField *)&InputQuote;
			m_pSpi->OnErrRtnQuoteInsert(pInputQuote, pRspInfoField);
		}
	}
	
	if (pInputQuote == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnErrRtnQuoteInsert(pInputQuote, pRspInfoField);
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///报价操作错误回报
void CFtdcUserApiImpl::OnErrRtnQuoteAction(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDQuoteActionField QuoteAction;
	CShfeFtdcQuoteActionField *pQuoteAction = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDQuoteActionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&QuoteAction);
		itor.Next();
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnErrRtnQuoteAction,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&QuoteAction, &CFTDQuoteActionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pQuoteAction = (CShfeFtdcQuoteActionField *)&QuoteAction;
			m_pSpi->OnErrRtnQuoteAction(pQuoteAction, pRspInfoField);
		}
	}
	
	if (pQuoteAction == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnErrRtnQuoteAction(pQuoteAction, pRspInfoField);
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///执行宣告录入错误回报
void CFtdcUserApiImpl::OnErrRtnExecOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputExecOrderField InputExecOrder;
	CShfeFtdcInputExecOrderField *pInputExecOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputExecOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputExecOrder);
		itor.Next();
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnErrRtnExecOrderInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputExecOrder, &CFTDInputExecOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputExecOrder = (CShfeFtdcInputExecOrderField *)&InputExecOrder;
			m_pSpi->OnErrRtnExecOrderInsert(pInputExecOrder, pRspInfoField);
		}
	}
	
	if (pInputExecOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnErrRtnExecOrderInsert(pInputExecOrder, pRspInfoField);
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///执行宣告操作错误回报
void CFtdcUserApiImpl::OnErrRtnExecOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDExecOrderActionField ExecOrderAction;
	CShfeFtdcExecOrderActionField *pExecOrderAction = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDExecOrderActionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&ExecOrderAction);
		itor.Next();
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnErrRtnExecOrderAction,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&ExecOrderAction, &CFTDExecOrderActionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pExecOrderAction = (CShfeFtdcExecOrderActionField *)&ExecOrderAction;
			m_pSpi->OnErrRtnExecOrderAction(pExecOrderAction, pRspInfoField);
		}
	}
	
	if (pExecOrderAction == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnErrRtnExecOrderAction(pExecOrderAction, pRspInfoField);
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///非标组合报单录入错误回报
void CFtdcUserApiImpl::OnErrRtnCombOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDInputCombOrderField InputCombOrder;
	CShfeFtdcInputCombOrderField *pInputCombOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDInputCombOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&InputCombOrder);
		itor.Next();
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnErrRtnCombOrderInsert,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&InputCombOrder, &CFTDInputCombOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pInputCombOrder = (CShfeFtdcInputCombOrderField *)&InputCombOrder;
			m_pSpi->OnErrRtnCombOrderInsert(pInputCombOrder, pRspInfoField);
		}
	}
	
	if (pInputCombOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnErrRtnCombOrderInsert(pInputCombOrder, pRspInfoField);
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///汇率查询应答
void CFtdcUserApiImpl::OnRspQryExchangeRate(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspExchangeRateField RspExchangeRate;
	CShfeFtdcRspExchangeRateField *pRspExchangeRate = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspExchangeRateField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspExchangeRate);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspExchangeRate = (CShfeFtdcRspExchangeRateField *)&RspExchangeRate;
			m_pSpi->OnRspQryExchangeRate(pRspExchangeRate, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryExchangeRate,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspExchangeRate, &CFTDRspExchangeRateField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspExchangeRate == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryExchangeRate(pRspExchangeRate, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///CPU应答
void CFtdcUserApiImpl::OnRspQryTopCpuInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTopCpuInfoField RspQryTopCpuInfo;
	CShfeFtdcRspQryTopCpuInfoField *pRspQryTopCpuInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTopCpuInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTopCpuInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTopCpuInfo = (CShfeFtdcRspQryTopCpuInfoField *)&RspQryTopCpuInfo;
			m_pSpi->OnRspQryTopCpuInfoTopic(pRspQryTopCpuInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryTopCpuInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTopCpuInfoTopic(pRspQryTopCpuInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///CPU应答
void CFtdcUserApiImpl::OnRtnTopCpuInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnTopCpuInfoField RtnTopCpuInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnTopCpuInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnTopCpuInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnTopCpuInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnTopCpuInfo, &CFTDRtnTopCpuInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTopCpuInfoTopic((CShfeFtdcRtnTopCpuInfoField *)&RtnTopCpuInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///Mem应答
void CFtdcUserApiImpl::OnRspQryTopMemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTopMemInfoField RspQryTopMemInfo;
	CShfeFtdcRspQryTopMemInfoField *pRspQryTopMemInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTopMemInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTopMemInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTopMemInfo = (CShfeFtdcRspQryTopMemInfoField *)&RspQryTopMemInfo;
			m_pSpi->OnRspQryTopMemInfoTopic(pRspQryTopMemInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryTopMemInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTopMemInfoTopic(pRspQryTopMemInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///Mem应答
void CFtdcUserApiImpl::OnRtnTopMemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnTopMemInfoField RtnTopMemInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnTopMemInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnTopMemInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnTopMemInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnTopMemInfo, &CFTDRtnTopMemInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTopMemInfoTopic((CShfeFtdcRtnTopMemInfoField *)&RtnTopMemInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///process应答
void CFtdcUserApiImpl::OnRspQryTopProcessInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTopProcessInfoField RspQryTopProcessInfo;
	CShfeFtdcRspQryTopProcessInfoField *pRspQryTopProcessInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTopProcessInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTopProcessInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTopProcessInfo = (CShfeFtdcRspQryTopProcessInfoField *)&RspQryTopProcessInfo;
			m_pSpi->OnRspQryTopProcessInfoTopic(pRspQryTopProcessInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryTopProcessInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTopProcessInfoTopic(pRspQryTopProcessInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///process应答
void CFtdcUserApiImpl::OnRtnTopProcessInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnTopProcessInfoField RtnTopProcessInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnTopProcessInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnTopProcessInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnTopProcessInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnTopProcessInfo, &CFTDRtnTopProcessInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTopProcessInfoTopic((CShfeFtdcRtnTopProcessInfoField *)&RtnTopProcessInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///filesystem应答
void CFtdcUserApiImpl::OnRspQryFileSystemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryFileSystemInfoField RspQryFileSystemInfo;
	CShfeFtdcRspQryFileSystemInfoField *pRspQryFileSystemInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryFileSystemInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryFileSystemInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryFileSystemInfo = (CShfeFtdcRspQryFileSystemInfoField *)&RspQryFileSystemInfo;
			m_pSpi->OnRspQryFileSystemInfoTopic(pRspQryFileSystemInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryFileSystemInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryFileSystemInfoTopic(pRspQryFileSystemInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///filesystem应答
void CFtdcUserApiImpl::OnRtnFileSystemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnFileSystemInfoField RtnFileSystemInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnFileSystemInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnFileSystemInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnFileSystemInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnFileSystemInfo, &CFTDRtnFileSystemInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnFileSystemInfoTopic((CShfeFtdcRtnFileSystemInfoField *)&RtnFileSystemInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///network应答
void CFtdcUserApiImpl::OnRspQryNetworkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetworkInfoField RspQryNetworkInfo;
	CShfeFtdcRspQryNetworkInfoField *pRspQryNetworkInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetworkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetworkInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetworkInfo = (CShfeFtdcRspQryNetworkInfoField *)&RspQryNetworkInfo;
			m_pSpi->OnRspQryNetworkInfoTopic(pRspQryNetworkInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetworkInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetworkInfoTopic(pRspQryNetworkInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///network应答
void CFtdcUserApiImpl::OnRtnNetworkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetworkInfoField RtnNetworkInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetworkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetworkInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetworkInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetworkInfo, &CFTDRtnNetworkInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetworkInfoTopic((CShfeFtdcRtnNetworkInfoField *)&RtnNetworkInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///客户端登录应答
void CFtdcUserApiImpl::OnRspQryClientLoginTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryClientLoginField RspQryClientLogin;
	CShfeFtdcRspQryClientLoginField *pRspQryClientLogin = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryClientLoginField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryClientLogin);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryClientLogin = (CShfeFtdcRspQryClientLoginField *)&RspQryClientLogin;
			m_pSpi->OnRspQryClientLoginTopic(pRspQryClientLogin, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryClientLogin == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryClientLoginTopic(pRspQryClientLogin, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///获得监控对象信息应答
void CFtdcUserApiImpl::OnRspQryMonitorObjectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonitorObjectField RspQryMonitorObject;
	CShfeFtdcRspQryMonitorObjectField *pRspQryMonitorObject = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonitorObjectField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonitorObject);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonitorObject = (CShfeFtdcRspQryMonitorObjectField *)&RspQryMonitorObject;
			m_pSpi->OnRspQryMonitorObjectTopic(pRspQryMonitorObject, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonitorObject == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonitorObjectTopic(pRspQryMonitorObject, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///获得监控对象信息应答
void CFtdcUserApiImpl::OnRtnMonitorObjectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonitorObjectField RtnMonitorObject;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonitorObjectField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonitorObject);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonitorObjectTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonitorObject, &CFTDRtnMonitorObjectField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonitorObjectTopic((CShfeFtdcRtnMonitorObjectField *)&RtnMonitorObject);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///获得业务进程和主机的对应关系应答
void CFtdcUserApiImpl::OnRspQryObjectRationalTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryObjectRationalField RspQryObjectRational;
	CShfeFtdcRspQryObjectRationalField *pRspQryObjectRational = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryObjectRationalField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryObjectRational);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryObjectRational = (CShfeFtdcRspQryObjectRationalField *)&RspQryObjectRational;
			m_pSpi->OnRspQryObjectRationalTopic(pRspQryObjectRational, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryObjectRational == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryObjectRationalTopic(pRspQryObjectRational, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///获得业务进程和主机的对应关系应答
void CFtdcUserApiImpl::OnRtnObjectRationalTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnObjectRationalField RtnObjectRational;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnObjectRationalField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnObjectRational);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnObjectRationalTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnObjectRational, &CFTDRtnObjectRationalField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnObjectRationalTopic((CShfeFtdcRtnObjectRationalField *)&RtnObjectRational);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///日志文件内容应答
void CFtdcUserApiImpl::OnRspQrySyslogInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySyslogInfoField RspQrySyslogInfo;
	CShfeFtdcRspQrySyslogInfoField *pRspQrySyslogInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySyslogInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySyslogInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySyslogInfo = (CShfeFtdcRspQrySyslogInfoField *)&RspQrySyslogInfo;
			m_pSpi->OnRspQrySyslogInfoTopic(pRspQrySyslogInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQrySyslogInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySyslogInfoTopic(pRspQrySyslogInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///日志文件内容应答
void CFtdcUserApiImpl::OnRtnSyslogInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnSyslogInfoField RtnSyslogInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnSyslogInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnSyslogInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnSyslogInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnSyslogInfo, &CFTDRtnSyslogInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSyslogInfoTopic((CShfeFtdcRtnSyslogInfoField *)&RtnSyslogInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///监控内容订阅应答
void CFtdcUserApiImpl::OnRspQrySubscriberTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySubscriberField RspQrySubscriber;
	CShfeFtdcRspQrySubscriberField *pRspQrySubscriber = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySubscriberField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySubscriber);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySubscriber = (CShfeFtdcRspQrySubscriberField *)&RspQrySubscriber;
			m_pSpi->OnRspQrySubscriberTopic(pRspQrySubscriber, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQrySubscriber == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySubscriberTopic(pRspQrySubscriber, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///对象关系查询应答
void CFtdcUserApiImpl::OnRspQryOidRelationTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryOidRelationField RspQryOidRelation;
	CShfeFtdcRspQryOidRelationField *pRspQryOidRelation = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryOidRelationField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryOidRelation);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryOidRelation = (CShfeFtdcRspQryOidRelationField *)&RspQryOidRelation;
			m_pSpi->OnRspQryOidRelationTopic(pRspQryOidRelation, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryOidRelation == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryOidRelationTopic(pRspQryOidRelation, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///对象关系查询应答
void CFtdcUserApiImpl::OnRtnOidRelationTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnOidRelationField RtnOidRelation;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnOidRelationField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnOidRelation);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnOidRelationTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnOidRelation, &CFTDRtnOidRelationField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnOidRelationTopic((CShfeFtdcRtnOidRelationField *)&RtnOidRelation);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///用户信息查询请求应答
void CFtdcUserApiImpl::OnRspQryUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryUserInfoField RspQryUserInfo;
	CShfeFtdcRspQryUserInfoField *pRspQryUserInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryUserInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryUserInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryUserInfo = (CShfeFtdcRspQryUserInfoField *)&RspQryUserInfo;
			m_pSpi->OnRspQryUserInfoTopic(pRspQryUserInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryUserInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryUserInfoTopic(pRspQryUserInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户信息查询请求应答
void CFtdcUserApiImpl::OnRtnUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnUserInfoField RtnUserInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnUserInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnUserInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnUserInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnUserInfo, &CFTDRtnUserInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnUserInfoTopic((CShfeFtdcRtnUserInfoField *)&RtnUserInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///在线用户信息查询请求应答
void CFtdcUserApiImpl::OnRspQryOnlineUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryOnlineUserInfoField RspQryOnlineUserInfo;
	CShfeFtdcRspQryOnlineUserInfoField *pRspQryOnlineUserInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryOnlineUserInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryOnlineUserInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryOnlineUserInfo = (CShfeFtdcRspQryOnlineUserInfoField *)&RspQryOnlineUserInfo;
			m_pSpi->OnRspQryOnlineUserInfoTopic(pRspQryOnlineUserInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryOnlineUserInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryOnlineUserInfoTopic(pRspQryOnlineUserInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///在线用户信息查询请求应答
void CFtdcUserApiImpl::OnRtnOnlineUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnOnlineUserInfoField RtnOnlineUserInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnOnlineUserInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnOnlineUserInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnOnlineUserInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnOnlineUserInfo, &CFTDRtnOnlineUserInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnOnlineUserInfoTopic((CShfeFtdcRtnOnlineUserInfoField *)&RtnOnlineUserInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///告警事件查询请求应答
void CFtdcUserApiImpl::OnRspQryWarningEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryWarningEventField RspQryWarningEvent;
	CShfeFtdcRspQryWarningEventField *pRspQryWarningEvent = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryWarningEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryWarningEvent);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryWarningEvent = (CShfeFtdcRspQryWarningEventField *)&RspQryWarningEvent;
			m_pSpi->OnRspQryWarningEventTopic(pRspQryWarningEvent, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryWarningEvent == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryWarningEventTopic(pRspQryWarningEvent, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///告警事件查询请求应答
void CFtdcUserApiImpl::OnRtnWarningEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnWarningEventField RtnWarningEvent;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnWarningEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnWarningEvent);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnWarningEventTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnWarningEvent, &CFTDRtnWarningEventField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnWarningEventTopic((CShfeFtdcRtnWarningEventField *)&RtnWarningEvent);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///CPU使用率查询请求应答
void CFtdcUserApiImpl::OnRspQryCPUUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryCPUUsageField RspQryCPUUsage;
	CShfeFtdcRspQryCPUUsageField *pRspQryCPUUsage = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryCPUUsageField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryCPUUsage);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryCPUUsage = (CShfeFtdcRspQryCPUUsageField *)&RspQryCPUUsage;
			m_pSpi->OnRspQryCPUUsageTopic(pRspQryCPUUsage, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryCPUUsage == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryCPUUsageTopic(pRspQryCPUUsage, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///CPU使用率查询请求应答
void CFtdcUserApiImpl::OnRtnCPUUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnCPUUsageField RtnCPUUsage;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnCPUUsageField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnCPUUsage);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnCPUUsageTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnCPUUsage, &CFTDRtnCPUUsageField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnCPUUsageTopic((CShfeFtdcRtnCPUUsageField *)&RtnCPUUsage);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///内存使用率查询请求应答
void CFtdcUserApiImpl::OnRspQryMemoryUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMemoryUsageField RspQryMemoryUsage;
	CShfeFtdcRspQryMemoryUsageField *pRspQryMemoryUsage = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMemoryUsageField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMemoryUsage);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMemoryUsage = (CShfeFtdcRspQryMemoryUsageField *)&RspQryMemoryUsage;
			m_pSpi->OnRspQryMemoryUsageTopic(pRspQryMemoryUsage, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMemoryUsage == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMemoryUsageTopic(pRspQryMemoryUsage, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///内存使用率查询请求应答
void CFtdcUserApiImpl::OnRtnMemoryUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMemoryUsageField RtnMemoryUsage;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMemoryUsageField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMemoryUsage);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMemoryUsageTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMemoryUsage, &CFTDRtnMemoryUsageField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMemoryUsageTopic((CShfeFtdcRtnMemoryUsageField *)&RtnMemoryUsage);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///硬盘使用率查询请求应答
void CFtdcUserApiImpl::OnRspQryDiskUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryDiskUsageField RspQryDiskUsage;
	CShfeFtdcRspQryDiskUsageField *pRspQryDiskUsage = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryDiskUsageField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryDiskUsage);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryDiskUsage = (CShfeFtdcRspQryDiskUsageField *)&RspQryDiskUsage;
			m_pSpi->OnRspQryDiskUsageTopic(pRspQryDiskUsage, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryDiskUsage == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryDiskUsageTopic(pRspQryDiskUsage, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///硬盘使用率查询请求应答
void CFtdcUserApiImpl::OnRtnDiskUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnDiskUsageField RtnDiskUsage;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnDiskUsageField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnDiskUsage);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnDiskUsageTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnDiskUsage, &CFTDRtnDiskUsageField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnDiskUsageTopic((CShfeFtdcRtnDiskUsageField *)&RtnDiskUsage);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///对象状态指标查询应答
void CFtdcUserApiImpl::OnRspQryObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryObjectAttrField RspQryObjectAttr;
	CShfeFtdcRspQryObjectAttrField *pRspQryObjectAttr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryObjectAttr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryObjectAttr = (CShfeFtdcRspQryObjectAttrField *)&RspQryObjectAttr;
			m_pSpi->OnRspQryObjectAttrTopic(pRspQryObjectAttr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryObjectAttr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryObjectAttrTopic(pRspQryObjectAttr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///对象状态指标查询应答
void CFtdcUserApiImpl::OnRtnObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnObjectAttrField RtnObjectAttr;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnObjectAttr);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnObjectAttrTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnObjectAttr, &CFTDRtnObjectAttrField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnObjectAttrTopic((CShfeFtdcRtnObjectAttrField *)&RtnObjectAttr);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///历史对象状态指标查询应答
void CFtdcUserApiImpl::OnRspQryHistoryObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryHistoryObjectAttrField RspQryHistoryObjectAttr;
	CShfeFtdcRspQryHistoryObjectAttrField *pRspQryHistoryObjectAttr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryHistoryObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryHistoryObjectAttr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryHistoryObjectAttr = (CShfeFtdcRspQryHistoryObjectAttrField *)&RspQryHistoryObjectAttr;
			m_pSpi->OnRspQryHistoryObjectAttrTopic(pRspQryHistoryObjectAttr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryHistoryObjectAttr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryHistoryObjectAttrTopic(pRspQryHistoryObjectAttr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///历史对象状态指标查询应答
void CFtdcUserApiImpl::OnRtnHistoryObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnHistoryObjectAttrField RtnHistoryObjectAttr;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnHistoryObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnHistoryObjectAttr);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnHistoryObjectAttrTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnHistoryObjectAttr, &CFTDRtnHistoryObjectAttrField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnHistoryObjectAttrTopic((CShfeFtdcRtnHistoryObjectAttrField *)&RtnHistoryObjectAttr);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///前置响应信息查询应答
void CFtdcUserApiImpl::OnRspQryFrontInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryFrontInfoField RspQryFrontInfo;
	CShfeFtdcRspQryFrontInfoField *pRspQryFrontInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryFrontInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryFrontInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryFrontInfo = (CShfeFtdcRspQryFrontInfoField *)&RspQryFrontInfo;
			m_pSpi->OnRspQryFrontInfoTopic(pRspQryFrontInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryFrontInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryFrontInfoTopic(pRspQryFrontInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///前置响应信息查询应答
void CFtdcUserApiImpl::OnRtnFrontInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnFrontInfoField RtnFrontInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnFrontInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnFrontInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnFrontInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnFrontInfo, &CFTDRtnFrontInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnFrontInfoTopic((CShfeFtdcRtnFrontInfoField *)&RtnFrontInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///用户登录应答
void CFtdcUserApiImpl::OnRspQrySysUserLoginTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySysUserLoginField RspQrySysUserLogin;
	CShfeFtdcRspQrySysUserLoginField *pRspQrySysUserLogin = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySysUserLoginField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySysUserLogin);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySysUserLogin = (CShfeFtdcRspQrySysUserLoginField *)&RspQrySysUserLogin;
			m_pSpi->OnRspQrySysUserLoginTopic(pRspQrySysUserLogin, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQrySysUserLogin == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySysUserLoginTopic(pRspQrySysUserLogin, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户登出应答
void CFtdcUserApiImpl::OnRspQrySysUserLogoutTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySysUserLogoutField RspQrySysUserLogout;
	CShfeFtdcRspQrySysUserLogoutField *pRspQrySysUserLogout = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySysUserLogoutField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySysUserLogout);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySysUserLogout = (CShfeFtdcRspQrySysUserLogoutField *)&RspQrySysUserLogout;
			m_pSpi->OnRspQrySysUserLogoutTopic(pRspQrySysUserLogout, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQrySysUserLogout == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySysUserLogoutTopic(pRspQrySysUserLogout, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户修改密码应答
void CFtdcUserApiImpl::OnRspQrySysUserPasswordUpdateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySysUserPasswordUpdateField RspQrySysUserPasswordUpdate;
	CShfeFtdcRspQrySysUserPasswordUpdateField *pRspQrySysUserPasswordUpdate = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySysUserPasswordUpdateField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySysUserPasswordUpdate);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySysUserPasswordUpdate = (CShfeFtdcRspQrySysUserPasswordUpdateField *)&RspQrySysUserPasswordUpdate;
			m_pSpi->OnRspQrySysUserPasswordUpdateTopic(pRspQrySysUserPasswordUpdate, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQrySysUserPasswordUpdate == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySysUserPasswordUpdateTopic(pRspQrySysUserPasswordUpdate, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///注册用户应答
void CFtdcUserApiImpl::OnRspQrySysUserRegisterTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySysUserRegisterField RspQrySysUserRegister;
	CShfeFtdcRspQrySysUserRegisterField *pRspQrySysUserRegister = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySysUserRegisterField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySysUserRegister);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySysUserRegister = (CShfeFtdcRspQrySysUserRegisterField *)&RspQrySysUserRegister;
			m_pSpi->OnRspQrySysUserRegisterTopic(pRspQrySysUserRegister, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQrySysUserRegister == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySysUserRegisterTopic(pRspQrySysUserRegister, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///删除用户应答
void CFtdcUserApiImpl::OnRspQrySysUserDeleteTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySysUserDeleteField RspQrySysUserDelete;
	CShfeFtdcRspQrySysUserDeleteField *pRspQrySysUserDelete = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySysUserDeleteField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySysUserDelete);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySysUserDelete = (CShfeFtdcRspQrySysUserDeleteField *)&RspQrySysUserDelete;
			m_pSpi->OnRspQrySysUserDeleteTopic(pRspQrySysUserDelete, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQrySysUserDelete == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySysUserDeleteTopic(pRspQrySysUserDelete, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///客户初始化应答
void CFtdcUserApiImpl::OnRspQryClientInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryClientInitField RspQryClientInit;
	CShfeFtdcRspQryClientInitField *pRspQryClientInit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryClientInitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryClientInit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryClientInit = (CShfeFtdcRspQryClientInitField *)&RspQryClientInit;
			m_pSpi->OnRspQryClientInitTopic(pRspQryClientInit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryClientInit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryClientInitTopic(pRspQryClientInit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///客户初始化应答
void CFtdcUserApiImpl::OnRtnClientInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnClientInitField RtnClientInit;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnClientInitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnClientInit);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnClientInitTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnClientInit, &CFTDRtnClientInitField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnClientInitTopic((CShfeFtdcRtnClientInitField *)&RtnClientInit);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///交易日志查询应答
void CFtdcUserApiImpl::OnRspQryTradeLogTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTradeLogField RspQryTradeLog;
	CShfeFtdcRspQryTradeLogField *pRspQryTradeLog = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTradeLogField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTradeLog);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTradeLog = (CShfeFtdcRspQryTradeLogField *)&RspQryTradeLog;
			m_pSpi->OnRspQryTradeLogTopic(pRspQryTradeLog, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryTradeLog == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTradeLogTopic(pRspQryTradeLog, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易日志查询应答
void CFtdcUserApiImpl::OnRtnTradeLogTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnTradeLogField RtnTradeLog;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnTradeLogField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnTradeLog);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnTradeLogTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnTradeLog, &CFTDRtnTradeLogField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTradeLogTopic((CShfeFtdcRtnTradeLogField *)&RtnTradeLog);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///交易峰值查询应答
void CFtdcUserApiImpl::OnRspQryTradepeakTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTradepeakField RspQryTradepeak;
	CShfeFtdcRspQryTradepeakField *pRspQryTradepeak = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTradepeakField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTradepeak);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTradepeak = (CShfeFtdcRspQryTradepeakField *)&RspQryTradepeak;
			m_pSpi->OnRspQryTradepeakTopic(pRspQryTradepeak, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryTradepeak == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTradepeakTopic(pRspQryTradepeak, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///
void CFtdcUserApiImpl::OnRtnUpdateSysConfigTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnUpdateSysConfigField RtnUpdateSysConfig;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnUpdateSysConfigField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnUpdateSysConfig);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnUpdateSysConfigTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnUpdateSysConfig, &CFTDRtnUpdateSysConfigField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnUpdateSysConfigTopic((CShfeFtdcRtnUpdateSysConfigField *)&RtnUpdateSysConfig);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///
void CFtdcUserApiImpl::OnRtnSysUser(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnSysUserField RtnSysUser;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnSysUserField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnSysUser);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnSysUser,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnSysUser, &CFTDRtnSysUserField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSysUser((CShfeFtdcRtnSysUserField *)&RtnSysUser);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///
void CFtdcUserApiImpl::OnRtnPriceLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnPriceLimitChgField RtnPriceLimitChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnPriceLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnPriceLimitChg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnPriceLimitChgTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnPriceLimitChg, &CFTDRtnPriceLimitChgField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnPriceLimitChgTopic((CShfeFtdcRtnPriceLimitChgField *)&RtnPriceLimitChg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///
void CFtdcUserApiImpl::OnRspQryHistoryCpuInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryHistoryCpuInfoField RspQryHistoryCpuInfo;
	CShfeFtdcRspQryHistoryCpuInfoField *pRspQryHistoryCpuInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryHistoryCpuInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryHistoryCpuInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryHistoryCpuInfo = (CShfeFtdcRspQryHistoryCpuInfoField *)&RspQryHistoryCpuInfo;
			m_pSpi->OnRspQryHistoryCpuInfoTopic(pRspQryHistoryCpuInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryHistoryCpuInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryHistoryCpuInfoTopic(pRspQryHistoryCpuInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///
void CFtdcUserApiImpl::OnRspQryHistoryMemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryHistoryMemInfoField RspQryHistoryMemInfo;
	CShfeFtdcRspQryHistoryMemInfoField *pRspQryHistoryMemInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryHistoryMemInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryHistoryMemInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryHistoryMemInfo = (CShfeFtdcRspQryHistoryMemInfoField *)&RspQryHistoryMemInfo;
			m_pSpi->OnRspQryHistoryMemInfoTopic(pRspQryHistoryMemInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryHistoryMemInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryHistoryMemInfoTopic(pRspQryHistoryMemInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///
void CFtdcUserApiImpl::OnRspQryHistoryNetworkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryHistoryNetworkInfoField RspQryHistoryNetworkInfo;
	CShfeFtdcRspQryHistoryNetworkInfoField *pRspQryHistoryNetworkInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryHistoryNetworkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryHistoryNetworkInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryHistoryNetworkInfo = (CShfeFtdcRspQryHistoryNetworkInfoField *)&RspQryHistoryNetworkInfo;
			m_pSpi->OnRspQryHistoryNetworkInfoTopic(pRspQryHistoryNetworkInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryHistoryNetworkInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryHistoryNetworkInfoTopic(pRspQryHistoryNetworkInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///HostConfig查询请求应答
void CFtdcUserApiImpl::OnRspQryHostConfig(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryHostConfigField RspQryHostConfig;
	CShfeFtdcRspQryHostConfigField *pRspQryHostConfig = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryHostConfigField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryHostConfig);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryHostConfig = (CShfeFtdcRspQryHostConfigField *)&RspQryHostConfig;
			m_pSpi->OnRspQryHostConfig(pRspQryHostConfig, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryHostConfig == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryHostConfig(pRspQryHostConfig, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///监控系统在线用户应答
void CFtdcUserApiImpl::OnRspQryMonitorOnlineUser(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonitorOnlineUserField RspQryMonitorOnlineUser;
	CShfeFtdcRspQryMonitorOnlineUserField *pRspQryMonitorOnlineUser = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonitorOnlineUserField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonitorOnlineUser);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonitorOnlineUser = (CShfeFtdcRspQryMonitorOnlineUserField *)&RspQryMonitorOnlineUser;
			m_pSpi->OnRspQryMonitorOnlineUser(pRspQryMonitorOnlineUser, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonitorOnlineUser == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonitorOnlineUser(pRspQryMonitorOnlineUser, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///监控系统时钟同步
void CFtdcUserApiImpl::OnRtnSysTimeSyncTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnSysTimeSyncField RtnSysTimeSync;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnSysTimeSyncField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnSysTimeSync);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnSysTimeSyncTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnSysTimeSync, &CFTDRtnSysTimeSyncField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSysTimeSyncTopic((CShfeFtdcRtnSysTimeSyncField *)&RtnSysTimeSync);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///数据中心切换通知
void CFtdcUserApiImpl::OnRtnDataCenterChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnDataCenterChgField RtnDataCenterChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnDataCenterChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnDataCenterChg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnDataCenterChgTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnDataCenterChg, &CFTDRtnDataCenterChgField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnDataCenterChgTopic((CShfeFtdcRtnDataCenterChgField *)&RtnDataCenterChg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///历史峰值查询应答
void CFtdcUserApiImpl::OnRspQryHistoryTradePeakTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryHistoryTradePeakField RspQryHistoryTradePeak;
	CShfeFtdcRspQryHistoryTradePeakField *pRspQryHistoryTradePeak = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryHistoryTradePeakField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryHistoryTradePeak);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryHistoryTradePeak = (CShfeFtdcRspQryHistoryTradePeakField *)&RspQryHistoryTradePeak;
			m_pSpi->OnRspQryHistoryTradePeakTopic(pRspQryHistoryTradePeak, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryHistoryTradePeak == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryHistoryTradePeakTopic(pRspQryHistoryTradePeak, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///历史峰值查询应答
void CFtdcUserApiImpl::OnRtnHistoryTradePeakTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnHistoryTradePeakField RtnHistoryTradePeak;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnHistoryTradePeakField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnHistoryTradePeak);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnHistoryTradePeakTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnHistoryTradePeak, &CFTDRtnHistoryTradePeakField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnHistoryTradePeakTopic((CShfeFtdcRtnHistoryTradePeakField *)&RtnHistoryTradePeak);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///日志事件查询应答
void CFtdcUserApiImpl::OnRspQrySyslogEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySyslogEventField RspQrySyslogEvent;
	CShfeFtdcRspQrySyslogEventField *pRspQrySyslogEvent = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySyslogEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySyslogEvent);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySyslogEvent = (CShfeFtdcRspQrySyslogEventField *)&RspQrySyslogEvent;
			m_pSpi->OnRspQrySyslogEventTopic(pRspQrySyslogEvent, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQrySyslogEvent == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySyslogEventTopic(pRspQrySyslogEvent, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///日志事件应答
void CFtdcUserApiImpl::OnRtnSyslogEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnSyslogEventField RtnSyslogEvent;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnSyslogEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnSyslogEvent);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnSyslogEventTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnSyslogEvent, &CFTDRtnSyslogEventField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSyslogEventTopic((CShfeFtdcRtnSyslogEventField *)&RtnSyslogEvent);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///交易日切换通知
void CFtdcUserApiImpl::OnRspQryTradeDayChangeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTradeDayChangeField RspQryTradeDayChange;
	CShfeFtdcRspQryTradeDayChangeField *pRspQryTradeDayChange = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTradeDayChangeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTradeDayChange);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTradeDayChange = (CShfeFtdcRspQryTradeDayChangeField *)&RspQryTradeDayChange;
			m_pSpi->OnRspQryTradeDayChangeTopic(pRspQryTradeDayChange, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryTradeDayChange == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTradeDayChangeTopic(pRspQryTradeDayChange, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///Web应用信息
void CFtdcUserApiImpl::OnRspQryWebAppInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryWebAppInfoField RspQryWebAppInfo;
	CShfeFtdcRspQryWebAppInfoField *pRspQryWebAppInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryWebAppInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryWebAppInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryWebAppInfo = (CShfeFtdcRspQryWebAppInfoField *)&RspQryWebAppInfo;
			m_pSpi->OnRspQryWebAppInfoTopic(pRspQryWebAppInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryWebAppInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryWebAppInfoTopic(pRspQryWebAppInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///Web应用信息
void CFtdcUserApiImpl::OnRtnWebAppInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnWebAppInfoField RtnWebAppInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnWebAppInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnWebAppInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnWebAppInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnWebAppInfo, &CFTDRtnWebAppInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnWebAppInfoTopic((CShfeFtdcRtnWebAppInfoField *)&RtnWebAppInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///应用servlet信息
void CFtdcUserApiImpl::OnRspQryServletInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryServletInfoField RspQryServletInfo;
	CShfeFtdcRspQryServletInfoField *pRspQryServletInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryServletInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryServletInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryServletInfo = (CShfeFtdcRspQryServletInfoField *)&RspQryServletInfo;
			m_pSpi->OnRspQryServletInfoTopic(pRspQryServletInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryServletInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryServletInfoTopic(pRspQryServletInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///应用servlet信息
void CFtdcUserApiImpl::OnRtnServletInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnServletInfoField RtnServletInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnServletInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnServletInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnServletInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnServletInfo, &CFTDRtnServletInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnServletInfoTopic((CShfeFtdcRtnServletInfoField *)&RtnServletInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///文件信息
void CFtdcUserApiImpl::OnRspQryFileInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryFileInfoField RspQryFileInfo;
	CShfeFtdcRspQryFileInfoField *pRspQryFileInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryFileInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryFileInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryFileInfo = (CShfeFtdcRspQryFileInfoField *)&RspQryFileInfo;
			m_pSpi->OnRspQryFileInfoTopic(pRspQryFileInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryFileInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryFileInfoTopic(pRspQryFileInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///文件信息
void CFtdcUserApiImpl::OnRtnFileInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnFileInfoField RtnFileInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnFileInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnFileInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnFileInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnFileInfo, &CFTDRtnFileInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnFileInfoTopic((CShfeFtdcRtnFileInfoField *)&RtnFileInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///应用会话信息
void CFtdcUserApiImpl::OnRspQrySessionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySessionInfoField RspQrySessionInfo;
	CShfeFtdcRspQrySessionInfoField *pRspQrySessionInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySessionInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySessionInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySessionInfo = (CShfeFtdcRspQrySessionInfoField *)&RspQrySessionInfo;
			m_pSpi->OnRspQrySessionInfoTopic(pRspQrySessionInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQrySessionInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySessionInfoTopic(pRspQrySessionInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///应用会话信息
void CFtdcUserApiImpl::OnRtnSessionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnSessionInfoField RtnSessionInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnSessionInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnSessionInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnSessionInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnSessionInfo, &CFTDRtnSessionInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSessionInfoTopic((CShfeFtdcRtnSessionInfoField *)&RtnSessionInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///JDBC信息
void CFtdcUserApiImpl::OnRspQryJDBCInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryJDBCInfoField RspQryJDBCInfo;
	CShfeFtdcRspQryJDBCInfoField *pRspQryJDBCInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryJDBCInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryJDBCInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryJDBCInfo = (CShfeFtdcRspQryJDBCInfoField *)&RspQryJDBCInfo;
			m_pSpi->OnRspQryJDBCInfoTopic(pRspQryJDBCInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryJDBCInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryJDBCInfoTopic(pRspQryJDBCInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///JDBC信息
void CFtdcUserApiImpl::OnRtnJDBCInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnJDBCInfoField RtnJDBCInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnJDBCInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnJDBCInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnJDBCInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnJDBCInfo, &CFTDRtnJDBCInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnJDBCInfoTopic((CShfeFtdcRtnJDBCInfoField *)&RtnJDBCInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///线程信息
void CFtdcUserApiImpl::OnRspQryThreadInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryThreadInfoField RspQryThreadInfo;
	CShfeFtdcRspQryThreadInfoField *pRspQryThreadInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryThreadInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryThreadInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryThreadInfo = (CShfeFtdcRspQryThreadInfoField *)&RspQryThreadInfo;
			m_pSpi->OnRspQryThreadInfoTopic(pRspQryThreadInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryThreadInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryThreadInfoTopic(pRspQryThreadInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///线程信息
void CFtdcUserApiImpl::OnRtnThreadInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnThreadInfoField RtnThreadInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnThreadInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnThreadInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnThreadInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnThreadInfo, &CFTDRtnThreadInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnThreadInfoTopic((CShfeFtdcRtnThreadInfoField *)&RtnThreadInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///虚拟机信息
void CFtdcUserApiImpl::OnRspQryVMInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryVMInfoField RspQryVMInfo;
	CShfeFtdcRspQryVMInfoField *pRspQryVMInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryVMInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryVMInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryVMInfo = (CShfeFtdcRspQryVMInfoField *)&RspQryVMInfo;
			m_pSpi->OnRspQryVMInfoTopic(pRspQryVMInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryVMInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryVMInfoTopic(pRspQryVMInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///虚拟机信息
void CFtdcUserApiImpl::OnRtnVMInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnVMInfoField RtnVMInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnVMInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnVMInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnVMInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnVMInfo, &CFTDRtnVMInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnVMInfoTopic((CShfeFtdcRtnVMInfoField *)&RtnVMInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///系统属性信息
void CFtdcUserApiImpl::OnRspQryPropertyInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryPropertyInfoField RspQryPropertyInfo;
	CShfeFtdcRspQryPropertyInfoField *pRspQryPropertyInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryPropertyInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryPropertyInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryPropertyInfo = (CShfeFtdcRspQryPropertyInfoField *)&RspQryPropertyInfo;
			m_pSpi->OnRspQryPropertyInfoTopic(pRspQryPropertyInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryPropertyInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPropertyInfoTopic(pRspQryPropertyInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///系统属性信息
void CFtdcUserApiImpl::OnRtnPropertyInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnPropertyInfoField RtnPropertyInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnPropertyInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnPropertyInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnPropertyInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnPropertyInfo, &CFTDRtnPropertyInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnPropertyInfoTopic((CShfeFtdcRtnPropertyInfoField *)&RtnPropertyInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///系统内存池信息
void CFtdcUserApiImpl::OnRspQryMemPoolInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMemPoolInfoField RspQryMemPoolInfo;
	CShfeFtdcRspQryMemPoolInfoField *pRspQryMemPoolInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMemPoolInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMemPoolInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMemPoolInfo = (CShfeFtdcRspQryMemPoolInfoField *)&RspQryMemPoolInfo;
			m_pSpi->OnRspQryMemPoolInfoTopic(pRspQryMemPoolInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMemPoolInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMemPoolInfoTopic(pRspQryMemPoolInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///系统内存池信息
void CFtdcUserApiImpl::OnRtnMemPoolInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMemPoolInfoField RtnMemPoolInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMemPoolInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMemPoolInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMemPoolInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMemPoolInfo, &CFTDRtnMemPoolInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMemPoolInfoTopic((CShfeFtdcRtnMemPoolInfoField *)&RtnMemPoolInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///文件内容信息
void CFtdcUserApiImpl::OnRspQryFileContentInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryFileContentInfoField RspQryFileContentInfo;
	CShfeFtdcRspQryFileContentInfoField *pRspQryFileContentInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryFileContentInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryFileContentInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryFileContentInfo = (CShfeFtdcRspQryFileContentInfoField *)&RspQryFileContentInfo;
			m_pSpi->OnRspQryFileContentInfoTopic(pRspQryFileContentInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryFileContentInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryFileContentInfoTopic(pRspQryFileContentInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///文件内容信息
void CFtdcUserApiImpl::OnRtnFileContentInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnFileContentInfoField RtnFileContentInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnFileContentInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnFileContentInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnFileContentInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnFileContentInfo, &CFTDRtnFileContentInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnFileContentInfoTopic((CShfeFtdcRtnFileContentInfoField *)&RtnFileContentInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///连接信息
void CFtdcUserApiImpl::OnRspQryConnectionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryConnectionInfoField RspQryConnectionInfo;
	CShfeFtdcRspQryConnectionInfoField *pRspQryConnectionInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryConnectionInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryConnectionInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryConnectionInfo = (CShfeFtdcRspQryConnectionInfoField *)&RspQryConnectionInfo;
			m_pSpi->OnRspQryConnectionInfoTopic(pRspQryConnectionInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryConnectionInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryConnectionInfoTopic(pRspQryConnectionInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///连接信息
void CFtdcUserApiImpl::OnRtnConnectionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnConnectionInfoField RtnConnectionInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnConnectionInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnConnectionInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnConnectionInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnConnectionInfo, &CFTDRtnConnectionInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnConnectionInfoTopic((CShfeFtdcRtnConnectionInfoField *)&RtnConnectionInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///连接器信息
void CFtdcUserApiImpl::OnRspQryConnectorInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryConnectorInfoField RspQryConnectorInfo;
	CShfeFtdcRspQryConnectorInfoField *pRspQryConnectorInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryConnectorInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryConnectorInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryConnectorInfo = (CShfeFtdcRspQryConnectorInfoField *)&RspQryConnectorInfo;
			m_pSpi->OnRspQryConnectorInfoTopic(pRspQryConnectorInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryConnectorInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryConnectorInfoTopic(pRspQryConnectorInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///连接器信息
void CFtdcUserApiImpl::OnRtnConnectorInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnConnectorInfoField RtnConnectorInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnConnectorInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnConnectorInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnConnectorInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnConnectorInfo, &CFTDRtnConnectorInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnConnectorInfoTopic((CShfeFtdcRtnConnectorInfoField *)&RtnConnectorInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///数据库查询应答
void CFtdcUserApiImpl::OnRspQryDBQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryDBQueryField RspQryDBQuery;
	CShfeFtdcRspQryDBQueryField *pRspQryDBQuery = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryDBQueryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryDBQuery);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryDBQuery = (CShfeFtdcRspQryDBQueryField *)&RspQryDBQuery;
			m_pSpi->OnRspQryDBQueryTopic(pRspQryDBQuery, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryDBQuery == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryDBQueryTopic(pRspQryDBQuery, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///数据库查询应答
void CFtdcUserApiImpl::OnRtnDBQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnDBQueryField RtnDBQuery;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnDBQueryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnDBQuery);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnDBQueryTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnDBQuery, &CFTDRtnDBQueryField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnDBQueryTopic((CShfeFtdcRtnDBQueryField *)&RtnDBQuery);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///通用返回应答
void CFtdcUserApiImpl::OnRspQryGeneralFieldTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDSysGeneralFieldField SysGeneralField;
	CShfeFtdcSysGeneralFieldField *pSysGeneralField = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDSysGeneralFieldField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&SysGeneralField);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pSysGeneralField = (CShfeFtdcSysGeneralFieldField *)&SysGeneralField;
			m_pSpi->OnRspQryGeneralFieldTopic(pSysGeneralField, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryGeneralFieldTopic,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&SysGeneralField, &CFTDSysGeneralFieldField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pSysGeneralField == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryGeneralFieldTopic(pSysGeneralField, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///通用返回应答
void CFtdcUserApiImpl::OnRtnGeneralFieldTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDSysGeneralFieldField SysGeneralField;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDSysGeneralFieldField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&SysGeneralField);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnGeneralFieldTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&SysGeneralField, &CFTDSysGeneralFieldField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnGeneralFieldTopic((CShfeFtdcSysGeneralFieldField *)&SysGeneralField);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///文件传输应答
void CFtdcUserApiImpl::OnRspQryGetFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryGetFileField RspQryGetFile;
	CShfeFtdcRspQryGetFileField *pRspQryGetFile = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryGetFileField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryGetFile);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryGetFile = (CShfeFtdcRspQryGetFileField *)&RspQryGetFile;
			m_pSpi->OnRspQryGetFileTopic(pRspQryGetFile, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryGetFile == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryGetFileTopic(pRspQryGetFile, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///告警明细
void CFtdcUserApiImpl::OnRspQryWarningQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryWarningQueryField RspQryWarningQuery;
	CShfeFtdcRspQryWarningQueryField *pRspQryWarningQuery = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryWarningQueryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryWarningQuery);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryWarningQuery = (CShfeFtdcRspQryWarningQueryField *)&RspQryWarningQuery;
			m_pSpi->OnRspQryWarningQueryTopic(pRspQryWarningQuery, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryWarningQuery == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryWarningQueryTopic(pRspQryWarningQuery, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///告警明细
void CFtdcUserApiImpl::OnRtnWarningQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnWarningQueryField RtnWarningQuery;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnWarningQueryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnWarningQuery);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnWarningQueryTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnWarningQuery, &CFTDRtnWarningQueryField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnWarningQueryTopic((CShfeFtdcRtnWarningQueryField *)&RtnWarningQuery);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///HostConfig订阅应答
void CFtdcUserApiImpl::OnRtnHostConfig(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnHostConfigField RtnHostConfig;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnHostConfigField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnHostConfig);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnHostConfig,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnHostConfig, &CFTDRtnHostConfigField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnHostConfig((CShfeFtdcRtnHostConfigField *)&RtnHostConfig);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///告警激活变更
void CFtdcUserApiImpl::OnRspQryWarningActiveChange(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryWarningActiveChangeField RspQryWarningActiveChange;
	CShfeFtdcRspQryWarningActiveChangeField *pRspQryWarningActiveChange = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryWarningActiveChangeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryWarningActiveChange);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryWarningActiveChange = (CShfeFtdcRspQryWarningActiveChangeField *)&RspQryWarningActiveChange;
			m_pSpi->OnRspQryWarningActiveChange(pRspQryWarningActiveChange, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryWarningActiveChange == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryWarningActiveChange(pRspQryWarningActiveChange, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///告警激活变更
void CFtdcUserApiImpl::OnRtnWarningActiveChange(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnWarningActiveChangeField RtnWarningActiveChange;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnWarningActiveChangeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnWarningActiveChange);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnWarningActiveChange,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnWarningActiveChange, &CFTDRtnWarningActiveChangeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnWarningActiveChange((CShfeFtdcRtnWarningActiveChangeField *)&RtnWarningActiveChange);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///通用操作
void CFtdcUserApiImpl::OnRspQryGeneralOperateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryGeneralOperateField RspQryGeneralOperate;
	CShfeFtdcRspQryGeneralOperateField *pRspQryGeneralOperate = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryGeneralOperateField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryGeneralOperate);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryGeneralOperate = (CShfeFtdcRspQryGeneralOperateField *)&RspQryGeneralOperate;
			m_pSpi->OnRspQryGeneralOperateTopic(pRspQryGeneralOperate, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryGeneralOperate == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryGeneralOperateTopic(pRspQryGeneralOperate, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///通用操作
void CFtdcUserApiImpl::OnRtnGeneralOperateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnGeneralOperateField RtnGeneralOperate;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnGeneralOperateField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnGeneralOperate);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnGeneralOperateTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnGeneralOperate, &CFTDRtnGeneralOperateField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnGeneralOperateTopic((CShfeFtdcRtnGeneralOperateField *)&RtnGeneralOperate);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///网络设备连接关系
void CFtdcUserApiImpl::OnRspQryNetDeviceLinkedTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetDeviceLinkedField RspQryNetDeviceLinked;
	CShfeFtdcRspQryNetDeviceLinkedField *pRspQryNetDeviceLinked = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetDeviceLinkedField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetDeviceLinked);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetDeviceLinked = (CShfeFtdcRspQryNetDeviceLinkedField *)&RspQryNetDeviceLinked;
			m_pSpi->OnRspQryNetDeviceLinkedTopic(pRspQryNetDeviceLinked, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetDeviceLinked == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetDeviceLinkedTopic(pRspQryNetDeviceLinked, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///网络设备连接关系
void CFtdcUserApiImpl::OnRtnNetDeviceLinkedTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetDeviceLinkedField RtnNetDeviceLinked;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetDeviceLinkedField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetDeviceLinked);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetDeviceLinkedTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetDeviceLinked, &CFTDRtnNetDeviceLinkedField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetDeviceLinkedTopic((CShfeFtdcRtnNetDeviceLinkedField *)&RtnNetDeviceLinked);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///交易系统登录信息
void CFtdcUserApiImpl::OnRspQryTradeUserLoginStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTradeUserLoginStatField RspQryTradeUserLoginStat;
	CShfeFtdcRspQryTradeUserLoginStatField *pRspQryTradeUserLoginStat = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTradeUserLoginStatField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTradeUserLoginStat);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTradeUserLoginStat = (CShfeFtdcRspQryTradeUserLoginStatField *)&RspQryTradeUserLoginStat;
			m_pSpi->OnRspQryTradeUserLoginStatTopic(pRspQryTradeUserLoginStat, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryTradeUserLoginStat == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTradeUserLoginStatTopic(pRspQryTradeUserLoginStat, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易系统前置报单响应信息
void CFtdcUserApiImpl::OnRspQryTradeFrontOrderRttStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTradeFrontOrderRttStatField RspQryTradeFrontOrderRttStat;
	CShfeFtdcRspQryTradeFrontOrderRttStatField *pRspQryTradeFrontOrderRttStat = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTradeFrontOrderRttStatField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTradeFrontOrderRttStat);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTradeFrontOrderRttStat = (CShfeFtdcRspQryTradeFrontOrderRttStatField *)&RspQryTradeFrontOrderRttStat;
			m_pSpi->OnRspQryTradeFrontOrderRttStatTopic(pRspQryTradeFrontOrderRttStat, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryTradeFrontOrderRttStat == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTradeFrontOrderRttStatTopic(pRspQryTradeFrontOrderRttStat, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易系统前置报单响应信息
void CFtdcUserApiImpl::OnRtnTradeFrontOrderRttStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnTradeFrontOrderRttStatField RtnTradeFrontOrderRttStat;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnTradeFrontOrderRttStatField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnTradeFrontOrderRttStat);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnTradeFrontOrderRttStatTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnTradeFrontOrderRttStat, &CFTDRtnTradeFrontOrderRttStatField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTradeFrontOrderRttStatTopic((CShfeFtdcRtnTradeFrontOrderRttStatField *)&RtnTradeFrontOrderRttStat);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///系统路由信息
void CFtdcUserApiImpl::OnRspQryRouterInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryRouterInfoField RspQryRouterInfo;
	CShfeFtdcRspQryRouterInfoField *pRspQryRouterInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryRouterInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryRouterInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryRouterInfo = (CShfeFtdcRspQryRouterInfoField *)&RspQryRouterInfo;
			m_pSpi->OnRspQryRouterInfoTopic(pRspQryRouterInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryRouterInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryRouterInfoTopic(pRspQryRouterInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///系统路由信息
void CFtdcUserApiImpl::OnRtnRouterInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnRouterInfoField RtnRouterInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnRouterInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnRouterInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnRouterInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnRouterInfo, &CFTDRtnRouterInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnRouterInfoTopic((CShfeFtdcRtnRouterInfoField *)&RtnRouterInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///磁盘I/O信息
void CFtdcUserApiImpl::OnRspQryDiskIOTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryDiskIOField RspQryDiskIO;
	CShfeFtdcRspQryDiskIOField *pRspQryDiskIO = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryDiskIOField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryDiskIO);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryDiskIO = (CShfeFtdcRspQryDiskIOField *)&RspQryDiskIO;
			m_pSpi->OnRspQryDiskIOTopic(pRspQryDiskIO, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryDiskIO == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryDiskIOTopic(pRspQryDiskIO, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///磁盘I/O信息
void CFtdcUserApiImpl::OnRtnDiskIOTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnDiskIOField RtnDiskIO;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnDiskIOField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnDiskIO);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnDiskIOTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnDiskIO, &CFTDRtnDiskIOField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnDiskIOTopic((CShfeFtdcRtnDiskIOField *)&RtnDiskIO);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///系统状态信息
void CFtdcUserApiImpl::OnRspQryStatInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryStatInfoField RspQryStatInfo;
	CShfeFtdcRspQryStatInfoField *pRspQryStatInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryStatInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryStatInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryStatInfo = (CShfeFtdcRspQryStatInfoField *)&RspQryStatInfo;
			m_pSpi->OnRspQryStatInfoTopic(pRspQryStatInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryStatInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryStatInfoTopic(pRspQryStatInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///系统状态信息
void CFtdcUserApiImpl::OnRtnStatInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnStatInfoField RtnStatInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnStatInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnStatInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnStatInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnStatInfo, &CFTDRtnStatInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnStatInfoTopic((CShfeFtdcRtnStatInfoField *)&RtnStatInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///交易系统前置报单分布区间
void CFtdcUserApiImpl::OnRspQryTradeOrderRttCutLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTradeOrderRttCutLineField RspQryTradeOrderRttCutLine;
	CShfeFtdcRspQryTradeOrderRttCutLineField *pRspQryTradeOrderRttCutLine = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTradeOrderRttCutLineField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTradeOrderRttCutLine);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTradeOrderRttCutLine = (CShfeFtdcRspQryTradeOrderRttCutLineField *)&RspQryTradeOrderRttCutLine;
			m_pSpi->OnRspQryTradeOrderRttCutLineTopic(pRspQryTradeOrderRttCutLine, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryTradeOrderRttCutLine == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTradeOrderRttCutLineTopic(pRspQryTradeOrderRttCutLine, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易系统前置报单分布区间
void CFtdcUserApiImpl::OnRtnTradeOrderRttCutLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnTradeOrderRttCutLineField RtnTradeOrderRttCutLine;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnTradeOrderRttCutLineField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnTradeOrderRttCutLine);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnTradeOrderRttCutLineTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnTradeOrderRttCutLine, &CFTDRtnTradeOrderRttCutLineField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTradeOrderRttCutLineTopic((CShfeFtdcRtnTradeOrderRttCutLineField *)&RtnTradeOrderRttCutLine);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///会员客户信息
void CFtdcUserApiImpl::OnRspQryClientInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryClientInfoField RspQryClientInfo;
	CShfeFtdcRspQryClientInfoField *pRspQryClientInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryClientInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryClientInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryClientInfo = (CShfeFtdcRspQryClientInfoField *)&RspQryClientInfo;
			m_pSpi->OnRspQryClientInfoTopic(pRspQryClientInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryClientInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryClientInfoTopic(pRspQryClientInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员客户信息
void CFtdcUserApiImpl::OnRtnClientInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnClientInfoField RtnClientInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnClientInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnClientInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnClientInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnClientInfo, &CFTDRtnClientInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnClientInfoTopic((CShfeFtdcRtnClientInfoField *)&RtnClientInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///应答事件描述
void CFtdcUserApiImpl::OnRspQryEventDescriptionTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryEventDescriptionField RspQryEventDescription;
	CShfeFtdcRspQryEventDescriptionField *pRspQryEventDescription = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryEventDescriptionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryEventDescription);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryEventDescription = (CShfeFtdcRspQryEventDescriptionField *)&RspQryEventDescription;
			m_pSpi->OnRspQryEventDescriptionTopic(pRspQryEventDescription, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryEventDescription == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryEventDescriptionTopic(pRspQryEventDescription, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅事件描述
void CFtdcUserApiImpl::OnRtnEventDescriptionTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnEventDescriptionField RtnEventDescription;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnEventDescriptionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnEventDescription);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnEventDescriptionTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnEventDescription, &CFTDRtnEventDescriptionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnEventDescriptionTopic((CShfeFtdcRtnEventDescriptionField *)&RtnEventDescription);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///应答前置唯一ID信息
void CFtdcUserApiImpl::OnRspQryFrontUniqueIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryFrontUniqueIDField RspQryFrontUniqueID;
	CShfeFtdcRspQryFrontUniqueIDField *pRspQryFrontUniqueID = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryFrontUniqueIDField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryFrontUniqueID);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryFrontUniqueID = (CShfeFtdcRspQryFrontUniqueIDField *)&RspQryFrontUniqueID;
			m_pSpi->OnRspQryFrontUniqueIDTopic(pRspQryFrontUniqueID, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryFrontUniqueID == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryFrontUniqueIDTopic(pRspQryFrontUniqueID, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅前置唯一ID信息
void CFtdcUserApiImpl::OnRtnFrontUniqueIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnFrontUniqueIDField RtnFrontUniqueID;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnFrontUniqueIDField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnFrontUniqueID);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnFrontUniqueIDTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnFrontUniqueID, &CFTDRtnFrontUniqueIDField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnFrontUniqueIDTopic((CShfeFtdcRtnFrontUniqueIDField *)&RtnFrontUniqueID);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///会员线路地址变更回应
void CFtdcUserApiImpl::OnRspQryNetPartyLinkAddrChangeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetPartyLinkAddrChangeField RspQryNetPartyLinkAddrChange;
	CShfeFtdcRspQryNetPartyLinkAddrChangeField *pRspQryNetPartyLinkAddrChange = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetPartyLinkAddrChangeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetPartyLinkAddrChange);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetPartyLinkAddrChange = (CShfeFtdcRspQryNetPartyLinkAddrChangeField *)&RspQryNetPartyLinkAddrChange;
			m_pSpi->OnRspQryNetPartyLinkAddrChangeTopic(pRspQryNetPartyLinkAddrChange, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetPartyLinkAddrChange == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetPartyLinkAddrChangeTopic(pRspQryNetPartyLinkAddrChange, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅会员线路地址变更信息
void CFtdcUserApiImpl::OnRtnNetPartyLinkAddrChangeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetPartyLinkAddrChangeField RtnNetPartyLinkAddrChange;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetPartyLinkAddrChangeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetPartyLinkAddrChange);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetPartyLinkAddrChangeTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetPartyLinkAddrChange, &CFTDRtnNetPartyLinkAddrChangeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetPartyLinkAddrChangeTopic((CShfeFtdcRtnNetPartyLinkAddrChangeField *)&RtnNetPartyLinkAddrChange);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///应答已删除会员列表信息
void CFtdcUserApiImpl::OnRspQryNetDelPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetDelPartyLinkInfoField RspQryNetDelPartyLinkInfo;
	CShfeFtdcRspQryNetDelPartyLinkInfoField *pRspQryNetDelPartyLinkInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetDelPartyLinkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetDelPartyLinkInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetDelPartyLinkInfo = (CShfeFtdcRspQryNetDelPartyLinkInfoField *)&RspQryNetDelPartyLinkInfo;
			m_pSpi->OnRspQryNetDelPartyLinkInfoTopic(pRspQryNetDelPartyLinkInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetDelPartyLinkInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetDelPartyLinkInfoTopic(pRspQryNetDelPartyLinkInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅已删除会员列表信息
void CFtdcUserApiImpl::OnRtnNetDelPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetDelPartyLinkInfoField RtnNetDelPartyLinkInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetDelPartyLinkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetDelPartyLinkInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetDelPartyLinkInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetDelPartyLinkInfo, &CFTDRtnNetDelPartyLinkInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetDelPartyLinkInfoTopic((CShfeFtdcRtnNetDelPartyLinkInfoField *)&RtnNetDelPartyLinkInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///返回网络性能排序
void CFtdcUserApiImpl::OnRspQryPerformanceTopTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryPerformanceTopField RspQryPerformanceTop;
	CShfeFtdcRspQryPerformanceTopField *pRspQryPerformanceTop = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryPerformanceTopField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryPerformanceTop);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryPerformanceTop = (CShfeFtdcRspQryPerformanceTopField *)&RspQryPerformanceTop;
			m_pSpi->OnRspQryPerformanceTopTopic(pRspQryPerformanceTop, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryPerformanceTop == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPerformanceTopTopic(pRspQryPerformanceTop, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅网络性能排序
void CFtdcUserApiImpl::OnRtnPerformanceTopTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnPerformanceTopField RtnPerformanceTop;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnPerformanceTopField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnPerformanceTop);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnPerformanceTopTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnPerformanceTop, &CFTDRtnPerformanceTopField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnPerformanceTopTopic((CShfeFtdcRtnPerformanceTopField *)&RtnPerformanceTop);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///网络大区划分应答
void CFtdcUserApiImpl::OnRspQryNetAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetAreaField RspQryNetArea;
	CShfeFtdcRspQryNetAreaField *pRspQryNetArea = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetAreaField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetArea);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetArea = (CShfeFtdcRspQryNetAreaField *)&RspQryNetArea;
			m_pSpi->OnRspQryNetAreaTopic(pRspQryNetArea, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetArea == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetAreaTopic(pRspQryNetArea, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///网络大区划分应答
void CFtdcUserApiImpl::OnRtnNetAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetAreaField RtnNetArea;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetAreaField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetArea);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetAreaTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetArea, &CFTDRtnNetAreaField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetAreaTopic((CShfeFtdcRtnNetAreaField *)&RtnNetArea);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///网络子区应答
void CFtdcUserApiImpl::OnRspQryNetSubAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetSubAreaField RspQryNetSubArea;
	CShfeFtdcRspQryNetSubAreaField *pRspQryNetSubArea = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetSubAreaField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetSubArea);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetSubArea = (CShfeFtdcRspQryNetSubAreaField *)&RspQryNetSubArea;
			m_pSpi->OnRspQryNetSubAreaTopic(pRspQryNetSubArea, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetSubArea == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetSubAreaTopic(pRspQryNetSubArea, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///网络子区应答
void CFtdcUserApiImpl::OnRtnNetSubAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetSubAreaField RtnNetSubArea;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetSubAreaField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetSubArea);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetSubAreaTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetSubArea, &CFTDRtnNetSubAreaField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetSubAreaTopic((CShfeFtdcRtnNetSubAreaField *)&RtnNetSubArea);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///网络子区IP应答
void CFtdcUserApiImpl::OnRspQryNetSubAreaIPTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetSubAreaIPField RspQryNetSubAreaIP;
	CShfeFtdcRspQryNetSubAreaIPField *pRspQryNetSubAreaIP = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetSubAreaIPField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetSubAreaIP);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetSubAreaIP = (CShfeFtdcRspQryNetSubAreaIPField *)&RspQryNetSubAreaIP;
			m_pSpi->OnRspQryNetSubAreaIPTopic(pRspQryNetSubAreaIP, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetSubAreaIP == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetSubAreaIPTopic(pRspQryNetSubAreaIP, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///网络子区IP应答
void CFtdcUserApiImpl::OnRtnNetSubAreaIPTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetSubAreaIPField RtnNetSubAreaIP;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetSubAreaIPField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetSubAreaIP);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetSubAreaIPTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetSubAreaIP, &CFTDRtnNetSubAreaIPField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetSubAreaIPTopic((CShfeFtdcRtnNetSubAreaIPField *)&RtnNetSubAreaIP);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///网络设备
void CFtdcUserApiImpl::OnRspQryNetDeviceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetDeviceField RspQryNetDevice;
	CShfeFtdcRspQryNetDeviceField *pRspQryNetDevice = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetDeviceField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetDevice);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetDevice = (CShfeFtdcRspQryNetDeviceField *)&RspQryNetDevice;
			m_pSpi->OnRspQryNetDeviceTopic(pRspQryNetDevice, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetDevice == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetDeviceTopic(pRspQryNetDevice, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///网络设备
void CFtdcUserApiImpl::OnRtnNetDeviceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetDeviceField RtnNetDevice;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetDeviceField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetDevice);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetDeviceTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetDevice, &CFTDRtnNetDeviceField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetDeviceTopic((CShfeFtdcRtnNetDeviceField *)&RtnNetDevice);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///网络设备探测请求应答
void CFtdcUserApiImpl::OnRspQryNetDeviceDetectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetDeviceDetectField RspQryNetDeviceDetect;
	CShfeFtdcRspQryNetDeviceDetectField *pRspQryNetDeviceDetect = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetDeviceDetectField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetDeviceDetect);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetDeviceDetect = (CShfeFtdcRspQryNetDeviceDetectField *)&RspQryNetDeviceDetect;
			m_pSpi->OnRspQryNetDeviceDetectTopic(pRspQryNetDeviceDetect, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetDeviceDetect == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetDeviceDetectTopic(pRspQryNetDeviceDetect, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///大楼
void CFtdcUserApiImpl::OnRspQryNetBuildingTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetBuildingField RspQryNetBuilding;
	CShfeFtdcRspQryNetBuildingField *pRspQryNetBuilding = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetBuildingField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetBuilding);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetBuilding = (CShfeFtdcRspQryNetBuildingField *)&RspQryNetBuilding;
			m_pSpi->OnRspQryNetBuildingTopic(pRspQryNetBuilding, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetBuilding == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetBuildingTopic(pRspQryNetBuilding, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///大楼
void CFtdcUserApiImpl::OnRtnNetBuildingTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetBuildingField RtnNetBuilding;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetBuildingField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetBuilding);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetBuildingTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetBuilding, &CFTDRtnNetBuildingField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetBuildingTopic((CShfeFtdcRtnNetBuildingField *)&RtnNetBuilding);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///机房
void CFtdcUserApiImpl::OnRspQryNetRoomTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetRoomField RspQryNetRoom;
	CShfeFtdcRspQryNetRoomField *pRspQryNetRoom = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetRoomField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetRoom);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetRoom = (CShfeFtdcRspQryNetRoomField *)&RspQryNetRoom;
			m_pSpi->OnRspQryNetRoomTopic(pRspQryNetRoom, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetRoom == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetRoomTopic(pRspQryNetRoom, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///机房
void CFtdcUserApiImpl::OnRtnNetRoomTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetRoomField RtnNetRoom;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetRoomField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetRoom);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetRoomTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetRoom, &CFTDRtnNetRoomField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetRoomTopic((CShfeFtdcRtnNetRoomField *)&RtnNetRoom);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///机柜
void CFtdcUserApiImpl::OnRspQryNetCabinetsTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetCabinetsField RspQryNetCabinets;
	CShfeFtdcRspQryNetCabinetsField *pRspQryNetCabinets = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetCabinetsField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetCabinets);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetCabinets = (CShfeFtdcRspQryNetCabinetsField *)&RspQryNetCabinets;
			m_pSpi->OnRspQryNetCabinetsTopic(pRspQryNetCabinets, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetCabinets == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetCabinetsTopic(pRspQryNetCabinets, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///机柜
void CFtdcUserApiImpl::OnRtnNetCabinetsTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetCabinetsField RtnNetCabinets;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetCabinetsField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetCabinets);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetCabinetsTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetCabinets, &CFTDRtnNetCabinetsField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetCabinetsTopic((CShfeFtdcRtnNetCabinetsField *)&RtnNetCabinets);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///OID
void CFtdcUserApiImpl::OnRspQryNetOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetOIDField RspQryNetOID;
	CShfeFtdcRspQryNetOIDField *pRspQryNetOID = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetOIDField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetOID);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetOID = (CShfeFtdcRspQryNetOIDField *)&RspQryNetOID;
			m_pSpi->OnRspQryNetOIDTopic(pRspQryNetOID, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetOID == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetOIDTopic(pRspQryNetOID, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///OID
void CFtdcUserApiImpl::OnRtnNetOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetOIDField RtnNetOID;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetOIDField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetOID);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetOIDTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetOID, &CFTDRtnNetOIDField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetOIDTopic((CShfeFtdcRtnNetOIDField *)&RtnNetOID);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///时间策略
void CFtdcUserApiImpl::OnRspQryNetTimePolicyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetTimePolicyField RspQryNetTimePolicy;
	CShfeFtdcRspQryNetTimePolicyField *pRspQryNetTimePolicy = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetTimePolicyField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetTimePolicy);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetTimePolicy = (CShfeFtdcRspQryNetTimePolicyField *)&RspQryNetTimePolicy;
			m_pSpi->OnRspQryNetTimePolicyTopic(pRspQryNetTimePolicy, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetTimePolicy == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetTimePolicyTopic(pRspQryNetTimePolicy, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///时间策略
void CFtdcUserApiImpl::OnRtnNetTimePolicyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetTimePolicyField RtnNetTimePolicy;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetTimePolicyField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetTimePolicy);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetTimePolicyTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetTimePolicy, &CFTDRtnNetTimePolicyField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetTimePolicyTopic((CShfeFtdcRtnNetTimePolicyField *)&RtnNetTimePolicy);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///采集任务
void CFtdcUserApiImpl::OnRspQryNetGatherTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetGatherTaskField RspQryNetGatherTask;
	CShfeFtdcRspQryNetGatherTaskField *pRspQryNetGatherTask = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetGatherTaskField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetGatherTask);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetGatherTask = (CShfeFtdcRspQryNetGatherTaskField *)&RspQryNetGatherTask;
			m_pSpi->OnRspQryNetGatherTaskTopic(pRspQryNetGatherTask, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetGatherTask == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetGatherTaskTopic(pRspQryNetGatherTask, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///采集任务
void CFtdcUserApiImpl::OnRtnNetGatherTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetGatherTaskField RtnNetGatherTask;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetGatherTaskField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetGatherTask);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetGatherTaskTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetGatherTask, &CFTDRtnNetGatherTaskField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetGatherTaskTopic((CShfeFtdcRtnNetGatherTaskField *)&RtnNetGatherTask);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///设备变更
void CFtdcUserApiImpl::OnRspQryNetDeviceChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetDeviceChgField RspQryNetDeviceChg;
	CShfeFtdcRspQryNetDeviceChgField *pRspQryNetDeviceChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetDeviceChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetDeviceChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetDeviceChg = (CShfeFtdcRspQryNetDeviceChgField *)&RspQryNetDeviceChg;
			m_pSpi->OnRspQryNetDeviceChgTopic(pRspQryNetDeviceChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetDeviceChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetDeviceChgTopic(pRspQryNetDeviceChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///设备变更
void CFtdcUserApiImpl::OnRtnNetDeviceChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetDeviceChgField RtnNetDeviceChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetDeviceChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetDeviceChg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetDeviceChgTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetDeviceChg, &CFTDRtnNetDeviceChgField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetDeviceChgTopic((CShfeFtdcRtnNetDeviceChgField *)&RtnNetDeviceChg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///常用设备型号
void CFtdcUserApiImpl::OnRspQryNetDeviceTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetDeviceTypeField RspQryNetDeviceType;
	CShfeFtdcRspQryNetDeviceTypeField *pRspQryNetDeviceType = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetDeviceTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetDeviceType);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetDeviceType = (CShfeFtdcRspQryNetDeviceTypeField *)&RspQryNetDeviceType;
			m_pSpi->OnRspQryNetDeviceTypeTopic(pRspQryNetDeviceType, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetDeviceType == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetDeviceTypeTopic(pRspQryNetDeviceType, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///常用设备型号
void CFtdcUserApiImpl::OnRtnNetDeviceTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetDeviceTypeField RtnNetDeviceType;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetDeviceTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetDeviceType);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetDeviceTypeTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetDeviceType, &CFTDRtnNetDeviceTypeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetDeviceTypeTopic((CShfeFtdcRtnNetDeviceTypeField *)&RtnNetDeviceType);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///常用设备类别
void CFtdcUserApiImpl::OnRspQryNetDeviceCategoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetDeviceCategoryField RspQryNetDeviceCategory;
	CShfeFtdcRspQryNetDeviceCategoryField *pRspQryNetDeviceCategory = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetDeviceCategoryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetDeviceCategory);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetDeviceCategory = (CShfeFtdcRspQryNetDeviceCategoryField *)&RspQryNetDeviceCategory;
			m_pSpi->OnRspQryNetDeviceCategoryTopic(pRspQryNetDeviceCategory, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetDeviceCategory == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetDeviceCategoryTopic(pRspQryNetDeviceCategory, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///常用设备类别
void CFtdcUserApiImpl::OnRtnNetDeviceCategoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetDeviceCategoryField RtnNetDeviceCategory;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetDeviceCategoryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetDeviceCategory);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetDeviceCategoryTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetDeviceCategory, &CFTDRtnNetDeviceCategoryField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetDeviceCategoryTopic((CShfeFtdcRtnNetDeviceCategoryField *)&RtnNetDeviceCategory);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///设备厂商
void CFtdcUserApiImpl::OnRspQryNetManufactoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetManufactoryField RspQryNetManufactory;
	CShfeFtdcRspQryNetManufactoryField *pRspQryNetManufactory = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetManufactoryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetManufactory);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetManufactory = (CShfeFtdcRspQryNetManufactoryField *)&RspQryNetManufactory;
			m_pSpi->OnRspQryNetManufactoryTopic(pRspQryNetManufactory, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetManufactory == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetManufactoryTopic(pRspQryNetManufactory, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///设备厂商
void CFtdcUserApiImpl::OnRtnNetManufactoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetManufactoryField RtnNetManufactory;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetManufactoryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetManufactory);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetManufactoryTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetManufactory, &CFTDRtnNetManufactoryField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetManufactoryTopic((CShfeFtdcRtnNetManufactoryField *)&RtnNetManufactory);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///设备共同体
void CFtdcUserApiImpl::OnRspQryNetCommunityTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetCommunityField RspQryNetCommunity;
	CShfeFtdcRspQryNetCommunityField *pRspQryNetCommunity = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetCommunityField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetCommunity);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetCommunity = (CShfeFtdcRspQryNetCommunityField *)&RspQryNetCommunity;
			m_pSpi->OnRspQryNetCommunityTopic(pRspQryNetCommunity, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetCommunity == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetCommunityTopic(pRspQryNetCommunity, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///设备共同体
void CFtdcUserApiImpl::OnRtnNetCommunityTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetCommunityField RtnNetCommunity;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetCommunityField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetCommunity);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetCommunityTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetCommunity, &CFTDRtnNetCommunityField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetCommunityTopic((CShfeFtdcRtnNetCommunityField *)&RtnNetCommunity);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///端口类型
void CFtdcUserApiImpl::OnRspQryNetPortTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetPortTypeField RspQryNetPortType;
	CShfeFtdcRspQryNetPortTypeField *pRspQryNetPortType = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetPortTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetPortType);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetPortType = (CShfeFtdcRspQryNetPortTypeField *)&RspQryNetPortType;
			m_pSpi->OnRspQryNetPortTypeTopic(pRspQryNetPortType, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetPortType == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetPortTypeTopic(pRspQryNetPortType, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///端口类型
void CFtdcUserApiImpl::OnRtnNetPortTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetPortTypeField RtnNetPortType;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetPortTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetPortType);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetPortTypeTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetPortType, &CFTDRtnNetPortTypeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetPortTypeTopic((CShfeFtdcRtnNetPortTypeField *)&RtnNetPortType);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///会员接入地点
void CFtdcUserApiImpl::OnRspQryNetPartAccessSpotTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetPartAccessSpotField RspQryNetPartAccessSpot;
	CShfeFtdcRspQryNetPartAccessSpotField *pRspQryNetPartAccessSpot = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetPartAccessSpotField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetPartAccessSpot);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetPartAccessSpot = (CShfeFtdcRspQryNetPartAccessSpotField *)&RspQryNetPartAccessSpot;
			m_pSpi->OnRspQryNetPartAccessSpotTopic(pRspQryNetPartAccessSpot, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetPartAccessSpot == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetPartAccessSpotTopic(pRspQryNetPartAccessSpot, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员接入地点
void CFtdcUserApiImpl::OnRtnNetPartAccessSpotTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetPartAccessSpotField RtnNetPartAccessSpot;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetPartAccessSpotField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetPartAccessSpot);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetPartAccessSpotTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetPartAccessSpot, &CFTDRtnNetPartAccessSpotField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetPartAccessSpotTopic((CShfeFtdcRtnNetPartAccessSpotField *)&RtnNetPartAccessSpot);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///端口
void CFtdcUserApiImpl::OnRspQryNetInterfaceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetInterfaceField RspQryNetInterface;
	CShfeFtdcRspQryNetInterfaceField *pRspQryNetInterface = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetInterfaceField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetInterface);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetInterface = (CShfeFtdcRspQryNetInterfaceField *)&RspQryNetInterface;
			m_pSpi->OnRspQryNetInterfaceTopic(pRspQryNetInterface, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetInterface == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetInterfaceTopic(pRspQryNetInterface, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///端口
void CFtdcUserApiImpl::OnRtnNetInterfaceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetInterfaceField RtnNetInterface;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetInterfaceField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetInterface);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetInterfaceTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetInterface, &CFTDRtnNetInterfaceField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetInterfaceTopic((CShfeFtdcRtnNetInterfaceField *)&RtnNetInterface);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///GeneralOID
void CFtdcUserApiImpl::OnRspQryNetGeneralOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetGeneralOIDField RspQryNetGeneralOID;
	CShfeFtdcRspQryNetGeneralOIDField *pRspQryNetGeneralOID = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetGeneralOIDField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetGeneralOID);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetGeneralOID = (CShfeFtdcRspQryNetGeneralOIDField *)&RspQryNetGeneralOID;
			m_pSpi->OnRspQryNetGeneralOIDTopic(pRspQryNetGeneralOID, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetGeneralOID == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetGeneralOIDTopic(pRspQryNetGeneralOID, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///GeneralOID
void CFtdcUserApiImpl::OnRtnNetGeneralOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetGeneralOIDField RtnNetGeneralOID;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetGeneralOIDField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetGeneralOID);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetGeneralOIDTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetGeneralOID, &CFTDRtnNetGeneralOIDField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetGeneralOIDTopic((CShfeFtdcRtnNetGeneralOIDField *)&RtnNetGeneralOID);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///监控对象类别
void CFtdcUserApiImpl::OnRspQryNetMonitorTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorTypeField RspQryNetMonitorType;
	CShfeFtdcRspQryNetMonitorTypeField *pRspQryNetMonitorType = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorType);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorType = (CShfeFtdcRspQryNetMonitorTypeField *)&RspQryNetMonitorType;
			m_pSpi->OnRspQryNetMonitorTypeTopic(pRspQryNetMonitorType, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetMonitorType == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorTypeTopic(pRspQryNetMonitorType, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///监控对象类别
void CFtdcUserApiImpl::OnRtnNetMonitorTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetMonitorTypeField RtnNetMonitorType;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorType);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetMonitorTypeTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetMonitorType, &CFTDRtnNetMonitorTypeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorTypeTopic((CShfeFtdcRtnNetMonitorTypeField *)&RtnNetMonitorType);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///指标统表
void CFtdcUserApiImpl::OnRspQryNetMonitorAttrScopeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorAttrScopeField RspQryNetMonitorAttrScope;
	CShfeFtdcRspQryNetMonitorAttrScopeField *pRspQryNetMonitorAttrScope = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorAttrScopeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorAttrScope);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorAttrScope = (CShfeFtdcRspQryNetMonitorAttrScopeField *)&RspQryNetMonitorAttrScope;
			m_pSpi->OnRspQryNetMonitorAttrScopeTopic(pRspQryNetMonitorAttrScope, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetMonitorAttrScope == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorAttrScopeTopic(pRspQryNetMonitorAttrScope, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///指标统表
void CFtdcUserApiImpl::OnRtnNetMonitorAttrScopeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetMonitorAttrScopeField RtnNetMonitorAttrScope;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorAttrScopeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorAttrScope);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetMonitorAttrScopeTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetMonitorAttrScope, &CFTDRtnNetMonitorAttrScopeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorAttrScopeTopic((CShfeFtdcRtnNetMonitorAttrScopeField *)&RtnNetMonitorAttrScope);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///监控指标表
void CFtdcUserApiImpl::OnRspQryNetMonitorAttrTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorAttrTypeField RspQryNetMonitorAttrType;
	CShfeFtdcRspQryNetMonitorAttrTypeField *pRspQryNetMonitorAttrType = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorAttrTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorAttrType);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorAttrType = (CShfeFtdcRspQryNetMonitorAttrTypeField *)&RspQryNetMonitorAttrType;
			m_pSpi->OnRspQryNetMonitorAttrTypeTopic(pRspQryNetMonitorAttrType, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetMonitorAttrType == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorAttrTypeTopic(pRspQryNetMonitorAttrType, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///监控指标表
void CFtdcUserApiImpl::OnRtnNetMonitorAttrTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetMonitorAttrTypeField RtnNetMonitorAttrType;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorAttrTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorAttrType);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetMonitorAttrTypeTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetMonitorAttrType, &CFTDRtnNetMonitorAttrTypeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorAttrTypeTopic((CShfeFtdcRtnNetMonitorAttrTypeField *)&RtnNetMonitorAttrType);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///监控对象指标表
void CFtdcUserApiImpl::OnRspQryNetMonitorObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorObjectAttrField RspQryNetMonitorObjectAttr;
	CShfeFtdcRspQryNetMonitorObjectAttrField *pRspQryNetMonitorObjectAttr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorObjectAttr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorObjectAttr = (CShfeFtdcRspQryNetMonitorObjectAttrField *)&RspQryNetMonitorObjectAttr;
			m_pSpi->OnRspQryNetMonitorObjectAttrTopic(pRspQryNetMonitorObjectAttr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetMonitorObjectAttr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorObjectAttrTopic(pRspQryNetMonitorObjectAttr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///监控对象指标表
void CFtdcUserApiImpl::OnRtnNetMonitorObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetMonitorObjectAttrField RtnNetMonitorObjectAttr;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorObjectAttr);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetMonitorObjectAttrTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetMonitorObjectAttr, &CFTDRtnNetMonitorObjectAttrField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorObjectAttrTopic((CShfeFtdcRtnNetMonitorObjectAttrField *)&RtnNetMonitorObjectAttr);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///职能区
void CFtdcUserApiImpl::OnRspQryNetFuncAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetFuncAreaField RspQryNetFuncArea;
	CShfeFtdcRspQryNetFuncAreaField *pRspQryNetFuncArea = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetFuncAreaField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetFuncArea);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetFuncArea = (CShfeFtdcRspQryNetFuncAreaField *)&RspQryNetFuncArea;
			m_pSpi->OnRspQryNetFuncAreaTopic(pRspQryNetFuncArea, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetFuncArea == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetFuncAreaTopic(pRspQryNetFuncArea, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///职能区
void CFtdcUserApiImpl::OnRtnNetFuncAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetFuncAreaField RtnNetFuncArea;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetFuncAreaField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetFuncArea);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetFuncAreaTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetFuncArea, &CFTDRtnNetFuncAreaField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetFuncAreaTopic((CShfeFtdcRtnNetFuncAreaField *)&RtnNetFuncArea);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///监控指令表
void CFtdcUserApiImpl::OnRspQryNetMonitorCommandTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorCommandTypeField RspQryNetMonitorCommandType;
	CShfeFtdcRspQryNetMonitorCommandTypeField *pRspQryNetMonitorCommandType = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorCommandTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorCommandType);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorCommandType = (CShfeFtdcRspQryNetMonitorCommandTypeField *)&RspQryNetMonitorCommandType;
			m_pSpi->OnRspQryNetMonitorCommandTypeTopic(pRspQryNetMonitorCommandType, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetMonitorCommandType == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorCommandTypeTopic(pRspQryNetMonitorCommandType, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///监控指令表
void CFtdcUserApiImpl::OnRtnNetMonitorCommandTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetMonitorCommandTypeField RtnNetMonitorCommandType;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorCommandTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorCommandType);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetMonitorCommandTypeTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetMonitorCommandType, &CFTDRtnNetMonitorCommandTypeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorCommandTypeTopic((CShfeFtdcRtnNetMonitorCommandTypeField *)&RtnNetMonitorCommandType);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///动作族表
void CFtdcUserApiImpl::OnRspQryNetMonitorActionGroupTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorActionGroupField RspQryNetMonitorActionGroup;
	CShfeFtdcRspQryNetMonitorActionGroupField *pRspQryNetMonitorActionGroup = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorActionGroupField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorActionGroup);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorActionGroup = (CShfeFtdcRspQryNetMonitorActionGroupField *)&RspQryNetMonitorActionGroup;
			m_pSpi->OnRspQryNetMonitorActionGroupTopic(pRspQryNetMonitorActionGroup, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetMonitorActionGroup == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorActionGroupTopic(pRspQryNetMonitorActionGroup, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///动作族表
void CFtdcUserApiImpl::OnRtnNetMonitorActionGroupTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetMonitorActionGroupField RtnNetMonitorActionGroup;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorActionGroupField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorActionGroup);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetMonitorActionGroupTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetMonitorActionGroup, &CFTDRtnNetMonitorActionGroupField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorActionGroupTopic((CShfeFtdcRtnNetMonitorActionGroupField *)&RtnNetMonitorActionGroup);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///设备对象组表
void CFtdcUserApiImpl::OnRspQryNetMonitorDeviceGroupTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorDeviceGroupField RspQryNetMonitorDeviceGroup;
	CShfeFtdcRspQryNetMonitorDeviceGroupField *pRspQryNetMonitorDeviceGroup = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorDeviceGroupField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorDeviceGroup);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorDeviceGroup = (CShfeFtdcRspQryNetMonitorDeviceGroupField *)&RspQryNetMonitorDeviceGroup;
			m_pSpi->OnRspQryNetMonitorDeviceGroupTopic(pRspQryNetMonitorDeviceGroup, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetMonitorDeviceGroup == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorDeviceGroupTopic(pRspQryNetMonitorDeviceGroup, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///设备对象组表
void CFtdcUserApiImpl::OnRtnNetMonitorDeviceGroupTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetMonitorDeviceGroupField RtnNetMonitorDeviceGroup;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorDeviceGroupField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorDeviceGroup);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetMonitorDeviceGroupTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetMonitorDeviceGroup, &CFTDRtnNetMonitorDeviceGroupField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorDeviceGroupTopic((CShfeFtdcRtnNetMonitorDeviceGroupField *)&RtnNetMonitorDeviceGroup);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///任务信息表
void CFtdcUserApiImpl::OnRspQryNetMonitorTaskInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorTaskInfoField RspQryNetMonitorTaskInfo;
	CShfeFtdcRspQryNetMonitorTaskInfoField *pRspQryNetMonitorTaskInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorTaskInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorTaskInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorTaskInfo = (CShfeFtdcRspQryNetMonitorTaskInfoField *)&RspQryNetMonitorTaskInfo;
			m_pSpi->OnRspQryNetMonitorTaskInfoTopic(pRspQryNetMonitorTaskInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetMonitorTaskInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorTaskInfoTopic(pRspQryNetMonitorTaskInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///任务信息表
void CFtdcUserApiImpl::OnRtnNetMonitorTaskInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetMonitorTaskInfoField RtnNetMonitorTaskInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorTaskInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorTaskInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetMonitorTaskInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetMonitorTaskInfo, &CFTDRtnNetMonitorTaskInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorTaskInfoTopic((CShfeFtdcRtnNetMonitorTaskInfoField *)&RtnNetMonitorTaskInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///任务结果表
void CFtdcUserApiImpl::OnRspQryNetMonitorTaskResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorTaskResultField RspQryNetMonitorTaskResult;
	CShfeFtdcRspQryNetMonitorTaskResultField *pRspQryNetMonitorTaskResult = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorTaskResultField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorTaskResult);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorTaskResult = (CShfeFtdcRspQryNetMonitorTaskResultField *)&RspQryNetMonitorTaskResult;
			m_pSpi->OnRspQryNetMonitorTaskResultTopic(pRspQryNetMonitorTaskResult, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetMonitorTaskResult == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorTaskResultTopic(pRspQryNetMonitorTaskResult, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///任务结果表
void CFtdcUserApiImpl::OnRtnNetMonitorTaskResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetMonitorTaskResultField RtnNetMonitorTaskResult;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorTaskResultField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorTaskResult);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetMonitorTaskResultTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetMonitorTaskResult, &CFTDRtnNetMonitorTaskResultField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorTaskResultTopic((CShfeFtdcRtnNetMonitorTaskResultField *)&RtnNetMonitorTaskResult);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///任务对象集
void CFtdcUserApiImpl::OnRspQryNetMonitorTaskObjectSetTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorTaskObjectSetField RspQryNetMonitorTaskObjectSet;
	CShfeFtdcRspQryNetMonitorTaskObjectSetField *pRspQryNetMonitorTaskObjectSet = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorTaskObjectSetField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorTaskObjectSet);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorTaskObjectSet = (CShfeFtdcRspQryNetMonitorTaskObjectSetField *)&RspQryNetMonitorTaskObjectSet;
			m_pSpi->OnRspQryNetMonitorTaskObjectSetTopic(pRspQryNetMonitorTaskObjectSet, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetMonitorTaskObjectSet == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorTaskObjectSetTopic(pRspQryNetMonitorTaskObjectSet, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///任务对象集
void CFtdcUserApiImpl::OnRtnNetMonitorTaskObjectSetTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetMonitorTaskObjectSetField RtnNetMonitorTaskObjectSet;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorTaskObjectSetField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorTaskObjectSet);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetMonitorTaskObjectSetTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetMonitorTaskObjectSet, &CFTDRtnNetMonitorTaskObjectSetField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorTaskObjectSetTopic((CShfeFtdcRtnNetMonitorTaskObjectSetField *)&RtnNetMonitorTaskObjectSet);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///会员链路信息表
void CFtdcUserApiImpl::OnRspQryNetPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetPartyLinkInfoField RspQryNetPartyLinkInfo;
	CShfeFtdcRspQryNetPartyLinkInfoField *pRspQryNetPartyLinkInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetPartyLinkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetPartyLinkInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetPartyLinkInfo = (CShfeFtdcRspQryNetPartyLinkInfoField *)&RspQryNetPartyLinkInfo;
			m_pSpi->OnRspQryNetPartyLinkInfoTopic(pRspQryNetPartyLinkInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetPartyLinkInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetPartyLinkInfoTopic(pRspQryNetPartyLinkInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员链路信息表
void CFtdcUserApiImpl::OnRtnNetPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetPartyLinkInfoField RtnNetPartyLinkInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetPartyLinkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetPartyLinkInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetPartyLinkInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetPartyLinkInfo, &CFTDRtnNetPartyLinkInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetPartyLinkInfoTopic((CShfeFtdcRtnNetPartyLinkInfoField *)&RtnNetPartyLinkInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///监控动作指标对照表
void CFtdcUserApiImpl::OnRspQryNetMonitorActionAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorActionAttrField RspQryNetMonitorActionAttr;
	CShfeFtdcRspQryNetMonitorActionAttrField *pRspQryNetMonitorActionAttr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorActionAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorActionAttr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorActionAttr = (CShfeFtdcRspQryNetMonitorActionAttrField *)&RspQryNetMonitorActionAttr;
			m_pSpi->OnRspQryNetMonitorActionAttrTopic(pRspQryNetMonitorActionAttr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetMonitorActionAttr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorActionAttrTopic(pRspQryNetMonitorActionAttr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///监控动作指标对照表
void CFtdcUserApiImpl::OnRtnNetMonitorActionAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetMonitorActionAttrField RtnNetMonitorActionAttr;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorActionAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorActionAttr);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetMonitorActionAttrTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetMonitorActionAttr, &CFTDRtnNetMonitorActionAttrField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorActionAttrTopic((CShfeFtdcRtnNetMonitorActionAttrField *)&RtnNetMonitorActionAttr);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///模块
void CFtdcUserApiImpl::OnRspQryNetModuleTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetModuleField RspQryNetModule;
	CShfeFtdcRspQryNetModuleField *pRspQryNetModule = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetModuleField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetModule);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetModule = (CShfeFtdcRspQryNetModuleField *)&RspQryNetModule;
			m_pSpi->OnRspQryNetModuleTopic(pRspQryNetModule, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetModule == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetModuleTopic(pRspQryNetModule, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///模块
void CFtdcUserApiImpl::OnRtnNetModuleTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetModuleField RtnNetModule;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetModuleField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetModule);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetModuleTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetModule, &CFTDRtnNetModuleField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetModuleTopic((CShfeFtdcRtnNetModuleField *)&RtnNetModule);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///告警表达式信息表
void CFtdcUserApiImpl::OnRspQryNetEventExprTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetEventExprField RspQryNetEventExpr;
	CShfeFtdcRspQryNetEventExprField *pRspQryNetEventExpr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetEventExprField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetEventExpr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetEventExpr = (CShfeFtdcRspQryNetEventExprField *)&RspQryNetEventExpr;
			m_pSpi->OnRspQryNetEventExprTopic(pRspQryNetEventExpr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetEventExpr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetEventExprTopic(pRspQryNetEventExpr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///告警表达式信息表
void CFtdcUserApiImpl::OnRtnNetEventExprTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetEventExprField RtnNetEventExpr;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetEventExprField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetEventExpr);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetEventExprTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetEventExpr, &CFTDRtnNetEventExprField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetEventExprTopic((CShfeFtdcRtnNetEventExprField *)&RtnNetEventExpr);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///事件类型
void CFtdcUserApiImpl::OnRspQryNetEventTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetEventTypeField RspQryNetEventType;
	CShfeFtdcRspQryNetEventTypeField *pRspQryNetEventType = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetEventTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetEventType);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetEventType = (CShfeFtdcRspQryNetEventTypeField *)&RspQryNetEventType;
			m_pSpi->OnRspQryNetEventTypeTopic(pRspQryNetEventType, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetEventType == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetEventTypeTopic(pRspQryNetEventType, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///事件类型
void CFtdcUserApiImpl::OnRtnNetEventTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetEventTypeField RtnNetEventType;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetEventTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetEventType);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetEventTypeTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetEventType, &CFTDRtnNetEventTypeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetEventTypeTopic((CShfeFtdcRtnNetEventTypeField *)&RtnNetEventType);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///事件子类型
void CFtdcUserApiImpl::OnRspQryNetSubEventTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetSubEventTypeField RspQryNetSubEventType;
	CShfeFtdcRspQryNetSubEventTypeField *pRspQryNetSubEventType = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetSubEventTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetSubEventType);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetSubEventType = (CShfeFtdcRspQryNetSubEventTypeField *)&RspQryNetSubEventType;
			m_pSpi->OnRspQryNetSubEventTypeTopic(pRspQryNetSubEventType, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetSubEventType == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetSubEventTypeTopic(pRspQryNetSubEventType, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///事件子类型
void CFtdcUserApiImpl::OnRtnNetSubEventTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetSubEventTypeField RtnNetSubEventType;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetSubEventTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetSubEventType);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetSubEventTypeTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetSubEventType, &CFTDRtnNetSubEventTypeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetSubEventTypeTopic((CShfeFtdcRtnNetSubEventTypeField *)&RtnNetSubEventType);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///事件级别
void CFtdcUserApiImpl::OnRspQryNetEventLevelTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetEventLevelField RspQryNetEventLevel;
	CShfeFtdcRspQryNetEventLevelField *pRspQryNetEventLevel = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetEventLevelField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetEventLevel);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetEventLevel = (CShfeFtdcRspQryNetEventLevelField *)&RspQryNetEventLevel;
			m_pSpi->OnRspQryNetEventLevelTopic(pRspQryNetEventLevel, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetEventLevel == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetEventLevelTopic(pRspQryNetEventLevel, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///事件级别
void CFtdcUserApiImpl::OnRtnNetEventLevelTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetEventLevelField RtnNetEventLevel;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetEventLevelField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetEventLevel);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetEventLevelTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetEventLevel, &CFTDRtnNetEventLevelField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetEventLevelTopic((CShfeFtdcRtnNetEventLevelField *)&RtnNetEventLevel);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///任务结果状态表
void CFtdcUserApiImpl::OnRspQryNetMonitorTaskStatusResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorTaskStatusResultField RspQryNetMonitorTaskStatusResult;
	CShfeFtdcRspQryNetMonitorTaskStatusResultField *pRspQryNetMonitorTaskStatusResult = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorTaskStatusResultField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorTaskStatusResult);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorTaskStatusResult = (CShfeFtdcRspQryNetMonitorTaskStatusResultField *)&RspQryNetMonitorTaskStatusResult;
			m_pSpi->OnRspQryNetMonitorTaskStatusResultTopic(pRspQryNetMonitorTaskStatusResult, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetMonitorTaskStatusResult == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorTaskStatusResultTopic(pRspQryNetMonitorTaskStatusResult, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///任务结果状态表
void CFtdcUserApiImpl::OnRtnNetMonitorTaskStatusResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetMonitorTaskStatusResultField RtnNetMonitorTaskStatusResult;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorTaskStatusResultField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorTaskStatusResult);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetMonitorTaskStatusResultTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetMonitorTaskStatusResult, &CFTDRtnNetMonitorTaskStatusResultField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorTaskStatusResultTopic((CShfeFtdcRtnNetMonitorTaskStatusResultField *)&RtnNetMonitorTaskStatusResult);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///配置服务对登陆的响应
void CFtdcUserApiImpl::OnRspConfigLoginTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryConfigLoginField RspQryConfigLogin;
	CShfeFtdcRspQryConfigLoginField *pRspQryConfigLogin = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryConfigLoginField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryConfigLogin);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryConfigLogin = (CShfeFtdcRspQryConfigLoginField *)&RspQryConfigLogin;
			m_pSpi->OnRspConfigLoginTopic(pRspQryConfigLogin, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryConfigLogin == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspConfigLoginTopic(pRspQryConfigLogin, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///对当前登录配置的服务角色的响应
void CFtdcUserApiImpl::OnRspServerTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspServerTypeField RspServerType;
	CShfeFtdcRspServerTypeField *pRspServerType = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspServerTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspServerType);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspServerType = (CShfeFtdcRspServerTypeField *)&RspServerType;
			m_pSpi->OnRspServerTypeTopic(pRspServerType, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspServerTypeTopic,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspServerType, &CFTDRspServerTypeField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspServerType == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspServerTypeTopic(pRspServerType, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///设备配置表
void CFtdcUserApiImpl::OnRspQryNetCfgFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetCfgFileField RspQryNetCfgFile;
	CShfeFtdcRspQryNetCfgFileField *pRspQryNetCfgFile = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetCfgFileField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetCfgFile);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetCfgFile = (CShfeFtdcRspQryNetCfgFileField *)&RspQryNetCfgFile;
			m_pSpi->OnRspQryNetCfgFileTopic(pRspQryNetCfgFile, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetCfgFile == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetCfgFileTopic(pRspQryNetCfgFile, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///设备配置表
void CFtdcUserApiImpl::OnRtnNetCfgFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetCfgFileField RtnNetCfgFile;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetCfgFileField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetCfgFile);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetCfgFileTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetCfgFile, &CFTDRtnNetCfgFileField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetCfgFileTopic((CShfeFtdcRtnNetCfgFileField *)&RtnNetCfgFile);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///任务结果规则分析表
void CFtdcUserApiImpl::OnRspQryNetMonitorDeviceTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorDeviceTaskField RspQryNetMonitorDeviceTask;
	CShfeFtdcRspQryNetMonitorDeviceTaskField *pRspQryNetMonitorDeviceTask = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorDeviceTaskField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorDeviceTask);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorDeviceTask = (CShfeFtdcRspQryNetMonitorDeviceTaskField *)&RspQryNetMonitorDeviceTask;
			m_pSpi->OnRspQryNetMonitorDeviceTaskTopic(pRspQryNetMonitorDeviceTask, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetMonitorDeviceTask == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorDeviceTaskTopic(pRspQryNetMonitorDeviceTask, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///任务结果规则分析表
void CFtdcUserApiImpl::OnRtnNetMonitorDeviceTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetMonitorDeviceTaskField RtnNetMonitorDeviceTask;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorDeviceTaskField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorDeviceTask);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetMonitorDeviceTaskTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetMonitorDeviceTask, &CFTDRtnNetMonitorDeviceTaskField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorDeviceTaskTopic((CShfeFtdcRtnNetMonitorDeviceTaskField *)&RtnNetMonitorDeviceTask);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///任务指令指标集表
void CFtdcUserApiImpl::OnRspQryNetMonitorTaskInstAttrsTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorTaskInstAttrsField RspQryNetMonitorTaskInstAttrs;
	CShfeFtdcRspQryNetMonitorTaskInstAttrsField *pRspQryNetMonitorTaskInstAttrs = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorTaskInstAttrsField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorTaskInstAttrs);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorTaskInstAttrs = (CShfeFtdcRspQryNetMonitorTaskInstAttrsField *)&RspQryNetMonitorTaskInstAttrs;
			m_pSpi->OnRspQryNetMonitorTaskInstAttrsTopic(pRspQryNetMonitorTaskInstAttrs, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetMonitorTaskInstAttrs == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorTaskInstAttrsTopic(pRspQryNetMonitorTaskInstAttrs, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///任务指令指标集表
void CFtdcUserApiImpl::OnRtnNetMonitorTaskInstAttrsTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetMonitorTaskInstAttrsField RtnNetMonitorTaskInstAttrs;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorTaskInstAttrsField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorTaskInstAttrs);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetMonitorTaskInstAttrsTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetMonitorTaskInstAttrs, &CFTDRtnNetMonitorTaskInstAttrsField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorTaskInstAttrsTopic((CShfeFtdcRtnNetMonitorTaskInstAttrsField *)&RtnNetMonitorTaskInstAttrs);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///文件通用操作
void CFtdcUserApiImpl::OnRspQryFileGeneralOperTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryFileGeneralOperField RspQryFileGeneralOper;
	CShfeFtdcRspQryFileGeneralOperField *pRspQryFileGeneralOper = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryFileGeneralOperField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryFileGeneralOper);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryFileGeneralOper = (CShfeFtdcRspQryFileGeneralOperField *)&RspQryFileGeneralOper;
			m_pSpi->OnRspQryFileGeneralOperTopic(pRspQryFileGeneralOper, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryFileGeneralOper == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryFileGeneralOperTopic(pRspQryFileGeneralOper, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///文件通用操作
void CFtdcUserApiImpl::OnRtnFileGeneralOperTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnFileGeneralOperField RtnFileGeneralOper;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnFileGeneralOperField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnFileGeneralOper);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnFileGeneralOperTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnFileGeneralOper, &CFTDRtnFileGeneralOperField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnFileGeneralOperTopic((CShfeFtdcRtnFileGeneralOperField *)&RtnFileGeneralOper);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///基线表
void CFtdcUserApiImpl::OnRspQryNetBaseLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetBaseLineField RspQryNetBaseLine;
	CShfeFtdcRspQryNetBaseLineField *pRspQryNetBaseLine = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetBaseLineField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetBaseLine);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetBaseLine = (CShfeFtdcRspQryNetBaseLineField *)&RspQryNetBaseLine;
			m_pSpi->OnRspQryNetBaseLineTopic(pRspQryNetBaseLine, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetBaseLine == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetBaseLineTopic(pRspQryNetBaseLine, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///基线表
void CFtdcUserApiImpl::OnRtnNetBaseLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetBaseLineField RtnNetBaseLine;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetBaseLineField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetBaseLine);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetBaseLineTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetBaseLine, &CFTDRtnNetBaseLineField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetBaseLineTopic((CShfeFtdcRtnNetBaseLineField *)&RtnNetBaseLine);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///基线任务表
void CFtdcUserApiImpl::OnRspQryNetBaseLineTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetBaseLineTaskField RspQryNetBaseLineTask;
	CShfeFtdcRspQryNetBaseLineTaskField *pRspQryNetBaseLineTask = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetBaseLineTaskField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetBaseLineTask);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetBaseLineTask = (CShfeFtdcRspQryNetBaseLineTaskField *)&RspQryNetBaseLineTask;
			m_pSpi->OnRspQryNetBaseLineTaskTopic(pRspQryNetBaseLineTask, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetBaseLineTask == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetBaseLineTaskTopic(pRspQryNetBaseLineTask, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///基线任务表
void CFtdcUserApiImpl::OnRtnNetBaseLineTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetBaseLineTaskField RtnNetBaseLineTask;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetBaseLineTaskField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetBaseLineTask);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetBaseLineTaskTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetBaseLineTask, &CFTDRtnNetBaseLineTaskField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetBaseLineTaskTopic((CShfeFtdcRtnNetBaseLineTaskField *)&RtnNetBaseLineTask);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///基线结果表
void CFtdcUserApiImpl::OnRspQryNetBaseLineResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetBaseLineResultField RspQryNetBaseLineResult;
	CShfeFtdcRspQryNetBaseLineResultField *pRspQryNetBaseLineResult = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetBaseLineResultField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetBaseLineResult);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetBaseLineResult = (CShfeFtdcRspQryNetBaseLineResultField *)&RspQryNetBaseLineResult;
			m_pSpi->OnRspQryNetBaseLineResultTopic(pRspQryNetBaseLineResult, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetBaseLineResult == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetBaseLineResultTopic(pRspQryNetBaseLineResult, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///基线结果表
void CFtdcUserApiImpl::OnRtnNetBaseLineResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetBaseLineResultField RtnNetBaseLineResult;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetBaseLineResultField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetBaseLineResult);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetBaseLineResultTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetBaseLineResult, &CFTDRtnNetBaseLineResultField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetBaseLineResultTopic((CShfeFtdcRtnNetBaseLineResultField *)&RtnNetBaseLineResult);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///会员链路状态信息表
void CFtdcUserApiImpl::OnRspQryNetPartyLinkStatusInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetPartyLinkStatusInfoField RspQryNetPartyLinkStatusInfo;
	CShfeFtdcRspQryNetPartyLinkStatusInfoField *pRspQryNetPartyLinkStatusInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetPartyLinkStatusInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetPartyLinkStatusInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetPartyLinkStatusInfo = (CShfeFtdcRspQryNetPartyLinkStatusInfoField *)&RspQryNetPartyLinkStatusInfo;
			m_pSpi->OnRspQryNetPartyLinkStatusInfoTopic(pRspQryNetPartyLinkStatusInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetPartyLinkStatusInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetPartyLinkStatusInfoTopic(pRspQryNetPartyLinkStatusInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员链路状态信息表
void CFtdcUserApiImpl::OnRtnNetPartyLinkStatusInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetPartyLinkStatusInfoField RtnNetPartyLinkStatusInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetPartyLinkStatusInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetPartyLinkStatusInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetPartyLinkStatusInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetPartyLinkStatusInfo, &CFTDRtnNetPartyLinkStatusInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetPartyLinkStatusInfoTopic((CShfeFtdcRtnNetPartyLinkStatusInfoField *)&RtnNetPartyLinkStatusInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///会员SDH线路明细表
void CFtdcUserApiImpl::OnRspQryNetMemberSDHLineInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMemberSDHLineInfoField RspQryNetMemberSDHLineInfo;
	CShfeFtdcRspQryNetMemberSDHLineInfoField *pRspQryNetMemberSDHLineInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMemberSDHLineInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMemberSDHLineInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMemberSDHLineInfo = (CShfeFtdcRspQryNetMemberSDHLineInfoField *)&RspQryNetMemberSDHLineInfo;
			m_pSpi->OnRspQryNetMemberSDHLineInfoTopic(pRspQryNetMemberSDHLineInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetMemberSDHLineInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMemberSDHLineInfoTopic(pRspQryNetMemberSDHLineInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员SDH线路明细表
void CFtdcUserApiImpl::OnRtnNetMemberSDHLineInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetMemberSDHLineInfoField RtnNetMemberSDHLineInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMemberSDHLineInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMemberSDHLineInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetMemberSDHLineInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetMemberSDHLineInfo, &CFTDRtnNetMemberSDHLineInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMemberSDHLineInfoTopic((CShfeFtdcRtnNetMemberSDHLineInfoField *)&RtnNetMemberSDHLineInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///DDN链路信息表
void CFtdcUserApiImpl::OnRspQryNetDDNLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetDDNLinkInfoField RspQryNetDDNLinkInfo;
	CShfeFtdcRspQryNetDDNLinkInfoField *pRspQryNetDDNLinkInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetDDNLinkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetDDNLinkInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetDDNLinkInfo = (CShfeFtdcRspQryNetDDNLinkInfoField *)&RspQryNetDDNLinkInfo;
			m_pSpi->OnRspQryNetDDNLinkInfoTopic(pRspQryNetDDNLinkInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetDDNLinkInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetDDNLinkInfoTopic(pRspQryNetDDNLinkInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///DDN链路信息表
void CFtdcUserApiImpl::OnRtnNetDDNLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetDDNLinkInfoField RtnNetDDNLinkInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetDDNLinkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetDDNLinkInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetDDNLinkInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetDDNLinkInfo, &CFTDRtnNetDDNLinkInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetDDNLinkInfoTopic((CShfeFtdcRtnNetDDNLinkInfoField *)&RtnNetDDNLinkInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///非会员线路使用信息
void CFtdcUserApiImpl::OnRspQryNetPseudMemberLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetPseudMemberLinkInfoField RspQryNetPseudMemberLinkInfo;
	CShfeFtdcRspQryNetPseudMemberLinkInfoField *pRspQryNetPseudMemberLinkInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetPseudMemberLinkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetPseudMemberLinkInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetPseudMemberLinkInfo = (CShfeFtdcRspQryNetPseudMemberLinkInfoField *)&RspQryNetPseudMemberLinkInfo;
			m_pSpi->OnRspQryNetPseudMemberLinkInfoTopic(pRspQryNetPseudMemberLinkInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetPseudMemberLinkInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetPseudMemberLinkInfoTopic(pRspQryNetPseudMemberLinkInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///非会员线路使用信息
void CFtdcUserApiImpl::OnRtnNetPseudMemberLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetPseudMemberLinkInfoField RtnNetPseudMemberLinkInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetPseudMemberLinkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetPseudMemberLinkInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetPseudMemberLinkInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetPseudMemberLinkInfo, &CFTDRtnNetPseudMemberLinkInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetPseudMemberLinkInfoTopic((CShfeFtdcRtnNetPseudMemberLinkInfoField *)&RtnNetPseudMemberLinkInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///远端设备信息
void CFtdcUserApiImpl::OnRspQryOuterDeviceInfTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryOuterDeviceInfField RspQryOuterDeviceInf;
	CShfeFtdcRspQryOuterDeviceInfField *pRspQryOuterDeviceInf = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryOuterDeviceInfField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryOuterDeviceInf);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryOuterDeviceInf = (CShfeFtdcRspQryOuterDeviceInfField *)&RspQryOuterDeviceInf;
			m_pSpi->OnRspQryOuterDeviceInfTopic(pRspQryOuterDeviceInf, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryOuterDeviceInf == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryOuterDeviceInfTopic(pRspQryOuterDeviceInf, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///远端设备信息
void CFtdcUserApiImpl::OnRtnNetOuterDeviceInfTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetOuterDeviceInfField RtnNetOuterDeviceInf;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetOuterDeviceInfField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetOuterDeviceInf);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetOuterDeviceInfTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetOuterDeviceInf, &CFTDRtnNetOuterDeviceInfField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetOuterDeviceInfTopic((CShfeFtdcRtnNetOuterDeviceInfField *)&RtnNetOuterDeviceInf);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///本地ping结果
void CFtdcUserApiImpl::OnRspQryNetLocalPingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetLocalPingResultInfoField RspQryNetLocalPingResultInfo;
	CShfeFtdcRspQryNetLocalPingResultInfoField *pRspQryNetLocalPingResultInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetLocalPingResultInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetLocalPingResultInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetLocalPingResultInfo = (CShfeFtdcRspQryNetLocalPingResultInfoField *)&RspQryNetLocalPingResultInfo;
			m_pSpi->OnRspQryNetLocalPingResultInfoTopic(pRspQryNetLocalPingResultInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetLocalPingResultInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetLocalPingResultInfoTopic(pRspQryNetLocalPingResultInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///本地ping结果
void CFtdcUserApiImpl::OnRtnNetLocalPingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetLocalPingResultInfoField RtnNetLocalPingResultInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetLocalPingResultInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetLocalPingResultInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetLocalPingResultInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetLocalPingResultInfo, &CFTDRtnNetLocalPingResultInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetLocalPingResultInfoTopic((CShfeFtdcRtnNetLocalPingResultInfoField *)&RtnNetLocalPingResultInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///远程ping结果
void CFtdcUserApiImpl::OnRspQryNetRomotePingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetRomotePingResultInfoField RspQryNetRomotePingResultInfo;
	CShfeFtdcRspQryNetRomotePingResultInfoField *pRspQryNetRomotePingResultInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetRomotePingResultInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetRomotePingResultInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetRomotePingResultInfo = (CShfeFtdcRspQryNetRomotePingResultInfoField *)&RspQryNetRomotePingResultInfo;
			m_pSpi->OnRspQryNetRomotePingResultInfoTopic(pRspQryNetRomotePingResultInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetRomotePingResultInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetRomotePingResultInfoTopic(pRspQryNetRomotePingResultInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///远程ping结果
void CFtdcUserApiImpl::OnRtnNetRomotePingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetRomotePingResultInfoField RtnNetRomotePingResultInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetRomotePingResultInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetRomotePingResultInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetRomotePingResultInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetRomotePingResultInfo, &CFTDRtnNetRomotePingResultInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetRomotePingResultInfoTopic((CShfeFtdcRtnNetRomotePingResultInfoField *)&RtnNetRomotePingResultInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///进程信息数据库专用
void CFtdcUserApiImpl::OnRtnMonitorTopProcessInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonitorTopProcessInfoField RtnMonitorTopProcessInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonitorTopProcessInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonitorTopProcessInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonitorTopProcessInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonitorTopProcessInfo, &CFTDRtnMonitorTopProcessInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonitorTopProcessInfo((CShfeFtdcRtnMonitorTopProcessInfoField *)&RtnMonitorTopProcessInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///系统内部级联关系
void CFtdcUserApiImpl::OnRspQrySysInternalTopologyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySysInternalTopologyField RspQrySysInternalTopology;
	CShfeFtdcRspQrySysInternalTopologyField *pRspQrySysInternalTopology = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySysInternalTopologyField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySysInternalTopology);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySysInternalTopology = (CShfeFtdcRspQrySysInternalTopologyField *)&RspQrySysInternalTopology;
			m_pSpi->OnRspQrySysInternalTopologyTopic(pRspQrySysInternalTopology, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQrySysInternalTopology == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySysInternalTopologyTopic(pRspQrySysInternalTopology, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///系统内部级联关系
void CFtdcUserApiImpl::OnRtnSysInternalTopologyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnSysInternalTopologyField RtnSysInternalTopology;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnSysInternalTopologyField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnSysInternalTopology);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnSysInternalTopologyTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnSysInternalTopology, &CFTDRtnSysInternalTopologyField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSysInternalTopologyTopic((CShfeFtdcRtnSysInternalTopologyField *)&RtnSysInternalTopology);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///返回会员链路费用表
void CFtdcUserApiImpl::OnRspQryMemberLinkCostTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMemberLinkCostField RspQryMemberLinkCost;
	CShfeFtdcRspQryMemberLinkCostField *pRspQryMemberLinkCost = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMemberLinkCostField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMemberLinkCost);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMemberLinkCost = (CShfeFtdcRspQryMemberLinkCostField *)&RspQryMemberLinkCost;
			m_pSpi->OnRspQryMemberLinkCostTopic(pRspQryMemberLinkCost, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMemberLinkCost == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMemberLinkCostTopic(pRspQryMemberLinkCost, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅会员链路费用表
void CFtdcUserApiImpl::OnRtnMemberLinkCostTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMemberLinkCostField RtnMemberLinkCost;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMemberLinkCostField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMemberLinkCost);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMemberLinkCostTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMemberLinkCost, &CFTDRtnMemberLinkCostField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMemberLinkCostTopic((CShfeFtdcRtnMemberLinkCostField *)&RtnMemberLinkCost);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///返回会员链路月租表
void CFtdcUserApiImpl::OnRspQryNetPartylinkMonthlyRentTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetPartylinkMonthlyRentField RspQryNetPartylinkMonthlyRent;
	CShfeFtdcRspQryNetPartylinkMonthlyRentField *pRspQryNetPartylinkMonthlyRent = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetPartylinkMonthlyRentField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetPartylinkMonthlyRent);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetPartylinkMonthlyRent = (CShfeFtdcRspQryNetPartylinkMonthlyRentField *)&RspQryNetPartylinkMonthlyRent;
			m_pSpi->OnRspQryNetPartylinkMonthlyRentTopic(pRspQryNetPartylinkMonthlyRent, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetPartylinkMonthlyRent == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetPartylinkMonthlyRentTopic(pRspQryNetPartylinkMonthlyRent, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅会员链路月租表
void CFtdcUserApiImpl::OnRtnNetPartylinkMonthlyRentTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetPartylinkMonthlyRentField RtnNetPartylinkMonthlyRent;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetPartylinkMonthlyRentField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetPartylinkMonthlyRent);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetPartylinkMonthlyRentTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetPartylinkMonthlyRent, &CFTDRtnNetPartylinkMonthlyRentField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetPartylinkMonthlyRentTopic((CShfeFtdcRtnNetPartylinkMonthlyRentField *)&RtnNetPartylinkMonthlyRent);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///返回非会员链路表信息
void CFtdcUserApiImpl::OnRspQryNetNonPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetNonPartyLinkInfoField RspQryNetNonPartyLinkInfo;
	CShfeFtdcRspQryNetNonPartyLinkInfoField *pRspQryNetNonPartyLinkInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetNonPartyLinkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetNonPartyLinkInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetNonPartyLinkInfo = (CShfeFtdcRspQryNetNonPartyLinkInfoField *)&RspQryNetNonPartyLinkInfo;
			m_pSpi->OnRspQryNetNonPartyLinkInfoTopic(pRspQryNetNonPartyLinkInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryNetNonPartyLinkInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetNonPartyLinkInfoTopic(pRspQryNetNonPartyLinkInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅非会员链路表信息
void CFtdcUserApiImpl::OnRtnNetNonPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnNetNonPartyLinkInfoField RtnNetNonPartyLinkInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetNonPartyLinkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetNonPartyLinkInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnNetNonPartyLinkInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnNetNonPartyLinkInfo, &CFTDRtnNetNonPartyLinkInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetNonPartyLinkInfoTopic((CShfeFtdcRtnNetNonPartyLinkInfoField *)&RtnNetNonPartyLinkInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///应答配置信息
void CFtdcUserApiImpl::OnRspQryMonConfigInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonConfigInfoField RspQryMonConfigInfo;
	CShfeFtdcRspQryMonConfigInfoField *pRspQryMonConfigInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonConfigInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonConfigInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonConfigInfo = (CShfeFtdcRspQryMonConfigInfoField *)&RspQryMonConfigInfo;
			m_pSpi->OnRspQryMonConfigInfo(pRspQryMonConfigInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonConfigInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonConfigInfo(pRspQryMonConfigInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///应答配置信息
void CFtdcUserApiImpl::OnRtnMonConfigInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonConfigInfoField RtnMonConfigInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonConfigInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonConfigInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonConfigInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonConfigInfo, &CFTDRtnMonConfigInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonConfigInfo((CShfeFtdcRtnMonConfigInfoField *)&RtnMonConfigInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///通知监控日信息
void CFtdcUserApiImpl::OnRtnMonitorDayInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDMonitorDayInfoField MonitorDayInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDMonitorDayInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&MonitorDayInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonitorDayInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&MonitorDayInfo, &CFTDMonitorDayInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonitorDayInfo((CShfeFtdcMonitorDayInfoField *)&MonitorDayInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///通知交易日信息
void CFtdcUserApiImpl::OnRtnTradingDayInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDTradingDayInfoField TradingDayInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDTradingDayInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&TradingDayInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnTradingDayInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&TradingDayInfo, &CFTDTradingDayInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTradingDayInfo((CShfeFtdcTradingDayInfoField *)&TradingDayInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///监控阶段结束
void CFtdcUserApiImpl::OnRtnSectionFinish(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDMonitorSectionField MonitorSection;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDMonitorSectionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&MonitorSection);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnSectionFinish,", szTimeBuffer);
			FIELD_TO_STRING((char *)&MonitorSection, &CFTDMonitorSectionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSectionFinish((CShfeFtdcMonitorSectionField *)&MonitorSection);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///监控阶段切换
void CFtdcUserApiImpl::OnRtnSectionChange(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDMonitorSectionField MonitorSection;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDMonitorSectionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&MonitorSection);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnSectionChange,", szTimeBuffer);
			FIELD_TO_STRING((char *)&MonitorSection, &CFTDMonitorSectionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSectionChange((CShfeFtdcMonitorSectionField *)&MonitorSection);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///服务连接响应
void CFtdcUserApiImpl::OnRspMonServiceConnect(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspMonServiceConnectField RspMonServiceConnect;
	CShfeFtdcRspMonServiceConnectField *pRspMonServiceConnect = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspMonServiceConnectField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspMonServiceConnect);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspMonServiceConnect = (CShfeFtdcRspMonServiceConnectField *)&RspMonServiceConnect;
			m_pSpi->OnRspMonServiceConnect(pRspMonServiceConnect, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspMonServiceConnect,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspMonServiceConnect, &CFTDRspMonServiceConnectField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspMonServiceConnect == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspMonServiceConnect(pRspMonServiceConnect, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///Proxy或探针名称配置
void CFtdcUserApiImpl::OnRtnMonProxyConfig(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonProxyConfigField RtnMonProxyConfig;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonProxyConfigField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonProxyConfig);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonProxyConfig,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonProxyConfig, &CFTDRtnMonProxyConfigField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonProxyConfig((CShfeFtdcRtnMonProxyConfigField *)&RtnMonProxyConfig);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///服务的当前状态响应
void CFtdcUserApiImpl::OnRspQryMonServiceStatus(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonServiceStatusField RspQryMonServiceStatus;
	CShfeFtdcRspQryMonServiceStatusField *pRspQryMonServiceStatus = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonServiceStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonServiceStatus);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonServiceStatus = (CShfeFtdcRspQryMonServiceStatusField *)&RspQryMonServiceStatus;
			m_pSpi->OnRspQryMonServiceStatus(pRspQryMonServiceStatus, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonServiceStatus == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonServiceStatus(pRspQryMonServiceStatus, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///服务的当前状态推送
void CFtdcUserApiImpl::OnRtnMonServiceStatus(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonServiceStatusField RtnMonServiceStatus;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonServiceStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonServiceStatus);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonServiceStatus,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonServiceStatus, &CFTDRtnMonServiceStatusField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonServiceStatus((CShfeFtdcRtnMonServiceStatusField *)&RtnMonServiceStatus);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///当前数据中心角色
void CFtdcUserApiImpl::OnRtnMonDataCenterRole(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonDataCenterRoleField RtnMonDataCenterRole;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonDataCenterRoleField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonDataCenterRole);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonDataCenterRole,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonDataCenterRole, &CFTDRtnMonDataCenterRoleField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonDataCenterRole((CShfeFtdcRtnMonDataCenterRoleField *)&RtnMonDataCenterRole);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///探针任务配置查询响应
void CFtdcUserApiImpl::OnRspQryMonProbeTask(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonProbeTaskField RspQryMonProbeTask;
	CShfeFtdcRspQryMonProbeTaskField *pRspQryMonProbeTask = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonProbeTaskField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonProbeTask);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonProbeTask = (CShfeFtdcRspQryMonProbeTaskField *)&RspQryMonProbeTask;
			m_pSpi->OnRspQryMonProbeTask(pRspQryMonProbeTask, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonProbeTask == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonProbeTask(pRspQryMonProbeTask, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///探针任务配置推送
void CFtdcUserApiImpl::OnRtnMonProbeTask(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonProbeTaskField RtnMonProbeTask;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonProbeTaskField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonProbeTask);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonProbeTask,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonProbeTask, &CFTDRtnMonProbeTaskField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonProbeTask((CShfeFtdcRtnMonProbeTaskField *)&RtnMonProbeTask);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///监控系统指标查询应答
void CFtdcUserApiImpl::OnRspQryMonObjectAttr(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonObjectAttrField RspQryMonObjectAttr;
	CShfeFtdcRspQryMonObjectAttrField *pRspQryMonObjectAttr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonObjectAttr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonObjectAttr = (CShfeFtdcRspQryMonObjectAttrField *)&RspQryMonObjectAttr;
			m_pSpi->OnRspQryMonObjectAttr(pRspQryMonObjectAttr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonObjectAttr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonObjectAttr(pRspQryMonObjectAttr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///监控系统指标查询推送
void CFtdcUserApiImpl::OnRtnMonObjectAttr(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonObjectAttrField RtnMonObjectAttr;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonObjectAttr);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonObjectAttr,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonObjectAttr, &CFTDRtnMonObjectAttrField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonObjectAttr((CShfeFtdcRtnMonObjectAttrField *)&RtnMonObjectAttr);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///监控系统Syslog事件查询应答
void CFtdcUserApiImpl::OnRspQryMonSyslogEvent(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonSyslogEventField RspQryMonSyslogEvent;
	CShfeFtdcRspQryMonSyslogEventField *pRspQryMonSyslogEvent = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonSyslogEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonSyslogEvent);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonSyslogEvent = (CShfeFtdcRspQryMonSyslogEventField *)&RspQryMonSyslogEvent;
			m_pSpi->OnRspQryMonSyslogEvent(pRspQryMonSyslogEvent, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonSyslogEvent == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonSyslogEvent(pRspQryMonSyslogEvent, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///监控系统Syslog事件查询推送
void CFtdcUserApiImpl::OnRtnMonSyslogEvent(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonSyslogEventField RtnMonSyslogEvent;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonSyslogEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonSyslogEvent);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonSyslogEvent,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonSyslogEvent, &CFTDRtnMonSyslogEventField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonSyslogEvent((CShfeFtdcRtnMonSyslogEventField *)&RtnMonSyslogEvent);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///文件读取偏移量查询应答
void CFtdcUserApiImpl::OnRspQryMonFileOffset(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonFileOffsetField RspQryMonFileOffset;
	CShfeFtdcRspQryMonFileOffsetField *pRspQryMonFileOffset = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonFileOffsetField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonFileOffset);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonFileOffset = (CShfeFtdcRspQryMonFileOffsetField *)&RspQryMonFileOffset;
			m_pSpi->OnRspQryMonFileOffset(pRspQryMonFileOffset, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonFileOffset == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonFileOffset(pRspQryMonFileOffset, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///文件读取偏移量查询推送
void CFtdcUserApiImpl::OnRtnMonFileOffset(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonFileOffsetField RtnMonFileOffset;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonFileOffsetField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonFileOffset);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonFileOffset,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonFileOffset, &CFTDRtnMonFileOffsetField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonFileOffset((CShfeFtdcRtnMonFileOffsetField *)&RtnMonFileOffset);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///文件内容查询应答
void CFtdcUserApiImpl::OnRspQryMonFileContent(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonFileContentField RspQryMonFileContent;
	CShfeFtdcRspQryMonFileContentField *pRspQryMonFileContent = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonFileContentField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonFileContent);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonFileContent = (CShfeFtdcRspQryMonFileContentField *)&RspQryMonFileContent;
			m_pSpi->OnRspQryMonFileContent(pRspQryMonFileContent, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonFileContent == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonFileContent(pRspQryMonFileContent, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///文件内容通告
void CFtdcUserApiImpl::OnRtnMonFileContent(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonFileContentField RtnMonFileContent;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonFileContentField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonFileContent);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonFileContent,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonFileContent, &CFTDRtnMonFileContentField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonFileContent((CShfeFtdcRtnMonFileContentField *)&RtnMonFileContent);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///主机基础环境信息应答
void CFtdcUserApiImpl::OnRspQryMonHostBasicEnv(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonHostBasicEnvField RspQryMonHostBasicEnv;
	CShfeFtdcRspQryMonHostBasicEnvField *pRspQryMonHostBasicEnv = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonHostBasicEnvField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonHostBasicEnv);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonHostBasicEnv = (CShfeFtdcRspQryMonHostBasicEnvField *)&RspQryMonHostBasicEnv;
			m_pSpi->OnRspQryMonHostBasicEnv(pRspQryMonHostBasicEnv, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonHostBasicEnv == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonHostBasicEnv(pRspQryMonHostBasicEnv, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主机基础环境信息应答
void CFtdcUserApiImpl::OnRtnMonHostBasicEnv(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonHostBasicEnvField RtnMonHostBasicEnv;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonHostBasicEnvField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonHostBasicEnv);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonHostBasicEnv,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonHostBasicEnv, &CFTDRtnMonHostBasicEnvField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonHostBasicEnv((CShfeFtdcRtnMonHostBasicEnvField *)&RtnMonHostBasicEnv);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///主机基础网络信息应答
void CFtdcUserApiImpl::OnRspQryMonHostNetworkEnv(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonHostNetworkEnvField RspQryMonHostNetworkEnv;
	CShfeFtdcRspQryMonHostNetworkEnvField *pRspQryMonHostNetworkEnv = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonHostNetworkEnvField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonHostNetworkEnv);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonHostNetworkEnv = (CShfeFtdcRspQryMonHostNetworkEnvField *)&RspQryMonHostNetworkEnv;
			m_pSpi->OnRspQryMonHostNetworkEnv(pRspQryMonHostNetworkEnv, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonHostNetworkEnv == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonHostNetworkEnv(pRspQryMonHostNetworkEnv, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主机基础网络信息通告
void CFtdcUserApiImpl::OnRtnMonHostNetworkEnv(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonHostNetworkEnvField RtnMonHostNetworkEnv;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonHostNetworkEnvField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonHostNetworkEnv);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonHostNetworkEnv,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonHostNetworkEnv, &CFTDRtnMonHostNetworkEnvField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonHostNetworkEnv((CShfeFtdcRtnMonHostNetworkEnvField *)&RtnMonHostNetworkEnv);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///主机文件系统信息应答
void CFtdcUserApiImpl::OnRspQryMonHostFileSysEnv(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonHostFileSysEnvField RspQryMonHostFileSysEnv;
	CShfeFtdcRspQryMonHostFileSysEnvField *pRspQryMonHostFileSysEnv = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonHostFileSysEnvField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonHostFileSysEnv);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonHostFileSysEnv = (CShfeFtdcRspQryMonHostFileSysEnvField *)&RspQryMonHostFileSysEnv;
			m_pSpi->OnRspQryMonHostFileSysEnv(pRspQryMonHostFileSysEnv, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonHostFileSysEnv == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonHostFileSysEnv(pRspQryMonHostFileSysEnv, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主机文件系统信息通告
void CFtdcUserApiImpl::OnRtnMonHostFileSysEnv(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonHostFileSysEnvField RtnMonHostFileSysEnv;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonHostFileSysEnvField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonHostFileSysEnv);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonHostFileSysEnv,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonHostFileSysEnv, &CFTDRtnMonHostFileSysEnvField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonHostFileSysEnv((CShfeFtdcRtnMonHostFileSysEnvField *)&RtnMonHostFileSysEnv);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///主机交换分区信息应答
void CFtdcUserApiImpl::OnRspQryMonHostSwapEnv(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonHostSwapEnvField RspQryMonHostSwapEnv;
	CShfeFtdcRspQryMonHostSwapEnvField *pRspQryMonHostSwapEnv = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonHostSwapEnvField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonHostSwapEnv);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonHostSwapEnv = (CShfeFtdcRspQryMonHostSwapEnvField *)&RspQryMonHostSwapEnv;
			m_pSpi->OnRspQryMonHostSwapEnv(pRspQryMonHostSwapEnv, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonHostSwapEnv == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonHostSwapEnv(pRspQryMonHostSwapEnv, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主机交换分区信息通告
void CFtdcUserApiImpl::OnRtnMonHostSwapEnv(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonHostSwapEnvField RtnMonHostSwapEnv;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonHostSwapEnvField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonHostSwapEnv);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonHostSwapEnv,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonHostSwapEnv, &CFTDRtnMonHostSwapEnvField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonHostSwapEnv((CShfeFtdcRtnMonHostSwapEnvField *)&RtnMonHostSwapEnv);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///主机的CPU信息指标信息应答
void CFtdcUserApiImpl::OnRspQryMonHostCPUAttr(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonHostCPUAttrField RspQryMonHostCPUAttr;
	CShfeFtdcRspQryMonHostCPUAttrField *pRspQryMonHostCPUAttr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonHostCPUAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonHostCPUAttr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonHostCPUAttr = (CShfeFtdcRspQryMonHostCPUAttrField *)&RspQryMonHostCPUAttr;
			m_pSpi->OnRspQryMonHostCPUAttr(pRspQryMonHostCPUAttr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonHostCPUAttr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonHostCPUAttr(pRspQryMonHostCPUAttr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主机的CPU信息指标信息
void CFtdcUserApiImpl::OnRtnMonHostCPUAttr(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonHostCPUAttrField RtnMonHostCPUAttr;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonHostCPUAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonHostCPUAttr);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonHostCPUAttr,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonHostCPUAttr, &CFTDRtnMonHostCPUAttrField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonHostCPUAttr((CShfeFtdcRtnMonHostCPUAttrField *)&RtnMonHostCPUAttr);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///主机的Memory使用信息应答
void CFtdcUserApiImpl::OnRspQryMonHostMemAttr(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonHostMemAttrField RspQryMonHostMemAttr;
	CShfeFtdcRspQryMonHostMemAttrField *pRspQryMonHostMemAttr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonHostMemAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonHostMemAttr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonHostMemAttr = (CShfeFtdcRspQryMonHostMemAttrField *)&RspQryMonHostMemAttr;
			m_pSpi->OnRspQryMonHostMemAttr(pRspQryMonHostMemAttr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonHostMemAttr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonHostMemAttr(pRspQryMonHostMemAttr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主机的Memory使用信息
void CFtdcUserApiImpl::OnRtnMonHostMemAttr(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonHostMemAttrField RtnMonHostMemAttr;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonHostMemAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonHostMemAttr);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonHostMemAttr,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonHostMemAttr, &CFTDRtnMonHostMemAttrField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonHostMemAttr((CShfeFtdcRtnMonHostMemAttrField *)&RtnMonHostMemAttr);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///主机的FileSystem使用信息应答
void CFtdcUserApiImpl::OnRspQryMonHostFileSystemAttr(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonHostFileSystemAttrField RspQryMonHostFileSystemAttr;
	CShfeFtdcRspQryMonHostFileSystemAttrField *pRspQryMonHostFileSystemAttr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonHostFileSystemAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonHostFileSystemAttr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonHostFileSystemAttr = (CShfeFtdcRspQryMonHostFileSystemAttrField *)&RspQryMonHostFileSystemAttr;
			m_pSpi->OnRspQryMonHostFileSystemAttr(pRspQryMonHostFileSystemAttr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonHostFileSystemAttr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonHostFileSystemAttr(pRspQryMonHostFileSystemAttr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主机的FileSystem使用信息
void CFtdcUserApiImpl::OnRtnMonHostFileSystemAttr(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonHostFileSystemAttrField RtnMonHostFileSystemAttr;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonHostFileSystemAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonHostFileSystemAttr);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonHostFileSystemAttr,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonHostFileSystemAttr, &CFTDRtnMonHostFileSystemAttrField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonHostFileSystemAttr((CShfeFtdcRtnMonHostFileSystemAttrField *)&RtnMonHostFileSystemAttr);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///主机的用户信息应答
void CFtdcUserApiImpl::OnRspQryMonHostUserInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonHostUserInfoField RspQryMonHostUserInfo;
	CShfeFtdcRspQryMonHostUserInfoField *pRspQryMonHostUserInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonHostUserInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonHostUserInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonHostUserInfo = (CShfeFtdcRspQryMonHostUserInfoField *)&RspQryMonHostUserInfo;
			m_pSpi->OnRspQryMonHostUserInfo(pRspQryMonHostUserInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonHostUserInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonHostUserInfo(pRspQryMonHostUserInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主机的用户信息
void CFtdcUserApiImpl::OnRtnMonHostUserInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonHostUserInfoField RtnMonHostUserInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonHostUserInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonHostUserInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonHostUserInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonHostUserInfo, &CFTDRtnMonHostUserInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonHostUserInfo((CShfeFtdcRtnMonHostUserInfoField *)&RtnMonHostUserInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///主机的在线用户信息应答
void CFtdcUserApiImpl::OnRspQryMonHostOnlineUserInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonHostOnlineUserInfoField RspQryMonHostOnlineUserInfo;
	CShfeFtdcRspQryMonHostOnlineUserInfoField *pRspQryMonHostOnlineUserInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonHostOnlineUserInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonHostOnlineUserInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonHostOnlineUserInfo = (CShfeFtdcRspQryMonHostOnlineUserInfoField *)&RspQryMonHostOnlineUserInfo;
			m_pSpi->OnRspQryMonHostOnlineUserInfo(pRspQryMonHostOnlineUserInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonHostOnlineUserInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonHostOnlineUserInfo(pRspQryMonHostOnlineUserInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主机的在线用户信息
void CFtdcUserApiImpl::OnRtnMonHostOnlineUserInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonHostOnlineUserInfoField RtnMonHostOnlineUserInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonHostOnlineUserInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonHostOnlineUserInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonHostOnlineUserInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonHostOnlineUserInfo, &CFTDRtnMonHostOnlineUserInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonHostOnlineUserInfo((CShfeFtdcRtnMonHostOnlineUserInfoField *)&RtnMonHostOnlineUserInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///主机的network使用信息应答
void CFtdcUserApiImpl::OnRspQryMonHostNetworkAttr(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonHostNetworkAttrField RspQryMonHostNetworkAttr;
	CShfeFtdcRspQryMonHostNetworkAttrField *pRspQryMonHostNetworkAttr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonHostNetworkAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonHostNetworkAttr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonHostNetworkAttr = (CShfeFtdcRspQryMonHostNetworkAttrField *)&RspQryMonHostNetworkAttr;
			m_pSpi->OnRspQryMonHostNetworkAttr(pRspQryMonHostNetworkAttr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonHostNetworkAttr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonHostNetworkAttr(pRspQryMonHostNetworkAttr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主机的network使用信息
void CFtdcUserApiImpl::OnRtnMonHostNetworkAttr(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonHostNetworkAttrField RtnMonHostNetworkAttr;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonHostNetworkAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonHostNetworkAttr);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonHostNetworkAttr,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonHostNetworkAttr, &CFTDRtnMonHostNetworkAttrField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonHostNetworkAttr((CShfeFtdcRtnMonHostNetworkAttrField *)&RtnMonHostNetworkAttr);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///主机的系统状态信息应答
void CFtdcUserApiImpl::OnRspQryMonHostStatInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonHostStatInfoField RspQryMonHostStatInfo;
	CShfeFtdcRspQryMonHostStatInfoField *pRspQryMonHostStatInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonHostStatInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonHostStatInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonHostStatInfo = (CShfeFtdcRspQryMonHostStatInfoField *)&RspQryMonHostStatInfo;
			m_pSpi->OnRspQryMonHostStatInfo(pRspQryMonHostStatInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonHostStatInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonHostStatInfo(pRspQryMonHostStatInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主机的系统状态信息
void CFtdcUserApiImpl::OnRtnMonHostStatInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonHostStatInfoField RtnMonHostStatInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonHostStatInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonHostStatInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonHostStatInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonHostStatInfo, &CFTDRtnMonHostStatInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonHostStatInfo((CShfeFtdcRtnMonHostStatInfoField *)&RtnMonHostStatInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///主机的磁盘IO信息应答
void CFtdcUserApiImpl::OnRspQryMonHostDiskIOAttr(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonHostDiskIOAttrField RspQryMonHostDiskIOAttr;
	CShfeFtdcRspQryMonHostDiskIOAttrField *pRspQryMonHostDiskIOAttr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonHostDiskIOAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonHostDiskIOAttr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonHostDiskIOAttr = (CShfeFtdcRspQryMonHostDiskIOAttrField *)&RspQryMonHostDiskIOAttr;
			m_pSpi->OnRspQryMonHostDiskIOAttr(pRspQryMonHostDiskIOAttr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonHostDiskIOAttr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonHostDiskIOAttr(pRspQryMonHostDiskIOAttr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主机的磁盘IO信息
void CFtdcUserApiImpl::OnRtnMonHostDiskIOAttr(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonHostDiskIOAttrField RtnMonHostDiskIOAttr;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonHostDiskIOAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonHostDiskIOAttr);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonHostDiskIOAttr,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonHostDiskIOAttr, &CFTDRtnMonHostDiskIOAttrField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonHostDiskIOAttr((CShfeFtdcRtnMonHostDiskIOAttrField *)&RtnMonHostDiskIOAttr);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///主机的路由信息应答
void CFtdcUserApiImpl::OnRspQryMonHostRouterInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonHostRouterInfoField RspQryMonHostRouterInfo;
	CShfeFtdcRspQryMonHostRouterInfoField *pRspQryMonHostRouterInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonHostRouterInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonHostRouterInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonHostRouterInfo = (CShfeFtdcRspQryMonHostRouterInfoField *)&RspQryMonHostRouterInfo;
			m_pSpi->OnRspQryMonHostRouterInfo(pRspQryMonHostRouterInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonHostRouterInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonHostRouterInfo(pRspQryMonHostRouterInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主机的路由信息
void CFtdcUserApiImpl::OnRtnMonHostRouterInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonHostRouterInfoField RtnMonHostRouterInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonHostRouterInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonHostRouterInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonHostRouterInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonHostRouterInfo, &CFTDRtnMonHostRouterInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonHostRouterInfo((CShfeFtdcRtnMonHostRouterInfoField *)&RtnMonHostRouterInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///主机的进程信息应答
void CFtdcUserApiImpl::OnRspQryMonHostProcessInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonHostProcessInfoField RspQryMonHostProcessInfo;
	CShfeFtdcRspQryMonHostProcessInfoField *pRspQryMonHostProcessInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonHostProcessInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonHostProcessInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonHostProcessInfo = (CShfeFtdcRspQryMonHostProcessInfoField *)&RspQryMonHostProcessInfo;
			m_pSpi->OnRspQryMonHostProcessInfo(pRspQryMonHostProcessInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonHostProcessInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonHostProcessInfo(pRspQryMonHostProcessInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主机的进程信息
void CFtdcUserApiImpl::OnRtnMonHostProcessInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonHostProcessInfoField RtnMonHostProcessInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonHostProcessInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonHostProcessInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonHostProcessInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonHostProcessInfo, &CFTDRtnMonHostProcessInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonHostProcessInfo((CShfeFtdcRtnMonHostProcessInfoField *)&RtnMonHostProcessInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///数据库采集的推送报文，包括了SP，DBLog，DBAttr
void CFtdcUserApiImpl::OnRtnMonDBQuery(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonDBQueryField RtnMonDBQuery;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonDBQueryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonDBQuery);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonDBQuery,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonDBQuery, &CFTDRtnMonDBQueryField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonDBQuery((CShfeFtdcRtnMonDBQueryField *)&RtnMonDBQuery);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///响应客户端临时SP查询请求
void CFtdcUserApiImpl::OnRspQryMonSPQuery(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRtnMonDBQueryField RtnMonDBQuery;
	CShfeFtdcRtnMonDBQueryField *pRtnMonDBQuery = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonDBQueryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonDBQuery);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRtnMonDBQuery = (CShfeFtdcRtnMonDBQueryField *)&RtnMonDBQuery;
			m_pSpi->OnRspQryMonSPQuery(pRtnMonDBQuery, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspQryMonSPQuery,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RtnMonDBQuery, &CFTDRtnMonDBQueryField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRtnMonDBQuery == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonSPQuery(pRtnMonDBQuery, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///服务版本信息响应
void CFtdcUserApiImpl::OnRspServiceVersion(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspServiceVersionField RspServiceVersion;
	CShfeFtdcRspServiceVersionField *pRspServiceVersion = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspServiceVersionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspServiceVersion);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspServiceVersion = (CShfeFtdcRspServiceVersionField *)&RspServiceVersion;
			m_pSpi->OnRspServiceVersion(pRspServiceVersion, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspServiceVersion,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspServiceVersion, &CFTDRspServiceVersionField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspServiceVersion == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspServiceVersion(pRspServiceVersion, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///服务应用程序响应
void CFtdcUserApiImpl::OnRspServiceProgram(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspServiceProgramField RspServiceProgram;
	CShfeFtdcRspServiceProgramField *pRspServiceProgram = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspServiceProgramField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspServiceProgram);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspServiceProgram = (CShfeFtdcRspServiceProgramField *)&RspServiceProgram;
			m_pSpi->OnRspServiceProgram(pRspServiceProgram, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspServiceProgram,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspServiceProgram, &CFTDRspServiceProgramField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspServiceProgram == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspServiceProgram(pRspServiceProgram, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///升级服务获取状态响应
void CFtdcUserApiImpl::OnRspUpdateState(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspUpdateStateField RspUpdateState;
	CShfeFtdcRspUpdateStateField *pRspUpdateState = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspUpdateStateField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspUpdateState);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspUpdateState = (CShfeFtdcRspUpdateStateField *)&RspUpdateState;
			m_pSpi->OnRspUpdateState(pRspUpdateState, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspUpdateState,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspUpdateState, &CFTDRspUpdateStateField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspUpdateState == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspUpdateState(pRspUpdateState, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅请求应答
void CFtdcUserApiImpl::OnRspSubscribe(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
}

///通知目标服务文件已成功接收
void CFtdcUserApiImpl::OnRspFileSendSuccess(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspFileSendSuccessField RspFileSendSuccess;
	CShfeFtdcRspFileSendSuccessField *pRspFileSendSuccess = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspFileSendSuccessField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspFileSendSuccess);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspFileSendSuccess = (CShfeFtdcRspFileSendSuccessField *)&RspFileSendSuccess;
			m_pSpi->OnRspFileSendSuccess(pRspFileSendSuccess, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRspFileSendSuccess,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&RspFileSendSuccess, &CFTDRspFileSendSuccessField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		
	}
	
	if (pRspFileSendSuccess == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspFileSendSuccess(pRspFileSendSuccess, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用于通知目标服务文件已发送成功
void CFtdcUserApiImpl::OnRtnFileSendSuccess(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnFileSendSuccessField RtnFileSendSuccess;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnFileSendSuccessField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnFileSendSuccess);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnFileSendSuccess,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnFileSendSuccess, &CFTDRtnFileSendSuccessField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnFileSendSuccess((CShfeFtdcRtnFileSendSuccessField *)&RtnFileSendSuccess);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///tomcat信息应答
void CFtdcUserApiImpl::OnRspQryMonTomcatInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonTomcatInfoField RspQryMonTomcatInfo;
	CShfeFtdcRspQryMonTomcatInfoField *pRspQryMonTomcatInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonTomcatInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonTomcatInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonTomcatInfo = (CShfeFtdcRspQryMonTomcatInfoField *)&RspQryMonTomcatInfo;
			m_pSpi->OnRspQryMonTomcatInfo(pRspQryMonTomcatInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonTomcatInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonTomcatInfo(pRspQryMonTomcatInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///tomcat信息推送
void CFtdcUserApiImpl::OnRtnMonTomcatInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonTomcatInfoField RtnMonTomcatInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonTomcatInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonTomcatInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonTomcatInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonTomcatInfo, &CFTDRtnMonTomcatInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonTomcatInfo((CShfeFtdcRtnMonTomcatInfoField *)&RtnMonTomcatInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///Web应用信息
void CFtdcUserApiImpl::OnRspQryMonWebAppInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonWebAppInfoField RspQryMonWebAppInfo;
	CShfeFtdcRspQryMonWebAppInfoField *pRspQryMonWebAppInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonWebAppInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonWebAppInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonWebAppInfo = (CShfeFtdcRspQryMonWebAppInfoField *)&RspQryMonWebAppInfo;
			m_pSpi->OnRspQryMonWebAppInfo(pRspQryMonWebAppInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonWebAppInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonWebAppInfo(pRspQryMonWebAppInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///Web应用信息
void CFtdcUserApiImpl::OnRtnMonWebAppInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonWebAppInfoField RtnMonWebAppInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonWebAppInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonWebAppInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonWebAppInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonWebAppInfo, &CFTDRtnMonWebAppInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonWebAppInfo((CShfeFtdcRtnMonWebAppInfoField *)&RtnMonWebAppInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///应用servlet信息
void CFtdcUserApiImpl::OnRspQryMonServletInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonServletInfoField RspQryMonServletInfo;
	CShfeFtdcRspQryMonServletInfoField *pRspQryMonServletInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonServletInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonServletInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonServletInfo = (CShfeFtdcRspQryMonServletInfoField *)&RspQryMonServletInfo;
			m_pSpi->OnRspQryMonServletInfo(pRspQryMonServletInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonServletInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonServletInfo(pRspQryMonServletInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///应用servlet信息
void CFtdcUserApiImpl::OnRtnMonServletInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonServletInfoField RtnMonServletInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonServletInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonServletInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonServletInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonServletInfo, &CFTDRtnMonServletInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonServletInfo((CShfeFtdcRtnMonServletInfoField *)&RtnMonServletInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///文件信息
void CFtdcUserApiImpl::OnRspQryMonFileInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonFileInfoField RspQryMonFileInfo;
	CShfeFtdcRspQryMonFileInfoField *pRspQryMonFileInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonFileInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonFileInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonFileInfo = (CShfeFtdcRspQryMonFileInfoField *)&RspQryMonFileInfo;
			m_pSpi->OnRspQryMonFileInfo(pRspQryMonFileInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonFileInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonFileInfo(pRspQryMonFileInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///文件信息
void CFtdcUserApiImpl::OnRtnMonFileInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonFileInfoField RtnMonFileInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonFileInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonFileInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonFileInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonFileInfo, &CFTDRtnMonFileInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonFileInfo((CShfeFtdcRtnMonFileInfoField *)&RtnMonFileInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///应用会话信息应答
void CFtdcUserApiImpl::OnRspQryMonSessionInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonSessionInfoField RspQryMonSessionInfo;
	CShfeFtdcRspQryMonSessionInfoField *pRspQryMonSessionInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonSessionInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonSessionInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonSessionInfo = (CShfeFtdcRspQryMonSessionInfoField *)&RspQryMonSessionInfo;
			m_pSpi->OnRspQryMonSessionInfo(pRspQryMonSessionInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonSessionInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonSessionInfo(pRspQryMonSessionInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///应用会话信息推送
void CFtdcUserApiImpl::OnRtnMonSessionInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonSessionInfoField RtnMonSessionInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonSessionInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonSessionInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonSessionInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonSessionInfo, &CFTDRtnMonSessionInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonSessionInfo((CShfeFtdcRtnMonSessionInfoField *)&RtnMonSessionInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///JDBC信息
void CFtdcUserApiImpl::OnRspQryMonJDBCInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonJDBCInfoField RspQryMonJDBCInfo;
	CShfeFtdcRspQryMonJDBCInfoField *pRspQryMonJDBCInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonJDBCInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonJDBCInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonJDBCInfo = (CShfeFtdcRspQryMonJDBCInfoField *)&RspQryMonJDBCInfo;
			m_pSpi->OnRspQryMonJDBCInfo(pRspQryMonJDBCInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonJDBCInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonJDBCInfo(pRspQryMonJDBCInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///JDBC信息
void CFtdcUserApiImpl::OnRtnMonJDBCInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonJDBCInfoField RtnMonJDBCInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonJDBCInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonJDBCInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonJDBCInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonJDBCInfo, &CFTDRtnMonJDBCInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonJDBCInfo((CShfeFtdcRtnMonJDBCInfoField *)&RtnMonJDBCInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///线程信息
void CFtdcUserApiImpl::OnRspQryMonThreadInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonThreadInfoField RspQryMonThreadInfo;
	CShfeFtdcRspQryMonThreadInfoField *pRspQryMonThreadInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonThreadInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonThreadInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonThreadInfo = (CShfeFtdcRspQryMonThreadInfoField *)&RspQryMonThreadInfo;
			m_pSpi->OnRspQryMonThreadInfo(pRspQryMonThreadInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonThreadInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonThreadInfo(pRspQryMonThreadInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///线程信息
void CFtdcUserApiImpl::OnRtnMonThreadInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonThreadInfoField RtnMonThreadInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonThreadInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonThreadInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonThreadInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonThreadInfo, &CFTDRtnMonThreadInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonThreadInfo((CShfeFtdcRtnMonThreadInfoField *)&RtnMonThreadInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///虚拟机信息
void CFtdcUserApiImpl::OnRspQryMonVMInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonVMInfoField RspQryMonVMInfo;
	CShfeFtdcRspQryMonVMInfoField *pRspQryMonVMInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonVMInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonVMInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonVMInfo = (CShfeFtdcRspQryMonVMInfoField *)&RspQryMonVMInfo;
			m_pSpi->OnRspQryMonVMInfo(pRspQryMonVMInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonVMInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonVMInfo(pRspQryMonVMInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///虚拟机信息
void CFtdcUserApiImpl::OnRtnMonVMInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonVMInfoField RtnMonVMInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonVMInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonVMInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonVMInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonVMInfo, &CFTDRtnMonVMInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonVMInfo((CShfeFtdcRtnMonVMInfoField *)&RtnMonVMInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///系统属性信息
void CFtdcUserApiImpl::OnRspQryMonPropertyInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonPropertyInfoField RspQryMonPropertyInfo;
	CShfeFtdcRspQryMonPropertyInfoField *pRspQryMonPropertyInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonPropertyInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonPropertyInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonPropertyInfo = (CShfeFtdcRspQryMonPropertyInfoField *)&RspQryMonPropertyInfo;
			m_pSpi->OnRspQryMonPropertyInfo(pRspQryMonPropertyInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonPropertyInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonPropertyInfo(pRspQryMonPropertyInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///系统属性信息
void CFtdcUserApiImpl::OnRtnMonPropertyInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonPropertyInfoField RtnMonPropertyInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonPropertyInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonPropertyInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonPropertyInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonPropertyInfo, &CFTDRtnMonPropertyInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonPropertyInfo((CShfeFtdcRtnMonPropertyInfoField *)&RtnMonPropertyInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///系统内存池信息
void CFtdcUserApiImpl::OnRspQryMonMemPoolInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonMemPoolInfoField RspQryMonMemPoolInfo;
	CShfeFtdcRspQryMonMemPoolInfoField *pRspQryMonMemPoolInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonMemPoolInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonMemPoolInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonMemPoolInfo = (CShfeFtdcRspQryMonMemPoolInfoField *)&RspQryMonMemPoolInfo;
			m_pSpi->OnRspQryMonMemPoolInfo(pRspQryMonMemPoolInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonMemPoolInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonMemPoolInfo(pRspQryMonMemPoolInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///系统内存池信息
void CFtdcUserApiImpl::OnRtnMonMemPoolInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonMemPoolInfoField RtnMonMemPoolInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonMemPoolInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonMemPoolInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonMemPoolInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonMemPoolInfo, &CFTDRtnMonMemPoolInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonMemPoolInfo((CShfeFtdcRtnMonMemPoolInfoField *)&RtnMonMemPoolInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///连接信息
void CFtdcUserApiImpl::OnRspQryMonConnectionInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonConnectionInfoField RspQryMonConnectionInfo;
	CShfeFtdcRspQryMonConnectionInfoField *pRspQryMonConnectionInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonConnectionInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonConnectionInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonConnectionInfo = (CShfeFtdcRspQryMonConnectionInfoField *)&RspQryMonConnectionInfo;
			m_pSpi->OnRspQryMonConnectionInfo(pRspQryMonConnectionInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonConnectionInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonConnectionInfo(pRspQryMonConnectionInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///连接信息
void CFtdcUserApiImpl::OnRtnMonConnectionInfo(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonConnectionInfoField RtnMonConnectionInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonConnectionInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonConnectionInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonConnectionInfo,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonConnectionInfo, &CFTDRtnMonConnectionInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonConnectionInfo((CShfeFtdcRtnMonConnectionInfoField *)&RtnMonConnectionInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///无效报单查询应答
void CFtdcUserApiImpl::OnRspQryInvalidateOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryInvalidateOrderField RspQryInvalidateOrder;
	CShfeFtdcRspQryInvalidateOrderField *pRspQryInvalidateOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryInvalidateOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryInvalidateOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryInvalidateOrder = (CShfeFtdcRspQryInvalidateOrderField *)&RspQryInvalidateOrder;
			m_pSpi->OnRspQryInvalidateOrderTopic(pRspQryInvalidateOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryInvalidateOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryInvalidateOrderTopic(pRspQryInvalidateOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///无效报单查询应答
void CFtdcUserApiImpl::OnRtnInvalidateOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnInvalidateOrderField RtnInvalidateOrder;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnInvalidateOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnInvalidateOrder);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnInvalidateOrderTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnInvalidateOrder, &CFTDRtnInvalidateOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnInvalidateOrderTopic((CShfeFtdcRtnInvalidateOrderField *)&RtnInvalidateOrder);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///报单状态查询应答
void CFtdcUserApiImpl::OnRspQryOrderStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryOrderStatusField RspQryOrderStatus;
	CShfeFtdcRspQryOrderStatusField *pRspQryOrderStatus = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryOrderStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryOrderStatus);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryOrderStatus = (CShfeFtdcRspQryOrderStatusField *)&RspQryOrderStatus;
			m_pSpi->OnRspQryOrderStatusTopic(pRspQryOrderStatus, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryOrderStatus == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryOrderStatusTopic(pRspQryOrderStatus, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///报单状态查询应答
void CFtdcUserApiImpl::OnRtnOrderStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnOrderStatusField RtnOrderStatus;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnOrderStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnOrderStatus);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnOrderStatusTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnOrderStatus, &CFTDRtnOrderStatusField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnOrderStatusTopic((CShfeFtdcRtnOrderStatusField *)&RtnOrderStatus);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///报单成交查询应答
void CFtdcUserApiImpl::OnRspQryBargainOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryBargainOrderField RspQryBargainOrder;
	CShfeFtdcRspQryBargainOrderField *pRspQryBargainOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryBargainOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryBargainOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryBargainOrder = (CShfeFtdcRspQryBargainOrderField *)&RspQryBargainOrder;
			m_pSpi->OnRspQryBargainOrderTopic(pRspQryBargainOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryBargainOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryBargainOrderTopic(pRspQryBargainOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///报单成交查询应答
void CFtdcUserApiImpl::OnRtnBargainOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnBargainOrderField RtnBargainOrder;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnBargainOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnBargainOrder);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnBargainOrderTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnBargainOrder, &CFTDRtnBargainOrderField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnBargainOrderTopic((CShfeFtdcRtnBargainOrderField *)&RtnBargainOrder);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///合约基本属性查询应答
void CFtdcUserApiImpl::OnRspQryInstPropertyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryInstPropertyField RspQryInstProperty;
	CShfeFtdcRspQryInstPropertyField *pRspQryInstProperty = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryInstPropertyField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryInstProperty);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryInstProperty = (CShfeFtdcRspQryInstPropertyField *)&RspQryInstProperty;
			m_pSpi->OnRspQryInstPropertyTopic(pRspQryInstProperty, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryInstProperty == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryInstPropertyTopic(pRspQryInstProperty, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///合约基本属性查询应答
void CFtdcUserApiImpl::OnRtnInstPropertyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnInstPropertyField RtnInstProperty;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnInstPropertyField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnInstProperty);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnInstPropertyTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnInstProperty, &CFTDRtnInstPropertyField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnInstPropertyTopic((CShfeFtdcRtnInstPropertyField *)&RtnInstProperty);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///合约保证金率查询应答
void CFtdcUserApiImpl::OnRspQryMarginRateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMarginRateField RspQryMarginRate;
	CShfeFtdcRspQryMarginRateField *pRspQryMarginRate = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMarginRateField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMarginRate);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMarginRate = (CShfeFtdcRspQryMarginRateField *)&RspQryMarginRate;
			m_pSpi->OnRspQryMarginRateTopic(pRspQryMarginRate, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMarginRate == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMarginRateTopic(pRspQryMarginRate, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///合约保证金率查询应答
void CFtdcUserApiImpl::OnRtnMarginRateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMarginRateField RtnMarginRate;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMarginRateField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMarginRate);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMarginRateTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMarginRate, &CFTDRtnMarginRateField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMarginRateTopic((CShfeFtdcRtnMarginRateField *)&RtnMarginRate);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///合约涨跌停板查询应答
void CFtdcUserApiImpl::OnRspQryPriceLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryPriceLimitField RspQryPriceLimit;
	CShfeFtdcRspQryPriceLimitField *pRspQryPriceLimit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryPriceLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryPriceLimit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryPriceLimit = (CShfeFtdcRspQryPriceLimitField *)&RspQryPriceLimit;
			m_pSpi->OnRspQryPriceLimitTopic(pRspQryPriceLimit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryPriceLimit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPriceLimitTopic(pRspQryPriceLimit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///合约涨跌停板查询应答
void CFtdcUserApiImpl::OnRtnPriceLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnPriceLimitField RtnPriceLimit;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnPriceLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnPriceLimit);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnPriceLimitTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnPriceLimit, &CFTDRtnPriceLimitField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnPriceLimitTopic((CShfeFtdcRtnPriceLimitField *)&RtnPriceLimit);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///会员限仓查询应答
void CFtdcUserApiImpl::OnRspQryPartPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryPartPosiLimitField RspQryPartPosiLimit;
	CShfeFtdcRspQryPartPosiLimitField *pRspQryPartPosiLimit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryPartPosiLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryPartPosiLimit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryPartPosiLimit = (CShfeFtdcRspQryPartPosiLimitField *)&RspQryPartPosiLimit;
			m_pSpi->OnRspQryPartPosiLimitTopic(pRspQryPartPosiLimit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryPartPosiLimit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPartPosiLimitTopic(pRspQryPartPosiLimit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员限仓查询应答
void CFtdcUserApiImpl::OnRtnPartPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnPartPosiLimitField RtnPartPosiLimit;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnPartPosiLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnPartPosiLimit);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnPartPosiLimitTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnPartPosiLimit, &CFTDRtnPartPosiLimitField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnPartPosiLimitTopic((CShfeFtdcRtnPartPosiLimitField *)&RtnPartPosiLimit);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///客户限仓查询应答
void CFtdcUserApiImpl::OnRspQryClientPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryClientPosiLimitField RspQryClientPosiLimit;
	CShfeFtdcRspQryClientPosiLimitField *pRspQryClientPosiLimit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryClientPosiLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryClientPosiLimit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryClientPosiLimit = (CShfeFtdcRspQryClientPosiLimitField *)&RspQryClientPosiLimit;
			m_pSpi->OnRspQryClientPosiLimitTopic(pRspQryClientPosiLimit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryClientPosiLimit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryClientPosiLimitTopic(pRspQryClientPosiLimit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///客户限仓查询应答
void CFtdcUserApiImpl::OnRtnClientPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnClientPosiLimitField RtnClientPosiLimit;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnClientPosiLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnClientPosiLimit);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnClientPosiLimitTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnClientPosiLimit, &CFTDRtnClientPosiLimitField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnClientPosiLimitTopic((CShfeFtdcRtnClientPosiLimitField *)&RtnClientPosiLimit);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///特殊客户限仓查询应答
void CFtdcUserApiImpl::OnRspQrySpecialPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySpecialPosiLimitField RspQrySpecialPosiLimit;
	CShfeFtdcRspQrySpecialPosiLimitField *pRspQrySpecialPosiLimit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySpecialPosiLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySpecialPosiLimit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySpecialPosiLimit = (CShfeFtdcRspQrySpecialPosiLimitField *)&RspQrySpecialPosiLimit;
			m_pSpi->OnRspQrySpecialPosiLimitTopic(pRspQrySpecialPosiLimit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQrySpecialPosiLimit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySpecialPosiLimitTopic(pRspQrySpecialPosiLimit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///特殊客户限仓查询应答
void CFtdcUserApiImpl::OnRtnSpecialPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnSpecialPosiLimitField RtnSpecialPosiLimit;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnSpecialPosiLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnSpecialPosiLimit);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnSpecialPosiLimitTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnSpecialPosiLimit, &CFTDRtnSpecialPosiLimitField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSpecialPosiLimitTopic((CShfeFtdcRtnSpecialPosiLimitField *)&RtnSpecialPosiLimit);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///账户出入金查询应答
void CFtdcUserApiImpl::OnRspQryTransactionChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTransactionChgField RspQryTransactionChg;
	CShfeFtdcRspQryTransactionChgField *pRspQryTransactionChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTransactionChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTransactionChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTransactionChg = (CShfeFtdcRspQryTransactionChgField *)&RspQryTransactionChg;
			m_pSpi->OnRspQryTransactionChgTopic(pRspQryTransactionChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryTransactionChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTransactionChgTopic(pRspQryTransactionChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///账户出入金查询应答
void CFtdcUserApiImpl::OnRtnTransactionChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnTransactionChgField RtnTransactionChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnTransactionChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnTransactionChg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnTransactionChgTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnTransactionChg, &CFTDRtnTransactionChgField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTransactionChgTopic((CShfeFtdcRtnTransactionChgField *)&RtnTransactionChg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///客户数据变动查询应答
void CFtdcUserApiImpl::OnRspQryClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryClientChgField RspQryClientChg;
	CShfeFtdcRspQryClientChgField *pRspQryClientChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryClientChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryClientChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryClientChg = (CShfeFtdcRspQryClientChgField *)&RspQryClientChg;
			m_pSpi->OnRspQryClientChgTopic(pRspQryClientChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryClientChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryClientChgTopic(pRspQryClientChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///客户数据变动查询应答
void CFtdcUserApiImpl::OnRtnClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnClientChgField RtnClientChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnClientChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnClientChg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnClientChgTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnClientChg, &CFTDRtnClientChgField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnClientChgTopic((CShfeFtdcRtnClientChgField *)&RtnClientChg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///会员客户对照变动查询应答
void CFtdcUserApiImpl::OnRspQryPartClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryPartClientChgField RspQryPartClientChg;
	CShfeFtdcRspQryPartClientChgField *pRspQryPartClientChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryPartClientChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryPartClientChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryPartClientChg = (CShfeFtdcRspQryPartClientChgField *)&RspQryPartClientChg;
			m_pSpi->OnRspQryPartClientChgTopic(pRspQryPartClientChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryPartClientChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPartClientChgTopic(pRspQryPartClientChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员客户对照变动查询应答
void CFtdcUserApiImpl::OnRtnPartClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnPartClientChgField RtnPartClientChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnPartClientChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnPartClientChg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnPartClientChgTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnPartClientChg, &CFTDRtnPartClientChgField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnPartClientChgTopic((CShfeFtdcRtnPartClientChgField *)&RtnPartClientChg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///限仓数据变动查询应答
void CFtdcUserApiImpl::OnRspQryPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryPosiLimitChgField RspQryPosiLimitChg;
	CShfeFtdcRspQryPosiLimitChgField *pRspQryPosiLimitChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryPosiLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryPosiLimitChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryPosiLimitChg = (CShfeFtdcRspQryPosiLimitChgField *)&RspQryPosiLimitChg;
			m_pSpi->OnRspQryPosiLimitChgTopic(pRspQryPosiLimitChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryPosiLimitChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPosiLimitChgTopic(pRspQryPosiLimitChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///限仓数据变动查询应答
void CFtdcUserApiImpl::OnRtnPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnPosiLimitChgField RtnPosiLimitChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnPosiLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnPosiLimitChg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnPosiLimitChgTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnPosiLimitChg, &CFTDRtnPosiLimitChgField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnPosiLimitChgTopic((CShfeFtdcRtnPosiLimitChgField *)&RtnPosiLimitChg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///保值额度变动查询应答
void CFtdcUserApiImpl::OnRspQryHedgeDetailChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryHedgeDetailChgField RspQryHedgeDetailChg;
	CShfeFtdcRspQryHedgeDetailChgField *pRspQryHedgeDetailChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryHedgeDetailChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryHedgeDetailChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryHedgeDetailChg = (CShfeFtdcRspQryHedgeDetailChgField *)&RspQryHedgeDetailChg;
			m_pSpi->OnRspQryHedgeDetailChgTopic(pRspQryHedgeDetailChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryHedgeDetailChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryHedgeDetailChgTopic(pRspQryHedgeDetailChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///保值额度变动查询应答
void CFtdcUserApiImpl::OnRtnHedgeDetailChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnHedgeDetailChgField RtnHedgeDetailChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnHedgeDetailChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnHedgeDetailChg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnHedgeDetailChgTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnHedgeDetailChg, &CFTDRtnHedgeDetailChgField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnHedgeDetailChgTopic((CShfeFtdcRtnHedgeDetailChgField *)&RtnHedgeDetailChg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///会员变动查询应答
void CFtdcUserApiImpl::OnRspQryParticipantChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryParticipantChgField RspQryParticipantChg;
	CShfeFtdcRspQryParticipantChgField *pRspQryParticipantChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryParticipantChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryParticipantChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryParticipantChg = (CShfeFtdcRspQryParticipantChgField *)&RspQryParticipantChg;
			m_pSpi->OnRspQryParticipantChgTopic(pRspQryParticipantChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryParticipantChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryParticipantChgTopic(pRspQryParticipantChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员变动查询应答
void CFtdcUserApiImpl::OnRtnParticipantChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnParticipantChgField RtnParticipantChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnParticipantChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnParticipantChg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnParticipantChgTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnParticipantChg, &CFTDRtnParticipantChgField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnParticipantChgTopic((CShfeFtdcRtnParticipantChgField *)&RtnParticipantChg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///保证金率变动查询应答
void CFtdcUserApiImpl::OnRspQryMarginRateChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMarginRateChgField RspQryMarginRateChg;
	CShfeFtdcRspQryMarginRateChgField *pRspQryMarginRateChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMarginRateChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMarginRateChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMarginRateChg = (CShfeFtdcRspQryMarginRateChgField *)&RspQryMarginRateChg;
			m_pSpi->OnRspQryMarginRateChgTopic(pRspQryMarginRateChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMarginRateChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMarginRateChgTopic(pRspQryMarginRateChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///保证金率变动查询应答
void CFtdcUserApiImpl::OnRtnMarginRateChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMarginRateChgField RtnMarginRateChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMarginRateChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMarginRateChg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMarginRateChgTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMarginRateChg, &CFTDRtnMarginRateChgField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMarginRateChgTopic((CShfeFtdcRtnMarginRateChgField *)&RtnMarginRateChg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///IP地址变动查询应答
void CFtdcUserApiImpl::OnRspQryUserIpChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryUserIpChgField RspQryUserIpChg;
	CShfeFtdcRspQryUserIpChgField *pRspQryUserIpChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryUserIpChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryUserIpChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryUserIpChg = (CShfeFtdcRspQryUserIpChgField *)&RspQryUserIpChg;
			m_pSpi->OnRspQryUserIpChgTopic(pRspQryUserIpChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryUserIpChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryUserIpChgTopic(pRspQryUserIpChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///IP地址变动查询应答
void CFtdcUserApiImpl::OnRtnUserIpChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnUserIpChgField RtnUserIpChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnUserIpChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnUserIpChg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnUserIpChgTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnUserIpChg, &CFTDRtnUserIpChgField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnUserIpChgTopic((CShfeFtdcRtnUserIpChgField *)&RtnUserIpChg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///限仓数据变动查询应答
void CFtdcUserApiImpl::OnRspQryClientPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryClientPosiLimitChgField RspQryClientPosiLimitChg;
	CShfeFtdcRspQryClientPosiLimitChgField *pRspQryClientPosiLimitChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryClientPosiLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryClientPosiLimitChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryClientPosiLimitChg = (CShfeFtdcRspQryClientPosiLimitChgField *)&RspQryClientPosiLimitChg;
			m_pSpi->OnRspQryClientPosiLimitChgTopic(pRspQryClientPosiLimitChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryClientPosiLimitChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryClientPosiLimitChgTopic(pRspQryClientPosiLimitChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///限仓数据变动查询应答
void CFtdcUserApiImpl::OnRtnClientPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnClientPosiLimitChgField RtnClientPosiLimitChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnClientPosiLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnClientPosiLimitChg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnClientPosiLimitChgTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnClientPosiLimitChg, &CFTDRtnClientPosiLimitChgField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnClientPosiLimitChgTopic((CShfeFtdcRtnClientPosiLimitChgField *)&RtnClientPosiLimitChg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///限仓数据变动查询应答
void CFtdcUserApiImpl::OnRspQrySpecPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySpecPosiLimitChgField RspQrySpecPosiLimitChg;
	CShfeFtdcRspQrySpecPosiLimitChgField *pRspQrySpecPosiLimitChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySpecPosiLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySpecPosiLimitChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySpecPosiLimitChg = (CShfeFtdcRspQrySpecPosiLimitChgField *)&RspQrySpecPosiLimitChg;
			m_pSpi->OnRspQrySpecPosiLimitChgTopic(pRspQrySpecPosiLimitChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQrySpecPosiLimitChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySpecPosiLimitChgTopic(pRspQrySpecPosiLimitChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///限仓数据变动查询应答
void CFtdcUserApiImpl::OnRtnSpecPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnSpecPosiLimitChgField RtnSpecPosiLimitChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnSpecPosiLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnSpecPosiLimitChg);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnSpecPosiLimitChgTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnSpecPosiLimitChg, &CFTDRtnSpecPosiLimitChgField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSpecPosiLimitChgTopic((CShfeFtdcRtnSpecPosiLimitChgField *)&RtnSpecPosiLimitChg);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///交易系统前置统计应答
void CFtdcUserApiImpl::OnRspQryFrontStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryFrontStatField RspQryFrontStat;
	CShfeFtdcRspQryFrontStatField *pRspQryFrontStat = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryFrontStatField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryFrontStat);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryFrontStat = (CShfeFtdcRspQryFrontStatField *)&RspQryFrontStat;
			m_pSpi->OnRspQryFrontStatTopic(pRspQryFrontStat, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryFrontStat == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryFrontStatTopic(pRspQryFrontStat, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员初始化应答
void CFtdcUserApiImpl::OnRspQryParticipantInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryParticipantInitField RspQryParticipantInit;
	CShfeFtdcRspQryParticipantInitField *pRspQryParticipantInit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryParticipantInitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryParticipantInit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryParticipantInit = (CShfeFtdcRspQryParticipantInitField *)&RspQryParticipantInit;
			m_pSpi->OnRspQryParticipantInitTopic(pRspQryParticipantInit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryParticipantInit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryParticipantInitTopic(pRspQryParticipantInit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员初始化应答
void CFtdcUserApiImpl::OnRtnParticipantInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnParticipantInitField RtnParticipantInit;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnParticipantInitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnParticipantInit);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnParticipantInitTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnParticipantInit, &CFTDRtnParticipantInitField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnParticipantInitTopic((CShfeFtdcRtnParticipantInitField *)&RtnParticipantInit);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///座席初始化应答
void CFtdcUserApiImpl::OnRspQryUserInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryUserInitField RspQryUserInit;
	CShfeFtdcRspQryUserInitField *pRspQryUserInit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryUserInitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryUserInit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryUserInit = (CShfeFtdcRspQryUserInitField *)&RspQryUserInit;
			m_pSpi->OnRspQryUserInitTopic(pRspQryUserInit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryUserInit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryUserInitTopic(pRspQryUserInit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///座席初始化应答
void CFtdcUserApiImpl::OnRtnUserInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnUserInitField RtnUserInit;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnUserInitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnUserInit);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnUserInitTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnUserInit, &CFTDRtnUserInitField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnUserInitTopic((CShfeFtdcRtnUserInitField *)&RtnUserInit);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///返回约状态切换数据
void CFtdcUserApiImpl::OnRspQryInstrumentStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryInstrumentStatusField RspQryInstrumentStatus;
	CShfeFtdcRspQryInstrumentStatusField *pRspQryInstrumentStatus = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryInstrumentStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryInstrumentStatus);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryInstrumentStatus = (CShfeFtdcRspQryInstrumentStatusField *)&RspQryInstrumentStatus;
			m_pSpi->OnRspQryInstrumentStatusTopic(pRspQryInstrumentStatus, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryInstrumentStatus == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryInstrumentStatusTopic(pRspQryInstrumentStatus, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅约状态切换数据
void CFtdcUserApiImpl::OnRtnInstrumentStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnInstrumentStatusField RtnInstrumentStatus;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnInstrumentStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnInstrumentStatus);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnInstrumentStatusTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnInstrumentStatus, &CFTDRtnInstrumentStatusField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnInstrumentStatusTopic((CShfeFtdcRtnInstrumentStatusField *)&RtnInstrumentStatus);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///返回合约交易节信息
void CFtdcUserApiImpl::OnRspQryCurrTradingSegmentAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryCurrTradingSegmentAttrField RspQryCurrTradingSegmentAttr;
	CShfeFtdcRspQryCurrTradingSegmentAttrField *pRspQryCurrTradingSegmentAttr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryCurrTradingSegmentAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryCurrTradingSegmentAttr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryCurrTradingSegmentAttr = (CShfeFtdcRspQryCurrTradingSegmentAttrField *)&RspQryCurrTradingSegmentAttr;
			m_pSpi->OnRspQryCurrTradingSegmentAttrTopic(pRspQryCurrTradingSegmentAttr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryCurrTradingSegmentAttr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryCurrTradingSegmentAttrTopic(pRspQryCurrTradingSegmentAttr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅合约交易节信息
void CFtdcUserApiImpl::OnRtnCurrTradingSegmentAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnCurrTradingSegmentAttrField RtnCurrTradingSegmentAttr;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnCurrTradingSegmentAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnCurrTradingSegmentAttr);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnCurrTradingSegmentAttrTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnCurrTradingSegmentAttr, &CFTDRtnCurrTradingSegmentAttrField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnCurrTradingSegmentAttrTopic((CShfeFtdcRtnCurrTradingSegmentAttrField *)&RtnCurrTradingSegmentAttr);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///交易系统登录信息
void CFtdcUserApiImpl::OnRspQryTradeUserLoginInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTradeUserLoginInfoField RspQryTradeUserLoginInfo;
	CShfeFtdcRspQryTradeUserLoginInfoField *pRspQryTradeUserLoginInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTradeUserLoginInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTradeUserLoginInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTradeUserLoginInfo = (CShfeFtdcRspQryTradeUserLoginInfoField *)&RspQryTradeUserLoginInfo;
			m_pSpi->OnRspQryTradeUserLoginInfoTopic(pRspQryTradeUserLoginInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryTradeUserLoginInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTradeUserLoginInfoTopic(pRspQryTradeUserLoginInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易系统登录信息
void CFtdcUserApiImpl::OnRtnTradeUserLoginInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnTradeUserLoginInfoField RtnTradeUserLoginInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnTradeUserLoginInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnTradeUserLoginInfo);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnTradeUserLoginInfoTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnTradeUserLoginInfo, &CFTDRtnTradeUserLoginInfoField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTradeUserLoginInfoTopic((CShfeFtdcRtnTradeUserLoginInfoField *)&RtnTradeUserLoginInfo);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///会员交易查询应答
void CFtdcUserApiImpl::OnRspQryPartTradeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryPartTradeField RspQryPartTrade;
	CShfeFtdcRspQryPartTradeField *pRspQryPartTrade = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryPartTradeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryPartTrade);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryPartTrade = (CShfeFtdcRspQryPartTradeField *)&RspQryPartTrade;
			m_pSpi->OnRspQryPartTradeTopic(pRspQryPartTrade, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryPartTrade == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPartTradeTopic(pRspQryPartTrade, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员席位交易状态
void CFtdcUserApiImpl::OnRspQryParticTradeOrderStatesTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryParticTradeOrderStatesField RspQryParticTradeOrderStates;
	CShfeFtdcRspQryParticTradeOrderStatesField *pRspQryParticTradeOrderStates = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryParticTradeOrderStatesField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryParticTradeOrderStates);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryParticTradeOrderStates = (CShfeFtdcRspQryParticTradeOrderStatesField *)&RspQryParticTradeOrderStates;
			m_pSpi->OnRspQryParticTradeOrderStatesTopic(pRspQryParticTradeOrderStates, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryParticTradeOrderStates == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryParticTradeOrderStatesTopic(pRspQryParticTradeOrderStates, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员席位交易状态
void CFtdcUserApiImpl::OnRtnParticTradeOrderStatesTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnParticTradeOrderStatesField RtnParticTradeOrderStates;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnParticTradeOrderStatesField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnParticTradeOrderStates);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnParticTradeOrderStatesTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnParticTradeOrderStates, &CFTDRtnParticTradeOrderStatesField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnParticTradeOrderStatesTopic((CShfeFtdcRtnParticTradeOrderStatesField *)&RtnParticTradeOrderStates);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///获得监控对象信息应答
void CFtdcUserApiImpl::OnRspQryMonitor2ObjectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonitor2ObjectField RspQryMonitor2Object;
	CShfeFtdcRspQryMonitor2ObjectField *pRspQryMonitor2Object = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonitor2ObjectField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonitor2Object);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonitor2Object = (CShfeFtdcRspQryMonitor2ObjectField *)&RspQryMonitor2Object;
			m_pSpi->OnRspQryMonitor2ObjectTopic(pRspQryMonitor2Object, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonitor2Object == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonitor2ObjectTopic(pRspQryMonitor2Object, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///获得监控对象信息应答
void CFtdcUserApiImpl::OnRtnMonitor2ObjectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonitor2ObjectField RtnMonitor2Object;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonitor2ObjectField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonitor2Object);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonitor2ObjectTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonitor2Object, &CFTDRtnMonitor2ObjectField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonitor2ObjectTopic((CShfeFtdcRtnMonitor2ObjectField *)&RtnMonitor2Object);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///主机环境信息应答
void CFtdcUserApiImpl::OnRspQryMonHostCommonEnvTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonHostCommonEnvField RspQryMonHostCommonEnv;
	CShfeFtdcRspQryMonHostCommonEnvField *pRspQryMonHostCommonEnv = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonHostCommonEnvField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonHostCommonEnv);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonHostCommonEnv = (CShfeFtdcRspQryMonHostCommonEnvField *)&RspQryMonHostCommonEnv;
			m_pSpi->OnRspQryMonHostCommonEnvTopic(pRspQryMonHostCommonEnv, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonHostCommonEnv == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonHostCommonEnvTopic(pRspQryMonHostCommonEnv, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///主机环境信息应答
void CFtdcUserApiImpl::OnRtnMonHostCommonEnvTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonHostCommonEnvField RtnMonHostCommonEnv;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonHostCommonEnvField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonHostCommonEnv);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonHostCommonEnvTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonHostCommonEnv, &CFTDRtnMonHostCommonEnvField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonHostCommonEnvTopic((CShfeFtdcRtnMonHostCommonEnvField *)&RtnMonHostCommonEnv);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///应答业务进程和主机关系
void CFtdcUserApiImpl::OnRspQryMonOidHostRationalTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonOidHostRationalField RspQryMonOidHostRational;
	CShfeFtdcRspQryMonOidHostRationalField *pRspQryMonOidHostRational = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonOidHostRationalField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonOidHostRational);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonOidHostRational = (CShfeFtdcRspQryMonOidHostRationalField *)&RspQryMonOidHostRational;
			m_pSpi->OnRspQryMonOidHostRationalTopic(pRspQryMonOidHostRational, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonOidHostRational == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonOidHostRationalTopic(pRspQryMonOidHostRational, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///推送业务进程和主机关系
void CFtdcUserApiImpl::OnRtnMonOidHostRationalTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonOidHostRationalField RtnMonOidHostRational;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonOidHostRationalField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonOidHostRational);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonOidHostRationalTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonOidHostRational, &CFTDRtnMonOidHostRationalField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonOidHostRationalTopic((CShfeFtdcRtnMonOidHostRationalField *)&RtnMonOidHostRational);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

///对象关系查询应答
void CFtdcUserApiImpl::OnRspQryMonOidRelationTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonOidRelationField RspQryMonOidRelation;
	CShfeFtdcRspQryMonOidRelationField *pRspQryMonOidRelation = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonOidRelationField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonOidRelation);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonOidRelation = (CShfeFtdcRspQryMonOidRelationField *)&RspQryMonOidRelation;
			m_pSpi->OnRspQryMonOidRelationTopic(pRspQryMonOidRelation, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
		
	}
	
	if (pRspQryMonOidRelation == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonOidRelationTopic(pRspQryMonOidRelation, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///对象关系查询应答
void CFtdcUserApiImpl::OnRtnMonOidRelationTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRtnMonOidRelationField RtnMonOidRelation;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonOidRelationField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonOidRelation);
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,OnRtnMonOidRelationTopic,", szTimeBuffer);
			FIELD_TO_STRING((char *)&RtnMonOidRelation, &CFTDRtnMonOidRelationField::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonOidRelationTopic((CShfeFtdcRtnMonOidRelationField *)&RtnMonOidRelation);
		}
		itor.Next();
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}


