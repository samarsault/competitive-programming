/*
ID: samarjeet
LANG: C++
TASK: combo
*/
#include <iostream>
#include <fstream>
#include <vector>

int N, ans = 0;

#define CLOSE(a, b) (abs(a - b) <= 2 || abs(a - b) >= N - 2)

using namespace std;

bool closeTo(int a, int b, int c, int x, int y, int z)
{
	return CLOSE(a, x) && CLOSE(b, y) && CLOSE(c, z);
}

int main(int argc, char const *argv[])
{
	// Open File
	ifstream fin("combo.in");
	ofstream fout("combo.out");

	int f1, f2, f3;
	int m1, m2, m3;
	// J: John's combination, M: Master combination
	fin >> N;
	fin >> f1 >> f2 >> f3;
	fin >> m1 >> m2 >> m3;

	// (a, b, c) is the combination
	for (int a = 1;a <= N;a++)
		for (int b = 1;b <= N;b++)
			for (int c=1;c <= N;c++)
				if (closeTo(a, b, c, f1, f2, f3) || closeTo(a, b, c, m1, m2, m3))
					ans++;


	fout << ans << endl;

	// Close File
	fin.close();
	fout.close();

	return 0;
}