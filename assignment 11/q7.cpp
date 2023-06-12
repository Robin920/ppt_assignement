#include <bits/stdc++.h>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;
    vector<int> result{-1, -1};

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            result[0] = mid;
            right = mid - 1;  
        }
    }

    left = 0;
    right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            result[1] = mid;
            left = mid + 1;  
        }
    }

    return result;
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = searchRange(nums, target);

    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
