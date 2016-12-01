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
!!if !strncmp(@name,"Rtn",3) && strncmp(@name,"RtnSyslogEvent",14)!!
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

#include "StdAfx.h"
#include "UserApiHandler.h"

extern list<EventSubInfo> g_EventSubList;

!!enter FTD!!
////////////////////////////////////////////////////////////////////////////////////////////////
// CUserApiHandlerWnd
LRESULT CUserApiHandlerWnd::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_USERAPI_DATAREACH)
	{
		ASSERT(m_pApiHandler);
		LPUSERAPIDATAPACKINFO pPackInfo = (LPUSERAPIDATAPACKINFO)wParam;
		ASSERT(pPackInfo);
		
		switch(pPackInfo->nTag)
		{
!!travel packages!!
!!if InUse(@name) && !strncmp(@name,"Rsp",3)!!
		case TAG_USERAPI_!!show_string strupr(strdup(@name))!! : 		///!!@comment
			{
				CRequestQueue &Queue = m_pApiHandler->GetRequestQueue();
				CRequestInfo *pReq = Queue[pPackInfo->nRequestID];
				if (pReq)
				{
					CSysApiDataEntry* pDataEntry = static_cast<CSysApiDataEntry*>(pReq->GetSender());
					int nRequestID = pReq->GetRelativeReqID();
					if (pPackInfo->bIsLast) Queue.Remove(pReq);
					pDataEntry->On!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!(CShfeFtdc!!@name!!Field*)pPackInfo->pData!!@pumpid!!!!next!!, nRequestID, pPackInfo->bIsLast);
				}
			}
			break;
			
!!endif!!
!!next!!

!!travel packages!!
!!if InUse(@name) && !strncmp(@name,"Rtn",3)!!
!!if !strcmp(@name, "RtnHostEnvTopic")!!

!!else!!
!!if InUse1(@name) || InUse2(@name)!!
		case TAG_USERAPI_!!show_string strupr(strdup(@name))!! : 		///!!@comment
		{
			!!travel self!!
			!!if @pumpid==0!!
			!!let firstchildname=@name!!
			!!endif!!
			!!next!!
			hash_map<string, list<void*>> &mapRegister = m_pApiHandler->Get!!@name!!Register();
			hash_map<string, list<void*>>::const_iterator map_iter;
			CShfeFtdc!!@firstchildname!!Field *pField = (CShfeFtdc!!@firstchildname!!Field*)pPackInfo->pData0;
			!!if InUse1(@name)!!
			!!if !strcmp(@name, "RtnSyslogInfoTopic") ||!strcmp(@name, "RtnDBQueryTopic") ||!strcmp(@name, "RtnObjectAttrTopic") ||!strcmp(@name, "RtnNetObjectAttrTopic")!!
			string str =pField->ObjectID;
			str +=".";
			str +=pField->AttrType;
			map_iter = mapRegister.find(str);
			!!else!!
			map_iter = mapRegister.find(pField->ObjectID);
			!!endif!!
			!!else!!
			!!if !strcmp(@name, "RtnNetworkInfoTopic")!!
			string str =pField->HostName;
			map_iter = mapRegister.find(str);
			!!else!!
			map_iter = mapRegister.find(pField->HostName);
			!!endif!!
			!!endif!!
			if (map_iter != mapRegister.end())
			{
				list<void*>::const_iterator list_iter = map_iter->second.begin();
				while (list_iter != map_iter->second.end())
				{
					static_cast<CSysApiDataEntry*>(*list_iter)->On!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!(CShfeFtdc!!@name!!Field*)pPackInfo->pData!!@pumpid!!!!next!!);
					list_iter++;
				}
			}
		}
		break;
		
!!elseif InUse3(@name) || InUse4(@name) || InUse5(@name)!!
		case TAG_USERAPI_!!show_string strupr(strdup(@name))!! : 		///!!@comment
		{
				list<void*> &reg = m_pApiHandler->Get!!@name!!Register();
				list<void*>::const_iterator iter = reg.begin();
				while(iter != reg.end())
				{
					CSysApiDataEntry *pDataEntry = static_cast<CSysApiDataEntry*>(*iter);
					pDataEntry->On!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!(CShfeFtdc!!@name!!Field*)pPackInfo->pData!!@pumpid!!!!next!!);
					iter++;
				}
		}
		break;
		
