#ifndef  _CHARSET_CONVERT_LINUX_
#define  _CHARSET_CONVERT_LINUX_

#include <iconv.h>


iconv_t CodeConverter(const char*from_charset, const char* to_charset);
	
int convert(iconv_t cd, char* inbuf, int inlen, char* outbuf, int outlen);		
		
int _Gb2312ToUtf8(const char* inbuf, int inlen, char* outbuf, int outlen);

int _Utf8ToGb2312(const char* inbuf, int inlen, char* outbuf, int outlen);

int Gb2312ToUtf8(const char* inputData, string& outputData);

int Utf8ToGb2312(const char* inputData, string& outputData);

#endif