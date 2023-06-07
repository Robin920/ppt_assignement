#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool backspaceCompare(string s, string t) {
    stack<char> stackS;
    stack<char> stackT;

    for (char c : s) {
        if (c != '#') {
            stackS.push(c);
        } else if (!stackS.empty()) {
            stackS.pop();
        }
    }

    for (char c : t) {
        if (c != '#') {
            stackT.push(c);
        } else if (!stackT.empty()) {
            stackT.pop();
        }
    }

    return stackS == stackT;
}

int main() {
    string s = "ab#c";
    string t = "ad#c";

    bool isEqual = backspaceCompare(s, t);

    if (isEqual) {
        cout << "Output: True" << endl;
    } else {
        cout << "Output: False" << endl;
    }

    return 0;
}
