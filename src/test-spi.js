var fs           = require ('fs');
var fileName     = "running-result.txt";
var jsFileName   = "running-result-js.txt";

var g_RspQryMonitorObjectTopic_callbackNumb = 0;
var g_RspQrySysUserLoginTopic_callbackNumb = 0;
var g_RtnObjectAttrTopic_callbackNumb = 0;
var g_RtnMonObjectAttr_callbackNumb = 0;


var g_MonConfigNumbToStr = [];
var g_MonConfigStrToNumb = []
var g_MonConfigName = [];
var g_MonConfigInfo = [];
var g_IsReqMonConfigEnd = [];
var g_treeViewMonConfigName = ""
var g_treeViewData = "";

function initGlobalPara () {
  g_MonConfigName = ["ObjectIDNS", "DomainNS", "AttrName"];
  g_treeViewMonConfigName = "ObjectIDNS";

  for (var i = 0; i < g_MonConfigName.length; ++i) {
    g_MonConfigNumbToStr[g_MonConfigName[i]] = [];
	g_MonConfigInfo[g_MonConfigName[i]] = ""
	g_IsReqMonConfigEnd[g_MonConfigName[i]] = false
  }
  g_MonConfigStrToNumb = g_MonConfigNumbToStr;
}

initGlobalPara();

