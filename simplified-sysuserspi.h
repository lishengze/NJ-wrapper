#ifndef _SYS_USER_SPI_H_
#define _SYS_USER_SPI_H_

#include "FtdcSysUserApi.h"
#include <sys/time.h>
#include <unistd.h>
#include <time.h>

class SysUserSpi :public CShfeFtdcSysUserSpi {
public:
    /*virtual SysUserSpi();*/

	int m_frontid;

	int m_MonitorObjectTopicNumb;

	int m_SysUserLoginTopicNumb;

	/*virtual ~SysUserSpi();*/

	virtual void OnFrontConnected();

	virtual void OnRspQrySysUserLoginTopic(CShfeFtdcRspQrySysUserLoginField *pRspQrySysUserLogin,
											CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryMonitorObjectTopic(CShfeFtdcRspQryMonitorObjectField* pRspQryMonitorObject,
		                                    CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	virtual void OnRtnObjectAttrTopic(CShfeFtdcRtnObjectAttrField *pRtnObjectAttr);


};

#endif
