# ASSIGNMENT SHELL TEAM - 47

This contains the following folder structure

```

|__Shell
|      |__ main.c
|      |__ user.c and user.h
|      |__ directory.c and directory.h
|      |__ makefile
|      |__ README.md
|
|__switch
|      |__switch.c and switch.h
|      |__
|      |__
|
|__create
|      |__
|      |__
|
|__update
|      |__
|      |__
|
|__setup
|      |__
|      |__
|
|__test
|      |__
|      |__
|
|__submit
|      |__
|      |__
|
|__compare
|      |__
|      |__
|__use
|    |__
|    |__
|
|__ README.md
|__ Mini_Project.pdf

```

# Shell
- open terminal shell folder and run the following commands
```
make clean
make 
make clean
./main
```
you will be asked for password. Enter any and you will be asked for it only when exiting from the program.

You don't need to use the same password  every time(its not a login page).

You will see something like below

```
name@name-system-name:./main
The password you are entering is temporary.
Use it to exit from the program
Enter Password : 1234
user>

```
you enter your commands for the prompt `user>`
commands you can use are as follows

# switch

when you enter switch you should also enter name of the folder or subject you want to switch to.

```
user>switch dsa
user/dsa>

```
The prompt will change as above one.
If you use it again you will get the following

```
user>switch dsa
user/dsa>switch dsm
user/dsm>switch Linear Algebra
user/Linear Algebra>

```
**`Note :`** `Linear Algebra` needs to be `la` in short i.e.,the prompt shhould be  `user/la>`.

# create 

# update

# setup

# test 

# submit

# compare

# use

## some references to headers


- [stdio.h](https://en.wikipedia.org/wiki/C_file_input/output) 
```
  |__fopen
  |__fclose
```
- [dirent.h](https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/dirent.h)

```
  |__opendir
  |__closedir
  |__struct dirent*
```
- [sys/stat.h ,sys/types.h ,unistd.h]()

```
  |__mkdir
```
## references on some files
- [.gitignore](https://www.pluralsight.com/guides/how-to-use-gitignore-file)

- [make file]()

## lost your prompt color
- when prompt color lost what should you do ?
use command
```
nano ~/.bashrc
```
then paste everything in `etc/kel/.bashrc` file into terminal(if you can't see the file use `ctr-h` then you will see it along with other '.' files)
save exit
then compile
```
source ~/.bashrc
```
for more understanding look at the following links(both).They will surely give you more idea.
[link1](https://askubuntu.com/questions/404424/how-do-i-restore-bashrc-to-its-default)
[link2](https://linuxhostsupport.com/blog/how-to-change-the-color-of-your-linux-prompt/)

### how to use git inside VScode

- [git](https://www.youtube.com/watch?v=F2DBSH2VoHQ)
