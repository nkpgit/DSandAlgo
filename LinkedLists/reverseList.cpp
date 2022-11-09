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

void reverse(list **node)
{
	list *t = *node;
	list *rev = NULL, *temp;
	while (t)
	{
		temp = t;
		t = t->next;
		temp->next = rev;
		rev = temp;
	}
	
	*node = rev;
}


int main(int argc, char* argv[])
{
	list *t = NULL;

	for (int i = 10; i > 1; i--)
	{
		t = insertNode(t, i);
	}
	Printlist(t); 

	
	reverse(&t);
	Printlist(t);

	

    return 0;
}
