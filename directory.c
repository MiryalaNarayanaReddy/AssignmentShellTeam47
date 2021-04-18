#include "directory.h"

void InitializePath()
{
    strcpy(PATH_OF_CURRENT_DIRECTORY, "../user");
}

void Print_current_directory_path()
{
    int i = 3;
    while (PATH_OF_CURRENT_DIRECTORY[i] != '\0')
    {
        printf("%c", PATH_OF_CURRENT_DIRECTORY[i++]);
    }
}
