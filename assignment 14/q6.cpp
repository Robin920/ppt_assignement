#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

Node* newNode(int key)
{
	Node *temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

Node* rotate(Node* head, int k)
{
	Node* last = head;
	Node* temp = head;

	if (head == NULL || k == 0) {
		return head;
	}

	while (last->next != NULL) {
		last = last->next;
	}

	while (k) {

		head = head->next;

		temp->next = NULL;

		last->next = temp;
		last = temp;

		temp = head;
		k--;
	}

	return head;
}

void printList(Node* n)
{
	while (n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

int main()
{
	Node *head = newNode(2);
	head->next = newNode(4);
	head->next->next = newNode(7);
	head->next->next->next = newNode(8);
	head->next->next->next->next = newNode(9);

	cout << "Given linked list \n";
	printList(head);
	head = rotate(head, 3);

	cout << "\nRotated Linked list \n";
	printList(head);
	return 1;
}

