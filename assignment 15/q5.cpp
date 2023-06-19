#include <bits/stdc++.h>
using namespace std;

void reverse(string &str){

stack<char>s;
for(auto it:str)s.push(it);

str.clear();

while(!s.empty()){
	str.push_back(s.top());
	s.pop();
}
}

int main() {
string str = "GeeksforGeeks";
reverse(str);
cout << "Reversed string is : " << str;
return 0;
}