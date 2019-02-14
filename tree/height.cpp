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

int height(tree *node)
{
	int rh = 0, lh = 0;

	if (node)
	{
		lh = height(node->left);
		rh = height(node->right);
		
		return 1 + (lh>rh?lh:rh);
	}
	return (lh>rh?lh:rh);
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

	cout<<height(t);
    return 0;
}