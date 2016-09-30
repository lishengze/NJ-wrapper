#include "CplusReq.h"
#include "simplified-sysuserspi.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "tool-function.h"

extern struct timeval g_startTime;

int main(int argc, char* argv[])
{
	ConnectToFront(1);

	int reqOption;

	 while (1) {

		 cin >> reqOption;
		 cout << endl;

		 if (1 == reqOption) {
			 TestReqQrySysUserLoginTopic(1);
		 }else if (2 == reqOption) {
			 TestReqQryMonitorObjectTopic(1);
		 } else if (3 == reqOption) {
			 TestReqQrySubscriberTopic();
     } else if (0 == reqOption) {
			 break;
		 }
	 }

	return 0;
}
