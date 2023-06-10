#include <iostream>
#include <vector>

using namespace std;

int lastRemaining(int n) {
    bool leftToRight = true;
    int remaining = n;
    int step = 1;
    int head = 1;

    while (remaining > 1) {
        if (leftToRight || remaining % 2 == 1) {
            head += step;
        }

        remaining /= 2;
        step *= 2;
        leftToRight = !leftToRight;
    }

    return head;
}

int main() {
    int n = 9;

    int lastNum = lastRemaining(n);
    cout<<"Output: " << lastNum << endl;

    return 0;
}
