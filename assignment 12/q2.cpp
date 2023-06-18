#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

bool findLoop(struct Node* head)
{
	if (head == NULL)
		return false;
	if (head->next == NULL) {
		return false;
	}
	struct Node* slow = head;
	struct Node* fast = head;
	
	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		
		if(slow == fast){
			return true;
		}
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
	head->next->next->next->next->next = head->next->next;

	if(findLoop(head)){
		cout<<"Output: true";
	} else {
		cout<<"Output: false";
	}

	return 0;
}
