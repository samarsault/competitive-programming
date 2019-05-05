/*
 * Siruseri Sports Stadium (Event Scheduling)
 * IARCS Sept 2004
 * Dynamic Programming O(n^2) Solution
 *
 */
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// sort according to ending times
bool cmp(pair<int, int> pa, pair<int, int> pb)
{
	return pa.second < pb.second;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	int n, a, b;
	cin >> n;

	vector<pair<int, int> > M;

	for (int i = 0;i < n;i++)
	{
		// a - start, b - length
		cin >> a >> b;
		// M[i] = (start, end)
		M.push_back(make_pair(a, a + b));
	}

	// sort according to ending times
	sort(M.begin(), M.end(), cmp);

	int ans = 0;
	int pend = -1;

	for (int i = 0;i < n;i++)
	{
		if (M[i].first > pend)
		{
			pend = M[i].second;
			ans++;
		}
	}

	cout << ans << endl;
}
