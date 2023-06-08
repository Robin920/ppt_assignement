#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* constructTree(string s) {
    if (s.empty()) {
        return nullptr;
    }

    int index = s.find('(');
    int val = stoi(s.substr(0, index));

    TreeNode* root = new TreeNode(val);

    int openParentheses = 0;
    int closeParentheses = 0;
    int leftStart = index;

    for (int i = index; i < s.length(); i++) {
        if (s[i] == '(') {
            openParentheses++;
        } else if (s[i] == ')') {
            closeParentheses++;
        }

        if (openParentheses == closeParentheses) {
            if (leftStart == index) {
                root->left = constructTree(s.substr(index + 1, i - index - 1));
                leftStart = i + 1;
            } else {
                root->right = constructTree(s.substr(leftStart + 1, i - leftStart - 1));
            }
        }
    }

    return root;
}

void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}

vector<int> constructBinaryTree(string s) {
    TreeNode* root = constructTree(s);

    vector<int> result;
    inorderTraversal(root, result);

    return result;
}

int main() {
    string s = "4(2(3)(1))(6(5))";

    vector<int> result = constructBinaryTree(s);

    cout << "Output: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