var Spi = function(){

    this.user = {};

    this.OnFrontConnected = function() {
			var outputStr = "++++++++++++++++ JS OnFrontConnected! ++++++++++++++++++" + "\n";
			fs.writeFile(jsFileName, outputStr, function(err) {
					if (err) {
							console.log(err);
					} 
			});

      if (true === this.user.bTestSysUserLogin) {
        this.user.userApi.ReqQrySysUserLoginTopic(this.user.sysUserLoginField, 1);
      }      

    }

    this.OnRspQrySysUserLoginTopic = function (pRspQrySysUserLogin, pRspInfo, nRequestID, bIsLast) {
      var outputStr = "\n++++++++++++++++ JS OnRspQrySysUserLoginTopic: START! ++++++++++++++++++\n";
      if (pRspQrySysUserLogin instanceof Object) {
        outputStr += "LoginTime :                 " + pRspQrySysUserLogin.LoginTime.toString() + "\n"
                    + "UserID :                    " + pRspQrySysUserLogin.UserID.toString() + "\n"
                    + "Privilege :                 " + pRspQrySysUserLogin.Privilege.toString() + "\n"
                    + "TradingDay :                " + pRspQrySysUserLogin.TradingDay.toString() + "\n"
                    + "VersionFlag :               " + pRspQrySysUserLogin.VersionFlag.toString() + "\n";

      } else {
              outputStr += "pRspQrySysUserLogin is NULL!\n";
      }
      if (pRspInfo instanceof Object) {
          outputStr += "pRspInfo->ErrorID:          " + pRspInfo.ErrorID.toString() + "\n"
                    + "pRspInfo->ErrorMsg:         " + pRspInfo.ErrorMsg.toString() + "\n"        
      }
      outputStr += "bIsLastNew :                " + bIsLast + "\n";
      outputStr += "++++++++++++++++ JS OnRspQrySysUserLoginTopic: END! ++++++++++++++++++" + "\n\n";

	  fs.appendFileSync(jsFileName, outputStr);
      console.log(outputStr);

      if (true === this.user.bTestMonConfigInfo) {
        this.user.userApi.ReqQryMonConfigInfo(this.user.monConfigInfoField, 1);
      }

      if (true === this.user.bTestSubscribe) {
        this.user.userApi.ReqSubscribe(this.user.subscribeField, 1)
      }

      if (true === this.user.bTestMonitor2Object && false === this.user.bTestMonConfigInfo) {
        this.user.userApi.ReqQryMonitor2ObjectTopic(this.user.monitor2ObjectField, 1)
      }

	  if (true === this.user.bTestSubscriberData) {
        this.user.userApi.ReqQrySubscriberTopic(this.user.subscriberField, 1)
      }

		if (true === this.user.bTestAllMonConfigInfo) {
			for (var i = 0; i < this.user.monConfigInfoFieldArray.length; ++i) {
				this.user.userApi.ReqQryMonConfigInfo(this.user.monConfigInfoFieldArray[i], 1);
			}
		}

    }

    this.OnRspQryMonConfigInfo = function (pRspQryMonConfigInfo, pRspInfo, nRequestID, bIsLast) {
        var outputStr = "\n++++++++++++++++ JS OnRspQryMonConfigInfo: START! ++++++++++++++++++\n";
        if (pRspQryMonConfigInfo instanceof Object) {
          outputStr += "ConfigName :                 " + pRspQryMonConfigInfo.ConfigName.toString() + "\n"                   
                     + "ConfigArg :                  " + pRspQryMonConfigInfo.ConfigArg.toString() + "\n"
                     + "ConfigContent :              " + pRspQryMonConfigInfo.ConfigContent.toString() + "\n"

			if (undefined !== g_MonConfigInfo[pRspQryMonConfigInfo.ConfigName]) {
				g_MonConfigInfo[pRspQryMonConfigInfo.ConfigName] += pRspQryMonConfigInfo.ConfigContent;
				g_IsReqMonConfigEnd[pRspQryMonConfigInfo.ConfigName] = bIsLast;
				var isAllRspEnd = true;
				for (var ConfigName in g_IsReqMonConfigEnd) {
					if (!g_IsReqMonConfigEnd[ConfigName]) {
						isAllRspEnd = false;break;
					}
				}
				if (bIsLast) {
					console.log (pRspQryMonConfigInfo.ConfigName + ' is end!');
				}
				if (isAllRspEnd) {
					for (var ConfigName in g_IsReqMonConfigEnd) {
						var outputData = "------------------ "+ ConfigName + " Data START!-----------------\n"
											+ g_MonConfigInfo[ConfigName] 
										 + "------------------ "+ ConfigName + " Data END!-----------------\n";
						fs.appendFileSync(jsFileName, outputData);
						g_MonConfigNumbToStr[ConfigName] = processMonConfigInfoData (g_MonConfigInfo[ConfigName]);						
					}

					setMonConfigStrToNumbData();
					outputMsg('g_MonConfigNumbToStr', g_MonConfigNumbToStr);
					outputMsg('g_MonConfigStrToNumb', g_MonConfigStrToNumb);

					if (true === this.user.bTestMonitor2Object) {
						this.user.userApi.ReqQryMonitor2ObjectTopic(this.user.monitor2ObjectField, 1)
					}
				}
			}
        } else {
                outputStr += "pRspQryMonConfigInfo is NULL!\n";
        }
        if (pRspInfo instanceof Object) {
           outputStr += "pRspInfo->ErrorID:          " + pRspInfo.ErrorID.toString() + "\n"
                      + "pRspInfo->ErrorMsg:         " + pRspInfo.ErrorMsg.toString() + "\n"        
        }				
        outputStr += "bIsLastNew :                " + bIsLast + "\n";
        outputStr += "++++++++++++++++ JS OnRspQryMonConfigInfo: END! ++++++++++++++++++" + "\n";

        // console.log(outputStr);
    }

	this.OnRspQryMonitor2ObjectTopic = function (pRspQryMonitor2Object, pRspInfo, nRequestID, bIsLast) {
			g_RspQryMonitorObjectTopic_callbackNumb++;
			var outputStr =  "\n************ JS::OnRspQryMonitor2ObjectTopic: START! ***********\n";
			if (pRspQryMonitor2Object instanceof Object) {
					outputStr += "ObjectID :               " + pRspQryMonitor2Object.ObjectID.toString() + "\n"
										+ "ObjectName :             " + pRspQryMonitor2Object.ObjectName.toString() + "\n"
										+ "WarningActive :          " + pRspQryMonitor2Object.WarningActive.toString() + "\n";
				if (this.user.bTestAllMonConfigInfo) {
						outputStr += "TransObjectID:           " + g_MonConfigNumbToStr["ObjectIDNS"][pRspQryMonitor2Object.ObjectID] + "\n"
						g_treeViewData += pRspQryMonitor2Object.ObjectID + ': ' + g_MonConfigNumbToStr["ObjectIDNS"][pRspQryMonitor2Object.ObjectID] + "\n";					
						pRspQryMonitor2Object.ObjectID = g_MonConfigNumbToStr["ObjectIDNS"][pRspQryMonitor2Object.ObjectID];
						saveTreeViewData (pRspQryMonitor2Object, bIsLast);
				}
			} else {
					outputStr += "pRspQryMonitorObject is NULL;\n";
			}
			if (pRspInfo instanceof Object) {
				outputStr += "pRspInfo->ErrorID:          " + pRspInfo.ErrorID.toString() + "\n"
					+ "pRspInfo->ErrorMsg:         " + pRspInfo.ErrorMsg.toString() + "\n"        
			}				
	
			outputStr += "bIsLast:                 " + bIsLast.toString() + "\n";
			outputStr += "g_RspQryMonitorObjectTopic_callbackNumb:   " + g_RspQryMonitorObjectTopic_callbackNumb + "\n";
			outputStr += "************ JS::OnRspQryMonitor2ObjectTopic: END! *********** \n";
			fs.appendFileSync(jsFileName, outputStr);

			console.log (outputStr);
			if (true === bIsLast) {
				// if (this.user.bTestAllMonConfigInfo) console.log (g_treeViewData);
			}
	}

	this.OnRtnMonObjectAttr = function (pRtnMonObjectAttr) {
				var outputStr = "\n************ JS::OnRtnMonObjectAttr: START! ***********\n";
				++g_RtnMonObjectAttr_callbackNumb;
				if (pRtnMonObjectAttr instanceof Object) {
						outputStr +=  "ObjectID:                " + pRtnMonObjectAttr.ObjectID + "\n"
												+ "AttrType:                " + pRtnMonObjectAttr.AttrType + "\n"
												+ "MonTime:                 " + pRtnMonObjectAttr.MonTime + "\n"
												+ "ValueType:               " + pRtnMonObjectAttr.ValueType + "\n"
												+ "AttrValue:               " + pRtnMonObjectAttr.AttrValue + "\n"
				} else {
						outputStr += "pRtnMonObjectAttr:          NULL!\n";
				}
				outputStr += "g_RtnMonObjectAttr_callbackNumb:   " + g_RtnMonObjectAttr_callbackNumb + "\n";
				outputStr += "************ JS::OnRtnMonObjectAttr: END! *********** \n";

				console.log(outputStr);
				fs.appendFile(jsFileName, outputStr, function(err) {
							if (err) {
									console.log(err);
							} 
				});        
	}

	this.OnRtnObjectAttrTopic = function (pRtnObjectAttr) {
			var outputStr = "\n************ JS::OnRtnObjectAttrTopic: START! ***********\n";
			++g_RtnObjectAttrTopic_callbackNumb;
			if (pRtnObjectAttr instanceof Object) {
					outputStr +=  "ObjectID:                " + pRtnObjectAttr.ObjectID + "\n"
											+ "AttrType:                " + pRtnObjectAttr.AttrType + "\n"
											+ "MonDate:                 " + pRtnObjectAttr.MonDate + "\n"
											+ "MonTime:                 " + pRtnObjectAttr.MonTime + "\n"
											+ "ValueType:               " + pRtnObjectAttr.ValueType + "\n"
											+ "AttrValue:               " + pRtnObjectAttr.AttrValue + "\n"
			} else {
					outputStr += "pRtnObjectAttr:          NULL!\n";
			}
			outputStr += "g_RtnObjectAttrTopic_callbackNumb:   " + g_RtnObjectAttrTopic_callbackNumb + "\n";
			outputStr += "************ JS::OnRtnObjectAttrTopic: END! *********** \n";

			console.log(outputStr);
			fs.appendFile(jsFileName, outputStr, function(err) {
						if (err) {
								console.log(err);
						} 
			});        
	}

    // this.OnRspQryMonConfigInfo = function (pRspQryMonConfigInfo, pRspInfo, nRequestID, bIsLast) {
    //     var outputStr = "\n++++++++++++++++ JS OnRspQryMonConfigInfo: START! ++++++++++++++++++\n";
    //     if (pRspQryMonConfigInfo instanceof Object) {
    //       outputStr += "ConfigName :                 " + pRspQryMonConfigInfo.ConfigName.toString() + "\n"                   
    //                  + "ConfigArg :                  " + pRspQryMonConfigInfo.ConfigArg.toString() + "\n"
    //                  + "ConfigContent :              " + pRspQryMonConfigInfo.ConfigContent.toString() + "\n"

		// 			if (undefined !== g_MonConfigInfo[pRspQryMonConfigInfo.ConfigName]) {
		// 				g_MonConfigInfo[pRspQryMonConfigInfo.ConfigName] += pRspQryMonConfigInfo.ConfigContent;
		// 				if (bIsLast) {
		// 					var outputData = "\n------------------ "+ pRspQryMonConfigInfo.ConfigName + " Data START!-----------------\n"
		// 													+ g_MonConfigInfo[pRspQryMonConfigInfo.ConfigName] 
		// 													+ "------------------ "+ pRspQryMonConfigInfo.ConfigName + " Data END!-----------------\n";

		// 					g_MonConfigNumbToStr[pRspQryMonConfigInfo.ConfigName] = processMonConfigInfoData (g_MonConfigInfo[pRspQryMonConfigInfo.ConfigName]);
		// 					fs.appendFileSync(jsFileName, outputData);
		// 				}
		// 			}

    //     } else {
    //             outputStr += "pRspQryMonConfigInfo is NULL!\n";
    //     }
    //     if (pRspInfo instanceof Object) {
    //        outputStr += "pRspInfo->ErrorID:          " + pRspInfo.ErrorID.toString() + "\n"
    //                   + "pRspInfo->ErrorMsg:         " + pRspInfo.ErrorMsg.toString() + "\n"        
    //     }				
    //     outputStr += "bIsLastNew :                " + bIsLast + "\n";
    //     outputStr += "++++++++++++++++ JS OnRspQryMonConfigInfo: END! ++++++++++++++++++" + "\n";
    //     // fs.appendFile(jsFileName, outputStr, function(err) {
    //     //     if (err) {
    //     //         console.log(err);
    //     //     } 
    //     // });

    //     console.log(outputStr);
    // }
	
};

