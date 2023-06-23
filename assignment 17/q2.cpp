#include <bits/stdc++.h>

using namespace std;

int kadane(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        currentSum += nums[i];
        if (currentSum < nums[i]) {
            currentSum = nums[i];
        }
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    return maxSum;
}

int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();

    int maxNonCircularSum = kadane(nums);

    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += nums[i];
        nums[i] = -nums[i];
    }

    int maxCircularSum = totalSum + kadane(nums);

    if (maxCircularSum <= 0) {
        return maxNonCircularSum;
    }

    return max(maxNonCircularSum, maxCircularSum);
}

int main() {
    vector<int> nums = {5,-3,5};
    int maxSum = maxSubarraySumCircular(nums);
    cout << "Maximum subarray sum: " << maxSum << endl;
    return 0;
}