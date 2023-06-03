#include<bits/stdc++.h>
using namespace std;

int maxNum(int arr[], int n,int maxi){
	if(n < 0){
		return maxi;
	}
	
	maxi = max(maxi, arr[n]);
	return maxNum(arr,n-1,maxi);
}

int main(){
	int arr[] = {1, 4, 3, -5, -4, 8, 6};
	int maxi = arr[0];
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Output: "<<maxNum(arr, n-1,maxi);
	return 0;
}