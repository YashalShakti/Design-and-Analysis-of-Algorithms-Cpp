#include<iostream>
#include<stdio.h>
using namespace std;

void dfs(int a[10][10], int source, int n, int visited[10])
{
	visited[source] = 1;
	for (int v = 1; v <= n; v++)
	{
		if (a[source][v] == 1 && visited[v] == 0)
			dfs(a, v, n, visited);

	}
}
int main()
{
	int n, visited[10], a[10][10], source;
	cout << "Enter the number of verticse\n";
	cin >> n;
	cout << "Enter the adjancency matrix\n";
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		cin >> a[i][j];
	cout << "Enter the source\n";
	cin >> source;
	for (int i = 1; i <= n; i++)
		visited[i] = 0;
	dfs(a, source, n, visited);
	for (int i = 1; i <= n;i++)
	if (visited[i] == 0)
	{
		cout << "The graph is not connected\n";
		cin >> n;
		exit(0);
	}
	cout << "The graph is connected\n";
	cin >> n;
	return -1;
}