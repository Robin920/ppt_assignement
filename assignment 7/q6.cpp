#include <iostream>
#include <string>

using namespace std;

bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) {
        return false;
    }

    string concatenated = s + s;

    return concatenated.find(goal) != string::npos;
}

int main() {
    string s = "abcde";
    string goal = "cdeab";

    bool canRotate = rotateString(s, goal);

    if (canRotate) {
        cout << "Output: True" << endl;
    } else {
        cout << "String cannot be rotated." << endl;
    }

    return 0;
}
