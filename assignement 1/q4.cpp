#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(const vector<int>& digits) {
    vector<int> result(digits); 
    int carry = 1; 

    for (int i = digits.size() - 1; i >= 0; i--) {
        int sum = result[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;

        if (carry == 0) {
            break; 
        }
    }

    if (carry > 0) {
        result.insert(result.begin(), carry); 
    }

    return result;
}

int main() {
    // Test case
    vector<int> digits = {1, 2, 3};
    vector<int> result = plusOne(digits);

    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}
