#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums) {
    int maxLength = 0;
    int count = 0;
    unordered_map<int, int> countMap;
    countMap[0] = -1;

    for (int i = 0; i < nums.size(); i++) {
        count += (nums[i] == 1) ? 1 : -1;

        if (countMap.count(count) > 0) {
            maxLength = max(maxLength, i - countMap[count]);
        } else {
            countMap[count] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums = {0, 1};

    int maxLength = findMaxLength(nums);

    cout << "The maximum length of a contiguous subarray with an equal number of 0 and 1 is: " << maxLength << endl;

    return 0;
}