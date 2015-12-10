#ifndef __DATAUTILS_H__
#define __DATAUTILS_H__

#pragma once

#include "..\interface\AppInterface.h"
#include <list>
using namespace std;

#define LINK_UPDOWN			_T("LINK_UPDOWN")
#define LINKADMIN_UPDOWN	_T("LINKADMIN_UPDOWN")
#define LINEPROTO_UPDOWN	_T("LINEPROTO_UPDOWN")
struct EventSubInfo 
{
	///�����¼��Ķ���IDָ��
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�¼���
	TShfeFtdcTypeObjectIDType	EventName;
	///���漶��
	TShfeFtdcTypeWarningLevelType	WarningLevel;

	///��������
	TShfeFtdcTypeSubcriberObjectIDType	filter;
	///������
	TShfeFtdcTypeSubcriberObjectIDType	antifilter;
	TShfeFtdcTypeProcessFlagType	ProcessFlag;

	list<void *>			Receiver;
};

class CLinkStatusNotification
{
public:
	virtual void NotifyMemberLinkChanged()=0;
};

class CMemberLinkData
{
public:
	CMemberLinkData(): m_nPortLinkStatus(0),
					   m_nPortProtoStatus(0),
					   m_nPortLinkStatusReal(0),
					   m_nPortProtoStatusReal(0)
	{}
	CString m_strID;
	CString m_strMemberName;
	CString m_strMemberNumber;
	CString m_strRemoteAddress;
	CString m_strLocalAddress;
	CString m_strAddress;
	CString m_strLineStatus;
	CString m_strConnect;
	CString m_strTelephone;
	CString m_strCellphone;
	CString m_strEmail;
	CString	m_strFax;
	CString m_strProvince;
	CString m_strLineNumber;
	CString m_strConnectWay;
	CString m_strWAN;
	CString m_strLAN;
	CString m_strIPAddress;
	CString m_strPortNumber;
	CString m_strOpenDate;
	CString m_strSoftware;
	CString m_strFeeType;
	CString m_strServicePro;
	CString m_strIfZiYing;
	CString m_strIfTuoGuan;
	CString m_strSeatNumber;
	CString m_strHasOtherLine;
	CString m_strPro;

	CString m_strDevicePort;
	CString m_strEventTime;
	
	int  GetPortStatus()
	{
		if (m_nPortLinkStatus<0 || m_nPortLinkStatus>2)	return 0;
		if (m_nPortProtoStatus<0 || m_nPortProtoStatus>1)	return 0;
		
		if (0==m_nPortLinkStatus && 0==m_nPortProtoStatus)
		{
			return 0;
		}
		else if (2==m_nPortLinkStatus)
		{
			return 3;
		}
		else if (0==m_nPortLinkStatus && 1==m_nPortProtoStatus)
		{
			return 1;
		}
		else if (1==m_nPortLinkStatus && 1==m_nPortProtoStatus)
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}
	
	int GetPortStatusInProcess()
	{
		if (m_nPortLinkStatusReal<0 || m_nPortLinkStatusReal>2)	return 0;
		if (m_nPortProtoStatusReal<0 || m_nPortProtoStatusReal>1)	return 0;

		if (0==m_nPortLinkStatusReal && 0==m_nPortProtoStatusReal)
		{
			return 0;
		}
		else if (2==m_nPortLinkStatusReal)
		{
			return 3;
		}
		else if (0==m_nPortLinkStatusReal && 1==m_nPortProtoStatusReal)
		{
			return 1;
		}
		else if (1==m_nPortLinkStatusReal && 1==m_nPortProtoStatusReal)
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}
	
