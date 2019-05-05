/*
ID: samarjeet
LANG: C++
TASK: milk
*/
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	// Open File
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int N, M, cost = 0, units = 0;
	fin >> N >> M;

	vector< pair<int, int> > vp (M);

	for (int i = 0;i < M;i++)
		fin >> vp[i].first >> vp[i].second;

	sort(vp.begin(), vp.end());

	int i = 0;
	while (i < M && units != N)
	{
		if (vp[i].second <= (N - units))
		{
			cost += vp[i].first * vp[i].second;
			units += vp[i].second;
		}
		else
		{
			cost += vp[i].first * (N - units);
			units += (N - units);
		}
		i++;
	}

	fout << cost << endl;

	// Close File
	fin.close();
	fout.close();

	return 0;
}