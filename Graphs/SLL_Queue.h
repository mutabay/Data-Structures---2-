//SLL_Queue.h File
//Mustafa Tayyip BAYRAM
//
#ifndef CEN_204_01_MUSTAFA_TAYYIP_BAYRAM_SLL_QUEUE_H
#define CEN_204_01_MUSTAFA_TAYYIP_BAYRAM_SLL_QUEUE_H

#include "General.h"
#include "SingleLinkedList.h"

typedef struct SingleLinkedListQueue{
    SLL * front;
    SLL * back;
}SLL_QUEUE;

SLL_QUEUE * CreateQueue();
SLL_QUEUE * Enqueue(SLL_QUEUE * pQueue,DATA_TYPE toAdd);
SLL_QUEUE * Dequeue();
BOOL Peek(SLL_QUEUE * pQueue,DATA_TYPE * datum);
void PrintSLL_Queue(SLL_QUEUE * pQueue);
BOOL IsEmpty(SLL_QUEUE * pQueue);



#endif //CEN_204_01_MUSTAFA_TAYYIP_BAYRAM_SLL_QUEUE_H
