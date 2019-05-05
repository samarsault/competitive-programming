#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;

typedef pair<int,int> pii;

map<int, multiset<int> > mp; // K[i] = { all j such that (i, j) in S }
// K[i] = all pairs with first element i

int main()
{
	int i, j,p,n;
	
	cin >> n;
	vector<pii> vp; 
	//(1,2) AND (2,1), (3,4) AND (4, 3), (5,8) AND (8, 5), (2,3) AND (3,2)	
	// O(n log n)
	for (p = 0; p < n; ++p) 
	{
		cin >> i >> j;
		
		if (mp.find(i) == mp.end())
			mp.insert(make_pair(i, multiset<int>{ j }));
		else
			mp[i].insert(j);
		
		vp.push_back(make_pair(i , j));
	}

	cout << "K_i = all pairs with first element i" << endl;
	for (map<int, multiset<int> >::iterator it = mp.begin();it!=mp.end();it++)
	{
		cout << "K_" << it->first << " = { ";
		for (multiset<int>::iterator i = (it->second).begin();i != it->second.end();i++)
			cout << *i << ' ';
		cout << "}" << endl;
	}

	long long count = 0;

	// O(n log n)
	for (p = 0;p < n;p++)
	{
		i = vp[p].first;
		j = vp[p].second;
		count += mp[j].count(i);
	}
	
	cout << count / 2 << endl;
	return 0;
}
