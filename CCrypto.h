/////////////////////////////////////////////////////////////////////////
///@system OraclePass
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CCrypto.h
///@brief�����˽ӿ�IEncryptAlgorithm, ʵ����Des��TripleDes
///@history 
///20070622 �ż̺�		�������ļ�
///20070702 ���ٻ�		����CTripleDesAlgorithm
/////////////////////////////////////////////////////////////////////////
#ifndef CCRYPTO_H
#define CCRYPTO_H
#include<string.h>
#include "CDes.h"

/////////////////////////////////////////////////////////////////////////
///IEncryptoAlgorithmΪ�ӽ��ܵĽӿ��ࡣ���ṩ���ܺͽ������򷽷���
/////////////////////////////////////////////////////////////////////////
class IEncryptAlgorithm
{
public:
	///���캯��
	IEncryptAlgorithm(){};
	///�򹹺���
	virtual ~IEncryptAlgorithm(){};

	///���ܽӿ�
	///@param	pIn		�������ַ���
	///@param	pOut	���ܺ��ַ���
	virtual int Encrypt(char *pIn, char *pOut) = 0;
	///���ܽӿ�
	///@param	pIn		�������ַ���
	///@param	pOut	���ܺ��ַ���
	virtual int Decrypt(char *pIn, char *pOut) = 0;
};

/////////////////////////////////////////////////////////////////////////
///NoEncryptoAlgorithmΪ�ӿ�����һ������ʵ�֣���������Ŀ�ģ���������ƽ��ƽ����
/////////////////////////////////////////////////////////////////////////
class NoEncryptAlgorithm:public IEncryptAlgorithm
{
public:
	///�򹹺���
	virtual ~NoEncryptAlgorithm(){};

	///���ܽӿ�
	///@param	pIn		�������ַ���
	///@param	pOut	���ܺ��ַ���
	virtual int Encrypt(char *pIn, char *pOut) {
		strcpy(pOut, pIn);
		return 0;
	}
	///���ܽӿ�
	///@param	pIn		�������ַ���
	///@param	pOut	���ܺ��ַ���
	virtual int Decrypt(char *pIn, char *pOut) {
		strcpy(pOut, pIn);
		return 0;
	}
};

/////////////////////////////////////////////////////////////////////////
///ʵ��Des�㷨�Ľӿ��࣬�����üӽ����õĿ��
/////////////////////////////////////////////////////////////////////////
class CDesEncryptAlgorithm:public IEncryptAlgorithm
{
public:
	///���캯��
	CDesEncryptAlgorithm() {
		m_szPassword[0]=0;
	}
	///�������Ĺ��캯��
	CDesEncryptAlgorithm(const char *szPassword) {
		SetPassword(szPassword);
	}
	///�򹹺���
	virtual ~CDesEncryptAlgorithm(){};
	///���ܽӿ�
	///@param	pIn		�������ַ���
	///@param	pOut	���ܺ��ַ���
	virtual int Encrypt(char *pIn, char *pOut) {
		if (m_szPassword[0]==0) {
			strcpy(pOut, pIn);
			return 0;
		}
		crypto.EncryptBase64(pIn, pOut, strlen(pIn), true);
		return 0;
	}
	///���ܽӿ�
	///@param	pIn		�������ַ���
	///@param	pOut	���ܺ��ַ���
	virtual int Decrypt(char *pIn, char *pOut) {
		if (m_szPassword[0]==0) {
			strcpy(pOut, pIn);
			return 0;
		}
		
		crypto.EncryptBase64(pIn, pOut, strlen(pIn)-3, false);
		return 0;
	}
	///���üӽ����õĿ���
	virtual void SetPassword(const char *szPassword) {
		strcpy(m_szPassword, szPassword);
		crypto.password(m_szPassword);
	}
	bool IsEnOrDe(std::string item_value){
		if (item_value.substr(item_value.length()-3,3) == "@#$"){return true;}
		else return false;
	}
private:
	///des�㷨�ľ���ʵ��
 	des crypto;
	///des�㷨ʹ�õĿ���
	char m_szPassword[60];
};

/////////////////////////////////////////////////////////////////////////
///ʵ��TripleDes�㷨�Ľӿ��࣬�����üӽ����õĿ��
/////////////////////////////////////////////////////////////////////////
class CTripleDesEncryptAlgorithm:public IEncryptAlgorithm
{
public:
	///���캯��
	CTripleDesEncryptAlgorithm() {
		m_szPassword[0]=0;
	}
	///�������Ĺ��캯��
	CTripleDesEncryptAlgorithm(const char *szPassword) {
		SetPassword(szPassword);
	}
	///�򹹺���
	virtual ~CTripleDesEncryptAlgorithm(){};

	///���ܽӿ�
	///@param	pIn		�������ַ���
	///@param	pOut	���ܺ��ַ���
	virtual int Encrypt(char *pIn, char *pOut) {
		if (m_szPassword[0]==0) {
			strcpy(pOut, pIn);
			return 0;
		}
		crypto.EncryptBase64(pIn, pOut, strlen(pIn), true);
		return 0;
	}
	///���ܽӿ�
	///@param	pIn		�������ַ���
	///@param	pOut	���ܺ��ַ���
	virtual int Decrypt(char *pIn, char *pOut) {
		if (m_szPassword[0]==0) {
			strcpy(pOut, pIn);
			return 0;
		}
		crypto.EncryptBase64(pIn, pOut, strlen(pIn)-3, false);
		return 0;
	}
	///���üӽ����õĿ���
	virtual void SetPassword(const char *szPassword) {
		strcpy(m_szPassword, szPassword);
		crypto.password(m_szPassword);
	}
	///�ж��ַ���Ϊ���Ļ������ģ�trueΪ����
	bool IsEnOrDe(std::string item_value){
		if (item_value.substr(item_value.length()-3,3) == "@#$"){return true;}
		else return false;
	}
private:
	///triple des�㷨�ľ���ʵ��
 	triple_des crypto;
	///triple des�㷨ʹ�õĿ���
	char m_szPassword[60];
};

#endif
