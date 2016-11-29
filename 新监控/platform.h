/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file platform.h
///@brief�������п�ƽ̨��Ҫ�ĺ꣬�Լ�������Ӧ��ͷ�ļ�
///@history 
///20020214	���ض�		�������ļ�
///20070912 �Ժ��		�޸�UNIX��
///20070927 �Ժ��		����LINUX��singalͷ�ļ�
///20080603 �Ժ��		����WIN32�µ�getopt����
///20080727 �Ժ��		����stackͷ�ļ�
///20090119 �Ժ��		�޸�GET_ACCURATE_TIME��ʹ��UNIX��WINN�º�����ͬ��
///						���պ�������NT-0065��
///20100423 ����        NT-0100������QWORD����������֧��64λ����
///20100430 ����        NT-0102����ǿ�Գ���4G���ļ���֧��
///20100903 ����        NT-0109�����˵��Ƿ�����ֵ
///20110509 ����        NT-0131��UserAPI�������ƣ�����GetSysClock�������޸��˷�windows��SLEEPʵ��
///20110519 ����        NT-0132�����������ƣ����Ӷ�64λ����֧��
// 20110622 ����		NT-0138������ϵͳ�������ܣ�����GetSysMicroClock����
// 20110622 ����		NT-0138 ����ϵͳ�������ܣ�����INT64����
///20110901 �Ժ��		NT-0150 ����GetPreciseTime��������ȡ��ȷ��΢��ĵ�ǰʱ��
///20120319 ����		���Ӷ���xtpЭ��ľ�ȷ��������
///20120319 ����        NT-0139 �ӿ���Ӧʱ�䣺���Ӷ���xtpЭ��ľ�ȷ��������
///20120726 ����        ���ڲ���ȫ���������˶�Ӧ��ȫ�汾�ķ�װ��localtime��inet_ntoa
/////////////////////////////////////////////////////////////////////////

#ifndef PLATFORM_H
#define PLATFORM_H

///Ŀǰ���ļ�֧�����ֲ�ͬ��ƽ̨���û���ʹ��WINDOWS��ʾmicrosoft windows�ĸ���
///ƽ̨��ʹ��VC 6.0���ϱ��룩��Ҳ����ʹ��UNIX��ʾ���ֲ�ͬ��unixƽ̨��ʹ��g++���룩��
///Ҳ����ʹ��VOS��ʾStratus��VOSƽ̨(ʹ��g++���룩
///#define WINDOWS
///#define VOS
///#define UNIX

///�Գ���4G���ļ���֧�֣�Ҫ����stdio.h��׼ͷ�ļ�ǰ������Ч
#define _FILE_OFFSET_BITS 64
#define INT_NaN INT_MAX
#define LONGINT_NaN LLONG_MAX


/////////////////////////////////////////////////////////////////////////
///����ƽ̨����Ҫ�������ļ�
/////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <errno.h>
#include <memory.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <float.h>

/////////////////////////////////////////////////////////////////////////
///STL
/////////////////////////////////////////////////////////////////////////
#ifdef WINDOWS
	#pragma warning(disable:4786)
#endif
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <stack>
using namespace std;

/////////////////////////////////////////////////////////////////////////
///Windows����ĺ�
/////////////////////////////////////////////////////////////////////////
#ifdef WINDOWS
#define WIN32
#define _CONSOLE
#define _MBCS
#endif

/////////////////////////////////////////////////////////////////////////
///Unix����ĺ�
/////////////////////////////////////////////////////////////////////////
#ifdef LINUX
#define UNIX
#endif

#ifdef HP_UX
#define UNIX
#define _BIG_ENDIAN_
//#define _XOPEN_SOURCE_EXTENDED
//#define _INCLUDE_POSIX_SOURCE
#endif

#ifdef DEBUG
#ifndef _DEBUG
#define _DEBUG
#endif
#endif

/////////////////////////////////////////////////////////////////////////
///�򿪻��߹رյ���ģʽ
/////////////////////////////////////////////////////////////////////////
//#define DEBUG

/////////////////////////////////////////////////////////////////////////
///����ƽ̨���е�ͷ�ļ�
/////////////////////////////////////////////////////////////////////////
#ifdef WINDOWS
#include <windows.h>
#include <io.h>
#include <process.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/timeb.h>
#include <winsock.h>
#include <fcntl.h>
#endif

