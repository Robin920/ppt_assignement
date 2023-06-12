#include <bits/stdc++.h>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> result;
    int n1 = nums1.size();
    int n2 = nums2.size();

    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (nums1[i] == nums2[j]) {
            result.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = intersect(nums1, nums2);

    cout << "Output: [ ";
    for (int num : result) {
        cout << num << " ";
    }
    cout <<"]";

    return 0;
}
