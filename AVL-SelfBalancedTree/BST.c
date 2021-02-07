#include"BST.h"

BST * CreateBST(DATA_TYPE data)
{
  BST * pRoot;
  pRoot = AllocateMemory(sizeof(BST),EXIT_PROGRAM);
  pRoot->data = data;
  pRoot->right = NULL;
  pRoot->left = NULL;
  return pRoot;
}

BST * SingleLeftRotation(BST * vertex)
{
    BST * z = vertex;
    BST * y = z->left;
    BST * C = y->right;

    y->right = z;
    z->left = C;
    return y;
}

BST * SingleRightRotation(BST * vertex)
{
    BST * x = vertex;
    BST * y = x->right;
    BST * B = y->left;

    y->left = x;
    x->right = B;
    return y;
}
BST * DoubleLeftRightRotation(BST * vertex)
{
    BST * z = vertex;
    BST * x = z->left;
    z->left = SingleRightRotation(x);
    return SingleLeftRotation(z);

}
BST * DoubleRightLeftRotation(BST * vertex)
{
    BST * x =vertex;
    BST * z = x->right;

    x->right = SingleLeftRotation(z);
    return SingleRightRotation(x);
}

BST * Add_AVLTree(BST * vertex ,DATA_TYPE toAdd)
{
    if (NULL == vertex)
    {
        return CreateBST(toAdd);
    }

    if (vertex->data < toAdd)
        vertex->right = Add_AVLTree(vertex->right,toAdd);
    else if (vertex->data>= toAdd)
        vertex->left = Add_AVLTree(vertex->left,toAdd);
    if(abs(Height(vertex->left) - Height(vertex->right)) > 1 )
    {
        if(toAdd < vertex->data)//LEFT-
        {
            if(toAdd < vertex->left->data)//LEFT-LEFT
                vertex = SingleLeftRotation(vertex);

            else //LEFT-RIGHT
                vertex = DoubleLeftRightRotation(vertex);
        }
        else //RIGHT
        {
            if(toAdd > vertex->right->data) //RIGHT-RIGHT
                vertex = SingleRightRotation(vertex);
            else //RIGHT-LEFT
                vertex = DoubleRightLeftRotation(vertex);
        }
    }
    return vertex;
}

void PrintBST(BST * vertex)
{
    if (NULL == vertex)
        return;
    printf("%d\n",vertex->data);
    PrintBST(vertex->left);
    PrintBST(vertex->right);
}


BOOL Search (BST * vertex, DATA_TYPE toFind)
{
    if(NULL == vertex)
        return FALSE;
    if (toFind == vertex->data)
        return TRUE;

    //DATA IS GREATER THAN ROOT'S DATA
    else if (vertex->data > toFind)
        return Search(vertex->left,toFind);

    //DATA IS LESS THAN ROOT'S DATA,
    else
        return Search(vertex->right,toFind);

}

BOOL SearchIter (BST * vertex , DATA_TYPE toFind)
{
    while (NULL != vertex)
    {
        if (toFind == vertex->data)
            return TRUE;
        else if (toFind <= vertex->data)
            vertex = vertex->left;
        else
            vertex = vertex->right;
    }
    return FALSE;
}

DATA_TYPE FindMin(BST * vertex)
{
    while ( NULL != vertex->left)
    {
        vertex = vertex->left;
    }
    return vertex->data;
}

DATA_TYPE FindMax(BST * vertex)
{
    while ( NULL != vertex->right)
    {
        vertex = vertex->right;
    }
    return vertex->data;
}


int Height1 (BST * vertex)
{
    if (NULL == vertex)
        return -1 ;
    //COMPUTE THE HEIGHT OF EACH SUBTREE
    int lHeight = Height1(vertex->left);
    int rHeight = Height1(vertex->right);

    if (lHeight < rHeight)
        return rHeight + 1;
    else
        return lHeight + 1;
}

int Height (BST * vertex)
{
    if (NULL == vertex)
        return -1;
    return ( 1 + MAX(Height(vertex->left),Height( vertex->right)));

}

int Depth (BST * vertex , DATA_TYPE toFind)
{
    int counter = 0;
    while (vertex != NULL)
    {
        if (toFind == vertex->data)
            return counter;
        else if (toFind > vertex->data)
        {
            vertex = vertex->right;
            counter++;
        }
        else if (toFind < vertex->data)
        {
            vertex = vertex->left;
            counter++;
        }
    }

    return -1;
}

void printLevelOrder(BST * vertex)
{
    int height = Height(vertex);
    int i;
    for (i = 0 ; i < height ; i++)
    {
        printGivenLevel(vertex,i);
        printf("\n");
    }

}

void printGivenLevel(BST * vertex,int level)
{
    if (NULL == vertex)
        return;
    if (level == 1)
        printf("%d",vertex->data);
    else if (level > 1)
    {
        printGivenLevel(vertex->left,level - 1);
        printGivenLevel(vertex->right, level - 1);
    }
}














