#ifdef UNIX
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
typedef int cid_t;
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <pthread.h>
#include <sys/timeb.h>
#include <fcntl.h>
#ifdef LINUX
#include <semaphore.h>
#include <signal.h>
#else
#include <sys/semaphore.h>
#endif
#endif

#ifdef AIX
#include <strings.h>
#endif
#ifdef HP_UX
#include <strings.h>
#endif

#ifdef VOS
#define $shortmap
#define $longmap
#define $memset memset
#include <voslib.h>
#include <c_utilities.h>
#include <errno.h>
#include <streams_utilities.h>
#include <error_codes.h>
#include <tcp_types.h>
#include <socket.h>
#include <tcp_socket.h>
#include <in.h>
#include <ioctl.h>
#define _TYPEDEF_DEV_T
#define _TYPEDEF_OFF_T
#include <sys/stat.h>
#endif

/////////////////////////////////////////////////////////////////////////
///·��������
/////////////////////////////////////////////////////////////////////////
#include "mpath.h"

/////////////////////////////////////////////////////////////////////////
///�����׼���ȵ�����
/////////////////////////////////////////////////////////////////////////
typedef unsigned char	BYTE;
typedef unsigned short	WORD;
typedef char	INT1;
typedef short	INT2;
typedef int	INT4;
typedef float	REAL4;
typedef double	REAL8;

#ifndef  WINDOWS
	typedef unsigned int		DWORD;
	typedef unsigned long int	QWORD;
	typedef long int			INT64;
#else 
	#if defined (_MSC_VER) && (_MSC_VER >= 1020)
		#pragma  warning(disable:4819 4996)
	#else 
		typedef unsigned int	DWORD;
	#endif
	
	typedef unsigned __int64	QWORD;
	typedef __int64				INT64;
#endif

/////////////////////////////////////////////////////////////////////////
///�ֽ������
/////////////////////////////////////////////////////////////////////////
inline WORD ChangeEndian(WORD value)
{
	return	((value&0x00ff)<<8)|
			((value&0xff00)>>8);
}

inline DWORD ChangeEndian(DWORD value)
{
	return	((value&0x000000ff)<<24) |
			((value&0x0000ff00)<<8)  |
			((value&0x00ff0000)>>8)  |
			((value&0xff000000)>>24);
}

inline QWORD ChangeEndian(QWORD value)
{
#ifdef WINDOWS
	return	((value&0x00000000000000ffUI64)<<56) |
			((value&0x000000000000ff00UI64)<<40)  |
			((value&0x0000000000ff0000UI64)<<24)  |
			((value&0x00000000ff000000UI64)<<8)  |
			((value&0x000000ff00000000UI64)>>8)  |
			((value&0x0000ff0000000000UI64)>>24)  |
			((value&0x00ff000000000000UI64)>>40)  |
			((value&0xff00000000000000UI64)>>56);
#else
	return	((value&0x00000000000000ffUll)<<56) |
			((value&0x000000000000ff00Ull)<<40)  |
			((value&0x0000000000ff0000Ull)<<24)  |
			((value&0x00000000ff000000Ull)<<8)  |
			((value&0x000000ff00000000Ull)>>8)  |
			((value&0x0000ff0000000000Ull)>>24)  |
			((value&0x00ff000000000000Ull)>>40)  |
			((value&0xff00000000000000Ull)>>56);
#endif
}

inline fpos_t ChangeEndian(fpos_t value)
{
	fpos_t temp = value;
	char *pSource = (char *)&value;
	char *pTarget = (char *)&temp;
	pTarget[7] = pSource[0];
	pTarget[6] = pSource[1];
	pTarget[5] = pSource[2];
	pTarget[4] = pSource[3];
	pTarget[3] = pSource[4];
	pTarget[2] = pSource[5];
	pTarget[1] = pSource[6];
	pTarget[0] = pSource[7];
	return temp;
}

#ifndef _BIG_ENDIAN_
#define CHANGE_ENDIAN(value)	value = ::ChangeEndian(value)
#else
#define CHANGE_ENDIAN(value)
#endif

