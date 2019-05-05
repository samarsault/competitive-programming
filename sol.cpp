#include <iostream>
#include <vector>
#include <algorithm>
#include<set>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<set<char> > V;
	long long dc[10];
	long long ans=0;
	fill(dc,dc+10,0);
	string s;
	for(int i = 0;i < n;i++)
	{
		cin >> s;
		set<char> S(s.begin(), s.end());
		if (V.find(V.begin(), V.end(), S) == V.end()){
			for (auto it = S.begin();it!=S.end();it++)
				dc[*it - '0']++;
			V.push_back(S);
		}
	}

	for (int i = 0;i < n;i++) {
		for (auto it = V[i].begin();it!=V[i].end();it++) {
			ans += dc[*it-'0'] - 1;
		}
	}
	cout << ans/2 << endl;
	return 0;
}
