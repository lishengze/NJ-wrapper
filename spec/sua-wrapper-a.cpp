NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryTopMemInfoTopic) {
    OutputCallbackMessage("\n****** sua-wrapper: ReqQryTopMemInfoTopic: START! ******", g_RunningResult_File);
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
}
