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
	
	if (node == NULL)
		return 0;
	else
	{
		int lh = height(node->left);
		int rh = height(node->right);

		return 1 + (lh>rh?lh:rh);
	}
}
int Diameter(tree *root)
{
	// The diameter of the tree is the number of nodes on the largest path between two leaves
	int max = 0;
	if (root == NULL)
		return 0;
	
	int lh = height(root->left);
	int rh = height(root->right);

	int ld = Diameter(root->left);
	int rd = Diameter(root->right);
	
	if (max < lh + rh + 1)
		max = lh + rh + 1;
	if (max < ld)
		max = ld;
	if (max <rd)
		max = rd;

	return max;
}
int main(int argc, char* argv[])
{
	tree * t1 = newnode(1);
	t1->left = newnode(2);
	t1->right = newnode(3);
	t1->right->left = newnode(33);

	cout<<Diameter(t1);
    return 0;
}