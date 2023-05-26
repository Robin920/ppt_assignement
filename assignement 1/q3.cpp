#include <iostream>
#include <vector>
using namespace std;

int searchInsert(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    // Test case
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int index = searchInsert(nums, target);

    cout << "Output: " << index << endl;

    return 0;
}
