#include "directory.h"
#include "user.h"

// returns pointer to the new node(directory) created with given name.

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

// This inserts all subdirectorys and files(inside a given folder) into root.
// this avoids . and .. files because they cause infinite recurrsion.

void ListDirecs(PtrToDirec root)
{
    //  printf("path  - %s\n",root->Path);
    DIR *dir = opendir(root->Path); //open the directory
    if (dir == NULL)
    {
        return;
    }
    struct dirent *curr_dir = readdir(dir); //gets the pointer to the actual directory contents

    while (curr_dir != NULL)
    {
        /*ignore ".git" folder we don't need it*/
        /*. and .. folders cause infinite recurrsion*/
        if (strcmp(curr_dir->d_name, ".") != 0 && strcmp(curr_dir->d_name, "..") != 0 && strcmp(curr_dir->d_name, ".git") != 0)
        {
            if (curr_dir->d_type == DT_DIR) //checks if it is directory
            {
                if (root->PtrToSubDirecs == NULL) // subdirectory section has no folders
                {
                    root->PtrToSubDirecs = NewDirec(curr_dir->d_name);
                }
                else // subdirectory section has some folders
                {
                    //insert new one in the starting of linked list.
                    PtrToDirec temp = NewDirec(curr_dir->d_name);
                    temp->Next = root->PtrToSubDirecs;
                    root->PtrToSubDirecs = temp;
                }
                //store the path and name in the node.
                strcpy(root->PtrToSubDirecs->Path, root->Path);
                strcat(root->PtrToSubDirecs->Path, "/");
                strcat(root->PtrToSubDirecs->Path, curr_dir->d_name);

                //   printf("%s\n", curr_dir->d_name);

                ListDirecs(root->PtrToSubDirecs); //list the subdirectories
            }
            else
            {
                //it is file so insert in subfiles section.
                if (root->PtrToSubFiles == NULL) // subfiles section has no files
                {
                    root->PtrToSubFiles = NewDirec(curr_dir->d_name);
                }
                else //subfiles section has some files
                {
                    //insert new one in the starting of linked list.
                    PtrToDirec temp = NewDirec(curr_dir->d_name);
                    temp->Next = root->PtrToSubFiles;
                    root->PtrToSubFiles = temp;
                }
                //store the path and name in the node.
                strcpy(root->PtrToSubFiles->Path, root->Path);
                strcat(root->PtrToSubFiles->Path, "/");
                strcat(root->PtrToSubFiles->Path, curr_dir->d_name);
                // printf("%s\n", curr_dir->d_name);
            }
        }
        curr_dir = readdir(dir); //read the next name of folder or file.
    }
    closedir(dir); //close the directory stream or buffer.
}

// this prints n spaces
void _print_spaces(int Number)
{
    if (Number > 0)
        for (int i = 0; i < Number; i++)
        {
            printf(" ");
        }
}

/****************************************************************************
 *                                                                          *
 *  __print_tree_choice()  will print the root as follows                   *
 *                                                                          *
 * if choice  == __print_path --->this will print the path of root.         *
 *            == __print_name ---> this will print the name of root.        *
 *            == __print_name_and_path --->this print both name and path.   *
 *                                                                          *
 * if it is directory--->print in green color                               *
 * if it is file     --->print in pink color                                *
 *                                                                          *
 ****************************************************************************/

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

/*******************************************************************************************************************
 *                                                                                                                 *
 * PrintDirecTree() will print the tree structure with indentation based on the depth of the node.                 *
 *                                                                                                                 *
 * this will recurrsively call itself on subdirectories with depth =  depth+1                                      *
 * it takes root node and current depth initally will be 0 when using in other functions                           *
 * And choice so that it is passed to __print_tree_choice to print names or paths or both...                       *
 * This function will not print the root it will print only its contents so..                                      *
 * if you want it you print(using __print_tree_choice ofcourse) it yourself and call this funtion with depth =1    *
 *                                                                                                                 *
 *******************************************************************************************************************/
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

/*
 * InitializeDirecTree() will initialize a tree i.e,
 * you give the name of folder and its path relative to main function then
 * it will make new directory node and passes it to ListDirecs() function to list all directories and files into the tree
 * then it will return the root.
 */

PtrToDirec InitializeDirecTree(char name[], char root_path[])
{
    PtrToDirec DirecTree = NewDirec(name);
    strcpy(DirecTree->Path, root_path);
    ListDirecs(DirecTree);
    return DirecTree;
}

//This is hard coded path of user folder.

void InitializePath()
{
    strcpy(PATH_OF_CURRENT_DIRECTORY, "../../user");
}

//this wil abbreviate the name of the subject only.
void AbbreviateSubject()
{
    char s[MAX_PATH_LEN];
    int i = 6, j = 0; //here 6 is hard coded as  path contains ../../user we remove ../../ in prompt.

    while (PATH_OF_CURRENT_DIRECTORY[i] != '/' && PATH_OF_CURRENT_DIRECTORY[i] != '\0')
    {
        PROMPT_PATH[j++] = PATH_OF_CURRENT_DIRECTORY[i++];
    }
    PROMPT_PATH[j++] = PATH_OF_CURRENT_DIRECTORY[i];
    PROMPT_PATH[j] = '\0';
    j = 0;
    if (PATH_OF_CURRENT_DIRECTORY[i] == '/')
    {
        i++;
        s[j++] = PATH_OF_CURRENT_DIRECTORY[i];
    }
    while (PATH_OF_CURRENT_DIRECTORY[i] != '/' && PATH_OF_CURRENT_DIRECTORY[i] != '\0') //abbreviates subject
    {
        if (PATH_OF_CURRENT_DIRECTORY[i + 1] != ' ' && (PATH_OF_CURRENT_DIRECTORY[i] == ' ' || PATH_OF_CURRENT_DIRECTORY[i] == '/'))
        {
            s[j++] = PATH_OF_CURRENT_DIRECTORY[i + 1];
        }
        i++;
    }
    s[j] = '\0';
    //   printf("%s\n%s\n", PROMPT_PATH, s);
    strcat(PROMPT_PATH, s);
    strcat(PROMPT_PATH, &PATH_OF_CURRENT_DIRECTORY[i]); //joins rest of the path to PROMPT_PATH
}

// This will print the path of current directory in bold blue color.

void Print_current_directory_path(bool abbreviate_subject)
{
    if (abbreviate_subject)
    {
        AbbreviateSubject();
        print_in_color(&PROMPT_PATH[0], BLUE, BOLD);
    }
    else
    {
        print_in_color(&PATH_OF_CURRENT_DIRECTORY[6], BLUE, BOLD);
    }
    //here 6 is hard coded as  path contains ../../user we remove ../../ in prompt.
}
