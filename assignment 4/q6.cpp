#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> result(nums.size());
    int left = 0;
    int right = nums.size() - 1;
    int index = nums.size() - 1;
    
    while (left <= right) {
        if (abs(nums[left]) > abs(nums[right])) {
            result[index] = nums[left] * nums[left];
            left++;
        } else {
            result[index] = nums[right] * nums[right];
            right--;
        }
        index--;
    }
    
    return result;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    
    vector<int> squaredSorted = sortedSquares(nums);
    
    cout << "Output: [";
    for (int num : squaredSorted) {
        cout << num << " ";
    }
    cout <<"]"<< endl;
    
    return 0;
}
