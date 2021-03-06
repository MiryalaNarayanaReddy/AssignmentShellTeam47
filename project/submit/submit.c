#include "submit.h"

// this code uses this method to zip
// cd ../../user/dsa && zip -r assign-1.zip assign-1 && cd -

void execute(PtrToDirec name, char *input_string)
{
    char exe_command[MAX_PATH_LEN];
    char s[1000];
    char path[MAX_PATH_LEN];
    
    print_in_color("Zipping...", PINK, NOTBOLD);

    strcpy(path, CURRENT_DIRECTORY->Path);
    AddSlashSpaceInSubjectName(path); //add slash before every space

    //for changing directory
    strcpy(exe_command, "cd ");
    strcat(exe_command, path);

    strcat(exe_command, " && ");

    //for zipping
    strcat(exe_command, "zip -r ");
    strcat(exe_command, input_string);
    strcat(exe_command, ".zip ");
    strcat(exe_command, input_string);

    // for changing directory
    strcat(exe_command, " && ");
    strcat(exe_command, "cd -");
    printf("\n");

    system(exe_command);

    strcpy(s,input_string);
    strcat(s,".zip");

    //For adding this zipped file to the tree structure
    PtrToDirec New_dir = InitializeDirecTree(s, name->Path);
    New_dir->Next = CURRENT_DIRECTORY->PtrToSubDirecs;
    CURRENT_DIRECTORY->PtrToSubDirecs = New_dir;
}

void zipper(char *input_string)
{
    char error_str[1000];

    //The path of the assignment folder is found and stored
    PtrToDirec ptrtofolder = FindDirectory(CURRENT_DIRECTORY, input_string);

    //Checks if the paths exist (i.e. if both folders exist)
    if (ptrtofolder == NULL)
    {
        sprintf(error_str, "%s - No such folder\n", input_string);
        print_in_color(error_str, RED, NOTBOLD);
    }
    //If it exists execute the zipping procedure
    else
        execute(ptrtofolder, input_string);
}
