#include <iostream>
#include <string>

using namespace std;

int stringLength(string str) {
 
    if (str == "")
        return 0;

    return 1 + stringLength(str.substr(1));
}

int main() {
    string str = "Hello, World!";
    int length = stringLength(str);
    cout << "Length of the string: " << length << endl;

    return 0;
}
