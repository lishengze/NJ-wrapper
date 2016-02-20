#include "charset-convert-linux.h"

#include <iconv.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <malloc.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

iconv_t CodeConverter(const char*from_charset, const char* to_charset) {		
	iconv_t cd = iconv_open(to_charset, from_charset);
	return cd;
}

void SetValue(char * inputData, int inputLength) {
	inputLength += 2; 
	for (int i = 0; i < inputLength; ++i) {
		inputData[i] = 'a';
	}
}
			
int _Gb2312ToUtf8(char* inbuf, int inlen, char* outbuf, int outlen) {
	iconv_t Gb2312ToUtf8 = CodeConverter("gb2312", "utf-8");
	// iconv_t Gb2312ToUtf8 = iconv_open("utf-8", "gb2312");
	char* pin  = inbuf;
	char* pout = outbuf;
	memset(outbuf, 0, outlen);
	int flag = 0;
	flag = iconv(Gb2312ToUtf8, (char**)&pin, (size_t*)&inlen, (char**)&pout, (size_t*)&outlen);
	// SetValue(outbuf, outlen);
	iconv_close(Gb2312ToUtf8);
	return flag;
}

int Gb2312ToUtf8(char* inputData, int inputLength, char* outputData, int outputLength) {
	iconv_t Gb2312ToUtf8 = iconv_open("utf-8", "gb2312");
	char* pin  = inputData;
	char* pout = outputData;
	memset(outputData, 0, outputLength);
	int flag = 0;
	flag = iconv(Gb2312ToUtf8, (char**)&pin, (size_t*)&inputLength, (char**)&pout, (size_t*)&outputLength);
	iconv_close(Gb2312ToUtf8);
	return flag;	
}	

int Gb2312ToUtf8(char* inputData, string& outputData) {
	int inputLength = strlen(inputData);
    const int outputLength = 4096 * 24;
	char outputStr[outputLength];
    
	int flag = _Gb2312ToUtf8(inputData, inputLength, outputStr, outputLength);	
	// outputData = outputStr;
	outputData = inputData;
	return flag;
}

// int Gb2312ToUtf8(char* inputData, string& outputData) {
// 	int inputLength = strlen(inputData);
//     const int outputLength = 4096 * 12;
// 	char outputStr[outputLength];
//     char* pin  = inputData;
// 	char* pout = outputStr;
// 	memset(pout, 0, outputLength);
	
// 	int flag = 0;
// 	iconv_t Gb2312ToUtf8 = iconv_open("utf-8", "gb2312");
// 	flag = iconv(Gb2312ToUtf8, (char**)&pin, (size_t*)&inputLength, (char**)&pout, (size_t*)&outputLength);
// 	cout << "flag:   " << flag << endl;
	
// 	iconv_close(Gb2312ToUtf8);	
// 	outputData = outputStr;
// 	// outputData = inputData;
// 	return flag;
// }


// int Gb2312ToUtf8(char* inputData, string& outputData) {
// 	int inputLength  = strlen(inputData);	 
// 	int outputLength = (inputLength ) * 24;	
// 	char* outputStr  = new char[outputLength];
	
// 	if (NULL == outputStr) {
// 		printf("Gb2312ToUtf8 Failed in allocating memeory for outputStr!\n");
// 		return -1;
// 	}
    
// 	int flag = _Gb2312ToUtf8(inputData, inputLength, outputStr, outputLength);	
// 	// outputData = outputStr;
// 	outputData = inputData;
	    
// 	if (NULL != outputStr) {
// 		delete[] outputStr;
// 		outputStr = NULL;
// 	}	
	
// 	return flag;
// }


int _Utf8ToGb2312(char* inbuf, int inlen, char* outbuf, int outlen) {
	iconv_t Utf8ToGb2312 = CodeConverter("utf-8", "gb2312");
	char** pin = &inbuf;
	char** pout = &outbuf;
	memset(outbuf, 0, outlen);
	int flag = iconv(Utf8ToGb2312, pin, (size_t*)&inlen, pout, (size_t*)&outlen);
	iconv_close(Utf8ToGb2312);
	return flag;	
}


int Utf8ToGb2312(char* inputData, string& outputData) {
	int inputLength = strlen(inputData);
    const int outputLength = 4096;
	char outputStr[outputLength];
	
	if (NULL == outputStr) {
		printf("Gb2312ToUtf8 Failed in allocating memeory for outputStr!\n");
		return -1;
	}
	
	int flag = _Utf8ToGb2312(inputData, inputLength, outputStr, outputLength);	
	outputData = outputStr;
	
	return flag;
}

int convert(iconv_t cd, char* inbuf, int inlen, char* outbuf, int outlen) {
	char** pin = const_cast<char**>(&inbuf);
	char** pout = &outbuf;
	memset(outbuf, 0, outlen);
	int flag = iconv(cd, pin, (size_t*)&inlen, pout, (size_t*)&outlen);
	iconv_close(cd);
	return flag;
}		

