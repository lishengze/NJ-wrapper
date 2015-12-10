 /*
 Simple File for Test!
 */
 #include "SpiCFunc.h"
 #include "FtdcSysUserApiStruct.h"
 #include <iostream>
 using std::cin;
 using std::cout;
 using std::endl;
 using namespace v8;
 Nan::Persistent<v8::Object> SpiObj;
 uv_async_t async;
 uv_async_t asyncOnFrontDisconnected;
 uv_async_t asyncOnHeartBeatWarning;
 
int g_RtnNetPartyLinkStatusInfoTopic_Sys_index = 0;
int g_RtnNetPartyLinkStatusInfoTopic_Fun_index = 0;
std::queue<void**> g_RtnNetPartyLinkStatusInfoTopic_queue;
uv_mutex_t g_RtnNetPartyLinkStatusInfoTopic_data_mutex;   // 
uv_mutex_t g_RtnNetPartyLinkStatusInfoTopic_mutex;
uv_sem_t   g_RtnNetPartyLinkStatusInfoTopic_sem;
 
int g_RtnTradeUserLoginInfoTopic_Sys_index = 0;
int g_RtnTradeUserLoginInfoTopic_Fun_index = 0; 
std::queue<void**> g_RtnTradeUserLoginInfoTopic_queue;
uv_mutex_t g_RtnTradeUserLoginInfoTopic_data_mutex;   // 
uv_mutex_t g_RtnTradeUserLoginInfoTopic_mutex;
uv_sem_t   g_RtnTradeUserLoginInfoTopic_sem;

int g_OnRspQryNetMonitorAttrScopeTopic_Sys_index = 0;
int g_OnRspQryNetMonitorAttrScopeTopic_Fun_index = 0; 
std::queue<void**> g_OnRspQryNetMonitorAttrScopeTopic_queue;
uv_mutex_t g_OnRspQryNetMonitorAttrScopeTopic_data_mutex;   // 
uv_mutex_t g_OnRspQryNetMonitorAttrScopeTopic_mutex;
uv_sem_t   g_OnRspQryNetMonitorAttrScopeTopicc_sem;

