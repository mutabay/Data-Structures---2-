#ifndef SEPERATE_CHAINING_BASIC_H_INCLUDED
#define SEPERATE_CHAINING_BASIC_H_INCLUDED

#include"General.h"
#include"SingleLinkedList.h"

#define HASH_TABLE_SIZE 11

int hashFunction(int tableSize,int key);
BOOL hashInsert(int key);
void printHashTable();
BOOL hashFind(int key);


#endif // SEPERATE_CHAINING_BASIC_H_INCLUDED
