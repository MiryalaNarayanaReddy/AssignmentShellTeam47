#ifndef __DIRECTORY_H
#define __DIRECTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#define MAX_LEN_NAME 21

typedef Directory Direc;
typedef Directory PtrToDirec;

struct Directory
{
    char Name[MAX_LEN_NAME];
    Direc *PtrToSubDirecs;
    Direc *PtrToSubFiles;
    Direc *Next;
};

PtrToDirec InitializeDirec();

// define MAX_PATH_LEN 1000

// char PATH_OF_CURRENT_DIRECTORY[MAX_PATH_LEN];

// void InitializePath();
// void Print_current_directory_path();

#endif