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
|      |__ test.c and test.h
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
|    |__use.c and use.h
|    |__README.md
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
You will see something like below

```
name@name-system-name:~$./main
user>
```
you enter your commands for the prompt `user>`
commands you can use are as follows

# switch

# create 

# update

- reference [listing directories](https://www.youtube.com/watch?v=j9yL30R6npk)

# setup

# test 

# submit

# compare

- reference [md5sum](https://www.a2hosting.in/kb/developer-corner/linux/working-with-file-checksums)

`Note`:you don't need any account as mention in above link.

use the following command

```
name@name-system-name:~$ md5sum switch/switch.c  > md5sums.txt

```
comment one line in switch.c and then run the following command

```
name@name-system-name:~$ md5sum switch/switch.c  > md5sums1.txt

```
you will see both are different that shows that the file is corrupt(not the same or modified).

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

- [makefile](https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/).read only makefile1 to get an idea. others are for extra knowledge.

### lost your prompt color
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

### wanna have online VScode experience

- [github1s](https://github1s.com/).

- just replace `github.com` with `github1s.com` in browser tab then enter.
- now you will see vs environment.(but its readonly)
- so you see the bottom `Develop your own project on gipod`  click on it.
