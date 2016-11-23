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
///@file !!@fileid!!FtdcUserApiImpl.cpp
///@brief ʵ���˿ͻ��˽ӿ�
///@history 
///20060106	�Ժ��		�������ļ�
// 20110624 ����        NT-0139 �ӿ���Ӧʱ��
// 20120726 ����        ���ڲ���ȫ���������˶�Ӧ��ȫ�汾�ķ�װ��localtime
// 20120807 ��Ң��      NT-0170 �����غ���־��������
/////////////////////////////////////////////////////////////////////////

#include "public.h"
#include "!!@fileid!!FtdcUserApiImpl.h"
CFtdcUserApiImpl::CFtdcUserApiImpl(const char *pszFlowPath, const char *pszUserApiType, CSelectReactor *pReactor)
:CFtdcUserApiImplBase(pszFlowPath, pszUserApiType, pReactor)
{
}

!!enter FTD!!
!!travel packages!!
!!let package_name=@name!!
!!if !strncmp(@name,"Req",3) && strcmp(@name,"ReqUserLogin")!!
///!!@comment!!
int CFtdcUserApiImpl::!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!C!!@functionid!!Ftdc!!@name!!Field *p!!@name!!!!next!!, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_!!@package_name!!, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
!!travel self!!
	CFTD!!@name!!Field !!@name!!Field;
	memcpy(&!!@name!!Field, p!!@name!!, sizeof(CFTD!!@name!!Field));
	FTDC_ADD_FIELD(&m_reqPackage, &!!@name!!Field);
	!!if !strncmp(@package_name, "ReqQry", 6) !!
	!!endif!!
!!next!!

!!if !strncmp(@package_name, "ReqQry", 6) !!
	int nRet = RequestToQueryFlow();
!!else!!
	int nRet = RequestToDialogFlow();
	if(m_fpRequstDump != NULL)
	{
		char szTimeBuffer[20];
		time_t dwCurrTime = m_pReactor->Time();
		struct tm currTime;
		LocalTime(&dwCurrTime, &currTime);
		strftime(szTimeBuffer, sizeof(szTimeBuffer),
			"%Y%m%d %H:%M:%S",&currTime);
		fprintf(m_fpRequstDump, "%s,!!@name!!,%d,", szTimeBuffer, nRet);
	!!travel self!!
		FIELD_TO_STRING((char *)p!!@name!!, &CFTD!!@name!!Field::m_Describe, m_fpRequstDump);
	!!next!!
		fprintf(m_fpRequstDump, "\n");
		fflush(m_fpRequstDump);
	}
!!endif!!	
	m_mutexAction.UnLock();
	
	return nRet;
}
!!endif!!
!!next!!

void CFtdcUserApiImpl::HandleResponse(CFTDCPackage *pMessage, WORD nSequenceSeries)
{

	switch(pMessage->GetTID()) {
!!travel packages!!
!!if !strncmp(@name,"Rsp",3)!!
	///!!@comment!!
	case FTD_TID_!!@name!!:
		On!!@name!!(pMessage, nSequenceSeries);
		break;
!!elseif !strncmp(@name,"Rtn",3)!!
	///!!@comment!!
	case FTD_TID_!!@name!!:
		On!!@name!!(pMessage, nSequenceSeries);
		break;
!!elseif !strncmp(@name,"ErrRtn",6)!!
	///!!@comment!!
	case FTD_TID_!!@name!!:
		On!!@name!!(pMessage, nSequenceSeries);
		break;
!!elseif !strncmp(@name,"Intl",4)!!
	///!!@comment!!
	case FTD_TID_!!@name!!:
		On!!@name!!(pMessage, nSequenceSeries);
		break;
!!endif!!
!!next!!
	default:
		break;
	}
}

C!!@functionid!!FtdcUserApi *C!!@functionid!!FtdcUserApi::CreateFtdcUserApi(const char *pszFlowPath,
													const char *pszUserApiType)
{
	return new CFtdcUserApiImpl(pszFlowPath, pszUserApiType, new CSelectReactor(true));
}

const char *C!!@functionid!!FtdcUserApi::GetVersion(int &nMajorVersion, int &nMinorVersion)
{
		nMajorVersion = atoi(MAJOR_VERSION);
		nMinorVersion = atoi(MINOR_VERSION);
		return "!!@exchangeid!! User Api V"MAJOR_VERSION"."MINOR_VERSION" Build "__DATE__" "__TIME__" "SUFFIX_STR;
}


