#include<iostream>
using namespace std;

int x[10],w[10],d;


void subset(int cs, int k, int r)
{
	x[k] = 1;
	if (cs + w[k] == d)
	{
		cout << "\nThe subset is :";
		for (int i = 0; i <= k;i++)
		if (x[i] == 1)
			cout << w[i] << " ";
	}
	else
	{
		if (cs + w[k] + w[k + 1] <= d)
			subset(cs + w[k], k + 1, r - w[k]);
		if (cs + r - w[k] >= d&&cs + w[k] <= d)
		{
			x[k] = 0;
			subset(cs, k + 1, r - w[k]);
		}
	}

}
int main()
{
	int n, sum=0;
	cout << "Enter the number of elements\n";
	cin >> n;
	cout << "Enter the set\n";
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
		sum += w[i];
	}
	cout << "Enter the max subset value\n";
	cin >> d;
	subset(0, 0, sum);
	cin >> n;
	return -1;
}