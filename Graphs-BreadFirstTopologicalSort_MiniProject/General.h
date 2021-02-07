//General.h File
#ifndef CEN_204_01_MUSTAFA_TAYYIP_BAYRAM_GENERAL_H
#define CEN_204_01_MUSTAFA_TAYYIP_BAYRAM_GENERAL_H

#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

#define TRUE 1
#define FALSE 0
#define EXIT_PROGRAM 1

typedef int BOOL;
typedef int DATA_TYPE;

void * AllocateMemory(size_t size, BOOL exitAllocation);


#endif //CEN_204_01_MUSTAFA_TAYYIP_BAYRAM_GENERAL_H
