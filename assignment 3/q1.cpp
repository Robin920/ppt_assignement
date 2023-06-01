#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end()); 

    int closestSum = nums[0] + nums[1] + nums[2]; 
    int minDiff = abs(closestSum - target); 

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int diff = abs(sum - target);

            if (diff < minDiff) {
                minDiff = diff;
                closestSum = sum;
            }

            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return closestSum;
}

int main(){
	vector<int> nums = {-1,2,1,-4};
	int target = 1;
	
	cout<<"Output: "<<threeSumClosest(nums,target);
	return 0;
}