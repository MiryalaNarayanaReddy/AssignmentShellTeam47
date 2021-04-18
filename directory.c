#include "directory.h"

void InitializePath()
{
   strcpy(PATH_OF_CURRENT_DIRECTORY ,"user");
}

void Print_current_directory_path()
{
    printf("%s", PATH_OF_CURRENT_DIRECTORY);
}
