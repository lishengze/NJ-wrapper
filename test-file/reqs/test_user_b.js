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

		User[0] = {};
        User[0].userApi  = new addon.FtdcSysUserApi_Wrapper();
        User[0].Spi      = function() {};

		User[0].userApi.RegisterFront(innerTestSystemPath);
        User[0].userApi.RegisterSpi(new User[0].Spi());
        User[0].userApi.Init();

		User[0].loginField           = new structJs.CShfeFtdcReqQrySysUserLoginField();
		User[0].loginField.UserID    = "NewUserIDI_" + 0;
		User[0].loginField.Password  = "1234567";
		User[0].loginField.VersionID = "2.0.0.0";

		User[0].Spi.prototype.OnFrontConnected = function() {

			console.log('\n++++++++++++ JS FrontConnected START! +++++++++++++');

			console.log("ReqQrySysUserLoginTopic "+ 0 + "  result: "
						+ User[0].userApi.ReqQrySysUserLoginTopic(User[0].loginField , 1) + "\n");
                        
			console.log('++++++++++++ JS FrontConnected END! +++++++++++++\n');
		}

		User[0].SysUserLoginTopicfileName  = "OnRspQrySysUserLoginTopic-JS-Test-CallbackData.txt";
		User[0].SysUserLoginTopicStringData = "";
		User[0].rspQrySysUserLoginTopicCalledTime = 0;
		User[0].Spi.prototype.OnRspQrySysUserLoginTopic = function(pRspQrySysUserLogin,pRspInfo,nRequestID,bIsLast)
		{
				var outputStr = "\n++++++++++++++++ JS OnRspQrySysUserLoginTopic: START! ++++++++++++++++++\n";

				if (pRspQrySysUserLogin instanceof Object) {
					outputStr += "LoginTime :                 " + pRspQrySysUserLogin.LoginTime.toString() + "\n"
							   + "UserID :                    " + pRspQrySysUserLogin.UserID.toString() + "\n"
							   + "Privilege :                 " + pRspQrySysUserLogin.Privilege.toString() + "\n"
							   + "TradingDay :                " + pRspQrySysUserLogin.TradingDay.toString() + "\n"
							   + "VersionFlag :               " + pRspQrySysUserLogin.VersionFlag.toString() + "\n"
							   + "SysUserLoginCalledTime :    " + User[0].rspQrySysUserLoginTopicCalledTime.toString() + "\n";

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
		}
