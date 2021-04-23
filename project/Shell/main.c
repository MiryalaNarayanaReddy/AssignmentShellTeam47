#include <stdio.h>
#include "directory.h"
#include "user.h"

int main()
{
  printf("The password you are entering is temporary.\n");
  printf("Use it to exit from the program\n");
  printf("Enter Password : ");
  scanf("%s", password);

  PtrToDirec direc_tree = InitializeDirecTree("assignment", "../../");
  printf("\nyour direc tree \n\n");
  PrintDirecTree(direc_tree, 0, __print_name);
  printf("\n\n");

  InitializePath();
  prompt();
  Command command;

  while (true)
  {
    command = Get_Command();
    PerformAction(command);
    prompt();
  }
}