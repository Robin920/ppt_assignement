#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    vector<int> result;
    int i = 0, j = 0, k = 0;
    
    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            result.push_back(arr1[i]);
            i++;
            j++;
            k++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr3[k]) {
            j++;
        } else {
            k++;
        }
    }
    
    return result;
}
int main(){
	vector<int> arr1 = {1,2,3,4,5}, arr2 = {1,2,5,7,9}, arr3 = {1,3,4,5,8};
	vector<int> ans = commonElements(arr1, arr2, arr3);
	cout<<"Output: [";
	for(auto it:ans){
		cout<<" "<<it<<" ";
	}
	cout<<"]";
	return 0;
}