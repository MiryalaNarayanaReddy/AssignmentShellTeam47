# link

main :  main.o directory.o user.o switch.o test.o use.o create.o submit.o setup.o update.o compare.o
	gcc  main.o directory.o user.o switch.o test.o use.o create.o submit.o setup.o update.o compare.o -o main

#  Shell

main.o :main.c
	gcc -c main.c

directory.o : directory.c
	gcc -c directory.c

user.o : user.c
	gcc -c user.c

# switch

switch.o : ../switch/switch.c
	gcc -c ../switch/switch.c

# create

create.o : ../create/create.c
	gcc -c ../create/create.c

# test

test.o : ../test/test.c
	gcc -c ../test/test.c

# use

use.o : ../use/use.c
	gcc -c ../use/use.c

# submit

submit.o : ../submit/submit.c
	gcc -c ../submit/submit.c

# setup

setup.o : ../setup/setup.c
	gcc -c ../setup/setup.c

# update

update.o : ../update/update.c
	gcc -c ../update/update.c
	
# compare

compare.o : ../compare/compare.c
	gcc -c ../compare/compare.c	

# make clean

clean:
	rm *.o
	rm main
