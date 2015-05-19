#include<iostream>
using namespace std;

int main()
{
	int n, sum = 0,cost[10][10],source,min,min_sum=0,ne=1,visited[10],a,b;
	cout << "Enter the number of nodes\n";
	cin >> n;
	cout << "Enter the costs\n";
	for (int j = 1; j <= n; j++)
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[j][i];

	}
	for (int j = 1; j <= n; j++)
		visited[j] = 0;
	cout << "Enter the source\n";
	cin >>source;
	visited[source] = 1;
	while (ne < n)
	{
		min = 999;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (cost[i][j] < min)
					if (visited[i] == 0)
						continue;
					else
					{
						min = cost[i][j];
						a = i;
						b = j;
					}
				
			}
		}
		if (visited[a] == 0 || visited[b] == 0)
		{
			min_sum += min;
			cout << "Edge :" << ne++ << " (" << a << "," << b << ")" << " Cost : " << min<<endl;
			visited[b] = 1;
		}
		cost[a][b] = cost[b][a] = 999;
		
	}


	cout << "Min cost: " << min_sum;

	cin >> n;
	return -1;
}