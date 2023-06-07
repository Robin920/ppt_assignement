#include <iostream>
#include <string>

using namespace std;

bool isStrobogrammatic(string num) {
    int left = 0;
    int right = num.length() - 1;

    while (left <= right) {
        if (num[left] == '0' && num[right] == '0' ||
            num[left] == '1' && num[right] == '1' ||
            num[left] == '6' && num[right] == '9' ||
            num[left] == '8' && num[right] == '8' ||
            num[left] == '9' && num[right] == '6') {
            left++;
            right--;
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    string num1 = "69";

    cout<< "Output: " << (isStrobogrammatic(num1) ? "true" : "false") << endl;
   
    return 0;
}
