#include "CplusReq.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{    
	 ConnectToFront(40);
     
	 int reqOption;
	 
	 while (1) {
		 
		 cin >> reqOption;

		 if (1 == reqOption) {
			 TestReqQrySysUserLoginTopic(1);
		 }
		 else if (2 == reqOption) {
			 TestReqQryMonitorObjectTopic(1);
		 } else if (3 == reqOption) {
             TestReqQrySysUserLoginTopic(1);
         } else if (0 == reqOption) {
			 break;
		 }
	 }
	 
	return 0;
}
