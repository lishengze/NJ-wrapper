
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
 void SysUserSpi::OnFrontConnected(){
     std::cout<<"SysUserSpi::OnFrontConnected()"<<std::endl;
     uv_async_send(&async);
 }
void SysUserSpi::OnFrontDisConnected(int nReason){
      std::cout<<"SysUserSpi::OnFrontDisConnected()!"<<std::endl;
      asyncOnFrontDisconnected.data=(void*)nReason;
      uv_async_send(&asyncOnFrontDisconnected);
 }
void SysUserSpi::OnHeartBeatWarning(int nTimeLapse){
    std::cout<<"SysUserSpi::OnHeartBeatWarning()!"<<std::endl;
    asyncOnHeartBeatWarning.data=(void*)nTimeLapse;
    uv_async_send(&asyncOnHeartBeatWarning);
}
 //以下自动生成
void SysUserSpi::OnRspQryTopCpuInfoTopic(CShfeFtdcRspQryTopCpuInfoField *pRspQryTopCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryTopCpuInfo->HostName:"<<pRspQryTopCpuInfo->HostName<<std::endl;
  std::cout<<"on pRspQryTopCpuInfo->MonDate:"<<pRspQryTopCpuInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryTopCpuInfo->MonTime:"<<pRspQryTopCpuInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryTopCpuInfo->CPU:"<<pRspQryTopCpuInfo->CPU<<std::endl;
  std::cout<<"on pRspQryTopCpuInfo->LOAD:"<<pRspQryTopCpuInfo->LOAD<<std::endl;
  std::cout<<"on pRspQryTopCpuInfo->USER:"<<pRspQryTopCpuInfo->USER<<std::endl;
  std::cout<<"on pRspQryTopCpuInfo->NICE:"<<pRspQryTopCpuInfo->NICE<<std::endl;
  std::cout<<"on pRspQryTopCpuInfo->SYS:"<<pRspQryTopCpuInfo->SYS<<std::endl;
  std::cout<<"on pRspQryTopCpuInfo->IDLE:"<<pRspQryTopCpuInfo->IDLE<<std::endl;
  std::cout<<"on pRspQryTopCpuInfo->BLOCK:"<<pRspQryTopCpuInfo->BLOCK<<std::endl;
  std::cout<<"on pRspQryTopCpuInfo->SWAIT:"<<pRspQryTopCpuInfo->SWAIT<<std::endl;
  std::cout<<"on pRspQryTopCpuInfo->INTR:"<<pRspQryTopCpuInfo->INTR<<std::endl;
  std::cout<<"on pRspQryTopCpuInfo->SSYS:"<<pRspQryTopCpuInfo->SSYS<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryTopCpuInfoField* pNewRspQryTopCpuInfo =new CShfeFtdcRspQryTopCpuInfoField;
  memcpy(pNewRspQryTopCpuInfo,pRspQryTopCpuInfo,sizeof(CShfeFtdcRspQryTopCpuInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTopCpuInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTopCpuInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryTopCpuInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnTopCpuInfoTopic(CShfeFtdcRtnTopCpuInfoField *pRtnTopCpuInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnTopCpuInfo->HostName:"<<pRtnTopCpuInfo->HostName<<std::endl;
  std::cout<<"on pRtnTopCpuInfo->MonDate:"<<pRtnTopCpuInfo->MonDate<<std::endl;
  std::cout<<"on pRtnTopCpuInfo->MonTime:"<<pRtnTopCpuInfo->MonTime<<std::endl;
  std::cout<<"on pRtnTopCpuInfo->CPU:"<<pRtnTopCpuInfo->CPU<<std::endl;
  std::cout<<"on pRtnTopCpuInfo->LOAD:"<<pRtnTopCpuInfo->LOAD<<std::endl;
  std::cout<<"on pRtnTopCpuInfo->USER:"<<pRtnTopCpuInfo->USER<<std::endl;
  std::cout<<"on pRtnTopCpuInfo->NICE:"<<pRtnTopCpuInfo->NICE<<std::endl;
  std::cout<<"on pRtnTopCpuInfo->SYS:"<<pRtnTopCpuInfo->SYS<<std::endl;
  std::cout<<"on pRtnTopCpuInfo->IDLE:"<<pRtnTopCpuInfo->IDLE<<std::endl;
  std::cout<<"on pRtnTopCpuInfo->BLOCK:"<<pRtnTopCpuInfo->BLOCK<<std::endl;
  std::cout<<"on pRtnTopCpuInfo->SWAIT:"<<pRtnTopCpuInfo->SWAIT<<std::endl;
  std::cout<<"on pRtnTopCpuInfo->INTR:"<<pRtnTopCpuInfo->INTR<<std::endl;
  std::cout<<"on pRtnTopCpuInfo->SSYS:"<<pRtnTopCpuInfo->SSYS<<std::endl;
  CShfeFtdcRtnTopCpuInfoField* pNewRtnTopCpuInfo =new CShfeFtdcRtnTopCpuInfoField;
  memcpy(pNewRtnTopCpuInfo,pRtnTopCpuInfo,sizeof(CShfeFtdcRtnTopCpuInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnTopCpuInfo;
  asyncOnRtnTopCpuInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnTopCpuInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryTopMemInfoTopic(CShfeFtdcRspQryTopMemInfoField *pRspQryTopMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  try {
  std::cout<<"\n******* SysUserSpi::OnRspQryTopMemInfoTopic: START *******"<<std::endl;
  
  if (NULL == pRspQryTopMemInfo) {
    cout << "pRspQryTopMemInfo is NULL" << endl;
    
    if (NULL != pRspInfo) {
      cout << "pRspInfo->ErrorID: " << pRspInfo->ErrorID << endl;
      cout << "pRspInfo->ErrorMsg: " << pRspInfo->ErrorMsg << endl;
    }
    
  } else {
    
     std::cout << "Data in pRspQryTopMemInfo: " << * (char*)(pRspQryTopMemInfo) << endl;
  std::cout<<"on pRspQryTopMemInfo->HostName:"<<pRspQryTopMemInfo->HostName  <<std::endl;
  std::cout<<"on pRspQryTopMemInfo->MonDate:"<<pRspQryTopMemInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryTopMemInfo->MonTime:"<<pRspQryTopMemInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryTopMemInfo->TOTALREAL:"<<pRspQryTopMemInfo->TOTALREAL<<std::endl;
  std::cout<<"on pRspQryTopMemInfo->ACTIVEREAL:"<<pRspQryTopMemInfo->ACTIVEREAL<<std::endl;
  std::cout<<"on pRspQryTopMemInfo->TOTALVIRTUAL:"<<pRspQryTopMemInfo->TOTALVIRTUAL<<std::endl;
  std::cout<<"on pRspQryTopMemInfo->ACTIVEVIRTUAL:"<<pRspQryTopMemInfo->ACTIVEVIRTUAL<<std::endl;
  std::cout<<"on pRspQryTopMemInfo->FREE:"<<pRspQryTopMemInfo->FREE<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;

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
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
    asyncOnRspQryTopMemInfoTopic.data=(void*)&paramArray[0];
    uv_async_send(&asyncOnRspQryTopMemInfoTopic);
     std::cout<<"******* SysUserSpi::OnRspQryTopMemInfoTopic: START *******\n"<<std::endl;      
   }  
   
  } catch (char *str) {  
        cout << "error: " << str << endl;  
  } catch (exception& error) {
    
    std::cout << "Standard exception: " << error.what() << std::endl;  
  }
  
}
void SysUserSpi::OnRtnTopMemInfoTopic(CShfeFtdcRtnTopMemInfoField *pRtnTopMemInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnTopMemInfo->HostName:"<<pRtnTopMemInfo->HostName<<std::endl;
  std::cout<<"on pRtnTopMemInfo->MonDate:"<<pRtnTopMemInfo->MonDate<<std::endl;
  std::cout<<"on pRtnTopMemInfo->MonTime:"<<pRtnTopMemInfo->MonTime<<std::endl;
  std::cout<<"on pRtnTopMemInfo->TOTALREAL:"<<pRtnTopMemInfo->TOTALREAL<<std::endl;
  std::cout<<"on pRtnTopMemInfo->ACTIVEREAL:"<<pRtnTopMemInfo->ACTIVEREAL<<std::endl;
  std::cout<<"on pRtnTopMemInfo->TOTALVIRTUAL:"<<pRtnTopMemInfo->TOTALVIRTUAL<<std::endl;
  std::cout<<"on pRtnTopMemInfo->ACTIVEVIRTUAL:"<<pRtnTopMemInfo->ACTIVEVIRTUAL<<std::endl;
  std::cout<<"on pRtnTopMemInfo->FREE:"<<pRtnTopMemInfo->FREE<<std::endl;
  CShfeFtdcRtnTopMemInfoField* pNewRtnTopMemInfo =new CShfeFtdcRtnTopMemInfoField;
  memcpy(pNewRtnTopMemInfo,pRtnTopMemInfo,sizeof(CShfeFtdcRtnTopMemInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnTopMemInfo;
  asyncOnRtnTopMemInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnTopMemInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryTopProcessInfoTopic(CShfeFtdcRspQryTopProcessInfoField *pRspQryTopProcessInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryTopProcessInfo->HostName:"<<pRspQryTopProcessInfo->HostName<<std::endl;
  std::cout<<"on pRspQryTopProcessInfo->MonDate:"<<pRspQryTopProcessInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryTopProcessInfo->MonTime:"<<pRspQryTopProcessInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryTopProcessInfo->CPU:"<<pRspQryTopProcessInfo->CPU<<std::endl;
  std::cout<<"on pRspQryTopProcessInfo->TTY:"<<pRspQryTopProcessInfo->TTY<<std::endl;
  std::cout<<"on pRspQryTopProcessInfo->PID:"<<pRspQryTopProcessInfo->PID<<std::endl;
  std::cout<<"on pRspQryTopProcessInfo->USERNAME:"<<pRspQryTopProcessInfo->USERNAME<<std::endl;
  std::cout<<"on pRspQryTopProcessInfo->PRI:"<<pRspQryTopProcessInfo->PRI<<std::endl;
  std::cout<<"on pRspQryTopProcessInfo->NI:"<<pRspQryTopProcessInfo->NI<<std::endl;
  std::cout<<"on pRspQryTopProcessInfo->SIZE:"<<pRspQryTopProcessInfo->SIZE<<std::endl;
  std::cout<<"on pRspQryTopProcessInfo->RES:"<<pRspQryTopProcessInfo->RES<<std::endl;
  std::cout<<"on pRspQryTopProcessInfo->STATE:"<<pRspQryTopProcessInfo->STATE<<std::endl;
  std::cout<<"on pRspQryTopProcessInfo->TIME:"<<pRspQryTopProcessInfo->TIME<<std::endl;
  std::cout<<"on pRspQryTopProcessInfo->pWCPU:"<<pRspQryTopProcessInfo->pWCPU<<std::endl;
  std::cout<<"on pRspQryTopProcessInfo->pCPU:"<<pRspQryTopProcessInfo->pCPU<<std::endl;
  std::cout<<"on pRspQryTopProcessInfo->COMMAND:"<<pRspQryTopProcessInfo->COMMAND<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryTopProcessInfoField* pNewRspQryTopProcessInfo =new CShfeFtdcRspQryTopProcessInfoField;
  memcpy(pNewRspQryTopProcessInfo,pRspQryTopProcessInfo,sizeof(CShfeFtdcRspQryTopProcessInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTopProcessInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTopProcessInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryTopProcessInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnTopProcessInfoTopic(CShfeFtdcRtnTopProcessInfoField *pRtnTopProcessInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnTopProcessInfo->HostName:"<<pRtnTopProcessInfo->HostName<<std::endl;
  std::cout<<"on pRtnTopProcessInfo->MonDate:"<<pRtnTopProcessInfo->MonDate<<std::endl;
  std::cout<<"on pRtnTopProcessInfo->MonTime:"<<pRtnTopProcessInfo->MonTime<<std::endl;
  std::cout<<"on pRtnTopProcessInfo->CPU:"<<pRtnTopProcessInfo->CPU<<std::endl;
  std::cout<<"on pRtnTopProcessInfo->TTY:"<<pRtnTopProcessInfo->TTY<<std::endl;
  std::cout<<"on pRtnTopProcessInfo->PID:"<<pRtnTopProcessInfo->PID<<std::endl;
  std::cout<<"on pRtnTopProcessInfo->USERNAME:"<<pRtnTopProcessInfo->USERNAME<<std::endl;
  std::cout<<"on pRtnTopProcessInfo->PRI:"<<pRtnTopProcessInfo->PRI<<std::endl;
  std::cout<<"on pRtnTopProcessInfo->NI:"<<pRtnTopProcessInfo->NI<<std::endl;
  std::cout<<"on pRtnTopProcessInfo->SIZE:"<<pRtnTopProcessInfo->SIZE<<std::endl;
  std::cout<<"on pRtnTopProcessInfo->RES:"<<pRtnTopProcessInfo->RES<<std::endl;
  std::cout<<"on pRtnTopProcessInfo->STATE:"<<pRtnTopProcessInfo->STATE<<std::endl;
  std::cout<<"on pRtnTopProcessInfo->TIME:"<<pRtnTopProcessInfo->TIME<<std::endl;
  std::cout<<"on pRtnTopProcessInfo->pWCPU:"<<pRtnTopProcessInfo->pWCPU<<std::endl;
  std::cout<<"on pRtnTopProcessInfo->pCPU:"<<pRtnTopProcessInfo->pCPU<<std::endl;
  std::cout<<"on pRtnTopProcessInfo->COMMAND:"<<pRtnTopProcessInfo->COMMAND<<std::endl;
  CShfeFtdcRtnTopProcessInfoField* pNewRtnTopProcessInfo =new CShfeFtdcRtnTopProcessInfoField;
  memcpy(pNewRtnTopProcessInfo,pRtnTopProcessInfo,sizeof(CShfeFtdcRtnTopProcessInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnTopProcessInfo;
  asyncOnRtnTopProcessInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnTopProcessInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryFileSystemInfoTopic(CShfeFtdcRspQryFileSystemInfoField *pRspQryFileSystemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryFileSystemInfo->HostName:"<<pRspQryFileSystemInfo->HostName<<std::endl;
  std::cout<<"on pRspQryFileSystemInfo->MonDate:"<<pRspQryFileSystemInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryFileSystemInfo->MonTime:"<<pRspQryFileSystemInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryFileSystemInfo->FILESYSTEM:"<<pRspQryFileSystemInfo->FILESYSTEM<<std::endl;
  std::cout<<"on pRspQryFileSystemInfo->SIZE:"<<pRspQryFileSystemInfo->SIZE<<std::endl;
  std::cout<<"on pRspQryFileSystemInfo->USED:"<<pRspQryFileSystemInfo->USED<<std::endl;
  std::cout<<"on pRspQryFileSystemInfo->AVAIL:"<<pRspQryFileSystemInfo->AVAIL<<std::endl;
  std::cout<<"on pRspQryFileSystemInfo->pUSERD:"<<pRspQryFileSystemInfo->pUSERD<<std::endl;
  std::cout<<"on pRspQryFileSystemInfo->ISIZE:"<<pRspQryFileSystemInfo->ISIZE<<std::endl;
  std::cout<<"on pRspQryFileSystemInfo->IUSED:"<<pRspQryFileSystemInfo->IUSED<<std::endl;
  std::cout<<"on pRspQryFileSystemInfo->IFREE:"<<pRspQryFileSystemInfo->IFREE<<std::endl;
  std::cout<<"on pRspQryFileSystemInfo->pIUSED:"<<pRspQryFileSystemInfo->pIUSED<<std::endl;
  std::cout<<"on pRspQryFileSystemInfo->MountedOn:"<<pRspQryFileSystemInfo->MountedOn<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryFileSystemInfoField* pNewRspQryFileSystemInfo =new CShfeFtdcRspQryFileSystemInfoField;
  memcpy(pNewRspQryFileSystemInfo,pRspQryFileSystemInfo,sizeof(CShfeFtdcRspQryFileSystemInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryFileSystemInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryFileSystemInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryFileSystemInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnFileSystemInfoTopic(CShfeFtdcRtnFileSystemInfoField *pRtnFileSystemInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnFileSystemInfo->HostName:"<<pRtnFileSystemInfo->HostName<<std::endl;
  std::cout<<"on pRtnFileSystemInfo->MonDate:"<<pRtnFileSystemInfo->MonDate<<std::endl;
  std::cout<<"on pRtnFileSystemInfo->MonTime:"<<pRtnFileSystemInfo->MonTime<<std::endl;
  std::cout<<"on pRtnFileSystemInfo->FILESYSTEM:"<<pRtnFileSystemInfo->FILESYSTEM<<std::endl;
  std::cout<<"on pRtnFileSystemInfo->SIZE:"<<pRtnFileSystemInfo->SIZE<<std::endl;
  std::cout<<"on pRtnFileSystemInfo->USED:"<<pRtnFileSystemInfo->USED<<std::endl;
  std::cout<<"on pRtnFileSystemInfo->AVAIL:"<<pRtnFileSystemInfo->AVAIL<<std::endl;
  std::cout<<"on pRtnFileSystemInfo->pUSERD:"<<pRtnFileSystemInfo->pUSERD<<std::endl;
  std::cout<<"on pRtnFileSystemInfo->ISIZE:"<<pRtnFileSystemInfo->ISIZE<<std::endl;
  std::cout<<"on pRtnFileSystemInfo->IUSED:"<<pRtnFileSystemInfo->IUSED<<std::endl;
  std::cout<<"on pRtnFileSystemInfo->IFREE:"<<pRtnFileSystemInfo->IFREE<<std::endl;
  std::cout<<"on pRtnFileSystemInfo->pIUSED:"<<pRtnFileSystemInfo->pIUSED<<std::endl;
  std::cout<<"on pRtnFileSystemInfo->MountedOn:"<<pRtnFileSystemInfo->MountedOn<<std::endl;
  CShfeFtdcRtnFileSystemInfoField* pNewRtnFileSystemInfo =new CShfeFtdcRtnFileSystemInfoField;
  memcpy(pNewRtnFileSystemInfo,pRtnFileSystemInfo,sizeof(CShfeFtdcRtnFileSystemInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnFileSystemInfo;
  asyncOnRtnFileSystemInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnFileSystemInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetworkInfoTopic(CShfeFtdcRspQryNetworkInfoField *pRspQryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetworkInfo->HostName:"<<pRspQryNetworkInfo->HostName<<std::endl;
  std::cout<<"on pRspQryNetworkInfo->MonDate:"<<pRspQryNetworkInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryNetworkInfo->MonTime:"<<pRspQryNetworkInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryNetworkInfo->LANNAME:"<<pRspQryNetworkInfo->LANNAME<<std::endl;
  std::cout<<"on pRspQryNetworkInfo->LANSTATUS:"<<pRspQryNetworkInfo->LANSTATUS<<std::endl;
  std::cout<<"on pRspQryNetworkInfo->IPADDRESS:"<<pRspQryNetworkInfo->IPADDRESS<<std::endl;
  std::cout<<"on pRspQryNetworkInfo->RECVBYTES:"<<pRspQryNetworkInfo->RECVBYTES<<std::endl;
  std::cout<<"on pRspQryNetworkInfo->RECVPACKETS:"<<pRspQryNetworkInfo->RECVPACKETS<<std::endl;
  std::cout<<"on pRspQryNetworkInfo->RECVERRORPACKETS:"<<pRspQryNetworkInfo->RECVERRORPACKETS<<std::endl;
  std::cout<<"on pRspQryNetworkInfo->RECVDROPPACKETS:"<<pRspQryNetworkInfo->RECVDROPPACKETS<<std::endl;
  std::cout<<"on pRspQryNetworkInfo->SENDBYTES:"<<pRspQryNetworkInfo->SENDBYTES<<std::endl;
  std::cout<<"on pRspQryNetworkInfo->SENDPACKETS:"<<pRspQryNetworkInfo->SENDPACKETS<<std::endl;
  std::cout<<"on pRspQryNetworkInfo->SENDERRORPACKETS:"<<pRspQryNetworkInfo->SENDERRORPACKETS<<std::endl;
  std::cout<<"on pRspQryNetworkInfo->SENDDROPPACKETS:"<<pRspQryNetworkInfo->SENDDROPPACKETS<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetworkInfoField* pNewRspQryNetworkInfo =new CShfeFtdcRspQryNetworkInfoField;
  memcpy(pNewRspQryNetworkInfo,pRspQryNetworkInfo,sizeof(CShfeFtdcRspQryNetworkInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetworkInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetworkInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetworkInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetworkInfoTopic(CShfeFtdcRtnNetworkInfoField *pRtnNetworkInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetworkInfo->HostName:"<<pRtnNetworkInfo->HostName<<std::endl;
  std::cout<<"on pRtnNetworkInfo->MonDate:"<<pRtnNetworkInfo->MonDate<<std::endl;
  std::cout<<"on pRtnNetworkInfo->MonTime:"<<pRtnNetworkInfo->MonTime<<std::endl;
  std::cout<<"on pRtnNetworkInfo->LANNAME:"<<pRtnNetworkInfo->LANNAME<<std::endl;
  std::cout<<"on pRtnNetworkInfo->LANSTATUS:"<<pRtnNetworkInfo->LANSTATUS<<std::endl;
  std::cout<<"on pRtnNetworkInfo->IPADDRESS:"<<pRtnNetworkInfo->IPADDRESS<<std::endl;
  std::cout<<"on pRtnNetworkInfo->RECVBYTES:"<<pRtnNetworkInfo->RECVBYTES<<std::endl;
  std::cout<<"on pRtnNetworkInfo->RECVPACKETS:"<<pRtnNetworkInfo->RECVPACKETS<<std::endl;
  std::cout<<"on pRtnNetworkInfo->RECVERRORPACKETS:"<<pRtnNetworkInfo->RECVERRORPACKETS<<std::endl;
  std::cout<<"on pRtnNetworkInfo->RECVDROPPACKETS:"<<pRtnNetworkInfo->RECVDROPPACKETS<<std::endl;
  std::cout<<"on pRtnNetworkInfo->SENDBYTES:"<<pRtnNetworkInfo->SENDBYTES<<std::endl;
  std::cout<<"on pRtnNetworkInfo->SENDPACKETS:"<<pRtnNetworkInfo->SENDPACKETS<<std::endl;
  std::cout<<"on pRtnNetworkInfo->SENDERRORPACKETS:"<<pRtnNetworkInfo->SENDERRORPACKETS<<std::endl;
  std::cout<<"on pRtnNetworkInfo->SENDDROPPACKETS:"<<pRtnNetworkInfo->SENDDROPPACKETS<<std::endl;
  CShfeFtdcRtnNetworkInfoField* pNewRtnNetworkInfo =new CShfeFtdcRtnNetworkInfoField;
  memcpy(pNewRtnNetworkInfo,pRtnNetworkInfo,sizeof(CShfeFtdcRtnNetworkInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetworkInfo;
  asyncOnRtnNetworkInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetworkInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryClientLoginTopic(CShfeFtdcRspQryClientLoginField *pRspQryClientLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"\n **************** SysUserSpi::OnRspQryClientLoginTopic:  START **************** "<<std::endl;
  std::cout<<"on pRspQryClientLogin->UserName:"<<pRspQryClientLogin->UserName<<std::endl;
  std::cout<<"on pRspQryClientLogin->Privalage:"<<pRspQryClientLogin->Privalage<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryClientLoginField* pNewRspQryClientLogin =new CShfeFtdcRspQryClientLoginField;
  memcpy(pNewRspQryClientLogin,pRspQryClientLogin,sizeof(CShfeFtdcRspQryClientLoginField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryClientLogin;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryClientLoginTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryClientLoginTopic);
  std::cout<<"\n **************** SysUserSpi::OnRspQryClientLoginTopic end! ****************  \n "<<std::endl;
}

void SysUserSpi::OnRspQryMonitorObjectTopic(CShfeFtdcRspQryMonitorObjectField *pRspQryMonitorObject, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryMonitorObject->ObjectID:"<<pRspQryMonitorObject->ObjectID<<std::endl;
  std::cout<<"on pRspQryMonitorObject->ObjectName:"<<pRspQryMonitorObject->ObjectName<<std::endl;
  std::cout<<"on pRspQryMonitorObject->WarningActive:"<<pRspQryMonitorObject->WarningActive<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryMonitorObjectField* pNewRspQryMonitorObject =new CShfeFtdcRspQryMonitorObjectField;
  memcpy(pNewRspQryMonitorObject,pRspQryMonitorObject,sizeof(CShfeFtdcRspQryMonitorObjectField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryMonitorObject;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryMonitorObjectTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryMonitorObjectTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnMonitorObjectTopic(CShfeFtdcRtnMonitorObjectField *pRtnMonitorObject)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnMonitorObject->ObjectID:"<<pRtnMonitorObject->ObjectID<<std::endl;
  std::cout<<"on pRtnMonitorObject->ObjectName:"<<pRtnMonitorObject->ObjectName<<std::endl;
  std::cout<<"on pRtnMonitorObject->WarningActive:"<<pRtnMonitorObject->WarningActive<<std::endl;
  CShfeFtdcRtnMonitorObjectField* pNewRtnMonitorObject =new CShfeFtdcRtnMonitorObjectField;
  memcpy(pNewRtnMonitorObject,pRtnMonitorObject,sizeof(CShfeFtdcRtnMonitorObjectField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnMonitorObject;
  asyncOnRtnMonitorObjectTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnMonitorObjectTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryObjectRationalTopic(CShfeFtdcRspQryObjectRationalField *pRspQryObjectRational, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryObjectRational->ObjectID:"<<pRspQryObjectRational->ObjectID<<std::endl;
  std::cout<<"on pRspQryObjectRational->HostObjectID:"<<pRspQryObjectRational->HostObjectID<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryObjectRationalField* pNewRspQryObjectRational =new CShfeFtdcRspQryObjectRationalField;
  memcpy(pNewRspQryObjectRational,pRspQryObjectRational,sizeof(CShfeFtdcRspQryObjectRationalField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryObjectRational;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryObjectRationalTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryObjectRationalTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnObjectRationalTopic(CShfeFtdcRtnObjectRationalField *pRtnObjectRational)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnObjectRational->ObjectID:"<<pRtnObjectRational->ObjectID<<std::endl;
  std::cout<<"on pRtnObjectRational->HostObjectID:"<<pRtnObjectRational->HostObjectID<<std::endl;
  CShfeFtdcRtnObjectRationalField* pNewRtnObjectRational =new CShfeFtdcRtnObjectRationalField;
  memcpy(pNewRtnObjectRational,pRtnObjectRational,sizeof(CShfeFtdcRtnObjectRationalField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnObjectRational;
  asyncOnRtnObjectRationalTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnObjectRationalTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQrySyslogInfoTopic(CShfeFtdcRspQrySyslogInfoField *pRspQrySyslogInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQrySyslogInfo->MonDate:"<<pRspQrySyslogInfo->MonDate<<std::endl;
  std::cout<<"on pRspQrySyslogInfo->MonTime:"<<pRspQrySyslogInfo->MonTime<<std::endl;
  std::cout<<"on pRspQrySyslogInfo->ObjectID:"<<pRspQrySyslogInfo->ObjectID<<std::endl;
  std::cout<<"on pRspQrySyslogInfo->AttrType:"<<pRspQrySyslogInfo->AttrType<<std::endl;
  std::cout<<"on pRspQrySyslogInfo->ContLen:"<<pRspQrySyslogInfo->ContLen<<std::endl;
  std::cout<<"on pRspQrySyslogInfo->FileContent:"<<pRspQrySyslogInfo->FileContent<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQrySyslogInfoField* pNewRspQrySyslogInfo =new CShfeFtdcRspQrySyslogInfoField;
  memcpy(pNewRspQrySyslogInfo,pRspQrySyslogInfo,sizeof(CShfeFtdcRspQrySyslogInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySyslogInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySyslogInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQrySyslogInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnSyslogInfoTopic(CShfeFtdcRtnSyslogInfoField *pRtnSyslogInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnSyslogInfo->MonDate:"<<pRtnSyslogInfo->MonDate<<std::endl;
  std::cout<<"on pRtnSyslogInfo->MonTime:"<<pRtnSyslogInfo->MonTime<<std::endl;
  std::cout<<"on pRtnSyslogInfo->ObjectID:"<<pRtnSyslogInfo->ObjectID<<std::endl;
  std::cout<<"on pRtnSyslogInfo->AttrType:"<<pRtnSyslogInfo->AttrType<<std::endl;
  std::cout<<"on pRtnSyslogInfo->ContLen:"<<pRtnSyslogInfo->ContLen<<std::endl;
  std::cout<<"on pRtnSyslogInfo->FileContent:"<<pRtnSyslogInfo->FileContent<<std::endl;
  CShfeFtdcRtnSyslogInfoField* pNewRtnSyslogInfo =new CShfeFtdcRtnSyslogInfoField;
  memcpy(pNewRtnSyslogInfo,pRtnSyslogInfo,sizeof(CShfeFtdcRtnSyslogInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSyslogInfo;
  asyncOnRtnSyslogInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnSyslogInfoTopic);
  std::cout<<"end send "<<std::endl;
}

// TestSubscriber;

void SysUserSpi::OnRspQrySubscriberTopic(CShfeFtdcRspQrySubscriberField *pRspQrySubscriber, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"\n********** SysUserSpi::OnRspQrySubscriberTopic: START ********"<<std::endl;
  if (NULL == pRspQrySubscriber) {
    cout << " pRspQrySubscriber is NULL" << endl;
    
    if (NULL != pRspInfo) {
       cout << "pRspInfo -> ErrorID: " << pRspInfo -> ErrorID << endl;
       cout << "pRspInfo -> ErrorMsg: " << pRspInfo -> ErrorMsg  << endl; 
    }
  } else {    
  
  std::cout<<"SysUserSpi::pRspQrySubscriber->ErrorID:"<<pRspQrySubscriber->ErrorID<<std::endl;
  std::cout<<"SysUserSpi::pRspQrySubscriber->ErrorMsg:"<<pRspQrySubscriber->ErrorMsg<<std::endl;
  std::cout<<"SysUserSpi::pRspQrySubscriber->ObjectID:"<<pRspQrySubscriber->ObjectID<<std::endl;
  std::cout<<"SysUserSpi::pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"SysUserSpi::nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"SysUserSpi::bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQrySubscriberField* pNewRspQrySubscriber =new CShfeFtdcRspQrySubscriberField;
  memcpy(pNewRspQrySubscriber,pRspQrySubscriber,sizeof(CShfeFtdcRspQrySubscriberField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySubscriber;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySubscriberTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQrySubscriberTopic);
  std::cout<<"\n********** SysUserSpi::OnRspQrySubscriberTopic: END ********\n"<<std::endl;
  
  }
}
void SysUserSpi::OnRspQryOidRelationTopic(CShfeFtdcRspQryOidRelationField *pRspQryOidRelation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryOidRelation->ObjectID:"<<pRspQryOidRelation->ObjectID<<std::endl;
  std::cout<<"on pRspQryOidRelation->HoldObjectID:"<<pRspQryOidRelation->HoldObjectID<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryOidRelationField* pNewRspQryOidRelation =new CShfeFtdcRspQryOidRelationField;
  memcpy(pNewRspQryOidRelation,pRspQryOidRelation,sizeof(CShfeFtdcRspQryOidRelationField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryOidRelation;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryOidRelationTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryOidRelationTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnOidRelationTopic(CShfeFtdcRtnOidRelationField *pRtnOidRelation)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnOidRelation->ObjectID:"<<pRtnOidRelation->ObjectID<<std::endl;
  std::cout<<"on pRtnOidRelation->HoldObjectID:"<<pRtnOidRelation->HoldObjectID<<std::endl;
  CShfeFtdcRtnOidRelationField* pNewRtnOidRelation =new CShfeFtdcRtnOidRelationField;
  memcpy(pNewRtnOidRelation,pRtnOidRelation,sizeof(CShfeFtdcRtnOidRelationField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnOidRelation;
  asyncOnRtnOidRelationTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnOidRelationTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryUserInfoTopic(CShfeFtdcRspQryUserInfoField *pRspQryUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryUserInfo->USERNAME:"<<pRspQryUserInfo->USERNAME<<std::endl;
  std::cout<<"on pRspQryUserInfo->USERID:"<<pRspQryUserInfo->USERID<<std::endl;
  std::cout<<"on pRspQryUserInfo->GROUPNAME:"<<pRspQryUserInfo->GROUPNAME<<std::endl;
  std::cout<<"on pRspQryUserInfo->GROUPID:"<<pRspQryUserInfo->GROUPID<<std::endl;
  std::cout<<"on pRspQryUserInfo->HOMEPATH:"<<pRspQryUserInfo->HOMEPATH<<std::endl;
  std::cout<<"on pRspQryUserInfo->SHELL:"<<pRspQryUserInfo->SHELL<<std::endl;
  std::cout<<"on pRspQryUserInfo->ObjectID:"<<pRspQryUserInfo->ObjectID<<std::endl;
  std::cout<<"on pRspQryUserInfo->MonTime:"<<pRspQryUserInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryUserInfo->MonDate:"<<pRspQryUserInfo->MonDate<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryUserInfoField* pNewRspQryUserInfo =new CShfeFtdcRspQryUserInfoField;
  memcpy(pNewRspQryUserInfo,pRspQryUserInfo,sizeof(CShfeFtdcRspQryUserInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryUserInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryUserInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryUserInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnUserInfoTopic(CShfeFtdcRtnUserInfoField *pRtnUserInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnUserInfo->USERNAME:"<<pRtnUserInfo->USERNAME<<std::endl;
  std::cout<<"on pRtnUserInfo->USERID:"<<pRtnUserInfo->USERID<<std::endl;
  std::cout<<"on pRtnUserInfo->GROUPNAME:"<<pRtnUserInfo->GROUPNAME<<std::endl;
  std::cout<<"on pRtnUserInfo->GROUPID:"<<pRtnUserInfo->GROUPID<<std::endl;
  std::cout<<"on pRtnUserInfo->HOMEPATH:"<<pRtnUserInfo->HOMEPATH<<std::endl;
  std::cout<<"on pRtnUserInfo->SHELL:"<<pRtnUserInfo->SHELL<<std::endl;
  std::cout<<"on pRtnUserInfo->ObjectID:"<<pRtnUserInfo->ObjectID<<std::endl;
  std::cout<<"on pRtnUserInfo->MonTime:"<<pRtnUserInfo->MonTime<<std::endl;
  std::cout<<"on pRtnUserInfo->MonDate:"<<pRtnUserInfo->MonDate<<std::endl;
  CShfeFtdcRtnUserInfoField* pNewRtnUserInfo =new CShfeFtdcRtnUserInfoField;
  memcpy(pNewRtnUserInfo,pRtnUserInfo,sizeof(CShfeFtdcRtnUserInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnUserInfo;
  asyncOnRtnUserInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnUserInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryOnlineUserInfoTopic(CShfeFtdcRspQryOnlineUserInfoField *pRspQryOnlineUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryOnlineUserInfo->USERNAME:"<<pRspQryOnlineUserInfo->USERNAME<<std::endl;
  std::cout<<"on pRspQryOnlineUserInfo->TIME:"<<pRspQryOnlineUserInfo->TIME<<std::endl;
  std::cout<<"on pRspQryOnlineUserInfo->TTY:"<<pRspQryOnlineUserInfo->TTY<<std::endl;
  std::cout<<"on pRspQryOnlineUserInfo->IP:"<<pRspQryOnlineUserInfo->IP<<std::endl;
  std::cout<<"on pRspQryOnlineUserInfo->CONNECTIME:"<<pRspQryOnlineUserInfo->CONNECTIME<<std::endl;
  std::cout<<"on pRspQryOnlineUserInfo->PID:"<<pRspQryOnlineUserInfo->PID<<std::endl;
  std::cout<<"on pRspQryOnlineUserInfo->ObjectID:"<<pRspQryOnlineUserInfo->ObjectID<<std::endl;
  std::cout<<"on pRspQryOnlineUserInfo->MonTime:"<<pRspQryOnlineUserInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryOnlineUserInfo->MonDate:"<<pRspQryOnlineUserInfo->MonDate<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryOnlineUserInfoField* pNewRspQryOnlineUserInfo =new CShfeFtdcRspQryOnlineUserInfoField;
  memcpy(pNewRspQryOnlineUserInfo,pRspQryOnlineUserInfo,sizeof(CShfeFtdcRspQryOnlineUserInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryOnlineUserInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryOnlineUserInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryOnlineUserInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnOnlineUserInfoTopic(CShfeFtdcRtnOnlineUserInfoField *pRtnOnlineUserInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnOnlineUserInfo->USERNAME:"<<pRtnOnlineUserInfo->USERNAME<<std::endl;
  std::cout<<"on pRtnOnlineUserInfo->TIME:"<<pRtnOnlineUserInfo->TIME<<std::endl;
  std::cout<<"on pRtnOnlineUserInfo->TTY:"<<pRtnOnlineUserInfo->TTY<<std::endl;
  std::cout<<"on pRtnOnlineUserInfo->IP:"<<pRtnOnlineUserInfo->IP<<std::endl;
  std::cout<<"on pRtnOnlineUserInfo->CONNECTIME:"<<pRtnOnlineUserInfo->CONNECTIME<<std::endl;
  std::cout<<"on pRtnOnlineUserInfo->PID:"<<pRtnOnlineUserInfo->PID<<std::endl;
  std::cout<<"on pRtnOnlineUserInfo->ObjectID:"<<pRtnOnlineUserInfo->ObjectID<<std::endl;
  std::cout<<"on pRtnOnlineUserInfo->MonTime:"<<pRtnOnlineUserInfo->MonTime<<std::endl;
  std::cout<<"on pRtnOnlineUserInfo->MonDate:"<<pRtnOnlineUserInfo->MonDate<<std::endl;
  CShfeFtdcRtnOnlineUserInfoField* pNewRtnOnlineUserInfo =new CShfeFtdcRtnOnlineUserInfoField;
  memcpy(pNewRtnOnlineUserInfo,pRtnOnlineUserInfo,sizeof(CShfeFtdcRtnOnlineUserInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnOnlineUserInfo;
  asyncOnRtnOnlineUserInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnOnlineUserInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryWarningEventTopic(CShfeFtdcRspQryWarningEventField *pRspQryWarningEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  // std::cout<<"\n**************** SysUserSpi::OnRspQryWarningEventTopic: START ****************"<<std::endl;
  // std::cout<<"on pRspQryWarningEvent->MonDate:"<<pRspQryWarningEvent->MonDate<<std::endl;
  // std::cout<<"on pRspQryWarningEvent->MonTime:"<<pRspQryWarningEvent->MonTime<<std::endl;
  // std::cout<<"on pRspQryWarningEvent->OccurDate:"<<pRspQryWarningEvent->OccurDate<<std::endl;
  // std::cout<<"on pRspQryWarningEvent->OccurTime:"<<pRspQryWarningEvent->OccurTime<<std::endl;
  // std::cout<<"on pRspQryWarningEvent->EvendID:"<<pRspQryWarningEvent->EvendID<<std::endl;
  // std::cout<<"on pRspQryWarningEvent->ObjectID:"<<pRspQryWarningEvent->ObjectID<<std::endl;
  // std::cout<<"on pRspQryWarningEvent->IPAddress:"<<pRspQryWarningEvent->IPAddress<<std::endl;
  // std::cout<<"on pRspQryWarningEvent->EventName:"<<pRspQryWarningEvent->EventName<<std::endl;
  // std::cout<<"on pRspQryWarningEvent->EventNum:"<<pRspQryWarningEvent->EventNum<<std::endl;
  // std::cout<<"on pRspQryWarningEvent->EventType:"<<pRspQryWarningEvent->EventType<<std::endl;
  // std::cout<<"on pRspQryWarningEvent->EventDes:"<<pRspQryWarningEvent->EventDes<<std::endl;
  // std::cout<<"on pRspQryWarningEvent->ProcessFlag:"<<pRspQryWarningEvent->ProcessFlag<<std::endl;
  // std::cout<<"on pRspQryWarningEvent->WarningLevel:"<<pRspQryWarningEvent->WarningLevel<<std::endl;
  // std::cout<<"on pRspQryWarningEvent->EventDealDes:"<<pRspQryWarningEvent->EventDealDes<<std::endl;
  // std::cout<<"on pRspQryWarningEvent->FullEventName:"<<pRspQryWarningEvent->FullEventName<<std::endl;
  // std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  // std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  // std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryWarningEventField* pNewRspQryWarningEvent =new CShfeFtdcRspQryWarningEventField;
  memcpy(pNewRspQryWarningEvent,pRspQryWarningEvent,sizeof(CShfeFtdcRspQryWarningEventField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryWarningEvent;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryWarningEventTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryWarningEventTopic);
//  std::cout<<"\**************** SysUserSpi::OnRspQryWarningEventTopic: END \n****************"<<std::endl;
}
void SysUserSpi::OnRtnWarningEventTopic(CShfeFtdcRtnWarningEventField *pRtnWarningEvent)
{
  // std::cout<<"\n**************** SysUserSpi::OnRtnWarningEventTopic: START ****************"<<std::endl;
  // std::cout<<"on pRtnWarningEvent->MonDate:"<<pRtnWarningEvent->MonDate<<std::endl;
  // std::cout<<"on pRtnWarningEvent->MonTime:"<<pRtnWarningEvent->MonTime<<std::endl;
  // std::cout<<"on pRtnWarningEvent->OccurDate:"<<pRtnWarningEvent->OccurDate<<std::endl;
  // std::cout<<"on pRtnWarningEvent->OccurTime:"<<pRtnWarningEvent->OccurTime<<std::endl;
  // std::cout<<"on pRtnWarningEvent->EvendID:"<<pRtnWarningEvent->EvendID<<std::endl;
  // std::cout<<"on pRtnWarningEvent->ObjectID:"<<pRtnWarningEvent->ObjectID<<std::endl;
  // std::cout<<"on pRtnWarningEvent->IPAddress:"<<pRtnWarningEvent->IPAddress<<std::endl;
  // std::cout<<"on pRtnWarningEvent->EventName:"<<pRtnWarningEvent->EventName<<std::endl;
  // std::cout<<"on pRtnWarningEvent->EventNum:"<<pRtnWarningEvent->EventNum<<std::endl;
  // std::cout<<"on pRtnWarningEvent->EventType:"<<pRtnWarningEvent->EventType<<std::endl;
  // std::cout<<"on pRtnWarningEvent->EventDes:"<<pRtnWarningEvent->EventDes<<std::endl;
  // std::cout<<"on pRtnWarningEvent->ProcessFlag:"<<pRtnWarningEvent->ProcessFlag<<std::endl;
  // std::cout<<"on pRtnWarningEvent->WarningLevel:"<<pRtnWarningEvent->WarningLevel<<std::endl;
  // std::cout<<"on pRtnWarningEvent->EventDealDes:"<<pRtnWarningEvent->EventDealDes<<std::endl;
  // std::cout<<"on pRtnWarningEvent->FullEventName:"<<pRtnWarningEvent->FullEventName<<std::endl;
  // std::cout<<"on pRtnWarningEvent->EventCount:"<<pRtnWarningEvent->EventCount<<std::endl;
  CShfeFtdcRtnWarningEventField* pNewRtnWarningEvent =new CShfeFtdcRtnWarningEventField;
  memcpy(pNewRtnWarningEvent,pRtnWarningEvent,sizeof(CShfeFtdcRtnWarningEventField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnWarningEvent;
  asyncOnRtnWarningEventTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnWarningEventTopic);
  // std::cout<<"**************** SysUserSpi::OnRtnWarningEventTopic: END ****************\n"<<std::endl;
}
void SysUserSpi::OnRspQryCPUUsageTopic(CShfeFtdcRspQryCPUUsageField *pRspQryCPUUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryCPUUsage->ObjectID:"<<pRspQryCPUUsage->ObjectID<<std::endl;
  std::cout<<"on pRspQryCPUUsage->MonDate:"<<pRspQryCPUUsage->MonDate<<std::endl;
  std::cout<<"on pRspQryCPUUsage->MonTime:"<<pRspQryCPUUsage->MonTime<<std::endl;
  std::cout<<"on pRspQryCPUUsage->CPUUsage:"<<pRspQryCPUUsage->CPUUsage<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryCPUUsageField* pNewRspQryCPUUsage =new CShfeFtdcRspQryCPUUsageField;
  memcpy(pNewRspQryCPUUsage,pRspQryCPUUsage,sizeof(CShfeFtdcRspQryCPUUsageField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryCPUUsage;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryCPUUsageTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryCPUUsageTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnCPUUsageTopic(CShfeFtdcRtnCPUUsageField *pRtnCPUUsage)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnCPUUsage->ObjectID:"<<pRtnCPUUsage->ObjectID<<std::endl;
  std::cout<<"on pRtnCPUUsage->MonDate:"<<pRtnCPUUsage->MonDate<<std::endl;
  std::cout<<"on pRtnCPUUsage->MonTime:"<<pRtnCPUUsage->MonTime<<std::endl;
  std::cout<<"on pRtnCPUUsage->CPUUsage:"<<pRtnCPUUsage->CPUUsage<<std::endl;
  CShfeFtdcRtnCPUUsageField* pNewRtnCPUUsage =new CShfeFtdcRtnCPUUsageField;
  memcpy(pNewRtnCPUUsage,pRtnCPUUsage,sizeof(CShfeFtdcRtnCPUUsageField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnCPUUsage;
  asyncOnRtnCPUUsageTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnCPUUsageTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryMemoryUsageTopic(CShfeFtdcRspQryMemoryUsageField *pRspQryMemoryUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryMemoryUsage->ObjectID:"<<pRspQryMemoryUsage->ObjectID<<std::endl;
  std::cout<<"on pRspQryMemoryUsage->MonDate:"<<pRspQryMemoryUsage->MonDate<<std::endl;
  std::cout<<"on pRspQryMemoryUsage->MonTime:"<<pRspQryMemoryUsage->MonTime<<std::endl;
  std::cout<<"on pRspQryMemoryUsage->MemoryUsage:"<<pRspQryMemoryUsage->MemoryUsage<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryMemoryUsageField* pNewRspQryMemoryUsage =new CShfeFtdcRspQryMemoryUsageField;
  memcpy(pNewRspQryMemoryUsage,pRspQryMemoryUsage,sizeof(CShfeFtdcRspQryMemoryUsageField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryMemoryUsage;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryMemoryUsageTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryMemoryUsageTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnMemoryUsageTopic(CShfeFtdcRtnMemoryUsageField *pRtnMemoryUsage)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnMemoryUsage->ObjectID:"<<pRtnMemoryUsage->ObjectID<<std::endl;
  std::cout<<"on pRtnMemoryUsage->MonDate:"<<pRtnMemoryUsage->MonDate<<std::endl;
  std::cout<<"on pRtnMemoryUsage->MonTime:"<<pRtnMemoryUsage->MonTime<<std::endl;
  std::cout<<"on pRtnMemoryUsage->MemoryUsage:"<<pRtnMemoryUsage->MemoryUsage<<std::endl;
  CShfeFtdcRtnMemoryUsageField* pNewRtnMemoryUsage =new CShfeFtdcRtnMemoryUsageField;
  memcpy(pNewRtnMemoryUsage,pRtnMemoryUsage,sizeof(CShfeFtdcRtnMemoryUsageField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnMemoryUsage;
  asyncOnRtnMemoryUsageTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnMemoryUsageTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryDiskUsageTopic(CShfeFtdcRspQryDiskUsageField *pRspQryDiskUsage, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryDiskUsage->ObjectID:"<<pRspQryDiskUsage->ObjectID<<std::endl;
  std::cout<<"on pRspQryDiskUsage->MonDate:"<<pRspQryDiskUsage->MonDate<<std::endl;
  std::cout<<"on pRspQryDiskUsage->MonTime:"<<pRspQryDiskUsage->MonTime<<std::endl;
  std::cout<<"on pRspQryDiskUsage->DiskUsage:"<<pRspQryDiskUsage->DiskUsage<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryDiskUsageField* pNewRspQryDiskUsage =new CShfeFtdcRspQryDiskUsageField;
  memcpy(pNewRspQryDiskUsage,pRspQryDiskUsage,sizeof(CShfeFtdcRspQryDiskUsageField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryDiskUsage;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryDiskUsageTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryDiskUsageTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnDiskUsageTopic(CShfeFtdcRtnDiskUsageField *pRtnDiskUsage)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnDiskUsage->ObjectID:"<<pRtnDiskUsage->ObjectID<<std::endl;
  std::cout<<"on pRtnDiskUsage->MonDate:"<<pRtnDiskUsage->MonDate<<std::endl;
  std::cout<<"on pRtnDiskUsage->MonTime:"<<pRtnDiskUsage->MonTime<<std::endl;
  std::cout<<"on pRtnDiskUsage->DiskUsage:"<<pRtnDiskUsage->DiskUsage<<std::endl;
  CShfeFtdcRtnDiskUsageField* pNewRtnDiskUsage =new CShfeFtdcRtnDiskUsageField;
  memcpy(pNewRtnDiskUsage,pRtnDiskUsage,sizeof(CShfeFtdcRtnDiskUsageField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnDiskUsage;
  asyncOnRtnDiskUsageTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnDiskUsageTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryObjectAttrTopic(CShfeFtdcRspQryObjectAttrField *pRspQryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryObjectAttr->ObjectID:"<<pRspQryObjectAttr->ObjectID<<std::endl;
  std::cout<<"on pRspQryObjectAttr->AttrType:"<<pRspQryObjectAttr->AttrType<<std::endl;
  std::cout<<"on pRspQryObjectAttr->MonDate:"<<pRspQryObjectAttr->MonDate<<std::endl;
  std::cout<<"on pRspQryObjectAttr->MonTime:"<<pRspQryObjectAttr->MonTime<<std::endl;
  std::cout<<"on pRspQryObjectAttr->ValueType:"<<pRspQryObjectAttr->ValueType<<std::endl;
  std::cout<<"on pRspQryObjectAttr->AttrValue:"<<pRspQryObjectAttr->AttrValue<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryObjectAttrField* pNewRspQryObjectAttr =new CShfeFtdcRspQryObjectAttrField;
  memcpy(pNewRspQryObjectAttr,pRspQryObjectAttr,sizeof(CShfeFtdcRspQryObjectAttrField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryObjectAttr;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryObjectAttrTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryObjectAttrTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnObjectAttrTopic(CShfeFtdcRtnObjectAttrField *pRtnObjectAttr)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnObjectAttr->ObjectID:"<<pRtnObjectAttr->ObjectID<<std::endl;
  std::cout<<"on pRtnObjectAttr->AttrType:"<<pRtnObjectAttr->AttrType<<std::endl;
  std::cout<<"on pRtnObjectAttr->MonDate:"<<pRtnObjectAttr->MonDate<<std::endl;
  std::cout<<"on pRtnObjectAttr->MonTime:"<<pRtnObjectAttr->MonTime<<std::endl;
  std::cout<<"on pRtnObjectAttr->ValueType:"<<pRtnObjectAttr->ValueType<<std::endl;
  std::cout<<"on pRtnObjectAttr->AttrValue:"<<pRtnObjectAttr->AttrValue<<std::endl;
  CShfeFtdcRtnObjectAttrField* pNewRtnObjectAttr =new CShfeFtdcRtnObjectAttrField;
  memcpy(pNewRtnObjectAttr,pRtnObjectAttr,sizeof(CShfeFtdcRtnObjectAttrField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnObjectAttr;
  asyncOnRtnObjectAttrTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnObjectAttrTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryInvalidateOrderTopic(CShfeFtdcRspQryInvalidateOrderField *pRspQryInvalidateOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->OrderSysID:"<<pRspQryInvalidateOrder->OrderSysID<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->OrderLocalID:"<<pRspQryInvalidateOrder->OrderLocalID<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->ActionDate:"<<pRspQryInvalidateOrder->ActionDate<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->ActionTime:"<<pRspQryInvalidateOrder->ActionTime<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->ErrorMsg:"<<pRspQryInvalidateOrder->ErrorMsg<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->ParticipantID:"<<pRspQryInvalidateOrder->ParticipantID<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->UserID:"<<pRspQryInvalidateOrder->UserID<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->ClientID:"<<pRspQryInvalidateOrder->ClientID<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->InstrumentID:"<<pRspQryInvalidateOrder->InstrumentID<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->Direction:"<<pRspQryInvalidateOrder->Direction<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->CombOffsetFlag:"<<pRspQryInvalidateOrder->CombOffsetFlag<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->CombHedgeFlag:"<<pRspQryInvalidateOrder->CombHedgeFlag<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->LimitPrice:"<<pRspQryInvalidateOrder->LimitPrice<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->VolumeTotalOriginal:"<<pRspQryInvalidateOrder->VolumeTotalOriginal<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->TimeCondition:"<<pRspQryInvalidateOrder->TimeCondition<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->VolumeCondition:"<<pRspQryInvalidateOrder->VolumeCondition<<std::endl;
  std::cout<<"on pRspQryInvalidateOrder->MinVolume:"<<pRspQryInvalidateOrder->MinVolume<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryInvalidateOrderField* pNewRspQryInvalidateOrder =new CShfeFtdcRspQryInvalidateOrderField;
  memcpy(pNewRspQryInvalidateOrder,pRspQryInvalidateOrder,sizeof(CShfeFtdcRspQryInvalidateOrderField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryInvalidateOrder;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryInvalidateOrderTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryInvalidateOrderTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnInvalidateOrderTopic(CShfeFtdcRtnInvalidateOrderField *pRtnInvalidateOrder)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->OrderSysID:"<<pRtnInvalidateOrder->OrderSysID<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->OrderLocalID:"<<pRtnInvalidateOrder->OrderLocalID<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->ActionDate:"<<pRtnInvalidateOrder->ActionDate<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->ActionTime:"<<pRtnInvalidateOrder->ActionTime<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->ErrorMsg:"<<pRtnInvalidateOrder->ErrorMsg<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->ParticipantID:"<<pRtnInvalidateOrder->ParticipantID<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->UserID:"<<pRtnInvalidateOrder->UserID<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->ClientID:"<<pRtnInvalidateOrder->ClientID<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->InstrumentID:"<<pRtnInvalidateOrder->InstrumentID<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->Direction:"<<pRtnInvalidateOrder->Direction<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->CombOffsetFlag:"<<pRtnInvalidateOrder->CombOffsetFlag<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->CombHedgeFlag:"<<pRtnInvalidateOrder->CombHedgeFlag<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->LimitPrice:"<<pRtnInvalidateOrder->LimitPrice<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->VolumeTotalOriginal:"<<pRtnInvalidateOrder->VolumeTotalOriginal<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->TimeCondition:"<<pRtnInvalidateOrder->TimeCondition<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->VolumeCondition:"<<pRtnInvalidateOrder->VolumeCondition<<std::endl;
  std::cout<<"on pRtnInvalidateOrder->MinVolume:"<<pRtnInvalidateOrder->MinVolume<<std::endl;
  CShfeFtdcRtnInvalidateOrderField* pNewRtnInvalidateOrder =new CShfeFtdcRtnInvalidateOrderField;
  memcpy(pNewRtnInvalidateOrder,pRtnInvalidateOrder,sizeof(CShfeFtdcRtnInvalidateOrderField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnInvalidateOrder;
  asyncOnRtnInvalidateOrderTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnInvalidateOrderTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryOrderStatusTopic(CShfeFtdcRspQryOrderStatusField *pRspQryOrderStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryOrderStatus->ActionDate:"<<pRspQryOrderStatus->ActionDate<<std::endl;
  std::cout<<"on pRspQryOrderStatus->ActionTime:"<<pRspQryOrderStatus->ActionTime<<std::endl;
  std::cout<<"on pRspQryOrderStatus->OrderSysID:"<<pRspQryOrderStatus->OrderSysID<<std::endl;
  std::cout<<"on pRspQryOrderStatus->OrderLocalID:"<<pRspQryOrderStatus->OrderLocalID<<std::endl;
  std::cout<<"on pRspQryOrderStatus->InsertDate:"<<pRspQryOrderStatus->InsertDate<<std::endl;
  std::cout<<"on pRspQryOrderStatus->InsertTime:"<<pRspQryOrderStatus->InsertTime<<std::endl;
  std::cout<<"on pRspQryOrderStatus->OrderStatus:"<<pRspQryOrderStatus->OrderStatus<<std::endl;
  std::cout<<"on pRspQryOrderStatus->ParticipantID:"<<pRspQryOrderStatus->ParticipantID<<std::endl;
  std::cout<<"on pRspQryOrderStatus->UserID:"<<pRspQryOrderStatus->UserID<<std::endl;
  std::cout<<"on pRspQryOrderStatus->ClientID:"<<pRspQryOrderStatus->ClientID<<std::endl;
  std::cout<<"on pRspQryOrderStatus->InstrumentID:"<<pRspQryOrderStatus->InstrumentID<<std::endl;
  std::cout<<"on pRspQryOrderStatus->Direction:"<<pRspQryOrderStatus->Direction<<std::endl;
  std::cout<<"on pRspQryOrderStatus->CombOffsetFlag:"<<pRspQryOrderStatus->CombOffsetFlag<<std::endl;
  std::cout<<"on pRspQryOrderStatus->CombHedgeFlag:"<<pRspQryOrderStatus->CombHedgeFlag<<std::endl;
  std::cout<<"on pRspQryOrderStatus->LimitPrice:"<<pRspQryOrderStatus->LimitPrice<<std::endl;
  std::cout<<"on pRspQryOrderStatus->VolumeTotalOriginal:"<<pRspQryOrderStatus->VolumeTotalOriginal<<std::endl;
  std::cout<<"on pRspQryOrderStatus->TimeCondition:"<<pRspQryOrderStatus->TimeCondition<<std::endl;
  std::cout<<"on pRspQryOrderStatus->VolumeCondition:"<<pRspQryOrderStatus->VolumeCondition<<std::endl;
  std::cout<<"on pRspQryOrderStatus->MinVolume:"<<pRspQryOrderStatus->MinVolume<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryOrderStatusField* pNewRspQryOrderStatus =new CShfeFtdcRspQryOrderStatusField;
  memcpy(pNewRspQryOrderStatus,pRspQryOrderStatus,sizeof(CShfeFtdcRspQryOrderStatusField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryOrderStatus;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryOrderStatusTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryOrderStatusTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnOrderStatusTopic(CShfeFtdcRtnOrderStatusField *pRtnOrderStatus)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnOrderStatus->ActionDate:"<<pRtnOrderStatus->ActionDate<<std::endl;
  std::cout<<"on pRtnOrderStatus->ActionTime:"<<pRtnOrderStatus->ActionTime<<std::endl;
  std::cout<<"on pRtnOrderStatus->OrderSysID:"<<pRtnOrderStatus->OrderSysID<<std::endl;
  std::cout<<"on pRtnOrderStatus->OrderLocalID:"<<pRtnOrderStatus->OrderLocalID<<std::endl;
  std::cout<<"on pRtnOrderStatus->InsertDate:"<<pRtnOrderStatus->InsertDate<<std::endl;
  std::cout<<"on pRtnOrderStatus->InsertTime:"<<pRtnOrderStatus->InsertTime<<std::endl;
  std::cout<<"on pRtnOrderStatus->OrderStatus:"<<pRtnOrderStatus->OrderStatus<<std::endl;
  std::cout<<"on pRtnOrderStatus->ParticipantID:"<<pRtnOrderStatus->ParticipantID<<std::endl;
  std::cout<<"on pRtnOrderStatus->UserID:"<<pRtnOrderStatus->UserID<<std::endl;
  std::cout<<"on pRtnOrderStatus->ClientID:"<<pRtnOrderStatus->ClientID<<std::endl;
  std::cout<<"on pRtnOrderStatus->InstrumentID:"<<pRtnOrderStatus->InstrumentID<<std::endl;
  std::cout<<"on pRtnOrderStatus->Direction:"<<pRtnOrderStatus->Direction<<std::endl;
  std::cout<<"on pRtnOrderStatus->CombOffsetFlag:"<<pRtnOrderStatus->CombOffsetFlag<<std::endl;
  std::cout<<"on pRtnOrderStatus->CombHedgeFlag:"<<pRtnOrderStatus->CombHedgeFlag<<std::endl;
  std::cout<<"on pRtnOrderStatus->LimitPrice:"<<pRtnOrderStatus->LimitPrice<<std::endl;
  std::cout<<"on pRtnOrderStatus->VolumeTotalOriginal:"<<pRtnOrderStatus->VolumeTotalOriginal<<std::endl;
  std::cout<<"on pRtnOrderStatus->TimeCondition:"<<pRtnOrderStatus->TimeCondition<<std::endl;
  std::cout<<"on pRtnOrderStatus->VolumeCondition:"<<pRtnOrderStatus->VolumeCondition<<std::endl;
  std::cout<<"on pRtnOrderStatus->MinVolume:"<<pRtnOrderStatus->MinVolume<<std::endl;
  CShfeFtdcRtnOrderStatusField* pNewRtnOrderStatus =new CShfeFtdcRtnOrderStatusField;
  memcpy(pNewRtnOrderStatus,pRtnOrderStatus,sizeof(CShfeFtdcRtnOrderStatusField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnOrderStatus;
  asyncOnRtnOrderStatusTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnOrderStatusTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryBargainOrderTopic(CShfeFtdcRspQryBargainOrderField *pRspQryBargainOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryBargainOrder->ActionDate:"<<pRspQryBargainOrder->ActionDate<<std::endl;
  std::cout<<"on pRspQryBargainOrder->ActionTime:"<<pRspQryBargainOrder->ActionTime<<std::endl;
  std::cout<<"on pRspQryBargainOrder->TradeID:"<<pRspQryBargainOrder->TradeID<<std::endl;
  std::cout<<"on pRspQryBargainOrder->OrderSysID:"<<pRspQryBargainOrder->OrderSysID<<std::endl;
  std::cout<<"on pRspQryBargainOrder->InstrumentID:"<<pRspQryBargainOrder->InstrumentID<<std::endl;
  std::cout<<"on pRspQryBargainOrder->Price:"<<pRspQryBargainOrder->Price<<std::endl;
  std::cout<<"on pRspQryBargainOrder->Volume:"<<pRspQryBargainOrder->Volume<<std::endl;
  std::cout<<"on pRspQryBargainOrder->ParticipantID:"<<pRspQryBargainOrder->ParticipantID<<std::endl;
  std::cout<<"on pRspQryBargainOrder->UserID:"<<pRspQryBargainOrder->UserID<<std::endl;
  std::cout<<"on pRspQryBargainOrder->ClientID:"<<pRspQryBargainOrder->ClientID<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryBargainOrderField* pNewRspQryBargainOrder =new CShfeFtdcRspQryBargainOrderField;
  memcpy(pNewRspQryBargainOrder,pRspQryBargainOrder,sizeof(CShfeFtdcRspQryBargainOrderField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryBargainOrder;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryBargainOrderTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryBargainOrderTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnBargainOrderTopic(CShfeFtdcRtnBargainOrderField *pRtnBargainOrder)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnBargainOrder->ActionDate:"<<pRtnBargainOrder->ActionDate<<std::endl;
  std::cout<<"on pRtnBargainOrder->ActionTime:"<<pRtnBargainOrder->ActionTime<<std::endl;
  std::cout<<"on pRtnBargainOrder->TradeID:"<<pRtnBargainOrder->TradeID<<std::endl;
  std::cout<<"on pRtnBargainOrder->OrderSysID:"<<pRtnBargainOrder->OrderSysID<<std::endl;
  std::cout<<"on pRtnBargainOrder->InstrumentID:"<<pRtnBargainOrder->InstrumentID<<std::endl;
  std::cout<<"on pRtnBargainOrder->Price:"<<pRtnBargainOrder->Price<<std::endl;
  std::cout<<"on pRtnBargainOrder->Volume:"<<pRtnBargainOrder->Volume<<std::endl;
  std::cout<<"on pRtnBargainOrder->ParticipantID:"<<pRtnBargainOrder->ParticipantID<<std::endl;
  std::cout<<"on pRtnBargainOrder->UserID:"<<pRtnBargainOrder->UserID<<std::endl;
  std::cout<<"on pRtnBargainOrder->ClientID:"<<pRtnBargainOrder->ClientID<<std::endl;
  CShfeFtdcRtnBargainOrderField* pNewRtnBargainOrder =new CShfeFtdcRtnBargainOrderField;
  memcpy(pNewRtnBargainOrder,pRtnBargainOrder,sizeof(CShfeFtdcRtnBargainOrderField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnBargainOrder;
  asyncOnRtnBargainOrderTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnBargainOrderTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryInstPropertyTopic(CShfeFtdcRspQryInstPropertyField *pRspQryInstProperty, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryInstProperty->ActionDate:"<<pRspQryInstProperty->ActionDate<<std::endl;
  std::cout<<"on pRspQryInstProperty->ActionTime:"<<pRspQryInstProperty->ActionTime<<std::endl;
  std::cout<<"on pRspQryInstProperty->InstrumentID:"<<pRspQryInstProperty->InstrumentID<<std::endl;
  std::cout<<"on pRspQryInstProperty->SettlementGroupID:"<<pRspQryInstProperty->SettlementGroupID<<std::endl;
  std::cout<<"on pRspQryInstProperty->UnderlyingInstrID:"<<pRspQryInstProperty->UnderlyingInstrID<<std::endl;
  std::cout<<"on pRspQryInstProperty->ProductClass:"<<pRspQryInstProperty->ProductClass<<std::endl;
  std::cout<<"on pRspQryInstProperty->PositionType:"<<pRspQryInstProperty->PositionType<<std::endl;
  std::cout<<"on pRspQryInstProperty->VolumeMultiple:"<<pRspQryInstProperty->VolumeMultiple<<std::endl;
  std::cout<<"on pRspQryInstProperty->UnderlyingMultiple:"<<pRspQryInstProperty->UnderlyingMultiple<<std::endl;
  std::cout<<"on pRspQryInstProperty->InstLifePhase:"<<pRspQryInstProperty->InstLifePhase<<std::endl;
  std::cout<<"on pRspQryInstProperty->OpenDate:"<<pRspQryInstProperty->OpenDate<<std::endl;
  std::cout<<"on pRspQryInstProperty->ExpireDate:"<<pRspQryInstProperty->ExpireDate<<std::endl;
  std::cout<<"on pRspQryInstProperty->StartDelivDate:"<<pRspQryInstProperty->StartDelivDate<<std::endl;
  std::cout<<"on pRspQryInstProperty->EndDelivDate:"<<pRspQryInstProperty->EndDelivDate<<std::endl;
  std::cout<<"on pRspQryInstProperty->BasisPrice:"<<pRspQryInstProperty->BasisPrice<<std::endl;
  std::cout<<"on pRspQryInstProperty->MaxMarketOrderVolume:"<<pRspQryInstProperty->MaxMarketOrderVolume<<std::endl;
  std::cout<<"on pRspQryInstProperty->MinMarketOrderVolume:"<<pRspQryInstProperty->MinMarketOrderVolume<<std::endl;
  std::cout<<"on pRspQryInstProperty->MaxLimitOrderVolume:"<<pRspQryInstProperty->MaxLimitOrderVolume<<std::endl;
  std::cout<<"on pRspQryInstProperty->MinLimitOrderVolume:"<<pRspQryInstProperty->MinLimitOrderVolume<<std::endl;
  std::cout<<"on pRspQryInstProperty->PriceTick:"<<pRspQryInstProperty->PriceTick<<std::endl;
  std::cout<<"on pRspQryInstProperty->AllowDelivPersonOpen:"<<pRspQryInstProperty->AllowDelivPersonOpen<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryInstPropertyField* pNewRspQryInstProperty =new CShfeFtdcRspQryInstPropertyField;
  memcpy(pNewRspQryInstProperty,pRspQryInstProperty,sizeof(CShfeFtdcRspQryInstPropertyField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryInstProperty;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryInstPropertyTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryInstPropertyTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnInstPropertyTopic(CShfeFtdcRtnInstPropertyField *pRtnInstProperty)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnInstProperty->ActionDate:"<<pRtnInstProperty->ActionDate<<std::endl;
  std::cout<<"on pRtnInstProperty->ActionTime:"<<pRtnInstProperty->ActionTime<<std::endl;
  std::cout<<"on pRtnInstProperty->InstrumentID:"<<pRtnInstProperty->InstrumentID<<std::endl;
  std::cout<<"on pRtnInstProperty->SettlementGroupID:"<<pRtnInstProperty->SettlementGroupID<<std::endl;
  std::cout<<"on pRtnInstProperty->UnderlyingInstrID:"<<pRtnInstProperty->UnderlyingInstrID<<std::endl;
  std::cout<<"on pRtnInstProperty->ProductClass:"<<pRtnInstProperty->ProductClass<<std::endl;
  std::cout<<"on pRtnInstProperty->PositionType:"<<pRtnInstProperty->PositionType<<std::endl;
  std::cout<<"on pRtnInstProperty->VolumeMultiple:"<<pRtnInstProperty->VolumeMultiple<<std::endl;
  std::cout<<"on pRtnInstProperty->UnderlyingMultiple:"<<pRtnInstProperty->UnderlyingMultiple<<std::endl;
  std::cout<<"on pRtnInstProperty->InstLifePhase:"<<pRtnInstProperty->InstLifePhase<<std::endl;
  std::cout<<"on pRtnInstProperty->OpenDate:"<<pRtnInstProperty->OpenDate<<std::endl;
  std::cout<<"on pRtnInstProperty->ExpireDate:"<<pRtnInstProperty->ExpireDate<<std::endl;
  std::cout<<"on pRtnInstProperty->StartDelivDate:"<<pRtnInstProperty->StartDelivDate<<std::endl;
  std::cout<<"on pRtnInstProperty->EndDelivDate:"<<pRtnInstProperty->EndDelivDate<<std::endl;
  std::cout<<"on pRtnInstProperty->BasisPrice:"<<pRtnInstProperty->BasisPrice<<std::endl;
  std::cout<<"on pRtnInstProperty->MaxMarketOrderVolume:"<<pRtnInstProperty->MaxMarketOrderVolume<<std::endl;
  std::cout<<"on pRtnInstProperty->MinMarketOrderVolume:"<<pRtnInstProperty->MinMarketOrderVolume<<std::endl;
  std::cout<<"on pRtnInstProperty->MaxLimitOrderVolume:"<<pRtnInstProperty->MaxLimitOrderVolume<<std::endl;
  std::cout<<"on pRtnInstProperty->MinLimitOrderVolume:"<<pRtnInstProperty->MinLimitOrderVolume<<std::endl;
  std::cout<<"on pRtnInstProperty->PriceTick:"<<pRtnInstProperty->PriceTick<<std::endl;
  std::cout<<"on pRtnInstProperty->AllowDelivPersonOpen:"<<pRtnInstProperty->AllowDelivPersonOpen<<std::endl;
  CShfeFtdcRtnInstPropertyField* pNewRtnInstProperty =new CShfeFtdcRtnInstPropertyField;
  memcpy(pNewRtnInstProperty,pRtnInstProperty,sizeof(CShfeFtdcRtnInstPropertyField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnInstProperty;
  asyncOnRtnInstPropertyTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnInstPropertyTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryMarginRateTopic(CShfeFtdcRspQryMarginRateField *pRspQryMarginRate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryMarginRate->ActionDate:"<<pRspQryMarginRate->ActionDate<<std::endl;
  std::cout<<"on pRspQryMarginRate->ActionTime:"<<pRspQryMarginRate->ActionTime<<std::endl;
  std::cout<<"on pRspQryMarginRate->InstrumentID:"<<pRspQryMarginRate->InstrumentID<<std::endl;
  std::cout<<"on pRspQryMarginRate->ParticipantID:"<<pRspQryMarginRate->ParticipantID<<std::endl;
  std::cout<<"on pRspQryMarginRate->TradingRole:"<<pRspQryMarginRate->TradingRole<<std::endl;
  std::cout<<"on pRspQryMarginRate->HedgeFlag:"<<pRspQryMarginRate->HedgeFlag<<std::endl;
  std::cout<<"on pRspQryMarginRate->ValueMode:"<<pRspQryMarginRate->ValueMode<<std::endl;
  std::cout<<"on pRspQryMarginRate->LongMarginRatio:"<<pRspQryMarginRate->LongMarginRatio<<std::endl;
  std::cout<<"on pRspQryMarginRate->ShortMarginRatio:"<<pRspQryMarginRate->ShortMarginRatio<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryMarginRateField* pNewRspQryMarginRate =new CShfeFtdcRspQryMarginRateField;
  memcpy(pNewRspQryMarginRate,pRspQryMarginRate,sizeof(CShfeFtdcRspQryMarginRateField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryMarginRate;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryMarginRateTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryMarginRateTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnMarginRateTopic(CShfeFtdcRtnMarginRateField *pRtnMarginRate)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnMarginRate->ActionDate:"<<pRtnMarginRate->ActionDate<<std::endl;
  std::cout<<"on pRtnMarginRate->ActionTime:"<<pRtnMarginRate->ActionTime<<std::endl;
  std::cout<<"on pRtnMarginRate->InstrumentID:"<<pRtnMarginRate->InstrumentID<<std::endl;
  std::cout<<"on pRtnMarginRate->ParticipantID:"<<pRtnMarginRate->ParticipantID<<std::endl;
  std::cout<<"on pRtnMarginRate->TradingRole:"<<pRtnMarginRate->TradingRole<<std::endl;
  std::cout<<"on pRtnMarginRate->HedgeFlag:"<<pRtnMarginRate->HedgeFlag<<std::endl;
  std::cout<<"on pRtnMarginRate->ValueMode:"<<pRtnMarginRate->ValueMode<<std::endl;
  std::cout<<"on pRtnMarginRate->LongMarginRatio:"<<pRtnMarginRate->LongMarginRatio<<std::endl;
  std::cout<<"on pRtnMarginRate->ShortMarginRatio:"<<pRtnMarginRate->ShortMarginRatio<<std::endl;
  CShfeFtdcRtnMarginRateField* pNewRtnMarginRate =new CShfeFtdcRtnMarginRateField;
  memcpy(pNewRtnMarginRate,pRtnMarginRate,sizeof(CShfeFtdcRtnMarginRateField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnMarginRate;
  asyncOnRtnMarginRateTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnMarginRateTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryPriceLimitTopic(CShfeFtdcRspQryPriceLimitField *pRspQryPriceLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryPriceLimit->ActionDate:"<<pRspQryPriceLimit->ActionDate<<std::endl;
  std::cout<<"on pRspQryPriceLimit->ActionTime:"<<pRspQryPriceLimit->ActionTime<<std::endl;
  std::cout<<"on pRspQryPriceLimit->InstrumentID:"<<pRspQryPriceLimit->InstrumentID<<std::endl;
  std::cout<<"on pRspQryPriceLimit->ValueMode:"<<pRspQryPriceLimit->ValueMode<<std::endl;
  std::cout<<"on pRspQryPriceLimit->RoundingMode:"<<pRspQryPriceLimit->RoundingMode<<std::endl;
  std::cout<<"on pRspQryPriceLimit->UpperLimitPrice:"<<pRspQryPriceLimit->UpperLimitPrice<<std::endl;
  std::cout<<"on pRspQryPriceLimit->LowerLimitPrice:"<<pRspQryPriceLimit->LowerLimitPrice<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryPriceLimitField* pNewRspQryPriceLimit =new CShfeFtdcRspQryPriceLimitField;
  memcpy(pNewRspQryPriceLimit,pRspQryPriceLimit,sizeof(CShfeFtdcRspQryPriceLimitField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryPriceLimit;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryPriceLimitTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryPriceLimitTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnPriceLimitTopic(CShfeFtdcRtnPriceLimitField *pRtnPriceLimit)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnPriceLimit->ActionDate:"<<pRtnPriceLimit->ActionDate<<std::endl;
  std::cout<<"on pRtnPriceLimit->ActionTime:"<<pRtnPriceLimit->ActionTime<<std::endl;
  std::cout<<"on pRtnPriceLimit->InstrumentID:"<<pRtnPriceLimit->InstrumentID<<std::endl;
  std::cout<<"on pRtnPriceLimit->ValueMode:"<<pRtnPriceLimit->ValueMode<<std::endl;
  std::cout<<"on pRtnPriceLimit->RoundingMode:"<<pRtnPriceLimit->RoundingMode<<std::endl;
  std::cout<<"on pRtnPriceLimit->UpperLimitPrice:"<<pRtnPriceLimit->UpperLimitPrice<<std::endl;
  std::cout<<"on pRtnPriceLimit->LowerLimitPrice:"<<pRtnPriceLimit->LowerLimitPrice<<std::endl;
  CShfeFtdcRtnPriceLimitField* pNewRtnPriceLimit =new CShfeFtdcRtnPriceLimitField;
  memcpy(pNewRtnPriceLimit,pRtnPriceLimit,sizeof(CShfeFtdcRtnPriceLimitField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnPriceLimit;
  asyncOnRtnPriceLimitTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnPriceLimitTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryPartPosiLimitTopic(CShfeFtdcRspQryPartPosiLimitField *pRspQryPartPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryPartPosiLimit->ActionDate:"<<pRspQryPartPosiLimit->ActionDate<<std::endl;
  std::cout<<"on pRspQryPartPosiLimit->ActionTime:"<<pRspQryPartPosiLimit->ActionTime<<std::endl;
  std::cout<<"on pRspQryPartPosiLimit->InstrumentID:"<<pRspQryPartPosiLimit->InstrumentID<<std::endl;
  std::cout<<"on pRspQryPartPosiLimit->ParticipantID:"<<pRspQryPartPosiLimit->ParticipantID<<std::endl;
  std::cout<<"on pRspQryPartPosiLimit->TradingRole:"<<pRspQryPartPosiLimit->TradingRole<<std::endl;
  std::cout<<"on pRspQryPartPosiLimit->StartTotalPosition:"<<pRspQryPartPosiLimit->StartTotalPosition<<std::endl;
  std::cout<<"on pRspQryPartPosiLimit->ValueMode:"<<pRspQryPartPosiLimit->ValueMode<<std::endl;
  std::cout<<"on pRspQryPartPosiLimit->LongPosLimit:"<<pRspQryPartPosiLimit->LongPosLimit<<std::endl;
  std::cout<<"on pRspQryPartPosiLimit->ShortPosLimit:"<<pRspQryPartPosiLimit->ShortPosLimit<<std::endl;
  std::cout<<"on pRspQryPartPosiLimit->UpperLimitPrice:"<<pRspQryPartPosiLimit->UpperLimitPrice<<std::endl;
  std::cout<<"on pRspQryPartPosiLimit->LowerLimitPrice:"<<pRspQryPartPosiLimit->LowerLimitPrice<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryPartPosiLimitField* pNewRspQryPartPosiLimit =new CShfeFtdcRspQryPartPosiLimitField;
  memcpy(pNewRspQryPartPosiLimit,pRspQryPartPosiLimit,sizeof(CShfeFtdcRspQryPartPosiLimitField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryPartPosiLimit;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryPartPosiLimitTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryPartPosiLimitTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnPartPosiLimitTopic(CShfeFtdcRtnPartPosiLimitField *pRtnPartPosiLimit)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnPartPosiLimit->ActionDate:"<<pRtnPartPosiLimit->ActionDate<<std::endl;
  std::cout<<"on pRtnPartPosiLimit->ActionTime:"<<pRtnPartPosiLimit->ActionTime<<std::endl;
  std::cout<<"on pRtnPartPosiLimit->InstrumentID:"<<pRtnPartPosiLimit->InstrumentID<<std::endl;
  std::cout<<"on pRtnPartPosiLimit->ParticipantID:"<<pRtnPartPosiLimit->ParticipantID<<std::endl;
  std::cout<<"on pRtnPartPosiLimit->TradingRole:"<<pRtnPartPosiLimit->TradingRole<<std::endl;
  std::cout<<"on pRtnPartPosiLimit->StartTotalPosition:"<<pRtnPartPosiLimit->StartTotalPosition<<std::endl;
  std::cout<<"on pRtnPartPosiLimit->ValueMode:"<<pRtnPartPosiLimit->ValueMode<<std::endl;
  std::cout<<"on pRtnPartPosiLimit->LongPosLimit:"<<pRtnPartPosiLimit->LongPosLimit<<std::endl;
  std::cout<<"on pRtnPartPosiLimit->ShortPosLimit:"<<pRtnPartPosiLimit->ShortPosLimit<<std::endl;
  std::cout<<"on pRtnPartPosiLimit->UpperLimitPrice:"<<pRtnPartPosiLimit->UpperLimitPrice<<std::endl;
  std::cout<<"on pRtnPartPosiLimit->LowerLimitPrice:"<<pRtnPartPosiLimit->LowerLimitPrice<<std::endl;
  CShfeFtdcRtnPartPosiLimitField* pNewRtnPartPosiLimit =new CShfeFtdcRtnPartPosiLimitField;
  memcpy(pNewRtnPartPosiLimit,pRtnPartPosiLimit,sizeof(CShfeFtdcRtnPartPosiLimitField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnPartPosiLimit;
  asyncOnRtnPartPosiLimitTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnPartPosiLimitTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryClientPosiLimitTopic(CShfeFtdcRspQryClientPosiLimitField *pRspQryClientPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryClientPosiLimit->ActionDate:"<<pRspQryClientPosiLimit->ActionDate<<std::endl;
  std::cout<<"on pRspQryClientPosiLimit->ActionTime:"<<pRspQryClientPosiLimit->ActionTime<<std::endl;
  std::cout<<"on pRspQryClientPosiLimit->InstrumentID:"<<pRspQryClientPosiLimit->InstrumentID<<std::endl;
  std::cout<<"on pRspQryClientPosiLimit->ClientType:"<<pRspQryClientPosiLimit->ClientType<<std::endl;
  std::cout<<"on pRspQryClientPosiLimit->TradingRole:"<<pRspQryClientPosiLimit->TradingRole<<std::endl;
  std::cout<<"on pRspQryClientPosiLimit->StartTotalPosition:"<<pRspQryClientPosiLimit->StartTotalPosition<<std::endl;
  std::cout<<"on pRspQryClientPosiLimit->ValueMode:"<<pRspQryClientPosiLimit->ValueMode<<std::endl;
  std::cout<<"on pRspQryClientPosiLimit->LongPosLimit:"<<pRspQryClientPosiLimit->LongPosLimit<<std::endl;
  std::cout<<"on pRspQryClientPosiLimit->ShortPosLimit:"<<pRspQryClientPosiLimit->ShortPosLimit<<std::endl;
  std::cout<<"on pRspQryClientPosiLimit->UpperLimitPrice:"<<pRspQryClientPosiLimit->UpperLimitPrice<<std::endl;
  std::cout<<"on pRspQryClientPosiLimit->LowerLimitPrice:"<<pRspQryClientPosiLimit->LowerLimitPrice<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryClientPosiLimitField* pNewRspQryClientPosiLimit =new CShfeFtdcRspQryClientPosiLimitField;
  memcpy(pNewRspQryClientPosiLimit,pRspQryClientPosiLimit,sizeof(CShfeFtdcRspQryClientPosiLimitField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryClientPosiLimit;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryClientPosiLimitTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryClientPosiLimitTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnClientPosiLimitTopic(CShfeFtdcRtnClientPosiLimitField *pRtnClientPosiLimit)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnClientPosiLimit->ActionDate:"<<pRtnClientPosiLimit->ActionDate<<std::endl;
  std::cout<<"on pRtnClientPosiLimit->ActionTime:"<<pRtnClientPosiLimit->ActionTime<<std::endl;
  std::cout<<"on pRtnClientPosiLimit->InstrumentID:"<<pRtnClientPosiLimit->InstrumentID<<std::endl;
  std::cout<<"on pRtnClientPosiLimit->ClientType:"<<pRtnClientPosiLimit->ClientType<<std::endl;
  std::cout<<"on pRtnClientPosiLimit->TradingRole:"<<pRtnClientPosiLimit->TradingRole<<std::endl;
  std::cout<<"on pRtnClientPosiLimit->StartTotalPosition:"<<pRtnClientPosiLimit->StartTotalPosition<<std::endl;
  std::cout<<"on pRtnClientPosiLimit->ValueMode:"<<pRtnClientPosiLimit->ValueMode<<std::endl;
  std::cout<<"on pRtnClientPosiLimit->LongPosLimit:"<<pRtnClientPosiLimit->LongPosLimit<<std::endl;
  std::cout<<"on pRtnClientPosiLimit->ShortPosLimit:"<<pRtnClientPosiLimit->ShortPosLimit<<std::endl;
  std::cout<<"on pRtnClientPosiLimit->UpperLimitPrice:"<<pRtnClientPosiLimit->UpperLimitPrice<<std::endl;
  std::cout<<"on pRtnClientPosiLimit->LowerLimitPrice:"<<pRtnClientPosiLimit->LowerLimitPrice<<std::endl;
  CShfeFtdcRtnClientPosiLimitField* pNewRtnClientPosiLimit =new CShfeFtdcRtnClientPosiLimitField;
  memcpy(pNewRtnClientPosiLimit,pRtnClientPosiLimit,sizeof(CShfeFtdcRtnClientPosiLimitField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnClientPosiLimit;
  asyncOnRtnClientPosiLimitTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnClientPosiLimitTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQrySpecialPosiLimitTopic(CShfeFtdcRspQrySpecialPosiLimitField *pRspQrySpecialPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQrySpecialPosiLimit->ActionDate:"<<pRspQrySpecialPosiLimit->ActionDate<<std::endl;
  std::cout<<"on pRspQrySpecialPosiLimit->ActionTime:"<<pRspQrySpecialPosiLimit->ActionTime<<std::endl;
  std::cout<<"on pRspQrySpecialPosiLimit->InstrumentID:"<<pRspQrySpecialPosiLimit->InstrumentID<<std::endl;
  std::cout<<"on pRspQrySpecialPosiLimit->ClientID:"<<pRspQrySpecialPosiLimit->ClientID<<std::endl;
  std::cout<<"on pRspQrySpecialPosiLimit->TradingRole:"<<pRspQrySpecialPosiLimit->TradingRole<<std::endl;
  std::cout<<"on pRspQrySpecialPosiLimit->StartTotalPosition:"<<pRspQrySpecialPosiLimit->StartTotalPosition<<std::endl;
  std::cout<<"on pRspQrySpecialPosiLimit->ValueMode:"<<pRspQrySpecialPosiLimit->ValueMode<<std::endl;
  std::cout<<"on pRspQrySpecialPosiLimit->LongPosLimit:"<<pRspQrySpecialPosiLimit->LongPosLimit<<std::endl;
  std::cout<<"on pRspQrySpecialPosiLimit->ShortPosLimit:"<<pRspQrySpecialPosiLimit->ShortPosLimit<<std::endl;
  std::cout<<"on pRspQrySpecialPosiLimit->UpperLimitPrice:"<<pRspQrySpecialPosiLimit->UpperLimitPrice<<std::endl;
  std::cout<<"on pRspQrySpecialPosiLimit->LowerLimitPrice:"<<pRspQrySpecialPosiLimit->LowerLimitPrice<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQrySpecialPosiLimitField* pNewRspQrySpecialPosiLimit =new CShfeFtdcRspQrySpecialPosiLimitField;
  memcpy(pNewRspQrySpecialPosiLimit,pRspQrySpecialPosiLimit,sizeof(CShfeFtdcRspQrySpecialPosiLimitField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySpecialPosiLimit;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySpecialPosiLimitTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQrySpecialPosiLimitTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnSpecialPosiLimitTopic(CShfeFtdcRtnSpecialPosiLimitField *pRtnSpecialPosiLimit)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnSpecialPosiLimit->ActionDate:"<<pRtnSpecialPosiLimit->ActionDate<<std::endl;
  std::cout<<"on pRtnSpecialPosiLimit->ActionTime:"<<pRtnSpecialPosiLimit->ActionTime<<std::endl;
  std::cout<<"on pRtnSpecialPosiLimit->InstrumentID:"<<pRtnSpecialPosiLimit->InstrumentID<<std::endl;
  std::cout<<"on pRtnSpecialPosiLimit->ClientID:"<<pRtnSpecialPosiLimit->ClientID<<std::endl;
  std::cout<<"on pRtnSpecialPosiLimit->TradingRole:"<<pRtnSpecialPosiLimit->TradingRole<<std::endl;
  std::cout<<"on pRtnSpecialPosiLimit->StartTotalPosition:"<<pRtnSpecialPosiLimit->StartTotalPosition<<std::endl;
  std::cout<<"on pRtnSpecialPosiLimit->ValueMode:"<<pRtnSpecialPosiLimit->ValueMode<<std::endl;
  std::cout<<"on pRtnSpecialPosiLimit->LongPosLimit:"<<pRtnSpecialPosiLimit->LongPosLimit<<std::endl;
  std::cout<<"on pRtnSpecialPosiLimit->ShortPosLimit:"<<pRtnSpecialPosiLimit->ShortPosLimit<<std::endl;
  std::cout<<"on pRtnSpecialPosiLimit->UpperLimitPrice:"<<pRtnSpecialPosiLimit->UpperLimitPrice<<std::endl;
  std::cout<<"on pRtnSpecialPosiLimit->LowerLimitPrice:"<<pRtnSpecialPosiLimit->LowerLimitPrice<<std::endl;
  CShfeFtdcRtnSpecialPosiLimitField* pNewRtnSpecialPosiLimit =new CShfeFtdcRtnSpecialPosiLimitField;
  memcpy(pNewRtnSpecialPosiLimit,pRtnSpecialPosiLimit,sizeof(CShfeFtdcRtnSpecialPosiLimitField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSpecialPosiLimit;
  asyncOnRtnSpecialPosiLimitTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnSpecialPosiLimitTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryTransactionChgTopic(CShfeFtdcRspQryTransactionChgField *pRspQryTransactionChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryTransactionChg->ActionDate:"<<pRspQryTransactionChg->ActionDate<<std::endl;
  std::cout<<"on pRspQryTransactionChg->ActionTime:"<<pRspQryTransactionChg->ActionTime<<std::endl;
  std::cout<<"on pRspQryTransactionChg->BillSN:"<<pRspQryTransactionChg->BillSN<<std::endl;
  std::cout<<"on pRspQryTransactionChg->ParticipantAccount:"<<pRspQryTransactionChg->ParticipantAccount<<std::endl;
  std::cout<<"on pRspQryTransactionChg->ParticipantID:"<<pRspQryTransactionChg->ParticipantID<<std::endl;
  std::cout<<"on pRspQryTransactionChg->Amount:"<<pRspQryTransactionChg->Amount<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryTransactionChgField* pNewRspQryTransactionChg =new CShfeFtdcRspQryTransactionChgField;
  memcpy(pNewRspQryTransactionChg,pRspQryTransactionChg,sizeof(CShfeFtdcRspQryTransactionChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTransactionChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTransactionChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryTransactionChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnTransactionChgTopic(CShfeFtdcRtnTransactionChgField *pRtnTransactionChg)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnTransactionChg->ActionDate:"<<pRtnTransactionChg->ActionDate<<std::endl;
  std::cout<<"on pRtnTransactionChg->ActionTime:"<<pRtnTransactionChg->ActionTime<<std::endl;
  std::cout<<"on pRtnTransactionChg->BillSN:"<<pRtnTransactionChg->BillSN<<std::endl;
  std::cout<<"on pRtnTransactionChg->ParticipantAccount:"<<pRtnTransactionChg->ParticipantAccount<<std::endl;
  std::cout<<"on pRtnTransactionChg->ParticipantID:"<<pRtnTransactionChg->ParticipantID<<std::endl;
  std::cout<<"on pRtnTransactionChg->Amount:"<<pRtnTransactionChg->Amount<<std::endl;
  CShfeFtdcRtnTransactionChgField* pNewRtnTransactionChg =new CShfeFtdcRtnTransactionChgField;
  memcpy(pNewRtnTransactionChg,pRtnTransactionChg,sizeof(CShfeFtdcRtnTransactionChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnTransactionChg;
  asyncOnRtnTransactionChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnTransactionChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryClientChgTopic(CShfeFtdcRspQryClientChgField *pRspQryClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryClientChg->ActionDate:"<<pRspQryClientChg->ActionDate<<std::endl;
  std::cout<<"on pRspQryClientChg->ActionTime:"<<pRspQryClientChg->ActionTime<<std::endl;
  std::cout<<"on pRspQryClientChg->ClientID:"<<pRspQryClientChg->ClientID<<std::endl;
  std::cout<<"on pRspQryClientChg->ClientName:"<<pRspQryClientChg->ClientName<<std::endl;
  std::cout<<"on pRspQryClientChg->ClientType:"<<pRspQryClientChg->ClientType<<std::endl;
  std::cout<<"on pRspQryClientChg->IsActive:"<<pRspQryClientChg->IsActive<<std::endl;
  std::cout<<"on pRspQryClientChg->IdentifiedCardType:"<<pRspQryClientChg->IdentifiedCardType<<std::endl;
  std::cout<<"on pRspQryClientChg->IdentifiedCardNo:"<<pRspQryClientChg->IdentifiedCardNo<<std::endl;
  std::cout<<"on pRspQryClientChg->OperationType:"<<pRspQryClientChg->OperationType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryClientChgField* pNewRspQryClientChg =new CShfeFtdcRspQryClientChgField;
  memcpy(pNewRspQryClientChg,pRspQryClientChg,sizeof(CShfeFtdcRspQryClientChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryClientChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryClientChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryClientChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnClientChgTopic(CShfeFtdcRtnClientChgField *pRtnClientChg)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnClientChg->ActionDate:"<<pRtnClientChg->ActionDate<<std::endl;
  std::cout<<"on pRtnClientChg->ActionTime:"<<pRtnClientChg->ActionTime<<std::endl;
  std::cout<<"on pRtnClientChg->ClientID:"<<pRtnClientChg->ClientID<<std::endl;
  std::cout<<"on pRtnClientChg->ClientName:"<<pRtnClientChg->ClientName<<std::endl;
  std::cout<<"on pRtnClientChg->ClientType:"<<pRtnClientChg->ClientType<<std::endl;
  std::cout<<"on pRtnClientChg->IsActive:"<<pRtnClientChg->IsActive<<std::endl;
  std::cout<<"on pRtnClientChg->IdentifiedCardType:"<<pRtnClientChg->IdentifiedCardType<<std::endl;
  std::cout<<"on pRtnClientChg->IdentifiedCardNo:"<<pRtnClientChg->IdentifiedCardNo<<std::endl;
  std::cout<<"on pRtnClientChg->OperationType:"<<pRtnClientChg->OperationType<<std::endl;
  CShfeFtdcRtnClientChgField* pNewRtnClientChg =new CShfeFtdcRtnClientChgField;
  memcpy(pNewRtnClientChg,pRtnClientChg,sizeof(CShfeFtdcRtnClientChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnClientChg;
  asyncOnRtnClientChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnClientChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryPartClientChgTopic(CShfeFtdcRspQryPartClientChgField *pRspQryPartClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryPartClientChg->ActionDate:"<<pRspQryPartClientChg->ActionDate<<std::endl;
  std::cout<<"on pRspQryPartClientChg->ActionTime:"<<pRspQryPartClientChg->ActionTime<<std::endl;
  std::cout<<"on pRspQryPartClientChg->ClientID:"<<pRspQryPartClientChg->ClientID<<std::endl;
  std::cout<<"on pRspQryPartClientChg->ParticipantID:"<<pRspQryPartClientChg->ParticipantID<<std::endl;
  std::cout<<"on pRspQryPartClientChg->OperationType:"<<pRspQryPartClientChg->OperationType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryPartClientChgField* pNewRspQryPartClientChg =new CShfeFtdcRspQryPartClientChgField;
  memcpy(pNewRspQryPartClientChg,pRspQryPartClientChg,sizeof(CShfeFtdcRspQryPartClientChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryPartClientChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryPartClientChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryPartClientChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnPartClientChgTopic(CShfeFtdcRtnPartClientChgField *pRtnPartClientChg)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnPartClientChg->ActionDate:"<<pRtnPartClientChg->ActionDate<<std::endl;
  std::cout<<"on pRtnPartClientChg->ActionTime:"<<pRtnPartClientChg->ActionTime<<std::endl;
  std::cout<<"on pRtnPartClientChg->ClientID:"<<pRtnPartClientChg->ClientID<<std::endl;
  std::cout<<"on pRtnPartClientChg->ParticipantID:"<<pRtnPartClientChg->ParticipantID<<std::endl;
  std::cout<<"on pRtnPartClientChg->OperationType:"<<pRtnPartClientChg->OperationType<<std::endl;
  CShfeFtdcRtnPartClientChgField* pNewRtnPartClientChg =new CShfeFtdcRtnPartClientChgField;
  memcpy(pNewRtnPartClientChg,pRtnPartClientChg,sizeof(CShfeFtdcRtnPartClientChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnPartClientChg;
  asyncOnRtnPartClientChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnPartClientChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryPosiLimitChgTopic(CShfeFtdcRspQryPosiLimitChgField *pRspQryPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryPosiLimitChg->ActionDate:"<<pRspQryPosiLimitChg->ActionDate<<std::endl;
  std::cout<<"on pRspQryPosiLimitChg->ActionTime:"<<pRspQryPosiLimitChg->ActionTime<<std::endl;
  std::cout<<"on pRspQryPosiLimitChg->InstrumentID:"<<pRspQryPosiLimitChg->InstrumentID<<std::endl;
  std::cout<<"on pRspQryPosiLimitChg->ParticipantID:"<<pRspQryPosiLimitChg->ParticipantID<<std::endl;
  std::cout<<"on pRspQryPosiLimitChg->TradingRole:"<<pRspQryPosiLimitChg->TradingRole<<std::endl;
  std::cout<<"on pRspQryPosiLimitChg->StartTotalPosition:"<<pRspQryPosiLimitChg->StartTotalPosition<<std::endl;
  std::cout<<"on pRspQryPosiLimitChg->ValueMode:"<<pRspQryPosiLimitChg->ValueMode<<std::endl;
  std::cout<<"on pRspQryPosiLimitChg->LongPosLimit:"<<pRspQryPosiLimitChg->LongPosLimit<<std::endl;
  std::cout<<"on pRspQryPosiLimitChg->ShortPosLimit:"<<pRspQryPosiLimitChg->ShortPosLimit<<std::endl;
  std::cout<<"on pRspQryPosiLimitChg->OperationType:"<<pRspQryPosiLimitChg->OperationType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryPosiLimitChgField* pNewRspQryPosiLimitChg =new CShfeFtdcRspQryPosiLimitChgField;
  memcpy(pNewRspQryPosiLimitChg,pRspQryPosiLimitChg,sizeof(CShfeFtdcRspQryPosiLimitChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryPosiLimitChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryPosiLimitChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryPosiLimitChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnPosiLimitChgTopic(CShfeFtdcRtnPosiLimitChgField *pRtnPosiLimitChg)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnPosiLimitChg->ActionDate:"<<pRtnPosiLimitChg->ActionDate<<std::endl;
  std::cout<<"on pRtnPosiLimitChg->ActionTime:"<<pRtnPosiLimitChg->ActionTime<<std::endl;
  std::cout<<"on pRtnPosiLimitChg->InstrumentID:"<<pRtnPosiLimitChg->InstrumentID<<std::endl;
  std::cout<<"on pRtnPosiLimitChg->ParticipantID:"<<pRtnPosiLimitChg->ParticipantID<<std::endl;
  std::cout<<"on pRtnPosiLimitChg->TradingRole:"<<pRtnPosiLimitChg->TradingRole<<std::endl;
  std::cout<<"on pRtnPosiLimitChg->StartTotalPosition:"<<pRtnPosiLimitChg->StartTotalPosition<<std::endl;
  std::cout<<"on pRtnPosiLimitChg->ValueMode:"<<pRtnPosiLimitChg->ValueMode<<std::endl;
  std::cout<<"on pRtnPosiLimitChg->LongPosLimit:"<<pRtnPosiLimitChg->LongPosLimit<<std::endl;
  std::cout<<"on pRtnPosiLimitChg->ShortPosLimit:"<<pRtnPosiLimitChg->ShortPosLimit<<std::endl;
  std::cout<<"on pRtnPosiLimitChg->OperationType:"<<pRtnPosiLimitChg->OperationType<<std::endl;
  CShfeFtdcRtnPosiLimitChgField* pNewRtnPosiLimitChg =new CShfeFtdcRtnPosiLimitChgField;
  memcpy(pNewRtnPosiLimitChg,pRtnPosiLimitChg,sizeof(CShfeFtdcRtnPosiLimitChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnPosiLimitChg;
  asyncOnRtnPosiLimitChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnPosiLimitChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryHedgeDetailChgTopic(CShfeFtdcRspQryHedgeDetailChgField *pRspQryHedgeDetailChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryHedgeDetailChg->ActionDate:"<<pRspQryHedgeDetailChg->ActionDate<<std::endl;
  std::cout<<"on pRspQryHedgeDetailChg->ActionTime:"<<pRspQryHedgeDetailChg->ActionTime<<std::endl;
  std::cout<<"on pRspQryHedgeDetailChg->ParticipantID:"<<pRspQryHedgeDetailChg->ParticipantID<<std::endl;
  std::cout<<"on pRspQryHedgeDetailChg->ClientID:"<<pRspQryHedgeDetailChg->ClientID<<std::endl;
  std::cout<<"on pRspQryHedgeDetailChg->OperatorID:"<<pRspQryHedgeDetailChg->OperatorID<<std::endl;
  std::cout<<"on pRspQryHedgeDetailChg->Time:"<<pRspQryHedgeDetailChg->Time<<std::endl;
  std::cout<<"on pRspQryHedgeDetailChg->InstrumentID:"<<pRspQryHedgeDetailChg->InstrumentID<<std::endl;
  std::cout<<"on pRspQryHedgeDetailChg->PosiDirection:"<<pRspQryHedgeDetailChg->PosiDirection<<std::endl;
  std::cout<<"on pRspQryHedgeDetailChg->TradingVolume:"<<pRspQryHedgeDetailChg->TradingVolume<<std::endl;
  std::cout<<"on pRspQryHedgeDetailChg->HedgeQuota:"<<pRspQryHedgeDetailChg->HedgeQuota<<std::endl;
  std::cout<<"on pRspQryHedgeDetailChg->OperationType:"<<pRspQryHedgeDetailChg->OperationType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryHedgeDetailChgField* pNewRspQryHedgeDetailChg =new CShfeFtdcRspQryHedgeDetailChgField;
  memcpy(pNewRspQryHedgeDetailChg,pRspQryHedgeDetailChg,sizeof(CShfeFtdcRspQryHedgeDetailChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryHedgeDetailChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryHedgeDetailChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryHedgeDetailChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnHedgeDetailChgTopic(CShfeFtdcRtnHedgeDetailChgField *pRtnHedgeDetailChg)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnHedgeDetailChg->ActionDate:"<<pRtnHedgeDetailChg->ActionDate<<std::endl;
  std::cout<<"on pRtnHedgeDetailChg->ActionTime:"<<pRtnHedgeDetailChg->ActionTime<<std::endl;
  std::cout<<"on pRtnHedgeDetailChg->ParticipantID:"<<pRtnHedgeDetailChg->ParticipantID<<std::endl;
  std::cout<<"on pRtnHedgeDetailChg->ClientID:"<<pRtnHedgeDetailChg->ClientID<<std::endl;
  std::cout<<"on pRtnHedgeDetailChg->OperatorID:"<<pRtnHedgeDetailChg->OperatorID<<std::endl;
  std::cout<<"on pRtnHedgeDetailChg->Time:"<<pRtnHedgeDetailChg->Time<<std::endl;
  std::cout<<"on pRtnHedgeDetailChg->InstrumentID:"<<pRtnHedgeDetailChg->InstrumentID<<std::endl;
  std::cout<<"on pRtnHedgeDetailChg->PosiDirection:"<<pRtnHedgeDetailChg->PosiDirection<<std::endl;
  std::cout<<"on pRtnHedgeDetailChg->TradingVolume:"<<pRtnHedgeDetailChg->TradingVolume<<std::endl;
  std::cout<<"on pRtnHedgeDetailChg->HedgeQuota:"<<pRtnHedgeDetailChg->HedgeQuota<<std::endl;
  std::cout<<"on pRtnHedgeDetailChg->OperationType:"<<pRtnHedgeDetailChg->OperationType<<std::endl;
  CShfeFtdcRtnHedgeDetailChgField* pNewRtnHedgeDetailChg =new CShfeFtdcRtnHedgeDetailChgField;
  memcpy(pNewRtnHedgeDetailChg,pRtnHedgeDetailChg,sizeof(CShfeFtdcRtnHedgeDetailChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnHedgeDetailChg;
  asyncOnRtnHedgeDetailChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnHedgeDetailChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryParticipantChgTopic(CShfeFtdcRspQryParticipantChgField *pRspQryParticipantChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryParticipantChg->ActionDate:"<<pRspQryParticipantChg->ActionDate<<std::endl;
  std::cout<<"on pRspQryParticipantChg->ActionTime:"<<pRspQryParticipantChg->ActionTime<<std::endl;
  std::cout<<"on pRspQryParticipantChg->ParticipantID:"<<pRspQryParticipantChg->ParticipantID<<std::endl;
  std::cout<<"on pRspQryParticipantChg->ParticipantName:"<<pRspQryParticipantChg->ParticipantName<<std::endl;
  std::cout<<"on pRspQryParticipantChg->ParticipantAbbr:"<<pRspQryParticipantChg->ParticipantAbbr<<std::endl;
  std::cout<<"on pRspQryParticipantChg->MemberType:"<<pRspQryParticipantChg->MemberType<<std::endl;
  std::cout<<"on pRspQryParticipantChg->IsActive:"<<pRspQryParticipantChg->IsActive<<std::endl;
  std::cout<<"on pRspQryParticipantChg->OperationType:"<<pRspQryParticipantChg->OperationType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryParticipantChgField* pNewRspQryParticipantChg =new CShfeFtdcRspQryParticipantChgField;
  memcpy(pNewRspQryParticipantChg,pRspQryParticipantChg,sizeof(CShfeFtdcRspQryParticipantChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryParticipantChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryParticipantChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryParticipantChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnParticipantChgTopic(CShfeFtdcRtnParticipantChgField *pRtnParticipantChg)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnParticipantChg->ActionDate:"<<pRtnParticipantChg->ActionDate<<std::endl;
  std::cout<<"on pRtnParticipantChg->ActionTime:"<<pRtnParticipantChg->ActionTime<<std::endl;
  std::cout<<"on pRtnParticipantChg->ParticipantID:"<<pRtnParticipantChg->ParticipantID<<std::endl;
  std::cout<<"on pRtnParticipantChg->ParticipantName:"<<pRtnParticipantChg->ParticipantName<<std::endl;
  std::cout<<"on pRtnParticipantChg->ParticipantAbbr:"<<pRtnParticipantChg->ParticipantAbbr<<std::endl;
  std::cout<<"on pRtnParticipantChg->MemberType:"<<pRtnParticipantChg->MemberType<<std::endl;
  std::cout<<"on pRtnParticipantChg->IsActive:"<<pRtnParticipantChg->IsActive<<std::endl;
  std::cout<<"on pRtnParticipantChg->OperationType:"<<pRtnParticipantChg->OperationType<<std::endl;
  CShfeFtdcRtnParticipantChgField* pNewRtnParticipantChg =new CShfeFtdcRtnParticipantChgField;
  memcpy(pNewRtnParticipantChg,pRtnParticipantChg,sizeof(CShfeFtdcRtnParticipantChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnParticipantChg;
  asyncOnRtnParticipantChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnParticipantChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryMarginRateChgTopic(CShfeFtdcRspQryMarginRateChgField *pRspQryMarginRateChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryMarginRateChg->ActionDate:"<<pRspQryMarginRateChg->ActionDate<<std::endl;
  std::cout<<"on pRspQryMarginRateChg->ActionTime:"<<pRspQryMarginRateChg->ActionTime<<std::endl;
  std::cout<<"on pRspQryMarginRateChg->InstrumentID:"<<pRspQryMarginRateChg->InstrumentID<<std::endl;
  std::cout<<"on pRspQryMarginRateChg->ParticipantID:"<<pRspQryMarginRateChg->ParticipantID<<std::endl;
  std::cout<<"on pRspQryMarginRateChg->TradingRole:"<<pRspQryMarginRateChg->TradingRole<<std::endl;
  std::cout<<"on pRspQryMarginRateChg->HedgeFlag:"<<pRspQryMarginRateChg->HedgeFlag<<std::endl;
  std::cout<<"on pRspQryMarginRateChg->ValueMode:"<<pRspQryMarginRateChg->ValueMode<<std::endl;
  std::cout<<"on pRspQryMarginRateChg->LongMarginRatio:"<<pRspQryMarginRateChg->LongMarginRatio<<std::endl;
  std::cout<<"on pRspQryMarginRateChg->ShortMarginRatio:"<<pRspQryMarginRateChg->ShortMarginRatio<<std::endl;
  std::cout<<"on pRspQryMarginRateChg->OperationType:"<<pRspQryMarginRateChg->OperationType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryMarginRateChgField* pNewRspQryMarginRateChg =new CShfeFtdcRspQryMarginRateChgField;
  memcpy(pNewRspQryMarginRateChg,pRspQryMarginRateChg,sizeof(CShfeFtdcRspQryMarginRateChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryMarginRateChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryMarginRateChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryMarginRateChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnMarginRateChgTopic(CShfeFtdcRtnMarginRateChgField *pRtnMarginRateChg)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnMarginRateChg->ActionDate:"<<pRtnMarginRateChg->ActionDate<<std::endl;
  std::cout<<"on pRtnMarginRateChg->ActionTime:"<<pRtnMarginRateChg->ActionTime<<std::endl;
  std::cout<<"on pRtnMarginRateChg->InstrumentID:"<<pRtnMarginRateChg->InstrumentID<<std::endl;
  std::cout<<"on pRtnMarginRateChg->ParticipantID:"<<pRtnMarginRateChg->ParticipantID<<std::endl;
  std::cout<<"on pRtnMarginRateChg->TradingRole:"<<pRtnMarginRateChg->TradingRole<<std::endl;
  std::cout<<"on pRtnMarginRateChg->HedgeFlag:"<<pRtnMarginRateChg->HedgeFlag<<std::endl;
  std::cout<<"on pRtnMarginRateChg->ValueMode:"<<pRtnMarginRateChg->ValueMode<<std::endl;
  std::cout<<"on pRtnMarginRateChg->LongMarginRatio:"<<pRtnMarginRateChg->LongMarginRatio<<std::endl;
  std::cout<<"on pRtnMarginRateChg->ShortMarginRatio:"<<pRtnMarginRateChg->ShortMarginRatio<<std::endl;
  std::cout<<"on pRtnMarginRateChg->OperationType:"<<pRtnMarginRateChg->OperationType<<std::endl;
  CShfeFtdcRtnMarginRateChgField* pNewRtnMarginRateChg =new CShfeFtdcRtnMarginRateChgField;
  memcpy(pNewRtnMarginRateChg,pRtnMarginRateChg,sizeof(CShfeFtdcRtnMarginRateChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnMarginRateChg;
  asyncOnRtnMarginRateChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnMarginRateChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryUserIpChgTopic(CShfeFtdcRspQryUserIpChgField *pRspQryUserIpChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryUserIpChg->ActionDate:"<<pRspQryUserIpChg->ActionDate<<std::endl;
  std::cout<<"on pRspQryUserIpChg->ActionTime:"<<pRspQryUserIpChg->ActionTime<<std::endl;
  std::cout<<"on pRspQryUserIpChg->UserID:"<<pRspQryUserIpChg->UserID<<std::endl;
  std::cout<<"on pRspQryUserIpChg->IPAddress:"<<pRspQryUserIpChg->IPAddress<<std::endl;
  std::cout<<"on pRspQryUserIpChg->IPMask:"<<pRspQryUserIpChg->IPMask<<std::endl;
  std::cout<<"on pRspQryUserIpChg->OperationType:"<<pRspQryUserIpChg->OperationType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryUserIpChgField* pNewRspQryUserIpChg =new CShfeFtdcRspQryUserIpChgField;
  memcpy(pNewRspQryUserIpChg,pRspQryUserIpChg,sizeof(CShfeFtdcRspQryUserIpChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryUserIpChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryUserIpChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryUserIpChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnUserIpChgTopic(CShfeFtdcRtnUserIpChgField *pRtnUserIpChg)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnUserIpChg->ActionDate:"<<pRtnUserIpChg->ActionDate<<std::endl;
  std::cout<<"on pRtnUserIpChg->ActionTime:"<<pRtnUserIpChg->ActionTime<<std::endl;
  std::cout<<"on pRtnUserIpChg->UserID:"<<pRtnUserIpChg->UserID<<std::endl;
  std::cout<<"on pRtnUserIpChg->IPAddress:"<<pRtnUserIpChg->IPAddress<<std::endl;
  std::cout<<"on pRtnUserIpChg->IPMask:"<<pRtnUserIpChg->IPMask<<std::endl;
  std::cout<<"on pRtnUserIpChg->OperationType:"<<pRtnUserIpChg->OperationType<<std::endl;
  CShfeFtdcRtnUserIpChgField* pNewRtnUserIpChg =new CShfeFtdcRtnUserIpChgField;
  memcpy(pNewRtnUserIpChg,pRtnUserIpChg,sizeof(CShfeFtdcRtnUserIpChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnUserIpChg;
  asyncOnRtnUserIpChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnUserIpChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryClientPosiLimitChgTopic(CShfeFtdcRspQryClientPosiLimitChgField *pRspQryClientPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryClientPosiLimitChg->ActionDate:"<<pRspQryClientPosiLimitChg->ActionDate<<std::endl;
  std::cout<<"on pRspQryClientPosiLimitChg->ActionTime:"<<pRspQryClientPosiLimitChg->ActionTime<<std::endl;
  std::cout<<"on pRspQryClientPosiLimitChg->InstrumentID:"<<pRspQryClientPosiLimitChg->InstrumentID<<std::endl;
  std::cout<<"on pRspQryClientPosiLimitChg->ClientType:"<<pRspQryClientPosiLimitChg->ClientType<<std::endl;
  std::cout<<"on pRspQryClientPosiLimitChg->TradingRole:"<<pRspQryClientPosiLimitChg->TradingRole<<std::endl;
  std::cout<<"on pRspQryClientPosiLimitChg->StartTotalPosition:"<<pRspQryClientPosiLimitChg->StartTotalPosition<<std::endl;
  std::cout<<"on pRspQryClientPosiLimitChg->ValueMode:"<<pRspQryClientPosiLimitChg->ValueMode<<std::endl;
  std::cout<<"on pRspQryClientPosiLimitChg->LongPosLimit:"<<pRspQryClientPosiLimitChg->LongPosLimit<<std::endl;
  std::cout<<"on pRspQryClientPosiLimitChg->ShortPosLimit:"<<pRspQryClientPosiLimitChg->ShortPosLimit<<std::endl;
  std::cout<<"on pRspQryClientPosiLimitChg->OperationType:"<<pRspQryClientPosiLimitChg->OperationType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryClientPosiLimitChgField* pNewRspQryClientPosiLimitChg =new CShfeFtdcRspQryClientPosiLimitChgField;
  memcpy(pNewRspQryClientPosiLimitChg,pRspQryClientPosiLimitChg,sizeof(CShfeFtdcRspQryClientPosiLimitChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryClientPosiLimitChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryClientPosiLimitChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryClientPosiLimitChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnClientPosiLimitChgTopic(CShfeFtdcRtnClientPosiLimitChgField *pRtnClientPosiLimitChg)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnClientPosiLimitChg->ActionDate:"<<pRtnClientPosiLimitChg->ActionDate<<std::endl;
  std::cout<<"on pRtnClientPosiLimitChg->ActionTime:"<<pRtnClientPosiLimitChg->ActionTime<<std::endl;
  std::cout<<"on pRtnClientPosiLimitChg->InstrumentID:"<<pRtnClientPosiLimitChg->InstrumentID<<std::endl;
  std::cout<<"on pRtnClientPosiLimitChg->ClientType:"<<pRtnClientPosiLimitChg->ClientType<<std::endl;
  std::cout<<"on pRtnClientPosiLimitChg->TradingRole:"<<pRtnClientPosiLimitChg->TradingRole<<std::endl;
  std::cout<<"on pRtnClientPosiLimitChg->StartTotalPosition:"<<pRtnClientPosiLimitChg->StartTotalPosition<<std::endl;
  std::cout<<"on pRtnClientPosiLimitChg->ValueMode:"<<pRtnClientPosiLimitChg->ValueMode<<std::endl;
  std::cout<<"on pRtnClientPosiLimitChg->LongPosLimit:"<<pRtnClientPosiLimitChg->LongPosLimit<<std::endl;
  std::cout<<"on pRtnClientPosiLimitChg->ShortPosLimit:"<<pRtnClientPosiLimitChg->ShortPosLimit<<std::endl;
  std::cout<<"on pRtnClientPosiLimitChg->OperationType:"<<pRtnClientPosiLimitChg->OperationType<<std::endl;
  CShfeFtdcRtnClientPosiLimitChgField* pNewRtnClientPosiLimitChg =new CShfeFtdcRtnClientPosiLimitChgField;
  memcpy(pNewRtnClientPosiLimitChg,pRtnClientPosiLimitChg,sizeof(CShfeFtdcRtnClientPosiLimitChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnClientPosiLimitChg;
  asyncOnRtnClientPosiLimitChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnClientPosiLimitChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQrySpecPosiLimitChgTopic(CShfeFtdcRspQrySpecPosiLimitChgField *pRspQrySpecPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQrySpecPosiLimitChg->ActionDate:"<<pRspQrySpecPosiLimitChg->ActionDate<<std::endl;
  std::cout<<"on pRspQrySpecPosiLimitChg->ActionTime:"<<pRspQrySpecPosiLimitChg->ActionTime<<std::endl;
  std::cout<<"on pRspQrySpecPosiLimitChg->InstrumentID:"<<pRspQrySpecPosiLimitChg->InstrumentID<<std::endl;
  std::cout<<"on pRspQrySpecPosiLimitChg->ClientID:"<<pRspQrySpecPosiLimitChg->ClientID<<std::endl;
  std::cout<<"on pRspQrySpecPosiLimitChg->TradingRole:"<<pRspQrySpecPosiLimitChg->TradingRole<<std::endl;
  std::cout<<"on pRspQrySpecPosiLimitChg->StartTotalPosition:"<<pRspQrySpecPosiLimitChg->StartTotalPosition<<std::endl;
  std::cout<<"on pRspQrySpecPosiLimitChg->ValueMode:"<<pRspQrySpecPosiLimitChg->ValueMode<<std::endl;
  std::cout<<"on pRspQrySpecPosiLimitChg->LongPosLimit:"<<pRspQrySpecPosiLimitChg->LongPosLimit<<std::endl;
  std::cout<<"on pRspQrySpecPosiLimitChg->ShortPosLimit:"<<pRspQrySpecPosiLimitChg->ShortPosLimit<<std::endl;
  std::cout<<"on pRspQrySpecPosiLimitChg->OperationType:"<<pRspQrySpecPosiLimitChg->OperationType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQrySpecPosiLimitChgField* pNewRspQrySpecPosiLimitChg =new CShfeFtdcRspQrySpecPosiLimitChgField;
  memcpy(pNewRspQrySpecPosiLimitChg,pRspQrySpecPosiLimitChg,sizeof(CShfeFtdcRspQrySpecPosiLimitChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySpecPosiLimitChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySpecPosiLimitChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQrySpecPosiLimitChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnSpecPosiLimitChgTopic(CShfeFtdcRtnSpecPosiLimitChgField *pRtnSpecPosiLimitChg)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnSpecPosiLimitChg->ActionDate:"<<pRtnSpecPosiLimitChg->ActionDate<<std::endl;
  std::cout<<"on pRtnSpecPosiLimitChg->ActionTime:"<<pRtnSpecPosiLimitChg->ActionTime<<std::endl;
  std::cout<<"on pRtnSpecPosiLimitChg->InstrumentID:"<<pRtnSpecPosiLimitChg->InstrumentID<<std::endl;
  std::cout<<"on pRtnSpecPosiLimitChg->ClientID:"<<pRtnSpecPosiLimitChg->ClientID<<std::endl;
  std::cout<<"on pRtnSpecPosiLimitChg->TradingRole:"<<pRtnSpecPosiLimitChg->TradingRole<<std::endl;
  std::cout<<"on pRtnSpecPosiLimitChg->StartTotalPosition:"<<pRtnSpecPosiLimitChg->StartTotalPosition<<std::endl;
  std::cout<<"on pRtnSpecPosiLimitChg->ValueMode:"<<pRtnSpecPosiLimitChg->ValueMode<<std::endl;
  std::cout<<"on pRtnSpecPosiLimitChg->LongPosLimit:"<<pRtnSpecPosiLimitChg->LongPosLimit<<std::endl;
  std::cout<<"on pRtnSpecPosiLimitChg->ShortPosLimit:"<<pRtnSpecPosiLimitChg->ShortPosLimit<<std::endl;
  std::cout<<"on pRtnSpecPosiLimitChg->OperationType:"<<pRtnSpecPosiLimitChg->OperationType<<std::endl;
  CShfeFtdcRtnSpecPosiLimitChgField* pNewRtnSpecPosiLimitChg =new CShfeFtdcRtnSpecPosiLimitChgField;
  memcpy(pNewRtnSpecPosiLimitChg,pRtnSpecPosiLimitChg,sizeof(CShfeFtdcRtnSpecPosiLimitChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSpecPosiLimitChg;
  asyncOnRtnSpecPosiLimitChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnSpecPosiLimitChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryHistoryObjectAttrTopic(CShfeFtdcRspQryHistoryObjectAttrField *pRspQryHistoryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryHistoryObjectAttr->MonDate:"<<pRspQryHistoryObjectAttr->MonDate<<std::endl;
  std::cout<<"on pRspQryHistoryObjectAttr->BeginTime:"<<pRspQryHistoryObjectAttr->BeginTime<<std::endl;
  std::cout<<"on pRspQryHistoryObjectAttr->EndTime:"<<pRspQryHistoryObjectAttr->EndTime<<std::endl;
  std::cout<<"on pRspQryHistoryObjectAttr->ObjectID:"<<pRspQryHistoryObjectAttr->ObjectID<<std::endl;
  std::cout<<"on pRspQryHistoryObjectAttr->AttrType:"<<pRspQryHistoryObjectAttr->AttrType<<std::endl;
  std::cout<<"on pRspQryHistoryObjectAttr->ValueType:"<<pRspQryHistoryObjectAttr->ValueType<<std::endl;
  std::cout<<"on pRspQryHistoryObjectAttr->FirstValue:"<<pRspQryHistoryObjectAttr->FirstValue<<std::endl;
  std::cout<<"on pRspQryHistoryObjectAttr->EndValue:"<<pRspQryHistoryObjectAttr->EndValue<<std::endl;
  std::cout<<"on pRspQryHistoryObjectAttr->AvgValue:"<<pRspQryHistoryObjectAttr->AvgValue<<std::endl;
  std::cout<<"on pRspQryHistoryObjectAttr->MinValue:"<<pRspQryHistoryObjectAttr->MinValue<<std::endl;
  std::cout<<"on pRspQryHistoryObjectAttr->MaxValue:"<<pRspQryHistoryObjectAttr->MaxValue<<std::endl;
  std::cout<<"on pRspQryHistoryObjectAttr->ValueCount:"<<pRspQryHistoryObjectAttr->ValueCount<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryHistoryObjectAttrField* pNewRspQryHistoryObjectAttr =new CShfeFtdcRspQryHistoryObjectAttrField;
  memcpy(pNewRspQryHistoryObjectAttr,pRspQryHistoryObjectAttr,sizeof(CShfeFtdcRspQryHistoryObjectAttrField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryHistoryObjectAttr;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryHistoryObjectAttrTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryHistoryObjectAttrTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnHistoryObjectAttrTopic(CShfeFtdcRtnHistoryObjectAttrField *pRtnHistoryObjectAttr)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnHistoryObjectAttr->MonDate:"<<pRtnHistoryObjectAttr->MonDate<<std::endl;
  std::cout<<"on pRtnHistoryObjectAttr->BeginTime:"<<pRtnHistoryObjectAttr->BeginTime<<std::endl;
  std::cout<<"on pRtnHistoryObjectAttr->EndTime:"<<pRtnHistoryObjectAttr->EndTime<<std::endl;
  std::cout<<"on pRtnHistoryObjectAttr->ObjectID:"<<pRtnHistoryObjectAttr->ObjectID<<std::endl;
  std::cout<<"on pRtnHistoryObjectAttr->AttrType:"<<pRtnHistoryObjectAttr->AttrType<<std::endl;
  std::cout<<"on pRtnHistoryObjectAttr->ValueType:"<<pRtnHistoryObjectAttr->ValueType<<std::endl;
  std::cout<<"on pRtnHistoryObjectAttr->FirstValue:"<<pRtnHistoryObjectAttr->FirstValue<<std::endl;
  std::cout<<"on pRtnHistoryObjectAttr->EndValue:"<<pRtnHistoryObjectAttr->EndValue<<std::endl;
  std::cout<<"on pRtnHistoryObjectAttr->AvgValue:"<<pRtnHistoryObjectAttr->AvgValue<<std::endl;
  std::cout<<"on pRtnHistoryObjectAttr->MinValue:"<<pRtnHistoryObjectAttr->MinValue<<std::endl;
  std::cout<<"on pRtnHistoryObjectAttr->MaxValue:"<<pRtnHistoryObjectAttr->MaxValue<<std::endl;
  std::cout<<"on pRtnHistoryObjectAttr->ValueCount:"<<pRtnHistoryObjectAttr->ValueCount<<std::endl;
  CShfeFtdcRtnHistoryObjectAttrField* pNewRtnHistoryObjectAttr =new CShfeFtdcRtnHistoryObjectAttrField;
  memcpy(pNewRtnHistoryObjectAttr,pRtnHistoryObjectAttr,sizeof(CShfeFtdcRtnHistoryObjectAttrField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnHistoryObjectAttr;
  asyncOnRtnHistoryObjectAttrTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnHistoryObjectAttrTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryFrontInfoTopic(CShfeFtdcRspQryFrontInfoField *pRspQryFrontInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryFrontInfo->MonDate:"<<pRspQryFrontInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryFrontInfo->MonTime:"<<pRspQryFrontInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryFrontInfo->FrontId:"<<pRspQryFrontInfo->FrontId<<std::endl;
  std::cout<<"on pRspQryFrontInfo->RspCondition:"<<pRspQryFrontInfo->RspCondition<<std::endl;
  std::cout<<"on pRspQryFrontInfo->ReqCount:"<<pRspQryFrontInfo->ReqCount<<std::endl;
  std::cout<<"on pRspQryFrontInfo->ReqRate:"<<pRspQryFrontInfo->ReqRate<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryFrontInfoField* pNewRspQryFrontInfo =new CShfeFtdcRspQryFrontInfoField;
  memcpy(pNewRspQryFrontInfo,pRspQryFrontInfo,sizeof(CShfeFtdcRspQryFrontInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryFrontInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryFrontInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryFrontInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnFrontInfoTopic(CShfeFtdcRtnFrontInfoField *pRtnFrontInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnFrontInfo->MonDate:"<<pRtnFrontInfo->MonDate<<std::endl;
  std::cout<<"on pRtnFrontInfo->MonTime:"<<pRtnFrontInfo->MonTime<<std::endl;
  std::cout<<"on pRtnFrontInfo->FrontId:"<<pRtnFrontInfo->FrontId<<std::endl;
  std::cout<<"on pRtnFrontInfo->RspCondition:"<<pRtnFrontInfo->RspCondition<<std::endl;
  std::cout<<"on pRtnFrontInfo->ReqCount:"<<pRtnFrontInfo->ReqCount<<std::endl;
  std::cout<<"on pRtnFrontInfo->ReqRate:"<<pRtnFrontInfo->ReqRate<<std::endl;
  CShfeFtdcRtnFrontInfoField* pNewRtnFrontInfo =new CShfeFtdcRtnFrontInfoField;
  memcpy(pNewRtnFrontInfo,pRtnFrontInfo,sizeof(CShfeFtdcRtnFrontInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnFrontInfo;
  asyncOnRtnFrontInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnFrontInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQrySysUserLoginTopic(CShfeFtdcRspQrySysUserLoginField *pRspQrySysUserLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"\n**************** SysUserSpi::OnRspQrySysUserLoginTopic: START **************** "<<std::endl;
  std::cout<<"on pRspQrySysUserLogin->UserID:"<<pRspQrySysUserLogin->UserID<<std::endl;
  std::cout<<"on pRspQrySysUserLogin->TradingDay:"<<pRspQrySysUserLogin->TradingDay<<std::endl;
  std::cout<<"on pRspQrySysUserLogin->LoginTime:"<<pRspQrySysUserLogin->LoginTime<<std::endl;
  std::cout<<"on pRspQrySysUserLogin->Privilege:"<<pRspQrySysUserLogin->Privilege<<std::endl;
  std::cout<<"on pRspQrySysUserLogin->VersionFlag:"<<pRspQrySysUserLogin->VersionFlag<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQrySysUserLoginField* pNewRspQrySysUserLogin =new CShfeFtdcRspQrySysUserLoginField;
  memcpy(pNewRspQrySysUserLogin,pRspQrySysUserLogin,sizeof(CShfeFtdcRspQrySysUserLoginField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySysUserLogin;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySysUserLoginTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQrySysUserLoginTopic);
  std::cout<<"****************  SysUserSpi::OnRspQrySysUserLoginTopic: END **************** \n"<<std::endl;
}
void SysUserSpi::OnRspQrySysUserLogoutTopic(CShfeFtdcRspQrySysUserLogoutField *pRspQrySysUserLogout, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQrySysUserLogout->UserID:"<<pRspQrySysUserLogout->UserID<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQrySysUserLogoutField* pNewRspQrySysUserLogout =new CShfeFtdcRspQrySysUserLogoutField;
  memcpy(pNewRspQrySysUserLogout,pRspQrySysUserLogout,sizeof(CShfeFtdcRspQrySysUserLogoutField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySysUserLogout;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySysUserLogoutTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQrySysUserLogoutTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQrySysUserPasswordUpdateTopic(CShfeFtdcRspQrySysUserPasswordUpdateField *pRspQrySysUserPasswordUpdate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQrySysUserPasswordUpdate->UserID:"<<pRspQrySysUserPasswordUpdate->UserID<<std::endl;
  std::cout<<"on pRspQrySysUserPasswordUpdate->PasswordChgMsg:"<<pRspQrySysUserPasswordUpdate->PasswordChgMsg<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQrySysUserPasswordUpdateField* pNewRspQrySysUserPasswordUpdate =new CShfeFtdcRspQrySysUserPasswordUpdateField;
  memcpy(pNewRspQrySysUserPasswordUpdate,pRspQrySysUserPasswordUpdate,sizeof(CShfeFtdcRspQrySysUserPasswordUpdateField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySysUserPasswordUpdate;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySysUserPasswordUpdateTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQrySysUserPasswordUpdateTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQrySysUserRegisterTopic(CShfeFtdcRspQrySysUserRegisterField *pRspQrySysUserRegister, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQrySysUserRegister->UserID:"<<pRspQrySysUserRegister->UserID<<std::endl;
  std::cout<<"on pRspQrySysUserRegister->Privilege:"<<pRspQrySysUserRegister->Privilege<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQrySysUserRegisterField* pNewRspQrySysUserRegister =new CShfeFtdcRspQrySysUserRegisterField;
  memcpy(pNewRspQrySysUserRegister,pRspQrySysUserRegister,sizeof(CShfeFtdcRspQrySysUserRegisterField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySysUserRegister;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySysUserRegisterTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQrySysUserRegisterTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQrySysUserDeleteTopic(CShfeFtdcRspQrySysUserDeleteField *pRspQrySysUserDelete, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQrySysUserDelete->UserID:"<<pRspQrySysUserDelete->UserID<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQrySysUserDeleteField* pNewRspQrySysUserDelete =new CShfeFtdcRspQrySysUserDeleteField;
  memcpy(pNewRspQrySysUserDelete,pRspQrySysUserDelete,sizeof(CShfeFtdcRspQrySysUserDeleteField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySysUserDelete;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySysUserDeleteTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQrySysUserDeleteTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryParticipantInitTopic(CShfeFtdcRspQryParticipantInitField *pRspQryParticipantInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryParticipantInit->ParticipantID:"<<pRspQryParticipantInit->ParticipantID<<std::endl;
  std::cout<<"on pRspQryParticipantInit->ParticipantName:"<<pRspQryParticipantInit->ParticipantName<<std::endl;
  std::cout<<"on pRspQryParticipantInit->ParticipantAbbr:"<<pRspQryParticipantInit->ParticipantAbbr<<std::endl;
  std::cout<<"on pRspQryParticipantInit->MemberType:"<<pRspQryParticipantInit->MemberType<<std::endl;
  std::cout<<"on pRspQryParticipantInit->IsActive:"<<pRspQryParticipantInit->IsActive<<std::endl;
  std::cout<<"on pRspQryParticipantInit->OperationType:"<<pRspQryParticipantInit->OperationType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryParticipantInitField* pNewRspQryParticipantInit =new CShfeFtdcRspQryParticipantInitField;
  memcpy(pNewRspQryParticipantInit,pRspQryParticipantInit,sizeof(CShfeFtdcRspQryParticipantInitField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryParticipantInit;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryParticipantInitTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryParticipantInitTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnParticipantInitTopic(CShfeFtdcRtnParticipantInitField *pRtnParticipantInit)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnParticipantInit->ParticipantID:"<<pRtnParticipantInit->ParticipantID<<std::endl;
  std::cout<<"on pRtnParticipantInit->ParticipantName:"<<pRtnParticipantInit->ParticipantName<<std::endl;
  std::cout<<"on pRtnParticipantInit->ParticipantAbbr:"<<pRtnParticipantInit->ParticipantAbbr<<std::endl;
  std::cout<<"on pRtnParticipantInit->MemberType:"<<pRtnParticipantInit->MemberType<<std::endl;
  std::cout<<"on pRtnParticipantInit->IsActive:"<<pRtnParticipantInit->IsActive<<std::endl;
  std::cout<<"on pRtnParticipantInit->OperationType:"<<pRtnParticipantInit->OperationType<<std::endl;
  CShfeFtdcRtnParticipantInitField* pNewRtnParticipantInit =new CShfeFtdcRtnParticipantInitField;
  memcpy(pNewRtnParticipantInit,pRtnParticipantInit,sizeof(CShfeFtdcRtnParticipantInitField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnParticipantInit;
  asyncOnRtnParticipantInitTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnParticipantInitTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryUserInitTopic(CShfeFtdcRspQryUserInitField *pRspQryUserInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryUserInit->ParticipantID:"<<pRspQryUserInit->ParticipantID<<std::endl;
  std::cout<<"on pRspQryUserInit->UserID:"<<pRspQryUserInit->UserID<<std::endl;
  std::cout<<"on pRspQryUserInit->UserType:"<<pRspQryUserInit->UserType<<std::endl;
  std::cout<<"on pRspQryUserInit->Password:"<<pRspQryUserInit->Password<<std::endl;
  std::cout<<"on pRspQryUserInit->IsActive:"<<pRspQryUserInit->IsActive<<std::endl;
  std::cout<<"on pRspQryUserInit->OperationType:"<<pRspQryUserInit->OperationType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryUserInitField* pNewRspQryUserInit =new CShfeFtdcRspQryUserInitField;
  memcpy(pNewRspQryUserInit,pRspQryUserInit,sizeof(CShfeFtdcRspQryUserInitField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryUserInit;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryUserInitTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryUserInitTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnUserInitTopic(CShfeFtdcRtnUserInitField *pRtnUserInit)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnUserInit->ParticipantID:"<<pRtnUserInit->ParticipantID<<std::endl;
  std::cout<<"on pRtnUserInit->UserID:"<<pRtnUserInit->UserID<<std::endl;
  std::cout<<"on pRtnUserInit->UserType:"<<pRtnUserInit->UserType<<std::endl;
  std::cout<<"on pRtnUserInit->Password:"<<pRtnUserInit->Password<<std::endl;
  std::cout<<"on pRtnUserInit->IsActive:"<<pRtnUserInit->IsActive<<std::endl;
  std::cout<<"on pRtnUserInit->OperationType:"<<pRtnUserInit->OperationType<<std::endl;
  CShfeFtdcRtnUserInitField* pNewRtnUserInit =new CShfeFtdcRtnUserInitField;
  memcpy(pNewRtnUserInit,pRtnUserInit,sizeof(CShfeFtdcRtnUserInitField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnUserInit;
  asyncOnRtnUserInitTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnUserInitTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryClientInitTopic(CShfeFtdcRspQryClientInitField *pRspQryClientInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryClientInit->ClientID:"<<pRspQryClientInit->ClientID<<std::endl;
  std::cout<<"on pRspQryClientInit->ClientName:"<<pRspQryClientInit->ClientName<<std::endl;
  std::cout<<"on pRspQryClientInit->IdentifiedCardType:"<<pRspQryClientInit->IdentifiedCardType<<std::endl;
  std::cout<<"on pRspQryClientInit->IdentifiedCardNo:"<<pRspQryClientInit->IdentifiedCardNo<<std::endl;
  std::cout<<"on pRspQryClientInit->TradingRole:"<<pRspQryClientInit->TradingRole<<std::endl;
  std::cout<<"on pRspQryClientInit->ClientType:"<<pRspQryClientInit->ClientType<<std::endl;
  std::cout<<"on pRspQryClientInit->IsActive:"<<pRspQryClientInit->IsActive<<std::endl;
  std::cout<<"on pRspQryClientInit->OperationType:"<<pRspQryClientInit->OperationType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryClientInitField* pNewRspQryClientInit =new CShfeFtdcRspQryClientInitField;
  memcpy(pNewRspQryClientInit,pRspQryClientInit,sizeof(CShfeFtdcRspQryClientInitField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryClientInit;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryClientInitTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryClientInitTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnClientInitTopic(CShfeFtdcRtnClientInitField *pRtnClientInit)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnClientInit->ClientID:"<<pRtnClientInit->ClientID<<std::endl;
  std::cout<<"on pRtnClientInit->ClientName:"<<pRtnClientInit->ClientName<<std::endl;
  std::cout<<"on pRtnClientInit->IdentifiedCardType:"<<pRtnClientInit->IdentifiedCardType<<std::endl;
  std::cout<<"on pRtnClientInit->IdentifiedCardNo:"<<pRtnClientInit->IdentifiedCardNo<<std::endl;
  std::cout<<"on pRtnClientInit->TradingRole:"<<pRtnClientInit->TradingRole<<std::endl;
  std::cout<<"on pRtnClientInit->ClientType:"<<pRtnClientInit->ClientType<<std::endl;
  std::cout<<"on pRtnClientInit->IsActive:"<<pRtnClientInit->IsActive<<std::endl;
  std::cout<<"on pRtnClientInit->OperationType:"<<pRtnClientInit->OperationType<<std::endl;
  CShfeFtdcRtnClientInitField* pNewRtnClientInit =new CShfeFtdcRtnClientInitField;
  memcpy(pNewRtnClientInit,pRtnClientInit,sizeof(CShfeFtdcRtnClientInitField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnClientInit;
  asyncOnRtnClientInitTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnClientInitTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryTradeLogTopic(CShfeFtdcRspQryTradeLogField *pRspQryTradeLog, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryTradeLog->bFlag:"<<pRspQryTradeLog->bFlag<<std::endl;
  std::cout<<"on pRspQryTradeLog->TradeLogStr:"<<pRspQryTradeLog->TradeLogStr<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryTradeLogField* pNewRspQryTradeLog =new CShfeFtdcRspQryTradeLogField;
  memcpy(pNewRspQryTradeLog,pRspQryTradeLog,sizeof(CShfeFtdcRspQryTradeLogField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTradeLog;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTradeLogTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryTradeLogTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnTradeLogTopic(CShfeFtdcRtnTradeLogField *pRtnTradeLog)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnTradeLog->bFlag:"<<pRtnTradeLog->bFlag<<std::endl;
  std::cout<<"on pRtnTradeLog->TradeLogStr:"<<pRtnTradeLog->TradeLogStr<<std::endl;
  CShfeFtdcRtnTradeLogField* pNewRtnTradeLog =new CShfeFtdcRtnTradeLogField;
  memcpy(pNewRtnTradeLog,pRtnTradeLog,sizeof(CShfeFtdcRtnTradeLogField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnTradeLog;
  asyncOnRtnTradeLogTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnTradeLogTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryTradeUserLoginInfoTopic(CShfeFtdcRspQryTradeUserLoginInfoField *pRspQryTradeUserLoginInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"SysUserSpi::OnRspQryTradeUserLoginInfoTopic: ok"<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginInfo->ObjectID:"<<pRspQryTradeUserLoginInfo->ObjectID<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginInfo->UserID:"<<pRspQryTradeUserLoginInfo->UserID<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginInfo->ParticipantID:"<<pRspQryTradeUserLoginInfo->ParticipantID<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginInfo->ProtocolInfo:"<<pRspQryTradeUserLoginInfo->ProtocolInfo<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginInfo->IPAddress:"<<pRspQryTradeUserLoginInfo->IPAddress<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginInfo->FrontID:"<<pRspQryTradeUserLoginInfo->FrontID<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginInfo->UserType:"<<pRspQryTradeUserLoginInfo->UserType<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginInfo->AccessType:"<<pRspQryTradeUserLoginInfo->AccessType<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginInfo->ActionDate:"<<pRspQryTradeUserLoginInfo->ActionDate<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginInfo->ActionTime:"<<pRspQryTradeUserLoginInfo->ActionTime<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginInfo->ActionFlag:"<<pRspQryTradeUserLoginInfo->ActionFlag<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginInfo->DataCenter:"<<pRspQryTradeUserLoginInfo->DataCenter<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryTradeUserLoginInfoField* pNewRspQryTradeUserLoginInfo =new CShfeFtdcRspQryTradeUserLoginInfoField;
  memcpy(pNewRspQryTradeUserLoginInfo,pRspQryTradeUserLoginInfo,sizeof(CShfeFtdcRspQryTradeUserLoginInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTradeUserLoginInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTradeUserLoginInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryTradeUserLoginInfoTopic);
  std::cout<<"SysUserSpi::OnRspQryTradeUserLoginInfoTopic: end send \n"<<std::endl;
}
void SysUserSpi::OnRtnTradeUserLoginInfoTopic(CShfeFtdcRtnTradeUserLoginInfoField *pRtnTradeUserLoginInfo)
{
  std::cout<<"\n********** Spi::OnRtnTradeUserLoginInfoTopic: START ********"<<std::endl;
  std::cout<<"on pRtnTradeUserLoginInfo->ObjectID:"<<pRtnTradeUserLoginInfo->ObjectID<<std::endl;
  std::cout<<"on pRtnTradeUserLoginInfo->UserID:"<<pRtnTradeUserLoginInfo->UserID<<std::endl;
  std::cout<<"on pRtnTradeUserLoginInfo->ParticipantID:"<<pRtnTradeUserLoginInfo->ParticipantID<<std::endl;
  std::cout<<"on pRtnTradeUserLoginInfo->ProtocolInfo:"<<pRtnTradeUserLoginInfo->ProtocolInfo<<std::endl;
  std::cout<<"on pRtnTradeUserLoginInfo->IPAddress:"<<pRtnTradeUserLoginInfo->IPAddress<<std::endl;
  std::cout<<"on pRtnTradeUserLoginInfo->FrontID:"<<pRtnTradeUserLoginInfo->FrontID<<std::endl;
  std::cout<<"on pRtnTradeUserLoginInfo->UserType:"<<pRtnTradeUserLoginInfo->UserType<<std::endl;
  std::cout<<"on pRtnTradeUserLoginInfo->AccessType:"<<pRtnTradeUserLoginInfo->AccessType<<std::endl;
  std::cout<<"on pRtnTradeUserLoginInfo->ActionDate:"<<pRtnTradeUserLoginInfo->ActionDate<<std::endl;
  std::cout<<"on pRtnTradeUserLoginInfo->ActionTime:"<<pRtnTradeUserLoginInfo->ActionTime<<std::endl;
  std::cout<<"on pRtnTradeUserLoginInfo->ActionFlag:"<<pRtnTradeUserLoginInfo->ActionFlag<<std::endl;
  std::cout<<"on pRtnTradeUserLoginInfo->DataCenter:"<<pRtnTradeUserLoginInfo->DataCenter<<std::endl;
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
  uv_async_send(&asyncOnRtnTradeUserLoginInfoTopic);
  
  uv_mutex_unlock(&g_RtnTradeUserLoginInfoTopic_mutex);  
  
  std::cout<<"********** Spi::OnRtnTradeUserLoginInfoTopic: END! ********\n"<<std::endl;
}
void SysUserSpi::OnRspQryPartTradeTopic(CShfeFtdcRspQryPartTradeField *pRspQryPartTrade, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryPartTrade->ActionDate:"<<pRspQryPartTrade->ActionDate<<std::endl;
  std::cout<<"on pRspQryPartTrade->ActionTime:"<<pRspQryPartTrade->ActionTime<<std::endl;
  std::cout<<"on pRspQryPartTrade->InstrumentID:"<<pRspQryPartTrade->InstrumentID<<std::endl;
  std::cout<<"on pRspQryPartTrade->ParticipantID:"<<pRspQryPartTrade->ParticipantID<<std::endl;
  std::cout<<"on pRspQryPartTrade->TotalPositiveOrder:"<<pRspQryPartTrade->TotalPositiveOrder<<std::endl;
  std::cout<<"on pRspQryPartTrade->TotalNegativeOrder:"<<pRspQryPartTrade->TotalNegativeOrder<<std::endl;
  std::cout<<"on pRspQryPartTrade->TotalPositiveTrade:"<<pRspQryPartTrade->TotalPositiveTrade<<std::endl;
  std::cout<<"on pRspQryPartTrade->TotalNegativeTrade:"<<pRspQryPartTrade->TotalNegativeTrade<<std::endl;
  std::cout<<"on pRspQryPartTrade->TotalPositivePosi:"<<pRspQryPartTrade->TotalPositivePosi<<std::endl;
  std::cout<<"on pRspQryPartTrade->TotalNegativePosi:"<<pRspQryPartTrade->TotalNegativePosi<<std::endl;
  std::cout<<"on pRspQryPartTrade->OperationType:"<<pRspQryPartTrade->OperationType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryPartTradeField* pNewRspQryPartTrade =new CShfeFtdcRspQryPartTradeField;
  memcpy(pNewRspQryPartTrade,pRspQryPartTrade,sizeof(CShfeFtdcRspQryPartTradeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryPartTrade;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryPartTradeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryPartTradeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryTradepeakTopic(CShfeFtdcRspQryTradepeakField *pRspQryTradepeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryTradepeak->TradepeakFlag:"<<pRspQryTradepeak->TradepeakFlag<<std::endl;
  std::cout<<"on pRspQryTradepeak->PeakTime:"<<pRspQryTradepeak->PeakTime<<std::endl;
  std::cout<<"on pRspQryTradepeak->InsertOrder:"<<pRspQryTradepeak->InsertOrder<<std::endl;
  std::cout<<"on pRspQryTradepeak->ActionOrder:"<<pRspQryTradepeak->ActionOrder<<std::endl;
  std::cout<<"on pRspQryTradepeak->InvalidOrder:"<<pRspQryTradepeak->InvalidOrder<<std::endl;
  std::cout<<"on pRspQryTradepeak->TotalBusiness:"<<pRspQryTradepeak->TotalBusiness<<std::endl;
  std::cout<<"on pRspQryTradepeak->TradeCount:"<<pRspQryTradepeak->TradeCount<<std::endl;
  std::cout<<"on pRspQryTradepeak->TotalCount:"<<pRspQryTradepeak->TotalCount<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryTradepeakField* pNewRspQryTradepeak =new CShfeFtdcRspQryTradepeakField;
  memcpy(pNewRspQryTradepeak,pRspQryTradepeak,sizeof(CShfeFtdcRspQryTradepeakField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTradepeak;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTradepeakTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryTradepeakTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnUpdateSysConfigTopic(CShfeFtdcRtnUpdateSysConfigField *pRtnUpdateSysConfig)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnUpdateSysConfig->UpdateType:"<<pRtnUpdateSysConfig->UpdateType<<std::endl;
  std::cout<<"on pRtnUpdateSysConfig->OldValue:"<<pRtnUpdateSysConfig->OldValue<<std::endl;
  std::cout<<"on pRtnUpdateSysConfig->NewValue:"<<pRtnUpdateSysConfig->NewValue<<std::endl;
  std::cout<<"on pRtnUpdateSysConfig->Standby:"<<pRtnUpdateSysConfig->Standby<<std::endl;
  CShfeFtdcRtnUpdateSysConfigField* pNewRtnUpdateSysConfig =new CShfeFtdcRtnUpdateSysConfigField;
  memcpy(pNewRtnUpdateSysConfig,pRtnUpdateSysConfig,sizeof(CShfeFtdcRtnUpdateSysConfigField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnUpdateSysConfig;
  asyncOnRtnUpdateSysConfigTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnUpdateSysConfigTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnSysUser(CShfeFtdcRtnSysUserField *pRtnSysUser)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnSysUser->UserID:"<<pRtnSysUser->UserID<<std::endl;
  std::cout<<"on pRtnSysUser->UserName:"<<pRtnSysUser->UserName<<std::endl;
  std::cout<<"on pRtnSysUser->UserInfo:"<<pRtnSysUser->UserInfo<<std::endl;
  std::cout<<"on pRtnSysUser->Password:"<<pRtnSysUser->Password<<std::endl;
  std::cout<<"on pRtnSysUser->Privilege:"<<pRtnSysUser->Privilege<<std::endl;
  std::cout<<"on pRtnSysUser->EMail:"<<pRtnSysUser->EMail<<std::endl;
  std::cout<<"on pRtnSysUser->EMailFlag:"<<pRtnSysUser->EMailFlag<<std::endl;
  std::cout<<"on pRtnSysUser->HomePhone:"<<pRtnSysUser->HomePhone<<std::endl;
  std::cout<<"on pRtnSysUser->HomePhoneFlag:"<<pRtnSysUser->HomePhoneFlag<<std::endl;
  std::cout<<"on pRtnSysUser->MobilePhone:"<<pRtnSysUser->MobilePhone<<std::endl;
  std::cout<<"on pRtnSysUser->MobilePhoneFlag:"<<pRtnSysUser->MobilePhoneFlag<<std::endl;
  CShfeFtdcRtnSysUserField* pNewRtnSysUser =new CShfeFtdcRtnSysUserField;
  memcpy(pNewRtnSysUser,pRtnSysUser,sizeof(CShfeFtdcRtnSysUserField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSysUser;
  asyncOnRtnSysUser.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnSysUser);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnPriceLimitChgTopic(CShfeFtdcRtnPriceLimitChgField *pRtnPriceLimitChg)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnPriceLimitChg->ActionDate:"<<pRtnPriceLimitChg->ActionDate<<std::endl;
  std::cout<<"on pRtnPriceLimitChg->ActionTime:"<<pRtnPriceLimitChg->ActionTime<<std::endl;
  std::cout<<"on pRtnPriceLimitChg->InstrumentID:"<<pRtnPriceLimitChg->InstrumentID<<std::endl;
  std::cout<<"on pRtnPriceLimitChg->ValueMode:"<<pRtnPriceLimitChg->ValueMode<<std::endl;
  std::cout<<"on pRtnPriceLimitChg->RoundingMode:"<<pRtnPriceLimitChg->RoundingMode<<std::endl;
  std::cout<<"on pRtnPriceLimitChg->UpperLimitPrice:"<<pRtnPriceLimitChg->UpperLimitPrice<<std::endl;
  std::cout<<"on pRtnPriceLimitChg->LowerLimitPrice:"<<pRtnPriceLimitChg->LowerLimitPrice<<std::endl;
  std::cout<<"on pRtnPriceLimitChg->OperationType:"<<pRtnPriceLimitChg->OperationType<<std::endl;
  CShfeFtdcRtnPriceLimitChgField* pNewRtnPriceLimitChg =new CShfeFtdcRtnPriceLimitChgField;
  memcpy(pNewRtnPriceLimitChg,pRtnPriceLimitChg,sizeof(CShfeFtdcRtnPriceLimitChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnPriceLimitChg;
  asyncOnRtnPriceLimitChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnPriceLimitChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryHistoryCpuInfoTopic(CShfeFtdcRspQryHistoryCpuInfoField *pRspQryHistoryCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryHistoryCpuInfo->HostName:"<<pRspQryHistoryCpuInfo->HostName<<std::endl;
  std::cout<<"on pRspQryHistoryCpuInfo->MonDate:"<<pRspQryHistoryCpuInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryHistoryCpuInfo->MonTime:"<<pRspQryHistoryCpuInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryHistoryCpuInfo->CPU:"<<pRspQryHistoryCpuInfo->CPU<<std::endl;
  std::cout<<"on pRspQryHistoryCpuInfo->LOAD:"<<pRspQryHistoryCpuInfo->LOAD<<std::endl;
  std::cout<<"on pRspQryHistoryCpuInfo->USER:"<<pRspQryHistoryCpuInfo->USER<<std::endl;
  std::cout<<"on pRspQryHistoryCpuInfo->NICE:"<<pRspQryHistoryCpuInfo->NICE<<std::endl;
  std::cout<<"on pRspQryHistoryCpuInfo->SYS:"<<pRspQryHistoryCpuInfo->SYS<<std::endl;
  std::cout<<"on pRspQryHistoryCpuInfo->IDLE:"<<pRspQryHistoryCpuInfo->IDLE<<std::endl;
  std::cout<<"on pRspQryHistoryCpuInfo->BLOCK:"<<pRspQryHistoryCpuInfo->BLOCK<<std::endl;
  std::cout<<"on pRspQryHistoryCpuInfo->SWAIT:"<<pRspQryHistoryCpuInfo->SWAIT<<std::endl;
  std::cout<<"on pRspQryHistoryCpuInfo->INTR:"<<pRspQryHistoryCpuInfo->INTR<<std::endl;
  std::cout<<"on pRspQryHistoryCpuInfo->SSYS:"<<pRspQryHistoryCpuInfo->SSYS<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryHistoryCpuInfoField* pNewRspQryHistoryCpuInfo =new CShfeFtdcRspQryHistoryCpuInfoField;
  memcpy(pNewRspQryHistoryCpuInfo,pRspQryHistoryCpuInfo,sizeof(CShfeFtdcRspQryHistoryCpuInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryHistoryCpuInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryHistoryCpuInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryHistoryCpuInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryHistoryMemInfoTopic(CShfeFtdcRspQryHistoryMemInfoField *pRspQryHistoryMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"\n******* SysUserSpi::OnRspQryHistoryMemInfoTopic: START *******"<<std::endl;
  std::cout<<"on pRspQryHistoryMemInfo->HostName:"<<pRspQryHistoryMemInfo->HostName<<std::endl;
  std::cout<<"on pRspQryHistoryMemInfo->MonDate:"<<pRspQryHistoryMemInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryHistoryMemInfo->MonTime:"<<pRspQryHistoryMemInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryHistoryMemInfo->TOTALREAL:"<<pRspQryHistoryMemInfo->TOTALREAL<<std::endl;
  std::cout<<"on pRspQryHistoryMemInfo->ACTIVEREAL:"<<pRspQryHistoryMemInfo->ACTIVEREAL<<std::endl;
  std::cout<<"on pRspQryHistoryMemInfo->TOTALVIRTUAL:"<<pRspQryHistoryMemInfo->TOTALVIRTUAL<<std::endl;
  std::cout<<"on pRspQryHistoryMemInfo->ACTIVEVIRTUAL:"<<pRspQryHistoryMemInfo->ACTIVEVIRTUAL<<std::endl;
  std::cout<<"on pRspQryHistoryMemInfo->FREE:"<<pRspQryHistoryMemInfo->FREE<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryHistoryMemInfoField* pNewRspQryHistoryMemInfo =new CShfeFtdcRspQryHistoryMemInfoField;
  memcpy(pNewRspQryHistoryMemInfo,pRspQryHistoryMemInfo,sizeof(CShfeFtdcRspQryHistoryMemInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryHistoryMemInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryHistoryMemInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryHistoryMemInfoTopic);
  std::cout<<"******* SysUserSpi::OnRspQryHistoryMemInfoTopic: END *******\n"<<std::endl;
}
void SysUserSpi::OnRspQryHistoryNetworkInfoTopic(CShfeFtdcRspQryHistoryNetworkInfoField *pRspQryHistoryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryHistoryNetworkInfo->HostName:"<<pRspQryHistoryNetworkInfo->HostName<<std::endl;
  std::cout<<"on pRspQryHistoryNetworkInfo->MonDate:"<<pRspQryHistoryNetworkInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryHistoryNetworkInfo->MonTime:"<<pRspQryHistoryNetworkInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryHistoryNetworkInfo->LANNAME:"<<pRspQryHistoryNetworkInfo->LANNAME<<std::endl;
  std::cout<<"on pRspQryHistoryNetworkInfo->LANSTATUS:"<<pRspQryHistoryNetworkInfo->LANSTATUS<<std::endl;
  std::cout<<"on pRspQryHistoryNetworkInfo->IPADDRESS:"<<pRspQryHistoryNetworkInfo->IPADDRESS<<std::endl;
  std::cout<<"on pRspQryHistoryNetworkInfo->RECVBYTES:"<<pRspQryHistoryNetworkInfo->RECVBYTES<<std::endl;
  std::cout<<"on pRspQryHistoryNetworkInfo->RECVPACKETS:"<<pRspQryHistoryNetworkInfo->RECVPACKETS<<std::endl;
  std::cout<<"on pRspQryHistoryNetworkInfo->RECVERRORPACKETS:"<<pRspQryHistoryNetworkInfo->RECVERRORPACKETS<<std::endl;
  std::cout<<"on pRspQryHistoryNetworkInfo->RECVDROPPACKETS:"<<pRspQryHistoryNetworkInfo->RECVDROPPACKETS<<std::endl;
  std::cout<<"on pRspQryHistoryNetworkInfo->SENDBYTES:"<<pRspQryHistoryNetworkInfo->SENDBYTES<<std::endl;
  std::cout<<"on pRspQryHistoryNetworkInfo->SENDPACKETS:"<<pRspQryHistoryNetworkInfo->SENDPACKETS<<std::endl;
  std::cout<<"on pRspQryHistoryNetworkInfo->SENDERRORPACKETS:"<<pRspQryHistoryNetworkInfo->SENDERRORPACKETS<<std::endl;
  std::cout<<"on pRspQryHistoryNetworkInfo->SENDDROPPACKETS:"<<pRspQryHistoryNetworkInfo->SENDDROPPACKETS<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryHistoryNetworkInfoField* pNewRspQryHistoryNetworkInfo =new CShfeFtdcRspQryHistoryNetworkInfoField;
  memcpy(pNewRspQryHistoryNetworkInfo,pRspQryHistoryNetworkInfo,sizeof(CShfeFtdcRspQryHistoryNetworkInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryHistoryNetworkInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryHistoryNetworkInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryHistoryNetworkInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryMonitorOnlineUser(CShfeFtdcRspQryMonitorOnlineUserField *pRspQryMonitorOnlineUser, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryMonitorOnlineUser->UserID:"<<pRspQryMonitorOnlineUser->UserID<<std::endl;
  std::cout<<"on pRspQryMonitorOnlineUser->IPAddress:"<<pRspQryMonitorOnlineUser->IPAddress<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryMonitorOnlineUserField* pNewRspQryMonitorOnlineUser =new CShfeFtdcRspQryMonitorOnlineUserField;
  memcpy(pNewRspQryMonitorOnlineUser,pRspQryMonitorOnlineUser,sizeof(CShfeFtdcRspQryMonitorOnlineUserField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryMonitorOnlineUser;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryMonitorOnlineUser.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryMonitorOnlineUser);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryFrontStat(CShfeFtdcRspQryFrontStatField *pRspQryFrontStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryFrontStat->FrontID:"<<pRspQryFrontStat->FrontID<<std::endl;
  std::cout<<"on pRspQryFrontStat->PositiveOrder:"<<pRspQryFrontStat->PositiveOrder<<std::endl;
  std::cout<<"on pRspQryFrontStat->NegativeOrder:"<<pRspQryFrontStat->NegativeOrder<<std::endl;
  std::cout<<"on pRspQryFrontStat->TotalPositiveOrder:"<<pRspQryFrontStat->TotalPositiveOrder<<std::endl;
  std::cout<<"on pRspQryFrontStat->TotalNegativeOrder:"<<pRspQryFrontStat->TotalNegativeOrder<<std::endl;
  std::cout<<"on pRspQryFrontStat->OrderAction:"<<pRspQryFrontStat->OrderAction<<std::endl;
  std::cout<<"on pRspQryFrontStat->TotalOrderAction:"<<pRspQryFrontStat->TotalOrderAction<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryFrontStatField* pNewRspQryFrontStat =new CShfeFtdcRspQryFrontStatField;
  memcpy(pNewRspQryFrontStat,pRspQryFrontStat,sizeof(CShfeFtdcRspQryFrontStatField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryFrontStat;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryFrontStat.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryFrontStat);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnSysTimeSyncTopic(CShfeFtdcRtnSysTimeSyncField *pRtnSysTimeSync)
{
  std::cout<<"\n****************SysUserSpi::OnRtnSysTimeSyncTopic: START ****************"<<std::endl;
  try {
      std::cout<<"on pRtnSysTimeSync->MonDate:"<<pRtnSysTimeSync->MonDate<<std::endl;
  std::cout<<"on pRtnSysTimeSync->MonTime:"<<pRtnSysTimeSync->MonTime<<std::endl;
  CShfeFtdcRtnSysTimeSyncField* pNewRtnSysTimeSync =new CShfeFtdcRtnSysTimeSyncField;
  memcpy(pNewRtnSysTimeSync,pRtnSysTimeSync,sizeof(CShfeFtdcRtnSysTimeSyncField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSysTimeSync;
  asyncOnRtnSysTimeSyncTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnSysTimeSyncTopic);
  std::cout<<"**************** SysUserSpi::OnRtnSysTimeSyncTopic: END ****************\n"<<std::endl;
  } catch (exception& error) {
    
    cout << "exception: " << error.what() << endl;
  }

}
void SysUserSpi::OnRtnDataCenterChgTopic(CShfeFtdcRtnDataCenterChgField *pRtnDataCenterChg)
{
  std::cout<<"\n**************** SysUserSpi::OnRtnDataCenterChgTopic: START ****************"<<std::endl;
  std::cout<<"on pRtnDataCenterChg->DataCenterID:"<<pRtnDataCenterChg->DataCenterID<<std::endl;
  CShfeFtdcRtnDataCenterChgField* pNewRtnDataCenterChg =new CShfeFtdcRtnDataCenterChgField;
  memcpy(pNewRtnDataCenterChg,pRtnDataCenterChg,sizeof(CShfeFtdcRtnDataCenterChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnDataCenterChg;
  asyncOnRtnDataCenterChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnDataCenterChgTopic);
  std::cout<<"**************** SysUserSpi::OnRtnDataCenterChgTopic: END ****************\n"<<std::endl;
}
void SysUserSpi::OnRspQryHistoryTradePeakTopic(CShfeFtdcRspQryHistoryTradePeakField *pRspQryHistoryTradePeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryHistoryTradePeak->ObjectID:"<<pRspQryHistoryTradePeak->ObjectID<<std::endl;
  std::cout<<"on pRspQryHistoryTradePeak->MonDate:"<<pRspQryHistoryTradePeak->MonDate<<std::endl;
  std::cout<<"on pRspQryHistoryTradePeak->MonTime:"<<pRspQryHistoryTradePeak->MonTime<<std::endl;
  std::cout<<"on pRspQryHistoryTradePeak->AttrType:"<<pRspQryHistoryTradePeak->AttrType<<std::endl;
  std::cout<<"on pRspQryHistoryTradePeak->AttrValue:"<<pRspQryHistoryTradePeak->AttrValue<<std::endl;
  std::cout<<"on pRspQryHistoryTradePeak->RltAttrType:"<<pRspQryHistoryTradePeak->RltAttrType<<std::endl;
  std::cout<<"on pRspQryHistoryTradePeak->RltAttrValue:"<<pRspQryHistoryTradePeak->RltAttrValue<<std::endl;
  std::cout<<"on pRspQryHistoryTradePeak->MaxMonDate:"<<pRspQryHistoryTradePeak->MaxMonDate<<std::endl;
  std::cout<<"on pRspQryHistoryTradePeak->MaxMonTime:"<<pRspQryHistoryTradePeak->MaxMonTime<<std::endl;
  std::cout<<"on pRspQryHistoryTradePeak->MaxAttrValue:"<<pRspQryHistoryTradePeak->MaxAttrValue<<std::endl;
  std::cout<<"on pRspQryHistoryTradePeak->MaxRltAttrValue:"<<pRspQryHistoryTradePeak->MaxRltAttrValue<<std::endl;
  std::cout<<"on pRspQryHistoryTradePeak->OldMonDate:"<<pRspQryHistoryTradePeak->OldMonDate<<std::endl;
  std::cout<<"on pRspQryHistoryTradePeak->OldMonTime:"<<pRspQryHistoryTradePeak->OldMonTime<<std::endl;
  std::cout<<"on pRspQryHistoryTradePeak->OldAttrValue:"<<pRspQryHistoryTradePeak->OldAttrValue<<std::endl;
  std::cout<<"on pRspQryHistoryTradePeak->OldRltAttrValue:"<<pRspQryHistoryTradePeak->OldRltAttrValue<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryHistoryTradePeakField* pNewRspQryHistoryTradePeak =new CShfeFtdcRspQryHistoryTradePeakField;
  memcpy(pNewRspQryHistoryTradePeak,pRspQryHistoryTradePeak,sizeof(CShfeFtdcRspQryHistoryTradePeakField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryHistoryTradePeak;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryHistoryTradePeakTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryHistoryTradePeakTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnHistoryTradePeakTopic(CShfeFtdcRtnHistoryTradePeakField *pRtnHistoryTradePeak)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnHistoryTradePeak->ObjectID:"<<pRtnHistoryTradePeak->ObjectID<<std::endl;
  std::cout<<"on pRtnHistoryTradePeak->MonDate:"<<pRtnHistoryTradePeak->MonDate<<std::endl;
  std::cout<<"on pRtnHistoryTradePeak->MonTime:"<<pRtnHistoryTradePeak->MonTime<<std::endl;
  std::cout<<"on pRtnHistoryTradePeak->AttrType:"<<pRtnHistoryTradePeak->AttrType<<std::endl;
  std::cout<<"on pRtnHistoryTradePeak->AttrValue:"<<pRtnHistoryTradePeak->AttrValue<<std::endl;
  std::cout<<"on pRtnHistoryTradePeak->RltAttrType:"<<pRtnHistoryTradePeak->RltAttrType<<std::endl;
  std::cout<<"on pRtnHistoryTradePeak->RltAttrValue:"<<pRtnHistoryTradePeak->RltAttrValue<<std::endl;
  std::cout<<"on pRtnHistoryTradePeak->MaxMonDate:"<<pRtnHistoryTradePeak->MaxMonDate<<std::endl;
  std::cout<<"on pRtnHistoryTradePeak->MaxMonTime:"<<pRtnHistoryTradePeak->MaxMonTime<<std::endl;
  std::cout<<"on pRtnHistoryTradePeak->MaxAttrValue:"<<pRtnHistoryTradePeak->MaxAttrValue<<std::endl;
  std::cout<<"on pRtnHistoryTradePeak->MaxRltAttrValue:"<<pRtnHistoryTradePeak->MaxRltAttrValue<<std::endl;
  std::cout<<"on pRtnHistoryTradePeak->OldMonDate:"<<pRtnHistoryTradePeak->OldMonDate<<std::endl;
  std::cout<<"on pRtnHistoryTradePeak->OldMonTime:"<<pRtnHistoryTradePeak->OldMonTime<<std::endl;
  std::cout<<"on pRtnHistoryTradePeak->OldAttrValue:"<<pRtnHistoryTradePeak->OldAttrValue<<std::endl;
  std::cout<<"on pRtnHistoryTradePeak->OldRltAttrValue:"<<pRtnHistoryTradePeak->OldRltAttrValue<<std::endl;
  CShfeFtdcRtnHistoryTradePeakField* pNewRtnHistoryTradePeak =new CShfeFtdcRtnHistoryTradePeakField;
  memcpy(pNewRtnHistoryTradePeak,pRtnHistoryTradePeak,sizeof(CShfeFtdcRtnHistoryTradePeakField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnHistoryTradePeak;
  asyncOnRtnHistoryTradePeakTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnHistoryTradePeakTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQrySyslogEventTopic(CShfeFtdcRspQrySyslogEventField *pRspQrySyslogEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQrySyslogEvent->MonDate:"<<pRspQrySyslogEvent->MonDate<<std::endl;
  std::cout<<"on pRspQrySyslogEvent->MonTime:"<<pRspQrySyslogEvent->MonTime<<std::endl;
  std::cout<<"on pRspQrySyslogEvent->OccurDate:"<<pRspQrySyslogEvent->OccurDate<<std::endl;
  std::cout<<"on pRspQrySyslogEvent->OccurTime:"<<pRspQrySyslogEvent->OccurTime<<std::endl;
  std::cout<<"on pRspQrySyslogEvent->EvendID:"<<pRspQrySyslogEvent->EvendID<<std::endl;
  std::cout<<"on pRspQrySyslogEvent->ObjectID:"<<pRspQrySyslogEvent->ObjectID<<std::endl;
  std::cout<<"on pRspQrySyslogEvent->IPAddress:"<<pRspQrySyslogEvent->IPAddress<<std::endl;
  std::cout<<"on pRspQrySyslogEvent->EventName:"<<pRspQrySyslogEvent->EventName<<std::endl;
  std::cout<<"on pRspQrySyslogEvent->EventNum:"<<pRspQrySyslogEvent->EventNum<<std::endl;
  std::cout<<"on pRspQrySyslogEvent->EventType:"<<pRspQrySyslogEvent->EventType<<std::endl;
  std::cout<<"on pRspQrySyslogEvent->EventDes:"<<pRspQrySyslogEvent->EventDes<<std::endl;
  std::cout<<"on pRspQrySyslogEvent->ProcessFlag:"<<pRspQrySyslogEvent->ProcessFlag<<std::endl;
  std::cout<<"on pRspQrySyslogEvent->WarningLevel:"<<pRspQrySyslogEvent->WarningLevel<<std::endl;
  std::cout<<"on pRspQrySyslogEvent->EventDealDes:"<<pRspQrySyslogEvent->EventDealDes<<std::endl;
  std::cout<<"on pRspQrySyslogEvent->FullEventName:"<<pRspQrySyslogEvent->FullEventName<<std::endl;
  std::cout<<"on pRspQrySyslogEvent->EventCount:"<<pRspQrySyslogEvent->EventCount<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQrySyslogEventField* pNewRspQrySyslogEvent =new CShfeFtdcRspQrySyslogEventField;
  memcpy(pNewRspQrySyslogEvent,pRspQrySyslogEvent,sizeof(CShfeFtdcRspQrySyslogEventField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySyslogEvent;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySyslogEventTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQrySyslogEventTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnSyslogEventTopic(CShfeFtdcRtnSyslogEventField *pRtnSyslogEvent)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnSyslogEvent->MonDate:"<<pRtnSyslogEvent->MonDate<<std::endl;
  std::cout<<"on pRtnSyslogEvent->MonTime:"<<pRtnSyslogEvent->MonTime<<std::endl;
  std::cout<<"on pRtnSyslogEvent->OccurDate:"<<pRtnSyslogEvent->OccurDate<<std::endl;
  std::cout<<"on pRtnSyslogEvent->OccurTime:"<<pRtnSyslogEvent->OccurTime<<std::endl;
  std::cout<<"on pRtnSyslogEvent->EvendID:"<<pRtnSyslogEvent->EvendID<<std::endl;
  std::cout<<"on pRtnSyslogEvent->ObjectID:"<<pRtnSyslogEvent->ObjectID<<std::endl;
  std::cout<<"on pRtnSyslogEvent->IPAddress:"<<pRtnSyslogEvent->IPAddress<<std::endl;
  std::cout<<"on pRtnSyslogEvent->EventName:"<<pRtnSyslogEvent->EventName<<std::endl;
  std::cout<<"on pRtnSyslogEvent->EventNum:"<<pRtnSyslogEvent->EventNum<<std::endl;
  std::cout<<"on pRtnSyslogEvent->EventType:"<<pRtnSyslogEvent->EventType<<std::endl;
  std::cout<<"on pRtnSyslogEvent->EventDes:"<<pRtnSyslogEvent->EventDes<<std::endl;
  std::cout<<"on pRtnSyslogEvent->ProcessFlag:"<<pRtnSyslogEvent->ProcessFlag<<std::endl;
  std::cout<<"on pRtnSyslogEvent->WarningLevel:"<<pRtnSyslogEvent->WarningLevel<<std::endl;
  std::cout<<"on pRtnSyslogEvent->EventDealDes:"<<pRtnSyslogEvent->EventDealDes<<std::endl;
  std::cout<<"on pRtnSyslogEvent->FullEventName:"<<pRtnSyslogEvent->FullEventName<<std::endl;
  CShfeFtdcRtnSyslogEventField* pNewRtnSyslogEvent =new CShfeFtdcRtnSyslogEventField;
  memcpy(pNewRtnSyslogEvent,pRtnSyslogEvent,sizeof(CShfeFtdcRtnSyslogEventField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSyslogEvent;
  asyncOnRtnSyslogEventTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnSyslogEventTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryTradeDayChangeTopic(CShfeFtdcRspQryTradeDayChangeField *pRspQryTradeDayChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryTradeDayChange->ChangeType:"<<pRspQryTradeDayChange->ChangeType<<std::endl;
  std::cout<<"on pRspQryTradeDayChange->OldDate:"<<pRspQryTradeDayChange->OldDate<<std::endl;
  std::cout<<"on pRspQryTradeDayChange->NewDate:"<<pRspQryTradeDayChange->NewDate<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryTradeDayChangeField* pNewRspQryTradeDayChange =new CShfeFtdcRspQryTradeDayChangeField;
  memcpy(pNewRspQryTradeDayChange,pRspQryTradeDayChange,sizeof(CShfeFtdcRspQryTradeDayChangeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTradeDayChange;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTradeDayChangeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryTradeDayChangeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryWebAppInfoTopic(CShfeFtdcRspQryWebAppInfoField *pRspQryWebAppInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryWebAppInfo->ObjectID:"<<pRspQryWebAppInfo->ObjectID<<std::endl;
  std::cout<<"on pRspQryWebAppInfo->MonDate:"<<pRspQryWebAppInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryWebAppInfo->MonTime:"<<pRspQryWebAppInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryWebAppInfo->AppName:"<<pRspQryWebAppInfo->AppName<<std::endl;
  std::cout<<"on pRspQryWebAppInfo->Status:"<<pRspQryWebAppInfo->Status<<std::endl;
  std::cout<<"on pRspQryWebAppInfo->Desc:"<<pRspQryWebAppInfo->Desc<<std::endl;
  std::cout<<"on pRspQryWebAppInfo->StartTime:"<<pRspQryWebAppInfo->StartTime<<std::endl;
  std::cout<<"on pRspQryWebAppInfo->ServletNum:"<<pRspQryWebAppInfo->ServletNum<<std::endl;
  std::cout<<"on pRspQryWebAppInfo->ProcessTime:"<<pRspQryWebAppInfo->ProcessTime<<std::endl;
  std::cout<<"on pRspQryWebAppInfo->RequestNum:"<<pRspQryWebAppInfo->RequestNum<<std::endl;
  std::cout<<"on pRspQryWebAppInfo->ErrorNum:"<<pRspQryWebAppInfo->ErrorNum<<std::endl;
  std::cout<<"on pRspQryWebAppInfo->SessionSize:"<<pRspQryWebAppInfo->SessionSize<<std::endl;
  std::cout<<"on pRspQryWebAppInfo->TimeOut:"<<pRspQryWebAppInfo->TimeOut<<std::endl;
  std::cout<<"on pRspQryWebAppInfo->JDBCUsage:"<<pRspQryWebAppInfo->JDBCUsage<<std::endl;
  std::cout<<"on pRspQryWebAppInfo->JSPNum:"<<pRspQryWebAppInfo->JSPNum<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryWebAppInfoField* pNewRspQryWebAppInfo =new CShfeFtdcRspQryWebAppInfoField;
  memcpy(pNewRspQryWebAppInfo,pRspQryWebAppInfo,sizeof(CShfeFtdcRspQryWebAppInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryWebAppInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryWebAppInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryWebAppInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnWebAppInfoTopic(CShfeFtdcRtnWebAppInfoField *pRtnWebAppInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnWebAppInfo->ObjectID:"<<pRtnWebAppInfo->ObjectID<<std::endl;
  std::cout<<"on pRtnWebAppInfo->MonDate:"<<pRtnWebAppInfo->MonDate<<std::endl;
  std::cout<<"on pRtnWebAppInfo->MonTime:"<<pRtnWebAppInfo->MonTime<<std::endl;
  std::cout<<"on pRtnWebAppInfo->AppName:"<<pRtnWebAppInfo->AppName<<std::endl;
  std::cout<<"on pRtnWebAppInfo->Status:"<<pRtnWebAppInfo->Status<<std::endl;
  std::cout<<"on pRtnWebAppInfo->Desc:"<<pRtnWebAppInfo->Desc<<std::endl;
  std::cout<<"on pRtnWebAppInfo->StartTime:"<<pRtnWebAppInfo->StartTime<<std::endl;
  std::cout<<"on pRtnWebAppInfo->ServletNum:"<<pRtnWebAppInfo->ServletNum<<std::endl;
  std::cout<<"on pRtnWebAppInfo->ProcessTime:"<<pRtnWebAppInfo->ProcessTime<<std::endl;
  std::cout<<"on pRtnWebAppInfo->RequestNum:"<<pRtnWebAppInfo->RequestNum<<std::endl;
  std::cout<<"on pRtnWebAppInfo->ErrorNum:"<<pRtnWebAppInfo->ErrorNum<<std::endl;
  std::cout<<"on pRtnWebAppInfo->SessionSize:"<<pRtnWebAppInfo->SessionSize<<std::endl;
  std::cout<<"on pRtnWebAppInfo->TimeOut:"<<pRtnWebAppInfo->TimeOut<<std::endl;
  std::cout<<"on pRtnWebAppInfo->JDBCUsage:"<<pRtnWebAppInfo->JDBCUsage<<std::endl;
  std::cout<<"on pRtnWebAppInfo->JSPNum:"<<pRtnWebAppInfo->JSPNum<<std::endl;
  CShfeFtdcRtnWebAppInfoField* pNewRtnWebAppInfo =new CShfeFtdcRtnWebAppInfoField;
  memcpy(pNewRtnWebAppInfo,pRtnWebAppInfo,sizeof(CShfeFtdcRtnWebAppInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnWebAppInfo;
  asyncOnRtnWebAppInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnWebAppInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryServletInfoTopic(CShfeFtdcRspQryServletInfoField *pRspQryServletInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryServletInfo->ObjectID:"<<pRspQryServletInfo->ObjectID<<std::endl;
  std::cout<<"on pRspQryServletInfo->MonDate:"<<pRspQryServletInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryServletInfo->MonTime:"<<pRspQryServletInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryServletInfo->Name:"<<pRspQryServletInfo->Name<<std::endl;
  std::cout<<"on pRspQryServletInfo->LoadTime:"<<pRspQryServletInfo->LoadTime<<std::endl;
  std::cout<<"on pRspQryServletInfo->RequestNum:"<<pRspQryServletInfo->RequestNum<<std::endl;
  std::cout<<"on pRspQryServletInfo->RequestErrNum:"<<pRspQryServletInfo->RequestErrNum<<std::endl;
  std::cout<<"on pRspQryServletInfo->ProcessTime:"<<pRspQryServletInfo->ProcessTime<<std::endl;
  std::cout<<"on pRspQryServletInfo->MixTime:"<<pRspQryServletInfo->MixTime<<std::endl;
  std::cout<<"on pRspQryServletInfo->MaxTime:"<<pRspQryServletInfo->MaxTime<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryServletInfoField* pNewRspQryServletInfo =new CShfeFtdcRspQryServletInfoField;
  memcpy(pNewRspQryServletInfo,pRspQryServletInfo,sizeof(CShfeFtdcRspQryServletInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryServletInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryServletInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryServletInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnServletInfoTopic(CShfeFtdcRtnServletInfoField *pRtnServletInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnServletInfo->ObjectID:"<<pRtnServletInfo->ObjectID<<std::endl;
  std::cout<<"on pRtnServletInfo->MonDate:"<<pRtnServletInfo->MonDate<<std::endl;
  std::cout<<"on pRtnServletInfo->MonTime:"<<pRtnServletInfo->MonTime<<std::endl;
  std::cout<<"on pRtnServletInfo->Name:"<<pRtnServletInfo->Name<<std::endl;
  std::cout<<"on pRtnServletInfo->LoadTime:"<<pRtnServletInfo->LoadTime<<std::endl;
  std::cout<<"on pRtnServletInfo->RequestNum:"<<pRtnServletInfo->RequestNum<<std::endl;
  std::cout<<"on pRtnServletInfo->RequestErrNum:"<<pRtnServletInfo->RequestErrNum<<std::endl;
  std::cout<<"on pRtnServletInfo->ProcessTime:"<<pRtnServletInfo->ProcessTime<<std::endl;
  std::cout<<"on pRtnServletInfo->MixTime:"<<pRtnServletInfo->MixTime<<std::endl;
  std::cout<<"on pRtnServletInfo->MaxTime:"<<pRtnServletInfo->MaxTime<<std::endl;
  CShfeFtdcRtnServletInfoField* pNewRtnServletInfo =new CShfeFtdcRtnServletInfoField;
  memcpy(pNewRtnServletInfo,pRtnServletInfo,sizeof(CShfeFtdcRtnServletInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnServletInfo;
  asyncOnRtnServletInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnServletInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryFileInfoTopic(CShfeFtdcRspQryFileInfoField *pRspQryFileInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryFileInfo->ObjectID:"<<pRspQryFileInfo->ObjectID<<std::endl;
  std::cout<<"on pRspQryFileInfo->MonDate:"<<pRspQryFileInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryFileInfo->MonTime:"<<pRspQryFileInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryFileInfo->PathName:"<<pRspQryFileInfo->PathName<<std::endl;
  std::cout<<"on pRspQryFileInfo->FileSize:"<<pRspQryFileInfo->FileSize<<std::endl;
  std::cout<<"on pRspQryFileInfo->LastModDate:"<<pRspQryFileInfo->LastModDate<<std::endl;
  std::cout<<"on pRspQryFileInfo->FileType:"<<pRspQryFileInfo->FileType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryFileInfoField* pNewRspQryFileInfo =new CShfeFtdcRspQryFileInfoField;
  memcpy(pNewRspQryFileInfo,pRspQryFileInfo,sizeof(CShfeFtdcRspQryFileInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryFileInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryFileInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryFileInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnFileInfoTopic(CShfeFtdcRtnFileInfoField *pRtnFileInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnFileInfo->ObjectID:"<<pRtnFileInfo->ObjectID<<std::endl;
  std::cout<<"on pRtnFileInfo->MonDate:"<<pRtnFileInfo->MonDate<<std::endl;
  std::cout<<"on pRtnFileInfo->MonTime:"<<pRtnFileInfo->MonTime<<std::endl;
  std::cout<<"on pRtnFileInfo->PathName:"<<pRtnFileInfo->PathName<<std::endl;
  std::cout<<"on pRtnFileInfo->FileSize:"<<pRtnFileInfo->FileSize<<std::endl;
  std::cout<<"on pRtnFileInfo->LastModDate:"<<pRtnFileInfo->LastModDate<<std::endl;
  std::cout<<"on pRtnFileInfo->FileType:"<<pRtnFileInfo->FileType<<std::endl;
  CShfeFtdcRtnFileInfoField* pNewRtnFileInfo =new CShfeFtdcRtnFileInfoField;
  memcpy(pNewRtnFileInfo,pRtnFileInfo,sizeof(CShfeFtdcRtnFileInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnFileInfo;
  asyncOnRtnFileInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnFileInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQrySessionInfoTopic(CShfeFtdcRspQrySessionInfoField *pRspQrySessionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQrySessionInfo->ObjectID:"<<pRspQrySessionInfo->ObjectID<<std::endl;
  std::cout<<"on pRspQrySessionInfo->MonDate:"<<pRspQrySessionInfo->MonDate<<std::endl;
  std::cout<<"on pRspQrySessionInfo->MonTime:"<<pRspQrySessionInfo->MonTime<<std::endl;
  std::cout<<"on pRspQrySessionInfo->SessionID:"<<pRspQrySessionInfo->SessionID<<std::endl;
  std::cout<<"on pRspQrySessionInfo->SessionName:"<<pRspQrySessionInfo->SessionName<<std::endl;
  std::cout<<"on pRspQrySessionInfo->RemoteIP:"<<pRspQrySessionInfo->RemoteIP<<std::endl;
  std::cout<<"on pRspQrySessionInfo->BeginTime:"<<pRspQrySessionInfo->BeginTime<<std::endl;
  std::cout<<"on pRspQrySessionInfo->LatestTime:"<<pRspQrySessionInfo->LatestTime<<std::endl;
  std::cout<<"on pRspQrySessionInfo->MaxIdleTime:"<<pRspQrySessionInfo->MaxIdleTime<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQrySessionInfoField* pNewRspQrySessionInfo =new CShfeFtdcRspQrySessionInfoField;
  memcpy(pNewRspQrySessionInfo,pRspQrySessionInfo,sizeof(CShfeFtdcRspQrySessionInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySessionInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySessionInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQrySessionInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnSessionInfoTopic(CShfeFtdcRtnSessionInfoField *pRtnSessionInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnSessionInfo->ObjectID:"<<pRtnSessionInfo->ObjectID<<std::endl;
  std::cout<<"on pRtnSessionInfo->MonDate:"<<pRtnSessionInfo->MonDate<<std::endl;
  std::cout<<"on pRtnSessionInfo->MonTime:"<<pRtnSessionInfo->MonTime<<std::endl;
  std::cout<<"on pRtnSessionInfo->SessionID:"<<pRtnSessionInfo->SessionID<<std::endl;
  std::cout<<"on pRtnSessionInfo->SessionName:"<<pRtnSessionInfo->SessionName<<std::endl;
  std::cout<<"on pRtnSessionInfo->RemoteIP:"<<pRtnSessionInfo->RemoteIP<<std::endl;
  std::cout<<"on pRtnSessionInfo->BeginTime:"<<pRtnSessionInfo->BeginTime<<std::endl;
  std::cout<<"on pRtnSessionInfo->LatestTime:"<<pRtnSessionInfo->LatestTime<<std::endl;
  std::cout<<"on pRtnSessionInfo->MaxIdleTime:"<<pRtnSessionInfo->MaxIdleTime<<std::endl;
  CShfeFtdcRtnSessionInfoField* pNewRtnSessionInfo =new CShfeFtdcRtnSessionInfoField;
  memcpy(pNewRtnSessionInfo,pRtnSessionInfo,sizeof(CShfeFtdcRtnSessionInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSessionInfo;
  asyncOnRtnSessionInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnSessionInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryJDBCInfoTopic(CShfeFtdcRspQryJDBCInfoField *pRspQryJDBCInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryJDBCInfo->ObjectID:"<<pRspQryJDBCInfo->ObjectID<<std::endl;
  std::cout<<"on pRspQryJDBCInfo->MonDate:"<<pRspQryJDBCInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryJDBCInfo->MonTime:"<<pRspQryJDBCInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryJDBCInfo->AppName:"<<pRspQryJDBCInfo->AppName<<std::endl;
  std::cout<<"on pRspQryJDBCInfo->Name:"<<pRspQryJDBCInfo->Name<<std::endl;
  std::cout<<"on pRspQryJDBCInfo->Usage:"<<pRspQryJDBCInfo->Usage<<std::endl;
  std::cout<<"on pRspQryJDBCInfo->ConnNumMax:"<<pRspQryJDBCInfo->ConnNumMax<<std::endl;
  std::cout<<"on pRspQryJDBCInfo->ConnNumFree:"<<pRspQryJDBCInfo->ConnNumFree<<std::endl;
  std::cout<<"on pRspQryJDBCInfo->ConnNumUnRU:"<<pRspQryJDBCInfo->ConnNumUnRU<<std::endl;
  std::cout<<"on pRspQryJDBCInfo->ConnNumRU:"<<pRspQryJDBCInfo->ConnNumRU<<std::endl;
  std::cout<<"on pRspQryJDBCInfo->UserName:"<<pRspQryJDBCInfo->UserName<<std::endl;
  std::cout<<"on pRspQryJDBCInfo->Type:"<<pRspQryJDBCInfo->Type<<std::endl;
  std::cout<<"on pRspQryJDBCInfo->URL:"<<pRspQryJDBCInfo->URL<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryJDBCInfoField* pNewRspQryJDBCInfo =new CShfeFtdcRspQryJDBCInfoField;
  memcpy(pNewRspQryJDBCInfo,pRspQryJDBCInfo,sizeof(CShfeFtdcRspQryJDBCInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryJDBCInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryJDBCInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryJDBCInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnJDBCInfoTopic(CShfeFtdcRtnJDBCInfoField *pRtnJDBCInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnJDBCInfo->ObjectID:"<<pRtnJDBCInfo->ObjectID<<std::endl;
  std::cout<<"on pRtnJDBCInfo->MonDate:"<<pRtnJDBCInfo->MonDate<<std::endl;
  std::cout<<"on pRtnJDBCInfo->MonTime:"<<pRtnJDBCInfo->MonTime<<std::endl;
  std::cout<<"on pRtnJDBCInfo->AppName:"<<pRtnJDBCInfo->AppName<<std::endl;
  std::cout<<"on pRtnJDBCInfo->Name:"<<pRtnJDBCInfo->Name<<std::endl;
  std::cout<<"on pRtnJDBCInfo->Usage:"<<pRtnJDBCInfo->Usage<<std::endl;
  std::cout<<"on pRtnJDBCInfo->ConnNumMax:"<<pRtnJDBCInfo->ConnNumMax<<std::endl;
  std::cout<<"on pRtnJDBCInfo->ConnNumFree:"<<pRtnJDBCInfo->ConnNumFree<<std::endl;
  std::cout<<"on pRtnJDBCInfo->ConnNumUnRU:"<<pRtnJDBCInfo->ConnNumUnRU<<std::endl;
  std::cout<<"on pRtnJDBCInfo->ConnNumRU:"<<pRtnJDBCInfo->ConnNumRU<<std::endl;
  std::cout<<"on pRtnJDBCInfo->UserName:"<<pRtnJDBCInfo->UserName<<std::endl;
  std::cout<<"on pRtnJDBCInfo->Type:"<<pRtnJDBCInfo->Type<<std::endl;
  std::cout<<"on pRtnJDBCInfo->URL:"<<pRtnJDBCInfo->URL<<std::endl;
  CShfeFtdcRtnJDBCInfoField* pNewRtnJDBCInfo =new CShfeFtdcRtnJDBCInfoField;
  memcpy(pNewRtnJDBCInfo,pRtnJDBCInfo,sizeof(CShfeFtdcRtnJDBCInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnJDBCInfo;
  asyncOnRtnJDBCInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnJDBCInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryThreadInfoTopic(CShfeFtdcRspQryThreadInfoField *pRspQryThreadInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryThreadInfo->ObjectID:"<<pRspQryThreadInfo->ObjectID<<std::endl;
  std::cout<<"on pRspQryThreadInfo->MonDate:"<<pRspQryThreadInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryThreadInfo->MonTime:"<<pRspQryThreadInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryThreadInfo->Name:"<<pRspQryThreadInfo->Name<<std::endl;
  std::cout<<"on pRspQryThreadInfo->ThreadNum:"<<pRspQryThreadInfo->ThreadNum<<std::endl;
  std::cout<<"on pRspQryThreadInfo->ThreadStatus:"<<pRspQryThreadInfo->ThreadStatus<<std::endl;
  std::cout<<"on pRspQryThreadInfo->InNative:"<<pRspQryThreadInfo->InNative<<std::endl;
  std::cout<<"on pRspQryThreadInfo->Suspended:"<<pRspQryThreadInfo->Suspended<<std::endl;
  std::cout<<"on pRspQryThreadInfo->BlockCount:"<<pRspQryThreadInfo->BlockCount<<std::endl;
  std::cout<<"on pRspQryThreadInfo->WaitCount:"<<pRspQryThreadInfo->WaitCount<<std::endl;
  std::cout<<"on pRspQryThreadInfo->CpuTime:"<<pRspQryThreadInfo->CpuTime<<std::endl;
  std::cout<<"on pRspQryThreadInfo->UserTime:"<<pRspQryThreadInfo->UserTime<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryThreadInfoField* pNewRspQryThreadInfo =new CShfeFtdcRspQryThreadInfoField;
  memcpy(pNewRspQryThreadInfo,pRspQryThreadInfo,sizeof(CShfeFtdcRspQryThreadInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryThreadInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryThreadInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryThreadInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnThreadInfoTopic(CShfeFtdcRtnThreadInfoField *pRtnThreadInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnThreadInfo->ObjectID:"<<pRtnThreadInfo->ObjectID<<std::endl;
  std::cout<<"on pRtnThreadInfo->MonDate:"<<pRtnThreadInfo->MonDate<<std::endl;
  std::cout<<"on pRtnThreadInfo->MonTime:"<<pRtnThreadInfo->MonTime<<std::endl;
  std::cout<<"on pRtnThreadInfo->Name:"<<pRtnThreadInfo->Name<<std::endl;
  std::cout<<"on pRtnThreadInfo->ThreadNum:"<<pRtnThreadInfo->ThreadNum<<std::endl;
  std::cout<<"on pRtnThreadInfo->ThreadStatus:"<<pRtnThreadInfo->ThreadStatus<<std::endl;
  std::cout<<"on pRtnThreadInfo->InNative:"<<pRtnThreadInfo->InNative<<std::endl;
  std::cout<<"on pRtnThreadInfo->Suspended:"<<pRtnThreadInfo->Suspended<<std::endl;
  std::cout<<"on pRtnThreadInfo->BlockCount:"<<pRtnThreadInfo->BlockCount<<std::endl;
  std::cout<<"on pRtnThreadInfo->WaitCount:"<<pRtnThreadInfo->WaitCount<<std::endl;
  std::cout<<"on pRtnThreadInfo->CpuTime:"<<pRtnThreadInfo->CpuTime<<std::endl;
  std::cout<<"on pRtnThreadInfo->UserTime:"<<pRtnThreadInfo->UserTime<<std::endl;
  CShfeFtdcRtnThreadInfoField* pNewRtnThreadInfo =new CShfeFtdcRtnThreadInfoField;
  memcpy(pNewRtnThreadInfo,pRtnThreadInfo,sizeof(CShfeFtdcRtnThreadInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnThreadInfo;
  asyncOnRtnThreadInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnThreadInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryVMInfoTopic(CShfeFtdcRspQryVMInfoField *pRspQryVMInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryVMInfo->ObjectID:"<<pRspQryVMInfo->ObjectID<<std::endl;
  std::cout<<"on pRspQryVMInfo->MonDate:"<<pRspQryVMInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryVMInfo->MonTime:"<<pRspQryVMInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryVMInfo->Name:"<<pRspQryVMInfo->Name<<std::endl;
  std::cout<<"on pRspQryVMInfo->VmName:"<<pRspQryVMInfo->VmName<<std::endl;
  std::cout<<"on pRspQryVMInfo->VmVendor:"<<pRspQryVMInfo->VmVendor<<std::endl;
  std::cout<<"on pRspQryVMInfo->VmVersion:"<<pRspQryVMInfo->VmVersion<<std::endl;
  std::cout<<"on pRspQryVMInfo->StartTime:"<<pRspQryVMInfo->StartTime<<std::endl;
  std::cout<<"on pRspQryVMInfo->BootClassPath:"<<pRspQryVMInfo->BootClassPath<<std::endl;
  std::cout<<"on pRspQryVMInfo->ClassPath:"<<pRspQryVMInfo->ClassPath<<std::endl;
  std::cout<<"on pRspQryVMInfo->LibraryPath:"<<pRspQryVMInfo->LibraryPath<<std::endl;
  std::cout<<"on pRspQryVMInfo->Arguments:"<<pRspQryVMInfo->Arguments<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryVMInfoField* pNewRspQryVMInfo =new CShfeFtdcRspQryVMInfoField;
  memcpy(pNewRspQryVMInfo,pRspQryVMInfo,sizeof(CShfeFtdcRspQryVMInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryVMInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryVMInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryVMInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnVMInfoTopic(CShfeFtdcRtnVMInfoField *pRtnVMInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnVMInfo->ObjectID:"<<pRtnVMInfo->ObjectID<<std::endl;
  std::cout<<"on pRtnVMInfo->MonDate:"<<pRtnVMInfo->MonDate<<std::endl;
  std::cout<<"on pRtnVMInfo->MonTime:"<<pRtnVMInfo->MonTime<<std::endl;
  std::cout<<"on pRtnVMInfo->Name:"<<pRtnVMInfo->Name<<std::endl;
  std::cout<<"on pRtnVMInfo->VmName:"<<pRtnVMInfo->VmName<<std::endl;
  std::cout<<"on pRtnVMInfo->VmVendor:"<<pRtnVMInfo->VmVendor<<std::endl;
  std::cout<<"on pRtnVMInfo->VmVersion:"<<pRtnVMInfo->VmVersion<<std::endl;
  std::cout<<"on pRtnVMInfo->StartTime:"<<pRtnVMInfo->StartTime<<std::endl;
  std::cout<<"on pRtnVMInfo->BootClassPath:"<<pRtnVMInfo->BootClassPath<<std::endl;
  std::cout<<"on pRtnVMInfo->ClassPath:"<<pRtnVMInfo->ClassPath<<std::endl;
  std::cout<<"on pRtnVMInfo->LibraryPath:"<<pRtnVMInfo->LibraryPath<<std::endl;
  std::cout<<"on pRtnVMInfo->Arguments:"<<pRtnVMInfo->Arguments<<std::endl;
  CShfeFtdcRtnVMInfoField* pNewRtnVMInfo =new CShfeFtdcRtnVMInfoField;
  memcpy(pNewRtnVMInfo,pRtnVMInfo,sizeof(CShfeFtdcRtnVMInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnVMInfo;
  asyncOnRtnVMInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnVMInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryPropertyInfoTopic(CShfeFtdcRspQryPropertyInfoField *pRspQryPropertyInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryPropertyInfo->ObjectID:"<<pRspQryPropertyInfo->ObjectID<<std::endl;
  std::cout<<"on pRspQryPropertyInfo->MonDate:"<<pRspQryPropertyInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryPropertyInfo->MonTime:"<<pRspQryPropertyInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryPropertyInfo->Property:"<<pRspQryPropertyInfo->Property<<std::endl;
  std::cout<<"on pRspQryPropertyInfo->ClipFlag:"<<pRspQryPropertyInfo->ClipFlag<<std::endl;
  std::cout<<"on pRspQryPropertyInfo->Value:"<<pRspQryPropertyInfo->Value<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryPropertyInfoField* pNewRspQryPropertyInfo =new CShfeFtdcRspQryPropertyInfoField;
  memcpy(pNewRspQryPropertyInfo,pRspQryPropertyInfo,sizeof(CShfeFtdcRspQryPropertyInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryPropertyInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryPropertyInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryPropertyInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnPropertyInfoTopic(CShfeFtdcRtnPropertyInfoField *pRtnPropertyInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnPropertyInfo->ObjectID:"<<pRtnPropertyInfo->ObjectID<<std::endl;
  std::cout<<"on pRtnPropertyInfo->MonDate:"<<pRtnPropertyInfo->MonDate<<std::endl;
  std::cout<<"on pRtnPropertyInfo->MonTime:"<<pRtnPropertyInfo->MonTime<<std::endl;
  std::cout<<"on pRtnPropertyInfo->Property:"<<pRtnPropertyInfo->Property<<std::endl;
  std::cout<<"on pRtnPropertyInfo->ClipFlag:"<<pRtnPropertyInfo->ClipFlag<<std::endl;
  std::cout<<"on pRtnPropertyInfo->Value:"<<pRtnPropertyInfo->Value<<std::endl;
  CShfeFtdcRtnPropertyInfoField* pNewRtnPropertyInfo =new CShfeFtdcRtnPropertyInfoField;
  memcpy(pNewRtnPropertyInfo,pRtnPropertyInfo,sizeof(CShfeFtdcRtnPropertyInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnPropertyInfo;
  asyncOnRtnPropertyInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnPropertyInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryMemPoolInfoTopic(CShfeFtdcRspQryMemPoolInfoField *pRspQryMemPoolInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryMemPoolInfo->ObjectID:"<<pRspQryMemPoolInfo->ObjectID<<std::endl;
  std::cout<<"on pRspQryMemPoolInfo->MonDate:"<<pRspQryMemPoolInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryMemPoolInfo->MonTime:"<<pRspQryMemPoolInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryMemPoolInfo->PoolName:"<<pRspQryMemPoolInfo->PoolName<<std::endl;
  std::cout<<"on pRspQryMemPoolInfo->Usage:"<<pRspQryMemPoolInfo->Usage<<std::endl;
  std::cout<<"on pRspQryMemPoolInfo->committedbytes:"<<pRspQryMemPoolInfo->committedbytes<<std::endl;
  std::cout<<"on pRspQryMemPoolInfo->initbytes:"<<pRspQryMemPoolInfo->initbytes<<std::endl;
  std::cout<<"on pRspQryMemPoolInfo->maxbytes:"<<pRspQryMemPoolInfo->maxbytes<<std::endl;
  std::cout<<"on pRspQryMemPoolInfo->usedbytes:"<<pRspQryMemPoolInfo->usedbytes<<std::endl;
  std::cout<<"on pRspQryMemPoolInfo->Type:"<<pRspQryMemPoolInfo->Type<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryMemPoolInfoField* pNewRspQryMemPoolInfo =new CShfeFtdcRspQryMemPoolInfoField;
  memcpy(pNewRspQryMemPoolInfo,pRspQryMemPoolInfo,sizeof(CShfeFtdcRspQryMemPoolInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryMemPoolInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryMemPoolInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryMemPoolInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnMemPoolInfoTopic(CShfeFtdcRtnMemPoolInfoField *pRtnMemPoolInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnMemPoolInfo->ObjectID:"<<pRtnMemPoolInfo->ObjectID<<std::endl;
  std::cout<<"on pRtnMemPoolInfo->MonDate:"<<pRtnMemPoolInfo->MonDate<<std::endl;
  std::cout<<"on pRtnMemPoolInfo->MonTime:"<<pRtnMemPoolInfo->MonTime<<std::endl;
  std::cout<<"on pRtnMemPoolInfo->PoolName:"<<pRtnMemPoolInfo->PoolName<<std::endl;
  std::cout<<"on pRtnMemPoolInfo->Usage:"<<pRtnMemPoolInfo->Usage<<std::endl;
  std::cout<<"on pRtnMemPoolInfo->committedbytes:"<<pRtnMemPoolInfo->committedbytes<<std::endl;
  std::cout<<"on pRtnMemPoolInfo->initbytes:"<<pRtnMemPoolInfo->initbytes<<std::endl;
  std::cout<<"on pRtnMemPoolInfo->maxbytes:"<<pRtnMemPoolInfo->maxbytes<<std::endl;
  std::cout<<"on pRtnMemPoolInfo->usedbytes:"<<pRtnMemPoolInfo->usedbytes<<std::endl;
  std::cout<<"on pRtnMemPoolInfo->Type:"<<pRtnMemPoolInfo->Type<<std::endl;
  CShfeFtdcRtnMemPoolInfoField* pNewRtnMemPoolInfo =new CShfeFtdcRtnMemPoolInfoField;
  memcpy(pNewRtnMemPoolInfo,pRtnMemPoolInfo,sizeof(CShfeFtdcRtnMemPoolInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnMemPoolInfo;
  asyncOnRtnMemPoolInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnMemPoolInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryFileContentInfoTopic(CShfeFtdcRspQryFileContentInfoField *pRspQryFileContentInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryFileContentInfo->ObjectID:"<<pRspQryFileContentInfo->ObjectID<<std::endl;
  std::cout<<"on pRspQryFileContentInfo->MonDate:"<<pRspQryFileContentInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryFileContentInfo->MonTime:"<<pRspQryFileContentInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryFileContentInfo->FileName:"<<pRspQryFileContentInfo->FileName<<std::endl;
  std::cout<<"on pRspQryFileContentInfo->FileContent:"<<pRspQryFileContentInfo->FileContent<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryFileContentInfoField* pNewRspQryFileContentInfo =new CShfeFtdcRspQryFileContentInfoField;
  memcpy(pNewRspQryFileContentInfo,pRspQryFileContentInfo,sizeof(CShfeFtdcRspQryFileContentInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryFileContentInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryFileContentInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryFileContentInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnFileContentInfoTopic(CShfeFtdcRtnFileContentInfoField *pRtnFileContentInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnFileContentInfo->ObjectID:"<<pRtnFileContentInfo->ObjectID<<std::endl;
  std::cout<<"on pRtnFileContentInfo->MonDate:"<<pRtnFileContentInfo->MonDate<<std::endl;
  std::cout<<"on pRtnFileContentInfo->MonTime:"<<pRtnFileContentInfo->MonTime<<std::endl;
  std::cout<<"on pRtnFileContentInfo->FileName:"<<pRtnFileContentInfo->FileName<<std::endl;
  std::cout<<"on pRtnFileContentInfo->FileContent:"<<pRtnFileContentInfo->FileContent<<std::endl;
  CShfeFtdcRtnFileContentInfoField* pNewRtnFileContentInfo =new CShfeFtdcRtnFileContentInfoField;
  memcpy(pNewRtnFileContentInfo,pRtnFileContentInfo,sizeof(CShfeFtdcRtnFileContentInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnFileContentInfo;
  asyncOnRtnFileContentInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnFileContentInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryConnectionInfoTopic(CShfeFtdcRspQryConnectionInfoField *pRspQryConnectionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryConnectionInfo->ObjectID:"<<pRspQryConnectionInfo->ObjectID<<std::endl;
  std::cout<<"on pRspQryConnectionInfo->MonDate:"<<pRspQryConnectionInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryConnectionInfo->MonTime:"<<pRspQryConnectionInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryConnectionInfo->ServiceName:"<<pRspQryConnectionInfo->ServiceName<<std::endl;
  std::cout<<"on pRspQryConnectionInfo->Stage:"<<pRspQryConnectionInfo->Stage<<std::endl;
  std::cout<<"on pRspQryConnectionInfo->RequestCount:"<<pRspQryConnectionInfo->RequestCount<<std::endl;
  std::cout<<"on pRspQryConnectionInfo->ErrorCount:"<<pRspQryConnectionInfo->ErrorCount<<std::endl;
  std::cout<<"on pRspQryConnectionInfo->ProcTime:"<<pRspQryConnectionInfo->ProcTime<<std::endl;
  std::cout<<"on pRspQryConnectionInfo->BytesReceived:"<<pRspQryConnectionInfo->BytesReceived<<std::endl;
  std::cout<<"on pRspQryConnectionInfo->BytesSent:"<<pRspQryConnectionInfo->BytesSent<<std::endl;
  std::cout<<"on pRspQryConnectionInfo->RemoteIP:"<<pRspQryConnectionInfo->RemoteIP<<std::endl;
  std::cout<<"on pRspQryConnectionInfo->MaxAccessURI:"<<pRspQryConnectionInfo->MaxAccessURI<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryConnectionInfoField* pNewRspQryConnectionInfo =new CShfeFtdcRspQryConnectionInfoField;
  memcpy(pNewRspQryConnectionInfo,pRspQryConnectionInfo,sizeof(CShfeFtdcRspQryConnectionInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryConnectionInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryConnectionInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryConnectionInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnConnectionInfoTopic(CShfeFtdcRtnConnectionInfoField *pRtnConnectionInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnConnectionInfo->ObjectID:"<<pRtnConnectionInfo->ObjectID<<std::endl;
  std::cout<<"on pRtnConnectionInfo->MonDate:"<<pRtnConnectionInfo->MonDate<<std::endl;
  std::cout<<"on pRtnConnectionInfo->MonTime:"<<pRtnConnectionInfo->MonTime<<std::endl;
  std::cout<<"on pRtnConnectionInfo->ServiceName:"<<pRtnConnectionInfo->ServiceName<<std::endl;
  std::cout<<"on pRtnConnectionInfo->Stage:"<<pRtnConnectionInfo->Stage<<std::endl;
  std::cout<<"on pRtnConnectionInfo->RequestCount:"<<pRtnConnectionInfo->RequestCount<<std::endl;
  std::cout<<"on pRtnConnectionInfo->ErrorCount:"<<pRtnConnectionInfo->ErrorCount<<std::endl;
  std::cout<<"on pRtnConnectionInfo->ProcTime:"<<pRtnConnectionInfo->ProcTime<<std::endl;
  std::cout<<"on pRtnConnectionInfo->BytesReceived:"<<pRtnConnectionInfo->BytesReceived<<std::endl;
  std::cout<<"on pRtnConnectionInfo->BytesSent:"<<pRtnConnectionInfo->BytesSent<<std::endl;
  std::cout<<"on pRtnConnectionInfo->RemoteIP:"<<pRtnConnectionInfo->RemoteIP<<std::endl;
  std::cout<<"on pRtnConnectionInfo->MaxAccessURI:"<<pRtnConnectionInfo->MaxAccessURI<<std::endl;
  CShfeFtdcRtnConnectionInfoField* pNewRtnConnectionInfo =new CShfeFtdcRtnConnectionInfoField;
  memcpy(pNewRtnConnectionInfo,pRtnConnectionInfo,sizeof(CShfeFtdcRtnConnectionInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnConnectionInfo;
  asyncOnRtnConnectionInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnConnectionInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryConnectorInfoTopic(CShfeFtdcRspQryConnectorInfoField *pRspQryConnectorInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryConnectorInfo->ObjectID:"<<pRspQryConnectorInfo->ObjectID<<std::endl;
  std::cout<<"on pRspQryConnectorInfo->MonDate:"<<pRspQryConnectorInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryConnectorInfo->MonTime:"<<pRspQryConnectorInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryConnectorInfo->Name:"<<pRspQryConnectorInfo->Name<<std::endl;
  std::cout<<"on pRspQryConnectorInfo->ThreadsCount:"<<pRspQryConnectorInfo->ThreadsCount<<std::endl;
  std::cout<<"on pRspQryConnectorInfo->BusyThreadsCount:"<<pRspQryConnectorInfo->BusyThreadsCount<<std::endl;
  std::cout<<"on pRspQryConnectorInfo->MaxThreads:"<<pRspQryConnectorInfo->MaxThreads<<std::endl;
  std::cout<<"on pRspQryConnectorInfo->MaxSpareThreads:"<<pRspQryConnectorInfo->MaxSpareThreads<<std::endl;
  std::cout<<"on pRspQryConnectorInfo->MinSpareThreads:"<<pRspQryConnectorInfo->MinSpareThreads<<std::endl;
  std::cout<<"on pRspQryConnectorInfo->MaxTime:"<<pRspQryConnectorInfo->MaxTime<<std::endl;
  std::cout<<"on pRspQryConnectorInfo->MaxProcTime:"<<pRspQryConnectorInfo->MaxProcTime<<std::endl;
  std::cout<<"on pRspQryConnectorInfo->RequestCount:"<<pRspQryConnectorInfo->RequestCount<<std::endl;
  std::cout<<"on pRspQryConnectorInfo->ErrorCount:"<<pRspQryConnectorInfo->ErrorCount<<std::endl;
  std::cout<<"on pRspQryConnectorInfo->BytesReceived:"<<pRspQryConnectorInfo->BytesReceived<<std::endl;
  std::cout<<"on pRspQryConnectorInfo->BytesSent:"<<pRspQryConnectorInfo->BytesSent<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryConnectorInfoField* pNewRspQryConnectorInfo =new CShfeFtdcRspQryConnectorInfoField;
  memcpy(pNewRspQryConnectorInfo,pRspQryConnectorInfo,sizeof(CShfeFtdcRspQryConnectorInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryConnectorInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryConnectorInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryConnectorInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnConnectorInfoTopic(CShfeFtdcRtnConnectorInfoField *pRtnConnectorInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnConnectorInfo->ObjectID:"<<pRtnConnectorInfo->ObjectID<<std::endl;
  std::cout<<"on pRtnConnectorInfo->MonDate:"<<pRtnConnectorInfo->MonDate<<std::endl;
  std::cout<<"on pRtnConnectorInfo->MonTime:"<<pRtnConnectorInfo->MonTime<<std::endl;
  std::cout<<"on pRtnConnectorInfo->Name:"<<pRtnConnectorInfo->Name<<std::endl;
  std::cout<<"on pRtnConnectorInfo->ThreadsCount:"<<pRtnConnectorInfo->ThreadsCount<<std::endl;
  std::cout<<"on pRtnConnectorInfo->BusyThreadsCount:"<<pRtnConnectorInfo->BusyThreadsCount<<std::endl;
  std::cout<<"on pRtnConnectorInfo->MaxThreads:"<<pRtnConnectorInfo->MaxThreads<<std::endl;
  std::cout<<"on pRtnConnectorInfo->MaxSpareThreads:"<<pRtnConnectorInfo->MaxSpareThreads<<std::endl;
  std::cout<<"on pRtnConnectorInfo->MinSpareThreads:"<<pRtnConnectorInfo->MinSpareThreads<<std::endl;
  std::cout<<"on pRtnConnectorInfo->MaxTime:"<<pRtnConnectorInfo->MaxTime<<std::endl;
  std::cout<<"on pRtnConnectorInfo->MaxProcTime:"<<pRtnConnectorInfo->MaxProcTime<<std::endl;
  std::cout<<"on pRtnConnectorInfo->RequestCount:"<<pRtnConnectorInfo->RequestCount<<std::endl;
  std::cout<<"on pRtnConnectorInfo->ErrorCount:"<<pRtnConnectorInfo->ErrorCount<<std::endl;
  std::cout<<"on pRtnConnectorInfo->BytesReceived:"<<pRtnConnectorInfo->BytesReceived<<std::endl;
  std::cout<<"on pRtnConnectorInfo->BytesSent:"<<pRtnConnectorInfo->BytesSent<<std::endl;
  CShfeFtdcRtnConnectorInfoField* pNewRtnConnectorInfo =new CShfeFtdcRtnConnectorInfoField;
  memcpy(pNewRtnConnectorInfo,pRtnConnectorInfo,sizeof(CShfeFtdcRtnConnectorInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnConnectorInfo;
  asyncOnRtnConnectorInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnConnectorInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryDBQueryTopic(CShfeFtdcRspQryDBQueryField *pRspQryDBQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryDBQuery->ObjectID:"<<pRspQryDBQuery->ObjectID<<std::endl;
  std::cout<<"on pRspQryDBQuery->AttrType:"<<pRspQryDBQuery->AttrType<<std::endl;
  std::cout<<"on pRspQryDBQuery->MonDate:"<<pRspQryDBQuery->MonDate<<std::endl;
  std::cout<<"on pRspQryDBQuery->MonTime:"<<pRspQryDBQuery->MonTime<<std::endl;
  std::cout<<"on pRspQryDBQuery->DBQueryResult:"<<pRspQryDBQuery->DBQueryResult<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryDBQueryField* pNewRspQryDBQuery =new CShfeFtdcRspQryDBQueryField;
  memcpy(pNewRspQryDBQuery,pRspQryDBQuery,sizeof(CShfeFtdcRspQryDBQueryField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryDBQuery;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryDBQueryTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryDBQueryTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnDBQueryTopic(CShfeFtdcRtnDBQueryField *pRtnDBQuery)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnDBQuery->ObjectID:"<<pRtnDBQuery->ObjectID<<std::endl;
  std::cout<<"on pRtnDBQuery->AttrType:"<<pRtnDBQuery->AttrType<<std::endl;
  std::cout<<"on pRtnDBQuery->MonDate:"<<pRtnDBQuery->MonDate<<std::endl;
  std::cout<<"on pRtnDBQuery->MonTime:"<<pRtnDBQuery->MonTime<<std::endl;
  std::cout<<"on pRtnDBQuery->DBQueryResult:"<<pRtnDBQuery->DBQueryResult<<std::endl;
  CShfeFtdcRtnDBQueryField* pNewRtnDBQuery =new CShfeFtdcRtnDBQueryField;
  memcpy(pNewRtnDBQuery,pRtnDBQuery,sizeof(CShfeFtdcRtnDBQueryField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnDBQuery;
  asyncOnRtnDBQueryTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnDBQueryTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryGeneralFieldTopic(CShfeFtdcSysGeneralFieldField *pSysGeneralField, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pSysGeneralField->MonDate:"<<pSysGeneralField->MonDate<<std::endl;
  std::cout<<"on pSysGeneralField->MonTime:"<<pSysGeneralField->MonTime<<std::endl;
  std::cout<<"on pSysGeneralField->ObjectID:"<<pSysGeneralField->ObjectID<<std::endl;
  std::cout<<"on pSysGeneralField->SubObjectID:"<<pSysGeneralField->SubObjectID<<std::endl;
  std::cout<<"on pSysGeneralField->AttrType:"<<pSysGeneralField->AttrType<<std::endl;
  std::cout<<"on pSysGeneralField->Content:"<<pSysGeneralField->Content<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcSysGeneralFieldField* pNewSysGeneralField =new CShfeFtdcSysGeneralFieldField;
  memcpy(pNewSysGeneralField,pSysGeneralField,sizeof(CShfeFtdcSysGeneralFieldField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewSysGeneralField;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryGeneralFieldTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryGeneralFieldTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnGeneralFieldTopic(CShfeFtdcSysGeneralFieldField *pSysGeneralField)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pSysGeneralField->MonDate:"<<pSysGeneralField->MonDate<<std::endl;
  std::cout<<"on pSysGeneralField->MonTime:"<<pSysGeneralField->MonTime<<std::endl;
  std::cout<<"on pSysGeneralField->ObjectID:"<<pSysGeneralField->ObjectID<<std::endl;
  std::cout<<"on pSysGeneralField->SubObjectID:"<<pSysGeneralField->SubObjectID<<std::endl;
  std::cout<<"on pSysGeneralField->AttrType:"<<pSysGeneralField->AttrType<<std::endl;
  std::cout<<"on pSysGeneralField->Content:"<<pSysGeneralField->Content<<std::endl;
  CShfeFtdcSysGeneralFieldField* pNewSysGeneralField =new CShfeFtdcSysGeneralFieldField;
  memcpy(pNewSysGeneralField,pSysGeneralField,sizeof(CShfeFtdcSysGeneralFieldField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewSysGeneralField;
  asyncOnRtnGeneralFieldTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnGeneralFieldTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryGetFileTopic(CShfeFtdcRspQryGetFileField *pRspQryGetFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryGetFile->FileName:"<<pRspQryGetFile->FileName<<std::endl;
  std::cout<<"on pRspQryGetFile->Version:"<<pRspQryGetFile->Version<<std::endl;
  std::cout<<"on pRspQryGetFile->Offset:"<<pRspQryGetFile->Offset<<std::endl;
  std::cout<<"on pRspQryGetFile->Length:"<<pRspQryGetFile->Length<<std::endl;
  std::cout<<"on pRspQryGetFile->Comment:"<<pRspQryGetFile->Comment<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryGetFileField* pNewRspQryGetFile =new CShfeFtdcRspQryGetFileField;
  memcpy(pNewRspQryGetFile,pRspQryGetFile,sizeof(CShfeFtdcRspQryGetFileField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryGetFile;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryGetFileTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryGetFileTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryWarningQueryTopic(CShfeFtdcRspQryWarningQueryField *pRspQryWarningQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryWarningQuery->MonDate:"<<pRspQryWarningQuery->MonDate<<std::endl;
  std::cout<<"on pRspQryWarningQuery->MonTime:"<<pRspQryWarningQuery->MonTime<<std::endl;
  std::cout<<"on pRspQryWarningQuery->EvendID:"<<pRspQryWarningQuery->EvendID<<std::endl;
  std::cout<<"on pRspQryWarningQuery->DBQueryResult:"<<pRspQryWarningQuery->DBQueryResult<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryWarningQueryField* pNewRspQryWarningQuery =new CShfeFtdcRspQryWarningQueryField;
  memcpy(pNewRspQryWarningQuery,pRspQryWarningQuery,sizeof(CShfeFtdcRspQryWarningQueryField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryWarningQuery;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryWarningQueryTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryWarningQueryTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnWarningQueryTopic(CShfeFtdcRtnWarningQueryField *pRtnWarningQuery)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnWarningQuery->MonDate:"<<pRtnWarningQuery->MonDate<<std::endl;
  std::cout<<"on pRtnWarningQuery->MonTime:"<<pRtnWarningQuery->MonTime<<std::endl;
  std::cout<<"on pRtnWarningQuery->EvendID:"<<pRtnWarningQuery->EvendID<<std::endl;
  std::cout<<"on pRtnWarningQuery->DBQueryResult:"<<pRtnWarningQuery->DBQueryResult<<std::endl;
  CShfeFtdcRtnWarningQueryField* pNewRtnWarningQuery =new CShfeFtdcRtnWarningQueryField;
  memcpy(pNewRtnWarningQuery,pRtnWarningQuery,sizeof(CShfeFtdcRtnWarningQueryField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnWarningQuery;
  asyncOnRtnWarningQueryTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnWarningQueryTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnHostConfig(CShfeFtdcRtnHostConfigField *pRtnHostConfig)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnHostConfig->CfgType:"<<pRtnHostConfig->CfgType<<std::endl;
  std::cout<<"on pRtnHostConfig->CfgDataCenter:"<<pRtnHostConfig->CfgDataCenter<<std::endl;
  std::cout<<"on pRtnHostConfig->CfgName:"<<pRtnHostConfig->CfgName<<std::endl;
  std::cout<<"on pRtnHostConfig->CfgLocation:"<<pRtnHostConfig->CfgLocation<<std::endl;
  std::cout<<"on pRtnHostConfig->CfgHostName:"<<pRtnHostConfig->CfgHostName<<std::endl;
  std::cout<<"on pRtnHostConfig->CfgAttend:"<<pRtnHostConfig->CfgAttend<<std::endl;
  CShfeFtdcRtnHostConfigField* pNewRtnHostConfig =new CShfeFtdcRtnHostConfigField;
  memcpy(pNewRtnHostConfig,pRtnHostConfig,sizeof(CShfeFtdcRtnHostConfigField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnHostConfig;
  asyncOnRtnHostConfig.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnHostConfig);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryGeneralOperateTopic(CShfeFtdcRspQryGeneralOperateField *pRspQryGeneralOperate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryGeneralOperate->GeneralOperateType:"<<pRspQryGeneralOperate->GeneralOperateType<<std::endl;
  std::cout<<"on pRspQryGeneralOperate->GeneralOperateTable:"<<pRspQryGeneralOperate->GeneralOperateTable<<std::endl;
  std::cout<<"on pRspQryGeneralOperate->GeneralOperateOption:"<<pRspQryGeneralOperate->GeneralOperateOption<<std::endl;
  std::cout<<"on pRspQryGeneralOperate->GeneralOperateSet:"<<pRspQryGeneralOperate->GeneralOperateSet<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryGeneralOperateField* pNewRspQryGeneralOperate =new CShfeFtdcRspQryGeneralOperateField;
  memcpy(pNewRspQryGeneralOperate,pRspQryGeneralOperate,sizeof(CShfeFtdcRspQryGeneralOperateField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryGeneralOperate;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryGeneralOperateTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryGeneralOperateTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnGeneralOperateTopic(CShfeFtdcRtnGeneralOperateField *pRtnGeneralOperate)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnGeneralOperate->GeneralOperateType:"<<pRtnGeneralOperate->GeneralOperateType<<std::endl;
  std::cout<<"on pRtnGeneralOperate->GeneralOperateTable:"<<pRtnGeneralOperate->GeneralOperateTable<<std::endl;
  std::cout<<"on pRtnGeneralOperate->GeneralOperateOption:"<<pRtnGeneralOperate->GeneralOperateOption<<std::endl;
  std::cout<<"on pRtnGeneralOperate->GeneralOperateSet:"<<pRtnGeneralOperate->GeneralOperateSet<<std::endl;
  CShfeFtdcRtnGeneralOperateField* pNewRtnGeneralOperate =new CShfeFtdcRtnGeneralOperateField;
  memcpy(pNewRtnGeneralOperate,pRtnGeneralOperate,sizeof(CShfeFtdcRtnGeneralOperateField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnGeneralOperate;
  asyncOnRtnGeneralOperateTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnGeneralOperateTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetDeviceLinkedTopic(CShfeFtdcRspQryNetDeviceLinkedField *pRspQryNetDeviceLinked, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetDeviceLinked->OperationType:"<<pRspQryNetDeviceLinked->OperationType<<std::endl;
  std::cout<<"on pRspQryNetDeviceLinked->ID:"<<pRspQryNetDeviceLinked->ID<<std::endl;
  std::cout<<"on pRspQryNetDeviceLinked->NetDeviceID:"<<pRspQryNetDeviceLinked->NetDeviceID<<std::endl;
  std::cout<<"on pRspQryNetDeviceLinked->NetPortID:"<<pRspQryNetDeviceLinked->NetPortID<<std::endl;
  std::cout<<"on pRspQryNetDeviceLinked->NetObjectID:"<<pRspQryNetDeviceLinked->NetObjectID<<std::endl;
  std::cout<<"on pRspQryNetDeviceLinked->NetPortType:"<<pRspQryNetDeviceLinked->NetPortType<<std::endl;
  std::cout<<"on pRspQryNetDeviceLinked->LinkNetDeviceID:"<<pRspQryNetDeviceLinked->LinkNetDeviceID<<std::endl;
  std::cout<<"on pRspQryNetDeviceLinked->LinkNetPortID:"<<pRspQryNetDeviceLinked->LinkNetPortID<<std::endl;
  std::cout<<"on pRspQryNetDeviceLinked->LinkNetObjectID:"<<pRspQryNetDeviceLinked->LinkNetObjectID<<std::endl;
  std::cout<<"on pRspQryNetDeviceLinked->LinkNetPortType:"<<pRspQryNetDeviceLinked->LinkNetPortType<<std::endl;
  std::cout<<"on pRspQryNetDeviceLinked->LinkSource:"<<pRspQryNetDeviceLinked->LinkSource<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetDeviceLinkedField* pNewRspQryNetDeviceLinked =new CShfeFtdcRspQryNetDeviceLinkedField;
  memcpy(pNewRspQryNetDeviceLinked,pRspQryNetDeviceLinked,sizeof(CShfeFtdcRspQryNetDeviceLinkedField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetDeviceLinked;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetDeviceLinkedTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetDeviceLinkedTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetDeviceLinkedTopic(CShfeFtdcRtnNetDeviceLinkedField *pRtnNetDeviceLinked)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetDeviceLinked->OperationType:"<<pRtnNetDeviceLinked->OperationType<<std::endl;
  std::cout<<"on pRtnNetDeviceLinked->ID:"<<pRtnNetDeviceLinked->ID<<std::endl;
  std::cout<<"on pRtnNetDeviceLinked->NetDeviceID:"<<pRtnNetDeviceLinked->NetDeviceID<<std::endl;
  std::cout<<"on pRtnNetDeviceLinked->NetPortID:"<<pRtnNetDeviceLinked->NetPortID<<std::endl;
  std::cout<<"on pRtnNetDeviceLinked->NetObjectID:"<<pRtnNetDeviceLinked->NetObjectID<<std::endl;
  std::cout<<"on pRtnNetDeviceLinked->NetPortType:"<<pRtnNetDeviceLinked->NetPortType<<std::endl;
  std::cout<<"on pRtnNetDeviceLinked->LinkNetDeviceID:"<<pRtnNetDeviceLinked->LinkNetDeviceID<<std::endl;
  std::cout<<"on pRtnNetDeviceLinked->LinkNetPortID:"<<pRtnNetDeviceLinked->LinkNetPortID<<std::endl;
  std::cout<<"on pRtnNetDeviceLinked->LinkNetObjectID:"<<pRtnNetDeviceLinked->LinkNetObjectID<<std::endl;
  std::cout<<"on pRtnNetDeviceLinked->LinkNetPortType:"<<pRtnNetDeviceLinked->LinkNetPortType<<std::endl;
  std::cout<<"on pRtnNetDeviceLinked->LinkSource:"<<pRtnNetDeviceLinked->LinkSource<<std::endl;
  CShfeFtdcRtnNetDeviceLinkedField* pNewRtnNetDeviceLinked =new CShfeFtdcRtnNetDeviceLinkedField;
  memcpy(pNewRtnNetDeviceLinked,pRtnNetDeviceLinked,sizeof(CShfeFtdcRtnNetDeviceLinkedField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetDeviceLinked;
  asyncOnRtnNetDeviceLinkedTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetDeviceLinkedTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryTradeUserLoginStatTopic(CShfeFtdcRspQryTradeUserLoginStatField *pRspQryTradeUserLoginStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginStat->MonDate:"<<pRspQryTradeUserLoginStat->MonDate<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginStat->MonTime:"<<pRspQryTradeUserLoginStat->MonTime<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginStat->ObjectID:"<<pRspQryTradeUserLoginStat->ObjectID<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginStat->IPAddress:"<<pRspQryTradeUserLoginStat->IPAddress<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginStat->ParticipantID:"<<pRspQryTradeUserLoginStat->ParticipantID<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginStat->UserID:"<<pRspQryTradeUserLoginStat->UserID<<std::endl;
  std::cout<<"on pRspQryTradeUserLoginStat->FrontId:"<<pRspQryTradeUserLoginStat->FrontId<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryTradeUserLoginStatField* pNewRspQryTradeUserLoginStat =new CShfeFtdcRspQryTradeUserLoginStatField;
  memcpy(pNewRspQryTradeUserLoginStat,pRspQryTradeUserLoginStat,sizeof(CShfeFtdcRspQryTradeUserLoginStatField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTradeUserLoginStat;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTradeUserLoginStatTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryTradeUserLoginStatTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryTradeFrontOrderRttStatTopic(CShfeFtdcRspQryTradeFrontOrderRttStatField *pRspQryTradeFrontOrderRttStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryTradeFrontOrderRttStat->MonDate:"<<pRspQryTradeFrontOrderRttStat->MonDate<<std::endl;
  std::cout<<"on pRspQryTradeFrontOrderRttStat->MonTime:"<<pRspQryTradeFrontOrderRttStat->MonTime<<std::endl;
  std::cout<<"on pRspQryTradeFrontOrderRttStat->ObjectID:"<<pRspQryTradeFrontOrderRttStat->ObjectID<<std::endl;
  std::cout<<"on pRspQryTradeFrontOrderRttStat->OrderCount:"<<pRspQryTradeFrontOrderRttStat->OrderCount<<std::endl;
  std::cout<<"on pRspQryTradeFrontOrderRttStat->OrderRttSum:"<<pRspQryTradeFrontOrderRttStat->OrderRttSum<<std::endl;
  std::cout<<"on pRspQryTradeFrontOrderRttStat->OrderMaxRtt:"<<pRspQryTradeFrontOrderRttStat->OrderMaxRtt<<std::endl;
  std::cout<<"on pRspQryTradeFrontOrderRttStat->OrderMinRtt:"<<pRspQryTradeFrontOrderRttStat->OrderMinRtt<<std::endl;
  std::cout<<"on pRspQryTradeFrontOrderRttStat->OrderRttSqu:"<<pRspQryTradeFrontOrderRttStat->OrderRttSqu<<std::endl;
  std::cout<<"on pRspQryTradeFrontOrderRttStat->OrderRttCutDistrib:"<<pRspQryTradeFrontOrderRttStat->OrderRttCutDistrib<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryTradeFrontOrderRttStatField* pNewRspQryTradeFrontOrderRttStat =new CShfeFtdcRspQryTradeFrontOrderRttStatField;
  memcpy(pNewRspQryTradeFrontOrderRttStat,pRspQryTradeFrontOrderRttStat,sizeof(CShfeFtdcRspQryTradeFrontOrderRttStatField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTradeFrontOrderRttStat;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTradeFrontOrderRttStatTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryTradeFrontOrderRttStatTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnTradeFrontOrderRttStatTopic(CShfeFtdcRtnTradeFrontOrderRttStatField *pRtnTradeFrontOrderRttStat)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnTradeFrontOrderRttStat->MonDate:"<<pRtnTradeFrontOrderRttStat->MonDate<<std::endl;
  std::cout<<"on pRtnTradeFrontOrderRttStat->MonTime:"<<pRtnTradeFrontOrderRttStat->MonTime<<std::endl;
  std::cout<<"on pRtnTradeFrontOrderRttStat->ObjectID:"<<pRtnTradeFrontOrderRttStat->ObjectID<<std::endl;
  std::cout<<"on pRtnTradeFrontOrderRttStat->OrderCount:"<<pRtnTradeFrontOrderRttStat->OrderCount<<std::endl;
  std::cout<<"on pRtnTradeFrontOrderRttStat->OrderRttSum:"<<pRtnTradeFrontOrderRttStat->OrderRttSum<<std::endl;
  std::cout<<"on pRtnTradeFrontOrderRttStat->OrderMaxRtt:"<<pRtnTradeFrontOrderRttStat->OrderMaxRtt<<std::endl;
  std::cout<<"on pRtnTradeFrontOrderRttStat->OrderMinRtt:"<<pRtnTradeFrontOrderRttStat->OrderMinRtt<<std::endl;
  std::cout<<"on pRtnTradeFrontOrderRttStat->OrderRttSqu:"<<pRtnTradeFrontOrderRttStat->OrderRttSqu<<std::endl;
  std::cout<<"on pRtnTradeFrontOrderRttStat->OrderRttCutDistrib:"<<pRtnTradeFrontOrderRttStat->OrderRttCutDistrib<<std::endl;
  CShfeFtdcRtnTradeFrontOrderRttStatField* pNewRtnTradeFrontOrderRttStat =new CShfeFtdcRtnTradeFrontOrderRttStatField;
  memcpy(pNewRtnTradeFrontOrderRttStat,pRtnTradeFrontOrderRttStat,sizeof(CShfeFtdcRtnTradeFrontOrderRttStatField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnTradeFrontOrderRttStat;
  asyncOnRtnTradeFrontOrderRttStatTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnTradeFrontOrderRttStatTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryParticTradeOrderStatesTopic(CShfeFtdcRspQryParticTradeOrderStatesField *pRspQryParticTradeOrderStates, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryParticTradeOrderStates->ParticipantID:"<<pRspQryParticTradeOrderStates->ParticipantID<<std::endl;
  std::cout<<"on pRspQryParticTradeOrderStates->UserID:"<<pRspQryParticTradeOrderStates->UserID<<std::endl;
  std::cout<<"on pRspQryParticTradeOrderStates->MonDate:"<<pRspQryParticTradeOrderStates->MonDate<<std::endl;
  std::cout<<"on pRspQryParticTradeOrderStates->MonTime:"<<pRspQryParticTradeOrderStates->MonTime<<std::endl;
  std::cout<<"on pRspQryParticTradeOrderStates->StaticWidth:"<<pRspQryParticTradeOrderStates->StaticWidth<<std::endl;
  std::cout<<"on pRspQryParticTradeOrderStates->FrontID:"<<pRspQryParticTradeOrderStates->FrontID<<std::endl;
  std::cout<<"on pRspQryParticTradeOrderStates->OrderCount:"<<pRspQryParticTradeOrderStates->OrderCount<<std::endl;
  std::cout<<"on pRspQryParticTradeOrderStates->CancleCount:"<<pRspQryParticTradeOrderStates->CancleCount<<std::endl;
  std::cout<<"on pRspQryParticTradeOrderStates->QueryCount:"<<pRspQryParticTradeOrderStates->QueryCount<<std::endl;
  std::cout<<"on pRspQryParticTradeOrderStates->TradeCount:"<<pRspQryParticTradeOrderStates->TradeCount<<std::endl;
  std::cout<<"on pRspQryParticTradeOrderStates->TradeMoney:"<<pRspQryParticTradeOrderStates->TradeMoney<<std::endl;
  std::cout<<"on pRspQryParticTradeOrderStates->OrderCntMax:"<<pRspQryParticTradeOrderStates->OrderCntMax<<std::endl;
  std::cout<<"on pRspQryParticTradeOrderStates->CancleCntMax:"<<pRspQryParticTradeOrderStates->CancleCntMax<<std::endl;
  std::cout<<"on pRspQryParticTradeOrderStates->QueryCntMax:"<<pRspQryParticTradeOrderStates->QueryCntMax<<std::endl;
  std::cout<<"on pRspQryParticTradeOrderStates->TradeCntMax:"<<pRspQryParticTradeOrderStates->TradeCntMax<<std::endl;
  std::cout<<"on pRspQryParticTradeOrderStates->TradeMoneyMax:"<<pRspQryParticTradeOrderStates->TradeMoneyMax<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryParticTradeOrderStatesField* pNewRspQryParticTradeOrderStates =new CShfeFtdcRspQryParticTradeOrderStatesField;
  memcpy(pNewRspQryParticTradeOrderStates,pRspQryParticTradeOrderStates,sizeof(CShfeFtdcRspQryParticTradeOrderStatesField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryParticTradeOrderStates;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryParticTradeOrderStatesTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryParticTradeOrderStatesTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnParticTradeOrderStatesTopic(CShfeFtdcRtnParticTradeOrderStatesField *pRtnParticTradeOrderStates)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnParticTradeOrderStates->ParticipantID:"<<pRtnParticTradeOrderStates->ParticipantID<<std::endl;
  std::cout<<"on pRtnParticTradeOrderStates->UserID:"<<pRtnParticTradeOrderStates->UserID<<std::endl;
  std::cout<<"on pRtnParticTradeOrderStates->MonDate:"<<pRtnParticTradeOrderStates->MonDate<<std::endl;
  std::cout<<"on pRtnParticTradeOrderStates->MonTime:"<<pRtnParticTradeOrderStates->MonTime<<std::endl;
  std::cout<<"on pRtnParticTradeOrderStates->StaticWidth:"<<pRtnParticTradeOrderStates->StaticWidth<<std::endl;
  std::cout<<"on pRtnParticTradeOrderStates->FrontID:"<<pRtnParticTradeOrderStates->FrontID<<std::endl;
  std::cout<<"on pRtnParticTradeOrderStates->OrderCount:"<<pRtnParticTradeOrderStates->OrderCount<<std::endl;
  std::cout<<"on pRtnParticTradeOrderStates->CancleCount:"<<pRtnParticTradeOrderStates->CancleCount<<std::endl;
  std::cout<<"on pRtnParticTradeOrderStates->QueryCount:"<<pRtnParticTradeOrderStates->QueryCount<<std::endl;
  std::cout<<"on pRtnParticTradeOrderStates->TradeCount:"<<pRtnParticTradeOrderStates->TradeCount<<std::endl;
  std::cout<<"on pRtnParticTradeOrderStates->TradeMoney:"<<pRtnParticTradeOrderStates->TradeMoney<<std::endl;
  std::cout<<"on pRtnParticTradeOrderStates->OrderCntMax:"<<pRtnParticTradeOrderStates->OrderCntMax<<std::endl;
  std::cout<<"on pRtnParticTradeOrderStates->CancleCntMax:"<<pRtnParticTradeOrderStates->CancleCntMax<<std::endl;
  std::cout<<"on pRtnParticTradeOrderStates->QueryCntMax:"<<pRtnParticTradeOrderStates->QueryCntMax<<std::endl;
  std::cout<<"on pRtnParticTradeOrderStates->TradeCntMax:"<<pRtnParticTradeOrderStates->TradeCntMax<<std::endl;
  std::cout<<"on pRtnParticTradeOrderStates->TradeMoneyMax:"<<pRtnParticTradeOrderStates->TradeMoneyMax<<std::endl;
  CShfeFtdcRtnParticTradeOrderStatesField* pNewRtnParticTradeOrderStates =new CShfeFtdcRtnParticTradeOrderStatesField;
  memcpy(pNewRtnParticTradeOrderStates,pRtnParticTradeOrderStates,sizeof(CShfeFtdcRtnParticTradeOrderStatesField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnParticTradeOrderStates;
  asyncOnRtnParticTradeOrderStatesTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnParticTradeOrderStatesTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryRouterInfoTopic(CShfeFtdcRspQryRouterInfoField *pRspQryRouterInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryRouterInfo->HostName:"<<pRspQryRouterInfo->HostName<<std::endl;
  std::cout<<"on pRspQryRouterInfo->MonDate:"<<pRspQryRouterInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryRouterInfo->MonTime:"<<pRspQryRouterInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryRouterInfo->Dev:"<<pRspQryRouterInfo->Dev<<std::endl;
  std::cout<<"on pRspQryRouterInfo->Destination:"<<pRspQryRouterInfo->Destination<<std::endl;
  std::cout<<"on pRspQryRouterInfo->Gateway:"<<pRspQryRouterInfo->Gateway<<std::endl;
  std::cout<<"on pRspQryRouterInfo->Mask:"<<pRspQryRouterInfo->Mask<<std::endl;
  std::cout<<"on pRspQryRouterInfo->Flag:"<<pRspQryRouterInfo->Flag<<std::endl;
  std::cout<<"on pRspQryRouterInfo->RefCnt:"<<pRspQryRouterInfo->RefCnt<<std::endl;
  std::cout<<"on pRspQryRouterInfo->Use:"<<pRspQryRouterInfo->Use<<std::endl;
  std::cout<<"on pRspQryRouterInfo->Metric:"<<pRspQryRouterInfo->Metric<<std::endl;
  std::cout<<"on pRspQryRouterInfo->Mtu:"<<pRspQryRouterInfo->Mtu<<std::endl;
  std::cout<<"on pRspQryRouterInfo->Win:"<<pRspQryRouterInfo->Win<<std::endl;
  std::cout<<"on pRspQryRouterInfo->Rtt:"<<pRspQryRouterInfo->Rtt<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryRouterInfoField* pNewRspQryRouterInfo =new CShfeFtdcRspQryRouterInfoField;
  memcpy(pNewRspQryRouterInfo,pRspQryRouterInfo,sizeof(CShfeFtdcRspQryRouterInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryRouterInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryRouterInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryRouterInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnRouterInfoTopic(CShfeFtdcRtnRouterInfoField *pRtnRouterInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnRouterInfo->HostName:"<<pRtnRouterInfo->HostName<<std::endl;
  std::cout<<"on pRtnRouterInfo->MonDate:"<<pRtnRouterInfo->MonDate<<std::endl;
  std::cout<<"on pRtnRouterInfo->MonTime:"<<pRtnRouterInfo->MonTime<<std::endl;
  std::cout<<"on pRtnRouterInfo->Dev:"<<pRtnRouterInfo->Dev<<std::endl;
  std::cout<<"on pRtnRouterInfo->Destination:"<<pRtnRouterInfo->Destination<<std::endl;
  std::cout<<"on pRtnRouterInfo->Gateway:"<<pRtnRouterInfo->Gateway<<std::endl;
  std::cout<<"on pRtnRouterInfo->Mask:"<<pRtnRouterInfo->Mask<<std::endl;
  std::cout<<"on pRtnRouterInfo->Flag:"<<pRtnRouterInfo->Flag<<std::endl;
  std::cout<<"on pRtnRouterInfo->RefCnt:"<<pRtnRouterInfo->RefCnt<<std::endl;
  std::cout<<"on pRtnRouterInfo->Use:"<<pRtnRouterInfo->Use<<std::endl;
  std::cout<<"on pRtnRouterInfo->Metric:"<<pRtnRouterInfo->Metric<<std::endl;
  std::cout<<"on pRtnRouterInfo->Mtu:"<<pRtnRouterInfo->Mtu<<std::endl;
  std::cout<<"on pRtnRouterInfo->Win:"<<pRtnRouterInfo->Win<<std::endl;
  std::cout<<"on pRtnRouterInfo->Rtt:"<<pRtnRouterInfo->Rtt<<std::endl;
  CShfeFtdcRtnRouterInfoField* pNewRtnRouterInfo =new CShfeFtdcRtnRouterInfoField;
  memcpy(pNewRtnRouterInfo,pRtnRouterInfo,sizeof(CShfeFtdcRtnRouterInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnRouterInfo;
  asyncOnRtnRouterInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnRouterInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryDiskIOTopic(CShfeFtdcRspQryDiskIOField *pRspQryDiskIO, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryDiskIO->HostName:"<<pRspQryDiskIO->HostName<<std::endl;
  std::cout<<"on pRspQryDiskIO->MonDate:"<<pRspQryDiskIO->MonDate<<std::endl;
  std::cout<<"on pRspQryDiskIO->MonTime:"<<pRspQryDiskIO->MonTime<<std::endl;
  std::cout<<"on pRspQryDiskIO->PartName:"<<pRspQryDiskIO->PartName<<std::endl;
  std::cout<<"on pRspQryDiskIO->ReadMerges:"<<pRspQryDiskIO->ReadMerges<<std::endl;
  std::cout<<"on pRspQryDiskIO->WriteMerges:"<<pRspQryDiskIO->WriteMerges<<std::endl;
  std::cout<<"on pRspQryDiskIO->ReadIOs:"<<pRspQryDiskIO->ReadIOs<<std::endl;
  std::cout<<"on pRspQryDiskIO->WriteIOs:"<<pRspQryDiskIO->WriteIOs<<std::endl;
  std::cout<<"on pRspQryDiskIO->ReadKBs:"<<pRspQryDiskIO->ReadKBs<<std::endl;
  std::cout<<"on pRspQryDiskIO->WriteKBs:"<<pRspQryDiskIO->WriteKBs<<std::endl;
  std::cout<<"on pRspQryDiskIO->SizeVal:"<<pRspQryDiskIO->SizeVal<<std::endl;
  std::cout<<"on pRspQryDiskIO->QueueVal:"<<pRspQryDiskIO->QueueVal<<std::endl;
  std::cout<<"on pRspQryDiskIO->Svc_t:"<<pRspQryDiskIO->Svc_t<<std::endl;
  std::cout<<"on pRspQryDiskIO->Busy:"<<pRspQryDiskIO->Busy<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryDiskIOField* pNewRspQryDiskIO =new CShfeFtdcRspQryDiskIOField;
  memcpy(pNewRspQryDiskIO,pRspQryDiskIO,sizeof(CShfeFtdcRspQryDiskIOField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryDiskIO;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryDiskIOTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryDiskIOTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnDiskIOTopic(CShfeFtdcRtnDiskIOField *pRtnDiskIO)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnDiskIO->HostName:"<<pRtnDiskIO->HostName<<std::endl;
  std::cout<<"on pRtnDiskIO->MonDate:"<<pRtnDiskIO->MonDate<<std::endl;
  std::cout<<"on pRtnDiskIO->MonTime:"<<pRtnDiskIO->MonTime<<std::endl;
  std::cout<<"on pRtnDiskIO->PartName:"<<pRtnDiskIO->PartName<<std::endl;
  std::cout<<"on pRtnDiskIO->ReadMerges:"<<pRtnDiskIO->ReadMerges<<std::endl;
  std::cout<<"on pRtnDiskIO->WriteMerges:"<<pRtnDiskIO->WriteMerges<<std::endl;
  std::cout<<"on pRtnDiskIO->ReadIOs:"<<pRtnDiskIO->ReadIOs<<std::endl;
  std::cout<<"on pRtnDiskIO->WriteIOs:"<<pRtnDiskIO->WriteIOs<<std::endl;
  std::cout<<"on pRtnDiskIO->ReadKBs:"<<pRtnDiskIO->ReadKBs<<std::endl;
  std::cout<<"on pRtnDiskIO->WriteKBs:"<<pRtnDiskIO->WriteKBs<<std::endl;
  std::cout<<"on pRtnDiskIO->SizeVal:"<<pRtnDiskIO->SizeVal<<std::endl;
  std::cout<<"on pRtnDiskIO->QueueVal:"<<pRtnDiskIO->QueueVal<<std::endl;
  std::cout<<"on pRtnDiskIO->Svc_t:"<<pRtnDiskIO->Svc_t<<std::endl;
  std::cout<<"on pRtnDiskIO->Busy:"<<pRtnDiskIO->Busy<<std::endl;
  CShfeFtdcRtnDiskIOField* pNewRtnDiskIO =new CShfeFtdcRtnDiskIOField;
  memcpy(pNewRtnDiskIO,pRtnDiskIO,sizeof(CShfeFtdcRtnDiskIOField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnDiskIO;
  asyncOnRtnDiskIOTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnDiskIOTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryStatInfoTopic(CShfeFtdcRspQryStatInfoField *pRspQryStatInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryStatInfo->HostName:"<<pRspQryStatInfo->HostName<<std::endl;
  std::cout<<"on pRspQryStatInfo->MonDate:"<<pRspQryStatInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryStatInfo->MonTime:"<<pRspQryStatInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryStatInfo->ProcRun:"<<pRspQryStatInfo->ProcRun<<std::endl;
  std::cout<<"on pRspQryStatInfo->ProcBlk:"<<pRspQryStatInfo->ProcBlk<<std::endl;
  std::cout<<"on pRspQryStatInfo->SwapIn:"<<pRspQryStatInfo->SwapIn<<std::endl;
  std::cout<<"on pRspQryStatInfo->SwapOut:"<<pRspQryStatInfo->SwapOut<<std::endl;
  std::cout<<"on pRspQryStatInfo->BlockIn:"<<pRspQryStatInfo->BlockIn<<std::endl;
  std::cout<<"on pRspQryStatInfo->BlockOut:"<<pRspQryStatInfo->BlockOut<<std::endl;
  std::cout<<"on pRspQryStatInfo->Inter:"<<pRspQryStatInfo->Inter<<std::endl;
  std::cout<<"on pRspQryStatInfo->Context:"<<pRspQryStatInfo->Context<<std::endl;
  std::cout<<"on pRspQryStatInfo->CPUUser:"<<pRspQryStatInfo->CPUUser<<std::endl;
  std::cout<<"on pRspQryStatInfo->CPUSys:"<<pRspQryStatInfo->CPUSys<<std::endl;
  std::cout<<"on pRspQryStatInfo->CPUIdle:"<<pRspQryStatInfo->CPUIdle<<std::endl;
  std::cout<<"on pRspQryStatInfo->CPUIOWait:"<<pRspQryStatInfo->CPUIOWait<<std::endl;
  std::cout<<"on pRspQryStatInfo->CPUSteal:"<<pRspQryStatInfo->CPUSteal<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryStatInfoField* pNewRspQryStatInfo =new CShfeFtdcRspQryStatInfoField;
  memcpy(pNewRspQryStatInfo,pRspQryStatInfo,sizeof(CShfeFtdcRspQryStatInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryStatInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryStatInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryStatInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnStatInfoTopic(CShfeFtdcRtnStatInfoField *pRtnStatInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnStatInfo->HostName:"<<pRtnStatInfo->HostName<<std::endl;
  std::cout<<"on pRtnStatInfo->MonDate:"<<pRtnStatInfo->MonDate<<std::endl;
  std::cout<<"on pRtnStatInfo->MonTime:"<<pRtnStatInfo->MonTime<<std::endl;
  std::cout<<"on pRtnStatInfo->ProcRun:"<<pRtnStatInfo->ProcRun<<std::endl;
  std::cout<<"on pRtnStatInfo->ProcBlk:"<<pRtnStatInfo->ProcBlk<<std::endl;
  std::cout<<"on pRtnStatInfo->SwapIn:"<<pRtnStatInfo->SwapIn<<std::endl;
  std::cout<<"on pRtnStatInfo->SwapOut:"<<pRtnStatInfo->SwapOut<<std::endl;
  std::cout<<"on pRtnStatInfo->BlockIn:"<<pRtnStatInfo->BlockIn<<std::endl;
  std::cout<<"on pRtnStatInfo->BlockOut:"<<pRtnStatInfo->BlockOut<<std::endl;
  std::cout<<"on pRtnStatInfo->Inter:"<<pRtnStatInfo->Inter<<std::endl;
  std::cout<<"on pRtnStatInfo->Context:"<<pRtnStatInfo->Context<<std::endl;
  std::cout<<"on pRtnStatInfo->CPUUser:"<<pRtnStatInfo->CPUUser<<std::endl;
  std::cout<<"on pRtnStatInfo->CPUSys:"<<pRtnStatInfo->CPUSys<<std::endl;
  std::cout<<"on pRtnStatInfo->CPUIdle:"<<pRtnStatInfo->CPUIdle<<std::endl;
  std::cout<<"on pRtnStatInfo->CPUIOWait:"<<pRtnStatInfo->CPUIOWait<<std::endl;
  std::cout<<"on pRtnStatInfo->CPUSteal:"<<pRtnStatInfo->CPUSteal<<std::endl;
  CShfeFtdcRtnStatInfoField* pNewRtnStatInfo =new CShfeFtdcRtnStatInfoField;
  memcpy(pNewRtnStatInfo,pRtnStatInfo,sizeof(CShfeFtdcRtnStatInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnStatInfo;
  asyncOnRtnStatInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnStatInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryTradeOrderRttCutLineTopic(CShfeFtdcRspQryTradeOrderRttCutLineField *pRspQryTradeOrderRttCutLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryTradeOrderRttCutLine->MonDate:"<<pRspQryTradeOrderRttCutLine->MonDate<<std::endl;
  std::cout<<"on pRspQryTradeOrderRttCutLine->MonTime:"<<pRspQryTradeOrderRttCutLine->MonTime<<std::endl;
  std::cout<<"on pRspQryTradeOrderRttCutLine->UserName:"<<pRspQryTradeOrderRttCutLine->UserName<<std::endl;
  std::cout<<"on pRspQryTradeOrderRttCutLine->OrderRttCutLine:"<<pRspQryTradeOrderRttCutLine->OrderRttCutLine<<std::endl;
  std::cout<<"on pRspQryTradeOrderRttCutLine->OrderRttWidth:"<<pRspQryTradeOrderRttCutLine->OrderRttWidth<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryTradeOrderRttCutLineField* pNewRspQryTradeOrderRttCutLine =new CShfeFtdcRspQryTradeOrderRttCutLineField;
  memcpy(pNewRspQryTradeOrderRttCutLine,pRspQryTradeOrderRttCutLine,sizeof(CShfeFtdcRspQryTradeOrderRttCutLineField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryTradeOrderRttCutLine;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryTradeOrderRttCutLineTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryTradeOrderRttCutLineTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnTradeOrderRttCutLineTopic(CShfeFtdcRtnTradeOrderRttCutLineField *pRtnTradeOrderRttCutLine)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnTradeOrderRttCutLine->MonDate:"<<pRtnTradeOrderRttCutLine->MonDate<<std::endl;
  std::cout<<"on pRtnTradeOrderRttCutLine->OrderRttCutLine:"<<pRtnTradeOrderRttCutLine->OrderRttCutLine<<std::endl;
  CShfeFtdcRtnTradeOrderRttCutLineField* pNewRtnTradeOrderRttCutLine =new CShfeFtdcRtnTradeOrderRttCutLineField;
  memcpy(pNewRtnTradeOrderRttCutLine,pRtnTradeOrderRttCutLine,sizeof(CShfeFtdcRtnTradeOrderRttCutLineField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnTradeOrderRttCutLine;
  asyncOnRtnTradeOrderRttCutLineTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnTradeOrderRttCutLineTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryClientInfoTopic(CShfeFtdcRspQryClientInfoField *pRspQryClientInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryClientInfo->ClientID:"<<pRspQryClientInfo->ClientID<<std::endl;
  std::cout<<"on pRspQryClientInfo->ClientName:"<<pRspQryClientInfo->ClientName<<std::endl;
  std::cout<<"on pRspQryClientInfo->IdentifiedCardType:"<<pRspQryClientInfo->IdentifiedCardType<<std::endl;
  std::cout<<"on pRspQryClientInfo->IdentifiedCardNo:"<<pRspQryClientInfo->IdentifiedCardNo<<std::endl;
  std::cout<<"on pRspQryClientInfo->TradingRole:"<<pRspQryClientInfo->TradingRole<<std::endl;
  std::cout<<"on pRspQryClientInfo->ClientType:"<<pRspQryClientInfo->ClientType<<std::endl;
  std::cout<<"on pRspQryClientInfo->IsActive:"<<pRspQryClientInfo->IsActive<<std::endl;
  std::cout<<"on pRspQryClientInfo->OperationType:"<<pRspQryClientInfo->OperationType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryClientInfoField* pNewRspQryClientInfo =new CShfeFtdcRspQryClientInfoField;
  memcpy(pNewRspQryClientInfo,pRspQryClientInfo,sizeof(CShfeFtdcRspQryClientInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryClientInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryClientInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryClientInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnClientInfoTopic(CShfeFtdcRtnClientInfoField *pRtnClientInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnClientInfo->ClientID:"<<pRtnClientInfo->ClientID<<std::endl;
  std::cout<<"on pRtnClientInfo->ClientName:"<<pRtnClientInfo->ClientName<<std::endl;
  std::cout<<"on pRtnClientInfo->IdentifiedCardType:"<<pRtnClientInfo->IdentifiedCardType<<std::endl;
  std::cout<<"on pRtnClientInfo->IdentifiedCardNo:"<<pRtnClientInfo->IdentifiedCardNo<<std::endl;
  std::cout<<"on pRtnClientInfo->TradingRole:"<<pRtnClientInfo->TradingRole<<std::endl;
  std::cout<<"on pRtnClientInfo->ClientType:"<<pRtnClientInfo->ClientType<<std::endl;
  std::cout<<"on pRtnClientInfo->IsActive:"<<pRtnClientInfo->IsActive<<std::endl;
  std::cout<<"on pRtnClientInfo->OperationType:"<<pRtnClientInfo->OperationType<<std::endl;
  CShfeFtdcRtnClientInfoField* pNewRtnClientInfo =new CShfeFtdcRtnClientInfoField;
  memcpy(pNewRtnClientInfo,pRtnClientInfo,sizeof(CShfeFtdcRtnClientInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnClientInfo;
  asyncOnRtnClientInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnClientInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryEventDescriptionTopic(CShfeFtdcRspQryEventDescriptionField *pRspQryEventDescription, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryEventDescription->EventDesID:"<<pRspQryEventDescription->EventDesID<<std::endl;
  std::cout<<"on pRspQryEventDescription->UserName:"<<pRspQryEventDescription->UserName<<std::endl;
  std::cout<<"on pRspQryEventDescription->MonDate:"<<pRspQryEventDescription->MonDate<<std::endl;
  std::cout<<"on pRspQryEventDescription->MonTime:"<<pRspQryEventDescription->MonTime<<std::endl;
  std::cout<<"on pRspQryEventDescription->EventDes:"<<pRspQryEventDescription->EventDes<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryEventDescriptionField* pNewRspQryEventDescription =new CShfeFtdcRspQryEventDescriptionField;
  memcpy(pNewRspQryEventDescription,pRspQryEventDescription,sizeof(CShfeFtdcRspQryEventDescriptionField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryEventDescription;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryEventDescriptionTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryEventDescriptionTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnEventDescriptionTopic(CShfeFtdcRtnEventDescriptionField *pRtnEventDescription)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnEventDescription->EventDesID:"<<pRtnEventDescription->EventDesID<<std::endl;
  std::cout<<"on pRtnEventDescription->UserName:"<<pRtnEventDescription->UserName<<std::endl;
  std::cout<<"on pRtnEventDescription->MonDate:"<<pRtnEventDescription->MonDate<<std::endl;
  std::cout<<"on pRtnEventDescription->MonTime:"<<pRtnEventDescription->MonTime<<std::endl;
  std::cout<<"on pRtnEventDescription->EventDes:"<<pRtnEventDescription->EventDes<<std::endl;
  CShfeFtdcRtnEventDescriptionField* pNewRtnEventDescription =new CShfeFtdcRtnEventDescriptionField;
  memcpy(pNewRtnEventDescription,pRtnEventDescription,sizeof(CShfeFtdcRtnEventDescriptionField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnEventDescription;
  asyncOnRtnEventDescriptionTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnEventDescriptionTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryFrontUniqueIDTopic(CShfeFtdcRspQryFrontUniqueIDField *pRspQryFrontUniqueID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryFrontUniqueID->FrontID:"<<pRspQryFrontUniqueID->FrontID<<std::endl;
  std::cout<<"on pRspQryFrontUniqueID->FrontName:"<<pRspQryFrontUniqueID->FrontName<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryFrontUniqueIDField* pNewRspQryFrontUniqueID =new CShfeFtdcRspQryFrontUniqueIDField;
  memcpy(pNewRspQryFrontUniqueID,pRspQryFrontUniqueID,sizeof(CShfeFtdcRspQryFrontUniqueIDField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryFrontUniqueID;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryFrontUniqueIDTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryFrontUniqueIDTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnFrontUniqueIDTopic(CShfeFtdcRtnFrontUniqueIDField *pRtnFrontUniqueID)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnFrontUniqueID->FrontID:"<<pRtnFrontUniqueID->FrontID<<std::endl;
  std::cout<<"on pRtnFrontUniqueID->FrontName:"<<pRtnFrontUniqueID->FrontName<<std::endl;
  CShfeFtdcRtnFrontUniqueIDField* pNewRtnFrontUniqueID =new CShfeFtdcRtnFrontUniqueIDField;
  memcpy(pNewRtnFrontUniqueID,pRtnFrontUniqueID,sizeof(CShfeFtdcRtnFrontUniqueIDField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnFrontUniqueID;
  asyncOnRtnFrontUniqueIDTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnFrontUniqueIDTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetPartyLinkAddrChangeTopic(CShfeFtdcRspQryNetPartyLinkAddrChangeField *pRspQryNetPartyLinkAddrChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkAddrChange->OperationType:"<<pRspQryNetPartyLinkAddrChange->OperationType<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkAddrChange->ID:"<<pRspQryNetPartyLinkAddrChange->ID<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkAddrChange->RelationID:"<<pRspQryNetPartyLinkAddrChange->RelationID<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkAddrChange->OLDADDRESS:"<<pRspQryNetPartyLinkAddrChange->OLDADDRESS<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkAddrChange->NEWADDRESS:"<<pRspQryNetPartyLinkAddrChange->NEWADDRESS<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkAddrChange->OPERATOR:"<<pRspQryNetPartyLinkAddrChange->OPERATOR<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkAddrChange->MonDate:"<<pRspQryNetPartyLinkAddrChange->MonDate<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkAddrChange->MonTime:"<<pRspQryNetPartyLinkAddrChange->MonTime<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetPartyLinkAddrChangeField* pNewRspQryNetPartyLinkAddrChange =new CShfeFtdcRspQryNetPartyLinkAddrChangeField;
  memcpy(pNewRspQryNetPartyLinkAddrChange,pRspQryNetPartyLinkAddrChange,sizeof(CShfeFtdcRspQryNetPartyLinkAddrChangeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetPartyLinkAddrChange;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetPartyLinkAddrChangeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetPartyLinkAddrChangeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetPartyLinkAddrChangeTopic(CShfeFtdcRtnNetPartyLinkAddrChangeField *pRtnNetPartyLinkAddrChange)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetPartyLinkAddrChange->OperationType:"<<pRtnNetPartyLinkAddrChange->OperationType<<std::endl;
  std::cout<<"on pRtnNetPartyLinkAddrChange->ID:"<<pRtnNetPartyLinkAddrChange->ID<<std::endl;
  std::cout<<"on pRtnNetPartyLinkAddrChange->RelationID:"<<pRtnNetPartyLinkAddrChange->RelationID<<std::endl;
  std::cout<<"on pRtnNetPartyLinkAddrChange->OLDADDRESS:"<<pRtnNetPartyLinkAddrChange->OLDADDRESS<<std::endl;
  std::cout<<"on pRtnNetPartyLinkAddrChange->NEWADDRESS:"<<pRtnNetPartyLinkAddrChange->NEWADDRESS<<std::endl;
  std::cout<<"on pRtnNetPartyLinkAddrChange->OPERATOR:"<<pRtnNetPartyLinkAddrChange->OPERATOR<<std::endl;
  std::cout<<"on pRtnNetPartyLinkAddrChange->MonDate:"<<pRtnNetPartyLinkAddrChange->MonDate<<std::endl;
  std::cout<<"on pRtnNetPartyLinkAddrChange->MonTime:"<<pRtnNetPartyLinkAddrChange->MonTime<<std::endl;
  CShfeFtdcRtnNetPartyLinkAddrChangeField* pNewRtnNetPartyLinkAddrChange =new CShfeFtdcRtnNetPartyLinkAddrChangeField;
  memcpy(pNewRtnNetPartyLinkAddrChange,pRtnNetPartyLinkAddrChange,sizeof(CShfeFtdcRtnNetPartyLinkAddrChangeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetPartyLinkAddrChange;
  asyncOnRtnNetPartyLinkAddrChangeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetPartyLinkAddrChangeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetDelPartyLinkInfoTopic(CShfeFtdcRspQryNetDelPartyLinkInfoField *pRspQryNetDelPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->OperationType:"<<pRspQryNetDelPartyLinkInfo->OperationType<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->ID:"<<pRspQryNetDelPartyLinkInfo->ID<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->MEMBER_NO:"<<pRspQryNetDelPartyLinkInfo->MEMBER_NO<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->MEMBER_NAME:"<<pRspQryNetDelPartyLinkInfo->MEMBER_NAME<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->REMOTE_ADDR:"<<pRspQryNetDelPartyLinkInfo->REMOTE_ADDR<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->LOCAL_ADDR:"<<pRspQryNetDelPartyLinkInfo->LOCAL_ADDR<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->ADDRESS:"<<pRspQryNetDelPartyLinkInfo->ADDRESS<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->LINE_STATUS:"<<pRspQryNetDelPartyLinkInfo->LINE_STATUS<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->CONTACT:"<<pRspQryNetDelPartyLinkInfo->CONTACT<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->TELEPHONE:"<<pRspQryNetDelPartyLinkInfo->TELEPHONE<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->MOBILEPHONE:"<<pRspQryNetDelPartyLinkInfo->MOBILEPHONE<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->EMAIL:"<<pRspQryNetDelPartyLinkInfo->EMAIL<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->FAX:"<<pRspQryNetDelPartyLinkInfo->FAX<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->PROVINCE:"<<pRspQryNetDelPartyLinkInfo->PROVINCE<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->DDN_NO:"<<pRspQryNetDelPartyLinkInfo->DDN_NO<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->IN_MODE:"<<pRspQryNetDelPartyLinkInfo->IN_MODE<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->IP_WAN:"<<pRspQryNetDelPartyLinkInfo->IP_WAN<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->IP_LAN:"<<pRspQryNetDelPartyLinkInfo->IP_LAN<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->IPADDR:"<<pRspQryNetDelPartyLinkInfo->IPADDR<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->Interface:"<<pRspQryNetDelPartyLinkInfo->Interface<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->INTERFACE_DATE:"<<pRspQryNetDelPartyLinkInfo->INTERFACE_DATE<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->SOFTWARE:"<<pRspQryNetDelPartyLinkInfo->SOFTWARE<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->FEE_TYPE:"<<pRspQryNetDelPartyLinkInfo->FEE_TYPE<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->SERVICEPROVIDER:"<<pRspQryNetDelPartyLinkInfo->SERVICEPROVIDER<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->IF_ZIYING:"<<pRspQryNetDelPartyLinkInfo->IF_ZIYING<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->IF_TUOGUAN:"<<pRspQryNetDelPartyLinkInfo->IF_TUOGUAN<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->HASOTHER:"<<pRspQryNetDelPartyLinkInfo->HASOTHER<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->SEAT_NO:"<<pRspQryNetDelPartyLinkInfo->SEAT_NO<<std::endl;
  std::cout<<"on pRspQryNetDelPartyLinkInfo->PRO:"<<pRspQryNetDelPartyLinkInfo->PRO<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetDelPartyLinkInfoField* pNewRspQryNetDelPartyLinkInfo =new CShfeFtdcRspQryNetDelPartyLinkInfoField;
  memcpy(pNewRspQryNetDelPartyLinkInfo,pRspQryNetDelPartyLinkInfo,sizeof(CShfeFtdcRspQryNetDelPartyLinkInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetDelPartyLinkInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetDelPartyLinkInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetDelPartyLinkInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetDelPartyLinkInfoTopic(CShfeFtdcRtnNetDelPartyLinkInfoField *pRtnNetDelPartyLinkInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->OperationType:"<<pRtnNetDelPartyLinkInfo->OperationType<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->ID:"<<pRtnNetDelPartyLinkInfo->ID<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->MEMBER_NO:"<<pRtnNetDelPartyLinkInfo->MEMBER_NO<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->MEMBER_NAME:"<<pRtnNetDelPartyLinkInfo->MEMBER_NAME<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->REMOTE_ADDR:"<<pRtnNetDelPartyLinkInfo->REMOTE_ADDR<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->LOCAL_ADDR:"<<pRtnNetDelPartyLinkInfo->LOCAL_ADDR<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->ADDRESS:"<<pRtnNetDelPartyLinkInfo->ADDRESS<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->LINE_STATUS:"<<pRtnNetDelPartyLinkInfo->LINE_STATUS<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->CONTACT:"<<pRtnNetDelPartyLinkInfo->CONTACT<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->TELEPHONE:"<<pRtnNetDelPartyLinkInfo->TELEPHONE<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->MOBILEPHONE:"<<pRtnNetDelPartyLinkInfo->MOBILEPHONE<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->EMAIL:"<<pRtnNetDelPartyLinkInfo->EMAIL<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->FAX:"<<pRtnNetDelPartyLinkInfo->FAX<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->PROVINCE:"<<pRtnNetDelPartyLinkInfo->PROVINCE<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->DDN_NO:"<<pRtnNetDelPartyLinkInfo->DDN_NO<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->IN_MODE:"<<pRtnNetDelPartyLinkInfo->IN_MODE<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->IP_WAN:"<<pRtnNetDelPartyLinkInfo->IP_WAN<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->IP_LAN:"<<pRtnNetDelPartyLinkInfo->IP_LAN<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->IPADDR:"<<pRtnNetDelPartyLinkInfo->IPADDR<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->Interface:"<<pRtnNetDelPartyLinkInfo->Interface<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->INTERFACE_DATE:"<<pRtnNetDelPartyLinkInfo->INTERFACE_DATE<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->SOFTWARE:"<<pRtnNetDelPartyLinkInfo->SOFTWARE<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->FEE_TYPE:"<<pRtnNetDelPartyLinkInfo->FEE_TYPE<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->SERVICEPROVIDER:"<<pRtnNetDelPartyLinkInfo->SERVICEPROVIDER<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->IF_ZIYING:"<<pRtnNetDelPartyLinkInfo->IF_ZIYING<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->IF_TUOGUAN:"<<pRtnNetDelPartyLinkInfo->IF_TUOGUAN<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->HASOTHER:"<<pRtnNetDelPartyLinkInfo->HASOTHER<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->SEAT_NO:"<<pRtnNetDelPartyLinkInfo->SEAT_NO<<std::endl;
  std::cout<<"on pRtnNetDelPartyLinkInfo->PRO:"<<pRtnNetDelPartyLinkInfo->PRO<<std::endl;
  CShfeFtdcRtnNetDelPartyLinkInfoField* pNewRtnNetDelPartyLinkInfo =new CShfeFtdcRtnNetDelPartyLinkInfoField;
  memcpy(pNewRtnNetDelPartyLinkInfo,pRtnNetDelPartyLinkInfo,sizeof(CShfeFtdcRtnNetDelPartyLinkInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetDelPartyLinkInfo;
  asyncOnRtnNetDelPartyLinkInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetDelPartyLinkInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryPerformanceTopTopic(CShfeFtdcRspQryPerformanceTopField *pRspQryPerformanceTop, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryPerformanceTop->OperationType:"<<pRspQryPerformanceTop->OperationType<<std::endl;
  std::cout<<"on pRspQryPerformanceTop->AttrType:"<<pRspQryPerformanceTop->AttrType<<std::endl;
  std::cout<<"on pRspQryPerformanceTop->NetArea:"<<pRspQryPerformanceTop->NetArea<<std::endl;
  std::cout<<"on pRspQryPerformanceTop->NetSubArea:"<<pRspQryPerformanceTop->NetSubArea<<std::endl;
  std::cout<<"on pRspQryPerformanceTop->KeyWord:"<<pRspQryPerformanceTop->KeyWord<<std::endl;
  std::cout<<"on pRspQryPerformanceTop->SortValue:"<<pRspQryPerformanceTop->SortValue<<std::endl;
  std::cout<<"on pRspQryPerformanceTop->SortType:"<<pRspQryPerformanceTop->SortType<<std::endl;
  std::cout<<"on pRspQryPerformanceTop->DuringTimeType:"<<pRspQryPerformanceTop->DuringTimeType<<std::endl;
  std::cout<<"on pRspQryPerformanceTop->DuringTimeValue:"<<pRspQryPerformanceTop->DuringTimeValue<<std::endl;
  std::cout<<"on pRspQryPerformanceTop->TopN:"<<pRspQryPerformanceTop->TopN<<std::endl;
  std::cout<<"on pRspQryPerformanceTop->TopResult:"<<pRspQryPerformanceTop->TopResult<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryPerformanceTopField* pNewRspQryPerformanceTop =new CShfeFtdcRspQryPerformanceTopField;
  memcpy(pNewRspQryPerformanceTop,pRspQryPerformanceTop,sizeof(CShfeFtdcRspQryPerformanceTopField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryPerformanceTop;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryPerformanceTopTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryPerformanceTopTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnPerformanceTopTopic(CShfeFtdcRtnPerformanceTopField *pRtnPerformanceTop)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnPerformanceTop->OperationType:"<<pRtnPerformanceTop->OperationType<<std::endl;
  std::cout<<"on pRtnPerformanceTop->AttrType:"<<pRtnPerformanceTop->AttrType<<std::endl;
  std::cout<<"on pRtnPerformanceTop->NetArea:"<<pRtnPerformanceTop->NetArea<<std::endl;
  std::cout<<"on pRtnPerformanceTop->NetSubArea:"<<pRtnPerformanceTop->NetSubArea<<std::endl;
  std::cout<<"on pRtnPerformanceTop->KeyWord:"<<pRtnPerformanceTop->KeyWord<<std::endl;
  std::cout<<"on pRtnPerformanceTop->SortValue:"<<pRtnPerformanceTop->SortValue<<std::endl;
  std::cout<<"on pRtnPerformanceTop->SortType:"<<pRtnPerformanceTop->SortType<<std::endl;
  std::cout<<"on pRtnPerformanceTop->DuringTimeType:"<<pRtnPerformanceTop->DuringTimeType<<std::endl;
  std::cout<<"on pRtnPerformanceTop->DuringTimeValue:"<<pRtnPerformanceTop->DuringTimeValue<<std::endl;
  std::cout<<"on pRtnPerformanceTop->TopN:"<<pRtnPerformanceTop->TopN<<std::endl;
  std::cout<<"on pRtnPerformanceTop->TopResult:"<<pRtnPerformanceTop->TopResult<<std::endl;
  CShfeFtdcRtnPerformanceTopField* pNewRtnPerformanceTop =new CShfeFtdcRtnPerformanceTopField;
  memcpy(pNewRtnPerformanceTop,pRtnPerformanceTop,sizeof(CShfeFtdcRtnPerformanceTopField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnPerformanceTop;
  asyncOnRtnPerformanceTopTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnPerformanceTopTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryInstrumentStatusTopic(CShfeFtdcRspQryInstrumentStatusField *pRspQryInstrumentStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryInstrumentStatus->SettlementGroupID:"<<pRspQryInstrumentStatus->SettlementGroupID<<std::endl;
  std::cout<<"on pRspQryInstrumentStatus->InstrumentID:"<<pRspQryInstrumentStatus->InstrumentID<<std::endl;
  std::cout<<"on pRspQryInstrumentStatus->InstrumentStatus:"<<pRspQryInstrumentStatus->InstrumentStatus<<std::endl;
  std::cout<<"on pRspQryInstrumentStatus->TradingSegmentSN:"<<pRspQryInstrumentStatus->TradingSegmentSN<<std::endl;
  std::cout<<"on pRspQryInstrumentStatus->EnterTime:"<<pRspQryInstrumentStatus->EnterTime<<std::endl;
  std::cout<<"on pRspQryInstrumentStatus->EnterReason:"<<pRspQryInstrumentStatus->EnterReason<<std::endl;
  std::cout<<"on pRspQryInstrumentStatus->EnterDate:"<<pRspQryInstrumentStatus->EnterDate<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryInstrumentStatusField* pNewRspQryInstrumentStatus =new CShfeFtdcRspQryInstrumentStatusField;
  memcpy(pNewRspQryInstrumentStatus,pRspQryInstrumentStatus,sizeof(CShfeFtdcRspQryInstrumentStatusField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryInstrumentStatus;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryInstrumentStatusTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryInstrumentStatusTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnInstrumentStatusTopic(CShfeFtdcRtnInstrumentStatusField *pRtnInstrumentStatus)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnInstrumentStatus->SettlementGroupID:"<<pRtnInstrumentStatus->SettlementGroupID<<std::endl;
  std::cout<<"on pRtnInstrumentStatus->InstrumentID:"<<pRtnInstrumentStatus->InstrumentID<<std::endl;
  std::cout<<"on pRtnInstrumentStatus->InstrumentStatus:"<<pRtnInstrumentStatus->InstrumentStatus<<std::endl;
  std::cout<<"on pRtnInstrumentStatus->TradingSegmentSN:"<<pRtnInstrumentStatus->TradingSegmentSN<<std::endl;
  std::cout<<"on pRtnInstrumentStatus->EnterTime:"<<pRtnInstrumentStatus->EnterTime<<std::endl;
  std::cout<<"on pRtnInstrumentStatus->EnterReason:"<<pRtnInstrumentStatus->EnterReason<<std::endl;
  std::cout<<"on pRtnInstrumentStatus->EnterDate:"<<pRtnInstrumentStatus->EnterDate<<std::endl;
  CShfeFtdcRtnInstrumentStatusField* pNewRtnInstrumentStatus =new CShfeFtdcRtnInstrumentStatusField;
  memcpy(pNewRtnInstrumentStatus,pRtnInstrumentStatus,sizeof(CShfeFtdcRtnInstrumentStatusField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnInstrumentStatus;
  asyncOnRtnInstrumentStatusTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnInstrumentStatusTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryCurrTradingSegmentAttrTopic(CShfeFtdcRspQryCurrTradingSegmentAttrField *pRspQryCurrTradingSegmentAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryCurrTradingSegmentAttr->SettlementGroupID:"<<pRspQryCurrTradingSegmentAttr->SettlementGroupID<<std::endl;
  std::cout<<"on pRspQryCurrTradingSegmentAttr->TradingSegmentSN:"<<pRspQryCurrTradingSegmentAttr->TradingSegmentSN<<std::endl;
  std::cout<<"on pRspQryCurrTradingSegmentAttr->TradingSegmentName:"<<pRspQryCurrTradingSegmentAttr->TradingSegmentName<<std::endl;
  std::cout<<"on pRspQryCurrTradingSegmentAttr->StartTime:"<<pRspQryCurrTradingSegmentAttr->StartTime<<std::endl;
  std::cout<<"on pRspQryCurrTradingSegmentAttr->InstrumentStatus:"<<pRspQryCurrTradingSegmentAttr->InstrumentStatus<<std::endl;
  std::cout<<"on pRspQryCurrTradingSegmentAttr->InstrumentID:"<<pRspQryCurrTradingSegmentAttr->InstrumentID<<std::endl;
  std::cout<<"on pRspQryCurrTradingSegmentAttr->AdvanceDays:"<<pRspQryCurrTradingSegmentAttr->AdvanceDays<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryCurrTradingSegmentAttrField* pNewRspQryCurrTradingSegmentAttr =new CShfeFtdcRspQryCurrTradingSegmentAttrField;
  memcpy(pNewRspQryCurrTradingSegmentAttr,pRspQryCurrTradingSegmentAttr,sizeof(CShfeFtdcRspQryCurrTradingSegmentAttrField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryCurrTradingSegmentAttr;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryCurrTradingSegmentAttrTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryCurrTradingSegmentAttrTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnCurrTradingSegmentAttrTopic(CShfeFtdcRtnCurrTradingSegmentAttrField *pRtnCurrTradingSegmentAttr)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnCurrTradingSegmentAttr->SettlementGroupID:"<<pRtnCurrTradingSegmentAttr->SettlementGroupID<<std::endl;
  std::cout<<"on pRtnCurrTradingSegmentAttr->TradingSegmentSN:"<<pRtnCurrTradingSegmentAttr->TradingSegmentSN<<std::endl;
  std::cout<<"on pRtnCurrTradingSegmentAttr->TradingSegmentName:"<<pRtnCurrTradingSegmentAttr->TradingSegmentName<<std::endl;
  std::cout<<"on pRtnCurrTradingSegmentAttr->StartTime:"<<pRtnCurrTradingSegmentAttr->StartTime<<std::endl;
  std::cout<<"on pRtnCurrTradingSegmentAttr->InstrumentStatus:"<<pRtnCurrTradingSegmentAttr->InstrumentStatus<<std::endl;
  std::cout<<"on pRtnCurrTradingSegmentAttr->InstrumentID:"<<pRtnCurrTradingSegmentAttr->InstrumentID<<std::endl;
  std::cout<<"on pRtnCurrTradingSegmentAttr->AdvanceDays:"<<pRtnCurrTradingSegmentAttr->AdvanceDays<<std::endl;
  CShfeFtdcRtnCurrTradingSegmentAttrField* pNewRtnCurrTradingSegmentAttr =new CShfeFtdcRtnCurrTradingSegmentAttrField;
  memcpy(pNewRtnCurrTradingSegmentAttr,pRtnCurrTradingSegmentAttr,sizeof(CShfeFtdcRtnCurrTradingSegmentAttrField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnCurrTradingSegmentAttr;
  asyncOnRtnCurrTradingSegmentAttrTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnCurrTradingSegmentAttrTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetAreaTopic(CShfeFtdcRspQryNetAreaField *pRspQryNetArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetArea->OperationType:"<<pRspQryNetArea->OperationType<<std::endl;
  std::cout<<"on pRspQryNetArea->ID:"<<pRspQryNetArea->ID<<std::endl;
  std::cout<<"on pRspQryNetArea->CName:"<<pRspQryNetArea->CName<<std::endl;
  std::cout<<"on pRspQryNetArea->EName:"<<pRspQryNetArea->EName<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetAreaField* pNewRspQryNetArea =new CShfeFtdcRspQryNetAreaField;
  memcpy(pNewRspQryNetArea,pRspQryNetArea,sizeof(CShfeFtdcRspQryNetAreaField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetArea;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetAreaTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetAreaTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetAreaTopic(CShfeFtdcRtnNetAreaField *pRtnNetArea)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetArea->OperationType:"<<pRtnNetArea->OperationType<<std::endl;
  std::cout<<"on pRtnNetArea->ID:"<<pRtnNetArea->ID<<std::endl;
  std::cout<<"on pRtnNetArea->CName:"<<pRtnNetArea->CName<<std::endl;
  std::cout<<"on pRtnNetArea->EName:"<<pRtnNetArea->EName<<std::endl;
  CShfeFtdcRtnNetAreaField* pNewRtnNetArea =new CShfeFtdcRtnNetAreaField;
  memcpy(pNewRtnNetArea,pRtnNetArea,sizeof(CShfeFtdcRtnNetAreaField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetArea;
  asyncOnRtnNetAreaTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetAreaTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetSubAreaTopic(CShfeFtdcRspQryNetSubAreaField *pRspQryNetSubArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetSubArea->OperationType:"<<pRspQryNetSubArea->OperationType<<std::endl;
  std::cout<<"on pRspQryNetSubArea->ID:"<<pRspQryNetSubArea->ID<<std::endl;
  std::cout<<"on pRspQryNetSubArea->SysNetAreaID:"<<pRspQryNetSubArea->SysNetAreaID<<std::endl;
  std::cout<<"on pRspQryNetSubArea->CName:"<<pRspQryNetSubArea->CName<<std::endl;
  std::cout<<"on pRspQryNetSubArea->EName:"<<pRspQryNetSubArea->EName<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetSubAreaField* pNewRspQryNetSubArea =new CShfeFtdcRspQryNetSubAreaField;
  memcpy(pNewRspQryNetSubArea,pRspQryNetSubArea,sizeof(CShfeFtdcRspQryNetSubAreaField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetSubArea;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetSubAreaTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetSubAreaTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetSubAreaTopic(CShfeFtdcRtnNetSubAreaField *pRtnNetSubArea)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetSubArea->OperationType:"<<pRtnNetSubArea->OperationType<<std::endl;
  std::cout<<"on pRtnNetSubArea->ID:"<<pRtnNetSubArea->ID<<std::endl;
  std::cout<<"on pRtnNetSubArea->SysNetAreaID:"<<pRtnNetSubArea->SysNetAreaID<<std::endl;
  std::cout<<"on pRtnNetSubArea->CName:"<<pRtnNetSubArea->CName<<std::endl;
  std::cout<<"on pRtnNetSubArea->EName:"<<pRtnNetSubArea->EName<<std::endl;
  CShfeFtdcRtnNetSubAreaField* pNewRtnNetSubArea =new CShfeFtdcRtnNetSubAreaField;
  memcpy(pNewRtnNetSubArea,pRtnNetSubArea,sizeof(CShfeFtdcRtnNetSubAreaField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetSubArea;
  asyncOnRtnNetSubAreaTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetSubAreaTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetSubAreaIPTopic(CShfeFtdcRspQryNetSubAreaIPField *pRspQryNetSubAreaIP, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetSubAreaIP->OperationType:"<<pRspQryNetSubAreaIP->OperationType<<std::endl;
  std::cout<<"on pRspQryNetSubAreaIP->ID:"<<pRspQryNetSubAreaIP->ID<<std::endl;
  std::cout<<"on pRspQryNetSubAreaIP->SysNetSubAreaID:"<<pRspQryNetSubAreaIP->SysNetSubAreaID<<std::endl;
  std::cout<<"on pRspQryNetSubAreaIP->IP:"<<pRspQryNetSubAreaIP->IP<<std::endl;
  std::cout<<"on pRspQryNetSubAreaIP->Mask:"<<pRspQryNetSubAreaIP->Mask<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetSubAreaIPField* pNewRspQryNetSubAreaIP =new CShfeFtdcRspQryNetSubAreaIPField;
  memcpy(pNewRspQryNetSubAreaIP,pRspQryNetSubAreaIP,sizeof(CShfeFtdcRspQryNetSubAreaIPField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetSubAreaIP;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetSubAreaIPTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetSubAreaIPTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetSubAreaIPTopic(CShfeFtdcRtnNetSubAreaIPField *pRtnNetSubAreaIP)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetSubAreaIP->OperationType:"<<pRtnNetSubAreaIP->OperationType<<std::endl;
  std::cout<<"on pRtnNetSubAreaIP->ID:"<<pRtnNetSubAreaIP->ID<<std::endl;
  std::cout<<"on pRtnNetSubAreaIP->SysNetSubAreaID:"<<pRtnNetSubAreaIP->SysNetSubAreaID<<std::endl;
  std::cout<<"on pRtnNetSubAreaIP->IP:"<<pRtnNetSubAreaIP->IP<<std::endl;
  std::cout<<"on pRtnNetSubAreaIP->Mask:"<<pRtnNetSubAreaIP->Mask<<std::endl;
  CShfeFtdcRtnNetSubAreaIPField* pNewRtnNetSubAreaIP =new CShfeFtdcRtnNetSubAreaIPField;
  memcpy(pNewRtnNetSubAreaIP,pRtnNetSubAreaIP,sizeof(CShfeFtdcRtnNetSubAreaIPField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetSubAreaIP;
  asyncOnRtnNetSubAreaIPTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetSubAreaIPTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetDeviceTopic(CShfeFtdcRspQryNetDeviceField *pRspQryNetDevice, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetDevice->OperationType:"<<pRspQryNetDevice->OperationType<<std::endl;
  std::cout<<"on pRspQryNetDevice->ID:"<<pRspQryNetDevice->ID<<std::endl;
  std::cout<<"on pRspQryNetDevice->ObjectID:"<<pRspQryNetDevice->ObjectID<<std::endl;
  std::cout<<"on pRspQryNetDevice->MonitorType_ID:"<<pRspQryNetDevice->MonitorType_ID<<std::endl;
  std::cout<<"on pRspQryNetDevice->SysNetSubAreaID:"<<pRspQryNetDevice->SysNetSubAreaID<<std::endl;
  std::cout<<"on pRspQryNetDevice->CATEGORY_ID:"<<pRspQryNetDevice->CATEGORY_ID<<std::endl;
  std::cout<<"on pRspQryNetDevice->FuctionArea:"<<pRspQryNetDevice->FuctionArea<<std::endl;
  std::cout<<"on pRspQryNetDevice->IPADDR:"<<pRspQryNetDevice->IPADDR<<std::endl;
  std::cout<<"on pRspQryNetDevice->IPDECODE:"<<pRspQryNetDevice->IPDECODE<<std::endl;
  std::cout<<"on pRspQryNetDevice->NAME:"<<pRspQryNetDevice->NAME<<std::endl;
  std::cout<<"on pRspQryNetDevice->PORTNUMBER:"<<pRspQryNetDevice->PORTNUMBER<<std::endl;
  std::cout<<"on pRspQryNetDevice->CONFIGFILE:"<<pRspQryNetDevice->CONFIGFILE<<std::endl;
  std::cout<<"on pRspQryNetDevice->RCOMMUNITY:"<<pRspQryNetDevice->RCOMMUNITY<<std::endl;
  std::cout<<"on pRspQryNetDevice->SNMPVERSION:"<<pRspQryNetDevice->SNMPVERSION<<std::endl;
  std::cout<<"on pRspQryNetDevice->RAMSIZE:"<<pRspQryNetDevice->RAMSIZE<<std::endl;
  std::cout<<"on pRspQryNetDevice->FLASHSIZE:"<<pRspQryNetDevice->FLASHSIZE<<std::endl;
  std::cout<<"on pRspQryNetDevice->NVRAMSIZE:"<<pRspQryNetDevice->NVRAMSIZE<<std::endl;
  std::cout<<"on pRspQryNetDevice->CABINET_ID:"<<pRspQryNetDevice->CABINET_ID<<std::endl;
  std::cout<<"on pRspQryNetDevice->ROOM_ID:"<<pRspQryNetDevice->ROOM_ID<<std::endl;
  std::cout<<"on pRspQryNetDevice->IOSVERSION_ID:"<<pRspQryNetDevice->IOSVERSION_ID<<std::endl;
  std::cout<<"on pRspQryNetDevice->DESCRIPTION:"<<pRspQryNetDevice->DESCRIPTION<<std::endl;
  std::cout<<"on pRspQryNetDevice->USERNAME:"<<pRspQryNetDevice->USERNAME<<std::endl;
  std::cout<<"on pRspQryNetDevice->PASSWD:"<<pRspQryNetDevice->PASSWD<<std::endl;
  std::cout<<"on pRspQryNetDevice->ENPASSWD:"<<pRspQryNetDevice->ENPASSWD<<std::endl;
  std::cout<<"on pRspQryNetDevice->MANUFACTORY_ID:"<<pRspQryNetDevice->MANUFACTORY_ID<<std::endl;
  std::cout<<"on pRspQryNetDevice->CFGSAVETYPE:"<<pRspQryNetDevice->CFGSAVETYPE<<std::endl;
  std::cout<<"on pRspQryNetDevice->DEVICETYPE:"<<pRspQryNetDevice->DEVICETYPE<<std::endl;
  std::cout<<"on pRspQryNetDevice->SENDSMS:"<<pRspQryNetDevice->SENDSMS<<std::endl;
  std::cout<<"on pRspQryNetDevice->ISSNMP:"<<pRspQryNetDevice->ISSNMP<<std::endl;
  std::cout<<"on pRspQryNetDevice->SLOTNUM:"<<pRspQryNetDevice->SLOTNUM<<std::endl;
  std::cout<<"on pRspQryNetDevice->ISPING:"<<pRspQryNetDevice->ISPING<<std::endl;
  std::cout<<"on pRspQryNetDevice->IFNUM:"<<pRspQryNetDevice->IFNUM<<std::endl;
  std::cout<<"on pRspQryNetDevice->APPLICATION_ID:"<<pRspQryNetDevice->APPLICATION_ID<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetDeviceField* pNewRspQryNetDevice =new CShfeFtdcRspQryNetDeviceField;
  memcpy(pNewRspQryNetDevice,pRspQryNetDevice,sizeof(CShfeFtdcRspQryNetDeviceField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetDevice;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetDeviceTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetDeviceTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetDeviceTopic(CShfeFtdcRtnNetDeviceField *pRtnNetDevice)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetDevice->OperationType:"<<pRtnNetDevice->OperationType<<std::endl;
  std::cout<<"on pRtnNetDevice->ID:"<<pRtnNetDevice->ID<<std::endl;
  std::cout<<"on pRtnNetDevice->ObjectID:"<<pRtnNetDevice->ObjectID<<std::endl;
  std::cout<<"on pRtnNetDevice->MonitorType_ID:"<<pRtnNetDevice->MonitorType_ID<<std::endl;
  std::cout<<"on pRtnNetDevice->SysNetSubAreaID:"<<pRtnNetDevice->SysNetSubAreaID<<std::endl;
  std::cout<<"on pRtnNetDevice->CATEGORY_ID:"<<pRtnNetDevice->CATEGORY_ID<<std::endl;
  std::cout<<"on pRtnNetDevice->FuctionArea:"<<pRtnNetDevice->FuctionArea<<std::endl;
  std::cout<<"on pRtnNetDevice->IPADDR:"<<pRtnNetDevice->IPADDR<<std::endl;
  std::cout<<"on pRtnNetDevice->IPDECODE:"<<pRtnNetDevice->IPDECODE<<std::endl;
  std::cout<<"on pRtnNetDevice->NAME:"<<pRtnNetDevice->NAME<<std::endl;
  std::cout<<"on pRtnNetDevice->PORTNUMBER:"<<pRtnNetDevice->PORTNUMBER<<std::endl;
  std::cout<<"on pRtnNetDevice->CONFIGFILE:"<<pRtnNetDevice->CONFIGFILE<<std::endl;
  std::cout<<"on pRtnNetDevice->RCOMMUNITY:"<<pRtnNetDevice->RCOMMUNITY<<std::endl;
  std::cout<<"on pRtnNetDevice->SNMPVERSION:"<<pRtnNetDevice->SNMPVERSION<<std::endl;
  std::cout<<"on pRtnNetDevice->RAMSIZE:"<<pRtnNetDevice->RAMSIZE<<std::endl;
  std::cout<<"on pRtnNetDevice->FLASHSIZE:"<<pRtnNetDevice->FLASHSIZE<<std::endl;
  std::cout<<"on pRtnNetDevice->NVRAMSIZE:"<<pRtnNetDevice->NVRAMSIZE<<std::endl;
  std::cout<<"on pRtnNetDevice->CABINET_ID:"<<pRtnNetDevice->CABINET_ID<<std::endl;
  std::cout<<"on pRtnNetDevice->ROOM_ID:"<<pRtnNetDevice->ROOM_ID<<std::endl;
  std::cout<<"on pRtnNetDevice->IOSVERSION_ID:"<<pRtnNetDevice->IOSVERSION_ID<<std::endl;
  std::cout<<"on pRtnNetDevice->DESCRIPTION:"<<pRtnNetDevice->DESCRIPTION<<std::endl;
  std::cout<<"on pRtnNetDevice->USERNAME:"<<pRtnNetDevice->USERNAME<<std::endl;
  std::cout<<"on pRtnNetDevice->PASSWD:"<<pRtnNetDevice->PASSWD<<std::endl;
  std::cout<<"on pRtnNetDevice->ENPASSWD:"<<pRtnNetDevice->ENPASSWD<<std::endl;
  std::cout<<"on pRtnNetDevice->MANUFACTORY_ID:"<<pRtnNetDevice->MANUFACTORY_ID<<std::endl;
  std::cout<<"on pRtnNetDevice->CFGSAVETYPE:"<<pRtnNetDevice->CFGSAVETYPE<<std::endl;
  std::cout<<"on pRtnNetDevice->DEVICETYPE:"<<pRtnNetDevice->DEVICETYPE<<std::endl;
  std::cout<<"on pRtnNetDevice->SENDSMS:"<<pRtnNetDevice->SENDSMS<<std::endl;
  std::cout<<"on pRtnNetDevice->ISSNMP:"<<pRtnNetDevice->ISSNMP<<std::endl;
  std::cout<<"on pRtnNetDevice->SLOTNUM:"<<pRtnNetDevice->SLOTNUM<<std::endl;
  std::cout<<"on pRtnNetDevice->ISPING:"<<pRtnNetDevice->ISPING<<std::endl;
  std::cout<<"on pRtnNetDevice->IFNUM:"<<pRtnNetDevice->IFNUM<<std::endl;
  std::cout<<"on pRtnNetDevice->APPLICATION_ID:"<<pRtnNetDevice->APPLICATION_ID<<std::endl;
  CShfeFtdcRtnNetDeviceField* pNewRtnNetDevice =new CShfeFtdcRtnNetDeviceField;
  memcpy(pNewRtnNetDevice,pRtnNetDevice,sizeof(CShfeFtdcRtnNetDeviceField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetDevice;
  asyncOnRtnNetDeviceTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetDeviceTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetDeviceDetectTopic(CShfeFtdcRspQryNetDeviceDetectField *pRspQryNetDeviceDetect, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetDeviceDetect->SysNetAreaID:"<<pRspQryNetDeviceDetect->SysNetAreaID<<std::endl;
  std::cout<<"on pRspQryNetDeviceDetect->SysNetSubAreaID:"<<pRspQryNetDeviceDetect->SysNetSubAreaID<<std::endl;
  std::cout<<"on pRspQryNetDeviceDetect->IP:"<<pRspQryNetDeviceDetect->IP<<std::endl;
  std::cout<<"on pRspQryNetDeviceDetect->Mask:"<<pRspQryNetDeviceDetect->Mask<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetDeviceDetectField* pNewRspQryNetDeviceDetect =new CShfeFtdcRspQryNetDeviceDetectField;
  memcpy(pNewRspQryNetDeviceDetect,pRspQryNetDeviceDetect,sizeof(CShfeFtdcRspQryNetDeviceDetectField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetDeviceDetect;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetDeviceDetectTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetDeviceDetectTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetBuildingTopic(CShfeFtdcRspQryNetBuildingField *pRspQryNetBuilding, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetBuilding->OperationType:"<<pRspQryNetBuilding->OperationType<<std::endl;
  std::cout<<"on pRspQryNetBuilding->ID:"<<pRspQryNetBuilding->ID<<std::endl;
  std::cout<<"on pRspQryNetBuilding->CName:"<<pRspQryNetBuilding->CName<<std::endl;
  std::cout<<"on pRspQryNetBuilding->EName:"<<pRspQryNetBuilding->EName<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetBuildingField* pNewRspQryNetBuilding =new CShfeFtdcRspQryNetBuildingField;
  memcpy(pNewRspQryNetBuilding,pRspQryNetBuilding,sizeof(CShfeFtdcRspQryNetBuildingField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetBuilding;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetBuildingTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetBuildingTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetBuildingTopic(CShfeFtdcRtnNetBuildingField *pRtnNetBuilding)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetBuilding->OperationType:"<<pRtnNetBuilding->OperationType<<std::endl;
  std::cout<<"on pRtnNetBuilding->ID:"<<pRtnNetBuilding->ID<<std::endl;
  std::cout<<"on pRtnNetBuilding->CName:"<<pRtnNetBuilding->CName<<std::endl;
  std::cout<<"on pRtnNetBuilding->EName:"<<pRtnNetBuilding->EName<<std::endl;
  CShfeFtdcRtnNetBuildingField* pNewRtnNetBuilding =new CShfeFtdcRtnNetBuildingField;
  memcpy(pNewRtnNetBuilding,pRtnNetBuilding,sizeof(CShfeFtdcRtnNetBuildingField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetBuilding;
  asyncOnRtnNetBuildingTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetBuildingTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetRoomTopic(CShfeFtdcRspQryNetRoomField *pRspQryNetRoom, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetRoom->OperationType:"<<pRspQryNetRoom->OperationType<<std::endl;
  std::cout<<"on pRspQryNetRoom->ID:"<<pRspQryNetRoom->ID<<std::endl;
  std::cout<<"on pRspQryNetRoom->SysNetBuildingID:"<<pRspQryNetRoom->SysNetBuildingID<<std::endl;
  std::cout<<"on pRspQryNetRoom->CName:"<<pRspQryNetRoom->CName<<std::endl;
  std::cout<<"on pRspQryNetRoom->EName:"<<pRspQryNetRoom->EName<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetRoomField* pNewRspQryNetRoom =new CShfeFtdcRspQryNetRoomField;
  memcpy(pNewRspQryNetRoom,pRspQryNetRoom,sizeof(CShfeFtdcRspQryNetRoomField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetRoom;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetRoomTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetRoomTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetRoomTopic(CShfeFtdcRtnNetRoomField *pRtnNetRoom)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetRoom->OperationType:"<<pRtnNetRoom->OperationType<<std::endl;
  std::cout<<"on pRtnNetRoom->ID:"<<pRtnNetRoom->ID<<std::endl;
  std::cout<<"on pRtnNetRoom->SysNetBuildingID:"<<pRtnNetRoom->SysNetBuildingID<<std::endl;
  std::cout<<"on pRtnNetRoom->CName:"<<pRtnNetRoom->CName<<std::endl;
  std::cout<<"on pRtnNetRoom->EName:"<<pRtnNetRoom->EName<<std::endl;
  CShfeFtdcRtnNetRoomField* pNewRtnNetRoom =new CShfeFtdcRtnNetRoomField;
  memcpy(pNewRtnNetRoom,pRtnNetRoom,sizeof(CShfeFtdcRtnNetRoomField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetRoom;
  asyncOnRtnNetRoomTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetRoomTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetCabinetsTopic(CShfeFtdcRspQryNetCabinetsField *pRspQryNetCabinets, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetCabinets->OperationType:"<<pRspQryNetCabinets->OperationType<<std::endl;
  std::cout<<"on pRspQryNetCabinets->ID:"<<pRspQryNetCabinets->ID<<std::endl;
  std::cout<<"on pRspQryNetCabinets->SysNetRoomID:"<<pRspQryNetCabinets->SysNetRoomID<<std::endl;
  std::cout<<"on pRspQryNetCabinets->SysNetBuildingID:"<<pRspQryNetCabinets->SysNetBuildingID<<std::endl;
  std::cout<<"on pRspQryNetCabinets->CName:"<<pRspQryNetCabinets->CName<<std::endl;
  std::cout<<"on pRspQryNetCabinets->EName:"<<pRspQryNetCabinets->EName<<std::endl;
  std::cout<<"on pRspQryNetCabinets->CabinetsType:"<<pRspQryNetCabinets->CabinetsType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetCabinetsField* pNewRspQryNetCabinets =new CShfeFtdcRspQryNetCabinetsField;
  memcpy(pNewRspQryNetCabinets,pRspQryNetCabinets,sizeof(CShfeFtdcRspQryNetCabinetsField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetCabinets;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetCabinetsTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetCabinetsTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetCabinetsTopic(CShfeFtdcRtnNetCabinetsField *pRtnNetCabinets)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetCabinets->OperationType:"<<pRtnNetCabinets->OperationType<<std::endl;
  std::cout<<"on pRtnNetCabinets->ID:"<<pRtnNetCabinets->ID<<std::endl;
  std::cout<<"on pRtnNetCabinets->SysNetRoomID:"<<pRtnNetCabinets->SysNetRoomID<<std::endl;
  std::cout<<"on pRtnNetCabinets->SysNetBuildingID:"<<pRtnNetCabinets->SysNetBuildingID<<std::endl;
  std::cout<<"on pRtnNetCabinets->CName:"<<pRtnNetCabinets->CName<<std::endl;
  std::cout<<"on pRtnNetCabinets->EName:"<<pRtnNetCabinets->EName<<std::endl;
  std::cout<<"on pRtnNetCabinets->CabinetsType:"<<pRtnNetCabinets->CabinetsType<<std::endl;
  CShfeFtdcRtnNetCabinetsField* pNewRtnNetCabinets =new CShfeFtdcRtnNetCabinetsField;
  memcpy(pNewRtnNetCabinets,pRtnNetCabinets,sizeof(CShfeFtdcRtnNetCabinetsField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetCabinets;
  asyncOnRtnNetCabinetsTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetCabinetsTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetOIDTopic(CShfeFtdcRspQryNetOIDField *pRspQryNetOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetOID->OperationType:"<<pRspQryNetOID->OperationType<<std::endl;
  std::cout<<"on pRspQryNetOID->ID:"<<pRspQryNetOID->ID<<std::endl;
  std::cout<<"on pRspQryNetOID->Manufactory:"<<pRspQryNetOID->Manufactory<<std::endl;
  std::cout<<"on pRspQryNetOID->DeviceType:"<<pRspQryNetOID->DeviceType<<std::endl;
  std::cout<<"on pRspQryNetOID->CName:"<<pRspQryNetOID->CName<<std::endl;
  std::cout<<"on pRspQryNetOID->EName:"<<pRspQryNetOID->EName<<std::endl;
  std::cout<<"on pRspQryNetOID->OID:"<<pRspQryNetOID->OID<<std::endl;
  std::cout<<"on pRspQryNetOID->Unit:"<<pRspQryNetOID->Unit<<std::endl;
  std::cout<<"on pRspQryNetOID->isTheTable:"<<pRspQryNetOID->isTheTable<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetOIDField* pNewRspQryNetOID =new CShfeFtdcRspQryNetOIDField;
  memcpy(pNewRspQryNetOID,pRspQryNetOID,sizeof(CShfeFtdcRspQryNetOIDField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetOID;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetOIDTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetOIDTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetOIDTopic(CShfeFtdcRtnNetOIDField *pRtnNetOID)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetOID->OperationType:"<<pRtnNetOID->OperationType<<std::endl;
  std::cout<<"on pRtnNetOID->ID:"<<pRtnNetOID->ID<<std::endl;
  std::cout<<"on pRtnNetOID->Manufactory:"<<pRtnNetOID->Manufactory<<std::endl;
  std::cout<<"on pRtnNetOID->DeviceType:"<<pRtnNetOID->DeviceType<<std::endl;
  std::cout<<"on pRtnNetOID->CName:"<<pRtnNetOID->CName<<std::endl;
  std::cout<<"on pRtnNetOID->EName:"<<pRtnNetOID->EName<<std::endl;
  std::cout<<"on pRtnNetOID->OID:"<<pRtnNetOID->OID<<std::endl;
  std::cout<<"on pRtnNetOID->Unit:"<<pRtnNetOID->Unit<<std::endl;
  std::cout<<"on pRtnNetOID->isTheTable:"<<pRtnNetOID->isTheTable<<std::endl;
  CShfeFtdcRtnNetOIDField* pNewRtnNetOID =new CShfeFtdcRtnNetOIDField;
  memcpy(pNewRtnNetOID,pRtnNetOID,sizeof(CShfeFtdcRtnNetOIDField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetOID;
  asyncOnRtnNetOIDTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetOIDTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetTimePolicyTopic(CShfeFtdcRspQryNetTimePolicyField *pRspQryNetTimePolicy, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetTimePolicy->OperationType:"<<pRspQryNetTimePolicy->OperationType<<std::endl;
  std::cout<<"on pRspQryNetTimePolicy->ID:"<<pRspQryNetTimePolicy->ID<<std::endl;
  std::cout<<"on pRspQryNetTimePolicy->CName:"<<pRspQryNetTimePolicy->CName<<std::endl;
  std::cout<<"on pRspQryNetTimePolicy->EName:"<<pRspQryNetTimePolicy->EName<<std::endl;
  std::cout<<"on pRspQryNetTimePolicy->PolicyType:"<<pRspQryNetTimePolicy->PolicyType<<std::endl;
  std::cout<<"on pRspQryNetTimePolicy->PolicyString:"<<pRspQryNetTimePolicy->PolicyString<<std::endl;
  std::cout<<"on pRspQryNetTimePolicy->TradingDay:"<<pRspQryNetTimePolicy->TradingDay<<std::endl;
  std::cout<<"on pRspQryNetTimePolicy->Description:"<<pRspQryNetTimePolicy->Description<<std::endl;
  std::cout<<"on pRspQryNetTimePolicy->Operation:"<<pRspQryNetTimePolicy->Operation<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetTimePolicyField* pNewRspQryNetTimePolicy =new CShfeFtdcRspQryNetTimePolicyField;
  memcpy(pNewRspQryNetTimePolicy,pRspQryNetTimePolicy,sizeof(CShfeFtdcRspQryNetTimePolicyField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetTimePolicy;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetTimePolicyTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetTimePolicyTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetTimePolicyTopic(CShfeFtdcRtnNetTimePolicyField *pRtnNetTimePolicy)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetTimePolicy->OperationType:"<<pRtnNetTimePolicy->OperationType<<std::endl;
  std::cout<<"on pRtnNetTimePolicy->ID:"<<pRtnNetTimePolicy->ID<<std::endl;
  std::cout<<"on pRtnNetTimePolicy->CName:"<<pRtnNetTimePolicy->CName<<std::endl;
  std::cout<<"on pRtnNetTimePolicy->EName:"<<pRtnNetTimePolicy->EName<<std::endl;
  std::cout<<"on pRtnNetTimePolicy->PolicyType:"<<pRtnNetTimePolicy->PolicyType<<std::endl;
  std::cout<<"on pRtnNetTimePolicy->PolicyString:"<<pRtnNetTimePolicy->PolicyString<<std::endl;
  std::cout<<"on pRtnNetTimePolicy->TradingDay:"<<pRtnNetTimePolicy->TradingDay<<std::endl;
  std::cout<<"on pRtnNetTimePolicy->Description:"<<pRtnNetTimePolicy->Description<<std::endl;
  std::cout<<"on pRtnNetTimePolicy->Operation:"<<pRtnNetTimePolicy->Operation<<std::endl;
  CShfeFtdcRtnNetTimePolicyField* pNewRtnNetTimePolicy =new CShfeFtdcRtnNetTimePolicyField;
  memcpy(pNewRtnNetTimePolicy,pRtnNetTimePolicy,sizeof(CShfeFtdcRtnNetTimePolicyField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetTimePolicy;
  asyncOnRtnNetTimePolicyTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetTimePolicyTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetGatherTaskTopic(CShfeFtdcRspQryNetGatherTaskField *pRspQryNetGatherTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetGatherTask->OperationType:"<<pRspQryNetGatherTask->OperationType<<std::endl;
  std::cout<<"on pRspQryNetGatherTask->ID:"<<pRspQryNetGatherTask->ID<<std::endl;
  std::cout<<"on pRspQryNetGatherTask->ObjectID:"<<pRspQryNetGatherTask->ObjectID<<std::endl;
  std::cout<<"on pRspQryNetGatherTask->AttrType:"<<pRspQryNetGatherTask->AttrType<<std::endl;
  std::cout<<"on pRspQryNetGatherTask->PolicyTypeID:"<<pRspQryNetGatherTask->PolicyTypeID<<std::endl;
  std::cout<<"on pRspQryNetGatherTask->DataType:"<<pRspQryNetGatherTask->DataType<<std::endl;
  std::cout<<"on pRspQryNetGatherTask->TypeFlag:"<<pRspQryNetGatherTask->TypeFlag<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetGatherTaskField* pNewRspQryNetGatherTask =new CShfeFtdcRspQryNetGatherTaskField;
  memcpy(pNewRspQryNetGatherTask,pRspQryNetGatherTask,sizeof(CShfeFtdcRspQryNetGatherTaskField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetGatherTask;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetGatherTaskTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetGatherTaskTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetGatherTaskTopic(CShfeFtdcRtnNetGatherTaskField *pRtnNetGatherTask)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetGatherTask->OperationType:"<<pRtnNetGatherTask->OperationType<<std::endl;
  std::cout<<"on pRtnNetGatherTask->ID:"<<pRtnNetGatherTask->ID<<std::endl;
  std::cout<<"on pRtnNetGatherTask->ObjectID:"<<pRtnNetGatherTask->ObjectID<<std::endl;
  std::cout<<"on pRtnNetGatherTask->AttrType:"<<pRtnNetGatherTask->AttrType<<std::endl;
  std::cout<<"on pRtnNetGatherTask->PolicyTypeID:"<<pRtnNetGatherTask->PolicyTypeID<<std::endl;
  std::cout<<"on pRtnNetGatherTask->DataType:"<<pRtnNetGatherTask->DataType<<std::endl;
  std::cout<<"on pRtnNetGatherTask->TypeFlag:"<<pRtnNetGatherTask->TypeFlag<<std::endl;
  CShfeFtdcRtnNetGatherTaskField* pNewRtnNetGatherTask =new CShfeFtdcRtnNetGatherTaskField;
  memcpy(pNewRtnNetGatherTask,pRtnNetGatherTask,sizeof(CShfeFtdcRtnNetGatherTaskField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetGatherTask;
  asyncOnRtnNetGatherTaskTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetGatherTaskTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetDeviceChgTopic(CShfeFtdcRspQryNetDeviceChgField *pRspQryNetDeviceChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetDeviceChg->DeviceID:"<<pRspQryNetDeviceChg->DeviceID<<std::endl;
  std::cout<<"on pRspQryNetDeviceChg->SysNetSubAreaID:"<<pRspQryNetDeviceChg->SysNetSubAreaID<<std::endl;
  std::cout<<"on pRspQryNetDeviceChg->OldObjectID:"<<pRspQryNetDeviceChg->OldObjectID<<std::endl;
  std::cout<<"on pRspQryNetDeviceChg->NewObjectID:"<<pRspQryNetDeviceChg->NewObjectID<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetDeviceChgField* pNewRspQryNetDeviceChg =new CShfeFtdcRspQryNetDeviceChgField;
  memcpy(pNewRspQryNetDeviceChg,pRspQryNetDeviceChg,sizeof(CShfeFtdcRspQryNetDeviceChgField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetDeviceChg;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetDeviceChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetDeviceChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetDeviceChgTopic(CShfeFtdcRtnNetDeviceChgField *pRtnNetDeviceChg)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetDeviceChg->DeviceID:"<<pRtnNetDeviceChg->DeviceID<<std::endl;
  std::cout<<"on pRtnNetDeviceChg->SysNetSubAreaID:"<<pRtnNetDeviceChg->SysNetSubAreaID<<std::endl;
  std::cout<<"on pRtnNetDeviceChg->OldObjectID:"<<pRtnNetDeviceChg->OldObjectID<<std::endl;
  std::cout<<"on pRtnNetDeviceChg->NewObjectID:"<<pRtnNetDeviceChg->NewObjectID<<std::endl;
  CShfeFtdcRtnNetDeviceChgField* pNewRtnNetDeviceChg =new CShfeFtdcRtnNetDeviceChgField;
  memcpy(pNewRtnNetDeviceChg,pRtnNetDeviceChg,sizeof(CShfeFtdcRtnNetDeviceChgField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetDeviceChg;
  asyncOnRtnNetDeviceChgTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetDeviceChgTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetDeviceTypeTopic(CShfeFtdcRspQryNetDeviceTypeField *pRspQryNetDeviceType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetDeviceType->OperationType:"<<pRspQryNetDeviceType->OperationType<<std::endl;
  std::cout<<"on pRspQryNetDeviceType->ID:"<<pRspQryNetDeviceType->ID<<std::endl;
  std::cout<<"on pRspQryNetDeviceType->Manufactory:"<<pRspQryNetDeviceType->Manufactory<<std::endl;
  std::cout<<"on pRspQryNetDeviceType->DeviceType:"<<pRspQryNetDeviceType->DeviceType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetDeviceTypeField* pNewRspQryNetDeviceType =new CShfeFtdcRspQryNetDeviceTypeField;
  memcpy(pNewRspQryNetDeviceType,pRspQryNetDeviceType,sizeof(CShfeFtdcRspQryNetDeviceTypeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetDeviceType;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetDeviceTypeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetDeviceTypeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetDeviceTypeTopic(CShfeFtdcRtnNetDeviceTypeField *pRtnNetDeviceType)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetDeviceType->OperationType:"<<pRtnNetDeviceType->OperationType<<std::endl;
  std::cout<<"on pRtnNetDeviceType->ID:"<<pRtnNetDeviceType->ID<<std::endl;
  std::cout<<"on pRtnNetDeviceType->Manufactory:"<<pRtnNetDeviceType->Manufactory<<std::endl;
  std::cout<<"on pRtnNetDeviceType->DeviceType:"<<pRtnNetDeviceType->DeviceType<<std::endl;
  CShfeFtdcRtnNetDeviceTypeField* pNewRtnNetDeviceType =new CShfeFtdcRtnNetDeviceTypeField;
  memcpy(pNewRtnNetDeviceType,pRtnNetDeviceType,sizeof(CShfeFtdcRtnNetDeviceTypeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetDeviceType;
  asyncOnRtnNetDeviceTypeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetDeviceTypeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetDeviceCategoryTopic(CShfeFtdcRspQryNetDeviceCategoryField *pRspQryNetDeviceCategory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetDeviceCategory->OperationType:"<<pRspQryNetDeviceCategory->OperationType<<std::endl;
  std::cout<<"on pRspQryNetDeviceCategory->ID:"<<pRspQryNetDeviceCategory->ID<<std::endl;
  std::cout<<"on pRspQryNetDeviceCategory->CName:"<<pRspQryNetDeviceCategory->CName<<std::endl;
  std::cout<<"on pRspQryNetDeviceCategory->EName:"<<pRspQryNetDeviceCategory->EName<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetDeviceCategoryField* pNewRspQryNetDeviceCategory =new CShfeFtdcRspQryNetDeviceCategoryField;
  memcpy(pNewRspQryNetDeviceCategory,pRspQryNetDeviceCategory,sizeof(CShfeFtdcRspQryNetDeviceCategoryField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetDeviceCategory;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetDeviceCategoryTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetDeviceCategoryTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetDeviceCategoryTopic(CShfeFtdcRtnNetDeviceCategoryField *pRtnNetDeviceCategory)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetDeviceCategory->OperationType:"<<pRtnNetDeviceCategory->OperationType<<std::endl;
  std::cout<<"on pRtnNetDeviceCategory->ID:"<<pRtnNetDeviceCategory->ID<<std::endl;
  std::cout<<"on pRtnNetDeviceCategory->CName:"<<pRtnNetDeviceCategory->CName<<std::endl;
  std::cout<<"on pRtnNetDeviceCategory->EName:"<<pRtnNetDeviceCategory->EName<<std::endl;
  CShfeFtdcRtnNetDeviceCategoryField* pNewRtnNetDeviceCategory =new CShfeFtdcRtnNetDeviceCategoryField;
  memcpy(pNewRtnNetDeviceCategory,pRtnNetDeviceCategory,sizeof(CShfeFtdcRtnNetDeviceCategoryField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetDeviceCategory;
  asyncOnRtnNetDeviceCategoryTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetDeviceCategoryTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetManufactoryTopic(CShfeFtdcRspQryNetManufactoryField *pRspQryNetManufactory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetManufactory->OperationType:"<<pRspQryNetManufactory->OperationType<<std::endl;
  std::cout<<"on pRspQryNetManufactory->ID:"<<pRspQryNetManufactory->ID<<std::endl;
  std::cout<<"on pRspQryNetManufactory->CName:"<<pRspQryNetManufactory->CName<<std::endl;
  std::cout<<"on pRspQryNetManufactory->EName:"<<pRspQryNetManufactory->EName<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetManufactoryField* pNewRspQryNetManufactory =new CShfeFtdcRspQryNetManufactoryField;
  memcpy(pNewRspQryNetManufactory,pRspQryNetManufactory,sizeof(CShfeFtdcRspQryNetManufactoryField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetManufactory;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetManufactoryTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetManufactoryTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetManufactoryTopic(CShfeFtdcRtnNetManufactoryField *pRtnNetManufactory)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetManufactory->OperationType:"<<pRtnNetManufactory->OperationType<<std::endl;
  std::cout<<"on pRtnNetManufactory->ID:"<<pRtnNetManufactory->ID<<std::endl;
  std::cout<<"on pRtnNetManufactory->CName:"<<pRtnNetManufactory->CName<<std::endl;
  std::cout<<"on pRtnNetManufactory->EName:"<<pRtnNetManufactory->EName<<std::endl;
  CShfeFtdcRtnNetManufactoryField* pNewRtnNetManufactory =new CShfeFtdcRtnNetManufactoryField;
  memcpy(pNewRtnNetManufactory,pRtnNetManufactory,sizeof(CShfeFtdcRtnNetManufactoryField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetManufactory;
  asyncOnRtnNetManufactoryTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetManufactoryTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetCommunityTopic(CShfeFtdcRspQryNetCommunityField *pRspQryNetCommunity, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetCommunity->OperationType:"<<pRspQryNetCommunity->OperationType<<std::endl;
  std::cout<<"on pRspQryNetCommunity->ID:"<<pRspQryNetCommunity->ID<<std::endl;
  std::cout<<"on pRspQryNetCommunity->IPADDR:"<<pRspQryNetCommunity->IPADDR<<std::endl;
  std::cout<<"on pRspQryNetCommunity->COMMUNITY:"<<pRspQryNetCommunity->COMMUNITY<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetCommunityField* pNewRspQryNetCommunity =new CShfeFtdcRspQryNetCommunityField;
  memcpy(pNewRspQryNetCommunity,pRspQryNetCommunity,sizeof(CShfeFtdcRspQryNetCommunityField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetCommunity;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetCommunityTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetCommunityTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetCommunityTopic(CShfeFtdcRtnNetCommunityField *pRtnNetCommunity)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetCommunity->OperationType:"<<pRtnNetCommunity->OperationType<<std::endl;
  std::cout<<"on pRtnNetCommunity->ID:"<<pRtnNetCommunity->ID<<std::endl;
  std::cout<<"on pRtnNetCommunity->IPADDR:"<<pRtnNetCommunity->IPADDR<<std::endl;
  std::cout<<"on pRtnNetCommunity->COMMUNITY:"<<pRtnNetCommunity->COMMUNITY<<std::endl;
  CShfeFtdcRtnNetCommunityField* pNewRtnNetCommunity =new CShfeFtdcRtnNetCommunityField;
  memcpy(pNewRtnNetCommunity,pRtnNetCommunity,sizeof(CShfeFtdcRtnNetCommunityField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetCommunity;
  asyncOnRtnNetCommunityTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetCommunityTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetPortTypeTopic(CShfeFtdcRspQryNetPortTypeField *pRspQryNetPortType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetPortType->OperationType:"<<pRspQryNetPortType->OperationType<<std::endl;
  std::cout<<"on pRspQryNetPortType->ID:"<<pRspQryNetPortType->ID<<std::endl;
  std::cout<<"on pRspQryNetPortType->CName:"<<pRspQryNetPortType->CName<<std::endl;
  std::cout<<"on pRspQryNetPortType->EName:"<<pRspQryNetPortType->EName<<std::endl;
  std::cout<<"on pRspQryNetPortType->Description:"<<pRspQryNetPortType->Description<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetPortTypeField* pNewRspQryNetPortType =new CShfeFtdcRspQryNetPortTypeField;
  memcpy(pNewRspQryNetPortType,pRspQryNetPortType,sizeof(CShfeFtdcRspQryNetPortTypeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetPortType;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetPortTypeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetPortTypeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetPortTypeTopic(CShfeFtdcRtnNetPortTypeField *pRtnNetPortType)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetPortType->OperationType:"<<pRtnNetPortType->OperationType<<std::endl;
  std::cout<<"on pRtnNetPortType->ID:"<<pRtnNetPortType->ID<<std::endl;
  std::cout<<"on pRtnNetPortType->CName:"<<pRtnNetPortType->CName<<std::endl;
  std::cout<<"on pRtnNetPortType->EName:"<<pRtnNetPortType->EName<<std::endl;
  std::cout<<"on pRtnNetPortType->Description:"<<pRtnNetPortType->Description<<std::endl;
  CShfeFtdcRtnNetPortTypeField* pNewRtnNetPortType =new CShfeFtdcRtnNetPortTypeField;
  memcpy(pNewRtnNetPortType,pRtnNetPortType,sizeof(CShfeFtdcRtnNetPortTypeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetPortType;
  asyncOnRtnNetPortTypeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetPortTypeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetPartAccessSpotTopic(CShfeFtdcRspQryNetPartAccessSpotField *pRspQryNetPartAccessSpot, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetPartAccessSpot->OperationType:"<<pRspQryNetPartAccessSpot->OperationType<<std::endl;
  std::cout<<"on pRspQryNetPartAccessSpot->ID:"<<pRspQryNetPartAccessSpot->ID<<std::endl;
  std::cout<<"on pRspQryNetPartAccessSpot->CName:"<<pRspQryNetPartAccessSpot->CName<<std::endl;
  std::cout<<"on pRspQryNetPartAccessSpot->EName:"<<pRspQryNetPartAccessSpot->EName<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetPartAccessSpotField* pNewRspQryNetPartAccessSpot =new CShfeFtdcRspQryNetPartAccessSpotField;
  memcpy(pNewRspQryNetPartAccessSpot,pRspQryNetPartAccessSpot,sizeof(CShfeFtdcRspQryNetPartAccessSpotField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetPartAccessSpot;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetPartAccessSpotTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetPartAccessSpotTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetPartAccessSpotTopic(CShfeFtdcRtnNetPartAccessSpotField *pRtnNetPartAccessSpot)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetPartAccessSpot->OperationType:"<<pRtnNetPartAccessSpot->OperationType<<std::endl;
  std::cout<<"on pRtnNetPartAccessSpot->ID:"<<pRtnNetPartAccessSpot->ID<<std::endl;
  std::cout<<"on pRtnNetPartAccessSpot->CName:"<<pRtnNetPartAccessSpot->CName<<std::endl;
  std::cout<<"on pRtnNetPartAccessSpot->EName:"<<pRtnNetPartAccessSpot->EName<<std::endl;
  CShfeFtdcRtnNetPartAccessSpotField* pNewRtnNetPartAccessSpot =new CShfeFtdcRtnNetPartAccessSpotField;
  memcpy(pNewRtnNetPartAccessSpot,pRtnNetPartAccessSpot,sizeof(CShfeFtdcRtnNetPartAccessSpotField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetPartAccessSpot;
  asyncOnRtnNetPartAccessSpotTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetPartAccessSpotTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetInterfaceTopic(CShfeFtdcRspQryNetInterfaceField *pRspQryNetInterface, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetInterface->OperationType:"<<pRspQryNetInterface->OperationType<<std::endl;
  std::cout<<"on pRspQryNetInterface->ID:"<<pRspQryNetInterface->ID<<std::endl;
  std::cout<<"on pRspQryNetInterface->ObjectID:"<<pRspQryNetInterface->ObjectID<<std::endl;
  std::cout<<"on pRspQryNetInterface->MonitorType_ID:"<<pRspQryNetInterface->MonitorType_ID<<std::endl;
  std::cout<<"on pRspQryNetInterface->IfType:"<<pRspQryNetInterface->IfType<<std::endl;
  std::cout<<"on pRspQryNetInterface->EName:"<<pRspQryNetInterface->EName<<std::endl;
  std::cout<<"on pRspQryNetInterface->IpAddress:"<<pRspQryNetInterface->IpAddress<<std::endl;
  std::cout<<"on pRspQryNetInterface->IpMask:"<<pRspQryNetInterface->IpMask<<std::endl;
  std::cout<<"on pRspQryNetInterface->IfStatus:"<<pRspQryNetInterface->IfStatus<<std::endl;
  std::cout<<"on pRspQryNetInterface->MAC:"<<pRspQryNetInterface->MAC<<std::endl;
  std::cout<<"on pRspQryNetInterface->DeviceID:"<<pRspQryNetInterface->DeviceID<<std::endl;
  std::cout<<"on pRspQryNetInterface->DeviceObjectID:"<<pRspQryNetInterface->DeviceObjectID<<std::endl;
  std::cout<<"on pRspQryNetInterface->DeviceIndex:"<<pRspQryNetInterface->DeviceIndex<<std::endl;
  std::cout<<"on pRspQryNetInterface->isPolling:"<<pRspQryNetInterface->isPolling<<std::endl;
  std::cout<<"on pRspQryNetInterface->Description:"<<pRspQryNetInterface->Description<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetInterfaceField* pNewRspQryNetInterface =new CShfeFtdcRspQryNetInterfaceField;
  memcpy(pNewRspQryNetInterface,pRspQryNetInterface,sizeof(CShfeFtdcRspQryNetInterfaceField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetInterface;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetInterfaceTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetInterfaceTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetInterfaceTopic(CShfeFtdcRtnNetInterfaceField *pRtnNetInterface)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetInterface->OperationType:"<<pRtnNetInterface->OperationType<<std::endl;
  std::cout<<"on pRtnNetInterface->ID:"<<pRtnNetInterface->ID<<std::endl;
  std::cout<<"on pRtnNetInterface->ObjectID:"<<pRtnNetInterface->ObjectID<<std::endl;
  std::cout<<"on pRtnNetInterface->MonitorType_ID:"<<pRtnNetInterface->MonitorType_ID<<std::endl;
  std::cout<<"on pRtnNetInterface->IfType:"<<pRtnNetInterface->IfType<<std::endl;
  std::cout<<"on pRtnNetInterface->EName:"<<pRtnNetInterface->EName<<std::endl;
  std::cout<<"on pRtnNetInterface->IpAddress:"<<pRtnNetInterface->IpAddress<<std::endl;
  std::cout<<"on pRtnNetInterface->IpMask:"<<pRtnNetInterface->IpMask<<std::endl;
  std::cout<<"on pRtnNetInterface->IfStatus:"<<pRtnNetInterface->IfStatus<<std::endl;
  std::cout<<"on pRtnNetInterface->MAC:"<<pRtnNetInterface->MAC<<std::endl;
  std::cout<<"on pRtnNetInterface->DeviceID:"<<pRtnNetInterface->DeviceID<<std::endl;
  std::cout<<"on pRtnNetInterface->DeviceObjectID:"<<pRtnNetInterface->DeviceObjectID<<std::endl;
  std::cout<<"on pRtnNetInterface->DeviceIndex:"<<pRtnNetInterface->DeviceIndex<<std::endl;
  std::cout<<"on pRtnNetInterface->isPolling:"<<pRtnNetInterface->isPolling<<std::endl;
  std::cout<<"on pRtnNetInterface->Description:"<<pRtnNetInterface->Description<<std::endl;
  CShfeFtdcRtnNetInterfaceField* pNewRtnNetInterface =new CShfeFtdcRtnNetInterfaceField;
  memcpy(pNewRtnNetInterface,pRtnNetInterface,sizeof(CShfeFtdcRtnNetInterfaceField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetInterface;
  asyncOnRtnNetInterfaceTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetInterfaceTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetGeneralOIDTopic(CShfeFtdcRspQryNetGeneralOIDField *pRspQryNetGeneralOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetGeneralOID->OperationType:"<<pRspQryNetGeneralOID->OperationType<<std::endl;
  std::cout<<"on pRspQryNetGeneralOID->ID:"<<pRspQryNetGeneralOID->ID<<std::endl;
  std::cout<<"on pRspQryNetGeneralOID->CName:"<<pRspQryNetGeneralOID->CName<<std::endl;
  std::cout<<"on pRspQryNetGeneralOID->EName:"<<pRspQryNetGeneralOID->EName<<std::endl;
  std::cout<<"on pRspQryNetGeneralOID->OID:"<<pRspQryNetGeneralOID->OID<<std::endl;
  std::cout<<"on pRspQryNetGeneralOID->Unit:"<<pRspQryNetGeneralOID->Unit<<std::endl;
  std::cout<<"on pRspQryNetGeneralOID->isTheTable:"<<pRspQryNetGeneralOID->isTheTable<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetGeneralOIDField* pNewRspQryNetGeneralOID =new CShfeFtdcRspQryNetGeneralOIDField;
  memcpy(pNewRspQryNetGeneralOID,pRspQryNetGeneralOID,sizeof(CShfeFtdcRspQryNetGeneralOIDField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetGeneralOID;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetGeneralOIDTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetGeneralOIDTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetGeneralOIDTopic(CShfeFtdcRtnNetGeneralOIDField *pRtnNetGeneralOID)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetGeneralOID->OperationType:"<<pRtnNetGeneralOID->OperationType<<std::endl;
  std::cout<<"on pRtnNetGeneralOID->ID:"<<pRtnNetGeneralOID->ID<<std::endl;
  std::cout<<"on pRtnNetGeneralOID->CName:"<<pRtnNetGeneralOID->CName<<std::endl;
  std::cout<<"on pRtnNetGeneralOID->EName:"<<pRtnNetGeneralOID->EName<<std::endl;
  std::cout<<"on pRtnNetGeneralOID->OID:"<<pRtnNetGeneralOID->OID<<std::endl;
  std::cout<<"on pRtnNetGeneralOID->Unit:"<<pRtnNetGeneralOID->Unit<<std::endl;
  std::cout<<"on pRtnNetGeneralOID->isTheTable:"<<pRtnNetGeneralOID->isTheTable<<std::endl;
  CShfeFtdcRtnNetGeneralOIDField* pNewRtnNetGeneralOID =new CShfeFtdcRtnNetGeneralOIDField;
  memcpy(pNewRtnNetGeneralOID,pRtnNetGeneralOID,sizeof(CShfeFtdcRtnNetGeneralOIDField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetGeneralOID;
  asyncOnRtnNetGeneralOIDTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetGeneralOIDTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetMonitorTypeTopic(CShfeFtdcRspQryNetMonitorTypeField *pRspQryNetMonitorType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetMonitorType->OperationType:"<<pRspQryNetMonitorType->OperationType<<std::endl;
  std::cout<<"on pRspQryNetMonitorType->ID:"<<pRspQryNetMonitorType->ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorType->CName:"<<pRspQryNetMonitorType->CName<<std::endl;
  std::cout<<"on pRspQryNetMonitorType->EName:"<<pRspQryNetMonitorType->EName<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetMonitorTypeField* pNewRspQryNetMonitorType =new CShfeFtdcRspQryNetMonitorTypeField;
  memcpy(pNewRspQryNetMonitorType,pRspQryNetMonitorType,sizeof(CShfeFtdcRspQryNetMonitorTypeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorType;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorTypeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetMonitorTypeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetMonitorTypeTopic(CShfeFtdcRtnNetMonitorTypeField *pRtnNetMonitorType)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetMonitorType->OperationType:"<<pRtnNetMonitorType->OperationType<<std::endl;
  std::cout<<"on pRtnNetMonitorType->ID:"<<pRtnNetMonitorType->ID<<std::endl;
  std::cout<<"on pRtnNetMonitorType->CName:"<<pRtnNetMonitorType->CName<<std::endl;
  std::cout<<"on pRtnNetMonitorType->EName:"<<pRtnNetMonitorType->EName<<std::endl;
  CShfeFtdcRtnNetMonitorTypeField* pNewRtnNetMonitorType =new CShfeFtdcRtnNetMonitorTypeField;
  memcpy(pNewRtnNetMonitorType,pRtnNetMonitorType,sizeof(CShfeFtdcRtnNetMonitorTypeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorType;
  asyncOnRtnNetMonitorTypeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetMonitorTypeTopic);
  std::cout<<"end send "<<std::endl;
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
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorAttrScopeTopic.data=(void*)&paramArray[0];
  
  uv_mutex_lock(&g_OnRspQryNetMonitorAttrScopeTopic_data_mutex);
  g_OnRspQryNetMonitorAttrScopeTopic_queue.push(paramArray);
  uv_mutex_unlock(&g_OnRspQryNetMonitorAttrScopeTopic_data_mutex);
  
  uv_sem_wait(&g_OnRspQryNetMonitorAttrScopeTopicc_sem);
  uv_mutex_lock(&g_OnRspQryNetMonitorAttrScopeTopic_mutex);
  
  std::cout<<"\n*********** SysUserSpi::OnRspQryNetMonitorAttrScopeTopic: START! **********"<<std::endl;
  cout << "****** g_OnRspQryNetMonitorAttrScopeTopic_Sys_index: " 
       << g_OnRspQryNetMonitorAttrScopeTopic_Sys_index++ <<" ******" <<endl;       
  std::cout<<"on pRspQryNetMonitorAttrScope->OperationType:"<<pRspQryNetMonitorAttrScope->OperationType<<std::endl;
  std::cout<<"on pRspQryNetMonitorAttrScope->ID:"<<pRspQryNetMonitorAttrScope->ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorAttrScope->CName:"<<pRspQryNetMonitorAttrScope->CName<<std::endl;
  std::cout<<"on pRspQryNetMonitorAttrScope->EName:"<<pRspQryNetMonitorAttrScope->EName<<std::endl;
  std::cout<<"on pRspQryNetMonitorAttrScope->Comments:"<<pRspQryNetMonitorAttrScope->Comments<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  
  uv_async_send(&asyncOnRspQryNetMonitorAttrScopeTopic);
  
  uv_mutex_unlock(&g_OnRspQryNetMonitorAttrScopeTopic_mutex);
  
  std::cout<<"*********** SysUserSpi::OnRspQryNetMonitorAttrScopeTopic: END! **********\n"<<std::endl;
}
void SysUserSpi::OnRtnNetMonitorAttrScopeTopic(CShfeFtdcRtnNetMonitorAttrScopeField *pRtnNetMonitorAttrScope)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetMonitorAttrScope->OperationType:"<<pRtnNetMonitorAttrScope->OperationType<<std::endl;
  std::cout<<"on pRtnNetMonitorAttrScope->ID:"<<pRtnNetMonitorAttrScope->ID<<std::endl;
  std::cout<<"on pRtnNetMonitorAttrScope->CName:"<<pRtnNetMonitorAttrScope->CName<<std::endl;
  std::cout<<"on pRtnNetMonitorAttrScope->EName:"<<pRtnNetMonitorAttrScope->EName<<std::endl;
  std::cout<<"on pRtnNetMonitorAttrScope->Comments:"<<pRtnNetMonitorAttrScope->Comments<<std::endl;
  CShfeFtdcRtnNetMonitorAttrScopeField* pNewRtnNetMonitorAttrScope =new CShfeFtdcRtnNetMonitorAttrScopeField;
  memcpy(pNewRtnNetMonitorAttrScope,pRtnNetMonitorAttrScope,sizeof(CShfeFtdcRtnNetMonitorAttrScopeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorAttrScope;
  asyncOnRtnNetMonitorAttrScopeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetMonitorAttrScopeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetMonitorAttrTypeTopic(CShfeFtdcRspQryNetMonitorAttrTypeField *pRspQryNetMonitorAttrType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetMonitorAttrType->OperationType:"<<pRspQryNetMonitorAttrType->OperationType<<std::endl;
  std::cout<<"on pRspQryNetMonitorAttrType->ID:"<<pRspQryNetMonitorAttrType->ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorAttrType->MANUFACTORY_ID:"<<pRspQryNetMonitorAttrType->MANUFACTORY_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorAttrType->MonitorType_ID:"<<pRspQryNetMonitorAttrType->MonitorType_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorAttrType->AttrType_ID:"<<pRspQryNetMonitorAttrType->AttrType_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorAttrType->MANUFACTORY:"<<pRspQryNetMonitorAttrType->MANUFACTORY<<std::endl;
  std::cout<<"on pRspQryNetMonitorAttrType->MonitorType:"<<pRspQryNetMonitorAttrType->MonitorType<<std::endl;
  std::cout<<"on pRspQryNetMonitorAttrType->AttrType:"<<pRspQryNetMonitorAttrType->AttrType<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetMonitorAttrTypeField* pNewRspQryNetMonitorAttrType =new CShfeFtdcRspQryNetMonitorAttrTypeField;
  memcpy(pNewRspQryNetMonitorAttrType,pRspQryNetMonitorAttrType,sizeof(CShfeFtdcRspQryNetMonitorAttrTypeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorAttrType;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorAttrTypeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetMonitorAttrTypeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetMonitorAttrTypeTopic(CShfeFtdcRtnNetMonitorAttrTypeField *pRtnNetMonitorAttrType)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetMonitorAttrType->OperationType:"<<pRtnNetMonitorAttrType->OperationType<<std::endl;
  std::cout<<"on pRtnNetMonitorAttrType->ID:"<<pRtnNetMonitorAttrType->ID<<std::endl;
  std::cout<<"on pRtnNetMonitorAttrType->MANUFACTORY_ID:"<<pRtnNetMonitorAttrType->MANUFACTORY_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorAttrType->MonitorType_ID:"<<pRtnNetMonitorAttrType->MonitorType_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorAttrType->AttrType_ID:"<<pRtnNetMonitorAttrType->AttrType_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorAttrType->MANUFACTORY:"<<pRtnNetMonitorAttrType->MANUFACTORY<<std::endl;
  std::cout<<"on pRtnNetMonitorAttrType->MonitorType:"<<pRtnNetMonitorAttrType->MonitorType<<std::endl;
  std::cout<<"on pRtnNetMonitorAttrType->AttrType:"<<pRtnNetMonitorAttrType->AttrType<<std::endl;
  CShfeFtdcRtnNetMonitorAttrTypeField* pNewRtnNetMonitorAttrType =new CShfeFtdcRtnNetMonitorAttrTypeField;
  memcpy(pNewRtnNetMonitorAttrType,pRtnNetMonitorAttrType,sizeof(CShfeFtdcRtnNetMonitorAttrTypeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorAttrType;
  asyncOnRtnNetMonitorAttrTypeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetMonitorAttrTypeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetMonitorObjectAttrTopic(CShfeFtdcRspQryNetMonitorObjectAttrField *pRspQryNetMonitorObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetMonitorObjectAttr->OperationType:"<<pRspQryNetMonitorObjectAttr->OperationType<<std::endl;
  std::cout<<"on pRspQryNetMonitorObjectAttr->ID:"<<pRspQryNetMonitorObjectAttr->ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorObjectAttr->ObjectID:"<<pRspQryNetMonitorObjectAttr->ObjectID<<std::endl;
  std::cout<<"on pRspQryNetMonitorObjectAttr->AttrType:"<<pRspQryNetMonitorObjectAttr->AttrType<<std::endl;
  std::cout<<"on pRspQryNetMonitorObjectAttr->PolicyTypeID:"<<pRspQryNetMonitorObjectAttr->PolicyTypeID<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetMonitorObjectAttrField* pNewRspQryNetMonitorObjectAttr =new CShfeFtdcRspQryNetMonitorObjectAttrField;
  memcpy(pNewRspQryNetMonitorObjectAttr,pRspQryNetMonitorObjectAttr,sizeof(CShfeFtdcRspQryNetMonitorObjectAttrField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorObjectAttr;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorObjectAttrTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetMonitorObjectAttrTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetMonitorObjectAttrTopic(CShfeFtdcRtnNetMonitorObjectAttrField *pRtnNetMonitorObjectAttr)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetMonitorObjectAttr->OperationType:"<<pRtnNetMonitorObjectAttr->OperationType<<std::endl;
  std::cout<<"on pRtnNetMonitorObjectAttr->ID:"<<pRtnNetMonitorObjectAttr->ID<<std::endl;
  std::cout<<"on pRtnNetMonitorObjectAttr->ObjectID:"<<pRtnNetMonitorObjectAttr->ObjectID<<std::endl;
  std::cout<<"on pRtnNetMonitorObjectAttr->AttrType:"<<pRtnNetMonitorObjectAttr->AttrType<<std::endl;
  std::cout<<"on pRtnNetMonitorObjectAttr->PolicyTypeID:"<<pRtnNetMonitorObjectAttr->PolicyTypeID<<std::endl;
  CShfeFtdcRtnNetMonitorObjectAttrField* pNewRtnNetMonitorObjectAttr =new CShfeFtdcRtnNetMonitorObjectAttrField;
  memcpy(pNewRtnNetMonitorObjectAttr,pRtnNetMonitorObjectAttr,sizeof(CShfeFtdcRtnNetMonitorObjectAttrField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorObjectAttr;
  asyncOnRtnNetMonitorObjectAttrTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetMonitorObjectAttrTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetFuncAreaTopic(CShfeFtdcRspQryNetFuncAreaField *pRspQryNetFuncArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetFuncArea->OperationType:"<<pRspQryNetFuncArea->OperationType<<std::endl;
  std::cout<<"on pRspQryNetFuncArea->ID:"<<pRspQryNetFuncArea->ID<<std::endl;
  std::cout<<"on pRspQryNetFuncArea->SysNetSubAreaID:"<<pRspQryNetFuncArea->SysNetSubAreaID<<std::endl;
  std::cout<<"on pRspQryNetFuncArea->CName:"<<pRspQryNetFuncArea->CName<<std::endl;
  std::cout<<"on pRspQryNetFuncArea->EName:"<<pRspQryNetFuncArea->EName<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetFuncAreaField* pNewRspQryNetFuncArea =new CShfeFtdcRspQryNetFuncAreaField;
  memcpy(pNewRspQryNetFuncArea,pRspQryNetFuncArea,sizeof(CShfeFtdcRspQryNetFuncAreaField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetFuncArea;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetFuncAreaTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetFuncAreaTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetFuncAreaTopic(CShfeFtdcRtnNetFuncAreaField *pRtnNetFuncArea)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetFuncArea->OperationType:"<<pRtnNetFuncArea->OperationType<<std::endl;
  std::cout<<"on pRtnNetFuncArea->ID:"<<pRtnNetFuncArea->ID<<std::endl;
  std::cout<<"on pRtnNetFuncArea->SysNetSubAreaID:"<<pRtnNetFuncArea->SysNetSubAreaID<<std::endl;
  std::cout<<"on pRtnNetFuncArea->CName:"<<pRtnNetFuncArea->CName<<std::endl;
  std::cout<<"on pRtnNetFuncArea->EName:"<<pRtnNetFuncArea->EName<<std::endl;
  CShfeFtdcRtnNetFuncAreaField* pNewRtnNetFuncArea =new CShfeFtdcRtnNetFuncAreaField;
  memcpy(pNewRtnNetFuncArea,pRtnNetFuncArea,sizeof(CShfeFtdcRtnNetFuncAreaField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetFuncArea;
  asyncOnRtnNetFuncAreaTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetFuncAreaTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetMonitorCommandTypeTopic(CShfeFtdcRspQryNetMonitorCommandTypeField *pRspQryNetMonitorCommandType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetMonitorCommandType->OperationType:"<<pRspQryNetMonitorCommandType->OperationType<<std::endl;
  std::cout<<"on pRspQryNetMonitorCommandType->ID:"<<pRspQryNetMonitorCommandType->ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorCommandType->Manufactory_ID:"<<pRspQryNetMonitorCommandType->Manufactory_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorCommandType->MonitorType_ID:"<<pRspQryNetMonitorCommandType->MonitorType_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorCommandType->DeviceModle_ID:"<<pRspQryNetMonitorCommandType->DeviceModle_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorCommandType->ActionGroup_ID:"<<pRspQryNetMonitorCommandType->ActionGroup_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorCommandType->Manufactory:"<<pRspQryNetMonitorCommandType->Manufactory<<std::endl;
  std::cout<<"on pRspQryNetMonitorCommandType->MonitorType:"<<pRspQryNetMonitorCommandType->MonitorType<<std::endl;
  std::cout<<"on pRspQryNetMonitorCommandType->DeviceModle:"<<pRspQryNetMonitorCommandType->DeviceModle<<std::endl;
  std::cout<<"on pRspQryNetMonitorCommandType->ActionGroup:"<<pRspQryNetMonitorCommandType->ActionGroup<<std::endl;
  std::cout<<"on pRspQryNetMonitorCommandType->Command:"<<pRspQryNetMonitorCommandType->Command<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetMonitorCommandTypeField* pNewRspQryNetMonitorCommandType =new CShfeFtdcRspQryNetMonitorCommandTypeField;
  memcpy(pNewRspQryNetMonitorCommandType,pRspQryNetMonitorCommandType,sizeof(CShfeFtdcRspQryNetMonitorCommandTypeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorCommandType;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorCommandTypeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetMonitorCommandTypeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetMonitorCommandTypeTopic(CShfeFtdcRtnNetMonitorCommandTypeField *pRtnNetMonitorCommandType)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetMonitorCommandType->OperationType:"<<pRtnNetMonitorCommandType->OperationType<<std::endl;
  std::cout<<"on pRtnNetMonitorCommandType->ID:"<<pRtnNetMonitorCommandType->ID<<std::endl;
  std::cout<<"on pRtnNetMonitorCommandType->Manufactory_ID:"<<pRtnNetMonitorCommandType->Manufactory_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorCommandType->MonitorType_ID:"<<pRtnNetMonitorCommandType->MonitorType_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorCommandType->DeviceModle_ID:"<<pRtnNetMonitorCommandType->DeviceModle_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorCommandType->ActionGroup_ID:"<<pRtnNetMonitorCommandType->ActionGroup_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorCommandType->Manufactory:"<<pRtnNetMonitorCommandType->Manufactory<<std::endl;
  std::cout<<"on pRtnNetMonitorCommandType->MonitorType:"<<pRtnNetMonitorCommandType->MonitorType<<std::endl;
  std::cout<<"on pRtnNetMonitorCommandType->DeviceModle:"<<pRtnNetMonitorCommandType->DeviceModle<<std::endl;
  std::cout<<"on pRtnNetMonitorCommandType->ActionGroup:"<<pRtnNetMonitorCommandType->ActionGroup<<std::endl;
  std::cout<<"on pRtnNetMonitorCommandType->Command:"<<pRtnNetMonitorCommandType->Command<<std::endl;
  CShfeFtdcRtnNetMonitorCommandTypeField* pNewRtnNetMonitorCommandType =new CShfeFtdcRtnNetMonitorCommandTypeField;
  memcpy(pNewRtnNetMonitorCommandType,pRtnNetMonitorCommandType,sizeof(CShfeFtdcRtnNetMonitorCommandTypeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorCommandType;
  asyncOnRtnNetMonitorCommandTypeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetMonitorCommandTypeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetMonitorActionGroupTopic(CShfeFtdcRspQryNetMonitorActionGroupField *pRspQryNetMonitorActionGroup, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetMonitorActionGroup->OperationType:"<<pRspQryNetMonitorActionGroup->OperationType<<std::endl;
  std::cout<<"on pRspQryNetMonitorActionGroup->ID:"<<pRspQryNetMonitorActionGroup->ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorActionGroup->CName:"<<pRspQryNetMonitorActionGroup->CName<<std::endl;
  std::cout<<"on pRspQryNetMonitorActionGroup->EName:"<<pRspQryNetMonitorActionGroup->EName<<std::endl;
  std::cout<<"on pRspQryNetMonitorActionGroup->ActionType:"<<pRspQryNetMonitorActionGroup->ActionType<<std::endl;
  std::cout<<"on pRspQryNetMonitorActionGroup->Comments:"<<pRspQryNetMonitorActionGroup->Comments<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetMonitorActionGroupField* pNewRspQryNetMonitorActionGroup =new CShfeFtdcRspQryNetMonitorActionGroupField;
  memcpy(pNewRspQryNetMonitorActionGroup,pRspQryNetMonitorActionGroup,sizeof(CShfeFtdcRspQryNetMonitorActionGroupField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorActionGroup;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorActionGroupTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetMonitorActionGroupTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetMonitorActionGroupTopic(CShfeFtdcRtnNetMonitorActionGroupField *pRtnNetMonitorActionGroup)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetMonitorActionGroup->OperationType:"<<pRtnNetMonitorActionGroup->OperationType<<std::endl;
  std::cout<<"on pRtnNetMonitorActionGroup->ID:"<<pRtnNetMonitorActionGroup->ID<<std::endl;
  std::cout<<"on pRtnNetMonitorActionGroup->CName:"<<pRtnNetMonitorActionGroup->CName<<std::endl;
  std::cout<<"on pRtnNetMonitorActionGroup->EName:"<<pRtnNetMonitorActionGroup->EName<<std::endl;
  std::cout<<"on pRtnNetMonitorActionGroup->ActionType:"<<pRtnNetMonitorActionGroup->ActionType<<std::endl;
  std::cout<<"on pRtnNetMonitorActionGroup->Comments:"<<pRtnNetMonitorActionGroup->Comments<<std::endl;
  CShfeFtdcRtnNetMonitorActionGroupField* pNewRtnNetMonitorActionGroup =new CShfeFtdcRtnNetMonitorActionGroupField;
  memcpy(pNewRtnNetMonitorActionGroup,pRtnNetMonitorActionGroup,sizeof(CShfeFtdcRtnNetMonitorActionGroupField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorActionGroup;
  asyncOnRtnNetMonitorActionGroupTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetMonitorActionGroupTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetMonitorDeviceGroupTopic(CShfeFtdcRspQryNetMonitorDeviceGroupField *pRspQryNetMonitorDeviceGroup, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetMonitorDeviceGroup->OperationType:"<<pRspQryNetMonitorDeviceGroup->OperationType<<std::endl;
  std::cout<<"on pRspQryNetMonitorDeviceGroup->ID:"<<pRspQryNetMonitorDeviceGroup->ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorDeviceGroup->CName:"<<pRspQryNetMonitorDeviceGroup->CName<<std::endl;
  std::cout<<"on pRspQryNetMonitorDeviceGroup->EName:"<<pRspQryNetMonitorDeviceGroup->EName<<std::endl;
  std::cout<<"on pRspQryNetMonitorDeviceGroup->Condition:"<<pRspQryNetMonitorDeviceGroup->Condition<<std::endl;
  std::cout<<"on pRspQryNetMonitorDeviceGroup->Comments:"<<pRspQryNetMonitorDeviceGroup->Comments<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetMonitorDeviceGroupField* pNewRspQryNetMonitorDeviceGroup =new CShfeFtdcRspQryNetMonitorDeviceGroupField;
  memcpy(pNewRspQryNetMonitorDeviceGroup,pRspQryNetMonitorDeviceGroup,sizeof(CShfeFtdcRspQryNetMonitorDeviceGroupField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorDeviceGroup;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorDeviceGroupTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetMonitorDeviceGroupTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetMonitorDeviceGroupTopic(CShfeFtdcRtnNetMonitorDeviceGroupField *pRtnNetMonitorDeviceGroup)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetMonitorDeviceGroup->OperationType:"<<pRtnNetMonitorDeviceGroup->OperationType<<std::endl;
  std::cout<<"on pRtnNetMonitorDeviceGroup->ID:"<<pRtnNetMonitorDeviceGroup->ID<<std::endl;
  std::cout<<"on pRtnNetMonitorDeviceGroup->CName:"<<pRtnNetMonitorDeviceGroup->CName<<std::endl;
  std::cout<<"on pRtnNetMonitorDeviceGroup->EName:"<<pRtnNetMonitorDeviceGroup->EName<<std::endl;
  std::cout<<"on pRtnNetMonitorDeviceGroup->Condition:"<<pRtnNetMonitorDeviceGroup->Condition<<std::endl;
  std::cout<<"on pRtnNetMonitorDeviceGroup->Comments:"<<pRtnNetMonitorDeviceGroup->Comments<<std::endl;
  CShfeFtdcRtnNetMonitorDeviceGroupField* pNewRtnNetMonitorDeviceGroup =new CShfeFtdcRtnNetMonitorDeviceGroupField;
  memcpy(pNewRtnNetMonitorDeviceGroup,pRtnNetMonitorDeviceGroup,sizeof(CShfeFtdcRtnNetMonitorDeviceGroupField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorDeviceGroup;
  asyncOnRtnNetMonitorDeviceGroupTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetMonitorDeviceGroupTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetMonitorTaskInfoTopic(CShfeFtdcRspQryNetMonitorTaskInfoField *pRspQryNetMonitorTaskInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->OperationType:"<<pRspQryNetMonitorTaskInfo->OperationType<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->ID:"<<pRspQryNetMonitorTaskInfo->ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->CName:"<<pRspQryNetMonitorTaskInfo->CName<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->EName:"<<pRspQryNetMonitorTaskInfo->EName<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->DeviceGroup_ID:"<<pRspQryNetMonitorTaskInfo->DeviceGroup_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->ManagerGroup_ID:"<<pRspQryNetMonitorTaskInfo->ManagerGroup_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->TimePolicy_ID:"<<pRspQryNetMonitorTaskInfo->TimePolicy_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->TaskPriority_ID:"<<pRspQryNetMonitorTaskInfo->TaskPriority_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->OutputPolicy_ID:"<<pRspQryNetMonitorTaskInfo->OutputPolicy_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->ActionGroup_ID:"<<pRspQryNetMonitorTaskInfo->ActionGroup_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->EventExprStr:"<<pRspQryNetMonitorTaskInfo->EventExprStr<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->DeviceGroup:"<<pRspQryNetMonitorTaskInfo->DeviceGroup<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->ManagerGroup:"<<pRspQryNetMonitorTaskInfo->ManagerGroup<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->TimePolicy:"<<pRspQryNetMonitorTaskInfo->TimePolicy<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->TaskPriority:"<<pRspQryNetMonitorTaskInfo->TaskPriority<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->OutputPolicy:"<<pRspQryNetMonitorTaskInfo->OutputPolicy<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->ActionGroup:"<<pRspQryNetMonitorTaskInfo->ActionGroup<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->ValidFlag:"<<pRspQryNetMonitorTaskInfo->ValidFlag<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->TaskStatus:"<<pRspQryNetMonitorTaskInfo->TaskStatus<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInfo->Comments:"<<pRspQryNetMonitorTaskInfo->Comments<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetMonitorTaskInfoField* pNewRspQryNetMonitorTaskInfo =new CShfeFtdcRspQryNetMonitorTaskInfoField;
  memcpy(pNewRspQryNetMonitorTaskInfo,pRspQryNetMonitorTaskInfo,sizeof(CShfeFtdcRspQryNetMonitorTaskInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorTaskInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorTaskInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetMonitorTaskInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetMonitorTaskInfoTopic(CShfeFtdcRtnNetMonitorTaskInfoField *pRtnNetMonitorTaskInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->OperationType:"<<pRtnNetMonitorTaskInfo->OperationType<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->ID:"<<pRtnNetMonitorTaskInfo->ID<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->CName:"<<pRtnNetMonitorTaskInfo->CName<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->EName:"<<pRtnNetMonitorTaskInfo->EName<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->DeviceGroup_ID:"<<pRtnNetMonitorTaskInfo->DeviceGroup_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->ManagerGroup_ID:"<<pRtnNetMonitorTaskInfo->ManagerGroup_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->TimePolicy_ID:"<<pRtnNetMonitorTaskInfo->TimePolicy_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->TaskPriority_ID:"<<pRtnNetMonitorTaskInfo->TaskPriority_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->OutputPolicy_ID:"<<pRtnNetMonitorTaskInfo->OutputPolicy_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->ActionGroup_ID:"<<pRtnNetMonitorTaskInfo->ActionGroup_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->EventExprStr:"<<pRtnNetMonitorTaskInfo->EventExprStr<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->DeviceGroup:"<<pRtnNetMonitorTaskInfo->DeviceGroup<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->ManagerGroup:"<<pRtnNetMonitorTaskInfo->ManagerGroup<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->TimePolicy:"<<pRtnNetMonitorTaskInfo->TimePolicy<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->TaskPriority:"<<pRtnNetMonitorTaskInfo->TaskPriority<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->OutputPolicy:"<<pRtnNetMonitorTaskInfo->OutputPolicy<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->ActionGroup:"<<pRtnNetMonitorTaskInfo->ActionGroup<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->ValidFlag:"<<pRtnNetMonitorTaskInfo->ValidFlag<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->TaskStatus:"<<pRtnNetMonitorTaskInfo->TaskStatus<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInfo->Comments:"<<pRtnNetMonitorTaskInfo->Comments<<std::endl;
  CShfeFtdcRtnNetMonitorTaskInfoField* pNewRtnNetMonitorTaskInfo =new CShfeFtdcRtnNetMonitorTaskInfoField;
  memcpy(pNewRtnNetMonitorTaskInfo,pRtnNetMonitorTaskInfo,sizeof(CShfeFtdcRtnNetMonitorTaskInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorTaskInfo;
  asyncOnRtnNetMonitorTaskInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetMonitorTaskInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetMonitorTaskResultTopic(CShfeFtdcRspQryNetMonitorTaskResultField *pRspQryNetMonitorTaskResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskResult->OperationType:"<<pRspQryNetMonitorTaskResult->OperationType<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskResult->ObjectID:"<<pRspQryNetMonitorTaskResult->ObjectID<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskResult->Task_ID:"<<pRspQryNetMonitorTaskResult->Task_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskResult->OperateTime:"<<pRspQryNetMonitorTaskResult->OperateTime<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskResult->MonDate:"<<pRspQryNetMonitorTaskResult->MonDate<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskResult->MonTime:"<<pRspQryNetMonitorTaskResult->MonTime<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskResult->InstructChain:"<<pRspQryNetMonitorTaskResult->InstructChain<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskResult->ResultChain:"<<pRspQryNetMonitorTaskResult->ResultChain<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskResult->Flag:"<<pRspQryNetMonitorTaskResult->Flag<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetMonitorTaskResultField* pNewRspQryNetMonitorTaskResult =new CShfeFtdcRspQryNetMonitorTaskResultField;
  memcpy(pNewRspQryNetMonitorTaskResult,pRspQryNetMonitorTaskResult,sizeof(CShfeFtdcRspQryNetMonitorTaskResultField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorTaskResult;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorTaskResultTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetMonitorTaskResultTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetMonitorTaskResultTopic(CShfeFtdcRtnNetMonitorTaskResultField *pRtnNetMonitorTaskResult)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskResult->OperationType:"<<pRtnNetMonitorTaskResult->OperationType<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskResult->ObjectID:"<<pRtnNetMonitorTaskResult->ObjectID<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskResult->Task_ID:"<<pRtnNetMonitorTaskResult->Task_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskResult->OperateTime:"<<pRtnNetMonitorTaskResult->OperateTime<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskResult->MonDate:"<<pRtnNetMonitorTaskResult->MonDate<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskResult->MonTime:"<<pRtnNetMonitorTaskResult->MonTime<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskResult->InstructChain:"<<pRtnNetMonitorTaskResult->InstructChain<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskResult->ResultChain:"<<pRtnNetMonitorTaskResult->ResultChain<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskResult->Flag:"<<pRtnNetMonitorTaskResult->Flag<<std::endl;
  CShfeFtdcRtnNetMonitorTaskResultField* pNewRtnNetMonitorTaskResult =new CShfeFtdcRtnNetMonitorTaskResultField;
  memcpy(pNewRtnNetMonitorTaskResult,pRtnNetMonitorTaskResult,sizeof(CShfeFtdcRtnNetMonitorTaskResultField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorTaskResult;
  asyncOnRtnNetMonitorTaskResultTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetMonitorTaskResultTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetMonitorTaskObjectSetTopic(CShfeFtdcRspQryNetMonitorTaskObjectSetField *pRspQryNetMonitorTaskObjectSet, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskObjectSet->OperationType:"<<pRspQryNetMonitorTaskObjectSet->OperationType<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskObjectSet->ID:"<<pRspQryNetMonitorTaskObjectSet->ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskObjectSet->DeviceGroup_ID:"<<pRspQryNetMonitorTaskObjectSet->DeviceGroup_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskObjectSet->Device_ID:"<<pRspQryNetMonitorTaskObjectSet->Device_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskObjectSet->DataCenter:"<<pRspQryNetMonitorTaskObjectSet->DataCenter<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetMonitorTaskObjectSetField* pNewRspQryNetMonitorTaskObjectSet =new CShfeFtdcRspQryNetMonitorTaskObjectSetField;
  memcpy(pNewRspQryNetMonitorTaskObjectSet,pRspQryNetMonitorTaskObjectSet,sizeof(CShfeFtdcRspQryNetMonitorTaskObjectSetField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorTaskObjectSet;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorTaskObjectSetTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetMonitorTaskObjectSetTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetMonitorTaskObjectSetTopic(CShfeFtdcRtnNetMonitorTaskObjectSetField *pRtnNetMonitorTaskObjectSet)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskObjectSet->OperationType:"<<pRtnNetMonitorTaskObjectSet->OperationType<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskObjectSet->ID:"<<pRtnNetMonitorTaskObjectSet->ID<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskObjectSet->DeviceGroup_ID:"<<pRtnNetMonitorTaskObjectSet->DeviceGroup_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskObjectSet->Device_ID:"<<pRtnNetMonitorTaskObjectSet->Device_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskObjectSet->DataCenter:"<<pRtnNetMonitorTaskObjectSet->DataCenter<<std::endl;
  CShfeFtdcRtnNetMonitorTaskObjectSetField* pNewRtnNetMonitorTaskObjectSet =new CShfeFtdcRtnNetMonitorTaskObjectSetField;
  memcpy(pNewRtnNetMonitorTaskObjectSet,pRtnNetMonitorTaskObjectSet,sizeof(CShfeFtdcRtnNetMonitorTaskObjectSetField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorTaskObjectSet;
  asyncOnRtnNetMonitorTaskObjectSetTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetMonitorTaskObjectSetTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetPartyLinkInfoTopic(CShfeFtdcRspQryNetPartyLinkInfoField *pRspQryNetPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->OperationType:"<<pRspQryNetPartyLinkInfo->OperationType<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->ID:"<<pRspQryNetPartyLinkInfo->ID<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->MEMBER_NO:"<<pRspQryNetPartyLinkInfo->MEMBER_NO<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->MEMBER_NAME:"<<pRspQryNetPartyLinkInfo->MEMBER_NAME<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->REMOTE_ADDR:"<<pRspQryNetPartyLinkInfo->REMOTE_ADDR<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->LOCAL_ADDR:"<<pRspQryNetPartyLinkInfo->LOCAL_ADDR<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->ADDRESS:"<<pRspQryNetPartyLinkInfo->ADDRESS<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->LINE_STATUS:"<<pRspQryNetPartyLinkInfo->LINE_STATUS<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->CONTACT:"<<pRspQryNetPartyLinkInfo->CONTACT<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->TELEPHONE:"<<pRspQryNetPartyLinkInfo->TELEPHONE<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->MOBILEPHONE:"<<pRspQryNetPartyLinkInfo->MOBILEPHONE<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->EMAIL:"<<pRspQryNetPartyLinkInfo->EMAIL<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->FAX:"<<pRspQryNetPartyLinkInfo->FAX<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->PROVINCE:"<<pRspQryNetPartyLinkInfo->PROVINCE<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->DDN_NO:"<<pRspQryNetPartyLinkInfo->DDN_NO<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->IN_MODE:"<<pRspQryNetPartyLinkInfo->IN_MODE<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->IP_WAN:"<<pRspQryNetPartyLinkInfo->IP_WAN<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->IP_LAN:"<<pRspQryNetPartyLinkInfo->IP_LAN<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->IPADDR:"<<pRspQryNetPartyLinkInfo->IPADDR<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->Interface:"<<pRspQryNetPartyLinkInfo->Interface<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->INTERFACE_DATE:"<<pRspQryNetPartyLinkInfo->INTERFACE_DATE<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->SOFTWARE:"<<pRspQryNetPartyLinkInfo->SOFTWARE<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->FEE_TYPE:"<<pRspQryNetPartyLinkInfo->FEE_TYPE<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->SERVICEPROVIDER:"<<pRspQryNetPartyLinkInfo->SERVICEPROVIDER<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->IF_ZIYING:"<<pRspQryNetPartyLinkInfo->IF_ZIYING<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->IF_TUOGUAN:"<<pRspQryNetPartyLinkInfo->IF_TUOGUAN<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->HASOTHER:"<<pRspQryNetPartyLinkInfo->HASOTHER<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->SEAT_NO:"<<pRspQryNetPartyLinkInfo->SEAT_NO<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkInfo->PRO:"<<pRspQryNetPartyLinkInfo->PRO<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetPartyLinkInfoField* pNewRspQryNetPartyLinkInfo =new CShfeFtdcRspQryNetPartyLinkInfoField;
  memcpy(pNewRspQryNetPartyLinkInfo,pRspQryNetPartyLinkInfo,sizeof(CShfeFtdcRspQryNetPartyLinkInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetPartyLinkInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetPartyLinkInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetPartyLinkInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetPartyLinkInfoTopic(CShfeFtdcRtnNetPartyLinkInfoField *pRtnNetPartyLinkInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->OperationType:"<<pRtnNetPartyLinkInfo->OperationType<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->ID:"<<pRtnNetPartyLinkInfo->ID<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->MEMBER_NO:"<<pRtnNetPartyLinkInfo->MEMBER_NO<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->MEMBER_NAME:"<<pRtnNetPartyLinkInfo->MEMBER_NAME<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->REMOTE_ADDR:"<<pRtnNetPartyLinkInfo->REMOTE_ADDR<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->LOCAL_ADDR:"<<pRtnNetPartyLinkInfo->LOCAL_ADDR<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->ADDRESS:"<<pRtnNetPartyLinkInfo->ADDRESS<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->LINE_STATUS:"<<pRtnNetPartyLinkInfo->LINE_STATUS<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->CONTACT:"<<pRtnNetPartyLinkInfo->CONTACT<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->TELEPHONE:"<<pRtnNetPartyLinkInfo->TELEPHONE<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->MOBILEPHONE:"<<pRtnNetPartyLinkInfo->MOBILEPHONE<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->EMAIL:"<<pRtnNetPartyLinkInfo->EMAIL<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->FAX:"<<pRtnNetPartyLinkInfo->FAX<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->PROVINCE:"<<pRtnNetPartyLinkInfo->PROVINCE<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->DDN_NO:"<<pRtnNetPartyLinkInfo->DDN_NO<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->IN_MODE:"<<pRtnNetPartyLinkInfo->IN_MODE<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->IP_WAN:"<<pRtnNetPartyLinkInfo->IP_WAN<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->IP_LAN:"<<pRtnNetPartyLinkInfo->IP_LAN<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->IPADDR:"<<pRtnNetPartyLinkInfo->IPADDR<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->Interface:"<<pRtnNetPartyLinkInfo->Interface<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->INTERFACE_DATE:"<<pRtnNetPartyLinkInfo->INTERFACE_DATE<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->SOFTWARE:"<<pRtnNetPartyLinkInfo->SOFTWARE<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->FEE_TYPE:"<<pRtnNetPartyLinkInfo->FEE_TYPE<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->SERVICEPROVIDER:"<<pRtnNetPartyLinkInfo->SERVICEPROVIDER<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->IF_ZIYING:"<<pRtnNetPartyLinkInfo->IF_ZIYING<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->IF_TUOGUAN:"<<pRtnNetPartyLinkInfo->IF_TUOGUAN<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->HASOTHER:"<<pRtnNetPartyLinkInfo->HASOTHER<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->SEAT_NO:"<<pRtnNetPartyLinkInfo->SEAT_NO<<std::endl;
  std::cout<<"on pRtnNetPartyLinkInfo->PRO:"<<pRtnNetPartyLinkInfo->PRO<<std::endl;
  CShfeFtdcRtnNetPartyLinkInfoField* pNewRtnNetPartyLinkInfo =new CShfeFtdcRtnNetPartyLinkInfoField;
  memcpy(pNewRtnNetPartyLinkInfo,pRtnNetPartyLinkInfo,sizeof(CShfeFtdcRtnNetPartyLinkInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetPartyLinkInfo;
  asyncOnRtnNetPartyLinkInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetPartyLinkInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetMonitorActionAttrTopic(CShfeFtdcRspQryNetMonitorActionAttrField *pRspQryNetMonitorActionAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetMonitorActionAttr->OperationType:"<<pRspQryNetMonitorActionAttr->OperationType<<std::endl;
  std::cout<<"on pRspQryNetMonitorActionAttr->ID:"<<pRspQryNetMonitorActionAttr->ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorActionAttr->ActionGroup_ID:"<<pRspQryNetMonitorActionAttr->ActionGroup_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorActionAttr->MonitorAttr_ID:"<<pRspQryNetMonitorActionAttr->MonitorAttr_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorActionAttr->MonitorAttrName:"<<pRspQryNetMonitorActionAttr->MonitorAttrName<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetMonitorActionAttrField* pNewRspQryNetMonitorActionAttr =new CShfeFtdcRspQryNetMonitorActionAttrField;
  memcpy(pNewRspQryNetMonitorActionAttr,pRspQryNetMonitorActionAttr,sizeof(CShfeFtdcRspQryNetMonitorActionAttrField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorActionAttr;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorActionAttrTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetMonitorActionAttrTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetMonitorActionAttrTopic(CShfeFtdcRtnNetMonitorActionAttrField *pRtnNetMonitorActionAttr)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetMonitorActionAttr->OperationType:"<<pRtnNetMonitorActionAttr->OperationType<<std::endl;
  std::cout<<"on pRtnNetMonitorActionAttr->ID:"<<pRtnNetMonitorActionAttr->ID<<std::endl;
  std::cout<<"on pRtnNetMonitorActionAttr->ActionGroup_ID:"<<pRtnNetMonitorActionAttr->ActionGroup_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorActionAttr->MonitorAttr_ID:"<<pRtnNetMonitorActionAttr->MonitorAttr_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorActionAttr->MonitorAttrName:"<<pRtnNetMonitorActionAttr->MonitorAttrName<<std::endl;
  CShfeFtdcRtnNetMonitorActionAttrField* pNewRtnNetMonitorActionAttr =new CShfeFtdcRtnNetMonitorActionAttrField;
  memcpy(pNewRtnNetMonitorActionAttr,pRtnNetMonitorActionAttr,sizeof(CShfeFtdcRtnNetMonitorActionAttrField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorActionAttr;
  asyncOnRtnNetMonitorActionAttrTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetMonitorActionAttrTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetModuleTopic(CShfeFtdcRspQryNetModuleField *pRspQryNetModule, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetModule->OperationType:"<<pRspQryNetModule->OperationType<<std::endl;
  std::cout<<"on pRspQryNetModule->ID:"<<pRspQryNetModule->ID<<std::endl;
  std::cout<<"on pRspQryNetModule->ObjectID:"<<pRspQryNetModule->ObjectID<<std::endl;
  std::cout<<"on pRspQryNetModule->MonitorType_ID:"<<pRspQryNetModule->MonitorType_ID<<std::endl;
  std::cout<<"on pRspQryNetModule->DeviceID:"<<pRspQryNetModule->DeviceID<<std::endl;
  std::cout<<"on pRspQryNetModule->DeviceObjectID:"<<pRspQryNetModule->DeviceObjectID<<std::endl;
  std::cout<<"on pRspQryNetModule->Name:"<<pRspQryNetModule->Name<<std::endl;
  std::cout<<"on pRspQryNetModule->Description:"<<pRspQryNetModule->Description<<std::endl;
  std::cout<<"on pRspQryNetModule->ModuleIndex:"<<pRspQryNetModule->ModuleIndex<<std::endl;
  std::cout<<"on pRspQryNetModule->EntPhyIndex:"<<pRspQryNetModule->EntPhyIndex<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetModuleField* pNewRspQryNetModule =new CShfeFtdcRspQryNetModuleField;
  memcpy(pNewRspQryNetModule,pRspQryNetModule,sizeof(CShfeFtdcRspQryNetModuleField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetModule;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetModuleTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetModuleTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetModuleTopic(CShfeFtdcRtnNetModuleField *pRtnNetModule)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetModule->OperationType:"<<pRtnNetModule->OperationType<<std::endl;
  std::cout<<"on pRtnNetModule->ID:"<<pRtnNetModule->ID<<std::endl;
  std::cout<<"on pRtnNetModule->ObjectID:"<<pRtnNetModule->ObjectID<<std::endl;
  std::cout<<"on pRtnNetModule->MonitorType_ID:"<<pRtnNetModule->MonitorType_ID<<std::endl;
  std::cout<<"on pRtnNetModule->DeviceID:"<<pRtnNetModule->DeviceID<<std::endl;
  std::cout<<"on pRtnNetModule->DeviceObjectID:"<<pRtnNetModule->DeviceObjectID<<std::endl;
  std::cout<<"on pRtnNetModule->Name:"<<pRtnNetModule->Name<<std::endl;
  std::cout<<"on pRtnNetModule->Description:"<<pRtnNetModule->Description<<std::endl;
  std::cout<<"on pRtnNetModule->ModuleIndex:"<<pRtnNetModule->ModuleIndex<<std::endl;
  std::cout<<"on pRtnNetModule->EntPhyIndex:"<<pRtnNetModule->EntPhyIndex<<std::endl;
  CShfeFtdcRtnNetModuleField* pNewRtnNetModule =new CShfeFtdcRtnNetModuleField;
  memcpy(pNewRtnNetModule,pRtnNetModule,sizeof(CShfeFtdcRtnNetModuleField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetModule;
  asyncOnRtnNetModuleTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetModuleTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetEventExprTopic(CShfeFtdcRspQryNetEventExprField *pRspQryNetEventExpr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetEventExpr->OperationType:"<<pRspQryNetEventExpr->OperationType<<std::endl;
  std::cout<<"on pRspQryNetEventExpr->ID:"<<pRspQryNetEventExpr->ID<<std::endl;
  std::cout<<"on pRspQryNetEventExpr->CNAME:"<<pRspQryNetEventExpr->CNAME<<std::endl;
  std::cout<<"on pRspQryNetEventExpr->ENAME:"<<pRspQryNetEventExpr->ENAME<<std::endl;
  std::cout<<"on pRspQryNetEventExpr->WarningLEVEL:"<<pRspQryNetEventExpr->WarningLEVEL<<std::endl;
  std::cout<<"on pRspQryNetEventExpr->EventTypeID:"<<pRspQryNetEventExpr->EventTypeID<<std::endl;
  std::cout<<"on pRspQryNetEventExpr->SubEventTypeID:"<<pRspQryNetEventExpr->SubEventTypeID<<std::endl;
  std::cout<<"on pRspQryNetEventExpr->GIVEUPTIME:"<<pRspQryNetEventExpr->GIVEUPTIME<<std::endl;
  std::cout<<"on pRspQryNetEventExpr->CONTROL:"<<pRspQryNetEventExpr->CONTROL<<std::endl;
  std::cout<<"on pRspQryNetEventExpr->EXPR:"<<pRspQryNetEventExpr->EXPR<<std::endl;
  std::cout<<"on pRspQryNetEventExpr->BRIEF:"<<pRspQryNetEventExpr->BRIEF<<std::endl;
  std::cout<<"on pRspQryNetEventExpr->DISCRIPTION:"<<pRspQryNetEventExpr->DISCRIPTION<<std::endl;
  std::cout<<"on pRspQryNetEventExpr->MSGGROUP_ID:"<<pRspQryNetEventExpr->MSGGROUP_ID<<std::endl;
  std::cout<<"on pRspQryNetEventExpr->ADMINGROUP_ID:"<<pRspQryNetEventExpr->ADMINGROUP_ID<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetEventExprField* pNewRspQryNetEventExpr =new CShfeFtdcRspQryNetEventExprField;
  memcpy(pNewRspQryNetEventExpr,pRspQryNetEventExpr,sizeof(CShfeFtdcRspQryNetEventExprField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetEventExpr;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetEventExprTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetEventExprTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetEventExprTopic(CShfeFtdcRtnNetEventExprField *pRtnNetEventExpr)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetEventExpr->OperationType:"<<pRtnNetEventExpr->OperationType<<std::endl;
  std::cout<<"on pRtnNetEventExpr->ID:"<<pRtnNetEventExpr->ID<<std::endl;
  std::cout<<"on pRtnNetEventExpr->CNAME:"<<pRtnNetEventExpr->CNAME<<std::endl;
  std::cout<<"on pRtnNetEventExpr->ENAME:"<<pRtnNetEventExpr->ENAME<<std::endl;
  std::cout<<"on pRtnNetEventExpr->WarningLEVEL:"<<pRtnNetEventExpr->WarningLEVEL<<std::endl;
  std::cout<<"on pRtnNetEventExpr->EventTypeID:"<<pRtnNetEventExpr->EventTypeID<<std::endl;
  std::cout<<"on pRtnNetEventExpr->SubEventTypeID:"<<pRtnNetEventExpr->SubEventTypeID<<std::endl;
  std::cout<<"on pRtnNetEventExpr->GIVEUPTIME:"<<pRtnNetEventExpr->GIVEUPTIME<<std::endl;
  std::cout<<"on pRtnNetEventExpr->CONTROL:"<<pRtnNetEventExpr->CONTROL<<std::endl;
  std::cout<<"on pRtnNetEventExpr->EXPR:"<<pRtnNetEventExpr->EXPR<<std::endl;
  std::cout<<"on pRtnNetEventExpr->BRIEF:"<<pRtnNetEventExpr->BRIEF<<std::endl;
  std::cout<<"on pRtnNetEventExpr->DISCRIPTION:"<<pRtnNetEventExpr->DISCRIPTION<<std::endl;
  std::cout<<"on pRtnNetEventExpr->MSGGROUP_ID:"<<pRtnNetEventExpr->MSGGROUP_ID<<std::endl;
  std::cout<<"on pRtnNetEventExpr->ADMINGROUP_ID:"<<pRtnNetEventExpr->ADMINGROUP_ID<<std::endl;
  CShfeFtdcRtnNetEventExprField* pNewRtnNetEventExpr =new CShfeFtdcRtnNetEventExprField;
  memcpy(pNewRtnNetEventExpr,pRtnNetEventExpr,sizeof(CShfeFtdcRtnNetEventExprField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetEventExpr;
  asyncOnRtnNetEventExprTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetEventExprTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetEventTypeTopic(CShfeFtdcRspQryNetEventTypeField *pRspQryNetEventType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetEventType->OperationType:"<<pRspQryNetEventType->OperationType<<std::endl;
  std::cout<<"on pRspQryNetEventType->ID:"<<pRspQryNetEventType->ID<<std::endl;
  std::cout<<"on pRspQryNetEventType->CName:"<<pRspQryNetEventType->CName<<std::endl;
  std::cout<<"on pRspQryNetEventType->EName:"<<pRspQryNetEventType->EName<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetEventTypeField* pNewRspQryNetEventType =new CShfeFtdcRspQryNetEventTypeField;
  memcpy(pNewRspQryNetEventType,pRspQryNetEventType,sizeof(CShfeFtdcRspQryNetEventTypeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetEventType;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetEventTypeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetEventTypeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetEventTypeTopic(CShfeFtdcRtnNetEventTypeField *pRtnNetEventType)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetEventType->OperationType:"<<pRtnNetEventType->OperationType<<std::endl;
  std::cout<<"on pRtnNetEventType->ID:"<<pRtnNetEventType->ID<<std::endl;
  std::cout<<"on pRtnNetEventType->CName:"<<pRtnNetEventType->CName<<std::endl;
  std::cout<<"on pRtnNetEventType->EName:"<<pRtnNetEventType->EName<<std::endl;
  CShfeFtdcRtnNetEventTypeField* pNewRtnNetEventType =new CShfeFtdcRtnNetEventTypeField;
  memcpy(pNewRtnNetEventType,pRtnNetEventType,sizeof(CShfeFtdcRtnNetEventTypeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetEventType;
  asyncOnRtnNetEventTypeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetEventTypeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetSubEventTypeTopic(CShfeFtdcRspQryNetSubEventTypeField *pRspQryNetSubEventType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetSubEventType->OperationType:"<<pRspQryNetSubEventType->OperationType<<std::endl;
  std::cout<<"on pRspQryNetSubEventType->ID:"<<pRspQryNetSubEventType->ID<<std::endl;
  std::cout<<"on pRspQryNetSubEventType->CName:"<<pRspQryNetSubEventType->CName<<std::endl;
  std::cout<<"on pRspQryNetSubEventType->EName:"<<pRspQryNetSubEventType->EName<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetSubEventTypeField* pNewRspQryNetSubEventType =new CShfeFtdcRspQryNetSubEventTypeField;
  memcpy(pNewRspQryNetSubEventType,pRspQryNetSubEventType,sizeof(CShfeFtdcRspQryNetSubEventTypeField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetSubEventType;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetSubEventTypeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetSubEventTypeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetSubEventTypeTopic(CShfeFtdcRtnNetSubEventTypeField *pRtnNetSubEventType)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetSubEventType->OperationType:"<<pRtnNetSubEventType->OperationType<<std::endl;
  std::cout<<"on pRtnNetSubEventType->ID:"<<pRtnNetSubEventType->ID<<std::endl;
  std::cout<<"on pRtnNetSubEventType->CName:"<<pRtnNetSubEventType->CName<<std::endl;
  std::cout<<"on pRtnNetSubEventType->EName:"<<pRtnNetSubEventType->EName<<std::endl;
  CShfeFtdcRtnNetSubEventTypeField* pNewRtnNetSubEventType =new CShfeFtdcRtnNetSubEventTypeField;
  memcpy(pNewRtnNetSubEventType,pRtnNetSubEventType,sizeof(CShfeFtdcRtnNetSubEventTypeField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetSubEventType;
  asyncOnRtnNetSubEventTypeTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetSubEventTypeTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetEventLevelTopic(CShfeFtdcRspQryNetEventLevelField *pRspQryNetEventLevel, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetEventLevel->OperationType:"<<pRspQryNetEventLevel->OperationType<<std::endl;
  std::cout<<"on pRspQryNetEventLevel->ID:"<<pRspQryNetEventLevel->ID<<std::endl;
  std::cout<<"on pRspQryNetEventLevel->CName:"<<pRspQryNetEventLevel->CName<<std::endl;
  std::cout<<"on pRspQryNetEventLevel->EName:"<<pRspQryNetEventLevel->EName<<std::endl;
  std::cout<<"on pRspQryNetEventLevel->DISCRIPTION:"<<pRspQryNetEventLevel->DISCRIPTION<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetEventLevelField* pNewRspQryNetEventLevel =new CShfeFtdcRspQryNetEventLevelField;
  memcpy(pNewRspQryNetEventLevel,pRspQryNetEventLevel,sizeof(CShfeFtdcRspQryNetEventLevelField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetEventLevel;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetEventLevelTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetEventLevelTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetEventLevelTopic(CShfeFtdcRtnNetEventLevelField *pRtnNetEventLevel)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetEventLevel->OperationType:"<<pRtnNetEventLevel->OperationType<<std::endl;
  std::cout<<"on pRtnNetEventLevel->ID:"<<pRtnNetEventLevel->ID<<std::endl;
  std::cout<<"on pRtnNetEventLevel->CName:"<<pRtnNetEventLevel->CName<<std::endl;
  std::cout<<"on pRtnNetEventLevel->EName:"<<pRtnNetEventLevel->EName<<std::endl;
  std::cout<<"on pRtnNetEventLevel->DISCRIPTION:"<<pRtnNetEventLevel->DISCRIPTION<<std::endl;
  CShfeFtdcRtnNetEventLevelField* pNewRtnNetEventLevel =new CShfeFtdcRtnNetEventLevelField;
  memcpy(pNewRtnNetEventLevel,pRtnNetEventLevel,sizeof(CShfeFtdcRtnNetEventLevelField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetEventLevel;
  asyncOnRtnNetEventLevelTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetEventLevelTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetMonitorTaskStatusResultTopic(CShfeFtdcRspQryNetMonitorTaskStatusResultField *pRspQryNetMonitorTaskStatusResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskStatusResult->OperationType:"<<pRspQryNetMonitorTaskStatusResult->OperationType<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskStatusResult->ObjectID:"<<pRspQryNetMonitorTaskStatusResult->ObjectID<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskStatusResult->Task_ID:"<<pRspQryNetMonitorTaskStatusResult->Task_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskStatusResult->OperateTime:"<<pRspQryNetMonitorTaskStatusResult->OperateTime<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskStatusResult->MonDate:"<<pRspQryNetMonitorTaskStatusResult->MonDate<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskStatusResult->MonTime:"<<pRspQryNetMonitorTaskStatusResult->MonTime<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskStatusResult->Flag:"<<pRspQryNetMonitorTaskStatusResult->Flag<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetMonitorTaskStatusResultField* pNewRspQryNetMonitorTaskStatusResult =new CShfeFtdcRspQryNetMonitorTaskStatusResultField;
  memcpy(pNewRspQryNetMonitorTaskStatusResult,pRspQryNetMonitorTaskStatusResult,sizeof(CShfeFtdcRspQryNetMonitorTaskStatusResultField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorTaskStatusResult;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorTaskStatusResultTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetMonitorTaskStatusResultTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetMonitorTaskStatusResultTopic(CShfeFtdcRtnNetMonitorTaskStatusResultField *pRtnNetMonitorTaskStatusResult)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskStatusResult->OperationType:"<<pRtnNetMonitorTaskStatusResult->OperationType<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskStatusResult->ObjectID:"<<pRtnNetMonitorTaskStatusResult->ObjectID<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskStatusResult->Task_ID:"<<pRtnNetMonitorTaskStatusResult->Task_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskStatusResult->OperateTime:"<<pRtnNetMonitorTaskStatusResult->OperateTime<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskStatusResult->MonDate:"<<pRtnNetMonitorTaskStatusResult->MonDate<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskStatusResult->MonTime:"<<pRtnNetMonitorTaskStatusResult->MonTime<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskStatusResult->Flag:"<<pRtnNetMonitorTaskStatusResult->Flag<<std::endl;
  CShfeFtdcRtnNetMonitorTaskStatusResultField* pNewRtnNetMonitorTaskStatusResult =new CShfeFtdcRtnNetMonitorTaskStatusResultField;
  memcpy(pNewRtnNetMonitorTaskStatusResult,pRtnNetMonitorTaskStatusResult,sizeof(CShfeFtdcRtnNetMonitorTaskStatusResultField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorTaskStatusResult;
  asyncOnRtnNetMonitorTaskStatusResultTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetMonitorTaskStatusResultTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetCfgFileTopic(CShfeFtdcRspQryNetCfgFileField *pRspQryNetCfgFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetCfgFile->OperationType:"<<pRspQryNetCfgFile->OperationType<<std::endl;
  std::cout<<"on pRspQryNetCfgFile->ObjectID:"<<pRspQryNetCfgFile->ObjectID<<std::endl;
  std::cout<<"on pRspQryNetCfgFile->MonDate:"<<pRspQryNetCfgFile->MonDate<<std::endl;
  std::cout<<"on pRspQryNetCfgFile->MonTime:"<<pRspQryNetCfgFile->MonTime<<std::endl;
  std::cout<<"on pRspQryNetCfgFile->CfgFileName:"<<pRspQryNetCfgFile->CfgFileName<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetCfgFileField* pNewRspQryNetCfgFile =new CShfeFtdcRspQryNetCfgFileField;
  memcpy(pNewRspQryNetCfgFile,pRspQryNetCfgFile,sizeof(CShfeFtdcRspQryNetCfgFileField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetCfgFile;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetCfgFileTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetCfgFileTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetCfgFileTopic(CShfeFtdcRtnNetCfgFileField *pRtnNetCfgFile)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetCfgFile->OperationType:"<<pRtnNetCfgFile->OperationType<<std::endl;
  std::cout<<"on pRtnNetCfgFile->ObjectID:"<<pRtnNetCfgFile->ObjectID<<std::endl;
  std::cout<<"on pRtnNetCfgFile->MonDate:"<<pRtnNetCfgFile->MonDate<<std::endl;
  std::cout<<"on pRtnNetCfgFile->MonTime:"<<pRtnNetCfgFile->MonTime<<std::endl;
  std::cout<<"on pRtnNetCfgFile->CfgFileName:"<<pRtnNetCfgFile->CfgFileName<<std::endl;
  CShfeFtdcRtnNetCfgFileField* pNewRtnNetCfgFile =new CShfeFtdcRtnNetCfgFileField;
  memcpy(pNewRtnNetCfgFile,pRtnNetCfgFile,sizeof(CShfeFtdcRtnNetCfgFileField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetCfgFile;
  asyncOnRtnNetCfgFileTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetCfgFileTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetMonitorDeviceTaskTopic(CShfeFtdcRspQryNetMonitorDeviceTaskField *pRspQryNetMonitorDeviceTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetMonitorDeviceTask->OperationType:"<<pRspQryNetMonitorDeviceTask->OperationType<<std::endl;
  std::cout<<"on pRspQryNetMonitorDeviceTask->ID:"<<pRspQryNetMonitorDeviceTask->ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorDeviceTask->ObjectID:"<<pRspQryNetMonitorDeviceTask->ObjectID<<std::endl;
  std::cout<<"on pRspQryNetMonitorDeviceTask->IPAddress:"<<pRspQryNetMonitorDeviceTask->IPAddress<<std::endl;
  std::cout<<"on pRspQryNetMonitorDeviceTask->Manufactory_ID:"<<pRspQryNetMonitorDeviceTask->Manufactory_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorDeviceTask->InstructChain:"<<pRspQryNetMonitorDeviceTask->InstructChain<<std::endl;
  std::cout<<"on pRspQryNetMonitorDeviceTask->InstructAlias:"<<pRspQryNetMonitorDeviceTask->InstructAlias<<std::endl;
  std::cout<<"on pRspQryNetMonitorDeviceTask->InstructArgs:"<<pRspQryNetMonitorDeviceTask->InstructArgs<<std::endl;
  std::cout<<"on pRspQryNetMonitorDeviceTask->DefParamChain:"<<pRspQryNetMonitorDeviceTask->DefParamChain<<std::endl;
  std::cout<<"on pRspQryNetMonitorDeviceTask->Flag:"<<pRspQryNetMonitorDeviceTask->Flag<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetMonitorDeviceTaskField* pNewRspQryNetMonitorDeviceTask =new CShfeFtdcRspQryNetMonitorDeviceTaskField;
  memcpy(pNewRspQryNetMonitorDeviceTask,pRspQryNetMonitorDeviceTask,sizeof(CShfeFtdcRspQryNetMonitorDeviceTaskField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorDeviceTask;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorDeviceTaskTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetMonitorDeviceTaskTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetMonitorDeviceTaskTopic(CShfeFtdcRtnNetMonitorDeviceTaskField *pRtnNetMonitorDeviceTask)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetMonitorDeviceTask->OperationType:"<<pRtnNetMonitorDeviceTask->OperationType<<std::endl;
  std::cout<<"on pRtnNetMonitorDeviceTask->ID:"<<pRtnNetMonitorDeviceTask->ID<<std::endl;
  std::cout<<"on pRtnNetMonitorDeviceTask->ObjectID:"<<pRtnNetMonitorDeviceTask->ObjectID<<std::endl;
  std::cout<<"on pRtnNetMonitorDeviceTask->IPAddress:"<<pRtnNetMonitorDeviceTask->IPAddress<<std::endl;
  std::cout<<"on pRtnNetMonitorDeviceTask->Manufactory_ID:"<<pRtnNetMonitorDeviceTask->Manufactory_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorDeviceTask->InstructChain:"<<pRtnNetMonitorDeviceTask->InstructChain<<std::endl;
  std::cout<<"on pRtnNetMonitorDeviceTask->InstructAlias:"<<pRtnNetMonitorDeviceTask->InstructAlias<<std::endl;
  std::cout<<"on pRtnNetMonitorDeviceTask->InstructArgs:"<<pRtnNetMonitorDeviceTask->InstructArgs<<std::endl;
  std::cout<<"on pRtnNetMonitorDeviceTask->DefParamChain:"<<pRtnNetMonitorDeviceTask->DefParamChain<<std::endl;
  std::cout<<"on pRtnNetMonitorDeviceTask->Flag:"<<pRtnNetMonitorDeviceTask->Flag<<std::endl;
  CShfeFtdcRtnNetMonitorDeviceTaskField* pNewRtnNetMonitorDeviceTask =new CShfeFtdcRtnNetMonitorDeviceTaskField;
  memcpy(pNewRtnNetMonitorDeviceTask,pRtnNetMonitorDeviceTask,sizeof(CShfeFtdcRtnNetMonitorDeviceTaskField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorDeviceTask;
  asyncOnRtnNetMonitorDeviceTaskTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetMonitorDeviceTaskTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetMonitorTaskInstAttrsTopic(CShfeFtdcRspQryNetMonitorTaskInstAttrsField *pRspQryNetMonitorTaskInstAttrs, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInstAttrs->OperationType:"<<pRspQryNetMonitorTaskInstAttrs->OperationType<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInstAttrs->ID:"<<pRspQryNetMonitorTaskInstAttrs->ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInstAttrs->Manufactory_ID:"<<pRspQryNetMonitorTaskInstAttrs->Manufactory_ID<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInstAttrs->InstructAlias:"<<pRspQryNetMonitorTaskInstAttrs->InstructAlias<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInstAttrs->DEVICETYPE:"<<pRspQryNetMonitorTaskInstAttrs->DEVICETYPE<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInstAttrs->AttrsChain:"<<pRspQryNetMonitorTaskInstAttrs->AttrsChain<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInstAttrs->DefRegularChain:"<<pRspQryNetMonitorTaskInstAttrs->DefRegularChain<<std::endl;
  std::cout<<"on pRspQryNetMonitorTaskInstAttrs->DefParamChain:"<<pRspQryNetMonitorTaskInstAttrs->DefParamChain<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetMonitorTaskInstAttrsField* pNewRspQryNetMonitorTaskInstAttrs =new CShfeFtdcRspQryNetMonitorTaskInstAttrsField;
  memcpy(pNewRspQryNetMonitorTaskInstAttrs,pRspQryNetMonitorTaskInstAttrs,sizeof(CShfeFtdcRspQryNetMonitorTaskInstAttrsField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMonitorTaskInstAttrs;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMonitorTaskInstAttrsTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetMonitorTaskInstAttrsTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetMonitorTaskInstAttrsTopic(CShfeFtdcRtnNetMonitorTaskInstAttrsField *pRtnNetMonitorTaskInstAttrs)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInstAttrs->OperationType:"<<pRtnNetMonitorTaskInstAttrs->OperationType<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInstAttrs->ID:"<<pRtnNetMonitorTaskInstAttrs->ID<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInstAttrs->Manufactory_ID:"<<pRtnNetMonitorTaskInstAttrs->Manufactory_ID<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInstAttrs->InstructAlias:"<<pRtnNetMonitorTaskInstAttrs->InstructAlias<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInstAttrs->DEVICETYPE:"<<pRtnNetMonitorTaskInstAttrs->DEVICETYPE<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInstAttrs->AttrsChain:"<<pRtnNetMonitorTaskInstAttrs->AttrsChain<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInstAttrs->DefRegularChain:"<<pRtnNetMonitorTaskInstAttrs->DefRegularChain<<std::endl;
  std::cout<<"on pRtnNetMonitorTaskInstAttrs->DefParamChain:"<<pRtnNetMonitorTaskInstAttrs->DefParamChain<<std::endl;
  CShfeFtdcRtnNetMonitorTaskInstAttrsField* pNewRtnNetMonitorTaskInstAttrs =new CShfeFtdcRtnNetMonitorTaskInstAttrsField;
  memcpy(pNewRtnNetMonitorTaskInstAttrs,pRtnNetMonitorTaskInstAttrs,sizeof(CShfeFtdcRtnNetMonitorTaskInstAttrsField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMonitorTaskInstAttrs;
  asyncOnRtnNetMonitorTaskInstAttrsTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetMonitorTaskInstAttrsTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryFileGeneralOperTopic(CShfeFtdcRspQryFileGeneralOperField *pRspQryFileGeneralOper, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryFileGeneralOper->OperationType:"<<pRspQryFileGeneralOper->OperationType<<std::endl;
  std::cout<<"on pRspQryFileGeneralOper->FileName:"<<pRspQryFileGeneralOper->FileName<<std::endl;
  std::cout<<"on pRspQryFileGeneralOper->Version:"<<pRspQryFileGeneralOper->Version<<std::endl;
  std::cout<<"on pRspQryFileGeneralOper->SubVersion:"<<pRspQryFileGeneralOper->SubVersion<<std::endl;
  std::cout<<"on pRspQryFileGeneralOper->MonDate:"<<pRspQryFileGeneralOper->MonDate<<std::endl;
  std::cout<<"on pRspQryFileGeneralOper->MonTime:"<<pRspQryFileGeneralOper->MonTime<<std::endl;
  std::cout<<"on pRspQryFileGeneralOper->UserName:"<<pRspQryFileGeneralOper->UserName<<std::endl;
  std::cout<<"on pRspQryFileGeneralOper->OperType:"<<pRspQryFileGeneralOper->OperType<<std::endl;
  std::cout<<"on pRspQryFileGeneralOper->OperResult:"<<pRspQryFileGeneralOper->OperResult<<std::endl;
  std::cout<<"on pRspQryFileGeneralOper->Comments:"<<pRspQryFileGeneralOper->Comments<<std::endl;
  std::cout<<"on pRspQryFileGeneralOper->Offset:"<<pRspQryFileGeneralOper->Offset<<std::endl;
  std::cout<<"on pRspQryFileGeneralOper->Length:"<<pRspQryFileGeneralOper->Length<<std::endl;
  std::cout<<"on pRspQryFileGeneralOper->FileContent:"<<pRspQryFileGeneralOper->FileContent<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryFileGeneralOperField* pNewRspQryFileGeneralOper =new CShfeFtdcRspQryFileGeneralOperField;
  memcpy(pNewRspQryFileGeneralOper,pRspQryFileGeneralOper,sizeof(CShfeFtdcRspQryFileGeneralOperField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryFileGeneralOper;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryFileGeneralOperTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryFileGeneralOperTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnFileGeneralOperTopic(CShfeFtdcRtnFileGeneralOperField *pRtnFileGeneralOper)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnFileGeneralOper->OperationType:"<<pRtnFileGeneralOper->OperationType<<std::endl;
  std::cout<<"on pRtnFileGeneralOper->FileName:"<<pRtnFileGeneralOper->FileName<<std::endl;
  std::cout<<"on pRtnFileGeneralOper->Version:"<<pRtnFileGeneralOper->Version<<std::endl;
  std::cout<<"on pRtnFileGeneralOper->SubVersion:"<<pRtnFileGeneralOper->SubVersion<<std::endl;
  std::cout<<"on pRtnFileGeneralOper->MonDate:"<<pRtnFileGeneralOper->MonDate<<std::endl;
  std::cout<<"on pRtnFileGeneralOper->MonTime:"<<pRtnFileGeneralOper->MonTime<<std::endl;
  std::cout<<"on pRtnFileGeneralOper->UserName:"<<pRtnFileGeneralOper->UserName<<std::endl;
  std::cout<<"on pRtnFileGeneralOper->OperType:"<<pRtnFileGeneralOper->OperType<<std::endl;
  std::cout<<"on pRtnFileGeneralOper->OperResult:"<<pRtnFileGeneralOper->OperResult<<std::endl;
  std::cout<<"on pRtnFileGeneralOper->Comments:"<<pRtnFileGeneralOper->Comments<<std::endl;
  std::cout<<"on pRtnFileGeneralOper->Offset:"<<pRtnFileGeneralOper->Offset<<std::endl;
  std::cout<<"on pRtnFileGeneralOper->Length:"<<pRtnFileGeneralOper->Length<<std::endl;
  std::cout<<"on pRtnFileGeneralOper->FileContent:"<<pRtnFileGeneralOper->FileContent<<std::endl;
  CShfeFtdcRtnFileGeneralOperField* pNewRtnFileGeneralOper =new CShfeFtdcRtnFileGeneralOperField;
  memcpy(pNewRtnFileGeneralOper,pRtnFileGeneralOper,sizeof(CShfeFtdcRtnFileGeneralOperField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnFileGeneralOper;
  asyncOnRtnFileGeneralOperTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnFileGeneralOperTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetBaseLineTopic(CShfeFtdcRspQryNetBaseLineField *pRspQryNetBaseLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetBaseLine->OperationType:"<<pRspQryNetBaseLine->OperationType<<std::endl;
  std::cout<<"on pRspQryNetBaseLine->ID:"<<pRspQryNetBaseLine->ID<<std::endl;
  std::cout<<"on pRspQryNetBaseLine->MANUFACTORY_ID:"<<pRspQryNetBaseLine->MANUFACTORY_ID<<std::endl;
  std::cout<<"on pRspQryNetBaseLine->Name:"<<pRspQryNetBaseLine->Name<<std::endl;
  std::cout<<"on pRspQryNetBaseLine->SerialUsed:"<<pRspQryNetBaseLine->SerialUsed<<std::endl;
  std::cout<<"on pRspQryNetBaseLine->data:"<<pRspQryNetBaseLine->data<<std::endl;
  std::cout<<"on pRspQryNetBaseLine->memo:"<<pRspQryNetBaseLine->memo<<std::endl;
  std::cout<<"on pRspQryNetBaseLine->Flag:"<<pRspQryNetBaseLine->Flag<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetBaseLineField* pNewRspQryNetBaseLine =new CShfeFtdcRspQryNetBaseLineField;
  memcpy(pNewRspQryNetBaseLine,pRspQryNetBaseLine,sizeof(CShfeFtdcRspQryNetBaseLineField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetBaseLine;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetBaseLineTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetBaseLineTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetBaseLineTopic(CShfeFtdcRtnNetBaseLineField *pRtnNetBaseLine)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetBaseLine->OperationType:"<<pRtnNetBaseLine->OperationType<<std::endl;
  std::cout<<"on pRtnNetBaseLine->ID:"<<pRtnNetBaseLine->ID<<std::endl;
  std::cout<<"on pRtnNetBaseLine->MANUFACTORY_ID:"<<pRtnNetBaseLine->MANUFACTORY_ID<<std::endl;
  std::cout<<"on pRtnNetBaseLine->Name:"<<pRtnNetBaseLine->Name<<std::endl;
  std::cout<<"on pRtnNetBaseLine->SerialUsed:"<<pRtnNetBaseLine->SerialUsed<<std::endl;
  std::cout<<"on pRtnNetBaseLine->data:"<<pRtnNetBaseLine->data<<std::endl;
  std::cout<<"on pRtnNetBaseLine->memo:"<<pRtnNetBaseLine->memo<<std::endl;
  std::cout<<"on pRtnNetBaseLine->Flag:"<<pRtnNetBaseLine->Flag<<std::endl;
  CShfeFtdcRtnNetBaseLineField* pNewRtnNetBaseLine =new CShfeFtdcRtnNetBaseLineField;
  memcpy(pNewRtnNetBaseLine,pRtnNetBaseLine,sizeof(CShfeFtdcRtnNetBaseLineField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetBaseLine;
  asyncOnRtnNetBaseLineTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetBaseLineTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetBaseLineTaskTopic(CShfeFtdcRspQryNetBaseLineTaskField *pRspQryNetBaseLineTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetBaseLineTask->OperationType:"<<pRspQryNetBaseLineTask->OperationType<<std::endl;
  std::cout<<"on pRspQryNetBaseLineTask->ID:"<<pRspQryNetBaseLineTask->ID<<std::endl;
  std::cout<<"on pRspQryNetBaseLineTask->Name:"<<pRspQryNetBaseLineTask->Name<<std::endl;
  std::cout<<"on pRspQryNetBaseLineTask->BaseLineIDList:"<<pRspQryNetBaseLineTask->BaseLineIDList<<std::endl;
  std::cout<<"on pRspQryNetBaseLineTask->DeviceIDList:"<<pRspQryNetBaseLineTask->DeviceIDList<<std::endl;
  std::cout<<"on pRspQryNetBaseLineTask->GenDate:"<<pRspQryNetBaseLineTask->GenDate<<std::endl;
  std::cout<<"on pRspQryNetBaseLineTask->GenTime:"<<pRspQryNetBaseLineTask->GenTime<<std::endl;
  std::cout<<"on pRspQryNetBaseLineTask->GenUser:"<<pRspQryNetBaseLineTask->GenUser<<std::endl;
  std::cout<<"on pRspQryNetBaseLineTask->memo:"<<pRspQryNetBaseLineTask->memo<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetBaseLineTaskField* pNewRspQryNetBaseLineTask =new CShfeFtdcRspQryNetBaseLineTaskField;
  memcpy(pNewRspQryNetBaseLineTask,pRspQryNetBaseLineTask,sizeof(CShfeFtdcRspQryNetBaseLineTaskField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetBaseLineTask;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetBaseLineTaskTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetBaseLineTaskTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetBaseLineTaskTopic(CShfeFtdcRtnNetBaseLineTaskField *pRtnNetBaseLineTask)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetBaseLineTask->OperationType:"<<pRtnNetBaseLineTask->OperationType<<std::endl;
  std::cout<<"on pRtnNetBaseLineTask->ID:"<<pRtnNetBaseLineTask->ID<<std::endl;
  std::cout<<"on pRtnNetBaseLineTask->Name:"<<pRtnNetBaseLineTask->Name<<std::endl;
  std::cout<<"on pRtnNetBaseLineTask->BaseLineIDList:"<<pRtnNetBaseLineTask->BaseLineIDList<<std::endl;
  std::cout<<"on pRtnNetBaseLineTask->DeviceIDList:"<<pRtnNetBaseLineTask->DeviceIDList<<std::endl;
  std::cout<<"on pRtnNetBaseLineTask->GenDate:"<<pRtnNetBaseLineTask->GenDate<<std::endl;
  std::cout<<"on pRtnNetBaseLineTask->GenTime:"<<pRtnNetBaseLineTask->GenTime<<std::endl;
  std::cout<<"on pRtnNetBaseLineTask->GenUser:"<<pRtnNetBaseLineTask->GenUser<<std::endl;
  std::cout<<"on pRtnNetBaseLineTask->memo:"<<pRtnNetBaseLineTask->memo<<std::endl;
  CShfeFtdcRtnNetBaseLineTaskField* pNewRtnNetBaseLineTask =new CShfeFtdcRtnNetBaseLineTaskField;
  memcpy(pNewRtnNetBaseLineTask,pRtnNetBaseLineTask,sizeof(CShfeFtdcRtnNetBaseLineTaskField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetBaseLineTask;
  asyncOnRtnNetBaseLineTaskTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetBaseLineTaskTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetBaseLineResultTopic(CShfeFtdcRspQryNetBaseLineResultField *pRspQryNetBaseLineResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetBaseLineResult->OperationType:"<<pRspQryNetBaseLineResult->OperationType<<std::endl;
  std::cout<<"on pRspQryNetBaseLineResult->ID:"<<pRspQryNetBaseLineResult->ID<<std::endl;
  std::cout<<"on pRspQryNetBaseLineResult->BaseLineName:"<<pRspQryNetBaseLineResult->BaseLineName<<std::endl;
  std::cout<<"on pRspQryNetBaseLineResult->DeviceObjID:"<<pRspQryNetBaseLineResult->DeviceObjID<<std::endl;
  std::cout<<"on pRspQryNetBaseLineResult->DeviceIP:"<<pRspQryNetBaseLineResult->DeviceIP<<std::endl;
  std::cout<<"on pRspQryNetBaseLineResult->Result:"<<pRspQryNetBaseLineResult->Result<<std::endl;
  std::cout<<"on pRspQryNetBaseLineResult->GenDate:"<<pRspQryNetBaseLineResult->GenDate<<std::endl;
  std::cout<<"on pRspQryNetBaseLineResult->GenTime:"<<pRspQryNetBaseLineResult->GenTime<<std::endl;
  std::cout<<"on pRspQryNetBaseLineResult->GenUser:"<<pRspQryNetBaseLineResult->GenUser<<std::endl;
  std::cout<<"on pRspQryNetBaseLineResult->Flag:"<<pRspQryNetBaseLineResult->Flag<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetBaseLineResultField* pNewRspQryNetBaseLineResult =new CShfeFtdcRspQryNetBaseLineResultField;
  memcpy(pNewRspQryNetBaseLineResult,pRspQryNetBaseLineResult,sizeof(CShfeFtdcRspQryNetBaseLineResultField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetBaseLineResult;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetBaseLineResultTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetBaseLineResultTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetBaseLineResultTopic(CShfeFtdcRtnNetBaseLineResultField *pRtnNetBaseLineResult)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetBaseLineResult->OperationType:"<<pRtnNetBaseLineResult->OperationType<<std::endl;
  std::cout<<"on pRtnNetBaseLineResult->ID:"<<pRtnNetBaseLineResult->ID<<std::endl;
  std::cout<<"on pRtnNetBaseLineResult->BaseLineName:"<<pRtnNetBaseLineResult->BaseLineName<<std::endl;
  std::cout<<"on pRtnNetBaseLineResult->DeviceObjID:"<<pRtnNetBaseLineResult->DeviceObjID<<std::endl;
  std::cout<<"on pRtnNetBaseLineResult->DeviceIP:"<<pRtnNetBaseLineResult->DeviceIP<<std::endl;
  std::cout<<"on pRtnNetBaseLineResult->Result:"<<pRtnNetBaseLineResult->Result<<std::endl;
  std::cout<<"on pRtnNetBaseLineResult->GenDate:"<<pRtnNetBaseLineResult->GenDate<<std::endl;
  std::cout<<"on pRtnNetBaseLineResult->GenTime:"<<pRtnNetBaseLineResult->GenTime<<std::endl;
  std::cout<<"on pRtnNetBaseLineResult->GenUser:"<<pRtnNetBaseLineResult->GenUser<<std::endl;
  std::cout<<"on pRtnNetBaseLineResult->Flag:"<<pRtnNetBaseLineResult->Flag<<std::endl;
  CShfeFtdcRtnNetBaseLineResultField* pNewRtnNetBaseLineResult =new CShfeFtdcRtnNetBaseLineResultField;
  memcpy(pNewRtnNetBaseLineResult,pRtnNetBaseLineResult,sizeof(CShfeFtdcRtnNetBaseLineResultField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetBaseLineResult;
  asyncOnRtnNetBaseLineResultTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetBaseLineResultTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetPartyLinkStatusInfoTopic(CShfeFtdcRspQryNetPartyLinkStatusInfoField *pRspQryNetPartyLinkStatusInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkStatusInfo->OperationType:"<<pRspQryNetPartyLinkStatusInfo->OperationType<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkStatusInfo->MonDate:"<<pRspQryNetPartyLinkStatusInfo->MonDate<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkStatusInfo->MonTime:"<<pRspQryNetPartyLinkStatusInfo->MonTime<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkStatusInfo->SEAT_NO:"<<pRspQryNetPartyLinkStatusInfo->SEAT_NO<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkStatusInfo->IPADDR:"<<pRspQryNetPartyLinkStatusInfo->IPADDR<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkStatusInfo->Interface:"<<pRspQryNetPartyLinkStatusInfo->Interface<<std::endl;
  std::cout<<"on pRspQryNetPartyLinkStatusInfo->status:"<<pRspQryNetPartyLinkStatusInfo->status<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetPartyLinkStatusInfoField* pNewRspQryNetPartyLinkStatusInfo =new CShfeFtdcRspQryNetPartyLinkStatusInfoField;
  memcpy(pNewRspQryNetPartyLinkStatusInfo,pRspQryNetPartyLinkStatusInfo,sizeof(CShfeFtdcRspQryNetPartyLinkStatusInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetPartyLinkStatusInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetPartyLinkStatusInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetPartyLinkStatusInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetPartyLinkStatusInfoTopic(CShfeFtdcRtnNetPartyLinkStatusInfoField *pRtnNetPartyLinkStatusInfo)
{
  std::cout<<"\n********** SysUserSpi::OnRtnNetPartyLinkStatusInfoTopic: START ********"<<std::endl;  
  std::cout<<"on pRtnNetPartyLinkStatusInfo->OperationType:"<<pRtnNetPartyLinkStatusInfo->OperationType<<std::endl;
  std::cout<<"on pRtnNetPartyLinkStatusInfo->MonDate:"<<pRtnNetPartyLinkStatusInfo->MonDate<<std::endl;
  std::cout<<"on pRtnNetPartyLinkStatusInfo->MonTime:"<<pRtnNetPartyLinkStatusInfo->MonTime<<std::endl;
  std::cout<<"on pRtnNetPartyLinkStatusInfo->SEAT_NO:"<<pRtnNetPartyLinkStatusInfo->SEAT_NO<<std::endl;
  std::cout<<"on pRtnNetPartyLinkStatusInfo->IPADDR:"<<pRtnNetPartyLinkStatusInfo->IPADDR<<std::endl;
  std::cout<<"on pRtnNetPartyLinkStatusInfo->Interface:"<<pRtnNetPartyLinkStatusInfo->Interface<<std::endl;
  std::cout<<"on pRtnNetPartyLinkStatusInfo->status:"<<pRtnNetPartyLinkStatusInfo->status<<std::endl;
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
  
  std::cout<< "**** g_RtnNetPartyLinkStatusInfoTopic_Sys_index: " << g_RtnNetPartyLinkStatusInfoTopic_Sys_index++ << endl;
  uv_async_send(&asyncOnRtnNetPartyLinkStatusInfoTopic);
  
  uv_mutex_unlock(&g_RtnNetPartyLinkStatusInfoTopic_mutex);  
   
  std::cout<<"********** SysUserSpi::OnRtnNetPartyLinkStatusInfoTopic: END ********\n"<<std::endl;
}
void SysUserSpi::OnRspQryNetMemberSDHLineInfoTopic(CShfeFtdcRspQryNetMemberSDHLineInfoField *pRspQryNetMemberSDHLineInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->OperationType:"<<pRspQryNetMemberSDHLineInfo->OperationType<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->ID:"<<pRspQryNetMemberSDHLineInfo->ID<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->SeqNo:"<<pRspQryNetMemberSDHLineInfo->SeqNo<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->MemContractNo:"<<pRspQryNetMemberSDHLineInfo->MemContractNo<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->ApplyPerson:"<<pRspQryNetMemberSDHLineInfo->ApplyPerson<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->MonthlyRental:"<<pRspQryNetMemberSDHLineInfo->MonthlyRental<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->MemberNo:"<<pRspQryNetMemberSDHLineInfo->MemberNo<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->ParticipantName:"<<pRspQryNetMemberSDHLineInfo->ParticipantName<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->ClientManager:"<<pRspQryNetMemberSDHLineInfo->ClientManager<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->Bandwidth:"<<pRspQryNetMemberSDHLineInfo->Bandwidth<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->InterfaceType:"<<pRspQryNetMemberSDHLineInfo->InterfaceType<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->RemoteCircuit:"<<pRspQryNetMemberSDHLineInfo->RemoteCircuit<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->LocalCircuit:"<<pRspQryNetMemberSDHLineInfo->LocalCircuit<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->Remark:"<<pRspQryNetMemberSDHLineInfo->Remark<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->EndALineAddress:"<<pRspQryNetMemberSDHLineInfo->EndALineAddress<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->EndAContact:"<<pRspQryNetMemberSDHLineInfo->EndAContact<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->EndZLineAddress:"<<pRspQryNetMemberSDHLineInfo->EndZLineAddress<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->ContactName:"<<pRspQryNetMemberSDHLineInfo->ContactName<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->TELEPHONE:"<<pRspQryNetMemberSDHLineInfo->TELEPHONE<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->MOBILEPHONE:"<<pRspQryNetMemberSDHLineInfo->MOBILEPHONE<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->IPADDR:"<<pRspQryNetMemberSDHLineInfo->IPADDR<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->Interface:"<<pRspQryNetMemberSDHLineInfo->Interface<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->PROVINCE:"<<pRspQryNetMemberSDHLineInfo->PROVINCE<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->StartPortID:"<<pRspQryNetMemberSDHLineInfo->StartPortID<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->StartJump:"<<pRspQryNetMemberSDHLineInfo->StartJump<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->LINE_STATUS:"<<pRspQryNetMemberSDHLineInfo->LINE_STATUS<<std::endl;
  std::cout<<"on pRspQryNetMemberSDHLineInfo->DataCenterID:"<<pRspQryNetMemberSDHLineInfo->DataCenterID<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetMemberSDHLineInfoField* pNewRspQryNetMemberSDHLineInfo =new CShfeFtdcRspQryNetMemberSDHLineInfoField;
  memcpy(pNewRspQryNetMemberSDHLineInfo,pRspQryNetMemberSDHLineInfo,sizeof(CShfeFtdcRspQryNetMemberSDHLineInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetMemberSDHLineInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetMemberSDHLineInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetMemberSDHLineInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetMemberSDHLineInfoTopic(CShfeFtdcRtnNetMemberSDHLineInfoField *pRtnNetMemberSDHLineInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->OperationType:"<<pRtnNetMemberSDHLineInfo->OperationType<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->ID:"<<pRtnNetMemberSDHLineInfo->ID<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->SeqNo:"<<pRtnNetMemberSDHLineInfo->SeqNo<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->MemContractNo:"<<pRtnNetMemberSDHLineInfo->MemContractNo<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->ApplyPerson:"<<pRtnNetMemberSDHLineInfo->ApplyPerson<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->MonthlyRental:"<<pRtnNetMemberSDHLineInfo->MonthlyRental<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->MemberNo:"<<pRtnNetMemberSDHLineInfo->MemberNo<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->ParticipantName:"<<pRtnNetMemberSDHLineInfo->ParticipantName<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->ClientManager:"<<pRtnNetMemberSDHLineInfo->ClientManager<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->Bandwidth:"<<pRtnNetMemberSDHLineInfo->Bandwidth<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->InterfaceType:"<<pRtnNetMemberSDHLineInfo->InterfaceType<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->RemoteCircuit:"<<pRtnNetMemberSDHLineInfo->RemoteCircuit<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->LocalCircuit:"<<pRtnNetMemberSDHLineInfo->LocalCircuit<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->Remark:"<<pRtnNetMemberSDHLineInfo->Remark<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->EndALineAddress:"<<pRtnNetMemberSDHLineInfo->EndALineAddress<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->EndAContact:"<<pRtnNetMemberSDHLineInfo->EndAContact<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->EndZLineAddress:"<<pRtnNetMemberSDHLineInfo->EndZLineAddress<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->ContactName:"<<pRtnNetMemberSDHLineInfo->ContactName<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->TELEPHONE:"<<pRtnNetMemberSDHLineInfo->TELEPHONE<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->MOBILEPHONE:"<<pRtnNetMemberSDHLineInfo->MOBILEPHONE<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->IPADDR:"<<pRtnNetMemberSDHLineInfo->IPADDR<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->Interface:"<<pRtnNetMemberSDHLineInfo->Interface<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->PROVINCE:"<<pRtnNetMemberSDHLineInfo->PROVINCE<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->StartPortID:"<<pRtnNetMemberSDHLineInfo->StartPortID<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->StartJump:"<<pRtnNetMemberSDHLineInfo->StartJump<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->LINE_STATUS:"<<pRtnNetMemberSDHLineInfo->LINE_STATUS<<std::endl;
  std::cout<<"on pRtnNetMemberSDHLineInfo->DataCenterID:"<<pRtnNetMemberSDHLineInfo->DataCenterID<<std::endl;
  CShfeFtdcRtnNetMemberSDHLineInfoField* pNewRtnNetMemberSDHLineInfo =new CShfeFtdcRtnNetMemberSDHLineInfoField;
  memcpy(pNewRtnNetMemberSDHLineInfo,pRtnNetMemberSDHLineInfo,sizeof(CShfeFtdcRtnNetMemberSDHLineInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetMemberSDHLineInfo;
  asyncOnRtnNetMemberSDHLineInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetMemberSDHLineInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetDDNLinkInfoTopic(CShfeFtdcRspQryNetDDNLinkInfoField *pRspQryNetDDNLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetDDNLinkInfo->OperationType:"<<pRspQryNetDDNLinkInfo->OperationType<<std::endl;
  std::cout<<"on pRspQryNetDDNLinkInfo->ID:"<<pRspQryNetDDNLinkInfo->ID<<std::endl;
  std::cout<<"on pRspQryNetDDNLinkInfo->ClientName:"<<pRspQryNetDDNLinkInfo->ClientName<<std::endl;
  std::cout<<"on pRspQryNetDDNLinkInfo->DDN_NO:"<<pRspQryNetDDNLinkInfo->DDN_NO<<std::endl;
  std::cout<<"on pRspQryNetDDNLinkInfo->BusinessUnit:"<<pRspQryNetDDNLinkInfo->BusinessUnit<<std::endl;
  std::cout<<"on pRspQryNetDDNLinkInfo->Bandwidth:"<<pRspQryNetDDNLinkInfo->Bandwidth<<std::endl;
  std::cout<<"on pRspQryNetDDNLinkInfo->EndAAddress:"<<pRspQryNetDDNLinkInfo->EndAAddress<<std::endl;
  std::cout<<"on pRspQryNetDDNLinkInfo->EndAContactName:"<<pRspQryNetDDNLinkInfo->EndAContactName<<std::endl;
  std::cout<<"on pRspQryNetDDNLinkInfo->EndZAddress:"<<pRspQryNetDDNLinkInfo->EndZAddress<<std::endl;
  std::cout<<"on pRspQryNetDDNLinkInfo->EndZContactName:"<<pRspQryNetDDNLinkInfo->EndZContactName<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetDDNLinkInfoField* pNewRspQryNetDDNLinkInfo =new CShfeFtdcRspQryNetDDNLinkInfoField;
  memcpy(pNewRspQryNetDDNLinkInfo,pRspQryNetDDNLinkInfo,sizeof(CShfeFtdcRspQryNetDDNLinkInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetDDNLinkInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetDDNLinkInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetDDNLinkInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetDDNLinkInfoTopic(CShfeFtdcRtnNetDDNLinkInfoField *pRtnNetDDNLinkInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetDDNLinkInfo->OperationType:"<<pRtnNetDDNLinkInfo->OperationType<<std::endl;
  std::cout<<"on pRtnNetDDNLinkInfo->ID:"<<pRtnNetDDNLinkInfo->ID<<std::endl;
  std::cout<<"on pRtnNetDDNLinkInfo->ClientName:"<<pRtnNetDDNLinkInfo->ClientName<<std::endl;
  std::cout<<"on pRtnNetDDNLinkInfo->DDN_NO:"<<pRtnNetDDNLinkInfo->DDN_NO<<std::endl;
  std::cout<<"on pRtnNetDDNLinkInfo->BusinessUnit:"<<pRtnNetDDNLinkInfo->BusinessUnit<<std::endl;
  std::cout<<"on pRtnNetDDNLinkInfo->Bandwidth:"<<pRtnNetDDNLinkInfo->Bandwidth<<std::endl;
  std::cout<<"on pRtnNetDDNLinkInfo->EndAAddress:"<<pRtnNetDDNLinkInfo->EndAAddress<<std::endl;
  std::cout<<"on pRtnNetDDNLinkInfo->EndAContactName:"<<pRtnNetDDNLinkInfo->EndAContactName<<std::endl;
  std::cout<<"on pRtnNetDDNLinkInfo->EndZAddress:"<<pRtnNetDDNLinkInfo->EndZAddress<<std::endl;
  std::cout<<"on pRtnNetDDNLinkInfo->EndZContactName:"<<pRtnNetDDNLinkInfo->EndZContactName<<std::endl;
  CShfeFtdcRtnNetDDNLinkInfoField* pNewRtnNetDDNLinkInfo =new CShfeFtdcRtnNetDDNLinkInfoField;
  memcpy(pNewRtnNetDDNLinkInfo,pRtnNetDDNLinkInfo,sizeof(CShfeFtdcRtnNetDDNLinkInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetDDNLinkInfo;
  asyncOnRtnNetDDNLinkInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetDDNLinkInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetPseudMemberLinkInfoTopic(CShfeFtdcRspQryNetPseudMemberLinkInfoField *pRspQryNetPseudMemberLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->OperationType:"<<pRspQryNetPseudMemberLinkInfo->OperationType<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->ID:"<<pRspQryNetPseudMemberLinkInfo->ID<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->SeqNo:"<<pRspQryNetPseudMemberLinkInfo->SeqNo<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->MemContractNo:"<<pRspQryNetPseudMemberLinkInfo->MemContractNo<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->LineUsage:"<<pRspQryNetPseudMemberLinkInfo->LineUsage<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->LocalCircuit:"<<pRspQryNetPseudMemberLinkInfo->LocalCircuit<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->RemoteCircuit:"<<pRspQryNetPseudMemberLinkInfo->RemoteCircuit<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->BusinessUnit:"<<pRspQryNetPseudMemberLinkInfo->BusinessUnit<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->Bandwidth:"<<pRspQryNetPseudMemberLinkInfo->Bandwidth<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->ApplyPerson:"<<pRspQryNetPseudMemberLinkInfo->ApplyPerson<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->MonthlyRental:"<<pRspQryNetPseudMemberLinkInfo->MonthlyRental<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->EndAAddress:"<<pRspQryNetPseudMemberLinkInfo->EndAAddress<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->EndAContactName:"<<pRspQryNetPseudMemberLinkInfo->EndAContactName<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->EndZAddress:"<<pRspQryNetPseudMemberLinkInfo->EndZAddress<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->EndZContactName:"<<pRspQryNetPseudMemberLinkInfo->EndZContactName<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->Telephone:"<<pRspQryNetPseudMemberLinkInfo->Telephone<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->LineInfo:"<<pRspQryNetPseudMemberLinkInfo->LineInfo<<std::endl;
  std::cout<<"on pRspQryNetPseudMemberLinkInfo->IPADDR:"<<pRspQryNetPseudMemberLinkInfo->IPADDR<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetPseudMemberLinkInfoField* pNewRspQryNetPseudMemberLinkInfo =new CShfeFtdcRspQryNetPseudMemberLinkInfoField;
  memcpy(pNewRspQryNetPseudMemberLinkInfo,pRspQryNetPseudMemberLinkInfo,sizeof(CShfeFtdcRspQryNetPseudMemberLinkInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetPseudMemberLinkInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetPseudMemberLinkInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetPseudMemberLinkInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetPseudMemberLinkInfoTopic(CShfeFtdcRtnNetPseudMemberLinkInfoField *pRtnNetPseudMemberLinkInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->OperationType:"<<pRtnNetPseudMemberLinkInfo->OperationType<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->ID:"<<pRtnNetPseudMemberLinkInfo->ID<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->SeqNo:"<<pRtnNetPseudMemberLinkInfo->SeqNo<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->MemContractNo:"<<pRtnNetPseudMemberLinkInfo->MemContractNo<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->LineUsage:"<<pRtnNetPseudMemberLinkInfo->LineUsage<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->LocalCircuit:"<<pRtnNetPseudMemberLinkInfo->LocalCircuit<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->RemoteCircuit:"<<pRtnNetPseudMemberLinkInfo->RemoteCircuit<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->BusinessUnit:"<<pRtnNetPseudMemberLinkInfo->BusinessUnit<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->Bandwidth:"<<pRtnNetPseudMemberLinkInfo->Bandwidth<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->ApplyPerson:"<<pRtnNetPseudMemberLinkInfo->ApplyPerson<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->MonthlyRental:"<<pRtnNetPseudMemberLinkInfo->MonthlyRental<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->EndAAddress:"<<pRtnNetPseudMemberLinkInfo->EndAAddress<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->EndAContactName:"<<pRtnNetPseudMemberLinkInfo->EndAContactName<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->EndZAddress:"<<pRtnNetPseudMemberLinkInfo->EndZAddress<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->EndZContactName:"<<pRtnNetPseudMemberLinkInfo->EndZContactName<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->Telephone:"<<pRtnNetPseudMemberLinkInfo->Telephone<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->LineInfo:"<<pRtnNetPseudMemberLinkInfo->LineInfo<<std::endl;
  std::cout<<"on pRtnNetPseudMemberLinkInfo->IPADDR:"<<pRtnNetPseudMemberLinkInfo->IPADDR<<std::endl;
  CShfeFtdcRtnNetPseudMemberLinkInfoField* pNewRtnNetPseudMemberLinkInfo =new CShfeFtdcRtnNetPseudMemberLinkInfoField;
  memcpy(pNewRtnNetPseudMemberLinkInfo,pRtnNetPseudMemberLinkInfo,sizeof(CShfeFtdcRtnNetPseudMemberLinkInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetPseudMemberLinkInfo;
  asyncOnRtnNetPseudMemberLinkInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetPseudMemberLinkInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryOuterDeviceInfTopic(CShfeFtdcRspQryOuterDeviceInfField *pRspQryOuterDeviceInf, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryOuterDeviceInf->OperationType:"<<pRspQryOuterDeviceInf->OperationType<<std::endl;
  std::cout<<"on pRspQryOuterDeviceInf->ID:"<<pRspQryOuterDeviceInf->ID<<std::endl;
  std::cout<<"on pRspQryOuterDeviceInf->IPADDR:"<<pRspQryOuterDeviceInf->IPADDR<<std::endl;
  std::cout<<"on pRspQryOuterDeviceInf->NAME:"<<pRspQryOuterDeviceInf->NAME<<std::endl;
  std::cout<<"on pRspQryOuterDeviceInf->memo:"<<pRspQryOuterDeviceInf->memo<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryOuterDeviceInfField* pNewRspQryOuterDeviceInf =new CShfeFtdcRspQryOuterDeviceInfField;
  memcpy(pNewRspQryOuterDeviceInf,pRspQryOuterDeviceInf,sizeof(CShfeFtdcRspQryOuterDeviceInfField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryOuterDeviceInf;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryOuterDeviceInfTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryOuterDeviceInfTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetOuterDeviceInfTopic(CShfeFtdcRtnNetOuterDeviceInfField *pRtnNetOuterDeviceInf)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetOuterDeviceInf->OperationType:"<<pRtnNetOuterDeviceInf->OperationType<<std::endl;
  std::cout<<"on pRtnNetOuterDeviceInf->ID:"<<pRtnNetOuterDeviceInf->ID<<std::endl;
  std::cout<<"on pRtnNetOuterDeviceInf->IPADDR:"<<pRtnNetOuterDeviceInf->IPADDR<<std::endl;
  std::cout<<"on pRtnNetOuterDeviceInf->NAME:"<<pRtnNetOuterDeviceInf->NAME<<std::endl;
  std::cout<<"on pRtnNetOuterDeviceInf->memo:"<<pRtnNetOuterDeviceInf->memo<<std::endl;
  CShfeFtdcRtnNetOuterDeviceInfField* pNewRtnNetOuterDeviceInf =new CShfeFtdcRtnNetOuterDeviceInfField;
  memcpy(pNewRtnNetOuterDeviceInf,pRtnNetOuterDeviceInf,sizeof(CShfeFtdcRtnNetOuterDeviceInfField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetOuterDeviceInf;
  asyncOnRtnNetOuterDeviceInfTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetOuterDeviceInfTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetLocalPingResultInfoTopic(CShfeFtdcRspQryNetLocalPingResultInfoField *pRspQryNetLocalPingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetLocalPingResultInfo->OperationType:"<<pRspQryNetLocalPingResultInfo->OperationType<<std::endl;
  std::cout<<"on pRspQryNetLocalPingResultInfo->ID:"<<pRspQryNetLocalPingResultInfo->ID<<std::endl;
  std::cout<<"on pRspQryNetLocalPingResultInfo->SouIPADDR:"<<pRspQryNetLocalPingResultInfo->SouIPADDR<<std::endl;
  std::cout<<"on pRspQryNetLocalPingResultInfo->SouNAME:"<<pRspQryNetLocalPingResultInfo->SouNAME<<std::endl;
  std::cout<<"on pRspQryNetLocalPingResultInfo->TarIPADDR:"<<pRspQryNetLocalPingResultInfo->TarIPADDR<<std::endl;
  std::cout<<"on pRspQryNetLocalPingResultInfo->TarNAME:"<<pRspQryNetLocalPingResultInfo->TarNAME<<std::endl;
  std::cout<<"on pRspQryNetLocalPingResultInfo->PDateSta:"<<pRspQryNetLocalPingResultInfo->PDateSta<<std::endl;
  std::cout<<"on pRspQryNetLocalPingResultInfo->PTimeSta:"<<pRspQryNetLocalPingResultInfo->PTimeSta<<std::endl;
  std::cout<<"on pRspQryNetLocalPingResultInfo->ConnRate:"<<pRspQryNetLocalPingResultInfo->ConnRate<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetLocalPingResultInfoField* pNewRspQryNetLocalPingResultInfo =new CShfeFtdcRspQryNetLocalPingResultInfoField;
  memcpy(pNewRspQryNetLocalPingResultInfo,pRspQryNetLocalPingResultInfo,sizeof(CShfeFtdcRspQryNetLocalPingResultInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetLocalPingResultInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetLocalPingResultInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetLocalPingResultInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetLocalPingResultInfoTopic(CShfeFtdcRtnNetLocalPingResultInfoField *pRtnNetLocalPingResultInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetLocalPingResultInfo->OperationType:"<<pRtnNetLocalPingResultInfo->OperationType<<std::endl;
  std::cout<<"on pRtnNetLocalPingResultInfo->ID:"<<pRtnNetLocalPingResultInfo->ID<<std::endl;
  std::cout<<"on pRtnNetLocalPingResultInfo->SouIPADDR:"<<pRtnNetLocalPingResultInfo->SouIPADDR<<std::endl;
  std::cout<<"on pRtnNetLocalPingResultInfo->SouNAME:"<<pRtnNetLocalPingResultInfo->SouNAME<<std::endl;
  std::cout<<"on pRtnNetLocalPingResultInfo->TarIPADDR:"<<pRtnNetLocalPingResultInfo->TarIPADDR<<std::endl;
  std::cout<<"on pRtnNetLocalPingResultInfo->TarNAME:"<<pRtnNetLocalPingResultInfo->TarNAME<<std::endl;
  std::cout<<"on pRtnNetLocalPingResultInfo->PDateSta:"<<pRtnNetLocalPingResultInfo->PDateSta<<std::endl;
  std::cout<<"on pRtnNetLocalPingResultInfo->PTimeSta:"<<pRtnNetLocalPingResultInfo->PTimeSta<<std::endl;
  std::cout<<"on pRtnNetLocalPingResultInfo->ConnRate:"<<pRtnNetLocalPingResultInfo->ConnRate<<std::endl;
  CShfeFtdcRtnNetLocalPingResultInfoField* pNewRtnNetLocalPingResultInfo =new CShfeFtdcRtnNetLocalPingResultInfoField;
  memcpy(pNewRtnNetLocalPingResultInfo,pRtnNetLocalPingResultInfo,sizeof(CShfeFtdcRtnNetLocalPingResultInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetLocalPingResultInfo;
  asyncOnRtnNetLocalPingResultInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetLocalPingResultInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetRomotePingResultInfoTopic(CShfeFtdcRspQryNetRomotePingResultInfoField *pRspQryNetRomotePingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetRomotePingResultInfo->OperationType:"<<pRspQryNetRomotePingResultInfo->OperationType<<std::endl;
  std::cout<<"on pRspQryNetRomotePingResultInfo->ID:"<<pRspQryNetRomotePingResultInfo->ID<<std::endl;
  std::cout<<"on pRspQryNetRomotePingResultInfo->SouIPADDR:"<<pRspQryNetRomotePingResultInfo->SouIPADDR<<std::endl;
  std::cout<<"on pRspQryNetRomotePingResultInfo->SouNAME:"<<pRspQryNetRomotePingResultInfo->SouNAME<<std::endl;
  std::cout<<"on pRspQryNetRomotePingResultInfo->TarIPADDR:"<<pRspQryNetRomotePingResultInfo->TarIPADDR<<std::endl;
  std::cout<<"on pRspQryNetRomotePingResultInfo->TarNAME:"<<pRspQryNetRomotePingResultInfo->TarNAME<<std::endl;
  std::cout<<"on pRspQryNetRomotePingResultInfo->PDateSta:"<<pRspQryNetRomotePingResultInfo->PDateSta<<std::endl;
  std::cout<<"on pRspQryNetRomotePingResultInfo->PTimeSta:"<<pRspQryNetRomotePingResultInfo->PTimeSta<<std::endl;
  std::cout<<"on pRspQryNetRomotePingResultInfo->ConnRate:"<<pRspQryNetRomotePingResultInfo->ConnRate<<std::endl;
  std::cout<<"on pRspQryNetRomotePingResultInfo->TimeDlyMin:"<<pRspQryNetRomotePingResultInfo->TimeDlyMin<<std::endl;
  std::cout<<"on pRspQryNetRomotePingResultInfo->TimeDlyMax:"<<pRspQryNetRomotePingResultInfo->TimeDlyMax<<std::endl;
  std::cout<<"on pRspQryNetRomotePingResultInfo->TimeDlyAvg:"<<pRspQryNetRomotePingResultInfo->TimeDlyAvg<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetRomotePingResultInfoField* pNewRspQryNetRomotePingResultInfo =new CShfeFtdcRspQryNetRomotePingResultInfoField;
  memcpy(pNewRspQryNetRomotePingResultInfo,pRspQryNetRomotePingResultInfo,sizeof(CShfeFtdcRspQryNetRomotePingResultInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetRomotePingResultInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetRomotePingResultInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetRomotePingResultInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetRomotePingResultInfoTopic(CShfeFtdcRtnNetRomotePingResultInfoField *pRtnNetRomotePingResultInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetRomotePingResultInfo->OperationType:"<<pRtnNetRomotePingResultInfo->OperationType<<std::endl;
  std::cout<<"on pRtnNetRomotePingResultInfo->ID:"<<pRtnNetRomotePingResultInfo->ID<<std::endl;
  std::cout<<"on pRtnNetRomotePingResultInfo->SouIPADDR:"<<pRtnNetRomotePingResultInfo->SouIPADDR<<std::endl;
  std::cout<<"on pRtnNetRomotePingResultInfo->SouNAME:"<<pRtnNetRomotePingResultInfo->SouNAME<<std::endl;
  std::cout<<"on pRtnNetRomotePingResultInfo->TarIPADDR:"<<pRtnNetRomotePingResultInfo->TarIPADDR<<std::endl;
  std::cout<<"on pRtnNetRomotePingResultInfo->TarNAME:"<<pRtnNetRomotePingResultInfo->TarNAME<<std::endl;
  std::cout<<"on pRtnNetRomotePingResultInfo->PDateSta:"<<pRtnNetRomotePingResultInfo->PDateSta<<std::endl;
  std::cout<<"on pRtnNetRomotePingResultInfo->PTimeSta:"<<pRtnNetRomotePingResultInfo->PTimeSta<<std::endl;
  std::cout<<"on pRtnNetRomotePingResultInfo->ConnRate:"<<pRtnNetRomotePingResultInfo->ConnRate<<std::endl;
  std::cout<<"on pRtnNetRomotePingResultInfo->TimeDlyMin:"<<pRtnNetRomotePingResultInfo->TimeDlyMin<<std::endl;
  std::cout<<"on pRtnNetRomotePingResultInfo->TimeDlyMax:"<<pRtnNetRomotePingResultInfo->TimeDlyMax<<std::endl;
  std::cout<<"on pRtnNetRomotePingResultInfo->TimeDlyAvg:"<<pRtnNetRomotePingResultInfo->TimeDlyAvg<<std::endl;
  CShfeFtdcRtnNetRomotePingResultInfoField* pNewRtnNetRomotePingResultInfo =new CShfeFtdcRtnNetRomotePingResultInfoField;
  memcpy(pNewRtnNetRomotePingResultInfo,pRtnNetRomotePingResultInfo,sizeof(CShfeFtdcRtnNetRomotePingResultInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetRomotePingResultInfo;
  asyncOnRtnNetRomotePingResultInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetRomotePingResultInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnMonitorTopProcessInfo(CShfeFtdcRtnMonitorTopProcessInfoField *pRtnMonitorTopProcessInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnMonitorTopProcessInfo->HostName:"<<pRtnMonitorTopProcessInfo->HostName<<std::endl;
  std::cout<<"on pRtnMonitorTopProcessInfo->MonDate:"<<pRtnMonitorTopProcessInfo->MonDate<<std::endl;
  std::cout<<"on pRtnMonitorTopProcessInfo->MonTime:"<<pRtnMonitorTopProcessInfo->MonTime<<std::endl;
  std::cout<<"on pRtnMonitorTopProcessInfo->CPU:"<<pRtnMonitorTopProcessInfo->CPU<<std::endl;
  std::cout<<"on pRtnMonitorTopProcessInfo->TTY:"<<pRtnMonitorTopProcessInfo->TTY<<std::endl;
  std::cout<<"on pRtnMonitorTopProcessInfo->PID:"<<pRtnMonitorTopProcessInfo->PID<<std::endl;
  std::cout<<"on pRtnMonitorTopProcessInfo->USERNAME:"<<pRtnMonitorTopProcessInfo->USERNAME<<std::endl;
  std::cout<<"on pRtnMonitorTopProcessInfo->PRI:"<<pRtnMonitorTopProcessInfo->PRI<<std::endl;
  std::cout<<"on pRtnMonitorTopProcessInfo->NI:"<<pRtnMonitorTopProcessInfo->NI<<std::endl;
  std::cout<<"on pRtnMonitorTopProcessInfo->SSIZE:"<<pRtnMonitorTopProcessInfo->SSIZE<<std::endl;
  std::cout<<"on pRtnMonitorTopProcessInfo->RES:"<<pRtnMonitorTopProcessInfo->RES<<std::endl;
  std::cout<<"on pRtnMonitorTopProcessInfo->STATE:"<<pRtnMonitorTopProcessInfo->STATE<<std::endl;
  std::cout<<"on pRtnMonitorTopProcessInfo->STIME:"<<pRtnMonitorTopProcessInfo->STIME<<std::endl;
  std::cout<<"on pRtnMonitorTopProcessInfo->pWCPU:"<<pRtnMonitorTopProcessInfo->pWCPU<<std::endl;
  std::cout<<"on pRtnMonitorTopProcessInfo->pCPU:"<<pRtnMonitorTopProcessInfo->pCPU<<std::endl;
  std::cout<<"on pRtnMonitorTopProcessInfo->COMMAND:"<<pRtnMonitorTopProcessInfo->COMMAND<<std::endl;
  CShfeFtdcRtnMonitorTopProcessInfoField* pNewRtnMonitorTopProcessInfo =new CShfeFtdcRtnMonitorTopProcessInfoField;
  memcpy(pNewRtnMonitorTopProcessInfo,pRtnMonitorTopProcessInfo,sizeof(CShfeFtdcRtnMonitorTopProcessInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnMonitorTopProcessInfo;
  asyncOnRtnMonitorTopProcessInfo.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnMonitorTopProcessInfo);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQrySysInternalTopologyTopic(CShfeFtdcRspQrySysInternalTopologyField *pRspQrySysInternalTopology, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQrySysInternalTopology->InfoType:"<<pRspQrySysInternalTopology->InfoType<<std::endl;
  std::cout<<"on pRspQrySysInternalTopology->Node1_ID:"<<pRspQrySysInternalTopology->Node1_ID<<std::endl;
  std::cout<<"on pRspQrySysInternalTopology->Node1_Info:"<<pRspQrySysInternalTopology->Node1_Info<<std::endl;
  std::cout<<"on pRspQrySysInternalTopology->LinkInfo:"<<pRspQrySysInternalTopology->LinkInfo<<std::endl;
  std::cout<<"on pRspQrySysInternalTopology->LinkState:"<<pRspQrySysInternalTopology->LinkState<<std::endl;
  std::cout<<"on pRspQrySysInternalTopology->Node2_ID:"<<pRspQrySysInternalTopology->Node2_ID<<std::endl;
  std::cout<<"on pRspQrySysInternalTopology->Node2_Info:"<<pRspQrySysInternalTopology->Node2_Info<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQrySysInternalTopologyField* pNewRspQrySysInternalTopology =new CShfeFtdcRspQrySysInternalTopologyField;
  memcpy(pNewRspQrySysInternalTopology,pRspQrySysInternalTopology,sizeof(CShfeFtdcRspQrySysInternalTopologyField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQrySysInternalTopology;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQrySysInternalTopologyTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQrySysInternalTopologyTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnSysInternalTopologyTopic(CShfeFtdcRtnSysInternalTopologyField *pRtnSysInternalTopology)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnSysInternalTopology->InfoType:"<<pRtnSysInternalTopology->InfoType<<std::endl;
  std::cout<<"on pRtnSysInternalTopology->Node1_ID:"<<pRtnSysInternalTopology->Node1_ID<<std::endl;
  std::cout<<"on pRtnSysInternalTopology->Node1_Info:"<<pRtnSysInternalTopology->Node1_Info<<std::endl;
  std::cout<<"on pRtnSysInternalTopology->LinkInfo:"<<pRtnSysInternalTopology->LinkInfo<<std::endl;
  std::cout<<"on pRtnSysInternalTopology->LinkState:"<<pRtnSysInternalTopology->LinkState<<std::endl;
  std::cout<<"on pRtnSysInternalTopology->Node2_ID:"<<pRtnSysInternalTopology->Node2_ID<<std::endl;
  std::cout<<"on pRtnSysInternalTopology->Node2_Info:"<<pRtnSysInternalTopology->Node2_Info<<std::endl;
  CShfeFtdcRtnSysInternalTopologyField* pNewRtnSysInternalTopology =new CShfeFtdcRtnSysInternalTopologyField;
  memcpy(pNewRtnSysInternalTopology,pRtnSysInternalTopology,sizeof(CShfeFtdcRtnSysInternalTopologyField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSysInternalTopology;
  asyncOnRtnSysInternalTopologyTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnSysInternalTopologyTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryMemberLinkCostTopic(CShfeFtdcRspQryMemberLinkCostField *pRspQryMemberLinkCost, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryMemberLinkCost->OperationType:"<<pRspQryMemberLinkCost->OperationType<<std::endl;
  std::cout<<"on pRspQryMemberLinkCost->ID:"<<pRspQryMemberLinkCost->ID<<std::endl;
  std::cout<<"on pRspQryMemberLinkCost->ParticipantName:"<<pRspQryMemberLinkCost->ParticipantName<<std::endl;
  std::cout<<"on pRspQryMemberLinkCost->DDN_NO:"<<pRspQryMemberLinkCost->DDN_NO<<std::endl;
  std::cout<<"on pRspQryMemberLinkCost->ServiceProvider:"<<pRspQryMemberLinkCost->ServiceProvider<<std::endl;
  std::cout<<"on pRspQryMemberLinkCost->Pay_Date:"<<pRspQryMemberLinkCost->Pay_Date<<std::endl;
  std::cout<<"on pRspQryMemberLinkCost->B_Pay_Date:"<<pRspQryMemberLinkCost->B_Pay_Date<<std::endl;
  std::cout<<"on pRspQryMemberLinkCost->D_Pay_Date:"<<pRspQryMemberLinkCost->D_Pay_Date<<std::endl;
  std::cout<<"on pRspQryMemberLinkCost->Charge:"<<pRspQryMemberLinkCost->Charge<<std::endl;
  std::cout<<"on pRspQryMemberLinkCost->Fee_Type:"<<pRspQryMemberLinkCost->Fee_Type<<std::endl;
  std::cout<<"on pRspQryMemberLinkCost->Pro:"<<pRspQryMemberLinkCost->Pro<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryMemberLinkCostField* pNewRspQryMemberLinkCost =new CShfeFtdcRspQryMemberLinkCostField;
  memcpy(pNewRspQryMemberLinkCost,pRspQryMemberLinkCost,sizeof(CShfeFtdcRspQryMemberLinkCostField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryMemberLinkCost;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryMemberLinkCostTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryMemberLinkCostTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnMemberLinkCostTopic(CShfeFtdcRtnMemberLinkCostField *pRtnMemberLinkCost)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnMemberLinkCost->OperationType:"<<pRtnMemberLinkCost->OperationType<<std::endl;
  std::cout<<"on pRtnMemberLinkCost->ID:"<<pRtnMemberLinkCost->ID<<std::endl;
  std::cout<<"on pRtnMemberLinkCost->ParticipantName:"<<pRtnMemberLinkCost->ParticipantName<<std::endl;
  std::cout<<"on pRtnMemberLinkCost->DDN_NO:"<<pRtnMemberLinkCost->DDN_NO<<std::endl;
  std::cout<<"on pRtnMemberLinkCost->ServiceProvider:"<<pRtnMemberLinkCost->ServiceProvider<<std::endl;
  std::cout<<"on pRtnMemberLinkCost->Pay_Date:"<<pRtnMemberLinkCost->Pay_Date<<std::endl;
  std::cout<<"on pRtnMemberLinkCost->B_Pay_Date:"<<pRtnMemberLinkCost->B_Pay_Date<<std::endl;
  std::cout<<"on pRtnMemberLinkCost->D_Pay_Date:"<<pRtnMemberLinkCost->D_Pay_Date<<std::endl;
  std::cout<<"on pRtnMemberLinkCost->Charge:"<<pRtnMemberLinkCost->Charge<<std::endl;
  std::cout<<"on pRtnMemberLinkCost->Fee_Type:"<<pRtnMemberLinkCost->Fee_Type<<std::endl;
  std::cout<<"on pRtnMemberLinkCost->Pro:"<<pRtnMemberLinkCost->Pro<<std::endl;
  CShfeFtdcRtnMemberLinkCostField* pNewRtnMemberLinkCost =new CShfeFtdcRtnMemberLinkCostField;
  memcpy(pNewRtnMemberLinkCost,pRtnMemberLinkCost,sizeof(CShfeFtdcRtnMemberLinkCostField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnMemberLinkCost;
  asyncOnRtnMemberLinkCostTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnMemberLinkCostTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetPartylinkMonthlyRentTopic(CShfeFtdcRspQryNetPartylinkMonthlyRentField *pRspQryNetPartylinkMonthlyRent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetPartylinkMonthlyRent->OperationType:"<<pRspQryNetPartylinkMonthlyRent->OperationType<<std::endl;
  std::cout<<"on pRspQryNetPartylinkMonthlyRent->ID:"<<pRspQryNetPartylinkMonthlyRent->ID<<std::endl;
  std::cout<<"on pRspQryNetPartylinkMonthlyRent->LineName:"<<pRspQryNetPartylinkMonthlyRent->LineName<<std::endl;
  std::cout<<"on pRspQryNetPartylinkMonthlyRent->DDN_NO:"<<pRspQryNetPartylinkMonthlyRent->DDN_NO<<std::endl;
  std::cout<<"on pRspQryNetPartylinkMonthlyRent->ServiceProvider:"<<pRspQryNetPartylinkMonthlyRent->ServiceProvider<<std::endl;
  std::cout<<"on pRspQryNetPartylinkMonthlyRent->MonthlyRental:"<<pRspQryNetPartylinkMonthlyRent->MonthlyRental<<std::endl;
  std::cout<<"on pRspQryNetPartylinkMonthlyRent->Remark:"<<pRspQryNetPartylinkMonthlyRent->Remark<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetPartylinkMonthlyRentField* pNewRspQryNetPartylinkMonthlyRent =new CShfeFtdcRspQryNetPartylinkMonthlyRentField;
  memcpy(pNewRspQryNetPartylinkMonthlyRent,pRspQryNetPartylinkMonthlyRent,sizeof(CShfeFtdcRspQryNetPartylinkMonthlyRentField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetPartylinkMonthlyRent;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetPartylinkMonthlyRentTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetPartylinkMonthlyRentTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetPartylinkMonthlyRentTopic(CShfeFtdcRtnNetPartylinkMonthlyRentField *pRtnNetPartylinkMonthlyRent)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetPartylinkMonthlyRent->OperationType:"<<pRtnNetPartylinkMonthlyRent->OperationType<<std::endl;
  std::cout<<"on pRtnNetPartylinkMonthlyRent->ID:"<<pRtnNetPartylinkMonthlyRent->ID<<std::endl;
  std::cout<<"on pRtnNetPartylinkMonthlyRent->LineName:"<<pRtnNetPartylinkMonthlyRent->LineName<<std::endl;
  std::cout<<"on pRtnNetPartylinkMonthlyRent->DDN_NO:"<<pRtnNetPartylinkMonthlyRent->DDN_NO<<std::endl;
  std::cout<<"on pRtnNetPartylinkMonthlyRent->ServiceProvider:"<<pRtnNetPartylinkMonthlyRent->ServiceProvider<<std::endl;
  std::cout<<"on pRtnNetPartylinkMonthlyRent->MonthlyRental:"<<pRtnNetPartylinkMonthlyRent->MonthlyRental<<std::endl;
  std::cout<<"on pRtnNetPartylinkMonthlyRent->Remark:"<<pRtnNetPartylinkMonthlyRent->Remark<<std::endl;
  CShfeFtdcRtnNetPartylinkMonthlyRentField* pNewRtnNetPartylinkMonthlyRent =new CShfeFtdcRtnNetPartylinkMonthlyRentField;
  memcpy(pNewRtnNetPartylinkMonthlyRent,pRtnNetPartylinkMonthlyRent,sizeof(CShfeFtdcRtnNetPartylinkMonthlyRentField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetPartylinkMonthlyRent;
  asyncOnRtnNetPartylinkMonthlyRentTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetPartylinkMonthlyRentTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRspQryNetNonPartyLinkInfoTopic(CShfeFtdcRspQryNetNonPartyLinkInfoField *pRspQryNetNonPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->OperationType:"<<pRspQryNetNonPartyLinkInfo->OperationType<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->ID:"<<pRspQryNetNonPartyLinkInfo->ID<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->MEMBER_NO:"<<pRspQryNetNonPartyLinkInfo->MEMBER_NO<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->MEMBER_NAME:"<<pRspQryNetNonPartyLinkInfo->MEMBER_NAME<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->REMOTE_ADDR:"<<pRspQryNetNonPartyLinkInfo->REMOTE_ADDR<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->LOCAL_ADDR:"<<pRspQryNetNonPartyLinkInfo->LOCAL_ADDR<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->ADDRESS:"<<pRspQryNetNonPartyLinkInfo->ADDRESS<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->LINE_STATUS:"<<pRspQryNetNonPartyLinkInfo->LINE_STATUS<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->CONTACT:"<<pRspQryNetNonPartyLinkInfo->CONTACT<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->TELEPHONE:"<<pRspQryNetNonPartyLinkInfo->TELEPHONE<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->MOBILEPHONE:"<<pRspQryNetNonPartyLinkInfo->MOBILEPHONE<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->EMAIL:"<<pRspQryNetNonPartyLinkInfo->EMAIL<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->FAX:"<<pRspQryNetNonPartyLinkInfo->FAX<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->PROVINCE:"<<pRspQryNetNonPartyLinkInfo->PROVINCE<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->DDN_NO:"<<pRspQryNetNonPartyLinkInfo->DDN_NO<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->IN_MODE:"<<pRspQryNetNonPartyLinkInfo->IN_MODE<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->IP_WAN:"<<pRspQryNetNonPartyLinkInfo->IP_WAN<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->IP_LAN:"<<pRspQryNetNonPartyLinkInfo->IP_LAN<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->IPADDR:"<<pRspQryNetNonPartyLinkInfo->IPADDR<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->Interface:"<<pRspQryNetNonPartyLinkInfo->Interface<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->INTERFACE_DATE:"<<pRspQryNetNonPartyLinkInfo->INTERFACE_DATE<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->SOFTWARE:"<<pRspQryNetNonPartyLinkInfo->SOFTWARE<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->FEE_TYPE:"<<pRspQryNetNonPartyLinkInfo->FEE_TYPE<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->SERVICEPROVIDER:"<<pRspQryNetNonPartyLinkInfo->SERVICEPROVIDER<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->IF_ZIYING:"<<pRspQryNetNonPartyLinkInfo->IF_ZIYING<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->IF_TUOGUAN:"<<pRspQryNetNonPartyLinkInfo->IF_TUOGUAN<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->HASOTHER:"<<pRspQryNetNonPartyLinkInfo->HASOTHER<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->SEAT_NO:"<<pRspQryNetNonPartyLinkInfo->SEAT_NO<<std::endl;
  std::cout<<"on pRspQryNetNonPartyLinkInfo->PRO:"<<pRspQryNetNonPartyLinkInfo->PRO<<std::endl;
  std::cout<<"on pRspInfo:"<<pRspInfo<<std::endl;
  std::cout<<"on nRequestID:"<<nRequestID<<std::endl;
  std::cout<<"on bIsLast:"<<bIsLast<<std::endl;
  CShfeFtdcRspQryNetNonPartyLinkInfoField* pNewRspQryNetNonPartyLinkInfo =new CShfeFtdcRspQryNetNonPartyLinkInfoField;
  memcpy(pNewRspQryNetNonPartyLinkInfo,pRspQryNetNonPartyLinkInfo,sizeof(CShfeFtdcRspQryNetNonPartyLinkInfoField));
  int *pId=new int(nRequestID);
  bool *bIsLastNew=new bool(bIsLast);
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRspQryNetNonPartyLinkInfo;

    if(pRspInfo!=NULL){
        CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
        std::cout<<"on:ErrorId"<<pRspInfoNew->ErrorID<<std::endl;
        std::cout<<"on:ErrorMsg"<<pRspInfoNew->ErrorMsg<<std::endl;
        paramArray[1]=(void*)pRspInfoNew;
    }
    else{
        paramArray[1]=(void*)pRspInfo;
    }
    paramArray[2]=(void*)pId;
    paramArray[3]=(void*)bIsLastNew;
  asyncOnRspQryNetNonPartyLinkInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRspQryNetNonPartyLinkInfoTopic);
  std::cout<<"end send "<<std::endl;
}
void SysUserSpi::OnRtnNetNonPartyLinkInfoTopic(CShfeFtdcRtnNetNonPartyLinkInfoField *pRtnNetNonPartyLinkInfo)
{
  std::cout<<"ok"<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->OperationType:"<<pRtnNetNonPartyLinkInfo->OperationType<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->ID:"<<pRtnNetNonPartyLinkInfo->ID<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->MEMBER_NO:"<<pRtnNetNonPartyLinkInfo->MEMBER_NO<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->MEMBER_NAME:"<<pRtnNetNonPartyLinkInfo->MEMBER_NAME<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->REMOTE_ADDR:"<<pRtnNetNonPartyLinkInfo->REMOTE_ADDR<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->LOCAL_ADDR:"<<pRtnNetNonPartyLinkInfo->LOCAL_ADDR<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->ADDRESS:"<<pRtnNetNonPartyLinkInfo->ADDRESS<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->LINE_STATUS:"<<pRtnNetNonPartyLinkInfo->LINE_STATUS<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->CONTACT:"<<pRtnNetNonPartyLinkInfo->CONTACT<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->TELEPHONE:"<<pRtnNetNonPartyLinkInfo->TELEPHONE<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->MOBILEPHONE:"<<pRtnNetNonPartyLinkInfo->MOBILEPHONE<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->EMAIL:"<<pRtnNetNonPartyLinkInfo->EMAIL<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->FAX:"<<pRtnNetNonPartyLinkInfo->FAX<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->PROVINCE:"<<pRtnNetNonPartyLinkInfo->PROVINCE<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->DDN_NO:"<<pRtnNetNonPartyLinkInfo->DDN_NO<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->IN_MODE:"<<pRtnNetNonPartyLinkInfo->IN_MODE<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->IP_WAN:"<<pRtnNetNonPartyLinkInfo->IP_WAN<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->IP_LAN:"<<pRtnNetNonPartyLinkInfo->IP_LAN<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->IPADDR:"<<pRtnNetNonPartyLinkInfo->IPADDR<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->Interface:"<<pRtnNetNonPartyLinkInfo->Interface<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->INTERFACE_DATE:"<<pRtnNetNonPartyLinkInfo->INTERFACE_DATE<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->SOFTWARE:"<<pRtnNetNonPartyLinkInfo->SOFTWARE<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->FEE_TYPE:"<<pRtnNetNonPartyLinkInfo->FEE_TYPE<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->SERVICEPROVIDER:"<<pRtnNetNonPartyLinkInfo->SERVICEPROVIDER<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->IF_ZIYING:"<<pRtnNetNonPartyLinkInfo->IF_ZIYING<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->IF_TUOGUAN:"<<pRtnNetNonPartyLinkInfo->IF_TUOGUAN<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->HASOTHER:"<<pRtnNetNonPartyLinkInfo->HASOTHER<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->SEAT_NO:"<<pRtnNetNonPartyLinkInfo->SEAT_NO<<std::endl;
  std::cout<<"on pRtnNetNonPartyLinkInfo->PRO:"<<pRtnNetNonPartyLinkInfo->PRO<<std::endl;
  CShfeFtdcRtnNetNonPartyLinkInfoField* pNewRtnNetNonPartyLinkInfo =new CShfeFtdcRtnNetNonPartyLinkInfoField;
  memcpy(pNewRtnNetNonPartyLinkInfo,pRtnNetNonPartyLinkInfo,sizeof(CShfeFtdcRtnNetNonPartyLinkInfoField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnNetNonPartyLinkInfo;
  asyncOnRtnNetNonPartyLinkInfoTopic.data=(void*)&paramArray[0];
  uv_async_send(&asyncOnRtnNetNonPartyLinkInfoTopic);
  std::cout<<"end send "<<std::endl;
}


