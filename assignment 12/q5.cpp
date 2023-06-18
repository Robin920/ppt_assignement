#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void deleteLoop(struct Node* start)
{
	struct Node* temp = start;
	while(temp->next != start){
		temp = temp->next;
	}
	
	temp->next = NULL;
}
bool findLoop(struct Node* head)
{
	if (head == NULL)
		return false;
	if (head->next == NULL) {
		return false;
	}
	struct Node* slow = head;
	struct Node* fast = head;
	struct Node* temp = head;
	
	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		
		if(slow == fast){
			while(slow != temp){
				slow = slow->next;
				temp = temp->next;
			}
			deleteLoop(temp);
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

void printList(struct Node* ptr)
{
	while (ptr != NULL) {
		cout << ptr->data << "->";
		ptr = ptr->next;
	}
	cout << "NULL\n";
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
		cout<<"Loop removed: ";
		printList(head);
	} else {
		cout<<"Loop not present";
	}

	return 0;
}
