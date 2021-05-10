#include "compare.h"

void exec(PtrToDirec name, char *input_string, PtrToDirec name1, char *input_string1)
{
    char execommand[MAX_PATH_LEN];

    print_in_color("Displaying differences...", PINK, NOTBOLD);

    char path[MAX_PATH_LEN];

    strcpy(path, name1->Path);
    AddSlashSpaceInSubjectName(path); //add slash before every space
    
    char path1[MAX_PATH_LEN];

    strcpy(path1, name->Path);
    AddSlashSpaceInSubjectName(path1); //add slash before every space

    //unzipping the zipped file using system command
    strcpy(execommand, "unzip ");
    strcat(execommand, path);
    strcat(execommand, " -d ../../user/");
    strcat(execommand, input_string1);

    system(execommand);
    printf("\n");

    //md5sum of unzipped file is calculated at stored in dir2.txt and md5sum of required assignment in dir1.txt
    strcpy(execommand, "find ");
    strcat(execommand, path1);
    strcat(execommand, " -type f -exec md5sum {} + | sort -k 2 | sed 's/ .*\\// /'> dir1.txt");
    system(execommand);
    strcpy(execommand, "find ../../user/");
    strcat(execommand, input_string1);
    strcat(execommand, " -type f -exec md5sum {} + | sort -k 2 | sed 's/ .*\\// /'> dir2.txt");
    system(execommand);

    //the two are compared and the different files are printed using system commands
    strcpy(execommand, "diff -s dir1.txt dir2.txt");
    system(execommand);
    printf("\n");

    //the created dir1.txt, dir2.txt and unzipped folder are deleted using system commands
    strcpy(execommand, "rm dir1.txt");
    system(execommand);

    strcpy(execommand, "rm dir2.txt");
    system(execommand);

    strcpy(execommand, "rm -r ../../user/");
    strcat(execommand, input_string1);

    system(execommand);
}

void compare(char *input_string, char *input_string1)
{
    char error_str[MAX_LEN_NAME];

    //The paths of the assignment folder and zipped folder are found and stored
    PtrToDirec ptrtofolder = FindDirectory(CURRENT_DIRECTORY, input_string);
    PtrToDirec ptrtofolder1 = FindDirectory(CURRENT_DIRECTORY, input_string1);

    //Checks if the paths exist (i.e. if both folders exist)
    if (ptrtofolder == NULL)
    {
        sprintf(error_str, "%s - No such folder\n", input_string);
        print_in_color(error_str, RED, NOTBOLD);
    }

    else if (ptrtofolder1 == NULL)
    {
        sprintf(error_str, "%s - No such folder\n", input_string1);
        print_in_color(error_str, RED, NOTBOLD);
    }
    //If both exist execute the comparing procedure
    else
        exec(ptrtofolder, input_string, ptrtofolder1, input_string1);
}