	int  GetMaxWarningLevel()
	{
		int nMaxWarningLevel(1);
		map<int, int>::iterator iterEventLevel;
		for (iterEventLevel=m_mapEventNumLevel.begin(); iterEventLevel!=m_mapEventNumLevel.end(); ++iterEventLevel)
		{
			if (iterEventLevel->second>nMaxWarningLevel)
			{
				nMaxWarningLevel=iterEventLevel->second;
			}
		}
		
		return nMaxWarningLevel;
	}
	void SetPortStatus(int nPortStatus)
	{
		//if (m_strIPAddress==_T("172.1.1.46"))
		//{
		//	if (m_strPortNumber==_T("Serial4/0_1/2/1/2:0"))
		//	{
		//		int a=0; 

		//		a =100;
		//	}
		//}
		if (nPortStatus<0 || nPortStatus>3)	return;
		// up-up status
		if (0==nPortStatus)
		{
			m_nPortLinkStatus = 0;
			m_nPortProtoStatus = 0;
			
			m_nPortLinkStatusReal = 0;
			m_nPortProtoStatusReal = 0;
		}
		// up-down status
		else if (1==nPortStatus)
		{
			m_nPortLinkStatus = 0;
			m_nPortProtoStatus = 1;
			
			m_nPortLinkStatusReal = 0;
			m_nPortProtoStatusReal = 1;
		}
		// down-down status
		else if (2==nPortStatus)
		{
			m_nPortLinkStatus = 1;
			m_nPortProtoStatus = 1;
			
			m_nPortLinkStatusReal = 1;
			m_nPortProtoStatusReal = 1;
		}
		// admin-down status
		else if (3==nPortStatus)
		{
			m_nPortLinkStatus = 2;
			m_nPortProtoStatus = 1;
			
			m_nPortLinkStatusReal = 2;
			m_nPortProtoStatusReal = 1;
		}
		else
		{
			return;
		}
	}
	void AddNewWarningEvent(const CString& strEventName, const CString& strProcessFlag, int nEventNum, int nWarningLevel, CString strEventDescribe=_T(""))
	{
		//if (m_strIPAddress==_T("172.1.1.46"))
		//{
		//	if (m_strPortNumber==_T("Serial4/0_1/2/1/2:0"))
		//	{
		//		int a;
		//		a = 1000;
		//	}
		//}
		if (_T("Y")==strProcessFlag || _T("=")==strProcessFlag)
		{
			map<int, int>::iterator iterEventLevel(m_mapEventNumLevel.find(nEventNum));
			if (iterEventLevel!=m_mapEventNumLevel.end())
			{
				if (LINK_UPDOWN==strEventName)
				{
					m_nPortLinkStatus = 0;
				}
				else if (LINKADMIN_UPDOWN==strEventName)
				{
					m_nPortLinkStatus = 0;
				}
				else if (LINEPROTO_UPDOWN==strEventName)
				{
					m_nPortProtoStatus = 0;
				}
				else
				{
					// TODO:bian.xb@sift.com.cn
				}
				m_mapEventNumLevel.erase(iterEventLevel);
			}
			// ʵ��up����
			if (-1!=strEventDescribe.Find(_T("up")))
			{
				if (LINK_UPDOWN==strEventName)
				{
					m_nPortLinkStatusReal = 0;
				}
				else if (LINKADMIN_UPDOWN==strEventName)
				{
					m_nPortLinkStatusReal = 0;
				}
				else if (LINEPROTO_UPDOWN==strEventName)
				{
					m_nPortProtoStatusReal = 0;
				}
				else
				{
					// TODO:bian.xb@sift.com.cn
				}
			}
			else
			{
				if (LINK_UPDOWN==strEventName)
				{
					m_nPortLinkStatusReal = 1;
				}
				else if (LINKADMIN_UPDOWN==strEventName)
				{
					m_nPortLinkStatusReal = 2;
				}
				else if (LINEPROTO_UPDOWN==strEventName)
				{
					m_nPortProtoStatusReal = 1;
				}
				else
				{
					// TODO:bian.xb@sift.com.cn
				}
			}
		}
		else
		{
			map<int, int>::iterator iterEventLevel(m_mapEventNumLevel.find(nEventNum));
			if (iterEventLevel == m_mapEventNumLevel.end())
			{
				if (LINK_UPDOWN==strEventName)
				{
					m_nPortLinkStatus = 1;
				}
				else if (LINKADMIN_UPDOWN==strEventName)
				{
					m_nPortLinkStatus = 2;
				}
				else if (LINEPROTO_UPDOWN==strEventName)
				{
					m_nPortProtoStatus = 1;
				}
				else
				{
					// TODO:bian.xb@sift.com.cn
				}
				m_mapEventNumLevel.insert(make_pair(nEventNum, nWarningLevel));
			}
			// ʵ��down��
			if (-1!=strEventDescribe.Find(_T("down")))
			{
				if (LINK_UPDOWN==strEventName)
				{
					m_nPortLinkStatusReal = 1;
				}
				else if (LINKADMIN_UPDOWN==strEventName)
				{
					m_nPortLinkStatusReal = 2;
				}
				else if (LINEPROTO_UPDOWN==strEventName)
				{
					m_nPortProtoStatusReal = 1;
				}
				else
				{
					// TODO:bian.xb@sift.com.cn
				}
			}
			else
			{
				if (LINK_UPDOWN==strEventName)
				{
					m_nPortLinkStatusReal = 0;
				}
				else if (LINKADMIN_UPDOWN==strEventName)
				{
					m_nPortLinkStatusReal = 0;
				}
				else if (LINEPROTO_UPDOWN==strEventName)
				{
					m_nPortProtoStatusReal = 0;
				}
				else
				{
					// TODO:bian.xb@sift.com.cn
				}
			}
		}
	}
	void AddSyslogEvent(const CString& strEventName, const CString& strProcessFlag, int nEventNum, int nWarningLevel, CString strEventDescribe=_T(""))
	{
		if (m_strIPAddress==_T("172.1.1.46"))
		{
			if (m_strPortNumber==_T("Serial4/0_1/2/1/2:0"))
			{
				int a;
				a = 1000;
			}
		}
		if (-1!=strEventDescribe.Find(_T("down")))
		{
			if (LINK_UPDOWN==strEventName)
			{
				m_nPortLinkStatusReal = 1;
			}
			else if (LINKADMIN_UPDOWN==strEventName)
			{
				m_nPortLinkStatusReal = 2;
			}
			else if (LINEPROTO_UPDOWN==strEventName)
			{
				m_nPortProtoStatusReal = 1;
			}
			else
			{
				// TODO:bian.xb@sift.com.cn
			}
		}
		else if (-1!=strEventDescribe.Find(_T("up")))
		{
			if (LINK_UPDOWN==strEventName)
			{
				m_nPortLinkStatusReal = 0;
			}
			else if (LINKADMIN_UPDOWN==strEventName)
			{
				m_nPortLinkStatusReal = 0;
			}
			else if (LINEPROTO_UPDOWN==strEventName)
			{
				m_nPortProtoStatusReal = 0;
			}
			else
			{
				// TODO:bian.xb@sift.com.cn
			}
		}
	}
	
