#include "user.h"
#include "directory.h"
#include "../switch/switch.h"

// #include <../create/create.h>
// #include <../update/update.h>
// #include <../setup.setup.h>
// #include <../submit/submit.h>
// #include <../compare/compare.h>
// #include <../use/use.h>

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

// char *get_string()
// {
//     char ch;
//     int i = 0;
//     char s[MAX_STRLEN];
//     while ((ch = getchar()) != '\n')
//         s[i++] = ch;
//     s[i] = '\0';
//     char *string = (char *)malloc(sizeof(char) * (strlen(s) + 1));
//     return string;
// }

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
    else
    {
        fflush(stdin);
        printf("***INVALID COMMAND***\n");
        fflush(stdout);
        return __INVALID_COMMAND;
    }
}

void PerformAction(Command command)
{
    char input_string[MAX_STRLEN];
    //  scanf("%s", input_string);

    switch (command)
    {
    case __EXIT:

        printf("Enter password: ");
        scanf("%s", input_string);
        if (AreSame(input_string, password))
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            printf("Wrong password\n");
        }
        break;
    case __INVALID_COMMAND:

        break;
    case __switch:
        get_string(input_string);
        Switch_Directory(input_string);
        break;
    case __create:

        break;
    case __update:

        break;
    case __setup:

        break;
    case __test:

        break;
    case __submit:

        break;
    case __compare:

        break;
    case __use:

        break;
    default:
        printf("***SOMTHING IS WRONG***\n");
        printf("exiting.....\n");
        exit(EXIT_FAILURE);
        break;
    }
}
