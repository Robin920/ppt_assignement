#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
	int n = nums.size();
	vector<int> ans;

	ans.push_back(nums[0]);

	for (int i = 1; i < n; i++) {
		if (nums[i] > ans.back()) {
			ans.push_back(nums[i]);
		}
		else {
			int low = lower_bound(ans.begin(), ans.end(),
								nums[i])
					- ans.begin();

			ans[low] = nums[i];
		}
	}

	return ans.size();
}

int main()
{
	vector<int> nums = { 10,9,2,5,3,7,101,18 };

	cout<<"Length of LIS: "<< lengthOfLIS(nums);
	return 0;
}