#include <nan.h>
#include "ftdcsysuserapi-wrapper.h"
#include "FtdcSysUserApiStruct.h"
#include "sysuserspi.h"
#include "tool-function.h"
#include "id-func.h"
#include "CCrypto.h"
#include <string.h>

using namespace v8;

extern fstream g_RunningResult_File;

Nan::Persistent<Function> FtdcSysUserApi_Wrapper::constructor;

FtdcSysUserApi_Wrapper::FtdcSysUserApi_Wrapper(const char *pszFlowPath)
{
    m_userApi = CShfeFtdcSysUserApi::CreateFtdcSysUserApi(pszFlowPath);
    m_spi = new SysUserSpi();
    if (NULL == m_spi) {
       OutputCallbackMessage("FtdcSysUserApi_Wrapper::FtdcSysUserApi_Wrapper:: m_spi is NULL", g_RunningResult_File);
       return;
    }
}

FtdcSysUserApi_Wrapper::~FtdcSysUserApi_Wrapper() {
    m_userApi->Release();
    
    if (NULL != m_spi) {
        delete m_spi;
        m_spi = NULL;
    }
    
    g_RunningResult_File.close();
}

void FtdcSysUserApi_Wrapper::InitExports(Handle<Object> exports) {
    Nan::HandleScope scope;

    // Prepare constructor template
    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
    tpl->SetClassName(Nan::New<v8::String>("FtdcSysUserApi_Wrapper").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    //NODE_SET_PROTOTYPE_METHOD(tpl, "Init", Init);
    Nan::SetPrototypeMethod(tpl,"Release",Release);
    Nan::SetPrototypeMethod(tpl,"Init",Init);
    Nan::SetPrototypeMethod(tpl,"Join",Join);
    Nan::SetPrototypeMethod(tpl,"GetTradingDay",GetTradingDay);
    Nan::SetPrototypeMethod(tpl,"RegisterFront",RegisterFront);
    Nan::SetPrototypeMethod(tpl,"RegisterSpi",RegisterSpi);
    Nan::SetPrototypeMethod(tpl,"ReqQrySysUserLoginTopic",ReqQrySysUserLoginTopic);

    Nan::SetPrototypeMethod(tpl,"ReqQryTopCpuInfoTopic",ReqQryTopCpuInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryTopMemInfoTopic",ReqQryTopMemInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryTopProcessInfoTopic",ReqQryTopProcessInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryFileSystemInfoTopic",ReqQryFileSystemInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetworkInfoTopic",ReqQryNetworkInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryMonitorObjectTopic",ReqQryMonitorObjectTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryObjectRationalTopic",ReqQryObjectRationalTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQrySyslogInfoTopic",ReqQrySyslogInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQrySubscriberTopic",ReqQrySubscriberTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryOidRelationTopic",ReqQryOidRelationTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryUserInfoTopic",ReqQryUserInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryOnlineUserInfoTopic",ReqQryOnlineUserInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryWarningEventTopic",ReqQryWarningEventTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQrySyslogEventTopic",ReqQrySyslogEventTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQrySyslogEventSubcriberTopic",ReqQrySyslogEventSubcriberTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryObjectAttrTopic",ReqQryObjectAttrTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryInvalidateOrderTopic",ReqQryInvalidateOrderTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryOrderStatusTopic",ReqQryOrderStatusTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryBargainOrderTopic",ReqQryBargainOrderTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryInstPropertyTopic",ReqQryInstPropertyTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryMarginRateTopic",ReqQryMarginRateTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryPriceLimitTopic",ReqQryPriceLimitTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryPartPosiLimitTopic",ReqQryPartPosiLimitTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryClientPosiLimitTopic",ReqQryClientPosiLimitTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQrySpecialPosiLimitTopic",ReqQrySpecialPosiLimitTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryTransactionChgTopic",ReqQryTransactionChgTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryClientChgTopic",ReqQryClientChgTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryPartClientChgTopic",ReqQryPartClientChgTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryPosiLimitChgTopic",ReqQryPosiLimitChgTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryClientPosiLimitChgTopic",ReqQryClientPosiLimitChgTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQrySpecPosiLimitChgTopic",ReqQrySpecPosiLimitChgTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryHedgeDetailChgTopic",ReqQryHedgeDetailChgTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryParticipantChgTopic",ReqQryParticipantChgTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryMarginRateChgTopic",ReqQryMarginRateChgTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryUserIpChgTopic",ReqQryUserIpChgTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryHistoryObjectAttrTopic",ReqQryHistoryObjectAttrTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryFrontInfoTopic",ReqQryFrontInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQrySysUserLoginTopic",ReqQrySysUserLoginTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQrySysUserLogoutTopic",ReqQrySysUserLogoutTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQrySysUserPasswordUpdateTopic",ReqQrySysUserPasswordUpdateTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQrySysUserRegisterTopic",ReqQrySysUserRegisterTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQrySysUserDeleteTopic",ReqQrySysUserDeleteTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryTradeLogTopic",ReqQryTradeLogTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryParticipantInitTopic",ReqQryParticipantInitTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryUserInitTopic",ReqQryUserInitTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryWarningEventUpdateTopic",ReqQryWarningEventUpdateTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryTradeUserLoginInfoTopic",ReqQryTradeUserLoginInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryPartTradeTopic",ReqQryPartTradeTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryTradepeakTopic",ReqQryTradepeakTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryHistoryCpuInfoTopic",ReqQryHistoryCpuInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryHistoryMemInfoTopic",ReqQryHistoryMemInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryHistoryNetworkInfoTopic",ReqQryHistoryNetworkInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryMonitorOnlineUser",ReqQryMonitorOnlineUser);
    Nan::SetPrototypeMethod(tpl,"ReqQryFrontStat",ReqQryFrontStat);
    Nan::SetPrototypeMethod(tpl,"ReqQryHistoryTradePeakTopic",ReqQryHistoryTradePeakTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryTomcatInfoTopic",ReqQryTomcatInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryDBQueryTopic",ReqQryDBQueryTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryGetFileTopic",ReqQryGetFileTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQrySyslogEventUpdateTopic",ReqQrySyslogEventUpdateTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryWarningQueryTopic",ReqQryWarningQueryTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryWebVisitTopic",ReqQryWebVisitTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryWarningActiveChange",ReqQryWarningActiveChange);
    Nan::SetPrototypeMethod(tpl,"ReqQryTradeUserLoginStatTopic",ReqQryTradeUserLoginStatTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryGeneralOperateTopic",ReqQryGeneralOperateTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetDeviceLinkedTopic",ReqQryNetDeviceLinkedTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryRealTimeNetObjectAttrTopic",ReqQryRealTimeNetObjectAttrTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetAreaTopic",ReqQryNetAreaTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetSubAreaTopic",ReqQryNetSubAreaTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetSubAreaIPTopic",ReqQryNetSubAreaIPTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetDeviceDetectTopic",ReqQryNetDeviceDetectTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetDeviceRequestTopic",ReqQryNetDeviceRequestTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetBuildingTopic",ReqQryNetBuildingTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetRoomTopic",ReqQryNetRoomTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetCabinetsTopic",ReqQryNetCabinetsTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetOIDTopic",ReqQryNetOIDTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetTimePolicyTopic",ReqQryNetTimePolicyTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetGatherTaskTopic",ReqQryNetGatherTaskTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetDeviceChgTopic",ReqQryNetDeviceChgTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetDeviceTypeTopic",ReqQryNetDeviceTypeTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetDeviceCategoryTopic",ReqQryNetDeviceCategoryTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetManufactoryTopic",ReqQryNetManufactoryTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetCommunityTopic",ReqQryNetCommunityTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetPortTypeTopic",ReqQryNetPortTypeTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetPartAccessSpotTopic",ReqQryNetPartAccessSpotTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetInterfaceTopic",ReqQryNetInterfaceTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetGeneralOIDTopic",ReqQryNetGeneralOIDTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorTypeTopic",ReqQryNetMonitorTypeTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorAttrScopeTopic",ReqQryNetMonitorAttrScopeTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorAttrTypeTopic",ReqQryNetMonitorAttrTypeTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorObjectAttrTopic",ReqQryNetMonitorObjectAttrTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorTaskResultTopic",ReqQryNetMonitorTaskResultTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorDeviceGroupTopic",ReqQryNetMonitorDeviceGroupTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorTaskObjectSetTopic",ReqQryNetMonitorTaskObjectSetTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorTaskInfoTopic",ReqQryNetMonitorTaskInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetPartyLinkInfoTopic",ReqQryNetPartyLinkInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorActionAttrTopic",ReqQryNetMonitorActionAttrTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetModuleTopic",ReqQryNetModuleTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorTaskStatusResultTopic",ReqQryNetMonitorTaskStatusResultTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetCfgFileTopic",ReqQryNetCfgFileTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryFileGeneralOperTopic",ReqQryFileGeneralOperTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetPartyLinkStatusInfoTopic",ReqQryNetPartyLinkStatusInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetBaseLineTopic",ReqQryNetBaseLineTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetBaseLineResultTopic",ReqQryNetBaseLineResultTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetMonitorDeviceTaskTopic",ReqQryNetMonitorDeviceTaskTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetLocalPingResultInfoTopic",ReqQryNetLocalPingResultInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetRomotePingResultInfoTopic",ReqQryNetRomotePingResultInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryTradeFrontOrderRttStatTopic",ReqQryTradeFrontOrderRttStatTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryDiskIOTopic",ReqQryDiskIOTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryRouterInfoTopic",ReqQryRouterInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryStatInfoTopic",ReqQryStatInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryClientInfoTopic",ReqQryClientInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryParticTradeOrderStatesTopic",ReqQryParticTradeOrderStatesTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryTradeOrderRttCutLineTopic",ReqQryTradeOrderRttCutLineTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryEventDescriptionTopic",ReqQryEventDescriptionTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryFrontUniqueIDTopic",ReqQryFrontUniqueIDTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetPartyLinkAddrChangeTopic",ReqQryNetPartyLinkAddrChangeTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryNetDelPartyLinkInfoTopic",ReqQryNetDelPartyLinkInfoTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryInstrumentStatusTopic",ReqQryInstrumentStatusTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryCurrTradingSegmentAttrTopic",ReqQryCurrTradingSegmentAttrTopic);
    Nan::SetPrototypeMethod(tpl,"ReqQryPerformanceTopTopic",ReqQryPerformanceTopTopic);
    constructor.Reset(tpl->GetFunction());
    exports->Set(Nan::New("FtdcSysUserApi_Wrapper").ToLocalChecked(), tpl->GetFunction());
}

NAN_METHOD (FtdcSysUserApi_Wrapper::New) {
    if (info.IsConstructCall()) {
        // Invoked as constructor: `new FtdcSysUserApi_Wrapper(...)`
        Local<String> fileData= info[0]->IsUndefined() ? Nan::EmptyString()  : info[0]->ToString();
        String::Utf8Value utf8Str(fileData);
        FtdcSysUserApi_Wrapper* obj = new FtdcSysUserApi_Wrapper(*utf8Str);
        obj->Wrap(info.This());
        info.GetReturnValue().Set(info.This());
    } else {
        // Invoked as plain function `FtdcSysUserApi_Wrapper(...)`, turn into construct call.
        const int argc = 1;
        Local<Value> argv[argc] = { info[0] };
        Local<Function> cons = Nan::New<Function>(constructor);
        info.GetReturnValue().Set(cons->NewInstance(argc, argv));
    }
}

NAN_METHOD (FtdcSysUserApi_Wrapper::Release) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    obj->m_userApi->Release();
    info.GetReturnValue().SetUndefined();
}

NAN_METHOD (FtdcSysUserApi_Wrapper::Init) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    obj->m_userApi->Init();
    info.GetReturnValue().SetUndefined();
}

NAN_METHOD (FtdcSysUserApi_Wrapper::Join) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    int result=obj->m_userApi->Join();
    info.GetReturnValue().Set(Nan::New<v8::Int32>(result));
}

NAN_METHOD (FtdcSysUserApi_Wrapper::GetTradingDay) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    const char* result=obj->m_userApi->GetTradingDay();
    info.GetReturnValue().Set(Nan::New<v8::String>(result).ToLocalChecked());
}

NAN_METHOD (FtdcSysUserApi_Wrapper::RegisterFront) {
    Local<String> fileData= info[0]->IsUndefined() ? Nan::EmptyString()  : info[0]->ToString();
    String::Utf8Value utf8Str(fileData);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());

    obj->m_userApi->RegisterFront(*utf8Str);

    info.GetReturnValue().SetUndefined();
}

