var path     = require('path')
var spawn    = require('child_process').spawn;

var rspUserLoginCallNumb  = 1;
var rspMonitorObjCallNumb = 0;
var rtnObjectAttrCallNumb = 0;

var Spi = function(){
    
    this.user = {};    
    
    this.HelloSpi = function() {
        console.log("Hello Spi: " + this.user);
    }
    
    this.OnFrontConnected = function() {	

            var outputStr = '\n++++++++++++ JS FrontConnected START! +++++++++++++\n';               
            
            outputStr += '\nUserID:                   ' + this.user.loginField[0].UserID + "\n\n";

            for (var i = 0; i < this.user.loginReqNumbers; ++i) {                    
                console.log("ReqQrySysUserLoginTopic "+ i + "  result:" 
                                    + this.user.userApi.ReqQrySysUserLoginTopic(this.user.loginField[i], 1) + "\n");			
            }	   
                             
                                             
            outputStr += '++++++++++++ JS FrontConnected END! +++++++++++++\n';         
            console.log(outputStr);       
    }        
    
    this.OnRspQrySysUserLoginTopic = function(pRspQrySysUserLogin,pRspInfo,nRequestID,bIsLast) {
         var outputStr = "\n++++++++++++++++ JS OnRspQrySysUserLoginTopic: START! ++++++++++++++++++\n";
         outputStr += 'UserID:                     ' + this.user.loginField[0].UserID + "\n";
			 	if (pRspQrySysUserLogin instanceof Object) {
		      outputStr += "LoginTime :                 " + pRspQrySysUserLogin.LoginTime.toString() + "\n"
					           + "UserID :                    " + pRspQrySysUserLogin.UserID.toString() + "\n"
					           + "Privilege :                 " + pRspQrySysUserLogin.Privilege.toString() + "\n"
					           + "TradingDay :                " + pRspQrySysUserLogin.TradingDay.toString() + "\n"
					           + "VersionFlag :               " + pRspQrySysUserLogin.VersionFlag.toString() + "\n";	
					
				} else {
		            outputStr += "pRspQrySysUserLogin is NULL!\n";
		    }        

            for (var i = 0; i < this.user.ReqQrySubscriberNumbers; ++i) {                    
                console.log("ReqQrySubscriberTopic "+ i + "  result:" 
                             + this.user.userApi.ReqQrySubscriberTopic(this.user.reqQrySubscriberData, 1) + "\n");			
            }		
		        
            for (var i = 0; i < this.user.monitorObjectReqNumbers; ++i) {                    
                console.log("ReqQryMonitorObjectTopic "+ i + "  result:" 
                             + this.user.userApi.ReqQryMonitorObjectTopic(this.user.monitorObjectField, 1) + "\n");			
            }	

            outputStr += "bIsLastNew :                " + bIsLast + "\n";
            outputStr += "rspCallNumb:                " + rspUserLoginCallNumb + "\n";
            outputStr += "++++++++++++++++ JS OnRspQrySysUserLoginTopic: END! ++++++++++++++++++" + "\n";        
            rspUserLoginCallNumb++;
            console.log(outputStr);       
	}
    
    this.OnRspQryMonitorObjectTopic = function (pRspQryMonitorObject, pRspInfo, nRequestID, bIsLast) {
        rspMonitorObjCallNumb++;
        var outputStr =  "\n************ JS::OnRspQryMonitorObjectTopic: START! ***********\n";	
        outputStr += 'UserID:                  ' + this.user.loginField[0].UserID + "\n";
        if (pRspQryMonitorObject instanceof Object) {		
            outputStr += "ObjectID :               " + pRspQryMonitorObject.ObjectID.toString() + "\n" 
                       + "ObjectName :             " + pRspQryMonitorObject.ObjectName.toString() + "\n"  
                       + "WarningActive :          " + pRspQryMonitorObject.WarningActive.toString() + "\n";							                                                
        } else {
            outputStr += "pRspQryMonitorObject is NULL;\n";
        }
        
        outputStr += "bIsLast:                 " + bIsLast.toString() + "\n";
        outputStr += "rspMonitorObjCallNumb:   " + rspMonitorObjCallNumb + "\n";
        outputStr += "************ JS::OnRspQryMonitorObjectTopic: END! *********** \n";

        if (bIsLast === true) {
            console.log (outputStr);
        }
         
    }

    this.OnRspQrySysUserRegisterTopic = function (pRspQrySysUserRegister, pRspInfo, nRequestID, bIsLast) {
        var outputStr = "\n************ JS::OnRspQrySysUserRegisterTopic: START! ***********\n";    
        
        if (pRspQrySysUserRegister instanceof Object) {
            outputStr += "UserID:                               " + pRspQrySysUserRegister.UserID.toString() + "\n"
                       + "Privilege:                            " + pRspQrySysUserRegister.Privilege.toString() + "\n";
        } else {
            outputStr += "pRspQrySysUserRegister is NULL!\n";    
        }
        
        outputStr += "bIsLast in JS is:                     " + bIsLast.toString() + "\n";
        outputStr += "************ JS::OnRspQrySysUserRegisterTopic: END! ***********\n"
        
        console.log(outputStr);
        this.OnRspQrySysUserRegisterTopicCallTime++;        
        
    }

    // 订阅RtnObjectAttrTopic;
    this.OnRtnObjectAttrTopic = function (pRtnObjectAttr) {
        var outputStr = "\n************ JS::OnRtnObjectAttrTopic: START! ***********\n";
        ++rtnObjectAttrCallNumb;
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
        outputStr += "rtnObjectAttrCallNumb:   " + rtnObjectAttrCallNumb + "\n";
        outputStr += "************ JS::OnRtnObjectAttrTopic: END! *********** \n";    

        console.log(outputStr);
    }
};
    
exports.Spi = Spi;




