#include <iostream>
#include <string>
using namespace std;

void permute(string str, int l, int r) {
    if (l == r) {
        cout << str << " ";
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(str[l], str[i]);
        permute(str, l + 1, r);
        swap(str[l], str[i]);
    }
}

void printPermutations(string str) {
    int n = str.length();
    permute(str, 0, n - 1);
}

int main() {
    string str = "cd";
    printPermutations(str);
    
    return 0;
}
