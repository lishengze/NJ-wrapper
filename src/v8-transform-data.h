#ifndef _V8_TRANSFORM_DATA_H_
#define _V8_TRANSFORM_DATA_H_

#include <queue>
#include <map>
#include <vector>
#include "tool-function.h"
#include "id-func.h"
#include <nan.h>
#include <fstream>
using std::fstream;
using std::queue;
using std::map;
using std::vector;

extern fstream g_RunningResult_File;

void InitV8Transformdata (); 
 
void DeInitV8Transformdata ();


extern uv_mutex_t   g_FrontConnected_mutex;
extern uv_async_t   g_FrontConnected_async;
extern vector<FRONT_ID>   g_FrontConnected_IOUser_vec;
extern map<FRONT_ID, queue<void**> >   g_FrontConnected_Data_map;

extern uv_mutex_t   g_RspQrySysUserLoginTopic_mutex;
extern uv_async_t   g_RspQrySysUserLoginTopic_async;
extern vector<FRONT_ID>    g_RspQrySysUserLoginTopic_IOUser_vec;
extern map<FRONT_ID, queue<void**> >   g_RspQrySysUserLoginTopic_Data_map;


#endif

