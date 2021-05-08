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

void copy_file(char *source, char *destination)
{
    char exe_command[MAX_PATH_LEN];
    char s[MAX_PATH_LEN];
    char d[MAX_PATH_LEN];

    strcpy(exe_command, "cp ");

    strcpy(s, source);
    AddSlashSpaceInSubjectName(s); /////// source
    strcat(exe_command, s);

    strcat(exe_command, " ");

    strcpy(d, destination);
    AddSlashSpaceInSubjectName(d); ////// destination
    strcat(exe_command, d);

    system(exe_command);
}

void remove_file(PtrToDirec file)
{
    char clean_it[MAX_PATH_LEN];
    char path[MAX_PATH_LEN];

    strcpy(clean_it, "rm ");
    strcpy(path, file->Path);
    AddSlashSpaceInSubjectName(path);
    strcat(clean_it, path);

    system(clean_it);
}

char *get_last_modified_date(PtrToDirec file)
{
    char *time = (char *)malloc(sizeof(char) * MAX_LEN_NAME);
    char path[MAX_PATH_LEN];
    strcpy(time, "stat -c '%y' ");
    strcpy(path,file->Path);
    AddSlashSpaceInSubjectName(path);
    strcat(time,path);

    FILE *fp = fopen("i.txt", "w");
    fclose(fp);

    strcat(time, " > i.txt");
    system(time);

    fp = fopen("i.txt", "r");
    int i = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%ch", &time[i]);
        i++;
    }
    remove("i.txt");
    return time;
}

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
            if (strcmp(last_md_of_assign, last_md_of_copy) > 0)
            {
                remove_file(curr);
                copy_file(temp->Path, curr->Path);
            }
            free(last_md_of_assign);
            free(last_md_of_copy);
        }
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
