#include "directory.h"
#include "user.h"

PtrToDirec NewDirec(char name[])
{
    PtrToDirec new_direc = (PtrToDirec)malloc(sizeof(Direc));
    if (new_direc == NULL)
    {
        print_in_color("**Failed to make new dir node in tree**\n", RED, NOTBOLD);
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
        /*ignore ".git" folder we don't need it*/
        /*. and .. folders cause infinite recurrsion*/
        if (strcmp(curr_dir->d_name, ".") != 0 && strcmp(curr_dir->d_name, "..") != 0 && strcmp(curr_dir->d_name, ".git") != 0)
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

                ListDirecs(root->PtrToSubDirecs); //list the subdirectories
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
                strcpy(root->PtrToSubFiles->Path, root->Path);
                strcat(root->PtrToSubFiles->Path, "/");
                strcat(root->PtrToSubFiles->Path, curr_dir->d_name);
                // printf("%s\n", curr_dir->d_name);
            }
        }
        curr_dir = readdir(dir);
    }
    closedir(dir);
}

void _print_spaces(int Number)
{
    if (Number > 0)
        for (int i = 0; i < Number; i++)
        {
            printf(" ");
        }
}

void __print_tree_choice(PtrToDirec root, int choice, bool IsDir)
{
    char str[MAX_PATH_LEN * 10];
    int COLOR;
    if (IsDir)
    {
        COLOR = GREEN;
    }
    else
    {
        COLOR = PINK;
    }
    if (choice == __print_path)
    {
        sprintf(str, "%s\n", root->Path);
        print_in_color(str, COLOR, BOLD);
    }
    else if (choice == __print_name)
    {
        sprintf(str, "%s\n", root->Name);
        print_in_color(str, COLOR, BOLD);
    }
    else if (choice == __print_name_and_path)
    {
        sprintf(str, "%s ------- path = %s\n", root->Name, root->Path);
        print_in_color(str, COLOR, BOLD);
    }
}

void PrintDirecTree(PtrToDirec root, int depth, int choice)
{
    if (root == NULL)
        return;
    PtrToDirec temp = root;
    depth++;
    temp = root->PtrToSubDirecs;

    while (temp != NULL)
    {
        _print_spaces(depth);
        __print_tree_choice(temp, choice, true);
        PrintDirecTree(temp, depth, choice);
        temp = temp->Next;
    }

    temp = root->PtrToSubFiles;
    while (temp != NULL)
    {
        _print_spaces(depth);
        __print_tree_choice(temp, choice, false);
        temp = temp->Next;
    }
}

PtrToDirec InitializeDirecTree(char name[], char root_path[])
{
    PtrToDirec DirecTree = NewDirec(name);
    strcpy(DirecTree->Path, root_path);
    ListDirecs(DirecTree);
    return DirecTree;
}

void InitializePath()
{
    strcpy(PATH_OF_CURRENT_DIRECTORY, "../../user");
}

void Print_current_directory_path()
{
    print_in_color(&PATH_OF_CURRENT_DIRECTORY[6], BLUE, BOLD);
}
