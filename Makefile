# Makefile for testing mkdir functionality

.PHONY: clean

CC       = gcc
LD		   = gcc

LIBS		= -lrt

CFLAGS	= -c -Wall

C_EXT = c
OBJ_EXT = o
EXE_EXT = exe

EXE = mkdir_test_1.$(EXE_EXT) mkdir_test_2.$(EXE_EXT)
OBJECTS = mkdir_test_1.$(OBJ_EXT)	mkdir_test_2.$(OBJ_EXT)

%.o : %.c
	$(CC) $(CFLAGS) $*.$(C_EXT) -o $*.$(OBJ_EXT)

mkdir_test_1.$(EXE_EXT): mkdir_test_1.$(OBJ_EXT) $(DRIVER)
	$(LD) -o mkdir_test_1.$(EXE_EXT) $^ $(LIBS) 

mkdir_test_2.$(EXE_EXT): mkdir_test_2.$(OBJ_EXT) $(DRIVER)
	$(LD) -o mkdir_test_2.$(EXE_EXT) $^ $(LIBS) 

all: $(EXE)
	

clean:
	rm -f $(OBJECTS) $(EXE)
