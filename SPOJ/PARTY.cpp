#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pi pair<int, int>
#define vpi vector<pair <int, int> >

bool cmp2(pi p1, pi p2)
{
	if (p1.second == p2.second)
		return p1.first < p2.first;

	return p1.second > p2.second;
}

int main(int argc, char const *argv[])
{
	while (true)
	{
		int B, N;
		cin >> B >> N;
		
		if (B == 0 && N == 0)
			break;

		vector< pi > vp(N);
	
		for (int i = 0; i < N; ++i)
			cin >> vp[i].first >> vp[i].second;

		sort(vp.begin(), vp.end(), cmp2);

		int i = 0, sum = 0, sumf = 0;
		while (i < N && sum != B)
		{
			if (sum + vp[i].first <= B)
			{
				sum += vp[i].first;
				sumf += vp[i].second;
			}
			i++;
		}
		cout << sum << ' ' << sumf <<  endl;
	}
	return 0;
}