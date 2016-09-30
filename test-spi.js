var spawn        = require('child_process').spawn;
var fs           = require ('fs');
var path         = require ('path');

var g_RspQrySysUserLoginTopic_spi_callbackNumb = 0;
var g_RspQryNetMonitorAttrScopeTopic_spi_callbackNumb = 0;
var g_RspQryMonitorObjectTopic_spi_callbackNumb = 0;
var g_RtnObjectAttrTopic_spi_callbackNumb = 0;

var g_output_info = "";
var g_startTime = 0;
var g_endTime = 0;

var g_testTimeIndex = 4;
var g_sec_array = [1,5,30,60,60,60,60];
var g_min_array = [1,1,1, 1, 5, 30,60];
var g_sec = g_sec_array[g_testTimeIndex];
var g_min = g_min_array[g_testTimeIndex];
var g_stopusec = g_sec * g_min * 1000;
var g_test_rtn_time_numb = 7;

var g_reqNumb = 1;
var g_rtn_over = false;

var g_sec_rtnSendNumber = 100;
var g_sec_rtnSendFreq = 1000;
var g_rtn_callback_onesec = g_sec_rtnSendNumber * g_sec_rtnSendFreq;

var g_test_rsp_monitor_numb = 5;
var g_reqMonitor_number_array = [300, 600, 900, 1200, 1500];
var g_test_rsp_monitor_numb_index = 0;
var g_ReqQryMonitorObjectTopic_Numb = g_reqMonitor_number_array[0] * (g_stopusec/1000);
var g_monitor_callback_sumNumber = g_ReqQryMonitorObjectTopic_Numb * 633;
var g_RspMonitor_Over = false;

var g_isTestTtn = true;
var g_isTestReqMonitor = false;

var g_curDate = "";
var g_stop = false;
var g_isFirstCallback = true;

if (true === g_isTestTtn)
{
  var testfileName = path.join (__dirname, './test-com-redhat-js-Rtn-'+g_rtn_callback_onesec+'.txt');
}
if (true === g_isTestReqMonitor)
{
  var testfileName = path.join (__dirname, './test-com-redhat-js-monitor.txt');
}

var GetCurrTime = function() {
  myDate = new Date()
  return myDate;
}

var resetReqQrySubscriber = function() {
  if (g_reqNumb ==  6)
  {
    g_testTimeIndex++;

    if (g_testTimeIndex >= g_test_rtn_time_numb)
    {
      process.exit(0);
    }

    g_sec = g_sec_array[g_testTimeIndex];
    g_min = g_min_array[g_testTimeIndex];
    g_stopusec = g_sec * g_min * 1000;

    g_output_info = "\n----------- Reset Test Time! -----------" + '\n';
    g_output_info += "g_sec: " + g_sec + "    ";
    g_output_info += "g_min: " + g_min + '\n';
    g_output_info += "g_testTimeIndex:  " + g_testTimeIndex + '\n';

    fs.appendFileSync(testfileName, g_output_info);
    console.log (g_output_info);
    g_reqNumb = 1;
  }

  g_curDate = GetCurrTime();
  g_startTime = g_curDate.getTime();
  g_output_info = '\n' + 'StartTime:    ' + g_curDate + '\n';
  fs.appendFileSync (testfileName,  g_output_info);
  console.log (g_output_info);

  g_rtn_over = false;
  g_RtnObjectAttrTopic_spi_callbackNumb = 0;
}

