#ifndef _SYS_USER_SPI_H_
#define _SYS_USER_SPI_H_

#include "FtdcSysUserApi.h"
#include "tool-function.h"
#include "CplusReq.h"
#include "id-func.h"
#include "charset-convert-linux.h"
#include <string.h>

extern fstream g_RunningResult_File;

int g_RspQrySysUserLoginTopic_spi_callbackNumb = 0;
int g_RspQryNetMonitorAttrScopeTopic_spi_callbackNumb = 0;
int g_RspQryMonitorObjectTopic_spi_callbackNumb = 0;

void SysUserSpi::SysUserSpi() {
	
	m_frontid = -1;
	
	m_MonitorObjectTopicNumb = 0;
	
	m_SysUserLoginTopicNumb = 0;	
}

void SysUserSpi::OnFrontConnected(){
         
	OutputCallbackMessage("\n++++++++++++++ SysUserSpi::OnFrontConnected() SATRT! +++++++++++++++\n", g_RunningResult_File);
    
    TestReqQryMonitorObjectTopic(this.m_MonitorObjectTopicNumb);
	
    OutputCallbackMessage("\n++++++++++++++ SysUserSpi::OnFrontConnected() END! +++++++++++++++\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQrySysUserLoginTopic(CShfeFtdcRspQrySysUserLoginField* pRspQrySysUserLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQrySysUserLoginTopic: START! ******", g_RunningResult_File);
    OutputCallbackMessage("g_RspQrySysUserLoginTopic_spi_callbackNumb: ", g_RspQrySysUserLoginTopic_spi_callbackNumb++, g_RunningResult_File);

    void** paramArray = new void*[4];
    if (NULL == paramArray) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for paramArray", g_RunningResult_File);
        OutputCallbackMessage("****** SysUserSpi:: RspQrySysUserLoginTopic: END! ******\n", g_RunningResult_File);
        return; 
    } 

    CShfeFtdcRspQrySysUserLoginField* pNewRspQrySysUserLogin = NULL;
    if (NULL != pRspQrySysUserLogin) { 
        pNewRspQrySysUserLogin = new CShfeFtdcRspQrySysUserLoginField;
        if (NULL == pNewRspQrySysUserLogin) {
            OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pNewRspQrySysUserLogin", g_RunningResult_File);
            return;
        }
        memcpy (pNewRspQrySysUserLogin,pRspQrySysUserLogin, sizeof(CShfeFtdcRspQrySysUserLoginField));
    }

	CShfeFtdcRspInfoField* pRspInfoNew = NULL;
    if (NULL != pRspInfo){        
        pRspInfoNew = new CShfeFtdcRspInfoField;        
        if (NULL == pRspInfo) {
            OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pRspInfo", g_RunningResult_File);
            return;            
        }        
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));        
    }	
	
    int*  pId = new int(nRequestID);
    if (NULL == pId) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pId", g_RunningResult_File);
        return;
    }
    
    bool* bIsLastNew = new bool(bIsLast);
    if (NULL == bIsLastNew) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for bIsLastNew", g_RunningResult_File);
        return;
    }  	

    paramArray[0] = (void*)pNewRspQrySysUserLogin;
	paramArray[1] = (void*)pRspInfoNew;		
	paramArray[2] = (void*)pId;
    paramArray[3] = (void*)bIsLastNew;			
			
    if (NULL == pRspQrySysUserLogin) { 
        OutputCallbackMessage("SysUserSpi::pRspQrySysUserLogin is NULL" , g_RunningResult_File); 
    } else {
        OutputCallbackMessage("pRspQrySysUserLogin->UserID: ", pRspQrySysUserLogin->UserID, g_RunningResult_File);
        OutputCallbackMessage("pRspQrySysUserLogin->TradingDay: ", pRspQrySysUserLogin->TradingDay, g_RunningResult_File);
        OutputCallbackMessage("pRspQrySysUserLogin->LoginTime: ", pRspQrySysUserLogin->LoginTime, g_RunningResult_File);
        OutputCallbackMessage("pRspQrySysUserLogin->Privilege: ", pRspQrySysUserLogin->Privilege, g_RunningResult_File);
        OutputCallbackMessage("pRspQrySysUserLogin->VersionFlag: ", pRspQrySysUserLogin->VersionFlag, g_RunningResult_File);
    }
    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    OutputCallbackMessage("****** SysUserSpi:: RspQrySysUserLoginTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetMonitorAttrScopeTopic(CShfeFtdcRspQryNetMonitorAttrScopeField* pRspQryNetMonitorAttrScope, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetMonitorAttrScopeTopic: START! ******", g_RunningResult_File);
	OutputCallbackMessage("g_RspQryNetMonitorAttrScopeTopic_spi_callbackNumb: ", g_RspQryNetMonitorAttrScopeTopic_spi_callbackNumb++, g_RunningResult_File);

	void** paramArray = new void*[4];
	if (NULL == paramArray) {
		OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for paramArray", g_RunningResult_File);
		OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorAttrScopeTopic: END! ******\n", g_RunningResult_File);
		return;
	}

	CShfeFtdcRspQryNetMonitorAttrScopeField* pNewRspQryNetMonitorAttrScope = NULL;
	if (NULL != pRspQryNetMonitorAttrScope) {
		pNewRspQryNetMonitorAttrScope = new CShfeFtdcRspQryNetMonitorAttrScopeField;
		if (NULL == pNewRspQryNetMonitorAttrScope) {
			OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pNewRspQryNetMonitorAttrScope", g_RunningResult_File);
			return;
		}
		memcpy(pNewRspQryNetMonitorAttrScope, pRspQryNetMonitorAttrScope, sizeof(CShfeFtdcRspQryNetMonitorAttrScopeField));
	}

	CShfeFtdcRspInfoField* pRspInfoNew = NULL;
	if (NULL != pRspInfo){
		pRspInfoNew = new CShfeFtdcRspInfoField;
		if (NULL == pRspInfo) {
			OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pRspInfo", g_RunningResult_File);
			return;
		}
		memcpy(pRspInfoNew, pRspInfo, sizeof(CShfeFtdcRspInfoField));
	}

	int*  pId = new int(nRequestID);
	if (NULL == pId) {
		OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pId", g_RunningResult_File);
		return;
	}

	bool* bIsLastNew = new bool(bIsLast);
	if (NULL == bIsLastNew) {
		OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for bIsLastNew", g_RunningResult_File);
		return;
	}

	paramArray[0] = (void*)pNewRspQryNetMonitorAttrScope;
	paramArray[1] = (void*)pRspInfoNew;
	paramArray[2] = (void*)pId;
	paramArray[3] = (void*)bIsLastNew;

	if (NULL == pRspQryNetMonitorAttrScope) {
		OutputCallbackMessage("SysUserSpi::pRspQryNetMonitorAttrScope is NULL", g_RunningResult_File);
	}
	else {
		OutputCallbackMessage("pRspQryNetMonitorAttrScope->OperationType: ", pRspQryNetMonitorAttrScope->OperationType, g_RunningResult_File);
		OutputCallbackMessage("pRspQryNetMonitorAttrScope->ID: ", pRspQryNetMonitorAttrScope->ID, g_RunningResult_File);
		OutputCallbackMessage("pRspQryNetMonitorAttrScope->CName: ", pRspQryNetMonitorAttrScope->CName, g_RunningResult_File);
		OutputCallbackMessage("pRspQryNetMonitorAttrScope->EName: ", pRspQryNetMonitorAttrScope->EName, g_RunningResult_File);
		OutputCallbackMessage("pRspQryNetMonitorAttrScope->Comments: ", pRspQryNetMonitorAttrScope->Comments, g_RunningResult_File);
	}
	OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
	OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
	OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

	OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorAttrScopeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryMonitorObjectTopic(CShfeFtdcRspQryMonitorObjectField* pRspQryMonitorObject, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	OutputCallbackMessage("\n****** SysUserSpi:: RspQryMonitorObjectTopic: START! ******", g_RunningResult_File);
	OutputCallbackMessage("g_RspQryMonitorObjectTopic_spi_callbackNumb: ", g_RspQryMonitorObjectTopic_spi_callbackNumb++, g_RunningResult_File);

	void** paramArray = new void*[4];
	if (NULL == paramArray) {
		OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for paramArray", g_RunningResult_File);
		OutputCallbackMessage("****** SysUserSpi:: RspQryMonitorObjectTopic: END! ******\n", g_RunningResult_File);
		return;
	}

	CShfeFtdcRspQryMonitorObjectField* pNewRspQryMonitorObject = NULL;
	if (NULL != pRspQryMonitorObject) {
		pNewRspQryMonitorObject = new CShfeFtdcRspQryMonitorObjectField;
		if (NULL == pNewRspQryMonitorObject) {
			OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pNewRspQryMonitorObject", g_RunningResult_File);
			return;
		}
		memcpy(pNewRspQryMonitorObject, pRspQryMonitorObject, sizeof(CShfeFtdcRspQryMonitorObjectField));
	}

	CShfeFtdcRspInfoField* pRspInfoNew = NULL;
	if (NULL != pRspInfo){
		pRspInfoNew = new CShfeFtdcRspInfoField;
		if (NULL == pRspInfo) {
			OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pRspInfo", g_RunningResult_File);
			return;
		}
		memcpy(pRspInfoNew, pRspInfo, sizeof(CShfeFtdcRspInfoField));
	}

	int*  pId = new int(nRequestID);
	if (NULL == pId) {
		OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pId", g_RunningResult_File);
		return;
	}

	bool* bIsLastNew = new bool(bIsLast);
	if (NULL == bIsLastNew) {
		OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for bIsLastNew", g_RunningResult_File);
		return;
	}

	paramArray[0] = (void*)pNewRspQryMonitorObject;
	paramArray[1] = (void*)pRspInfoNew;
	paramArray[2] = (void*)pId;
	paramArray[3] = (void*)bIsLastNew;

	if (NULL == pRspQryMonitorObject) {
		OutputCallbackMessage("SysUserSpi::pRspQryMonitorObject is NULL", g_RunningResult_File);
	}
	else {
		string utf8string;
		OutputCallbackMessage("pRspQryMonitorObject->ObjectID: ", pRspQryMonitorObject->ObjectID, g_RunningResult_File);
		OutputCallbackMessage("pRspQryMonitorObject->ObjectName: ", pRspQryMonitorObject->ObjectName, g_RunningResult_File);
		OutputCallbackMessage("pRspQryMonitorObject->WarningActive: ", pRspQryMonitorObject->WarningActive, g_RunningResult_File);
		Gb2312ToUtf8(pRspQryMonitorObject->ObjectID, utf8string);
		Gb2312ToUtf8(pRspQryMonitorObject->ObjectName, utf8string);
	}
	OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
	OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
	OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

	OutputCallbackMessage("****** SysUserSpi:: RspQryMonitorObjectTopic: END! ******\n", g_RunningResult_File);
}


#endif
