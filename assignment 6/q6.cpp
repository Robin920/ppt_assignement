#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findOriginalArray(vector<int>& changed) {
    if (changed.size() % 2 != 0) {
        return {}; 
    }
    
    vector<int> original;
    unordered_map<int, int> counts;

    for (int num : changed) {
        counts[num]++;
    }

    for (int num : changed) {
        if (counts[num] == 0) {
            continue; // Skip if the current element has been used
        }
        
        int doubleNum = num * 2;
        
        if (counts[doubleNum] == 0) {
            return {};
        }

        original.push_back(num);
        counts[num]--;
        counts[doubleNum]--;
    }

    if (original.size() != changed.size() / 2) {
        return {};
    }
    
    return original;
}

int main() {
    vector<int> changed = {1, 3, 4, 2, 6, 8};
    vector<int> original = findOriginalArray(changed);
    
    cout << "Output: [";
    for (int num : original) {
        cout << num << " ";
    }
    cout <<"]";
    
    return 0;
}
