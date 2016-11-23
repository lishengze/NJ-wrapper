/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file FtdcUserApiImpl.h
///@brief 定义了客户端接口实现
///@history 
///20060106	赵鸿昊		创建该文件
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

	///用户退出请求
	virtual int ReqUserLogout(CShfeFtdcReqUserLogoutField *pReqUserLogout, int nRequestID);

	///报单录入请求
	virtual int ReqOrderInsert(CShfeFtdcInputOrderField *pInputOrder, int nRequestID);

	///报单操作请求
	virtual int ReqOrderAction(CShfeFtdcOrderActionField *pOrderAction, int nRequestID);

	///报价录入请求
	virtual int ReqQuoteInsert(CShfeFtdcInputQuoteField *pInputQuote, int nRequestID);

	///报价操作请求
	virtual int ReqQuoteAction(CShfeFtdcQuoteActionField *pQuoteAction, int nRequestID);

	///OTC报单录入请求
	virtual int ReqOTCOrderInsert(CShfeFtdcOTCOrderField *pOTCOrder, int nRequestID);

	///用户密码修改请求
	virtual int ReqUserPasswordUpdate(CShfeFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID);

	///执行宣告录入请求
	virtual int ReqExecOrderInsert(CShfeFtdcInputExecOrderField *pInputExecOrder, int nRequestID);

	///执行宣告操作请求
	virtual int ReqExecOrderAction(CShfeFtdcExecOrderActionField *pExecOrderAction, int nRequestID);

	///管理报单录入请求
	virtual int ReqAdminOrderInsert(CShfeFtdcInputAdminOrderField *pInputAdminOrder, int nRequestID);

	///非标组合报单录入请求
	virtual int ReqCombOrderInsert(CShfeFtdcInputCombOrderField *pInputCombOrder, int nRequestID);

	///订阅主题请求
	virtual int ReqSubscribeTopic(CShfeFtdcDisseminationField *pDissemination, int nRequestID);

	///交易所公告请求
	virtual int ReqBulletin(CShfeFtdcBulletinField *pBulletin, int nRequestID);

	///交易所信息请求
	virtual int ReqInformation(CShfeFtdcInformationField *pInformation, int nRequestID);

	///合约交易状态改变请求
	virtual int ReqInstrumentStatusUpdate(CShfeFtdcInstrumentStatusField *pInstrumentStatus, int nRequestID);

	///强制用户退出请求
	virtual int ReqForceUserExit(CShfeFtdcForceUserExitField *pForceUserExit, int nRequestID);

	///用户会话删除请求
	virtual int ReqForceUserLogout(CShfeFtdcForceUserExitField *pForceUserExit, int nRequestID);

	///交易所数据同步状态改变请求
	virtual int ReqExchangeDataSyncStatusUpdate(CShfeFtdcExchangeDataSyncStatusField *pExchangeDataSyncStatus, int nRequestID);

	///结算组数据同步状态改变请求
	virtual int ReqSGDataSyncStatusUpdate(CShfeFtdcSGDataSyncStatusField *pSGDataSyncStatus, int nRequestID);

	///会员资金查询请求
	virtual int ReqQryPartAccount(CShfeFtdcQryPartAccountField *pQryPartAccount, int nRequestID);

	///报单查询请求
	virtual int ReqQryOrder(CShfeFtdcQryOrderField *pQryOrder, int nRequestID);

	///报价查询请求
	virtual int ReqQryQuote(CShfeFtdcQryQuoteField *pQryQuote, int nRequestID);

	///成交单查询请求
	virtual int ReqQryTrade(CShfeFtdcQryTradeField *pQryTrade, int nRequestID);

	///会员客户查询请求
	virtual int ReqQryClient(CShfeFtdcQryClientField *pQryClient, int nRequestID);

	///会员持仓查询请求
	virtual int ReqQryPartPosition(CShfeFtdcQryPartPositionField *pQryPartPosition, int nRequestID);

	///客户持仓查询请求
	virtual int ReqQryClientPosition(CShfeFtdcQryClientPositionField *pQryClientPosition, int nRequestID);

	///合约查询请求
	virtual int ReqQryInstrument(CShfeFtdcQryInstrumentField *pQryInstrument, int nRequestID);

	///合约交易状态查询请求
	virtual int ReqQryInstrumentStatus(CShfeFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID);

	///结算组状态查询请求
	virtual int ReqQrySGDataSyncStatus(CShfeFtdcQrySGDataSyncStatusField *pQrySGDataSyncStatus, int nRequestID);

	///保值额度查询
	virtual int ReqQryHedgeVolume(CShfeFtdcQryHedgeVolumeField *pQryHedgeVolume, int nRequestID);

	///信用限额查询请求
	virtual int ReqQryCreditLimit(CShfeFtdcQryCreditLimitField *pQryCreditLimit, int nRequestID);

	///非标组合报单查询请求
	virtual int ReqQryCombOrder(CShfeFtdcQryCombOrderField *pQryCombOrder, int nRequestID);

	///执行宣告查询请求
	virtual int ReqQryExecOrder(CShfeFtdcQryExecOrderField *pQryExecOrder, int nRequestID);

	///普通行情查询请求
	virtual int ReqQryMarketData(CShfeFtdcQryMarketDataField *pQryMarketData, int nRequestID);

	///交易所公告查询请求
	virtual int ReqQryBulletin(CShfeFtdcQryBulletinField *pQryBulletin, int nRequestID);

	///主题查询请求
	virtual int ReqQryTopic(CShfeFtdcDisseminationField *pDissemination, int nRequestID);

	///用户在线查询请求
	virtual int ReqQryUserSession(CShfeFtdcQryUserSessionField *pQryUserSession, int nRequestID);

	///用户查询请求
	virtual int ReqQryUser(CShfeFtdcQryUserField *pQryUser, int nRequestID);

	///会员查询请求
	virtual int ReqQryParticipant(CShfeFtdcQryParticipantField *pQryParticipant, int nRequestID);

	///合约价位查询
	virtual int ReqQryMBLMarketData(CShfeFtdcQryMBLMarketDataField *pQryMBLMarketData, int nRequestID);

	///信息查询
	virtual int ReqQryInformation(CShfeFtdcQryInformationField *pQryInformation, int nRequestID);

	///客户持仓查询请求
	virtual int ReqQryClientPositionV1(CShfeFtdcQryClientPositionV1Field *pQryClientPositionV1, int nRequestID);

	///汇率查询请求
	virtual int ReqQryExchangeRate(CShfeFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID);

	///CPU查询
	virtual int ReqQryTopCpuInfoTopic(CShfeFtdcReqQryTopCpuInfoField *pReqQryTopCpuInfo, int nRequestID);

	///Mem查询
	virtual int ReqQryTopMemInfoTopic(CShfeFtdcReqQryTopMemInfoField *pReqQryTopMemInfo, int nRequestID);

	///process查询
	virtual int ReqQryTopProcessInfoTopic(CShfeFtdcReqQryTopProcessInfoField *pReqQryTopProcessInfo, int nRequestID);

	///filesystem查询
	virtual int ReqQryFileSystemInfoTopic(CShfeFtdcReqQryFileSystemInfoField *pReqQryFileSystemInfo, int nRequestID);

	///network查询
	virtual int ReqQryNetworkInfoTopic(CShfeFtdcReqQryNetworkInfoField *pReqQryNetworkInfo, int nRequestID);

	///主机环境信息查询
	virtual int ReqQryHostEnvTopic(CShfeFtdcReqQryHostEnvField *pReqQryHostEnv, int nRequestID);

	///客户端登录查询
	virtual int ReqQryClientLoginTopic(CShfeFtdcReqQryClientLoginField *pReqQryClientLogin, int nRequestID);

	///获得监控对象信息查询
	virtual int ReqQryMonitorObjectTopic(CShfeFtdcReqQryMonitorObjectField *pReqQryMonitorObject, int nRequestID);

	///获得业务进程和主机的对应关系查询
	virtual int ReqQryObjectRationalTopic(CShfeFtdcReqQryObjectRationalField *pReqQryObjectRational, int nRequestID);

	///日志文件内容查询
	virtual int ReqQrySyslogInfoTopic(CShfeFtdcReqQrySyslogInfoField *pReqQrySyslogInfo, int nRequestID);

	///监控内容订阅请求
	virtual int ReqQrySubscriberTopic(CShfeFtdcReqQrySubscriberField *pReqQrySubscriber, int nRequestID);

	///对象关系查询
	virtual int ReqQryOidRelationTopic(CShfeFtdcReqQryOidRelationField *pReqQryOidRelation, int nRequestID);

	///用户信息查询请求
	virtual int ReqQryUserInfoTopic(CShfeFtdcReqQryUserInfoField *pReqQryUserInfo, int nRequestID);

	///在线用户信息查询请求
	virtual int ReqQryOnlineUserInfoTopic(CShfeFtdcReqQryOnlineUserInfoField *pReqQryOnlineUserInfo, int nRequestID);

	///告警事件查询请求
	virtual int ReqQryWarningEventTopic(CShfeFtdcReqQryWarningEventField *pReqQryWarningEvent, int nRequestID);

	///CPU使用率查询请求
	virtual int ReqQryCPUUsageTopic(CShfeFtdcReqQryCPUUsageField *pReqQryCPUUsage, int nRequestID);

	///内存使用率查询请求
	virtual int ReqQryMemoryUsageTopic(CShfeFtdcReqQryMemoryUsageField *pReqQryMemoryUsage, int nRequestID);

	///硬盘使用率查询请求
	virtual int ReqQryDiskUsageTopic(CShfeFtdcReqQryDiskUsageField *pReqQryDiskUsage, int nRequestID);

	///对象状态指标查询
	virtual int ReqQryObjectAttrTopic(CShfeFtdcReqQryObjectAttrField *pReqQryObjectAttr, int nRequestID);

	///KeyFile查询请求
	virtual int ReqQryKeyFileInfoTopic(CShfeFtdcReqQryKeyFileInfoField *pReqQryKeyFileInfo, int nRequestID);

	///HostMonitorCfg查询请求
	virtual int ReqQryHostMonitorCfgTopic(CShfeFtdcReqQryHostMonitorCfgField *pReqQryHostMonitorCfg, int nRequestID);

	///AppMonitorCfg查询请求
	virtual int ReqQryAppMonitorCfgTopic(CShfeFtdcReqQryAppMonitorCfgField *pReqQryAppMonitorCfg, int nRequestID);

	///HostConfig查询请求
	virtual int ReqQryHostConfigTopic(CShfeFtdcReqQryHostConfigField *pReqQryHostConfig, int nRequestID);

	///历史对象状态指标查询
	virtual int ReqQryHistoryObjectAttrTopic(CShfeFtdcReqQryHistoryObjectAttrField *pReqQryHistoryObjectAttr, int nRequestID);

	///前置响应信息查询
	virtual int ReqQryFrontInfoTopic(CShfeFtdcReqQryFrontInfoField *pReqQryFrontInfo, int nRequestID);

	///用户登录
	virtual int ReqQrySysUserLoginTopic(CShfeFtdcReqQrySysUserLoginField *pReqQrySysUserLogin, int nRequestID);

	///用户登出
	virtual int ReqQrySysUserLogoutTopic(CShfeFtdcReqQrySysUserLogoutField *pReqQrySysUserLogout, int nRequestID);

	///用户修改密码
	virtual int ReqQrySysUserPasswordUpdateTopic(CShfeFtdcReqQrySysUserPasswordUpdateField *pReqQrySysUserPasswordUpdate, int nRequestID);

	///注册用户
	virtual int ReqQrySysUserRegisterTopic(CShfeFtdcReqQrySysUserRegisterField *pReqQrySysUserRegister, int nRequestID);

	///删除用户
	virtual int ReqQrySysUserDeleteTopic(CShfeFtdcReqQrySysUserDeleteField *pReqQrySysUserDelete, int nRequestID);

	///交易日志查询
	virtual int ReqQryTradeLogTopic(CShfeFtdcReqQryTradeLogField *pReqQryTradeLog, int nRequestID);

	///告警事件修改
	virtual int ReqQryWarningEventUpdateTopic(CShfeFtdcReqQryWarningEventUpdateField *pReqQryWarningEventUpdate, int nRequestID);

	///交易峰值查询
	virtual int ReqQryTradepeakTopic(CShfeFtdcReqQryTradepeakField *pReqQryTradepeak, int nRequestID);

	///
	virtual int ReqQryHistoryCpuInfoTopic(CShfeFtdcReqQryHistoryCpuInfoField *pReqQryHistoryCpuInfo, int nRequestID);

	///
	virtual int ReqQryHistoryMemInfoTopic(CShfeFtdcReqQryHistoryMemInfoField *pReqQryHistoryMemInfo, int nRequestID);

	///
	virtual int ReqQryHistoryNetworkInfoTopic(CShfeFtdcReqQryHistoryNetworkInfoField *pReqQryHistoryNetworkInfo, int nRequestID);

	///监控系统在线用户查询
	virtual int ReqQryMonitorOnlineUser(CShfeFtdcReqQryMonitorOnlineUserField *pReqQryMonitorOnlineUser, int nRequestID);

	///历史峰值查询
	virtual int ReqQryHistoryTradePeakTopic(CShfeFtdcReqQryHistoryTradePeakField *pReqQryHistoryTradePeak, int nRequestID);

	///日志事件查询
	virtual int ReqQrySyslogEventTopic(CShfeFtdcReqQrySyslogEventField *pReqQrySyslogEvent, int nRequestID);

	///日志事件订阅请求
	virtual int ReqQrySyslogEventSubcriberTopic(CShfeFtdcReqQrySyslogEventSubcriberField *pReqQrySyslogEventSubcriber, int nRequestID);

	///交易日切换通知
	virtual int ReqQryTradeDayChangeTopic(CShfeFtdcReqQryTradeDayChangeField *pReqQryTradeDayChange, int nRequestID);

	///tomcat信息查询
	virtual int ReqQryTomcatInfoTopic(CShfeFtdcReqQryTomcatInfoField *pReqQryTomcatInfo, int nRequestID);

	///虚拟机信息查询
	virtual int ReqQryVMInfoTopic(CShfeFtdcReqQryVMInfoField *pReqQryVMInfo, int nRequestID);

	///系统属性信息查询
	virtual int ReqQryPropertyInfoTopic(CShfeFtdcReqQryPropertyInfoField *pReqQryPropertyInfo, int nRequestID);

	///系统内存池信息查询
	virtual int ReqQryMemPoolInfoTopic(CShfeFtdcReqQryMemPoolInfoField *pReqQryMemPoolInfo, int nRequestID);

	///文件内容信息查询
	virtual int ReqQryFileContentInfoTopic(CShfeFtdcReqQryFileContentInfoField *pReqQryFileContentInfo, int nRequestID);

	///连接信息查询
	virtual int ReqQryConnectionInfoTopic(CShfeFtdcReqQryConnectionInfoField *pReqQryConnectionInfo, int nRequestID);

	///连接器信息查询
	virtual int ReqQryConnectorInfoTopic(CShfeFtdcReqQryConnectorInfoField *pReqQryConnectorInfo, int nRequestID);

	///数据库查询
	virtual int ReqQryDBQueryTopic(CShfeFtdcReqQryDBQueryField *pReqQryDBQuery, int nRequestID);

	///文件传输请求
	virtual int ReqQryGetFileTopic(CShfeFtdcReqQryGetFileField *pReqQryGetFile, int nRequestID);

	///日志事件修改请求
	virtual int ReqQrySyslogEventUpdateTopic(CShfeFtdcReqQrySyslogEventUpdateField *pReqQrySyslogEventUpdate, int nRequestID);

	///告警明细查询
	virtual int ReqQryWarningQueryTopic(CShfeFtdcReqQryWarningQueryField *pReqQryWarningQuery, int nRequestID);

	///网站访问查询
	virtual int ReqQryWebVisitTopic(CShfeFtdcReqQryWebVisitField *pReqQryWebVisit, int nRequestID);

	///告警激活变更
	virtual int ReqQryWarningActiveChange(CShfeFtdcReqQryWarningActiveChangeField *pReqQryWarningActiveChange, int nRequestID);

	///通用操作
	virtual int ReqQryGeneralOperateTopic(CShfeFtdcReqQryGeneralOperateField *pReqQryGeneralOperate, int nRequestID);

	///网络设备连接关系请求
	virtual int ReqQryNetDeviceLinkedTopic(CShfeFtdcReqQryNetDeviceLinkedField *pReqQryNetDeviceLinked, int nRequestID);

	///交易系统登录信息请求
	virtual int ReqQryTradeUserLoginStatTopic(CShfeFtdcReqQryTradeUserLoginStatField *pReqQryTradeUserLoginStat, int nRequestID);

	///交易系统前置报单响应信息
	virtual int ReqQryTradeFrontOrderRttStatTopic(CShfeFtdcReqQryTradeFrontOrderRttStatField *pReqQryTradeFrontOrderRttStat, int nRequestID);

	///系统路由信息
	virtual int ReqQryRouterInfoTopic(CShfeFtdcReqQryRouterInfoField *pReqQryRouterInfo, int nRequestID);

	///磁盘I/O信息
	virtual int ReqQryDiskIOTopic(CShfeFtdcReqQryDiskIOField *pReqQryDiskIO, int nRequestID);

	///系统状态信息
	virtual int ReqQryStatInfoTopic(CShfeFtdcReqQryStatInfoField *pReqQryStatInfo, int nRequestID);

	///交易系统前置报单分布区间
	virtual int ReqQryTradeOrderRttCutLineTopic(CShfeFtdcReqQryTradeOrderRttCutLineField *pReqQryTradeOrderRttCutLine, int nRequestID);

	///会员客户信息
	virtual int ReqQryClientInfoTopic(CShfeFtdcReqQryClientInfoField *pReqQryClientInfo, int nRequestID);

	///请求事件描述
	virtual int ReqQryEventDescriptionTopic(CShfeFtdcReqQryEventDescriptionField *pReqQryEventDescription, int nRequestID);

	///订阅前置唯一ID信息
	virtual int ReqQryFrontUniqueIDTopic(CShfeFtdcReqQryFrontUniqueIDField *pReqQryFrontUniqueID, int nRequestID);

	///会员线路地址变更请求
	virtual int ReqQryNetPartyLinkAddrChangeTopic(CShfeFtdcReqQryNetPartyLinkAddrChangeField *pReqQryNetPartyLinkAddrChange, int nRequestID);

	///请求已删除会员列表信息
	virtual int ReqQryNetDelPartyLinkInfoTopic(CShfeFtdcReqQryNetDelPartyLinkInfoField *pReqQryNetDelPartyLinkInfo, int nRequestID);

	///请求网络性能排序
	virtual int ReqQryPerformanceTopTopic(CShfeFtdcReqQryPerformanceTopField *pReqQryPerformanceTop, int nRequestID);

	///最新网络指标查询
	virtual int ReqQryRealTimeNetObjectAttrTopic(CShfeFtdcReqQryRealTimeNetObjectAttrField *pReqQryRealTimeNetObjectAttr, int nRequestID);

	///网络大区划分查询
	virtual int ReqQryNetAreaTopic(CShfeFtdcReqQryNetAreaField *pReqQryNetArea, int nRequestID);

	///网络子区查询
	virtual int ReqQryNetSubAreaTopic(CShfeFtdcReqQryNetSubAreaField *pReqQryNetSubArea, int nRequestID);

	///网络子区IP查询
	virtual int ReqQryNetSubAreaIPTopic(CShfeFtdcReqQryNetSubAreaIPField *pReqQryNetSubAreaIP, int nRequestID);

	///网络设备探测请求
	virtual int ReqQryNetDeviceDetectTopic(CShfeFtdcReqQryNetDeviceDetectField *pReqQryNetDeviceDetect, int nRequestID);

	///网络设备查询请求
	virtual int ReqQryNetDeviceRequestTopic(CShfeFtdcReqQryNetDeviceRequestField *pReqQryNetDeviceRequest, int nRequestID);

	///大楼查询
	virtual int ReqQryNetBuildingTopic(CShfeFtdcReqQryNetBuildingField *pReqQryNetBuilding, int nRequestID);

	///机房查询
	virtual int ReqQryNetRoomTopic(CShfeFtdcReqQryNetRoomField *pReqQryNetRoom, int nRequestID);

	///机柜查询
	virtual int ReqQryNetCabinetsTopic(CShfeFtdcReqQryNetCabinetsField *pReqQryNetCabinets, int nRequestID);

	///OID
	virtual int ReqQryNetOIDTopic(CShfeFtdcReqQryNetOIDField *pReqQryNetOID, int nRequestID);

	///时间策略
	virtual int ReqQryNetTimePolicyTopic(CShfeFtdcReqQryNetTimePolicyField *pReqQryNetTimePolicy, int nRequestID);

	///采集任务查询
	virtual int ReqQryNetGatherTaskTopic(CShfeFtdcReqQryNetGatherTaskField *pReqQryNetGatherTask, int nRequestID);

	///设备变更请求
	virtual int ReqQryNetDeviceChgTopic(CShfeFtdcReqQryNetDeviceChgField *pReqQryNetDeviceChg, int nRequestID);

	///常用设备型号请求
	virtual int ReqQryNetDeviceTypeTopic(CShfeFtdcReqQryNetDeviceTypeField *pReqQryNetDeviceType, int nRequestID);

	///常用设备类别请求
	virtual int ReqQryNetDeviceCategoryTopic(CShfeFtdcReqQryNetDeviceCategoryField *pReqQryNetDeviceCategory, int nRequestID);

	///设备厂商请求
	virtual int ReqQryNetManufactoryTopic(CShfeFtdcReqQryNetManufactoryField *pReqQryNetManufactory, int nRequestID);

	///设备共同体请求
	virtual int ReqQryNetCommunityTopic(CShfeFtdcReqQryNetCommunityField *pReqQryNetCommunity, int nRequestID);

	///端口类型请求
	virtual int ReqQryNetPortTypeTopic(CShfeFtdcReqQryNetPortTypeField *pReqQryNetPortType, int nRequestID);

	///会员接入地点请求
	virtual int ReqQryNetPartAccessSpotTopic(CShfeFtdcReqQryNetPartAccessSpotField *pReqQryNetPartAccessSpot, int nRequestID);

	///端口请求
	virtual int ReqQryNetInterfaceTopic(CShfeFtdcReqQryNetInterfaceField *pReqQryNetInterface, int nRequestID);

	///GeneralOID请求
	virtual int ReqQryNetGeneralOIDTopic(CShfeFtdcReqQryNetGeneralOIDField *pReqQryNetGeneralOID, int nRequestID);

	///监控对象类别
	virtual int ReqQryNetMonitorTypeTopic(CShfeFtdcReqQryNetMonitorTypeField *pReqQryNetMonitorType, int nRequestID);

	///指标统表
	virtual int ReqQryNetMonitorAttrScopeTopic(CShfeFtdcReqQryNetMonitorAttrScopeField *pReqQryNetMonitorAttrScope, int nRequestID);

	///监控指标表
	virtual int ReqQryNetMonitorAttrTypeTopic(CShfeFtdcReqQryNetMonitorAttrTypeField *pReqQryNetMonitorAttrType, int nRequestID);

	///监控对象指标表
	virtual int ReqQryNetMonitorObjectAttrTopic(CShfeFtdcReqQryNetMonitorObjectAttrField *pReqQryNetMonitorObjectAttr, int nRequestID);

	///职能区
	virtual int ReqQryNetFuncAreaTopic(CShfeFtdcReqQryNetFuncAreaField *pReqQryNetFuncArea, int nRequestID);

	///监控指令表
	virtual int ReqQryNetMonitorCommandTypeTopic(CShfeFtdcReqQryNetMonitorCommandTypeField *pReqQryNetMonitorCommandType, int nRequestID);

	///动作族表
	virtual int ReqQryNetMonitorActionGroupTopic(CShfeFtdcReqQryNetMonitorActionGroupField *pReqQryNetMonitorActionGroup, int nRequestID);

	///设备对象组表
	virtual int ReqQryNetMonitorDeviceGroupTopic(CShfeFtdcReqQryNetMonitorDeviceGroupField *pReqQryNetMonitorDeviceGroup, int nRequestID);

	///任务信息表
	virtual int ReqQryNetMonitorTaskInfoTopic(CShfeFtdcReqQryNetMonitorTaskInfoField *pReqQryNetMonitorTaskInfo, int nRequestID);

	///任务结果表
	virtual int ReqQryNetMonitorTaskResultTopic(CShfeFtdcReqQryNetMonitorTaskResultField *pReqQryNetMonitorTaskResult, int nRequestID);

	///任务对象集
	virtual int ReqQryNetMonitorTaskObjectSetTopic(CShfeFtdcReqQryNetMonitorTaskObjectSetField *pReqQryNetMonitorTaskObjectSet, int nRequestID);

	///会员链路信息表
	virtual int ReqQryNetPartyLinkInfoTopic(CShfeFtdcReqQryNetPartyLinkInfoField *pReqQryNetPartyLinkInfo, int nRequestID);

	///监控动作指标对照表
	virtual int ReqQryNetMonitorActionAttrTopic(CShfeFtdcReqQryNetMonitorActionAttrField *pReqQryNetMonitorActionAttr, int nRequestID);

	///模块
	virtual int ReqQryNetModuleTopic(CShfeFtdcReqQryNetModuleField *pReqQryNetModule, int nRequestID);

	///告警表达式信息表
	virtual int ReqQryNetEventExprTopic(CShfeFtdcReqQryNetEventExprField *pReqQryNetEventExpr, int nRequestID);

	///事件类型
	virtual int ReqQryNetEventTypeTopic(CShfeFtdcReqQryNetEventTypeField *pReqQryNetEventType, int nRequestID);

	///事件子类型
	virtual int ReqQryNetSubEventTypeTopic(CShfeFtdcReqQryNetSubEventTypeField *pReqQryNetSubEventType, int nRequestID);

	///事件级别
	virtual int ReqQryNetEventLevelTopic(CShfeFtdcReqQryNetEventLevelField *pReqQryNetEventLevel, int nRequestID);

	///任务结果状态表
	virtual int ReqQryNetMonitorTaskStatusResultTopic(CShfeFtdcReqQryNetMonitorTaskStatusResultField *pReqQryNetMonitorTaskStatusResult, int nRequestID);

	///登陆配置服务的请求
	virtual int ReqConfigLoginTopic(CShfeFtdcReqConfigLoginField *pReqConfigLogin, int nRequestID);

	///告知服务，让其退出
	virtual int ReqSysServerExitTopic(CShfeFtdcReqSysServerExitField *pReqSysServerExit, int nRequestID);

	///设备配置表
	virtual int ReqQryNetCfgFileTopic(CShfeFtdcReqQryNetCfgFileField *pReqQryNetCfgFile, int nRequestID);

	///任务结果规则分析表
	virtual int ReqQryNetMonitorDeviceTaskTopic(CShfeFtdcReqQryNetMonitorDeviceTaskField *pReqQryNetMonitorDeviceTask, int nRequestID);

	///任务指令指标集表
	virtual int ReqQryNetMonitorTaskInstAttrsTopic(CShfeFtdcReqQryNetMonitorTaskInstAttrsField *pReqQryNetMonitorTaskInstAttrs, int nRequestID);

	///文件通用操作
	virtual int ReqQryFileGeneralOperTopic(CShfeFtdcReqQryFileGeneralOperField *pReqQryFileGeneralOper, int nRequestID);

	///基线表
	virtual int ReqQryNetBaseLineTopic(CShfeFtdcReqQryNetBaseLineField *pReqQryNetBaseLine, int nRequestID);

	///基线任务表
	virtual int ReqQryNetBaseLineTaskTopic(CShfeFtdcReqQryNetBaseLineTaskField *pReqQryNetBaseLineTask, int nRequestID);

	///基线结果表
	virtual int ReqQryNetBaseLineResultTopic(CShfeFtdcReqQryNetBaseLineResultField *pReqQryNetBaseLineResult, int nRequestID);

	///会员链路状态信息表
	virtual int ReqQryNetPartyLinkStatusInfoTopic(CShfeFtdcReqQryNetPartyLinkStatusInfoField *pReqQryNetPartyLinkStatusInfo, int nRequestID);

	///会员SDH线路明细表
	virtual int ReqQryNetMemberSDHLineInfoTopic(CShfeFtdcReqQryNetMemberSDHLineInfoField *pReqQryNetMemberSDHLineInfo, int nRequestID);

	///DDN链路信息表
	virtual int ReqQryNetDDNLinkInfoTopic(CShfeFtdcReqQryNetDDNLinkInfoField *pReqQryNetDDNLinkInfo, int nRequestID);

	///非会员线路使用信息
	virtual int ReqQryNetPseudMemberLinkInfoTopic(CShfeFtdcReqQryNetPseudMemberLinkInfoField *pReqQryNetPseudMemberLinkInfo, int nRequestID);

	///远端设备信息
	virtual int ReqQryOuterDeviceInfTopic(CShfeFtdcReqQryOuterDeviceInfField *pReqQryOuterDeviceInf, int nRequestID);

	///本地ping结果
	virtual int ReqQryNetLocalPingResultInfoTopic(CShfeFtdcReqQryNetLocalPingResultInfoField *pReqQryNetLocalPingResultInfo, int nRequestID);

	///远程ping结果
	virtual int ReqQryNetRomotePingResultInfoTopic(CShfeFtdcReqQryNetRomotePingResultInfoField *pReqQryNetRomotePingResultInfo, int nRequestID);

	///系统内部级联关系
	virtual int ReqQrySysInternalTopologyTopic(CShfeFtdcReqQrySysInternalTopologyField *pReqQrySysInternalTopology, int nRequestID);

	///请求会员链路费用表
	virtual int ReqQryMemberLinkCostTopic(CShfeFtdcReqQryMemberLinkCostField *pReqQryMemberLinkCost, int nRequestID);

	///请求会员链路月租表
	virtual int ReqQryNetPartylinkMonthlyRentTopic(CShfeFtdcReqQryNetPartylinkMonthlyRentField *pReqQryNetPartylinkMonthlyRent, int nRequestID);

	///请求非会员链路表信息
	virtual int ReqQryNetNonPartyLinkInfoTopic(CShfeFtdcReqQryNetNonPartyLinkInfoField *pReqQryNetNonPartyLinkInfo, int nRequestID);

	///请求配置信息
	virtual int ReqQryMonConfigInfo(CShfeFtdcReqQryMonConfigInfoField *pReqQryMonConfigInfo, int nRequestID);

	///服务连接请求
	virtual int ReqMonServiceConnect(CShfeFtdcReqMonServiceConnectField *pReqMonServiceConnect, int nRequestID);

	///服务的当前状态查询
	virtual int ReqQryMonServiceStatus(CShfeFtdcReqQryMonServiceStatusField *pReqQryMonServiceStatus, int nRequestID);

	///探针任务配置查询请求
	virtual int ReqQryMonProbeTask(CShfeFtdcReqQryMonProbeTaskField *pReqQryMonProbeTask, int nRequestID);

	///监控系统指标查询请求
	virtual int ReqQryMonObjectAttr(CShfeFtdcReqQryMonObjectAttrField *pReqQryMonObjectAttr, int nRequestID);

	///监控系统Syslog事件查询请求
	virtual int ReqQryMonSyslogEvent(CShfeFtdcReqQryMonSyslogEventField *pReqQryMonSyslogEvent, int nRequestID);

	///文件读取偏移量查询请求
	virtual int ReqQryMonFileOffset(CShfeFtdcReqQryMonFileOffsetField *pReqQryMonFileOffset, int nRequestID);

	///文件内容查询请求
	virtual int ReqQryMonFileContent(CShfeFtdcReqQryMonFileContentField *pReqQryMonFileContent, int nRequestID);

	///主机基础环境信息查询请求
	virtual int ReqQryMonHostBasicEnv(CShfeFtdcReqQryMonHostBasicEnvField *pReqQryMonHostBasicEnv, int nRequestID);

	///主机基础网络信息查询
	virtual int ReqQryMonHostNetworkEnv(CShfeFtdcReqQryMonHostNetworkEnvField *pReqQryMonHostNetworkEnv, int nRequestID);

	///主机文件系统信息查询
	virtual int ReqQryMonHostFileSysEnv(CShfeFtdcReqQryMonHostFileSysEnvField *pReqQryMonHostFileSysEnv, int nRequestID);

	///主机交换分区信息查询
	virtual int ReqQryMonHostSwapEnv(CShfeFtdcReqQryMonHostSwapEnvField *pReqQryMonHostSwapEnv, int nRequestID);

	///主机的CPU信息指标信息请求
	virtual int ReqQryMonHostCPUAttr(CShfeFtdcReqQryMonHostCPUAttrField *pReqQryMonHostCPUAttr, int nRequestID);

	///主机的Memory使用信息请求
	virtual int ReqQryMonHostMemAttr(CShfeFtdcReqQryMonHostMemAttrField *pReqQryMonHostMemAttr, int nRequestID);

	///主机的FileSystem使用信息请求
	virtual int ReqQryMonHostFileSystemAttr(CShfeFtdcReqQryMonHostFileSystemAttrField *pReqQryMonHostFileSystemAttr, int nRequestID);

	///主机的用户信息请求
	virtual int ReqQryMonHostUserInfo(CShfeFtdcReqQryMonHostUserInfoField *pReqQryMonHostUserInfo, int nRequestID);

	///主机的在线用户信息请求
	virtual int ReqQryMonHostOnlineUserInfo(CShfeFtdcReqQryMonHostOnlineUserInfoField *pReqQryMonHostOnlineUserInfo, int nRequestID);

	///主机的network使用信息请求
	virtual int ReqQryMonHostNetworkAttr(CShfeFtdcReqQryMonHostNetworkAttrField *pReqQryMonHostNetworkAttr, int nRequestID);

	///主机的系统状态信息请求
	virtual int ReqQryMonHostStatInfo(CShfeFtdcReqQryMonHostStatInfoField *pReqQryMonHostStatInfo, int nRequestID);

	///主机的磁盘IO信息请求
	virtual int ReqQryMonHostDiskIOAttr(CShfeFtdcReqQryMonHostDiskIOAttrField *pReqQryMonHostDiskIOAttr, int nRequestID);

	///主机的路由信息请求
	virtual int ReqQryMonHostRouterInfo(CShfeFtdcReqQryMonHostRouterInfoField *pReqQryMonHostRouterInfo, int nRequestID);

	///主机的进程信息请求
	virtual int ReqQryMonHostProcessInfo(CShfeFtdcReqQryMonHostProcessInfoField *pReqQryMonHostProcessInfo, int nRequestID);

	///客户端临时SP查询请求
	virtual int ReqQryMonSPQuery(CShfeFtdcReqQryMonSPQueryField *pReqQryMonSPQuery, int nRequestID);

	///服务版本信息请求
	virtual int ReqServiceVersion(CShfeFtdcReqServiceVersionField *pReqServiceVersion, int nRequestID);

	///服务应用程序请求
	virtual int ReqServiceProgram(CShfeFtdcReqServiceProgramField *pReqServiceProgram, int nRequestID);

	///升级服务获取状态
	virtual int ReqUpdateState(CShfeFtdcReqUpdateStateField *pReqUpdateState, int nRequestID);

	///订阅请求
	virtual int ReqSubscribe(CShfeFtdcReqSubscribeField *pReqSubscribe, int nRequestID);

	///取消订阅请求
	virtual int ReqCancelSubscribe(CShfeFtdcReqSubscribeField *pReqSubscribe, int nRequestID);

	///用于通知目标服务文件已发送成功
	virtual int ReqFileSendSuccess(CShfeFtdcReqFileSendSuccessField *pReqFileSendSuccess, int nRequestID);

	///tomcat信息查询
	virtual int ReqQryMonTomcatInfo(CShfeFtdcReqQryMonTomcatInfoField *pReqQryMonTomcatInfo, int nRequestID);

	///虚拟机信息查询
	virtual int ReqQryMonVMInfo(CShfeFtdcReqQryMonVMInfoField *pReqQryMonVMInfo, int nRequestID);

	///系统属性信息查询
	virtual int ReqQryMonPropertyInfo(CShfeFtdcReqQryMonPropertyInfoField *pReqQryMonPropertyInfo, int nRequestID);

	///系统内存池信息查询
	virtual int ReqQryMonMemPoolInfo(CShfeFtdcReqQryMonMemPoolInfoField *pReqQryMonMemPoolInfo, int nRequestID);

	///连接信息查询
	virtual int ReqQryMonConnectionInfo(CShfeFtdcReqQryMonConnectionInfoField *pReqQryMonConnectionInfo, int nRequestID);

	///无效报单查询
	virtual int ReqQryInvalidateOrderTopic(CShfeFtdcReqQryInvalidateOrderField *pReqQryInvalidateOrder, int nRequestID);

	///报单状态查询
	virtual int ReqQryOrderStatusTopic(CShfeFtdcReqQryOrderStatusField *pReqQryOrderStatus, int nRequestID);

	///报单成交查询
	virtual int ReqQryBargainOrderTopic(CShfeFtdcReqQryBargainOrderField *pReqQryBargainOrder, int nRequestID);

	///合约基本属性查询
	virtual int ReqQryInstPropertyTopic(CShfeFtdcReqQryInstPropertyField *pReqQryInstProperty, int nRequestID);

	///合约保证金率查询
	virtual int ReqQryMarginRateTopic(CShfeFtdcReqQryMarginRateField *pReqQryMarginRate, int nRequestID);

	///合约涨跌停板查询
	virtual int ReqQryPriceLimitTopic(CShfeFtdcReqQryPriceLimitField *pReqQryPriceLimit, int nRequestID);

	///会员限仓查询
	virtual int ReqQryPartPosiLimitTopic(CShfeFtdcReqQryPartPosiLimitField *pReqQryPartPosiLimit, int nRequestID);

	///客户限仓查询
	virtual int ReqQryClientPosiLimitTopic(CShfeFtdcReqQryClientPosiLimitField *pReqQryClientPosiLimit, int nRequestID);

	///特殊客户限仓查询
	virtual int ReqQrySpecialPosiLimitTopic(CShfeFtdcReqQrySpecialPosiLimitField *pReqQrySpecialPosiLimit, int nRequestID);

	///账户出入金查询
	virtual int ReqQryTransactionChgTopic(CShfeFtdcReqQryTransactionChgField *pReqQryTransactionChg, int nRequestID);

	///客户数据变动查询
	virtual int ReqQryClientChgTopic(CShfeFtdcReqQryClientChgField *pReqQryClientChg, int nRequestID);

	///会员客户对照变动查询
	virtual int ReqQryPartClientChgTopic(CShfeFtdcReqQryPartClientChgField *pReqQryPartClientChg, int nRequestID);

	///限仓数据变动查询
	virtual int ReqQryPosiLimitChgTopic(CShfeFtdcReqQryPosiLimitChgField *pReqQryPosiLimitChg, int nRequestID);

	///保值额度变动查询
	virtual int ReqQryHedgeDetailChgTopic(CShfeFtdcReqQryHedgeDetailChgField *pReqQryHedgeDetailChg, int nRequestID);

	///会员变动查询
	virtual int ReqQryParticipantChgTopic(CShfeFtdcReqQryParticipantChgField *pReqQryParticipantChg, int nRequestID);

	///保证金率变动查询
	virtual int ReqQryMarginRateChgTopic(CShfeFtdcReqQryMarginRateChgField *pReqQryMarginRateChg, int nRequestID);

	///IP地址变动查询
	virtual int ReqQryUserIpChgTopic(CShfeFtdcReqQryUserIpChgField *pReqQryUserIpChg, int nRequestID);

	///限仓数据变动查询
	virtual int ReqQryClientPosiLimitChgTopic(CShfeFtdcReqQryClientPosiLimitChgField *pReqQryClientPosiLimitChg, int nRequestID);

	///限仓数据变动查询
	virtual int ReqQrySpecPosiLimitChgTopic(CShfeFtdcReqQrySpecPosiLimitChgField *pReqQrySpecPosiLimitChg, int nRequestID);

	///交易系统前置统计查询
	virtual int ReqQryFrontStatTopic(CShfeFtdcReqQryFrontStatField *pReqQryFrontStat, int nRequestID);

	///管理平台初始化信息查询
	virtual int ReqQryParticipantInitTopic(CShfeFtdcReqQryParticipantInitField *pReqQryParticipantInit, int nRequestID);

	///管理平台初始化信息查询
	virtual int ReqQryUserInitTopic(CShfeFtdcReqQryUserInitField *pReqQryUserInit, int nRequestID);

	///请求约状态切换数据
	virtual int ReqQryInstrumentStatusTopic(CShfeFtdcReqQryInstrumentStatusField *pReqQryInstrumentStatus, int nRequestID);

	///请求合约交易节信息
	virtual int ReqQryCurrTradingSegmentAttrTopic(CShfeFtdcReqQryCurrTradingSegmentAttrField *pReqQryCurrTradingSegmentAttr, int nRequestID);

	///交易系统登录信息查询
	virtual int ReqQryTradeUserLoginInfoTopic(CShfeFtdcReqQryTradeUserLoginInfoField *pReqQryTradeUserLoginInfo, int nRequestID);

	///会员交易查询
	virtual int ReqQryPartTradeTopic(CShfeFtdcReqQryPartTradeField *pReqQryPartTrade, int nRequestID);

	///会员席位交易状态
	virtual int ReqQryParticTradeOrderStatesTopic(CShfeFtdcReqQryParticTradeOrderStatesField *pReqQryParticTradeOrderStates, int nRequestID);

	///获得监控对象信息查询
	virtual int ReqQryMonitor2ObjectTopic(CShfeFtdcReqQryMonitor2ObjectField *pReqQryMonitor2Object, int nRequestID);

	///主机环境信息查询
	virtual int ReqQryMonHostCommonEnvTopic(CShfeFtdcReqQryMonHostCommonEnvField *pReqQryMonHostCommonEnv, int nRequestID);

	///获取业务进程和主机关系
	virtual int ReqQryMonOidHostRationalTopic(CShfeFtdcReqQryMonOidHostRationalField *pReqQryMonOidHostRational, int nRequestID);

	///对象关系查询
	virtual int ReqQryMonOidRelationTopic(CShfeFtdcReqQryMonOidRelationField *pReqQryMonOidRelation, int nRequestID);
