#include"SLLI_Stack.h"

SLLI * CreateSLLI (DATA_TYPE toCreate)
{
    SLLI * pItem;
    pItem = AllocateMemory(sizeof(SLLI),EXIT_PROGRAM);
    pItem->next = NULL;
    pItem->data = toCreate;

    return pItem;
}

void DestroySLLI(SLLI * pTemp)
{
    pTemp->next = NULL;
    free(pTemp);
}

SLLI * Push(SLLI * pHead, DATA_TYPE toAdd)
{
    if (NULL == pHead)
        return CreateSLLI(toAdd);

    SLLI * pTemp = CreateSLLI(toAdd);
    pTemp->next = pHead;
    pHead = pTemp;
    return pHead;
}

SLLI * Pop(SLLI * pHead,DATA_TYPE * datum)
{
    if (NULL == pHead)
        printf("Stack is empty\n");

    SLLI * pTemp = pHead;
    * datum = pHead->data;
    pHead = pHead->next;
    DestroySLLI(pTemp);
    return pHead;
}

BOOL Peek(SLLI * pHead,DATA_TYPE * datum)
{
    if(NULL == pHead)
        return FALSE;
    *datum = pHead->data;
    return TRUE;
}


void printSLLI(SLLI * pHead)
{
    if (NULL == pHead)
        return;

    printf("SLLI ITEM ->%d\n",pHead->data);
    printSLLI(pHead->next);

}


