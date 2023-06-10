#include <iostream>
#include <string>
using namespace std;

bool isConsonant(char c) {
    c = tolower(c);
    return (c >= 'a' && c <= 'z' && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

int countConsonants(string str) {
    int count = 0;
    for (char c : str) {
        if (isConsonant(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    string str = "geeksforgeeks portal";
    int consonantCount = countConsonants(str);
    cout << "Total number of consonants: " << consonantCount << endl;
    
    return 0;
}
