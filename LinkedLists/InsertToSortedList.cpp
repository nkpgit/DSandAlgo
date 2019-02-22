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
void Printlist(list *node)
{
	while (node)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
}

void inserttoSortedlist(list **node, int data)
{
	list *t = *node, *p = NULL;
	list *newnode = newNode(data);

	if (t == NULL)
	{
		*node = newnode;
		return;
	}

	if (data < t->data)
	{
		newnode->next = *node;
		*node = newnode;
		return;
	}
		
	while (t)
	{
		if (data < t->data)
		{
			newnode->next = t;
			p->next = newnode;
			break;
		}
		p = t;
		t = t->next;
	}

	if (t == NULL && p->data < data)
		p->next = newnode;

}
int main(int argc, char* argv[])
{
	list *t = NULL;

	for (int i = 10; i > 1; i--)
	{
		t = insertNode(t, i);
	}
	Printlist(t); 

	cout<<"insert 1\n";
	inserttoSortedlist(&t, 1);
	Printlist(t);

	cout<<"insert 20\n";
	inserttoSortedlist(&t, 20);
	Printlist(t);

	cout<<"insert 15\n";
	inserttoSortedlist(&t, 15);
	Printlist(t);

    return 0;
}
