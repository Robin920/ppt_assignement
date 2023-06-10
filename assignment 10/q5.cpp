#include <iostream>
#include <string>

using namespace std;

int countSubstring(string str) {
    int count = 0;
    int length = str.length();

    for (int i = 0; i < length; i++) {
        count++;
        int left = i - 1;
        int right = i + 1;

        while (left >= 0 && right < length && str[left] == str[right]) {
            count++;
            left--;
            right++;
        }
    }

    return count;
}

int main() {
    string str = "abcab";
    int count = countSubstring(str);
    cout << "Count of contiguous substrings: " << count << endl;

    return 0;
}
