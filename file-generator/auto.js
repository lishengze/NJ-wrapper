// 用于自动生成所有的脚本文件;
var exec = require("child_process").exec;
var geneOriginData = "node apps-xmltojson.js";
var node = "node ";
var addonFileName = "apps-addon-c.js";
var eventsFileName = "apps-event-js.js";
var reqWrapperCFileName = "apps-sua-wrapper-c.js";
var reqWrapperHFileName = "apps-sua-wrapper-h.js";
var sysuserspiCFileName = "apps-sysuserspi-c.js";
var sysuserspiHFileName = "apps-sysuserspi-h.js";
var nanTransDataCFileName = "apps-v8-transform-data-c.js";
var nanTransDataHFileName = "apps-v8-transform-data-h.js";
var nanTransFuncCFileName = "apps-v8-transform-func-c.js";
var nanTransFuncHFileName = "apps-v8-transform-func-h.js";
var fileName = [addonFileName, eventsFileName,
								reqWrapperCFileName, reqWrapperHFileName, sysuserspiCFileName, sysuserspiHFileName,
                nanTransDataCFileName, nanTransDataHFileName, nanTransFuncCFileName, nanTransFuncHFileName];

exec(geneOriginData, function (error, stdout, stderr) {
    console.log('stdout: ' + stdout);
    if (error !== null) {
      console.log('exec error: ' + error);
    } else {
			for (var i = 0; i < fileName.length; ++i) {
				exec(node + fileName[i], function (error, stdout, stderr) {
					console.log('stdout: ' + stdout);
					if (error !== null) {
						console.log('exec error: ' + error);
					}
				});
			}
		}
});