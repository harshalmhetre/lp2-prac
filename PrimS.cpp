#include <bits/stdc++.h>
using namespace std;

#define V 5

int minweight(int weight[], bool visited[])
{
	int min = INT_MAX, min_index;
	
	for (int v = 0; v < V; v++)
		if (visited[v] == false && weight[v] < min)
			min = weight[v], min_index = v;
	
	return min_index;
}

void printMST(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"<< graph[i][parent[i]] << " \n";

	int totalWeight = 0;
	for (int i = 1; i < V; i++)
		totalWeight += graph[i][parent[i]];
	cout << "Total weight of MST: " << totalWeight << endl;
}

void primMST(int graph[V][V])
{
	int parent[V];

	int weight[V];

	bool visited[V];

	for (int i = 0; i < V; i++)
		weight[i] = INT_MAX, visited[i] = false;

	weight[0] = 0;

	parent[0] = -1;

	for (int count = 0; count < V - 1; count++)
	{

		int u = minweight(weight, visited);

		visited[u] = true;

		for (int v = 0; v < V; v++)
			if (graph[u][v] && visited[v] == false && graph[u][v] < weight[v])
				parent[v] = u, weight[v] = graph[u][v];

	}

	printMST(parent, graph);
}

int main()
{
	int graph[V][V] = {{0, 2, 0, 6, 0},
					   {2, 0, 3, 8, 5},
					   {0, 3, 0, 0, 7},
					   {6, 8, 0, 0, 9},
					   {0, 5, 7, 9, 0}};

	primMST(graph);

	return 0;
}

// This code is contributed by rathbhupendra
/*output
Edge 	Weight
0 - 1 	2
1 - 2 	3
0 - 3 	6
1 - 4 	5*/
