#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

#define MAX_PATH_LEN 1000

void make_dir_path(char *path, int spaces, char *new_dir_name)
{
    int index = 0;
    while (spaces != 0)
    {
        if (path[index++] == '/')
            spaces--;
    }
    path[index] = '\0';
    strcat(path, new_dir_name);
    mkdir(path, 0700);
}

void setup(char *file_path)
{
    char tree_path[MAX_PATH_LEN];
    strcpy(tree_path, "../../");
    FILE *fp = fopen(file_path, "r");
    int space_count = 0;
    char ch;
    char str[2];
    str[1] = '\0';
    char new_folder[MAX_PATH_LEN];
    while (!feof(fp))
    {
        space_count = 0;
        fscanf(fp, "%c", &ch);
        while (ch == ' ')
        {
            fscanf(fp, "%c", &ch);
            space_count++;
        }
        new_folder[0] = '\0';
        while (ch != '\n')
        {
            str[0] = ch;
            strcat(new_folder, str);
            fscanf(fp, "%c", &ch);
        }
        //  printf("%s - -  -", new_folder);
        make_dir_path(tree_path, space_count + 2, new_folder);
        strcat(tree_path, "/");
        //  printf("%s\n", tree_path);
    }
}