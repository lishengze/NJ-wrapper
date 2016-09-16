var addon    = require("./build/Release/addon");
var structJs = require("./SysUserApiStruct_JS.js");
var fs       = require('fs');
var path     = require('path')
var spawn    = require('child_process').spawn;

var realTimeSystemPath  = "tcp://172.1.128.165:18841";
var innerTestSystemPath = "tcp://172.1.128.111:18842";

var loginReqNumbers  = 1;
var nRequestID       = 1;

var User = [];
// Register Callback Info.
for (var i = 0; i < loginReqNumbers; ++i) {
	
    User[i] = {};
	User[i].userApi  = new addon.FtdcSysUserApi_Wrapper();
	User[i].Spi      = function(){};

	User[i].loginField           = new structJs.CShfeFtdcReqQrySysUserLoginField();
    User[i].loginField.UserID    = "NewUserIDI_" + i;
    User[i].loginField.Password  = "1234567";
    User[i].loginField.VersionID = "2.0.0.0";   
 	
	User[i].Spi.prototype.OnFrontConnected = function() {
	
		console.log('\n++++++++++++ JS FrontConnected START! +++++++++++++');    
	
        console.log("i: " + i);
        sleep(1);
		console.log("ReqQrySysUserLoginTopic "+ i + "  result:" 
					+ User[i].userApi.ReqQrySysUserLoginTopic(User[i].loginField , 1) + "\n");				
				
		console.log('++++++++++++ JS FrontConnected END! +++++++++++++\n'); 
	}
	
	User[i].SysUserLoginTopicfileName  = "OnRspQrySysUserLoginTopic-JS-Test-CallbackData.txt";
	User[i].SysUserLoginTopicStringData = "";
	User[i].rspQrySysUserLoginTopicCalledTime = 0;
	User[i].Spi.prototype.OnRspQrySysUserLoginTopic = function(pRspQrySysUserLogin,pRspInfo,nRequestID,bIsLast)
	{
			var outputStr = "";
			outputStr += "\n++++++++++++++++ JS OnRspQrySysUserLoginTopic: START! ++++++++++++++++++\n";
	
			if (pRspQrySysUserLogin instanceof Object) {
				outputStr += "LoginTime :                 " + pRspQrySysUserLogin.LoginTime.toString() + "\n"
				    	   + "UserID :                    " + pRspQrySysUserLogin.UserID.toString() + "\n"
						   + "Privilege :                 " + pRspQrySysUserLogin.Privilege.toString() + "\n"
						   + "TradingDay :                " + pRspQrySysUserLogin.TradingDay.toString() + "\n"
						   + "VersionFlag :               " + pRspQrySysUserLogin.VersionFlag.toString() + "\n"	
						   + "SysUserLoginCalledTime :    " + User[i].rspQrySysUserLoginTopicCalledTime.toString() + "\n";	
				
			} else {
				outputStr += "pRspQrySysUserLogin is NULL!\n";
			}
			
			outputStr += "bIsLastNew :               " + bIsLast + "\n";
			outputStr += "++++++++++++++++ JS OnRspQrySysUserLoginTopic: END! ++++++++++++++++++" + "\n"
			console.log(outputStr);
			
            var dir = path.join('/proc',process.pid.toString(),'task');
            var ls = spawn('ls', [dir]);
                ls.stdout.on('data', function(data){
                console.log('Time:'+Date.now()+'\nthreads:\n'+data);
            });
            
			// SysUserLoginTopicStringData += outputStr;
			
			// if (true === bIsLast) {
			// 	fs.writeFile(pathName + SysUserLoginTopicfileName, SysUserLoginTopicStringData, function(err) {
			// 		if (err) {
			// 			console.log(err);
			// 		} else {
			// 			console.log('Succeed in saving ' + pathName + SysUserLoginTopicfileName);
			// 		}	
			// 	});						
			// 	ReqQrySysUserLoginTopicCallbackData = [];		
			// }
	}
}

for (var i = 0; i < loginReqNumbers; ++i) {    
 	User[i].userApi.RegisterFront(innerTestSystemPath);   
    User[i].userApi.RegisterSpi(new User[i].Spi());
    User[i].userApi.Init();       
}

function sleep(sleepTime) {
       for(var start = Date.now(); Date.now() - start <= sleepTime; ) { } 
}

// var interval = setInterval(function() {
// 	var dir = path.join('/proc',process.pid.toString(),'task');
// 	var ls = spawn('ls', [dir]);
// 	ls.stdout.on('data', function(data){
// 	  console.log('Time:'+Date.now()+'\nthreads:\n'+data);
// 	});
// }, 500);



