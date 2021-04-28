#ifndef __UPDATE_H__
#define __UPDATE_H__

#include "../Shell/directory.h"

void remove_file(PtrToDirec file);
char *get_last_modified_date(PtrToDirec file);
void check_for_updates(PtrToDirec root, PtrToDirec check_folder);
void update(char *input_string);

#endif