!!endif!!
!!endif!!
!!endif!!
!!next!!
		case TAG_USERAPI_RTNSYSLOGEVENTTOPIC:
			{
				list<EventSubInfo>::iterator it =g_EventSubList.begin();
				for(; it !=g_EventSubList.end() ;it++)
				{
					CShfeFtdcRtnSyslogEventField *pField =(CShfeFtdcRtnSyslogEventField *)(pPackInfo->pData0);
					if(((!strcmp(pField->ObjectID ,(*it).ObjectID))||(!strcmp((*it).ObjectID ,""))) && ((!strcmp(pField->EventName ,(*it).EventName))||(!strcmp((*it).EventName ,""))) && ((!strcmp(pField->ProcessFlag ,(*it).ProcessFlag))||(!strcmp((*it).ProcessFlag,""))) &&((!strcmp(pField->WarningLevel ,(*it).WarningLevel))||(!strcmp((*it).WarningLevel ,""))))
					{
						string str =pField->EventDes;
						if(strcmp((*it).filter ,""))
						{
							string str1 =(*it).filter;
							list<string> theList;
							int  index1 =0;
							int index2 =str1.find(";");
							if(index2 ==string::npos)
								theList.push_back(str1.substr(index1 ,str1.size()));
							while (index2 !=string::npos)
							{
								theList.push_back(str1.substr(index1 ,index2 -index1));
								index1 =index2 +1;
								index2 =str1.find(";" ,index1);
								if(index2 ==string::npos)
									theList.push_back(str1.substr(index1 ,str1.size()));
							}
							list<string>::iterator itList =theList.begin();
							for( ;itList!=theList.end() ;itList++)
							{
								int iv = str.find(*itList);
								if(iv ==string::npos)
									break;
							}
							if(itList!=theList.end())
								continue;
						}
						if(strcmp((*it).antifilter ,""))
						{
							string str1 =(*it).antifilter;
							list<string> theList;
							int  index1 =0;
							int index2 =str1.find(";");
							if(index2 ==string::npos)
								theList.push_back(str1.substr(index1 ,str1.size()));
							while (index2 !=string::npos)
							{
								theList.push_back(str1.substr(index1 ,index2 -index1));
								index1 =index2 +1;
								index2 =str1.find(";" ,index1);
								if(index2 ==string::npos)
									theList.push_back(str1.substr(index1 ,str1.size()));
							}
							list<string>::iterator itList =theList.begin();
							for( ;itList !=theList.end() ;itList ++)
							{
								int iv = str.find(*itList);
								if(iv !=string::npos)
									break;
							}
							if(itList !=theList.end())
								continue;
						}
						list<void *> &theList =(*it).Receiver;
						list<void *>::iterator itList =theList.begin();
						for(; itList !=theList.end() ;itList ++)
						{
							CSysApiDataEntry *pDataEntry = static_cast<CSysApiDataEntry*>(*itList);
							pDataEntry->OnRtnSyslogEventTopic((CShfeFtdcRtnSyslogEventField*)(pPackInfo->pData0));
						}
					}
				}
			}
			break;	
		default :
			break;
		}
		return 0;
	}
	else if (message == WM_USERAPI_ONCONNECT)
	{
		CList<LPVOID> &reg = m_pApiHandler->GetConnectionStateRegister();
		POSITION pos = reg.GetHeadPosition();
		while(pos)
		{
			CSysApiDataEntry* pDataEntry = (CSysApiDataEntry*)reg.GetNext(pos);
			pDataEntry->OnFrontConnected();
		}
		return 0;
	}
	else if (message == WM_USERAPI_ONDISCONNECT)
	{
		CList<LPVOID> &reg = m_pApiHandler->GetConnectionStateRegister();
		POSITION pos = reg.GetHeadPosition();
		while(pos)
		{
			CSysApiDataEntry* pDataEntry = (CSysApiDataEntry*)reg.GetNext(pos);
			pDataEntry->OnFrontDisconnected(wParam);
		}
		return 0;
	}
	
	return CWnd::WindowProc(message, wParam, lParam);
}

