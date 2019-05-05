#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second < p2.second;
}

int main(void)
{
	int i, j, n;
	cin >> n;
	vector<pair<int, int> > p(n);
	
	for (i = 0;i < n;i++)
		cin >> p[i].first >> p[i].second;

	sort(p.begin(), p.end(), cmp);
	// solution set
	vector<int> S;

	while (p.size())
	{
		j = p.begin()->second;
		S.push_back(j);
		for (vector<pair<int,int> >::iterator it = p.begin();it != p.end();)
		{
			if (j <= it->second && j >= it->first)
				p.erase(it);
			else
				it++;
		}
	}

	// output
	cout << S.size() << endl;
}
