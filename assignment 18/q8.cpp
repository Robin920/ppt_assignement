#include <bits/stdc++.h>
using namespace std;

bool recreationalSpot(int arr[], int n)
{
	vector<int> small;

	int min1 = arr[0];
	for (int i = 0; i < n; i++) {
		if (min1 >= arr[i]) {
			min1 = arr[i];

			small.push_back(-1);
		}
		else {

			small.push_back(min1);
		}
	}

	stack<int> s;

	for (int i = n - 1; i > 0; i--) {

		while (!s.empty() && s.top() <= small[i]) {
			s.pop();
		}

		if (!s.empty() && small[i] != -1
			&& s.top() < arr[i])
			return true;
		s.push(arr[i]);
	}

	return false;
}

int main()
{

	int arr[] = { 1,2,3,4 };
	int N = sizeof(arr) / sizeof(arr[0]);

    cout<<"Output: ";
	if (recreationalSpot(arr, N)) {
		cout << "True";
	}
	else {
		cout << "False";
	}
	return 0;
}
