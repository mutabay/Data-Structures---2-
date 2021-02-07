#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define TRUE 1
#define FALSE 0
#define EXIT_PROGRAM TRUE

typedef int BOOL;
typedef int DATA_TYPE;

void * AllocateMemory(int size , BOOL bExit);


#endif // GENERAL_H_INCLUDED
