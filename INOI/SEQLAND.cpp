#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, k;
set<int> tmp;
vector<set<int> > V;
bool family[400];

void dfs(int i)
{
	for (int j = 0;j < n;j++)
	{
		if (!family[j])
		{
			tmp.clear();
			set_intersection(V[i].begin(), V[i].end(), V[j].begin(), V[j].end(), std::inserter(tmp, tmp.begin()));
			
			if (tmp.size() >= k)
			{
				family[j] = true;
				dfs(j);
			}
		}
	}
}

int main(void)
{
	int i, p, t;
	cin >> n >> k;
	V.resize(n);
	fill(family, family + 400, false);
	for (i = 0;i < n;i++)
	{
		cin >> p;
		while (p--)
		{
			cin >> t;
			V[i].insert(t);
		}
	}

	family[0] = true;
	dfs(0);
	int ans = 0;
	for (i = 0;i < n;i++)
		ans += family[i];
	cout << ans << endl;
	return 0;
}
