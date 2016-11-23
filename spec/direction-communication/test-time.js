var ReqQrySubscriberTopic = function() {
		var curWholeTime = (new Date()).toLocaleString();
		// var curDate = (curWholeTime.substring(0,10)).replace(/-/g, '');
		var curDate = curWholeTime.substring(0,10);
		curDate = curDate.substring(0,4) + curDate.substring(5,7) + curDate.substring(8);
		var curTime = curWholeTime.substring(11);
		console.log (curDate);
		console.log (curTime);
}

ReqQrySubscriberTopic();