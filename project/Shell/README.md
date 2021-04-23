# Shell

## directory.h

- Direc is a node 
- PtrToDirec is a pointer to node

```
root
    | 
    |-name
    |-path
    |
    |-subdirecs -> dir1 -> dir2      ->        dir3   -> NULL
    |               |                            |
    |               |-subdirecs->NULL            |->subdirecs
    |               |                            |
    |               |->subfiles->file4->file9    |->subfies
    |               |
    |
    |- subfiles -> file1 -> file2 ->NULL
    |               |                            
    |               |-subdirecs->NULL           
    |               |                            
    |               |->subfiles->NULL
    |               
    |               
    |-Next

```