#include <stdafx.h>
#include <queue>
#include <iostream>
using namespace std;
struct tree
{
	int data;
	tree *left;
	tree *right;
};

tree *newnode(int data)
{
	tree *t = new tree();
	t->data = data;
	t->left = NULL;
	t->right = NULL;
	return t;
}

int maxElementTree(tree *node)
{
	int left, right, max = 0;
	if (node)
	{
		left = maxElementTree(node->left);
		right = maxElementTree(node->right);
		max = left>right?left:right;
		if (max < node->data)
			max = node->data;
	}
	return max;
}
int main(int argc, char* argv[])
{
	tree * t = newnode(1);
	t->left = newnode(2);
	t->right = newnode(3);
	
	t->left->left = newnode(4);
	t->left->right = newnode(5);
	t->right->left = newnode(6);
	t->right->right = newnode(7);

	cout<<maxElementTree(t);
    return 0;
}