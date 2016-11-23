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
///@file FtdcSysUserApi.h
///@brief �����˿ͻ��˽ӿ�
///@history 
///20070227	zhangjie		�������ļ�
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCSYSUSERAPI_H)
#define _FTDCSYSUSERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FtdcSysUserApiStruct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_SYSUSER_API_EXPORT
#define SYSUSER_API_EXPORT __declspec(dllexport)
#else
#define SYSUSER_API_EXPORT __declspec(dllimport)
#pragma comment(lib, "sysuserapi.lib")
#endif
#else
#define SYSUSER_API_EXPORT 
#endif

!!enter FTD!!
class CShfeFtdcSysUserSpi
{
public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected(){};
	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason){};
		
	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse){};
	
!!travel packages!!
!!if InUse(@name)!!
!!if !strncmp(@name,"Rsp",3)!!

	///!!@comment!!
	virtual void On!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!CShfeFtdc!!@name!!Field *p!!@name!!!!next!!, int nRequestID, bool bIsLast) {};
!!elseif !strncmp(@name,"Rtn",3)!!

	///!!@comment!!
	virtual void On!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!CShfeFtdc!!@name!!Field *p!!@name!!!!next!!) {};
!!endif!!
!!endif!!
!!next!!
};

class SYSUSER_API_EXPORT CShfeFtdcSysUserApi
{
public:
	///����SysUserApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	///@return ��������UserApi
	static CShfeFtdcSysUserApi *CreateFtdcSysUserApi(const char *pszFlowPath = "");
	
	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release() = 0;
	
	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	virtual void Init() = 0;
	
	///�ȴ��ӿ��߳̽�������
	///@return �߳��˳�����
	virtual int Join() = 0;
	
	///��ȡ��ǰ������
	///@retrun ��ȡ���Ľ�����
	///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
	virtual const char *GetTradingDay() = 0;
	
	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	
	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CShfeFtdcSysUserSpi *pSpi) = 0;
	
	///�����г����顣
	///@param nTopicID �г���������  
	///@param nResumeType �г������ش���ʽ  
	///        TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        TERT_RESUME:���ϴ��յ�������
	///        TERT_QUICK:�ȴ��͵�ǰ�������,�ٴ��͵�¼���г����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
	virtual void SubscribeMarketDataTopic(int nTopicID, TE_RESUME_TYPE nResumeType) = 0;
	
	///���Ļ�Աʵʱ�ʽ�״����
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ����ݡ�
	virtual void SubscribePartAccount(void) = 0;

	///�û���¼����
	virtual int ReqUserLogin(CShfeFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;
	
!!travel packages!!
!!if InUse(@name)!!
!!if !strncmp(@name,"Req",3) && strcmp(@name,"ReqUserLogin") && strcmp(@name,"ReqQrySpecialPart") && strcmp(@name,"ReqQrySpecialClient") && strcmp(@name,"ReqQryInstPositionRate") && strcmp(@name, "ReqSimulateStressTest") && strcmp(@name,"ReqMarketStressTest") && strcmp(@name,"ReqQryInstPosiOverLmt")!!

	///!!@comment!!
	virtual int !!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!CShfeFtdc!!@name!!Field *p!!@name!!!!next!!, int nRequestID) = 0;
!!endif!!
!!endif!!
!!next!!


protected:
	~CShfeFtdcSysUserApi(){};
};
!!leave!!  

#endif
