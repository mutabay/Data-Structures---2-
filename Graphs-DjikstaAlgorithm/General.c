//
// Created by tyyp- on 3.06.2020.
//

#include "General.h"

void * AllocateMemory(size_t size, BOOL exitAllocation) {
    void *pMem = malloc(size);
    if (!pMem)
    {
        printf("Memory Can not Allocated\n");
        if (exitAllocation)
            exit(TRUE);
    }
    return pMem;
}