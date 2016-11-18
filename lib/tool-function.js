exports.hereDoc = function(f) {
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}

exports.OutputMessage = function (data) {
	console.log(data);	
}