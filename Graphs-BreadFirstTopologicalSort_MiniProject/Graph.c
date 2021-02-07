//Graph.c File
//Mustafa Tayyip BAYRAM
//
#include "Graph.h"

Graph * CreateGraph(int AdjMatrix[VERTEX_COUNT][VERTEX_COUNT])
{
    //Creating Structure
    Graph * graph;
    graph = AllocateMemory(sizeof(graph),EXIT_PROGRAM);
    graph->Vertex = VERTEX_COUNT;
    graph->Adj = (int**)AllocateMemory(sizeof(int *) * graph->Vertex, EXIT_PROGRAM);
    int i;
    for (i = 0; i < graph->Vertex; ++i)
        graph->Adj[i] = (int *)AllocateMemory(sizeof(int) * graph->Vertex, EXIT_PROGRAM);

    //Transfer Adj Matrix to struct
    int u,v;
    for (u = 0; u < graph->Vertex; ++u) {
        for (v= 0; v < graph->Vertex; ++v)
            graph->Adj[u][v] = AdjMatrix[u][v];
    }
    return graph;
}

void PrintMatrix(Graph * graph)
{
    //Matrix Printer On To Screen
    int i,j;
    for(i = 0;i < graph->Vertex; ++i)
    {
        for (j = 0; j < graph->Vertex; ++j) {
            printf("%d",graph->Adj[i][j]);
        }
        printf("\n");
    }
}

int * FindInDegree(Graph * graph)
{
    int * InDegree = AllocateMemory(sizeof(int) * VERTEX_COUNT,EXIT_PROGRAM);
    //Fill up 0 Indegree array-Cleaning
    for (int i = 0; i < graph->Vertex; ++i) {
        InDegree[i] = 0;
    }
    //Fill the indegree array from the adj matrix.
    for (int i = 0; i < graph->Vertex; i++) {
        for (int j = 0; j < graph->Vertex; j++) {
            InDegree[j] += graph->Adj[i][j];
        }
    }
    return InDegree;
}

int * BreadFirstTopologicalSort(Graph * graph)
{
    int * InDegree = FindInDegree(graph);                   //Declare Indegree array and queue struct
    SLL_QUEUE * queue = CreateQueue();

    int i;
    for (i = 0; i < graph->Vertex ; i++) {                  //In this for block I check the Indegrees (We should take 0 ones because in topological
        if(0 == InDegree[i] ) {                             // sort roots are those)and enqueue the 0 ones  queue
            queue = Enqueue(queue,i);
        }
    }
                                                  //Allocating memory for topSort Array-I want to fill the sort on to array and return it.
    int * topSort = AllocateMemory(sizeof(int) * VERTEX_COUNT,EXIT_PROGRAM);
    int j = 0;
    while (!IsEmpty(queue))                                 //If queue will be empty then while loop unnecessary it must be stopped at that point.
    {
        int dequeuedItem;                                //dequeuedItem store the dequeued Numbers
        queue = Dequeue(queue,&dequeuedItem);
        topSort[j++] = dequeuedItem;                            // In this place dequeuedItem assign topsort after that j variable increase 1 value
        for (i = 0; i < graph->Vertex ; i++) {
            if (1 == graph->Adj[dequeuedItem][i] )                  //In this place we should assign 0 where dequeued items' links to they other vertices
            {                                                   //because dequeued item is visited so we should break edge between they others
                graph->Adj[dequeuedItem][i] = 0;
                InDegree[i] = InDegree[i] - 1;                   //Also we should decrease them into the InDegree Array because if their connections to cut off
                if(0 == InDegree[i])                             // their Indegrees must decreased in the same way
                    queue = Enqueue(queue,i);                       // In this row we should enqueue the Indegrees which is 0 for topologic sort.
            }
        }
    }
    return topSort;
}