/////////////////////////////////////////////////////////////////////////
///@system ��һ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file FtdcStruct.h
///@brief �����˿ͻ��˽ӿ�ʹ�õ�ҵ�����ݽṹ
///@history 
///20070227	zhangjie		�������ļ�
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCSYSSTRUCT_H)
#define _FTDCSYSSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FtdcSysUserApiDataType.h"

///��Ϣ�ַ�
struct CShfeFtdcDisseminationField
{
	///����ϵ�к�
	TShfeFtdcSequenceSeriesType	SequenceSeries;
	///���к�
	TShfeFtdcSequenceNoType	SequenceNo;
};

///��Ӧ��Ϣ
struct CShfeFtdcRspInfoField
{
	///�������
	TShfeFtdcErrorIDType	ErrorID;
	///������Ϣ
	TShfeFtdcErrorMsgType	ErrorMsg;
};

///ͨѶ�׶�
struct CShfeFtdcCommPhaseField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///ͨѶʱ�κ�
	TShfeFtdcCommPhaseNoType	CommPhaseNo;
};

///������������
struct CShfeFtdcExchangeTradingDayField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///����������
	TShfeFtdcExchangeIDType	ExchangeID;
};

///����Ự
struct CShfeFtdcSettlementSessionField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
};

///��ǰʱ��
struct CShfeFtdcCurrentTimeField
{
	///��ǰ����
	TShfeFtdcDateType	CurrDate;
	///��ǰʱ��
	TShfeFtdcTimeType	CurrTime;
	///��ǰʱ�䣨���룩
	TShfeFtdcMillisecType	CurrMillisec;
};

///�û���¼����
struct CShfeFtdcReqUserLoginField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///����
	TShfeFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TShfeFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TShfeFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TShfeFtdcProtocolInfoType	ProtocolInfo;
	///�������Ĵ���
	TShfeFtdcDataCenterIDType	DataCenterID;
};

///�û���¼Ӧ��
struct CShfeFtdcRspUserLoginField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///��¼�ɹ�ʱ��
	TShfeFtdcTimeType	LoginTime;
	///��󱾵ر�����
	TShfeFtdcOrderLocalIDType	MaxOrderLocalID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///����ϵͳ����
	TShfeFtdcTradingSystemNameType	TradingSystemName;
	///�������Ĵ���
	TShfeFtdcDataCenterIDType	DataCenterID;
	///��Ա˽������ǰ����
	TShfeFtdcSequenceNoType	PrivateFlowSize;
	///����Ա˽������ǰ����
	TShfeFtdcSequenceNoType	UserFlowSize;
};

///�û��ǳ�����
struct CShfeFtdcReqUserLogoutField
{
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
};

///�û��ǳ�Ӧ��
struct CShfeFtdcRspUserLogoutField
{
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
};

///���뱨��
struct CShfeFtdcInputOrderField
{
	///�������
	TShfeFtdcOrderSysIDType	OrderSysID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�����۸�����
	TShfeFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TShfeFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TShfeFtdcPriceType	LimitPrice;
	///����
	TShfeFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TShfeFtdcTimeConditionType	TimeCondition;
	///GTD����
	TShfeFtdcDateType	GTDDate;
	///�ɽ�������
	TShfeFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TShfeFtdcVolumeType	MinVolume;
	///��������
	TShfeFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TShfeFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TShfeFtdcForceCloseReasonType	ForceCloseReason;
	///���ر������
	TShfeFtdcOrderLocalIDType	OrderLocalID;
	///�Զ������־
	TShfeFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TShfeFtdcBusinessUnitType	BusinessUnit;
};

///��������
struct CShfeFtdcOrderActionField
{
	///�������
	TShfeFtdcOrderSysIDType	OrderSysID;
	///���ر������
	TShfeFtdcOrderLocalIDType	OrderLocalID;
	///����������־
	TShfeFtdcActionFlagType	ActionFlag;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///�۸�
	TShfeFtdcPriceType	LimitPrice;
	///�����仯
	TShfeFtdcVolumeType	VolumeChange;
	///�������ر��
	TShfeFtdcOrderLocalIDType	ActionLocalID;
	///ҵ��Ԫ
	TShfeFtdcBusinessUnitType	BusinessUnit;
};

///OTC����
struct CShfeFtdcOTCOrderField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///OTC�������
	TShfeFtdcOTCOrderSysIDType	OTCOrderSysID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��������
	TShfeFtdcDirectionType	Direction;
	///��ƽ��־
	TShfeFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TShfeFtdcPriceType	Price;
	///����
	TShfeFtdcVolumeType	Volume;
	///���ַ���Ա����
	TShfeFtdcParticipantIDType	OtherParticipantID;
	///���ַ��ͻ�����
	TShfeFtdcClientIDType	OtherClientID;
	///���ַ������û�����
	TShfeFtdcUserIDType	OtherUserID;
	///���ַ���ƽ��־
	TShfeFtdcOffsetFlagType	OtherOffsetFlag;
	///���ַ��ױ���־
	TShfeFtdcHedgeFlagType	OtherHedgeFlag;
	///����OTC�������
	TShfeFtdcOrderLocalIDType	OTCOrderLocalID;
	///OTC����״̬
	TShfeFtdcOTCOrderStatusType	OTCOrderStatus;
	///����ʱ��
	TShfeFtdcTimeType	InsertTime;
	///����ʱ��
	TShfeFtdcTimeType	CancelTime;
	///�����Ա���
	TShfeFtdcParticipantIDType	ClearingPartID;
	///���ַ������Ա���
	TShfeFtdcParticipantIDType	OtherClearingPartID;
};

///���뱨��
struct CShfeFtdcInputQuoteField
{
	///���۱��
	TShfeFtdcQuoteSysIDType	QuoteSysID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///����
	TShfeFtdcVolumeType	Volume;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///���ر��۱��
	TShfeFtdcOrderLocalIDType	QuoteLocalID;
	///ҵ��Ԫ
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///����Ͽ�ƽ��־
	TShfeFtdcCombOffsetFlagType	BidCombOffsetFlag;
	///������ױ���־
	TShfeFtdcCombHedgeFlagType	BidCombHedgeFlag;
	///�򷽼۸�
	TShfeFtdcPriceType	BidPrice;
	///������Ͽ�ƽ��־
	TShfeFtdcCombOffsetFlagType	AskCombOffsetFlag;
	///��������ױ���־
	TShfeFtdcCombHedgeFlagType	AskCombHedgeFlag;
	///�����۸�
	TShfeFtdcPriceType	AskPrice;
};

///���۲���
struct CShfeFtdcQuoteActionField
{
	///���۱��
	TShfeFtdcQuoteSysIDType	QuoteSysID;
	///���ر��۱��
	TShfeFtdcOrderLocalIDType	QuoteLocalID;
	///����������־
	TShfeFtdcActionFlagType	ActionFlag;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///�������ر��
	TShfeFtdcOrderLocalIDType	ActionLocalID;
	///ҵ��Ԫ
	TShfeFtdcBusinessUnitType	BusinessUnit;
};

///����ִ������
struct CShfeFtdcInputExecOrderField
{
	///��Լ���
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///����ִ��������
	TShfeFtdcOrderLocalIDType	ExecOrderLocalID;
	///����
	TShfeFtdcVolumeType	Volume;
	///ҵ��Ԫ
	TShfeFtdcBusinessUnitType	BusinessUnit;
};

///ִ���������
struct CShfeFtdcExecOrderActionField
{
	///ִ��������
	TShfeFtdcExecOrderSysIDType	ExecOrderSysID;
	///����ִ��������
	TShfeFtdcOrderLocalIDType	ExecOrderLocalID;
	///����������־
	TShfeFtdcActionFlagType	ActionFlag;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///�������ر��
	TShfeFtdcOrderLocalIDType	ActionLocalID;
	///ҵ��Ԫ
	TShfeFtdcBusinessUnitType	BusinessUnit;
};

///�û���¼�˳�
struct CShfeFtdcUserLogoutField
{
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
};

///�û������޸�
struct CShfeFtdcUserPasswordUpdateField
{
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///������
	TShfeFtdcPasswordType	OldPassword;
	///������
	TShfeFtdcPasswordType	NewPassword;
};

///����Ǳ���ϱ���
struct CShfeFtdcInputCombOrderField
{
	///��ϱ������
	TShfeFtdcOrderSysIDType	CombOrderSysID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///�۸�
	TShfeFtdcPriceType	LimitPrice;
	///����
	TShfeFtdcVolumeType	VolumeTotalOriginal;
	///���ر������
	TShfeFtdcOrderLocalIDType	CombOrderLocalID;
	///ҵ��Ԫ
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///��Լ����1
	TShfeFtdcInstrumentIDType	InstrumentID1;
	///��������1
	TShfeFtdcDirectionType	Direction1;
	///���ȳ���1
	TShfeFtdcLegMultipleType	LegMultiple1;
	///��ƽ��־1
	TShfeFtdcOffsetFlagType	OffsetFlag1;
	///Ͷ���ױ���־1
	TShfeFtdcHedgeFlagType	HedgeFlag1;
	///��Լ����2
	TShfeFtdcInstrumentIDType	InstrumentID2;
	///��������2
	TShfeFtdcDirectionType	Direction2;
	///���ȳ���2
	TShfeFtdcLegMultipleType	LegMultiple2;
	///��ƽ��־2
	TShfeFtdcOffsetFlagType	OffsetFlag2;
	///Ͷ���ױ���־2
	TShfeFtdcHedgeFlagType	HedgeFlag2;
	///��Լ����3
	TShfeFtdcInstrumentIDType	InstrumentID3;
	///��������3
	TShfeFtdcDirectionType	Direction3;
	///���ȳ���3
	TShfeFtdcLegMultipleType	LegMultiple3;
	///��ƽ��־3
	TShfeFtdcOffsetFlagType	OffsetFlag3;
	///Ͷ���ױ���־3
	TShfeFtdcHedgeFlagType	HedgeFlag3;
	///��Լ����4
	TShfeFtdcInstrumentIDType	InstrumentID4;
	///��������4
	TShfeFtdcDirectionType	Direction4;
	///���ȳ���4
	TShfeFtdcLegMultipleType	LegMultiple4;
	///��ƽ��־4
	TShfeFtdcOffsetFlagType	OffsetFlag4;
	///Ͷ���ױ���־4
	TShfeFtdcHedgeFlagType	HedgeFlag4;
};

///ǿ���û��˳�
struct CShfeFtdcForceUserExitField
{
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
};

///��Ա�ʽ��ʻ����
struct CShfeFtdcAccountDepositField
{
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///�ʽ��˺�
	TShfeFtdcAccountIDType	Account;
	///�����
	TShfeFtdcMoneyType	Deposit;
};

///������ѯ
struct CShfeFtdcQryOrderField
{
	///��ʼ��Ա����
	TShfeFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TShfeFtdcParticipantIDType	PartIDEnd;
	///�������
	TShfeFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///��ʼʱ��
	TShfeFtdcTimeType	TimeStart;
	///����ʱ��
	TShfeFtdcTimeType	TimeEnd;
};

///���۲�ѯ
struct CShfeFtdcQryQuoteField
{
	///��ʼ��Ա����
	TShfeFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TShfeFtdcParticipantIDType	PartIDEnd;
	///���۱��
	TShfeFtdcQuoteSysIDType	QuoteSysID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
};

///�ɽ���ѯ
struct CShfeFtdcQryTradeField
{
	///��ʼ��Ա����
	TShfeFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TShfeFtdcParticipantIDType	PartIDEnd;
	///��ʼ��Լ����
	TShfeFtdcInstrumentIDType	InstIDStart;
	///������Լ����
	TShfeFtdcInstrumentIDType	InstIDEnd;
	///�ɽ����
	TShfeFtdcTradeIDType	TradeID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///��ʼʱ��
	TShfeFtdcTimeType	TimeStart;
	///����ʱ��
	TShfeFtdcTimeType	TimeEnd;
};

///�����ѯ
struct CShfeFtdcQryMarketDataField
{
	///��Ʒ����
	TShfeFtdcProductIDType	ProductID;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
};

///�ͻ���ѯ
struct CShfeFtdcQryClientField
{
	///��ʼ��Ա����
	TShfeFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TShfeFtdcParticipantIDType	PartIDEnd;
	///��ʼ�ͻ�����
	TShfeFtdcClientIDType	ClientIDStart;
	///�����ͻ�����
	TShfeFtdcClientIDType	ClientIDEnd;
};

///��Ա�ֲֲ�ѯ
struct CShfeFtdcQryPartPositionField
{
	///��ʼ��Ա����
	TShfeFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TShfeFtdcParticipantIDType	PartIDEnd;
	///��ʼ��Լ����
	TShfeFtdcInstrumentIDType	InstIDStart;
	///������Լ����
	TShfeFtdcInstrumentIDType	InstIDEnd;
};

///�ͻ��ֲֲ�ѯ
struct CShfeFtdcQryClientPositionField
{
	///��ʼ��Ա����
	TShfeFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TShfeFtdcParticipantIDType	PartIDEnd;
	///��ʼ�ͻ�����
	TShfeFtdcClientIDType	ClientIDStart;
	///�����ͻ�����
	TShfeFtdcClientIDType	ClientIDEnd;
	///��ʼ��Լ����
	TShfeFtdcInstrumentIDType	InstIDStart;
	///������Լ����
	TShfeFtdcInstrumentIDType	InstIDEnd;
	///�ͻ�����
	TShfeFtdcClientTypeType	ClientType;
};

///�����ʽ��ѯ
struct CShfeFtdcQryPartAccountField
{
	///��ʼ��Ա����
	TShfeFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TShfeFtdcParticipantIDType	PartIDEnd;
	///�ʽ��ʺ�
	TShfeFtdcAccountIDType	AccountID;
};

///��Լ��ѯ
struct CShfeFtdcQryInstrumentField
{
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///��Ʒ�����
	TShfeFtdcProductGroupIDType	ProductGroupID;
	///��Ʒ����
	TShfeFtdcProductIDType	ProductID;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
};

///��Լ״̬��ѯ
struct CShfeFtdcQryInstrumentStatusField
{
	///��ʼ��Լ����
	TShfeFtdcInstrumentIDType	InstIDStart;
	///������Լ����
	TShfeFtdcInstrumentIDType	InstIDEnd;
};

///������״̬��ѯ
struct CShfeFtdcQrySGDataSyncStatusField
{
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
};

///�û����߲�ѯ
struct CShfeFtdcQryUserSessionField
{
	///��ʼ�����û�����
	TShfeFtdcUserIDType	UserIDStart;
	///���������û�����
	TShfeFtdcUserIDType	UserIDEnd;
};

///�û���ѯ
struct CShfeFtdcQryUserField
{
	///��ʼ�����û�����
	TShfeFtdcUserIDType	UserIDStart;
	///���������û�����
	TShfeFtdcUserIDType	UserIDEnd;
};

///�����ѯ
struct CShfeFtdcQryBulletinField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///�г�����
	TShfeFtdcMarketIDType	MarketID;
	///������
	TShfeFtdcBulletinIDType	BulletinID;
	///��������
	TShfeFtdcNewsTypeType	NewsType;
	///�����̶�
	TShfeFtdcNewsUrgencyType	NewsUrgency;
};

///��Ա��ѯ
struct CShfeFtdcQryParticipantField
{
	///��ʼ��Ա����
	TShfeFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TShfeFtdcParticipantIDType	PartIDEnd;
};

///��ֵ��Ȳ�ѯ
struct CShfeFtdcQryHedgeVolumeField
{
	///��ʼ��Ա����
	TShfeFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TShfeFtdcParticipantIDType	PartIDEnd;
	///��ʼ�ͻ�����
	TShfeFtdcClientIDType	ClientIDStart;
	///�����ͻ�����
	TShfeFtdcClientIDType	ClientIDEnd;
	///��ʼ��Լ����
	TShfeFtdcInstrumentIDType	InstIDStart;
	///������Լ����
	TShfeFtdcInstrumentIDType	InstIDEnd;
};

///��Լ��λ��ѯ
struct CShfeFtdcQryMBLMarketDataField
{
	///��ʼ��Լ����
	TShfeFtdcInstrumentIDType	InstIDStart;
	///������Լ����
	TShfeFtdcInstrumentIDType	InstIDEnd;
	///��������
	TShfeFtdcDirectionType	Direction;
};

///�����޶��ѯ
struct CShfeFtdcQryCreditLimitField
{
	///���׻�Ա���
	TShfeFtdcParticipantIDType	ParticipantID;
	///�����Ա���
	TShfeFtdcParticipantIDType	ClearingPartID;
};

///�Ǳ���ϱ�����ѯ
struct CShfeFtdcQryCombOrderField
{
	///��ʼ��Ա����
	TShfeFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TShfeFtdcParticipantIDType	PartIDEnd;
	///��ϱ������
	TShfeFtdcOrderSysIDType	CombOrderSysID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
};

///��Ա�ʽ�Ӧ��
struct CShfeFtdcRspPartAccountField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///�ϴν���׼����
	TShfeFtdcMoneyType	PreBalance;
	///��ǰ��֤���ܶ�
	TShfeFtdcMoneyType	CurrMargin;
	///ƽ��ӯ��
	TShfeFtdcMoneyType	CloseProfit;
	///��ȨȨ������֧
	TShfeFtdcMoneyType	Premium;
	///�����
	TShfeFtdcMoneyType	Deposit;
	///������
	TShfeFtdcMoneyType	Withdraw;
	///�ڻ�����׼����
	TShfeFtdcMoneyType	Balance;
	///�����ʽ�
	TShfeFtdcMoneyType	Available;
	///�ʽ��ʺ�
	TShfeFtdcAccountIDType	AccountID;
	///����ı�֤��
	TShfeFtdcMoneyType	FrozenMargin;
	///�����Ȩ����
	TShfeFtdcMoneyType	FrozenPremium;
	///����׼����
	TShfeFtdcMoneyType	BaseReserve;
};

///��Ա�ֲ�Ӧ��
struct CShfeFtdcRspPartPositionField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///Ͷ���ױ���־
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///�ֲֶ�շ���
	TShfeFtdcPosiDirectionType	PosiDirection;
	///���ճֲ�
	TShfeFtdcVolumeType	YdPosition;
	///���ճֲ�
	TShfeFtdcVolumeType	Position;
	///��ͷ����
	TShfeFtdcVolumeType	LongFrozen;
	///��ͷ����
	TShfeFtdcVolumeType	ShortFrozen;
	///���ն�ͷ����
	TShfeFtdcVolumeType	YdLongFrozen;
	///���տ�ͷ����
	TShfeFtdcVolumeType	YdShortFrozen;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///���׽�ɫ
	TShfeFtdcTradingRoleType	TradingRole;
};

///�ͻ��ֲ�Ӧ��
struct CShfeFtdcRspClientPositionField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///Ͷ���ױ���־
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///�ֲֶ�շ���
	TShfeFtdcPosiDirectionType	PosiDirection;
	///���ճֲ�
	TShfeFtdcVolumeType	YdPosition;
	///���ճֲ�
	TShfeFtdcVolumeType	Position;
	///��ͷ����
	TShfeFtdcVolumeType	LongFrozen;
	///��ͷ����
	TShfeFtdcVolumeType	ShortFrozen;
	///���ն�ͷ����
	TShfeFtdcVolumeType	YdLongFrozen;
	///���տ�ͷ����
	TShfeFtdcVolumeType	YdShortFrozen;
	///������ɽ���
	TShfeFtdcVolumeType	BuyTradeVolume;
	///�������ɽ���
	TShfeFtdcVolumeType	SellTradeVolume;
	///�ֲֳɱ�
	TShfeFtdcMoneyType	PositionCost;
	///���ճֲֳɱ�
	TShfeFtdcMoneyType	YdPositionCost;
	///ռ�õı�֤��
	TShfeFtdcMoneyType	UseMargin;
	///����ı�֤��
	TShfeFtdcMoneyType	FrozenMargin;
	///��ͷ����ı�֤��
	TShfeFtdcMoneyType	LongFrozenMargin;
	///��ͷ����ı�֤��
	TShfeFtdcMoneyType	ShortFrozenMargin;
	///�����Ȩ����
	TShfeFtdcMoneyType	FrozenPremium;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
};

///��Լ��ѯӦ��
struct CShfeFtdcRspInstrumentField
{
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	TShfeFtdcProductIDType	ProductID;
	///��Ʒ�����
	TShfeFtdcProductGroupIDType	ProductGroupID;
	///������Ʒ����
	TShfeFtdcInstrumentIDType	UnderlyingInstrID;
	///��Ʒ����
	TShfeFtdcProductClassType	ProductClass;
	///�ֲ�����
	TShfeFtdcPositionTypeType	PositionType;
	///ִ�м�
	TShfeFtdcPriceType	StrikePrice;
	///��Ȩ����
	TShfeFtdcOptionsTypeType	OptionsType;
	///��Լ��������
	TShfeFtdcVolumeMultipleType	VolumeMultiple;
	///��Լ������Ʒ����
	TShfeFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TShfeFtdcInstrumentNameType	InstrumentName;
	///�������
	TShfeFtdcYearType	DeliveryYear;
	///������
	TShfeFtdcMonthType	DeliveryMonth;
	///��ǰ�·�
	TShfeFtdcAdvanceMonthType	AdvanceMonth;
	///��ǰ�Ƿ���
	TShfeFtdcBoolType	IsTrading;
	///������
	TShfeFtdcDateType	CreateDate;
	///������
	TShfeFtdcDateType	OpenDate;
	///������
	TShfeFtdcDateType	ExpireDate;
	///��ʼ������
	TShfeFtdcDateType	StartDelivDate;
	///��󽻸���
	TShfeFtdcDateType	EndDelivDate;
	///���ƻ�׼��
	TShfeFtdcPriceType	BasisPrice;
	///�м۵�����µ���
	TShfeFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TShfeFtdcVolumeType	MinMarketOrderVolume;
	///�޼۵�����µ���
	TShfeFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TShfeFtdcVolumeType	MinLimitOrderVolume;
	///��С�䶯��λ
	TShfeFtdcPriceType	PriceTick;
	///��������Ȼ�˿���
	TShfeFtdcMonthCountType	AllowDelivPersonOpen;
};

///��Ϣ��ѯ
struct CShfeFtdcQryInformationField
{
	///��ʼ��Ϣ����
	TShfeFtdcInformationIDType	InformationIDStart;
	///������Ϣ����
	TShfeFtdcInformationIDType	InformationIDEnd;
};

///��Ϣ��ѯ
struct CShfeFtdcInformationField
{
	///��Ϣ���
	TShfeFtdcInformationIDType	InformationID;
	///���к�
	TShfeFtdcSequenceNoType	SequenceNo;
	///��Ϣ����
	TShfeFtdcContentType	Content;
	///���ĳ���
	TShfeFtdcContentLengthType	ContentLength;
	///�Ƿ����
	TShfeFtdcBoolType	IsAccomplished;
};

///�����޶�
struct CShfeFtdcCreditLimitField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///�ϴν���׼����
	TShfeFtdcMoneyType	PreBalance;
	///��ǰ��֤���ܶ�
	TShfeFtdcMoneyType	CurrMargin;
	///ƽ��ӯ��
	TShfeFtdcMoneyType	CloseProfit;
	///��ȨȨ������֧
	TShfeFtdcMoneyType	Premium;
	///�����
	TShfeFtdcMoneyType	Deposit;
	///������
	TShfeFtdcMoneyType	Withdraw;
	///�ڻ�����׼����
	TShfeFtdcMoneyType	Balance;
	///�����ʽ�
	TShfeFtdcMoneyType	Available;
	///���׻�Ա���
	TShfeFtdcParticipantIDType	ParticipantID;
	///�����Ա���
	TShfeFtdcParticipantIDType	ClearingPartID;
	///����ı�֤��
	TShfeFtdcMoneyType	FrozenMargin;
	///�����Ȩ����
	TShfeFtdcMoneyType	FrozenPremium;
};

///�ͻ���ѯӦ��
struct CShfeFtdcRspClientField
{
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�ͻ�����
	TShfeFtdcPartyNameType	ClientName;
	///֤������
	TShfeFtdcIdCardTypeType	IdentifiedCardType;
	///ԭ֤������
	TShfeFtdcIdentifiedCardNoV1Type	UseLess;
	///���׽�ɫ
	TShfeFtdcTradingRoleType	TradingRole;
	///�ͻ�����
	TShfeFtdcClientTypeType	ClientType;
	///�Ƿ��Ծ
	TShfeFtdcBoolType	IsActive;
	///��Ա��
	TShfeFtdcParticipantIDType	ParticipantID;
	///֤������
	TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
};

///����������
struct CShfeFtdcFlowMessageCancelField
{
	///����ϵ�к�
	TShfeFtdcSequenceSeriesType	SequenceSeries;
	///������
	TShfeFtdcDateType	TradingDay;
	///�������Ĵ���
	TShfeFtdcDataCenterIDType	DataCenterID;
	///������ʼ���к�
	TShfeFtdcSequenceNoType	StartSequenceNo;
	///���˽������к�
	TShfeFtdcSequenceNoType	EndSequenceNo;
};

///��Ա
struct CShfeFtdcParticipantField
{
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///��Ա����
	TShfeFtdcParticipantNameType	ParticipantName;
	///��Ա���
	TShfeFtdcParticipantAbbrType	ParticipantAbbr;
	///��Ա����
	TShfeFtdcMemberTypeType	MemberType;
	///�Ƿ��Ծ
	TShfeFtdcBoolType	IsActive;
};

///�û�
struct CShfeFtdcUserField
{
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///�����û�����
	TShfeFtdcUserTypeType	UserType;
	///����
	TShfeFtdcPasswordType	Password;
	///����ԱȨ��
	TShfeFtdcUserActiveType	IsActive;
};

///�ͻ�
struct CShfeFtdcClientField
{
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�ͻ�����
	TShfeFtdcPartyNameType	ClientName;
	///֤������
	TShfeFtdcIdCardTypeType	IdentifiedCardType;
	///֤������
	TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///���׽�ɫ
	TShfeFtdcTradingRoleType	TradingRole;
	///�ͻ�����
	TShfeFtdcClientTypeType	ClientType;
	///�Ƿ��Ծ
	TShfeFtdcBoolType	IsActive;
};

///�û��Ự
struct CShfeFtdcUserSessionField
{
	///ǰ�ñ��
	TShfeFtdcFrontIDType	FrontID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///�����û�����
	TShfeFtdcUserTypeType	UserType;
	///�Ự���
	TShfeFtdcSessionIDType	SessionID;
	///��¼ʱ��
	TShfeFtdcTimeType	LoginTime;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///�û��˲�Ʒ��Ϣ
	TShfeFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TShfeFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TShfeFtdcProtocolInfoType	ProtocolInfo;
	///�Ự����
	TShfeFtdcSessionTypeType	SessionType;
};

///��Ʒ��
struct CShfeFtdcProductGroupField
{
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///��Ʒ�����
	TShfeFtdcProductGroupIDType	ProductGroupID;
	///��Ʒ������
	TShfeFtdcProductGroupNameType	ProductGroupName;
	///��Ʒ����
	TShfeFtdcCommodityIDType	CommodityID;
};

///��Ʒ
struct CShfeFtdcProductField
{
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	TShfeFtdcProductIDType	ProductID;
	///��Ʒ�����
	TShfeFtdcProductGroupIDType	ProductGroupID;
	///��Ʒ����
	TShfeFtdcProductNameType	ProductName;
	///��Ʒ����
	TShfeFtdcProductClassType	ProductClass;
};

///��Լ
struct CShfeFtdcInstrumentField
{
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	TShfeFtdcProductIDType	ProductID;
	///��Ʒ�����
	TShfeFtdcProductGroupIDType	ProductGroupID;
	///������Ʒ����
	TShfeFtdcInstrumentIDType	UnderlyingInstrID;
	///��Ʒ����
	TShfeFtdcProductClassType	ProductClass;
	///�ֲ�����
	TShfeFtdcPositionTypeType	PositionType;
	///ִ�м�
	TShfeFtdcPriceType	StrikePrice;
	///��Ȩ����
	TShfeFtdcOptionsTypeType	OptionsType;
	///��Լ��������
	TShfeFtdcVolumeMultipleType	VolumeMultiple;
	///��Լ������Ʒ����
	TShfeFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TShfeFtdcInstrumentNameType	InstrumentName;
	///�������
	TShfeFtdcYearType	DeliveryYear;
	///������
	TShfeFtdcMonthType	DeliveryMonth;
	///��ǰ�·�
	TShfeFtdcAdvanceMonthType	AdvanceMonth;
	///��ǰ�Ƿ���
	TShfeFtdcBoolType	IsTrading;
};

///��Ͻ��׺�Լ�ĵ���
struct CShfeFtdcCombinationLegField
{
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///��Ϻ�Լ����
	TShfeFtdcInstrumentIDType	CombInstrumentID;
	///���ȱ��
	TShfeFtdcLegIDType	LegID;
	///���Ⱥ�Լ����
	TShfeFtdcInstrumentIDType	LegInstrumentID;
	///��������
	TShfeFtdcDirectionType	Direction;
	///���ȳ���
	TShfeFtdcLegMultipleType	LegMultiple;
	///�Ƶ�����
	TShfeFtdcImplyLevelType	ImplyLevel;
};

