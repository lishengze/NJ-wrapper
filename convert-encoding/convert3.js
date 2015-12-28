// convert from UTF-8 to ISO-8859-1
var Buffer = require('buffer').Buffer;
var Iconv  = require('iconv').Iconv;
var assert = require('assert');

var iconv = new Iconv('EUC-CN','UTF-8');
var buffer1 = iconv.convert('Host cpuƽ��ʹ����');
var buffer2 = iconv.convert(new Buffer('Hello, world!'));

console.log('buffer1: ' + buffer1 + '\nbuffer2: ' + buffer2);

// assert.equals(buffer1.inspect(), buffer2.inspect());
// do something useful with the buffer