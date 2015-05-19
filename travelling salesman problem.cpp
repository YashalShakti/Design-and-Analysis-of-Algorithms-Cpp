#include<iostream>
using namespace std;
int cities[10], cost[10][10], trip[10], source, min = 999,optimum,trip2[10];

void swap(int a[], int b, int c)
{
	int temp;
	temp = a[b];
	a[b] = a[c];
	a[c] = temp;
}
int approx(int cities[], int n, int i)
{
	int sum=0;
	if (i == n)
	{
		if (cities[1] == source)
		{
			sum = 0;
			for (int j = 1; j <= n - 1; j++)
			{
				sum += cost[cities[j]][cities[j + 1]];
			}
			sum += cost[cities[n]][source];
			if (sum < min)
			{
				min = sum;
				for (int j = 1; j <= n; j++)
					trip[j] = cities[j];

			}

		}
	}
	else
	{
		for (int j = i; j <= n; j++)
		{
			swap(cities, i, j);
			approx(cities, n, i+1);
			swap(cities, j, i);
		}

	}
		return min;
}
int optimal(int source,int n)
{
	int min, p, from,visited[10];
	 from = source;
	 optimum = 0;
	for (int i = 1; i <= n; i++)
		visited[i] = 0;
	visited[source] = 1;
	for (int i = 1; i < n; i++)
	{
		min = 999;
		for (int j = 1; j <= n; j++)
			if (cost[from][j] < min && cost[from][j] != 0 && visited[j] != 1)
			{
				min = cost[from][j];
				p = j;
			}
			visited[p] = 1;
			optimum = optimum + min;
			from = p;
			trip2[i] = p;
		
	}
	trip[0] = source;
	optimum += cost[from][source];
	return optimum;
}



int main()
{
	int n, sum = 0;
	cout << "Enter the number of cities\n";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cities[i] = i;

	}
	cout << "Enter the costs\n";
	for (int j = 1; j <= n; j++)
	for (int i = 1; i <= n; i++)
	{
		cin>>cost[j][i];

	}
	cout << "Enter the source city\n";
	cin >> source;
	cout << "The solution via approximate method is: "<<approx(cities,n,1)<<"\n";
	for (int i = 1; i <= n; i++)
		cout << trip[i] << "> ";
	cout << "\nThe optimal solution is: " << optimal(source,n) << "\n";
	for (int i = 0; i < n; i++)
		cout << trip2[i] << "> ";
	
	cin >> n;
	return -1;
}