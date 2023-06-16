#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x)
	{
		val = x;
		next = NULL;
	}
};

void rev(ListNode** head)
{
	ListNode *pre, *curr, *nex;

	pre = NULL;
	curr = *head;
	nex = curr->next;

	while (curr) {
		curr->next = pre;
		pre = curr;
		curr = nex;
		nex = (curr)
				? curr->next
				: NULL;
	}
	*head = pre;
}

void printList(ListNode* head)
{
	while (head) {

		cout << head->val
			<< ' ';
		head = head->next;
	}
}

ListNode* nextLargerLL(ListNode* head)
{
	if (head == NULL)
		return NULL;

	ListNode* res
		= new ListNode(-1);
	ListNode* temp = res;

	rev(&head);
	stack<int> st;

	while (head) {

		if (st.empty()) {
			temp->next
				= new ListNode(0);
			st.push(head->val);
		}
		else {

			while (!st.empty()
				&& st.top()
						<= head->val)
				st.pop();

			if (st.empty()) {
				temp->next
					= new ListNode(0);

				st.push(head->val);
			}
			else {
				temp->next
					= new ListNode(st.top());
				st.push(head->val);
			}
		}
		head = head->next;
		temp = temp->next;
	}

	temp = res;
	res = res->next;
	delete temp;

	rev(&res);
	return res;
}

int main()
{
	ListNode* head = new ListNode(2);
	ListNode* curr = head;

	curr->next = new ListNode(7);
	curr = curr->next;

	curr->next = new ListNode(4);
	curr = curr->next;

	curr->next = new ListNode(3);
	curr = curr->next;

	curr->next = new ListNode(5);
	curr = curr->next;

	printList(nextLargerLL(head));
	return 0;
}