////////////////////////////////////////////////////////////////////////////////////////////////
// CUserApiHandler
CUserApiHandler::CUserApiHandler(void) : m_wndHandler(this)
{
}

CUserApiHandler::~CUserApiHandler(void)
{
	Release();
}

void CUserApiHandler::Create(void)
{
	if (!m_wndHandler.GetSafeHwnd())
	{
		m_wndHandler.CreateEx(
			WS_EX_TOPMOST | WS_EX_TOOLWINDOW, 
			AfxRegisterWndClass(NULL),
			NULL, 
			WS_POPUP, 
			CRect(0, 0, 0, 0), 
			NULL, 
			NULL);
		ASSERT(m_wndHandler.GetSafeHwnd());
	}

	if (!m_pUserApi)
	{
		m_pUserApi = CShfeFtdcSysUserApi::CreateFtdcSysUserApi();
		VERIFY(m_pUserApi);
		m_pUserApi->RegisterSpi(this);
	}
}

void CUserApiHandler::Release(void)
{
	if (m_wndHandler.GetSafeHwnd())
	{
		m_wndHandler.DestroyWindow();
	}
	
	if (m_pUserApi)
	{
		m_pUserApi->RegisterSpi(NULL);
		m_pUserApi->Release();
		m_pUserApi = NULL;
	}
}

void CUserApiHandler::Clear(void)
{
	m_RequestQueue.RemoveAll();
	m_mapObjectSubCounter.RemoveAll();
!!travel packages!!
	!!if InUse1(@name) || InUse2(@name)!!
	m_!!@name!!Register.clear();
	!!elseif InUse3(@name) || InUse4(@name) || InUse5(@name)!!
	m_!!@name!!Register.clear();
	!!endif!!
!!next!!
}

void CUserApiHandler::Reset(void)
{
	Clear();
	Release();
	Create();
}

CRequestQueue& CUserApiHandler::GetRequestQueue(void)
{
	return m_RequestQueue;
}

CShfeFtdcSysUserApi* CUserApiHandler::GetUserApi(void)
{
	return m_pUserApi;
}

void CUserApiHandler::OnFrontConnected()
{
	m_wndHandler.SendMessage(WM_USERAPI_ONCONNECT, NULL, NULL);
}

void CUserApiHandler::OnFrontDisconnected(int nReason)
{
	m_wndHandler.SendMessage(WM_USERAPI_ONDISCONNECT, (WPARAM)nReason, NULL);
}

!!travel packages!!
!!if InUse(@name) && !strncmp(@name,"Rsp",3)!!
///!!@comment
void CUserApiHandler::On!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!CShfeFtdc!!@name!!Field *p!!@name!!!!next!!, int nRequestID, bool bIsLast)
{
	USERAPIDATAPACKINFO packinfo = {
		TAG_USERAPI_!!show_string strupr(strdup(@name))!!, 
		nRequestID, 
		bIsLast, 
		!!travel self!!!!if @pumpid!=0!!, !!endif!!(LPVOID)p!!@name!!!!next!! };
	m_wndHandler.SendMessage(WM_USERAPI_DATAREACH, (WPARAM)(LPVOID)(&packinfo), 0);
}

!!endif!!
!!next!!


!!travel packages!!
!!if InUse(@name) && !strncmp(@name,"Rtn",3)!!
///!!@comment
void CUserApiHandler::On!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!CShfeFtdc!!@name!!Field *p!!@name!!!!next!!)
{
	USERAPIDATAPACKINFO packinfo = {
		TAG_USERAPI_!!show_string strupr(strdup(@name))!!, 
		0, 
		FALSE, 
		!!travel self!!!!if @pumpid!=0!!, !!endif!!(LPVOID)p!!@name!!!!next!! };
	m_wndHandler.SendMessage(WM_USERAPI_DATAREACH, (WPARAM)(LPVOID)(&packinfo), 0);
}

!!endif!!
!!next!!

!!leave!!