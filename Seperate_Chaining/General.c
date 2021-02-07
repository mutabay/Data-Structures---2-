#include"General.h"
void* AllocateMemory(size_t size, BOOL bExit)
{
    void * pvMem;
    pvMem = malloc(size);
    if (NULL == pvMem )
    {
        printf("Memory Cannot Allocated");
        if ( TRUE == bExit)
            exit(1);
    }

    return pvMem;
}

