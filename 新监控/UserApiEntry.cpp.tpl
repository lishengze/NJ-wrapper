!!function!!
#include <set>
using namespace std;

struct ltstr
{
	bool operator()(const char* s1, const char* s2) const
	{
		return strcmp(s1, s2) < 0;
	}
};

typedef set<char *, ltstr> CPackageSet;
CPackageSet g_setUsePackage;
CPackageSet g_Package1;
CPackageSet g_Package2;
CPackageSet g_Package3;
CPackageSet g_Package4;
CPackageSet g_Package5;

bool InUse(char *name)
{
	return (g_setUsePackage.find(name)!=g_setUsePackage.end());
}

bool InUse1(char *name)
{
	return (g_Package1.find(name)!=g_Package1.end());
}

bool InUse2(char *name)
{
	return (g_Package2.find(name)!=g_Package2.end());
}

bool InUse3(char *name)
{
	return (g_Package3.find(name)!=g_Package3.end());
}

bool InUse4(char *name)
{
	return (g_Package4.find(name)!=g_Package4.end());
}

bool InUse5(char *name)
{
	return (g_Package5.find(name)!=g_Package5.end());
}

!!endfunction!!

!!enter sysuserapi!!
!!travel self!!	
!!command g_setUsePackage.insert(@name);!!
!!if !strncmp(@name,"Rtn",3)!!
!!if !strcmp(@sysTag,"1")!!
	!!command g_Package1.insert(@name);!!
!!elseif !strcmp(@sysTag,"2")!!
	!!command g_Package2.insert(@name);!!
!!elseif !strcmp(@sysTag,"3")!!
	!!command g_Package3.insert(@name);!!
!!elseif !strcmp(@sysTag,"4")!!
	!!command g_Package4.insert(@name);!!
!!elseif !strcmp(@sysTag,"5")!!
	!!command g_Package5.insert(@name);!!
!!endif!!
!!endif!!
!!next!!
!!leave!!

!!enter FTD!!
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
	
!!travel packages!!
!!if InUse1(@name) || InUse2(@name)!!
	///清除!!@comment!!订阅表中与之相关的订阅记录
	{
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().Get!!@name!!Register();
		hash_map<string, list<void*>>::iterator &map_iter = mapRetgister.begin();
		while (map_iter != mapRetgister.end())
		{
			list<void*> &lstSender = map_iter->second;
			lstSender.remove((void*)this);
			map_iter++;
		}
	}
	
!!elseif InUse3(@name) || InUse4(@name) ||  InUse5(@name)!!
	///清除!!@comment!!订阅表中与之相关的订阅记录
	dispatcher.GetUserApiHandler().Get!!@name!!Register().remove((void*)this);
!!endif!!
!!next!!
}


!!travel packages!!
!!if InUse(@name) && !strncmp(@name,"Req",3) && strcmp(@name,"ReqQrySyslogEventSubcriberTopic")!!
///!!@comment
BOOL CSysApiDataEntry::!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!CShfeFtdc!!@name!!Field *p!!@name!!!!next!!, int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	CRequestQueue &Queue = dispatcher.GetUserApiHandler().GetRequestQueue();

	int nRet = dispatcher.GetUserApiHandler().GetUserApi()->!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!p!!@name!!!!next!!, ++Queue);
	if (nRet == 0) Queue.Add(new CRequestInfo(this, (INT)Queue, nRequestID));
	
	return (nRet == 0);
}

!!endif!!
!!next!!

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

!!travel packages!!
!!if InUse1(@name) || InUse2(@name)!!
///订阅!!@comment
BOOL CSysApiDataEntry::Sub!!@name!!(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum , TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
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
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().Get!!@name!!Register();
		mapRetgister[str].push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅!!@comment
BOOL CSysApiDataEntry::Unsub!!@name!!(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
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
		hash_map<string, list<void*>> &mapRetgister = dispatcher.GetUserApiHandler().Get!!@name!!Register();
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

!!elseif InUse3(@name)!!
///订阅!!@comment
BOOL CSysApiDataEntry::Sub!!@name!!(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().Get!!@name!!Register();
	lstRegister.push_back((void*)this);
	return TRUE;
}

///取消订阅!!@comment
BOOL CSysApiDataEntry::Unsub!!@name!!(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
	list<void*> &lstRegister = dispatcher.GetUserApiHandler().Get!!@name!!Register();
	lstRegister.remove((void*)this);
	return TRUE;
}

!!elseif InUse4(@name)!!
///订阅!!@comment
BOOL CSysApiDataEntry::Sub!!@name!!(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID)
{
	if (SubscriberTopic(ObjectID, subObjectID, nObjectNum,startDate ,startTime ,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().Get!!@name!!Register();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅!!@comment
BOOL CSysApiDataEntry::Unsub!!@name!!(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID)
{
	if (UnsubscriberTopic(ObjectID, subObjectID,nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().Get!!@name!!Register();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

!!elseif InUse5(@name)!!
///订阅!!@comment
BOOL CSysApiDataEntry::Sub!!@name!!(QWORD ObjectID, QWORD subObjectID, int nRequestID)
{
	CShfeFtdcReqSubscribeField field = {0};
	field.ObjectID = ObjectID;
	field.AttrType = subObjectID;
	if (ReqSubscribe(&field, nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().Get!!@name!!Register();
		lstRegister.push_back((void*)this);
		return TRUE;
	}
	else return FALSE;
}

///取消订阅!!@comment
BOOL CSysApiDataEntry::Unsub!!@name!!(QWORD ObjectID, QWORD subObjectID, int nRequestID)
{
	CShfeFtdcReqSubscribeField field = {0};
	field.ObjectID = ObjectID;
	field.AttrType = subObjectID;
	if (ReqCancelSubscribe(&field, nRequestID))
	{
		CDataDispatcher &dispatcher = static_cast<CDataDispatcher&>(theApp.GetDataDispatcher());
		list<void*> &lstRegister = dispatcher.GetUserApiHandler().Get!!@name!!Register();
		lstRegister.remove((void*)this);
		return TRUE;
	}
	else return FALSE;
}

!!endif!!
!!next!!

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

!!leave!!