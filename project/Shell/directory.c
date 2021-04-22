#include "directory.h"

PtrToDirec NewDirec(char name[])
{
    PtrToDirec new_direc = (PtrToDirec)malloc(sizeof(Direc));
    if (new_direc == NULL)
    {
        printf("**Failed to make new dir node in tree**\n");
        return NULL;
    }
    strcpy(new_direc->Name, name);
    new_direc->PtrToSubFiles = NULL;
    new_direc->PtrToSubDirecs = NULL;
    return new_direc;
}

void ListDirecs(PtrToDirec root)
{
    //  printf("path  - %s\n",root->Path);
    DIR *dir = opendir(root->Path);
    if (dir == NULL)
    {
        return;
    }
    struct dirent *curr_dir = readdir(dir);

    while (curr_dir != NULL)
    {
        if (strcmp(curr_dir->d_name, ".") != 0 && strcmp(curr_dir->d_name, "..") != 0)
        {
            if (curr_dir->d_type == DT_DIR)
            {
                if (root->PtrToSubDirecs == NULL)
                {
                    root->PtrToSubDirecs = NewDirec(curr_dir->d_name);
                }
                else
                {
                    PtrToDirec temp = NewDirec(curr_dir->d_name);
                    temp->Next = root->PtrToSubDirecs;
                    root->PtrToSubDirecs = temp;
                }
                strcpy(root->PtrToSubDirecs->Path, root->Path);
                strcat(root->PtrToSubDirecs->Path, "/");
                strcat(root->PtrToSubDirecs->Path, curr_dir->d_name);

                //   printf("%s\n", curr_dir->d_name);

                ListDirecs(root->PtrToSubDirecs);
            }
            else
            {
                if (root->PtrToSubFiles == NULL)
                {
                    root->PtrToSubFiles = NewDirec(curr_dir->d_name);
                }
                else
                {
                    PtrToDirec temp = NewDirec(curr_dir->d_name);
                    temp->Next = root->PtrToSubFiles;
                    root->PtrToSubFiles = temp;
                }
                // printf("%s\n", curr_dir->d_name);
            }
        }
        curr_dir = readdir(dir);
    }
    closedir(dir);
}

void print_direc_tree(PtrToDirec root, int depth)
{
    PtrToDirec temp = root;
    if (depth > 0)
        for (int i = 0; i < depth; i++)
        {
            printf(" ");
        }
    printf("%s\n", root->Name);

    depth++;
    temp = root->PtrToSubDirecs;

    while (temp != NULL)
    {
        for (int i = 0; i < depth; i++)
        {
            printf(" ");
        }
        print_direc_tree(temp, depth);
        temp = temp->Next;
    }
    temp = root->PtrToSubFiles;
    while (temp != NULL)
    {
        for (int i = 0; i < depth; i++)
        {
            printf(" ");
        }
        print_direc_tree(temp, depth);
        temp = temp->Next;
    }
}

PtrToDirec InitializeDirec()
{
    PtrToDirec DirecTree = NewDirec("user");
    strcpy(DirecTree->Path, "../../user");
    ListDirecs(DirecTree);
    print_direc_tree(DirecTree, 0);
}

// void InitializePath()
// {
//     strcpy(PATH_OF_CURRENT_DIRECTORY, "../user");
// }
// void Print_current_directory_path()
// {
//     int i = 3;
//     while (PATH_OF_CURRENT_DIRECTORY[i] != '\0')
//     {
//         printf("%c", PATH_OF_CURRENT_DIRECTORY[i++]);
//     }
// }
