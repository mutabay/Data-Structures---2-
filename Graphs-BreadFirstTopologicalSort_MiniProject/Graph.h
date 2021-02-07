//Graphs.h File
//Mustafa Tayyip BAYRAM
//

#ifndef CEN_204_01_MUSTAFA_TAYYIP_BAYRAM_GRAPH_H
#define CEN_204_01_MUSTAFA_TAYYIP_BAYRAM_GRAPH_H

#include "General.h"
#include "SLL.h"
#include "Queue_SLL.h"

#define VERTEX_COUNT 10

typedef struct Graph_ {
    int Vertex;
    int ** Adj;
}Graph;

Graph * CreateGraph(int AdjMatrix[VERTEX_COUNT][VERTEX_COUNT]);
void PrintMatrix(Graph * graph);
int * FindInDegree(Graph * graph);
int * BreadFirstTopologicalSort(Graph * graph);



#endif //CEN_204_01_MUSTAFA_TAYYIP_BAYRAM_GRAPH_H
