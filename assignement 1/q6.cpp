#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(const vector<int>& nums) {
    unordered_set<int> numSet;

    for (int num : nums) {
        if (numSet.find(num) != numSet.end()) {
            return true;
        }
        numSet.insert(num);
    }

    return false;
}

int main() {

    vector<int> nums = {1, 2, 3, 1};
    bool result = containsDuplicate(nums);

    (result)?cout << "Output: true":cout<<"Output: false";

    return 0;
}
