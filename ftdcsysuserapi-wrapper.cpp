#include <nan.h>
#include "ftdcsysuserapi-wrapper.h"
#include "FtdcSysUserApi.h"
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
    // m_userApi = NULL;
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

 // Prototype
 Nan::SetPrototypeMethod(tpl,"RegisterFront",RegisterFront);
 Nan::SetPrototypeMethod(tpl,"RegisterSpi",RegisterSpi);
 Nan::SetPrototypeMethod(tpl,"Init",Init);
 Nan::SetPrototypeMethod(tpl,"ReqQrySysUserLoginTopic",ReqQrySysUserLoginTopic); 
 Nan::SetPrototypeMethod(tpl,"Join",Join);

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
        
        // obj->m_spi->m_frontid = ++g_idnumb;
        
        obj->m_userApi->RegisterSpi(obj->m_spi);
    }
    info.GetReturnValue().SetUndefined();
}

NAN_METHOD (FtdcSysUserApi_Wrapper::Init) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    obj->m_userApi->Init();
    info.GetReturnValue().SetUndefined();
}
     
NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQrySysUserLoginTopic) {
     std::cout<<"ReqQrySysUserLoginTopic Called!"<<std::endl;
     FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
     if(!(info[0]->IsObject() && info[1]->IsNumber()))
     {
     Nan::ThrowError("wrong parameter!");
     }
     //convert parameter one
     v8::Local<v8::Object> paramOne=Nan::To<v8::Object>(info[0]).ToLocalChecked();
     CShfeFtdcReqQrySysUserLoginField field;
     //UserID
     v8::Local<v8::Object> paramOneUserIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("UserID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneUserIDStr(Nan::To<v8::String>(paramOneUserIDObj).ToLocalChecked());
     // strcpy_s(field.UserID, 16, *paramOneUserIDStr);
     strncpy(field.UserID, *paramOneUserIDStr, 16);
     std::cout<<*paramOneUserIDStr<<std::endl;
     //Password
     v8::Local<v8::Object> paramOnePasswordObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("Password").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOnePasswordStr(Nan::To<v8::String>(paramOnePasswordObj).ToLocalChecked());
     //encrypt password
     CDesEncryptAlgorithm DesEncrypt;
     DesEncrypt.SetPassword("monitor");
     char encryptedPassword[256] = {0};
     DesEncrypt.Encrypt(*paramOnePasswordStr, encryptedPassword);
     // strcpy_s(field.Password, 41, encryptedPassword);
     strncpy(field.Password, encryptedPassword, 41);
     std::cout<<encryptedPassword<<std::endl;
     //VersionID
     v8::Local<v8::Object> paramOneVersionIDObj=Nan::To<v8::Object>( Nan::Get(paramOne,Nan::New<v8::String>("VersionID").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
     v8::String::Utf8Value paramOneVersionIDStr(Nan::To<v8::String>(paramOneVersionIDObj).ToLocalChecked());
     // strcpy_s(field.VersionID, 17, *paramOneVersionIDStr);
     strncpy(field.VersionID, *paramOneVersionIDStr, 17);
     std::cout<<*paramOneVersionIDStr<<std::endl;
     //convert parameter two
     v8::Local<v8::Integer> paramTwo=Nan::To<v8::Integer>(info[1]).ToLocalChecked();
     int nRequestID=(int)paramTwo->Value();

     //call natvie method
     double returnValue= obj->m_userApi->ReqQrySysUserLoginTopic(&field, nRequestID);

     info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}

NAN_METHOD (FtdcSysUserApi_Wrapper::Join) {
    FtdcSysUserApi_Wrapper* obj = ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
    int result=obj->m_userApi->Join();
    info.GetReturnValue().Set(Nan::New<v8::Int32>(result));
}
