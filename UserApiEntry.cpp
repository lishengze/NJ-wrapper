
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
	
	///��������������֮��ص�δ�������
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();
	Queue.RemoveBySender((LPVOID)this);
	
	///���CPUӦ���ı�����֮��صĶ��ļ�¼
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
	
	///���MemӦ���ı�����֮��صĶ��ļ�¼
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
	
	///���processӦ���ı�����֮��صĶ��ļ�¼
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
	
	///���filesystemӦ���ı�����֮��صĶ��ļ�¼
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
	
	///���networkӦ���ı�����֮��صĶ��ļ�¼
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
	
	///�������������ϢӦ���ı�����֮��صĶ��ļ�¼
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
	
	///�����ü�ض�����ϢӦ���ı�����֮��صĶ��ļ�¼
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
	
	///������ҵ����̺������Ķ�Ӧ��ϵӦ���ı�����֮��صĶ��ļ�¼
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
	
	///�����־�ļ�����Ӧ���ı�����֮��صĶ��ļ�¼
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
	
	///��������ϵ��ѯӦ���ı�����֮��صĶ��ļ�¼
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
	
	///����û���Ϣ��ѯ����Ӧ���ı�����֮��صĶ��ļ�¼
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
	
	///��������û���Ϣ��ѯ����Ӧ���ı�����֮��صĶ��ļ�¼
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
	
	///����澯�¼���ѯ����Ӧ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnWarningEventTopicRegister().remove((void*)this);
	///�������״ָ̬���ѯӦ���ı�����֮��صĶ��ļ�¼
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
	
	///�����Ч������ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnInvalidateOrderTopicRegister().remove((void*)this);
	///�������״̬��ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnOrderStatusTopicRegister().remove((void*)this);
	///��������ɽ���ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnBargainOrderTopicRegister().remove((void*)this);
	///�����Լ�������Բ�ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnInstPropertyTopicRegister().remove((void*)this);
	///�����Լ��֤���ʲ�ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnMarginRateTopicRegister().remove((void*)this);
	///�����Լ�ǵ�ͣ���ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnPriceLimitTopicRegister().remove((void*)this);
	///�����Ա�޲ֲ�ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnPartPosiLimitTopicRegister().remove((void*)this);
	///����ͻ��޲ֲ�ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnClientPosiLimitTopicRegister().remove((void*)this);
	///�������ͻ��޲ֲ�ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnSpecialPosiLimitTopicRegister().remove((void*)this);
	///����˻�������ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnTransactionChgTopicRegister().remove((void*)this);
	///����ͻ����ݱ䶯��ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnClientChgTopicRegister().remove((void*)this);
	///�����Ա�ͻ����ձ䶯��ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnPartClientChgTopicRegister().remove((void*)this);
	///����޲����ݱ䶯��ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnPosiLimitChgTopicRegister().remove((void*)this);
	///�����ֵ��ȱ䶯��ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnHedgeDetailChgTopicRegister().remove((void*)this);
	///�����Ա�䶯��ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnParticipantChgTopicRegister().remove((void*)this);
	///�����֤���ʱ䶯��ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnMarginRateChgTopicRegister().remove((void*)this);
	///���IP��ַ�䶯��ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnUserIpChgTopicRegister().remove((void*)this);
	///����޲����ݱ䶯��ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnClientPosiLimitChgTopicRegister().remove((void*)this);
	///����޲����ݱ䶯��ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnSpecPosiLimitChgTopicRegister().remove((void*)this);
	///�����ʷ����״ָ̬���ѯӦ���ı�����֮��صĶ��ļ�¼
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
	
	///���ǰ����Ӧ��Ϣ��ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnFrontInfoTopicRegister().remove((void*)this);
	///�����Ա��ʼ��Ӧ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnParticipantInitTopicRegister().remove((void*)this);
	///�����ϯ��ʼ��Ӧ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnUserInitTopicRegister().remove((void*)this);
	///����ͻ���ʼ��Ӧ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnClientInitTopicRegister().remove((void*)this);
	///���������־��ѯӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnTradeLogTopicRegister().remove((void*)this);
	///�������ϵͳ��¼��Ϣ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnTradeUserLoginInfoTopicRegister().remove((void*)this);
	///������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnUpdateSysConfigTopicRegister().remove((void*)this);
	///������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnSysUserRegister().remove((void*)this);
	///������ϵͳʱ��ͬ�����ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnSysTimeSyncTopicRegister().remove((void*)this);
	///������������л�֪ͨ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnDataCenterChgTopicRegister().remove((void*)this);
	///�����־�¼�Ӧ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnSyslogEventTopicRegister().remove((void*)this);
	///���WebӦ����Ϣ���ı�����֮��صĶ��ļ�¼
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
	
	///���Ӧ��servlet��Ϣ���ı�����֮��صĶ��ļ�¼
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
	
	///����ļ���Ϣ���ı�����֮��صĶ��ļ�¼
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
	
	///���Ӧ�ûỰ��Ϣ���ı�����֮��صĶ��ļ�¼
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
	
	///���JDBC��Ϣ���ı�����֮��صĶ��ļ�¼
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
	
	///����߳���Ϣ���ı�����֮��صĶ��ļ�¼
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
	
	///����������Ϣ���ı�����֮��صĶ��ļ�¼
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
	
	///���ϵͳ������Ϣ���ı�����֮��صĶ��ļ�¼
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
	
	///���ϵͳ�ڴ����Ϣ���ı�����֮��صĶ��ļ�¼
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
	
	///����ļ�������Ϣ���ı�����֮��صĶ��ļ�¼
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
	
	///���������Ϣ���ı�����֮��صĶ��ļ�¼
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
	
	///�����������Ϣ���ı�����֮��صĶ��ļ�¼
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
	
	///������ݿ��ѯӦ���ı�����֮��صĶ��ļ�¼
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
	
	///���ͨ�÷���Ӧ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnGeneralFieldTopicRegister().remove((void*)this);
	///����澯���������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnWarningActiveChangeRegister().remove((void*)this);
	///���ͨ�ò������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnGeneralOperateTopicRegister().remove((void*)this);
	///��������豸���ӹ�ϵ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetDeviceLinkedTopicRegister().remove((void*)this);
	///�������ϵͳǰ�ñ�����Ӧ��Ϣ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnTradeFrontOrderRttStatTopicRegister().remove((void*)this);
	///�����Աϯλ����״̬���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnParticTradeOrderStatesTopicRegister().remove((void*)this);
	///���ϵͳ·����Ϣ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnRouterInfoTopicRegister().remove((void*)this);
	///�������I/O��Ϣ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnDiskIOTopicRegister().remove((void*)this);
	///���ϵͳ״̬��Ϣ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnStatInfoTopicRegister().remove((void*)this);
	///�������ϵͳǰ�ñ����ֲ����䶩�ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnTradeOrderRttCutLineTopicRegister().remove((void*)this);
	///�����Ա�ͻ���Ϣ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnClientInfoTopicRegister().remove((void*)this);
	///��������¼��������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnEventDescriptionTopicRegister().remove((void*)this);
	///�������ǰ��ΨһID��Ϣ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnFrontUniqueIDTopicRegister().remove((void*)this);
	///������Ļ�Ա��·��ַ�����Ϣ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetPartyLinkAddrChangeTopicRegister().remove((void*)this);
	///���������ɾ����Ա�б���Ϣ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetDelPartyLinkInfoTopicRegister().remove((void*)this);
	///��������������������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnPerformanceTopTopicRegister().remove((void*)this);
	///�������Լ״̬�л����ݶ��ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnInstrumentStatusTopicRegister().remove((void*)this);
	///������ĺ�Լ���׽���Ϣ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnCurrTradingSegmentAttrTopicRegister().remove((void*)this);
	///��������������Ӧ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetAreaTopicRegister().remove((void*)this);
	///�����������Ӧ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetSubAreaTopicRegister().remove((void*)this);
	///�����������IPӦ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetSubAreaIPTopicRegister().remove((void*)this);
	///��������豸���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetDeviceTopicRegister().remove((void*)this);
	///�����¥���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetBuildingTopicRegister().remove((void*)this);
	///����������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetRoomTopicRegister().remove((void*)this);
	///��������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetCabinetsTopicRegister().remove((void*)this);
	///���OID���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetOIDTopicRegister().remove((void*)this);
	///���ʱ����Զ��ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetTimePolicyTopicRegister().remove((void*)this);
	///����ɼ������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetGatherTaskTopicRegister().remove((void*)this);
	///����豸������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetDeviceChgTopicRegister().remove((void*)this);
	///��������豸�ͺŶ��ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetDeviceTypeTopicRegister().remove((void*)this);
	///��������豸����ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetDeviceCategoryTopicRegister().remove((void*)this);
	///����豸���̶��ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetManufactoryTopicRegister().remove((void*)this);
	///����豸��ͬ�嶩�ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetCommunityTopicRegister().remove((void*)this);
	///����˿����Ͷ��ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetPortTypeTopicRegister().remove((void*)this);
	///�����Ա����ص㶩�ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetPartAccessSpotTopicRegister().remove((void*)this);
	///����˿ڶ��ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetInterfaceTopicRegister().remove((void*)this);
	///���GeneralOID���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetGeneralOIDTopicRegister().remove((void*)this);
	///�����ض�������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetMonitorTypeTopicRegister().remove((void*)this);
	///���ָ��ͳ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetMonitorAttrScopeTopicRegister().remove((void*)this);
	///������ָ����ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetMonitorAttrTypeTopicRegister().remove((void*)this);
	///�����ض���ָ����ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetMonitorObjectAttrTopicRegister().remove((void*)this);
	///����豸��������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetMonitorDeviceGroupTopicRegister().remove((void*)this);
	///���������Ϣ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetMonitorTaskInfoTopicRegister().remove((void*)this);
	///������������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetMonitorTaskResultTopicRegister().remove((void*)this);
	///���������󼯶��ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetMonitorTaskObjectSetTopicRegister().remove((void*)this);
	///�����Ա��·��Ϣ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetPartyLinkInfoTopicRegister().remove((void*)this);
	///���ģ�鶩�ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetModuleTopicRegister().remove((void*)this);
	///���������״̬���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetMonitorTaskStatusResultTopicRegister().remove((void*)this);
	///����豸���ñ��ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetCfgFileTopicRegister().remove((void*)this);
	///�������������������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetMonitorDeviceTaskTopicRegister().remove((void*)this);
	///����ļ�ͨ�ò������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnFileGeneralOperTopicRegister().remove((void*)this);
	///������߱��ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetBaseLineTopicRegister().remove((void*)this);
	///������߽�����ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetBaseLineResultTopicRegister().remove((void*)this);
	///�����Ա��·״̬��Ϣ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetPartyLinkStatusInfoTopicRegister().remove((void*)this);
	///�������ping������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetLocalPingResultInfoTopicRegister().remove((void*)this);
	///���Զ��ping������ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetRomotePingResultInfoTopicRegister().remove((void*)this);
	///������Ļ�Ա��·���ñ��ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnMemberLinkCostTopicRegister().remove((void*)this);
	///������ķǻ�Ա��·����Ϣ���ı�����֮��صĶ��ļ�¼
	dispatcher.GetUserApiHandler().GetRtnNetNonPartyLinkInfoTopicRegister().remove((void*)this);
}


