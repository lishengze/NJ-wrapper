#include "FtdcSysUserApi.h"
#include "simplified-sysuserspi.h"
#include "tool-function.h"
#include <string.h>

fstream g_RunningResult_File;
CShfeFtdcSysUserApi* g_pUserApi;
SysUserSpi* g_pUserSpi;

char* g_realTimeSystemPath = (char*)("tcp://172.1.128.172:19943");
// char* g_realTimeSystemPath = (char*)("tcp://172.1.128.165:18841");
char* g_innerTestSystemPath = (char*)("tcp://172.1.128.111:18842");

int g_FrontID = 0;

void ConnectToFront(int userNumber) {

	g_RunningResult_File.open("cplusplus-callback-result.txt", ios::out);

	if (!g_RunningResult_File) {
		OutputCallbackMessage("Failed to open running-message.txt", g_RunningResult_File);
		g_RunningResult_File.close();
	}

	cout << "Registerfront Start!" << endl;

	g_pUserSpi = new SysUserSpi();
	g_pUserApi = CShfeFtdcSysUserApi::CreateFtdcSysUserApi("./usr/");

	g_pUserSpi->m_frontid = g_FrontID++;
	g_pUserSpi->m_MonitorObjectTopicNumb = 1;
	g_pUserSpi->m_SysUserLoginTopicNumb = 0;

	g_pUserApi->RegisterFront(g_realTimeSystemPath);
	g_pUserApi->RegisterSpi(g_pUserSpi);
	g_pUserApi->Init();

	cout << "Registerfront End!" << endl;
}

void TestReqQrySysUserLoginTopic(int ReqQrySysUserLoginTopicNumbers) {
	struct CShfeFtdcReqQrySysUserLoginField loginField;
	memset((void*)&loginField, 0, sizeof(CShfeFtdcReqQrySysUserLoginField));
	strncpy(loginField.UserID, "admin", sizeof("admin"));
	strncpy(loginField.Password, "admin", sizeof("admi"));
	strncpy(loginField.VersionID, "2.0.0.0", sizeof("2.0.0.0"));

	cout << "loginField.UserID:        " << loginField.UserID << endl;
	cout << "loginField.Password:      " << loginField.Password << endl;
	cout << "loginField.VersionID:     " << loginField.VersionID  << endl;
	cout << "ReqQrySysUserLoginTopic result: " << g_pUserApi->ReqQrySysUserLoginTopic(&loginField, 1) << endl;
}

void TestReqQryMonitorObjectTopic(int ReqQryMonitorObjectTopicNumbers) {
	struct CShfeFtdcReqQryMonitorObjectField monitorObjectField;
	memset((void*)&monitorObjectField, 0, sizeof(CShfeFtdcReqQryMonitorObjectField));

	for (int i = 0; i < ReqQryMonitorObjectTopicNumbers; ++i) {
		g_pUserApi->ReqQryMonitorObjectTopic(&monitorObjectField, 1);
	}
}

void TestReqQrySubscriberTopic() {
	struct CShfeFtdcReqQrySubscriberField subscriberField;
	memset((void*)&subscriberField, 0, sizeof(CShfeFtdcReqQrySubscriberField));

	strncpy(subscriberField.ObjectID, "TMS.PuDian.app.sysprobe.1.CPUUsage", sizeof("TMS.PuDian.app.sysprobe.1.CPUUsage"));
	subscriberField.ObjectNum = -1;
	subscriberField.KeepAlive = 1;

	g_pUserApi->ReqQrySubscriberTopic(&subscriberField, 1);
}
