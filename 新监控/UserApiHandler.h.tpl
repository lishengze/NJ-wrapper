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
CPackageSet g_PackageOther;

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

bool InUseOther(char *name)
{
	return (g_PackageOther.find(name)!=g_PackageOther.end());
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
!!else!!
	!!command g_PackageOther.insert(@name);!!
!!endif!!
!!endif!!
!!next!!
!!leave!!

#ifndef __USERAPIUTILS_H__
#define __USERAPIUTILS_H__
#pragma once

#include <list>
#include <map>
#include <hash_map>
using namespace std;
using namespace stdext;

#include "..\UserApi\FtdcSysUserApi.h"
#include "..\common\CommonClass.h"
#include "DataUtils.h"


// �Զ�������Ϣ
#define WM_USERAPI_START						WM_USER + 100
#define WM_USERAPI_ONCONNECT				WM_USERAPI_START + 1
#define WM_USERAPI_ONDISCONNECT			WM_USERAPI_START + 2
#define WM_USERAPI_DATAREACH				WM_USERAPI_START + 3

!!enter FTD!!
// ����UserApi�������ݵ����
enum {
	TAG_USERAPI_START,
!!travel packages!!
!!if InUse(@name) && (!strncmp(@name,"Rsp",3) || !strncmp(@name,"Rtn",3))!!
	TAG_USERAPI_!!show_string strupr(strdup(@name))!!,		///!!@comment
!!endif!!
!!next!!
	TAG_USERAPI_END
};


// ��¼UserApi���͹�����������Ϣ
typedef struct tagUSERAPIDATAPACKINFO
{
	UINT nTag;			// ���ݵ����
	INT nRequestID;		// ����ID
	bool bIsLast;		// �Ƿ�Ϊ���һ�����ݰ�
	LPVOID pData0;
	LPVOID pData1;
	LPVOID pData2;
	LPVOID pData3;
	LPVOID pData4;
	LPVOID pData5;
	LPVOID pData6;
	LPVOID pData7;
} USERAPIDATAPACKINFO;
typedef USERAPIDATAPACKINFO *  PUSERAPIDATAPACKINFO;
typedef USERAPIDATAPACKINFO *  LPUSERAPIDATAPACKINFO;


class CUserApiHandler;

////////////////////////////////////////////////////////////////////////////////////////////////
// CUserApiHandlerWnd
class CUserApiHandlerWnd : public CWnd
{
	friend class CUserApiHandler;
	
public:
	CUserApiHandlerWnd(CUserApiHandler *pApiHandler) : m_pApiHandler(pApiHandler) {};
	
protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	
private:
	CUserApiHandler *m_pApiHandler;
};


////////////////////////////////////////////////////////////////////////////////////////////////
// CUserApiHandler
class CUserApiHandler : protected CShfeFtdcSysUserSpi
{
public:
	CUserApiHandler(void);
	~CUserApiHandler(void);
	
public:
	void Create(void);
	void Release(void);
	void Clear(void);
	void Reset(void);
	CRequestQueue& GetRequestQueue(void);
	CShfeFtdcSysUserApi* GetUserApi(void);
	/// ���Ķ��������
	CMap<CString, LPCTSTR, int, int> &GetObjectSubCounter(void) { return m_mapObjectSubCounter; };
	/// ����״̬ӳ���
	CList<LPVOID> &GetConnectionStateRegister(void) { return m_ConnectionStateRegister; };
!!travel packages!!
	!!if InUse1(@name) || InUse2(@name)!!
	hash_map<string, list<void*>> &Get!!@name!!Register(void) { return m_!!@name!!Register; };			///!!@comment!!;
	!!elseif InUse3(@name) || InUseOther(@name)!!
	list<void*> &Get!!@name!!Register(void) { return m_!!@name!!Register; };			///!!@comment!!;
	!!endif!!
!!next!!
	
protected:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	void OnFrontConnected();
	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	void OnFrontDisconnected(int nReason);

!!travel packages!!
!!if InUse(@name)!!
!!if !strncmp(@name,"Rsp",3)!!
	///!!@comment!!
	void On!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!CShfeFtdc!!@name!!Field *p!!@name!!!!next!!, int nRequestID, bool bIsLast);

!!endif!!
!!endif!!
!!next!!


!!travel packages!!
!!if InUse(@name)!!
!!if !strncmp(@name,"Rtn",3)!!
	///!!@comment!!
	void On!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!CShfeFtdc!!@name!!Field *p!!@name!!!!next!!);

!!endif!!
!!endif!!
!!next!!

private:
	CUserApiHandlerWnd m_wndHandler;
	CRequestQueue m_RequestQueue;
	CShfeFtdcSysUserApi* m_pUserApi;
	/// ���Ķ��������
	CMap<CString, LPCTSTR, int, int> m_mapObjectSubCounter;
	/// ����״̬ӳ���
	CList<LPVOID> m_ConnectionStateRegister;
!!travel packages!!
	!!if InUse1(@name) || InUse2(@name)!!
	hash_map<string, list<void*>> m_!!@name!!Register;
	!!elseif InUse3(@name) || InUseOther(@name)!!
	list<void*> m_!!@name!!Register;
	!!endif!!
!!next!!
};
!!leave!!

#endif