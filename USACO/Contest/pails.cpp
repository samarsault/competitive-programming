/*
ID: samarjeet27
LANG: C++
TASK: pails
*/
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream fin;
	ofstream fout;
	
	// Open File
	fin.open("pails.in");
	fout.open("pails.out");

	int X, Y, M;
	fin >> X >> Y >> M;
	int mxans = 0;
	int ans = 0;
	int d1 = M / X;
	int d2 = M / Y;

	for (int i = 0;i <= d1;i++)
	{
		for (int k = 0;k <= d2;k++)
		{
			ans = X * i + Y * k;
			if (ans > mxans && ans <= M)
				mxans = ans;
		}
	}

	fout << mxans << endl;
	// Close File
	fin.close();
	fout.close();

	return 0;
}