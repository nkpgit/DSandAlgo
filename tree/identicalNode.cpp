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

int isSame(tree *t1, tree *t2)
{
	// if both tree are null return true
	// if both trees are not null then compare the data
	if (!t1 && !t2)
		return 1;
	if (!t1 || !t2)
		return 0;
	return (t1->data == t2->data && 
			isSame(t1->left, t2->left) && 
			isSame(t1->right, t2->right));

	
}
int main(int argc, char* argv[])
{
	tree * t1 = newnode(1);
	t1->left = newnode(2);
	t1->right = newnode(3);
	t1->right->left = newnode(33);

	tree * t2 = newnode(1);
	t2->left = newnode(2);
	t2->right = newnode(3);
	t2->right->left = newnode(33);
	
	cout<<isSame(t1, t2);

	t2->right->right = newnode(13);

	cout<<isSame(t1, t2);
    return 0;
}