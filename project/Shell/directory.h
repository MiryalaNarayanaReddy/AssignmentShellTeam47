#ifndef __DIRECTORY_H
#define __DIRECTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>

#define MAX_LEN_NAME 31
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

PtrToDirec NewDirec(char name[]);//makes a new node
PtrToDirec InitializeDirecTree(char name[], char root_path[]);
/* calls ListDirecs to make the directory tree recurrsively */
void ListDirecs(PtrToDirec root);
void PrintDirecTree(PtrToDirec root, int depth,int choice);//prints the directory tree 

char PATH_OF_CURRENT_DIRECTORY[MAX_PATH_LEN];
void Print_current_directory_path();
void InitializePath();

#endif