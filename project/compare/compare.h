#ifndef __COMPARE_H
#define __COMPARE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>

#include "../Shell/user.h"
#include "../switch/switch.h"
#include "../Shell/directory.h"
#include "../create/create.h"

void compare(char *input_string, char *input_string1);
void exec(PtrToDirec name, char *input_string, PtrToDirec name1, char *input_string1);

#endif
