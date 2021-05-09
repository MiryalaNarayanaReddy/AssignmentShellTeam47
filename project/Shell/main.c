#include <stdio.h>
#include "directory.h"
#include "user.h"

#define ABBR 0

int main()
{
  // This is hard coded path of user folder.
  PtrToDirec direc_tree = InitializeDirecTree("user", "../../user");
  CURRENT_DIRECTORY = direc_tree; //current directory is global variable

  //InitializePath() will intialize current directory path but this is also hard coded user folder path
  InitializePath();

  Command command;
  bool __using_use = false;
  bool __abbreviate_subject = false;

#ifdef ABBR
  __abbreviate_subject = true;
#endif

  /*****************************************************
 * Go in a loop                                        *
 * fetching command using Get_Command()                *
 * executing the command using PerformAction(...)      *
 * show the prompt for next command                    *
 ******************************************************/

  /*                         Get_Command()
 *                        /                 \
 *                       /                   \
 *                      /                     |
 *                     |                      |
 *                     |                      V
 *                   Prompt()         PerformAction(..)
 *                     /|\                   /
 *                      \                   /
 *                       \_________________/
 *   
 * 
 */
  // This is like fetch-execute cycle CPU.
  prompt(__abbreviate_subject); //This will print the prompt
  while (true)
  {
    command = Get_Command();
    PerformAction(direc_tree, command, &__using_use);
    prompt(__abbreviate_subject);
  }
}
