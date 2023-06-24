#include <bits/stdc++.h>
using namespace std;


void Union(int a[], int b[], int n, int m)
{
	int* result = new int[n + m];

	int index = 0;
	int left = 0, right = 0;
	while (left < n && right < m) {

		if (a[left] < b[right]) {
			if (index != 0
				&& a[left] == result[index - 1]) {
				left++;
			}
			else {
				result[index] = a[left];
				left++;
				index++;
			}
		}
		else {
			if (index != 0
				&& b[right] == result[index - 1]) {
				right++;
			}
			else {
				result[index] = b[right];
				right++;
				index++;
			}
		}
	}

	while (left < n) {
		if (index != 0 && a[left] == result[index - 1]) {
			left++;
		}
		else {
			result[index] = a[left];
			left++;
			index++;
		}
	}

	while (right < m) {
		if (index != 0 && b[right] == result[index - 1]) {
			right++;
		}
		else {
			result[index] = b[right];
			right++;
			index++;
		}
	}

	cout << "Union: ";
	for (int k = 0; k < index; k++)
		cout << result[k] << " ";
	cout << endl;
};


void intersection(int a[], int b[], int n, int m)
{

	int i = 0, j = 0, k = 0;
	int* result = new int[n + m];
	while (i < n && j < m) {
		if (a[i] < b[j])
			i++;
		else if (a[i] > b[j])
			j++;
		else {
			if (k != 0 && a[i] == result[k - 1]) {
				i++;
				j++;
			}
			else {
				result[k] = a[i];
				i++;
				j++;
				k++;
			}
		}
	}
	cout << "Intersection: ";
	for (int x = 0; x < k; x++)
		cout << result[x] << " ";
	cout << endl;
}


int main()
{
	int a[] = { 1,2,2,1 };
	int b[] = { 2,2 };

	int n = sizeof(a) / sizeof(a[0]);
	int m = sizeof(b) / sizeof(b[0]);

	sort(a, a + n);
	sort(b, b + m);

	Union(a, b, n, m);
	intersection(a, b, n, m);
}