	void RegisterLinkStatus(CLinkStatusNotification* pLinkInfoNotify)
	{
		m_vecLinkInfoNotify.push_back(pLinkInfoNotify);
	}
	
	void AddLinkRealStatus(COleDateTime timeEvent, int nPortStatus)
	{
		m_mapLinkRealStatus.insert(make_pair(timeEvent, nPortStatus));
		NotifyLinkStatusChange();
	}
	
	void AddLinkVirtualStatus(COleDateTime timeEvent, int nPortStatus)
	{
		m_mapLinkVirtualStatus.insert(make_pair(timeEvent, nPortStatus));
	}
	
	map<COleDateTime, int>& GetRealStatusStream(){return m_mapLinkRealStatus;}
	
	map<COleDateTime, int>& GetVirtualStatusStream(){return m_mapLinkVirtualStatus;}
	
	void NotifyLinkStatusChange()
	{
		vector<CLinkStatusNotification*>::iterator iterNotification;
		for (iterNotification=m_vecLinkInfoNotify.begin(); iterNotification!=m_vecLinkInfoNotify.end(); ++iterNotification)
		{
			(*iterNotification)->NotifyMemberLinkChanged();
		}
	}
	
	int GetRealTimeRealStatus(int& nStatus, CString& strLstChgTime)
	{
		nStatus = -1;
		strLstChgTime.Empty();
		if (m_mapLinkRealStatus.size()<=0)
		{
			return -1;
		}
		else
		{
			map<COleDateTime, int>::reverse_iterator rIter(m_mapLinkRealStatus.rbegin());
			nStatus = rIter->second;
			strLstChgTime.Format(_T("%04d%02d%02d %02d:%02d:%02d"), rIter->first.GetYear(),rIter->first.GetMonth(),rIter->first.GetDay(),rIter->first.GetHour(),rIter->first.GetMinute(),rIter->first.GetSecond());
			return rIter->second;
		}
	}
	
