#include <stdafx.h>
#include <queue>
#include <iostream>
using namespace std;

int FindMaxBST_itr(tree *r)
{
	if (!r)
		return -1;

	while (r)
	{
		if (r->right == NULL)
			return r->data;
		else
			r = r->right;
	}
	return r->data;
}

int FindMaxBST_rec(tree *r)
{
	if (r->right == NULL)
		return r->data;
	else
		return FindMaxBST_rec( r->right);
}

int main(int argc, char* argv[])
{
    return 0;
}