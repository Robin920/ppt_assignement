#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findErrorNums(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(2);
    unordered_set<int> numSet;
    int duplicate, missing;

    for (int num : nums) {
        if (numSet.find(num) != numSet.end()) {
            duplicate = num;
        } else {
            numSet.insert(num);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (numSet.find(i) == numSet.end()) {
            missing = i;
            break;
        }
    }

    result[0] = duplicate;
    result[1] = missing;

    return result;
}

int main() {

    vector<int> nums = {1, 2, 2, 4};
    vector<int> result = findErrorNums(nums);

    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";

    return 0;
}
