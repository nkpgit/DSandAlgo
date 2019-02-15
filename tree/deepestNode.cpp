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

tree * deepestNode(tree *node)
{
	tree *t = NULL;
	queue <tree *> q;
	q.push(node);

	while(!q.empty())
	{
		t = q.front();
		q.pop();

		if (t->left)
			q.push(t->left);
		if (t->right)
			q.push(t->right);
	}
	return t;
}
int main(int argc, char* argv[])
{
	tree * t = newnode(1);
	t->left = newnode(2);
	t->right = newnode(3);
	t->right->left = newnode(33);

	tree *temp = deepestNode(t);
	cout<<temp->data;
	
    return 0;
}