#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


#define FALSE 0
#define TRUE 1

#define EXIT_PROGRAM 1

typedef int BOOL;

void* AllocateMemory(size_t size, BOOL bExit);

#endif // GENERAL_H_INCLUDED
