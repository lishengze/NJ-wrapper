// 用于自动生成所有的脚本文件;
var exec = require("child_process").exec;
var node = "node ";
var xmlFileName = "apps-xmltojson.js";
var addonFileName = "apps-addon-c.js";
var eventsFileName = "apps-event-js.js";
var apiDataStructFileName = "apps-apiStruct-js.js";
var reqWrapperCFileName = "apps-sua-wrapper-c.js";
var reqWrapperHFileName = "apps-sua-wrapper-h.js";
var sysuserspiCFileName = "apps-sysuserspi-c.js";
var sysuserspiHFileName = "apps-sysuserspi-h.js";
var nanTransDataCFileName = "apps-v8-transform-data-c.js";
var nanTransDataHFileName = "apps-v8-transform-data-h.js";
var nanTransFuncCFileName = "apps-v8-transform-func-c.js";
var nanTransFuncHFileName = "apps-v8-transform-func-h.js";
var fileName = [xmlFileName, addonFileName, eventsFileName, apiDataStructFileName,
								reqWrapperCFileName, reqWrapperHFileName, sysuserspiCFileName, sysuserspiHFileName,
                nanTransDataCFileName, nanTransDataHFileName, nanTransFuncCFileName, nanTransFuncHFileName];
var serverName = process.argv[2];

if (process.argv[3] !== undefined) {
	var desCpDirName = process.argv[3];
} else {
	var desCpDirName = 'lib'
}

// console.log (process.argv) 

exec(node + fileName[0] + ' ' + serverName, function (error, stdout, stderr) {
    console.log('auto stdout: ' + stdout);
    if (error !== null) {
      console.log('auto error: ' + error);
    } else {
			for (var i = 1; i < fileName.length; ++i) {
				exec(node + fileName[i] + ' ' + serverName, function(fileNameIndex){
						return function (error, stdout, stderr) {
							console.log('auto stdout: ' + stdout);
							if (error !== null) {
								console.log('auto error: ' + error);
							} else {
								if (fileNameIndex === fileName.length-1) {
									exec('cp -fr ../new-file/*.cpp ../' + desCpDirName + '/', function(error,stdout, stderr) {
										if (error !== null) {
											console.log('exec error: ' + error);
										} 
									});
									exec('cp -fr ../new-file/*.h ../' + desCpDirName + '/', function(error,stdout, stderr) {
										if (error !== null) {
											console.log('exec error: ' + error);
										} 
									});
								}
							}
						}
				}(i));
			}
		}
});