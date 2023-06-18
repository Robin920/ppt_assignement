// C++ program to merge a linked list into another at
// alternate positions
#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};

void push(Node ** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void merge(Node *p, Node **q)
{
	Node *p_curr = p, *q_curr = *q;
	Node *p_next, *q_next;

	while (p_curr != NULL && q_curr != NULL)
	{
		p_next = p_curr->next;
		q_next = q_curr->next;

		q_curr->next = p_next; 
		p_curr->next = q_curr; 

		p_curr = p_next;
		q_curr = q_next;
	}

	*q = q_curr; 
}

int main()
{
	Node *p = NULL, *q = NULL;
	push(&p, 3);
	push(&p, 2);
	push(&p, 1);
	cout<<"First Linked List:\n";
	printList(p);

	push(&q, 8);
	push(&q, 7);
	push(&q, 6);
	push(&q, 5);
	push(&q, 4);
	cout<<"Second Linked List:\n";
	printList(q);

	merge(p, &q);

	cout<<"Modified First Linked List:\n";
	printList(p);

	cout<<"Modified Second Linked List:\n";
	printList(q);

	return 0;
}