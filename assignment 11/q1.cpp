#include <iostream>
using namespace std;

int mySqrt(int x) {
    if (x == 0) {
        return 0;
    }
    
    int left = 1, right = x;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if ((mid*mid) <= x && ((mid + 1)*(mid+1)) > x) {
            return mid; 
        } else if ((mid*mid) > x) {
            right = mid - 1; 
        } else {
            left = mid + 1;  
        }
    }
    
    return -1;
}

int main() {
    int x = 8;
    int result = mySqrt(x);
    cout << "Square root of " << x << " rounded down: " << result << endl;
    
    return 0;
}
