//Graphs.h File
//Mustafa Tayyip BAYRAM
//

#ifndef CEN_204_01_MUSTAFA_TAYYIP_BAYRAM_GRAPHS_H
#define CEN_204_01_MUSTAFA_TAYYIP_BAYRAM_GRAPHS_H

#include "General.h"
#include "SingleLinkedList.h"
#include "SLL_Queue.h"

#define VERTEX_COUNT 10

typedef struct Graph_ {
    int vertex;
    int ** Adj;
}Graph;

Graph * CreateGraph(int AdjMatrix[VERTEX_COUNT][VERTEX_COUNT]);
void AddEdge(Graph * graph,int from,int to);
void PrintMatrix(Graph * graph);
int * FindInDegree(Graph * graph);
int * BreadFirstTopologicalSort(Graph * graph);



#endif //CEN_204_01_MUSTAFA_TAYYIP_BAYRAM_GRAPHS_H
