var fs = require('fs');
var fileName = "./data.txt"
var originData = fs.readFile(fileName, function (err,data) {
	if (err) throw err;
  console.log(data);
}); 
// var originData = '22,主机网络信息 \n124,主机活跃信息';
// console.log (originData);

function processMonConfigInfoData (originData) {
	var tmpData = originData.split("\n")
}
