// var otherJS="socket.io.js";//js文件路径
// document.write('<scr' + 'ipt type="text/javascript" src="'+otherJS+'"></scr' + 'ipt>');

		var url = 'http://localhost';
		var rootSocket = io.connect(url);
		var loginMessage = "OnRspQrySysUserLoginTopic";
		writeData('Connect default io namespace');
		
		var userSocketClient = {};
			
		// 注册来自服务端的消息, 需要响应的事件只注册一次.	
		rootSocket.on('ready to establish connect', function(username){
			
			writeData('establish connect ' + username);
				
			userSocketClient[username] = io.connect(url + '/' + username); // stoped;
						
			userSocketClient[username].on('connect completed', function(username){
			
				writeData(username + ' connect completed');		
				
				 if (username === 'admin') {
					 loginServer(username);
				 }																				
			});	
			
			userSocketClient[username].on('connect_server', function(data){
			
				writeData(data);								
			});
			
			userSocketClient[username].on(loginMessage, function (loginData) {
				console.log(loginData);
			});
			
			userSocketClient[username].on('Get from Server', function(data){
				
				writeData('Get from Server: Hi Client '+ data);				
			});
										
		});
						
		function addUser(username) {
		
			writeData(url + '/' + username);		
			rootSocket.emit('new user', username);		// 发多次;				
						
		}
	
		function loginServer(username){
			
			userSocketClient[username].emit('Login server', username);					
		}
		
		function disconnectServer (username) {
			userSocketClient[username].disconnect();
		}
	
		function testCommunicateUser(username){
						
			userSocketClient[username].emit('Get from Client', username);
		}				
		
		function writeData(Data){
					
			console.log(Data);			
			// alert(Data);						
		}			