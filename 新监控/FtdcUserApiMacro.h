/////////////////////////////////////////////////////////////////////////
///@system ��һ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file FtdcUserApiMacro.h
///@brief �����˿ͻ��˽ӿ������ֽ������ĺ�
///@history 
///20070308	�ܾ�	�������ļ�
///20070614 �Ժ��	ͳһ�汾��ʶ
/////////////////////////////////////////////////////////////////////////
#if !defined(_FTDCUSERAPIMACRO_H)
#define _FTDCUSERAPIMACRO_H
#if !defined(FTDCUSERAPI)
#define FTDCUSERAPI CShfeFtdcUserApi
#endif
#if !defined(FTDCUSERSPI)
#define FTDCUSERSPI CShfeFtdcUserSpi
#endif
#if !defined(FTDCREQUSERLOGINFIELD)
#define FTDCREQUSERLOGINFIELD CShfeFtdcReqUserLoginField
#endif
#if !defined(FTDCDEPTHMARKETDATAFIELD)
#define FTDCDEPTHMARKETDATAFIELD CShfeFtdcDepthMarketDataField
#endif
#if !defined(FTDCDISSEMINATIONINFOFIELD)
#define FTDCDISSEMINATIONINFOFIELD CShfeFtdcDisseminationField
#endif

#ifndef MAJOR_VERSION
#define MAJOR_VERSION "1"
#endif
#ifndef MINOR_VERSION
#define MINOR_VERSION "22"
#endif
#ifndef SUFFIX_STR
#define SUFFIX_STR  ""
#endif

#ifndef INTERFACE_PRODUCT_INFO
#define INTERFACE_PRODUCT_INFO "SHFE UserAPI v"MAJOR_VERSION"."MINOR_VERSION" "SUFFIX_STR
#endif
#ifndef FTDCUSERAPI_H
#define FTDCUSERAPI_H "FtdcUserApi.h"
#endif
#endif
