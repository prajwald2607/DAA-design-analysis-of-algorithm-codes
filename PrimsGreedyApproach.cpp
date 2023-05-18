#include <iostream>
#include <climits>
#define vertices 5
using namespace std;
int minimumkeyMST(int k[vertices], int mst[vertices])
{
	int minimum = INT_MAX, min, i;
	for (i = 0; i < vertices; i++)
	{
		if (mst[i] == 0 && k[i] < minimum)
		{
			minimum = k[i];
			min = i;
		}
	}
	return min;
}
void prims(int g[vertices][vertices])
{
	int parent[vertices];
	int k[vertices];
	int mst[vertices];
	int i, j, count, totalCost = 0, edge, v;
	for (i = 0; i < vertices; i++)
	{
		k[i] = INT_MAX;
		mst[i] = 0;
	}
	k[0] = 0;
	parent[0] = -1;

	for (count = 0; count < vertices - 1; count++)
	{
		edge = minimumkeyMST(k, mst);
		mst[edge] = 1;

		for (v = 0; v < vertices; v++)
		{
			if (g[edge][v] && mst[v] == 0 && g[edge][v] < k[v])
			{
				parent[v] = edge;
				k[v] = g[edge][v];
			}
		}
	}
	cout << "\nEdges \t Weight: " << endl;
	for (i = 1; i < vertices; i++)
	{
		totalCost += g[i][parent[i]];
		cout << parent[i] << "--->" << i << "\t " << g[i][parent[i]] << endl;
	}
	cout << "\nThe Total Minimum Cost in the given Graph is: " << totalCost << endl;
}
int main()
{
	int i, j, v;
	int g[vertices][vertices];
	cout << "Enter the number of vertices: " << endl;
	cin >> v;
	cout << "Enter cost values in the Adjaceny Matrix: " << endl;
	for (i = 0; i < vertices; i++)
	{
		for (j = 0; j < vertices; j++)
		{
			cin >> g[i][j];
		}
	}
	cout << endl;
	prims(g);
	return 0;
}
