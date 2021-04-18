main : main.o directory.o user.o
	gcc main.o directory.o user.o -o main

main.o :main.c
	gcc -c main.c

directory.o : directory.c
	gcc -c directory.c

user.o : user.c
	gcc -c user.c

clean:
	rm *.o
