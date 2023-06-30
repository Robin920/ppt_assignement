#include <bits/stdc++.h>
using namespace std;


struct Node {
	int key;
	Node *left, *right;
};


Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

int findLargestSubtreeSum(Node* root, int& ans)
{
	if (root == NULL)	
		return 0;
	
	int currSum = root->key +
	findLargestSubtreeSum(root->left, ans)
	+ findLargestSubtreeSum(root->right, ans);

	ans = max(ans, currSum);

	return currSum;
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	
	if (root == NULL)	
		return 0;
	
	int ans = INT_MIN;

	findLargestSubtreeSum(root, ans);

	cout<<"Output: "<<ans;

	return 0;
}
