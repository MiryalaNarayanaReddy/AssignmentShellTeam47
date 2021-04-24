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

void Execute(char name[])
{
    char exe_command[MAX_PATH_LEN];
    strcpy(exe_command, " python3 ");
    strcat(exe_command, " ../../dist/submitter.py ");
    strcat(exe_command, " > ../../test_logs_");
    strcat(exe_command, name);
    strcat(exe_command, ".txt");
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
    PtrToDirec dist_tree = InitializeDirecTree("dist", "../../dist");
    PtrToDirec exists = FindFile(dist_tree, "submitter.py");
    if (exists == false)
    {
        printf("**No such file \"submitter.py\" - missing or removed\n");
        return;
    }
    else
    {
        Execute(input_string);
    }
}
