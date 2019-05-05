/*
ID: samarjeet
LANG: C++
TASK: reduce
*/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


double distance(int x1, int y1, int x2, int y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int fencelen(int X[], int Y[], int N)
{
	int min = X[0],
		max = X[0];
	for (int i = 1;i < N;i++)
	{
		if (X[i] < min)
			min = X[i];
		if (X[i] > max)
			max = X[i];
	}
}

int main(int argc, char const *argv[])
{
	int N;

	// Open File
	ifstream fin("reduce.in");
	ofstream fout("reduce.out");

	fin >> N;
	int X[N], Y[N];
	int maxX, maxY;

	for (int i = 0;i < N;i++)
	{
		fin >> X[i] >> Y[i];
	}

	// Close File
	fin.close();
	fout.close();

	return 0;
}