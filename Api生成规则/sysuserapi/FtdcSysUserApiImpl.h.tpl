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

bool InUse(char *name)
{
	return (g_setUsePackage.find(name)!=g_setUsePackage.end());
}

!!endfunction!!
!!enter sysuserapi!!
!!travel self!!	
!!command g_setUsePackage.insert(@name);!!
!!next!!
!!leave!!
/////////////////////////////////////////////////////////////////////////
///@system ��һ��������ϵͳ���ռ��ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file FtdcSysUserApiImpl.h
///@brief �����˿ͻ��˽ӿ�ʵ��
///@history 
///20070207 zhangjie		�������ļ�
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCSYSUSERAPIIMPL_H)
#define _FTDCSYSUSERAPIIMPL_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//#include "FtdcSysUserApi.h"

#include "FtdcSysUserApiImplBase.h"

!!enter FTD!!
///SysUserApi�ӿ�ʵ��
class CFtdcSysUserApiImpl : public CFtdcSysUserApiImplBase
{
public:	
	CFtdcSysUserApiImpl(const char *pszFlowPath, CSelectReactor *pReactor);
	virtual void HandleResponse(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
!!travel packages!!
!!if InUse(@name)!!
!!if !strncmp(@name,"Req",3) && strcmp(@name,"ReqUserLogin") && strcmp(@name,"ReqQryInstPositionRate") && strcmp(@name,"ReqSimulateStressTest")!!

	///!!@comment!!
	virtual int !!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!CShfeFtdc!!@name!!Field *p!!@name!!!!next!!, int nRequestID);
!!endif!!
!!endif!!
!!next!!

private:
!!travel packages!!
!!if InUse(@name)!!
!!if !strncmp(@name,"Rsp",3) !!
	///!!@comment!!
	void On!!@name!!(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
!!elseif !strncmp(@name,"Rtn",3)!!
	///!!@comment!!
	void On!!@name!!(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
!!elseif !strncmp(@name,"ErrRtn",6)!!
	///!!@comment!!
	void On!!@name!!(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
!!endif!!
!!endif!!
!!next!!

};

!!leave!!  

#endif