var g_saveTreeDataFlag = true;
var treeViewFileName = "./treeViewData.json";

function outputMsg(description, info) {
	// console.log(description);
	fs.appendFileSync(jsFileName, description + ': ');
	if (typeof(info) === 'object') {
		fs.appendFileSync(jsFileName, '\n')
		for (var key in info) {
			outputMsg(key, info[key])
		}
	} else {
		fs.appendFileSync(jsFileName, info + '\n')
	}

	// console.log(info);
	// console.log('')
}

function setMonConfigStrToNumbData () {
  for (var i = 0; i < g_MonConfigName.length; ++i) {
    var curMonConfigName = g_MonConfigName[i];
    var tmpData = g_MonConfigNumbToStr[curMonConfigName]
    for (var numb in tmpData) {
      g_MonConfigStrToNumb[curMonConfigName][tmpData[numb]] = numb;
    }    
  }
}

function saveTreeViewData (data, bIsLast) {
	var outputData = "";
	var tabSpace = ["", "  ", "    ", "      "];
	if (g_saveTreeDataFlag) {
		outputData += tabSpace[0] + "{ \n"
								+ tabSpace[1] + "\"rspData\": [ \n";
		g_saveTreeDataFlag = false;
	}

	if (data instanceof Object) {
		outputData += tabSpace[2] + "{\n"
								+ tabSpace[3] + "\"ObjectID\": \"" + data.ObjectID + "\",\n"
								+ tabSpace[3] + "\"ObjectName\": \"" + data.ObjectName + "\",\n"
								+ tabSpace[3] + "\"WarningActive\": \"" + data.WarningActive + "\"\n"
							  + tabSpace[2] + "}";
		if (!bIsLast) {
			outputData += ",";
		} 
		outputData += "\n";

	}

	if (bIsLast) {
		outputData += tabSpace[1] + "] \n"
								+ tabSpace[0] + "}\n"
	}
	fs.appendFileSync(treeViewFileName, outputData);
}

