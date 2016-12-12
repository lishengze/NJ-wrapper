var fs           = require ('fs');
var fileName     = "running-result.txt";
var jsFileName   = "running-result-js.txt";

var g_RspQryMonitorObjectTopic_callbackNumb = 0;
var g_RspQrySysUserLoginTopic_callbackNumb = 0;
var g_RtnObjectAttrTopic_callbackNumb = 0;
var g_RtnMonObjectAttr_callbackNumb = 0;
var g_MonConfigInfo = [];
g_MonConfigInfo["ObjectIDNS"] = "";
g_MonConfigInfo["DomainNS"] = "";
g_MonConfigInfo["AttrName"] = "";
var g_treeViewMapDara;
var g_treeViewData="";

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
      outputStr += "++++++++++++++++ JS OnRspQrySysUserLoginTopic: END! ++++++++++++++++++" + "\n";

      fs.appendFile(jsFileName, outputStr, function(err) {
          if (err) {
              console.log(err);
          } 
      });
      console.log(outputStr);

      if (true === this.user.bTestMonConfigInfo) {
        this.user.userApi.ReqQryMonConfigInfo(this.user.monConfigInfoField, 1);
      }

      if (true === this.user.bTestSubscribe) {
        this.user.userApi.ReqSubscribe(this.user.subscribeField, 1)
      }

      // if (true === this.user.bTestMonitor2Object) {
      //   this.user.userApi.ReqQryMonitor2ObjectTopic(this.user.monitor2ObjectField, 1)
      // }

			if (true === this.user.bTestSubscriberData) {
        this.user.userApi.ReqQrySubscriberTopic(this.user.subscriberField, 1)
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
						if (true === bIsLast) {
							var outputData = "------------------ "+ pRspQryMonConfigInfo.ConfigName + " Data START!-----------------\n"
							               + g_MonConfigInfo[pRspQryMonConfigInfo.ConfigName] 
														 + "------------------ "+ pRspQryMonConfigInfo.ConfigName + " Data END!-----------------\n";
							
							fs.appendFile(jsFileName, outputData, function(err) {
								if (err) {
										console.log(err);
								} 
        			});

							g_treeViewMapDara = processMonConfigInfoData (g_MonConfigInfo[pRspQryMonConfigInfo.ConfigName]);
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
        // fs.appendFile(jsFileName, outputStr, function(err) {
        //     if (err) {
        //         console.log(err);
        //     } 
        // });

        // console.log(outputStr);
    }

		this.OnRspQryMonitor2ObjectTopic = function (pRspQryMonitor2Object, pRspInfo, nRequestID, bIsLast) {
				g_RspQryMonitorObjectTopic_callbackNumb++;
				var outputStr =  "\n************ JS::OnRspQryMonitor2ObjectTopic: START! ***********\n";
				if (pRspQryMonitor2Object instanceof Object) {
						outputStr += "ObjectID :               " + pRspQryMonitor2Object.ObjectID.toString() + "\n"
											+ "ObjectName :             " + pRspQryMonitor2Object.ObjectName.toString() + "\n"
											+ "WarningActive :          " + pRspQryMonitor2Object.WarningActive.toString() + "\n";
						g_treeViewData += pRspQryMonitor2Object.ObjectID + ': ' + g_treeViewMapDara[pRspQryMonitor2Object.ObjectID] + "\n";
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
		
				fs.appendFile(jsFileName, outputStr, function(err) {
							if (err) {
									console.log(err);
							} 
				});

				console.log (outputStr);
				if (true === bIsLast) {
				    console.log (g_treeViewData);
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
};

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
