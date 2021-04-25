#include "../switch/switch.h"

void use(char *input_string)
{
    PtrToDirec temp = CURRENT_DIRECTORY;
    Switch_Directory(CURRENT_DIRECTORY, input_string);
    CURRENT_DIRECTORY = temp;
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
