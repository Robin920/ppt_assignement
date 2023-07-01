#include <bits/stdc++.h>
using namespace std;

struct Node {
	struct Node* left, *right;
	int key;
};

struct Node* newNode(int key)
{
	struct Node* ptr = new Node;
	ptr->key = key;
	ptr->left = ptr->right = NULL;
	return ptr;
}

struct Node* insert(struct Node* root, int key)
{
	if (!root)
		root = newNode(key);
	else if (root->key > key)
		root->left = insert(root->left, key);
	else if (root->key < key)
		root->right = insert(root->right, key);
	return root;
}


int distanceFromRoot(struct Node* root, int x)
{
	if (root->key == x)
		return 0;
	else if (root->key > x)
		return 1 + distanceFromRoot(root->left, x);
	return 1 + distanceFromRoot(root->right, x);
}

int distanceBetween2(struct Node* root, int a, int b)
{
	if (!root)
		return 0;

	if (root->key > a && root->key > b)
		return distanceBetween2(root->left, a, b);

	if (root->key < a && root->key < b) 
		return distanceBetween2(root->right, a, b);

	if (root->key >= a && root->key <= b)
		return distanceFromRoot(root, a) +
			distanceFromRoot(root, b);
}


int findDistWrapper(Node *root, int a, int b)
{
if (a > b)
	swap(a, b);
return distanceBetween2(root, a, b);
}

int main()
{
	struct Node* root = NULL; 
	root = insert(root, 8);
	insert(root, 3);
	insert(root, 1);
	insert(root, 6);
	insert(root, 4);
	insert(root, 7);
	insert(root, 10);
	insert(root, 14);
	insert(root, 13);
	int a = 6, b = 14;
    
    cout<<"Distance: "<<findDistWrapper(root, a, b);
    return 0;
}
