#include <stdafx.h>
#include <queue>
#include <iostream>
using namespace std;

struct list
{
	int data;
	list *next;
};

list * newNode(int data)
{
	list *t = new list();
	t->data = data;
	t->next = NULL;

	return t;
}
list * insertNode(list *node, int data)
{
	list *t = newNode(data);
	if (!node)
		node = t;
	else
	{
		t->next = node;
		node = t;
	}
	return node;
}
list* findNTHnodeFromLast(list *node, int n)
{
	list *nth = NULL, *first = node;
	while (node)
	{

		if (n == 0)
		{
			nth = first;
				break;
		}
		n--;
		node = node->next;
	}

	while (node)
	{
		nth = nth->next;
		node = node->next;
	}

	return nth;
}
int main(int argc, char* argv[])
{
	list *t = NULL;

	for (int i = 10; i > 0; i--)
	{
		t = insertNode(t, i);
	}
	cout<<findNTHnodeFromLast(t, 5)->data;
    return 0;
}
