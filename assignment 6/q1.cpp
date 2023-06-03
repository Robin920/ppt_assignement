#include <bits/stdc++.h>
using namespace std;

vector<int> diStringMatch(string s) 
    {
        vector<int> v1;
        int i=0,j=s.length();
        
        for(int k=0;k<s.length();k++){
            if(s[k]=='I'){v1.push_back(i);i++;}
            else{v1.push_back(j);j--;}
        }

        v1.push_back(j--);
        return v1;
    }
    
int main() {
    string s = "IDID";
    vector<int> perm = diStringMatch(s);

    cout << "Reconstructed Permutation: ";
    for (int num : perm) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}