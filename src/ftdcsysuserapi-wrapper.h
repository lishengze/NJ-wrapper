#ifndef FTDCSYSUSERAPI_WRAPPER_H
#define FTDCSYSUSERAPI_WRAPPER_H

#include <nan.h>
#include "FtdcUserApi.h"
#include "sysuserspi.h"

class FtdcSysUserApi_Wrapper : public Nan::ObjectWrap{
 public:
     static void InitExports(v8::Handle<v8::Object> exports);

 public:
     explicit FtdcSysUserApi_Wrapper(const char *pszFlowPath);
     ~FtdcSysUserApi_Wrapper();
  
     static Nan::Persistent<v8::Function> constructor;
     CShfeFtdcUserApi* m_userApi;
     SysUserSpi* m_spi;

     static NAN_METHOD(New);
     static NAN_METHOD(RegisterFront);
     static NAN_METHOD(RegisterSpi);
     static NAN_METHOD(Init);

     static NAN_METHOD(ReqQrySysUserLoginTopic);

     static NAN_METHOD(Join);
 
};

#endif