#include <iostream>
#include <vector>
#include <string>

using namespace std;

int compress(vector<char>& chars) {
    int read = 0;
    int write = 0;
    int count = 1;

    while (read < chars.size()) {
        if (read + 1 == chars.size() || chars[read] != chars[read + 1]) {
            chars[write] = chars[read];
            write++;

            if (count > 1) {
                string countStr = to_string(count);
                for (char digit : countStr) {
                    chars[write] = digit;
                    write++;
                }
            }

            count = 1;
        } else {
            count++;
        }

        read++;
    }

    return write;
}

int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int compressedLength = compress(chars);

    cout << "Compressed Length: " << compressedLength << endl;
    cout << "Compressed Array: ";
    for (int i = 0; i < compressedLength; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}