///�˻��ʽ���Ϣ
struct CShfeFtdcAccountInfoField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///�ϴν���׼����
	TShfeFtdcMoneyType	PreBalance;
	///��ǰ��֤���ܶ�
	TShfeFtdcMoneyType	CurrMargin;
	///ƽ��ӯ��
	TShfeFtdcMoneyType	CloseProfit;
	///��ȨȨ������֧
	TShfeFtdcMoneyType	Premium;
	///�����
	TShfeFtdcMoneyType	Deposit;
	///������
	TShfeFtdcMoneyType	Withdraw;
	///�ڻ�����׼����
	TShfeFtdcMoneyType	Balance;
	///�����ʽ�
	TShfeFtdcMoneyType	Available;
	///��������
	TShfeFtdcDateType	DateAccountOpen;
	///�ϴν��������
	TShfeFtdcDateType	PreDate;
	///�Ͻ���ı��
	TShfeFtdcSettlementIDType	PreSettlementID;
	///�ϴα�֤���ܶ�
	TShfeFtdcMoneyType	PreMargin;
	///�ڻ���֤��
	TShfeFtdcMoneyType	FuturesMargin;
	///��Ȩ��֤��
	TShfeFtdcMoneyType	OptionsMargin;
	///�ֲ�ӯ��
	TShfeFtdcMoneyType	PositionProfit;
	///����ӯ��
	TShfeFtdcMoneyType	Profit;
	///��Ϣ����
	TShfeFtdcMoneyType	Interest;
	///������
	TShfeFtdcMoneyType	Fee;
	///����Ѻ���
	TShfeFtdcMoneyType	TotalCollateral;
	///����Ѻ�ֵı�֤����
	TShfeFtdcMoneyType	CollateralForMargin;
	///�ϴ��ʽ���Ϣ����
	TShfeFtdcMoneyType	PreAccmulateInterest;
	///�ʽ���Ϣ����
	TShfeFtdcMoneyType	AccumulateInterest;
	///��Ѻ�����ѻ���
	TShfeFtdcMoneyType	AccumulateFee;
	///�����ʽ�
	TShfeFtdcMoneyType	ForzenDeposit;
	///�ʻ�״̬
	TShfeFtdcAccountStatusType	AccountStatus;
	///�ʽ��ʺ�
	TShfeFtdcAccountIDType	AccountID;
};

///��Ա��Լ�ֲ�
struct CShfeFtdcPartPositionField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///Ͷ���ױ���־
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///�ֲֶ�շ���
	TShfeFtdcPosiDirectionType	PosiDirection;
	///���ճֲ�
	TShfeFtdcVolumeType	YdPosition;
	///���ճֲ�
	TShfeFtdcVolumeType	Position;
	///��ͷ����
	TShfeFtdcVolumeType	LongFrozen;
	///��ͷ����
	TShfeFtdcVolumeType	ShortFrozen;
	///���ն�ͷ����
	TShfeFtdcVolumeType	YdLongFrozen;
	///���տ�ͷ����
	TShfeFtdcVolumeType	YdShortFrozen;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///���׽�ɫ
	TShfeFtdcTradingRoleType	TradingRole;
};

///�ͻ���Լ�ֲ�
struct CShfeFtdcClientPositionField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///Ͷ���ױ���־
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///�ֲֶ�շ���
	TShfeFtdcPosiDirectionType	PosiDirection;
	///���ճֲ�
	TShfeFtdcVolumeType	YdPosition;
	///���ճֲ�
	TShfeFtdcVolumeType	Position;
	///��ͷ����
	TShfeFtdcVolumeType	LongFrozen;
	///��ͷ����
	TShfeFtdcVolumeType	ShortFrozen;
	///���ն�ͷ����
	TShfeFtdcVolumeType	YdLongFrozen;
	///���տ�ͷ����
	TShfeFtdcVolumeType	YdShortFrozen;
	///������ɽ���
	TShfeFtdcVolumeType	BuyTradeVolume;
	///�������ɽ���
	TShfeFtdcVolumeType	SellTradeVolume;
	///�ֲֳɱ�
	TShfeFtdcMoneyType	PositionCost;
	///���ճֲֳɱ�
	TShfeFtdcMoneyType	YdPositionCost;
	///ռ�õı�֤��
	TShfeFtdcMoneyType	UseMargin;
	///����ı�֤��
	TShfeFtdcMoneyType	FrozenMargin;
	///��ͷ����ı�֤��
	TShfeFtdcMoneyType	LongFrozenMargin;
	///��ͷ����ı�֤��
	TShfeFtdcMoneyType	ShortFrozenMargin;
	///�����Ȩ����
	TShfeFtdcMoneyType	FrozenPremium;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
};

///��ֵ�����
struct CShfeFtdcHedgeVolumeField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��ͷ��ֵ������������
	TShfeFtdcVolumeType	LongVolumeOriginal;
	///��ͷ��ֵ������������
	TShfeFtdcVolumeType	ShortVolumeOriginal;
	///��ͷ��ֵ���
	TShfeFtdcVolumeType	LongVolume;
	///��ͷ��ֵ���
	TShfeFtdcVolumeType	ShortVolume;
};

///�г�����
struct CShfeFtdcMarketDataField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///���¼�
	TShfeFtdcPriceType	LastPrice;
	///�����
	TShfeFtdcPriceType	PreSettlementPrice;
	///������
	TShfeFtdcPriceType	PreClosePrice;
	///��ֲ���
	TShfeFtdcLargeVolumeType	PreOpenInterest;
	///����
	TShfeFtdcPriceType	OpenPrice;
	///��߼�
	TShfeFtdcPriceType	HighestPrice;
	///��ͼ�
	TShfeFtdcPriceType	LowestPrice;
	///����
	TShfeFtdcVolumeType	Volume;
	///�ɽ����
	TShfeFtdcMoneyType	Turnover;
	///�ֲ���
	TShfeFtdcLargeVolumeType	OpenInterest;
	///������
	TShfeFtdcPriceType	ClosePrice;
	///�����
	TShfeFtdcPriceType	SettlementPrice;
	///��ͣ���
	TShfeFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TShfeFtdcPriceType	LowerLimitPrice;
	///����ʵ��
	TShfeFtdcRatioType	PreDelta;
	///����ʵ��
	TShfeFtdcRatioType	CurrDelta;
	///����޸�ʱ��
	TShfeFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TShfeFtdcMillisecType	UpdateMillisec;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
};

///����г�����
struct CShfeFtdcDepthMarketDataField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///���¼�
	TShfeFtdcPriceType	LastPrice;
	///�����
	TShfeFtdcPriceType	PreSettlementPrice;
	///������
	TShfeFtdcPriceType	PreClosePrice;
	///��ֲ���
	TShfeFtdcLargeVolumeType	PreOpenInterest;
	///����
	TShfeFtdcPriceType	OpenPrice;
	///��߼�
	TShfeFtdcPriceType	HighestPrice;
	///��ͼ�
	TShfeFtdcPriceType	LowestPrice;
	///����
	TShfeFtdcVolumeType	Volume;
	///�ɽ����
	TShfeFtdcMoneyType	Turnover;
	///�ֲ���
	TShfeFtdcLargeVolumeType	OpenInterest;
	///������
	TShfeFtdcPriceType	ClosePrice;
	///�����
	TShfeFtdcPriceType	SettlementPrice;
	///��ͣ���
	TShfeFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TShfeFtdcPriceType	LowerLimitPrice;
	///����ʵ��
	TShfeFtdcRatioType	PreDelta;
	///����ʵ��
	TShfeFtdcRatioType	CurrDelta;
	///����޸�ʱ��
	TShfeFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TShfeFtdcMillisecType	UpdateMillisec;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�����һ
	TShfeFtdcPriceType	BidPrice1;
	///������һ
	TShfeFtdcVolumeType	BidVolume1;
	///������һ
	TShfeFtdcPriceType	AskPrice1;
	///������һ
	TShfeFtdcVolumeType	AskVolume1;
	///����۶�
	TShfeFtdcPriceType	BidPrice2;
	///��������
	TShfeFtdcVolumeType	BidVolume2;
	///�����۶�
	TShfeFtdcPriceType	AskPrice2;
	///��������
	TShfeFtdcVolumeType	AskVolume2;
	///�������
	TShfeFtdcPriceType	BidPrice3;
	///��������
	TShfeFtdcVolumeType	BidVolume3;
	///��������
	TShfeFtdcPriceType	AskPrice3;
	///��������
	TShfeFtdcVolumeType	AskVolume3;
	///�������
	TShfeFtdcPriceType	BidPrice4;
	///��������
	TShfeFtdcVolumeType	BidVolume4;
	///��������
	TShfeFtdcPriceType	AskPrice4;
	///��������
	TShfeFtdcVolumeType	AskVolume4;
	///�������
	TShfeFtdcPriceType	BidPrice5;
	///��������
	TShfeFtdcVolumeType	BidVolume5;
	///��������
	TShfeFtdcPriceType	AskPrice5;
	///��������
	TShfeFtdcVolumeType	AskVolume5;
};

///�ּ۱�
struct CShfeFtdcMBLMarketDataField
{
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��������
	TShfeFtdcDirectionType	Direction;
	///�۸�
	TShfeFtdcPriceType	Price;
	///����
	TShfeFtdcVolumeType	Volume;
};

///��������
struct CShfeFtdcAliasDefineField
{
	///��ʼλ��
	TShfeFtdcStartPosType	StartPos;
	///����
	TShfeFtdcAliasType	Alias;
	///ԭ��
	TShfeFtdcOriginalTextType	OriginalText;
};

///�����������
struct CShfeFtdcMarketDataBaseField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///�����
	TShfeFtdcPriceType	PreSettlementPrice;
	///������
	TShfeFtdcPriceType	PreClosePrice;
	///��ֲ���
	TShfeFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TShfeFtdcRatioType	PreDelta;
};

///���龲̬����
struct CShfeFtdcMarketDataStaticField
{
	///����
	TShfeFtdcPriceType	OpenPrice;
	///��߼�
	TShfeFtdcPriceType	HighestPrice;
	///��ͼ�
	TShfeFtdcPriceType	LowestPrice;
	///������
	TShfeFtdcPriceType	ClosePrice;
	///��ͣ���
	TShfeFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TShfeFtdcPriceType	LowerLimitPrice;
	///�����
	TShfeFtdcPriceType	SettlementPrice;
	///����ʵ��
	TShfeFtdcRatioType	CurrDelta;
};

///�������³ɽ�����
struct CShfeFtdcMarketDataLastMatchField
{
	///���¼�
	TShfeFtdcPriceType	LastPrice;
	///����
	TShfeFtdcVolumeType	Volume;
	///�ɽ����
	TShfeFtdcMoneyType	Turnover;
	///�ֲ���
	TShfeFtdcLargeVolumeType	OpenInterest;
};

///�������ż�����
struct CShfeFtdcMarketDataBestPriceField
{
	///�����һ
	TShfeFtdcPriceType	BidPrice1;
	///������һ
	TShfeFtdcVolumeType	BidVolume1;
	///������һ
	TShfeFtdcPriceType	AskPrice1;
	///������һ
	TShfeFtdcVolumeType	AskVolume1;
};

///�����������������
struct CShfeFtdcMarketDataBid23Field
{
	///����۶�
	TShfeFtdcPriceType	BidPrice2;
	///��������
	TShfeFtdcVolumeType	BidVolume2;
	///�������
	TShfeFtdcPriceType	BidPrice3;
	///��������
	TShfeFtdcVolumeType	BidVolume3;
};

///������������������
struct CShfeFtdcMarketDataAsk23Field
{
	///�����۶�
	TShfeFtdcPriceType	AskPrice2;
	///��������
	TShfeFtdcVolumeType	AskVolume2;
	///��������
	TShfeFtdcPriceType	AskPrice3;
	///��������
	TShfeFtdcVolumeType	AskVolume3;
};

///���������ġ�������
struct CShfeFtdcMarketDataBid45Field
{
	///�������
	TShfeFtdcPriceType	BidPrice4;
	///��������
	TShfeFtdcVolumeType	BidVolume4;
	///�������
	TShfeFtdcPriceType	BidPrice5;
	///��������
	TShfeFtdcVolumeType	BidVolume5;
};

///���������ġ�������
struct CShfeFtdcMarketDataAsk45Field
{
	///��������
	TShfeFtdcPriceType	AskPrice4;
	///��������
	TShfeFtdcVolumeType	AskVolume4;
	///��������
	TShfeFtdcPriceType	AskPrice5;
	///��������
	TShfeFtdcVolumeType	AskVolume5;
};

///�������ʱ������
struct CShfeFtdcMarketDataUpdateTimeField
{
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TShfeFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TShfeFtdcMillisecType	UpdateMillisec;
};

///����
struct CShfeFtdcQuoteField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///���۱��
	TShfeFtdcQuoteSysIDType	QuoteSysID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///����
	TShfeFtdcVolumeType	Volume;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///���ر��۱��
	TShfeFtdcOrderLocalIDType	QuoteLocalID;
	///ҵ��Ԫ
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///����Ͽ�ƽ��־
	TShfeFtdcCombOffsetFlagType	BidCombOffsetFlag;
	///������ױ���־
	TShfeFtdcCombHedgeFlagType	BidCombHedgeFlag;
	///�򷽼۸�
	TShfeFtdcPriceType	BidPrice;
	///������Ͽ�ƽ��־
	TShfeFtdcCombOffsetFlagType	AskCombOffsetFlag;
	///��������ױ���־
	TShfeFtdcCombHedgeFlagType	AskCombHedgeFlag;
	///�����۸�
	TShfeFtdcPriceType	AskPrice;
	///����ʱ��
	TShfeFtdcTimeType	InsertTime;
	///����ʱ��
	TShfeFtdcTimeType	CancelTime;
	///�ɽ�ʱ��
	TShfeFtdcTimeType	TradeTime;
	///�򷽱������
	TShfeFtdcOrderSysIDType	BidOrderSysID;
	///�����������
	TShfeFtdcOrderSysIDType	AskOrderSysID;
	///�����Ա���
	TShfeFtdcParticipantIDType	ClearingPartID;
};

///�ɽ�
struct CShfeFtdcTradeField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///�ɽ����
	TShfeFtdcTradeIDType	TradeID;
	///��������
	TShfeFtdcDirectionType	Direction;
	///�������
	TShfeFtdcOrderSysIDType	OrderSysID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///���׽�ɫ
	TShfeFtdcTradingRoleType	TradingRole;
	///�ʽ��ʺ�
	TShfeFtdcAccountIDType	AccountID;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��ƽ��־
	TShfeFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TShfeFtdcPriceType	Price;
	///����
	TShfeFtdcVolumeType	Volume;
	///�ɽ�ʱ��
	TShfeFtdcTimeType	TradeTime;
	///�ɽ�����
	TShfeFtdcTradeTypeType	TradeType;
	///�ɽ�����Դ
	TShfeFtdcPriceSourceType	PriceSource;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///���ر������
	TShfeFtdcOrderLocalIDType	OrderLocalID;
	///�����Ա���
	TShfeFtdcParticipantIDType	ClearingPartID;
	///ҵ��Ԫ
	TShfeFtdcBusinessUnitType	BusinessUnit;
};

///����
struct CShfeFtdcOrderField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///�������
	TShfeFtdcOrderSysIDType	OrderSysID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�����۸�����
	TShfeFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TShfeFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TShfeFtdcPriceType	LimitPrice;
	///����
	TShfeFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TShfeFtdcTimeConditionType	TimeCondition;
	///GTD����
	TShfeFtdcDateType	GTDDate;
	///�ɽ�������
	TShfeFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TShfeFtdcVolumeType	MinVolume;
	///��������
	TShfeFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TShfeFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TShfeFtdcForceCloseReasonType	ForceCloseReason;
	///���ر������
	TShfeFtdcOrderLocalIDType	OrderLocalID;
	///�Զ������־
	TShfeFtdcBoolType	IsAutoSuspend;
	///������Դ
	TShfeFtdcOrderSourceType	OrderSource;
	///����״̬
	TShfeFtdcOrderStatusType	OrderStatus;
	///��������
	TShfeFtdcOrderTypeType	OrderType;
	///��ɽ�����
	TShfeFtdcVolumeType	VolumeTraded;
	///ʣ������
	TShfeFtdcVolumeType	VolumeTotal;
	///��������
	TShfeFtdcDateType	InsertDate;
	///����ʱ��
	TShfeFtdcTimeType	InsertTime;
	///����ʱ��
	TShfeFtdcTimeType	ActiveTime;
	///����ʱ��
	TShfeFtdcTimeType	SuspendTime;
	///����޸�ʱ��
	TShfeFtdcTimeType	UpdateTime;
	///����ʱ��
	TShfeFtdcTimeType	CancelTime;
	///����޸Ľ����û�����
	TShfeFtdcUserIDType	ActiveUserID;
	///����Ȩ
	TShfeFtdcPriorityType	Priority;
	///��ʱ���Ŷӵ����
	TShfeFtdcTimeSortIDType	TimeSortID;
	///�����Ա���
	TShfeFtdcParticipantIDType	ClearingPartID;
	///ҵ��Ԫ
	TShfeFtdcBusinessUnitType	BusinessUnit;
};

///ִ������
struct CShfeFtdcExecOrderField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///��Լ���
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///����ִ��������
	TShfeFtdcOrderLocalIDType	ExecOrderLocalID;
	///����
	TShfeFtdcVolumeType	Volume;
	///ҵ��Ԫ
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///ִ��������
	TShfeFtdcExecOrderSysIDType	ExecOrderSysID;
	///��������
	TShfeFtdcDateType	InsertDate;
	///����ʱ��
	TShfeFtdcTimeType	InsertTime;
	///����ʱ��
	TShfeFtdcTimeType	CancelTime;
	///ִ�н��
	TShfeFtdcExecResultType	ExecResult;
	///�����Ա���
	TShfeFtdcParticipantIDType	ClearingPartID;
};

///�Ǳ���ϱ���
struct CShfeFtdcCombOrderField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///��ϱ������
	TShfeFtdcOrderSysIDType	CombOrderSysID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///�۸�
	TShfeFtdcPriceType	LimitPrice;
	///����
	TShfeFtdcVolumeType	VolumeTotalOriginal;
	///���ر������
	TShfeFtdcOrderLocalIDType	CombOrderLocalID;
	///ҵ��Ԫ
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///��Լ����1
	TShfeFtdcInstrumentIDType	InstrumentID1;
	///��������1
	TShfeFtdcDirectionType	Direction1;
	///���ȳ���1
	TShfeFtdcLegMultipleType	LegMultiple1;
	///��ƽ��־1
	TShfeFtdcOffsetFlagType	OffsetFlag1;
	///Ͷ���ױ���־1
	TShfeFtdcHedgeFlagType	HedgeFlag1;
	///��Լ����2
	TShfeFtdcInstrumentIDType	InstrumentID2;
	///��������2
	TShfeFtdcDirectionType	Direction2;
	///���ȳ���2
	TShfeFtdcLegMultipleType	LegMultiple2;
	///��ƽ��־2
	TShfeFtdcOffsetFlagType	OffsetFlag2;
	///Ͷ���ױ���־2
	TShfeFtdcHedgeFlagType	HedgeFlag2;
	///��Լ����3
	TShfeFtdcInstrumentIDType	InstrumentID3;
	///��������3
	TShfeFtdcDirectionType	Direction3;
	///���ȳ���3
	TShfeFtdcLegMultipleType	LegMultiple3;
	///��ƽ��־3
	TShfeFtdcOffsetFlagType	OffsetFlag3;
	///Ͷ���ױ���־3
	TShfeFtdcHedgeFlagType	HedgeFlag3;
	///��Լ����4
	TShfeFtdcInstrumentIDType	InstrumentID4;
	///��������4
	TShfeFtdcDirectionType	Direction4;
	///���ȳ���4
	TShfeFtdcLegMultipleType	LegMultiple4;
	///��ƽ��־4
	TShfeFtdcOffsetFlagType	OffsetFlag4;
	///Ͷ���ױ���־4
	TShfeFtdcHedgeFlagType	HedgeFlag4;
	///������Դ
	TShfeFtdcOrderSourceType	OrderSource;
	///��ɽ�����
	TShfeFtdcVolumeType	VolumeTraded;
	///ʣ������
	TShfeFtdcVolumeType	VolumeTotal;
	///��������
	TShfeFtdcDateType	InsertDate;
	///����ʱ��
	TShfeFtdcTimeType	InsertTime;
	///�����Ա���
	TShfeFtdcParticipantIDType	ClearingPartID;
};

///������
struct CShfeFtdcAdminOrderField
{
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///����������
	TShfeFtdcAdminOrderCommandFlagType	AdminOrderCommand;
	///�����Ա���
	TShfeFtdcParticipantIDType	ClearingPartID;
	///���׻�Ա���
	TShfeFtdcParticipantIDType	ParticipantID;
	///���
	TShfeFtdcMoneyType	Amount;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
};

///����������
struct CShfeFtdcInputAdminOrderField
{
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///����������
	TShfeFtdcAdminOrderCommandFlagType	AdminOrderCommand;
	///�����Ա���
	TShfeFtdcParticipantIDType	ClearingPartID;
	///���׻�Ա���
	TShfeFtdcParticipantIDType	ParticipantID;
	///���
	TShfeFtdcMoneyType	Amount;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
};

///����
struct CShfeFtdcBulletinField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///������
	TShfeFtdcBulletinIDType	BulletinID;
	///���к�
	TShfeFtdcSequenceNoType	SequenceNo;
	///��������
	TShfeFtdcNewsTypeType	NewsType;
	///�����̶�
	TShfeFtdcNewsUrgencyType	NewsUrgency;
	///����ʱ��
	TShfeFtdcTimeType	SendTime;
	///��ϢժҪ
	TShfeFtdcAbstractType	Abstract;
	///��Ϣ��Դ
	TShfeFtdcComeFromType	ComeFrom;
	///��Ϣ����
	TShfeFtdcContentType	Content;
	///WEB��ַ
	TShfeFtdcURLLinkType	URLLink;
	///�г�����
	TShfeFtdcMarketIDType	MarketID;
};

///����������ͬ��״̬
struct CShfeFtdcExchangeDataSyncStatusField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///����������
	TShfeFtdcExchangeIDType	ExchangeID;
	///����������ͬ��״̬
	TShfeFtdcExchangeDataSyncStatusType	ExchangeDataSyncStatus;
};

///����������ͬ��״̬
struct CShfeFtdcSGDataSyncStatusField
{
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TShfeFtdcDateType	TradingDay;
	///������
	TShfeFtdcSettlementIDType	SettlementID;
	///����������ͬ��״̬
	TShfeFtdcSGDataSyncStatusType	SGDataSyncStatus;
};

///��Լ״̬
struct CShfeFtdcInstrumentStatusField
{
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Լ����״̬
	TShfeFtdcInstrumentStatusType	InstrumentStatus;
	///���׽׶α��
	TShfeFtdcTradingSegmentSNType	TradingSegmentSN;
	///���뱾״̬ʱ��
	TShfeFtdcTimeType	EnterTime;
	///���뱾״̬ԭ��
	TShfeFtdcInstStatusEnterReasonType	EnterReason;
};

///RTT����
struct CShfeFtdcRTTMeasureField
{
	///����ʱ��
	int	RTT;
};

///�ͻ��ֲֲ�ѯ
struct CShfeFtdcQryClientPositionV1Field
{
	///��ʼ��Ա����
	TShfeFtdcParticipantIDType	PartIDStart;
	///������Ա����
	TShfeFtdcParticipantIDType	PartIDEnd;
	///��ʼ�ͻ�����
	TShfeFtdcClientIDType	ClientIDStart;
	///�����ͻ�����
	TShfeFtdcClientIDType	ClientIDEnd;
	///��ʼ��Լ����
	TShfeFtdcInstrumentIDType	InstIDStart;
	///������Լ����
	TShfeFtdcInstrumentIDType	InstIDEnd;
};

///CPU��Դʹ�ò�ѯ
struct CShfeFtdcReqQryTopCpuInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcTypeCPUIdType	CPU;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///�������ı��
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///CPU��Դʹ����Ϣ
struct CShfeFtdcRspQryTopCpuInfoField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///CPU�ı��
	TShfeFtdcTypeCPUIdType	CPU;
	///
	TShfeFtdcRatioType	LOAD;
	///
	TShfeFtdcRatioType	USER;
	///
	TShfeFtdcRatioType	NICE;
	///
	TShfeFtdcRatioType	SYS;
	///
	TShfeFtdcRatioType	IDLE;
	///
	TShfeFtdcRatioType	BLOCK;
	///
	TShfeFtdcRatioType	SWAIT;
	///
	TShfeFtdcRatioType	INTR;
	///
	TShfeFtdcRatioType	SSYS;
};

///CPU��Դʹ����Ϣ
struct CShfeFtdcRtnTopCpuInfoField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///CPU�ı��
	TShfeFtdcTypeCPUIdType	CPU;
	///
	TShfeFtdcRatioType	LOAD;
	///
	TShfeFtdcRatioType	USER;
	///
	TShfeFtdcRatioType	NICE;
	///
	TShfeFtdcRatioType	SYS;
	///
	TShfeFtdcRatioType	IDLE;
	///
	TShfeFtdcRatioType	BLOCK;
	///
	TShfeFtdcRatioType	SWAIT;
	///
	TShfeFtdcRatioType	INTR;
	///
	TShfeFtdcRatioType	SSYS;
};

///Mem��Դʹ�ò�ѯ
struct CShfeFtdcReqQryTopMemInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///�������ı��
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///Mem��Դʹ����Ϣ
struct CShfeFtdcRspQryTopMemInfoField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///Total Real Memory
	TShfeFtdcVolumeType	TOTALREAL;
	///Active Real Memory
	TShfeFtdcVolumeType	ACTIVEREAL;
	///Total Virtual Memory
	TShfeFtdcVolumeType	TOTALVIRTUAL;
	///Active Virtual Memory
	TShfeFtdcVolumeType	ACTIVEVIRTUAL;
	///Free Memory
	TShfeFtdcVolumeType	FREE;
};

///Mem��Դʹ����Ϣ
struct CShfeFtdcRtnTopMemInfoField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///Total Real Memory
	TShfeFtdcVolumeType	TOTALREAL;
	///Active Real Memory
	TShfeFtdcVolumeType	ACTIVEREAL;
	///Total Virtual Memory
	TShfeFtdcVolumeType	TOTALVIRTUAL;
	///Active Virtual Memory
	TShfeFtdcVolumeType	ACTIVEVIRTUAL;
	///Free Memory
	TShfeFtdcVolumeType	FREE;
};

///process��Դʹ�ò�ѯ
struct CShfeFtdcReqQryTopProcessInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///�������ı��
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///process��Դʹ����Ϣ
struct CShfeFtdcRspQryTopProcessInfoField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///��������
	TShfeFtdcTypeCPUIdType	CPU;
	///�ն���
	TShfeFtdcTypeChar10Type	TTY;
	///���̺�
	TShfeFtdcVolumeType	PID;
	///�û���
	TShfeFtdcTypeChar10Type	USERNAME;
	///��������ȼ�
	TShfeFtdcVolumeType	PRI;
	///�����niceֵ
	TShfeFtdcVolumeType	NI;
	///����Ĵ�����������ټ���ջ�ռ�Ĵ�С
	TShfeFtdcVolumeType	SIZE;
	///����ʹ�õ������ڴ��������
	TShfeFtdcVolumeType	RES;
	///�����״̬
	TShfeFtdcTypeChar10Type	STATE;
	///������ʼʱʹ�õ���CPUʱ��
	TShfeFtdcTimeType	TIME;
	///���̵�CPU������Ȩ�ذٷֱ�
	TShfeFtdcRatioType	pWCPU;
	///���̵�ԭʼ��CPU�����ʰٷֱ�
	TShfeFtdcRatioType	pCPU;
	///�������̵�������
	TShfeFtdcTypeCommandType	COMMAND;
};

///process��Դʹ����Ϣ
struct CShfeFtdcRtnTopProcessInfoField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///��������
	TShfeFtdcTypeCPUIdType	CPU;
	///�ն���
	TShfeFtdcTypeChar10Type	TTY;
	///���̺�
	TShfeFtdcVolumeType	PID;
	///�û���
	TShfeFtdcTypeChar10Type	USERNAME;
	///��������ȼ�
	TShfeFtdcVolumeType	PRI;
	///�����niceֵ
	TShfeFtdcVolumeType	NI;
	///����Ĵ�����������ټ���ջ�ռ�Ĵ�С
	TShfeFtdcVolumeType	SIZE;
	///����ʹ�õ������ڴ��������
	TShfeFtdcVolumeType	RES;
	///�����״̬
	TShfeFtdcTypeChar10Type	STATE;
	///������ʼʱʹ�õ���CPUʱ��
	TShfeFtdcTimeType	TIME;
	///���̵�CPU������Ȩ�ذٷֱ�
	TShfeFtdcRatioType	pWCPU;
	///���̵�ԭʼ��CPU�����ʰٷֱ�
	TShfeFtdcRatioType	pCPU;
	///�������̵�������
	TShfeFtdcTypeCommandType	COMMAND;
};

///filesystem��Դʹ�ò�ѯ
struct CShfeFtdcReqQryFileSystemInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///�������ı��
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///filesystem��Դʹ����Ϣ
struct CShfeFtdcRspQryFileSystemInfoField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�ļ�ϵͳ������
	TShfeFtdcTypeCommandType	FILESYSTEM;
	///�ռ�����
	TShfeFtdcVolumeType	SIZE;
	///���ÿռ��С
	TShfeFtdcVolumeType	USED;
	///���ÿռ��С
	TShfeFtdcVolumeType	AVAIL;
	///���õİٷֱ�
	TShfeFtdcRatioType	pUSERD;
	///inode����
	TShfeFtdcVolumeType	ISIZE;
	///����inode��С
	TShfeFtdcVolumeType	IUSED;
	///����inode��С
	TShfeFtdcVolumeType	IFREE;
	///���õİٷֱ�
	TShfeFtdcRatioType	pIUSED;
	///����λ��
	TShfeFtdcTypeCommandType	MountedOn;
};

///filesystem��Դʹ����Ϣ
struct CShfeFtdcRtnFileSystemInfoField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�ļ�ϵͳ������
	TShfeFtdcTypeCommandType	FILESYSTEM;
	///�ռ�����
	TShfeFtdcVolumeType	SIZE;
	///���ÿռ��С
	TShfeFtdcVolumeType	USED;
	///���ÿռ��С
	TShfeFtdcVolumeType	AVAIL;
	///���õİٷֱ�
	TShfeFtdcRatioType	pUSERD;
	///inode����
	TShfeFtdcVolumeType	ISIZE;
	///����inode��С
	TShfeFtdcVolumeType	IUSED;
	///����inode��С
	TShfeFtdcVolumeType	IFREE;
	///���õİٷֱ�
	TShfeFtdcRatioType	pIUSED;
	///����λ��
	TShfeFtdcTypeCommandType	MountedOn;
};

