#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<vector<int>> findMissingNumbers(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    vector<int> missingInNums1, missingInNums2;
    
    for (int num : nums1) {
        if (set2.find(num) == set2.end()) {
            missingInNums2.push_back(num);
        }
    }
    
    for (int num : nums2) {
        if (set1.find(num) == set1.end()) {
            missingInNums1.push_back(num);
        }
    }
    
    return {{missingInNums1.begin(), missingInNums1.end()}, {missingInNums2.begin(), missingInNums2.end()}};
}

int main(){
	vector<int> nums1 = {1,2,3}, nums2 = {2,4,6};
	vector<vector<int>> ans = findMissingNumbers(nums2,nums1);
	
	cout<<"Output: [";
	for(auto it:ans){
		cout<<" [";
		for(auto i:it){
			cout<<" "<<i<<" ";
		}
		cout<<"] ";
	}
	cout<<"]";
	return 0;
}
