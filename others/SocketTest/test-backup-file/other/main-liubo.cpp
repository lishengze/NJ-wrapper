#include "FtdcUserApi.h"
#include "FtdData.h"
#include "CCrypto.h"
#include <stdio.h>

#define CRYPTO_KEY	"monitor"

class CUserApiHandler : public CShfeFtdcUserSpi
{
	virtual void OnRspError(CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	{
		printf("ID = %d, MSG = %s\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
	};


	virtual void OnRspUpdateCheck(CShfeFtdcRspUpdateCheckField *pRspUpdateCheck, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	{
		printf("FileName %s\n", pRspUpdateCheck->FileName);
		printf("Version %s\n", pRspUpdateCheck->Version);
		printf("Force %d\n", pRspUpdateCheck->Force);
		printf("IncUpgrade %d\n", pRspUpdateCheck->IncUpgrade);
		printf("FileDigest %s\n", pRspUpdateCheck->FileDigest);
		printf("Description %s\n", pRspUpdateCheck->Description);
		printf("FileSize %d\n", pRspUpdateCheck->FileSize);
	};


	virtual void OnRspGetUpdateFile(CShfeFtdcRspQryGetFileField *pRspQryGetFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		static FILE* fp = NULL;

		if (fp == NULL)
		{
			fp = fopen("recv.dat", "wb");
		}
		
		printf("bIsLast %d | ", bIsLast);

		if (pRspQryGetFile && fp != NULL)
		{
			printf("Version %s | ", pRspQryGetFile->Version);
			printf("FileName %s | ", pRspQryGetFile->FileName);
			printf("Offset %d | ", pRspQryGetFile->Offset);
			printf("Length %d\n", pRspQryGetFile->Length);

			fwrite((void*)(pRspQryGetFile->Comment),
				sizeof(char), pRspQryGetFile->Length, fp);
		}

		if (bIsLast && fp != NULL)
		{
			fflush(fp);
			fclose(fp);
			fp = NULL;
		}
	}

	virtual void OnRspUserPasswordUpdate(
		CShfeFtdcUserPasswordUpdateField *pUserPasswordUpdate, 
		CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		printf("ID = %d, MSG = %s\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
	}

	virtual void OnRspUserLogout(
		CShfeFtdcRspUserLogoutField *pRspUserLogout, 
		CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	{
		printf("ID = %d, MSG = %s\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		printf("UserID = %s, ParticipantID = %s\n", pRspUserLogout->UserID, pRspUserLogout->ParticipantID);
	}

	virtual void OnRspUserLogin(
		CShfeFtdcRspUserLoginField *pRspUserLogin, 
		CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	{
		printf("ID = %d, MSG = %s\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		printf("UserID = %s, ParticipantID = %s, Role = %d, Date = %s, Time = %s\n", 
			pRspUserLogin->UserID, pRspUserLogin->ParticipantID, pRspUserLogin->UserFlowSize,
			pRspUserLogin->ActionDay, pRspUserLogin->LoginTime);
	}


	virtual void OnRtnWarningEventTopic(CShfeFtdcRtnWarningEventField *pRtnWarningEvent) 
	{
		static int i = 0;

		printf( "================================ %d\n", ++i);

		printf( "MonDate = %s\n", pRtnWarningEvent->MonDate);
		printf( "MonTime = %s\n", pRtnWarningEvent->MonTime);
		printf( "OccurDate = %s\n", pRtnWarningEvent->OccurDate);
		printf( "OccurTime = %s\n", pRtnWarningEvent->OccurTime);
		printf( "EvendID = %d\n", pRtnWarningEvent->EvendID);
		printf( "ProcessFlag = %s\n", pRtnWarningEvent->ProcessFlag);
		printf( "-------------------------------------\n");
		printf( "EventName = %s\n", pRtnWarningEvent->EventName);
		printf( "ObjectID = %s\n", pRtnWarningEvent->ObjectID);
		printf( "IPAddress = %s\n", pRtnWarningEvent->IPAddress);
		printf( "EventNum = %d\n", pRtnWarningEvent->EventNum);
		printf( "FullEventName = %s\n", pRtnWarningEvent->FullEventName);
		printf( "WarningLevel = %s\n", pRtnWarningEvent->WarningLevel);
		printf( "EventDes = %s\n", pRtnWarningEvent->EventDes);
		printf( "EventDealDes = %s\n", pRtnWarningEvent->EventDealDes);
		printf( "EventType = %d\n", pRtnWarningEvent->EventType);
		printf( "EventCount = %d\n", pRtnWarningEvent->EventCount);

		printf( "====================================\n");
	}

	virtual void OnRtnObjectAttrTopic(CShfeFtdcRtnObjectAttrField *pRtnObjectAttr) 
	{
		static int i = 0;
		printf("OnRtnObjectAttrTopic %d\n", ++i);
	}

	virtual void OnRtnObjectAttrDigit(CShfeFtdcRtnObjectAttrDigitField *pRtnObjectAttrDigit)
	{
		printf( "==========OnRtnObjectAttrDigit===========\n\n\n\n");
		printf("SystemID %d\n", pRtnObjectAttrDigit->SystemID);
		printf("ObjectID %d\n", pRtnObjectAttrDigit->ObjectID);
		printf("AttrType %d\n", pRtnObjectAttrDigit->AttrType);
		printf("Seconds %d\n", pRtnObjectAttrDigit->Seconds);
		printf("ValueType %d\n", pRtnObjectAttrDigit->ValueType);
		printf("AttrValue %s\n", pRtnObjectAttrDigit->AttrValue);
	};

	virtual void OnRtnWarningEventDigit(CShfeFtdcRtnWarningEventDigitField *pRtnWarningEventDigit) 
	{
		printf("EventID = %d\n", pRtnWarningEventDigit->EvendID);
		printf("Seconds = %d\n", pRtnWarningEventDigit->Seconds);
		printf("ProcessFlag = %s\n", pRtnWarningEventDigit->ProcessFlag);
	};

	virtual void OnRspQryObjectAttrDigit(CShfeFtdcRspObjectAttrDigitField *pRspObjectAttrDigit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (pRspObjectAttrDigit != NULL)
		{
			printf( "==========OnRspQryObjectAttrDigit===========\n\n\n\n");
			printf("Seconds %d\n", pRspObjectAttrDigit->Seconds);
			printf("AttrValue %s\n", pRspObjectAttrDigit->AttrValue);
			printf("IsLast = %d\n", bIsLast);
		}

		if (pRspInfo != NULL)
		{
			printf("ErrorID = %d, ErrorMsg = %s\n",
				pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		}

		if (pRspObjectAttrDigit == NULL && pRspInfo == NULL)
		{
			printf("Empty PKG isLast = %d\n", bIsLast);
		}
	};

	virtual void OnRspAddUser(CShfeFtdcRspAddUserField *pRspAddUser, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	{
		if (pRspInfo != NULL)
		{
			printf("ErrorID = %d, ErrorMsg = %s\n",
				pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		}

		printf("UserID = %s, PartID = %s\n",
			pRspAddUser->UserID, pRspAddUser->PartID);
	};

	virtual void OnRspDelUser(CShfeFtdcRspDelUserField *pRspDelUser, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	{
		if (pRspInfo != NULL)
		{
			printf("ErrorID = %d, ErrorMsg = %s\n",
				pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		}

		printf("UserID = %s, PartID = %s\n",
			pRspDelUser->UserID, pRspDelUser->PartID);
	};

	virtual void OnRspUpdateUser(CShfeFtdcRspUpdateUserField *pRspUpdateUser, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	{
		if (pRspInfo != NULL)
		{
			printf("ErrorID = %d, ErrorMsg = %s\n",
				pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		}

		printf("UserID = %s, PartID = %s\n",
			pRspUpdateUser->UserID, pRspUpdateUser->PartID);
	};

	///获取用户列表应答
	virtual void OnRspGetUserList(CShfeFtdcRspGetUserListField *pRspGetUserList, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	{
		if (pRspInfo != NULL)
		{
			printf("ErrorID = %d, ErrorMsg = %s\n",
				pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		}
		if (pRspGetUserList != NULL)
		{
			printf("UserID = %s, PartID = %s, Role = %d, Name = %s, Mobile = %s, EMail = %s, Status = %d\n",
				pRspGetUserList->UserID, pRspGetUserList->PartID,
				pRspGetUserList->Role, pRspGetUserList->Name,
				pRspGetUserList->Mobile, pRspGetUserList->EMail, pRspGetUserList->UserStatus);
		}
	};

	///添加会员应答
	virtual void OnRspAddParticipant(CShfeFtdcRspAddParticipantField *pRspAddParticipant, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (pRspInfo != NULL)
		{
			printf("ErrorID = %d, ErrorMsg = %s\n",
				pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		}
		if (pRspAddParticipant != NULL)
		{
			printf("PartID = %s\n",
				pRspAddParticipant->PartID);
		}
	};

	///删除会员应答
	virtual void OnRspDelParticipant(CShfeFtdcRspDelParticipantField *pRspDelParticipant, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (pRspInfo != NULL)
		{
			printf("ErrorID = %d, ErrorMsg = %s\n",
				pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		}
		if (pRspDelParticipant != NULL)
		{
			printf("PartID = %s\n",
				pRspDelParticipant->PartID);
		}
	};

	///更新会员应答
	virtual void OnRspUpdateParticipant(CShfeFtdcRspUpdateParticipantField *pRspUpdateParticipant, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	{
		if (pRspInfo != NULL)
		{
			printf("ErrorID = %d, ErrorMsg = %s\n",
				pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		}
		if (pRspUpdateParticipant != NULL)
		{
			printf("PartID = %s\n",
				pRspUpdateParticipant->PartID);
		}
	};

	///获取用户列表应答
	virtual void OnRspGetPartList(CShfeFtdcRspGetPartListField *pRspGetPartList, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (pRspInfo != NULL)
		{
			printf("ErrorID = %d, ErrorMsg = %s\n",
				pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		}
		if (pRspGetPartList != NULL)
		{
			printf("PartID = %s\n",
				pRspGetPartList->PartID);
		}
	};

	virtual void OnRspFeedback(CShfeFtdcRspFeedbackInfoField *pRspFeedbackInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	{
		if (pRspInfo != NULL)
		{
			printf("ErrorID = %d, ErrorMsg = %s\n",
				pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		}
		if (pRspFeedbackInfo != NULL)
		{
			printf("PartID = %d\n",
				pRspFeedbackInfo->ErrorID);
		}
	};

	///系统资源应答
	virtual void OnRspResourceSystem(CShfeFtdcRspResourceSystemField *pRspResourceSystem, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	{
		if (pRspInfo != NULL)
		{
			printf("ErrorID = %d, ErrorMsg = %s\n",
				pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		}
		if (pRspResourceSystem != NULL)
		{
			printf("SystemName = %s, SystemID=%d, PartID=%s, ObjectsID=%s\n",
				pRspResourceSystem->SystemName,
				pRspResourceSystem->SystemID,
				pRspResourceSystem->PartID,
				pRspResourceSystem->ObjectsID);
		}
	};

	///对象资源应答
	virtual void OnRspResourceObject(CShfeFtdcRspResourceObjectField *pRspResourceObject, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	{
		if (pRspInfo != NULL)
		{
			printf("ErrorID = %d, ErrorMsg = %s\n",
				pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		}
		if (pRspResourceObject != NULL)
		{
			printf("ObjectName = %s, ObjectID = %d, AttrTypesID=%s\n",
				pRspResourceObject->ObjectName,
				pRspResourceObject->ObjectID,
				pRspResourceObject->AttrTypesID);
		}
	};

	///指标资源应答
	virtual void OnRspResourceAttrType(CShfeFtdcRspResourceAttrTypeField *pRspResourceAttrType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (pRspInfo != NULL)
		{
			printf("ErrorID = %d, ErrorMsg = %s\n",
				pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		}
		if (pRspResourceAttrType != NULL)
		{
			printf("AttrTypeName = %s, AttrTypeID=%d, interval=%d, valueType=%d, comment=%s\n",
				pRspResourceAttrType->AttrTypeName,
				pRspResourceAttrType->AttrTypeID,
				pRspResourceAttrType->interval,
				pRspResourceAttrType->valueType,
				pRspResourceAttrType->comment);
		}
	};


	///时间同步
	virtual void OnRtnSyncTime(CShfeFtdcRtnSyncTimeField *pRtnSyncTime) 
	{
		printf("Seconds %d\n",
			pRtnSyncTime->Seconds);
	};

	///应答交易日
	virtual void OnRspTradeDay(CShfeFtdcRspTradeDayField *pRspTradeDay, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	{
		if (pRspInfo != NULL)
		{
			printf("ErrorID = %d, ErrorMsg = %s\n",
				pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		}
		if (pRspTradeDay != NULL)
		{
			printf("TaskDay=%s, TaskDayType=%d, TradeDay=%s, TradeDayType=%d\n\n\n",
				pRspTradeDay->TaskDay,
				pRspTradeDay->TaskDayType,
				pRspTradeDay->TradeDay,
				pRspTradeDay->TradeDayType);
		}
	};

	///交易日切换
	virtual void OnRtnTradeDay(CShfeFtdcRtnTradeDayField *pRtnTradeDay) 
	{
		if (pRtnTradeDay != NULL)
		{
			printf("TaskDay=%s, TaskDayType=%d, TradeDay=%s, TradeDayType=%d\n\n\n",
				pRtnTradeDay->TaskDay,
				pRtnTradeDay->TaskDayType,
				pRtnTradeDay->TradeDay,
				pRtnTradeDay->TradeDayType);
		}
	};

};


int main()
{
	char des[256] = {0};

	CDesEncryptAlgorithm DesEncrypt;
	DesEncrypt.SetPassword(CRYPTO_KEY);

	CShfeFtdcUserApi *m_api = CShfeFtdcUserApi::CreateFtdcUserApi();
	m_api->RegisterSpi(new CUserApiHandler());
	m_api->RegisterFront("tcp://172.1.128.144:19944");
	//m_api->RegisterFront("tcp://172.1.128.144:18844");
	//m_api->RegisterFront("tcp://172.1.128.140:12345");
	//m_api->RegisterFront("tcp://172.1.128.144:19944");

	m_api->SubscribePrivateTopic(TERT_RESUME);

	m_api->Init();

	while (1)
	{
		int ch = getchar();

		if ( ch == 'a' )
		{
			CShfeFtdcReqUserLoginField field;
			char* p = "SFIT";
			strcpy(field.ParticipantID, p);
			p = "zhang.san";
			strcpy(field.UserID, p);
			memset(des, 0, sizeof(des));
			DesEncrypt.Encrypt("111111", des);
			memcpy(field.Password, des, 41);
			m_api->ReqUserLogin(&field, 0);
		}

		if ( ch == 'b' )
		{
			//请求系统映射关系
			CShfeFtdcReqResourceSystemField SystemField;
			char* p = "SFIT";
			strcpy(SystemField.PartID, p);
			SystemField.ResCount = 0;
			m_api->ReqResourceSystem(&SystemField, 0);

			CShfeFtdcReqResourceObjectField ObjectField;
			memset(&ObjectField, 0, sizeof(ObjectField));
			m_api->ReqResourceObject(&ObjectField, 0);

			CShfeFtdcReqResourceAttrTypeField AttrTypeField;
			memset(&AttrTypeField, 0, sizeof(AttrTypeField));
			m_api->ReqResourceAttrType(&AttrTypeField, 0);
		}

		if ( ch == 'c' )
		{
			CShfeFtdcReqTopicsInitField field;
			m_api->ReqTopicsInit(&field, 0);
		}

		if ( ch == 'd')
		{
			CShfeFtdcReqQrySubscriberField field;
			field.KeepAlive = 1;
			field.ObjectNum = 0;
			const char * p = "QHA.SYS01.os";
			memcpy(field.ObjectID, p, strlen(p)+1);
			m_api->ReqQrySubscriberTopic(&field, 1);
		}

		if ( ch == 'e')
		{
			CShfeFtdcReqQrySubscriberField field;
			field.KeepAlive = 0;
			const char * p = "QHA.SYS01.os";
			memcpy(field.ObjectID, p, strlen(p)+1);
			m_api->ReqQrySubscriberTopic(&field, 1);
		}

		if ( ch == 'f')
		{
			CShfeFtdcReqGetPartListField field;
			m_api->ReqGetPartList(&field, 0);
		}

		if ( ch == 'g')
		{
			CShfeFtdcReqGetUserListField field;
			const char * p = "QHA";
			memcpy(field.PartID, p, strlen(p)+1);
			memset(field.UserID, 0, 16);
			m_api->ReqGetUserList(&field, 0);
		}

		if ( ch == 'h')
		{
			CShfeFtdcReqAddParticipantField field;
			const char * p = "QHC";
			memcpy(field.PartID, p, strlen(p)+1);
			field.UserLimit = 4;
			m_api->ReqAddParticipant(&field, 0);
		}

		if ( ch == 'i')
		{
			CShfeFtdcReqDelParticipantField field;
			const char * p = "QHC";
			memcpy(field.PartID, p, strlen(p)+1);
			m_api->ReqDelParticipant(&field, 0);

		}

		if ( ch == 'j')
		{
			CShfeFtdcReqQrySubscriberField field;
			field.KeepAlive = 1;
			field.ObjectNum = 3;
			//const char * p = "QHA.SYS01.app";
			const char * p = "QHB.SYS01.app.tserver:OrderRate";
			memcpy(field.ObjectID, p, strlen(p)+1);
			p = "QHB.SYS01.app.tserver";
			m_api->ReqQrySubscriberTopic(&field, 1);
		}

		if ( ch == 'k')
		{
			CShfeFtdcReqQrySubscriberField field;
			field.KeepAlive = 0;
			//const char * p = "QHA.SYS01.app";
			const char * p = "QHB.SYS01.app.tserver:OrderRate";
			memcpy(field.ObjectID, p, strlen(p)+1);
			m_api->ReqQrySubscriberTopic(&field, 1);
		}

		if ( ch == 'l')
		{
			CShfeFtdcUserPasswordUpdateField field;
			memset(des, 0, sizeof(des));
			DesEncrypt.Encrypt("111111", des);
			memcpy(field.OldPassword, des, 41);

			memset(des, 0, sizeof(des));
			DesEncrypt.Encrypt("333333", des);
			memcpy(field.NewPassword, des, 41);

			memcpy(field.UserID, "QHA\\zhang.san", 16);
			memcpy(field.ParticipantID, "QHA", 11);

			m_api->ReqUserPasswordUpdate(&field, 0);
		}

		if ( ch == 'm')
		{
			CShfeFtdcUserPasswordUpdateField field;
			memset(des, 0, sizeof(des));
			DesEncrypt.Encrypt("333333", des);
			memcpy(field.OldPassword, des, 41);

			memset(des, 0, sizeof(des));
			DesEncrypt.Encrypt("111111", des);
			memcpy(field.NewPassword, des, 41);

			memcpy(field.UserID, "QHA\\zhang.san", 16);
			memcpy(field.ParticipantID, "QHA", 11);

			m_api->ReqUserPasswordUpdate(&field, 0);
		}



		if ( ch == 'n')
		{
			CShfeFtdcReqUpdateCheckField field;
			memset(&field, 0, sizeof(field));
			memcpy(field.FileName, "monitor4android", 256);
			memcpy(field.Version, "1.0.0", 16);
			memcpy(field.FileDigest, "d7e50610170c2ba20d25d4a7f52cac99", 128);

			m_api->ReqUpdateCheck(&field, 0);
		}

		if ( ch == 'o')
		{
			CShfeFtdcReqQryGetFileField field;
			memset(&field, 0, sizeof(field));
			memcpy(field.FileName, "monitor4android", 256);
			memcpy(field.Version, "1.0.0", 16);
			field.Offset = 0;
			m_api->ReqGetUpdateFile(&field, 0);
		}

		if ( ch == 'p')
		{
			CShfeFtdcReqUpdateCheckField field;
			memset(&field, 0, sizeof(field));
			memcpy(field.FileName, "monitor4android", 256);
			memcpy(field.Version, "1.0.4", 16);
			memcpy(field.FileDigest, "ebd974a96a2e904301268794ad0cbf6b", 128);

			m_api->ReqUpdateCheck(&field, 0);
		}

		if ( ch == 'q')
		{
			CShfeFtdcReqQryGetFileField field;
			memset(&field, 0, sizeof(field));
			memcpy(field.FileName, "monitor4android", 256);
			memcpy(field.Version, "1.0.4", 16);
			field.Offset = 0;
			m_api->ReqQryGetFileTopic(&field, 0);
		}



		if ( ch == 'r')
		{
			CShfeFtdcReqFeedbackInfoField field;
			memset(&field, 0, sizeof(field));
			memcpy(field.UserID, "zhang.san", 15);
			memcpy(field.PartID, "SFIT", 15);
			memcpy(field.Data, "xxxxxx", 8);
			memcpy(field.Time, "yyyyyy", 8);
			memcpy(field.SystemInfo, "ssssssssssssssssssssssssssssssssssssss", 50);
			memcpy(field.Version, "1.0.0.0", 16);
			memcpy(field.Remark, "balabalabalabalabalabalabalabalabalabalabalabalabalabala", 2000);
			m_api->ReqFeedback(&field, 0);
		}


		if ( ch == 's')
		{
			CShfeFtdcReqUserLogoutField field;
			memset(&field, 0, sizeof(field));
			memcpy(field.UserID, "QHA\\zhang.san", 16);
			memcpy(field.ParticipantID, "QHA", 11);
			m_api->ReqUserLogout(&field, 0);
		}


		if ( ch == 't')
		{
			CShfeFtdcReqQryObjectAttrField field;
			memset(&field, 0, sizeof(field));
			const char * p = "QHA.SYS01.app.tserver";
			memcpy(field.ObjectID, p, strlen(p)+1);

			p = "HandleInput";
			//p = "HandleInput_Schem_600";
			memcpy(field.AttrType, p, strlen(p)+1);

			field.Count = 12345;
			p = "20150104";
			memcpy(field.StartDate, p, strlen(p)+1);
			p = "19:00:00";
			memcpy(field.StartTime, p, strlen(p)+1);

			p = "20150105";
			memcpy(field.EndDate, p, strlen(p)+1);
			p = "19:00:00";
			memcpy(field.EndTime, p, strlen(p)+1);

			m_api->ReqQryObjectAttrTopic(&field, 0);
		}

		if ( ch == 'u')
		{
			CShfeFtdcReqAddUserField field;
			memset(&field, 0, sizeof(field));
			const char * p = "wangwu2";
			memcpy(field.UserID, p, strlen(p)+1);
			p = "QHB";
			memcpy(field.PartID, p, strlen(p)+1);

			memset(des, 0, sizeof(des));
			DesEncrypt.Encrypt("111111", des);
			p = des;
			memcpy(field.Password, p, strlen(p)+1);

			p = "123456788";
			memcpy(field.Mobile, p, strlen(p)+1);
			p = "wangwu@163.com";
			memcpy(field.EMail, p, strlen(p)+1);

			p = "王五";
			memcpy(field.Name, p, strlen(p)+1);

			field.Role = 1;

			m_api->ReqAddUser(&field, 0);
		}

		if ( ch == 'v')
		{
			CShfeFtdcReqDelUserField field;
			memset(&field, 0, sizeof(field));
			const char * p = "wangwu";
			memcpy(field.UserID, p, strlen(p)+1);

			p = "QHA";
			memcpy(field.PartID, p, strlen(p)+1);

			m_api->ReqDelUser(&field, 0);
		}

		if ( ch == 'w')
		{
			CShfeFtdcReqUpdateUserField field;
			memset(&field, 0, sizeof(field));

			const char * p = "wangwu";
			memcpy(field.UserID, p, strlen(p)+1);

			p = "QHA";
			memcpy(field.PartID, p, strlen(p)+1);

			p = "987654321";
			memcpy(field.Mobile, p, strlen(p)+1);


			m_api->ReqUpdateUser(&field, 0);
		}

		if ( ch == 'x')
		{
			CShfeFtdcReqUpdateParticipantField field;
			memset(&field, 0, sizeof(field));

			const char * p = "QHC";
			memcpy(field.PartID, p, strlen(p)+1);
			field.UserLimit = 100;
			m_api->ReqUpdateParticipant(&field, 0);
		}

		if ( ch == 'y')
		{
			CShfeFtdcReqGetUserListField field;
			memset(&field, 0, sizeof(field));

			//const char * p = "wangwu";
			//memcpy(field.UserID, p, strlen(p)+1);
			memset(field.UserID, 0, 10);

			const char * p = "QHA";
			//memcpy(field.PartID, p, strlen(p)+1);
			memset(field.PartID, 0, 10);


			m_api->ReqGetUserList(&field, 0);
		}

		if ( ch == 'z')
		{
			CShfeFtdcReqQrySubscriberField field;
			field.KeepAlive = 1;
			const char * p = "QHA.SYS01.app.Status:MaxCPUUsageValue";
			memcpy(field.ObjectID, p, strlen(p)+1);
			m_api->ReqQrySubscriberTopic(&field, 1);
		}

		if ( ch == '1')
		{
			CShfeFtdcReqQrySubscriberField field;
			field.KeepAlive = 0;
			const char * p = "QHA.SYS01.app.Status:MaxCPUUsageValue";
			memcpy(field.ObjectID, p, strlen(p)+1);
			m_api->ReqQrySubscriberTopic(&field, 1);
		}

		if ( ch == '2')
		{
			CShfeFtdcReqQrySubscriberField field;
			field.KeepAlive = 1;
			const char * p = "QHA.SYS01.app.Status:AllNum";
			memcpy(field.ObjectID, p, strlen(p)+1);
			m_api->ReqQrySubscriberTopic(&field, 1);
		}

		if ( ch == '3')
		{
			CShfeFtdcReqQrySubscriberField field;
			field.KeepAlive = 0;
			const char * p = "QHA.SYS01.app.Status:AllNum";
			memcpy(field.ObjectID, p, strlen(p)+1);
			m_api->ReqQrySubscriberTopic(&field, 1);
		}

		if ( ch == '4')
		{
			CShfeFtdcReqTradeDayField field;
			m_api->ReqTradeDay(&field, 1);
		}

	}


	m_api->Join();
	


	return 0;
}