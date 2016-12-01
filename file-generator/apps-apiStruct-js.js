var fs = require('fs');
var hereDoc = require('../lib/tool-function.js').hereDoc;
var serverName = process.argv[2];
var pathName = '../lib/' + serverName + '/';
var ftdContent = require(pathName + "FTD.json");

var ftdField = ftdContent.FTD.fields[0].fieldDefine;
var tabSpace = ["","    ", "        ", "            ", "                ","                    "];
var fileData = "";

for(var fieldIndex = 0; fieldIndex < ftdField.length; fieldIndex++) {

		var itemlength = ftdField[fieldIndex].item.length;
		var fieldName = ftdField[fieldIndex].$.name ;
		fileData += "exports.CShfeFtdc" + fieldName + "Field = function ()\n{\n";
		
		for(var itemIndex = 0; itemIndex < itemlength; itemIndex++) {

				var itemName = ftdField[fieldIndex].item[itemIndex].$.name;
				var itemType = ftdField[fieldIndex].item[itemIndex].$.type.substring(1, ftdField[fieldIndex].item[itemIndex].$.type.length - 4);
				var itemClassType = getItemClassType(itemType);

				if ("StringClass" === itemClassType) {
					fileData += tabSpace[1] + "this." + itemName + " = \"\"; \n"
				} else {
					fileData += tabSpace[1] + "this." + itemName + " = 0; \n"
				}
		}
		fileData += "};\n\n"
}

function getItemClassType (itemType) {
    for (var typeIndex = 0; typeIndex < ftdContent.FTD.types[0].String.length; typeIndex++) {
        if (ftdContent.FTD.types[0].String[typeIndex].$.typename === itemType) {
            return "StringClass";
        }
    }	

    for (var typeIndex = 0; typeIndex < ftdContent.FTD.types[0].VString.length; typeIndex++) {
        if (ftdContent.FTD.types[0].VString[typeIndex].$.typename === itemType) {
            return "StringClass";
        }
    }

    for (var typeIndex = 0; typeIndex < ftdContent.FTD.types[0].Array.length; typeIndex++) {
        if (ftdContent.FTD.types[0].Array[typeIndex].$.typename === itemType) {
            return "StringClass";
        }
    }

		return "NumberClass";  
}

var pathName = '../new-file/';
var fileName = 'SysUserApiStruct.js';
fs.writeFile(pathName + fileName, fileData, function (err) {
    if (err) {
        console.log(err);
    } else {
        console.log('Succeed in saving ' + pathName + fileName);
    }
});
