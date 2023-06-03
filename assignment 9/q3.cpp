#include<bits/stdc++.h>
using namespace std;

int facto(int N){
	if(N == 0){
		return 1;
	}
	
	return N*facto(N-1);
}

int main(){
	int N = 5;
	
	cout<<"Output: "<<facto(N);
	return 0;
}