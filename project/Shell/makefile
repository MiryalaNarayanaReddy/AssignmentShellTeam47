main : main.o directory.o switch.o test.o user.o use.o
	gcc main.o directory.o switch.o test.o user.o  use.o -o main

main.o :main.c
	gcc -c main.c

directory.o : directory.c
	gcc -c directory.c

user.o : user.c
	gcc -c user.c

switch.o : ../switch/switch.c
	gcc -c ../switch/switch.c

test.o : ../test/test.c
	gcc -c ../test/test.c

use.o : ../use/use.c
	gcc -c ../use/use.c

clean:
	rm *.o
