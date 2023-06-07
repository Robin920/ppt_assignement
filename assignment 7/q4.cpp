#include <bits/stdc++.h>

using namespace std;

string reverseWords(string s) {
        int l =0;
        int  r = 0;
        while(l < s.size()) {
            while(r < s.size() && s[r] != ' ') {
                r++;
            }
            reverse(s.begin()+l, s.begin()+r);
            l = r+1;
            r = l;
        }
        return s;
}

int main() {
    string s = "Let's take LeetCode contest";

    string reversed = reverseWords(s);
    cout << "Outputs: " << reversed << endl;

    return 0;
}
