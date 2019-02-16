#include <stdafx.h>
#include <queue>
#include <iostream>
using namespace std;

int FindMinBST_itr(tree *r)
{
	if (!r)
		return -1;

	while (r)
	{
		if (r->left == NULL)
			return r->data;
		else
			r = r->left;
	}
	return r->data;
}

int FindMinBST_rec(tree *r)
{
	if (r->left == NULL)
		return r->data;
	else
		return FindMaxBST_rec( r->left);
}

int main(int argc, char* argv[])
{
    return 0;
}