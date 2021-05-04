#include "create.h"
#include "../switch/switch.h"
#include "../Shell/directory.h"
#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>

void copy_everything(char *destination)
{
    char command[MAX_PATH_LEN];
    strcpy(command, "cp -r ");
    strcat(command, "../../assignment/./");
    strcat(command, " ");
    strcat(command, PATH_OF_CURRENT_DIRECTORY);
    strcat(command, "/./");
    strcat(command, destination);
    system(command);
}

void create(char *input_string)
{
    char new_assign[MAX_PATH_LEN];
    strcpy(new_assign, PATH_OF_CURRENT_DIRECTORY);
    strcat(new_assign, "/");
    strcat(new_assign, input_string);
    PtrToDirec dir = FindDirectory(CURRENT_DIRECTORY, input_string);

    if (dir == NULL)
    {
        MakeNewFolder(new_assign);
    }

    copy_everything(input_string);
    
    //this is for updating the tree in the code
    PtrToDirec New_dir = InitializeDirecTree(input_string,new_assign);
    New_dir->Next = CURRENT_DIRECTORY->PtrToSubDirecs;
    CURRENT_DIRECTORY->PtrToSubDirecs = New_dir;
}

void MakeNewFolder(char *Path_to_new_directory)
{

    mkdir(Path_to_new_directory, 0700);
    DIR *curr_dir = opendir(Path_to_new_directory);

    if (curr_dir)
    {
        closedir(curr_dir);
    }
    else
    {
        printf("could not open folder\n");
    }
}