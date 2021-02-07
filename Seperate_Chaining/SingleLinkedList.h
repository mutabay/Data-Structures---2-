#ifndef SINGLELINKEDLIST_H_INCLUDED
#define SINGLELINKEDLIST_H_INCLUDED
#include"General.h"

typedef struct SingleLinkedListItem
{
    int data;
    struct SingleLinkedListItem * pNext;

}SLLI;



SLLI* AddItemToEnd(SLLI* pHead, int toAdd);
SLLI * AddItemToFront(SLLI * pHead,int toAdd);


void PrintSinlgeLinkedList( SLLI * pHead );


SLLI * Find(SLLI * pHead, int toFind);

SLLI * DeleteItem( SLLI * pHead, int toDel);
SLLI* DeleteItem_recursive(SLLI* pHead, int toDel);

void PrintList_recursive(SLLI* pHead);
void PrintListReverse_recursive(SLLI* pHead);

void DestroySLLRecursive(SLLI * pHead);











#endif // SINGLELINKEDLIST_H_INCLUDED