function OutputFunc(data) {
	for (configName in data) {
		for (value in data[configName]) {
			console.log (value + ": " + data[configName][value]);
		}
	}
}

function processMonConfigInfoData (originData) {
	var tmpData = originData.split("\n");
    var numberStringIndex = getTransDataIndex(tmpData);	
	var transData = [];

	// console.log (tmpData);
	console.log (numberStringIndex);
	for (var i = 0; i < tmpData.length; ++i) {
		tmpData[i] = tmpData[i].split(",");
		if (tmpData[i].length === 2) {
			transData[tmpData[i][numberStringIndex.numberIndex]] = tmpData[i][numberStringIndex.stringIndex].replace(' ','');
			// console.log (tmpData[i][numberStringIndex.numberIndex] + ': ' + transData[tmpData[i][numberStringIndex.numberIndex]]);			
		}
	}

	// console.log (transData);
	return transData;
}

function getTransDataIndex (originData) {
	var indexData = {};
	for (var i = 0; i < originData.length; ++i) {
		var testData = originData[i].split(",");
		if (testData.length === 2) {
			if (isNumber(testData[0])) {
				indexData.numberIndex = 0;
				indexData.stringIndex = 1;
			} else {
				indexData.numberIndex = 1;
				indexData.stringIndex = 0;
			}
			break;
		}
		
	}
	// console.log (indexData);
	return indexData;
}

function isNumber (value) {
	var valueArray = value.split('');
	var numbArray = ['0','1', '2', '3', '4', '5', '6', '7', '8', '9'];
	var isNumb;
	for (var i = 0; i < valueArray.length; ++i) {
		isNumb = false; 
		for (var j = 0; j < numbArray.length; ++j) {
			if (valueArray[i].toString() == numbArray[j].toString()){
				isNumb = true;
				break;
			} 			
		}
		if (!isNumb) {return isNumb;}
	}
	return isNumb;
}

exports.Spi = Spi;
