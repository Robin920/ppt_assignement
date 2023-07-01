#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node* nextRight;

	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->nextRight = NULL;
	}
};

void connect(node* root)
{
	if (root == NULL)
		return;

	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();

		node* prev = NULL;
		while (size--) {
			node* temp = q.front();
			q.pop();

			if (temp->left)
				q.push(temp->left);

			if (temp->right)
				q.push(temp->right);

			if (prev != NULL)
				prev->nextRight = temp;
			prev = temp;
		}
		prev->nextRight = NULL;
	}
}

int main()
{
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	connect(root);

	cout << "Output: "<<endl;
	cout << root->data << " -> "
		<< (root->nextRight ? root->nextRight->data : -1)
		<< endl;
	cout << root->left->data << " -> "
		<< (root->left->nextRight
				? root->left->nextRight->data
				: -1)
		<< endl;
	cout << root->right->data << " -> "
		<< (root->right->nextRight
				? root->right->nextRight->data
				: -1)
		<< endl;
	cout << root->left->left->data
		<< " -> "
		<< (root->left->left->nextRight
				? root->left->left->nextRight->data
				: -1)
		<< endl;
	cout << root->left->right->data
		<< " -> "
		<< (root->left->right->nextRight
				? root->left->right->nextRight->data
				: -1)
		<< endl;
	cout << root->right->left->data
		<< " -> "
		<< (root->right->left->nextRight
				? root->right->left->nextRight->data
				: -1)
		<< endl;
	cout << root->right->right->data
		<< " -> "
		<< (root->right->right->nextRight
				? root->right->right->nextRight->data
				: -1)
		<< endl;

	return 0;
}