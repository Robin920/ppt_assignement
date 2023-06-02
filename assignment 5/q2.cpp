#include <iostream>
#include <cmath>

using namespace std;

int arrangeCoins(int n) {
    int k = 0;
    while (n >= 0) {
        k++;
        n -= k;
    }
    return k - 1;
}

int main() {
    int n = 5;
    int completeRows = arrangeCoins(n);
    
    cout << "Output: " << completeRows << endl;
    
    return 0;
}
