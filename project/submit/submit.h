#ifndef __SUBMIT_H
#define __SUBMIT_H

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

void zipper(char *input_string);
void execute(PtrToDirec name, char *input_string);

#endif
