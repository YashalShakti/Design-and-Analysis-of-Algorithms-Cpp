#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<process.h>

using namespace std;

int indeg[10], flag[10], n, a[10][10];
void topology();
void main5()
{
	int i, j;
	printf("enter the number of vertices:");
	cin >> n;
	printf("enter the adjacency matrix:");
	for (i = 1; i <= n; i++)
	for (j = 1; j <=n; j++)
		cin >> a[i][j];
	printf("\nthe topolgical ordering of the vertices is:");
	topology();
	cin >> n;
}
void topology()
{
	int i, j, cnt = 0, m = 0;
	for (i = 1; i <= n; i++)
	for (j = 1; j<=n; j++)
		indeg[i] += a[j][i];
	while (cnt<n)
	{
		m++;
		if (m == n)
		{
			printf("\ntopological ordering is not possible");
			printf("\nthe given graphic is cyclic");
			cin >> m;
			exit(0);
		}
		for (i = 1; i<=n; i++)
		{
			if (indeg[i] == 0 && flag[i] == 0)
			{
				printf("\n-->>%d %d", i,m);
				cnt++;
				flag[i] = 1;
				for (j = 1; j <= n; j++)
				{
					printf("\n%d %d %d", i, j,indeg[j]);
					if (a[i][j] == 1)
						indeg[j]--;
				}
			}
		}
	}
}

