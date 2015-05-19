#include<omp.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MAX 100

using namespace std;

void mergesort(int[100], int, int);
void merge(int[100], int, int, int);
int a[MAX];
int main()
{
	int i, n;
	clock_t start, end;
	cout<<"Enter the number of elements\n";
	cin>>n;
	cout<<"\nThe random array before sorting is:\n";
	for (i = 0; i < n; i++)
	{
		a[i] = (rand()+(rand()*rand()%1000))%100;
		cout<<" "<<a[i];
	}
	start = clock();
	mergesort(a, 0, n - 1);
	end = clock();
	cout<<"\nElements of array after sorting are \n";
	for (i = 0; i < n; i++)
		cout << " "<<a[i];
	cout << "\nTime take is: "<< (end - start) / (double)CLK_TCK;
	cin >> n;
	return 1;
}
void mergesort(int a[100], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergesort(a, low, mid );
		mergesort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}
void merge(int a[100], int low, int mid, int high)
{
	int i=low, j=mid+1, k=low,c[100];
#pragma omp parallel
	while ((i <= mid) && (j <= high))
	{
		if (a[i] <= a[j])
		{
			c[k++] = a[i++];
			
		}
		else
		{
			c[k++] = a[j++];
			
		}
		

	}

	if (i <= mid)
	{
#pragma omp parallel for
		for (int q = i; q <= mid; q++)
			c[k++] = a[q];
	}
	else
	{
#pragma omp parallel for
		for (int q = j; q <= high; q++)
			c[k++] = a[q];
	}

#pragma omp parallel for
	for (i = low; i <= high; i++)
		a[i] = c[i];
	
}