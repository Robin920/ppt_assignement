#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x)
		: val(x)
		, next(NULL)
	{
	}
};

ListNode* getNode(int data)
{
	ListNode* temp;
	temp = (ListNode*)malloc(sizeof(ListNode));
	temp->val = data;
	temp->next = NULL;
	return temp;
}

void printList(ListNode* head)
{
	while (head->next) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << head->val;
}

ListNode* removeZeroSum(ListNode* head, int K)
{
	ListNode* root = new ListNode(0);

	root->next = head;

	unordered_map<int, ListNode*> umap;

	umap[0] = root;

	int sum = 0;

	while (head != NULL) {

		sum += head->val;
		ListNode* headNext = head->next;

		if (umap.find(sum - K) != umap.end()) {

			ListNode* prev = umap[sum - K];
			ListNode* start = prev;

			sum = sum - K;
			int aux = sum;
			prev = prev->next;
			while (prev != head) {
				ListNode* temp = prev;
				aux += prev->val;
				if (prev != head) {
					umap.erase(aux);
				}
				prev = prev->next;
				delete temp;
			}

			delete head;
			start->next = headNext;
		}

		else if (umap.find(sum) == umap.end()) {
			umap[sum] = head;
		}

		head = headNext;
	}

	return root->next;
}

int main()
{
	ListNode* head;

	head = getNode(1);
	head->next = getNode(2);
	head->next->next = getNode(3);
	head->next->next->next = getNode(-3);
	head->next->next->next->next = getNode(4);

	int K = 0;

	head = removeZeroSum(head, K);

	if (head != NULL)
		printList(head);
	return 0;
}
