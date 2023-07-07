#include <bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n)
{
int pow[40] = { 1 };

for (int i = 1; i <= 30; ++i)
	pow[i] = pow[i - 1] * 2;

int l = 1, r = 2147483647;

int ans = -1;

while (l <= r) {
	int mid = l + ((r - l) / 2);

	int cnt = 0;

	for (long long i = 1; i <= mid; i *= 5)

	{
	for (long long j = 1; j * i <= mid; j *= 3)

	{
		cnt += upper_bound(pow, pow + 31,
						mid / (i * j)) - pow;
	}
	}

	if (cnt < n)
	l = mid + 1;

	else
	r = mid - 1, ans = mid;
}

return ans;
}

int main()
{
	
	int n = 10;

	cout <<"Output: "<< nthUglyNumber(n);
	return 0;
}
