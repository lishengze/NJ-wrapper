#*****************************************************************************

# Copyright        :  

#

# Author           :   huochangjun

# Date             :   2012-08-16

# Version           :   Demo1 动态链接库

# Description             :   Demo

#

#****************************************************************************/

 

SHELL = /bin/sh

 

LIB_DIR = /cbs/lhbb/hcj/dy2/lib/

BIN_DIR = /cbs/lhbb/hcj/dy2/bin/

OBJECT_DIR = /cbs/lhbb/dy2/test/obj/

APP_DIR = /cbs/lhbb/hcj/dy2/testapp/

 

$(shell mkdir -p ${LIB_DIR})

$(shell mkdir -p ${BIN_DIR})

$(shell mkdir -p ${OBJECT_DIR})

 

RM = rm -fr

#****************************************************************************

 

CC = gcc

SHARED = -shared -o

FPIC = -fPIC -c

 

SRC_OBJECT = $(APP_DIR)test_a.c $(APP_DIR)test_b.c $(APP_DIR)test_c.c

H_OBJECT = $(APP_DIR)so_test.h

OBJECT = test_a.o test_b.o test_c.o

 

DY_SRC_OBJECT = $(APP_DIR)test.c

DY_OBJECT=test.o

 

LIB_OBJECT = libtest.so

BIN_OBJECT = test

 

#****************************************************************************

 

.PHONY:all

all:$(LIB_OBJECT) $(BIN_OBJECT)

 

$(LIB_OBJECT):$(OBJECT)

        $(CC) $(OBJECT) $(SHARED) -fPIC -o $(LIB_OBJECT)

        mv $(LIB_OBJECT) $(LIB_DIR)

 

$(OBJECT):$(SRC_OBJECT) $(H_OBJECT)

        $(CC) $(FPIC) $(SRC_OBJECT)

 

$(BIN_OBJECT):$(DY_OBJECT)

        $(CC) $(OBJECT_DIR)$(DY_OBJECT) -L$(LIB_DIR) -ltest -o $(BIN_OBJECT)

        mv $(BIN_OBJECT) $(BIN_DIR)

 

$(DY_OBJECT):$(DY_SRC_OBJECT)

        $(CC) -c $(DY_SRC_OBJECT)

 

        mv $(OBJECT) $(DY_OBJECT) $(OBJECT_DIR)

 

clean:

        $(RM) $(LIB_DIR) $(BIN_DIR) $(OBJECT_DIR)