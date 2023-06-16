#include<bits/stdc++.h>
using namespace std;

struct Node
{
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


void rearrangeEvenOdd(Node *head)
{
if(head==NULL || head->next == NULL){
	
	return;
}
Node* temp = head;
Node* oddStart = NULL; 
Node* oddEnd = NULL;
Node* evenStart = NULL; 
Node* evenEnd = NULL;

int i = 1;
while(temp != NULL){

	if(i%2 ==0){

	if(evenStart == NULL){
		evenStart = temp;

	}
	else{
		evenEnd->next = temp;

	}
	evenEnd = temp;
	}
	else{
	
	if(oddStart == NULL){
		oddStart = temp;
	}
	else{
		oddEnd->next = temp;
	}
	oddEnd = temp;
	}
	temp = temp->next;
	i++;
}

oddEnd->next = evenStart;

evenEnd->next = NULL;

head = oddStart; 
}

void printlist(Node * node)
{
	while (node != NULL)
	{
		cout << node->data << "->";
		node = node->next;
	}
	cout << "NULL" << endl;
}

int main(void)
{
	Node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	rearrangeEvenOdd(head);

	cout << "\nModified Linked List\n";
	printlist(head);

	return 0;
}
