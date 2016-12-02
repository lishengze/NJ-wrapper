var fs           = require ('fs');
var fileName     = "running-result.txt";
var jsFileName   = "running-result-js.txt";

var g_RspQryMonitorObjectTopic_callbackNumb = 0;
var g_RspQrySysUserLoginTopic_callbackNumb = 0;
var g_RtnObjectAttrTopic_callbackNumb = 0;
var g_RtnMonObjectAttr_callbackNumb = 0;

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

      if (true === this.user.bTestSubscriberData) {
        this.user.userApi.ReqQrySubscriberTopic(this.user.subscriberField, 1)
      }

      if (true === this.user.bTestSubscribe) {
        this.user.userApi.ReqSubscribe(this.user.subscribeField, 1)
      }

      if (true === this.user.bTestMonitor2Object) {
        this.user.userApi.ReqQryMonitor2ObjectTopic(this.user.monitor2ObjectField, 1)
      }

    }

		this.OnRspQryMonitor2ObjectTopic = function (pRspQryMonitor2Object, pRspInfo, nRequestID, bIsLast) {
				g_RspQryMonitorObjectTopic_callbackNumb++;
				var outputStr =  "\n************ JS::OnRspQryMonitorObjectTopic: START! ***********\n";
				if (pRspQryMonitor2Object instanceof Object) {
						outputStr += "ObjectID :               " + pRspQryMonitor2Object.ObjectID.toString() + "\n"
											+ "ObjectName :             " + pRspQryMonitor2Object.ObjectName.toString() + "\n"
											+ "WarningActive :          " + pRspQryMonitor2Object.WarningActive.toString() + "\n";
				} else {
						outputStr += "pRspQryMonitorObject is NULL;\n";
				}
				if (pRspInfo instanceof Object) {
           outputStr += "pRspInfo->ErrorID:          " + pRspInfo.ErrorID.toString() + "\n"
                      + "pRspInfo->ErrorMsg:         " + pRspInfo.ErrorMsg.toString() + "\n"        
        }
		
				outputStr += "bIsLast:                 " + bIsLast.toString() + "\n";
				outputStr += "g_RspQryMonitorObjectTopic_callbackNumb:   " + g_RspQryMonitorObjectTopic_callbackNumb + "\n";
				outputStr += "************ JS::OnRspQryMonitorObjectTopic: END! *********** \n";
		
				fs.appendFile(jsFileName, outputStr, function(err) {
							if (err) {
									console.log(err);
							} 
				});

				// console.log (outputStr);
				if (true === bIsLast) {
				    console.log (outputStr);
				}
		}

    this.OnRspQryMonConfigInfo = function (pRspQryMonConfigInfo, pRspInfo, nRequestID, bIsLast) {
        var outputStr = "\n++++++++++++++++ JS OnRspQryMonConfigInfo: START! ++++++++++++++++++\n";
        if (pRspQryMonConfigInfo instanceof Object) {
          outputStr += "ConfigName :                 " + pRspQryMonConfigInfo.ConfigName.toString() + "\n"                   
                     + "ConfigArg :                  " + pRspQryMonConfigInfo.ConfigArg.toString() + "\n"
                     + "ConfigContent :              " + pRspQryMonConfigInfo.ConfigContent.toString() + "\n"

        } else {
                outputStr += "pRspQryMonConfigInfo is NULL!\n";
        }
        if (pRspInfo instanceof Object) {
           outputStr += "pRspInfo->ErrorID:          " + pRspInfo.ErrorID.toString() + "\n"
                      + "pRspInfo->ErrorMsg:         " + pRspInfo.ErrorMsg.toString() + "\n"        
        }

        outputStr += "bIsLastNew :                " + bIsLast + "\n";
        outputStr += "++++++++++++++++ JS OnRspQryMonConfigInfo: END! ++++++++++++++++++" + "\n";

        fs.appendFile(jsFileName, outputStr, function(err) {
            if (err) {
                console.log(err);
            } 
        });

        console.log(outputStr);
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

exports.Spi = Spi;
