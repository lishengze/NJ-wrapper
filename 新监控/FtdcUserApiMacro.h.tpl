!!let exchangeid=""!!
!!let functionid=""!!
!!let macroid=""!!
!!let fileid=""!!
!!enter exchangeinfo!!
!!travel self!!
!!if @pumpid==0!!
!!let exchangeid=@name!!
!!elseif @pumpid==1!!
!!let functionid=@name!!
!!elseif @pumpid==2!!
!!let macroid=@name!!
!!elseif @pumpid==3!!
!!let fileid=@name!!
!!endif!!
!!next!!
!!leave!!
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
#define FTDCUSERAPI C!!@functionid!!FtdcUserApi
#endif
#if !defined(FTDCUSERSPI)
#define FTDCUSERSPI C!!@functionid!!FtdcUserSpi
#endif
#if !defined(FTDCREQUSERLOGINFIELD)
#define FTDCREQUSERLOGINFIELD C!!@functionid!!FtdcReqUserLoginField
#endif
#if !defined(FTDCDEPTHMARKETDATAFIELD)
#define FTDCDEPTHMARKETDATAFIELD C!!@functionid!!FtdcDepthMarketDataField
#endif
#if !defined(FTDCDISSEMINATIONINFOFIELD)
#define FTDCDISSEMINATIONINFOFIELD C!!@functionid!!FtdcDisseminationField
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
#define INTERFACE_PRODUCT_INFO "!!@macroid!! UserAPI v"MAJOR_VERSION"."MINOR_VERSION" "SUFFIX_STR
#endif
#ifndef FTDCUSERAPI_H
#define FTDCUSERAPI_H "!!@fileid!!FtdcUserApi.h"
#endif
#endif