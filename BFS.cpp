#include<stdio.h>
#include<iostream>
#include<time.h>

using namespace std;

void bfs(int a[10][10], int source, int length, int visited[10])
{
	int front, rear, u, v, q[20];
	front = 0;
	rear = -1;
	q[++rear] = source;
	while (front <= rear)
	{
		u = q[front++];
		for (int v = 1; v <= length; v++)
		{
			if (a[u][v] == 1 && visited[v] == 0)
			{
				q[++rear] = v;
				visited[v] = 1;

			}
		}
	}
	for (int i = 1; i <= length; i++)
	if (visited[i] == 1)
		cout << "The node " << i << "is reachable\n";
	else
		cout << "The node " << i << "is not reachable\n";
		
}
int mainBFS()
{
	int n, a[10][10], source,visted[10];
	cout << "Enter the number of verticse\n";
	cin >> n;
	cout << "Enter the adjancency matrix\n";
	for (int i = 1; i <= n;i++)
	for (int j = 1; j <= n; j++)
		cin >> a[i][j];
	cout << "Enter the source\n";
	cin >> source;
	for (int i = 1; i <= n; i++)
		visted[i] = 0;
	visted[source] = 1;
	bfs(a, source, n, visted);
	cin >> n;
	

	return -1;
}
	



