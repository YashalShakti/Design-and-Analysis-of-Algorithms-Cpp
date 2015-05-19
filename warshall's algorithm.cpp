#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<iostream>
#include<process.h>

using namespace std;
int n, i, j, k, a[50][50], p[50][50];
void warshall(int n, int a[50][50], int p[50][50])
{
	for (i = 1; i <= n; i++)
	for (j = 1; j <= n; j++)
		p[i][j] = a[i][j];
	for (k = 1; k <= n; k++)
	for (i = 1; i <= n; i++)
	for (j = 1; j <= n; j++)
	if (p[i][k] == 1 && p[k][j] == 1)
		p[i][j] = 1;
}
void input(int n, int a[50][50])
{
	for (i = 1; i <= n; i++)
	for (j = 1; j <= n; j++)
		cin >> a[i][j];
}
void output(int n, int p[50][50])
{
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			printf("%d\t", p[i][j]);
		printf("\n");
	}
}
void main()
{
	int i, j;
	clock_t st, end;
	printf("enter the number of nodes:\n");
	cin >> n;
	printf("enter the adjacency matrix:\n");
	input(n, a);
	st = clock();
	warshall(n, a, p);
	end = clock();
	printf("the transitive closure is:\n");
	output(n, p);
	printf("the time taken by warshall's algorithm is %d sec\n", (end - st) / CLK_TCK);
	cin >> n;
}