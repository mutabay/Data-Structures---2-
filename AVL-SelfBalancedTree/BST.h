#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include"General.h"
#include"SLLI_Stack.h"
#define MAX(a,b)    ((a>b)?a:b)



typedef struct tagBST{
    DATA_TYPE data;
    struct tagBST * left;
    struct tagBST * right;
}BST;

BST * CreateBST(DATA_TYPE data);

BST * SingleLeftRotation(BST * vertex);
BST * SingleRightRotation(BST * vertex);
BST * DoubleLeftRightRotation(BST * vertex);
BST * DoubleRightLeftRotation(BST * vertex);
BST * Add_AVLTree(BST * vertex ,DATA_TYPE toAdd);

void PrintBST(BST * vertex);
BOOL Search (BST * vertex, DATA_TYPE toFind);
BOOL SearchIter (BST * vertex , DATA_TYPE toFind);
DATA_TYPE FindMin(BST * vertex);
DATA_TYPE FindMax(BST * vertex);
int Height1 (BST * vertex);
int Height (BST * vertex);
int Depth (BST * vertex , DATA_TYPE toFind);
void printLevelOrder(BST * vertex);
void printGivenLevel(BST * vertex,int level);



#endif // BST_H_INCLUDED
