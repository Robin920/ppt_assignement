#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int distributeCandies(vector<int>& candyType) {
    int n = candyType.size();
    int maxCandies = n / 2;

    unordered_set<int> uniqueCandies;

    for (int i = 0; i < n; i++) {
        uniqueCandies.insert(candyType[i]);
    }

    int mpSize = uniqueCandies.size();
    return min(maxCandies, mpSize);
}

int main() {

    vector<int> candyType = {1, 1, 2, 2, 3, 3};
    int maxNum = distributeCandies(candyType);

    cout << "Output: " << maxNum <<endl;

    return 0;
}
