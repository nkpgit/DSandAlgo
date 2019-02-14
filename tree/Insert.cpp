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

void Insert(tree *node, int data)
{

	tree *temp;
	queue<tree *> q;
	q.push(node);
	while (!q.empty())
	{
		temp = q.front();
		q.pop();

		if (temp->left)
			q.push(temp->left);
		else
		{
			temp->left = newnode(data);
			break;
		}

		if (temp->right)
			q.push(temp->right);
		else
		{
			temp->right = newnode(data);
			break;
		}
	}
	
}
int main(int argc, char* argv[])
{
	tree * t = newnode(1);
	t->left = newnode(2);
	t->right = newnode(3);
	
	Insert(t,4);
	Insert(t,5);
	Insert(t,6);
	Insert(t,7);

	
    return 0;
}