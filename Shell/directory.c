#include "directory.h"

// void InitializePath()
// {
//     strcpy(PATH_OF_CURRENT_DIRECTORY, "../user");
// }

// void Print_current_directory_path()
// {
//     int i = 3;
//     while (PATH_OF_CURRENT_DIRECTORY[i] != '\0')
//     {
//         printf("%c", PATH_OF_CURRENT_DIRECTORY[i++]);
//     }
// }

PtrToDirec NewDirec()
{
    PtrToDirec new_direc = (PtrToDirec)malloc(sizeof(Direc));
    return new_direc;
}


PtrToDirec InitializeDirec()
{
    DIR *dir = opendir("../");
    struct dirent* curr_dir = readdir(dir);
    PtrToDirec DirecTree = NewDirec();
    strcpy(DirecTree.Name,curr_dir->d_name);
    
    
    
    close(dir);
}
