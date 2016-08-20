executavel :  sendoBruxo.o main.o
	gcc -o executavel sendoBruxo.o main.o 

main.o : main.c
	gcc -c main.c 

sendoBruxo.o : sendoBruxo.c sendoBruxo.h
	gcc -c sendoBruxo.c 

clean: 
	rm *.o sendoBruxo