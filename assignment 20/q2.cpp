\#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;

	Node(int x)
	{
		data = x;
		right = NULL;
		left = NULL;
	}
};

Node* constructBst(int arr[], int n)
{
	queue<pair<Node*, pair<int, int> > > q;

	if (n == 0)
		return NULL;

	Node *root = new Node(arr[0]), *head = root;

	q.push({ root, { INT_MIN, INT_MAX } });

	for (int i = 1; i < n; i++) {

		Node* temp = q.front().first;
		pair<int, int> range = q.front().second;

		if (arr[i] > range.first && arr[i] < range.second) {

			if (arr[i] < temp->data) {

				if(temp->left != NULL){
					q.pop();
					i--;
					continue;
				}
			
				temp->left = new Node(arr[i]);
				q.push({ temp->left,
						{ range.first, temp->data } });
			}

			else {
				q.pop();
				temp->right = new Node(arr[i]);
				q.push({ temp->right,
						{ temp->data, range.second } });
			}
		}
		else {

			q.pop();
			i--;
		}
	}
	return head;
}

void inorderTraversal(Node* root)
{
	if (!root)
		return;

	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right);
}


int main()
{
	int arr[] = { 7, 4, 12, 3, 6, 8, 1, 5, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	Node* root = constructBst(arr, n);

	cout << "Inorder Traversal: ";
	inorderTraversal(root);
	return 0;
}