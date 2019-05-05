#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> vi;

class ClassScores
{
public:
	vi findMode(vi);
};

vi ClassScores::findMode(vi v)
{
	map<int,int> mp;
	int mx = 0;
	for(int i = 0, l = v.size();i < l;i++)
	{
		if (mp.find(v[i]) == mp.end())
			mp[v[i]] = 1;
		else
			mp[v[i]]++;
		mx = max(mp[v[i]], mx);
	}
	
	vi result;
	for (map<int, int>::iterator it = mp.begin();it!=mp.end();it++)
		if (it->second == mx)
			result.push_back(it->first);
	return result;
}
