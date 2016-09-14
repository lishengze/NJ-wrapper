CC = g++
TARGET = a.out
OBJS = main.o CplusReq.o simplified-sysuserspi.o
#LIB_PATH := -L../CplusReqProg
#LIBS     := $(LIB_PATH) -lsysuserapi

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -L../CplusReqProg -lsysuserapi

main.o:main.cpp CplusReq.h
	$(CC) -c main.cpp

CplusReq.o:CplusReq.cpp CplusReq.h FtdcSysUserApi.h simplified-sysuserspi.h tool-function.h
	$(CC) -c CplusReq.cpp

simplified-sysuserspi.o:simplified-sysuserspi.cpp simplified-sysuserspi.h FtdcSysUserApi.h tool-function.h
	$(CC) -c simplified-sysuserspi.cpp

# charset-convert-linux.o:charset-convert-linux.cpp charset-convert-linux.h
# 	$(CC) -c charset-convert-linux.cpp

.PHONY : clean
clean :
	rm -f *.o
