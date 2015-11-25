var app = require('http').createServer(onRequest); // 创建代理服务器;
var io = require('socket.io')(app);

app.listen(80);

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
var userNameArry = [];
var userCount = 0;

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


function loginServer(socket){
			
	var addon;	
	var body = "";
		
		try{
			addon = require('./Release/addon.node');}
			catch(error){
			console.log(error);
		}

		var structJs=require("./SysUserApiStruct_JS.js");

		var Spi=function(){};
		Spi.prototype.OnFrontConnected=function(){
			
			body += "FrontConnected!\n";			   
			console.log("FrontConnected!");
			socket.emit('connect_server', body);
		};
	
		Spi.prototype.OnRspQrySysUserLoginTopic=function(){
												
			console.log("haha!");
			console.log("交易日："+userApi.GetTradingDay());
			body += "haha!\n"+"交易日："+userApi.GetTradingDay();	
			socket.emit('connect_server', body);   // 将消息传送给客户端;
		}

		var userApi = new addon.FtdcSysUserApi_Wrapper();

		userApi.RegisterFront("tcp://172.1.128.165:18841");      
		userApi.RegisterSpi(new Spi());                          
		userApi.Init();	
	
		var loginField=new structJs.CShfeFtdcReqQrySysUserLoginField();
		loginField.UserID="admin";
		loginField.Password="admin";
		loginField.VersionID="2.0.0.0";
				
}
