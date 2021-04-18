#ifndef __DIRECTORY_H
#define __DIRECTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LEN 1000

char PATH_OF_CURRENT_DIRECTORY[MAX_PATH_LEN];

void InitializePath();
void Print_current_directory_path();

#endif