///CPU��ѯ
BOOL CSysApiDataEntry::ReqQryTopCpuInfoTopic(CShfeFtdcReqQryTopCpuInfoField *pReqQryTopCpuInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTopCpuInfoTopic(pReqQryTopCpuInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///Mem��ѯ
BOOL CSysApiDataEntry::ReqQryTopMemInfoTopic(CShfeFtdcReqQryTopMemInfoField *pReqQryTopMemInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTopMemInfoTopic(pReqQryTopMemInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///process��ѯ
BOOL CSysApiDataEntry::ReqQryTopProcessInfoTopic(CShfeFtdcReqQryTopProcessInfoField *pReqQryTopProcessInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTopProcessInfoTopic(pReqQryTopProcessInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///filesystem��ѯ
BOOL CSysApiDataEntry::ReqQryFileSystemInfoTopic(CShfeFtdcReqQryFileSystemInfoField *pReqQryFileSystemInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryFileSystemInfoTopic(pReqQryFileSystemInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///network��ѯ
BOOL CSysApiDataEntry::ReqQryNetworkInfoTopic(CShfeFtdcReqQryNetworkInfoField *pReqQryNetworkInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetworkInfoTopic(pReqQryNetworkInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����������Ϣ��ѯ
BOOL CSysApiDataEntry::ReqQryHostEnvTopic(CShfeFtdcReqQryHostEnvField *pReqQryHostEnv, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryHostEnvTopic(pReqQryHostEnv, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��ü�ض�����Ϣ��ѯ
BOOL CSysApiDataEntry::ReqQryMonitorObjectTopic(CShfeFtdcReqQryMonitorObjectField *pReqQryMonitorObject, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryMonitorObjectTopic(pReqQryMonitorObject, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///���ҵ����̺������Ķ�Ӧ��ϵ��ѯ
BOOL CSysApiDataEntry::ReqQryObjectRationalTopic(CShfeFtdcReqQryObjectRationalField *pReqQryObjectRational, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryObjectRationalTopic(pReqQryObjectRational, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��־�ļ����ݲ�ѯ
BOOL CSysApiDataEntry::ReqQrySyslogInfoTopic(CShfeFtdcReqQrySyslogInfoField *pReqQrySyslogInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySyslogInfoTopic(pReqQrySyslogInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///������ݶ�������
BOOL CSysApiDataEntry::ReqQrySubscriberTopic(CShfeFtdcReqQrySubscriberField *pReqQrySubscriber, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySubscriberTopic(pReqQrySubscriber, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�����ϵ��ѯ
BOOL CSysApiDataEntry::ReqQryOidRelationTopic(CShfeFtdcReqQryOidRelationField *pReqQryOidRelation, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryOidRelationTopic(pReqQryOidRelation, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�û���Ϣ��ѯ����
BOOL CSysApiDataEntry::ReqQryUserInfoTopic(CShfeFtdcReqQryUserInfoField *pReqQryUserInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryUserInfoTopic(pReqQryUserInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�����û���Ϣ��ѯ����
BOOL CSysApiDataEntry::ReqQryOnlineUserInfoTopic(CShfeFtdcReqQryOnlineUserInfoField *pReqQryOnlineUserInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryOnlineUserInfoTopic(pReqQryOnlineUserInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�澯�¼���ѯ����
BOOL CSysApiDataEntry::ReqQryWarningEventTopic(CShfeFtdcReqQryWarningEventField *pReqQryWarningEvent, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryWarningEventTopic(pReqQryWarningEvent, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����״ָ̬���ѯ
BOOL CSysApiDataEntry::ReqQryObjectAttrTopic(CShfeFtdcReqQryObjectAttrField *pReqQryObjectAttr, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryObjectAttrTopic(pReqQryObjectAttr, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��Ч������ѯ
BOOL CSysApiDataEntry::ReqQryInvalidateOrderTopic(CShfeFtdcReqQryInvalidateOrderField *pReqQryInvalidateOrder, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryInvalidateOrderTopic(pReqQryInvalidateOrder, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����״̬��ѯ
BOOL CSysApiDataEntry::ReqQryOrderStatusTopic(CShfeFtdcReqQryOrderStatusField *pReqQryOrderStatus, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryOrderStatusTopic(pReqQryOrderStatus, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�����ɽ���ѯ
BOOL CSysApiDataEntry::ReqQryBargainOrderTopic(CShfeFtdcReqQryBargainOrderField *pReqQryBargainOrder, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryBargainOrderTopic(pReqQryBargainOrder, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��Լ�������Բ�ѯ
BOOL CSysApiDataEntry::ReqQryInstPropertyTopic(CShfeFtdcReqQryInstPropertyField *pReqQryInstProperty, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryInstPropertyTopic(pReqQryInstProperty, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��Լ��֤���ʲ�ѯ
BOOL CSysApiDataEntry::ReqQryMarginRateTopic(CShfeFtdcReqQryMarginRateField *pReqQryMarginRate, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryMarginRateTopic(pReqQryMarginRate, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��Լ�ǵ�ͣ���ѯ
BOOL CSysApiDataEntry::ReqQryPriceLimitTopic(CShfeFtdcReqQryPriceLimitField *pReqQryPriceLimit, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryPriceLimitTopic(pReqQryPriceLimit, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��Ա�޲ֲ�ѯ
BOOL CSysApiDataEntry::ReqQryPartPosiLimitTopic(CShfeFtdcReqQryPartPosiLimitField *pReqQryPartPosiLimit, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryPartPosiLimitTopic(pReqQryPartPosiLimit, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�ͻ��޲ֲ�ѯ
BOOL CSysApiDataEntry::ReqQryClientPosiLimitTopic(CShfeFtdcReqQryClientPosiLimitField *pReqQryClientPosiLimit, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryClientPosiLimitTopic(pReqQryClientPosiLimit, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����ͻ��޲ֲ�ѯ
BOOL CSysApiDataEntry::ReqQrySpecialPosiLimitTopic(CShfeFtdcReqQrySpecialPosiLimitField *pReqQrySpecialPosiLimit, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySpecialPosiLimitTopic(pReqQrySpecialPosiLimit, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�˻�������ѯ
BOOL CSysApiDataEntry::ReqQryTransactionChgTopic(CShfeFtdcReqQryTransactionChgField *pReqQryTransactionChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTransactionChgTopic(pReqQryTransactionChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�ͻ����ݱ䶯��ѯ
BOOL CSysApiDataEntry::ReqQryClientChgTopic(CShfeFtdcReqQryClientChgField *pReqQryClientChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryClientChgTopic(pReqQryClientChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��Ա�ͻ����ձ䶯��ѯ
BOOL CSysApiDataEntry::ReqQryPartClientChgTopic(CShfeFtdcReqQryPartClientChgField *pReqQryPartClientChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryPartClientChgTopic(pReqQryPartClientChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�޲����ݱ䶯��ѯ
BOOL CSysApiDataEntry::ReqQryPosiLimitChgTopic(CShfeFtdcReqQryPosiLimitChgField *pReqQryPosiLimitChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryPosiLimitChgTopic(pReqQryPosiLimitChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��ֵ��ȱ䶯��ѯ
BOOL CSysApiDataEntry::ReqQryHedgeDetailChgTopic(CShfeFtdcReqQryHedgeDetailChgField *pReqQryHedgeDetailChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryHedgeDetailChgTopic(pReqQryHedgeDetailChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��Ա�䶯��ѯ
BOOL CSysApiDataEntry::ReqQryParticipantChgTopic(CShfeFtdcReqQryParticipantChgField *pReqQryParticipantChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryParticipantChgTopic(pReqQryParticipantChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��֤���ʱ䶯��ѯ
BOOL CSysApiDataEntry::ReqQryMarginRateChgTopic(CShfeFtdcReqQryMarginRateChgField *pReqQryMarginRateChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryMarginRateChgTopic(pReqQryMarginRateChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///IP��ַ�䶯��ѯ
BOOL CSysApiDataEntry::ReqQryUserIpChgTopic(CShfeFtdcReqQryUserIpChgField *pReqQryUserIpChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryUserIpChgTopic(pReqQryUserIpChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�޲����ݱ䶯��ѯ
BOOL CSysApiDataEntry::ReqQryClientPosiLimitChgTopic(CShfeFtdcReqQryClientPosiLimitChgField *pReqQryClientPosiLimitChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryClientPosiLimitChgTopic(pReqQryClientPosiLimitChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�޲����ݱ䶯��ѯ
BOOL CSysApiDataEntry::ReqQrySpecPosiLimitChgTopic(CShfeFtdcReqQrySpecPosiLimitChgField *pReqQrySpecPosiLimitChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySpecPosiLimitChgTopic(pReqQrySpecPosiLimitChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��ʷ����״ָ̬���ѯ
BOOL CSysApiDataEntry::ReqQryHistoryObjectAttrTopic(CShfeFtdcReqQryHistoryObjectAttrField *pReqQryHistoryObjectAttr, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryHistoryObjectAttrTopic(pReqQryHistoryObjectAttr, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///ǰ����Ӧ��Ϣ��ѯ
BOOL CSysApiDataEntry::ReqQryFrontInfoTopic(CShfeFtdcReqQryFrontInfoField *pReqQryFrontInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryFrontInfoTopic(pReqQryFrontInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�û���¼
BOOL CSysApiDataEntry::ReqQrySysUserLoginTopic(CShfeFtdcReqQrySysUserLoginField *pReqQrySysUserLogin, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySysUserLoginTopic(pReqQrySysUserLogin, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�û��ǳ�
BOOL CSysApiDataEntry::ReqQrySysUserLogoutTopic(CShfeFtdcReqQrySysUserLogoutField *pReqQrySysUserLogout, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySysUserLogoutTopic(pReqQrySysUserLogout, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�û��޸�����
BOOL CSysApiDataEntry::ReqQrySysUserPasswordUpdateTopic(CShfeFtdcReqQrySysUserPasswordUpdateField *pReqQrySysUserPasswordUpdate, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySysUserPasswordUpdateTopic(pReqQrySysUserPasswordUpdate, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///ע���û�
BOOL CSysApiDataEntry::ReqQrySysUserRegisterTopic(CShfeFtdcReqQrySysUserRegisterField *pReqQrySysUserRegister, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySysUserRegisterTopic(pReqQrySysUserRegister, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///ɾ���û�
BOOL CSysApiDataEntry::ReqQrySysUserDeleteTopic(CShfeFtdcReqQrySysUserDeleteField *pReqQrySysUserDelete, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySysUserDeleteTopic(pReqQrySysUserDelete, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///������־��ѯ
BOOL CSysApiDataEntry::ReqQryTradeLogTopic(CShfeFtdcReqQryTradeLogField *pReqQryTradeLog, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTradeLogTopic(pReqQryTradeLog, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�澯�¼��޸�
BOOL CSysApiDataEntry::ReqQryWarningEventUpdateTopic(CShfeFtdcReqQryWarningEventUpdateField *pReqQryWarningEventUpdate, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryWarningEventUpdateTopic(pReqQryWarningEventUpdate, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����ϵͳ��¼��Ϣ��ѯ
BOOL CSysApiDataEntry::ReqQryTradeUserLoginInfoTopic(CShfeFtdcReqQryTradeUserLoginInfoField *pReqQryTradeUserLoginInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTradeUserLoginInfoTopic(pReqQryTradeUserLoginInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��Ա���ײ�ѯ
BOOL CSysApiDataEntry::ReqQryPartTradeTopic(CShfeFtdcReqQryPartTradeField *pReqQryPartTrade, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryPartTradeTopic(pReqQryPartTrade, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///���׷�ֵ��ѯ
BOOL CSysApiDataEntry::ReqQryTradepeakTopic(CShfeFtdcReqQryTradepeakField *pReqQryTradepeak, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTradepeakTopic(pReqQryTradepeak, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����ƽ̨��ʼ����Ϣ��ѯ
BOOL CSysApiDataEntry::ReqQryParticipantInitTopic(CShfeFtdcReqQryParticipantInitField *pReqQryParticipantInit, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryParticipantInitTopic(pReqQryParticipantInit, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����ƽ̨��ʼ����Ϣ��ѯ
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

///���ϵͳ�����û���ѯ
BOOL CSysApiDataEntry::ReqQryMonitorOnlineUser(CShfeFtdcReqQryMonitorOnlineUserField *pReqQryMonitorOnlineUser, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryMonitorOnlineUser(pReqQryMonitorOnlineUser, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����ϵͳǰ��ͳ�Ʋ�ѯ
BOOL CSysApiDataEntry::ReqQryFrontStat(CShfeFtdcReqQryFrontStatField *pReqQryFrontStat, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryFrontStat(pReqQryFrontStat, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��ʷ��ֵ��ѯ
BOOL CSysApiDataEntry::ReqQryHistoryTradePeakTopic(CShfeFtdcReqQryHistoryTradePeakField *pReqQryHistoryTradePeak, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryHistoryTradePeakTopic(pReqQryHistoryTradePeak, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��־�¼���ѯ
BOOL CSysApiDataEntry::ReqQrySyslogEventTopic(CShfeFtdcReqQrySyslogEventField *pReqQrySyslogEvent, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySyslogEventTopic(pReqQrySyslogEvent, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///tomcat��Ϣ��ѯ
BOOL CSysApiDataEntry::ReqQryTomcatInfoTopic(CShfeFtdcReqQryTomcatInfoField *pReqQryTomcatInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTomcatInfoTopic(pReqQryTomcatInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///���ݿ��ѯ
BOOL CSysApiDataEntry::ReqQryDBQueryTopic(CShfeFtdcReqQryDBQueryField *pReqQryDBQuery, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryDBQueryTopic(pReqQryDBQuery, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�ļ���������
BOOL CSysApiDataEntry::ReqQryGetFileTopic(CShfeFtdcReqQryGetFileField *pReqQryGetFile, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryGetFileTopic(pReqQryGetFile, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��־�¼��޸�����
BOOL CSysApiDataEntry::ReqQrySyslogEventUpdateTopic(CShfeFtdcReqQrySyslogEventUpdateField *pReqQrySyslogEventUpdate, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQrySyslogEventUpdateTopic(pReqQrySyslogEventUpdate, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�澯��ϸ��ѯ
BOOL CSysApiDataEntry::ReqQryWarningQueryTopic(CShfeFtdcReqQryWarningQueryField *pReqQryWarningQuery, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryWarningQueryTopic(pReqQryWarningQuery, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��վ���ʲ�ѯ
BOOL CSysApiDataEntry::ReqQryWebVisitTopic(CShfeFtdcReqQryWebVisitField *pReqQryWebVisit, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryWebVisitTopic(pReqQryWebVisit, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�澯������
BOOL CSysApiDataEntry::ReqQryWarningActiveChange(CShfeFtdcReqQryWarningActiveChangeField *pReqQryWarningActiveChange, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryWarningActiveChange(pReqQryWarningActiveChange, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///ͨ�ò���
BOOL CSysApiDataEntry::ReqQryGeneralOperateTopic(CShfeFtdcReqQryGeneralOperateField *pReqQryGeneralOperate, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryGeneralOperateTopic(pReqQryGeneralOperate, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�����豸���ӹ�ϵ����
BOOL CSysApiDataEntry::ReqQryNetDeviceLinkedTopic(CShfeFtdcReqQryNetDeviceLinkedField *pReqQryNetDeviceLinked, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetDeviceLinkedTopic(pReqQryNetDeviceLinked, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����ϵͳ��¼��Ϣ����
BOOL CSysApiDataEntry::ReqQryTradeUserLoginStatTopic(CShfeFtdcReqQryTradeUserLoginStatField *pReqQryTradeUserLoginStat, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTradeUserLoginStatTopic(pReqQryTradeUserLoginStat, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����ϵͳǰ�ñ�����Ӧ��Ϣ
BOOL CSysApiDataEntry::ReqQryTradeFrontOrderRttStatTopic(CShfeFtdcReqQryTradeFrontOrderRttStatField *pReqQryTradeFrontOrderRttStat, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTradeFrontOrderRttStatTopic(pReqQryTradeFrontOrderRttStat, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��Աϯλ����״̬
BOOL CSysApiDataEntry::ReqQryParticTradeOrderStatesTopic(CShfeFtdcReqQryParticTradeOrderStatesField *pReqQryParticTradeOrderStates, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryParticTradeOrderStatesTopic(pReqQryParticTradeOrderStates, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///ϵͳ·����Ϣ
BOOL CSysApiDataEntry::ReqQryRouterInfoTopic(CShfeFtdcReqQryRouterInfoField *pReqQryRouterInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryRouterInfoTopic(pReqQryRouterInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����I/O��Ϣ
BOOL CSysApiDataEntry::ReqQryDiskIOTopic(CShfeFtdcReqQryDiskIOField *pReqQryDiskIO, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryDiskIOTopic(pReqQryDiskIO, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///ϵͳ״̬��Ϣ
BOOL CSysApiDataEntry::ReqQryStatInfoTopic(CShfeFtdcReqQryStatInfoField *pReqQryStatInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryStatInfoTopic(pReqQryStatInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����ϵͳǰ�ñ����ֲ�����
BOOL CSysApiDataEntry::ReqQryTradeOrderRttCutLineTopic(CShfeFtdcReqQryTradeOrderRttCutLineField *pReqQryTradeOrderRttCutLine, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryTradeOrderRttCutLineTopic(pReqQryTradeOrderRttCutLine, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��Ա�ͻ���Ϣ
BOOL CSysApiDataEntry::ReqQryClientInfoTopic(CShfeFtdcReqQryClientInfoField *pReqQryClientInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryClientInfoTopic(pReqQryClientInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�����¼�����
BOOL CSysApiDataEntry::ReqQryEventDescriptionTopic(CShfeFtdcReqQryEventDescriptionField *pReqQryEventDescription, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryEventDescriptionTopic(pReqQryEventDescription, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����ǰ��ΨһID��Ϣ
BOOL CSysApiDataEntry::ReqQryFrontUniqueIDTopic(CShfeFtdcReqQryFrontUniqueIDField *pReqQryFrontUniqueID, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryFrontUniqueIDTopic(pReqQryFrontUniqueID, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��Ա��·��ַ�������
BOOL CSysApiDataEntry::ReqQryNetPartyLinkAddrChangeTopic(CShfeFtdcReqQryNetPartyLinkAddrChangeField *pReqQryNetPartyLinkAddrChange, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetPartyLinkAddrChangeTopic(pReqQryNetPartyLinkAddrChange, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///������ɾ����Ա�б���Ϣ
BOOL CSysApiDataEntry::ReqQryNetDelPartyLinkInfoTopic(CShfeFtdcReqQryNetDelPartyLinkInfoField *pReqQryNetDelPartyLinkInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetDelPartyLinkInfoTopic(pReqQryNetDelPartyLinkInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����������������
BOOL CSysApiDataEntry::ReqQryPerformanceTopTopic(CShfeFtdcReqQryPerformanceTopField *pReqQryPerformanceTop, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryPerformanceTopTopic(pReqQryPerformanceTop, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����Լ״̬�л�����
BOOL CSysApiDataEntry::ReqQryInstrumentStatusTopic(CShfeFtdcReqQryInstrumentStatusField *pReqQryInstrumentStatus, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryInstrumentStatusTopic(pReqQryInstrumentStatus, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�����Լ���׽���Ϣ
BOOL CSysApiDataEntry::ReqQryCurrTradingSegmentAttrTopic(CShfeFtdcReqQryCurrTradingSegmentAttrField *pReqQryCurrTradingSegmentAttr, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryCurrTradingSegmentAttrTopic(pReqQryCurrTradingSegmentAttr, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��������ָ���ѯ
BOOL CSysApiDataEntry::ReqQryRealTimeNetObjectAttrTopic(CShfeFtdcReqQryRealTimeNetObjectAttrField *pReqQryRealTimeNetObjectAttr, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryRealTimeNetObjectAttrTopic(pReqQryRealTimeNetObjectAttr, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����������ֲ�ѯ
BOOL CSysApiDataEntry::ReqQryNetAreaTopic(CShfeFtdcReqQryNetAreaField *pReqQryNetArea, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetAreaTopic(pReqQryNetArea, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����������ѯ
BOOL CSysApiDataEntry::ReqQryNetSubAreaTopic(CShfeFtdcReqQryNetSubAreaField *pReqQryNetSubArea, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetSubAreaTopic(pReqQryNetSubArea, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��������IP��ѯ
BOOL CSysApiDataEntry::ReqQryNetSubAreaIPTopic(CShfeFtdcReqQryNetSubAreaIPField *pReqQryNetSubAreaIP, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetSubAreaIPTopic(pReqQryNetSubAreaIP, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�����豸̽������
BOOL CSysApiDataEntry::ReqQryNetDeviceDetectTopic(CShfeFtdcReqQryNetDeviceDetectField *pReqQryNetDeviceDetect, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetDeviceDetectTopic(pReqQryNetDeviceDetect, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�����豸��ѯ����
BOOL CSysApiDataEntry::ReqQryNetDeviceRequestTopic(CShfeFtdcReqQryNetDeviceRequestField *pReqQryNetDeviceRequest, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetDeviceRequestTopic(pReqQryNetDeviceRequest, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��¥��ѯ
BOOL CSysApiDataEntry::ReqQryNetBuildingTopic(CShfeFtdcReqQryNetBuildingField *pReqQryNetBuilding, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetBuildingTopic(pReqQryNetBuilding, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///������ѯ
BOOL CSysApiDataEntry::ReqQryNetRoomTopic(CShfeFtdcReqQryNetRoomField *pReqQryNetRoom, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetRoomTopic(pReqQryNetRoom, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�����ѯ
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

///ʱ�����
BOOL CSysApiDataEntry::ReqQryNetTimePolicyTopic(CShfeFtdcReqQryNetTimePolicyField *pReqQryNetTimePolicy, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetTimePolicyTopic(pReqQryNetTimePolicy, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�ɼ������ѯ
BOOL CSysApiDataEntry::ReqQryNetGatherTaskTopic(CShfeFtdcReqQryNetGatherTaskField *pReqQryNetGatherTask, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetGatherTaskTopic(pReqQryNetGatherTask, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�豸�������
BOOL CSysApiDataEntry::ReqQryNetDeviceChgTopic(CShfeFtdcReqQryNetDeviceChgField *pReqQryNetDeviceChg, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetDeviceChgTopic(pReqQryNetDeviceChg, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�����豸�ͺ�����
BOOL CSysApiDataEntry::ReqQryNetDeviceTypeTopic(CShfeFtdcReqQryNetDeviceTypeField *pReqQryNetDeviceType, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetDeviceTypeTopic(pReqQryNetDeviceType, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�����豸�������
BOOL CSysApiDataEntry::ReqQryNetDeviceCategoryTopic(CShfeFtdcReqQryNetDeviceCategoryField *pReqQryNetDeviceCategory, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetDeviceCategoryTopic(pReqQryNetDeviceCategory, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�豸��������
BOOL CSysApiDataEntry::ReqQryNetManufactoryTopic(CShfeFtdcReqQryNetManufactoryField *pReqQryNetManufactory, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetManufactoryTopic(pReqQryNetManufactory, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�豸��ͬ������
BOOL CSysApiDataEntry::ReqQryNetCommunityTopic(CShfeFtdcReqQryNetCommunityField *pReqQryNetCommunity, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetCommunityTopic(pReqQryNetCommunity, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�˿���������
BOOL CSysApiDataEntry::ReqQryNetPortTypeTopic(CShfeFtdcReqQryNetPortTypeField *pReqQryNetPortType, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetPortTypeTopic(pReqQryNetPortType, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��Ա����ص�����
BOOL CSysApiDataEntry::ReqQryNetPartAccessSpotTopic(CShfeFtdcReqQryNetPartAccessSpotField *pReqQryNetPartAccessSpot, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetPartAccessSpotTopic(pReqQryNetPartAccessSpot, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�˿�����
BOOL CSysApiDataEntry::ReqQryNetInterfaceTopic(CShfeFtdcReqQryNetInterfaceField *pReqQryNetInterface, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetInterfaceTopic(pReqQryNetInterface, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///GeneralOID����
BOOL CSysApiDataEntry::ReqQryNetGeneralOIDTopic(CShfeFtdcReqQryNetGeneralOIDField *pReqQryNetGeneralOID, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetGeneralOIDTopic(pReqQryNetGeneralOID, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��ض������
BOOL CSysApiDataEntry::ReqQryNetMonitorTypeTopic(CShfeFtdcReqQryNetMonitorTypeField *pReqQryNetMonitorType, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorTypeTopic(pReqQryNetMonitorType, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///ָ��ͳ��
BOOL CSysApiDataEntry::ReqQryNetMonitorAttrScopeTopic(CShfeFtdcReqQryNetMonitorAttrScopeField *pReqQryNetMonitorAttrScope, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorAttrScopeTopic(pReqQryNetMonitorAttrScope, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///���ָ���
BOOL CSysApiDataEntry::ReqQryNetMonitorAttrTypeTopic(CShfeFtdcReqQryNetMonitorAttrTypeField *pReqQryNetMonitorAttrType, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorAttrTypeTopic(pReqQryNetMonitorAttrType, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��ض���ָ���
BOOL CSysApiDataEntry::ReqQryNetMonitorObjectAttrTopic(CShfeFtdcReqQryNetMonitorObjectAttrField *pReqQryNetMonitorObjectAttr, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorObjectAttrTopic(pReqQryNetMonitorObjectAttr, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�豸�������
BOOL CSysApiDataEntry::ReqQryNetMonitorDeviceGroupTopic(CShfeFtdcReqQryNetMonitorDeviceGroupField *pReqQryNetMonitorDeviceGroup, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorDeviceGroupTopic(pReqQryNetMonitorDeviceGroup, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///������Ϣ��
BOOL CSysApiDataEntry::ReqQryNetMonitorTaskInfoTopic(CShfeFtdcReqQryNetMonitorTaskInfoField *pReqQryNetMonitorTaskInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorTaskInfoTopic(pReqQryNetMonitorTaskInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��������
BOOL CSysApiDataEntry::ReqQryNetMonitorTaskResultTopic(CShfeFtdcReqQryNetMonitorTaskResultField *pReqQryNetMonitorTaskResult, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorTaskResultTopic(pReqQryNetMonitorTaskResult, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�������
BOOL CSysApiDataEntry::ReqQryNetMonitorTaskObjectSetTopic(CShfeFtdcReqQryNetMonitorTaskObjectSetField *pReqQryNetMonitorTaskObjectSet, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorTaskObjectSetTopic(pReqQryNetMonitorTaskObjectSet, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��Ա��·��Ϣ��
BOOL CSysApiDataEntry::ReqQryNetPartyLinkInfoTopic(CShfeFtdcReqQryNetPartyLinkInfoField *pReqQryNetPartyLinkInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetPartyLinkInfoTopic(pReqQryNetPartyLinkInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��ض���ָ����ձ�
BOOL CSysApiDataEntry::ReqQryNetMonitorActionAttrTopic(CShfeFtdcReqQryNetMonitorActionAttrField *pReqQryNetMonitorActionAttr, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorActionAttrTopic(pReqQryNetMonitorActionAttr, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///ģ��
BOOL CSysApiDataEntry::ReqQryNetModuleTopic(CShfeFtdcReqQryNetModuleField *pReqQryNetModule, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetModuleTopic(pReqQryNetModule, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///������״̬��
BOOL CSysApiDataEntry::ReqQryNetMonitorTaskStatusResultTopic(CShfeFtdcReqQryNetMonitorTaskStatusResultField *pReqQryNetMonitorTaskStatusResult, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorTaskStatusResultTopic(pReqQryNetMonitorTaskStatusResult, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�豸���ñ�
BOOL CSysApiDataEntry::ReqQryNetCfgFileTopic(CShfeFtdcReqQryNetCfgFileField *pReqQryNetCfgFile, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetCfgFileTopic(pReqQryNetCfgFile, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///���������������
BOOL CSysApiDataEntry::ReqQryNetMonitorDeviceTaskTopic(CShfeFtdcReqQryNetMonitorDeviceTaskField *pReqQryNetMonitorDeviceTask, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetMonitorDeviceTaskTopic(pReqQryNetMonitorDeviceTask, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///�ļ�ͨ�ò���
BOOL CSysApiDataEntry::ReqQryFileGeneralOperTopic(CShfeFtdcReqQryFileGeneralOperField *pReqQryFileGeneralOper, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryFileGeneralOperTopic(pReqQryFileGeneralOper, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///���߱�
BOOL CSysApiDataEntry::ReqQryNetBaseLineTopic(CShfeFtdcReqQryNetBaseLineField *pReqQryNetBaseLine, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetBaseLineTopic(pReqQryNetBaseLine, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///���߽����
BOOL CSysApiDataEntry::ReqQryNetBaseLineResultTopic(CShfeFtdcReqQryNetBaseLineResultField *pReqQryNetBaseLineResult, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetBaseLineResultTopic(pReqQryNetBaseLineResult, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///��Ա��·״̬��Ϣ��
BOOL CSysApiDataEntry::ReqQryNetPartyLinkStatusInfoTopic(CShfeFtdcReqQryNetPartyLinkStatusInfoField *pReqQryNetPartyLinkStatusInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetPartyLinkStatusInfoTopic(pReqQryNetPartyLinkStatusInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����ping���
BOOL CSysApiDataEntry::ReqQryNetLocalPingResultInfoTopic(CShfeFtdcReqQryNetLocalPingResultInfoField *pReqQryNetLocalPingResultInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetLocalPingResultInfoTopic(pReqQryNetLocalPingResultInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///Զ��ping���
BOOL CSysApiDataEntry::ReqQryNetRomotePingResultInfoTopic(CShfeFtdcReqQryNetRomotePingResultInfoField *pReqQryNetRomotePingResultInfo, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->ReqQryNetRomotePingResultInfoTopic(pReqQryNetRomotePingResultInfo, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

///����ǻ�Ա��·����Ϣ
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

///����CPUӦ��
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

///ȡ������CPUӦ��
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

///����MemӦ��
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

///ȡ������MemӦ��
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

///����processӦ��
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

///ȡ������processӦ��
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

///����filesystemӦ��
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

///ȡ������filesystemӦ��
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

///����networkӦ��
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

///ȡ������networkӦ��
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

///��������������ϢӦ��
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

///ȡ����������������ϢӦ��
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

///���Ļ�ü�ض�����ϢӦ��
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

///ȡ�����Ļ�ü�ض�����ϢӦ��
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

///���Ļ��ҵ����̺������Ķ�Ӧ��ϵӦ��
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

///ȡ�����Ļ��ҵ����̺������Ķ�Ӧ��ϵӦ��
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

///������־�ļ�����Ӧ��
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

///ȡ��������־�ļ�����Ӧ��
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

///���Ķ����ϵ��ѯӦ��
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

///ȡ�����Ķ����ϵ��ѯӦ��
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

///�����û���Ϣ��ѯ����Ӧ��
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

///ȡ�������û���Ϣ��ѯ����Ӧ��
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

///���������û���Ϣ��ѯ����Ӧ��
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

///ȡ�����������û���Ϣ��ѯ����Ӧ��
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

///���ĸ澯�¼���ѯ����Ӧ��
BOOL CSysApiDataEntry::SubRtnWarningEventTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnWarningEventTopicRegister();
	lstRegister.push_back((void*)this);
	return TRUE;
}

///ȡ�����ĸ澯�¼���ѯ����Ӧ��
BOOL CSysApiDataEntry::UnsubRtnWarningEventTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnWarningEventTopicRegister();
	lstRegister.remove((void*)this);
	return TRUE;
}

///���Ķ���״ָ̬���ѯӦ��
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

///ȡ�����Ķ���״ָ̬���ѯӦ��
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

///������Ч������ѯӦ��
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

///ȡ��������Ч������ѯӦ��
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

///���ı���״̬��ѯӦ��
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

///ȡ�����ı���״̬��ѯӦ��
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

///���ı����ɽ���ѯӦ��
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

///ȡ�����ı����ɽ���ѯӦ��
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

///���ĺ�Լ�������Բ�ѯӦ��
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

///ȡ�����ĺ�Լ�������Բ�ѯӦ��
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

///���ĺ�Լ��֤���ʲ�ѯӦ��
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

///ȡ�����ĺ�Լ��֤���ʲ�ѯӦ��
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

///���ĺ�Լ�ǵ�ͣ���ѯӦ��
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

///ȡ�����ĺ�Լ�ǵ�ͣ���ѯӦ��
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

///���Ļ�Ա�޲ֲ�ѯӦ��
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

///ȡ�����Ļ�Ա�޲ֲ�ѯӦ��
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

///���Ŀͻ��޲ֲ�ѯӦ��
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

///ȡ�����Ŀͻ��޲ֲ�ѯӦ��
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

///��������ͻ��޲ֲ�ѯӦ��
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

///ȡ����������ͻ��޲ֲ�ѯӦ��
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

///�����˻�������ѯӦ��
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

///ȡ�������˻�������ѯӦ��
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

///���Ŀͻ����ݱ䶯��ѯӦ��
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

///ȡ�����Ŀͻ����ݱ䶯��ѯӦ��
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

///���Ļ�Ա�ͻ����ձ䶯��ѯӦ��
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

///ȡ�����Ļ�Ա�ͻ����ձ䶯��ѯӦ��
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

///�����޲����ݱ䶯��ѯӦ��
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

///ȡ�������޲����ݱ䶯��ѯӦ��
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

///���ı�ֵ��ȱ䶯��ѯӦ��
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

///ȡ�����ı�ֵ��ȱ䶯��ѯӦ��
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

///���Ļ�Ա�䶯��ѯӦ��
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

///ȡ�����Ļ�Ա�䶯��ѯӦ��
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

///���ı�֤���ʱ䶯��ѯӦ��
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

///ȡ�����ı�֤���ʱ䶯��ѯӦ��
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

///����IP��ַ�䶯��ѯӦ��
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

///ȡ������IP��ַ�䶯��ѯӦ��
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

///�����޲����ݱ䶯��ѯӦ��
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

///ȡ�������޲����ݱ䶯��ѯӦ��
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

///�����޲����ݱ䶯��ѯӦ��
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

///ȡ�������޲����ݱ䶯��ѯӦ��
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

///������ʷ����״ָ̬���ѯӦ��
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

///ȡ��������ʷ����״ָ̬���ѯӦ��
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

///����ǰ����Ӧ��Ϣ��ѯӦ��
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

///ȡ������ǰ����Ӧ��Ϣ��ѯӦ��
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

///���Ļ�Ա��ʼ��Ӧ��
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

///ȡ�����Ļ�Ա��ʼ��Ӧ��
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

///������ϯ��ʼ��Ӧ��
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

///ȡ��������ϯ��ʼ��Ӧ��
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

///���Ŀͻ���ʼ��Ӧ��
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

///ȡ�����Ŀͻ���ʼ��Ӧ��
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

///���Ľ�����־��ѯӦ��
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

///ȡ�����Ľ�����־��ѯӦ��
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

///���Ľ���ϵͳ��¼��Ϣ
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

///ȡ�����Ľ���ϵͳ��¼��Ϣ
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

///����
BOOL CSysApiDataEntry::SubRtnUpdateSysConfigTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnUpdateSysConfigTopicRegister();
	lstRegister.push_back((void*)this);
	return TRUE;
}

///ȡ������
BOOL CSysApiDataEntry::UnsubRtnUpdateSysConfigTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnUpdateSysConfigTopicRegister();
	lstRegister.remove((void*)this);
	return TRUE;
}

///����
BOOL CSysApiDataEntry::SubRtnSysUser(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnSysUserRegister();
	lstRegister.push_back((void*)this);
	return TRUE;
}

///ȡ������
BOOL CSysApiDataEntry::UnsubRtnSysUser(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnSysUserRegister();
	lstRegister.remove((void*)this);
	return TRUE;
}

///���ļ��ϵͳʱ��ͬ��
BOOL CSysApiDataEntry::SubRtnSysTimeSyncTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnSysTimeSyncTopicRegister();
	lstRegister.push_back((void*)this);
	return TRUE;
}

///ȡ�����ļ��ϵͳʱ��ͬ��
BOOL CSysApiDataEntry::UnsubRtnSysTimeSyncTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnSysTimeSyncTopicRegister();
	lstRegister.remove((void*)this);
	return TRUE;
}

///�������������л�֪ͨ
BOOL CSysApiDataEntry::SubRtnDataCenterChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnDataCenterChgTopicRegister();
	lstRegister.push_back((void*)this);
	return TRUE;
}

///ȡ���������������л�֪ͨ
BOOL CSysApiDataEntry::UnsubRtnDataCenterChgTopic(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnDataCenterChgTopicRegister();
	lstRegister.remove((void*)this);
	return TRUE;
}

///������־�¼�Ӧ��
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

///ȡ��������־�¼�Ӧ��
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

///����WebӦ����Ϣ
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

///ȡ������WebӦ����Ϣ
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

///����Ӧ��servlet��Ϣ
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

///ȡ������Ӧ��servlet��Ϣ
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

///�����ļ���Ϣ
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

///ȡ�������ļ���Ϣ
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

///����Ӧ�ûỰ��Ϣ
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

///ȡ������Ӧ�ûỰ��Ϣ
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

///����JDBC��Ϣ
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

///ȡ������JDBC��Ϣ
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

///�����߳���Ϣ
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

///ȡ�������߳���Ϣ
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

///�����������Ϣ
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

///ȡ�������������Ϣ
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

///����ϵͳ������Ϣ
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

///ȡ������ϵͳ������Ϣ
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

///����ϵͳ�ڴ����Ϣ
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

///ȡ������ϵͳ�ڴ����Ϣ
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

///�����ļ�������Ϣ
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

///ȡ�������ļ�������Ϣ
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

///����������Ϣ
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

///ȡ������������Ϣ
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

///������������Ϣ
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

///ȡ��������������Ϣ
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

///�������ݿ��ѯӦ��
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

///ȡ���������ݿ��ѯӦ��
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

///����ͨ�÷���Ӧ��
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

///ȡ������ͨ�÷���Ӧ��
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

///���ĸ澯������
BOOL CSysApiDataEntry::SubRtnWarningActiveChange(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnWarningActiveChangeRegister();
	lstRegister.push_back((void*)this);
	return TRUE;
}

///ȡ�����ĸ澯������
BOOL CSysApiDataEntry::UnsubRtnWarningActiveChange(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().GetRtnWarningActiveChangeRegister();
	lstRegister.remove((void*)this);
	return TRUE;
}

///����ͨ�ò���
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

///ȡ������ͨ�ò���
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

///���������豸���ӹ�ϵ
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

///ȡ�����������豸���ӹ�ϵ
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

///���Ľ���ϵͳǰ�ñ�����Ӧ��Ϣ
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

///ȡ�����Ľ���ϵͳǰ�ñ�����Ӧ��Ϣ
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

///���Ļ�Աϯλ����״̬
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

///ȡ�����Ļ�Աϯλ����״̬
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

///����ϵͳ·����Ϣ
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

///ȡ������ϵͳ·����Ϣ
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

///���Ĵ���I/O��Ϣ
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

///ȡ�����Ĵ���I/O��Ϣ
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

///����ϵͳ״̬��Ϣ
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

///ȡ������ϵͳ״̬��Ϣ
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

///���Ľ���ϵͳǰ�ñ����ֲ�����
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

///ȡ�����Ľ���ϵͳǰ�ñ����ֲ�����
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

///���Ļ�Ա�ͻ���Ϣ
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

///ȡ�����Ļ�Ա�ͻ���Ϣ
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

///���Ķ����¼�����
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

///ȡ�����Ķ����¼�����
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

///���Ķ���ǰ��ΨһID��Ϣ
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

///ȡ�����Ķ���ǰ��ΨһID��Ϣ
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

///���Ķ��Ļ�Ա��·��ַ�����Ϣ
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

///ȡ�����Ķ��Ļ�Ա��·��ַ�����Ϣ
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

///���Ķ�����ɾ����Ա�б���Ϣ
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

///ȡ�����Ķ�����ɾ����Ա�б���Ϣ
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

///���Ķ���������������
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

///ȡ�����Ķ���������������
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

///���Ķ���Լ״̬�л�����
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

///ȡ�����Ķ���Լ״̬�л�����
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

///���Ķ��ĺ�Լ���׽���Ϣ
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

///ȡ�����Ķ��ĺ�Լ���׽���Ϣ
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

///���������������Ӧ��
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

///ȡ�����������������Ӧ��
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

///������������Ӧ��
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

///ȡ��������������Ӧ��
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

///������������IPӦ��
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

///ȡ��������������IPӦ��
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

///���������豸
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

///ȡ�����������豸
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

///���Ĵ�¥
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

///ȡ�����Ĵ�¥
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

///���Ļ���
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

///ȡ�����Ļ���
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

///���Ļ���
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

///ȡ�����Ļ���
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

///����OID
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

///ȡ������OID
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

///����ʱ�����
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

///ȡ������ʱ�����
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

///���Ĳɼ�����
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

///ȡ�����Ĳɼ�����
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

///�����豸���
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

///ȡ�������豸���
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

///���ĳ����豸�ͺ�
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

///ȡ�����ĳ����豸�ͺ�
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

///���ĳ����豸���
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

///ȡ�����ĳ����豸���
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

///�����豸����
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

///ȡ�������豸����
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

///�����豸��ͬ��
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

///ȡ�������豸��ͬ��
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

///���Ķ˿�����
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

///ȡ�����Ķ˿�����
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

///���Ļ�Ա����ص�
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

///ȡ�����Ļ�Ա����ص�
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

///���Ķ˿�
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

///ȡ�����Ķ˿�
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

///����GeneralOID
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

///ȡ������GeneralOID
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

///���ļ�ض������
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

///ȡ�����ļ�ض������
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

///����ָ��ͳ��
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

///ȡ������ָ��ͳ��
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

///���ļ��ָ���
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

///ȡ�����ļ��ָ���
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

///���ļ�ض���ָ���
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

///ȡ�����ļ�ض���ָ���
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

///�����豸�������
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

///ȡ�������豸�������
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

///����������Ϣ��
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

///ȡ������������Ϣ��
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

///������������
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

///ȡ��������������
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

///�����������
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

///ȡ�������������
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

///���Ļ�Ա��·��Ϣ��
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

///ȡ�����Ļ�Ա��·��Ϣ��
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

///����ģ��
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

///ȡ������ģ��
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

///����������״̬��
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

///ȡ������������״̬��
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

///�����豸���ñ�
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

///ȡ�������豸���ñ�
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

///�������������������
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

///ȡ���������������������
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

///�����ļ�ͨ�ò���
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

///ȡ�������ļ�ͨ�ò���
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

///���Ļ��߱�
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

///ȡ�����Ļ��߱�
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

///���Ļ��߽����
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

///ȡ�����Ļ��߽����
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

///���Ļ�Ա��·״̬��Ϣ��
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

///ȡ�����Ļ�Ա��·״̬��Ϣ��
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

///���ı���ping���
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

///ȡ�����ı���ping���
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

///����Զ��ping���
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

///ȡ������Զ��ping���
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

///���Ķ��Ļ�Ա��·���ñ�
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

///ȡ�����Ķ��Ļ�Ա��·���ñ�
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

///���Ķ��ķǻ�Ա��·����Ϣ
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

///ȡ�����Ķ��ķǻ�Ա��·����Ϣ
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

