#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <iterator>

#define all(X) X.begin(), X.end()

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;

int main(void)
{
	deque<int> Q;
	int n, k;
	cin >> n;
	vi a(n);
	for (int i = 0;i < n;i++)
		cin >> a[i];
	cin >> k;
	for (int i = 0;i < n;i++)
	{
		while (!Q.empty() && a[Q.back()] < a[i])
			Q.pop_back();
		while (!Q.empty() && Q.front() < i - k)
			Q.pop_front();
		Q.push_back(i);
		if (i >= k-1)
			cout << a[Q.front()]<< ' ';
	}
	cout << endl;
}
