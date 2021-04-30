#ifndef __USER_H
#define __USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "directory.h"

#define MAX_STRLEN 100


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
    __EXIT,
    __print_path,
    __print_name,
    __print_name_and_path,
    __tree,
    __back
};

typedef int Command;
typedef char *string;

void prompt();
Command Get_Command();
void PerformAction(PtrToDirec root, Command command, bool *using_use);

bool AreSame(char *, char *);

char use_input_string[MAX_LEN_NAME];

#endif
