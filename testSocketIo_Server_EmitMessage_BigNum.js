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
		
	  console.log('Data stream started!');

	  int = setInterval(function(){				  
	  var dataNumb = 100000;
	  var maxValue = 30;
	  var modValue = dataNumb % (2 * maxValue);
	  var sectionNumb = (dataNumb-modValue) / (2 * maxValue);
	  var sectionProperty = new Array(2 * maxValue);
	  var data =  new Array(dataNumb);
	  	
    //   var dataProperty = {
	// 	dataNumb: dataNumb,
	// 	maxValue: maxValue,
	// 	modValue: modValue,
	// 	sectionNumb: sectionNumb  
	//   };	  		  
	//   console.log(dataProperty);
	  
	  var tmpValue = maxValue;
	  for (var i = 0; i < 2 * maxValue; ++i) {
		  if (i >= maxValue) {			  
		   	  sectionProperty[i] = {
			  	maxValue: tmpValue--,
			  	length: sectionNumb
		  	  };  			  
		  } else {
			  sectionProperty[i] = {
			  	maxValue: i+1,
			  	length: sectionNumb
		  	  };  
		  }		  		  
	  }
	  sectionProperty[maxValue-1].length += modValue/2; 
	  sectionProperty[maxValue].length += modValue/2;
	  
	  var tmpIndex = 0;
	  var sectionMinValue = 100;
	  var sectionMaxValue = 0;
	  for (var i = 0; i < 2*maxValue; ++i) {
		  for (var j =0; j < sectionProperty[i].length; ++j) {
			  data[tmpIndex++] = Math.random() +  sectionProperty[i].maxValue - 1;
			  
			  if (data[tmpIndex-1] > sectionMaxValue) {
				  sectionMaxValue = data[tmpIndex-1];
			  }	else if (data[tmpIndex-1] < sectionMinValue) {
				  sectionMinValue = data[tmpIndex-1];
			  }		  
		  }
	  }	  
	 
	 console.log('tmpIndex: ' + tmpIndex.toString() 
	            +'  maxValue: ' + sectionMaxValue.toString()
			    + ' minValue: ' + sectionMinValue.toString());
		 
	  var maxminData = [sectionMaxValue, sectionMinValue];		  		  
		  		
	// 	socket.emit('new data comes', maxminData);
		socket.emit('new data comes', data);
	    }, 1500);
	});
	
});


