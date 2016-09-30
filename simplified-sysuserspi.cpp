#include "FtdcSysUserApi.h"
#include "tool-function.h"
#include "simplified-sysuserspi.h"
#include "CplusReq.h"
#include <stdlib.h>
#include <string.h>
#include <string>
using std::string;

// char* g_realTimeSystemPath = (char*)("tcp://192.168.100.1:19943");
char* g_realTimeSystemPath = (char*)("tcp://172.1.128.172:19943");
// char* g_realTimeSystemPath = (char*)("tcp://172.1.128.165:18841");
char* g_innerTestSystemPath = (char*)("tcp://172.1.128.111:18842");

fstream g_RunningResult_File;

int g_RspQrySysUserLoginTopic_spi_callbackNumb = 0;
int g_RspQryNetMonitorAttrScopeTopic_spi_callbackNumb = 0;
int g_RspQryMonitorObjectTopic_spi_callbackNumb = 0;
int g_RtnObjectAttrTopic_spi_callbackNumb = 0;

bool g_rtn_over = false;
int g_sec_rtnSendNumber = 10;
int g_sec_rtnSendFreq = 1000;
int g_rtn_callback_onesec = g_sec_rtnSendNumber * g_sec_rtnSendFreq;

int  g_testTimeIndex = 6;
int  g_reqNumb = 1;
const int g_test_rtn_time_numb = 7;
double g_sec_array[g_test_rtn_time_numb] = {1,5,30,60,60,60,60};
double g_min_array[g_test_rtn_time_numb] = {1,1,1, 1, 5, 30,60};

double g_sec = g_sec_array[g_testTimeIndex];
double g_min = g_min_array[g_testTimeIndex];
double g_stopusec = g_min * g_sec * 1000000;

int  g_oneSecReqNumb = 300 * 3;

const int g_test_rsp_monitor_numb = 5;
int g_reqMonitor_number_array[g_test_rsp_monitor_numb] = {300, 600, 900, 1200, 1500};
int g_test_rsp_monitor_numb_index = 0;
int  g_ReqQryMonitorObjectTopic_Numb = g_reqMonitor_number_array[0] * (g_stopusec/1000000);
int  g_monitor_callback_sumNumber = g_ReqQryMonitorObjectTopic_Numb * 633;
bool g_RspMonitor_Over = false;

struct timeval g_startTime;
struct timeval g_endTime;

bool g_isTestTtn = true;
bool g_isTestReq = false;
bool g_isFirstCallback = true;

// string g_fileName = "test-com-redhat-c-MonitorRsp.txt";
string g_fileName = "test-com-redhat-c-rtn-10000.txt";

string getCurTime();

void resetReqQrySubscriber() {
    if (g_reqNumb == 6) {
        g_testTimeIndex++;

        if (g_testTimeIndex >= g_test_rtn_time_numb) {
            exit(0);
        }
        g_sec = g_sec_array[g_testTimeIndex];
        g_min = g_min_array[g_testTimeIndex];
        g_stopusec = g_min * g_sec * 1000000;
        OutputCallbackMessage("Reset Test Time!", g_RunningResult_File);
        OutputCallbackMessage("g_sec: ", g_sec, g_RunningResult_File);
        OutputCallbackMessage("g_min: ", g_min, g_RunningResult_File);
        g_reqNumb = 1;
    }
    gettimeofday( &g_startTime, NULL );
    OutputCallbackMessage("StartTime:     ", getCurTime(), g_RunningResult_File);

    g_rtn_over = false;
    g_RtnObjectAttrTopic_spi_callbackNumb = 0;
}

void SysUserSpi::OnFrontConnected(){

    g_RunningResult_File.open(g_fileName.c_str(), ios::app|ios::out);

  	if (!g_RunningResult_File) {
  		OutputCallbackMessage("Failed to open running-message.txt", g_RunningResult_File);
  		g_RunningResult_File.close();
  	}

    if ( true == g_isTestTtn) {
      OutputCallbackMessage("********* Test ReqQrySubscriberTopic ************", g_RunningResult_File);
      OutputCallbackMessage("g_rtn_callback_onesec:       ",  g_rtn_callback_onesec, g_RunningResult_File);
      OutputCallbackMessage("g_sec: ", g_sec, g_RunningResult_File);
      OutputCallbackMessage("g_min: ", g_min, g_RunningResult_File);
      OutputCallbackMessage("\n", g_RunningResult_File);

      TestReqQrySubscriberTopic();
    }

    if (true == g_isTestReq) {
      TestReqQryMonitorObjectTopic(g_ReqQryMonitorObjectTopic_Numb);
      // TestReqQryMonitorObjectTopic(1);
    }
}

