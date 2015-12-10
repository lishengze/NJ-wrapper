
 #include "SysUserSpi.h"
 #include <iostream>
 #include "SpiCFunc.h"
 #include <vector>
 #include <string>
 #include <sstream>
 #include <memory.h>
 using std::cin;
 using std::cout;
 using std::endl;
 using namespace std;
 
 int g_OnRtnSyslogEventTopic_Sys_numb = 0;
 int g_OnRtnNetPartyLinkStatusInfoTopic_Sys_Numb = 0;
 
 void SysUserSpi::OnFrontConnected(){
     cout << "SysUserSpi::OnFrontConnected()"<< endl;
     // uv_async_send(&async);
 }
void SysUserSpi::OnFrontDisConnected(int nReason){
      cout << "SysUserSpi::OnFrontDisConnected()!"<< endl;
      asyncOnFrontDisconnected.data=(void*)nReason;
      // uv_async_send(&asyncOnFrontDisconnected);
 }
void SysUserSpi::OnHeartBeatWarning(int nTimeLapse){
    cout << "SysUserSpi::OnHeartBeatWarning()!"<< endl;
    asyncOnHeartBeatWarning.data=(void*)nTimeLapse;
    // uv_async_send(&asyncOnHeartBeatWarning);
}
 //以下自动生成
void SysUserSpi::OnRspQryTopCpuInfoTopic(CShfeFtdcRspQryTopCpuInfoField *pRspQryTopCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryTopCpuInfo->HostName:"<<pRspQryTopCpuInfo->HostName<< endl;
  cout << "on pRspQryTopCpuInfo->MonDate:"<<pRspQryTopCpuInfo->MonDate<< endl;
  cout << "on pRspQryTopCpuInfo->MonTime:"<<pRspQryTopCpuInfo->MonTime<< endl;
  cout << "on pRspQryTopCpuInfo->CPU:"<<pRspQryTopCpuInfo->CPU<< endl;
  cout << "on pRspQryTopCpuInfo->LOAD:"<<pRspQryTopCpuInfo->LOAD<< endl;
  cout << "on pRspQryTopCpuInfo->USER:"<<pRspQryTopCpuInfo->USER<< endl;
  cout << "on pRspQryTopCpuInfo->NICE:"<<pRspQryTopCpuInfo->NICE<< endl;
  cout << "on pRspQryTopCpuInfo->SYS:"<<pRspQryTopCpuInfo->SYS<< endl;
  cout << "on pRspQryTopCpuInfo->IDLE:"<<pRspQryTopCpuInfo->IDLE<< endl;
  cout << "on pRspQryTopCpuInfo->BLOCK:"<<pRspQryTopCpuInfo->BLOCK<< endl;
  cout << "on pRspQryTopCpuInfo->SWAIT:"<<pRspQryTopCpuInfo->SWAIT<< endl;
  cout << "on pRspQryTopCpuInfo->INTR:"<<pRspQryTopCpuInfo->INTR<< endl;
  cout << "on pRspQryTopCpuInfo->SSYS:"<<pRspQryTopCpuInfo->SSYS<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryTopCpuInfoField* pNewRspQryTopCpuInfo =new CShfeFtdcRspQryTopCpuInfoField;
  memcpy(pNewRspQryTopCpuInfo,pRspQryTopCpuInfo,sizeof(CShfeFtdcRspQryTopCpuInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTopCpuInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTopCpuInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryTopCpuInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnTopCpuInfoTopic(CShfeFtdcRtnTopCpuInfoField *pRtnTopCpuInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnTopCpuInfo->HostName:"<<pRtnTopCpuInfo->HostName<< endl;
  cout << "on pRtnTopCpuInfo->MonDate:"<<pRtnTopCpuInfo->MonDate<< endl;
  cout << "on pRtnTopCpuInfo->MonTime:"<<pRtnTopCpuInfo->MonTime<< endl;
  cout << "on pRtnTopCpuInfo->CPU:"<<pRtnTopCpuInfo->CPU<< endl;
  cout << "on pRtnTopCpuInfo->LOAD:"<<pRtnTopCpuInfo->LOAD<< endl;
  cout << "on pRtnTopCpuInfo->USER:"<<pRtnTopCpuInfo->USER<< endl;
  cout << "on pRtnTopCpuInfo->NICE:"<<pRtnTopCpuInfo->NICE<< endl;
  cout << "on pRtnTopCpuInfo->SYS:"<<pRtnTopCpuInfo->SYS<< endl;
  cout << "on pRtnTopCpuInfo->IDLE:"<<pRtnTopCpuInfo->IDLE<< endl;
  cout << "on pRtnTopCpuInfo->BLOCK:"<<pRtnTopCpuInfo->BLOCK<< endl;
  cout << "on pRtnTopCpuInfo->SWAIT:"<<pRtnTopCpuInfo->SWAIT<< endl;
  cout << "on pRtnTopCpuInfo->INTR:"<<pRtnTopCpuInfo->INTR<< endl;
  cout << "on pRtnTopCpuInfo->SSYS:"<<pRtnTopCpuInfo->SSYS<< endl;
  CShfeFtdcRtnTopCpuInfoField* pNewRtnTopCpuInfo =new CShfeFtdcRtnTopCpuInfoField;
  memcpy(pNewRtnTopCpuInfo,pRtnTopCpuInfo,sizeof(CShfeFtdcRtnTopCpuInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnTopCpuInfo;
  asyncOnRtnTopCpuInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnTopCpuInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryTopMemInfoTopic(CShfeFtdcRspQryTopMemInfoField *pRspQryTopMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  try {
  cout << "\n******* SysUserSpi::OnRspQryTopMemInfoTopic: START *******"<< endl;
  
  if (NULL == pRspQryTopMemInfo) {
    cout << "pRspQryTopMemInfo is NULL" << endl;
    
    if (NULL != pRspInfo) {
      cout << "pRspInfo->ErrorID: " << pRspInfo->ErrorID << endl;
      cout << "pRspInfo->ErrorMsg: " << pRspInfo->ErrorMsg << endl;
    }
    
  } else {
    
     std::cout << "Data in pRspQryTopMemInfo: " << * (char*)(pRspQryTopMemInfo) << endl;
  cout << "on pRspQryTopMemInfo->HostName:"<<pRspQryTopMemInfo->HostName  << endl;
  cout << "on pRspQryTopMemInfo->MonDate:"<<pRspQryTopMemInfo->MonDate<< endl;
  cout << "on pRspQryTopMemInfo->MonTime:"<<pRspQryTopMemInfo->MonTime<< endl;
  cout << "on pRspQryTopMemInfo->TOTALREAL:"<<pRspQryTopMemInfo->TOTALREAL<< endl;
  cout << "on pRspQryTopMemInfo->ACTIVEREAL:"<<pRspQryTopMemInfo->ACTIVEREAL<< endl;
  cout << "on pRspQryTopMemInfo->TOTALVIRTUAL:"<<pRspQryTopMemInfo->TOTALVIRTUAL<< endl;
  cout << "on pRspQryTopMemInfo->ACTIVEVIRTUAL:"<<pRspQryTopMemInfo->ACTIVEVIRTUAL<< endl;
  cout << "on pRspQryTopMemInfo->FREE:"<<pRspQryTopMemInfo->FREE<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;

  CShfeFtdcRspQryTopMemInfoField* pNewRspQryTopMemInfo =new CShfeFtdcRspQryTopMemInfoField;  
    
  memcpy(pNewRspQryTopMemInfo,pRspQryTopMemInfo,sizeof(CShfeFtdcRspQryTopMemInfoField));
  
//  cout << "memcpy done!" << endl;
  
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTopMemInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    asyncOnRspQryTopMemInfoTopic.data=(void*)&paramArray[0];
    // uv_async_send(&asyncOnRspQryTopMemInfoTopic);
     cout << "******* SysUserSpi::OnRspQryTopMemInfoTopic: START *******\n"<< endl;      
   }  
   
  } catch (char *str) {  
        cout << "error: " << str << endl;  
  } catch (exception& error) {
    
    std::cout << "Standard exception: " << error.what() << std::endl;  
  }
  
}
void SysUserSpi::OnRtnTopMemInfoTopic(CShfeFtdcRtnTopMemInfoField *pRtnTopMemInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnTopMemInfo->HostName:"<<pRtnTopMemInfo->HostName<< endl;
  cout << "on pRtnTopMemInfo->MonDate:"<<pRtnTopMemInfo->MonDate<< endl;
  cout << "on pRtnTopMemInfo->MonTime:"<<pRtnTopMemInfo->MonTime<< endl;
  cout << "on pRtnTopMemInfo->TOTALREAL:"<<pRtnTopMemInfo->TOTALREAL<< endl;
  cout << "on pRtnTopMemInfo->ACTIVEREAL:"<<pRtnTopMemInfo->ACTIVEREAL<< endl;
  cout << "on pRtnTopMemInfo->TOTALVIRTUAL:"<<pRtnTopMemInfo->TOTALVIRTUAL<< endl;
  cout << "on pRtnTopMemInfo->ACTIVEVIRTUAL:"<<pRtnTopMemInfo->ACTIVEVIRTUAL<< endl;
  cout << "on pRtnTopMemInfo->FREE:"<<pRtnTopMemInfo->FREE<< endl;
  CShfeFtdcRtnTopMemInfoField* pNewRtnTopMemInfo =new CShfeFtdcRtnTopMemInfoField;
  memcpy(pNewRtnTopMemInfo,pRtnTopMemInfo,sizeof(CShfeFtdcRtnTopMemInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnTopMemInfo;
  asyncOnRtnTopMemInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnTopMemInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryTopProcessInfoTopic(CShfeFtdcRspQryTopProcessInfoField *pRspQryTopProcessInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryTopProcessInfo->HostName:"<<pRspQryTopProcessInfo->HostName<< endl;
  cout << "on pRspQryTopProcessInfo->MonDate:"<<pRspQryTopProcessInfo->MonDate<< endl;
  cout << "on pRspQryTopProcessInfo->MonTime:"<<pRspQryTopProcessInfo->MonTime<< endl;
  cout << "on pRspQryTopProcessInfo->CPU:"<<pRspQryTopProcessInfo->CPU<< endl;
  cout << "on pRspQryTopProcessInfo->TTY:"<<pRspQryTopProcessInfo->TTY<< endl;
  cout << "on pRspQryTopProcessInfo->PID:"<<pRspQryTopProcessInfo->PID<< endl;
  cout << "on pRspQryTopProcessInfo->USERNAME:"<<pRspQryTopProcessInfo->USERNAME<< endl;
  cout << "on pRspQryTopProcessInfo->PRI:"<<pRspQryTopProcessInfo->PRI<< endl;
  cout << "on pRspQryTopProcessInfo->NI:"<<pRspQryTopProcessInfo->NI<< endl;
  cout << "on pRspQryTopProcessInfo->SIZE:"<<pRspQryTopProcessInfo->SIZE<< endl;
  cout << "on pRspQryTopProcessInfo->RES:"<<pRspQryTopProcessInfo->RES<< endl;
  cout << "on pRspQryTopProcessInfo->STATE:"<<pRspQryTopProcessInfo->STATE<< endl;
  cout << "on pRspQryTopProcessInfo->TIME:"<<pRspQryTopProcessInfo->TIME<< endl;
  cout << "on pRspQryTopProcessInfo->pWCPU:"<<pRspQryTopProcessInfo->pWCPU<< endl;
  cout << "on pRspQryTopProcessInfo->pCPU:"<<pRspQryTopProcessInfo->pCPU<< endl;
  cout << "on pRspQryTopProcessInfo->COMMAND:"<<pRspQryTopProcessInfo->COMMAND<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryTopProcessInfoField* pNewRspQryTopProcessInfo =new CShfeFtdcRspQryTopProcessInfoField;
  memcpy(pNewRspQryTopProcessInfo,pRspQryTopProcessInfo,sizeof(CShfeFtdcRspQryTopProcessInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTopProcessInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTopProcessInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryTopProcessInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnTopProcessInfoTopic(CShfeFtdcRtnTopProcessInfoField *pRtnTopProcessInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnTopProcessInfo->HostName:"<<pRtnTopProcessInfo->HostName<< endl;
  cout << "on pRtnTopProcessInfo->MonDate:"<<pRtnTopProcessInfo->MonDate<< endl;
  cout << "on pRtnTopProcessInfo->MonTime:"<<pRtnTopProcessInfo->MonTime<< endl;
  cout << "on pRtnTopProcessInfo->CPU:"<<pRtnTopProcessInfo->CPU<< endl;
  cout << "on pRtnTopProcessInfo->TTY:"<<pRtnTopProcessInfo->TTY<< endl;
  cout << "on pRtnTopProcessInfo->PID:"<<pRtnTopProcessInfo->PID<< endl;
  cout << "on pRtnTopProcessInfo->USERNAME:"<<pRtnTopProcessInfo->USERNAME<< endl;
  cout << "on pRtnTopProcessInfo->PRI:"<<pRtnTopProcessInfo->PRI<< endl;
  cout << "on pRtnTopProcessInfo->NI:"<<pRtnTopProcessInfo->NI<< endl;
  cout << "on pRtnTopProcessInfo->SIZE:"<<pRtnTopProcessInfo->SIZE<< endl;
  cout << "on pRtnTopProcessInfo->RES:"<<pRtnTopProcessInfo->RES<< endl;
  cout << "on pRtnTopProcessInfo->STATE:"<<pRtnTopProcessInfo->STATE<< endl;
  cout << "on pRtnTopProcessInfo->TIME:"<<pRtnTopProcessInfo->TIME<< endl;
  cout << "on pRtnTopProcessInfo->pWCPU:"<<pRtnTopProcessInfo->pWCPU<< endl;
  cout << "on pRtnTopProcessInfo->pCPU:"<<pRtnTopProcessInfo->pCPU<< endl;
  cout << "on pRtnTopProcessInfo->COMMAND:"<<pRtnTopProcessInfo->COMMAND<< endl;
  CShfeFtdcRtnTopProcessInfoField* pNewRtnTopProcessInfo =new CShfeFtdcRtnTopProcessInfoField;
  memcpy(pNewRtnTopProcessInfo,pRtnTopProcessInfo,sizeof(CShfeFtdcRtnTopProcessInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnTopProcessInfo;
  asyncOnRtnTopProcessInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnTopProcessInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryFileSystemInfoTopic(CShfeFtdcRspQryFileSystemInfoField *pRspQryFileSystemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryFileSystemInfo->HostName:"<<pRspQryFileSystemInfo->HostName<< endl;
  cout << "on pRspQryFileSystemInfo->MonDate:"<<pRspQryFileSystemInfo->MonDate<< endl;
  cout << "on pRspQryFileSystemInfo->MonTime:"<<pRspQryFileSystemInfo->MonTime<< endl;
  cout << "on pRspQryFileSystemInfo->FILESYSTEM:"<<pRspQryFileSystemInfo->FILESYSTEM<< endl;
  cout << "on pRspQryFileSystemInfo->SIZE:"<<pRspQryFileSystemInfo->SIZE<< endl;
  cout << "on pRspQryFileSystemInfo->USED:"<<pRspQryFileSystemInfo->USED<< endl;
  cout << "on pRspQryFileSystemInfo->AVAIL:"<<pRspQryFileSystemInfo->AVAIL<< endl;
  cout << "on pRspQryFileSystemInfo->pUSERD:"<<pRspQryFileSystemInfo->pUSERD<< endl;
  cout << "on pRspQryFileSystemInfo->ISIZE:"<<pRspQryFileSystemInfo->ISIZE<< endl;
  cout << "on pRspQryFileSystemInfo->IUSED:"<<pRspQryFileSystemInfo->IUSED<< endl;
  cout << "on pRspQryFileSystemInfo->IFREE:"<<pRspQryFileSystemInfo->IFREE<< endl;
  cout << "on pRspQryFileSystemInfo->pIUSED:"<<pRspQryFileSystemInfo->pIUSED<< endl;
  cout << "on pRspQryFileSystemInfo->MountedOn:"<<pRspQryFileSystemInfo->MountedOn<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryFileSystemInfoField* pNewRspQryFileSystemInfo =new CShfeFtdcRspQryFileSystemInfoField;
  memcpy(pNewRspQryFileSystemInfo,pRspQryFileSystemInfo,sizeof(CShfeFtdcRspQryFileSystemInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryFileSystemInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryFileSystemInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryFileSystemInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnFileSystemInfoTopic(CShfeFtdcRtnFileSystemInfoField *pRtnFileSystemInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnFileSystemInfo->HostName:"<<pRtnFileSystemInfo->HostName<< endl;
  cout << "on pRtnFileSystemInfo->MonDate:"<<pRtnFileSystemInfo->MonDate<< endl;
  cout << "on pRtnFileSystemInfo->MonTime:"<<pRtnFileSystemInfo->MonTime<< endl;
  cout << "on pRtnFileSystemInfo->FILESYSTEM:"<<pRtnFileSystemInfo->FILESYSTEM<< endl;
  cout << "on pRtnFileSystemInfo->SIZE:"<<pRtnFileSystemInfo->SIZE<< endl;
  cout << "on pRtnFileSystemInfo->USED:"<<pRtnFileSystemInfo->USED<< endl;
  cout << "on pRtnFileSystemInfo->AVAIL:"<<pRtnFileSystemInfo->AVAIL<< endl;
  cout << "on pRtnFileSystemInfo->pUSERD:"<<pRtnFileSystemInfo->pUSERD<< endl;
  cout << "on pRtnFileSystemInfo->ISIZE:"<<pRtnFileSystemInfo->ISIZE<< endl;
  cout << "on pRtnFileSystemInfo->IUSED:"<<pRtnFileSystemInfo->IUSED<< endl;
  cout << "on pRtnFileSystemInfo->IFREE:"<<pRtnFileSystemInfo->IFREE<< endl;
  cout << "on pRtnFileSystemInfo->pIUSED:"<<pRtnFileSystemInfo->pIUSED<< endl;
  cout << "on pRtnFileSystemInfo->MountedOn:"<<pRtnFileSystemInfo->MountedOn<< endl;
  CShfeFtdcRtnFileSystemInfoField* pNewRtnFileSystemInfo =new CShfeFtdcRtnFileSystemInfoField;
  memcpy(pNewRtnFileSystemInfo,pRtnFileSystemInfo,sizeof(CShfeFtdcRtnFileSystemInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnFileSystemInfo;
  asyncOnRtnFileSystemInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnFileSystemInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetworkInfoTopic(CShfeFtdcRspQryNetworkInfoField *pRspQryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetworkInfo->HostName:"<<pRspQryNetworkInfo->HostName<< endl;
  cout << "on pRspQryNetworkInfo->MonDate:"<<pRspQryNetworkInfo->MonDate<< endl;
  cout << "on pRspQryNetworkInfo->MonTime:"<<pRspQryNetworkInfo->MonTime<< endl;
  cout << "on pRspQryNetworkInfo->LANNAME:"<<pRspQryNetworkInfo->LANNAME<< endl;
  cout << "on pRspQryNetworkInfo->LANSTATUS:"<<pRspQryNetworkInfo->LANSTATUS<< endl;
  cout << "on pRspQryNetworkInfo->IPADDRESS:"<<pRspQryNetworkInfo->IPADDRESS<< endl;
  cout << "on pRspQryNetworkInfo->RECVBYTES:"<<pRspQryNetworkInfo->RECVBYTES<< endl;
  cout << "on pRspQryNetworkInfo->RECVPACKETS:"<<pRspQryNetworkInfo->RECVPACKETS<< endl;
  cout << "on pRspQryNetworkInfo->RECVERRORPACKETS:"<<pRspQryNetworkInfo->RECVERRORPACKETS<< endl;
  cout << "on pRspQryNetworkInfo->RECVDROPPACKETS:"<<pRspQryNetworkInfo->RECVDROPPACKETS<< endl;
  cout << "on pRspQryNetworkInfo->SENDBYTES:"<<pRspQryNetworkInfo->SENDBYTES<< endl;
  cout << "on pRspQryNetworkInfo->SENDPACKETS:"<<pRspQryNetworkInfo->SENDPACKETS<< endl;
  cout << "on pRspQryNetworkInfo->SENDERRORPACKETS:"<<pRspQryNetworkInfo->SENDERRORPACKETS<< endl;
  cout << "on pRspQryNetworkInfo->SENDDROPPACKETS:"<<pRspQryNetworkInfo->SENDDROPPACKETS<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetworkInfoField* pNewRspQryNetworkInfo =new CShfeFtdcRspQryNetworkInfoField;
  memcpy(pNewRspQryNetworkInfo,pRspQryNetworkInfo,sizeof(CShfeFtdcRspQryNetworkInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetworkInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetworkInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetworkInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetworkInfoTopic(CShfeFtdcRtnNetworkInfoField *pRtnNetworkInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetworkInfo->HostName:"<<pRtnNetworkInfo->HostName<< endl;
  cout << "on pRtnNetworkInfo->MonDate:"<<pRtnNetworkInfo->MonDate<< endl;
  cout << "on pRtnNetworkInfo->MonTime:"<<pRtnNetworkInfo->MonTime<< endl;
  cout << "on pRtnNetworkInfo->LANNAME:"<<pRtnNetworkInfo->LANNAME<< endl;
  cout << "on pRtnNetworkInfo->LANSTATUS:"<<pRtnNetworkInfo->LANSTATUS<< endl;
  cout << "on pRtnNetworkInfo->IPADDRESS:"<<pRtnNetworkInfo->IPADDRESS<< endl;
  cout << "on pRtnNetworkInfo->RECVBYTES:"<<pRtnNetworkInfo->RECVBYTES<< endl;
  cout << "on pRtnNetworkInfo->RECVPACKETS:"<<pRtnNetworkInfo->RECVPACKETS<< endl;
  cout << "on pRtnNetworkInfo->RECVERRORPACKETS:"<<pRtnNetworkInfo->RECVERRORPACKETS<< endl;
  cout << "on pRtnNetworkInfo->RECVDROPPACKETS:"<<pRtnNetworkInfo->RECVDROPPACKETS<< endl;
  cout << "on pRtnNetworkInfo->SENDBYTES:"<<pRtnNetworkInfo->SENDBYTES<< endl;
  cout << "on pRtnNetworkInfo->SENDPACKETS:"<<pRtnNetworkInfo->SENDPACKETS<< endl;
  cout << "on pRtnNetworkInfo->SENDERRORPACKETS:"<<pRtnNetworkInfo->SENDERRORPACKETS<< endl;
  cout << "on pRtnNetworkInfo->SENDDROPPACKETS:"<<pRtnNetworkInfo->SENDDROPPACKETS<< endl;
  CShfeFtdcRtnNetworkInfoField* pNewRtnNetworkInfo =new CShfeFtdcRtnNetworkInfoField;
  memcpy(pNewRtnNetworkInfo,pRtnNetworkInfo,sizeof(CShfeFtdcRtnNetworkInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetworkInfo;
  asyncOnRtnNetworkInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetworkInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryClientLoginTopic(CShfeFtdcRspQryClientLoginField *pRspQryClientLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "\n **************** SysUserSpi::OnRspQryClientLoginTopic:  START **************** "<< endl;
  cout << "on pRspQryClientLogin->UserName:"<<pRspQryClientLogin->UserName<< endl;
  cout << "on pRspQryClientLogin->Privalage:"<<pRspQryClientLogin->Privalage<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryClientLoginField* pNewRspQryClientLogin =new CShfeFtdcRspQryClientLoginField;
  memcpy(pNewRspQryClientLogin,pRspQryClientLogin,sizeof(CShfeFtdcRspQryClientLoginField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryClientLogin;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryClientLoginTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryClientLoginTopic);
  cout << "\n **************** SysUserSpi::OnRspQryClientLoginTopic end! ****************  \n "<< endl;
}

void SysUserSpi::OnRspQryMonitorObjectTopic(CShfeFtdcRspQryMonitorObjectField *pRspQryMonitorObject, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryMonitorObject->ObjectID:"<<pRspQryMonitorObject->ObjectID<< endl;
  cout << "on pRspQryMonitorObject->ObjectName:"<<pRspQryMonitorObject->ObjectName<< endl;
  cout << "on pRspQryMonitorObject->WarningActive:"<<pRspQryMonitorObject->WarningActive<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryMonitorObjectField* pNewRspQryMonitorObject =new CShfeFtdcRspQryMonitorObjectField;
  memcpy(pNewRspQryMonitorObject,pRspQryMonitorObject,sizeof(CShfeFtdcRspQryMonitorObjectField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryMonitorObject;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryMonitorObjectTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryMonitorObjectTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnMonitorObjectTopic(CShfeFtdcRtnMonitorObjectField *pRtnMonitorObject)
{
  cout << "ok"<< endl;
  cout << "on pRtnMonitorObject->ObjectID:"<<pRtnMonitorObject->ObjectID<< endl;
  cout << "on pRtnMonitorObject->ObjectName:"<<pRtnMonitorObject->ObjectName<< endl;
  cout << "on pRtnMonitorObject->WarningActive:"<<pRtnMonitorObject->WarningActive<< endl;
  CShfeFtdcRtnMonitorObjectField* pNewRtnMonitorObject =new CShfeFtdcRtnMonitorObjectField;
  memcpy(pNewRtnMonitorObject,pRtnMonitorObject,sizeof(CShfeFtdcRtnMonitorObjectField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnMonitorObject;
  asyncOnRtnMonitorObjectTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnMonitorObjectTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryObjectRationalTopic(CShfeFtdcRspQryObjectRationalField *pRspQryObjectRational, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryObjectRational->ObjectID:"<<pRspQryObjectRational->ObjectID<< endl;
  cout << "on pRspQryObjectRational->HostObjectID:"<<pRspQryObjectRational->HostObjectID<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryObjectRationalField* pNewRspQryObjectRational =new CShfeFtdcRspQryObjectRationalField;
  memcpy(pNewRspQryObjectRational,pRspQryObjectRational,sizeof(CShfeFtdcRspQryObjectRationalField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryObjectRational;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryObjectRationalTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryObjectRationalTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnObjectRationalTopic(CShfeFtdcRtnObjectRationalField *pRtnObjectRational)
{
  cout << "ok"<< endl;
  cout << "on pRtnObjectRational->ObjectID:"<<pRtnObjectRational->ObjectID<< endl;
  cout << "on pRtnObjectRational->HostObjectID:"<<pRtnObjectRational->HostObjectID<< endl;
  CShfeFtdcRtnObjectRationalField* pNewRtnObjectRational =new CShfeFtdcRtnObjectRationalField;
  memcpy(pNewRtnObjectRational,pRtnObjectRational,sizeof(CShfeFtdcRtnObjectRationalField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnObjectRational;
  asyncOnRtnObjectRationalTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnObjectRationalTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQrySyslogInfoTopic(CShfeFtdcRspQrySyslogInfoField *pRspQrySyslogInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQrySyslogInfo->MonDate:"<<pRspQrySyslogInfo->MonDate<< endl;
  cout << "on pRspQrySyslogInfo->MonTime:"<<pRspQrySyslogInfo->MonTime<< endl;
  cout << "on pRspQrySyslogInfo->ObjectID:"<<pRspQrySyslogInfo->ObjectID<< endl;
  cout << "on pRspQrySyslogInfo->AttrType:"<<pRspQrySyslogInfo->AttrType<< endl;
  cout << "on pRspQrySyslogInfo->ContLen:"<<pRspQrySyslogInfo->ContLen<< endl;
  cout << "on pRspQrySyslogInfo->FileContent:"<<pRspQrySyslogInfo->FileContent<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQrySyslogInfoField* pNewRspQrySyslogInfo =new CShfeFtdcRspQrySyslogInfoField;
  memcpy(pNewRspQrySyslogInfo,pRspQrySyslogInfo,sizeof(CShfeFtdcRspQrySyslogInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySyslogInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySyslogInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQrySyslogInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnSyslogInfoTopic(CShfeFtdcRtnSyslogInfoField *pRtnSyslogInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnSyslogInfo->MonDate:"<<pRtnSyslogInfo->MonDate<< endl;
  cout << "on pRtnSyslogInfo->MonTime:"<<pRtnSyslogInfo->MonTime<< endl;
  cout << "on pRtnSyslogInfo->ObjectID:"<<pRtnSyslogInfo->ObjectID<< endl;
  cout << "on pRtnSyslogInfo->AttrType:"<<pRtnSyslogInfo->AttrType<< endl;
  cout << "on pRtnSyslogInfo->ContLen:"<<pRtnSyslogInfo->ContLen<< endl;
  cout << "on pRtnSyslogInfo->FileContent:"<<pRtnSyslogInfo->FileContent<< endl;
  CShfeFtdcRtnSyslogInfoField* pNewRtnSyslogInfo =new CShfeFtdcRtnSyslogInfoField;
  memcpy(pNewRtnSyslogInfo,pRtnSyslogInfo,sizeof(CShfeFtdcRtnSyslogInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSyslogInfo;
  asyncOnRtnSyslogInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnSyslogInfoTopic);
  cout << "end send "<< endl;
}

// TestSubscriber;

void SysUserSpi::OnRspQrySubscriberTopic(CShfeFtdcRspQrySubscriberField *pRspQrySubscriber, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "\n********** SysUserSpi::OnRspQrySubscriberTopic: START ********"<< endl;
  if (NULL == pRspQrySubscriber) {
    cout << " pRspQrySubscriber is NULL" << endl;
    
    if (NULL != pRspInfo) {
       cout << "pRspInfo -> ErrorID: " << pRspInfo -> ErrorID << endl;
       cout << "pRspInfo -> ErrorMsg: " << pRspInfo -> ErrorMsg  << endl; 
    }
  } else {    
  
  cout << "SysUserSpi::pRspQrySubscriber->ErrorID:"<<pRspQrySubscriber->ErrorID<< endl;
  cout << "SysUserSpi::pRspQrySubscriber->ErrorMsg:"<<pRspQrySubscriber->ErrorMsg<< endl;
  cout << "SysUserSpi::pRspQrySubscriber->ObjectID:"<<pRspQrySubscriber->ObjectID<< endl;
  cout << "SysUserSpi::pRspInfo:"<<pRspInfo<< endl;
  cout << "SysUserSpi::nRequestID:"<<nRequestID<< endl;
  cout << "SysUserSpi::bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQrySubscriberField* pNewRspQrySubscriber =new CShfeFtdcRspQrySubscriberField;
  memcpy(pNewRspQrySubscriber,pRspQrySubscriber,sizeof(CShfeFtdcRspQrySubscriberField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySubscriber;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySubscriberTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQrySubscriberTopic);
  cout << "\n********** SysUserSpi::OnRspQrySubscriberTopic: END ********\n"<< endl;
  
  }
}
void SysUserSpi::OnRspQryOidRelationTopic(CShfeFtdcRspQryOidRelationField *pRspQryOidRelation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryOidRelation->ObjectID:"<<pRspQryOidRelation->ObjectID<< endl;
  cout << "on pRspQryOidRelation->HoldObjectID:"<<pRspQryOidRelation->HoldObjectID<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryOidRelationField* pNewRspQryOidRelation =new CShfeFtdcRspQryOidRelationField;
  memcpy(pNewRspQryOidRelation,pRspQryOidRelation,sizeof(CShfeFtdcRspQryOidRelationField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryOidRelation;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryOidRelationTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryOidRelationTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnOidRelationTopic(CShfeFtdcRtnOidRelationField *pRtnOidRelation)
{
  cout << "ok"<< endl;
  cout << "on pRtnOidRelation->ObjectID:"<<pRtnOidRelation->ObjectID<< endl;
  cout << "on pRtnOidRelation->HoldObjectID:"<<pRtnOidRelation->HoldObjectID<< endl;
  CShfeFtdcRtnOidRelationField* pNewRtnOidRelation =new CShfeFtdcRtnOidRelationField;
  memcpy(pNewRtnOidRelation,pRtnOidRelation,sizeof(CShfeFtdcRtnOidRelationField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnOidRelation;
  asyncOnRtnOidRelationTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnOidRelationTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryUserInfoTopic(CShfeFtdcRspQryUserInfoField *pRspQryUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryUserInfo->USERNAME:"<<pRspQryUserInfo->USERNAME<< endl;
  cout << "on pRspQryUserInfo->USERID:"<<pRspQryUserInfo->USERID<< endl;
  cout << "on pRspQryUserInfo->GROUPNAME:"<<pRspQryUserInfo->GROUPNAME<< endl;
  cout << "on pRspQryUserInfo->GROUPID:"<<pRspQryUserInfo->GROUPID<< endl;
  cout << "on pRspQryUserInfo->HOMEPATH:"<<pRspQryUserInfo->HOMEPATH<< endl;
  cout << "on pRspQryUserInfo->SHELL:"<<pRspQryUserInfo->SHELL<< endl;
  cout << "on pRspQryUserInfo->ObjectID:"<<pRspQryUserInfo->ObjectID<< endl;
  cout << "on pRspQryUserInfo->MonTime:"<<pRspQryUserInfo->MonTime<< endl;
  cout << "on pRspQryUserInfo->MonDate:"<<pRspQryUserInfo->MonDate<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryUserInfoField* pNewRspQryUserInfo =new CShfeFtdcRspQryUserInfoField;
  memcpy(pNewRspQryUserInfo,pRspQryUserInfo,sizeof(CShfeFtdcRspQryUserInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryUserInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryUserInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryUserInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnUserInfoTopic(CShfeFtdcRtnUserInfoField *pRtnUserInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnUserInfo->USERNAME:"<<pRtnUserInfo->USERNAME<< endl;
  cout << "on pRtnUserInfo->USERID:"<<pRtnUserInfo->USERID<< endl;
  cout << "on pRtnUserInfo->GROUPNAME:"<<pRtnUserInfo->GROUPNAME<< endl;
  cout << "on pRtnUserInfo->GROUPID:"<<pRtnUserInfo->GROUPID<< endl;
  cout << "on pRtnUserInfo->HOMEPATH:"<<pRtnUserInfo->HOMEPATH<< endl;
  cout << "on pRtnUserInfo->SHELL:"<<pRtnUserInfo->SHELL<< endl;
  cout << "on pRtnUserInfo->ObjectID:"<<pRtnUserInfo->ObjectID<< endl;
  cout << "on pRtnUserInfo->MonTime:"<<pRtnUserInfo->MonTime<< endl;
  cout << "on pRtnUserInfo->MonDate:"<<pRtnUserInfo->MonDate<< endl;
  CShfeFtdcRtnUserInfoField* pNewRtnUserInfo =new CShfeFtdcRtnUserInfoField;
  memcpy(pNewRtnUserInfo,pRtnUserInfo,sizeof(CShfeFtdcRtnUserInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnUserInfo;
  asyncOnRtnUserInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnUserInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryOnlineUserInfoTopic(CShfeFtdcRspQryOnlineUserInfoField *pRspQryOnlineUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryOnlineUserInfo->USERNAME:"<<pRspQryOnlineUserInfo->USERNAME<< endl;
  cout << "on pRspQryOnlineUserInfo->TIME:"<<pRspQryOnlineUserInfo->TIME<< endl;
  cout << "on pRspQryOnlineUserInfo->TTY:"<<pRspQryOnlineUserInfo->TTY<< endl;
  cout << "on pRspQryOnlineUserInfo->IP:"<<pRspQryOnlineUserInfo->IP<< endl;
  cout << "on pRspQryOnlineUserInfo->CONNECTIME:"<<pRspQryOnlineUserInfo->CONNECTIME<< endl;
  cout << "on pRspQryOnlineUserInfo->PID:"<<pRspQryOnlineUserInfo->PID<< endl;
  cout << "on pRspQryOnlineUserInfo->ObjectID:"<<pRspQryOnlineUserInfo->ObjectID<< endl;
  cout << "on pRspQryOnlineUserInfo->MonTime:"<<pRspQryOnlineUserInfo->MonTime<< endl;
  cout << "on pRspQryOnlineUserInfo->MonDate:"<<pRspQryOnlineUserInfo->MonDate<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryOnlineUserInfoField* pNewRspQryOnlineUserInfo =new CShfeFtdcRspQryOnlineUserInfoField;
  memcpy(pNewRspQryOnlineUserInfo,pRspQryOnlineUserInfo,sizeof(CShfeFtdcRspQryOnlineUserInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryOnlineUserInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryOnlineUserInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryOnlineUserInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnOnlineUserInfoTopic(CShfeFtdcRtnOnlineUserInfoField *pRtnOnlineUserInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnOnlineUserInfo->USERNAME:"<<pRtnOnlineUserInfo->USERNAME<< endl;
  cout << "on pRtnOnlineUserInfo->TIME:"<<pRtnOnlineUserInfo->TIME<< endl;
  cout << "on pRtnOnlineUserInfo->TTY:"<<pRtnOnlineUserInfo->TTY<< endl;
  cout << "on pRtnOnlineUserInfo->IP:"<<pRtnOnlineUserInfo->IP<< endl;
  cout << "on pRtnOnlineUserInfo->CONNECTIME:"<<pRtnOnlineUserInfo->CONNECTIME<< endl;
  cout << "on pRtnOnlineUserInfo->PID:"<<pRtnOnlineUserInfo->PID<< endl;
  cout << "on pRtnOnlineUserInfo->ObjectID:"<<pRtnOnlineUserInfo->ObjectID<< endl;
  cout << "on pRtnOnlineUserInfo->MonTime:"<<pRtnOnlineUserInfo->MonTime<< endl;
  cout << "on pRtnOnlineUserInfo->MonDate:"<<pRtnOnlineUserInfo->MonDate<< endl;
  CShfeFtdcRtnOnlineUserInfoField* pNewRtnOnlineUserInfo =new CShfeFtdcRtnOnlineUserInfoField;
  memcpy(pNewRtnOnlineUserInfo,pRtnOnlineUserInfo,sizeof(CShfeFtdcRtnOnlineUserInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnOnlineUserInfo;
  asyncOnRtnOnlineUserInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnOnlineUserInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryWarningEventTopic(CShfeFtdcRspQryWarningEventField *pRspQryWarningEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  // cout << "\n**************** SysUserSpi::OnRspQryWarningEventTopic: START ****************"<< endl;
  // cout << "on pRspQryWarningEvent->MonDate:"<<pRspQryWarningEvent->MonDate<< endl;
  // cout << "on pRspQryWarningEvent->MonTime:"<<pRspQryWarningEvent->MonTime<< endl;
  // cout << "on pRspQryWarningEvent->OccurDate:"<<pRspQryWarningEvent->OccurDate<< endl;
  // cout << "on pRspQryWarningEvent->OccurTime:"<<pRspQryWarningEvent->OccurTime<< endl;
  // cout << "on pRspQryWarningEvent->EvendID:"<<pRspQryWarningEvent->EvendID<< endl;
  // cout << "on pRspQryWarningEvent->ObjectID:"<<pRspQryWarningEvent->ObjectID<< endl;
  // cout << "on pRspQryWarningEvent->IPAddress:"<<pRspQryWarningEvent->IPAddress<< endl;
  // cout << "on pRspQryWarningEvent->EventName:"<<pRspQryWarningEvent->EventName<< endl;
  // cout << "on pRspQryWarningEvent->EventNum:"<<pRspQryWarningEvent->EventNum<< endl;
  // cout << "on pRspQryWarningEvent->EventType:"<<pRspQryWarningEvent->EventType<< endl;
  // cout << "on pRspQryWarningEvent->EventDes:"<<pRspQryWarningEvent->EventDes<< endl;
  // cout << "on pRspQryWarningEvent->ProcessFlag:"<<pRspQryWarningEvent->ProcessFlag<< endl;
  // cout << "on pRspQryWarningEvent->WarningLevel:"<<pRspQryWarningEvent->WarningLevel<< endl;
  // cout << "on pRspQryWarningEvent->EventDealDes:"<<pRspQryWarningEvent->EventDealDes<< endl;
  // cout << "on pRspQryWarningEvent->FullEventName:"<<pRspQryWarningEvent->FullEventName<< endl;
  // cout << "on pRspInfo:"<<pRspInfo<< endl;
  // cout << "on nRequestID:"<<nRequestID<< endl;
  // cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryWarningEventField* pNewRspQryWarningEvent =new CShfeFtdcRspQryWarningEventField;
  memcpy(pNewRspQryWarningEvent,pRspQryWarningEvent,sizeof(CShfeFtdcRspQryWarningEventField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryWarningEvent;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryWarningEventTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryWarningEventTopic);
//  cout << "\**************** SysUserSpi::OnRspQryWarningEventTopic: END \n****************"<< endl;
}
void SysUserSpi::OnRtnWarningEventTopic(CShfeFtdcRtnWarningEventField *pRtnWarningEvent)
{
  // cout << "\n**************** SysUserSpi::OnRtnWarningEventTopic: START ****************"<< endl;
  // cout << "on pRtnWarningEvent->MonDate:"<<pRtnWarningEvent->MonDate<< endl;
  // cout << "on pRtnWarningEvent->MonTime:"<<pRtnWarningEvent->MonTime<< endl;
  // cout << "on pRtnWarningEvent->OccurDate:"<<pRtnWarningEvent->OccurDate<< endl;
  // cout << "on pRtnWarningEvent->OccurTime:"<<pRtnWarningEvent->OccurTime<< endl;
  // cout << "on pRtnWarningEvent->EvendID:"<<pRtnWarningEvent->EvendID<< endl;
  // cout << "on pRtnWarningEvent->ObjectID:"<<pRtnWarningEvent->ObjectID<< endl;
  // cout << "on pRtnWarningEvent->IPAddress:"<<pRtnWarningEvent->IPAddress<< endl;
  // cout << "on pRtnWarningEvent->EventName:"<<pRtnWarningEvent->EventName<< endl;
  // cout << "on pRtnWarningEvent->EventNum:"<<pRtnWarningEvent->EventNum<< endl;
  // cout << "on pRtnWarningEvent->EventType:"<<pRtnWarningEvent->EventType<< endl;
  // cout << "on pRtnWarningEvent->EventDes:"<<pRtnWarningEvent->EventDes<< endl;
  // cout << "on pRtnWarningEvent->ProcessFlag:"<<pRtnWarningEvent->ProcessFlag<< endl;
  // cout << "on pRtnWarningEvent->WarningLevel:"<<pRtnWarningEvent->WarningLevel<< endl;
  // cout << "on pRtnWarningEvent->EventDealDes:"<<pRtnWarningEvent->EventDealDes<< endl;
  // cout << "on pRtnWarningEvent->FullEventName:"<<pRtnWarningEvent->FullEventName<< endl;
  // cout << "on pRtnWarningEvent->EventCount:"<<pRtnWarningEvent->EventCount<< endl;
  CShfeFtdcRtnWarningEventField* pNewRtnWarningEvent =new CShfeFtdcRtnWarningEventField;
  memcpy(pNewRtnWarningEvent,pRtnWarningEvent,sizeof(CShfeFtdcRtnWarningEventField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnWarningEvent;
  asyncOnRtnWarningEventTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnWarningEventTopic);
  // cout << "**************** SysUserSpi::OnRtnWarningEventTopic: END ****************\n"<< endl;
}
void SysUserSpi::OnRspQryCPUUsageTopic(CShfeFtdcRspQryCPUUsageField *pRspQryCPUUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryCPUUsage->ObjectID:"<<pRspQryCPUUsage->ObjectID<< endl;
  cout << "on pRspQryCPUUsage->MonDate:"<<pRspQryCPUUsage->MonDate<< endl;
  cout << "on pRspQryCPUUsage->MonTime:"<<pRspQryCPUUsage->MonTime<< endl;
  cout << "on pRspQryCPUUsage->CPUUsage:"<<pRspQryCPUUsage->CPUUsage<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryCPUUsageField* pNewRspQryCPUUsage =new CShfeFtdcRspQryCPUUsageField;
  memcpy(pNewRspQryCPUUsage,pRspQryCPUUsage,sizeof(CShfeFtdcRspQryCPUUsageField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryCPUUsage;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryCPUUsageTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryCPUUsageTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnCPUUsageTopic(CShfeFtdcRtnCPUUsageField *pRtnCPUUsage)
{
  cout << "ok"<< endl;
  cout << "on pRtnCPUUsage->ObjectID:"<<pRtnCPUUsage->ObjectID<< endl;
  cout << "on pRtnCPUUsage->MonDate:"<<pRtnCPUUsage->MonDate<< endl;
  cout << "on pRtnCPUUsage->MonTime:"<<pRtnCPUUsage->MonTime<< endl;
  cout << "on pRtnCPUUsage->CPUUsage:"<<pRtnCPUUsage->CPUUsage<< endl;
  CShfeFtdcRtnCPUUsageField* pNewRtnCPUUsage =new CShfeFtdcRtnCPUUsageField;
  memcpy(pNewRtnCPUUsage,pRtnCPUUsage,sizeof(CShfeFtdcRtnCPUUsageField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnCPUUsage;
  asyncOnRtnCPUUsageTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnCPUUsageTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryMemoryUsageTopic(CShfeFtdcRspQryMemoryUsageField *pRspQryMemoryUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryMemoryUsage->ObjectID:"<<pRspQryMemoryUsage->ObjectID<< endl;
  cout << "on pRspQryMemoryUsage->MonDate:"<<pRspQryMemoryUsage->MonDate<< endl;
  cout << "on pRspQryMemoryUsage->MonTime:"<<pRspQryMemoryUsage->MonTime<< endl;
  cout << "on pRspQryMemoryUsage->MemoryUsage:"<<pRspQryMemoryUsage->MemoryUsage<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryMemoryUsageField* pNewRspQryMemoryUsage =new CShfeFtdcRspQryMemoryUsageField;
  memcpy(pNewRspQryMemoryUsage,pRspQryMemoryUsage,sizeof(CShfeFtdcRspQryMemoryUsageField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryMemoryUsage;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryMemoryUsageTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryMemoryUsageTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnMemoryUsageTopic(CShfeFtdcRtnMemoryUsageField *pRtnMemoryUsage)
{
  cout << "ok"<< endl;
  cout << "on pRtnMemoryUsage->ObjectID:"<<pRtnMemoryUsage->ObjectID<< endl;
  cout << "on pRtnMemoryUsage->MonDate:"<<pRtnMemoryUsage->MonDate<< endl;
  cout << "on pRtnMemoryUsage->MonTime:"<<pRtnMemoryUsage->MonTime<< endl;
  cout << "on pRtnMemoryUsage->MemoryUsage:"<<pRtnMemoryUsage->MemoryUsage<< endl;
  CShfeFtdcRtnMemoryUsageField* pNewRtnMemoryUsage =new CShfeFtdcRtnMemoryUsageField;
  memcpy(pNewRtnMemoryUsage,pRtnMemoryUsage,sizeof(CShfeFtdcRtnMemoryUsageField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnMemoryUsage;
  asyncOnRtnMemoryUsageTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnMemoryUsageTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryDiskUsageTopic(CShfeFtdcRspQryDiskUsageField *pRspQryDiskUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryDiskUsage->ObjectID:"<<pRspQryDiskUsage->ObjectID<< endl;
  cout << "on pRspQryDiskUsage->MonDate:"<<pRspQryDiskUsage->MonDate<< endl;
  cout << "on pRspQryDiskUsage->MonTime:"<<pRspQryDiskUsage->MonTime<< endl;
  cout << "on pRspQryDiskUsage->DiskUsage:"<<pRspQryDiskUsage->DiskUsage<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryDiskUsageField* pNewRspQryDiskUsage =new CShfeFtdcRspQryDiskUsageField;
  memcpy(pNewRspQryDiskUsage,pRspQryDiskUsage,sizeof(CShfeFtdcRspQryDiskUsageField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryDiskUsage;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryDiskUsageTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryDiskUsageTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnDiskUsageTopic(CShfeFtdcRtnDiskUsageField *pRtnDiskUsage)
{
  cout << "ok"<< endl;
  cout << "on pRtnDiskUsage->ObjectID:"<<pRtnDiskUsage->ObjectID<< endl;
  cout << "on pRtnDiskUsage->MonDate:"<<pRtnDiskUsage->MonDate<< endl;
  cout << "on pRtnDiskUsage->MonTime:"<<pRtnDiskUsage->MonTime<< endl;
  cout << "on pRtnDiskUsage->DiskUsage:"<<pRtnDiskUsage->DiskUsage<< endl;
  CShfeFtdcRtnDiskUsageField* pNewRtnDiskUsage =new CShfeFtdcRtnDiskUsageField;
  memcpy(pNewRtnDiskUsage,pRtnDiskUsage,sizeof(CShfeFtdcRtnDiskUsageField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnDiskUsage;
  asyncOnRtnDiskUsageTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnDiskUsageTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryObjectAttrTopic(CShfeFtdcRspQryObjectAttrField *pRspQryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryObjectAttr->ObjectID:"<<pRspQryObjectAttr->ObjectID<< endl;
  cout << "on pRspQryObjectAttr->AttrType:"<<pRspQryObjectAttr->AttrType<< endl;
  cout << "on pRspQryObjectAttr->MonDate:"<<pRspQryObjectAttr->MonDate<< endl;
  cout << "on pRspQryObjectAttr->MonTime:"<<pRspQryObjectAttr->MonTime<< endl;
  cout << "on pRspQryObjectAttr->ValueType:"<<pRspQryObjectAttr->ValueType<< endl;
  cout << "on pRspQryObjectAttr->AttrValue:"<<pRspQryObjectAttr->AttrValue<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryObjectAttrField* pNewRspQryObjectAttr =new CShfeFtdcRspQryObjectAttrField;
  memcpy(pNewRspQryObjectAttr,pRspQryObjectAttr,sizeof(CShfeFtdcRspQryObjectAttrField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryObjectAttr;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryObjectAttrTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryObjectAttrTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnObjectAttrTopic(CShfeFtdcRtnObjectAttrField *pRtnObjectAttr)
{
  cout << "ok"<< endl;
  cout << "on pRtnObjectAttr->ObjectID:"<<pRtnObjectAttr->ObjectID<< endl;
  cout << "on pRtnObjectAttr->AttrType:"<<pRtnObjectAttr->AttrType<< endl;
  cout << "on pRtnObjectAttr->MonDate:"<<pRtnObjectAttr->MonDate<< endl;
  cout << "on pRtnObjectAttr->MonTime:"<<pRtnObjectAttr->MonTime<< endl;
  cout << "on pRtnObjectAttr->ValueType:"<<pRtnObjectAttr->ValueType<< endl;
  cout << "on pRtnObjectAttr->AttrValue:"<<pRtnObjectAttr->AttrValue<< endl;
  CShfeFtdcRtnObjectAttrField* pNewRtnObjectAttr =new CShfeFtdcRtnObjectAttrField;
  memcpy(pNewRtnObjectAttr,pRtnObjectAttr,sizeof(CShfeFtdcRtnObjectAttrField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnObjectAttr;
  asyncOnRtnObjectAttrTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnObjectAttrTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryInvalidateOrderTopic(CShfeFtdcRspQryInvalidateOrderField *pRspQryInvalidateOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryInvalidateOrder->OrderSysID:"<<pRspQryInvalidateOrder->OrderSysID<< endl;
  cout << "on pRspQryInvalidateOrder->OrderLocalID:"<<pRspQryInvalidateOrder->OrderLocalID<< endl;
  cout << "on pRspQryInvalidateOrder->ActionDate:"<<pRspQryInvalidateOrder->ActionDate<< endl;
  cout << "on pRspQryInvalidateOrder->ActionTime:"<<pRspQryInvalidateOrder->ActionTime<< endl;
  cout << "on pRspQryInvalidateOrder->ErrorMsg:"<<pRspQryInvalidateOrder->ErrorMsg<< endl;
  cout << "on pRspQryInvalidateOrder->ParticipantID:"<<pRspQryInvalidateOrder->ParticipantID<< endl;
  cout << "on pRspQryInvalidateOrder->UserID:"<<pRspQryInvalidateOrder->UserID<< endl;
  cout << "on pRspQryInvalidateOrder->ClientID:"<<pRspQryInvalidateOrder->ClientID<< endl;
  cout << "on pRspQryInvalidateOrder->InstrumentID:"<<pRspQryInvalidateOrder->InstrumentID<< endl;
  cout << "on pRspQryInvalidateOrder->Direction:"<<pRspQryInvalidateOrder->Direction<< endl;
  cout << "on pRspQryInvalidateOrder->CombOffsetFlag:"<<pRspQryInvalidateOrder->CombOffsetFlag<< endl;
  cout << "on pRspQryInvalidateOrder->CombHedgeFlag:"<<pRspQryInvalidateOrder->CombHedgeFlag<< endl;
  cout << "on pRspQryInvalidateOrder->LimitPrice:"<<pRspQryInvalidateOrder->LimitPrice<< endl;
  cout << "on pRspQryInvalidateOrder->VolumeTotalOriginal:"<<pRspQryInvalidateOrder->VolumeTotalOriginal<< endl;
  cout << "on pRspQryInvalidateOrder->TimeCondition:"<<pRspQryInvalidateOrder->TimeCondition<< endl;
  cout << "on pRspQryInvalidateOrder->VolumeCondition:"<<pRspQryInvalidateOrder->VolumeCondition<< endl;
  cout << "on pRspQryInvalidateOrder->MinVolume:"<<pRspQryInvalidateOrder->MinVolume<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryInvalidateOrderField* pNewRspQryInvalidateOrder =new CShfeFtdcRspQryInvalidateOrderField;
  memcpy(pNewRspQryInvalidateOrder,pRspQryInvalidateOrder,sizeof(CShfeFtdcRspQryInvalidateOrderField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryInvalidateOrder;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryInvalidateOrderTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryInvalidateOrderTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnInvalidateOrderTopic(CShfeFtdcRtnInvalidateOrderField *pRtnInvalidateOrder)
{
  cout << "ok"<< endl;
  cout << "on pRtnInvalidateOrder->OrderSysID:"<<pRtnInvalidateOrder->OrderSysID<< endl;
  cout << "on pRtnInvalidateOrder->OrderLocalID:"<<pRtnInvalidateOrder->OrderLocalID<< endl;
  cout << "on pRtnInvalidateOrder->ActionDate:"<<pRtnInvalidateOrder->ActionDate<< endl;
  cout << "on pRtnInvalidateOrder->ActionTime:"<<pRtnInvalidateOrder->ActionTime<< endl;
  cout << "on pRtnInvalidateOrder->ErrorMsg:"<<pRtnInvalidateOrder->ErrorMsg<< endl;
  cout << "on pRtnInvalidateOrder->ParticipantID:"<<pRtnInvalidateOrder->ParticipantID<< endl;
  cout << "on pRtnInvalidateOrder->UserID:"<<pRtnInvalidateOrder->UserID<< endl;
  cout << "on pRtnInvalidateOrder->ClientID:"<<pRtnInvalidateOrder->ClientID<< endl;
  cout << "on pRtnInvalidateOrder->InstrumentID:"<<pRtnInvalidateOrder->InstrumentID<< endl;
  cout << "on pRtnInvalidateOrder->Direction:"<<pRtnInvalidateOrder->Direction<< endl;
  cout << "on pRtnInvalidateOrder->CombOffsetFlag:"<<pRtnInvalidateOrder->CombOffsetFlag<< endl;
  cout << "on pRtnInvalidateOrder->CombHedgeFlag:"<<pRtnInvalidateOrder->CombHedgeFlag<< endl;
  cout << "on pRtnInvalidateOrder->LimitPrice:"<<pRtnInvalidateOrder->LimitPrice<< endl;
  cout << "on pRtnInvalidateOrder->VolumeTotalOriginal:"<<pRtnInvalidateOrder->VolumeTotalOriginal<< endl;
  cout << "on pRtnInvalidateOrder->TimeCondition:"<<pRtnInvalidateOrder->TimeCondition<< endl;
  cout << "on pRtnInvalidateOrder->VolumeCondition:"<<pRtnInvalidateOrder->VolumeCondition<< endl;
  cout << "on pRtnInvalidateOrder->MinVolume:"<<pRtnInvalidateOrder->MinVolume<< endl;
  CShfeFtdcRtnInvalidateOrderField* pNewRtnInvalidateOrder =new CShfeFtdcRtnInvalidateOrderField;
  memcpy(pNewRtnInvalidateOrder,pRtnInvalidateOrder,sizeof(CShfeFtdcRtnInvalidateOrderField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnInvalidateOrder;
  asyncOnRtnInvalidateOrderTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnInvalidateOrderTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryOrderStatusTopic(CShfeFtdcRspQryOrderStatusField *pRspQryOrderStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryOrderStatus->ActionDate:"<<pRspQryOrderStatus->ActionDate<< endl;
  cout << "on pRspQryOrderStatus->ActionTime:"<<pRspQryOrderStatus->ActionTime<< endl;
  cout << "on pRspQryOrderStatus->OrderSysID:"<<pRspQryOrderStatus->OrderSysID<< endl;
  cout << "on pRspQryOrderStatus->OrderLocalID:"<<pRspQryOrderStatus->OrderLocalID<< endl;
  cout << "on pRspQryOrderStatus->InsertDate:"<<pRspQryOrderStatus->InsertDate<< endl;
  cout << "on pRspQryOrderStatus->InsertTime:"<<pRspQryOrderStatus->InsertTime<< endl;
  cout << "on pRspQryOrderStatus->OrderStatus:"<<pRspQryOrderStatus->OrderStatus<< endl;
  cout << "on pRspQryOrderStatus->ParticipantID:"<<pRspQryOrderStatus->ParticipantID<< endl;
  cout << "on pRspQryOrderStatus->UserID:"<<pRspQryOrderStatus->UserID<< endl;
  cout << "on pRspQryOrderStatus->ClientID:"<<pRspQryOrderStatus->ClientID<< endl;
  cout << "on pRspQryOrderStatus->InstrumentID:"<<pRspQryOrderStatus->InstrumentID<< endl;
  cout << "on pRspQryOrderStatus->Direction:"<<pRspQryOrderStatus->Direction<< endl;
  cout << "on pRspQryOrderStatus->CombOffsetFlag:"<<pRspQryOrderStatus->CombOffsetFlag<< endl;
  cout << "on pRspQryOrderStatus->CombHedgeFlag:"<<pRspQryOrderStatus->CombHedgeFlag<< endl;
  cout << "on pRspQryOrderStatus->LimitPrice:"<<pRspQryOrderStatus->LimitPrice<< endl;
  cout << "on pRspQryOrderStatus->VolumeTotalOriginal:"<<pRspQryOrderStatus->VolumeTotalOriginal<< endl;
  cout << "on pRspQryOrderStatus->TimeCondition:"<<pRspQryOrderStatus->TimeCondition<< endl;
  cout << "on pRspQryOrderStatus->VolumeCondition:"<<pRspQryOrderStatus->VolumeCondition<< endl;
  cout << "on pRspQryOrderStatus->MinVolume:"<<pRspQryOrderStatus->MinVolume<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryOrderStatusField* pNewRspQryOrderStatus =new CShfeFtdcRspQryOrderStatusField;
  memcpy(pNewRspQryOrderStatus,pRspQryOrderStatus,sizeof(CShfeFtdcRspQryOrderStatusField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryOrderStatus;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryOrderStatusTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryOrderStatusTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnOrderStatusTopic(CShfeFtdcRtnOrderStatusField *pRtnOrderStatus)
{
  cout << "ok"<< endl;
  cout << "on pRtnOrderStatus->ActionDate:"<<pRtnOrderStatus->ActionDate<< endl;
  cout << "on pRtnOrderStatus->ActionTime:"<<pRtnOrderStatus->ActionTime<< endl;
  cout << "on pRtnOrderStatus->OrderSysID:"<<pRtnOrderStatus->OrderSysID<< endl;
  cout << "on pRtnOrderStatus->OrderLocalID:"<<pRtnOrderStatus->OrderLocalID<< endl;
  cout << "on pRtnOrderStatus->InsertDate:"<<pRtnOrderStatus->InsertDate<< endl;
  cout << "on pRtnOrderStatus->InsertTime:"<<pRtnOrderStatus->InsertTime<< endl;
  cout << "on pRtnOrderStatus->OrderStatus:"<<pRtnOrderStatus->OrderStatus<< endl;
  cout << "on pRtnOrderStatus->ParticipantID:"<<pRtnOrderStatus->ParticipantID<< endl;
  cout << "on pRtnOrderStatus->UserID:"<<pRtnOrderStatus->UserID<< endl;
  cout << "on pRtnOrderStatus->ClientID:"<<pRtnOrderStatus->ClientID<< endl;
  cout << "on pRtnOrderStatus->InstrumentID:"<<pRtnOrderStatus->InstrumentID<< endl;
  cout << "on pRtnOrderStatus->Direction:"<<pRtnOrderStatus->Direction<< endl;
  cout << "on pRtnOrderStatus->CombOffsetFlag:"<<pRtnOrderStatus->CombOffsetFlag<< endl;
  cout << "on pRtnOrderStatus->CombHedgeFlag:"<<pRtnOrderStatus->CombHedgeFlag<< endl;
  cout << "on pRtnOrderStatus->LimitPrice:"<<pRtnOrderStatus->LimitPrice<< endl;
  cout << "on pRtnOrderStatus->VolumeTotalOriginal:"<<pRtnOrderStatus->VolumeTotalOriginal<< endl;
  cout << "on pRtnOrderStatus->TimeCondition:"<<pRtnOrderStatus->TimeCondition<< endl;
  cout << "on pRtnOrderStatus->VolumeCondition:"<<pRtnOrderStatus->VolumeCondition<< endl;
  cout << "on pRtnOrderStatus->MinVolume:"<<pRtnOrderStatus->MinVolume<< endl;
  CShfeFtdcRtnOrderStatusField* pNewRtnOrderStatus =new CShfeFtdcRtnOrderStatusField;
  memcpy(pNewRtnOrderStatus,pRtnOrderStatus,sizeof(CShfeFtdcRtnOrderStatusField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnOrderStatus;
  asyncOnRtnOrderStatusTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnOrderStatusTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryBargainOrderTopic(CShfeFtdcRspQryBargainOrderField *pRspQryBargainOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryBargainOrder->ActionDate:"<<pRspQryBargainOrder->ActionDate<< endl;
  cout << "on pRspQryBargainOrder->ActionTime:"<<pRspQryBargainOrder->ActionTime<< endl;
  cout << "on pRspQryBargainOrder->TradeID:"<<pRspQryBargainOrder->TradeID<< endl;
  cout << "on pRspQryBargainOrder->OrderSysID:"<<pRspQryBargainOrder->OrderSysID<< endl;
  cout << "on pRspQryBargainOrder->InstrumentID:"<<pRspQryBargainOrder->InstrumentID<< endl;
  cout << "on pRspQryBargainOrder->Price:"<<pRspQryBargainOrder->Price<< endl;
  cout << "on pRspQryBargainOrder->Volume:"<<pRspQryBargainOrder->Volume<< endl;
  cout << "on pRspQryBargainOrder->ParticipantID:"<<pRspQryBargainOrder->ParticipantID<< endl;
  cout << "on pRspQryBargainOrder->UserID:"<<pRspQryBargainOrder->UserID<< endl;
  cout << "on pRspQryBargainOrder->ClientID:"<<pRspQryBargainOrder->ClientID<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryBargainOrderField* pNewRspQryBargainOrder =new CShfeFtdcRspQryBargainOrderField;
  memcpy(pNewRspQryBargainOrder,pRspQryBargainOrder,sizeof(CShfeFtdcRspQryBargainOrderField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryBargainOrder;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryBargainOrderTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryBargainOrderTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnBargainOrderTopic(CShfeFtdcRtnBargainOrderField *pRtnBargainOrder)
{
  cout << "ok"<< endl;
  cout << "on pRtnBargainOrder->ActionDate:"<<pRtnBargainOrder->ActionDate<< endl;
  cout << "on pRtnBargainOrder->ActionTime:"<<pRtnBargainOrder->ActionTime<< endl;
  cout << "on pRtnBargainOrder->TradeID:"<<pRtnBargainOrder->TradeID<< endl;
  cout << "on pRtnBargainOrder->OrderSysID:"<<pRtnBargainOrder->OrderSysID<< endl;
  cout << "on pRtnBargainOrder->InstrumentID:"<<pRtnBargainOrder->InstrumentID<< endl;
  cout << "on pRtnBargainOrder->Price:"<<pRtnBargainOrder->Price<< endl;
  cout << "on pRtnBargainOrder->Volume:"<<pRtnBargainOrder->Volume<< endl;
  cout << "on pRtnBargainOrder->ParticipantID:"<<pRtnBargainOrder->ParticipantID<< endl;
  cout << "on pRtnBargainOrder->UserID:"<<pRtnBargainOrder->UserID<< endl;
  cout << "on pRtnBargainOrder->ClientID:"<<pRtnBargainOrder->ClientID<< endl;
  CShfeFtdcRtnBargainOrderField* pNewRtnBargainOrder =new CShfeFtdcRtnBargainOrderField;
  memcpy(pNewRtnBargainOrder,pRtnBargainOrder,sizeof(CShfeFtdcRtnBargainOrderField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnBargainOrder;
  asyncOnRtnBargainOrderTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnBargainOrderTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryInstPropertyTopic(CShfeFtdcRspQryInstPropertyField *pRspQryInstProperty, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryInstProperty->ActionDate:"<<pRspQryInstProperty->ActionDate<< endl;
  cout << "on pRspQryInstProperty->ActionTime:"<<pRspQryInstProperty->ActionTime<< endl;
  cout << "on pRspQryInstProperty->InstrumentID:"<<pRspQryInstProperty->InstrumentID<< endl;
  cout << "on pRspQryInstProperty->SettlementGroupID:"<<pRspQryInstProperty->SettlementGroupID<< endl;
  cout << "on pRspQryInstProperty->UnderlyingInstrID:"<<pRspQryInstProperty->UnderlyingInstrID<< endl;
  cout << "on pRspQryInstProperty->ProductClass:"<<pRspQryInstProperty->ProductClass<< endl;
  cout << "on pRspQryInstProperty->PositionType:"<<pRspQryInstProperty->PositionType<< endl;
  cout << "on pRspQryInstProperty->VolumeMultiple:"<<pRspQryInstProperty->VolumeMultiple<< endl;
  cout << "on pRspQryInstProperty->UnderlyingMultiple:"<<pRspQryInstProperty->UnderlyingMultiple<< endl;
  cout << "on pRspQryInstProperty->InstLifePhase:"<<pRspQryInstProperty->InstLifePhase<< endl;
  cout << "on pRspQryInstProperty->OpenDate:"<<pRspQryInstProperty->OpenDate<< endl;
  cout << "on pRspQryInstProperty->ExpireDate:"<<pRspQryInstProperty->ExpireDate<< endl;
  cout << "on pRspQryInstProperty->StartDelivDate:"<<pRspQryInstProperty->StartDelivDate<< endl;
  cout << "on pRspQryInstProperty->EndDelivDate:"<<pRspQryInstProperty->EndDelivDate<< endl;
  cout << "on pRspQryInstProperty->BasisPrice:"<<pRspQryInstProperty->BasisPrice<< endl;
  cout << "on pRspQryInstProperty->MaxMarketOrderVolume:"<<pRspQryInstProperty->MaxMarketOrderVolume<< endl;
  cout << "on pRspQryInstProperty->MinMarketOrderVolume:"<<pRspQryInstProperty->MinMarketOrderVolume<< endl;
  cout << "on pRspQryInstProperty->MaxLimitOrderVolume:"<<pRspQryInstProperty->MaxLimitOrderVolume<< endl;
  cout << "on pRspQryInstProperty->MinLimitOrderVolume:"<<pRspQryInstProperty->MinLimitOrderVolume<< endl;
  cout << "on pRspQryInstProperty->PriceTick:"<<pRspQryInstProperty->PriceTick<< endl;
  cout << "on pRspQryInstProperty->AllowDelivPersonOpen:"<<pRspQryInstProperty->AllowDelivPersonOpen<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryInstPropertyField* pNewRspQryInstProperty =new CShfeFtdcRspQryInstPropertyField;
  memcpy(pNewRspQryInstProperty,pRspQryInstProperty,sizeof(CShfeFtdcRspQryInstPropertyField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryInstProperty;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryInstPropertyTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryInstPropertyTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnInstPropertyTopic(CShfeFtdcRtnInstPropertyField *pRtnInstProperty)
{
  cout << "ok"<< endl;
  cout << "on pRtnInstProperty->ActionDate:"<<pRtnInstProperty->ActionDate<< endl;
  cout << "on pRtnInstProperty->ActionTime:"<<pRtnInstProperty->ActionTime<< endl;
  cout << "on pRtnInstProperty->InstrumentID:"<<pRtnInstProperty->InstrumentID<< endl;
  cout << "on pRtnInstProperty->SettlementGroupID:"<<pRtnInstProperty->SettlementGroupID<< endl;
  cout << "on pRtnInstProperty->UnderlyingInstrID:"<<pRtnInstProperty->UnderlyingInstrID<< endl;
  cout << "on pRtnInstProperty->ProductClass:"<<pRtnInstProperty->ProductClass<< endl;
  cout << "on pRtnInstProperty->PositionType:"<<pRtnInstProperty->PositionType<< endl;
  cout << "on pRtnInstProperty->VolumeMultiple:"<<pRtnInstProperty->VolumeMultiple<< endl;
  cout << "on pRtnInstProperty->UnderlyingMultiple:"<<pRtnInstProperty->UnderlyingMultiple<< endl;
  cout << "on pRtnInstProperty->InstLifePhase:"<<pRtnInstProperty->InstLifePhase<< endl;
  cout << "on pRtnInstProperty->OpenDate:"<<pRtnInstProperty->OpenDate<< endl;
  cout << "on pRtnInstProperty->ExpireDate:"<<pRtnInstProperty->ExpireDate<< endl;
  cout << "on pRtnInstProperty->StartDelivDate:"<<pRtnInstProperty->StartDelivDate<< endl;
  cout << "on pRtnInstProperty->EndDelivDate:"<<pRtnInstProperty->EndDelivDate<< endl;
  cout << "on pRtnInstProperty->BasisPrice:"<<pRtnInstProperty->BasisPrice<< endl;
  cout << "on pRtnInstProperty->MaxMarketOrderVolume:"<<pRtnInstProperty->MaxMarketOrderVolume<< endl;
  cout << "on pRtnInstProperty->MinMarketOrderVolume:"<<pRtnInstProperty->MinMarketOrderVolume<< endl;
  cout << "on pRtnInstProperty->MaxLimitOrderVolume:"<<pRtnInstProperty->MaxLimitOrderVolume<< endl;
  cout << "on pRtnInstProperty->MinLimitOrderVolume:"<<pRtnInstProperty->MinLimitOrderVolume<< endl;
  cout << "on pRtnInstProperty->PriceTick:"<<pRtnInstProperty->PriceTick<< endl;
  cout << "on pRtnInstProperty->AllowDelivPersonOpen:"<<pRtnInstProperty->AllowDelivPersonOpen<< endl;
  CShfeFtdcRtnInstPropertyField* pNewRtnInstProperty =new CShfeFtdcRtnInstPropertyField;
  memcpy(pNewRtnInstProperty,pRtnInstProperty,sizeof(CShfeFtdcRtnInstPropertyField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnInstProperty;
  asyncOnRtnInstPropertyTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnInstPropertyTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryMarginRateTopic(CShfeFtdcRspQryMarginRateField *pRspQryMarginRate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryMarginRate->ActionDate:"<<pRspQryMarginRate->ActionDate<< endl;
  cout << "on pRspQryMarginRate->ActionTime:"<<pRspQryMarginRate->ActionTime<< endl;
  cout << "on pRspQryMarginRate->InstrumentID:"<<pRspQryMarginRate->InstrumentID<< endl;
  cout << "on pRspQryMarginRate->ParticipantID:"<<pRspQryMarginRate->ParticipantID<< endl;
  cout << "on pRspQryMarginRate->TradingRole:"<<pRspQryMarginRate->TradingRole<< endl;
  cout << "on pRspQryMarginRate->HedgeFlag:"<<pRspQryMarginRate->HedgeFlag<< endl;
  cout << "on pRspQryMarginRate->ValueMode:"<<pRspQryMarginRate->ValueMode<< endl;
  cout << "on pRspQryMarginRate->LongMarginRatio:"<<pRspQryMarginRate->LongMarginRatio<< endl;
  cout << "on pRspQryMarginRate->ShortMarginRatio:"<<pRspQryMarginRate->ShortMarginRatio<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryMarginRateField* pNewRspQryMarginRate =new CShfeFtdcRspQryMarginRateField;
  memcpy(pNewRspQryMarginRate,pRspQryMarginRate,sizeof(CShfeFtdcRspQryMarginRateField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryMarginRate;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryMarginRateTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryMarginRateTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnMarginRateTopic(CShfeFtdcRtnMarginRateField *pRtnMarginRate)
{
  cout << "ok"<< endl;
  cout << "on pRtnMarginRate->ActionDate:"<<pRtnMarginRate->ActionDate<< endl;
  cout << "on pRtnMarginRate->ActionTime:"<<pRtnMarginRate->ActionTime<< endl;
  cout << "on pRtnMarginRate->InstrumentID:"<<pRtnMarginRate->InstrumentID<< endl;
  cout << "on pRtnMarginRate->ParticipantID:"<<pRtnMarginRate->ParticipantID<< endl;
  cout << "on pRtnMarginRate->TradingRole:"<<pRtnMarginRate->TradingRole<< endl;
  cout << "on pRtnMarginRate->HedgeFlag:"<<pRtnMarginRate->HedgeFlag<< endl;
  cout << "on pRtnMarginRate->ValueMode:"<<pRtnMarginRate->ValueMode<< endl;
  cout << "on pRtnMarginRate->LongMarginRatio:"<<pRtnMarginRate->LongMarginRatio<< endl;
  cout << "on pRtnMarginRate->ShortMarginRatio:"<<pRtnMarginRate->ShortMarginRatio<< endl;
  CShfeFtdcRtnMarginRateField* pNewRtnMarginRate =new CShfeFtdcRtnMarginRateField;
  memcpy(pNewRtnMarginRate,pRtnMarginRate,sizeof(CShfeFtdcRtnMarginRateField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnMarginRate;
  asyncOnRtnMarginRateTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnMarginRateTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryPriceLimitTopic(CShfeFtdcRspQryPriceLimitField *pRspQryPriceLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryPriceLimit->ActionDate:"<<pRspQryPriceLimit->ActionDate<< endl;
  cout << "on pRspQryPriceLimit->ActionTime:"<<pRspQryPriceLimit->ActionTime<< endl;
  cout << "on pRspQryPriceLimit->InstrumentID:"<<pRspQryPriceLimit->InstrumentID<< endl;
  cout << "on pRspQryPriceLimit->ValueMode:"<<pRspQryPriceLimit->ValueMode<< endl;
  cout << "on pRspQryPriceLimit->RoundingMode:"<<pRspQryPriceLimit->RoundingMode<< endl;
  cout << "on pRspQryPriceLimit->UpperLimitPrice:"<<pRspQryPriceLimit->UpperLimitPrice<< endl;
  cout << "on pRspQryPriceLimit->LowerLimitPrice:"<<pRspQryPriceLimit->LowerLimitPrice<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryPriceLimitField* pNewRspQryPriceLimit =new CShfeFtdcRspQryPriceLimitField;
  memcpy(pNewRspQryPriceLimit,pRspQryPriceLimit,sizeof(CShfeFtdcRspQryPriceLimitField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryPriceLimit;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryPriceLimitTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryPriceLimitTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnPriceLimitTopic(CShfeFtdcRtnPriceLimitField *pRtnPriceLimit)
{
  cout << "ok"<< endl;
  cout << "on pRtnPriceLimit->ActionDate:"<<pRtnPriceLimit->ActionDate<< endl;
  cout << "on pRtnPriceLimit->ActionTime:"<<pRtnPriceLimit->ActionTime<< endl;
  cout << "on pRtnPriceLimit->InstrumentID:"<<pRtnPriceLimit->InstrumentID<< endl;
  cout << "on pRtnPriceLimit->ValueMode:"<<pRtnPriceLimit->ValueMode<< endl;
  cout << "on pRtnPriceLimit->RoundingMode:"<<pRtnPriceLimit->RoundingMode<< endl;
  cout << "on pRtnPriceLimit->UpperLimitPrice:"<<pRtnPriceLimit->UpperLimitPrice<< endl;
  cout << "on pRtnPriceLimit->LowerLimitPrice:"<<pRtnPriceLimit->LowerLimitPrice<< endl;
  CShfeFtdcRtnPriceLimitField* pNewRtnPriceLimit =new CShfeFtdcRtnPriceLimitField;
  memcpy(pNewRtnPriceLimit,pRtnPriceLimit,sizeof(CShfeFtdcRtnPriceLimitField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnPriceLimit;
  asyncOnRtnPriceLimitTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnPriceLimitTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryPartPosiLimitTopic(CShfeFtdcRspQryPartPosiLimitField *pRspQryPartPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryPartPosiLimit->ActionDate:"<<pRspQryPartPosiLimit->ActionDate<< endl;
  cout << "on pRspQryPartPosiLimit->ActionTime:"<<pRspQryPartPosiLimit->ActionTime<< endl;
  cout << "on pRspQryPartPosiLimit->InstrumentID:"<<pRspQryPartPosiLimit->InstrumentID<< endl;
  cout << "on pRspQryPartPosiLimit->ParticipantID:"<<pRspQryPartPosiLimit->ParticipantID<< endl;
  cout << "on pRspQryPartPosiLimit->TradingRole:"<<pRspQryPartPosiLimit->TradingRole<< endl;
  cout << "on pRspQryPartPosiLimit->StartTotalPosition:"<<pRspQryPartPosiLimit->StartTotalPosition<< endl;
  cout << "on pRspQryPartPosiLimit->ValueMode:"<<pRspQryPartPosiLimit->ValueMode<< endl;
  cout << "on pRspQryPartPosiLimit->LongPosLimit:"<<pRspQryPartPosiLimit->LongPosLimit<< endl;
  cout << "on pRspQryPartPosiLimit->ShortPosLimit:"<<pRspQryPartPosiLimit->ShortPosLimit<< endl;
  cout << "on pRspQryPartPosiLimit->UpperLimitPrice:"<<pRspQryPartPosiLimit->UpperLimitPrice<< endl;
  cout << "on pRspQryPartPosiLimit->LowerLimitPrice:"<<pRspQryPartPosiLimit->LowerLimitPrice<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryPartPosiLimitField* pNewRspQryPartPosiLimit =new CShfeFtdcRspQryPartPosiLimitField;
  memcpy(pNewRspQryPartPosiLimit,pRspQryPartPosiLimit,sizeof(CShfeFtdcRspQryPartPosiLimitField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryPartPosiLimit;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryPartPosiLimitTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryPartPosiLimitTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnPartPosiLimitTopic(CShfeFtdcRtnPartPosiLimitField *pRtnPartPosiLimit)
{
  cout << "ok"<< endl;
  cout << "on pRtnPartPosiLimit->ActionDate:"<<pRtnPartPosiLimit->ActionDate<< endl;
  cout << "on pRtnPartPosiLimit->ActionTime:"<<pRtnPartPosiLimit->ActionTime<< endl;
  cout << "on pRtnPartPosiLimit->InstrumentID:"<<pRtnPartPosiLimit->InstrumentID<< endl;
  cout << "on pRtnPartPosiLimit->ParticipantID:"<<pRtnPartPosiLimit->ParticipantID<< endl;
  cout << "on pRtnPartPosiLimit->TradingRole:"<<pRtnPartPosiLimit->TradingRole<< endl;
  cout << "on pRtnPartPosiLimit->StartTotalPosition:"<<pRtnPartPosiLimit->StartTotalPosition<< endl;
  cout << "on pRtnPartPosiLimit->ValueMode:"<<pRtnPartPosiLimit->ValueMode<< endl;
  cout << "on pRtnPartPosiLimit->LongPosLimit:"<<pRtnPartPosiLimit->LongPosLimit<< endl;
  cout << "on pRtnPartPosiLimit->ShortPosLimit:"<<pRtnPartPosiLimit->ShortPosLimit<< endl;
  cout << "on pRtnPartPosiLimit->UpperLimitPrice:"<<pRtnPartPosiLimit->UpperLimitPrice<< endl;
  cout << "on pRtnPartPosiLimit->LowerLimitPrice:"<<pRtnPartPosiLimit->LowerLimitPrice<< endl;
  CShfeFtdcRtnPartPosiLimitField* pNewRtnPartPosiLimit =new CShfeFtdcRtnPartPosiLimitField;
  memcpy(pNewRtnPartPosiLimit,pRtnPartPosiLimit,sizeof(CShfeFtdcRtnPartPosiLimitField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnPartPosiLimit;
  asyncOnRtnPartPosiLimitTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnPartPosiLimitTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryClientPosiLimitTopic(CShfeFtdcRspQryClientPosiLimitField *pRspQryClientPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryClientPosiLimit->ActionDate:"<<pRspQryClientPosiLimit->ActionDate<< endl;
  cout << "on pRspQryClientPosiLimit->ActionTime:"<<pRspQryClientPosiLimit->ActionTime<< endl;
  cout << "on pRspQryClientPosiLimit->InstrumentID:"<<pRspQryClientPosiLimit->InstrumentID<< endl;
  cout << "on pRspQryClientPosiLimit->ClientType:"<<pRspQryClientPosiLimit->ClientType<< endl;
  cout << "on pRspQryClientPosiLimit->TradingRole:"<<pRspQryClientPosiLimit->TradingRole<< endl;
  cout << "on pRspQryClientPosiLimit->StartTotalPosition:"<<pRspQryClientPosiLimit->StartTotalPosition<< endl;
  cout << "on pRspQryClientPosiLimit->ValueMode:"<<pRspQryClientPosiLimit->ValueMode<< endl;
  cout << "on pRspQryClientPosiLimit->LongPosLimit:"<<pRspQryClientPosiLimit->LongPosLimit<< endl;
  cout << "on pRspQryClientPosiLimit->ShortPosLimit:"<<pRspQryClientPosiLimit->ShortPosLimit<< endl;
  cout << "on pRspQryClientPosiLimit->UpperLimitPrice:"<<pRspQryClientPosiLimit->UpperLimitPrice<< endl;
  cout << "on pRspQryClientPosiLimit->LowerLimitPrice:"<<pRspQryClientPosiLimit->LowerLimitPrice<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryClientPosiLimitField* pNewRspQryClientPosiLimit =new CShfeFtdcRspQryClientPosiLimitField;
  memcpy(pNewRspQryClientPosiLimit,pRspQryClientPosiLimit,sizeof(CShfeFtdcRspQryClientPosiLimitField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryClientPosiLimit;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryClientPosiLimitTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryClientPosiLimitTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnClientPosiLimitTopic(CShfeFtdcRtnClientPosiLimitField *pRtnClientPosiLimit)
{
  cout << "ok"<< endl;
  cout << "on pRtnClientPosiLimit->ActionDate:"<<pRtnClientPosiLimit->ActionDate<< endl;
  cout << "on pRtnClientPosiLimit->ActionTime:"<<pRtnClientPosiLimit->ActionTime<< endl;
  cout << "on pRtnClientPosiLimit->InstrumentID:"<<pRtnClientPosiLimit->InstrumentID<< endl;
  cout << "on pRtnClientPosiLimit->ClientType:"<<pRtnClientPosiLimit->ClientType<< endl;
  cout << "on pRtnClientPosiLimit->TradingRole:"<<pRtnClientPosiLimit->TradingRole<< endl;
  cout << "on pRtnClientPosiLimit->StartTotalPosition:"<<pRtnClientPosiLimit->StartTotalPosition<< endl;
  cout << "on pRtnClientPosiLimit->ValueMode:"<<pRtnClientPosiLimit->ValueMode<< endl;
  cout << "on pRtnClientPosiLimit->LongPosLimit:"<<pRtnClientPosiLimit->LongPosLimit<< endl;
  cout << "on pRtnClientPosiLimit->ShortPosLimit:"<<pRtnClientPosiLimit->ShortPosLimit<< endl;
  cout << "on pRtnClientPosiLimit->UpperLimitPrice:"<<pRtnClientPosiLimit->UpperLimitPrice<< endl;
  cout << "on pRtnClientPosiLimit->LowerLimitPrice:"<<pRtnClientPosiLimit->LowerLimitPrice<< endl;
  CShfeFtdcRtnClientPosiLimitField* pNewRtnClientPosiLimit =new CShfeFtdcRtnClientPosiLimitField;
  memcpy(pNewRtnClientPosiLimit,pRtnClientPosiLimit,sizeof(CShfeFtdcRtnClientPosiLimitField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnClientPosiLimit;
  asyncOnRtnClientPosiLimitTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnClientPosiLimitTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQrySpecialPosiLimitTopic(CShfeFtdcRspQrySpecialPosiLimitField *pRspQrySpecialPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQrySpecialPosiLimit->ActionDate:"<<pRspQrySpecialPosiLimit->ActionDate<< endl;
  cout << "on pRspQrySpecialPosiLimit->ActionTime:"<<pRspQrySpecialPosiLimit->ActionTime<< endl;
  cout << "on pRspQrySpecialPosiLimit->InstrumentID:"<<pRspQrySpecialPosiLimit->InstrumentID<< endl;
  cout << "on pRspQrySpecialPosiLimit->ClientID:"<<pRspQrySpecialPosiLimit->ClientID<< endl;
  cout << "on pRspQrySpecialPosiLimit->TradingRole:"<<pRspQrySpecialPosiLimit->TradingRole<< endl;
  cout << "on pRspQrySpecialPosiLimit->StartTotalPosition:"<<pRspQrySpecialPosiLimit->StartTotalPosition<< endl;
  cout << "on pRspQrySpecialPosiLimit->ValueMode:"<<pRspQrySpecialPosiLimit->ValueMode<< endl;
  cout << "on pRspQrySpecialPosiLimit->LongPosLimit:"<<pRspQrySpecialPosiLimit->LongPosLimit<< endl;
  cout << "on pRspQrySpecialPosiLimit->ShortPosLimit:"<<pRspQrySpecialPosiLimit->ShortPosLimit<< endl;
  cout << "on pRspQrySpecialPosiLimit->UpperLimitPrice:"<<pRspQrySpecialPosiLimit->UpperLimitPrice<< endl;
  cout << "on pRspQrySpecialPosiLimit->LowerLimitPrice:"<<pRspQrySpecialPosiLimit->LowerLimitPrice<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQrySpecialPosiLimitField* pNewRspQrySpecialPosiLimit =new CShfeFtdcRspQrySpecialPosiLimitField;
  memcpy(pNewRspQrySpecialPosiLimit,pRspQrySpecialPosiLimit,sizeof(CShfeFtdcRspQrySpecialPosiLimitField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySpecialPosiLimit;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySpecialPosiLimitTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQrySpecialPosiLimitTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnSpecialPosiLimitTopic(CShfeFtdcRtnSpecialPosiLimitField *pRtnSpecialPosiLimit)
{
  cout << "ok"<< endl;
  cout << "on pRtnSpecialPosiLimit->ActionDate:"<<pRtnSpecialPosiLimit->ActionDate<< endl;
  cout << "on pRtnSpecialPosiLimit->ActionTime:"<<pRtnSpecialPosiLimit->ActionTime<< endl;
  cout << "on pRtnSpecialPosiLimit->InstrumentID:"<<pRtnSpecialPosiLimit->InstrumentID<< endl;
  cout << "on pRtnSpecialPosiLimit->ClientID:"<<pRtnSpecialPosiLimit->ClientID<< endl;
  cout << "on pRtnSpecialPosiLimit->TradingRole:"<<pRtnSpecialPosiLimit->TradingRole<< endl;
  cout << "on pRtnSpecialPosiLimit->StartTotalPosition:"<<pRtnSpecialPosiLimit->StartTotalPosition<< endl;
  cout << "on pRtnSpecialPosiLimit->ValueMode:"<<pRtnSpecialPosiLimit->ValueMode<< endl;
  cout << "on pRtnSpecialPosiLimit->LongPosLimit:"<<pRtnSpecialPosiLimit->LongPosLimit<< endl;
  cout << "on pRtnSpecialPosiLimit->ShortPosLimit:"<<pRtnSpecialPosiLimit->ShortPosLimit<< endl;
  cout << "on pRtnSpecialPosiLimit->UpperLimitPrice:"<<pRtnSpecialPosiLimit->UpperLimitPrice<< endl;
  cout << "on pRtnSpecialPosiLimit->LowerLimitPrice:"<<pRtnSpecialPosiLimit->LowerLimitPrice<< endl;
  CShfeFtdcRtnSpecialPosiLimitField* pNewRtnSpecialPosiLimit =new CShfeFtdcRtnSpecialPosiLimitField;
  memcpy(pNewRtnSpecialPosiLimit,pRtnSpecialPosiLimit,sizeof(CShfeFtdcRtnSpecialPosiLimitField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSpecialPosiLimit;
  asyncOnRtnSpecialPosiLimitTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnSpecialPosiLimitTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryTransactionChgTopic(CShfeFtdcRspQryTransactionChgField *pRspQryTransactionChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryTransactionChg->ActionDate:"<<pRspQryTransactionChg->ActionDate<< endl;
  cout << "on pRspQryTransactionChg->ActionTime:"<<pRspQryTransactionChg->ActionTime<< endl;
  cout << "on pRspQryTransactionChg->BillSN:"<<pRspQryTransactionChg->BillSN<< endl;
  cout << "on pRspQryTransactionChg->ParticipantAccount:"<<pRspQryTransactionChg->ParticipantAccount<< endl;
  cout << "on pRspQryTransactionChg->ParticipantID:"<<pRspQryTransactionChg->ParticipantID<< endl;
  cout << "on pRspQryTransactionChg->Amount:"<<pRspQryTransactionChg->Amount<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryTransactionChgField* pNewRspQryTransactionChg =new CShfeFtdcRspQryTransactionChgField;
  memcpy(pNewRspQryTransactionChg,pRspQryTransactionChg,sizeof(CShfeFtdcRspQryTransactionChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTransactionChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTransactionChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryTransactionChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnTransactionChgTopic(CShfeFtdcRtnTransactionChgField *pRtnTransactionChg)
{
  cout << "ok"<< endl;
  cout << "on pRtnTransactionChg->ActionDate:"<<pRtnTransactionChg->ActionDate<< endl;
  cout << "on pRtnTransactionChg->ActionTime:"<<pRtnTransactionChg->ActionTime<< endl;
  cout << "on pRtnTransactionChg->BillSN:"<<pRtnTransactionChg->BillSN<< endl;
  cout << "on pRtnTransactionChg->ParticipantAccount:"<<pRtnTransactionChg->ParticipantAccount<< endl;
  cout << "on pRtnTransactionChg->ParticipantID:"<<pRtnTransactionChg->ParticipantID<< endl;
  cout << "on pRtnTransactionChg->Amount:"<<pRtnTransactionChg->Amount<< endl;
  CShfeFtdcRtnTransactionChgField* pNewRtnTransactionChg =new CShfeFtdcRtnTransactionChgField;
  memcpy(pNewRtnTransactionChg,pRtnTransactionChg,sizeof(CShfeFtdcRtnTransactionChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnTransactionChg;
  asyncOnRtnTransactionChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnTransactionChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryClientChgTopic(CShfeFtdcRspQryClientChgField *pRspQryClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryClientChg->ActionDate:"<<pRspQryClientChg->ActionDate<< endl;
  cout << "on pRspQryClientChg->ActionTime:"<<pRspQryClientChg->ActionTime<< endl;
  cout << "on pRspQryClientChg->ClientID:"<<pRspQryClientChg->ClientID<< endl;
  cout << "on pRspQryClientChg->ClientName:"<<pRspQryClientChg->ClientName<< endl;
  cout << "on pRspQryClientChg->ClientType:"<<pRspQryClientChg->ClientType<< endl;
  cout << "on pRspQryClientChg->IsActive:"<<pRspQryClientChg->IsActive<< endl;
  cout << "on pRspQryClientChg->IdentifiedCardType:"<<pRspQryClientChg->IdentifiedCardType<< endl;
  cout << "on pRspQryClientChg->IdentifiedCardNo:"<<pRspQryClientChg->IdentifiedCardNo<< endl;
  cout << "on pRspQryClientChg->OperationType:"<<pRspQryClientChg->OperationType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryClientChgField* pNewRspQryClientChg =new CShfeFtdcRspQryClientChgField;
  memcpy(pNewRspQryClientChg,pRspQryClientChg,sizeof(CShfeFtdcRspQryClientChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryClientChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryClientChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryClientChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnClientChgTopic(CShfeFtdcRtnClientChgField *pRtnClientChg)
{
  cout << "ok"<< endl;
  cout << "on pRtnClientChg->ActionDate:"<<pRtnClientChg->ActionDate<< endl;
  cout << "on pRtnClientChg->ActionTime:"<<pRtnClientChg->ActionTime<< endl;
  cout << "on pRtnClientChg->ClientID:"<<pRtnClientChg->ClientID<< endl;
  cout << "on pRtnClientChg->ClientName:"<<pRtnClientChg->ClientName<< endl;
  cout << "on pRtnClientChg->ClientType:"<<pRtnClientChg->ClientType<< endl;
  cout << "on pRtnClientChg->IsActive:"<<pRtnClientChg->IsActive<< endl;
  cout << "on pRtnClientChg->IdentifiedCardType:"<<pRtnClientChg->IdentifiedCardType<< endl;
  cout << "on pRtnClientChg->IdentifiedCardNo:"<<pRtnClientChg->IdentifiedCardNo<< endl;
  cout << "on pRtnClientChg->OperationType:"<<pRtnClientChg->OperationType<< endl;
  CShfeFtdcRtnClientChgField* pNewRtnClientChg =new CShfeFtdcRtnClientChgField;
  memcpy(pNewRtnClientChg,pRtnClientChg,sizeof(CShfeFtdcRtnClientChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnClientChg;
  asyncOnRtnClientChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnClientChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryPartClientChgTopic(CShfeFtdcRspQryPartClientChgField *pRspQryPartClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryPartClientChg->ActionDate:"<<pRspQryPartClientChg->ActionDate<< endl;
  cout << "on pRspQryPartClientChg->ActionTime:"<<pRspQryPartClientChg->ActionTime<< endl;
  cout << "on pRspQryPartClientChg->ClientID:"<<pRspQryPartClientChg->ClientID<< endl;
  cout << "on pRspQryPartClientChg->ParticipantID:"<<pRspQryPartClientChg->ParticipantID<< endl;
  cout << "on pRspQryPartClientChg->OperationType:"<<pRspQryPartClientChg->OperationType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryPartClientChgField* pNewRspQryPartClientChg =new CShfeFtdcRspQryPartClientChgField;
  memcpy(pNewRspQryPartClientChg,pRspQryPartClientChg,sizeof(CShfeFtdcRspQryPartClientChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryPartClientChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryPartClientChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryPartClientChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnPartClientChgTopic(CShfeFtdcRtnPartClientChgField *pRtnPartClientChg)
{
  cout << "ok"<< endl;
  cout << "on pRtnPartClientChg->ActionDate:"<<pRtnPartClientChg->ActionDate<< endl;
  cout << "on pRtnPartClientChg->ActionTime:"<<pRtnPartClientChg->ActionTime<< endl;
  cout << "on pRtnPartClientChg->ClientID:"<<pRtnPartClientChg->ClientID<< endl;
  cout << "on pRtnPartClientChg->ParticipantID:"<<pRtnPartClientChg->ParticipantID<< endl;
  cout << "on pRtnPartClientChg->OperationType:"<<pRtnPartClientChg->OperationType<< endl;
  CShfeFtdcRtnPartClientChgField* pNewRtnPartClientChg =new CShfeFtdcRtnPartClientChgField;
  memcpy(pNewRtnPartClientChg,pRtnPartClientChg,sizeof(CShfeFtdcRtnPartClientChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnPartClientChg;
  asyncOnRtnPartClientChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnPartClientChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryPosiLimitChgTopic(CShfeFtdcRspQryPosiLimitChgField *pRspQryPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryPosiLimitChg->ActionDate:"<<pRspQryPosiLimitChg->ActionDate<< endl;
  cout << "on pRspQryPosiLimitChg->ActionTime:"<<pRspQryPosiLimitChg->ActionTime<< endl;
  cout << "on pRspQryPosiLimitChg->InstrumentID:"<<pRspQryPosiLimitChg->InstrumentID<< endl;
  cout << "on pRspQryPosiLimitChg->ParticipantID:"<<pRspQryPosiLimitChg->ParticipantID<< endl;
  cout << "on pRspQryPosiLimitChg->TradingRole:"<<pRspQryPosiLimitChg->TradingRole<< endl;
  cout << "on pRspQryPosiLimitChg->StartTotalPosition:"<<pRspQryPosiLimitChg->StartTotalPosition<< endl;
  cout << "on pRspQryPosiLimitChg->ValueMode:"<<pRspQryPosiLimitChg->ValueMode<< endl;
  cout << "on pRspQryPosiLimitChg->LongPosLimit:"<<pRspQryPosiLimitChg->LongPosLimit<< endl;
  cout << "on pRspQryPosiLimitChg->ShortPosLimit:"<<pRspQryPosiLimitChg->ShortPosLimit<< endl;
  cout << "on pRspQryPosiLimitChg->OperationType:"<<pRspQryPosiLimitChg->OperationType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryPosiLimitChgField* pNewRspQryPosiLimitChg =new CShfeFtdcRspQryPosiLimitChgField;
  memcpy(pNewRspQryPosiLimitChg,pRspQryPosiLimitChg,sizeof(CShfeFtdcRspQryPosiLimitChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryPosiLimitChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryPosiLimitChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryPosiLimitChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnPosiLimitChgTopic(CShfeFtdcRtnPosiLimitChgField *pRtnPosiLimitChg)
{
  cout << "ok"<< endl;
  cout << "on pRtnPosiLimitChg->ActionDate:"<<pRtnPosiLimitChg->ActionDate<< endl;
  cout << "on pRtnPosiLimitChg->ActionTime:"<<pRtnPosiLimitChg->ActionTime<< endl;
  cout << "on pRtnPosiLimitChg->InstrumentID:"<<pRtnPosiLimitChg->InstrumentID<< endl;
  cout << "on pRtnPosiLimitChg->ParticipantID:"<<pRtnPosiLimitChg->ParticipantID<< endl;
  cout << "on pRtnPosiLimitChg->TradingRole:"<<pRtnPosiLimitChg->TradingRole<< endl;
  cout << "on pRtnPosiLimitChg->StartTotalPosition:"<<pRtnPosiLimitChg->StartTotalPosition<< endl;
  cout << "on pRtnPosiLimitChg->ValueMode:"<<pRtnPosiLimitChg->ValueMode<< endl;
  cout << "on pRtnPosiLimitChg->LongPosLimit:"<<pRtnPosiLimitChg->LongPosLimit<< endl;
  cout << "on pRtnPosiLimitChg->ShortPosLimit:"<<pRtnPosiLimitChg->ShortPosLimit<< endl;
  cout << "on pRtnPosiLimitChg->OperationType:"<<pRtnPosiLimitChg->OperationType<< endl;
  CShfeFtdcRtnPosiLimitChgField* pNewRtnPosiLimitChg =new CShfeFtdcRtnPosiLimitChgField;
  memcpy(pNewRtnPosiLimitChg,pRtnPosiLimitChg,sizeof(CShfeFtdcRtnPosiLimitChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnPosiLimitChg;
  asyncOnRtnPosiLimitChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnPosiLimitChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryHedgeDetailChgTopic(CShfeFtdcRspQryHedgeDetailChgField *pRspQryHedgeDetailChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryHedgeDetailChg->ActionDate:"<<pRspQryHedgeDetailChg->ActionDate<< endl;
  cout << "on pRspQryHedgeDetailChg->ActionTime:"<<pRspQryHedgeDetailChg->ActionTime<< endl;
  cout << "on pRspQryHedgeDetailChg->ParticipantID:"<<pRspQryHedgeDetailChg->ParticipantID<< endl;
  cout << "on pRspQryHedgeDetailChg->ClientID:"<<pRspQryHedgeDetailChg->ClientID<< endl;
  cout << "on pRspQryHedgeDetailChg->OperatorID:"<<pRspQryHedgeDetailChg->OperatorID<< endl;
  cout << "on pRspQryHedgeDetailChg->Time:"<<pRspQryHedgeDetailChg->Time<< endl;
  cout << "on pRspQryHedgeDetailChg->InstrumentID:"<<pRspQryHedgeDetailChg->InstrumentID<< endl;
  cout << "on pRspQryHedgeDetailChg->PosiDirection:"<<pRspQryHedgeDetailChg->PosiDirection<< endl;
  cout << "on pRspQryHedgeDetailChg->TradingVolume:"<<pRspQryHedgeDetailChg->TradingVolume<< endl;
  cout << "on pRspQryHedgeDetailChg->HedgeQuota:"<<pRspQryHedgeDetailChg->HedgeQuota<< endl;
  cout << "on pRspQryHedgeDetailChg->OperationType:"<<pRspQryHedgeDetailChg->OperationType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryHedgeDetailChgField* pNewRspQryHedgeDetailChg =new CShfeFtdcRspQryHedgeDetailChgField;
  memcpy(pNewRspQryHedgeDetailChg,pRspQryHedgeDetailChg,sizeof(CShfeFtdcRspQryHedgeDetailChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryHedgeDetailChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryHedgeDetailChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryHedgeDetailChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnHedgeDetailChgTopic(CShfeFtdcRtnHedgeDetailChgField *pRtnHedgeDetailChg)
{
  cout << "ok"<< endl;
  cout << "on pRtnHedgeDetailChg->ActionDate:"<<pRtnHedgeDetailChg->ActionDate<< endl;
  cout << "on pRtnHedgeDetailChg->ActionTime:"<<pRtnHedgeDetailChg->ActionTime<< endl;
  cout << "on pRtnHedgeDetailChg->ParticipantID:"<<pRtnHedgeDetailChg->ParticipantID<< endl;
  cout << "on pRtnHedgeDetailChg->ClientID:"<<pRtnHedgeDetailChg->ClientID<< endl;
  cout << "on pRtnHedgeDetailChg->OperatorID:"<<pRtnHedgeDetailChg->OperatorID<< endl;
  cout << "on pRtnHedgeDetailChg->Time:"<<pRtnHedgeDetailChg->Time<< endl;
  cout << "on pRtnHedgeDetailChg->InstrumentID:"<<pRtnHedgeDetailChg->InstrumentID<< endl;
  cout << "on pRtnHedgeDetailChg->PosiDirection:"<<pRtnHedgeDetailChg->PosiDirection<< endl;
  cout << "on pRtnHedgeDetailChg->TradingVolume:"<<pRtnHedgeDetailChg->TradingVolume<< endl;
  cout << "on pRtnHedgeDetailChg->HedgeQuota:"<<pRtnHedgeDetailChg->HedgeQuota<< endl;
  cout << "on pRtnHedgeDetailChg->OperationType:"<<pRtnHedgeDetailChg->OperationType<< endl;
  CShfeFtdcRtnHedgeDetailChgField* pNewRtnHedgeDetailChg =new CShfeFtdcRtnHedgeDetailChgField;
  memcpy(pNewRtnHedgeDetailChg,pRtnHedgeDetailChg,sizeof(CShfeFtdcRtnHedgeDetailChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnHedgeDetailChg;
  asyncOnRtnHedgeDetailChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnHedgeDetailChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryParticipantChgTopic(CShfeFtdcRspQryParticipantChgField *pRspQryParticipantChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryParticipantChg->ActionDate:"<<pRspQryParticipantChg->ActionDate<< endl;
  cout << "on pRspQryParticipantChg->ActionTime:"<<pRspQryParticipantChg->ActionTime<< endl;
  cout << "on pRspQryParticipantChg->ParticipantID:"<<pRspQryParticipantChg->ParticipantID<< endl;
  cout << "on pRspQryParticipantChg->ParticipantName:"<<pRspQryParticipantChg->ParticipantName<< endl;
  cout << "on pRspQryParticipantChg->ParticipantAbbr:"<<pRspQryParticipantChg->ParticipantAbbr<< endl;
  cout << "on pRspQryParticipantChg->MemberType:"<<pRspQryParticipantChg->MemberType<< endl;
  cout << "on pRspQryParticipantChg->IsActive:"<<pRspQryParticipantChg->IsActive<< endl;
  cout << "on pRspQryParticipantChg->OperationType:"<<pRspQryParticipantChg->OperationType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryParticipantChgField* pNewRspQryParticipantChg =new CShfeFtdcRspQryParticipantChgField;
  memcpy(pNewRspQryParticipantChg,pRspQryParticipantChg,sizeof(CShfeFtdcRspQryParticipantChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryParticipantChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryParticipantChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryParticipantChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnParticipantChgTopic(CShfeFtdcRtnParticipantChgField *pRtnParticipantChg)
{
  cout << "ok"<< endl;
  cout << "on pRtnParticipantChg->ActionDate:"<<pRtnParticipantChg->ActionDate<< endl;
  cout << "on pRtnParticipantChg->ActionTime:"<<pRtnParticipantChg->ActionTime<< endl;
  cout << "on pRtnParticipantChg->ParticipantID:"<<pRtnParticipantChg->ParticipantID<< endl;
  cout << "on pRtnParticipantChg->ParticipantName:"<<pRtnParticipantChg->ParticipantName<< endl;
  cout << "on pRtnParticipantChg->ParticipantAbbr:"<<pRtnParticipantChg->ParticipantAbbr<< endl;
  cout << "on pRtnParticipantChg->MemberType:"<<pRtnParticipantChg->MemberType<< endl;
  cout << "on pRtnParticipantChg->IsActive:"<<pRtnParticipantChg->IsActive<< endl;
  cout << "on pRtnParticipantChg->OperationType:"<<pRtnParticipantChg->OperationType<< endl;
  CShfeFtdcRtnParticipantChgField* pNewRtnParticipantChg =new CShfeFtdcRtnParticipantChgField;
  memcpy(pNewRtnParticipantChg,pRtnParticipantChg,sizeof(CShfeFtdcRtnParticipantChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnParticipantChg;
  asyncOnRtnParticipantChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnParticipantChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryMarginRateChgTopic(CShfeFtdcRspQryMarginRateChgField *pRspQryMarginRateChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryMarginRateChg->ActionDate:"<<pRspQryMarginRateChg->ActionDate<< endl;
  cout << "on pRspQryMarginRateChg->ActionTime:"<<pRspQryMarginRateChg->ActionTime<< endl;
  cout << "on pRspQryMarginRateChg->InstrumentID:"<<pRspQryMarginRateChg->InstrumentID<< endl;
  cout << "on pRspQryMarginRateChg->ParticipantID:"<<pRspQryMarginRateChg->ParticipantID<< endl;
  cout << "on pRspQryMarginRateChg->TradingRole:"<<pRspQryMarginRateChg->TradingRole<< endl;
  cout << "on pRspQryMarginRateChg->HedgeFlag:"<<pRspQryMarginRateChg->HedgeFlag<< endl;
  cout << "on pRspQryMarginRateChg->ValueMode:"<<pRspQryMarginRateChg->ValueMode<< endl;
  cout << "on pRspQryMarginRateChg->LongMarginRatio:"<<pRspQryMarginRateChg->LongMarginRatio<< endl;
  cout << "on pRspQryMarginRateChg->ShortMarginRatio:"<<pRspQryMarginRateChg->ShortMarginRatio<< endl;
  cout << "on pRspQryMarginRateChg->OperationType:"<<pRspQryMarginRateChg->OperationType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryMarginRateChgField* pNewRspQryMarginRateChg =new CShfeFtdcRspQryMarginRateChgField;
  memcpy(pNewRspQryMarginRateChg,pRspQryMarginRateChg,sizeof(CShfeFtdcRspQryMarginRateChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryMarginRateChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryMarginRateChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryMarginRateChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnMarginRateChgTopic(CShfeFtdcRtnMarginRateChgField *pRtnMarginRateChg)
{
  cout << "ok"<< endl;
  cout << "on pRtnMarginRateChg->ActionDate:"<<pRtnMarginRateChg->ActionDate<< endl;
  cout << "on pRtnMarginRateChg->ActionTime:"<<pRtnMarginRateChg->ActionTime<< endl;
  cout << "on pRtnMarginRateChg->InstrumentID:"<<pRtnMarginRateChg->InstrumentID<< endl;
  cout << "on pRtnMarginRateChg->ParticipantID:"<<pRtnMarginRateChg->ParticipantID<< endl;
  cout << "on pRtnMarginRateChg->TradingRole:"<<pRtnMarginRateChg->TradingRole<< endl;
  cout << "on pRtnMarginRateChg->HedgeFlag:"<<pRtnMarginRateChg->HedgeFlag<< endl;
  cout << "on pRtnMarginRateChg->ValueMode:"<<pRtnMarginRateChg->ValueMode<< endl;
  cout << "on pRtnMarginRateChg->LongMarginRatio:"<<pRtnMarginRateChg->LongMarginRatio<< endl;
  cout << "on pRtnMarginRateChg->ShortMarginRatio:"<<pRtnMarginRateChg->ShortMarginRatio<< endl;
  cout << "on pRtnMarginRateChg->OperationType:"<<pRtnMarginRateChg->OperationType<< endl;
  CShfeFtdcRtnMarginRateChgField* pNewRtnMarginRateChg =new CShfeFtdcRtnMarginRateChgField;
  memcpy(pNewRtnMarginRateChg,pRtnMarginRateChg,sizeof(CShfeFtdcRtnMarginRateChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnMarginRateChg;
  asyncOnRtnMarginRateChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnMarginRateChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryUserIpChgTopic(CShfeFtdcRspQryUserIpChgField *pRspQryUserIpChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryUserIpChg->ActionDate:"<<pRspQryUserIpChg->ActionDate<< endl;
  cout << "on pRspQryUserIpChg->ActionTime:"<<pRspQryUserIpChg->ActionTime<< endl;
  cout << "on pRspQryUserIpChg->UserID:"<<pRspQryUserIpChg->UserID<< endl;
  cout << "on pRspQryUserIpChg->IPAddress:"<<pRspQryUserIpChg->IPAddress<< endl;
  cout << "on pRspQryUserIpChg->IPMask:"<<pRspQryUserIpChg->IPMask<< endl;
  cout << "on pRspQryUserIpChg->OperationType:"<<pRspQryUserIpChg->OperationType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryUserIpChgField* pNewRspQryUserIpChg =new CShfeFtdcRspQryUserIpChgField;
  memcpy(pNewRspQryUserIpChg,pRspQryUserIpChg,sizeof(CShfeFtdcRspQryUserIpChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryUserIpChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryUserIpChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryUserIpChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnUserIpChgTopic(CShfeFtdcRtnUserIpChgField *pRtnUserIpChg)
{
  cout << "ok"<< endl;
  cout << "on pRtnUserIpChg->ActionDate:"<<pRtnUserIpChg->ActionDate<< endl;
  cout << "on pRtnUserIpChg->ActionTime:"<<pRtnUserIpChg->ActionTime<< endl;
  cout << "on pRtnUserIpChg->UserID:"<<pRtnUserIpChg->UserID<< endl;
  cout << "on pRtnUserIpChg->IPAddress:"<<pRtnUserIpChg->IPAddress<< endl;
  cout << "on pRtnUserIpChg->IPMask:"<<pRtnUserIpChg->IPMask<< endl;
  cout << "on pRtnUserIpChg->OperationType:"<<pRtnUserIpChg->OperationType<< endl;
  CShfeFtdcRtnUserIpChgField* pNewRtnUserIpChg =new CShfeFtdcRtnUserIpChgField;
  memcpy(pNewRtnUserIpChg,pRtnUserIpChg,sizeof(CShfeFtdcRtnUserIpChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnUserIpChg;
  asyncOnRtnUserIpChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnUserIpChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryClientPosiLimitChgTopic(CShfeFtdcRspQryClientPosiLimitChgField *pRspQryClientPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryClientPosiLimitChg->ActionDate:"<<pRspQryClientPosiLimitChg->ActionDate<< endl;
  cout << "on pRspQryClientPosiLimitChg->ActionTime:"<<pRspQryClientPosiLimitChg->ActionTime<< endl;
  cout << "on pRspQryClientPosiLimitChg->InstrumentID:"<<pRspQryClientPosiLimitChg->InstrumentID<< endl;
  cout << "on pRspQryClientPosiLimitChg->ClientType:"<<pRspQryClientPosiLimitChg->ClientType<< endl;
  cout << "on pRspQryClientPosiLimitChg->TradingRole:"<<pRspQryClientPosiLimitChg->TradingRole<< endl;
  cout << "on pRspQryClientPosiLimitChg->StartTotalPosition:"<<pRspQryClientPosiLimitChg->StartTotalPosition<< endl;
  cout << "on pRspQryClientPosiLimitChg->ValueMode:"<<pRspQryClientPosiLimitChg->ValueMode<< endl;
  cout << "on pRspQryClientPosiLimitChg->LongPosLimit:"<<pRspQryClientPosiLimitChg->LongPosLimit<< endl;
  cout << "on pRspQryClientPosiLimitChg->ShortPosLimit:"<<pRspQryClientPosiLimitChg->ShortPosLimit<< endl;
  cout << "on pRspQryClientPosiLimitChg->OperationType:"<<pRspQryClientPosiLimitChg->OperationType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryClientPosiLimitChgField* pNewRspQryClientPosiLimitChg =new CShfeFtdcRspQryClientPosiLimitChgField;
  memcpy(pNewRspQryClientPosiLimitChg,pRspQryClientPosiLimitChg,sizeof(CShfeFtdcRspQryClientPosiLimitChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryClientPosiLimitChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryClientPosiLimitChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryClientPosiLimitChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnClientPosiLimitChgTopic(CShfeFtdcRtnClientPosiLimitChgField *pRtnClientPosiLimitChg)
{
  cout << "ok"<< endl;
  cout << "on pRtnClientPosiLimitChg->ActionDate:"<<pRtnClientPosiLimitChg->ActionDate<< endl;
  cout << "on pRtnClientPosiLimitChg->ActionTime:"<<pRtnClientPosiLimitChg->ActionTime<< endl;
  cout << "on pRtnClientPosiLimitChg->InstrumentID:"<<pRtnClientPosiLimitChg->InstrumentID<< endl;
  cout << "on pRtnClientPosiLimitChg->ClientType:"<<pRtnClientPosiLimitChg->ClientType<< endl;
  cout << "on pRtnClientPosiLimitChg->TradingRole:"<<pRtnClientPosiLimitChg->TradingRole<< endl;
  cout << "on pRtnClientPosiLimitChg->StartTotalPosition:"<<pRtnClientPosiLimitChg->StartTotalPosition<< endl;
  cout << "on pRtnClientPosiLimitChg->ValueMode:"<<pRtnClientPosiLimitChg->ValueMode<< endl;
  cout << "on pRtnClientPosiLimitChg->LongPosLimit:"<<pRtnClientPosiLimitChg->LongPosLimit<< endl;
  cout << "on pRtnClientPosiLimitChg->ShortPosLimit:"<<pRtnClientPosiLimitChg->ShortPosLimit<< endl;
  cout << "on pRtnClientPosiLimitChg->OperationType:"<<pRtnClientPosiLimitChg->OperationType<< endl;
  CShfeFtdcRtnClientPosiLimitChgField* pNewRtnClientPosiLimitChg =new CShfeFtdcRtnClientPosiLimitChgField;
  memcpy(pNewRtnClientPosiLimitChg,pRtnClientPosiLimitChg,sizeof(CShfeFtdcRtnClientPosiLimitChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnClientPosiLimitChg;
  asyncOnRtnClientPosiLimitChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnClientPosiLimitChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQrySpecPosiLimitChgTopic(CShfeFtdcRspQrySpecPosiLimitChgField *pRspQrySpecPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQrySpecPosiLimitChg->ActionDate:"<<pRspQrySpecPosiLimitChg->ActionDate<< endl;
  cout << "on pRspQrySpecPosiLimitChg->ActionTime:"<<pRspQrySpecPosiLimitChg->ActionTime<< endl;
  cout << "on pRspQrySpecPosiLimitChg->InstrumentID:"<<pRspQrySpecPosiLimitChg->InstrumentID<< endl;
  cout << "on pRspQrySpecPosiLimitChg->ClientID:"<<pRspQrySpecPosiLimitChg->ClientID<< endl;
  cout << "on pRspQrySpecPosiLimitChg->TradingRole:"<<pRspQrySpecPosiLimitChg->TradingRole<< endl;
  cout << "on pRspQrySpecPosiLimitChg->StartTotalPosition:"<<pRspQrySpecPosiLimitChg->StartTotalPosition<< endl;
  cout << "on pRspQrySpecPosiLimitChg->ValueMode:"<<pRspQrySpecPosiLimitChg->ValueMode<< endl;
  cout << "on pRspQrySpecPosiLimitChg->LongPosLimit:"<<pRspQrySpecPosiLimitChg->LongPosLimit<< endl;
  cout << "on pRspQrySpecPosiLimitChg->ShortPosLimit:"<<pRspQrySpecPosiLimitChg->ShortPosLimit<< endl;
  cout << "on pRspQrySpecPosiLimitChg->OperationType:"<<pRspQrySpecPosiLimitChg->OperationType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQrySpecPosiLimitChgField* pNewRspQrySpecPosiLimitChg =new CShfeFtdcRspQrySpecPosiLimitChgField;
  memcpy(pNewRspQrySpecPosiLimitChg,pRspQrySpecPosiLimitChg,sizeof(CShfeFtdcRspQrySpecPosiLimitChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySpecPosiLimitChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySpecPosiLimitChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQrySpecPosiLimitChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnSpecPosiLimitChgTopic(CShfeFtdcRtnSpecPosiLimitChgField *pRtnSpecPosiLimitChg)
{
  cout << "ok"<< endl;
  cout << "on pRtnSpecPosiLimitChg->ActionDate:"<<pRtnSpecPosiLimitChg->ActionDate<< endl;
  cout << "on pRtnSpecPosiLimitChg->ActionTime:"<<pRtnSpecPosiLimitChg->ActionTime<< endl;
  cout << "on pRtnSpecPosiLimitChg->InstrumentID:"<<pRtnSpecPosiLimitChg->InstrumentID<< endl;
  cout << "on pRtnSpecPosiLimitChg->ClientID:"<<pRtnSpecPosiLimitChg->ClientID<< endl;
  cout << "on pRtnSpecPosiLimitChg->TradingRole:"<<pRtnSpecPosiLimitChg->TradingRole<< endl;
  cout << "on pRtnSpecPosiLimitChg->StartTotalPosition:"<<pRtnSpecPosiLimitChg->StartTotalPosition<< endl;
  cout << "on pRtnSpecPosiLimitChg->ValueMode:"<<pRtnSpecPosiLimitChg->ValueMode<< endl;
  cout << "on pRtnSpecPosiLimitChg->LongPosLimit:"<<pRtnSpecPosiLimitChg->LongPosLimit<< endl;
  cout << "on pRtnSpecPosiLimitChg->ShortPosLimit:"<<pRtnSpecPosiLimitChg->ShortPosLimit<< endl;
  cout << "on pRtnSpecPosiLimitChg->OperationType:"<<pRtnSpecPosiLimitChg->OperationType<< endl;
  CShfeFtdcRtnSpecPosiLimitChgField* pNewRtnSpecPosiLimitChg =new CShfeFtdcRtnSpecPosiLimitChgField;
  memcpy(pNewRtnSpecPosiLimitChg,pRtnSpecPosiLimitChg,sizeof(CShfeFtdcRtnSpecPosiLimitChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSpecPosiLimitChg;
  asyncOnRtnSpecPosiLimitChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnSpecPosiLimitChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryHistoryObjectAttrTopic(CShfeFtdcRspQryHistoryObjectAttrField *pRspQryHistoryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryHistoryObjectAttr->MonDate:"<<pRspQryHistoryObjectAttr->MonDate<< endl;
  cout << "on pRspQryHistoryObjectAttr->BeginTime:"<<pRspQryHistoryObjectAttr->BeginTime<< endl;
  cout << "on pRspQryHistoryObjectAttr->EndTime:"<<pRspQryHistoryObjectAttr->EndTime<< endl;
  cout << "on pRspQryHistoryObjectAttr->ObjectID:"<<pRspQryHistoryObjectAttr->ObjectID<< endl;
  cout << "on pRspQryHistoryObjectAttr->AttrType:"<<pRspQryHistoryObjectAttr->AttrType<< endl;
  cout << "on pRspQryHistoryObjectAttr->ValueType:"<<pRspQryHistoryObjectAttr->ValueType<< endl;
  cout << "on pRspQryHistoryObjectAttr->FirstValue:"<<pRspQryHistoryObjectAttr->FirstValue<< endl;
  cout << "on pRspQryHistoryObjectAttr->EndValue:"<<pRspQryHistoryObjectAttr->EndValue<< endl;
  cout << "on pRspQryHistoryObjectAttr->AvgValue:"<<pRspQryHistoryObjectAttr->AvgValue<< endl;
  cout << "on pRspQryHistoryObjectAttr->MinValue:"<<pRspQryHistoryObjectAttr->MinValue<< endl;
  cout << "on pRspQryHistoryObjectAttr->MaxValue:"<<pRspQryHistoryObjectAttr->MaxValue<< endl;
  cout << "on pRspQryHistoryObjectAttr->ValueCount:"<<pRspQryHistoryObjectAttr->ValueCount<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryHistoryObjectAttrField* pNewRspQryHistoryObjectAttr =new CShfeFtdcRspQryHistoryObjectAttrField;
  memcpy(pNewRspQryHistoryObjectAttr,pRspQryHistoryObjectAttr,sizeof(CShfeFtdcRspQryHistoryObjectAttrField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryHistoryObjectAttr;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryHistoryObjectAttrTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryHistoryObjectAttrTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnHistoryObjectAttrTopic(CShfeFtdcRtnHistoryObjectAttrField *pRtnHistoryObjectAttr)
{
  cout << "ok"<< endl;
  cout << "on pRtnHistoryObjectAttr->MonDate:"<<pRtnHistoryObjectAttr->MonDate<< endl;
  cout << "on pRtnHistoryObjectAttr->BeginTime:"<<pRtnHistoryObjectAttr->BeginTime<< endl;
  cout << "on pRtnHistoryObjectAttr->EndTime:"<<pRtnHistoryObjectAttr->EndTime<< endl;
  cout << "on pRtnHistoryObjectAttr->ObjectID:"<<pRtnHistoryObjectAttr->ObjectID<< endl;
  cout << "on pRtnHistoryObjectAttr->AttrType:"<<pRtnHistoryObjectAttr->AttrType<< endl;
  cout << "on pRtnHistoryObjectAttr->ValueType:"<<pRtnHistoryObjectAttr->ValueType<< endl;
  cout << "on pRtnHistoryObjectAttr->FirstValue:"<<pRtnHistoryObjectAttr->FirstValue<< endl;
  cout << "on pRtnHistoryObjectAttr->EndValue:"<<pRtnHistoryObjectAttr->EndValue<< endl;
  cout << "on pRtnHistoryObjectAttr->AvgValue:"<<pRtnHistoryObjectAttr->AvgValue<< endl;
  cout << "on pRtnHistoryObjectAttr->MinValue:"<<pRtnHistoryObjectAttr->MinValue<< endl;
  cout << "on pRtnHistoryObjectAttr->MaxValue:"<<pRtnHistoryObjectAttr->MaxValue<< endl;
  cout << "on pRtnHistoryObjectAttr->ValueCount:"<<pRtnHistoryObjectAttr->ValueCount<< endl;
  CShfeFtdcRtnHistoryObjectAttrField* pNewRtnHistoryObjectAttr =new CShfeFtdcRtnHistoryObjectAttrField;
  memcpy(pNewRtnHistoryObjectAttr,pRtnHistoryObjectAttr,sizeof(CShfeFtdcRtnHistoryObjectAttrField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnHistoryObjectAttr;
  asyncOnRtnHistoryObjectAttrTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnHistoryObjectAttrTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryFrontInfoTopic(CShfeFtdcRspQryFrontInfoField *pRspQryFrontInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryFrontInfo->MonDate:"<<pRspQryFrontInfo->MonDate<< endl;
  cout << "on pRspQryFrontInfo->MonTime:"<<pRspQryFrontInfo->MonTime<< endl;
  cout << "on pRspQryFrontInfo->FrontId:"<<pRspQryFrontInfo->FrontId<< endl;
  cout << "on pRspQryFrontInfo->RspCondition:"<<pRspQryFrontInfo->RspCondition<< endl;
  cout << "on pRspQryFrontInfo->ReqCount:"<<pRspQryFrontInfo->ReqCount<< endl;
  cout << "on pRspQryFrontInfo->ReqRate:"<<pRspQryFrontInfo->ReqRate<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryFrontInfoField* pNewRspQryFrontInfo =new CShfeFtdcRspQryFrontInfoField;
  memcpy(pNewRspQryFrontInfo,pRspQryFrontInfo,sizeof(CShfeFtdcRspQryFrontInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryFrontInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryFrontInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryFrontInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnFrontInfoTopic(CShfeFtdcRtnFrontInfoField *pRtnFrontInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnFrontInfo->MonDate:"<<pRtnFrontInfo->MonDate<< endl;
  cout << "on pRtnFrontInfo->MonTime:"<<pRtnFrontInfo->MonTime<< endl;
  cout << "on pRtnFrontInfo->FrontId:"<<pRtnFrontInfo->FrontId<< endl;
  cout << "on pRtnFrontInfo->RspCondition:"<<pRtnFrontInfo->RspCondition<< endl;
  cout << "on pRtnFrontInfo->ReqCount:"<<pRtnFrontInfo->ReqCount<< endl;
  cout << "on pRtnFrontInfo->ReqRate:"<<pRtnFrontInfo->ReqRate<< endl;
  CShfeFtdcRtnFrontInfoField* pNewRtnFrontInfo =new CShfeFtdcRtnFrontInfoField;
  memcpy(pNewRtnFrontInfo,pRtnFrontInfo,sizeof(CShfeFtdcRtnFrontInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnFrontInfo;
  asyncOnRtnFrontInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnFrontInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQrySysUserLoginTopic(CShfeFtdcRspQrySysUserLoginField *pRspQrySysUserLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "\n**************** SysUserSpi::OnRspQrySysUserLoginTopic: START **************** "<< endl;
  cout << "on pRspQrySysUserLogin->UserID:"<<pRspQrySysUserLogin->UserID<< endl;
  cout << "on pRspQrySysUserLogin->TradingDay:"<<pRspQrySysUserLogin->TradingDay<< endl;
  cout << "on pRspQrySysUserLogin->LoginTime:"<<pRspQrySysUserLogin->LoginTime<< endl;
  cout << "on pRspQrySysUserLogin->Privilege:"<<pRspQrySysUserLogin->Privilege<< endl;
  cout << "on pRspQrySysUserLogin->VersionFlag:"<<pRspQrySysUserLogin->VersionFlag<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQrySysUserLoginField* pNewRspQrySysUserLogin =new CShfeFtdcRspQrySysUserLoginField;
  memcpy(pNewRspQrySysUserLogin,pRspQrySysUserLogin,sizeof(CShfeFtdcRspQrySysUserLoginField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySysUserLogin;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySysUserLoginTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQrySysUserLoginTopic);
  cout << "****************  SysUserSpi::OnRspQrySysUserLoginTopic: END **************** \n"<< endl;
}
void SysUserSpi::OnRspQrySysUserLogoutTopic(CShfeFtdcRspQrySysUserLogoutField *pRspQrySysUserLogout, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQrySysUserLogout->UserID:"<<pRspQrySysUserLogout->UserID<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQrySysUserLogoutField* pNewRspQrySysUserLogout =new CShfeFtdcRspQrySysUserLogoutField;
  memcpy(pNewRspQrySysUserLogout,pRspQrySysUserLogout,sizeof(CShfeFtdcRspQrySysUserLogoutField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySysUserLogout;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySysUserLogoutTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQrySysUserLogoutTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQrySysUserPasswordUpdateTopic(CShfeFtdcRspQrySysUserPasswordUpdateField *pRspQrySysUserPasswordUpdate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQrySysUserPasswordUpdate->UserID:"<<pRspQrySysUserPasswordUpdate->UserID<< endl;
  cout << "on pRspQrySysUserPasswordUpdate->PasswordChgMsg:"<<pRspQrySysUserPasswordUpdate->PasswordChgMsg<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQrySysUserPasswordUpdateField* pNewRspQrySysUserPasswordUpdate =new CShfeFtdcRspQrySysUserPasswordUpdateField;
  memcpy(pNewRspQrySysUserPasswordUpdate,pRspQrySysUserPasswordUpdate,sizeof(CShfeFtdcRspQrySysUserPasswordUpdateField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySysUserPasswordUpdate;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySysUserPasswordUpdateTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQrySysUserPasswordUpdateTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQrySysUserRegisterTopic(CShfeFtdcRspQrySysUserRegisterField *pRspQrySysUserRegister, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQrySysUserRegister->UserID:"<<pRspQrySysUserRegister->UserID<< endl;
  cout << "on pRspQrySysUserRegister->Privilege:"<<pRspQrySysUserRegister->Privilege<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQrySysUserRegisterField* pNewRspQrySysUserRegister =new CShfeFtdcRspQrySysUserRegisterField;
  memcpy(pNewRspQrySysUserRegister,pRspQrySysUserRegister,sizeof(CShfeFtdcRspQrySysUserRegisterField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySysUserRegister;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySysUserRegisterTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQrySysUserRegisterTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQrySysUserDeleteTopic(CShfeFtdcRspQrySysUserDeleteField *pRspQrySysUserDelete, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQrySysUserDelete->UserID:"<<pRspQrySysUserDelete->UserID<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQrySysUserDeleteField* pNewRspQrySysUserDelete =new CShfeFtdcRspQrySysUserDeleteField;
  memcpy(pNewRspQrySysUserDelete,pRspQrySysUserDelete,sizeof(CShfeFtdcRspQrySysUserDeleteField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySysUserDelete;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySysUserDeleteTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQrySysUserDeleteTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryParticipantInitTopic(CShfeFtdcRspQryParticipantInitField *pRspQryParticipantInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryParticipantInit->ParticipantID:"<<pRspQryParticipantInit->ParticipantID<< endl;
  cout << "on pRspQryParticipantInit->ParticipantName:"<<pRspQryParticipantInit->ParticipantName<< endl;
  cout << "on pRspQryParticipantInit->ParticipantAbbr:"<<pRspQryParticipantInit->ParticipantAbbr<< endl;
  cout << "on pRspQryParticipantInit->MemberType:"<<pRspQryParticipantInit->MemberType<< endl;
  cout << "on pRspQryParticipantInit->IsActive:"<<pRspQryParticipantInit->IsActive<< endl;
  cout << "on pRspQryParticipantInit->OperationType:"<<pRspQryParticipantInit->OperationType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryParticipantInitField* pNewRspQryParticipantInit =new CShfeFtdcRspQryParticipantInitField;
  memcpy(pNewRspQryParticipantInit,pRspQryParticipantInit,sizeof(CShfeFtdcRspQryParticipantInitField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryParticipantInit;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryParticipantInitTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryParticipantInitTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnParticipantInitTopic(CShfeFtdcRtnParticipantInitField *pRtnParticipantInit)
{
  cout << "ok"<< endl;
  cout << "on pRtnParticipantInit->ParticipantID:"<<pRtnParticipantInit->ParticipantID<< endl;
  cout << "on pRtnParticipantInit->ParticipantName:"<<pRtnParticipantInit->ParticipantName<< endl;
  cout << "on pRtnParticipantInit->ParticipantAbbr:"<<pRtnParticipantInit->ParticipantAbbr<< endl;
  cout << "on pRtnParticipantInit->MemberType:"<<pRtnParticipantInit->MemberType<< endl;
  cout << "on pRtnParticipantInit->IsActive:"<<pRtnParticipantInit->IsActive<< endl;
  cout << "on pRtnParticipantInit->OperationType:"<<pRtnParticipantInit->OperationType<< endl;
  CShfeFtdcRtnParticipantInitField* pNewRtnParticipantInit =new CShfeFtdcRtnParticipantInitField;
  memcpy(pNewRtnParticipantInit,pRtnParticipantInit,sizeof(CShfeFtdcRtnParticipantInitField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnParticipantInit;
  asyncOnRtnParticipantInitTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnParticipantInitTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryUserInitTopic(CShfeFtdcRspQryUserInitField *pRspQryUserInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryUserInit->ParticipantID:"<<pRspQryUserInit->ParticipantID<< endl;
  cout << "on pRspQryUserInit->UserID:"<<pRspQryUserInit->UserID<< endl;
  cout << "on pRspQryUserInit->UserType:"<<pRspQryUserInit->UserType<< endl;
  cout << "on pRspQryUserInit->Password:"<<pRspQryUserInit->Password<< endl;
  cout << "on pRspQryUserInit->IsActive:"<<pRspQryUserInit->IsActive<< endl;
  cout << "on pRspQryUserInit->OperationType:"<<pRspQryUserInit->OperationType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryUserInitField* pNewRspQryUserInit =new CShfeFtdcRspQryUserInitField;
  memcpy(pNewRspQryUserInit,pRspQryUserInit,sizeof(CShfeFtdcRspQryUserInitField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryUserInit;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryUserInitTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryUserInitTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnUserInitTopic(CShfeFtdcRtnUserInitField *pRtnUserInit)
{
  cout << "ok"<< endl;
  cout << "on pRtnUserInit->ParticipantID:"<<pRtnUserInit->ParticipantID<< endl;
  cout << "on pRtnUserInit->UserID:"<<pRtnUserInit->UserID<< endl;
  cout << "on pRtnUserInit->UserType:"<<pRtnUserInit->UserType<< endl;
  cout << "on pRtnUserInit->Password:"<<pRtnUserInit->Password<< endl;
  cout << "on pRtnUserInit->IsActive:"<<pRtnUserInit->IsActive<< endl;
  cout << "on pRtnUserInit->OperationType:"<<pRtnUserInit->OperationType<< endl;
  CShfeFtdcRtnUserInitField* pNewRtnUserInit =new CShfeFtdcRtnUserInitField;
  memcpy(pNewRtnUserInit,pRtnUserInit,sizeof(CShfeFtdcRtnUserInitField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnUserInit;
  asyncOnRtnUserInitTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnUserInitTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryClientInitTopic(CShfeFtdcRspQryClientInitField *pRspQryClientInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryClientInit->ClientID:"<<pRspQryClientInit->ClientID<< endl;
  cout << "on pRspQryClientInit->ClientName:"<<pRspQryClientInit->ClientName<< endl;
  cout << "on pRspQryClientInit->IdentifiedCardType:"<<pRspQryClientInit->IdentifiedCardType<< endl;
  cout << "on pRspQryClientInit->IdentifiedCardNo:"<<pRspQryClientInit->IdentifiedCardNo<< endl;
  cout << "on pRspQryClientInit->TradingRole:"<<pRspQryClientInit->TradingRole<< endl;
  cout << "on pRspQryClientInit->ClientType:"<<pRspQryClientInit->ClientType<< endl;
  cout << "on pRspQryClientInit->IsActive:"<<pRspQryClientInit->IsActive<< endl;
  cout << "on pRspQryClientInit->OperationType:"<<pRspQryClientInit->OperationType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryClientInitField* pNewRspQryClientInit =new CShfeFtdcRspQryClientInitField;
  memcpy(pNewRspQryClientInit,pRspQryClientInit,sizeof(CShfeFtdcRspQryClientInitField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryClientInit;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryClientInitTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryClientInitTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnClientInitTopic(CShfeFtdcRtnClientInitField *pRtnClientInit)
{
  cout << "ok"<< endl;
  cout << "on pRtnClientInit->ClientID:"<<pRtnClientInit->ClientID<< endl;
  cout << "on pRtnClientInit->ClientName:"<<pRtnClientInit->ClientName<< endl;
  cout << "on pRtnClientInit->IdentifiedCardType:"<<pRtnClientInit->IdentifiedCardType<< endl;
  cout << "on pRtnClientInit->IdentifiedCardNo:"<<pRtnClientInit->IdentifiedCardNo<< endl;
  cout << "on pRtnClientInit->TradingRole:"<<pRtnClientInit->TradingRole<< endl;
  cout << "on pRtnClientInit->ClientType:"<<pRtnClientInit->ClientType<< endl;
  cout << "on pRtnClientInit->IsActive:"<<pRtnClientInit->IsActive<< endl;
  cout << "on pRtnClientInit->OperationType:"<<pRtnClientInit->OperationType<< endl;
  CShfeFtdcRtnClientInitField* pNewRtnClientInit =new CShfeFtdcRtnClientInitField;
  memcpy(pNewRtnClientInit,pRtnClientInit,sizeof(CShfeFtdcRtnClientInitField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnClientInit;
  asyncOnRtnClientInitTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnClientInitTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryTradeLogTopic(CShfeFtdcRspQryTradeLogField *pRspQryTradeLog, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryTradeLog->bFlag:"<<pRspQryTradeLog->bFlag<< endl;
  cout << "on pRspQryTradeLog->TradeLogStr:"<<pRspQryTradeLog->TradeLogStr<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryTradeLogField* pNewRspQryTradeLog =new CShfeFtdcRspQryTradeLogField;
  memcpy(pNewRspQryTradeLog,pRspQryTradeLog,sizeof(CShfeFtdcRspQryTradeLogField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTradeLog;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTradeLogTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryTradeLogTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnTradeLogTopic(CShfeFtdcRtnTradeLogField *pRtnTradeLog)
{
  cout << "ok"<< endl;
  cout << "on pRtnTradeLog->bFlag:"<<pRtnTradeLog->bFlag<< endl;
  cout << "on pRtnTradeLog->TradeLogStr:"<<pRtnTradeLog->TradeLogStr<< endl;
  CShfeFtdcRtnTradeLogField* pNewRtnTradeLog =new CShfeFtdcRtnTradeLogField;
  memcpy(pNewRtnTradeLog,pRtnTradeLog,sizeof(CShfeFtdcRtnTradeLogField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnTradeLog;
  asyncOnRtnTradeLogTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnTradeLogTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryTradeUserLoginInfoTopic(CShfeFtdcRspQryTradeUserLoginInfoField *pRspQryTradeUserLoginInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "SysUserSpi::OnRspQryTradeUserLoginInfoTopic: ok"<< endl;
  cout << "on pRspQryTradeUserLoginInfo->ObjectID:"<<pRspQryTradeUserLoginInfo->ObjectID<< endl;
  cout << "on pRspQryTradeUserLoginInfo->UserID:"<<pRspQryTradeUserLoginInfo->UserID<< endl;
  cout << "on pRspQryTradeUserLoginInfo->ParticipantID:"<<pRspQryTradeUserLoginInfo->ParticipantID<< endl;
  cout << "on pRspQryTradeUserLoginInfo->ProtocolInfo:"<<pRspQryTradeUserLoginInfo->ProtocolInfo<< endl;
  cout << "on pRspQryTradeUserLoginInfo->IPAddress:"<<pRspQryTradeUserLoginInfo->IPAddress<< endl;
  cout << "on pRspQryTradeUserLoginInfo->FrontID:"<<pRspQryTradeUserLoginInfo->FrontID<< endl;
  cout << "on pRspQryTradeUserLoginInfo->UserType:"<<pRspQryTradeUserLoginInfo->UserType<< endl;
  cout << "on pRspQryTradeUserLoginInfo->AccessType:"<<pRspQryTradeUserLoginInfo->AccessType<< endl;
  cout << "on pRspQryTradeUserLoginInfo->ActionDate:"<<pRspQryTradeUserLoginInfo->ActionDate<< endl;
  cout << "on pRspQryTradeUserLoginInfo->ActionTime:"<<pRspQryTradeUserLoginInfo->ActionTime<< endl;
  cout << "on pRspQryTradeUserLoginInfo->ActionFlag:"<<pRspQryTradeUserLoginInfo->ActionFlag<< endl;
  cout << "on pRspQryTradeUserLoginInfo->DataCenter:"<<pRspQryTradeUserLoginInfo->DataCenter<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryTradeUserLoginInfoField* pNewRspQryTradeUserLoginInfo =new CShfeFtdcRspQryTradeUserLoginInfoField;
  memcpy(pNewRspQryTradeUserLoginInfo,pRspQryTradeUserLoginInfo,sizeof(CShfeFtdcRspQryTradeUserLoginInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTradeUserLoginInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTradeUserLoginInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryTradeUserLoginInfoTopic);
  cout << "SysUserSpi::OnRspQryTradeUserLoginInfoTopic: end send \n"<< endl;
}
void SysUserSpi::OnRtnTradeUserLoginInfoTopic(CShfeFtdcRtnTradeUserLoginInfoField *pRtnTradeUserLoginInfo)
{
  cout << "\n********** Spi::OnRtnTradeUserLoginInfoTopic: START ********"<< endl;
  cout << "on pRtnTradeUserLoginInfo->ObjectID:"<<pRtnTradeUserLoginInfo->ObjectID<< endl;
  cout << "on pRtnTradeUserLoginInfo->UserID:"<<pRtnTradeUserLoginInfo->UserID<< endl;
  cout << "on pRtnTradeUserLoginInfo->ParticipantID:"<<pRtnTradeUserLoginInfo->ParticipantID<< endl;
  cout << "on pRtnTradeUserLoginInfo->ProtocolInfo:"<<pRtnTradeUserLoginInfo->ProtocolInfo<< endl;
  cout << "on pRtnTradeUserLoginInfo->IPAddress:"<<pRtnTradeUserLoginInfo->IPAddress<< endl;
  cout << "on pRtnTradeUserLoginInfo->FrontID:"<<pRtnTradeUserLoginInfo->FrontID<< endl;
  cout << "on pRtnTradeUserLoginInfo->UserType:"<<pRtnTradeUserLoginInfo->UserType<< endl;
  cout << "on pRtnTradeUserLoginInfo->AccessType:"<<pRtnTradeUserLoginInfo->AccessType<< endl;
  cout << "on pRtnTradeUserLoginInfo->ActionDate:"<<pRtnTradeUserLoginInfo->ActionDate<< endl;
  cout << "on pRtnTradeUserLoginInfo->ActionTime:"<<pRtnTradeUserLoginInfo->ActionTime<< endl;
  cout << "on pRtnTradeUserLoginInfo->ActionFlag:"<<pRtnTradeUserLoginInfo->ActionFlag<< endl;
  cout << "on pRtnTradeUserLoginInfo->DataCenter:"<<pRtnTradeUserLoginInfo->DataCenter<< endl;
  CShfeFtdcRtnTradeUserLoginInfoField* pNewRtnTradeUserLoginInfo =new CShfeFtdcRtnTradeUserLoginInfoField;
  memcpy(pNewRtnTradeUserLoginInfo,pRtnTradeUserLoginInfo,sizeof(CShfeFtdcRtnTradeUserLoginInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnTradeUserLoginInfo;
  asyncOnRtnTradeUserLoginInfoTopic.data=(void*)&paramArray[0];
  
  uv_mutex_lock(&g_RtnTradeUserLoginInfoTopic_data_mutex);
  
  g_RtnTradeUserLoginInfoTopic_queue.push(paramArray);
  
  uv_mutex_unlock(&g_RtnTradeUserLoginInfoTopic_data_mutex);

  uv_sem_wait(&g_RtnTradeUserLoginInfoTopic_sem);
  uv_mutex_lock(&g_RtnTradeUserLoginInfoTopic_mutex);  
  
  std::cout << "**** g_RtnTradeUserLoginInfoTopic_Sys_index: " 
              << g_RtnTradeUserLoginInfoTopic_Sys_index++ << endl;  
  // uv_async_send(&asyncOnRtnTradeUserLoginInfoTopic);
  
  uv_mutex_unlock(&g_RtnTradeUserLoginInfoTopic_mutex);  
  
  cout << "********** Spi::OnRtnTradeUserLoginInfoTopic: END! ********\n"<< endl;
}
void SysUserSpi::OnRspQryPartTradeTopic(CShfeFtdcRspQryPartTradeField *pRspQryPartTrade, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryPartTrade->ActionDate:"<<pRspQryPartTrade->ActionDate<< endl;
  cout << "on pRspQryPartTrade->ActionTime:"<<pRspQryPartTrade->ActionTime<< endl;
  cout << "on pRspQryPartTrade->InstrumentID:"<<pRspQryPartTrade->InstrumentID<< endl;
  cout << "on pRspQryPartTrade->ParticipantID:"<<pRspQryPartTrade->ParticipantID<< endl;
  cout << "on pRspQryPartTrade->TotalPositiveOrder:"<<pRspQryPartTrade->TotalPositiveOrder<< endl;
  cout << "on pRspQryPartTrade->TotalNegativeOrder:"<<pRspQryPartTrade->TotalNegativeOrder<< endl;
  cout << "on pRspQryPartTrade->TotalPositiveTrade:"<<pRspQryPartTrade->TotalPositiveTrade<< endl;
  cout << "on pRspQryPartTrade->TotalNegativeTrade:"<<pRspQryPartTrade->TotalNegativeTrade<< endl;
  cout << "on pRspQryPartTrade->TotalPositivePosi:"<<pRspQryPartTrade->TotalPositivePosi<< endl;
  cout << "on pRspQryPartTrade->TotalNegativePosi:"<<pRspQryPartTrade->TotalNegativePosi<< endl;
  cout << "on pRspQryPartTrade->OperationType:"<<pRspQryPartTrade->OperationType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryPartTradeField* pNewRspQryPartTrade =new CShfeFtdcRspQryPartTradeField;
  memcpy(pNewRspQryPartTrade,pRspQryPartTrade,sizeof(CShfeFtdcRspQryPartTradeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryPartTrade;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryPartTradeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryPartTradeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryTradepeakTopic(CShfeFtdcRspQryTradepeakField *pRspQryTradepeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryTradepeak->TradepeakFlag:"<<pRspQryTradepeak->TradepeakFlag<< endl;
  cout << "on pRspQryTradepeak->PeakTime:"<<pRspQryTradepeak->PeakTime<< endl;
  cout << "on pRspQryTradepeak->InsertOrder:"<<pRspQryTradepeak->InsertOrder<< endl;
  cout << "on pRspQryTradepeak->ActionOrder:"<<pRspQryTradepeak->ActionOrder<< endl;
  cout << "on pRspQryTradepeak->InvalidOrder:"<<pRspQryTradepeak->InvalidOrder<< endl;
  cout << "on pRspQryTradepeak->TotalBusiness:"<<pRspQryTradepeak->TotalBusiness<< endl;
  cout << "on pRspQryTradepeak->TradeCount:"<<pRspQryTradepeak->TradeCount<< endl;
  cout << "on pRspQryTradepeak->TotalCount:"<<pRspQryTradepeak->TotalCount<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryTradepeakField* pNewRspQryTradepeak =new CShfeFtdcRspQryTradepeakField;
  memcpy(pNewRspQryTradepeak,pRspQryTradepeak,sizeof(CShfeFtdcRspQryTradepeakField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTradepeak;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTradepeakTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryTradepeakTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnUpdateSysConfigTopic(CShfeFtdcRtnUpdateSysConfigField *pRtnUpdateSysConfig)
{
  cout << "ok"<< endl;
  cout << "on pRtnUpdateSysConfig->UpdateType:"<<pRtnUpdateSysConfig->UpdateType<< endl;
  cout << "on pRtnUpdateSysConfig->OldValue:"<<pRtnUpdateSysConfig->OldValue<< endl;
  cout << "on pRtnUpdateSysConfig->NewValue:"<<pRtnUpdateSysConfig->NewValue<< endl;
  cout << "on pRtnUpdateSysConfig->Standby:"<<pRtnUpdateSysConfig->Standby<< endl;
  CShfeFtdcRtnUpdateSysConfigField* pNewRtnUpdateSysConfig =new CShfeFtdcRtnUpdateSysConfigField;
  memcpy(pNewRtnUpdateSysConfig,pRtnUpdateSysConfig,sizeof(CShfeFtdcRtnUpdateSysConfigField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnUpdateSysConfig;
  asyncOnRtnUpdateSysConfigTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnUpdateSysConfigTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnSysUser(CShfeFtdcRtnSysUserField *pRtnSysUser)
{
  cout << "ok"<< endl;
  cout << "on pRtnSysUser->UserID:"<<pRtnSysUser->UserID<< endl;
  cout << "on pRtnSysUser->UserName:"<<pRtnSysUser->UserName<< endl;
  cout << "on pRtnSysUser->UserInfo:"<<pRtnSysUser->UserInfo<< endl;
  cout << "on pRtnSysUser->Password:"<<pRtnSysUser->Password<< endl;
  cout << "on pRtnSysUser->Privilege:"<<pRtnSysUser->Privilege<< endl;
  cout << "on pRtnSysUser->EMail:"<<pRtnSysUser->EMail<< endl;
  cout << "on pRtnSysUser->EMailFlag:"<<pRtnSysUser->EMailFlag<< endl;
  cout << "on pRtnSysUser->HomePhone:"<<pRtnSysUser->HomePhone<< endl;
  cout << "on pRtnSysUser->HomePhoneFlag:"<<pRtnSysUser->HomePhoneFlag<< endl;
  cout << "on pRtnSysUser->MobilePhone:"<<pRtnSysUser->MobilePhone<< endl;
  cout << "on pRtnSysUser->MobilePhoneFlag:"<<pRtnSysUser->MobilePhoneFlag<< endl;
  CShfeFtdcRtnSysUserField* pNewRtnSysUser =new CShfeFtdcRtnSysUserField;
  memcpy(pNewRtnSysUser,pRtnSysUser,sizeof(CShfeFtdcRtnSysUserField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSysUser;
  asyncOnRtnSysUser.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnSysUser);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnPriceLimitChgTopic(CShfeFtdcRtnPriceLimitChgField *pRtnPriceLimitChg)
{
  cout << "ok"<< endl;
  cout << "on pRtnPriceLimitChg->ActionDate:"<<pRtnPriceLimitChg->ActionDate<< endl;
  cout << "on pRtnPriceLimitChg->ActionTime:"<<pRtnPriceLimitChg->ActionTime<< endl;
  cout << "on pRtnPriceLimitChg->InstrumentID:"<<pRtnPriceLimitChg->InstrumentID<< endl;
  cout << "on pRtnPriceLimitChg->ValueMode:"<<pRtnPriceLimitChg->ValueMode<< endl;
  cout << "on pRtnPriceLimitChg->RoundingMode:"<<pRtnPriceLimitChg->RoundingMode<< endl;
  cout << "on pRtnPriceLimitChg->UpperLimitPrice:"<<pRtnPriceLimitChg->UpperLimitPrice<< endl;
  cout << "on pRtnPriceLimitChg->LowerLimitPrice:"<<pRtnPriceLimitChg->LowerLimitPrice<< endl;
  cout << "on pRtnPriceLimitChg->OperationType:"<<pRtnPriceLimitChg->OperationType<< endl;
  CShfeFtdcRtnPriceLimitChgField* pNewRtnPriceLimitChg =new CShfeFtdcRtnPriceLimitChgField;
  memcpy(pNewRtnPriceLimitChg,pRtnPriceLimitChg,sizeof(CShfeFtdcRtnPriceLimitChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnPriceLimitChg;
  asyncOnRtnPriceLimitChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnPriceLimitChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryHistoryCpuInfoTopic(CShfeFtdcRspQryHistoryCpuInfoField *pRspQryHistoryCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryHistoryCpuInfo->HostName:"<<pRspQryHistoryCpuInfo->HostName<< endl;
  cout << "on pRspQryHistoryCpuInfo->MonDate:"<<pRspQryHistoryCpuInfo->MonDate<< endl;
  cout << "on pRspQryHistoryCpuInfo->MonTime:"<<pRspQryHistoryCpuInfo->MonTime<< endl;
  cout << "on pRspQryHistoryCpuInfo->CPU:"<<pRspQryHistoryCpuInfo->CPU<< endl;
  cout << "on pRspQryHistoryCpuInfo->LOAD:"<<pRspQryHistoryCpuInfo->LOAD<< endl;
  cout << "on pRspQryHistoryCpuInfo->USER:"<<pRspQryHistoryCpuInfo->USER<< endl;
  cout << "on pRspQryHistoryCpuInfo->NICE:"<<pRspQryHistoryCpuInfo->NICE<< endl;
  cout << "on pRspQryHistoryCpuInfo->SYS:"<<pRspQryHistoryCpuInfo->SYS<< endl;
  cout << "on pRspQryHistoryCpuInfo->IDLE:"<<pRspQryHistoryCpuInfo->IDLE<< endl;
  cout << "on pRspQryHistoryCpuInfo->BLOCK:"<<pRspQryHistoryCpuInfo->BLOCK<< endl;
  cout << "on pRspQryHistoryCpuInfo->SWAIT:"<<pRspQryHistoryCpuInfo->SWAIT<< endl;
  cout << "on pRspQryHistoryCpuInfo->INTR:"<<pRspQryHistoryCpuInfo->INTR<< endl;
  cout << "on pRspQryHistoryCpuInfo->SSYS:"<<pRspQryHistoryCpuInfo->SSYS<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryHistoryCpuInfoField* pNewRspQryHistoryCpuInfo =new CShfeFtdcRspQryHistoryCpuInfoField;
  memcpy(pNewRspQryHistoryCpuInfo,pRspQryHistoryCpuInfo,sizeof(CShfeFtdcRspQryHistoryCpuInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryHistoryCpuInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryHistoryCpuInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryHistoryCpuInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryHistoryMemInfoTopic(CShfeFtdcRspQryHistoryMemInfoField *pRspQryHistoryMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "\n******* SysUserSpi::OnRspQryHistoryMemInfoTopic: START *******"<< endl;
  cout << "on pRspQryHistoryMemInfo->HostName:"<<pRspQryHistoryMemInfo->HostName<< endl;
  cout << "on pRspQryHistoryMemInfo->MonDate:"<<pRspQryHistoryMemInfo->MonDate<< endl;
  cout << "on pRspQryHistoryMemInfo->MonTime:"<<pRspQryHistoryMemInfo->MonTime<< endl;
  cout << "on pRspQryHistoryMemInfo->TOTALREAL:"<<pRspQryHistoryMemInfo->TOTALREAL<< endl;
  cout << "on pRspQryHistoryMemInfo->ACTIVEREAL:"<<pRspQryHistoryMemInfo->ACTIVEREAL<< endl;
  cout << "on pRspQryHistoryMemInfo->TOTALVIRTUAL:"<<pRspQryHistoryMemInfo->TOTALVIRTUAL<< endl;
  cout << "on pRspQryHistoryMemInfo->ACTIVEVIRTUAL:"<<pRspQryHistoryMemInfo->ACTIVEVIRTUAL<< endl;
  cout << "on pRspQryHistoryMemInfo->FREE:"<<pRspQryHistoryMemInfo->FREE<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryHistoryMemInfoField* pNewRspQryHistoryMemInfo =new CShfeFtdcRspQryHistoryMemInfoField;
  memcpy(pNewRspQryHistoryMemInfo,pRspQryHistoryMemInfo,sizeof(CShfeFtdcRspQryHistoryMemInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryHistoryMemInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryHistoryMemInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryHistoryMemInfoTopic);
  cout << "******* SysUserSpi::OnRspQryHistoryMemInfoTopic: END *******\n"<< endl;
}
void SysUserSpi::OnRspQryHistoryNetworkInfoTopic(CShfeFtdcRspQryHistoryNetworkInfoField *pRspQryHistoryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryHistoryNetworkInfo->HostName:"<<pRspQryHistoryNetworkInfo->HostName<< endl;
  cout << "on pRspQryHistoryNetworkInfo->MonDate:"<<pRspQryHistoryNetworkInfo->MonDate<< endl;
  cout << "on pRspQryHistoryNetworkInfo->MonTime:"<<pRspQryHistoryNetworkInfo->MonTime<< endl;
  cout << "on pRspQryHistoryNetworkInfo->LANNAME:"<<pRspQryHistoryNetworkInfo->LANNAME<< endl;
  cout << "on pRspQryHistoryNetworkInfo->LANSTATUS:"<<pRspQryHistoryNetworkInfo->LANSTATUS<< endl;
  cout << "on pRspQryHistoryNetworkInfo->IPADDRESS:"<<pRspQryHistoryNetworkInfo->IPADDRESS<< endl;
  cout << "on pRspQryHistoryNetworkInfo->RECVBYTES:"<<pRspQryHistoryNetworkInfo->RECVBYTES<< endl;
  cout << "on pRspQryHistoryNetworkInfo->RECVPACKETS:"<<pRspQryHistoryNetworkInfo->RECVPACKETS<< endl;
  cout << "on pRspQryHistoryNetworkInfo->RECVERRORPACKETS:"<<pRspQryHistoryNetworkInfo->RECVERRORPACKETS<< endl;
  cout << "on pRspQryHistoryNetworkInfo->RECVDROPPACKETS:"<<pRspQryHistoryNetworkInfo->RECVDROPPACKETS<< endl;
  cout << "on pRspQryHistoryNetworkInfo->SENDBYTES:"<<pRspQryHistoryNetworkInfo->SENDBYTES<< endl;
  cout << "on pRspQryHistoryNetworkInfo->SENDPACKETS:"<<pRspQryHistoryNetworkInfo->SENDPACKETS<< endl;
  cout << "on pRspQryHistoryNetworkInfo->SENDERRORPACKETS:"<<pRspQryHistoryNetworkInfo->SENDERRORPACKETS<< endl;
  cout << "on pRspQryHistoryNetworkInfo->SENDDROPPACKETS:"<<pRspQryHistoryNetworkInfo->SENDDROPPACKETS<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryHistoryNetworkInfoField* pNewRspQryHistoryNetworkInfo =new CShfeFtdcRspQryHistoryNetworkInfoField;
  memcpy(pNewRspQryHistoryNetworkInfo,pRspQryHistoryNetworkInfo,sizeof(CShfeFtdcRspQryHistoryNetworkInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryHistoryNetworkInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryHistoryNetworkInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryHistoryNetworkInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryMonitorOnlineUser(CShfeFtdcRspQryMonitorOnlineUserField *pRspQryMonitorOnlineUser, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryMonitorOnlineUser->UserID:"<<pRspQryMonitorOnlineUser->UserID<< endl;
  cout << "on pRspQryMonitorOnlineUser->IPAddress:"<<pRspQryMonitorOnlineUser->IPAddress<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryMonitorOnlineUserField* pNewRspQryMonitorOnlineUser =new CShfeFtdcRspQryMonitorOnlineUserField;
  memcpy(pNewRspQryMonitorOnlineUser,pRspQryMonitorOnlineUser,sizeof(CShfeFtdcRspQryMonitorOnlineUserField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryMonitorOnlineUser;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryMonitorOnlineUser.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryMonitorOnlineUser);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryFrontStat(CShfeFtdcRspQryFrontStatField *pRspQryFrontStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryFrontStat->FrontID:"<<pRspQryFrontStat->FrontID<< endl;
  cout << "on pRspQryFrontStat->PositiveOrder:"<<pRspQryFrontStat->PositiveOrder<< endl;
  cout << "on pRspQryFrontStat->NegativeOrder:"<<pRspQryFrontStat->NegativeOrder<< endl;
  cout << "on pRspQryFrontStat->TotalPositiveOrder:"<<pRspQryFrontStat->TotalPositiveOrder<< endl;
  cout << "on pRspQryFrontStat->TotalNegativeOrder:"<<pRspQryFrontStat->TotalNegativeOrder<< endl;
  cout << "on pRspQryFrontStat->OrderAction:"<<pRspQryFrontStat->OrderAction<< endl;
  cout << "on pRspQryFrontStat->TotalOrderAction:"<<pRspQryFrontStat->TotalOrderAction<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryFrontStatField* pNewRspQryFrontStat =new CShfeFtdcRspQryFrontStatField;
  memcpy(pNewRspQryFrontStat,pRspQryFrontStat,sizeof(CShfeFtdcRspQryFrontStatField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryFrontStat;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryFrontStat.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryFrontStat);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnSysTimeSyncTopic(CShfeFtdcRtnSysTimeSyncField *pRtnSysTimeSync)
{
  cout << "\n****************SysUserSpi::OnRtnSysTimeSyncTopic: START ****************"<< endl;
  try {
      cout << "on pRtnSysTimeSync->MonDate:"<<pRtnSysTimeSync->MonDate<< endl;
  cout << "on pRtnSysTimeSync->MonTime:"<<pRtnSysTimeSync->MonTime<< endl;
  CShfeFtdcRtnSysTimeSyncField* pNewRtnSysTimeSync =new CShfeFtdcRtnSysTimeSyncField;
  memcpy(pNewRtnSysTimeSync,pRtnSysTimeSync,sizeof(CShfeFtdcRtnSysTimeSyncField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSysTimeSync;
  asyncOnRtnSysTimeSyncTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnSysTimeSyncTopic);
  cout << "**************** SysUserSpi::OnRtnSysTimeSyncTopic: END ****************\n"<< endl;
  } catch (exception& error) {
    
    cout << "exception: " << error.what() << endl;
  }

}
void SysUserSpi::OnRtnDataCenterChgTopic(CShfeFtdcRtnDataCenterChgField *pRtnDataCenterChg)
{
  cout << "\n**************** SysUserSpi::OnRtnDataCenterChgTopic: START ****************"<< endl;
  cout << "on pRtnDataCenterChg->DataCenterID:"<<pRtnDataCenterChg->DataCenterID<< endl;
  CShfeFtdcRtnDataCenterChgField* pNewRtnDataCenterChg =new CShfeFtdcRtnDataCenterChgField;
  memcpy(pNewRtnDataCenterChg,pRtnDataCenterChg,sizeof(CShfeFtdcRtnDataCenterChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnDataCenterChg;
  asyncOnRtnDataCenterChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnDataCenterChgTopic);
  cout << "**************** SysUserSpi::OnRtnDataCenterChgTopic: END ****************\n"<< endl;
}
void SysUserSpi::OnRspQryHistoryTradePeakTopic(CShfeFtdcRspQryHistoryTradePeakField *pRspQryHistoryTradePeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryHistoryTradePeak->ObjectID:"<<pRspQryHistoryTradePeak->ObjectID<< endl;
  cout << "on pRspQryHistoryTradePeak->MonDate:"<<pRspQryHistoryTradePeak->MonDate<< endl;
  cout << "on pRspQryHistoryTradePeak->MonTime:"<<pRspQryHistoryTradePeak->MonTime<< endl;
  cout << "on pRspQryHistoryTradePeak->AttrType:"<<pRspQryHistoryTradePeak->AttrType<< endl;
  cout << "on pRspQryHistoryTradePeak->AttrValue:"<<pRspQryHistoryTradePeak->AttrValue<< endl;
  cout << "on pRspQryHistoryTradePeak->RltAttrType:"<<pRspQryHistoryTradePeak->RltAttrType<< endl;
  cout << "on pRspQryHistoryTradePeak->RltAttrValue:"<<pRspQryHistoryTradePeak->RltAttrValue<< endl;
  cout << "on pRspQryHistoryTradePeak->MaxMonDate:"<<pRspQryHistoryTradePeak->MaxMonDate<< endl;
  cout << "on pRspQryHistoryTradePeak->MaxMonTime:"<<pRspQryHistoryTradePeak->MaxMonTime<< endl;
  cout << "on pRspQryHistoryTradePeak->MaxAttrValue:"<<pRspQryHistoryTradePeak->MaxAttrValue<< endl;
  cout << "on pRspQryHistoryTradePeak->MaxRltAttrValue:"<<pRspQryHistoryTradePeak->MaxRltAttrValue<< endl;
  cout << "on pRspQryHistoryTradePeak->OldMonDate:"<<pRspQryHistoryTradePeak->OldMonDate<< endl;
  cout << "on pRspQryHistoryTradePeak->OldMonTime:"<<pRspQryHistoryTradePeak->OldMonTime<< endl;
  cout << "on pRspQryHistoryTradePeak->OldAttrValue:"<<pRspQryHistoryTradePeak->OldAttrValue<< endl;
  cout << "on pRspQryHistoryTradePeak->OldRltAttrValue:"<<pRspQryHistoryTradePeak->OldRltAttrValue<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryHistoryTradePeakField* pNewRspQryHistoryTradePeak =new CShfeFtdcRspQryHistoryTradePeakField;
  memcpy(pNewRspQryHistoryTradePeak,pRspQryHistoryTradePeak,sizeof(CShfeFtdcRspQryHistoryTradePeakField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryHistoryTradePeak;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryHistoryTradePeakTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryHistoryTradePeakTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnHistoryTradePeakTopic(CShfeFtdcRtnHistoryTradePeakField *pRtnHistoryTradePeak)
{
  cout << "ok"<< endl;
  cout << "on pRtnHistoryTradePeak->ObjectID:"<<pRtnHistoryTradePeak->ObjectID<< endl;
  cout << "on pRtnHistoryTradePeak->MonDate:"<<pRtnHistoryTradePeak->MonDate<< endl;
  cout << "on pRtnHistoryTradePeak->MonTime:"<<pRtnHistoryTradePeak->MonTime<< endl;
  cout << "on pRtnHistoryTradePeak->AttrType:"<<pRtnHistoryTradePeak->AttrType<< endl;
  cout << "on pRtnHistoryTradePeak->AttrValue:"<<pRtnHistoryTradePeak->AttrValue<< endl;
  cout << "on pRtnHistoryTradePeak->RltAttrType:"<<pRtnHistoryTradePeak->RltAttrType<< endl;
  cout << "on pRtnHistoryTradePeak->RltAttrValue:"<<pRtnHistoryTradePeak->RltAttrValue<< endl;
  cout << "on pRtnHistoryTradePeak->MaxMonDate:"<<pRtnHistoryTradePeak->MaxMonDate<< endl;
  cout << "on pRtnHistoryTradePeak->MaxMonTime:"<<pRtnHistoryTradePeak->MaxMonTime<< endl;
  cout << "on pRtnHistoryTradePeak->MaxAttrValue:"<<pRtnHistoryTradePeak->MaxAttrValue<< endl;
  cout << "on pRtnHistoryTradePeak->MaxRltAttrValue:"<<pRtnHistoryTradePeak->MaxRltAttrValue<< endl;
  cout << "on pRtnHistoryTradePeak->OldMonDate:"<<pRtnHistoryTradePeak->OldMonDate<< endl;
  cout << "on pRtnHistoryTradePeak->OldMonTime:"<<pRtnHistoryTradePeak->OldMonTime<< endl;
  cout << "on pRtnHistoryTradePeak->OldAttrValue:"<<pRtnHistoryTradePeak->OldAttrValue<< endl;
  cout << "on pRtnHistoryTradePeak->OldRltAttrValue:"<<pRtnHistoryTradePeak->OldRltAttrValue<< endl;
  CShfeFtdcRtnHistoryTradePeakField* pNewRtnHistoryTradePeak =new CShfeFtdcRtnHistoryTradePeakField;
  memcpy(pNewRtnHistoryTradePeak,pRtnHistoryTradePeak,sizeof(CShfeFtdcRtnHistoryTradePeakField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnHistoryTradePeak;
  asyncOnRtnHistoryTradePeakTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnHistoryTradePeakTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQrySyslogEventTopic(CShfeFtdcRspQrySyslogEventField *pRspQrySyslogEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQrySyslogEvent->MonDate:"<<pRspQrySyslogEvent->MonDate<< endl;
  cout << "on pRspQrySyslogEvent->MonTime:"<<pRspQrySyslogEvent->MonTime<< endl;
  cout << "on pRspQrySyslogEvent->OccurDate:"<<pRspQrySyslogEvent->OccurDate<< endl;
  cout << "on pRspQrySyslogEvent->OccurTime:"<<pRspQrySyslogEvent->OccurTime<< endl;
  cout << "on pRspQrySyslogEvent->EvendID:"<<pRspQrySyslogEvent->EvendID<< endl;
  cout << "on pRspQrySyslogEvent->ObjectID:"<<pRspQrySyslogEvent->ObjectID<< endl;
  cout << "on pRspQrySyslogEvent->IPAddress:"<<pRspQrySyslogEvent->IPAddress<< endl;
  cout << "on pRspQrySyslogEvent->EventName:"<<pRspQrySyslogEvent->EventName<< endl;
  cout << "on pRspQrySyslogEvent->EventNum:"<<pRspQrySyslogEvent->EventNum<< endl;
  cout << "on pRspQrySyslogEvent->EventType:"<<pRspQrySyslogEvent->EventType<< endl;
  cout << "on pRspQrySyslogEvent->EventDes:"<<pRspQrySyslogEvent->EventDes<< endl;
  cout << "on pRspQrySyslogEvent->ProcessFlag:"<<pRspQrySyslogEvent->ProcessFlag<< endl;
  cout << "on pRspQrySyslogEvent->WarningLevel:"<<pRspQrySyslogEvent->WarningLevel<< endl;
  cout << "on pRspQrySyslogEvent->EventDealDes:"<<pRspQrySyslogEvent->EventDealDes<< endl;
  cout << "on pRspQrySyslogEvent->FullEventName:"<<pRspQrySyslogEvent->FullEventName<< endl;
  cout << "on pRspQrySyslogEvent->EventCount:"<<pRspQrySyslogEvent->EventCount<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQrySyslogEventField* pNewRspQrySyslogEvent =new CShfeFtdcRspQrySyslogEventField;
  memcpy(pNewRspQrySyslogEvent,pRspQrySyslogEvent,sizeof(CShfeFtdcRspQrySyslogEventField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySyslogEvent;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySyslogEventTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQrySyslogEventTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnSyslogEventTopic(CShfeFtdcRtnSyslogEventField *pRtnSyslogEvent)
{
  cout << "\n********* SysUserSpi::OnRtnSyslogEventTopic: START! ********"<< endl;
  cout << "g_OnRtnSyslogEventTopic_Sys_numb: " << g_OnRtnSyslogEventTopic_Sys_numb++ << endl;
  cout << "on pRtnSyslogEvent->MonDate:"<<pRtnSyslogEvent->MonDate<< endl;
  cout << "on pRtnSyslogEvent->MonTime:"<<pRtnSyslogEvent->MonTime<< endl;
  cout << "on pRtnSyslogEvent->OccurDate:"<<pRtnSyslogEvent->OccurDate<< endl;
  cout << "on pRtnSyslogEvent->OccurTime:"<<pRtnSyslogEvent->OccurTime<< endl;
  cout << "on pRtnSyslogEvent->EvendID:"<<pRtnSyslogEvent->EvendID<< endl;
  cout << "on pRtnSyslogEvent->ObjectID:"<<pRtnSyslogEvent->ObjectID<< endl;
  cout << "on pRtnSyslogEvent->IPAddress:"<<pRtnSyslogEvent->IPAddress<< endl;
  cout << "on pRtnSyslogEvent->EventName:"<<pRtnSyslogEvent->EventName<< endl;
  cout << "on pRtnSyslogEvent->EventNum:"<<pRtnSyslogEvent->EventNum<< endl;
  cout << "on pRtnSyslogEvent->EventType:"<<pRtnSyslogEvent->EventType<< endl;
  cout << "on pRtnSyslogEvent->EventDes:"<<pRtnSyslogEvent->EventDes<< endl;
  cout << "on pRtnSyslogEvent->ProcessFlag:"<<pRtnSyslogEvent->ProcessFlag<< endl;
  cout << "on pRtnSyslogEvent->WarningLevel:"<<pRtnSyslogEvent->WarningLevel<< endl;
  cout << "on pRtnSyslogEvent->EventDealDes:"<<pRtnSyslogEvent->EventDealDes<< endl;
  cout << "on pRtnSyslogEvent->FullEventName:"<<pRtnSyslogEvent->FullEventName<< endl;
  CShfeFtdcRtnSyslogEventField* pNewRtnSyslogEvent =new CShfeFtdcRtnSyslogEventField;
  memcpy(pNewRtnSyslogEvent,pRtnSyslogEvent,sizeof(CShfeFtdcRtnSyslogEventField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSyslogEvent;
  asyncOnRtnSyslogEventTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnSyslogEventTopic);
   cout << "\n********* SysUserSpi::OnRtnSyslogEventTopic: START! ********"<< endl;
}
void SysUserSpi::OnRspQryTradeDayChangeTopic(CShfeFtdcRspQryTradeDayChangeField *pRspQryTradeDayChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryTradeDayChange->ChangeType:"<<pRspQryTradeDayChange->ChangeType<< endl;
  cout << "on pRspQryTradeDayChange->OldDate:"<<pRspQryTradeDayChange->OldDate<< endl;
  cout << "on pRspQryTradeDayChange->NewDate:"<<pRspQryTradeDayChange->NewDate<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryTradeDayChangeField* pNewRspQryTradeDayChange =new CShfeFtdcRspQryTradeDayChangeField;
  memcpy(pNewRspQryTradeDayChange,pRspQryTradeDayChange,sizeof(CShfeFtdcRspQryTradeDayChangeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTradeDayChange;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTradeDayChangeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryTradeDayChangeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryWebAppInfoTopic(CShfeFtdcRspQryWebAppInfoField *pRspQryWebAppInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryWebAppInfo->ObjectID:"<<pRspQryWebAppInfo->ObjectID<< endl;
  cout << "on pRspQryWebAppInfo->MonDate:"<<pRspQryWebAppInfo->MonDate<< endl;
  cout << "on pRspQryWebAppInfo->MonTime:"<<pRspQryWebAppInfo->MonTime<< endl;
  cout << "on pRspQryWebAppInfo->AppName:"<<pRspQryWebAppInfo->AppName<< endl;
  cout << "on pRspQryWebAppInfo->Status:"<<pRspQryWebAppInfo->Status<< endl;
  cout << "on pRspQryWebAppInfo->Desc:"<<pRspQryWebAppInfo->Desc<< endl;
  cout << "on pRspQryWebAppInfo->StartTime:"<<pRspQryWebAppInfo->StartTime<< endl;
  cout << "on pRspQryWebAppInfo->ServletNum:"<<pRspQryWebAppInfo->ServletNum<< endl;
  cout << "on pRspQryWebAppInfo->ProcessTime:"<<pRspQryWebAppInfo->ProcessTime<< endl;
  cout << "on pRspQryWebAppInfo->RequestNum:"<<pRspQryWebAppInfo->RequestNum<< endl;
  cout << "on pRspQryWebAppInfo->ErrorNum:"<<pRspQryWebAppInfo->ErrorNum<< endl;
  cout << "on pRspQryWebAppInfo->SessionSize:"<<pRspQryWebAppInfo->SessionSize<< endl;
  cout << "on pRspQryWebAppInfo->TimeOut:"<<pRspQryWebAppInfo->TimeOut<< endl;
  cout << "on pRspQryWebAppInfo->JDBCUsage:"<<pRspQryWebAppInfo->JDBCUsage<< endl;
  cout << "on pRspQryWebAppInfo->JSPNum:"<<pRspQryWebAppInfo->JSPNum<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryWebAppInfoField* pNewRspQryWebAppInfo =new CShfeFtdcRspQryWebAppInfoField;
  memcpy(pNewRspQryWebAppInfo,pRspQryWebAppInfo,sizeof(CShfeFtdcRspQryWebAppInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryWebAppInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryWebAppInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryWebAppInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnWebAppInfoTopic(CShfeFtdcRtnWebAppInfoField *pRtnWebAppInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnWebAppInfo->ObjectID:"<<pRtnWebAppInfo->ObjectID<< endl;
  cout << "on pRtnWebAppInfo->MonDate:"<<pRtnWebAppInfo->MonDate<< endl;
  cout << "on pRtnWebAppInfo->MonTime:"<<pRtnWebAppInfo->MonTime<< endl;
  cout << "on pRtnWebAppInfo->AppName:"<<pRtnWebAppInfo->AppName<< endl;
  cout << "on pRtnWebAppInfo->Status:"<<pRtnWebAppInfo->Status<< endl;
  cout << "on pRtnWebAppInfo->Desc:"<<pRtnWebAppInfo->Desc<< endl;
  cout << "on pRtnWebAppInfo->StartTime:"<<pRtnWebAppInfo->StartTime<< endl;
  cout << "on pRtnWebAppInfo->ServletNum:"<<pRtnWebAppInfo->ServletNum<< endl;
  cout << "on pRtnWebAppInfo->ProcessTime:"<<pRtnWebAppInfo->ProcessTime<< endl;
  cout << "on pRtnWebAppInfo->RequestNum:"<<pRtnWebAppInfo->RequestNum<< endl;
  cout << "on pRtnWebAppInfo->ErrorNum:"<<pRtnWebAppInfo->ErrorNum<< endl;
  cout << "on pRtnWebAppInfo->SessionSize:"<<pRtnWebAppInfo->SessionSize<< endl;
  cout << "on pRtnWebAppInfo->TimeOut:"<<pRtnWebAppInfo->TimeOut<< endl;
  cout << "on pRtnWebAppInfo->JDBCUsage:"<<pRtnWebAppInfo->JDBCUsage<< endl;
  cout << "on pRtnWebAppInfo->JSPNum:"<<pRtnWebAppInfo->JSPNum<< endl;
  CShfeFtdcRtnWebAppInfoField* pNewRtnWebAppInfo =new CShfeFtdcRtnWebAppInfoField;
  memcpy(pNewRtnWebAppInfo,pRtnWebAppInfo,sizeof(CShfeFtdcRtnWebAppInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnWebAppInfo;
  asyncOnRtnWebAppInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnWebAppInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryServletInfoTopic(CShfeFtdcRspQryServletInfoField *pRspQryServletInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryServletInfo->ObjectID:"<<pRspQryServletInfo->ObjectID<< endl;
  cout << "on pRspQryServletInfo->MonDate:"<<pRspQryServletInfo->MonDate<< endl;
  cout << "on pRspQryServletInfo->MonTime:"<<pRspQryServletInfo->MonTime<< endl;
  cout << "on pRspQryServletInfo->Name:"<<pRspQryServletInfo->Name<< endl;
  cout << "on pRspQryServletInfo->LoadTime:"<<pRspQryServletInfo->LoadTime<< endl;
  cout << "on pRspQryServletInfo->RequestNum:"<<pRspQryServletInfo->RequestNum<< endl;
  cout << "on pRspQryServletInfo->RequestErrNum:"<<pRspQryServletInfo->RequestErrNum<< endl;
  cout << "on pRspQryServletInfo->ProcessTime:"<<pRspQryServletInfo->ProcessTime<< endl;
  cout << "on pRspQryServletInfo->MixTime:"<<pRspQryServletInfo->MixTime<< endl;
  cout << "on pRspQryServletInfo->MaxTime:"<<pRspQryServletInfo->MaxTime<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryServletInfoField* pNewRspQryServletInfo =new CShfeFtdcRspQryServletInfoField;
  memcpy(pNewRspQryServletInfo,pRspQryServletInfo,sizeof(CShfeFtdcRspQryServletInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryServletInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryServletInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryServletInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnServletInfoTopic(CShfeFtdcRtnServletInfoField *pRtnServletInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnServletInfo->ObjectID:"<<pRtnServletInfo->ObjectID<< endl;
  cout << "on pRtnServletInfo->MonDate:"<<pRtnServletInfo->MonDate<< endl;
  cout << "on pRtnServletInfo->MonTime:"<<pRtnServletInfo->MonTime<< endl;
  cout << "on pRtnServletInfo->Name:"<<pRtnServletInfo->Name<< endl;
  cout << "on pRtnServletInfo->LoadTime:"<<pRtnServletInfo->LoadTime<< endl;
  cout << "on pRtnServletInfo->RequestNum:"<<pRtnServletInfo->RequestNum<< endl;
  cout << "on pRtnServletInfo->RequestErrNum:"<<pRtnServletInfo->RequestErrNum<< endl;
  cout << "on pRtnServletInfo->ProcessTime:"<<pRtnServletInfo->ProcessTime<< endl;
  cout << "on pRtnServletInfo->MixTime:"<<pRtnServletInfo->MixTime<< endl;
  cout << "on pRtnServletInfo->MaxTime:"<<pRtnServletInfo->MaxTime<< endl;
  CShfeFtdcRtnServletInfoField* pNewRtnServletInfo =new CShfeFtdcRtnServletInfoField;
  memcpy(pNewRtnServletInfo,pRtnServletInfo,sizeof(CShfeFtdcRtnServletInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnServletInfo;
  asyncOnRtnServletInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnServletInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryFileInfoTopic(CShfeFtdcRspQryFileInfoField *pRspQryFileInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryFileInfo->ObjectID:"<<pRspQryFileInfo->ObjectID<< endl;
  cout << "on pRspQryFileInfo->MonDate:"<<pRspQryFileInfo->MonDate<< endl;
  cout << "on pRspQryFileInfo->MonTime:"<<pRspQryFileInfo->MonTime<< endl;
  cout << "on pRspQryFileInfo->PathName:"<<pRspQryFileInfo->PathName<< endl;
  cout << "on pRspQryFileInfo->FileSize:"<<pRspQryFileInfo->FileSize<< endl;
  cout << "on pRspQryFileInfo->LastModDate:"<<pRspQryFileInfo->LastModDate<< endl;
  cout << "on pRspQryFileInfo->FileType:"<<pRspQryFileInfo->FileType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryFileInfoField* pNewRspQryFileInfo =new CShfeFtdcRspQryFileInfoField;
  memcpy(pNewRspQryFileInfo,pRspQryFileInfo,sizeof(CShfeFtdcRspQryFileInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryFileInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryFileInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryFileInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnFileInfoTopic(CShfeFtdcRtnFileInfoField *pRtnFileInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnFileInfo->ObjectID:"<<pRtnFileInfo->ObjectID<< endl;
  cout << "on pRtnFileInfo->MonDate:"<<pRtnFileInfo->MonDate<< endl;
  cout << "on pRtnFileInfo->MonTime:"<<pRtnFileInfo->MonTime<< endl;
  cout << "on pRtnFileInfo->PathName:"<<pRtnFileInfo->PathName<< endl;
  cout << "on pRtnFileInfo->FileSize:"<<pRtnFileInfo->FileSize<< endl;
  cout << "on pRtnFileInfo->LastModDate:"<<pRtnFileInfo->LastModDate<< endl;
  cout << "on pRtnFileInfo->FileType:"<<pRtnFileInfo->FileType<< endl;
  CShfeFtdcRtnFileInfoField* pNewRtnFileInfo =new CShfeFtdcRtnFileInfoField;
  memcpy(pNewRtnFileInfo,pRtnFileInfo,sizeof(CShfeFtdcRtnFileInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnFileInfo;
  asyncOnRtnFileInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnFileInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQrySessionInfoTopic(CShfeFtdcRspQrySessionInfoField *pRspQrySessionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQrySessionInfo->ObjectID:"<<pRspQrySessionInfo->ObjectID<< endl;
  cout << "on pRspQrySessionInfo->MonDate:"<<pRspQrySessionInfo->MonDate<< endl;
  cout << "on pRspQrySessionInfo->MonTime:"<<pRspQrySessionInfo->MonTime<< endl;
  cout << "on pRspQrySessionInfo->SessionID:"<<pRspQrySessionInfo->SessionID<< endl;
  cout << "on pRspQrySessionInfo->SessionName:"<<pRspQrySessionInfo->SessionName<< endl;
  cout << "on pRspQrySessionInfo->RemoteIP:"<<pRspQrySessionInfo->RemoteIP<< endl;
  cout << "on pRspQrySessionInfo->BeginTime:"<<pRspQrySessionInfo->BeginTime<< endl;
  cout << "on pRspQrySessionInfo->LatestTime:"<<pRspQrySessionInfo->LatestTime<< endl;
  cout << "on pRspQrySessionInfo->MaxIdleTime:"<<pRspQrySessionInfo->MaxIdleTime<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQrySessionInfoField* pNewRspQrySessionInfo =new CShfeFtdcRspQrySessionInfoField;
  memcpy(pNewRspQrySessionInfo,pRspQrySessionInfo,sizeof(CShfeFtdcRspQrySessionInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySessionInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySessionInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQrySessionInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnSessionInfoTopic(CShfeFtdcRtnSessionInfoField *pRtnSessionInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnSessionInfo->ObjectID:"<<pRtnSessionInfo->ObjectID<< endl;
  cout << "on pRtnSessionInfo->MonDate:"<<pRtnSessionInfo->MonDate<< endl;
  cout << "on pRtnSessionInfo->MonTime:"<<pRtnSessionInfo->MonTime<< endl;
  cout << "on pRtnSessionInfo->SessionID:"<<pRtnSessionInfo->SessionID<< endl;
  cout << "on pRtnSessionInfo->SessionName:"<<pRtnSessionInfo->SessionName<< endl;
  cout << "on pRtnSessionInfo->RemoteIP:"<<pRtnSessionInfo->RemoteIP<< endl;
  cout << "on pRtnSessionInfo->BeginTime:"<<pRtnSessionInfo->BeginTime<< endl;
  cout << "on pRtnSessionInfo->LatestTime:"<<pRtnSessionInfo->LatestTime<< endl;
  cout << "on pRtnSessionInfo->MaxIdleTime:"<<pRtnSessionInfo->MaxIdleTime<< endl;
  CShfeFtdcRtnSessionInfoField* pNewRtnSessionInfo =new CShfeFtdcRtnSessionInfoField;
  memcpy(pNewRtnSessionInfo,pRtnSessionInfo,sizeof(CShfeFtdcRtnSessionInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSessionInfo;
  asyncOnRtnSessionInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnSessionInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryJDBCInfoTopic(CShfeFtdcRspQryJDBCInfoField *pRspQryJDBCInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryJDBCInfo->ObjectID:"<<pRspQryJDBCInfo->ObjectID<< endl;
  cout << "on pRspQryJDBCInfo->MonDate:"<<pRspQryJDBCInfo->MonDate<< endl;
  cout << "on pRspQryJDBCInfo->MonTime:"<<pRspQryJDBCInfo->MonTime<< endl;
  cout << "on pRspQryJDBCInfo->AppName:"<<pRspQryJDBCInfo->AppName<< endl;
  cout << "on pRspQryJDBCInfo->Name:"<<pRspQryJDBCInfo->Name<< endl;
  cout << "on pRspQryJDBCInfo->Usage:"<<pRspQryJDBCInfo->Usage<< endl;
  cout << "on pRspQryJDBCInfo->ConnNumMax:"<<pRspQryJDBCInfo->ConnNumMax<< endl;
  cout << "on pRspQryJDBCInfo->ConnNumFree:"<<pRspQryJDBCInfo->ConnNumFree<< endl;
  cout << "on pRspQryJDBCInfo->ConnNumUnRU:"<<pRspQryJDBCInfo->ConnNumUnRU<< endl;
  cout << "on pRspQryJDBCInfo->ConnNumRU:"<<pRspQryJDBCInfo->ConnNumRU<< endl;
  cout << "on pRspQryJDBCInfo->UserName:"<<pRspQryJDBCInfo->UserName<< endl;
  cout << "on pRspQryJDBCInfo->Type:"<<pRspQryJDBCInfo->Type<< endl;
  cout << "on pRspQryJDBCInfo->URL:"<<pRspQryJDBCInfo->URL<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryJDBCInfoField* pNewRspQryJDBCInfo =new CShfeFtdcRspQryJDBCInfoField;
  memcpy(pNewRspQryJDBCInfo,pRspQryJDBCInfo,sizeof(CShfeFtdcRspQryJDBCInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryJDBCInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryJDBCInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryJDBCInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnJDBCInfoTopic(CShfeFtdcRtnJDBCInfoField *pRtnJDBCInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnJDBCInfo->ObjectID:"<<pRtnJDBCInfo->ObjectID<< endl;
  cout << "on pRtnJDBCInfo->MonDate:"<<pRtnJDBCInfo->MonDate<< endl;
  cout << "on pRtnJDBCInfo->MonTime:"<<pRtnJDBCInfo->MonTime<< endl;
  cout << "on pRtnJDBCInfo->AppName:"<<pRtnJDBCInfo->AppName<< endl;
  cout << "on pRtnJDBCInfo->Name:"<<pRtnJDBCInfo->Name<< endl;
  cout << "on pRtnJDBCInfo->Usage:"<<pRtnJDBCInfo->Usage<< endl;
  cout << "on pRtnJDBCInfo->ConnNumMax:"<<pRtnJDBCInfo->ConnNumMax<< endl;
  cout << "on pRtnJDBCInfo->ConnNumFree:"<<pRtnJDBCInfo->ConnNumFree<< endl;
  cout << "on pRtnJDBCInfo->ConnNumUnRU:"<<pRtnJDBCInfo->ConnNumUnRU<< endl;
  cout << "on pRtnJDBCInfo->ConnNumRU:"<<pRtnJDBCInfo->ConnNumRU<< endl;
  cout << "on pRtnJDBCInfo->UserName:"<<pRtnJDBCInfo->UserName<< endl;
  cout << "on pRtnJDBCInfo->Type:"<<pRtnJDBCInfo->Type<< endl;
  cout << "on pRtnJDBCInfo->URL:"<<pRtnJDBCInfo->URL<< endl;
  CShfeFtdcRtnJDBCInfoField* pNewRtnJDBCInfo =new CShfeFtdcRtnJDBCInfoField;
  memcpy(pNewRtnJDBCInfo,pRtnJDBCInfo,sizeof(CShfeFtdcRtnJDBCInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnJDBCInfo;
  asyncOnRtnJDBCInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnJDBCInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryThreadInfoTopic(CShfeFtdcRspQryThreadInfoField *pRspQryThreadInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryThreadInfo->ObjectID:"<<pRspQryThreadInfo->ObjectID<< endl;
  cout << "on pRspQryThreadInfo->MonDate:"<<pRspQryThreadInfo->MonDate<< endl;
  cout << "on pRspQryThreadInfo->MonTime:"<<pRspQryThreadInfo->MonTime<< endl;
  cout << "on pRspQryThreadInfo->Name:"<<pRspQryThreadInfo->Name<< endl;
  cout << "on pRspQryThreadInfo->ThreadNum:"<<pRspQryThreadInfo->ThreadNum<< endl;
  cout << "on pRspQryThreadInfo->ThreadStatus:"<<pRspQryThreadInfo->ThreadStatus<< endl;
  cout << "on pRspQryThreadInfo->InNative:"<<pRspQryThreadInfo->InNative<< endl;
  cout << "on pRspQryThreadInfo->Suspended:"<<pRspQryThreadInfo->Suspended<< endl;
  cout << "on pRspQryThreadInfo->BlockCount:"<<pRspQryThreadInfo->BlockCount<< endl;
  cout << "on pRspQryThreadInfo->WaitCount:"<<pRspQryThreadInfo->WaitCount<< endl;
  cout << "on pRspQryThreadInfo->CpuTime:"<<pRspQryThreadInfo->CpuTime<< endl;
  cout << "on pRspQryThreadInfo->UserTime:"<<pRspQryThreadInfo->UserTime<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryThreadInfoField* pNewRspQryThreadInfo =new CShfeFtdcRspQryThreadInfoField;
  memcpy(pNewRspQryThreadInfo,pRspQryThreadInfo,sizeof(CShfeFtdcRspQryThreadInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryThreadInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryThreadInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryThreadInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnThreadInfoTopic(CShfeFtdcRtnThreadInfoField *pRtnThreadInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnThreadInfo->ObjectID:"<<pRtnThreadInfo->ObjectID<< endl;
  cout << "on pRtnThreadInfo->MonDate:"<<pRtnThreadInfo->MonDate<< endl;
  cout << "on pRtnThreadInfo->MonTime:"<<pRtnThreadInfo->MonTime<< endl;
  cout << "on pRtnThreadInfo->Name:"<<pRtnThreadInfo->Name<< endl;
  cout << "on pRtnThreadInfo->ThreadNum:"<<pRtnThreadInfo->ThreadNum<< endl;
  cout << "on pRtnThreadInfo->ThreadStatus:"<<pRtnThreadInfo->ThreadStatus<< endl;
  cout << "on pRtnThreadInfo->InNative:"<<pRtnThreadInfo->InNative<< endl;
  cout << "on pRtnThreadInfo->Suspended:"<<pRtnThreadInfo->Suspended<< endl;
  cout << "on pRtnThreadInfo->BlockCount:"<<pRtnThreadInfo->BlockCount<< endl;
  cout << "on pRtnThreadInfo->WaitCount:"<<pRtnThreadInfo->WaitCount<< endl;
  cout << "on pRtnThreadInfo->CpuTime:"<<pRtnThreadInfo->CpuTime<< endl;
  cout << "on pRtnThreadInfo->UserTime:"<<pRtnThreadInfo->UserTime<< endl;
  CShfeFtdcRtnThreadInfoField* pNewRtnThreadInfo =new CShfeFtdcRtnThreadInfoField;
  memcpy(pNewRtnThreadInfo,pRtnThreadInfo,sizeof(CShfeFtdcRtnThreadInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnThreadInfo;
  asyncOnRtnThreadInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnThreadInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryVMInfoTopic(CShfeFtdcRspQryVMInfoField *pRspQryVMInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryVMInfo->ObjectID:"<<pRspQryVMInfo->ObjectID<< endl;
  cout << "on pRspQryVMInfo->MonDate:"<<pRspQryVMInfo->MonDate<< endl;
  cout << "on pRspQryVMInfo->MonTime:"<<pRspQryVMInfo->MonTime<< endl;
  cout << "on pRspQryVMInfo->Name:"<<pRspQryVMInfo->Name<< endl;
  cout << "on pRspQryVMInfo->VmName:"<<pRspQryVMInfo->VmName<< endl;
  cout << "on pRspQryVMInfo->VmVendor:"<<pRspQryVMInfo->VmVendor<< endl;
  cout << "on pRspQryVMInfo->VmVersion:"<<pRspQryVMInfo->VmVersion<< endl;
  cout << "on pRspQryVMInfo->StartTime:"<<pRspQryVMInfo->StartTime<< endl;
  cout << "on pRspQryVMInfo->BootClassPath:"<<pRspQryVMInfo->BootClassPath<< endl;
  cout << "on pRspQryVMInfo->ClassPath:"<<pRspQryVMInfo->ClassPath<< endl;
  cout << "on pRspQryVMInfo->LibraryPath:"<<pRspQryVMInfo->LibraryPath<< endl;
  cout << "on pRspQryVMInfo->Arguments:"<<pRspQryVMInfo->Arguments<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryVMInfoField* pNewRspQryVMInfo =new CShfeFtdcRspQryVMInfoField;
  memcpy(pNewRspQryVMInfo,pRspQryVMInfo,sizeof(CShfeFtdcRspQryVMInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryVMInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryVMInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryVMInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnVMInfoTopic(CShfeFtdcRtnVMInfoField *pRtnVMInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnVMInfo->ObjectID:"<<pRtnVMInfo->ObjectID<< endl;
  cout << "on pRtnVMInfo->MonDate:"<<pRtnVMInfo->MonDate<< endl;
  cout << "on pRtnVMInfo->MonTime:"<<pRtnVMInfo->MonTime<< endl;
  cout << "on pRtnVMInfo->Name:"<<pRtnVMInfo->Name<< endl;
  cout << "on pRtnVMInfo->VmName:"<<pRtnVMInfo->VmName<< endl;
  cout << "on pRtnVMInfo->VmVendor:"<<pRtnVMInfo->VmVendor<< endl;
  cout << "on pRtnVMInfo->VmVersion:"<<pRtnVMInfo->VmVersion<< endl;
  cout << "on pRtnVMInfo->StartTime:"<<pRtnVMInfo->StartTime<< endl;
  cout << "on pRtnVMInfo->BootClassPath:"<<pRtnVMInfo->BootClassPath<< endl;
  cout << "on pRtnVMInfo->ClassPath:"<<pRtnVMInfo->ClassPath<< endl;
  cout << "on pRtnVMInfo->LibraryPath:"<<pRtnVMInfo->LibraryPath<< endl;
  cout << "on pRtnVMInfo->Arguments:"<<pRtnVMInfo->Arguments<< endl;
  CShfeFtdcRtnVMInfoField* pNewRtnVMInfo =new CShfeFtdcRtnVMInfoField;
  memcpy(pNewRtnVMInfo,pRtnVMInfo,sizeof(CShfeFtdcRtnVMInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnVMInfo;
  asyncOnRtnVMInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnVMInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryPropertyInfoTopic(CShfeFtdcRspQryPropertyInfoField *pRspQryPropertyInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryPropertyInfo->ObjectID:"<<pRspQryPropertyInfo->ObjectID<< endl;
  cout << "on pRspQryPropertyInfo->MonDate:"<<pRspQryPropertyInfo->MonDate<< endl;
  cout << "on pRspQryPropertyInfo->MonTime:"<<pRspQryPropertyInfo->MonTime<< endl;
  cout << "on pRspQryPropertyInfo->Property:"<<pRspQryPropertyInfo->Property<< endl;
  cout << "on pRspQryPropertyInfo->ClipFlag:"<<pRspQryPropertyInfo->ClipFlag<< endl;
  cout << "on pRspQryPropertyInfo->Value:"<<pRspQryPropertyInfo->Value<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryPropertyInfoField* pNewRspQryPropertyInfo =new CShfeFtdcRspQryPropertyInfoField;
  memcpy(pNewRspQryPropertyInfo,pRspQryPropertyInfo,sizeof(CShfeFtdcRspQryPropertyInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryPropertyInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryPropertyInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryPropertyInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnPropertyInfoTopic(CShfeFtdcRtnPropertyInfoField *pRtnPropertyInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnPropertyInfo->ObjectID:"<<pRtnPropertyInfo->ObjectID<< endl;
  cout << "on pRtnPropertyInfo->MonDate:"<<pRtnPropertyInfo->MonDate<< endl;
  cout << "on pRtnPropertyInfo->MonTime:"<<pRtnPropertyInfo->MonTime<< endl;
  cout << "on pRtnPropertyInfo->Property:"<<pRtnPropertyInfo->Property<< endl;
  cout << "on pRtnPropertyInfo->ClipFlag:"<<pRtnPropertyInfo->ClipFlag<< endl;
  cout << "on pRtnPropertyInfo->Value:"<<pRtnPropertyInfo->Value<< endl;
  CShfeFtdcRtnPropertyInfoField* pNewRtnPropertyInfo =new CShfeFtdcRtnPropertyInfoField;
  memcpy(pNewRtnPropertyInfo,pRtnPropertyInfo,sizeof(CShfeFtdcRtnPropertyInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnPropertyInfo;
  asyncOnRtnPropertyInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnPropertyInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryMemPoolInfoTopic(CShfeFtdcRspQryMemPoolInfoField *pRspQryMemPoolInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryMemPoolInfo->ObjectID:"<<pRspQryMemPoolInfo->ObjectID<< endl;
  cout << "on pRspQryMemPoolInfo->MonDate:"<<pRspQryMemPoolInfo->MonDate<< endl;
  cout << "on pRspQryMemPoolInfo->MonTime:"<<pRspQryMemPoolInfo->MonTime<< endl;
  cout << "on pRspQryMemPoolInfo->PoolName:"<<pRspQryMemPoolInfo->PoolName<< endl;
  cout << "on pRspQryMemPoolInfo->Usage:"<<pRspQryMemPoolInfo->Usage<< endl;
  cout << "on pRspQryMemPoolInfo->committedbytes:"<<pRspQryMemPoolInfo->committedbytes<< endl;
  cout << "on pRspQryMemPoolInfo->initbytes:"<<pRspQryMemPoolInfo->initbytes<< endl;
  cout << "on pRspQryMemPoolInfo->maxbytes:"<<pRspQryMemPoolInfo->maxbytes<< endl;
  cout << "on pRspQryMemPoolInfo->usedbytes:"<<pRspQryMemPoolInfo->usedbytes<< endl;
  cout << "on pRspQryMemPoolInfo->Type:"<<pRspQryMemPoolInfo->Type<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryMemPoolInfoField* pNewRspQryMemPoolInfo =new CShfeFtdcRspQryMemPoolInfoField;
  memcpy(pNewRspQryMemPoolInfo,pRspQryMemPoolInfo,sizeof(CShfeFtdcRspQryMemPoolInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryMemPoolInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryMemPoolInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryMemPoolInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnMemPoolInfoTopic(CShfeFtdcRtnMemPoolInfoField *pRtnMemPoolInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnMemPoolInfo->ObjectID:"<<pRtnMemPoolInfo->ObjectID<< endl;
  cout << "on pRtnMemPoolInfo->MonDate:"<<pRtnMemPoolInfo->MonDate<< endl;
  cout << "on pRtnMemPoolInfo->MonTime:"<<pRtnMemPoolInfo->MonTime<< endl;
  cout << "on pRtnMemPoolInfo->PoolName:"<<pRtnMemPoolInfo->PoolName<< endl;
  cout << "on pRtnMemPoolInfo->Usage:"<<pRtnMemPoolInfo->Usage<< endl;
  cout << "on pRtnMemPoolInfo->committedbytes:"<<pRtnMemPoolInfo->committedbytes<< endl;
  cout << "on pRtnMemPoolInfo->initbytes:"<<pRtnMemPoolInfo->initbytes<< endl;
  cout << "on pRtnMemPoolInfo->maxbytes:"<<pRtnMemPoolInfo->maxbytes<< endl;
  cout << "on pRtnMemPoolInfo->usedbytes:"<<pRtnMemPoolInfo->usedbytes<< endl;
  cout << "on pRtnMemPoolInfo->Type:"<<pRtnMemPoolInfo->Type<< endl;
  CShfeFtdcRtnMemPoolInfoField* pNewRtnMemPoolInfo =new CShfeFtdcRtnMemPoolInfoField;
  memcpy(pNewRtnMemPoolInfo,pRtnMemPoolInfo,sizeof(CShfeFtdcRtnMemPoolInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnMemPoolInfo;
  asyncOnRtnMemPoolInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnMemPoolInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryFileContentInfoTopic(CShfeFtdcRspQryFileContentInfoField *pRspQryFileContentInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryFileContentInfo->ObjectID:"<<pRspQryFileContentInfo->ObjectID<< endl;
  cout << "on pRspQryFileContentInfo->MonDate:"<<pRspQryFileContentInfo->MonDate<< endl;
  cout << "on pRspQryFileContentInfo->MonTime:"<<pRspQryFileContentInfo->MonTime<< endl;
  cout << "on pRspQryFileContentInfo->FileName:"<<pRspQryFileContentInfo->FileName<< endl;
  cout << "on pRspQryFileContentInfo->FileContent:"<<pRspQryFileContentInfo->FileContent<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryFileContentInfoField* pNewRspQryFileContentInfo =new CShfeFtdcRspQryFileContentInfoField;
  memcpy(pNewRspQryFileContentInfo,pRspQryFileContentInfo,sizeof(CShfeFtdcRspQryFileContentInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryFileContentInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryFileContentInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryFileContentInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnFileContentInfoTopic(CShfeFtdcRtnFileContentInfoField *pRtnFileContentInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnFileContentInfo->ObjectID:"<<pRtnFileContentInfo->ObjectID<< endl;
  cout << "on pRtnFileContentInfo->MonDate:"<<pRtnFileContentInfo->MonDate<< endl;
  cout << "on pRtnFileContentInfo->MonTime:"<<pRtnFileContentInfo->MonTime<< endl;
  cout << "on pRtnFileContentInfo->FileName:"<<pRtnFileContentInfo->FileName<< endl;
  cout << "on pRtnFileContentInfo->FileContent:"<<pRtnFileContentInfo->FileContent<< endl;
  CShfeFtdcRtnFileContentInfoField* pNewRtnFileContentInfo =new CShfeFtdcRtnFileContentInfoField;
  memcpy(pNewRtnFileContentInfo,pRtnFileContentInfo,sizeof(CShfeFtdcRtnFileContentInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnFileContentInfo;
  asyncOnRtnFileContentInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnFileContentInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryConnectionInfoTopic(CShfeFtdcRspQryConnectionInfoField *pRspQryConnectionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryConnectionInfo->ObjectID:"<<pRspQryConnectionInfo->ObjectID<< endl;
  cout << "on pRspQryConnectionInfo->MonDate:"<<pRspQryConnectionInfo->MonDate<< endl;
  cout << "on pRspQryConnectionInfo->MonTime:"<<pRspQryConnectionInfo->MonTime<< endl;
  cout << "on pRspQryConnectionInfo->ServiceName:"<<pRspQryConnectionInfo->ServiceName<< endl;
  cout << "on pRspQryConnectionInfo->Stage:"<<pRspQryConnectionInfo->Stage<< endl;
  cout << "on pRspQryConnectionInfo->RequestCount:"<<pRspQryConnectionInfo->RequestCount<< endl;
  cout << "on pRspQryConnectionInfo->ErrorCount:"<<pRspQryConnectionInfo->ErrorCount<< endl;
  cout << "on pRspQryConnectionInfo->ProcTime:"<<pRspQryConnectionInfo->ProcTime<< endl;
  cout << "on pRspQryConnectionInfo->BytesReceived:"<<pRspQryConnectionInfo->BytesReceived<< endl;
  cout << "on pRspQryConnectionInfo->BytesSent:"<<pRspQryConnectionInfo->BytesSent<< endl;
  cout << "on pRspQryConnectionInfo->RemoteIP:"<<pRspQryConnectionInfo->RemoteIP<< endl;
  cout << "on pRspQryConnectionInfo->MaxAccessURI:"<<pRspQryConnectionInfo->MaxAccessURI<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryConnectionInfoField* pNewRspQryConnectionInfo =new CShfeFtdcRspQryConnectionInfoField;
  memcpy(pNewRspQryConnectionInfo,pRspQryConnectionInfo,sizeof(CShfeFtdcRspQryConnectionInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryConnectionInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryConnectionInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryConnectionInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnConnectionInfoTopic(CShfeFtdcRtnConnectionInfoField *pRtnConnectionInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnConnectionInfo->ObjectID:"<<pRtnConnectionInfo->ObjectID<< endl;
  cout << "on pRtnConnectionInfo->MonDate:"<<pRtnConnectionInfo->MonDate<< endl;
  cout << "on pRtnConnectionInfo->MonTime:"<<pRtnConnectionInfo->MonTime<< endl;
  cout << "on pRtnConnectionInfo->ServiceName:"<<pRtnConnectionInfo->ServiceName<< endl;
  cout << "on pRtnConnectionInfo->Stage:"<<pRtnConnectionInfo->Stage<< endl;
  cout << "on pRtnConnectionInfo->RequestCount:"<<pRtnConnectionInfo->RequestCount<< endl;
  cout << "on pRtnConnectionInfo->ErrorCount:"<<pRtnConnectionInfo->ErrorCount<< endl;
  cout << "on pRtnConnectionInfo->ProcTime:"<<pRtnConnectionInfo->ProcTime<< endl;
  cout << "on pRtnConnectionInfo->BytesReceived:"<<pRtnConnectionInfo->BytesReceived<< endl;
  cout << "on pRtnConnectionInfo->BytesSent:"<<pRtnConnectionInfo->BytesSent<< endl;
  cout << "on pRtnConnectionInfo->RemoteIP:"<<pRtnConnectionInfo->RemoteIP<< endl;
  cout << "on pRtnConnectionInfo->MaxAccessURI:"<<pRtnConnectionInfo->MaxAccessURI<< endl;
  CShfeFtdcRtnConnectionInfoField* pNewRtnConnectionInfo =new CShfeFtdcRtnConnectionInfoField;
  memcpy(pNewRtnConnectionInfo,pRtnConnectionInfo,sizeof(CShfeFtdcRtnConnectionInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnConnectionInfo;
  asyncOnRtnConnectionInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnConnectionInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryConnectorInfoTopic(CShfeFtdcRspQryConnectorInfoField *pRspQryConnectorInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryConnectorInfo->ObjectID:"<<pRspQryConnectorInfo->ObjectID<< endl;
  cout << "on pRspQryConnectorInfo->MonDate:"<<pRspQryConnectorInfo->MonDate<< endl;
  cout << "on pRspQryConnectorInfo->MonTime:"<<pRspQryConnectorInfo->MonTime<< endl;
  cout << "on pRspQryConnectorInfo->Name:"<<pRspQryConnectorInfo->Name<< endl;
  cout << "on pRspQryConnectorInfo->ThreadsCount:"<<pRspQryConnectorInfo->ThreadsCount<< endl;
  cout << "on pRspQryConnectorInfo->BusyThreadsCount:"<<pRspQryConnectorInfo->BusyThreadsCount<< endl;
  cout << "on pRspQryConnectorInfo->MaxThreads:"<<pRspQryConnectorInfo->MaxThreads<< endl;
  cout << "on pRspQryConnectorInfo->MaxSpareThreads:"<<pRspQryConnectorInfo->MaxSpareThreads<< endl;
  cout << "on pRspQryConnectorInfo->MinSpareThreads:"<<pRspQryConnectorInfo->MinSpareThreads<< endl;
  cout << "on pRspQryConnectorInfo->MaxTime:"<<pRspQryConnectorInfo->MaxTime<< endl;
  cout << "on pRspQryConnectorInfo->MaxProcTime:"<<pRspQryConnectorInfo->MaxProcTime<< endl;
  cout << "on pRspQryConnectorInfo->RequestCount:"<<pRspQryConnectorInfo->RequestCount<< endl;
  cout << "on pRspQryConnectorInfo->ErrorCount:"<<pRspQryConnectorInfo->ErrorCount<< endl;
  cout << "on pRspQryConnectorInfo->BytesReceived:"<<pRspQryConnectorInfo->BytesReceived<< endl;
  cout << "on pRspQryConnectorInfo->BytesSent:"<<pRspQryConnectorInfo->BytesSent<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryConnectorInfoField* pNewRspQryConnectorInfo =new CShfeFtdcRspQryConnectorInfoField;
  memcpy(pNewRspQryConnectorInfo,pRspQryConnectorInfo,sizeof(CShfeFtdcRspQryConnectorInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryConnectorInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryConnectorInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryConnectorInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnConnectorInfoTopic(CShfeFtdcRtnConnectorInfoField *pRtnConnectorInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnConnectorInfo->ObjectID:"<<pRtnConnectorInfo->ObjectID<< endl;
  cout << "on pRtnConnectorInfo->MonDate:"<<pRtnConnectorInfo->MonDate<< endl;
  cout << "on pRtnConnectorInfo->MonTime:"<<pRtnConnectorInfo->MonTime<< endl;
  cout << "on pRtnConnectorInfo->Name:"<<pRtnConnectorInfo->Name<< endl;
  cout << "on pRtnConnectorInfo->ThreadsCount:"<<pRtnConnectorInfo->ThreadsCount<< endl;
  cout << "on pRtnConnectorInfo->BusyThreadsCount:"<<pRtnConnectorInfo->BusyThreadsCount<< endl;
  cout << "on pRtnConnectorInfo->MaxThreads:"<<pRtnConnectorInfo->MaxThreads<< endl;
  cout << "on pRtnConnectorInfo->MaxSpareThreads:"<<pRtnConnectorInfo->MaxSpareThreads<< endl;
  cout << "on pRtnConnectorInfo->MinSpareThreads:"<<pRtnConnectorInfo->MinSpareThreads<< endl;
  cout << "on pRtnConnectorInfo->MaxTime:"<<pRtnConnectorInfo->MaxTime<< endl;
  cout << "on pRtnConnectorInfo->MaxProcTime:"<<pRtnConnectorInfo->MaxProcTime<< endl;
  cout << "on pRtnConnectorInfo->RequestCount:"<<pRtnConnectorInfo->RequestCount<< endl;
  cout << "on pRtnConnectorInfo->ErrorCount:"<<pRtnConnectorInfo->ErrorCount<< endl;
  cout << "on pRtnConnectorInfo->BytesReceived:"<<pRtnConnectorInfo->BytesReceived<< endl;
  cout << "on pRtnConnectorInfo->BytesSent:"<<pRtnConnectorInfo->BytesSent<< endl;
  CShfeFtdcRtnConnectorInfoField* pNewRtnConnectorInfo =new CShfeFtdcRtnConnectorInfoField;
  memcpy(pNewRtnConnectorInfo,pRtnConnectorInfo,sizeof(CShfeFtdcRtnConnectorInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnConnectorInfo;
  asyncOnRtnConnectorInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnConnectorInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryDBQueryTopic(CShfeFtdcRspQryDBQueryField *pRspQryDBQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryDBQuery->ObjectID:"<<pRspQryDBQuery->ObjectID<< endl;
  cout << "on pRspQryDBQuery->AttrType:"<<pRspQryDBQuery->AttrType<< endl;
  cout << "on pRspQryDBQuery->MonDate:"<<pRspQryDBQuery->MonDate<< endl;
  cout << "on pRspQryDBQuery->MonTime:"<<pRspQryDBQuery->MonTime<< endl;
  cout << "on pRspQryDBQuery->DBQueryResult:"<<pRspQryDBQuery->DBQueryResult<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryDBQueryField* pNewRspQryDBQuery =new CShfeFtdcRspQryDBQueryField;
  memcpy(pNewRspQryDBQuery,pRspQryDBQuery,sizeof(CShfeFtdcRspQryDBQueryField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryDBQuery;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryDBQueryTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryDBQueryTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnDBQueryTopic(CShfeFtdcRtnDBQueryField *pRtnDBQuery)
{
  cout << "ok"<< endl;
  cout << "on pRtnDBQuery->ObjectID:"<<pRtnDBQuery->ObjectID<< endl;
  cout << "on pRtnDBQuery->AttrType:"<<pRtnDBQuery->AttrType<< endl;
  cout << "on pRtnDBQuery->MonDate:"<<pRtnDBQuery->MonDate<< endl;
  cout << "on pRtnDBQuery->MonTime:"<<pRtnDBQuery->MonTime<< endl;
  cout << "on pRtnDBQuery->DBQueryResult:"<<pRtnDBQuery->DBQueryResult<< endl;
  CShfeFtdcRtnDBQueryField* pNewRtnDBQuery =new CShfeFtdcRtnDBQueryField;
  memcpy(pNewRtnDBQuery,pRtnDBQuery,sizeof(CShfeFtdcRtnDBQueryField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnDBQuery;
  asyncOnRtnDBQueryTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnDBQueryTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryGeneralFieldTopic(CShfeFtdcSysGeneralFieldField *pSysGeneralField, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pSysGeneralField->MonDate:"<<pSysGeneralField->MonDate<< endl;
  cout << "on pSysGeneralField->MonTime:"<<pSysGeneralField->MonTime<< endl;
  cout << "on pSysGeneralField->ObjectID:"<<pSysGeneralField->ObjectID<< endl;
  cout << "on pSysGeneralField->SubObjectID:"<<pSysGeneralField->SubObjectID<< endl;
  cout << "on pSysGeneralField->AttrType:"<<pSysGeneralField->AttrType<< endl;
  cout << "on pSysGeneralField->Content:"<<pSysGeneralField->Content<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcSysGeneralFieldField* pNewSysGeneralField =new CShfeFtdcSysGeneralFieldField;
  memcpy(pNewSysGeneralField,pSysGeneralField,sizeof(CShfeFtdcSysGeneralFieldField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewSysGeneralField;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryGeneralFieldTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryGeneralFieldTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnGeneralFieldTopic(CShfeFtdcSysGeneralFieldField *pSysGeneralField)
{
  cout << "ok"<< endl;
  cout << "on pSysGeneralField->MonDate:"<<pSysGeneralField->MonDate<< endl;
  cout << "on pSysGeneralField->MonTime:"<<pSysGeneralField->MonTime<< endl;
  cout << "on pSysGeneralField->ObjectID:"<<pSysGeneralField->ObjectID<< endl;
  cout << "on pSysGeneralField->SubObjectID:"<<pSysGeneralField->SubObjectID<< endl;
  cout << "on pSysGeneralField->AttrType:"<<pSysGeneralField->AttrType<< endl;
  cout << "on pSysGeneralField->Content:"<<pSysGeneralField->Content<< endl;
  CShfeFtdcSysGeneralFieldField* pNewSysGeneralField =new CShfeFtdcSysGeneralFieldField;
  memcpy(pNewSysGeneralField,pSysGeneralField,sizeof(CShfeFtdcSysGeneralFieldField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewSysGeneralField;
  asyncOnRtnGeneralFieldTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnGeneralFieldTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryGetFileTopic(CShfeFtdcRspQryGetFileField *pRspQryGetFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryGetFile->FileName:"<<pRspQryGetFile->FileName<< endl;
  cout << "on pRspQryGetFile->Version:"<<pRspQryGetFile->Version<< endl;
  cout << "on pRspQryGetFile->Offset:"<<pRspQryGetFile->Offset<< endl;
  cout << "on pRspQryGetFile->Length:"<<pRspQryGetFile->Length<< endl;
  cout << "on pRspQryGetFile->Comment:"<<pRspQryGetFile->Comment<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryGetFileField* pNewRspQryGetFile =new CShfeFtdcRspQryGetFileField;
  memcpy(pNewRspQryGetFile,pRspQryGetFile,sizeof(CShfeFtdcRspQryGetFileField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryGetFile;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryGetFileTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryGetFileTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryWarningQueryTopic(CShfeFtdcRspQryWarningQueryField *pRspQryWarningQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryWarningQuery->MonDate:"<<pRspQryWarningQuery->MonDate<< endl;
  cout << "on pRspQryWarningQuery->MonTime:"<<pRspQryWarningQuery->MonTime<< endl;
  cout << "on pRspQryWarningQuery->EvendID:"<<pRspQryWarningQuery->EvendID<< endl;
  cout << "on pRspQryWarningQuery->DBQueryResult:"<<pRspQryWarningQuery->DBQueryResult<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryWarningQueryField* pNewRspQryWarningQuery =new CShfeFtdcRspQryWarningQueryField;
  memcpy(pNewRspQryWarningQuery,pRspQryWarningQuery,sizeof(CShfeFtdcRspQryWarningQueryField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryWarningQuery;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryWarningQueryTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryWarningQueryTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnWarningQueryTopic(CShfeFtdcRtnWarningQueryField *pRtnWarningQuery)
{
  cout << "ok"<< endl;
  cout << "on pRtnWarningQuery->MonDate:"<<pRtnWarningQuery->MonDate<< endl;
  cout << "on pRtnWarningQuery->MonTime:"<<pRtnWarningQuery->MonTime<< endl;
  cout << "on pRtnWarningQuery->EvendID:"<<pRtnWarningQuery->EvendID<< endl;
  cout << "on pRtnWarningQuery->DBQueryResult:"<<pRtnWarningQuery->DBQueryResult<< endl;
  CShfeFtdcRtnWarningQueryField* pNewRtnWarningQuery =new CShfeFtdcRtnWarningQueryField;
  memcpy(pNewRtnWarningQuery,pRtnWarningQuery,sizeof(CShfeFtdcRtnWarningQueryField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnWarningQuery;
  asyncOnRtnWarningQueryTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnWarningQueryTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnHostConfig(CShfeFtdcRtnHostConfigField *pRtnHostConfig)
{
  cout << "ok"<< endl;
  cout << "on pRtnHostConfig->CfgType:"<<pRtnHostConfig->CfgType<< endl;
  cout << "on pRtnHostConfig->CfgDataCenter:"<<pRtnHostConfig->CfgDataCenter<< endl;
  cout << "on pRtnHostConfig->CfgName:"<<pRtnHostConfig->CfgName<< endl;
  cout << "on pRtnHostConfig->CfgLocation:"<<pRtnHostConfig->CfgLocation<< endl;
  cout << "on pRtnHostConfig->CfgHostName:"<<pRtnHostConfig->CfgHostName<< endl;
  cout << "on pRtnHostConfig->CfgAttend:"<<pRtnHostConfig->CfgAttend<< endl;
  CShfeFtdcRtnHostConfigField* pNewRtnHostConfig =new CShfeFtdcRtnHostConfigField;
  memcpy(pNewRtnHostConfig,pRtnHostConfig,sizeof(CShfeFtdcRtnHostConfigField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnHostConfig;
  asyncOnRtnHostConfig.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnHostConfig);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryGeneralOperateTopic(CShfeFtdcRspQryGeneralOperateField *pRspQryGeneralOperate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryGeneralOperate->GeneralOperateType:"<<pRspQryGeneralOperate->GeneralOperateType<< endl;
  cout << "on pRspQryGeneralOperate->GeneralOperateTable:"<<pRspQryGeneralOperate->GeneralOperateTable<< endl;
  cout << "on pRspQryGeneralOperate->GeneralOperateOption:"<<pRspQryGeneralOperate->GeneralOperateOption<< endl;
  cout << "on pRspQryGeneralOperate->GeneralOperateSet:"<<pRspQryGeneralOperate->GeneralOperateSet<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryGeneralOperateField* pNewRspQryGeneralOperate =new CShfeFtdcRspQryGeneralOperateField;
  memcpy(pNewRspQryGeneralOperate,pRspQryGeneralOperate,sizeof(CShfeFtdcRspQryGeneralOperateField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryGeneralOperate;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryGeneralOperateTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryGeneralOperateTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnGeneralOperateTopic(CShfeFtdcRtnGeneralOperateField *pRtnGeneralOperate)
{
  cout << "ok"<< endl;
  cout << "on pRtnGeneralOperate->GeneralOperateType:"<<pRtnGeneralOperate->GeneralOperateType<< endl;
  cout << "on pRtnGeneralOperate->GeneralOperateTable:"<<pRtnGeneralOperate->GeneralOperateTable<< endl;
  cout << "on pRtnGeneralOperate->GeneralOperateOption:"<<pRtnGeneralOperate->GeneralOperateOption<< endl;
  cout << "on pRtnGeneralOperate->GeneralOperateSet:"<<pRtnGeneralOperate->GeneralOperateSet<< endl;
  CShfeFtdcRtnGeneralOperateField* pNewRtnGeneralOperate =new CShfeFtdcRtnGeneralOperateField;
  memcpy(pNewRtnGeneralOperate,pRtnGeneralOperate,sizeof(CShfeFtdcRtnGeneralOperateField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnGeneralOperate;
  asyncOnRtnGeneralOperateTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnGeneralOperateTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetDeviceLinkedTopic(CShfeFtdcRspQryNetDeviceLinkedField *pRspQryNetDeviceLinked, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetDeviceLinked->OperationType:"<<pRspQryNetDeviceLinked->OperationType<< endl;
  cout << "on pRspQryNetDeviceLinked->ID:"<<pRspQryNetDeviceLinked->ID<< endl;
  cout << "on pRspQryNetDeviceLinked->NetDeviceID:"<<pRspQryNetDeviceLinked->NetDeviceID<< endl;
  cout << "on pRspQryNetDeviceLinked->NetPortID:"<<pRspQryNetDeviceLinked->NetPortID<< endl;
  cout << "on pRspQryNetDeviceLinked->NetObjectID:"<<pRspQryNetDeviceLinked->NetObjectID<< endl;
  cout << "on pRspQryNetDeviceLinked->NetPortType:"<<pRspQryNetDeviceLinked->NetPortType<< endl;
  cout << "on pRspQryNetDeviceLinked->LinkNetDeviceID:"<<pRspQryNetDeviceLinked->LinkNetDeviceID<< endl;
  cout << "on pRspQryNetDeviceLinked->LinkNetPortID:"<<pRspQryNetDeviceLinked->LinkNetPortID<< endl;
  cout << "on pRspQryNetDeviceLinked->LinkNetObjectID:"<<pRspQryNetDeviceLinked->LinkNetObjectID<< endl;
  cout << "on pRspQryNetDeviceLinked->LinkNetPortType:"<<pRspQryNetDeviceLinked->LinkNetPortType<< endl;
  cout << "on pRspQryNetDeviceLinked->LinkSource:"<<pRspQryNetDeviceLinked->LinkSource<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetDeviceLinkedField* pNewRspQryNetDeviceLinked =new CShfeFtdcRspQryNetDeviceLinkedField;
  memcpy(pNewRspQryNetDeviceLinked,pRspQryNetDeviceLinked,sizeof(CShfeFtdcRspQryNetDeviceLinkedField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetDeviceLinked;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetDeviceLinkedTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetDeviceLinkedTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetDeviceLinkedTopic(CShfeFtdcRtnNetDeviceLinkedField *pRtnNetDeviceLinked)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetDeviceLinked->OperationType:"<<pRtnNetDeviceLinked->OperationType<< endl;
  cout << "on pRtnNetDeviceLinked->ID:"<<pRtnNetDeviceLinked->ID<< endl;
  cout << "on pRtnNetDeviceLinked->NetDeviceID:"<<pRtnNetDeviceLinked->NetDeviceID<< endl;
  cout << "on pRtnNetDeviceLinked->NetPortID:"<<pRtnNetDeviceLinked->NetPortID<< endl;
  cout << "on pRtnNetDeviceLinked->NetObjectID:"<<pRtnNetDeviceLinked->NetObjectID<< endl;
  cout << "on pRtnNetDeviceLinked->NetPortType:"<<pRtnNetDeviceLinked->NetPortType<< endl;
  cout << "on pRtnNetDeviceLinked->LinkNetDeviceID:"<<pRtnNetDeviceLinked->LinkNetDeviceID<< endl;
  cout << "on pRtnNetDeviceLinked->LinkNetPortID:"<<pRtnNetDeviceLinked->LinkNetPortID<< endl;
  cout << "on pRtnNetDeviceLinked->LinkNetObjectID:"<<pRtnNetDeviceLinked->LinkNetObjectID<< endl;
  cout << "on pRtnNetDeviceLinked->LinkNetPortType:"<<pRtnNetDeviceLinked->LinkNetPortType<< endl;
  cout << "on pRtnNetDeviceLinked->LinkSource:"<<pRtnNetDeviceLinked->LinkSource<< endl;
  CShfeFtdcRtnNetDeviceLinkedField* pNewRtnNetDeviceLinked =new CShfeFtdcRtnNetDeviceLinkedField;
  memcpy(pNewRtnNetDeviceLinked,pRtnNetDeviceLinked,sizeof(CShfeFtdcRtnNetDeviceLinkedField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetDeviceLinked;
  asyncOnRtnNetDeviceLinkedTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetDeviceLinkedTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryTradeUserLoginStatTopic(CShfeFtdcRspQryTradeUserLoginStatField *pRspQryTradeUserLoginStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryTradeUserLoginStat->MonDate:"<<pRspQryTradeUserLoginStat->MonDate<< endl;
  cout << "on pRspQryTradeUserLoginStat->MonTime:"<<pRspQryTradeUserLoginStat->MonTime<< endl;
  cout << "on pRspQryTradeUserLoginStat->ObjectID:"<<pRspQryTradeUserLoginStat->ObjectID<< endl;
  cout << "on pRspQryTradeUserLoginStat->IPAddress:"<<pRspQryTradeUserLoginStat->IPAddress<< endl;
  cout << "on pRspQryTradeUserLoginStat->ParticipantID:"<<pRspQryTradeUserLoginStat->ParticipantID<< endl;
  cout << "on pRspQryTradeUserLoginStat->UserID:"<<pRspQryTradeUserLoginStat->UserID<< endl;
  cout << "on pRspQryTradeUserLoginStat->FrontId:"<<pRspQryTradeUserLoginStat->FrontId<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryTradeUserLoginStatField* pNewRspQryTradeUserLoginStat =new CShfeFtdcRspQryTradeUserLoginStatField;
  memcpy(pNewRspQryTradeUserLoginStat,pRspQryTradeUserLoginStat,sizeof(CShfeFtdcRspQryTradeUserLoginStatField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTradeUserLoginStat;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTradeUserLoginStatTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryTradeUserLoginStatTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryTradeFrontOrderRttStatTopic(CShfeFtdcRspQryTradeFrontOrderRttStatField *pRspQryTradeFrontOrderRttStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryTradeFrontOrderRttStat->MonDate:"<<pRspQryTradeFrontOrderRttStat->MonDate<< endl;
  cout << "on pRspQryTradeFrontOrderRttStat->MonTime:"<<pRspQryTradeFrontOrderRttStat->MonTime<< endl;
  cout << "on pRspQryTradeFrontOrderRttStat->ObjectID:"<<pRspQryTradeFrontOrderRttStat->ObjectID<< endl;
  cout << "on pRspQryTradeFrontOrderRttStat->OrderCount:"<<pRspQryTradeFrontOrderRttStat->OrderCount<< endl;
  cout << "on pRspQryTradeFrontOrderRttStat->OrderRttSum:"<<pRspQryTradeFrontOrderRttStat->OrderRttSum<< endl;
  cout << "on pRspQryTradeFrontOrderRttStat->OrderMaxRtt:"<<pRspQryTradeFrontOrderRttStat->OrderMaxRtt<< endl;
  cout << "on pRspQryTradeFrontOrderRttStat->OrderMinRtt:"<<pRspQryTradeFrontOrderRttStat->OrderMinRtt<< endl;
  cout << "on pRspQryTradeFrontOrderRttStat->OrderRttSqu:"<<pRspQryTradeFrontOrderRttStat->OrderRttSqu<< endl;
  cout << "on pRspQryTradeFrontOrderRttStat->OrderRttCutDistrib:"<<pRspQryTradeFrontOrderRttStat->OrderRttCutDistrib<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryTradeFrontOrderRttStatField* pNewRspQryTradeFrontOrderRttStat =new CShfeFtdcRspQryTradeFrontOrderRttStatField;
  memcpy(pNewRspQryTradeFrontOrderRttStat,pRspQryTradeFrontOrderRttStat,sizeof(CShfeFtdcRspQryTradeFrontOrderRttStatField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTradeFrontOrderRttStat;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTradeFrontOrderRttStatTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryTradeFrontOrderRttStatTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnTradeFrontOrderRttStatTopic(CShfeFtdcRtnTradeFrontOrderRttStatField *pRtnTradeFrontOrderRttStat)
{
  cout << "ok"<< endl;
  cout << "on pRtnTradeFrontOrderRttStat->MonDate:"<<pRtnTradeFrontOrderRttStat->MonDate<< endl;
  cout << "on pRtnTradeFrontOrderRttStat->MonTime:"<<pRtnTradeFrontOrderRttStat->MonTime<< endl;
  cout << "on pRtnTradeFrontOrderRttStat->ObjectID:"<<pRtnTradeFrontOrderRttStat->ObjectID<< endl;
  cout << "on pRtnTradeFrontOrderRttStat->OrderCount:"<<pRtnTradeFrontOrderRttStat->OrderCount<< endl;
  cout << "on pRtnTradeFrontOrderRttStat->OrderRttSum:"<<pRtnTradeFrontOrderRttStat->OrderRttSum<< endl;
  cout << "on pRtnTradeFrontOrderRttStat->OrderMaxRtt:"<<pRtnTradeFrontOrderRttStat->OrderMaxRtt<< endl;
  cout << "on pRtnTradeFrontOrderRttStat->OrderMinRtt:"<<pRtnTradeFrontOrderRttStat->OrderMinRtt<< endl;
  cout << "on pRtnTradeFrontOrderRttStat->OrderRttSqu:"<<pRtnTradeFrontOrderRttStat->OrderRttSqu<< endl;
  cout << "on pRtnTradeFrontOrderRttStat->OrderRttCutDistrib:"<<pRtnTradeFrontOrderRttStat->OrderRttCutDistrib<< endl;
  CShfeFtdcRtnTradeFrontOrderRttStatField* pNewRtnTradeFrontOrderRttStat =new CShfeFtdcRtnTradeFrontOrderRttStatField;
  memcpy(pNewRtnTradeFrontOrderRttStat,pRtnTradeFrontOrderRttStat,sizeof(CShfeFtdcRtnTradeFrontOrderRttStatField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnTradeFrontOrderRttStat;
  asyncOnRtnTradeFrontOrderRttStatTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnTradeFrontOrderRttStatTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryParticTradeOrderStatesTopic(CShfeFtdcRspQryParticTradeOrderStatesField *pRspQryParticTradeOrderStates, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryParticTradeOrderStates->ParticipantID:"<<pRspQryParticTradeOrderStates->ParticipantID<< endl;
  cout << "on pRspQryParticTradeOrderStates->UserID:"<<pRspQryParticTradeOrderStates->UserID<< endl;
  cout << "on pRspQryParticTradeOrderStates->MonDate:"<<pRspQryParticTradeOrderStates->MonDate<< endl;
  cout << "on pRspQryParticTradeOrderStates->MonTime:"<<pRspQryParticTradeOrderStates->MonTime<< endl;
  cout << "on pRspQryParticTradeOrderStates->StaticWidth:"<<pRspQryParticTradeOrderStates->StaticWidth<< endl;
  cout << "on pRspQryParticTradeOrderStates->FrontID:"<<pRspQryParticTradeOrderStates->FrontID<< endl;
  cout << "on pRspQryParticTradeOrderStates->OrderCount:"<<pRspQryParticTradeOrderStates->OrderCount<< endl;
  cout << "on pRspQryParticTradeOrderStates->CancleCount:"<<pRspQryParticTradeOrderStates->CancleCount<< endl;
  cout << "on pRspQryParticTradeOrderStates->QueryCount:"<<pRspQryParticTradeOrderStates->QueryCount<< endl;
  cout << "on pRspQryParticTradeOrderStates->TradeCount:"<<pRspQryParticTradeOrderStates->TradeCount<< endl;
  cout << "on pRspQryParticTradeOrderStates->TradeMoney:"<<pRspQryParticTradeOrderStates->TradeMoney<< endl;
  cout << "on pRspQryParticTradeOrderStates->OrderCntMax:"<<pRspQryParticTradeOrderStates->OrderCntMax<< endl;
  cout << "on pRspQryParticTradeOrderStates->CancleCntMax:"<<pRspQryParticTradeOrderStates->CancleCntMax<< endl;
  cout << "on pRspQryParticTradeOrderStates->QueryCntMax:"<<pRspQryParticTradeOrderStates->QueryCntMax<< endl;
  cout << "on pRspQryParticTradeOrderStates->TradeCntMax:"<<pRspQryParticTradeOrderStates->TradeCntMax<< endl;
  cout << "on pRspQryParticTradeOrderStates->TradeMoneyMax:"<<pRspQryParticTradeOrderStates->TradeMoneyMax<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryParticTradeOrderStatesField* pNewRspQryParticTradeOrderStates =new CShfeFtdcRspQryParticTradeOrderStatesField;
  memcpy(pNewRspQryParticTradeOrderStates,pRspQryParticTradeOrderStates,sizeof(CShfeFtdcRspQryParticTradeOrderStatesField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryParticTradeOrderStates;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryParticTradeOrderStatesTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryParticTradeOrderStatesTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnParticTradeOrderStatesTopic(CShfeFtdcRtnParticTradeOrderStatesField *pRtnParticTradeOrderStates)
{
  cout << "ok"<< endl;
  cout << "on pRtnParticTradeOrderStates->ParticipantID:"<<pRtnParticTradeOrderStates->ParticipantID<< endl;
  cout << "on pRtnParticTradeOrderStates->UserID:"<<pRtnParticTradeOrderStates->UserID<< endl;
  cout << "on pRtnParticTradeOrderStates->MonDate:"<<pRtnParticTradeOrderStates->MonDate<< endl;
  cout << "on pRtnParticTradeOrderStates->MonTime:"<<pRtnParticTradeOrderStates->MonTime<< endl;
  cout << "on pRtnParticTradeOrderStates->StaticWidth:"<<pRtnParticTradeOrderStates->StaticWidth<< endl;
  cout << "on pRtnParticTradeOrderStates->FrontID:"<<pRtnParticTradeOrderStates->FrontID<< endl;
  cout << "on pRtnParticTradeOrderStates->OrderCount:"<<pRtnParticTradeOrderStates->OrderCount<< endl;
  cout << "on pRtnParticTradeOrderStates->CancleCount:"<<pRtnParticTradeOrderStates->CancleCount<< endl;
  cout << "on pRtnParticTradeOrderStates->QueryCount:"<<pRtnParticTradeOrderStates->QueryCount<< endl;
  cout << "on pRtnParticTradeOrderStates->TradeCount:"<<pRtnParticTradeOrderStates->TradeCount<< endl;
  cout << "on pRtnParticTradeOrderStates->TradeMoney:"<<pRtnParticTradeOrderStates->TradeMoney<< endl;
  cout << "on pRtnParticTradeOrderStates->OrderCntMax:"<<pRtnParticTradeOrderStates->OrderCntMax<< endl;
  cout << "on pRtnParticTradeOrderStates->CancleCntMax:"<<pRtnParticTradeOrderStates->CancleCntMax<< endl;
  cout << "on pRtnParticTradeOrderStates->QueryCntMax:"<<pRtnParticTradeOrderStates->QueryCntMax<< endl;
  cout << "on pRtnParticTradeOrderStates->TradeCntMax:"<<pRtnParticTradeOrderStates->TradeCntMax<< endl;
  cout << "on pRtnParticTradeOrderStates->TradeMoneyMax:"<<pRtnParticTradeOrderStates->TradeMoneyMax<< endl;
  CShfeFtdcRtnParticTradeOrderStatesField* pNewRtnParticTradeOrderStates =new CShfeFtdcRtnParticTradeOrderStatesField;
  memcpy(pNewRtnParticTradeOrderStates,pRtnParticTradeOrderStates,sizeof(CShfeFtdcRtnParticTradeOrderStatesField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnParticTradeOrderStates;
  asyncOnRtnParticTradeOrderStatesTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnParticTradeOrderStatesTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryRouterInfoTopic(CShfeFtdcRspQryRouterInfoField *pRspQryRouterInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryRouterInfo->HostName:"<<pRspQryRouterInfo->HostName<< endl;
  cout << "on pRspQryRouterInfo->MonDate:"<<pRspQryRouterInfo->MonDate<< endl;
  cout << "on pRspQryRouterInfo->MonTime:"<<pRspQryRouterInfo->MonTime<< endl;
  cout << "on pRspQryRouterInfo->Dev:"<<pRspQryRouterInfo->Dev<< endl;
  cout << "on pRspQryRouterInfo->Destination:"<<pRspQryRouterInfo->Destination<< endl;
  cout << "on pRspQryRouterInfo->Gateway:"<<pRspQryRouterInfo->Gateway<< endl;
  cout << "on pRspQryRouterInfo->Mask:"<<pRspQryRouterInfo->Mask<< endl;
  cout << "on pRspQryRouterInfo->Flag:"<<pRspQryRouterInfo->Flag<< endl;
  cout << "on pRspQryRouterInfo->RefCnt:"<<pRspQryRouterInfo->RefCnt<< endl;
  cout << "on pRspQryRouterInfo->Use:"<<pRspQryRouterInfo->Use<< endl;
  cout << "on pRspQryRouterInfo->Metric:"<<pRspQryRouterInfo->Metric<< endl;
  cout << "on pRspQryRouterInfo->Mtu:"<<pRspQryRouterInfo->Mtu<< endl;
  cout << "on pRspQryRouterInfo->Win:"<<pRspQryRouterInfo->Win<< endl;
  cout << "on pRspQryRouterInfo->Rtt:"<<pRspQryRouterInfo->Rtt<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryRouterInfoField* pNewRspQryRouterInfo =new CShfeFtdcRspQryRouterInfoField;
  memcpy(pNewRspQryRouterInfo,pRspQryRouterInfo,sizeof(CShfeFtdcRspQryRouterInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryRouterInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryRouterInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryRouterInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnRouterInfoTopic(CShfeFtdcRtnRouterInfoField *pRtnRouterInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnRouterInfo->HostName:"<<pRtnRouterInfo->HostName<< endl;
  cout << "on pRtnRouterInfo->MonDate:"<<pRtnRouterInfo->MonDate<< endl;
  cout << "on pRtnRouterInfo->MonTime:"<<pRtnRouterInfo->MonTime<< endl;
  cout << "on pRtnRouterInfo->Dev:"<<pRtnRouterInfo->Dev<< endl;
  cout << "on pRtnRouterInfo->Destination:"<<pRtnRouterInfo->Destination<< endl;
  cout << "on pRtnRouterInfo->Gateway:"<<pRtnRouterInfo->Gateway<< endl;
  cout << "on pRtnRouterInfo->Mask:"<<pRtnRouterInfo->Mask<< endl;
  cout << "on pRtnRouterInfo->Flag:"<<pRtnRouterInfo->Flag<< endl;
  cout << "on pRtnRouterInfo->RefCnt:"<<pRtnRouterInfo->RefCnt<< endl;
  cout << "on pRtnRouterInfo->Use:"<<pRtnRouterInfo->Use<< endl;
  cout << "on pRtnRouterInfo->Metric:"<<pRtnRouterInfo->Metric<< endl;
  cout << "on pRtnRouterInfo->Mtu:"<<pRtnRouterInfo->Mtu<< endl;
  cout << "on pRtnRouterInfo->Win:"<<pRtnRouterInfo->Win<< endl;
  cout << "on pRtnRouterInfo->Rtt:"<<pRtnRouterInfo->Rtt<< endl;
  CShfeFtdcRtnRouterInfoField* pNewRtnRouterInfo =new CShfeFtdcRtnRouterInfoField;
  memcpy(pNewRtnRouterInfo,pRtnRouterInfo,sizeof(CShfeFtdcRtnRouterInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnRouterInfo;
  asyncOnRtnRouterInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnRouterInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryDiskIOTopic(CShfeFtdcRspQryDiskIOField *pRspQryDiskIO, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryDiskIO->HostName:"<<pRspQryDiskIO->HostName<< endl;
  cout << "on pRspQryDiskIO->MonDate:"<<pRspQryDiskIO->MonDate<< endl;
  cout << "on pRspQryDiskIO->MonTime:"<<pRspQryDiskIO->MonTime<< endl;
  cout << "on pRspQryDiskIO->PartName:"<<pRspQryDiskIO->PartName<< endl;
  cout << "on pRspQryDiskIO->ReadMerges:"<<pRspQryDiskIO->ReadMerges<< endl;
  cout << "on pRspQryDiskIO->WriteMerges:"<<pRspQryDiskIO->WriteMerges<< endl;
  cout << "on pRspQryDiskIO->ReadIOs:"<<pRspQryDiskIO->ReadIOs<< endl;
  cout << "on pRspQryDiskIO->WriteIOs:"<<pRspQryDiskIO->WriteIOs<< endl;
  cout << "on pRspQryDiskIO->ReadKBs:"<<pRspQryDiskIO->ReadKBs<< endl;
  cout << "on pRspQryDiskIO->WriteKBs:"<<pRspQryDiskIO->WriteKBs<< endl;
  cout << "on pRspQryDiskIO->SizeVal:"<<pRspQryDiskIO->SizeVal<< endl;
  cout << "on pRspQryDiskIO->QueueVal:"<<pRspQryDiskIO->QueueVal<< endl;
  cout << "on pRspQryDiskIO->Svc_t:"<<pRspQryDiskIO->Svc_t<< endl;
  cout << "on pRspQryDiskIO->Busy:"<<pRspQryDiskIO->Busy<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryDiskIOField* pNewRspQryDiskIO =new CShfeFtdcRspQryDiskIOField;
  memcpy(pNewRspQryDiskIO,pRspQryDiskIO,sizeof(CShfeFtdcRspQryDiskIOField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryDiskIO;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryDiskIOTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryDiskIOTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnDiskIOTopic(CShfeFtdcRtnDiskIOField *pRtnDiskIO)
{
  cout << "ok"<< endl;
  cout << "on pRtnDiskIO->HostName:"<<pRtnDiskIO->HostName<< endl;
  cout << "on pRtnDiskIO->MonDate:"<<pRtnDiskIO->MonDate<< endl;
  cout << "on pRtnDiskIO->MonTime:"<<pRtnDiskIO->MonTime<< endl;
  cout << "on pRtnDiskIO->PartName:"<<pRtnDiskIO->PartName<< endl;
  cout << "on pRtnDiskIO->ReadMerges:"<<pRtnDiskIO->ReadMerges<< endl;
  cout << "on pRtnDiskIO->WriteMerges:"<<pRtnDiskIO->WriteMerges<< endl;
  cout << "on pRtnDiskIO->ReadIOs:"<<pRtnDiskIO->ReadIOs<< endl;
  cout << "on pRtnDiskIO->WriteIOs:"<<pRtnDiskIO->WriteIOs<< endl;
  cout << "on pRtnDiskIO->ReadKBs:"<<pRtnDiskIO->ReadKBs<< endl;
  cout << "on pRtnDiskIO->WriteKBs:"<<pRtnDiskIO->WriteKBs<< endl;
  cout << "on pRtnDiskIO->SizeVal:"<<pRtnDiskIO->SizeVal<< endl;
  cout << "on pRtnDiskIO->QueueVal:"<<pRtnDiskIO->QueueVal<< endl;
  cout << "on pRtnDiskIO->Svc_t:"<<pRtnDiskIO->Svc_t<< endl;
  cout << "on pRtnDiskIO->Busy:"<<pRtnDiskIO->Busy<< endl;
  CShfeFtdcRtnDiskIOField* pNewRtnDiskIO =new CShfeFtdcRtnDiskIOField;
  memcpy(pNewRtnDiskIO,pRtnDiskIO,sizeof(CShfeFtdcRtnDiskIOField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnDiskIO;
  asyncOnRtnDiskIOTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnDiskIOTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryStatInfoTopic(CShfeFtdcRspQryStatInfoField *pRspQryStatInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryStatInfo->HostName:"<<pRspQryStatInfo->HostName<< endl;
  cout << "on pRspQryStatInfo->MonDate:"<<pRspQryStatInfo->MonDate<< endl;
  cout << "on pRspQryStatInfo->MonTime:"<<pRspQryStatInfo->MonTime<< endl;
  cout << "on pRspQryStatInfo->ProcRun:"<<pRspQryStatInfo->ProcRun<< endl;
  cout << "on pRspQryStatInfo->ProcBlk:"<<pRspQryStatInfo->ProcBlk<< endl;
  cout << "on pRspQryStatInfo->SwapIn:"<<pRspQryStatInfo->SwapIn<< endl;
  cout << "on pRspQryStatInfo->SwapOut:"<<pRspQryStatInfo->SwapOut<< endl;
  cout << "on pRspQryStatInfo->BlockIn:"<<pRspQryStatInfo->BlockIn<< endl;
  cout << "on pRspQryStatInfo->BlockOut:"<<pRspQryStatInfo->BlockOut<< endl;
  cout << "on pRspQryStatInfo->Inter:"<<pRspQryStatInfo->Inter<< endl;
  cout << "on pRspQryStatInfo->Context:"<<pRspQryStatInfo->Context<< endl;
  cout << "on pRspQryStatInfo->CPUUser:"<<pRspQryStatInfo->CPUUser<< endl;
  cout << "on pRspQryStatInfo->CPUSys:"<<pRspQryStatInfo->CPUSys<< endl;
  cout << "on pRspQryStatInfo->CPUIdle:"<<pRspQryStatInfo->CPUIdle<< endl;
  cout << "on pRspQryStatInfo->CPUIOWait:"<<pRspQryStatInfo->CPUIOWait<< endl;
  cout << "on pRspQryStatInfo->CPUSteal:"<<pRspQryStatInfo->CPUSteal<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryStatInfoField* pNewRspQryStatInfo =new CShfeFtdcRspQryStatInfoField;
  memcpy(pNewRspQryStatInfo,pRspQryStatInfo,sizeof(CShfeFtdcRspQryStatInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryStatInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryStatInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryStatInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnStatInfoTopic(CShfeFtdcRtnStatInfoField *pRtnStatInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnStatInfo->HostName:"<<pRtnStatInfo->HostName<< endl;
  cout << "on pRtnStatInfo->MonDate:"<<pRtnStatInfo->MonDate<< endl;
  cout << "on pRtnStatInfo->MonTime:"<<pRtnStatInfo->MonTime<< endl;
  cout << "on pRtnStatInfo->ProcRun:"<<pRtnStatInfo->ProcRun<< endl;
  cout << "on pRtnStatInfo->ProcBlk:"<<pRtnStatInfo->ProcBlk<< endl;
  cout << "on pRtnStatInfo->SwapIn:"<<pRtnStatInfo->SwapIn<< endl;
  cout << "on pRtnStatInfo->SwapOut:"<<pRtnStatInfo->SwapOut<< endl;
  cout << "on pRtnStatInfo->BlockIn:"<<pRtnStatInfo->BlockIn<< endl;
  cout << "on pRtnStatInfo->BlockOut:"<<pRtnStatInfo->BlockOut<< endl;
  cout << "on pRtnStatInfo->Inter:"<<pRtnStatInfo->Inter<< endl;
  cout << "on pRtnStatInfo->Context:"<<pRtnStatInfo->Context<< endl;
  cout << "on pRtnStatInfo->CPUUser:"<<pRtnStatInfo->CPUUser<< endl;
  cout << "on pRtnStatInfo->CPUSys:"<<pRtnStatInfo->CPUSys<< endl;
  cout << "on pRtnStatInfo->CPUIdle:"<<pRtnStatInfo->CPUIdle<< endl;
  cout << "on pRtnStatInfo->CPUIOWait:"<<pRtnStatInfo->CPUIOWait<< endl;
  cout << "on pRtnStatInfo->CPUSteal:"<<pRtnStatInfo->CPUSteal<< endl;
  CShfeFtdcRtnStatInfoField* pNewRtnStatInfo =new CShfeFtdcRtnStatInfoField;
  memcpy(pNewRtnStatInfo,pRtnStatInfo,sizeof(CShfeFtdcRtnStatInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnStatInfo;
  asyncOnRtnStatInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnStatInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryTradeOrderRttCutLineTopic(CShfeFtdcRspQryTradeOrderRttCutLineField *pRspQryTradeOrderRttCutLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryTradeOrderRttCutLine->MonDate:"<<pRspQryTradeOrderRttCutLine->MonDate<< endl;
  cout << "on pRspQryTradeOrderRttCutLine->MonTime:"<<pRspQryTradeOrderRttCutLine->MonTime<< endl;
  cout << "on pRspQryTradeOrderRttCutLine->UserName:"<<pRspQryTradeOrderRttCutLine->UserName<< endl;
  cout << "on pRspQryTradeOrderRttCutLine->OrderRttCutLine:"<<pRspQryTradeOrderRttCutLine->OrderRttCutLine<< endl;
  cout << "on pRspQryTradeOrderRttCutLine->OrderRttWidth:"<<pRspQryTradeOrderRttCutLine->OrderRttWidth<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryTradeOrderRttCutLineField* pNewRspQryTradeOrderRttCutLine =new CShfeFtdcRspQryTradeOrderRttCutLineField;
  memcpy(pNewRspQryTradeOrderRttCutLine,pRspQryTradeOrderRttCutLine,sizeof(CShfeFtdcRspQryTradeOrderRttCutLineField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTradeOrderRttCutLine;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTradeOrderRttCutLineTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryTradeOrderRttCutLineTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnTradeOrderRttCutLineTopic(CShfeFtdcRtnTradeOrderRttCutLineField *pRtnTradeOrderRttCutLine)
{
  cout << "ok"<< endl;
  cout << "on pRtnTradeOrderRttCutLine->MonDate:"<<pRtnTradeOrderRttCutLine->MonDate<< endl;
  cout << "on pRtnTradeOrderRttCutLine->OrderRttCutLine:"<<pRtnTradeOrderRttCutLine->OrderRttCutLine<< endl;
  CShfeFtdcRtnTradeOrderRttCutLineField* pNewRtnTradeOrderRttCutLine =new CShfeFtdcRtnTradeOrderRttCutLineField;
  memcpy(pNewRtnTradeOrderRttCutLine,pRtnTradeOrderRttCutLine,sizeof(CShfeFtdcRtnTradeOrderRttCutLineField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnTradeOrderRttCutLine;
  asyncOnRtnTradeOrderRttCutLineTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnTradeOrderRttCutLineTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryClientInfoTopic(CShfeFtdcRspQryClientInfoField *pRspQryClientInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryClientInfo->ClientID:"<<pRspQryClientInfo->ClientID<< endl;
  cout << "on pRspQryClientInfo->ClientName:"<<pRspQryClientInfo->ClientName<< endl;
  cout << "on pRspQryClientInfo->IdentifiedCardType:"<<pRspQryClientInfo->IdentifiedCardType<< endl;
  cout << "on pRspQryClientInfo->IdentifiedCardNo:"<<pRspQryClientInfo->IdentifiedCardNo<< endl;
  cout << "on pRspQryClientInfo->TradingRole:"<<pRspQryClientInfo->TradingRole<< endl;
  cout << "on pRspQryClientInfo->ClientType:"<<pRspQryClientInfo->ClientType<< endl;
  cout << "on pRspQryClientInfo->IsActive:"<<pRspQryClientInfo->IsActive<< endl;
  cout << "on pRspQryClientInfo->OperationType:"<<pRspQryClientInfo->OperationType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryClientInfoField* pNewRspQryClientInfo =new CShfeFtdcRspQryClientInfoField;
  memcpy(pNewRspQryClientInfo,pRspQryClientInfo,sizeof(CShfeFtdcRspQryClientInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryClientInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryClientInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryClientInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnClientInfoTopic(CShfeFtdcRtnClientInfoField *pRtnClientInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnClientInfo->ClientID:"<<pRtnClientInfo->ClientID<< endl;
  cout << "on pRtnClientInfo->ClientName:"<<pRtnClientInfo->ClientName<< endl;
  cout << "on pRtnClientInfo->IdentifiedCardType:"<<pRtnClientInfo->IdentifiedCardType<< endl;
  cout << "on pRtnClientInfo->IdentifiedCardNo:"<<pRtnClientInfo->IdentifiedCardNo<< endl;
  cout << "on pRtnClientInfo->TradingRole:"<<pRtnClientInfo->TradingRole<< endl;
  cout << "on pRtnClientInfo->ClientType:"<<pRtnClientInfo->ClientType<< endl;
  cout << "on pRtnClientInfo->IsActive:"<<pRtnClientInfo->IsActive<< endl;
  cout << "on pRtnClientInfo->OperationType:"<<pRtnClientInfo->OperationType<< endl;
  CShfeFtdcRtnClientInfoField* pNewRtnClientInfo =new CShfeFtdcRtnClientInfoField;
  memcpy(pNewRtnClientInfo,pRtnClientInfo,sizeof(CShfeFtdcRtnClientInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnClientInfo;
  asyncOnRtnClientInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnClientInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryEventDescriptionTopic(CShfeFtdcRspQryEventDescriptionField *pRspQryEventDescription, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryEventDescription->EventDesID:"<<pRspQryEventDescription->EventDesID<< endl;
  cout << "on pRspQryEventDescription->UserName:"<<pRspQryEventDescription->UserName<< endl;
  cout << "on pRspQryEventDescription->MonDate:"<<pRspQryEventDescription->MonDate<< endl;
  cout << "on pRspQryEventDescription->MonTime:"<<pRspQryEventDescription->MonTime<< endl;
  cout << "on pRspQryEventDescription->EventDes:"<<pRspQryEventDescription->EventDes<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryEventDescriptionField* pNewRspQryEventDescription =new CShfeFtdcRspQryEventDescriptionField;
  memcpy(pNewRspQryEventDescription,pRspQryEventDescription,sizeof(CShfeFtdcRspQryEventDescriptionField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryEventDescription;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryEventDescriptionTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryEventDescriptionTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnEventDescriptionTopic(CShfeFtdcRtnEventDescriptionField *pRtnEventDescription)
{
  cout << "ok"<< endl;
  cout << "on pRtnEventDescription->EventDesID:"<<pRtnEventDescription->EventDesID<< endl;
  cout << "on pRtnEventDescription->UserName:"<<pRtnEventDescription->UserName<< endl;
  cout << "on pRtnEventDescription->MonDate:"<<pRtnEventDescription->MonDate<< endl;
  cout << "on pRtnEventDescription->MonTime:"<<pRtnEventDescription->MonTime<< endl;
  cout << "on pRtnEventDescription->EventDes:"<<pRtnEventDescription->EventDes<< endl;
  CShfeFtdcRtnEventDescriptionField* pNewRtnEventDescription =new CShfeFtdcRtnEventDescriptionField;
  memcpy(pNewRtnEventDescription,pRtnEventDescription,sizeof(CShfeFtdcRtnEventDescriptionField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnEventDescription;
  asyncOnRtnEventDescriptionTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnEventDescriptionTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryFrontUniqueIDTopic(CShfeFtdcRspQryFrontUniqueIDField *pRspQryFrontUniqueID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryFrontUniqueID->FrontID:"<<pRspQryFrontUniqueID->FrontID<< endl;
  cout << "on pRspQryFrontUniqueID->FrontName:"<<pRspQryFrontUniqueID->FrontName<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryFrontUniqueIDField* pNewRspQryFrontUniqueID =new CShfeFtdcRspQryFrontUniqueIDField;
  memcpy(pNewRspQryFrontUniqueID,pRspQryFrontUniqueID,sizeof(CShfeFtdcRspQryFrontUniqueIDField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryFrontUniqueID;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryFrontUniqueIDTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryFrontUniqueIDTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnFrontUniqueIDTopic(CShfeFtdcRtnFrontUniqueIDField *pRtnFrontUniqueID)
{
  cout << "ok"<< endl;
  cout << "on pRtnFrontUniqueID->FrontID:"<<pRtnFrontUniqueID->FrontID<< endl;
  cout << "on pRtnFrontUniqueID->FrontName:"<<pRtnFrontUniqueID->FrontName<< endl;
  CShfeFtdcRtnFrontUniqueIDField* pNewRtnFrontUniqueID =new CShfeFtdcRtnFrontUniqueIDField;
  memcpy(pNewRtnFrontUniqueID,pRtnFrontUniqueID,sizeof(CShfeFtdcRtnFrontUniqueIDField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnFrontUniqueID;
  asyncOnRtnFrontUniqueIDTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnFrontUniqueIDTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetPartyLinkAddrChangeTopic(CShfeFtdcRspQryNetPartyLinkAddrChangeField *pRspQryNetPartyLinkAddrChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetPartyLinkAddrChange->OperationType:"<<pRspQryNetPartyLinkAddrChange->OperationType<< endl;
  cout << "on pRspQryNetPartyLinkAddrChange->ID:"<<pRspQryNetPartyLinkAddrChange->ID<< endl;
  cout << "on pRspQryNetPartyLinkAddrChange->RelationID:"<<pRspQryNetPartyLinkAddrChange->RelationID<< endl;
  cout << "on pRspQryNetPartyLinkAddrChange->OLDADDRESS:"<<pRspQryNetPartyLinkAddrChange->OLDADDRESS<< endl;
  cout << "on pRspQryNetPartyLinkAddrChange->NEWADDRESS:"<<pRspQryNetPartyLinkAddrChange->NEWADDRESS<< endl;
  cout << "on pRspQryNetPartyLinkAddrChange->OPERATOR:"<<pRspQryNetPartyLinkAddrChange->OPERATOR<< endl;
  cout << "on pRspQryNetPartyLinkAddrChange->MonDate:"<<pRspQryNetPartyLinkAddrChange->MonDate<< endl;
  cout << "on pRspQryNetPartyLinkAddrChange->MonTime:"<<pRspQryNetPartyLinkAddrChange->MonTime<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetPartyLinkAddrChangeField* pNewRspQryNetPartyLinkAddrChange =new CShfeFtdcRspQryNetPartyLinkAddrChangeField;
  memcpy(pNewRspQryNetPartyLinkAddrChange,pRspQryNetPartyLinkAddrChange,sizeof(CShfeFtdcRspQryNetPartyLinkAddrChangeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetPartyLinkAddrChange;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetPartyLinkAddrChangeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetPartyLinkAddrChangeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetPartyLinkAddrChangeTopic(CShfeFtdcRtnNetPartyLinkAddrChangeField *pRtnNetPartyLinkAddrChange)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetPartyLinkAddrChange->OperationType:"<<pRtnNetPartyLinkAddrChange->OperationType<< endl;
  cout << "on pRtnNetPartyLinkAddrChange->ID:"<<pRtnNetPartyLinkAddrChange->ID<< endl;
  cout << "on pRtnNetPartyLinkAddrChange->RelationID:"<<pRtnNetPartyLinkAddrChange->RelationID<< endl;
  cout << "on pRtnNetPartyLinkAddrChange->OLDADDRESS:"<<pRtnNetPartyLinkAddrChange->OLDADDRESS<< endl;
  cout << "on pRtnNetPartyLinkAddrChange->NEWADDRESS:"<<pRtnNetPartyLinkAddrChange->NEWADDRESS<< endl;
  cout << "on pRtnNetPartyLinkAddrChange->OPERATOR:"<<pRtnNetPartyLinkAddrChange->OPERATOR<< endl;
  cout << "on pRtnNetPartyLinkAddrChange->MonDate:"<<pRtnNetPartyLinkAddrChange->MonDate<< endl;
  cout << "on pRtnNetPartyLinkAddrChange->MonTime:"<<pRtnNetPartyLinkAddrChange->MonTime<< endl;
  CShfeFtdcRtnNetPartyLinkAddrChangeField* pNewRtnNetPartyLinkAddrChange =new CShfeFtdcRtnNetPartyLinkAddrChangeField;
  memcpy(pNewRtnNetPartyLinkAddrChange,pRtnNetPartyLinkAddrChange,sizeof(CShfeFtdcRtnNetPartyLinkAddrChangeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetPartyLinkAddrChange;
  asyncOnRtnNetPartyLinkAddrChangeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetPartyLinkAddrChangeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetDelPartyLinkInfoTopic(CShfeFtdcRspQryNetDelPartyLinkInfoField *pRspQryNetDelPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->OperationType:"<<pRspQryNetDelPartyLinkInfo->OperationType<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->ID:"<<pRspQryNetDelPartyLinkInfo->ID<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->MEMBER_NO:"<<pRspQryNetDelPartyLinkInfo->MEMBER_NO<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->MEMBER_NAME:"<<pRspQryNetDelPartyLinkInfo->MEMBER_NAME<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->REMOTE_ADDR:"<<pRspQryNetDelPartyLinkInfo->REMOTE_ADDR<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->LOCAL_ADDR:"<<pRspQryNetDelPartyLinkInfo->LOCAL_ADDR<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->ADDRESS:"<<pRspQryNetDelPartyLinkInfo->ADDRESS<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->LINE_STATUS:"<<pRspQryNetDelPartyLinkInfo->LINE_STATUS<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->CONTACT:"<<pRspQryNetDelPartyLinkInfo->CONTACT<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->TELEPHONE:"<<pRspQryNetDelPartyLinkInfo->TELEPHONE<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->MOBILEPHONE:"<<pRspQryNetDelPartyLinkInfo->MOBILEPHONE<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->EMAIL:"<<pRspQryNetDelPartyLinkInfo->EMAIL<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->FAX:"<<pRspQryNetDelPartyLinkInfo->FAX<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->PROVINCE:"<<pRspQryNetDelPartyLinkInfo->PROVINCE<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->DDN_NO:"<<pRspQryNetDelPartyLinkInfo->DDN_NO<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->IN_MODE:"<<pRspQryNetDelPartyLinkInfo->IN_MODE<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->IP_WAN:"<<pRspQryNetDelPartyLinkInfo->IP_WAN<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->IP_LAN:"<<pRspQryNetDelPartyLinkInfo->IP_LAN<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->IPADDR:"<<pRspQryNetDelPartyLinkInfo->IPADDR<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->Interface:"<<pRspQryNetDelPartyLinkInfo->Interface<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->INTERFACE_DATE:"<<pRspQryNetDelPartyLinkInfo->INTERFACE_DATE<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->SOFTWARE:"<<pRspQryNetDelPartyLinkInfo->SOFTWARE<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->FEE_TYPE:"<<pRspQryNetDelPartyLinkInfo->FEE_TYPE<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->SERVICEPROVIDER:"<<pRspQryNetDelPartyLinkInfo->SERVICEPROVIDER<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->IF_ZIYING:"<<pRspQryNetDelPartyLinkInfo->IF_ZIYING<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->IF_TUOGUAN:"<<pRspQryNetDelPartyLinkInfo->IF_TUOGUAN<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->HASOTHER:"<<pRspQryNetDelPartyLinkInfo->HASOTHER<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->SEAT_NO:"<<pRspQryNetDelPartyLinkInfo->SEAT_NO<< endl;
  cout << "on pRspQryNetDelPartyLinkInfo->PRO:"<<pRspQryNetDelPartyLinkInfo->PRO<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetDelPartyLinkInfoField* pNewRspQryNetDelPartyLinkInfo =new CShfeFtdcRspQryNetDelPartyLinkInfoField;
  memcpy(pNewRspQryNetDelPartyLinkInfo,pRspQryNetDelPartyLinkInfo,sizeof(CShfeFtdcRspQryNetDelPartyLinkInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetDelPartyLinkInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetDelPartyLinkInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetDelPartyLinkInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetDelPartyLinkInfoTopic(CShfeFtdcRtnNetDelPartyLinkInfoField *pRtnNetDelPartyLinkInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->OperationType:"<<pRtnNetDelPartyLinkInfo->OperationType<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->ID:"<<pRtnNetDelPartyLinkInfo->ID<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->MEMBER_NO:"<<pRtnNetDelPartyLinkInfo->MEMBER_NO<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->MEMBER_NAME:"<<pRtnNetDelPartyLinkInfo->MEMBER_NAME<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->REMOTE_ADDR:"<<pRtnNetDelPartyLinkInfo->REMOTE_ADDR<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->LOCAL_ADDR:"<<pRtnNetDelPartyLinkInfo->LOCAL_ADDR<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->ADDRESS:"<<pRtnNetDelPartyLinkInfo->ADDRESS<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->LINE_STATUS:"<<pRtnNetDelPartyLinkInfo->LINE_STATUS<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->CONTACT:"<<pRtnNetDelPartyLinkInfo->CONTACT<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->TELEPHONE:"<<pRtnNetDelPartyLinkInfo->TELEPHONE<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->MOBILEPHONE:"<<pRtnNetDelPartyLinkInfo->MOBILEPHONE<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->EMAIL:"<<pRtnNetDelPartyLinkInfo->EMAIL<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->FAX:"<<pRtnNetDelPartyLinkInfo->FAX<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->PROVINCE:"<<pRtnNetDelPartyLinkInfo->PROVINCE<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->DDN_NO:"<<pRtnNetDelPartyLinkInfo->DDN_NO<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->IN_MODE:"<<pRtnNetDelPartyLinkInfo->IN_MODE<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->IP_WAN:"<<pRtnNetDelPartyLinkInfo->IP_WAN<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->IP_LAN:"<<pRtnNetDelPartyLinkInfo->IP_LAN<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->IPADDR:"<<pRtnNetDelPartyLinkInfo->IPADDR<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->Interface:"<<pRtnNetDelPartyLinkInfo->Interface<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->INTERFACE_DATE:"<<pRtnNetDelPartyLinkInfo->INTERFACE_DATE<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->SOFTWARE:"<<pRtnNetDelPartyLinkInfo->SOFTWARE<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->FEE_TYPE:"<<pRtnNetDelPartyLinkInfo->FEE_TYPE<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->SERVICEPROVIDER:"<<pRtnNetDelPartyLinkInfo->SERVICEPROVIDER<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->IF_ZIYING:"<<pRtnNetDelPartyLinkInfo->IF_ZIYING<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->IF_TUOGUAN:"<<pRtnNetDelPartyLinkInfo->IF_TUOGUAN<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->HASOTHER:"<<pRtnNetDelPartyLinkInfo->HASOTHER<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->SEAT_NO:"<<pRtnNetDelPartyLinkInfo->SEAT_NO<< endl;
  cout << "on pRtnNetDelPartyLinkInfo->PRO:"<<pRtnNetDelPartyLinkInfo->PRO<< endl;
  CShfeFtdcRtnNetDelPartyLinkInfoField* pNewRtnNetDelPartyLinkInfo =new CShfeFtdcRtnNetDelPartyLinkInfoField;
  memcpy(pNewRtnNetDelPartyLinkInfo,pRtnNetDelPartyLinkInfo,sizeof(CShfeFtdcRtnNetDelPartyLinkInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetDelPartyLinkInfo;
  asyncOnRtnNetDelPartyLinkInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetDelPartyLinkInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryPerformanceTopTopic(CShfeFtdcRspQryPerformanceTopField *pRspQryPerformanceTop, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryPerformanceTop->OperationType:"<<pRspQryPerformanceTop->OperationType<< endl;
  cout << "on pRspQryPerformanceTop->AttrType:"<<pRspQryPerformanceTop->AttrType<< endl;
  cout << "on pRspQryPerformanceTop->NetArea:"<<pRspQryPerformanceTop->NetArea<< endl;
  cout << "on pRspQryPerformanceTop->NetSubArea:"<<pRspQryPerformanceTop->NetSubArea<< endl;
  cout << "on pRspQryPerformanceTop->KeyWord:"<<pRspQryPerformanceTop->KeyWord<< endl;
  cout << "on pRspQryPerformanceTop->SortValue:"<<pRspQryPerformanceTop->SortValue<< endl;
  cout << "on pRspQryPerformanceTop->SortType:"<<pRspQryPerformanceTop->SortType<< endl;
  cout << "on pRspQryPerformanceTop->DuringTimeType:"<<pRspQryPerformanceTop->DuringTimeType<< endl;
  cout << "on pRspQryPerformanceTop->DuringTimeValue:"<<pRspQryPerformanceTop->DuringTimeValue<< endl;
  cout << "on pRspQryPerformanceTop->TopN:"<<pRspQryPerformanceTop->TopN<< endl;
  cout << "on pRspQryPerformanceTop->TopResult:"<<pRspQryPerformanceTop->TopResult<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryPerformanceTopField* pNewRspQryPerformanceTop =new CShfeFtdcRspQryPerformanceTopField;
  memcpy(pNewRspQryPerformanceTop,pRspQryPerformanceTop,sizeof(CShfeFtdcRspQryPerformanceTopField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryPerformanceTop;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryPerformanceTopTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryPerformanceTopTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnPerformanceTopTopic(CShfeFtdcRtnPerformanceTopField *pRtnPerformanceTop)
{
  cout << "ok"<< endl;
  cout << "on pRtnPerformanceTop->OperationType:"<<pRtnPerformanceTop->OperationType<< endl;
  cout << "on pRtnPerformanceTop->AttrType:"<<pRtnPerformanceTop->AttrType<< endl;
  cout << "on pRtnPerformanceTop->NetArea:"<<pRtnPerformanceTop->NetArea<< endl;
  cout << "on pRtnPerformanceTop->NetSubArea:"<<pRtnPerformanceTop->NetSubArea<< endl;
  cout << "on pRtnPerformanceTop->KeyWord:"<<pRtnPerformanceTop->KeyWord<< endl;
  cout << "on pRtnPerformanceTop->SortValue:"<<pRtnPerformanceTop->SortValue<< endl;
  cout << "on pRtnPerformanceTop->SortType:"<<pRtnPerformanceTop->SortType<< endl;
  cout << "on pRtnPerformanceTop->DuringTimeType:"<<pRtnPerformanceTop->DuringTimeType<< endl;
  cout << "on pRtnPerformanceTop->DuringTimeValue:"<<pRtnPerformanceTop->DuringTimeValue<< endl;
  cout << "on pRtnPerformanceTop->TopN:"<<pRtnPerformanceTop->TopN<< endl;
  cout << "on pRtnPerformanceTop->TopResult:"<<pRtnPerformanceTop->TopResult<< endl;
  CShfeFtdcRtnPerformanceTopField* pNewRtnPerformanceTop =new CShfeFtdcRtnPerformanceTopField;
  memcpy(pNewRtnPerformanceTop,pRtnPerformanceTop,sizeof(CShfeFtdcRtnPerformanceTopField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnPerformanceTop;
  asyncOnRtnPerformanceTopTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnPerformanceTopTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryInstrumentStatusTopic(CShfeFtdcRspQryInstrumentStatusField *pRspQryInstrumentStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryInstrumentStatus->SettlementGroupID:"<<pRspQryInstrumentStatus->SettlementGroupID<< endl;
  cout << "on pRspQryInstrumentStatus->InstrumentID:"<<pRspQryInstrumentStatus->InstrumentID<< endl;
  cout << "on pRspQryInstrumentStatus->InstrumentStatus:"<<pRspQryInstrumentStatus->InstrumentStatus<< endl;
  cout << "on pRspQryInstrumentStatus->TradingSegmentSN:"<<pRspQryInstrumentStatus->TradingSegmentSN<< endl;
  cout << "on pRspQryInstrumentStatus->EnterTime:"<<pRspQryInstrumentStatus->EnterTime<< endl;
  cout << "on pRspQryInstrumentStatus->EnterReason:"<<pRspQryInstrumentStatus->EnterReason<< endl;
  cout << "on pRspQryInstrumentStatus->EnterDate:"<<pRspQryInstrumentStatus->EnterDate<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryInstrumentStatusField* pNewRspQryInstrumentStatus =new CShfeFtdcRspQryInstrumentStatusField;
  memcpy(pNewRspQryInstrumentStatus,pRspQryInstrumentStatus,sizeof(CShfeFtdcRspQryInstrumentStatusField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryInstrumentStatus;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryInstrumentStatusTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryInstrumentStatusTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnInstrumentStatusTopic(CShfeFtdcRtnInstrumentStatusField *pRtnInstrumentStatus)
{
  cout << "ok"<< endl;
  cout << "on pRtnInstrumentStatus->SettlementGroupID:"<<pRtnInstrumentStatus->SettlementGroupID<< endl;
  cout << "on pRtnInstrumentStatus->InstrumentID:"<<pRtnInstrumentStatus->InstrumentID<< endl;
  cout << "on pRtnInstrumentStatus->InstrumentStatus:"<<pRtnInstrumentStatus->InstrumentStatus<< endl;
  cout << "on pRtnInstrumentStatus->TradingSegmentSN:"<<pRtnInstrumentStatus->TradingSegmentSN<< endl;
  cout << "on pRtnInstrumentStatus->EnterTime:"<<pRtnInstrumentStatus->EnterTime<< endl;
  cout << "on pRtnInstrumentStatus->EnterReason:"<<pRtnInstrumentStatus->EnterReason<< endl;
  cout << "on pRtnInstrumentStatus->EnterDate:"<<pRtnInstrumentStatus->EnterDate<< endl;
  CShfeFtdcRtnInstrumentStatusField* pNewRtnInstrumentStatus =new CShfeFtdcRtnInstrumentStatusField;
  memcpy(pNewRtnInstrumentStatus,pRtnInstrumentStatus,sizeof(CShfeFtdcRtnInstrumentStatusField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnInstrumentStatus;
  asyncOnRtnInstrumentStatusTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnInstrumentStatusTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryCurrTradingSegmentAttrTopic(CShfeFtdcRspQryCurrTradingSegmentAttrField *pRspQryCurrTradingSegmentAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryCurrTradingSegmentAttr->SettlementGroupID:"<<pRspQryCurrTradingSegmentAttr->SettlementGroupID<< endl;
  cout << "on pRspQryCurrTradingSegmentAttr->TradingSegmentSN:"<<pRspQryCurrTradingSegmentAttr->TradingSegmentSN<< endl;
  cout << "on pRspQryCurrTradingSegmentAttr->TradingSegmentName:"<<pRspQryCurrTradingSegmentAttr->TradingSegmentName<< endl;
  cout << "on pRspQryCurrTradingSegmentAttr->StartTime:"<<pRspQryCurrTradingSegmentAttr->StartTime<< endl;
  cout << "on pRspQryCurrTradingSegmentAttr->InstrumentStatus:"<<pRspQryCurrTradingSegmentAttr->InstrumentStatus<< endl;
  cout << "on pRspQryCurrTradingSegmentAttr->InstrumentID:"<<pRspQryCurrTradingSegmentAttr->InstrumentID<< endl;
  cout << "on pRspQryCurrTradingSegmentAttr->AdvanceDays:"<<pRspQryCurrTradingSegmentAttr->AdvanceDays<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryCurrTradingSegmentAttrField* pNewRspQryCurrTradingSegmentAttr =new CShfeFtdcRspQryCurrTradingSegmentAttrField;
  memcpy(pNewRspQryCurrTradingSegmentAttr,pRspQryCurrTradingSegmentAttr,sizeof(CShfeFtdcRspQryCurrTradingSegmentAttrField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryCurrTradingSegmentAttr;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryCurrTradingSegmentAttrTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryCurrTradingSegmentAttrTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnCurrTradingSegmentAttrTopic(CShfeFtdcRtnCurrTradingSegmentAttrField *pRtnCurrTradingSegmentAttr)
{
  cout << "ok"<< endl;
  cout << "on pRtnCurrTradingSegmentAttr->SettlementGroupID:"<<pRtnCurrTradingSegmentAttr->SettlementGroupID<< endl;
  cout << "on pRtnCurrTradingSegmentAttr->TradingSegmentSN:"<<pRtnCurrTradingSegmentAttr->TradingSegmentSN<< endl;
  cout << "on pRtnCurrTradingSegmentAttr->TradingSegmentName:"<<pRtnCurrTradingSegmentAttr->TradingSegmentName<< endl;
  cout << "on pRtnCurrTradingSegmentAttr->StartTime:"<<pRtnCurrTradingSegmentAttr->StartTime<< endl;
  cout << "on pRtnCurrTradingSegmentAttr->InstrumentStatus:"<<pRtnCurrTradingSegmentAttr->InstrumentStatus<< endl;
  cout << "on pRtnCurrTradingSegmentAttr->InstrumentID:"<<pRtnCurrTradingSegmentAttr->InstrumentID<< endl;
  cout << "on pRtnCurrTradingSegmentAttr->AdvanceDays:"<<pRtnCurrTradingSegmentAttr->AdvanceDays<< endl;
  CShfeFtdcRtnCurrTradingSegmentAttrField* pNewRtnCurrTradingSegmentAttr =new CShfeFtdcRtnCurrTradingSegmentAttrField;
  memcpy(pNewRtnCurrTradingSegmentAttr,pRtnCurrTradingSegmentAttr,sizeof(CShfeFtdcRtnCurrTradingSegmentAttrField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnCurrTradingSegmentAttr;
  asyncOnRtnCurrTradingSegmentAttrTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnCurrTradingSegmentAttrTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetAreaTopic(CShfeFtdcRspQryNetAreaField *pRspQryNetArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetArea->OperationType:"<<pRspQryNetArea->OperationType<< endl;
  cout << "on pRspQryNetArea->ID:"<<pRspQryNetArea->ID<< endl;
  cout << "on pRspQryNetArea->CName:"<<pRspQryNetArea->CName<< endl;
  cout << "on pRspQryNetArea->EName:"<<pRspQryNetArea->EName<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetAreaField* pNewRspQryNetArea =new CShfeFtdcRspQryNetAreaField;
  memcpy(pNewRspQryNetArea,pRspQryNetArea,sizeof(CShfeFtdcRspQryNetAreaField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetArea;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetAreaTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetAreaTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetAreaTopic(CShfeFtdcRtnNetAreaField *pRtnNetArea)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetArea->OperationType:"<<pRtnNetArea->OperationType<< endl;
  cout << "on pRtnNetArea->ID:"<<pRtnNetArea->ID<< endl;
  cout << "on pRtnNetArea->CName:"<<pRtnNetArea->CName<< endl;
  cout << "on pRtnNetArea->EName:"<<pRtnNetArea->EName<< endl;
  CShfeFtdcRtnNetAreaField* pNewRtnNetArea =new CShfeFtdcRtnNetAreaField;
  memcpy(pNewRtnNetArea,pRtnNetArea,sizeof(CShfeFtdcRtnNetAreaField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetArea;
  asyncOnRtnNetAreaTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetAreaTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetSubAreaTopic(CShfeFtdcRspQryNetSubAreaField *pRspQryNetSubArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetSubArea->OperationType:"<<pRspQryNetSubArea->OperationType<< endl;
  cout << "on pRspQryNetSubArea->ID:"<<pRspQryNetSubArea->ID<< endl;
  cout << "on pRspQryNetSubArea->SysNetAreaID:"<<pRspQryNetSubArea->SysNetAreaID<< endl;
  cout << "on pRspQryNetSubArea->CName:"<<pRspQryNetSubArea->CName<< endl;
  cout << "on pRspQryNetSubArea->EName:"<<pRspQryNetSubArea->EName<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetSubAreaField* pNewRspQryNetSubArea =new CShfeFtdcRspQryNetSubAreaField;
  memcpy(pNewRspQryNetSubArea,pRspQryNetSubArea,sizeof(CShfeFtdcRspQryNetSubAreaField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetSubArea;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetSubAreaTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetSubAreaTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetSubAreaTopic(CShfeFtdcRtnNetSubAreaField *pRtnNetSubArea)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetSubArea->OperationType:"<<pRtnNetSubArea->OperationType<< endl;
  cout << "on pRtnNetSubArea->ID:"<<pRtnNetSubArea->ID<< endl;
  cout << "on pRtnNetSubArea->SysNetAreaID:"<<pRtnNetSubArea->SysNetAreaID<< endl;
  cout << "on pRtnNetSubArea->CName:"<<pRtnNetSubArea->CName<< endl;
  cout << "on pRtnNetSubArea->EName:"<<pRtnNetSubArea->EName<< endl;
  CShfeFtdcRtnNetSubAreaField* pNewRtnNetSubArea =new CShfeFtdcRtnNetSubAreaField;
  memcpy(pNewRtnNetSubArea,pRtnNetSubArea,sizeof(CShfeFtdcRtnNetSubAreaField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetSubArea;
  asyncOnRtnNetSubAreaTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetSubAreaTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetSubAreaIPTopic(CShfeFtdcRspQryNetSubAreaIPField *pRspQryNetSubAreaIP, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetSubAreaIP->OperationType:"<<pRspQryNetSubAreaIP->OperationType<< endl;
  cout << "on pRspQryNetSubAreaIP->ID:"<<pRspQryNetSubAreaIP->ID<< endl;
  cout << "on pRspQryNetSubAreaIP->SysNetSubAreaID:"<<pRspQryNetSubAreaIP->SysNetSubAreaID<< endl;
  cout << "on pRspQryNetSubAreaIP->IP:"<<pRspQryNetSubAreaIP->IP<< endl;
  cout << "on pRspQryNetSubAreaIP->Mask:"<<pRspQryNetSubAreaIP->Mask<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetSubAreaIPField* pNewRspQryNetSubAreaIP =new CShfeFtdcRspQryNetSubAreaIPField;
  memcpy(pNewRspQryNetSubAreaIP,pRspQryNetSubAreaIP,sizeof(CShfeFtdcRspQryNetSubAreaIPField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetSubAreaIP;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetSubAreaIPTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetSubAreaIPTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetSubAreaIPTopic(CShfeFtdcRtnNetSubAreaIPField *pRtnNetSubAreaIP)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetSubAreaIP->OperationType:"<<pRtnNetSubAreaIP->OperationType<< endl;
  cout << "on pRtnNetSubAreaIP->ID:"<<pRtnNetSubAreaIP->ID<< endl;
  cout << "on pRtnNetSubAreaIP->SysNetSubAreaID:"<<pRtnNetSubAreaIP->SysNetSubAreaID<< endl;
  cout << "on pRtnNetSubAreaIP->IP:"<<pRtnNetSubAreaIP->IP<< endl;
  cout << "on pRtnNetSubAreaIP->Mask:"<<pRtnNetSubAreaIP->Mask<< endl;
  CShfeFtdcRtnNetSubAreaIPField* pNewRtnNetSubAreaIP =new CShfeFtdcRtnNetSubAreaIPField;
  memcpy(pNewRtnNetSubAreaIP,pRtnNetSubAreaIP,sizeof(CShfeFtdcRtnNetSubAreaIPField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetSubAreaIP;
  asyncOnRtnNetSubAreaIPTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetSubAreaIPTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetDeviceTopic(CShfeFtdcRspQryNetDeviceField *pRspQryNetDevice, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetDevice->OperationType:"<<pRspQryNetDevice->OperationType<< endl;
  cout << "on pRspQryNetDevice->ID:"<<pRspQryNetDevice->ID<< endl;
  cout << "on pRspQryNetDevice->ObjectID:"<<pRspQryNetDevice->ObjectID<< endl;
  cout << "on pRspQryNetDevice->MonitorType_ID:"<<pRspQryNetDevice->MonitorType_ID<< endl;
  cout << "on pRspQryNetDevice->SysNetSubAreaID:"<<pRspQryNetDevice->SysNetSubAreaID<< endl;
  cout << "on pRspQryNetDevice->CATEGORY_ID:"<<pRspQryNetDevice->CATEGORY_ID<< endl;
  cout << "on pRspQryNetDevice->FuctionArea:"<<pRspQryNetDevice->FuctionArea<< endl;
  cout << "on pRspQryNetDevice->IPADDR:"<<pRspQryNetDevice->IPADDR<< endl;
  cout << "on pRspQryNetDevice->IPDECODE:"<<pRspQryNetDevice->IPDECODE<< endl;
  cout << "on pRspQryNetDevice->NAME:"<<pRspQryNetDevice->NAME<< endl;
  cout << "on pRspQryNetDevice->PORTNUMBER:"<<pRspQryNetDevice->PORTNUMBER<< endl;
  cout << "on pRspQryNetDevice->CONFIGFILE:"<<pRspQryNetDevice->CONFIGFILE<< endl;
  cout << "on pRspQryNetDevice->RCOMMUNITY:"<<pRspQryNetDevice->RCOMMUNITY<< endl;
  cout << "on pRspQryNetDevice->SNMPVERSION:"<<pRspQryNetDevice->SNMPVERSION<< endl;
  cout << "on pRspQryNetDevice->RAMSIZE:"<<pRspQryNetDevice->RAMSIZE<< endl;
  cout << "on pRspQryNetDevice->FLASHSIZE:"<<pRspQryNetDevice->FLASHSIZE<< endl;
  cout << "on pRspQryNetDevice->NVRAMSIZE:"<<pRspQryNetDevice->NVRAMSIZE<< endl;
  cout << "on pRspQryNetDevice->CABINET_ID:"<<pRspQryNetDevice->CABINET_ID<< endl;
  cout << "on pRspQryNetDevice->ROOM_ID:"<<pRspQryNetDevice->ROOM_ID<< endl;
  cout << "on pRspQryNetDevice->IOSVERSION_ID:"<<pRspQryNetDevice->IOSVERSION_ID<< endl;
  cout << "on pRspQryNetDevice->DESCRIPTION:"<<pRspQryNetDevice->DESCRIPTION<< endl;
  cout << "on pRspQryNetDevice->USERNAME:"<<pRspQryNetDevice->USERNAME<< endl;
  cout << "on pRspQryNetDevice->PASSWD:"<<pRspQryNetDevice->PASSWD<< endl;
  cout << "on pRspQryNetDevice->ENPASSWD:"<<pRspQryNetDevice->ENPASSWD<< endl;
  cout << "on pRspQryNetDevice->MANUFACTORY_ID:"<<pRspQryNetDevice->MANUFACTORY_ID<< endl;
  cout << "on pRspQryNetDevice->CFGSAVETYPE:"<<pRspQryNetDevice->CFGSAVETYPE<< endl;
  cout << "on pRspQryNetDevice->DEVICETYPE:"<<pRspQryNetDevice->DEVICETYPE<< endl;
  cout << "on pRspQryNetDevice->SENDSMS:"<<pRspQryNetDevice->SENDSMS<< endl;
  cout << "on pRspQryNetDevice->ISSNMP:"<<pRspQryNetDevice->ISSNMP<< endl;
  cout << "on pRspQryNetDevice->SLOTNUM:"<<pRspQryNetDevice->SLOTNUM<< endl;
  cout << "on pRspQryNetDevice->ISPING:"<<pRspQryNetDevice->ISPING<< endl;
  cout << "on pRspQryNetDevice->IFNUM:"<<pRspQryNetDevice->IFNUM<< endl;
  cout << "on pRspQryNetDevice->APPLICATION_ID:"<<pRspQryNetDevice->APPLICATION_ID<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetDeviceField* pNewRspQryNetDevice =new CShfeFtdcRspQryNetDeviceField;
  memcpy(pNewRspQryNetDevice,pRspQryNetDevice,sizeof(CShfeFtdcRspQryNetDeviceField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetDevice;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetDeviceTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetDeviceTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetDeviceTopic(CShfeFtdcRtnNetDeviceField *pRtnNetDevice)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetDevice->OperationType:"<<pRtnNetDevice->OperationType<< endl;
  cout << "on pRtnNetDevice->ID:"<<pRtnNetDevice->ID<< endl;
  cout << "on pRtnNetDevice->ObjectID:"<<pRtnNetDevice->ObjectID<< endl;
  cout << "on pRtnNetDevice->MonitorType_ID:"<<pRtnNetDevice->MonitorType_ID<< endl;
  cout << "on pRtnNetDevice->SysNetSubAreaID:"<<pRtnNetDevice->SysNetSubAreaID<< endl;
  cout << "on pRtnNetDevice->CATEGORY_ID:"<<pRtnNetDevice->CATEGORY_ID<< endl;
  cout << "on pRtnNetDevice->FuctionArea:"<<pRtnNetDevice->FuctionArea<< endl;
  cout << "on pRtnNetDevice->IPADDR:"<<pRtnNetDevice->IPADDR<< endl;
  cout << "on pRtnNetDevice->IPDECODE:"<<pRtnNetDevice->IPDECODE<< endl;
  cout << "on pRtnNetDevice->NAME:"<<pRtnNetDevice->NAME<< endl;
  cout << "on pRtnNetDevice->PORTNUMBER:"<<pRtnNetDevice->PORTNUMBER<< endl;
  cout << "on pRtnNetDevice->CONFIGFILE:"<<pRtnNetDevice->CONFIGFILE<< endl;
  cout << "on pRtnNetDevice->RCOMMUNITY:"<<pRtnNetDevice->RCOMMUNITY<< endl;
  cout << "on pRtnNetDevice->SNMPVERSION:"<<pRtnNetDevice->SNMPVERSION<< endl;
  cout << "on pRtnNetDevice->RAMSIZE:"<<pRtnNetDevice->RAMSIZE<< endl;
  cout << "on pRtnNetDevice->FLASHSIZE:"<<pRtnNetDevice->FLASHSIZE<< endl;
  cout << "on pRtnNetDevice->NVRAMSIZE:"<<pRtnNetDevice->NVRAMSIZE<< endl;
  cout << "on pRtnNetDevice->CABINET_ID:"<<pRtnNetDevice->CABINET_ID<< endl;
  cout << "on pRtnNetDevice->ROOM_ID:"<<pRtnNetDevice->ROOM_ID<< endl;
  cout << "on pRtnNetDevice->IOSVERSION_ID:"<<pRtnNetDevice->IOSVERSION_ID<< endl;
  cout << "on pRtnNetDevice->DESCRIPTION:"<<pRtnNetDevice->DESCRIPTION<< endl;
  cout << "on pRtnNetDevice->USERNAME:"<<pRtnNetDevice->USERNAME<< endl;
  cout << "on pRtnNetDevice->PASSWD:"<<pRtnNetDevice->PASSWD<< endl;
  cout << "on pRtnNetDevice->ENPASSWD:"<<pRtnNetDevice->ENPASSWD<< endl;
  cout << "on pRtnNetDevice->MANUFACTORY_ID:"<<pRtnNetDevice->MANUFACTORY_ID<< endl;
  cout << "on pRtnNetDevice->CFGSAVETYPE:"<<pRtnNetDevice->CFGSAVETYPE<< endl;
  cout << "on pRtnNetDevice->DEVICETYPE:"<<pRtnNetDevice->DEVICETYPE<< endl;
  cout << "on pRtnNetDevice->SENDSMS:"<<pRtnNetDevice->SENDSMS<< endl;
  cout << "on pRtnNetDevice->ISSNMP:"<<pRtnNetDevice->ISSNMP<< endl;
  cout << "on pRtnNetDevice->SLOTNUM:"<<pRtnNetDevice->SLOTNUM<< endl;
  cout << "on pRtnNetDevice->ISPING:"<<pRtnNetDevice->ISPING<< endl;
  cout << "on pRtnNetDevice->IFNUM:"<<pRtnNetDevice->IFNUM<< endl;
  cout << "on pRtnNetDevice->APPLICATION_ID:"<<pRtnNetDevice->APPLICATION_ID<< endl;
  CShfeFtdcRtnNetDeviceField* pNewRtnNetDevice =new CShfeFtdcRtnNetDeviceField;
  memcpy(pNewRtnNetDevice,pRtnNetDevice,sizeof(CShfeFtdcRtnNetDeviceField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetDevice;
  asyncOnRtnNetDeviceTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetDeviceTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetDeviceDetectTopic(CShfeFtdcRspQryNetDeviceDetectField *pRspQryNetDeviceDetect, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetDeviceDetect->SysNetAreaID:"<<pRspQryNetDeviceDetect->SysNetAreaID<< endl;
  cout << "on pRspQryNetDeviceDetect->SysNetSubAreaID:"<<pRspQryNetDeviceDetect->SysNetSubAreaID<< endl;
  cout << "on pRspQryNetDeviceDetect->IP:"<<pRspQryNetDeviceDetect->IP<< endl;
  cout << "on pRspQryNetDeviceDetect->Mask:"<<pRspQryNetDeviceDetect->Mask<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetDeviceDetectField* pNewRspQryNetDeviceDetect =new CShfeFtdcRspQryNetDeviceDetectField;
  memcpy(pNewRspQryNetDeviceDetect,pRspQryNetDeviceDetect,sizeof(CShfeFtdcRspQryNetDeviceDetectField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetDeviceDetect;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetDeviceDetectTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetDeviceDetectTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetBuildingTopic(CShfeFtdcRspQryNetBuildingField *pRspQryNetBuilding, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetBuilding->OperationType:"<<pRspQryNetBuilding->OperationType<< endl;
  cout << "on pRspQryNetBuilding->ID:"<<pRspQryNetBuilding->ID<< endl;
  cout << "on pRspQryNetBuilding->CName:"<<pRspQryNetBuilding->CName<< endl;
  cout << "on pRspQryNetBuilding->EName:"<<pRspQryNetBuilding->EName<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetBuildingField* pNewRspQryNetBuilding =new CShfeFtdcRspQryNetBuildingField;
  memcpy(pNewRspQryNetBuilding,pRspQryNetBuilding,sizeof(CShfeFtdcRspQryNetBuildingField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetBuilding;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetBuildingTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetBuildingTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetBuildingTopic(CShfeFtdcRtnNetBuildingField *pRtnNetBuilding)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetBuilding->OperationType:"<<pRtnNetBuilding->OperationType<< endl;
  cout << "on pRtnNetBuilding->ID:"<<pRtnNetBuilding->ID<< endl;
  cout << "on pRtnNetBuilding->CName:"<<pRtnNetBuilding->CName<< endl;
  cout << "on pRtnNetBuilding->EName:"<<pRtnNetBuilding->EName<< endl;
  CShfeFtdcRtnNetBuildingField* pNewRtnNetBuilding =new CShfeFtdcRtnNetBuildingField;
  memcpy(pNewRtnNetBuilding,pRtnNetBuilding,sizeof(CShfeFtdcRtnNetBuildingField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetBuilding;
  asyncOnRtnNetBuildingTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetBuildingTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetRoomTopic(CShfeFtdcRspQryNetRoomField *pRspQryNetRoom, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetRoom->OperationType:"<<pRspQryNetRoom->OperationType<< endl;
  cout << "on pRspQryNetRoom->ID:"<<pRspQryNetRoom->ID<< endl;
  cout << "on pRspQryNetRoom->SysNetBuildingID:"<<pRspQryNetRoom->SysNetBuildingID<< endl;
  cout << "on pRspQryNetRoom->CName:"<<pRspQryNetRoom->CName<< endl;
  cout << "on pRspQryNetRoom->EName:"<<pRspQryNetRoom->EName<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetRoomField* pNewRspQryNetRoom =new CShfeFtdcRspQryNetRoomField;
  memcpy(pNewRspQryNetRoom,pRspQryNetRoom,sizeof(CShfeFtdcRspQryNetRoomField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetRoom;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetRoomTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetRoomTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetRoomTopic(CShfeFtdcRtnNetRoomField *pRtnNetRoom)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetRoom->OperationType:"<<pRtnNetRoom->OperationType<< endl;
  cout << "on pRtnNetRoom->ID:"<<pRtnNetRoom->ID<< endl;
  cout << "on pRtnNetRoom->SysNetBuildingID:"<<pRtnNetRoom->SysNetBuildingID<< endl;
  cout << "on pRtnNetRoom->CName:"<<pRtnNetRoom->CName<< endl;
  cout << "on pRtnNetRoom->EName:"<<pRtnNetRoom->EName<< endl;
  CShfeFtdcRtnNetRoomField* pNewRtnNetRoom =new CShfeFtdcRtnNetRoomField;
  memcpy(pNewRtnNetRoom,pRtnNetRoom,sizeof(CShfeFtdcRtnNetRoomField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetRoom;
  asyncOnRtnNetRoomTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetRoomTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetCabinetsTopic(CShfeFtdcRspQryNetCabinetsField *pRspQryNetCabinets, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetCabinets->OperationType:"<<pRspQryNetCabinets->OperationType<< endl;
  cout << "on pRspQryNetCabinets->ID:"<<pRspQryNetCabinets->ID<< endl;
  cout << "on pRspQryNetCabinets->SysNetRoomID:"<<pRspQryNetCabinets->SysNetRoomID<< endl;
  cout << "on pRspQryNetCabinets->SysNetBuildingID:"<<pRspQryNetCabinets->SysNetBuildingID<< endl;
  cout << "on pRspQryNetCabinets->CName:"<<pRspQryNetCabinets->CName<< endl;
  cout << "on pRspQryNetCabinets->EName:"<<pRspQryNetCabinets->EName<< endl;
  cout << "on pRspQryNetCabinets->CabinetsType:"<<pRspQryNetCabinets->CabinetsType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetCabinetsField* pNewRspQryNetCabinets =new CShfeFtdcRspQryNetCabinetsField;
  memcpy(pNewRspQryNetCabinets,pRspQryNetCabinets,sizeof(CShfeFtdcRspQryNetCabinetsField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetCabinets;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetCabinetsTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetCabinetsTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetCabinetsTopic(CShfeFtdcRtnNetCabinetsField *pRtnNetCabinets)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetCabinets->OperationType:"<<pRtnNetCabinets->OperationType<< endl;
  cout << "on pRtnNetCabinets->ID:"<<pRtnNetCabinets->ID<< endl;
  cout << "on pRtnNetCabinets->SysNetRoomID:"<<pRtnNetCabinets->SysNetRoomID<< endl;
  cout << "on pRtnNetCabinets->SysNetBuildingID:"<<pRtnNetCabinets->SysNetBuildingID<< endl;
  cout << "on pRtnNetCabinets->CName:"<<pRtnNetCabinets->CName<< endl;
  cout << "on pRtnNetCabinets->EName:"<<pRtnNetCabinets->EName<< endl;
  cout << "on pRtnNetCabinets->CabinetsType:"<<pRtnNetCabinets->CabinetsType<< endl;
  CShfeFtdcRtnNetCabinetsField* pNewRtnNetCabinets =new CShfeFtdcRtnNetCabinetsField;
  memcpy(pNewRtnNetCabinets,pRtnNetCabinets,sizeof(CShfeFtdcRtnNetCabinetsField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetCabinets;
  asyncOnRtnNetCabinetsTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetCabinetsTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetOIDTopic(CShfeFtdcRspQryNetOIDField *pRspQryNetOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetOID->OperationType:"<<pRspQryNetOID->OperationType<< endl;
  cout << "on pRspQryNetOID->ID:"<<pRspQryNetOID->ID<< endl;
  cout << "on pRspQryNetOID->Manufactory:"<<pRspQryNetOID->Manufactory<< endl;
  cout << "on pRspQryNetOID->DeviceType:"<<pRspQryNetOID->DeviceType<< endl;
  cout << "on pRspQryNetOID->CName:"<<pRspQryNetOID->CName<< endl;
  cout << "on pRspQryNetOID->EName:"<<pRspQryNetOID->EName<< endl;
  cout << "on pRspQryNetOID->OID:"<<pRspQryNetOID->OID<< endl;
  cout << "on pRspQryNetOID->Unit:"<<pRspQryNetOID->Unit<< endl;
  cout << "on pRspQryNetOID->isTheTable:"<<pRspQryNetOID->isTheTable<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetOIDField* pNewRspQryNetOID =new CShfeFtdcRspQryNetOIDField;
  memcpy(pNewRspQryNetOID,pRspQryNetOID,sizeof(CShfeFtdcRspQryNetOIDField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetOID;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetOIDTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetOIDTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetOIDTopic(CShfeFtdcRtnNetOIDField *pRtnNetOID)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetOID->OperationType:"<<pRtnNetOID->OperationType<< endl;
  cout << "on pRtnNetOID->ID:"<<pRtnNetOID->ID<< endl;
  cout << "on pRtnNetOID->Manufactory:"<<pRtnNetOID->Manufactory<< endl;
  cout << "on pRtnNetOID->DeviceType:"<<pRtnNetOID->DeviceType<< endl;
  cout << "on pRtnNetOID->CName:"<<pRtnNetOID->CName<< endl;
  cout << "on pRtnNetOID->EName:"<<pRtnNetOID->EName<< endl;
  cout << "on pRtnNetOID->OID:"<<pRtnNetOID->OID<< endl;
  cout << "on pRtnNetOID->Unit:"<<pRtnNetOID->Unit<< endl;
  cout << "on pRtnNetOID->isTheTable:"<<pRtnNetOID->isTheTable<< endl;
  CShfeFtdcRtnNetOIDField* pNewRtnNetOID =new CShfeFtdcRtnNetOIDField;
  memcpy(pNewRtnNetOID,pRtnNetOID,sizeof(CShfeFtdcRtnNetOIDField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetOID;
  asyncOnRtnNetOIDTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetOIDTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetTimePolicyTopic(CShfeFtdcRspQryNetTimePolicyField *pRspQryNetTimePolicy, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetTimePolicy->OperationType:"<<pRspQryNetTimePolicy->OperationType<< endl;
  cout << "on pRspQryNetTimePolicy->ID:"<<pRspQryNetTimePolicy->ID<< endl;
  cout << "on pRspQryNetTimePolicy->CName:"<<pRspQryNetTimePolicy->CName<< endl;
  cout << "on pRspQryNetTimePolicy->EName:"<<pRspQryNetTimePolicy->EName<< endl;
  cout << "on pRspQryNetTimePolicy->PolicyType:"<<pRspQryNetTimePolicy->PolicyType<< endl;
  cout << "on pRspQryNetTimePolicy->PolicyString:"<<pRspQryNetTimePolicy->PolicyString<< endl;
  cout << "on pRspQryNetTimePolicy->TradingDay:"<<pRspQryNetTimePolicy->TradingDay<< endl;
  cout << "on pRspQryNetTimePolicy->Description:"<<pRspQryNetTimePolicy->Description<< endl;
  cout << "on pRspQryNetTimePolicy->Operation:"<<pRspQryNetTimePolicy->Operation<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetTimePolicyField* pNewRspQryNetTimePolicy =new CShfeFtdcRspQryNetTimePolicyField;
  memcpy(pNewRspQryNetTimePolicy,pRspQryNetTimePolicy,sizeof(CShfeFtdcRspQryNetTimePolicyField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetTimePolicy;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetTimePolicyTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetTimePolicyTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetTimePolicyTopic(CShfeFtdcRtnNetTimePolicyField *pRtnNetTimePolicy)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetTimePolicy->OperationType:"<<pRtnNetTimePolicy->OperationType<< endl;
  cout << "on pRtnNetTimePolicy->ID:"<<pRtnNetTimePolicy->ID<< endl;
  cout << "on pRtnNetTimePolicy->CName:"<<pRtnNetTimePolicy->CName<< endl;
  cout << "on pRtnNetTimePolicy->EName:"<<pRtnNetTimePolicy->EName<< endl;
  cout << "on pRtnNetTimePolicy->PolicyType:"<<pRtnNetTimePolicy->PolicyType<< endl;
  cout << "on pRtnNetTimePolicy->PolicyString:"<<pRtnNetTimePolicy->PolicyString<< endl;
  cout << "on pRtnNetTimePolicy->TradingDay:"<<pRtnNetTimePolicy->TradingDay<< endl;
  cout << "on pRtnNetTimePolicy->Description:"<<pRtnNetTimePolicy->Description<< endl;
  cout << "on pRtnNetTimePolicy->Operation:"<<pRtnNetTimePolicy->Operation<< endl;
  CShfeFtdcRtnNetTimePolicyField* pNewRtnNetTimePolicy =new CShfeFtdcRtnNetTimePolicyField;
  memcpy(pNewRtnNetTimePolicy,pRtnNetTimePolicy,sizeof(CShfeFtdcRtnNetTimePolicyField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetTimePolicy;
  asyncOnRtnNetTimePolicyTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetTimePolicyTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetGatherTaskTopic(CShfeFtdcRspQryNetGatherTaskField *pRspQryNetGatherTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetGatherTask->OperationType:"<<pRspQryNetGatherTask->OperationType<< endl;
  cout << "on pRspQryNetGatherTask->ID:"<<pRspQryNetGatherTask->ID<< endl;
  cout << "on pRspQryNetGatherTask->ObjectID:"<<pRspQryNetGatherTask->ObjectID<< endl;
  cout << "on pRspQryNetGatherTask->AttrType:"<<pRspQryNetGatherTask->AttrType<< endl;
  cout << "on pRspQryNetGatherTask->PolicyTypeID:"<<pRspQryNetGatherTask->PolicyTypeID<< endl;
  cout << "on pRspQryNetGatherTask->DataType:"<<pRspQryNetGatherTask->DataType<< endl;
  cout << "on pRspQryNetGatherTask->TypeFlag:"<<pRspQryNetGatherTask->TypeFlag<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetGatherTaskField* pNewRspQryNetGatherTask =new CShfeFtdcRspQryNetGatherTaskField;
  memcpy(pNewRspQryNetGatherTask,pRspQryNetGatherTask,sizeof(CShfeFtdcRspQryNetGatherTaskField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetGatherTask;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetGatherTaskTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetGatherTaskTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetGatherTaskTopic(CShfeFtdcRtnNetGatherTaskField *pRtnNetGatherTask)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetGatherTask->OperationType:"<<pRtnNetGatherTask->OperationType<< endl;
  cout << "on pRtnNetGatherTask->ID:"<<pRtnNetGatherTask->ID<< endl;
  cout << "on pRtnNetGatherTask->ObjectID:"<<pRtnNetGatherTask->ObjectID<< endl;
  cout << "on pRtnNetGatherTask->AttrType:"<<pRtnNetGatherTask->AttrType<< endl;
  cout << "on pRtnNetGatherTask->PolicyTypeID:"<<pRtnNetGatherTask->PolicyTypeID<< endl;
  cout << "on pRtnNetGatherTask->DataType:"<<pRtnNetGatherTask->DataType<< endl;
  cout << "on pRtnNetGatherTask->TypeFlag:"<<pRtnNetGatherTask->TypeFlag<< endl;
  CShfeFtdcRtnNetGatherTaskField* pNewRtnNetGatherTask =new CShfeFtdcRtnNetGatherTaskField;
  memcpy(pNewRtnNetGatherTask,pRtnNetGatherTask,sizeof(CShfeFtdcRtnNetGatherTaskField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetGatherTask;
  asyncOnRtnNetGatherTaskTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetGatherTaskTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetDeviceChgTopic(CShfeFtdcRspQryNetDeviceChgField *pRspQryNetDeviceChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetDeviceChg->DeviceID:"<<pRspQryNetDeviceChg->DeviceID<< endl;
  cout << "on pRspQryNetDeviceChg->SysNetSubAreaID:"<<pRspQryNetDeviceChg->SysNetSubAreaID<< endl;
  cout << "on pRspQryNetDeviceChg->OldObjectID:"<<pRspQryNetDeviceChg->OldObjectID<< endl;
  cout << "on pRspQryNetDeviceChg->NewObjectID:"<<pRspQryNetDeviceChg->NewObjectID<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetDeviceChgField* pNewRspQryNetDeviceChg =new CShfeFtdcRspQryNetDeviceChgField;
  memcpy(pNewRspQryNetDeviceChg,pRspQryNetDeviceChg,sizeof(CShfeFtdcRspQryNetDeviceChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetDeviceChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetDeviceChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetDeviceChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetDeviceChgTopic(CShfeFtdcRtnNetDeviceChgField *pRtnNetDeviceChg)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetDeviceChg->DeviceID:"<<pRtnNetDeviceChg->DeviceID<< endl;
  cout << "on pRtnNetDeviceChg->SysNetSubAreaID:"<<pRtnNetDeviceChg->SysNetSubAreaID<< endl;
  cout << "on pRtnNetDeviceChg->OldObjectID:"<<pRtnNetDeviceChg->OldObjectID<< endl;
  cout << "on pRtnNetDeviceChg->NewObjectID:"<<pRtnNetDeviceChg->NewObjectID<< endl;
  CShfeFtdcRtnNetDeviceChgField* pNewRtnNetDeviceChg =new CShfeFtdcRtnNetDeviceChgField;
  memcpy(pNewRtnNetDeviceChg,pRtnNetDeviceChg,sizeof(CShfeFtdcRtnNetDeviceChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetDeviceChg;
  asyncOnRtnNetDeviceChgTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetDeviceChgTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetDeviceTypeTopic(CShfeFtdcRspQryNetDeviceTypeField *pRspQryNetDeviceType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetDeviceType->OperationType:"<<pRspQryNetDeviceType->OperationType<< endl;
  cout << "on pRspQryNetDeviceType->ID:"<<pRspQryNetDeviceType->ID<< endl;
  cout << "on pRspQryNetDeviceType->Manufactory:"<<pRspQryNetDeviceType->Manufactory<< endl;
  cout << "on pRspQryNetDeviceType->DeviceType:"<<pRspQryNetDeviceType->DeviceType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetDeviceTypeField* pNewRspQryNetDeviceType =new CShfeFtdcRspQryNetDeviceTypeField;
  memcpy(pNewRspQryNetDeviceType,pRspQryNetDeviceType,sizeof(CShfeFtdcRspQryNetDeviceTypeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetDeviceType;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetDeviceTypeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetDeviceTypeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetDeviceTypeTopic(CShfeFtdcRtnNetDeviceTypeField *pRtnNetDeviceType)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetDeviceType->OperationType:"<<pRtnNetDeviceType->OperationType<< endl;
  cout << "on pRtnNetDeviceType->ID:"<<pRtnNetDeviceType->ID<< endl;
  cout << "on pRtnNetDeviceType->Manufactory:"<<pRtnNetDeviceType->Manufactory<< endl;
  cout << "on pRtnNetDeviceType->DeviceType:"<<pRtnNetDeviceType->DeviceType<< endl;
  CShfeFtdcRtnNetDeviceTypeField* pNewRtnNetDeviceType =new CShfeFtdcRtnNetDeviceTypeField;
  memcpy(pNewRtnNetDeviceType,pRtnNetDeviceType,sizeof(CShfeFtdcRtnNetDeviceTypeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetDeviceType;
  asyncOnRtnNetDeviceTypeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetDeviceTypeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetDeviceCategoryTopic(CShfeFtdcRspQryNetDeviceCategoryField *pRspQryNetDeviceCategory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetDeviceCategory->OperationType:"<<pRspQryNetDeviceCategory->OperationType<< endl;
  cout << "on pRspQryNetDeviceCategory->ID:"<<pRspQryNetDeviceCategory->ID<< endl;
  cout << "on pRspQryNetDeviceCategory->CName:"<<pRspQryNetDeviceCategory->CName<< endl;
  cout << "on pRspQryNetDeviceCategory->EName:"<<pRspQryNetDeviceCategory->EName<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetDeviceCategoryField* pNewRspQryNetDeviceCategory =new CShfeFtdcRspQryNetDeviceCategoryField;
  memcpy(pNewRspQryNetDeviceCategory,pRspQryNetDeviceCategory,sizeof(CShfeFtdcRspQryNetDeviceCategoryField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetDeviceCategory;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetDeviceCategoryTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetDeviceCategoryTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetDeviceCategoryTopic(CShfeFtdcRtnNetDeviceCategoryField *pRtnNetDeviceCategory)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetDeviceCategory->OperationType:"<<pRtnNetDeviceCategory->OperationType<< endl;
  cout << "on pRtnNetDeviceCategory->ID:"<<pRtnNetDeviceCategory->ID<< endl;
  cout << "on pRtnNetDeviceCategory->CName:"<<pRtnNetDeviceCategory->CName<< endl;
  cout << "on pRtnNetDeviceCategory->EName:"<<pRtnNetDeviceCategory->EName<< endl;
  CShfeFtdcRtnNetDeviceCategoryField* pNewRtnNetDeviceCategory =new CShfeFtdcRtnNetDeviceCategoryField;
  memcpy(pNewRtnNetDeviceCategory,pRtnNetDeviceCategory,sizeof(CShfeFtdcRtnNetDeviceCategoryField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetDeviceCategory;
  asyncOnRtnNetDeviceCategoryTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetDeviceCategoryTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetManufactoryTopic(CShfeFtdcRspQryNetManufactoryField *pRspQryNetManufactory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetManufactory->OperationType:"<<pRspQryNetManufactory->OperationType<< endl;
  cout << "on pRspQryNetManufactory->ID:"<<pRspQryNetManufactory->ID<< endl;
  cout << "on pRspQryNetManufactory->CName:"<<pRspQryNetManufactory->CName<< endl;
  cout << "on pRspQryNetManufactory->EName:"<<pRspQryNetManufactory->EName<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetManufactoryField* pNewRspQryNetManufactory =new CShfeFtdcRspQryNetManufactoryField;
  memcpy(pNewRspQryNetManufactory,pRspQryNetManufactory,sizeof(CShfeFtdcRspQryNetManufactoryField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetManufactory;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetManufactoryTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetManufactoryTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetManufactoryTopic(CShfeFtdcRtnNetManufactoryField *pRtnNetManufactory)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetManufactory->OperationType:"<<pRtnNetManufactory->OperationType<< endl;
  cout << "on pRtnNetManufactory->ID:"<<pRtnNetManufactory->ID<< endl;
  cout << "on pRtnNetManufactory->CName:"<<pRtnNetManufactory->CName<< endl;
  cout << "on pRtnNetManufactory->EName:"<<pRtnNetManufactory->EName<< endl;
  CShfeFtdcRtnNetManufactoryField* pNewRtnNetManufactory =new CShfeFtdcRtnNetManufactoryField;
  memcpy(pNewRtnNetManufactory,pRtnNetManufactory,sizeof(CShfeFtdcRtnNetManufactoryField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetManufactory;
  asyncOnRtnNetManufactoryTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetManufactoryTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetCommunityTopic(CShfeFtdcRspQryNetCommunityField *pRspQryNetCommunity, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetCommunity->OperationType:"<<pRspQryNetCommunity->OperationType<< endl;
  cout << "on pRspQryNetCommunity->ID:"<<pRspQryNetCommunity->ID<< endl;
  cout << "on pRspQryNetCommunity->IPADDR:"<<pRspQryNetCommunity->IPADDR<< endl;
  cout << "on pRspQryNetCommunity->COMMUNITY:"<<pRspQryNetCommunity->COMMUNITY<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetCommunityField* pNewRspQryNetCommunity =new CShfeFtdcRspQryNetCommunityField;
  memcpy(pNewRspQryNetCommunity,pRspQryNetCommunity,sizeof(CShfeFtdcRspQryNetCommunityField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetCommunity;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetCommunityTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetCommunityTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetCommunityTopic(CShfeFtdcRtnNetCommunityField *pRtnNetCommunity)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetCommunity->OperationType:"<<pRtnNetCommunity->OperationType<< endl;
  cout << "on pRtnNetCommunity->ID:"<<pRtnNetCommunity->ID<< endl;
  cout << "on pRtnNetCommunity->IPADDR:"<<pRtnNetCommunity->IPADDR<< endl;
  cout << "on pRtnNetCommunity->COMMUNITY:"<<pRtnNetCommunity->COMMUNITY<< endl;
  CShfeFtdcRtnNetCommunityField* pNewRtnNetCommunity =new CShfeFtdcRtnNetCommunityField;
  memcpy(pNewRtnNetCommunity,pRtnNetCommunity,sizeof(CShfeFtdcRtnNetCommunityField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetCommunity;
  asyncOnRtnNetCommunityTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetCommunityTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetPortTypeTopic(CShfeFtdcRspQryNetPortTypeField *pRspQryNetPortType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetPortType->OperationType:"<<pRspQryNetPortType->OperationType<< endl;
  cout << "on pRspQryNetPortType->ID:"<<pRspQryNetPortType->ID<< endl;
  cout << "on pRspQryNetPortType->CName:"<<pRspQryNetPortType->CName<< endl;
  cout << "on pRspQryNetPortType->EName:"<<pRspQryNetPortType->EName<< endl;
  cout << "on pRspQryNetPortType->Description:"<<pRspQryNetPortType->Description<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetPortTypeField* pNewRspQryNetPortType =new CShfeFtdcRspQryNetPortTypeField;
  memcpy(pNewRspQryNetPortType,pRspQryNetPortType,sizeof(CShfeFtdcRspQryNetPortTypeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetPortType;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetPortTypeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetPortTypeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetPortTypeTopic(CShfeFtdcRtnNetPortTypeField *pRtnNetPortType)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetPortType->OperationType:"<<pRtnNetPortType->OperationType<< endl;
  cout << "on pRtnNetPortType->ID:"<<pRtnNetPortType->ID<< endl;
  cout << "on pRtnNetPortType->CName:"<<pRtnNetPortType->CName<< endl;
  cout << "on pRtnNetPortType->EName:"<<pRtnNetPortType->EName<< endl;
  cout << "on pRtnNetPortType->Description:"<<pRtnNetPortType->Description<< endl;
  CShfeFtdcRtnNetPortTypeField* pNewRtnNetPortType =new CShfeFtdcRtnNetPortTypeField;
  memcpy(pNewRtnNetPortType,pRtnNetPortType,sizeof(CShfeFtdcRtnNetPortTypeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetPortType;
  asyncOnRtnNetPortTypeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetPortTypeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetPartAccessSpotTopic(CShfeFtdcRspQryNetPartAccessSpotField *pRspQryNetPartAccessSpot, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetPartAccessSpot->OperationType:"<<pRspQryNetPartAccessSpot->OperationType<< endl;
  cout << "on pRspQryNetPartAccessSpot->ID:"<<pRspQryNetPartAccessSpot->ID<< endl;
  cout << "on pRspQryNetPartAccessSpot->CName:"<<pRspQryNetPartAccessSpot->CName<< endl;
  cout << "on pRspQryNetPartAccessSpot->EName:"<<pRspQryNetPartAccessSpot->EName<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetPartAccessSpotField* pNewRspQryNetPartAccessSpot =new CShfeFtdcRspQryNetPartAccessSpotField;
  memcpy(pNewRspQryNetPartAccessSpot,pRspQryNetPartAccessSpot,sizeof(CShfeFtdcRspQryNetPartAccessSpotField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetPartAccessSpot;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetPartAccessSpotTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetPartAccessSpotTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetPartAccessSpotTopic(CShfeFtdcRtnNetPartAccessSpotField *pRtnNetPartAccessSpot)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetPartAccessSpot->OperationType:"<<pRtnNetPartAccessSpot->OperationType<< endl;
  cout << "on pRtnNetPartAccessSpot->ID:"<<pRtnNetPartAccessSpot->ID<< endl;
  cout << "on pRtnNetPartAccessSpot->CName:"<<pRtnNetPartAccessSpot->CName<< endl;
  cout << "on pRtnNetPartAccessSpot->EName:"<<pRtnNetPartAccessSpot->EName<< endl;
  CShfeFtdcRtnNetPartAccessSpotField* pNewRtnNetPartAccessSpot =new CShfeFtdcRtnNetPartAccessSpotField;
  memcpy(pNewRtnNetPartAccessSpot,pRtnNetPartAccessSpot,sizeof(CShfeFtdcRtnNetPartAccessSpotField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetPartAccessSpot;
  asyncOnRtnNetPartAccessSpotTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetPartAccessSpotTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetInterfaceTopic(CShfeFtdcRspQryNetInterfaceField *pRspQryNetInterface, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetInterface->OperationType:"<<pRspQryNetInterface->OperationType<< endl;
  cout << "on pRspQryNetInterface->ID:"<<pRspQryNetInterface->ID<< endl;
  cout << "on pRspQryNetInterface->ObjectID:"<<pRspQryNetInterface->ObjectID<< endl;
  cout << "on pRspQryNetInterface->MonitorType_ID:"<<pRspQryNetInterface->MonitorType_ID<< endl;
  cout << "on pRspQryNetInterface->IfType:"<<pRspQryNetInterface->IfType<< endl;
  cout << "on pRspQryNetInterface->EName:"<<pRspQryNetInterface->EName<< endl;
  cout << "on pRspQryNetInterface->IpAddress:"<<pRspQryNetInterface->IpAddress<< endl;
  cout << "on pRspQryNetInterface->IpMask:"<<pRspQryNetInterface->IpMask<< endl;
  cout << "on pRspQryNetInterface->IfStatus:"<<pRspQryNetInterface->IfStatus<< endl;
  cout << "on pRspQryNetInterface->MAC:"<<pRspQryNetInterface->MAC<< endl;
  cout << "on pRspQryNetInterface->DeviceID:"<<pRspQryNetInterface->DeviceID<< endl;
  cout << "on pRspQryNetInterface->DeviceObjectID:"<<pRspQryNetInterface->DeviceObjectID<< endl;
  cout << "on pRspQryNetInterface->DeviceIndex:"<<pRspQryNetInterface->DeviceIndex<< endl;
  cout << "on pRspQryNetInterface->isPolling:"<<pRspQryNetInterface->isPolling<< endl;
  cout << "on pRspQryNetInterface->Description:"<<pRspQryNetInterface->Description<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetInterfaceField* pNewRspQryNetInterface =new CShfeFtdcRspQryNetInterfaceField;
  memcpy(pNewRspQryNetInterface,pRspQryNetInterface,sizeof(CShfeFtdcRspQryNetInterfaceField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetInterface;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetInterfaceTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetInterfaceTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetInterfaceTopic(CShfeFtdcRtnNetInterfaceField *pRtnNetInterface)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetInterface->OperationType:"<<pRtnNetInterface->OperationType<< endl;
  cout << "on pRtnNetInterface->ID:"<<pRtnNetInterface->ID<< endl;
  cout << "on pRtnNetInterface->ObjectID:"<<pRtnNetInterface->ObjectID<< endl;
  cout << "on pRtnNetInterface->MonitorType_ID:"<<pRtnNetInterface->MonitorType_ID<< endl;
  cout << "on pRtnNetInterface->IfType:"<<pRtnNetInterface->IfType<< endl;
  cout << "on pRtnNetInterface->EName:"<<pRtnNetInterface->EName<< endl;
  cout << "on pRtnNetInterface->IpAddress:"<<pRtnNetInterface->IpAddress<< endl;
  cout << "on pRtnNetInterface->IpMask:"<<pRtnNetInterface->IpMask<< endl;
  cout << "on pRtnNetInterface->IfStatus:"<<pRtnNetInterface->IfStatus<< endl;
  cout << "on pRtnNetInterface->MAC:"<<pRtnNetInterface->MAC<< endl;
  cout << "on pRtnNetInterface->DeviceID:"<<pRtnNetInterface->DeviceID<< endl;
  cout << "on pRtnNetInterface->DeviceObjectID:"<<pRtnNetInterface->DeviceObjectID<< endl;
  cout << "on pRtnNetInterface->DeviceIndex:"<<pRtnNetInterface->DeviceIndex<< endl;
  cout << "on pRtnNetInterface->isPolling:"<<pRtnNetInterface->isPolling<< endl;
  cout << "on pRtnNetInterface->Description:"<<pRtnNetInterface->Description<< endl;
  CShfeFtdcRtnNetInterfaceField* pNewRtnNetInterface =new CShfeFtdcRtnNetInterfaceField;
  memcpy(pNewRtnNetInterface,pRtnNetInterface,sizeof(CShfeFtdcRtnNetInterfaceField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetInterface;
  asyncOnRtnNetInterfaceTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetInterfaceTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetGeneralOIDTopic(CShfeFtdcRspQryNetGeneralOIDField *pRspQryNetGeneralOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetGeneralOID->OperationType:"<<pRspQryNetGeneralOID->OperationType<< endl;
  cout << "on pRspQryNetGeneralOID->ID:"<<pRspQryNetGeneralOID->ID<< endl;
  cout << "on pRspQryNetGeneralOID->CName:"<<pRspQryNetGeneralOID->CName<< endl;
  cout << "on pRspQryNetGeneralOID->EName:"<<pRspQryNetGeneralOID->EName<< endl;
  cout << "on pRspQryNetGeneralOID->OID:"<<pRspQryNetGeneralOID->OID<< endl;
  cout << "on pRspQryNetGeneralOID->Unit:"<<pRspQryNetGeneralOID->Unit<< endl;
  cout << "on pRspQryNetGeneralOID->isTheTable:"<<pRspQryNetGeneralOID->isTheTable<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetGeneralOIDField* pNewRspQryNetGeneralOID =new CShfeFtdcRspQryNetGeneralOIDField;
  memcpy(pNewRspQryNetGeneralOID,pRspQryNetGeneralOID,sizeof(CShfeFtdcRspQryNetGeneralOIDField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetGeneralOID;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetGeneralOIDTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetGeneralOIDTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetGeneralOIDTopic(CShfeFtdcRtnNetGeneralOIDField *pRtnNetGeneralOID)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetGeneralOID->OperationType:"<<pRtnNetGeneralOID->OperationType<< endl;
  cout << "on pRtnNetGeneralOID->ID:"<<pRtnNetGeneralOID->ID<< endl;
  cout << "on pRtnNetGeneralOID->CName:"<<pRtnNetGeneralOID->CName<< endl;
  cout << "on pRtnNetGeneralOID->EName:"<<pRtnNetGeneralOID->EName<< endl;
  cout << "on pRtnNetGeneralOID->OID:"<<pRtnNetGeneralOID->OID<< endl;
  cout << "on pRtnNetGeneralOID->Unit:"<<pRtnNetGeneralOID->Unit<< endl;
  cout << "on pRtnNetGeneralOID->isTheTable:"<<pRtnNetGeneralOID->isTheTable<< endl;
  CShfeFtdcRtnNetGeneralOIDField* pNewRtnNetGeneralOID =new CShfeFtdcRtnNetGeneralOIDField;
  memcpy(pNewRtnNetGeneralOID,pRtnNetGeneralOID,sizeof(CShfeFtdcRtnNetGeneralOIDField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetGeneralOID;
  asyncOnRtnNetGeneralOIDTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetGeneralOIDTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetMonitorTypeTopic(CShfeFtdcRspQryNetMonitorTypeField *pRspQryNetMonitorType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetMonitorType->OperationType:"<<pRspQryNetMonitorType->OperationType<< endl;
  cout << "on pRspQryNetMonitorType->ID:"<<pRspQryNetMonitorType->ID<< endl;
  cout << "on pRspQryNetMonitorType->CName:"<<pRspQryNetMonitorType->CName<< endl;
  cout << "on pRspQryNetMonitorType->EName:"<<pRspQryNetMonitorType->EName<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetMonitorTypeField* pNewRspQryNetMonitorType =new CShfeFtdcRspQryNetMonitorTypeField;
  memcpy(pNewRspQryNetMonitorType,pRspQryNetMonitorType,sizeof(CShfeFtdcRspQryNetMonitorTypeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorType;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorTypeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetMonitorTypeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetMonitorTypeTopic(CShfeFtdcRtnNetMonitorTypeField *pRtnNetMonitorType)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetMonitorType->OperationType:"<<pRtnNetMonitorType->OperationType<< endl;
  cout << "on pRtnNetMonitorType->ID:"<<pRtnNetMonitorType->ID<< endl;
  cout << "on pRtnNetMonitorType->CName:"<<pRtnNetMonitorType->CName<< endl;
  cout << "on pRtnNetMonitorType->EName:"<<pRtnNetMonitorType->EName<< endl;
  CShfeFtdcRtnNetMonitorTypeField* pNewRtnNetMonitorType =new CShfeFtdcRtnNetMonitorTypeField;
  memcpy(pNewRtnNetMonitorType,pRtnNetMonitorType,sizeof(CShfeFtdcRtnNetMonitorTypeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorType;
  asyncOnRtnNetMonitorTypeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetMonitorTypeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetMonitorAttrScopeTopic(CShfeFtdcRspQryNetMonitorAttrScopeField *pRspQryNetMonitorAttrScope, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{

  CShfeFtdcRspQryNetMonitorAttrScopeField* pNewRspQryNetMonitorAttrScope =new CShfeFtdcRspQryNetMonitorAttrScopeField;
  memcpy(pNewRspQryNetMonitorAttrScope,pRspQryNetMonitorAttrScope,sizeof(CShfeFtdcRspQryNetMonitorAttrScopeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorAttrScope;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
//  asyncOnRspQryNetMonitorAttrScopeTopic.data=(void*)&paramArray[0];
  
//   uv_mutex_lock(&g_OnRspQryNetMonitorAttrScopeTopic_data_mutex);
//   g_OnRspQryNetMonitorAttrScopeTopic_queue.push(paramArray);
//   uv_mutex_unlock(&g_OnRspQryNetMonitorAttrScopeTopic_data_mutex);
  
// //  uv_sem_wait(&g_OnRspQryNetMonitorAttrScopeTopicc_sem);
//   uv_mutex_lock(&g_OnRspQryNetMonitorAttrScopeTopic_mutex);
  
//   int iPid = (int)getpid();    
  
  cout << "\n*********** SysUserSpi::OnRspQryNetMonitorAttrScopeTopic: START! **********"<< endl;
  cout << "****** g_OnRspQryNetMonitorAttrScopeTopic_Sys_index: " 
       << g_OnRspQryNetMonitorAttrScopeTopic_Sys_index++ <<" ******" <<endl;
//  cout << "The process id is:                                   " <<iPid <<std::endl;    
//   cout << "on pRspQryNetMonitorAttrScope->OperationType:        " <<pRspQryNetMonitorAttrScope->OperationType<< endl;
//   cout << "on pRspQryNetMonitorAttrScope->ID:                   " <<pRspQryNetMonitorAttrScope->ID<< endl;
//   cout << "on pRspQryNetMonitorAttrScope->CName:                " <<pRspQryNetMonitorAttrScope->CName<< endl;
//   cout << "on pRspQryNetMonitorAttrScope->EName:                " <<pRspQryNetMonitorAttrScope->EName<< endl;
//   cout << "on pRspQryNetMonitorAttrScope->Comments:             " <<pRspQryNetMonitorAttrScope->Comments<< endl;
//   cout << "on pRspInfo:                                         " <<pRspInfo<< endl;
//   cout << "on nRequestID:                                       " <<nRequestID<< endl;
//   cout << "on bIsLast:                                          " <<bIsLast<< endl;
  
//   uv_async_send(&asyncOnRspQryNetMonitorAttrScopeTopic);
  
//   uv_mutex_unlock(&g_OnRspQryNetMonitorAttrScopeTopic_mutex);
  
   cout << "*********** SysUserSpi::OnRspQryNetMonitorAttrScopeTopic: END! **********\n"<< endl;
}
void SysUserSpi::OnRtnNetMonitorAttrScopeTopic(CShfeFtdcRtnNetMonitorAttrScopeField *pRtnNetMonitorAttrScope)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetMonitorAttrScope->OperationType:"<<pRtnNetMonitorAttrScope->OperationType<< endl;
  cout << "on pRtnNetMonitorAttrScope->ID:"<<pRtnNetMonitorAttrScope->ID<< endl;
  cout << "on pRtnNetMonitorAttrScope->CName:"<<pRtnNetMonitorAttrScope->CName<< endl;
  cout << "on pRtnNetMonitorAttrScope->EName:"<<pRtnNetMonitorAttrScope->EName<< endl;
  cout << "on pRtnNetMonitorAttrScope->Comments:"<<pRtnNetMonitorAttrScope->Comments<< endl;
  CShfeFtdcRtnNetMonitorAttrScopeField* pNewRtnNetMonitorAttrScope =new CShfeFtdcRtnNetMonitorAttrScopeField;
  memcpy(pNewRtnNetMonitorAttrScope,pRtnNetMonitorAttrScope,sizeof(CShfeFtdcRtnNetMonitorAttrScopeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorAttrScope;
  asyncOnRtnNetMonitorAttrScopeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetMonitorAttrScopeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetMonitorAttrTypeTopic(CShfeFtdcRspQryNetMonitorAttrTypeField *pRspQryNetMonitorAttrType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetMonitorAttrType->OperationType:"<<pRspQryNetMonitorAttrType->OperationType<< endl;
  cout << "on pRspQryNetMonitorAttrType->ID:"<<pRspQryNetMonitorAttrType->ID<< endl;
  cout << "on pRspQryNetMonitorAttrType->MANUFACTORY_ID:"<<pRspQryNetMonitorAttrType->MANUFACTORY_ID<< endl;
  cout << "on pRspQryNetMonitorAttrType->MonitorType_ID:"<<pRspQryNetMonitorAttrType->MonitorType_ID<< endl;
  cout << "on pRspQryNetMonitorAttrType->AttrType_ID:"<<pRspQryNetMonitorAttrType->AttrType_ID<< endl;
  cout << "on pRspQryNetMonitorAttrType->MANUFACTORY:"<<pRspQryNetMonitorAttrType->MANUFACTORY<< endl;
  cout << "on pRspQryNetMonitorAttrType->MonitorType:"<<pRspQryNetMonitorAttrType->MonitorType<< endl;
  cout << "on pRspQryNetMonitorAttrType->AttrType:"<<pRspQryNetMonitorAttrType->AttrType<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetMonitorAttrTypeField* pNewRspQryNetMonitorAttrType =new CShfeFtdcRspQryNetMonitorAttrTypeField;
  memcpy(pNewRspQryNetMonitorAttrType,pRspQryNetMonitorAttrType,sizeof(CShfeFtdcRspQryNetMonitorAttrTypeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorAttrType;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorAttrTypeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetMonitorAttrTypeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetMonitorAttrTypeTopic(CShfeFtdcRtnNetMonitorAttrTypeField *pRtnNetMonitorAttrType)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetMonitorAttrType->OperationType:"<<pRtnNetMonitorAttrType->OperationType<< endl;
  cout << "on pRtnNetMonitorAttrType->ID:"<<pRtnNetMonitorAttrType->ID<< endl;
  cout << "on pRtnNetMonitorAttrType->MANUFACTORY_ID:"<<pRtnNetMonitorAttrType->MANUFACTORY_ID<< endl;
  cout << "on pRtnNetMonitorAttrType->MonitorType_ID:"<<pRtnNetMonitorAttrType->MonitorType_ID<< endl;
  cout << "on pRtnNetMonitorAttrType->AttrType_ID:"<<pRtnNetMonitorAttrType->AttrType_ID<< endl;
  cout << "on pRtnNetMonitorAttrType->MANUFACTORY:"<<pRtnNetMonitorAttrType->MANUFACTORY<< endl;
  cout << "on pRtnNetMonitorAttrType->MonitorType:"<<pRtnNetMonitorAttrType->MonitorType<< endl;
  cout << "on pRtnNetMonitorAttrType->AttrType:"<<pRtnNetMonitorAttrType->AttrType<< endl;
  CShfeFtdcRtnNetMonitorAttrTypeField* pNewRtnNetMonitorAttrType =new CShfeFtdcRtnNetMonitorAttrTypeField;
  memcpy(pNewRtnNetMonitorAttrType,pRtnNetMonitorAttrType,sizeof(CShfeFtdcRtnNetMonitorAttrTypeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorAttrType;
  asyncOnRtnNetMonitorAttrTypeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetMonitorAttrTypeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetMonitorObjectAttrTopic(CShfeFtdcRspQryNetMonitorObjectAttrField *pRspQryNetMonitorObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetMonitorObjectAttr->OperationType:"<<pRspQryNetMonitorObjectAttr->OperationType<< endl;
  cout << "on pRspQryNetMonitorObjectAttr->ID:"<<pRspQryNetMonitorObjectAttr->ID<< endl;
  cout << "on pRspQryNetMonitorObjectAttr->ObjectID:"<<pRspQryNetMonitorObjectAttr->ObjectID<< endl;
  cout << "on pRspQryNetMonitorObjectAttr->AttrType:"<<pRspQryNetMonitorObjectAttr->AttrType<< endl;
  cout << "on pRspQryNetMonitorObjectAttr->PolicyTypeID:"<<pRspQryNetMonitorObjectAttr->PolicyTypeID<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetMonitorObjectAttrField* pNewRspQryNetMonitorObjectAttr =new CShfeFtdcRspQryNetMonitorObjectAttrField;
  memcpy(pNewRspQryNetMonitorObjectAttr,pRspQryNetMonitorObjectAttr,sizeof(CShfeFtdcRspQryNetMonitorObjectAttrField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorObjectAttr;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorObjectAttrTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetMonitorObjectAttrTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetMonitorObjectAttrTopic(CShfeFtdcRtnNetMonitorObjectAttrField *pRtnNetMonitorObjectAttr)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetMonitorObjectAttr->OperationType:"<<pRtnNetMonitorObjectAttr->OperationType<< endl;
  cout << "on pRtnNetMonitorObjectAttr->ID:"<<pRtnNetMonitorObjectAttr->ID<< endl;
  cout << "on pRtnNetMonitorObjectAttr->ObjectID:"<<pRtnNetMonitorObjectAttr->ObjectID<< endl;
  cout << "on pRtnNetMonitorObjectAttr->AttrType:"<<pRtnNetMonitorObjectAttr->AttrType<< endl;
  cout << "on pRtnNetMonitorObjectAttr->PolicyTypeID:"<<pRtnNetMonitorObjectAttr->PolicyTypeID<< endl;
  CShfeFtdcRtnNetMonitorObjectAttrField* pNewRtnNetMonitorObjectAttr =new CShfeFtdcRtnNetMonitorObjectAttrField;
  memcpy(pNewRtnNetMonitorObjectAttr,pRtnNetMonitorObjectAttr,sizeof(CShfeFtdcRtnNetMonitorObjectAttrField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorObjectAttr;
  asyncOnRtnNetMonitorObjectAttrTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetMonitorObjectAttrTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetFuncAreaTopic(CShfeFtdcRspQryNetFuncAreaField *pRspQryNetFuncArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetFuncArea->OperationType:"<<pRspQryNetFuncArea->OperationType<< endl;
  cout << "on pRspQryNetFuncArea->ID:"<<pRspQryNetFuncArea->ID<< endl;
  cout << "on pRspQryNetFuncArea->SysNetSubAreaID:"<<pRspQryNetFuncArea->SysNetSubAreaID<< endl;
  cout << "on pRspQryNetFuncArea->CName:"<<pRspQryNetFuncArea->CName<< endl;
  cout << "on pRspQryNetFuncArea->EName:"<<pRspQryNetFuncArea->EName<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetFuncAreaField* pNewRspQryNetFuncArea =new CShfeFtdcRspQryNetFuncAreaField;
  memcpy(pNewRspQryNetFuncArea,pRspQryNetFuncArea,sizeof(CShfeFtdcRspQryNetFuncAreaField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetFuncArea;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetFuncAreaTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetFuncAreaTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetFuncAreaTopic(CShfeFtdcRtnNetFuncAreaField *pRtnNetFuncArea)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetFuncArea->OperationType:"<<pRtnNetFuncArea->OperationType<< endl;
  cout << "on pRtnNetFuncArea->ID:"<<pRtnNetFuncArea->ID<< endl;
  cout << "on pRtnNetFuncArea->SysNetSubAreaID:"<<pRtnNetFuncArea->SysNetSubAreaID<< endl;
  cout << "on pRtnNetFuncArea->CName:"<<pRtnNetFuncArea->CName<< endl;
  cout << "on pRtnNetFuncArea->EName:"<<pRtnNetFuncArea->EName<< endl;
  CShfeFtdcRtnNetFuncAreaField* pNewRtnNetFuncArea =new CShfeFtdcRtnNetFuncAreaField;
  memcpy(pNewRtnNetFuncArea,pRtnNetFuncArea,sizeof(CShfeFtdcRtnNetFuncAreaField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetFuncArea;
  asyncOnRtnNetFuncAreaTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetFuncAreaTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetMonitorCommandTypeTopic(CShfeFtdcRspQryNetMonitorCommandTypeField *pRspQryNetMonitorCommandType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetMonitorCommandType->OperationType:"<<pRspQryNetMonitorCommandType->OperationType<< endl;
  cout << "on pRspQryNetMonitorCommandType->ID:"<<pRspQryNetMonitorCommandType->ID<< endl;
  cout << "on pRspQryNetMonitorCommandType->Manufactory_ID:"<<pRspQryNetMonitorCommandType->Manufactory_ID<< endl;
  cout << "on pRspQryNetMonitorCommandType->MonitorType_ID:"<<pRspQryNetMonitorCommandType->MonitorType_ID<< endl;
  cout << "on pRspQryNetMonitorCommandType->DeviceModle_ID:"<<pRspQryNetMonitorCommandType->DeviceModle_ID<< endl;
  cout << "on pRspQryNetMonitorCommandType->ActionGroup_ID:"<<pRspQryNetMonitorCommandType->ActionGroup_ID<< endl;
  cout << "on pRspQryNetMonitorCommandType->Manufactory:"<<pRspQryNetMonitorCommandType->Manufactory<< endl;
  cout << "on pRspQryNetMonitorCommandType->MonitorType:"<<pRspQryNetMonitorCommandType->MonitorType<< endl;
  cout << "on pRspQryNetMonitorCommandType->DeviceModle:"<<pRspQryNetMonitorCommandType->DeviceModle<< endl;
  cout << "on pRspQryNetMonitorCommandType->ActionGroup:"<<pRspQryNetMonitorCommandType->ActionGroup<< endl;
  cout << "on pRspQryNetMonitorCommandType->Command:"<<pRspQryNetMonitorCommandType->Command<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetMonitorCommandTypeField* pNewRspQryNetMonitorCommandType =new CShfeFtdcRspQryNetMonitorCommandTypeField;
  memcpy(pNewRspQryNetMonitorCommandType,pRspQryNetMonitorCommandType,sizeof(CShfeFtdcRspQryNetMonitorCommandTypeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorCommandType;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorCommandTypeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetMonitorCommandTypeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetMonitorCommandTypeTopic(CShfeFtdcRtnNetMonitorCommandTypeField *pRtnNetMonitorCommandType)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetMonitorCommandType->OperationType:"<<pRtnNetMonitorCommandType->OperationType<< endl;
  cout << "on pRtnNetMonitorCommandType->ID:"<<pRtnNetMonitorCommandType->ID<< endl;
  cout << "on pRtnNetMonitorCommandType->Manufactory_ID:"<<pRtnNetMonitorCommandType->Manufactory_ID<< endl;
  cout << "on pRtnNetMonitorCommandType->MonitorType_ID:"<<pRtnNetMonitorCommandType->MonitorType_ID<< endl;
  cout << "on pRtnNetMonitorCommandType->DeviceModle_ID:"<<pRtnNetMonitorCommandType->DeviceModle_ID<< endl;
  cout << "on pRtnNetMonitorCommandType->ActionGroup_ID:"<<pRtnNetMonitorCommandType->ActionGroup_ID<< endl;
  cout << "on pRtnNetMonitorCommandType->Manufactory:"<<pRtnNetMonitorCommandType->Manufactory<< endl;
  cout << "on pRtnNetMonitorCommandType->MonitorType:"<<pRtnNetMonitorCommandType->MonitorType<< endl;
  cout << "on pRtnNetMonitorCommandType->DeviceModle:"<<pRtnNetMonitorCommandType->DeviceModle<< endl;
  cout << "on pRtnNetMonitorCommandType->ActionGroup:"<<pRtnNetMonitorCommandType->ActionGroup<< endl;
  cout << "on pRtnNetMonitorCommandType->Command:"<<pRtnNetMonitorCommandType->Command<< endl;
  CShfeFtdcRtnNetMonitorCommandTypeField* pNewRtnNetMonitorCommandType =new CShfeFtdcRtnNetMonitorCommandTypeField;
  memcpy(pNewRtnNetMonitorCommandType,pRtnNetMonitorCommandType,sizeof(CShfeFtdcRtnNetMonitorCommandTypeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorCommandType;
  asyncOnRtnNetMonitorCommandTypeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetMonitorCommandTypeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetMonitorActionGroupTopic(CShfeFtdcRspQryNetMonitorActionGroupField *pRspQryNetMonitorActionGroup, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetMonitorActionGroup->OperationType:"<<pRspQryNetMonitorActionGroup->OperationType<< endl;
  cout << "on pRspQryNetMonitorActionGroup->ID:"<<pRspQryNetMonitorActionGroup->ID<< endl;
  cout << "on pRspQryNetMonitorActionGroup->CName:"<<pRspQryNetMonitorActionGroup->CName<< endl;
  cout << "on pRspQryNetMonitorActionGroup->EName:"<<pRspQryNetMonitorActionGroup->EName<< endl;
  cout << "on pRspQryNetMonitorActionGroup->ActionType:"<<pRspQryNetMonitorActionGroup->ActionType<< endl;
  cout << "on pRspQryNetMonitorActionGroup->Comments:"<<pRspQryNetMonitorActionGroup->Comments<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetMonitorActionGroupField* pNewRspQryNetMonitorActionGroup =new CShfeFtdcRspQryNetMonitorActionGroupField;
  memcpy(pNewRspQryNetMonitorActionGroup,pRspQryNetMonitorActionGroup,sizeof(CShfeFtdcRspQryNetMonitorActionGroupField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorActionGroup;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorActionGroupTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetMonitorActionGroupTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetMonitorActionGroupTopic(CShfeFtdcRtnNetMonitorActionGroupField *pRtnNetMonitorActionGroup)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetMonitorActionGroup->OperationType:"<<pRtnNetMonitorActionGroup->OperationType<< endl;
  cout << "on pRtnNetMonitorActionGroup->ID:"<<pRtnNetMonitorActionGroup->ID<< endl;
  cout << "on pRtnNetMonitorActionGroup->CName:"<<pRtnNetMonitorActionGroup->CName<< endl;
  cout << "on pRtnNetMonitorActionGroup->EName:"<<pRtnNetMonitorActionGroup->EName<< endl;
  cout << "on pRtnNetMonitorActionGroup->ActionType:"<<pRtnNetMonitorActionGroup->ActionType<< endl;
  cout << "on pRtnNetMonitorActionGroup->Comments:"<<pRtnNetMonitorActionGroup->Comments<< endl;
  CShfeFtdcRtnNetMonitorActionGroupField* pNewRtnNetMonitorActionGroup =new CShfeFtdcRtnNetMonitorActionGroupField;
  memcpy(pNewRtnNetMonitorActionGroup,pRtnNetMonitorActionGroup,sizeof(CShfeFtdcRtnNetMonitorActionGroupField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorActionGroup;
  asyncOnRtnNetMonitorActionGroupTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetMonitorActionGroupTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetMonitorDeviceGroupTopic(CShfeFtdcRspQryNetMonitorDeviceGroupField *pRspQryNetMonitorDeviceGroup, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetMonitorDeviceGroup->OperationType:"<<pRspQryNetMonitorDeviceGroup->OperationType<< endl;
  cout << "on pRspQryNetMonitorDeviceGroup->ID:"<<pRspQryNetMonitorDeviceGroup->ID<< endl;
  cout << "on pRspQryNetMonitorDeviceGroup->CName:"<<pRspQryNetMonitorDeviceGroup->CName<< endl;
  cout << "on pRspQryNetMonitorDeviceGroup->EName:"<<pRspQryNetMonitorDeviceGroup->EName<< endl;
  cout << "on pRspQryNetMonitorDeviceGroup->Condition:"<<pRspQryNetMonitorDeviceGroup->Condition<< endl;
  cout << "on pRspQryNetMonitorDeviceGroup->Comments:"<<pRspQryNetMonitorDeviceGroup->Comments<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetMonitorDeviceGroupField* pNewRspQryNetMonitorDeviceGroup =new CShfeFtdcRspQryNetMonitorDeviceGroupField;
  memcpy(pNewRspQryNetMonitorDeviceGroup,pRspQryNetMonitorDeviceGroup,sizeof(CShfeFtdcRspQryNetMonitorDeviceGroupField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorDeviceGroup;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorDeviceGroupTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetMonitorDeviceGroupTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetMonitorDeviceGroupTopic(CShfeFtdcRtnNetMonitorDeviceGroupField *pRtnNetMonitorDeviceGroup)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetMonitorDeviceGroup->OperationType:"<<pRtnNetMonitorDeviceGroup->OperationType<< endl;
  cout << "on pRtnNetMonitorDeviceGroup->ID:"<<pRtnNetMonitorDeviceGroup->ID<< endl;
  cout << "on pRtnNetMonitorDeviceGroup->CName:"<<pRtnNetMonitorDeviceGroup->CName<< endl;
  cout << "on pRtnNetMonitorDeviceGroup->EName:"<<pRtnNetMonitorDeviceGroup->EName<< endl;
  cout << "on pRtnNetMonitorDeviceGroup->Condition:"<<pRtnNetMonitorDeviceGroup->Condition<< endl;
  cout << "on pRtnNetMonitorDeviceGroup->Comments:"<<pRtnNetMonitorDeviceGroup->Comments<< endl;
  CShfeFtdcRtnNetMonitorDeviceGroupField* pNewRtnNetMonitorDeviceGroup =new CShfeFtdcRtnNetMonitorDeviceGroupField;
  memcpy(pNewRtnNetMonitorDeviceGroup,pRtnNetMonitorDeviceGroup,sizeof(CShfeFtdcRtnNetMonitorDeviceGroupField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorDeviceGroup;
  asyncOnRtnNetMonitorDeviceGroupTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetMonitorDeviceGroupTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetMonitorTaskInfoTopic(CShfeFtdcRspQryNetMonitorTaskInfoField *pRspQryNetMonitorTaskInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->OperationType:"<<pRspQryNetMonitorTaskInfo->OperationType<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->ID:"<<pRspQryNetMonitorTaskInfo->ID<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->CName:"<<pRspQryNetMonitorTaskInfo->CName<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->EName:"<<pRspQryNetMonitorTaskInfo->EName<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->DeviceGroup_ID:"<<pRspQryNetMonitorTaskInfo->DeviceGroup_ID<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->ManagerGroup_ID:"<<pRspQryNetMonitorTaskInfo->ManagerGroup_ID<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->TimePolicy_ID:"<<pRspQryNetMonitorTaskInfo->TimePolicy_ID<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->TaskPriority_ID:"<<pRspQryNetMonitorTaskInfo->TaskPriority_ID<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->OutputPolicy_ID:"<<pRspQryNetMonitorTaskInfo->OutputPolicy_ID<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->ActionGroup_ID:"<<pRspQryNetMonitorTaskInfo->ActionGroup_ID<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->EventExprStr:"<<pRspQryNetMonitorTaskInfo->EventExprStr<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->DeviceGroup:"<<pRspQryNetMonitorTaskInfo->DeviceGroup<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->ManagerGroup:"<<pRspQryNetMonitorTaskInfo->ManagerGroup<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->TimePolicy:"<<pRspQryNetMonitorTaskInfo->TimePolicy<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->TaskPriority:"<<pRspQryNetMonitorTaskInfo->TaskPriority<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->OutputPolicy:"<<pRspQryNetMonitorTaskInfo->OutputPolicy<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->ActionGroup:"<<pRspQryNetMonitorTaskInfo->ActionGroup<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->ValidFlag:"<<pRspQryNetMonitorTaskInfo->ValidFlag<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->TaskStatus:"<<pRspQryNetMonitorTaskInfo->TaskStatus<< endl;
  cout << "on pRspQryNetMonitorTaskInfo->Comments:"<<pRspQryNetMonitorTaskInfo->Comments<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetMonitorTaskInfoField* pNewRspQryNetMonitorTaskInfo =new CShfeFtdcRspQryNetMonitorTaskInfoField;
  memcpy(pNewRspQryNetMonitorTaskInfo,pRspQryNetMonitorTaskInfo,sizeof(CShfeFtdcRspQryNetMonitorTaskInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorTaskInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorTaskInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetMonitorTaskInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetMonitorTaskInfoTopic(CShfeFtdcRtnNetMonitorTaskInfoField *pRtnNetMonitorTaskInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetMonitorTaskInfo->OperationType:"<<pRtnNetMonitorTaskInfo->OperationType<< endl;
  cout << "on pRtnNetMonitorTaskInfo->ID:"<<pRtnNetMonitorTaskInfo->ID<< endl;
  cout << "on pRtnNetMonitorTaskInfo->CName:"<<pRtnNetMonitorTaskInfo->CName<< endl;
  cout << "on pRtnNetMonitorTaskInfo->EName:"<<pRtnNetMonitorTaskInfo->EName<< endl;
  cout << "on pRtnNetMonitorTaskInfo->DeviceGroup_ID:"<<pRtnNetMonitorTaskInfo->DeviceGroup_ID<< endl;
  cout << "on pRtnNetMonitorTaskInfo->ManagerGroup_ID:"<<pRtnNetMonitorTaskInfo->ManagerGroup_ID<< endl;
  cout << "on pRtnNetMonitorTaskInfo->TimePolicy_ID:"<<pRtnNetMonitorTaskInfo->TimePolicy_ID<< endl;
  cout << "on pRtnNetMonitorTaskInfo->TaskPriority_ID:"<<pRtnNetMonitorTaskInfo->TaskPriority_ID<< endl;
  cout << "on pRtnNetMonitorTaskInfo->OutputPolicy_ID:"<<pRtnNetMonitorTaskInfo->OutputPolicy_ID<< endl;
  cout << "on pRtnNetMonitorTaskInfo->ActionGroup_ID:"<<pRtnNetMonitorTaskInfo->ActionGroup_ID<< endl;
  cout << "on pRtnNetMonitorTaskInfo->EventExprStr:"<<pRtnNetMonitorTaskInfo->EventExprStr<< endl;
  cout << "on pRtnNetMonitorTaskInfo->DeviceGroup:"<<pRtnNetMonitorTaskInfo->DeviceGroup<< endl;
  cout << "on pRtnNetMonitorTaskInfo->ManagerGroup:"<<pRtnNetMonitorTaskInfo->ManagerGroup<< endl;
  cout << "on pRtnNetMonitorTaskInfo->TimePolicy:"<<pRtnNetMonitorTaskInfo->TimePolicy<< endl;
  cout << "on pRtnNetMonitorTaskInfo->TaskPriority:"<<pRtnNetMonitorTaskInfo->TaskPriority<< endl;
  cout << "on pRtnNetMonitorTaskInfo->OutputPolicy:"<<pRtnNetMonitorTaskInfo->OutputPolicy<< endl;
  cout << "on pRtnNetMonitorTaskInfo->ActionGroup:"<<pRtnNetMonitorTaskInfo->ActionGroup<< endl;
  cout << "on pRtnNetMonitorTaskInfo->ValidFlag:"<<pRtnNetMonitorTaskInfo->ValidFlag<< endl;
  cout << "on pRtnNetMonitorTaskInfo->TaskStatus:"<<pRtnNetMonitorTaskInfo->TaskStatus<< endl;
  cout << "on pRtnNetMonitorTaskInfo->Comments:"<<pRtnNetMonitorTaskInfo->Comments<< endl;
  CShfeFtdcRtnNetMonitorTaskInfoField* pNewRtnNetMonitorTaskInfo =new CShfeFtdcRtnNetMonitorTaskInfoField;
  memcpy(pNewRtnNetMonitorTaskInfo,pRtnNetMonitorTaskInfo,sizeof(CShfeFtdcRtnNetMonitorTaskInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorTaskInfo;
  asyncOnRtnNetMonitorTaskInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetMonitorTaskInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetMonitorTaskResultTopic(CShfeFtdcRspQryNetMonitorTaskResultField *pRspQryNetMonitorTaskResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetMonitorTaskResult->OperationType:"<<pRspQryNetMonitorTaskResult->OperationType<< endl;
  cout << "on pRspQryNetMonitorTaskResult->ObjectID:"<<pRspQryNetMonitorTaskResult->ObjectID<< endl;
  cout << "on pRspQryNetMonitorTaskResult->Task_ID:"<<pRspQryNetMonitorTaskResult->Task_ID<< endl;
  cout << "on pRspQryNetMonitorTaskResult->OperateTime:"<<pRspQryNetMonitorTaskResult->OperateTime<< endl;
  cout << "on pRspQryNetMonitorTaskResult->MonDate:"<<pRspQryNetMonitorTaskResult->MonDate<< endl;
  cout << "on pRspQryNetMonitorTaskResult->MonTime:"<<pRspQryNetMonitorTaskResult->MonTime<< endl;
  cout << "on pRspQryNetMonitorTaskResult->InstructChain:"<<pRspQryNetMonitorTaskResult->InstructChain<< endl;
  cout << "on pRspQryNetMonitorTaskResult->ResultChain:"<<pRspQryNetMonitorTaskResult->ResultChain<< endl;
  cout << "on pRspQryNetMonitorTaskResult->Flag:"<<pRspQryNetMonitorTaskResult->Flag<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetMonitorTaskResultField* pNewRspQryNetMonitorTaskResult =new CShfeFtdcRspQryNetMonitorTaskResultField;
  memcpy(pNewRspQryNetMonitorTaskResult,pRspQryNetMonitorTaskResult,sizeof(CShfeFtdcRspQryNetMonitorTaskResultField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorTaskResult;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorTaskResultTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetMonitorTaskResultTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetMonitorTaskResultTopic(CShfeFtdcRtnNetMonitorTaskResultField *pRtnNetMonitorTaskResult)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetMonitorTaskResult->OperationType:"<<pRtnNetMonitorTaskResult->OperationType<< endl;
  cout << "on pRtnNetMonitorTaskResult->ObjectID:"<<pRtnNetMonitorTaskResult->ObjectID<< endl;
  cout << "on pRtnNetMonitorTaskResult->Task_ID:"<<pRtnNetMonitorTaskResult->Task_ID<< endl;
  cout << "on pRtnNetMonitorTaskResult->OperateTime:"<<pRtnNetMonitorTaskResult->OperateTime<< endl;
  cout << "on pRtnNetMonitorTaskResult->MonDate:"<<pRtnNetMonitorTaskResult->MonDate<< endl;
  cout << "on pRtnNetMonitorTaskResult->MonTime:"<<pRtnNetMonitorTaskResult->MonTime<< endl;
  cout << "on pRtnNetMonitorTaskResult->InstructChain:"<<pRtnNetMonitorTaskResult->InstructChain<< endl;
  cout << "on pRtnNetMonitorTaskResult->ResultChain:"<<pRtnNetMonitorTaskResult->ResultChain<< endl;
  cout << "on pRtnNetMonitorTaskResult->Flag:"<<pRtnNetMonitorTaskResult->Flag<< endl;
  CShfeFtdcRtnNetMonitorTaskResultField* pNewRtnNetMonitorTaskResult =new CShfeFtdcRtnNetMonitorTaskResultField;
  memcpy(pNewRtnNetMonitorTaskResult,pRtnNetMonitorTaskResult,sizeof(CShfeFtdcRtnNetMonitorTaskResultField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorTaskResult;
  asyncOnRtnNetMonitorTaskResultTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetMonitorTaskResultTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetMonitorTaskObjectSetTopic(CShfeFtdcRspQryNetMonitorTaskObjectSetField *pRspQryNetMonitorTaskObjectSet, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetMonitorTaskObjectSet->OperationType:"<<pRspQryNetMonitorTaskObjectSet->OperationType<< endl;
  cout << "on pRspQryNetMonitorTaskObjectSet->ID:"<<pRspQryNetMonitorTaskObjectSet->ID<< endl;
  cout << "on pRspQryNetMonitorTaskObjectSet->DeviceGroup_ID:"<<pRspQryNetMonitorTaskObjectSet->DeviceGroup_ID<< endl;
  cout << "on pRspQryNetMonitorTaskObjectSet->Device_ID:"<<pRspQryNetMonitorTaskObjectSet->Device_ID<< endl;
  cout << "on pRspQryNetMonitorTaskObjectSet->DataCenter:"<<pRspQryNetMonitorTaskObjectSet->DataCenter<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetMonitorTaskObjectSetField* pNewRspQryNetMonitorTaskObjectSet =new CShfeFtdcRspQryNetMonitorTaskObjectSetField;
  memcpy(pNewRspQryNetMonitorTaskObjectSet,pRspQryNetMonitorTaskObjectSet,sizeof(CShfeFtdcRspQryNetMonitorTaskObjectSetField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorTaskObjectSet;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorTaskObjectSetTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetMonitorTaskObjectSetTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetMonitorTaskObjectSetTopic(CShfeFtdcRtnNetMonitorTaskObjectSetField *pRtnNetMonitorTaskObjectSet)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetMonitorTaskObjectSet->OperationType:"<<pRtnNetMonitorTaskObjectSet->OperationType<< endl;
  cout << "on pRtnNetMonitorTaskObjectSet->ID:"<<pRtnNetMonitorTaskObjectSet->ID<< endl;
  cout << "on pRtnNetMonitorTaskObjectSet->DeviceGroup_ID:"<<pRtnNetMonitorTaskObjectSet->DeviceGroup_ID<< endl;
  cout << "on pRtnNetMonitorTaskObjectSet->Device_ID:"<<pRtnNetMonitorTaskObjectSet->Device_ID<< endl;
  cout << "on pRtnNetMonitorTaskObjectSet->DataCenter:"<<pRtnNetMonitorTaskObjectSet->DataCenter<< endl;
  CShfeFtdcRtnNetMonitorTaskObjectSetField* pNewRtnNetMonitorTaskObjectSet =new CShfeFtdcRtnNetMonitorTaskObjectSetField;
  memcpy(pNewRtnNetMonitorTaskObjectSet,pRtnNetMonitorTaskObjectSet,sizeof(CShfeFtdcRtnNetMonitorTaskObjectSetField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorTaskObjectSet;
  asyncOnRtnNetMonitorTaskObjectSetTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetMonitorTaskObjectSetTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetPartyLinkInfoTopic(CShfeFtdcRspQryNetPartyLinkInfoField *pRspQryNetPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetPartyLinkInfo->OperationType:"<<pRspQryNetPartyLinkInfo->OperationType<< endl;
  cout << "on pRspQryNetPartyLinkInfo->ID:"<<pRspQryNetPartyLinkInfo->ID<< endl;
  cout << "on pRspQryNetPartyLinkInfo->MEMBER_NO:"<<pRspQryNetPartyLinkInfo->MEMBER_NO<< endl;
  cout << "on pRspQryNetPartyLinkInfo->MEMBER_NAME:"<<pRspQryNetPartyLinkInfo->MEMBER_NAME<< endl;
  cout << "on pRspQryNetPartyLinkInfo->REMOTE_ADDR:"<<pRspQryNetPartyLinkInfo->REMOTE_ADDR<< endl;
  cout << "on pRspQryNetPartyLinkInfo->LOCAL_ADDR:"<<pRspQryNetPartyLinkInfo->LOCAL_ADDR<< endl;
  cout << "on pRspQryNetPartyLinkInfo->ADDRESS:"<<pRspQryNetPartyLinkInfo->ADDRESS<< endl;
  cout << "on pRspQryNetPartyLinkInfo->LINE_STATUS:"<<pRspQryNetPartyLinkInfo->LINE_STATUS<< endl;
  cout << "on pRspQryNetPartyLinkInfo->CONTACT:"<<pRspQryNetPartyLinkInfo->CONTACT<< endl;
  cout << "on pRspQryNetPartyLinkInfo->TELEPHONE:"<<pRspQryNetPartyLinkInfo->TELEPHONE<< endl;
  cout << "on pRspQryNetPartyLinkInfo->MOBILEPHONE:"<<pRspQryNetPartyLinkInfo->MOBILEPHONE<< endl;
  cout << "on pRspQryNetPartyLinkInfo->EMAIL:"<<pRspQryNetPartyLinkInfo->EMAIL<< endl;
  cout << "on pRspQryNetPartyLinkInfo->FAX:"<<pRspQryNetPartyLinkInfo->FAX<< endl;
  cout << "on pRspQryNetPartyLinkInfo->PROVINCE:"<<pRspQryNetPartyLinkInfo->PROVINCE<< endl;
  cout << "on pRspQryNetPartyLinkInfo->DDN_NO:"<<pRspQryNetPartyLinkInfo->DDN_NO<< endl;
  cout << "on pRspQryNetPartyLinkInfo->IN_MODE:"<<pRspQryNetPartyLinkInfo->IN_MODE<< endl;
  cout << "on pRspQryNetPartyLinkInfo->IP_WAN:"<<pRspQryNetPartyLinkInfo->IP_WAN<< endl;
  cout << "on pRspQryNetPartyLinkInfo->IP_LAN:"<<pRspQryNetPartyLinkInfo->IP_LAN<< endl;
  cout << "on pRspQryNetPartyLinkInfo->IPADDR:"<<pRspQryNetPartyLinkInfo->IPADDR<< endl;
  cout << "on pRspQryNetPartyLinkInfo->Interface:"<<pRspQryNetPartyLinkInfo->Interface<< endl;
  cout << "on pRspQryNetPartyLinkInfo->INTERFACE_DATE:"<<pRspQryNetPartyLinkInfo->INTERFACE_DATE<< endl;
  cout << "on pRspQryNetPartyLinkInfo->SOFTWARE:"<<pRspQryNetPartyLinkInfo->SOFTWARE<< endl;
  cout << "on pRspQryNetPartyLinkInfo->FEE_TYPE:"<<pRspQryNetPartyLinkInfo->FEE_TYPE<< endl;
  cout << "on pRspQryNetPartyLinkInfo->SERVICEPROVIDER:"<<pRspQryNetPartyLinkInfo->SERVICEPROVIDER<< endl;
  cout << "on pRspQryNetPartyLinkInfo->IF_ZIYING:"<<pRspQryNetPartyLinkInfo->IF_ZIYING<< endl;
  cout << "on pRspQryNetPartyLinkInfo->IF_TUOGUAN:"<<pRspQryNetPartyLinkInfo->IF_TUOGUAN<< endl;
  cout << "on pRspQryNetPartyLinkInfo->HASOTHER:"<<pRspQryNetPartyLinkInfo->HASOTHER<< endl;
  cout << "on pRspQryNetPartyLinkInfo->SEAT_NO:"<<pRspQryNetPartyLinkInfo->SEAT_NO<< endl;
  cout << "on pRspQryNetPartyLinkInfo->PRO:"<<pRspQryNetPartyLinkInfo->PRO<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetPartyLinkInfoField* pNewRspQryNetPartyLinkInfo =new CShfeFtdcRspQryNetPartyLinkInfoField;
  memcpy(pNewRspQryNetPartyLinkInfo,pRspQryNetPartyLinkInfo,sizeof(CShfeFtdcRspQryNetPartyLinkInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetPartyLinkInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetPartyLinkInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetPartyLinkInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetPartyLinkInfoTopic(CShfeFtdcRtnNetPartyLinkInfoField *pRtnNetPartyLinkInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetPartyLinkInfo->OperationType:"<<pRtnNetPartyLinkInfo->OperationType<< endl;
  cout << "on pRtnNetPartyLinkInfo->ID:"<<pRtnNetPartyLinkInfo->ID<< endl;
  cout << "on pRtnNetPartyLinkInfo->MEMBER_NO:"<<pRtnNetPartyLinkInfo->MEMBER_NO<< endl;
  cout << "on pRtnNetPartyLinkInfo->MEMBER_NAME:"<<pRtnNetPartyLinkInfo->MEMBER_NAME<< endl;
  cout << "on pRtnNetPartyLinkInfo->REMOTE_ADDR:"<<pRtnNetPartyLinkInfo->REMOTE_ADDR<< endl;
  cout << "on pRtnNetPartyLinkInfo->LOCAL_ADDR:"<<pRtnNetPartyLinkInfo->LOCAL_ADDR<< endl;
  cout << "on pRtnNetPartyLinkInfo->ADDRESS:"<<pRtnNetPartyLinkInfo->ADDRESS<< endl;
  cout << "on pRtnNetPartyLinkInfo->LINE_STATUS:"<<pRtnNetPartyLinkInfo->LINE_STATUS<< endl;
  cout << "on pRtnNetPartyLinkInfo->CONTACT:"<<pRtnNetPartyLinkInfo->CONTACT<< endl;
  cout << "on pRtnNetPartyLinkInfo->TELEPHONE:"<<pRtnNetPartyLinkInfo->TELEPHONE<< endl;
  cout << "on pRtnNetPartyLinkInfo->MOBILEPHONE:"<<pRtnNetPartyLinkInfo->MOBILEPHONE<< endl;
  cout << "on pRtnNetPartyLinkInfo->EMAIL:"<<pRtnNetPartyLinkInfo->EMAIL<< endl;
  cout << "on pRtnNetPartyLinkInfo->FAX:"<<pRtnNetPartyLinkInfo->FAX<< endl;
  cout << "on pRtnNetPartyLinkInfo->PROVINCE:"<<pRtnNetPartyLinkInfo->PROVINCE<< endl;
  cout << "on pRtnNetPartyLinkInfo->DDN_NO:"<<pRtnNetPartyLinkInfo->DDN_NO<< endl;
  cout << "on pRtnNetPartyLinkInfo->IN_MODE:"<<pRtnNetPartyLinkInfo->IN_MODE<< endl;
  cout << "on pRtnNetPartyLinkInfo->IP_WAN:"<<pRtnNetPartyLinkInfo->IP_WAN<< endl;
  cout << "on pRtnNetPartyLinkInfo->IP_LAN:"<<pRtnNetPartyLinkInfo->IP_LAN<< endl;
  cout << "on pRtnNetPartyLinkInfo->IPADDR:"<<pRtnNetPartyLinkInfo->IPADDR<< endl;
  cout << "on pRtnNetPartyLinkInfo->Interface:"<<pRtnNetPartyLinkInfo->Interface<< endl;
  cout << "on pRtnNetPartyLinkInfo->INTERFACE_DATE:"<<pRtnNetPartyLinkInfo->INTERFACE_DATE<< endl;
  cout << "on pRtnNetPartyLinkInfo->SOFTWARE:"<<pRtnNetPartyLinkInfo->SOFTWARE<< endl;
  cout << "on pRtnNetPartyLinkInfo->FEE_TYPE:"<<pRtnNetPartyLinkInfo->FEE_TYPE<< endl;
  cout << "on pRtnNetPartyLinkInfo->SERVICEPROVIDER:"<<pRtnNetPartyLinkInfo->SERVICEPROVIDER<< endl;
  cout << "on pRtnNetPartyLinkInfo->IF_ZIYING:"<<pRtnNetPartyLinkInfo->IF_ZIYING<< endl;
  cout << "on pRtnNetPartyLinkInfo->IF_TUOGUAN:"<<pRtnNetPartyLinkInfo->IF_TUOGUAN<< endl;
  cout << "on pRtnNetPartyLinkInfo->HASOTHER:"<<pRtnNetPartyLinkInfo->HASOTHER<< endl;
  cout << "on pRtnNetPartyLinkInfo->SEAT_NO:"<<pRtnNetPartyLinkInfo->SEAT_NO<< endl;
  cout << "on pRtnNetPartyLinkInfo->PRO:"<<pRtnNetPartyLinkInfo->PRO<< endl;
  CShfeFtdcRtnNetPartyLinkInfoField* pNewRtnNetPartyLinkInfo =new CShfeFtdcRtnNetPartyLinkInfoField;
  memcpy(pNewRtnNetPartyLinkInfo,pRtnNetPartyLinkInfo,sizeof(CShfeFtdcRtnNetPartyLinkInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetPartyLinkInfo;
  asyncOnRtnNetPartyLinkInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetPartyLinkInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetMonitorActionAttrTopic(CShfeFtdcRspQryNetMonitorActionAttrField *pRspQryNetMonitorActionAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetMonitorActionAttr->OperationType:"<<pRspQryNetMonitorActionAttr->OperationType<< endl;
  cout << "on pRspQryNetMonitorActionAttr->ID:"<<pRspQryNetMonitorActionAttr->ID<< endl;
  cout << "on pRspQryNetMonitorActionAttr->ActionGroup_ID:"<<pRspQryNetMonitorActionAttr->ActionGroup_ID<< endl;
  cout << "on pRspQryNetMonitorActionAttr->MonitorAttr_ID:"<<pRspQryNetMonitorActionAttr->MonitorAttr_ID<< endl;
  cout << "on pRspQryNetMonitorActionAttr->MonitorAttrName:"<<pRspQryNetMonitorActionAttr->MonitorAttrName<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetMonitorActionAttrField* pNewRspQryNetMonitorActionAttr =new CShfeFtdcRspQryNetMonitorActionAttrField;
  memcpy(pNewRspQryNetMonitorActionAttr,pRspQryNetMonitorActionAttr,sizeof(CShfeFtdcRspQryNetMonitorActionAttrField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorActionAttr;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorActionAttrTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetMonitorActionAttrTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetMonitorActionAttrTopic(CShfeFtdcRtnNetMonitorActionAttrField *pRtnNetMonitorActionAttr)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetMonitorActionAttr->OperationType:"<<pRtnNetMonitorActionAttr->OperationType<< endl;
  cout << "on pRtnNetMonitorActionAttr->ID:"<<pRtnNetMonitorActionAttr->ID<< endl;
  cout << "on pRtnNetMonitorActionAttr->ActionGroup_ID:"<<pRtnNetMonitorActionAttr->ActionGroup_ID<< endl;
  cout << "on pRtnNetMonitorActionAttr->MonitorAttr_ID:"<<pRtnNetMonitorActionAttr->MonitorAttr_ID<< endl;
  cout << "on pRtnNetMonitorActionAttr->MonitorAttrName:"<<pRtnNetMonitorActionAttr->MonitorAttrName<< endl;
  CShfeFtdcRtnNetMonitorActionAttrField* pNewRtnNetMonitorActionAttr =new CShfeFtdcRtnNetMonitorActionAttrField;
  memcpy(pNewRtnNetMonitorActionAttr,pRtnNetMonitorActionAttr,sizeof(CShfeFtdcRtnNetMonitorActionAttrField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorActionAttr;
  asyncOnRtnNetMonitorActionAttrTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetMonitorActionAttrTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetModuleTopic(CShfeFtdcRspQryNetModuleField *pRspQryNetModule, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetModule->OperationType:"<<pRspQryNetModule->OperationType<< endl;
  cout << "on pRspQryNetModule->ID:"<<pRspQryNetModule->ID<< endl;
  cout << "on pRspQryNetModule->ObjectID:"<<pRspQryNetModule->ObjectID<< endl;
  cout << "on pRspQryNetModule->MonitorType_ID:"<<pRspQryNetModule->MonitorType_ID<< endl;
  cout << "on pRspQryNetModule->DeviceID:"<<pRspQryNetModule->DeviceID<< endl;
  cout << "on pRspQryNetModule->DeviceObjectID:"<<pRspQryNetModule->DeviceObjectID<< endl;
  cout << "on pRspQryNetModule->Name:"<<pRspQryNetModule->Name<< endl;
  cout << "on pRspQryNetModule->Description:"<<pRspQryNetModule->Description<< endl;
  cout << "on pRspQryNetModule->ModuleIndex:"<<pRspQryNetModule->ModuleIndex<< endl;
  cout << "on pRspQryNetModule->EntPhyIndex:"<<pRspQryNetModule->EntPhyIndex<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetModuleField* pNewRspQryNetModule =new CShfeFtdcRspQryNetModuleField;
  memcpy(pNewRspQryNetModule,pRspQryNetModule,sizeof(CShfeFtdcRspQryNetModuleField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetModule;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetModuleTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetModuleTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetModuleTopic(CShfeFtdcRtnNetModuleField *pRtnNetModule)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetModule->OperationType:"<<pRtnNetModule->OperationType<< endl;
  cout << "on pRtnNetModule->ID:"<<pRtnNetModule->ID<< endl;
  cout << "on pRtnNetModule->ObjectID:"<<pRtnNetModule->ObjectID<< endl;
  cout << "on pRtnNetModule->MonitorType_ID:"<<pRtnNetModule->MonitorType_ID<< endl;
  cout << "on pRtnNetModule->DeviceID:"<<pRtnNetModule->DeviceID<< endl;
  cout << "on pRtnNetModule->DeviceObjectID:"<<pRtnNetModule->DeviceObjectID<< endl;
  cout << "on pRtnNetModule->Name:"<<pRtnNetModule->Name<< endl;
  cout << "on pRtnNetModule->Description:"<<pRtnNetModule->Description<< endl;
  cout << "on pRtnNetModule->ModuleIndex:"<<pRtnNetModule->ModuleIndex<< endl;
  cout << "on pRtnNetModule->EntPhyIndex:"<<pRtnNetModule->EntPhyIndex<< endl;
  CShfeFtdcRtnNetModuleField* pNewRtnNetModule =new CShfeFtdcRtnNetModuleField;
  memcpy(pNewRtnNetModule,pRtnNetModule,sizeof(CShfeFtdcRtnNetModuleField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetModule;
  asyncOnRtnNetModuleTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetModuleTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetEventExprTopic(CShfeFtdcRspQryNetEventExprField *pRspQryNetEventExpr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetEventExpr->OperationType:"<<pRspQryNetEventExpr->OperationType<< endl;
  cout << "on pRspQryNetEventExpr->ID:"<<pRspQryNetEventExpr->ID<< endl;
  cout << "on pRspQryNetEventExpr->CNAME:"<<pRspQryNetEventExpr->CNAME<< endl;
  cout << "on pRspQryNetEventExpr->ENAME:"<<pRspQryNetEventExpr->ENAME<< endl;
  cout << "on pRspQryNetEventExpr->WarningLEVEL:"<<pRspQryNetEventExpr->WarningLEVEL<< endl;
  cout << "on pRspQryNetEventExpr->EventTypeID:"<<pRspQryNetEventExpr->EventTypeID<< endl;
  cout << "on pRspQryNetEventExpr->SubEventTypeID:"<<pRspQryNetEventExpr->SubEventTypeID<< endl;
  cout << "on pRspQryNetEventExpr->GIVEUPTIME:"<<pRspQryNetEventExpr->GIVEUPTIME<< endl;
  cout << "on pRspQryNetEventExpr->CONTROL:"<<pRspQryNetEventExpr->CONTROL<< endl;
  cout << "on pRspQryNetEventExpr->EXPR:"<<pRspQryNetEventExpr->EXPR<< endl;
  cout << "on pRspQryNetEventExpr->BRIEF:"<<pRspQryNetEventExpr->BRIEF<< endl;
  cout << "on pRspQryNetEventExpr->DISCRIPTION:"<<pRspQryNetEventExpr->DISCRIPTION<< endl;
  cout << "on pRspQryNetEventExpr->MSGGROUP_ID:"<<pRspQryNetEventExpr->MSGGROUP_ID<< endl;
  cout << "on pRspQryNetEventExpr->ADMINGROUP_ID:"<<pRspQryNetEventExpr->ADMINGROUP_ID<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetEventExprField* pNewRspQryNetEventExpr =new CShfeFtdcRspQryNetEventExprField;
  memcpy(pNewRspQryNetEventExpr,pRspQryNetEventExpr,sizeof(CShfeFtdcRspQryNetEventExprField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetEventExpr;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetEventExprTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetEventExprTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetEventExprTopic(CShfeFtdcRtnNetEventExprField *pRtnNetEventExpr)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetEventExpr->OperationType:"<<pRtnNetEventExpr->OperationType<< endl;
  cout << "on pRtnNetEventExpr->ID:"<<pRtnNetEventExpr->ID<< endl;
  cout << "on pRtnNetEventExpr->CNAME:"<<pRtnNetEventExpr->CNAME<< endl;
  cout << "on pRtnNetEventExpr->ENAME:"<<pRtnNetEventExpr->ENAME<< endl;
  cout << "on pRtnNetEventExpr->WarningLEVEL:"<<pRtnNetEventExpr->WarningLEVEL<< endl;
  cout << "on pRtnNetEventExpr->EventTypeID:"<<pRtnNetEventExpr->EventTypeID<< endl;
  cout << "on pRtnNetEventExpr->SubEventTypeID:"<<pRtnNetEventExpr->SubEventTypeID<< endl;
  cout << "on pRtnNetEventExpr->GIVEUPTIME:"<<pRtnNetEventExpr->GIVEUPTIME<< endl;
  cout << "on pRtnNetEventExpr->CONTROL:"<<pRtnNetEventExpr->CONTROL<< endl;
  cout << "on pRtnNetEventExpr->EXPR:"<<pRtnNetEventExpr->EXPR<< endl;
  cout << "on pRtnNetEventExpr->BRIEF:"<<pRtnNetEventExpr->BRIEF<< endl;
  cout << "on pRtnNetEventExpr->DISCRIPTION:"<<pRtnNetEventExpr->DISCRIPTION<< endl;
  cout << "on pRtnNetEventExpr->MSGGROUP_ID:"<<pRtnNetEventExpr->MSGGROUP_ID<< endl;
  cout << "on pRtnNetEventExpr->ADMINGROUP_ID:"<<pRtnNetEventExpr->ADMINGROUP_ID<< endl;
  CShfeFtdcRtnNetEventExprField* pNewRtnNetEventExpr =new CShfeFtdcRtnNetEventExprField;
  memcpy(pNewRtnNetEventExpr,pRtnNetEventExpr,sizeof(CShfeFtdcRtnNetEventExprField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetEventExpr;
  asyncOnRtnNetEventExprTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetEventExprTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetEventTypeTopic(CShfeFtdcRspQryNetEventTypeField *pRspQryNetEventType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetEventType->OperationType:"<<pRspQryNetEventType->OperationType<< endl;
  cout << "on pRspQryNetEventType->ID:"<<pRspQryNetEventType->ID<< endl;
  cout << "on pRspQryNetEventType->CName:"<<pRspQryNetEventType->CName<< endl;
  cout << "on pRspQryNetEventType->EName:"<<pRspQryNetEventType->EName<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetEventTypeField* pNewRspQryNetEventType =new CShfeFtdcRspQryNetEventTypeField;
  memcpy(pNewRspQryNetEventType,pRspQryNetEventType,sizeof(CShfeFtdcRspQryNetEventTypeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetEventType;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetEventTypeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetEventTypeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetEventTypeTopic(CShfeFtdcRtnNetEventTypeField *pRtnNetEventType)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetEventType->OperationType:"<<pRtnNetEventType->OperationType<< endl;
  cout << "on pRtnNetEventType->ID:"<<pRtnNetEventType->ID<< endl;
  cout << "on pRtnNetEventType->CName:"<<pRtnNetEventType->CName<< endl;
  cout << "on pRtnNetEventType->EName:"<<pRtnNetEventType->EName<< endl;
  CShfeFtdcRtnNetEventTypeField* pNewRtnNetEventType =new CShfeFtdcRtnNetEventTypeField;
  memcpy(pNewRtnNetEventType,pRtnNetEventType,sizeof(CShfeFtdcRtnNetEventTypeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetEventType;
  asyncOnRtnNetEventTypeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetEventTypeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetSubEventTypeTopic(CShfeFtdcRspQryNetSubEventTypeField *pRspQryNetSubEventType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetSubEventType->OperationType:"<<pRspQryNetSubEventType->OperationType<< endl;
  cout << "on pRspQryNetSubEventType->ID:"<<pRspQryNetSubEventType->ID<< endl;
  cout << "on pRspQryNetSubEventType->CName:"<<pRspQryNetSubEventType->CName<< endl;
  cout << "on pRspQryNetSubEventType->EName:"<<pRspQryNetSubEventType->EName<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetSubEventTypeField* pNewRspQryNetSubEventType =new CShfeFtdcRspQryNetSubEventTypeField;
  memcpy(pNewRspQryNetSubEventType,pRspQryNetSubEventType,sizeof(CShfeFtdcRspQryNetSubEventTypeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetSubEventType;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetSubEventTypeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetSubEventTypeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetSubEventTypeTopic(CShfeFtdcRtnNetSubEventTypeField *pRtnNetSubEventType)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetSubEventType->OperationType:"<<pRtnNetSubEventType->OperationType<< endl;
  cout << "on pRtnNetSubEventType->ID:"<<pRtnNetSubEventType->ID<< endl;
  cout << "on pRtnNetSubEventType->CName:"<<pRtnNetSubEventType->CName<< endl;
  cout << "on pRtnNetSubEventType->EName:"<<pRtnNetSubEventType->EName<< endl;
  CShfeFtdcRtnNetSubEventTypeField* pNewRtnNetSubEventType =new CShfeFtdcRtnNetSubEventTypeField;
  memcpy(pNewRtnNetSubEventType,pRtnNetSubEventType,sizeof(CShfeFtdcRtnNetSubEventTypeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetSubEventType;
  asyncOnRtnNetSubEventTypeTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetSubEventTypeTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetEventLevelTopic(CShfeFtdcRspQryNetEventLevelField *pRspQryNetEventLevel, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetEventLevel->OperationType:"<<pRspQryNetEventLevel->OperationType<< endl;
  cout << "on pRspQryNetEventLevel->ID:"<<pRspQryNetEventLevel->ID<< endl;
  cout << "on pRspQryNetEventLevel->CName:"<<pRspQryNetEventLevel->CName<< endl;
  cout << "on pRspQryNetEventLevel->EName:"<<pRspQryNetEventLevel->EName<< endl;
  cout << "on pRspQryNetEventLevel->DISCRIPTION:"<<pRspQryNetEventLevel->DISCRIPTION<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetEventLevelField* pNewRspQryNetEventLevel =new CShfeFtdcRspQryNetEventLevelField;
  memcpy(pNewRspQryNetEventLevel,pRspQryNetEventLevel,sizeof(CShfeFtdcRspQryNetEventLevelField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetEventLevel;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetEventLevelTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetEventLevelTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetEventLevelTopic(CShfeFtdcRtnNetEventLevelField *pRtnNetEventLevel)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetEventLevel->OperationType:"<<pRtnNetEventLevel->OperationType<< endl;
  cout << "on pRtnNetEventLevel->ID:"<<pRtnNetEventLevel->ID<< endl;
  cout << "on pRtnNetEventLevel->CName:"<<pRtnNetEventLevel->CName<< endl;
  cout << "on pRtnNetEventLevel->EName:"<<pRtnNetEventLevel->EName<< endl;
  cout << "on pRtnNetEventLevel->DISCRIPTION:"<<pRtnNetEventLevel->DISCRIPTION<< endl;
  CShfeFtdcRtnNetEventLevelField* pNewRtnNetEventLevel =new CShfeFtdcRtnNetEventLevelField;
  memcpy(pNewRtnNetEventLevel,pRtnNetEventLevel,sizeof(CShfeFtdcRtnNetEventLevelField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetEventLevel;
  asyncOnRtnNetEventLevelTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetEventLevelTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetMonitorTaskStatusResultTopic(CShfeFtdcRspQryNetMonitorTaskStatusResultField *pRspQryNetMonitorTaskStatusResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetMonitorTaskStatusResult->OperationType:"<<pRspQryNetMonitorTaskStatusResult->OperationType<< endl;
  cout << "on pRspQryNetMonitorTaskStatusResult->ObjectID:"<<pRspQryNetMonitorTaskStatusResult->ObjectID<< endl;
  cout << "on pRspQryNetMonitorTaskStatusResult->Task_ID:"<<pRspQryNetMonitorTaskStatusResult->Task_ID<< endl;
  cout << "on pRspQryNetMonitorTaskStatusResult->OperateTime:"<<pRspQryNetMonitorTaskStatusResult->OperateTime<< endl;
  cout << "on pRspQryNetMonitorTaskStatusResult->MonDate:"<<pRspQryNetMonitorTaskStatusResult->MonDate<< endl;
  cout << "on pRspQryNetMonitorTaskStatusResult->MonTime:"<<pRspQryNetMonitorTaskStatusResult->MonTime<< endl;
  cout << "on pRspQryNetMonitorTaskStatusResult->Flag:"<<pRspQryNetMonitorTaskStatusResult->Flag<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetMonitorTaskStatusResultField* pNewRspQryNetMonitorTaskStatusResult =new CShfeFtdcRspQryNetMonitorTaskStatusResultField;
  memcpy(pNewRspQryNetMonitorTaskStatusResult,pRspQryNetMonitorTaskStatusResult,sizeof(CShfeFtdcRspQryNetMonitorTaskStatusResultField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorTaskStatusResult;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorTaskStatusResultTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetMonitorTaskStatusResultTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetMonitorTaskStatusResultTopic(CShfeFtdcRtnNetMonitorTaskStatusResultField *pRtnNetMonitorTaskStatusResult)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetMonitorTaskStatusResult->OperationType:"<<pRtnNetMonitorTaskStatusResult->OperationType<< endl;
  cout << "on pRtnNetMonitorTaskStatusResult->ObjectID:"<<pRtnNetMonitorTaskStatusResult->ObjectID<< endl;
  cout << "on pRtnNetMonitorTaskStatusResult->Task_ID:"<<pRtnNetMonitorTaskStatusResult->Task_ID<< endl;
  cout << "on pRtnNetMonitorTaskStatusResult->OperateTime:"<<pRtnNetMonitorTaskStatusResult->OperateTime<< endl;
  cout << "on pRtnNetMonitorTaskStatusResult->MonDate:"<<pRtnNetMonitorTaskStatusResult->MonDate<< endl;
  cout << "on pRtnNetMonitorTaskStatusResult->MonTime:"<<pRtnNetMonitorTaskStatusResult->MonTime<< endl;
  cout << "on pRtnNetMonitorTaskStatusResult->Flag:"<<pRtnNetMonitorTaskStatusResult->Flag<< endl;
  CShfeFtdcRtnNetMonitorTaskStatusResultField* pNewRtnNetMonitorTaskStatusResult =new CShfeFtdcRtnNetMonitorTaskStatusResultField;
  memcpy(pNewRtnNetMonitorTaskStatusResult,pRtnNetMonitorTaskStatusResult,sizeof(CShfeFtdcRtnNetMonitorTaskStatusResultField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorTaskStatusResult;
  asyncOnRtnNetMonitorTaskStatusResultTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetMonitorTaskStatusResultTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetCfgFileTopic(CShfeFtdcRspQryNetCfgFileField *pRspQryNetCfgFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetCfgFile->OperationType:"<<pRspQryNetCfgFile->OperationType<< endl;
  cout << "on pRspQryNetCfgFile->ObjectID:"<<pRspQryNetCfgFile->ObjectID<< endl;
  cout << "on pRspQryNetCfgFile->MonDate:"<<pRspQryNetCfgFile->MonDate<< endl;
  cout << "on pRspQryNetCfgFile->MonTime:"<<pRspQryNetCfgFile->MonTime<< endl;
  cout << "on pRspQryNetCfgFile->CfgFileName:"<<pRspQryNetCfgFile->CfgFileName<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetCfgFileField* pNewRspQryNetCfgFile =new CShfeFtdcRspQryNetCfgFileField;
  memcpy(pNewRspQryNetCfgFile,pRspQryNetCfgFile,sizeof(CShfeFtdcRspQryNetCfgFileField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetCfgFile;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetCfgFileTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetCfgFileTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetCfgFileTopic(CShfeFtdcRtnNetCfgFileField *pRtnNetCfgFile)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetCfgFile->OperationType:"<<pRtnNetCfgFile->OperationType<< endl;
  cout << "on pRtnNetCfgFile->ObjectID:"<<pRtnNetCfgFile->ObjectID<< endl;
  cout << "on pRtnNetCfgFile->MonDate:"<<pRtnNetCfgFile->MonDate<< endl;
  cout << "on pRtnNetCfgFile->MonTime:"<<pRtnNetCfgFile->MonTime<< endl;
  cout << "on pRtnNetCfgFile->CfgFileName:"<<pRtnNetCfgFile->CfgFileName<< endl;
  CShfeFtdcRtnNetCfgFileField* pNewRtnNetCfgFile =new CShfeFtdcRtnNetCfgFileField;
  memcpy(pNewRtnNetCfgFile,pRtnNetCfgFile,sizeof(CShfeFtdcRtnNetCfgFileField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetCfgFile;
  asyncOnRtnNetCfgFileTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetCfgFileTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetMonitorDeviceTaskTopic(CShfeFtdcRspQryNetMonitorDeviceTaskField *pRspQryNetMonitorDeviceTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetMonitorDeviceTask->OperationType:"<<pRspQryNetMonitorDeviceTask->OperationType<< endl;
  cout << "on pRspQryNetMonitorDeviceTask->ID:"<<pRspQryNetMonitorDeviceTask->ID<< endl;
  cout << "on pRspQryNetMonitorDeviceTask->ObjectID:"<<pRspQryNetMonitorDeviceTask->ObjectID<< endl;
  cout << "on pRspQryNetMonitorDeviceTask->IPAddress:"<<pRspQryNetMonitorDeviceTask->IPAddress<< endl;
  cout << "on pRspQryNetMonitorDeviceTask->Manufactory_ID:"<<pRspQryNetMonitorDeviceTask->Manufactory_ID<< endl;
  cout << "on pRspQryNetMonitorDeviceTask->InstructChain:"<<pRspQryNetMonitorDeviceTask->InstructChain<< endl;
  cout << "on pRspQryNetMonitorDeviceTask->InstructAlias:"<<pRspQryNetMonitorDeviceTask->InstructAlias<< endl;
  cout << "on pRspQryNetMonitorDeviceTask->InstructArgs:"<<pRspQryNetMonitorDeviceTask->InstructArgs<< endl;
  cout << "on pRspQryNetMonitorDeviceTask->DefParamChain:"<<pRspQryNetMonitorDeviceTask->DefParamChain<< endl;
  cout << "on pRspQryNetMonitorDeviceTask->Flag:"<<pRspQryNetMonitorDeviceTask->Flag<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetMonitorDeviceTaskField* pNewRspQryNetMonitorDeviceTask =new CShfeFtdcRspQryNetMonitorDeviceTaskField;
  memcpy(pNewRspQryNetMonitorDeviceTask,pRspQryNetMonitorDeviceTask,sizeof(CShfeFtdcRspQryNetMonitorDeviceTaskField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorDeviceTask;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorDeviceTaskTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetMonitorDeviceTaskTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetMonitorDeviceTaskTopic(CShfeFtdcRtnNetMonitorDeviceTaskField *pRtnNetMonitorDeviceTask)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetMonitorDeviceTask->OperationType:"<<pRtnNetMonitorDeviceTask->OperationType<< endl;
  cout << "on pRtnNetMonitorDeviceTask->ID:"<<pRtnNetMonitorDeviceTask->ID<< endl;
  cout << "on pRtnNetMonitorDeviceTask->ObjectID:"<<pRtnNetMonitorDeviceTask->ObjectID<< endl;
  cout << "on pRtnNetMonitorDeviceTask->IPAddress:"<<pRtnNetMonitorDeviceTask->IPAddress<< endl;
  cout << "on pRtnNetMonitorDeviceTask->Manufactory_ID:"<<pRtnNetMonitorDeviceTask->Manufactory_ID<< endl;
  cout << "on pRtnNetMonitorDeviceTask->InstructChain:"<<pRtnNetMonitorDeviceTask->InstructChain<< endl;
  cout << "on pRtnNetMonitorDeviceTask->InstructAlias:"<<pRtnNetMonitorDeviceTask->InstructAlias<< endl;
  cout << "on pRtnNetMonitorDeviceTask->InstructArgs:"<<pRtnNetMonitorDeviceTask->InstructArgs<< endl;
  cout << "on pRtnNetMonitorDeviceTask->DefParamChain:"<<pRtnNetMonitorDeviceTask->DefParamChain<< endl;
  cout << "on pRtnNetMonitorDeviceTask->Flag:"<<pRtnNetMonitorDeviceTask->Flag<< endl;
  CShfeFtdcRtnNetMonitorDeviceTaskField* pNewRtnNetMonitorDeviceTask =new CShfeFtdcRtnNetMonitorDeviceTaskField;
  memcpy(pNewRtnNetMonitorDeviceTask,pRtnNetMonitorDeviceTask,sizeof(CShfeFtdcRtnNetMonitorDeviceTaskField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorDeviceTask;
  asyncOnRtnNetMonitorDeviceTaskTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetMonitorDeviceTaskTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetMonitorTaskInstAttrsTopic(CShfeFtdcRspQryNetMonitorTaskInstAttrsField *pRspQryNetMonitorTaskInstAttrs, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetMonitorTaskInstAttrs->OperationType:"<<pRspQryNetMonitorTaskInstAttrs->OperationType<< endl;
  cout << "on pRspQryNetMonitorTaskInstAttrs->ID:"<<pRspQryNetMonitorTaskInstAttrs->ID<< endl;
  cout << "on pRspQryNetMonitorTaskInstAttrs->Manufactory_ID:"<<pRspQryNetMonitorTaskInstAttrs->Manufactory_ID<< endl;
  cout << "on pRspQryNetMonitorTaskInstAttrs->InstructAlias:"<<pRspQryNetMonitorTaskInstAttrs->InstructAlias<< endl;
  cout << "on pRspQryNetMonitorTaskInstAttrs->DEVICETYPE:"<<pRspQryNetMonitorTaskInstAttrs->DEVICETYPE<< endl;
  cout << "on pRspQryNetMonitorTaskInstAttrs->AttrsChain:"<<pRspQryNetMonitorTaskInstAttrs->AttrsChain<< endl;
  cout << "on pRspQryNetMonitorTaskInstAttrs->DefRegularChain:"<<pRspQryNetMonitorTaskInstAttrs->DefRegularChain<< endl;
  cout << "on pRspQryNetMonitorTaskInstAttrs->DefParamChain:"<<pRspQryNetMonitorTaskInstAttrs->DefParamChain<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetMonitorTaskInstAttrsField* pNewRspQryNetMonitorTaskInstAttrs =new CShfeFtdcRspQryNetMonitorTaskInstAttrsField;
  memcpy(pNewRspQryNetMonitorTaskInstAttrs,pRspQryNetMonitorTaskInstAttrs,sizeof(CShfeFtdcRspQryNetMonitorTaskInstAttrsField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorTaskInstAttrs;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorTaskInstAttrsTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetMonitorTaskInstAttrsTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetMonitorTaskInstAttrsTopic(CShfeFtdcRtnNetMonitorTaskInstAttrsField *pRtnNetMonitorTaskInstAttrs)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetMonitorTaskInstAttrs->OperationType:"<<pRtnNetMonitorTaskInstAttrs->OperationType<< endl;
  cout << "on pRtnNetMonitorTaskInstAttrs->ID:"<<pRtnNetMonitorTaskInstAttrs->ID<< endl;
  cout << "on pRtnNetMonitorTaskInstAttrs->Manufactory_ID:"<<pRtnNetMonitorTaskInstAttrs->Manufactory_ID<< endl;
  cout << "on pRtnNetMonitorTaskInstAttrs->InstructAlias:"<<pRtnNetMonitorTaskInstAttrs->InstructAlias<< endl;
  cout << "on pRtnNetMonitorTaskInstAttrs->DEVICETYPE:"<<pRtnNetMonitorTaskInstAttrs->DEVICETYPE<< endl;
  cout << "on pRtnNetMonitorTaskInstAttrs->AttrsChain:"<<pRtnNetMonitorTaskInstAttrs->AttrsChain<< endl;
  cout << "on pRtnNetMonitorTaskInstAttrs->DefRegularChain:"<<pRtnNetMonitorTaskInstAttrs->DefRegularChain<< endl;
  cout << "on pRtnNetMonitorTaskInstAttrs->DefParamChain:"<<pRtnNetMonitorTaskInstAttrs->DefParamChain<< endl;
  CShfeFtdcRtnNetMonitorTaskInstAttrsField* pNewRtnNetMonitorTaskInstAttrs =new CShfeFtdcRtnNetMonitorTaskInstAttrsField;
  memcpy(pNewRtnNetMonitorTaskInstAttrs,pRtnNetMonitorTaskInstAttrs,sizeof(CShfeFtdcRtnNetMonitorTaskInstAttrsField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorTaskInstAttrs;
  asyncOnRtnNetMonitorTaskInstAttrsTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetMonitorTaskInstAttrsTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryFileGeneralOperTopic(CShfeFtdcRspQryFileGeneralOperField *pRspQryFileGeneralOper, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryFileGeneralOper->OperationType:"<<pRspQryFileGeneralOper->OperationType<< endl;
  cout << "on pRspQryFileGeneralOper->FileName:"<<pRspQryFileGeneralOper->FileName<< endl;
  cout << "on pRspQryFileGeneralOper->Version:"<<pRspQryFileGeneralOper->Version<< endl;
  cout << "on pRspQryFileGeneralOper->SubVersion:"<<pRspQryFileGeneralOper->SubVersion<< endl;
  cout << "on pRspQryFileGeneralOper->MonDate:"<<pRspQryFileGeneralOper->MonDate<< endl;
  cout << "on pRspQryFileGeneralOper->MonTime:"<<pRspQryFileGeneralOper->MonTime<< endl;
  cout << "on pRspQryFileGeneralOper->UserName:"<<pRspQryFileGeneralOper->UserName<< endl;
  cout << "on pRspQryFileGeneralOper->OperType:"<<pRspQryFileGeneralOper->OperType<< endl;
  cout << "on pRspQryFileGeneralOper->OperResult:"<<pRspQryFileGeneralOper->OperResult<< endl;
  cout << "on pRspQryFileGeneralOper->Comments:"<<pRspQryFileGeneralOper->Comments<< endl;
  cout << "on pRspQryFileGeneralOper->Offset:"<<pRspQryFileGeneralOper->Offset<< endl;
  cout << "on pRspQryFileGeneralOper->Length:"<<pRspQryFileGeneralOper->Length<< endl;
  cout << "on pRspQryFileGeneralOper->FileContent:"<<pRspQryFileGeneralOper->FileContent<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryFileGeneralOperField* pNewRspQryFileGeneralOper =new CShfeFtdcRspQryFileGeneralOperField;
  memcpy(pNewRspQryFileGeneralOper,pRspQryFileGeneralOper,sizeof(CShfeFtdcRspQryFileGeneralOperField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryFileGeneralOper;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryFileGeneralOperTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryFileGeneralOperTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnFileGeneralOperTopic(CShfeFtdcRtnFileGeneralOperField *pRtnFileGeneralOper)
{
  cout << "ok"<< endl;
  cout << "on pRtnFileGeneralOper->OperationType:"<<pRtnFileGeneralOper->OperationType<< endl;
  cout << "on pRtnFileGeneralOper->FileName:"<<pRtnFileGeneralOper->FileName<< endl;
  cout << "on pRtnFileGeneralOper->Version:"<<pRtnFileGeneralOper->Version<< endl;
  cout << "on pRtnFileGeneralOper->SubVersion:"<<pRtnFileGeneralOper->SubVersion<< endl;
  cout << "on pRtnFileGeneralOper->MonDate:"<<pRtnFileGeneralOper->MonDate<< endl;
  cout << "on pRtnFileGeneralOper->MonTime:"<<pRtnFileGeneralOper->MonTime<< endl;
  cout << "on pRtnFileGeneralOper->UserName:"<<pRtnFileGeneralOper->UserName<< endl;
  cout << "on pRtnFileGeneralOper->OperType:"<<pRtnFileGeneralOper->OperType<< endl;
  cout << "on pRtnFileGeneralOper->OperResult:"<<pRtnFileGeneralOper->OperResult<< endl;
  cout << "on pRtnFileGeneralOper->Comments:"<<pRtnFileGeneralOper->Comments<< endl;
  cout << "on pRtnFileGeneralOper->Offset:"<<pRtnFileGeneralOper->Offset<< endl;
  cout << "on pRtnFileGeneralOper->Length:"<<pRtnFileGeneralOper->Length<< endl;
  cout << "on pRtnFileGeneralOper->FileContent:"<<pRtnFileGeneralOper->FileContent<< endl;
  CShfeFtdcRtnFileGeneralOperField* pNewRtnFileGeneralOper =new CShfeFtdcRtnFileGeneralOperField;
  memcpy(pNewRtnFileGeneralOper,pRtnFileGeneralOper,sizeof(CShfeFtdcRtnFileGeneralOperField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnFileGeneralOper;
  asyncOnRtnFileGeneralOperTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnFileGeneralOperTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetBaseLineTopic(CShfeFtdcRspQryNetBaseLineField *pRspQryNetBaseLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetBaseLine->OperationType:"<<pRspQryNetBaseLine->OperationType<< endl;
  cout << "on pRspQryNetBaseLine->ID:"<<pRspQryNetBaseLine->ID<< endl;
  cout << "on pRspQryNetBaseLine->MANUFACTORY_ID:"<<pRspQryNetBaseLine->MANUFACTORY_ID<< endl;
  cout << "on pRspQryNetBaseLine->Name:"<<pRspQryNetBaseLine->Name<< endl;
  cout << "on pRspQryNetBaseLine->SerialUsed:"<<pRspQryNetBaseLine->SerialUsed<< endl;
  cout << "on pRspQryNetBaseLine->data:"<<pRspQryNetBaseLine->data<< endl;
  cout << "on pRspQryNetBaseLine->memo:"<<pRspQryNetBaseLine->memo<< endl;
  cout << "on pRspQryNetBaseLine->Flag:"<<pRspQryNetBaseLine->Flag<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetBaseLineField* pNewRspQryNetBaseLine =new CShfeFtdcRspQryNetBaseLineField;
  memcpy(pNewRspQryNetBaseLine,pRspQryNetBaseLine,sizeof(CShfeFtdcRspQryNetBaseLineField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetBaseLine;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetBaseLineTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetBaseLineTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetBaseLineTopic(CShfeFtdcRtnNetBaseLineField *pRtnNetBaseLine)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetBaseLine->OperationType:"<<pRtnNetBaseLine->OperationType<< endl;
  cout << "on pRtnNetBaseLine->ID:"<<pRtnNetBaseLine->ID<< endl;
  cout << "on pRtnNetBaseLine->MANUFACTORY_ID:"<<pRtnNetBaseLine->MANUFACTORY_ID<< endl;
  cout << "on pRtnNetBaseLine->Name:"<<pRtnNetBaseLine->Name<< endl;
  cout << "on pRtnNetBaseLine->SerialUsed:"<<pRtnNetBaseLine->SerialUsed<< endl;
  cout << "on pRtnNetBaseLine->data:"<<pRtnNetBaseLine->data<< endl;
  cout << "on pRtnNetBaseLine->memo:"<<pRtnNetBaseLine->memo<< endl;
  cout << "on pRtnNetBaseLine->Flag:"<<pRtnNetBaseLine->Flag<< endl;
  CShfeFtdcRtnNetBaseLineField* pNewRtnNetBaseLine =new CShfeFtdcRtnNetBaseLineField;
  memcpy(pNewRtnNetBaseLine,pRtnNetBaseLine,sizeof(CShfeFtdcRtnNetBaseLineField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetBaseLine;
  asyncOnRtnNetBaseLineTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetBaseLineTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetBaseLineTaskTopic(CShfeFtdcRspQryNetBaseLineTaskField *pRspQryNetBaseLineTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetBaseLineTask->OperationType:"<<pRspQryNetBaseLineTask->OperationType<< endl;
  cout << "on pRspQryNetBaseLineTask->ID:"<<pRspQryNetBaseLineTask->ID<< endl;
  cout << "on pRspQryNetBaseLineTask->Name:"<<pRspQryNetBaseLineTask->Name<< endl;
  cout << "on pRspQryNetBaseLineTask->BaseLineIDList:"<<pRspQryNetBaseLineTask->BaseLineIDList<< endl;
  cout << "on pRspQryNetBaseLineTask->DeviceIDList:"<<pRspQryNetBaseLineTask->DeviceIDList<< endl;
  cout << "on pRspQryNetBaseLineTask->GenDate:"<<pRspQryNetBaseLineTask->GenDate<< endl;
  cout << "on pRspQryNetBaseLineTask->GenTime:"<<pRspQryNetBaseLineTask->GenTime<< endl;
  cout << "on pRspQryNetBaseLineTask->GenUser:"<<pRspQryNetBaseLineTask->GenUser<< endl;
  cout << "on pRspQryNetBaseLineTask->memo:"<<pRspQryNetBaseLineTask->memo<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetBaseLineTaskField* pNewRspQryNetBaseLineTask =new CShfeFtdcRspQryNetBaseLineTaskField;
  memcpy(pNewRspQryNetBaseLineTask,pRspQryNetBaseLineTask,sizeof(CShfeFtdcRspQryNetBaseLineTaskField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetBaseLineTask;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetBaseLineTaskTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetBaseLineTaskTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetBaseLineTaskTopic(CShfeFtdcRtnNetBaseLineTaskField *pRtnNetBaseLineTask)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetBaseLineTask->OperationType:"<<pRtnNetBaseLineTask->OperationType<< endl;
  cout << "on pRtnNetBaseLineTask->ID:"<<pRtnNetBaseLineTask->ID<< endl;
  cout << "on pRtnNetBaseLineTask->Name:"<<pRtnNetBaseLineTask->Name<< endl;
  cout << "on pRtnNetBaseLineTask->BaseLineIDList:"<<pRtnNetBaseLineTask->BaseLineIDList<< endl;
  cout << "on pRtnNetBaseLineTask->DeviceIDList:"<<pRtnNetBaseLineTask->DeviceIDList<< endl;
  cout << "on pRtnNetBaseLineTask->GenDate:"<<pRtnNetBaseLineTask->GenDate<< endl;
  cout << "on pRtnNetBaseLineTask->GenTime:"<<pRtnNetBaseLineTask->GenTime<< endl;
  cout << "on pRtnNetBaseLineTask->GenUser:"<<pRtnNetBaseLineTask->GenUser<< endl;
  cout << "on pRtnNetBaseLineTask->memo:"<<pRtnNetBaseLineTask->memo<< endl;
  CShfeFtdcRtnNetBaseLineTaskField* pNewRtnNetBaseLineTask =new CShfeFtdcRtnNetBaseLineTaskField;
  memcpy(pNewRtnNetBaseLineTask,pRtnNetBaseLineTask,sizeof(CShfeFtdcRtnNetBaseLineTaskField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetBaseLineTask;
  asyncOnRtnNetBaseLineTaskTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetBaseLineTaskTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetBaseLineResultTopic(CShfeFtdcRspQryNetBaseLineResultField *pRspQryNetBaseLineResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetBaseLineResult->OperationType:"<<pRspQryNetBaseLineResult->OperationType<< endl;
  cout << "on pRspQryNetBaseLineResult->ID:"<<pRspQryNetBaseLineResult->ID<< endl;
  cout << "on pRspQryNetBaseLineResult->BaseLineName:"<<pRspQryNetBaseLineResult->BaseLineName<< endl;
  cout << "on pRspQryNetBaseLineResult->DeviceObjID:"<<pRspQryNetBaseLineResult->DeviceObjID<< endl;
  cout << "on pRspQryNetBaseLineResult->DeviceIP:"<<pRspQryNetBaseLineResult->DeviceIP<< endl;
  cout << "on pRspQryNetBaseLineResult->Result:"<<pRspQryNetBaseLineResult->Result<< endl;
  cout << "on pRspQryNetBaseLineResult->GenDate:"<<pRspQryNetBaseLineResult->GenDate<< endl;
  cout << "on pRspQryNetBaseLineResult->GenTime:"<<pRspQryNetBaseLineResult->GenTime<< endl;
  cout << "on pRspQryNetBaseLineResult->GenUser:"<<pRspQryNetBaseLineResult->GenUser<< endl;
  cout << "on pRspQryNetBaseLineResult->Flag:"<<pRspQryNetBaseLineResult->Flag<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetBaseLineResultField* pNewRspQryNetBaseLineResult =new CShfeFtdcRspQryNetBaseLineResultField;
  memcpy(pNewRspQryNetBaseLineResult,pRspQryNetBaseLineResult,sizeof(CShfeFtdcRspQryNetBaseLineResultField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetBaseLineResult;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetBaseLineResultTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetBaseLineResultTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetBaseLineResultTopic(CShfeFtdcRtnNetBaseLineResultField *pRtnNetBaseLineResult)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetBaseLineResult->OperationType:"<<pRtnNetBaseLineResult->OperationType<< endl;
  cout << "on pRtnNetBaseLineResult->ID:"<<pRtnNetBaseLineResult->ID<< endl;
  cout << "on pRtnNetBaseLineResult->BaseLineName:"<<pRtnNetBaseLineResult->BaseLineName<< endl;
  cout << "on pRtnNetBaseLineResult->DeviceObjID:"<<pRtnNetBaseLineResult->DeviceObjID<< endl;
  cout << "on pRtnNetBaseLineResult->DeviceIP:"<<pRtnNetBaseLineResult->DeviceIP<< endl;
  cout << "on pRtnNetBaseLineResult->Result:"<<pRtnNetBaseLineResult->Result<< endl;
  cout << "on pRtnNetBaseLineResult->GenDate:"<<pRtnNetBaseLineResult->GenDate<< endl;
  cout << "on pRtnNetBaseLineResult->GenTime:"<<pRtnNetBaseLineResult->GenTime<< endl;
  cout << "on pRtnNetBaseLineResult->GenUser:"<<pRtnNetBaseLineResult->GenUser<< endl;
  cout << "on pRtnNetBaseLineResult->Flag:"<<pRtnNetBaseLineResult->Flag<< endl;
  CShfeFtdcRtnNetBaseLineResultField* pNewRtnNetBaseLineResult =new CShfeFtdcRtnNetBaseLineResultField;
  memcpy(pNewRtnNetBaseLineResult,pRtnNetBaseLineResult,sizeof(CShfeFtdcRtnNetBaseLineResultField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetBaseLineResult;
  asyncOnRtnNetBaseLineResultTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetBaseLineResultTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetPartyLinkStatusInfoTopic(CShfeFtdcRspQryNetPartyLinkStatusInfoField *pRspQryNetPartyLinkStatusInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetPartyLinkStatusInfo->OperationType:"<<pRspQryNetPartyLinkStatusInfo->OperationType<< endl;
  cout << "on pRspQryNetPartyLinkStatusInfo->MonDate:"<<pRspQryNetPartyLinkStatusInfo->MonDate<< endl;
  cout << "on pRspQryNetPartyLinkStatusInfo->MonTime:"<<pRspQryNetPartyLinkStatusInfo->MonTime<< endl;
  cout << "on pRspQryNetPartyLinkStatusInfo->SEAT_NO:"<<pRspQryNetPartyLinkStatusInfo->SEAT_NO<< endl;
  cout << "on pRspQryNetPartyLinkStatusInfo->IPADDR:"<<pRspQryNetPartyLinkStatusInfo->IPADDR<< endl;
  cout << "on pRspQryNetPartyLinkStatusInfo->Interface:"<<pRspQryNetPartyLinkStatusInfo->Interface<< endl;
  cout << "on pRspQryNetPartyLinkStatusInfo->status:"<<pRspQryNetPartyLinkStatusInfo->status<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetPartyLinkStatusInfoField* pNewRspQryNetPartyLinkStatusInfo =new CShfeFtdcRspQryNetPartyLinkStatusInfoField;
  memcpy(pNewRspQryNetPartyLinkStatusInfo,pRspQryNetPartyLinkStatusInfo,sizeof(CShfeFtdcRspQryNetPartyLinkStatusInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetPartyLinkStatusInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetPartyLinkStatusInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetPartyLinkStatusInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetPartyLinkStatusInfoTopic(CShfeFtdcRtnNetPartyLinkStatusInfoField *pRtnNetPartyLinkStatusInfo)
{
  cout << "\n********** SysUserSpi::OnRtnNetPartyLinkStatusInfoTopic: START ********"<< endl;  
  cout << "g_OnRtnNetPartyLinkStatusInfoTopic_Sys_Numb: " << g_OnRtnNetPartyLinkStatusInfoTopic_Sys_Numb++ << endl;
  cout << "on pRtnNetPartyLinkStatusInfo->OperationType:"<<pRtnNetPartyLinkStatusInfo->OperationType<< endl;
  cout << "on pRtnNetPartyLinkStatusInfo->MonDate:"<<pRtnNetPartyLinkStatusInfo->MonDate<< endl;
  cout << "on pRtnNetPartyLinkStatusInfo->MonTime:"<<pRtnNetPartyLinkStatusInfo->MonTime<< endl;
  cout << "on pRtnNetPartyLinkStatusInfo->SEAT_NO:"<<pRtnNetPartyLinkStatusInfo->SEAT_NO<< endl;
  cout << "on pRtnNetPartyLinkStatusInfo->IPADDR:"<<pRtnNetPartyLinkStatusInfo->IPADDR<< endl;
  cout << "on pRtnNetPartyLinkStatusInfo->Interface:"<<pRtnNetPartyLinkStatusInfo->Interface<< endl;
  cout << "on pRtnNetPartyLinkStatusInfo->status:"<<pRtnNetPartyLinkStatusInfo->status<< endl;
  CShfeFtdcRtnNetPartyLinkStatusInfoField* pNewRtnNetPartyLinkStatusInfo =new CShfeFtdcRtnNetPartyLinkStatusInfoField;
  memcpy(pNewRtnNetPartyLinkStatusInfo,pRtnNetPartyLinkStatusInfo,sizeof(CShfeFtdcRtnNetPartyLinkStatusInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetPartyLinkStatusInfo;
  asyncOnRtnNetPartyLinkStatusInfoTopic.data=(void*)&paramArray[0];
  
  uv_mutex_lock(&g_RtnNetPartyLinkStatusInfoTopic_data_mutex);
  
  g_RtnNetPartyLinkStatusInfoTopic_queue.push(paramArray);
  
  uv_mutex_unlock(&g_RtnNetPartyLinkStatusInfoTopic_data_mutex);

  uv_sem_wait(&g_RtnNetPartyLinkStatusInfoTopic_sem);
  uv_mutex_lock(&g_RtnNetPartyLinkStatusInfoTopic_mutex);  
  
  cout <<  "**** g_RtnNetPartyLinkStatusInfoTopic_Sys_index: " << g_RtnNetPartyLinkStatusInfoTopic_Sys_index++ << endl;
  // uv_async_send(&asyncOnRtnNetPartyLinkStatusInfoTopic);
  
  uv_mutex_unlock(&g_RtnNetPartyLinkStatusInfoTopic_mutex);  
   
  cout << "********** SysUserSpi::OnRtnNetPartyLinkStatusInfoTopic: END ********\n"<< endl;
}
void SysUserSpi::OnRspQryNetMemberSDHLineInfoTopic(CShfeFtdcRspQryNetMemberSDHLineInfoField *pRspQryNetMemberSDHLineInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->OperationType:"<<pRspQryNetMemberSDHLineInfo->OperationType<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->ID:"<<pRspQryNetMemberSDHLineInfo->ID<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->SeqNo:"<<pRspQryNetMemberSDHLineInfo->SeqNo<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->MemContractNo:"<<pRspQryNetMemberSDHLineInfo->MemContractNo<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->ApplyPerson:"<<pRspQryNetMemberSDHLineInfo->ApplyPerson<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->MonthlyRental:"<<pRspQryNetMemberSDHLineInfo->MonthlyRental<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->MemberNo:"<<pRspQryNetMemberSDHLineInfo->MemberNo<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->ParticipantName:"<<pRspQryNetMemberSDHLineInfo->ParticipantName<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->ClientManager:"<<pRspQryNetMemberSDHLineInfo->ClientManager<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->Bandwidth:"<<pRspQryNetMemberSDHLineInfo->Bandwidth<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->InterfaceType:"<<pRspQryNetMemberSDHLineInfo->InterfaceType<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->RemoteCircuit:"<<pRspQryNetMemberSDHLineInfo->RemoteCircuit<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->LocalCircuit:"<<pRspQryNetMemberSDHLineInfo->LocalCircuit<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->Remark:"<<pRspQryNetMemberSDHLineInfo->Remark<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->EndALineAddress:"<<pRspQryNetMemberSDHLineInfo->EndALineAddress<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->EndAContact:"<<pRspQryNetMemberSDHLineInfo->EndAContact<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->EndZLineAddress:"<<pRspQryNetMemberSDHLineInfo->EndZLineAddress<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->ContactName:"<<pRspQryNetMemberSDHLineInfo->ContactName<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->TELEPHONE:"<<pRspQryNetMemberSDHLineInfo->TELEPHONE<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->MOBILEPHONE:"<<pRspQryNetMemberSDHLineInfo->MOBILEPHONE<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->IPADDR:"<<pRspQryNetMemberSDHLineInfo->IPADDR<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->Interface:"<<pRspQryNetMemberSDHLineInfo->Interface<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->PROVINCE:"<<pRspQryNetMemberSDHLineInfo->PROVINCE<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->StartPortID:"<<pRspQryNetMemberSDHLineInfo->StartPortID<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->StartJump:"<<pRspQryNetMemberSDHLineInfo->StartJump<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->LINE_STATUS:"<<pRspQryNetMemberSDHLineInfo->LINE_STATUS<< endl;
  cout << "on pRspQryNetMemberSDHLineInfo->DataCenterID:"<<pRspQryNetMemberSDHLineInfo->DataCenterID<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetMemberSDHLineInfoField* pNewRspQryNetMemberSDHLineInfo =new CShfeFtdcRspQryNetMemberSDHLineInfoField;
  memcpy(pNewRspQryNetMemberSDHLineInfo,pRspQryNetMemberSDHLineInfo,sizeof(CShfeFtdcRspQryNetMemberSDHLineInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMemberSDHLineInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMemberSDHLineInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetMemberSDHLineInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetMemberSDHLineInfoTopic(CShfeFtdcRtnNetMemberSDHLineInfoField *pRtnNetMemberSDHLineInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->OperationType:"<<pRtnNetMemberSDHLineInfo->OperationType<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->ID:"<<pRtnNetMemberSDHLineInfo->ID<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->SeqNo:"<<pRtnNetMemberSDHLineInfo->SeqNo<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->MemContractNo:"<<pRtnNetMemberSDHLineInfo->MemContractNo<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->ApplyPerson:"<<pRtnNetMemberSDHLineInfo->ApplyPerson<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->MonthlyRental:"<<pRtnNetMemberSDHLineInfo->MonthlyRental<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->MemberNo:"<<pRtnNetMemberSDHLineInfo->MemberNo<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->ParticipantName:"<<pRtnNetMemberSDHLineInfo->ParticipantName<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->ClientManager:"<<pRtnNetMemberSDHLineInfo->ClientManager<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->Bandwidth:"<<pRtnNetMemberSDHLineInfo->Bandwidth<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->InterfaceType:"<<pRtnNetMemberSDHLineInfo->InterfaceType<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->RemoteCircuit:"<<pRtnNetMemberSDHLineInfo->RemoteCircuit<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->LocalCircuit:"<<pRtnNetMemberSDHLineInfo->LocalCircuit<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->Remark:"<<pRtnNetMemberSDHLineInfo->Remark<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->EndALineAddress:"<<pRtnNetMemberSDHLineInfo->EndALineAddress<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->EndAContact:"<<pRtnNetMemberSDHLineInfo->EndAContact<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->EndZLineAddress:"<<pRtnNetMemberSDHLineInfo->EndZLineAddress<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->ContactName:"<<pRtnNetMemberSDHLineInfo->ContactName<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->TELEPHONE:"<<pRtnNetMemberSDHLineInfo->TELEPHONE<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->MOBILEPHONE:"<<pRtnNetMemberSDHLineInfo->MOBILEPHONE<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->IPADDR:"<<pRtnNetMemberSDHLineInfo->IPADDR<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->Interface:"<<pRtnNetMemberSDHLineInfo->Interface<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->PROVINCE:"<<pRtnNetMemberSDHLineInfo->PROVINCE<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->StartPortID:"<<pRtnNetMemberSDHLineInfo->StartPortID<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->StartJump:"<<pRtnNetMemberSDHLineInfo->StartJump<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->LINE_STATUS:"<<pRtnNetMemberSDHLineInfo->LINE_STATUS<< endl;
  cout << "on pRtnNetMemberSDHLineInfo->DataCenterID:"<<pRtnNetMemberSDHLineInfo->DataCenterID<< endl;
  CShfeFtdcRtnNetMemberSDHLineInfoField* pNewRtnNetMemberSDHLineInfo =new CShfeFtdcRtnNetMemberSDHLineInfoField;
  memcpy(pNewRtnNetMemberSDHLineInfo,pRtnNetMemberSDHLineInfo,sizeof(CShfeFtdcRtnNetMemberSDHLineInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMemberSDHLineInfo;
  asyncOnRtnNetMemberSDHLineInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetMemberSDHLineInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetDDNLinkInfoTopic(CShfeFtdcRspQryNetDDNLinkInfoField *pRspQryNetDDNLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetDDNLinkInfo->OperationType:"<<pRspQryNetDDNLinkInfo->OperationType<< endl;
  cout << "on pRspQryNetDDNLinkInfo->ID:"<<pRspQryNetDDNLinkInfo->ID<< endl;
  cout << "on pRspQryNetDDNLinkInfo->ClientName:"<<pRspQryNetDDNLinkInfo->ClientName<< endl;
  cout << "on pRspQryNetDDNLinkInfo->DDN_NO:"<<pRspQryNetDDNLinkInfo->DDN_NO<< endl;
  cout << "on pRspQryNetDDNLinkInfo->BusinessUnit:"<<pRspQryNetDDNLinkInfo->BusinessUnit<< endl;
  cout << "on pRspQryNetDDNLinkInfo->Bandwidth:"<<pRspQryNetDDNLinkInfo->Bandwidth<< endl;
  cout << "on pRspQryNetDDNLinkInfo->EndAAddress:"<<pRspQryNetDDNLinkInfo->EndAAddress<< endl;
  cout << "on pRspQryNetDDNLinkInfo->EndAContactName:"<<pRspQryNetDDNLinkInfo->EndAContactName<< endl;
  cout << "on pRspQryNetDDNLinkInfo->EndZAddress:"<<pRspQryNetDDNLinkInfo->EndZAddress<< endl;
  cout << "on pRspQryNetDDNLinkInfo->EndZContactName:"<<pRspQryNetDDNLinkInfo->EndZContactName<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetDDNLinkInfoField* pNewRspQryNetDDNLinkInfo =new CShfeFtdcRspQryNetDDNLinkInfoField;
  memcpy(pNewRspQryNetDDNLinkInfo,pRspQryNetDDNLinkInfo,sizeof(CShfeFtdcRspQryNetDDNLinkInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetDDNLinkInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetDDNLinkInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetDDNLinkInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetDDNLinkInfoTopic(CShfeFtdcRtnNetDDNLinkInfoField *pRtnNetDDNLinkInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetDDNLinkInfo->OperationType:"<<pRtnNetDDNLinkInfo->OperationType<< endl;
  cout << "on pRtnNetDDNLinkInfo->ID:"<<pRtnNetDDNLinkInfo->ID<< endl;
  cout << "on pRtnNetDDNLinkInfo->ClientName:"<<pRtnNetDDNLinkInfo->ClientName<< endl;
  cout << "on pRtnNetDDNLinkInfo->DDN_NO:"<<pRtnNetDDNLinkInfo->DDN_NO<< endl;
  cout << "on pRtnNetDDNLinkInfo->BusinessUnit:"<<pRtnNetDDNLinkInfo->BusinessUnit<< endl;
  cout << "on pRtnNetDDNLinkInfo->Bandwidth:"<<pRtnNetDDNLinkInfo->Bandwidth<< endl;
  cout << "on pRtnNetDDNLinkInfo->EndAAddress:"<<pRtnNetDDNLinkInfo->EndAAddress<< endl;
  cout << "on pRtnNetDDNLinkInfo->EndAContactName:"<<pRtnNetDDNLinkInfo->EndAContactName<< endl;
  cout << "on pRtnNetDDNLinkInfo->EndZAddress:"<<pRtnNetDDNLinkInfo->EndZAddress<< endl;
  cout << "on pRtnNetDDNLinkInfo->EndZContactName:"<<pRtnNetDDNLinkInfo->EndZContactName<< endl;
  CShfeFtdcRtnNetDDNLinkInfoField* pNewRtnNetDDNLinkInfo =new CShfeFtdcRtnNetDDNLinkInfoField;
  memcpy(pNewRtnNetDDNLinkInfo,pRtnNetDDNLinkInfo,sizeof(CShfeFtdcRtnNetDDNLinkInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetDDNLinkInfo;
  asyncOnRtnNetDDNLinkInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetDDNLinkInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetPseudMemberLinkInfoTopic(CShfeFtdcRspQryNetPseudMemberLinkInfoField *pRspQryNetPseudMemberLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->OperationType:"<<pRspQryNetPseudMemberLinkInfo->OperationType<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->ID:"<<pRspQryNetPseudMemberLinkInfo->ID<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->SeqNo:"<<pRspQryNetPseudMemberLinkInfo->SeqNo<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->MemContractNo:"<<pRspQryNetPseudMemberLinkInfo->MemContractNo<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->LineUsage:"<<pRspQryNetPseudMemberLinkInfo->LineUsage<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->LocalCircuit:"<<pRspQryNetPseudMemberLinkInfo->LocalCircuit<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->RemoteCircuit:"<<pRspQryNetPseudMemberLinkInfo->RemoteCircuit<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->BusinessUnit:"<<pRspQryNetPseudMemberLinkInfo->BusinessUnit<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->Bandwidth:"<<pRspQryNetPseudMemberLinkInfo->Bandwidth<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->ApplyPerson:"<<pRspQryNetPseudMemberLinkInfo->ApplyPerson<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->MonthlyRental:"<<pRspQryNetPseudMemberLinkInfo->MonthlyRental<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->EndAAddress:"<<pRspQryNetPseudMemberLinkInfo->EndAAddress<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->EndAContactName:"<<pRspQryNetPseudMemberLinkInfo->EndAContactName<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->EndZAddress:"<<pRspQryNetPseudMemberLinkInfo->EndZAddress<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->EndZContactName:"<<pRspQryNetPseudMemberLinkInfo->EndZContactName<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->Telephone:"<<pRspQryNetPseudMemberLinkInfo->Telephone<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->LineInfo:"<<pRspQryNetPseudMemberLinkInfo->LineInfo<< endl;
  cout << "on pRspQryNetPseudMemberLinkInfo->IPADDR:"<<pRspQryNetPseudMemberLinkInfo->IPADDR<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetPseudMemberLinkInfoField* pNewRspQryNetPseudMemberLinkInfo =new CShfeFtdcRspQryNetPseudMemberLinkInfoField;
  memcpy(pNewRspQryNetPseudMemberLinkInfo,pRspQryNetPseudMemberLinkInfo,sizeof(CShfeFtdcRspQryNetPseudMemberLinkInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetPseudMemberLinkInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetPseudMemberLinkInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetPseudMemberLinkInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetPseudMemberLinkInfoTopic(CShfeFtdcRtnNetPseudMemberLinkInfoField *pRtnNetPseudMemberLinkInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->OperationType:"<<pRtnNetPseudMemberLinkInfo->OperationType<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->ID:"<<pRtnNetPseudMemberLinkInfo->ID<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->SeqNo:"<<pRtnNetPseudMemberLinkInfo->SeqNo<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->MemContractNo:"<<pRtnNetPseudMemberLinkInfo->MemContractNo<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->LineUsage:"<<pRtnNetPseudMemberLinkInfo->LineUsage<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->LocalCircuit:"<<pRtnNetPseudMemberLinkInfo->LocalCircuit<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->RemoteCircuit:"<<pRtnNetPseudMemberLinkInfo->RemoteCircuit<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->BusinessUnit:"<<pRtnNetPseudMemberLinkInfo->BusinessUnit<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->Bandwidth:"<<pRtnNetPseudMemberLinkInfo->Bandwidth<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->ApplyPerson:"<<pRtnNetPseudMemberLinkInfo->ApplyPerson<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->MonthlyRental:"<<pRtnNetPseudMemberLinkInfo->MonthlyRental<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->EndAAddress:"<<pRtnNetPseudMemberLinkInfo->EndAAddress<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->EndAContactName:"<<pRtnNetPseudMemberLinkInfo->EndAContactName<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->EndZAddress:"<<pRtnNetPseudMemberLinkInfo->EndZAddress<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->EndZContactName:"<<pRtnNetPseudMemberLinkInfo->EndZContactName<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->Telephone:"<<pRtnNetPseudMemberLinkInfo->Telephone<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->LineInfo:"<<pRtnNetPseudMemberLinkInfo->LineInfo<< endl;
  cout << "on pRtnNetPseudMemberLinkInfo->IPADDR:"<<pRtnNetPseudMemberLinkInfo->IPADDR<< endl;
  CShfeFtdcRtnNetPseudMemberLinkInfoField* pNewRtnNetPseudMemberLinkInfo =new CShfeFtdcRtnNetPseudMemberLinkInfoField;
  memcpy(pNewRtnNetPseudMemberLinkInfo,pRtnNetPseudMemberLinkInfo,sizeof(CShfeFtdcRtnNetPseudMemberLinkInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetPseudMemberLinkInfo;
  asyncOnRtnNetPseudMemberLinkInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetPseudMemberLinkInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryOuterDeviceInfTopic(CShfeFtdcRspQryOuterDeviceInfField *pRspQryOuterDeviceInf, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryOuterDeviceInf->OperationType:"<<pRspQryOuterDeviceInf->OperationType<< endl;
  cout << "on pRspQryOuterDeviceInf->ID:"<<pRspQryOuterDeviceInf->ID<< endl;
  cout << "on pRspQryOuterDeviceInf->IPADDR:"<<pRspQryOuterDeviceInf->IPADDR<< endl;
  cout << "on pRspQryOuterDeviceInf->NAME:"<<pRspQryOuterDeviceInf->NAME<< endl;
  cout << "on pRspQryOuterDeviceInf->memo:"<<pRspQryOuterDeviceInf->memo<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryOuterDeviceInfField* pNewRspQryOuterDeviceInf =new CShfeFtdcRspQryOuterDeviceInfField;
  memcpy(pNewRspQryOuterDeviceInf,pRspQryOuterDeviceInf,sizeof(CShfeFtdcRspQryOuterDeviceInfField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryOuterDeviceInf;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryOuterDeviceInfTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryOuterDeviceInfTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetOuterDeviceInfTopic(CShfeFtdcRtnNetOuterDeviceInfField *pRtnNetOuterDeviceInf)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetOuterDeviceInf->OperationType:"<<pRtnNetOuterDeviceInf->OperationType<< endl;
  cout << "on pRtnNetOuterDeviceInf->ID:"<<pRtnNetOuterDeviceInf->ID<< endl;
  cout << "on pRtnNetOuterDeviceInf->IPADDR:"<<pRtnNetOuterDeviceInf->IPADDR<< endl;
  cout << "on pRtnNetOuterDeviceInf->NAME:"<<pRtnNetOuterDeviceInf->NAME<< endl;
  cout << "on pRtnNetOuterDeviceInf->memo:"<<pRtnNetOuterDeviceInf->memo<< endl;
  CShfeFtdcRtnNetOuterDeviceInfField* pNewRtnNetOuterDeviceInf =new CShfeFtdcRtnNetOuterDeviceInfField;
  memcpy(pNewRtnNetOuterDeviceInf,pRtnNetOuterDeviceInf,sizeof(CShfeFtdcRtnNetOuterDeviceInfField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetOuterDeviceInf;
  asyncOnRtnNetOuterDeviceInfTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetOuterDeviceInfTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetLocalPingResultInfoTopic(CShfeFtdcRspQryNetLocalPingResultInfoField *pRspQryNetLocalPingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetLocalPingResultInfo->OperationType:"<<pRspQryNetLocalPingResultInfo->OperationType<< endl;
  cout << "on pRspQryNetLocalPingResultInfo->ID:"<<pRspQryNetLocalPingResultInfo->ID<< endl;
  cout << "on pRspQryNetLocalPingResultInfo->SouIPADDR:"<<pRspQryNetLocalPingResultInfo->SouIPADDR<< endl;
  cout << "on pRspQryNetLocalPingResultInfo->SouNAME:"<<pRspQryNetLocalPingResultInfo->SouNAME<< endl;
  cout << "on pRspQryNetLocalPingResultInfo->TarIPADDR:"<<pRspQryNetLocalPingResultInfo->TarIPADDR<< endl;
  cout << "on pRspQryNetLocalPingResultInfo->TarNAME:"<<pRspQryNetLocalPingResultInfo->TarNAME<< endl;
  cout << "on pRspQryNetLocalPingResultInfo->PDateSta:"<<pRspQryNetLocalPingResultInfo->PDateSta<< endl;
  cout << "on pRspQryNetLocalPingResultInfo->PTimeSta:"<<pRspQryNetLocalPingResultInfo->PTimeSta<< endl;
  cout << "on pRspQryNetLocalPingResultInfo->ConnRate:"<<pRspQryNetLocalPingResultInfo->ConnRate<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetLocalPingResultInfoField* pNewRspQryNetLocalPingResultInfo =new CShfeFtdcRspQryNetLocalPingResultInfoField;
  memcpy(pNewRspQryNetLocalPingResultInfo,pRspQryNetLocalPingResultInfo,sizeof(CShfeFtdcRspQryNetLocalPingResultInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetLocalPingResultInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetLocalPingResultInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetLocalPingResultInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetLocalPingResultInfoTopic(CShfeFtdcRtnNetLocalPingResultInfoField *pRtnNetLocalPingResultInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetLocalPingResultInfo->OperationType:"<<pRtnNetLocalPingResultInfo->OperationType<< endl;
  cout << "on pRtnNetLocalPingResultInfo->ID:"<<pRtnNetLocalPingResultInfo->ID<< endl;
  cout << "on pRtnNetLocalPingResultInfo->SouIPADDR:"<<pRtnNetLocalPingResultInfo->SouIPADDR<< endl;
  cout << "on pRtnNetLocalPingResultInfo->SouNAME:"<<pRtnNetLocalPingResultInfo->SouNAME<< endl;
  cout << "on pRtnNetLocalPingResultInfo->TarIPADDR:"<<pRtnNetLocalPingResultInfo->TarIPADDR<< endl;
  cout << "on pRtnNetLocalPingResultInfo->TarNAME:"<<pRtnNetLocalPingResultInfo->TarNAME<< endl;
  cout << "on pRtnNetLocalPingResultInfo->PDateSta:"<<pRtnNetLocalPingResultInfo->PDateSta<< endl;
  cout << "on pRtnNetLocalPingResultInfo->PTimeSta:"<<pRtnNetLocalPingResultInfo->PTimeSta<< endl;
  cout << "on pRtnNetLocalPingResultInfo->ConnRate:"<<pRtnNetLocalPingResultInfo->ConnRate<< endl;
  CShfeFtdcRtnNetLocalPingResultInfoField* pNewRtnNetLocalPingResultInfo =new CShfeFtdcRtnNetLocalPingResultInfoField;
  memcpy(pNewRtnNetLocalPingResultInfo,pRtnNetLocalPingResultInfo,sizeof(CShfeFtdcRtnNetLocalPingResultInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetLocalPingResultInfo;
  asyncOnRtnNetLocalPingResultInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetLocalPingResultInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetRomotePingResultInfoTopic(CShfeFtdcRspQryNetRomotePingResultInfoField *pRspQryNetRomotePingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetRomotePingResultInfo->OperationType:"<<pRspQryNetRomotePingResultInfo->OperationType<< endl;
  cout << "on pRspQryNetRomotePingResultInfo->ID:"<<pRspQryNetRomotePingResultInfo->ID<< endl;
  cout << "on pRspQryNetRomotePingResultInfo->SouIPADDR:"<<pRspQryNetRomotePingResultInfo->SouIPADDR<< endl;
  cout << "on pRspQryNetRomotePingResultInfo->SouNAME:"<<pRspQryNetRomotePingResultInfo->SouNAME<< endl;
  cout << "on pRspQryNetRomotePingResultInfo->TarIPADDR:"<<pRspQryNetRomotePingResultInfo->TarIPADDR<< endl;
  cout << "on pRspQryNetRomotePingResultInfo->TarNAME:"<<pRspQryNetRomotePingResultInfo->TarNAME<< endl;
  cout << "on pRspQryNetRomotePingResultInfo->PDateSta:"<<pRspQryNetRomotePingResultInfo->PDateSta<< endl;
  cout << "on pRspQryNetRomotePingResultInfo->PTimeSta:"<<pRspQryNetRomotePingResultInfo->PTimeSta<< endl;
  cout << "on pRspQryNetRomotePingResultInfo->ConnRate:"<<pRspQryNetRomotePingResultInfo->ConnRate<< endl;
  cout << "on pRspQryNetRomotePingResultInfo->TimeDlyMin:"<<pRspQryNetRomotePingResultInfo->TimeDlyMin<< endl;
  cout << "on pRspQryNetRomotePingResultInfo->TimeDlyMax:"<<pRspQryNetRomotePingResultInfo->TimeDlyMax<< endl;
  cout << "on pRspQryNetRomotePingResultInfo->TimeDlyAvg:"<<pRspQryNetRomotePingResultInfo->TimeDlyAvg<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetRomotePingResultInfoField* pNewRspQryNetRomotePingResultInfo =new CShfeFtdcRspQryNetRomotePingResultInfoField;
  memcpy(pNewRspQryNetRomotePingResultInfo,pRspQryNetRomotePingResultInfo,sizeof(CShfeFtdcRspQryNetRomotePingResultInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetRomotePingResultInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetRomotePingResultInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetRomotePingResultInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetRomotePingResultInfoTopic(CShfeFtdcRtnNetRomotePingResultInfoField *pRtnNetRomotePingResultInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetRomotePingResultInfo->OperationType:"<<pRtnNetRomotePingResultInfo->OperationType<< endl;
  cout << "on pRtnNetRomotePingResultInfo->ID:"<<pRtnNetRomotePingResultInfo->ID<< endl;
  cout << "on pRtnNetRomotePingResultInfo->SouIPADDR:"<<pRtnNetRomotePingResultInfo->SouIPADDR<< endl;
  cout << "on pRtnNetRomotePingResultInfo->SouNAME:"<<pRtnNetRomotePingResultInfo->SouNAME<< endl;
  cout << "on pRtnNetRomotePingResultInfo->TarIPADDR:"<<pRtnNetRomotePingResultInfo->TarIPADDR<< endl;
  cout << "on pRtnNetRomotePingResultInfo->TarNAME:"<<pRtnNetRomotePingResultInfo->TarNAME<< endl;
  cout << "on pRtnNetRomotePingResultInfo->PDateSta:"<<pRtnNetRomotePingResultInfo->PDateSta<< endl;
  cout << "on pRtnNetRomotePingResultInfo->PTimeSta:"<<pRtnNetRomotePingResultInfo->PTimeSta<< endl;
  cout << "on pRtnNetRomotePingResultInfo->ConnRate:"<<pRtnNetRomotePingResultInfo->ConnRate<< endl;
  cout << "on pRtnNetRomotePingResultInfo->TimeDlyMin:"<<pRtnNetRomotePingResultInfo->TimeDlyMin<< endl;
  cout << "on pRtnNetRomotePingResultInfo->TimeDlyMax:"<<pRtnNetRomotePingResultInfo->TimeDlyMax<< endl;
  cout << "on pRtnNetRomotePingResultInfo->TimeDlyAvg:"<<pRtnNetRomotePingResultInfo->TimeDlyAvg<< endl;
  CShfeFtdcRtnNetRomotePingResultInfoField* pNewRtnNetRomotePingResultInfo =new CShfeFtdcRtnNetRomotePingResultInfoField;
  memcpy(pNewRtnNetRomotePingResultInfo,pRtnNetRomotePingResultInfo,sizeof(CShfeFtdcRtnNetRomotePingResultInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetRomotePingResultInfo;
  asyncOnRtnNetRomotePingResultInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetRomotePingResultInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnMonitorTopProcessInfo(CShfeFtdcRtnMonitorTopProcessInfoField *pRtnMonitorTopProcessInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnMonitorTopProcessInfo->HostName:"<<pRtnMonitorTopProcessInfo->HostName<< endl;
  cout << "on pRtnMonitorTopProcessInfo->MonDate:"<<pRtnMonitorTopProcessInfo->MonDate<< endl;
  cout << "on pRtnMonitorTopProcessInfo->MonTime:"<<pRtnMonitorTopProcessInfo->MonTime<< endl;
  cout << "on pRtnMonitorTopProcessInfo->CPU:"<<pRtnMonitorTopProcessInfo->CPU<< endl;
  cout << "on pRtnMonitorTopProcessInfo->TTY:"<<pRtnMonitorTopProcessInfo->TTY<< endl;
  cout << "on pRtnMonitorTopProcessInfo->PID:"<<pRtnMonitorTopProcessInfo->PID<< endl;
  cout << "on pRtnMonitorTopProcessInfo->USERNAME:"<<pRtnMonitorTopProcessInfo->USERNAME<< endl;
  cout << "on pRtnMonitorTopProcessInfo->PRI:"<<pRtnMonitorTopProcessInfo->PRI<< endl;
  cout << "on pRtnMonitorTopProcessInfo->NI:"<<pRtnMonitorTopProcessInfo->NI<< endl;
  cout << "on pRtnMonitorTopProcessInfo->SSIZE:"<<pRtnMonitorTopProcessInfo->SSIZE<< endl;
  cout << "on pRtnMonitorTopProcessInfo->RES:"<<pRtnMonitorTopProcessInfo->RES<< endl;
  cout << "on pRtnMonitorTopProcessInfo->STATE:"<<pRtnMonitorTopProcessInfo->STATE<< endl;
  cout << "on pRtnMonitorTopProcessInfo->STIME:"<<pRtnMonitorTopProcessInfo->STIME<< endl;
  cout << "on pRtnMonitorTopProcessInfo->pWCPU:"<<pRtnMonitorTopProcessInfo->pWCPU<< endl;
  cout << "on pRtnMonitorTopProcessInfo->pCPU:"<<pRtnMonitorTopProcessInfo->pCPU<< endl;
  cout << "on pRtnMonitorTopProcessInfo->COMMAND:"<<pRtnMonitorTopProcessInfo->COMMAND<< endl;
  CShfeFtdcRtnMonitorTopProcessInfoField* pNewRtnMonitorTopProcessInfo =new CShfeFtdcRtnMonitorTopProcessInfoField;
  memcpy(pNewRtnMonitorTopProcessInfo,pRtnMonitorTopProcessInfo,sizeof(CShfeFtdcRtnMonitorTopProcessInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnMonitorTopProcessInfo;
  asyncOnRtnMonitorTopProcessInfo.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnMonitorTopProcessInfo);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQrySysInternalTopologyTopic(CShfeFtdcRspQrySysInternalTopologyField *pRspQrySysInternalTopology, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQrySysInternalTopology->InfoType:"<<pRspQrySysInternalTopology->InfoType<< endl;
  cout << "on pRspQrySysInternalTopology->Node1_ID:"<<pRspQrySysInternalTopology->Node1_ID<< endl;
  cout << "on pRspQrySysInternalTopology->Node1_Info:"<<pRspQrySysInternalTopology->Node1_Info<< endl;
  cout << "on pRspQrySysInternalTopology->LinkInfo:"<<pRspQrySysInternalTopology->LinkInfo<< endl;
  cout << "on pRspQrySysInternalTopology->LinkState:"<<pRspQrySysInternalTopology->LinkState<< endl;
  cout << "on pRspQrySysInternalTopology->Node2_ID:"<<pRspQrySysInternalTopology->Node2_ID<< endl;
  cout << "on pRspQrySysInternalTopology->Node2_Info:"<<pRspQrySysInternalTopology->Node2_Info<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQrySysInternalTopologyField* pNewRspQrySysInternalTopology =new CShfeFtdcRspQrySysInternalTopologyField;
  memcpy(pNewRspQrySysInternalTopology,pRspQrySysInternalTopology,sizeof(CShfeFtdcRspQrySysInternalTopologyField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySysInternalTopology;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySysInternalTopologyTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQrySysInternalTopologyTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnSysInternalTopologyTopic(CShfeFtdcRtnSysInternalTopologyField *pRtnSysInternalTopology)
{
  cout << "ok"<< endl;
  cout << "on pRtnSysInternalTopology->InfoType:"<<pRtnSysInternalTopology->InfoType<< endl;
  cout << "on pRtnSysInternalTopology->Node1_ID:"<<pRtnSysInternalTopology->Node1_ID<< endl;
  cout << "on pRtnSysInternalTopology->Node1_Info:"<<pRtnSysInternalTopology->Node1_Info<< endl;
  cout << "on pRtnSysInternalTopology->LinkInfo:"<<pRtnSysInternalTopology->LinkInfo<< endl;
  cout << "on pRtnSysInternalTopology->LinkState:"<<pRtnSysInternalTopology->LinkState<< endl;
  cout << "on pRtnSysInternalTopology->Node2_ID:"<<pRtnSysInternalTopology->Node2_ID<< endl;
  cout << "on pRtnSysInternalTopology->Node2_Info:"<<pRtnSysInternalTopology->Node2_Info<< endl;
  CShfeFtdcRtnSysInternalTopologyField* pNewRtnSysInternalTopology =new CShfeFtdcRtnSysInternalTopologyField;
  memcpy(pNewRtnSysInternalTopology,pRtnSysInternalTopology,sizeof(CShfeFtdcRtnSysInternalTopologyField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSysInternalTopology;
  asyncOnRtnSysInternalTopologyTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnSysInternalTopologyTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryMemberLinkCostTopic(CShfeFtdcRspQryMemberLinkCostField *pRspQryMemberLinkCost, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryMemberLinkCost->OperationType:"<<pRspQryMemberLinkCost->OperationType<< endl;
  cout << "on pRspQryMemberLinkCost->ID:"<<pRspQryMemberLinkCost->ID<< endl;
  cout << "on pRspQryMemberLinkCost->ParticipantName:"<<pRspQryMemberLinkCost->ParticipantName<< endl;
  cout << "on pRspQryMemberLinkCost->DDN_NO:"<<pRspQryMemberLinkCost->DDN_NO<< endl;
  cout << "on pRspQryMemberLinkCost->ServiceProvider:"<<pRspQryMemberLinkCost->ServiceProvider<< endl;
  cout << "on pRspQryMemberLinkCost->Pay_Date:"<<pRspQryMemberLinkCost->Pay_Date<< endl;
  cout << "on pRspQryMemberLinkCost->B_Pay_Date:"<<pRspQryMemberLinkCost->B_Pay_Date<< endl;
  cout << "on pRspQryMemberLinkCost->D_Pay_Date:"<<pRspQryMemberLinkCost->D_Pay_Date<< endl;
  cout << "on pRspQryMemberLinkCost->Charge:"<<pRspQryMemberLinkCost->Charge<< endl;
  cout << "on pRspQryMemberLinkCost->Fee_Type:"<<pRspQryMemberLinkCost->Fee_Type<< endl;
  cout << "on pRspQryMemberLinkCost->Pro:"<<pRspQryMemberLinkCost->Pro<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryMemberLinkCostField* pNewRspQryMemberLinkCost =new CShfeFtdcRspQryMemberLinkCostField;
  memcpy(pNewRspQryMemberLinkCost,pRspQryMemberLinkCost,sizeof(CShfeFtdcRspQryMemberLinkCostField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryMemberLinkCost;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryMemberLinkCostTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryMemberLinkCostTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnMemberLinkCostTopic(CShfeFtdcRtnMemberLinkCostField *pRtnMemberLinkCost)
{
  cout << "ok"<< endl;
  cout << "on pRtnMemberLinkCost->OperationType:"<<pRtnMemberLinkCost->OperationType<< endl;
  cout << "on pRtnMemberLinkCost->ID:"<<pRtnMemberLinkCost->ID<< endl;
  cout << "on pRtnMemberLinkCost->ParticipantName:"<<pRtnMemberLinkCost->ParticipantName<< endl;
  cout << "on pRtnMemberLinkCost->DDN_NO:"<<pRtnMemberLinkCost->DDN_NO<< endl;
  cout << "on pRtnMemberLinkCost->ServiceProvider:"<<pRtnMemberLinkCost->ServiceProvider<< endl;
  cout << "on pRtnMemberLinkCost->Pay_Date:"<<pRtnMemberLinkCost->Pay_Date<< endl;
  cout << "on pRtnMemberLinkCost->B_Pay_Date:"<<pRtnMemberLinkCost->B_Pay_Date<< endl;
  cout << "on pRtnMemberLinkCost->D_Pay_Date:"<<pRtnMemberLinkCost->D_Pay_Date<< endl;
  cout << "on pRtnMemberLinkCost->Charge:"<<pRtnMemberLinkCost->Charge<< endl;
  cout << "on pRtnMemberLinkCost->Fee_Type:"<<pRtnMemberLinkCost->Fee_Type<< endl;
  cout << "on pRtnMemberLinkCost->Pro:"<<pRtnMemberLinkCost->Pro<< endl;
  CShfeFtdcRtnMemberLinkCostField* pNewRtnMemberLinkCost =new CShfeFtdcRtnMemberLinkCostField;
  memcpy(pNewRtnMemberLinkCost,pRtnMemberLinkCost,sizeof(CShfeFtdcRtnMemberLinkCostField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnMemberLinkCost;
  asyncOnRtnMemberLinkCostTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnMemberLinkCostTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetPartylinkMonthlyRentTopic(CShfeFtdcRspQryNetPartylinkMonthlyRentField *pRspQryNetPartylinkMonthlyRent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetPartylinkMonthlyRent->OperationType:"<<pRspQryNetPartylinkMonthlyRent->OperationType<< endl;
  cout << "on pRspQryNetPartylinkMonthlyRent->ID:"<<pRspQryNetPartylinkMonthlyRent->ID<< endl;
  cout << "on pRspQryNetPartylinkMonthlyRent->LineName:"<<pRspQryNetPartylinkMonthlyRent->LineName<< endl;
  cout << "on pRspQryNetPartylinkMonthlyRent->DDN_NO:"<<pRspQryNetPartylinkMonthlyRent->DDN_NO<< endl;
  cout << "on pRspQryNetPartylinkMonthlyRent->ServiceProvider:"<<pRspQryNetPartylinkMonthlyRent->ServiceProvider<< endl;
  cout << "on pRspQryNetPartylinkMonthlyRent->MonthlyRental:"<<pRspQryNetPartylinkMonthlyRent->MonthlyRental<< endl;
  cout << "on pRspQryNetPartylinkMonthlyRent->Remark:"<<pRspQryNetPartylinkMonthlyRent->Remark<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetPartylinkMonthlyRentField* pNewRspQryNetPartylinkMonthlyRent =new CShfeFtdcRspQryNetPartylinkMonthlyRentField;
  memcpy(pNewRspQryNetPartylinkMonthlyRent,pRspQryNetPartylinkMonthlyRent,sizeof(CShfeFtdcRspQryNetPartylinkMonthlyRentField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetPartylinkMonthlyRent;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetPartylinkMonthlyRentTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetPartylinkMonthlyRentTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetPartylinkMonthlyRentTopic(CShfeFtdcRtnNetPartylinkMonthlyRentField *pRtnNetPartylinkMonthlyRent)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetPartylinkMonthlyRent->OperationType:"<<pRtnNetPartylinkMonthlyRent->OperationType<< endl;
  cout << "on pRtnNetPartylinkMonthlyRent->ID:"<<pRtnNetPartylinkMonthlyRent->ID<< endl;
  cout << "on pRtnNetPartylinkMonthlyRent->LineName:"<<pRtnNetPartylinkMonthlyRent->LineName<< endl;
  cout << "on pRtnNetPartylinkMonthlyRent->DDN_NO:"<<pRtnNetPartylinkMonthlyRent->DDN_NO<< endl;
  cout << "on pRtnNetPartylinkMonthlyRent->ServiceProvider:"<<pRtnNetPartylinkMonthlyRent->ServiceProvider<< endl;
  cout << "on pRtnNetPartylinkMonthlyRent->MonthlyRental:"<<pRtnNetPartylinkMonthlyRent->MonthlyRental<< endl;
  cout << "on pRtnNetPartylinkMonthlyRent->Remark:"<<pRtnNetPartylinkMonthlyRent->Remark<< endl;
  CShfeFtdcRtnNetPartylinkMonthlyRentField* pNewRtnNetPartylinkMonthlyRent =new CShfeFtdcRtnNetPartylinkMonthlyRentField;
  memcpy(pNewRtnNetPartylinkMonthlyRent,pRtnNetPartylinkMonthlyRent,sizeof(CShfeFtdcRtnNetPartylinkMonthlyRentField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetPartylinkMonthlyRent;
  asyncOnRtnNetPartylinkMonthlyRentTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetPartylinkMonthlyRentTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRspQryNetNonPartyLinkInfoTopic(CShfeFtdcRspQryNetNonPartyLinkInfoField *pRspQryNetNonPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "ok"<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->OperationType:"<<pRspQryNetNonPartyLinkInfo->OperationType<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->ID:"<<pRspQryNetNonPartyLinkInfo->ID<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->MEMBER_NO:"<<pRspQryNetNonPartyLinkInfo->MEMBER_NO<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->MEMBER_NAME:"<<pRspQryNetNonPartyLinkInfo->MEMBER_NAME<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->REMOTE_ADDR:"<<pRspQryNetNonPartyLinkInfo->REMOTE_ADDR<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->LOCAL_ADDR:"<<pRspQryNetNonPartyLinkInfo->LOCAL_ADDR<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->ADDRESS:"<<pRspQryNetNonPartyLinkInfo->ADDRESS<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->LINE_STATUS:"<<pRspQryNetNonPartyLinkInfo->LINE_STATUS<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->CONTACT:"<<pRspQryNetNonPartyLinkInfo->CONTACT<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->TELEPHONE:"<<pRspQryNetNonPartyLinkInfo->TELEPHONE<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->MOBILEPHONE:"<<pRspQryNetNonPartyLinkInfo->MOBILEPHONE<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->EMAIL:"<<pRspQryNetNonPartyLinkInfo->EMAIL<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->FAX:"<<pRspQryNetNonPartyLinkInfo->FAX<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->PROVINCE:"<<pRspQryNetNonPartyLinkInfo->PROVINCE<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->DDN_NO:"<<pRspQryNetNonPartyLinkInfo->DDN_NO<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->IN_MODE:"<<pRspQryNetNonPartyLinkInfo->IN_MODE<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->IP_WAN:"<<pRspQryNetNonPartyLinkInfo->IP_WAN<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->IP_LAN:"<<pRspQryNetNonPartyLinkInfo->IP_LAN<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->IPADDR:"<<pRspQryNetNonPartyLinkInfo->IPADDR<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->Interface:"<<pRspQryNetNonPartyLinkInfo->Interface<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->INTERFACE_DATE:"<<pRspQryNetNonPartyLinkInfo->INTERFACE_DATE<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->SOFTWARE:"<<pRspQryNetNonPartyLinkInfo->SOFTWARE<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->FEE_TYPE:"<<pRspQryNetNonPartyLinkInfo->FEE_TYPE<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->SERVICEPROVIDER:"<<pRspQryNetNonPartyLinkInfo->SERVICEPROVIDER<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->IF_ZIYING:"<<pRspQryNetNonPartyLinkInfo->IF_ZIYING<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->IF_TUOGUAN:"<<pRspQryNetNonPartyLinkInfo->IF_TUOGUAN<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->HASOTHER:"<<pRspQryNetNonPartyLinkInfo->HASOTHER<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->SEAT_NO:"<<pRspQryNetNonPartyLinkInfo->SEAT_NO<< endl;
  cout << "on pRspQryNetNonPartyLinkInfo->PRO:"<<pRspQryNetNonPartyLinkInfo->PRO<< endl;
  cout << "on pRspInfo:"<<pRspInfo<< endl;
  cout << "on nRequestID:"<<nRequestID<< endl;
  cout << "on bIsLast:"<<bIsLast<< endl;
  CShfeFtdcRspQryNetNonPartyLinkInfoField* pNewRspQryNetNonPartyLinkInfo =new CShfeFtdcRspQryNetNonPartyLinkInfoField;
  memcpy(pNewRspQryNetNonPartyLinkInfo,pRspQryNetNonPartyLinkInfo,sizeof(CShfeFtdcRspQryNetNonPartyLinkInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetNonPartyLinkInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
        cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetNonPartyLinkInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRspQryNetNonPartyLinkInfoTopic);
  cout << "end send "<< endl;
}
void SysUserSpi::OnRtnNetNonPartyLinkInfoTopic(CShfeFtdcRtnNetNonPartyLinkInfoField *pRtnNetNonPartyLinkInfo)
{
  cout << "ok"<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->OperationType:"<<pRtnNetNonPartyLinkInfo->OperationType<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->ID:"<<pRtnNetNonPartyLinkInfo->ID<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->MEMBER_NO:"<<pRtnNetNonPartyLinkInfo->MEMBER_NO<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->MEMBER_NAME:"<<pRtnNetNonPartyLinkInfo->MEMBER_NAME<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->REMOTE_ADDR:"<<pRtnNetNonPartyLinkInfo->REMOTE_ADDR<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->LOCAL_ADDR:"<<pRtnNetNonPartyLinkInfo->LOCAL_ADDR<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->ADDRESS:"<<pRtnNetNonPartyLinkInfo->ADDRESS<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->LINE_STATUS:"<<pRtnNetNonPartyLinkInfo->LINE_STATUS<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->CONTACT:"<<pRtnNetNonPartyLinkInfo->CONTACT<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->TELEPHONE:"<<pRtnNetNonPartyLinkInfo->TELEPHONE<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->MOBILEPHONE:"<<pRtnNetNonPartyLinkInfo->MOBILEPHONE<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->EMAIL:"<<pRtnNetNonPartyLinkInfo->EMAIL<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->FAX:"<<pRtnNetNonPartyLinkInfo->FAX<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->PROVINCE:"<<pRtnNetNonPartyLinkInfo->PROVINCE<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->DDN_NO:"<<pRtnNetNonPartyLinkInfo->DDN_NO<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->IN_MODE:"<<pRtnNetNonPartyLinkInfo->IN_MODE<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->IP_WAN:"<<pRtnNetNonPartyLinkInfo->IP_WAN<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->IP_LAN:"<<pRtnNetNonPartyLinkInfo->IP_LAN<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->IPADDR:"<<pRtnNetNonPartyLinkInfo->IPADDR<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->Interface:"<<pRtnNetNonPartyLinkInfo->Interface<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->INTERFACE_DATE:"<<pRtnNetNonPartyLinkInfo->INTERFACE_DATE<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->SOFTWARE:"<<pRtnNetNonPartyLinkInfo->SOFTWARE<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->FEE_TYPE:"<<pRtnNetNonPartyLinkInfo->FEE_TYPE<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->SERVICEPROVIDER:"<<pRtnNetNonPartyLinkInfo->SERVICEPROVIDER<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->IF_ZIYING:"<<pRtnNetNonPartyLinkInfo->IF_ZIYING<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->IF_TUOGUAN:"<<pRtnNetNonPartyLinkInfo->IF_TUOGUAN<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->HASOTHER:"<<pRtnNetNonPartyLinkInfo->HASOTHER<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->SEAT_NO:"<<pRtnNetNonPartyLinkInfo->SEAT_NO<< endl;
  cout << "on pRtnNetNonPartyLinkInfo->PRO:"<<pRtnNetNonPartyLinkInfo->PRO<< endl;
  CShfeFtdcRtnNetNonPartyLinkInfoField* pNewRtnNetNonPartyLinkInfo =new CShfeFtdcRtnNetNonPartyLinkInfoField;
  memcpy(pNewRtnNetNonPartyLinkInfo,pRtnNetNonPartyLinkInfo,sizeof(CShfeFtdcRtnNetNonPartyLinkInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetNonPartyLinkInfo;
  asyncOnRtnNetNonPartyLinkInfoTopic.data=(void*)&paramArray[0];
  // uv_async_send(&asyncOnRtnNetNonPartyLinkInfoTopic);
  cout << "end send "<< endl;
}


