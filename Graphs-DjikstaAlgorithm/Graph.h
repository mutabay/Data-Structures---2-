//
// Created by tyyp- on 3.06.2020.
//

#ifndef GRAPHS_DJIKSTAALGORITHM_GRAPH_H
#define GRAPHS_DJIKSTAALGORITHM_GRAPH_H

#include "General.h"

#define VERTEX_COUNT 7

#define INF             INT_MAX
#define INVALID_VERTEX  -1
#define V1        0
#define V2        1
#define V3        2
#define V4        3
#define V5        4
#define V6        5
#define V7        6

#define KNOWN   TRUE
#define UNKNOWN FALSE


typedef struct _Graph{
    int ** AdjMatrix;
    BOOL * KnownVertices;
    int * Distances;
    int * PrevVertices;
}Graph;


Graph * InitializeGraphStruct(int MatrixModel[VERTEX_COUNT][VERTEX_COUNT]);
int FindSmallestUnknownVertex(Graph *graph);
Graph * DijkstraShortestPath(int startVertex,Graph * graph);
Graph * PrimAlgorithm(int startVertex,Graph * graph);
void PrintMinDistances(int start_vertex, int * Distances);
void PrintPreviousVertex(int * PrevVertex);
void PrintPath(int vertex,int * PrevVertex);



void PrintMatrix(int ** AdjMatrix);


#endif //GRAPHS_DJIKSTAALGORITHM_GRAPH_H
