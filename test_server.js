var fs = require('fs');
var options = {
  key: fs.readFileSync("sfit.key"),
  cert: fs.readFileSync("sfit.cert"),
};

var app = require('https').createServer(options,onRequest); // 创建代理服务器;
var io  = require('socket.io')(app);
app.listen(8000);

// var app = require('http').createServer(onRequest); // 创建代理服务器;
// var io  = require('socket.io')(app);
// app.listen(80);

var server = require('./server.js');

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
io.on('connection', function(rootSocket) {
	
	console.log('rootSocket connected!');	
	rootSocket.on('new user', function(userName) {				
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
				
			curSocket.on('Get from Client', function(data){				
				console.log('\nGet from Client: Hi server ' + data);																			
				curSocket.emit('Get from Server', data);
			});		
			
			// 为每个后台请求建立专属连订阅事件;			
			curSocket.on('ReqQrySysUserLoginTopic', function(userName){				
				console.log(userName + ' Login server');						
				server.ReqQrySysUserLoginTopic(curSocket);						
			});	
			
			curSocket.on('ReqNetMonitorAttrScope', function(username) {
				server.ReqNetMonitorAttrScope(curSocket);
			});						
			
	   });
	  
	   rootSocket.emit('ready to establish connect', userName);	  
	   console.log('\nnew user: ' + userName + ' arrived');											
	});
	
});
