// 作者: 李晟泽
// 日期：2016.11.17;
// 作用：提供nodejs封装的输出接口和部分初始化工作。

#include <nan.h>
#include "ftdcsysuserapi-wrapper.h"
#include "tool-function.h"
#include "v8-transform-data.h"
#include "id-func.h"
#include <fstream>
using std::fstream;

extern fstream g_RunningResult_File;

using namespace v8;

void InitAll(Handle<Object> exports) {
    InitFrontIDQueue();        
    FtdcSysUserApi_Wrapper::InitExports (exports);
    InitV8Transformdata ();  

    g_RunningResult_File.open("running-result.txt",ios::out);    
    if (!g_RunningResult_File) {
        OutputCallbackMessage("Failed to open running-message.txt", g_RunningResult_File);
        g_RunningResult_File.close();
    }
    
    
 } 
 
NODE_MODULE (addon, InitAll);
 
