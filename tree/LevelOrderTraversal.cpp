#include <stdafx.h>
#include <Windows.h>
#include <vector>
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
void LevelOrder(tree *t)
{
	queue<tree*> q;
	q.push(t);
	tree *temp;

	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		cout<<temp->data<<endl;

		if (temp->left)
			q.push(temp->left);

		if (temp->right)
			q.push(temp->right);
	}
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

	LevelOrder(t);
    return 0;
}