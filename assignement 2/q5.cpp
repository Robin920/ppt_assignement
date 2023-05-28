#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();

    int product1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
    int product2 = nums[0] * nums[1] * nums[n - 1];
    int product3 = nums[0] * nums[1] * nums[2];

    return max(product1, max(product2, product3));
}

int main() {

    vector<int> nums = {1, 2, 3};

    int maxProduct = maximumProduct(nums);
    cout << "Output: " << maxProduct << endl;

    return 0;
}
