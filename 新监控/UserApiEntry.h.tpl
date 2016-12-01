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

#ifndef __USERAPIENTRY_H__
#define __USERAPIENTRY_H__

#pragma once
#include "..\DataUtils.h"

!!enter FTD!!
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
	
!!travel packages!!
!!if InUse(@name)!!
!!if !strncmp(@name,"Rsp",3)!!
	///!!@comment!!
	virtual void On!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!CShfeFtdc!!@name!!Field *p!!@name!!!!next!!, int nRequestID, bool bIsLast){};

!!endif!!
!!endif!!
!!next!!


!!travel packages!!
!!if InUse(@name)!!
!!if !strncmp(@name,"Rtn",3)!!
	///!!@comment!!
	virtual void On!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!CShfeFtdc!!@name!!Field *p!!@name!!!!next!!){};

!!endif!!
!!endif!!
!!next!!

!!travel packages!!
!!if InUse(@name)!!
!!if !strncmp(@name,"Req",3)!!
	///!!@comment!!
	virtual BOOL !!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!CShfeFtdc!!@name!!Field *p!!@name!!!!next!!, int nRequestID = 0);
	
!!endif!!
!!endif!!
!!next!!

!!travel packages!!
!!if InUse5(@name) && !strncmp(@name,"Rtn",3)!!
	///¶©ÔÄ!!@comment!!
	virtual BOOL Sub!!@name!!(QWORD ObjectID, QWORD subObjectID=0, int nRequestID=0);
	///È¡Ïû¶©ÔÄ!!@comment!!
	virtual BOOL Unsub!!@name!!(QWORD ObjectID, QWORD subObjectID=0, int nRequestID=0);
	
!!elseif InUse(@name) && !strncmp(@name,"Rtn",3)!!
	///¶©ÔÄ!!@comment!!
	virtual BOOL Sub!!@name!!(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="", int nObjectNum = DEFAULT_OBJECTNUM ,TShfeFtdcDateType startDate ="", TShfeFtdcTimeType startTime ="" ,int nRequestID = 0);
	///È¡Ïû¶©ÔÄ!!@comment!!
	virtual BOOL Unsub!!@name!!(TShfeFtdcTypeSubcriberObjectIDType	ObjectID, TShfeFtdcTypeObjectIDType	subObjectID ="",int nRequestID = 0);
	
!!endif!!
!!next!!
	
private:
	BOOL SubscriberTopic(TShfeFtdcTypeSubcriberObjectIDType ObjectID,   TShfeFtdcTypeObjectIDType	subObjectID, int nObjectNum ,TShfeFtdcDateType startDate, TShfeFtdcTimeType startTime ,int nRequestID);
	BOOL UnsubscriberTopic(TShfeFtdcTypeSubcriberObjectIDType ObjectID, TShfeFtdcTypeObjectIDType	subObjectID,int nRequestID);
};
!!leave!!


#endif