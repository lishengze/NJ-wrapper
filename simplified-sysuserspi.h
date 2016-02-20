#ifndef _SYS_USER_SPI_H_
#define _SYS_USER_SPI_H_

#include "FtdcSysUserApi.h"
#include "id-func.h"

class SysUserSpi :public CShfeFtdcSysUserSpi {
public:

    SysUserSpi();

	FRONT_ID m_frontid;
	
	int m_MonitorObjectTopicNumb;
	
	int m_SysUserLoginTopicNumb;
	
	virtual ~SysUserSpi();

	virtual void OnFrontConnected();

	virtual void OnRspQrySysUserLoginTopic(CShfeFtdcRspQrySysUserLoginField *pRspQrySysUserLogin,
											CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryNetMonitorAttrScopeTopic (CShfeFtdcRspQryNetMonitorAttrScopeField *pRspQryNetMonitorAttrScope,
													CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryMonitorObjectTopic(CShfeFtdcRspQryMonitorObjectField* pRspQryMonitorObject,
		                                    CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

};

#endif
