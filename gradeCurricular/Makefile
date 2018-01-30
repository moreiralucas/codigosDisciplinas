# MAKEFILE

CC = g++

CPP = -std=c++11

CFLAGS =  `pkg-config --cflags --libs opencv`

PROG = executavel.out
# PROG = RESULT

#OBJ = 	clahe.o

all:
	$(CC) $(CPP) main.cpp $(CFLAGS) -o $(PROG) -g
# 	$(CC) geraResult.c $(CFLAGS) $(LDFLAGS) -o $(PROG) -g

clean:
	rm -f *.o *~ core $(PROG)
