#include <bits/stdc++.h>

using namespace std;

string decodeString(string s) {
    stack<int> countStack;
    stack<string> strStack;
    string currentString;
    int count = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            count = count * 10 + (ch - '0');
        } else if (ch == '[') {
            countStack.push(count);
            strStack.push(currentString);
            count = 0;
            currentString.clear();
        } else if (ch == ']') {
            string decodedString = strStack.top();
            strStack.pop();
            int repeatCount = countStack.top();
            countStack.pop();

            for (int i = 0; i < repeatCount; i++) {
                decodedString += currentString;
            }

            currentString = decodedString;
        } else {
            currentString += ch;
        }
    }

    return currentString;
}

int main() {
    string s = "3[a]2[bc]";
    string decodedString = decodeString(s);
    cout << "Decoded string: " << decodedString << endl;

    return 0;
}
