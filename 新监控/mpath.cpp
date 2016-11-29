/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file mpath.h
///@brief ʵ���˿�ƽ̨��·������
///@history 
///20060303	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#include "platform.h"

void convertPath(char *target, const char *source)
{
	const char *s;
	char *t;
	for (s=source, t=target; ((s-source)<MAX_PATH_LEN) && (*s!='\0'); s++, t++)
	{
		if (strchr(ALL_SPLITS,*s)!=NULL)
		{
			*t=PATH_SPLIT;
		}
		else
		{
			*t=*s;
		}
	}
	*t='\0';
}
	
FILE *mfopen(const char *filename, const char *mode)
{
	char actualName[MAX_PATH_LEN+1];
	convertPath(actualName,filename);
	return fopen(actualName,mode);
}
