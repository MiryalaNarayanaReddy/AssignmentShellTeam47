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

  while (true)
  {
    command = Get_Command();
    PerformAction(direc_tree, command);
    prompt();
  }
}