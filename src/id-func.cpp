#include "id-func.h"
#include <queue>
#include <nan.h>
#include <iostream>
using std::queue;
using std::cin;
using std::cout;
using std::endl;

queue<FRONT_ID>    g_QueueIDSet;
uv_mutex_t         g_QueueIDSet_mutex;
const int          g_QueueAtomNumb = 500;
int                g_QueueNumbSum  = 0;

void InitFrontIDQueue () {
	uv_mutex_init (&g_QueueIDSet_mutex);
	
	uv_mutex_lock(&g_QueueIDSet_mutex);
	for (int i = 0; i < g_QueueAtomNumb; ++i) {
		g_QueueIDSet.push(i);
	}	
	g_QueueNumbSum += g_QueueAtomNumb;
	uv_mutex_unlock(&g_QueueIDSet_mutex);
}

void ResizeFrontIDQueue() {
	for (int i = g_QueueNumbSum; i < g_QueueAtomNumb; ++i) {
		g_QueueIDSet.push(i + g_QueueNumbSum);
	}	
	g_QueueNumbSum += g_QueueAtomNumb;
}

FRONT_ID GetFrontID() {	
	FRONT_ID tmpID;
	uv_mutex_lock(&g_QueueIDSet_mutex);	
	if (true == g_QueueIDSet.empty()) {
		ResizeFrontIDQueue();
	}	
	tmpID = g_QueueIDSet.front();
	g_QueueIDSet.pop();
	uv_mutex_unlock(&g_QueueIDSet_mutex);
	return tmpID;	
}

void ReAllocateID(FRONT_ID& frontid) {
	uv_mutex_lock(&g_QueueIDSet_mutex);
	g_QueueIDSet.push(frontid);
	uv_mutex_unlock(&g_QueueIDSet_mutex);	
}
