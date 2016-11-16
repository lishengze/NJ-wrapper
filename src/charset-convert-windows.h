#ifndef  _CHARSET_CONVERT_WINDOWS_H_
#define  _CHARSET_CONVERT_WINDOWS_H_

#include <string>
#include <windows.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void Gb2312ToUtf8(const char *pcGb2312, std::string & strUtf8);

/** UTF8TOGB2312*/
void Utf8ToGb2312(const char *pcUtf8, std::string & strGB2312);

// std::string StringToUtf8(const std::string& strSource)
// {
// 	std::string strTmp = "";
// 	Gb2312ToUtf8(strSource.c_str(), strTmp);
// 	return strTmp;
// }

// std::string StringToGB2312(const std::string& strSource)
// {
// 	std::string strTmp = "";
// 	Utf8ToGb2312(strSource.c_str(), strTmp);
// 	return strTmp;
// }

// std::string StringToUtf8(const char * strSource)
// {
// 	return StringToUtf8(std::string(strSource));
// }

// std::string StringToGB2312(const char * strSource)
// {
// 	std::string strTmp = "";
// 	Utf8ToGb2312(strSource, strTmp);
// 	return strTmp;
// }


#endif