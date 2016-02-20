#ifndef _TESTFUNC_H_
#define _TESTFUNC_H_
#include "FtdcSysUserApi.h"
#include "simplified-sysuserspi.h"
#include "tool-function.h"
#include "id-func.h"
#include <string.h>
/**
* ����ֱ�Ӳ���C++�ص���
* ���ԣ�1. ReqQrySysUserLoginTopic�� OnRspQrySysUserLoginTopic
	   2. ReqQryNetMonitorAttrScopeTopic�� OnRspQryNetMonitorAttrScopeTopic
	   3. ReqQryMonitorObjectTopic�� OnRspQryMonitorObjectTopic
*/

fstream g_RunningResult_File;
CShfeFtdcSysUserApi* g_pUserApi = CShfeFtdcSysUserApi::CreateFtdcSysUserApi();
CShfeFtdcSysUserSpi* g_pUserSpi = new SysUserSpi();
char* g_realTimeSystemPath = (char*)("tcp://172.1.128.165:18841");    // ʵʱ����ϵͳ;
char* g_innerTestSystemPath = (char*)("tcp://172.1.128.111:18842");   // �ڲ�����ϵͳ;

void ConnectToFront(int userNumber) {
	
	g_RunningResult_File.open("cplusplus-callback-result.txt", ios::out);

	if (!g_RunningResult_File) {
		OutputCallbackMessage("Failed to open running-message.txt", g_RunningResult_File);
		g_RunningResult_File.close();
	}

	cout << "Registerfront Start!" << endl;
	
	CShfeFtdcSysUserApi** pUserApi = new CShfeFtdcSysUserApi*[userNumber];
	CShfeFtdcSysUserSpi* pUserSpi  = new CShfeFtdcSysUserSpi[userNumber];
	
	for (int i = 0; i < userNumber; ++i) {
				
		pUserSpi[i].m_frontid = GetFrontID();
		pUserSpi[i].m_MonitorAttrScopeTopicNumb = 1;
		pUserSpi[i].m_SysUserLoginTopicNumb = 0;
		
		pUserApi[i] = CShfeFtdcSysUserApi::CreateFtdcSysUserApi();
		pUserApi[i]->RegisterFront(g_realTimeSystemPath);
        pUserApi[i]->RegisterSpi((CShfeFtdcSysUserSpi*)&pUserSpi[i]);
		pUserApi[i]->Init();			
	}

	cout << "Registerfront End!" << endl;	
}

void TestReqQryNetMonitorAttrScopeTopic(int ReqQryNetMonitorAttrScopeTopicNumbers) {
	struct CShfeFtdcReqQryNetMonitorAttrScopeField netMonitorAttrerScopeField;
	memset((void*)&netMonitorAttrerScopeField, 0, sizeof(CShfeFtdcReqQryNetMonitorAttrScopeField));

	for (int i = 0; i < ReqQryNetMonitorAttrScopeTopicNumbers; ++i) {
		g_pUserApi->ReqQryNetMonitorAttrScopeTopic(&netMonitorAttrerScopeField, 1);
	}
}

void TestReqQrySysUserLoginTopic(int ReqQrySysUserLoginTopicNumbers) {
	struct CShfeFtdcReqQrySysUserLoginField loginField[2];
	strncpy(loginField[0].UserID, "admin", sizeof("admin"));
	strncpy(loginField[0].Password, "admin", sizeof("admin"));
	strncpy(loginField[0].VersionID, "2.0.0.0", sizeof("2.0.0.0"));

	for (int i = 0; i < ReqQrySysUserLoginTopicNumbers; ++i) {
		//int flag = g_pUserApi->ReqQrySysUserLoginTopic(&loginField[i], 1);
		//cout << "ReqQrySysUserLoginTopic result: " << flag << endl;
		cout << "ReqQrySysUserLoginTopic result: " << g_pUserApi->ReqQrySysUserLoginTopic(&loginField[i], 1) << endl;
	}
}

void TestReqQryMonitorObjectTopic(int ReqQryMonitorObjectTopicNumbers) {
	struct CShfeFtdcReqQryMonitorObjectField monitorObjectField;
	memset((void*)&monitorObjectField, 0, sizeof(CShfeFtdcReqQryMonitorObjectField));

	for (int i = 0; i < ReqQryMonitorObjectTopicNumbers; ++i) {
		g_pUserApi->ReqQryMonitorObjectTopic(&monitorObjectField, 1);
	}
}

#endif