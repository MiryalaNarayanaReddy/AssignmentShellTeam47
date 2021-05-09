#include "../switch/switch.h"
#include "use.h"


// we use 'use' command to add assign folder to the current exisiting prompt ex. " user/dsa/assign> ""
bool use(char *input_string)
{
    PtrToDirec temp = CURRENT_DIRECTORY;
    if (FindDirectory(CURRENT_DIRECTORY, input_string) != NULL) //to find whether the current subject directory has the input string i.e the assignment or not
    {
        Switch_Directory(CURRENT_DIRECTORY, input_string);// switch to the assignment directory 

        NEW_CURR_PATH = CURRENT_DIRECTORY; // NEW_CURR_PATH will be the current directory i.e assignment directory
        //printf("%s \n", NEW_CURR_PATH->Name);

        CURRENT_DIRECTORY = temp; //we need to keep track of current subject directory 
        
        return true;
    }
    else
    {
        return false;
    }
}

/*this is to move back to the current subject directory i.e
from:
user/subject/assign>
to:
user/subject>
*/

void change_dir_back()
{
    int index = 0;
    int LastForwordSlash = 0;
    while (PATH_OF_CURRENT_DIRECTORY[index] != '\0') 
    {
        if (PATH_OF_CURRENT_DIRECTORY[index] == '/') // this will find the index for the last backslash 
        {
            LastForwordSlash = index;     
        }
        index++;
    }
    //printf("%d",index);
    //printf("\n%c",PATH_OF_CURRENT_DIRECTORY[LastForwordSlash]);
    //printf("\n%s",PATH_OF_CURRENT_DIRECTORY); // the path of current directory will be till the assignment folder i.e ../../user/subject/assign
    PATH_OF_CURRENT_DIRECTORY[LastForwordSlash] = '\0'; // this will remove the assign folder as this will travel only till the last backslash
    //printf("\n%s",PATH_OF_CURRENT_DIRECTORY); // now the path will be ../../user/subject
}
