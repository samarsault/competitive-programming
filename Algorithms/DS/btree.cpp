#include <iostream>

using namespace std;

/* binary search tree */
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} node;

bool search(node *root, int val)
{
	if (root == NULL)
		return false;

	if (root->data== val)
		return true;
	else if (root->data > val)
		return search(root->left, val);
	else // root->n < val
		return search(root->right, val);
}

int size(node *root)
{
	if (root == NULL)
		return 0;
	return size(root->left) + 1 + size(root->right);
}

int maxDepth(node *root)
{
	if (root == NULL)
		return 0;
	else
	{
		int ldepth = maxDepth(root->left);
		int rdepth = maxDepth(root->right);

		if (ldepth > rdepth)
			return ldepth + 1;
		else
			return rdepth + 1;
	}
}

node* createNode(int data)
{
	node *nd = new node;
	nd->data = data;
	nd->left = NULL;
	nd->right = NULL;

	return nd;
}

node* insert(node *tn, int data)
{
	if (tn == NULL)
	{
		tn = createNode(data);
		return tn;
	}
	else if (data <= tn->data)
	{
		tn->left = insert(tn->left, data);
	}
	else
	{
		tn->right = insert(tn->right, data);
	}
	return tn;
}

int minValue(node *root)
{
	if (root->left == NULL)
		return root->data;
	return minValue(root->left);
}

void printTree(node *root)
{
	if (root == NULL)
		return;

	printTree(root->left);
	cout << root->data << " ";
	printTree(root->left);
}

int main(int argc, char const *argv[])
{
	// Build Tree
	node *root = createNode(4);
	node *two = insert(root, 2);
	insert(root, 5);
	insert(two, 1);
	insert(two, 3);

	cout << "1 is in tree "<< search(root,  1) << endl;
	cout << "Max Depth of Tree "<< maxDepth(root) << endl;
	cout << "No. of Nodes in Tree "<< size(root) << endl;
	cout << "Min Value: " << minValue(root) << endl;

	printTree(root);
	return 0;
}