int g_idnumb = 0;
NAN_METHOD (FtdcSysUserApi_Wrapper::RegisterSpi) {
    std::cout<<"RegisterSpi Called!"<<std::endl;
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(info[0]->IsObject())
    {
        //obj->m_spi=new SysUserSpi(Nan::To<v8::Object>(info[0]).ToLocalChecked());
        //obj->m_userApi->RegisterSpi(obj->m_spi);
        
        obj->m_spi->m_spiobj.Reset(Nan::To<v8::Object>(info[0]).ToLocalChecked());
        obj->m_spi->m_frontid = GetFrontID();
        obj->m_userApi->RegisterSpi(obj->m_spi);
    }
    info.GetReturnValue().SetUndefined();
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqUserLogin) {
     std::cout<<"ReqUserLogin Called!"<<std::endl;
     FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
     if(!(info[0]->IsObject() && info[1]->IsNumber()))
     {
     Nan::ThrowError("wrong parameter!");
     }
     //convert parameter one
     v8::Local<v8::Object> paraValue=Nan::To<v8::Object>(info[0]).ToLocalChecked();
     CShfeFtdcReqUserLoginField field;
     //TradingDay
     v8::Local<v8::Object> paramOneTradingDayObj=Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("TradingDay").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneTradingDayStr(Nan::To<v8::String>(paramOneTradingDayObj).ToLocalChecked());
     // strcpy_s(field.TradingDay, 9, *paramOneTradingDayStr);
     strncpy(field.TradingDay, *paramOneTradingDayStr,9);
     //UserID
     v8::Local<v8::Object> paramOneUserIDObj=Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneUserIDStr(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
     // strcpy_s(field.UserID, 16, *paramOneUserIDStr);
     strncpy(field.UserID, *paramOneUserIDStr, 16);
     //ParticipantID
     v8::Local<v8::Object> paramOneParticipantIDObj=Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("ParticipantID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneParticipantIDStr(Nan::To<v8::String>(paramOneParticipantIDObj).ToLocalChecked());
     // strcpy_s(field.ParticipantID, 11, *paramOneUserIDStr);
     strncpy(field.ParticipantID, *paramOneUserIDStr, 11);
     //Password
     v8::Local<v8::Object> paramOnePasswordObj=Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("Password").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOnePasswordStr(Nan::To<v8::String>(paramOnePasswordObj).ToLocalChecked());
     // strcpy_s(field.Password, 41, *paramOnePasswordStr);
     strncpy(field.Password, *paramOnePasswordStr, 41);
     //convert parameter two
     v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
     int nRequestID = (int)paramTwo->Value();

     //call natvie method
     double returnValue= obj->m_userApi->ReqUserLogin(&field, nRequestID);

     info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
     
// NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQrySysUserLoginTopic) {
//      std::cout<<"ReqQrySysUserLoginTopic Called!"<<std::endl;
//      FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
//      if(!(info[0]->IsObject() && info[1]->IsNumber()))
//      {
//      Nan::ThrowError("wrong parameter!");
//      }

//      v8::Local<v8::Object> paraValue=Nan::To<v8::Object>(info[0]).ToLocalChecked();
//      CShfeFtdcReqQrySysUserLoginField field;

//      v8::Local<v8::Object> paramOneUserIDObj=Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
//      v8::String::Utf8Value paramOneUserIDStr(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
//      strncpy(field.UserID, *paramOneUserIDStr, 16);

//      v8::Local<v8::Object> paramOnePasswordObj=Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("Password").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
//      v8::String::Utf8Value paramOnePasswordStr(Nan::To<v8::String>(paramOnePasswordObj).ToLocalChecked());
//      CDesEncryptAlgorithm DesEncrypt;
//      DesEncrypt.SetPassword("monitor");
//      char encryptedPassword[256] = {0};
//      DesEncrypt.Encrypt(*paramOnePasswordStr, encryptedPassword);
//      strncpy(field.Password, encryptedPassword, 41);

//      v8::Local<v8::Object> paramOneVersionIDObj=Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("VersionID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
//      v8::String::Utf8Value paramOneVersionIDStr(Nan::To<v8::String>(paramOneVersionIDObj).ToLocalChecked());
//      strncpy(field.VersionID, *paramOneVersionIDStr, 17);

//      v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
//      int nRequestID=(int)paramTwo->Value();

//      double returnValue= obj->m_userApi->ReqQrySysUserLoginTopic(&field, nRequestID);

//      info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
// }


NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryTopCpuInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTopCpuInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryTopCpuInfoField field;

    v8::Local<v8::Object> HostNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value HostNameData(Nan::To<v8::String>(HostNameObj).ToLocalChecked());
    strncpy(field.HostName, *HostNameData, 65);

    v8::Local<v8::Object> CPUObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("CPU").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CPUData(Nan::To<v8::String>(CPUObj).ToLocalChecked());
    strncpy(field.CPU, *CPUData, 6);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> KeepAliveObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> KeepAliveData = Nan::To<v8::Integer>(KeepAliveObj).ToLocalChecked();
    field.KeepAlive = KeepAliveData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryTopCpuInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTopCpuInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryTopMemInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTopMemInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryTopMemInfoField field;

    v8::Local<v8::Object> HostNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value HostNameData(Nan::To<v8::String>(HostNameObj).ToLocalChecked());
    strncpy(field.HostName, *HostNameData, 65);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> KeepAliveObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> KeepAliveData = Nan::To<v8::Integer>(KeepAliveObj).ToLocalChecked();
    field.KeepAlive = KeepAliveData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryTopMemInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTopMemInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryTopProcessInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTopProcessInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryTopProcessInfoField field;

    v8::Local<v8::Object> HostNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value HostNameData(Nan::To<v8::String>(HostNameObj).ToLocalChecked());
    strncpy(field.HostName, *HostNameData, 65);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> KeepAliveObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> KeepAliveData = Nan::To<v8::Integer>(KeepAliveObj).ToLocalChecked();
    field.KeepAlive = KeepAliveData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryTopProcessInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTopProcessInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryFileSystemInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryFileSystemInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryFileSystemInfoField field;

    v8::Local<v8::Object> HostNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value HostNameData(Nan::To<v8::String>(HostNameObj).ToLocalChecked());
    strncpy(field.HostName, *HostNameData, 65);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> KeepAliveObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> KeepAliveData = Nan::To<v8::Integer>(KeepAliveObj).ToLocalChecked();
    field.KeepAlive = KeepAliveData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryFileSystemInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryFileSystemInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetworkInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetworkInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetworkInfoField field;

    v8::Local<v8::Object> HostNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value HostNameData(Nan::To<v8::String>(HostNameObj).ToLocalChecked());
    strncpy(field.HostName, *HostNameData, 65);

    v8::Local<v8::Object> LANNAMEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("LANNAME").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value LANNAMEData(Nan::To<v8::String>(LANNAMEObj).ToLocalChecked());
    strncpy(field.LANNAME, *LANNAMEData, 11);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> KeepAliveObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> KeepAliveData = Nan::To<v8::Integer>(KeepAliveObj).ToLocalChecked();
    field.KeepAlive = KeepAliveData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetworkInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetworkInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryMonitorObjectTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryMonitorObjectTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryMonitorObjectField field;

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 65);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> KeepAliveObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> KeepAliveData = Nan::To<v8::Integer>(KeepAliveObj).ToLocalChecked();
    field.KeepAlive = KeepAliveData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryMonitorObjectTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryMonitorObjectTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryObjectRationalTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryObjectRationalTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryObjectRationalField field;

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 65);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> KeepAliveObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> KeepAliveData = Nan::To<v8::Integer>(KeepAliveObj).ToLocalChecked();
    field.KeepAlive = KeepAliveData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryObjectRationalTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryObjectRationalTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQrySyslogInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySyslogInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQrySyslogInfoField field;

    v8::Local<v8::Object> FileNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("FileName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value FileNameData(Nan::To<v8::String>(FileNameObj).ToLocalChecked());
    strncpy(field.FileName, *FileNameData, 65);

    v8::Local<v8::Object> subFileNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("subFileName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value subFileNameData(Nan::To<v8::String>(subFileNameObj).ToLocalChecked());
    strncpy(field.subFileName, *subFileNameData, 65);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQrySyslogInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySyslogInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQrySubscriberTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySubscriberTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQrySubscriberField field;

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 513);

    v8::Local<v8::Object> ObjectNumObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectNum").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> ObjectNumData = Nan::To<v8::Integer>(ObjectNumObj).ToLocalChecked();
    field.ObjectNum = ObjectNumData->Value();

    v8::Local<v8::Object> KeepAliveObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> KeepAliveData = Nan::To<v8::Integer>(KeepAliveObj).ToLocalChecked();
    field.KeepAlive = KeepAliveData->Value();

    v8::Local<v8::Object> MonDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonDateData(Nan::To<v8::String>(MonDateObj).ToLocalChecked());
    strncpy(field.MonDate, *MonDateData, 9);

    v8::Local<v8::Object> MonTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonTimeData(Nan::To<v8::String>(MonTimeObj).ToLocalChecked());
    strncpy(field.MonTime, *MonTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQrySubscriberTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySubscriberTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryOidRelationTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryOidRelationTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryOidRelationField field;

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 65);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryOidRelationTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryOidRelationTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryUserInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryUserInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryUserInfoField field;

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 65);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryUserInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryUserInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryOnlineUserInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryOnlineUserInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryOnlineUserInfoField field;

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 65);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryOnlineUserInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryOnlineUserInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryWarningEventTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryWarningEventTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryWarningEventField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> WarningLevelObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("WarningLevel").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value WarningLevelData(Nan::To<v8::String>(WarningLevelObj).ToLocalChecked());
    strncpy(field.WarningLevel, *WarningLevelData, 11);

    v8::Local<v8::Object> EventTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> EventTypeData = Nan::To<v8::Integer>(EventTypeObj).ToLocalChecked();
    field.EventType = EventTypeData->Value();

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 257);

    v8::Local<v8::Object> EventNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EventNameData(Nan::To<v8::String>(EventNameObj).ToLocalChecked());
    strncpy(field.EventName, *EventNameData, 65);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryWarningEventTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryWarningEventTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQrySyslogEventTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySyslogEventTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQrySyslogEventField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> EventTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> EventTypeData = Nan::To<v8::Integer>(EventTypeObj).ToLocalChecked();
    field.EventType = EventTypeData->Value();

    v8::Local<v8::Object> WarningLevelObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("WarningLevel").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value WarningLevelData(Nan::To<v8::String>(WarningLevelObj).ToLocalChecked());
    strncpy(field.WarningLevel, *WarningLevelData, 11);

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 257);

    v8::Local<v8::Object> EventNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EventNameData(Nan::To<v8::String>(EventNameObj).ToLocalChecked());
    strncpy(field.EventName, *EventNameData, 65);

    v8::Local<v8::Object> IPAddressObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IPAddress").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IPAddressData(Nan::To<v8::String>(IPAddressObj).ToLocalChecked());
    strncpy(field.IPAddress, *IPAddressData, 16);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQrySyslogEventTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySyslogEventTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQrySyslogEventSubcriberTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySyslogEventSubcriberTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQrySyslogEventSubcriberField field;

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 257);

    v8::Local<v8::Object> EventNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EventNameData(Nan::To<v8::String>(EventNameObj).ToLocalChecked());
    strncpy(field.EventName, *EventNameData, 65);

    v8::Local<v8::Object> WarningLevelObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("WarningLevel").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value WarningLevelData(Nan::To<v8::String>(WarningLevelObj).ToLocalChecked());
    strncpy(field.WarningLevel, *WarningLevelData, 11);

    v8::Local<v8::Object> filterObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("filter").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value filterData(Nan::To<v8::String>(filterObj).ToLocalChecked());
    strncpy(field.filter, *filterData, 513);

    v8::Local<v8::Object> antifilterObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("antifilter").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value antifilterData(Nan::To<v8::String>(antifilterObj).ToLocalChecked());
    strncpy(field.antifilter, *antifilterData, 513);

    v8::Local<v8::Object> ObjectNumObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectNum").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> ObjectNumData = Nan::To<v8::Integer>(ObjectNumObj).ToLocalChecked();
    field.ObjectNum = ObjectNumData->Value();

    v8::Local<v8::Object> KeepAliveObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> KeepAliveData = Nan::To<v8::Integer>(KeepAliveObj).ToLocalChecked();
    field.KeepAlive = KeepAliveData->Value();

    v8::Local<v8::Object> MonDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonDateData(Nan::To<v8::String>(MonDateObj).ToLocalChecked());
    strncpy(field.MonDate, *MonDateData, 9);

    v8::Local<v8::Object> MonTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonTimeData(Nan::To<v8::String>(MonTimeObj).ToLocalChecked());
    strncpy(field.MonTime, *MonTimeData, 9);

    v8::Local<v8::Object> ProcessFlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ProcessFlag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ProcessFlagData(Nan::To<v8::String>(ProcessFlagObj).ToLocalChecked());
    strncpy(field.ProcessFlag, *ProcessFlagData, 2);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQrySyslogEventSubcriberTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySyslogEventSubcriberTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryObjectAttrTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryObjectAttrTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryObjectAttrField field;

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 129);

    v8::Local<v8::Object> AttrTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value AttrTypeData(Nan::To<v8::String>(AttrTypeObj).ToLocalChecked());
    strncpy(field.AttrType, *AttrTypeData, 257);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryObjectAttrTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryObjectAttrTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryInvalidateOrderTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryInvalidateOrderTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryInvalidateOrderField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryInvalidateOrderTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryInvalidateOrderTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryOrderStatusTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryOrderStatusTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryOrderStatusField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryOrderStatusTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryOrderStatusTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryBargainOrderTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryBargainOrderTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryBargainOrderField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryBargainOrderTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryBargainOrderTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryInstPropertyTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryInstPropertyTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryInstPropertyField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryInstPropertyTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryInstPropertyTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryMarginRateTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryMarginRateTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryMarginRateField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryMarginRateTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryMarginRateTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryPriceLimitTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryPriceLimitTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryPriceLimitField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryPriceLimitTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryPriceLimitTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryPartPosiLimitTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryPartPosiLimitTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryPartPosiLimitField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryPartPosiLimitTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryPartPosiLimitTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryClientPosiLimitTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryClientPosiLimitTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryClientPosiLimitField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryClientPosiLimitTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryClientPosiLimitTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQrySpecialPosiLimitTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySpecialPosiLimitTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQrySpecialPosiLimitField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQrySpecialPosiLimitTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySpecialPosiLimitTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryTransactionChgTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTransactionChgTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryTransactionChgField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryTransactionChgTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTransactionChgTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryClientChgTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryClientChgTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryClientChgField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryClientChgTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryClientChgTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryPartClientChgTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryPartClientChgTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryPartClientChgField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryPartClientChgTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryPartClientChgTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryPosiLimitChgTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryPosiLimitChgTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryPosiLimitChgField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryPosiLimitChgTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryPosiLimitChgTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryClientPosiLimitChgTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryClientPosiLimitChgTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryClientPosiLimitChgField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryClientPosiLimitChgTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryClientPosiLimitChgTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQrySpecPosiLimitChgTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySpecPosiLimitChgTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQrySpecPosiLimitChgField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQrySpecPosiLimitChgTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySpecPosiLimitChgTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryHedgeDetailChgTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryHedgeDetailChgTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryHedgeDetailChgField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryHedgeDetailChgTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryHedgeDetailChgTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryParticipantChgTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryParticipantChgTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryParticipantChgField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryParticipantChgTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryParticipantChgTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryMarginRateChgTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryMarginRateChgTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryMarginRateChgField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryMarginRateChgTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryMarginRateChgTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryUserIpChgTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryUserIpChgTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryUserIpChgField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryUserIpChgTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryUserIpChgTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryHistoryObjectAttrTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryHistoryObjectAttrTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryHistoryObjectAttrField field;

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 129);

    v8::Local<v8::Object> AttrTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value AttrTypeData(Nan::To<v8::String>(AttrTypeObj).ToLocalChecked());
    strncpy(field.AttrType, *AttrTypeData, 257);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryHistoryObjectAttrTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryHistoryObjectAttrTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryFrontInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryFrontInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryFrontInfoField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryFrontInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryFrontInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQrySysUserLoginTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySysUserLoginTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQrySysUserLoginField field;

    v8::Local<v8::Object> UserIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value UserIDData(Nan::To<v8::String>(UserIDObj).ToLocalChecked());
    strncpy(field.UserID, *UserIDData, 16);

    v8::Local<v8::Object> PasswordObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Password").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value PasswordData(Nan::To<v8::String>(PasswordObj).ToLocalChecked());
    strncpy(field.Password, *PasswordData, 41);

    v8::Local<v8::Object> VersionIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("VersionID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value VersionIDData(Nan::To<v8::String>(VersionIDObj).ToLocalChecked());
    strncpy(field.VersionID, *VersionIDData, 17);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQrySysUserLoginTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySysUserLoginTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQrySysUserLogoutTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySysUserLogoutTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQrySysUserLogoutField field;

    v8::Local<v8::Object> UserIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value UserIDData(Nan::To<v8::String>(UserIDObj).ToLocalChecked());
    strncpy(field.UserID, *UserIDData, 16);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQrySysUserLogoutTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySysUserLogoutTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQrySysUserPasswordUpdateTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySysUserPasswordUpdateTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQrySysUserPasswordUpdateField field;

    v8::Local<v8::Object> UserIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value UserIDData(Nan::To<v8::String>(UserIDObj).ToLocalChecked());
    strncpy(field.UserID, *UserIDData, 16);

    v8::Local<v8::Object> OldPasswordObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OldPassword").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value OldPasswordData(Nan::To<v8::String>(OldPasswordObj).ToLocalChecked());
    strncpy(field.OldPassword, *OldPasswordData, 41);

    v8::Local<v8::Object> NewPasswordObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("NewPassword").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value NewPasswordData(Nan::To<v8::String>(NewPasswordObj).ToLocalChecked());
    strncpy(field.NewPassword, *NewPasswordData, 41);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQrySysUserPasswordUpdateTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySysUserPasswordUpdateTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQrySysUserRegisterTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySysUserRegisterTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQrySysUserRegisterField field;

    v8::Local<v8::Object> UserIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value UserIDData(Nan::To<v8::String>(UserIDObj).ToLocalChecked());
    strncpy(field.UserID, *UserIDData, 16);

    v8::Local<v8::Object> UserNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("UserName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value UserNameData(Nan::To<v8::String>(UserNameObj).ToLocalChecked());
    strncpy(field.UserName, *UserNameData, 16);

    v8::Local<v8::Object> UserInfoObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("UserInfo").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value UserInfoData(Nan::To<v8::String>(UserInfoObj).ToLocalChecked());
    strncpy(field.UserInfo, *UserInfoData, 100);

    v8::Local<v8::Object> PasswordObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Password").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value PasswordData(Nan::To<v8::String>(PasswordObj).ToLocalChecked());
    strncpy(field.Password, *PasswordData, 41);

    v8::Local<v8::Object> PrivilegeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Privilege").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> PrivilegeData = Nan::To<v8::Integer>(PrivilegeObj).ToLocalChecked();
    field.Privilege = PrivilegeData->Value();

    v8::Local<v8::Object> EMailObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EMail").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EMailData(Nan::To<v8::String>(EMailObj).ToLocalChecked());
    strncpy(field.EMail, *EMailData, 51);

    v8::Local<v8::Object> EMailFlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EMailFlag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> EMailFlagData = Nan::To<v8::Integer>(EMailFlagObj).ToLocalChecked();
    field.EMailFlag = EMailFlagData->Value();

    v8::Local<v8::Object> HomePhoneObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("HomePhone").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value HomePhoneData(Nan::To<v8::String>(HomePhoneObj).ToLocalChecked());
    strncpy(field.HomePhone, *HomePhoneData, 31);

    v8::Local<v8::Object> HomePhoneFlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("HomePhoneFlag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> HomePhoneFlagData = Nan::To<v8::Integer>(HomePhoneFlagObj).ToLocalChecked();
    field.HomePhoneFlag = HomePhoneFlagData->Value();

    v8::Local<v8::Object> MobilePhoneObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MobilePhone").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MobilePhoneData(Nan::To<v8::String>(MobilePhoneObj).ToLocalChecked());
    strncpy(field.MobilePhone, *MobilePhoneData, 31);

    v8::Local<v8::Object> MobilePhoneFlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MobilePhoneFlag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> MobilePhoneFlagData = Nan::To<v8::Integer>(MobilePhoneFlagObj).ToLocalChecked();
    field.MobilePhoneFlag = MobilePhoneFlagData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQrySysUserRegisterTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySysUserRegisterTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQrySysUserDeleteTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySysUserDeleteTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQrySysUserDeleteField field;

    v8::Local<v8::Object> UserIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value UserIDData(Nan::To<v8::String>(UserIDObj).ToLocalChecked());
    strncpy(field.UserID, *UserIDData, 16);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQrySysUserDeleteTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySysUserDeleteTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryTradeLogTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTradeLogTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryTradeLogField field;

    v8::Local<v8::Object> TradingDayObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TradingDay").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value TradingDayData(Nan::To<v8::String>(TradingDayObj).ToLocalChecked());
    strncpy(field.TradingDay, *TradingDayData, 9);

    v8::Local<v8::Object> IPAddressObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IPAddress").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IPAddressData(Nan::To<v8::String>(IPAddressObj).ToLocalChecked());
    strncpy(field.IPAddress, *IPAddressData, 16);

    v8::Local<v8::Object> FrontIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("FrontID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value FrontIDData(Nan::To<v8::String>(FrontIDObj).ToLocalChecked());
    strncpy(field.FrontID, *FrontIDData, 9);

    v8::Local<v8::Object> StartParticipantObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartParticipant").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartParticipantData(Nan::To<v8::String>(StartParticipantObj).ToLocalChecked());
    strncpy(field.StartParticipant, *StartParticipantData, 11);

    v8::Local<v8::Object> EndParticipantObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndParticipant").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndParticipantData(Nan::To<v8::String>(EndParticipantObj).ToLocalChecked());
    strncpy(field.EndParticipant, *EndParticipantData, 11);

    v8::Local<v8::Object> StartUserObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartUser").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartUserData(Nan::To<v8::String>(StartUserObj).ToLocalChecked());
    strncpy(field.StartUser, *StartUserData, 16);

    v8::Local<v8::Object> EndUserObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndUser").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndUserData(Nan::To<v8::String>(EndUserObj).ToLocalChecked());
    strncpy(field.EndUser, *EndUserData, 16);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> StartSessionIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartSessionID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartSessionIDData(Nan::To<v8::String>(StartSessionIDObj).ToLocalChecked());
    strncpy(field.StartSessionID, *StartSessionIDData, 9);

    v8::Local<v8::Object> EndSessionIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndSessionID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndSessionIDData(Nan::To<v8::String>(EndSessionIDObj).ToLocalChecked());
    strncpy(field.EndSessionID, *EndSessionIDData, 9);

    v8::Local<v8::Object> IPFlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IPFlag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IPFlagData = Nan::To<v8::Integer>(IPFlagObj).ToLocalChecked();
    field.IPFlag = IPFlagData->Value();

    v8::Local<v8::Object> PartFlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("PartFlag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> PartFlagData = Nan::To<v8::Integer>(PartFlagObj).ToLocalChecked();
    field.PartFlag = PartFlagData->Value();

    v8::Local<v8::Object> UserIDFlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("UserIDFlag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> UserIDFlagData = Nan::To<v8::Integer>(UserIDFlagObj).ToLocalChecked();
    field.UserIDFlag = UserIDFlagData->Value();

    v8::Local<v8::Object> TimeFlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TimeFlag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> TimeFlagData = Nan::To<v8::Integer>(TimeFlagObj).ToLocalChecked();
    field.TimeFlag = TimeFlagData->Value();

    v8::Local<v8::Object> FrontFlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("FrontFlag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> FrontFlagData = Nan::To<v8::Integer>(FrontFlagObj).ToLocalChecked();
    field.FrontFlag = FrontFlagData->Value();

    v8::Local<v8::Object> SessionFlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SessionFlag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> SessionFlagData = Nan::To<v8::Integer>(SessionFlagObj).ToLocalChecked();
    field.SessionFlag = SessionFlagData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryTradeLogTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTradeLogTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryParticipantInitTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryParticipantInitTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryParticipantInitField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryParticipantInitTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryParticipantInitTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryUserInitTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryUserInitTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryUserInitField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryUserInitTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryUserInitTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryWarningEventUpdateTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryWarningEventUpdateTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryWarningEventUpdateField field;

    v8::Local<v8::Object> MonDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonDateData(Nan::To<v8::String>(MonDateObj).ToLocalChecked());
    strncpy(field.MonDate, *MonDateData, 9);

    v8::Local<v8::Object> MonTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonTimeData(Nan::To<v8::String>(MonTimeObj).ToLocalChecked());
    strncpy(field.MonTime, *MonTimeData, 9);

    v8::Local<v8::Object> OccurDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OccurDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value OccurDateData(Nan::To<v8::String>(OccurDateObj).ToLocalChecked());
    strncpy(field.OccurDate, *OccurDateData, 9);

    v8::Local<v8::Object> OccurTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OccurTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value OccurTimeData(Nan::To<v8::String>(OccurTimeObj).ToLocalChecked());
    strncpy(field.OccurTime, *OccurTimeData, 9);

    v8::Local<v8::Object> EvendIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EvendID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> EvendIDData = Nan::To<v8::Integer>(EvendIDObj).ToLocalChecked();
    field.EvendID = EvendIDData->Value();

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 257);

    v8::Local<v8::Object> IPAddressObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IPAddress").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IPAddressData(Nan::To<v8::String>(IPAddressObj).ToLocalChecked());
    strncpy(field.IPAddress, *IPAddressData, 16);

    v8::Local<v8::Object> EventNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EventNameData(Nan::To<v8::String>(EventNameObj).ToLocalChecked());
    strncpy(field.EventName, *EventNameData, 65);

    v8::Local<v8::Object> EventNumObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventNum").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> EventNumData = Nan::To<v8::Integer>(EventNumObj).ToLocalChecked();
    field.EventNum = EventNumData->Value();

    v8::Local<v8::Object> EventTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> EventTypeData = Nan::To<v8::Integer>(EventTypeObj).ToLocalChecked();
    field.EventType = EventTypeData->Value();

    v8::Local<v8::Object> EventDesObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventDes").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EventDesData(Nan::To<v8::String>(EventDesObj).ToLocalChecked());
    strncpy(field.EventDes, *EventDesData, 513);

    v8::Local<v8::Object> ProcessFlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ProcessFlag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ProcessFlagData(Nan::To<v8::String>(ProcessFlagObj).ToLocalChecked());
    strncpy(field.ProcessFlag, *ProcessFlagData, 2);

    v8::Local<v8::Object> WarningLevelObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("WarningLevel").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value WarningLevelData(Nan::To<v8::String>(WarningLevelObj).ToLocalChecked());
    strncpy(field.WarningLevel, *WarningLevelData, 11);

    v8::Local<v8::Object> ActiveDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ActiveDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ActiveDateData(Nan::To<v8::String>(ActiveDateObj).ToLocalChecked());
    strncpy(field.ActiveDate, *ActiveDateData, 9);

    v8::Local<v8::Object> ActiveTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ActiveTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ActiveTimeData(Nan::To<v8::String>(ActiveTimeObj).ToLocalChecked());
    strncpy(field.ActiveTime, *ActiveTimeData, 9);

    v8::Local<v8::Object> EventDealDesObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventDealDes").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EventDealDesData(Nan::To<v8::String>(EventDealDesObj).ToLocalChecked());
    strncpy(field.EventDealDes, *EventDealDesData, 65);

    v8::Local<v8::Object> FullEventNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("FullEventName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value FullEventNameData(Nan::To<v8::String>(FullEventNameObj).ToLocalChecked());
    strncpy(field.FullEventName, *FullEventNameData, 257);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryWarningEventUpdateTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryWarningEventUpdateTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryTradeUserLoginInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTradeUserLoginInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryTradeUserLoginInfoField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryTradeUserLoginInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTradeUserLoginInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryPartTradeTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryPartTradeTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryPartTradeField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryPartTradeTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryPartTradeTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryTradepeakTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTradepeakTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryTradepeakField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> TradepeakFlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TradepeakFlag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> TradepeakFlagData = Nan::To<v8::Integer>(TradepeakFlagObj).ToLocalChecked();
    field.TradepeakFlag = TradepeakFlagData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryTradepeakTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTradepeakTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryHistoryCpuInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryHistoryCpuInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryHistoryCpuInfoField field;

    v8::Local<v8::Object> HostNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value HostNameData(Nan::To<v8::String>(HostNameObj).ToLocalChecked());
    strncpy(field.HostName, *HostNameData, 65);

    v8::Local<v8::Object> CPUObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("CPU").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CPUData(Nan::To<v8::String>(CPUObj).ToLocalChecked());
    strncpy(field.CPU, *CPUData, 6);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> KeepAliveObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> KeepAliveData = Nan::To<v8::Integer>(KeepAliveObj).ToLocalChecked();
    field.KeepAlive = KeepAliveData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryHistoryCpuInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryHistoryCpuInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryHistoryMemInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryHistoryMemInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryHistoryMemInfoField field;

    v8::Local<v8::Object> HostNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value HostNameData(Nan::To<v8::String>(HostNameObj).ToLocalChecked());
    strncpy(field.HostName, *HostNameData, 65);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> KeepAliveObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> KeepAliveData = Nan::To<v8::Integer>(KeepAliveObj).ToLocalChecked();
    field.KeepAlive = KeepAliveData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryHistoryMemInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryHistoryMemInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryHistoryNetworkInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryHistoryNetworkInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryHistoryNetworkInfoField field;

    v8::Local<v8::Object> HostNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value HostNameData(Nan::To<v8::String>(HostNameObj).ToLocalChecked());
    strncpy(field.HostName, *HostNameData, 65);

    v8::Local<v8::Object> LANNAMEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("LANNAME").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value LANNAMEData(Nan::To<v8::String>(LANNAMEObj).ToLocalChecked());
    strncpy(field.LANNAME, *LANNAMEData, 11);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> KeepAliveObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> KeepAliveData = Nan::To<v8::Integer>(KeepAliveObj).ToLocalChecked();
    field.KeepAlive = KeepAliveData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryHistoryNetworkInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryHistoryNetworkInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryMonitorOnlineUser) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryMonitorOnlineUser: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryMonitorOnlineUserField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryMonitorOnlineUser(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryMonitorOnlineUser: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryFrontStat) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryFrontStat: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryFrontStatField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryFrontStat(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryFrontStat: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryHistoryTradePeakTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryHistoryTradePeakTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryHistoryTradePeakField field;

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryHistoryTradePeakTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryHistoryTradePeakTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryTomcatInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTomcatInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryTomcatInfoField field;

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 65);

    v8::Local<v8::Object> SubObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SubObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value SubObjectIDData(Nan::To<v8::String>(SubObjectIDObj).ToLocalChecked());
    strncpy(field.SubObjectID, *SubObjectIDData, 65);

    v8::Local<v8::Object> AttrTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value AttrTypeData(Nan::To<v8::String>(AttrTypeObj).ToLocalChecked());
    strncpy(field.AttrType, *AttrTypeData, 257);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryTomcatInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTomcatInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryDBQueryTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryDBQueryTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryDBQueryField field;

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 65);

    v8::Local<v8::Object> AttrTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value AttrTypeData(Nan::To<v8::String>(AttrTypeObj).ToLocalChecked());
    strncpy(field.AttrType, *AttrTypeData, 65);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryDBQueryTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryDBQueryTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryGetFileTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryGetFileTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryGetFileField field;

    v8::Local<v8::Object> FileNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("FileName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value FileNameData(Nan::To<v8::String>(FileNameObj).ToLocalChecked());
    strncpy(field.FileName, *FileNameData, 257);

    v8::Local<v8::Object> VersionObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Version").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value VersionData(Nan::To<v8::String>(VersionObj).ToLocalChecked());
    strncpy(field.Version, *VersionData, 17);

    v8::Local<v8::Object> OffsetObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Offset").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OffsetData = Nan::To<v8::Integer>(OffsetObj).ToLocalChecked();
    field.Offset = OffsetData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryGetFileTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryGetFileTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQrySyslogEventUpdateTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySyslogEventUpdateTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQrySyslogEventUpdateField field;

    v8::Local<v8::Object> MonDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonDateData(Nan::To<v8::String>(MonDateObj).ToLocalChecked());
    strncpy(field.MonDate, *MonDateData, 9);

    v8::Local<v8::Object> MonTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonTimeData(Nan::To<v8::String>(MonTimeObj).ToLocalChecked());
    strncpy(field.MonTime, *MonTimeData, 9);

    v8::Local<v8::Object> OccurDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OccurDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value OccurDateData(Nan::To<v8::String>(OccurDateObj).ToLocalChecked());
    strncpy(field.OccurDate, *OccurDateData, 9);

    v8::Local<v8::Object> OccurTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OccurTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value OccurTimeData(Nan::To<v8::String>(OccurTimeObj).ToLocalChecked());
    strncpy(field.OccurTime, *OccurTimeData, 9);

    v8::Local<v8::Object> EvendIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EvendID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> EvendIDData = Nan::To<v8::Integer>(EvendIDObj).ToLocalChecked();
    field.EvendID = EvendIDData->Value();

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 257);

    v8::Local<v8::Object> IPAddressObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IPAddress").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IPAddressData(Nan::To<v8::String>(IPAddressObj).ToLocalChecked());
    strncpy(field.IPAddress, *IPAddressData, 16);

    v8::Local<v8::Object> EventNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EventNameData(Nan::To<v8::String>(EventNameObj).ToLocalChecked());
    strncpy(field.EventName, *EventNameData, 65);

    v8::Local<v8::Object> EventNumObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventNum").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> EventNumData = Nan::To<v8::Integer>(EventNumObj).ToLocalChecked();
    field.EventNum = EventNumData->Value();

    v8::Local<v8::Object> EventTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> EventTypeData = Nan::To<v8::Integer>(EventTypeObj).ToLocalChecked();
    field.EventType = EventTypeData->Value();

    v8::Local<v8::Object> EventDesObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventDes").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EventDesData(Nan::To<v8::String>(EventDesObj).ToLocalChecked());
    strncpy(field.EventDes, *EventDesData, 513);

    v8::Local<v8::Object> ProcessFlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ProcessFlag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ProcessFlagData(Nan::To<v8::String>(ProcessFlagObj).ToLocalChecked());
    strncpy(field.ProcessFlag, *ProcessFlagData, 2);

    v8::Local<v8::Object> WarningLevelObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("WarningLevel").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value WarningLevelData(Nan::To<v8::String>(WarningLevelObj).ToLocalChecked());
    strncpy(field.WarningLevel, *WarningLevelData, 11);

    v8::Local<v8::Object> EventDealDesObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventDealDes").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EventDealDesData(Nan::To<v8::String>(EventDealDesObj).ToLocalChecked());
    strncpy(field.EventDealDes, *EventDealDesData, 65);

    v8::Local<v8::Object> FullEventNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("FullEventName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value FullEventNameData(Nan::To<v8::String>(FullEventNameObj).ToLocalChecked());
    strncpy(field.FullEventName, *FullEventNameData, 257);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQrySyslogEventUpdateTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQrySyslogEventUpdateTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryWarningQueryTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryWarningQueryTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryWarningQueryField field;

    v8::Local<v8::Object> EvendIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EvendID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> EvendIDData = Nan::To<v8::Integer>(EvendIDObj).ToLocalChecked();
    field.EvendID = EvendIDData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryWarningQueryTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryWarningQueryTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryWebVisitTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryWebVisitTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryWebVisitField field;

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 65);

    v8::Local<v8::Object> AttrTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value AttrTypeData(Nan::To<v8::String>(AttrTypeObj).ToLocalChecked());
    strncpy(field.AttrType, *AttrTypeData, 257);

    v8::Local<v8::Object> BeginDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("BeginDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value BeginDateData(Nan::To<v8::String>(BeginDateObj).ToLocalChecked());
    strncpy(field.BeginDate, *BeginDateData, 9);

    v8::Local<v8::Object> BeginTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("BeginTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value BeginTimeData(Nan::To<v8::String>(BeginTimeObj).ToLocalChecked());
    strncpy(field.BeginTime, *BeginTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryWebVisitTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryWebVisitTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryWarningActiveChange) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryWarningActiveChange: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryWarningActiveChangeField field;

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 65);

    v8::Local<v8::Object> MonDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonDateData(Nan::To<v8::String>(MonDateObj).ToLocalChecked());
    strncpy(field.MonDate, *MonDateData, 9);

    v8::Local<v8::Object> MonTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonTimeData(Nan::To<v8::String>(MonTimeObj).ToLocalChecked());
    strncpy(field.MonTime, *MonTimeData, 9);

    v8::Local<v8::Object> WarningActiveObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("WarningActive").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> WarningActiveData = Nan::To<v8::Integer>(WarningActiveObj).ToLocalChecked();
    field.WarningActive = WarningActiveData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryWarningActiveChange(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryWarningActiveChange: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryTradeUserLoginStatTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTradeUserLoginStatTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryTradeUserLoginStatField field;

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 65);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryTradeUserLoginStatTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTradeUserLoginStatTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryGeneralOperateTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryGeneralOperateTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryGeneralOperateField field;

    v8::Local<v8::Object> GeneralOperateTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("GeneralOperateType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> GeneralOperateTypeData = Nan::To<v8::Integer>(GeneralOperateTypeObj).ToLocalChecked();
    field.GeneralOperateType = GeneralOperateTypeData->Value();

    v8::Local<v8::Object> GeneralOperateTableObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("GeneralOperateTable").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value GeneralOperateTableData(Nan::To<v8::String>(GeneralOperateTableObj).ToLocalChecked());
    strncpy(field.GeneralOperateTable, *GeneralOperateTableData, 129);

    v8::Local<v8::Object> GeneralOperateOptionObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("GeneralOperateOption").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value GeneralOperateOptionData(Nan::To<v8::String>(GeneralOperateOptionObj).ToLocalChecked());
    strncpy(field.GeneralOperateOption, *GeneralOperateOptionData, 801);

    v8::Local<v8::Object> GeneralOperateSetObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("GeneralOperateSet").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value GeneralOperateSetData(Nan::To<v8::String>(GeneralOperateSetObj).ToLocalChecked());
    strncpy(field.GeneralOperateSet, *GeneralOperateSetData, 3001);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryGeneralOperateTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryGeneralOperateTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetDeviceLinkedTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetDeviceLinkedTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetDeviceLinkedField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> SysNetSubAreaIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SysNetSubAreaID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> SysNetSubAreaIDData = Nan::To<v8::Integer>(SysNetSubAreaIDObj).ToLocalChecked();
    field.SysNetSubAreaID = SysNetSubAreaIDData->Value();

    v8::Local<v8::Object> FuctionAreaObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("FuctionArea").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value FuctionAreaData(Nan::To<v8::String>(FuctionAreaObj).ToLocalChecked());
    strncpy(field.FuctionArea, *FuctionAreaData, 65);

    v8::Local<v8::Object> IPDECODEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IPDECODE").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IPDECODEData = Nan::To<v8::Integer>(IPDECODEObj).ToLocalChecked();
    field.IPDECODE = IPDECODEData->Value();

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 129);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetDeviceLinkedTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetDeviceLinkedTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryRealTimeNetObjectAttrTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryRealTimeNetObjectAttrTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryRealTimeNetObjectAttrField field;

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 129);

    v8::Local<v8::Object> AttrTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value AttrTypeData(Nan::To<v8::String>(AttrTypeObj).ToLocalChecked());
    strncpy(field.AttrType, *AttrTypeData, 257);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryRealTimeNetObjectAttrTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryRealTimeNetObjectAttrTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetAreaTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetAreaTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetAreaField field;

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetAreaTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetAreaTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetSubAreaTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetSubAreaTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetSubAreaField field;

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> SysNetAreaIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SysNetAreaID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> SysNetAreaIDData = Nan::To<v8::Integer>(SysNetAreaIDObj).ToLocalChecked();
    field.SysNetAreaID = SysNetAreaIDData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetSubAreaTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetSubAreaTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetSubAreaIPTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetSubAreaIPTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetSubAreaIPField field;

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> SysNetAreaIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SysNetAreaID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> SysNetAreaIDData = Nan::To<v8::Integer>(SysNetAreaIDObj).ToLocalChecked();
    field.SysNetAreaID = SysNetAreaIDData->Value();

    v8::Local<v8::Object> SysNetSubAreaIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SysNetSubAreaID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> SysNetSubAreaIDData = Nan::To<v8::Integer>(SysNetSubAreaIDObj).ToLocalChecked();
    field.SysNetSubAreaID = SysNetSubAreaIDData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetSubAreaIPTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetSubAreaIPTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetDeviceDetectTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetDeviceDetectTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetDeviceDetectField field;

    v8::Local<v8::Object> SysNetAreaIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SysNetAreaID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> SysNetAreaIDData = Nan::To<v8::Integer>(SysNetAreaIDObj).ToLocalChecked();
    field.SysNetAreaID = SysNetAreaIDData->Value();

    v8::Local<v8::Object> SysNetSubAreaIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SysNetSubAreaID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> SysNetSubAreaIDData = Nan::To<v8::Integer>(SysNetSubAreaIDObj).ToLocalChecked();
    field.SysNetSubAreaID = SysNetSubAreaIDData->Value();

    v8::Local<v8::Object> IPObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IP").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IPData(Nan::To<v8::String>(IPObj).ToLocalChecked());
    strncpy(field.IP, *IPData, 16);

    v8::Local<v8::Object> MaskObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Mask").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MaskData(Nan::To<v8::String>(MaskObj).ToLocalChecked());
    strncpy(field.Mask, *MaskData, 16);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetDeviceDetectTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetDeviceDetectTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetDeviceRequestTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetDeviceRequestTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetDeviceRequestField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> SysNetSubAreaIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SysNetSubAreaID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> SysNetSubAreaIDData = Nan::To<v8::Integer>(SysNetSubAreaIDObj).ToLocalChecked();
    field.SysNetSubAreaID = SysNetSubAreaIDData->Value();

    v8::Local<v8::Object> FuctionAreaObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("FuctionArea").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value FuctionAreaData(Nan::To<v8::String>(FuctionAreaObj).ToLocalChecked());
    strncpy(field.FuctionArea, *FuctionAreaData, 65);

    v8::Local<v8::Object> IPDECODEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IPDECODE").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IPDECODEData = Nan::To<v8::Integer>(IPDECODEObj).ToLocalChecked();
    field.IPDECODE = IPDECODEData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetDeviceRequestTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetDeviceRequestTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetBuildingTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetBuildingTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetBuildingField field;

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetBuildingTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetBuildingTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetRoomTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetRoomTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetRoomField field;

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> SysNetBuildingIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SysNetBuildingID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> SysNetBuildingIDData = Nan::To<v8::Integer>(SysNetBuildingIDObj).ToLocalChecked();
    field.SysNetBuildingID = SysNetBuildingIDData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetRoomTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetRoomTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetCabinetsTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetCabinetsTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetCabinetsField field;

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> SysNetRoomIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SysNetRoomID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> SysNetRoomIDData = Nan::To<v8::Integer>(SysNetRoomIDObj).ToLocalChecked();
    field.SysNetRoomID = SysNetRoomIDData->Value();

    v8::Local<v8::Object> SysNetBuildingIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SysNetBuildingID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> SysNetBuildingIDData = Nan::To<v8::Integer>(SysNetBuildingIDObj).ToLocalChecked();
    field.SysNetBuildingID = SysNetBuildingIDData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetCabinetsTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetCabinetsTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetOIDTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetOIDTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetOIDField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> ManufactoryObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Manufactory").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ManufactoryData(Nan::To<v8::String>(ManufactoryObj).ToLocalChecked());
    strncpy(field.Manufactory, *ManufactoryData, 65);

    v8::Local<v8::Object> DeviceTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DeviceType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value DeviceTypeData(Nan::To<v8::String>(DeviceTypeObj).ToLocalChecked());
    strncpy(field.DeviceType, *DeviceTypeData, 65);

    v8::Local<v8::Object> CNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CNameData(Nan::To<v8::String>(CNameObj).ToLocalChecked());
    strncpy(field.CName, *CNameData, 65);

    v8::Local<v8::Object> ENameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ENameData(Nan::To<v8::String>(ENameObj).ToLocalChecked());
    strncpy(field.EName, *ENameData, 65);

    v8::Local<v8::Object> OIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value OIDData(Nan::To<v8::String>(OIDObj).ToLocalChecked());
    strncpy(field.OID, *OIDData, 65);

    v8::Local<v8::Object> UnitObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Unit").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value UnitData(Nan::To<v8::String>(UnitObj).ToLocalChecked());
    strncpy(field.Unit, *UnitData, 65);

    v8::Local<v8::Object> isTheTableObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("isTheTable").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> isTheTableData = Nan::To<v8::Integer>(isTheTableObj).ToLocalChecked();
    field.isTheTable = isTheTableData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetOIDTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetOIDTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetTimePolicyTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetTimePolicyTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetTimePolicyField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> CNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CNameData(Nan::To<v8::String>(CNameObj).ToLocalChecked());
    strncpy(field.CName, *CNameData, 65);

    v8::Local<v8::Object> ENameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ENameData(Nan::To<v8::String>(ENameObj).ToLocalChecked());
    strncpy(field.EName, *ENameData, 65);

    v8::Local<v8::Object> PolicyTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("PolicyType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> PolicyTypeData = Nan::To<v8::Integer>(PolicyTypeObj).ToLocalChecked();
    field.PolicyType = PolicyTypeData->Value();

    v8::Local<v8::Object> PolicyStringObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("PolicyString").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value PolicyStringData(Nan::To<v8::String>(PolicyStringObj).ToLocalChecked());
    strncpy(field.PolicyString, *PolicyStringData, 513);

    v8::Local<v8::Object> TradingDayObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TradingDay").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> TradingDayData = Nan::To<v8::Integer>(TradingDayObj).ToLocalChecked();
    field.TradingDay = TradingDayData->Value();

    v8::Local<v8::Object> DescriptionObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Description").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value DescriptionData(Nan::To<v8::String>(DescriptionObj).ToLocalChecked());
    strncpy(field.Description, *DescriptionData, 257);

    v8::Local<v8::Object> OperationObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Operation").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationData = Nan::To<v8::Integer>(OperationObj).ToLocalChecked();
    field.Operation = OperationData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetTimePolicyTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetTimePolicyTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetGatherTaskTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetGatherTaskTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetGatherTaskField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 129);

    v8::Local<v8::Object> AttrTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value AttrTypeData(Nan::To<v8::String>(AttrTypeObj).ToLocalChecked());
    strncpy(field.AttrType, *AttrTypeData, 257);

    v8::Local<v8::Object> PolicyTypeIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("PolicyTypeID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> PolicyTypeIDData = Nan::To<v8::Integer>(PolicyTypeIDObj).ToLocalChecked();
    field.PolicyTypeID = PolicyTypeIDData->Value();

    v8::Local<v8::Object> DataTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DataType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> DataTypeData = Nan::To<v8::Integer>(DataTypeObj).ToLocalChecked();
    field.DataType = DataTypeData->Value();

    v8::Local<v8::Object> TypeFlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TypeFlag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> TypeFlagData = Nan::To<v8::Integer>(TypeFlagObj).ToLocalChecked();
    field.TypeFlag = TypeFlagData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetGatherTaskTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetGatherTaskTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetDeviceChgTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetDeviceChgTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetDeviceChgField field;

    v8::Local<v8::Object> DeviceIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DeviceID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> DeviceIDData = Nan::To<v8::Integer>(DeviceIDObj).ToLocalChecked();
    field.DeviceID = DeviceIDData->Value();

    v8::Local<v8::Object> SysNetSubAreaIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SysNetSubAreaID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> SysNetSubAreaIDData = Nan::To<v8::Integer>(SysNetSubAreaIDObj).ToLocalChecked();
    field.SysNetSubAreaID = SysNetSubAreaIDData->Value();

    v8::Local<v8::Object> OldObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OldObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value OldObjectIDData(Nan::To<v8::String>(OldObjectIDObj).ToLocalChecked());
    strncpy(field.OldObjectID, *OldObjectIDData, 129);

    v8::Local<v8::Object> NewObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("NewObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value NewObjectIDData(Nan::To<v8::String>(NewObjectIDObj).ToLocalChecked());
    strncpy(field.NewObjectID, *NewObjectIDData, 129);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetDeviceChgTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetDeviceChgTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetDeviceTypeTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetDeviceTypeTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetDeviceTypeField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> ManufactoryObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Manufactory").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ManufactoryData(Nan::To<v8::String>(ManufactoryObj).ToLocalChecked());
    strncpy(field.Manufactory, *ManufactoryData, 65);

    v8::Local<v8::Object> DeviceTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DeviceType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value DeviceTypeData(Nan::To<v8::String>(DeviceTypeObj).ToLocalChecked());
    strncpy(field.DeviceType, *DeviceTypeData, 65);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetDeviceTypeTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetDeviceTypeTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetDeviceCategoryTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetDeviceCategoryTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetDeviceCategoryField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> CNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CNameData(Nan::To<v8::String>(CNameObj).ToLocalChecked());
    strncpy(field.CName, *CNameData, 65);

    v8::Local<v8::Object> ENameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ENameData(Nan::To<v8::String>(ENameObj).ToLocalChecked());
    strncpy(field.EName, *ENameData, 65);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetDeviceCategoryTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetDeviceCategoryTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetManufactoryTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetManufactoryTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetManufactoryField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> CNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CNameData(Nan::To<v8::String>(CNameObj).ToLocalChecked());
    strncpy(field.CName, *CNameData, 65);

    v8::Local<v8::Object> ENameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ENameData(Nan::To<v8::String>(ENameObj).ToLocalChecked());
    strncpy(field.EName, *ENameData, 65);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetManufactoryTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetManufactoryTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetCommunityTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetCommunityTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetCommunityField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> IPADDRObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IPADDR").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IPADDRData(Nan::To<v8::String>(IPADDRObj).ToLocalChecked());
    strncpy(field.IPADDR, *IPADDRData, 16);

    v8::Local<v8::Object> COMMUNITYObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("COMMUNITY").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value COMMUNITYData(Nan::To<v8::String>(COMMUNITYObj).ToLocalChecked());
    strncpy(field.COMMUNITY, *COMMUNITYData, 65);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetCommunityTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetCommunityTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetPortTypeTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetPortTypeTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetPortTypeField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> CNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CNameData(Nan::To<v8::String>(CNameObj).ToLocalChecked());
    strncpy(field.CName, *CNameData, 65);

    v8::Local<v8::Object> ENameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ENameData(Nan::To<v8::String>(ENameObj).ToLocalChecked());
    strncpy(field.EName, *ENameData, 65);

    v8::Local<v8::Object> DescriptionObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Description").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value DescriptionData(Nan::To<v8::String>(DescriptionObj).ToLocalChecked());
    strncpy(field.Description, *DescriptionData, 65);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetPortTypeTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetPortTypeTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetPartAccessSpotTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetPartAccessSpotTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetPartAccessSpotField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> CNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CNameData(Nan::To<v8::String>(CNameObj).ToLocalChecked());
    strncpy(field.CName, *CNameData, 65);

    v8::Local<v8::Object> ENameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ENameData(Nan::To<v8::String>(ENameObj).ToLocalChecked());
    strncpy(field.EName, *ENameData, 65);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetPartAccessSpotTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetPartAccessSpotTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetInterfaceTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetInterfaceTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetInterfaceField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 129);

    v8::Local<v8::Object> MonitorType_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonitorType_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> MonitorType_IDData = Nan::To<v8::Integer>(MonitorType_IDObj).ToLocalChecked();
    field.MonitorType_ID = MonitorType_IDData->Value();

    v8::Local<v8::Object> IfTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IfType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IfTypeData = Nan::To<v8::Integer>(IfTypeObj).ToLocalChecked();
    field.IfType = IfTypeData->Value();

    v8::Local<v8::Object> ENameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ENameData(Nan::To<v8::String>(ENameObj).ToLocalChecked());
    strncpy(field.EName, *ENameData, 65);

    v8::Local<v8::Object> IpAddressObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IpAddress").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IpAddressData(Nan::To<v8::String>(IpAddressObj).ToLocalChecked());
    strncpy(field.IpAddress, *IpAddressData, 16);

    v8::Local<v8::Object> IpMaskObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IpMask").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IpMaskData(Nan::To<v8::String>(IpMaskObj).ToLocalChecked());
    strncpy(field.IpMask, *IpMaskData, 16);

    v8::Local<v8::Object> IfStatusObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IfStatus").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IfStatusData = Nan::To<v8::Integer>(IfStatusObj).ToLocalChecked();
    field.IfStatus = IfStatusData->Value();

    v8::Local<v8::Object> MACObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MAC").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MACData(Nan::To<v8::String>(MACObj).ToLocalChecked());
    strncpy(field.MAC, *MACData, 65);

    v8::Local<v8::Object> DeviceIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DeviceID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> DeviceIDData = Nan::To<v8::Integer>(DeviceIDObj).ToLocalChecked();
    field.DeviceID = DeviceIDData->Value();

    v8::Local<v8::Object> DeviceObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DeviceObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value DeviceObjectIDData(Nan::To<v8::String>(DeviceObjectIDObj).ToLocalChecked());
    strncpy(field.DeviceObjectID, *DeviceObjectIDData, 129);

    v8::Local<v8::Object> DeviceIndexObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DeviceIndex").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value DeviceIndexData(Nan::To<v8::String>(DeviceIndexObj).ToLocalChecked());
    strncpy(field.DeviceIndex, *DeviceIndexData, 17);

    v8::Local<v8::Object> isPollingObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("isPolling").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> isPollingData = Nan::To<v8::Integer>(isPollingObj).ToLocalChecked();
    field.isPolling = isPollingData->Value();

    v8::Local<v8::Object> DescriptionObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Description").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value DescriptionData(Nan::To<v8::String>(DescriptionObj).ToLocalChecked());
    strncpy(field.Description, *DescriptionData, 65);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetInterfaceTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetInterfaceTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetGeneralOIDTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetGeneralOIDTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetGeneralOIDField field;

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetGeneralOIDTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetGeneralOIDTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetMonitorTypeTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorTypeTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetMonitorTypeField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> CNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CNameData(Nan::To<v8::String>(CNameObj).ToLocalChecked());
    strncpy(field.CName, *CNameData, 65);

    v8::Local<v8::Object> ENameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ENameData(Nan::To<v8::String>(ENameObj).ToLocalChecked());
    strncpy(field.EName, *ENameData, 65);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetMonitorTypeTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorTypeTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetMonitorAttrScopeTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorAttrScopeTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetMonitorAttrScopeField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> CNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CNameData(Nan::To<v8::String>(CNameObj).ToLocalChecked());
    strncpy(field.CName, *CNameData, 257);

    v8::Local<v8::Object> ENameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ENameData(Nan::To<v8::String>(ENameObj).ToLocalChecked());
    strncpy(field.EName, *ENameData, 257);

    v8::Local<v8::Object> CommentsObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Comments").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CommentsData(Nan::To<v8::String>(CommentsObj).ToLocalChecked());
    strncpy(field.Comments, *CommentsData, 257);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetMonitorAttrScopeTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorAttrScopeTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetMonitorAttrTypeTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorAttrTypeTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetMonitorAttrTypeField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> MANUFACTORY_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MANUFACTORY_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> MANUFACTORY_IDData = Nan::To<v8::Integer>(MANUFACTORY_IDObj).ToLocalChecked();
    field.MANUFACTORY_ID = MANUFACTORY_IDData->Value();

    v8::Local<v8::Object> MonitorType_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonitorType_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> MonitorType_IDData = Nan::To<v8::Integer>(MonitorType_IDObj).ToLocalChecked();
    field.MonitorType_ID = MonitorType_IDData->Value();

    v8::Local<v8::Object> AttrType_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("AttrType_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> AttrType_IDData = Nan::To<v8::Integer>(AttrType_IDObj).ToLocalChecked();
    field.AttrType_ID = AttrType_IDData->Value();

    v8::Local<v8::Object> MANUFACTORYObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MANUFACTORY").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MANUFACTORYData(Nan::To<v8::String>(MANUFACTORYObj).ToLocalChecked());
    strncpy(field.MANUFACTORY, *MANUFACTORYData, 65);

    v8::Local<v8::Object> MonitorTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonitorType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonitorTypeData(Nan::To<v8::String>(MonitorTypeObj).ToLocalChecked());
    strncpy(field.MonitorType, *MonitorTypeData, 65);

    v8::Local<v8::Object> AttrTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value AttrTypeData(Nan::To<v8::String>(AttrTypeObj).ToLocalChecked());
    strncpy(field.AttrType, *AttrTypeData, 257);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetMonitorAttrTypeTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorAttrTypeTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetMonitorObjectAttrTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorObjectAttrTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetMonitorObjectAttrField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 129);

    v8::Local<v8::Object> AttrTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value AttrTypeData(Nan::To<v8::String>(AttrTypeObj).ToLocalChecked());
    strncpy(field.AttrType, *AttrTypeData, 257);

    v8::Local<v8::Object> PolicyTypeIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("PolicyTypeID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> PolicyTypeIDData = Nan::To<v8::Integer>(PolicyTypeIDObj).ToLocalChecked();
    field.PolicyTypeID = PolicyTypeIDData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetMonitorObjectAttrTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorObjectAttrTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetMonitorTaskResultTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorTaskResultTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetMonitorTaskResultField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 129);

    v8::Local<v8::Object> Task_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Task_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> Task_IDData = Nan::To<v8::Integer>(Task_IDObj).ToLocalChecked();
    field.Task_ID = Task_IDData->Value();

    v8::Local<v8::Object> OperateTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperateTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperateTimeData = Nan::To<v8::Integer>(OperateTimeObj).ToLocalChecked();
    field.OperateTime = OperateTimeData->Value();

    v8::Local<v8::Object> MonDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonDateData(Nan::To<v8::String>(MonDateObj).ToLocalChecked());
    strncpy(field.MonDate, *MonDateData, 9);

    v8::Local<v8::Object> MonTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonTimeData(Nan::To<v8::String>(MonTimeObj).ToLocalChecked());
    strncpy(field.MonTime, *MonTimeData, 9);

    v8::Local<v8::Object> InstructChainObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("InstructChain").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value InstructChainData(Nan::To<v8::String>(InstructChainObj).ToLocalChecked());
    strncpy(field.InstructChain, *InstructChainData, 257);

    v8::Local<v8::Object> ResultChainObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ResultChain").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ResultChainData(Nan::To<v8::String>(ResultChainObj).ToLocalChecked());
    strncpy(field.ResultChain, *ResultChainData, 1025);

    v8::Local<v8::Object> FlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Flag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> FlagData = Nan::To<v8::Integer>(FlagObj).ToLocalChecked();
    field.Flag = FlagData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetMonitorTaskResultTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorTaskResultTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetMonitorDeviceGroupTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorDeviceGroupTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetMonitorDeviceGroupField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> CNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CNameData(Nan::To<v8::String>(CNameObj).ToLocalChecked());
    strncpy(field.CName, *CNameData, 65);

    v8::Local<v8::Object> ENameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ENameData(Nan::To<v8::String>(ENameObj).ToLocalChecked());
    strncpy(field.EName, *ENameData, 65);

    v8::Local<v8::Object> ConditionObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Condition").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ConditionData(Nan::To<v8::String>(ConditionObj).ToLocalChecked());
    strncpy(field.Condition, *ConditionData, 513);

    v8::Local<v8::Object> CommentsObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Comments").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CommentsData(Nan::To<v8::String>(CommentsObj).ToLocalChecked());
    strncpy(field.Comments, *CommentsData, 257);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetMonitorDeviceGroupTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorDeviceGroupTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetMonitorTaskObjectSetTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorTaskObjectSetTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetMonitorTaskObjectSetField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> DeviceGroup_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DeviceGroup_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> DeviceGroup_IDData = Nan::To<v8::Integer>(DeviceGroup_IDObj).ToLocalChecked();
    field.DeviceGroup_ID = DeviceGroup_IDData->Value();

    v8::Local<v8::Object> Device_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Device_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> Device_IDData = Nan::To<v8::Integer>(Device_IDObj).ToLocalChecked();
    field.Device_ID = Device_IDData->Value();

    v8::Local<v8::Object> DataCenterObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DataCenter").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> DataCenterData = Nan::To<v8::Integer>(DataCenterObj).ToLocalChecked();
    field.DataCenter = DataCenterData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetMonitorTaskObjectSetTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorTaskObjectSetTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetMonitorTaskInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorTaskInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetMonitorTaskInfoField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> CNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("CName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CNameData(Nan::To<v8::String>(CNameObj).ToLocalChecked());
    strncpy(field.CName, *CNameData, 65);

    v8::Local<v8::Object> ENameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ENameData(Nan::To<v8::String>(ENameObj).ToLocalChecked());
    strncpy(field.EName, *ENameData, 65);

    v8::Local<v8::Object> DeviceGroup_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DeviceGroup_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> DeviceGroup_IDData = Nan::To<v8::Integer>(DeviceGroup_IDObj).ToLocalChecked();
    field.DeviceGroup_ID = DeviceGroup_IDData->Value();

    v8::Local<v8::Object> ManagerGroup_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ManagerGroup_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> ManagerGroup_IDData = Nan::To<v8::Integer>(ManagerGroup_IDObj).ToLocalChecked();
    field.ManagerGroup_ID = ManagerGroup_IDData->Value();

    v8::Local<v8::Object> TimePolicy_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TimePolicy_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> TimePolicy_IDData = Nan::To<v8::Integer>(TimePolicy_IDObj).ToLocalChecked();
    field.TimePolicy_ID = TimePolicy_IDData->Value();

    v8::Local<v8::Object> TaskPriority_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TaskPriority_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> TaskPriority_IDData = Nan::To<v8::Integer>(TaskPriority_IDObj).ToLocalChecked();
    field.TaskPriority_ID = TaskPriority_IDData->Value();

    v8::Local<v8::Object> OutputPolicy_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OutputPolicy_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OutputPolicy_IDData = Nan::To<v8::Integer>(OutputPolicy_IDObj).ToLocalChecked();
    field.OutputPolicy_ID = OutputPolicy_IDData->Value();

    v8::Local<v8::Object> ActionGroup_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ActionGroup_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> ActionGroup_IDData = Nan::To<v8::Integer>(ActionGroup_IDObj).ToLocalChecked();
    field.ActionGroup_ID = ActionGroup_IDData->Value();

    v8::Local<v8::Object> EventExprStrObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventExprStr").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EventExprStrData(Nan::To<v8::String>(EventExprStrObj).ToLocalChecked());
    strncpy(field.EventExprStr, *EventExprStrData, 1025);

    v8::Local<v8::Object> DeviceGroupObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DeviceGroup").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value DeviceGroupData(Nan::To<v8::String>(DeviceGroupObj).ToLocalChecked());
    strncpy(field.DeviceGroup, *DeviceGroupData, 65);

    v8::Local<v8::Object> ManagerGroupObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ManagerGroup").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ManagerGroupData(Nan::To<v8::String>(ManagerGroupObj).ToLocalChecked());
    strncpy(field.ManagerGroup, *ManagerGroupData, 65);

    v8::Local<v8::Object> TimePolicyObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TimePolicy").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value TimePolicyData(Nan::To<v8::String>(TimePolicyObj).ToLocalChecked());
    strncpy(field.TimePolicy, *TimePolicyData, 65);

    v8::Local<v8::Object> TaskPriorityObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TaskPriority").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value TaskPriorityData(Nan::To<v8::String>(TaskPriorityObj).ToLocalChecked());
    strncpy(field.TaskPriority, *TaskPriorityData, 65);

    v8::Local<v8::Object> OutputPolicyObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OutputPolicy").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value OutputPolicyData(Nan::To<v8::String>(OutputPolicyObj).ToLocalChecked());
    strncpy(field.OutputPolicy, *OutputPolicyData, 65);

    v8::Local<v8::Object> ActionGroupObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ActionGroup").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ActionGroupData(Nan::To<v8::String>(ActionGroupObj).ToLocalChecked());
    strncpy(field.ActionGroup, *ActionGroupData, 65);

    v8::Local<v8::Object> ValidFlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ValidFlag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> ValidFlagData = Nan::To<v8::Integer>(ValidFlagObj).ToLocalChecked();
    field.ValidFlag = ValidFlagData->Value();

    v8::Local<v8::Object> TaskStatusObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TaskStatus").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> TaskStatusData = Nan::To<v8::Integer>(TaskStatusObj).ToLocalChecked();
    field.TaskStatus = TaskStatusData->Value();

    v8::Local<v8::Object> CommentsObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Comments").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CommentsData(Nan::To<v8::String>(CommentsObj).ToLocalChecked());
    strncpy(field.Comments, *CommentsData, 257);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetMonitorTaskInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorTaskInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetPartyLinkInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetPartyLinkInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetPartyLinkInfoField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> MEMBER_NOObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MEMBER_NO").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MEMBER_NOData(Nan::To<v8::String>(MEMBER_NOObj).ToLocalChecked());
    strncpy(field.MEMBER_NO, *MEMBER_NOData, 33);

    v8::Local<v8::Object> MEMBER_NAMEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MEMBER_NAME").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MEMBER_NAMEData(Nan::To<v8::String>(MEMBER_NAMEObj).ToLocalChecked());
    strncpy(field.MEMBER_NAME, *MEMBER_NAMEData, 65);

    v8::Local<v8::Object> REMOTE_ADDRObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("REMOTE_ADDR").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value REMOTE_ADDRData(Nan::To<v8::String>(REMOTE_ADDRObj).ToLocalChecked());
    strncpy(field.REMOTE_ADDR, *REMOTE_ADDRData, 65);

    v8::Local<v8::Object> LOCAL_ADDRObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("LOCAL_ADDR").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value LOCAL_ADDRData(Nan::To<v8::String>(LOCAL_ADDRObj).ToLocalChecked());
    strncpy(field.LOCAL_ADDR, *LOCAL_ADDRData, 65);

    v8::Local<v8::Object> ADDRESSObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ADDRESS").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ADDRESSData(Nan::To<v8::String>(ADDRESSObj).ToLocalChecked());
    strncpy(field.ADDRESS, *ADDRESSData, 257);

    v8::Local<v8::Object> LINE_STATUSObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("LINE_STATUS").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value LINE_STATUSData(Nan::To<v8::String>(LINE_STATUSObj).ToLocalChecked());
    strncpy(field.LINE_STATUS, *LINE_STATUSData, 33);

    v8::Local<v8::Object> CONTACTObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("CONTACT").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CONTACTData(Nan::To<v8::String>(CONTACTObj).ToLocalChecked());
    strncpy(field.CONTACT, *CONTACTData, 33);

    v8::Local<v8::Object> TELEPHONEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TELEPHONE").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value TELEPHONEData(Nan::To<v8::String>(TELEPHONEObj).ToLocalChecked());
    strncpy(field.TELEPHONE, *TELEPHONEData, 65);

    v8::Local<v8::Object> MOBILEPHONEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MOBILEPHONE").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MOBILEPHONEData(Nan::To<v8::String>(MOBILEPHONEObj).ToLocalChecked());
    strncpy(field.MOBILEPHONE, *MOBILEPHONEData, 65);

    v8::Local<v8::Object> EMAILObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EMAIL").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EMAILData(Nan::To<v8::String>(EMAILObj).ToLocalChecked());
    strncpy(field.EMAIL, *EMAILData, 65);

    v8::Local<v8::Object> FAXObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("FAX").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value FAXData(Nan::To<v8::String>(FAXObj).ToLocalChecked());
    strncpy(field.FAX, *FAXData, 65);

    v8::Local<v8::Object> PROVINCEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("PROVINCE").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value PROVINCEData(Nan::To<v8::String>(PROVINCEObj).ToLocalChecked());
    strncpy(field.PROVINCE, *PROVINCEData, 33);

    v8::Local<v8::Object> DDN_NOObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DDN_NO").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value DDN_NOData(Nan::To<v8::String>(DDN_NOObj).ToLocalChecked());
    strncpy(field.DDN_NO, *DDN_NOData, 65);

    v8::Local<v8::Object> IN_MODEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IN_MODE").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IN_MODEData(Nan::To<v8::String>(IN_MODEObj).ToLocalChecked());
    strncpy(field.IN_MODE, *IN_MODEData, 65);

    v8::Local<v8::Object> IP_WANObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IP_WAN").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IP_WANData(Nan::To<v8::String>(IP_WANObj).ToLocalChecked());
    strncpy(field.IP_WAN, *IP_WANData, 65);

    v8::Local<v8::Object> IP_LANObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IP_LAN").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IP_LANData(Nan::To<v8::String>(IP_LANObj).ToLocalChecked());
    strncpy(field.IP_LAN, *IP_LANData, 65);

    v8::Local<v8::Object> IPADDRObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IPADDR").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IPADDRData(Nan::To<v8::String>(IPADDRObj).ToLocalChecked());
    strncpy(field.IPADDR, *IPADDRData, 65);

    v8::Local<v8::Object> InterfaceObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Interface").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value InterfaceData(Nan::To<v8::String>(InterfaceObj).ToLocalChecked());
    strncpy(field.Interface, *InterfaceData, 65);

    v8::Local<v8::Object> INTERFACE_DATEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("INTERFACE_DATE").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value INTERFACE_DATEData(Nan::To<v8::String>(INTERFACE_DATEObj).ToLocalChecked());
    strncpy(field.INTERFACE_DATE, *INTERFACE_DATEData, 33);

    v8::Local<v8::Object> SOFTWAREObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SOFTWARE").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value SOFTWAREData(Nan::To<v8::String>(SOFTWAREObj).ToLocalChecked());
    strncpy(field.SOFTWARE, *SOFTWAREData, 33);

    v8::Local<v8::Object> FEE_TYPEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("FEE_TYPE").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value FEE_TYPEData(Nan::To<v8::String>(FEE_TYPEObj).ToLocalChecked());
    strncpy(field.FEE_TYPE, *FEE_TYPEData, 33);

    v8::Local<v8::Object> SERVICEPROVIDERObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SERVICEPROVIDER").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value SERVICEPROVIDERData(Nan::To<v8::String>(SERVICEPROVIDERObj).ToLocalChecked());
    strncpy(field.SERVICEPROVIDER, *SERVICEPROVIDERData, 33);

    v8::Local<v8::Object> IF_ZIYINGObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IF_ZIYING").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IF_ZIYINGData(Nan::To<v8::String>(IF_ZIYINGObj).ToLocalChecked());
    strncpy(field.IF_ZIYING, *IF_ZIYINGData, 33);

    v8::Local<v8::Object> IF_TUOGUANObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IF_TUOGUAN").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IF_TUOGUANData(Nan::To<v8::String>(IF_TUOGUANObj).ToLocalChecked());
    strncpy(field.IF_TUOGUAN, *IF_TUOGUANData, 33);

    v8::Local<v8::Object> HASOTHERObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("HASOTHER").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value HASOTHERData(Nan::To<v8::String>(HASOTHERObj).ToLocalChecked());
    strncpy(field.HASOTHER, *HASOTHERData, 33);

    v8::Local<v8::Object> SEAT_NOObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SEAT_NO").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value SEAT_NOData(Nan::To<v8::String>(SEAT_NOObj).ToLocalChecked());
    strncpy(field.SEAT_NO, *SEAT_NOData, 1025);

    v8::Local<v8::Object> PROObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("PRO").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value PROData(Nan::To<v8::String>(PROObj).ToLocalChecked());
    strncpy(field.PRO, *PROData, 513);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetPartyLinkInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetPartyLinkInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetMonitorActionAttrTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorActionAttrTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetMonitorActionAttrField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> ActionGroup_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ActionGroup_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> ActionGroup_IDData = Nan::To<v8::Integer>(ActionGroup_IDObj).ToLocalChecked();
    field.ActionGroup_ID = ActionGroup_IDData->Value();

    v8::Local<v8::Object> MonitorAttr_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonitorAttr_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> MonitorAttr_IDData = Nan::To<v8::Integer>(MonitorAttr_IDObj).ToLocalChecked();
    field.MonitorAttr_ID = MonitorAttr_IDData->Value();

    v8::Local<v8::Object> MonitorAttrNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonitorAttrName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonitorAttrNameData(Nan::To<v8::String>(MonitorAttrNameObj).ToLocalChecked());
    strncpy(field.MonitorAttrName, *MonitorAttrNameData, 257);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetMonitorActionAttrTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorActionAttrTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetModuleTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetModuleTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetModuleField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 129);

    v8::Local<v8::Object> MonitorType_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonitorType_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> MonitorType_IDData = Nan::To<v8::Integer>(MonitorType_IDObj).ToLocalChecked();
    field.MonitorType_ID = MonitorType_IDData->Value();

    v8::Local<v8::Object> DeviceIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DeviceID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> DeviceIDData = Nan::To<v8::Integer>(DeviceIDObj).ToLocalChecked();
    field.DeviceID = DeviceIDData->Value();

    v8::Local<v8::Object> DeviceObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DeviceObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value DeviceObjectIDData(Nan::To<v8::String>(DeviceObjectIDObj).ToLocalChecked());
    strncpy(field.DeviceObjectID, *DeviceObjectIDData, 129);

    v8::Local<v8::Object> NameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Name").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value NameData(Nan::To<v8::String>(NameObj).ToLocalChecked());
    strncpy(field.Name, *NameData, 65);

    v8::Local<v8::Object> DescriptionObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Description").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value DescriptionData(Nan::To<v8::String>(DescriptionObj).ToLocalChecked());
    strncpy(field.Description, *DescriptionData, 129);

    v8::Local<v8::Object> ModuleIndexObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ModuleIndex").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> ModuleIndexData = Nan::To<v8::Integer>(ModuleIndexObj).ToLocalChecked();
    field.ModuleIndex = ModuleIndexData->Value();

    v8::Local<v8::Object> EntPhyIndexObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EntPhyIndex").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> EntPhyIndexData = Nan::To<v8::Integer>(EntPhyIndexObj).ToLocalChecked();
    field.EntPhyIndex = EntPhyIndexData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetModuleTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetModuleTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetMonitorTaskStatusResultTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorTaskStatusResultTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetMonitorTaskStatusResultField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 129);

    v8::Local<v8::Object> Task_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Task_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> Task_IDData = Nan::To<v8::Integer>(Task_IDObj).ToLocalChecked();
    field.Task_ID = Task_IDData->Value();

    v8::Local<v8::Object> OperateTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperateTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperateTimeData = Nan::To<v8::Integer>(OperateTimeObj).ToLocalChecked();
    field.OperateTime = OperateTimeData->Value();

    v8::Local<v8::Object> MonDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonDateData(Nan::To<v8::String>(MonDateObj).ToLocalChecked());
    strncpy(field.MonDate, *MonDateData, 9);

    v8::Local<v8::Object> MonTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonTimeData(Nan::To<v8::String>(MonTimeObj).ToLocalChecked());
    strncpy(field.MonTime, *MonTimeData, 9);

    v8::Local<v8::Object> FlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Flag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> FlagData = Nan::To<v8::Integer>(FlagObj).ToLocalChecked();
    field.Flag = FlagData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetMonitorTaskStatusResultTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorTaskStatusResultTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetCfgFileTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetCfgFileTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetCfgFileField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 129);

    v8::Local<v8::Object> MonDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonDateData(Nan::To<v8::String>(MonDateObj).ToLocalChecked());
    strncpy(field.MonDate, *MonDateData, 9);

    v8::Local<v8::Object> MonTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonTimeData(Nan::To<v8::String>(MonTimeObj).ToLocalChecked());
    strncpy(field.MonTime, *MonTimeData, 9);

    v8::Local<v8::Object> CfgFileNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("CfgFileName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CfgFileNameData(Nan::To<v8::String>(CfgFileNameObj).ToLocalChecked());
    strncpy(field.CfgFileName, *CfgFileNameData, 257);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetCfgFileTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetCfgFileTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryFileGeneralOperTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryFileGeneralOperTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryFileGeneralOperField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> FileNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("FileName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value FileNameData(Nan::To<v8::String>(FileNameObj).ToLocalChecked());
    strncpy(field.FileName, *FileNameData, 257);

    v8::Local<v8::Object> VersionObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Version").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value VersionData(Nan::To<v8::String>(VersionObj).ToLocalChecked());
    strncpy(field.Version, *VersionData, 17);

    v8::Local<v8::Object> SubVersionObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SubVersion").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> SubVersionData = Nan::To<v8::Integer>(SubVersionObj).ToLocalChecked();
    field.SubVersion = SubVersionData->Value();

    v8::Local<v8::Object> MonDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonDateData(Nan::To<v8::String>(MonDateObj).ToLocalChecked());
    strncpy(field.MonDate, *MonDateData, 9);

    v8::Local<v8::Object> MonTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonTimeData(Nan::To<v8::String>(MonTimeObj).ToLocalChecked());
    strncpy(field.MonTime, *MonTimeData, 9);

    v8::Local<v8::Object> UserNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("UserName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value UserNameData(Nan::To<v8::String>(UserNameObj).ToLocalChecked());
    strncpy(field.UserName, *UserNameData, 21);

    v8::Local<v8::Object> OperTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperTypeData = Nan::To<v8::Integer>(OperTypeObj).ToLocalChecked();
    field.OperType = OperTypeData->Value();

    v8::Local<v8::Object> OperResultObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperResult").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperResultData = Nan::To<v8::Integer>(OperResultObj).ToLocalChecked();
    field.OperResult = OperResultData->Value();

    v8::Local<v8::Object> CommentsObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Comments").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CommentsData(Nan::To<v8::String>(CommentsObj).ToLocalChecked());
    strncpy(field.Comments, *CommentsData, 257);

    v8::Local<v8::Object> OffsetObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Offset").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OffsetData = Nan::To<v8::Integer>(OffsetObj).ToLocalChecked();
    field.Offset = OffsetData->Value();

    v8::Local<v8::Object> LengthObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Length").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> LengthData = Nan::To<v8::Integer>(LengthObj).ToLocalChecked();
    field.Length = LengthData->Value();

    v8::Local<v8::Object> FileContentObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("FileContent").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value FileContentData(Nan::To<v8::String>(FileContentObj).ToLocalChecked());
    strncpy(field.FileContent, *FileContentData, 3001);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryFileGeneralOperTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryFileGeneralOperTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetPartyLinkStatusInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetPartyLinkStatusInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetPartyLinkStatusInfoField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> KeyCompareObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeyCompare").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> KeyCompareData = Nan::To<v8::Integer>(KeyCompareObj).ToLocalChecked();
    field.KeyCompare = KeyCompareData->Value();

    v8::Local<v8::Object> KeyNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeyName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value KeyNameData(Nan::To<v8::String>(KeyNameObj).ToLocalChecked());
    strncpy(field.KeyName, *KeyNameData, 257);

    v8::Local<v8::Object> KeyValueObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeyValue").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value KeyValueData(Nan::To<v8::String>(KeyValueObj).ToLocalChecked());
    strncpy(field.KeyValue, *KeyValueData, 257);

    v8::Local<v8::Object> MonDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonDateData(Nan::To<v8::String>(MonDateObj).ToLocalChecked());
    strncpy(field.MonDate, *MonDateData, 9);

    v8::Local<v8::Object> MonTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonTimeData(Nan::To<v8::String>(MonTimeObj).ToLocalChecked());
    strncpy(field.MonTime, *MonTimeData, 9);

    v8::Local<v8::Object> SEAT_NOObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SEAT_NO").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value SEAT_NOData(Nan::To<v8::String>(SEAT_NOObj).ToLocalChecked());
    strncpy(field.SEAT_NO, *SEAT_NOData, 33);

    v8::Local<v8::Object> IPADDRObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IPADDR").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IPADDRData(Nan::To<v8::String>(IPADDRObj).ToLocalChecked());
    strncpy(field.IPADDR, *IPADDRData, 65);

    v8::Local<v8::Object> InterfaceObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Interface").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value InterfaceData(Nan::To<v8::String>(InterfaceObj).ToLocalChecked());
    strncpy(field.Interface, *InterfaceData, 65);

    v8::Local<v8::Object> statusObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("status").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value statusData(Nan::To<v8::String>(statusObj).ToLocalChecked());
    strncpy(field.status, *statusData, 65);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetPartyLinkStatusInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetPartyLinkStatusInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetBaseLineTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetBaseLineTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetBaseLineField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> MANUFACTORY_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MANUFACTORY_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> MANUFACTORY_IDData = Nan::To<v8::Integer>(MANUFACTORY_IDObj).ToLocalChecked();
    field.MANUFACTORY_ID = MANUFACTORY_IDData->Value();

    v8::Local<v8::Object> NameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Name").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value NameData(Nan::To<v8::String>(NameObj).ToLocalChecked());
    strncpy(field.Name, *NameData, 129);

    v8::Local<v8::Object> SerialUsedObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SerialUsed").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value SerialUsedData(Nan::To<v8::String>(SerialUsedObj).ToLocalChecked());
    strncpy(field.SerialUsed, *SerialUsedData, 129);

    v8::Local<v8::Object> dataObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("data").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value dataData(Nan::To<v8::String>(dataObj).ToLocalChecked());
    strncpy(field.data, *dataData, 2001);

    v8::Local<v8::Object> memoObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("memo").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value memoData(Nan::To<v8::String>(memoObj).ToLocalChecked());
    strncpy(field.memo, *memoData, 257);

    v8::Local<v8::Object> FlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Flag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> FlagData = Nan::To<v8::Integer>(FlagObj).ToLocalChecked();
    field.Flag = FlagData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetBaseLineTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetBaseLineTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetBaseLineResultTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetBaseLineResultTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetBaseLineResultField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> BaseLineNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("BaseLineName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value BaseLineNameData(Nan::To<v8::String>(BaseLineNameObj).ToLocalChecked());
    strncpy(field.BaseLineName, *BaseLineNameData, 129);

    v8::Local<v8::Object> DeviceObjIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DeviceObjID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value DeviceObjIDData(Nan::To<v8::String>(DeviceObjIDObj).ToLocalChecked());
    strncpy(field.DeviceObjID, *DeviceObjIDData, 129);

    v8::Local<v8::Object> DeviceIPObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DeviceIP").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value DeviceIPData(Nan::To<v8::String>(DeviceIPObj).ToLocalChecked());
    strncpy(field.DeviceIP, *DeviceIPData, 16);

    v8::Local<v8::Object> ResultObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Result").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ResultData(Nan::To<v8::String>(ResultObj).ToLocalChecked());
    strncpy(field.Result, *ResultData, 3001);

    v8::Local<v8::Object> GenDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("GenDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value GenDateData(Nan::To<v8::String>(GenDateObj).ToLocalChecked());
    strncpy(field.GenDate, *GenDateData, 9);

    v8::Local<v8::Object> GenTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("GenTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value GenTimeData(Nan::To<v8::String>(GenTimeObj).ToLocalChecked());
    strncpy(field.GenTime, *GenTimeData, 9);

    v8::Local<v8::Object> GenUserObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("GenUser").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value GenUserData(Nan::To<v8::String>(GenUserObj).ToLocalChecked());
    strncpy(field.GenUser, *GenUserData, 21);

    v8::Local<v8::Object> FlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Flag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> FlagData = Nan::To<v8::Integer>(FlagObj).ToLocalChecked();
    field.Flag = FlagData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetBaseLineResultTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetBaseLineResultTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetMonitorDeviceTaskTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorDeviceTaskTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetMonitorDeviceTaskField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 129);

    v8::Local<v8::Object> IPAddressObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IPAddress").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IPAddressData(Nan::To<v8::String>(IPAddressObj).ToLocalChecked());
    strncpy(field.IPAddress, *IPAddressData, 16);

    v8::Local<v8::Object> Manufactory_IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Manufactory_ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> Manufactory_IDData = Nan::To<v8::Integer>(Manufactory_IDObj).ToLocalChecked();
    field.Manufactory_ID = Manufactory_IDData->Value();

    v8::Local<v8::Object> InstructChainObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("InstructChain").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value InstructChainData(Nan::To<v8::String>(InstructChainObj).ToLocalChecked());
    strncpy(field.InstructChain, *InstructChainData, 257);

    v8::Local<v8::Object> InstructAliasObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("InstructAlias").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value InstructAliasData(Nan::To<v8::String>(InstructAliasObj).ToLocalChecked());
    strncpy(field.InstructAlias, *InstructAliasData, 129);

    v8::Local<v8::Object> InstructArgsObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("InstructArgs").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value InstructArgsData(Nan::To<v8::String>(InstructArgsObj).ToLocalChecked());
    strncpy(field.InstructArgs, *InstructArgsData, 257);

    v8::Local<v8::Object> DefParamChainObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DefParamChain").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value DefParamChainData(Nan::To<v8::String>(DefParamChainObj).ToLocalChecked());
    strncpy(field.DefParamChain, *DefParamChainData, 2001);

    v8::Local<v8::Object> FlagObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Flag").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> FlagData = Nan::To<v8::Integer>(FlagObj).ToLocalChecked();
    field.Flag = FlagData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetMonitorDeviceTaskTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetMonitorDeviceTaskTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetLocalPingResultInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetLocalPingResultInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetLocalPingResultInfoField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> SouIPADDRObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SouIPADDR").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value SouIPADDRData(Nan::To<v8::String>(SouIPADDRObj).ToLocalChecked());
    strncpy(field.SouIPADDR, *SouIPADDRData, 16);

    v8::Local<v8::Object> SouNAMEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SouNAME").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value SouNAMEData(Nan::To<v8::String>(SouNAMEObj).ToLocalChecked());
    strncpy(field.SouNAME, *SouNAMEData, 129);

    v8::Local<v8::Object> TarIPADDRObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TarIPADDR").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value TarIPADDRData(Nan::To<v8::String>(TarIPADDRObj).ToLocalChecked());
    strncpy(field.TarIPADDR, *TarIPADDRData, 16);

    v8::Local<v8::Object> TarNAMEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TarNAME").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value TarNAMEData(Nan::To<v8::String>(TarNAMEObj).ToLocalChecked());
    strncpy(field.TarNAME, *TarNAMEData, 129);

    v8::Local<v8::Object> PDateStaObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("PDateSta").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value PDateStaData(Nan::To<v8::String>(PDateStaObj).ToLocalChecked());
    strncpy(field.PDateSta, *PDateStaData, 9);

    v8::Local<v8::Object> PTimeStaObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("PTimeSta").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value PTimeStaData(Nan::To<v8::String>(PTimeStaObj).ToLocalChecked());
    strncpy(field.PTimeSta, *PTimeStaData, 9);

    v8::Local<v8::Object> ConnRateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ConnRate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> ConnRateData = Nan::To<v8::Integer>(ConnRateObj).ToLocalChecked();
    field.ConnRate = ConnRateData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetLocalPingResultInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetLocalPingResultInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetRomotePingResultInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetRomotePingResultInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetRomotePingResultInfoField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> SouIPADDRObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SouIPADDR").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value SouIPADDRData(Nan::To<v8::String>(SouIPADDRObj).ToLocalChecked());
    strncpy(field.SouIPADDR, *SouIPADDRData, 16);

    v8::Local<v8::Object> SouNAMEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SouNAME").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value SouNAMEData(Nan::To<v8::String>(SouNAMEObj).ToLocalChecked());
    strncpy(field.SouNAME, *SouNAMEData, 129);

    v8::Local<v8::Object> TarIPADDRObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TarIPADDR").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value TarIPADDRData(Nan::To<v8::String>(TarIPADDRObj).ToLocalChecked());
    strncpy(field.TarIPADDR, *TarIPADDRData, 16);

    v8::Local<v8::Object> TarNAMEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TarNAME").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value TarNAMEData(Nan::To<v8::String>(TarNAMEObj).ToLocalChecked());
    strncpy(field.TarNAME, *TarNAMEData, 129);

    v8::Local<v8::Object> PDateStaObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("PDateSta").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value PDateStaData(Nan::To<v8::String>(PDateStaObj).ToLocalChecked());
    strncpy(field.PDateSta, *PDateStaData, 9);

    v8::Local<v8::Object> PTimeStaObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("PTimeSta").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value PTimeStaData(Nan::To<v8::String>(PTimeStaObj).ToLocalChecked());
    strncpy(field.PTimeSta, *PTimeStaData, 9);

    v8::Local<v8::Object> ConnRateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ConnRate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> ConnRateData = Nan::To<v8::Integer>(ConnRateObj).ToLocalChecked();
    field.ConnRate = ConnRateData->Value();

    v8::Local<v8::Object> TimeDlyMinObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TimeDlyMin").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value TimeDlyMinData(Nan::To<v8::String>(TimeDlyMinObj).ToLocalChecked());
    strncpy(field.TimeDlyMin, *TimeDlyMinData, 129);

    v8::Local<v8::Object> TimeDlyMaxObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TimeDlyMax").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value TimeDlyMaxData(Nan::To<v8::String>(TimeDlyMaxObj).ToLocalChecked());
    strncpy(field.TimeDlyMax, *TimeDlyMaxData, 129);

    v8::Local<v8::Object> TimeDlyAvgObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TimeDlyAvg").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value TimeDlyAvgData(Nan::To<v8::String>(TimeDlyAvgObj).ToLocalChecked());
    strncpy(field.TimeDlyAvg, *TimeDlyAvgData, 129);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetRomotePingResultInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetRomotePingResultInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryTradeFrontOrderRttStatTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTradeFrontOrderRttStatTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryTradeFrontOrderRttStatField field;

    v8::Local<v8::Object> ObjectIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ObjectID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ObjectIDData(Nan::To<v8::String>(ObjectIDObj).ToLocalChecked());
    strncpy(field.ObjectID, *ObjectIDData, 65);

    v8::Local<v8::Object> MonDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonDateData(Nan::To<v8::String>(MonDateObj).ToLocalChecked());
    strncpy(field.MonDate, *MonDateData, 9);

    v8::Local<v8::Object> MonStartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonStartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonStartTimeData(Nan::To<v8::String>(MonStartTimeObj).ToLocalChecked());
    strncpy(field.MonStartTime, *MonStartTimeData, 9);

    v8::Local<v8::Object> MonEndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonEndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonEndTimeData(Nan::To<v8::String>(MonEndTimeObj).ToLocalChecked());
    strncpy(field.MonEndTime, *MonEndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryTradeFrontOrderRttStatTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTradeFrontOrderRttStatTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryDiskIOTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryDiskIOTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryDiskIOField field;

    v8::Local<v8::Object> HostNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value HostNameData(Nan::To<v8::String>(HostNameObj).ToLocalChecked());
    strncpy(field.HostName, *HostNameData, 65);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> KeepAliveObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> KeepAliveData = Nan::To<v8::Integer>(KeepAliveObj).ToLocalChecked();
    field.KeepAlive = KeepAliveData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryDiskIOTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryDiskIOTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryRouterInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryRouterInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryRouterInfoField field;

    v8::Local<v8::Object> HostNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value HostNameData(Nan::To<v8::String>(HostNameObj).ToLocalChecked());
    strncpy(field.HostName, *HostNameData, 65);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> KeepAliveObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> KeepAliveData = Nan::To<v8::Integer>(KeepAliveObj).ToLocalChecked();
    field.KeepAlive = KeepAliveData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryRouterInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryRouterInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryStatInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryStatInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryStatInfoField field;

    v8::Local<v8::Object> HostNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value HostNameData(Nan::To<v8::String>(HostNameObj).ToLocalChecked());
    strncpy(field.HostName, *HostNameData, 65);

    v8::Local<v8::Object> StartDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartDateData(Nan::To<v8::String>(StartDateObj).ToLocalChecked());
    strncpy(field.StartDate, *StartDateData, 9);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> EndDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndDateData(Nan::To<v8::String>(EndDateObj).ToLocalChecked());
    strncpy(field.EndDate, *EndDateData, 9);

    v8::Local<v8::Object> EndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EndTimeData(Nan::To<v8::String>(EndTimeObj).ToLocalChecked());
    strncpy(field.EndTime, *EndTimeData, 9);

    v8::Local<v8::Object> KeepAliveObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> KeepAliveData = Nan::To<v8::Integer>(KeepAliveObj).ToLocalChecked();
    field.KeepAlive = KeepAliveData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryStatInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryStatInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryClientInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryClientInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryClientInfoField field;

    v8::Local<v8::Object> ClientIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ClientID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ClientIDData(Nan::To<v8::String>(ClientIDObj).ToLocalChecked());
    strncpy(field.ClientID, *ClientIDData, 11);

    v8::Local<v8::Object> ClientNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ClientName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ClientNameData(Nan::To<v8::String>(ClientNameObj).ToLocalChecked());
    strncpy(field.ClientName, *ClientNameData, 81);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryClientInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryClientInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryParticTradeOrderStatesTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryParticTradeOrderStatesTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryParticTradeOrderStatesField field;

    v8::Local<v8::Object> ParticipantIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ParticipantID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ParticipantIDData(Nan::To<v8::String>(ParticipantIDObj).ToLocalChecked());
    strncpy(field.ParticipantID, *ParticipantIDData, 11);

    v8::Local<v8::Object> UserIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value UserIDData(Nan::To<v8::String>(UserIDObj).ToLocalChecked());
    strncpy(field.UserID, *UserIDData, 16);

    v8::Local<v8::Object> MonDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonDateData(Nan::To<v8::String>(MonDateObj).ToLocalChecked());
    strncpy(field.MonDate, *MonDateData, 9);

    v8::Local<v8::Object> MonStartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonStartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonStartTimeData(Nan::To<v8::String>(MonStartTimeObj).ToLocalChecked());
    strncpy(field.MonStartTime, *MonStartTimeData, 9);

    v8::Local<v8::Object> MonEndTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonEndTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonEndTimeData(Nan::To<v8::String>(MonEndTimeObj).ToLocalChecked());
    strncpy(field.MonEndTime, *MonEndTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryParticTradeOrderStatesTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryParticTradeOrderStatesTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryTradeOrderRttCutLineTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTradeOrderRttCutLineTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryTradeOrderRttCutLineField field;

    v8::Local<v8::Object> MonDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonDateData(Nan::To<v8::String>(MonDateObj).ToLocalChecked());
    strncpy(field.MonDate, *MonDateData, 9);

    v8::Local<v8::Object> MonTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonTimeData(Nan::To<v8::String>(MonTimeObj).ToLocalChecked());
    strncpy(field.MonTime, *MonTimeData, 9);

    v8::Local<v8::Object> UserNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("UserName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value UserNameData(Nan::To<v8::String>(UserNameObj).ToLocalChecked());
    strncpy(field.UserName, *UserNameData, 65);

    v8::Local<v8::Object> OrderRttCutLineObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OrderRttCutLine").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value OrderRttCutLineData(Nan::To<v8::String>(OrderRttCutLineObj).ToLocalChecked());
    strncpy(field.OrderRttCutLine, *OrderRttCutLineData, 129);

    v8::Local<v8::Object> OrderRttWidthObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OrderRttWidth").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OrderRttWidthData = Nan::To<v8::Integer>(OrderRttWidthObj).ToLocalChecked();
    field.OrderRttWidth = OrderRttWidthData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryTradeOrderRttCutLineTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryTradeOrderRttCutLineTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryEventDescriptionTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryEventDescriptionTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryEventDescriptionField field;

    v8::Local<v8::Object> EventDesIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventDesID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EventDesIDData(Nan::To<v8::String>(EventDesIDObj).ToLocalChecked());
    strncpy(field.EventDesID, *EventDesIDData, 13);

    v8::Local<v8::Object> UserNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("UserName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value UserNameData(Nan::To<v8::String>(UserNameObj).ToLocalChecked());
    strncpy(field.UserName, *UserNameData, 65);

    v8::Local<v8::Object> MonDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonDateData(Nan::To<v8::String>(MonDateObj).ToLocalChecked());
    strncpy(field.MonDate, *MonDateData, 9);

    v8::Local<v8::Object> MonTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonTimeData(Nan::To<v8::String>(MonTimeObj).ToLocalChecked());
    strncpy(field.MonTime, *MonTimeData, 9);

    v8::Local<v8::Object> EventDesObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EventDes").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EventDesData(Nan::To<v8::String>(EventDesObj).ToLocalChecked());
    strncpy(field.EventDes, *EventDesData, 401);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryEventDescriptionTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryEventDescriptionTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryFrontUniqueIDTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryFrontUniqueIDTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryFrontUniqueIDField field;

    v8::Local<v8::Object> FrontIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("FrontID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> FrontIDData = Nan::To<v8::Integer>(FrontIDObj).ToLocalChecked();
    field.FrontID = FrontIDData->Value();

    v8::Local<v8::Object> FrontNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("FrontName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value FrontNameData(Nan::To<v8::String>(FrontNameObj).ToLocalChecked());
    strncpy(field.FrontName, *FrontNameData, 51);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryFrontUniqueIDTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryFrontUniqueIDTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetPartyLinkAddrChangeTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetPartyLinkAddrChangeTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetPartyLinkAddrChangeField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> RelationIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("RelationID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> RelationIDData = Nan::To<v8::Integer>(RelationIDObj).ToLocalChecked();
    field.RelationID = RelationIDData->Value();

    v8::Local<v8::Object> OLDADDRESSObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OLDADDRESS").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value OLDADDRESSData(Nan::To<v8::String>(OLDADDRESSObj).ToLocalChecked());
    strncpy(field.OLDADDRESS, *OLDADDRESSData, 257);

    v8::Local<v8::Object> NEWADDRESSObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("NEWADDRESS").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value NEWADDRESSData(Nan::To<v8::String>(NEWADDRESSObj).ToLocalChecked());
    strncpy(field.NEWADDRESS, *NEWADDRESSData, 257);

    v8::Local<v8::Object> OPERATORObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OPERATOR").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value OPERATORData(Nan::To<v8::String>(OPERATORObj).ToLocalChecked());
    strncpy(field.OPERATOR, *OPERATORData, 33);

    v8::Local<v8::Object> MonDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonDateData(Nan::To<v8::String>(MonDateObj).ToLocalChecked());
    strncpy(field.MonDate, *MonDateData, 9);

    v8::Local<v8::Object> MonTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MonTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MonTimeData(Nan::To<v8::String>(MonTimeObj).ToLocalChecked());
    strncpy(field.MonTime, *MonTimeData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetPartyLinkAddrChangeTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetPartyLinkAddrChangeTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryNetDelPartyLinkInfoTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetDelPartyLinkInfoTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryNetDelPartyLinkInfoField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> IDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> IDData = Nan::To<v8::Integer>(IDObj).ToLocalChecked();
    field.ID = IDData->Value();

    v8::Local<v8::Object> MEMBER_NOObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MEMBER_NO").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MEMBER_NOData(Nan::To<v8::String>(MEMBER_NOObj).ToLocalChecked());
    strncpy(field.MEMBER_NO, *MEMBER_NOData, 33);

    v8::Local<v8::Object> MEMBER_NAMEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MEMBER_NAME").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MEMBER_NAMEData(Nan::To<v8::String>(MEMBER_NAMEObj).ToLocalChecked());
    strncpy(field.MEMBER_NAME, *MEMBER_NAMEData, 65);

    v8::Local<v8::Object> REMOTE_ADDRObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("REMOTE_ADDR").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value REMOTE_ADDRData(Nan::To<v8::String>(REMOTE_ADDRObj).ToLocalChecked());
    strncpy(field.REMOTE_ADDR, *REMOTE_ADDRData, 65);

    v8::Local<v8::Object> LOCAL_ADDRObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("LOCAL_ADDR").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value LOCAL_ADDRData(Nan::To<v8::String>(LOCAL_ADDRObj).ToLocalChecked());
    strncpy(field.LOCAL_ADDR, *LOCAL_ADDRData, 65);

    v8::Local<v8::Object> ADDRESSObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("ADDRESS").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value ADDRESSData(Nan::To<v8::String>(ADDRESSObj).ToLocalChecked());
    strncpy(field.ADDRESS, *ADDRESSData, 257);

    v8::Local<v8::Object> LINE_STATUSObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("LINE_STATUS").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value LINE_STATUSData(Nan::To<v8::String>(LINE_STATUSObj).ToLocalChecked());
    strncpy(field.LINE_STATUS, *LINE_STATUSData, 33);

    v8::Local<v8::Object> CONTACTObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("CONTACT").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value CONTACTData(Nan::To<v8::String>(CONTACTObj).ToLocalChecked());
    strncpy(field.CONTACT, *CONTACTData, 33);

    v8::Local<v8::Object> TELEPHONEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TELEPHONE").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value TELEPHONEData(Nan::To<v8::String>(TELEPHONEObj).ToLocalChecked());
    strncpy(field.TELEPHONE, *TELEPHONEData, 65);

    v8::Local<v8::Object> MOBILEPHONEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("MOBILEPHONE").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value MOBILEPHONEData(Nan::To<v8::String>(MOBILEPHONEObj).ToLocalChecked());
    strncpy(field.MOBILEPHONE, *MOBILEPHONEData, 65);

    v8::Local<v8::Object> EMAILObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EMAIL").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EMAILData(Nan::To<v8::String>(EMAILObj).ToLocalChecked());
    strncpy(field.EMAIL, *EMAILData, 65);

    v8::Local<v8::Object> FAXObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("FAX").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value FAXData(Nan::To<v8::String>(FAXObj).ToLocalChecked());
    strncpy(field.FAX, *FAXData, 65);

    v8::Local<v8::Object> PROVINCEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("PROVINCE").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value PROVINCEData(Nan::To<v8::String>(PROVINCEObj).ToLocalChecked());
    strncpy(field.PROVINCE, *PROVINCEData, 33);

    v8::Local<v8::Object> DDN_NOObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DDN_NO").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value DDN_NOData(Nan::To<v8::String>(DDN_NOObj).ToLocalChecked());
    strncpy(field.DDN_NO, *DDN_NOData, 65);

    v8::Local<v8::Object> IN_MODEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IN_MODE").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IN_MODEData(Nan::To<v8::String>(IN_MODEObj).ToLocalChecked());
    strncpy(field.IN_MODE, *IN_MODEData, 65);

    v8::Local<v8::Object> IP_WANObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IP_WAN").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IP_WANData(Nan::To<v8::String>(IP_WANObj).ToLocalChecked());
    strncpy(field.IP_WAN, *IP_WANData, 65);

    v8::Local<v8::Object> IP_LANObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IP_LAN").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IP_LANData(Nan::To<v8::String>(IP_LANObj).ToLocalChecked());
    strncpy(field.IP_LAN, *IP_LANData, 65);

    v8::Local<v8::Object> IPADDRObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IPADDR").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IPADDRData(Nan::To<v8::String>(IPADDRObj).ToLocalChecked());
    strncpy(field.IPADDR, *IPADDRData, 65);

    v8::Local<v8::Object> InterfaceObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("Interface").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value InterfaceData(Nan::To<v8::String>(InterfaceObj).ToLocalChecked());
    strncpy(field.Interface, *InterfaceData, 65);

    v8::Local<v8::Object> INTERFACE_DATEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("INTERFACE_DATE").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value INTERFACE_DATEData(Nan::To<v8::String>(INTERFACE_DATEObj).ToLocalChecked());
    strncpy(field.INTERFACE_DATE, *INTERFACE_DATEData, 33);

    v8::Local<v8::Object> SOFTWAREObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SOFTWARE").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value SOFTWAREData(Nan::To<v8::String>(SOFTWAREObj).ToLocalChecked());
    strncpy(field.SOFTWARE, *SOFTWAREData, 33);

    v8::Local<v8::Object> FEE_TYPEObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("FEE_TYPE").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value FEE_TYPEData(Nan::To<v8::String>(FEE_TYPEObj).ToLocalChecked());
    strncpy(field.FEE_TYPE, *FEE_TYPEData, 33);

    v8::Local<v8::Object> SERVICEPROVIDERObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SERVICEPROVIDER").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value SERVICEPROVIDERData(Nan::To<v8::String>(SERVICEPROVIDERObj).ToLocalChecked());
    strncpy(field.SERVICEPROVIDER, *SERVICEPROVIDERData, 33);

    v8::Local<v8::Object> IF_ZIYINGObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IF_ZIYING").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IF_ZIYINGData(Nan::To<v8::String>(IF_ZIYINGObj).ToLocalChecked());
    strncpy(field.IF_ZIYING, *IF_ZIYINGData, 33);

    v8::Local<v8::Object> IF_TUOGUANObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("IF_TUOGUAN").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value IF_TUOGUANData(Nan::To<v8::String>(IF_TUOGUANObj).ToLocalChecked());
    strncpy(field.IF_TUOGUAN, *IF_TUOGUANData, 33);

    v8::Local<v8::Object> HASOTHERObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("HASOTHER").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value HASOTHERData(Nan::To<v8::String>(HASOTHERObj).ToLocalChecked());
    strncpy(field.HASOTHER, *HASOTHERData, 33);

    v8::Local<v8::Object> SEAT_NOObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SEAT_NO").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value SEAT_NOData(Nan::To<v8::String>(SEAT_NOObj).ToLocalChecked());
    strncpy(field.SEAT_NO, *SEAT_NOData, 1025);

    v8::Local<v8::Object> PROObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("PRO").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value PROData(Nan::To<v8::String>(PROObj).ToLocalChecked());
    strncpy(field.PRO, *PROData, 513);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryNetDelPartyLinkInfoTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryNetDelPartyLinkInfoTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryInstrumentStatusTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryInstrumentStatusTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryInstrumentStatusField field;

    v8::Local<v8::Object> SettlementGroupIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SettlementGroupID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value SettlementGroupIDData(Nan::To<v8::String>(SettlementGroupIDObj).ToLocalChecked());
    strncpy(field.SettlementGroupID, *SettlementGroupIDData, 9);

    v8::Local<v8::Object> InstrumentIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("InstrumentID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value InstrumentIDData(Nan::To<v8::String>(InstrumentIDObj).ToLocalChecked());
    strncpy(field.InstrumentID, *InstrumentIDData, 31);

    v8::Local<v8::Object> InstrumentStatusObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("InstrumentStatus").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> InstrumentStatusData = Nan::To<v8::Integer>(InstrumentStatusObj).ToLocalChecked();
    field.InstrumentStatus = InstrumentStatusData->Value();

    v8::Local<v8::Object> TradingSegmentSNObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TradingSegmentSN").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> TradingSegmentSNData = Nan::To<v8::Integer>(TradingSegmentSNObj).ToLocalChecked();
    field.TradingSegmentSN = TradingSegmentSNData->Value();

    v8::Local<v8::Object> EnterTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EnterTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EnterTimeData(Nan::To<v8::String>(EnterTimeObj).ToLocalChecked());
    strncpy(field.EnterTime, *EnterTimeData, 9);

    v8::Local<v8::Object> EnterReasonObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EnterReason").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> EnterReasonData = Nan::To<v8::Integer>(EnterReasonObj).ToLocalChecked();
    field.EnterReason = EnterReasonData->Value();

    v8::Local<v8::Object> EnterDateObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("EnterDate").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value EnterDateData(Nan::To<v8::String>(EnterDateObj).ToLocalChecked());
    strncpy(field.EnterDate, *EnterDateData, 9);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryInstrumentStatusTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryInstrumentStatusTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryCurrTradingSegmentAttrTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryCurrTradingSegmentAttrTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryCurrTradingSegmentAttrField field;

    v8::Local<v8::Object> SettlementGroupIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SettlementGroupID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value SettlementGroupIDData(Nan::To<v8::String>(SettlementGroupIDObj).ToLocalChecked());
    strncpy(field.SettlementGroupID, *SettlementGroupIDData, 9);

    v8::Local<v8::Object> TradingSegmentSNObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TradingSegmentSN").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> TradingSegmentSNData = Nan::To<v8::Integer>(TradingSegmentSNObj).ToLocalChecked();
    field.TradingSegmentSN = TradingSegmentSNData->Value();

    v8::Local<v8::Object> TradingSegmentNameObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TradingSegmentName").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value TradingSegmentNameData(Nan::To<v8::String>(TradingSegmentNameObj).ToLocalChecked());
    strncpy(field.TradingSegmentName, *TradingSegmentNameData, 21);

    v8::Local<v8::Object> StartTimeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value StartTimeData(Nan::To<v8::String>(StartTimeObj).ToLocalChecked());
    strncpy(field.StartTime, *StartTimeData, 9);

    v8::Local<v8::Object> InstrumentStatusObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("InstrumentStatus").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> InstrumentStatusData = Nan::To<v8::Integer>(InstrumentStatusObj).ToLocalChecked();
    field.InstrumentStatus = InstrumentStatusData->Value();

    v8::Local<v8::Object> InstrumentIDObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("InstrumentID").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value InstrumentIDData(Nan::To<v8::String>(InstrumentIDObj).ToLocalChecked());
    strncpy(field.InstrumentID, *InstrumentIDData, 31);

    v8::Local<v8::Object> AdvanceDaysObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("AdvanceDays").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> AdvanceDaysData = Nan::To<v8::Integer>(AdvanceDaysObj).ToLocalChecked();
    field.AdvanceDays = AdvanceDaysData->Value();

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryCurrTradingSegmentAttrTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryCurrTradingSegmentAttrTopic: END! ******", g_RunningResult_File);
}

NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryPerformanceTopTopic) {
    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryPerformanceTopTopic: START! ******", g_RunningResult_File);

    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    if(!(info[0]->IsObject() && info[1]->IsNumber()))
    {
        Nan::ThrowError("wrong parameter!");
    }
    v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
    CShfeFtdcReqQryPerformanceTopField field;

    v8::Local<v8::Object> OperationTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("OperationType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> OperationTypeData = Nan::To<v8::Integer>(OperationTypeObj).ToLocalChecked();
    field.OperationType = OperationTypeData->Value();

    v8::Local<v8::Object> AttrTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("AttrType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value AttrTypeData(Nan::To<v8::String>(AttrTypeObj).ToLocalChecked());
    strncpy(field.AttrType, *AttrTypeData, 65);

    v8::Local<v8::Object> NetAreaObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("NetArea").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> NetAreaData = Nan::To<v8::Integer>(NetAreaObj).ToLocalChecked();
    field.NetArea = NetAreaData->Value();

    v8::Local<v8::Object> NetSubAreaObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("NetSubArea").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value NetSubAreaData(Nan::To<v8::String>(NetSubAreaObj).ToLocalChecked());
    strncpy(field.NetSubArea, *NetSubAreaData, 65);

    v8::Local<v8::Object> KeyWordObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("KeyWord").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value KeyWordData(Nan::To<v8::String>(KeyWordObj).ToLocalChecked());
    strncpy(field.KeyWord, *KeyWordData, 101);

    v8::Local<v8::Object> SortValueObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SortValue").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> SortValueData = Nan::To<v8::Integer>(SortValueObj).ToLocalChecked();
    field.SortValue = SortValueData->Value();

    v8::Local<v8::Object> SortTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("SortType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> SortTypeData = Nan::To<v8::Integer>(SortTypeObj).ToLocalChecked();
    field.SortType = SortTypeData->Value();

    v8::Local<v8::Object> DuringTimeTypeObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DuringTimeType").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> DuringTimeTypeData = Nan::To<v8::Integer>(DuringTimeTypeObj).ToLocalChecked();
    field.DuringTimeType = DuringTimeTypeData->Value();

    v8::Local<v8::Object> DuringTimeValueObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("DuringTimeValue").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> DuringTimeValueData = Nan::To<v8::Integer>(DuringTimeValueObj).ToLocalChecked();
    field.DuringTimeValue = DuringTimeValueData->Value();

    v8::Local<v8::Object> TopNObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TopN").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Integer> TopNData = Nan::To<v8::Integer>(TopNObj).ToLocalChecked();
    field.TopN = TopNData->Value();

    v8::Local<v8::Object> TopResultObj = Nan::To<v8::Object>(Nan::Get(paraValue,Nan::New<v8::String>("TopResult").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
    v8::String::Utf8Value TopResultData(Nan::To<v8::String>(TopResultObj).ToLocalChecked());
    strncpy(field.TopResult, *TopResultData, 257);

    v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
    int nRequestID = (int)paramTwo->Value();

    double returnValue= obj->m_userApi->ReqQryPerformanceTopTopic(&field, nRequestID);

    info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));

    OutputCallbackMessage("\n****** FtdApi-wrapper: ReqQryPerformanceTopTopic: END! ******", g_RunningResult_File);
}
