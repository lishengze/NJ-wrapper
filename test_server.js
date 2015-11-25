var app = require('http').createServer(onRequest); // 创建代理服务器;
var io  = require('socket.io')(app);
app.listen(80);

var process = require('process');
function onRequest(request, response){
	try {
			response.writeHead(200, {'Content-Type':'text/plain'});
			response.write('Hello Socket.io');
			response.end();
	}catch (err) {
			console.error(err);
	}

}

var userSocketServer = {};
var userNameArry     = [];
var userCount        = 0;

// 连接后台服务器.
io.on('connection', function(socket) {
	
	console.log('rootSocket');
	
	socket.on('new user', function(userName) {
				
		for (var i = 0, length = userNameArry.length; i < length; ++i)
		{
			if (userNameArry[i] === userName) {
				
				console.log(userName + ' is already in.');
				return;
			}			
		}
		
		userNameArry[userCount] = userName;
		
		userCount += 1;
						
		// 为每个用户以用户名注册专属连接;				
		userSocketServer[userName] = io.of('/' + userName);
								 				 
		// 为每个用户建立专属连接, 
		// 所有的通讯都在 connection 响应的事件里, 通过emit, on控制;		
		userSocketServer[userName].on('connection', function(curSocket){
			
			console.log(userName + ' connect completed.');
			
			curSocket.emit('connect completed', userName);
			
			curSocket.on('Login server', function(userName){
				
				console.log(userName + ' Login server');
						
				loginServer(curSocket);						
			});	
	
			curSocket.on('Get from Client', function(data){
				
				console.log('\nGet from Client: Hi server ' + data);										
									
				curSocket.emit('Get from Server', data);
			});								
			
	   });
	  
	  socket.emit('ready to establish connect', userName);
	  
	  console.log('\nnew user: ' + userName + ' arrived');											
	});
	
});



var addon = require("./build/Release/addon");
var structJs=require("./SysUserApiStruct_JS.js");
var fs = require('fs');
var Spi=function(){};
Spi.prototype.OnFrontConnected=function(){
	console.log("FrontConnected!");
};

var userApi = new addon.FtdcSysUserApi_Wrapper();
userApi.RegisterFront("tcp://172.1.128.111:18842");       // 内部测试环境;
userApi.RegisterSpi(new Spi());
userApi.Init();

var nRequestID=1;

function loginServer(socket){
					
	Spi.prototype.OnRspQrySysUserLoginTopic = function(pRspQrySysUserLogin,pRspInfo,nRequestID,bIsLast)
	{
	// console.log("\n" + "**************Test JS Api: START! ***********");
	// console.log("LoginTime in JS is: "+pRspQrySysUserLogin.LoginTime);
	// console.log("UserID in JS is: "+pRspQrySysUserLogin.UserID);
	// console.log("Privilege in JS is: "+pRspQrySysUserLogin.Privilege);
	// console.log("TradingDay in JS is: "+pRspQrySysUserLogin.TradingDay);
	// console.log("VersionFlag in JS is: "+pRspQrySysUserLogin.VersionFlag);
	// console.log("datatype of pRspQrySysUserLogin is: "+typeof(pRspQrySysUserLogin));
	
	// if(pRspInfo instanceof Object){
    //   console.log("ErrorID in JS is: "+pRspInfo.ErrorID);
    //   console.log("ErrorMsg in JS is: "+pRspInfo.ErrorMsg);
	// }
	// else{
	// 	console.log("datatype of pRspInfo is: "+typeof(pRspInfo));
	// 	console.log("pRspInfo is: "+pRspInfo);		
	// }
	
	// console.log("nRequestID in JS is: "+nRequestID);
	// console.log("nIsLastNew in JS is: "+bIsLast);
	// console.log("**************Test JS Api: END! *************" + "\n");
	
		var loginData = {};
		loginData.LoginTime = pRspQrySysUserLogin.LoginTime;
		loginData.UserID = pRspQrySysUserLogin.UserID;
		loginData.Privilege = pRspQrySysUserLogin.Privilege;
		loginData.TradingDay = pRspQrySysUserLogin.TradingDay;
		loginData.VersionFlag = pRspQrySysUserLogin.VersionFlag;
		loginData.nRequestID = pRspQrySysUserLogin.nRequestID;
		loginData.nIsLastNew = pRspQrySysUserLogin.nIsLastNew;
	
		if(pRspInfo instanceof Object){
			loginData.ErrorID = pRspQrySysUserLogin.ErrorID;
			loginData.ErrorMsg = pRspQrySysUserLogin.ErrorMsg;
		}
		
		var message = "OnRspQrySysUserLoginTopic";
		socket.emit(message, loginData);
	
	}
		
// 请求登陆;
	var loginField       = new structJs.CShfeFtdcReqQrySysUserLoginField();
	loginField.UserID    = "admin";
	loginField.Password  = "admin";
	loginField.VersionID = "2.0.0.0";
	console.log("ReqLogin result:" + userApi.ReqQrySysUserLoginTopic(loginField, nRequestID) + "\n");			
				
}
