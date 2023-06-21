#include <bits/stdc++.h>

using namespace std;

void reverseFirstK(queue<int>& q, int k)
{
	deque<int> d;

	for (int i = 0; i < k; i++) {
		d.push_front(q.front());
		q.pop();
	}

	while (!d.empty()) {
		q.push(d.front());
		d.pop_front();
	}

	for (int i = 0; i < q.size() - k; i++) {
		q.push(q.front());
		q.pop();
	}
}

int main()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);
	q.push(70);
	q.push(80);
	q.push(90);
	q.push(100);

	int k = 5;

	reverseFirstK(q, k);

    cout<<"Output: ";
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}