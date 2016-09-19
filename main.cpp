#include "CplusReq.h"
#include "simplified-sysuserspi.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "tool-function.h"

double g_sec = 1;
double g_min = 1;
double g_stopusec = g_min * g_sec * 1000000;

extern int g_RtnObjectAttrTopic_spi_callbackNumb;
extern struct timeval g_startTime;
extern bool g_rtn_over;
extern int g_reqNumb;
extern int g_testTimeIndex;

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

			 if (g_reqNumb == 6) {
				cout << "reset time!" << endl;
				cout << "g_sec: "; cin >> g_sec;
				cout << "g_min: "; cin >> g_min;
				g_stopusec = g_min * g_sec * 1000000;
				g_reqNumb = 1;
				g_testTimeIndex++;
			 }


			 g_rtn_over = false;
			 g_RtnObjectAttrTopic_spi_callbackNumb = 0;

       		//  TestReqQrySubscriberTopic();

			 gettimeofday( &g_startTime, NULL );

			 	time_t t;
				struct tm *pnow = NULL;

				t = time(&t);
				pnow = localtime(&t);

				string curTime = asctime(pnow);

			//  OutputCallbackMessage("StartTime: ", showCurTime(), g_RunningResult_File);
			 OutputCallbackMessage("StartTime:     ", curTime, g_RunningResult_File);
     } else if (0 == reqOption) {
			 break;
		 }
	 }

	return 0;
}
