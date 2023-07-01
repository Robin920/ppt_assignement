#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
	if (root == NULL) {
		return;
	}
	inorder(root->left, nodes);
	nodes.push_back(root);
	inorder(root->right, nodes);
}

TreeNode* constructBST(vector<TreeNode*>& nodes, int start, int end) {
	if (start > end) {
		return NULL;
	}
	int mid = (start + end) / 2;
	TreeNode* root = nodes[mid];
	root->left = constructBST(nodes, start, mid - 1);
	root->right = constructBST(nodes, mid + 1, end);
	return root;
}

TreeNode* convertToBST(TreeNode* root) {
	vector<TreeNode*> nodes;
	inorder(root, nodes);
	sort(nodes.begin(), nodes.end(), [](const TreeNode* a, const TreeNode* b) {
		return a->val < b->val;
	});
	return constructBST(nodes, 0, nodes.size() - 1);
}

void printInorder(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	printInorder(root->left);
	cout << root->val << " ";
	printInorder(root->right);
}


int main() {
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(8);
	root->left->right = new TreeNode(4);

	TreeNode* bst = convertToBST(root);

cout <<"Following is Inorder Traversal of the converted BST:" << endl ;
	printInorder(bst);
	cout << endl;

	return 0;
}
