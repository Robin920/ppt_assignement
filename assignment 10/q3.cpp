#include <bits/stdc++.h>

using namespace std;

void printSubsets(string& set, string subset, int index) {
    int n = set.length();
    if (index == n) {
        cout << subset << " ";
        return;
    }
    printSubsets(set, subset + set[index], index + 1);

    printSubsets(set, subset, index + 1);
}

int main() {
    string set = "abc";

    cout<<"Output: {";
    printSubsets(set, "", 0);
    cout<<"}";
    return 0;
}
