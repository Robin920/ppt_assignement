#include <iostream>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> charCount;

    for (char c : s) {
        charCount[c]++;
    }

    for (int i = 0; i < s.length(); i++) {
        if (charCount[s[i]] == 1) {
            return i;
        }
    }

    return -1; 
}

int main() {
    string s = "leetcode";
    int index = firstUniqChar(s);
    cout << "Index of first non-repeating character: " << index << endl;
    return 0;
}
