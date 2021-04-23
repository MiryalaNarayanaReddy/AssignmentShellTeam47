#include "switch.h"
#include "../Shell/directory.h"
#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>

void Switch_Directory(PtrToDirec root, char *input_string)
{
    bool exits = DoesDirectoryExist(root, input_string);
    if (!exits)
    {
        PtrToDirec new_dir = NewDirec(input_string);
        assert(new_dir);
        new_dir->Next = root->PtrToSubDirecs;
        root->PtrToSubDirecs = new_dir;
        strcpy(root->PtrToSubDirecs->Path, root->Path);
        strcat(root->PtrToSubDirecs->Path, "/");
        strcat(root->PtrToSubDirecs->Path, input_string);
    }

    strcpy(PATH_OF_CURRENT_DIRECTORY, root->PtrToSubDirecs->Path);

    if (!exits)
    {
        CreateNewDirectory();
    }
}

bool DoesDirectoryExist(PtrToDirec root, char *dir_name)
{
    PtrToDirec temp = root->PtrToSubDirecs;

    if (temp == NULL)
    {
        return false;
    }
    while (temp != NULL)
    {
        if (AreSame(dir_name, temp->Name))
        {
            return true;
        }
        temp = temp->Next;
    }
    return false;
}

void CreateNewDirectory()
{
    mkdir(PATH_OF_CURRENT_DIRECTORY, 0700);
    DIR *curr_dir = opendir(PATH_OF_CURRENT_DIRECTORY);
    if (curr_dir)
    {
        closedir(curr_dir);
    }
    else
    {
        printf("could not open folder\n");
    }
}
