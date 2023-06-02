#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxCount(int m, int n, vector<vector<int>>& ops) {
    int minX = m;
    int minY = n;
    
    for (auto& op : ops) {
        minX = min(minX, op[0]);
        minY = min(minY, op[1]);
    }
    
    return minX * minY;
}

int main() {
    int m = 3;
    int n = 3;
    vector<vector<int>> ops = {{2, 2}, {3, 3}};
    
    int count = maxCount(m, n, ops);
    
    cout << "Output: " << count << endl;
    
    return 0;
}
