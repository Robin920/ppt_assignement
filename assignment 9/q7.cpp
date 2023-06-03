#include <iostream>
#include <string>

using namespace std;

void permute(string& str, int start, int end) {
    if (start == end) {
        cout << str << " ";
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(str[start], str[i]);
        permute(str, start + 1, end);
        swap(str[start], str[i]);
    }
}

int main() {
    string S = "ABC";

    cout << "Permutations of string " << S << ":" << endl;
    permute(S, 0, S.length() - 1);

    return 0;
}
