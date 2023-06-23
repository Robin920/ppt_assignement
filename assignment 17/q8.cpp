#include <iostream>
#include <vector>

using namespace std;

class DataStream {
public:
    DataStream(int value, int k) : value(value), k(k), buffer(k, 0), count(0), currentIndex(0) {}

    bool consec(int num) {
        buffer[currentIndex] = num;
        currentIndex = (currentIndex + 1) % k;
        count++;

        if (count < k) {
            return false;
        }

        for (int i = 0; i < k; i++) {
            if (buffer[i] != value) {
                return false;
            }
        }

        return true;
    }

private:
    int value;
    int k;
    vector<int> buffer;
    int count;
    int currentIndex;
};

int main() {
    DataStream ds(4, 3);

    cout << boolalpha;
    cout << ds.consec(4) << endl;  
    cout << ds.consec(4) << endl; 
    cout << ds.consec(4) << endl;  
    cout << ds.consec(3) << endl;  

    return 0;
}
