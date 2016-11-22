NAN_METHOD (FtdcSysUserApi_Wrapper::ReqQryTopMemInfoTopic) {
  std::cout<<"ReqQryTopMemInfoTopic Called!"<<std::endl;
  FtdcSysUserApi_Wrapper* obj  =  ObjectWrap::Unwrap<FtdcSysUserApi_Wrapper>(info.Holder());
  if(!(info[0]->IsObject() && info[1]->IsNumber()))
  {
   Nan::ThrowError("wrong parameter!");
  }

  v8::Local<v8::Object> paraValue = Nan::To<v8::Object>(info[0]).ToLocalChecked();
  CShfeFtdcReqQryTopMemInfoField field;

  v8::Local<v8::Object> paramOneHostNameObj = Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("HostName").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneHostNamefileData(Nan::To<v8::String>(paramOneHostNameObj).ToLocalChecked());
  strncpy(field.HostName, *paramOneHostNamefileData, 65);

  v8::Local<v8::Object> paramOneStartDateObj = Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("StartDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartDatefileData(Nan::To<v8::String>(paramOneStartDateObj).ToLocalChecked());
  strncpy(field.StartDate, *paramOneStartDatefileData, 9);

  v8::Local<v8::Object> paramOneStartTimeObj = Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("StartTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneStartTimefileData(Nan::To<v8::String>(paramOneStartTimeObj).ToLocalChecked());
  strncpy(field.StartTime, *paramOneStartTimefileData, 9);

  v8::Local<v8::Object> paramOneEndDateObj = Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("EndDate").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndDatefileData(Nan::To<v8::String>(paramOneEndDateObj).ToLocalChecked());
  strncpy(field.EndDate, *paramOneEndDatefileData, 9);

  v8::Local<v8::Object> paramOneEndTimeObj = Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("EndTime").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::String::Utf8Value paramOneEndTimefileData(Nan::To<v8::String>(paramOneEndTimeObj).ToLocalChecked());
  strncpy(field.EndTime, *paramOneEndTimefileData, 9);

  v8::Local<v8::Object> paramOneKeepAliveObj = Nan::To<v8::Object>( Nan::Get(paraValue,Nan::New<v8::String>("KeepAlive").ToLocalChecked()).ToLocalChecked() ).ToLocalChecked();
  v8::Local<v8::Integer> paramOneKeepAlivefileData = Nan::To<v8::Integer>( paramOneKeepAliveObj).ToLocalChecked();
  field.KeepAlive = paramOneKeepAlivefileData->Value();

  v8::Local<v8::Integer> paramTwo = Nan::To<v8::Integer>(info[1]).ToLocalChecked();
  int nRequestID = (int)paramTwo->Value();

  double returnValue =  obj->m_userApi->ReqQryTopMemInfoTopic(&field, nRequestID);

  info.GetReturnValue().Set(Nan::New<v8::Number>(returnValue));
}
