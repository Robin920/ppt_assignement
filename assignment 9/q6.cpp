#include<bits/stdc++.h>
using namespace std;

int nAp(int a, int d,int N){
	if (N == 1) {
        return a; 
    } else {
        int prevTerm = nAp(a, d, N - 1); 
        return prevTerm + d; 
    }
}

int main(){
	int a = 2,d = 1, N = 5;
	
	cout<<"Output: "<<nAp(a,d,N);
	return 0;
}