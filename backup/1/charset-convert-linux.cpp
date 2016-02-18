#include "charset-convert-linux.h"

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

iconv_t CodeConverter(const char*from_charset, const char* to_charset) {		
	iconv_t cd = iconv_open(to_charset, from_charset);
	return cd;
}
	
int convert(iconv_t cd, char* inbuf, int inlen, char* outbuf, int outlen) {
	char** pin = const_cast<char**>(&inbuf);
	char** pout = &outbuf;
	memset(outbuf, 0, outlen);
	int flag = iconv(cd, pin, (size_t*)&inlen, pout, (size_t*)&outlen);
	iconv_close(cd);
	return flag;
}		
		
int _Gb2312ToUtf8(const char* inbuf, int inlen, char* outbuf, int outlen) {
	iconv_t Utf8ToGb2312 = CodeConverter("utf-8", "gb2312");
	char** pin = const_cast<char**>(&inbuf);
	char** pout = &outbuf;
	memset(outbuf, 0, outlen);
	int flag = iconv(Utf8ToGb2312, pin, (size_t*)&inlen, pout, (size_t*)&outlen);
	iconv_close(Utf8ToGb2312);
	return flag;
}	

int _Utf8ToGb2312(const char* inbuf, int inlen, char* outbuf, int outlen) {
	iconv_t Gb2312ToUtf8 = CodeConverter("utf-8", "gb2312");
	char** pin = const_cast<char**>(&inbuf);
	char** pout = &outbuf;
	memset(outbuf, 0, outlen);
	int flag = iconv(Gb2312ToUtf8, pin, (size_t*)&inlen, pout, (size_t*)&outlen);
	iconv_close(Gb2312ToUtf8);
	return flag;	
}

int Gb2312ToUtf8(const char* inputData, string& outputData) {
	int inputLength = strlen(inputData);
	int outputLength = inputLength * 2;
	char* outputStr = new char[outputLength];
	
	if (NULL == outputStr) {
		printf("Gb2312ToUtf8 Failed in allocating memeory for outputStr!\n");
		return -1;
	}
	
	int flag = _Gb2312ToUtf8(inputData, inputLength, outputStr, outputLength);	
	outputData = outputStr;
	
	if (NULL != outputStr) {
		delete[] outputStr; 
	}	
	return flag;
}

int Utf8ToGb2312(const char* inputData, string& outputData) {
	int inputLength = strlen(inputData);
	int outputLength = inputLength * 2;
	char* outputStr = new char[outputLength];
	
	if (NULL == outputStr) {
		printf("Gb2312ToUtf8 Failed in allocating memeory for outputStr!\n");
		return -1;
	}
	
	int flag = _Utf8ToGb2312(inputData, inputLength, outputStr, outputLength);	
	outputData = outputStr;
	
	if (NULL != outputStr) {
		delete[] outputStr; 
	}	
	return flag;
}
