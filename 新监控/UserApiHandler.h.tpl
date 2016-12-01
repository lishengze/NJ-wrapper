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


// 自定定义消息
#define WM_USERAPI_START						WM_USER + 100
#define WM_USERAPI_ONCONNECT				WM_USERAPI_START + 1
#define WM_USERAPI_ONDISCONNECT			WM_USERAPI_START + 2
#define WM_USERAPI_DATAREACH				WM_USERAPI_START + 3

!!enter FTD!!
// 定义UserApi到达数据的类别
enum {
	TAG_USERAPI_START,
!!travel packages!!
!!if InUse(@name) && (!strncmp(@name,"Rsp",3) || !strncmp(@name,"Rtn",3))!!
	TAG_USERAPI_!!show_string strupr(strdup(@name))!!,		///!!@comment
!!endif!!
!!next!!
	TAG_USERAPI_END
};


// 记录UserApi发送过来的数据信息
typedef struct tagUSERAPIDATAPACKINFO
{
	UINT nTag;			// 数据的类别
	INT nRequestID;		// 请求ID
	bool bIsLast;		// 是否为最后一个数据包
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
	/// 订阅对象计数器
	CMap<CString, LPCTSTR, int, int> &GetObjectSubCounter(void) { return m_mapObjectSubCounter; };
	/// 连接状态映射表
	CList<LPVOID> &GetConnectionStateRegister(void) { return m_ConnectionStateRegister; };
!!travel packages!!
	!!if InUse1(@name) || InUse2(@name)!!
	hash_map<string, list<void*>> &Get!!@name!!Register(void) { return m_!!@name!!Register; };			///!!@comment!!;
	!!elseif InUse3(@name) || InUseOther(@name)!!
	list<void*> &Get!!@name!!Register(void) { return m_!!@name!!Register; };			///!!@comment!!;
	!!endif!!
!!next!!
	
protected:
	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	void OnFrontConnected();
	
	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
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
	/// 订阅对象计数器
	CMap<CString, LPCTSTR, int, int> m_mapObjectSubCounter;
	/// 连接状态映射表
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