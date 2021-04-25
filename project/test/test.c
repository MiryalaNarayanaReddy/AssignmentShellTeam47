#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>
#include "../Shell/directory.h"
#include "../Shell/user.h"
#include "../switch/switch.h"
#include "../Shell/directory.h"

void Execute(PtrToDirec name, PtrToDirec dist_folder)
{
    char exe_command[MAX_PATH_LEN];
    strcpy(exe_command, " python3 ");
    strcat(exe_command, name->Path);
    strcat(exe_command, " > ");
    strcat(exe_command, dist_folder->Path);
    strcat(exe_command, "/test_logs.txt");
    system(exe_command);
}

PtrToDirec FindFile(PtrToDirec root, char *file_name)
{
    PtrToDirec temp = root->PtrToSubFiles;
    if (temp == NULL)
    {
        return false;
    }
    while (temp->Next != NULL)
    {
        if (AreSame(file_name, temp->Name))
        {
            return temp;
        }
        temp = temp->Next;
    }
    if (AreSame(file_name, temp->Name))
    {
        return temp;
    }
    return false;
}

void test(char *input_string)
{
    PtrToDirec ptrtofolder = FindDirectory(CURRENT_DIRECTORY, input_string);
    PtrToDirec ptrtodist = FindDirectory(ptrtofolder, "dist");
    PtrToDirec exists = FindFile(ptrtodist, "submitter.py");

    if (exists == NULL)
    {
        printf("**No such file \"submitter.py\" - missing or removed\n");
        return;
    }
    else
    {
        Execute(exists, ptrtodist);
    }
}
