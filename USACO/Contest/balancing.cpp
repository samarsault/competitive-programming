/*
ID: samarjeet27
LANG: C++
TASK: balancing
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// N and B
int N, B;
// Coordinates of each cow
vector< pair<int, int> > vp;

// Maximum Value of M for (a, b)
// O(n)
int maxM(int a, int b)
{
	int mxM = 0;
	int quads[4] = { 0, 0, 0, 0 };
	// All 4 quadrants
	for (int k = 0;k < N;k++)
	{
		int x = vp[k].first, y = vp[k].second;
		if (x > a && y > b)
		{
			quads[0]++;
		}
		else if (x < a && y > b)
		{
			quads[1]++;
		}
		else if (x < a && y < b)
		{
			quads[2]++;
		}
		else if (x > a && y < b)
		{
			quads[3]++;
		}
	}

	for (int i = 0;i < 4;i++)
	{
		if (mxM < quads[i])
		{
			mxM = quads[i];
		}
	}
	return mxM;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	ifstream fin("balancing.in");;
	ofstream fout("balancing.out");;

	fin >> N >> B;

	for (int i =0 ;i < N;i++)
	{
		pair<int, int> p;
		fin >> p.first >> p.second;
		vp.push_back(p);
	}

	int minM = 1e9;

	for (int x = 0;x < N;x++)
	{
		for (int y = 0;y < N;y++)
		{
			int j = maxM(vp[x].first + 1, vp[y].second + 1);
			if (j < minM)
				minM = j;
		}
	}
	fout << minM << endl;

	// Close File
	fin.close();
	fout.close();

	return 0;
}