#include <bits/stdc++.h>
using namespace std;

bool validMountainArray(vector<int>& arr) {
    int n = arr.size();
    int i = 0;

    if (n < 3) {
        return false;
    }

    while (i < n - 1 && arr[i] < arr[i + 1]) {
        i++;
    }

    if (i == 0 || i == n - 1) {
        return false;
    }

    while (i < n - 1 && arr[i] > arr[i + 1]) {
        i++;
    }

    return i == n - 1;
}

int main() {
    vector<int> arr = {2, 1};

    bool isValid = validMountainArray(arr);

    if (isValid) {
        cout << "The array is a valid mountain array." << endl;
    } else {
        cout << "The array is not a valid mountain array." << endl;
    }

    return 0;
}




