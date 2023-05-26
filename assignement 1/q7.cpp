#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int nonZeroIndex = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[nonZeroIndex] = nums[i];
            nonZeroIndex++;
        }
    }

    for (int i = nonZeroIndex; i < n; i++) {
        nums[i] = 0;
    }
}

int main() {

    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);

    cout << "Output: [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";

    return 0;
}
