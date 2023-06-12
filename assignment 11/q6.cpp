#include <bits/stdc++.h>

using namespace std;

int findMin(const vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    if (nums[left] < nums[right]) {
        return nums[left];
    }

    while (left < right) {
        int mid = (left + right) / 2;

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return nums[left];
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    int min_element = findMin(nums);
    cout << min_element << endl;

    return 0;
}
