#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> quadruplets;
    int n = nums.size();
    
    if (n < 4) {
        return quadruplets;
    }
    
    sort(nums.begin(), nums.end());  
    
    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;  // Skip duplicates for the first number
        }
        
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;  // Skip duplicates for the second number
            }
            
            int left = j + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                
                if (sum == target) {
                    quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                    
                    // Skip duplicates for the third number
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    
                    // Skip duplicates for the fourth number
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    left++;
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
    }
    
    return quadruplets;
}

int main(){
	vector<int> nums ={1,0,-1,0,-2,2};
	int target = 0;
	
	cout<<"Output: [ ";
	vector<vector<int>> ans = fourSum(nums,target);
	for(auto& it: ans){
		cout<<"[";
		for(auto& itt: it){
			cout<<itt<<" ";
		}
		cout<<"], ";
	}
	cout<<" ]";
	return 0;
}