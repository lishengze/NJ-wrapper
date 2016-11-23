!!enter UFDataTypes!!
/////////////////////////////////////////////////////////////////////////
///@system ��һ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file FtdcDataType.h
///@brief �����˿ͻ��˽ӿ�ʹ�õ�ҵ����������
///@history 
///20070227	zhangjie		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef FTDCSYSDATATYPE_H
#define FTDCSYSDATATYPE_H

enum TE_RESUME_TYPE
{
	TERT_RESTART = 0,
	TERT_RESUME,
	TERT_QUICK
};

!!travel self!!
/////////////////////////////////////////////////////////////////////////
///TFtdc!!@typename!!Type��һ��!!@label!!����
/////////////////////////////////////////////////////////////////////////
!!if !strcmp(@name,"RangeInt")!!
typedef int TShfeFtdc!!@typename!!Type;

!!elseif !strcmp(@name,"RangeChar")!!
typedef char TShfeFtdc!!@typename!!Type;

!!elseif !strcmp(@name,"String")!!
typedef char TShfeFtdc!!@typename!!Type[!!show_value(atoi(@length)+1)!!];

!!elseif !strcmp(@name,"VString")!!
typedef char TShfeFtdc!!@typename!!Type[!!show_value(atoi(@length)+1)!!];

!!elseif !strcmp(@name,"Array")!!
typedef char TShfeFtdc!!@typename!!Type[!!show_value(atoi(@length)+1)!!];

!!elseif !strcmp(@name,"Int")!!
typedef int TShfeFtdc!!@typename!!Type;

!!elseif !strcmp(@name,"Word")!!
typedef short TShfeFtdc!!@typename!!Type;

!!elseif !strcmp(@name,"QWord")!!
typedef QWORD TShfeFtdc!!@typename!!Type;

!!elseif !strcmp(@name,"Char")!!
typedef char TShfeFtdc!!@typename!!Type;

!!elseif !strcmp(@name,"EnumChar")!!
!!travel self!!
///!!@label!!
#define SHFE_FTDC_!!@prefix!!_!!@name!! '!!@value!!'
!!next!!

typedef char TShfeFtdc!!@typename!!Type;

!!elseif !strcmp(@name,"Float")!!
typedef double TShfeFtdc!!@typename!!Type;

!!elseif !strcmp(@name,"FixNumber")!!
typedef double TShfeFtdc!!@typename!!Type;

!!elseif !strcmp(@name,"Pointer")!!
typedef char *TShfeFtdc!!@typename!!Type;

!!else!!
	!!error printf("unknown type %s in %s\n",@name,@typename);!!
!!endif!!
!!next!!
#endif
!!leave!!