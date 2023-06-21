#include<bits/stdc++.h>
using namespace std;

	void deleteMid(stack<char>&s, int sizeOfStack, int current)
	{
		if(current==sizeOfStack/2)
		{
			s.pop();
			return;
		}
		
		int x = s.top();
		s.pop();
		current+=1;

		deleteMid(s,sizeOfStack,current);
		
		s.push(x);
	}


int main()
{
	stack<char> st;

	st.push('5');
	st.push('4');
	st.push('3');
	st.push('2');
	st.push('1');

	deleteMid(st, st.size(),0);
    cout<<"Output: [";
	while (!st.empty())
	{
		char p=st.top();
		st.pop();
		cout << p << " ";
	}
	cout<<"]";
	return 0;
}