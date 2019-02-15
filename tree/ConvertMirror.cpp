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

void ConvertMirror(tree *root)
{
	if (root)
	{
		ConvertMirror(root->left);
		ConvertMirror(root->right);

		// swap
		tree *t = root->left;
		root->left = root->right;
		root->right = t;
	}
	
}
int main(int argc, char* argv[])
{
	tree * t1 = newnode(6);
	t1->left = newnode(2);
	t1->right = newnode(3);
	t1->right->left = newnode(3);

	ConvertMirror(t1);
    return 0;
}