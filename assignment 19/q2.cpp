#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int, int> >& v, vector<int>& ans,
		int l, int mid, int h)
{
	vector<pair<int, int> >
		t; 
	int i = l;
	int j = mid + 1;

	while (i < mid + 1 && j <= h) {

		if (v[i].first > v[j].first) {
			ans[v[i].second] += (h - j + 1);
			t.push_back(v[i]);
			i++;
		}
		else {
			t.push_back(v[j]);
			j++;
		}
	}

	while (i <= mid)
		t.push_back(v[i++]);

	while (j <= h)
		t.push_back(v[j++]);

	for (int k = 0, i = l; i <= h; i++, k++)
		v[i] = t[k];
}

void mergesort(vector<pair<int, int> >& v, vector<int>& ans,
			int i, int j)
{
	if (i < j) {
		int mid = (i + j) / 2;

		mergesort(v, ans, i, mid);

		mergesort(v, ans, mid + 1, j);

		merge(v, ans, i, mid, j);
	}
}

vector<int> constructLowerArray(int* arr, int n)
{
	vector<pair<int, int> > v;

	for (int i = 0; i < n; i++)
		v.push_back({ arr[i], i });

	vector<int> ans(n, 0);

	mergesort(v, ans, 0, n - 1);

	return ans;
}

int main()
{
	int arr[] = { 5,2,6,1 };
	int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Output: [ ";
	auto ans = constructLowerArray(arr, n);
	for (auto x : ans) {
		cout << x << " ";
	}
	cout << " ]";
	return 0;
}