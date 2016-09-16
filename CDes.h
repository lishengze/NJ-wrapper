/////////////////////////////////////////////////////////////////////////
///@system OraclePass
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CCrypto.h
///@brief������CBase64�����ࡢdes��triple des������
///@history 
///20070622 �ż̺�		�������ļ�
///20070622 �ż̺�		DES and Triple-DES Encryption and Decryption, from efgh.com/software
///20070702 ���ٻ�		����triple des
/////////////////////////////////////////////////////////////////////////

#ifndef CDES_H
#define CDES_H

const int DES_KEY_SIZE      =  56;
const int DES_DATA_SIZE     =  64;
const int DES_SBUFFER_SIZE  =  48;
const int DES_ROUNDS =  16;

/////////////////////////////////////////////////////////////////////////
///Base64�����İ�װ�ࡣ
/////////////////////////////////////////////////////////////////////////
class CBase64 {
public:
	//���ر�������ASCII�ַ������ȡ�
	int Encode(const unsigned char *pSrc, char *pDst, int nSrcLen, int nMaxLineLen=2000);
	//���ر������Ķ������ַ������ȡ�
	int Decode(const char *pSrc, unsigned char *pDst, int nSrcLen);
};

class triple_des;

/////////////////////////////////////////////////////////////////////////
///des���㷨ʵ�֣��ⲿ��������password()��EncryptBase64()������
/////////////////////////////////////////////////////////////////////////
class des
{
private:
	const char *xmix(const char *, 
		unsigned char [DES_DATA_SIZE],
		const unsigned char [DES_KEY_SIZE]);
	void encrypt_decrypt(unsigned char [DES_DATA_SIZE], int);
	unsigned char compressed_shifted_key[DES_ROUNDS][DES_SBUFFER_SIZE];
	CBase64 base64;

public:
	void initialize(const unsigned char[DES_KEY_SIZE]);
	void password(const char *);
	void encrypt(unsigned char data[DES_DATA_SIZE]) {
		encrypt_decrypt(data, 1);
	}
	void decrypt(unsigned char data[DES_DATA_SIZE]) {
		encrypt_decrypt(data, 0);
	}
	char* encryptbuffer(const char *buff,int size,bool isEncrypt);

public:
	///�ӽ��ܺ�����
	///����ʹ��Base64��ʽ���롣
	///@para pSrc	���룺������Ϊ���ģ�������ΪBase64���������ġ�
	///@para pDst	���򣺼�����ΪBase64���������ģ�������Ϊ���ġ�
	///@para nSrcLen	�������ݳ��ȡ�
	///@para isEncrypt	1Ϊ���ܣ�0Ϊ���ܡ�
	void EncryptBase64(const char *pSrc, char *pDst, int nSrcLen, bool isEncrypt);
	
	friend class triple_des;
};

/////////////////////////////////////////////////////////////////////////
///triple des���㷨ʵ�֣��ⲿ��������password()��EncryptBase64()������
/////////////////////////////////////////////////////////////////////////
class triple_des
{
private:
    des part[3];
    void encrypt_decrypt(unsigned char [DES_DATA_SIZE], int);
	CBase64 base64;
public:
	void initialize(const unsigned char key[3*DES_KEY_SIZE]) {
		part[0].initialize(key);
		part[1].initialize(key + DES_KEY_SIZE);
		part[2].initialize(key + 2*DES_KEY_SIZE);
    }
    void password(const char *);
    void encrypt(unsigned char data[DES_DATA_SIZE]) {
		part[0].encrypt(data);
		part[1].decrypt(data);
		part[2].encrypt(data);
    }
    void decrypt(unsigned char data[DES_DATA_SIZE]) {
		part[2].decrypt(data);
		part[1].encrypt(data);
		part[0].decrypt(data);
    }
public:
	char* encryptbuffer(const char *buff,int size,bool isEncrypt);
	///�ӽ��ܺ�����
	///����ʹ��Base64��ʽ���롣
	///@para pSrc	���룺������Ϊ���ģ�������ΪBase64���������ġ�
	///@para pDst	���򣺼�����ΪBase64���������ģ�������Ϊ���ġ�
	///@para nSrcLen	�������ݳ��ȡ�
	///@para isEncrypt	1Ϊ���ܣ�0Ϊ���ܡ�
	void EncryptBase64(const char *pSrc, char *pDst, int nSrcLen, bool isEncrypt);
};

#endif