///����Ӧ��
void CFtdcUserApiImpl::OnRspError(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	C!!@functionid!!FtdcRspInfoField *pRspInfoField = (C!!@functionid!!FtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	if (m_pSpi != NULL)
	{
		m_pSpi->OnRspError(pRspInfoField, pMessage->GetRequestId(), true);
	}
}

!!travel packages!!
!!let package_name=@name!!
!!if !strncmp(@name,"Rsp",3) && strcmp(@name, "RspError")!!
///!!@comment!!
void CFtdcUserApiImpl::On!!@name!!(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
!!if !strcmp(@name, "RspUserLogin")!!
	CUserSubscriberMap::iterator it;
	CFTDUserCommFluxControlField UserCommFluxControlField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &UserCommFluxControlField) > 0)
	{
		C!!@functionid!!FtdcUserCommFluxControlField *pUserCommFluxControlField = (C!!@functionid!!FtdcUserCommFluxControlField *)&UserCommFluxControlField;
		if(pUserCommFluxControlField!=NULL)
		{
			CFtdcUserSubscriber *pFtdcUserSubscriber=NULL;
			for(it=m_mapSubscriber.begin();it!=m_mapSubscriber.end();it++)
			{
				pFtdcUserSubscriber=(CFtdcUserSubscriber *)it->second;
				if(pUserCommFluxControlField->MaxTradeCommFlux>0&&pFtdcUserSubscriber->GetSequenceSeries()==TSS_DIALOG)
				{
					pFtdcUserSubscriber->SetTradeMaxCommFlux(pUserCommFluxControlField->MaxTradeCommFlux);
				}
				if(pUserCommFluxControlField->MaxTradeOnWayCommFlux>0&&pFtdcUserSubscriber->GetSequenceSeries()==TSS_DIALOG)
				{
					pFtdcUserSubscriber->SetTradeMaxOnWayCommFlux(pUserCommFluxControlField->MaxTradeOnWayCommFlux);
				}
				if(pUserCommFluxControlField->MaxQueryCommFlux>0&&pFtdcUserSubscriber->GetSequenceSeries()==TSS_QUERY)
				{
					pFtdcUserSubscriber->SetQueryMaxCommFlux(pUserCommFluxControlField->MaxQueryCommFlux);
				}
				if(pUserCommFluxControlField->MaxQueryOnWayCommFlux>0&&pFtdcUserSubscriber->GetSequenceSeries()==TSS_QUERY)
				{
					pFtdcUserSubscriber->SetQueryMaxOnWayCommFlux(pUserCommFluxControlField->MaxQueryOnWayCommFlux);
				}
			}
		}
	}
!!endif!!
	CFTDRspInfoField rspInfoField;
	C!!@functionid!!FtdcRspInfoField *pRspInfoField = (C!!@functionid!!FtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
!!travel self!!
!!if strcmp(@name, "RspInfo")!!
	CFTD!!@name!!Field !!@name!!;
	C!!@functionid!!Ftdc!!@name!!Field *p!!@name!! = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTD!!@name!!Field::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&!!@name!!);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			p!!@name!! = (C!!@functionid!!Ftdc!!@name!!Field *)&!!@name!!;
			m_pSpi->On!!@package_name!!(p!!@name!!, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	!!if strncmp(@name, "RspQry", 6) && strcmp(@name, "RspUserLogout") && strcmp(@name, "RspUserLogin")!!
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,On!!@package_name!!,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&!!@name!!, &CFTD!!@name!!Field::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
	!!endif	
		
	}
	
	if (p!!@name!! == NULL && m_pSpi != NULL)
	{
		m_pSpi->On!!@package_name!!(p!!@name!!, pRspInfoField, pMessage->GetRequestId(), true);
	}
!!endif!!
!!next!!
}

!!elseif !strncmp(@name,"Rtn",3)!!
///!!@comment!!
void CFtdcUserApiImpl::On!!@name!!(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
!!travel self!!
	CFTD!!@name!!Field !!@name!!;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTD!!@name!!Field::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&!!@name!!);
		!!if !strcmp(@name, "DepthMarketData")!!
		CFtdcUserApiImplBase::OnRtnDepthMarketData(&!!@name!!, nSequenceSeries);
		!!endif!!
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,On!!@package_name!!,", szTimeBuffer);
			FIELD_TO_STRING((char *)&!!@name!!, &CFTD!!@name!!Field::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			m_pSpi->On!!@package_name!!((C!!@functionid!!Ftdc!!@name!!Field *)&!!@name!!);
		}
		itor.Next();
	}
!!next!!
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

!!elseif !strncmp(@name,"ErrRtn",6)!!
///!!@comment!!
void CFtdcUserApiImpl::On!!@name!!(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
	CFTDRspInfoField rspInfoField;
	C!!@functionid!!FtdcRspInfoField *pRspInfoField = (C!!@functionid!!FtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
!!travel self!!
!!if strcmp(@name, "RspInfo")!!
	CFTD!!@name!!Field !!@name!!;
	C!!@functionid!!Ftdc!!@name!!Field *p!!@name!! = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTD!!@name!!Field::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&!!@name!!);
		itor.Next();
		if(m_fpResponseDump != NULL)
		{
			char szTimeBuffer[20];
			time_t dwCurrTime = m_pReactor->Time();
			struct tm currTime;
			LocalTime(&dwCurrTime, &currTime);
			strftime(szTimeBuffer, sizeof(szTimeBuffer),
				"%Y%m%d %H:%M:%S",&currTime);
			fprintf(m_fpResponseDump, "%s,On!!@package_name!!,", szTimeBuffer);
			if(pRspInfoField != NULL)
			{
				fprintf(m_fpResponseDump,"%d,%s,", pRspInfoField->ErrorID, pRspInfoField->ErrorMsg);
			}
			else
			{
				fprintf(m_fpResponseDump,",,");
			}
			FIELD_TO_STRING((char *)&!!@name!!, &CFTD!!@name!!Field::m_Describe, m_fpResponseDump);
			fprintf(m_fpResponseDump, "\n");
			fflush(m_fpResponseDump);
		}
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			p!!@name!! = (C!!@functionid!!Ftdc!!@name!!Field *)&!!@name!!;
			m_pSpi->On!!@package_name!!(p!!@name!!, pRspInfoField);
		}
	}
	
	if (p!!@name!! == NULL && m_pSpi != NULL)
	{
		m_pSpi->On!!@package_name!!(p!!@name!!, pRspInfoField);
	}
!!endif!!
!!next!!
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageEnd((int)nSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

!!endif!!
!!next!!

!!leave!!  
