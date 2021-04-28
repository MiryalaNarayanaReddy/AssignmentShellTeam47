#include "../switch/switch.h"
#include "use.h"

bool use(char *input_string)
{
    PtrToDirec temp = CURRENT_DIRECTORY;
    if (FindDirectory(CURRENT_DIRECTORY, input_string) != NULL)
    {
        Switch_Directory(CURRENT_DIRECTORY, input_string);

        NEW_CURR_PATH = CURRENT_DIRECTORY;
        //printf("%s \n", NEW_CURR_PATH->Name);
        CURRENT_DIRECTORY = temp;
        return true;
    }
    else
    {
        return false;
    }
}

void change_dir_back()
{
    int index = 0;
    int LastForwordSlash = 0;
    while (PATH_OF_CURRENT_DIRECTORY[index] != '\0')
    {
        if (PATH_OF_CURRENT_DIRECTORY[index] == '/')
        {
            LastForwordSlash = index;
        }
        index++;
    }
    PATH_OF_CURRENT_DIRECTORY[LastForwordSlash] = '\0';
}

