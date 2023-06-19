#include <iostream>
#include <stack>
using namespace std;

void printPrevSmaller(int arr[], int n)
{
	stack<int> S;

	for (int i=0; i<n; i++)
	{
		while (!S.empty() && S.top() >= arr[i])
			S.pop();

		if (S.empty())
			cout << "-1, ";
		else 
			cout << S.top() << ", ";

		S.push(arr[i]);
	}
}

int main()
{
	int arr[] = {1, 6, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	printPrevSmaller(arr, n);
	return 0;
}
