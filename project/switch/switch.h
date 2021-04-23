#ifndef __SWITCH_H
#define __SWITCH_H

#include "../Shell/user.h"

bool DoesDirectoryExist(PtrToDirec root, char *dir_name);
void CreateNewDirectory();
void Switch_Directory(PtrToDirec root, char *input_string);

#endif