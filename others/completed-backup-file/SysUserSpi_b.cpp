#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory.h>
#include "SysUserSpi.h"
#include "SpiCFunc.h"
#include "tool-function.h"
using std::cin;
using std::cout;
using std::endl;
 
extern fstream g_RunningResult_File;
 
void SysUserSpi::OnFrontConnected(){
    OutputCallbackMessage("SysUserSpi::OnFrontConnected()", g_RunningResult_File);
    uv_async_send(&g_FrontConnected_async);
}
 
void SysUserSpi::OnFrontDisConnected(int nReason){
   OutputCallbackMessage("SysUserSpi::OnFrontDisConnected()!", g_RunningResult_File);    
   uv_mutex_lock(&g_FrontDisconnected_mutex);
   g_FrontDisconnected_queue.push(nReason);
   uv_mutex_unlock(&g_FrontDisconnected_mutex);
    
   uv_async_send(&g_FrontDisconnected_async);
}
 
void SysUserSpi::OnHeartBeatWarning(int nTimeLapse){     
   OutputCallbackMessage("SysUserSpi::OnHeartBeatWarning()!", g_RunningResult_File);
    
   uv_mutex_lock(&g_HeartBeatWarning_mutex);
   g_HeartBeatWarning_queue.push(nTimeLapse);
   uv_mutex_unlock(&g_HeartBeatWarning_mutex);

   uv_async_send(&g_HeartBeatWarning_async);
}
 
 //以下自动生成
void SysUserSpi::OnRspQryTopCpuInfoTopic(CShfeFtdcRspQryTopCpuInfoField* pRspQryTopCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryTopCpuInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryTopCpuInfo) { 
        OutputCallbackMessage("pRspQryTopCpuInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryTopCpuInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryTopCpuInfo->HostName: ", pRspQryTopCpuInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopCpuInfo->MonDate: ", pRspQryTopCpuInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopCpuInfo->MonTime: ", pRspQryTopCpuInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopCpuInfo->CPU: ", pRspQryTopCpuInfo->CPU, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopCpuInfo->LOAD: ", pRspQryTopCpuInfo->LOAD, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopCpuInfo->USER: ", pRspQryTopCpuInfo->USER, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopCpuInfo->NICE: ", pRspQryTopCpuInfo->NICE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopCpuInfo->SYS: ", pRspQryTopCpuInfo->SYS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopCpuInfo->IDLE: ", pRspQryTopCpuInfo->IDLE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopCpuInfo->BLOCK: ", pRspQryTopCpuInfo->BLOCK, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopCpuInfo->SWAIT: ", pRspQryTopCpuInfo->SWAIT, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopCpuInfo->INTR: ", pRspQryTopCpuInfo->INTR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopCpuInfo->SSYS: ", pRspQryTopCpuInfo->SSYS, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryTopCpuInfoField* pNewRspQryTopCpuInfo = new CShfeFtdcRspQryTopCpuInfoField;
    memcpy (pNewRspQryTopCpuInfo, pRspQryTopCpuInfo, sizeof(CShfeFtdcRspQryTopCpuInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryTopCpuInfo;

    uv_mutex_lock (&g_RspQryTopCpuInfoTopic_mutex);
    g_RspQryTopCpuInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryTopCpuInfoTopic_mutex);

    uv_async_send(&g_RspQryTopCpuInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryTopCpuInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnTopCpuInfoTopic(CShfeFtdcRtnTopCpuInfoField* pRtnTopCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnTopCpuInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnTopCpuInfo) { 
        OutputCallbackMessage("pRtnTopCpuInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnTopCpuInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnTopCpuInfo->HostName: ", pRtnTopCpuInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopCpuInfo->MonDate: ", pRtnTopCpuInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopCpuInfo->MonTime: ", pRtnTopCpuInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopCpuInfo->CPU: ", pRtnTopCpuInfo->CPU, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopCpuInfo->LOAD: ", pRtnTopCpuInfo->LOAD, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopCpuInfo->USER: ", pRtnTopCpuInfo->USER, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopCpuInfo->NICE: ", pRtnTopCpuInfo->NICE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopCpuInfo->SYS: ", pRtnTopCpuInfo->SYS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopCpuInfo->IDLE: ", pRtnTopCpuInfo->IDLE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopCpuInfo->BLOCK: ", pRtnTopCpuInfo->BLOCK, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopCpuInfo->SWAIT: ", pRtnTopCpuInfo->SWAIT, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopCpuInfo->INTR: ", pRtnTopCpuInfo->INTR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopCpuInfo->SSYS: ", pRtnTopCpuInfo->SSYS, g_RunningResult_File);

    CShfeFtdcRtnTopCpuInfoField* pNewRtnTopCpuInfo = new CShfeFtdcRtnTopCpuInfoField;
    memcpy (pNewRtnTopCpuInfo, pRtnTopCpuInfo, sizeof(CShfeFtdcRtnTopCpuInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnTopCpuInfo;

    uv_mutex_lock (&g_RtnTopCpuInfoTopic_mutex);
    g_RtnTopCpuInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnTopCpuInfoTopic_mutex);

    uv_async_send(&g_RtnTopCpuInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnTopCpuInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryTopMemInfoTopic(CShfeFtdcRspQryTopMemInfoField* pRspQryTopMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryTopMemInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryTopMemInfo) { 
        OutputCallbackMessage("pRspQryTopMemInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryTopMemInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryTopMemInfo->HostName: ", pRspQryTopMemInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopMemInfo->MonDate: ", pRspQryTopMemInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopMemInfo->MonTime: ", pRspQryTopMemInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopMemInfo->TOTALREAL: ", pRspQryTopMemInfo->TOTALREAL, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopMemInfo->ACTIVEREAL: ", pRspQryTopMemInfo->ACTIVEREAL, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopMemInfo->TOTALVIRTUAL: ", pRspQryTopMemInfo->TOTALVIRTUAL, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopMemInfo->ACTIVEVIRTUAL: ", pRspQryTopMemInfo->ACTIVEVIRTUAL, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopMemInfo->FREE: ", pRspQryTopMemInfo->FREE, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryTopMemInfoField* pNewRspQryTopMemInfo = new CShfeFtdcRspQryTopMemInfoField;
    memcpy (pNewRspQryTopMemInfo, pRspQryTopMemInfo, sizeof(CShfeFtdcRspQryTopMemInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryTopMemInfo;

    uv_mutex_lock (&g_RspQryTopMemInfoTopic_mutex);
    g_RspQryTopMemInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryTopMemInfoTopic_mutex);

    uv_async_send(&g_RspQryTopMemInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryTopMemInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnTopMemInfoTopic(CShfeFtdcRtnTopMemInfoField* pRtnTopMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnTopMemInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnTopMemInfo) { 
        OutputCallbackMessage("pRtnTopMemInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnTopMemInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnTopMemInfo->HostName: ", pRtnTopMemInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopMemInfo->MonDate: ", pRtnTopMemInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopMemInfo->MonTime: ", pRtnTopMemInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopMemInfo->TOTALREAL: ", pRtnTopMemInfo->TOTALREAL, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopMemInfo->ACTIVEREAL: ", pRtnTopMemInfo->ACTIVEREAL, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopMemInfo->TOTALVIRTUAL: ", pRtnTopMemInfo->TOTALVIRTUAL, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopMemInfo->ACTIVEVIRTUAL: ", pRtnTopMemInfo->ACTIVEVIRTUAL, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopMemInfo->FREE: ", pRtnTopMemInfo->FREE, g_RunningResult_File);

    CShfeFtdcRtnTopMemInfoField* pNewRtnTopMemInfo = new CShfeFtdcRtnTopMemInfoField;
    memcpy (pNewRtnTopMemInfo, pRtnTopMemInfo, sizeof(CShfeFtdcRtnTopMemInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnTopMemInfo;

    uv_mutex_lock (&g_RtnTopMemInfoTopic_mutex);
    g_RtnTopMemInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnTopMemInfoTopic_mutex);

    uv_async_send(&g_RtnTopMemInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnTopMemInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryTopProcessInfoTopic(CShfeFtdcRspQryTopProcessInfoField* pRspQryTopProcessInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryTopProcessInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryTopProcessInfo) { 
        OutputCallbackMessage("pRspQryTopProcessInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryTopProcessInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryTopProcessInfo->HostName: ", pRspQryTopProcessInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopProcessInfo->MonDate: ", pRspQryTopProcessInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopProcessInfo->MonTime: ", pRspQryTopProcessInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopProcessInfo->CPU: ", pRspQryTopProcessInfo->CPU, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopProcessInfo->TTY: ", pRspQryTopProcessInfo->TTY, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopProcessInfo->PID: ", pRspQryTopProcessInfo->PID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopProcessInfo->USERNAME: ", pRspQryTopProcessInfo->USERNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopProcessInfo->PRI: ", pRspQryTopProcessInfo->PRI, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopProcessInfo->NI: ", pRspQryTopProcessInfo->NI, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopProcessInfo->SIZE: ", pRspQryTopProcessInfo->SIZE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopProcessInfo->RES: ", pRspQryTopProcessInfo->RES, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopProcessInfo->STATE: ", pRspQryTopProcessInfo->STATE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopProcessInfo->TIME: ", pRspQryTopProcessInfo->TIME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopProcessInfo->pWCPU: ", pRspQryTopProcessInfo->pWCPU, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopProcessInfo->pCPU: ", pRspQryTopProcessInfo->pCPU, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTopProcessInfo->COMMAND: ", pRspQryTopProcessInfo->COMMAND, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryTopProcessInfoField* pNewRspQryTopProcessInfo = new CShfeFtdcRspQryTopProcessInfoField;
    memcpy (pNewRspQryTopProcessInfo, pRspQryTopProcessInfo, sizeof(CShfeFtdcRspQryTopProcessInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryTopProcessInfo;

    uv_mutex_lock (&g_RspQryTopProcessInfoTopic_mutex);
    g_RspQryTopProcessInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryTopProcessInfoTopic_mutex);

    uv_async_send(&g_RspQryTopProcessInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryTopProcessInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnTopProcessInfoTopic(CShfeFtdcRtnTopProcessInfoField* pRtnTopProcessInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnTopProcessInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnTopProcessInfo) { 
        OutputCallbackMessage("pRtnTopProcessInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnTopProcessInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnTopProcessInfo->HostName: ", pRtnTopProcessInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopProcessInfo->MonDate: ", pRtnTopProcessInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopProcessInfo->MonTime: ", pRtnTopProcessInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopProcessInfo->CPU: ", pRtnTopProcessInfo->CPU, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopProcessInfo->TTY: ", pRtnTopProcessInfo->TTY, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopProcessInfo->PID: ", pRtnTopProcessInfo->PID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopProcessInfo->USERNAME: ", pRtnTopProcessInfo->USERNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopProcessInfo->PRI: ", pRtnTopProcessInfo->PRI, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopProcessInfo->NI: ", pRtnTopProcessInfo->NI, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopProcessInfo->SIZE: ", pRtnTopProcessInfo->SIZE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopProcessInfo->RES: ", pRtnTopProcessInfo->RES, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopProcessInfo->STATE: ", pRtnTopProcessInfo->STATE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopProcessInfo->TIME: ", pRtnTopProcessInfo->TIME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopProcessInfo->pWCPU: ", pRtnTopProcessInfo->pWCPU, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopProcessInfo->pCPU: ", pRtnTopProcessInfo->pCPU, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTopProcessInfo->COMMAND: ", pRtnTopProcessInfo->COMMAND, g_RunningResult_File);

    CShfeFtdcRtnTopProcessInfoField* pNewRtnTopProcessInfo = new CShfeFtdcRtnTopProcessInfoField;
    memcpy (pNewRtnTopProcessInfo, pRtnTopProcessInfo, sizeof(CShfeFtdcRtnTopProcessInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnTopProcessInfo;

    uv_mutex_lock (&g_RtnTopProcessInfoTopic_mutex);
    g_RtnTopProcessInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnTopProcessInfoTopic_mutex);

    uv_async_send(&g_RtnTopProcessInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnTopProcessInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryFileSystemInfoTopic(CShfeFtdcRspQryFileSystemInfoField* pRspQryFileSystemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryFileSystemInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryFileSystemInfo) { 
        OutputCallbackMessage("pRspQryFileSystemInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryFileSystemInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryFileSystemInfo->HostName: ", pRspQryFileSystemInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileSystemInfo->MonDate: ", pRspQryFileSystemInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileSystemInfo->MonTime: ", pRspQryFileSystemInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileSystemInfo->FILESYSTEM: ", pRspQryFileSystemInfo->FILESYSTEM, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileSystemInfo->SIZE: ", pRspQryFileSystemInfo->SIZE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileSystemInfo->USED: ", pRspQryFileSystemInfo->USED, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileSystemInfo->AVAIL: ", pRspQryFileSystemInfo->AVAIL, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileSystemInfo->pUSERD: ", pRspQryFileSystemInfo->pUSERD, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileSystemInfo->ISIZE: ", pRspQryFileSystemInfo->ISIZE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileSystemInfo->IUSED: ", pRspQryFileSystemInfo->IUSED, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileSystemInfo->IFREE: ", pRspQryFileSystemInfo->IFREE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileSystemInfo->pIUSED: ", pRspQryFileSystemInfo->pIUSED, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileSystemInfo->MountedOn: ", pRspQryFileSystemInfo->MountedOn, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryFileSystemInfoField* pNewRspQryFileSystemInfo = new CShfeFtdcRspQryFileSystemInfoField;
    memcpy (pNewRspQryFileSystemInfo, pRspQryFileSystemInfo, sizeof(CShfeFtdcRspQryFileSystemInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryFileSystemInfo;

    uv_mutex_lock (&g_RspQryFileSystemInfoTopic_mutex);
    g_RspQryFileSystemInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryFileSystemInfoTopic_mutex);

    uv_async_send(&g_RspQryFileSystemInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryFileSystemInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnFileSystemInfoTopic(CShfeFtdcRtnFileSystemInfoField* pRtnFileSystemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnFileSystemInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnFileSystemInfo) { 
        OutputCallbackMessage("pRtnFileSystemInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnFileSystemInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnFileSystemInfo->HostName: ", pRtnFileSystemInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileSystemInfo->MonDate: ", pRtnFileSystemInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileSystemInfo->MonTime: ", pRtnFileSystemInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileSystemInfo->FILESYSTEM: ", pRtnFileSystemInfo->FILESYSTEM, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileSystemInfo->SIZE: ", pRtnFileSystemInfo->SIZE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileSystemInfo->USED: ", pRtnFileSystemInfo->USED, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileSystemInfo->AVAIL: ", pRtnFileSystemInfo->AVAIL, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileSystemInfo->pUSERD: ", pRtnFileSystemInfo->pUSERD, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileSystemInfo->ISIZE: ", pRtnFileSystemInfo->ISIZE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileSystemInfo->IUSED: ", pRtnFileSystemInfo->IUSED, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileSystemInfo->IFREE: ", pRtnFileSystemInfo->IFREE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileSystemInfo->pIUSED: ", pRtnFileSystemInfo->pIUSED, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileSystemInfo->MountedOn: ", pRtnFileSystemInfo->MountedOn, g_RunningResult_File);

    CShfeFtdcRtnFileSystemInfoField* pNewRtnFileSystemInfo = new CShfeFtdcRtnFileSystemInfoField;
    memcpy (pNewRtnFileSystemInfo, pRtnFileSystemInfo, sizeof(CShfeFtdcRtnFileSystemInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnFileSystemInfo;

    uv_mutex_lock (&g_RtnFileSystemInfoTopic_mutex);
    g_RtnFileSystemInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnFileSystemInfoTopic_mutex);

    uv_async_send(&g_RtnFileSystemInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnFileSystemInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetworkInfoTopic(CShfeFtdcRspQryNetworkInfoField* pRspQryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetworkInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetworkInfo) { 
        OutputCallbackMessage("pRspQryNetworkInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetworkInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetworkInfo->HostName: ", pRspQryNetworkInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetworkInfo->MonDate: ", pRspQryNetworkInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetworkInfo->MonTime: ", pRspQryNetworkInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetworkInfo->LANNAME: ", pRspQryNetworkInfo->LANNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetworkInfo->LANSTATUS: ", pRspQryNetworkInfo->LANSTATUS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetworkInfo->IPADDRESS: ", pRspQryNetworkInfo->IPADDRESS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetworkInfo->RECVBYTES: ", pRspQryNetworkInfo->RECVBYTES, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetworkInfo->RECVPACKETS: ", pRspQryNetworkInfo->RECVPACKETS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetworkInfo->RECVERRORPACKETS: ", pRspQryNetworkInfo->RECVERRORPACKETS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetworkInfo->RECVDROPPACKETS: ", pRspQryNetworkInfo->RECVDROPPACKETS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetworkInfo->SENDBYTES: ", pRspQryNetworkInfo->SENDBYTES, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetworkInfo->SENDPACKETS: ", pRspQryNetworkInfo->SENDPACKETS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetworkInfo->SENDERRORPACKETS: ", pRspQryNetworkInfo->SENDERRORPACKETS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetworkInfo->SENDDROPPACKETS: ", pRspQryNetworkInfo->SENDDROPPACKETS, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetworkInfoField* pNewRspQryNetworkInfo = new CShfeFtdcRspQryNetworkInfoField;
    memcpy (pNewRspQryNetworkInfo, pRspQryNetworkInfo, sizeof(CShfeFtdcRspQryNetworkInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetworkInfo;

    uv_mutex_lock (&g_RspQryNetworkInfoTopic_mutex);
    g_RspQryNetworkInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetworkInfoTopic_mutex);

    uv_async_send(&g_RspQryNetworkInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetworkInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetworkInfoTopic(CShfeFtdcRtnNetworkInfoField* pRtnNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetworkInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetworkInfo) { 
        OutputCallbackMessage("pRtnNetworkInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetworkInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetworkInfo->HostName: ", pRtnNetworkInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetworkInfo->MonDate: ", pRtnNetworkInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetworkInfo->MonTime: ", pRtnNetworkInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetworkInfo->LANNAME: ", pRtnNetworkInfo->LANNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetworkInfo->LANSTATUS: ", pRtnNetworkInfo->LANSTATUS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetworkInfo->IPADDRESS: ", pRtnNetworkInfo->IPADDRESS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetworkInfo->RECVBYTES: ", pRtnNetworkInfo->RECVBYTES, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetworkInfo->RECVPACKETS: ", pRtnNetworkInfo->RECVPACKETS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetworkInfo->RECVERRORPACKETS: ", pRtnNetworkInfo->RECVERRORPACKETS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetworkInfo->RECVDROPPACKETS: ", pRtnNetworkInfo->RECVDROPPACKETS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetworkInfo->SENDBYTES: ", pRtnNetworkInfo->SENDBYTES, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetworkInfo->SENDPACKETS: ", pRtnNetworkInfo->SENDPACKETS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetworkInfo->SENDERRORPACKETS: ", pRtnNetworkInfo->SENDERRORPACKETS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetworkInfo->SENDDROPPACKETS: ", pRtnNetworkInfo->SENDDROPPACKETS, g_RunningResult_File);

    CShfeFtdcRtnNetworkInfoField* pNewRtnNetworkInfo = new CShfeFtdcRtnNetworkInfoField;
    memcpy (pNewRtnNetworkInfo, pRtnNetworkInfo, sizeof(CShfeFtdcRtnNetworkInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetworkInfo;

    uv_mutex_lock (&g_RtnNetworkInfoTopic_mutex);
    g_RtnNetworkInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetworkInfoTopic_mutex);

    uv_async_send(&g_RtnNetworkInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetworkInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryClientLoginTopic(CShfeFtdcRspQryClientLoginField* pRspQryClientLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryClientLoginTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryClientLogin) { 
        OutputCallbackMessage("pRspQryClientLogin is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryClientLoginTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryClientLogin->UserName: ", pRspQryClientLogin->UserName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientLogin->Privalage: ", pRspQryClientLogin->Privalage, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryClientLoginField* pNewRspQryClientLogin = new CShfeFtdcRspQryClientLoginField;
    memcpy (pNewRspQryClientLogin, pRspQryClientLogin, sizeof(CShfeFtdcRspQryClientLoginField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryClientLogin;

    uv_mutex_lock (&g_RspQryClientLoginTopic_mutex);
    g_RspQryClientLoginTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryClientLoginTopic_mutex);

    uv_async_send(&g_RspQryClientLoginTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryClientLoginTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryMonitorObjectTopic(CShfeFtdcRspQryMonitorObjectField* pRspQryMonitorObject, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryMonitorObjectTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryMonitorObject) { 
        OutputCallbackMessage("pRspQryMonitorObject is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryMonitorObjectTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryMonitorObject->ObjectID: ", pRspQryMonitorObject->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMonitorObject->ObjectName: ", pRspQryMonitorObject->ObjectName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMonitorObject->WarningActive: ", pRspQryMonitorObject->WarningActive, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryMonitorObjectField* pNewRspQryMonitorObject = new CShfeFtdcRspQryMonitorObjectField;
    memcpy (pNewRspQryMonitorObject, pRspQryMonitorObject, sizeof(CShfeFtdcRspQryMonitorObjectField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryMonitorObject;

    uv_mutex_lock (&g_RspQryMonitorObjectTopic_mutex);
    g_RspQryMonitorObjectTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryMonitorObjectTopic_mutex);

    uv_async_send(&g_RspQryMonitorObjectTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryMonitorObjectTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnMonitorObjectTopic(CShfeFtdcRtnMonitorObjectField* pRtnMonitorObject, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnMonitorObjectTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnMonitorObject) { 
        OutputCallbackMessage("pRtnMonitorObject is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnMonitorObjectTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnMonitorObject->ObjectID: ", pRtnMonitorObject->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorObject->ObjectName: ", pRtnMonitorObject->ObjectName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorObject->WarningActive: ", pRtnMonitorObject->WarningActive, g_RunningResult_File);

    CShfeFtdcRtnMonitorObjectField* pNewRtnMonitorObject = new CShfeFtdcRtnMonitorObjectField;
    memcpy (pNewRtnMonitorObject, pRtnMonitorObject, sizeof(CShfeFtdcRtnMonitorObjectField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnMonitorObject;

    uv_mutex_lock (&g_RtnMonitorObjectTopic_mutex);
    g_RtnMonitorObjectTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnMonitorObjectTopic_mutex);

    uv_async_send(&g_RtnMonitorObjectTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnMonitorObjectTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryObjectRationalTopic(CShfeFtdcRspQryObjectRationalField* pRspQryObjectRational, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryObjectRationalTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryObjectRational) { 
        OutputCallbackMessage("pRspQryObjectRational is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryObjectRationalTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryObjectRational->ObjectID: ", pRspQryObjectRational->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryObjectRational->HostObjectID: ", pRspQryObjectRational->HostObjectID, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryObjectRationalField* pNewRspQryObjectRational = new CShfeFtdcRspQryObjectRationalField;
    memcpy (pNewRspQryObjectRational, pRspQryObjectRational, sizeof(CShfeFtdcRspQryObjectRationalField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryObjectRational;

    uv_mutex_lock (&g_RspQryObjectRationalTopic_mutex);
    g_RspQryObjectRationalTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryObjectRationalTopic_mutex);

    uv_async_send(&g_RspQryObjectRationalTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryObjectRationalTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnObjectRationalTopic(CShfeFtdcRtnObjectRationalField* pRtnObjectRational, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnObjectRationalTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnObjectRational) { 
        OutputCallbackMessage("pRtnObjectRational is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnObjectRationalTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnObjectRational->ObjectID: ", pRtnObjectRational->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnObjectRational->HostObjectID: ", pRtnObjectRational->HostObjectID, g_RunningResult_File);

    CShfeFtdcRtnObjectRationalField* pNewRtnObjectRational = new CShfeFtdcRtnObjectRationalField;
    memcpy (pNewRtnObjectRational, pRtnObjectRational, sizeof(CShfeFtdcRtnObjectRationalField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnObjectRational;

    uv_mutex_lock (&g_RtnObjectRationalTopic_mutex);
    g_RtnObjectRationalTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnObjectRationalTopic_mutex);

    uv_async_send(&g_RtnObjectRationalTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnObjectRationalTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQrySyslogInfoTopic(CShfeFtdcRspQrySyslogInfoField* pRspQrySyslogInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQrySyslogInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQrySyslogInfo) { 
        OutputCallbackMessage("pRspQrySyslogInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQrySyslogInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQrySyslogInfo->MonDate: ", pRspQrySyslogInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogInfo->MonTime: ", pRspQrySyslogInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogInfo->ObjectID: ", pRspQrySyslogInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogInfo->AttrType: ", pRspQrySyslogInfo->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogInfo->ContLen: ", pRspQrySyslogInfo->ContLen, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogInfo->FileContent: ", pRspQrySyslogInfo->FileContent, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQrySyslogInfoField* pNewRspQrySyslogInfo = new CShfeFtdcRspQrySyslogInfoField;
    memcpy (pNewRspQrySyslogInfo, pRspQrySyslogInfo, sizeof(CShfeFtdcRspQrySyslogInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQrySyslogInfo;

    uv_mutex_lock (&g_RspQrySyslogInfoTopic_mutex);
    g_RspQrySyslogInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQrySyslogInfoTopic_mutex);

    uv_async_send(&g_RspQrySyslogInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQrySyslogInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnSyslogInfoTopic(CShfeFtdcRtnSyslogInfoField* pRtnSyslogInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnSyslogInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnSyslogInfo) { 
        OutputCallbackMessage("pRtnSyslogInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnSyslogInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnSyslogInfo->MonDate: ", pRtnSyslogInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogInfo->MonTime: ", pRtnSyslogInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogInfo->ObjectID: ", pRtnSyslogInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogInfo->AttrType: ", pRtnSyslogInfo->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogInfo->ContLen: ", pRtnSyslogInfo->ContLen, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogInfo->FileContent: ", pRtnSyslogInfo->FileContent, g_RunningResult_File);

    CShfeFtdcRtnSyslogInfoField* pNewRtnSyslogInfo = new CShfeFtdcRtnSyslogInfoField;
    memcpy (pNewRtnSyslogInfo, pRtnSyslogInfo, sizeof(CShfeFtdcRtnSyslogInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnSyslogInfo;

    uv_mutex_lock (&g_RtnSyslogInfoTopic_mutex);
    g_RtnSyslogInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnSyslogInfoTopic_mutex);

    uv_async_send(&g_RtnSyslogInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnSyslogInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQrySubscriberTopic(CShfeFtdcRspQrySubscriberField* pRspQrySubscriber, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQrySubscriberTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQrySubscriber) { 
        OutputCallbackMessage("pRspQrySubscriber is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQrySubscriberTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQrySubscriber->ErrorID: ", pRspQrySubscriber->ErrorID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySubscriber->ErrorMsg: ", pRspQrySubscriber->ErrorMsg, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySubscriber->ObjectID: ", pRspQrySubscriber->ObjectID, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQrySubscriberField* pNewRspQrySubscriber = new CShfeFtdcRspQrySubscriberField;
    memcpy (pNewRspQrySubscriber, pRspQrySubscriber, sizeof(CShfeFtdcRspQrySubscriberField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQrySubscriber;

    uv_mutex_lock (&g_RspQrySubscriberTopic_mutex);
    g_RspQrySubscriberTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQrySubscriberTopic_mutex);

    uv_async_send(&g_RspQrySubscriberTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQrySubscriberTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryOidRelationTopic(CShfeFtdcRspQryOidRelationField* pRspQryOidRelation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryOidRelationTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryOidRelation) { 
        OutputCallbackMessage("pRspQryOidRelation is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryOidRelationTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryOidRelation->ObjectID: ", pRspQryOidRelation->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOidRelation->HoldObjectID: ", pRspQryOidRelation->HoldObjectID, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryOidRelationField* pNewRspQryOidRelation = new CShfeFtdcRspQryOidRelationField;
    memcpy (pNewRspQryOidRelation, pRspQryOidRelation, sizeof(CShfeFtdcRspQryOidRelationField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryOidRelation;

    uv_mutex_lock (&g_RspQryOidRelationTopic_mutex);
    g_RspQryOidRelationTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryOidRelationTopic_mutex);

    uv_async_send(&g_RspQryOidRelationTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryOidRelationTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnOidRelationTopic(CShfeFtdcRtnOidRelationField* pRtnOidRelation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnOidRelationTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnOidRelation) { 
        OutputCallbackMessage("pRtnOidRelation is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnOidRelationTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnOidRelation->ObjectID: ", pRtnOidRelation->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOidRelation->HoldObjectID: ", pRtnOidRelation->HoldObjectID, g_RunningResult_File);

    CShfeFtdcRtnOidRelationField* pNewRtnOidRelation = new CShfeFtdcRtnOidRelationField;
    memcpy (pNewRtnOidRelation, pRtnOidRelation, sizeof(CShfeFtdcRtnOidRelationField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnOidRelation;

    uv_mutex_lock (&g_RtnOidRelationTopic_mutex);
    g_RtnOidRelationTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnOidRelationTopic_mutex);

    uv_async_send(&g_RtnOidRelationTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnOidRelationTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryUserInfoTopic(CShfeFtdcRspQryUserInfoField* pRspQryUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryUserInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryUserInfo) { 
        OutputCallbackMessage("pRspQryUserInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryUserInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryUserInfo->USERNAME: ", pRspQryUserInfo->USERNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserInfo->USERID: ", pRspQryUserInfo->USERID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserInfo->GROUPNAME: ", pRspQryUserInfo->GROUPNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserInfo->GROUPID: ", pRspQryUserInfo->GROUPID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserInfo->HOMEPATH: ", pRspQryUserInfo->HOMEPATH, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserInfo->SHELL: ", pRspQryUserInfo->SHELL, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserInfo->ObjectID: ", pRspQryUserInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserInfo->MonTime: ", pRspQryUserInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserInfo->MonDate: ", pRspQryUserInfo->MonDate, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryUserInfoField* pNewRspQryUserInfo = new CShfeFtdcRspQryUserInfoField;
    memcpy (pNewRspQryUserInfo, pRspQryUserInfo, sizeof(CShfeFtdcRspQryUserInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryUserInfo;

    uv_mutex_lock (&g_RspQryUserInfoTopic_mutex);
    g_RspQryUserInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryUserInfoTopic_mutex);

    uv_async_send(&g_RspQryUserInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryUserInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnUserInfoTopic(CShfeFtdcRtnUserInfoField* pRtnUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnUserInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnUserInfo) { 
        OutputCallbackMessage("pRtnUserInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnUserInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnUserInfo->USERNAME: ", pRtnUserInfo->USERNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserInfo->USERID: ", pRtnUserInfo->USERID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserInfo->GROUPNAME: ", pRtnUserInfo->GROUPNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserInfo->GROUPID: ", pRtnUserInfo->GROUPID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserInfo->HOMEPATH: ", pRtnUserInfo->HOMEPATH, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserInfo->SHELL: ", pRtnUserInfo->SHELL, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserInfo->ObjectID: ", pRtnUserInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserInfo->MonTime: ", pRtnUserInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserInfo->MonDate: ", pRtnUserInfo->MonDate, g_RunningResult_File);

    CShfeFtdcRtnUserInfoField* pNewRtnUserInfo = new CShfeFtdcRtnUserInfoField;
    memcpy (pNewRtnUserInfo, pRtnUserInfo, sizeof(CShfeFtdcRtnUserInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnUserInfo;

    uv_mutex_lock (&g_RtnUserInfoTopic_mutex);
    g_RtnUserInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnUserInfoTopic_mutex);

    uv_async_send(&g_RtnUserInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnUserInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryOnlineUserInfoTopic(CShfeFtdcRspQryOnlineUserInfoField* pRspQryOnlineUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryOnlineUserInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryOnlineUserInfo) { 
        OutputCallbackMessage("pRspQryOnlineUserInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryOnlineUserInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryOnlineUserInfo->USERNAME: ", pRspQryOnlineUserInfo->USERNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOnlineUserInfo->TIME: ", pRspQryOnlineUserInfo->TIME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOnlineUserInfo->TTY: ", pRspQryOnlineUserInfo->TTY, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOnlineUserInfo->IP: ", pRspQryOnlineUserInfo->IP, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOnlineUserInfo->CONNECTIME: ", pRspQryOnlineUserInfo->CONNECTIME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOnlineUserInfo->PID: ", pRspQryOnlineUserInfo->PID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOnlineUserInfo->ObjectID: ", pRspQryOnlineUserInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOnlineUserInfo->MonTime: ", pRspQryOnlineUserInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOnlineUserInfo->MonDate: ", pRspQryOnlineUserInfo->MonDate, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryOnlineUserInfoField* pNewRspQryOnlineUserInfo = new CShfeFtdcRspQryOnlineUserInfoField;
    memcpy (pNewRspQryOnlineUserInfo, pRspQryOnlineUserInfo, sizeof(CShfeFtdcRspQryOnlineUserInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryOnlineUserInfo;

    uv_mutex_lock (&g_RspQryOnlineUserInfoTopic_mutex);
    g_RspQryOnlineUserInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryOnlineUserInfoTopic_mutex);

    uv_async_send(&g_RspQryOnlineUserInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryOnlineUserInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnOnlineUserInfoTopic(CShfeFtdcRtnOnlineUserInfoField* pRtnOnlineUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnOnlineUserInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnOnlineUserInfo) { 
        OutputCallbackMessage("pRtnOnlineUserInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnOnlineUserInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnOnlineUserInfo->USERNAME: ", pRtnOnlineUserInfo->USERNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOnlineUserInfo->TIME: ", pRtnOnlineUserInfo->TIME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOnlineUserInfo->TTY: ", pRtnOnlineUserInfo->TTY, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOnlineUserInfo->IP: ", pRtnOnlineUserInfo->IP, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOnlineUserInfo->CONNECTIME: ", pRtnOnlineUserInfo->CONNECTIME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOnlineUserInfo->PID: ", pRtnOnlineUserInfo->PID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOnlineUserInfo->ObjectID: ", pRtnOnlineUserInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOnlineUserInfo->MonTime: ", pRtnOnlineUserInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOnlineUserInfo->MonDate: ", pRtnOnlineUserInfo->MonDate, g_RunningResult_File);

    CShfeFtdcRtnOnlineUserInfoField* pNewRtnOnlineUserInfo = new CShfeFtdcRtnOnlineUserInfoField;
    memcpy (pNewRtnOnlineUserInfo, pRtnOnlineUserInfo, sizeof(CShfeFtdcRtnOnlineUserInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnOnlineUserInfo;

    uv_mutex_lock (&g_RtnOnlineUserInfoTopic_mutex);
    g_RtnOnlineUserInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnOnlineUserInfoTopic_mutex);

    uv_async_send(&g_RtnOnlineUserInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnOnlineUserInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryWarningEventTopic(CShfeFtdcRspQryWarningEventField* pRspQryWarningEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryWarningEventTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryWarningEvent) { 
        OutputCallbackMessage("pRspQryWarningEvent is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryWarningEventTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryWarningEvent->MonDate: ", pRspQryWarningEvent->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningEvent->MonTime: ", pRspQryWarningEvent->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningEvent->OccurDate: ", pRspQryWarningEvent->OccurDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningEvent->OccurTime: ", pRspQryWarningEvent->OccurTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningEvent->EvendID: ", pRspQryWarningEvent->EvendID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningEvent->ObjectID: ", pRspQryWarningEvent->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningEvent->IPAddress: ", pRspQryWarningEvent->IPAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningEvent->EventName: ", pRspQryWarningEvent->EventName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningEvent->EventNum: ", pRspQryWarningEvent->EventNum, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningEvent->EventType: ", pRspQryWarningEvent->EventType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningEvent->EventDes: ", pRspQryWarningEvent->EventDes, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningEvent->ProcessFlag: ", pRspQryWarningEvent->ProcessFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningEvent->WarningLevel: ", pRspQryWarningEvent->WarningLevel, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningEvent->EventDealDes: ", pRspQryWarningEvent->EventDealDes, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningEvent->FullEventName: ", pRspQryWarningEvent->FullEventName, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryWarningEventField* pNewRspQryWarningEvent = new CShfeFtdcRspQryWarningEventField;
    memcpy (pNewRspQryWarningEvent, pRspQryWarningEvent, sizeof(CShfeFtdcRspQryWarningEventField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryWarningEvent;

    uv_mutex_lock (&g_RspQryWarningEventTopic_mutex);
    g_RspQryWarningEventTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryWarningEventTopic_mutex);

    uv_async_send(&g_RspQryWarningEventTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryWarningEventTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnWarningEventTopic(CShfeFtdcRtnWarningEventField* pRtnWarningEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnWarningEventTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnWarningEvent) { 
        OutputCallbackMessage("pRtnWarningEvent is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnWarningEventTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnWarningEvent->MonDate: ", pRtnWarningEvent->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningEvent->MonTime: ", pRtnWarningEvent->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningEvent->OccurDate: ", pRtnWarningEvent->OccurDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningEvent->OccurTime: ", pRtnWarningEvent->OccurTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningEvent->EvendID: ", pRtnWarningEvent->EvendID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningEvent->ObjectID: ", pRtnWarningEvent->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningEvent->IPAddress: ", pRtnWarningEvent->IPAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningEvent->EventName: ", pRtnWarningEvent->EventName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningEvent->EventNum: ", pRtnWarningEvent->EventNum, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningEvent->EventType: ", pRtnWarningEvent->EventType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningEvent->EventDes: ", pRtnWarningEvent->EventDes, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningEvent->ProcessFlag: ", pRtnWarningEvent->ProcessFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningEvent->WarningLevel: ", pRtnWarningEvent->WarningLevel, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningEvent->EventDealDes: ", pRtnWarningEvent->EventDealDes, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningEvent->FullEventName: ", pRtnWarningEvent->FullEventName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningEvent->EventCount: ", pRtnWarningEvent->EventCount, g_RunningResult_File);

    CShfeFtdcRtnWarningEventField* pNewRtnWarningEvent = new CShfeFtdcRtnWarningEventField;
    memcpy (pNewRtnWarningEvent, pRtnWarningEvent, sizeof(CShfeFtdcRtnWarningEventField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnWarningEvent;

    uv_mutex_lock (&g_RtnWarningEventTopic_mutex);
    g_RtnWarningEventTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnWarningEventTopic_mutex);

    uv_async_send(&g_RtnWarningEventTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnWarningEventTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryCPUUsageTopic(CShfeFtdcRspQryCPUUsageField* pRspQryCPUUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryCPUUsageTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryCPUUsage) { 
        OutputCallbackMessage("pRspQryCPUUsage is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryCPUUsageTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryCPUUsage->ObjectID: ", pRspQryCPUUsage->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryCPUUsage->MonDate: ", pRspQryCPUUsage->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryCPUUsage->MonTime: ", pRspQryCPUUsage->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryCPUUsage->CPUUsage: ", pRspQryCPUUsage->CPUUsage, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryCPUUsageField* pNewRspQryCPUUsage = new CShfeFtdcRspQryCPUUsageField;
    memcpy (pNewRspQryCPUUsage, pRspQryCPUUsage, sizeof(CShfeFtdcRspQryCPUUsageField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryCPUUsage;

    uv_mutex_lock (&g_RspQryCPUUsageTopic_mutex);
    g_RspQryCPUUsageTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryCPUUsageTopic_mutex);

    uv_async_send(&g_RspQryCPUUsageTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryCPUUsageTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnCPUUsageTopic(CShfeFtdcRtnCPUUsageField* pRtnCPUUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnCPUUsageTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnCPUUsage) { 
        OutputCallbackMessage("pRtnCPUUsage is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnCPUUsageTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnCPUUsage->ObjectID: ", pRtnCPUUsage->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnCPUUsage->MonDate: ", pRtnCPUUsage->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnCPUUsage->MonTime: ", pRtnCPUUsage->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnCPUUsage->CPUUsage: ", pRtnCPUUsage->CPUUsage, g_RunningResult_File);

    CShfeFtdcRtnCPUUsageField* pNewRtnCPUUsage = new CShfeFtdcRtnCPUUsageField;
    memcpy (pNewRtnCPUUsage, pRtnCPUUsage, sizeof(CShfeFtdcRtnCPUUsageField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnCPUUsage;

    uv_mutex_lock (&g_RtnCPUUsageTopic_mutex);
    g_RtnCPUUsageTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnCPUUsageTopic_mutex);

    uv_async_send(&g_RtnCPUUsageTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnCPUUsageTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryMemoryUsageTopic(CShfeFtdcRspQryMemoryUsageField* pRspQryMemoryUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryMemoryUsageTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryMemoryUsage) { 
        OutputCallbackMessage("pRspQryMemoryUsage is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryMemoryUsageTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryMemoryUsage->ObjectID: ", pRspQryMemoryUsage->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemoryUsage->MonDate: ", pRspQryMemoryUsage->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemoryUsage->MonTime: ", pRspQryMemoryUsage->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemoryUsage->MemoryUsage: ", pRspQryMemoryUsage->MemoryUsage, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryMemoryUsageField* pNewRspQryMemoryUsage = new CShfeFtdcRspQryMemoryUsageField;
    memcpy (pNewRspQryMemoryUsage, pRspQryMemoryUsage, sizeof(CShfeFtdcRspQryMemoryUsageField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryMemoryUsage;

    uv_mutex_lock (&g_RspQryMemoryUsageTopic_mutex);
    g_RspQryMemoryUsageTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryMemoryUsageTopic_mutex);

    uv_async_send(&g_RspQryMemoryUsageTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryMemoryUsageTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnMemoryUsageTopic(CShfeFtdcRtnMemoryUsageField* pRtnMemoryUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnMemoryUsageTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnMemoryUsage) { 
        OutputCallbackMessage("pRtnMemoryUsage is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnMemoryUsageTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnMemoryUsage->ObjectID: ", pRtnMemoryUsage->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemoryUsage->MonDate: ", pRtnMemoryUsage->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemoryUsage->MonTime: ", pRtnMemoryUsage->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemoryUsage->MemoryUsage: ", pRtnMemoryUsage->MemoryUsage, g_RunningResult_File);

    CShfeFtdcRtnMemoryUsageField* pNewRtnMemoryUsage = new CShfeFtdcRtnMemoryUsageField;
    memcpy (pNewRtnMemoryUsage, pRtnMemoryUsage, sizeof(CShfeFtdcRtnMemoryUsageField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnMemoryUsage;

    uv_mutex_lock (&g_RtnMemoryUsageTopic_mutex);
    g_RtnMemoryUsageTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnMemoryUsageTopic_mutex);

    uv_async_send(&g_RtnMemoryUsageTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnMemoryUsageTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryDiskUsageTopic(CShfeFtdcRspQryDiskUsageField* pRspQryDiskUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryDiskUsageTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryDiskUsage) { 
        OutputCallbackMessage("pRspQryDiskUsage is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryDiskUsageTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryDiskUsage->ObjectID: ", pRspQryDiskUsage->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDiskUsage->MonDate: ", pRspQryDiskUsage->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDiskUsage->MonTime: ", pRspQryDiskUsage->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDiskUsage->DiskUsage: ", pRspQryDiskUsage->DiskUsage, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryDiskUsageField* pNewRspQryDiskUsage = new CShfeFtdcRspQryDiskUsageField;
    memcpy (pNewRspQryDiskUsage, pRspQryDiskUsage, sizeof(CShfeFtdcRspQryDiskUsageField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryDiskUsage;

    uv_mutex_lock (&g_RspQryDiskUsageTopic_mutex);
    g_RspQryDiskUsageTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryDiskUsageTopic_mutex);

    uv_async_send(&g_RspQryDiskUsageTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryDiskUsageTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnDiskUsageTopic(CShfeFtdcRtnDiskUsageField* pRtnDiskUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnDiskUsageTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnDiskUsage) { 
        OutputCallbackMessage("pRtnDiskUsage is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnDiskUsageTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnDiskUsage->ObjectID: ", pRtnDiskUsage->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDiskUsage->MonDate: ", pRtnDiskUsage->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDiskUsage->MonTime: ", pRtnDiskUsage->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDiskUsage->DiskUsage: ", pRtnDiskUsage->DiskUsage, g_RunningResult_File);

    CShfeFtdcRtnDiskUsageField* pNewRtnDiskUsage = new CShfeFtdcRtnDiskUsageField;
    memcpy (pNewRtnDiskUsage, pRtnDiskUsage, sizeof(CShfeFtdcRtnDiskUsageField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnDiskUsage;

    uv_mutex_lock (&g_RtnDiskUsageTopic_mutex);
    g_RtnDiskUsageTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnDiskUsageTopic_mutex);

    uv_async_send(&g_RtnDiskUsageTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnDiskUsageTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryObjectAttrTopic(CShfeFtdcRspQryObjectAttrField* pRspQryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryObjectAttrTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryObjectAttr) { 
        OutputCallbackMessage("pRspQryObjectAttr is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryObjectAttrTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryObjectAttr->ObjectID: ", pRspQryObjectAttr->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryObjectAttr->AttrType: ", pRspQryObjectAttr->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryObjectAttr->MonDate: ", pRspQryObjectAttr->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryObjectAttr->MonTime: ", pRspQryObjectAttr->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryObjectAttr->ValueType: ", pRspQryObjectAttr->ValueType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryObjectAttr->AttrValue: ", pRspQryObjectAttr->AttrValue, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryObjectAttrField* pNewRspQryObjectAttr = new CShfeFtdcRspQryObjectAttrField;
    memcpy (pNewRspQryObjectAttr, pRspQryObjectAttr, sizeof(CShfeFtdcRspQryObjectAttrField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryObjectAttr;

    uv_mutex_lock (&g_RspQryObjectAttrTopic_mutex);
    g_RspQryObjectAttrTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryObjectAttrTopic_mutex);

    uv_async_send(&g_RspQryObjectAttrTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryObjectAttrTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnObjectAttrTopic(CShfeFtdcRtnObjectAttrField* pRtnObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnObjectAttrTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnObjectAttr) { 
        OutputCallbackMessage("pRtnObjectAttr is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnObjectAttrTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnObjectAttr->ObjectID: ", pRtnObjectAttr->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnObjectAttr->AttrType: ", pRtnObjectAttr->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnObjectAttr->MonDate: ", pRtnObjectAttr->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnObjectAttr->MonTime: ", pRtnObjectAttr->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnObjectAttr->ValueType: ", pRtnObjectAttr->ValueType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnObjectAttr->AttrValue: ", pRtnObjectAttr->AttrValue, g_RunningResult_File);

    CShfeFtdcRtnObjectAttrField* pNewRtnObjectAttr = new CShfeFtdcRtnObjectAttrField;
    memcpy (pNewRtnObjectAttr, pRtnObjectAttr, sizeof(CShfeFtdcRtnObjectAttrField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnObjectAttr;

    uv_mutex_lock (&g_RtnObjectAttrTopic_mutex);
    g_RtnObjectAttrTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnObjectAttrTopic_mutex);

    uv_async_send(&g_RtnObjectAttrTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnObjectAttrTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryInvalidateOrderTopic(CShfeFtdcRspQryInvalidateOrderField* pRspQryInvalidateOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryInvalidateOrderTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryInvalidateOrder) { 
        OutputCallbackMessage("pRspQryInvalidateOrder is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryInvalidateOrderTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryInvalidateOrder->OrderSysID: ", pRspQryInvalidateOrder->OrderSysID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInvalidateOrder->OrderLocalID: ", pRspQryInvalidateOrder->OrderLocalID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInvalidateOrder->ActionDate: ", pRspQryInvalidateOrder->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInvalidateOrder->ActionTime: ", pRspQryInvalidateOrder->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInvalidateOrder->ErrorMsg: ", pRspQryInvalidateOrder->ErrorMsg, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInvalidateOrder->ParticipantID: ", pRspQryInvalidateOrder->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInvalidateOrder->UserID: ", pRspQryInvalidateOrder->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInvalidateOrder->ClientID: ", pRspQryInvalidateOrder->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInvalidateOrder->InstrumentID: ", pRspQryInvalidateOrder->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInvalidateOrder->Direction: ", pRspQryInvalidateOrder->Direction, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInvalidateOrder->CombOffsetFlag: ", pRspQryInvalidateOrder->CombOffsetFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInvalidateOrder->CombHedgeFlag: ", pRspQryInvalidateOrder->CombHedgeFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInvalidateOrder->LimitPrice: ", pRspQryInvalidateOrder->LimitPrice, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInvalidateOrder->VolumeTotalOriginal: ", pRspQryInvalidateOrder->VolumeTotalOriginal, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInvalidateOrder->TimeCondition: ", pRspQryInvalidateOrder->TimeCondition, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInvalidateOrder->VolumeCondition: ", pRspQryInvalidateOrder->VolumeCondition, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInvalidateOrder->MinVolume: ", pRspQryInvalidateOrder->MinVolume, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryInvalidateOrderField* pNewRspQryInvalidateOrder = new CShfeFtdcRspQryInvalidateOrderField;
    memcpy (pNewRspQryInvalidateOrder, pRspQryInvalidateOrder, sizeof(CShfeFtdcRspQryInvalidateOrderField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryInvalidateOrder;

    uv_mutex_lock (&g_RspQryInvalidateOrderTopic_mutex);
    g_RspQryInvalidateOrderTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryInvalidateOrderTopic_mutex);

    uv_async_send(&g_RspQryInvalidateOrderTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryInvalidateOrderTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnInvalidateOrderTopic(CShfeFtdcRtnInvalidateOrderField* pRtnInvalidateOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnInvalidateOrderTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnInvalidateOrder) { 
        OutputCallbackMessage("pRtnInvalidateOrder is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnInvalidateOrderTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnInvalidateOrder->OrderSysID: ", pRtnInvalidateOrder->OrderSysID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInvalidateOrder->OrderLocalID: ", pRtnInvalidateOrder->OrderLocalID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInvalidateOrder->ActionDate: ", pRtnInvalidateOrder->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInvalidateOrder->ActionTime: ", pRtnInvalidateOrder->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInvalidateOrder->ErrorMsg: ", pRtnInvalidateOrder->ErrorMsg, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInvalidateOrder->ParticipantID: ", pRtnInvalidateOrder->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInvalidateOrder->UserID: ", pRtnInvalidateOrder->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInvalidateOrder->ClientID: ", pRtnInvalidateOrder->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInvalidateOrder->InstrumentID: ", pRtnInvalidateOrder->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInvalidateOrder->Direction: ", pRtnInvalidateOrder->Direction, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInvalidateOrder->CombOffsetFlag: ", pRtnInvalidateOrder->CombOffsetFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInvalidateOrder->CombHedgeFlag: ", pRtnInvalidateOrder->CombHedgeFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInvalidateOrder->LimitPrice: ", pRtnInvalidateOrder->LimitPrice, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInvalidateOrder->VolumeTotalOriginal: ", pRtnInvalidateOrder->VolumeTotalOriginal, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInvalidateOrder->TimeCondition: ", pRtnInvalidateOrder->TimeCondition, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInvalidateOrder->VolumeCondition: ", pRtnInvalidateOrder->VolumeCondition, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInvalidateOrder->MinVolume: ", pRtnInvalidateOrder->MinVolume, g_RunningResult_File);

    CShfeFtdcRtnInvalidateOrderField* pNewRtnInvalidateOrder = new CShfeFtdcRtnInvalidateOrderField;
    memcpy (pNewRtnInvalidateOrder, pRtnInvalidateOrder, sizeof(CShfeFtdcRtnInvalidateOrderField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnInvalidateOrder;

    uv_mutex_lock (&g_RtnInvalidateOrderTopic_mutex);
    g_RtnInvalidateOrderTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnInvalidateOrderTopic_mutex);

    uv_async_send(&g_RtnInvalidateOrderTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnInvalidateOrderTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryOrderStatusTopic(CShfeFtdcRspQryOrderStatusField* pRspQryOrderStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryOrderStatusTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryOrderStatus) { 
        OutputCallbackMessage("pRspQryOrderStatus is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryOrderStatusTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryOrderStatus->ActionDate: ", pRspQryOrderStatus->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->ActionTime: ", pRspQryOrderStatus->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->OrderSysID: ", pRspQryOrderStatus->OrderSysID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->OrderLocalID: ", pRspQryOrderStatus->OrderLocalID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->InsertDate: ", pRspQryOrderStatus->InsertDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->InsertTime: ", pRspQryOrderStatus->InsertTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->OrderStatus: ", pRspQryOrderStatus->OrderStatus, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->ParticipantID: ", pRspQryOrderStatus->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->UserID: ", pRspQryOrderStatus->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->ClientID: ", pRspQryOrderStatus->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->InstrumentID: ", pRspQryOrderStatus->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->Direction: ", pRspQryOrderStatus->Direction, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->CombOffsetFlag: ", pRspQryOrderStatus->CombOffsetFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->CombHedgeFlag: ", pRspQryOrderStatus->CombHedgeFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->LimitPrice: ", pRspQryOrderStatus->LimitPrice, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->VolumeTotalOriginal: ", pRspQryOrderStatus->VolumeTotalOriginal, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->TimeCondition: ", pRspQryOrderStatus->TimeCondition, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->VolumeCondition: ", pRspQryOrderStatus->VolumeCondition, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOrderStatus->MinVolume: ", pRspQryOrderStatus->MinVolume, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryOrderStatusField* pNewRspQryOrderStatus = new CShfeFtdcRspQryOrderStatusField;
    memcpy (pNewRspQryOrderStatus, pRspQryOrderStatus, sizeof(CShfeFtdcRspQryOrderStatusField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryOrderStatus;

    uv_mutex_lock (&g_RspQryOrderStatusTopic_mutex);
    g_RspQryOrderStatusTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryOrderStatusTopic_mutex);

    uv_async_send(&g_RspQryOrderStatusTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryOrderStatusTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnOrderStatusTopic(CShfeFtdcRtnOrderStatusField* pRtnOrderStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnOrderStatusTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnOrderStatus) { 
        OutputCallbackMessage("pRtnOrderStatus is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnOrderStatusTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnOrderStatus->ActionDate: ", pRtnOrderStatus->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->ActionTime: ", pRtnOrderStatus->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->OrderSysID: ", pRtnOrderStatus->OrderSysID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->OrderLocalID: ", pRtnOrderStatus->OrderLocalID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->InsertDate: ", pRtnOrderStatus->InsertDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->InsertTime: ", pRtnOrderStatus->InsertTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->OrderStatus: ", pRtnOrderStatus->OrderStatus, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->ParticipantID: ", pRtnOrderStatus->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->UserID: ", pRtnOrderStatus->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->ClientID: ", pRtnOrderStatus->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->InstrumentID: ", pRtnOrderStatus->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->Direction: ", pRtnOrderStatus->Direction, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->CombOffsetFlag: ", pRtnOrderStatus->CombOffsetFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->CombHedgeFlag: ", pRtnOrderStatus->CombHedgeFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->LimitPrice: ", pRtnOrderStatus->LimitPrice, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->VolumeTotalOriginal: ", pRtnOrderStatus->VolumeTotalOriginal, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->TimeCondition: ", pRtnOrderStatus->TimeCondition, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->VolumeCondition: ", pRtnOrderStatus->VolumeCondition, g_RunningResult_File);
    OutputCallbackMessage(" pRtnOrderStatus->MinVolume: ", pRtnOrderStatus->MinVolume, g_RunningResult_File);

    CShfeFtdcRtnOrderStatusField* pNewRtnOrderStatus = new CShfeFtdcRtnOrderStatusField;
    memcpy (pNewRtnOrderStatus, pRtnOrderStatus, sizeof(CShfeFtdcRtnOrderStatusField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnOrderStatus;

    uv_mutex_lock (&g_RtnOrderStatusTopic_mutex);
    g_RtnOrderStatusTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnOrderStatusTopic_mutex);

    uv_async_send(&g_RtnOrderStatusTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnOrderStatusTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryBargainOrderTopic(CShfeFtdcRspQryBargainOrderField* pRspQryBargainOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryBargainOrderTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryBargainOrder) { 
        OutputCallbackMessage("pRspQryBargainOrder is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryBargainOrderTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryBargainOrder->ActionDate: ", pRspQryBargainOrder->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryBargainOrder->ActionTime: ", pRspQryBargainOrder->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryBargainOrder->TradeID: ", pRspQryBargainOrder->TradeID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryBargainOrder->OrderSysID: ", pRspQryBargainOrder->OrderSysID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryBargainOrder->InstrumentID: ", pRspQryBargainOrder->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryBargainOrder->Price: ", pRspQryBargainOrder->Price, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryBargainOrder->Volume: ", pRspQryBargainOrder->Volume, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryBargainOrder->ParticipantID: ", pRspQryBargainOrder->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryBargainOrder->UserID: ", pRspQryBargainOrder->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryBargainOrder->ClientID: ", pRspQryBargainOrder->ClientID, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryBargainOrderField* pNewRspQryBargainOrder = new CShfeFtdcRspQryBargainOrderField;
    memcpy (pNewRspQryBargainOrder, pRspQryBargainOrder, sizeof(CShfeFtdcRspQryBargainOrderField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryBargainOrder;

    uv_mutex_lock (&g_RspQryBargainOrderTopic_mutex);
    g_RspQryBargainOrderTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryBargainOrderTopic_mutex);

    uv_async_send(&g_RspQryBargainOrderTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryBargainOrderTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnBargainOrderTopic(CShfeFtdcRtnBargainOrderField* pRtnBargainOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnBargainOrderTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnBargainOrder) { 
        OutputCallbackMessage("pRtnBargainOrder is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnBargainOrderTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnBargainOrder->ActionDate: ", pRtnBargainOrder->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnBargainOrder->ActionTime: ", pRtnBargainOrder->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnBargainOrder->TradeID: ", pRtnBargainOrder->TradeID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnBargainOrder->OrderSysID: ", pRtnBargainOrder->OrderSysID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnBargainOrder->InstrumentID: ", pRtnBargainOrder->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnBargainOrder->Price: ", pRtnBargainOrder->Price, g_RunningResult_File);
    OutputCallbackMessage(" pRtnBargainOrder->Volume: ", pRtnBargainOrder->Volume, g_RunningResult_File);
    OutputCallbackMessage(" pRtnBargainOrder->ParticipantID: ", pRtnBargainOrder->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnBargainOrder->UserID: ", pRtnBargainOrder->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnBargainOrder->ClientID: ", pRtnBargainOrder->ClientID, g_RunningResult_File);

    CShfeFtdcRtnBargainOrderField* pNewRtnBargainOrder = new CShfeFtdcRtnBargainOrderField;
    memcpy (pNewRtnBargainOrder, pRtnBargainOrder, sizeof(CShfeFtdcRtnBargainOrderField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnBargainOrder;

    uv_mutex_lock (&g_RtnBargainOrderTopic_mutex);
    g_RtnBargainOrderTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnBargainOrderTopic_mutex);

    uv_async_send(&g_RtnBargainOrderTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnBargainOrderTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryInstPropertyTopic(CShfeFtdcRspQryInstPropertyField* pRspQryInstProperty, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryInstPropertyTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryInstProperty) { 
        OutputCallbackMessage("pRspQryInstProperty is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryInstPropertyTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryInstProperty->ActionDate: ", pRspQryInstProperty->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->ActionTime: ", pRspQryInstProperty->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->InstrumentID: ", pRspQryInstProperty->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->SettlementGroupID: ", pRspQryInstProperty->SettlementGroupID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->UnderlyingInstrID: ", pRspQryInstProperty->UnderlyingInstrID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->ProductClass: ", pRspQryInstProperty->ProductClass, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->PositionType: ", pRspQryInstProperty->PositionType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->VolumeMultiple: ", pRspQryInstProperty->VolumeMultiple, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->UnderlyingMultiple: ", pRspQryInstProperty->UnderlyingMultiple, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->InstLifePhase: ", pRspQryInstProperty->InstLifePhase, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->OpenDate: ", pRspQryInstProperty->OpenDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->ExpireDate: ", pRspQryInstProperty->ExpireDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->StartDelivDate: ", pRspQryInstProperty->StartDelivDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->EndDelivDate: ", pRspQryInstProperty->EndDelivDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->BasisPrice: ", pRspQryInstProperty->BasisPrice, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->MaxMarketOrderVolume: ", pRspQryInstProperty->MaxMarketOrderVolume, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->MinMarketOrderVolume: ", pRspQryInstProperty->MinMarketOrderVolume, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->MaxLimitOrderVolume: ", pRspQryInstProperty->MaxLimitOrderVolume, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->MinLimitOrderVolume: ", pRspQryInstProperty->MinLimitOrderVolume, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->PriceTick: ", pRspQryInstProperty->PriceTick, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstProperty->AllowDelivPersonOpen: ", pRspQryInstProperty->AllowDelivPersonOpen, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryInstPropertyField* pNewRspQryInstProperty = new CShfeFtdcRspQryInstPropertyField;
    memcpy (pNewRspQryInstProperty, pRspQryInstProperty, sizeof(CShfeFtdcRspQryInstPropertyField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryInstProperty;

    uv_mutex_lock (&g_RspQryInstPropertyTopic_mutex);
    g_RspQryInstPropertyTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryInstPropertyTopic_mutex);

    uv_async_send(&g_RspQryInstPropertyTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryInstPropertyTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnInstPropertyTopic(CShfeFtdcRtnInstPropertyField* pRtnInstProperty, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnInstPropertyTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnInstProperty) { 
        OutputCallbackMessage("pRtnInstProperty is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnInstPropertyTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnInstProperty->ActionDate: ", pRtnInstProperty->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->ActionTime: ", pRtnInstProperty->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->InstrumentID: ", pRtnInstProperty->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->SettlementGroupID: ", pRtnInstProperty->SettlementGroupID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->UnderlyingInstrID: ", pRtnInstProperty->UnderlyingInstrID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->ProductClass: ", pRtnInstProperty->ProductClass, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->PositionType: ", pRtnInstProperty->PositionType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->VolumeMultiple: ", pRtnInstProperty->VolumeMultiple, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->UnderlyingMultiple: ", pRtnInstProperty->UnderlyingMultiple, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->InstLifePhase: ", pRtnInstProperty->InstLifePhase, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->OpenDate: ", pRtnInstProperty->OpenDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->ExpireDate: ", pRtnInstProperty->ExpireDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->StartDelivDate: ", pRtnInstProperty->StartDelivDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->EndDelivDate: ", pRtnInstProperty->EndDelivDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->BasisPrice: ", pRtnInstProperty->BasisPrice, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->MaxMarketOrderVolume: ", pRtnInstProperty->MaxMarketOrderVolume, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->MinMarketOrderVolume: ", pRtnInstProperty->MinMarketOrderVolume, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->MaxLimitOrderVolume: ", pRtnInstProperty->MaxLimitOrderVolume, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->MinLimitOrderVolume: ", pRtnInstProperty->MinLimitOrderVolume, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->PriceTick: ", pRtnInstProperty->PriceTick, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstProperty->AllowDelivPersonOpen: ", pRtnInstProperty->AllowDelivPersonOpen, g_RunningResult_File);

    CShfeFtdcRtnInstPropertyField* pNewRtnInstProperty = new CShfeFtdcRtnInstPropertyField;
    memcpy (pNewRtnInstProperty, pRtnInstProperty, sizeof(CShfeFtdcRtnInstPropertyField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnInstProperty;

    uv_mutex_lock (&g_RtnInstPropertyTopic_mutex);
    g_RtnInstPropertyTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnInstPropertyTopic_mutex);

    uv_async_send(&g_RtnInstPropertyTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnInstPropertyTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryMarginRateTopic(CShfeFtdcRspQryMarginRateField* pRspQryMarginRate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryMarginRateTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryMarginRate) { 
        OutputCallbackMessage("pRspQryMarginRate is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryMarginRateTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryMarginRate->ActionDate: ", pRspQryMarginRate->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRate->ActionTime: ", pRspQryMarginRate->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRate->InstrumentID: ", pRspQryMarginRate->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRate->ParticipantID: ", pRspQryMarginRate->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRate->TradingRole: ", pRspQryMarginRate->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRate->HedgeFlag: ", pRspQryMarginRate->HedgeFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRate->ValueMode: ", pRspQryMarginRate->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRate->LongMarginRatio: ", pRspQryMarginRate->LongMarginRatio, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRate->ShortMarginRatio: ", pRspQryMarginRate->ShortMarginRatio, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryMarginRateField* pNewRspQryMarginRate = new CShfeFtdcRspQryMarginRateField;
    memcpy (pNewRspQryMarginRate, pRspQryMarginRate, sizeof(CShfeFtdcRspQryMarginRateField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryMarginRate;

    uv_mutex_lock (&g_RspQryMarginRateTopic_mutex);
    g_RspQryMarginRateTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryMarginRateTopic_mutex);

    uv_async_send(&g_RspQryMarginRateTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryMarginRateTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnMarginRateTopic(CShfeFtdcRtnMarginRateField* pRtnMarginRate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnMarginRateTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnMarginRate) { 
        OutputCallbackMessage("pRtnMarginRate is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnMarginRateTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnMarginRate->ActionDate: ", pRtnMarginRate->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRate->ActionTime: ", pRtnMarginRate->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRate->InstrumentID: ", pRtnMarginRate->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRate->ParticipantID: ", pRtnMarginRate->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRate->TradingRole: ", pRtnMarginRate->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRate->HedgeFlag: ", pRtnMarginRate->HedgeFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRate->ValueMode: ", pRtnMarginRate->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRate->LongMarginRatio: ", pRtnMarginRate->LongMarginRatio, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRate->ShortMarginRatio: ", pRtnMarginRate->ShortMarginRatio, g_RunningResult_File);

    CShfeFtdcRtnMarginRateField* pNewRtnMarginRate = new CShfeFtdcRtnMarginRateField;
    memcpy (pNewRtnMarginRate, pRtnMarginRate, sizeof(CShfeFtdcRtnMarginRateField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnMarginRate;

    uv_mutex_lock (&g_RtnMarginRateTopic_mutex);
    g_RtnMarginRateTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnMarginRateTopic_mutex);

    uv_async_send(&g_RtnMarginRateTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnMarginRateTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryPriceLimitTopic(CShfeFtdcRspQryPriceLimitField* pRspQryPriceLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryPriceLimitTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryPriceLimit) { 
        OutputCallbackMessage("pRspQryPriceLimit is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryPriceLimitTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryPriceLimit->ActionDate: ", pRspQryPriceLimit->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPriceLimit->ActionTime: ", pRspQryPriceLimit->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPriceLimit->InstrumentID: ", pRspQryPriceLimit->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPriceLimit->ValueMode: ", pRspQryPriceLimit->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPriceLimit->RoundingMode: ", pRspQryPriceLimit->RoundingMode, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPriceLimit->UpperLimitPrice: ", pRspQryPriceLimit->UpperLimitPrice, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPriceLimit->LowerLimitPrice: ", pRspQryPriceLimit->LowerLimitPrice, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryPriceLimitField* pNewRspQryPriceLimit = new CShfeFtdcRspQryPriceLimitField;
    memcpy (pNewRspQryPriceLimit, pRspQryPriceLimit, sizeof(CShfeFtdcRspQryPriceLimitField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryPriceLimit;

    uv_mutex_lock (&g_RspQryPriceLimitTopic_mutex);
    g_RspQryPriceLimitTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryPriceLimitTopic_mutex);

    uv_async_send(&g_RspQryPriceLimitTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryPriceLimitTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnPriceLimitTopic(CShfeFtdcRtnPriceLimitField* pRtnPriceLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnPriceLimitTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnPriceLimit) { 
        OutputCallbackMessage("pRtnPriceLimit is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnPriceLimitTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnPriceLimit->ActionDate: ", pRtnPriceLimit->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPriceLimit->ActionTime: ", pRtnPriceLimit->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPriceLimit->InstrumentID: ", pRtnPriceLimit->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPriceLimit->ValueMode: ", pRtnPriceLimit->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPriceLimit->RoundingMode: ", pRtnPriceLimit->RoundingMode, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPriceLimit->UpperLimitPrice: ", pRtnPriceLimit->UpperLimitPrice, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPriceLimit->LowerLimitPrice: ", pRtnPriceLimit->LowerLimitPrice, g_RunningResult_File);

    CShfeFtdcRtnPriceLimitField* pNewRtnPriceLimit = new CShfeFtdcRtnPriceLimitField;
    memcpy (pNewRtnPriceLimit, pRtnPriceLimit, sizeof(CShfeFtdcRtnPriceLimitField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnPriceLimit;

    uv_mutex_lock (&g_RtnPriceLimitTopic_mutex);
    g_RtnPriceLimitTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnPriceLimitTopic_mutex);

    uv_async_send(&g_RtnPriceLimitTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnPriceLimitTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryPartPosiLimitTopic(CShfeFtdcRspQryPartPosiLimitField* pRspQryPartPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryPartPosiLimitTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryPartPosiLimit) { 
        OutputCallbackMessage("pRspQryPartPosiLimit is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryPartPosiLimitTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryPartPosiLimit->ActionDate: ", pRspQryPartPosiLimit->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartPosiLimit->ActionTime: ", pRspQryPartPosiLimit->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartPosiLimit->InstrumentID: ", pRspQryPartPosiLimit->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartPosiLimit->ParticipantID: ", pRspQryPartPosiLimit->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartPosiLimit->TradingRole: ", pRspQryPartPosiLimit->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartPosiLimit->StartTotalPosition: ", pRspQryPartPosiLimit->StartTotalPosition, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartPosiLimit->ValueMode: ", pRspQryPartPosiLimit->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartPosiLimit->LongPosLimit: ", pRspQryPartPosiLimit->LongPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartPosiLimit->ShortPosLimit: ", pRspQryPartPosiLimit->ShortPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartPosiLimit->UpperLimitPrice: ", pRspQryPartPosiLimit->UpperLimitPrice, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartPosiLimit->LowerLimitPrice: ", pRspQryPartPosiLimit->LowerLimitPrice, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryPartPosiLimitField* pNewRspQryPartPosiLimit = new CShfeFtdcRspQryPartPosiLimitField;
    memcpy (pNewRspQryPartPosiLimit, pRspQryPartPosiLimit, sizeof(CShfeFtdcRspQryPartPosiLimitField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryPartPosiLimit;

    uv_mutex_lock (&g_RspQryPartPosiLimitTopic_mutex);
    g_RspQryPartPosiLimitTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryPartPosiLimitTopic_mutex);

    uv_async_send(&g_RspQryPartPosiLimitTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryPartPosiLimitTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnPartPosiLimitTopic(CShfeFtdcRtnPartPosiLimitField* pRtnPartPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnPartPosiLimitTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnPartPosiLimit) { 
        OutputCallbackMessage("pRtnPartPosiLimit is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnPartPosiLimitTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnPartPosiLimit->ActionDate: ", pRtnPartPosiLimit->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPartPosiLimit->ActionTime: ", pRtnPartPosiLimit->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPartPosiLimit->InstrumentID: ", pRtnPartPosiLimit->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPartPosiLimit->ParticipantID: ", pRtnPartPosiLimit->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPartPosiLimit->TradingRole: ", pRtnPartPosiLimit->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPartPosiLimit->StartTotalPosition: ", pRtnPartPosiLimit->StartTotalPosition, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPartPosiLimit->ValueMode: ", pRtnPartPosiLimit->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPartPosiLimit->LongPosLimit: ", pRtnPartPosiLimit->LongPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPartPosiLimit->ShortPosLimit: ", pRtnPartPosiLimit->ShortPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPartPosiLimit->UpperLimitPrice: ", pRtnPartPosiLimit->UpperLimitPrice, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPartPosiLimit->LowerLimitPrice: ", pRtnPartPosiLimit->LowerLimitPrice, g_RunningResult_File);

    CShfeFtdcRtnPartPosiLimitField* pNewRtnPartPosiLimit = new CShfeFtdcRtnPartPosiLimitField;
    memcpy (pNewRtnPartPosiLimit, pRtnPartPosiLimit, sizeof(CShfeFtdcRtnPartPosiLimitField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnPartPosiLimit;

    uv_mutex_lock (&g_RtnPartPosiLimitTopic_mutex);
    g_RtnPartPosiLimitTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnPartPosiLimitTopic_mutex);

    uv_async_send(&g_RtnPartPosiLimitTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnPartPosiLimitTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryClientPosiLimitTopic(CShfeFtdcRspQryClientPosiLimitField* pRspQryClientPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryClientPosiLimitTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryClientPosiLimit) { 
        OutputCallbackMessage("pRspQryClientPosiLimit is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryClientPosiLimitTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryClientPosiLimit->ActionDate: ", pRspQryClientPosiLimit->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimit->ActionTime: ", pRspQryClientPosiLimit->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimit->InstrumentID: ", pRspQryClientPosiLimit->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimit->ClientType: ", pRspQryClientPosiLimit->ClientType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimit->TradingRole: ", pRspQryClientPosiLimit->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimit->StartTotalPosition: ", pRspQryClientPosiLimit->StartTotalPosition, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimit->ValueMode: ", pRspQryClientPosiLimit->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimit->LongPosLimit: ", pRspQryClientPosiLimit->LongPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimit->ShortPosLimit: ", pRspQryClientPosiLimit->ShortPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimit->UpperLimitPrice: ", pRspQryClientPosiLimit->UpperLimitPrice, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimit->LowerLimitPrice: ", pRspQryClientPosiLimit->LowerLimitPrice, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryClientPosiLimitField* pNewRspQryClientPosiLimit = new CShfeFtdcRspQryClientPosiLimitField;
    memcpy (pNewRspQryClientPosiLimit, pRspQryClientPosiLimit, sizeof(CShfeFtdcRspQryClientPosiLimitField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryClientPosiLimit;

    uv_mutex_lock (&g_RspQryClientPosiLimitTopic_mutex);
    g_RspQryClientPosiLimitTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryClientPosiLimitTopic_mutex);

    uv_async_send(&g_RspQryClientPosiLimitTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryClientPosiLimitTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnClientPosiLimitTopic(CShfeFtdcRtnClientPosiLimitField* pRtnClientPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnClientPosiLimitTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnClientPosiLimit) { 
        OutputCallbackMessage("pRtnClientPosiLimit is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnClientPosiLimitTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnClientPosiLimit->ActionDate: ", pRtnClientPosiLimit->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimit->ActionTime: ", pRtnClientPosiLimit->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimit->InstrumentID: ", pRtnClientPosiLimit->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimit->ClientType: ", pRtnClientPosiLimit->ClientType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimit->TradingRole: ", pRtnClientPosiLimit->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimit->StartTotalPosition: ", pRtnClientPosiLimit->StartTotalPosition, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimit->ValueMode: ", pRtnClientPosiLimit->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimit->LongPosLimit: ", pRtnClientPosiLimit->LongPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimit->ShortPosLimit: ", pRtnClientPosiLimit->ShortPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimit->UpperLimitPrice: ", pRtnClientPosiLimit->UpperLimitPrice, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimit->LowerLimitPrice: ", pRtnClientPosiLimit->LowerLimitPrice, g_RunningResult_File);

    CShfeFtdcRtnClientPosiLimitField* pNewRtnClientPosiLimit = new CShfeFtdcRtnClientPosiLimitField;
    memcpy (pNewRtnClientPosiLimit, pRtnClientPosiLimit, sizeof(CShfeFtdcRtnClientPosiLimitField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnClientPosiLimit;

    uv_mutex_lock (&g_RtnClientPosiLimitTopic_mutex);
    g_RtnClientPosiLimitTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnClientPosiLimitTopic_mutex);

    uv_async_send(&g_RtnClientPosiLimitTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnClientPosiLimitTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQrySpecialPosiLimitTopic(CShfeFtdcRspQrySpecialPosiLimitField* pRspQrySpecialPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQrySpecialPosiLimitTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQrySpecialPosiLimit) { 
        OutputCallbackMessage("pRspQrySpecialPosiLimit is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQrySpecialPosiLimitTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQrySpecialPosiLimit->ActionDate: ", pRspQrySpecialPosiLimit->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecialPosiLimit->ActionTime: ", pRspQrySpecialPosiLimit->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecialPosiLimit->InstrumentID: ", pRspQrySpecialPosiLimit->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecialPosiLimit->ClientID: ", pRspQrySpecialPosiLimit->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecialPosiLimit->TradingRole: ", pRspQrySpecialPosiLimit->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecialPosiLimit->StartTotalPosition: ", pRspQrySpecialPosiLimit->StartTotalPosition, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecialPosiLimit->ValueMode: ", pRspQrySpecialPosiLimit->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecialPosiLimit->LongPosLimit: ", pRspQrySpecialPosiLimit->LongPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecialPosiLimit->ShortPosLimit: ", pRspQrySpecialPosiLimit->ShortPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecialPosiLimit->UpperLimitPrice: ", pRspQrySpecialPosiLimit->UpperLimitPrice, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecialPosiLimit->LowerLimitPrice: ", pRspQrySpecialPosiLimit->LowerLimitPrice, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQrySpecialPosiLimitField* pNewRspQrySpecialPosiLimit = new CShfeFtdcRspQrySpecialPosiLimitField;
    memcpy (pNewRspQrySpecialPosiLimit, pRspQrySpecialPosiLimit, sizeof(CShfeFtdcRspQrySpecialPosiLimitField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQrySpecialPosiLimit;

    uv_mutex_lock (&g_RspQrySpecialPosiLimitTopic_mutex);
    g_RspQrySpecialPosiLimitTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQrySpecialPosiLimitTopic_mutex);

    uv_async_send(&g_RspQrySpecialPosiLimitTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQrySpecialPosiLimitTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnSpecialPosiLimitTopic(CShfeFtdcRtnSpecialPosiLimitField* pRtnSpecialPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnSpecialPosiLimitTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnSpecialPosiLimit) { 
        OutputCallbackMessage("pRtnSpecialPosiLimit is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnSpecialPosiLimitTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnSpecialPosiLimit->ActionDate: ", pRtnSpecialPosiLimit->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecialPosiLimit->ActionTime: ", pRtnSpecialPosiLimit->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecialPosiLimit->InstrumentID: ", pRtnSpecialPosiLimit->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecialPosiLimit->ClientID: ", pRtnSpecialPosiLimit->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecialPosiLimit->TradingRole: ", pRtnSpecialPosiLimit->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecialPosiLimit->StartTotalPosition: ", pRtnSpecialPosiLimit->StartTotalPosition, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecialPosiLimit->ValueMode: ", pRtnSpecialPosiLimit->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecialPosiLimit->LongPosLimit: ", pRtnSpecialPosiLimit->LongPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecialPosiLimit->ShortPosLimit: ", pRtnSpecialPosiLimit->ShortPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecialPosiLimit->UpperLimitPrice: ", pRtnSpecialPosiLimit->UpperLimitPrice, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecialPosiLimit->LowerLimitPrice: ", pRtnSpecialPosiLimit->LowerLimitPrice, g_RunningResult_File);

    CShfeFtdcRtnSpecialPosiLimitField* pNewRtnSpecialPosiLimit = new CShfeFtdcRtnSpecialPosiLimitField;
    memcpy (pNewRtnSpecialPosiLimit, pRtnSpecialPosiLimit, sizeof(CShfeFtdcRtnSpecialPosiLimitField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnSpecialPosiLimit;

    uv_mutex_lock (&g_RtnSpecialPosiLimitTopic_mutex);
    g_RtnSpecialPosiLimitTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnSpecialPosiLimitTopic_mutex);

    uv_async_send(&g_RtnSpecialPosiLimitTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnSpecialPosiLimitTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryTransactionChgTopic(CShfeFtdcRspQryTransactionChgField* pRspQryTransactionChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryTransactionChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryTransactionChg) { 
        OutputCallbackMessage("pRspQryTransactionChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryTransactionChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryTransactionChg->ActionDate: ", pRspQryTransactionChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTransactionChg->ActionTime: ", pRspQryTransactionChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTransactionChg->BillSN: ", pRspQryTransactionChg->BillSN, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTransactionChg->ParticipantAccount: ", pRspQryTransactionChg->ParticipantAccount, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTransactionChg->ParticipantID: ", pRspQryTransactionChg->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTransactionChg->Amount: ", pRspQryTransactionChg->Amount, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryTransactionChgField* pNewRspQryTransactionChg = new CShfeFtdcRspQryTransactionChgField;
    memcpy (pNewRspQryTransactionChg, pRspQryTransactionChg, sizeof(CShfeFtdcRspQryTransactionChgField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryTransactionChg;

    uv_mutex_lock (&g_RspQryTransactionChgTopic_mutex);
    g_RspQryTransactionChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryTransactionChgTopic_mutex);

    uv_async_send(&g_RspQryTransactionChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryTransactionChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnTransactionChgTopic(CShfeFtdcRtnTransactionChgField* pRtnTransactionChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnTransactionChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnTransactionChg) { 
        OutputCallbackMessage("pRtnTransactionChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnTransactionChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnTransactionChg->ActionDate: ", pRtnTransactionChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTransactionChg->ActionTime: ", pRtnTransactionChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTransactionChg->BillSN: ", pRtnTransactionChg->BillSN, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTransactionChg->ParticipantAccount: ", pRtnTransactionChg->ParticipantAccount, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTransactionChg->ParticipantID: ", pRtnTransactionChg->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTransactionChg->Amount: ", pRtnTransactionChg->Amount, g_RunningResult_File);

    CShfeFtdcRtnTransactionChgField* pNewRtnTransactionChg = new CShfeFtdcRtnTransactionChgField;
    memcpy (pNewRtnTransactionChg, pRtnTransactionChg, sizeof(CShfeFtdcRtnTransactionChgField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnTransactionChg;

    uv_mutex_lock (&g_RtnTransactionChgTopic_mutex);
    g_RtnTransactionChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnTransactionChgTopic_mutex);

    uv_async_send(&g_RtnTransactionChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnTransactionChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryClientChgTopic(CShfeFtdcRspQryClientChgField* pRspQryClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryClientChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryClientChg) { 
        OutputCallbackMessage("pRspQryClientChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryClientChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryClientChg->ActionDate: ", pRspQryClientChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientChg->ActionTime: ", pRspQryClientChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientChg->ClientID: ", pRspQryClientChg->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientChg->ClientName: ", pRspQryClientChg->ClientName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientChg->ClientType: ", pRspQryClientChg->ClientType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientChg->IsActive: ", pRspQryClientChg->IsActive, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientChg->IdentifiedCardType: ", pRspQryClientChg->IdentifiedCardType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientChg->IdentifiedCardNo: ", pRspQryClientChg->IdentifiedCardNo, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientChg->OperationType: ", pRspQryClientChg->OperationType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryClientChgField* pNewRspQryClientChg = new CShfeFtdcRspQryClientChgField;
    memcpy (pNewRspQryClientChg, pRspQryClientChg, sizeof(CShfeFtdcRspQryClientChgField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryClientChg;

    uv_mutex_lock (&g_RspQryClientChgTopic_mutex);
    g_RspQryClientChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryClientChgTopic_mutex);

    uv_async_send(&g_RspQryClientChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryClientChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnClientChgTopic(CShfeFtdcRtnClientChgField* pRtnClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnClientChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnClientChg) { 
        OutputCallbackMessage("pRtnClientChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnClientChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnClientChg->ActionDate: ", pRtnClientChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientChg->ActionTime: ", pRtnClientChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientChg->ClientID: ", pRtnClientChg->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientChg->ClientName: ", pRtnClientChg->ClientName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientChg->ClientType: ", pRtnClientChg->ClientType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientChg->IsActive: ", pRtnClientChg->IsActive, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientChg->IdentifiedCardType: ", pRtnClientChg->IdentifiedCardType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientChg->IdentifiedCardNo: ", pRtnClientChg->IdentifiedCardNo, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientChg->OperationType: ", pRtnClientChg->OperationType, g_RunningResult_File);

    CShfeFtdcRtnClientChgField* pNewRtnClientChg = new CShfeFtdcRtnClientChgField;
    memcpy (pNewRtnClientChg, pRtnClientChg, sizeof(CShfeFtdcRtnClientChgField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnClientChg;

    uv_mutex_lock (&g_RtnClientChgTopic_mutex);
    g_RtnClientChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnClientChgTopic_mutex);

    uv_async_send(&g_RtnClientChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnClientChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryPartClientChgTopic(CShfeFtdcRspQryPartClientChgField* pRspQryPartClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryPartClientChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryPartClientChg) { 
        OutputCallbackMessage("pRspQryPartClientChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryPartClientChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryPartClientChg->ActionDate: ", pRspQryPartClientChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartClientChg->ActionTime: ", pRspQryPartClientChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartClientChg->ClientID: ", pRspQryPartClientChg->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartClientChg->ParticipantID: ", pRspQryPartClientChg->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartClientChg->OperationType: ", pRspQryPartClientChg->OperationType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryPartClientChgField* pNewRspQryPartClientChg = new CShfeFtdcRspQryPartClientChgField;
    memcpy (pNewRspQryPartClientChg, pRspQryPartClientChg, sizeof(CShfeFtdcRspQryPartClientChgField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryPartClientChg;

    uv_mutex_lock (&g_RspQryPartClientChgTopic_mutex);
    g_RspQryPartClientChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryPartClientChgTopic_mutex);

    uv_async_send(&g_RspQryPartClientChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryPartClientChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnPartClientChgTopic(CShfeFtdcRtnPartClientChgField* pRtnPartClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnPartClientChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnPartClientChg) { 
        OutputCallbackMessage("pRtnPartClientChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnPartClientChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnPartClientChg->ActionDate: ", pRtnPartClientChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPartClientChg->ActionTime: ", pRtnPartClientChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPartClientChg->ClientID: ", pRtnPartClientChg->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPartClientChg->ParticipantID: ", pRtnPartClientChg->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPartClientChg->OperationType: ", pRtnPartClientChg->OperationType, g_RunningResult_File);

    CShfeFtdcRtnPartClientChgField* pNewRtnPartClientChg = new CShfeFtdcRtnPartClientChgField;
    memcpy (pNewRtnPartClientChg, pRtnPartClientChg, sizeof(CShfeFtdcRtnPartClientChgField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnPartClientChg;

    uv_mutex_lock (&g_RtnPartClientChgTopic_mutex);
    g_RtnPartClientChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnPartClientChgTopic_mutex);

    uv_async_send(&g_RtnPartClientChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnPartClientChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryPosiLimitChgTopic(CShfeFtdcRspQryPosiLimitChgField* pRspQryPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryPosiLimitChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryPosiLimitChg) { 
        OutputCallbackMessage("pRspQryPosiLimitChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryPosiLimitChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryPosiLimitChg->ActionDate: ", pRspQryPosiLimitChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPosiLimitChg->ActionTime: ", pRspQryPosiLimitChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPosiLimitChg->InstrumentID: ", pRspQryPosiLimitChg->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPosiLimitChg->ParticipantID: ", pRspQryPosiLimitChg->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPosiLimitChg->TradingRole: ", pRspQryPosiLimitChg->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPosiLimitChg->StartTotalPosition: ", pRspQryPosiLimitChg->StartTotalPosition, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPosiLimitChg->ValueMode: ", pRspQryPosiLimitChg->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPosiLimitChg->LongPosLimit: ", pRspQryPosiLimitChg->LongPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPosiLimitChg->ShortPosLimit: ", pRspQryPosiLimitChg->ShortPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPosiLimitChg->OperationType: ", pRspQryPosiLimitChg->OperationType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryPosiLimitChgField* pNewRspQryPosiLimitChg = new CShfeFtdcRspQryPosiLimitChgField;
    memcpy (pNewRspQryPosiLimitChg, pRspQryPosiLimitChg, sizeof(CShfeFtdcRspQryPosiLimitChgField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryPosiLimitChg;

    uv_mutex_lock (&g_RspQryPosiLimitChgTopic_mutex);
    g_RspQryPosiLimitChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryPosiLimitChgTopic_mutex);

    uv_async_send(&g_RspQryPosiLimitChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryPosiLimitChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnPosiLimitChgTopic(CShfeFtdcRtnPosiLimitChgField* pRtnPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnPosiLimitChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnPosiLimitChg) { 
        OutputCallbackMessage("pRtnPosiLimitChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnPosiLimitChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnPosiLimitChg->ActionDate: ", pRtnPosiLimitChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPosiLimitChg->ActionTime: ", pRtnPosiLimitChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPosiLimitChg->InstrumentID: ", pRtnPosiLimitChg->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPosiLimitChg->ParticipantID: ", pRtnPosiLimitChg->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPosiLimitChg->TradingRole: ", pRtnPosiLimitChg->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPosiLimitChg->StartTotalPosition: ", pRtnPosiLimitChg->StartTotalPosition, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPosiLimitChg->ValueMode: ", pRtnPosiLimitChg->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPosiLimitChg->LongPosLimit: ", pRtnPosiLimitChg->LongPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPosiLimitChg->ShortPosLimit: ", pRtnPosiLimitChg->ShortPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPosiLimitChg->OperationType: ", pRtnPosiLimitChg->OperationType, g_RunningResult_File);

    CShfeFtdcRtnPosiLimitChgField* pNewRtnPosiLimitChg = new CShfeFtdcRtnPosiLimitChgField;
    memcpy (pNewRtnPosiLimitChg, pRtnPosiLimitChg, sizeof(CShfeFtdcRtnPosiLimitChgField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnPosiLimitChg;

    uv_mutex_lock (&g_RtnPosiLimitChgTopic_mutex);
    g_RtnPosiLimitChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnPosiLimitChgTopic_mutex);

    uv_async_send(&g_RtnPosiLimitChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnPosiLimitChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryHedgeDetailChgTopic(CShfeFtdcRspQryHedgeDetailChgField* pRspQryHedgeDetailChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryHedgeDetailChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryHedgeDetailChg) { 
        OutputCallbackMessage("pRspQryHedgeDetailChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryHedgeDetailChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryHedgeDetailChg->ActionDate: ", pRspQryHedgeDetailChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHedgeDetailChg->ActionTime: ", pRspQryHedgeDetailChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHedgeDetailChg->ParticipantID: ", pRspQryHedgeDetailChg->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHedgeDetailChg->ClientID: ", pRspQryHedgeDetailChg->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHedgeDetailChg->OperatorID: ", pRspQryHedgeDetailChg->OperatorID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHedgeDetailChg->Time: ", pRspQryHedgeDetailChg->Time, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHedgeDetailChg->InstrumentID: ", pRspQryHedgeDetailChg->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHedgeDetailChg->PosiDirection: ", pRspQryHedgeDetailChg->PosiDirection, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHedgeDetailChg->TradingVolume: ", pRspQryHedgeDetailChg->TradingVolume, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHedgeDetailChg->HedgeQuota: ", pRspQryHedgeDetailChg->HedgeQuota, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHedgeDetailChg->OperationType: ", pRspQryHedgeDetailChg->OperationType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryHedgeDetailChgField* pNewRspQryHedgeDetailChg = new CShfeFtdcRspQryHedgeDetailChgField;
    memcpy (pNewRspQryHedgeDetailChg, pRspQryHedgeDetailChg, sizeof(CShfeFtdcRspQryHedgeDetailChgField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryHedgeDetailChg;

    uv_mutex_lock (&g_RspQryHedgeDetailChgTopic_mutex);
    g_RspQryHedgeDetailChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryHedgeDetailChgTopic_mutex);

    uv_async_send(&g_RspQryHedgeDetailChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryHedgeDetailChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnHedgeDetailChgTopic(CShfeFtdcRtnHedgeDetailChgField* pRtnHedgeDetailChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnHedgeDetailChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnHedgeDetailChg) { 
        OutputCallbackMessage("pRtnHedgeDetailChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnHedgeDetailChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnHedgeDetailChg->ActionDate: ", pRtnHedgeDetailChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHedgeDetailChg->ActionTime: ", pRtnHedgeDetailChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHedgeDetailChg->ParticipantID: ", pRtnHedgeDetailChg->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHedgeDetailChg->ClientID: ", pRtnHedgeDetailChg->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHedgeDetailChg->OperatorID: ", pRtnHedgeDetailChg->OperatorID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHedgeDetailChg->Time: ", pRtnHedgeDetailChg->Time, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHedgeDetailChg->InstrumentID: ", pRtnHedgeDetailChg->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHedgeDetailChg->PosiDirection: ", pRtnHedgeDetailChg->PosiDirection, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHedgeDetailChg->TradingVolume: ", pRtnHedgeDetailChg->TradingVolume, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHedgeDetailChg->HedgeQuota: ", pRtnHedgeDetailChg->HedgeQuota, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHedgeDetailChg->OperationType: ", pRtnHedgeDetailChg->OperationType, g_RunningResult_File);

    CShfeFtdcRtnHedgeDetailChgField* pNewRtnHedgeDetailChg = new CShfeFtdcRtnHedgeDetailChgField;
    memcpy (pNewRtnHedgeDetailChg, pRtnHedgeDetailChg, sizeof(CShfeFtdcRtnHedgeDetailChgField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnHedgeDetailChg;

    uv_mutex_lock (&g_RtnHedgeDetailChgTopic_mutex);
    g_RtnHedgeDetailChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnHedgeDetailChgTopic_mutex);

    uv_async_send(&g_RtnHedgeDetailChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnHedgeDetailChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryParticipantChgTopic(CShfeFtdcRspQryParticipantChgField* pRspQryParticipantChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryParticipantChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryParticipantChg) { 
        OutputCallbackMessage("pRspQryParticipantChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryParticipantChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryParticipantChg->ActionDate: ", pRspQryParticipantChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticipantChg->ActionTime: ", pRspQryParticipantChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticipantChg->ParticipantID: ", pRspQryParticipantChg->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticipantChg->ParticipantName: ", pRspQryParticipantChg->ParticipantName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticipantChg->ParticipantAbbr: ", pRspQryParticipantChg->ParticipantAbbr, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticipantChg->MemberType: ", pRspQryParticipantChg->MemberType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticipantChg->IsActive: ", pRspQryParticipantChg->IsActive, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticipantChg->OperationType: ", pRspQryParticipantChg->OperationType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryParticipantChgField* pNewRspQryParticipantChg = new CShfeFtdcRspQryParticipantChgField;
    memcpy (pNewRspQryParticipantChg, pRspQryParticipantChg, sizeof(CShfeFtdcRspQryParticipantChgField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryParticipantChg;

    uv_mutex_lock (&g_RspQryParticipantChgTopic_mutex);
    g_RspQryParticipantChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryParticipantChgTopic_mutex);

    uv_async_send(&g_RspQryParticipantChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryParticipantChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnParticipantChgTopic(CShfeFtdcRtnParticipantChgField* pRtnParticipantChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnParticipantChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnParticipantChg) { 
        OutputCallbackMessage("pRtnParticipantChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnParticipantChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnParticipantChg->ActionDate: ", pRtnParticipantChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticipantChg->ActionTime: ", pRtnParticipantChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticipantChg->ParticipantID: ", pRtnParticipantChg->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticipantChg->ParticipantName: ", pRtnParticipantChg->ParticipantName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticipantChg->ParticipantAbbr: ", pRtnParticipantChg->ParticipantAbbr, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticipantChg->MemberType: ", pRtnParticipantChg->MemberType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticipantChg->IsActive: ", pRtnParticipantChg->IsActive, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticipantChg->OperationType: ", pRtnParticipantChg->OperationType, g_RunningResult_File);

    CShfeFtdcRtnParticipantChgField* pNewRtnParticipantChg = new CShfeFtdcRtnParticipantChgField;
    memcpy (pNewRtnParticipantChg, pRtnParticipantChg, sizeof(CShfeFtdcRtnParticipantChgField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnParticipantChg;

    uv_mutex_lock (&g_RtnParticipantChgTopic_mutex);
    g_RtnParticipantChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnParticipantChgTopic_mutex);

    uv_async_send(&g_RtnParticipantChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnParticipantChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryMarginRateChgTopic(CShfeFtdcRspQryMarginRateChgField* pRspQryMarginRateChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryMarginRateChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryMarginRateChg) { 
        OutputCallbackMessage("pRspQryMarginRateChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryMarginRateChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryMarginRateChg->ActionDate: ", pRspQryMarginRateChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRateChg->ActionTime: ", pRspQryMarginRateChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRateChg->InstrumentID: ", pRspQryMarginRateChg->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRateChg->ParticipantID: ", pRspQryMarginRateChg->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRateChg->TradingRole: ", pRspQryMarginRateChg->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRateChg->HedgeFlag: ", pRspQryMarginRateChg->HedgeFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRateChg->ValueMode: ", pRspQryMarginRateChg->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRateChg->LongMarginRatio: ", pRspQryMarginRateChg->LongMarginRatio, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRateChg->ShortMarginRatio: ", pRspQryMarginRateChg->ShortMarginRatio, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMarginRateChg->OperationType: ", pRspQryMarginRateChg->OperationType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryMarginRateChgField* pNewRspQryMarginRateChg = new CShfeFtdcRspQryMarginRateChgField;
    memcpy (pNewRspQryMarginRateChg, pRspQryMarginRateChg, sizeof(CShfeFtdcRspQryMarginRateChgField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryMarginRateChg;

    uv_mutex_lock (&g_RspQryMarginRateChgTopic_mutex);
    g_RspQryMarginRateChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryMarginRateChgTopic_mutex);

    uv_async_send(&g_RspQryMarginRateChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryMarginRateChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnMarginRateChgTopic(CShfeFtdcRtnMarginRateChgField* pRtnMarginRateChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnMarginRateChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnMarginRateChg) { 
        OutputCallbackMessage("pRtnMarginRateChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnMarginRateChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnMarginRateChg->ActionDate: ", pRtnMarginRateChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRateChg->ActionTime: ", pRtnMarginRateChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRateChg->InstrumentID: ", pRtnMarginRateChg->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRateChg->ParticipantID: ", pRtnMarginRateChg->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRateChg->TradingRole: ", pRtnMarginRateChg->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRateChg->HedgeFlag: ", pRtnMarginRateChg->HedgeFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRateChg->ValueMode: ", pRtnMarginRateChg->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRateChg->LongMarginRatio: ", pRtnMarginRateChg->LongMarginRatio, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRateChg->ShortMarginRatio: ", pRtnMarginRateChg->ShortMarginRatio, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMarginRateChg->OperationType: ", pRtnMarginRateChg->OperationType, g_RunningResult_File);

    CShfeFtdcRtnMarginRateChgField* pNewRtnMarginRateChg = new CShfeFtdcRtnMarginRateChgField;
    memcpy (pNewRtnMarginRateChg, pRtnMarginRateChg, sizeof(CShfeFtdcRtnMarginRateChgField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnMarginRateChg;

    uv_mutex_lock (&g_RtnMarginRateChgTopic_mutex);
    g_RtnMarginRateChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnMarginRateChgTopic_mutex);

    uv_async_send(&g_RtnMarginRateChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnMarginRateChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryUserIpChgTopic(CShfeFtdcRspQryUserIpChgField* pRspQryUserIpChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryUserIpChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryUserIpChg) { 
        OutputCallbackMessage("pRspQryUserIpChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryUserIpChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryUserIpChg->ActionDate: ", pRspQryUserIpChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserIpChg->ActionTime: ", pRspQryUserIpChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserIpChg->UserID: ", pRspQryUserIpChg->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserIpChg->IPAddress: ", pRspQryUserIpChg->IPAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserIpChg->IPMask: ", pRspQryUserIpChg->IPMask, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserIpChg->OperationType: ", pRspQryUserIpChg->OperationType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryUserIpChgField* pNewRspQryUserIpChg = new CShfeFtdcRspQryUserIpChgField;
    memcpy (pNewRspQryUserIpChg, pRspQryUserIpChg, sizeof(CShfeFtdcRspQryUserIpChgField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryUserIpChg;

    uv_mutex_lock (&g_RspQryUserIpChgTopic_mutex);
    g_RspQryUserIpChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryUserIpChgTopic_mutex);

    uv_async_send(&g_RspQryUserIpChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryUserIpChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnUserIpChgTopic(CShfeFtdcRtnUserIpChgField* pRtnUserIpChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnUserIpChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnUserIpChg) { 
        OutputCallbackMessage("pRtnUserIpChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnUserIpChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnUserIpChg->ActionDate: ", pRtnUserIpChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserIpChg->ActionTime: ", pRtnUserIpChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserIpChg->UserID: ", pRtnUserIpChg->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserIpChg->IPAddress: ", pRtnUserIpChg->IPAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserIpChg->IPMask: ", pRtnUserIpChg->IPMask, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserIpChg->OperationType: ", pRtnUserIpChg->OperationType, g_RunningResult_File);

    CShfeFtdcRtnUserIpChgField* pNewRtnUserIpChg = new CShfeFtdcRtnUserIpChgField;
    memcpy (pNewRtnUserIpChg, pRtnUserIpChg, sizeof(CShfeFtdcRtnUserIpChgField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnUserIpChg;

    uv_mutex_lock (&g_RtnUserIpChgTopic_mutex);
    g_RtnUserIpChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnUserIpChgTopic_mutex);

    uv_async_send(&g_RtnUserIpChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnUserIpChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryClientPosiLimitChgTopic(CShfeFtdcRspQryClientPosiLimitChgField* pRspQryClientPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryClientPosiLimitChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryClientPosiLimitChg) { 
        OutputCallbackMessage("pRspQryClientPosiLimitChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryClientPosiLimitChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryClientPosiLimitChg->ActionDate: ", pRspQryClientPosiLimitChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimitChg->ActionTime: ", pRspQryClientPosiLimitChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimitChg->InstrumentID: ", pRspQryClientPosiLimitChg->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimitChg->ClientType: ", pRspQryClientPosiLimitChg->ClientType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimitChg->TradingRole: ", pRspQryClientPosiLimitChg->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimitChg->StartTotalPosition: ", pRspQryClientPosiLimitChg->StartTotalPosition, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimitChg->ValueMode: ", pRspQryClientPosiLimitChg->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimitChg->LongPosLimit: ", pRspQryClientPosiLimitChg->LongPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimitChg->ShortPosLimit: ", pRspQryClientPosiLimitChg->ShortPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientPosiLimitChg->OperationType: ", pRspQryClientPosiLimitChg->OperationType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryClientPosiLimitChgField* pNewRspQryClientPosiLimitChg = new CShfeFtdcRspQryClientPosiLimitChgField;
    memcpy (pNewRspQryClientPosiLimitChg, pRspQryClientPosiLimitChg, sizeof(CShfeFtdcRspQryClientPosiLimitChgField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryClientPosiLimitChg;

    uv_mutex_lock (&g_RspQryClientPosiLimitChgTopic_mutex);
    g_RspQryClientPosiLimitChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryClientPosiLimitChgTopic_mutex);

    uv_async_send(&g_RspQryClientPosiLimitChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryClientPosiLimitChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnClientPosiLimitChgTopic(CShfeFtdcRtnClientPosiLimitChgField* pRtnClientPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnClientPosiLimitChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnClientPosiLimitChg) { 
        OutputCallbackMessage("pRtnClientPosiLimitChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnClientPosiLimitChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnClientPosiLimitChg->ActionDate: ", pRtnClientPosiLimitChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimitChg->ActionTime: ", pRtnClientPosiLimitChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimitChg->InstrumentID: ", pRtnClientPosiLimitChg->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimitChg->ClientType: ", pRtnClientPosiLimitChg->ClientType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimitChg->TradingRole: ", pRtnClientPosiLimitChg->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimitChg->StartTotalPosition: ", pRtnClientPosiLimitChg->StartTotalPosition, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimitChg->ValueMode: ", pRtnClientPosiLimitChg->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimitChg->LongPosLimit: ", pRtnClientPosiLimitChg->LongPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimitChg->ShortPosLimit: ", pRtnClientPosiLimitChg->ShortPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientPosiLimitChg->OperationType: ", pRtnClientPosiLimitChg->OperationType, g_RunningResult_File);

    CShfeFtdcRtnClientPosiLimitChgField* pNewRtnClientPosiLimitChg = new CShfeFtdcRtnClientPosiLimitChgField;
    memcpy (pNewRtnClientPosiLimitChg, pRtnClientPosiLimitChg, sizeof(CShfeFtdcRtnClientPosiLimitChgField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnClientPosiLimitChg;

    uv_mutex_lock (&g_RtnClientPosiLimitChgTopic_mutex);
    g_RtnClientPosiLimitChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnClientPosiLimitChgTopic_mutex);

    uv_async_send(&g_RtnClientPosiLimitChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnClientPosiLimitChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQrySpecPosiLimitChgTopic(CShfeFtdcRspQrySpecPosiLimitChgField* pRspQrySpecPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQrySpecPosiLimitChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQrySpecPosiLimitChg) { 
        OutputCallbackMessage("pRspQrySpecPosiLimitChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQrySpecPosiLimitChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQrySpecPosiLimitChg->ActionDate: ", pRspQrySpecPosiLimitChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecPosiLimitChg->ActionTime: ", pRspQrySpecPosiLimitChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecPosiLimitChg->InstrumentID: ", pRspQrySpecPosiLimitChg->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecPosiLimitChg->ClientID: ", pRspQrySpecPosiLimitChg->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecPosiLimitChg->TradingRole: ", pRspQrySpecPosiLimitChg->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecPosiLimitChg->StartTotalPosition: ", pRspQrySpecPosiLimitChg->StartTotalPosition, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecPosiLimitChg->ValueMode: ", pRspQrySpecPosiLimitChg->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecPosiLimitChg->LongPosLimit: ", pRspQrySpecPosiLimitChg->LongPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecPosiLimitChg->ShortPosLimit: ", pRspQrySpecPosiLimitChg->ShortPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySpecPosiLimitChg->OperationType: ", pRspQrySpecPosiLimitChg->OperationType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQrySpecPosiLimitChgField* pNewRspQrySpecPosiLimitChg = new CShfeFtdcRspQrySpecPosiLimitChgField;
    memcpy (pNewRspQrySpecPosiLimitChg, pRspQrySpecPosiLimitChg, sizeof(CShfeFtdcRspQrySpecPosiLimitChgField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQrySpecPosiLimitChg;

    uv_mutex_lock (&g_RspQrySpecPosiLimitChgTopic_mutex);
    g_RspQrySpecPosiLimitChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQrySpecPosiLimitChgTopic_mutex);

    uv_async_send(&g_RspQrySpecPosiLimitChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQrySpecPosiLimitChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnSpecPosiLimitChgTopic(CShfeFtdcRtnSpecPosiLimitChgField* pRtnSpecPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnSpecPosiLimitChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnSpecPosiLimitChg) { 
        OutputCallbackMessage("pRtnSpecPosiLimitChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnSpecPosiLimitChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnSpecPosiLimitChg->ActionDate: ", pRtnSpecPosiLimitChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecPosiLimitChg->ActionTime: ", pRtnSpecPosiLimitChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecPosiLimitChg->InstrumentID: ", pRtnSpecPosiLimitChg->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecPosiLimitChg->ClientID: ", pRtnSpecPosiLimitChg->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecPosiLimitChg->TradingRole: ", pRtnSpecPosiLimitChg->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecPosiLimitChg->StartTotalPosition: ", pRtnSpecPosiLimitChg->StartTotalPosition, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecPosiLimitChg->ValueMode: ", pRtnSpecPosiLimitChg->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecPosiLimitChg->LongPosLimit: ", pRtnSpecPosiLimitChg->LongPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecPosiLimitChg->ShortPosLimit: ", pRtnSpecPosiLimitChg->ShortPosLimit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSpecPosiLimitChg->OperationType: ", pRtnSpecPosiLimitChg->OperationType, g_RunningResult_File);

    CShfeFtdcRtnSpecPosiLimitChgField* pNewRtnSpecPosiLimitChg = new CShfeFtdcRtnSpecPosiLimitChgField;
    memcpy (pNewRtnSpecPosiLimitChg, pRtnSpecPosiLimitChg, sizeof(CShfeFtdcRtnSpecPosiLimitChgField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnSpecPosiLimitChg;

    uv_mutex_lock (&g_RtnSpecPosiLimitChgTopic_mutex);
    g_RtnSpecPosiLimitChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnSpecPosiLimitChgTopic_mutex);

    uv_async_send(&g_RtnSpecPosiLimitChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnSpecPosiLimitChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryHistoryObjectAttrTopic(CShfeFtdcRspQryHistoryObjectAttrField* pRspQryHistoryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryHistoryObjectAttrTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryHistoryObjectAttr) { 
        OutputCallbackMessage("pRspQryHistoryObjectAttr is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryHistoryObjectAttrTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryHistoryObjectAttr->MonDate: ", pRspQryHistoryObjectAttr->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryObjectAttr->BeginTime: ", pRspQryHistoryObjectAttr->BeginTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryObjectAttr->EndTime: ", pRspQryHistoryObjectAttr->EndTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryObjectAttr->ObjectID: ", pRspQryHistoryObjectAttr->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryObjectAttr->AttrType: ", pRspQryHistoryObjectAttr->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryObjectAttr->ValueType: ", pRspQryHistoryObjectAttr->ValueType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryObjectAttr->FirstValue: ", pRspQryHistoryObjectAttr->FirstValue, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryObjectAttr->EndValue: ", pRspQryHistoryObjectAttr->EndValue, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryObjectAttr->AvgValue: ", pRspQryHistoryObjectAttr->AvgValue, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryObjectAttr->MinValue: ", pRspQryHistoryObjectAttr->MinValue, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryObjectAttr->MaxValue: ", pRspQryHistoryObjectAttr->MaxValue, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryObjectAttr->ValueCount: ", pRspQryHistoryObjectAttr->ValueCount, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryHistoryObjectAttrField* pNewRspQryHistoryObjectAttr = new CShfeFtdcRspQryHistoryObjectAttrField;
    memcpy (pNewRspQryHistoryObjectAttr, pRspQryHistoryObjectAttr, sizeof(CShfeFtdcRspQryHistoryObjectAttrField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryHistoryObjectAttr;

    uv_mutex_lock (&g_RspQryHistoryObjectAttrTopic_mutex);
    g_RspQryHistoryObjectAttrTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryHistoryObjectAttrTopic_mutex);

    uv_async_send(&g_RspQryHistoryObjectAttrTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryHistoryObjectAttrTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnHistoryObjectAttrTopic(CShfeFtdcRtnHistoryObjectAttrField* pRtnHistoryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnHistoryObjectAttrTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnHistoryObjectAttr) { 
        OutputCallbackMessage("pRtnHistoryObjectAttr is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnHistoryObjectAttrTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnHistoryObjectAttr->MonDate: ", pRtnHistoryObjectAttr->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryObjectAttr->BeginTime: ", pRtnHistoryObjectAttr->BeginTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryObjectAttr->EndTime: ", pRtnHistoryObjectAttr->EndTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryObjectAttr->ObjectID: ", pRtnHistoryObjectAttr->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryObjectAttr->AttrType: ", pRtnHistoryObjectAttr->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryObjectAttr->ValueType: ", pRtnHistoryObjectAttr->ValueType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryObjectAttr->FirstValue: ", pRtnHistoryObjectAttr->FirstValue, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryObjectAttr->EndValue: ", pRtnHistoryObjectAttr->EndValue, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryObjectAttr->AvgValue: ", pRtnHistoryObjectAttr->AvgValue, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryObjectAttr->MinValue: ", pRtnHistoryObjectAttr->MinValue, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryObjectAttr->MaxValue: ", pRtnHistoryObjectAttr->MaxValue, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryObjectAttr->ValueCount: ", pRtnHistoryObjectAttr->ValueCount, g_RunningResult_File);

    CShfeFtdcRtnHistoryObjectAttrField* pNewRtnHistoryObjectAttr = new CShfeFtdcRtnHistoryObjectAttrField;
    memcpy (pNewRtnHistoryObjectAttr, pRtnHistoryObjectAttr, sizeof(CShfeFtdcRtnHistoryObjectAttrField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnHistoryObjectAttr;

    uv_mutex_lock (&g_RtnHistoryObjectAttrTopic_mutex);
    g_RtnHistoryObjectAttrTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnHistoryObjectAttrTopic_mutex);

    uv_async_send(&g_RtnHistoryObjectAttrTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnHistoryObjectAttrTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryFrontInfoTopic(CShfeFtdcRspQryFrontInfoField* pRspQryFrontInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryFrontInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryFrontInfo) { 
        OutputCallbackMessage("pRspQryFrontInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryFrontInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryFrontInfo->MonDate: ", pRspQryFrontInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFrontInfo->MonTime: ", pRspQryFrontInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFrontInfo->FrontId: ", pRspQryFrontInfo->FrontId, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFrontInfo->RspCondition: ", pRspQryFrontInfo->RspCondition, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFrontInfo->ReqCount: ", pRspQryFrontInfo->ReqCount, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFrontInfo->ReqRate: ", pRspQryFrontInfo->ReqRate, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryFrontInfoField* pNewRspQryFrontInfo = new CShfeFtdcRspQryFrontInfoField;
    memcpy (pNewRspQryFrontInfo, pRspQryFrontInfo, sizeof(CShfeFtdcRspQryFrontInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryFrontInfo;

    uv_mutex_lock (&g_RspQryFrontInfoTopic_mutex);
    g_RspQryFrontInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryFrontInfoTopic_mutex);

    uv_async_send(&g_RspQryFrontInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryFrontInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnFrontInfoTopic(CShfeFtdcRtnFrontInfoField* pRtnFrontInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnFrontInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnFrontInfo) { 
        OutputCallbackMessage("pRtnFrontInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnFrontInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnFrontInfo->MonDate: ", pRtnFrontInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFrontInfo->MonTime: ", pRtnFrontInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFrontInfo->FrontId: ", pRtnFrontInfo->FrontId, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFrontInfo->RspCondition: ", pRtnFrontInfo->RspCondition, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFrontInfo->ReqCount: ", pRtnFrontInfo->ReqCount, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFrontInfo->ReqRate: ", pRtnFrontInfo->ReqRate, g_RunningResult_File);

    CShfeFtdcRtnFrontInfoField* pNewRtnFrontInfo = new CShfeFtdcRtnFrontInfoField;
    memcpy (pNewRtnFrontInfo, pRtnFrontInfo, sizeof(CShfeFtdcRtnFrontInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnFrontInfo;

    uv_mutex_lock (&g_RtnFrontInfoTopic_mutex);
    g_RtnFrontInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnFrontInfoTopic_mutex);

    uv_async_send(&g_RtnFrontInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnFrontInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQrySysUserLoginTopic(CShfeFtdcRspQrySysUserLoginField* pRspQrySysUserLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQrySysUserLoginTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQrySysUserLogin) { 
        OutputCallbackMessage("pRspQrySysUserLogin is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQrySysUserLoginTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQrySysUserLogin->UserID: ", pRspQrySysUserLogin->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySysUserLogin->TradingDay: ", pRspQrySysUserLogin->TradingDay, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySysUserLogin->LoginTime: ", pRspQrySysUserLogin->LoginTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySysUserLogin->Privilege: ", pRspQrySysUserLogin->Privilege, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySysUserLogin->VersionFlag: ", pRspQrySysUserLogin->VersionFlag, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQrySysUserLoginField* pNewRspQrySysUserLogin = new CShfeFtdcRspQrySysUserLoginField;
    memcpy (pNewRspQrySysUserLogin, pRspQrySysUserLogin, sizeof(CShfeFtdcRspQrySysUserLoginField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQrySysUserLogin;

    uv_mutex_lock (&g_RspQrySysUserLoginTopic_mutex);
    g_RspQrySysUserLoginTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQrySysUserLoginTopic_mutex);

    uv_async_send(&g_RspQrySysUserLoginTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQrySysUserLoginTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQrySysUserLogoutTopic(CShfeFtdcRspQrySysUserLogoutField* pRspQrySysUserLogout, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQrySysUserLogoutTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQrySysUserLogout) { 
        OutputCallbackMessage("pRspQrySysUserLogout is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQrySysUserLogoutTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQrySysUserLogout->UserID: ", pRspQrySysUserLogout->UserID, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQrySysUserLogoutField* pNewRspQrySysUserLogout = new CShfeFtdcRspQrySysUserLogoutField;
    memcpy (pNewRspQrySysUserLogout, pRspQrySysUserLogout, sizeof(CShfeFtdcRspQrySysUserLogoutField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQrySysUserLogout;

    uv_mutex_lock (&g_RspQrySysUserLogoutTopic_mutex);
    g_RspQrySysUserLogoutTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQrySysUserLogoutTopic_mutex);

    uv_async_send(&g_RspQrySysUserLogoutTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQrySysUserLogoutTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQrySysUserPasswordUpdateTopic(CShfeFtdcRspQrySysUserPasswordUpdateField* pRspQrySysUserPasswordUpdate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQrySysUserPasswordUpdateTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQrySysUserPasswordUpdate) { 
        OutputCallbackMessage("pRspQrySysUserPasswordUpdate is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQrySysUserPasswordUpdateTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQrySysUserPasswordUpdate->UserID: ", pRspQrySysUserPasswordUpdate->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySysUserPasswordUpdate->PasswordChgMsg: ", pRspQrySysUserPasswordUpdate->PasswordChgMsg, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQrySysUserPasswordUpdateField* pNewRspQrySysUserPasswordUpdate = new CShfeFtdcRspQrySysUserPasswordUpdateField;
    memcpy (pNewRspQrySysUserPasswordUpdate, pRspQrySysUserPasswordUpdate, sizeof(CShfeFtdcRspQrySysUserPasswordUpdateField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQrySysUserPasswordUpdate;

    uv_mutex_lock (&g_RspQrySysUserPasswordUpdateTopic_mutex);
    g_RspQrySysUserPasswordUpdateTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQrySysUserPasswordUpdateTopic_mutex);

    uv_async_send(&g_RspQrySysUserPasswordUpdateTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQrySysUserPasswordUpdateTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQrySysUserRegisterTopic(CShfeFtdcRspQrySysUserRegisterField* pRspQrySysUserRegister, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQrySysUserRegisterTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQrySysUserRegister) { 
        OutputCallbackMessage("pRspQrySysUserRegister is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQrySysUserRegisterTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQrySysUserRegister->UserID: ", pRspQrySysUserRegister->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySysUserRegister->Privilege: ", pRspQrySysUserRegister->Privilege, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQrySysUserRegisterField* pNewRspQrySysUserRegister = new CShfeFtdcRspQrySysUserRegisterField;
    memcpy (pNewRspQrySysUserRegister, pRspQrySysUserRegister, sizeof(CShfeFtdcRspQrySysUserRegisterField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQrySysUserRegister;

    uv_mutex_lock (&g_RspQrySysUserRegisterTopic_mutex);
    g_RspQrySysUserRegisterTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQrySysUserRegisterTopic_mutex);

    uv_async_send(&g_RspQrySysUserRegisterTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQrySysUserRegisterTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQrySysUserDeleteTopic(CShfeFtdcRspQrySysUserDeleteField* pRspQrySysUserDelete, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQrySysUserDeleteTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQrySysUserDelete) { 
        OutputCallbackMessage("pRspQrySysUserDelete is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQrySysUserDeleteTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQrySysUserDelete->UserID: ", pRspQrySysUserDelete->UserID, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQrySysUserDeleteField* pNewRspQrySysUserDelete = new CShfeFtdcRspQrySysUserDeleteField;
    memcpy (pNewRspQrySysUserDelete, pRspQrySysUserDelete, sizeof(CShfeFtdcRspQrySysUserDeleteField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQrySysUserDelete;

    uv_mutex_lock (&g_RspQrySysUserDeleteTopic_mutex);
    g_RspQrySysUserDeleteTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQrySysUserDeleteTopic_mutex);

    uv_async_send(&g_RspQrySysUserDeleteTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQrySysUserDeleteTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryParticipantInitTopic(CShfeFtdcRspQryParticipantInitField* pRspQryParticipantInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryParticipantInitTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryParticipantInit) { 
        OutputCallbackMessage("pRspQryParticipantInit is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryParticipantInitTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryParticipantInit->ParticipantID: ", pRspQryParticipantInit->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticipantInit->ParticipantName: ", pRspQryParticipantInit->ParticipantName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticipantInit->ParticipantAbbr: ", pRspQryParticipantInit->ParticipantAbbr, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticipantInit->MemberType: ", pRspQryParticipantInit->MemberType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticipantInit->IsActive: ", pRspQryParticipantInit->IsActive, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticipantInit->OperationType: ", pRspQryParticipantInit->OperationType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryParticipantInitField* pNewRspQryParticipantInit = new CShfeFtdcRspQryParticipantInitField;
    memcpy (pNewRspQryParticipantInit, pRspQryParticipantInit, sizeof(CShfeFtdcRspQryParticipantInitField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryParticipantInit;

    uv_mutex_lock (&g_RspQryParticipantInitTopic_mutex);
    g_RspQryParticipantInitTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryParticipantInitTopic_mutex);

    uv_async_send(&g_RspQryParticipantInitTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryParticipantInitTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnParticipantInitTopic(CShfeFtdcRtnParticipantInitField* pRtnParticipantInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnParticipantInitTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnParticipantInit) { 
        OutputCallbackMessage("pRtnParticipantInit is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnParticipantInitTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnParticipantInit->ParticipantID: ", pRtnParticipantInit->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticipantInit->ParticipantName: ", pRtnParticipantInit->ParticipantName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticipantInit->ParticipantAbbr: ", pRtnParticipantInit->ParticipantAbbr, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticipantInit->MemberType: ", pRtnParticipantInit->MemberType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticipantInit->IsActive: ", pRtnParticipantInit->IsActive, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticipantInit->OperationType: ", pRtnParticipantInit->OperationType, g_RunningResult_File);

    CShfeFtdcRtnParticipantInitField* pNewRtnParticipantInit = new CShfeFtdcRtnParticipantInitField;
    memcpy (pNewRtnParticipantInit, pRtnParticipantInit, sizeof(CShfeFtdcRtnParticipantInitField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnParticipantInit;

    uv_mutex_lock (&g_RtnParticipantInitTopic_mutex);
    g_RtnParticipantInitTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnParticipantInitTopic_mutex);

    uv_async_send(&g_RtnParticipantInitTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnParticipantInitTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryUserInitTopic(CShfeFtdcRspQryUserInitField* pRspQryUserInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryUserInitTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryUserInit) { 
        OutputCallbackMessage("pRspQryUserInit is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryUserInitTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryUserInit->ParticipantID: ", pRspQryUserInit->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserInit->UserID: ", pRspQryUserInit->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserInit->UserType: ", pRspQryUserInit->UserType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserInit->Password: ", pRspQryUserInit->Password, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserInit->IsActive: ", pRspQryUserInit->IsActive, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryUserInit->OperationType: ", pRspQryUserInit->OperationType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryUserInitField* pNewRspQryUserInit = new CShfeFtdcRspQryUserInitField;
    memcpy (pNewRspQryUserInit, pRspQryUserInit, sizeof(CShfeFtdcRspQryUserInitField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryUserInit;

    uv_mutex_lock (&g_RspQryUserInitTopic_mutex);
    g_RspQryUserInitTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryUserInitTopic_mutex);

    uv_async_send(&g_RspQryUserInitTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryUserInitTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnUserInitTopic(CShfeFtdcRtnUserInitField* pRtnUserInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnUserInitTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnUserInit) { 
        OutputCallbackMessage("pRtnUserInit is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnUserInitTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnUserInit->ParticipantID: ", pRtnUserInit->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserInit->UserID: ", pRtnUserInit->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserInit->UserType: ", pRtnUserInit->UserType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserInit->Password: ", pRtnUserInit->Password, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserInit->IsActive: ", pRtnUserInit->IsActive, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUserInit->OperationType: ", pRtnUserInit->OperationType, g_RunningResult_File);

    CShfeFtdcRtnUserInitField* pNewRtnUserInit = new CShfeFtdcRtnUserInitField;
    memcpy (pNewRtnUserInit, pRtnUserInit, sizeof(CShfeFtdcRtnUserInitField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnUserInit;

    uv_mutex_lock (&g_RtnUserInitTopic_mutex);
    g_RtnUserInitTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnUserInitTopic_mutex);

    uv_async_send(&g_RtnUserInitTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnUserInitTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryClientInitTopic(CShfeFtdcRspQryClientInitField* pRspQryClientInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryClientInitTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryClientInit) { 
        OutputCallbackMessage("pRspQryClientInit is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryClientInitTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryClientInit->ClientID: ", pRspQryClientInit->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientInit->ClientName: ", pRspQryClientInit->ClientName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientInit->IdentifiedCardType: ", pRspQryClientInit->IdentifiedCardType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientInit->IdentifiedCardNo: ", pRspQryClientInit->IdentifiedCardNo, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientInit->TradingRole: ", pRspQryClientInit->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientInit->ClientType: ", pRspQryClientInit->ClientType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientInit->IsActive: ", pRspQryClientInit->IsActive, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientInit->OperationType: ", pRspQryClientInit->OperationType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryClientInitField* pNewRspQryClientInit = new CShfeFtdcRspQryClientInitField;
    memcpy (pNewRspQryClientInit, pRspQryClientInit, sizeof(CShfeFtdcRspQryClientInitField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryClientInit;

    uv_mutex_lock (&g_RspQryClientInitTopic_mutex);
    g_RspQryClientInitTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryClientInitTopic_mutex);

    uv_async_send(&g_RspQryClientInitTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryClientInitTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnClientInitTopic(CShfeFtdcRtnClientInitField* pRtnClientInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnClientInitTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnClientInit) { 
        OutputCallbackMessage("pRtnClientInit is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnClientInitTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnClientInit->ClientID: ", pRtnClientInit->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientInit->ClientName: ", pRtnClientInit->ClientName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientInit->IdentifiedCardType: ", pRtnClientInit->IdentifiedCardType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientInit->IdentifiedCardNo: ", pRtnClientInit->IdentifiedCardNo, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientInit->TradingRole: ", pRtnClientInit->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientInit->ClientType: ", pRtnClientInit->ClientType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientInit->IsActive: ", pRtnClientInit->IsActive, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientInit->OperationType: ", pRtnClientInit->OperationType, g_RunningResult_File);

    CShfeFtdcRtnClientInitField* pNewRtnClientInit = new CShfeFtdcRtnClientInitField;
    memcpy (pNewRtnClientInit, pRtnClientInit, sizeof(CShfeFtdcRtnClientInitField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnClientInit;

    uv_mutex_lock (&g_RtnClientInitTopic_mutex);
    g_RtnClientInitTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnClientInitTopic_mutex);

    uv_async_send(&g_RtnClientInitTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnClientInitTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryTradeLogTopic(CShfeFtdcRspQryTradeLogField* pRspQryTradeLog, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryTradeLogTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryTradeLog) { 
        OutputCallbackMessage("pRspQryTradeLog is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryTradeLogTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryTradeLog->bFlag: ", pRspQryTradeLog->bFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeLog->TradeLogStr: ", pRspQryTradeLog->TradeLogStr, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryTradeLogField* pNewRspQryTradeLog = new CShfeFtdcRspQryTradeLogField;
    memcpy (pNewRspQryTradeLog, pRspQryTradeLog, sizeof(CShfeFtdcRspQryTradeLogField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryTradeLog;

    uv_mutex_lock (&g_RspQryTradeLogTopic_mutex);
    g_RspQryTradeLogTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryTradeLogTopic_mutex);

    uv_async_send(&g_RspQryTradeLogTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryTradeLogTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnTradeLogTopic(CShfeFtdcRtnTradeLogField* pRtnTradeLog, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnTradeLogTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnTradeLog) { 
        OutputCallbackMessage("pRtnTradeLog is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnTradeLogTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnTradeLog->bFlag: ", pRtnTradeLog->bFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeLog->TradeLogStr: ", pRtnTradeLog->TradeLogStr, g_RunningResult_File);

    CShfeFtdcRtnTradeLogField* pNewRtnTradeLog = new CShfeFtdcRtnTradeLogField;
    memcpy (pNewRtnTradeLog, pRtnTradeLog, sizeof(CShfeFtdcRtnTradeLogField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnTradeLog;

    uv_mutex_lock (&g_RtnTradeLogTopic_mutex);
    g_RtnTradeLogTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnTradeLogTopic_mutex);

    uv_async_send(&g_RtnTradeLogTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnTradeLogTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryTradeUserLoginInfoTopic(CShfeFtdcRspQryTradeUserLoginInfoField* pRspQryTradeUserLoginInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryTradeUserLoginInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryTradeUserLoginInfo) { 
        OutputCallbackMessage("pRspQryTradeUserLoginInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryTradeUserLoginInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryTradeUserLoginInfo->ObjectID: ", pRspQryTradeUserLoginInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginInfo->UserID: ", pRspQryTradeUserLoginInfo->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginInfo->ParticipantID: ", pRspQryTradeUserLoginInfo->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginInfo->ProtocolInfo: ", pRspQryTradeUserLoginInfo->ProtocolInfo, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginInfo->IPAddress: ", pRspQryTradeUserLoginInfo->IPAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginInfo->FrontID: ", pRspQryTradeUserLoginInfo->FrontID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginInfo->UserType: ", pRspQryTradeUserLoginInfo->UserType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginInfo->AccessType: ", pRspQryTradeUserLoginInfo->AccessType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginInfo->ActionDate: ", pRspQryTradeUserLoginInfo->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginInfo->ActionTime: ", pRspQryTradeUserLoginInfo->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginInfo->ActionFlag: ", pRspQryTradeUserLoginInfo->ActionFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginInfo->DataCenter: ", pRspQryTradeUserLoginInfo->DataCenter, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryTradeUserLoginInfoField* pNewRspQryTradeUserLoginInfo = new CShfeFtdcRspQryTradeUserLoginInfoField;
    memcpy (pNewRspQryTradeUserLoginInfo, pRspQryTradeUserLoginInfo, sizeof(CShfeFtdcRspQryTradeUserLoginInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryTradeUserLoginInfo;

    uv_mutex_lock (&g_RspQryTradeUserLoginInfoTopic_mutex);
    g_RspQryTradeUserLoginInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryTradeUserLoginInfoTopic_mutex);

    uv_async_send(&g_RspQryTradeUserLoginInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryTradeUserLoginInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnTradeUserLoginInfoTopic(CShfeFtdcRtnTradeUserLoginInfoField* pRtnTradeUserLoginInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnTradeUserLoginInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnTradeUserLoginInfo) { 
        OutputCallbackMessage("pRtnTradeUserLoginInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnTradeUserLoginInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnTradeUserLoginInfo->ObjectID: ", pRtnTradeUserLoginInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeUserLoginInfo->UserID: ", pRtnTradeUserLoginInfo->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeUserLoginInfo->ParticipantID: ", pRtnTradeUserLoginInfo->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeUserLoginInfo->ProtocolInfo: ", pRtnTradeUserLoginInfo->ProtocolInfo, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeUserLoginInfo->IPAddress: ", pRtnTradeUserLoginInfo->IPAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeUserLoginInfo->FrontID: ", pRtnTradeUserLoginInfo->FrontID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeUserLoginInfo->UserType: ", pRtnTradeUserLoginInfo->UserType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeUserLoginInfo->AccessType: ", pRtnTradeUserLoginInfo->AccessType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeUserLoginInfo->ActionDate: ", pRtnTradeUserLoginInfo->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeUserLoginInfo->ActionTime: ", pRtnTradeUserLoginInfo->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeUserLoginInfo->ActionFlag: ", pRtnTradeUserLoginInfo->ActionFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeUserLoginInfo->DataCenter: ", pRtnTradeUserLoginInfo->DataCenter, g_RunningResult_File);

    CShfeFtdcRtnTradeUserLoginInfoField* pNewRtnTradeUserLoginInfo = new CShfeFtdcRtnTradeUserLoginInfoField;
    memcpy (pNewRtnTradeUserLoginInfo, pRtnTradeUserLoginInfo, sizeof(CShfeFtdcRtnTradeUserLoginInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnTradeUserLoginInfo;

    uv_mutex_lock (&g_RtnTradeUserLoginInfoTopic_mutex);
    g_RtnTradeUserLoginInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnTradeUserLoginInfoTopic_mutex);

    uv_async_send(&g_RtnTradeUserLoginInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnTradeUserLoginInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryPartTradeTopic(CShfeFtdcRspQryPartTradeField* pRspQryPartTrade, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryPartTradeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryPartTrade) { 
        OutputCallbackMessage("pRspQryPartTrade is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryPartTradeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryPartTrade->ActionDate: ", pRspQryPartTrade->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartTrade->ActionTime: ", pRspQryPartTrade->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartTrade->InstrumentID: ", pRspQryPartTrade->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartTrade->ParticipantID: ", pRspQryPartTrade->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartTrade->TotalPositiveOrder: ", pRspQryPartTrade->TotalPositiveOrder, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartTrade->TotalNegativeOrder: ", pRspQryPartTrade->TotalNegativeOrder, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartTrade->TotalPositiveTrade: ", pRspQryPartTrade->TotalPositiveTrade, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartTrade->TotalNegativeTrade: ", pRspQryPartTrade->TotalNegativeTrade, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartTrade->TotalPositivePosi: ", pRspQryPartTrade->TotalPositivePosi, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartTrade->TotalNegativePosi: ", pRspQryPartTrade->TotalNegativePosi, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPartTrade->OperationType: ", pRspQryPartTrade->OperationType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryPartTradeField* pNewRspQryPartTrade = new CShfeFtdcRspQryPartTradeField;
    memcpy (pNewRspQryPartTrade, pRspQryPartTrade, sizeof(CShfeFtdcRspQryPartTradeField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryPartTrade;

    uv_mutex_lock (&g_RspQryPartTradeTopic_mutex);
    g_RspQryPartTradeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryPartTradeTopic_mutex);

    uv_async_send(&g_RspQryPartTradeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryPartTradeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryTradepeakTopic(CShfeFtdcRspQryTradepeakField* pRspQryTradepeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryTradepeakTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryTradepeak) { 
        OutputCallbackMessage("pRspQryTradepeak is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryTradepeakTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryTradepeak->TradepeakFlag: ", pRspQryTradepeak->TradepeakFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradepeak->PeakTime: ", pRspQryTradepeak->PeakTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradepeak->InsertOrder: ", pRspQryTradepeak->InsertOrder, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradepeak->ActionOrder: ", pRspQryTradepeak->ActionOrder, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradepeak->InvalidOrder: ", pRspQryTradepeak->InvalidOrder, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradepeak->TotalBusiness: ", pRspQryTradepeak->TotalBusiness, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradepeak->TradeCount: ", pRspQryTradepeak->TradeCount, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradepeak->TotalCount: ", pRspQryTradepeak->TotalCount, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryTradepeakField* pNewRspQryTradepeak = new CShfeFtdcRspQryTradepeakField;
    memcpy (pNewRspQryTradepeak, pRspQryTradepeak, sizeof(CShfeFtdcRspQryTradepeakField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryTradepeak;

    uv_mutex_lock (&g_RspQryTradepeakTopic_mutex);
    g_RspQryTradepeakTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryTradepeakTopic_mutex);

    uv_async_send(&g_RspQryTradepeakTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryTradepeakTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnUpdateSysConfigTopic(CShfeFtdcRtnUpdateSysConfigField* pRtnUpdateSysConfig, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnUpdateSysConfigTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnUpdateSysConfig) { 
        OutputCallbackMessage("pRtnUpdateSysConfig is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnUpdateSysConfigTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnUpdateSysConfig->UpdateType: ", pRtnUpdateSysConfig->UpdateType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUpdateSysConfig->OldValue: ", pRtnUpdateSysConfig->OldValue, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUpdateSysConfig->NewValue: ", pRtnUpdateSysConfig->NewValue, g_RunningResult_File);
    OutputCallbackMessage(" pRtnUpdateSysConfig->Standby: ", pRtnUpdateSysConfig->Standby, g_RunningResult_File);

    CShfeFtdcRtnUpdateSysConfigField* pNewRtnUpdateSysConfig = new CShfeFtdcRtnUpdateSysConfigField;
    memcpy (pNewRtnUpdateSysConfig, pRtnUpdateSysConfig, sizeof(CShfeFtdcRtnUpdateSysConfigField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnUpdateSysConfig;

    uv_mutex_lock (&g_RtnUpdateSysConfigTopic_mutex);
    g_RtnUpdateSysConfigTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnUpdateSysConfigTopic_mutex);

    uv_async_send(&g_RtnUpdateSysConfigTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnUpdateSysConfigTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnSysUser(CShfeFtdcRtnSysUserField* pRtnSysUser, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnSysUser: START! ******", g_RunningResult_File);

    if (NULL == pRtnSysUser) { 
        OutputCallbackMessage("pRtnSysUser is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnSysUser: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnSysUser->UserID: ", pRtnSysUser->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysUser->UserName: ", pRtnSysUser->UserName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysUser->UserInfo: ", pRtnSysUser->UserInfo, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysUser->Password: ", pRtnSysUser->Password, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysUser->Privilege: ", pRtnSysUser->Privilege, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysUser->EMail: ", pRtnSysUser->EMail, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysUser->EMailFlag: ", pRtnSysUser->EMailFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysUser->HomePhone: ", pRtnSysUser->HomePhone, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysUser->HomePhoneFlag: ", pRtnSysUser->HomePhoneFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysUser->MobilePhone: ", pRtnSysUser->MobilePhone, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysUser->MobilePhoneFlag: ", pRtnSysUser->MobilePhoneFlag, g_RunningResult_File);

    CShfeFtdcRtnSysUserField* pNewRtnSysUser = new CShfeFtdcRtnSysUserField;
    memcpy (pNewRtnSysUser, pRtnSysUser, sizeof(CShfeFtdcRtnSysUserField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnSysUser;

    uv_mutex_lock (&g_RtnSysUser_mutex);
    g_RtnSysUser_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnSysUser_mutex);

    uv_async_send(&g_RtnSysUser_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnSysUser: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnPriceLimitChgTopic(CShfeFtdcRtnPriceLimitChgField* pRtnPriceLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnPriceLimitChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnPriceLimitChg) { 
        OutputCallbackMessage("pRtnPriceLimitChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnPriceLimitChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnPriceLimitChg->ActionDate: ", pRtnPriceLimitChg->ActionDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPriceLimitChg->ActionTime: ", pRtnPriceLimitChg->ActionTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPriceLimitChg->InstrumentID: ", pRtnPriceLimitChg->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPriceLimitChg->ValueMode: ", pRtnPriceLimitChg->ValueMode, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPriceLimitChg->RoundingMode: ", pRtnPriceLimitChg->RoundingMode, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPriceLimitChg->UpperLimitPrice: ", pRtnPriceLimitChg->UpperLimitPrice, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPriceLimitChg->LowerLimitPrice: ", pRtnPriceLimitChg->LowerLimitPrice, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPriceLimitChg->OperationType: ", pRtnPriceLimitChg->OperationType, g_RunningResult_File);

    CShfeFtdcRtnPriceLimitChgField* pNewRtnPriceLimitChg = new CShfeFtdcRtnPriceLimitChgField;
    memcpy (pNewRtnPriceLimitChg, pRtnPriceLimitChg, sizeof(CShfeFtdcRtnPriceLimitChgField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnPriceLimitChg;

    uv_mutex_lock (&g_RtnPriceLimitChgTopic_mutex);
    g_RtnPriceLimitChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnPriceLimitChgTopic_mutex);

    uv_async_send(&g_RtnPriceLimitChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnPriceLimitChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryHistoryCpuInfoTopic(CShfeFtdcRspQryHistoryCpuInfoField* pRspQryHistoryCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryHistoryCpuInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryHistoryCpuInfo) { 
        OutputCallbackMessage("pRspQryHistoryCpuInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryHistoryCpuInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryHistoryCpuInfo->HostName: ", pRspQryHistoryCpuInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryCpuInfo->MonDate: ", pRspQryHistoryCpuInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryCpuInfo->MonTime: ", pRspQryHistoryCpuInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryCpuInfo->CPU: ", pRspQryHistoryCpuInfo->CPU, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryCpuInfo->LOAD: ", pRspQryHistoryCpuInfo->LOAD, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryCpuInfo->USER: ", pRspQryHistoryCpuInfo->USER, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryCpuInfo->NICE: ", pRspQryHistoryCpuInfo->NICE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryCpuInfo->SYS: ", pRspQryHistoryCpuInfo->SYS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryCpuInfo->IDLE: ", pRspQryHistoryCpuInfo->IDLE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryCpuInfo->BLOCK: ", pRspQryHistoryCpuInfo->BLOCK, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryCpuInfo->SWAIT: ", pRspQryHistoryCpuInfo->SWAIT, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryCpuInfo->INTR: ", pRspQryHistoryCpuInfo->INTR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryCpuInfo->SSYS: ", pRspQryHistoryCpuInfo->SSYS, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryHistoryCpuInfoField* pNewRspQryHistoryCpuInfo = new CShfeFtdcRspQryHistoryCpuInfoField;
    memcpy (pNewRspQryHistoryCpuInfo, pRspQryHistoryCpuInfo, sizeof(CShfeFtdcRspQryHistoryCpuInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryHistoryCpuInfo;

    uv_mutex_lock (&g_RspQryHistoryCpuInfoTopic_mutex);
    g_RspQryHistoryCpuInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryHistoryCpuInfoTopic_mutex);

    uv_async_send(&g_RspQryHistoryCpuInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryHistoryCpuInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryHistoryMemInfoTopic(CShfeFtdcRspQryHistoryMemInfoField* pRspQryHistoryMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryHistoryMemInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryHistoryMemInfo) { 
        OutputCallbackMessage("pRspQryHistoryMemInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryHistoryMemInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryHistoryMemInfo->HostName: ", pRspQryHistoryMemInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryMemInfo->MonDate: ", pRspQryHistoryMemInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryMemInfo->MonTime: ", pRspQryHistoryMemInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryMemInfo->TOTALREAL: ", pRspQryHistoryMemInfo->TOTALREAL, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryMemInfo->ACTIVEREAL: ", pRspQryHistoryMemInfo->ACTIVEREAL, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryMemInfo->TOTALVIRTUAL: ", pRspQryHistoryMemInfo->TOTALVIRTUAL, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryMemInfo->ACTIVEVIRTUAL: ", pRspQryHistoryMemInfo->ACTIVEVIRTUAL, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryMemInfo->FREE: ", pRspQryHistoryMemInfo->FREE, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryHistoryMemInfoField* pNewRspQryHistoryMemInfo = new CShfeFtdcRspQryHistoryMemInfoField;
    memcpy (pNewRspQryHistoryMemInfo, pRspQryHistoryMemInfo, sizeof(CShfeFtdcRspQryHistoryMemInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryHistoryMemInfo;

    uv_mutex_lock (&g_RspQryHistoryMemInfoTopic_mutex);
    g_RspQryHistoryMemInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryHistoryMemInfoTopic_mutex);

    uv_async_send(&g_RspQryHistoryMemInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryHistoryMemInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryHistoryNetworkInfoTopic(CShfeFtdcRspQryHistoryNetworkInfoField* pRspQryHistoryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryHistoryNetworkInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryHistoryNetworkInfo) { 
        OutputCallbackMessage("pRspQryHistoryNetworkInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryHistoryNetworkInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryHistoryNetworkInfo->HostName: ", pRspQryHistoryNetworkInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryNetworkInfo->MonDate: ", pRspQryHistoryNetworkInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryNetworkInfo->MonTime: ", pRspQryHistoryNetworkInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryNetworkInfo->LANNAME: ", pRspQryHistoryNetworkInfo->LANNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryNetworkInfo->LANSTATUS: ", pRspQryHistoryNetworkInfo->LANSTATUS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryNetworkInfo->IPADDRESS: ", pRspQryHistoryNetworkInfo->IPADDRESS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryNetworkInfo->RECVBYTES: ", pRspQryHistoryNetworkInfo->RECVBYTES, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryNetworkInfo->RECVPACKETS: ", pRspQryHistoryNetworkInfo->RECVPACKETS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryNetworkInfo->RECVERRORPACKETS: ", pRspQryHistoryNetworkInfo->RECVERRORPACKETS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryNetworkInfo->RECVDROPPACKETS: ", pRspQryHistoryNetworkInfo->RECVDROPPACKETS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryNetworkInfo->SENDBYTES: ", pRspQryHistoryNetworkInfo->SENDBYTES, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryNetworkInfo->SENDPACKETS: ", pRspQryHistoryNetworkInfo->SENDPACKETS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryNetworkInfo->SENDERRORPACKETS: ", pRspQryHistoryNetworkInfo->SENDERRORPACKETS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryNetworkInfo->SENDDROPPACKETS: ", pRspQryHistoryNetworkInfo->SENDDROPPACKETS, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryHistoryNetworkInfoField* pNewRspQryHistoryNetworkInfo = new CShfeFtdcRspQryHistoryNetworkInfoField;
    memcpy (pNewRspQryHistoryNetworkInfo, pRspQryHistoryNetworkInfo, sizeof(CShfeFtdcRspQryHistoryNetworkInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryHistoryNetworkInfo;

    uv_mutex_lock (&g_RspQryHistoryNetworkInfoTopic_mutex);
    g_RspQryHistoryNetworkInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryHistoryNetworkInfoTopic_mutex);

    uv_async_send(&g_RspQryHistoryNetworkInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryHistoryNetworkInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryMonitorOnlineUser(CShfeFtdcRspQryMonitorOnlineUserField* pRspQryMonitorOnlineUser, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryMonitorOnlineUser: START! ******", g_RunningResult_File);

    if (NULL == pRspQryMonitorOnlineUser) { 
        OutputCallbackMessage("pRspQryMonitorOnlineUser is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryMonitorOnlineUser: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryMonitorOnlineUser->UserID: ", pRspQryMonitorOnlineUser->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMonitorOnlineUser->IPAddress: ", pRspQryMonitorOnlineUser->IPAddress, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryMonitorOnlineUserField* pNewRspQryMonitorOnlineUser = new CShfeFtdcRspQryMonitorOnlineUserField;
    memcpy (pNewRspQryMonitorOnlineUser, pRspQryMonitorOnlineUser, sizeof(CShfeFtdcRspQryMonitorOnlineUserField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryMonitorOnlineUser;

    uv_mutex_lock (&g_RspQryMonitorOnlineUser_mutex);
    g_RspQryMonitorOnlineUser_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryMonitorOnlineUser_mutex);

    uv_async_send(&g_RspQryMonitorOnlineUser_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryMonitorOnlineUser: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryFrontStat(CShfeFtdcRspQryFrontStatField* pRspQryFrontStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryFrontStat: START! ******", g_RunningResult_File);

    if (NULL == pRspQryFrontStat) { 
        OutputCallbackMessage("pRspQryFrontStat is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryFrontStat: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryFrontStat->FrontID: ", pRspQryFrontStat->FrontID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFrontStat->PositiveOrder: ", pRspQryFrontStat->PositiveOrder, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFrontStat->NegativeOrder: ", pRspQryFrontStat->NegativeOrder, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFrontStat->TotalPositiveOrder: ", pRspQryFrontStat->TotalPositiveOrder, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFrontStat->TotalNegativeOrder: ", pRspQryFrontStat->TotalNegativeOrder, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFrontStat->OrderAction: ", pRspQryFrontStat->OrderAction, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFrontStat->TotalOrderAction: ", pRspQryFrontStat->TotalOrderAction, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryFrontStatField* pNewRspQryFrontStat = new CShfeFtdcRspQryFrontStatField;
    memcpy (pNewRspQryFrontStat, pRspQryFrontStat, sizeof(CShfeFtdcRspQryFrontStatField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryFrontStat;

    uv_mutex_lock (&g_RspQryFrontStat_mutex);
    g_RspQryFrontStat_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryFrontStat_mutex);

    uv_async_send(&g_RspQryFrontStat_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryFrontStat: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnSysTimeSyncTopic(CShfeFtdcRtnSysTimeSyncField* pRtnSysTimeSync, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnSysTimeSyncTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnSysTimeSync) { 
        OutputCallbackMessage("pRtnSysTimeSync is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnSysTimeSyncTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnSysTimeSync->MonDate: ", pRtnSysTimeSync->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysTimeSync->MonTime: ", pRtnSysTimeSync->MonTime, g_RunningResult_File);

    CShfeFtdcRtnSysTimeSyncField* pNewRtnSysTimeSync = new CShfeFtdcRtnSysTimeSyncField;
    memcpy (pNewRtnSysTimeSync, pRtnSysTimeSync, sizeof(CShfeFtdcRtnSysTimeSyncField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnSysTimeSync;

    uv_mutex_lock (&g_RtnSysTimeSyncTopic_mutex);
    g_RtnSysTimeSyncTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnSysTimeSyncTopic_mutex);

    uv_async_send(&g_RtnSysTimeSyncTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnSysTimeSyncTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnDataCenterChgTopic(CShfeFtdcRtnDataCenterChgField* pRtnDataCenterChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnDataCenterChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnDataCenterChg) { 
        OutputCallbackMessage("pRtnDataCenterChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnDataCenterChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnDataCenterChg->DataCenterID: ", pRtnDataCenterChg->DataCenterID, g_RunningResult_File);

    CShfeFtdcRtnDataCenterChgField* pNewRtnDataCenterChg = new CShfeFtdcRtnDataCenterChgField;
    memcpy (pNewRtnDataCenterChg, pRtnDataCenterChg, sizeof(CShfeFtdcRtnDataCenterChgField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnDataCenterChg;

    uv_mutex_lock (&g_RtnDataCenterChgTopic_mutex);
    g_RtnDataCenterChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnDataCenterChgTopic_mutex);

    uv_async_send(&g_RtnDataCenterChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnDataCenterChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryHistoryTradePeakTopic(CShfeFtdcRspQryHistoryTradePeakField* pRspQryHistoryTradePeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryHistoryTradePeakTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryHistoryTradePeak) { 
        OutputCallbackMessage("pRspQryHistoryTradePeak is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryHistoryTradePeakTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryHistoryTradePeak->ObjectID: ", pRspQryHistoryTradePeak->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryTradePeak->MonDate: ", pRspQryHistoryTradePeak->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryTradePeak->MonTime: ", pRspQryHistoryTradePeak->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryTradePeak->AttrType: ", pRspQryHistoryTradePeak->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryTradePeak->AttrValue: ", pRspQryHistoryTradePeak->AttrValue, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryTradePeak->RltAttrType: ", pRspQryHistoryTradePeak->RltAttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryTradePeak->RltAttrValue: ", pRspQryHistoryTradePeak->RltAttrValue, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryTradePeak->MaxMonDate: ", pRspQryHistoryTradePeak->MaxMonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryTradePeak->MaxMonTime: ", pRspQryHistoryTradePeak->MaxMonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryTradePeak->MaxAttrValue: ", pRspQryHistoryTradePeak->MaxAttrValue, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryTradePeak->MaxRltAttrValue: ", pRspQryHistoryTradePeak->MaxRltAttrValue, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryTradePeak->OldMonDate: ", pRspQryHistoryTradePeak->OldMonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryTradePeak->OldMonTime: ", pRspQryHistoryTradePeak->OldMonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryTradePeak->OldAttrValue: ", pRspQryHistoryTradePeak->OldAttrValue, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryHistoryTradePeak->OldRltAttrValue: ", pRspQryHistoryTradePeak->OldRltAttrValue, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryHistoryTradePeakField* pNewRspQryHistoryTradePeak = new CShfeFtdcRspQryHistoryTradePeakField;
    memcpy (pNewRspQryHistoryTradePeak, pRspQryHistoryTradePeak, sizeof(CShfeFtdcRspQryHistoryTradePeakField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryHistoryTradePeak;

    uv_mutex_lock (&g_RspQryHistoryTradePeakTopic_mutex);
    g_RspQryHistoryTradePeakTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryHistoryTradePeakTopic_mutex);

    uv_async_send(&g_RspQryHistoryTradePeakTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryHistoryTradePeakTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnHistoryTradePeakTopic(CShfeFtdcRtnHistoryTradePeakField* pRtnHistoryTradePeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnHistoryTradePeakTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnHistoryTradePeak) { 
        OutputCallbackMessage("pRtnHistoryTradePeak is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnHistoryTradePeakTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnHistoryTradePeak->ObjectID: ", pRtnHistoryTradePeak->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryTradePeak->MonDate: ", pRtnHistoryTradePeak->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryTradePeak->MonTime: ", pRtnHistoryTradePeak->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryTradePeak->AttrType: ", pRtnHistoryTradePeak->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryTradePeak->AttrValue: ", pRtnHistoryTradePeak->AttrValue, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryTradePeak->RltAttrType: ", pRtnHistoryTradePeak->RltAttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryTradePeak->RltAttrValue: ", pRtnHistoryTradePeak->RltAttrValue, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryTradePeak->MaxMonDate: ", pRtnHistoryTradePeak->MaxMonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryTradePeak->MaxMonTime: ", pRtnHistoryTradePeak->MaxMonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryTradePeak->MaxAttrValue: ", pRtnHistoryTradePeak->MaxAttrValue, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryTradePeak->MaxRltAttrValue: ", pRtnHistoryTradePeak->MaxRltAttrValue, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryTradePeak->OldMonDate: ", pRtnHistoryTradePeak->OldMonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryTradePeak->OldMonTime: ", pRtnHistoryTradePeak->OldMonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryTradePeak->OldAttrValue: ", pRtnHistoryTradePeak->OldAttrValue, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHistoryTradePeak->OldRltAttrValue: ", pRtnHistoryTradePeak->OldRltAttrValue, g_RunningResult_File);

    CShfeFtdcRtnHistoryTradePeakField* pNewRtnHistoryTradePeak = new CShfeFtdcRtnHistoryTradePeakField;
    memcpy (pNewRtnHistoryTradePeak, pRtnHistoryTradePeak, sizeof(CShfeFtdcRtnHistoryTradePeakField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnHistoryTradePeak;

    uv_mutex_lock (&g_RtnHistoryTradePeakTopic_mutex);
    g_RtnHistoryTradePeakTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnHistoryTradePeakTopic_mutex);

    uv_async_send(&g_RtnHistoryTradePeakTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnHistoryTradePeakTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQrySyslogEventTopic(CShfeFtdcRspQrySyslogEventField* pRspQrySyslogEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQrySyslogEventTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQrySyslogEvent) { 
        OutputCallbackMessage("pRspQrySyslogEvent is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQrySyslogEventTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQrySyslogEvent->MonDate: ", pRspQrySyslogEvent->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogEvent->MonTime: ", pRspQrySyslogEvent->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogEvent->OccurDate: ", pRspQrySyslogEvent->OccurDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogEvent->OccurTime: ", pRspQrySyslogEvent->OccurTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogEvent->EvendID: ", pRspQrySyslogEvent->EvendID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogEvent->ObjectID: ", pRspQrySyslogEvent->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogEvent->IPAddress: ", pRspQrySyslogEvent->IPAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogEvent->EventName: ", pRspQrySyslogEvent->EventName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogEvent->EventNum: ", pRspQrySyslogEvent->EventNum, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogEvent->EventType: ", pRspQrySyslogEvent->EventType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogEvent->EventDes: ", pRspQrySyslogEvent->EventDes, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogEvent->ProcessFlag: ", pRspQrySyslogEvent->ProcessFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogEvent->WarningLevel: ", pRspQrySyslogEvent->WarningLevel, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogEvent->EventDealDes: ", pRspQrySyslogEvent->EventDealDes, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogEvent->FullEventName: ", pRspQrySyslogEvent->FullEventName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySyslogEvent->EventCount: ", pRspQrySyslogEvent->EventCount, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQrySyslogEventField* pNewRspQrySyslogEvent = new CShfeFtdcRspQrySyslogEventField;
    memcpy (pNewRspQrySyslogEvent, pRspQrySyslogEvent, sizeof(CShfeFtdcRspQrySyslogEventField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQrySyslogEvent;

    uv_mutex_lock (&g_RspQrySyslogEventTopic_mutex);
    g_RspQrySyslogEventTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQrySyslogEventTopic_mutex);

    uv_async_send(&g_RspQrySyslogEventTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQrySyslogEventTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnSyslogEventTopic(CShfeFtdcRtnSyslogEventField* pRtnSyslogEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnSyslogEventTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnSyslogEvent) { 
        OutputCallbackMessage("pRtnSyslogEvent is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnSyslogEventTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnSyslogEvent->MonDate: ", pRtnSyslogEvent->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogEvent->MonTime: ", pRtnSyslogEvent->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogEvent->OccurDate: ", pRtnSyslogEvent->OccurDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogEvent->OccurTime: ", pRtnSyslogEvent->OccurTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogEvent->EvendID: ", pRtnSyslogEvent->EvendID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogEvent->ObjectID: ", pRtnSyslogEvent->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogEvent->IPAddress: ", pRtnSyslogEvent->IPAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogEvent->EventName: ", pRtnSyslogEvent->EventName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogEvent->EventNum: ", pRtnSyslogEvent->EventNum, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogEvent->EventType: ", pRtnSyslogEvent->EventType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogEvent->EventDes: ", pRtnSyslogEvent->EventDes, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogEvent->ProcessFlag: ", pRtnSyslogEvent->ProcessFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogEvent->WarningLevel: ", pRtnSyslogEvent->WarningLevel, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogEvent->EventDealDes: ", pRtnSyslogEvent->EventDealDes, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSyslogEvent->FullEventName: ", pRtnSyslogEvent->FullEventName, g_RunningResult_File);

    CShfeFtdcRtnSyslogEventField* pNewRtnSyslogEvent = new CShfeFtdcRtnSyslogEventField;
    memcpy (pNewRtnSyslogEvent, pRtnSyslogEvent, sizeof(CShfeFtdcRtnSyslogEventField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnSyslogEvent;

    uv_mutex_lock (&g_RtnSyslogEventTopic_mutex);
    g_RtnSyslogEventTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnSyslogEventTopic_mutex);

    uv_async_send(&g_RtnSyslogEventTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnSyslogEventTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryTradeDayChangeTopic(CShfeFtdcRspQryTradeDayChangeField* pRspQryTradeDayChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryTradeDayChangeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryTradeDayChange) { 
        OutputCallbackMessage("pRspQryTradeDayChange is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryTradeDayChangeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryTradeDayChange->ChangeType: ", pRspQryTradeDayChange->ChangeType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeDayChange->OldDate: ", pRspQryTradeDayChange->OldDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeDayChange->NewDate: ", pRspQryTradeDayChange->NewDate, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryTradeDayChangeField* pNewRspQryTradeDayChange = new CShfeFtdcRspQryTradeDayChangeField;
    memcpy (pNewRspQryTradeDayChange, pRspQryTradeDayChange, sizeof(CShfeFtdcRspQryTradeDayChangeField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryTradeDayChange;

    uv_mutex_lock (&g_RspQryTradeDayChangeTopic_mutex);
    g_RspQryTradeDayChangeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryTradeDayChangeTopic_mutex);

    uv_async_send(&g_RspQryTradeDayChangeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryTradeDayChangeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryWebAppInfoTopic(CShfeFtdcRspQryWebAppInfoField* pRspQryWebAppInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryWebAppInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryWebAppInfo) { 
        OutputCallbackMessage("pRspQryWebAppInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryWebAppInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryWebAppInfo->ObjectID: ", pRspQryWebAppInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWebAppInfo->MonDate: ", pRspQryWebAppInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWebAppInfo->MonTime: ", pRspQryWebAppInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWebAppInfo->AppName: ", pRspQryWebAppInfo->AppName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWebAppInfo->Status: ", pRspQryWebAppInfo->Status, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWebAppInfo->Desc: ", pRspQryWebAppInfo->Desc, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWebAppInfo->StartTime: ", pRspQryWebAppInfo->StartTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWebAppInfo->ServletNum: ", pRspQryWebAppInfo->ServletNum, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWebAppInfo->ProcessTime: ", pRspQryWebAppInfo->ProcessTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWebAppInfo->RequestNum: ", pRspQryWebAppInfo->RequestNum, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWebAppInfo->ErrorNum: ", pRspQryWebAppInfo->ErrorNum, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWebAppInfo->SessionSize: ", pRspQryWebAppInfo->SessionSize, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWebAppInfo->TimeOut: ", pRspQryWebAppInfo->TimeOut, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWebAppInfo->JDBCUsage: ", pRspQryWebAppInfo->JDBCUsage, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWebAppInfo->JSPNum: ", pRspQryWebAppInfo->JSPNum, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryWebAppInfoField* pNewRspQryWebAppInfo = new CShfeFtdcRspQryWebAppInfoField;
    memcpy (pNewRspQryWebAppInfo, pRspQryWebAppInfo, sizeof(CShfeFtdcRspQryWebAppInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryWebAppInfo;

    uv_mutex_lock (&g_RspQryWebAppInfoTopic_mutex);
    g_RspQryWebAppInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryWebAppInfoTopic_mutex);

    uv_async_send(&g_RspQryWebAppInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryWebAppInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnWebAppInfoTopic(CShfeFtdcRtnWebAppInfoField* pRtnWebAppInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnWebAppInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnWebAppInfo) { 
        OutputCallbackMessage("pRtnWebAppInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnWebAppInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnWebAppInfo->ObjectID: ", pRtnWebAppInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWebAppInfo->MonDate: ", pRtnWebAppInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWebAppInfo->MonTime: ", pRtnWebAppInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWebAppInfo->AppName: ", pRtnWebAppInfo->AppName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWebAppInfo->Status: ", pRtnWebAppInfo->Status, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWebAppInfo->Desc: ", pRtnWebAppInfo->Desc, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWebAppInfo->StartTime: ", pRtnWebAppInfo->StartTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWebAppInfo->ServletNum: ", pRtnWebAppInfo->ServletNum, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWebAppInfo->ProcessTime: ", pRtnWebAppInfo->ProcessTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWebAppInfo->RequestNum: ", pRtnWebAppInfo->RequestNum, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWebAppInfo->ErrorNum: ", pRtnWebAppInfo->ErrorNum, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWebAppInfo->SessionSize: ", pRtnWebAppInfo->SessionSize, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWebAppInfo->TimeOut: ", pRtnWebAppInfo->TimeOut, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWebAppInfo->JDBCUsage: ", pRtnWebAppInfo->JDBCUsage, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWebAppInfo->JSPNum: ", pRtnWebAppInfo->JSPNum, g_RunningResult_File);

    CShfeFtdcRtnWebAppInfoField* pNewRtnWebAppInfo = new CShfeFtdcRtnWebAppInfoField;
    memcpy (pNewRtnWebAppInfo, pRtnWebAppInfo, sizeof(CShfeFtdcRtnWebAppInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnWebAppInfo;

    uv_mutex_lock (&g_RtnWebAppInfoTopic_mutex);
    g_RtnWebAppInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnWebAppInfoTopic_mutex);

    uv_async_send(&g_RtnWebAppInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnWebAppInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryServletInfoTopic(CShfeFtdcRspQryServletInfoField* pRspQryServletInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryServletInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryServletInfo) { 
        OutputCallbackMessage("pRspQryServletInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryServletInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryServletInfo->ObjectID: ", pRspQryServletInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryServletInfo->MonDate: ", pRspQryServletInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryServletInfo->MonTime: ", pRspQryServletInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryServletInfo->Name: ", pRspQryServletInfo->Name, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryServletInfo->LoadTime: ", pRspQryServletInfo->LoadTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryServletInfo->RequestNum: ", pRspQryServletInfo->RequestNum, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryServletInfo->RequestErrNum: ", pRspQryServletInfo->RequestErrNum, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryServletInfo->ProcessTime: ", pRspQryServletInfo->ProcessTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryServletInfo->MixTime: ", pRspQryServletInfo->MixTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryServletInfo->MaxTime: ", pRspQryServletInfo->MaxTime, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryServletInfoField* pNewRspQryServletInfo = new CShfeFtdcRspQryServletInfoField;
    memcpy (pNewRspQryServletInfo, pRspQryServletInfo, sizeof(CShfeFtdcRspQryServletInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryServletInfo;

    uv_mutex_lock (&g_RspQryServletInfoTopic_mutex);
    g_RspQryServletInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryServletInfoTopic_mutex);

    uv_async_send(&g_RspQryServletInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryServletInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnServletInfoTopic(CShfeFtdcRtnServletInfoField* pRtnServletInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnServletInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnServletInfo) { 
        OutputCallbackMessage("pRtnServletInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnServletInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnServletInfo->ObjectID: ", pRtnServletInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnServletInfo->MonDate: ", pRtnServletInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnServletInfo->MonTime: ", pRtnServletInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnServletInfo->Name: ", pRtnServletInfo->Name, g_RunningResult_File);
    OutputCallbackMessage(" pRtnServletInfo->LoadTime: ", pRtnServletInfo->LoadTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnServletInfo->RequestNum: ", pRtnServletInfo->RequestNum, g_RunningResult_File);
    OutputCallbackMessage(" pRtnServletInfo->RequestErrNum: ", pRtnServletInfo->RequestErrNum, g_RunningResult_File);
    OutputCallbackMessage(" pRtnServletInfo->ProcessTime: ", pRtnServletInfo->ProcessTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnServletInfo->MixTime: ", pRtnServletInfo->MixTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnServletInfo->MaxTime: ", pRtnServletInfo->MaxTime, g_RunningResult_File);

    CShfeFtdcRtnServletInfoField* pNewRtnServletInfo = new CShfeFtdcRtnServletInfoField;
    memcpy (pNewRtnServletInfo, pRtnServletInfo, sizeof(CShfeFtdcRtnServletInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnServletInfo;

    uv_mutex_lock (&g_RtnServletInfoTopic_mutex);
    g_RtnServletInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnServletInfoTopic_mutex);

    uv_async_send(&g_RtnServletInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnServletInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryFileInfoTopic(CShfeFtdcRspQryFileInfoField* pRspQryFileInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryFileInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryFileInfo) { 
        OutputCallbackMessage("pRspQryFileInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryFileInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryFileInfo->ObjectID: ", pRspQryFileInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileInfo->MonDate: ", pRspQryFileInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileInfo->MonTime: ", pRspQryFileInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileInfo->PathName: ", pRspQryFileInfo->PathName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileInfo->FileSize: ", pRspQryFileInfo->FileSize, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileInfo->LastModDate: ", pRspQryFileInfo->LastModDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileInfo->FileType: ", pRspQryFileInfo->FileType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryFileInfoField* pNewRspQryFileInfo = new CShfeFtdcRspQryFileInfoField;
    memcpy (pNewRspQryFileInfo, pRspQryFileInfo, sizeof(CShfeFtdcRspQryFileInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryFileInfo;

    uv_mutex_lock (&g_RspQryFileInfoTopic_mutex);
    g_RspQryFileInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryFileInfoTopic_mutex);

    uv_async_send(&g_RspQryFileInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryFileInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnFileInfoTopic(CShfeFtdcRtnFileInfoField* pRtnFileInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnFileInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnFileInfo) { 
        OutputCallbackMessage("pRtnFileInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnFileInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnFileInfo->ObjectID: ", pRtnFileInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileInfo->MonDate: ", pRtnFileInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileInfo->MonTime: ", pRtnFileInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileInfo->PathName: ", pRtnFileInfo->PathName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileInfo->FileSize: ", pRtnFileInfo->FileSize, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileInfo->LastModDate: ", pRtnFileInfo->LastModDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileInfo->FileType: ", pRtnFileInfo->FileType, g_RunningResult_File);

    CShfeFtdcRtnFileInfoField* pNewRtnFileInfo = new CShfeFtdcRtnFileInfoField;
    memcpy (pNewRtnFileInfo, pRtnFileInfo, sizeof(CShfeFtdcRtnFileInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnFileInfo;

    uv_mutex_lock (&g_RtnFileInfoTopic_mutex);
    g_RtnFileInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnFileInfoTopic_mutex);

    uv_async_send(&g_RtnFileInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnFileInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQrySessionInfoTopic(CShfeFtdcRspQrySessionInfoField* pRspQrySessionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQrySessionInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQrySessionInfo) { 
        OutputCallbackMessage("pRspQrySessionInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQrySessionInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQrySessionInfo->ObjectID: ", pRspQrySessionInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySessionInfo->MonDate: ", pRspQrySessionInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySessionInfo->MonTime: ", pRspQrySessionInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySessionInfo->SessionID: ", pRspQrySessionInfo->SessionID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySessionInfo->SessionName: ", pRspQrySessionInfo->SessionName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySessionInfo->RemoteIP: ", pRspQrySessionInfo->RemoteIP, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySessionInfo->BeginTime: ", pRspQrySessionInfo->BeginTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySessionInfo->LatestTime: ", pRspQrySessionInfo->LatestTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySessionInfo->MaxIdleTime: ", pRspQrySessionInfo->MaxIdleTime, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQrySessionInfoField* pNewRspQrySessionInfo = new CShfeFtdcRspQrySessionInfoField;
    memcpy (pNewRspQrySessionInfo, pRspQrySessionInfo, sizeof(CShfeFtdcRspQrySessionInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQrySessionInfo;

    uv_mutex_lock (&g_RspQrySessionInfoTopic_mutex);
    g_RspQrySessionInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQrySessionInfoTopic_mutex);

    uv_async_send(&g_RspQrySessionInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQrySessionInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnSessionInfoTopic(CShfeFtdcRtnSessionInfoField* pRtnSessionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnSessionInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnSessionInfo) { 
        OutputCallbackMessage("pRtnSessionInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnSessionInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnSessionInfo->ObjectID: ", pRtnSessionInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSessionInfo->MonDate: ", pRtnSessionInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSessionInfo->MonTime: ", pRtnSessionInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSessionInfo->SessionID: ", pRtnSessionInfo->SessionID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSessionInfo->SessionName: ", pRtnSessionInfo->SessionName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSessionInfo->RemoteIP: ", pRtnSessionInfo->RemoteIP, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSessionInfo->BeginTime: ", pRtnSessionInfo->BeginTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSessionInfo->LatestTime: ", pRtnSessionInfo->LatestTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSessionInfo->MaxIdleTime: ", pRtnSessionInfo->MaxIdleTime, g_RunningResult_File);

    CShfeFtdcRtnSessionInfoField* pNewRtnSessionInfo = new CShfeFtdcRtnSessionInfoField;
    memcpy (pNewRtnSessionInfo, pRtnSessionInfo, sizeof(CShfeFtdcRtnSessionInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnSessionInfo;

    uv_mutex_lock (&g_RtnSessionInfoTopic_mutex);
    g_RtnSessionInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnSessionInfoTopic_mutex);

    uv_async_send(&g_RtnSessionInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnSessionInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryJDBCInfoTopic(CShfeFtdcRspQryJDBCInfoField* pRspQryJDBCInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryJDBCInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryJDBCInfo) { 
        OutputCallbackMessage("pRspQryJDBCInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryJDBCInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryJDBCInfo->ObjectID: ", pRspQryJDBCInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryJDBCInfo->MonDate: ", pRspQryJDBCInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryJDBCInfo->MonTime: ", pRspQryJDBCInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryJDBCInfo->AppName: ", pRspQryJDBCInfo->AppName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryJDBCInfo->Name: ", pRspQryJDBCInfo->Name, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryJDBCInfo->Usage: ", pRspQryJDBCInfo->Usage, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryJDBCInfo->ConnNumMax: ", pRspQryJDBCInfo->ConnNumMax, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryJDBCInfo->ConnNumFree: ", pRspQryJDBCInfo->ConnNumFree, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryJDBCInfo->ConnNumUnRU: ", pRspQryJDBCInfo->ConnNumUnRU, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryJDBCInfo->ConnNumRU: ", pRspQryJDBCInfo->ConnNumRU, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryJDBCInfo->UserName: ", pRspQryJDBCInfo->UserName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryJDBCInfo->Type: ", pRspQryJDBCInfo->Type, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryJDBCInfo->URL: ", pRspQryJDBCInfo->URL, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryJDBCInfoField* pNewRspQryJDBCInfo = new CShfeFtdcRspQryJDBCInfoField;
    memcpy (pNewRspQryJDBCInfo, pRspQryJDBCInfo, sizeof(CShfeFtdcRspQryJDBCInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryJDBCInfo;

    uv_mutex_lock (&g_RspQryJDBCInfoTopic_mutex);
    g_RspQryJDBCInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryJDBCInfoTopic_mutex);

    uv_async_send(&g_RspQryJDBCInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryJDBCInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnJDBCInfoTopic(CShfeFtdcRtnJDBCInfoField* pRtnJDBCInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnJDBCInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnJDBCInfo) { 
        OutputCallbackMessage("pRtnJDBCInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnJDBCInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnJDBCInfo->ObjectID: ", pRtnJDBCInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnJDBCInfo->MonDate: ", pRtnJDBCInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnJDBCInfo->MonTime: ", pRtnJDBCInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnJDBCInfo->AppName: ", pRtnJDBCInfo->AppName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnJDBCInfo->Name: ", pRtnJDBCInfo->Name, g_RunningResult_File);
    OutputCallbackMessage(" pRtnJDBCInfo->Usage: ", pRtnJDBCInfo->Usage, g_RunningResult_File);
    OutputCallbackMessage(" pRtnJDBCInfo->ConnNumMax: ", pRtnJDBCInfo->ConnNumMax, g_RunningResult_File);
    OutputCallbackMessage(" pRtnJDBCInfo->ConnNumFree: ", pRtnJDBCInfo->ConnNumFree, g_RunningResult_File);
    OutputCallbackMessage(" pRtnJDBCInfo->ConnNumUnRU: ", pRtnJDBCInfo->ConnNumUnRU, g_RunningResult_File);
    OutputCallbackMessage(" pRtnJDBCInfo->ConnNumRU: ", pRtnJDBCInfo->ConnNumRU, g_RunningResult_File);
    OutputCallbackMessage(" pRtnJDBCInfo->UserName: ", pRtnJDBCInfo->UserName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnJDBCInfo->Type: ", pRtnJDBCInfo->Type, g_RunningResult_File);
    OutputCallbackMessage(" pRtnJDBCInfo->URL: ", pRtnJDBCInfo->URL, g_RunningResult_File);

    CShfeFtdcRtnJDBCInfoField* pNewRtnJDBCInfo = new CShfeFtdcRtnJDBCInfoField;
    memcpy (pNewRtnJDBCInfo, pRtnJDBCInfo, sizeof(CShfeFtdcRtnJDBCInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnJDBCInfo;

    uv_mutex_lock (&g_RtnJDBCInfoTopic_mutex);
    g_RtnJDBCInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnJDBCInfoTopic_mutex);

    uv_async_send(&g_RtnJDBCInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnJDBCInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryThreadInfoTopic(CShfeFtdcRspQryThreadInfoField* pRspQryThreadInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryThreadInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryThreadInfo) { 
        OutputCallbackMessage("pRspQryThreadInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryThreadInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryThreadInfo->ObjectID: ", pRspQryThreadInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryThreadInfo->MonDate: ", pRspQryThreadInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryThreadInfo->MonTime: ", pRspQryThreadInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryThreadInfo->Name: ", pRspQryThreadInfo->Name, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryThreadInfo->ThreadNum: ", pRspQryThreadInfo->ThreadNum, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryThreadInfo->ThreadStatus: ", pRspQryThreadInfo->ThreadStatus, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryThreadInfo->InNative: ", pRspQryThreadInfo->InNative, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryThreadInfo->Suspended: ", pRspQryThreadInfo->Suspended, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryThreadInfo->BlockCount: ", pRspQryThreadInfo->BlockCount, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryThreadInfo->WaitCount: ", pRspQryThreadInfo->WaitCount, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryThreadInfo->CpuTime: ", pRspQryThreadInfo->CpuTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryThreadInfo->UserTime: ", pRspQryThreadInfo->UserTime, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryThreadInfoField* pNewRspQryThreadInfo = new CShfeFtdcRspQryThreadInfoField;
    memcpy (pNewRspQryThreadInfo, pRspQryThreadInfo, sizeof(CShfeFtdcRspQryThreadInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryThreadInfo;

    uv_mutex_lock (&g_RspQryThreadInfoTopic_mutex);
    g_RspQryThreadInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryThreadInfoTopic_mutex);

    uv_async_send(&g_RspQryThreadInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryThreadInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnThreadInfoTopic(CShfeFtdcRtnThreadInfoField* pRtnThreadInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnThreadInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnThreadInfo) { 
        OutputCallbackMessage("pRtnThreadInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnThreadInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnThreadInfo->ObjectID: ", pRtnThreadInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnThreadInfo->MonDate: ", pRtnThreadInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnThreadInfo->MonTime: ", pRtnThreadInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnThreadInfo->Name: ", pRtnThreadInfo->Name, g_RunningResult_File);
    OutputCallbackMessage(" pRtnThreadInfo->ThreadNum: ", pRtnThreadInfo->ThreadNum, g_RunningResult_File);
    OutputCallbackMessage(" pRtnThreadInfo->ThreadStatus: ", pRtnThreadInfo->ThreadStatus, g_RunningResult_File);
    OutputCallbackMessage(" pRtnThreadInfo->InNative: ", pRtnThreadInfo->InNative, g_RunningResult_File);
    OutputCallbackMessage(" pRtnThreadInfo->Suspended: ", pRtnThreadInfo->Suspended, g_RunningResult_File);
    OutputCallbackMessage(" pRtnThreadInfo->BlockCount: ", pRtnThreadInfo->BlockCount, g_RunningResult_File);
    OutputCallbackMessage(" pRtnThreadInfo->WaitCount: ", pRtnThreadInfo->WaitCount, g_RunningResult_File);
    OutputCallbackMessage(" pRtnThreadInfo->CpuTime: ", pRtnThreadInfo->CpuTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnThreadInfo->UserTime: ", pRtnThreadInfo->UserTime, g_RunningResult_File);

    CShfeFtdcRtnThreadInfoField* pNewRtnThreadInfo = new CShfeFtdcRtnThreadInfoField;
    memcpy (pNewRtnThreadInfo, pRtnThreadInfo, sizeof(CShfeFtdcRtnThreadInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnThreadInfo;

    uv_mutex_lock (&g_RtnThreadInfoTopic_mutex);
    g_RtnThreadInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnThreadInfoTopic_mutex);

    uv_async_send(&g_RtnThreadInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnThreadInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryVMInfoTopic(CShfeFtdcRspQryVMInfoField* pRspQryVMInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryVMInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryVMInfo) { 
        OutputCallbackMessage("pRspQryVMInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryVMInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryVMInfo->ObjectID: ", pRspQryVMInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryVMInfo->MonDate: ", pRspQryVMInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryVMInfo->MonTime: ", pRspQryVMInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryVMInfo->Name: ", pRspQryVMInfo->Name, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryVMInfo->VmName: ", pRspQryVMInfo->VmName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryVMInfo->VmVendor: ", pRspQryVMInfo->VmVendor, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryVMInfo->VmVersion: ", pRspQryVMInfo->VmVersion, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryVMInfo->StartTime: ", pRspQryVMInfo->StartTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryVMInfo->BootClassPath: ", pRspQryVMInfo->BootClassPath, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryVMInfo->ClassPath: ", pRspQryVMInfo->ClassPath, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryVMInfo->LibraryPath: ", pRspQryVMInfo->LibraryPath, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryVMInfo->Arguments: ", pRspQryVMInfo->Arguments, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryVMInfoField* pNewRspQryVMInfo = new CShfeFtdcRspQryVMInfoField;
    memcpy (pNewRspQryVMInfo, pRspQryVMInfo, sizeof(CShfeFtdcRspQryVMInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryVMInfo;

    uv_mutex_lock (&g_RspQryVMInfoTopic_mutex);
    g_RspQryVMInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryVMInfoTopic_mutex);

    uv_async_send(&g_RspQryVMInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryVMInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnVMInfoTopic(CShfeFtdcRtnVMInfoField* pRtnVMInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnVMInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnVMInfo) { 
        OutputCallbackMessage("pRtnVMInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnVMInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnVMInfo->ObjectID: ", pRtnVMInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnVMInfo->MonDate: ", pRtnVMInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnVMInfo->MonTime: ", pRtnVMInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnVMInfo->Name: ", pRtnVMInfo->Name, g_RunningResult_File);
    OutputCallbackMessage(" pRtnVMInfo->VmName: ", pRtnVMInfo->VmName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnVMInfo->VmVendor: ", pRtnVMInfo->VmVendor, g_RunningResult_File);
    OutputCallbackMessage(" pRtnVMInfo->VmVersion: ", pRtnVMInfo->VmVersion, g_RunningResult_File);
    OutputCallbackMessage(" pRtnVMInfo->StartTime: ", pRtnVMInfo->StartTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnVMInfo->BootClassPath: ", pRtnVMInfo->BootClassPath, g_RunningResult_File);
    OutputCallbackMessage(" pRtnVMInfo->ClassPath: ", pRtnVMInfo->ClassPath, g_RunningResult_File);
    OutputCallbackMessage(" pRtnVMInfo->LibraryPath: ", pRtnVMInfo->LibraryPath, g_RunningResult_File);
    OutputCallbackMessage(" pRtnVMInfo->Arguments: ", pRtnVMInfo->Arguments, g_RunningResult_File);

    CShfeFtdcRtnVMInfoField* pNewRtnVMInfo = new CShfeFtdcRtnVMInfoField;
    memcpy (pNewRtnVMInfo, pRtnVMInfo, sizeof(CShfeFtdcRtnVMInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnVMInfo;

    uv_mutex_lock (&g_RtnVMInfoTopic_mutex);
    g_RtnVMInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnVMInfoTopic_mutex);

    uv_async_send(&g_RtnVMInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnVMInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryPropertyInfoTopic(CShfeFtdcRspQryPropertyInfoField* pRspQryPropertyInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryPropertyInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryPropertyInfo) { 
        OutputCallbackMessage("pRspQryPropertyInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryPropertyInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryPropertyInfo->ObjectID: ", pRspQryPropertyInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPropertyInfo->MonDate: ", pRspQryPropertyInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPropertyInfo->MonTime: ", pRspQryPropertyInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPropertyInfo->Property: ", pRspQryPropertyInfo->Property, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPropertyInfo->ClipFlag: ", pRspQryPropertyInfo->ClipFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPropertyInfo->Value: ", pRspQryPropertyInfo->Value, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryPropertyInfoField* pNewRspQryPropertyInfo = new CShfeFtdcRspQryPropertyInfoField;
    memcpy (pNewRspQryPropertyInfo, pRspQryPropertyInfo, sizeof(CShfeFtdcRspQryPropertyInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryPropertyInfo;

    uv_mutex_lock (&g_RspQryPropertyInfoTopic_mutex);
    g_RspQryPropertyInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryPropertyInfoTopic_mutex);

    uv_async_send(&g_RspQryPropertyInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryPropertyInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnPropertyInfoTopic(CShfeFtdcRtnPropertyInfoField* pRtnPropertyInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnPropertyInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnPropertyInfo) { 
        OutputCallbackMessage("pRtnPropertyInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnPropertyInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnPropertyInfo->ObjectID: ", pRtnPropertyInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPropertyInfo->MonDate: ", pRtnPropertyInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPropertyInfo->MonTime: ", pRtnPropertyInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPropertyInfo->Property: ", pRtnPropertyInfo->Property, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPropertyInfo->ClipFlag: ", pRtnPropertyInfo->ClipFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPropertyInfo->Value: ", pRtnPropertyInfo->Value, g_RunningResult_File);

    CShfeFtdcRtnPropertyInfoField* pNewRtnPropertyInfo = new CShfeFtdcRtnPropertyInfoField;
    memcpy (pNewRtnPropertyInfo, pRtnPropertyInfo, sizeof(CShfeFtdcRtnPropertyInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnPropertyInfo;

    uv_mutex_lock (&g_RtnPropertyInfoTopic_mutex);
    g_RtnPropertyInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnPropertyInfoTopic_mutex);

    uv_async_send(&g_RtnPropertyInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnPropertyInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryMemPoolInfoTopic(CShfeFtdcRspQryMemPoolInfoField* pRspQryMemPoolInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryMemPoolInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryMemPoolInfo) { 
        OutputCallbackMessage("pRspQryMemPoolInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryMemPoolInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryMemPoolInfo->ObjectID: ", pRspQryMemPoolInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemPoolInfo->MonDate: ", pRspQryMemPoolInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemPoolInfo->MonTime: ", pRspQryMemPoolInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemPoolInfo->PoolName: ", pRspQryMemPoolInfo->PoolName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemPoolInfo->Usage: ", pRspQryMemPoolInfo->Usage, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemPoolInfo->committedbytes: ", pRspQryMemPoolInfo->committedbytes, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemPoolInfo->initbytes: ", pRspQryMemPoolInfo->initbytes, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemPoolInfo->maxbytes: ", pRspQryMemPoolInfo->maxbytes, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemPoolInfo->usedbytes: ", pRspQryMemPoolInfo->usedbytes, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemPoolInfo->Type: ", pRspQryMemPoolInfo->Type, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryMemPoolInfoField* pNewRspQryMemPoolInfo = new CShfeFtdcRspQryMemPoolInfoField;
    memcpy (pNewRspQryMemPoolInfo, pRspQryMemPoolInfo, sizeof(CShfeFtdcRspQryMemPoolInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryMemPoolInfo;

    uv_mutex_lock (&g_RspQryMemPoolInfoTopic_mutex);
    g_RspQryMemPoolInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryMemPoolInfoTopic_mutex);

    uv_async_send(&g_RspQryMemPoolInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryMemPoolInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnMemPoolInfoTopic(CShfeFtdcRtnMemPoolInfoField* pRtnMemPoolInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnMemPoolInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnMemPoolInfo) { 
        OutputCallbackMessage("pRtnMemPoolInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnMemPoolInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnMemPoolInfo->ObjectID: ", pRtnMemPoolInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemPoolInfo->MonDate: ", pRtnMemPoolInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemPoolInfo->MonTime: ", pRtnMemPoolInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemPoolInfo->PoolName: ", pRtnMemPoolInfo->PoolName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemPoolInfo->Usage: ", pRtnMemPoolInfo->Usage, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemPoolInfo->committedbytes: ", pRtnMemPoolInfo->committedbytes, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemPoolInfo->initbytes: ", pRtnMemPoolInfo->initbytes, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemPoolInfo->maxbytes: ", pRtnMemPoolInfo->maxbytes, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemPoolInfo->usedbytes: ", pRtnMemPoolInfo->usedbytes, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemPoolInfo->Type: ", pRtnMemPoolInfo->Type, g_RunningResult_File);

    CShfeFtdcRtnMemPoolInfoField* pNewRtnMemPoolInfo = new CShfeFtdcRtnMemPoolInfoField;
    memcpy (pNewRtnMemPoolInfo, pRtnMemPoolInfo, sizeof(CShfeFtdcRtnMemPoolInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnMemPoolInfo;

    uv_mutex_lock (&g_RtnMemPoolInfoTopic_mutex);
    g_RtnMemPoolInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnMemPoolInfoTopic_mutex);

    uv_async_send(&g_RtnMemPoolInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnMemPoolInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryFileContentInfoTopic(CShfeFtdcRspQryFileContentInfoField* pRspQryFileContentInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryFileContentInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryFileContentInfo) { 
        OutputCallbackMessage("pRspQryFileContentInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryFileContentInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryFileContentInfo->ObjectID: ", pRspQryFileContentInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileContentInfo->MonDate: ", pRspQryFileContentInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileContentInfo->MonTime: ", pRspQryFileContentInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileContentInfo->FileName: ", pRspQryFileContentInfo->FileName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileContentInfo->FileContent: ", pRspQryFileContentInfo->FileContent, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryFileContentInfoField* pNewRspQryFileContentInfo = new CShfeFtdcRspQryFileContentInfoField;
    memcpy (pNewRspQryFileContentInfo, pRspQryFileContentInfo, sizeof(CShfeFtdcRspQryFileContentInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryFileContentInfo;

    uv_mutex_lock (&g_RspQryFileContentInfoTopic_mutex);
    g_RspQryFileContentInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryFileContentInfoTopic_mutex);

    uv_async_send(&g_RspQryFileContentInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryFileContentInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnFileContentInfoTopic(CShfeFtdcRtnFileContentInfoField* pRtnFileContentInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnFileContentInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnFileContentInfo) { 
        OutputCallbackMessage("pRtnFileContentInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnFileContentInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnFileContentInfo->ObjectID: ", pRtnFileContentInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileContentInfo->MonDate: ", pRtnFileContentInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileContentInfo->MonTime: ", pRtnFileContentInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileContentInfo->FileName: ", pRtnFileContentInfo->FileName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileContentInfo->FileContent: ", pRtnFileContentInfo->FileContent, g_RunningResult_File);

    CShfeFtdcRtnFileContentInfoField* pNewRtnFileContentInfo = new CShfeFtdcRtnFileContentInfoField;
    memcpy (pNewRtnFileContentInfo, pRtnFileContentInfo, sizeof(CShfeFtdcRtnFileContentInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnFileContentInfo;

    uv_mutex_lock (&g_RtnFileContentInfoTopic_mutex);
    g_RtnFileContentInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnFileContentInfoTopic_mutex);

    uv_async_send(&g_RtnFileContentInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnFileContentInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryConnectionInfoTopic(CShfeFtdcRspQryConnectionInfoField* pRspQryConnectionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryConnectionInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryConnectionInfo) { 
        OutputCallbackMessage("pRspQryConnectionInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryConnectionInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryConnectionInfo->ObjectID: ", pRspQryConnectionInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectionInfo->MonDate: ", pRspQryConnectionInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectionInfo->MonTime: ", pRspQryConnectionInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectionInfo->ServiceName: ", pRspQryConnectionInfo->ServiceName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectionInfo->Stage: ", pRspQryConnectionInfo->Stage, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectionInfo->RequestCount: ", pRspQryConnectionInfo->RequestCount, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectionInfo->ErrorCount: ", pRspQryConnectionInfo->ErrorCount, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectionInfo->ProcTime: ", pRspQryConnectionInfo->ProcTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectionInfo->BytesReceived: ", pRspQryConnectionInfo->BytesReceived, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectionInfo->BytesSent: ", pRspQryConnectionInfo->BytesSent, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectionInfo->RemoteIP: ", pRspQryConnectionInfo->RemoteIP, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectionInfo->MaxAccessURI: ", pRspQryConnectionInfo->MaxAccessURI, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryConnectionInfoField* pNewRspQryConnectionInfo = new CShfeFtdcRspQryConnectionInfoField;
    memcpy (pNewRspQryConnectionInfo, pRspQryConnectionInfo, sizeof(CShfeFtdcRspQryConnectionInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryConnectionInfo;

    uv_mutex_lock (&g_RspQryConnectionInfoTopic_mutex);
    g_RspQryConnectionInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryConnectionInfoTopic_mutex);

    uv_async_send(&g_RspQryConnectionInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryConnectionInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnConnectionInfoTopic(CShfeFtdcRtnConnectionInfoField* pRtnConnectionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnConnectionInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnConnectionInfo) { 
        OutputCallbackMessage("pRtnConnectionInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnConnectionInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnConnectionInfo->ObjectID: ", pRtnConnectionInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectionInfo->MonDate: ", pRtnConnectionInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectionInfo->MonTime: ", pRtnConnectionInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectionInfo->ServiceName: ", pRtnConnectionInfo->ServiceName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectionInfo->Stage: ", pRtnConnectionInfo->Stage, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectionInfo->RequestCount: ", pRtnConnectionInfo->RequestCount, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectionInfo->ErrorCount: ", pRtnConnectionInfo->ErrorCount, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectionInfo->ProcTime: ", pRtnConnectionInfo->ProcTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectionInfo->BytesReceived: ", pRtnConnectionInfo->BytesReceived, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectionInfo->BytesSent: ", pRtnConnectionInfo->BytesSent, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectionInfo->RemoteIP: ", pRtnConnectionInfo->RemoteIP, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectionInfo->MaxAccessURI: ", pRtnConnectionInfo->MaxAccessURI, g_RunningResult_File);

    CShfeFtdcRtnConnectionInfoField* pNewRtnConnectionInfo = new CShfeFtdcRtnConnectionInfoField;
    memcpy (pNewRtnConnectionInfo, pRtnConnectionInfo, sizeof(CShfeFtdcRtnConnectionInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnConnectionInfo;

    uv_mutex_lock (&g_RtnConnectionInfoTopic_mutex);
    g_RtnConnectionInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnConnectionInfoTopic_mutex);

    uv_async_send(&g_RtnConnectionInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnConnectionInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryConnectorInfoTopic(CShfeFtdcRspQryConnectorInfoField* pRspQryConnectorInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryConnectorInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryConnectorInfo) { 
        OutputCallbackMessage("pRspQryConnectorInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryConnectorInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryConnectorInfo->ObjectID: ", pRspQryConnectorInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectorInfo->MonDate: ", pRspQryConnectorInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectorInfo->MonTime: ", pRspQryConnectorInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectorInfo->Name: ", pRspQryConnectorInfo->Name, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectorInfo->ThreadsCount: ", pRspQryConnectorInfo->ThreadsCount, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectorInfo->BusyThreadsCount: ", pRspQryConnectorInfo->BusyThreadsCount, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectorInfo->MaxThreads: ", pRspQryConnectorInfo->MaxThreads, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectorInfo->MaxSpareThreads: ", pRspQryConnectorInfo->MaxSpareThreads, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectorInfo->MinSpareThreads: ", pRspQryConnectorInfo->MinSpareThreads, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectorInfo->MaxTime: ", pRspQryConnectorInfo->MaxTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectorInfo->MaxProcTime: ", pRspQryConnectorInfo->MaxProcTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectorInfo->RequestCount: ", pRspQryConnectorInfo->RequestCount, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectorInfo->ErrorCount: ", pRspQryConnectorInfo->ErrorCount, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectorInfo->BytesReceived: ", pRspQryConnectorInfo->BytesReceived, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryConnectorInfo->BytesSent: ", pRspQryConnectorInfo->BytesSent, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryConnectorInfoField* pNewRspQryConnectorInfo = new CShfeFtdcRspQryConnectorInfoField;
    memcpy (pNewRspQryConnectorInfo, pRspQryConnectorInfo, sizeof(CShfeFtdcRspQryConnectorInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryConnectorInfo;

    uv_mutex_lock (&g_RspQryConnectorInfoTopic_mutex);
    g_RspQryConnectorInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryConnectorInfoTopic_mutex);

    uv_async_send(&g_RspQryConnectorInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryConnectorInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnConnectorInfoTopic(CShfeFtdcRtnConnectorInfoField* pRtnConnectorInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnConnectorInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnConnectorInfo) { 
        OutputCallbackMessage("pRtnConnectorInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnConnectorInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnConnectorInfo->ObjectID: ", pRtnConnectorInfo->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectorInfo->MonDate: ", pRtnConnectorInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectorInfo->MonTime: ", pRtnConnectorInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectorInfo->Name: ", pRtnConnectorInfo->Name, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectorInfo->ThreadsCount: ", pRtnConnectorInfo->ThreadsCount, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectorInfo->BusyThreadsCount: ", pRtnConnectorInfo->BusyThreadsCount, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectorInfo->MaxThreads: ", pRtnConnectorInfo->MaxThreads, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectorInfo->MaxSpareThreads: ", pRtnConnectorInfo->MaxSpareThreads, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectorInfo->MinSpareThreads: ", pRtnConnectorInfo->MinSpareThreads, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectorInfo->MaxTime: ", pRtnConnectorInfo->MaxTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectorInfo->MaxProcTime: ", pRtnConnectorInfo->MaxProcTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectorInfo->RequestCount: ", pRtnConnectorInfo->RequestCount, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectorInfo->ErrorCount: ", pRtnConnectorInfo->ErrorCount, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectorInfo->BytesReceived: ", pRtnConnectorInfo->BytesReceived, g_RunningResult_File);
    OutputCallbackMessage(" pRtnConnectorInfo->BytesSent: ", pRtnConnectorInfo->BytesSent, g_RunningResult_File);

    CShfeFtdcRtnConnectorInfoField* pNewRtnConnectorInfo = new CShfeFtdcRtnConnectorInfoField;
    memcpy (pNewRtnConnectorInfo, pRtnConnectorInfo, sizeof(CShfeFtdcRtnConnectorInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnConnectorInfo;

    uv_mutex_lock (&g_RtnConnectorInfoTopic_mutex);
    g_RtnConnectorInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnConnectorInfoTopic_mutex);

    uv_async_send(&g_RtnConnectorInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnConnectorInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryDBQueryTopic(CShfeFtdcRspQryDBQueryField* pRspQryDBQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryDBQueryTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryDBQuery) { 
        OutputCallbackMessage("pRspQryDBQuery is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryDBQueryTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryDBQuery->ObjectID: ", pRspQryDBQuery->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDBQuery->AttrType: ", pRspQryDBQuery->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDBQuery->MonDate: ", pRspQryDBQuery->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDBQuery->MonTime: ", pRspQryDBQuery->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDBQuery->DBQueryResult: ", pRspQryDBQuery->DBQueryResult, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryDBQueryField* pNewRspQryDBQuery = new CShfeFtdcRspQryDBQueryField;
    memcpy (pNewRspQryDBQuery, pRspQryDBQuery, sizeof(CShfeFtdcRspQryDBQueryField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryDBQuery;

    uv_mutex_lock (&g_RspQryDBQueryTopic_mutex);
    g_RspQryDBQueryTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryDBQueryTopic_mutex);

    uv_async_send(&g_RspQryDBQueryTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryDBQueryTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnDBQueryTopic(CShfeFtdcRtnDBQueryField* pRtnDBQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnDBQueryTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnDBQuery) { 
        OutputCallbackMessage("pRtnDBQuery is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnDBQueryTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnDBQuery->ObjectID: ", pRtnDBQuery->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDBQuery->AttrType: ", pRtnDBQuery->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDBQuery->MonDate: ", pRtnDBQuery->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDBQuery->MonTime: ", pRtnDBQuery->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDBQuery->DBQueryResult: ", pRtnDBQuery->DBQueryResult, g_RunningResult_File);

    CShfeFtdcRtnDBQueryField* pNewRtnDBQuery = new CShfeFtdcRtnDBQueryField;
    memcpy (pNewRtnDBQuery, pRtnDBQuery, sizeof(CShfeFtdcRtnDBQueryField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnDBQuery;

    uv_mutex_lock (&g_RtnDBQueryTopic_mutex);
    g_RtnDBQueryTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnDBQueryTopic_mutex);

    uv_async_send(&g_RtnDBQueryTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnDBQueryTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryGeneralFieldTopic(CShfeFtdcSysGeneralFieldField* pSysGeneralField, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryGeneralFieldTopic: START! ******", g_RunningResult_File);

    if (NULL == pSysGeneralField) { 
        OutputCallbackMessage("pSysGeneralField is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryGeneralFieldTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pSysGeneralField->MonDate: ", pSysGeneralField->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pSysGeneralField->MonTime: ", pSysGeneralField->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pSysGeneralField->ObjectID: ", pSysGeneralField->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pSysGeneralField->SubObjectID: ", pSysGeneralField->SubObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pSysGeneralField->AttrType: ", pSysGeneralField->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pSysGeneralField->Content: ", pSysGeneralField->Content, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcSysGeneralFieldField* pNewSysGeneralField = new CShfeFtdcSysGeneralFieldField;
    memcpy (pNewSysGeneralField, pSysGeneralField, sizeof(CShfeFtdcSysGeneralFieldField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewSysGeneralField;

    uv_mutex_lock (&g_RspQryGeneralFieldTopic_mutex);
    g_RspQryGeneralFieldTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryGeneralFieldTopic_mutex);

    uv_async_send(&g_RspQryGeneralFieldTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryGeneralFieldTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnGeneralFieldTopic(CShfeFtdcSysGeneralFieldField* pSysGeneralField, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnGeneralFieldTopic: START! ******", g_RunningResult_File);

    if (NULL == pSysGeneralField) { 
        OutputCallbackMessage("pSysGeneralField is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnGeneralFieldTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pSysGeneralField->MonDate: ", pSysGeneralField->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pSysGeneralField->MonTime: ", pSysGeneralField->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pSysGeneralField->ObjectID: ", pSysGeneralField->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pSysGeneralField->SubObjectID: ", pSysGeneralField->SubObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pSysGeneralField->AttrType: ", pSysGeneralField->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pSysGeneralField->Content: ", pSysGeneralField->Content, g_RunningResult_File);

    CShfeFtdcSysGeneralFieldField* pNewSysGeneralField = new CShfeFtdcSysGeneralFieldField;
    memcpy (pNewSysGeneralField, pSysGeneralField, sizeof(CShfeFtdcSysGeneralFieldField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewSysGeneralField;

    uv_mutex_lock (&g_RtnGeneralFieldTopic_mutex);
    g_RtnGeneralFieldTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnGeneralFieldTopic_mutex);

    uv_async_send(&g_RtnGeneralFieldTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnGeneralFieldTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryGetFileTopic(CShfeFtdcRspQryGetFileField* pRspQryGetFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryGetFileTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryGetFile) { 
        OutputCallbackMessage("pRspQryGetFile is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryGetFileTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryGetFile->FileName: ", pRspQryGetFile->FileName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryGetFile->Version: ", pRspQryGetFile->Version, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryGetFile->Offset: ", pRspQryGetFile->Offset, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryGetFile->Length: ", pRspQryGetFile->Length, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryGetFile->Comment: ", pRspQryGetFile->Comment, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryGetFileField* pNewRspQryGetFile = new CShfeFtdcRspQryGetFileField;
    memcpy (pNewRspQryGetFile, pRspQryGetFile, sizeof(CShfeFtdcRspQryGetFileField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryGetFile;

    uv_mutex_lock (&g_RspQryGetFileTopic_mutex);
    g_RspQryGetFileTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryGetFileTopic_mutex);

    uv_async_send(&g_RspQryGetFileTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryGetFileTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryWarningQueryTopic(CShfeFtdcRspQryWarningQueryField* pRspQryWarningQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryWarningQueryTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryWarningQuery) { 
        OutputCallbackMessage("pRspQryWarningQuery is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryWarningQueryTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryWarningQuery->MonDate: ", pRspQryWarningQuery->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningQuery->MonTime: ", pRspQryWarningQuery->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningQuery->EvendID: ", pRspQryWarningQuery->EvendID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryWarningQuery->DBQueryResult: ", pRspQryWarningQuery->DBQueryResult, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryWarningQueryField* pNewRspQryWarningQuery = new CShfeFtdcRspQryWarningQueryField;
    memcpy (pNewRspQryWarningQuery, pRspQryWarningQuery, sizeof(CShfeFtdcRspQryWarningQueryField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryWarningQuery;

    uv_mutex_lock (&g_RspQryWarningQueryTopic_mutex);
    g_RspQryWarningQueryTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryWarningQueryTopic_mutex);

    uv_async_send(&g_RspQryWarningQueryTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryWarningQueryTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnWarningQueryTopic(CShfeFtdcRtnWarningQueryField* pRtnWarningQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnWarningQueryTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnWarningQuery) { 
        OutputCallbackMessage("pRtnWarningQuery is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnWarningQueryTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnWarningQuery->MonDate: ", pRtnWarningQuery->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningQuery->MonTime: ", pRtnWarningQuery->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningQuery->EvendID: ", pRtnWarningQuery->EvendID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnWarningQuery->DBQueryResult: ", pRtnWarningQuery->DBQueryResult, g_RunningResult_File);

    CShfeFtdcRtnWarningQueryField* pNewRtnWarningQuery = new CShfeFtdcRtnWarningQueryField;
    memcpy (pNewRtnWarningQuery, pRtnWarningQuery, sizeof(CShfeFtdcRtnWarningQueryField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnWarningQuery;

    uv_mutex_lock (&g_RtnWarningQueryTopic_mutex);
    g_RtnWarningQueryTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnWarningQueryTopic_mutex);

    uv_async_send(&g_RtnWarningQueryTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnWarningQueryTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnHostConfig(CShfeFtdcRtnHostConfigField* pRtnHostConfig, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnHostConfig: START! ******", g_RunningResult_File);

    if (NULL == pRtnHostConfig) { 
        OutputCallbackMessage("pRtnHostConfig is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnHostConfig: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnHostConfig->CfgType: ", pRtnHostConfig->CfgType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHostConfig->CfgDataCenter: ", pRtnHostConfig->CfgDataCenter, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHostConfig->CfgName: ", pRtnHostConfig->CfgName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHostConfig->CfgLocation: ", pRtnHostConfig->CfgLocation, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHostConfig->CfgHostName: ", pRtnHostConfig->CfgHostName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnHostConfig->CfgAttend: ", pRtnHostConfig->CfgAttend, g_RunningResult_File);

    CShfeFtdcRtnHostConfigField* pNewRtnHostConfig = new CShfeFtdcRtnHostConfigField;
    memcpy (pNewRtnHostConfig, pRtnHostConfig, sizeof(CShfeFtdcRtnHostConfigField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnHostConfig;

    uv_mutex_lock (&g_RtnHostConfig_mutex);
    g_RtnHostConfig_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnHostConfig_mutex);

    uv_async_send(&g_RtnHostConfig_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnHostConfig: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryGeneralOperateTopic(CShfeFtdcRspQryGeneralOperateField* pRspQryGeneralOperate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryGeneralOperateTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryGeneralOperate) { 
        OutputCallbackMessage("pRspQryGeneralOperate is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryGeneralOperateTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryGeneralOperate->GeneralOperateType: ", pRspQryGeneralOperate->GeneralOperateType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryGeneralOperate->GeneralOperateTable: ", pRspQryGeneralOperate->GeneralOperateTable, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryGeneralOperate->GeneralOperateOption: ", pRspQryGeneralOperate->GeneralOperateOption, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryGeneralOperate->GeneralOperateSet: ", pRspQryGeneralOperate->GeneralOperateSet, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryGeneralOperateField* pNewRspQryGeneralOperate = new CShfeFtdcRspQryGeneralOperateField;
    memcpy (pNewRspQryGeneralOperate, pRspQryGeneralOperate, sizeof(CShfeFtdcRspQryGeneralOperateField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryGeneralOperate;

    uv_mutex_lock (&g_RspQryGeneralOperateTopic_mutex);
    g_RspQryGeneralOperateTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryGeneralOperateTopic_mutex);

    uv_async_send(&g_RspQryGeneralOperateTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryGeneralOperateTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnGeneralOperateTopic(CShfeFtdcRtnGeneralOperateField* pRtnGeneralOperate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnGeneralOperateTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnGeneralOperate) { 
        OutputCallbackMessage("pRtnGeneralOperate is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnGeneralOperateTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnGeneralOperate->GeneralOperateType: ", pRtnGeneralOperate->GeneralOperateType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnGeneralOperate->GeneralOperateTable: ", pRtnGeneralOperate->GeneralOperateTable, g_RunningResult_File);
    OutputCallbackMessage(" pRtnGeneralOperate->GeneralOperateOption: ", pRtnGeneralOperate->GeneralOperateOption, g_RunningResult_File);
    OutputCallbackMessage(" pRtnGeneralOperate->GeneralOperateSet: ", pRtnGeneralOperate->GeneralOperateSet, g_RunningResult_File);

    CShfeFtdcRtnGeneralOperateField* pNewRtnGeneralOperate = new CShfeFtdcRtnGeneralOperateField;
    memcpy (pNewRtnGeneralOperate, pRtnGeneralOperate, sizeof(CShfeFtdcRtnGeneralOperateField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnGeneralOperate;

    uv_mutex_lock (&g_RtnGeneralOperateTopic_mutex);
    g_RtnGeneralOperateTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnGeneralOperateTopic_mutex);

    uv_async_send(&g_RtnGeneralOperateTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnGeneralOperateTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetDeviceLinkedTopic(CShfeFtdcRspQryNetDeviceLinkedField* pRspQryNetDeviceLinked, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetDeviceLinkedTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetDeviceLinked) { 
        OutputCallbackMessage("pRspQryNetDeviceLinked is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetDeviceLinkedTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetDeviceLinked->OperationType: ", pRspQryNetDeviceLinked->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceLinked->ID: ", pRspQryNetDeviceLinked->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceLinked->NetDeviceID: ", pRspQryNetDeviceLinked->NetDeviceID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceLinked->NetPortID: ", pRspQryNetDeviceLinked->NetPortID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceLinked->NetObjectID: ", pRspQryNetDeviceLinked->NetObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceLinked->NetPortType: ", pRspQryNetDeviceLinked->NetPortType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceLinked->LinkNetDeviceID: ", pRspQryNetDeviceLinked->LinkNetDeviceID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceLinked->LinkNetPortID: ", pRspQryNetDeviceLinked->LinkNetPortID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceLinked->LinkNetObjectID: ", pRspQryNetDeviceLinked->LinkNetObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceLinked->LinkNetPortType: ", pRspQryNetDeviceLinked->LinkNetPortType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceLinked->LinkSource: ", pRspQryNetDeviceLinked->LinkSource, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetDeviceLinkedField* pNewRspQryNetDeviceLinked = new CShfeFtdcRspQryNetDeviceLinkedField;
    memcpy (pNewRspQryNetDeviceLinked, pRspQryNetDeviceLinked, sizeof(CShfeFtdcRspQryNetDeviceLinkedField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetDeviceLinked;

    uv_mutex_lock (&g_RspQryNetDeviceLinkedTopic_mutex);
    g_RspQryNetDeviceLinkedTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetDeviceLinkedTopic_mutex);

    uv_async_send(&g_RspQryNetDeviceLinkedTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetDeviceLinkedTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetDeviceLinkedTopic(CShfeFtdcRtnNetDeviceLinkedField* pRtnNetDeviceLinked, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetDeviceLinkedTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetDeviceLinked) { 
        OutputCallbackMessage("pRtnNetDeviceLinked is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetDeviceLinkedTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetDeviceLinked->OperationType: ", pRtnNetDeviceLinked->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceLinked->ID: ", pRtnNetDeviceLinked->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceLinked->NetDeviceID: ", pRtnNetDeviceLinked->NetDeviceID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceLinked->NetPortID: ", pRtnNetDeviceLinked->NetPortID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceLinked->NetObjectID: ", pRtnNetDeviceLinked->NetObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceLinked->NetPortType: ", pRtnNetDeviceLinked->NetPortType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceLinked->LinkNetDeviceID: ", pRtnNetDeviceLinked->LinkNetDeviceID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceLinked->LinkNetPortID: ", pRtnNetDeviceLinked->LinkNetPortID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceLinked->LinkNetObjectID: ", pRtnNetDeviceLinked->LinkNetObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceLinked->LinkNetPortType: ", pRtnNetDeviceLinked->LinkNetPortType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceLinked->LinkSource: ", pRtnNetDeviceLinked->LinkSource, g_RunningResult_File);

    CShfeFtdcRtnNetDeviceLinkedField* pNewRtnNetDeviceLinked = new CShfeFtdcRtnNetDeviceLinkedField;
    memcpy (pNewRtnNetDeviceLinked, pRtnNetDeviceLinked, sizeof(CShfeFtdcRtnNetDeviceLinkedField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetDeviceLinked;

    uv_mutex_lock (&g_RtnNetDeviceLinkedTopic_mutex);
    g_RtnNetDeviceLinkedTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetDeviceLinkedTopic_mutex);

    uv_async_send(&g_RtnNetDeviceLinkedTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetDeviceLinkedTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryTradeUserLoginStatTopic(CShfeFtdcRspQryTradeUserLoginStatField* pRspQryTradeUserLoginStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryTradeUserLoginStatTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryTradeUserLoginStat) { 
        OutputCallbackMessage("pRspQryTradeUserLoginStat is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryTradeUserLoginStatTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryTradeUserLoginStat->MonDate: ", pRspQryTradeUserLoginStat->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginStat->MonTime: ", pRspQryTradeUserLoginStat->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginStat->ObjectID: ", pRspQryTradeUserLoginStat->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginStat->IPAddress: ", pRspQryTradeUserLoginStat->IPAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginStat->ParticipantID: ", pRspQryTradeUserLoginStat->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginStat->UserID: ", pRspQryTradeUserLoginStat->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeUserLoginStat->FrontId: ", pRspQryTradeUserLoginStat->FrontId, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryTradeUserLoginStatField* pNewRspQryTradeUserLoginStat = new CShfeFtdcRspQryTradeUserLoginStatField;
    memcpy (pNewRspQryTradeUserLoginStat, pRspQryTradeUserLoginStat, sizeof(CShfeFtdcRspQryTradeUserLoginStatField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryTradeUserLoginStat;

    uv_mutex_lock (&g_RspQryTradeUserLoginStatTopic_mutex);
    g_RspQryTradeUserLoginStatTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryTradeUserLoginStatTopic_mutex);

    uv_async_send(&g_RspQryTradeUserLoginStatTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryTradeUserLoginStatTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryTradeFrontOrderRttStatTopic(CShfeFtdcRspQryTradeFrontOrderRttStatField* pRspQryTradeFrontOrderRttStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryTradeFrontOrderRttStatTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryTradeFrontOrderRttStat) { 
        OutputCallbackMessage("pRspQryTradeFrontOrderRttStat is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryTradeFrontOrderRttStatTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryTradeFrontOrderRttStat->MonDate: ", pRspQryTradeFrontOrderRttStat->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeFrontOrderRttStat->MonTime: ", pRspQryTradeFrontOrderRttStat->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeFrontOrderRttStat->ObjectID: ", pRspQryTradeFrontOrderRttStat->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeFrontOrderRttStat->OrderCount: ", pRspQryTradeFrontOrderRttStat->OrderCount, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeFrontOrderRttStat->OrderRttSum: ", pRspQryTradeFrontOrderRttStat->OrderRttSum, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeFrontOrderRttStat->OrderMaxRtt: ", pRspQryTradeFrontOrderRttStat->OrderMaxRtt, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeFrontOrderRttStat->OrderMinRtt: ", pRspQryTradeFrontOrderRttStat->OrderMinRtt, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeFrontOrderRttStat->OrderRttSqu: ", pRspQryTradeFrontOrderRttStat->OrderRttSqu, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeFrontOrderRttStat->OrderRttCutDistrib: ", pRspQryTradeFrontOrderRttStat->OrderRttCutDistrib, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryTradeFrontOrderRttStatField* pNewRspQryTradeFrontOrderRttStat = new CShfeFtdcRspQryTradeFrontOrderRttStatField;
    memcpy (pNewRspQryTradeFrontOrderRttStat, pRspQryTradeFrontOrderRttStat, sizeof(CShfeFtdcRspQryTradeFrontOrderRttStatField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryTradeFrontOrderRttStat;

    uv_mutex_lock (&g_RspQryTradeFrontOrderRttStatTopic_mutex);
    g_RspQryTradeFrontOrderRttStatTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryTradeFrontOrderRttStatTopic_mutex);

    uv_async_send(&g_RspQryTradeFrontOrderRttStatTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryTradeFrontOrderRttStatTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnTradeFrontOrderRttStatTopic(CShfeFtdcRtnTradeFrontOrderRttStatField* pRtnTradeFrontOrderRttStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnTradeFrontOrderRttStatTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnTradeFrontOrderRttStat) { 
        OutputCallbackMessage("pRtnTradeFrontOrderRttStat is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnTradeFrontOrderRttStatTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnTradeFrontOrderRttStat->MonDate: ", pRtnTradeFrontOrderRttStat->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeFrontOrderRttStat->MonTime: ", pRtnTradeFrontOrderRttStat->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeFrontOrderRttStat->ObjectID: ", pRtnTradeFrontOrderRttStat->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeFrontOrderRttStat->OrderCount: ", pRtnTradeFrontOrderRttStat->OrderCount, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeFrontOrderRttStat->OrderRttSum: ", pRtnTradeFrontOrderRttStat->OrderRttSum, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeFrontOrderRttStat->OrderMaxRtt: ", pRtnTradeFrontOrderRttStat->OrderMaxRtt, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeFrontOrderRttStat->OrderMinRtt: ", pRtnTradeFrontOrderRttStat->OrderMinRtt, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeFrontOrderRttStat->OrderRttSqu: ", pRtnTradeFrontOrderRttStat->OrderRttSqu, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeFrontOrderRttStat->OrderRttCutDistrib: ", pRtnTradeFrontOrderRttStat->OrderRttCutDistrib, g_RunningResult_File);

    CShfeFtdcRtnTradeFrontOrderRttStatField* pNewRtnTradeFrontOrderRttStat = new CShfeFtdcRtnTradeFrontOrderRttStatField;
    memcpy (pNewRtnTradeFrontOrderRttStat, pRtnTradeFrontOrderRttStat, sizeof(CShfeFtdcRtnTradeFrontOrderRttStatField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnTradeFrontOrderRttStat;

    uv_mutex_lock (&g_RtnTradeFrontOrderRttStatTopic_mutex);
    g_RtnTradeFrontOrderRttStatTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnTradeFrontOrderRttStatTopic_mutex);

    uv_async_send(&g_RtnTradeFrontOrderRttStatTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnTradeFrontOrderRttStatTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryParticTradeOrderStatesTopic(CShfeFtdcRspQryParticTradeOrderStatesField* pRspQryParticTradeOrderStates, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryParticTradeOrderStatesTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryParticTradeOrderStates) { 
        OutputCallbackMessage("pRspQryParticTradeOrderStates is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryParticTradeOrderStatesTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryParticTradeOrderStates->ParticipantID: ", pRspQryParticTradeOrderStates->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticTradeOrderStates->UserID: ", pRspQryParticTradeOrderStates->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticTradeOrderStates->MonDate: ", pRspQryParticTradeOrderStates->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticTradeOrderStates->MonTime: ", pRspQryParticTradeOrderStates->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticTradeOrderStates->StaticWidth: ", pRspQryParticTradeOrderStates->StaticWidth, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticTradeOrderStates->FrontID: ", pRspQryParticTradeOrderStates->FrontID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticTradeOrderStates->OrderCount: ", pRspQryParticTradeOrderStates->OrderCount, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticTradeOrderStates->CancleCount: ", pRspQryParticTradeOrderStates->CancleCount, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticTradeOrderStates->QueryCount: ", pRspQryParticTradeOrderStates->QueryCount, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticTradeOrderStates->TradeCount: ", pRspQryParticTradeOrderStates->TradeCount, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticTradeOrderStates->TradeMoney: ", pRspQryParticTradeOrderStates->TradeMoney, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticTradeOrderStates->OrderCntMax: ", pRspQryParticTradeOrderStates->OrderCntMax, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticTradeOrderStates->CancleCntMax: ", pRspQryParticTradeOrderStates->CancleCntMax, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticTradeOrderStates->QueryCntMax: ", pRspQryParticTradeOrderStates->QueryCntMax, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticTradeOrderStates->TradeCntMax: ", pRspQryParticTradeOrderStates->TradeCntMax, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryParticTradeOrderStates->TradeMoneyMax: ", pRspQryParticTradeOrderStates->TradeMoneyMax, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryParticTradeOrderStatesField* pNewRspQryParticTradeOrderStates = new CShfeFtdcRspQryParticTradeOrderStatesField;
    memcpy (pNewRspQryParticTradeOrderStates, pRspQryParticTradeOrderStates, sizeof(CShfeFtdcRspQryParticTradeOrderStatesField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryParticTradeOrderStates;

    uv_mutex_lock (&g_RspQryParticTradeOrderStatesTopic_mutex);
    g_RspQryParticTradeOrderStatesTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryParticTradeOrderStatesTopic_mutex);

    uv_async_send(&g_RspQryParticTradeOrderStatesTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryParticTradeOrderStatesTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnParticTradeOrderStatesTopic(CShfeFtdcRtnParticTradeOrderStatesField* pRtnParticTradeOrderStates, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnParticTradeOrderStatesTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnParticTradeOrderStates) { 
        OutputCallbackMessage("pRtnParticTradeOrderStates is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnParticTradeOrderStatesTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnParticTradeOrderStates->ParticipantID: ", pRtnParticTradeOrderStates->ParticipantID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticTradeOrderStates->UserID: ", pRtnParticTradeOrderStates->UserID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticTradeOrderStates->MonDate: ", pRtnParticTradeOrderStates->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticTradeOrderStates->MonTime: ", pRtnParticTradeOrderStates->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticTradeOrderStates->StaticWidth: ", pRtnParticTradeOrderStates->StaticWidth, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticTradeOrderStates->FrontID: ", pRtnParticTradeOrderStates->FrontID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticTradeOrderStates->OrderCount: ", pRtnParticTradeOrderStates->OrderCount, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticTradeOrderStates->CancleCount: ", pRtnParticTradeOrderStates->CancleCount, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticTradeOrderStates->QueryCount: ", pRtnParticTradeOrderStates->QueryCount, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticTradeOrderStates->TradeCount: ", pRtnParticTradeOrderStates->TradeCount, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticTradeOrderStates->TradeMoney: ", pRtnParticTradeOrderStates->TradeMoney, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticTradeOrderStates->OrderCntMax: ", pRtnParticTradeOrderStates->OrderCntMax, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticTradeOrderStates->CancleCntMax: ", pRtnParticTradeOrderStates->CancleCntMax, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticTradeOrderStates->QueryCntMax: ", pRtnParticTradeOrderStates->QueryCntMax, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticTradeOrderStates->TradeCntMax: ", pRtnParticTradeOrderStates->TradeCntMax, g_RunningResult_File);
    OutputCallbackMessage(" pRtnParticTradeOrderStates->TradeMoneyMax: ", pRtnParticTradeOrderStates->TradeMoneyMax, g_RunningResult_File);

    CShfeFtdcRtnParticTradeOrderStatesField* pNewRtnParticTradeOrderStates = new CShfeFtdcRtnParticTradeOrderStatesField;
    memcpy (pNewRtnParticTradeOrderStates, pRtnParticTradeOrderStates, sizeof(CShfeFtdcRtnParticTradeOrderStatesField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnParticTradeOrderStates;

    uv_mutex_lock (&g_RtnParticTradeOrderStatesTopic_mutex);
    g_RtnParticTradeOrderStatesTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnParticTradeOrderStatesTopic_mutex);

    uv_async_send(&g_RtnParticTradeOrderStatesTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnParticTradeOrderStatesTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryRouterInfoTopic(CShfeFtdcRspQryRouterInfoField* pRspQryRouterInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryRouterInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryRouterInfo) { 
        OutputCallbackMessage("pRspQryRouterInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryRouterInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryRouterInfo->HostName: ", pRspQryRouterInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryRouterInfo->MonDate: ", pRspQryRouterInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryRouterInfo->MonTime: ", pRspQryRouterInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryRouterInfo->Dev: ", pRspQryRouterInfo->Dev, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryRouterInfo->Destination: ", pRspQryRouterInfo->Destination, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryRouterInfo->Gateway: ", pRspQryRouterInfo->Gateway, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryRouterInfo->Mask: ", pRspQryRouterInfo->Mask, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryRouterInfo->Flag: ", pRspQryRouterInfo->Flag, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryRouterInfo->RefCnt: ", pRspQryRouterInfo->RefCnt, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryRouterInfo->Use: ", pRspQryRouterInfo->Use, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryRouterInfo->Metric: ", pRspQryRouterInfo->Metric, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryRouterInfo->Mtu: ", pRspQryRouterInfo->Mtu, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryRouterInfo->Win: ", pRspQryRouterInfo->Win, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryRouterInfo->Rtt: ", pRspQryRouterInfo->Rtt, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryRouterInfoField* pNewRspQryRouterInfo = new CShfeFtdcRspQryRouterInfoField;
    memcpy (pNewRspQryRouterInfo, pRspQryRouterInfo, sizeof(CShfeFtdcRspQryRouterInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryRouterInfo;

    uv_mutex_lock (&g_RspQryRouterInfoTopic_mutex);
    g_RspQryRouterInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryRouterInfoTopic_mutex);

    uv_async_send(&g_RspQryRouterInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryRouterInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnRouterInfoTopic(CShfeFtdcRtnRouterInfoField* pRtnRouterInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnRouterInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnRouterInfo) { 
        OutputCallbackMessage("pRtnRouterInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnRouterInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnRouterInfo->HostName: ", pRtnRouterInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnRouterInfo->MonDate: ", pRtnRouterInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnRouterInfo->MonTime: ", pRtnRouterInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnRouterInfo->Dev: ", pRtnRouterInfo->Dev, g_RunningResult_File);
    OutputCallbackMessage(" pRtnRouterInfo->Destination: ", pRtnRouterInfo->Destination, g_RunningResult_File);
    OutputCallbackMessage(" pRtnRouterInfo->Gateway: ", pRtnRouterInfo->Gateway, g_RunningResult_File);
    OutputCallbackMessage(" pRtnRouterInfo->Mask: ", pRtnRouterInfo->Mask, g_RunningResult_File);
    OutputCallbackMessage(" pRtnRouterInfo->Flag: ", pRtnRouterInfo->Flag, g_RunningResult_File);
    OutputCallbackMessage(" pRtnRouterInfo->RefCnt: ", pRtnRouterInfo->RefCnt, g_RunningResult_File);
    OutputCallbackMessage(" pRtnRouterInfo->Use: ", pRtnRouterInfo->Use, g_RunningResult_File);
    OutputCallbackMessage(" pRtnRouterInfo->Metric: ", pRtnRouterInfo->Metric, g_RunningResult_File);
    OutputCallbackMessage(" pRtnRouterInfo->Mtu: ", pRtnRouterInfo->Mtu, g_RunningResult_File);
    OutputCallbackMessage(" pRtnRouterInfo->Win: ", pRtnRouterInfo->Win, g_RunningResult_File);
    OutputCallbackMessage(" pRtnRouterInfo->Rtt: ", pRtnRouterInfo->Rtt, g_RunningResult_File);

    CShfeFtdcRtnRouterInfoField* pNewRtnRouterInfo = new CShfeFtdcRtnRouterInfoField;
    memcpy (pNewRtnRouterInfo, pRtnRouterInfo, sizeof(CShfeFtdcRtnRouterInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnRouterInfo;

    uv_mutex_lock (&g_RtnRouterInfoTopic_mutex);
    g_RtnRouterInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnRouterInfoTopic_mutex);

    uv_async_send(&g_RtnRouterInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnRouterInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryDiskIOTopic(CShfeFtdcRspQryDiskIOField* pRspQryDiskIO, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryDiskIOTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryDiskIO) { 
        OutputCallbackMessage("pRspQryDiskIO is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryDiskIOTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryDiskIO->HostName: ", pRspQryDiskIO->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDiskIO->MonDate: ", pRspQryDiskIO->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDiskIO->MonTime: ", pRspQryDiskIO->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDiskIO->PartName: ", pRspQryDiskIO->PartName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDiskIO->ReadMerges: ", pRspQryDiskIO->ReadMerges, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDiskIO->WriteMerges: ", pRspQryDiskIO->WriteMerges, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDiskIO->ReadIOs: ", pRspQryDiskIO->ReadIOs, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDiskIO->WriteIOs: ", pRspQryDiskIO->WriteIOs, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDiskIO->ReadKBs: ", pRspQryDiskIO->ReadKBs, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDiskIO->WriteKBs: ", pRspQryDiskIO->WriteKBs, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDiskIO->SizeVal: ", pRspQryDiskIO->SizeVal, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDiskIO->QueueVal: ", pRspQryDiskIO->QueueVal, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDiskIO->Svc_t: ", pRspQryDiskIO->Svc_t, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryDiskIO->Busy: ", pRspQryDiskIO->Busy, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryDiskIOField* pNewRspQryDiskIO = new CShfeFtdcRspQryDiskIOField;
    memcpy (pNewRspQryDiskIO, pRspQryDiskIO, sizeof(CShfeFtdcRspQryDiskIOField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryDiskIO;

    uv_mutex_lock (&g_RspQryDiskIOTopic_mutex);
    g_RspQryDiskIOTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryDiskIOTopic_mutex);

    uv_async_send(&g_RspQryDiskIOTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryDiskIOTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnDiskIOTopic(CShfeFtdcRtnDiskIOField* pRtnDiskIO, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnDiskIOTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnDiskIO) { 
        OutputCallbackMessage("pRtnDiskIO is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnDiskIOTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnDiskIO->HostName: ", pRtnDiskIO->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDiskIO->MonDate: ", pRtnDiskIO->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDiskIO->MonTime: ", pRtnDiskIO->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDiskIO->PartName: ", pRtnDiskIO->PartName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDiskIO->ReadMerges: ", pRtnDiskIO->ReadMerges, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDiskIO->WriteMerges: ", pRtnDiskIO->WriteMerges, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDiskIO->ReadIOs: ", pRtnDiskIO->ReadIOs, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDiskIO->WriteIOs: ", pRtnDiskIO->WriteIOs, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDiskIO->ReadKBs: ", pRtnDiskIO->ReadKBs, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDiskIO->WriteKBs: ", pRtnDiskIO->WriteKBs, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDiskIO->SizeVal: ", pRtnDiskIO->SizeVal, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDiskIO->QueueVal: ", pRtnDiskIO->QueueVal, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDiskIO->Svc_t: ", pRtnDiskIO->Svc_t, g_RunningResult_File);
    OutputCallbackMessage(" pRtnDiskIO->Busy: ", pRtnDiskIO->Busy, g_RunningResult_File);

    CShfeFtdcRtnDiskIOField* pNewRtnDiskIO = new CShfeFtdcRtnDiskIOField;
    memcpy (pNewRtnDiskIO, pRtnDiskIO, sizeof(CShfeFtdcRtnDiskIOField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnDiskIO;

    uv_mutex_lock (&g_RtnDiskIOTopic_mutex);
    g_RtnDiskIOTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnDiskIOTopic_mutex);

    uv_async_send(&g_RtnDiskIOTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnDiskIOTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryStatInfoTopic(CShfeFtdcRspQryStatInfoField* pRspQryStatInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryStatInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryStatInfo) { 
        OutputCallbackMessage("pRspQryStatInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryStatInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryStatInfo->HostName: ", pRspQryStatInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryStatInfo->MonDate: ", pRspQryStatInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryStatInfo->MonTime: ", pRspQryStatInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryStatInfo->ProcRun: ", pRspQryStatInfo->ProcRun, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryStatInfo->ProcBlk: ", pRspQryStatInfo->ProcBlk, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryStatInfo->SwapIn: ", pRspQryStatInfo->SwapIn, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryStatInfo->SwapOut: ", pRspQryStatInfo->SwapOut, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryStatInfo->BlockIn: ", pRspQryStatInfo->BlockIn, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryStatInfo->BlockOut: ", pRspQryStatInfo->BlockOut, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryStatInfo->Inter: ", pRspQryStatInfo->Inter, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryStatInfo->Context: ", pRspQryStatInfo->Context, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryStatInfo->CPUUser: ", pRspQryStatInfo->CPUUser, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryStatInfo->CPUSys: ", pRspQryStatInfo->CPUSys, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryStatInfo->CPUIdle: ", pRspQryStatInfo->CPUIdle, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryStatInfo->CPUIOWait: ", pRspQryStatInfo->CPUIOWait, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryStatInfo->CPUSteal: ", pRspQryStatInfo->CPUSteal, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryStatInfoField* pNewRspQryStatInfo = new CShfeFtdcRspQryStatInfoField;
    memcpy (pNewRspQryStatInfo, pRspQryStatInfo, sizeof(CShfeFtdcRspQryStatInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryStatInfo;

    uv_mutex_lock (&g_RspQryStatInfoTopic_mutex);
    g_RspQryStatInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryStatInfoTopic_mutex);

    uv_async_send(&g_RspQryStatInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryStatInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnStatInfoTopic(CShfeFtdcRtnStatInfoField* pRtnStatInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnStatInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnStatInfo) { 
        OutputCallbackMessage("pRtnStatInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnStatInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnStatInfo->HostName: ", pRtnStatInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnStatInfo->MonDate: ", pRtnStatInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnStatInfo->MonTime: ", pRtnStatInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnStatInfo->ProcRun: ", pRtnStatInfo->ProcRun, g_RunningResult_File);
    OutputCallbackMessage(" pRtnStatInfo->ProcBlk: ", pRtnStatInfo->ProcBlk, g_RunningResult_File);
    OutputCallbackMessage(" pRtnStatInfo->SwapIn: ", pRtnStatInfo->SwapIn, g_RunningResult_File);
    OutputCallbackMessage(" pRtnStatInfo->SwapOut: ", pRtnStatInfo->SwapOut, g_RunningResult_File);
    OutputCallbackMessage(" pRtnStatInfo->BlockIn: ", pRtnStatInfo->BlockIn, g_RunningResult_File);
    OutputCallbackMessage(" pRtnStatInfo->BlockOut: ", pRtnStatInfo->BlockOut, g_RunningResult_File);
    OutputCallbackMessage(" pRtnStatInfo->Inter: ", pRtnStatInfo->Inter, g_RunningResult_File);
    OutputCallbackMessage(" pRtnStatInfo->Context: ", pRtnStatInfo->Context, g_RunningResult_File);
    OutputCallbackMessage(" pRtnStatInfo->CPUUser: ", pRtnStatInfo->CPUUser, g_RunningResult_File);
    OutputCallbackMessage(" pRtnStatInfo->CPUSys: ", pRtnStatInfo->CPUSys, g_RunningResult_File);
    OutputCallbackMessage(" pRtnStatInfo->CPUIdle: ", pRtnStatInfo->CPUIdle, g_RunningResult_File);
    OutputCallbackMessage(" pRtnStatInfo->CPUIOWait: ", pRtnStatInfo->CPUIOWait, g_RunningResult_File);
    OutputCallbackMessage(" pRtnStatInfo->CPUSteal: ", pRtnStatInfo->CPUSteal, g_RunningResult_File);

    CShfeFtdcRtnStatInfoField* pNewRtnStatInfo = new CShfeFtdcRtnStatInfoField;
    memcpy (pNewRtnStatInfo, pRtnStatInfo, sizeof(CShfeFtdcRtnStatInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnStatInfo;

    uv_mutex_lock (&g_RtnStatInfoTopic_mutex);
    g_RtnStatInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnStatInfoTopic_mutex);

    uv_async_send(&g_RtnStatInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnStatInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryTradeOrderRttCutLineTopic(CShfeFtdcRspQryTradeOrderRttCutLineField* pRspQryTradeOrderRttCutLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryTradeOrderRttCutLineTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryTradeOrderRttCutLine) { 
        OutputCallbackMessage("pRspQryTradeOrderRttCutLine is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryTradeOrderRttCutLineTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryTradeOrderRttCutLine->MonDate: ", pRspQryTradeOrderRttCutLine->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeOrderRttCutLine->MonTime: ", pRspQryTradeOrderRttCutLine->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeOrderRttCutLine->UserName: ", pRspQryTradeOrderRttCutLine->UserName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeOrderRttCutLine->OrderRttCutLine: ", pRspQryTradeOrderRttCutLine->OrderRttCutLine, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryTradeOrderRttCutLine->OrderRttWidth: ", pRspQryTradeOrderRttCutLine->OrderRttWidth, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryTradeOrderRttCutLineField* pNewRspQryTradeOrderRttCutLine = new CShfeFtdcRspQryTradeOrderRttCutLineField;
    memcpy (pNewRspQryTradeOrderRttCutLine, pRspQryTradeOrderRttCutLine, sizeof(CShfeFtdcRspQryTradeOrderRttCutLineField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryTradeOrderRttCutLine;

    uv_mutex_lock (&g_RspQryTradeOrderRttCutLineTopic_mutex);
    g_RspQryTradeOrderRttCutLineTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryTradeOrderRttCutLineTopic_mutex);

    uv_async_send(&g_RspQryTradeOrderRttCutLineTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryTradeOrderRttCutLineTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnTradeOrderRttCutLineTopic(CShfeFtdcRtnTradeOrderRttCutLineField* pRtnTradeOrderRttCutLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnTradeOrderRttCutLineTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnTradeOrderRttCutLine) { 
        OutputCallbackMessage("pRtnTradeOrderRttCutLine is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnTradeOrderRttCutLineTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnTradeOrderRttCutLine->MonDate: ", pRtnTradeOrderRttCutLine->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnTradeOrderRttCutLine->OrderRttCutLine: ", pRtnTradeOrderRttCutLine->OrderRttCutLine, g_RunningResult_File);

    CShfeFtdcRtnTradeOrderRttCutLineField* pNewRtnTradeOrderRttCutLine = new CShfeFtdcRtnTradeOrderRttCutLineField;
    memcpy (pNewRtnTradeOrderRttCutLine, pRtnTradeOrderRttCutLine, sizeof(CShfeFtdcRtnTradeOrderRttCutLineField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnTradeOrderRttCutLine;

    uv_mutex_lock (&g_RtnTradeOrderRttCutLineTopic_mutex);
    g_RtnTradeOrderRttCutLineTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnTradeOrderRttCutLineTopic_mutex);

    uv_async_send(&g_RtnTradeOrderRttCutLineTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnTradeOrderRttCutLineTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryClientInfoTopic(CShfeFtdcRspQryClientInfoField* pRspQryClientInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryClientInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryClientInfo) { 
        OutputCallbackMessage("pRspQryClientInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryClientInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryClientInfo->ClientID: ", pRspQryClientInfo->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientInfo->ClientName: ", pRspQryClientInfo->ClientName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientInfo->IdentifiedCardType: ", pRspQryClientInfo->IdentifiedCardType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientInfo->IdentifiedCardNo: ", pRspQryClientInfo->IdentifiedCardNo, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientInfo->TradingRole: ", pRspQryClientInfo->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientInfo->ClientType: ", pRspQryClientInfo->ClientType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientInfo->IsActive: ", pRspQryClientInfo->IsActive, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryClientInfo->OperationType: ", pRspQryClientInfo->OperationType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryClientInfoField* pNewRspQryClientInfo = new CShfeFtdcRspQryClientInfoField;
    memcpy (pNewRspQryClientInfo, pRspQryClientInfo, sizeof(CShfeFtdcRspQryClientInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryClientInfo;

    uv_mutex_lock (&g_RspQryClientInfoTopic_mutex);
    g_RspQryClientInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryClientInfoTopic_mutex);

    uv_async_send(&g_RspQryClientInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryClientInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnClientInfoTopic(CShfeFtdcRtnClientInfoField* pRtnClientInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnClientInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnClientInfo) { 
        OutputCallbackMessage("pRtnClientInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnClientInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnClientInfo->ClientID: ", pRtnClientInfo->ClientID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientInfo->ClientName: ", pRtnClientInfo->ClientName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientInfo->IdentifiedCardType: ", pRtnClientInfo->IdentifiedCardType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientInfo->IdentifiedCardNo: ", pRtnClientInfo->IdentifiedCardNo, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientInfo->TradingRole: ", pRtnClientInfo->TradingRole, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientInfo->ClientType: ", pRtnClientInfo->ClientType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientInfo->IsActive: ", pRtnClientInfo->IsActive, g_RunningResult_File);
    OutputCallbackMessage(" pRtnClientInfo->OperationType: ", pRtnClientInfo->OperationType, g_RunningResult_File);

    CShfeFtdcRtnClientInfoField* pNewRtnClientInfo = new CShfeFtdcRtnClientInfoField;
    memcpy (pNewRtnClientInfo, pRtnClientInfo, sizeof(CShfeFtdcRtnClientInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnClientInfo;

    uv_mutex_lock (&g_RtnClientInfoTopic_mutex);
    g_RtnClientInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnClientInfoTopic_mutex);

    uv_async_send(&g_RtnClientInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnClientInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryEventDescriptionTopic(CShfeFtdcRspQryEventDescriptionField* pRspQryEventDescription, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryEventDescriptionTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryEventDescription) { 
        OutputCallbackMessage("pRspQryEventDescription is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryEventDescriptionTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryEventDescription->EventDesID: ", pRspQryEventDescription->EventDesID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryEventDescription->UserName: ", pRspQryEventDescription->UserName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryEventDescription->MonDate: ", pRspQryEventDescription->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryEventDescription->MonTime: ", pRspQryEventDescription->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryEventDescription->EventDes: ", pRspQryEventDescription->EventDes, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryEventDescriptionField* pNewRspQryEventDescription = new CShfeFtdcRspQryEventDescriptionField;
    memcpy (pNewRspQryEventDescription, pRspQryEventDescription, sizeof(CShfeFtdcRspQryEventDescriptionField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryEventDescription;

    uv_mutex_lock (&g_RspQryEventDescriptionTopic_mutex);
    g_RspQryEventDescriptionTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryEventDescriptionTopic_mutex);

    uv_async_send(&g_RspQryEventDescriptionTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryEventDescriptionTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnEventDescriptionTopic(CShfeFtdcRtnEventDescriptionField* pRtnEventDescription, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnEventDescriptionTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnEventDescription) { 
        OutputCallbackMessage("pRtnEventDescription is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnEventDescriptionTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnEventDescription->EventDesID: ", pRtnEventDescription->EventDesID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnEventDescription->UserName: ", pRtnEventDescription->UserName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnEventDescription->MonDate: ", pRtnEventDescription->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnEventDescription->MonTime: ", pRtnEventDescription->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnEventDescription->EventDes: ", pRtnEventDescription->EventDes, g_RunningResult_File);

    CShfeFtdcRtnEventDescriptionField* pNewRtnEventDescription = new CShfeFtdcRtnEventDescriptionField;
    memcpy (pNewRtnEventDescription, pRtnEventDescription, sizeof(CShfeFtdcRtnEventDescriptionField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnEventDescription;

    uv_mutex_lock (&g_RtnEventDescriptionTopic_mutex);
    g_RtnEventDescriptionTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnEventDescriptionTopic_mutex);

    uv_async_send(&g_RtnEventDescriptionTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnEventDescriptionTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryFrontUniqueIDTopic(CShfeFtdcRspQryFrontUniqueIDField* pRspQryFrontUniqueID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryFrontUniqueIDTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryFrontUniqueID) { 
        OutputCallbackMessage("pRspQryFrontUniqueID is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryFrontUniqueIDTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryFrontUniqueID->FrontID: ", pRspQryFrontUniqueID->FrontID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFrontUniqueID->FrontName: ", pRspQryFrontUniqueID->FrontName, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryFrontUniqueIDField* pNewRspQryFrontUniqueID = new CShfeFtdcRspQryFrontUniqueIDField;
    memcpy (pNewRspQryFrontUniqueID, pRspQryFrontUniqueID, sizeof(CShfeFtdcRspQryFrontUniqueIDField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryFrontUniqueID;

    uv_mutex_lock (&g_RspQryFrontUniqueIDTopic_mutex);
    g_RspQryFrontUniqueIDTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryFrontUniqueIDTopic_mutex);

    uv_async_send(&g_RspQryFrontUniqueIDTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryFrontUniqueIDTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnFrontUniqueIDTopic(CShfeFtdcRtnFrontUniqueIDField* pRtnFrontUniqueID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnFrontUniqueIDTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnFrontUniqueID) { 
        OutputCallbackMessage("pRtnFrontUniqueID is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnFrontUniqueIDTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnFrontUniqueID->FrontID: ", pRtnFrontUniqueID->FrontID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFrontUniqueID->FrontName: ", pRtnFrontUniqueID->FrontName, g_RunningResult_File);

    CShfeFtdcRtnFrontUniqueIDField* pNewRtnFrontUniqueID = new CShfeFtdcRtnFrontUniqueIDField;
    memcpy (pNewRtnFrontUniqueID, pRtnFrontUniqueID, sizeof(CShfeFtdcRtnFrontUniqueIDField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnFrontUniqueID;

    uv_mutex_lock (&g_RtnFrontUniqueIDTopic_mutex);
    g_RtnFrontUniqueIDTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnFrontUniqueIDTopic_mutex);

    uv_async_send(&g_RtnFrontUniqueIDTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnFrontUniqueIDTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetPartyLinkAddrChangeTopic(CShfeFtdcRspQryNetPartyLinkAddrChangeField* pRspQryNetPartyLinkAddrChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetPartyLinkAddrChangeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetPartyLinkAddrChange) { 
        OutputCallbackMessage("pRspQryNetPartyLinkAddrChange is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetPartyLinkAddrChangeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetPartyLinkAddrChange->OperationType: ", pRspQryNetPartyLinkAddrChange->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkAddrChange->ID: ", pRspQryNetPartyLinkAddrChange->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkAddrChange->RelationID: ", pRspQryNetPartyLinkAddrChange->RelationID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkAddrChange->OLDADDRESS: ", pRspQryNetPartyLinkAddrChange->OLDADDRESS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkAddrChange->NEWADDRESS: ", pRspQryNetPartyLinkAddrChange->NEWADDRESS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkAddrChange->OPERATOR: ", pRspQryNetPartyLinkAddrChange->OPERATOR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkAddrChange->MonDate: ", pRspQryNetPartyLinkAddrChange->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkAddrChange->MonTime: ", pRspQryNetPartyLinkAddrChange->MonTime, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetPartyLinkAddrChangeField* pNewRspQryNetPartyLinkAddrChange = new CShfeFtdcRspQryNetPartyLinkAddrChangeField;
    memcpy (pNewRspQryNetPartyLinkAddrChange, pRspQryNetPartyLinkAddrChange, sizeof(CShfeFtdcRspQryNetPartyLinkAddrChangeField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetPartyLinkAddrChange;

    uv_mutex_lock (&g_RspQryNetPartyLinkAddrChangeTopic_mutex);
    g_RspQryNetPartyLinkAddrChangeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetPartyLinkAddrChangeTopic_mutex);

    uv_async_send(&g_RspQryNetPartyLinkAddrChangeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetPartyLinkAddrChangeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetPartyLinkAddrChangeTopic(CShfeFtdcRtnNetPartyLinkAddrChangeField* pRtnNetPartyLinkAddrChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetPartyLinkAddrChangeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetPartyLinkAddrChange) { 
        OutputCallbackMessage("pRtnNetPartyLinkAddrChange is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetPartyLinkAddrChangeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetPartyLinkAddrChange->OperationType: ", pRtnNetPartyLinkAddrChange->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkAddrChange->ID: ", pRtnNetPartyLinkAddrChange->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkAddrChange->RelationID: ", pRtnNetPartyLinkAddrChange->RelationID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkAddrChange->OLDADDRESS: ", pRtnNetPartyLinkAddrChange->OLDADDRESS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkAddrChange->NEWADDRESS: ", pRtnNetPartyLinkAddrChange->NEWADDRESS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkAddrChange->OPERATOR: ", pRtnNetPartyLinkAddrChange->OPERATOR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkAddrChange->MonDate: ", pRtnNetPartyLinkAddrChange->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkAddrChange->MonTime: ", pRtnNetPartyLinkAddrChange->MonTime, g_RunningResult_File);

    CShfeFtdcRtnNetPartyLinkAddrChangeField* pNewRtnNetPartyLinkAddrChange = new CShfeFtdcRtnNetPartyLinkAddrChangeField;
    memcpy (pNewRtnNetPartyLinkAddrChange, pRtnNetPartyLinkAddrChange, sizeof(CShfeFtdcRtnNetPartyLinkAddrChangeField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetPartyLinkAddrChange;

    uv_mutex_lock (&g_RtnNetPartyLinkAddrChangeTopic_mutex);
    g_RtnNetPartyLinkAddrChangeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetPartyLinkAddrChangeTopic_mutex);

    uv_async_send(&g_RtnNetPartyLinkAddrChangeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetPartyLinkAddrChangeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetDelPartyLinkInfoTopic(CShfeFtdcRspQryNetDelPartyLinkInfoField* pRspQryNetDelPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetDelPartyLinkInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetDelPartyLinkInfo) { 
        OutputCallbackMessage("pRspQryNetDelPartyLinkInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetDelPartyLinkInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->OperationType: ", pRspQryNetDelPartyLinkInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->ID: ", pRspQryNetDelPartyLinkInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->MEMBER_NO: ", pRspQryNetDelPartyLinkInfo->MEMBER_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->MEMBER_NAME: ", pRspQryNetDelPartyLinkInfo->MEMBER_NAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->REMOTE_ADDR: ", pRspQryNetDelPartyLinkInfo->REMOTE_ADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->LOCAL_ADDR: ", pRspQryNetDelPartyLinkInfo->LOCAL_ADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->ADDRESS: ", pRspQryNetDelPartyLinkInfo->ADDRESS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->LINE_STATUS: ", pRspQryNetDelPartyLinkInfo->LINE_STATUS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->CONTACT: ", pRspQryNetDelPartyLinkInfo->CONTACT, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->TELEPHONE: ", pRspQryNetDelPartyLinkInfo->TELEPHONE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->MOBILEPHONE: ", pRspQryNetDelPartyLinkInfo->MOBILEPHONE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->EMAIL: ", pRspQryNetDelPartyLinkInfo->EMAIL, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->FAX: ", pRspQryNetDelPartyLinkInfo->FAX, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->PROVINCE: ", pRspQryNetDelPartyLinkInfo->PROVINCE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->DDN_NO: ", pRspQryNetDelPartyLinkInfo->DDN_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->IN_MODE: ", pRspQryNetDelPartyLinkInfo->IN_MODE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->IP_WAN: ", pRspQryNetDelPartyLinkInfo->IP_WAN, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->IP_LAN: ", pRspQryNetDelPartyLinkInfo->IP_LAN, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->IPADDR: ", pRspQryNetDelPartyLinkInfo->IPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->Interface: ", pRspQryNetDelPartyLinkInfo->Interface, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->INTERFACE_DATE: ", pRspQryNetDelPartyLinkInfo->INTERFACE_DATE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->SOFTWARE: ", pRspQryNetDelPartyLinkInfo->SOFTWARE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->FEE_TYPE: ", pRspQryNetDelPartyLinkInfo->FEE_TYPE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->SERVICEPROVIDER: ", pRspQryNetDelPartyLinkInfo->SERVICEPROVIDER, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->IF_ZIYING: ", pRspQryNetDelPartyLinkInfo->IF_ZIYING, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->IF_TUOGUAN: ", pRspQryNetDelPartyLinkInfo->IF_TUOGUAN, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->HASOTHER: ", pRspQryNetDelPartyLinkInfo->HASOTHER, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->SEAT_NO: ", pRspQryNetDelPartyLinkInfo->SEAT_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDelPartyLinkInfo->PRO: ", pRspQryNetDelPartyLinkInfo->PRO, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetDelPartyLinkInfoField* pNewRspQryNetDelPartyLinkInfo = new CShfeFtdcRspQryNetDelPartyLinkInfoField;
    memcpy (pNewRspQryNetDelPartyLinkInfo, pRspQryNetDelPartyLinkInfo, sizeof(CShfeFtdcRspQryNetDelPartyLinkInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetDelPartyLinkInfo;

    uv_mutex_lock (&g_RspQryNetDelPartyLinkInfoTopic_mutex);
    g_RspQryNetDelPartyLinkInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetDelPartyLinkInfoTopic_mutex);

    uv_async_send(&g_RspQryNetDelPartyLinkInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetDelPartyLinkInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetDelPartyLinkInfoTopic(CShfeFtdcRtnNetDelPartyLinkInfoField* pRtnNetDelPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetDelPartyLinkInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetDelPartyLinkInfo) { 
        OutputCallbackMessage("pRtnNetDelPartyLinkInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetDelPartyLinkInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->OperationType: ", pRtnNetDelPartyLinkInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->ID: ", pRtnNetDelPartyLinkInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->MEMBER_NO: ", pRtnNetDelPartyLinkInfo->MEMBER_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->MEMBER_NAME: ", pRtnNetDelPartyLinkInfo->MEMBER_NAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->REMOTE_ADDR: ", pRtnNetDelPartyLinkInfo->REMOTE_ADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->LOCAL_ADDR: ", pRtnNetDelPartyLinkInfo->LOCAL_ADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->ADDRESS: ", pRtnNetDelPartyLinkInfo->ADDRESS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->LINE_STATUS: ", pRtnNetDelPartyLinkInfo->LINE_STATUS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->CONTACT: ", pRtnNetDelPartyLinkInfo->CONTACT, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->TELEPHONE: ", pRtnNetDelPartyLinkInfo->TELEPHONE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->MOBILEPHONE: ", pRtnNetDelPartyLinkInfo->MOBILEPHONE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->EMAIL: ", pRtnNetDelPartyLinkInfo->EMAIL, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->FAX: ", pRtnNetDelPartyLinkInfo->FAX, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->PROVINCE: ", pRtnNetDelPartyLinkInfo->PROVINCE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->DDN_NO: ", pRtnNetDelPartyLinkInfo->DDN_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->IN_MODE: ", pRtnNetDelPartyLinkInfo->IN_MODE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->IP_WAN: ", pRtnNetDelPartyLinkInfo->IP_WAN, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->IP_LAN: ", pRtnNetDelPartyLinkInfo->IP_LAN, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->IPADDR: ", pRtnNetDelPartyLinkInfo->IPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->Interface: ", pRtnNetDelPartyLinkInfo->Interface, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->INTERFACE_DATE: ", pRtnNetDelPartyLinkInfo->INTERFACE_DATE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->SOFTWARE: ", pRtnNetDelPartyLinkInfo->SOFTWARE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->FEE_TYPE: ", pRtnNetDelPartyLinkInfo->FEE_TYPE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->SERVICEPROVIDER: ", pRtnNetDelPartyLinkInfo->SERVICEPROVIDER, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->IF_ZIYING: ", pRtnNetDelPartyLinkInfo->IF_ZIYING, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->IF_TUOGUAN: ", pRtnNetDelPartyLinkInfo->IF_TUOGUAN, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->HASOTHER: ", pRtnNetDelPartyLinkInfo->HASOTHER, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->SEAT_NO: ", pRtnNetDelPartyLinkInfo->SEAT_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDelPartyLinkInfo->PRO: ", pRtnNetDelPartyLinkInfo->PRO, g_RunningResult_File);

    CShfeFtdcRtnNetDelPartyLinkInfoField* pNewRtnNetDelPartyLinkInfo = new CShfeFtdcRtnNetDelPartyLinkInfoField;
    memcpy (pNewRtnNetDelPartyLinkInfo, pRtnNetDelPartyLinkInfo, sizeof(CShfeFtdcRtnNetDelPartyLinkInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetDelPartyLinkInfo;

    uv_mutex_lock (&g_RtnNetDelPartyLinkInfoTopic_mutex);
    g_RtnNetDelPartyLinkInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetDelPartyLinkInfoTopic_mutex);

    uv_async_send(&g_RtnNetDelPartyLinkInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetDelPartyLinkInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryPerformanceTopTopic(CShfeFtdcRspQryPerformanceTopField* pRspQryPerformanceTop, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryPerformanceTopTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryPerformanceTop) { 
        OutputCallbackMessage("pRspQryPerformanceTop is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryPerformanceTopTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryPerformanceTop->OperationType: ", pRspQryPerformanceTop->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPerformanceTop->AttrType: ", pRspQryPerformanceTop->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPerformanceTop->NetArea: ", pRspQryPerformanceTop->NetArea, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPerformanceTop->NetSubArea: ", pRspQryPerformanceTop->NetSubArea, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPerformanceTop->KeyWord: ", pRspQryPerformanceTop->KeyWord, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPerformanceTop->SortValue: ", pRspQryPerformanceTop->SortValue, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPerformanceTop->SortType: ", pRspQryPerformanceTop->SortType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPerformanceTop->DuringTimeType: ", pRspQryPerformanceTop->DuringTimeType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPerformanceTop->DuringTimeValue: ", pRspQryPerformanceTop->DuringTimeValue, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPerformanceTop->TopN: ", pRspQryPerformanceTop->TopN, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryPerformanceTop->TopResult: ", pRspQryPerformanceTop->TopResult, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryPerformanceTopField* pNewRspQryPerformanceTop = new CShfeFtdcRspQryPerformanceTopField;
    memcpy (pNewRspQryPerformanceTop, pRspQryPerformanceTop, sizeof(CShfeFtdcRspQryPerformanceTopField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryPerformanceTop;

    uv_mutex_lock (&g_RspQryPerformanceTopTopic_mutex);
    g_RspQryPerformanceTopTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryPerformanceTopTopic_mutex);

    uv_async_send(&g_RspQryPerformanceTopTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryPerformanceTopTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnPerformanceTopTopic(CShfeFtdcRtnPerformanceTopField* pRtnPerformanceTop, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnPerformanceTopTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnPerformanceTop) { 
        OutputCallbackMessage("pRtnPerformanceTop is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnPerformanceTopTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnPerformanceTop->OperationType: ", pRtnPerformanceTop->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPerformanceTop->AttrType: ", pRtnPerformanceTop->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPerformanceTop->NetArea: ", pRtnPerformanceTop->NetArea, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPerformanceTop->NetSubArea: ", pRtnPerformanceTop->NetSubArea, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPerformanceTop->KeyWord: ", pRtnPerformanceTop->KeyWord, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPerformanceTop->SortValue: ", pRtnPerformanceTop->SortValue, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPerformanceTop->SortType: ", pRtnPerformanceTop->SortType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPerformanceTop->DuringTimeType: ", pRtnPerformanceTop->DuringTimeType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPerformanceTop->DuringTimeValue: ", pRtnPerformanceTop->DuringTimeValue, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPerformanceTop->TopN: ", pRtnPerformanceTop->TopN, g_RunningResult_File);
    OutputCallbackMessage(" pRtnPerformanceTop->TopResult: ", pRtnPerformanceTop->TopResult, g_RunningResult_File);

    CShfeFtdcRtnPerformanceTopField* pNewRtnPerformanceTop = new CShfeFtdcRtnPerformanceTopField;
    memcpy (pNewRtnPerformanceTop, pRtnPerformanceTop, sizeof(CShfeFtdcRtnPerformanceTopField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnPerformanceTop;

    uv_mutex_lock (&g_RtnPerformanceTopTopic_mutex);
    g_RtnPerformanceTopTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnPerformanceTopTopic_mutex);

    uv_async_send(&g_RtnPerformanceTopTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnPerformanceTopTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryInstrumentStatusTopic(CShfeFtdcRspQryInstrumentStatusField* pRspQryInstrumentStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryInstrumentStatusTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryInstrumentStatus) { 
        OutputCallbackMessage("pRspQryInstrumentStatus is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryInstrumentStatusTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryInstrumentStatus->SettlementGroupID: ", pRspQryInstrumentStatus->SettlementGroupID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstrumentStatus->InstrumentID: ", pRspQryInstrumentStatus->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstrumentStatus->InstrumentStatus: ", pRspQryInstrumentStatus->InstrumentStatus, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstrumentStatus->TradingSegmentSN: ", pRspQryInstrumentStatus->TradingSegmentSN, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstrumentStatus->EnterTime: ", pRspQryInstrumentStatus->EnterTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstrumentStatus->EnterReason: ", pRspQryInstrumentStatus->EnterReason, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryInstrumentStatus->EnterDate: ", pRspQryInstrumentStatus->EnterDate, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryInstrumentStatusField* pNewRspQryInstrumentStatus = new CShfeFtdcRspQryInstrumentStatusField;
    memcpy (pNewRspQryInstrumentStatus, pRspQryInstrumentStatus, sizeof(CShfeFtdcRspQryInstrumentStatusField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryInstrumentStatus;

    uv_mutex_lock (&g_RspQryInstrumentStatusTopic_mutex);
    g_RspQryInstrumentStatusTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryInstrumentStatusTopic_mutex);

    uv_async_send(&g_RspQryInstrumentStatusTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryInstrumentStatusTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnInstrumentStatusTopic(CShfeFtdcRtnInstrumentStatusField* pRtnInstrumentStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnInstrumentStatusTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnInstrumentStatus) { 
        OutputCallbackMessage("pRtnInstrumentStatus is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnInstrumentStatusTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnInstrumentStatus->SettlementGroupID: ", pRtnInstrumentStatus->SettlementGroupID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstrumentStatus->InstrumentID: ", pRtnInstrumentStatus->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstrumentStatus->InstrumentStatus: ", pRtnInstrumentStatus->InstrumentStatus, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstrumentStatus->TradingSegmentSN: ", pRtnInstrumentStatus->TradingSegmentSN, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstrumentStatus->EnterTime: ", pRtnInstrumentStatus->EnterTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstrumentStatus->EnterReason: ", pRtnInstrumentStatus->EnterReason, g_RunningResult_File);
    OutputCallbackMessage(" pRtnInstrumentStatus->EnterDate: ", pRtnInstrumentStatus->EnterDate, g_RunningResult_File);

    CShfeFtdcRtnInstrumentStatusField* pNewRtnInstrumentStatus = new CShfeFtdcRtnInstrumentStatusField;
    memcpy (pNewRtnInstrumentStatus, pRtnInstrumentStatus, sizeof(CShfeFtdcRtnInstrumentStatusField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnInstrumentStatus;

    uv_mutex_lock (&g_RtnInstrumentStatusTopic_mutex);
    g_RtnInstrumentStatusTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnInstrumentStatusTopic_mutex);

    uv_async_send(&g_RtnInstrumentStatusTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnInstrumentStatusTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryCurrTradingSegmentAttrTopic(CShfeFtdcRspQryCurrTradingSegmentAttrField* pRspQryCurrTradingSegmentAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryCurrTradingSegmentAttrTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryCurrTradingSegmentAttr) { 
        OutputCallbackMessage("pRspQryCurrTradingSegmentAttr is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryCurrTradingSegmentAttrTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryCurrTradingSegmentAttr->SettlementGroupID: ", pRspQryCurrTradingSegmentAttr->SettlementGroupID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryCurrTradingSegmentAttr->TradingSegmentSN: ", pRspQryCurrTradingSegmentAttr->TradingSegmentSN, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryCurrTradingSegmentAttr->TradingSegmentName: ", pRspQryCurrTradingSegmentAttr->TradingSegmentName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryCurrTradingSegmentAttr->StartTime: ", pRspQryCurrTradingSegmentAttr->StartTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryCurrTradingSegmentAttr->InstrumentStatus: ", pRspQryCurrTradingSegmentAttr->InstrumentStatus, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryCurrTradingSegmentAttr->InstrumentID: ", pRspQryCurrTradingSegmentAttr->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryCurrTradingSegmentAttr->AdvanceDays: ", pRspQryCurrTradingSegmentAttr->AdvanceDays, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryCurrTradingSegmentAttrField* pNewRspQryCurrTradingSegmentAttr = new CShfeFtdcRspQryCurrTradingSegmentAttrField;
    memcpy (pNewRspQryCurrTradingSegmentAttr, pRspQryCurrTradingSegmentAttr, sizeof(CShfeFtdcRspQryCurrTradingSegmentAttrField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryCurrTradingSegmentAttr;

    uv_mutex_lock (&g_RspQryCurrTradingSegmentAttrTopic_mutex);
    g_RspQryCurrTradingSegmentAttrTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryCurrTradingSegmentAttrTopic_mutex);

    uv_async_send(&g_RspQryCurrTradingSegmentAttrTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryCurrTradingSegmentAttrTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnCurrTradingSegmentAttrTopic(CShfeFtdcRtnCurrTradingSegmentAttrField* pRtnCurrTradingSegmentAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnCurrTradingSegmentAttrTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnCurrTradingSegmentAttr) { 
        OutputCallbackMessage("pRtnCurrTradingSegmentAttr is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnCurrTradingSegmentAttrTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnCurrTradingSegmentAttr->SettlementGroupID: ", pRtnCurrTradingSegmentAttr->SettlementGroupID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnCurrTradingSegmentAttr->TradingSegmentSN: ", pRtnCurrTradingSegmentAttr->TradingSegmentSN, g_RunningResult_File);
    OutputCallbackMessage(" pRtnCurrTradingSegmentAttr->TradingSegmentName: ", pRtnCurrTradingSegmentAttr->TradingSegmentName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnCurrTradingSegmentAttr->StartTime: ", pRtnCurrTradingSegmentAttr->StartTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnCurrTradingSegmentAttr->InstrumentStatus: ", pRtnCurrTradingSegmentAttr->InstrumentStatus, g_RunningResult_File);
    OutputCallbackMessage(" pRtnCurrTradingSegmentAttr->InstrumentID: ", pRtnCurrTradingSegmentAttr->InstrumentID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnCurrTradingSegmentAttr->AdvanceDays: ", pRtnCurrTradingSegmentAttr->AdvanceDays, g_RunningResult_File);

    CShfeFtdcRtnCurrTradingSegmentAttrField* pNewRtnCurrTradingSegmentAttr = new CShfeFtdcRtnCurrTradingSegmentAttrField;
    memcpy (pNewRtnCurrTradingSegmentAttr, pRtnCurrTradingSegmentAttr, sizeof(CShfeFtdcRtnCurrTradingSegmentAttrField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnCurrTradingSegmentAttr;

    uv_mutex_lock (&g_RtnCurrTradingSegmentAttrTopic_mutex);
    g_RtnCurrTradingSegmentAttrTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnCurrTradingSegmentAttrTopic_mutex);

    uv_async_send(&g_RtnCurrTradingSegmentAttrTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnCurrTradingSegmentAttrTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetAreaTopic(CShfeFtdcRspQryNetAreaField* pRspQryNetArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetAreaTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetArea) { 
        OutputCallbackMessage("pRspQryNetArea is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetAreaTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetArea->OperationType: ", pRspQryNetArea->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetArea->ID: ", pRspQryNetArea->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetArea->CName: ", pRspQryNetArea->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetArea->EName: ", pRspQryNetArea->EName, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetAreaField* pNewRspQryNetArea = new CShfeFtdcRspQryNetAreaField;
    memcpy (pNewRspQryNetArea, pRspQryNetArea, sizeof(CShfeFtdcRspQryNetAreaField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetArea;

    uv_mutex_lock (&g_RspQryNetAreaTopic_mutex);
    g_RspQryNetAreaTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetAreaTopic_mutex);

    uv_async_send(&g_RspQryNetAreaTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetAreaTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetAreaTopic(CShfeFtdcRtnNetAreaField* pRtnNetArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetAreaTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetArea) { 
        OutputCallbackMessage("pRtnNetArea is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetAreaTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetArea->OperationType: ", pRtnNetArea->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetArea->ID: ", pRtnNetArea->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetArea->CName: ", pRtnNetArea->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetArea->EName: ", pRtnNetArea->EName, g_RunningResult_File);

    CShfeFtdcRtnNetAreaField* pNewRtnNetArea = new CShfeFtdcRtnNetAreaField;
    memcpy (pNewRtnNetArea, pRtnNetArea, sizeof(CShfeFtdcRtnNetAreaField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetArea;

    uv_mutex_lock (&g_RtnNetAreaTopic_mutex);
    g_RtnNetAreaTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetAreaTopic_mutex);

    uv_async_send(&g_RtnNetAreaTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetAreaTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetSubAreaTopic(CShfeFtdcRspQryNetSubAreaField* pRspQryNetSubArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetSubAreaTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetSubArea) { 
        OutputCallbackMessage("pRspQryNetSubArea is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetSubAreaTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetSubArea->OperationType: ", pRspQryNetSubArea->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetSubArea->ID: ", pRspQryNetSubArea->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetSubArea->SysNetAreaID: ", pRspQryNetSubArea->SysNetAreaID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetSubArea->CName: ", pRspQryNetSubArea->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetSubArea->EName: ", pRspQryNetSubArea->EName, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetSubAreaField* pNewRspQryNetSubArea = new CShfeFtdcRspQryNetSubAreaField;
    memcpy (pNewRspQryNetSubArea, pRspQryNetSubArea, sizeof(CShfeFtdcRspQryNetSubAreaField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetSubArea;

    uv_mutex_lock (&g_RspQryNetSubAreaTopic_mutex);
    g_RspQryNetSubAreaTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetSubAreaTopic_mutex);

    uv_async_send(&g_RspQryNetSubAreaTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetSubAreaTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetSubAreaTopic(CShfeFtdcRtnNetSubAreaField* pRtnNetSubArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetSubAreaTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetSubArea) { 
        OutputCallbackMessage("pRtnNetSubArea is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetSubAreaTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetSubArea->OperationType: ", pRtnNetSubArea->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetSubArea->ID: ", pRtnNetSubArea->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetSubArea->SysNetAreaID: ", pRtnNetSubArea->SysNetAreaID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetSubArea->CName: ", pRtnNetSubArea->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetSubArea->EName: ", pRtnNetSubArea->EName, g_RunningResult_File);

    CShfeFtdcRtnNetSubAreaField* pNewRtnNetSubArea = new CShfeFtdcRtnNetSubAreaField;
    memcpy (pNewRtnNetSubArea, pRtnNetSubArea, sizeof(CShfeFtdcRtnNetSubAreaField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetSubArea;

    uv_mutex_lock (&g_RtnNetSubAreaTopic_mutex);
    g_RtnNetSubAreaTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetSubAreaTopic_mutex);

    uv_async_send(&g_RtnNetSubAreaTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetSubAreaTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetSubAreaIPTopic(CShfeFtdcRspQryNetSubAreaIPField* pRspQryNetSubAreaIP, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetSubAreaIPTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetSubAreaIP) { 
        OutputCallbackMessage("pRspQryNetSubAreaIP is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetSubAreaIPTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetSubAreaIP->OperationType: ", pRspQryNetSubAreaIP->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetSubAreaIP->ID: ", pRspQryNetSubAreaIP->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetSubAreaIP->SysNetSubAreaID: ", pRspQryNetSubAreaIP->SysNetSubAreaID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetSubAreaIP->IP: ", pRspQryNetSubAreaIP->IP, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetSubAreaIP->Mask: ", pRspQryNetSubAreaIP->Mask, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetSubAreaIPField* pNewRspQryNetSubAreaIP = new CShfeFtdcRspQryNetSubAreaIPField;
    memcpy (pNewRspQryNetSubAreaIP, pRspQryNetSubAreaIP, sizeof(CShfeFtdcRspQryNetSubAreaIPField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetSubAreaIP;

    uv_mutex_lock (&g_RspQryNetSubAreaIPTopic_mutex);
    g_RspQryNetSubAreaIPTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetSubAreaIPTopic_mutex);

    uv_async_send(&g_RspQryNetSubAreaIPTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetSubAreaIPTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetSubAreaIPTopic(CShfeFtdcRtnNetSubAreaIPField* pRtnNetSubAreaIP, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetSubAreaIPTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetSubAreaIP) { 
        OutputCallbackMessage("pRtnNetSubAreaIP is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetSubAreaIPTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetSubAreaIP->OperationType: ", pRtnNetSubAreaIP->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetSubAreaIP->ID: ", pRtnNetSubAreaIP->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetSubAreaIP->SysNetSubAreaID: ", pRtnNetSubAreaIP->SysNetSubAreaID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetSubAreaIP->IP: ", pRtnNetSubAreaIP->IP, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetSubAreaIP->Mask: ", pRtnNetSubAreaIP->Mask, g_RunningResult_File);

    CShfeFtdcRtnNetSubAreaIPField* pNewRtnNetSubAreaIP = new CShfeFtdcRtnNetSubAreaIPField;
    memcpy (pNewRtnNetSubAreaIP, pRtnNetSubAreaIP, sizeof(CShfeFtdcRtnNetSubAreaIPField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetSubAreaIP;

    uv_mutex_lock (&g_RtnNetSubAreaIPTopic_mutex);
    g_RtnNetSubAreaIPTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetSubAreaIPTopic_mutex);

    uv_async_send(&g_RtnNetSubAreaIPTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetSubAreaIPTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetDeviceTopic(CShfeFtdcRspQryNetDeviceField* pRspQryNetDevice, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetDeviceTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetDevice) { 
        OutputCallbackMessage("pRspQryNetDevice is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetDeviceTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetDevice->OperationType: ", pRspQryNetDevice->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->ID: ", pRspQryNetDevice->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->ObjectID: ", pRspQryNetDevice->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->MonitorType_ID: ", pRspQryNetDevice->MonitorType_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->SysNetSubAreaID: ", pRspQryNetDevice->SysNetSubAreaID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->CATEGORY_ID: ", pRspQryNetDevice->CATEGORY_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->FuctionArea: ", pRspQryNetDevice->FuctionArea, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->IPADDR: ", pRspQryNetDevice->IPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->IPDECODE: ", pRspQryNetDevice->IPDECODE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->NAME: ", pRspQryNetDevice->NAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->PORTNUMBER: ", pRspQryNetDevice->PORTNUMBER, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->CONFIGFILE: ", pRspQryNetDevice->CONFIGFILE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->RCOMMUNITY: ", pRspQryNetDevice->RCOMMUNITY, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->SNMPVERSION: ", pRspQryNetDevice->SNMPVERSION, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->RAMSIZE: ", pRspQryNetDevice->RAMSIZE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->FLASHSIZE: ", pRspQryNetDevice->FLASHSIZE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->NVRAMSIZE: ", pRspQryNetDevice->NVRAMSIZE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->CABINET_ID: ", pRspQryNetDevice->CABINET_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->ROOM_ID: ", pRspQryNetDevice->ROOM_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->IOSVERSION_ID: ", pRspQryNetDevice->IOSVERSION_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->DESCRIPTION: ", pRspQryNetDevice->DESCRIPTION, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->USERNAME: ", pRspQryNetDevice->USERNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->PASSWD: ", pRspQryNetDevice->PASSWD, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->ENPASSWD: ", pRspQryNetDevice->ENPASSWD, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->MANUFACTORY_ID: ", pRspQryNetDevice->MANUFACTORY_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->CFGSAVETYPE: ", pRspQryNetDevice->CFGSAVETYPE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->DEVICETYPE: ", pRspQryNetDevice->DEVICETYPE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->SENDSMS: ", pRspQryNetDevice->SENDSMS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->ISSNMP: ", pRspQryNetDevice->ISSNMP, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->SLOTNUM: ", pRspQryNetDevice->SLOTNUM, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->ISPING: ", pRspQryNetDevice->ISPING, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->IFNUM: ", pRspQryNetDevice->IFNUM, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDevice->APPLICATION_ID: ", pRspQryNetDevice->APPLICATION_ID, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetDeviceField* pNewRspQryNetDevice = new CShfeFtdcRspQryNetDeviceField;
    memcpy (pNewRspQryNetDevice, pRspQryNetDevice, sizeof(CShfeFtdcRspQryNetDeviceField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetDevice;

    uv_mutex_lock (&g_RspQryNetDeviceTopic_mutex);
    g_RspQryNetDeviceTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetDeviceTopic_mutex);

    uv_async_send(&g_RspQryNetDeviceTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetDeviceTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetDeviceTopic(CShfeFtdcRtnNetDeviceField* pRtnNetDevice, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetDeviceTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetDevice) { 
        OutputCallbackMessage("pRtnNetDevice is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetDeviceTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetDevice->OperationType: ", pRtnNetDevice->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->ID: ", pRtnNetDevice->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->ObjectID: ", pRtnNetDevice->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->MonitorType_ID: ", pRtnNetDevice->MonitorType_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->SysNetSubAreaID: ", pRtnNetDevice->SysNetSubAreaID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->CATEGORY_ID: ", pRtnNetDevice->CATEGORY_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->FuctionArea: ", pRtnNetDevice->FuctionArea, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->IPADDR: ", pRtnNetDevice->IPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->IPDECODE: ", pRtnNetDevice->IPDECODE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->NAME: ", pRtnNetDevice->NAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->PORTNUMBER: ", pRtnNetDevice->PORTNUMBER, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->CONFIGFILE: ", pRtnNetDevice->CONFIGFILE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->RCOMMUNITY: ", pRtnNetDevice->RCOMMUNITY, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->SNMPVERSION: ", pRtnNetDevice->SNMPVERSION, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->RAMSIZE: ", pRtnNetDevice->RAMSIZE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->FLASHSIZE: ", pRtnNetDevice->FLASHSIZE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->NVRAMSIZE: ", pRtnNetDevice->NVRAMSIZE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->CABINET_ID: ", pRtnNetDevice->CABINET_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->ROOM_ID: ", pRtnNetDevice->ROOM_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->IOSVERSION_ID: ", pRtnNetDevice->IOSVERSION_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->DESCRIPTION: ", pRtnNetDevice->DESCRIPTION, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->USERNAME: ", pRtnNetDevice->USERNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->PASSWD: ", pRtnNetDevice->PASSWD, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->ENPASSWD: ", pRtnNetDevice->ENPASSWD, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->MANUFACTORY_ID: ", pRtnNetDevice->MANUFACTORY_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->CFGSAVETYPE: ", pRtnNetDevice->CFGSAVETYPE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->DEVICETYPE: ", pRtnNetDevice->DEVICETYPE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->SENDSMS: ", pRtnNetDevice->SENDSMS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->ISSNMP: ", pRtnNetDevice->ISSNMP, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->SLOTNUM: ", pRtnNetDevice->SLOTNUM, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->ISPING: ", pRtnNetDevice->ISPING, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->IFNUM: ", pRtnNetDevice->IFNUM, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDevice->APPLICATION_ID: ", pRtnNetDevice->APPLICATION_ID, g_RunningResult_File);

    CShfeFtdcRtnNetDeviceField* pNewRtnNetDevice = new CShfeFtdcRtnNetDeviceField;
    memcpy (pNewRtnNetDevice, pRtnNetDevice, sizeof(CShfeFtdcRtnNetDeviceField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetDevice;

    uv_mutex_lock (&g_RtnNetDeviceTopic_mutex);
    g_RtnNetDeviceTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetDeviceTopic_mutex);

    uv_async_send(&g_RtnNetDeviceTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetDeviceTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetDeviceDetectTopic(CShfeFtdcRspQryNetDeviceDetectField* pRspQryNetDeviceDetect, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetDeviceDetectTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetDeviceDetect) { 
        OutputCallbackMessage("pRspQryNetDeviceDetect is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetDeviceDetectTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetDeviceDetect->SysNetAreaID: ", pRspQryNetDeviceDetect->SysNetAreaID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceDetect->SysNetSubAreaID: ", pRspQryNetDeviceDetect->SysNetSubAreaID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceDetect->IP: ", pRspQryNetDeviceDetect->IP, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceDetect->Mask: ", pRspQryNetDeviceDetect->Mask, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetDeviceDetectField* pNewRspQryNetDeviceDetect = new CShfeFtdcRspQryNetDeviceDetectField;
    memcpy (pNewRspQryNetDeviceDetect, pRspQryNetDeviceDetect, sizeof(CShfeFtdcRspQryNetDeviceDetectField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetDeviceDetect;

    uv_mutex_lock (&g_RspQryNetDeviceDetectTopic_mutex);
    g_RspQryNetDeviceDetectTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetDeviceDetectTopic_mutex);

    uv_async_send(&g_RspQryNetDeviceDetectTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetDeviceDetectTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetBuildingTopic(CShfeFtdcRspQryNetBuildingField* pRspQryNetBuilding, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetBuildingTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetBuilding) { 
        OutputCallbackMessage("pRspQryNetBuilding is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetBuildingTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetBuilding->OperationType: ", pRspQryNetBuilding->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBuilding->ID: ", pRspQryNetBuilding->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBuilding->CName: ", pRspQryNetBuilding->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBuilding->EName: ", pRspQryNetBuilding->EName, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetBuildingField* pNewRspQryNetBuilding = new CShfeFtdcRspQryNetBuildingField;
    memcpy (pNewRspQryNetBuilding, pRspQryNetBuilding, sizeof(CShfeFtdcRspQryNetBuildingField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetBuilding;

    uv_mutex_lock (&g_RspQryNetBuildingTopic_mutex);
    g_RspQryNetBuildingTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetBuildingTopic_mutex);

    uv_async_send(&g_RspQryNetBuildingTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetBuildingTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetBuildingTopic(CShfeFtdcRtnNetBuildingField* pRtnNetBuilding, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetBuildingTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetBuilding) { 
        OutputCallbackMessage("pRtnNetBuilding is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetBuildingTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetBuilding->OperationType: ", pRtnNetBuilding->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBuilding->ID: ", pRtnNetBuilding->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBuilding->CName: ", pRtnNetBuilding->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBuilding->EName: ", pRtnNetBuilding->EName, g_RunningResult_File);

    CShfeFtdcRtnNetBuildingField* pNewRtnNetBuilding = new CShfeFtdcRtnNetBuildingField;
    memcpy (pNewRtnNetBuilding, pRtnNetBuilding, sizeof(CShfeFtdcRtnNetBuildingField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetBuilding;

    uv_mutex_lock (&g_RtnNetBuildingTopic_mutex);
    g_RtnNetBuildingTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetBuildingTopic_mutex);

    uv_async_send(&g_RtnNetBuildingTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetBuildingTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetRoomTopic(CShfeFtdcRspQryNetRoomField* pRspQryNetRoom, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetRoomTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetRoom) { 
        OutputCallbackMessage("pRspQryNetRoom is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetRoomTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetRoom->OperationType: ", pRspQryNetRoom->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetRoom->ID: ", pRspQryNetRoom->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetRoom->SysNetBuildingID: ", pRspQryNetRoom->SysNetBuildingID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetRoom->CName: ", pRspQryNetRoom->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetRoom->EName: ", pRspQryNetRoom->EName, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetRoomField* pNewRspQryNetRoom = new CShfeFtdcRspQryNetRoomField;
    memcpy (pNewRspQryNetRoom, pRspQryNetRoom, sizeof(CShfeFtdcRspQryNetRoomField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetRoom;

    uv_mutex_lock (&g_RspQryNetRoomTopic_mutex);
    g_RspQryNetRoomTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetRoomTopic_mutex);

    uv_async_send(&g_RspQryNetRoomTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetRoomTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetRoomTopic(CShfeFtdcRtnNetRoomField* pRtnNetRoom, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetRoomTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetRoom) { 
        OutputCallbackMessage("pRtnNetRoom is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetRoomTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetRoom->OperationType: ", pRtnNetRoom->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetRoom->ID: ", pRtnNetRoom->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetRoom->SysNetBuildingID: ", pRtnNetRoom->SysNetBuildingID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetRoom->CName: ", pRtnNetRoom->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetRoom->EName: ", pRtnNetRoom->EName, g_RunningResult_File);

    CShfeFtdcRtnNetRoomField* pNewRtnNetRoom = new CShfeFtdcRtnNetRoomField;
    memcpy (pNewRtnNetRoom, pRtnNetRoom, sizeof(CShfeFtdcRtnNetRoomField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetRoom;

    uv_mutex_lock (&g_RtnNetRoomTopic_mutex);
    g_RtnNetRoomTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetRoomTopic_mutex);

    uv_async_send(&g_RtnNetRoomTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetRoomTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetCabinetsTopic(CShfeFtdcRspQryNetCabinetsField* pRspQryNetCabinets, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetCabinetsTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetCabinets) { 
        OutputCallbackMessage("pRspQryNetCabinets is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetCabinetsTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetCabinets->OperationType: ", pRspQryNetCabinets->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetCabinets->ID: ", pRspQryNetCabinets->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetCabinets->SysNetRoomID: ", pRspQryNetCabinets->SysNetRoomID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetCabinets->SysNetBuildingID: ", pRspQryNetCabinets->SysNetBuildingID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetCabinets->CName: ", pRspQryNetCabinets->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetCabinets->EName: ", pRspQryNetCabinets->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetCabinets->CabinetsType: ", pRspQryNetCabinets->CabinetsType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetCabinetsField* pNewRspQryNetCabinets = new CShfeFtdcRspQryNetCabinetsField;
    memcpy (pNewRspQryNetCabinets, pRspQryNetCabinets, sizeof(CShfeFtdcRspQryNetCabinetsField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetCabinets;

    uv_mutex_lock (&g_RspQryNetCabinetsTopic_mutex);
    g_RspQryNetCabinetsTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetCabinetsTopic_mutex);

    uv_async_send(&g_RspQryNetCabinetsTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetCabinetsTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetCabinetsTopic(CShfeFtdcRtnNetCabinetsField* pRtnNetCabinets, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetCabinetsTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetCabinets) { 
        OutputCallbackMessage("pRtnNetCabinets is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetCabinetsTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetCabinets->OperationType: ", pRtnNetCabinets->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetCabinets->ID: ", pRtnNetCabinets->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetCabinets->SysNetRoomID: ", pRtnNetCabinets->SysNetRoomID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetCabinets->SysNetBuildingID: ", pRtnNetCabinets->SysNetBuildingID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetCabinets->CName: ", pRtnNetCabinets->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetCabinets->EName: ", pRtnNetCabinets->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetCabinets->CabinetsType: ", pRtnNetCabinets->CabinetsType, g_RunningResult_File);

    CShfeFtdcRtnNetCabinetsField* pNewRtnNetCabinets = new CShfeFtdcRtnNetCabinetsField;
    memcpy (pNewRtnNetCabinets, pRtnNetCabinets, sizeof(CShfeFtdcRtnNetCabinetsField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetCabinets;

    uv_mutex_lock (&g_RtnNetCabinetsTopic_mutex);
    g_RtnNetCabinetsTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetCabinetsTopic_mutex);

    uv_async_send(&g_RtnNetCabinetsTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetCabinetsTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetOIDTopic(CShfeFtdcRspQryNetOIDField* pRspQryNetOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetOIDTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetOID) { 
        OutputCallbackMessage("pRspQryNetOID is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetOIDTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetOID->OperationType: ", pRspQryNetOID->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetOID->ID: ", pRspQryNetOID->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetOID->Manufactory: ", pRspQryNetOID->Manufactory, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetOID->DeviceType: ", pRspQryNetOID->DeviceType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetOID->CName: ", pRspQryNetOID->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetOID->EName: ", pRspQryNetOID->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetOID->OID: ", pRspQryNetOID->OID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetOID->Unit: ", pRspQryNetOID->Unit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetOID->isTheTable: ", pRspQryNetOID->isTheTable, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetOIDField* pNewRspQryNetOID = new CShfeFtdcRspQryNetOIDField;
    memcpy (pNewRspQryNetOID, pRspQryNetOID, sizeof(CShfeFtdcRspQryNetOIDField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetOID;

    uv_mutex_lock (&g_RspQryNetOIDTopic_mutex);
    g_RspQryNetOIDTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetOIDTopic_mutex);

    uv_async_send(&g_RspQryNetOIDTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetOIDTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetOIDTopic(CShfeFtdcRtnNetOIDField* pRtnNetOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetOIDTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetOID) { 
        OutputCallbackMessage("pRtnNetOID is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetOIDTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetOID->OperationType: ", pRtnNetOID->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetOID->ID: ", pRtnNetOID->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetOID->Manufactory: ", pRtnNetOID->Manufactory, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetOID->DeviceType: ", pRtnNetOID->DeviceType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetOID->CName: ", pRtnNetOID->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetOID->EName: ", pRtnNetOID->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetOID->OID: ", pRtnNetOID->OID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetOID->Unit: ", pRtnNetOID->Unit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetOID->isTheTable: ", pRtnNetOID->isTheTable, g_RunningResult_File);

    CShfeFtdcRtnNetOIDField* pNewRtnNetOID = new CShfeFtdcRtnNetOIDField;
    memcpy (pNewRtnNetOID, pRtnNetOID, sizeof(CShfeFtdcRtnNetOIDField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetOID;

    uv_mutex_lock (&g_RtnNetOIDTopic_mutex);
    g_RtnNetOIDTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetOIDTopic_mutex);

    uv_async_send(&g_RtnNetOIDTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetOIDTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetTimePolicyTopic(CShfeFtdcRspQryNetTimePolicyField* pRspQryNetTimePolicy, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetTimePolicyTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetTimePolicy) { 
        OutputCallbackMessage("pRspQryNetTimePolicy is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetTimePolicyTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetTimePolicy->OperationType: ", pRspQryNetTimePolicy->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetTimePolicy->ID: ", pRspQryNetTimePolicy->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetTimePolicy->CName: ", pRspQryNetTimePolicy->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetTimePolicy->EName: ", pRspQryNetTimePolicy->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetTimePolicy->PolicyType: ", pRspQryNetTimePolicy->PolicyType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetTimePolicy->PolicyString: ", pRspQryNetTimePolicy->PolicyString, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetTimePolicy->TradingDay: ", pRspQryNetTimePolicy->TradingDay, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetTimePolicy->Description: ", pRspQryNetTimePolicy->Description, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetTimePolicy->Operation: ", pRspQryNetTimePolicy->Operation, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetTimePolicyField* pNewRspQryNetTimePolicy = new CShfeFtdcRspQryNetTimePolicyField;
    memcpy (pNewRspQryNetTimePolicy, pRspQryNetTimePolicy, sizeof(CShfeFtdcRspQryNetTimePolicyField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetTimePolicy;

    uv_mutex_lock (&g_RspQryNetTimePolicyTopic_mutex);
    g_RspQryNetTimePolicyTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetTimePolicyTopic_mutex);

    uv_async_send(&g_RspQryNetTimePolicyTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetTimePolicyTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetTimePolicyTopic(CShfeFtdcRtnNetTimePolicyField* pRtnNetTimePolicy, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetTimePolicyTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetTimePolicy) { 
        OutputCallbackMessage("pRtnNetTimePolicy is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetTimePolicyTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetTimePolicy->OperationType: ", pRtnNetTimePolicy->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetTimePolicy->ID: ", pRtnNetTimePolicy->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetTimePolicy->CName: ", pRtnNetTimePolicy->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetTimePolicy->EName: ", pRtnNetTimePolicy->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetTimePolicy->PolicyType: ", pRtnNetTimePolicy->PolicyType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetTimePolicy->PolicyString: ", pRtnNetTimePolicy->PolicyString, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetTimePolicy->TradingDay: ", pRtnNetTimePolicy->TradingDay, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetTimePolicy->Description: ", pRtnNetTimePolicy->Description, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetTimePolicy->Operation: ", pRtnNetTimePolicy->Operation, g_RunningResult_File);

    CShfeFtdcRtnNetTimePolicyField* pNewRtnNetTimePolicy = new CShfeFtdcRtnNetTimePolicyField;
    memcpy (pNewRtnNetTimePolicy, pRtnNetTimePolicy, sizeof(CShfeFtdcRtnNetTimePolicyField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetTimePolicy;

    uv_mutex_lock (&g_RtnNetTimePolicyTopic_mutex);
    g_RtnNetTimePolicyTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetTimePolicyTopic_mutex);

    uv_async_send(&g_RtnNetTimePolicyTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetTimePolicyTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetGatherTaskTopic(CShfeFtdcRspQryNetGatherTaskField* pRspQryNetGatherTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetGatherTaskTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetGatherTask) { 
        OutputCallbackMessage("pRspQryNetGatherTask is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetGatherTaskTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetGatherTask->OperationType: ", pRspQryNetGatherTask->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetGatherTask->ID: ", pRspQryNetGatherTask->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetGatherTask->ObjectID: ", pRspQryNetGatherTask->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetGatherTask->AttrType: ", pRspQryNetGatherTask->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetGatherTask->PolicyTypeID: ", pRspQryNetGatherTask->PolicyTypeID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetGatherTask->DataType: ", pRspQryNetGatherTask->DataType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetGatherTask->TypeFlag: ", pRspQryNetGatherTask->TypeFlag, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetGatherTaskField* pNewRspQryNetGatherTask = new CShfeFtdcRspQryNetGatherTaskField;
    memcpy (pNewRspQryNetGatherTask, pRspQryNetGatherTask, sizeof(CShfeFtdcRspQryNetGatherTaskField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetGatherTask;

    uv_mutex_lock (&g_RspQryNetGatherTaskTopic_mutex);
    g_RspQryNetGatherTaskTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetGatherTaskTopic_mutex);

    uv_async_send(&g_RspQryNetGatherTaskTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetGatherTaskTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetGatherTaskTopic(CShfeFtdcRtnNetGatherTaskField* pRtnNetGatherTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetGatherTaskTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetGatherTask) { 
        OutputCallbackMessage("pRtnNetGatherTask is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetGatherTaskTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetGatherTask->OperationType: ", pRtnNetGatherTask->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetGatherTask->ID: ", pRtnNetGatherTask->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetGatherTask->ObjectID: ", pRtnNetGatherTask->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetGatherTask->AttrType: ", pRtnNetGatherTask->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetGatherTask->PolicyTypeID: ", pRtnNetGatherTask->PolicyTypeID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetGatherTask->DataType: ", pRtnNetGatherTask->DataType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetGatherTask->TypeFlag: ", pRtnNetGatherTask->TypeFlag, g_RunningResult_File);

    CShfeFtdcRtnNetGatherTaskField* pNewRtnNetGatherTask = new CShfeFtdcRtnNetGatherTaskField;
    memcpy (pNewRtnNetGatherTask, pRtnNetGatherTask, sizeof(CShfeFtdcRtnNetGatherTaskField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetGatherTask;

    uv_mutex_lock (&g_RtnNetGatherTaskTopic_mutex);
    g_RtnNetGatherTaskTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetGatherTaskTopic_mutex);

    uv_async_send(&g_RtnNetGatherTaskTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetGatherTaskTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetDeviceChgTopic(CShfeFtdcRspQryNetDeviceChgField* pRspQryNetDeviceChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetDeviceChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetDeviceChg) { 
        OutputCallbackMessage("pRspQryNetDeviceChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetDeviceChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetDeviceChg->DeviceID: ", pRspQryNetDeviceChg->DeviceID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceChg->SysNetSubAreaID: ", pRspQryNetDeviceChg->SysNetSubAreaID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceChg->OldObjectID: ", pRspQryNetDeviceChg->OldObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceChg->NewObjectID: ", pRspQryNetDeviceChg->NewObjectID, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetDeviceChgField* pNewRspQryNetDeviceChg = new CShfeFtdcRspQryNetDeviceChgField;
    memcpy (pNewRspQryNetDeviceChg, pRspQryNetDeviceChg, sizeof(CShfeFtdcRspQryNetDeviceChgField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetDeviceChg;

    uv_mutex_lock (&g_RspQryNetDeviceChgTopic_mutex);
    g_RspQryNetDeviceChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetDeviceChgTopic_mutex);

    uv_async_send(&g_RspQryNetDeviceChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetDeviceChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetDeviceChgTopic(CShfeFtdcRtnNetDeviceChgField* pRtnNetDeviceChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetDeviceChgTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetDeviceChg) { 
        OutputCallbackMessage("pRtnNetDeviceChg is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetDeviceChgTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetDeviceChg->DeviceID: ", pRtnNetDeviceChg->DeviceID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceChg->SysNetSubAreaID: ", pRtnNetDeviceChg->SysNetSubAreaID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceChg->OldObjectID: ", pRtnNetDeviceChg->OldObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceChg->NewObjectID: ", pRtnNetDeviceChg->NewObjectID, g_RunningResult_File);

    CShfeFtdcRtnNetDeviceChgField* pNewRtnNetDeviceChg = new CShfeFtdcRtnNetDeviceChgField;
    memcpy (pNewRtnNetDeviceChg, pRtnNetDeviceChg, sizeof(CShfeFtdcRtnNetDeviceChgField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetDeviceChg;

    uv_mutex_lock (&g_RtnNetDeviceChgTopic_mutex);
    g_RtnNetDeviceChgTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetDeviceChgTopic_mutex);

    uv_async_send(&g_RtnNetDeviceChgTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetDeviceChgTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetDeviceTypeTopic(CShfeFtdcRspQryNetDeviceTypeField* pRspQryNetDeviceType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetDeviceTypeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetDeviceType) { 
        OutputCallbackMessage("pRspQryNetDeviceType is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetDeviceTypeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetDeviceType->OperationType: ", pRspQryNetDeviceType->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceType->ID: ", pRspQryNetDeviceType->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceType->Manufactory: ", pRspQryNetDeviceType->Manufactory, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceType->DeviceType: ", pRspQryNetDeviceType->DeviceType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetDeviceTypeField* pNewRspQryNetDeviceType = new CShfeFtdcRspQryNetDeviceTypeField;
    memcpy (pNewRspQryNetDeviceType, pRspQryNetDeviceType, sizeof(CShfeFtdcRspQryNetDeviceTypeField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetDeviceType;

    uv_mutex_lock (&g_RspQryNetDeviceTypeTopic_mutex);
    g_RspQryNetDeviceTypeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetDeviceTypeTopic_mutex);

    uv_async_send(&g_RspQryNetDeviceTypeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetDeviceTypeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetDeviceTypeTopic(CShfeFtdcRtnNetDeviceTypeField* pRtnNetDeviceType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetDeviceTypeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetDeviceType) { 
        OutputCallbackMessage("pRtnNetDeviceType is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetDeviceTypeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetDeviceType->OperationType: ", pRtnNetDeviceType->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceType->ID: ", pRtnNetDeviceType->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceType->Manufactory: ", pRtnNetDeviceType->Manufactory, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceType->DeviceType: ", pRtnNetDeviceType->DeviceType, g_RunningResult_File);

    CShfeFtdcRtnNetDeviceTypeField* pNewRtnNetDeviceType = new CShfeFtdcRtnNetDeviceTypeField;
    memcpy (pNewRtnNetDeviceType, pRtnNetDeviceType, sizeof(CShfeFtdcRtnNetDeviceTypeField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetDeviceType;

    uv_mutex_lock (&g_RtnNetDeviceTypeTopic_mutex);
    g_RtnNetDeviceTypeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetDeviceTypeTopic_mutex);

    uv_async_send(&g_RtnNetDeviceTypeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetDeviceTypeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetDeviceCategoryTopic(CShfeFtdcRspQryNetDeviceCategoryField* pRspQryNetDeviceCategory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetDeviceCategoryTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetDeviceCategory) { 
        OutputCallbackMessage("pRspQryNetDeviceCategory is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetDeviceCategoryTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetDeviceCategory->OperationType: ", pRspQryNetDeviceCategory->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceCategory->ID: ", pRspQryNetDeviceCategory->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceCategory->CName: ", pRspQryNetDeviceCategory->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDeviceCategory->EName: ", pRspQryNetDeviceCategory->EName, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetDeviceCategoryField* pNewRspQryNetDeviceCategory = new CShfeFtdcRspQryNetDeviceCategoryField;
    memcpy (pNewRspQryNetDeviceCategory, pRspQryNetDeviceCategory, sizeof(CShfeFtdcRspQryNetDeviceCategoryField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetDeviceCategory;

    uv_mutex_lock (&g_RspQryNetDeviceCategoryTopic_mutex);
    g_RspQryNetDeviceCategoryTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetDeviceCategoryTopic_mutex);

    uv_async_send(&g_RspQryNetDeviceCategoryTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetDeviceCategoryTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetDeviceCategoryTopic(CShfeFtdcRtnNetDeviceCategoryField* pRtnNetDeviceCategory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetDeviceCategoryTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetDeviceCategory) { 
        OutputCallbackMessage("pRtnNetDeviceCategory is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetDeviceCategoryTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetDeviceCategory->OperationType: ", pRtnNetDeviceCategory->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceCategory->ID: ", pRtnNetDeviceCategory->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceCategory->CName: ", pRtnNetDeviceCategory->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDeviceCategory->EName: ", pRtnNetDeviceCategory->EName, g_RunningResult_File);

    CShfeFtdcRtnNetDeviceCategoryField* pNewRtnNetDeviceCategory = new CShfeFtdcRtnNetDeviceCategoryField;
    memcpy (pNewRtnNetDeviceCategory, pRtnNetDeviceCategory, sizeof(CShfeFtdcRtnNetDeviceCategoryField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetDeviceCategory;

    uv_mutex_lock (&g_RtnNetDeviceCategoryTopic_mutex);
    g_RtnNetDeviceCategoryTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetDeviceCategoryTopic_mutex);

    uv_async_send(&g_RtnNetDeviceCategoryTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetDeviceCategoryTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetManufactoryTopic(CShfeFtdcRspQryNetManufactoryField* pRspQryNetManufactory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetManufactoryTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetManufactory) { 
        OutputCallbackMessage("pRspQryNetManufactory is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetManufactoryTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetManufactory->OperationType: ", pRspQryNetManufactory->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetManufactory->ID: ", pRspQryNetManufactory->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetManufactory->CName: ", pRspQryNetManufactory->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetManufactory->EName: ", pRspQryNetManufactory->EName, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetManufactoryField* pNewRspQryNetManufactory = new CShfeFtdcRspQryNetManufactoryField;
    memcpy (pNewRspQryNetManufactory, pRspQryNetManufactory, sizeof(CShfeFtdcRspQryNetManufactoryField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetManufactory;

    uv_mutex_lock (&g_RspQryNetManufactoryTopic_mutex);
    g_RspQryNetManufactoryTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetManufactoryTopic_mutex);

    uv_async_send(&g_RspQryNetManufactoryTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetManufactoryTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetManufactoryTopic(CShfeFtdcRtnNetManufactoryField* pRtnNetManufactory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetManufactoryTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetManufactory) { 
        OutputCallbackMessage("pRtnNetManufactory is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetManufactoryTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetManufactory->OperationType: ", pRtnNetManufactory->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetManufactory->ID: ", pRtnNetManufactory->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetManufactory->CName: ", pRtnNetManufactory->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetManufactory->EName: ", pRtnNetManufactory->EName, g_RunningResult_File);

    CShfeFtdcRtnNetManufactoryField* pNewRtnNetManufactory = new CShfeFtdcRtnNetManufactoryField;
    memcpy (pNewRtnNetManufactory, pRtnNetManufactory, sizeof(CShfeFtdcRtnNetManufactoryField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetManufactory;

    uv_mutex_lock (&g_RtnNetManufactoryTopic_mutex);
    g_RtnNetManufactoryTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetManufactoryTopic_mutex);

    uv_async_send(&g_RtnNetManufactoryTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetManufactoryTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetCommunityTopic(CShfeFtdcRspQryNetCommunityField* pRspQryNetCommunity, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetCommunityTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetCommunity) { 
        OutputCallbackMessage("pRspQryNetCommunity is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetCommunityTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetCommunity->OperationType: ", pRspQryNetCommunity->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetCommunity->ID: ", pRspQryNetCommunity->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetCommunity->IPADDR: ", pRspQryNetCommunity->IPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetCommunity->COMMUNITY: ", pRspQryNetCommunity->COMMUNITY, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetCommunityField* pNewRspQryNetCommunity = new CShfeFtdcRspQryNetCommunityField;
    memcpy (pNewRspQryNetCommunity, pRspQryNetCommunity, sizeof(CShfeFtdcRspQryNetCommunityField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetCommunity;

    uv_mutex_lock (&g_RspQryNetCommunityTopic_mutex);
    g_RspQryNetCommunityTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetCommunityTopic_mutex);

    uv_async_send(&g_RspQryNetCommunityTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetCommunityTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetCommunityTopic(CShfeFtdcRtnNetCommunityField* pRtnNetCommunity, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetCommunityTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetCommunity) { 
        OutputCallbackMessage("pRtnNetCommunity is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetCommunityTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetCommunity->OperationType: ", pRtnNetCommunity->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetCommunity->ID: ", pRtnNetCommunity->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetCommunity->IPADDR: ", pRtnNetCommunity->IPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetCommunity->COMMUNITY: ", pRtnNetCommunity->COMMUNITY, g_RunningResult_File);

    CShfeFtdcRtnNetCommunityField* pNewRtnNetCommunity = new CShfeFtdcRtnNetCommunityField;
    memcpy (pNewRtnNetCommunity, pRtnNetCommunity, sizeof(CShfeFtdcRtnNetCommunityField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetCommunity;

    uv_mutex_lock (&g_RtnNetCommunityTopic_mutex);
    g_RtnNetCommunityTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetCommunityTopic_mutex);

    uv_async_send(&g_RtnNetCommunityTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetCommunityTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetPortTypeTopic(CShfeFtdcRspQryNetPortTypeField* pRspQryNetPortType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetPortTypeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetPortType) { 
        OutputCallbackMessage("pRspQryNetPortType is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetPortTypeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetPortType->OperationType: ", pRspQryNetPortType->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPortType->ID: ", pRspQryNetPortType->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPortType->CName: ", pRspQryNetPortType->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPortType->EName: ", pRspQryNetPortType->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPortType->Description: ", pRspQryNetPortType->Description, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetPortTypeField* pNewRspQryNetPortType = new CShfeFtdcRspQryNetPortTypeField;
    memcpy (pNewRspQryNetPortType, pRspQryNetPortType, sizeof(CShfeFtdcRspQryNetPortTypeField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetPortType;

    uv_mutex_lock (&g_RspQryNetPortTypeTopic_mutex);
    g_RspQryNetPortTypeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetPortTypeTopic_mutex);

    uv_async_send(&g_RspQryNetPortTypeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetPortTypeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetPortTypeTopic(CShfeFtdcRtnNetPortTypeField* pRtnNetPortType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetPortTypeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetPortType) { 
        OutputCallbackMessage("pRtnNetPortType is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetPortTypeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetPortType->OperationType: ", pRtnNetPortType->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPortType->ID: ", pRtnNetPortType->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPortType->CName: ", pRtnNetPortType->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPortType->EName: ", pRtnNetPortType->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPortType->Description: ", pRtnNetPortType->Description, g_RunningResult_File);

    CShfeFtdcRtnNetPortTypeField* pNewRtnNetPortType = new CShfeFtdcRtnNetPortTypeField;
    memcpy (pNewRtnNetPortType, pRtnNetPortType, sizeof(CShfeFtdcRtnNetPortTypeField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetPortType;

    uv_mutex_lock (&g_RtnNetPortTypeTopic_mutex);
    g_RtnNetPortTypeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetPortTypeTopic_mutex);

    uv_async_send(&g_RtnNetPortTypeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetPortTypeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetPartAccessSpotTopic(CShfeFtdcRspQryNetPartAccessSpotField* pRspQryNetPartAccessSpot, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetPartAccessSpotTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetPartAccessSpot) { 
        OutputCallbackMessage("pRspQryNetPartAccessSpot is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetPartAccessSpotTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetPartAccessSpot->OperationType: ", pRspQryNetPartAccessSpot->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartAccessSpot->ID: ", pRspQryNetPartAccessSpot->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartAccessSpot->CName: ", pRspQryNetPartAccessSpot->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartAccessSpot->EName: ", pRspQryNetPartAccessSpot->EName, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetPartAccessSpotField* pNewRspQryNetPartAccessSpot = new CShfeFtdcRspQryNetPartAccessSpotField;
    memcpy (pNewRspQryNetPartAccessSpot, pRspQryNetPartAccessSpot, sizeof(CShfeFtdcRspQryNetPartAccessSpotField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetPartAccessSpot;

    uv_mutex_lock (&g_RspQryNetPartAccessSpotTopic_mutex);
    g_RspQryNetPartAccessSpotTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetPartAccessSpotTopic_mutex);

    uv_async_send(&g_RspQryNetPartAccessSpotTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetPartAccessSpotTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetPartAccessSpotTopic(CShfeFtdcRtnNetPartAccessSpotField* pRtnNetPartAccessSpot, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetPartAccessSpotTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetPartAccessSpot) { 
        OutputCallbackMessage("pRtnNetPartAccessSpot is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetPartAccessSpotTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetPartAccessSpot->OperationType: ", pRtnNetPartAccessSpot->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartAccessSpot->ID: ", pRtnNetPartAccessSpot->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartAccessSpot->CName: ", pRtnNetPartAccessSpot->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartAccessSpot->EName: ", pRtnNetPartAccessSpot->EName, g_RunningResult_File);

    CShfeFtdcRtnNetPartAccessSpotField* pNewRtnNetPartAccessSpot = new CShfeFtdcRtnNetPartAccessSpotField;
    memcpy (pNewRtnNetPartAccessSpot, pRtnNetPartAccessSpot, sizeof(CShfeFtdcRtnNetPartAccessSpotField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetPartAccessSpot;

    uv_mutex_lock (&g_RtnNetPartAccessSpotTopic_mutex);
    g_RtnNetPartAccessSpotTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetPartAccessSpotTopic_mutex);

    uv_async_send(&g_RtnNetPartAccessSpotTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetPartAccessSpotTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetInterfaceTopic(CShfeFtdcRspQryNetInterfaceField* pRspQryNetInterface, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetInterfaceTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetInterface) { 
        OutputCallbackMessage("pRspQryNetInterface is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetInterfaceTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetInterface->OperationType: ", pRspQryNetInterface->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetInterface->ID: ", pRspQryNetInterface->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetInterface->ObjectID: ", pRspQryNetInterface->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetInterface->MonitorType_ID: ", pRspQryNetInterface->MonitorType_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetInterface->IfType: ", pRspQryNetInterface->IfType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetInterface->EName: ", pRspQryNetInterface->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetInterface->IpAddress: ", pRspQryNetInterface->IpAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetInterface->IpMask: ", pRspQryNetInterface->IpMask, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetInterface->IfStatus: ", pRspQryNetInterface->IfStatus, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetInterface->MAC: ", pRspQryNetInterface->MAC, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetInterface->DeviceID: ", pRspQryNetInterface->DeviceID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetInterface->DeviceObjectID: ", pRspQryNetInterface->DeviceObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetInterface->DeviceIndex: ", pRspQryNetInterface->DeviceIndex, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetInterface->isPolling: ", pRspQryNetInterface->isPolling, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetInterface->Description: ", pRspQryNetInterface->Description, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetInterfaceField* pNewRspQryNetInterface = new CShfeFtdcRspQryNetInterfaceField;
    memcpy (pNewRspQryNetInterface, pRspQryNetInterface, sizeof(CShfeFtdcRspQryNetInterfaceField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetInterface;

    uv_mutex_lock (&g_RspQryNetInterfaceTopic_mutex);
    g_RspQryNetInterfaceTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetInterfaceTopic_mutex);

    uv_async_send(&g_RspQryNetInterfaceTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetInterfaceTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetInterfaceTopic(CShfeFtdcRtnNetInterfaceField* pRtnNetInterface, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetInterfaceTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetInterface) { 
        OutputCallbackMessage("pRtnNetInterface is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetInterfaceTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetInterface->OperationType: ", pRtnNetInterface->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetInterface->ID: ", pRtnNetInterface->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetInterface->ObjectID: ", pRtnNetInterface->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetInterface->MonitorType_ID: ", pRtnNetInterface->MonitorType_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetInterface->IfType: ", pRtnNetInterface->IfType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetInterface->EName: ", pRtnNetInterface->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetInterface->IpAddress: ", pRtnNetInterface->IpAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetInterface->IpMask: ", pRtnNetInterface->IpMask, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetInterface->IfStatus: ", pRtnNetInterface->IfStatus, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetInterface->MAC: ", pRtnNetInterface->MAC, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetInterface->DeviceID: ", pRtnNetInterface->DeviceID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetInterface->DeviceObjectID: ", pRtnNetInterface->DeviceObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetInterface->DeviceIndex: ", pRtnNetInterface->DeviceIndex, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetInterface->isPolling: ", pRtnNetInterface->isPolling, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetInterface->Description: ", pRtnNetInterface->Description, g_RunningResult_File);

    CShfeFtdcRtnNetInterfaceField* pNewRtnNetInterface = new CShfeFtdcRtnNetInterfaceField;
    memcpy (pNewRtnNetInterface, pRtnNetInterface, sizeof(CShfeFtdcRtnNetInterfaceField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetInterface;

    uv_mutex_lock (&g_RtnNetInterfaceTopic_mutex);
    g_RtnNetInterfaceTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetInterfaceTopic_mutex);

    uv_async_send(&g_RtnNetInterfaceTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetInterfaceTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetGeneralOIDTopic(CShfeFtdcRspQryNetGeneralOIDField* pRspQryNetGeneralOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetGeneralOIDTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetGeneralOID) { 
        OutputCallbackMessage("pRspQryNetGeneralOID is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetGeneralOIDTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetGeneralOID->OperationType: ", pRspQryNetGeneralOID->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetGeneralOID->ID: ", pRspQryNetGeneralOID->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetGeneralOID->CName: ", pRspQryNetGeneralOID->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetGeneralOID->EName: ", pRspQryNetGeneralOID->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetGeneralOID->OID: ", pRspQryNetGeneralOID->OID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetGeneralOID->Unit: ", pRspQryNetGeneralOID->Unit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetGeneralOID->isTheTable: ", pRspQryNetGeneralOID->isTheTable, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetGeneralOIDField* pNewRspQryNetGeneralOID = new CShfeFtdcRspQryNetGeneralOIDField;
    memcpy (pNewRspQryNetGeneralOID, pRspQryNetGeneralOID, sizeof(CShfeFtdcRspQryNetGeneralOIDField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetGeneralOID;

    uv_mutex_lock (&g_RspQryNetGeneralOIDTopic_mutex);
    g_RspQryNetGeneralOIDTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetGeneralOIDTopic_mutex);

    uv_async_send(&g_RspQryNetGeneralOIDTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetGeneralOIDTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetGeneralOIDTopic(CShfeFtdcRtnNetGeneralOIDField* pRtnNetGeneralOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetGeneralOIDTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetGeneralOID) { 
        OutputCallbackMessage("pRtnNetGeneralOID is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetGeneralOIDTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetGeneralOID->OperationType: ", pRtnNetGeneralOID->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetGeneralOID->ID: ", pRtnNetGeneralOID->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetGeneralOID->CName: ", pRtnNetGeneralOID->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetGeneralOID->EName: ", pRtnNetGeneralOID->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetGeneralOID->OID: ", pRtnNetGeneralOID->OID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetGeneralOID->Unit: ", pRtnNetGeneralOID->Unit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetGeneralOID->isTheTable: ", pRtnNetGeneralOID->isTheTable, g_RunningResult_File);

    CShfeFtdcRtnNetGeneralOIDField* pNewRtnNetGeneralOID = new CShfeFtdcRtnNetGeneralOIDField;
    memcpy (pNewRtnNetGeneralOID, pRtnNetGeneralOID, sizeof(CShfeFtdcRtnNetGeneralOIDField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetGeneralOID;

    uv_mutex_lock (&g_RtnNetGeneralOIDTopic_mutex);
    g_RtnNetGeneralOIDTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetGeneralOIDTopic_mutex);

    uv_async_send(&g_RtnNetGeneralOIDTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetGeneralOIDTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetMonitorTypeTopic(CShfeFtdcRspQryNetMonitorTypeField* pRspQryNetMonitorType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetMonitorTypeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetMonitorType) { 
        OutputCallbackMessage("pRspQryNetMonitorType is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorTypeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetMonitorType->OperationType: ", pRspQryNetMonitorType->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorType->ID: ", pRspQryNetMonitorType->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorType->CName: ", pRspQryNetMonitorType->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorType->EName: ", pRspQryNetMonitorType->EName, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetMonitorTypeField* pNewRspQryNetMonitorType = new CShfeFtdcRspQryNetMonitorTypeField;
    memcpy (pNewRspQryNetMonitorType, pRspQryNetMonitorType, sizeof(CShfeFtdcRspQryNetMonitorTypeField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetMonitorType;

    uv_mutex_lock (&g_RspQryNetMonitorTypeTopic_mutex);
    g_RspQryNetMonitorTypeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetMonitorTypeTopic_mutex);

    uv_async_send(&g_RspQryNetMonitorTypeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorTypeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetMonitorTypeTopic(CShfeFtdcRtnNetMonitorTypeField* pRtnNetMonitorType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetMonitorTypeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetMonitorType) { 
        OutputCallbackMessage("pRtnNetMonitorType is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorTypeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetMonitorType->OperationType: ", pRtnNetMonitorType->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorType->ID: ", pRtnNetMonitorType->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorType->CName: ", pRtnNetMonitorType->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorType->EName: ", pRtnNetMonitorType->EName, g_RunningResult_File);

    CShfeFtdcRtnNetMonitorTypeField* pNewRtnNetMonitorType = new CShfeFtdcRtnNetMonitorTypeField;
    memcpy (pNewRtnNetMonitorType, pRtnNetMonitorType, sizeof(CShfeFtdcRtnNetMonitorTypeField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetMonitorType;

    uv_mutex_lock (&g_RtnNetMonitorTypeTopic_mutex);
    g_RtnNetMonitorTypeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetMonitorTypeTopic_mutex);

    uv_async_send(&g_RtnNetMonitorTypeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorTypeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetMonitorAttrScopeTopic(CShfeFtdcRspQryNetMonitorAttrScopeField* pRspQryNetMonitorAttrScope, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetMonitorAttrScopeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetMonitorAttrScope) { 
        OutputCallbackMessage("pRspQryNetMonitorAttrScope is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorAttrScopeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetMonitorAttrScope->OperationType: ", pRspQryNetMonitorAttrScope->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorAttrScope->ID: ", pRspQryNetMonitorAttrScope->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorAttrScope->CName: ", pRspQryNetMonitorAttrScope->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorAttrScope->EName: ", pRspQryNetMonitorAttrScope->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorAttrScope->Comments: ", pRspQryNetMonitorAttrScope->Comments, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetMonitorAttrScopeField* pNewRspQryNetMonitorAttrScope = new CShfeFtdcRspQryNetMonitorAttrScopeField;
    memcpy (pNewRspQryNetMonitorAttrScope, pRspQryNetMonitorAttrScope, sizeof(CShfeFtdcRspQryNetMonitorAttrScopeField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetMonitorAttrScope;

    uv_mutex_lock (&g_RspQryNetMonitorAttrScopeTopic_mutex);
    g_RspQryNetMonitorAttrScopeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetMonitorAttrScopeTopic_mutex);

    uv_async_send(&g_RspQryNetMonitorAttrScopeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorAttrScopeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetMonitorAttrScopeTopic(CShfeFtdcRtnNetMonitorAttrScopeField* pRtnNetMonitorAttrScope, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetMonitorAttrScopeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetMonitorAttrScope) { 
        OutputCallbackMessage("pRtnNetMonitorAttrScope is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorAttrScopeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetMonitorAttrScope->OperationType: ", pRtnNetMonitorAttrScope->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorAttrScope->ID: ", pRtnNetMonitorAttrScope->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorAttrScope->CName: ", pRtnNetMonitorAttrScope->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorAttrScope->EName: ", pRtnNetMonitorAttrScope->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorAttrScope->Comments: ", pRtnNetMonitorAttrScope->Comments, g_RunningResult_File);

    CShfeFtdcRtnNetMonitorAttrScopeField* pNewRtnNetMonitorAttrScope = new CShfeFtdcRtnNetMonitorAttrScopeField;
    memcpy (pNewRtnNetMonitorAttrScope, pRtnNetMonitorAttrScope, sizeof(CShfeFtdcRtnNetMonitorAttrScopeField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetMonitorAttrScope;

    uv_mutex_lock (&g_RtnNetMonitorAttrScopeTopic_mutex);
    g_RtnNetMonitorAttrScopeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetMonitorAttrScopeTopic_mutex);

    uv_async_send(&g_RtnNetMonitorAttrScopeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorAttrScopeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetMonitorAttrTypeTopic(CShfeFtdcRspQryNetMonitorAttrTypeField* pRspQryNetMonitorAttrType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetMonitorAttrTypeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetMonitorAttrType) { 
        OutputCallbackMessage("pRspQryNetMonitorAttrType is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorAttrTypeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetMonitorAttrType->OperationType: ", pRspQryNetMonitorAttrType->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorAttrType->ID: ", pRspQryNetMonitorAttrType->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorAttrType->MANUFACTORY_ID: ", pRspQryNetMonitorAttrType->MANUFACTORY_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorAttrType->MonitorType_ID: ", pRspQryNetMonitorAttrType->MonitorType_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorAttrType->AttrType_ID: ", pRspQryNetMonitorAttrType->AttrType_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorAttrType->MANUFACTORY: ", pRspQryNetMonitorAttrType->MANUFACTORY, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorAttrType->MonitorType: ", pRspQryNetMonitorAttrType->MonitorType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorAttrType->AttrType: ", pRspQryNetMonitorAttrType->AttrType, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetMonitorAttrTypeField* pNewRspQryNetMonitorAttrType = new CShfeFtdcRspQryNetMonitorAttrTypeField;
    memcpy (pNewRspQryNetMonitorAttrType, pRspQryNetMonitorAttrType, sizeof(CShfeFtdcRspQryNetMonitorAttrTypeField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetMonitorAttrType;

    uv_mutex_lock (&g_RspQryNetMonitorAttrTypeTopic_mutex);
    g_RspQryNetMonitorAttrTypeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetMonitorAttrTypeTopic_mutex);

    uv_async_send(&g_RspQryNetMonitorAttrTypeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorAttrTypeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetMonitorAttrTypeTopic(CShfeFtdcRtnNetMonitorAttrTypeField* pRtnNetMonitorAttrType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetMonitorAttrTypeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetMonitorAttrType) { 
        OutputCallbackMessage("pRtnNetMonitorAttrType is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorAttrTypeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetMonitorAttrType->OperationType: ", pRtnNetMonitorAttrType->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorAttrType->ID: ", pRtnNetMonitorAttrType->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorAttrType->MANUFACTORY_ID: ", pRtnNetMonitorAttrType->MANUFACTORY_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorAttrType->MonitorType_ID: ", pRtnNetMonitorAttrType->MonitorType_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorAttrType->AttrType_ID: ", pRtnNetMonitorAttrType->AttrType_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorAttrType->MANUFACTORY: ", pRtnNetMonitorAttrType->MANUFACTORY, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorAttrType->MonitorType: ", pRtnNetMonitorAttrType->MonitorType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorAttrType->AttrType: ", pRtnNetMonitorAttrType->AttrType, g_RunningResult_File);

    CShfeFtdcRtnNetMonitorAttrTypeField* pNewRtnNetMonitorAttrType = new CShfeFtdcRtnNetMonitorAttrTypeField;
    memcpy (pNewRtnNetMonitorAttrType, pRtnNetMonitorAttrType, sizeof(CShfeFtdcRtnNetMonitorAttrTypeField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetMonitorAttrType;

    uv_mutex_lock (&g_RtnNetMonitorAttrTypeTopic_mutex);
    g_RtnNetMonitorAttrTypeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetMonitorAttrTypeTopic_mutex);

    uv_async_send(&g_RtnNetMonitorAttrTypeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorAttrTypeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetMonitorObjectAttrTopic(CShfeFtdcRspQryNetMonitorObjectAttrField* pRspQryNetMonitorObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetMonitorObjectAttrTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetMonitorObjectAttr) { 
        OutputCallbackMessage("pRspQryNetMonitorObjectAttr is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorObjectAttrTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetMonitorObjectAttr->OperationType: ", pRspQryNetMonitorObjectAttr->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorObjectAttr->ID: ", pRspQryNetMonitorObjectAttr->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorObjectAttr->ObjectID: ", pRspQryNetMonitorObjectAttr->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorObjectAttr->AttrType: ", pRspQryNetMonitorObjectAttr->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorObjectAttr->PolicyTypeID: ", pRspQryNetMonitorObjectAttr->PolicyTypeID, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetMonitorObjectAttrField* pNewRspQryNetMonitorObjectAttr = new CShfeFtdcRspQryNetMonitorObjectAttrField;
    memcpy (pNewRspQryNetMonitorObjectAttr, pRspQryNetMonitorObjectAttr, sizeof(CShfeFtdcRspQryNetMonitorObjectAttrField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetMonitorObjectAttr;

    uv_mutex_lock (&g_RspQryNetMonitorObjectAttrTopic_mutex);
    g_RspQryNetMonitorObjectAttrTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetMonitorObjectAttrTopic_mutex);

    uv_async_send(&g_RspQryNetMonitorObjectAttrTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorObjectAttrTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetMonitorObjectAttrTopic(CShfeFtdcRtnNetMonitorObjectAttrField* pRtnNetMonitorObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetMonitorObjectAttrTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetMonitorObjectAttr) { 
        OutputCallbackMessage("pRtnNetMonitorObjectAttr is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorObjectAttrTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetMonitorObjectAttr->OperationType: ", pRtnNetMonitorObjectAttr->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorObjectAttr->ID: ", pRtnNetMonitorObjectAttr->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorObjectAttr->ObjectID: ", pRtnNetMonitorObjectAttr->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorObjectAttr->AttrType: ", pRtnNetMonitorObjectAttr->AttrType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorObjectAttr->PolicyTypeID: ", pRtnNetMonitorObjectAttr->PolicyTypeID, g_RunningResult_File);

    CShfeFtdcRtnNetMonitorObjectAttrField* pNewRtnNetMonitorObjectAttr = new CShfeFtdcRtnNetMonitorObjectAttrField;
    memcpy (pNewRtnNetMonitorObjectAttr, pRtnNetMonitorObjectAttr, sizeof(CShfeFtdcRtnNetMonitorObjectAttrField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetMonitorObjectAttr;

    uv_mutex_lock (&g_RtnNetMonitorObjectAttrTopic_mutex);
    g_RtnNetMonitorObjectAttrTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetMonitorObjectAttrTopic_mutex);

    uv_async_send(&g_RtnNetMonitorObjectAttrTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorObjectAttrTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetFuncAreaTopic(CShfeFtdcRspQryNetFuncAreaField* pRspQryNetFuncArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetFuncAreaTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetFuncArea) { 
        OutputCallbackMessage("pRspQryNetFuncArea is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetFuncAreaTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetFuncArea->OperationType: ", pRspQryNetFuncArea->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetFuncArea->ID: ", pRspQryNetFuncArea->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetFuncArea->SysNetSubAreaID: ", pRspQryNetFuncArea->SysNetSubAreaID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetFuncArea->CName: ", pRspQryNetFuncArea->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetFuncArea->EName: ", pRspQryNetFuncArea->EName, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetFuncAreaField* pNewRspQryNetFuncArea = new CShfeFtdcRspQryNetFuncAreaField;
    memcpy (pNewRspQryNetFuncArea, pRspQryNetFuncArea, sizeof(CShfeFtdcRspQryNetFuncAreaField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetFuncArea;

    uv_mutex_lock (&g_RspQryNetFuncAreaTopic_mutex);
    g_RspQryNetFuncAreaTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetFuncAreaTopic_mutex);

    uv_async_send(&g_RspQryNetFuncAreaTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetFuncAreaTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetFuncAreaTopic(CShfeFtdcRtnNetFuncAreaField* pRtnNetFuncArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetFuncAreaTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetFuncArea) { 
        OutputCallbackMessage("pRtnNetFuncArea is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetFuncAreaTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetFuncArea->OperationType: ", pRtnNetFuncArea->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetFuncArea->ID: ", pRtnNetFuncArea->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetFuncArea->SysNetSubAreaID: ", pRtnNetFuncArea->SysNetSubAreaID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetFuncArea->CName: ", pRtnNetFuncArea->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetFuncArea->EName: ", pRtnNetFuncArea->EName, g_RunningResult_File);

    CShfeFtdcRtnNetFuncAreaField* pNewRtnNetFuncArea = new CShfeFtdcRtnNetFuncAreaField;
    memcpy (pNewRtnNetFuncArea, pRtnNetFuncArea, sizeof(CShfeFtdcRtnNetFuncAreaField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetFuncArea;

    uv_mutex_lock (&g_RtnNetFuncAreaTopic_mutex);
    g_RtnNetFuncAreaTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetFuncAreaTopic_mutex);

    uv_async_send(&g_RtnNetFuncAreaTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetFuncAreaTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetMonitorCommandTypeTopic(CShfeFtdcRspQryNetMonitorCommandTypeField* pRspQryNetMonitorCommandType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetMonitorCommandTypeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetMonitorCommandType) { 
        OutputCallbackMessage("pRspQryNetMonitorCommandType is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorCommandTypeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetMonitorCommandType->OperationType: ", pRspQryNetMonitorCommandType->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorCommandType->ID: ", pRspQryNetMonitorCommandType->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorCommandType->Manufactory_ID: ", pRspQryNetMonitorCommandType->Manufactory_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorCommandType->MonitorType_ID: ", pRspQryNetMonitorCommandType->MonitorType_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorCommandType->DeviceModle_ID: ", pRspQryNetMonitorCommandType->DeviceModle_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorCommandType->ActionGroup_ID: ", pRspQryNetMonitorCommandType->ActionGroup_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorCommandType->Manufactory: ", pRspQryNetMonitorCommandType->Manufactory, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorCommandType->MonitorType: ", pRspQryNetMonitorCommandType->MonitorType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorCommandType->DeviceModle: ", pRspQryNetMonitorCommandType->DeviceModle, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorCommandType->ActionGroup: ", pRspQryNetMonitorCommandType->ActionGroup, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorCommandType->Command: ", pRspQryNetMonitorCommandType->Command, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetMonitorCommandTypeField* pNewRspQryNetMonitorCommandType = new CShfeFtdcRspQryNetMonitorCommandTypeField;
    memcpy (pNewRspQryNetMonitorCommandType, pRspQryNetMonitorCommandType, sizeof(CShfeFtdcRspQryNetMonitorCommandTypeField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetMonitorCommandType;

    uv_mutex_lock (&g_RspQryNetMonitorCommandTypeTopic_mutex);
    g_RspQryNetMonitorCommandTypeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetMonitorCommandTypeTopic_mutex);

    uv_async_send(&g_RspQryNetMonitorCommandTypeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorCommandTypeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetMonitorCommandTypeTopic(CShfeFtdcRtnNetMonitorCommandTypeField* pRtnNetMonitorCommandType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetMonitorCommandTypeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetMonitorCommandType) { 
        OutputCallbackMessage("pRtnNetMonitorCommandType is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorCommandTypeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetMonitorCommandType->OperationType: ", pRtnNetMonitorCommandType->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorCommandType->ID: ", pRtnNetMonitorCommandType->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorCommandType->Manufactory_ID: ", pRtnNetMonitorCommandType->Manufactory_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorCommandType->MonitorType_ID: ", pRtnNetMonitorCommandType->MonitorType_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorCommandType->DeviceModle_ID: ", pRtnNetMonitorCommandType->DeviceModle_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorCommandType->ActionGroup_ID: ", pRtnNetMonitorCommandType->ActionGroup_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorCommandType->Manufactory: ", pRtnNetMonitorCommandType->Manufactory, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorCommandType->MonitorType: ", pRtnNetMonitorCommandType->MonitorType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorCommandType->DeviceModle: ", pRtnNetMonitorCommandType->DeviceModle, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorCommandType->ActionGroup: ", pRtnNetMonitorCommandType->ActionGroup, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorCommandType->Command: ", pRtnNetMonitorCommandType->Command, g_RunningResult_File);

    CShfeFtdcRtnNetMonitorCommandTypeField* pNewRtnNetMonitorCommandType = new CShfeFtdcRtnNetMonitorCommandTypeField;
    memcpy (pNewRtnNetMonitorCommandType, pRtnNetMonitorCommandType, sizeof(CShfeFtdcRtnNetMonitorCommandTypeField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetMonitorCommandType;

    uv_mutex_lock (&g_RtnNetMonitorCommandTypeTopic_mutex);
    g_RtnNetMonitorCommandTypeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetMonitorCommandTypeTopic_mutex);

    uv_async_send(&g_RtnNetMonitorCommandTypeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorCommandTypeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetMonitorActionGroupTopic(CShfeFtdcRspQryNetMonitorActionGroupField* pRspQryNetMonitorActionGroup, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetMonitorActionGroupTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetMonitorActionGroup) { 
        OutputCallbackMessage("pRspQryNetMonitorActionGroup is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorActionGroupTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetMonitorActionGroup->OperationType: ", pRspQryNetMonitorActionGroup->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorActionGroup->ID: ", pRspQryNetMonitorActionGroup->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorActionGroup->CName: ", pRspQryNetMonitorActionGroup->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorActionGroup->EName: ", pRspQryNetMonitorActionGroup->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorActionGroup->ActionType: ", pRspQryNetMonitorActionGroup->ActionType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorActionGroup->Comments: ", pRspQryNetMonitorActionGroup->Comments, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetMonitorActionGroupField* pNewRspQryNetMonitorActionGroup = new CShfeFtdcRspQryNetMonitorActionGroupField;
    memcpy (pNewRspQryNetMonitorActionGroup, pRspQryNetMonitorActionGroup, sizeof(CShfeFtdcRspQryNetMonitorActionGroupField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetMonitorActionGroup;

    uv_mutex_lock (&g_RspQryNetMonitorActionGroupTopic_mutex);
    g_RspQryNetMonitorActionGroupTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetMonitorActionGroupTopic_mutex);

    uv_async_send(&g_RspQryNetMonitorActionGroupTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorActionGroupTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetMonitorActionGroupTopic(CShfeFtdcRtnNetMonitorActionGroupField* pRtnNetMonitorActionGroup, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetMonitorActionGroupTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetMonitorActionGroup) { 
        OutputCallbackMessage("pRtnNetMonitorActionGroup is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorActionGroupTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetMonitorActionGroup->OperationType: ", pRtnNetMonitorActionGroup->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorActionGroup->ID: ", pRtnNetMonitorActionGroup->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorActionGroup->CName: ", pRtnNetMonitorActionGroup->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorActionGroup->EName: ", pRtnNetMonitorActionGroup->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorActionGroup->ActionType: ", pRtnNetMonitorActionGroup->ActionType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorActionGroup->Comments: ", pRtnNetMonitorActionGroup->Comments, g_RunningResult_File);

    CShfeFtdcRtnNetMonitorActionGroupField* pNewRtnNetMonitorActionGroup = new CShfeFtdcRtnNetMonitorActionGroupField;
    memcpy (pNewRtnNetMonitorActionGroup, pRtnNetMonitorActionGroup, sizeof(CShfeFtdcRtnNetMonitorActionGroupField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetMonitorActionGroup;

    uv_mutex_lock (&g_RtnNetMonitorActionGroupTopic_mutex);
    g_RtnNetMonitorActionGroupTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetMonitorActionGroupTopic_mutex);

    uv_async_send(&g_RtnNetMonitorActionGroupTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorActionGroupTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetMonitorDeviceGroupTopic(CShfeFtdcRspQryNetMonitorDeviceGroupField* pRspQryNetMonitorDeviceGroup, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetMonitorDeviceGroupTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetMonitorDeviceGroup) { 
        OutputCallbackMessage("pRspQryNetMonitorDeviceGroup is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorDeviceGroupTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetMonitorDeviceGroup->OperationType: ", pRspQryNetMonitorDeviceGroup->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorDeviceGroup->ID: ", pRspQryNetMonitorDeviceGroup->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorDeviceGroup->CName: ", pRspQryNetMonitorDeviceGroup->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorDeviceGroup->EName: ", pRspQryNetMonitorDeviceGroup->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorDeviceGroup->Condition: ", pRspQryNetMonitorDeviceGroup->Condition, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorDeviceGroup->Comments: ", pRspQryNetMonitorDeviceGroup->Comments, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetMonitorDeviceGroupField* pNewRspQryNetMonitorDeviceGroup = new CShfeFtdcRspQryNetMonitorDeviceGroupField;
    memcpy (pNewRspQryNetMonitorDeviceGroup, pRspQryNetMonitorDeviceGroup, sizeof(CShfeFtdcRspQryNetMonitorDeviceGroupField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetMonitorDeviceGroup;

    uv_mutex_lock (&g_RspQryNetMonitorDeviceGroupTopic_mutex);
    g_RspQryNetMonitorDeviceGroupTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetMonitorDeviceGroupTopic_mutex);

    uv_async_send(&g_RspQryNetMonitorDeviceGroupTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorDeviceGroupTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetMonitorDeviceGroupTopic(CShfeFtdcRtnNetMonitorDeviceGroupField* pRtnNetMonitorDeviceGroup, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetMonitorDeviceGroupTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetMonitorDeviceGroup) { 
        OutputCallbackMessage("pRtnNetMonitorDeviceGroup is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorDeviceGroupTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetMonitorDeviceGroup->OperationType: ", pRtnNetMonitorDeviceGroup->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorDeviceGroup->ID: ", pRtnNetMonitorDeviceGroup->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorDeviceGroup->CName: ", pRtnNetMonitorDeviceGroup->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorDeviceGroup->EName: ", pRtnNetMonitorDeviceGroup->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorDeviceGroup->Condition: ", pRtnNetMonitorDeviceGroup->Condition, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorDeviceGroup->Comments: ", pRtnNetMonitorDeviceGroup->Comments, g_RunningResult_File);

    CShfeFtdcRtnNetMonitorDeviceGroupField* pNewRtnNetMonitorDeviceGroup = new CShfeFtdcRtnNetMonitorDeviceGroupField;
    memcpy (pNewRtnNetMonitorDeviceGroup, pRtnNetMonitorDeviceGroup, sizeof(CShfeFtdcRtnNetMonitorDeviceGroupField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetMonitorDeviceGroup;

    uv_mutex_lock (&g_RtnNetMonitorDeviceGroupTopic_mutex);
    g_RtnNetMonitorDeviceGroupTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetMonitorDeviceGroupTopic_mutex);

    uv_async_send(&g_RtnNetMonitorDeviceGroupTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorDeviceGroupTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetMonitorTaskInfoTopic(CShfeFtdcRspQryNetMonitorTaskInfoField* pRspQryNetMonitorTaskInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetMonitorTaskInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetMonitorTaskInfo) { 
        OutputCallbackMessage("pRspQryNetMonitorTaskInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorTaskInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->OperationType: ", pRspQryNetMonitorTaskInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->ID: ", pRspQryNetMonitorTaskInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->CName: ", pRspQryNetMonitorTaskInfo->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->EName: ", pRspQryNetMonitorTaskInfo->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->DeviceGroup_ID: ", pRspQryNetMonitorTaskInfo->DeviceGroup_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->ManagerGroup_ID: ", pRspQryNetMonitorTaskInfo->ManagerGroup_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->TimePolicy_ID: ", pRspQryNetMonitorTaskInfo->TimePolicy_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->TaskPriority_ID: ", pRspQryNetMonitorTaskInfo->TaskPriority_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->OutputPolicy_ID: ", pRspQryNetMonitorTaskInfo->OutputPolicy_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->ActionGroup_ID: ", pRspQryNetMonitorTaskInfo->ActionGroup_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->EventExprStr: ", pRspQryNetMonitorTaskInfo->EventExprStr, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->DeviceGroup: ", pRspQryNetMonitorTaskInfo->DeviceGroup, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->ManagerGroup: ", pRspQryNetMonitorTaskInfo->ManagerGroup, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->TimePolicy: ", pRspQryNetMonitorTaskInfo->TimePolicy, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->TaskPriority: ", pRspQryNetMonitorTaskInfo->TaskPriority, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->OutputPolicy: ", pRspQryNetMonitorTaskInfo->OutputPolicy, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->ActionGroup: ", pRspQryNetMonitorTaskInfo->ActionGroup, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->ValidFlag: ", pRspQryNetMonitorTaskInfo->ValidFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->TaskStatus: ", pRspQryNetMonitorTaskInfo->TaskStatus, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInfo->Comments: ", pRspQryNetMonitorTaskInfo->Comments, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetMonitorTaskInfoField* pNewRspQryNetMonitorTaskInfo = new CShfeFtdcRspQryNetMonitorTaskInfoField;
    memcpy (pNewRspQryNetMonitorTaskInfo, pRspQryNetMonitorTaskInfo, sizeof(CShfeFtdcRspQryNetMonitorTaskInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetMonitorTaskInfo;

    uv_mutex_lock (&g_RspQryNetMonitorTaskInfoTopic_mutex);
    g_RspQryNetMonitorTaskInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetMonitorTaskInfoTopic_mutex);

    uv_async_send(&g_RspQryNetMonitorTaskInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorTaskInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetMonitorTaskInfoTopic(CShfeFtdcRtnNetMonitorTaskInfoField* pRtnNetMonitorTaskInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetMonitorTaskInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetMonitorTaskInfo) { 
        OutputCallbackMessage("pRtnNetMonitorTaskInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorTaskInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->OperationType: ", pRtnNetMonitorTaskInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->ID: ", pRtnNetMonitorTaskInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->CName: ", pRtnNetMonitorTaskInfo->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->EName: ", pRtnNetMonitorTaskInfo->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->DeviceGroup_ID: ", pRtnNetMonitorTaskInfo->DeviceGroup_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->ManagerGroup_ID: ", pRtnNetMonitorTaskInfo->ManagerGroup_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->TimePolicy_ID: ", pRtnNetMonitorTaskInfo->TimePolicy_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->TaskPriority_ID: ", pRtnNetMonitorTaskInfo->TaskPriority_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->OutputPolicy_ID: ", pRtnNetMonitorTaskInfo->OutputPolicy_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->ActionGroup_ID: ", pRtnNetMonitorTaskInfo->ActionGroup_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->EventExprStr: ", pRtnNetMonitorTaskInfo->EventExprStr, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->DeviceGroup: ", pRtnNetMonitorTaskInfo->DeviceGroup, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->ManagerGroup: ", pRtnNetMonitorTaskInfo->ManagerGroup, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->TimePolicy: ", pRtnNetMonitorTaskInfo->TimePolicy, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->TaskPriority: ", pRtnNetMonitorTaskInfo->TaskPriority, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->OutputPolicy: ", pRtnNetMonitorTaskInfo->OutputPolicy, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->ActionGroup: ", pRtnNetMonitorTaskInfo->ActionGroup, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->ValidFlag: ", pRtnNetMonitorTaskInfo->ValidFlag, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->TaskStatus: ", pRtnNetMonitorTaskInfo->TaskStatus, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInfo->Comments: ", pRtnNetMonitorTaskInfo->Comments, g_RunningResult_File);

    CShfeFtdcRtnNetMonitorTaskInfoField* pNewRtnNetMonitorTaskInfo = new CShfeFtdcRtnNetMonitorTaskInfoField;
    memcpy (pNewRtnNetMonitorTaskInfo, pRtnNetMonitorTaskInfo, sizeof(CShfeFtdcRtnNetMonitorTaskInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetMonitorTaskInfo;

    uv_mutex_lock (&g_RtnNetMonitorTaskInfoTopic_mutex);
    g_RtnNetMonitorTaskInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetMonitorTaskInfoTopic_mutex);

    uv_async_send(&g_RtnNetMonitorTaskInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorTaskInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetMonitorTaskResultTopic(CShfeFtdcRspQryNetMonitorTaskResultField* pRspQryNetMonitorTaskResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetMonitorTaskResultTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetMonitorTaskResult) { 
        OutputCallbackMessage("pRspQryNetMonitorTaskResult is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorTaskResultTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetMonitorTaskResult->OperationType: ", pRspQryNetMonitorTaskResult->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskResult->ObjectID: ", pRspQryNetMonitorTaskResult->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskResult->Task_ID: ", pRspQryNetMonitorTaskResult->Task_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskResult->OperateTime: ", pRspQryNetMonitorTaskResult->OperateTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskResult->MonDate: ", pRspQryNetMonitorTaskResult->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskResult->MonTime: ", pRspQryNetMonitorTaskResult->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskResult->InstructChain: ", pRspQryNetMonitorTaskResult->InstructChain, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskResult->ResultChain: ", pRspQryNetMonitorTaskResult->ResultChain, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskResult->Flag: ", pRspQryNetMonitorTaskResult->Flag, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetMonitorTaskResultField* pNewRspQryNetMonitorTaskResult = new CShfeFtdcRspQryNetMonitorTaskResultField;
    memcpy (pNewRspQryNetMonitorTaskResult, pRspQryNetMonitorTaskResult, sizeof(CShfeFtdcRspQryNetMonitorTaskResultField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetMonitorTaskResult;

    uv_mutex_lock (&g_RspQryNetMonitorTaskResultTopic_mutex);
    g_RspQryNetMonitorTaskResultTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetMonitorTaskResultTopic_mutex);

    uv_async_send(&g_RspQryNetMonitorTaskResultTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorTaskResultTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetMonitorTaskResultTopic(CShfeFtdcRtnNetMonitorTaskResultField* pRtnNetMonitorTaskResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetMonitorTaskResultTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetMonitorTaskResult) { 
        OutputCallbackMessage("pRtnNetMonitorTaskResult is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorTaskResultTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetMonitorTaskResult->OperationType: ", pRtnNetMonitorTaskResult->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskResult->ObjectID: ", pRtnNetMonitorTaskResult->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskResult->Task_ID: ", pRtnNetMonitorTaskResult->Task_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskResult->OperateTime: ", pRtnNetMonitorTaskResult->OperateTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskResult->MonDate: ", pRtnNetMonitorTaskResult->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskResult->MonTime: ", pRtnNetMonitorTaskResult->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskResult->InstructChain: ", pRtnNetMonitorTaskResult->InstructChain, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskResult->ResultChain: ", pRtnNetMonitorTaskResult->ResultChain, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskResult->Flag: ", pRtnNetMonitorTaskResult->Flag, g_RunningResult_File);

    CShfeFtdcRtnNetMonitorTaskResultField* pNewRtnNetMonitorTaskResult = new CShfeFtdcRtnNetMonitorTaskResultField;
    memcpy (pNewRtnNetMonitorTaskResult, pRtnNetMonitorTaskResult, sizeof(CShfeFtdcRtnNetMonitorTaskResultField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetMonitorTaskResult;

    uv_mutex_lock (&g_RtnNetMonitorTaskResultTopic_mutex);
    g_RtnNetMonitorTaskResultTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetMonitorTaskResultTopic_mutex);

    uv_async_send(&g_RtnNetMonitorTaskResultTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorTaskResultTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetMonitorTaskObjectSetTopic(CShfeFtdcRspQryNetMonitorTaskObjectSetField* pRspQryNetMonitorTaskObjectSet, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetMonitorTaskObjectSetTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetMonitorTaskObjectSet) { 
        OutputCallbackMessage("pRspQryNetMonitorTaskObjectSet is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorTaskObjectSetTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetMonitorTaskObjectSet->OperationType: ", pRspQryNetMonitorTaskObjectSet->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskObjectSet->ID: ", pRspQryNetMonitorTaskObjectSet->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskObjectSet->DeviceGroup_ID: ", pRspQryNetMonitorTaskObjectSet->DeviceGroup_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskObjectSet->Device_ID: ", pRspQryNetMonitorTaskObjectSet->Device_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskObjectSet->DataCenter: ", pRspQryNetMonitorTaskObjectSet->DataCenter, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetMonitorTaskObjectSetField* pNewRspQryNetMonitorTaskObjectSet = new CShfeFtdcRspQryNetMonitorTaskObjectSetField;
    memcpy (pNewRspQryNetMonitorTaskObjectSet, pRspQryNetMonitorTaskObjectSet, sizeof(CShfeFtdcRspQryNetMonitorTaskObjectSetField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetMonitorTaskObjectSet;

    uv_mutex_lock (&g_RspQryNetMonitorTaskObjectSetTopic_mutex);
    g_RspQryNetMonitorTaskObjectSetTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetMonitorTaskObjectSetTopic_mutex);

    uv_async_send(&g_RspQryNetMonitorTaskObjectSetTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorTaskObjectSetTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetMonitorTaskObjectSetTopic(CShfeFtdcRtnNetMonitorTaskObjectSetField* pRtnNetMonitorTaskObjectSet, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetMonitorTaskObjectSetTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetMonitorTaskObjectSet) { 
        OutputCallbackMessage("pRtnNetMonitorTaskObjectSet is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorTaskObjectSetTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetMonitorTaskObjectSet->OperationType: ", pRtnNetMonitorTaskObjectSet->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskObjectSet->ID: ", pRtnNetMonitorTaskObjectSet->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskObjectSet->DeviceGroup_ID: ", pRtnNetMonitorTaskObjectSet->DeviceGroup_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskObjectSet->Device_ID: ", pRtnNetMonitorTaskObjectSet->Device_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskObjectSet->DataCenter: ", pRtnNetMonitorTaskObjectSet->DataCenter, g_RunningResult_File);

    CShfeFtdcRtnNetMonitorTaskObjectSetField* pNewRtnNetMonitorTaskObjectSet = new CShfeFtdcRtnNetMonitorTaskObjectSetField;
    memcpy (pNewRtnNetMonitorTaskObjectSet, pRtnNetMonitorTaskObjectSet, sizeof(CShfeFtdcRtnNetMonitorTaskObjectSetField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetMonitorTaskObjectSet;

    uv_mutex_lock (&g_RtnNetMonitorTaskObjectSetTopic_mutex);
    g_RtnNetMonitorTaskObjectSetTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetMonitorTaskObjectSetTopic_mutex);

    uv_async_send(&g_RtnNetMonitorTaskObjectSetTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorTaskObjectSetTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetPartyLinkInfoTopic(CShfeFtdcRspQryNetPartyLinkInfoField* pRspQryNetPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetPartyLinkInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetPartyLinkInfo) { 
        OutputCallbackMessage("pRspQryNetPartyLinkInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetPartyLinkInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->OperationType: ", pRspQryNetPartyLinkInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->ID: ", pRspQryNetPartyLinkInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->MEMBER_NO: ", pRspQryNetPartyLinkInfo->MEMBER_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->MEMBER_NAME: ", pRspQryNetPartyLinkInfo->MEMBER_NAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->REMOTE_ADDR: ", pRspQryNetPartyLinkInfo->REMOTE_ADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->LOCAL_ADDR: ", pRspQryNetPartyLinkInfo->LOCAL_ADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->ADDRESS: ", pRspQryNetPartyLinkInfo->ADDRESS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->LINE_STATUS: ", pRspQryNetPartyLinkInfo->LINE_STATUS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->CONTACT: ", pRspQryNetPartyLinkInfo->CONTACT, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->TELEPHONE: ", pRspQryNetPartyLinkInfo->TELEPHONE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->MOBILEPHONE: ", pRspQryNetPartyLinkInfo->MOBILEPHONE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->EMAIL: ", pRspQryNetPartyLinkInfo->EMAIL, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->FAX: ", pRspQryNetPartyLinkInfo->FAX, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->PROVINCE: ", pRspQryNetPartyLinkInfo->PROVINCE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->DDN_NO: ", pRspQryNetPartyLinkInfo->DDN_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->IN_MODE: ", pRspQryNetPartyLinkInfo->IN_MODE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->IP_WAN: ", pRspQryNetPartyLinkInfo->IP_WAN, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->IP_LAN: ", pRspQryNetPartyLinkInfo->IP_LAN, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->IPADDR: ", pRspQryNetPartyLinkInfo->IPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->Interface: ", pRspQryNetPartyLinkInfo->Interface, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->INTERFACE_DATE: ", pRspQryNetPartyLinkInfo->INTERFACE_DATE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->SOFTWARE: ", pRspQryNetPartyLinkInfo->SOFTWARE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->FEE_TYPE: ", pRspQryNetPartyLinkInfo->FEE_TYPE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->SERVICEPROVIDER: ", pRspQryNetPartyLinkInfo->SERVICEPROVIDER, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->IF_ZIYING: ", pRspQryNetPartyLinkInfo->IF_ZIYING, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->IF_TUOGUAN: ", pRspQryNetPartyLinkInfo->IF_TUOGUAN, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->HASOTHER: ", pRspQryNetPartyLinkInfo->HASOTHER, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->SEAT_NO: ", pRspQryNetPartyLinkInfo->SEAT_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkInfo->PRO: ", pRspQryNetPartyLinkInfo->PRO, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetPartyLinkInfoField* pNewRspQryNetPartyLinkInfo = new CShfeFtdcRspQryNetPartyLinkInfoField;
    memcpy (pNewRspQryNetPartyLinkInfo, pRspQryNetPartyLinkInfo, sizeof(CShfeFtdcRspQryNetPartyLinkInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetPartyLinkInfo;

    uv_mutex_lock (&g_RspQryNetPartyLinkInfoTopic_mutex);
    g_RspQryNetPartyLinkInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetPartyLinkInfoTopic_mutex);

    uv_async_send(&g_RspQryNetPartyLinkInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetPartyLinkInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetPartyLinkInfoTopic(CShfeFtdcRtnNetPartyLinkInfoField* pRtnNetPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetPartyLinkInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetPartyLinkInfo) { 
        OutputCallbackMessage("pRtnNetPartyLinkInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetPartyLinkInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetPartyLinkInfo->OperationType: ", pRtnNetPartyLinkInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->ID: ", pRtnNetPartyLinkInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->MEMBER_NO: ", pRtnNetPartyLinkInfo->MEMBER_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->MEMBER_NAME: ", pRtnNetPartyLinkInfo->MEMBER_NAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->REMOTE_ADDR: ", pRtnNetPartyLinkInfo->REMOTE_ADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->LOCAL_ADDR: ", pRtnNetPartyLinkInfo->LOCAL_ADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->ADDRESS: ", pRtnNetPartyLinkInfo->ADDRESS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->LINE_STATUS: ", pRtnNetPartyLinkInfo->LINE_STATUS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->CONTACT: ", pRtnNetPartyLinkInfo->CONTACT, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->TELEPHONE: ", pRtnNetPartyLinkInfo->TELEPHONE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->MOBILEPHONE: ", pRtnNetPartyLinkInfo->MOBILEPHONE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->EMAIL: ", pRtnNetPartyLinkInfo->EMAIL, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->FAX: ", pRtnNetPartyLinkInfo->FAX, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->PROVINCE: ", pRtnNetPartyLinkInfo->PROVINCE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->DDN_NO: ", pRtnNetPartyLinkInfo->DDN_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->IN_MODE: ", pRtnNetPartyLinkInfo->IN_MODE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->IP_WAN: ", pRtnNetPartyLinkInfo->IP_WAN, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->IP_LAN: ", pRtnNetPartyLinkInfo->IP_LAN, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->IPADDR: ", pRtnNetPartyLinkInfo->IPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->Interface: ", pRtnNetPartyLinkInfo->Interface, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->INTERFACE_DATE: ", pRtnNetPartyLinkInfo->INTERFACE_DATE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->SOFTWARE: ", pRtnNetPartyLinkInfo->SOFTWARE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->FEE_TYPE: ", pRtnNetPartyLinkInfo->FEE_TYPE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->SERVICEPROVIDER: ", pRtnNetPartyLinkInfo->SERVICEPROVIDER, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->IF_ZIYING: ", pRtnNetPartyLinkInfo->IF_ZIYING, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->IF_TUOGUAN: ", pRtnNetPartyLinkInfo->IF_TUOGUAN, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->HASOTHER: ", pRtnNetPartyLinkInfo->HASOTHER, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->SEAT_NO: ", pRtnNetPartyLinkInfo->SEAT_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkInfo->PRO: ", pRtnNetPartyLinkInfo->PRO, g_RunningResult_File);

    CShfeFtdcRtnNetPartyLinkInfoField* pNewRtnNetPartyLinkInfo = new CShfeFtdcRtnNetPartyLinkInfoField;
    memcpy (pNewRtnNetPartyLinkInfo, pRtnNetPartyLinkInfo, sizeof(CShfeFtdcRtnNetPartyLinkInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetPartyLinkInfo;

    uv_mutex_lock (&g_RtnNetPartyLinkInfoTopic_mutex);
    g_RtnNetPartyLinkInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetPartyLinkInfoTopic_mutex);

    uv_async_send(&g_RtnNetPartyLinkInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetPartyLinkInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetMonitorActionAttrTopic(CShfeFtdcRspQryNetMonitorActionAttrField* pRspQryNetMonitorActionAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetMonitorActionAttrTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetMonitorActionAttr) { 
        OutputCallbackMessage("pRspQryNetMonitorActionAttr is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorActionAttrTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetMonitorActionAttr->OperationType: ", pRspQryNetMonitorActionAttr->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorActionAttr->ID: ", pRspQryNetMonitorActionAttr->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorActionAttr->ActionGroup_ID: ", pRspQryNetMonitorActionAttr->ActionGroup_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorActionAttr->MonitorAttr_ID: ", pRspQryNetMonitorActionAttr->MonitorAttr_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorActionAttr->MonitorAttrName: ", pRspQryNetMonitorActionAttr->MonitorAttrName, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetMonitorActionAttrField* pNewRspQryNetMonitorActionAttr = new CShfeFtdcRspQryNetMonitorActionAttrField;
    memcpy (pNewRspQryNetMonitorActionAttr, pRspQryNetMonitorActionAttr, sizeof(CShfeFtdcRspQryNetMonitorActionAttrField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetMonitorActionAttr;

    uv_mutex_lock (&g_RspQryNetMonitorActionAttrTopic_mutex);
    g_RspQryNetMonitorActionAttrTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetMonitorActionAttrTopic_mutex);

    uv_async_send(&g_RspQryNetMonitorActionAttrTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorActionAttrTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetMonitorActionAttrTopic(CShfeFtdcRtnNetMonitorActionAttrField* pRtnNetMonitorActionAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetMonitorActionAttrTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetMonitorActionAttr) { 
        OutputCallbackMessage("pRtnNetMonitorActionAttr is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorActionAttrTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetMonitorActionAttr->OperationType: ", pRtnNetMonitorActionAttr->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorActionAttr->ID: ", pRtnNetMonitorActionAttr->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorActionAttr->ActionGroup_ID: ", pRtnNetMonitorActionAttr->ActionGroup_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorActionAttr->MonitorAttr_ID: ", pRtnNetMonitorActionAttr->MonitorAttr_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorActionAttr->MonitorAttrName: ", pRtnNetMonitorActionAttr->MonitorAttrName, g_RunningResult_File);

    CShfeFtdcRtnNetMonitorActionAttrField* pNewRtnNetMonitorActionAttr = new CShfeFtdcRtnNetMonitorActionAttrField;
    memcpy (pNewRtnNetMonitorActionAttr, pRtnNetMonitorActionAttr, sizeof(CShfeFtdcRtnNetMonitorActionAttrField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetMonitorActionAttr;

    uv_mutex_lock (&g_RtnNetMonitorActionAttrTopic_mutex);
    g_RtnNetMonitorActionAttrTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetMonitorActionAttrTopic_mutex);

    uv_async_send(&g_RtnNetMonitorActionAttrTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorActionAttrTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetModuleTopic(CShfeFtdcRspQryNetModuleField* pRspQryNetModule, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetModuleTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetModule) { 
        OutputCallbackMessage("pRspQryNetModule is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetModuleTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetModule->OperationType: ", pRspQryNetModule->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetModule->ID: ", pRspQryNetModule->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetModule->ObjectID: ", pRspQryNetModule->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetModule->MonitorType_ID: ", pRspQryNetModule->MonitorType_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetModule->DeviceID: ", pRspQryNetModule->DeviceID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetModule->DeviceObjectID: ", pRspQryNetModule->DeviceObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetModule->Name: ", pRspQryNetModule->Name, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetModule->Description: ", pRspQryNetModule->Description, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetModule->ModuleIndex: ", pRspQryNetModule->ModuleIndex, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetModule->EntPhyIndex: ", pRspQryNetModule->EntPhyIndex, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetModuleField* pNewRspQryNetModule = new CShfeFtdcRspQryNetModuleField;
    memcpy (pNewRspQryNetModule, pRspQryNetModule, sizeof(CShfeFtdcRspQryNetModuleField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetModule;

    uv_mutex_lock (&g_RspQryNetModuleTopic_mutex);
    g_RspQryNetModuleTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetModuleTopic_mutex);

    uv_async_send(&g_RspQryNetModuleTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetModuleTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetModuleTopic(CShfeFtdcRtnNetModuleField* pRtnNetModule, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetModuleTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetModule) { 
        OutputCallbackMessage("pRtnNetModule is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetModuleTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetModule->OperationType: ", pRtnNetModule->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetModule->ID: ", pRtnNetModule->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetModule->ObjectID: ", pRtnNetModule->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetModule->MonitorType_ID: ", pRtnNetModule->MonitorType_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetModule->DeviceID: ", pRtnNetModule->DeviceID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetModule->DeviceObjectID: ", pRtnNetModule->DeviceObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetModule->Name: ", pRtnNetModule->Name, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetModule->Description: ", pRtnNetModule->Description, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetModule->ModuleIndex: ", pRtnNetModule->ModuleIndex, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetModule->EntPhyIndex: ", pRtnNetModule->EntPhyIndex, g_RunningResult_File);

    CShfeFtdcRtnNetModuleField* pNewRtnNetModule = new CShfeFtdcRtnNetModuleField;
    memcpy (pNewRtnNetModule, pRtnNetModule, sizeof(CShfeFtdcRtnNetModuleField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetModule;

    uv_mutex_lock (&g_RtnNetModuleTopic_mutex);
    g_RtnNetModuleTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetModuleTopic_mutex);

    uv_async_send(&g_RtnNetModuleTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetModuleTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetEventExprTopic(CShfeFtdcRspQryNetEventExprField* pRspQryNetEventExpr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetEventExprTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetEventExpr) { 
        OutputCallbackMessage("pRspQryNetEventExpr is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetEventExprTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetEventExpr->OperationType: ", pRspQryNetEventExpr->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventExpr->ID: ", pRspQryNetEventExpr->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventExpr->CNAME: ", pRspQryNetEventExpr->CNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventExpr->ENAME: ", pRspQryNetEventExpr->ENAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventExpr->WarningLEVEL: ", pRspQryNetEventExpr->WarningLEVEL, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventExpr->EventTypeID: ", pRspQryNetEventExpr->EventTypeID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventExpr->SubEventTypeID: ", pRspQryNetEventExpr->SubEventTypeID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventExpr->GIVEUPTIME: ", pRspQryNetEventExpr->GIVEUPTIME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventExpr->CONTROL: ", pRspQryNetEventExpr->CONTROL, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventExpr->EXPR: ", pRspQryNetEventExpr->EXPR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventExpr->BRIEF: ", pRspQryNetEventExpr->BRIEF, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventExpr->DISCRIPTION: ", pRspQryNetEventExpr->DISCRIPTION, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventExpr->MSGGROUP_ID: ", pRspQryNetEventExpr->MSGGROUP_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventExpr->ADMINGROUP_ID: ", pRspQryNetEventExpr->ADMINGROUP_ID, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetEventExprField* pNewRspQryNetEventExpr = new CShfeFtdcRspQryNetEventExprField;
    memcpy (pNewRspQryNetEventExpr, pRspQryNetEventExpr, sizeof(CShfeFtdcRspQryNetEventExprField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetEventExpr;

    uv_mutex_lock (&g_RspQryNetEventExprTopic_mutex);
    g_RspQryNetEventExprTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetEventExprTopic_mutex);

    uv_async_send(&g_RspQryNetEventExprTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetEventExprTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetEventExprTopic(CShfeFtdcRtnNetEventExprField* pRtnNetEventExpr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetEventExprTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetEventExpr) { 
        OutputCallbackMessage("pRtnNetEventExpr is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetEventExprTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetEventExpr->OperationType: ", pRtnNetEventExpr->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventExpr->ID: ", pRtnNetEventExpr->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventExpr->CNAME: ", pRtnNetEventExpr->CNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventExpr->ENAME: ", pRtnNetEventExpr->ENAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventExpr->WarningLEVEL: ", pRtnNetEventExpr->WarningLEVEL, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventExpr->EventTypeID: ", pRtnNetEventExpr->EventTypeID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventExpr->SubEventTypeID: ", pRtnNetEventExpr->SubEventTypeID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventExpr->GIVEUPTIME: ", pRtnNetEventExpr->GIVEUPTIME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventExpr->CONTROL: ", pRtnNetEventExpr->CONTROL, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventExpr->EXPR: ", pRtnNetEventExpr->EXPR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventExpr->BRIEF: ", pRtnNetEventExpr->BRIEF, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventExpr->DISCRIPTION: ", pRtnNetEventExpr->DISCRIPTION, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventExpr->MSGGROUP_ID: ", pRtnNetEventExpr->MSGGROUP_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventExpr->ADMINGROUP_ID: ", pRtnNetEventExpr->ADMINGROUP_ID, g_RunningResult_File);

    CShfeFtdcRtnNetEventExprField* pNewRtnNetEventExpr = new CShfeFtdcRtnNetEventExprField;
    memcpy (pNewRtnNetEventExpr, pRtnNetEventExpr, sizeof(CShfeFtdcRtnNetEventExprField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetEventExpr;

    uv_mutex_lock (&g_RtnNetEventExprTopic_mutex);
    g_RtnNetEventExprTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetEventExprTopic_mutex);

    uv_async_send(&g_RtnNetEventExprTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetEventExprTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetEventTypeTopic(CShfeFtdcRspQryNetEventTypeField* pRspQryNetEventType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetEventTypeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetEventType) { 
        OutputCallbackMessage("pRspQryNetEventType is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetEventTypeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetEventType->OperationType: ", pRspQryNetEventType->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventType->ID: ", pRspQryNetEventType->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventType->CName: ", pRspQryNetEventType->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventType->EName: ", pRspQryNetEventType->EName, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetEventTypeField* pNewRspQryNetEventType = new CShfeFtdcRspQryNetEventTypeField;
    memcpy (pNewRspQryNetEventType, pRspQryNetEventType, sizeof(CShfeFtdcRspQryNetEventTypeField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetEventType;

    uv_mutex_lock (&g_RspQryNetEventTypeTopic_mutex);
    g_RspQryNetEventTypeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetEventTypeTopic_mutex);

    uv_async_send(&g_RspQryNetEventTypeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetEventTypeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetEventTypeTopic(CShfeFtdcRtnNetEventTypeField* pRtnNetEventType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetEventTypeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetEventType) { 
        OutputCallbackMessage("pRtnNetEventType is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetEventTypeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetEventType->OperationType: ", pRtnNetEventType->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventType->ID: ", pRtnNetEventType->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventType->CName: ", pRtnNetEventType->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventType->EName: ", pRtnNetEventType->EName, g_RunningResult_File);

    CShfeFtdcRtnNetEventTypeField* pNewRtnNetEventType = new CShfeFtdcRtnNetEventTypeField;
    memcpy (pNewRtnNetEventType, pRtnNetEventType, sizeof(CShfeFtdcRtnNetEventTypeField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetEventType;

    uv_mutex_lock (&g_RtnNetEventTypeTopic_mutex);
    g_RtnNetEventTypeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetEventTypeTopic_mutex);

    uv_async_send(&g_RtnNetEventTypeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetEventTypeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetSubEventTypeTopic(CShfeFtdcRspQryNetSubEventTypeField* pRspQryNetSubEventType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetSubEventTypeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetSubEventType) { 
        OutputCallbackMessage("pRspQryNetSubEventType is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetSubEventTypeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetSubEventType->OperationType: ", pRspQryNetSubEventType->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetSubEventType->ID: ", pRspQryNetSubEventType->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetSubEventType->CName: ", pRspQryNetSubEventType->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetSubEventType->EName: ", pRspQryNetSubEventType->EName, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetSubEventTypeField* pNewRspQryNetSubEventType = new CShfeFtdcRspQryNetSubEventTypeField;
    memcpy (pNewRspQryNetSubEventType, pRspQryNetSubEventType, sizeof(CShfeFtdcRspQryNetSubEventTypeField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetSubEventType;

    uv_mutex_lock (&g_RspQryNetSubEventTypeTopic_mutex);
    g_RspQryNetSubEventTypeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetSubEventTypeTopic_mutex);

    uv_async_send(&g_RspQryNetSubEventTypeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetSubEventTypeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetSubEventTypeTopic(CShfeFtdcRtnNetSubEventTypeField* pRtnNetSubEventType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetSubEventTypeTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetSubEventType) { 
        OutputCallbackMessage("pRtnNetSubEventType is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetSubEventTypeTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetSubEventType->OperationType: ", pRtnNetSubEventType->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetSubEventType->ID: ", pRtnNetSubEventType->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetSubEventType->CName: ", pRtnNetSubEventType->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetSubEventType->EName: ", pRtnNetSubEventType->EName, g_RunningResult_File);

    CShfeFtdcRtnNetSubEventTypeField* pNewRtnNetSubEventType = new CShfeFtdcRtnNetSubEventTypeField;
    memcpy (pNewRtnNetSubEventType, pRtnNetSubEventType, sizeof(CShfeFtdcRtnNetSubEventTypeField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetSubEventType;

    uv_mutex_lock (&g_RtnNetSubEventTypeTopic_mutex);
    g_RtnNetSubEventTypeTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetSubEventTypeTopic_mutex);

    uv_async_send(&g_RtnNetSubEventTypeTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetSubEventTypeTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetEventLevelTopic(CShfeFtdcRspQryNetEventLevelField* pRspQryNetEventLevel, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetEventLevelTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetEventLevel) { 
        OutputCallbackMessage("pRspQryNetEventLevel is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetEventLevelTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetEventLevel->OperationType: ", pRspQryNetEventLevel->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventLevel->ID: ", pRspQryNetEventLevel->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventLevel->CName: ", pRspQryNetEventLevel->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventLevel->EName: ", pRspQryNetEventLevel->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetEventLevel->DISCRIPTION: ", pRspQryNetEventLevel->DISCRIPTION, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetEventLevelField* pNewRspQryNetEventLevel = new CShfeFtdcRspQryNetEventLevelField;
    memcpy (pNewRspQryNetEventLevel, pRspQryNetEventLevel, sizeof(CShfeFtdcRspQryNetEventLevelField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetEventLevel;

    uv_mutex_lock (&g_RspQryNetEventLevelTopic_mutex);
    g_RspQryNetEventLevelTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetEventLevelTopic_mutex);

    uv_async_send(&g_RspQryNetEventLevelTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetEventLevelTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetEventLevelTopic(CShfeFtdcRtnNetEventLevelField* pRtnNetEventLevel, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetEventLevelTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetEventLevel) { 
        OutputCallbackMessage("pRtnNetEventLevel is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetEventLevelTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetEventLevel->OperationType: ", pRtnNetEventLevel->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventLevel->ID: ", pRtnNetEventLevel->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventLevel->CName: ", pRtnNetEventLevel->CName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventLevel->EName: ", pRtnNetEventLevel->EName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetEventLevel->DISCRIPTION: ", pRtnNetEventLevel->DISCRIPTION, g_RunningResult_File);

    CShfeFtdcRtnNetEventLevelField* pNewRtnNetEventLevel = new CShfeFtdcRtnNetEventLevelField;
    memcpy (pNewRtnNetEventLevel, pRtnNetEventLevel, sizeof(CShfeFtdcRtnNetEventLevelField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetEventLevel;

    uv_mutex_lock (&g_RtnNetEventLevelTopic_mutex);
    g_RtnNetEventLevelTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetEventLevelTopic_mutex);

    uv_async_send(&g_RtnNetEventLevelTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetEventLevelTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetMonitorTaskStatusResultTopic(CShfeFtdcRspQryNetMonitorTaskStatusResultField* pRspQryNetMonitorTaskStatusResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetMonitorTaskStatusResultTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetMonitorTaskStatusResult) { 
        OutputCallbackMessage("pRspQryNetMonitorTaskStatusResult is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorTaskStatusResultTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetMonitorTaskStatusResult->OperationType: ", pRspQryNetMonitorTaskStatusResult->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskStatusResult->ObjectID: ", pRspQryNetMonitorTaskStatusResult->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskStatusResult->Task_ID: ", pRspQryNetMonitorTaskStatusResult->Task_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskStatusResult->OperateTime: ", pRspQryNetMonitorTaskStatusResult->OperateTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskStatusResult->MonDate: ", pRspQryNetMonitorTaskStatusResult->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskStatusResult->MonTime: ", pRspQryNetMonitorTaskStatusResult->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskStatusResult->Flag: ", pRspQryNetMonitorTaskStatusResult->Flag, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetMonitorTaskStatusResultField* pNewRspQryNetMonitorTaskStatusResult = new CShfeFtdcRspQryNetMonitorTaskStatusResultField;
    memcpy (pNewRspQryNetMonitorTaskStatusResult, pRspQryNetMonitorTaskStatusResult, sizeof(CShfeFtdcRspQryNetMonitorTaskStatusResultField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetMonitorTaskStatusResult;

    uv_mutex_lock (&g_RspQryNetMonitorTaskStatusResultTopic_mutex);
    g_RspQryNetMonitorTaskStatusResultTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetMonitorTaskStatusResultTopic_mutex);

    uv_async_send(&g_RspQryNetMonitorTaskStatusResultTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorTaskStatusResultTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetMonitorTaskStatusResultTopic(CShfeFtdcRtnNetMonitorTaskStatusResultField* pRtnNetMonitorTaskStatusResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetMonitorTaskStatusResultTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetMonitorTaskStatusResult) { 
        OutputCallbackMessage("pRtnNetMonitorTaskStatusResult is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorTaskStatusResultTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetMonitorTaskStatusResult->OperationType: ", pRtnNetMonitorTaskStatusResult->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskStatusResult->ObjectID: ", pRtnNetMonitorTaskStatusResult->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskStatusResult->Task_ID: ", pRtnNetMonitorTaskStatusResult->Task_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskStatusResult->OperateTime: ", pRtnNetMonitorTaskStatusResult->OperateTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskStatusResult->MonDate: ", pRtnNetMonitorTaskStatusResult->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskStatusResult->MonTime: ", pRtnNetMonitorTaskStatusResult->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskStatusResult->Flag: ", pRtnNetMonitorTaskStatusResult->Flag, g_RunningResult_File);

    CShfeFtdcRtnNetMonitorTaskStatusResultField* pNewRtnNetMonitorTaskStatusResult = new CShfeFtdcRtnNetMonitorTaskStatusResultField;
    memcpy (pNewRtnNetMonitorTaskStatusResult, pRtnNetMonitorTaskStatusResult, sizeof(CShfeFtdcRtnNetMonitorTaskStatusResultField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetMonitorTaskStatusResult;

    uv_mutex_lock (&g_RtnNetMonitorTaskStatusResultTopic_mutex);
    g_RtnNetMonitorTaskStatusResultTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetMonitorTaskStatusResultTopic_mutex);

    uv_async_send(&g_RtnNetMonitorTaskStatusResultTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorTaskStatusResultTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetCfgFileTopic(CShfeFtdcRspQryNetCfgFileField* pRspQryNetCfgFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetCfgFileTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetCfgFile) { 
        OutputCallbackMessage("pRspQryNetCfgFile is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetCfgFileTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetCfgFile->OperationType: ", pRspQryNetCfgFile->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetCfgFile->ObjectID: ", pRspQryNetCfgFile->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetCfgFile->MonDate: ", pRspQryNetCfgFile->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetCfgFile->MonTime: ", pRspQryNetCfgFile->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetCfgFile->CfgFileName: ", pRspQryNetCfgFile->CfgFileName, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetCfgFileField* pNewRspQryNetCfgFile = new CShfeFtdcRspQryNetCfgFileField;
    memcpy (pNewRspQryNetCfgFile, pRspQryNetCfgFile, sizeof(CShfeFtdcRspQryNetCfgFileField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetCfgFile;

    uv_mutex_lock (&g_RspQryNetCfgFileTopic_mutex);
    g_RspQryNetCfgFileTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetCfgFileTopic_mutex);

    uv_async_send(&g_RspQryNetCfgFileTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetCfgFileTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetCfgFileTopic(CShfeFtdcRtnNetCfgFileField* pRtnNetCfgFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetCfgFileTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetCfgFile) { 
        OutputCallbackMessage("pRtnNetCfgFile is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetCfgFileTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetCfgFile->OperationType: ", pRtnNetCfgFile->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetCfgFile->ObjectID: ", pRtnNetCfgFile->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetCfgFile->MonDate: ", pRtnNetCfgFile->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetCfgFile->MonTime: ", pRtnNetCfgFile->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetCfgFile->CfgFileName: ", pRtnNetCfgFile->CfgFileName, g_RunningResult_File);

    CShfeFtdcRtnNetCfgFileField* pNewRtnNetCfgFile = new CShfeFtdcRtnNetCfgFileField;
    memcpy (pNewRtnNetCfgFile, pRtnNetCfgFile, sizeof(CShfeFtdcRtnNetCfgFileField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetCfgFile;

    uv_mutex_lock (&g_RtnNetCfgFileTopic_mutex);
    g_RtnNetCfgFileTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetCfgFileTopic_mutex);

    uv_async_send(&g_RtnNetCfgFileTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetCfgFileTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetMonitorDeviceTaskTopic(CShfeFtdcRspQryNetMonitorDeviceTaskField* pRspQryNetMonitorDeviceTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetMonitorDeviceTaskTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetMonitorDeviceTask) { 
        OutputCallbackMessage("pRspQryNetMonitorDeviceTask is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorDeviceTaskTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetMonitorDeviceTask->OperationType: ", pRspQryNetMonitorDeviceTask->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorDeviceTask->ID: ", pRspQryNetMonitorDeviceTask->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorDeviceTask->ObjectID: ", pRspQryNetMonitorDeviceTask->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorDeviceTask->IPAddress: ", pRspQryNetMonitorDeviceTask->IPAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorDeviceTask->Manufactory_ID: ", pRspQryNetMonitorDeviceTask->Manufactory_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorDeviceTask->InstructChain: ", pRspQryNetMonitorDeviceTask->InstructChain, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorDeviceTask->InstructAlias: ", pRspQryNetMonitorDeviceTask->InstructAlias, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorDeviceTask->InstructArgs: ", pRspQryNetMonitorDeviceTask->InstructArgs, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorDeviceTask->DefParamChain: ", pRspQryNetMonitorDeviceTask->DefParamChain, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorDeviceTask->Flag: ", pRspQryNetMonitorDeviceTask->Flag, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetMonitorDeviceTaskField* pNewRspQryNetMonitorDeviceTask = new CShfeFtdcRspQryNetMonitorDeviceTaskField;
    memcpy (pNewRspQryNetMonitorDeviceTask, pRspQryNetMonitorDeviceTask, sizeof(CShfeFtdcRspQryNetMonitorDeviceTaskField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetMonitorDeviceTask;

    uv_mutex_lock (&g_RspQryNetMonitorDeviceTaskTopic_mutex);
    g_RspQryNetMonitorDeviceTaskTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetMonitorDeviceTaskTopic_mutex);

    uv_async_send(&g_RspQryNetMonitorDeviceTaskTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorDeviceTaskTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetMonitorDeviceTaskTopic(CShfeFtdcRtnNetMonitorDeviceTaskField* pRtnNetMonitorDeviceTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetMonitorDeviceTaskTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetMonitorDeviceTask) { 
        OutputCallbackMessage("pRtnNetMonitorDeviceTask is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorDeviceTaskTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetMonitorDeviceTask->OperationType: ", pRtnNetMonitorDeviceTask->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorDeviceTask->ID: ", pRtnNetMonitorDeviceTask->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorDeviceTask->ObjectID: ", pRtnNetMonitorDeviceTask->ObjectID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorDeviceTask->IPAddress: ", pRtnNetMonitorDeviceTask->IPAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorDeviceTask->Manufactory_ID: ", pRtnNetMonitorDeviceTask->Manufactory_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorDeviceTask->InstructChain: ", pRtnNetMonitorDeviceTask->InstructChain, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorDeviceTask->InstructAlias: ", pRtnNetMonitorDeviceTask->InstructAlias, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorDeviceTask->InstructArgs: ", pRtnNetMonitorDeviceTask->InstructArgs, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorDeviceTask->DefParamChain: ", pRtnNetMonitorDeviceTask->DefParamChain, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorDeviceTask->Flag: ", pRtnNetMonitorDeviceTask->Flag, g_RunningResult_File);

    CShfeFtdcRtnNetMonitorDeviceTaskField* pNewRtnNetMonitorDeviceTask = new CShfeFtdcRtnNetMonitorDeviceTaskField;
    memcpy (pNewRtnNetMonitorDeviceTask, pRtnNetMonitorDeviceTask, sizeof(CShfeFtdcRtnNetMonitorDeviceTaskField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetMonitorDeviceTask;

    uv_mutex_lock (&g_RtnNetMonitorDeviceTaskTopic_mutex);
    g_RtnNetMonitorDeviceTaskTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetMonitorDeviceTaskTopic_mutex);

    uv_async_send(&g_RtnNetMonitorDeviceTaskTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorDeviceTaskTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetMonitorTaskInstAttrsTopic(CShfeFtdcRspQryNetMonitorTaskInstAttrsField* pRspQryNetMonitorTaskInstAttrs, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetMonitorTaskInstAttrsTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetMonitorTaskInstAttrs) { 
        OutputCallbackMessage("pRspQryNetMonitorTaskInstAttrs is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorTaskInstAttrsTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetMonitorTaskInstAttrs->OperationType: ", pRspQryNetMonitorTaskInstAttrs->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInstAttrs->ID: ", pRspQryNetMonitorTaskInstAttrs->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInstAttrs->Manufactory_ID: ", pRspQryNetMonitorTaskInstAttrs->Manufactory_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInstAttrs->InstructAlias: ", pRspQryNetMonitorTaskInstAttrs->InstructAlias, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInstAttrs->DEVICETYPE: ", pRspQryNetMonitorTaskInstAttrs->DEVICETYPE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInstAttrs->AttrsChain: ", pRspQryNetMonitorTaskInstAttrs->AttrsChain, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInstAttrs->DefRegularChain: ", pRspQryNetMonitorTaskInstAttrs->DefRegularChain, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMonitorTaskInstAttrs->DefParamChain: ", pRspQryNetMonitorTaskInstAttrs->DefParamChain, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetMonitorTaskInstAttrsField* pNewRspQryNetMonitorTaskInstAttrs = new CShfeFtdcRspQryNetMonitorTaskInstAttrsField;
    memcpy (pNewRspQryNetMonitorTaskInstAttrs, pRspQryNetMonitorTaskInstAttrs, sizeof(CShfeFtdcRspQryNetMonitorTaskInstAttrsField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetMonitorTaskInstAttrs;

    uv_mutex_lock (&g_RspQryNetMonitorTaskInstAttrsTopic_mutex);
    g_RspQryNetMonitorTaskInstAttrsTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetMonitorTaskInstAttrsTopic_mutex);

    uv_async_send(&g_RspQryNetMonitorTaskInstAttrsTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetMonitorTaskInstAttrsTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetMonitorTaskInstAttrsTopic(CShfeFtdcRtnNetMonitorTaskInstAttrsField* pRtnNetMonitorTaskInstAttrs, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetMonitorTaskInstAttrsTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetMonitorTaskInstAttrs) { 
        OutputCallbackMessage("pRtnNetMonitorTaskInstAttrs is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorTaskInstAttrsTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetMonitorTaskInstAttrs->OperationType: ", pRtnNetMonitorTaskInstAttrs->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInstAttrs->ID: ", pRtnNetMonitorTaskInstAttrs->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInstAttrs->Manufactory_ID: ", pRtnNetMonitorTaskInstAttrs->Manufactory_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInstAttrs->InstructAlias: ", pRtnNetMonitorTaskInstAttrs->InstructAlias, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInstAttrs->DEVICETYPE: ", pRtnNetMonitorTaskInstAttrs->DEVICETYPE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInstAttrs->AttrsChain: ", pRtnNetMonitorTaskInstAttrs->AttrsChain, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInstAttrs->DefRegularChain: ", pRtnNetMonitorTaskInstAttrs->DefRegularChain, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMonitorTaskInstAttrs->DefParamChain: ", pRtnNetMonitorTaskInstAttrs->DefParamChain, g_RunningResult_File);

    CShfeFtdcRtnNetMonitorTaskInstAttrsField* pNewRtnNetMonitorTaskInstAttrs = new CShfeFtdcRtnNetMonitorTaskInstAttrsField;
    memcpy (pNewRtnNetMonitorTaskInstAttrs, pRtnNetMonitorTaskInstAttrs, sizeof(CShfeFtdcRtnNetMonitorTaskInstAttrsField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetMonitorTaskInstAttrs;

    uv_mutex_lock (&g_RtnNetMonitorTaskInstAttrsTopic_mutex);
    g_RtnNetMonitorTaskInstAttrsTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetMonitorTaskInstAttrsTopic_mutex);

    uv_async_send(&g_RtnNetMonitorTaskInstAttrsTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetMonitorTaskInstAttrsTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryFileGeneralOperTopic(CShfeFtdcRspQryFileGeneralOperField* pRspQryFileGeneralOper, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryFileGeneralOperTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryFileGeneralOper) { 
        OutputCallbackMessage("pRspQryFileGeneralOper is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryFileGeneralOperTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryFileGeneralOper->OperationType: ", pRspQryFileGeneralOper->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileGeneralOper->FileName: ", pRspQryFileGeneralOper->FileName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileGeneralOper->Version: ", pRspQryFileGeneralOper->Version, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileGeneralOper->SubVersion: ", pRspQryFileGeneralOper->SubVersion, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileGeneralOper->MonDate: ", pRspQryFileGeneralOper->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileGeneralOper->MonTime: ", pRspQryFileGeneralOper->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileGeneralOper->UserName: ", pRspQryFileGeneralOper->UserName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileGeneralOper->OperType: ", pRspQryFileGeneralOper->OperType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileGeneralOper->OperResult: ", pRspQryFileGeneralOper->OperResult, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileGeneralOper->Comments: ", pRspQryFileGeneralOper->Comments, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileGeneralOper->Offset: ", pRspQryFileGeneralOper->Offset, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileGeneralOper->Length: ", pRspQryFileGeneralOper->Length, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryFileGeneralOper->FileContent: ", pRspQryFileGeneralOper->FileContent, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryFileGeneralOperField* pNewRspQryFileGeneralOper = new CShfeFtdcRspQryFileGeneralOperField;
    memcpy (pNewRspQryFileGeneralOper, pRspQryFileGeneralOper, sizeof(CShfeFtdcRspQryFileGeneralOperField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryFileGeneralOper;

    uv_mutex_lock (&g_RspQryFileGeneralOperTopic_mutex);
    g_RspQryFileGeneralOperTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryFileGeneralOperTopic_mutex);

    uv_async_send(&g_RspQryFileGeneralOperTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryFileGeneralOperTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnFileGeneralOperTopic(CShfeFtdcRtnFileGeneralOperField* pRtnFileGeneralOper, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnFileGeneralOperTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnFileGeneralOper) { 
        OutputCallbackMessage("pRtnFileGeneralOper is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnFileGeneralOperTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnFileGeneralOper->OperationType: ", pRtnFileGeneralOper->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileGeneralOper->FileName: ", pRtnFileGeneralOper->FileName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileGeneralOper->Version: ", pRtnFileGeneralOper->Version, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileGeneralOper->SubVersion: ", pRtnFileGeneralOper->SubVersion, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileGeneralOper->MonDate: ", pRtnFileGeneralOper->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileGeneralOper->MonTime: ", pRtnFileGeneralOper->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileGeneralOper->UserName: ", pRtnFileGeneralOper->UserName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileGeneralOper->OperType: ", pRtnFileGeneralOper->OperType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileGeneralOper->OperResult: ", pRtnFileGeneralOper->OperResult, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileGeneralOper->Comments: ", pRtnFileGeneralOper->Comments, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileGeneralOper->Offset: ", pRtnFileGeneralOper->Offset, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileGeneralOper->Length: ", pRtnFileGeneralOper->Length, g_RunningResult_File);
    OutputCallbackMessage(" pRtnFileGeneralOper->FileContent: ", pRtnFileGeneralOper->FileContent, g_RunningResult_File);

    CShfeFtdcRtnFileGeneralOperField* pNewRtnFileGeneralOper = new CShfeFtdcRtnFileGeneralOperField;
    memcpy (pNewRtnFileGeneralOper, pRtnFileGeneralOper, sizeof(CShfeFtdcRtnFileGeneralOperField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnFileGeneralOper;

    uv_mutex_lock (&g_RtnFileGeneralOperTopic_mutex);
    g_RtnFileGeneralOperTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnFileGeneralOperTopic_mutex);

    uv_async_send(&g_RtnFileGeneralOperTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnFileGeneralOperTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetBaseLineTopic(CShfeFtdcRspQryNetBaseLineField* pRspQryNetBaseLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetBaseLineTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetBaseLine) { 
        OutputCallbackMessage("pRspQryNetBaseLine is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetBaseLineTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetBaseLine->OperationType: ", pRspQryNetBaseLine->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLine->ID: ", pRspQryNetBaseLine->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLine->MANUFACTORY_ID: ", pRspQryNetBaseLine->MANUFACTORY_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLine->Name: ", pRspQryNetBaseLine->Name, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLine->SerialUsed: ", pRspQryNetBaseLine->SerialUsed, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLine->data: ", pRspQryNetBaseLine->data, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLine->memo: ", pRspQryNetBaseLine->memo, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLine->Flag: ", pRspQryNetBaseLine->Flag, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetBaseLineField* pNewRspQryNetBaseLine = new CShfeFtdcRspQryNetBaseLineField;
    memcpy (pNewRspQryNetBaseLine, pRspQryNetBaseLine, sizeof(CShfeFtdcRspQryNetBaseLineField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetBaseLine;

    uv_mutex_lock (&g_RspQryNetBaseLineTopic_mutex);
    g_RspQryNetBaseLineTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetBaseLineTopic_mutex);

    uv_async_send(&g_RspQryNetBaseLineTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetBaseLineTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetBaseLineTopic(CShfeFtdcRtnNetBaseLineField* pRtnNetBaseLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetBaseLineTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetBaseLine) { 
        OutputCallbackMessage("pRtnNetBaseLine is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetBaseLineTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetBaseLine->OperationType: ", pRtnNetBaseLine->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLine->ID: ", pRtnNetBaseLine->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLine->MANUFACTORY_ID: ", pRtnNetBaseLine->MANUFACTORY_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLine->Name: ", pRtnNetBaseLine->Name, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLine->SerialUsed: ", pRtnNetBaseLine->SerialUsed, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLine->data: ", pRtnNetBaseLine->data, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLine->memo: ", pRtnNetBaseLine->memo, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLine->Flag: ", pRtnNetBaseLine->Flag, g_RunningResult_File);

    CShfeFtdcRtnNetBaseLineField* pNewRtnNetBaseLine = new CShfeFtdcRtnNetBaseLineField;
    memcpy (pNewRtnNetBaseLine, pRtnNetBaseLine, sizeof(CShfeFtdcRtnNetBaseLineField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetBaseLine;

    uv_mutex_lock (&g_RtnNetBaseLineTopic_mutex);
    g_RtnNetBaseLineTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetBaseLineTopic_mutex);

    uv_async_send(&g_RtnNetBaseLineTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetBaseLineTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetBaseLineTaskTopic(CShfeFtdcRspQryNetBaseLineTaskField* pRspQryNetBaseLineTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetBaseLineTaskTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetBaseLineTask) { 
        OutputCallbackMessage("pRspQryNetBaseLineTask is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetBaseLineTaskTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetBaseLineTask->OperationType: ", pRspQryNetBaseLineTask->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineTask->ID: ", pRspQryNetBaseLineTask->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineTask->Name: ", pRspQryNetBaseLineTask->Name, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineTask->BaseLineIDList: ", pRspQryNetBaseLineTask->BaseLineIDList, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineTask->DeviceIDList: ", pRspQryNetBaseLineTask->DeviceIDList, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineTask->GenDate: ", pRspQryNetBaseLineTask->GenDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineTask->GenTime: ", pRspQryNetBaseLineTask->GenTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineTask->GenUser: ", pRspQryNetBaseLineTask->GenUser, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineTask->memo: ", pRspQryNetBaseLineTask->memo, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetBaseLineTaskField* pNewRspQryNetBaseLineTask = new CShfeFtdcRspQryNetBaseLineTaskField;
    memcpy (pNewRspQryNetBaseLineTask, pRspQryNetBaseLineTask, sizeof(CShfeFtdcRspQryNetBaseLineTaskField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetBaseLineTask;

    uv_mutex_lock (&g_RspQryNetBaseLineTaskTopic_mutex);
    g_RspQryNetBaseLineTaskTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetBaseLineTaskTopic_mutex);

    uv_async_send(&g_RspQryNetBaseLineTaskTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetBaseLineTaskTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetBaseLineTaskTopic(CShfeFtdcRtnNetBaseLineTaskField* pRtnNetBaseLineTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetBaseLineTaskTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetBaseLineTask) { 
        OutputCallbackMessage("pRtnNetBaseLineTask is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetBaseLineTaskTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetBaseLineTask->OperationType: ", pRtnNetBaseLineTask->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineTask->ID: ", pRtnNetBaseLineTask->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineTask->Name: ", pRtnNetBaseLineTask->Name, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineTask->BaseLineIDList: ", pRtnNetBaseLineTask->BaseLineIDList, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineTask->DeviceIDList: ", pRtnNetBaseLineTask->DeviceIDList, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineTask->GenDate: ", pRtnNetBaseLineTask->GenDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineTask->GenTime: ", pRtnNetBaseLineTask->GenTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineTask->GenUser: ", pRtnNetBaseLineTask->GenUser, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineTask->memo: ", pRtnNetBaseLineTask->memo, g_RunningResult_File);

    CShfeFtdcRtnNetBaseLineTaskField* pNewRtnNetBaseLineTask = new CShfeFtdcRtnNetBaseLineTaskField;
    memcpy (pNewRtnNetBaseLineTask, pRtnNetBaseLineTask, sizeof(CShfeFtdcRtnNetBaseLineTaskField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetBaseLineTask;

    uv_mutex_lock (&g_RtnNetBaseLineTaskTopic_mutex);
    g_RtnNetBaseLineTaskTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetBaseLineTaskTopic_mutex);

    uv_async_send(&g_RtnNetBaseLineTaskTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetBaseLineTaskTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetBaseLineResultTopic(CShfeFtdcRspQryNetBaseLineResultField* pRspQryNetBaseLineResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetBaseLineResultTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetBaseLineResult) { 
        OutputCallbackMessage("pRspQryNetBaseLineResult is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetBaseLineResultTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetBaseLineResult->OperationType: ", pRspQryNetBaseLineResult->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineResult->ID: ", pRspQryNetBaseLineResult->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineResult->BaseLineName: ", pRspQryNetBaseLineResult->BaseLineName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineResult->DeviceObjID: ", pRspQryNetBaseLineResult->DeviceObjID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineResult->DeviceIP: ", pRspQryNetBaseLineResult->DeviceIP, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineResult->Result: ", pRspQryNetBaseLineResult->Result, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineResult->GenDate: ", pRspQryNetBaseLineResult->GenDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineResult->GenTime: ", pRspQryNetBaseLineResult->GenTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineResult->GenUser: ", pRspQryNetBaseLineResult->GenUser, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetBaseLineResult->Flag: ", pRspQryNetBaseLineResult->Flag, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetBaseLineResultField* pNewRspQryNetBaseLineResult = new CShfeFtdcRspQryNetBaseLineResultField;
    memcpy (pNewRspQryNetBaseLineResult, pRspQryNetBaseLineResult, sizeof(CShfeFtdcRspQryNetBaseLineResultField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetBaseLineResult;

    uv_mutex_lock (&g_RspQryNetBaseLineResultTopic_mutex);
    g_RspQryNetBaseLineResultTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetBaseLineResultTopic_mutex);

    uv_async_send(&g_RspQryNetBaseLineResultTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetBaseLineResultTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetBaseLineResultTopic(CShfeFtdcRtnNetBaseLineResultField* pRtnNetBaseLineResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetBaseLineResultTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetBaseLineResult) { 
        OutputCallbackMessage("pRtnNetBaseLineResult is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetBaseLineResultTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetBaseLineResult->OperationType: ", pRtnNetBaseLineResult->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineResult->ID: ", pRtnNetBaseLineResult->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineResult->BaseLineName: ", pRtnNetBaseLineResult->BaseLineName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineResult->DeviceObjID: ", pRtnNetBaseLineResult->DeviceObjID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineResult->DeviceIP: ", pRtnNetBaseLineResult->DeviceIP, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineResult->Result: ", pRtnNetBaseLineResult->Result, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineResult->GenDate: ", pRtnNetBaseLineResult->GenDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineResult->GenTime: ", pRtnNetBaseLineResult->GenTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineResult->GenUser: ", pRtnNetBaseLineResult->GenUser, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetBaseLineResult->Flag: ", pRtnNetBaseLineResult->Flag, g_RunningResult_File);

    CShfeFtdcRtnNetBaseLineResultField* pNewRtnNetBaseLineResult = new CShfeFtdcRtnNetBaseLineResultField;
    memcpy (pNewRtnNetBaseLineResult, pRtnNetBaseLineResult, sizeof(CShfeFtdcRtnNetBaseLineResultField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetBaseLineResult;

    uv_mutex_lock (&g_RtnNetBaseLineResultTopic_mutex);
    g_RtnNetBaseLineResultTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetBaseLineResultTopic_mutex);

    uv_async_send(&g_RtnNetBaseLineResultTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetBaseLineResultTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetPartyLinkStatusInfoTopic(CShfeFtdcRspQryNetPartyLinkStatusInfoField* pRspQryNetPartyLinkStatusInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetPartyLinkStatusInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetPartyLinkStatusInfo) { 
        OutputCallbackMessage("pRspQryNetPartyLinkStatusInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetPartyLinkStatusInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetPartyLinkStatusInfo->OperationType: ", pRspQryNetPartyLinkStatusInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkStatusInfo->MonDate: ", pRspQryNetPartyLinkStatusInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkStatusInfo->MonTime: ", pRspQryNetPartyLinkStatusInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkStatusInfo->SEAT_NO: ", pRspQryNetPartyLinkStatusInfo->SEAT_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkStatusInfo->IPADDR: ", pRspQryNetPartyLinkStatusInfo->IPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkStatusInfo->Interface: ", pRspQryNetPartyLinkStatusInfo->Interface, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartyLinkStatusInfo->status: ", pRspQryNetPartyLinkStatusInfo->status, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetPartyLinkStatusInfoField* pNewRspQryNetPartyLinkStatusInfo = new CShfeFtdcRspQryNetPartyLinkStatusInfoField;
    memcpy (pNewRspQryNetPartyLinkStatusInfo, pRspQryNetPartyLinkStatusInfo, sizeof(CShfeFtdcRspQryNetPartyLinkStatusInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetPartyLinkStatusInfo;

    uv_mutex_lock (&g_RspQryNetPartyLinkStatusInfoTopic_mutex);
    g_RspQryNetPartyLinkStatusInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetPartyLinkStatusInfoTopic_mutex);

    uv_async_send(&g_RspQryNetPartyLinkStatusInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetPartyLinkStatusInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetPartyLinkStatusInfoTopic(CShfeFtdcRtnNetPartyLinkStatusInfoField* pRtnNetPartyLinkStatusInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetPartyLinkStatusInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetPartyLinkStatusInfo) { 
        OutputCallbackMessage("pRtnNetPartyLinkStatusInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetPartyLinkStatusInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetPartyLinkStatusInfo->OperationType: ", pRtnNetPartyLinkStatusInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkStatusInfo->MonDate: ", pRtnNetPartyLinkStatusInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkStatusInfo->MonTime: ", pRtnNetPartyLinkStatusInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkStatusInfo->SEAT_NO: ", pRtnNetPartyLinkStatusInfo->SEAT_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkStatusInfo->IPADDR: ", pRtnNetPartyLinkStatusInfo->IPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkStatusInfo->Interface: ", pRtnNetPartyLinkStatusInfo->Interface, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartyLinkStatusInfo->status: ", pRtnNetPartyLinkStatusInfo->status, g_RunningResult_File);

    CShfeFtdcRtnNetPartyLinkStatusInfoField* pNewRtnNetPartyLinkStatusInfo = new CShfeFtdcRtnNetPartyLinkStatusInfoField;
    memcpy (pNewRtnNetPartyLinkStatusInfo, pRtnNetPartyLinkStatusInfo, sizeof(CShfeFtdcRtnNetPartyLinkStatusInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetPartyLinkStatusInfo;

    uv_mutex_lock (&g_RtnNetPartyLinkStatusInfoTopic_mutex);
    g_RtnNetPartyLinkStatusInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetPartyLinkStatusInfoTopic_mutex);

    uv_async_send(&g_RtnNetPartyLinkStatusInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetPartyLinkStatusInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetMemberSDHLineInfoTopic(CShfeFtdcRspQryNetMemberSDHLineInfoField* pRspQryNetMemberSDHLineInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetMemberSDHLineInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetMemberSDHLineInfo) { 
        OutputCallbackMessage("pRspQryNetMemberSDHLineInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetMemberSDHLineInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->OperationType: ", pRspQryNetMemberSDHLineInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->ID: ", pRspQryNetMemberSDHLineInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->SeqNo: ", pRspQryNetMemberSDHLineInfo->SeqNo, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->MemContractNo: ", pRspQryNetMemberSDHLineInfo->MemContractNo, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->ApplyPerson: ", pRspQryNetMemberSDHLineInfo->ApplyPerson, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->MonthlyRental: ", pRspQryNetMemberSDHLineInfo->MonthlyRental, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->MemberNo: ", pRspQryNetMemberSDHLineInfo->MemberNo, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->ParticipantName: ", pRspQryNetMemberSDHLineInfo->ParticipantName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->ClientManager: ", pRspQryNetMemberSDHLineInfo->ClientManager, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->Bandwidth: ", pRspQryNetMemberSDHLineInfo->Bandwidth, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->InterfaceType: ", pRspQryNetMemberSDHLineInfo->InterfaceType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->RemoteCircuit: ", pRspQryNetMemberSDHLineInfo->RemoteCircuit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->LocalCircuit: ", pRspQryNetMemberSDHLineInfo->LocalCircuit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->Remark: ", pRspQryNetMemberSDHLineInfo->Remark, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->EndALineAddress: ", pRspQryNetMemberSDHLineInfo->EndALineAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->EndAContact: ", pRspQryNetMemberSDHLineInfo->EndAContact, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->EndZLineAddress: ", pRspQryNetMemberSDHLineInfo->EndZLineAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->ContactName: ", pRspQryNetMemberSDHLineInfo->ContactName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->TELEPHONE: ", pRspQryNetMemberSDHLineInfo->TELEPHONE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->MOBILEPHONE: ", pRspQryNetMemberSDHLineInfo->MOBILEPHONE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->IPADDR: ", pRspQryNetMemberSDHLineInfo->IPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->Interface: ", pRspQryNetMemberSDHLineInfo->Interface, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->PROVINCE: ", pRspQryNetMemberSDHLineInfo->PROVINCE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->StartPortID: ", pRspQryNetMemberSDHLineInfo->StartPortID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->StartJump: ", pRspQryNetMemberSDHLineInfo->StartJump, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->LINE_STATUS: ", pRspQryNetMemberSDHLineInfo->LINE_STATUS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetMemberSDHLineInfo->DataCenterID: ", pRspQryNetMemberSDHLineInfo->DataCenterID, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetMemberSDHLineInfoField* pNewRspQryNetMemberSDHLineInfo = new CShfeFtdcRspQryNetMemberSDHLineInfoField;
    memcpy (pNewRspQryNetMemberSDHLineInfo, pRspQryNetMemberSDHLineInfo, sizeof(CShfeFtdcRspQryNetMemberSDHLineInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetMemberSDHLineInfo;

    uv_mutex_lock (&g_RspQryNetMemberSDHLineInfoTopic_mutex);
    g_RspQryNetMemberSDHLineInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetMemberSDHLineInfoTopic_mutex);

    uv_async_send(&g_RspQryNetMemberSDHLineInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetMemberSDHLineInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetMemberSDHLineInfoTopic(CShfeFtdcRtnNetMemberSDHLineInfoField* pRtnNetMemberSDHLineInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetMemberSDHLineInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetMemberSDHLineInfo) { 
        OutputCallbackMessage("pRtnNetMemberSDHLineInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetMemberSDHLineInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->OperationType: ", pRtnNetMemberSDHLineInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->ID: ", pRtnNetMemberSDHLineInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->SeqNo: ", pRtnNetMemberSDHLineInfo->SeqNo, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->MemContractNo: ", pRtnNetMemberSDHLineInfo->MemContractNo, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->ApplyPerson: ", pRtnNetMemberSDHLineInfo->ApplyPerson, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->MonthlyRental: ", pRtnNetMemberSDHLineInfo->MonthlyRental, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->MemberNo: ", pRtnNetMemberSDHLineInfo->MemberNo, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->ParticipantName: ", pRtnNetMemberSDHLineInfo->ParticipantName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->ClientManager: ", pRtnNetMemberSDHLineInfo->ClientManager, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->Bandwidth: ", pRtnNetMemberSDHLineInfo->Bandwidth, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->InterfaceType: ", pRtnNetMemberSDHLineInfo->InterfaceType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->RemoteCircuit: ", pRtnNetMemberSDHLineInfo->RemoteCircuit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->LocalCircuit: ", pRtnNetMemberSDHLineInfo->LocalCircuit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->Remark: ", pRtnNetMemberSDHLineInfo->Remark, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->EndALineAddress: ", pRtnNetMemberSDHLineInfo->EndALineAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->EndAContact: ", pRtnNetMemberSDHLineInfo->EndAContact, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->EndZLineAddress: ", pRtnNetMemberSDHLineInfo->EndZLineAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->ContactName: ", pRtnNetMemberSDHLineInfo->ContactName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->TELEPHONE: ", pRtnNetMemberSDHLineInfo->TELEPHONE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->MOBILEPHONE: ", pRtnNetMemberSDHLineInfo->MOBILEPHONE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->IPADDR: ", pRtnNetMemberSDHLineInfo->IPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->Interface: ", pRtnNetMemberSDHLineInfo->Interface, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->PROVINCE: ", pRtnNetMemberSDHLineInfo->PROVINCE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->StartPortID: ", pRtnNetMemberSDHLineInfo->StartPortID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->StartJump: ", pRtnNetMemberSDHLineInfo->StartJump, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->LINE_STATUS: ", pRtnNetMemberSDHLineInfo->LINE_STATUS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetMemberSDHLineInfo->DataCenterID: ", pRtnNetMemberSDHLineInfo->DataCenterID, g_RunningResult_File);

    CShfeFtdcRtnNetMemberSDHLineInfoField* pNewRtnNetMemberSDHLineInfo = new CShfeFtdcRtnNetMemberSDHLineInfoField;
    memcpy (pNewRtnNetMemberSDHLineInfo, pRtnNetMemberSDHLineInfo, sizeof(CShfeFtdcRtnNetMemberSDHLineInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetMemberSDHLineInfo;

    uv_mutex_lock (&g_RtnNetMemberSDHLineInfoTopic_mutex);
    g_RtnNetMemberSDHLineInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetMemberSDHLineInfoTopic_mutex);

    uv_async_send(&g_RtnNetMemberSDHLineInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetMemberSDHLineInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetDDNLinkInfoTopic(CShfeFtdcRspQryNetDDNLinkInfoField* pRspQryNetDDNLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetDDNLinkInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetDDNLinkInfo) { 
        OutputCallbackMessage("pRspQryNetDDNLinkInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetDDNLinkInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetDDNLinkInfo->OperationType: ", pRspQryNetDDNLinkInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDDNLinkInfo->ID: ", pRspQryNetDDNLinkInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDDNLinkInfo->ClientName: ", pRspQryNetDDNLinkInfo->ClientName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDDNLinkInfo->DDN_NO: ", pRspQryNetDDNLinkInfo->DDN_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDDNLinkInfo->BusinessUnit: ", pRspQryNetDDNLinkInfo->BusinessUnit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDDNLinkInfo->Bandwidth: ", pRspQryNetDDNLinkInfo->Bandwidth, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDDNLinkInfo->EndAAddress: ", pRspQryNetDDNLinkInfo->EndAAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDDNLinkInfo->EndAContactName: ", pRspQryNetDDNLinkInfo->EndAContactName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDDNLinkInfo->EndZAddress: ", pRspQryNetDDNLinkInfo->EndZAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetDDNLinkInfo->EndZContactName: ", pRspQryNetDDNLinkInfo->EndZContactName, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetDDNLinkInfoField* pNewRspQryNetDDNLinkInfo = new CShfeFtdcRspQryNetDDNLinkInfoField;
    memcpy (pNewRspQryNetDDNLinkInfo, pRspQryNetDDNLinkInfo, sizeof(CShfeFtdcRspQryNetDDNLinkInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetDDNLinkInfo;

    uv_mutex_lock (&g_RspQryNetDDNLinkInfoTopic_mutex);
    g_RspQryNetDDNLinkInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetDDNLinkInfoTopic_mutex);

    uv_async_send(&g_RspQryNetDDNLinkInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetDDNLinkInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetDDNLinkInfoTopic(CShfeFtdcRtnNetDDNLinkInfoField* pRtnNetDDNLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetDDNLinkInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetDDNLinkInfo) { 
        OutputCallbackMessage("pRtnNetDDNLinkInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetDDNLinkInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetDDNLinkInfo->OperationType: ", pRtnNetDDNLinkInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDDNLinkInfo->ID: ", pRtnNetDDNLinkInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDDNLinkInfo->ClientName: ", pRtnNetDDNLinkInfo->ClientName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDDNLinkInfo->DDN_NO: ", pRtnNetDDNLinkInfo->DDN_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDDNLinkInfo->BusinessUnit: ", pRtnNetDDNLinkInfo->BusinessUnit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDDNLinkInfo->Bandwidth: ", pRtnNetDDNLinkInfo->Bandwidth, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDDNLinkInfo->EndAAddress: ", pRtnNetDDNLinkInfo->EndAAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDDNLinkInfo->EndAContactName: ", pRtnNetDDNLinkInfo->EndAContactName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDDNLinkInfo->EndZAddress: ", pRtnNetDDNLinkInfo->EndZAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetDDNLinkInfo->EndZContactName: ", pRtnNetDDNLinkInfo->EndZContactName, g_RunningResult_File);

    CShfeFtdcRtnNetDDNLinkInfoField* pNewRtnNetDDNLinkInfo = new CShfeFtdcRtnNetDDNLinkInfoField;
    memcpy (pNewRtnNetDDNLinkInfo, pRtnNetDDNLinkInfo, sizeof(CShfeFtdcRtnNetDDNLinkInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetDDNLinkInfo;

    uv_mutex_lock (&g_RtnNetDDNLinkInfoTopic_mutex);
    g_RtnNetDDNLinkInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetDDNLinkInfoTopic_mutex);

    uv_async_send(&g_RtnNetDDNLinkInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetDDNLinkInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetPseudMemberLinkInfoTopic(CShfeFtdcRspQryNetPseudMemberLinkInfoField* pRspQryNetPseudMemberLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetPseudMemberLinkInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetPseudMemberLinkInfo) { 
        OutputCallbackMessage("pRspQryNetPseudMemberLinkInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetPseudMemberLinkInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->OperationType: ", pRspQryNetPseudMemberLinkInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->ID: ", pRspQryNetPseudMemberLinkInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->SeqNo: ", pRspQryNetPseudMemberLinkInfo->SeqNo, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->MemContractNo: ", pRspQryNetPseudMemberLinkInfo->MemContractNo, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->LineUsage: ", pRspQryNetPseudMemberLinkInfo->LineUsage, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->LocalCircuit: ", pRspQryNetPseudMemberLinkInfo->LocalCircuit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->RemoteCircuit: ", pRspQryNetPseudMemberLinkInfo->RemoteCircuit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->BusinessUnit: ", pRspQryNetPseudMemberLinkInfo->BusinessUnit, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->Bandwidth: ", pRspQryNetPseudMemberLinkInfo->Bandwidth, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->ApplyPerson: ", pRspQryNetPseudMemberLinkInfo->ApplyPerson, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->MonthlyRental: ", pRspQryNetPseudMemberLinkInfo->MonthlyRental, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->EndAAddress: ", pRspQryNetPseudMemberLinkInfo->EndAAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->EndAContactName: ", pRspQryNetPseudMemberLinkInfo->EndAContactName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->EndZAddress: ", pRspQryNetPseudMemberLinkInfo->EndZAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->EndZContactName: ", pRspQryNetPseudMemberLinkInfo->EndZContactName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->Telephone: ", pRspQryNetPseudMemberLinkInfo->Telephone, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->LineInfo: ", pRspQryNetPseudMemberLinkInfo->LineInfo, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPseudMemberLinkInfo->IPADDR: ", pRspQryNetPseudMemberLinkInfo->IPADDR, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetPseudMemberLinkInfoField* pNewRspQryNetPseudMemberLinkInfo = new CShfeFtdcRspQryNetPseudMemberLinkInfoField;
    memcpy (pNewRspQryNetPseudMemberLinkInfo, pRspQryNetPseudMemberLinkInfo, sizeof(CShfeFtdcRspQryNetPseudMemberLinkInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetPseudMemberLinkInfo;

    uv_mutex_lock (&g_RspQryNetPseudMemberLinkInfoTopic_mutex);
    g_RspQryNetPseudMemberLinkInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetPseudMemberLinkInfoTopic_mutex);

    uv_async_send(&g_RspQryNetPseudMemberLinkInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetPseudMemberLinkInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetPseudMemberLinkInfoTopic(CShfeFtdcRtnNetPseudMemberLinkInfoField* pRtnNetPseudMemberLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetPseudMemberLinkInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetPseudMemberLinkInfo) { 
        OutputCallbackMessage("pRtnNetPseudMemberLinkInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetPseudMemberLinkInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->OperationType: ", pRtnNetPseudMemberLinkInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->ID: ", pRtnNetPseudMemberLinkInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->SeqNo: ", pRtnNetPseudMemberLinkInfo->SeqNo, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->MemContractNo: ", pRtnNetPseudMemberLinkInfo->MemContractNo, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->LineUsage: ", pRtnNetPseudMemberLinkInfo->LineUsage, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->LocalCircuit: ", pRtnNetPseudMemberLinkInfo->LocalCircuit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->RemoteCircuit: ", pRtnNetPseudMemberLinkInfo->RemoteCircuit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->BusinessUnit: ", pRtnNetPseudMemberLinkInfo->BusinessUnit, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->Bandwidth: ", pRtnNetPseudMemberLinkInfo->Bandwidth, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->ApplyPerson: ", pRtnNetPseudMemberLinkInfo->ApplyPerson, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->MonthlyRental: ", pRtnNetPseudMemberLinkInfo->MonthlyRental, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->EndAAddress: ", pRtnNetPseudMemberLinkInfo->EndAAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->EndAContactName: ", pRtnNetPseudMemberLinkInfo->EndAContactName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->EndZAddress: ", pRtnNetPseudMemberLinkInfo->EndZAddress, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->EndZContactName: ", pRtnNetPseudMemberLinkInfo->EndZContactName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->Telephone: ", pRtnNetPseudMemberLinkInfo->Telephone, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->LineInfo: ", pRtnNetPseudMemberLinkInfo->LineInfo, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPseudMemberLinkInfo->IPADDR: ", pRtnNetPseudMemberLinkInfo->IPADDR, g_RunningResult_File);

    CShfeFtdcRtnNetPseudMemberLinkInfoField* pNewRtnNetPseudMemberLinkInfo = new CShfeFtdcRtnNetPseudMemberLinkInfoField;
    memcpy (pNewRtnNetPseudMemberLinkInfo, pRtnNetPseudMemberLinkInfo, sizeof(CShfeFtdcRtnNetPseudMemberLinkInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetPseudMemberLinkInfo;

    uv_mutex_lock (&g_RtnNetPseudMemberLinkInfoTopic_mutex);
    g_RtnNetPseudMemberLinkInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetPseudMemberLinkInfoTopic_mutex);

    uv_async_send(&g_RtnNetPseudMemberLinkInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetPseudMemberLinkInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryOuterDeviceInfTopic(CShfeFtdcRspQryOuterDeviceInfField* pRspQryOuterDeviceInf, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryOuterDeviceInfTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryOuterDeviceInf) { 
        OutputCallbackMessage("pRspQryOuterDeviceInf is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryOuterDeviceInfTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryOuterDeviceInf->OperationType: ", pRspQryOuterDeviceInf->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOuterDeviceInf->ID: ", pRspQryOuterDeviceInf->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOuterDeviceInf->IPADDR: ", pRspQryOuterDeviceInf->IPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOuterDeviceInf->NAME: ", pRspQryOuterDeviceInf->NAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryOuterDeviceInf->memo: ", pRspQryOuterDeviceInf->memo, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryOuterDeviceInfField* pNewRspQryOuterDeviceInf = new CShfeFtdcRspQryOuterDeviceInfField;
    memcpy (pNewRspQryOuterDeviceInf, pRspQryOuterDeviceInf, sizeof(CShfeFtdcRspQryOuterDeviceInfField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryOuterDeviceInf;

    uv_mutex_lock (&g_RspQryOuterDeviceInfTopic_mutex);
    g_RspQryOuterDeviceInfTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryOuterDeviceInfTopic_mutex);

    uv_async_send(&g_RspQryOuterDeviceInfTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryOuterDeviceInfTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetOuterDeviceInfTopic(CShfeFtdcRtnNetOuterDeviceInfField* pRtnNetOuterDeviceInf, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetOuterDeviceInfTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetOuterDeviceInf) { 
        OutputCallbackMessage("pRtnNetOuterDeviceInf is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetOuterDeviceInfTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetOuterDeviceInf->OperationType: ", pRtnNetOuterDeviceInf->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetOuterDeviceInf->ID: ", pRtnNetOuterDeviceInf->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetOuterDeviceInf->IPADDR: ", pRtnNetOuterDeviceInf->IPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetOuterDeviceInf->NAME: ", pRtnNetOuterDeviceInf->NAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetOuterDeviceInf->memo: ", pRtnNetOuterDeviceInf->memo, g_RunningResult_File);

    CShfeFtdcRtnNetOuterDeviceInfField* pNewRtnNetOuterDeviceInf = new CShfeFtdcRtnNetOuterDeviceInfField;
    memcpy (pNewRtnNetOuterDeviceInf, pRtnNetOuterDeviceInf, sizeof(CShfeFtdcRtnNetOuterDeviceInfField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetOuterDeviceInf;

    uv_mutex_lock (&g_RtnNetOuterDeviceInfTopic_mutex);
    g_RtnNetOuterDeviceInfTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetOuterDeviceInfTopic_mutex);

    uv_async_send(&g_RtnNetOuterDeviceInfTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetOuterDeviceInfTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetLocalPingResultInfoTopic(CShfeFtdcRspQryNetLocalPingResultInfoField* pRspQryNetLocalPingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetLocalPingResultInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetLocalPingResultInfo) { 
        OutputCallbackMessage("pRspQryNetLocalPingResultInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetLocalPingResultInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetLocalPingResultInfo->OperationType: ", pRspQryNetLocalPingResultInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetLocalPingResultInfo->ID: ", pRspQryNetLocalPingResultInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetLocalPingResultInfo->SouIPADDR: ", pRspQryNetLocalPingResultInfo->SouIPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetLocalPingResultInfo->SouNAME: ", pRspQryNetLocalPingResultInfo->SouNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetLocalPingResultInfo->TarIPADDR: ", pRspQryNetLocalPingResultInfo->TarIPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetLocalPingResultInfo->TarNAME: ", pRspQryNetLocalPingResultInfo->TarNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetLocalPingResultInfo->PDateSta: ", pRspQryNetLocalPingResultInfo->PDateSta, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetLocalPingResultInfo->PTimeSta: ", pRspQryNetLocalPingResultInfo->PTimeSta, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetLocalPingResultInfo->ConnRate: ", pRspQryNetLocalPingResultInfo->ConnRate, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetLocalPingResultInfoField* pNewRspQryNetLocalPingResultInfo = new CShfeFtdcRspQryNetLocalPingResultInfoField;
    memcpy (pNewRspQryNetLocalPingResultInfo, pRspQryNetLocalPingResultInfo, sizeof(CShfeFtdcRspQryNetLocalPingResultInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetLocalPingResultInfo;

    uv_mutex_lock (&g_RspQryNetLocalPingResultInfoTopic_mutex);
    g_RspQryNetLocalPingResultInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetLocalPingResultInfoTopic_mutex);

    uv_async_send(&g_RspQryNetLocalPingResultInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetLocalPingResultInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetLocalPingResultInfoTopic(CShfeFtdcRtnNetLocalPingResultInfoField* pRtnNetLocalPingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetLocalPingResultInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetLocalPingResultInfo) { 
        OutputCallbackMessage("pRtnNetLocalPingResultInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetLocalPingResultInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetLocalPingResultInfo->OperationType: ", pRtnNetLocalPingResultInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetLocalPingResultInfo->ID: ", pRtnNetLocalPingResultInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetLocalPingResultInfo->SouIPADDR: ", pRtnNetLocalPingResultInfo->SouIPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetLocalPingResultInfo->SouNAME: ", pRtnNetLocalPingResultInfo->SouNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetLocalPingResultInfo->TarIPADDR: ", pRtnNetLocalPingResultInfo->TarIPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetLocalPingResultInfo->TarNAME: ", pRtnNetLocalPingResultInfo->TarNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetLocalPingResultInfo->PDateSta: ", pRtnNetLocalPingResultInfo->PDateSta, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetLocalPingResultInfo->PTimeSta: ", pRtnNetLocalPingResultInfo->PTimeSta, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetLocalPingResultInfo->ConnRate: ", pRtnNetLocalPingResultInfo->ConnRate, g_RunningResult_File);

    CShfeFtdcRtnNetLocalPingResultInfoField* pNewRtnNetLocalPingResultInfo = new CShfeFtdcRtnNetLocalPingResultInfoField;
    memcpy (pNewRtnNetLocalPingResultInfo, pRtnNetLocalPingResultInfo, sizeof(CShfeFtdcRtnNetLocalPingResultInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetLocalPingResultInfo;

    uv_mutex_lock (&g_RtnNetLocalPingResultInfoTopic_mutex);
    g_RtnNetLocalPingResultInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetLocalPingResultInfoTopic_mutex);

    uv_async_send(&g_RtnNetLocalPingResultInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetLocalPingResultInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetRomotePingResultInfoTopic(CShfeFtdcRspQryNetRomotePingResultInfoField* pRspQryNetRomotePingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetRomotePingResultInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetRomotePingResultInfo) { 
        OutputCallbackMessage("pRspQryNetRomotePingResultInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetRomotePingResultInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetRomotePingResultInfo->OperationType: ", pRspQryNetRomotePingResultInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetRomotePingResultInfo->ID: ", pRspQryNetRomotePingResultInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetRomotePingResultInfo->SouIPADDR: ", pRspQryNetRomotePingResultInfo->SouIPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetRomotePingResultInfo->SouNAME: ", pRspQryNetRomotePingResultInfo->SouNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetRomotePingResultInfo->TarIPADDR: ", pRspQryNetRomotePingResultInfo->TarIPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetRomotePingResultInfo->TarNAME: ", pRspQryNetRomotePingResultInfo->TarNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetRomotePingResultInfo->PDateSta: ", pRspQryNetRomotePingResultInfo->PDateSta, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetRomotePingResultInfo->PTimeSta: ", pRspQryNetRomotePingResultInfo->PTimeSta, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetRomotePingResultInfo->ConnRate: ", pRspQryNetRomotePingResultInfo->ConnRate, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetRomotePingResultInfo->TimeDlyMin: ", pRspQryNetRomotePingResultInfo->TimeDlyMin, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetRomotePingResultInfo->TimeDlyMax: ", pRspQryNetRomotePingResultInfo->TimeDlyMax, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetRomotePingResultInfo->TimeDlyAvg: ", pRspQryNetRomotePingResultInfo->TimeDlyAvg, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetRomotePingResultInfoField* pNewRspQryNetRomotePingResultInfo = new CShfeFtdcRspQryNetRomotePingResultInfoField;
    memcpy (pNewRspQryNetRomotePingResultInfo, pRspQryNetRomotePingResultInfo, sizeof(CShfeFtdcRspQryNetRomotePingResultInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetRomotePingResultInfo;

    uv_mutex_lock (&g_RspQryNetRomotePingResultInfoTopic_mutex);
    g_RspQryNetRomotePingResultInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetRomotePingResultInfoTopic_mutex);

    uv_async_send(&g_RspQryNetRomotePingResultInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetRomotePingResultInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetRomotePingResultInfoTopic(CShfeFtdcRtnNetRomotePingResultInfoField* pRtnNetRomotePingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetRomotePingResultInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetRomotePingResultInfo) { 
        OutputCallbackMessage("pRtnNetRomotePingResultInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetRomotePingResultInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetRomotePingResultInfo->OperationType: ", pRtnNetRomotePingResultInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetRomotePingResultInfo->ID: ", pRtnNetRomotePingResultInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetRomotePingResultInfo->SouIPADDR: ", pRtnNetRomotePingResultInfo->SouIPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetRomotePingResultInfo->SouNAME: ", pRtnNetRomotePingResultInfo->SouNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetRomotePingResultInfo->TarIPADDR: ", pRtnNetRomotePingResultInfo->TarIPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetRomotePingResultInfo->TarNAME: ", pRtnNetRomotePingResultInfo->TarNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetRomotePingResultInfo->PDateSta: ", pRtnNetRomotePingResultInfo->PDateSta, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetRomotePingResultInfo->PTimeSta: ", pRtnNetRomotePingResultInfo->PTimeSta, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetRomotePingResultInfo->ConnRate: ", pRtnNetRomotePingResultInfo->ConnRate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetRomotePingResultInfo->TimeDlyMin: ", pRtnNetRomotePingResultInfo->TimeDlyMin, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetRomotePingResultInfo->TimeDlyMax: ", pRtnNetRomotePingResultInfo->TimeDlyMax, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetRomotePingResultInfo->TimeDlyAvg: ", pRtnNetRomotePingResultInfo->TimeDlyAvg, g_RunningResult_File);

    CShfeFtdcRtnNetRomotePingResultInfoField* pNewRtnNetRomotePingResultInfo = new CShfeFtdcRtnNetRomotePingResultInfoField;
    memcpy (pNewRtnNetRomotePingResultInfo, pRtnNetRomotePingResultInfo, sizeof(CShfeFtdcRtnNetRomotePingResultInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetRomotePingResultInfo;

    uv_mutex_lock (&g_RtnNetRomotePingResultInfoTopic_mutex);
    g_RtnNetRomotePingResultInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetRomotePingResultInfoTopic_mutex);

    uv_async_send(&g_RtnNetRomotePingResultInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetRomotePingResultInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnMonitorTopProcessInfo(CShfeFtdcRtnMonitorTopProcessInfoField* pRtnMonitorTopProcessInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnMonitorTopProcessInfo: START! ******", g_RunningResult_File);

    if (NULL == pRtnMonitorTopProcessInfo) { 
        OutputCallbackMessage("pRtnMonitorTopProcessInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnMonitorTopProcessInfo: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnMonitorTopProcessInfo->HostName: ", pRtnMonitorTopProcessInfo->HostName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorTopProcessInfo->MonDate: ", pRtnMonitorTopProcessInfo->MonDate, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorTopProcessInfo->MonTime: ", pRtnMonitorTopProcessInfo->MonTime, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorTopProcessInfo->CPU: ", pRtnMonitorTopProcessInfo->CPU, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorTopProcessInfo->TTY: ", pRtnMonitorTopProcessInfo->TTY, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorTopProcessInfo->PID: ", pRtnMonitorTopProcessInfo->PID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorTopProcessInfo->USERNAME: ", pRtnMonitorTopProcessInfo->USERNAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorTopProcessInfo->PRI: ", pRtnMonitorTopProcessInfo->PRI, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorTopProcessInfo->NI: ", pRtnMonitorTopProcessInfo->NI, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorTopProcessInfo->SSIZE: ", pRtnMonitorTopProcessInfo->SSIZE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorTopProcessInfo->RES: ", pRtnMonitorTopProcessInfo->RES, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorTopProcessInfo->STATE: ", pRtnMonitorTopProcessInfo->STATE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorTopProcessInfo->STIME: ", pRtnMonitorTopProcessInfo->STIME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorTopProcessInfo->pWCPU: ", pRtnMonitorTopProcessInfo->pWCPU, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorTopProcessInfo->pCPU: ", pRtnMonitorTopProcessInfo->pCPU, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMonitorTopProcessInfo->COMMAND: ", pRtnMonitorTopProcessInfo->COMMAND, g_RunningResult_File);

    CShfeFtdcRtnMonitorTopProcessInfoField* pNewRtnMonitorTopProcessInfo = new CShfeFtdcRtnMonitorTopProcessInfoField;
    memcpy (pNewRtnMonitorTopProcessInfo, pRtnMonitorTopProcessInfo, sizeof(CShfeFtdcRtnMonitorTopProcessInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnMonitorTopProcessInfo;

    uv_mutex_lock (&g_RtnMonitorTopProcessInfo_mutex);
    g_RtnMonitorTopProcessInfo_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnMonitorTopProcessInfo_mutex);

    uv_async_send(&g_RtnMonitorTopProcessInfo_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnMonitorTopProcessInfo: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQrySysInternalTopologyTopic(CShfeFtdcRspQrySysInternalTopologyField* pRspQrySysInternalTopology, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQrySysInternalTopologyTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQrySysInternalTopology) { 
        OutputCallbackMessage("pRspQrySysInternalTopology is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQrySysInternalTopologyTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQrySysInternalTopology->InfoType: ", pRspQrySysInternalTopology->InfoType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySysInternalTopology->Node1_ID: ", pRspQrySysInternalTopology->Node1_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySysInternalTopology->Node1_Info: ", pRspQrySysInternalTopology->Node1_Info, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySysInternalTopology->LinkInfo: ", pRspQrySysInternalTopology->LinkInfo, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySysInternalTopology->LinkState: ", pRspQrySysInternalTopology->LinkState, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySysInternalTopology->Node2_ID: ", pRspQrySysInternalTopology->Node2_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQrySysInternalTopology->Node2_Info: ", pRspQrySysInternalTopology->Node2_Info, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQrySysInternalTopologyField* pNewRspQrySysInternalTopology = new CShfeFtdcRspQrySysInternalTopologyField;
    memcpy (pNewRspQrySysInternalTopology, pRspQrySysInternalTopology, sizeof(CShfeFtdcRspQrySysInternalTopologyField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQrySysInternalTopology;

    uv_mutex_lock (&g_RspQrySysInternalTopologyTopic_mutex);
    g_RspQrySysInternalTopologyTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQrySysInternalTopologyTopic_mutex);

    uv_async_send(&g_RspQrySysInternalTopologyTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQrySysInternalTopologyTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnSysInternalTopologyTopic(CShfeFtdcRtnSysInternalTopologyField* pRtnSysInternalTopology, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnSysInternalTopologyTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnSysInternalTopology) { 
        OutputCallbackMessage("pRtnSysInternalTopology is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnSysInternalTopologyTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnSysInternalTopology->InfoType: ", pRtnSysInternalTopology->InfoType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysInternalTopology->Node1_ID: ", pRtnSysInternalTopology->Node1_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysInternalTopology->Node1_Info: ", pRtnSysInternalTopology->Node1_Info, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysInternalTopology->LinkInfo: ", pRtnSysInternalTopology->LinkInfo, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysInternalTopology->LinkState: ", pRtnSysInternalTopology->LinkState, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysInternalTopology->Node2_ID: ", pRtnSysInternalTopology->Node2_ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnSysInternalTopology->Node2_Info: ", pRtnSysInternalTopology->Node2_Info, g_RunningResult_File);

    CShfeFtdcRtnSysInternalTopologyField* pNewRtnSysInternalTopology = new CShfeFtdcRtnSysInternalTopologyField;
    memcpy (pNewRtnSysInternalTopology, pRtnSysInternalTopology, sizeof(CShfeFtdcRtnSysInternalTopologyField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnSysInternalTopology;

    uv_mutex_lock (&g_RtnSysInternalTopologyTopic_mutex);
    g_RtnSysInternalTopologyTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnSysInternalTopologyTopic_mutex);

    uv_async_send(&g_RtnSysInternalTopologyTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnSysInternalTopologyTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryMemberLinkCostTopic(CShfeFtdcRspQryMemberLinkCostField* pRspQryMemberLinkCost, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryMemberLinkCostTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryMemberLinkCost) { 
        OutputCallbackMessage("pRspQryMemberLinkCost is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryMemberLinkCostTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryMemberLinkCost->OperationType: ", pRspQryMemberLinkCost->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemberLinkCost->ID: ", pRspQryMemberLinkCost->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemberLinkCost->ParticipantName: ", pRspQryMemberLinkCost->ParticipantName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemberLinkCost->DDN_NO: ", pRspQryMemberLinkCost->DDN_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemberLinkCost->ServiceProvider: ", pRspQryMemberLinkCost->ServiceProvider, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemberLinkCost->Pay_Date: ", pRspQryMemberLinkCost->Pay_Date, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemberLinkCost->B_Pay_Date: ", pRspQryMemberLinkCost->B_Pay_Date, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemberLinkCost->D_Pay_Date: ", pRspQryMemberLinkCost->D_Pay_Date, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemberLinkCost->Charge: ", pRspQryMemberLinkCost->Charge, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemberLinkCost->Fee_Type: ", pRspQryMemberLinkCost->Fee_Type, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryMemberLinkCost->Pro: ", pRspQryMemberLinkCost->Pro, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryMemberLinkCostField* pNewRspQryMemberLinkCost = new CShfeFtdcRspQryMemberLinkCostField;
    memcpy (pNewRspQryMemberLinkCost, pRspQryMemberLinkCost, sizeof(CShfeFtdcRspQryMemberLinkCostField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryMemberLinkCost;

    uv_mutex_lock (&g_RspQryMemberLinkCostTopic_mutex);
    g_RspQryMemberLinkCostTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryMemberLinkCostTopic_mutex);

    uv_async_send(&g_RspQryMemberLinkCostTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryMemberLinkCostTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnMemberLinkCostTopic(CShfeFtdcRtnMemberLinkCostField* pRtnMemberLinkCost, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnMemberLinkCostTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnMemberLinkCost) { 
        OutputCallbackMessage("pRtnMemberLinkCost is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnMemberLinkCostTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnMemberLinkCost->OperationType: ", pRtnMemberLinkCost->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemberLinkCost->ID: ", pRtnMemberLinkCost->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemberLinkCost->ParticipantName: ", pRtnMemberLinkCost->ParticipantName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemberLinkCost->DDN_NO: ", pRtnMemberLinkCost->DDN_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemberLinkCost->ServiceProvider: ", pRtnMemberLinkCost->ServiceProvider, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemberLinkCost->Pay_Date: ", pRtnMemberLinkCost->Pay_Date, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemberLinkCost->B_Pay_Date: ", pRtnMemberLinkCost->B_Pay_Date, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemberLinkCost->D_Pay_Date: ", pRtnMemberLinkCost->D_Pay_Date, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemberLinkCost->Charge: ", pRtnMemberLinkCost->Charge, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemberLinkCost->Fee_Type: ", pRtnMemberLinkCost->Fee_Type, g_RunningResult_File);
    OutputCallbackMessage(" pRtnMemberLinkCost->Pro: ", pRtnMemberLinkCost->Pro, g_RunningResult_File);

    CShfeFtdcRtnMemberLinkCostField* pNewRtnMemberLinkCost = new CShfeFtdcRtnMemberLinkCostField;
    memcpy (pNewRtnMemberLinkCost, pRtnMemberLinkCost, sizeof(CShfeFtdcRtnMemberLinkCostField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnMemberLinkCost;

    uv_mutex_lock (&g_RtnMemberLinkCostTopic_mutex);
    g_RtnMemberLinkCostTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnMemberLinkCostTopic_mutex);

    uv_async_send(&g_RtnMemberLinkCostTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnMemberLinkCostTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetPartylinkMonthlyRentTopic(CShfeFtdcRspQryNetPartylinkMonthlyRentField* pRspQryNetPartylinkMonthlyRent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetPartylinkMonthlyRentTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetPartylinkMonthlyRent) { 
        OutputCallbackMessage("pRspQryNetPartylinkMonthlyRent is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetPartylinkMonthlyRentTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetPartylinkMonthlyRent->OperationType: ", pRspQryNetPartylinkMonthlyRent->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartylinkMonthlyRent->ID: ", pRspQryNetPartylinkMonthlyRent->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartylinkMonthlyRent->LineName: ", pRspQryNetPartylinkMonthlyRent->LineName, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartylinkMonthlyRent->DDN_NO: ", pRspQryNetPartylinkMonthlyRent->DDN_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartylinkMonthlyRent->ServiceProvider: ", pRspQryNetPartylinkMonthlyRent->ServiceProvider, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartylinkMonthlyRent->MonthlyRental: ", pRspQryNetPartylinkMonthlyRent->MonthlyRental, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetPartylinkMonthlyRent->Remark: ", pRspQryNetPartylinkMonthlyRent->Remark, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetPartylinkMonthlyRentField* pNewRspQryNetPartylinkMonthlyRent = new CShfeFtdcRspQryNetPartylinkMonthlyRentField;
    memcpy (pNewRspQryNetPartylinkMonthlyRent, pRspQryNetPartylinkMonthlyRent, sizeof(CShfeFtdcRspQryNetPartylinkMonthlyRentField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetPartylinkMonthlyRent;

    uv_mutex_lock (&g_RspQryNetPartylinkMonthlyRentTopic_mutex);
    g_RspQryNetPartylinkMonthlyRentTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetPartylinkMonthlyRentTopic_mutex);

    uv_async_send(&g_RspQryNetPartylinkMonthlyRentTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetPartylinkMonthlyRentTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetPartylinkMonthlyRentTopic(CShfeFtdcRtnNetPartylinkMonthlyRentField* pRtnNetPartylinkMonthlyRent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetPartylinkMonthlyRentTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetPartylinkMonthlyRent) { 
        OutputCallbackMessage("pRtnNetPartylinkMonthlyRent is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetPartylinkMonthlyRentTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetPartylinkMonthlyRent->OperationType: ", pRtnNetPartylinkMonthlyRent->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartylinkMonthlyRent->ID: ", pRtnNetPartylinkMonthlyRent->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartylinkMonthlyRent->LineName: ", pRtnNetPartylinkMonthlyRent->LineName, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartylinkMonthlyRent->DDN_NO: ", pRtnNetPartylinkMonthlyRent->DDN_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartylinkMonthlyRent->ServiceProvider: ", pRtnNetPartylinkMonthlyRent->ServiceProvider, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartylinkMonthlyRent->MonthlyRental: ", pRtnNetPartylinkMonthlyRent->MonthlyRental, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetPartylinkMonthlyRent->Remark: ", pRtnNetPartylinkMonthlyRent->Remark, g_RunningResult_File);

    CShfeFtdcRtnNetPartylinkMonthlyRentField* pNewRtnNetPartylinkMonthlyRent = new CShfeFtdcRtnNetPartylinkMonthlyRentField;
    memcpy (pNewRtnNetPartylinkMonthlyRent, pRtnNetPartylinkMonthlyRent, sizeof(CShfeFtdcRtnNetPartylinkMonthlyRentField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetPartylinkMonthlyRent;

    uv_mutex_lock (&g_RtnNetPartylinkMonthlyRentTopic_mutex);
    g_RtnNetPartylinkMonthlyRentTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetPartylinkMonthlyRentTopic_mutex);

    uv_async_send(&g_RtnNetPartylinkMonthlyRentTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetPartylinkMonthlyRentTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQryNetNonPartyLinkInfoTopic(CShfeFtdcRspQryNetNonPartyLinkInfoField* pRspQryNetNonPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQryNetNonPartyLinkInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRspQryNetNonPartyLinkInfo) { 
        OutputCallbackMessage("pRspQryNetNonPartyLinkInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RspQryNetNonPartyLinkInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->OperationType: ", pRspQryNetNonPartyLinkInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->ID: ", pRspQryNetNonPartyLinkInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->MEMBER_NO: ", pRspQryNetNonPartyLinkInfo->MEMBER_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->MEMBER_NAME: ", pRspQryNetNonPartyLinkInfo->MEMBER_NAME, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->REMOTE_ADDR: ", pRspQryNetNonPartyLinkInfo->REMOTE_ADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->LOCAL_ADDR: ", pRspQryNetNonPartyLinkInfo->LOCAL_ADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->ADDRESS: ", pRspQryNetNonPartyLinkInfo->ADDRESS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->LINE_STATUS: ", pRspQryNetNonPartyLinkInfo->LINE_STATUS, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->CONTACT: ", pRspQryNetNonPartyLinkInfo->CONTACT, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->TELEPHONE: ", pRspQryNetNonPartyLinkInfo->TELEPHONE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->MOBILEPHONE: ", pRspQryNetNonPartyLinkInfo->MOBILEPHONE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->EMAIL: ", pRspQryNetNonPartyLinkInfo->EMAIL, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->FAX: ", pRspQryNetNonPartyLinkInfo->FAX, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->PROVINCE: ", pRspQryNetNonPartyLinkInfo->PROVINCE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->DDN_NO: ", pRspQryNetNonPartyLinkInfo->DDN_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->IN_MODE: ", pRspQryNetNonPartyLinkInfo->IN_MODE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->IP_WAN: ", pRspQryNetNonPartyLinkInfo->IP_WAN, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->IP_LAN: ", pRspQryNetNonPartyLinkInfo->IP_LAN, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->IPADDR: ", pRspQryNetNonPartyLinkInfo->IPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->Interface: ", pRspQryNetNonPartyLinkInfo->Interface, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->INTERFACE_DATE: ", pRspQryNetNonPartyLinkInfo->INTERFACE_DATE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->SOFTWARE: ", pRspQryNetNonPartyLinkInfo->SOFTWARE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->FEE_TYPE: ", pRspQryNetNonPartyLinkInfo->FEE_TYPE, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->SERVICEPROVIDER: ", pRspQryNetNonPartyLinkInfo->SERVICEPROVIDER, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->IF_ZIYING: ", pRspQryNetNonPartyLinkInfo->IF_ZIYING, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->IF_TUOGUAN: ", pRspQryNetNonPartyLinkInfo->IF_TUOGUAN, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->HASOTHER: ", pRspQryNetNonPartyLinkInfo->HASOTHER, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->SEAT_NO: ", pRspQryNetNonPartyLinkInfo->SEAT_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRspQryNetNonPartyLinkInfo->PRO: ", pRspQryNetNonPartyLinkInfo->PRO, g_RunningResult_File);

    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    CShfeFtdcRspQryNetNonPartyLinkInfoField* pNewRspQryNetNonPartyLinkInfo = new CShfeFtdcRspQryNetNonPartyLinkInfoField;
    memcpy (pNewRspQryNetNonPartyLinkInfo, pRspQryNetNonPartyLinkInfo, sizeof(CShfeFtdcRspQryNetNonPartyLinkInfoField));

    int*  pId = new int(nRequestID);
    bool* bIsLastNew = new bool(bIsLast);
    void** paramArray = new void*[4];
    
    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    paramArray[0] = (void*)pNewRspQryNetNonPartyLinkInfo;

    uv_mutex_lock (&g_RspQryNetNonPartyLinkInfoTopic_mutex);
    g_RspQryNetNonPartyLinkInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQryNetNonPartyLinkInfoTopic_mutex);

    uv_async_send(&g_RspQryNetNonPartyLinkInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQryNetNonPartyLinkInfoTopic: END! ******\n", g_RunningResult_File);
}

void SysUserSpi::OnRtnNetNonPartyLinkInfoTopic(CShfeFtdcRtnNetNonPartyLinkInfoField* pRtnNetNonPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RtnNetNonPartyLinkInfoTopic: START! ******", g_RunningResult_File);

    if (NULL == pRtnNetNonPartyLinkInfo) { 
        OutputCallbackMessage("pRtnNetNonPartyLinkInfo is NULL" , g_RunningResult_File); 
        OutputCallbackMessage("****** SysUserSpi:: RtnNetNonPartyLinkInfoTopic: END! ******\n", g_RunningResult_File); 
        return;
    }

    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->OperationType: ", pRtnNetNonPartyLinkInfo->OperationType, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->ID: ", pRtnNetNonPartyLinkInfo->ID, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->MEMBER_NO: ", pRtnNetNonPartyLinkInfo->MEMBER_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->MEMBER_NAME: ", pRtnNetNonPartyLinkInfo->MEMBER_NAME, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->REMOTE_ADDR: ", pRtnNetNonPartyLinkInfo->REMOTE_ADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->LOCAL_ADDR: ", pRtnNetNonPartyLinkInfo->LOCAL_ADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->ADDRESS: ", pRtnNetNonPartyLinkInfo->ADDRESS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->LINE_STATUS: ", pRtnNetNonPartyLinkInfo->LINE_STATUS, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->CONTACT: ", pRtnNetNonPartyLinkInfo->CONTACT, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->TELEPHONE: ", pRtnNetNonPartyLinkInfo->TELEPHONE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->MOBILEPHONE: ", pRtnNetNonPartyLinkInfo->MOBILEPHONE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->EMAIL: ", pRtnNetNonPartyLinkInfo->EMAIL, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->FAX: ", pRtnNetNonPartyLinkInfo->FAX, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->PROVINCE: ", pRtnNetNonPartyLinkInfo->PROVINCE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->DDN_NO: ", pRtnNetNonPartyLinkInfo->DDN_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->IN_MODE: ", pRtnNetNonPartyLinkInfo->IN_MODE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->IP_WAN: ", pRtnNetNonPartyLinkInfo->IP_WAN, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->IP_LAN: ", pRtnNetNonPartyLinkInfo->IP_LAN, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->IPADDR: ", pRtnNetNonPartyLinkInfo->IPADDR, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->Interface: ", pRtnNetNonPartyLinkInfo->Interface, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->INTERFACE_DATE: ", pRtnNetNonPartyLinkInfo->INTERFACE_DATE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->SOFTWARE: ", pRtnNetNonPartyLinkInfo->SOFTWARE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->FEE_TYPE: ", pRtnNetNonPartyLinkInfo->FEE_TYPE, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->SERVICEPROVIDER: ", pRtnNetNonPartyLinkInfo->SERVICEPROVIDER, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->IF_ZIYING: ", pRtnNetNonPartyLinkInfo->IF_ZIYING, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->IF_TUOGUAN: ", pRtnNetNonPartyLinkInfo->IF_TUOGUAN, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->HASOTHER: ", pRtnNetNonPartyLinkInfo->HASOTHER, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->SEAT_NO: ", pRtnNetNonPartyLinkInfo->SEAT_NO, g_RunningResult_File);
    OutputCallbackMessage(" pRtnNetNonPartyLinkInfo->PRO: ", pRtnNetNonPartyLinkInfo->PRO, g_RunningResult_File);

    CShfeFtdcRtnNetNonPartyLinkInfoField* pNewRtnNetNonPartyLinkInfo = new CShfeFtdcRtnNetNonPartyLinkInfoField;
    memcpy (pNewRtnNetNonPartyLinkInfo, pRtnNetNonPartyLinkInfo, sizeof(CShfeFtdcRtnNetNonPartyLinkInfoField));
    void** paramArray = new void*[1];
    paramArray[0] = (void*)pNewRtnNetNonPartyLinkInfo;

    uv_mutex_lock (&g_RtnNetNonPartyLinkInfoTopic_mutex);
    g_RtnNetNonPartyLinkInfoTopic_queue.push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RtnNetNonPartyLinkInfoTopic_mutex);

    uv_async_send(&g_RtnNetNonPartyLinkInfoTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RtnNetNonPartyLinkInfoTopic: END! ******\n", g_RunningResult_File);
}