///network��Դʹ�ò�ѯ
struct CShfeFtdcReqQryNetworkInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///������
	TShfeFtdcTypeLanNameType	LANNAME;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///�������ı��
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///network��Դʹ����Ϣ
struct CShfeFtdcRspQryNetworkInfoField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///������
	TShfeFtdcTypeLanNameType	LANNAME;
	///������up��down״̬
	TShfeFtdcTypeLanStatusType	LANSTATUS;
	///������ip��ַ
	TShfeFtdcIPAddressType	IPADDRESS;
	///�������͵����ݰ�
	TShfeFtdcLargeVolumeType	SENDPACKETS;
	///�������͵�����
	TShfeFtdcLargeVolumeType	SENDBYTES;
	///�������յ����ݰ�
	TShfeFtdcLargeVolumeType	RECVPACKETS;
	///�������յ�����
	TShfeFtdcLargeVolumeType	RECVBYTES;
};

///network��Դʹ����Ϣ
struct CShfeFtdcRtnNetworkInfoField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///������
	TShfeFtdcTypeLanNameType	LANNAME;
	///������up��down״̬
	TShfeFtdcTypeLanStatusType	LANSTATUS;
	///������ip��ַ
	TShfeFtdcIPAddressType	IPADDRESS;
	///�������͵����ݰ�
	TShfeFtdcLargeVolumeType	SENDPACKETS;
	///�������͵�����
	TShfeFtdcLargeVolumeType	SENDBYTES;
	///�������յ����ݰ�
	TShfeFtdcLargeVolumeType	RECVPACKETS;
	///�������յ�����
	TShfeFtdcLargeVolumeType	RECVBYTES;
};

///����������Ϣ��ѯ����
struct CShfeFtdcReqQryHostEnvField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///�������ı��
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///����������ϢӦ����Ϣ
struct CShfeFtdcRspQryHostEnvCommonField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�����ͺ�
	TShfeFtdcTypeHostModelType	HostModel;
	///�ڴ��С(K)
	TShfeFtdcVolumeType	MainMemory;
	///CPU����
	TShfeFtdcVolumeType	Processors;
	///32λ����64λ����ϵͳ
	TShfeFtdcVolumeType	OsMode;
};

///����������ϢӦ����Ϣ
struct CShfeFtdcRspQryHostEnvLanField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///LanID
	TShfeFtdcTypeHostModelType	LanHardwareID;
	///Mac��ַ
	TShfeFtdcTypeHostModelType	LanHardwareValue;
};

///����������ϢӦ����Ϣ
struct CShfeFtdcRspQryHostEnvStorageField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///Storage Devices
	TShfeFtdcTypeHostModelType	StorageDev;
	///HW Path
	TShfeFtdcTypeHostModelType	HWPath;
	///Interface
	TShfeFtdcTypeHostModelType	Interface;
};

///����������ϢӦ����Ϣ
struct CShfeFtdcRspQryHostEnvIOField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///IO Class
	TShfeFtdcTypeChar10Type	IoClass;
	///H/W Path
	TShfeFtdcTypeChar10Type	H_WPath;
	///Driver
	TShfeFtdcTypeChar10Type	IoDriver;
	///Description
	TShfeFtdcTypeDescriptionType	IoDescription;
};

///����������ϢӦ����Ϣ
struct CShfeFtdcRspQryHostEnvFSField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///LVM Device file
	TShfeFtdcTypeHostModelType	LVMDeviceFile;
	///mount point
	TShfeFtdcTypeCommandType	MountPoint;
	///size
	TShfeFtdcVolumeType	FSsize;
	///fs type
	TShfeFtdcTypeChar10Type	FSType;
};

///����������ϢӦ����Ϣ
struct CShfeFtdcRspQryHostEnvSwapField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///type
	TShfeFtdcTypeChar10Type	type;
	///size
	TShfeFtdcVolumeType	size;
	///priority
	TShfeFtdcVolumeType	priority;
	///device location
	TShfeFtdcTypeHostModelType	location;
};

///����������ϢӦ����Ϣ
struct CShfeFtdcRspQryHostEnvLanCfgField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///
	TShfeFtdcTypeLanNameType	LanName;
	///
	TShfeFtdcIPAddressType	IpAddress;
	///
	TShfeFtdcIPAddressType	IpMask;
};

///�ͻ��˵�¼��ѯ����
struct CShfeFtdcReqQryClientLoginField
{
	///��¼�û���
	TShfeFtdcTypeUserNameType	UserName;
	///��¼����
	TShfeFtdcTypeUserNameType	PassWord;
};

///�ͻ��˵�¼Ӧ����Ϣ
struct CShfeFtdcRspQryClientLoginField
{
	///��¼�û���
	TShfeFtdcTypeUserNameType	UserName;
	///��¼Ȩ��
	TShfeFtdcTypeUserNameType	Privalage;
};

///��ü�ض�����Ϣ��ѯ����
struct CShfeFtdcReqQryMonitorObjectField
{
	///ҵ����̶���ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///�������ı��
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///��ü�ض�����ϢӦ����Ϣ
struct CShfeFtdcRspQryMonitorObjectField
{
	///ҵ����̶���ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///����ҵ����̶�������
	TShfeFtdcTypeLongObjectNameType	ObjectName;
	///�澯�¼�������־λ
	TShfeFtdcTypeIsActiveType	WarningActive;
};

///��ü�ض�����ϢӦ����Ϣ
struct CShfeFtdcRtnMonitorObjectField
{
	///ҵ����̶���ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///����ҵ����̶�������
	TShfeFtdcTypeLongObjectNameType	ObjectName;
	///�澯�¼�������־λ
	TShfeFtdcTypeIsActiveType	WarningActive;
};

///���ҵ����̺������Ķ�Ӧ��ϵ��ѯ����
struct CShfeFtdcReqQryObjectRationalField
{
	///ҵ����̶���ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///�������ı��
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///���ҵ����̺������Ķ�Ӧ��ϵӦ����Ϣ
struct CShfeFtdcRspQryObjectRationalField
{
	///ҵ����̶���ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///ҵ��������ڵ�����ID
	TShfeFtdcTypeObjectIDType	HostObjectID;
};

///���ҵ����̺������Ķ�Ӧ��ϵӦ����Ϣ
struct CShfeFtdcRtnObjectRationalField
{
	///ҵ����̶���ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///ҵ��������ڵ�����ID
	TShfeFtdcTypeObjectIDType	HostObjectID;
};

///��־�ļ����ݲ�ѯ����
struct CShfeFtdcReqQrySyslogInfoField
{
	///�����ļ�·��
	TShfeFtdcTypeObjectIDType	FileName;
	///�ļ���
	TShfeFtdcTypeObjectIDType	subFileName;
};

///��־�ļ�����Ӧ����Ϣ
struct CShfeFtdcRspQrySyslogInfoField
{
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///���ָ������
	TShfeFtdcAttrTypeType	AttrType;
	///�ļ����ݳ���
	TShfeFtdcTypeContLenType	ContLen;
	///�ļ�����
	TShfeFtdcTypeFileContentType	FileContent;
};

///��־�ļ�����Ӧ����Ϣ
struct CShfeFtdcRtnSyslogInfoField
{
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///���ָ������
	TShfeFtdcAttrTypeType	AttrType;
	///�ļ����ݳ���
	TShfeFtdcTypeContLenType	ContLen;
	///�ļ�����
	TShfeFtdcTypeFileContentType	FileContent;
};

///������ݶ�������
struct CShfeFtdcReqQrySubscriberField
{
	///���Ķ�����
	TShfeFtdcTypeSubcriberObjectIDType	ObjectID;
	///���η��ض�����
	TShfeFtdcVolumeType	ObjectNum;
	///�������ı��
	TShfeFtdcTypeKeepAliveType	KeepAlive;
	///���صĳ�ʼ����
	TShfeFtdcDateType	MonDate;
	///���صĳ�ʼʱ��
	TShfeFtdcTimeType	MonTime;
};

///������ݶ���Ӧ����Ϣ
struct CShfeFtdcRspQrySubscriberField
{
	///�������
	TShfeFtdcErrorIDType	ErrorID;
	///������Ϣ
	TShfeFtdcErrorMsgType	ErrorMsg;
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
};

///������ݶ���Ӧ����Ϣ
struct CShfeFtdcRtnSubscriberField
{
	///�������
	TShfeFtdcErrorIDType	ErrorID;
	///������Ϣ
	TShfeFtdcErrorMsgType	ErrorMsg;
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
};

///�����ϵ��ѯ����
struct CShfeFtdcReqQryOidRelationField
{
	///
	TShfeFtdcTypeObjectIDType	ObjectID;
};

///�����ϵ��ѯӦ����Ϣ
struct CShfeFtdcRspQryOidRelationField
{
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///���������
	TShfeFtdcTypeObjectIDType	HoldObjectID;
};

///�����ϵ��ѯӦ����Ϣ
struct CShfeFtdcRtnOidRelationField
{
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///���������
	TShfeFtdcTypeObjectIDType	HoldObjectID;
};

///�û���Ϣ��ѯ����
struct CShfeFtdcReqQryUserInfoField
{
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///�û���Ϣ��ѯӦ����Ϣ
struct CShfeFtdcRspQryUserInfoField
{
	///�û���
	TShfeFtdcTypeUserNameType	USERNAME;
	///�û�ID
	TShfeFtdcVolumeType	USERID;
	///�û�����
	TShfeFtdcTypeUserNameType	GROUPNAME;
	///�û���ID
	TShfeFtdcVolumeType	GROUPID;
	///HOME·��
	TShfeFtdcTypeUserNameType	HOMEPATH;
	///�û�ʹ��SHELL����
	TShfeFtdcTypeUserNameType	SHELL;
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
};

///�û���Ϣ��ѯӦ����Ϣ
struct CShfeFtdcRtnUserInfoField
{
	///�û���
	TShfeFtdcTypeUserNameType	USERNAME;
	///�û�ID
	TShfeFtdcVolumeType	USERID;
	///�û�����
	TShfeFtdcTypeUserNameType	GROUPNAME;
	///�û���ID
	TShfeFtdcVolumeType	GROUPID;
	///HOME·��
	TShfeFtdcTypeUserNameType	HOMEPATH;
	///�û�ʹ��SHELL����
	TShfeFtdcTypeUserNameType	SHELL;
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
};

///�����û���Ϣ��ѯ����
struct CShfeFtdcReqQryOnlineUserInfoField
{
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///�����û���ϢӦ����Ϣ
struct CShfeFtdcRspQryOnlineUserInfoField
{
	///�û���
	TShfeFtdcTypeUserNameType	USERNAME;
	///��¼ʱ��
	TShfeFtdcTypeUserNameType	TIME;
	///�ն�����
	TShfeFtdcTypeUserNameType	TTY;
	///IP��ַ
	TShfeFtdcTypeUserNameType	IP;
	///����ʱ��
	TShfeFtdcTypeUserNameType	CONNECTIME;
	///����ID
	TShfeFtdcVolumeType	PID;
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
};

///�����û���ϢӦ����Ϣ
struct CShfeFtdcRtnOnlineUserInfoField
{
	///�û���
	TShfeFtdcTypeUserNameType	USERNAME;
	///��¼ʱ��
	TShfeFtdcTypeUserNameType	TIME;
	///�ն�����
	TShfeFtdcTypeUserNameType	TTY;
	///IP��ַ
	TShfeFtdcTypeUserNameType	IP;
	///����ʱ��
	TShfeFtdcTypeUserNameType	CONNECTIME;
	///����ID
	TShfeFtdcVolumeType	PID;
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
};

///�澯�¼�
struct CShfeFtdcSysWarningEventField
{
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�¼���������
	TShfeFtdcDateType	OccurDate;
	///�¼�����ʱ��
	TShfeFtdcTimeType	OccurTime;
	///�¼�ID
	TShfeFtdcVolumeType	EvendID;
	///�����¼��Ķ���IDָ��
	TShfeFtdcNetAttrTypeType	ObjectID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///�¼���
	TShfeFtdcTypeObjectIDType	EventName;
	///�¼���ǩ
	TShfeFtdcVolumeType	EventNum;
	///�¼�����
	TShfeFtdcVolumeType	EventType;
	///�¼�����
	TShfeFtdcTypeDescriptionType	EventDes;
	///������
	TShfeFtdcTypeProcessFlagType	ProcessFlag;
	///���漶��
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///�¼���������
	TShfeFtdcTypeObjectIDType	EventDealDes;
	///�¼�ȫ��
	TShfeFtdcNetAttrTypeType	FullEventName;
};

///�澯�¼���ѯ����
struct CShfeFtdcReqQryWarningEventField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///���漶��
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///�¼�����
	TShfeFtdcVolumeType	EventType;
	///�����¼��Ķ���IDָ��
	TShfeFtdcNetAttrTypeType	ObjectID;
	///�¼���
	TShfeFtdcTypeObjectIDType	EventName;
};

///�澯�¼�Ӧ����Ϣ
struct CShfeFtdcRspQryWarningEventField
{
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�¼���������
	TShfeFtdcDateType	OccurDate;
	///�¼�����ʱ��
	TShfeFtdcTimeType	OccurTime;
	///�¼�ID
	TShfeFtdcVolumeType	EvendID;
	///�����¼��Ķ���IDָ��
	TShfeFtdcNetAttrTypeType	ObjectID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///�¼���
	TShfeFtdcTypeObjectIDType	EventName;
	///�¼���ǩ
	TShfeFtdcVolumeType	EventNum;
	///�¼�����
	TShfeFtdcVolumeType	EventType;
	///�¼�����
	TShfeFtdcTypeDescriptionType	EventDes;
	///������
	TShfeFtdcTypeProcessFlagType	ProcessFlag;
	///���漶��
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///�¼���������
	TShfeFtdcTypeObjectIDType	EventDealDes;
	///�¼�ȫ��
	TShfeFtdcNetAttrTypeType	FullEventName;
};

///�澯�¼�Ӧ����Ϣ
struct CShfeFtdcRtnWarningEventField
{
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�¼���������
	TShfeFtdcDateType	OccurDate;
	///�¼�����ʱ��
	TShfeFtdcTimeType	OccurTime;
	///�¼�ID
	TShfeFtdcVolumeType	EvendID;
	///�����¼��Ķ���IDָ��
	TShfeFtdcNetAttrTypeType	ObjectID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///�¼���
	TShfeFtdcTypeObjectIDType	EventName;
	///�¼���ǩ
	TShfeFtdcVolumeType	EventNum;
	///�¼�����
	TShfeFtdcVolumeType	EventType;
	///�¼�����
	TShfeFtdcTypeDescriptionType	EventDes;
	///������
	TShfeFtdcTypeProcessFlagType	ProcessFlag;
	///���漶��
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///�¼���������
	TShfeFtdcTypeObjectIDType	EventDealDes;
	///�¼�ȫ��
	TShfeFtdcNetAttrTypeType	FullEventName;
};

///KeyFile����
struct CShfeFtdcReqQryKeyFileInfoField
{
	///�����ļ���ID
	TShfeFtdcTypeObjectIDType	FileName;
	///�����ļ���·��
	TShfeFtdcTypeObjectIDType	PathName;
};

///HostMonitorCfg����
struct CShfeFtdcReqQryHostMonitorCfgField
{
	///
	TShfeFtdcTypeMonitorTypeType	MonitorType;
	///�����ļ���·��
	TShfeFtdcTypeObjectIDType	PathName;
	///
	TShfeFtdcVolumeType	Interval;
};

///AppMonitorCfg����
struct CShfeFtdcReqQryAppMonitorCfgField
{
	///
	TShfeFtdcTypeMonitorTypeType	MonitorType;
	///
	TShfeFtdcTypePositionType	FSPosition;
};

///CPUʹ���ʲ�ѯ����
struct CShfeFtdcReqQryCPUUsageField
{
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///CPUʹ����Ӧ����Ϣ
struct CShfeFtdcRspQryCPUUsageField
{
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///CPUʹ����
	TShfeFtdcRatioType	CPUUsage;
};

///CPUʹ����Ӧ����Ϣ
struct CShfeFtdcRtnCPUUsageField
{
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///CPUʹ����
	TShfeFtdcRatioType	CPUUsage;
};

///�ڴ�ʹ���ʲ�ѯ����
struct CShfeFtdcReqQryMemoryUsageField
{
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///�ڴ�ʹ����Ӧ����Ϣ
struct CShfeFtdcRspQryMemoryUsageField
{
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�ڴ�ʹ����
	TShfeFtdcRatioType	MemoryUsage;
};

///�ڴ�ʹ����Ӧ����Ϣ
struct CShfeFtdcRtnMemoryUsageField
{
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�ڴ�ʹ����
	TShfeFtdcRatioType	MemoryUsage;
};

///Ӳ��ʹ���ʲ�ѯ����
struct CShfeFtdcReqQryDiskUsageField
{
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///Ӳ��ʹ����Ӧ����Ϣ
struct CShfeFtdcRspQryDiskUsageField
{
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///Ӳ��ʹ����
	TShfeFtdcRatioType	DiskUsage;
};

///Ӳ��ʹ����Ӧ����Ϣ
struct CShfeFtdcRtnDiskUsageField
{
	///���������
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///Ӳ��ʹ����
	TShfeFtdcRatioType	DiskUsage;
};

///����״ָ̬���ѯ
struct CShfeFtdcReqQryObjectAttrField
{
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///������ָ������
	TShfeFtdcNetAttrTypeType	AttrType;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///����״ָ̬���ѯӦ��
struct CShfeFtdcRspQryObjectAttrField
{
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///������ָ������
	TShfeFtdcNetAttrTypeType	AttrType;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///���ָ���ֵ����
	TShfeFtdcValueTypeType	ValueType;
	///���ָ��ľ���ֵ
	TShfeFtdcAttrValueType	AttrValue;
};

///����״ָ̬���ѯӦ��
struct CShfeFtdcRtnObjectAttrField
{
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///������ָ������
	TShfeFtdcNetAttrTypeType	AttrType;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///���ָ���ֵ����
	TShfeFtdcValueTypeType	ValueType;
	///���ָ��ľ���ֵ
	TShfeFtdcAttrValueType	AttrValue;
};

///�������ò�ѯ����
struct CShfeFtdcReqQryHostConfigField
{
	///
	TShfeFtdcCfgTypeType	CfgType;
	///
	TShfeFtdcCfgNameType	CfgDataCenter;
	///
	TShfeFtdcTypeObjectIDType	CfgName;
	///
	TShfeFtdcFilePathNameType	CfgLocation;
	///
	TShfeFtdcTypeObjectIDType	CfgHostName;
	///
	TShfeFtdcTypeObjectIDType	CfgAttend;
};

///��Ч������ѯ
struct CShfeFtdcReqQryInvalidateOrderField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///��Ч������ѯӦ��
struct CShfeFtdcRspQryInvalidateOrderField
{
	///�������
	TShfeFtdcOrderSysIDType	OrderSysID;
	///���ر������
	TShfeFtdcOrderLocalIDType	OrderLocalID;
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///������Ϣ
	TShfeFtdcErrorMsgType	ErrorMsg;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��������
	TShfeFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TShfeFtdcPriceType	LimitPrice;
	///����
	TShfeFtdcVolumeType	VolumeTotalOriginal;
};

///��Ч������ѯӦ��
struct CShfeFtdcRtnInvalidateOrderField
{
	///�������
	TShfeFtdcOrderSysIDType	OrderSysID;
	///���ر������
	TShfeFtdcOrderLocalIDType	OrderLocalID;
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///������Ϣ
	TShfeFtdcErrorMsgType	ErrorMsg;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��������
	TShfeFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TShfeFtdcPriceType	LimitPrice;
	///����
	TShfeFtdcVolumeType	VolumeTotalOriginal;
};

///����״̬��ѯ
struct CShfeFtdcReqQryOrderStatusField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///����״̬��ѯӦ��
struct CShfeFtdcRspQryOrderStatusField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///�������
	TShfeFtdcOrderSysIDType	OrderSysID;
	///���ر������
	TShfeFtdcOrderLocalIDType	OrderLocalID;
	///��������
	TShfeFtdcDateType	InsertDate;
	///����ʱ��
	TShfeFtdcTimeType	InsertTime;
	///����״̬
	TShfeFtdcOrderStatusType	OrderStatus;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��������
	TShfeFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TShfeFtdcPriceType	LimitPrice;
	///����
	TShfeFtdcVolumeType	VolumeTotalOriginal;
};

///����״̬��ѯӦ��
struct CShfeFtdcRtnOrderStatusField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///�������
	TShfeFtdcOrderSysIDType	OrderSysID;
	///���ر������
	TShfeFtdcOrderLocalIDType	OrderLocalID;
	///��������
	TShfeFtdcDateType	InsertDate;
	///����ʱ��
	TShfeFtdcTimeType	InsertTime;
	///����״̬
	TShfeFtdcOrderStatusType	OrderStatus;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��������
	TShfeFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TShfeFtdcPriceType	LimitPrice;
	///����
	TShfeFtdcVolumeType	VolumeTotalOriginal;
};

///�����ɽ���ѯ
struct CShfeFtdcReqQryBargainOrderField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///�����ɽ���ѯӦ��
struct CShfeFtdcRspQryBargainOrderField
{
	///�ɽ�����
	TShfeFtdcDateType	ActionDate;
	///�ɽ�ʱ��
	TShfeFtdcTimeType	ActionTime;
	///�ɽ����
	TShfeFtdcTradeIDType	TradeID;
	///�������
	TShfeFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�۸�
	TShfeFtdcPriceType	Price;
	///����
	TShfeFtdcVolumeType	Volume;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
};

///�����ɽ���ѯӦ��
struct CShfeFtdcRtnBargainOrderField
{
	///�ɽ�����
	TShfeFtdcDateType	ActionDate;
	///�ɽ�ʱ��
	TShfeFtdcTimeType	ActionTime;
	///�ɽ����
	TShfeFtdcTradeIDType	TradeID;
	///�������
	TShfeFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�۸�
	TShfeFtdcPriceType	Price;
	///����
	TShfeFtdcVolumeType	Volume;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
};

///��Լ�������Բ�ѯ
struct CShfeFtdcReqQryInstPropertyField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcDateType	EndDate;
};

///��Լ�������Բ�ѯӦ��
struct CShfeFtdcRspQryInstPropertyField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������Ʒ����
	TShfeFtdcInstrumentIDType	UnderlyingInstrID;
	///��Ʒ����
	TShfeFtdcProductClassType	ProductClass;
	///�ֲ�����
	TShfeFtdcPositionTypeType	PositionType;
	///��Լ��������
	TShfeFtdcVolumeMultipleType	VolumeMultiple;
	///��Լ������Ʒ����
	TShfeFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///��Լ��������״̬
	TShfeFtdcInstLifePhaseType	InstLifePhase;
	///������
	TShfeFtdcDateType	OpenDate;
	///������
	TShfeFtdcDateType	ExpireDate;
	///��ʼ������
	TShfeFtdcDateType	StartDelivDate;
	///��󽻸���
	TShfeFtdcDateType	EndDelivDate;
	///���ƻ�׼��
	TShfeFtdcPriceType	BasisPrice;
	///�м۵�����µ���
	TShfeFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TShfeFtdcVolumeType	MinMarketOrderVolume;
	///�޼۵�����µ���
	TShfeFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TShfeFtdcVolumeType	MinLimitOrderVolume;
	///��С�䶯��λ
	TShfeFtdcPriceType	PriceTick;
	///��������Ȼ�˿���
	TShfeFtdcMonthCountType	AllowDelivPersonOpen;
};

///��Լ�������Բ�ѯӦ��
struct CShfeFtdcRtnInstPropertyField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///���������
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///������Ʒ����
	TShfeFtdcInstrumentIDType	UnderlyingInstrID;
	///��Ʒ����
	TShfeFtdcProductClassType	ProductClass;
	///�ֲ�����
	TShfeFtdcPositionTypeType	PositionType;
	///��Լ��������
	TShfeFtdcVolumeMultipleType	VolumeMultiple;
	///��Լ������Ʒ����
	TShfeFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///��Լ��������״̬
	TShfeFtdcInstLifePhaseType	InstLifePhase;
	///������
	TShfeFtdcDateType	OpenDate;
	///������
	TShfeFtdcDateType	ExpireDate;
	///��ʼ������
	TShfeFtdcDateType	StartDelivDate;
	///��󽻸���
	TShfeFtdcDateType	EndDelivDate;
	///���ƻ�׼��
	TShfeFtdcPriceType	BasisPrice;
	///�м۵�����µ���
	TShfeFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TShfeFtdcVolumeType	MinMarketOrderVolume;
	///�޼۵�����µ���
	TShfeFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TShfeFtdcVolumeType	MinLimitOrderVolume;
	///��С�䶯��λ
	TShfeFtdcPriceType	PriceTick;
	///��������Ȼ�˿���
	TShfeFtdcMonthCountType	AllowDelivPersonOpen;
};

///��Լ��֤���ʲ�ѯ
struct CShfeFtdcReqQryMarginRateField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcDateType	EndDate;
};

///��Լ��֤���ʲ�ѯӦ��
struct CShfeFtdcRspQryMarginRateField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///���׽�ɫ
	TShfeFtdcTradingRoleType	TradingRole;
	///Ͷ���ױ���־
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///��ͷ��֤����
	TShfeFtdcRatioType	LongMarginRatio;
	///��ͷ��֤����
	TShfeFtdcRatioType	ShortMarginRatio;
};

///��Լ��֤���ʲ�ѯӦ��
struct CShfeFtdcRtnMarginRateField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///���׽�ɫ
	TShfeFtdcTradingRoleType	TradingRole;
	///Ͷ���ױ���־
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///��ͷ��֤����
	TShfeFtdcRatioType	LongMarginRatio;
	///��ͷ��֤����
	TShfeFtdcRatioType	ShortMarginRatio;
};

///��Լ�ǵ�ͣ���ѯ
struct CShfeFtdcReqQryPriceLimitField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcDateType	EndDate;
};

///��Լ�ǵ�ͣ���ѯӦ��
struct CShfeFtdcRspQryPriceLimitField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///���뷽ʽ
	TShfeFtdcRoundingModeType	RoundingMode;
	///��ͣ���
	TShfeFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TShfeFtdcPriceType	LowerLimitPrice;
};

///��Լ�ǵ�ͣ���ѯӦ��
struct CShfeFtdcRtnPriceLimitField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///���뷽ʽ
	TShfeFtdcRoundingModeType	RoundingMode;
	///��ͣ���
	TShfeFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TShfeFtdcPriceType	LowerLimitPrice;
};

///��Ա�޲ֲ�ѯ
struct CShfeFtdcReqQryPartPosiLimitField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcDateType	EndDate;
};

///��Ա�޲ֲ�ѯӦ��
struct CShfeFtdcRspQryPartPosiLimitField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///���׽�ɫ
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///�޲����
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///��ͷ�޲�
	TShfeFtdcRatioType	LongPosLimit;
	///��ͷ�޲�
	TShfeFtdcRatioType	ShortPosLimit;
	///��ͣ���
	TShfeFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TShfeFtdcPriceType	LowerLimitPrice;
};

///��Ա�޲ֲ�ѯӦ��
struct CShfeFtdcRtnPartPosiLimitField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///���׽�ɫ
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///�޲����
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///��ͷ�޲�
	TShfeFtdcRatioType	LongPosLimit;
	///��ͷ�޲�
	TShfeFtdcRatioType	ShortPosLimit;
	///��ͣ���
	TShfeFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TShfeFtdcPriceType	LowerLimitPrice;
};

///�ͻ��޲ֲ�ѯ
struct CShfeFtdcReqQryClientPosiLimitField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcDateType	EndDate;
};

///�ͻ��޲ֲ�ѯӦ��
struct CShfeFtdcRspQryClientPosiLimitField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�ͻ�����
	TShfeFtdcClientTypeType	ClientType;
	///���׽�ɫ
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///�޲����
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///��ͷ�޲�
	TShfeFtdcRatioType	LongPosLimit;
	///��ͷ�޲�
	TShfeFtdcRatioType	ShortPosLimit;
	///��ͣ���
	TShfeFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TShfeFtdcPriceType	LowerLimitPrice;
};

///�ͻ��޲ֲ�ѯӦ��
struct CShfeFtdcRtnClientPosiLimitField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�ͻ�����
	TShfeFtdcClientTypeType	ClientType;
	///���׽�ɫ
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///�޲����
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///��ͷ�޲�
	TShfeFtdcRatioType	LongPosLimit;
	///��ͷ�޲�
	TShfeFtdcRatioType	ShortPosLimit;
	///��ͣ���
	TShfeFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TShfeFtdcPriceType	LowerLimitPrice;
};

///����ͻ��޲ֲ�ѯ
struct CShfeFtdcReqQrySpecialPosiLimitField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcDateType	EndDate;
};

///����ͻ��޲ֲ�ѯӦ��
struct CShfeFtdcRspQrySpecialPosiLimitField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///���׽�ɫ
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///�޲����
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///��ͷ�޲�
	TShfeFtdcRatioType	LongPosLimit;
	///��ͷ�޲�
	TShfeFtdcRatioType	ShortPosLimit;
	///��ͣ���
	TShfeFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TShfeFtdcPriceType	LowerLimitPrice;
};

///����ͻ��޲ֲ�ѯӦ��
struct CShfeFtdcRtnSpecialPosiLimitField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///���׽�ɫ
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///�޲����
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///��ͷ�޲�
	TShfeFtdcRatioType	LongPosLimit;
	///��ͷ�޲�
	TShfeFtdcRatioType	ShortPosLimit;
	///��ͣ���
	TShfeFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TShfeFtdcPriceType	LowerLimitPrice;
};

