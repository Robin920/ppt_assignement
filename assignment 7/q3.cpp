#include <iostream>
#include <string>

using namespace std;

string addStrings(string num1, string num2) {
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;
    string result;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? (num1[i] - '0') : 0;
        int digit2 = (j >= 0) ? (num2[j] - '0') : 0;
        int digitSum = digit1 + digit2 + carry;

        result = char(digitSum % 10 + '0') + result;
        carry = digitSum / 10;

        i--;
        j--;
    }

    return result;
}

int main() {
    string num1 = "11";
    string num2 = "123";

    string sum = addStrings(num1, num2);
    cout << "Output: " << sum << endl;

    return 0;
}
