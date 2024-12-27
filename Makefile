eseg: main.o utils.o
	gcc -o eseg utils.o main.o

utils.o: utils.c utils.h 
	gcc -c utils.c 

main.o: main.c utils.h
	gcc -c main.c 

clean:
	rm -f *.o
	rm -f ./eseg