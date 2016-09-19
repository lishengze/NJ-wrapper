#include "tool-function.h"

#include <ctime>
using namespace std;

string showCurTime() {
	time_t t;
    struct tm *pnow = NULL;

    t = time(&t);
    pnow = localtime(&t);

    string curTime = asctime(pnow);
  	cout << curTime <<endl;
    return curTime;
}