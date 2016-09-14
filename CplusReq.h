#ifndef _TESTFUNC_H_
#define _TESTFUNC_H_
#include "FtdcSysUserApi.h"
#include "simplified-sysuserspi.h"
#include <fstream>
using std::fstream;

extern CShfeFtdcSysUserApi* g_pUserApi;
extern SysUserSpi* g_pUserSpi;
extern fstream g_RunningResult_File;

void ConnectToFront(int userNumber = 1) ;

void TestReqQrySysUserLoginTopic(int ReqQrySysUserLoginTopicNumbers = 1);

void TestReqQryMonitorObjectTopic(int ReqQryMonitorObjectTopicNumbers = 1);

void TestReqQrySubscriberTopic();

#endif