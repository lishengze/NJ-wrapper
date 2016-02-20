CC = g++
TARGET = a.out
OBJS = main.o CplusReq.o simplified-sysuserspi.o id-func.o charset-convert-linux.o	

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 
	
main.o:main.cpp CplusReq.h
	$(CC) -c main.cpp
	
CplusReq.o:CplusReq.cpp CplusReq.h FtdcSysUserApi.h simplified-sysuserspi.h tool-function.h id-func.h
	$(CC) -c CplusReq.cpp
	 
simplified-sysuserspi.o:simplified-sysuserspi.cpp simplified-sysuserspi.h FtdcSysUserApi.h tool-function.h CplusReq.h id-func.h charset-convert-linux.h
	$(CC) -c simplified-sysuserspi.cpp
	
id-func.o:id-func.cpp id-func.h	
	$(CC) -c id-func.cpp
	
charset-convert-linux.o:charset-convert-linux.cpp charset-convert-linux.h
	$(CC) -c charset-convert-linux.cpp
	
.PHONY : clean
clean :
	rm -f *.o	
	
