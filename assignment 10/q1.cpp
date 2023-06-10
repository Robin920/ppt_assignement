#include <iostream>

using namespace std;

bool isPowerOfThree(int n) {
    if (n <= 0) {
        return false;
    }

    while (n % 3 == 0) {
        n /= 3;
    }

    return n == 1;
}

int main() {
    int n = 0;

    bool isPower = isPowerOfThree(n);
    cout << (isPower ? "true" : "false") << endl;

    return 0;
}
