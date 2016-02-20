#ifndef _TESTFUNC_H_
#define _TESTFUNC_H_
#include "FtdcSysUserApi.h"
#include "simplified-sysuserspi.h"

void ConnectToFront(int userNumber = 1) ;

void TestReqQrySysUserLoginTopic(int ReqQrySysUserLoginTopicNumbers = 1);

void TestReqQryNetMonitorAttrScopeTopic(int ReqQryNetMonitorAttrScopeTopicNumbers = 1);

void TestReqQryMonitorObjectTopic(int ReqQryMonitorObjectTopicNumbers = 1);

#endif