	int GetRealTimeRealStatus()
	{
		if (m_mapLinkRealStatus.size()<=0)
		{
			return -1;
		}
		else
		{
			map<COleDateTime, int>::reverse_iterator rIter(m_mapLinkRealStatus.rbegin());
			return rIter->second;
		}
	}
	
	CString GetRealTimeRealChangeTime()
	{
		CString strDateTime(_T(""));
		if (m_mapLinkRealStatus.size()<=0)
		{
			return strDateTime;
		}
		else
		{
			map<COleDateTime, int>::reverse_iterator rIter(m_mapLinkRealStatus.rbegin());
			strDateTime.Format(_T("%04d%02d%02d %02d:%02d:%02d"), rIter->first.GetYear(),rIter->first.GetMonth(),rIter->first.GetDay(),rIter->first.GetHour(),rIter->first.GetMinute(),rIter->first.GetSecond());
			return strDateTime;
		}
	}
	
	int GetRealTimeVirtualStatus()
	{
		if (m_mapLinkVirtualStatus.size()<=0)
		{
			return -1;
		}
		else
		{
			map<COleDateTime, int>::reverse_iterator rIter(m_mapLinkVirtualStatus.rbegin());
			return rIter->second;
		}
	}
	// ��ѯ��ֹ��ĳ��ʱ�����·״̬
	int QryRealTimeRealRangeStatus(COleDateTime& timeStart, COleDateTime& timeEnd, int& nLinkStatus, CString& strLastChgTime)
	{
		int nStatus(-1);
		strLastChgTime.Empty();
		map<COleDateTime, int>::iterator iterRecord;
		for (iterRecord=m_mapLinkRealStatus.begin(); iterRecord!=m_mapLinkRealStatus.end(); ++iterRecord)
		{
			if (PrecociousTime(iterRecord->first, timeEnd))
			{
				nStatus = iterRecord->second;
				strLastChgTime.Format(_T("%04d%02d%02d %02d:%02d:%02d"), iterRecord->first.GetYear(),iterRecord->first.GetMonth(),
									  iterRecord->first.GetDay(),iterRecord->first.GetHour(),iterRecord->first.GetMinute(),iterRecord->first.GetSecond());
			}
			else
			{
				break;
			}
		}
		return nStatus;
	}
	BOOL PrecociousTime(COleDateTime timeLeft, COleDateTime& timeRight)
	{
		int nLeftHour(timeLeft.GetHour());
		int nLeftMin(timeLeft.GetMinute());
		int nLeftSec(timeLeft.GetSecond());

		int nRightHour(timeRight.GetHour());
		int nRightMin(timeRight.GetMinute());
		int nRightSec(timeRight.GetSecond());
		if (nLeftHour==nRightHour&&nLeftMin==nRightMin&&nLeftSec==nRightSec)
		{
			return TRUE;
		}
		else
		{
			return ((nLeftHour>nRightHour) || (nLeftHour==nRightHour&&nLeftMin>nRightMin) || (nLeftHour==nRightHour&&nLeftMin==nRightMin&&nLeftSec>nRightSec));
		}
	}
private:
	// �˿�״̬��ʾ�˿ڵ���״̬����link״̬��proto״̬��������
	int		m_nPortLinkStatus;
	int		m_nPortProtoStatus;
	
