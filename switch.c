#include "switch.h"
#include "../Shell/directory.h"
#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

void Switch_Directory(char *input_string)
{
    PATH_OF_CURRENT_DIRECTORY[7] = '/';
    PATH_OF_CURRENT_DIRECTORY[8] = '\0';
    strcat(PATH_OF_CURRENT_DIRECTORY, input_string);
    if (!DoesDirectoryExist())
    {
        NewDirectory();
    }
}

bool DoesDirectoryExist()
{
    DIR *curr_dir = opendir(PATH_OF_CURRENT_DIRECTORY);
    if (curr_dir)
    {
        closedir(curr_dir);
        return true; //directory exists
    }
    else if (ENOENT == errno)
    {
        return false; //directory does not exist
    }
    else 
    {
        printf("Something is wrong");
        return false;
    }
}

void NewDirectory()
{
    mkdir(PATH_OF_CURRENT_DIRECTORY, 0700);
    DIR *curr_dir = opendir(PATH_OF_CURRENT_DIRECTORY);
    if (curr_dir)
    {
        closedir(curr_dir);
    }
    else
    {
        printf("could not open folder\n");
    }
}