#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

bool cmp(pii A, pii B)
{
	if (A.second == B.second)
		return A.first > B.first;
	return A.second > B.second;
}

int main(void)
{
	int i, n, a, b, c;
	cin >> n;
	vector<pii> vp;

	for (i = 0;i < n;i++)
	{
		cin >> a >> b >> c;
		vp.push_back(make_pair(a, b + c));
	}

	sort(vp.begin(), vp.end(), cmp);
	
	int ans = 0, prev = 0;
	for (i = 0;i < n;i++)
	{
		ans = max(ans, vp[i].first + vp[i].second + prev);
		prev += vp[i].first;
	}
	cout << ans << endl;

	return 0;
}
