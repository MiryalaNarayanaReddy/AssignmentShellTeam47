#include <stdio.h>
#include "directory.h"
#include "user.h"

int main()
{
  PtrToDirec direc_tree = InitializeDirecTree("user", "../../user");
  CURRENT_DIRECTORY = direc_tree;
  InitializePath();
  prompt();
  Command command;
  bool __using_use = false;
  while (true)
  {
    command = Get_Command();
    PerformAction(direc_tree, command,&__using_use);
    prompt();
  }
}
