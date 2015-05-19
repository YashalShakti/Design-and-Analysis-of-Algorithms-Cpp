#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<fstream>

using namespace std;

const int MAX = 1000;
//Funtion to find the pivot element. Parameters are the Array , low and high indices. 
int partition(int a[], int low, int high)
{
	int  i, j, pivot, temp;
	//Pivot will initially be first element.
	pivot = a[low];
	i = low;
	j = high + 1;
	while (i <= j)
	{
		//All elements which are lesser than pivot element are passed through.
		do
		{
			i++;
		} while (pivot >= a[i]);
		do
		{
			j--;
		} while (pivot<a[j]);
		if (i<j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[low];
	a[low] = a[j];
	a[j] = temp;
	return j;
}

void quickSort(int a[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = partition(a, low, high);
		quickSort(a, low, mid - 1);
		quickSort(a, mid + 1, high);
	}
}
int main()
{
	clock_t start, end;
	int choice,a[1000], n, i = 0;
	cout << "\nEnter 1: to put random numbers and 2 to input numbers from \"QSinput.txt\" ";
	cin >> choice;
	cout << "\nEnter the number of elements : ";
	cin >> n;
	if (choice == 1)
	{
		cout << "\nEntering random numbers into the array\n";
		for (i = 0; i < n; i++)
			a[i] = rand();
	}
	else
	{
		ifstream fin;
		fin.open("QSinput.txt");
		for (i = 0; i < n; i++)
			fin >> a[i];
		
	}
	
	cout << "\n\nElements before sorting are :\n";
	for (i = 0; i < n; i++)
	{
		cout << " " << a[i];
	}
	start = clock();
	quickSort(a, 0, n - 1);
	end = clock();
	cout << "\n\nElements after sorting are :\n";
	for (i = 0; i < n; i++)
	{
		cout << " " << a[i];
	}
	cout << "\n\nTime taken is  : "<<(end - start) / (double)CLK_TCK;
	cin >> n;
	return 1;
}
