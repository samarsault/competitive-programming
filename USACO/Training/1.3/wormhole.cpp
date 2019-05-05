/*
ID: samarjeet
LANG: C++
TASK: wormhole
*/
#include <iostream>
#include <fstream>

using namespace std;

#define NMAX 13

typedef struct Pt {
	int X;
	int Y;
} Pt;

Pt coords[NMAX];
int partner[NMAX];

void solve()
{

}

int main(int argc, char const *argv[])
{
	// Open File
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");

	// Input
	int N, pairings = 0;
	fin >> N;

	for (int i = 0;i < N;i++)
	{
		fin >> coords[i].X >> coords[i].Y;
	}

	fin.close();

	// Solve

	// Output
	fout << pairings << endl;
	// Close File
	fout.close();

	return 0;
}