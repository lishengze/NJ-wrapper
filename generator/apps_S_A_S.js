var fs = require('fs');
var jsonContent=require("./package.json");
var str="";
var lengthField=0;//jsonContent.FTD.fields[0].fieldDefine.length;
 while(jsonContent.FTD.fields[0].fieldDefine[lengthField].$.name!=="SysNetNonPartyLinkInfo"){//SysNetNonPartyLinkInfo之后的不需要
     ++lengthField;
 }
lengthField++;
 for(var i=0;i<lengthField;i++) {//fieldDefine个数
     str += "exports.CShfeFtdc" + jsonContent.FTD.fields[0].fieldDefine[i].$.name + "Field=function()\n{\n";
     var itemlength=jsonContent.FTD.fields[0].fieldDefine[i].item.length;
     for(var j=0;j<itemlength;j++) {//每个fieldDefine的属性个数
         var IntTypeLength=jsonContent.FTD.types[0].Int.length;
         var StringTypeLength=jsonContent.FTD.types[0].String.length;
         var ArrayTypeLength=jsonContent.FTD.types[0].Array.length;
         var VStringTypeLength=jsonContent.FTD.types[0].VString.length;
         var itemType = jsonContent.FTD.fields[0].fieldDefine[i].item[j].$.type.substring(1, jsonContent.FTD.fields[0].fieldDefine[i].item[j].$.type.length - 4);

         var num=0;//用以判断是否在Int类型中找到对象。若为1则找到；
         for(var k=0;k<StringTypeLength;k++){
             if(itemType===jsonContent.FTD.types[0].String[k].$.typename)
               {
                 num++;
                 str += "  this." + jsonContent.FTD.fields[0].fieldDefine[i].item[j].$.name + "=\" \";\n";
                 break;
               }
         }
         for(var k=0;k<ArrayTypeLength;k++){
             if(itemType===jsonContent.FTD.types[0].Array[k].$.typename)
             {
                 num++;
                 str += "  this." + jsonContent.FTD.fields[0].fieldDefine[i].item[j].$.name + "=\" \";\n";
                 break;
             }
         }
         for(var k=0;k<VStringTypeLength;k++){
             if(itemType===jsonContent.FTD.types[0].VString[k].$.typename)
             {
                 num++;
                 str += "  this." + jsonContent.FTD.fields[0].fieldDefine[i].item[j].$.name + "=\" \";\n";
                 break;
             }
         }
         if(num===0) {
             str += "  this." + jsonContent.FTD.fields[0].fieldDefine[i].item[j].$.name + "=0;\n";
         }
     }
     str += "}\n\n";
 }
fs.writeFile('SysUserApiStruct_JS.js', str, function (err) {
    if (err) throw err;
    console.log('It\'s saved!');
});