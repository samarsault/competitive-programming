/*
 * Doubly Linked List
 */

#include <iostream>

 using namespace std;

typedef struct node {
	node *next;
	node *prev;
	int key;
} node;

class List {
private:
	node *start;
	node *last;
	node *NIL;
	node* makeNode(int key, node * next, node * prev)
	{
		node * N = new node;
		N->key = key;
		N->next = next;
		N->prev = prev;
		return N;
	}
public:
	List()
	{
		NIL = NULL;
		start = new node;
		start->prev = NIL;
		start->next = NIL;
		last = start;
	}
	~List()
	{
		delete start;
	}
	void insert(int key)
	{
		node *n = makeNode(key, NIL, last);
		n->prev = last;
		last = n;
	}
	void prepend(int key)
	{
		node *tmp = makeNode(key, start->next, start);
		start->next = tmp;
	}
	void remove(node *nd)
	{
		nd->prev->next = nd->next;
		nd->next->prev = nd->prev;
		delete nd;
	}
	node* begin()
	{
		return start->next;
	}
	node* end()
	{
		return last;
	}
};

int main(int argc, char const *argv[])
{
	return 0;
}