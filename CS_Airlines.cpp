//CS Airlines 
//Jesse Chairez
#include <iostream>
#include <limits.h>
#include <stdio.h>
using namespace std;
#define V 6

int min_Distance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_Index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_Index = v;

    return min_Index;
}

void print_Solution(int dist[])
{
    printf("CS Airlines\nVertex----Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}


void dijkstra(int graph[V][V], int src)
{
    int dist[V]; 
    bool sptSet[V]; 
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;


    for (int count = 0; count < V - 1; count++)
    {
        int u = min_Distance(dist, sptSet);
        
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    print_Solution(dist);
}

int main()
{
    
    int graph[V][V] = {{0, 120, 150, 0, 0, 500},
                       {120, 0, 0, 75, 0, 350},
                       {150, 0, 0, 0, 250, 0},
                       {0, 75, 0, 0, 150, 0},
                       {0, 0, 250, 150, 0, 0},
                       {500, 350, 0, 0, 0, 0}};

    dijkstra(graph, 0);

    return 0;
}
/*
CS Airlines
Vertex----Distance from Source
0        0
1        120
2        150
3        195
4        345
5        470
*/