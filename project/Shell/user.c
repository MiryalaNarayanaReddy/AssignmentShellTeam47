#include "user.h"
#include "directory.h"

#include "../switch/switch.h"
#include "../create/create.h"
#include "../update/update.h"
#include "../setup/setup.h"
#include "../submit/submit.h"
#include "../test/test.h"
// #include "../compare/compare.h"
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

void prompt()
{
    Print_current_directory_path();
    print_in_color(">", BLUE, BOLD);
}

bool AreSame(char *a, char *b)
{
    if (strcmp(a, b) == 0)
    {
        return true;
    }
    else
        return false;
}

void get_string(char *s)
{
    char ch;
    int i = 0;
    while ((ch = getchar()) == ' ')
        ;
    do
    {
        s[i++] = ch;
    } while ((ch = getchar()) != '\n');

    s[i] = '\0';
}

void clean_input()
{
    char ch;
    while ((ch = getchar()) != '\n')
        ;
}

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
    else
    {
        fflush(stdin);
        fflush(stdout);
        return __INVALID_COMMAND;
    }
}

void PerformAction(PtrToDirec root, Command command, bool *using_use)
{
    bool __using_use = *using_use;
    char input_string[MAX_STRLEN];

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
        get_string(input_string);
        setup(input_string);
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

        break;
    case __use:
        get_string(input_string);
        if (use(input_string))
        {
            __using_use = true;
            strcpy(use_input_string, input_string);
        }
        else
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
            PrintDirecTree(NEW_CURR_PATH, 0, __print_name);
        }
        else
        {
            PrintDirecTree(CURRENT_DIRECTORY, 0, __print_name);
        }
        printf("\n");
        break;
    case __back:
        change_dir_back();
        __using_use = false;
        break;
    default:
        print_in_color("***SOMTHING IS WRONG***\n", GREEN, BOLD);
        print_in_color("exiting.....\n", GREEN, BOLD);
        exit(EXIT_FAILURE);
        break;
    }
    *using_use = __using_use;
}
