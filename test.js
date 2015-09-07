
var addon = require("./build/Release/addon");
var structJs=require("./SysUserApiStruct_JS.js");

var Spi=function(){};
Spi.prototype.OnFrontConnected=function(){
	console.log("FrontConnected!");
};
///////////////////////////////////////////////////////////////////////////////////////////
// ///用户登录应答
// struct CShfeFtdcRspQrySysUserLoginField-->pRspQrySysUserLogin
// {
// 	///用户代码
// 	TShfeFtdcUserIDType	UserID;
// 	///交易日
// 	TShfeFtdcDateType	TradingDay;
// 	///登录成功时间
// 	TShfeFtdcTimeType	LoginTime;
// 	///用户权限
// 	TShfeFtdcPrivilegeType	Privilege;
// 	///版本匹配标识
// 	TShfeFtdcVersionFlagType	VersionFlag;
// };
// struct CShfeFtdcRspInfoField-->pRspInfo
// {
// 	///错误代码
// 	TShfeFtdcErrorIDType	ErrorID;
// 	///错误信息
// 	TShfeFtdcErrorMsgType	ErrorMsg;
// };
//Spi.prototype.OnRspQrySysUserLoginTopic=function(pRspQrySysUserLogin,pRspInfo,nRequestID,bIsLast)
Spi.prototype.OnRspQrySysUserLoginTopic=function(pRspQrySysUserLogin,pRspInfo,nRequestID,bIsLast)
{
	console.log("haha!");
	console.log("LoginTime in JS is: "+pRspQrySysUserLogin.LoginTime);
	console.log("UserID in JS is: "+pRspQrySysUserLogin.UserID);
	console.log("Privilege in JS is: "+pRspQrySysUserLogin.Privilege);
	console.log("TradingDay in JS is: "+pRspQrySysUserLogin.TradingDay);
	console.log("VersionFlag in JS is: "+pRspQrySysUserLogin.VersionFlag);
	console.log("datatype of pRspQrySysUserLogin is: "+typeof(pRspQrySysUserLogin));
	if(pRspInfo instanceof Object){
      console.log("ErrorID in JS is: "+pRspInfo.ErrorID);
      console.log("ErrorMsg in JS is: "+pRspInfo.ErrorMsg);
	}
	else{
		console.log("datatype of pRspInfo is: "+typeof(pRspInfo));
		console.log("pRspInfo is: "+pRspInfo);		
	}
	
	// console.log("ErrorID in JS is: "+pRspInfo.ErrorID);
	// console.log("ErrorMsg in JS is: "+pRspInfo.ErrorMsg);
	 console.log("nRequestID in JS is: "+nRequestID);
	 console.log("nIsLastNew in JS is: "+bIsLast);
}
var userApi = new addon.FtdcSysUserApi_Wrapper();
userApi.RegisterFront("tcp://172.1.128.165:18841");
userApi.RegisterSpi(new Spi());
userApi.Init();

var loginField=new structJs.CShfeFtdcReqQrySysUserLoginField();
loginField.UserID="admin";
loginField.Password="admin";
loginField.VersionID="2.0.0.0";
var nRequestID=1;
console.log("result:"+userApi.ReqQrySysUserLoginTopic(loginField, nRequestID));