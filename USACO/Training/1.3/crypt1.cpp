/*
ID: samarjeet
LANG: C++
TASK: crypt1
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
void printVect(vector<T> v)
{
	for(int i = 0, l = v.size();i < l;i++)
		cout << v[i] << " ";
	cout << endl;
}

bool digitsinSet(vector<int> S, int number)
{
	while (number > 0)
	{
		int digit = number % 10;
		if (find(S.begin(), S.end(), digit) == S.end())
			return false;
		number /= 10;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	// Open File
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");

	int N, tmp, nSol = 0;
	fin >> N;
	vector<int> S;
	for (int i = 0;i < N;i++)
	{
		fin >> tmp;
		S.push_back(tmp);
	}

	vector<int> abc;
	vector<int> de;

	// 100 - 999 i.e. all 3 digits numbers
	for (int i = 0;i < N;i++)
	{
		for (int k = 0;k < N;k++)
		{
			de.push_back(S[i] * 10 + S[k]);
			for (int j = 0;j < N;j++)
			{
				abc.push_back(S[i] * 100 + S[k] * 10 + S[j]);
			}
		}
	}
	printVect(de);

	int n1 = abc.size(), n2 = de.size();
	int p1, p2, prod;

	for (int i = 0;i < n1;i++)
	{
		for (int k = 0;k < n2;k++)
		{
			p1 = abc[i] * (de[k] % 10);
			p2 = abc[i] * ((de[k] / 10) % 10);
			prod = abc[i] * de[k];
			if (prod < 1e4 && p1 < 1e3 && p2 < 1e3 && digitsinSet(S, p1) && digitsinSet(S, p2) && digitsinSet(S, prod))
				nSol++;
		}
	}

	fout << nSol << endl;

	// Close File
	fin.close();
	fout.close();

	return 0;
}