void SysUserSpi::OnRspQryMonitorObjectTopic(CShfeFtdcRspQryMonitorObjectField* pRspQryMonitorObject, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  ++g_RspQryMonitorObjectTopic_spi_callbackNumb;
  gettimeofday( &g_endTime, NULL );

  if (true == g_isFirstCallback)
  {
    OutputCallbackMessage("********* Test ReqQryMonitorObjectTopic ************", g_RunningResult_File);
    OutputCallbackMessage("g_monitor_callback_sumNumber:       ",  g_monitor_callback_sumNumber, g_RunningResult_File);
    gettimeofday( &g_startTime, NULL );
    OutputCallbackMessage("StartTime:     ", getCurTime(), g_RunningResult_File);
    g_isFirstCallback = false;
  }

  if (g_RspQryMonitorObjectTopic_spi_callbackNumb == g_monitor_callback_sumNumber)
  {
    double costTime = 1000000 * (double)( g_endTime.tv_sec - g_startTime.tv_sec ) + (double)(g_endTime.tv_usec - g_startTime.tv_usec);
    int    dataSize = sizeof(CShfeFtdcRspQryMonitorObjectField) + sizeof (CShfeFtdcRspInfoField) + sizeof(int) + sizeof(bool);

    OutputCallbackMessage("CostTime:      ", costTime/1000000, "s", g_RunningResult_File);
    OutputCallbackMessage("callbackNumb:  ", g_RspQryMonitorObjectTopic_spi_callbackNumb, g_RunningResult_File);
    OutputCallbackMessage("AevCallbkNumb: ", (double)g_RspQryMonitorObjectTopic_spi_callbackNumb / (costTime/1000000), g_RunningResult_File);
    OutputCallbackMessage("bandwidth:     ", dataSize * (double)g_RspQryMonitorObjectTopic_spi_callbackNumb / (costTime/1000000) / 1024 / 1024, " MB/S", g_RunningResult_File);
    g_RunningResult_File << endl; cout << endl;
    OutputCallbackMessage("EndTime:       ", getCurTime(), g_RunningResult_File);
    g_RunningResult_File << endl;cout << endl;

    if (g_test_rsp_monitor_numb_index == g_test_rsp_monitor_numb-1) exit(0);

    g_ReqQryMonitorObjectTopic_Numb = g_reqMonitor_number_array[++g_test_rsp_monitor_numb_index];
    g_monitor_callback_sumNumber = g_ReqQryMonitorObjectTopic_Numb * 633;
    TestReqQryMonitorObjectTopic(g_ReqQryMonitorObjectTopic_Numb);
    g_isFirstCallback = true;
    g_RspQryMonitorObjectTopic_spi_callbackNumb = 0;
  }

  // if (true == g_RspMonitor_Over) return;

  // if (true == bIsLast) {
  //   cout << "Callback Time: " << costTime << " us" << endl;
  //   cout << "g_RspQryMonitorObjectTopic_spi_callbackNumb: " << g_RspQryMonitorObjectTopic_spi_callbackNumb << endl;
  // }

  // if ( costTime > g_stopusec) {
  //   OutputCallbackMessage("Time:          ", g_stopusec/1000000, "s", g_RunningResult_File);
  //   OutputCallbackMessage("callbackNumb:  ", g_RspQryMonitorObjectTopic_spi_callbackNumb, g_RunningResult_File);
  //   OutputCallbackMessage("AevCallbkNumb: ", (double)g_RspQryMonitorObjectTopic_spi_callbackNumb / (g_stopusec/1000000), g_RunningResult_File);
  //   OutputCallbackMessage("data:          ", dataSize * g_RspQryMonitorObjectTopic_spi_callbackNumb, g_RunningResult_File);
  //   OutputCallbackMessage("bandwidth:     ", dataSize * (double)g_RspQryMonitorObjectTopic_spi_callbackNumb / (g_stopusec/1000000) / 1024 / 1024, " MB/S", g_RunningResult_File);
  //   OutputCallbackMessage("SumNumber:     ", 633*g_ReqQryMonitorObjectTopic_Numb, g_RunningResult_File);
  //   g_RunningResult_File << endl; cout << endl;
  //   OutputCallbackMessage("EndTime:       ", getCurTime(), g_RunningResult_File);
  //   g_RunningResult_File << endl;cout << endl;
  //
  //   g_RspMonitor_Over = true;
  //   resetReqQrySubscriber();
  // }

}

