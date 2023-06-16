#include <bits/stdc++.h>
using namespace std;



struct Node {
	int data;
	Node *next, *random;
	Node(int x) {
		data = x;
		next = random = NULL;
	}
};

Node* cloneLinkedList(Node* head) {
	if (head == NULL) {
		return NULL;
	}
	
	Node* curr = head;
	while (curr != NULL) {
		Node* newNode = new Node(curr->data);
		newNode->next = curr->next;
		curr->next = newNode;
		curr = newNode->next;
	}
	
	curr = head;
	while (curr != NULL) {
		if (curr->random != NULL) {
			curr->next->random = curr->random->next;
		}
		curr = curr->next->next;
	}
	curr = head;
	Node* clonedHead = head->next;
	Node* clonedCurr = clonedHead;
	while (clonedCurr->next != NULL) {
		curr->next = curr->next->next;
		clonedCurr->next = clonedCurr->next->next;
		curr = curr->next;
		clonedCurr = clonedCurr->next;
	}
	curr->next = NULL;
	clonedCurr->next = NULL;
	
	return clonedHead;
}

void printList(Node* head)
{
	cout << head->data << "("
		<< head->random->data << ")";
	head = head->next;
	while (head != NULL) {
		cout << " -> " << head->data << "("
			<< head->random->data << ")";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next
		= new Node(5);
	head->random = head->next->next;
	head->next->random = head;
	head->next->next->random
		= head->next->next->next->next;
	head->next->next->next->random
		= head->next->next;
	head->next->next->next->next->random
		= head->next;

	Node* sol = cloneLinkedList(head);
	if(sol != NULL){
		cout<<"Output: 1";
	}else {
		cout<<"Output: 0";
	}
	
	return 0;
}
