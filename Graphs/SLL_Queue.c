//SLL_Queue.c File
//Mustafa Tayyip BAYRAM

#include "SLL_Queue.h"

SLL_QUEUE * CreateQueue()
{
    SLL_QUEUE * pQueue = AllocateMemory(sizeof(SLL_QUEUE),EXIT_PROGRAM);
    pQueue->front = NULL;
    pQueue->back = NULL;
    return pQueue;
}
SLL_QUEUE * Enqueue(SLL_QUEUE * pQueue,DATA_TYPE toAdd)
{
    //Preparing Item which will be added
    SLL * pQueueItem = CreateSingleLinkedListNode(toAdd);

    //Queue is empty
    if(!pQueue->back)
    {
        pQueue->back = pQueueItem;
        pQueue->front = pQueueItem;
    }
    else{
        //Adding from the end of the linked list
        pQueue->back->pNext = pQueueItem;
        pQueue->back = pQueue->back->pNext;
    }
    return pQueue;

}

SLL_QUEUE * Dequeue(SLL_QUEUE * pQueue,DATA_TYPE * pDatum)
{
    //Empty Queue
    if(!pQueue->front)
        return NULL;
    //Deleting from the start of the linked list
    SLL * pTemp = pQueue->front;
    pQueue->front = pQueue->front->pNext;

    //Gathering the deleted datum
    * pDatum = pTemp->data;

    DestroySingleLinkedListNode(pTemp);

    //There is not have item so back must be NULL
    if(!pQueue->front)
        pQueue->back = NULL;

    return pQueue;
}

BOOL Peek(SLL_QUEUE * pQueue,DATA_TYPE * datum)
{
    if(!pQueue->front)
        return FALSE;
    *datum = pQueue->front->data;
    return TRUE;
}

BOOL IsEmpty(SLL_QUEUE * pQueue)
{
    return (pQueue->front == NULL);
}

void PrintSLL_Queue(SLL_QUEUE * pQueue)
{
    PrintSingleLinkedList(pQueue->front);
}


