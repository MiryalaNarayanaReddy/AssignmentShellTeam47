#include "update.h"
#include "../create/create.h"
#include "../switch/switch.h"
#include "../Shell/directory.h"
#include "../test/test.h"
#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include "../create/create.h"

void copy_file(char *source, char *destination)//copies a file from source to destination
{
    char exe_command[MAX_PATH_LEN];
    char s[MAX_PATH_LEN];
    char d[MAX_PATH_LEN];

    strcpy(exe_command, "cp ");
//strcpy- It is a C library function which copies 2nd string to the 1st
    strcpy(s, source);
    AddSlashSpaceInSubjectName(s); /////// source
    strcat(exe_command, s);
//strcat- It is a C library function include in string.h header file which concatenates the last string and the first string and stores the result in first string.
    strcat(exe_command, " ");

    strcpy(d, destination);
    AddSlashSpaceInSubjectName(d); ////// destination
    strcat(exe_command, d);

    system(exe_command);
    //Using system(), we can execute any command that can run on terminal if operating system allows.
}

void remove_file(PtrToDirec file)//to remove the file which has been passed in the function.
{
    char clean_it[MAX_PATH_LEN];
    char path[MAX_PATH_LEN];

    strcpy(clean_it, "rm ");
    strcpy(path, file->Path);
    AddSlashSpaceInSubjectName(path);
    strcat(clean_it, path);

    system(clean_it);
}
/*If the time of last modification is more than the time of copying of file in a folder then it copies the new file in that folder*/
char *get_last_modified_date(PtrToDirec file)
{
    char *time = (char *)malloc(sizeof(char) * MAX_LEN_NAME);
    char path[MAX_PATH_LEN];
    strcpy(time, "stat -c '%y' ");
    strcpy(path,file->Path);
    AddSlashSpaceInSubjectName(path);
    strcat(time,path);

    FILE *fp = fopen("i.txt", "w");//(fopen() open the file pointed to using the given mode)
    //"w"=Creates an empty file for writing. If already exist then the contents are erased and is considered an empty file.
    fclose(fp);

    strcat(time, " > i.txt");
    system(time);

    fp = fopen("i.txt", "r");
    //"r"= Opens an existed file for reading.
    int i = 0;
    while (!feof(fp))//while end of the file is not visited i.e all the characters of i.txt get to read, the while loop continues.
    {
        fscanf(fp, "%ch", &time[i]);
        i++;
    }
    remove("i.txt");
    return time;
}
//This function is called recurrsively to check for updates for every folder in it.
void check_for_updates(PtrToDirec root, PtrToDirec check_folder)
{
    if (root == NULL)
        return;
    PtrToDirec temp = root;
    PtrToDirec temp2 = check_folder;

    temp = root->PtrToSubDirecs;
    temp2 = check_folder;

    PtrToDirec curr;

    while (temp != NULL)
    {
        curr = FindDirectory(temp2, temp->Name);

        check_for_updates(temp, curr);
        temp = temp->Next;
    }

    temp = root->PtrToSubFiles;
    temp2 = check_folder;

    char *last_md_of_assign;
    char *last_md_of_copy;

    while (temp != NULL)
    {
        curr = FindFile(temp2, temp->Name);
        if (curr != NULL)
        {
            last_md_of_assign = get_last_modified_date(temp);
            last_md_of_copy = get_last_modified_date(curr);
            if (strcmp(last_md_of_assign, last_md_of_copy) > 0)//checks for the modification time of existed file and changed one(copied)
            {
                remove_file(curr);
                copy_file(temp->Path, curr->Path);
            }
            free(last_md_of_assign);
            free(last_md_of_copy);
        }
        //If a new file has been added
        else
        {
            PtrToDirec new_file = NewDirec(temp->Name);
            new_file = check_folder->PtrToSubFiles;
            check_folder->PtrToSubFiles = new_file;

            strcpy(new_file->Path, check_folder->Path);
            strcat(new_file->Path, "/");
            strcat(new_file->Path, temp->Name);

            copy_file(temp->Path, new_file->Path);
        }
        temp = temp->Next;
    }
}

void update(char *input_string)
{
    PtrToDirec check_folder = FindDirectory(CURRENT_DIRECTORY, input_string);
    PtrToDirec assign_folder = InitializeDirecTree("assignment", "../../assignment");
    check_for_updates(assign_folder, check_folder);
}
