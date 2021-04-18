#ifndef __USER_H
#define __USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRLEN 100

char password[MAX_STRLEN];

enum
{
    __switch,
    __create,
    __update,
    __setup,
    __test,
    __submit,
    __compare,
    __use,
    __INVALID_COMMAND,
    __EXIT
};

typedef int Command;
typedef char *string;

void prompt();
Command Get_Command();
void PerformAction(Command);

bool AreSame(char *, char *);

#endif