#include "user.h"
#include "directory.h"

#include "../switch/switch.h"
#include "../create/create.h"
// #include "../update/update.h"
// #include "../setup.setup.h"
#include "../submit/submit.h"
#include "../test/test.h"
// #include "../compare/compare.h"
#include "../use/use.h"

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
        get_string(input_string);
        Switch_Directory(root, input_string);
        break;
    case __create:
        get_string(input_string);
        create(input_string);
        break;
    case __update:

        break;
    case __setup:

        break;
    case __test:
        get_string(input_string);
        test(input_string);
        break;
    case __submit:
        get_string(input_string);
        zipper(input_string);
        break;
    case __compare:

        break;
    case __use:
        get_string(input_string);
        use(input_string);
        break;
    case __back:
        change_dir_back();
        break;
    case __tree:
        printf("\n");
        PrintDirecTree(CURRENT_DIRECTORY, 0, __print_name);
        printf("\n");
        break;
    default:
        printf("***SOMTHING IS WRONG***\n");
        printf("exiting.....\n");
        exit(EXIT_FAILURE);
        break;
    }
}
