CC=g++
LDFLAGS= -std=c++11
#remover CFLAGS
CFLAGS=-I.
DEPS=main.hpp
OBJ = main.o search.o textos.o

%.o: %.cpp $(DEPS)
	$(CC) $(LDFLAGS) -c -o $@ $<
execute.out: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^
clean:
	rm -f *.o *~ core $(PROG)
