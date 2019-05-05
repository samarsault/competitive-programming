#include <stdio.h>

#define MAX 10

typedef short BOOL;

typedef struct node {
	int y; // edge (x, y)
	int weight; // edge weight
	struct node *next; // next edge
} node;

typedef struct {
	//
	node *edges[MAX + 1];
	// degree[i] is degree of vertex i
	size_t degree[MAX + 1];
	// no. of vertices
	int nvertices;
	// no. of edges
	int nedges;
	BOOL directed; // directed graph
} graph;


void graph_init(graph *G, BOOL directed)
{
	int i;

	G->nedges = 0;
	G->nvertices = 0;
	G->directed = directed;

	for (i = 1;i <= MAX;i++)
	{
		G->degree[i] = 0;
		G->edges[i] = NULL;
	}
}

int main(void)
{
	// graph G;
}