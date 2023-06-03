#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int num = 1;
    int rowStart = 0, rowEnd = n - 1;
    int colStart = 0, colEnd = n - 1;

    while (num <= n * n) {
        for (int i = colStart; i <= colEnd; i++) {
            matrix[rowStart][i] = num++;
        }
        rowStart++;

        for (int i = rowStart; i <= rowEnd; i++) {
            matrix[i][colEnd] = num++;
        }
        colEnd--;

        for (int i = colEnd; i >= colStart; i--) {
            matrix[rowEnd][i] = num++;
        }
        rowEnd--;

        for (int i = rowEnd; i >= rowStart; i--) {
            matrix[i][colStart] = num++;
        }
        colStart++;
    }

    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    cout<<"Output: [";
    for (int i = 0; i < n; i++) {
    	cout<<" [";
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout <<"] ";
    }
    cout<<"]";
}

int main() {
    int n = 3;

    vector<vector<int>> matrix = generateMatrix(n);
    printMatrix(matrix);

    return 0;
}