/////////////////////////////////////////////////////////////////////////
///���Ƴ����еĶ���
/////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
#define ASSERT(booleanExpression )					\
	if(!(booleanExpression)){						\
		RAISE_DESIGN_ERROR(#booleanExpression);		\
	}
#else
#define ASSERT(booleanExpression )
#endif


/////////////////////////////////////////////////////////////////////////
///�����ļ�������
/////////////////////////////////////////////////////////////////////////
///��Unix�£�����ʹ��stat����ȡ�ļ�״̬
#ifdef UNIX
#define struct_stat struct stat
#define STAT	stat
#endif
///��Windows�£�����ʹ��_stat����ȡ�ļ�״̬
#ifdef WINDOWS
#define struct_stat struct _stat
#define STAT	_stat
#endif
///��Vos�£�����ʹ��stat����ȡ�ļ�״̬
#ifdef VOS
#define struct_stat struct stat
#define STAT    stat
#endif

///��Unix�£�����ʹ��unlink��ɾ���ļ�
#ifdef UNIX
#define UNLINK unlink
#endif
///��Windows�£�����ʹ��_unlink��ɾ���ļ�
#ifdef WINDOWS
#define UNLINK _unlink
#endif
///��Vos�£�����ʹ��vos_unlink��ɾ���ļ�
#ifdef VOS
#define UNLINK vos_unlink
#endif

///����openʱ�Ĳ�������
#ifdef UNIX
#define OPEN_FOR_READ (O_RDONLY)
#define OPEN_FOR_WRITE (O_RDWR)
#define OPEN_FOR_CREATE (O_RDWR|O_CREAT|O_TRUNC)
#endif
#ifdef WINDOWS
#define OPEN_FOR_READ (O_BINARY|O_RDONLY)
#define OPEN_FOR_WRITE (O_BINARY|O_RDWR)
#define OPEN_FOR_CREATE (O_BINARY|O_RDWR|O_CREAT|O_TRUNC)
#endif

/////////////////////////////////////////////////////////////////////////
///�������ڴ������
/////////////////////////////////////////////////////////////////////////
#ifdef UNIX
#ifndef SHM_FAILED
#define SHM_FAILED (char *)(-1)
#endif
#define ALLOC_SHARE_MEMORY(ptr_addr, id,size)  				\
	{								\
		int shmid = shmget(id,size, IPC_CREAT|0644);		\
		if(shmid<0) 						\
		{							\
			*ptr_addr=NULL;					\
		}							\
		else 							\
		{ 							\
			*ptr_addr=(char *)shmat(shmid,(char *)0,0);	\
			if (*ptr_addr == SHM_FAILED)			\
				*ptr_addr=NULL;				\
		}							\
	}
#define REUSE_SHARE_MEMORY(ptr_addr, id,size)  				\
	{								\
 		int shmid = shmget(id,size, 0644);			\
		if(shmid<0) 						\
		{							\
			*ptr_addr=NULL;					\
		}							\
		else 							\
		{ 							\
			*ptr_addr=(char *)shmat(shmid,(char *)0,0);	\
			if(*ptr_addr == SHM_FAILED)			\
				*ptr_addr=NULL;				\
		}							\
	}
#endif

#ifdef WINDOWS
#define ALLOC_SHARE_MEMORY(ptr_addr,id,size)				\
	{								\
		HANDLE hfile,hmap;					\
		char buffer[80];					\
		sprintf(buffer,"\\mapping%d.mem",id);			\
		hfile=CreateFile(buffer,GENERIC_READ|GENERIC_WRITE,	\
			FILE_SHARE_READ|FILE_SHARE_WRITE,		\
			NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);	\
		if (hfile==INVALID_HANDLE_VALUE)			\
		{							\
			*ptr_addr=NULL;					\
		}							\
		else							\
		{							\
			hmap=CreateFileMapping(hfile,NULL,		\
				PAGE_READWRITE,0,size,NULL);		\
			if (hmap==NULL)					\
			{						\
				*ptr_addr=NULL;				\
			}						\
			else						\
			{						\
				*ptr_addr=(char *)MapViewOfFile(hmap,	\
					FILE_MAP_WRITE,0,0,size);	\
			}						\
		}							\
	}
#define REUSE_SHARE_MEMORY(ptr_addr,id,size)	ALLOC_SHARE_MEMORY(ptr_addr,id,size)
#endif

#ifdef VOS
#define ALLOC_SHARE_MEMORY(ptr_addr,id,size)	{*ptr_addr=NULL;}
#define REUSE_SHARE_MEMORY(ptr_addr,id,size)	{*ptr_addr=NULL;}
#endif

/////////////////////////////////////////////////////////////////////////
///�����̵߳�����
/////////////////////////////////////////////////////////////////////////


#ifdef WINDOWS
#define CREATE_PTHREAD(ptrThreadHandle,ptrThreadId, ptrFunc, ptrArgument)   ( (*ptrThreadHandle = CreateThread(NULL,0, (LPTHREAD_START_ROUTINE)ptrFunc,ptrArgument,0,ptrThreadId))==NULL?0:1)
#endif

#ifdef UNIX
#define CREATE_PTHREAD(ptrThreadHandle,ptrThreadId, ptrFunc, ptrArgument)  (pthread_create(ptrThreadHandle, NULL,ptrFunc,ptrArgument)?0:1)
#endif

#ifdef VOS
#define CREATE_PTHREAD(ptrThreadHandle,ptrThreadId, ptrFunc, ptrArgument)  0
#endif

//////////////////////////////////////////////////////////////////////////
/// �̺߳�����������ͬ
//////////////////////////////////////////////////////////////////////////
#ifdef WIN32
#define TheadEntry		\
		DWORD WINAPI _ThreadEntry(LPVOID pParam)
#else
#define TheadEntry		\
		void * _ThreadEntry(void *pParam)
#endif
 
//**********************************************************************
//�����ٽ���������
//**********************************************************************
#ifdef WINDOWS
#define CRITICAL_VAR		CRITICAL_SECTION
#define INIT_CRITICAL_VAR(v)	InitializeCriticalSection(&(v))
#define ENTER_CRITICAL(v)	EnterCriticalSection(&(v))
#define LEAVE_CRITICAL(v)	LeaveCriticalSection(&(v))
#define DELETE_CRITICAL_VAR(v)	DeleteCriticalSection(&(v))
#endif

#ifdef UNIX
#define CRITICAL_VAR		pthread_mutex_t
#define INIT_CRITICAL_VAR(v)	pthread_mutex_init(&(v), NULL);
#define ENTER_CRITICAL(v)	pthread_mutex_lock(&(v))
#define LEAVE_CRITICAL(v)	pthread_mutex_unlock(&(v))
#define DELETE_CRITICAL_VAR(v)	pthread_mutex_destroy(&(v));
#endif

/////////////////////////////////////////////////////////////////////////
///��windows������dll
/////////////////////////////////////////////////////////////////////////
#ifdef WINDOWS
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT 
#endif

/////////////////////////////////////////////////////////////////////////
///����ȷʱ�������
/////////////////////////////////////////////////////////////////////////
#ifdef WINDOWS
#define GET_ACCURATE_TIME(v) 			\
	{					\
		SYSTEMTIME t;			\
		GetLocalTime(&t);		\
		v=t.wHour*3600000+		\
			t.wMinute*60000+	\
			t.wSecond*1000+		\
			t.wMilliseconds;	\
	}
#endif

#ifdef UNIX
#define GET_ACCURATE_TIME(v)			\
	{					\
		struct timeval t;		\
		gettimeofday(&t,NULL);		\
		tm now;							\
		LocalTime(&t.tv_sec, &now);		\
		v=now.tm_hour*3600000+now.tm_min*60000+now.tm_sec*1000+		\
			t.tv_usec/1000;		\
	}
#endif

inline void GetPreciseTime(DWORD &dwSec, DWORD &dwUsec)
{
#ifdef WIN32	
	struct _timeb timebuffer;
	_ftime(&timebuffer);
	dwSec = (DWORD)timebuffer.time;	
	dwUsec = (DWORD)timebuffer.millitm * 1000;
#else
	struct timeval timeout;
    gettimeofday(&timeout, 0);
	dwSec = timeout.tv_sec;	
	dwUsec = timeout.tv_usec;
#endif
}

/////////////////////////////////////////////////////////////////////////
///�������ϵ�����
/////////////////////////////////////////////////////////////////////////
#define DOUBLE_NaN DBL_MAX

/////////////////////////////////////////////////////////////////////////
///���ֳ��ú���������
/////////////////////////////////////////////////////////////////////////
///��Windows�£�������Ҫʹ��Sleep��������sleep������ͳһ��SLEEP
#ifdef WINDOWS
#define SLEEP(ms) Sleep(ms)
#else
#define SLEEP(ms) usleep((ms)*1000)
#endif

///Sleep ʹ�õĲ�����һ��������˵����Sleep������Ϊ�����
#ifdef WINDOWS
#define SLEEP_SECONDS(seconds) Sleep((seconds)*1000)
#else
#define SLEEP_SECONDS(seconds) sleep(seconds)
#endif

///��ȡ��ǰ�̺߳�
#ifdef WINDOWS 
#define GetThreadID() ::GetCurrentThreadId()
#else
#define GetThreadID() ::pthread_self()
#endif

///�ȴ��źŵĸı�
#ifdef WINDOWS
#define WaitForObject(handle) (WaitForSingleObject(handle,INFINITE) != 0) 
#else
#define WaitForObject(handle) (pthread_join(handle, NULL) == 0)
#endif


#ifdef WINDOWS
#define GetSyncTime(currentTime,currentMilTime)	\
		currentMilTime = GetTickCount()/1000;		\
		currentTime = GetTickCount();
#else	
#define GetSyncTime(currentTime,currentMilTime)	\
		struct timeval timeout;					\
		gettimeofday(&timeout, 0);				\
		currentTime = timeout.tv_sec;			\
		currentMilTime = timeout.tv_sec*1000 + timeout.tv_usec/1000;
#endif
///��Windows�£�������Ҫ���¶���MAX��MIN��
#ifdef WINDOWS
#ifndef MAX
#define MAX(a,b) max(a,b)
#endif
#ifndef MIN
#define MIN(a,b) min(a,b)
#endif
#endif
#ifdef UNIX
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif

///windows�µ�isnan����
#ifdef WINDOWS
#define isnan _isnan
#endif

/////////////////////////////////////////////////////////////////////////
///Difference for fpos_t
/////////////////////////////////////////////////////////////////////////
#ifdef LINUX
#define FPOS_SET(fposValue,longValue)	(fposValue).__pos=(longValue)
#define FPOS_GET(fposValue)	(fposValue).__pos
#else
#define FPOS_SET(fposValue,longValue)	(fposValue)=(longValue)
#define FPOS_GET(fposValue)	(fposValue)
#endif

/////////////////////////////////////////////////////////////////////////
///����ָ���ϵĲ��
/////////////////////////////////////////////////////////////////////////
///��Windows�£�������Ҫʹ��pack(1)������pragma��ʾ��Ҫѹ���ṹ������ƽ̨�µ���Ӧ
///���ܶ��ڱ���ѡ����ʵ��
#ifdef WINDOWS
//#pragma pack(1)
#endif

///��Vos�£�������Ҫʹ��pack(1)?�����pragma��ʾ��Ҫѹ���ṹ������ƽ̨�µ���Ӧ
///���ܶ��ڱ���ѡ����ʵ��
#ifdef VOS
//#pragma pack(1)
#endif

#ifdef WIN32
extern char	*optarg;		// global argument pointer
extern int	optind; 		// global argv index

extern int getopt(int argc, char *argv[], char *optstring);

#endif

// �õ���ǰϵͳʱ�ӣ���ȷ�����루Ŀǰ��λ�������ֻ���������ֵ��
extern DWORD GetSysClock();

// �õ���ǰϵͳʱ�ӣ���ȷ��΢��
extern QWORD GetSysMicroClock();

// ���뾫ȷ�����Ĺ���
#ifdef RTT_MEASURE

#define MAX_RTT_MEASURE_NUM 10000000

struct TRttMeasure
{
	DWORD SequenceNo;
	QWORD BeginClock;
	QWORD EndClock;
	QWORD BizClock1;
	QWORD BizClock2;
	QWORD BizClock3;
	QWORD BizClock4;
};	

extern TRttMeasure** g_RttMeasures;
extern DWORD g_FrontSubjectID;
extern void DumpRttMeasure();

#endif

// �����ǶԲ���ȫ�ĺ����İ�ȫ�汾���з�װ
#ifdef WINDOWS
	#if _MSC_VER <= 1200
		#define LocalTime(time, result) {struct tm* tmVC6 = localtime(time); *result = *tmVC6;} 	
	#else
		#define LocalTime(time, result) localtime_s(result, time) 
	#endif
#else
	#define LocalTime(time, result) localtime_r(time, result) 
#endif

// Added by Henchi, 20140610
#ifdef WINDOWS
	#if _MSC_VER <= 1200
		#define GMTime(time, result) {struct tm* tmVC6 = gmtime(time); *result = *tmVC6;} 	
	#else
		#define GMTime(time, result) gmtime_s(result, time) 
	#endif
#else
	#define GMTime(time, result) gmtime_r(time, result) 
#endif

#define GlobalTime(time, result) GMTime(time, result)

#ifdef WINDOWS
#if _MSC_VER <= 1200
#define STRTOK(buf,delim,point)	strtok(buf,delim) 	
#else
#define STRTOK	strtok_s
#endif
#else
#define STRTOK	strtok_r
#endif
extern void InetNtoA(struct in_addr ina, char* result);

#endif
