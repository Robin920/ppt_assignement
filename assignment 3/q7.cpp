#include <bits/stdc++.h>
using namespace std;

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> result;

    auto addRange = [&](int start, int end) {
        result.push_back("["+to_string(start) + "," + to_string(end)+"]");
    };

    if (nums[0] > lower) {
        addRange(lower, nums[0] - 1);
    }

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1] + 1) {
            addRange(nums[i - 1] + 1, nums[i] - 1);
        }
    }

    if (nums.back() < upper) {
        addRange(nums.back() + 1, upper);
    }
    
    return result;
}

int main(){
	vector<int> nums = {0,1,3,50,75};
	int lower = 0, upper = 99;
	
	vector<string> ans = findMissingRanges(nums,lower,upper);
	cout<<"Output: ";
	for(auto it: ans){
		cout<<" "<<it<<" ";
	}
	
	return 0;
}
