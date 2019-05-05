// O(n^2) Qolution
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>

#define all(X) X.begin(), X.end()
#define mp(a,b) make_pair(a,b)

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<vi> vii;
typedef vector<ll> vll;

const int mxn = 1e5;
int n, k;

struct cmp
{
	bool operator()(pair<ll, pii> p1, pair<ll, pii> p2)
	{
		if (p1.first == p2.first)
			return p1.second.first < p2.second.first;
		return p1.first > p2.first;
	}
};

int main(void)
{
	cin >> n >> k;
	vll a(n+1, 0 ), pre(n+1, 0);

	for (int i =1 ;i  <= n;i++) {
		cin >> a[i];
		pre[i] = pre[i-1] + a[i];
	}

	set < pair<ll, pii > , cmp> S;
	S.insert( mp(pre[n], mp(1, n) ) );

	while (k-- && !S.empty())
	{
		auto top = *S.begin();
		S.erase(top);
		cout << top.first << ' ';
		int l = top.second.first, r = top.second.second;
		if (l != r) {
			S.insert(mp(pre[r-1] - pre[l-1], mp(l, r - 1)));
			S.insert(mp(pre[r] - pre[l], mp(l + 1, r)));
		}
	}
	cout << endl;
}