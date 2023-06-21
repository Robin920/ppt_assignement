#include<bits/stdc++.h>
using namespace std;

stack<int> st;

int stack_reverse(int num){
	while(num != 0){
		st.push(num%10);
		num = num/10;
	}
	
	int reverse = 0,i = 1;
	
	while(!st.empty()){
		reverse = reverse + (st.top()*i);
		st.pop();
		i = i*10;
	}
	
	return reverse;
}
int main(){
	int num = 6899;
	
	cout<<"Reversed number: "<<stack_reverse(num);
	return 0;
}