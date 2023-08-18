/*
LAB TASK 13
QUESTION: 13a. Write a C program to implement Adjacency Matrix of a given graph.

Test Cases:
case = t1
input = 4
0 1 1 0 1 0 1 1 1 1 0 1 0 1 1 0
output =

ADJACENCY MATRIX OF GRAPH G
VERTEX 0 : 0 1 1 0
VERTEX 1 : 1 0 1 1
VERTEX 2 : 1 1 0 1
VERTEX 3 : 0 1 1 0

*/
// Start writing program from here
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void getgraph();
void printgraph();
int G[MAX][MAX];
int n, i, j;
void main()
{
    scanf("%d", &n);
    int G[n][n];
    getgraph(G);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    printgraph(G);
}

void getgraph(int G[n][n])
{

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            G[i][j] = 0;
        }
    }
}
void printgraph(int G[n][n])
{
    int i, j;
    printf("ADJACENCY MATRIX OF GRAPH G");
    for (i = 0; i < n; i++)
    {
        printf("\nVERTEX %d : ", i);
        for (j = 0; j < n; j++)
        {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}

///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
/*
LAB TASK 13
QUESTION: 13 B- Write a C program to implement Adjacency List of a given graph.
Test Cases:
case = t1
input = 4 5
0 1
0 2
0 3
1 2
2 3
output =
ADJACENCY LIST OF GRAPH G

Vertex 0: 3 -> 2 -> 1 ->
Vertex 1: 2 -> 0 ->
Vertex 2: 3 -> 1 -> 0 ->
Vertex 3: 2 -> 0 ->
*/
// Start writing program from here
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int vertex;
    struct node *next;
};
struct node *createNode(int);
struct Graph
{
    int numVertices;
    struct node **adjLists;
};
struct Graph *createGraph(int);
void addEdge(struct Graph *, int, int);
void printGraph(struct Graph *);

void main()
{

    struct Graph *graph;
    int i, no_of_vertices, no_of_edges, src, dest;

    scanf("%d%d", &no_of_vertices, &no_of_edges);
    graph = createGraph(no_of_vertices);

    for (i = 0; i < no_of_edges; i++)
    {
        scanf("%d%d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printGraph(graph);
}

struct node *createNode(int n)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->vertex = n;
    temp->next = NULL;
    return temp;
}

struct Graph *createGraph(int n)
{
    struct Graph *temp = (struct Graph *)malloc(sizeof(struct Graph));

    temp->numVertices = n;
    temp->adjLists = (struct node **)malloc(n * sizeof(struct node *));

    for (int i = 0; i < n; i++)
        temp->adjLists[i] = 0;

    return temp;
}

void addEdge(struct Graph *graph, int s, int d)
{
    struct node *temp;

    temp = createNode(d);
    temp->next = graph->adjLists[s];
    graph->adjLists[s] = temp;

    temp = createNode(s);
    temp->next = graph->adjLists[d];
    graph->adjLists[d] = temp;
}

void printGraph(struct Graph *graph)
{
    printf("ADJACENCY LIST OF GRAPH G\n");

    for (int i = 0; i < graph->numVertices; i++)
    {
        struct node *temp = graph->adjLists[i];
        printf("\nVertex %d: ", i);
        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
    }
}

