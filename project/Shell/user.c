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

bool __using_use = false;
char use_input_string[MAX_LEN_NAME];
void prompt()
{
    Print_current_directory_path();
    printf(">");
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

void PerformAction(PtrToDirec root, Command command)
{
    char input_string[MAX_STRLEN];

    switch (command)
    {
    case __EXIT:
        exit(EXIT_SUCCESS);
        break;
    case __INVALID_COMMAND:
        printf("*** INVALID COMMAND ***\n");
        break;
    case __switch:
        if (__using_use)
        {
            fflush(stdin);
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
            fflush(stdin);
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
            fflush(stdin);
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
            fflush(stdin);
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
            fflush(stdin);
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
            printf("%s - No such folder\n", input_string);
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
        printf("***SOMTHING IS WRONG***\n");
        printf("exiting.....\n");
        exit(EXIT_FAILURE);
        break;
    }
}
