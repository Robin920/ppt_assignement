#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x);

void printUnion(int arr1[], int arr2[], int m, int n)
{
	if (m > n) {
		int* tempp = arr1;
		arr1 = arr2;
		arr2 = tempp;

		int temp = m;
		m = n;
		n = temp;
	}


	sort(arr1, arr1 + m);
	for (int i = 0; i < m; i++)
		cout << arr1[i] << " ";

	for (int i = 0; i < n; i++)
		if (binarySearch(arr1, 0, m - 1, arr2[i]) == -1)
			cout << arr2[i] << " ";
}


void printIntersection(int arr1[], int arr2[], int m, int n)
{
	if (m > n) {
		int* tempp = arr1;
		arr1 = arr2;
		arr2 = tempp;

		int temp = m;
		m = n;
		n = temp;
	}


	sort(arr1, arr1 + m);

	for (int i = 0; i < n; i++)
		if (binarySearch(arr1, 0, m - 1, arr2[i]) != -1)
			cout << arr2[i] << " ";
}


int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		if (arr[mid] == x)
			return mid;


		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		return binarySearch(arr, mid + 1, r, x);
	}

	return -1;
}


int main()
{
	int arr1[] = { 1,2,2,1 };
	int arr2[] = { 2,2 };
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	cout << "Union of two arrays is " << endl;
	printUnion(arr1, arr2, m, n);
	cout << endl;
	cout << "Intersection of two arrays is " << endl;
	printIntersection(arr1, arr2, m, n);
	return 0;
}
