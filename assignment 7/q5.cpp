#include <iostream>
#include <string>

using namespace std;

void reverseRange(string& s, int start, int end) {
    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

string reverseStr(string s, int k) {
    int n = s.length();

    for (int i = 0; i < n; i += 2 * k) {
        // Reverse the first k characters
        int start = i;
        int end = min(i + k - 1, n - 1);
        reverseRange(s, start, end);
    }

    return s;
}

int main() {
    string s = "abcdefg";
    int k = 2;

    string reversed = reverseStr(s, k);

    cout << "Output: " << reversed << endl;

    return 0;
}
