#ifndef __SWITCH_H
#define __SWITCH_H

#include "../Shell/user.h"


void Switch_Directory(PtrToDirec root, char *input_string);

PtrToDirec FindDirectory(PtrToDirec root, char *dir_name);
/* searches only subdirectory names in root directory */

void CreateNewDirectory();
//really creates directory

#endif