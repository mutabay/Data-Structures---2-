//
// Created by tyyp- on 3.06.2020.
//

#include "Graph.h"



Graph * InitializeGraphStruct(int MatrixModel[VERTEX_COUNT][VERTEX_COUNT])
{
    //Allocate memory for container
    Graph * graph = AllocateMemory(sizeof(Graph),EXIT_PROGRAM);
    //Allocate memory for matrix's first dimension
    graph->AdjMatrix = (int**)AllocateMemory(sizeof(int *) *VERTEX_COUNT,EXIT_PROGRAM);
    int i;//Allocating memory for matrix's second dimension.
    for (i = 0; i < VERTEX_COUNT; ++i){
        graph->AdjMatrix[i] = (int *)AllocateMemory(sizeof(int) * VERTEX_COUNT,EXIT_PROGRAM);
    }
    //Allocating other arrays.
    graph->KnownVertices = AllocateMemory(sizeof(BOOL) * VERTEX_COUNT,EXIT_PROGRAM);
    graph->PrevVertices = AllocateMemory(sizeof(int ) * VERTEX_COUNT, EXIT_PROGRAM);
    graph->Distances = AllocateMemory(sizeof(int ) * VERTEX_COUNT, EXIT_PROGRAM);

    //Transfer Adj Matrix to struct and initialize other arrays.
    int u,v;
    for (u = 0; u < VERTEX_COUNT; ++u) {
        for (v= 0; v < VERTEX_COUNT; ++v)
            graph->AdjMatrix[u][v] = MatrixModel[u][v];

        graph->KnownVertices[u] = UNKNOWN;
        graph->PrevVertices[u] = INVALID_VERTEX;
        graph->Distances[u] = INF;
    }
    return graph;
}

int FindSmallestUnknownVertex(Graph *graph)
{
    int minDistance = INF;
    int minDistance_Vertex =INVALID_VERTEX;

    for (int vertexIndex = 0; vertexIndex < VERTEX_COUNT; ++vertexIndex) {
        if ( UNKNOWN == graph->KnownVertices[vertexIndex] )
        {
            if ( graph->Distances[vertexIndex] < minDistance )
            {
                minDistance = graph->Distances[vertexIndex];
                minDistance_Vertex = vertexIndex;
            }
        }
    }
    return minDistance_Vertex;
    
}

Graph * DijkstraShortestPath(int startVertex,Graph * graph)
{
    // Set start vertex' distance as 0 (min)
    graph->Distances[startVertex] = 0;
    int minDistance_Vertex,distance;
    // Find "min distance vertex" "among unknown ones"
    while (INVALID_VERTEX != (minDistance_Vertex = FindSmallestUnknownVertex(graph)) )
    {
        // Make "KNOWN" selected vertex
        graph->KnownVertices[minDistance_Vertex] = KNOWN;
        // Check selected vertex' neighbors
        for (int vertexIndex = 0; vertexIndex < VERTEX_COUNT; ++vertexIndex)
        {            // Check UNKNOWN neighbors
            // INF != graph->AdjMatrix[minDistance_Vertex][vertexIndex] : means "vertexIndex" is a neighbour of minDistance_Vertex
            if (INF != graph->AdjMatrix[minDistance_Vertex][vertexIndex] && UNKNOWN == graph->KnownVertices[vertexIndex])
            {
                // UNKNOWN neighbor's distance from selected vertex
                distance = graph->AdjMatrix[minDistance_Vertex][vertexIndex];

                // If distance of neighbour can be lowered then set this new distance as the
                // current min distance of it (i.e neighbor's) AKTARMA KONTROLU
                if ( graph->Distances[minDistance_Vertex] + distance < graph->Distances[vertexIndex] )
                {
                    graph->Distances[vertexIndex] = graph->Distances[minDistance_Vertex] + distance;
                    graph->PrevVertices[vertexIndex] = minDistance_Vertex;
                }

            }//IF
        }//FOR
    }//WHILE
    return graph;
}

Graph * PrimAlgorithm(int startVertex,Graph * graph)
{
    // Set start vertex' distance as 0 (min)
    graph->Distances[startVertex] = 0;
    int minDistance_Vertex,distance;
    // Find "min distance vertex" "among unknown ones"
    while (INVALID_VERTEX != (minDistance_Vertex = FindSmallestUnknownVertex(graph)) ) // parametreleri birleştir.
    {
        // Make "KNOWN" selected vertex
        graph->KnownVertices[minDistance_Vertex] = KNOWN;
        // Check selected vertex' neighbors
        for (int vertexIndex = 0; vertexIndex < VERTEX_COUNT; ++vertexIndex)
        {            // Check UNKNOWN neighbors
            // INF != graph->AdjMatrix[minDistance_Vertex][vertexIndex] : means "vertexIndex" is a neighbour of minDistance_Vertex
            if (INF != graph->AdjMatrix[minDistance_Vertex][vertexIndex] && UNKNOWN == graph->KnownVertices[vertexIndex])
            {
                // UNKNOWN neighbor's distance from selected vertex
                distance = graph->AdjMatrix[minDistance_Vertex][vertexIndex];

                // If distance of neighbour can be lowered then set this new distance as the
                // current min distance of it (i.e neighbor's) AKTARMA KONTROLU
                if ( distance < graph->Distances[vertexIndex] )  //!!!!!!!!!!!!!!!!!!!!!DIFFERENCE IS HERE !!!!!!!!!!!!!!!!!!!!!
                {
                    graph->Distances[vertexIndex] =  distance; //!!!!!!!!!!!!!!!!!!!!!DIFFERENCE IS HERE !!!!!!!!!!!!!!!!!!!!!
                    graph->PrevVertices[vertexIndex] = minDistance_Vertex;
                }

            }//IF
        }//FOR
    }//WHILE
    return graph;
}

void PrintMinDistances(int start_vertex, int * Distances)
{
    int i;

    for (i = 0; i < VERTEX_COUNT; ++i)
        printf("V%d's min distance from %d is %d\n", (i + 1), start_vertex, Distances[i] );
}

void PrintPreviousVertex(int * PrevVertex)
{
    int i;

    for (i = 0; i < VERTEX_COUNT; ++i)
        printf("V%d's previous vertx is V%d\n", (i + 1), (PrevVertex[i] + 1) );
}

void PrintPath(int vertex,int * PrevVertex)
{
    if (INVALID_VERTEX != vertex) {
        PrintPath(PrevVertex[vertex],PrevVertex);
        printf("V%d -> ", (vertex + 1));
    }
}

void PrintMatrix(int ** AdjMatrix)
{
    //Matrix Printer On To Screen
    int i,j;
    for(i = 0;i < VERTEX_COUNT;++i)
    {
        for (j = 0; j <VERTEX_COUNT; ++j) {
            printf("%d",AdjMatrix[i][j]);
        }
        printf("\n");
    }
}