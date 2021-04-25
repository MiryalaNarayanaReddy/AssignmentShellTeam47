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

void copy_everthing()
{
}

void create(char *input_string)
{
    MakeNewFolder(input_string);
    void copy_everthing();
}

void MakeNewFolder(char *input_string)
{
    char new_assign[MAX_PATH_LEN];
    strcpy(new_assign, PATH_OF_CURRENT_DIRECTORY);
    strcat(new_assign, "/");
    strcat(new_assign, input_string);
    mkdir(new_assign, 0700);
    DIR *curr_dir = opendir(PATH_OF_CURRENT_DIRECTORY);

    if (curr_dir)
    {
        closedir(curr_dir);
        //this is for updating the tree in the code
        PtrToDirec New_dir = NewDirec(input_string);
        New_dir->Next = CURRENT_DIRECTORY->PtrToSubDirecs;
        CURRENT_DIRECTORY->PtrToSubDirecs = New_dir;
        strcpy(CURRENT_DIRECTORY->PtrToSubDirecs->Path, new_assign);
    }
    else
    {
        printf("could not open folder\n");
    }
}