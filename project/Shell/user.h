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
    __back,
    __clear_screen,
};

typedef int Command;
typedef char *string;

void prompt(bool abbreviate_subject);
Command Get_Command();
void PerformAction(PtrToDirec root, Command command, bool *__using_use);

bool AreSame(char *, char *);

char use_input_string[MAX_LEN_NAME];
void print_in_color(char *string, int color, bool bold);

#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define PINK 35
#define TORSQUE 35
#define BOLD 1
#define NOTBOLD 0

#endif
