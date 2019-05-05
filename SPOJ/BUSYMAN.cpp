#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second < p2.second;
}

int main(int argc, char const *argv[])
{
	int T, N, start, end;
	cin >> T;

	while (T--)
	{
		cin >> N;
		vector< pair<int, int> > vp;
		for (int i = 0;i < N;i++)
		{
			cin >> start >> end;
			vp.push_back(make_pair(start, end));
		}

		// sort by end times
		sort(vp.begin(), vp.end(), cmp);

		// no. of activities
		// at least 1
		int act = 1;
		// last activity selected
		int j = 0;
		for (int i = 1;i < N;i++)
		{
			// vp[i].first = start time of activity i
			// vp[j].second = end time of activity j
			// we can select activity i only if activity j has been completed
			if (vp[i].first >= vp[j].second)
			{
				act++;
				// update last activity selected
				j = i;
			}
		}
		cout << act << endl;
	}
	return 0;
}