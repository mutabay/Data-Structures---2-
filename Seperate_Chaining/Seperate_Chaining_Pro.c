#ifndef SEPERATE_CHAINING_PRO_C_INCLUDED
#define SEPERATE_CHAINING_PRO_C_INCLUDED
#include"Seperate_Chaining_Pro.h"

void PrintHashTablePro(HashTable * pHashTable)
{
    int i;
    for (i = 0; i < pHashTable->tableSize ;i++)
    {
        printf("HASH TABLE[%d]\n",i);
        PrintSinlgeLinkedList(pHashTable->pTable[i]);
        printf("----------------------------\n");
    }
}

int HashFunctionPro(HashTable * pHashTable,int key)
{
    return key % pHashTable->tableSize;
}

HashTable * CreateHashTable(int tableSize)
{
    HashTable * pHashTable;
    pHashTable = AllocateMemory(sizeof(HashTable),EXIT_PROGRAM);
    pHashTable->pTable = AllocateMemory(sizeof(SLLI) * tableSize,EXIT_PROGRAM);
    pHashTable->tableSize = tableSize;
    pHashTable->itemCount = 0;

    int i;
    for(i = 0; i < pHashTable->tableSize; ++i)
        pHashTable->pTable[i] = NULL;

    return pHashTable;
}

void InsertHashTable(HashTable * pHashTable,int key)
{
    int index = HashFunctionPro(pHashTable,key);
    pHashTable->pTable[index] = AddItemToFront(pHashTable->pTable[index],key);
    pHashTable->itemCount++;
}

void DestroyHashTable(HashTable * pHashTable)
{
    int i;
    for (i = 0; i < pHashTable->tableSize ; ++i)
        DestroySLLRecursive(pHashTable->pTable[i]);
    free(pHashTable->pTable);
    free(pHashTable);
}

#endif // SEPERATE_CHAINING_PRO_C_INCLUDED
