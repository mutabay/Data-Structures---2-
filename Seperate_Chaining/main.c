#include <stdio.h>
#include <stdlib.h>
#include"General.h"
#include"Seperate_Chaining_Basic.h"
#include"SingleLinkedList.h"
#include"Seperate_Chaining_Pro.h"


int main()
{
    int i;

    /* BASIC ONE
    for (i = 0; i < HASH_TABLE_SIZE;i++)
    {
        if(TRUE == hashInsert(i + 1))
            printf("++++++++++%d inserted^^^^^^^+++++++\n",i + 1);
        else
            printf("++++++++++%d NOT inserted^^^^^^^+++++++\n",i + 1);
    }
    printf("---------------------------------\n");
    printHashTable();
    printf("---------------------------------");
    if(TRUE == hashFind(10))
            printf("++++++++++%d find^^^^^^^+++++++\n",10);
        else
            printf("++++++++++%d NOT found^^^^^^^+++++++\n",10);
    */

    //FOR PRO
    int data[] = { 44, 666, 27, 102, 58, 90, 30, 63, 24, 11, 2 };
    int toFind;

    HashTable * pHashtable = CreateHashTable(HASH_TABLE_SIZE);
    for(i = 0; i < pHashtable->tableSize ;++i )
        InsertHashTable(pHashtable,data[i]);
    PrintHashTablePro(pHashtable);



    return 0;
}
