#include<bits/stdc++.h>
using namespace std;

int product(int arr[],int n){
	if(n == 0){
		return arr[0];
	}

	return arr[n]*product(arr,n-1);
}

int main(){
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Output: "<<product(arr,n-1);
	return 0;
}