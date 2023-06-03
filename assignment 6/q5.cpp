#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minProductSum(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int left = 0;
    int right = nums1.size() - 1;
    int minProductSum = 0;

    for (int i = nums2.size() - 1; i >= 0; i--) {
        minProductSum += nums2[i] * nums1[left++];
    }

    return minProductSum;
}

int main() {
    vector<int> nums1 = {5, 3, 4, 2};
    vector<int> nums2 = {4, 2, 2, 5};

    int result = minProductSum(nums1, nums2);
    cout << "Minimum Product Sum: " << result << endl;

    return 0;
}