///�˻�������ѯ
struct CShfeFtdcReqQryTransactionChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///�˻�������ѯӦ��
struct CShfeFtdcRspQryTransactionChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///�ʻ�������ˮ��
	TShfeFtdcSerialNoType	BillSN;
	///�ʽ��˻�
	TShfeFtdcAccountIDType	ParticipantAccount;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///������
	TShfeFtdcMoneyType	Amount;
};

///�˻�������ѯӦ��
struct CShfeFtdcRtnTransactionChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///�ʻ�������ˮ��
	TShfeFtdcSerialNoType	BillSN;
	///�ʽ��˻�
	TShfeFtdcAccountIDType	ParticipantAccount;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///������
	TShfeFtdcMoneyType	Amount;
};

///�ͻ����ݱ䶯��ѯ
struct CShfeFtdcReqQryClientChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///�ͻ����ݱ䶯��ѯӦ��
struct CShfeFtdcRspQryClientChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�ͻ�����
	TShfeFtdcPartyNameType	ClientName;
	///�ͻ�����
	TShfeFtdcClientTypeType	ClientType;
	///�Ƿ��Ծ
	TShfeFtdcBoolType	IsActive;
	///֤������
	TShfeFtdcIdCardTypeType	IdentifiedCardType;
	///֤������
	TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///�ͻ����ݱ䶯��ѯӦ��
struct CShfeFtdcRtnClientChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�ͻ�����
	TShfeFtdcPartyNameType	ClientName;
	///�ͻ�����
	TShfeFtdcClientTypeType	ClientType;
	///�Ƿ��Ծ
	TShfeFtdcBoolType	IsActive;
	///֤������
	TShfeFtdcIdCardTypeType	IdentifiedCardType;
	///֤������
	TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///��Ա�ͻ����ձ䶯��ѯ
struct CShfeFtdcReqQryPartClientChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///��Ա�ͻ����ձ䶯��ѯӦ��
struct CShfeFtdcRspQryPartClientChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///��Ա�ͻ����ձ䶯��ѯӦ��
struct CShfeFtdcRtnPartClientChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///�޲����ݱ䶯��ѯ
struct CShfeFtdcReqQryPosiLimitChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///�޲����ݱ䶯��ѯӦ��
struct CShfeFtdcRspQryPosiLimitChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///���׽�ɫ
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///�޲����
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///��ͷ�޲�
	TShfeFtdcRatioType	LongPosLimit;
	///��ͷ�޲�
	TShfeFtdcRatioType	ShortPosLimit;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///�޲����ݱ䶯��ѯӦ��
struct CShfeFtdcRtnPosiLimitChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///���׽�ɫ
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///�޲����
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///��ͷ�޲�
	TShfeFtdcRatioType	LongPosLimit;
	///��ͷ�޲�
	TShfeFtdcRatioType	ShortPosLimit;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///��ֵ��ȱ䶯��ѯ
struct CShfeFtdcReqQryHedgeDetailChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///��ֵ��ȱ䶯��ѯӦ��
struct CShfeFtdcRspQryHedgeDetailChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�û�����
	TShfeFtdcOperatorIDType	OperatorID;
	///ʱ��
	TShfeFtdcTimeType	Time;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�ֲֶ�շ���
	TShfeFtdcPosiDirectionType	PosiDirection;
	///������
	TShfeFtdcVolumeType	TradingVolume;
	///��ֵ���
	TShfeFtdcVolumeType	HedgeQuota;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///��ֵ��ȱ䶯��ѯӦ��
struct CShfeFtdcRtnHedgeDetailChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�û�����
	TShfeFtdcOperatorIDType	OperatorID;
	///ʱ��
	TShfeFtdcTimeType	Time;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�ֲֶ�շ���
	TShfeFtdcPosiDirectionType	PosiDirection;
	///������
	TShfeFtdcVolumeType	TradingVolume;
	///��ֵ���
	TShfeFtdcVolumeType	HedgeQuota;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///��Ա�䶯��ѯ
struct CShfeFtdcReqQryParticipantChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///��Ա�䶯��ѯӦ��
struct CShfeFtdcRspQryParticipantChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///��Ա����
	TShfeFtdcParticipantNameType	ParticipantName;
	///��Ա���
	TShfeFtdcParticipantAbbrType	ParticipantAbbr;
	///��Ա����
	TShfeFtdcMemberTypeType	MemberType;
	///�Ƿ��Ծ
	TShfeFtdcBoolType	IsActive;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///��Ա�䶯��ѯӦ��
struct CShfeFtdcRtnParticipantChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///��Ա����
	TShfeFtdcParticipantNameType	ParticipantName;
	///��Ա���
	TShfeFtdcParticipantAbbrType	ParticipantAbbr;
	///��Ա����
	TShfeFtdcMemberTypeType	MemberType;
	///�Ƿ��Ծ
	TShfeFtdcBoolType	IsActive;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///��֤���ʱ䶯��ѯ
struct CShfeFtdcReqQryMarginRateChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///��֤���ʱ䶯��ѯӦ��
struct CShfeFtdcRspQryMarginRateChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///���׽�ɫ
	TShfeFtdcTradingRoleType	TradingRole;
	///Ͷ���ױ���־
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///��ͷ��֤����
	TShfeFtdcRatioType	LongMarginRatio;
	///��ͷ��֤����
	TShfeFtdcRatioType	ShortMarginRatio;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///��֤���ʱ䶯��ѯӦ��
struct CShfeFtdcRtnMarginRateChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///���׽�ɫ
	TShfeFtdcTradingRoleType	TradingRole;
	///Ͷ���ױ���־
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///��ͷ��֤����
	TShfeFtdcRatioType	LongMarginRatio;
	///��ͷ��֤����
	TShfeFtdcRatioType	ShortMarginRatio;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///IP��ַ�䶯��ѯ
struct CShfeFtdcReqQryUserIpChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///IP��ַ�䶯��ѯӦ��
struct CShfeFtdcRspQryUserIpChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///IP��ַ����
	TShfeFtdcIPAddressType	IPMask;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///IP��ַ�䶯��ѯӦ��
struct CShfeFtdcRtnUserIpChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///IP��ַ����
	TShfeFtdcIPAddressType	IPMask;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///�޲����ݱ䶯��ѯ
struct CShfeFtdcReqQryClientPosiLimitChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///�޲����ݱ䶯��ѯӦ��
struct CShfeFtdcRspQryClientPosiLimitChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�ͻ�����
	TShfeFtdcClientTypeType	ClientType;
	///���׽�ɫ
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///�޲����
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///��ͷ�޲�
	TShfeFtdcRatioType	LongPosLimit;
	///��ͷ�޲�
	TShfeFtdcRatioType	ShortPosLimit;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///�޲����ݱ䶯��ѯӦ��
struct CShfeFtdcRtnClientPosiLimitChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�ͻ�����
	TShfeFtdcClientTypeType	ClientType;
	///���׽�ɫ
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///�޲����
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///��ͷ�޲�
	TShfeFtdcRatioType	LongPosLimit;
	///��ͷ�޲�
	TShfeFtdcRatioType	ShortPosLimit;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///�޲����ݱ䶯��ѯ
struct CShfeFtdcReqQrySpecPosiLimitChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///�޲����ݱ䶯��ѯӦ��
struct CShfeFtdcRspQrySpecPosiLimitChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///���׽�ɫ
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///�޲����
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///��ͷ�޲�
	TShfeFtdcRatioType	LongPosLimit;
	///��ͷ�޲�
	TShfeFtdcRatioType	ShortPosLimit;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///�޲����ݱ䶯��ѯӦ��
struct CShfeFtdcRtnSpecPosiLimitChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///���׽�ɫ
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///�޲����
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///��ͷ�޲�
	TShfeFtdcRatioType	LongPosLimit;
	///��ͷ�޲�
	TShfeFtdcRatioType	ShortPosLimit;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///��ʷ����״̬��ѯ
struct CShfeFtdcReqQryHistoryObjectAttrField
{
	///���������
	TShfeFtdcNetObjectIDType	ObjectID;
	///���ָ������
	TShfeFtdcNetAttrTypeType	AttrType;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///��ʷ����״̬��ѯӦ��
struct CShfeFtdcRspQryHistoryObjectAttrField
{
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�����ڿ�ʼʱ��
	TShfeFtdcTimeType	BeginTime;
	///�����ڽ���ʱ��
	TShfeFtdcTimeType	EndTime;
	///���������
	TShfeFtdcNetObjectIDType	ObjectID;
	///���ָ������
	TShfeFtdcNetAttrTypeType	AttrType;
	///���ָ���ֵ����
	TShfeFtdcValueTypeType	ValueType;
	///�������յ���һ��ֵ
	TShfeFtdcRatioType	FirstValue;
	///�������յ����һ��ֵ
	TShfeFtdcRatioType	EndValue;
	///������ƽ��ֵ
	TShfeFtdcRatioType	AvgValue;
	///�������յ���Сֵ
	TShfeFtdcRatioType	MinValue;
	///�������յ����ֵ
	TShfeFtdcRatioType	MaxValue;
	///�������յ�ָ�����
	TShfeFtdcVolumeType	ValueCount;
};

///��ʷ����״̬��ѯӦ��
struct CShfeFtdcRtnHistoryObjectAttrField
{
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�����ڿ�ʼʱ��
	TShfeFtdcTimeType	BeginTime;
	///�����ڽ���ʱ��
	TShfeFtdcTimeType	EndTime;
	///���������
	TShfeFtdcNetObjectIDType	ObjectID;
	///���ָ������
	TShfeFtdcNetAttrTypeType	AttrType;
	///���ָ���ֵ����
	TShfeFtdcValueTypeType	ValueType;
	///�������յ���һ��ֵ
	TShfeFtdcRatioType	FirstValue;
	///�������յ����һ��ֵ
	TShfeFtdcRatioType	EndValue;
	///������ƽ��ֵ
	TShfeFtdcRatioType	AvgValue;
	///�������յ���Сֵ
	TShfeFtdcRatioType	MinValue;
	///�������յ����ֵ
	TShfeFtdcRatioType	MaxValue;
	///�������յ�ָ�����
	TShfeFtdcVolumeType	ValueCount;
};

///ǰ����Ӧ��Ϣ��ѯ
struct CShfeFtdcReqQryFrontInfoField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///ǰ����Ӧ��Ϣ��ѯӦ��
struct CShfeFtdcRspQryFrontInfoField
{
	///����
	TShfeFtdcDateType	MonDate;
	///�����ڿ�ʼʱ��
	TShfeFtdcTimeType	MonTime;
	///ǰ�û���
	TShfeFtdcTypeObjectIDType	FrontId;
	///ǰ����Ӧʱ������
	TShfeFtdcVolumeType	RspCondition;
	///������
	TShfeFtdcVolumeType	ReqCount;
	///��ռ�ܱ�������
	TShfeFtdcRatioType	ReqRate;
};

///ǰ����Ӧ��Ϣ��ѯӦ��
struct CShfeFtdcRtnFrontInfoField
{
	///����
	TShfeFtdcDateType	MonDate;
	///�����ڿ�ʼʱ��
	TShfeFtdcTimeType	MonTime;
	///ǰ�û���
	TShfeFtdcTypeObjectIDType	FrontId;
	///ǰ����Ӧʱ������
	TShfeFtdcVolumeType	RspCondition;
	///������
	TShfeFtdcVolumeType	ReqCount;
	///��ռ�ܱ�������
	TShfeFtdcRatioType	ReqRate;
};

///�û���¼��ѯ
struct CShfeFtdcReqQrySysUserLoginField
{
	///�û�����
	TShfeFtdcUserIDType	UserID;
	///����
	TShfeFtdcPasswordType	Password;
	///�汾��
	TShfeFtdcVersionIDType	VersionID;
};

///�û���¼Ӧ��
struct CShfeFtdcRspQrySysUserLoginField
{
	///�û�����
	TShfeFtdcUserIDType	UserID;
	///������
	TShfeFtdcDateType	TradingDay;
	///��¼�ɹ�ʱ��
	TShfeFtdcTimeType	LoginTime;
	///�û�Ȩ��
	TShfeFtdcPrivilegeType	Privilege;
	///�汾ƥ���ʶ
	TShfeFtdcVersionFlagType	VersionFlag;
};

///�û��ǳ�
struct CShfeFtdcReqQrySysUserLogoutField
{
	///�û�����
	TShfeFtdcUserIDType	UserID;
};

///�û��ǳ�Ӧ��
struct CShfeFtdcRspQrySysUserLogoutField
{
	///�û�����
	TShfeFtdcUserIDType	UserID;
};

///�û��޸�����
struct CShfeFtdcReqQrySysUserPasswordUpdateField
{
	///�û�����
	TShfeFtdcUserIDType	UserID;
	///������
	TShfeFtdcPasswordType	OldPassword;
	///������
	TShfeFtdcPasswordType	NewPassword;
};

///�û��޸�����Ӧ��
struct CShfeFtdcRspQrySysUserPasswordUpdateField
{
	///�û�����
	TShfeFtdcUserIDType	UserID;
	///�����޸ķ�����Ϣ
	TShfeFtdcActionMsgType	PasswordChgMsg;
};

///�û�ע��
struct CShfeFtdcReqQrySysUserRegisterField
{
	///�û�����
	TShfeFtdcUserIDType	UserID;
	///�û�����
	TShfeFtdcUserIDType	UserName;
	///�û���Ϣ
	TShfeFtdcUserInfoType	UserInfo;
	///����
	TShfeFtdcPasswordType	Password;
	///�û�Ȩ��
	TShfeFtdcPrivilegeType	Privilege;
	///�û������ʼ�
	TShfeFtdcEMailType	EMail;
	///�û������ʼ����ձ��
	TShfeFtdcReciveFlagType	EMailFlag;
	///�û��̶��绰
	TShfeFtdcTelephoneType	HomePhone;
	///�û��̶��绰���ձ��
	TShfeFtdcReciveFlagType	HomePhoneFlag;
	///�û��ֻ�
	TShfeFtdcTelephoneType	MobilePhone;
	///�û��ֻ����ձ��
	TShfeFtdcReciveFlagType	MobilePhoneFlag;
};

///�û�ע��Ӧ��
struct CShfeFtdcRspQrySysUserRegisterField
{
	///�û�����
	TShfeFtdcUserIDType	UserID;
	///�û�Ȩ��
	TShfeFtdcPrivilegeType	Privilege;
};

///ɾ���û�
struct CShfeFtdcReqQrySysUserDeleteField
{
	///�û�����
	TShfeFtdcUserIDType	UserID;
};

///ɾ���û�Ӧ��
struct CShfeFtdcRspQrySysUserDeleteField
{
	///�û�����
	TShfeFtdcUserIDType	UserID;
};

///��Ա��ʼ��Ӧ��
struct CShfeFtdcRspQryParticipantInitField
{
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///��Ա����
	TShfeFtdcParticipantNameType	ParticipantName;
	///��Ա���
	TShfeFtdcParticipantAbbrType	ParticipantAbbr;
	///��Ա����
	TShfeFtdcMemberTypeType	MemberType;
	///�Ƿ��Ծ
	TShfeFtdcBoolType	IsActive;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///��Ա��ʼ��Ӧ��
struct CShfeFtdcRtnParticipantInitField
{
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///��Ա����
	TShfeFtdcParticipantNameType	ParticipantName;
	///��Ա���
	TShfeFtdcParticipantAbbrType	ParticipantAbbr;
	///��Ա����
	TShfeFtdcMemberTypeType	MemberType;
	///�Ƿ��Ծ
	TShfeFtdcBoolType	IsActive;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///��ϯ��ʼ��Ӧ��
struct CShfeFtdcRspQryUserInitField
{
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///�����û�����
	TShfeFtdcUserTypeType	UserType;
	///����
	TShfeFtdcPasswordType	Password;
	///����ԱȨ��
	TShfeFtdcUserActiveType	IsActive;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///��ϯ��ʼ��Ӧ��
struct CShfeFtdcRtnUserInitField
{
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///�����û�����
	TShfeFtdcUserTypeType	UserType;
	///����
	TShfeFtdcPasswordType	Password;
	///����ԱȨ��
	TShfeFtdcUserActiveType	IsActive;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///�ͻ���ʼ��Ӧ��
struct CShfeFtdcRspQryClientInitField
{
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�ͻ�����
	TShfeFtdcPartyNameType	ClientName;
	///֤������
	TShfeFtdcIdCardTypeType	IdentifiedCardType;
	///֤������
	TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///���׽�ɫ
	TShfeFtdcTradingRoleType	TradingRole;
	///�ͻ�����
	TShfeFtdcClientTypeType	ClientType;
	///�Ƿ��Ծ
	TShfeFtdcBoolType	IsActive;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///�ͻ���ʼ��Ӧ��
struct CShfeFtdcRtnClientInitField
{
	///�ͻ�����
	TShfeFtdcClientIDType	ClientID;
	///�ͻ�����
	TShfeFtdcPartyNameType	ClientName;
	///֤������
	TShfeFtdcIdCardTypeType	IdentifiedCardType;
	///֤������
	TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///���׽�ɫ
	TShfeFtdcTradingRoleType	TradingRole;
	///�ͻ�����
	TShfeFtdcClientTypeType	ClientType;
	///�Ƿ��Ծ
	TShfeFtdcBoolType	IsActive;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///������־��ѯ
struct CShfeFtdcReqQryTradeLogField
{
	///������
	TShfeFtdcDateType	TradingDay;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///��ʼ��Ա��
	TShfeFtdcParticipantIDType	StartParticipant;
	///������Ա��
	TShfeFtdcParticipantIDType	EndParticipant;
	///��ʼϯλ��
	TShfeFtdcUserIDType	StartUser;
	///����ϯλ��
	TShfeFtdcUserIDType	EndUser;
	///��ʼʱ��
	TShfeFtdcTimeType	StartTime;
	///����ʱ��
	TShfeFtdcTimeType	EndTime;
	///����IP���˱��
	TShfeFtdcBoolType	IPFlag;
	///���ݻ�Ա���˱��
	TShfeFtdcBoolType	PartFlag;
	///����ϯλ���˱��
	TShfeFtdcBoolType	UserIDFlag;
	///����ʱ����˱��
	TShfeFtdcBoolType	TimeFlag;
};

///������־��ѯӦ��
struct CShfeFtdcRspQryTradeLogField
{
	///
	TShfeFtdcBoolType	bFlag;
	///
	TShfeFtdcTradeLogStrType	TradeLogStr;
};

///������־��ѯӦ��
struct CShfeFtdcRtnTradeLogField
{
	///
	TShfeFtdcBoolType	bFlag;
	///
	TShfeFtdcTradeLogStrType	TradeLogStr;
};

///�澯ʱ���޸�
struct CShfeFtdcReqQryWarningEventUpdateField
{
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�¼���������
	TShfeFtdcDateType	OccurDate;
	///�¼�����ʱ��
	TShfeFtdcTimeType	OccurTime;
	///�¼�ID
	TShfeFtdcVolumeType	EvendID;
	///�����¼��Ķ���IDָ��
	TShfeFtdcNetAttrTypeType	ObjectID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///�¼���
	TShfeFtdcTypeObjectIDType	EventName;
	///�¼���ǩ
	TShfeFtdcVolumeType	EventNum;
	///�¼�����
	TShfeFtdcVolumeType	EventType;
	///�¼�����
	TShfeFtdcTypeDescriptionType	EventDes;
	///������
	TShfeFtdcTypeProcessFlagType	ProcessFlag;
	///���漶��
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///�澯��������
	TShfeFtdcDateType	ActiveDate;
	///�澯����ʱ��
	TShfeFtdcTimeType	ActiveTime;
	///�¼���������
	TShfeFtdcTypeObjectIDType	EventDealDes;
	///�¼�ȫ��
	TShfeFtdcNetAttrTypeType	FullEventName;
};

///����ϵͳ��¼��Ϣ��ѯ
struct CShfeFtdcReqQryTradeUserLoginInfoField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///����ϵͳ��¼��ϢӦ��
struct CShfeFtdcRspQryTradeUserLoginInfoField
{
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///Э����Ϣ
	TShfeFtdcProtocolInfoType	ProtocolInfo;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///ǰ�û����
	TShfeFtdcFrontIDType	FrontID;
	///�û����
	TShfeFtdcTypeObjectIDType	UserType;
	/// ���뷽ʽ
	TShfeFtdcTypeObjectIDType	AccessType;
	///��¼��ǳ�ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��¼��ǳ����
	TShfeFtdcBoolType	ActionFlag;
	///����������
	TShfeFtdcTypeObjectIDType	DataCenter;
};

///����ϵͳ��¼��ϢӦ��
struct CShfeFtdcRtnTradeUserLoginInfoField
{
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///Э����Ϣ
	TShfeFtdcProtocolInfoType	ProtocolInfo;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///ǰ�û����
	TShfeFtdcFrontIDType	FrontID;
	///�û����
	TShfeFtdcTypeObjectIDType	UserType;
	/// ���뷽ʽ
	TShfeFtdcTypeObjectIDType	AccessType;
	///��¼��ǳ�ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��¼��ǳ����
	TShfeFtdcBoolType	ActionFlag;
	///����������
	TShfeFtdcTypeObjectIDType	DataCenter;
};

///��Ա���ײ�ѯ
struct CShfeFtdcReqQryPartTradeField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///��Ա���ײ�ѯӦ��
struct CShfeFtdcRspQryPartTradeField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�ܱ�����
	TShfeFtdcVolumeType	TotalPositiveOrder;
	///�ܱ�������
	TShfeFtdcVolumeType	TotalNegativeOrder;
	///���ܳɽ���
	TShfeFtdcVolumeType	TotalPositiveTrade;
	///�����ܳɽ���
	TShfeFtdcVolumeType	TotalNegativeTrade;
	///�ܶ�ͷ�ֲ���
	TShfeFtdcVolumeType	TotalPositivePosi;
	///�ܿ�ͷ�ֲ���
	TShfeFtdcVolumeType	TotalNegativePosi;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///���׷�ֵ��ѯ
struct CShfeFtdcReqQryTradepeakField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///
	TShfeFtdcTradepeakFlagType	TradepeakFlag;
};

///���׷�ֵ��ѯӦ��
struct CShfeFtdcRspQryTradepeakField
{
	///ͳ����Ϣ��������
	TShfeFtdcTradepeakFlagType	TradepeakFlag;
	///ʱ��
	TShfeFtdcTimeType	PeakTime;
	///����������
	TShfeFtdcVolumeType	InsertOrder;
	///����������
	TShfeFtdcVolumeType	ActionOrder;
	///��Ч������
	TShfeFtdcVolumeType	InvalidOrder;
	///���׺ϼ�
	TShfeFtdcVolumeType	TotalBusiness;
	///�ɽ���
	TShfeFtdcVolumeType	TradeCount;
	///�ϼ�
	TShfeFtdcVolumeType	TotalCount;
};

///
struct CShfeFtdcRtnUpdateSysConfigField
{
	///��������
	TShfeFtdcTypeObjectIDType	UpdateType;
	///��ֵ
	TShfeFtdcTypeObjectIDType	OldValue;
	///��ֵ
	TShfeFtdcTypeObjectIDType	NewValue;
	///����
	TShfeFtdcTypeObjectIDType	Standby;
};

///
struct CShfeFtdcRtnSysUserField
{
	///�û�����
	TShfeFtdcUserIDType	UserID;
	///�û�����
	TShfeFtdcUserIDType	UserName;
	///�û���Ϣ
	TShfeFtdcUserInfoType	UserInfo;
	///����
	TShfeFtdcPasswordType	Password;
	///�û�Ȩ��
	TShfeFtdcPrivilegeType	Privilege;
	///�û������ʼ�
	TShfeFtdcEMailType	EMail;
	///�û������ʼ����ձ��
	TShfeFtdcReciveFlagType	EMailFlag;
	///�û��̶��绰
	TShfeFtdcTelephoneType	HomePhone;
	///�û��̶��绰���ձ��
	TShfeFtdcReciveFlagType	HomePhoneFlag;
	///�û��ֻ�
	TShfeFtdcTelephoneType	MobilePhone;
	///�û��ֻ����ձ��
	TShfeFtdcReciveFlagType	MobilePhoneFlag;
};

///
struct CShfeFtdcRtnPriceLimitChgField
{
	///��������
	TShfeFtdcDateType	ActionDate;
	///����ʱ��
	TShfeFtdcTimeType	ActionTime;
	///��Լ����
	TShfeFtdcInstrumentIDType	InstrumentID;
	///ȡֵ��ʽ
	TShfeFtdcValueModeType	ValueMode;
	///���뷽ʽ
	TShfeFtdcRoundingModeType	RoundingMode;
	///��ͣ���
	TShfeFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TShfeFtdcPriceType	LowerLimitPrice;
	///��������
	TShfeFtdcDBOperationTypeType	OperationType;
};

///����ƽ̨��ʼ����Ϣ��ѯ
struct CShfeFtdcReqQryParticipantInitField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///����ƽ̨��ʼ����Ϣ��ѯ
struct CShfeFtdcReqQryUserInitField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///�ļ���д���
struct CShfeFtdcSysFileAccessInfoField
{
	///
	TShfeFtdcTypeObjectIDType	ObjectID;
	///
	TShfeFtdcLargeVolumeType	FileSize;
	///
	TShfeFtdcLargeVolumeType	FileTime;
};

///��ʷCpu״̬��ѯ
struct CShfeFtdcReqQryHistoryCpuInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcTypeCPUIdType	CPU;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///�������ı��
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///��ʷCpu��ѯӦ��
struct CShfeFtdcRspQryHistoryCpuInfoField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///CPU�ı��
	TShfeFtdcTypeCPUIdType	CPU;
	///
	TShfeFtdcRatioType	LOAD;
	///
	TShfeFtdcRatioType	USER;
	///
	TShfeFtdcRatioType	NICE;
	///
	TShfeFtdcRatioType	SYS;
	///
	TShfeFtdcRatioType	IDLE;
	///
	TShfeFtdcRatioType	BLOCK;
	///
	TShfeFtdcRatioType	SWAIT;
	///
	TShfeFtdcRatioType	INTR;
	///
	TShfeFtdcRatioType	SSYS;
};

///��ʷMem״̬��ѯ
struct CShfeFtdcReqQryHistoryMemInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///�������ı��
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///��ʷMem��ѯӦ��
struct CShfeFtdcRspQryHistoryMemInfoField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///Total Real Memory
	TShfeFtdcVolumeType	TOTALREAL;
	///Active Real Memory
	TShfeFtdcVolumeType	ACTIVEREAL;
	///Total Virtual Memory
	TShfeFtdcVolumeType	TOTALVIRTUAL;
	///Active Virtual Memory
	TShfeFtdcVolumeType	ACTIVEVIRTUAL;
	///Free Memory
	TShfeFtdcVolumeType	FREE;
};

///��ʷ����״̬��ѯ
struct CShfeFtdcReqQryHistoryNetworkInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///������
	TShfeFtdcTypeLanNameType	LANNAME;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///�������ı��
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///��ʷ�����ѯӦ��
struct CShfeFtdcRspQryHistoryNetworkInfoField
{
	///��������
	TShfeFtdcTypeObjectIDType	HostName;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///������
	TShfeFtdcTypeLanNameType	LANNAME;
	///������up��down״̬
	TShfeFtdcTypeLanStatusType	LANSTATUS;
	///������ip��ַ
	TShfeFtdcIPAddressType	IPADDRESS;
	///�������͵����ݰ�
	TShfeFtdcLargeVolumeType	SENDPACKETS;
	///�������͵�����
	TShfeFtdcLargeVolumeType	SENDBYTES;
	///�������յ����ݰ�
	TShfeFtdcLargeVolumeType	RECVPACKETS;
	///�������յ�����
	TShfeFtdcLargeVolumeType	RECVBYTES;
};

///�������ò�ѯ����Ӧ��
struct CShfeFtdcRspQryHostConfigField
{
	///
	TShfeFtdcCfgTypeType	CfgType;
	///
	TShfeFtdcCfgNameType	CfgDataCenter;
	///
	TShfeFtdcTypeObjectIDType	CfgName;
	///
	TShfeFtdcFilePathNameType	CfgLocation;
	///
	TShfeFtdcTypeObjectIDType	CfgHostName;
	///
	TShfeFtdcTypeObjectIDType	CfgAttend;
};

///���ϵͳ�����û���ѯ
struct CShfeFtdcReqQryMonitorOnlineUserField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///���ϵͳ�����û�Ӧ��
struct CShfeFtdcRspQryMonitorOnlineUserField
{
	///�û�����
	TShfeFtdcUserIDType	UserID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
};

///����ϵͳǰ��ͳ�Ʋ�ѯ
struct CShfeFtdcReqQryFrontStatField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///����ϵͳǰ��ͳ��Ӧ��
struct CShfeFtdcRspQryFrontStatField
{
	///ǰ�û����
	TShfeFtdcFrontIDType	FrontID;
	///�ܱ������
	TShfeFtdcVolumeType	PositiveOrder;
	///�ܱ�������
	TShfeFtdcVolumeType	NegativeOrder;
	///�ܱ�������
	TShfeFtdcVolumeType	TotalPositiveOrder;
	///�ܱ�������
	TShfeFtdcVolumeType	TotalNegativeOrder;
	///����״̬�ı����
	TShfeFtdcVolumeType	OrderAction;
	///����״̬�ı�����
	TShfeFtdcVolumeType	TotalOrderAction;
};

///���ϵͳʱ��ͬ��
struct CShfeFtdcRtnSysTimeSyncField
{
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
};

///���������л�֪ͨ
struct CShfeFtdcRtnDataCenterChgField
{
	///������������
	TShfeFtdcTypeObjectIDType	DataCenterID;
};

///��ʷ��ֵ��ѯ
struct CShfeFtdcReqQryHistoryTradePeakField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///��ʷ��ֵ��ѯӦ��
struct CShfeFtdcRspQryHistoryTradePeakField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�����������
	TShfeFtdcDateType	MonDate;
	///�������ʱ��
	TShfeFtdcTimeType	MonTime;
	///���ָ��
	TShfeFtdcAttrTypeType	AttrType;
	///�������ֵ
	TShfeFtdcMoneyType	AttrValue;
	///���ָ��
	TShfeFtdcAttrTypeType	RltAttrType;
	///���ָ�굱ʱ��ֵ
	TShfeFtdcMoneyType	RltAttrValue;
	///���ֵ������
	TShfeFtdcDateType	MaxMonDate;
	///���ֵ��ʱ��
	TShfeFtdcTimeType	MaxMonTime;
	///ָ����ʷ���ֵ
	TShfeFtdcMoneyType	MaxAttrValue;
	///���ָ�굱ʱ��ֵ
	TShfeFtdcMoneyType	MaxRltAttrValue;
	///����ֵ������
	TShfeFtdcDateType	OldMonDate;
	///����ֵ��ʱ��
	TShfeFtdcTimeType	OldMonTime;
	///���ָ��Ĵ���ֵ
	TShfeFtdcMoneyType	OldAttrValue;
	///���ָ�굱ʱ��ֵ
	TShfeFtdcMoneyType	OldRltAttrValue;
};

///��ʷ��ֵ��ѯӦ��
struct CShfeFtdcRtnHistoryTradePeakField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�����������
	TShfeFtdcDateType	MonDate;
	///�������ʱ��
	TShfeFtdcTimeType	MonTime;
	///���ָ��
	TShfeFtdcAttrTypeType	AttrType;
	///�������ֵ
	TShfeFtdcMoneyType	AttrValue;
	///���ָ��
	TShfeFtdcAttrTypeType	RltAttrType;
	///���ָ�굱ʱ��ֵ
	TShfeFtdcMoneyType	RltAttrValue;
	///���ֵ������
	TShfeFtdcDateType	MaxMonDate;
	///���ֵ��ʱ��
	TShfeFtdcTimeType	MaxMonTime;
	///ָ����ʷ���ֵ
	TShfeFtdcMoneyType	MaxAttrValue;
	///���ָ�굱ʱ��ֵ
	TShfeFtdcMoneyType	MaxRltAttrValue;
	///����ֵ������
	TShfeFtdcDateType	OldMonDate;
	///����ֵ��ʱ��
	TShfeFtdcTimeType	OldMonTime;
	///���ָ��Ĵ���ֵ
	TShfeFtdcMoneyType	OldAttrValue;
	///���ָ�굱ʱ��ֵ
	TShfeFtdcMoneyType	OldRltAttrValue;
};

///��־�¼���ѯ
struct CShfeFtdcReqQrySyslogEventField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///�¼�����
	TShfeFtdcVolumeType	EventType;
	///���漶��
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///�����¼��Ķ���IDָ��
	TShfeFtdcNetAttrTypeType	ObjectID;
	///�¼���
	TShfeFtdcTypeObjectIDType	EventName;
};

///��־�¼���ѯӦ��
struct CShfeFtdcRspQrySyslogEventField
{
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�¼���������
	TShfeFtdcDateType	OccurDate;
	///�¼�����ʱ��
	TShfeFtdcTimeType	OccurTime;
	///�¼�ID
	TShfeFtdcVolumeType	EvendID;
	///�����¼��Ķ���IDָ��
	TShfeFtdcNetAttrTypeType	ObjectID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///�¼���
	TShfeFtdcTypeObjectIDType	EventName;
	///�¼���ǩ
	TShfeFtdcVolumeType	EventNum;
	///�¼�����
	TShfeFtdcVolumeType	EventType;
	///�¼�����
	TShfeFtdcTypeDescriptionType	EventDes;
	///������
	TShfeFtdcTypeProcessFlagType	ProcessFlag;
	///���漶��
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///�¼���������
	TShfeFtdcTypeObjectIDType	EventDealDes;
	///�¼�ȫ��
	TShfeFtdcNetAttrTypeType	FullEventName;
};

///��־�¼�Ӧ��
struct CShfeFtdcRtnSyslogEventField
{
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�¼���������
	TShfeFtdcDateType	OccurDate;
	///�¼�����ʱ��
	TShfeFtdcTimeType	OccurTime;
	///�¼�ID
	TShfeFtdcVolumeType	EvendID;
	///�����¼��Ķ���IDָ��
	TShfeFtdcNetAttrTypeType	ObjectID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///�¼���
	TShfeFtdcTypeObjectIDType	EventName;
	///�¼���ǩ
	TShfeFtdcVolumeType	EventNum;
	///�¼�����
	TShfeFtdcVolumeType	EventType;
	///�¼�����
	TShfeFtdcTypeDescriptionType	EventDes;
	///������
	TShfeFtdcTypeProcessFlagType	ProcessFlag;
	///���漶��
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///�¼���������
	TShfeFtdcTypeObjectIDType	EventDealDes;
	///�¼�ȫ��
	TShfeFtdcNetAttrTypeType	FullEventName;
};

///��־�¼���������
struct CShfeFtdcReqQrySyslogEventSubcriberField
{
	///�����¼��Ķ���IDָ��
	TShfeFtdcNetAttrTypeType	ObjectID;
	///�¼���
	TShfeFtdcTypeObjectIDType	EventName;
	///���漶��
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///����������
	TShfeFtdcTypeSubcriberObjectIDType	filter;
	///������������
	TShfeFtdcTypeSubcriberObjectIDType	antifilter;
	///���η��ض�����
	TShfeFtdcVolumeType	ObjectNum;
	///�������ı��
	TShfeFtdcTypeKeepAliveType	KeepAlive;
	///���صĳ�ʼ����
	TShfeFtdcDateType	MonDate;
	///���صĳ�ʼʱ��
	TShfeFtdcTimeType	MonTime;
	///������
	TShfeFtdcTypeProcessFlagType	ProcessFlag;
};

///�������л�֪ͨ
struct CShfeFtdcReqQryTradeDayChangeField
{
	///�л�����
	TShfeFtdcTypeObjectIDType	ChangeType;
	///ԭ������
	TShfeFtdcDateType	OldDate;
	///�½�����
	TShfeFtdcDateType	NewDate;
};

///�������л�֪ͨ
struct CShfeFtdcRspQryTradeDayChangeField
{
	///�л�����
	TShfeFtdcTypeObjectIDType	ChangeType;
	///ԭ������
	TShfeFtdcDateType	OldDate;
	///�½�����
	TShfeFtdcDateType	NewDate;
};

///tomcat��Ϣ��ѯ
struct CShfeFtdcReqQryTomcatInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�Ӽ�ض���
	TShfeFtdcTypeObjectIDType	SubObjectID;
	///���ָ��
	TShfeFtdcFilePathNameType	AttrType;
};

