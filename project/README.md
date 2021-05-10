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
|      |__README.md
|
|
|__create
|      |__create.h
|      |__create.c
|
|__update
|      |__update.h
|      |__update.c
|
|__setup
|      |__setup.h
|      |__setup.c
|
|__test
|      |__test.h
|      |__test.c
|
|__submit
|      |__submit.h
|      |__submit.c
|
|__compare
|      |__compare.h
|      |__compare.c
|__use
|      |__use.c and use.h
|      |__README.md
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
You enter your commands for the prompt `user>`
commands you can use are as follows

# switch
   - This command will help you to switch between different subject folders.
   - Type switch along with the subject folder name you want to switch.
   
   ```
   user>switch dsa
   user/dsa>
   ```
   If you want to again switch to different subject follow the given command

   ```
   user/dsa>switch dsm
   user/dsm>
   ```
   
   

# create 
  - This command creates a new folder for the assignment, downloads (or copies locally) the contents of the dist folder and the problem statement into the current directory.

  ```
  user>switch dsa
  user/dsa>
  ```

  For creating subfolder use the following command and copies contents of assignment folder outside our project folder.

  ```
  user/dsa>create assign-1
  user/dsa>
  ```
# update
  
  - This command will replace the old files in assign folder with new ones from assignment folder outside our project folder.
  - i.e if TA changes anything in .pdf file or submitter. py that file in our folder will be replaced by new one

  ```
  user/dsa>update assign-1
  user/dsa>
  ```
 - This will call check_for_updates()function and calls it recurrsively for every folder in it.

 - and for files inside each folder it gets its time of last modification.

 - if the time of last modification is more than time of downloding(copying) of our file in assign-1 folder....
   then it removes that file and copies the new one into our assign-1 folder.

`Note:` 

 - if new files are added then it will add them...
 - if a file is edited then it will add them.
 - this will not update any folders if newones are added
 - if file is removed then it will not be removed in our folder.
 - if user modifies his assign-1 folder files then it may not modify them..
 - reference [listing directories](https://www.youtube.com/watch?v=j9yL30R6npk)


# setup
 This command make indented tree directory structure.
  
  ```
  user>setup assign-1
  user>
  ``` 
  
  This will create assign-1 folder and the required indented tree directory structure (of structure in i.txt) <u> inside assign-1 folder </u>.

# test 
 - Runs the submitter.py file in the dist folder, if it exist. The compilation error are stored in txt file.
 - The compilation error are stored in .txt file and sent to the TA for debugging.

 ```
 user/dsa>test assign-1
 user/dsa>
 ```
 - After this command gets executed , the .txt file with compilation error will be created in assign-1 folder.

# submit
 - Zips the required assignment folder and stores it in the current subject folder
 - Command used is
 ```
 cd /dir/ && zip -r assign.zip assign && cd -
 ```
 ```
 user/dsa>submit assign-1
 user/dsa>
 ```
 - After this command gets executed , the zip file of assign-1 will be copied to the present subject directory.

# compare
 

 - Compares the file tree to check if any of the files in the submitted zip are different from any of the files in the given assignment directory.
 - Prints list of different files using MD5 sum command
 - To run compare:
 ```
 user/dsa>compare assign-1 assign-1.zip
 user/dsa>
 ```

 Following commands have been used

 ```
 name@name-system-name:~$ find /path of assignment/ -type f -exec md5sum {} + | sort -k 2 | sed 's/ .*\\// /'> dir1.txt
 name@name-system-name:~$ find /path of assignment zip file/ -type f -exec md5sum {} + | sort -k 2 | sed 's/ .*\\// /'> dir2.txt

 ```
 Then the two text files are compared

 ```
 name@name-system-name:~$ diff -s dir1.txt dir2.txt

 ```
 you will see the different files in both or nothing if they are the same.

# use
 - This command changes the prompt to ``` user/folder/<assignment>```

  ```
  user>switch dsa
  user/dsa>use assign-1
  user/dsa/assign-1>
  ```
# tree
 - This command prints the tree structure of the present directory.

 ```
 user/dsa>tree
 ```
 This will print all the contents of the subject folder dsa.
 
 # back
 - This command changes from this prompt ``` user/folder/<assignment>``` to this ``` user/folder>``` i.e moves back to the subject directory

  ```
  user>switch dsa
  user/dsa>use assign-1
  user/dsa/assign-1>back
  user/dsa>
  ```
 
# clear
 - This will clear the screen and show the prompt.

 ```
 user/dsa>submit
 user/dsa>test
 user/dsa>clear
 ```
- this will clear screen

```
user/dsa>
``` 
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

### Want to have online VScode experience

- [github1s](https://github1s.com/).

- just replace `github.com` with `github1s.com` in browser tab then enter.
- now you will see vs environment.(but its readonly)
- so you see the bottom `Develop your own project on gipod`  click on it.
