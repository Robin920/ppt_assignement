#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

bool findCircle(struct Node* head)
{
	if (head->next == NULL) {
		return true;
	}
	struct Node* temp = head;
	
	while(temp){
		if(temp->next == head){
			return true;
		}
		temp = temp->next;
	}

	return false;
}

Node* newNode(int data)
{
	struct Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

int main()
{
	struct Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = head;

	if(findCircle(head)){
		cout<<"Output: true";
	} else {
		cout<<"Output: false";
	}

	return 0;
}
