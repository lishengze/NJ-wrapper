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

int _Gb2312ToUtf8(char* inbuf, size_t inlen, char* outbuf, size_t outlen) {
	iconv_t Gb2312ToUtf8 = CodeConverter("gb2312", "utf-8");
	// iconv_t Gb2312ToUtf8 = iconv_open("utf-8", "gb2312");
	char* pin  = inbuf;
	char* pout = outbuf;
	memset(outbuf, 0, outlen);
	int flag = 0;
	flag = iconv(Gb2312ToUtf8, (char**)&pin, &inlen, (char**)&pout, &outlen);
	iconv_close(Gb2312ToUtf8);
	return flag;
}

int Gb2312ToUtf8(char* inputData, int inputLength, char* outputData, int outputLength) {
	iconv_t Gb2312ToUtf8 = iconv_open("utf-8", "gb2312");
	char* pin  = inputData;
	char* pout = outputData;
	// memset(outputData, 0, outputLength);
	int flag = 0;
	flag = iconv(Gb2312ToUtf8, (char**)&pin, (size_t*)&inputLength, (char**)&pout, (size_t*)&outputLength);
	iconv_close(Gb2312ToUtf8);
	return flag;
}

// int Gb2312ToUtf8(char* inputData, string& outputData) {
//	 	int inputLength = strlen(inputData);
//	  const int outputLength = 4096 * 24;
//	 	char outputStr[outputLength];
//
//	 	int flag = _Gb2312ToUtf8(inputData, inputLength, outputStr, outputLength);
//	 	outputData = outputStr;
//	 	// outputData = inputData;
//	 	cout << "flag: " << flag << endl;
//	 	return flag;
// }

// void transformTest(char *src, char *dest, long unsigned int destLen){
//	//char *src ="我们一二三四五";
//    long unsigned int srcLen = strlen(src);
//    //long unsigned int destLen = 256;
//    int iconvLen = -1;
//    //char* dest = (char*)malloc(destLen * sizeof(char));
//    char* obj = dest;
//    //memset(dest, 0, 256);
//
//    iconv_t convId;
//    convId = iconv_open("utf-8", "gb2312");
//    if ((long unsigned int)convId == -1)
//    {
//        perror("iconv open error");
//    }
//
//    printf("before, src: %s, dest: %s, srcLen: %d, destLen: %d\n", src, dest, srcLen, destLen);
//    iconvLen = iconv(convId, &src, &srcLen, &dest, &destLen);
//    printf("after,  src: %s, obj: %s, dest: %s, srcLen: %d, destLen: %d\n", src, obj, dest, srcLen, destLen);
//    printf("iconvLen: %d\n", iconvLen);
//    if (iconvLen == -1)
//    {
//        perror("error:");
//    }
//	/*
//    unsigned int convLen = 256 - destLen;
//    FILE* f = fopen("test.txt", "w");
//    if (fwrite(obj, 1, convLen, f) != convLen)
//    {
//        printf("fwrite error!\n");
//    }
//    fclose(f);
//	*/
//    iconv_close(convId);
//    dest=obj;
//    //free(obj);
//}

int Gb2312ToUtf8(char* inputData, string& outputData) {
	int inputLength  = strlen(inputData);
	int outputLength = (inputLength ) * 4;
	char* outputStr  = new char[outputLength];

	if (NULL == outputStr) {
		printf("Gb2312ToUtf8 Failed in allocating memeory for outputStr!\n");
		return -1;
	}

	int flag = _Gb2312ToUtf8(inputData, inputLength, outputStr, outputLength/2);
	 outputData = outputStr;
	// outputData = inputData;

	if (NULL != outputStr) {
		delete[] outputStr;
		outputStr = NULL;
	}

	return flag;
}


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

