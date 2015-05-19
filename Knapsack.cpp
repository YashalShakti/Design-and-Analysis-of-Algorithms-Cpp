#include<iostream>
#include<conio.h>

using namespace std;
int weights[10], table[10][10], value[10], solVector[10];
int max(int a, int b)
{
	return(a>b) ? a : b;
}
int knap(int i, int j)
{
	if (i == 0 || j == 0)
		table[i][j] = 0;
	else if (j<weights[i])
		table[i][j] = knap(i - 1, j);
	else
		table[i][j] = max(knap(i - 1, j), value[i] + knap(i - 1, j - weights[i]));
	return table[i][j];
}
void optimal(int i, int j)
{
	if (i >= 1 || j >= 1)
	if (table[i][j] != table[i - 1][j])
	{
		cout << "item: " << i << endl;
		solVector[i] = 1;
		j = j - weights[i];
		optimal(i - 1, j);
	}
	else
		optimal(i - 1, j);
}
void main2()
{
	int profit, w1, n, i, j;
	cout << "Enter the number of items available to put in the Knapsack:";
	cin >> n;
	cout << "Enter the capacity of the knapsack:";
	cin >> w1;
	cout << "\nEnter the values:";
	for (i = 1; i <= n; i++)
		cin >> value[i];
	cout << "Enter the weights:";
	for (i = 1; i <= n; i++)
		cin >> weights[i];
	profit = knap(n, w1);
	cout << "profit: " << profit << "\noptimal subset is:\n";
	optimal(n, w1);
	cout << "the solution vector is:";
	for (i = 1; i <= n; i++)
		cout << solVector[i];
	cin >> i;
}
