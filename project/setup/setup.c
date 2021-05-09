#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include "../Shell/user.h"
#include "../create/create.h"

//makes the directory given pos-->index of point of path where the tree starts
//and number of subfolders is spaces and name of directory to be created.
void make_dir_path(char *path, int pos, int spaces, char *new_dir_name)
{
    int index = pos;
    while (spaces != 0)
    {
        if (path[index++] == '/') //count the number of '/''s and you have add your folder there.
            spaces--;
    }
    path[index] = '\0'; //cut the string at that point and concatinate it with dir_name
    strcat(path, new_dir_name);
    mkdir(path, 0700);
}

void setup(char *input_string)
{
    char tree_path[MAX_PATH_LEN];
    strcpy(tree_path, PATH_OF_CURRENT_DIRECTORY);
    strcat(tree_path, "/");
    strcat(tree_path, input_string);
    // AddSlashSpaceInSubjectName(tree_path);
    mkdir(tree_path, 0700);
    strcat(tree_path, "/");
    //  printf("%s\n", tree_path);
    int len = strlen(tree_path); // this is the point where one has to make folders and added it to the path

    FILE *fp = fopen("../../i.txt", "r"); //txt file with indented folder names.

    int space_count = 0;
    char ch;
    char str[2];
    str[1] = '\0';
    char new_folder[MAX_PATH_LEN];

    while (!feof(fp)) // while not end of file.
    {
        space_count = 0;
        fscanf(fp, "%c", &ch);

        while (ch == ' ') //count number of spaces
        {
            fscanf(fp, "%c", &ch);
            space_count++;
        }
        new_folder[0] = '\0'; //starting new_folder
        while (ch != '\n')    //scan the whole string upto '\n'
        {
            str[0] = ch;             //store it in str
            strcat(new_folder, str); //concatinate it with new_folder name
            fscanf(fp, "%c", &ch);
        }
        //   printf("%s - -  -", new_folder);
        make_dir_path(tree_path, len, space_count, new_folder); //new_folder contains folder name
        strcat(tree_path, "/");
        // printf("%s\n", tree_path);
    }
}