///WebӦ����Ϣ
struct CShfeFtdcRspQryWebAppInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///WebӦ������
	TShfeFtdcCfgNameType	AppName;
	///Ӧ������״̬
	TShfeFtdcTypeObjectNameType	Status;
	///Ӧ��������Ϣ
	TShfeFtdcTypeDescriptionType	Desc;
	///Ӧ������ʱ��
	TShfeFtdcTypeCurrentTimeType	StartTime;
	///Ӧ��servlet����
	TShfeFtdcTypeChar10Type	ServletNum;
	///Ӧ�ô�����ʱ��
	TShfeFtdcTypeCommandType	ProcessTime;
	///Ӧ���ۼƽ���������
	TShfeFtdcTypeCommandType	RequestNum;
	///Ӧ���ۼƴ�����
	TShfeFtdcTypeCommandType	ErrorNum;
	///Ӧ�õ�ǰ�Ự��
	TShfeFtdcTypeChar10Type	SessionSize;
	///�Ự��ʱʱ��(��)
	TShfeFtdcTypeChar10Type	TimeOut;
	///Ӧ��JDBC����ʹ����
	TShfeFtdcTypeChar10Type	JDBCUsage;
	///Ӧ��JSP�ļ�����
	TShfeFtdcTypeChar10Type	JSPNum;
};

///WebӦ����Ϣ
struct CShfeFtdcRtnWebAppInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///WebӦ������
	TShfeFtdcCfgNameType	AppName;
	///Ӧ������״̬
	TShfeFtdcTypeObjectNameType	Status;
	///Ӧ��������Ϣ
	TShfeFtdcTypeDescriptionType	Desc;
	///Ӧ������ʱ��
	TShfeFtdcTypeCurrentTimeType	StartTime;
	///Ӧ��servlet����
	TShfeFtdcTypeChar10Type	ServletNum;
	///Ӧ�ô�����ʱ��
	TShfeFtdcTypeCommandType	ProcessTime;
	///Ӧ���ۼƽ���������
	TShfeFtdcTypeCommandType	RequestNum;
	///Ӧ���ۼƴ�����
	TShfeFtdcTypeCommandType	ErrorNum;
	///Ӧ�õ�ǰ�Ự��
	TShfeFtdcTypeChar10Type	SessionSize;
	///�Ự��ʱʱ��(��)
	TShfeFtdcTypeChar10Type	TimeOut;
	///Ӧ��JDBC����ʹ����
	TShfeFtdcTypeChar10Type	JDBCUsage;
	///Ӧ��JSP�ļ�����
	TShfeFtdcTypeChar10Type	JSPNum;
};

///Ӧ��servlet��Ϣ
struct CShfeFtdcRspQryServletInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///servlet����
	TShfeFtdcTypeObjectIDType	Name;
	///���غ�ʱ
	TShfeFtdcTypeContLenType	LoadTime;
	///������������
	TShfeFtdcRatioType	RequestNum;
	///��������
	TShfeFtdcRatioType	RequestErrNum;
	///����ʱ��
	TShfeFtdcRatioType	ProcessTime;
	///��С����ʱ��
	TShfeFtdcTypeContLenType	MixTime;
	///�����ʱ��
	TShfeFtdcTypeContLenType	MaxTime;
};

///Ӧ��servlet��Ϣ
struct CShfeFtdcRtnServletInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///servlet����
	TShfeFtdcTypeObjectIDType	Name;
	///���غ�ʱ
	TShfeFtdcTypeContLenType	LoadTime;
	///������������
	TShfeFtdcRatioType	RequestNum;
	///��������
	TShfeFtdcRatioType	RequestErrNum;
	///����ʱ��
	TShfeFtdcRatioType	ProcessTime;
	///��С����ʱ��
	TShfeFtdcTypeContLenType	MixTime;
	///�����ʱ��
	TShfeFtdcTypeContLenType	MaxTime;
};

///�ļ���Ϣ
struct CShfeFtdcRspQryFileInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�ļ�ȫ·����
	TShfeFtdcFilePathNameType	PathName;
	///�ļ���С
	TShfeFtdcTypeChar10Type	FileSize;
	///�ļ�����޸�ʱ��
	TShfeFtdcTypeMonitorTypeType	LastModDate;
	///�ļ�����
	TShfeFtdcTypeObjectNameType	FileType;
};

///�ļ���Ϣ
struct CShfeFtdcRtnFileInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�ļ�ȫ·����
	TShfeFtdcFilePathNameType	PathName;
	///�ļ���С
	TShfeFtdcTypeChar10Type	FileSize;
	///�ļ�����޸�ʱ��
	TShfeFtdcTypeMonitorTypeType	LastModDate;
	///�ļ�����
	TShfeFtdcTypeObjectNameType	FileType;
};

///Ӧ�ûỰ��Ϣ
struct CShfeFtdcRspQrySessionInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///Session���
	TShfeFtdcCfgNameType	SessionID;
	///Session����
	TShfeFtdcTypeObjectIDType	SessionName;
	///Session��Ӧ�ͻ���IP��ַ
	TShfeFtdcTypeObjectNameType	RemoteIP;
	///Session����ʱ��
	TShfeFtdcTypeHostModelType	BeginTime;
	///Session��������ʱ��
	TShfeFtdcTypeHostModelType	LatestTime;
	///Session��ʱʱ��(��)
	TShfeFtdcTypeContLenType	MaxIdleTime;
};

///Ӧ�ûỰ��Ϣ
struct CShfeFtdcRtnSessionInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///Session���
	TShfeFtdcCfgNameType	SessionID;
	///Session����
	TShfeFtdcTypeObjectIDType	SessionName;
	///Session��Ӧ�ͻ���IP��ַ
	TShfeFtdcTypeObjectNameType	RemoteIP;
	///Session����ʱ��
	TShfeFtdcTypeHostModelType	BeginTime;
	///Session��������ʱ��
	TShfeFtdcTypeHostModelType	LatestTime;
	///Session��ʱʱ��(��)
	TShfeFtdcTypeContLenType	MaxIdleTime;
};

///JDBC��Ϣ
struct CShfeFtdcRspQryJDBCInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///Ӧ�ó�������
	TShfeFtdcCfgNameType	AppName;
	///JDBC���ӳ�����
	TShfeFtdcCfgNameType	Name;
	///���ӳ�ʹ�ñ���
	TShfeFtdcStockPercentType	Usage;
	///���������
	TShfeFtdcTypeContLenType	ConnNumMax;
	///����������
	TShfeFtdcTypeContLenType	ConnNumFree;
	///��������������
	TShfeFtdcTypeContLenType	ConnNumUnRU;
	///������������
	TShfeFtdcTypeContLenType	ConnNumRU;
	///��Ӧ���ݿ��û�
	TShfeFtdcCfgNameType	UserName;
	///JDBC����
	TShfeFtdcTypeObjectIDType	Type;
	///JDBC Url
	TShfeFtdcTypeObjectIDType	URL;
};

///JDBC��Ϣ
struct CShfeFtdcRtnJDBCInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///Ӧ�ó�������
	TShfeFtdcCfgNameType	AppName;
	///JDBC���ӳ�����
	TShfeFtdcCfgNameType	Name;
	///���ӳ�ʹ�ñ���
	TShfeFtdcStockPercentType	Usage;
	///���������
	TShfeFtdcTypeContLenType	ConnNumMax;
	///����������
	TShfeFtdcTypeContLenType	ConnNumFree;
	///��������������
	TShfeFtdcTypeContLenType	ConnNumUnRU;
	///������������
	TShfeFtdcTypeContLenType	ConnNumRU;
	///��Ӧ���ݿ��û�
	TShfeFtdcCfgNameType	UserName;
	///JDBC����
	TShfeFtdcTypeObjectIDType	Type;
	///JDBC Url
	TShfeFtdcTypeObjectIDType	URL;
};

///�߳���Ϣ
struct CShfeFtdcRspQryThreadInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�߳�����
	TShfeFtdcTypeObjectIDType	Name;
	///�̱߳��
	TShfeFtdcTypeContLenType	ThreadNum;
	///�߳�״̬
	TShfeFtdcTypeObjectNameType	ThreadStatus;
	///�߳�Native��ʶ
	TShfeFtdcTypeContLenType	InNative;
	///�߳�Suspended��ʶ
	TShfeFtdcTypeLanNameType	Suspended;
	///�߳���������
	TShfeFtdcTypeLanNameType	BlockCount;
	///�̵߳ȴ�����
	TShfeFtdcTypeContLenType	WaitCount;
	///�߳�CPUʱ��
	TShfeFtdcRatioType	CpuTime;
	///�߳��û�ʱ��
	TShfeFtdcRatioType	UserTime;
};

///�߳���Ϣ
struct CShfeFtdcRtnThreadInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�߳�����
	TShfeFtdcTypeObjectIDType	Name;
	///�̱߳��
	TShfeFtdcTypeContLenType	ThreadNum;
	///�߳�״̬
	TShfeFtdcTypeObjectNameType	ThreadStatus;
	///�߳�Native��ʶ
	TShfeFtdcTypeContLenType	InNative;
	///�߳�Suspended��ʶ
	TShfeFtdcTypeLanNameType	Suspended;
	///�߳���������
	TShfeFtdcTypeLanNameType	BlockCount;
	///�̵߳ȴ�����
	TShfeFtdcTypeContLenType	WaitCount;
	///�߳�CPUʱ��
	TShfeFtdcRatioType	CpuTime;
	///�߳��û�ʱ��
	TShfeFtdcRatioType	UserTime;
};

///�������Ϣ��ѯ
struct CShfeFtdcReqQryVMInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�Ӽ�ض���
	TShfeFtdcTypeObjectIDType	SubObjectID;
	///���ָ��
	TShfeFtdcFilePathNameType	AttrType;
};

///�������Ϣ
struct CShfeFtdcRspQryVMInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///���������
	TShfeFtdcTypeObjectIDType	Name;
	///���������
	TShfeFtdcTypeObjectIDType	VmName;
	///��Ӧ��
	TShfeFtdcTypeObjectIDType	VmVendor;
	///������汾
	TShfeFtdcTypeObjectIDType	VmVersion;
	///����ʱ��
	TShfeFtdcTypeObjectIDType	StartTime;
	///������·��
	TShfeFtdcTypeFileContentType	BootClassPath;
	///��·��
	TShfeFtdcTypeFileContentType	ClassPath;
	///��·��
	TShfeFtdcTypeFileContentType	LibraryPath;
	///��������
	TShfeFtdcTypeFileContentType	Arguments;
};

///�������Ϣ
struct CShfeFtdcRtnVMInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///���������
	TShfeFtdcTypeObjectIDType	Name;
	///���������
	TShfeFtdcTypeObjectIDType	VmName;
	///��Ӧ��
	TShfeFtdcTypeObjectIDType	VmVendor;
	///������汾
	TShfeFtdcTypeObjectIDType	VmVersion;
	///����ʱ��
	TShfeFtdcTypeObjectIDType	StartTime;
	///������·��
	TShfeFtdcTypeFileContentType	BootClassPath;
	///��·��
	TShfeFtdcTypeFileContentType	ClassPath;
	///��·��
	TShfeFtdcTypeFileContentType	LibraryPath;
	///��������
	TShfeFtdcTypeFileContentType	Arguments;
};

///ϵͳ������Ϣ��ѯ
struct CShfeFtdcReqQryPropertyInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�Ӽ�ض���
	TShfeFtdcTypeObjectIDType	SubObjectID;
	///���ָ��
	TShfeFtdcFilePathNameType	AttrType;
};

///ϵͳ������Ϣ
struct CShfeFtdcRspQryPropertyInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///ϵͳ������
	TShfeFtdcTypeObjectIDType	Property;
	///�ָ��ʶ
	TShfeFtdcTypeContLenType	ClipFlag;
	///����ֵ
	TShfeFtdcFilePathNameType	Value;
};

///ϵͳ������Ϣ
struct CShfeFtdcRtnPropertyInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///ϵͳ������
	TShfeFtdcTypeObjectIDType	Property;
	///�ָ��ʶ
	TShfeFtdcTypeContLenType	ClipFlag;
	///����ֵ
	TShfeFtdcFilePathNameType	Value;
};

///ϵͳ�ڴ����Ϣ��ѯ
struct CShfeFtdcReqQryMemPoolInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�Ӽ�ض���
	TShfeFtdcTypeObjectIDType	SubObjectID;
	///���ָ��
	TShfeFtdcFilePathNameType	AttrType;
};

///ϵͳ�ڴ����Ϣ
struct CShfeFtdcRspQryMemPoolInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///ϵͳ������
	TShfeFtdcCfgNameType	PoolName;
	///ϵͳ������
	TShfeFtdcTypeChar10Type	Usage;
	///ϵͳ������
	TShfeFtdcTypeCommandType	committedbytes;
	///ϵͳ������
	TShfeFtdcTypeCommandType	initbytes;
	///ϵͳ������
	TShfeFtdcTypeCommandType	maxbytes;
	///ϵͳ������
	TShfeFtdcTypeCommandType	usedbytes;
	///ϵͳ������
	TShfeFtdcTypeChar10Type	Type;
};

///ϵͳ�ڴ����Ϣ
struct CShfeFtdcRtnMemPoolInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///ϵͳ������
	TShfeFtdcCfgNameType	PoolName;
	///ϵͳ������
	TShfeFtdcTypeChar10Type	Usage;
	///ϵͳ������
	TShfeFtdcTypeCommandType	committedbytes;
	///ϵͳ������
	TShfeFtdcTypeCommandType	initbytes;
	///ϵͳ������
	TShfeFtdcTypeCommandType	maxbytes;
	///ϵͳ������
	TShfeFtdcTypeCommandType	usedbytes;
	///ϵͳ������
	TShfeFtdcTypeChar10Type	Type;
};

///�ļ�������Ϣ��ѯ
struct CShfeFtdcReqQryFileContentInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�Ӽ�ض���
	TShfeFtdcTypeObjectIDType	SubObjectID;
	///���ָ��
	TShfeFtdcFilePathNameType	AttrType;
};

///�ļ�������Ϣ
struct CShfeFtdcRspQryFileContentInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�ļ���
	TShfeFtdcFilePathNameType	FileName;
	///�ļ�����
	TShfeFtdcTypeFileContentType	FileContent;
};

///�ļ�������Ϣ
struct CShfeFtdcRtnFileContentInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�ļ���
	TShfeFtdcFilePathNameType	FileName;
	///�ļ�����
	TShfeFtdcTypeFileContentType	FileContent;
};

///������Ϣ��ѯ
struct CShfeFtdcReqQryConnectionInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�Ӽ�ض���
	TShfeFtdcTypeObjectIDType	SubObjectID;
	///���ָ��
	TShfeFtdcFilePathNameType	AttrType;
};

///������Ϣ
struct CShfeFtdcRspQryConnectionInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�����߳���
	TShfeFtdcCfgNameType	ServiceName;
	///��ǰ״̬
	TShfeFtdcTypeChar10Type	Stage;
	///�ۼƽ���������
	TShfeFtdcRatioType	RequestCount;
	///�ۼƴ�����
	TShfeFtdcRatioType	ErrorCount;
	///�ۼƴ���ʱ��
	TShfeFtdcRatioType	ProcTime;
	///�ۼƽ����ֽ���
	TShfeFtdcRatioType	BytesReceived;
	///�ۼƷ����ֽ���
	TShfeFtdcRatioType	BytesSent;
	///Զ��IP��ַ
	TShfeFtdcTypeObjectNameType	RemoteIP;
	///�������URI
	TShfeFtdcAttrTypeType	MaxAccessURI;
};

///������Ϣ
struct CShfeFtdcRtnConnectionInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�����߳���
	TShfeFtdcCfgNameType	ServiceName;
	///��ǰ״̬
	TShfeFtdcTypeChar10Type	Stage;
	///�ۼƽ���������
	TShfeFtdcRatioType	RequestCount;
	///�ۼƴ�����
	TShfeFtdcRatioType	ErrorCount;
	///�ۼƴ���ʱ��
	TShfeFtdcRatioType	ProcTime;
	///�ۼƽ����ֽ���
	TShfeFtdcRatioType	BytesReceived;
	///�ۼƷ����ֽ���
	TShfeFtdcRatioType	BytesSent;
	///Զ��IP��ַ
	TShfeFtdcTypeObjectNameType	RemoteIP;
	///�������URI
	TShfeFtdcAttrTypeType	MaxAccessURI;
};

///��������Ϣ��ѯ
struct CShfeFtdcReqQryConnectorInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�Ӽ�ض���
	TShfeFtdcTypeObjectIDType	SubObjectID;
	///���ָ��
	TShfeFtdcFilePathNameType	AttrType;
};

///��������Ϣ
struct CShfeFtdcRspQryConnectorInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///����������
	TShfeFtdcTypeObjectNameType	Name;
	///��ǰ�����߳���
	TShfeFtdcTypeChar10Type	ThreadsCount;
	///��ǰ��æ�߳���
	TShfeFtdcTypeChar10Type	BusyThreadsCount;
	///����߳���
	TShfeFtdcTypeChar10Type	MaxThreads;
	///�������߳���
	TShfeFtdcTypeChar10Type	MaxSpareThreads;
	///��С�����߳���
	TShfeFtdcTypeChar10Type	MinSpareThreads;
	///�����ʱ��
	TShfeFtdcTypeCommandType	MaxTime;
	///�����ʱ��
	TShfeFtdcTypeCommandType	MaxProcTime;
	///�ۼƽ���������
	TShfeFtdcTypeCommandType	RequestCount;
	///�ۼƴ�����
	TShfeFtdcTypeCommandType	ErrorCount;
	///�ۼƽ����ֽ���
	TShfeFtdcTypeChar10Type	BytesReceived;
	///�ۼƷ����ֽ���
	TShfeFtdcTypeChar10Type	BytesSent;
};

///��������Ϣ
struct CShfeFtdcRtnConnectorInfoField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///����������
	TShfeFtdcTypeObjectNameType	Name;
	///��ǰ�����߳���
	TShfeFtdcTypeChar10Type	ThreadsCount;
	///��ǰ��æ�߳���
	TShfeFtdcTypeChar10Type	BusyThreadsCount;
	///����߳���
	TShfeFtdcTypeChar10Type	MaxThreads;
	///�������߳���
	TShfeFtdcTypeChar10Type	MaxSpareThreads;
	///��С�����߳���
	TShfeFtdcTypeChar10Type	MinSpareThreads;
	///�����ʱ��
	TShfeFtdcTypeCommandType	MaxTime;
	///�����ʱ��
	TShfeFtdcTypeCommandType	MaxProcTime;
	///�ۼƽ���������
	TShfeFtdcTypeCommandType	RequestCount;
	///�ۼƴ�����
	TShfeFtdcTypeCommandType	ErrorCount;
	///�ۼƽ����ֽ���
	TShfeFtdcTypeChar10Type	BytesReceived;
	///�ۼƷ����ֽ���
	TShfeFtdcTypeChar10Type	BytesSent;
};

///���ݿ��ѯ
struct CShfeFtdcReqQryDBQueryField
{
	///���ݿ�ʵ������ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�洢������
	TShfeFtdcAttrTypeType	AttrType;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///���ݿ��ѯӦ��
struct CShfeFtdcRspQryDBQueryField
{
	///���ݿ�ʵ������ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�洢������
	TShfeFtdcAttrTypeType	AttrType;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///���ݿ��ѯ���
	TShfeFtdcDBQueryResultType	DBQueryResult;
};

///���ݿ��ѯӦ��
struct CShfeFtdcRtnDBQueryField
{
	///���ݿ�ʵ������ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�洢������
	TShfeFtdcAttrTypeType	AttrType;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///���ݿ��ѯ���
	TShfeFtdcDBQueryResultType	DBQueryResult;
};

///ͨ�÷���Ӧ��
struct CShfeFtdcSysGeneralFieldField
{
	///�������
	TShfeFtdcDateType	MonDate;
	///���ʱ��
	TShfeFtdcTimeType	MonTime;
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///�Ӽ�ض���
	TShfeFtdcTypeObjectIDType	SubObjectID;
	///���ָ��
	TShfeFtdcFilePathNameType	AttrType;
	///ͨ�÷����ֶ�
	TShfeFtdcGeneralResultType	Content;
};

///�ļ���������
struct CShfeFtdcReqQryGetFileField
{
	///�ļ�����
	TShfeFtdcNetAttrTypeType	FileName;
	///�ļ��汾
	TShfeFtdcFileVersionType	Version;
	///�ļ�ƫ��
	TShfeFtdcOffsetType	Offset;
};

///�ļ�����Ӧ��
struct CShfeFtdcRspQryGetFileField
{
	///�ļ�����
	TShfeFtdcNetAttrTypeType	FileName;
	///�ļ��汾
	TShfeFtdcFileVersionType	Version;
	///�ļ�ƫ��
	TShfeFtdcOffsetType	Offset;
	///Comment��ʵ�����ݳ���
	TShfeFtdcCommLengthType	Length;
	///�ļ�����
	TShfeFtdcFileCommentType	Comment;
};

///��־�¼��޸�����
struct CShfeFtdcReqQrySyslogEventUpdateField
{
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�¼���������
	TShfeFtdcDateType	OccurDate;
	///�¼�����ʱ��
	TShfeFtdcTimeType	OccurTime;
	///�¼�ID
	TShfeFtdcVolumeType	EvendID;
	///�����¼��Ķ���IDָ��
	TShfeFtdcNetAttrTypeType	ObjectID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///�¼���
	TShfeFtdcTypeObjectIDType	EventName;
	///�¼���ǩ
	TShfeFtdcVolumeType	EventNum;
	///�¼�����
	TShfeFtdcVolumeType	EventType;
	///�¼�����
	TShfeFtdcTypeDescriptionType	EventDes;
	///������
	TShfeFtdcTypeProcessFlagType	ProcessFlag;
	///���漶��
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///�¼���������
	TShfeFtdcTypeObjectIDType	EventDealDes;
	///�¼�ȫ��
	TShfeFtdcNetAttrTypeType	FullEventName;
};

///�澯��ϸ��ѯ
struct CShfeFtdcReqQryWarningQueryField
{
	///�¼�ID
	TShfeFtdcVolumeType	EvendID;
};

///�澯��ϸ
struct CShfeFtdcRspQryWarningQueryField
{
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�¼�ID
	TShfeFtdcVolumeType	EvendID;
	///���ݿ��ѯ���
	TShfeFtdcDBQueryResultType	DBQueryResult;
};

///�澯��ϸ
struct CShfeFtdcRtnWarningQueryField
{
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�¼�ID
	TShfeFtdcVolumeType	EvendID;
	///���ݿ��ѯ���
	TShfeFtdcDBQueryResultType	DBQueryResult;
};

///��վ���ʲ�ѯ
struct CShfeFtdcReqQryWebVisitField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///���ָ��
	TShfeFtdcFilePathNameType	AttrType;
	///��ʼ����
	TShfeFtdcDateType	BeginDate;
	///��ʼʱ��
	TShfeFtdcTimeType	BeginTime;
	///��������
	TShfeFtdcDateType	EndDate;
	///����ʱ��
	TShfeFtdcTimeType	EndTime;
};

///�������ò�ѯ����Ӧ��
struct CShfeFtdcRtnHostConfigField
{
	///
	TShfeFtdcCfgTypeType	CfgType;
	///
	TShfeFtdcCfgNameType	CfgDataCenter;
	///
	TShfeFtdcTypeObjectIDType	CfgName;
	///
	TShfeFtdcFilePathNameType	CfgLocation;
	///
	TShfeFtdcTypeObjectIDType	CfgHostName;
	///
	TShfeFtdcTypeObjectIDType	CfgAttend;
};

