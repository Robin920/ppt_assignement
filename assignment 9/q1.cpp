#include<bits/stdc++.h>
using namespace std;

int isPowTwo(int n){
	if(n == 1){
		return true;
	}
	if(n%2 != 0){
		return false;
	}
	
	return isPowTwo(n/2);
}

int main(){
	int n = 81;
	
	if(isPowTwo(n)){
		cout<<"Output: True";
	}else
	{
		cout<<"Output: False";
	}
	return 0;
}