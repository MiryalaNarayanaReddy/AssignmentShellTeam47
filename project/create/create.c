#include "create.h"
#include "../switch/switch.h"
#include "../Shell/directory.h"
#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>

// if there are any white spaces in names of folders then
// this function adds a '\' before every white space in the given path

void AddSlashSpaceInSubjectName(char *input_string)
{
    char s[MAX_PATH_LEN];
    strcpy(s, input_string);
    int i = 0;
    int j = 0;
    while (s[i] != '\0')
    {
        if (s[i + 1] != ' ' && s[i] == ' ') // linear algerbra --->linear\ algebra
        {
            input_string[j++] = '\\';
            input_string[j++] = s[i++];
        }
        input_string[j++] = s[i++];
    }
    input_string[j] = '\0';
    // printf("%s\n", input_string);
}

/*************************************************************************************
 *                                                                                   *
 * This uses system (terminal) command                                               *
 * cp -r source_path destination_path                                                *
 * here -r is for recurrsive copying                                                 *
 * cp -r ../../assignment/./ ../../user/linear algebra/assign-1/./                   *
 * This will no work because 'linear algebra' has a white space.                     *
 * cp -r ../../assignment/./ ../../user/linear\ algebra/assign-1/./                  *
 * this will work.i.e.,put a back slash before every space in the name of folder.    *
 *                                                                                   *
 *************************************************************************************/

void copy_everything(char *destination)
{
    char command[MAX_PATH_LEN];
    strcpy(command, "cp -r ");
    strcat(command, "../../assignment/./ "); //source

    char dest_path[MAX_PATH_LEN];
    strcpy(dest_path, PATH_OF_CURRENT_DIRECTORY);
    strcat(dest_path, "/./");
    strcat(dest_path, destination);
    AddSlashSpaceInSubjectName(&dest_path[0]); //destination

    strcat(command, dest_path);
    system(command);
}
// creates a directory and copies everything from assignment folder into input_string folder in current directory
void create(char *input_string)
{
    char new_assign[MAX_PATH_LEN];

    strcpy(new_assign, PATH_OF_CURRENT_DIRECTORY);
    strcat(new_assign, "/");
    strcat(new_assign, input_string); //now new_assign contains the path to this input_string folder relative to main.

    PtrToDirec dir = FindDirectory(CURRENT_DIRECTORY, input_string);

    if (dir == NULL) //there is no such folder so make it.
    {
        MakeNewFolder(new_assign);
    }
    else
    {
        printf("folder with name");
        char error_str[MAX_LEN_NAME];
        sprintf(error_str, " %s ", input_string);
        print_in_color(error_str, RED, BOLD);
        printf("already exists...\n");
        print_in_color("No copying done\n", GREEN, BOLD);
        return;
    }
    copy_everything(input_string);

    //this is for updating the tree in the code
    // (just adds in the begining of list of subdirectories of current directory )
    PtrToDirec New_dir = InitializeDirecTree(input_string, new_assign);
    New_dir->Next = CURRENT_DIRECTORY->PtrToSubDirecs;
    CURRENT_DIRECTORY->PtrToSubDirecs = New_dir;
}

// makes a folder with given path
void MakeNewFolder(char *Path_to_new_directory)
{
    mkdir(Path_to_new_directory, 0700);
    DIR *curr_dir = opendir(Path_to_new_directory);

    if (curr_dir) //curr_dir is not NULL
    {
        closedir(curr_dir);
    }
    else
    {
        print_in_color("could not open folder\n", RED, NOTBOLD);
    }
}
