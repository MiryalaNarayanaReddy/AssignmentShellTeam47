main : main.o directory.o user.o switch.o
	gcc main.o directory.o user.o switch.o -o main

main.o :main.c
	gcc -c main.c

directory.o : directory.c
	gcc -c directory.c

switch.o : ../switch/switch.c
	gcc -c ../switch/switch.c

user.o : user.c
	gcc -c user.c

clean:
	rm *.o
