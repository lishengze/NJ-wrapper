#ifndef  _CHARSET_CONVERT_WINDOWS_H_
#define  _CHARSET_CONVERT_WINDOWS_H_

#include <string>
#include <windows.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

const int CHAR_BUFSIZE = 4096;       

void Gb2312ToUtf8(const char *pcGb2312, std::string & strUtf8)

{

	//wchar_t pcUnicode[CHAR_BUFSIZE];

	//gb2312 to unicode

	int nUnicodeLen = MultiByteToWideChar(CP_ACP, 0, pcGb2312, -1, NULL, 0);

	wchar_t * pcUnicode = new wchar_t[nUnicodeLen + 1];
	memset(pcUnicode, 0, nUnicodeLen * 2 + 2);

	MultiByteToWideChar(CP_ACP, 0, pcGb2312, -1, pcUnicode, nUnicodeLen);


	//unicode to utf8

	int nUtf8Len = WideCharToMultiByte(CP_UTF8, 0, pcUnicode, -1, NULL, 0, NULL, NULL);

	char *pcUtf8 = new char[nUtf8Len + 1];
	memset(pcUtf8, 0, nUtf8Len + 1);

	WideCharToMultiByte(CP_UTF8, 0, pcUnicode, -1, pcUtf8, nUtf8Len, NULL, NULL);

	strUtf8 = pcUtf8;
	delete[] pcUtf8;
	delete[] pcUnicode;
}

/** UTF8TOGB2312*/
void Utf8ToGb2312(const char *pcUtf8, std::string & strGB2312)

{

	//wchar_t pcUnicode[CHAR_BUFSIZE];

	int nUnicodeLen = MultiByteToWideChar(CP_UTF8, 0, pcUtf8, -1, NULL, 0);

	wchar_t * pcUnicode = new wchar_t[nUnicodeLen + 1];
	memset(pcUnicode, 0, nUnicodeLen * 2 + 2);

	//utf8 to unicode

	MultiByteToWideChar(CP_UTF8, 0, pcUtf8, -1, pcUnicode, nUnicodeLen);

	//unicode to gb2312

	int nGb2312Len = WideCharToMultiByte(CP_ACP, 0, pcUnicode, -1, NULL, 0, NULL, NULL);

	char *pcGb2312 = new char[nGb2312Len + 1];
	memset(pcGb2312, 0, nGb2312Len + 1);

	WideCharToMultiByte(CP_ACP, 0, pcUnicode, -1, pcGb2312, nGb2312Len, NULL, NULL);

	strGB2312 = pcGb2312;
	delete[] pcGb2312;
	delete[] pcUnicode;
}

#endif