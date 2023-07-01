#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};

node * bToDLL(node *root)
{
	stack<pair<node*, int>> s;
	s.push({root, 0});
	vector<int> res;
	bool flag = true;
	node* head = NULL;
	node* prev = NULL;
	while(!s.empty()) {
		auto x = s.top();
		node* t = x.first;
		int state = x.second;
		s.pop();
		if(state == 3 or t == NULL) continue;
		s.push({t, state+1});
		if(state == 0) s.push({t->left, 0});
		else if(state == 1) {
			if(prev) prev->right = t;
			t->left = prev;
			prev = t;
			if(flag) {
				head = t;
				flag = false;
			}
		}
		else if(state == 2) s.push({t->right, 0});
	}
	return head;
}

node* newNode(int data)
{
	node* new_node = new node;
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return (new_node);
}

void printList(node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->right;
	}
}

int main()
{
	node* root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(20);
	root->right->left = newNode(30);
	root->right->right = newNode(35);

	node* head = bToDLL(root);

	printList(head);

	return 0;
}
