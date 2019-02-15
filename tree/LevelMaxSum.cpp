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

int LevelMaxSum(tree *root)
{
	
	int max = 0, sum = 0;;
	tree *t = NULL;
	queue<tree *> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty())
	{
		t = q.front();
		q.pop();
		
		if (t== NULL)
		{
			if (max < sum)
				max = sum;
			sum = 0;

			if (!q.empty())
			{
				q.push(NULL);
			}
			else
				break;
		}
		else
		{
			sum += t->data;
			if (t->left)
				q.push(t->left);
			if (t->right)
				q.push(t->right);
		}

	}

	return max;
}
int main(int argc, char* argv[])
{
	tree * t1 = newnode(6);
	t1->left = newnode(2);
	t1->right = newnode(3);
	t1->right->left = newnode(3);

	cout<<LevelMaxSum(t1);
    return 0;
}