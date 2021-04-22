#ifndef __DIRECTORY_H
#define __DIRECTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#define MAX_LEN_NAME 21
#define MAX_PATH_LEN 1000

typedef struct Directory Direc;
typedef struct Directory *PtrToDirec;

struct Directory
{
    char Name[MAX_LEN_NAME];
    char Path[MAX_PATH_LEN];
    Direc *PtrToSubDirecs;
    Direc *PtrToSubFiles;
    Direc *Next;
};

PtrToDirec NewDirec(char name[]);
PtrToDirec InitializeDirec();

// define MAX_PATH_LEN 1000

// char PATH_OF_CURRENT_DIRECTORY[MAX_PATH_LEN];

// void InitializePath();
// void Print_current_directory_path();

#endif