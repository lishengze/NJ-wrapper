
#include "stdafx.h"
#include "UserApiEntry.h"

list<EventSubInfo> g_EventSubList;

///////////////////////////////////////////////////////////////////////////////////////////////////
// CSysApiDataEntry
CSysApiDataEntry::CSysApiDataEntry(void)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CList<LPVOID> &lstDataEntry = dispatcher.GetUserApiHandler().GetConnectionStateRegister();
	lstDataEntry.AddTail((LPVOID)this);
}

CSysApiDataEntry::~CSysApiDataEntry(void)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	
	CList<LPVOID> &lstDataEntry = dispatcher.GetUserApiHandler().GetConnectionStateRegister();
	POSITION pos = lstDataEntry.Find((LPVOID)this);
	if (pos) lstDataEntry.RemoveAt(pos);
	
	///清除请求队列中与之相关的未完成请求
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();
	Queue.RemoveBySender((LPVOID)this);
	
	///清除CPU应答订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnTopCpuInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除Mem应答订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnTopMemInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除process应答订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnTopProcessInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除filesystem应答订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnFileSystemInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除network应答订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnNetworkInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除主机环境信息应答订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnHostEnvTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除获得监控对象信息应答订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnMonitorObjectTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除获得业务进程和主机的对应关系应答订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnObjectRationalTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除日志文件内容应答订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnSyslogInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除对象关系查询应答订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnOidRelationTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除用户信息查询请求应答订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnUserInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除在线用户信息查询请求应答订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnOnlineUserInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除告警事件查询请求应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnWarningEventTopicRegister().remove((void*)this);
	///清除对象状态指标查询应答订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnObjectAttrTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除无效报单查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnInvalidateOrderTopicRegister().remove((void*)this);
	///清除报单状态查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnOrderStatusTopicRegister().remove((void*)this);
	///清除报单成交查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnBargainOrderTopicRegister().remove((void*)this);
	///清除合约基本属性查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnInstPropertyTopicRegister().remove((void*)this);
	///清除合约保证金率查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnMarginRateTopicRegister().remove((void*)this);
	///清除合约涨跌停板查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnPriceLimitTopicRegister().remove((void*)this);
	///清除会员限仓查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnPartPosiLimitTopicRegister().remove((void*)this);
	///清除客户限仓查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnClientPosiLimitTopicRegister().remove((void*)this);
	///清除特殊客户限仓查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnSpecialPosiLimitTopicRegister().remove((void*)this);
	///清除账户出入金查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnTransactionChgTopicRegister().remove((void*)this);
	///清除客户数据变动查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnClientChgTopicRegister().remove((void*)this);
	///清除会员客户对照变动查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnPartClientChgTopicRegister().remove((void*)this);
	///清除限仓数据变动查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnPosiLimitChgTopicRegister().remove((void*)this);
	///清除保值额度变动查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnHedgeDetailChgTopicRegister().remove((void*)this);
	///清除会员变动查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnParticipantChgTopicRegister().remove((void*)this);
	///清除保证金率变动查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnMarginRateChgTopicRegister().remove((void*)this);
	///清除IP地址变动查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnUserIpChgTopicRegister().remove((void*)this);
	///清除限仓数据变动查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnClientPosiLimitChgTopicRegister().remove((void*)this);
	///清除限仓数据变动查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnSpecPosiLimitChgTopicRegister().remove((void*)this);
	///清除历史对象状态指标查询应答订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnHistoryObjectAttrTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除前置响应信息查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnFrontInfoTopicRegister().remove((void*)this);
	///清除会员初始化应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnParticipantInitTopicRegister().remove((void*)this);
	///清除座席初始化应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnUserInitTopicRegister().remove((void*)this);
	///清除客户初始化应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnClientInitTopicRegister().remove((void*)this);
	///清除交易日志查询应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnTradeLogTopicRegister().remove((void*)this);
	///清除交易系统登录信息订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnTradeUserLoginInfoTopicRegister().remove((void*)this);
	///清除订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnUpdateSysConfigTopicRegister().remove((void*)this);
	///清除订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnSysUserRegister().remove((void*)this);
	///清除监控系统时钟同步订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnSysTimeSyncTopicRegister().remove((void*)this);
	///清除数据中心切换通知订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnDataCenterChgTopicRegister().remove((void*)this);
	///清除日志事件应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnSyslogEventTopicRegister().remove((void*)this);
	///清除Web应用信息订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnWebAppInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除应用servlet信息订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnServletInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除文件信息订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnFileInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除应用会话信息订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnSessionInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除JDBC信息订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnJDBCInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除线程信息订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnThreadInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除虚拟机信息订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnVMInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除系统属性信息订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnPropertyInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除系统内存池信息订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnMemPoolInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除文件内容信息订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnFileContentInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除连接信息订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnConnectionInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除连接器信息订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnConnectorInfoTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除数据库查询应答订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnDBQueryTopicRegister();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
	///清除通用返回应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnGeneralFieldTopicRegister().remove((void*)this);
	///清除告警激活变更订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnWarningActiveChangeRegister().remove((void*)this);
	///清除通用操作订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnGeneralOperateTopicRegister().remove((void*)this);
	///清除网络设备连接关系订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetDeviceLinkedTopicRegister().remove((void*)this);
	///清除交易系统前置报单响应信息订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnTradeFrontOrderRttStatTopicRegister().remove((void*)this);
	///清除会员席位交易状态订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnParticTradeOrderStatesTopicRegister().remove((void*)this);
	///清除系统路由信息订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnRouterInfoTopicRegister().remove((void*)this);
	///清除磁盘I/O信息订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnDiskIOTopicRegister().remove((void*)this);
	///清除系统状态信息订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnStatInfoTopicRegister().remove((void*)this);
	///清除交易系统前置报单分布区间订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnTradeOrderRttCutLineTopicRegister().remove((void*)this);
	///清除会员客户信息订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnClientInfoTopicRegister().remove((void*)this);
	///清除订阅事件描述订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnEventDescriptionTopicRegister().remove((void*)this);
	///清除订阅前置唯一ID信息订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnFrontUniqueIDTopicRegister().remove((void*)this);
	///清除订阅会员线路地址变更信息订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetPartyLinkAddrChangeTopicRegister().remove((void*)this);
	///清除订阅已删除会员列表信息订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetDelPartyLinkInfoTopicRegister().remove((void*)this);
	///清除订阅网络性能排序订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnPerformanceTopTopicRegister().remove((void*)this);
	///清除订阅约状态切换数据订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnInstrumentStatusTopicRegister().remove((void*)this);
	///清除订阅合约交易节信息订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnCurrTradingSegmentAttrTopicRegister().remove((void*)this);
	///清除网络大区划分应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetAreaTopicRegister().remove((void*)this);
	///清除网络子区应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetSubAreaTopicRegister().remove((void*)this);
	///清除网络子区IP应答订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetSubAreaIPTopicRegister().remove((void*)this);
	///清除网络设备订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetDeviceTopicRegister().remove((void*)this);
	///清除大楼订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetBuildingTopicRegister().remove((void*)this);
	///清除机房订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetRoomTopicRegister().remove((void*)this);
	///清除机柜订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetCabinetsTopicRegister().remove((void*)this);
	///清除OID订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetOIDTopicRegister().remove((void*)this);
	///清除时间策略订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetTimePolicyTopicRegister().remove((void*)this);
	///清除采集任务订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetGatherTaskTopicRegister().remove((void*)this);
	///清除设备变更订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetDeviceChgTopicRegister().remove((void*)this);
	///清除常用设备型号订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetDeviceTypeTopicRegister().remove((void*)this);
	///清除常用设备类别订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetDeviceCategoryTopicRegister().remove((void*)this);
	///清除设备厂商订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetManufactoryTopicRegister().remove((void*)this);
	///清除设备共同体订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetCommunityTopicRegister().remove((void*)this);
	///清除端口类型订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetPortTypeTopicRegister().remove((void*)this);
	///清除会员接入地点订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetPartAccessSpotTopicRegister().remove((void*)this);
	///清除端口订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetInterfaceTopicRegister().remove((void*)this);
	///清除GeneralOID订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetGeneralOIDTopicRegister().remove((void*)this);
	///清除监控对象类别订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetMonitorTypeTopicRegister().remove((void*)this);
	///清除指标统表订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetMonitorAttrScopeTopicRegister().remove((void*)this);
	///清除监控指标表订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetMonitorAttrTypeTopicRegister().remove((void*)this);
	///清除监控对象指标表订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetMonitorObjectAttrTopicRegister().remove((void*)this);
	///清除设备对象组表订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetMonitorDeviceGroupTopicRegister().remove((void*)this);
	///清除任务信息表订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetMonitorTaskInfoTopicRegister().remove((void*)this);
	///清除任务结果表订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetMonitorTaskResultTopicRegister().remove((void*)this);
	///清除任务对象集订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetMonitorTaskObjectSetTopicRegister().remove((void*)this);
	///清除会员链路信息表订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetPartyLinkInfoTopicRegister().remove((void*)this);
	///清除模块订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetModuleTopicRegister().remove((void*)this);
	///清除任务结果状态表订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetMonitorTaskStatusResultTopicRegister().remove((void*)this);
	///清除设备配置表订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetCfgFileTopicRegister().remove((void*)this);
	///清除任务结果规则分析表订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetMonitorDeviceTaskTopicRegister().remove((void*)this);
	///清除文件通用操作订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnFileGeneralOperTopicRegister().remove((void*)this);
	///清除基线表订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetBaseLineTopicRegister().remove((void*)this);
	///清除基线结果表订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetBaseLineResultTopicRegister().remove((void*)this);
	///清除会员链路状态信息表订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetPartyLinkStatusInfoTopicRegister().remove((void*)this);
	///清除本地ping结果订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetLocalPingResultInfoTopicRegister().remove((void*)this);
	///清除远程ping结果订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetRomotePingResultInfoTopicRegister().remove((void*)this);
	///清除订阅会员链路费用表订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnMemberLinkCostTopicRegister().remove((void*)this);
	///清除订阅非会员链路表信息订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().GetRtnNetNonPartyLinkInfoTopicRegister().remove((void*)this);
}


