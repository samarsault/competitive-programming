/*
ID: samarjeet
LANG: C++
TASK: ariprog
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second < p2.second;
}

int main(int argc, char const *argv[])
{
	// Open File
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");
	
	int n, m;
	fin >> n >> m;

	// set of bisquares
	set<int> S;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < m;j++)
			S.insert(i*i + j * j);

	vector<pair<int, int> > sol;
	
	for (set<int>::iterator it = S.begin();it != S.end();it++)
	{
		for (int d = 1;d < 250;d++)
		{
			int l = 1;
			int curr = *it;
			
			while (l < n)
			{	
				if (*S.find(curr + d))
				{
					curr += d;
					l++;
				}
				else
				{
					break;
				}
			}

			if (l == n)
				sol.push_back(make_pair(*it, d));
		}
	}

	sort(sol.begin(), sol.end(), cmp);

	for (int i = 0, l = sol.size();i < l;i++)
		cout << sol[i].first << ' ' << sol[i].second << endl;

	// Close File
	fin.close();
	fout.close();

	return 0;
}
