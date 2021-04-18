#include "user.h"
#include <../switch/switch.h>
#include <../create/create.h>
#include <../update/update.h>
#include <../setup.setup.h>
#include <../submit/submit.h>
#include <../compare/compare.h>
#include <../use/use.h>

#define MAX_STRLEN 100

void prompt()
{
    Print_current_directory_path();
    printf("> ");
}

bool AreSame(Command a, Command b)
{
    if (strcmp(a, b) == 0)
    {
        return true;
    }
    else
        return false;
}

Command Get_Command()
{
    char input_string[MAX_STRLEN];
    scanf("%s", &input_string);
    string command = (string)malloc(sizeof(char) * (strlen(s) + 1));
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
        printf("***INVALID COMMAND***");
        return Get_Command();
    }
}

PerformAction(Command command)
{
}
