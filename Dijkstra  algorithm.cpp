#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<iostream>
using namespace std;
int dist[20], visited[20], weight[20][20], parent[20], n, source;
int findmin()
{
	int i, min;
	for (i = 1; i <= n; i++)
	if (visited[i] == 0)
	{
		min = i;
		break;
	}
	for (i = 1; i <= n; i++)
	{
		if (dist[i]<dist[min] && visited[i] == 0)
			min = i;
	}
	return min;
}
void dijikstra()
{
	int i, currentVertex, minNeighbor, k, j;
	for (i = 1; i <= n; i++)
	{
		visited[i] = 0;
		dist[i] = 999;
		parent[i] = 0;
	}
	dist[source] = 0;
	for (k = 1; k <= n; k++)
	{
		minNeighbor = findmin();
		visited[minNeighbor] = 1;
		for (currentVertex = 1; currentVertex <= n; currentVertex++)
		{
			if (weight[minNeighbor][currentVertex] != 999 && visited[currentVertex] == 0)
			{
				if (dist[currentVertex]>  dist[minNeighbor] + weight[minNeighbor][currentVertex])
				{
					dist[currentVertex] = dist[minNeighbor] + weight[minNeighbor][currentVertex];
					parent[currentVertex] = minNeighbor;
				}
			}
		}
	}
	printf("shortest path costs\n");
	for (i = 1; i <= n; i++)
	{
		if (dist[i] == 999)
			printf("sorry!  no path for source %d to %d vertex", source, i);
		else
			printf("path cost from %d to %d is %d\n", source, i, dist[i]);
	}
	printf("shortest group of paths are\n");
	for (i = 1; i <= n; i++)
	{
		if (i != source && dist[i] != 999)
		{
			printf("%d", i);
			j = parent[i];
			while (parent[j] != 0)
			{
				printf("-->%d", j);
				j = parent[j];
			}
			printf("-->%d\n", source);
		}
	}
}
void main()
{
	int i, j;
	clock_t end, st;
	printf("enter the number of vertices\n");
	cin >>n;
	printf("enter the cost of vertices\n");
	for (i = 1; i <= n; i++)
	for (j = 1; j <= n; j++)
		cin >> weight[i][j];
	printf("enter the source vertex\n");
	cin >> source;
	st = clock();
	dijikstra();
	end = clock();
	printf("time taken is %d\n", (end - st) / CLK_TCK);
	cin >> source;

}





