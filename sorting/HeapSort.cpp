#include <stdafx.h>
#include <queue>
#include <iostream>
using namespace std;

void Swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void heapFy(int *A, int size, int i)
{
	int large = i;
	int l = 2*i +1;
	int r = 2*i +2;

	if (l < size && A[large] < A[l])
		large = l;
	if (r < size && A[large] < A[r])
		large = r;

	if (i != large)
	{
		Swap(A[i], A[large]);
		heapFy(A, size, large);
	}
}

void HeapSort(int *A, int size)
{
	// build heaps
	for (int i = size/2 -1; i >=0 ; i--)
		heapFy(A, size, i);

	for (int i = size -1; i>0; i--)
	{
		Swap (A[0], A[i]);
		heapFy(A, i, 0);
	}
}
int main(int argc, char* argv[])
{
	int A[] = {12,4,89,1,67,3,66,100,102,15,9};
	HeapSort(A, 11);
    return 0;
}
