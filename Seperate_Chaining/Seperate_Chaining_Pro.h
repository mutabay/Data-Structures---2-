#ifndef SEPERATE_CHAINING_PRO_H_INCLUDED
#define SEPERATE_CHAINING_PRO_H_INCLUDED

#define DATA_SIZE 11

#include"General.h"
#include"SingleLinkedList.h"

typedef struct _HashTable
{
    SLLI ** pTable;
    int tableSize;
    int itemCount;
}HashTable;

void PrintHashTablePro(HashTable * pHashTable);
int HashFunctionPro(HashTable * pHashTable,int key);
HashTable * CreateHashTable(int tableSize);
void InsertHashTable(HashTable * pHashTable,int key);




#endif // SEPERATE_CHAINING_PRO_H_INCLUDED
