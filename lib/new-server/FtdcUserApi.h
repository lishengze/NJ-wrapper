/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file FtdcUserApi.h
///@brief 定义了客户端接口
///@history 
///20060106	赵鸿昊		创建该文件
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
	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected(){};
	
	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	virtual void OnFrontDisconnected(int nReason){};
		
	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	virtual void OnHeartBeatWarning(int nTimeLapse){};
	
	///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
	///@param nTopicID 主题代码（如私有流、公共流、行情流等）
	///@param nSequenceNo 报文序号
	virtual void OnPackageStart(int nTopicID, int nSequenceNo){};
	
	///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
	///@param nTopicID 主题代码（如私有流、公共流、行情流等）
	///@param nSequenceNo 报文序号
	virtual void OnPackageEnd(int nTopicID, int nSequenceNo){};
	

	///错误应答
	virtual void OnRspError(CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户登录应答
	virtual void OnRspUserLogin(CShfeFtdcRspUserLoginField *pRspUserLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户退出应答
	virtual void OnRspUserLogout(CShfeFtdcRspUserLogoutField *pRspUserLogout, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单录入应答
	virtual void OnRspOrderInsert(CShfeFtdcInputOrderField *pInputOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单操作应答
	virtual void OnRspOrderAction(CShfeFtdcOrderActionField *pOrderAction, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报价录入应答
	virtual void OnRspQuoteInsert(CShfeFtdcInputQuoteField *pInputQuote, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报价操作应答
	virtual void OnRspQuoteAction(CShfeFtdcQuoteActionField *pQuoteAction, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///OTC报单录入应答
	virtual void OnRspOTCOrderInsert(CShfeFtdcOTCOrderField *pOTCOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户密码修改应答
	virtual void OnRspUserPasswordUpdate(CShfeFtdcUserPasswordUpdateField *pUserPasswordUpdate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///执行宣告录入应答
	virtual void OnRspExecOrderInsert(CShfeFtdcInputExecOrderField *pInputExecOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///执行宣告操作应答
	virtual void OnRspExecOrderAction(CShfeFtdcExecOrderActionField *pExecOrderAction, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///管理报单录入应答
	virtual void OnRspAdminOrderInsert(CShfeFtdcInputAdminOrderField *pInputAdminOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///非标组合报单录入应答
	virtual void OnRspCombOrderInsert(CShfeFtdcInputCombOrderField *pInputCombOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅主题应答
	virtual void OnRspSubscribeTopic(CShfeFtdcDisseminationField *pDissemination, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易所公告请求应答
	virtual void OnRspBulletin(CShfeFtdcBulletinField *pBulletin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易所公告信息应答
	virtual void OnRspInformation(CShfeFtdcInformationField *pInformation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约交易状态改变应答
	virtual void OnRspInstrumentStatusUpdate(CShfeFtdcInstrumentStatusField *pInstrumentStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///强制用户退出应答
	virtual void OnRspForceUserExit(CShfeFtdcForceUserExitField *pForceUserExit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户会话删除应答
	virtual void OnRspForceUserLogout(CShfeFtdcForceUserExitField *pForceUserExit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易所数据同步状态改变应答
	virtual void OnRspExchangeDataSyncStatusUpdate(CShfeFtdcExchangeDataSyncStatusField *pExchangeDataSyncStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///结算组数据同步状态改变应答
	virtual void OnRspSGDataSyncStatusUpdate(CShfeFtdcSGDataSyncStatusField *pSGDataSyncStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员资金查询应答
	virtual void OnRspQryPartAccount(CShfeFtdcRspPartAccountField *pRspPartAccount, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单查询应答
	virtual void OnRspQryOrder(CShfeFtdcOrderField *pOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报价查询应答
	virtual void OnRspQryQuote(CShfeFtdcQuoteField *pQuote, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///成交单查询应答
	virtual void OnRspQryTrade(CShfeFtdcTradeField *pTrade, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员客户查询应答
	virtual void OnRspQryClient(CShfeFtdcRspClientField *pRspClient, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员持仓查询应答
	virtual void OnRspQryPartPosition(CShfeFtdcRspPartPositionField *pRspPartPosition, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///客户持仓查询应答
	virtual void OnRspQryClientPosition(CShfeFtdcRspClientPositionField *pRspClientPosition, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约查询应答
	virtual void OnRspQryInstrument(CShfeFtdcRspInstrumentField *pRspInstrument, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约交易状态查询应答
	virtual void OnRspQryInstrumentStatus(CShfeFtdcInstrumentStatusField *pInstrumentStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///结算组状态查询应答
	virtual void OnRspQrySGDataSyncStatus(CShfeFtdcSGDataSyncStatusField *pSGDataSyncStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///保值额度应答
	virtual void OnRspQryHedgeVolume(CShfeFtdcHedgeVolumeField *pHedgeVolume, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///信用限额查询应答
	virtual void OnRspQryCreditLimit(CShfeFtdcCreditLimitField *pCreditLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///非标组合报单查询应答
	virtual void OnRspQryCombOrder(CShfeFtdcCombOrderField *pCombOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///执行宣告查询应答
	virtual void OnRspQryExecOrder(CShfeFtdcExecOrderField *pExecOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///普通行情查询应答
	virtual void OnRspQryMarketData(CShfeFtdcMarketDataField *pMarketData, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易所公告查询请求应答
	virtual void OnRspQryBulletin(CShfeFtdcBulletinField *pBulletin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主题查询应答
	virtual void OnRspQryTopic(CShfeFtdcDisseminationField *pDissemination, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户在线查询应答
	virtual void OnRspQryUserSession(CShfeFtdcUserSessionField *pUserSession, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户查询应答
	virtual void OnRspQryUser(CShfeFtdcUserField *pUser, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员查询应答
	virtual void OnRspQryParticipant(CShfeFtdcParticipantField *pParticipant, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约价位查询应答
	virtual void OnRspQryMBLMarketData(CShfeFtdcMBLMarketDataField *pMBLMarketData, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///信息查询应答
	virtual void OnRspQryInformation(CShfeFtdcInformationField *pInformation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///成交回报
	virtual void OnRtnTrade(CShfeFtdcTradeField *pTrade) {};

	///报单回报
	virtual void OnRtnOrder(CShfeFtdcOrderField *pOrder) {};

	///执行宣告回报
	virtual void OnRtnExecOrder(CShfeFtdcExecOrderField *pExecOrder) {};

	///报价回报
	virtual void OnRtnQuote(CShfeFtdcQuoteField *pQuote) {};

	///非标组合报单回报
	virtual void OnRtnCombOrder(CShfeFtdcCombOrderField *pCombOrder) {};

	///合约交易状态通知
	virtual void OnRtnInstrumentStatus(CShfeFtdcInstrumentStatusField *pInstrumentStatus) {};

	///增加合约通知
	virtual void OnRtnInsInstrument(CShfeFtdcInstrumentField *pInstrument) {};

	///删除合约通知
	virtual void OnRtnDelInstrument(CShfeFtdcInstrumentField *pInstrument) {};

	///增加合约单腿通知
	virtual void OnRtnInsCombinationLeg(CShfeFtdcCombinationLegField *pCombinationLeg) {};

	///删除合约单腿通知
	virtual void OnRtnDelCombinationLeg(CShfeFtdcCombinationLegField *pCombinationLeg) {};

	///别名定义通知
	virtual void OnRtnAliasDefine(CShfeFtdcAliasDefineField *pAliasDefine) {};

	///数据流回退通知
	virtual void OnRtnFlowMessageCancel(CShfeFtdcFlowMessageCancelField *pFlowMessageCancel) {};

	///公告通知
	virtual void OnRtnBulletin(CShfeFtdcBulletinField *pBulletin) {};

	///普通行情通知
	virtual void OnRtnMarketData(CShfeFtdcMarketDataField *pMarketData) {};

	///深度行情通知
	virtual void OnRtnDepthMarketData(CShfeFtdcDepthMarketDataField *pDepthMarketData) {};

	///管理报单通知
	virtual void OnRtnAdminOrder(CShfeFtdcAdminOrderField *pAdminOrder) {};

	///报单录入错误回报
	virtual void OnErrRtnOrderInsert(CShfeFtdcInputOrderField *pInputOrder, CShfeFtdcRspInfoField *pRspInfo) {};

	///报单操作错误回报
	virtual void OnErrRtnOrderAction(CShfeFtdcOrderActionField *pOrderAction, CShfeFtdcRspInfoField *pRspInfo) {};

	///报价录入错误回报
	virtual void OnErrRtnQuoteInsert(CShfeFtdcInputQuoteField *pInputQuote, CShfeFtdcRspInfoField *pRspInfo) {};

	///报价操作错误回报
	virtual void OnErrRtnQuoteAction(CShfeFtdcQuoteActionField *pQuoteAction, CShfeFtdcRspInfoField *pRspInfo) {};

	///执行宣告录入错误回报
	virtual void OnErrRtnExecOrderInsert(CShfeFtdcInputExecOrderField *pInputExecOrder, CShfeFtdcRspInfoField *pRspInfo) {};

	///执行宣告操作错误回报
	virtual void OnErrRtnExecOrderAction(CShfeFtdcExecOrderActionField *pExecOrderAction, CShfeFtdcRspInfoField *pRspInfo) {};

	///非标组合报单录入错误回报
	virtual void OnErrRtnCombOrderInsert(CShfeFtdcInputCombOrderField *pInputCombOrder, CShfeFtdcRspInfoField *pRspInfo) {};

	///汇率查询应答
	virtual void OnRspQryExchangeRate(CShfeFtdcRspExchangeRateField *pRspExchangeRate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///CPU应答
	virtual void OnRspQryTopCpuInfoTopic(CShfeFtdcRspQryTopCpuInfoField *pRspQryTopCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///CPU应答
	virtual void OnRtnTopCpuInfoTopic(CShfeFtdcRtnTopCpuInfoField *pRtnTopCpuInfo) {};

	///Mem应答
	virtual void OnRspQryTopMemInfoTopic(CShfeFtdcRspQryTopMemInfoField *pRspQryTopMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Mem应答
	virtual void OnRtnTopMemInfoTopic(CShfeFtdcRtnTopMemInfoField *pRtnTopMemInfo) {};

	///process应答
	virtual void OnRspQryTopProcessInfoTopic(CShfeFtdcRspQryTopProcessInfoField *pRspQryTopProcessInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///process应答
	virtual void OnRtnTopProcessInfoTopic(CShfeFtdcRtnTopProcessInfoField *pRtnTopProcessInfo) {};

	///filesystem应答
	virtual void OnRspQryFileSystemInfoTopic(CShfeFtdcRspQryFileSystemInfoField *pRspQryFileSystemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///filesystem应答
	virtual void OnRtnFileSystemInfoTopic(CShfeFtdcRtnFileSystemInfoField *pRtnFileSystemInfo) {};

	///network应答
	virtual void OnRspQryNetworkInfoTopic(CShfeFtdcRspQryNetworkInfoField *pRspQryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///network应答
	virtual void OnRtnNetworkInfoTopic(CShfeFtdcRtnNetworkInfoField *pRtnNetworkInfo) {};

	///客户端登录应答
	virtual void OnRspQryClientLoginTopic(CShfeFtdcRspQryClientLoginField *pRspQryClientLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///获得监控对象信息应答
	virtual void OnRspQryMonitorObjectTopic(CShfeFtdcRspQryMonitorObjectField *pRspQryMonitorObject, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///获得监控对象信息应答
	virtual void OnRtnMonitorObjectTopic(CShfeFtdcRtnMonitorObjectField *pRtnMonitorObject) {};

	///获得业务进程和主机的对应关系应答
	virtual void OnRspQryObjectRationalTopic(CShfeFtdcRspQryObjectRationalField *pRspQryObjectRational, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///获得业务进程和主机的对应关系应答
	virtual void OnRtnObjectRationalTopic(CShfeFtdcRtnObjectRationalField *pRtnObjectRational) {};

	///日志文件内容应答
	virtual void OnRspQrySyslogInfoTopic(CShfeFtdcRspQrySyslogInfoField *pRspQrySyslogInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///日志文件内容应答
	virtual void OnRtnSyslogInfoTopic(CShfeFtdcRtnSyslogInfoField *pRtnSyslogInfo) {};

	///监控内容订阅应答
	virtual void OnRspQrySubscriberTopic(CShfeFtdcRspQrySubscriberField *pRspQrySubscriber, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///对象关系查询应答
	virtual void OnRspQryOidRelationTopic(CShfeFtdcRspQryOidRelationField *pRspQryOidRelation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///对象关系查询应答
	virtual void OnRtnOidRelationTopic(CShfeFtdcRtnOidRelationField *pRtnOidRelation) {};

	///用户信息查询请求应答
	virtual void OnRspQryUserInfoTopic(CShfeFtdcRspQryUserInfoField *pRspQryUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户信息查询请求应答
	virtual void OnRtnUserInfoTopic(CShfeFtdcRtnUserInfoField *pRtnUserInfo) {};

	///在线用户信息查询请求应答
	virtual void OnRspQryOnlineUserInfoTopic(CShfeFtdcRspQryOnlineUserInfoField *pRspQryOnlineUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///在线用户信息查询请求应答
	virtual void OnRtnOnlineUserInfoTopic(CShfeFtdcRtnOnlineUserInfoField *pRtnOnlineUserInfo) {};

	///告警事件查询请求应答
	virtual void OnRspQryWarningEventTopic(CShfeFtdcRspQryWarningEventField *pRspQryWarningEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///告警事件查询请求应答
	virtual void OnRtnWarningEventTopic(CShfeFtdcRtnWarningEventField *pRtnWarningEvent) {};

	///CPU使用率查询请求应答
	virtual void OnRspQryCPUUsageTopic(CShfeFtdcRspQryCPUUsageField *pRspQryCPUUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///CPU使用率查询请求应答
	virtual void OnRtnCPUUsageTopic(CShfeFtdcRtnCPUUsageField *pRtnCPUUsage) {};

	///内存使用率查询请求应答
	virtual void OnRspQryMemoryUsageTopic(CShfeFtdcRspQryMemoryUsageField *pRspQryMemoryUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///内存使用率查询请求应答
	virtual void OnRtnMemoryUsageTopic(CShfeFtdcRtnMemoryUsageField *pRtnMemoryUsage) {};

	///硬盘使用率查询请求应答
	virtual void OnRspQryDiskUsageTopic(CShfeFtdcRspQryDiskUsageField *pRspQryDiskUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///硬盘使用率查询请求应答
	virtual void OnRtnDiskUsageTopic(CShfeFtdcRtnDiskUsageField *pRtnDiskUsage) {};

	///对象状态指标查询应答
	virtual void OnRspQryObjectAttrTopic(CShfeFtdcRspQryObjectAttrField *pRspQryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///对象状态指标查询应答
	virtual void OnRtnObjectAttrTopic(CShfeFtdcRtnObjectAttrField *pRtnObjectAttr) {};

	///历史对象状态指标查询应答
	virtual void OnRspQryHistoryObjectAttrTopic(CShfeFtdcRspQryHistoryObjectAttrField *pRspQryHistoryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///历史对象状态指标查询应答
	virtual void OnRtnHistoryObjectAttrTopic(CShfeFtdcRtnHistoryObjectAttrField *pRtnHistoryObjectAttr) {};

	///前置响应信息查询应答
	virtual void OnRspQryFrontInfoTopic(CShfeFtdcRspQryFrontInfoField *pRspQryFrontInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///前置响应信息查询应答
	virtual void OnRtnFrontInfoTopic(CShfeFtdcRtnFrontInfoField *pRtnFrontInfo) {};

	///用户登录应答
	virtual void OnRspQrySysUserLoginTopic(CShfeFtdcRspQrySysUserLoginField *pRspQrySysUserLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户登出应答
	virtual void OnRspQrySysUserLogoutTopic(CShfeFtdcRspQrySysUserLogoutField *pRspQrySysUserLogout, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户修改密码应答
	virtual void OnRspQrySysUserPasswordUpdateTopic(CShfeFtdcRspQrySysUserPasswordUpdateField *pRspQrySysUserPasswordUpdate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///注册用户应答
	virtual void OnRspQrySysUserRegisterTopic(CShfeFtdcRspQrySysUserRegisterField *pRspQrySysUserRegister, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///删除用户应答
	virtual void OnRspQrySysUserDeleteTopic(CShfeFtdcRspQrySysUserDeleteField *pRspQrySysUserDelete, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///客户初始化应答
	virtual void OnRspQryClientInitTopic(CShfeFtdcRspQryClientInitField *pRspQryClientInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///客户初始化应答
	virtual void OnRtnClientInitTopic(CShfeFtdcRtnClientInitField *pRtnClientInit) {};

	///交易日志查询应答
	virtual void OnRspQryTradeLogTopic(CShfeFtdcRspQryTradeLogField *pRspQryTradeLog, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易日志查询应答
	virtual void OnRtnTradeLogTopic(CShfeFtdcRtnTradeLogField *pRtnTradeLog) {};

	///交易峰值查询应答
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

	///HostConfig查询请求应答
	virtual void OnRspQryHostConfig(CShfeFtdcRspQryHostConfigField *pRspQryHostConfig, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///监控系统在线用户应答
	virtual void OnRspQryMonitorOnlineUser(CShfeFtdcRspQryMonitorOnlineUserField *pRspQryMonitorOnlineUser, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///监控系统时钟同步
	virtual void OnRtnSysTimeSyncTopic(CShfeFtdcRtnSysTimeSyncField *pRtnSysTimeSync) {};

	///数据中心切换通知
	virtual void OnRtnDataCenterChgTopic(CShfeFtdcRtnDataCenterChgField *pRtnDataCenterChg) {};

	///历史峰值查询应答
	virtual void OnRspQryHistoryTradePeakTopic(CShfeFtdcRspQryHistoryTradePeakField *pRspQryHistoryTradePeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///历史峰值查询应答
	virtual void OnRtnHistoryTradePeakTopic(CShfeFtdcRtnHistoryTradePeakField *pRtnHistoryTradePeak) {};

	///日志事件查询应答
	virtual void OnRspQrySyslogEventTopic(CShfeFtdcRspQrySyslogEventField *pRspQrySyslogEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///日志事件应答
	virtual void OnRtnSyslogEventTopic(CShfeFtdcRtnSyslogEventField *pRtnSyslogEvent) {};

	///交易日切换通知
	virtual void OnRspQryTradeDayChangeTopic(CShfeFtdcRspQryTradeDayChangeField *pRspQryTradeDayChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Web应用信息
	virtual void OnRspQryWebAppInfoTopic(CShfeFtdcRspQryWebAppInfoField *pRspQryWebAppInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Web应用信息
	virtual void OnRtnWebAppInfoTopic(CShfeFtdcRtnWebAppInfoField *pRtnWebAppInfo) {};

	///应用servlet信息
	virtual void OnRspQryServletInfoTopic(CShfeFtdcRspQryServletInfoField *pRspQryServletInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///应用servlet信息
	virtual void OnRtnServletInfoTopic(CShfeFtdcRtnServletInfoField *pRtnServletInfo) {};

	///文件信息
	virtual void OnRspQryFileInfoTopic(CShfeFtdcRspQryFileInfoField *pRspQryFileInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///文件信息
	virtual void OnRtnFileInfoTopic(CShfeFtdcRtnFileInfoField *pRtnFileInfo) {};

	///应用会话信息
	virtual void OnRspQrySessionInfoTopic(CShfeFtdcRspQrySessionInfoField *pRspQrySessionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///应用会话信息
	virtual void OnRtnSessionInfoTopic(CShfeFtdcRtnSessionInfoField *pRtnSessionInfo) {};

	///JDBC信息
	virtual void OnRspQryJDBCInfoTopic(CShfeFtdcRspQryJDBCInfoField *pRspQryJDBCInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///JDBC信息
	virtual void OnRtnJDBCInfoTopic(CShfeFtdcRtnJDBCInfoField *pRtnJDBCInfo) {};

	///线程信息
	virtual void OnRspQryThreadInfoTopic(CShfeFtdcRspQryThreadInfoField *pRspQryThreadInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///线程信息
	virtual void OnRtnThreadInfoTopic(CShfeFtdcRtnThreadInfoField *pRtnThreadInfo) {};

	///虚拟机信息
	virtual void OnRspQryVMInfoTopic(CShfeFtdcRspQryVMInfoField *pRspQryVMInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///虚拟机信息
	virtual void OnRtnVMInfoTopic(CShfeFtdcRtnVMInfoField *pRtnVMInfo) {};

	///系统属性信息
	virtual void OnRspQryPropertyInfoTopic(CShfeFtdcRspQryPropertyInfoField *pRspQryPropertyInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///系统属性信息
	virtual void OnRtnPropertyInfoTopic(CShfeFtdcRtnPropertyInfoField *pRtnPropertyInfo) {};

	///系统内存池信息
	virtual void OnRspQryMemPoolInfoTopic(CShfeFtdcRspQryMemPoolInfoField *pRspQryMemPoolInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///系统内存池信息
	virtual void OnRtnMemPoolInfoTopic(CShfeFtdcRtnMemPoolInfoField *pRtnMemPoolInfo) {};

	///文件内容信息
	virtual void OnRspQryFileContentInfoTopic(CShfeFtdcRspQryFileContentInfoField *pRspQryFileContentInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///文件内容信息
	virtual void OnRtnFileContentInfoTopic(CShfeFtdcRtnFileContentInfoField *pRtnFileContentInfo) {};

	///连接信息
	virtual void OnRspQryConnectionInfoTopic(CShfeFtdcRspQryConnectionInfoField *pRspQryConnectionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///连接信息
	virtual void OnRtnConnectionInfoTopic(CShfeFtdcRtnConnectionInfoField *pRtnConnectionInfo) {};

	///连接器信息
	virtual void OnRspQryConnectorInfoTopic(CShfeFtdcRspQryConnectorInfoField *pRspQryConnectorInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///连接器信息
	virtual void OnRtnConnectorInfoTopic(CShfeFtdcRtnConnectorInfoField *pRtnConnectorInfo) {};

	///数据库查询应答
	virtual void OnRspQryDBQueryTopic(CShfeFtdcRspQryDBQueryField *pRspQryDBQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///数据库查询应答
	virtual void OnRtnDBQueryTopic(CShfeFtdcRtnDBQueryField *pRtnDBQuery) {};

	///通用返回应答
	virtual void OnRspQryGeneralFieldTopic(CShfeFtdcSysGeneralFieldField *pSysGeneralField, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///通用返回应答
	virtual void OnRtnGeneralFieldTopic(CShfeFtdcSysGeneralFieldField *pSysGeneralField) {};

	///文件传输应答
	virtual void OnRspQryGetFileTopic(CShfeFtdcRspQryGetFileField *pRspQryGetFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///告警明细
	virtual void OnRspQryWarningQueryTopic(CShfeFtdcRspQryWarningQueryField *pRspQryWarningQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///告警明细
	virtual void OnRtnWarningQueryTopic(CShfeFtdcRtnWarningQueryField *pRtnWarningQuery) {};

	///HostConfig订阅应答
	virtual void OnRtnHostConfig(CShfeFtdcRtnHostConfigField *pRtnHostConfig) {};

	///告警激活变更
	virtual void OnRspQryWarningActiveChange(CShfeFtdcRspQryWarningActiveChangeField *pRspQryWarningActiveChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///告警激活变更
	virtual void OnRtnWarningActiveChange(CShfeFtdcRtnWarningActiveChangeField *pRtnWarningActiveChange) {};

	///通用操作
	virtual void OnRspQryGeneralOperateTopic(CShfeFtdcRspQryGeneralOperateField *pRspQryGeneralOperate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///通用操作
	virtual void OnRtnGeneralOperateTopic(CShfeFtdcRtnGeneralOperateField *pRtnGeneralOperate) {};

	///网络设备连接关系
	virtual void OnRspQryNetDeviceLinkedTopic(CShfeFtdcRspQryNetDeviceLinkedField *pRspQryNetDeviceLinked, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///网络设备连接关系
	virtual void OnRtnNetDeviceLinkedTopic(CShfeFtdcRtnNetDeviceLinkedField *pRtnNetDeviceLinked) {};

	///交易系统登录信息
	virtual void OnRspQryTradeUserLoginStatTopic(CShfeFtdcRspQryTradeUserLoginStatField *pRspQryTradeUserLoginStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易系统前置报单响应信息
	virtual void OnRspQryTradeFrontOrderRttStatTopic(CShfeFtdcRspQryTradeFrontOrderRttStatField *pRspQryTradeFrontOrderRttStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易系统前置报单响应信息
	virtual void OnRtnTradeFrontOrderRttStatTopic(CShfeFtdcRtnTradeFrontOrderRttStatField *pRtnTradeFrontOrderRttStat) {};

	///系统路由信息
	virtual void OnRspQryRouterInfoTopic(CShfeFtdcRspQryRouterInfoField *pRspQryRouterInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///系统路由信息
	virtual void OnRtnRouterInfoTopic(CShfeFtdcRtnRouterInfoField *pRtnRouterInfo) {};

	///磁盘I/O信息
	virtual void OnRspQryDiskIOTopic(CShfeFtdcRspQryDiskIOField *pRspQryDiskIO, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///磁盘I/O信息
	virtual void OnRtnDiskIOTopic(CShfeFtdcRtnDiskIOField *pRtnDiskIO) {};

	///系统状态信息
	virtual void OnRspQryStatInfoTopic(CShfeFtdcRspQryStatInfoField *pRspQryStatInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///系统状态信息
	virtual void OnRtnStatInfoTopic(CShfeFtdcRtnStatInfoField *pRtnStatInfo) {};

	///交易系统前置报单分布区间
	virtual void OnRspQryTradeOrderRttCutLineTopic(CShfeFtdcRspQryTradeOrderRttCutLineField *pRspQryTradeOrderRttCutLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易系统前置报单分布区间
	virtual void OnRtnTradeOrderRttCutLineTopic(CShfeFtdcRtnTradeOrderRttCutLineField *pRtnTradeOrderRttCutLine) {};

	///会员客户信息
	virtual void OnRspQryClientInfoTopic(CShfeFtdcRspQryClientInfoField *pRspQryClientInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员客户信息
	virtual void OnRtnClientInfoTopic(CShfeFtdcRtnClientInfoField *pRtnClientInfo) {};

	///应答事件描述
	virtual void OnRspQryEventDescriptionTopic(CShfeFtdcRspQryEventDescriptionField *pRspQryEventDescription, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅事件描述
	virtual void OnRtnEventDescriptionTopic(CShfeFtdcRtnEventDescriptionField *pRtnEventDescription) {};

	///应答前置唯一ID信息
	virtual void OnRspQryFrontUniqueIDTopic(CShfeFtdcRspQryFrontUniqueIDField *pRspQryFrontUniqueID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅前置唯一ID信息
	virtual void OnRtnFrontUniqueIDTopic(CShfeFtdcRtnFrontUniqueIDField *pRtnFrontUniqueID) {};

	///会员线路地址变更回应
	virtual void OnRspQryNetPartyLinkAddrChangeTopic(CShfeFtdcRspQryNetPartyLinkAddrChangeField *pRspQryNetPartyLinkAddrChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅会员线路地址变更信息
	virtual void OnRtnNetPartyLinkAddrChangeTopic(CShfeFtdcRtnNetPartyLinkAddrChangeField *pRtnNetPartyLinkAddrChange) {};

	///应答已删除会员列表信息
	virtual void OnRspQryNetDelPartyLinkInfoTopic(CShfeFtdcRspQryNetDelPartyLinkInfoField *pRspQryNetDelPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅已删除会员列表信息
	virtual void OnRtnNetDelPartyLinkInfoTopic(CShfeFtdcRtnNetDelPartyLinkInfoField *pRtnNetDelPartyLinkInfo) {};

	///返回网络性能排序
	virtual void OnRspQryPerformanceTopTopic(CShfeFtdcRspQryPerformanceTopField *pRspQryPerformanceTop, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅网络性能排序
	virtual void OnRtnPerformanceTopTopic(CShfeFtdcRtnPerformanceTopField *pRtnPerformanceTop) {};

	///网络大区划分应答
	virtual void OnRspQryNetAreaTopic(CShfeFtdcRspQryNetAreaField *pRspQryNetArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///网络大区划分应答
	virtual void OnRtnNetAreaTopic(CShfeFtdcRtnNetAreaField *pRtnNetArea) {};

	///网络子区应答
	virtual void OnRspQryNetSubAreaTopic(CShfeFtdcRspQryNetSubAreaField *pRspQryNetSubArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///网络子区应答
	virtual void OnRtnNetSubAreaTopic(CShfeFtdcRtnNetSubAreaField *pRtnNetSubArea) {};

	///网络子区IP应答
	virtual void OnRspQryNetSubAreaIPTopic(CShfeFtdcRspQryNetSubAreaIPField *pRspQryNetSubAreaIP, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///网络子区IP应答
	virtual void OnRtnNetSubAreaIPTopic(CShfeFtdcRtnNetSubAreaIPField *pRtnNetSubAreaIP) {};

	///网络设备
	virtual void OnRspQryNetDeviceTopic(CShfeFtdcRspQryNetDeviceField *pRspQryNetDevice, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///网络设备
	virtual void OnRtnNetDeviceTopic(CShfeFtdcRtnNetDeviceField *pRtnNetDevice) {};

	///网络设备探测请求应答
	virtual void OnRspQryNetDeviceDetectTopic(CShfeFtdcRspQryNetDeviceDetectField *pRspQryNetDeviceDetect, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///大楼
	virtual void OnRspQryNetBuildingTopic(CShfeFtdcRspQryNetBuildingField *pRspQryNetBuilding, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///大楼
	virtual void OnRtnNetBuildingTopic(CShfeFtdcRtnNetBuildingField *pRtnNetBuilding) {};

	///机房
	virtual void OnRspQryNetRoomTopic(CShfeFtdcRspQryNetRoomField *pRspQryNetRoom, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///机房
	virtual void OnRtnNetRoomTopic(CShfeFtdcRtnNetRoomField *pRtnNetRoom) {};

	///机柜
	virtual void OnRspQryNetCabinetsTopic(CShfeFtdcRspQryNetCabinetsField *pRspQryNetCabinets, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///机柜
	virtual void OnRtnNetCabinetsTopic(CShfeFtdcRtnNetCabinetsField *pRtnNetCabinets) {};

	///OID
	virtual void OnRspQryNetOIDTopic(CShfeFtdcRspQryNetOIDField *pRspQryNetOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///OID
	virtual void OnRtnNetOIDTopic(CShfeFtdcRtnNetOIDField *pRtnNetOID) {};

	///时间策略
	virtual void OnRspQryNetTimePolicyTopic(CShfeFtdcRspQryNetTimePolicyField *pRspQryNetTimePolicy, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///时间策略
	virtual void OnRtnNetTimePolicyTopic(CShfeFtdcRtnNetTimePolicyField *pRtnNetTimePolicy) {};

	///采集任务
	virtual void OnRspQryNetGatherTaskTopic(CShfeFtdcRspQryNetGatherTaskField *pRspQryNetGatherTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///采集任务
	virtual void OnRtnNetGatherTaskTopic(CShfeFtdcRtnNetGatherTaskField *pRtnNetGatherTask) {};

	///设备变更
	virtual void OnRspQryNetDeviceChgTopic(CShfeFtdcRspQryNetDeviceChgField *pRspQryNetDeviceChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设备变更
	virtual void OnRtnNetDeviceChgTopic(CShfeFtdcRtnNetDeviceChgField *pRtnNetDeviceChg) {};

	///常用设备型号
	virtual void OnRspQryNetDeviceTypeTopic(CShfeFtdcRspQryNetDeviceTypeField *pRspQryNetDeviceType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///常用设备型号
	virtual void OnRtnNetDeviceTypeTopic(CShfeFtdcRtnNetDeviceTypeField *pRtnNetDeviceType) {};

	///常用设备类别
	virtual void OnRspQryNetDeviceCategoryTopic(CShfeFtdcRspQryNetDeviceCategoryField *pRspQryNetDeviceCategory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///常用设备类别
	virtual void OnRtnNetDeviceCategoryTopic(CShfeFtdcRtnNetDeviceCategoryField *pRtnNetDeviceCategory) {};

	///设备厂商
	virtual void OnRspQryNetManufactoryTopic(CShfeFtdcRspQryNetManufactoryField *pRspQryNetManufactory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设备厂商
	virtual void OnRtnNetManufactoryTopic(CShfeFtdcRtnNetManufactoryField *pRtnNetManufactory) {};

	///设备共同体
	virtual void OnRspQryNetCommunityTopic(CShfeFtdcRspQryNetCommunityField *pRspQryNetCommunity, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设备共同体
	virtual void OnRtnNetCommunityTopic(CShfeFtdcRtnNetCommunityField *pRtnNetCommunity) {};

	///端口类型
	virtual void OnRspQryNetPortTypeTopic(CShfeFtdcRspQryNetPortTypeField *pRspQryNetPortType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///端口类型
	virtual void OnRtnNetPortTypeTopic(CShfeFtdcRtnNetPortTypeField *pRtnNetPortType) {};

	///会员接入地点
	virtual void OnRspQryNetPartAccessSpotTopic(CShfeFtdcRspQryNetPartAccessSpotField *pRspQryNetPartAccessSpot, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员接入地点
	virtual void OnRtnNetPartAccessSpotTopic(CShfeFtdcRtnNetPartAccessSpotField *pRtnNetPartAccessSpot) {};

	///端口
	virtual void OnRspQryNetInterfaceTopic(CShfeFtdcRspQryNetInterfaceField *pRspQryNetInterface, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///端口
	virtual void OnRtnNetInterfaceTopic(CShfeFtdcRtnNetInterfaceField *pRtnNetInterface) {};

	///GeneralOID
	virtual void OnRspQryNetGeneralOIDTopic(CShfeFtdcRspQryNetGeneralOIDField *pRspQryNetGeneralOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///GeneralOID
	virtual void OnRtnNetGeneralOIDTopic(CShfeFtdcRtnNetGeneralOIDField *pRtnNetGeneralOID) {};

	///监控对象类别
	virtual void OnRspQryNetMonitorTypeTopic(CShfeFtdcRspQryNetMonitorTypeField *pRspQryNetMonitorType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///监控对象类别
	virtual void OnRtnNetMonitorTypeTopic(CShfeFtdcRtnNetMonitorTypeField *pRtnNetMonitorType) {};

	///指标统表
	virtual void OnRspQryNetMonitorAttrScopeTopic(CShfeFtdcRspQryNetMonitorAttrScopeField *pRspQryNetMonitorAttrScope, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///指标统表
	virtual void OnRtnNetMonitorAttrScopeTopic(CShfeFtdcRtnNetMonitorAttrScopeField *pRtnNetMonitorAttrScope) {};

	///监控指标表
	virtual void OnRspQryNetMonitorAttrTypeTopic(CShfeFtdcRspQryNetMonitorAttrTypeField *pRspQryNetMonitorAttrType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///监控指标表
	virtual void OnRtnNetMonitorAttrTypeTopic(CShfeFtdcRtnNetMonitorAttrTypeField *pRtnNetMonitorAttrType) {};

	///监控对象指标表
	virtual void OnRspQryNetMonitorObjectAttrTopic(CShfeFtdcRspQryNetMonitorObjectAttrField *pRspQryNetMonitorObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///监控对象指标表
	virtual void OnRtnNetMonitorObjectAttrTopic(CShfeFtdcRtnNetMonitorObjectAttrField *pRtnNetMonitorObjectAttr) {};

	///职能区
	virtual void OnRspQryNetFuncAreaTopic(CShfeFtdcRspQryNetFuncAreaField *pRspQryNetFuncArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///职能区
	virtual void OnRtnNetFuncAreaTopic(CShfeFtdcRtnNetFuncAreaField *pRtnNetFuncArea) {};

	///监控指令表
	virtual void OnRspQryNetMonitorCommandTypeTopic(CShfeFtdcRspQryNetMonitorCommandTypeField *pRspQryNetMonitorCommandType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///监控指令表
	virtual void OnRtnNetMonitorCommandTypeTopic(CShfeFtdcRtnNetMonitorCommandTypeField *pRtnNetMonitorCommandType) {};

	///动作族表
	virtual void OnRspQryNetMonitorActionGroupTopic(CShfeFtdcRspQryNetMonitorActionGroupField *pRspQryNetMonitorActionGroup, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///动作族表
	virtual void OnRtnNetMonitorActionGroupTopic(CShfeFtdcRtnNetMonitorActionGroupField *pRtnNetMonitorActionGroup) {};

	///设备对象组表
	virtual void OnRspQryNetMonitorDeviceGroupTopic(CShfeFtdcRspQryNetMonitorDeviceGroupField *pRspQryNetMonitorDeviceGroup, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设备对象组表
	virtual void OnRtnNetMonitorDeviceGroupTopic(CShfeFtdcRtnNetMonitorDeviceGroupField *pRtnNetMonitorDeviceGroup) {};

	///任务信息表
	virtual void OnRspQryNetMonitorTaskInfoTopic(CShfeFtdcRspQryNetMonitorTaskInfoField *pRspQryNetMonitorTaskInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///任务信息表
	virtual void OnRtnNetMonitorTaskInfoTopic(CShfeFtdcRtnNetMonitorTaskInfoField *pRtnNetMonitorTaskInfo) {};

	///任务结果表
	virtual void OnRspQryNetMonitorTaskResultTopic(CShfeFtdcRspQryNetMonitorTaskResultField *pRspQryNetMonitorTaskResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///任务结果表
	virtual void OnRtnNetMonitorTaskResultTopic(CShfeFtdcRtnNetMonitorTaskResultField *pRtnNetMonitorTaskResult) {};

	///任务对象集
	virtual void OnRspQryNetMonitorTaskObjectSetTopic(CShfeFtdcRspQryNetMonitorTaskObjectSetField *pRspQryNetMonitorTaskObjectSet, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///任务对象集
	virtual void OnRtnNetMonitorTaskObjectSetTopic(CShfeFtdcRtnNetMonitorTaskObjectSetField *pRtnNetMonitorTaskObjectSet) {};

	///会员链路信息表
	virtual void OnRspQryNetPartyLinkInfoTopic(CShfeFtdcRspQryNetPartyLinkInfoField *pRspQryNetPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员链路信息表
	virtual void OnRtnNetPartyLinkInfoTopic(CShfeFtdcRtnNetPartyLinkInfoField *pRtnNetPartyLinkInfo) {};

	///监控动作指标对照表
	virtual void OnRspQryNetMonitorActionAttrTopic(CShfeFtdcRspQryNetMonitorActionAttrField *pRspQryNetMonitorActionAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///监控动作指标对照表
	virtual void OnRtnNetMonitorActionAttrTopic(CShfeFtdcRtnNetMonitorActionAttrField *pRtnNetMonitorActionAttr) {};

	///模块
	virtual void OnRspQryNetModuleTopic(CShfeFtdcRspQryNetModuleField *pRspQryNetModule, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///模块
	virtual void OnRtnNetModuleTopic(CShfeFtdcRtnNetModuleField *pRtnNetModule) {};

	///告警表达式信息表
	virtual void OnRspQryNetEventExprTopic(CShfeFtdcRspQryNetEventExprField *pRspQryNetEventExpr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///告警表达式信息表
	virtual void OnRtnNetEventExprTopic(CShfeFtdcRtnNetEventExprField *pRtnNetEventExpr) {};

	///事件类型
	virtual void OnRspQryNetEventTypeTopic(CShfeFtdcRspQryNetEventTypeField *pRspQryNetEventType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///事件类型
	virtual void OnRtnNetEventTypeTopic(CShfeFtdcRtnNetEventTypeField *pRtnNetEventType) {};

	///事件子类型
	virtual void OnRspQryNetSubEventTypeTopic(CShfeFtdcRspQryNetSubEventTypeField *pRspQryNetSubEventType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///事件子类型
	virtual void OnRtnNetSubEventTypeTopic(CShfeFtdcRtnNetSubEventTypeField *pRtnNetSubEventType) {};

	///事件级别
	virtual void OnRspQryNetEventLevelTopic(CShfeFtdcRspQryNetEventLevelField *pRspQryNetEventLevel, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///事件级别
	virtual void OnRtnNetEventLevelTopic(CShfeFtdcRtnNetEventLevelField *pRtnNetEventLevel) {};

	///任务结果状态表
	virtual void OnRspQryNetMonitorTaskStatusResultTopic(CShfeFtdcRspQryNetMonitorTaskStatusResultField *pRspQryNetMonitorTaskStatusResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///任务结果状态表
	virtual void OnRtnNetMonitorTaskStatusResultTopic(CShfeFtdcRtnNetMonitorTaskStatusResultField *pRtnNetMonitorTaskStatusResult) {};

	///配置服务对登陆的响应
	virtual void OnRspConfigLoginTopic(CShfeFtdcRspQryConfigLoginField *pRspQryConfigLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///对当前登录配置的服务角色的响应
	virtual void OnRspServerTypeTopic(CShfeFtdcRspServerTypeField *pRspServerType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设备配置表
	virtual void OnRspQryNetCfgFileTopic(CShfeFtdcRspQryNetCfgFileField *pRspQryNetCfgFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设备配置表
	virtual void OnRtnNetCfgFileTopic(CShfeFtdcRtnNetCfgFileField *pRtnNetCfgFile) {};

	///任务结果规则分析表
	virtual void OnRspQryNetMonitorDeviceTaskTopic(CShfeFtdcRspQryNetMonitorDeviceTaskField *pRspQryNetMonitorDeviceTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///任务结果规则分析表
	virtual void OnRtnNetMonitorDeviceTaskTopic(CShfeFtdcRtnNetMonitorDeviceTaskField *pRtnNetMonitorDeviceTask) {};

	///任务指令指标集表
	virtual void OnRspQryNetMonitorTaskInstAttrsTopic(CShfeFtdcRspQryNetMonitorTaskInstAttrsField *pRspQryNetMonitorTaskInstAttrs, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///任务指令指标集表
	virtual void OnRtnNetMonitorTaskInstAttrsTopic(CShfeFtdcRtnNetMonitorTaskInstAttrsField *pRtnNetMonitorTaskInstAttrs) {};

	///文件通用操作
	virtual void OnRspQryFileGeneralOperTopic(CShfeFtdcRspQryFileGeneralOperField *pRspQryFileGeneralOper, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///文件通用操作
	virtual void OnRtnFileGeneralOperTopic(CShfeFtdcRtnFileGeneralOperField *pRtnFileGeneralOper) {};

	///基线表
	virtual void OnRspQryNetBaseLineTopic(CShfeFtdcRspQryNetBaseLineField *pRspQryNetBaseLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///基线表
	virtual void OnRtnNetBaseLineTopic(CShfeFtdcRtnNetBaseLineField *pRtnNetBaseLine) {};

	///基线任务表
	virtual void OnRspQryNetBaseLineTaskTopic(CShfeFtdcRspQryNetBaseLineTaskField *pRspQryNetBaseLineTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///基线任务表
	virtual void OnRtnNetBaseLineTaskTopic(CShfeFtdcRtnNetBaseLineTaskField *pRtnNetBaseLineTask) {};

	///基线结果表
	virtual void OnRspQryNetBaseLineResultTopic(CShfeFtdcRspQryNetBaseLineResultField *pRspQryNetBaseLineResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///基线结果表
	virtual void OnRtnNetBaseLineResultTopic(CShfeFtdcRtnNetBaseLineResultField *pRtnNetBaseLineResult) {};

	///会员链路状态信息表
	virtual void OnRspQryNetPartyLinkStatusInfoTopic(CShfeFtdcRspQryNetPartyLinkStatusInfoField *pRspQryNetPartyLinkStatusInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员链路状态信息表
	virtual void OnRtnNetPartyLinkStatusInfoTopic(CShfeFtdcRtnNetPartyLinkStatusInfoField *pRtnNetPartyLinkStatusInfo) {};

	///会员SDH线路明细表
	virtual void OnRspQryNetMemberSDHLineInfoTopic(CShfeFtdcRspQryNetMemberSDHLineInfoField *pRspQryNetMemberSDHLineInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员SDH线路明细表
	virtual void OnRtnNetMemberSDHLineInfoTopic(CShfeFtdcRtnNetMemberSDHLineInfoField *pRtnNetMemberSDHLineInfo) {};

	///DDN链路信息表
	virtual void OnRspQryNetDDNLinkInfoTopic(CShfeFtdcRspQryNetDDNLinkInfoField *pRspQryNetDDNLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///DDN链路信息表
	virtual void OnRtnNetDDNLinkInfoTopic(CShfeFtdcRtnNetDDNLinkInfoField *pRtnNetDDNLinkInfo) {};

	///非会员线路使用信息
	virtual void OnRspQryNetPseudMemberLinkInfoTopic(CShfeFtdcRspQryNetPseudMemberLinkInfoField *pRspQryNetPseudMemberLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///非会员线路使用信息
	virtual void OnRtnNetPseudMemberLinkInfoTopic(CShfeFtdcRtnNetPseudMemberLinkInfoField *pRtnNetPseudMemberLinkInfo) {};

	///远端设备信息
	virtual void OnRspQryOuterDeviceInfTopic(CShfeFtdcRspQryOuterDeviceInfField *pRspQryOuterDeviceInf, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///远端设备信息
	virtual void OnRtnNetOuterDeviceInfTopic(CShfeFtdcRtnNetOuterDeviceInfField *pRtnNetOuterDeviceInf) {};

	///本地ping结果
	virtual void OnRspQryNetLocalPingResultInfoTopic(CShfeFtdcRspQryNetLocalPingResultInfoField *pRspQryNetLocalPingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///本地ping结果
	virtual void OnRtnNetLocalPingResultInfoTopic(CShfeFtdcRtnNetLocalPingResultInfoField *pRtnNetLocalPingResultInfo) {};

	///远程ping结果
	virtual void OnRspQryNetRomotePingResultInfoTopic(CShfeFtdcRspQryNetRomotePingResultInfoField *pRspQryNetRomotePingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///远程ping结果
	virtual void OnRtnNetRomotePingResultInfoTopic(CShfeFtdcRtnNetRomotePingResultInfoField *pRtnNetRomotePingResultInfo) {};

	///进程信息数据库专用
	virtual void OnRtnMonitorTopProcessInfo(CShfeFtdcRtnMonitorTopProcessInfoField *pRtnMonitorTopProcessInfo) {};

	///系统内部级联关系
	virtual void OnRspQrySysInternalTopologyTopic(CShfeFtdcRspQrySysInternalTopologyField *pRspQrySysInternalTopology, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///系统内部级联关系
	virtual void OnRtnSysInternalTopologyTopic(CShfeFtdcRtnSysInternalTopologyField *pRtnSysInternalTopology) {};

	///返回会员链路费用表
	virtual void OnRspQryMemberLinkCostTopic(CShfeFtdcRspQryMemberLinkCostField *pRspQryMemberLinkCost, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅会员链路费用表
	virtual void OnRtnMemberLinkCostTopic(CShfeFtdcRtnMemberLinkCostField *pRtnMemberLinkCost) {};

	///返回会员链路月租表
	virtual void OnRspQryNetPartylinkMonthlyRentTopic(CShfeFtdcRspQryNetPartylinkMonthlyRentField *pRspQryNetPartylinkMonthlyRent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅会员链路月租表
	virtual void OnRtnNetPartylinkMonthlyRentTopic(CShfeFtdcRtnNetPartylinkMonthlyRentField *pRtnNetPartylinkMonthlyRent) {};

	///返回非会员链路表信息
	virtual void OnRspQryNetNonPartyLinkInfoTopic(CShfeFtdcRspQryNetNonPartyLinkInfoField *pRspQryNetNonPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅非会员链路表信息
	virtual void OnRtnNetNonPartyLinkInfoTopic(CShfeFtdcRtnNetNonPartyLinkInfoField *pRtnNetNonPartyLinkInfo) {};

	///应答配置信息
	virtual void OnRspQryMonConfigInfo(CShfeFtdcRspQryMonConfigInfoField *pRspQryMonConfigInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///应答配置信息
	virtual void OnRtnMonConfigInfo(CShfeFtdcRtnMonConfigInfoField *pRtnMonConfigInfo) {};

	///通知监控日信息
	virtual void OnRtnMonitorDayInfo(CShfeFtdcMonitorDayInfoField *pMonitorDayInfo) {};

	///通知交易日信息
	virtual void OnRtnTradingDayInfo(CShfeFtdcTradingDayInfoField *pTradingDayInfo) {};

	///监控阶段结束
	virtual void OnRtnSectionFinish(CShfeFtdcMonitorSectionField *pMonitorSection) {};

	///监控阶段切换
	virtual void OnRtnSectionChange(CShfeFtdcMonitorSectionField *pMonitorSection) {};

	///服务连接响应
	virtual void OnRspMonServiceConnect(CShfeFtdcRspMonServiceConnectField *pRspMonServiceConnect, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Proxy或探针名称配置
	virtual void OnRtnMonProxyConfig(CShfeFtdcRtnMonProxyConfigField *pRtnMonProxyConfig) {};

	///服务的当前状态响应
	virtual void OnRspQryMonServiceStatus(CShfeFtdcRspQryMonServiceStatusField *pRspQryMonServiceStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///服务的当前状态推送
	virtual void OnRtnMonServiceStatus(CShfeFtdcRtnMonServiceStatusField *pRtnMonServiceStatus) {};

	///当前数据中心角色
	virtual void OnRtnMonDataCenterRole(CShfeFtdcRtnMonDataCenterRoleField *pRtnMonDataCenterRole) {};

	///探针任务配置查询响应
	virtual void OnRspQryMonProbeTask(CShfeFtdcRspQryMonProbeTaskField *pRspQryMonProbeTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///探针任务配置推送
	virtual void OnRtnMonProbeTask(CShfeFtdcRtnMonProbeTaskField *pRtnMonProbeTask) {};

	///监控系统指标查询应答
	virtual void OnRspQryMonObjectAttr(CShfeFtdcRspQryMonObjectAttrField *pRspQryMonObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///监控系统指标查询推送
	virtual void OnRtnMonObjectAttr(CShfeFtdcRtnMonObjectAttrField *pRtnMonObjectAttr) {};

	///监控系统Syslog事件查询应答
	virtual void OnRspQryMonSyslogEvent(CShfeFtdcRspQryMonSyslogEventField *pRspQryMonSyslogEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///监控系统Syslog事件查询推送
	virtual void OnRtnMonSyslogEvent(CShfeFtdcRtnMonSyslogEventField *pRtnMonSyslogEvent) {};

	///文件读取偏移量查询应答
	virtual void OnRspQryMonFileOffset(CShfeFtdcRspQryMonFileOffsetField *pRspQryMonFileOffset, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///文件读取偏移量查询推送
	virtual void OnRtnMonFileOffset(CShfeFtdcRtnMonFileOffsetField *pRtnMonFileOffset) {};

	///文件内容查询应答
	virtual void OnRspQryMonFileContent(CShfeFtdcRspQryMonFileContentField *pRspQryMonFileContent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///文件内容通告
	virtual void OnRtnMonFileContent(CShfeFtdcRtnMonFileContentField *pRtnMonFileContent) {};

	///主机基础环境信息应答
	virtual void OnRspQryMonHostBasicEnv(CShfeFtdcRspQryMonHostBasicEnvField *pRspQryMonHostBasicEnv, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主机基础环境信息应答
	virtual void OnRtnMonHostBasicEnv(CShfeFtdcRtnMonHostBasicEnvField *pRtnMonHostBasicEnv) {};

	///主机基础网络信息应答
	virtual void OnRspQryMonHostNetworkEnv(CShfeFtdcRspQryMonHostNetworkEnvField *pRspQryMonHostNetworkEnv, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主机基础网络信息通告
	virtual void OnRtnMonHostNetworkEnv(CShfeFtdcRtnMonHostNetworkEnvField *pRtnMonHostNetworkEnv) {};

	///主机文件系统信息应答
	virtual void OnRspQryMonHostFileSysEnv(CShfeFtdcRspQryMonHostFileSysEnvField *pRspQryMonHostFileSysEnv, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主机文件系统信息通告
	virtual void OnRtnMonHostFileSysEnv(CShfeFtdcRtnMonHostFileSysEnvField *pRtnMonHostFileSysEnv) {};

	///主机交换分区信息应答
	virtual void OnRspQryMonHostSwapEnv(CShfeFtdcRspQryMonHostSwapEnvField *pRspQryMonHostSwapEnv, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主机交换分区信息通告
	virtual void OnRtnMonHostSwapEnv(CShfeFtdcRtnMonHostSwapEnvField *pRtnMonHostSwapEnv) {};

	///主机的CPU信息指标信息应答
	virtual void OnRspQryMonHostCPUAttr(CShfeFtdcRspQryMonHostCPUAttrField *pRspQryMonHostCPUAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主机的CPU信息指标信息
	virtual void OnRtnMonHostCPUAttr(CShfeFtdcRtnMonHostCPUAttrField *pRtnMonHostCPUAttr) {};

	///主机的Memory使用信息应答
	virtual void OnRspQryMonHostMemAttr(CShfeFtdcRspQryMonHostMemAttrField *pRspQryMonHostMemAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主机的Memory使用信息
	virtual void OnRtnMonHostMemAttr(CShfeFtdcRtnMonHostMemAttrField *pRtnMonHostMemAttr) {};

	///主机的FileSystem使用信息应答
	virtual void OnRspQryMonHostFileSystemAttr(CShfeFtdcRspQryMonHostFileSystemAttrField *pRspQryMonHostFileSystemAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主机的FileSystem使用信息
	virtual void OnRtnMonHostFileSystemAttr(CShfeFtdcRtnMonHostFileSystemAttrField *pRtnMonHostFileSystemAttr) {};

	///主机的用户信息应答
	virtual void OnRspQryMonHostUserInfo(CShfeFtdcRspQryMonHostUserInfoField *pRspQryMonHostUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主机的用户信息
	virtual void OnRtnMonHostUserInfo(CShfeFtdcRtnMonHostUserInfoField *pRtnMonHostUserInfo) {};

	///主机的在线用户信息应答
	virtual void OnRspQryMonHostOnlineUserInfo(CShfeFtdcRspQryMonHostOnlineUserInfoField *pRspQryMonHostOnlineUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主机的在线用户信息
	virtual void OnRtnMonHostOnlineUserInfo(CShfeFtdcRtnMonHostOnlineUserInfoField *pRtnMonHostOnlineUserInfo) {};

	///主机的network使用信息应答
	virtual void OnRspQryMonHostNetworkAttr(CShfeFtdcRspQryMonHostNetworkAttrField *pRspQryMonHostNetworkAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主机的network使用信息
	virtual void OnRtnMonHostNetworkAttr(CShfeFtdcRtnMonHostNetworkAttrField *pRtnMonHostNetworkAttr) {};

	///主机的系统状态信息应答
	virtual void OnRspQryMonHostStatInfo(CShfeFtdcRspQryMonHostStatInfoField *pRspQryMonHostStatInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主机的系统状态信息
	virtual void OnRtnMonHostStatInfo(CShfeFtdcRtnMonHostStatInfoField *pRtnMonHostStatInfo) {};

	///主机的磁盘IO信息应答
	virtual void OnRspQryMonHostDiskIOAttr(CShfeFtdcRspQryMonHostDiskIOAttrField *pRspQryMonHostDiskIOAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主机的磁盘IO信息
	virtual void OnRtnMonHostDiskIOAttr(CShfeFtdcRtnMonHostDiskIOAttrField *pRtnMonHostDiskIOAttr) {};

	///主机的路由信息应答
	virtual void OnRspQryMonHostRouterInfo(CShfeFtdcRspQryMonHostRouterInfoField *pRspQryMonHostRouterInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主机的路由信息
	virtual void OnRtnMonHostRouterInfo(CShfeFtdcRtnMonHostRouterInfoField *pRtnMonHostRouterInfo) {};

	///主机的进程信息应答
	virtual void OnRspQryMonHostProcessInfo(CShfeFtdcRspQryMonHostProcessInfoField *pRspQryMonHostProcessInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主机的进程信息
	virtual void OnRtnMonHostProcessInfo(CShfeFtdcRtnMonHostProcessInfoField *pRtnMonHostProcessInfo) {};

	///数据库采集的推送报文，包括了SP，DBLog，DBAttr
	virtual void OnRtnMonDBQuery(CShfeFtdcRtnMonDBQueryField *pRtnMonDBQuery) {};

	///响应客户端临时SP查询请求
	virtual void OnRspQryMonSPQuery(CShfeFtdcRtnMonDBQueryField *pRtnMonDBQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///服务版本信息响应
	virtual void OnRspServiceVersion(CShfeFtdcRspServiceVersionField *pRspServiceVersion, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///服务应用程序响应
	virtual void OnRspServiceProgram(CShfeFtdcRspServiceProgramField *pRspServiceProgram, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///升级服务获取状态响应
	virtual void OnRspUpdateState(CShfeFtdcRspUpdateStateField *pRspUpdateState, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅请求应答
	virtual void OnRspSubscribe(CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///通知目标服务文件已成功接收
	virtual void OnRspFileSendSuccess(CShfeFtdcRspFileSendSuccessField *pRspFileSendSuccess, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用于通知目标服务文件已发送成功
	virtual void OnRtnFileSendSuccess(CShfeFtdcRtnFileSendSuccessField *pRtnFileSendSuccess) {};

	///tomcat信息应答
	virtual void OnRspQryMonTomcatInfo(CShfeFtdcRspQryMonTomcatInfoField *pRspQryMonTomcatInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///tomcat信息推送
	virtual void OnRtnMonTomcatInfo(CShfeFtdcRtnMonTomcatInfoField *pRtnMonTomcatInfo) {};

	///Web应用信息
	virtual void OnRspQryMonWebAppInfo(CShfeFtdcRspQryMonWebAppInfoField *pRspQryMonWebAppInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Web应用信息
	virtual void OnRtnMonWebAppInfo(CShfeFtdcRtnMonWebAppInfoField *pRtnMonWebAppInfo) {};

	///应用servlet信息
	virtual void OnRspQryMonServletInfo(CShfeFtdcRspQryMonServletInfoField *pRspQryMonServletInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///应用servlet信息
	virtual void OnRtnMonServletInfo(CShfeFtdcRtnMonServletInfoField *pRtnMonServletInfo) {};

	///文件信息
	virtual void OnRspQryMonFileInfo(CShfeFtdcRspQryMonFileInfoField *pRspQryMonFileInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///文件信息
	virtual void OnRtnMonFileInfo(CShfeFtdcRtnMonFileInfoField *pRtnMonFileInfo) {};

	///应用会话信息应答
	virtual void OnRspQryMonSessionInfo(CShfeFtdcRspQryMonSessionInfoField *pRspQryMonSessionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///应用会话信息推送
	virtual void OnRtnMonSessionInfo(CShfeFtdcRtnMonSessionInfoField *pRtnMonSessionInfo) {};

	///JDBC信息
	virtual void OnRspQryMonJDBCInfo(CShfeFtdcRspQryMonJDBCInfoField *pRspQryMonJDBCInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///JDBC信息
	virtual void OnRtnMonJDBCInfo(CShfeFtdcRtnMonJDBCInfoField *pRtnMonJDBCInfo) {};

	///线程信息
	virtual void OnRspQryMonThreadInfo(CShfeFtdcRspQryMonThreadInfoField *pRspQryMonThreadInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///线程信息
	virtual void OnRtnMonThreadInfo(CShfeFtdcRtnMonThreadInfoField *pRtnMonThreadInfo) {};

	///虚拟机信息
	virtual void OnRspQryMonVMInfo(CShfeFtdcRspQryMonVMInfoField *pRspQryMonVMInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///虚拟机信息
	virtual void OnRtnMonVMInfo(CShfeFtdcRtnMonVMInfoField *pRtnMonVMInfo) {};

	///系统属性信息
	virtual void OnRspQryMonPropertyInfo(CShfeFtdcRspQryMonPropertyInfoField *pRspQryMonPropertyInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///系统属性信息
	virtual void OnRtnMonPropertyInfo(CShfeFtdcRtnMonPropertyInfoField *pRtnMonPropertyInfo) {};

	///系统内存池信息
	virtual void OnRspQryMonMemPoolInfo(CShfeFtdcRspQryMonMemPoolInfoField *pRspQryMonMemPoolInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///系统内存池信息
	virtual void OnRtnMonMemPoolInfo(CShfeFtdcRtnMonMemPoolInfoField *pRtnMonMemPoolInfo) {};

	///连接信息
	virtual void OnRspQryMonConnectionInfo(CShfeFtdcRspQryMonConnectionInfoField *pRspQryMonConnectionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///连接信息
	virtual void OnRtnMonConnectionInfo(CShfeFtdcRtnMonConnectionInfoField *pRtnMonConnectionInfo) {};

	///无效报单查询应答
	virtual void OnRspQryInvalidateOrderTopic(CShfeFtdcRspQryInvalidateOrderField *pRspQryInvalidateOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///无效报单查询应答
	virtual void OnRtnInvalidateOrderTopic(CShfeFtdcRtnInvalidateOrderField *pRtnInvalidateOrder) {};

	///报单状态查询应答
	virtual void OnRspQryOrderStatusTopic(CShfeFtdcRspQryOrderStatusField *pRspQryOrderStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单状态查询应答
	virtual void OnRtnOrderStatusTopic(CShfeFtdcRtnOrderStatusField *pRtnOrderStatus) {};

	///报单成交查询应答
	virtual void OnRspQryBargainOrderTopic(CShfeFtdcRspQryBargainOrderField *pRspQryBargainOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单成交查询应答
	virtual void OnRtnBargainOrderTopic(CShfeFtdcRtnBargainOrderField *pRtnBargainOrder) {};

	///合约基本属性查询应答
	virtual void OnRspQryInstPropertyTopic(CShfeFtdcRspQryInstPropertyField *pRspQryInstProperty, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约基本属性查询应答
	virtual void OnRtnInstPropertyTopic(CShfeFtdcRtnInstPropertyField *pRtnInstProperty) {};

	///合约保证金率查询应答
	virtual void OnRspQryMarginRateTopic(CShfeFtdcRspQryMarginRateField *pRspQryMarginRate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约保证金率查询应答
	virtual void OnRtnMarginRateTopic(CShfeFtdcRtnMarginRateField *pRtnMarginRate) {};

	///合约涨跌停板查询应答
	virtual void OnRspQryPriceLimitTopic(CShfeFtdcRspQryPriceLimitField *pRspQryPriceLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约涨跌停板查询应答
	virtual void OnRtnPriceLimitTopic(CShfeFtdcRtnPriceLimitField *pRtnPriceLimit) {};

	///会员限仓查询应答
	virtual void OnRspQryPartPosiLimitTopic(CShfeFtdcRspQryPartPosiLimitField *pRspQryPartPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员限仓查询应答
	virtual void OnRtnPartPosiLimitTopic(CShfeFtdcRtnPartPosiLimitField *pRtnPartPosiLimit) {};

	///客户限仓查询应答
	virtual void OnRspQryClientPosiLimitTopic(CShfeFtdcRspQryClientPosiLimitField *pRspQryClientPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///客户限仓查询应答
	virtual void OnRtnClientPosiLimitTopic(CShfeFtdcRtnClientPosiLimitField *pRtnClientPosiLimit) {};

	///特殊客户限仓查询应答
	virtual void OnRspQrySpecialPosiLimitTopic(CShfeFtdcRspQrySpecialPosiLimitField *pRspQrySpecialPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///特殊客户限仓查询应答
	virtual void OnRtnSpecialPosiLimitTopic(CShfeFtdcRtnSpecialPosiLimitField *pRtnSpecialPosiLimit) {};

	///账户出入金查询应答
	virtual void OnRspQryTransactionChgTopic(CShfeFtdcRspQryTransactionChgField *pRspQryTransactionChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///账户出入金查询应答
	virtual void OnRtnTransactionChgTopic(CShfeFtdcRtnTransactionChgField *pRtnTransactionChg) {};

	///客户数据变动查询应答
	virtual void OnRspQryClientChgTopic(CShfeFtdcRspQryClientChgField *pRspQryClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///客户数据变动查询应答
	virtual void OnRtnClientChgTopic(CShfeFtdcRtnClientChgField *pRtnClientChg) {};

	///会员客户对照变动查询应答
	virtual void OnRspQryPartClientChgTopic(CShfeFtdcRspQryPartClientChgField *pRspQryPartClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员客户对照变动查询应答
	virtual void OnRtnPartClientChgTopic(CShfeFtdcRtnPartClientChgField *pRtnPartClientChg) {};

	///限仓数据变动查询应答
	virtual void OnRspQryPosiLimitChgTopic(CShfeFtdcRspQryPosiLimitChgField *pRspQryPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///限仓数据变动查询应答
	virtual void OnRtnPosiLimitChgTopic(CShfeFtdcRtnPosiLimitChgField *pRtnPosiLimitChg) {};

	///保值额度变动查询应答
	virtual void OnRspQryHedgeDetailChgTopic(CShfeFtdcRspQryHedgeDetailChgField *pRspQryHedgeDetailChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///保值额度变动查询应答
	virtual void OnRtnHedgeDetailChgTopic(CShfeFtdcRtnHedgeDetailChgField *pRtnHedgeDetailChg) {};

	///会员变动查询应答
	virtual void OnRspQryParticipantChgTopic(CShfeFtdcRspQryParticipantChgField *pRspQryParticipantChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员变动查询应答
	virtual void OnRtnParticipantChgTopic(CShfeFtdcRtnParticipantChgField *pRtnParticipantChg) {};

	///保证金率变动查询应答
	virtual void OnRspQryMarginRateChgTopic(CShfeFtdcRspQryMarginRateChgField *pRspQryMarginRateChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///保证金率变动查询应答
	virtual void OnRtnMarginRateChgTopic(CShfeFtdcRtnMarginRateChgField *pRtnMarginRateChg) {};

	///IP地址变动查询应答
	virtual void OnRspQryUserIpChgTopic(CShfeFtdcRspQryUserIpChgField *pRspQryUserIpChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///IP地址变动查询应答
	virtual void OnRtnUserIpChgTopic(CShfeFtdcRtnUserIpChgField *pRtnUserIpChg) {};

	///限仓数据变动查询应答
	virtual void OnRspQryClientPosiLimitChgTopic(CShfeFtdcRspQryClientPosiLimitChgField *pRspQryClientPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///限仓数据变动查询应答
	virtual void OnRtnClientPosiLimitChgTopic(CShfeFtdcRtnClientPosiLimitChgField *pRtnClientPosiLimitChg) {};

	///限仓数据变动查询应答
	virtual void OnRspQrySpecPosiLimitChgTopic(CShfeFtdcRspQrySpecPosiLimitChgField *pRspQrySpecPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///限仓数据变动查询应答
	virtual void OnRtnSpecPosiLimitChgTopic(CShfeFtdcRtnSpecPosiLimitChgField *pRtnSpecPosiLimitChg) {};

	///交易系统前置统计应答
	virtual void OnRspQryFrontStatTopic(CShfeFtdcRspQryFrontStatField *pRspQryFrontStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员初始化应答
	virtual void OnRspQryParticipantInitTopic(CShfeFtdcRspQryParticipantInitField *pRspQryParticipantInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员初始化应答
	virtual void OnRtnParticipantInitTopic(CShfeFtdcRtnParticipantInitField *pRtnParticipantInit) {};

	///座席初始化应答
	virtual void OnRspQryUserInitTopic(CShfeFtdcRspQryUserInitField *pRspQryUserInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///座席初始化应答
	virtual void OnRtnUserInitTopic(CShfeFtdcRtnUserInitField *pRtnUserInit) {};

	///返回约状态切换数据
	virtual void OnRspQryInstrumentStatusTopic(CShfeFtdcRspQryInstrumentStatusField *pRspQryInstrumentStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅约状态切换数据
	virtual void OnRtnInstrumentStatusTopic(CShfeFtdcRtnInstrumentStatusField *pRtnInstrumentStatus) {};

	///返回合约交易节信息
	virtual void OnRspQryCurrTradingSegmentAttrTopic(CShfeFtdcRspQryCurrTradingSegmentAttrField *pRspQryCurrTradingSegmentAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅合约交易节信息
	virtual void OnRtnCurrTradingSegmentAttrTopic(CShfeFtdcRtnCurrTradingSegmentAttrField *pRtnCurrTradingSegmentAttr) {};

	///交易系统登录信息
	virtual void OnRspQryTradeUserLoginInfoTopic(CShfeFtdcRspQryTradeUserLoginInfoField *pRspQryTradeUserLoginInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易系统登录信息
	virtual void OnRtnTradeUserLoginInfoTopic(CShfeFtdcRtnTradeUserLoginInfoField *pRtnTradeUserLoginInfo) {};

	///会员交易查询应答
	virtual void OnRspQryPartTradeTopic(CShfeFtdcRspQryPartTradeField *pRspQryPartTrade, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员席位交易状态
	virtual void OnRspQryParticTradeOrderStatesTopic(CShfeFtdcRspQryParticTradeOrderStatesField *pRspQryParticTradeOrderStates, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员席位交易状态
	virtual void OnRtnParticTradeOrderStatesTopic(CShfeFtdcRtnParticTradeOrderStatesField *pRtnParticTradeOrderStates) {};

	///获得监控对象信息应答
	virtual void OnRspQryMonitor2ObjectTopic(CShfeFtdcRspQryMonitor2ObjectField *pRspQryMonitor2Object, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///获得监控对象信息应答
	virtual void OnRtnMonitor2ObjectTopic(CShfeFtdcRtnMonitor2ObjectField *pRtnMonitor2Object) {};

	///主机环境信息应答
	virtual void OnRspQryMonHostCommonEnvTopic(CShfeFtdcRspQryMonHostCommonEnvField *pRspQryMonHostCommonEnv, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主机环境信息应答
	virtual void OnRtnMonHostCommonEnvTopic(CShfeFtdcRtnMonHostCommonEnvField *pRtnMonHostCommonEnv) {};

	///应答业务进程和主机关系
	virtual void OnRspQryMonOidHostRationalTopic(CShfeFtdcRspQryMonOidHostRationalField *pRspQryMonOidHostRational, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///推送业务进程和主机关系
	virtual void OnRtnMonOidHostRationalTopic(CShfeFtdcRtnMonOidHostRationalField *pRtnMonOidHostRational) {};

	///对象关系查询应答
	virtual void OnRspQryMonOidRelationTopic(CShfeFtdcRspQryMonOidRelationField *pRspQryMonOidRelation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///对象关系查询应答
	virtual void OnRtnMonOidRelationTopic(CShfeFtdcRtnMonOidRelationField *pRtnMonOidRelation) {};
};

class USER_API_EXPORT CShfeFtdcUserApi
{
public:
	///创建UserApi
	///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
	///@param pszUserApiType UserAPI类型
	///@return 创建出的UserApi
	static CShfeFtdcUserApi *CreateFtdcUserApi(const char *pszFlowPath = "",
											const char *pszUserApiType = "");
	
	///获取系统版本号
	///@param nMajorVersion 主版本号
	///@param nMinorVersion 子版本号
	///@return 系统标识字符串
	static const char *GetVersion(int &nMajorVersion, int &nMinorVersion);
	
	///删除接口对象本身
	///@remark 不再使用本接口对象时,调用该函数删除接口对象
	virtual void Release() = 0;
	
	///初始化
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	virtual void Init() = 0;
	
	///等待接口线程结束运行
	///@return 线程退出代码
	virtual int Join() = 0;
	
	///获取当前交易日
	///@retrun 获取到的交易日
	///@remark 只有登录成功后,才能得到正确的交易日
	virtual const char *GetTradingDay() = 0;
	
	///注册前置机网络地址
	///@param pszFrontAddress：前置机网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	
	///注册名字服务器网络地址
	///@param pszNsAddress：名字服务器网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
	///@remark RegisterFront优先于RegisterNameServer
	virtual void RegisterNameServer(char *pszNsAddress) = 0;
	
	///注册回调接口
	///@param pSpi 派生自回调接口类的实例
	virtual void RegisterSpi(CShfeFtdcUserSpi *pSpi) = 0;
	
	///加载证书
	///@param pszCertFileName 用户证书文件名
	///@param pszKeyFileName 用户私钥文件名
	///@param pszCaFileName 可信任CA证书文件名
	///@param pszKeyFilePassword 用户私钥文件密码
	///@return 0 操作成功
	///@return -1 可信任CA证书载入失败
	///@return -2 用户证书载入失败
	///@return -3 用户私钥载入失败	
	///@return -4 用户证书校验失败
	virtual int RegisterCertificateFile(const char *pszCertFileName, const char *pszKeyFileName, 
		const char *pszCaFileName, const char *pszKeyFilePassword) = 0;
	
	///订阅市场行情。
	///@param nTopicID 市场行情主题  
	///@param nResumeType 市场行情重传方式  
	///        TERT_RESTART:从本交易日开始重传
	///        TERT_RESUME:从上次收到的续传
	///        TERT_QUICK:先传送当前行情快照,再传送登录后市场行情的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	virtual void SubscribeMarketDataTopic(int nTopicID, TE_RESUME_TYPE nResumeType) = 0;

	///订阅私有流。
	///@param nResumeType 私有流重传方式  
	///        TERT_RESTART:从本交易日开始重传
	///        TERT_RESUME:从上次收到的续传
	///        TERT_QUICK:只传送登录后私有流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	virtual void SubscribePrivateTopic(TE_RESUME_TYPE nResumeType) = 0;
	
	///订阅公共流。
	///@param nResumeType 公共流重传方式  
	///        TERT_RESTART:从本交易日开始重传
	///        TERT_RESUME:从上次收到的续传
	///        TERT_QUICK:只传送登录后公共流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
	virtual void SubscribePublicTopic(TE_RESUME_TYPE nResumeType) = 0;
	
	///订阅交易员流。
	///@param nResumeType 交易员流重传方式  
	///        TERT_RESTART:从本交易日开始重传
	///        TERT_RESUME:从上次收到的续传
	///        TERT_QUICK:只传送登录后交易员流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到交易员流的数据。
	virtual void SubscribeUserTopic(TE_RESUME_TYPE nResumeType) = 0;
	
	///设置心跳超时时间。
	///@param timeout 心跳超时时间(秒)  
	virtual void SetHeartbeatTimeout(unsigned int timeout) = 0;
	
	///打开请求日志文件
	///@param pszReqLogFileName 请求日志文件名  
	///@return 0 操作成功
	///@return -1 打开日志文件失败
	virtual int OpenRequestLog(const char *pszReqLogFileName) = 0;

	///打开应答日志文件
	///@param pszRspLogFileName 应答日志文件名  
	///@return 0 操作成功
	///@return -1 打开日志文件失败
	virtual int OpenResponseLog(const char *pszRspLogFileName) = 0;
	
	///用户登录请求
	virtual int ReqUserLogin(CShfeFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;

	///用户退出请求
	virtual int ReqUserLogout(CShfeFtdcReqUserLogoutField *pReqUserLogout, int nRequestID) = 0;

	///报单录入请求
	virtual int ReqOrderInsert(CShfeFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	///报单操作请求
	virtual int ReqOrderAction(CShfeFtdcOrderActionField *pOrderAction, int nRequestID) = 0;

	///报价录入请求
	virtual int ReqQuoteInsert(CShfeFtdcInputQuoteField *pInputQuote, int nRequestID) = 0;

	///报价操作请求
	virtual int ReqQuoteAction(CShfeFtdcQuoteActionField *pQuoteAction, int nRequestID) = 0;

	///OTC报单录入请求
	virtual int ReqOTCOrderInsert(CShfeFtdcOTCOrderField *pOTCOrder, int nRequestID) = 0;

	///用户密码修改请求
	virtual int ReqUserPasswordUpdate(CShfeFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

	///执行宣告录入请求
	virtual int ReqExecOrderInsert(CShfeFtdcInputExecOrderField *pInputExecOrder, int nRequestID) = 0;

	///执行宣告操作请求
	virtual int ReqExecOrderAction(CShfeFtdcExecOrderActionField *pExecOrderAction, int nRequestID) = 0;

	///管理报单录入请求
	virtual int ReqAdminOrderInsert(CShfeFtdcInputAdminOrderField *pInputAdminOrder, int nRequestID) = 0;

	///非标组合报单录入请求
	virtual int ReqCombOrderInsert(CShfeFtdcInputCombOrderField *pInputCombOrder, int nRequestID) = 0;

	///订阅主题请求
	virtual int ReqSubscribeTopic(CShfeFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///交易所公告请求
	virtual int ReqBulletin(CShfeFtdcBulletinField *pBulletin, int nRequestID) = 0;

	///交易所信息请求
	virtual int ReqInformation(CShfeFtdcInformationField *pInformation, int nRequestID) = 0;

	///合约交易状态改变请求
	virtual int ReqInstrumentStatusUpdate(CShfeFtdcInstrumentStatusField *pInstrumentStatus, int nRequestID) = 0;

	///强制用户退出请求
	virtual int ReqForceUserExit(CShfeFtdcForceUserExitField *pForceUserExit, int nRequestID) = 0;

	///用户会话删除请求
	virtual int ReqForceUserLogout(CShfeFtdcForceUserExitField *pForceUserExit, int nRequestID) = 0;

	///交易所数据同步状态改变请求
	virtual int ReqExchangeDataSyncStatusUpdate(CShfeFtdcExchangeDataSyncStatusField *pExchangeDataSyncStatus, int nRequestID) = 0;

	///结算组数据同步状态改变请求
	virtual int ReqSGDataSyncStatusUpdate(CShfeFtdcSGDataSyncStatusField *pSGDataSyncStatus, int nRequestID) = 0;

	///会员资金查询请求
	virtual int ReqQryPartAccount(CShfeFtdcQryPartAccountField *pQryPartAccount, int nRequestID) = 0;

	///报单查询请求
	virtual int ReqQryOrder(CShfeFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///报价查询请求
	virtual int ReqQryQuote(CShfeFtdcQryQuoteField *pQryQuote, int nRequestID) = 0;

	///成交单查询请求
	virtual int ReqQryTrade(CShfeFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///会员客户查询请求
	virtual int ReqQryClient(CShfeFtdcQryClientField *pQryClient, int nRequestID) = 0;

	///会员持仓查询请求
	virtual int ReqQryPartPosition(CShfeFtdcQryPartPositionField *pQryPartPosition, int nRequestID) = 0;

	///客户持仓查询请求
	virtual int ReqQryClientPosition(CShfeFtdcQryClientPositionField *pQryClientPosition, int nRequestID) = 0;

	///合约查询请求
	virtual int ReqQryInstrument(CShfeFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///合约交易状态查询请求
	virtual int ReqQryInstrumentStatus(CShfeFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID) = 0;

	///结算组状态查询请求
	virtual int ReqQrySGDataSyncStatus(CShfeFtdcQrySGDataSyncStatusField *pQrySGDataSyncStatus, int nRequestID) = 0;

	///保值额度查询
	virtual int ReqQryHedgeVolume(CShfeFtdcQryHedgeVolumeField *pQryHedgeVolume, int nRequestID) = 0;

	///信用限额查询请求
	virtual int ReqQryCreditLimit(CShfeFtdcQryCreditLimitField *pQryCreditLimit, int nRequestID) = 0;

	///非标组合报单查询请求
	virtual int ReqQryCombOrder(CShfeFtdcQryCombOrderField *pQryCombOrder, int nRequestID) = 0;

	///执行宣告查询请求
	virtual int ReqQryExecOrder(CShfeFtdcQryExecOrderField *pQryExecOrder, int nRequestID) = 0;

	///普通行情查询请求
	virtual int ReqQryMarketData(CShfeFtdcQryMarketDataField *pQryMarketData, int nRequestID) = 0;

	///交易所公告查询请求
	virtual int ReqQryBulletin(CShfeFtdcQryBulletinField *pQryBulletin, int nRequestID) = 0;

	///主题查询请求
	virtual int ReqQryTopic(CShfeFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///用户在线查询请求
	virtual int ReqQryUserSession(CShfeFtdcQryUserSessionField *pQryUserSession, int nRequestID) = 0;

	///用户查询请求
	virtual int ReqQryUser(CShfeFtdcQryUserField *pQryUser, int nRequestID) = 0;

	///会员查询请求
	virtual int ReqQryParticipant(CShfeFtdcQryParticipantField *pQryParticipant, int nRequestID) = 0;

	///合约价位查询
	virtual int ReqQryMBLMarketData(CShfeFtdcQryMBLMarketDataField *pQryMBLMarketData, int nRequestID) = 0;

	///信息查询
	virtual int ReqQryInformation(CShfeFtdcQryInformationField *pQryInformation, int nRequestID) = 0;

	///客户持仓查询请求
	virtual int ReqQryClientPositionV1(CShfeFtdcQryClientPositionV1Field *pQryClientPositionV1, int nRequestID) = 0;

	///汇率查询请求
	virtual int ReqQryExchangeRate(CShfeFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID) = 0;

	///CPU查询
	virtual int ReqQryTopCpuInfoTopic(CShfeFtdcReqQryTopCpuInfoField *pReqQryTopCpuInfo, int nRequestID) = 0;

	///Mem查询
	virtual int ReqQryTopMemInfoTopic(CShfeFtdcReqQryTopMemInfoField *pReqQryTopMemInfo, int nRequestID) = 0;

	///process查询
	virtual int ReqQryTopProcessInfoTopic(CShfeFtdcReqQryTopProcessInfoField *pReqQryTopProcessInfo, int nRequestID) = 0;

	///filesystem查询
	virtual int ReqQryFileSystemInfoTopic(CShfeFtdcReqQryFileSystemInfoField *pReqQryFileSystemInfo, int nRequestID) = 0;

	///network查询
	virtual int ReqQryNetworkInfoTopic(CShfeFtdcReqQryNetworkInfoField *pReqQryNetworkInfo, int nRequestID) = 0;

	///主机环境信息查询
	virtual int ReqQryHostEnvTopic(CShfeFtdcReqQryHostEnvField *pReqQryHostEnv, int nRequestID) = 0;

	///客户端登录查询
	virtual int ReqQryClientLoginTopic(CShfeFtdcReqQryClientLoginField *pReqQryClientLogin, int nRequestID) = 0;

	///获得监控对象信息查询
	virtual int ReqQryMonitorObjectTopic(CShfeFtdcReqQryMonitorObjectField *pReqQryMonitorObject, int nRequestID) = 0;

	///获得业务进程和主机的对应关系查询
	virtual int ReqQryObjectRationalTopic(CShfeFtdcReqQryObjectRationalField *pReqQryObjectRational, int nRequestID) = 0;

	///日志文件内容查询
	virtual int ReqQrySyslogInfoTopic(CShfeFtdcReqQrySyslogInfoField *pReqQrySyslogInfo, int nRequestID) = 0;

	///监控内容订阅请求
	virtual int ReqQrySubscriberTopic(CShfeFtdcReqQrySubscriberField *pReqQrySubscriber, int nRequestID) = 0;

	///对象关系查询
	virtual int ReqQryOidRelationTopic(CShfeFtdcReqQryOidRelationField *pReqQryOidRelation, int nRequestID) = 0;

	///用户信息查询请求
	virtual int ReqQryUserInfoTopic(CShfeFtdcReqQryUserInfoField *pReqQryUserInfo, int nRequestID) = 0;

	///在线用户信息查询请求
	virtual int ReqQryOnlineUserInfoTopic(CShfeFtdcReqQryOnlineUserInfoField *pReqQryOnlineUserInfo, int nRequestID) = 0;

	///告警事件查询请求
	virtual int ReqQryWarningEventTopic(CShfeFtdcReqQryWarningEventField *pReqQryWarningEvent, int nRequestID) = 0;

	///CPU使用率查询请求
	virtual int ReqQryCPUUsageTopic(CShfeFtdcReqQryCPUUsageField *pReqQryCPUUsage, int nRequestID) = 0;

	///内存使用率查询请求
	virtual int ReqQryMemoryUsageTopic(CShfeFtdcReqQryMemoryUsageField *pReqQryMemoryUsage, int nRequestID) = 0;

	///硬盘使用率查询请求
	virtual int ReqQryDiskUsageTopic(CShfeFtdcReqQryDiskUsageField *pReqQryDiskUsage, int nRequestID) = 0;

	///对象状态指标查询
	virtual int ReqQryObjectAttrTopic(CShfeFtdcReqQryObjectAttrField *pReqQryObjectAttr, int nRequestID) = 0;

	///KeyFile查询请求
	virtual int ReqQryKeyFileInfoTopic(CShfeFtdcReqQryKeyFileInfoField *pReqQryKeyFileInfo, int nRequestID) = 0;

	///HostMonitorCfg查询请求
	virtual int ReqQryHostMonitorCfgTopic(CShfeFtdcReqQryHostMonitorCfgField *pReqQryHostMonitorCfg, int nRequestID) = 0;

	///AppMonitorCfg查询请求
	virtual int ReqQryAppMonitorCfgTopic(CShfeFtdcReqQryAppMonitorCfgField *pReqQryAppMonitorCfg, int nRequestID) = 0;

	///HostConfig查询请求
	virtual int ReqQryHostConfigTopic(CShfeFtdcReqQryHostConfigField *pReqQryHostConfig, int nRequestID) = 0;

	///历史对象状态指标查询
	virtual int ReqQryHistoryObjectAttrTopic(CShfeFtdcReqQryHistoryObjectAttrField *pReqQryHistoryObjectAttr, int nRequestID) = 0;

	///前置响应信息查询
	virtual int ReqQryFrontInfoTopic(CShfeFtdcReqQryFrontInfoField *pReqQryFrontInfo, int nRequestID) = 0;

	///用户登录
	virtual int ReqQrySysUserLoginTopic(CShfeFtdcReqQrySysUserLoginField *pReqQrySysUserLogin, int nRequestID) = 0;

	///用户登出
	virtual int ReqQrySysUserLogoutTopic(CShfeFtdcReqQrySysUserLogoutField *pReqQrySysUserLogout, int nRequestID) = 0;

	///用户修改密码
	virtual int ReqQrySysUserPasswordUpdateTopic(CShfeFtdcReqQrySysUserPasswordUpdateField *pReqQrySysUserPasswordUpdate, int nRequestID) = 0;

	///注册用户
	virtual int ReqQrySysUserRegisterTopic(CShfeFtdcReqQrySysUserRegisterField *pReqQrySysUserRegister, int nRequestID) = 0;

	///删除用户
	virtual int ReqQrySysUserDeleteTopic(CShfeFtdcReqQrySysUserDeleteField *pReqQrySysUserDelete, int nRequestID) = 0;

	///交易日志查询
	virtual int ReqQryTradeLogTopic(CShfeFtdcReqQryTradeLogField *pReqQryTradeLog, int nRequestID) = 0;

	///告警事件修改
	virtual int ReqQryWarningEventUpdateTopic(CShfeFtdcReqQryWarningEventUpdateField *pReqQryWarningEventUpdate, int nRequestID) = 0;

	///交易峰值查询
	virtual int ReqQryTradepeakTopic(CShfeFtdcReqQryTradepeakField *pReqQryTradepeak, int nRequestID) = 0;

	///
	virtual int ReqQryHistoryCpuInfoTopic(CShfeFtdcReqQryHistoryCpuInfoField *pReqQryHistoryCpuInfo, int nRequestID) = 0;

	///
	virtual int ReqQryHistoryMemInfoTopic(CShfeFtdcReqQryHistoryMemInfoField *pReqQryHistoryMemInfo, int nRequestID) = 0;

	///
	virtual int ReqQryHistoryNetworkInfoTopic(CShfeFtdcReqQryHistoryNetworkInfoField *pReqQryHistoryNetworkInfo, int nRequestID) = 0;

	///监控系统在线用户查询
	virtual int ReqQryMonitorOnlineUser(CShfeFtdcReqQryMonitorOnlineUserField *pReqQryMonitorOnlineUser, int nRequestID) = 0;

	///历史峰值查询
	virtual int ReqQryHistoryTradePeakTopic(CShfeFtdcReqQryHistoryTradePeakField *pReqQryHistoryTradePeak, int nRequestID) = 0;

	///日志事件查询
	virtual int ReqQrySyslogEventTopic(CShfeFtdcReqQrySyslogEventField *pReqQrySyslogEvent, int nRequestID) = 0;

	///日志事件订阅请求
	virtual int ReqQrySyslogEventSubcriberTopic(CShfeFtdcReqQrySyslogEventSubcriberField *pReqQrySyslogEventSubcriber, int nRequestID) = 0;

	///交易日切换通知
	virtual int ReqQryTradeDayChangeTopic(CShfeFtdcReqQryTradeDayChangeField *pReqQryTradeDayChange, int nRequestID) = 0;

	///tomcat信息查询
	virtual int ReqQryTomcatInfoTopic(CShfeFtdcReqQryTomcatInfoField *pReqQryTomcatInfo, int nRequestID) = 0;

	///虚拟机信息查询
	virtual int ReqQryVMInfoTopic(CShfeFtdcReqQryVMInfoField *pReqQryVMInfo, int nRequestID) = 0;

	///系统属性信息查询
	virtual int ReqQryPropertyInfoTopic(CShfeFtdcReqQryPropertyInfoField *pReqQryPropertyInfo, int nRequestID) = 0;

	///系统内存池信息查询
	virtual int ReqQryMemPoolInfoTopic(CShfeFtdcReqQryMemPoolInfoField *pReqQryMemPoolInfo, int nRequestID) = 0;

	///文件内容信息查询
	virtual int ReqQryFileContentInfoTopic(CShfeFtdcReqQryFileContentInfoField *pReqQryFileContentInfo, int nRequestID) = 0;

	///连接信息查询
	virtual int ReqQryConnectionInfoTopic(CShfeFtdcReqQryConnectionInfoField *pReqQryConnectionInfo, int nRequestID) = 0;

	///连接器信息查询
	virtual int ReqQryConnectorInfoTopic(CShfeFtdcReqQryConnectorInfoField *pReqQryConnectorInfo, int nRequestID) = 0;

	///数据库查询
	virtual int ReqQryDBQueryTopic(CShfeFtdcReqQryDBQueryField *pReqQryDBQuery, int nRequestID) = 0;

	///文件传输请求
	virtual int ReqQryGetFileTopic(CShfeFtdcReqQryGetFileField *pReqQryGetFile, int nRequestID) = 0;

	///日志事件修改请求
	virtual int ReqQrySyslogEventUpdateTopic(CShfeFtdcReqQrySyslogEventUpdateField *pReqQrySyslogEventUpdate, int nRequestID) = 0;

	///告警明细查询
	virtual int ReqQryWarningQueryTopic(CShfeFtdcReqQryWarningQueryField *pReqQryWarningQuery, int nRequestID) = 0;

	///网站访问查询
	virtual int ReqQryWebVisitTopic(CShfeFtdcReqQryWebVisitField *pReqQryWebVisit, int nRequestID) = 0;

	///告警激活变更
	virtual int ReqQryWarningActiveChange(CShfeFtdcReqQryWarningActiveChangeField *pReqQryWarningActiveChange, int nRequestID) = 0;

	///通用操作
	virtual int ReqQryGeneralOperateTopic(CShfeFtdcReqQryGeneralOperateField *pReqQryGeneralOperate, int nRequestID) = 0;

	///网络设备连接关系请求
	virtual int ReqQryNetDeviceLinkedTopic(CShfeFtdcReqQryNetDeviceLinkedField *pReqQryNetDeviceLinked, int nRequestID) = 0;

	///交易系统登录信息请求
	virtual int ReqQryTradeUserLoginStatTopic(CShfeFtdcReqQryTradeUserLoginStatField *pReqQryTradeUserLoginStat, int nRequestID) = 0;

	///交易系统前置报单响应信息
	virtual int ReqQryTradeFrontOrderRttStatTopic(CShfeFtdcReqQryTradeFrontOrderRttStatField *pReqQryTradeFrontOrderRttStat, int nRequestID) = 0;

	///系统路由信息
	virtual int ReqQryRouterInfoTopic(CShfeFtdcReqQryRouterInfoField *pReqQryRouterInfo, int nRequestID) = 0;

	///磁盘I/O信息
	virtual int ReqQryDiskIOTopic(CShfeFtdcReqQryDiskIOField *pReqQryDiskIO, int nRequestID) = 0;

	///系统状态信息
	virtual int ReqQryStatInfoTopic(CShfeFtdcReqQryStatInfoField *pReqQryStatInfo, int nRequestID) = 0;

	///交易系统前置报单分布区间
	virtual int ReqQryTradeOrderRttCutLineTopic(CShfeFtdcReqQryTradeOrderRttCutLineField *pReqQryTradeOrderRttCutLine, int nRequestID) = 0;

	///会员客户信息
	virtual int ReqQryClientInfoTopic(CShfeFtdcReqQryClientInfoField *pReqQryClientInfo, int nRequestID) = 0;

	///请求事件描述
	virtual int ReqQryEventDescriptionTopic(CShfeFtdcReqQryEventDescriptionField *pReqQryEventDescription, int nRequestID) = 0;

	///订阅前置唯一ID信息
	virtual int ReqQryFrontUniqueIDTopic(CShfeFtdcReqQryFrontUniqueIDField *pReqQryFrontUniqueID, int nRequestID) = 0;

	///会员线路地址变更请求
	virtual int ReqQryNetPartyLinkAddrChangeTopic(CShfeFtdcReqQryNetPartyLinkAddrChangeField *pReqQryNetPartyLinkAddrChange, int nRequestID) = 0;

	///请求已删除会员列表信息
	virtual int ReqQryNetDelPartyLinkInfoTopic(CShfeFtdcReqQryNetDelPartyLinkInfoField *pReqQryNetDelPartyLinkInfo, int nRequestID) = 0;

	///请求网络性能排序
	virtual int ReqQryPerformanceTopTopic(CShfeFtdcReqQryPerformanceTopField *pReqQryPerformanceTop, int nRequestID) = 0;

	///最新网络指标查询
	virtual int ReqQryRealTimeNetObjectAttrTopic(CShfeFtdcReqQryRealTimeNetObjectAttrField *pReqQryRealTimeNetObjectAttr, int nRequestID) = 0;

	///网络大区划分查询
	virtual int ReqQryNetAreaTopic(CShfeFtdcReqQryNetAreaField *pReqQryNetArea, int nRequestID) = 0;

	///网络子区查询
	virtual int ReqQryNetSubAreaTopic(CShfeFtdcReqQryNetSubAreaField *pReqQryNetSubArea, int nRequestID) = 0;

	///网络子区IP查询
	virtual int ReqQryNetSubAreaIPTopic(CShfeFtdcReqQryNetSubAreaIPField *pReqQryNetSubAreaIP, int nRequestID) = 0;

	///网络设备探测请求
	virtual int ReqQryNetDeviceDetectTopic(CShfeFtdcReqQryNetDeviceDetectField *pReqQryNetDeviceDetect, int nRequestID) = 0;

	///网络设备查询请求
	virtual int ReqQryNetDeviceRequestTopic(CShfeFtdcReqQryNetDeviceRequestField *pReqQryNetDeviceRequest, int nRequestID) = 0;

	///大楼查询
	virtual int ReqQryNetBuildingTopic(CShfeFtdcReqQryNetBuildingField *pReqQryNetBuilding, int nRequestID) = 0;

	///机房查询
	virtual int ReqQryNetRoomTopic(CShfeFtdcReqQryNetRoomField *pReqQryNetRoom, int nRequestID) = 0;

	///机柜查询
	virtual int ReqQryNetCabinetsTopic(CShfeFtdcReqQryNetCabinetsField *pReqQryNetCabinets, int nRequestID) = 0;

	///OID
	virtual int ReqQryNetOIDTopic(CShfeFtdcReqQryNetOIDField *pReqQryNetOID, int nRequestID) = 0;

	///时间策略
	virtual int ReqQryNetTimePolicyTopic(CShfeFtdcReqQryNetTimePolicyField *pReqQryNetTimePolicy, int nRequestID) = 0;

	///采集任务查询
	virtual int ReqQryNetGatherTaskTopic(CShfeFtdcReqQryNetGatherTaskField *pReqQryNetGatherTask, int nRequestID) = 0;

	///设备变更请求
	virtual int ReqQryNetDeviceChgTopic(CShfeFtdcReqQryNetDeviceChgField *pReqQryNetDeviceChg, int nRequestID) = 0;

	///常用设备型号请求
	virtual int ReqQryNetDeviceTypeTopic(CShfeFtdcReqQryNetDeviceTypeField *pReqQryNetDeviceType, int nRequestID) = 0;

	///常用设备类别请求
	virtual int ReqQryNetDeviceCategoryTopic(CShfeFtdcReqQryNetDeviceCategoryField *pReqQryNetDeviceCategory, int nRequestID) = 0;

	///设备厂商请求
	virtual int ReqQryNetManufactoryTopic(CShfeFtdcReqQryNetManufactoryField *pReqQryNetManufactory, int nRequestID) = 0;

	///设备共同体请求
	virtual int ReqQryNetCommunityTopic(CShfeFtdcReqQryNetCommunityField *pReqQryNetCommunity, int nRequestID) = 0;

	///端口类型请求
	virtual int ReqQryNetPortTypeTopic(CShfeFtdcReqQryNetPortTypeField *pReqQryNetPortType, int nRequestID) = 0;

	///会员接入地点请求
	virtual int ReqQryNetPartAccessSpotTopic(CShfeFtdcReqQryNetPartAccessSpotField *pReqQryNetPartAccessSpot, int nRequestID) = 0;

	///端口请求
	virtual int ReqQryNetInterfaceTopic(CShfeFtdcReqQryNetInterfaceField *pReqQryNetInterface, int nRequestID) = 0;

	///GeneralOID请求
	virtual int ReqQryNetGeneralOIDTopic(CShfeFtdcReqQryNetGeneralOIDField *pReqQryNetGeneralOID, int nRequestID) = 0;

	///监控对象类别
	virtual int ReqQryNetMonitorTypeTopic(CShfeFtdcReqQryNetMonitorTypeField *pReqQryNetMonitorType, int nRequestID) = 0;

	///指标统表
	virtual int ReqQryNetMonitorAttrScopeTopic(CShfeFtdcReqQryNetMonitorAttrScopeField *pReqQryNetMonitorAttrScope, int nRequestID) = 0;

	///监控指标表
	virtual int ReqQryNetMonitorAttrTypeTopic(CShfeFtdcReqQryNetMonitorAttrTypeField *pReqQryNetMonitorAttrType, int nRequestID) = 0;

	///监控对象指标表
	virtual int ReqQryNetMonitorObjectAttrTopic(CShfeFtdcReqQryNetMonitorObjectAttrField *pReqQryNetMonitorObjectAttr, int nRequestID) = 0;

	///职能区
	virtual int ReqQryNetFuncAreaTopic(CShfeFtdcReqQryNetFuncAreaField *pReqQryNetFuncArea, int nRequestID) = 0;

	///监控指令表
	virtual int ReqQryNetMonitorCommandTypeTopic(CShfeFtdcReqQryNetMonitorCommandTypeField *pReqQryNetMonitorCommandType, int nRequestID) = 0;

	///动作族表
	virtual int ReqQryNetMonitorActionGroupTopic(CShfeFtdcReqQryNetMonitorActionGroupField *pReqQryNetMonitorActionGroup, int nRequestID) = 0;

	///设备对象组表
	virtual int ReqQryNetMonitorDeviceGroupTopic(CShfeFtdcReqQryNetMonitorDeviceGroupField *pReqQryNetMonitorDeviceGroup, int nRequestID) = 0;

	///任务信息表
	virtual int ReqQryNetMonitorTaskInfoTopic(CShfeFtdcReqQryNetMonitorTaskInfoField *pReqQryNetMonitorTaskInfo, int nRequestID) = 0;

	///任务结果表
	virtual int ReqQryNetMonitorTaskResultTopic(CShfeFtdcReqQryNetMonitorTaskResultField *pReqQryNetMonitorTaskResult, int nRequestID) = 0;

	///任务对象集
	virtual int ReqQryNetMonitorTaskObjectSetTopic(CShfeFtdcReqQryNetMonitorTaskObjectSetField *pReqQryNetMonitorTaskObjectSet, int nRequestID) = 0;

	///会员链路信息表
	virtual int ReqQryNetPartyLinkInfoTopic(CShfeFtdcReqQryNetPartyLinkInfoField *pReqQryNetPartyLinkInfo, int nRequestID) = 0;

	///监控动作指标对照表
	virtual int ReqQryNetMonitorActionAttrTopic(CShfeFtdcReqQryNetMonitorActionAttrField *pReqQryNetMonitorActionAttr, int nRequestID) = 0;

	///模块
	virtual int ReqQryNetModuleTopic(CShfeFtdcReqQryNetModuleField *pReqQryNetModule, int nRequestID) = 0;

	///告警表达式信息表
	virtual int ReqQryNetEventExprTopic(CShfeFtdcReqQryNetEventExprField *pReqQryNetEventExpr, int nRequestID) = 0;

	///事件类型
	virtual int ReqQryNetEventTypeTopic(CShfeFtdcReqQryNetEventTypeField *pReqQryNetEventType, int nRequestID) = 0;

	///事件子类型
	virtual int ReqQryNetSubEventTypeTopic(CShfeFtdcReqQryNetSubEventTypeField *pReqQryNetSubEventType, int nRequestID) = 0;

	///事件级别
	virtual int ReqQryNetEventLevelTopic(CShfeFtdcReqQryNetEventLevelField *pReqQryNetEventLevel, int nRequestID) = 0;

	///任务结果状态表
	virtual int ReqQryNetMonitorTaskStatusResultTopic(CShfeFtdcReqQryNetMonitorTaskStatusResultField *pReqQryNetMonitorTaskStatusResult, int nRequestID) = 0;

	///登陆配置服务的请求
	virtual int ReqConfigLoginTopic(CShfeFtdcReqConfigLoginField *pReqConfigLogin, int nRequestID) = 0;

	///告知服务，让其退出
	virtual int ReqSysServerExitTopic(CShfeFtdcReqSysServerExitField *pReqSysServerExit, int nRequestID) = 0;

	///设备配置表
	virtual int ReqQryNetCfgFileTopic(CShfeFtdcReqQryNetCfgFileField *pReqQryNetCfgFile, int nRequestID) = 0;

	///任务结果规则分析表
	virtual int ReqQryNetMonitorDeviceTaskTopic(CShfeFtdcReqQryNetMonitorDeviceTaskField *pReqQryNetMonitorDeviceTask, int nRequestID) = 0;

	///任务指令指标集表
	virtual int ReqQryNetMonitorTaskInstAttrsTopic(CShfeFtdcReqQryNetMonitorTaskInstAttrsField *pReqQryNetMonitorTaskInstAttrs, int nRequestID) = 0;

	///文件通用操作
	virtual int ReqQryFileGeneralOperTopic(CShfeFtdcReqQryFileGeneralOperField *pReqQryFileGeneralOper, int nRequestID) = 0;

	///基线表
	virtual int ReqQryNetBaseLineTopic(CShfeFtdcReqQryNetBaseLineField *pReqQryNetBaseLine, int nRequestID) = 0;

	///基线任务表
	virtual int ReqQryNetBaseLineTaskTopic(CShfeFtdcReqQryNetBaseLineTaskField *pReqQryNetBaseLineTask, int nRequestID) = 0;

	///基线结果表
	virtual int ReqQryNetBaseLineResultTopic(CShfeFtdcReqQryNetBaseLineResultField *pReqQryNetBaseLineResult, int nRequestID) = 0;

	///会员链路状态信息表
	virtual int ReqQryNetPartyLinkStatusInfoTopic(CShfeFtdcReqQryNetPartyLinkStatusInfoField *pReqQryNetPartyLinkStatusInfo, int nRequestID) = 0;

	///会员SDH线路明细表
	virtual int ReqQryNetMemberSDHLineInfoTopic(CShfeFtdcReqQryNetMemberSDHLineInfoField *pReqQryNetMemberSDHLineInfo, int nRequestID) = 0;

	///DDN链路信息表
	virtual int ReqQryNetDDNLinkInfoTopic(CShfeFtdcReqQryNetDDNLinkInfoField *pReqQryNetDDNLinkInfo, int nRequestID) = 0;

	///非会员线路使用信息
	virtual int ReqQryNetPseudMemberLinkInfoTopic(CShfeFtdcReqQryNetPseudMemberLinkInfoField *pReqQryNetPseudMemberLinkInfo, int nRequestID) = 0;

	///远端设备信息
	virtual int ReqQryOuterDeviceInfTopic(CShfeFtdcReqQryOuterDeviceInfField *pReqQryOuterDeviceInf, int nRequestID) = 0;

	///本地ping结果
	virtual int ReqQryNetLocalPingResultInfoTopic(CShfeFtdcReqQryNetLocalPingResultInfoField *pReqQryNetLocalPingResultInfo, int nRequestID) = 0;

	///远程ping结果
	virtual int ReqQryNetRomotePingResultInfoTopic(CShfeFtdcReqQryNetRomotePingResultInfoField *pReqQryNetRomotePingResultInfo, int nRequestID) = 0;

	///系统内部级联关系
	virtual int ReqQrySysInternalTopologyTopic(CShfeFtdcReqQrySysInternalTopologyField *pReqQrySysInternalTopology, int nRequestID) = 0;

	///请求会员链路费用表
	virtual int ReqQryMemberLinkCostTopic(CShfeFtdcReqQryMemberLinkCostField *pReqQryMemberLinkCost, int nRequestID) = 0;

	///请求会员链路月租表
	virtual int ReqQryNetPartylinkMonthlyRentTopic(CShfeFtdcReqQryNetPartylinkMonthlyRentField *pReqQryNetPartylinkMonthlyRent, int nRequestID) = 0;

	///请求非会员链路表信息
	virtual int ReqQryNetNonPartyLinkInfoTopic(CShfeFtdcReqQryNetNonPartyLinkInfoField *pReqQryNetNonPartyLinkInfo, int nRequestID) = 0;

	///请求配置信息
	virtual int ReqQryMonConfigInfo(CShfeFtdcReqQryMonConfigInfoField *pReqQryMonConfigInfo, int nRequestID) = 0;

	///服务连接请求
	virtual int ReqMonServiceConnect(CShfeFtdcReqMonServiceConnectField *pReqMonServiceConnect, int nRequestID) = 0;

	///服务的当前状态查询
	virtual int ReqQryMonServiceStatus(CShfeFtdcReqQryMonServiceStatusField *pReqQryMonServiceStatus, int nRequestID) = 0;

	///探针任务配置查询请求
	virtual int ReqQryMonProbeTask(CShfeFtdcReqQryMonProbeTaskField *pReqQryMonProbeTask, int nRequestID) = 0;

	///监控系统指标查询请求
	virtual int ReqQryMonObjectAttr(CShfeFtdcReqQryMonObjectAttrField *pReqQryMonObjectAttr, int nRequestID) = 0;

	///监控系统Syslog事件查询请求
	virtual int ReqQryMonSyslogEvent(CShfeFtdcReqQryMonSyslogEventField *pReqQryMonSyslogEvent, int nRequestID) = 0;

	///文件读取偏移量查询请求
	virtual int ReqQryMonFileOffset(CShfeFtdcReqQryMonFileOffsetField *pReqQryMonFileOffset, int nRequestID) = 0;

	///文件内容查询请求
	virtual int ReqQryMonFileContent(CShfeFtdcReqQryMonFileContentField *pReqQryMonFileContent, int nRequestID) = 0;

	///主机基础环境信息查询请求
	virtual int ReqQryMonHostBasicEnv(CShfeFtdcReqQryMonHostBasicEnvField *pReqQryMonHostBasicEnv, int nRequestID) = 0;

	///主机基础网络信息查询
	virtual int ReqQryMonHostNetworkEnv(CShfeFtdcReqQryMonHostNetworkEnvField *pReqQryMonHostNetworkEnv, int nRequestID) = 0;

	///主机文件系统信息查询
	virtual int ReqQryMonHostFileSysEnv(CShfeFtdcReqQryMonHostFileSysEnvField *pReqQryMonHostFileSysEnv, int nRequestID) = 0;

	///主机交换分区信息查询
	virtual int ReqQryMonHostSwapEnv(CShfeFtdcReqQryMonHostSwapEnvField *pReqQryMonHostSwapEnv, int nRequestID) = 0;

	///主机的CPU信息指标信息请求
	virtual int ReqQryMonHostCPUAttr(CShfeFtdcReqQryMonHostCPUAttrField *pReqQryMonHostCPUAttr, int nRequestID) = 0;

	///主机的Memory使用信息请求
	virtual int ReqQryMonHostMemAttr(CShfeFtdcReqQryMonHostMemAttrField *pReqQryMonHostMemAttr, int nRequestID) = 0;

	///主机的FileSystem使用信息请求
	virtual int ReqQryMonHostFileSystemAttr(CShfeFtdcReqQryMonHostFileSystemAttrField *pReqQryMonHostFileSystemAttr, int nRequestID) = 0;

	///主机的用户信息请求
	virtual int ReqQryMonHostUserInfo(CShfeFtdcReqQryMonHostUserInfoField *pReqQryMonHostUserInfo, int nRequestID) = 0;

	///主机的在线用户信息请求
	virtual int ReqQryMonHostOnlineUserInfo(CShfeFtdcReqQryMonHostOnlineUserInfoField *pReqQryMonHostOnlineUserInfo, int nRequestID) = 0;

	///主机的network使用信息请求
	virtual int ReqQryMonHostNetworkAttr(CShfeFtdcReqQryMonHostNetworkAttrField *pReqQryMonHostNetworkAttr, int nRequestID) = 0;

	///主机的系统状态信息请求
	virtual int ReqQryMonHostStatInfo(CShfeFtdcReqQryMonHostStatInfoField *pReqQryMonHostStatInfo, int nRequestID) = 0;

	///主机的磁盘IO信息请求
	virtual int ReqQryMonHostDiskIOAttr(CShfeFtdcReqQryMonHostDiskIOAttrField *pReqQryMonHostDiskIOAttr, int nRequestID) = 0;

	///主机的路由信息请求
	virtual int ReqQryMonHostRouterInfo(CShfeFtdcReqQryMonHostRouterInfoField *pReqQryMonHostRouterInfo, int nRequestID) = 0;

	///主机的进程信息请求
	virtual int ReqQryMonHostProcessInfo(CShfeFtdcReqQryMonHostProcessInfoField *pReqQryMonHostProcessInfo, int nRequestID) = 0;

	///客户端临时SP查询请求
	virtual int ReqQryMonSPQuery(CShfeFtdcReqQryMonSPQueryField *pReqQryMonSPQuery, int nRequestID) = 0;

	///服务版本信息请求
	virtual int ReqServiceVersion(CShfeFtdcReqServiceVersionField *pReqServiceVersion, int nRequestID) = 0;

	///服务应用程序请求
	virtual int ReqServiceProgram(CShfeFtdcReqServiceProgramField *pReqServiceProgram, int nRequestID) = 0;

	///升级服务获取状态
	virtual int ReqUpdateState(CShfeFtdcReqUpdateStateField *pReqUpdateState, int nRequestID) = 0;

	///订阅请求
	virtual int ReqSubscribe(CShfeFtdcReqSubscribeField *pReqSubscribe, int nRequestID) = 0;

	///取消订阅请求
	virtual int ReqCancelSubscribe(CShfeFtdcReqSubscribeField *pReqSubscribe, int nRequestID) = 0;

	///用于通知目标服务文件已发送成功
	virtual int ReqFileSendSuccess(CShfeFtdcReqFileSendSuccessField *pReqFileSendSuccess, int nRequestID) = 0;

	///tomcat信息查询
	virtual int ReqQryMonTomcatInfo(CShfeFtdcReqQryMonTomcatInfoField *pReqQryMonTomcatInfo, int nRequestID) = 0;

	///虚拟机信息查询
	virtual int ReqQryMonVMInfo(CShfeFtdcReqQryMonVMInfoField *pReqQryMonVMInfo, int nRequestID) = 0;

	///系统属性信息查询
	virtual int ReqQryMonPropertyInfo(CShfeFtdcReqQryMonPropertyInfoField *pReqQryMonPropertyInfo, int nRequestID) = 0;

	///系统内存池信息查询
	virtual int ReqQryMonMemPoolInfo(CShfeFtdcReqQryMonMemPoolInfoField *pReqQryMonMemPoolInfo, int nRequestID) = 0;

	///连接信息查询
	virtual int ReqQryMonConnectionInfo(CShfeFtdcReqQryMonConnectionInfoField *pReqQryMonConnectionInfo, int nRequestID) = 0;

	///无效报单查询
	virtual int ReqQryInvalidateOrderTopic(CShfeFtdcReqQryInvalidateOrderField *pReqQryInvalidateOrder, int nRequestID) = 0;

	///报单状态查询
	virtual int ReqQryOrderStatusTopic(CShfeFtdcReqQryOrderStatusField *pReqQryOrderStatus, int nRequestID) = 0;

	///报单成交查询
	virtual int ReqQryBargainOrderTopic(CShfeFtdcReqQryBargainOrderField *pReqQryBargainOrder, int nRequestID) = 0;

	///合约基本属性查询
	virtual int ReqQryInstPropertyTopic(CShfeFtdcReqQryInstPropertyField *pReqQryInstProperty, int nRequestID) = 0;

	///合约保证金率查询
	virtual int ReqQryMarginRateTopic(CShfeFtdcReqQryMarginRateField *pReqQryMarginRate, int nRequestID) = 0;

	///合约涨跌停板查询
	virtual int ReqQryPriceLimitTopic(CShfeFtdcReqQryPriceLimitField *pReqQryPriceLimit, int nRequestID) = 0;

	///会员限仓查询
	virtual int ReqQryPartPosiLimitTopic(CShfeFtdcReqQryPartPosiLimitField *pReqQryPartPosiLimit, int nRequestID) = 0;

	///客户限仓查询
	virtual int ReqQryClientPosiLimitTopic(CShfeFtdcReqQryClientPosiLimitField *pReqQryClientPosiLimit, int nRequestID) = 0;

	///特殊客户限仓查询
	virtual int ReqQrySpecialPosiLimitTopic(CShfeFtdcReqQrySpecialPosiLimitField *pReqQrySpecialPosiLimit, int nRequestID) = 0;

	///账户出入金查询
	virtual int ReqQryTransactionChgTopic(CShfeFtdcReqQryTransactionChgField *pReqQryTransactionChg, int nRequestID) = 0;

	///客户数据变动查询
	virtual int ReqQryClientChgTopic(CShfeFtdcReqQryClientChgField *pReqQryClientChg, int nRequestID) = 0;

	///会员客户对照变动查询
	virtual int ReqQryPartClientChgTopic(CShfeFtdcReqQryPartClientChgField *pReqQryPartClientChg, int nRequestID) = 0;

	///限仓数据变动查询
	virtual int ReqQryPosiLimitChgTopic(CShfeFtdcReqQryPosiLimitChgField *pReqQryPosiLimitChg, int nRequestID) = 0;

	///保值额度变动查询
	virtual int ReqQryHedgeDetailChgTopic(CShfeFtdcReqQryHedgeDetailChgField *pReqQryHedgeDetailChg, int nRequestID) = 0;

	///会员变动查询
	virtual int ReqQryParticipantChgTopic(CShfeFtdcReqQryParticipantChgField *pReqQryParticipantChg, int nRequestID) = 0;

	///保证金率变动查询
	virtual int ReqQryMarginRateChgTopic(CShfeFtdcReqQryMarginRateChgField *pReqQryMarginRateChg, int nRequestID) = 0;

	///IP地址变动查询
	virtual int ReqQryUserIpChgTopic(CShfeFtdcReqQryUserIpChgField *pReqQryUserIpChg, int nRequestID) = 0;

	///限仓数据变动查询
	virtual int ReqQryClientPosiLimitChgTopic(CShfeFtdcReqQryClientPosiLimitChgField *pReqQryClientPosiLimitChg, int nRequestID) = 0;

	///限仓数据变动查询
	virtual int ReqQrySpecPosiLimitChgTopic(CShfeFtdcReqQrySpecPosiLimitChgField *pReqQrySpecPosiLimitChg, int nRequestID) = 0;

	///交易系统前置统计查询
	virtual int ReqQryFrontStatTopic(CShfeFtdcReqQryFrontStatField *pReqQryFrontStat, int nRequestID) = 0;

	///管理平台初始化信息查询
	virtual int ReqQryParticipantInitTopic(CShfeFtdcReqQryParticipantInitField *pReqQryParticipantInit, int nRequestID) = 0;

	///管理平台初始化信息查询
	virtual int ReqQryUserInitTopic(CShfeFtdcReqQryUserInitField *pReqQryUserInit, int nRequestID) = 0;

	///请求约状态切换数据
	virtual int ReqQryInstrumentStatusTopic(CShfeFtdcReqQryInstrumentStatusField *pReqQryInstrumentStatus, int nRequestID) = 0;

	///请求合约交易节信息
	virtual int ReqQryCurrTradingSegmentAttrTopic(CShfeFtdcReqQryCurrTradingSegmentAttrField *pReqQryCurrTradingSegmentAttr, int nRequestID) = 0;

	///交易系统登录信息查询
	virtual int ReqQryTradeUserLoginInfoTopic(CShfeFtdcReqQryTradeUserLoginInfoField *pReqQryTradeUserLoginInfo, int nRequestID) = 0;

	///会员交易查询
	virtual int ReqQryPartTradeTopic(CShfeFtdcReqQryPartTradeField *pReqQryPartTrade, int nRequestID) = 0;

	///会员席位交易状态
	virtual int ReqQryParticTradeOrderStatesTopic(CShfeFtdcReqQryParticTradeOrderStatesField *pReqQryParticTradeOrderStates, int nRequestID) = 0;

	///获得监控对象信息查询
	virtual int ReqQryMonitor2ObjectTopic(CShfeFtdcReqQryMonitor2ObjectField *pReqQryMonitor2Object, int nRequestID) = 0;

	///主机环境信息查询
	virtual int ReqQryMonHostCommonEnvTopic(CShfeFtdcReqQryMonHostCommonEnvField *pReqQryMonHostCommonEnv, int nRequestID) = 0;

	///获取业务进程和主机关系
	virtual int ReqQryMonOidHostRationalTopic(CShfeFtdcReqQryMonOidHostRationalField *pReqQryMonOidHostRational, int nRequestID) = 0;

	///对象关系查询
	virtual int ReqQryMonOidRelationTopic(CShfeFtdcReqQryMonOidRelationField *pReqQryMonOidRelation, int nRequestID) = 0;
protected:
	~CShfeFtdcUserApi(){};
};

#endif
