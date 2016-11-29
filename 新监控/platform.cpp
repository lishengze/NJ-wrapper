/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file platform.cpp
///@briefʵ�ֿ�ƽ̨��Ҫ�ĺ���
///@history 
///20080603 �Ժ��		����������WIN32�µ�getopt����
///20110509 ����        NT-0131 UserAPI�������ƣ�����GetSysClock����
// 20110622 ����		NT-0138 ����ϵͳ�������ܣ�����GetSysMicroClock����
///20120319 ����        NT-0139 �ӿ���Ӧʱ�䣺���Ӷ���xtpЭ��ľ�ȷ��������
#include "platform.h"

#ifdef WIN32
char	*optarg;		// global argument pointer
int		optind = 0; 	// global argv index

int getopt(int argc, char *argv[], char *optstring)
{
	static char *next = NULL;
	if (optind == 0)
		next = NULL;

	optarg = NULL;

	if (next == NULL || *next == ('\0'))
	{
		if (optind == 0)
			optind++;

		if (optind >= argc || argv[optind][0] != ('-') || argv[optind][1] == ('\0'))
		{
			optarg = NULL;
			if (optind < argc)
				optarg = argv[optind];
			return EOF;
		}

		if (strcmp(argv[optind], ("--")) == 0)
		{
			optind++;
			optarg = NULL;
			if (optind < argc)
				optarg = argv[optind];
			return EOF;
		}

		next = argv[optind];
		next++;		// skip past -
		optind++;
	}

	char c = *next++;
	char *cp = strchr(optstring, c);

	if (cp == NULL || c == (':'))
		return ('?');

	cp++;
	if (*cp == (':'))
	{
		if (*next != ('\0'))
		{
			optarg = next;
			next = NULL;
		}
		else if (optind < argc)
		{
			optarg = argv[optind];
			optind++;
		}
		else
		{
			return ('?');
		}
	}

	return c;
}
#endif

DWORD GetSysClock()
{
	DWORD currTime = 0;
	DWORD currMilTime = 0;

#ifdef WIN32	
	struct _timeb timebuffer;
	_ftime(&timebuffer);
	currTime = (DWORD) timebuffer.time;	
	currMilTime = timebuffer.millitm;
#else
	struct timeval timeout;
    gettimeofday(&timeout, 0);
	currTime = timeout.tv_sec;	
	currMilTime = timeout.tv_usec / 1000;
#endif

	return currTime * 1000 + currMilTime;
}

QWORD GetSysMicroClock()
{
	QWORD currTime = 0;
	QWORD currMicroTime = 0;

#ifdef WIN32	
	struct _timeb timebuffer;
	_ftime(&timebuffer);
	currTime = (QWORD) timebuffer.time;	
	currMicroTime = timebuffer.millitm * 1000;
#else
	struct timeval timeout;
    gettimeofday(&timeout, 0);
	currTime = timeout.tv_sec;
	currMicroTime = timeout.tv_usec;
#endif

	return currTime * 1000000 + currMicroTime;
}

// xtpЭ��ľ�ȷ�������ݵ����
#ifdef RTT_MEASURE

TRttMeasure** g_RttMeasures = NULL;
DWORD g_FrontSubjectID = 0;

void DumpRttMeasure()
{
	// ����ļ�
	FILE* file = NULL;
	char buffer[1024];
		
	// �����ļ�
	file = fopen("rtt.txt", "wt");

	if (file == NULL)
	{
		printf("open rtt file failed!\n");

		return;
	}

	sprintf(buffer, "SubjectID: %d\n", g_FrontSubjectID);
	fputs(buffer, file);

	sprintf(buffer, "SequenceNo,RTT,Biz1,Biz2,Biz3\n");
	fputs(buffer, file);
	
	TRttMeasure* pRttMeasure = NULL;

	for (int i = 0; i < MAX_RTT_MEASURE_NUM; i ++)
	{
		pRttMeasure = g_RttMeasures[i];

		// ����������������
		if (pRttMeasure->BeginClock == 0 || pRttMeasure->EndClock == 0 || pRttMeasure->BizClock1 == 0 || pRttMeasure->BizClock2 == 0)
			continue;

		if (pRttMeasure->BizClock3 != 0 && pRttMeasure->BizClock4 != 0)
			sprintf(buffer, "%d,%d,%d,%d,%d,%d,%d,%d\n", pRttMeasure->SequenceNo, (int) (pRttMeasure->EndClock - pRttMeasure->BeginClock), (int) (pRttMeasure->BizClock1 - pRttMeasure->BeginClock), (int) (pRttMeasure->BizClock2 - pRttMeasure->BizClock1), (int) (pRttMeasure->EndClock - pRttMeasure->BizClock2), (int) (pRttMeasure->BizClock3 - pRttMeasure->BizClock1), (int) (pRttMeasure->BizClock4 - pRttMeasure->BizClock3), (int) (pRttMeasure->BizClock2 - pRttMeasure->BizClock4));
		else
			sprintf(buffer, "%d,%d,%d,%d,%d\n", pRttMeasure->SequenceNo, (int) (pRttMeasure->EndClock - pRttMeasure->BeginClock), (int) (pRttMeasure->BizClock1 - pRttMeasure->BeginClock), (int) (pRttMeasure->BizClock2 - pRttMeasure->BizClock1), (int) (pRttMeasure->EndClock - pRttMeasure->BizClock2));

		fputs(buffer, file);
	}
			
	fclose(file);
}

#endif

#define	UC(b)	(((int)b)&0xff)

void InetNtoA(struct in_addr ina, char* result)
{
	register char* p = (char*) &ina;
	sprintf(result, "%d.%d.%d.%d", UC(p[0]), UC(p[1]), UC(p[2]), UC(p[3]));
}