void SysUserSpi::OnRtnObjectAttrTopic(CShfeFtdcRtnObjectAttrField *pRtnObjectAttr)
{
  if (true == g_isFirstCallback)
  {
    gettimeofday( &g_startTime, NULL );
    OutputCallbackMessage("StartTime:     ", getCurTime(), g_RunningResult_File);
    g_isFirstCallback = false;
  }

  if (g_rtn_over == true) return;

  ++g_RtnObjectAttrTopic_spi_callbackNumb;
  gettimeofday( &g_endTime, NULL );
  if (1000000 * (double)( g_endTime.tv_sec - g_startTime.tv_sec ) + (double)(g_endTime.tv_usec - g_startTime.tv_usec) > g_stopusec)
  {
    OutputCallbackMessage("Time:          ", g_stopusec/1000000, g_RunningResult_File);
    OutputCallbackMessage("CallbackNumb:  ", g_RtnObjectAttrTopic_spi_callbackNumb, g_RunningResult_File);
    OutputCallbackMessage("AevCallbkNumb: ", (double)g_RtnObjectAttrTopic_spi_callbackNumb / (g_stopusec/1000000), g_RunningResult_File);
    OutputCallbackMessage("Bandwidth:     ", sizeof(CShfeFtdcRtnObjectAttrField) * g_RtnObjectAttrTopic_spi_callbackNumb /(g_stopusec/1000000)/ 1024/1024, "MB/S", g_RunningResult_File);
    OutputCallbackMessage("ReqNumb:       ", g_reqNumb++, g_RunningResult_File);
    g_RunningResult_File << endl; cout << endl;
    OutputCallbackMessage("EndTime:       ", getCurTime(), g_RunningResult_File);

    g_RunningResult_File << endl; cout << endl;
    g_rtn_over = true;
    resetReqQrySubscriber();
  }
}

