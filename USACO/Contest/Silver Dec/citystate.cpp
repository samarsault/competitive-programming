#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;

typedef pair<string,string> pss;

map<string, multiset<string> > mp; // mp['SC'] = all cities in SC (codes)

int main()
{
	int i, n;
	ifstream fin("citystate.in");
	ofstream fout("citystate.out");
	
	fin >> n;
	string city , state, city_code;
	vector<pss> vp; // (city code, state code)
	
	// O(n log n)
	for (i = 0; i < n; ++i) 
	{
		fin >> city >> state;
		city_code = city.substr(0, 2); // city code
		
		if (mp.find(state) == mp.end())
			mp.insert(make_pair(state, multiset<string>{ city_code }));
		else
			mp[state].insert(city_code);
		
		vp.push_back(make_pair(state, city_code));
	}

	int count = 0;

	// O(n log n)
	for (i = 0;i < n;i++)
	{
		string s1 = vp[i].first;
		string c1 = vp[i].second;
		if (c1 == s1) continue; // MISTAKE: Not from the same state
		if (mp.find(c1) != mp.end())
			count += mp[c1].count(s1);
	}
	
	fout << count / 2 << endl;
	
	return 0;
}
