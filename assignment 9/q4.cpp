#include<bits/stdc++.h>
using namespace std;

int expo(int N,int P){
	if(P == 0){
		return 1;
	}
	
	return N*expo(N,P-1);
}

int main(){
	int N = 2;
	int P = 5;
	cout<<"Output: "<<expo(N,P);
	return 0;
}