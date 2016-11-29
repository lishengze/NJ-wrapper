/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file mpath.h
///@brief �����˿�ƽ̨��·������
///@history 
///20060303	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef MPATH_H
#define MPATH_H

#ifdef WINDOWS
#define PATH_SPLIT '\\'
#endif

#ifdef UNIX
#define PATH_SPLIT '/'
#endif

#define ALL_SPLITS "\\/$"

#define MAX_PATH_LEN 200
	
///ת��·��
///@param	target	Ŀ��
///@param	source	Դ
void convertPath(char *target, const char *source);
	
///�滻��׼��fopen����
FILE *mfopen(const char *filename, const char *mode);

#endif
