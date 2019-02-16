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
// Merge two sorted array
void Merge(int *A, int start, int mid, int end)
{
	int *T1, *T2, nT1 = mid-start+1, nT2 = end-mid;
	int i, j, k;
	T1 = new int[nT1];
	T2 = new int[nT2];

	for (i = 0; i< nT1; i++)
		T1[i] = A[i+start];

	for (i = 0; i< nT2; i++)
		T2[i] = A[i+mid+1];

	i =0; j=0; k = start;

	while (i < nT1 && j < nT2)
	{
		if (T1[i] < T2[j])
			A[k++] = T1[i++];
		else
			A[k++] = T2[j++];
	}

	while(i < nT1)
		A[k++] = T1[i++];

	while(j < nT2)
		A[k++] = T2[j++];

	delete [] T1;
	delete [] T2;
}
void MergeSort(int *A, int start, int end)
{
	if (start < end)
	{
		int mid = ( start + end )/2;
		MergeSort(A, start, mid);
		MergeSort(A, mid+1, end);
		Merge(A, start, mid, end);
	}
}

int main(int argc, char* argv[])
{
	int A[] = {12,4,89,1,67,3,66,100,102,15,9};
	MergeSort(A, 0, 10);
    return 0;
}
