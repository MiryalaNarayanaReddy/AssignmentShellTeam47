#ifndef __USER_H
#define __USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
};

typedef int Command;
typedef char *string;

void prompt();
Command Get_Command();
PerformAction(Command);

bool AreSame(Command, Command);

#endif