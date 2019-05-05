#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<string,string> pss;

int main()
{
	ifstream fin("citystate.in");
	ofstream fout("citystate.out");

	int i, j, n;
	fin >> n;
	string c,s;
	vector<pss> vp;

	for (i = 0; i < n; ++i) 
	{
		fin >> c >> s;
		vp.push_back(make_pair(c.substr(0, 2), s));
	}

	long long count = 0;
	for (i = 0;i < n;i++)
		for (j = i + 1;j < n;j++)
			if ( vp[i].first == vp[j].second && vp[j].first == vp[i].second)
				count++;

	fout << count << endl;
	return 0;
}

