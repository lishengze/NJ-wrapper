 //test.js
var fs = require('fs');
var xml2js = require('xml2js');

function loadXMLDoc(filePath){
	var json;
	try {
		var fileData = fs.readFileSync(filePath,'utf8');
		var parser = new xml2js.Parser();
		parser.parseString(fileData.substring(0, fileData.length), function(err, result){
			json = JSON.stringify(result);
		});
		return json;      //返回生成的JSON
	} catch (ex) {
		console.log(ex);
		}
}

var fileName = ['sysuserapi', 'FTD'];
var serverName = process.argv[2];

for (var i = 0; i < fileName.length; ++i) {
	var pathName = '../lib/' + serverName + '/';
	var xmlFileName  = pathName + fileName[i] + ".xml";
	var jsonFileName = pathName + fileName[i] + ".json";

	var fileData = loadXMLDoc(xmlFileName);

	fs.writeFile(jsonFileName, fileData, function(fileName) {
		return function (err) {
						if (err) {
							console.log(err);
						} else {
							console.log('Succeed in saving ' + fileName);
						}
					}
		}(jsonFileName)
	);
}
