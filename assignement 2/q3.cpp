#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int findLHS(vector<int>& nums) {
    int maxLength = 0;

    unordered_map<int, int> frequencyMap;
    for (int num : nums) {
        frequencyMap[num]++;
    }

    for (auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
        int currentNum = it->first;
        int currentFreq = it->second;

        if (frequencyMap.count(currentNum + 1)) {
            maxLength = max(maxLength, currentFreq + frequencyMap[currentNum + 1]);
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums = {1, 3, 2, 2, 5, 3, 7};
    int maxLength = findLHS(nums);

    cout << "Output: " << maxLength << endl;

    return 0;
}
