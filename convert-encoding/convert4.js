var iconv = require('iconv-lite');
var encodingName = "GB2313";
var originalData = "Sample input string"; 

// Convert from an encoded buffer to js string. 
// var str = iconv.decode(new Buffer([0x68, 0x65, 0x6c, 0x6c, 0x6f]), 'GB2313');
 
// Convert from js string to an encoded buffer. 
var buf = iconv.encode("Sample input string", 'GB2313');

console.log("")