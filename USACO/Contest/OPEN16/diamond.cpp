/*
ID: samarjeet
LANG: C++
TASK: diamond
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

long N, K, ans = 0;

int main(int argc, char const *argv[])
{
	// Open File
	ifstream fin("diamond.in");
	ofstream fout("diamond.out");

	fin >> N >> K;
	long A[N];
	vector<int> s1, s2, tmp;

	for (int i = 0 ;i < N;i++)
		fin >> A[i];

	sort(A, A + N);

	for (int i = 0;i < N;i++)
	{
		long j = A[i] + K;
		while (A[i] <= j)
		{
			tmp.push_back(A[i]);
			i++;
		}
	}

	// Close File
	fin.close();
	fout.close();

	return 0;
}
