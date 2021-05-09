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
#include "../create/create.h"

// python3 file.txt > logs.txt
void Execute(PtrToDirec name, PtrToDirec dist_folder)
{
    char exe_command[MAX_PATH_LEN];
    char path[MAX_PATH_LEN];
    strcpy(exe_command, " python3 ");

    strcpy(path, name->Path);
    AddSlashSpaceInSubjectName(path);
    strcat(exe_command, path);
    strcat(exe_command, " > ");

    strcpy(path, dist_folder->Path);
    AddSlashSpaceInSubjectName(path);
    strcat(exe_command, path);

    strcat(exe_command, "/test_logs.txt");
    system(exe_command);
}
// this returns a pointer to file
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

    // folder exists ?
    if (ptrtofolder == NULL)
    {
        sprintf(err_message, "%s is missing\n", input_string);
        print_in_color(err_message, RED, NOTBOLD);
        return;
    }

    PtrToDirec ptrtodist = FindDirectory(ptrtofolder, "dist");

    // dist exists ?
    if (ptrtodist == NULL)
    {
        sprintf(err_message, "dist folder is missing\n");
        print_in_color(err_message, RED, NOTBOLD);

        return;
    }

    PtrToDirec exists = FindFile(ptrtodist, "submitter.py");

    //submitter.py exists ?
    if (exists == NULL)
    {
        sprintf(err_message, "**No such file \"submitter.py\" - missing or removed\n");
        print_in_color(err_message, RED, NOTBOLD);

        return;
    }
    else
    {
        Execute(exists, ptrtodist); //then excute the file

        if (FindFile(ptrtodist, "test_logs.txt") != NULL) //if log.txt file is alreay there
        {
            return;
        }
        PtrToDirec logs_file = NewDirec("test_logs.txt"); //add it to the tree.
        logs_file->Next = ptrtodist->PtrToSubFiles;
        ptrtodist->PtrToSubFiles = logs_file;
        strcpy(logs_file->Path, ptrtodist->Path);
        strcat(logs_file->Path, "/");
    }
}
