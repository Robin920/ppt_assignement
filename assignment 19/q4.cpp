#include <bits/stdc++.h>
using namespace std;

void move_zeros_to_right(vector<int>& m)
{
	int count = 0;
	int length=m.size();
	for (int i = 0; i < length; i++) {
		if (m[i] == 0) {
			count++;
			m.erase(m.begin() + i);
			i--;
			length--;
		}
	}

	for (int i = 0; i < count; i++) {
		m.push_back(0);
	}
	cout << "array after shifting zeros to right side: "
		<< endl;
	for (int i = 0; i < m.size(); i++) {
		cout << m[i] << " ";
	}
}

int main()
{
	vector<int> m{ 1, 2, 0, 4, 3, 0, 5, 0 };

	move_zeros_to_right(m);
	return 0;
}
