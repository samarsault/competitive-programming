#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

typedef long long LL;

string s;
LL n;

// position of ith character after k rotations
string rot(string s, int k)
{
	if (k == 0)
		return s;
	string r = s;
	for (int i = 1;i < s.size();i++)
		r[i] = s[i - 1];
	r[0] = s[s.size() - 1];
	return rot(r, k-1);
}

int main(int argc, char *argv[])
{
	ifstream fin("cowcode.in");
	ofstream fout("cowcode.out");

	fin >> s >> n;

	LL ch = n % s.size(); // which character 0..n-1
	string j = rot(s, );
	// cout << j << endl;
	fout << j[ch] << endl;

	fin.close();
	fout.close();
	return 0;
}
