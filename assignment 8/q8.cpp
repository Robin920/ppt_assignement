#include <bits/stdc++.h>

using namespace std;

bool buddyStrings(string s, string goal) {
    int n = s.size();
    int m = goal.size();

    if (n != m) {
        return false;
    }

    if (s == goal) {
        unordered_set<char> uniqueChars;
        for (char ch : s) {
            uniqueChars.insert(ch);
        }
        return uniqueChars.size() < n;
    }

    int firstDiff = -1;
    int secondDiff = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] != goal[i]) {
            if (firstDiff == -1) {
                firstDiff = i;
            } else if (secondDiff == -1) {
                secondDiff = i;
            } else {
                return false;
            }
        }
    }

    if (firstDiff != -1 && secondDiff != -1) {
        return s[firstDiff] == goal[secondDiff] && s[secondDiff] == goal[firstDiff];
    }

    return false;
}

int main() {
    string s = "ab";
    string goal = "ba";

    bool canSwap = buddyStrings(s, goal);
    cout <<"Output: "<< (canSwap ? "true" : "false") << endl;

    return 0;
}
