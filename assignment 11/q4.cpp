#include <iostream>
#include <vector>
using namespace std;

int countRange(vector<int>& nums, int start, int end) {
    int count = 0;
    for (int num : nums) {
        if (num >= start && num <= end) {
            count++;
        }
    }
    return count;
}

int findDuplicate(vector<int>& nums) {
    int left = 1;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = countRange(nums, left, mid);

        if (count > mid - left + 1) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    int repeatedNum = findDuplicate(nums);
    cout << "Repeated number: " << repeatedNum << endl;

    return 0;
}