void OnRspQryNetMonitorAttrScopeTopic(uv_async_t *handle)
{
    std::cout<<"\n*********** CFunc::OnRspQryNetMonitorAttrScopeTopic: START! **********"<<std::endl;
    cout << "****** g_OnRspQryNetMonitorAttrScopeTopic_Fun_index:  " 
         << g_OnRspQryNetMonitorAttrScopeTopic_Fun_index++ << " ******" << endl;
         
  //  queue<void**> tmpQueue;
         
  //   int iPid = (int)getpid();
  //   std::cout<<"The process id is:   "<<iPid<<std::endl;
    
  //   void**paramArrayNew=new void*[4];
  //  // paramArrayNew = (void**)handle->data;
  //   paramArrayNew = g_OnRspQryNetMonitorAttrScopeTopic_queue.pop();
  //   Nan::HandleScope scope;
  //   if(SpiObj.IsEmpty())
  //   {
  //     std::cout<<" IsEmpty()"<<std::endl;
  //     return;
  //   }
  //   v8::Local<v8::Object> localSpiObj=Nan::New<v8::Object>(SpiObj);
  //   v8::Local<v8::Value> OnFrontConnected=localSpiObj->Get(Nan::New<v8::String>("OnRspQryNetMonitorAttrScopeTopic").ToLocalChecked());
  //   if(OnFrontConnected->IsFunction())
  //   {
  //     v8::Local<v8::Function> function=v8::Local<v8::Function>::Cast(OnFrontConnected);
  //     Nan::Callback callback(function); 
  //     CShfeFtdcRspQryNetMonitorAttrScopeField *pRspQryNetMonitorAttrScope =(CShfeFtdcRspQryNetMonitorAttrScopeField *)(paramArrayNew[0]);
  //     CShfeFtdcRspInfoField *pRspInfo =(CShfeFtdcRspInfoField *)(paramArrayNew[1]);
  //     int nRequestID =*(int*)paramArrayNew[2];
  //     bool nIsLastNew=*(bool*)paramArrayNew[3];
  //     ///////////////////////////////////output message///////////////////////// 
  //     if(pRspInfo!=NULL){
  //       std::cout<<"ErrorMsg:"<<pRspInfo->ErrorMsg<<std::endl; 
  //     }
  //     else if(pRspInfo==NULL){
  //     std::cout<<"pRspInfo:   "<<"NULL"<<std::endl;
  //     }
  //     std::cout<<"nRequestID: "<<nRequestID<<std::endl;
  //     std::cout<<"nIsLastNew: "<<nIsLastNew<<std::endl;
  //    v8::Local<v8::String> OperationType=Nan::New<v8::String>("OperationType").ToLocalChecked();
  //    v8::Local<v8::Integer> OperationTypeValue=Nan::New<v8::Integer>(pRspQryNetMonitorAttrScope->OperationType);
  //    v8::Local<v8::String> ID=Nan::New<v8::String>("ID").ToLocalChecked();
  //    v8::Local<v8::Integer> IDValue=Nan::New<v8::Integer>(pRspQryNetMonitorAttrScope->ID);
  //    v8::Local<v8::String> CName=Nan::New<v8::String>("CName").ToLocalChecked();
  //    v8::Local<v8::String> CNameValue=Nan::New(pRspQryNetMonitorAttrScope->CName).ToLocalChecked();
  //    v8::Local<v8::String> EName=Nan::New<v8::String>("EName").ToLocalChecked();
  //    v8::Local<v8::String> ENameValue=Nan::New(pRspQryNetMonitorAttrScope->EName).ToLocalChecked();
  //    v8::Local<v8::String> Comments=Nan::New<v8::String>("Comments").ToLocalChecked();
  //    v8::Local<v8::String> CommentsValue=Nan::New(pRspQryNetMonitorAttrScope->Comments).ToLocalChecked();
  //    v8::Local<v8::Object> pRspQryNetMonitorAttrScopeJS=Nan::New<v8::Object>();
  //    pRspQryNetMonitorAttrScopeJS->Set(Local<v8::Value>(OperationType),Local<v8::Value>(OperationTypeValue));
  //    pRspQryNetMonitorAttrScopeJS->Set(Local<v8::Value>(ID),Local<v8::Value>(IDValue));
  //    pRspQryNetMonitorAttrScopeJS->Set(Local<v8::Value>(CName),Local<v8::Value>(CNameValue));
  //    pRspQryNetMonitorAttrScopeJS->Set(Local<v8::Value>(EName),Local<v8::Value>(ENameValue));
  //    pRspQryNetMonitorAttrScopeJS->Set(Local<v8::Value>(Comments),Local<v8::Value>(CommentsValue));

  //     v8::Local<v8::Object> pRspInfoJS=Nan::New<v8::Object>();
  //     if(pRspInfo!=NULL){
  //         v8::Local<v8::String> ErrorID=Nan::New<v8::String>("ErrorID").ToLocalChecked();
  //         v8::Local<v8::Integer> ErrorIDValue=Nan::New<v8::Integer>(pRspInfo->ErrorID);
  //         v8::Local<v8::String> ErrorMsg=Nan::New<v8::String>("ErrorMsg").ToLocalChecked();
  //         v8::Local<v8::String> ErrorMsggValue=Nan::New(pRspInfo->ErrorMsg).ToLocalChecked();

  //          v8::Local<v8::Object> pRspInfoJS=Nan::New<v8::Object>();
  //         pRspInfoJS->Set(Local<v8::Value>(ErrorID),Local<v8::Value>(ErrorIDValue));
  //         pRspInfoJS->Set(Local<v8::Value>(ErrorMsg),Local<v8::Value>(ErrorMsggValue));
  //     }
  //     std::cout<<"pRspInfo==NULL"<<std::endl;
  //     // v8::Local<v8::String> pRspInfoJSS=Nan::New<v8::String>("test").ToLocalChecked();
  //     v8::Local<v8::Integer> nRequestIDJS=Nan::New<v8::Integer>(nRequestID);
  //     v8::Local<v8::Boolean> nIsLastNewJS=Nan::New<v8::Boolean>(nIsLastNew);

  //     v8::Local<v8::Value> params[4];
  //        params[0]=Local<v8::Value>(pRspQryNetMonitorAttrScopeJS);

  //       if(pRspInfo!=NULL)
  //           params[1]=Local<v8::Value>(pRspInfoJS);
  //       else
  //           params[1]=Local<v8::Value>( Nan::Undefined());
  //       params[2]=Local<v8::Value>(nRequestIDJS);
  //       params[3]=Local<v8::Value>(nIsLastNewJS);
  //   //    callback.Call(4, params);
  //   }    
  //   for(int i=0;i<4;i++){
  //       delete []paramArrayNew[i];
  //   }
  //   delete []paramArrayNew;
          
  std::cout<<"*********** CFunc::OnRspQryNetMonitorAttrScopeTopic: END! **********\n"<<std::endl;    
 // uv_sem_post(&g_OnRspQryNetMonitorAttrScopeTopicc_sem);    
}