	// EventNum �� WarningLevel���ձ�
	map<int, int> m_mapEventNumLevel;
	
	
	// ��ʵ�˿�״̬�����¼��޹�
	int		m_nPortLinkStatusReal;
	int		m_nPortProtoStatusReal;
	
	map<int, int> m_mapEventNumLevelReal;
	
	vector<CLinkStatusNotification*>	m_vecLinkInfoNotify;
	
	map<COleDateTime, int>	m_mapLinkRealStatus;
	map<COleDateTime, int>  m_mapLinkVirtualStatus;
};

struct TNetDeviceInfo {
	//�豸id
	int			deviceID;
	//����id
	int			subNetID;

	//�������
	int			nFactoryID;
	
	//�豸���
	int			nDevCate;
	int			nIPDecode;
	
	CString		objID;
	//�豸����
	CString		objName;
	CString		ipAddr;
	//������������
	CString		subArea;
	///�豸�ͺ�
	CString     deviceType;
};

///////////////////////////////////////////////////////////////////////////////////////////////
// ����������Ϣ
class CHostEnvProperty : public IHostEnvProperty
{
public:
	CHostEnvProperty(void);
	~CHostEnvProperty(void);

public:
	///��ȡ������Ҫ������Ϣ
	const CShfeFtdcRspQryHostEnvCommonField& GetHostEnvCommon(void);

	///��ȡ����������Ϣ
	CArray<CShfeFtdcRspQryHostEnvLanField>& GetHostEnvLan(void);

	///��ȡ�����洢�豸��Ϣ
	CArray<CShfeFtdcRspQryHostEnvStorageField>& GetHostEnvStorage(void);

	///��ȡ����IO�豸��Ϣ
	CArray<CShfeFtdcRspQryHostEnvIOField>& GetHostEnvIO(void);

	///��ȡ�����ļ�ϵͳ��Ϣ
	CArray<CShfeFtdcRspQryHostEnvFSField>& GetHostEnvFS(void);

	///��ȡ��������������Ϣ
	CArray<CShfeFtdcRspQryHostEnvSwapField>& GetHostEnvSwap(void);

	///��ȡ��������������Ϣ
	CArray<CShfeFtdcRspQryHostEnvLanCfgField>& GetHostEnvLanCfg(void);

public:
	void SetHostEnvCommon(const CShfeFtdcRspQryHostEnvCommonField& field);

private:
	///������Ҫ������Ϣ
	CShfeFtdcRspQryHostEnvCommonField m_HostEnvCommon;

	///����������Ϣ
	CArray<CShfeFtdcRspQryHostEnvLanField> m_HostEnvLanList;

	///�����洢�豸��Ϣ
	CArray<CShfeFtdcRspQryHostEnvStorageField> m_HostEnvStorageList;

	///����IO�豸��Ϣ
	CArray<CShfeFtdcRspQryHostEnvIOField> m_HostEnvIOList;

	///�����ļ�ϵͳ��Ϣ
	CArray<CShfeFtdcRspQryHostEnvFSField> m_HostEnvFSList;

	///��������������Ϣ
	CArray<CShfeFtdcRspQryHostEnvSwapField> m_HostEnvSwapList;

	///��������������Ϣ
	CArray<CShfeFtdcRspQryHostEnvLanCfgField> m_HostEnvLanCfgList;
};

