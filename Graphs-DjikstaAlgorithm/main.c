#include <stdio.h>
#include "Graph.h"


int main() {
    /// IN MARK ALLEN WEISS'S BOOK DIJKSTRA ALGORITHM USES WITH DIGRAPHS AND PRIM'S ALGORITHM USES IN DIRECTED GRAPHS
    int matrixModel[VERTEX_COUNT][VERTEX_COUNT] = {
                //   v1    v2   v3   v4   v5    v6   v7
            /*v1*/ { INF,   2,   4,   1,   INF,  INF, INF  },
            /*v2*/ { 2,   INF, INF,   3,   10,   INF, INF  },
            /*v3*/ { 4,     INF, INF, 2,   INF,   5,  INF  },
            /*v4*/ { 1,     3,   2,   INF,   7,   8,   4  },
            /*v5*/ { INF,   10, INF,  7,   INF,  INF,  6  },
            /*v6*/ { INF,   INF, 5,   8,   INF,  INF,  1  },
            /*v7*/ { INF,   INF, INF, 4,    6,    1,  INF  },

    };

    Graph * graph = InitializeGraphStruct(matrixModel);
    /*
    graph = DijkstraShortestPath(V1,graph);
    PrintMinDistances(V1, graph->Distances);
    printf("-----------------\n");
    PrintPreviousVertex(graph->PrevVertices);

    printf("-----------------\n");
    printf("PATHS\n");
    for (int i = 0; i < VERTEX_COUNT; ++i) {
        printf("PATH to reach V%d is ", (i + 1));
        PrintPath(i,graph->PrevVertices);
        printf(" %d (min. cost) \n",graph->Distances[i]);
    }
*/
    printf("PRIM ALGORITHM\n");
    graph = PrimAlgorithm(V1,graph);
    PrintMinDistances(V1, graph->Distances);
    printf("-----------------\n");
    PrintPreviousVertex(graph->PrevVertices);

    printf("-----------------\n");
    printf("PATHS\n");
    for (int i = 0; i < VERTEX_COUNT; ++i) {
        printf("PATH to reach V%d is ", (i + 1));
        PrintPath(i,graph->PrevVertices);
        printf(" %d (min. cost) \n",graph->Distances[i]);
    }

    return 0;
}
