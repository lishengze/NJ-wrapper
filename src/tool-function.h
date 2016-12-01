#ifndef _TOOL_FUNCTION_H_
#define _TOOL_FUNCTION_H_

#include <iostream>
#include <string>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ios;

template <class valueType>
void OutputCallbackMessage(valueType data) {
	cout << data << endl;
}

template <class valueType>
void OutputCallbackMessage(valueType data, fstream& f_File) {
	cout << data << endl;
	if (f_File) {
	 	f_File << data << endl;
	} else {
	//	cout << data << endl;
	}	
}

template<class valueType>
void OutputCallbackMessage(string varName, valueType varValue) {
	cout << varName << varValue << endl;
}

template<class valueType>
void OutputCallbackMessage(string varName, valueType varValue, fstream& f_File) {
	cout << varName << varValue << endl;
	if (f_File) {
		f_File << varName << varValue << endl;
	} else {
	//	cout << varName << varValue << endl;
	}	
}

#endif