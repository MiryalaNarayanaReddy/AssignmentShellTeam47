#include <stdio.h>
#include "directory.h"
#include "user.h"

int main()
{
    printf("The password you are entering is temporary.\n");
    printf("Use it to exit from the program\n");
    printf("Enter Password : ");
    scanf("%s", password);

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