///CPU查询
BOOL CSysApiDataEntry::ReqQryTopCpuInfoTopic(CShfeFtdcReqQryTopCpuInfoField *pReqQryTopCpuInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTopCpuInfoTopic(pReqQryTopCpuInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///Mem查询
BOOL CSysApiDataEntry::ReqQryTopMemInfoTopic(CShfeFtdcReqQryTopMemInfoField *pReqQryTopMemInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTopMemInfoTopic(pReqQryTopMemInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///process查询
BOOL CSysApiDataEntry::ReqQryTopProcessInfoTopic(CShfeFtdcReqQryTopProcessInfoField *pReqQryTopProcessInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTopProcessInfoTopic(pReqQryTopProcessInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///filesystem查询
BOOL CSysApiDataEntry::ReqQryFileSystemInfoTopic(CShfeFtdcReqQryFileSystemInfoField *pReqQryFileSystemInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryFileSystemInfoTopic(pReqQryFileSystemInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///network查询
BOOL CSysApiDataEntry::ReqQryNetworkInfoTopic(CShfeFtdcReqQryNetworkInfoField *pReqQryNetworkInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetworkInfoTopic(pReqQryNetworkInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///主机环境信息查询
BOOL CSysApiDataEntry::ReqQryHostEnvTopic(CShfeFtdcReqQryHostEnvField *pReqQryHostEnv, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryHostEnvTopic(pReqQryHostEnv, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///获得监控对象信息查询
BOOL CSysApiDataEntry::ReqQryMonitorObjectTopic(CShfeFtdcReqQryMonitorObjectField *pReqQryMonitorObject, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryMonitorObjectTopic(pReqQryMonitorObject, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///获得业务进程和主机的对应关系查询
BOOL CSysApiDataEntry::ReqQryObjectRationalTopic(CShfeFtdcReqQryObjectRationalField *pReqQryObjectRational, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryObjectRationalTopic(pReqQryObjectRational, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///日志文件内容查询
BOOL CSysApiDataEntry::ReqQrySyslogInfoTopic(CShfeFtdcReqQrySyslogInfoField *pReqQrySyslogInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySyslogInfoTopic(pReqQrySyslogInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///监控内容订阅请求
BOOL CSysApiDataEntry::ReqQrySubscriberTopic(CShfeFtdcReqQrySubscriberField *pReqQrySubscriber, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySubscriberTopic(pReqQrySubscriber, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///对象关系查询
BOOL CSysApiDataEntry::ReqQryOidRelationTopic(CShfeFtdcReqQryOidRelationField *pReqQryOidRelation, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryOidRelationTopic(pReqQryOidRelation, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///用户信息查询请求
BOOL CSysApiDataEntry::ReqQryUserInfoTopic(CShfeFtdcReqQryUserInfoField *pReqQryUserInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryUserInfoTopic(pReqQryUserInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///在线用户信息查询请求
BOOL CSysApiDataEntry::ReqQryOnlineUserInfoTopic(CShfeFtdcReqQryOnlineUserInfoField *pReqQryOnlineUserInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryOnlineUserInfoTopic(pReqQryOnlineUserInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///告警事件查询请求
BOOL CSysApiDataEntry::ReqQryWarningEventTopic(CShfeFtdcReqQryWarningEventField *pReqQryWarningEvent, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryWarningEventTopic(pReqQryWarningEvent, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///对象状态指标查询
BOOL CSysApiDataEntry::ReqQryObjectAttrTopic(CShfeFtdcReqQryObjectAttrField *pReqQryObjectAttr, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryObjectAttrTopic(pReqQryObjectAttr, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///无效报单查询
BOOL CSysApiDataEntry::ReqQryInvalidateOrderTopic(CShfeFtdcReqQryInvalidateOrderField *pReqQryInvalidateOrder, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryInvalidateOrderTopic(pReqQryInvalidateOrder, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///报单状态查询
BOOL CSysApiDataEntry::ReqQryOrderStatusTopic(CShfeFtdcReqQryOrderStatusField *pReqQryOrderStatus, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryOrderStatusTopic(pReqQryOrderStatus, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///报单成交查询
BOOL CSysApiDataEntry::ReqQryBargainOrderTopic(CShfeFtdcReqQryBargainOrderField *pReqQryBargainOrder, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryBargainOrderTopic(pReqQryBargainOrder, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///合约基本属性查询
BOOL CSysApiDataEntry::ReqQryInstPropertyTopic(CShfeFtdcReqQryInstPropertyField *pReqQryInstProperty, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryInstPropertyTopic(pReqQryInstProperty, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///合约保证金率查询
BOOL CSysApiDataEntry::ReqQryMarginRateTopic(CShfeFtdcReqQryMarginRateField *pReqQryMarginRate, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryMarginRateTopic(pReqQryMarginRate, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///合约涨跌停板查询
BOOL CSysApiDataEntry::ReqQryPriceLimitTopic(CShfeFtdcReqQryPriceLimitField *pReqQryPriceLimit, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryPriceLimitTopic(pReqQryPriceLimit, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///会员限仓查询
BOOL CSysApiDataEntry::ReqQryPartPosiLimitTopic(CShfeFtdcReqQryPartPosiLimitField *pReqQryPartPosiLimit, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryPartPosiLimitTopic(pReqQryPartPosiLimit, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///客户限仓查询
BOOL CSysApiDataEntry::ReqQryClientPosiLimitTopic(CShfeFtdcReqQryClientPosiLimitField *pReqQryClientPosiLimit, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryClientPosiLimitTopic(pReqQryClientPosiLimit, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///特殊客户限仓查询
BOOL CSysApiDataEntry::ReqQrySpecialPosiLimitTopic(CShfeFtdcReqQrySpecialPosiLimitField *pReqQrySpecialPosiLimit, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySpecialPosiLimitTopic(pReqQrySpecialPosiLimit, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///账户出入金查询
BOOL CSysApiDataEntry::ReqQryTransactionChgTopic(CShfeFtdcReqQryTransactionChgField *pReqQryTransactionChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTransactionChgTopic(pReqQryTransactionChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///客户数据变动查询
BOOL CSysApiDataEntry::ReqQryClientChgTopic(CShfeFtdcReqQryClientChgField *pReqQryClientChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryClientChgTopic(pReqQryClientChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///会员客户对照变动查询
BOOL CSysApiDataEntry::ReqQryPartClientChgTopic(CShfeFtdcReqQryPartClientChgField *pReqQryPartClientChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryPartClientChgTopic(pReqQryPartClientChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///限仓数据变动查询
BOOL CSysApiDataEntry::ReqQryPosiLimitChgTopic(CShfeFtdcReqQryPosiLimitChgField *pReqQryPosiLimitChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryPosiLimitChgTopic(pReqQryPosiLimitChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///保值额度变动查询
BOOL CSysApiDataEntry::ReqQryHedgeDetailChgTopic(CShfeFtdcReqQryHedgeDetailChgField *pReqQryHedgeDetailChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryHedgeDetailChgTopic(pReqQryHedgeDetailChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///会员变动查询
BOOL CSysApiDataEntry::ReqQryParticipantChgTopic(CShfeFtdcReqQryParticipantChgField *pReqQryParticipantChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryParticipantChgTopic(pReqQryParticipantChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///保证金率变动查询
BOOL CSysApiDataEntry::ReqQryMarginRateChgTopic(CShfeFtdcReqQryMarginRateChgField *pReqQryMarginRateChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryMarginRateChgTopic(pReqQryMarginRateChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///IP地址变动查询
BOOL CSysApiDataEntry::ReqQryUserIpChgTopic(CShfeFtdcReqQryUserIpChgField *pReqQryUserIpChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryUserIpChgTopic(pReqQryUserIpChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///限仓数据变动查询
BOOL CSysApiDataEntry::ReqQryClientPosiLimitChgTopic(CShfeFtdcReqQryClientPosiLimitChgField *pReqQryClientPosiLimitChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryClientPosiLimitChgTopic(pReqQryClientPosiLimitChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///限仓数据变动查询
BOOL CSysApiDataEntry::ReqQrySpecPosiLimitChgTopic(CShfeFtdcReqQrySpecPosiLimitChgField *pReqQrySpecPosiLimitChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySpecPosiLimitChgTopic(pReqQrySpecPosiLimitChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///历史对象状态指标查询
BOOL CSysApiDataEntry::ReqQryHistoryObjectAttrTopic(CShfeFtdcReqQryHistoryObjectAttrField *pReqQryHistoryObjectAttr, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryHistoryObjectAttrTopic(pReqQryHistoryObjectAttr, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///前置响应信息查询
BOOL CSysApiDataEntry::ReqQryFrontInfoTopic(CShfeFtdcReqQryFrontInfoField *pReqQryFrontInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryFrontInfoTopic(pReqQryFrontInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///用户登录
BOOL CSysApiDataEntry::ReqQrySysUserLoginTopic(CShfeFtdcReqQrySysUserLoginField *pReqQrySysUserLogin, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySysUserLoginTopic(pReqQrySysUserLogin, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///用户登出
BOOL CSysApiDataEntry::ReqQrySysUserLogoutTopic(CShfeFtdcReqQrySysUserLogoutField *pReqQrySysUserLogout, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySysUserLogoutTopic(pReqQrySysUserLogout, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///用户修改密码
BOOL CSysApiDataEntry::ReqQrySysUserPasswordUpdateTopic(CShfeFtdcReqQrySysUserPasswordUpdateField *pReqQrySysUserPasswordUpdate, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySysUserPasswordUpdateTopic(pReqQrySysUserPasswordUpdate, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///注册用户
BOOL CSysApiDataEntry::ReqQrySysUserRegisterTopic(CShfeFtdcReqQrySysUserRegisterField *pReqQrySysUserRegister, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySysUserRegisterTopic(pReqQrySysUserRegister, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///删除用户
BOOL CSysApiDataEntry::ReqQrySysUserDeleteTopic(CShfeFtdcReqQrySysUserDeleteField *pReqQrySysUserDelete, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySysUserDeleteTopic(pReqQrySysUserDelete, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///交易日志查询
BOOL CSysApiDataEntry::ReqQryTradeLogTopic(CShfeFtdcReqQryTradeLogField *pReqQryTradeLog, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTradeLogTopic(pReqQryTradeLog, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///告警事件修改
BOOL CSysApiDataEntry::ReqQryWarningEventUpdateTopic(CShfeFtdcReqQryWarningEventUpdateField *pReqQryWarningEventUpdate, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryWarningEventUpdateTopic(pReqQryWarningEventUpdate, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///交易系统登录信息查询
BOOL CSysApiDataEntry::ReqQryTradeUserLoginInfoTopic(CShfeFtdcReqQryTradeUserLoginInfoField *pReqQryTradeUserLoginInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTradeUserLoginInfoTopic(pReqQryTradeUserLoginInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///会员交易查询
BOOL CSysApiDataEntry::ReqQryPartTradeTopic(CShfeFtdcReqQryPartTradeField *pReqQryPartTrade, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryPartTradeTopic(pReqQryPartTrade, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///交易峰值查询
BOOL CSysApiDataEntry::ReqQryTradepeakTopic(CShfeFtdcReqQryTradepeakField *pReqQryTradepeak, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTradepeakTopic(pReqQryTradepeak, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///管理平台初始化信息查询
BOOL CSysApiDataEntry::ReqQryParticipantInitTopic(CShfeFtdcReqQryParticipantInitField *pReqQryParticipantInit, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryParticipantInitTopic(pReqQryParticipantInit, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///管理平台初始化信息查询
BOOL CSysApiDataEntry::ReqQryUserInitTopic(CShfeFtdcReqQryUserInitField *pReqQryUserInit, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryUserInitTopic(pReqQryUserInit, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///
BOOL CSysApiDataEntry::ReqQryHistoryCpuInfoTopic(CShfeFtdcReqQryHistoryCpuInfoField *pReqQryHistoryCpuInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryHistoryCpuInfoTopic(pReqQryHistoryCpuInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///
BOOL CSysApiDataEntry::ReqQryHistoryMemInfoTopic(CShfeFtdcReqQryHistoryMemInfoField *pReqQryHistoryMemInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryHistoryMemInfoTopic(pReqQryHistoryMemInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///
BOOL CSysApiDataEntry::ReqQryHistoryNetworkInfoTopic(CShfeFtdcReqQryHistoryNetworkInfoField *pReqQryHistoryNetworkInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryHistoryNetworkInfoTopic(pReqQryHistoryNetworkInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///监控系统在线用户查询
BOOL CSysApiDataEntry::ReqQryMonitorOnlineUser(CShfeFtdcReqQryMonitorOnlineUserField *pReqQryMonitorOnlineUser, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryMonitorOnlineUser(pReqQryMonitorOnlineUser, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///交易系统前置统计查询
BOOL CSysApiDataEntry::ReqQryFrontStat(CShfeFtdcReqQryFrontStatField *pReqQryFrontStat, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryFrontStat(pReqQryFrontStat, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///历史峰值查询
BOOL CSysApiDataEntry::ReqQryHistoryTradePeakTopic(CShfeFtdcReqQryHistoryTradePeakField *pReqQryHistoryTradePeak, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryHistoryTradePeakTopic(pReqQryHistoryTradePeak, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///日志事件查询
BOOL CSysApiDataEntry::ReqQrySyslogEventTopic(CShfeFtdcReqQrySyslogEventField *pReqQrySyslogEvent, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySyslogEventTopic(pReqQrySyslogEvent, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///tomcat信息查询
BOOL CSysApiDataEntry::ReqQryTomcatInfoTopic(CShfeFtdcReqQryTomcatInfoField *pReqQryTomcatInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTomcatInfoTopic(pReqQryTomcatInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///数据库查询
BOOL CSysApiDataEntry::ReqQryDBQueryTopic(CShfeFtdcReqQryDBQueryField *pReqQryDBQuery, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryDBQueryTopic(pReqQryDBQuery, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///文件传输请求
BOOL CSysApiDataEntry::ReqQryGetFileTopic(CShfeFtdcReqQryGetFileField *pReqQryGetFile, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryGetFileTopic(pReqQryGetFile, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///日志事件修改请求
BOOL CSysApiDataEntry::ReqQrySyslogEventUpdateTopic(CShfeFtdcReqQrySyslogEventUpdateField *pReqQrySyslogEventUpdate, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySyslogEventUpdateTopic(pReqQrySyslogEventUpdate, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///告警明细查询
BOOL CSysApiDataEntry::ReqQryWarningQueryTopic(CShfeFtdcReqQryWarningQueryField *pReqQryWarningQuery, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryWarningQueryTopic(pReqQryWarningQuery, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///网站访问查询
BOOL CSysApiDataEntry::ReqQryWebVisitTopic(CShfeFtdcReqQryWebVisitField *pReqQryWebVisit, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryWebVisitTopic(pReqQryWebVisit, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///告警激活变更
BOOL CSysApiDataEntry::ReqQryWarningActiveChange(CShfeFtdcReqQryWarningActiveChangeField *pReqQryWarningActiveChange, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryWarningActiveChange(pReqQryWarningActiveChange, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///通用操作
BOOL CSysApiDataEntry::ReqQryGeneralOperateTopic(CShfeFtdcReqQryGeneralOperateField *pReqQryGeneralOperate, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryGeneralOperateTopic(pReqQryGeneralOperate, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///网络设备连接关系请求
BOOL CSysApiDataEntry::ReqQryNetDeviceLinkedTopic(CShfeFtdcReqQryNetDeviceLinkedField *pReqQryNetDeviceLinked, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetDeviceLinkedTopic(pReqQryNetDeviceLinked, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///交易系统登录信息请求
BOOL CSysApiDataEntry::ReqQryTradeUserLoginStatTopic(CShfeFtdcReqQryTradeUserLoginStatField *pReqQryTradeUserLoginStat, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTradeUserLoginStatTopic(pReqQryTradeUserLoginStat, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///交易系统前置报单响应信息
BOOL CSysApiDataEntry::ReqQryTradeFrontOrderRttStatTopic(CShfeFtdcReqQryTradeFrontOrderRttStatField *pReqQryTradeFrontOrderRttStat, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTradeFrontOrderRttStatTopic(pReqQryTradeFrontOrderRttStat, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///会员席位交易状态
BOOL CSysApiDataEntry::ReqQryParticTradeOrderStatesTopic(CShfeFtdcReqQryParticTradeOrderStatesField *pReqQryParticTradeOrderStates, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryParticTradeOrderStatesTopic(pReqQryParticTradeOrderStates, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///系统路由信息
BOOL CSysApiDataEntry::ReqQryRouterInfoTopic(CShfeFtdcReqQryRouterInfoField *pReqQryRouterInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryRouterInfoTopic(pReqQryRouterInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///磁盘I/O信息
BOOL CSysApiDataEntry::ReqQryDiskIOTopic(CShfeFtdcReqQryDiskIOField *pReqQryDiskIO, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryDiskIOTopic(pReqQryDiskIO, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///系统状态信息
BOOL CSysApiDataEntry::ReqQryStatInfoTopic(CShfeFtdcReqQryStatInfoField *pReqQryStatInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryStatInfoTopic(pReqQryStatInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///交易系统前置报单分布区间
BOOL CSysApiDataEntry::ReqQryTradeOrderRttCutLineTopic(CShfeFtdcReqQryTradeOrderRttCutLineField *pReqQryTradeOrderRttCutLine, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTradeOrderRttCutLineTopic(pReqQryTradeOrderRttCutLine, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///会员客户信息
BOOL CSysApiDataEntry::ReqQryClientInfoTopic(CShfeFtdcReqQryClientInfoField *pReqQryClientInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryClientInfoTopic(pReqQryClientInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///请求事件描述
BOOL CSysApiDataEntry::ReqQryEventDescriptionTopic(CShfeFtdcReqQryEventDescriptionField *pReqQryEventDescription, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryEventDescriptionTopic(pReqQryEventDescription, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///订阅前置唯一ID信息
BOOL CSysApiDataEntry::ReqQryFrontUniqueIDTopic(CShfeFtdcReqQryFrontUniqueIDField *pReqQryFrontUniqueID, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryFrontUniqueIDTopic(pReqQryFrontUniqueID, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///会员线路地址变更请求
BOOL CSysApiDataEntry::ReqQryNetPartyLinkAddrChangeTopic(CShfeFtdcReqQryNetPartyLinkAddrChangeField *pReqQryNetPartyLinkAddrChange, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetPartyLinkAddrChangeTopic(pReqQryNetPartyLinkAddrChange, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///请求已删除会员列表信息
BOOL CSysApiDataEntry::ReqQryNetDelPartyLinkInfoTopic(CShfeFtdcReqQryNetDelPartyLinkInfoField *pReqQryNetDelPartyLinkInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetDelPartyLinkInfoTopic(pReqQryNetDelPartyLinkInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///请求网络性能排序
BOOL CSysApiDataEntry::ReqQryPerformanceTopTopic(CShfeFtdcReqQryPerformanceTopField *pReqQryPerformanceTop, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryPerformanceTopTopic(pReqQryPerformanceTop, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///请求约状态切换数据
BOOL CSysApiDataEntry::ReqQryInstrumentStatusTopic(CShfeFtdcReqQryInstrumentStatusField *pReqQryInstrumentStatus, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryInstrumentStatusTopic(pReqQryInstrumentStatus, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///请求合约交易节信息
BOOL CSysApiDataEntry::ReqQryCurrTradingSegmentAttrTopic(CShfeFtdcReqQryCurrTradingSegmentAttrField *pReqQryCurrTradingSegmentAttr, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryCurrTradingSegmentAttrTopic(pReqQryCurrTradingSegmentAttr, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///最新网络指标查询
BOOL CSysApiDataEntry::ReqQryRealTimeNetObjectAttrTopic(CShfeFtdcReqQryRealTimeNetObjectAttrField *pReqQryRealTimeNetObjectAttr, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryRealTimeNetObjectAttrTopic(pReqQryRealTimeNetObjectAttr, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///网络大区划分查询
BOOL CSysApiDataEntry::ReqQryNetAreaTopic(CShfeFtdcReqQryNetAreaField *pReqQryNetArea, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetAreaTopic(pReqQryNetArea, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///网络子区查询
BOOL CSysApiDataEntry::ReqQryNetSubAreaTopic(CShfeFtdcReqQryNetSubAreaField *pReqQryNetSubArea, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetSubAreaTopic(pReqQryNetSubArea, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///网络子区IP查询
BOOL CSysApiDataEntry::ReqQryNetSubAreaIPTopic(CShfeFtdcReqQryNetSubAreaIPField *pReqQryNetSubAreaIP, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetSubAreaIPTopic(pReqQryNetSubAreaIP, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///网络设备探测请求
BOOL CSysApiDataEntry::ReqQryNetDeviceDetectTopic(CShfeFtdcReqQryNetDeviceDetectField *pReqQryNetDeviceDetect, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetDeviceDetectTopic(pReqQryNetDeviceDetect, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///网络设备查询请求
BOOL CSysApiDataEntry::ReqQryNetDeviceRequestTopic(CShfeFtdcReqQryNetDeviceRequestField *pReqQryNetDeviceRequest, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetDeviceRequestTopic(pReqQryNetDeviceRequest, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///大楼查询
BOOL CSysApiDataEntry::ReqQryNetBuildingTopic(CShfeFtdcReqQryNetBuildingField *pReqQryNetBuilding, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetBuildingTopic(pReqQryNetBuilding, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///机房查询
BOOL CSysApiDataEntry::ReqQryNetRoomTopic(CShfeFtdcReqQryNetRoomField *pReqQryNetRoom, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetRoomTopic(pReqQryNetRoom, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///机柜查询
BOOL CSysApiDataEntry::ReqQryNetCabinetsTopic(CShfeFtdcReqQryNetCabinetsField *pReqQryNetCabinets, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetCabinetsTopic(pReqQryNetCabinets, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///OID
BOOL CSysApiDataEntry::ReqQryNetOIDTopic(CShfeFtdcReqQryNetOIDField *pReqQryNetOID, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetOIDTopic(pReqQryNetOID, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///时间策略
BOOL CSysApiDataEntry::ReqQryNetTimePolicyTopic(CShfeFtdcReqQryNetTimePolicyField *pReqQryNetTimePolicy, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetTimePolicyTopic(pReqQryNetTimePolicy, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///采集任务查询
BOOL CSysApiDataEntry::ReqQryNetGatherTaskTopic(CShfeFtdcReqQryNetGatherTaskField *pReqQryNetGatherTask, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetGatherTaskTopic(pReqQryNetGatherTask, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///设备变更请求
BOOL CSysApiDataEntry::ReqQryNetDeviceChgTopic(CShfeFtdcReqQryNetDeviceChgField *pReqQryNetDeviceChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetDeviceChgTopic(pReqQryNetDeviceChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///常用设备型号请求
BOOL CSysApiDataEntry::ReqQryNetDeviceTypeTopic(CShfeFtdcReqQryNetDeviceTypeField *pReqQryNetDeviceType, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetDeviceTypeTopic(pReqQryNetDeviceType, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///常用设备类别请求
BOOL CSysApiDataEntry::ReqQryNetDeviceCategoryTopic(CShfeFtdcReqQryNetDeviceCategoryField *pReqQryNetDeviceCategory, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetDeviceCategoryTopic(pReqQryNetDeviceCategory, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///设备厂商请求
BOOL CSysApiDataEntry::ReqQryNetManufactoryTopic(CShfeFtdcReqQryNetManufactoryField *pReqQryNetManufactory, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetManufactoryTopic(pReqQryNetManufactory, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///设备共同体请求
BOOL CSysApiDataEntry::ReqQryNetCommunityTopic(CShfeFtdcReqQryNetCommunityField *pReqQryNetCommunity, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetCommunityTopic(pReqQryNetCommunity, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///端口类型请求
BOOL CSysApiDataEntry::ReqQryNetPortTypeTopic(CShfeFtdcReqQryNetPortTypeField *pReqQryNetPortType, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetPortTypeTopic(pReqQryNetPortType, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///会员接入地点请求
BOOL CSysApiDataEntry::ReqQryNetPartAccessSpotTopic(CShfeFtdcReqQryNetPartAccessSpotField *pReqQryNetPartAccessSpot, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetPartAccessSpotTopic(pReqQryNetPartAccessSpot, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///端口请求
BOOL CSysApiDataEntry::ReqQryNetInterfaceTopic(CShfeFtdcReqQryNetInterfaceField *pReqQryNetInterface, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetInterfaceTopic(pReqQryNetInterface, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///GeneralOID请求
BOOL CSysApiDataEntry::ReqQryNetGeneralOIDTopic(CShfeFtdcReqQryNetGeneralOIDField *pReqQryNetGeneralOID, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetGeneralOIDTopic(pReqQryNetGeneralOID, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///监控对象类别
BOOL CSysApiDataEntry::ReqQryNetMonitorTypeTopic(CShfeFtdcReqQryNetMonitorTypeField *pReqQryNetMonitorType, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorTypeTopic(pReqQryNetMonitorType, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///指标统表
BOOL CSysApiDataEntry::ReqQryNetMonitorAttrScopeTopic(CShfeFtdcReqQryNetMonitorAttrScopeField *pReqQryNetMonitorAttrScope, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorAttrScopeTopic(pReqQryNetMonitorAttrScope, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///监控指标表
BOOL CSysApiDataEntry::ReqQryNetMonitorAttrTypeTopic(CShfeFtdcReqQryNetMonitorAttrTypeField *pReqQryNetMonitorAttrType, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorAttrTypeTopic(pReqQryNetMonitorAttrType, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///监控对象指标表
BOOL CSysApiDataEntry::ReqQryNetMonitorObjectAttrTopic(CShfeFtdcReqQryNetMonitorObjectAttrField *pReqQryNetMonitorObjectAttr, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorObjectAttrTopic(pReqQryNetMonitorObjectAttr, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///设备对象组表
BOOL CSysApiDataEntry::ReqQryNetMonitorDeviceGroupTopic(CShfeFtdcReqQryNetMonitorDeviceGroupField *pReqQryNetMonitorDeviceGroup, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorDeviceGroupTopic(pReqQryNetMonitorDeviceGroup, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///任务信息表
BOOL CSysApiDataEntry::ReqQryNetMonitorTaskInfoTopic(CShfeFtdcReqQryNetMonitorTaskInfoField *pReqQryNetMonitorTaskInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorTaskInfoTopic(pReqQryNetMonitorTaskInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///任务结果表
BOOL CSysApiDataEntry::ReqQryNetMonitorTaskResultTopic(CShfeFtdcReqQryNetMonitorTaskResultField *pReqQryNetMonitorTaskResult, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorTaskResultTopic(pReqQryNetMonitorTaskResult, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///任务对象集
BOOL CSysApiDataEntry::ReqQryNetMonitorTaskObjectSetTopic(CShfeFtdcReqQryNetMonitorTaskObjectSetField *pReqQryNetMonitorTaskObjectSet, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorTaskObjectSetTopic(pReqQryNetMonitorTaskObjectSet, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///会员链路信息表
BOOL CSysApiDataEntry::ReqQryNetPartyLinkInfoTopic(CShfeFtdcReqQryNetPartyLinkInfoField *pReqQryNetPartyLinkInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetPartyLinkInfoTopic(pReqQryNetPartyLinkInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///监控动作指标对照表
BOOL CSysApiDataEntry::ReqQryNetMonitorActionAttrTopic(CShfeFtdcReqQryNetMonitorActionAttrField *pReqQryNetMonitorActionAttr, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorActionAttrTopic(pReqQryNetMonitorActionAttr, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///模块
BOOL CSysApiDataEntry::ReqQryNetModuleTopic(CShfeFtdcReqQryNetModuleField *pReqQryNetModule, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetModuleTopic(pReqQryNetModule, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///任务结果状态表
BOOL CSysApiDataEntry::ReqQryNetMonitorTaskStatusResultTopic(CShfeFtdcReqQryNetMonitorTaskStatusResultField *pReqQryNetMonitorTaskStatusResult, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorTaskStatusResultTopic(pReqQryNetMonitorTaskStatusResult, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///设备配置表
BOOL CSysApiDataEntry::ReqQryNetCfgFileTopic(CShfeFtdcReqQryNetCfgFileField *pReqQryNetCfgFile, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetCfgFileTopic(pReqQryNetCfgFile, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///任务结果规则分析表
BOOL CSysApiDataEntry::ReqQryNetMonitorDeviceTaskTopic(CShfeFtdcReqQryNetMonitorDeviceTaskField *pReqQryNetMonitorDeviceTask, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorDeviceTaskTopic(pReqQryNetMonitorDeviceTask, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///文件通用操作
BOOL CSysApiDataEntry::ReqQryFileGeneralOperTopic(CShfeFtdcReqQryFileGeneralOperField *pReqQryFileGeneralOper, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryFileGeneralOperTopic(pReqQryFileGeneralOper, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///基线表
BOOL CSysApiDataEntry::ReqQryNetBaseLineTopic(CShfeFtdcReqQryNetBaseLineField *pReqQryNetBaseLine, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetBaseLineTopic(pReqQryNetBaseLine, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///基线结果表
BOOL CSysApiDataEntry::ReqQryNetBaseLineResultTopic(CShfeFtdcReqQryNetBaseLineResultField *pReqQryNetBaseLineResult, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetBaseLineResultTopic(pReqQryNetBaseLineResult, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///会员链路状态信息表
BOOL CSysApiDataEntry::ReqQryNetPartyLinkStatusInfoTopic(CShfeFtdcReqQryNetPartyLinkStatusInfoField *pReqQryNetPartyLinkStatusInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetPartyLinkStatusInfoTopic(pReqQryNetPartyLinkStatusInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///本地ping结果
BOOL CSysApiDataEntry::ReqQryNetLocalPingResultInfoTopic(CShfeFtdcReqQryNetLocalPingResultInfoField *pReqQryNetLocalPingResultInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetLocalPingResultInfoTopic(pReqQryNetLocalPingResultInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///远程ping结果
BOOL CSysApiDataEntry::ReqQryNetRomotePingResultInfoTopic(CShfeFtdcReqQryNetRomotePingResultInfoField *pReqQryNetRomotePingResultInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetRomotePingResultInfoTopic(pReqQryNetRomotePingResultInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///请求非会员链路表信息
BOOL CSysApiDataEntry::ReqQryNetNonPartyLinkInfoTopic(CShfeFtdcReqQryNetNonPartyLinkInfoField *pReqQryNetNonPartyLinkInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetNonPartyLinkInfoTopic(pReqQryNetNonPartyLinkInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}


BOOL CSysApiDataEntry::ReqQrySyslogEventSubcriberTopic(CShfeFtdcReqQrySyslogEventSubcriberField *pReqQrySyslogEventSubcriber, int nRequestID)
{
	if(pReqQrySyslogEventSubcriber->KeepAlive)
	{
		if(pReqQrySyslogEventSubcriber->ObjectNum ==-1)
		{
			lstrcpyA(pReqQrySyslogEventSubcriber->MonTime, CT2A(theApp.GetDataDispatcher().GetEventSubcriberTime()));
			strcpy(pReqQrySyslogEventSubcriber->MonDate, theApp.GetDataDispatcher().GetTradingDay().data());
		}
	}
	list<EventSubInfo>::iterator it =g_EventSubList.begin();
	for(; it !=g_EventSubList.end() ;it++)
	{
		if(!strcmp(pReqQrySyslogEventSubcriber->ObjectID ,(*it).ObjectID) &&!strcmp(pReqQrySyslogEventSubcriber->EventName ,(*it).EventName) &&!strcmp(pReqQrySyslogEventSubcriber->ProcessFlag,(*it).ProcessFlag) &&!strcmp(pReqQrySyslogEventSubcriber->WarningLevel ,(*it).WarningLevel) &&!strcmp(pReqQrySyslogEventSubcriber->filter,(*it).filter) &&!strcmp(pReqQrySyslogEventSubcriber->antifilter,(*it).antifilter))
			break;
	}
	if(it ==g_EventSubList.end())
	{
		if(pReqQrySyslogEventSubcriber->KeepAlive)
		{
			EventSubInfo info;
			strcpy(info.EventName ,pReqQrySyslogEventSubcriber->EventName);
			strcpy(info.ObjectID ,pReqQrySyslogEventSubcriber->ObjectID);
			strcpy(info.ProcessFlag,pReqQrySyslogEventSubcriber->ProcessFlag);
			strcpy(info.WarningLevel ,pReqQrySyslogEventSubcriber->WarningLevel);
			strcpy(info.filter,pReqQrySyslogEventSubcriber->filter);
			strcpy(info.antifilter,pReqQrySyslogEventSubcriber->antifilter);
			list<void *> theList;
			theList.push_back((void *)this);
			info.Receiver =theList;
			g_EventSubList.push_back(info);
			CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
			return (dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySyslogEventSubcriberTopic(pReqQrySyslogEventSubcriber ,0));
		}
	}
	else
	{
		if(pReqQrySyslogEventSubcriber->KeepAlive)
		{
			(*it).Receiver.push_back((void *)this);
			CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
			return (dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySyslogEventSubcriberTopic(pReqQrySyslogEventSubcriber ,0));
		}
		else
		{
			list<void *>::iterator itList =(*it).Receiver.begin();
			while(itList !=(*it).Receiver.end())
			{
				list<void *>::iterator itListTmp =itList;
				itListTmp++;
				if((*itList) ==this)
				{
					(*it).Receiver.erase(itList);
					if((*it).Receiver.size() ==0)
					{
						g_EventSubList.erase(it);
						CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
						return (dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySyslogEventSubcriberTopic(pReqQrySyslogEventSubcriber ,0));
					}
				}
				itList =itListTmp;
			}
		}
	}
	return TRUE;
}

///订阅CPU应答
BOOL CSysApiDataEntry::SubRtnTopCpuInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnTopCpuInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅CPU应答
BOOL CSysApiDataEntry::UnsubRtnTopCpuInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnTopCpuInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅Mem应答
BOOL CSysApiDataEntry::SubRtnTopMemInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnTopMemInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅Mem应答
BOOL CSysApiDataEntry::UnsubRtnTopMemInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnTopMemInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅process应答
BOOL CSysApiDataEntry::SubRtnTopProcessInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnTopProcessInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅process应答
BOOL CSysApiDataEntry::UnsubRtnTopProcessInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnTopProcessInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅filesystem应答
BOOL CSysApiDataEntry::SubRtnFileSystemInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnFileSystemInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅filesystem应答
BOOL CSysApiDataEntry::UnsubRtnFileSystemInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnFileSystemInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅network应答
BOOL CSysApiDataEntry::SubRtnNetworkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnNetworkInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅network应答
BOOL CSysApiDataEntry::UnsubRtnNetworkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnNetworkInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅主机环境信息应答
BOOL CSysApiDataEntry::SubRtnHostEnvTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnHostEnvTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅主机环境信息应答
BOOL CSysApiDataEntry::UnsubRtnHostEnvTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnHostEnvTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅获得监控对象信息应答
BOOL CSysApiDataEntry::SubRtnMonitorObjectTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnMonitorObjectTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅获得监控对象信息应答
BOOL CSysApiDataEntry::UnsubRtnMonitorObjectTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnMonitorObjectTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅获得业务进程和主机的对应关系应答
BOOL CSysApiDataEntry::SubRtnObjectRationalTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnObjectRationalTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅获得业务进程和主机的对应关系应答
BOOL CSysApiDataEntry::UnsubRtnObjectRationalTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnObjectRationalTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅日志文件内容应答
BOOL CSysApiDataEntry::SubRtnSyslogInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnSyslogInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅日志文件内容应答
BOOL CSysApiDataEntry::UnsubRtnSyslogInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnSyslogInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅对象关系查询应答
BOOL CSysApiDataEntry::SubRtnOidRelationTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnOidRelationTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅对象关系查询应答
BOOL CSysApiDataEntry::UnsubRtnOidRelationTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnOidRelationTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅用户信息查询请求应答
BOOL CSysApiDataEntry::SubRtnUserInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnUserInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅用户信息查询请求应答
BOOL CSysApiDataEntry::UnsubRtnUserInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnUserInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅在线用户信息查询请求应答
BOOL CSysApiDataEntry::SubRtnOnlineUserInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnOnlineUserInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅在线用户信息查询请求应答
BOOL CSysApiDataEntry::UnsubRtnOnlineUserInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnOnlineUserInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅告警事件查询请求应答
BOOL CSysApiDataEntry::SubRtnWarningEventTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnWarningEventTopicRegister();
	lstRegister.push_back((void*)this);
	return TRUE;
}

///取消订阅告警事件查询请求应答
BOOL CSysApiDataEntry::UnsubRtnWarningEventTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnWarningEventTopicRegister();
	lstRegister.remove((void*)this);
	return TRUE;
}

///订阅对象状态指标查询应答
BOOL CSysApiDataEntry::SubRtnObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnObjectAttrTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅对象状态指标查询应答
BOOL CSysApiDataEntry::UnsubRtnObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnObjectAttrTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅无效报单查询应答
BOOL CSysApiDataEntry::SubRtnInvalidateOrderTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnInvalidateOrderTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅无效报单查询应答
BOOL CSysApiDataEntry::UnsubRtnInvalidateOrderTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnInvalidateOrderTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅报单状态查询应答
BOOL CSysApiDataEntry::SubRtnOrderStatusTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnOrderStatusTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅报单状态查询应答
BOOL CSysApiDataEntry::UnsubRtnOrderStatusTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnOrderStatusTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅报单成交查询应答
BOOL CSysApiDataEntry::SubRtnBargainOrderTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnBargainOrderTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅报单成交查询应答
BOOL CSysApiDataEntry::UnsubRtnBargainOrderTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnBargainOrderTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅合约基本属性查询应答
BOOL CSysApiDataEntry::SubRtnInstPropertyTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnInstPropertyTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅合约基本属性查询应答
BOOL CSysApiDataEntry::UnsubRtnInstPropertyTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnInstPropertyTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅合约保证金率查询应答
BOOL CSysApiDataEntry::SubRtnMarginRateTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnMarginRateTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅合约保证金率查询应答
BOOL CSysApiDataEntry::UnsubRtnMarginRateTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnMarginRateTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅合约涨跌停板查询应答
BOOL CSysApiDataEntry::SubRtnPriceLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnPriceLimitTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅合约涨跌停板查询应答
BOOL CSysApiDataEntry::UnsubRtnPriceLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnPriceLimitTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅会员限仓查询应答
BOOL CSysApiDataEntry::SubRtnPartPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnPartPosiLimitTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅会员限仓查询应答
BOOL CSysApiDataEntry::UnsubRtnPartPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnPartPosiLimitTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅客户限仓查询应答
BOOL CSysApiDataEntry::SubRtnClientPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnClientPosiLimitTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅客户限仓查询应答
BOOL CSysApiDataEntry::UnsubRtnClientPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnClientPosiLimitTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅特殊客户限仓查询应答
BOOL CSysApiDataEntry::SubRtnSpecialPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnSpecialPosiLimitTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅特殊客户限仓查询应答
BOOL CSysApiDataEntry::UnsubRtnSpecialPosiLimitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnSpecialPosiLimitTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅账户出入金查询应答
BOOL CSysApiDataEntry::SubRtnTransactionChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnTransactionChgTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅账户出入金查询应答
BOOL CSysApiDataEntry::UnsubRtnTransactionChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnTransactionChgTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅客户数据变动查询应答
BOOL CSysApiDataEntry::SubRtnClientChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnClientChgTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅客户数据变动查询应答
BOOL CSysApiDataEntry::UnsubRtnClientChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnClientChgTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅会员客户对照变动查询应答
BOOL CSysApiDataEntry::SubRtnPartClientChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnPartClientChgTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅会员客户对照变动查询应答
BOOL CSysApiDataEntry::UnsubRtnPartClientChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnPartClientChgTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅限仓数据变动查询应答
BOOL CSysApiDataEntry::SubRtnPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnPosiLimitChgTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅限仓数据变动查询应答
BOOL CSysApiDataEntry::UnsubRtnPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnPosiLimitChgTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅保值额度变动查询应答
BOOL CSysApiDataEntry::SubRtnHedgeDetailChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnHedgeDetailChgTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅保值额度变动查询应答
BOOL CSysApiDataEntry::UnsubRtnHedgeDetailChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnHedgeDetailChgTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅会员变动查询应答
BOOL CSysApiDataEntry::SubRtnParticipantChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnParticipantChgTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅会员变动查询应答
BOOL CSysApiDataEntry::UnsubRtnParticipantChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnParticipantChgTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅保证金率变动查询应答
BOOL CSysApiDataEntry::SubRtnMarginRateChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnMarginRateChgTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅保证金率变动查询应答
BOOL CSysApiDataEntry::UnsubRtnMarginRateChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnMarginRateChgTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅IP地址变动查询应答
BOOL CSysApiDataEntry::SubRtnUserIpChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnUserIpChgTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅IP地址变动查询应答
BOOL CSysApiDataEntry::UnsubRtnUserIpChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnUserIpChgTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅限仓数据变动查询应答
BOOL CSysApiDataEntry::SubRtnClientPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnClientPosiLimitChgTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅限仓数据变动查询应答
BOOL CSysApiDataEntry::UnsubRtnClientPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnClientPosiLimitChgTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅限仓数据变动查询应答
BOOL CSysApiDataEntry::SubRtnSpecPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnSpecPosiLimitChgTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅限仓数据变动查询应答
BOOL CSysApiDataEntry::UnsubRtnSpecPosiLimitChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnSpecPosiLimitChgTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅历史对象状态指标查询应答
BOOL CSysApiDataEntry::SubRtnHistoryObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnHistoryObjectAttrTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅历史对象状态指标查询应答
BOOL CSysApiDataEntry::UnsubRtnHistoryObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnHistoryObjectAttrTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅前置响应信息查询应答
BOOL CSysApiDataEntry::SubRtnFrontInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnFrontInfoTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅前置响应信息查询应答
BOOL CSysApiDataEntry::UnsubRtnFrontInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnFrontInfoTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅会员初始化应答
BOOL CSysApiDataEntry::SubRtnParticipantInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnParticipantInitTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅会员初始化应答
BOOL CSysApiDataEntry::UnsubRtnParticipantInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnParticipantInitTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅座席初始化应答
BOOL CSysApiDataEntry::SubRtnUserInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnUserInitTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅座席初始化应答
BOOL CSysApiDataEntry::UnsubRtnUserInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnUserInitTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅客户初始化应答
BOOL CSysApiDataEntry::SubRtnClientInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnClientInitTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅客户初始化应答
BOOL CSysApiDataEntry::UnsubRtnClientInitTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnClientInitTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅交易日志查询应答
BOOL CSysApiDataEntry::SubRtnTradeLogTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnTradeLogTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅交易日志查询应答
BOOL CSysApiDataEntry::UnsubRtnTradeLogTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnTradeLogTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅交易系统登录信息
BOOL CSysApiDataEntry::SubRtnTradeUserLoginInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnTradeUserLoginInfoTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅交易系统登录信息
BOOL CSysApiDataEntry::UnsubRtnTradeUserLoginInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnTradeUserLoginInfoTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅
BOOL CSysApiDataEntry::SubRtnUpdateSysConfigTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnUpdateSysConfigTopicRegister();
	lstRegister.push_back((void*)this);
	return TRUE;
}

///取消订阅
BOOL CSysApiDataEntry::UnsubRtnUpdateSysConfigTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnUpdateSysConfigTopicRegister();
	lstRegister.remove((void*)this);
	return TRUE;
}

///订阅
BOOL CSysApiDataEntry::SubRtnSysUser(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnSysUserRegister();
	lstRegister.push_back((void*)this);
	return TRUE;
}

///取消订阅
BOOL CSysApiDataEntry::UnsubRtnSysUser(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnSysUserRegister();
	lstRegister.remove((void*)this);
	return TRUE;
}

///订阅监控系统时钟同步
BOOL CSysApiDataEntry::SubRtnSysTimeSyncTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnSysTimeSyncTopicRegister();
	lstRegister.push_back((void*)this);
	return TRUE;
}

///取消订阅监控系统时钟同步
BOOL CSysApiDataEntry::UnsubRtnSysTimeSyncTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnSysTimeSyncTopicRegister();
	lstRegister.remove((void*)this);
	return TRUE;
}

///订阅数据中心切换通知
BOOL CSysApiDataEntry::SubRtnDataCenterChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnDataCenterChgTopicRegister();
	lstRegister.push_back((void*)this);
	return TRUE;
}

///取消订阅数据中心切换通知
BOOL CSysApiDataEntry::UnsubRtnDataCenterChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnDataCenterChgTopicRegister();
	lstRegister.remove((void*)this);
	return TRUE;
}

///订阅日志事件应答
BOOL CSysApiDataEntry::SubRtnSyslogEventTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnSyslogEventTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅日志事件应答
BOOL CSysApiDataEntry::UnsubRtnSyslogEventTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnSyslogEventTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅Web应用信息
BOOL CSysApiDataEntry::SubRtnWebAppInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnWebAppInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅Web应用信息
BOOL CSysApiDataEntry::UnsubRtnWebAppInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnWebAppInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅应用servlet信息
BOOL CSysApiDataEntry::SubRtnServletInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnServletInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅应用servlet信息
BOOL CSysApiDataEntry::UnsubRtnServletInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnServletInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅文件信息
BOOL CSysApiDataEntry::SubRtnFileInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnFileInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅文件信息
BOOL CSysApiDataEntry::UnsubRtnFileInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnFileInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅应用会话信息
BOOL CSysApiDataEntry::SubRtnSessionInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnSessionInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅应用会话信息
BOOL CSysApiDataEntry::UnsubRtnSessionInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnSessionInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅JDBC信息
BOOL CSysApiDataEntry::SubRtnJDBCInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnJDBCInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅JDBC信息
BOOL CSysApiDataEntry::UnsubRtnJDBCInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnJDBCInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅线程信息
BOOL CSysApiDataEntry::SubRtnThreadInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnThreadInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅线程信息
BOOL CSysApiDataEntry::UnsubRtnThreadInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnThreadInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅虚拟机信息
BOOL CSysApiDataEntry::SubRtnVMInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnVMInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅虚拟机信息
BOOL CSysApiDataEntry::UnsubRtnVMInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnVMInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅系统属性信息
BOOL CSysApiDataEntry::SubRtnPropertyInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnPropertyInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅系统属性信息
BOOL CSysApiDataEntry::UnsubRtnPropertyInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnPropertyInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅系统内存池信息
BOOL CSysApiDataEntry::SubRtnMemPoolInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnMemPoolInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅系统内存池信息
BOOL CSysApiDataEntry::UnsubRtnMemPoolInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnMemPoolInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅文件内容信息
BOOL CSysApiDataEntry::SubRtnFileContentInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnFileContentInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅文件内容信息
BOOL CSysApiDataEntry::UnsubRtnFileContentInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnFileContentInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅连接信息
BOOL CSysApiDataEntry::SubRtnConnectionInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnConnectionInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅连接信息
BOOL CSysApiDataEntry::UnsubRtnConnectionInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnConnectionInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅连接器信息
BOOL CSysApiDataEntry::SubRtnConnectorInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnConnectorInfoTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅连接器信息
BOOL CSysApiDataEntry::UnsubRtnConnectorInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnConnectorInfoTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅数据库查询应答
BOOL CSysApiDataEntry::SubRtnDBQueryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID,subObjectID,  nObjectNum,startDate ,startTime ,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnDBQueryTopicRegister();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅数据库查询应答
BOOL CSysApiDataEntry::UnsubRtnDBQueryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		string str =ObjectID;
		if(subObjectID)
		{
			if(strcmp(subObjectID ,"") !=0)
			{
				str +=".";
				str +=subObjectID;
			}
		}
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().GetRtnDBQueryTopicRegister();
		hash_map<string, list<void*>>::iterator map_iter = mapRetgister.find(str);
		if (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
		}
		return TRUE;
	}
	else return FALSE;
}

///订阅通用返回应答
BOOL CSysApiDataEntry::SubRtnGeneralFieldTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnGeneralFieldTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅通用返回应答
BOOL CSysApiDataEntry::UnsubRtnGeneralFieldTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnGeneralFieldTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅告警激活变更
BOOL CSysApiDataEntry::SubRtnWarningActiveChange(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnWarningActiveChangeRegister();
	lstRegister.push_back((void*)this);
	return TRUE;
}

///取消订阅告警激活变更
BOOL CSysApiDataEntry::UnsubRtnWarningActiveChange(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnWarningActiveChangeRegister();
	lstRegister.remove((void*)this);
	return TRUE;
}

///订阅通用操作
BOOL CSysApiDataEntry::SubRtnGeneralOperateTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnGeneralOperateTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅通用操作
BOOL CSysApiDataEntry::UnsubRtnGeneralOperateTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnGeneralOperateTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅网络设备连接关系
BOOL CSysApiDataEntry::SubRtnNetDeviceLinkedTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetDeviceLinkedTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅网络设备连接关系
BOOL CSysApiDataEntry::UnsubRtnNetDeviceLinkedTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetDeviceLinkedTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅交易系统前置报单响应信息
BOOL CSysApiDataEntry::SubRtnTradeFrontOrderRttStatTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnTradeFrontOrderRttStatTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅交易系统前置报单响应信息
BOOL CSysApiDataEntry::UnsubRtnTradeFrontOrderRttStatTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnTradeFrontOrderRttStatTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅会员席位交易状态
BOOL CSysApiDataEntry::SubRtnParticTradeOrderStatesTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnParticTradeOrderStatesTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅会员席位交易状态
BOOL CSysApiDataEntry::UnsubRtnParticTradeOrderStatesTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnParticTradeOrderStatesTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅系统路由信息
BOOL CSysApiDataEntry::SubRtnRouterInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnRouterInfoTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅系统路由信息
BOOL CSysApiDataEntry::UnsubRtnRouterInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnRouterInfoTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅磁盘I/O信息
BOOL CSysApiDataEntry::SubRtnDiskIOTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnDiskIOTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅磁盘I/O信息
BOOL CSysApiDataEntry::UnsubRtnDiskIOTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnDiskIOTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅系统状态信息
BOOL CSysApiDataEntry::SubRtnStatInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnStatInfoTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅系统状态信息
BOOL CSysApiDataEntry::UnsubRtnStatInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnStatInfoTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅交易系统前置报单分布区间
BOOL CSysApiDataEntry::SubRtnTradeOrderRttCutLineTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnTradeOrderRttCutLineTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅交易系统前置报单分布区间
BOOL CSysApiDataEntry::UnsubRtnTradeOrderRttCutLineTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnTradeOrderRttCutLineTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅会员客户信息
BOOL CSysApiDataEntry::SubRtnClientInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnClientInfoTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅会员客户信息
BOOL CSysApiDataEntry::UnsubRtnClientInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnClientInfoTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅订阅事件描述
BOOL CSysApiDataEntry::SubRtnEventDescriptionTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnEventDescriptionTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅订阅事件描述
BOOL CSysApiDataEntry::UnsubRtnEventDescriptionTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnEventDescriptionTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅订阅前置唯一ID信息
BOOL CSysApiDataEntry::SubRtnFrontUniqueIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnFrontUniqueIDTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅订阅前置唯一ID信息
BOOL CSysApiDataEntry::UnsubRtnFrontUniqueIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnFrontUniqueIDTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅订阅会员线路地址变更信息
BOOL CSysApiDataEntry::SubRtnNetPartyLinkAddrChangeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetPartyLinkAddrChangeTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅订阅会员线路地址变更信息
BOOL CSysApiDataEntry::UnsubRtnNetPartyLinkAddrChangeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetPartyLinkAddrChangeTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅订阅已删除会员列表信息
BOOL CSysApiDataEntry::SubRtnNetDelPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetDelPartyLinkInfoTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅订阅已删除会员列表信息
BOOL CSysApiDataEntry::UnsubRtnNetDelPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetDelPartyLinkInfoTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅订阅网络性能排序
BOOL CSysApiDataEntry::SubRtnPerformanceTopTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnPerformanceTopTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅订阅网络性能排序
BOOL CSysApiDataEntry::UnsubRtnPerformanceTopTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnPerformanceTopTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅订阅约状态切换数据
BOOL CSysApiDataEntry::SubRtnInstrumentStatusTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnInstrumentStatusTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅订阅约状态切换数据
BOOL CSysApiDataEntry::UnsubRtnInstrumentStatusTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnInstrumentStatusTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅订阅合约交易节信息
BOOL CSysApiDataEntry::SubRtnCurrTradingSegmentAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnCurrTradingSegmentAttrTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅订阅合约交易节信息
BOOL CSysApiDataEntry::UnsubRtnCurrTradingSegmentAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnCurrTradingSegmentAttrTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅网络大区划分应答
BOOL CSysApiDataEntry::SubRtnNetAreaTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetAreaTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅网络大区划分应答
BOOL CSysApiDataEntry::UnsubRtnNetAreaTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetAreaTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅网络子区应答
BOOL CSysApiDataEntry::SubRtnNetSubAreaTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetSubAreaTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅网络子区应答
BOOL CSysApiDataEntry::UnsubRtnNetSubAreaTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetSubAreaTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅网络子区IP应答
BOOL CSysApiDataEntry::SubRtnNetSubAreaIPTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetSubAreaIPTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅网络子区IP应答
BOOL CSysApiDataEntry::UnsubRtnNetSubAreaIPTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetSubAreaIPTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅网络设备
BOOL CSysApiDataEntry::SubRtnNetDeviceTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetDeviceTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅网络设备
BOOL CSysApiDataEntry::UnsubRtnNetDeviceTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetDeviceTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅大楼
BOOL CSysApiDataEntry::SubRtnNetBuildingTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetBuildingTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅大楼
BOOL CSysApiDataEntry::UnsubRtnNetBuildingTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetBuildingTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅机房
BOOL CSysApiDataEntry::SubRtnNetRoomTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetRoomTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅机房
BOOL CSysApiDataEntry::UnsubRtnNetRoomTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetRoomTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅机柜
BOOL CSysApiDataEntry::SubRtnNetCabinetsTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetCabinetsTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅机柜
BOOL CSysApiDataEntry::UnsubRtnNetCabinetsTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetCabinetsTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅OID
BOOL CSysApiDataEntry::SubRtnNetOIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetOIDTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅OID
BOOL CSysApiDataEntry::UnsubRtnNetOIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetOIDTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅时间策略
BOOL CSysApiDataEntry::SubRtnNetTimePolicyTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetTimePolicyTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅时间策略
BOOL CSysApiDataEntry::UnsubRtnNetTimePolicyTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetTimePolicyTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅采集任务
BOOL CSysApiDataEntry::SubRtnNetGatherTaskTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetGatherTaskTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅采集任务
BOOL CSysApiDataEntry::UnsubRtnNetGatherTaskTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetGatherTaskTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅设备变更
BOOL CSysApiDataEntry::SubRtnNetDeviceChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetDeviceChgTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅设备变更
BOOL CSysApiDataEntry::UnsubRtnNetDeviceChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetDeviceChgTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅常用设备型号
BOOL CSysApiDataEntry::SubRtnNetDeviceTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetDeviceTypeTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅常用设备型号
BOOL CSysApiDataEntry::UnsubRtnNetDeviceTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetDeviceTypeTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅常用设备类别
BOOL CSysApiDataEntry::SubRtnNetDeviceCategoryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetDeviceCategoryTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅常用设备类别
BOOL CSysApiDataEntry::UnsubRtnNetDeviceCategoryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetDeviceCategoryTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅设备厂商
BOOL CSysApiDataEntry::SubRtnNetManufactoryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetManufactoryTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅设备厂商
BOOL CSysApiDataEntry::UnsubRtnNetManufactoryTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetManufactoryTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅设备共同体
BOOL CSysApiDataEntry::SubRtnNetCommunityTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetCommunityTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅设备共同体
BOOL CSysApiDataEntry::UnsubRtnNetCommunityTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetCommunityTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅端口类型
BOOL CSysApiDataEntry::SubRtnNetPortTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetPortTypeTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅端口类型
BOOL CSysApiDataEntry::UnsubRtnNetPortTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetPortTypeTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅会员接入地点
BOOL CSysApiDataEntry::SubRtnNetPartAccessSpotTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetPartAccessSpotTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅会员接入地点
BOOL CSysApiDataEntry::UnsubRtnNetPartAccessSpotTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetPartAccessSpotTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅端口
BOOL CSysApiDataEntry::SubRtnNetInterfaceTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetInterfaceTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅端口
BOOL CSysApiDataEntry::UnsubRtnNetInterfaceTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetInterfaceTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅GeneralOID
BOOL CSysApiDataEntry::SubRtnNetGeneralOIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetGeneralOIDTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅GeneralOID
BOOL CSysApiDataEntry::UnsubRtnNetGeneralOIDTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetGeneralOIDTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅监控对象类别
BOOL CSysApiDataEntry::SubRtnNetMonitorTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorTypeTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅监控对象类别
BOOL CSysApiDataEntry::UnsubRtnNetMonitorTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorTypeTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅指标统表
BOOL CSysApiDataEntry::SubRtnNetMonitorAttrScopeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorAttrScopeTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅指标统表
BOOL CSysApiDataEntry::UnsubRtnNetMonitorAttrScopeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorAttrScopeTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅监控指标表
BOOL CSysApiDataEntry::SubRtnNetMonitorAttrTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorAttrTypeTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅监控指标表
BOOL CSysApiDataEntry::UnsubRtnNetMonitorAttrTypeTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorAttrTypeTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅监控对象指标表
BOOL CSysApiDataEntry::SubRtnNetMonitorObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorObjectAttrTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅监控对象指标表
BOOL CSysApiDataEntry::UnsubRtnNetMonitorObjectAttrTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorObjectAttrTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅设备对象组表
BOOL CSysApiDataEntry::SubRtnNetMonitorDeviceGroupTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorDeviceGroupTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅设备对象组表
BOOL CSysApiDataEntry::UnsubRtnNetMonitorDeviceGroupTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorDeviceGroupTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅任务信息表
BOOL CSysApiDataEntry::SubRtnNetMonitorTaskInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorTaskInfoTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅任务信息表
BOOL CSysApiDataEntry::UnsubRtnNetMonitorTaskInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorTaskInfoTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅任务结果表
BOOL CSysApiDataEntry::SubRtnNetMonitorTaskResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorTaskResultTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅任务结果表
BOOL CSysApiDataEntry::UnsubRtnNetMonitorTaskResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorTaskResultTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅任务对象集
BOOL CSysApiDataEntry::SubRtnNetMonitorTaskObjectSetTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorTaskObjectSetTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅任务对象集
BOOL CSysApiDataEntry::UnsubRtnNetMonitorTaskObjectSetTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorTaskObjectSetTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅会员链路信息表
BOOL CSysApiDataEntry::SubRtnNetPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetPartyLinkInfoTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅会员链路信息表
BOOL CSysApiDataEntry::UnsubRtnNetPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetPartyLinkInfoTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅模块
BOOL CSysApiDataEntry::SubRtnNetModuleTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetModuleTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅模块
BOOL CSysApiDataEntry::UnsubRtnNetModuleTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetModuleTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅任务结果状态表
BOOL CSysApiDataEntry::SubRtnNetMonitorTaskStatusResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorTaskStatusResultTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅任务结果状态表
BOOL CSysApiDataEntry::UnsubRtnNetMonitorTaskStatusResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorTaskStatusResultTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅设备配置表
BOOL CSysApiDataEntry::SubRtnNetCfgFileTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetCfgFileTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅设备配置表
BOOL CSysApiDataEntry::UnsubRtnNetCfgFileTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetCfgFileTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅任务结果规则分析表
BOOL CSysApiDataEntry::SubRtnNetMonitorDeviceTaskTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorDeviceTaskTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅任务结果规则分析表
BOOL CSysApiDataEntry::UnsubRtnNetMonitorDeviceTaskTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetMonitorDeviceTaskTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅文件通用操作
BOOL CSysApiDataEntry::SubRtnFileGeneralOperTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnFileGeneralOperTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅文件通用操作
BOOL CSysApiDataEntry::UnsubRtnFileGeneralOperTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnFileGeneralOperTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅基线表
BOOL CSysApiDataEntry::SubRtnNetBaseLineTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetBaseLineTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅基线表
BOOL CSysApiDataEntry::UnsubRtnNetBaseLineTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetBaseLineTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅基线结果表
BOOL CSysApiDataEntry::SubRtnNetBaseLineResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetBaseLineResultTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅基线结果表
BOOL CSysApiDataEntry::UnsubRtnNetBaseLineResultTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetBaseLineResultTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅会员链路状态信息表
BOOL CSysApiDataEntry::SubRtnNetPartyLinkStatusInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetPartyLinkStatusInfoTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅会员链路状态信息表
BOOL CSysApiDataEntry::UnsubRtnNetPartyLinkStatusInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetPartyLinkStatusInfoTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅本地ping结果
BOOL CSysApiDataEntry::SubRtnNetLocalPingResultInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetLocalPingResultInfoTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅本地ping结果
BOOL CSysApiDataEntry::UnsubRtnNetLocalPingResultInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetLocalPingResultInfoTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅远程ping结果
BOOL CSysApiDataEntry::SubRtnNetRomotePingResultInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetRomotePingResultInfoTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅远程ping结果
BOOL CSysApiDataEntry::UnsubRtnNetRomotePingResultInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetRomotePingResultInfoTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅订阅会员链路费用表
BOOL CSysApiDataEntry::SubRtnMemberLinkCostTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnMemberLinkCostTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅订阅会员链路费用表
BOOL CSysApiDataEntry::UnsubRtnMemberLinkCostTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnMemberLinkCostTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///订阅订阅非会员链路表信息
BOOL CSysApiDataEntry::SubRtnNetNonPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetNonPartyLinkInfoTopicRegister();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅订阅非会员链路表信息
BOOL CSysApiDataEntry::UnsubRtnNetNonPartyLinkInfoTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnNetNonPartyLinkInfoTopicRegister();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}


BOOL CSysApiDataEntry::SubscriberTopic(TShfeFtdcTypeSubcriberObjectIDType ObjectID, TShfeFtdcTypeObjectIDType	subObjectID , int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	CString strObjectID = CA2T(ObjectID);
	if(subObjectID)
	{
		if(strcmp(subObjectID ,"") !=0)
		{
			strObjectID +=_T(".");
			strObjectID +=CA2T(subObjectID);
		}
	}
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	CShfeFtdcReqQrySubscriberField field;
	memset(&field, 0, sizeof(field));
	lstrcpyA(field.ObjectID, CT2A(strObjectID));
	field.ObjectNum = nObjectNum;
	field.KeepAlive = 1;
	if(nObjectNum ==-1)
	{
		lstrcpyA(field.MonTime, CT2A(dispatcher.GetSubcriberTime()));
		strcpy(field.MonDate, dispatcher.GetTradingDay().data());
	}
	if(nObjectNum ==-2)
	{
		strcpy(field.MonDate ,startDate);
		strcpy(field.MonTime ,startTime);
	}
	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySubscriberTopic(&field, ++Queue);
	if (nRet == 0)
	{
		Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
		CMap<CString, LPCTSTR, int, int> &mapCounter = dispatcher.GetUserApiHandler().GetObjectSubCounter();
		int value = 0;
		if (mapCounter.Lookup(strObjectID, value)) mapCounter.SetAt(strObjectID, ++value);
		else mapCounter.SetAt(strObjectID, 1);
	}

	return (nRet == 0);
}

BOOL CSysApiDataEntry::UnsubscriberTopic(TShfeFtdcTypeSubcriberObjectIDType ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ,int nRequestID)
{
	CString strObjectID = CA2T(ObjectID);
	if(subObjectID)
	{
		if(strcmp(subObjectID ,"") !=0)
		{
			strObjectID +=_T(".");
			strObjectID +=CA2T(subObjectID);
		}
	}
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());

	CMap<CString, LPCTSTR, int, int> &mapCounter = dispatcher.GetUserApiHandler().GetObjectSubCounter();
	int value = 0;
	if (!mapCounter.Lookup(strObjectID, value) || value <= 0)
		return FALSE;

	if (value == 1)
	{
		CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();
		CShfeFtdcReqQrySubscriberField field;
		memset(&field, 0, sizeof(field));
		lstrcpyA(field.ObjectID,  CT2A(strObjectID));
		field.KeepAlive = 0;
		int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySubscriberTopic(&field, ++Queue);
		if (nRet == 0)
		{
			Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
		}
		if (nRet != 0) return FALSE;
	}

	mapCounter.SetAt(strObjectID, --value);

	return TRUE;
}