///////////////////////////////////////////////////////////////////////////////////////////////
// CMonitorObject
class CMonitorObject : public IMonitorObject
{
	DECLARE_DYNCREATE(CMonitorObject)
public:
	CMonitorObject(void);
	CMonitorObject(LPCTSTR lpszObjectID, LPCTSTR lpszObjectName,LPCTSTR lpszKeyword = NULL, IMonitorObjectProperty *pProperty = NULL, IMonitorObject *pParent = NULL ,int nState =0);
	virtual ~CMonitorObject(void);

///���¼̳�ʵ����IMonitorObject�ķ���
public:
	LPCTSTR GetObjectID(void);
	LPCTSTR GetObjectName(void);
	LPCTSTR GetKeyword(void);
	int GetWarningState(void){return m_warningState;}
	IMonitorObject* GetParent(void);
	IMonitorObjectProperty* GetProperty(void);
	void FindObjectsByID(LPCTSTR lpszObjectID,vector<CString> & objects_vec);
	CList<IMonitorObject*> &GetChilds(void);

	void SetParentObj(IMonitorObject* pParent);
	void SetObjectID(LPCTSTR lpszObjectID);
	void SetObjectName(LPCTSTR lpszObjectName);
	void SetKeyword(LPCTSTR lpszKeyword);
	void SetProperty(IMonitorObjectProperty *pProperty);
	void SetWarningState(int nState){m_warningState =nState;}
	void SetWarningStateLeaf(int nState);
	void SetEventMessageState(int nState){m_nEventMessageState=nState;}
	void SetStatusFromChild(BOOL bStatusFromChild){m_bStatusFromChildren=bStatusFromChild;}
	void SetAttrMessageState(int nState){m_attrMessageState = nState;}
	int GetAttrMessageState(){return m_attrMessageState;}
	
	int  GetEventMessageState(void){return m_nEventMessageState;}
	void GetObjListByDepth(int dep, CList<IMonitorObject*>& ObjList);
	void SetObjDepthInTree(int dep) {m_depth = dep;};
	int	GetObjDepthInTree() { return m_depth;};
	void SetObjMonitorType(int objType /* = 0 */){m_objmonitortype = objType;};
	BOOL IsStatusFromChild(){return m_bStatusFromChildren;}

	int GetObjMonitorType() {return m_objmonitortype;};

	void SetObjDeviceFactory(int nFactory) {m_nDeviceFactory = nFactory;};
	int GetObjDeviceFactory() {return m_nDeviceFactory;};
	IMonitorObject* FindObjectByID(LPCTSTR lpszObjectID);
	IMonitorObject* FindObjectByKey(LPCTSTR lpszKeyword);
	IMonitorObject* FindObjectByName(LPCTSTR lpszKeyword);

	CString FindNagetivePoint(void);

public:
	//void SetParent(IMonitorObject* pParent);

private:
	CString m_strObjectID;
	CString m_strObjectName;
	CString m_strKeyword;
	int m_warningState;
	int m_nEventMessageState;
	IMonitorObjectProperty* m_pProperty;
	CList<IMonitorObject*> m_ObjectList;
	IMonitorObject* m_pParent;
	IMonitorObject* m_pRight;
	int m_attrMessageState;

	//obj��tree�е����
	int m_depth;
	//��ض�������
	int m_objmonitortype;
	//�豸����id
	int m_nDeviceFactory;
	// ����ĳЩ�ڵ��������״̬���������ӽڵ��״̬�������¼�Ƿ������ӽڵ�״̬��
	BOOL m_bStatusFromChildren;
};

///////////////////////////////////////////////////////////////////////////////////////////////
///������Ϣ
class CRequestInfo
{
	friend class CRequestQueue;

public:
	CRequestInfo(PVOID pSender, INT nAbsoluteReqID, INT nRelativeReqID = 0, DWORD dwTimeout = INFINITE);
	~CRequestInfo(void);

protected:
	CRequestInfo(void);

public:
	BOOL operator==(const INT nReqID);

	///��������ID�����ԣ�
	operator INT();

	///��ȡ�������󵽶��еĶ���
	PVOID GetSender(void);

	///��ȡ��Ե�RequestID
	INT GetRelativeReqID(void);

	///��ȡ���Ե�RequestID
	INT GetAbsoluteReqID(void);

	///��ȡ���������ʱ��
	DWORD GetTime(void);

