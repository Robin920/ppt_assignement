#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int x)
	{
		data = x;
		next = NULL;
	}
};

void printList(Node* node)
{
	while (node != NULL) {
		cout<<node->data<<" ";
		node = node->next;
	}
	cout << endl;
}

	Node* mergeKLists(Node* arr[], int K)
	{
		Node* head = NULL;
		while (1) {
			int a = 0;
			int z;
			Node* curr;
			int min = INT_MAX;
			for (int i = 0; i < K; i++) {
				if (arr[i] != NULL) {
					a++;
					if (arr[i]->data < min) {
						min = arr[i]->data;
						z = i;
					}
				}
			}
			if (a != 0) {
				arr[z] = arr[z]->next;
				Node* temp = new Node(min);
				if (head == NULL) {
					head = temp;
					curr = temp;
				}
				else {
					curr->next = temp;
					curr = temp;
				}
			}
			else {
				return head;
			}
		}
	}

int main()
{
	int k = 3; 
	int n = 4; 
	Node* arr[k];

	arr[0] = new Node(1);
	arr[0]->next = new Node(4);
	arr[0]->next->next = new Node(5);

	arr[1] = new Node(1);
	arr[1]->next = new Node(3);
	arr[1]->next->next = new Node(4);

	arr[2] = new Node(2);
	arr[2]->next = new Node(6);
	
	Node* head = mergeKLists(arr, k);

    cout<<"Output: ";
	printList(head);
	return 0;
}