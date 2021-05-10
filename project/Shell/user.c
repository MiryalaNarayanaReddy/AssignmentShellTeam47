#include "user.h"
#include "directory.h"

#include "../switch/switch.h"
#include "../create/create.h"
#include "../update/update.h"
#include "../setup/setup.h"
#include "../submit/submit.h"
#include "../test/test.h"
#include "../compare/compare.h"
#include "../use/use.h"

// ESC[background_colour;Text_colourm output ESC[m”

// \033[    \033[m --->for start and end
// \e[1m    \e[0m  --->bold test
// 231 background white color

// red - 31m
// green - 32m
// yellow - 33m
// blue - 34m
// pink - 35m

// prints the given string in specified color and in bold if bold is true.
void print_in_color(char *string, int color, bool bold)
{
    if (bold)
    {
        printf("\033[231;%dm\e[1m%s\e[0m\033[m", color, string);
    }
    else
    {
        printf("\033[231;%dm%s\033[m", color, string);
    }
}

//This will use two functions to print the prompt.

void prompt(bool abbreviate_subject)
{
    Print_current_directory_path(abbreviate_subject);
    print_in_color(">", BLUE, BOLD);
}

//checks if two strings are same.
bool AreSame(char *a, char *b)
{
    if (strcmp(a, b) == 0)
    {
        return true;
    }
    else
        return false;
}

//gets the whole string upto end of line leaving trailing white spaces.
void get_string(char *s)
{
    char ch;
    int i = 0;
    while ((ch = getchar()) == ' ') // to remove spaces in the begining
        ;
    do
    {
        s[i++] = ch;
    } while ((ch = getchar()) != '\n');
    while (s[i - 1] == ' ') //to remove the spaces at the end
    {
        i--;
    }
    s[i] = '\0';
}

//clears the input buffer in one line upto '\n'
void clean_input() 
{
    char ch;
    while ((ch = getchar()) != '\n')
        ;
}

// gets the command a string and returns an encoded number for given string.
Command Get_Command()
{
    char command[10];
    scanf("%s", command);

    // printf("%s\n",command);
    if (AreSame(command, "exit"))
    {
        return __EXIT;
    }
    if (AreSame(command, "switch"))
    {
        return __switch;
    }
    else if (AreSame(command, "create"))
    {
        return __create;
    }
    else if (AreSame(command, "update"))
    {
        return __update;
    }
    else if (AreSame(command, "setup"))
    {
        return __setup;
    }
    else if (AreSame(command, "test"))
    {
        return __test;
    }
    else if (AreSame(command, "submit"))
    {
        return __submit;
    }
    else if (AreSame(command, "compare"))
    {
        return __compare;
    }
    else if (AreSame(command, "use"))
    {
        return __use;
    }
    else if (AreSame(command, "back"))
    {
        return __back;
    }
    else if (AreSame(command, "tree"))
    {
        return __tree;
    }
    else if (AreSame(command, "clear"))
    {
        return __clear_screen;
    }
    else
    {
        clean_input();
        return __INVALID_COMMAND;
    }
}

void PerformAction(PtrToDirec root, Command command, bool *using_use)
{
    bool __using_use = *using_use;
    char input_string[MAX_STRLEN];
    char input_string1[MAX_STRLEN];

    /* if __using_use is true 
     *      we are in assignment folder in some subject folder.
     *      we don't need the assignment name so clear input then call respective functions..
     * else
     *      we get the string and call respective functions
     */

    switch (command)
    {
    case __EXIT:
        print_in_color("exiting...\n", PINK, BOLD);
        exit(EXIT_SUCCESS);
        break;
    case __INVALID_COMMAND:
        print_in_color("*** INVALID COMMAND ***\n", RED, BOLD);
        break;
    case __switch:
        if (__using_use)
        {
            clean_input();
            Switch_Directory(root, use_input_string);
        }
        else
        {
            get_string(input_string);
            Switch_Directory(root, input_string);
        }
        break;
    case __create:
        if (__using_use)
        {
            clean_input();
            create(use_input_string);
        }
        else
        {
            get_string(input_string);
            create(input_string);
        }
        break;
    case __update:
        if (__using_use)
        {
            clean_input();
            update(use_input_string);
        }
        else
        {
            get_string(input_string);
            update(input_string);
        }
        break;
    case __setup:
        if (__using_use)
        {
            clean_input();
            setup(use_input_string);
        }
        else
        {
            get_string(input_string);
            setup(input_string);
        }
        break;
    case __test:
        if (__using_use)
        {
            clean_input();
            test(use_input_string);
        }
        else
        {
            get_string(input_string);
            test(input_string);
        }
        break;
    case __submit:
        if (__using_use)
        {
            clean_input();
            zipper(use_input_string);
        }
        else
        {
            get_string(input_string);
            zipper(input_string);
        }

        break;
    case __compare:
       if (__using_use)
        {
            scanf("%s", input_string);
            if (AreSame(input_string, use_input_string))
            {
                scanf("%s", input_string);
                compare(use_input_string, input_string);
            }
            else
            {
                compare(use_input_string, input_string);
            }
        }
        else
        {
            char zipfile[MAX_LEN_NAME];
            scanf("%s", input_string);
            scanf("%s", zipfile);
            compare(input_string, zipfile);
        }
        break;
    case __use:
        get_string(input_string);
        if (use(input_string)) //this returns true if folder with  name input_string exists.
        {
            __using_use = true;
            strcpy(use_input_string, input_string);
            // store the name in use_input_string so that other functions use this
            // when __using_use is true
        }
        else //no folder with that name
        {
            char error_str[MAX_LEN_NAME];
            sprintf(error_str, "%s - No such folder\n", input_string);
            print_in_color(error_str, RED, NOTBOLD);
        }
        break;
    case __tree:
        printf("\n");
        if (__using_use)
        {
            PrintDirecTree(NEW_CURR_PATH, 0, __print_name); //new current path contains the actual path
        }
        else
        {
            PrintDirecTree(CURRENT_DIRECTORY, 0, __print_name); //this contains the previous path
        }
        printf("\n");
        break;
    case __back:
        change_dir_back();
        __using_use = false;
        break;
    case __clear_screen:
        system("clear");
        break;
    default: //will not happen but is good practice to have it.
        print_in_color("***SOMTHING IS WRONG***\n", GREEN, BOLD);
        print_in_color("exiting.....\n", GREEN, BOLD);
        exit(EXIT_FAILURE);
        break;
    }
    *using_use = __using_use; //store the value of __using_use in *using_use. so that changes are retained.
}
