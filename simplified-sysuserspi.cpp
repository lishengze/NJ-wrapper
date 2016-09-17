#include "FtdcSysUserApi.h"
#include "tool-function.h"
#include "simplified-sysuserspi.h"
#include "CplusReq.h"
#include <stdlib.h>
#include <string.h>
#include <string>
using std::string;

extern fstream g_RunningResult_File;
extern double g_stopusec;

int g_RspQrySysUserLoginTopic_spi_callbackNumb = 0;
int g_RspQryNetMonitorAttrScopeTopic_spi_callbackNumb = 0;
int g_RspQryMonitorObjectTopic_spi_callbackNumb = 0;
int g_RtnObjectAttrTopic_spi_callbackNumb = 0;

struct timeval g_startTime;
struct timeval g_endTime;

void SysUserSpi::OnFrontConnected(){

    TestReqQrySubscriberTopic();

    gettimeofday( &g_startTime, NULL );

    time_t t;
    struct tm *pnow = NULL;

    t = time(&t);
    pnow = localtime(&t);

    string curTime = asctime(pnow);

    OutputCallbackMessage("StartTime:     ", curTime, g_RunningResult_File);

//   OutputCallbackMessage("\n++++++++++++++ SysUserSpi::OnFrontConnected()+++++++++++++++", g_RunningResult_File);

//   OutputCallbackMessage("\n++++++++++++++ SysUserSpi::OnFrontConnected() SATRT! +++++++++++++++\n", g_RunningResult_File);

//   OutputCallbackMessage("\n++++++++++++++ SysUserSpi::OnFrontConnected() END! +++++++++++++++\n", g_RunningResult_File);
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

void SysUserSpi::OnRspQryMonitorObjectTopic(CShfeFtdcRspQryMonitorObjectField* pRspQryMonitorObject, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	OutputCallbackMessage("\n****** SysUserSpi:: RspQryMonitorObjectTopic: START! ******", g_RunningResult_File);
	OutputCallbackMessage("callbackNumb:                        ", g_RspQryMonitorObjectTopic_spi_callbackNumb++, g_RunningResult_File);

	if (NULL == pRspQryMonitorObject) {
		OutputCallbackMessage("pRspQryMonitorObject:        NULL", g_RunningResult_File);
	} else {
		OutputCallbackMessage("pRspQryMonitorObject->ObjectID:      ", pRspQryMonitorObject->ObjectID, g_RunningResult_File);
		OutputCallbackMessage("pRspQryMonitorObject->ObjectName:    ", pRspQryMonitorObject->ObjectName, g_RunningResult_File);
		OutputCallbackMessage("pRspQryMonitorObject->WarningActive: ", pRspQryMonitorObject->WarningActive, g_RunningResult_File);
	}
	if (NULL != pRspInfo) {
		OutputCallbackMessage("ErrorID:                  ", pRspInfo->ErrorID, g_RunningResult_File);
		OutputCallbackMessage("ErrorMsg:                 ", pRspInfo->ErrorMsg, g_RunningResult_File);
	}
	OutputCallbackMessage("nRequestID:                          ", nRequestID, g_RunningResult_File);
	OutputCallbackMessage("bIsLast:                             ", bIsLast, g_RunningResult_File);
	OutputCallbackMessage("****** SysUserSpi:: RspQryMonitorObjectTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnObjectAttrTopic(CShfeFtdcRtnObjectAttrField *pRtnObjectAttr) {
  ++g_RtnObjectAttrTopic_spi_callbackNumb;
  gettimeofday( &g_endTime, NULL );
  if (1000000 * (double)( g_endTime.tv_sec - g_startTime.tv_sec ) + (double)(g_endTime.tv_usec - g_startTime.tv_usec) > g_stopusec) {
    // cout << "Time: " << g_stopusec << "us callbackNumb: " << g_RtnObjectAttrTopic_spi_callbackNumb
    //      << " data: " << sizeof(CShfeFtdcRtnObjectAttrField) * g_RtnObjectAttrTopic_spi_callbackNumb << " bytes"<< endl;

    OutputCallbackMessage("Time:          ", g_stopusec/1000000, g_RunningResult_File);
    OutputCallbackMessage("callbackNumb:  ", g_RtnObjectAttrTopic_spi_callbackNumb, g_RunningResult_File);
    OutputCallbackMessage("AevCallbkNumb: ", (double)g_RtnObjectAttrTopic_spi_callbackNumb / (g_stopusec/1000000), g_RunningResult_File);
    OutputCallbackMessage("data:          ", sizeof(CShfeFtdcRtnObjectAttrField) * g_RtnObjectAttrTopic_spi_callbackNumb, g_RunningResult_File);
    g_RunningResult_File << endl;
    // OutputCallbackMessage("EndTime:       ", showCurTime(), g_RunningResult_File);

    time_t t;
    struct tm *pnow = NULL;

    t = time(&t);
    pnow = localtime(&t);

    string curTime = asctime(pnow);

//  OutputCallbackMessage("StartTime: ", showCurTime(), g_RunningResult_File);
    OutputCallbackMessage("EndTime:       ", curTime, g_RunningResult_File);
    g_RunningResult_File << endl;
    exit(0);
  }
}


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