///�澯������
struct CShfeFtdcReqQryWarningActiveChangeField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///����
	TShfeFtdcDateType	MonDate;
	///ʱ��
	TShfeFtdcTimeType	MonTime;
	///�澯�¼�������־λ
	TShfeFtdcTypeIsActiveType	WarningActive;
};

///�澯������
struct CShfeFtdcRspQryWarningActiveChangeField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///����
	TShfeFtdcDateType	MonDate;
	///ʱ��
	TShfeFtdcTimeType	MonTime;
	///�澯�¼�������־λ
	TShfeFtdcTypeIsActiveType	WarningActive;
};

///�澯������
struct CShfeFtdcRtnWarningActiveChangeField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///����
	TShfeFtdcDateType	MonDate;
	///ʱ��
	TShfeFtdcTimeType	MonTime;
	///�澯�¼�������־λ
	TShfeFtdcTypeIsActiveType	WarningActive;
};

///ͨ�ò���
struct CShfeFtdcReqQryGeneralOperateField
{
	///ͨ�ò�������
	TShfeFtdcGeneralOperateTypeType	GeneralOperateType;
	///ͨ�ò�����
	TShfeFtdcGeneralOperateTableType	GeneralOperateTable;
	///ͨ�ò���ѡ��
	TShfeFtdcGeneralOperateOptionType	GeneralOperateOption;
	///ͨ�ò�����
	TShfeFtdcGeneralOperateSetType	GeneralOperateSet;
};

///ͨ�ò���
struct CShfeFtdcRspQryGeneralOperateField
{
	///ͨ�ò�������
	TShfeFtdcGeneralOperateTypeType	GeneralOperateType;
	///ͨ�ò�����
	TShfeFtdcGeneralOperateTableType	GeneralOperateTable;
	///ͨ�ò���ѡ��
	TShfeFtdcGeneralOperateOptionType	GeneralOperateOption;
	///ͨ�ò�����
	TShfeFtdcGeneralOperateSetType	GeneralOperateSet;
};

///ͨ�ò���
struct CShfeFtdcRtnGeneralOperateField
{
	///ͨ�ò�������
	TShfeFtdcGeneralOperateTypeType	GeneralOperateType;
	///ͨ�ò�����
	TShfeFtdcGeneralOperateTableType	GeneralOperateTable;
	///ͨ�ò���ѡ��
	TShfeFtdcGeneralOperateOptionType	GeneralOperateOption;
	///ͨ�ò�����
	TShfeFtdcGeneralOperateSetType	GeneralOperateSet;
};

///�����豸���ӹ�ϵ����
struct CShfeFtdcReqQryNetDeviceLinkedField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///��Ϊ���ֵ�ְ������
	TShfeFtdcTypeObjectIDType	FuctionArea;
	///IP��
	TShfeFtdcVolumeType	IPDECODE;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
};

///�����豸���ӹ�ϵ
struct CShfeFtdcRspQryNetDeviceLinkedField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�豸ID
	TShfeFtdcVolumeType	NetDeviceID;
	///�豸�˿�ID
	TShfeFtdcVolumeType	NetPortID;
	///��ض���
	TShfeFtdcNetObjectIDType	NetObjectID;
	///��ض���˿�����
	TShfeFtdcNetDevicePortTypeType	NetPortType;
	///�����豸ID
	TShfeFtdcVolumeType	LinkNetDeviceID;
	///�����豸�˿�ID
	TShfeFtdcVolumeType	LinkNetPortID;
	///���Ӷ���
	TShfeFtdcNetObjectIDType	LinkNetObjectID;
	///���Ӷ���˿�����
	TShfeFtdcNetDevicePortTypeType	LinkNetPortType;
	///������Դ
	TShfeFtdcVolumeType	LinkSource;
};

///�����豸���ӹ�ϵ
struct CShfeFtdcRtnNetDeviceLinkedField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�豸ID
	TShfeFtdcVolumeType	NetDeviceID;
	///�豸�˿�ID
	TShfeFtdcVolumeType	NetPortID;
	///��ض���
	TShfeFtdcNetObjectIDType	NetObjectID;
	///��ض���˿�����
	TShfeFtdcNetDevicePortTypeType	NetPortType;
	///�����豸ID
	TShfeFtdcVolumeType	LinkNetDeviceID;
	///�����豸�˿�ID
	TShfeFtdcVolumeType	LinkNetPortID;
	///���Ӷ���
	TShfeFtdcNetObjectIDType	LinkNetObjectID;
	///���Ӷ���˿�����
	TShfeFtdcNetDevicePortTypeType	LinkNetPortType;
	///������Դ
	TShfeFtdcVolumeType	LinkSource;
};

///����ϵͳ��¼��Ϣ����
struct CShfeFtdcReqQryTradeUserLoginStatField
{
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
};

///����ϵͳ��¼��Ϣ
struct CShfeFtdcRspQryTradeUserLoginStatField
{
	///��¼����
	TShfeFtdcDateType	MonDate;
	///��¼ʱ��
	TShfeFtdcTimeType	MonTime;
	///��ض���
	TShfeFtdcTypeObjectIDType	ObjectID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///��Ա����
	TShfeFtdcParticipantIDType	ParticipantID;
	///�����û�����
	TShfeFtdcUserIDType	UserID;
	///ǰ�û���
	TShfeFtdcTypeObjectIDType	FrontId;
};

///ʵʱ�����������
struct CShfeFtdcReqQryRealTimeNetObjectAttrField
{
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///������ָ������
	TShfeFtdcNetAttrTypeType	AttrType;
};

///�����������
struct CShfeFtdcReqQryNetAreaField
{
	///ID
	TShfeFtdcVolumeType	ID;
};

///�������Ӧ��
struct CShfeFtdcRspQryNetAreaField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�������Ӧ��
struct CShfeFtdcRtnNetAreaField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�����������
struct CShfeFtdcReqQryNetSubAreaField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetArea
	TShfeFtdcVolumeType	SysNetAreaID;
};

///�������Ӧ��
struct CShfeFtdcRspQryNetSubAreaField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetArea
	TShfeFtdcVolumeType	SysNetAreaID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�������Ӧ��
struct CShfeFtdcRtnNetSubAreaField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetArea
	TShfeFtdcVolumeType	SysNetAreaID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�����������
struct CShfeFtdcReqQryNetSubAreaIPField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetArea
	TShfeFtdcVolumeType	SysNetAreaID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
};

///�������Ӧ��
struct CShfeFtdcRspQryNetSubAreaIPField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///ip��ַ
	TShfeFtdcIPAddressType	IP;
	///����
	TShfeFtdcIPAddressType	Mask;
};

///�������Ӧ��
struct CShfeFtdcRtnNetSubAreaIPField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///ip��ַ
	TShfeFtdcIPAddressType	IP;
	///����
	TShfeFtdcIPAddressType	Mask;
};

///�����豸̽������
struct CShfeFtdcReqQryNetDeviceDetectField
{
	///SysNetArea
	TShfeFtdcVolumeType	SysNetAreaID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///ip��ַ
	TShfeFtdcIPAddressType	IP;
	///����
	TShfeFtdcIPAddressType	Mask;
};

///�����豸��ѯ����
struct CShfeFtdcReqQryNetDeviceRequestField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///��Ϊ���ֵ�ְ������
	TShfeFtdcTypeObjectIDType	FuctionArea;
	///IP��
	TShfeFtdcVolumeType	IPDECODE;
};

///�����豸
struct CShfeFtdcRspQryNetDeviceField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��ض���
	TShfeFtdcNetObjectIDType	ObjectID;
	///��ض�������
	TShfeFtdcVolumeType	MonitorType_ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///����ID  
	TShfeFtdcVolumeType	CATEGORY_ID;
	///��Ϊ���ֵ�ְ������  
	TShfeFtdcTypeObjectIDType	FuctionArea;
	///IP��ַ  
	TShfeFtdcIPAddressType	IPADDR;
	///IP��    
	TShfeFtdcVolumeType	IPDECODE;
	///�豸���� 
	TShfeFtdcNetObjectIDType	NAME;
	///             
	TShfeFtdcVolumeType	PORTNUMBER;
	///          
	TShfeFtdcTypeObjectIDType	CONFIGFILE;
	///��ͬ����  
	TShfeFtdcTypeObjectIDType	RCOMMUNITY;
	///snmp�汾     
	TShfeFtdcVolumeType	SNMPVERSION;
	///ramsize(B)   
	TShfeFtdcVolumeType	RAMSIZE;
	///falshsize(B) 
	TShfeFtdcVolumeType	FLASHSIZE;
	///nvramsize(B) 
	TShfeFtdcVolumeType	NVRAMSIZE;
	///��������
	TShfeFtdcVolumeType	CABINET_ID;
	///
	TShfeFtdcVolumeType	ROOM_ID;
	///����汾
	TShfeFtdcVolumeType	IOSVERSION_ID;
	///ϵͳ����
	TShfeFtdcNetAttrTypeType	DESCRIPTION;
	///��¼�û���
	TShfeFtdcTypeObjectIDType	USERNAME;
	///��¼����
	TShfeFtdcNetAttrTypeType	PASSWD;
	///enable����
	TShfeFtdcNetAttrTypeType	ENPASSWD;
	///��������
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///���ñ���Э��
	TShfeFtdcVolumeType	CFGSAVETYPE;
	///�豸�ͺ�
	TShfeFtdcNetObjectIDType	DEVICETYPE;
	///�Ƿ���Ÿ澯
	TShfeFtdcVolumeType	SENDSMS;
	///�Ƿ��Զ�snmp̽��
	TShfeFtdcVolumeType	ISSNMP;
	///��λ��
	TShfeFtdcVolumeType	SLOTNUM;
	///�Ƿ��Զ�ping
	TShfeFtdcVolumeType	ISPING;
	///�˿�����
	TShfeFtdcVolumeType	IFNUM;
	///Ѳ�����
	TShfeFtdcVolumeType	APPLICATION_ID;
};

///�����豸
struct CShfeFtdcRtnNetDeviceField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��ض���
	TShfeFtdcNetObjectIDType	ObjectID;
	///��ض�������
	TShfeFtdcVolumeType	MonitorType_ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///����ID  
	TShfeFtdcVolumeType	CATEGORY_ID;
	///��Ϊ���ֵ�ְ������  
	TShfeFtdcTypeObjectIDType	FuctionArea;
	///IP��ַ  
	TShfeFtdcIPAddressType	IPADDR;
	///IP��    
	TShfeFtdcVolumeType	IPDECODE;
	///�豸���� 
	TShfeFtdcNetObjectIDType	NAME;
	///             
	TShfeFtdcVolumeType	PORTNUMBER;
	///          
	TShfeFtdcTypeObjectIDType	CONFIGFILE;
	///��ͬ����  
	TShfeFtdcTypeObjectIDType	RCOMMUNITY;
	///snmp�汾     
	TShfeFtdcVolumeType	SNMPVERSION;
	///ramsize(B)   
	TShfeFtdcVolumeType	RAMSIZE;
	///falshsize(B) 
	TShfeFtdcVolumeType	FLASHSIZE;
	///nvramsize(B) 
	TShfeFtdcVolumeType	NVRAMSIZE;
	///��������
	TShfeFtdcVolumeType	CABINET_ID;
	///
	TShfeFtdcVolumeType	ROOM_ID;
	///����汾
	TShfeFtdcVolumeType	IOSVERSION_ID;
	///ϵͳ����
	TShfeFtdcNetAttrTypeType	DESCRIPTION;
	///��¼�û���
	TShfeFtdcTypeObjectIDType	USERNAME;
	///��¼����
	TShfeFtdcNetAttrTypeType	PASSWD;
	///enable����
	TShfeFtdcNetAttrTypeType	ENPASSWD;
	///��������
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///���ñ���Э��
	TShfeFtdcVolumeType	CFGSAVETYPE;
	///�豸�ͺ�
	TShfeFtdcNetObjectIDType	DEVICETYPE;
	///�Ƿ���Ÿ澯
	TShfeFtdcVolumeType	SENDSMS;
	///�Ƿ��Զ�snmp̽��
	TShfeFtdcVolumeType	ISSNMP;
	///��λ��
	TShfeFtdcVolumeType	SLOTNUM;
	///�Ƿ��Զ�ping
	TShfeFtdcVolumeType	ISPING;
	///�˿�����
	TShfeFtdcVolumeType	IFNUM;
	///Ѳ�����
	TShfeFtdcVolumeType	APPLICATION_ID;
};

///�����豸̽������Ӧ��
struct CShfeFtdcRspQryNetDeviceDetectField
{
	///SysNetArea
	TShfeFtdcVolumeType	SysNetAreaID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///ip��ַ
	TShfeFtdcIPAddressType	IP;
	///����
	TShfeFtdcIPAddressType	Mask;
};

///��¥��ѯ
struct CShfeFtdcReqQryNetBuildingField
{
	///ID
	TShfeFtdcVolumeType	ID;
};

///��¥
struct CShfeFtdcRspQryNetBuildingField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///��¥
struct CShfeFtdcRtnNetBuildingField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///������ѯ
struct CShfeFtdcReqQryNetRoomField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetBuildingID
	TShfeFtdcVolumeType	SysNetBuildingID;
};

///����
struct CShfeFtdcRspQryNetRoomField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��¥
	TShfeFtdcVolumeType	SysNetBuildingID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///����
struct CShfeFtdcRtnNetRoomField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��¥
	TShfeFtdcVolumeType	SysNetBuildingID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///����
struct CShfeFtdcReqQryNetCabinetsField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetRoomID
	TShfeFtdcVolumeType	SysNetRoomID;
	///SysNetBuildingID
	TShfeFtdcVolumeType	SysNetBuildingID;
};

///����
struct CShfeFtdcRspQryNetCabinetsField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetRoomID
	TShfeFtdcVolumeType	SysNetRoomID;
	///SysNetBuildingID
	TShfeFtdcVolumeType	SysNetBuildingID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///��������
	TShfeFtdcTypeObjectIDType	CabinetsType;
};

///����
struct CShfeFtdcRtnNetCabinetsField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetRoomID
	TShfeFtdcVolumeType	SysNetRoomID;
	///SysNetBuildingID
	TShfeFtdcVolumeType	SysNetBuildingID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///��������
	TShfeFtdcTypeObjectIDType	CabinetsType;
};

///OID
struct CShfeFtdcReqQryNetOIDField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcTypeObjectIDType	Manufactory;
	///�豸�ͺ�
	TShfeFtdcTypeObjectIDType	DeviceType;
	///OID������
	TShfeFtdcTypeObjectIDType	CName;
	///OIDӢ����
	TShfeFtdcTypeObjectIDType	EName;
	///OID
	TShfeFtdcTypeObjectIDType	OID;
	///��λ
	TShfeFtdcTypeObjectIDType	Unit;
	///�Ƿ������־
	TShfeFtdcVolumeType	isTheTable;
};

///OID
struct CShfeFtdcRspQryNetOIDField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcTypeObjectIDType	Manufactory;
	///�豸�ͺ�
	TShfeFtdcTypeObjectIDType	DeviceType;
	///OID������
	TShfeFtdcTypeObjectIDType	CName;
	///OIDӢ����
	TShfeFtdcTypeObjectIDType	EName;
	///OID
	TShfeFtdcTypeObjectIDType	OID;
	///��λ
	TShfeFtdcTypeObjectIDType	Unit;
	///�Ƿ������־
	TShfeFtdcVolumeType	isTheTable;
};

///OID
struct CShfeFtdcRtnNetOIDField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcTypeObjectIDType	Manufactory;
	///�豸�ͺ�
	TShfeFtdcTypeObjectIDType	DeviceType;
	///OID������
	TShfeFtdcTypeObjectIDType	CName;
	///OIDӢ����
	TShfeFtdcTypeObjectIDType	EName;
	///OID
	TShfeFtdcTypeObjectIDType	OID;
	///��λ
	TShfeFtdcTypeObjectIDType	Unit;
	///�Ƿ������־
	TShfeFtdcVolumeType	isTheTable;
};

///ʱ�����
struct CShfeFtdcReqQryNetTimePolicyField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///ʱ�����������
	TShfeFtdcTypeObjectIDType	CName;
	///ʱ�����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///��������
	TShfeFtdcVolumeType	PolicyType;
	///���������ô�
	TShfeFtdcPolicyStringTypeType	PolicyString;
	///����������
	TShfeFtdcVolumeType	TradingDay;
	///����������
	TShfeFtdcNetAttrTypeType	Description;
	///��������
	TShfeFtdcVolumeType	Operation;
};

///ʱ�����
struct CShfeFtdcRspQryNetTimePolicyField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///ʱ�����������
	TShfeFtdcTypeObjectIDType	CName;
	///ʱ�����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///��������
	TShfeFtdcVolumeType	PolicyType;
	///���������ô�
	TShfeFtdcPolicyStringTypeType	PolicyString;
	///����������
	TShfeFtdcVolumeType	TradingDay;
	///����������
	TShfeFtdcNetAttrTypeType	Description;
	///��������
	TShfeFtdcVolumeType	Operation;
};

///ʱ�����
struct CShfeFtdcRtnNetTimePolicyField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///ʱ�����������
	TShfeFtdcTypeObjectIDType	CName;
	///ʱ�����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///��������
	TShfeFtdcVolumeType	PolicyType;
	///���������ô�
	TShfeFtdcPolicyStringTypeType	PolicyString;
	///����������
	TShfeFtdcVolumeType	TradingDay;
	///����������
	TShfeFtdcNetAttrTypeType	Description;
	///��������
	TShfeFtdcVolumeType	Operation;
};

///�ɼ������ѯ
struct CShfeFtdcReqQryNetGatherTaskField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///������ָ������
	TShfeFtdcNetAttrTypeType	AttrType;
	///ʱ�����ID
	TShfeFtdcVolumeType	PolicyTypeID;
	///��������
	TShfeFtdcVolumeType	DataType;
	///���ͱ�ʶ
	TShfeFtdcVolumeType	TypeFlag;
};

///�ɼ�����
struct CShfeFtdcRspQryNetGatherTaskField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///������ָ������
	TShfeFtdcNetAttrTypeType	AttrType;
	///ʱ�����ID
	TShfeFtdcVolumeType	PolicyTypeID;
	///��������
	TShfeFtdcVolumeType	DataType;
	///���ͱ�ʶ
	TShfeFtdcVolumeType	TypeFlag;
};

///�ɼ�����
struct CShfeFtdcRtnNetGatherTaskField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///������ָ������
	TShfeFtdcNetAttrTypeType	AttrType;
	///ʱ�����ID
	TShfeFtdcVolumeType	PolicyTypeID;
	///��������
	TShfeFtdcVolumeType	DataType;
	///���ͱ�ʶ
	TShfeFtdcVolumeType	TypeFlag;
};

///�ɼ������ѯ
struct CShfeFtdcReqQryNetDeviceChgField
{
	///�豸ID
	TShfeFtdcVolumeType	DeviceID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	OldObjectID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	NewObjectID;
};

///�ɼ�����
struct CShfeFtdcRspQryNetDeviceChgField
{
	///�豸ID
	TShfeFtdcVolumeType	DeviceID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	OldObjectID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	NewObjectID;
};

///�ɼ�����
struct CShfeFtdcRtnNetDeviceChgField
{
	///�豸ID
	TShfeFtdcVolumeType	DeviceID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	OldObjectID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	NewObjectID;
};

///�����豸�ͺ�����
struct CShfeFtdcReqQryNetDeviceTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcTypeObjectIDType	Manufactory;
	///�豸�ͺ�
	TShfeFtdcTypeObjectIDType	DeviceType;
};

///�����豸�ͺ�
struct CShfeFtdcRspQryNetDeviceTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcTypeObjectIDType	Manufactory;
	///�豸�ͺ�
	TShfeFtdcTypeObjectIDType	DeviceType;
};

///�����豸�ͺ�
struct CShfeFtdcRtnNetDeviceTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcTypeObjectIDType	Manufactory;
	///�豸�ͺ�
	TShfeFtdcTypeObjectIDType	DeviceType;
};

///�����豸�������
struct CShfeFtdcReqQryNetDeviceCategoryField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///���������
	TShfeFtdcTypeObjectIDType	CName;
	///���Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�����豸���
struct CShfeFtdcRspQryNetDeviceCategoryField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///���������
	TShfeFtdcTypeObjectIDType	CName;
	///���Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�����豸���
struct CShfeFtdcRtnNetDeviceCategoryField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///���������
	TShfeFtdcTypeObjectIDType	CName;
	///���Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�豸��������
struct CShfeFtdcReqQryNetManufactoryField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�豸����
struct CShfeFtdcRspQryNetManufactoryField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�豸����
struct CShfeFtdcRtnNetManufactoryField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�豸��ͬ������
struct CShfeFtdcReqQryNetCommunityField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPADDR;
	///��ͬ����
	TShfeFtdcTypeObjectIDType	COMMUNITY;
};

///�豸��ͬ��
struct CShfeFtdcRspQryNetCommunityField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPADDR;
	///��ͬ����
	TShfeFtdcTypeObjectIDType	COMMUNITY;
};

///�豸��ͬ��
struct CShfeFtdcRtnNetCommunityField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPADDR;
	///��ͬ����
	TShfeFtdcTypeObjectIDType	COMMUNITY;
};

///�˿���������
struct CShfeFtdcReqQryNetPortTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///������
	TShfeFtdcTypeObjectIDType	CName;
	///Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///����
	TShfeFtdcTypeObjectIDType	Description;
};

///�˿�����
struct CShfeFtdcRspQryNetPortTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///������
	TShfeFtdcTypeObjectIDType	CName;
	///Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///����
	TShfeFtdcTypeObjectIDType	Description;
};

///�˿�����
struct CShfeFtdcRtnNetPortTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///������
	TShfeFtdcTypeObjectIDType	CName;
	///Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///����
	TShfeFtdcTypeObjectIDType	Description;
};

///��Ա����ص�����
struct CShfeFtdcReqQryNetPartAccessSpotField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///������
	TShfeFtdcTypeObjectIDType	CName;
	///Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///��Ա����ص�
struct CShfeFtdcRspQryNetPartAccessSpotField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///������
	TShfeFtdcTypeObjectIDType	CName;
	///Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///��Ա����ص�
struct CShfeFtdcRtnNetPartAccessSpotField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///������
	TShfeFtdcTypeObjectIDType	CName;
	///Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�˿�����
struct CShfeFtdcReqQryNetInterfaceField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��ض���
	TShfeFtdcNetObjectIDType	ObjectID;
	///��ض�������
	TShfeFtdcVolumeType	MonitorType_ID;
	///�˿�����
	TShfeFtdcVolumeType	IfType;
	///�˿���
	TShfeFtdcTypeObjectIDType	EName;
	///IP��ַ
	TShfeFtdcIPAddressType	IpAddress;
	///����
	TShfeFtdcIPAddressType	IpMask;
	///�˿�״̬
	TShfeFtdcVolumeType	IfStatus;
	///�����ַ
	TShfeFtdcTypeObjectIDType	MAC;
	///�����豸ID
	TShfeFtdcVolumeType	DeviceID;
	///�����豸ObjectID
	TShfeFtdcNetObjectIDType	DeviceObjectID;
	///�����豸�˿�����
	TShfeFtdcTypeObjectNameType	DeviceIndex;
	///�Ƿ���ѯ
	TShfeFtdcVolumeType	isPolling;
	///����
	TShfeFtdcTypeObjectIDType	Description;
};

///�˿�
struct CShfeFtdcRspQryNetInterfaceField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��ض���
	TShfeFtdcNetObjectIDType	ObjectID;
	///��ض�������
	TShfeFtdcVolumeType	MonitorType_ID;
	///�˿�����
	TShfeFtdcVolumeType	IfType;
	///�˿���
	TShfeFtdcTypeObjectIDType	EName;
	///IP��ַ
	TShfeFtdcIPAddressType	IpAddress;
	///����
	TShfeFtdcIPAddressType	IpMask;
	///�˿�״̬
	TShfeFtdcVolumeType	IfStatus;
	///�����ַ
	TShfeFtdcTypeObjectIDType	MAC;
	///�����豸ID
	TShfeFtdcVolumeType	DeviceID;
	///�����豸ObjectID
	TShfeFtdcNetObjectIDType	DeviceObjectID;
	///�����豸�˿�����
	TShfeFtdcTypeObjectNameType	DeviceIndex;
	///�Ƿ���ѯ
	TShfeFtdcVolumeType	isPolling;
	///����
	TShfeFtdcTypeObjectIDType	Description;
};

///�˿�
struct CShfeFtdcRtnNetInterfaceField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��ض���
	TShfeFtdcNetObjectIDType	ObjectID;
	///��ض�������
	TShfeFtdcVolumeType	MonitorType_ID;
	///�˿�����
	TShfeFtdcVolumeType	IfType;
	///�˿���
	TShfeFtdcTypeObjectIDType	EName;
	///IP��ַ
	TShfeFtdcIPAddressType	IpAddress;
	///����
	TShfeFtdcIPAddressType	IpMask;
	///�˿�״̬
	TShfeFtdcVolumeType	IfStatus;
	///�����ַ
	TShfeFtdcTypeObjectIDType	MAC;
	///�����豸ID
	TShfeFtdcVolumeType	DeviceID;
	///�����豸ObjectID
	TShfeFtdcNetObjectIDType	DeviceObjectID;
	///�����豸�˿�����
	TShfeFtdcTypeObjectNameType	DeviceIndex;
	///�Ƿ���ѯ
	TShfeFtdcVolumeType	isPolling;
	///����
	TShfeFtdcTypeObjectIDType	Description;
};

///GeneralOID
struct CShfeFtdcReqQryNetGeneralOIDField
{
	///ID
	TShfeFtdcVolumeType	ID;
};

///GeneralOID
struct CShfeFtdcRspQryNetGeneralOIDField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///OID������
	TShfeFtdcTypeObjectIDType	CName;
	///OIDӢ����
	TShfeFtdcTypeObjectIDType	EName;
	///OID
	TShfeFtdcTypeObjectIDType	OID;
	///��λ
	TShfeFtdcTypeObjectIDType	Unit;
	///�Ƿ������־
	TShfeFtdcVolumeType	isTheTable;
};

///GeneralOID
struct CShfeFtdcRtnNetGeneralOIDField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///OID������
	TShfeFtdcTypeObjectIDType	CName;
	///OIDӢ����
	TShfeFtdcTypeObjectIDType	EName;
	///OID
	TShfeFtdcTypeObjectIDType	OID;
	///��λ
	TShfeFtdcTypeObjectIDType	Unit;
	///�Ƿ������־
	TShfeFtdcVolumeType	isTheTable;
};

///��ض������
struct CShfeFtdcReqQryNetMonitorTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///OID������
	TShfeFtdcTypeObjectIDType	CName;
	///OIDӢ����
	TShfeFtdcTypeObjectIDType	EName;
};

///��ض������
struct CShfeFtdcRspQryNetMonitorTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///OID������
	TShfeFtdcTypeObjectIDType	CName;
	///OIDӢ����
	TShfeFtdcTypeObjectIDType	EName;
};

///��ض������
struct CShfeFtdcRtnNetMonitorTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///OID������
	TShfeFtdcTypeObjectIDType	CName;
	///OIDӢ����
	TShfeFtdcTypeObjectIDType	EName;
};

///ָ��ͳ��
struct CShfeFtdcReqQryNetMonitorAttrScopeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///ָ��������
	TShfeFtdcNetAttrTypeType	CName;
	///ָ��Ӣ����
	TShfeFtdcNetAttrTypeType	EName;
	///ע��
	TShfeFtdcNetAttrTypeType	Comments;
};

///ָ��ͳ��
struct CShfeFtdcRspQryNetMonitorAttrScopeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///ָ��������
	TShfeFtdcNetAttrTypeType	CName;
	///ָ��Ӣ����
	TShfeFtdcNetAttrTypeType	EName;
	///ע��
	TShfeFtdcNetAttrTypeType	Comments;
};

///ָ��ͳ��
struct CShfeFtdcRtnNetMonitorAttrScopeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///ָ��������
	TShfeFtdcNetAttrTypeType	CName;
	///ָ��Ӣ����
	TShfeFtdcNetAttrTypeType	EName;
	///ע��
	TShfeFtdcNetAttrTypeType	Comments;
};

///���ָ���
struct CShfeFtdcReqQryNetMonitorAttrTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///�豸���
	TShfeFtdcVolumeType	MonitorType_ID;
	///������ָ��ID
	TShfeFtdcVolumeType	AttrType_ID;
	///��������
	TShfeFtdcTypeObjectIDType	MANUFACTORY;
	///�豸���
	TShfeFtdcTypeObjectIDType	MonitorType;
	///������ָ��
	TShfeFtdcNetAttrTypeType	AttrType;
};

///���ָ���
struct CShfeFtdcRspQryNetMonitorAttrTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///�豸���
	TShfeFtdcVolumeType	MonitorType_ID;
	///������ָ��ID
	TShfeFtdcVolumeType	AttrType_ID;
	///��������
	TShfeFtdcTypeObjectIDType	MANUFACTORY;
	///�豸���
	TShfeFtdcTypeObjectIDType	MonitorType;
	///������ָ��
	TShfeFtdcNetAttrTypeType	AttrType;
};

///���ָ���
struct CShfeFtdcRtnNetMonitorAttrTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///�豸���
	TShfeFtdcVolumeType	MonitorType_ID;
	///������ָ��ID
	TShfeFtdcVolumeType	AttrType_ID;
	///��������
	TShfeFtdcTypeObjectIDType	MANUFACTORY;
	///�豸���
	TShfeFtdcTypeObjectIDType	MonitorType;
	///������ָ��
	TShfeFtdcNetAttrTypeType	AttrType;
};

///��ض���ָ���
struct CShfeFtdcReqQryNetMonitorObjectAttrField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��ض���
	TShfeFtdcNetObjectIDType	ObjectID;
	///������ָ��
	TShfeFtdcNetAttrTypeType	AttrType;
	///ʱ�����ID
	TShfeFtdcVolumeType	PolicyTypeID;
};

