#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minimumScore(vector<int>& nums, int k) {
    int n = nums.size();
    
    sort(nums.begin(), nums.end());

    int minScore = nums[n - 1] - nums[0];

    for (int i = 1; i < n; i++) {
        int minValue = nums[i] - k;
        int maxValue = nums[i - 1] + k;
        minScore = min(minScore, maxValue - minValue); 
    }

    return minScore;
}

int main() {
    vector<int> nums = {1};
    int k = 0;

    int minScore = minimumScore(nums, k);

    cout << "Output: " << minScore << endl;

    return 0;
}
