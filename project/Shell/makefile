main : main.o directory.o switch.o test.o user.o use.o create.o
	gcc main.o directory.o switch.o test.o user.o  use.o create.o -o main

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

create.o : ../create/create.c
	gcc -c ../create/create.c
	
submit.o : ../submit/submit.c
	gcc -c ../submit/submit.c	

clean:
	rm *.o
