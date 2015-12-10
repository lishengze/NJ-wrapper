
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

 int g_OnRspQrySysUserLoginTopic_Sys_Numb = 0;
 int g_OnRtnSysTimeSyncTopic_Sys_Numb = 0;
 int g_OnRtnDataCenterChgTopic_Sys_Numb = 0;
 int g_OnRtnNetPartyLinkStatusInfoTopic_Sys_Numb = 0;
 int g_OnRtnWarningEventTopic_Sys_Numb = 0;
 int g_OnRtnWarningQueryTopic_Sys_Numb = 0;
 int g_OnRspQryNetMonitorAttrScopeTopic_Sys_Numb = 0;


void  SysUserSpi::OnRspQryNetMonitorAttrScopeTopic(CShfeFtdcRspQryNetMonitorAttrScopeField *pRspQryNetMonitorAttrScope,
                            CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{

  cout << "\n*********** SysUserSpi::OnRspQryNetMonitorAttrScopeTopic: START! **********"<< endl;
   if (NULL == pRspQryNetMonitorAttrScope) {
     cout << "****** g_OnRspQryNetMonitorAttrScopeTopic_Sys_index: "
          << g_OnRspQryNetMonitorAttrScopeTopic_Sys_index++ <<" ******" <<endl;
     cout << "\npRspQryNetMonitorAttrScope is NULL!\n " << endl;
 
     return;
   }

   cout << "****** g_OnRspQryNetMonitorAttrScopeTopic_Sys_index: "
        << g_OnRspQryNetMonitorAttrScopeTopic_Sys_index++ <<" ******" <<endl;

      // 处理数据，将数据存储到
      CShfeFtdcRspQryNetMonitorAttrScopeField* pNewRspQryNetMonitorAttrScope =new CShfeFtdcRspQryNetMonitorAttrScopeField;
      memcpy(pNewRspQryNetMonitorAttrScope, pRspQryNetMonitorAttrScope, sizeof(CShfeFtdcRspQryNetMonitorAttrScopeField));
      int *pId=new int(nRequestID);
      bool *bIsLastNew=new bool(bIsLast);
      void** paramArray=new void*[4];
      void* tmpPA0 = paramArray[0];
      //        cout << "Spi::paramArray:                               " << paramArray << endl;
      paramArray[0]=(void*)pNewRspQryNetMonitorAttrScope;
      // cout << "Spi::paramArray[0]:                            " << paramArray[0] << endl;
      // cout << "g_OnRspQryNetMonitorAttrScopeTopic_Sys_Numb:   " << g_OnRspQryNetMonitorAttrScopeTopic_Sys_Numb++ << endl;
      // cout << "Spi::pRspQryNetMonitorAttrScope->Comments:     " << pRspQryNetMonitorAttrScope->Comments<< endl;
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


     //     asyncOnRspQryNetMonitorAttrScopeTopic.data=(void*)&paramArray[0];

      uv_mutex_lock(&g_OnRspQryNetMonitorAttrScopeTopic_data_mutex);
      g_OnRspQryNetMonitorAttrScopeTopic_queue.push((void**)&paramArray[0]);
      uv_mutex_unlock(&g_OnRspQryNetMonitorAttrScopeTopic_data_mutex);


      // 传递数据；
      //  //       uv_sem_wait(&g_OnRspQryNetMonitorAttrScopeTopicc_sem);
      //  //       uv_mutex_lock(&g_OnRspQryNetMonitorAttrScopeTopic_mutex);

      //         cout << "\n*********** SysUserSpi::OnRspQryNetMonitorAttrScopeTopic: START! **********"<< endl;

      //         cout << "****** g_OnRspQryNetMonitorAttrScopeTopic_Sys_index: "
      //              << g_OnRspQryNetMonitorAttrScopeTopic_Sys_index++ <<" ******" <<endl;
      //  //     cout << "Spi::pOriRspQryNetMonitorAttrScope's address:  " << pRspQryNetMonitorAttrScope << endl;
      // //        cout << "Spi::paramArray:                               " << paramArray << endl;
      //         cout << "Spi::pNewRspQryNetMonitorAttrScope's address:  " << pNewRspQryNetMonitorAttrScope << endl;
      // //        cout << "Spi::tmpPA0:                                   " << tmpPA0 << endl;
      //         cout << "Spi::paramArray[0]:                            " << paramArray[0] << endl;
      //    //     paramArray[0]=(void*)pNewRspQryNetMonitorAttrScope;
      //         cout << "Spi::TransNewRspQryNetMonitorAttrScope:        "
      //              << (CShfeFtdcRspQryNetMonitorAttrScopeField*) paramArray[0] << endl;

       //      asyncOnRspQryNetMonitorAttrScopeTopic.data=(void*)&paramArray[0];

        uv_async_send(&asyncOnRspQryNetMonitorAttrScopeTopic);

      //          uv_mutex_unlock(&g_OnRspQryNetMonitorAttrScopeTopic_mutex);

   cout << "*********** SysUserSpi::OnRspQryNetMonitorAttrScopeTopic: END! **********\n"<< endl;

}

//  cout << "Spi::pRspQryNetMonitorAttrScope's address:  " << pRspQryNetMonitorAttrScope << endl;

/*


*/

/****************** 登陆的回调与订阅的信息 ********************/
void  SysUserSpi::OnRspQrySysUserLoginTopic(CShfeFtdcRspQrySysUserLoginField *pRspQrySysUserLogin,
											CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  cout << "\n**************** SysUserSpi::OnRspQrySysUserLoginTopic: START **************** "<< endl;

  // if (NULL == pRspQrySysUserLogin) {
  //   cout << "\npRspQrySysUserLogin is NULL!\n " << endl;
  //   cout << "****** g_OnRspQrySysUserLoginTopic_Sys_index: "
  //        << g_OnRspQrySysUserLoginTopic_Sys_index++ <<" ******" <<endl;
  //   return;
  // }
  
  // if (NULL != pRspQrySysUserLogin) {
  // cout << "on pRspQrySysUserLogin->UserID:"<<pRspQrySysUserLogin->UserID<< endl;
  // cout << "on pRspQrySysUserLogin->TradingDay:"<<pRspQrySysUserLogin->TradingDay<< endl;
  // cout << "on pRspQrySysUserLogin->LoginTime:"<<pRspQrySysUserLogin->LoginTime<< endl;
  // cout << "on pRspQrySysUserLogin->Privilege:"<<pRspQrySysUserLogin->Privilege<< endl;
  // cout << "on pRspQrySysUserLogin->VersionFlag:"<<pRspQrySysUserLogin->VersionFlag<< endl;
  // cout << "on pRspInfo:"<<pRspInfo<< endl;
  // cout << "on nRequestID:"<<nRequestID<< endl;
  // cout << "on bIsLast:"<<bIsLast<< endl;
  // CShfeFtdcRspQrySysUserLoginField* pNewRspQrySysUserLogin =new CShfeFtdcRspQrySysUserLoginField;
  // memcpy(pNewRspQrySysUserLogin,pRspQrySysUserLogin,sizeof(CShfeFtdcRspQrySysUserLoginField));
  // int *pId=new int(nRequestID);
  // bool *bIsLastNew=new bool(bIsLast);
  // void** paramArray=new void*[4];
  // paramArray[0]=(void*)pNewRspQrySysUserLogin;

  //   if(pRspInfo!=NULL){
  //       CShfeFtdcRspInfoField* pRspInfoNew = new CShfeFtdcRspInfoField;
  //       memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));
  //       cout << "on:ErrorId"<<pRspInfoNew->ErrorID<< endl;
  //       cout << "on:ErrorMsg"<<pRspInfoNew->ErrorMsg<< endl;
  //       paramArray[1]=(void*)pRspInfoNew;
  //   }
  //   else{
  //       paramArray[1]=(void*)pRspInfo;
  //   }
  //   paramArray[2]=(void*)pId;
  //   paramArray[3]=(void*)bIsLastNew;
  //   asyncOnRspQrySysUserLoginTopic.data=(void*)&paramArray[0];
  //   uv_async_send(&asyncOnRspQrySysUserLoginTopic);
  // } else {
  //   cout << "pRspQrySysUserLogin is NULL!" << endl;
  // }

  cout << "****************  SysUserSpi::OnRspQrySysUserLoginTopic: END **************** \n"<< endl;
}

void SysUserSpi::OnRtnSysTimeSyncTopic(CShfeFtdcRtnSysTimeSyncField *pRtnSysTimeSync) {

  cout << "\n****************SysUserSpi::OnRtnSysTimeSyncTopic: START ****************"<< endl;
  cout << "g_OnRtnSysTimeSyncTopic_Sys_Numb: " << g_OnRtnSysTimeSyncTopic_Sys_Numb++ << endl;
  cout << "on pRtnSysTimeSync->MonDate:      " << pRtnSysTimeSync->MonDate<< endl;
  cout << "on pRtnSysTimeSync->MonTime:      " << pRtnSysTimeSync->MonTime<< endl;

  CShfeFtdcRtnSysTimeSyncField* pNewRtnSysTimeSync =new CShfeFtdcRtnSysTimeSyncField;
  memcpy(pNewRtnSysTimeSync,pRtnSysTimeSync,sizeof(CShfeFtdcRtnSysTimeSyncField));
  void** paramArray=new void*[4];
  paramArray[0]=(void*)pNewRtnSysTimeSync;
  asyncOnRtnSysTimeSyncTopic.data=(void*)&paramArray[0];
  
  // uv_async_send(&asyncOnRtnSysTimeSyncTopic);

  cout << "**************** SysUserSpi::OnRtnSysTimeSyncTopic: END ****************\n"<< endl;

}

void SysUserSpi::OnRtnDataCenterChgTopic(CShfeFtdcRtnDataCenterChgField *pRtnDataCenterChg)
{
  cout << "\n**************** SysUserSpi::OnRtnDataCenterChgTopic: START ****************"<< endl;
  cout << "g_OnRtnDataCenterChgTopic_Sys_Numb: " << g_OnRtnDataCenterChgTopic_Sys_Numb++ << endl;
  cout << "on pRtnDataCenterChg->DataCenterID: " << pRtnDataCenterChg->DataCenterID << endl;
  cout << "**************** SysUserSpi::OnRtnDataCenterChgTopic: END ****************\n"<< endl;
}

void SysUserSpi::OnRtnNetPartyLinkStatusInfoTopic(CShfeFtdcRtnNetPartyLinkStatusInfoField *pRtnNetPartyLinkStatusInfo) {
  cout << "\n**************** SysUserSpi::OnRtnNetPartyLinkStatusInfoTopic: START ****************"<< endl;
  cout << "g_OnRtnNetPartyLinkStatusInfoTopic_Sys_Numb: " << g_OnRtnNetPartyLinkStatusInfoTopic_Sys_Numb++ << endl;
  cout << "**************** SysUserSpi::OnRtnNetPartyLinkStatusInfoTopic: END ****************\n"<< endl;
}

void  SysUserSpi::OnRtnWarningEventTopic(CShfeFtdcRtnWarningEventField *pRtnWarningEvent) {
  cout << "\n**************** SysUserSpi::OnRtnWarningEventTopic: START ****************"<< endl;
  cout << "g_OnRtnWarningEventTopic_Sys_Numb: " << g_OnRtnWarningEventTopic_Sys_Numb++ << endl;
  cout << "**************** SysUserSpi::OnRtnWarningEventTopic: END ****************\n"<< endl;
}

void  SysUserSpi::OnRtnWarningQueryTopic(CShfeFtdcRtnWarningQueryField *pRtnWarningQuery) {
  cout << "\n**************** SysUserSpi::OnRtnWarningQueryTopic: START ****************"<< endl;
  cout << "g_OnRtnWarningQueryTopic_Sys_Numb: " << g_OnRtnWarningQueryTopic_Sys_Numb++ << endl;
  cout << "**************** SysUserSpi::OnRtnWarningQueryTopic: END ****************\n"<< endl;
}
