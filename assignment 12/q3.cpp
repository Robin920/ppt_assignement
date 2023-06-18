#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node* next;
	node(int val)
	{
		data = val;
		next = NULL;
	}
};

struct llist {

	node* head;
	llist() { head = NULL; }

	void insertAtBegin(int val)
	{
		node* newNode = new node(val);
		newNode->next = head;
		head = newNode;
	}
	
	void nthFromEnd(int n)
	{
		node* main_ptr = head;
		node* ref_ptr = head;

		if (head == NULL) {
			cout << "List is empty" << endl;
			return;
		}

		for (int i = 1; i < n; i++) {
			ref_ptr = ref_ptr->next;
			if (ref_ptr == NULL) {
				cout << n
					<< " is greater than no. of nodes in "
						"the list"
					<< endl;
				return;
			}
		}

		while (ref_ptr != NULL && ref_ptr->next != NULL) {
			ref_ptr = ref_ptr->next;
			main_ptr = main_ptr->next;
		}
		cout << "Node no. " << n
			<< " from end is: " << main_ptr->data << endl;
	}

	void displaylist()
	{
		node* temp = head;
		while (temp != NULL) {
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};

int main()
{
	llist ll;

	for(int i=9;i>=1;i--){
		ll.insertAtBegin(i);
	}
	
	ll.displaylist();

	ll.nthFromEnd(2);

	return 0;
}