#include<iostream>
#include<omp.h>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}
void floyd(int matrix[10][10], int n)
{
	int distance[10][10];
#pragma omp parallel for
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		distance[i][j] = matrix[i][j];
omp_set_num_threads(2);
#pragma omp parallel for
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
			//cout << "\nk=" << k << "in thread " << omp_get_num_threads();

		}
	}
	cout << "The distance matrix is\n";
#pragma omp parallel for
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << distance[i][j] << "  ";
		cout << endl;

	}
}
int main()
{
	int n,  cost[10][10];
	cout << "Enter the number of nodes\n";
	cin >> n;
	cout << "Enter the costs\n";
	for (int j = 0; j < n; j++)
	for (int i = 0; i < n; i++)
	{
		cin >> cost[j][i];

	}
	
	floyd(cost, n);
	cin >> n;
	return -1;
}
