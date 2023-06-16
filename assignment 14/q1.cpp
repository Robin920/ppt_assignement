#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

int detectAndRemoveLoop(Node* head)
{
	if (head == NULL || head->next == NULL)
		return 1;

	Node *slow = head, *fast = head;

	slow = slow->next;
	fast = fast->next->next;

	while (fast && fast->next) {
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow == fast) {
		slow = head;
		if (slow == fast)
			while (fast->next != slow)
				fast = fast->next;
		else {
			while (slow->next != fast->next) {
				slow = slow->next;
				fast = fast->next;
			}
		}

		fast->next = NULL;
	}
	
	return 1;
}

int main()
{
	Node* head = newNode(1);
	head->next = head;
	head->next = newNode(8);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);

	head->next->next->next->next = head;

	cout<<"Output: "<<detectAndRemoveLoop(head);

	return 0;
}