	///��ȡ����ĳ�ʱʱ�䣬����Ϊ��λ
	DWORD GetTimeout(void);

private:
	///���������ʱ��
	DWORD m_dwTime;
	///����ĳ�ʱʱ�䣬����Ϊ��λ
	DWORD m_dwTimeout;
	///��Ե�����ID
	INT m_nAbsoluteReqID;
	///���Ե�����ID
	INT m_nRelativeReqID;
	///�������󵽶��еĶ���
	PVOID m_pSender;
};

///////////////////////////////////////////////////////////////////////////////////////////////
// CRequestQueue���������
class CRequestQueue
{
public:
	CRequestQueue(void);
	~CRequestQueue(void);

public:
	///��������е�β��׷��һ������
	CRequestInfo* Add(CRequestInfo *pRequest);

	///��ȡ��ǰ������ID
	INT GetRequestID(void);

	///�Ӷ�����ɾ������
	///@param	nRequestID	�����ţ�����������ɾ��
	BOOL Remove(int nRequestID);

	///�Ӷ�����ɾ������
	///@param	pRequest	����ֱ�Ӹ��������ָ����ң����Ӷ�����ɾ����
	BOOL Remove(CRequestInfo* pRequest);

	///�Ӷ�����ɾ������
	///@param	pSender	��������Ķ���ɾ�����и�pSender�йص�����
	void RemoveBySender(LPVOID pSender);

	///�Ӷ�����ɾ����������
	void RemoveAll(void);

	///����������У�ɾ�����������ҰѸ�������IDm_nReqestID��Ϊ0
	void Reset(void);

	///��++���أ���m_nReqestID����
	INT operator++();
	INT operator++(INT);
	operator INT();
	CRequestInfo* operator[](int nRequestID);

private:
	///����ID��ÿ��ʵ����һ�����󣬾ͽ�m_nReqestID����1
	INT m_nReqestID;
	CList<CRequestInfo*> m_lstQueque;
};


///�Ե�½�û���Ϣ
class CUserInfo : public IUserInfo
{
public:
	CUserInfo(void);
	CUserInfo(CShfeFtdcRspQrySysUserLoginField *pField);

public:
	///��ȡ�û�ID
	LPCTSTR GetUserID(void) { return m_strUserID; };

	///��ȡ�û�Ȩ��
	int GetPrivilege(void) { return m_nPrivilege; };

	///��ȡ��ǰ������
	LPCTSTR GetTradingDay(void) { return m_strTradingDay; };

	///��ȡ�û���¼ʱ��
	LPCTSTR GetLoginTime(void) { return m_strLoginTime; };

	///������=����
	CUserInfo& operator=(CShfeFtdcRspQrySysUserLoginField& field);

	///��ȡ��ǰ����ʱ��
	LPCTSTR GetTradingTime(void) { return m_strTradingTime; }

	void SetTradingTime(const CString& tradingTime)	{m_strTradingTime=tradingTime;}
private:
	///�û�ID
	CString m_strUserID;

	///�û�Ȩ��
	int m_nPrivilege;

	///��ǰ������
	CString m_strTradingDay;

	///�û���¼ʱ��
	CString m_strLoginTime;

	///��ǰ������
	CString m_strTradingTime;
};

class CTimePolicyData {
public:
	CTimePolicyData():policyID(0)
		,cname(_T(""))
		,ename(_T(""))
		,PolicyString(_T(""))
		,Description(_T(""))
		,Type(0)
		,TradingDay(0)
	{
	}
	CTimePolicyData(int id, LPCSTR  cn, LPCSTR en, LPCSTR policy, LPCSTR des, int type, int trade):
		policyID(id)
		,cname(cn)
		,ename(en)
		,PolicyString(policy)
		,Description(des)
		,Type(type)
		,TradingDay(trade)
	{
	}

	CString GetPolicyDescription(){ return cname;};
public:
	CString cname;
	CString ename;
	CString	PolicyString;
	CString	Description;
	int		policyID;
	int		Type;
	int		TradingDay;

};

#endif