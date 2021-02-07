#include"Seperate_Chaining_Basic.h"

SLLI * pHashTable[HASH_TABLE_SIZE];

int hashFunction(int tableSize,int key)
{
    return key % tableSize;
}

BOOL hashInsert(int key)
{
    int index = hashFunction(HASH_TABLE_SIZE,key);
    pHashTable[index] = AddItemToFront(pHashTable[index],key);
    return TRUE;
}

void printHashTable()
{
    int i;
    for(i = 0; i < HASH_TABLE_SIZE ;i++)
    {
        printf("HASH TABLE INDEX %d\n",i);
        PrintSinlgeLinkedList(pHashTable[i]);
        printf("\n");
    }
}

BOOL hashFind(int key)
{
    int index = hashFunction(HASH_TABLE_SIZE,key);
    SLLI * pItem = Find(pHashTable[index],key);
    if(NULL == pItem)
        return FALSE;
    else
        return TRUE;
}

