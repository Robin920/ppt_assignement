#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();

    for (int i = n - 1; i >= 0; i--) {

        digits[i]++;

        if (digits[i] < 10) {
            return digits;
        }

        digits[i] = 0;
    }

    digits.insert(digits.begin(), 1);
    
    return digits;
}

int main(){
	vector<int> digits = {1,2,3};
	cout<<"Output: [";
	digits = plusOne(digits);
	for(auto it:digits){
		cout<<" "<<it<<" ";
	}
	cout<<"]";
	return 0;
}