void SysUserSpi::OnRspQrySysUserLoginTopic(CShfeFtdcRspQrySysUserLoginField* pRspQrySysUserLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQrySysUserLoginTopic: START! ******", g_RunningResult_File);
    //OutputCallbackMessage("g_RspQrySysUserLoginTopic_spi_callbackNumb: ", g_RspQrySysUserLoginTopic_spi_callbackNumb++, g_RunningResult_File);

    if (NULL == pRspQrySysUserLogin) {
        OutputCallbackMessage("pRspQrySysUserLogin:      NULL" , g_RunningResult_File);
    } else {
        OutputCallbackMessage("pRspQrySysUserLogin->UserID:       ", pRspQrySysUserLogin->UserID, g_RunningResult_File);
        OutputCallbackMessage("pRspQrySysUserLogin->TradingDay:   ", pRspQrySysUserLogin->TradingDay, g_RunningResult_File);
        OutputCallbackMessage("pRspQrySysUserLogin->LoginTime:    ", pRspQrySysUserLogin->LoginTime, g_RunningResult_File);
        OutputCallbackMessage("pRspQrySysUserLogin->Privilege:    ", pRspQrySysUserLogin->Privilege, g_RunningResult_File);
        OutputCallbackMessage("pRspQrySysUserLogin->VersionFlag:  ", pRspQrySysUserLogin->VersionFlag, g_RunningResult_File);
    }
	if (NULL != pRspInfo) {
		OutputCallbackMessage("ErrorID:                  ", pRspInfo->ErrorID, g_RunningResult_File);
		OutputCallbackMessage("ErrorMsg:                 ", pRspInfo->ErrorMsg, g_RunningResult_File);
	}
    OutputCallbackMessage("nRequestID:                        ", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:                           ", bIsLast,    g_RunningResult_File);
    OutputCallbackMessage("****** SysUserSpi:: RspQrySysUserLoginTopic: END! ******\n", g_RunningResult_File);
}

string getCurTime()
{
	  time_t t;
    struct tm *pnow = NULL;

    t = time(&t);
    pnow = localtime(&t);

    string curTime = asctime(pnow);
    return curTime;
}

// void SysUserSpi::OnRspQryMonitorObjectTopic(CShfeFtdcRspQryMonitorObjectField* pRspQryMonitorObject, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
// 	OutputCallbackMessage("\n****** SysUserSpi:: RspQryMonitorObjectTopic: START! ******", g_RunningResult_File);
// 	OutputCallbackMessage("callbackNumb:                        ", ++g_RspQryMonitorObjectTopic_spi_callbackNumb, g_RunningResult_File);
//
// 	if (NULL == pRspQryMonitorObject) {
// 		OutputCallbackMessage("pRspQryMonitorObject:        NULL", g_RunningResult_File);
// 	} else {
// 		OutputCallbackMessage("pRspQryMonitorObject->ObjectID:      ", pRspQryMonitorObject->ObjectID, g_RunningResult_File);
// 		OutputCallbackMessage("pRspQryMonitorObject->ObjectName:    ", pRspQryMonitorObject->ObjectName, g_RunningResult_File);
// 		OutputCallbackMessage("pRspQryMonitorObject->WarningActive: ", pRspQryMonitorObject->WarningActive, g_RunningResult_File);
// 	}
// 	if (NULL != pRspInfo) {
// 		OutputCallbackMessage("ErrorID:                  ", pRspInfo->ErrorID, g_RunningResult_File);
// 		OutputCallbackMessage("ErrorMsg:                 ", pRspInfo->ErrorMsg, g_RunningResult_File);
// 	}
// 	OutputCallbackMessage("nRequestID:                          ", nRequestID, g_RunningResult_File);
// 	OutputCallbackMessage("bIsLast:                             ", bIsLast, g_RunningResult_File);
// 	OutputCallbackMessage("****** SysUserSpi:: RspQryMonitorObjectTopic: END! ******\n", g_RunningResult_File);
// }


// void SysUserSpi::OnRtnObjectAttrTopic(CShfeFtdcRtnObjectAttrField *pRtnObjectAttr) {
// 	OutputCallbackMessage("\n****** SysUserSpi:: OnRtnObjectAttrTopic: START! ******", g_RunningResult_File);
// 	OutputCallbackMessage("callbackNumb:                  ", g_RtnObjectAttrTopic_spi_callbackNumb++, g_RunningResult_File);

// 	if (NULL == pRtnObjectAttr) {
// 		OutputCallbackMessage("pRspQryMonitorObject:          NULL", g_RunningResult_File);
// 	} else {
// 		OutputCallbackMessage("pRtnObjectAttr->ObjectID:      ", pRtnObjectAttr->ObjectID, g_RunningResult_File);
// 		OutputCallbackMessage("pRtnObjectAttr->AttrType:      ", pRtnObjectAttr->AttrType, g_RunningResult_File);
// 		OutputCallbackMessage("pRtnObjectAttr->MonDate:       ", pRtnObjectAttr->MonDate, g_RunningResult_File);
// 		OutputCallbackMessage("pRtnObjectAttr->MonTime:       ", pRtnObjectAttr->MonTime, g_RunningResult_File);
// 		OutputCallbackMessage("pRtnObjectAttr->ValueType:     ", pRtnObjectAttr->ValueType, g_RunningResult_File);
// 		OutputCallbackMessage("pRtnObjectAttr->AttrValue:     ", pRtnObjectAttr->AttrValue, g_RunningResult_File);
// 	}
// 	OutputCallbackMessage("****** SysUserSpi:: OnRtnObjectAttrTopic: END! ******\n", g_RunningResult_File);
// }
