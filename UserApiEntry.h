
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
	
	///CPU应答
	virtual void OnRspQryTopCpuInfoTopic(CShfeFtdcRspQryTopCpuInfoField *pRspQryTopCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///Mem应答
	virtual void OnRspQryTopMemInfoTopic(CShfeFtdcRspQryTopMemInfoField *pRspQryTopMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///process应答
	virtual void OnRspQryTopProcessInfoTopic(CShfeFtdcRspQryTopProcessInfoField *pRspQryTopProcessInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///filesystem应答
	virtual void OnRspQryFileSystemInfoTopic(CShfeFtdcRspQryFileSystemInfoField *pRspQryFileSystemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///network应答
	virtual void OnRspQryNetworkInfoTopic(CShfeFtdcRspQryNetworkInfoField *pRspQryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///主机环境信息应答
	virtual void OnRspQryHostEnvTopic(CShfeFtdcRspQryHostEnvCommonField *pRspQryHostEnvCommon, CShfeFtdcRspQryHostEnvLanField *pRspQryHostEnvLan, CShfeFtdcRspQryHostEnvStorageField *pRspQryHostEnvStorage, CShfeFtdcRspQryHostEnvIOField *pRspQryHostEnvIO, CShfeFtdcRspQryHostEnvFSField *pRspQryHostEnvFS, CShfeFtdcRspQryHostEnvSwapField *pRspQryHostEnvSwap, CShfeFtdcRspQryHostEnvLanCfgField *pRspQryHostEnvLanCfg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///获得监控对象信息应答
	virtual void OnRspQryMonitorObjectTopic(CShfeFtdcRspQryMonitorObjectField *pRspQryMonitorObject, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///获得业务进程和主机的对应关系应答
	virtual void OnRspQryObjectRationalTopic(CShfeFtdcRspQryObjectRationalField *pRspQryObjectRational, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///日志文件内容应答
	virtual void OnRspQrySyslogInfoTopic(CShfeFtdcRspQrySyslogInfoField *pRspQrySyslogInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///监控内容订阅应答
	virtual void OnRspQrySubscriberTopic(CShfeFtdcRspQrySubscriberField *pRspQrySubscriber, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///对象关系查询应答
	virtual void OnRspQryOidRelationTopic(CShfeFtdcRspQryOidRelationField *pRspQryOidRelation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///用户信息查询请求应答
	virtual void OnRspQryUserInfoTopic(CShfeFtdcRspQryUserInfoField *pRspQryUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///在线用户信息查询请求应答
	virtual void OnRspQryOnlineUserInfoTopic(CShfeFtdcRspQryOnlineUserInfoField *pRspQryOnlineUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///告警事件查询请求应答
	virtual void OnRspQryWarningEventTopic(CShfeFtdcRspQryWarningEventField *pRspQryWarningEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///对象状态指标查询应答
	virtual void OnRspQryObjectAttrTopic(CShfeFtdcRspQryObjectAttrField *pRspQryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///无效报单查询应答
	virtual void OnRspQryInvalidateOrderTopic(CShfeFtdcRspQryInvalidateOrderField *pRspQryInvalidateOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///报单状态查询应答
	virtual void OnRspQryOrderStatusTopic(CShfeFtdcRspQryOrderStatusField *pRspQryOrderStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///报单成交查询应答
	virtual void OnRspQryBargainOrderTopic(CShfeFtdcRspQryBargainOrderField *pRspQryBargainOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///合约基本属性查询应答
	virtual void OnRspQryInstPropertyTopic(CShfeFtdcRspQryInstPropertyField *pRspQryInstProperty, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///合约保证金率查询应答
	virtual void OnRspQryMarginRateTopic(CShfeFtdcRspQryMarginRateField *pRspQryMarginRate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///合约涨跌停板查询应答
	virtual void OnRspQryPriceLimitTopic(CShfeFtdcRspQryPriceLimitField *pRspQryPriceLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///会员限仓查询应答
	virtual void OnRspQryPartPosiLimitTopic(CShfeFtdcRspQryPartPosiLimitField *pRspQryPartPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///客户限仓查询应答
	virtual void OnRspQryClientPosiLimitTopic(CShfeFtdcRspQryClientPosiLimitField *pRspQryClientPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///特殊客户限仓查询应答
	virtual void OnRspQrySpecialPosiLimitTopic(CShfeFtdcRspQrySpecialPosiLimitField *pRspQrySpecialPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///账户出入金查询应答
	virtual void OnRspQryTransactionChgTopic(CShfeFtdcRspQryTransactionChgField *pRspQryTransactionChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///客户数据变动查询应答
	virtual void OnRspQryClientChgTopic(CShfeFtdcRspQryClientChgField *pRspQryClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///会员客户对照变动查询应答
	virtual void OnRspQryPartClientChgTopic(CShfeFtdcRspQryPartClientChgField *pRspQryPartClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///限仓数据变动查询应答
	virtual void OnRspQryPosiLimitChgTopic(CShfeFtdcRspQryPosiLimitChgField *pRspQryPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///保值额度变动查询应答
	virtual void OnRspQryHedgeDetailChgTopic(CShfeFtdcRspQryHedgeDetailChgField *pRspQryHedgeDetailChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///会员变动查询应答
	virtual void OnRspQryParticipantChgTopic(CShfeFtdcRspQryParticipantChgField *pRspQryParticipantChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///保证金率变动查询应答
	virtual void OnRspQryMarginRateChgTopic(CShfeFtdcRspQryMarginRateChgField *pRspQryMarginRateChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///IP地址变动查询应答
	virtual void OnRspQryUserIpChgTopic(CShfeFtdcRspQryUserIpChgField *pRspQryUserIpChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///限仓数据变动查询应答
	virtual void OnRspQryClientPosiLimitChgTopic(CShfeFtdcRspQryClientPosiLimitChgField *pRspQryClientPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///限仓数据变动查询应答
	virtual void OnRspQrySpecPosiLimitChgTopic(CShfeFtdcRspQrySpecPosiLimitChgField *pRspQrySpecPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///历史对象状态指标查询应答
	virtual void OnRspQryHistoryObjectAttrTopic(CShfeFtdcRspQryHistoryObjectAttrField *pRspQryHistoryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///前置响应信息查询应答
	virtual void OnRspQryFrontInfoTopic(CShfeFtdcRspQryFrontInfoField *pRspQryFrontInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///用户登录应答
	virtual void OnRspQrySysUserLoginTopic(CShfeFtdcRspQrySysUserLoginField *pRspQrySysUserLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///用户登出应答
	virtual void OnRspQrySysUserLogoutTopic(CShfeFtdcRspQrySysUserLogoutField *pRspQrySysUserLogout, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///用户修改密码应答
	virtual void OnRspQrySysUserPasswordUpdateTopic(CShfeFtdcRspQrySysUserPasswordUpdateField *pRspQrySysUserPasswordUpdate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///注册用户应答
	virtual void OnRspQrySysUserRegisterTopic(CShfeFtdcRspQrySysUserRegisterField *pRspQrySysUserRegister, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///删除用户应答
	virtual void OnRspQrySysUserDeleteTopic(CShfeFtdcRspQrySysUserDeleteField *pRspQrySysUserDelete, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///会员初始化应答
	virtual void OnRspQryParticipantInitTopic(CShfeFtdcRspQryParticipantInitField *pRspQryParticipantInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///座席初始化应答
	virtual void OnRspQryUserInitTopic(CShfeFtdcRspQryUserInitField *pRspQryUserInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///客户初始化应答
	virtual void OnRspQryClientInitTopic(CShfeFtdcRspQryClientInitField *pRspQryClientInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///交易日志查询应答
	virtual void OnRspQryTradeLogTopic(CShfeFtdcRspQryTradeLogField *pRspQryTradeLog, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///交易系统登录信息
	virtual void OnRspQryTradeUserLoginInfoTopic(CShfeFtdcRspQryTradeUserLoginInfoField *pRspQryTradeUserLoginInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///会员交易查询应答
	virtual void OnRspQryPartTradeTopic(CShfeFtdcRspQryPartTradeField *pRspQryPartTrade, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///交易峰值查询应答
	virtual void OnRspQryTradepeakTopic(CShfeFtdcRspQryTradepeakField *pRspQryTradepeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///
	virtual void OnRspQryHistoryCpuInfoTopic(CShfeFtdcRspQryHistoryCpuInfoField *pRspQryHistoryCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///
	virtual void OnRspQryHistoryMemInfoTopic(CShfeFtdcRspQryHistoryMemInfoField *pRspQryHistoryMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///
	virtual void OnRspQryHistoryNetworkInfoTopic(CShfeFtdcRspQryHistoryNetworkInfoField *pRspQryHistoryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///监控系统在线用户应答
	virtual void OnRspQryMonitorOnlineUser(CShfeFtdcRspQryMonitorOnlineUserField *pRspQryMonitorOnlineUser, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///交易系统前置统计应答
	virtual void OnRspQryFrontStat(CShfeFtdcRspQryFrontStatField *pRspQryFrontStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///历史峰值查询应答
	virtual void OnRspQryHistoryTradePeakTopic(CShfeFtdcRspQryHistoryTradePeakField *pRspQryHistoryTradePeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///日志事件查询应答
	virtual void OnRspQrySyslogEventTopic(CShfeFtdcRspQrySyslogEventField *pRspQrySyslogEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///Web应用信息
	virtual void OnRspQryWebAppInfoTopic(CShfeFtdcRspQryWebAppInfoField *pRspQryWebAppInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///应用servlet信息
	virtual void OnRspQryServletInfoTopic(CShfeFtdcRspQryServletInfoField *pRspQryServletInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///文件信息
	virtual void OnRspQryFileInfoTopic(CShfeFtdcRspQryFileInfoField *pRspQryFileInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///应用会话信息
	virtual void OnRspQrySessionInfoTopic(CShfeFtdcRspQrySessionInfoField *pRspQrySessionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///JDBC信息
	virtual void OnRspQryJDBCInfoTopic(CShfeFtdcRspQryJDBCInfoField *pRspQryJDBCInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///线程信息
	virtual void OnRspQryThreadInfoTopic(CShfeFtdcRspQryThreadInfoField *pRspQryThreadInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///虚拟机信息
	virtual void OnRspQryVMInfoTopic(CShfeFtdcRspQryVMInfoField *pRspQryVMInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///系统属性信息
	virtual void OnRspQryPropertyInfoTopic(CShfeFtdcRspQryPropertyInfoField *pRspQryPropertyInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///系统内存池信息
	virtual void OnRspQryMemPoolInfoTopic(CShfeFtdcRspQryMemPoolInfoField *pRspQryMemPoolInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///文件内容信息
	virtual void OnRspQryFileContentInfoTopic(CShfeFtdcRspQryFileContentInfoField *pRspQryFileContentInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///连接信息
	virtual void OnRspQryConnectionInfoTopic(CShfeFtdcRspQryConnectionInfoField *pRspQryConnectionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///连接器信息
	virtual void OnRspQryConnectorInfoTopic(CShfeFtdcRspQryConnectorInfoField *pRspQryConnectorInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///数据库查询应答
	virtual void OnRspQryDBQueryTopic(CShfeFtdcRspQryDBQueryField *pRspQryDBQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///通用返回应答
	virtual void OnRspQryGeneralFieldTopic(CShfeFtdcSysGeneralFieldField *pSysGeneralField, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///文件传输应答
	virtual void OnRspQryGetFileTopic(CShfeFtdcRspQryGetFileField *pRspQryGetFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///告警明细
	virtual void OnRspQryWarningQueryTopic(CShfeFtdcRspQryWarningQueryField *pRspQryWarningQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///通用操作
	virtual void OnRspQryGeneralOperateTopic(CShfeFtdcRspQryGeneralOperateField *pRspQryGeneralOperate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///网络设备连接关系
	virtual void OnRspQryNetDeviceLinkedTopic(CShfeFtdcRspQryNetDeviceLinkedField *pRspQryNetDeviceLinked, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///交易系统登录信息
	virtual void OnRspQryTradeUserLoginStatTopic(CShfeFtdcRspQryTradeUserLoginStatField *pRspQryTradeUserLoginStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///交易系统前置报单响应信息
	virtual void OnRspQryTradeFrontOrderRttStatTopic(CShfeFtdcRspQryTradeFrontOrderRttStatField *pRspQryTradeFrontOrderRttStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///会员席位交易状态
	virtual void OnRspQryParticTradeOrderStatesTopic(CShfeFtdcRspQryParticTradeOrderStatesField *pRspQryParticTradeOrderStates, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///系统路由信息
	virtual void OnRspQryRouterInfoTopic(CShfeFtdcRspQryRouterInfoField *pRspQryRouterInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///磁盘I/O信息
	virtual void OnRspQryDiskIOTopic(CShfeFtdcRspQryDiskIOField *pRspQryDiskIO, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///系统状态信息
	virtual void OnRspQryStatInfoTopic(CShfeFtdcRspQryStatInfoField *pRspQryStatInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///交易系统前置报单分布区间
	virtual void OnRspQryTradeOrderRttCutLineTopic(CShfeFtdcRspQryTradeOrderRttCutLineField *pRspQryTradeOrderRttCutLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///会员客户信息
	virtual void OnRspQryClientInfoTopic(CShfeFtdcRspQryClientInfoField *pRspQryClientInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///应答事件描述
	virtual void OnRspQryEventDescriptionTopic(CShfeFtdcRspQryEventDescriptionField *pRspQryEventDescription, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///应答前置唯一ID信息
	virtual void OnRspQryFrontUniqueIDTopic(CShfeFtdcRspQryFrontUniqueIDField *pRspQryFrontUniqueID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///会员线路地址变更回应
	virtual void OnRspQryNetPartyLinkAddrChangeTopic(CShfeFtdcRspQryNetPartyLinkAddrChangeField *pRspQryNetPartyLinkAddrChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///应答已删除会员列表信息
	virtual void OnRspQryNetDelPartyLinkInfoTopic(CShfeFtdcRspQryNetDelPartyLinkInfoField *pRspQryNetDelPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///返回网络性能排序
	virtual void OnRspQryPerformanceTopTopic(CShfeFtdcRspQryPerformanceTopField *pRspQryPerformanceTop, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///返回约状态切换数据
	virtual void OnRspQryInstrumentStatusTopic(CShfeFtdcRspQryInstrumentStatusField *pRspQryInstrumentStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///返回合约交易节信息
	virtual void OnRspQryCurrTradingSegmentAttrTopic(CShfeFtdcRspQryCurrTradingSegmentAttrField *pRspQryCurrTradingSegmentAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///网络大区划分应答
	virtual void OnRspQryNetAreaTopic(CShfeFtdcRspQryNetAreaField *pRspQryNetArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///网络子区应答
	virtual void OnRspQryNetSubAreaTopic(CShfeFtdcRspQryNetSubAreaField *pRspQryNetSubArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///网络子区IP应答
	virtual void OnRspQryNetSubAreaIPTopic(CShfeFtdcRspQryNetSubAreaIPField *pRspQryNetSubAreaIP, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///网络设备
	virtual void OnRspQryNetDeviceTopic(CShfeFtdcRspQryNetDeviceField *pRspQryNetDevice, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///网络设备探测请求应答
	virtual void OnRspQryNetDeviceDetectTopic(CShfeFtdcRspQryNetDeviceDetectField *pRspQryNetDeviceDetect, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///大楼
	virtual void OnRspQryNetBuildingTopic(CShfeFtdcRspQryNetBuildingField *pRspQryNetBuilding, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///机房
	virtual void OnRspQryNetRoomTopic(CShfeFtdcRspQryNetRoomField *pRspQryNetRoom, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///机柜
	virtual void OnRspQryNetCabinetsTopic(CShfeFtdcRspQryNetCabinetsField *pRspQryNetCabinets, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///OID
	virtual void OnRspQryNetOIDTopic(CShfeFtdcRspQryNetOIDField *pRspQryNetOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///时间策略
	virtual void OnRspQryNetTimePolicyTopic(CShfeFtdcRspQryNetTimePolicyField *pRspQryNetTimePolicy, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///采集任务
	virtual void OnRspQryNetGatherTaskTopic(CShfeFtdcRspQryNetGatherTaskField *pRspQryNetGatherTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///设备变更
	virtual void OnRspQryNetDeviceChgTopic(CShfeFtdcRspQryNetDeviceChgField *pRspQryNetDeviceChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///常用设备型号
	virtual void OnRspQryNetDeviceTypeTopic(CShfeFtdcRspQryNetDeviceTypeField *pRspQryNetDeviceType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///常用设备类别
	virtual void OnRspQryNetDeviceCategoryTopic(CShfeFtdcRspQryNetDeviceCategoryField *pRspQryNetDeviceCategory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///设备厂商
	virtual void OnRspQryNetManufactoryTopic(CShfeFtdcRspQryNetManufactoryField *pRspQryNetManufactory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///设备共同体
	virtual void OnRspQryNetCommunityTopic(CShfeFtdcRspQryNetCommunityField *pRspQryNetCommunity, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///端口类型
	virtual void OnRspQryNetPortTypeTopic(CShfeFtdcRspQryNetPortTypeField *pRspQryNetPortType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///会员接入地点
	virtual void OnRspQryNetPartAccessSpotTopic(CShfeFtdcRspQryNetPartAccessSpotField *pRspQryNetPartAccessSpot, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///端口
	virtual void OnRspQryNetInterfaceTopic(CShfeFtdcRspQryNetInterfaceField *pRspQryNetInterface, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///GeneralOID
	virtual void OnRspQryNetGeneralOIDTopic(CShfeFtdcRspQryNetGeneralOIDField *pRspQryNetGeneralOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///监控对象类别
	virtual void OnRspQryNetMonitorTypeTopic(CShfeFtdcRspQryNetMonitorTypeField *pRspQryNetMonitorType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///指标统表
	virtual void OnRspQryNetMonitorAttrScopeTopic(CShfeFtdcRspQryNetMonitorAttrScopeField *pRspQryNetMonitorAttrScope, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///监控指标表
	virtual void OnRspQryNetMonitorAttrTypeTopic(CShfeFtdcRspQryNetMonitorAttrTypeField *pRspQryNetMonitorAttrType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///监控对象指标表
	virtual void OnRspQryNetMonitorObjectAttrTopic(CShfeFtdcRspQryNetMonitorObjectAttrField *pRspQryNetMonitorObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///设备对象组表
	virtual void OnRspQryNetMonitorDeviceGroupTopic(CShfeFtdcRspQryNetMonitorDeviceGroupField *pRspQryNetMonitorDeviceGroup, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///任务信息表
	virtual void OnRspQryNetMonitorTaskInfoTopic(CShfeFtdcRspQryNetMonitorTaskInfoField *pRspQryNetMonitorTaskInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///任务结果表
	virtual void OnRspQryNetMonitorTaskResultTopic(CShfeFtdcRspQryNetMonitorTaskResultField *pRspQryNetMonitorTaskResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///任务对象集
	virtual void OnRspQryNetMonitorTaskObjectSetTopic(CShfeFtdcRspQryNetMonitorTaskObjectSetField *pRspQryNetMonitorTaskObjectSet, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///会员链路信息表
	virtual void OnRspQryNetPartyLinkInfoTopic(CShfeFtdcRspQryNetPartyLinkInfoField *pRspQryNetPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///监控动作指标对照表
	virtual void OnRspQryNetMonitorActionAttrTopic(CShfeFtdcRspQryNetMonitorActionAttrField *pRspQryNetMonitorActionAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///模块
	virtual void OnRspQryNetModuleTopic(CShfeFtdcRspQryNetModuleField *pRspQryNetModule, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///任务结果状态表
	virtual void OnRspQryNetMonitorTaskStatusResultTopic(CShfeFtdcRspQryNetMonitorTaskStatusResultField *pRspQryNetMonitorTaskStatusResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///设备配置表
	virtual void OnRspQryNetCfgFileTopic(CShfeFtdcRspQryNetCfgFileField *pRspQryNetCfgFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///任务结果规则分析表
	virtual void OnRspQryNetMonitorDeviceTaskTopic(CShfeFtdcRspQryNetMonitorDeviceTaskField *pRspQryNetMonitorDeviceTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///文件通用操作
	virtual void OnRspQryFileGeneralOperTopic(CShfeFtdcRspQryFileGeneralOperField *pRspQryFileGeneralOper, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///基线表
	virtual void OnRspQryNetBaseLineTopic(CShfeFtdcRspQryNetBaseLineField *pRspQryNetBaseLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///基线结果表
	virtual void OnRspQryNetBaseLineResultTopic(CShfeFtdcRspQryNetBaseLineResultField *pRspQryNetBaseLineResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///会员链路状态信息表
	virtual void OnRspQryNetPartyLinkStatusInfoTopic(CShfeFtdcRspQryNetPartyLinkStatusInfoField *pRspQryNetPartyLinkStatusInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///本地ping结果
	virtual void OnRspQryNetLocalPingResultInfoTopic(CShfeFtdcRspQryNetLocalPingResultInfoField *pRspQryNetLocalPingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///远程ping结果
	virtual void OnRspQryNetRomotePingResultInfoTopic(CShfeFtdcRspQryNetRomotePingResultInfoField *pRspQryNetRomotePingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///返回会员链路费用表
	virtual void OnRspQryMemberLinkCostTopic(CShfeFtdcRspQryMemberLinkCostField *pRspQryMemberLinkCost, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///返回非会员链路表信息
	virtual void OnRspQryNetNonPartyLinkInfoTopic(CShfeFtdcRspQryNetNonPartyLinkInfoField *pRspQryNetNonPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};



	///CPU应答
	virtual void OnRtnTopCpuInfoTopic(CShfeFtdcRtnTopCpuInfoField *pRtnTopCpuInfo){};

	///Mem应答
	virtual void OnRtnTopMemInfoTopic(CShfeFtdcRtnTopMemInfoField *pRtnTopMemInfo){};

	///process应答
	virtual void OnRtnTopProcessInfoTopic(CShfeFtdcRtnTopProcessInfoField *pRtnTopProcessInfo){};

	///filesystem应答
	virtual void OnRtnFileSystemInfoTopic(CShfeFtdcRtnFileSystemInfoField *pRtnFileSystemInfo){};

	///network应答
	virtual void OnRtnNetworkInfoTopic(CShfeFtdcRtnNetworkInfoField *pRtnNetworkInfo){};

	///主机环境信息应答
	virtual void OnRtnHostEnvTopic(CShfeFtdcRspQryHostEnvCommonField *pRspQryHostEnvCommon, CShfeFtdcRspQryHostEnvLanField *pRspQryHostEnvLan, CShfeFtdcRspQryHostEnvStorageField *pRspQryHostEnvStorage, CShfeFtdcRspQryHostEnvIOField *pRspQryHostEnvIO, CShfeFtdcRspQryHostEnvFSField *pRspQryHostEnvFS, CShfeFtdcRspQryHostEnvSwapField *pRspQryHostEnvSwap, CShfeFtdcRspQryHostEnvLanCfgField *pRspQryHostEnvLanCfg, CShfeFtdcRspInfoField *pRspInfo){};

	///获得监控对象信息应答
	virtual void OnRtnMonitorObjectTopic(CShfeFtdcRtnMonitorObjectField *pRtnMonitorObject){};

	///获得业务进程和主机的对应关系应答
	virtual void OnRtnObjectRationalTopic(CShfeFtdcRtnObjectRationalField *pRtnObjectRational){};

	///日志文件内容应答
	virtual void OnRtnSyslogInfoTopic(CShfeFtdcRtnSyslogInfoField *pRtnSyslogInfo){};

	///对象关系查询应答
	virtual void OnRtnOidRelationTopic(CShfeFtdcRtnOidRelationField *pRtnOidRelation){};

	///用户信息查询请求应答
	virtual void OnRtnUserInfoTopic(CShfeFtdcRtnUserInfoField *pRtnUserInfo){};

	///在线用户信息查询请求应答
	virtual void OnRtnOnlineUserInfoTopic(CShfeFtdcRtnOnlineUserInfoField *pRtnOnlineUserInfo){};

	///告警事件查询请求应答
	virtual void OnRtnWarningEventTopic(CShfeFtdcRtnWarningEventField *pRtnWarningEvent){};

	///对象状态指标查询应答
	virtual void OnRtnObjectAttrTopic(CShfeFtdcRtnObjectAttrField *pRtnObjectAttr){};

	///无效报单查询应答
	virtual void OnRtnInvalidateOrderTopic(CShfeFtdcRtnInvalidateOrderField *pRtnInvalidateOrder){};

	///报单状态查询应答
	virtual void OnRtnOrderStatusTopic(CShfeFtdcRtnOrderStatusField *pRtnOrderStatus){};

	///报单成交查询应答
	virtual void OnRtnBargainOrderTopic(CShfeFtdcRtnBargainOrderField *pRtnBargainOrder){};

	///合约基本属性查询应答
	virtual void OnRtnInstPropertyTopic(CShfeFtdcRtnInstPropertyField *pRtnInstProperty){};

	///合约保证金率查询应答
	virtual void OnRtnMarginRateTopic(CShfeFtdcRtnMarginRateField *pRtnMarginRate){};

	///合约涨跌停板查询应答
	virtual void OnRtnPriceLimitTopic(CShfeFtdcRtnPriceLimitField *pRtnPriceLimit){};

	///会员限仓查询应答
	virtual void OnRtnPartPosiLimitTopic(CShfeFtdcRtnPartPosiLimitField *pRtnPartPosiLimit){};

	///客户限仓查询应答
	virtual void OnRtnClientPosiLimitTopic(CShfeFtdcRtnClientPosiLimitField *pRtnClientPosiLimit){};

	///特殊客户限仓查询应答
	virtual void OnRtnSpecialPosiLimitTopic(CShfeFtdcRtnSpecialPosiLimitField *pRtnSpecialPosiLimit){};

	///账户出入金查询应答
	virtual void OnRtnTransactionChgTopic(CShfeFtdcRtnTransactionChgField *pRtnTransactionChg){};

	///客户数据变动查询应答
	virtual void OnRtnClientChgTopic(CShfeFtdcRtnClientChgField *pRtnClientChg){};

	///会员客户对照变动查询应答
	virtual void OnRtnPartClientChgTopic(CShfeFtdcRtnPartClientChgField *pRtnPartClientChg){};

	///限仓数据变动查询应答
	virtual void OnRtnPosiLimitChgTopic(CShfeFtdcRtnPosiLimitChgField *pRtnPosiLimitChg){};

	///保值额度变动查询应答
	virtual void OnRtnHedgeDetailChgTopic(CShfeFtdcRtnHedgeDetailChgField *pRtnHedgeDetailChg){};

	///会员变动查询应答
	virtual void OnRtnParticipantChgTopic(CShfeFtdcRtnParticipantChgField *pRtnParticipantChg){};

	///保证金率变动查询应答
	virtual void OnRtnMarginRateChgTopic(CShfeFtdcRtnMarginRateChgField *pRtnMarginRateChg){};

	///IP地址变动查询应答
	virtual void OnRtnUserIpChgTopic(CShfeFtdcRtnUserIpChgField *pRtnUserIpChg){};

	///限仓数据变动查询应答
	virtual void OnRtnClientPosiLimitChgTopic(CShfeFtdcRtnClientPosiLimitChgField *pRtnClientPosiLimitChg){};

	///限仓数据变动查询应答
	virtual void OnRtnSpecPosiLimitChgTopic(CShfeFtdcRtnSpecPosiLimitChgField *pRtnSpecPosiLimitChg){};

	///历史对象状态指标查询应答
	virtual void OnRtnHistoryObjectAttrTopic(CShfeFtdcRtnHistoryObjectAttrField *pRtnHistoryObjectAttr){};

	///前置响应信息查询应答
	virtual void OnRtnFrontInfoTopic(CShfeFtdcRtnFrontInfoField *pRtnFrontInfo){};

	///会员初始化应答
	virtual void OnRtnParticipantInitTopic(CShfeFtdcRtnParticipantInitField *pRtnParticipantInit){};

	///座席初始化应答
	virtual void OnRtnUserInitTopic(CShfeFtdcRtnUserInitField *pRtnUserInit){};

	///客户初始化应答
	virtual void OnRtnClientInitTopic(CShfeFtdcRtnClientInitField *pRtnClientInit){};

	///交易日志查询应答
	virtual void OnRtnTradeLogTopic(CShfeFtdcRtnTradeLogField *pRtnTradeLog){};

	///交易系统登录信息
	virtual void OnRtnTradeUserLoginInfoTopic(CShfeFtdcRtnTradeUserLoginInfoField *pRtnTradeUserLoginInfo){};

	///
	virtual void OnRtnUpdateSysConfigTopic(CShfeFtdcRtnUpdateSysConfigField *pRtnUpdateSysConfig){};

	///
	virtual void OnRtnSysUser(CShfeFtdcRtnSysUserField *pRtnSysUser){};

	///监控系统时钟同步
	virtual void OnRtnSysTimeSyncTopic(CShfeFtdcRtnSysTimeSyncField *pRtnSysTimeSync){};

	///数据中心切换通知
	virtual void OnRtnDataCenterChgTopic(CShfeFtdcRtnDataCenterChgField *pRtnDataCenterChg){};

	///日志事件应答
	virtual void OnRtnSyslogEventTopic(CShfeFtdcRtnSyslogEventField *pRtnSyslogEvent){};

	///Web应用信息
	virtual void OnRtnWebAppInfoTopic(CShfeFtdcRtnWebAppInfoField *pRtnWebAppInfo){};

	///应用servlet信息
	virtual void OnRtnServletInfoTopic(CShfeFtdcRtnServletInfoField *pRtnServletInfo){};

	///文件信息
	virtual void OnRtnFileInfoTopic(CShfeFtdcRtnFileInfoField *pRtnFileInfo){};

	///应用会话信息
	virtual void OnRtnSessionInfoTopic(CShfeFtdcRtnSessionInfoField *pRtnSessionInfo){};

	///JDBC信息
	virtual void OnRtnJDBCInfoTopic(CShfeFtdcRtnJDBCInfoField *pRtnJDBCInfo){};

	///线程信息
	virtual void OnRtnThreadInfoTopic(CShfeFtdcRtnThreadInfoField *pRtnThreadInfo){};

	///虚拟机信息
	virtual void OnRtnVMInfoTopic(CShfeFtdcRtnVMInfoField *pRtnVMInfo){};

	///系统属性信息
	virtual void OnRtnPropertyInfoTopic(CShfeFtdcRtnPropertyInfoField *pRtnPropertyInfo){};

	///系统内存池信息
	virtual void OnRtnMemPoolInfoTopic(CShfeFtdcRtnMemPoolInfoField *pRtnMemPoolInfo){};

	///文件内容信息
	virtual void OnRtnFileContentInfoTopic(CShfeFtdcRtnFileContentInfoField *pRtnFileContentInfo){};

	///连接信息
	virtual void OnRtnConnectionInfoTopic(CShfeFtdcRtnConnectionInfoField *pRtnConnectionInfo){};

	///连接器信息
	virtual void OnRtnConnectorInfoTopic(CShfeFtdcRtnConnectorInfoField *pRtnConnectorInfo){};

	///数据库查询应答
	virtual void OnRtnDBQueryTopic(CShfeFtdcRtnDBQueryField *pRtnDBQuery){};

	///通用返回应答
	virtual void OnRtnGeneralFieldTopic(CShfeFtdcSysGeneralFieldField *pSysGeneralField){};

	///告警激活变更
	virtual void OnRtnWarningActiveChange(CShfeFtdcRtnWarningActiveChangeField *pRtnWarningActiveChange){};

	///通用操作
	virtual void OnRtnGeneralOperateTopic(CShfeFtdcRtnGeneralOperateField *pRtnGeneralOperate){};

	///网络设备连接关系
	virtual void OnRtnNetDeviceLinkedTopic(CShfeFtdcRtnNetDeviceLinkedField *pRtnNetDeviceLinked){};

	///交易系统前置报单响应信息
	virtual void OnRtnTradeFrontOrderRttStatTopic(CShfeFtdcRtnTradeFrontOrderRttStatField *pRtnTradeFrontOrderRttStat){};

	///会员席位交易状态
	virtual void OnRtnParticTradeOrderStatesTopic(CShfeFtdcRtnParticTradeOrderStatesField *pRtnParticTradeOrderStates){};

	///系统路由信息
	virtual void OnRtnRouterInfoTopic(CShfeFtdcRtnRouterInfoField *pRtnRouterInfo){};

	///磁盘I/O信息
	virtual void OnRtnDiskIOTopic(CShfeFtdcRtnDiskIOField *pRtnDiskIO){};

	///系统状态信息
	virtual void OnRtnStatInfoTopic(CShfeFtdcRtnStatInfoField *pRtnStatInfo){};

	///交易系统前置报单分布区间
	virtual void OnRtnTradeOrderRttCutLineTopic(CShfeFtdcRtnTradeOrderRttCutLineField *pRtnTradeOrderRttCutLine){};

	///会员客户信息
	virtual void OnRtnClientInfoTopic(CShfeFtdcRtnClientInfoField *pRtnClientInfo){};

	///订阅事件描述
	virtual void OnRtnEventDescriptionTopic(CShfeFtdcRtnEventDescriptionField *pRtnEventDescription){};

	///订阅前置唯一ID信息
	virtual void OnRtnFrontUniqueIDTopic(CShfeFtdcRtnFrontUniqueIDField *pRtnFrontUniqueID){};

	///订阅会员线路地址变更信息
	virtual void OnRtnNetPartyLinkAddrChangeTopic(CShfeFtdcRtnNetPartyLinkAddrChangeField *pRtnNetPartyLinkAddrChange){};

	///订阅已删除会员列表信息
	virtual void OnRtnNetDelPartyLinkInfoTopic(CShfeFtdcRtnNetDelPartyLinkInfoField *pRtnNetDelPartyLinkInfo){};

	///订阅网络性能排序
	virtual void OnRtnPerformanceTopTopic(CShfeFtdcRtnPerformanceTopField *pRtnPerformanceTop){};

	///订阅约状态切换数据
	virtual void OnRtnInstrumentStatusTopic(CShfeFtdcRtnInstrumentStatusField *pRtnInstrumentStatus){};

	///订阅合约交易节信息
	virtual void OnRtnCurrTradingSegmentAttrTopic(CShfeFtdcRtnCurrTradingSegmentAttrField *pRtnCurrTradingSegmentAttr){};

	///网络大区划分应答
	virtual void OnRtnNetAreaTopic(CShfeFtdcRtnNetAreaField *pRtnNetArea){};

	///网络子区应答
	virtual void OnRtnNetSubAreaTopic(CShfeFtdcRtnNetSubAreaField *pRtnNetSubArea){};

	///网络子区IP应答
	virtual void OnRtnNetSubAreaIPTopic(CShfeFtdcRtnNetSubAreaIPField *pRtnNetSubAreaIP){};

	///网络设备
	virtual void OnRtnNetDeviceTopic(CShfeFtdcRtnNetDeviceField *pRtnNetDevice){};

	///大楼
	virtual void OnRtnNetBuildingTopic(CShfeFtdcRtnNetBuildingField *pRtnNetBuilding){};

	///机房
	virtual void OnRtnNetRoomTopic(CShfeFtdcRtnNetRoomField *pRtnNetRoom){};

	///机柜
	virtual void OnRtnNetCabinetsTopic(CShfeFtdcRtnNetCabinetsField *pRtnNetCabinets){};

	///OID
	virtual void OnRtnNetOIDTopic(CShfeFtdcRtnNetOIDField *pRtnNetOID){};

	///时间策略
	virtual void OnRtnNetTimePolicyTopic(CShfeFtdcRtnNetTimePolicyField *pRtnNetTimePolicy){};

	///采集任务
	virtual void OnRtnNetGatherTaskTopic(CShfeFtdcRtnNetGatherTaskField *pRtnNetGatherTask){};

	///设备变更
	virtual void OnRtnNetDeviceChgTopic(CShfeFtdcRtnNetDeviceChgField *pRtnNetDeviceChg){};

	///常用设备型号
	virtual void OnRtnNetDeviceTypeTopic(CShfeFtdcRtnNetDeviceTypeField *pRtnNetDeviceType){};

	///常用设备类别
	virtual void OnRtnNetDeviceCategoryTopic(CShfeFtdcRtnNetDeviceCategoryField *pRtnNetDeviceCategory){};

	///设备厂商
	virtual void OnRtnNetManufactoryTopic(CShfeFtdcRtnNetManufactoryField *pRtnNetManufactory){};

	///设备共同体
	virtual void OnRtnNetCommunityTopic(CShfeFtdcRtnNetCommunityField *pRtnNetCommunity){};

	///端口类型
	virtual void OnRtnNetPortTypeTopic(CShfeFtdcRtnNetPortTypeField *pRtnNetPortType){};

	///会员接入地点
	virtual void OnRtnNetPartAccessSpotTopic(CShfeFtdcRtnNetPartAccessSpotField *pRtnNetPartAccessSpot){};

	///端口
	virtual void OnRtnNetInterfaceTopic(CShfeFtdcRtnNetInterfaceField *pRtnNetInterface){};

	///GeneralOID
	virtual void OnRtnNetGeneralOIDTopic(CShfeFtdcRtnNetGeneralOIDField *pRtnNetGeneralOID){};

	///监控对象类别
	virtual void OnRtnNetMonitorTypeTopic(CShfeFtdcRtnNetMonitorTypeField *pRtnNetMonitorType){};

	///指标统表
	virtual void OnRtnNetMonitorAttrScopeTopic(CShfeFtdcRtnNetMonitorAttrScopeField *pRtnNetMonitorAttrScope){};

	///监控指标表
	virtual void OnRtnNetMonitorAttrTypeTopic(CShfeFtdcRtnNetMonitorAttrTypeField *pRtnNetMonitorAttrType){};

	///监控对象指标表
	virtual void OnRtnNetMonitorObjectAttrTopic(CShfeFtdcRtnNetMonitorObjectAttrField *pRtnNetMonitorObjectAttr){};

	///设备对象组表
	virtual void OnRtnNetMonitorDeviceGroupTopic(CShfeFtdcRtnNetMonitorDeviceGroupField *pRtnNetMonitorDeviceGroup){};

	///任务信息表
	virtual void OnRtnNetMonitorTaskInfoTopic(CShfeFtdcRtnNetMonitorTaskInfoField *pRtnNetMonitorTaskInfo){};

	///任务结果表
	virtual void OnRtnNetMonitorTaskResultTopic(CShfeFtdcRtnNetMonitorTaskResultField *pRtnNetMonitorTaskResult){};

	///任务对象集
	virtual void OnRtnNetMonitorTaskObjectSetTopic(CShfeFtdcRtnNetMonitorTaskObjectSetField *pRtnNetMonitorTaskObjectSet){};

	///会员链路信息表
	virtual void OnRtnNetPartyLinkInfoTopic(CShfeFtdcRtnNetPartyLinkInfoField *pRtnNetPartyLinkInfo){};

	///模块
	virtual void OnRtnNetModuleTopic(CShfeFtdcRtnNetModuleField *pRtnNetModule){};

	///任务结果状态表
	virtual void OnRtnNetMonitorTaskStatusResultTopic(CShfeFtdcRtnNetMonitorTaskStatusResultField *pRtnNetMonitorTaskStatusResult){};

	///设备配置表
	virtual void OnRtnNetCfgFileTopic(CShfeFtdcRtnNetCfgFileField *pRtnNetCfgFile){};

	///任务结果规则分析表
	virtual void OnRtnNetMonitorDeviceTaskTopic(CShfeFtdcRtnNetMonitorDeviceTaskField *pRtnNetMonitorDeviceTask){};

	///文件通用操作
	virtual void OnRtnFileGeneralOperTopic(CShfeFtdcRtnFileGeneralOperField *pRtnFileGeneralOper){};

	///基线表
	virtual void OnRtnNetBaseLineTopic(CShfeFtdcRtnNetBaseLineField *pRtnNetBaseLine){};

	///基线结果表
	virtual void OnRtnNetBaseLineResultTopic(CShfeFtdcRtnNetBaseLineResultField *pRtnNetBaseLineResult){};

	///会员链路状态信息表
	virtual void OnRtnNetPartyLinkStatusInfoTopic(CShfeFtdcRtnNetPartyLinkStatusInfoField *pRtnNetPartyLinkStatusInfo){};

	///本地ping结果
	virtual void OnRtnNetLocalPingResultInfoTopic(CShfeFtdcRtnNetLocalPingResultInfoField *pRtnNetLocalPingResultInfo){};

	///远程ping结果
	virtual void OnRtnNetRomotePingResultInfoTopic(CShfeFtdcRtnNetRomotePingResultInfoField *pRtnNetRomotePingResultInfo){};

	///订阅会员链路费用表
	virtual void OnRtnMemberLinkCostTopic(CShfeFtdcRtnMemberLinkCostField *pRtnMemberLinkCost){};

	///订阅非会员链路表信息
	virtual void OnRtnNetNonPartyLinkInfoTopic(CShfeFtdcRtnNetNonPartyLinkInfoField *pRtnNetNonPartyLinkInfo){};


	///CPU查询
	virtual BOOL ReqQryTopCpuInfoTopic(CShfeFtdcReqQryTopCpuInfoField *pReqQryTopCpuInfo, int nRequestID = 0);
	
	///Mem查询
	virtual BOOL ReqQryTopMemInfoTopic(CShfeFtdcReqQryTopMemInfoField *pReqQryTopMemInfo, int nRequestID = 0);
	
	///process查询
	virtual BOOL ReqQryTopProcessInfoTopic(CShfeFtdcReqQryTopProcessInfoField *pReqQryTopProcessInfo, int nRequestID = 0);
	
	///filesystem查询
	virtual BOOL ReqQryFileSystemInfoTopic(CShfeFtdcReqQryFileSystemInfoField *pReqQryFileSystemInfo, int nRequestID = 0);
	
	///network查询
	virtual BOOL ReqQryNetworkInfoTopic(CShfeFtdcReqQryNetworkInfoField *pReqQryNetworkInfo, int nRequestID = 0);
	
	///主机环境信息查询
	virtual BOOL ReqQryHostEnvTopic(CShfeFtdcReqQryHostEnvField *pReqQryHostEnv, int nRequestID = 0);
	
	///获得监控对象信息查询
	virtual BOOL ReqQryMonitorObjectTopic(CShfeFtdcReqQryMonitorObjectField *pReqQryMonitorObject, int nRequestID = 0);
	
	///获得业务进程和主机的对应关系查询
	virtual BOOL ReqQryObjectRationalTopic(CShfeFtdcReqQryObjectRationalField *pReqQryObjectRational, int nRequestID = 0);
	
	///日志文件内容查询
	virtual BOOL ReqQrySyslogInfoTopic(CShfeFtdcReqQrySyslogInfoField *pReqQrySyslogInfo, int nRequestID = 0);
	
	///监控内容订阅请求
	virtual BOOL ReqQrySubscriberTopic(CShfeFtdcReqQrySubscriberField *pReqQrySubscriber, int nRequestID = 0);
	
	///对象关系查询
	virtual BOOL ReqQryOidRelationTopic(CShfeFtdcReqQryOidRelationField *pReqQryOidRelation, int nRequestID = 0);
	
	///用户信息查询请求
	virtual BOOL ReqQryUserInfoTopic(CShfeFtdcReqQryUserInfoField *pReqQryUserInfo, int nRequestID = 0);
	
	///在线用户信息查询请求
	virtual BOOL ReqQryOnlineUserInfoTopic(CShfeFtdcReqQryOnlineUserInfoField *pReqQryOnlineUserInfo, int nRequestID = 0);
	
	///告警事件查询请求
	virtual BOOL ReqQryWarningEventTopic(CShfeFtdcReqQryWarningEventField *pReqQryWarningEvent, int nRequestID = 0);
	
	///对象状态指标查询
	virtual BOOL ReqQryObjectAttrTopic(CShfeFtdcReqQryObjectAttrField *pReqQryObjectAttr, int nRequestID = 0);
	
	///无效报单查询
	virtual BOOL ReqQryInvalidateOrderTopic(CShfeFtdcReqQryInvalidateOrderField *pReqQryInvalidateOrder, int nRequestID = 0);
	
	///报单状态查询
	virtual BOOL ReqQryOrderStatusTopic(CShfeFtdcReqQryOrderStatusField *pReqQryOrderStatus, int nRequestID = 0);
	
	///报单成交查询
	virtual BOOL ReqQryBargainOrderTopic(CShfeFtdcReqQryBargainOrderField *pReqQryBargainOrder, int nRequestID = 0);
	
	///合约基本属性查询
	virtual BOOL ReqQryInstPropertyTopic(CShfeFtdcReqQryInstPropertyField *pReqQryInstProperty, int nRequestID = 0);
	
	///合约保证金率查询
	virtual BOOL ReqQryMarginRateTopic(CShfeFtdcReqQryMarginRateField *pReqQryMarginRate, int nRequestID = 0);
	
	///合约涨跌停板查询
	virtual BOOL ReqQryPriceLimitTopic(CShfeFtdcReqQryPriceLimitField *pReqQryPriceLimit, int nRequestID = 0);
	
	///会员限仓查询
	virtual BOOL ReqQryPartPosiLimitTopic(CShfeFtdcReqQryPartPosiLimitField *pReqQryPartPosiLimit, int nRequestID = 0);
	
	///客户限仓查询
	virtual BOOL ReqQryClientPosiLimitTopic(CShfeFtdcReqQryClientPosiLimitField *pReqQryClientPosiLimit, int nRequestID = 0);
	
	///特殊客户限仓查询
	virtual BOOL ReqQrySpecialPosiLimitTopic(CShfeFtdcReqQrySpecialPosiLimitField *pReqQrySpecialPosiLimit, int nRequestID = 0);
	
	///账户出入金查询
	virtual BOOL ReqQryTransactionChgTopic(CShfeFtdcReqQryTransactionChgField *pReqQryTransactionChg, int nRequestID = 0);
	
	///客户数据变动查询
	virtual BOOL ReqQryClientChgTopic(CShfeFtdcReqQryClientChgField *pReqQryClientChg, int nRequestID = 0);
	
	///会员客户对照变动查询
	virtual BOOL ReqQryPartClientChgTopic(CShfeFtdcReqQryPartClientChgField *pReqQryPartClientChg, int nRequestID = 0);
	
	///限仓数据变动查询
	virtual BOOL ReqQryPosiLimitChgTopic(CShfeFtdcReqQryPosiLimitChgField *pReqQryPosiLimitChg, int nRequestID = 0);
	
	///保值额度变动查询
	virtual BOOL ReqQryHedgeDetailChgTopic(CShfeFtdcReqQryHedgeDetailChgField *pReqQryHedgeDetailChg, int nRequestID = 0);
	
	///会员变动查询
	virtual BOOL ReqQryParticipantChgTopic(CShfeFtdcReqQryParticipantChgField *pReqQryParticipantChg, int nRequestID = 0);
	
	///保证金率变动查询
	virtual BOOL ReqQryMarginRateChgTopic(CShfeFtdcReqQryMarginRateChgField *pReqQryMarginRateChg, int nRequestID = 0);
	
	///IP地址变动查询
	virtual BOOL ReqQryUserIpChgTopic(CShfeFtdcReqQryUserIpChgField *pReqQryUserIpChg, int nRequestID = 0);
	
	///限仓数据变动查询
	virtual BOOL ReqQryClientPosiLimitChgTopic(CShfeFtdcReqQryClientPosiLimitChgField *pReqQryClientPosiLimitChg, int nRequestID = 0);
	
	///限仓数据变动查询
	virtual BOOL ReqQrySpecPosiLimitChgTopic(CShfeFtdcReqQrySpecPosiLimitChgField *pReqQrySpecPosiLimitChg, int nRequestID = 0);
	
	///历史对象状态指标查询
	virtual BOOL ReqQryHistoryObjectAttrTopic(CShfeFtdcReqQryHistoryObjectAttrField *pReqQryHistoryObjectAttr, int nRequestID = 0);
	
	///前置响应信息查询
	virtual BOOL ReqQryFrontInfoTopic(CShfeFtdcReqQryFrontInfoField *pReqQryFrontInfo, int nRequestID = 0);
	
	///用户登录
	virtual BOOL ReqQrySysUserLoginTopic(CShfeFtdcReqQrySysUserLoginField *pReqQrySysUserLogin, int nRequestID = 0);
	
	///用户登出
	virtual BOOL ReqQrySysUserLogoutTopic(CShfeFtdcReqQrySysUserLogoutField *pReqQrySysUserLogout, int nRequestID = 0);
	
	///用户修改密码
	virtual BOOL ReqQrySysUserPasswordUpdateTopic(CShfeFtdcReqQrySysUserPasswordUpdateField *pReqQrySysUserPasswordUpdate, int nRequestID = 0);
	
	///注册用户
	virtual BOOL ReqQrySysUserRegisterTopic(CShfeFtdcReqQrySysUserRegisterField *pReqQrySysUserRegister, int nRequestID = 0);
	
	///删除用户
	virtual BOOL ReqQrySysUserDeleteTopic(CShfeFtdcReqQrySysUserDeleteField *pReqQrySysUserDelete, int nRequestID = 0);
	
	///交易日志查询
	virtual BOOL ReqQryTradeLogTopic(CShfeFtdcReqQryTradeLogField *pReqQryTradeLog, int nRequestID = 0);
	
	///告警事件修改
	virtual BOOL ReqQryWarningEventUpdateTopic(CShfeFtdcReqQryWarningEventUpdateField *pReqQryWarningEventUpdate, int nRequestID = 0);
	
	///交易系统登录信息查询
	virtual BOOL ReqQryTradeUserLoginInfoTopic(CShfeFtdcReqQryTradeUserLoginInfoField *pReqQryTradeUserLoginInfo, int nRequestID = 0);
	
	///会员交易查询
	virtual BOOL ReqQryPartTradeTopic(CShfeFtdcReqQryPartTradeField *pReqQryPartTrade, int nRequestID = 0);
	
	///交易峰值查询
	virtual BOOL ReqQryTradepeakTopic(CShfeFtdcReqQryTradepeakField *pReqQryTradepeak, int nRequestID = 0);
	
	///管理平台初始化信息查询
	virtual BOOL ReqQryParticipantInitTopic(CShfeFtdcReqQryParticipantInitField *pReqQryParticipantInit, int nRequestID = 0);
	
	///管理平台初始化信息查询
	virtual BOOL ReqQryUserInitTopic(CShfeFtdcReqQryUserInitField *pReqQryUserInit, int nRequestID = 0);
	
	///
	virtual BOOL ReqQryHistoryCpuInfoTopic(CShfeFtdcReqQryHistoryCpuInfoField *pReqQryHistoryCpuInfo, int nRequestID = 0);
	
	///
	virtual BOOL ReqQryHistoryMemInfoTopic(CShfeFtdcReqQryHistoryMemInfoField *pReqQryHistoryMemInfo, int nRequestID = 0);
	
	///
	virtual BOOL ReqQryHistoryNetworkInfoTopic(CShfeFtdcReqQryHistoryNetworkInfoField *pReqQryHistoryNetworkInfo, int nRequestID = 0);
	
	///监控系统在线用户查询
	virtual BOOL ReqQryMonitorOnlineUser(CShfeFtdcReqQryMonitorOnlineUserField *pReqQryMonitorOnlineUser, int nRequestID = 0);
	
	///交易系统前置统计查询
	virtual BOOL ReqQryFrontStat(CShfeFtdcReqQryFrontStatField *pReqQryFrontStat, int nRequestID = 0);
	
	///历史峰值查询
	virtual BOOL ReqQryHistoryTradePeakTopic(CShfeFtdcReqQryHistoryTradePeakField *pReqQryHistoryTradePeak, int nRequestID = 0);
	
	///日志事件查询
	virtual BOOL ReqQrySyslogEventTopic(CShfeFtdcReqQrySyslogEventField *pReqQrySyslogEvent, int nRequestID = 0);
	
	///日志事件订阅请求
	virtual BOOL ReqQrySyslogEventSubcriberTopic(CShfeFtdcReqQrySyslogEventSubcriberField *pReqQrySyslogEventSubcriber, int nRequestID = 0);
	
	///tomcat信息查询
	virtual BOOL ReqQryTomcatInfoTopic(CShfeFtdcReqQryTomcatInfoField *pReqQryTomcatInfo, int nRequestID = 0);
	
	///数据库查询
	virtual BOOL ReqQryDBQueryTopic(CShfeFtdcReqQryDBQueryField *pReqQryDBQuery, int nRequestID = 0);
	
	///文件传输请求
	virtual BOOL ReqQryGetFileTopic(CShfeFtdcReqQryGetFileField *pReqQryGetFile, int nRequestID = 0);
	
	///日志事件修改请求
	virtual BOOL ReqQrySyslogEventUpdateTopic(CShfeFtdcReqQrySyslogEventUpdateField *pReqQrySyslogEventUpdate, int nRequestID = 0);
	
	///告警明细查询
	virtual BOOL ReqQryWarningQueryTopic(CShfeFtdcReqQryWarningQueryField *pReqQryWarningQuery, int nRequestID = 0);
	
	///网站访问查询
	virtual BOOL ReqQryWebVisitTopic(CShfeFtdcReqQryWebVisitField *pReqQryWebVisit, int nRequestID = 0);
	
	///告警激活变更
	virtual BOOL ReqQryWarningActiveChange(CShfeFtdcReqQryWarningActiveChangeField *pReqQryWarningActiveChange, int nRequestID = 0);
	
	///通用操作
	virtual BOOL ReqQryGeneralOperateTopic(CShfeFtdcReqQryGeneralOperateField *pReqQryGeneralOperate, int nRequestID = 0);
	
	///网络设备连接关系请求
	virtual BOOL ReqQryNetDeviceLinkedTopic(CShfeFtdcReqQryNetDeviceLinkedField *pReqQryNetDeviceLinked, int nRequestID = 0);
	
	///交易系统登录信息请求
	virtual BOOL ReqQryTradeUserLoginStatTopic(CShfeFtdcReqQryTradeUserLoginStatField *pReqQryTradeUserLoginStat, int nRequestID = 0);
	
	///交易系统前置报单响应信息
	virtual BOOL ReqQryTradeFrontOrderRttStatTopic(CShfeFtdcReqQryTradeFrontOrderRttStatField *pReqQryTradeFrontOrderRttStat, int nRequestID = 0);
	
	///会员席位交易状态
	virtual BOOL ReqQryParticTradeOrderStatesTopic(CShfeFtdcReqQryParticTradeOrderStatesField *pReqQryParticTradeOrderStates, int nRequestID = 0);
	
	///系统路由信息
	virtual BOOL ReqQryRouterInfoTopic(CShfeFtdcReqQryRouterInfoField *pReqQryRouterInfo, int nRequestID = 0);
	
	///磁盘I/O信息
	virtual BOOL ReqQryDiskIOTopic(CShfeFtdcReqQryDiskIOField *pReqQryDiskIO, int nRequestID = 0);
	
	///系统状态信息
	virtual BOOL ReqQryStatInfoTopic(CShfeFtdcReqQryStatInfoField *pReqQryStatInfo, int nRequestID = 0);
	
	///交易系统前置报单分布区间
	virtual BOOL ReqQryTradeOrderRttCutLineTopic(CShfeFtdcReqQryTradeOrderRttCutLineField *pReqQryTradeOrderRttCutLine, int nRequestID = 0);
	
	///会员客户信息
	virtual BOOL ReqQryClientInfoTopic(CShfeFtdcReqQryClientInfoField *pReqQryClientInfo, int nRequestID = 0);
	
	///请求事件描述
	virtual BOOL ReqQryEventDescriptionTopic(CShfeFtdcReqQryEventDescriptionField *pReqQryEventDescription, int nRequestID = 0);
	
	///订阅前置唯一ID信息
	virtual BOOL ReqQryFrontUniqueIDTopic(CShfeFtdcReqQryFrontUniqueIDField *pReqQryFrontUniqueID, int nRequestID = 0);
	
	///会员线路地址变更请求
	virtual BOOL ReqQryNetPartyLinkAddrChangeTopic(CShfeFtdcReqQryNetPartyLinkAddrChangeField *pReqQryNetPartyLinkAddrChange, int nRequestID = 0);
	
	///请求已删除会员列表信息
	virtual BOOL ReqQryNetDelPartyLinkInfoTopic(CShfeFtdcReqQryNetDelPartyLinkInfoField *pReqQryNetDelPartyLinkInfo, int nRequestID = 0);
	
	///请求网络性能排序
	virtual BOOL ReqQryPerformanceTopTopic(CShfeFtdcReqQryPerformanceTopField *pReqQryPerformanceTop, int nRequestID = 0);
	
	///请求约状态切换数据
	virtual BOOL ReqQryInstrumentStatusTopic(CShfeFtdcReqQryInstrumentStatusField *pReqQryInstrumentStatus, int nRequestID = 0);
	
	///请求合约交易节信息
	virtual BOOL ReqQryCurrTradingSegmentAttrTopic(CShfeFtdcReqQryCurrTradingSegmentAttrField *pReqQryCurrTradingSegmentAttr, int nRequestID = 0);
	
	///最新网络指标查询
	virtual BOOL ReqQryRealTimeNetObjectAttrTopic(CShfeFtdcReqQryRealTimeNetObjectAttrField *pReqQryRealTimeNetObjectAttr, int nRequestID = 0);
	
	///网络大区划分查询
	virtual BOOL ReqQryNetAreaTopic(CShfeFtdcReqQryNetAreaField *pReqQryNetArea, int nRequestID = 0);
	
	///网络子区查询
	virtual BOOL ReqQryNetSubAreaTopic(CShfeFtdcReqQryNetSubAreaField *pReqQryNetSubArea, int nRequestID = 0);
	
	///网络子区IP查询
	virtual BOOL ReqQryNetSubAreaIPTopic(CShfeFtdcReqQryNetSubAreaIPField *pReqQryNetSubAreaIP, int nRequestID = 0);
	
	///网络设备探测请求
	virtual BOOL ReqQryNetDeviceDetectTopic(CShfeFtdcReqQryNetDeviceDetectField *pReqQryNetDeviceDetect, int nRequestID = 0);
	
	///网络设备查询请求
	virtual BOOL ReqQryNetDeviceRequestTopic(CShfeFtdcReqQryNetDeviceRequestField *pReqQryNetDeviceRequest, int nRequestID = 0);
	
	///大楼查询
	virtual BOOL ReqQryNetBuildingTopic(CShfeFtdcReqQryNetBuildingField *pReqQryNetBuilding, int nRequestID = 0);
	
	///机房查询
	virtual BOOL ReqQryNetRoomTopic(CShfeFtdcReqQryNetRoomField *pReqQryNetRoom, int nRequestID = 0);
	
	///机柜查询
	virtual BOOL ReqQryNetCabinetsTopic(CShfeFtdcReqQryNetCabinetsField *pReqQryNetCabinets, int nRequestID = 0);
	
	///OID
	virtual BOOL ReqQryNetOIDTopic(CShfeFtdcReqQryNetOIDField *pReqQryNetOID, int nRequestID = 0);
	
	///时间策略
	virtual BOOL ReqQryNetTimePolicyTopic(CShfeFtdcReqQryNetTimePolicyField *pReqQryNetTimePolicy, int nRequestID = 0);
	
	///采集任务查询
	virtual BOOL ReqQryNetGatherTaskTopic(CShfeFtdcReqQryNetGatherTaskField *pReqQryNetGatherTask, int nRequestID = 0);
	
	///设备变更请求
	virtual BOOL ReqQryNetDeviceChgTopic(CShfeFtdcReqQryNetDeviceChgField *pReqQryNetDeviceChg, int nRequestID = 0);
	
	///常用设备型号请求
	virtual BOOL ReqQryNetDeviceTypeTopic(CShfeFtdcReqQryNetDeviceTypeField *pReqQryNetDeviceType, int nRequestID = 0);
	
	///常用设备类别请求
	virtual BOOL ReqQryNetDeviceCategoryTopic(CShfeFtdcReqQryNetDeviceCategoryField *pReqQryNetDeviceCategory, int nRequestID = 0);
	
	///设备厂商请求
	virtual BOOL ReqQryNetManufactoryTopic(CShfeFtdcReqQryNetManufactoryField *pReqQryNetManufactory, int nRequestID = 0);
	
	///设备共同体请求
	virtual BOOL ReqQryNetCommunityTopic(CShfeFtdcReqQryNetCommunityField *pReqQryNetCommunity, int nRequestID = 0);
	
	///端口类型请求
	virtual BOOL ReqQryNetPortTypeTopic(CShfeFtdcReqQryNetPortTypeField *pReqQryNetPortType, int nRequestID = 0);
	
	///会员接入地点请求
	virtual BOOL ReqQryNetPartAccessSpotTopic(CShfeFtdcReqQryNetPartAccessSpotField *pReqQryNetPartAccessSpot, int nRequestID = 0);
	
	///端口请求
	virtual BOOL ReqQryNetInterfaceTopic(CShfeFtdcReqQryNetInterfaceField *pReqQryNetInterface, int nRequestID = 0);
	
	///GeneralOID请求
	virtual BOOL ReqQryNetGeneralOIDTopic(CShfeFtdcReqQryNetGeneralOIDField *pReqQryNetGeneralOID, int nRequestID = 0);
	
	///监控对象类别
	virtual BOOL ReqQryNetMonitorTypeTopic(CShfeFtdcReqQryNetMonitorTypeField *pReqQryNetMonitorType, int nRequestID = 0);
	
	///指标统表
	virtual BOOL ReqQryNetMonitorAttrScopeTopic(CShfeFtdcReqQryNetMonitorAttrScopeField *pReqQryNetMonitorAttrScope, int nRequestID = 0);
	
	///监控指标表
	virtual BOOL ReqQryNetMonitorAttrTypeTopic(CShfeFtdcReqQryNetMonitorAttrTypeField *pReqQryNetMonitorAttrType, int nRequestID = 0);
	
	///监控对象指标表
	virtual BOOL ReqQryNetMonitorObjectAttrTopic(CShfeFtdcReqQryNetMonitorObjectAttrField *pReqQryNetMonitorObjectAttr, int nRequestID = 0);
	
	///设备对象组表
	virtual BOOL ReqQryNetMonitorDeviceGroupTopic(CShfeFtdcReqQryNetMonitorDeviceGroupField *pReqQryNetMonitorDeviceGroup, int nRequestID = 0);
	
	///任务信息表
	virtual BOOL ReqQryNetMonitorTaskInfoTopic(CShfeFtdcReqQryNetMonitorTaskInfoField *pReqQryNetMonitorTaskInfo, int nRequestID = 0);
	
	///任务结果表
	virtual BOOL ReqQryNetMonitorTaskResultTopic(CShfeFtdcReqQryNetMonitorTaskResultField *pReqQryNetMonitorTaskResult, int nRequestID = 0);
	
	///任务对象集
	virtual BOOL ReqQryNetMonitorTaskObjectSetTopic(CShfeFtdcReqQryNetMonitorTaskObjectSetField *pReqQryNetMonitorTaskObjectSet, int nRequestID = 0);
	
	///会员链路信息表
	virtual BOOL ReqQryNetPartyLinkInfoTopic(CShfeFtdcReqQryNetPartyLinkInfoField *pReqQryNetPartyLinkInfo, int nRequestID = 0);
	
	///监控动作指标对照表
	virtual BOOL ReqQryNetMonitorActionAttrTopic(CShfeFtdcReqQryNetMonitorActionAttrField *pReqQryNetMonitorActionAttr, int nRequestID = 0);
	
	///模块
	virtual BOOL ReqQryNetModuleTopic(CShfeFtdcReqQryNetModuleField *pReqQryNetModule, int nRequestID = 0);
	
	///任务结果状态表
	virtual BOOL ReqQryNetMonitorTaskStatusResultTopic(CShfeFtdcReqQryNetMonitorTaskStatusResultField *pReqQryNetMonitorTaskStatusResult, int nRequestID = 0);
	
	///设备配置表
	virtual BOOL ReqQryNetCfgFileTopic(CShfeFtdcReqQryNetCfgFileField *pReqQryNetCfgFile, int nRequestID = 0);
	
	///任务结果规则分析表
	virtual BOOL ReqQryNetMonitorDeviceTaskTopic(CShfeFtdcReqQryNetMonitorDeviceTaskField *pReqQryNetMonitorDeviceTask, int nRequestID = 0);
	
	///文件通用操作
	virtual BOOL ReqQryFileGeneralOperTopic(CShfeFtdcReqQryFileGeneralOperField *pReqQryFileGeneralOper, int nRequestID = 0);
	
	///基线表
	virtual BOOL ReqQryNetBaseLineTopic(CShfeFtdcReqQryNetBaseLineField *pReqQryNetBaseLine, int nRequestID = 0);
	
	///基线结果表
	virtual BOOL ReqQryNetBaseLineResultTopic(CShfeFtdcReqQryNetBaseLineResultField *pReqQryNetBaseLineResult, int nRequestID = 0);
	
	///会员链路状态信息表
	virtual BOOL ReqQryNetPartyLinkStatusInfoTopic(CShfeFtdcReqQryNetPartyLinkStatusInfoField *pReqQryNetPartyLinkStatusInfo, int nRequestID = 0);
	
	///本地ping结果
	virtual BOOL ReqQryNetLocalPingResultInfoTopic(CShfeFtdcReqQryNetLocalPingResultInfoField *pReqQryNetLocalPingResultInfo, int nRequestID = 0);
	
	///远程ping结果
	virtual BOOL ReqQryNetRomotePingResultInfoTopic(CShfeFtdcReqQryNetRomotePingResultInfoField *pReqQryNetRomotePingResultInfo, int nRequestID = 0);
	
	///请求非会员链路表信息
	virtual BOOL ReqQryNetNonPartyLinkInfoTopic(CShfeFtdcReqQryNetNonPartyLinkInfoField *pReqQryNetNonPartyLinkInfo, int nRequestID = 0);
	

	///订阅CPU应答
	virtual BOOL SubRtnTopCpuInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅CPU应答
	virtual BOOL UnsubRtnTopCpuInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅Mem应答
	virtual BOOL SubRtnTopMemInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅Mem应答
	virtual BOOL UnsubRtnTopMemInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅process应答
	virtual BOOL SubRtnTopProcessInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅process应答
	virtual BOOL UnsubRtnTopProcessInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅filesystem应答
	virtual BOOL SubRtnFileSystemInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅filesystem应答
	virtual BOOL UnsubRtnFileSystemInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅network应答
	virtual BOOL SubRtnNetworkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅network应答
	virtual BOOL UnsubRtnNetworkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅主机环境信息应答
	virtual BOOL SubRtnHostEnvTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅主机环境信息应答
	virtual BOOL UnsubRtnHostEnvTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅获得监控对象信息应答
	virtual BOOL SubRtnMonitorObjectTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅获得监控对象信息应答
	virtual BOOL UnsubRtnMonitorObjectTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅获得业务进程和主机的对应关系应答
	virtual BOOL SubRtnObjectRationalTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅获得业务进程和主机的对应关系应答
	virtual BOOL UnsubRtnObjectRationalTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅日志文件内容应答
	virtual BOOL SubRtnSyslogInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅日志文件内容应答
	virtual BOOL UnsubRtnSyslogInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅对象关系查询应答
	virtual BOOL SubRtnOidRelationTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅对象关系查询应答
	virtual BOOL UnsubRtnOidRelationTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅用户信息查询请求应答
	virtual BOOL SubRtnUserInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅用户信息查询请求应答
	virtual BOOL UnsubRtnUserInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅在线用户信息查询请求应答
	virtual BOOL SubRtnOnlineUserInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅在线用户信息查询请求应答
	virtual BOOL UnsubRtnOnlineUserInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅告警事件查询请求应答
	virtual BOOL SubRtnWarningEventTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅告警事件查询请求应答
	virtual BOOL UnsubRtnWarningEventTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅对象状态指标查询应答
	virtual BOOL SubRtnObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅对象状态指标查询应答
	virtual BOOL UnsubRtnObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅无效报单查询应答
	virtual BOOL SubRtnInvalidateOrderTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅无效报单查询应答
	virtual BOOL UnsubRtnInvalidateOrderTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅报单状态查询应答
	virtual BOOL SubRtnOrderStatusTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅报单状态查询应答
	virtual BOOL UnsubRtnOrderStatusTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅报单成交查询应答
	virtual BOOL SubRtnBargainOrderTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅报单成交查询应答
	virtual BOOL UnsubRtnBargainOrderTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅合约基本属性查询应答
	virtual BOOL SubRtnInstPropertyTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅合约基本属性查询应答
	virtual BOOL UnsubRtnInstPropertyTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅合约保证金率查询应答
	virtual BOOL SubRtnMarginRateTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅合约保证金率查询应答
	virtual BOOL UnsubRtnMarginRateTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅合约涨跌停板查询应答
	virtual BOOL SubRtnPriceLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅合约涨跌停板查询应答
	virtual BOOL UnsubRtnPriceLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅会员限仓查询应答
	virtual BOOL SubRtnPartPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅会员限仓查询应答
	virtual BOOL UnsubRtnPartPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅客户限仓查询应答
	virtual BOOL SubRtnClientPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅客户限仓查询应答
	virtual BOOL UnsubRtnClientPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅特殊客户限仓查询应答
	virtual BOOL SubRtnSpecialPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅特殊客户限仓查询应答
	virtual BOOL UnsubRtnSpecialPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅账户出入金查询应答
	virtual BOOL SubRtnTransactionChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅账户出入金查询应答
	virtual BOOL UnsubRtnTransactionChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅客户数据变动查询应答
	virtual BOOL SubRtnClientChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅客户数据变动查询应答
	virtual BOOL UnsubRtnClientChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅会员客户对照变动查询应答
	virtual BOOL SubRtnPartClientChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅会员客户对照变动查询应答
	virtual BOOL UnsubRtnPartClientChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅限仓数据变动查询应答
	virtual BOOL SubRtnPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅限仓数据变动查询应答
	virtual BOOL UnsubRtnPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅保值额度变动查询应答
	virtual BOOL SubRtnHedgeDetailChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅保值额度变动查询应答
	virtual BOOL UnsubRtnHedgeDetailChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅会员变动查询应答
	virtual BOOL SubRtnParticipantChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅会员变动查询应答
	virtual BOOL UnsubRtnParticipantChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅保证金率变动查询应答
	virtual BOOL SubRtnMarginRateChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅保证金率变动查询应答
	virtual BOOL UnsubRtnMarginRateChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅IP地址变动查询应答
	virtual BOOL SubRtnUserIpChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅IP地址变动查询应答
	virtual BOOL UnsubRtnUserIpChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅限仓数据变动查询应答
	virtual BOOL SubRtnClientPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅限仓数据变动查询应答
	virtual BOOL UnsubRtnClientPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅限仓数据变动查询应答
	virtual BOOL SubRtnSpecPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅限仓数据变动查询应答
	virtual BOOL UnsubRtnSpecPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅历史对象状态指标查询应答
	virtual BOOL SubRtnHistoryObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅历史对象状态指标查询应答
	virtual BOOL UnsubRtnHistoryObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅前置响应信息查询应答
	virtual BOOL SubRtnFrontInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅前置响应信息查询应答
	virtual BOOL UnsubRtnFrontInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅会员初始化应答
	virtual BOOL SubRtnParticipantInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅会员初始化应答
	virtual BOOL UnsubRtnParticipantInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅座席初始化应答
	virtual BOOL SubRtnUserInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅座席初始化应答
	virtual BOOL UnsubRtnUserInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅客户初始化应答
	virtual BOOL SubRtnClientInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅客户初始化应答
	virtual BOOL UnsubRtnClientInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅交易日志查询应答
	virtual BOOL SubRtnTradeLogTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅交易日志查询应答
	virtual BOOL UnsubRtnTradeLogTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅交易系统登录信息
	virtual BOOL SubRtnTradeUserLoginInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅交易系统登录信息
	virtual BOOL UnsubRtnTradeUserLoginInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅
	virtual BOOL SubRtnUpdateSysConfigTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅
	virtual BOOL UnsubRtnUpdateSysConfigTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅
	virtual BOOL SubRtnSysUser(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅
	virtual BOOL UnsubRtnSysUser(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅监控系统时钟同步
	virtual BOOL SubRtnSysTimeSyncTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅监控系统时钟同步
	virtual BOOL UnsubRtnSysTimeSyncTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅数据中心切换通知
	virtual BOOL SubRtnDataCenterChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅数据中心切换通知
	virtual BOOL UnsubRtnDataCenterChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅日志事件应答
	virtual BOOL SubRtnSyslogEventTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅日志事件应答
	virtual BOOL UnsubRtnSyslogEventTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅Web应用信息
	virtual BOOL SubRtnWebAppInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅Web应用信息
	virtual BOOL UnsubRtnWebAppInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅应用servlet信息
	virtual BOOL SubRtnServletInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅应用servlet信息
	virtual BOOL UnsubRtnServletInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅文件信息
	virtual BOOL SubRtnFileInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅文件信息
	virtual BOOL UnsubRtnFileInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅应用会话信息
	virtual BOOL SubRtnSessionInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅应用会话信息
	virtual BOOL UnsubRtnSessionInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅JDBC信息
	virtual BOOL SubRtnJDBCInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅JDBC信息
	virtual BOOL UnsubRtnJDBCInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅线程信息
	virtual BOOL SubRtnThreadInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅线程信息
	virtual BOOL UnsubRtnThreadInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅虚拟机信息
	virtual BOOL SubRtnVMInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅虚拟机信息
	virtual BOOL UnsubRtnVMInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅系统属性信息
	virtual BOOL SubRtnPropertyInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅系统属性信息
	virtual BOOL UnsubRtnPropertyInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅系统内存池信息
	virtual BOOL SubRtnMemPoolInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅系统内存池信息
	virtual BOOL UnsubRtnMemPoolInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅文件内容信息
	virtual BOOL SubRtnFileContentInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅文件内容信息
	virtual BOOL UnsubRtnFileContentInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅连接信息
	virtual BOOL SubRtnConnectionInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅连接信息
	virtual BOOL UnsubRtnConnectionInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅连接器信息
	virtual BOOL SubRtnConnectorInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅连接器信息
	virtual BOOL UnsubRtnConnectorInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅数据库查询应答
	virtual BOOL SubRtnDBQueryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅数据库查询应答
	virtual BOOL UnsubRtnDBQueryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅通用返回应答
	virtual BOOL SubRtnGeneralFieldTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅通用返回应答
	virtual BOOL UnsubRtnGeneralFieldTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅告警激活变更
	virtual BOOL SubRtnWarningActiveChange(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅告警激活变更
	virtual BOOL UnsubRtnWarningActiveChange(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅通用操作
	virtual BOOL SubRtnGeneralOperateTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅通用操作
	virtual BOOL UnsubRtnGeneralOperateTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅网络设备连接关系
	virtual BOOL SubRtnNetDeviceLinkedTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅网络设备连接关系
	virtual BOOL UnsubRtnNetDeviceLinkedTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅交易系统前置报单响应信息
	virtual BOOL SubRtnTradeFrontOrderRttStatTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅交易系统前置报单响应信息
	virtual BOOL UnsubRtnTradeFrontOrderRttStatTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅会员席位交易状态
	virtual BOOL SubRtnParticTradeOrderStatesTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅会员席位交易状态
	virtual BOOL UnsubRtnParticTradeOrderStatesTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅系统路由信息
	virtual BOOL SubRtnRouterInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅系统路由信息
	virtual BOOL UnsubRtnRouterInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅磁盘I/O信息
	virtual BOOL SubRtnDiskIOTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅磁盘I/O信息
	virtual BOOL UnsubRtnDiskIOTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅系统状态信息
	virtual BOOL SubRtnStatInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅系统状态信息
	virtual BOOL UnsubRtnStatInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅交易系统前置报单分布区间
	virtual BOOL SubRtnTradeOrderRttCutLineTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅交易系统前置报单分布区间
	virtual BOOL UnsubRtnTradeOrderRttCutLineTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅会员客户信息
	virtual BOOL SubRtnClientInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅会员客户信息
	virtual BOOL UnsubRtnClientInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅订阅事件描述
	virtual BOOL SubRtnEventDescriptionTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅订阅事件描述
	virtual BOOL UnsubRtnEventDescriptionTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅订阅前置唯一ID信息
	virtual BOOL SubRtnFrontUniqueIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅订阅前置唯一ID信息
	virtual BOOL UnsubRtnFrontUniqueIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅订阅会员线路地址变更信息
	virtual BOOL SubRtnNetPartyLinkAddrChangeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅订阅会员线路地址变更信息
	virtual BOOL UnsubRtnNetPartyLinkAddrChangeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅订阅已删除会员列表信息
	virtual BOOL SubRtnNetDelPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅订阅已删除会员列表信息
	virtual BOOL UnsubRtnNetDelPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅订阅网络性能排序
	virtual BOOL SubRtnPerformanceTopTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅订阅网络性能排序
	virtual BOOL UnsubRtnPerformanceTopTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅订阅约状态切换数据
	virtual BOOL SubRtnInstrumentStatusTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅订阅约状态切换数据
	virtual BOOL UnsubRtnInstrumentStatusTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅订阅合约交易节信息
	virtual BOOL SubRtnCurrTradingSegmentAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅订阅合约交易节信息
	virtual BOOL UnsubRtnCurrTradingSegmentAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅网络大区划分应答
	virtual BOOL SubRtnNetAreaTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅网络大区划分应答
	virtual BOOL UnsubRtnNetAreaTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅网络子区应答
	virtual BOOL SubRtnNetSubAreaTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅网络子区应答
	virtual BOOL UnsubRtnNetSubAreaTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅网络子区IP应答
	virtual BOOL SubRtnNetSubAreaIPTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅网络子区IP应答
	virtual BOOL UnsubRtnNetSubAreaIPTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅网络设备
	virtual BOOL SubRtnNetDeviceTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅网络设备
	virtual BOOL UnsubRtnNetDeviceTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅大楼
	virtual BOOL SubRtnNetBuildingTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅大楼
	virtual BOOL UnsubRtnNetBuildingTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅机房
	virtual BOOL SubRtnNetRoomTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅机房
	virtual BOOL UnsubRtnNetRoomTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅机柜
	virtual BOOL SubRtnNetCabinetsTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅机柜
	virtual BOOL UnsubRtnNetCabinetsTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅OID
	virtual BOOL SubRtnNetOIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅OID
	virtual BOOL UnsubRtnNetOIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅时间策略
	virtual BOOL SubRtnNetTimePolicyTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅时间策略
	virtual BOOL UnsubRtnNetTimePolicyTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅采集任务
	virtual BOOL SubRtnNetGatherTaskTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅采集任务
	virtual BOOL UnsubRtnNetGatherTaskTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅设备变更
	virtual BOOL SubRtnNetDeviceChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅设备变更
	virtual BOOL UnsubRtnNetDeviceChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅常用设备型号
	virtual BOOL SubRtnNetDeviceTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅常用设备型号
	virtual BOOL UnsubRtnNetDeviceTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅常用设备类别
	virtual BOOL SubRtnNetDeviceCategoryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅常用设备类别
	virtual BOOL UnsubRtnNetDeviceCategoryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅设备厂商
	virtual BOOL SubRtnNetManufactoryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅设备厂商
	virtual BOOL UnsubRtnNetManufactoryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅设备共同体
	virtual BOOL SubRtnNetCommunityTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅设备共同体
	virtual BOOL UnsubRtnNetCommunityTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅端口类型
	virtual BOOL SubRtnNetPortTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅端口类型
	virtual BOOL UnsubRtnNetPortTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅会员接入地点
	virtual BOOL SubRtnNetPartAccessSpotTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅会员接入地点
	virtual BOOL UnsubRtnNetPartAccessSpotTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅端口
	virtual BOOL SubRtnNetInterfaceTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅端口
	virtual BOOL UnsubRtnNetInterfaceTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅GeneralOID
	virtual BOOL SubRtnNetGeneralOIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅GeneralOID
	virtual BOOL UnsubRtnNetGeneralOIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅监控对象类别
	virtual BOOL SubRtnNetMonitorTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅监控对象类别
	virtual BOOL UnsubRtnNetMonitorTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅指标统表
	virtual BOOL SubRtnNetMonitorAttrScopeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅指标统表
	virtual BOOL UnsubRtnNetMonitorAttrScopeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅监控指标表
	virtual BOOL SubRtnNetMonitorAttrTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅监控指标表
	virtual BOOL UnsubRtnNetMonitorAttrTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅监控对象指标表
	virtual BOOL SubRtnNetMonitorObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅监控对象指标表
	virtual BOOL UnsubRtnNetMonitorObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅设备对象组表
	virtual BOOL SubRtnNetMonitorDeviceGroupTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅设备对象组表
	virtual BOOL UnsubRtnNetMonitorDeviceGroupTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅任务信息表
	virtual BOOL SubRtnNetMonitorTaskInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅任务信息表
	virtual BOOL UnsubRtnNetMonitorTaskInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅任务结果表
	virtual BOOL SubRtnNetMonitorTaskResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅任务结果表
	virtual BOOL UnsubRtnNetMonitorTaskResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅任务对象集
	virtual BOOL SubRtnNetMonitorTaskObjectSetTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅任务对象集
	virtual BOOL UnsubRtnNetMonitorTaskObjectSetTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅会员链路信息表
	virtual BOOL SubRtnNetPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅会员链路信息表
	virtual BOOL UnsubRtnNetPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅模块
	virtual BOOL SubRtnNetModuleTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅模块
	virtual BOOL UnsubRtnNetModuleTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅任务结果状态表
	virtual BOOL SubRtnNetMonitorTaskStatusResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅任务结果状态表
	virtual BOOL UnsubRtnNetMonitorTaskStatusResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅设备配置表
	virtual BOOL SubRtnNetCfgFileTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅设备配置表
	virtual BOOL UnsubRtnNetCfgFileTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅任务结果规则分析表
	virtual BOOL SubRtnNetMonitorDeviceTaskTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅任务结果规则分析表
	virtual BOOL UnsubRtnNetMonitorDeviceTaskTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅文件通用操作
	virtual BOOL SubRtnFileGeneralOperTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅文件通用操作
	virtual BOOL UnsubRtnFileGeneralOperTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅基线表
	virtual BOOL SubRtnNetBaseLineTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅基线表
	virtual BOOL UnsubRtnNetBaseLineTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅基线结果表
	virtual BOOL SubRtnNetBaseLineResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅基线结果表
	virtual BOOL UnsubRtnNetBaseLineResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅会员链路状态信息表
	virtual BOOL SubRtnNetPartyLinkStatusInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅会员链路状态信息表
	virtual BOOL UnsubRtnNetPartyLinkStatusInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅本地ping结果
	virtual BOOL SubRtnNetLocalPingResultInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅本地ping结果
	virtual BOOL UnsubRtnNetLocalPingResultInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅远程ping结果
	virtual BOOL SubRtnNetRomotePingResultInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅远程ping结果
	virtual BOOL UnsubRtnNetRomotePingResultInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅订阅会员链路费用表
	virtual BOOL SubRtnMemberLinkCostTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅订阅会员链路费用表
	virtual BOOL UnsubRtnMemberLinkCostTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	///订阅订阅非会员链路表信息
	virtual BOOL SubRtnNetNonPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///取消订阅订阅非会员链路表信息
	virtual BOOL UnsubRtnNetNonPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	
private:
	BOOL SubscriberTopic(TShfeFtdcTypeSubcriberObjectIDType ObjectID,   TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum ,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID);
	BOOL UnsubscriberTopic(TShfeFtdcTypeSubcriberObjectIDType ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID);
};


#endif
