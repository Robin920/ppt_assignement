#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    vector<vector<int>> transpose(cols, vector<int>(rows));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    
    return transpose;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    vector<vector<int>> transpose = transposeMatrix(matrix);
    
    cout << "Output: [";
    for (const vector<int>& row : transpose) {
    	cout<<" [";
        for (int num : row) {
            cout << num << " ";
        }
        cout <<"] ";
    }
    cout<<"]";
    
    return 0;
}
