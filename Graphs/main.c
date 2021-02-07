//main.c File
//Mustafa Tayyip BAYRAM
#include <stdio.h>
#include "General.h"
#include "SingleLinkedList.h"
#include "SLL_Queue.h"
#include "Graphs.h"


int main() {

    int AdjMatrix[VERTEX_COUNT][VERTEX_COUNT] = { //Creating Adj Matrix
            {0,1,0,0,0,1,0,0,0,0},
            {0,0,0,0,0,0,0,1,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,1,0,1,0,0,1,1,0},
            {0,0,0,0,0,0,0,0,1,0},
            {0,0,0,0,0,0,0,0,0,0},
            {1,1,1,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,1,0,0,0,0,1,0,0},
            {0,0,0,0,1,0,0,0,0,0}
    };

    Graph * graph;
    graph = CreateGraph(AdjMatrix);//Declare Graph Struct

    PrintMatrix(graph);


    printf("ADJ Matrix\n");
    PrintMatrix(graph); //Printing ADJ Matrix
    printf("\n----------------------------------\n");

    int * inDegree = FindInDegree(graph); //Declare İnDegree Array
    printf("Indegreees -> ");
    for (int i = 0; i < VERTEX_COUNT; ++i) {
        printf("%d " ,inDegree[i]);
    }
    printf("-----------------\n");
    printf("-----------------\n");

    int * topSort = BreadFirstTopologicalSort(graph);//Declare topological sort array
    printf("\nVertices after topological sorting are:\n");
    int i;
    for (i = 0; i < VERTEX_COUNT ; i++) {
        printf("%d -",topSort[i]);
    }
    return 0;
}
