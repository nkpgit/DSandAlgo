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
// Partition index
int Partition(int *A, int mid, int end)
{
	int last = end;

	while (last > mid)
	{
		if (A[mid] > A[end])
			Swap(A[mid], A[--last]);
		else
			mid++;
	}
	Swap(A[last], A[end]);

	return last;
}
void QuickSort(int *A, int start, int end)
{
	if (start < end)
	{
		int p = Partition(A, start, end);
		
		QuickSort(A, start, p-1);
		QuickSort(A, p+1, end);
	}
}

int main(int argc, char* argv[])
{
	int A[] = {12,4,89,1,67,3,66,100,102,15,9};
	QuickSort(A, 0, 10);
    return 0;
}
