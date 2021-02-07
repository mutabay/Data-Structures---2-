//
// Created by Mutabay on 4/16/2020.
//
#include "SingleLinkedList.h"

SLL * CreateSingleLinkedListNode(DATA_TYPE toCreate)
{
    SLL * pNode = AllocateMemory(sizeof(SLL),EXIT_PROGRAM);
    pNode->data = toCreate;
    pNode->pNext = NULL;
    return pNode;
}

void DestroySingleLinkedListNode(SLL * pTemp)
{
    pTemp->pNext = NULL;
    free(pTemp);
}

void PrintSingleLinkedList(SLL * pHead )
{
    while (NULL != pHead)
    {
        printf("Item of SLLIQUEUE->%d\n",pHead->data);
        pHead = pHead->pNext;
    }
}