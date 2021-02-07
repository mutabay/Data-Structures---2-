#include"General.h"
#include"BST.h"
#include"SLLI_Stack.h"

int main()
{
    BST * vertex = NULL;
    vertex = Add_AVLTree(vertex,6);
    vertex = Add_AVLTree(vertex,2);
    vertex = Add_AVLTree(vertex,4);
    PrintBST(vertex);
    return 0;
}