private:
	///错误应答
	void OnRspError(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户登录应答
	void OnRspUserLogin(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户退出应答
	void OnRspUserLogout(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单录入应答
	void OnRspOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单操作应答
	void OnRspOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报价录入应答
	void OnRspQuoteInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报价操作应答
	void OnRspQuoteAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///OTC报单录入应答
	void OnRspOTCOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户密码修改应答
	void OnRspUserPasswordUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///执行宣告录入应答
	void OnRspExecOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///执行宣告操作应答
	void OnRspExecOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///管理报单录入应答
	void OnRspAdminOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///非标组合报单录入应答
	void OnRspCombOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅主题应答
	void OnRspSubscribeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易所公告请求应答
	void OnRspBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易所公告信息应答
	void OnRspInformation(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约交易状态改变应答
	void OnRspInstrumentStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///强制用户退出应答
	void OnRspForceUserExit(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户会话删除应答
	void OnRspForceUserLogout(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易所数据同步状态改变应答
	void OnRspExchangeDataSyncStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///结算组数据同步状态改变应答
	void OnRspSGDataSyncStatusUpdate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员资金查询应答
	void OnRspQryPartAccount(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单查询应答
	void OnRspQryOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报价查询应答
	void OnRspQryQuote(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///成交单查询应答
	void OnRspQryTrade(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员客户查询应答
	void OnRspQryClient(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员持仓查询应答
	void OnRspQryPartPosition(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///客户持仓查询应答
	void OnRspQryClientPosition(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约查询应答
	void OnRspQryInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约交易状态查询应答
	void OnRspQryInstrumentStatus(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///结算组状态查询应答
	void OnRspQrySGDataSyncStatus(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///保值额度应答
	void OnRspQryHedgeVolume(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///信用限额查询应答
	void OnRspQryCreditLimit(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///非标组合报单查询应答
	void OnRspQryCombOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///执行宣告查询应答
	void OnRspQryExecOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///普通行情查询应答
	void OnRspQryMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易所公告查询请求应答
	void OnRspQryBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主题查询应答
	void OnRspQryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户在线查询应答
	void OnRspQryUserSession(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户查询应答
	void OnRspQryUser(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员查询应答
	void OnRspQryParticipant(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约价位查询应答
	void OnRspQryMBLMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///信息查询应答
	void OnRspQryInformation(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///成交回报
	void OnRtnTrade(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单回报
	void OnRtnOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///执行宣告回报
	void OnRtnExecOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报价回报
	void OnRtnQuote(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///非标组合报单回报
	void OnRtnCombOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约交易状态通知
	void OnRtnInstrumentStatus(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///增加合约通知
	void OnRtnInsInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///删除合约通知
	void OnRtnDelInstrument(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///增加合约单腿通知
	void OnRtnInsCombinationLeg(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///删除合约单腿通知
	void OnRtnDelCombinationLeg(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///别名定义通知
	void OnRtnAliasDefine(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///数据流回退通知
	void OnRtnFlowMessageCancel(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///公告通知
	void OnRtnBulletin(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///普通行情通知
	void OnRtnMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///深度行情通知
	void OnRtnDepthMarketData(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///管理报单通知
	void OnRtnAdminOrder(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单录入错误回报
	void OnErrRtnOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单操作错误回报
	void OnErrRtnOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报价录入错误回报
	void OnErrRtnQuoteInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报价操作错误回报
	void OnErrRtnQuoteAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///执行宣告录入错误回报
	void OnErrRtnExecOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///执行宣告操作错误回报
	void OnErrRtnExecOrderAction(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///非标组合报单录入错误回报
	void OnErrRtnCombOrderInsert(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///汇率查询应答
	void OnRspQryExchangeRate(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///CPU应答
	void OnRspQryTopCpuInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///CPU应答
	void OnRtnTopCpuInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Mem应答
	void OnRspQryTopMemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Mem应答
	void OnRtnTopMemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///process应答
	void OnRspQryTopProcessInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///process应答
	void OnRtnTopProcessInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///filesystem应答
	void OnRspQryFileSystemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///filesystem应答
	void OnRtnFileSystemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///network应答
	void OnRspQryNetworkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///network应答
	void OnRtnNetworkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///客户端登录应答
	void OnRspQryClientLoginTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///获得监控对象信息应答
	void OnRspQryMonitorObjectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///获得监控对象信息应答
	void OnRtnMonitorObjectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///获得业务进程和主机的对应关系应答
	void OnRspQryObjectRationalTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///获得业务进程和主机的对应关系应答
	void OnRtnObjectRationalTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///日志文件内容应答
	void OnRspQrySyslogInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///日志文件内容应答
	void OnRtnSyslogInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控内容订阅应答
	void OnRspQrySubscriberTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///对象关系查询应答
	void OnRspQryOidRelationTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///对象关系查询应答
	void OnRtnOidRelationTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户信息查询请求应答
	void OnRspQryUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户信息查询请求应答
	void OnRtnUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///在线用户信息查询请求应答
	void OnRspQryOnlineUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///在线用户信息查询请求应答
	void OnRtnOnlineUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///告警事件查询请求应答
	void OnRspQryWarningEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///告警事件查询请求应答
	void OnRtnWarningEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///CPU使用率查询请求应答
	void OnRspQryCPUUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///CPU使用率查询请求应答
	void OnRtnCPUUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///内存使用率查询请求应答
	void OnRspQryMemoryUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///内存使用率查询请求应答
	void OnRtnMemoryUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///硬盘使用率查询请求应答
	void OnRspQryDiskUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///硬盘使用率查询请求应答
	void OnRtnDiskUsageTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///对象状态指标查询应答
	void OnRspQryObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///对象状态指标查询应答
	void OnRtnObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///历史对象状态指标查询应答
	void OnRspQryHistoryObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///历史对象状态指标查询应答
	void OnRtnHistoryObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///前置响应信息查询应答
	void OnRspQryFrontInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///前置响应信息查询应答
	void OnRtnFrontInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户登录应答
	void OnRspQrySysUserLoginTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户登出应答
	void OnRspQrySysUserLogoutTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户修改密码应答
	void OnRspQrySysUserPasswordUpdateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///注册用户应答
	void OnRspQrySysUserRegisterTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///删除用户应答
	void OnRspQrySysUserDeleteTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///客户初始化应答
	void OnRspQryClientInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///客户初始化应答
	void OnRtnClientInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易日志查询应答
	void OnRspQryTradeLogTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易日志查询应答
	void OnRtnTradeLogTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易峰值查询应答
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
	
	///HostConfig查询请求应答
	void OnRspQryHostConfig(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控系统在线用户应答
	void OnRspQryMonitorOnlineUser(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控系统时钟同步
	void OnRtnSysTimeSyncTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///数据中心切换通知
	void OnRtnDataCenterChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///历史峰值查询应答
	void OnRspQryHistoryTradePeakTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///历史峰值查询应答
	void OnRtnHistoryTradePeakTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///日志事件查询应答
	void OnRspQrySyslogEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///日志事件应答
	void OnRtnSyslogEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易日切换通知
	void OnRspQryTradeDayChangeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Web应用信息
	void OnRspQryWebAppInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Web应用信息
	void OnRtnWebAppInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应用servlet信息
	void OnRspQryServletInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应用servlet信息
	void OnRtnServletInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件信息
	void OnRspQryFileInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件信息
	void OnRtnFileInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应用会话信息
	void OnRspQrySessionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应用会话信息
	void OnRtnSessionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///JDBC信息
	void OnRspQryJDBCInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///JDBC信息
	void OnRtnJDBCInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///线程信息
	void OnRspQryThreadInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///线程信息
	void OnRtnThreadInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///虚拟机信息
	void OnRspQryVMInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///虚拟机信息
	void OnRtnVMInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统属性信息
	void OnRspQryPropertyInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统属性信息
	void OnRtnPropertyInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统内存池信息
	void OnRspQryMemPoolInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统内存池信息
	void OnRtnMemPoolInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件内容信息
	void OnRspQryFileContentInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件内容信息
	void OnRtnFileContentInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///连接信息
	void OnRspQryConnectionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///连接信息
	void OnRtnConnectionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///连接器信息
	void OnRspQryConnectorInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///连接器信息
	void OnRtnConnectorInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///数据库查询应答
	void OnRspQryDBQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///数据库查询应答
	void OnRtnDBQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///通用返回应答
	void OnRspQryGeneralFieldTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///通用返回应答
	void OnRtnGeneralFieldTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件传输应答
	void OnRspQryGetFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///告警明细
	void OnRspQryWarningQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///告警明细
	void OnRtnWarningQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///HostConfig订阅应答
	void OnRtnHostConfig(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///告警激活变更
	void OnRspQryWarningActiveChange(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///告警激活变更
	void OnRtnWarningActiveChange(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///通用操作
	void OnRspQryGeneralOperateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///通用操作
	void OnRtnGeneralOperateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络设备连接关系
	void OnRspQryNetDeviceLinkedTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络设备连接关系
	void OnRtnNetDeviceLinkedTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易系统登录信息
	void OnRspQryTradeUserLoginStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易系统前置报单响应信息
	void OnRspQryTradeFrontOrderRttStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易系统前置报单响应信息
	void OnRtnTradeFrontOrderRttStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统路由信息
	void OnRspQryRouterInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统路由信息
	void OnRtnRouterInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///磁盘I/O信息
	void OnRspQryDiskIOTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///磁盘I/O信息
	void OnRtnDiskIOTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统状态信息
	void OnRspQryStatInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统状态信息
	void OnRtnStatInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易系统前置报单分布区间
	void OnRspQryTradeOrderRttCutLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易系统前置报单分布区间
	void OnRtnTradeOrderRttCutLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员客户信息
	void OnRspQryClientInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员客户信息
	void OnRtnClientInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应答事件描述
	void OnRspQryEventDescriptionTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅事件描述
	void OnRtnEventDescriptionTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应答前置唯一ID信息
	void OnRspQryFrontUniqueIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅前置唯一ID信息
	void OnRtnFrontUniqueIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员线路地址变更回应
	void OnRspQryNetPartyLinkAddrChangeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅会员线路地址变更信息
	void OnRtnNetPartyLinkAddrChangeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应答已删除会员列表信息
	void OnRspQryNetDelPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅已删除会员列表信息
	void OnRtnNetDelPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///返回网络性能排序
	void OnRspQryPerformanceTopTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅网络性能排序
	void OnRtnPerformanceTopTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络大区划分应答
	void OnRspQryNetAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络大区划分应答
	void OnRtnNetAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络子区应答
	void OnRspQryNetSubAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络子区应答
	void OnRtnNetSubAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络子区IP应答
	void OnRspQryNetSubAreaIPTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络子区IP应答
	void OnRtnNetSubAreaIPTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络设备
	void OnRspQryNetDeviceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络设备
	void OnRtnNetDeviceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络设备探测请求应答
	void OnRspQryNetDeviceDetectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///大楼
	void OnRspQryNetBuildingTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///大楼
	void OnRtnNetBuildingTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///机房
	void OnRspQryNetRoomTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///机房
	void OnRtnNetRoomTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///机柜
	void OnRspQryNetCabinetsTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///机柜
	void OnRtnNetCabinetsTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///OID
	void OnRspQryNetOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///OID
	void OnRtnNetOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///时间策略
	void OnRspQryNetTimePolicyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///时间策略
	void OnRtnNetTimePolicyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///采集任务
	void OnRspQryNetGatherTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///采集任务
	void OnRtnNetGatherTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备变更
	void OnRspQryNetDeviceChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备变更
	void OnRtnNetDeviceChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///常用设备型号
	void OnRspQryNetDeviceTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///常用设备型号
	void OnRtnNetDeviceTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///常用设备类别
	void OnRspQryNetDeviceCategoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///常用设备类别
	void OnRtnNetDeviceCategoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备厂商
	void OnRspQryNetManufactoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备厂商
	void OnRtnNetManufactoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备共同体
	void OnRspQryNetCommunityTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备共同体
	void OnRtnNetCommunityTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///端口类型
	void OnRspQryNetPortTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///端口类型
	void OnRtnNetPortTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员接入地点
	void OnRspQryNetPartAccessSpotTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员接入地点
	void OnRtnNetPartAccessSpotTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///端口
	void OnRspQryNetInterfaceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///端口
	void OnRtnNetInterfaceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///GeneralOID
	void OnRspQryNetGeneralOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///GeneralOID
	void OnRtnNetGeneralOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控对象类别
	void OnRspQryNetMonitorTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控对象类别
	void OnRtnNetMonitorTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///指标统表
	void OnRspQryNetMonitorAttrScopeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///指标统表
	void OnRtnNetMonitorAttrScopeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控指标表
	void OnRspQryNetMonitorAttrTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控指标表
	void OnRtnNetMonitorAttrTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控对象指标表
	void OnRspQryNetMonitorObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控对象指标表
	void OnRtnNetMonitorObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///职能区
	void OnRspQryNetFuncAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///职能区
	void OnRtnNetFuncAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控指令表
	void OnRspQryNetMonitorCommandTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控指令表
	void OnRtnNetMonitorCommandTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///动作族表
	void OnRspQryNetMonitorActionGroupTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///动作族表
	void OnRtnNetMonitorActionGroupTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备对象组表
	void OnRspQryNetMonitorDeviceGroupTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备对象组表
	void OnRtnNetMonitorDeviceGroupTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务信息表
	void OnRspQryNetMonitorTaskInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务信息表
	void OnRtnNetMonitorTaskInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务结果表
	void OnRspQryNetMonitorTaskResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务结果表
	void OnRtnNetMonitorTaskResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务对象集
	void OnRspQryNetMonitorTaskObjectSetTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务对象集
	void OnRtnNetMonitorTaskObjectSetTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员链路信息表
	void OnRspQryNetPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员链路信息表
	void OnRtnNetPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控动作指标对照表
	void OnRspQryNetMonitorActionAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控动作指标对照表
	void OnRtnNetMonitorActionAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///模块
	void OnRspQryNetModuleTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///模块
	void OnRtnNetModuleTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///告警表达式信息表
	void OnRspQryNetEventExprTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///告警表达式信息表
	void OnRtnNetEventExprTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///事件类型
	void OnRspQryNetEventTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///事件类型
	void OnRtnNetEventTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///事件子类型
	void OnRspQryNetSubEventTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///事件子类型
	void OnRtnNetSubEventTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///事件级别
	void OnRspQryNetEventLevelTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///事件级别
	void OnRtnNetEventLevelTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务结果状态表
	void OnRspQryNetMonitorTaskStatusResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务结果状态表
	void OnRtnNetMonitorTaskStatusResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///配置服务对登陆的响应
	void OnRspConfigLoginTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///对当前登录配置的服务角色的响应
	void OnRspServerTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备配置表
	void OnRspQryNetCfgFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备配置表
	void OnRtnNetCfgFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务结果规则分析表
	void OnRspQryNetMonitorDeviceTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务结果规则分析表
	void OnRtnNetMonitorDeviceTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务指令指标集表
	void OnRspQryNetMonitorTaskInstAttrsTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务指令指标集表
	void OnRtnNetMonitorTaskInstAttrsTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件通用操作
	void OnRspQryFileGeneralOperTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件通用操作
	void OnRtnFileGeneralOperTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///基线表
	void OnRspQryNetBaseLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///基线表
	void OnRtnNetBaseLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///基线任务表
	void OnRspQryNetBaseLineTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///基线任务表
	void OnRtnNetBaseLineTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///基线结果表
	void OnRspQryNetBaseLineResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///基线结果表
	void OnRtnNetBaseLineResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员链路状态信息表
	void OnRspQryNetPartyLinkStatusInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员链路状态信息表
	void OnRtnNetPartyLinkStatusInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员SDH线路明细表
	void OnRspQryNetMemberSDHLineInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员SDH线路明细表
	void OnRtnNetMemberSDHLineInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///DDN链路信息表
	void OnRspQryNetDDNLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///DDN链路信息表
	void OnRtnNetDDNLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///非会员线路使用信息
	void OnRspQryNetPseudMemberLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///非会员线路使用信息
	void OnRtnNetPseudMemberLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///远端设备信息
	void OnRspQryOuterDeviceInfTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///远端设备信息
	void OnRtnNetOuterDeviceInfTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///本地ping结果
	void OnRspQryNetLocalPingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///本地ping结果
	void OnRtnNetLocalPingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///远程ping结果
	void OnRspQryNetRomotePingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///远程ping结果
	void OnRtnNetRomotePingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///进程信息数据库专用
	void OnRtnMonitorTopProcessInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统内部级联关系
	void OnRspQrySysInternalTopologyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统内部级联关系
	void OnRtnSysInternalTopologyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///返回会员链路费用表
	void OnRspQryMemberLinkCostTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅会员链路费用表
	void OnRtnMemberLinkCostTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///返回会员链路月租表
	void OnRspQryNetPartylinkMonthlyRentTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅会员链路月租表
	void OnRtnNetPartylinkMonthlyRentTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///返回非会员链路表信息
	void OnRspQryNetNonPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅非会员链路表信息
	void OnRtnNetNonPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应答配置信息
	void OnRspQryMonConfigInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应答配置信息
	void OnRtnMonConfigInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///通知监控日信息
	void OnRtnMonitorDayInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///通知交易日信息
	void OnRtnTradingDayInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控阶段结束
	void OnRtnSectionFinish(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控阶段切换
	void OnRtnSectionChange(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///服务连接响应
	void OnRspMonServiceConnect(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Proxy或探针名称配置
	void OnRtnMonProxyConfig(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///服务的当前状态响应
	void OnRspQryMonServiceStatus(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///服务的当前状态推送
	void OnRtnMonServiceStatus(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///当前数据中心角色
	void OnRtnMonDataCenterRole(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///探针任务配置查询响应
	void OnRspQryMonProbeTask(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///探针任务配置推送
	void OnRtnMonProbeTask(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控系统指标查询应答
	void OnRspQryMonObjectAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控系统指标查询推送
	void OnRtnMonObjectAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控系统Syslog事件查询应答
	void OnRspQryMonSyslogEvent(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控系统Syslog事件查询推送
	void OnRtnMonSyslogEvent(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件读取偏移量查询应答
	void OnRspQryMonFileOffset(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件读取偏移量查询推送
	void OnRtnMonFileOffset(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件内容查询应答
	void OnRspQryMonFileContent(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件内容通告
	void OnRtnMonFileContent(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机基础环境信息应答
	void OnRspQryMonHostBasicEnv(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机基础环境信息应答
	void OnRtnMonHostBasicEnv(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机基础网络信息应答
	void OnRspQryMonHostNetworkEnv(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机基础网络信息通告
	void OnRtnMonHostNetworkEnv(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机文件系统信息应答
	void OnRspQryMonHostFileSysEnv(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机文件系统信息通告
	void OnRtnMonHostFileSysEnv(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机交换分区信息应答
	void OnRspQryMonHostSwapEnv(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机交换分区信息通告
	void OnRtnMonHostSwapEnv(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的CPU信息指标信息应答
	void OnRspQryMonHostCPUAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的CPU信息指标信息
	void OnRtnMonHostCPUAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的Memory使用信息应答
	void OnRspQryMonHostMemAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的Memory使用信息
	void OnRtnMonHostMemAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的FileSystem使用信息应答
	void OnRspQryMonHostFileSystemAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的FileSystem使用信息
	void OnRtnMonHostFileSystemAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的用户信息应答
	void OnRspQryMonHostUserInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的用户信息
	void OnRtnMonHostUserInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的在线用户信息应答
	void OnRspQryMonHostOnlineUserInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的在线用户信息
	void OnRtnMonHostOnlineUserInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的network使用信息应答
	void OnRspQryMonHostNetworkAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的network使用信息
	void OnRtnMonHostNetworkAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的系统状态信息应答
	void OnRspQryMonHostStatInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的系统状态信息
	void OnRtnMonHostStatInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的磁盘IO信息应答
	void OnRspQryMonHostDiskIOAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的磁盘IO信息
	void OnRtnMonHostDiskIOAttr(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的路由信息应答
	void OnRspQryMonHostRouterInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的路由信息
	void OnRtnMonHostRouterInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的进程信息应答
	void OnRspQryMonHostProcessInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机的进程信息
	void OnRtnMonHostProcessInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///数据库采集的推送报文，包括了SP，DBLog，DBAttr
	void OnRtnMonDBQuery(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///响应客户端临时SP查询请求
	void OnRspQryMonSPQuery(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///服务版本信息响应
	void OnRspServiceVersion(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///服务应用程序响应
	void OnRspServiceProgram(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///升级服务获取状态响应
	void OnRspUpdateState(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅请求应答
	void OnRspSubscribe(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///通知目标服务文件已成功接收
	void OnRspFileSendSuccess(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用于通知目标服务文件已发送成功
	void OnRtnFileSendSuccess(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///tomcat信息应答
	void OnRspQryMonTomcatInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///tomcat信息推送
	void OnRtnMonTomcatInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Web应用信息
	void OnRspQryMonWebAppInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Web应用信息
	void OnRtnMonWebAppInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应用servlet信息
	void OnRspQryMonServletInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应用servlet信息
	void OnRtnMonServletInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件信息
	void OnRspQryMonFileInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件信息
	void OnRtnMonFileInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应用会话信息应答
	void OnRspQryMonSessionInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应用会话信息推送
	void OnRtnMonSessionInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///JDBC信息
	void OnRspQryMonJDBCInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///JDBC信息
	void OnRtnMonJDBCInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///线程信息
	void OnRspQryMonThreadInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///线程信息
	void OnRtnMonThreadInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///虚拟机信息
	void OnRspQryMonVMInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///虚拟机信息
	void OnRtnMonVMInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统属性信息
	void OnRspQryMonPropertyInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统属性信息
	void OnRtnMonPropertyInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统内存池信息
	void OnRspQryMonMemPoolInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统内存池信息
	void OnRtnMonMemPoolInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///连接信息
	void OnRspQryMonConnectionInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///连接信息
	void OnRtnMonConnectionInfo(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///无效报单查询应答
	void OnRspQryInvalidateOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///无效报单查询应答
	void OnRtnInvalidateOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单状态查询应答
	void OnRspQryOrderStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单状态查询应答
	void OnRtnOrderStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单成交查询应答
	void OnRspQryBargainOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单成交查询应答
	void OnRtnBargainOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约基本属性查询应答
	void OnRspQryInstPropertyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约基本属性查询应答
	void OnRtnInstPropertyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约保证金率查询应答
	void OnRspQryMarginRateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约保证金率查询应答
	void OnRtnMarginRateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约涨跌停板查询应答
	void OnRspQryPriceLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约涨跌停板查询应答
	void OnRtnPriceLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员限仓查询应答
	void OnRspQryPartPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员限仓查询应答
	void OnRtnPartPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///客户限仓查询应答
	void OnRspQryClientPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///客户限仓查询应答
	void OnRtnClientPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///特殊客户限仓查询应答
	void OnRspQrySpecialPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///特殊客户限仓查询应答
	void OnRtnSpecialPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///账户出入金查询应答
	void OnRspQryTransactionChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///账户出入金查询应答
	void OnRtnTransactionChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///客户数据变动查询应答
	void OnRspQryClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///客户数据变动查询应答
	void OnRtnClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员客户对照变动查询应答
	void OnRspQryPartClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员客户对照变动查询应答
	void OnRtnPartClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///限仓数据变动查询应答
	void OnRspQryPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///限仓数据变动查询应答
	void OnRtnPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///保值额度变动查询应答
	void OnRspQryHedgeDetailChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///保值额度变动查询应答
	void OnRtnHedgeDetailChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员变动查询应答
	void OnRspQryParticipantChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员变动查询应答
	void OnRtnParticipantChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///保证金率变动查询应答
	void OnRspQryMarginRateChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///保证金率变动查询应答
	void OnRtnMarginRateChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///IP地址变动查询应答
	void OnRspQryUserIpChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///IP地址变动查询应答
	void OnRtnUserIpChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///限仓数据变动查询应答
	void OnRspQryClientPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///限仓数据变动查询应答
	void OnRtnClientPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///限仓数据变动查询应答
	void OnRspQrySpecPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///限仓数据变动查询应答
	void OnRtnSpecPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易系统前置统计应答
	void OnRspQryFrontStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员初始化应答
	void OnRspQryParticipantInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员初始化应答
	void OnRtnParticipantInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///座席初始化应答
	void OnRspQryUserInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///座席初始化应答
	void OnRtnUserInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///返回约状态切换数据
	void OnRspQryInstrumentStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅约状态切换数据
	void OnRtnInstrumentStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///返回合约交易节信息
	void OnRspQryCurrTradingSegmentAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅合约交易节信息
	void OnRtnCurrTradingSegmentAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易系统登录信息
	void OnRspQryTradeUserLoginInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易系统登录信息
	void OnRtnTradeUserLoginInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员交易查询应答
	void OnRspQryPartTradeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员席位交易状态
	void OnRspQryParticTradeOrderStatesTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员席位交易状态
	void OnRtnParticTradeOrderStatesTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///获得监控对象信息应答
	void OnRspQryMonitor2ObjectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///获得监控对象信息应答
	void OnRtnMonitor2ObjectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机环境信息应答
	void OnRspQryMonHostCommonEnvTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///主机环境信息应答
	void OnRtnMonHostCommonEnvTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应答业务进程和主机关系
	void OnRspQryMonOidHostRationalTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///推送业务进程和主机关系
	void OnRtnMonOidHostRationalTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///对象关系查询应答
	void OnRspQryMonOidRelationTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///对象关系查询应答
	void OnRtnMonOidRelationTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
};

#endif
