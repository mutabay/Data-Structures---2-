#include"SingleLinkedList.h"


SLLI * AddItemToEnd(SLLI* pHead, int toAdd)
{
    //PREPARE NEW SSLI ITEM

    SLLI * pNewItem = AllocateMemory(sizeof(SLLI) , TRUE);
    pNewItem ->data = toAdd;
    pNewItem ->pNext = NULL;

    if (NULL == pHead)
        return pNewItem;
    else
    {
        SLLI * pTemp = pHead;
        while (NULL != pTemp->pNext)
            pTemp = pTemp->pNext;

        pTemp->pNext = pNewItem;
        return pHead;
    }
}

SLLI * AddItemToFront(SLLI * pHead,int toAdd)
{
    SLLI * pItem = AllocateMemory(sizeof(SLLI),EXIT_PROGRAM);
    pItem->data = toAdd;
    pItem->pNext = pHead;

    return pItem;
}

void PrintSinlgeLinkedList( SLLI * pHead )
{
    while(NULL != pHead)
    {
        printf("Item ->>>> %d\n",pHead->data);
        pHead = pHead->pNext;
    }
}


void PrintList_recursive(SLLI* pHead)
{
    if (NULL == pHead)
        return ;
    printf("Item data : %d\n", pHead->data);
    PrintList_recursive(pHead->pNext);
}

void PrintListReverse_recursive(SLLI* pHead)
{
    if ( NULL == pHead)
        return;

    PrintListReverse_recursive(pHead->pNext);
    printf("Item data : %d\n", pHead->data);
}


SLLI * Find(SLLI * pHead, int toFind)
{

    while ( NULL != pHead)
    {
        if (pHead->data == toFind)
            return pHead;

        pHead = pHead->pNext;
    }

    return NULL;
}

SLLI * DeleteItem( SLLI * pHead, int toDel)
{
    SLLI * pCur = pHead;
    SLLI * prev = NULL;
    //FÝND
    while ( NULL != pHead && pCur->data != toDel)
    {
        prev = pCur;
        pCur = pCur->pNext;
    }
    if ( NULL != pCur)
    {
        //CASE 1 - REMOVE FÝRST ITEM
        if (NULL == prev)
            pHead = pCur->pNext;
        //CASE 2 - REMOVE ANY OTHER ITEM
        else
            prev->pNext = pCur->pNext;

        pCur->pNext = NULL;
        free(pCur);
     }
     return pHead;
}

SLLI* DeleteItem_recursive(SLLI* pHead, int toDel)
{
    if (NULL != pHead)
    {
        if ( toDel != pHead->data)
            pHead->pNext = DeleteItem_recursive(pHead->pNext,toDel);

        //FOUND
        else
        {
            SLLI * toReturn = pHead->pNext;
            pHead->pNext = NULL;
            free(pHead);
            return toReturn;
        }
    }

    return pHead;
}

void DestroySLLRecursive(SLLI * pHead)
{
    if(NULL != pHead )
    {
        DestroySLLRecursive(pHead->pNext);
        pHead->pNext = NULL;
        free(pHead);
    }
}
