#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> findMissingNumbers(vector<int>& nums1, vector<int>& nums2) {
    vector<int> missingNums1, missingNums2;
    unordered_set<int> numSet(nums2.begin(), nums2.end());

    for (int num : nums1) {
        if (numSet.find(num) == numSet.end()) {
            missingNums1.push_back(num);
        }
    }

    numSet.clear();
    numSet.insert(nums1.begin(), nums1.end());

    for (int num : nums2) {
        if (numSet.find(num) == numSet.end()) {
            missingNums2.push_back(num);
        }
    }

    return {missingNums1, missingNums2};
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    vector<vector<int>> missingNumbers = findMissingNumbers(nums1, nums2);

    cout << "Missing numbers in nums1: ";
    for (int num : missingNumbers[0]) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Missing numbers in nums2: ";
    for (int num : missingNumbers[1]) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
