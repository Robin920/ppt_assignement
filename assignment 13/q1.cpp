#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void insert(Node** root, int item)
{
	Node *ptr, *temp;
	temp = new Node;
	temp->data = item;
	temp->next = NULL;

	if (*root == NULL)
		*root = temp;
	else {
		ptr = *root;
		while (ptr->next != NULL)
			ptr = ptr->next;

		ptr->next = temp;
	}
}

Node* newList(Node* root1, Node* root2)
{
	Node *ptr1 = root1, *ptr2 = root2, *ptr;
	Node *root = NULL, *temp;

	while (ptr1 != NULL) {
		temp = new Node;
		temp->next = NULL;

		if (ptr1->data < ptr2->data)
			temp->data = ptr2->data;
		else
			temp->data = ptr1->data;

		if (root == NULL)
			root = temp;
		else {
			ptr = root;
			while (ptr->next != NULL)
				ptr = ptr->next;

			ptr->next = temp;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return root;
}

void display(Node* root)
{
	while (root != NULL) {
		cout << root->data << "->";
		root = root->next;
	}

	cout << endl;
}

int main()
{
	Node *root1 = NULL, *root2 = NULL, *root = NULL;

	insert(&root1, 5);
	insert(&root1, 2);
	insert(&root1, 3);
	insert(&root1, 8);

	insert(&root2, 1);
	insert(&root2, 7);
	insert(&root2, 4);
	insert(&root2, 5);

	root = newList(root1, root2);
	cout << "New List: ";
	display(root);
	return 0;
}