///��ض���ָ���
struct CShfeFtdcRspQryNetMonitorObjectAttrField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��ض���
	TShfeFtdcNetObjectIDType	ObjectID;
	///������ָ��
	TShfeFtdcNetAttrTypeType	AttrType;
	///ʱ�����ID
	TShfeFtdcVolumeType	PolicyTypeID;
};

///��ض���ָ���
struct CShfeFtdcRtnNetMonitorObjectAttrField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��ض���
	TShfeFtdcNetObjectIDType	ObjectID;
	///������ָ��
	TShfeFtdcNetAttrTypeType	AttrType;
	///ʱ�����ID
	TShfeFtdcVolumeType	PolicyTypeID;
};

///ְ����
struct CShfeFtdcReqQryNetFuncAreaField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///ְ����
struct CShfeFtdcRspQryNetFuncAreaField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///ְ����
struct CShfeFtdcRtnNetFuncAreaField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///���ָ���
struct CShfeFtdcReqQryNetMonitorCommandTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///�豸���ID
	TShfeFtdcVolumeType	MonitorType_ID;
	///�豸�ͺ�ID
	TShfeFtdcVolumeType	DeviceModle_ID;
	///������ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///��������
	TShfeFtdcTypeObjectIDType	Manufactory;
	///�豸���
	TShfeFtdcTypeObjectIDType	MonitorType;
	///�豸�ͺ�
	TShfeFtdcTypeObjectIDType	DeviceModle;
	///������
	TShfeFtdcTypeObjectIDType	ActionGroup;
	///ָ����
	TShfeFtdcNetAttrTypeType	Command;
};

///���ָ���
struct CShfeFtdcRspQryNetMonitorCommandTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///�豸���ID
	TShfeFtdcVolumeType	MonitorType_ID;
	///�豸�ͺ�ID
	TShfeFtdcVolumeType	DeviceModle_ID;
	///������ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///��������
	TShfeFtdcTypeObjectIDType	Manufactory;
	///�豸���
	TShfeFtdcTypeObjectIDType	MonitorType;
	///�豸�ͺ�
	TShfeFtdcTypeObjectIDType	DeviceModle;
	///������
	TShfeFtdcTypeObjectIDType	ActionGroup;
	///ָ����
	TShfeFtdcNetAttrTypeType	Command;
};

///���ָ���
struct CShfeFtdcRtnNetMonitorCommandTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///�豸���ID
	TShfeFtdcVolumeType	MonitorType_ID;
	///�豸�ͺ�ID
	TShfeFtdcVolumeType	DeviceModle_ID;
	///������ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///��������
	TShfeFtdcTypeObjectIDType	Manufactory;
	///�豸���
	TShfeFtdcTypeObjectIDType	MonitorType;
	///�豸�ͺ�
	TShfeFtdcTypeObjectIDType	DeviceModle;
	///������
	TShfeFtdcTypeObjectIDType	ActionGroup;
	///ָ����
	TShfeFtdcNetAttrTypeType	Command;
};

///�������
struct CShfeFtdcReqQryNetMonitorActionGroupField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///������������
	TShfeFtdcTypeObjectIDType	CName;
	///������Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///����������
	TShfeFtdcVolumeType	ActionType;
	///ע��
	TShfeFtdcNetAttrTypeType	Comments;
};

///�������
struct CShfeFtdcRspQryNetMonitorActionGroupField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///������������
	TShfeFtdcTypeObjectIDType	CName;
	///������Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///����������
	TShfeFtdcVolumeType	ActionType;
	///ע��
	TShfeFtdcNetAttrTypeType	Comments;
};

///�������
struct CShfeFtdcRtnNetMonitorActionGroupField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///������������
	TShfeFtdcTypeObjectIDType	CName;
	///������Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///����������
	TShfeFtdcVolumeType	ActionType;
	///ע��
	TShfeFtdcNetAttrTypeType	Comments;
};

///�豸�������
struct CShfeFtdcReqQryNetMonitorDeviceGroupField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�豸������������
	TShfeFtdcTypeObjectIDType	CName;
	///�豸������Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///�豸��������
	TShfeFtdcNetAttrTypeType	Condition;
	///ע��
	TShfeFtdcNetAttrTypeType	Comments;
};

///�豸�������
struct CShfeFtdcRspQryNetMonitorDeviceGroupField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�豸������������
	TShfeFtdcTypeObjectIDType	CName;
	///�豸������Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///�豸��������
	TShfeFtdcNetAttrTypeType	Condition;
	///ע��
	TShfeFtdcNetAttrTypeType	Comments;
};

///�豸�������
struct CShfeFtdcRtnNetMonitorDeviceGroupField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�豸������������
	TShfeFtdcTypeObjectIDType	CName;
	///�豸������Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///�豸��������
	TShfeFtdcNetAttrTypeType	Condition;
	///ע��
	TShfeFtdcNetAttrTypeType	Comments;
};

///������Ϣ��
struct CShfeFtdcReqQryNetMonitorTaskInfoField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///�豸������ID
	TShfeFtdcVolumeType	DeviceGroup_ID;
	///������Ա������ID
	TShfeFtdcVolumeType	ManagerGroup_ID;
	///����ʱ�����ID
	TShfeFtdcVolumeType	TimePolicy_ID;
	///�������ȼ�ID
	TShfeFtdcVolumeType	TaskPriority_ID;
	///����������ID
	TShfeFtdcVolumeType	OutputPolicy_ID;
	///��������ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///������ʽID���ϴ�
	TShfeFtdcGeneralResultType	EventExprStr;
	///�豸������
	TShfeFtdcTypeObjectIDType	DeviceGroup;
	///������Ա������
	TShfeFtdcTypeObjectIDType	ManagerGroup;
	///����ʱ�����
	TShfeFtdcTypeObjectIDType	TimePolicy;
	///�������ȼ�
	TShfeFtdcTypeObjectIDType	TaskPriority;
	///����������
	TShfeFtdcTypeObjectIDType	OutputPolicy;
	///��������
	TShfeFtdcTypeObjectIDType	ActionGroup;
	///������Ч�Ա�ʶ
	TShfeFtdcVolumeType	ValidFlag;
	///����״̬��ʶ
	TShfeFtdcVolumeType	TaskStatus;
	///��������
	TShfeFtdcNetAttrTypeType	Comments;
};

///������Ϣ��
struct CShfeFtdcRspQryNetMonitorTaskInfoField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///�豸������ID
	TShfeFtdcVolumeType	DeviceGroup_ID;
	///������Ա������ID
	TShfeFtdcVolumeType	ManagerGroup_ID;
	///����ʱ�����ID
	TShfeFtdcVolumeType	TimePolicy_ID;
	///�������ȼ�ID
	TShfeFtdcVolumeType	TaskPriority_ID;
	///����������ID
	TShfeFtdcVolumeType	OutputPolicy_ID;
	///��������ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///������ʽID���ϴ�
	TShfeFtdcGeneralResultType	EventExprStr;
	///�豸������
	TShfeFtdcTypeObjectIDType	DeviceGroup;
	///������Ա������
	TShfeFtdcTypeObjectIDType	ManagerGroup;
	///����ʱ�����
	TShfeFtdcTypeObjectIDType	TimePolicy;
	///�������ȼ�
	TShfeFtdcTypeObjectIDType	TaskPriority;
	///����������
	TShfeFtdcTypeObjectIDType	OutputPolicy;
	///��������
	TShfeFtdcTypeObjectIDType	ActionGroup;
	///������Ч�Ա�ʶ
	TShfeFtdcVolumeType	ValidFlag;
	///����״̬��ʶ
	TShfeFtdcVolumeType	TaskStatus;
	///��������
	TShfeFtdcNetAttrTypeType	Comments;
};

///������Ϣ��
struct CShfeFtdcRtnNetMonitorTaskInfoField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///�豸������ID
	TShfeFtdcVolumeType	DeviceGroup_ID;
	///������Ա������ID
	TShfeFtdcVolumeType	ManagerGroup_ID;
	///����ʱ�����ID
	TShfeFtdcVolumeType	TimePolicy_ID;
	///�������ȼ�ID
	TShfeFtdcVolumeType	TaskPriority_ID;
	///����������ID
	TShfeFtdcVolumeType	OutputPolicy_ID;
	///��������ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///������ʽID���ϴ�
	TShfeFtdcGeneralResultType	EventExprStr;
	///�豸������
	TShfeFtdcTypeObjectIDType	DeviceGroup;
	///������Ա������
	TShfeFtdcTypeObjectIDType	ManagerGroup;
	///����ʱ�����
	TShfeFtdcTypeObjectIDType	TimePolicy;
	///�������ȼ�
	TShfeFtdcTypeObjectIDType	TaskPriority;
	///����������
	TShfeFtdcTypeObjectIDType	OutputPolicy;
	///��������
	TShfeFtdcTypeObjectIDType	ActionGroup;
	///������Ч�Ա�ʶ
	TShfeFtdcVolumeType	ValidFlag;
	///����״̬��ʶ
	TShfeFtdcVolumeType	TaskStatus;
	///��������
	TShfeFtdcNetAttrTypeType	Comments;
};

///��������
struct CShfeFtdcReqQryNetMonitorTaskResultField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///����ID
	TShfeFtdcVolumeType	Task_ID;
	///ִ�д���
	TShfeFtdcVolumeType	OperateTime;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///ָ�
	TShfeFtdcNetAttrTypeType	InstructChain;
	///�����
	TShfeFtdcGeneralResultType	ResultChain;
	///����ִ�б�ʶ
	TShfeFtdcVolumeType	Flag;
};

///��������
struct CShfeFtdcRspQryNetMonitorTaskResultField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///����ID
	TShfeFtdcVolumeType	Task_ID;
	///ִ�д���
	TShfeFtdcVolumeType	OperateTime;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///ָ�
	TShfeFtdcNetAttrTypeType	InstructChain;
	///�����
	TShfeFtdcGeneralResultType	ResultChain;
	///����ִ�б�ʶ
	TShfeFtdcVolumeType	Flag;
};

///��������
struct CShfeFtdcRtnNetMonitorTaskResultField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///����ID
	TShfeFtdcVolumeType	Task_ID;
	///ִ�д���
	TShfeFtdcVolumeType	OperateTime;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///ָ�
	TShfeFtdcNetAttrTypeType	InstructChain;
	///�����
	TShfeFtdcGeneralResultType	ResultChain;
	///����ִ�б�ʶ
	TShfeFtdcVolumeType	Flag;
};

///�������
struct CShfeFtdcReqQryNetMonitorTaskObjectSetField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�豸������ID
	TShfeFtdcVolumeType	DeviceGroup_ID;
	///�豸ID
	TShfeFtdcVolumeType	Device_ID;
	///DataCenter
	TShfeFtdcDataCenterFlagType	DataCenter;
};

///�������
struct CShfeFtdcRspQryNetMonitorTaskObjectSetField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�豸������ID
	TShfeFtdcVolumeType	DeviceGroup_ID;
	///�豸ID
	TShfeFtdcVolumeType	Device_ID;
	///DataCenter
	TShfeFtdcDataCenterFlagType	DataCenter;
};

///�������
struct CShfeFtdcRtnNetMonitorTaskObjectSetField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�豸������ID
	TShfeFtdcVolumeType	DeviceGroup_ID;
	///�豸ID
	TShfeFtdcVolumeType	Device_ID;
	///DataCenter
	TShfeFtdcDataCenterFlagType	DataCenter;
};

///��Ա��·��Ϣ��
struct CShfeFtdcReqQryNetPartyLinkInfoField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��Ա��
	TShfeFtdcCfgNameType	MEMBER_NO;
	///��Ա����
	TShfeFtdcTypeObjectIDType	MEMBER_NAME;
	///��Ա����ص�
	TShfeFtdcTypeObjectIDType	REMOTE_ADDR;
	///�����������
	TShfeFtdcTypeObjectIDType	LOCAL_ADDR;
	///��ַ
	TShfeFtdcNetAttrTypeType	ADDRESS;
	///��·״̬
	TShfeFtdcCfgNameType	LINE_STATUS;
	///��ϵ��
	TShfeFtdcCfgNameType	CONTACT;
	///��ϵ�绰
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///�ֻ���
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	TShfeFtdcTypeObjectIDType	EMAIL;
	///����
	TShfeFtdcTypeObjectIDType	FAX;
	///����ʡ��
	TShfeFtdcCfgNameType	PROVINCE;
	///��·���
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///���뷽ʽ
	TShfeFtdcTypeObjectIDType	IN_MODE;
	///����IP����
	TShfeFtdcTypeObjectIDType	IP_WAN;
	///����IP����
	TShfeFtdcTypeObjectIDType	IP_LAN;
	///·��������IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///·�����˿ں�
	TShfeFtdcTypeObjectIDType	Interface;
	///�ӿڿ�ͨ����
	TShfeFtdcCfgNameType	INTERFACE_DATE;
	///�������
	TShfeFtdcCfgNameType	SOFTWARE;
	///��������
	TShfeFtdcCfgNameType	FEE_TYPE;
	///��Ӫ��
	TShfeFtdcCfgNameType	SERVICEPROVIDER;
	///�Ƿ���Ӫ
	TShfeFtdcCfgNameType	IF_ZIYING;
	///�Ƿ��й�
	TShfeFtdcCfgNameType	IF_TUOGUAN;
	///����������·
	TShfeFtdcCfgNameType	HASOTHER;
	///ϯλ��
	TShfeFtdcCfgNameType	SEAT_NO;
	///��ע
	TShfeFtdcNetAttrTypeType	PRO;
};

///��Ա��·��Ϣ��
struct CShfeFtdcRspQryNetPartyLinkInfoField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��Ա��
	TShfeFtdcCfgNameType	MEMBER_NO;
	///��Ա����
	TShfeFtdcTypeObjectIDType	MEMBER_NAME;
	///��Ա����ص�
	TShfeFtdcTypeObjectIDType	REMOTE_ADDR;
	///�����������
	TShfeFtdcTypeObjectIDType	LOCAL_ADDR;
	///��ַ
	TShfeFtdcNetAttrTypeType	ADDRESS;
	///��·״̬
	TShfeFtdcCfgNameType	LINE_STATUS;
	///��ϵ��
	TShfeFtdcCfgNameType	CONTACT;
	///��ϵ�绰
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///�ֻ���
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	TShfeFtdcTypeObjectIDType	EMAIL;
	///����
	TShfeFtdcTypeObjectIDType	FAX;
	///����ʡ��
	TShfeFtdcCfgNameType	PROVINCE;
	///��·���
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///���뷽ʽ
	TShfeFtdcTypeObjectIDType	IN_MODE;
	///����IP����
	TShfeFtdcTypeObjectIDType	IP_WAN;
	///����IP����
	TShfeFtdcTypeObjectIDType	IP_LAN;
	///·��������IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///·�����˿ں�
	TShfeFtdcTypeObjectIDType	Interface;
	///�ӿڿ�ͨ����
	TShfeFtdcCfgNameType	INTERFACE_DATE;
	///�������
	TShfeFtdcCfgNameType	SOFTWARE;
	///��������
	TShfeFtdcCfgNameType	FEE_TYPE;
	///��Ӫ��
	TShfeFtdcCfgNameType	SERVICEPROVIDER;
	///�Ƿ���Ӫ
	TShfeFtdcCfgNameType	IF_ZIYING;
	///�Ƿ��й�
	TShfeFtdcCfgNameType	IF_TUOGUAN;
	///����������·
	TShfeFtdcCfgNameType	HASOTHER;
	///ϯλ��
	TShfeFtdcCfgNameType	SEAT_NO;
	///��ע
	TShfeFtdcNetAttrTypeType	PRO;
};

///��Ա��·��Ϣ��
struct CShfeFtdcRtnNetPartyLinkInfoField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��Ա��
	TShfeFtdcCfgNameType	MEMBER_NO;
	///��Ա����
	TShfeFtdcTypeObjectIDType	MEMBER_NAME;
	///��Ա����ص�
	TShfeFtdcTypeObjectIDType	REMOTE_ADDR;
	///�����������
	TShfeFtdcTypeObjectIDType	LOCAL_ADDR;
	///��ַ
	TShfeFtdcNetAttrTypeType	ADDRESS;
	///��·״̬
	TShfeFtdcCfgNameType	LINE_STATUS;
	///��ϵ��
	TShfeFtdcCfgNameType	CONTACT;
	///��ϵ�绰
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///�ֻ���
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	TShfeFtdcTypeObjectIDType	EMAIL;
	///����
	TShfeFtdcTypeObjectIDType	FAX;
	///����ʡ��
	TShfeFtdcCfgNameType	PROVINCE;
	///��·���
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///���뷽ʽ
	TShfeFtdcTypeObjectIDType	IN_MODE;
	///����IP����
	TShfeFtdcTypeObjectIDType	IP_WAN;
	///����IP����
	TShfeFtdcTypeObjectIDType	IP_LAN;
	///·��������IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///·�����˿ں�
	TShfeFtdcTypeObjectIDType	Interface;
	///�ӿڿ�ͨ����
	TShfeFtdcCfgNameType	INTERFACE_DATE;
	///�������
	TShfeFtdcCfgNameType	SOFTWARE;
	///��������
	TShfeFtdcCfgNameType	FEE_TYPE;
	///��Ӫ��
	TShfeFtdcCfgNameType	SERVICEPROVIDER;
	///�Ƿ���Ӫ
	TShfeFtdcCfgNameType	IF_ZIYING;
	///�Ƿ��й�
	TShfeFtdcCfgNameType	IF_TUOGUAN;
	///����������·
	TShfeFtdcCfgNameType	HASOTHER;
	///ϯλ��
	TShfeFtdcCfgNameType	SEAT_NO;
	///��ע
	TShfeFtdcNetAttrTypeType	PRO;
};

///��ض���ָ����ձ�
struct CShfeFtdcReqQryNetMonitorActionAttrField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///������ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///��ض���ID
	TShfeFtdcVolumeType	MonitorAttr_ID;
	///ָ��Ӣ����
	TShfeFtdcNetAttrTypeType	MonitorAttrName;
};

///��ض���ָ����ձ�
struct CShfeFtdcRspQryNetMonitorActionAttrField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///������ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///��ض���ID
	TShfeFtdcVolumeType	MonitorAttr_ID;
	///ָ��Ӣ����
	TShfeFtdcNetAttrTypeType	MonitorAttrName;
};

///��ض���ָ����ձ�
struct CShfeFtdcRtnNetMonitorActionAttrField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///������ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///��ض���ID
	TShfeFtdcVolumeType	MonitorAttr_ID;
	///ָ��Ӣ����
	TShfeFtdcNetAttrTypeType	MonitorAttrName;
};

///ģ��
struct CShfeFtdcReqQryNetModuleField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///��ض�������
	TShfeFtdcVolumeType	MonitorType_ID;
	///�����豸ID
	TShfeFtdcVolumeType	DeviceID;
	///�����豸ObjectID
	TShfeFtdcNetObjectIDType	DeviceObjectID;
	///����
	TShfeFtdcTypeObjectIDType	Name;
	///����
	TShfeFtdcNetObjectIDType	Description;
	///ģ������
	TShfeFtdcVolumeType	ModuleIndex;
	///��������
	TShfeFtdcVolumeType	EntPhyIndex;
};

///ģ��
struct CShfeFtdcRspQryNetModuleField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///��ض�������
	TShfeFtdcVolumeType	MonitorType_ID;
	///�����豸ID
	TShfeFtdcVolumeType	DeviceID;
	///�����豸ObjectID
	TShfeFtdcNetObjectIDType	DeviceObjectID;
	///����
	TShfeFtdcTypeObjectIDType	Name;
	///����
	TShfeFtdcNetObjectIDType	Description;
	///ģ������
	TShfeFtdcVolumeType	ModuleIndex;
	///��������
	TShfeFtdcVolumeType	EntPhyIndex;
};

///ģ��
struct CShfeFtdcRtnNetModuleField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///��ض�������
	TShfeFtdcVolumeType	MonitorType_ID;
	///�����豸ID
	TShfeFtdcVolumeType	DeviceID;
	///�����豸ObjectID
	TShfeFtdcNetObjectIDType	DeviceObjectID;
	///����
	TShfeFtdcTypeObjectIDType	Name;
	///����
	TShfeFtdcNetObjectIDType	Description;
	///ģ������
	TShfeFtdcVolumeType	ModuleIndex;
	///��������
	TShfeFtdcVolumeType	EntPhyIndex;
};

///�澯���ʽ��Ϣ��
struct CShfeFtdcReqQryNetEventExprField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�����¼���
	TShfeFtdcNetObjectIDType	CNAME;
	///Ӣ���¼���
	TShfeFtdcNetObjectIDType	ENAME;
	///�¼�����
	TShfeFtdcCfgNameType	WarningLEVEL;
	///�¼�����
	TShfeFtdcVolumeType	EventTypeID;
	///�¼�������
	TShfeFtdcVolumeType	SubEventTypeID;
	///�澯���ʱ��
	TShfeFtdcVolumeType	GIVEUPTIME;
	///���ƶ�����
	TShfeFtdcGeneralResultType	CONTROL;
	///���ʽ������
	TShfeFtdcGeneralResultType	EXPR;
	///�¼�����
	TShfeFtdcTypeObjectIDType	BRIEF;
	///�¼�������
	TShfeFtdcNetAttrTypeType	DISCRIPTION;
	///��Ϣ��ID
	TShfeFtdcVolumeType	MSGGROUP_ID;
	///����Ա��ID
	TShfeFtdcVolumeType	ADMINGROUP_ID;
};

///�澯���ʽ��Ϣ��
struct CShfeFtdcRspQryNetEventExprField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�����¼���
	TShfeFtdcNetObjectIDType	CNAME;
	///Ӣ���¼���
	TShfeFtdcNetObjectIDType	ENAME;
	///�¼�����
	TShfeFtdcCfgNameType	WarningLEVEL;
	///�¼�����
	TShfeFtdcVolumeType	EventTypeID;
	///�¼�������
	TShfeFtdcVolumeType	SubEventTypeID;
	///�澯���ʱ��
	TShfeFtdcVolumeType	GIVEUPTIME;
	///���ƶ�����
	TShfeFtdcGeneralResultType	CONTROL;
	///���ʽ������
	TShfeFtdcGeneralResultType	EXPR;
	///�¼�����
	TShfeFtdcTypeObjectIDType	BRIEF;
	///�¼�������
	TShfeFtdcNetAttrTypeType	DISCRIPTION;
	///��Ϣ��ID
	TShfeFtdcVolumeType	MSGGROUP_ID;
	///����Ա��ID
	TShfeFtdcVolumeType	ADMINGROUP_ID;
};

///�澯���ʽ��Ϣ��
struct CShfeFtdcRtnNetEventExprField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�����¼���
	TShfeFtdcNetObjectIDType	CNAME;
	///Ӣ���¼���
	TShfeFtdcNetObjectIDType	ENAME;
	///�¼�����
	TShfeFtdcCfgNameType	WarningLEVEL;
	///�¼�����
	TShfeFtdcVolumeType	EventTypeID;
	///�¼�������
	TShfeFtdcVolumeType	SubEventTypeID;
	///�澯���ʱ��
	TShfeFtdcVolumeType	GIVEUPTIME;
	///���ƶ�����
	TShfeFtdcGeneralResultType	CONTROL;
	///���ʽ������
	TShfeFtdcGeneralResultType	EXPR;
	///�¼�����
	TShfeFtdcTypeObjectIDType	BRIEF;
	///�¼�������
	TShfeFtdcNetAttrTypeType	DISCRIPTION;
	///��Ϣ��ID
	TShfeFtdcVolumeType	MSGGROUP_ID;
	///����Ա��ID
	TShfeFtdcVolumeType	ADMINGROUP_ID;
};

///�¼�����
struct CShfeFtdcReqQryNetEventTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�¼�����������
	TShfeFtdcTypeObjectIDType	CName;
	///�¼�����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�¼�����
struct CShfeFtdcRspQryNetEventTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�¼�����������
	TShfeFtdcTypeObjectIDType	CName;
	///�¼�����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�¼�����
struct CShfeFtdcRtnNetEventTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�¼�����������
	TShfeFtdcTypeObjectIDType	CName;
	///�¼�����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�¼�������
struct CShfeFtdcReqQryNetSubEventTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�¼�������������
	TShfeFtdcTypeObjectIDType	CName;
	///�¼�������Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�¼�������
struct CShfeFtdcRspQryNetSubEventTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�¼�������������
	TShfeFtdcTypeObjectIDType	CName;
	///�¼�������Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�¼�������
struct CShfeFtdcRtnNetSubEventTypeField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�¼�������������
	TShfeFtdcTypeObjectIDType	CName;
	///�¼�������Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///�¼�����
struct CShfeFtdcReqQryNetEventLevelField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�¼�����������
	TShfeFtdcTypeObjectIDType	CName;
	///�¼�����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///�¼�����������
	TShfeFtdcNetAttrTypeType	DISCRIPTION;
};

///�¼�����
struct CShfeFtdcRspQryNetEventLevelField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�¼�����������
	TShfeFtdcTypeObjectIDType	CName;
	///�¼�����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///�¼�����������
	TShfeFtdcNetAttrTypeType	DISCRIPTION;
};

///�¼�����
struct CShfeFtdcRtnNetEventLevelField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�¼�����������
	TShfeFtdcTypeObjectIDType	CName;
	///�¼�����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///�¼�����������
	TShfeFtdcNetAttrTypeType	DISCRIPTION;
};

///������״̬��
struct CShfeFtdcReqQryNetMonitorTaskStatusResultField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///����ID
	TShfeFtdcVolumeType	Task_ID;
	///ִ�д���
	TShfeFtdcVolumeType	OperateTime;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///����ִ�б�ʶ
	TShfeFtdcVolumeType	Flag;
};

///������״̬��
struct CShfeFtdcRspQryNetMonitorTaskStatusResultField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///����ID
	TShfeFtdcVolumeType	Task_ID;
	///ִ�д���
	TShfeFtdcVolumeType	OperateTime;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///����ִ�б�ʶ
	TShfeFtdcVolumeType	Flag;
};

///������״̬��
struct CShfeFtdcRtnNetMonitorTaskStatusResultField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///����ID
	TShfeFtdcVolumeType	Task_ID;
	///ִ�д���
	TShfeFtdcVolumeType	OperateTime;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///����ִ�б�ʶ
	TShfeFtdcVolumeType	Flag;
};

///��½���÷��������
struct CShfeFtdcReqConfigLoginField
{
	///DataCenter
	TShfeFtdcDataCenterFlagType	DataCenter;
	///ID
	TShfeFtdcVolumeType	ID;
	///HasConfig
	TShfeFtdcVolumeType	HasConfig;
	///Authorization
	TShfeFtdcAuthorizationInfoType	Authorization;
};

///�Ե�½���÷����������Ӧ
struct CShfeFtdcRspQryConfigLoginField
{
	///�������
	TShfeFtdcErrorIDType	ErrorID;
	///������Ϣ
	TShfeFtdcErrorMsgType	ErrorMsg;
};

///�Ե�ǰ��¼���õķ����ɫ����Ӧ
struct CShfeFtdcRspServerTypeField
{
	///IsMaster
	TShfeFtdcVolumeType	IsMaster;
};

///�˳���������
struct CShfeFtdcReqSysServerExitField
{
	///Time
	TShfeFtdcDateTimeType	Time;
	///Authorization
	TShfeFtdcAuthorizationInfoType	Authorization;
};

///�豸���ñ�
struct CShfeFtdcReqQryNetCfgFileField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///��ض���
	TShfeFtdcNetObjectIDType	ObjectID;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�����ļ���
	TShfeFtdcNetAttrTypeType	CfgFileName;
};

///�豸���ñ�
struct CShfeFtdcRspQryNetCfgFileField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///��ض���
	TShfeFtdcNetObjectIDType	ObjectID;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�����ļ���
	TShfeFtdcNetAttrTypeType	CfgFileName;
};

///�豸���ñ�
struct CShfeFtdcRtnNetCfgFileField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///��ض���
	TShfeFtdcNetObjectIDType	ObjectID;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///�����ļ���
	TShfeFtdcNetAttrTypeType	CfgFileName;
};

///���������������
struct CShfeFtdcReqQryNetMonitorDeviceTaskField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///�����豸����ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///ָ��
	TShfeFtdcNetAttrTypeType	InstructChain;
	///ָ�����
	TShfeFtdcNetAttrTypeType	InstructAlias;
	///ָ�������
	TShfeFtdcNetAttrTypeType	InstructArgs;
	///ָ��Ĭ�ϲ�����
	TShfeFtdcGeneralResultType	DefParamChain;
};

///���������������
struct CShfeFtdcRspQryNetMonitorDeviceTaskField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///�����豸����ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///ָ��
	TShfeFtdcNetAttrTypeType	InstructChain;
	///ָ�����
	TShfeFtdcNetAttrTypeType	InstructAlias;
	///ָ�������
	TShfeFtdcNetAttrTypeType	InstructArgs;
	///ָ��Ĭ�ϲ�����
	TShfeFtdcGeneralResultType	DefParamChain;
};

///���������������
struct CShfeFtdcRtnNetMonitorDeviceTaskField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///�����豸����ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///ָ��
	TShfeFtdcNetAttrTypeType	InstructChain;
	///ָ�����
	TShfeFtdcNetAttrTypeType	InstructAlias;
	///ָ�������
	TShfeFtdcNetAttrTypeType	InstructArgs;
	///ָ��Ĭ�ϲ�����
	TShfeFtdcGeneralResultType	DefParamChain;
};

///����ָ��ָ�꼯��
struct CShfeFtdcReqQryNetMonitorTaskInstAttrsField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�����豸����ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///ָ�����
	TShfeFtdcNetAttrTypeType	InstructAlias;
	///�豸�ͺ�
	TShfeFtdcNetObjectIDType	DEVICETYPE;
	///ָ�괮
	TShfeFtdcGeneralResultType	AttrsChain;
	///ָ��Ĭ�Ϲ���
	TShfeFtdcGeneralResultType	DefRegularChain;
	///ָ��Ĭ�ϲ�����
	TShfeFtdcGeneralResultType	DefParamChain;
};

