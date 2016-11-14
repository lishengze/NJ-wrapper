#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory.h>
#include "sysuserspi.h"
#include "v8-transform-data.h"
#include "tool-function.h"
#include <fstream>
#include <queue>
#include <map>
#include <vector>
using std::queue;
using std::map;
using std::vector;
using std::fstream;
using std::cin;
using std::cout;
using std::endl;
 
extern fstream g_RunningResult_File;
 
void SysUserSpi::OnFrontConnected () {
    OutputCallbackMessage("\n************SysUserSpi::OnFrontConnected() START! ************", g_RunningResult_File);

    void** paramArray = new void*[1];
    if (NULL == paramArray) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for paramArray", g_RunningResult_File);
        OutputCallbackMessage("****** SysUserSpi:: OnFrontConnected: END! ******\n", g_RunningResult_File);
        return;
    }

    Nan::Persistent<v8::Object>* pSpiObj = new Nan::Persistent<v8::Object>;
    if (NULL == pSpiObj) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pSpiObj", g_RunningResult_File);
        OutputCallbackMessage("****** SysUserSpi:: OnFrontConnected: END! ******\n", g_RunningResult_File);
        return;        
    }           
    memcpy(pSpiObj, &(this->m_spiobj), sizeof(Nan::Persistent<v8::Object>));
    
    paramArray[0] = (void*)pSpiObj; 
        
    uv_mutex_lock(&g_FrontConnected_mutex);
    vector<FRONT_ID>::iterator it ;
    for(it = g_FrontConnected_IOUser_vec.begin();
        it != g_FrontConnected_IOUser_vec.end(); it++ ) {
        if (*it == this->m_frontid){
             break;
        }       
    }            
    if (it ==  g_FrontConnected_IOUser_vec.end()) {
        g_FrontConnected_IOUser_vec.push_back(this->m_frontid);
    }  
    g_FrontConnected_Data_map[this->m_frontid].push((void**)(&paramArray[0]));
    uv_mutex_unlock(&g_FrontConnected_mutex);

    uv_async_send(&g_FrontConnected_async);

    OutputCallbackMessage("************SysUserSpi::OnFrontConnected() END! ************\n", g_RunningResult_File);
}

void SysUserSpi::OnRspQrySysUserLoginTopic(CShfeFtdcRspQrySysUserLoginField* pRspQrySysUserLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    OutputCallbackMessage("\n****** SysUserSpi:: RspQrySysUserLoginTopic: START! ******", g_RunningResult_File);

    Nan::Persistent<v8::Object>* pSpiObj = new Nan::Persistent<v8::Object>;
    if (NULL == pSpiObj) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pSpiObj", g_RunningResult_File);
        OutputCallbackMessage("****** SysUserSpi:: OnFrontConnected: END! ******\n", g_RunningResult_File);
        return;        
    }           
    memcpy(pSpiObj, &(this->m_spiobj), sizeof(Nan::Persistent<v8::Object>));
          
     void** paramArray = new void*[5];
    if (NULL == paramArray) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for paramArray", g_RunningResult_File);
        OutputCallbackMessage("****** SysUserSpi:: RspQrySysUserLoginTopic: END! ******\n", g_RunningResult_File);
        return; 
    } 

    CShfeFtdcRspQrySysUserLoginField* pNewRspQrySysUserLogin = NULL;
    if (NULL != pRspQrySysUserLogin) { 
        pNewRspQrySysUserLogin = new CShfeFtdcRspQrySysUserLoginField;
        if (NULL == pNewRspQrySysUserLogin) {
            OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pNewRspQrySysUserLogin", g_RunningResult_File);
            return;
        }
        memcpy (pNewRspQrySysUserLogin,pRspQrySysUserLogin, sizeof(CShfeFtdcRspQrySysUserLoginField));
    }

	CShfeFtdcRspInfoField* pRspInfoNew = NULL;
    if (NULL != pRspInfo){        
        pRspInfoNew = new CShfeFtdcRspInfoField;        
        if (NULL == pRspInfo) {
            OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pRspInfo", g_RunningResult_File);
            return;            
        }        
        memcpy(pRspInfoNew,pRspInfo,sizeof(CShfeFtdcRspInfoField));        
    }	
	
    int*  pId = new int(nRequestID);
    if (NULL == pId) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for pId", g_RunningResult_File);
        return;
    }
    
    bool* bIsLastNew = new bool(bIsLast);
    if (NULL == bIsLastNew) {
        OutputCallbackMessage("SysUserSpi:: Faild in allocating memory for bIsLastNew", g_RunningResult_File);
        return;
    }  	

    paramArray[0] = (void*)pSpiObj;
    paramArray[1] = (void*)pNewRspQrySysUserLogin;
    paramArray[2] = (void*)pRspInfoNew;		
    paramArray[3] = (void*)pId;
    paramArray[4] = (void*)bIsLastNew;			
			
    if (NULL == pRspQrySysUserLogin) { 
        OutputCallbackMessage("SysUserSpi::pRspQrySysUserLogin is NULL" , g_RunningResult_File); 
    } else {
        OutputCallbackMessage("pRspQrySysUserLogin->UserID: ", pRspQrySysUserLogin->UserID, g_RunningResult_File);
        OutputCallbackMessage("pRspQrySysUserLogin->TradingDay: ", pRspQrySysUserLogin->TradingDay, g_RunningResult_File);
        OutputCallbackMessage("pRspQrySysUserLogin->LoginTime: ", pRspQrySysUserLogin->LoginTime, g_RunningResult_File);
        OutputCallbackMessage("pRspQrySysUserLogin->Privilege: ", pRspQrySysUserLogin->Privilege, g_RunningResult_File);
        OutputCallbackMessage("pRspQrySysUserLogin->VersionFlag: ", pRspQrySysUserLogin->VersionFlag, g_RunningResult_File);
    }
    OutputCallbackMessage("pRspInfo:", pRspInfo, g_RunningResult_File);
    OutputCallbackMessage("nRequestID:", nRequestID, g_RunningResult_File);
    OutputCallbackMessage("bIsLast:", bIsLast, g_RunningResult_File);

    uv_mutex_lock (&g_RspQrySysUserLoginTopic_mutex);
    vector<FRONT_ID>::iterator it ;
    for(it = g_RspQrySysUserLoginTopic_IOUser_vec.begin();
        it != g_RspQrySysUserLoginTopic_IOUser_vec.end(); it++ ) {
        if (*it == this->m_frontid) break;     
    }
    if (it == g_RspQrySysUserLoginTopic_IOUser_vec.end()) {
        g_RspQrySysUserLoginTopic_IOUser_vec.push_back(this->m_frontid);
    }
    g_RspQrySysUserLoginTopic_Data_map[this->m_frontid].push ((void**)&paramArray[0]);
    uv_mutex_unlock (&g_RspQrySysUserLoginTopic_mutex);

    uv_async_send(&g_RspQrySysUserLoginTopic_async);
    OutputCallbackMessage("****** SysUserSpi:: RspQrySysUserLoginTopic: END! ******\n", g_RunningResult_File);
}



