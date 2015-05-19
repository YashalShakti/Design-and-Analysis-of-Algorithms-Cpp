#include<iostream>
using namespace std;
void printsol(int a[10], int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n;j++)
		if (j == a[i])
			cout << " q ";
		else
			cout << " x ";
		cout << endl;
	}
	
}
int place(int x[10], int k)
{

	for (int i = 1; i < k; i++)
		if (x[i] == x[k] || abs(x[i] - x[k]) ==abs(i - k) || i - x[i] == k - x[i] || i + x[i] == k + x[k])
			return 0;
		
			return 1;
	
}
void nqueens(int n)
{
	int column[10], count=0, row;
	row = 1;
	column[row] = 0;
	while (row != 0)
	{
		column[row]+=1;
		
		while (column[row] <= n && (!place(column, row)))
		{
			column[row] += 1;
		}
		if (column[row] <= n)
		{
			if (row == n)
			{
				cout << "Solution " << ++count<<endl;
				printsol(column,n);
			}
			else
			{
				row++;
				column[row] = 0;
			}
		}
		else
			row--;


	}

}
int main()
{
	int n;
	cout << "Enter the number of queens\n";
	cin >> n;
	nqueens(n);
	cin >> n;
	return -1;
}
