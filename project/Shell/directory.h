#ifndef __DIRECTORY_H
#define __DIRECTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>

#define MAX_LEN_NAME 1000
#define MAX_PATH_LEN 10000

typedef struct Directory Direc;
typedef struct Directory *PtrToDirec;

// directory node has the following fields
struct Directory
{
    char Name[MAX_LEN_NAME];
    char Path[MAX_PATH_LEN];
    Direc *PtrToSubDirecs;
    Direc *PtrToSubFiles;
    Direc *Next;
};

PtrToDirec NewDirec(char name[]); //makes a new node
PtrToDirec InitializeDirecTree(char name[], char root_path[]);
/* calls ListDirecs to make the directory tree recurrsively */
void ListDirecs(PtrToDirec root);                            // inserts all nodes into tree recurrsively
void PrintDirecTree(PtrToDirec root, int depth, int choice); //prints the directory tree

//The following two are global to all files the include this header.
char PATH_OF_CURRENT_DIRECTORY[MAX_PATH_LEN];
char PROMPT_PATH[MAX_PATH_LEN];
PtrToDirec CURRENT_DIRECTORY;

void Print_current_directory_path(bool abbreviate_subject);
void InitializePath();

#endif