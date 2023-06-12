#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > mid) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    vector<int> nums = {0, 1, 3};
    int missingNum = missingNumber(nums);
    cout << "Missing number: " << missingNum << endl;

    return 0;
}
