void OnRspQrySysUserLoginTopic (uv_async_t *handle){
    OutputCallbackMessage("\n****** v8-transform-func:: RspQrySysUserLoginTopic: START! ******", g_RunningResult_File);
    queue<void**>* pReceivedData;
    uv_mutex_lock (&g_RspQrySysUserLoginTopic_mutex);

    int ioUserNumb = g_RspQrySysUserLoginTopic_IOUser_vec.size();
    pReceivedData = new queue<void**>[ioUserNumb];
    int i = 0;
    for(vector<FRONT_ID>::iterator it = g_RspQrySysUserLoginTopic_IOUser_vec.begin();
        it != g_RspQrySysUserLoginTopic_IOUser_vec.end(); it++ , i++) {
        int dataNumb = g_RspQrySysUserLoginTopic_Data_map[*it].size();
        OutputCallbackMessage("dataNumb in this queue is: ",  dataNumb, g_RunningResult_File);
        while (!g_RspQrySysUserLoginTopic_Data_map[*it].empty()) {
            pReceivedData[i].push (g_RspQrySysUserLoginTopic_Data_map[*it].front());
            g_RspQrySysUserLoginTopic_Data_map[*it].pop();
        }
    }
    g_RspQrySysUserLoginTopic_IOUser_vec.clear();

    uv_mutex_unlock (&g_RspQrySysUserLoginTopic_mutex);

    for (int i = 0; i < ioUserNumb; ++i) {
        while ( !pReceivedData[i].empty() ) {
            void** paramArray = pReceivedData[i].front();
            pReceivedData[i].pop();

            if (NULL == paramArray ) {
                OutputCallbackMessage ("v8-transform-func::Delivered RspQrySysUserLoginTopic paramArray is NULL", g_RunningResult_File);
                OutputCallbackMessage ("****** v8-transform-func:: RspQrySysUserLoginTopic: END! ******\n", g_RunningResult_File);
                return;
            }

            Nan::HandleScope scope;
            Nan::Persistent<v8::Object>* pSpiObj = (Nan::Persistent<v8::Object>*)paramArray[0];
            if (pSpiObj->IsEmpty()) {
                OutputCallbackMessage ("v8-transform-func::pSpiObj is NULL", g_RunningResult_File);
                return;
            }
        
            v8::Local<v8::Object> localSpiObj = Nan::New<v8::Object>(*pSpiObj);            
            v8::Local<v8::Value> OnRspQrySysUserLoginTopic = localSpiObj->Get(Nan::New<v8::String>("OnRspQrySysUserLoginTopic").ToLocalChecked());
            CShfeFtdcRspQrySysUserLoginField* pRspQrySysUserLogin = (CShfeFtdcRspQrySysUserLoginField*)(paramArray[1]);
            CShfeFtdcRspInfoField *pRspInfo = (CShfeFtdcRspInfoField *)(paramArray[2]);
            int* pRequestID = (int*)paramArray[3];
            bool* pIsLastNew = (bool*)paramArray[4];

            if (OnRspQrySysUserLoginTopic->IsFunction()) {

                v8::Local<v8::Function> function = v8::Local<v8::Function>::Cast(OnRspQrySysUserLoginTopic);
                Nan::Callback callback(function);

                v8::Local<v8::Object> pRspQrySysUserLoginJS = Nan::New<v8::Object>();
                v8::Local<v8::Object> pRspInfoJS = Nan::New<v8::Object>();
                v8::Local<v8::Integer> nRequestIDJS = Nan::New<v8::Integer>(*pRequestID);
                v8::Local<v8::Boolean> nIsLastNewJS = Nan::New<v8::Boolean>(*pIsLastNew);
                
                if (NULL != pRspQrySysUserLogin) { 
                    string utf8string;
                    v8::Local<v8::String> UserID = Nan::New<v8::String> ("UserID").ToLocalChecked();
                    Gb2312ToUtf8(pRspQrySysUserLogin->UserID, utf8string);
                    v8::Local<v8::String> UserIDValue = Nan::New<v8::String> (utf8string.c_str()).ToLocalChecked();
                    pRspQrySysUserLoginJS->Set(Local<v8::Value> (UserID), Local<v8::Value>(UserIDValue));

                    v8::Local<v8::String> TradingDay = Nan::New<v8::String> ("TradingDay").ToLocalChecked();
                    Gb2312ToUtf8(pRspQrySysUserLogin->TradingDay, utf8string);
                    v8::Local<v8::String> TradingDayValue = Nan::New<v8::String> (utf8string.c_str()).ToLocalChecked();
                    pRspQrySysUserLoginJS->Set(Local<v8::Value> (TradingDay), Local<v8::Value>(TradingDayValue));

                    v8::Local<v8::String> LoginTime = Nan::New<v8::String> ("LoginTime").ToLocalChecked();
                    Gb2312ToUtf8(pRspQrySysUserLogin->LoginTime, utf8string);
                    v8::Local<v8::String> LoginTimeValue = Nan::New<v8::String> (utf8string.c_str()).ToLocalChecked();
                    pRspQrySysUserLoginJS->Set(Local<v8::Value> (LoginTime), Local<v8::Value>(LoginTimeValue));

                    v8::Local<v8::String> Privilege = Nan::New<v8::String> ("Privilege").ToLocalChecked();
                    v8::Local<v8::Integer> PrivilegeValue = Nan::New<v8::Integer> (pRspQrySysUserLogin->Privilege);
                    pRspQrySysUserLoginJS->Set(Local<v8::Value> (Privilege), Local<v8::Value>(PrivilegeValue));

                    v8::Local<v8::String> VersionFlag = Nan::New<v8::String> ("VersionFlag").ToLocalChecked();
                    v8::Local<v8::Integer> VersionFlagValue = Nan::New<v8::Integer> (pRspQrySysUserLogin->VersionFlag);
                    pRspQrySysUserLoginJS->Set(Local<v8::Value> (VersionFlag), Local<v8::Value>(VersionFlagValue));

                }

                if (NULL != pRspInfo){
                    v8::Local<v8::String>  ErrorID = Nan::New<v8::String>("ErrorID").ToLocalChecked();
                    v8::Local<v8::Integer> ErrorIDValue = Nan::New<v8::Integer>(pRspInfo->ErrorID);
                    pRspInfoJS->Set(Local<v8::Value>(ErrorID),Local<v8::Value>(ErrorIDValue));
                        
                    v8::Local<v8::String>  ErrorMsg = Nan::New<v8::String>("ErrorMsg").ToLocalChecked();
                    v8::Local<v8::String>  ErrorMsggValue = Nan::New(pRspInfo->ErrorMsg).ToLocalChecked();                                
                    pRspInfoJS->Set(Local<v8::Value>(ErrorMsg),Local<v8::Value>(ErrorMsggValue));
			    }                

                v8::Local<v8::Value> params[4];
                if (NULL != pRspQrySysUserLogin) { 
                    params[0] = Local<v8::Value>(pRspQrySysUserLoginJS);
                } else { 
                    params[0] = Local<v8::Value>(Nan::Undefined());
                };

                if (NULL != pRspInfo) {
                    params[1] = Local<v8::Value>(pRspInfoJS);
                } else {
                    params[1] = Local<v8::Value>(Nan::Undefined());
                }
                params[2] = Local<v8::Value>(nRequestIDJS);
                params[3] = Local<v8::Value>(nIsLastNewJS);
                
                callback.Call(localSpiObj, 4, params);

            } // OnFrontConnected->IsFunction() end!


            if(NULL != pSpiObj) {
                delete pSpiObj;
                pSpiObj = NULL;
            }
            if (NULL != pRspQrySysUserLogin) { 
                delete pRspQrySysUserLogin;
                pRspQrySysUserLogin = NULL;
            }

            if (NULL != pRspInfo) {
                delete pRspInfo;
                pRspInfo = NULL;
            }       
            
            if (NULL != pRequestID) {
                delete pRequestID;
                pRequestID = NULL;
            }  
            
            if (NULL != pIsLastNew) {
                delete pIsLastNew;
                pIsLastNew = NULL;
            }  

            if (NULL != paramArray) {
                delete []paramArray;
                paramArray = NULL;
            }       
         } // while() end!;
     } // for() end!
     
     if (NULL != pReceivedData) {
        delete[] pReceivedData;
        pReceivedData = NULL;
     }
     
    OutputCallbackMessage("****** v8-transform-func:: RspQrySysUserLoginTopic: END! ******\n", g_RunningResult_File);
}