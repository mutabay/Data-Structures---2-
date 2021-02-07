#include"General.h"

void * AllocateMemory(int size , BOOL bExit)
{
    void * pvMem ;
    pvMem = malloc(size);
    if(NULL == pvMem)
    {
        printf("Can not allocated memory\n");
        if(TRUE == bExit)
            exit(1);
        else
            return NULL;
    }
    return pvMem;
}
