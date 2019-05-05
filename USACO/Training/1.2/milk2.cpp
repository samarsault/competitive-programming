/*
ID: samarjeet
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// Represents a time interval
typedef struct Interval
{
	int start;
	int end;
} Interval;

bool compare(Interval a, Interval b)
{
	return a.start < b.start;
}

int main(int argc, char const *argv[])
{
	// files
	ifstream fin  ("milk2.in");
	ofstream fout ("milk2.out");

	int N;
	fin >> N;
	Interval *vals = new Interval[N];

	// read input
	for (int i = 0;i < N;i++)
		fin >> vals[i].start >> vals[i].end;

	// sort according to start time
	sort(vals, vals + N, compare);

	Interval cur = vals[0];
	int tmilk = 0, tnomilk = 0, tmp;

	for (int i = 1;i < N;i++)
	{
		Interval vl = vals[i];
		if (vl.start > cur.end)
		{
			tmp = vl.start - cur.end;
			if (tmp > tnomilk)
				tnomilk = tmp;

			tmp = cur.end - cur.start;

			if (tmp > tmilk)
				tmilk = tmp;

			cur = vl;
		}
		else 
		{
			if (vl.end > cur.end)
				cur.end = vl.end;
		}
	}

	tmp = cur.end - cur.start;

	if (tmp > tmilk)
		tmilk = tmp;

	fout << tmilk << " " << tnomilk << endl;

	// close file
	fin.close();
	fout.close();

	return 0;
}