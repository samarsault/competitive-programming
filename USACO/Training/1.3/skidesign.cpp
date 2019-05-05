/*
ID: samarjeet
LANG: C++
TASK: skidesign
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	// Open File
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");

	int N, mcost = 1e8, cost = 0, t;
	fin >> N;
	int hills[N];

	for (int i = 0;i < N;i++)
		fin >> hills[i];


	for (int i = 0;i <= 83;i++)
	{
		cost = 0;
		for (int k = 0;k < N;k++)
		{
			// Possible Intervals
			// (0, 17)
			// (1, 18)
			if (hills[k] < i)
				t = i - hills[k];
			else if (hills[k] > (i + 17))
				t = hills[k] - (i + 17);
			else
				t = 0;

			cost += t * t;
		}

		mcost = min(cost, mcost);
	}


	fout << mcost << endl;

	// Close File
	fin.close();
	fout.close();

	return 0;
}