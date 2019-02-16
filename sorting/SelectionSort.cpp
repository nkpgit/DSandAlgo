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
void SelectionSort(int *A, int size)
{
	int min, index = 0;;

	for (int i = 0; i<size; i++)
	{
		min = A[i];
		for (int j = i; j <= size; j++)
		{
			if (min > A[j])
			{
				index = j;
				min = A[j];
			}
		}
		if (min != A[i])
			Swap(A[i], A[index]);
	}
}

int main(int argc, char* argv[])
{
	int A[] = {2,4,89,1,67,3,66,100,12,15,9};
	SelectionSort(A, 10);
    return 0;
}
