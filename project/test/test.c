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
#include "../Shell/user.h"

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

    while (temp != NULL)
    {
        if (AreSame(file_name, temp->Name))
        {
            return temp;
        }
        temp = temp->Next;
    }
    return temp;
}

void test(char *input_string)
{
    char err_message[MAX_LEN_NAME];
    PtrToDirec ptrtofolder = FindDirectory(CURRENT_DIRECTORY, input_string);
    if (ptrtofolder == NULL)
    {
        sprintf(err_message, "%s is missing\n", input_string);
        print_in_color(err_message, RED, NOTBOLD);
        return;
    }
    PtrToDirec ptrtodist = FindDirectory(ptrtofolder, "dist");
    if (ptrtodist == NULL)
    {
        sprintf(err_message, "dist folder is missing\n");
        print_in_color(err_message, RED, NOTBOLD);

        return;
    }
    PtrToDirec exists = FindFile(ptrtodist, "submitter.py");

    if (exists == NULL)
    {
        sprintf(err_message, "**No such file \"submitter.py\" - missing or removed\n");
        print_in_color(err_message, RED, NOTBOLD);

        return;
    }
    else
    {
        Execute(exists, ptrtodist);

        if (FindFile(ptrtodist, "test_logs.txt")!=NULL)
        {
            return;
        }
        PtrToDirec logs_file = NewDirec("test_logs.txt");
        logs_file->Next = ptrtodist->PtrToSubFiles;
        ptrtodist->PtrToSubFiles = logs_file;
        strcpy(logs_file->Path, ptrtodist->Path);
        strcat(logs_file->Path, "/");
    }
}
