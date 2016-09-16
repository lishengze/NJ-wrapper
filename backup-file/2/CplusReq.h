#ifndef _TESTFUNC_H_
#define _TESTFUNC_H_
#include "FtdcSysUserApi.h"
#include "sysuserspi.h"
#include "tool-function.h"
#include <string.h>
/**
* ����ֱ�Ӳ���C++�ص���
* ���ԣ�1. ReqQrySysUserLoginTopic�� OnRspQrySysUserLoginTopic
	   2. ReqQryNetMonitorAttrScopeTopic�� OnRspQryNetMonitorAttrScopeTopic
	   3. ReqQryMonitorObjectTopic�� OnRspQryMonitorObjectTopic
*/

// fstream g_RunningResult_File;

CShfeFtdcSysUserApi* g_pUserApi = CShfeFtdcSysUserApi::CreateFtdcSysUserApi();
CShfeFtdcSysUserSpi* g_pUserSpi = new SysUserSpi();
char* g_realTimeSystemPath = (char*)("tcp://172.1.128.165:18841");    // ʵʱ����ϵͳ;
char* g_innerTestSystemPath = (char*)("tcp://172.1.128.111:18842");   // �ڲ�����ϵͳ;

void TestReqQrySysUserLoginTopic(int ReqQrySysUserLoginTopicNumbers);
void TestReqQryNetMonitorAttrScopeTopic(int ReqQryNetMonitorAttrScopeTopicNumbers);
void TestReqQryMonitorObjectTopic(int ReqQryMonitorObjectTopicNumbers);

void ConnectToFront() {
	// g_RunningResult_File.open("cplusplus-callback-result.txt", ios::out);
	// if (!g_RunningResult_File) {
	// 	OutputCallbackMessage("Failed to open running-message.txt", g_RunningResult_File);
	// 	g_RunningResult_File.close();
	// }

	cout << "Registerfront Start!" << endl;

	g_pUserApi->RegisterFront(g_realTimeSystemPath);
    
	g_pUserApi->RegisterSpi(g_pUserSpi);

	g_pUserApi->Init();

	// cout << "g_pUserApi->Join() " << endl;
	// g_pUserApi->Join();

	cout << "Registerfront End!" << endl;	
}

/************************************************************************/
/* 
struct CShfeFtdcReqQrySysUserLoginField
{
//�û�����
TShfeFtdcUserIDType	UserID;
//����
TShfeFtdcPasswordType	Password;
//�汾��
TShfeFtdcVersionIDType	VersionID;
};                                                                     
*/
/************************************************************************/

void TestReqQrySysUserLoginTopic(int ReqQrySysUserLoginTopicNumbers) {
	struct CShfeFtdcReqQrySysUserLoginField loginField[2];
	strncpy(loginField[0].UserID, "admin", sizeof("admin"));
	strncpy(loginField[0].Password, "admin", sizeof("admin"));
	strncpy(loginField[0].VersionID, "2.0.0.0", sizeof("2.0.0.0"));

	for (int i = 0; i < ReqQrySysUserLoginTopicNumbers; ++i) {
		cout << "ReqQrySysUserLoginTopic result: " 
             << g_pUserApi->ReqQrySysUserLoginTopic(&loginField[i], 1) << endl;
	}
}

void TestReqQryNetMonitorAttrScopeTopic(int ReqQryNetMonitorAttrScopeTopicNumbers) {
	struct CShfeFtdcReqQryNetMonitorAttrScopeField netMonitorAttrerScopeField;
	memset((void*)&netMonitorAttrerScopeField, 0, sizeof(CShfeFtdcReqQryNetMonitorAttrScopeField));

	for (int i = 0; i < ReqQryNetMonitorAttrScopeTopicNumbers; ++i) {
		cout <<"ReqQryNetMonitorAttrScopeTopic result: "  
             << g_pUserApi->ReqQryNetMonitorAttrScopeTopic(&netMonitorAttrerScopeField, 1) << endl;
	}
}

void TestReqQryMonitorObjectTopic(int ReqQryMonitorObjectTopicNumbers) {
	struct CShfeFtdcReqQryMonitorObjectField monitorObjectField;
	memset((void*)&monitorObjectField, 0, sizeof(CShfeFtdcReqQryMonitorObjectField));

	for (int i = 0; i < ReqQryMonitorObjectTopicNumbers; ++i) {
		cout << "ReqQryMonitorObjectTopic result: " 
             << g_pUserApi->ReqQryMonitorObjectTopic(&monitorObjectField, 1) << endl;
	}
}

void ReleaseMemory() {
	//g_pUserApi->Release();
	//OutputCallbackMessage("Release g_pUserApi", g_RunningResult_File);

	//if (NULL != g_pUserSpi) {
	//	delete g_pUserSpi;
	//	OutputCallbackMessage("Delete g_pUserSpi", g_RunningResult_File);
	//	g_pUserSpi = NULL;
	//}
//	Sleep(2000);
}

void TestCopy () {
	char data[16];
	cout << "sizeof(123456): " << sizeof("123456") << endl;
	strncpy(data, "123456", sizeof("123456"));
	cout << "data: " << data << endl;
}
#endif