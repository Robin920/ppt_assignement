#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> parentheses;

    for (char c : s) {
        if (c == '(' || c == '*') {
            parentheses.push(c);
        } else if (c == ')') {
            if (!parentheses.empty() && (parentheses.top() == '(' || parentheses.top() == '*')) {
                parentheses.pop();
            } else {
                parentheses.push(')');
            }
        }
    }

    while (!parentheses.empty()) {
        if (parentheses.top() == '(' || parentheses.top() == '*') {
            parentheses.pop();
        } else {
            break;
        }
    }

    return parentheses.empty();
}

int main() {
    string s = "()";

    bool isValidString = isValid(s);

    cout << boolalpha;
    cout << "Output: " << isValidString << endl;

    return 0;
}
