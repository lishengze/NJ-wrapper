#include "v8-transform-data.h"
#include "v8-transform-func.h"
#include "FtdcSysUserApiStruct.h"
#include "tool-function.h"
#include "id-func.h"
#include <fstream>
using std::fstream;

using namespace v8;

fstream g_RunningResult_File;

void InitV8Transformdata () {
    
    uv_async_init (uv_default_loop(), &g_FrontConnected_async, OnFrontConnected);
    uv_mutex_init (&g_FrontConnected_mutex);

    uv_async_init (uv_default_loop(), &g_RspQrySysUserLoginTopic_async, OnRspQrySysUserLoginTopic);
    uv_mutex_init (&g_RspQrySysUserLoginTopic_mutex);
}

void DeInitV8Transformdata () {
    
    uv_close ((uv_handle_t*)&g_FrontConnected_async, NULL);

    uv_close ((uv_handle_t*) &g_RspQrySysUserLoginTopic_async,NULL);
}


uv_mutex_t   g_FrontConnected_mutex;
uv_async_t   g_FrontConnected_async;
vector<FRONT_ID>   g_FrontConnected_IOUser_vec;
map<FRONT_ID, queue<void**> >   g_FrontConnected_Data_map;

uv_mutex_t   g_RspQrySysUserLoginTopic_mutex;
uv_async_t   g_RspQrySysUserLoginTopic_async;
vector<FRONT_ID>    g_RspQrySysUserLoginTopic_IOUser_vec;
map<FRONT_ID, queue<void**> >   g_RspQrySysUserLoginTopic_Data_map;

