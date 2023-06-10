#include <iostream>
using namespace std;

void towerOfHanoi(int n, int source, int destination, int auxiliary, int& moves) {
    if (n == 1) {
        cout << "move disk 1 from rod " << source << " to rod " << destination << endl;
        moves++;
        return;
    }

    towerOfHanoi(n - 1, source, auxiliary, destination, moves);
    cout << "move disk " << n << " from rod " << source << " to rod " << destination << endl;
    moves++;
    towerOfHanoi(n - 1, auxiliary, destination, source, moves);
}

int main() {
    int N = 2;
    int moves = 0;
    towerOfHanoi(N, 1, 3, 2, moves);
    cout << "Total moves: " << moves << endl;

    return 0;
}
