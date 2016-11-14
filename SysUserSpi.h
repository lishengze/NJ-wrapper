#ifndef _SYSUSERSPI_H_
 #define _SYSUSERSPI_H_

 #include "FtdcSysUserApi.h"
 #include "tool-function.h"
 #include "id-func.h"
 #include "nan.h"

 class SysUserSpi: public CShfeFtdcSysUserSpi
 {
    public:
        Nan::Persistent<v8::Object> m_spiobj;
        FRONT_ID m_frontid;
        
    public:
        virtual ~SysUserSpi() {}
        
        virtual void OnFrontConnected();

        virtual void OnRspQrySysUserLoginTopic(CShfeFtdcRspQrySysUserLoginField *pRspQrySysUserLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

};


#endif