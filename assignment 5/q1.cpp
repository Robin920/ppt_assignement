#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> convertTo2DArray(vector<int>& original, int m, int n) {
    int size = original.size();
    if (m * n != size) {
        return {};
    }
    
    vector<vector<int>> result(m, vector<int>(n));
    int index = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = original[index++];
        }
    }
    
    return result;
}

int main() {
    vector<int> original = {1, 2, 3, 4};
    int m = 2;
    int n = 2;
    
    vector<vector<int>> result = convertTo2DArray(original, m, n);
    
    if (result.empty()) {
        cout << "Unable to create a valid 2D array." << endl;
    } else {
        cout << "Output: [";
        for (const auto& row : result) {
        	cout<<" [";
            for (int num : row) {
                cout << num << " ";
            }
            cout <<"] ";
        }
        cout<<"]";
    }
    
    return 0;
}
