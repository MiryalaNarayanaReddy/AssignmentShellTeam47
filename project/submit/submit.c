#include "submit.h"

void execute(PtrToDirec name, char *input_string)
{
    char exe_command[MAX_PATH_LEN];
    strcpy(exe_command, "zip -r ");
    strcat(exe_command, name->Path);
    strcat(exe_command, ".zip ");
    strcat(exe_command, name->Path);

    system(exe_command);
}

void zipper(char *input_string)
{
    char folder[1000];
    char final_zip[1000];

    PtrToDirec ptrtofolder = FindDirectory(CURRENT_DIRECTORY, input_string);

    if (ptrtofolder == NULL)
        printf("File does not exist\n");

    else
        execute(ptrtofolder, input_string);
}
