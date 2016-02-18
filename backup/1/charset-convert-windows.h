#ifndef  _CHARSET_CONVERT_WINDOWS_H_
#define  _CHARSET_CONVERT_WINDOWS_H_    

void Gb2312ToUtf8(const char *pcGb2312, std::string & strUtf8);

/** UTF8TOGB2312*/
void Utf8ToGb2312(const char *pcUtf8, std::string & strGB2312);

#endif