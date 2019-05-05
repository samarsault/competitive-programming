/*
ID: samarjeet27
LANG: C++
TASK: pails
*/
#include <iostream>
#include <fstream>

using namespace std;

/* Circular Linked List */
typedef struct node {
	int data;
	struct node *next;
} node;

node* nth(node *root, int n)
{
	for (int i = 0;i < n;i++)
		root = root->next;
	return root;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);

	ifstream fin ("cbarn.in");
	ofstream fout ("cbarn.out");

	node *root = new node;
	node *current = root;
	int n;
	fin >> n;
	for (int i = 0;i < n;i++)
	{
		fin >> current->data;
		current->next = new node;
		current = current->next;
	}
	nth(root, n - 1)->next = root;
	// Solve
	// minimum distance
	int counter = 0, mindist = 0, dist = 0;

	for (int i = 0;i < n;i++)
	{
		counter = 0;
		dist = 0;
		node *head = nth(root, i);
		node *curr = head;
		do 
		{
			dist += (head->data * counter);
			counter++;
			head = head->next;
		}
		while (head != curr);

		if (mindist == 0 || dist < mindist)
			mindist = dist;
	}

	fout << mindist << endl;
	// free memory
	delete root;
	// Close File
	fin.close();
	fout.close();

	return 0;

}