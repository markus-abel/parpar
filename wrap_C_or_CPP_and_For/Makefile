FOR=gfortran
CC=gcc
CPP=g++
EXECUTABLES=main
FOR_FLAG="-malign-double"
CC_FLAGS="-Wpadded -Wpacked -malign-double -mpreferred-stack-boundary=8"
CPP_FLAGS="-Wpadded -Wpacked -malign-double -mpreferred-stack-boundary=8"

main: main.o sub.o subcpp.o
# 	$(FOR) -o main main.o subc.o
	$(FOR) -o main main.o subcpp.o -lstdc++

.PHONY:

main.o:
	$(FOR) -c main.for

subc.o:
	$(CC) -c subc.c

subcpp.o:
	$(CPP) -c subcpp.cpp

clean:
	rm -f *.o *~ $(EXECUTABLES)