///����ָ��ָ�꼯��
struct CShfeFtdcRspQryNetMonitorTaskInstAttrsField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�����豸����ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///ָ�����
	TShfeFtdcNetAttrTypeType	InstructAlias;
	///�豸�ͺ�
	TShfeFtdcNetObjectIDType	DEVICETYPE;
	///ָ�괮
	TShfeFtdcGeneralResultType	AttrsChain;
	///ָ��Ĭ�Ϲ���
	TShfeFtdcGeneralResultType	DefRegularChain;
	///ָ��Ĭ�ϲ�����
	TShfeFtdcGeneralResultType	DefParamChain;
};

///����ָ��ָ�꼯��
struct CShfeFtdcRtnNetMonitorTaskInstAttrsField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///�����豸����ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///ָ�����
	TShfeFtdcNetAttrTypeType	InstructAlias;
	///�豸�ͺ�
	TShfeFtdcNetObjectIDType	DEVICETYPE;
	///ָ�괮
	TShfeFtdcGeneralResultType	AttrsChain;
	///ָ��Ĭ�Ϲ���
	TShfeFtdcGeneralResultType	DefRegularChain;
	///ָ��Ĭ�ϲ�����
	TShfeFtdcGeneralResultType	DefParamChain;
};

///�ļ�ͨ�ò���
struct CShfeFtdcReqQryFileGeneralOperField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///�ļ���
	TShfeFtdcNetAttrTypeType	FileName;
	///�ļ��汾
	TShfeFtdcFileVersionType	Version;
	///С�汾��
	TShfeFtdcVolumeType	SubVersion;
	///����
	TShfeFtdcDateType	MonDate;
	///ʱ��
	TShfeFtdcTimeType	MonTime;
	///�ļ������û�
	TShfeFtdcTypeUserNameType	UserName;
	///��������
	TShfeFtdcVolumeType	OperType;
	///�������
	TShfeFtdcVolumeType	OperResult;
	///ע��
	TShfeFtdcNetAttrTypeType	Comments;
	///�ļ�ƫ��
	TShfeFtdcOffsetType	Offset;
	///Content��ʵ�����ݳ���
	TShfeFtdcCommLengthType	Length;
	///�ļ�����
	TShfeFtdcFileCommentType	FileContent;
};

///�ļ�ͨ�ò���
struct CShfeFtdcRspQryFileGeneralOperField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///�ļ���
	TShfeFtdcNetAttrTypeType	FileName;
	///�ļ��汾
	TShfeFtdcFileVersionType	Version;
	///С�汾��
	TShfeFtdcVolumeType	SubVersion;
	///����
	TShfeFtdcDateType	MonDate;
	///ʱ��
	TShfeFtdcTimeType	MonTime;
	///�ļ������û�
	TShfeFtdcTypeUserNameType	UserName;
	///��������
	TShfeFtdcVolumeType	OperType;
	///�������
	TShfeFtdcVolumeType	OperResult;
	///ע��
	TShfeFtdcNetAttrTypeType	Comments;
	///�ļ�ƫ��
	TShfeFtdcOffsetType	Offset;
	///Content��ʵ�����ݳ���
	TShfeFtdcCommLengthType	Length;
	///�ļ�����
	TShfeFtdcFileCommentType	FileContent;
};

///�ļ�ͨ�ò���
struct CShfeFtdcRtnFileGeneralOperField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///�ļ���
	TShfeFtdcNetAttrTypeType	FileName;
	///�ļ��汾
	TShfeFtdcFileVersionType	Version;
	///С�汾��
	TShfeFtdcVolumeType	SubVersion;
	///����
	TShfeFtdcDateType	MonDate;
	///ʱ��
	TShfeFtdcTimeType	MonTime;
	///�ļ������û�
	TShfeFtdcTypeUserNameType	UserName;
	///��������
	TShfeFtdcVolumeType	OperType;
	///�������
	TShfeFtdcVolumeType	OperResult;
	///ע��
	TShfeFtdcNetAttrTypeType	Comments;
	///�ļ�ƫ��
	TShfeFtdcOffsetType	Offset;
	///Content��ʵ�����ݳ���
	TShfeFtdcCommLengthType	Length;
	///�ļ�����
	TShfeFtdcFileCommentType	FileContent;
};

///���߱�
struct CShfeFtdcReqQryNetBaseLineField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///�ļ���
	TShfeFtdcNetObjectIDType	Name;
	///�豸�ͺ�
	TShfeFtdcNetObjectIDType	SerialUsed;
	///�ļ�����
	TShfeFtdcbaseCommentType	data;
	///��ע
	TShfeFtdcNetAttrTypeType	memo;
	///������־
	TShfeFtdcVolumeType	Flag;
};

///���߱�
struct CShfeFtdcRspQryNetBaseLineField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///�ļ���
	TShfeFtdcNetObjectIDType	Name;
	///�豸�ͺ�
	TShfeFtdcNetObjectIDType	SerialUsed;
	///�ļ�����
	TShfeFtdcbaseCommentType	data;
	///��ע
	TShfeFtdcNetAttrTypeType	memo;
	///������־
	TShfeFtdcVolumeType	Flag;
};

///���߱�
struct CShfeFtdcRtnNetBaseLineField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///�ļ���
	TShfeFtdcNetObjectIDType	Name;
	///�豸�ͺ�
	TShfeFtdcNetObjectIDType	SerialUsed;
	///�ļ�����
	TShfeFtdcbaseCommentType	data;
	///��ע
	TShfeFtdcNetAttrTypeType	memo;
	///������־
	TShfeFtdcVolumeType	Flag;
};

///���������
struct CShfeFtdcReqQryNetBaseLineTaskField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///����ID�б�
	TShfeFtdcGeneralResultType	BaseLineIDList;
	///�豸ID�б�
	TShfeFtdcGeneralResultType	DeviceIDList;
	///��������
	TShfeFtdcDateType	GenDate;
	///����ʱ��
	TShfeFtdcTimeType	GenTime;
	///������
	TShfeFtdcTypeUserNameType	GenUser;
};

///���������
struct CShfeFtdcRspQryNetBaseLineTaskField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///����ID�б�
	TShfeFtdcGeneralResultType	BaseLineIDList;
	///�豸ID�б�
	TShfeFtdcGeneralResultType	DeviceIDList;
	///��������
	TShfeFtdcDateType	GenDate;
	///����ʱ��
	TShfeFtdcTimeType	GenTime;
	///������
	TShfeFtdcTypeUserNameType	GenUser;
};

///���������
struct CShfeFtdcRtnNetBaseLineTaskField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///����ID�б�
	TShfeFtdcGeneralResultType	BaseLineIDList;
	///�豸ID�б�
	TShfeFtdcGeneralResultType	DeviceIDList;
	///��������
	TShfeFtdcDateType	GenDate;
	///����ʱ��
	TShfeFtdcTimeType	GenTime;
	///������
	TShfeFtdcTypeUserNameType	GenUser;
};

///���߽����
struct CShfeFtdcReqQryNetBaseLineResultField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcNetObjectIDType	BaseLineName;
	///�豸ObjID
	TShfeFtdcNetObjectIDType	DeviceObjID;
	///�豸IP
	TShfeFtdcIPAddressType	DeviceIP;
	///���߽��
	TShfeFtdcFileCommentType	Result;
	///��������
	TShfeFtdcDateType	GenDate;
	///����ʱ��
	TShfeFtdcTimeType	GenTime;
	///������
	TShfeFtdcTypeUserNameType	GenUser;
};

///���߽����
struct CShfeFtdcRspQryNetBaseLineResultField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcNetObjectIDType	BaseLineName;
	///�豸ObjID
	TShfeFtdcNetObjectIDType	DeviceObjID;
	///�豸IP
	TShfeFtdcIPAddressType	DeviceIP;
	///���߽��
	TShfeFtdcFileCommentType	Result;
	///��������
	TShfeFtdcDateType	GenDate;
	///����ʱ��
	TShfeFtdcTimeType	GenTime;
	///������
	TShfeFtdcTypeUserNameType	GenUser;
};

///���߽����
struct CShfeFtdcRtnNetBaseLineResultField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcNetObjectIDType	BaseLineName;
	///�豸ObjID
	TShfeFtdcNetObjectIDType	DeviceObjID;
	///�豸IP
	TShfeFtdcIPAddressType	DeviceIP;
	///���߽��
	TShfeFtdcFileCommentType	Result;
	///��������
	TShfeFtdcDateType	GenDate;
	///����ʱ��
	TShfeFtdcTimeType	GenTime;
	///������
	TShfeFtdcTypeUserNameType	GenUser;
};

///��Ա��·״̬��Ϣ��
struct CShfeFtdcReqQryNetPartyLinkStatusInfoField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///���ҷ�ʽ
	TShfeFtdcCompareTypeType	KeyCompare;
	///��������
	TShfeFtdcNetAttrTypeType	KeyName;
	///����ֵ
	TShfeFtdcNetAttrTypeType	KeyValue;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///ϯλ��
	TShfeFtdcCfgNameType	SEAT_NO;
	///·��������IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///·�����˿ں�
	TShfeFtdcTypeObjectIDType	Interface;
	///��·״̬
	TShfeFtdcTypeObjectIDType	status;
};

///��Ա��·״̬��Ϣ��
struct CShfeFtdcRspQryNetPartyLinkStatusInfoField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///ϯλ��
	TShfeFtdcCfgNameType	SEAT_NO;
	///·��������IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///·�����˿ں�
	TShfeFtdcTypeObjectIDType	Interface;
	///��·״̬
	TShfeFtdcTypeObjectIDType	status;
};

///��Ա��·״̬��Ϣ��
struct CShfeFtdcRtnNetPartyLinkStatusInfoField
{
	///��������
	TShfeFtdcVolumeType	OperationType;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///ϯλ��
	TShfeFtdcCfgNameType	SEAT_NO;
	///·��������IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///·�����˿ں�
	TShfeFtdcTypeObjectIDType	Interface;
	///��·״̬
	TShfeFtdcTypeObjectIDType	status;
};

///
struct CShfeFtdcSysNetAreaField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///
struct CShfeFtdcSysNetSubAreaField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetArea
	TShfeFtdcVolumeType	SysNetAreaID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///
struct CShfeFtdcSysNetSubAreaIPField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///ip��ַ
	TShfeFtdcIPAddressType	IP;
	///����
	TShfeFtdcIPAddressType	Mask;
};

///
struct CShfeFtdcSysNetDeviceTypeField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcTypeObjectIDType	Manufactory;
	///�豸�ͺ�
	TShfeFtdcTypeObjectIDType	DeviceType;
};

///
struct CShfeFtdcSysNetOIDField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcTypeObjectIDType	Manufactory;
	///�豸�ͺ�
	TShfeFtdcTypeObjectIDType	DeviceType;
	///OID������
	TShfeFtdcTypeObjectIDType	CName;
	///OIDӢ����
	TShfeFtdcTypeObjectIDType	EName;
	///OID
	TShfeFtdcTypeObjectIDType	OID;
	///��λ
	TShfeFtdcTypeObjectIDType	Unit;
	///�Ƿ������־
	TShfeFtdcVolumeType	isTheTable;
};

///
struct CShfeFtdcSysNetTimePolicyField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///ʱ�����������
	TShfeFtdcTypeObjectIDType	CName;
	///ʱ�����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///��������
	TShfeFtdcVolumeType	PolicyType;
	///���������ô�
	TShfeFtdcPolicyStringTypeType	PolicyString;
	///����������
	TShfeFtdcVolumeType	TradingDay;
	///����������
	TShfeFtdcNetAttrTypeType	Description;
	///��������
	TShfeFtdcVolumeType	Operation;
};

///
struct CShfeFtdcSysNetGatherTaskField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///������ָ������
	TShfeFtdcNetAttrTypeType	AttrType;
	///ʱ�����ID
	TShfeFtdcVolumeType	PolicyTypeID;
	///��������
	TShfeFtdcVolumeType	DataType;
	///���ͱ�ʶ
	TShfeFtdcVolumeType	TypeFlag;
};

///
struct CShfeFtdcSysNetDeviceCategoryField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///���������
	TShfeFtdcTypeObjectIDType	CName;
	///���Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///
struct CShfeFtdcSysNetManufactoryField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///
struct CShfeFtdcSysNetCommunityField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPADDR;
	///��ͬ����
	TShfeFtdcTypeObjectIDType	COMMUNITY;
};

///
struct CShfeFtdcSysNetGeneralOIDField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///OID������
	TShfeFtdcTypeObjectIDType	CName;
	///OIDӢ����
	TShfeFtdcTypeObjectIDType	EName;
	///OID
	TShfeFtdcTypeObjectIDType	OID;
	///��λ
	TShfeFtdcTypeObjectIDType	Unit;
	///�Ƿ������־
	TShfeFtdcVolumeType	isTheTable;
};

///
struct CShfeFtdcSysNetDeviceLinkedField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///�豸ID
	TShfeFtdcVolumeType	NetDeviceID;
	///�豸�˿�ID
	TShfeFtdcVolumeType	NetPortID;
	///��ض���
	TShfeFtdcNetObjectIDType	NetObjectID;
	///��ض���˿�����
	TShfeFtdcNetDevicePortTypeType	NetPortType;
	///�����豸ID
	TShfeFtdcVolumeType	LinkNetDeviceID;
	///�����豸�˿�ID
	TShfeFtdcVolumeType	LinkNetPortID;
	///���Ӷ���
	TShfeFtdcNetObjectIDType	LinkNetObjectID;
	///���Ӷ���˿�����
	TShfeFtdcNetDevicePortTypeType	LinkNetPortType;
	///������Դ
	TShfeFtdcVolumeType	LinkSource;
};

///
struct CShfeFtdcSysNetDeviceField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///��ض���
	TShfeFtdcNetObjectIDType	ObjectID;
	///��ض�������
	TShfeFtdcVolumeType	MonitorType_ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///����ID  
	TShfeFtdcVolumeType	CATEGORY_ID;
	///��Ϊ���ֵ�ְ������  
	TShfeFtdcTypeObjectIDType	FuctionArea;
	///IP��ַ  
	TShfeFtdcIPAddressType	IPADDR;
	///IP��    
	TShfeFtdcVolumeType	IPDECODE;
	///�豸���� 
	TShfeFtdcNetObjectIDType	NAME;
	///             
	TShfeFtdcVolumeType	PORTNUMBER;
	///          
	TShfeFtdcTypeObjectIDType	CONFIGFILE;
	///��ͬ����  
	TShfeFtdcTypeObjectIDType	RCOMMUNITY;
	///snmp�汾     
	TShfeFtdcVolumeType	SNMPVERSION;
	///ramsize(B)   
	TShfeFtdcVolumeType	RAMSIZE;
	///falshsize(B) 
	TShfeFtdcVolumeType	FLASHSIZE;
	///nvramsize(B) 
	TShfeFtdcVolumeType	NVRAMSIZE;
	///��������
	TShfeFtdcVolumeType	CABINET_ID;
	///
	TShfeFtdcVolumeType	ROOM_ID;
	///����汾
	TShfeFtdcVolumeType	IOSVERSION_ID;
	///ϵͳ����
	TShfeFtdcNetAttrTypeType	DESCRIPTION;
	///��¼�û���
	TShfeFtdcTypeObjectIDType	USERNAME;
	///��¼����
	TShfeFtdcNetAttrTypeType	PASSWD;
	///enable����
	TShfeFtdcNetAttrTypeType	ENPASSWD;
	///��������
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///���ñ���Э��
	TShfeFtdcVolumeType	CFGSAVETYPE;
	///�豸�ͺ�
	TShfeFtdcNetObjectIDType	DEVICETYPE;
	///�Ƿ���Ÿ澯
	TShfeFtdcVolumeType	SENDSMS;
	///�Ƿ��Զ�snmp̽��
	TShfeFtdcVolumeType	ISSNMP;
	///��λ��
	TShfeFtdcVolumeType	SLOTNUM;
	///�Ƿ��Զ�ping
	TShfeFtdcVolumeType	ISPING;
	///�˿�����
	TShfeFtdcVolumeType	IFNUM;
	///Ѳ�����
	TShfeFtdcVolumeType	APPLICATION_ID;
};

///
struct CShfeFtdcSysNetInterfaceField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///��ض���
	TShfeFtdcNetObjectIDType	ObjectID;
	///��ض�������
	TShfeFtdcVolumeType	MonitorType_ID;
	///�˿�����
	TShfeFtdcVolumeType	IfType;
	///�˿���
	TShfeFtdcTypeObjectIDType	EName;
	///IP��ַ
	TShfeFtdcIPAddressType	IpAddress;
	///����
	TShfeFtdcIPAddressType	IpMask;
	///�˿�״̬
	TShfeFtdcVolumeType	IfStatus;
	///�����ַ
	TShfeFtdcTypeObjectIDType	MAC;
	///�����豸ID
	TShfeFtdcVolumeType	DeviceID;
	///�����豸ObjectID
	TShfeFtdcNetObjectIDType	DeviceObjectID;
	///�����豸�˿�����
	TShfeFtdcTypeObjectNameType	DeviceIndex;
	///�Ƿ���ѯ
	TShfeFtdcVolumeType	isPolling;
	///����
	TShfeFtdcTypeObjectIDType	Description;
};

///
struct CShfeFtdcSysNetMonitorTypeField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///OID������
	TShfeFtdcTypeObjectIDType	CName;
	///OIDӢ����
	TShfeFtdcTypeObjectIDType	EName;
};

///
struct CShfeFtdcSysNetMonitorAttrScopeField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///ָ��������
	TShfeFtdcNetAttrTypeType	CName;
	///ָ��Ӣ����
	TShfeFtdcNetAttrTypeType	EName;
	///ע��
	TShfeFtdcNetAttrTypeType	Comments;
};

///
struct CShfeFtdcSysNetMonitorAttrTypeField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///�豸���
	TShfeFtdcVolumeType	MonitorType_ID;
	///������ָ��ID
	TShfeFtdcVolumeType	AttrType_ID;
	///��������
	TShfeFtdcTypeObjectIDType	MANUFACTORY;
	///�豸���
	TShfeFtdcTypeObjectIDType	MonitorType;
	///������ָ��
	TShfeFtdcNetAttrTypeType	AttrType;
};

///
struct CShfeFtdcSysNetMonitorObjectAttrField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///��ض���
	TShfeFtdcNetObjectIDType	ObjectID;
	///������ָ��
	TShfeFtdcNetAttrTypeType	AttrType;
	///ʱ�����ID
	TShfeFtdcVolumeType	PolicyTypeID;
};

///
struct CShfeFtdcSysNetFuncAreaField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///
struct CShfeFtdcSysNetMonitorCommandTypeField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///��������ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///�豸���ID
	TShfeFtdcVolumeType	MonitorType_ID;
	///�豸�ͺ�ID
	TShfeFtdcVolumeType	DeviceModle_ID;
	///������ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///��������
	TShfeFtdcTypeObjectIDType	Manufactory;
	///�豸���
	TShfeFtdcTypeObjectIDType	MonitorType;
	///�豸�ͺ�
	TShfeFtdcTypeObjectIDType	DeviceModle;
	///������
	TShfeFtdcTypeObjectIDType	ActionGroup;
	///ָ����
	TShfeFtdcNetAttrTypeType	Command;
};

///
struct CShfeFtdcSysNetMonitorActionGroupField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///������������
	TShfeFtdcTypeObjectIDType	CName;
	///������Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///����������
	TShfeFtdcVolumeType	ActionType;
	///ע��
	TShfeFtdcNetAttrTypeType	Comments;
};

///
struct CShfeFtdcSysNetMonitorDeviceGroupField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///�豸������������
	TShfeFtdcTypeObjectIDType	CName;
	///�豸������Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///�豸��������
	TShfeFtdcNetAttrTypeType	Condition;
	///ע��
	TShfeFtdcNetAttrTypeType	Comments;
};

///
struct CShfeFtdcSysNetMonitorTaskInfoField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///����������
	TShfeFtdcTypeObjectIDType	CName;
	///����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///�豸������ID
	TShfeFtdcVolumeType	DeviceGroup_ID;
	///������Ա������ID
	TShfeFtdcVolumeType	ManagerGroup_ID;
	///����ʱ�����ID
	TShfeFtdcVolumeType	TimePolicy_ID;
	///�������ȼ�ID
	TShfeFtdcVolumeType	TaskPriority_ID;
	///����������ID
	TShfeFtdcVolumeType	OutputPolicy_ID;
	///��������ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///������ʽID���ϴ�
	TShfeFtdcGeneralResultType	EventExprStr;
	///�豸������
	TShfeFtdcTypeObjectIDType	DeviceGroup;
	///������Ա������
	TShfeFtdcTypeObjectIDType	ManagerGroup;
	///����ʱ�����
	TShfeFtdcTypeObjectIDType	TimePolicy;
	///�������ȼ�
	TShfeFtdcTypeObjectIDType	TaskPriority;
	///����������
	TShfeFtdcTypeObjectIDType	OutputPolicy;
	///��������
	TShfeFtdcTypeObjectIDType	ActionGroup;
	///������Ч�Ա�ʶ
	TShfeFtdcVolumeType	ValidFlag;
	///����״̬��ʶ
	TShfeFtdcVolumeType	TaskStatus;
	///��������
	TShfeFtdcNetAttrTypeType	Comments;
};

///
struct CShfeFtdcSysNetDeviceChgField
{
	///�豸ID
	TShfeFtdcVolumeType	DeviceID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	OldObjectID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	NewObjectID;
};

///
struct CShfeFtdcSysNetMonitorTaskResultField
{
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///����ID
	TShfeFtdcVolumeType	Task_ID;
	///ִ�д���
	TShfeFtdcVolumeType	OperateTime;
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///ָ�
	TShfeFtdcNetAttrTypeType	InstructChain;
	///�����
	TShfeFtdcGeneralResultType	ResultChain;
	///����ִ�б�ʶ
	TShfeFtdcVolumeType	Flag;
};

///
struct CShfeFtdcSysNetMonitorTaskObjectSetField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///�豸������ID
	TShfeFtdcVolumeType	DeviceGroup_ID;
	///�豸ID
	TShfeFtdcVolumeType	Device_ID;
	///DataCenter
	TShfeFtdcDataCenterFlagType	DataCenter;
};

///
struct CShfeFtdcSysNetPartyLinkInfoField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///��Ա��
	TShfeFtdcCfgNameType	MEMBER_NO;
	///��Ա����
	TShfeFtdcTypeObjectIDType	MEMBER_NAME;
	///��Ա����ص�
	TShfeFtdcTypeObjectIDType	REMOTE_ADDR;
	///�����������
	TShfeFtdcTypeObjectIDType	LOCAL_ADDR;
	///��ַ
	TShfeFtdcNetAttrTypeType	ADDRESS;
	///��·״̬
	TShfeFtdcCfgNameType	LINE_STATUS;
	///��ϵ��
	TShfeFtdcCfgNameType	CONTACT;
	///��ϵ�绰
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///�ֻ���
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	TShfeFtdcTypeObjectIDType	EMAIL;
	///����
	TShfeFtdcTypeObjectIDType	FAX;
	///����ʡ��
	TShfeFtdcCfgNameType	PROVINCE;
	///��·���
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///���뷽ʽ
	TShfeFtdcTypeObjectIDType	IN_MODE;
	///����IP����
	TShfeFtdcTypeObjectIDType	IP_WAN;
	///����IP����
	TShfeFtdcTypeObjectIDType	IP_LAN;
	///·��������IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///·�����˿ں�
	TShfeFtdcTypeObjectIDType	Interface;
	///�ӿڿ�ͨ����
	TShfeFtdcCfgNameType	INTERFACE_DATE;
	///�������
	TShfeFtdcCfgNameType	SOFTWARE;
	///��������
	TShfeFtdcCfgNameType	FEE_TYPE;
	///��Ӫ��
	TShfeFtdcCfgNameType	SERVICEPROVIDER;
	///�Ƿ���Ӫ
	TShfeFtdcCfgNameType	IF_ZIYING;
	///�Ƿ��й�
	TShfeFtdcCfgNameType	IF_TUOGUAN;
	///����������·
	TShfeFtdcCfgNameType	HASOTHER;
	///ϯλ��
	TShfeFtdcCfgNameType	SEAT_NO;
	///��ע
	TShfeFtdcNetAttrTypeType	PRO;
};

///
struct CShfeFtdcSysNetMonitorActionAttrField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///������ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///��ض���ID
	TShfeFtdcVolumeType	MonitorAttr_ID;
	///ָ��Ӣ����
	TShfeFtdcNetAttrTypeType	MonitorAttrName;
};

///
struct CShfeFtdcSysNetModuleField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///��ض�������
	TShfeFtdcVolumeType	MonitorType_ID;
	///�����豸ID
	TShfeFtdcVolumeType	DeviceID;
	///�����豸ObjectID
	TShfeFtdcNetObjectIDType	DeviceObjectID;
	///����
	TShfeFtdcTypeObjectIDType	Name;
	///����
	TShfeFtdcNetObjectIDType	Description;
	///ģ������
	TShfeFtdcVolumeType	ModuleIndex;
	///��������
	TShfeFtdcVolumeType	EntPhyIndex;
};

///
struct CShfeFtdcSysNetEventExprField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///�����¼���
	TShfeFtdcNetObjectIDType	CNAME;
	///Ӣ���¼���
	TShfeFtdcNetObjectIDType	ENAME;
	///�¼�����
	TShfeFtdcCfgNameType	WarningLEVEL;
	///�¼�����
	TShfeFtdcVolumeType	EventTypeID;
	///�¼�������
	TShfeFtdcVolumeType	SubEventTypeID;
	///�澯���ʱ��
	TShfeFtdcVolumeType	GIVEUPTIME;
	///���ƶ�����
	TShfeFtdcGeneralResultType	CONTROL;
	///���ʽ������
	TShfeFtdcGeneralResultType	EXPR;
	///�¼�����
	TShfeFtdcTypeObjectIDType	BRIEF;
	///�¼�������
	TShfeFtdcNetAttrTypeType	DISCRIPTION;
	///��Ϣ��ID
	TShfeFtdcVolumeType	MSGGROUP_ID;
	///����Ա��ID
	TShfeFtdcVolumeType	ADMINGROUP_ID;
};

///
struct CShfeFtdcSysNetEventTypeField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///�¼�����������
	TShfeFtdcTypeObjectIDType	CName;
	///�¼�����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///
struct CShfeFtdcSysNetSubEventTypeField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///�¼�������������
	TShfeFtdcTypeObjectIDType	CName;
	///�¼�������Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
};

///
struct CShfeFtdcSysNetEventLevelField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///�¼�����������
	TShfeFtdcTypeObjectIDType	CName;
	///�¼�����Ӣ����
	TShfeFtdcTypeObjectIDType	EName;
	///�¼�����������
	TShfeFtdcNetAttrTypeType	DISCRIPTION;
};

///
struct CShfeFtdcSysNetMonitorDeviceTaskField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///�����ض���ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///IP��ַ
	TShfeFtdcIPAddressType	IPAddress;
	///�����豸����ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///ָ��
	TShfeFtdcNetAttrTypeType	InstructChain;
	///ָ�����
	TShfeFtdcNetAttrTypeType	InstructAlias;
	///ָ�������
	TShfeFtdcNetAttrTypeType	InstructArgs;
	///ָ��Ĭ�ϲ�����
	TShfeFtdcGeneralResultType	DefParamChain;
};

///
struct CShfeFtdcSysNetMonitorTaskInstAttrsField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///�����豸����ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///ָ�����
	TShfeFtdcNetAttrTypeType	InstructAlias;
	///�豸�ͺ�
	TShfeFtdcNetObjectIDType	DEVICETYPE;
	///ָ�괮
	TShfeFtdcGeneralResultType	AttrsChain;
	///ָ��Ĭ�Ϲ���
	TShfeFtdcGeneralResultType	DefRegularChain;
	///ָ��Ĭ�ϲ�����
	TShfeFtdcGeneralResultType	DefParamChain;
};

///
struct CShfeFtdcSysNetBaseLineField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///�ļ���
	TShfeFtdcNetObjectIDType	Name;
	///�豸�ͺ�
	TShfeFtdcNetObjectIDType	SerialUsed;
	///�ļ�����
	TShfeFtdcbaseCommentType	data;
	///��ע
	TShfeFtdcNetAttrTypeType	memo;
	///������־
	TShfeFtdcVolumeType	Flag;
};

///
struct CShfeFtdcSysNetBaseLineTaskField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///����ID�б�
	TShfeFtdcGeneralResultType	BaseLineIDList;
	///�豸ID�б�
	TShfeFtdcGeneralResultType	DeviceIDList;
	///��������
	TShfeFtdcDateType	GenDate;
	///����ʱ��
	TShfeFtdcTimeType	GenTime;
	///������
	TShfeFtdcTypeUserNameType	GenUser;
};

///
struct CShfeFtdcSysNetBaseLineResultField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///��������
	TShfeFtdcNetObjectIDType	BaseLineName;
	///�豸ObjID
	TShfeFtdcNetObjectIDType	DeviceObjID;
	///�豸IP
	TShfeFtdcIPAddressType	DeviceIP;
	///���߽��
	TShfeFtdcFileCommentType	Result;
	///��������
	TShfeFtdcDateType	GenDate;
	///����ʱ��
	TShfeFtdcTimeType	GenTime;
	///������
	TShfeFtdcTypeUserNameType	GenUser;
};

///
struct CShfeFtdcSysNetPartyLinkStatusInfoField
{
	///�ɼ�������
	TShfeFtdcDateType	MonDate;
	///�ɼ���ʱ��
	TShfeFtdcTimeType	MonTime;
	///ϯλ��
	TShfeFtdcCfgNameType	SEAT_NO;
	///·��������IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///·�����˿ں�
	TShfeFtdcTypeObjectIDType	Interface;
	///��·״̬
	TShfeFtdcTypeObjectIDType	status;
};



#endif
