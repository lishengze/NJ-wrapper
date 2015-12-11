// // var io = require('socket.io-client');
// var url = 'https://localhost:443';
// var rootSocket = io.connect(url, {secure:true});
// // var rootSocket = io.connect(url);
// var loginMessage = "OnRspQrySysUserLoginTopic";
// // var fs = require('fs');

var url = 'http://localhost';
var rootSocket = io.connect(url);
		
writeData('Connect default io namespace');
		
var userSocketClient = {};
var userNameArry     = [];
var userCount        = 0;

/*
var io=require('socket.io-client');
  var url = 'https://localhost:443';
  rootSocket = io.connect(url,{secure:true});

  rootSocket.emit('start data stream', 'start');
  rootSocket.on('new data comes', function(data){
     console.log('did receive data');
    });
*/

// 注册来自服务端的消息, 需要响应的事件只注册一次.	
rootSocket.on('ready to establish connect', function(username){
				
	writeData('establish connect ' + username);
					
	userSocketClient[username] = io.connect(url + '/' + username); // stoped;
							
	userSocketClient[username].on('connect completed', function(username){	
		userNameArry[userCount++] = username;		
		writeData(username + ' connect completed');						
		if (username === 'admin') {
				loginServer(username);
		}																				
	});	
			
	userSocketClient[username].on('connect_server', function(data){
		writeData(data);								
	});
				
		
	userSocketClient[username].on('Get from Server', function(data){				
		writeData('Get from Server: Hi Client '+ data);				
	});		
	
	userSocketClient[username].on("ReqQrySysUserLoginTopic CallbackData", function (callbackData) {
		alert(callbackData[0].LoginTime);
	});
	
	userSocketClient[username].on("RtnNetLocalPingResultInfoTopic CallbackData", function (callbackData) {
		alert(callbackData.PTimeSta);
	});
	
	userSocketClient[username].on("RtnSysTimeSyncTopic CallbackData", function (callbackData) {
		alert(callbackData.MonTime);
	});
						
	userSocketClient[username].on("ReqNetMonitorAttrScope CallbackData", function (callbackData) {
		alert(callbackData[0].ID);
	});
	
	
										
});
						
function addUser(username) {		
	writeData(url + '/' + username);		
	rootSocket.emit('new user', username);		// 发多次;				
}
	
function ReqQrySysUserLoginTopic(username){
	var bIsUserNameConnected = false;
	for (var i = 0; i<userCount; ++i) {
		if (userNameArry[i] === username) {
			bIsUserNameConnected = true;
			break;
		} 
	}
	
	if (true === bIsUserNameConnected) {
		userSocketClient[username].emit('ReqQrySysUserLoginTopic', username);	
	} else {
		alert(username + " doesn't connect to the server.");
		return;
	}								
}
				
function disconnectServer (username) {
	userSocketClient[username].disconnect();
}
	
function testCommunicateUser(username){
	var bIsUserNameConnected = false;
	for (var i = 0; i<userCount; ++i) {
		if (userNameArry[i] === username) {
			bIsUserNameConnected = true;
			break;
		} 
	}
	
	if (true === bIsUserNameConnected) {
		userSocketClient[username].emit('Get from Client', username);
	} else {
		alert(username + " doesn't connect to the server.");
		return;
	}			
}
				
function ReqNetMonitorAttrScope(username){
	var bIsUserNameConnected = false;
	for (var i = 0; i<userCount; ++i) {
		if (userNameArry[i] === username) {
			bIsUserNameConnected = true;
			break;
		} 
	}
	
	if (true === bIsUserNameConnected) {
		userSocketClient[username].emit('ReqNetMonitorAttrScope', username);	
	} else {
		alert(username + " doesn't connect to the server.");
		return;
	}						
}	

function writeData(Data){
		console.log(Data);								
}		
