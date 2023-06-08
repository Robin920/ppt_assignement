#include <bits/stdc++.h>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    unordered_map<char, int> targetFreq, currFreq;
    int pLen = p.length();
    int sLen = s.length();

    for (char ch : p) {
        targetFreq[ch]++;
    }

    int left = 0, right = 0;

    while (right < sLen) {
        if (targetFreq.find(s[right]) != targetFreq.end()) {
            currFreq[s[right]]++;
        }
        if (right - left + 1 > pLen) {
            if (targetFreq.find(s[left]) != targetFreq.end()) {
                currFreq[s[left]]--;
                if (currFreq[s[left]] == 0) {
                    currFreq.erase(s[left]);
                }
            }
            left++;
        }
        if (right - left + 1 == pLen && currFreq == targetFreq) {
            result.push_back(left);
        }

        right++;
    }

    return result;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> result = findAnagrams(s, p);

    cout << "Indices of anagram substrings: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
