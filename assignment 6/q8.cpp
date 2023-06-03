#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
    int m = mat1.size();
    int k = mat1[0].size();
    int n = mat2[0].size();

    vector<vector<int>> result(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int l = 0; l < k; l++) {
                if (mat1[i][l] != 0 && mat2[l][j] != 0) {
                    sum += mat1[i][l] * mat2[l][j];
                }
            }
            result[i][j] = sum;
        }
    }

    return result;
}

void printMatrix(const vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    cout<<"Output: [";
    for (int i = 0; i < m; i++) {
    	cout<<" [";
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout <<"] ";
    }
    cout<<"]";
}

int main() {
    vector<vector<int>> mat1 = {{1, 0, 0}, {-1, 0, 3}};
    vector<vector<int>> mat2 = {{7, 0, 0}, {0, 0, 0}, {0, 0, 1}};

    vector<vector<int>> result = multiply(mat1, mat2);
    printMatrix(result);

    return 0;
}
