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
	
	var int;
	console.log('rootSocket completed');
		
	socket.on('stop emit data', function(obj){
		clearInterval(int);
	})
	 
	socket.on('start data stream', function (obj) {	
	  
	  var data = [15, 20, 25,28];
	  int = setInterval(function(){
		
		var randonValue = Math.ceil(Math.random() * 20);
		var maximumIndex = 0, minimumIndex = 0;
		for (var i = 1, length = data.length; i < length; ++i) {
			
			if (data[maximumIndex] < data[i]) {
				maximumIndex = i;
			} 		
			
			if (data[minimumIndex] > data[i]) {
				minimumIndex = i;
			}
		}
		
		if (maximumIndex === minimumIndex) {
			minimumIndex = data.length - 1;
		}		
		
		data[maximumIndex] -= randonValue;
		data[minimumIndex] += randonValue;
		
		socket.emit('new data comes', data);
	    }, 500);
	});
	

});
