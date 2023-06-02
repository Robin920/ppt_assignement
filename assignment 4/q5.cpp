#include <iostream>

using namespace std;

int arrangeCoins(int n) {
    int count = 0;
    int i = 1;
    
    while (n >= i) {
        n -= i;
        i++;
        count++;
    }
    
    return count;
}

int main() {
    int n = 5;
    
    int completeRows = arrangeCoins(n);
    
    cout << "Output: " << completeRows << endl;
    
    return 0;
}
