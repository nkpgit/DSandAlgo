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

int isMirror(tree *l, tree *r)
{
	// Base condition
	if (!l && !r)
		return 1;

	if (!l || !r)
		return 0;
	if (l->data != r->data)
		return 0;
	return (isMirror(l->left, r->right) && isMirror(l->right, r->left));
	
}
int main(int argc, char* argv[])
{
	tree * t1 = newnode(6);
	t1->left = newnode(3);
	t1->right = newnode(2);
	t1->right->left = newnode(3);

	tree * t2 = newnode(6);
	t2->left = newnode(2);
	t2->right = newnode(3);
	t2->left->right = newnode(3);

	cout<<isMirror(t1, t2); //mirror
	t1->data = 5;
	cout<<isMirror(t1, t2);
    return 0;
}