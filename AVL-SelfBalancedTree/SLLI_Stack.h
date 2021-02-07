#ifndef SLLI_STACK_H_INCLUDED
#define SLLI_STACK_H_INCLUDED
#include"General.h"


typedef struct SingleLinkedList
{
    DATA_TYPE data;
    struct SingleLinkedList * next;
}SLLI;

SLLI * CreateSLLI (DATA_TYPE toCreate);
void DestroySLLI(SLLI * pTemp);

SLLI * Push(SLLI * pHead, DATA_TYPE toAdd);
SLLI * Pop(SLLI * pHead,DATA_TYPE * datum);
BOOL Peek(SLLI * pHead,DATA_TYPE * datum);


void printSLLI(SLLI * pHead);

#endif // SLLI_STACK_H_INCLUDED
