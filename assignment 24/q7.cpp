// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;

void printKMax(int arr[], int N, int K)
{

	deque<int> Qi(K);

	int i;
	for (i = 0; i < K; ++i) {

		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])

			Qi.pop_back();

		Qi.push_back(i);
	}

	for (; i < N; ++i) {

		cout << arr[Qi.front()] << " ";

		while ((!Qi.empty()) && Qi.front() <= i - K)

			Qi.pop_front();

		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
			Qi.pop_back();

		Qi.push_back(i);
	}

	cout << arr[Qi.front()];
}

int main()
{
	int arr[] = { 1,3,-1,-3,5,3,6,7 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 3;

    cout<<"Output: [ ";
	printKMax(arr, N, K);
	cout<<" ]";
	return 0;
}