var Spi = function(){

    this.user = {};
    this.TestReqQryMonitorObjectTopic = function(reqNumber)
    {
      for (var i = 0; i < reqNumber; ++i)
      {
        this.user.userApi.ReqQryMonitorObjectTopic(this.user.monitorObjectField, 1)
      }
    }

    this.TestReqQrySubscriberTopic = function(reqNumber)
    {
      for (var i = 0; i < reqNumber; ++i)
      {
        this.user.userApi.ReqQrySubscriberTopic(this.user.reqQrySubscriberData, 1)
      }
    }

    this.HelloSpi = function()
    {
        console.log("Hello Spi: " + this.user);
    }

    this.OnFrontConnected = function()
    {
      if (true === g_isTestTtn)
      {
        var testfileName = path.join (__dirname, './test-com-redhat-js-Rtn-'+g_rtn_callback_onesec+'.txt');
        this.TestReqQrySubscriberTopic(1);
      }

      if (true === g_isTestReqMonitor)
      {
        var testfileName = path.join (__dirname, './test-com-redhat-js-monitor.txt');
        this.TestReqQryMonitorObjectTopic(g_ReqQryMonitorObjectTopic_Numb);
        // this.TestReqQryMonitorObjectTopic(1);
      }
    }

    this.OnRspQryMonitorObjectTopic = function (pRspQryMonitorObject, pRspInfo, nRequestID, bIsLast)
    {
      ++g_RspQryMonitorObjectTopic_spi_callbackNumb;
      g_endTime = GetCurrTime().getTime();

      if (true == g_isFirstCallback)
      {
        g_startTime = GetCurrTime().getTime();
        g_output_info = "********* Test ReqQryMonitorObjectTopic ************" + '\n'
                      + "g_monitor_callback_sumNumber:       " + g_monitor_callback_sumNumber + '\n\n'
                      + "StartTime:     " + GetCurrTime() + '\n';
        fs.appendFileSync (testfileName, g_output_info); console.log (g_output_info);

        g_isFirstCallback = false;
      }

      if (g_RspQryMonitorObjectTopic_spi_callbackNumb == g_monitor_callback_sumNumber)
      {
        var  costTime = g_endTime - g_startTime;
        var  dataSize = 197;
        g_output_info = "CostTime:      " + costTime/1000 + "s" + '\n'
                      + "SumCallbkNumb: " + g_RspQryMonitorObjectTopic_spi_callbackNumb + '\n'
                      + "AevCallbkNumb: " + g_RspQryMonitorObjectTopic_spi_callbackNumb / (costTime/1000) + '\n'
                      + "Bandwidth:     " + dataSize * g_RspQryMonitorObjectTopic_spi_callbackNumb / (costTime/1000) / 1024 / 1024 +" MB/S" + '\n'
                      + "EndTime:       " + GetCurrTime() + '\n';
        fs.appendFileSync (testfileName, g_output_info + '\n');console.log (g_output_info);

        if (g_test_rsp_monitor_numb_index === g_test_rsp_monitor_numb-1) process.exit(0);

        g_ReqQryMonitorObjectTopic_Numb = g_reqMonitor_number_array[++g_test_rsp_monitor_numb_index];
        g_monitor_callback_sumNumber = g_ReqQryMonitorObjectTopic_Numb * 633;
        this.TestReqQryMonitorObjectTopic(g_ReqQryMonitorObjectTopic_Numb);
        g_isFirstCallback = true;
        g_RspQryMonitorObjectTopic_spi_callbackNumb = 0;
      }
    }

    // this.OnRspQryMonitorObjectTopic = function (pRspQryMonitorObject, pRspInfo, nRequestID, bIsLast)
    // {
    //     g_RspQryMonitorObjectTopic_spi_callbackNumb++;
    //     var outputStr =  "\n************ JS::OnRspQryMonitorObjectTopic: START! ***********\n";
    //     outputStr += 'UserID:                  ' + this.user.loginField.UserID + "\n";
    //     if (pRspQryMonitorObject instanceof Object) {
    //         outputStr += "ObjectID :               " + pRspQryMonitorObject.ObjectID.toString() + "\n"
    //                    + "ObjectName :             " + pRspQryMonitorObject.ObjectName.toString() + "\n"
    //                    + "WarningActive :          " + pRspQryMonitorObject.WarningActive.toString() + "\n";
    //     } else {
    //         outputStr += "pRspQryMonitorObject is NULL;\n";
    //     }
    //
    //     outputStr += "bIsLast:                 " + bIsLast.toString() + "\n";
    //     outputStr += "g_RspQryMonitorObjectTopic_spi_callbackNumb:   " + g_RspQryMonitorObjectTopic_spi_callbackNumb + "\n";
    //     outputStr += "************ JS::OnRspQryMonitorObjectTopic: END! *********** \n";
    //
    //     if (bIsLast === true) {
    //         console.log (outputStr);
    //     }
    // }

    this.OnRtnObjectAttrTopic = function (pRtnObjectAttr)
    {
      if (true == g_isFirstCallback)
      {
        g_startTime = GetCurrTime().getTime();
        g_output_info = "********* Test RtnObjectAttrTopic ************" + '\n'
                      + "g_rtn_callback_onesec: " + g_rtn_callback_onesec + '\n'
                      + "g_sec: " + g_sec + "       g_min: " + g_min + "\n\n"
                      + "StartTime:     " + GetCurrTime() + '\n';
        fs.appendFileSync (testfileName, g_output_info); console.log (g_output_info);

        g_isFirstCallback = false;
      }

      if (g_rtn_over === true) return

      ++g_RtnObjectAttrTopic_spi_callbackNumb;
      g_curDate = GetCurrTime();
      if ((g_curDate.getTime() - g_startTime) > g_stopusec)
      {
        g_output_info =  'TestTime :     ' + g_stopusec/1000 + 's\n'
        g_output_info += 'SumCallbkNumb: ' + g_RtnObjectAttrTopic_spi_callbackNumb + '\n'
        g_output_info += 'AveCallbkNumb: ' + g_RtnObjectAttrTopic_spi_callbackNumb / (g_stopusec/1000) + '\n'
        g_output_info += 'BandWidth:     ' + g_RtnObjectAttrTopic_spi_callbackNumb * 432 / g_stopusec * 1000 / 1024/1024 + 'M/s\n'
        g_output_info += 'g_reqNumb:     ' + g_reqNumb++ + '\n';
        g_output_info += 'EndTime:       ' + g_curDate + '\n';

        fs.appendFileSync (testfileName, g_output_info + '\n');console.log (g_output_info);

        g_rtn_over = true;
        resetReqQrySubscriber();
      }

    }

    this.OnRspQrySysUserLoginTopic = function(pRspQrySysUserLogin,pRspInfo,nRequestID,bIsLast)
    {
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
            outputStr += "rspCallNumb:                " + g_RspQrySysUserLoginTopic_spi_callbackNumb + "\n";
            outputStr += "++++++++++++++++ JS OnRspQrySysUserLoginTopic: END! ++++++++++++++++++" + "\n";
            g_RspQrySysUserLoginTopic_spi_callbackNumb++;
            console.log(outputStr);
    }

    this.OnRspQrySysUserRegisterTopic = function (pRspQrySysUserRegister, pRspInfo, nRequestID, bIsLast)
    {
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
};

// this.OnRtnObjectAttrTopic = function (pRtnObjectAttr) {
//     var outputStr = "\n************ JS::OnRtnObjectAttrTopic: START! ***********\n";
//     ++g_RtnObjectAttrTopic_spi_callbackNumb;
//     if (pRtnObjectAttr instanceof Object) {
//         outputStr +=  "ObjectID:                " + pRtnObjectAttr.ObjectID + "\n"
//                     + "AttrType:                " + pRtnObjectAttr.AttrType + "\n"
//                     + "MonDate:                 " + pRtnObjectAttr.MonDate + "\n"
//                     + "MonTime:                 " + pRtnObjectAttr.MonTime + "\n"
//                     + "ValueType:               " + pRtnObjectAttr.ValueType + "\n"
//                     + "AttrValue:               " + pRtnObjectAttr.AttrValue + "\n"
//     } else {
//         outputStr += "pRtnObjectAttr:          NULL!\n";
//     }
//     outputStr += "g_RtnObjectAttrTopic_spi_callbackNumb:   " + g_RtnObjectAttrTopic_spi_callbackNumb + "\n";
//     outputStr += "************ JS::OnRtnObjectAttrTopic: END! *********** \n";
//
//     console.log(outputStr);
// }

exports.Spi = Spi;
