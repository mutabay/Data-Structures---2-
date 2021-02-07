//
// Created by Mutabay on 4/16/2020.
//

#ifndef CEN_204_01_MUSTAFA_TAYYIP_BAYRAM_SLL_H
#define CEN_204_01_MUSTAFA_TAYYIP_BAYRAM_SLL_H

#include "General.h"

typedef struct SingleLinkedList{
    DATA_TYPE data;
    struct SingleLinkedList * pNext;
}SLL;

SLL * CreateSingleLinkedListNode(DATA_TYPE toCreate);
void DestroySingleLinkedListNode(SLL * pTemp);
void PrintSingleLinkedList(SLL * pHead );

#endif //CEN_204_01_MUSTAFA_TAYYIP_BAYRAM_SLL_H
