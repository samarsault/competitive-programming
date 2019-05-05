/*
ID: samarjeet
LANG: C++
TASK: transform
*/
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>

#define DEV

using namespace std;

typedef string* matrix;
int N, ans = 0;

string reversed(string s)
{
	string T = s;
	reverse(T.begin(), T.end());
	return T;
}

matrix reflect(matrix mx)
{
	matrix tmp = new string[N];
	for (int i = 0;i < N;i++)
		tmp[i] = reversed(mx[i]);
	return tmp;
}

matrix rotX(matrix mx, int X=90)
{
	matrix tmp = new string[N];
	for (int i = 0;i < N;i++)
	{
		for (int k = 0;k < N;k++)
		{
			tmp[i][k] = mx[N - 1 - k][i];
		}
	}
	return tmp;
}

bool compare(matrix m1, matrix m2)
{
	for (int i = 0;i < N;i++)
		for(int k = 0;k < N;k++)
			if(m1[i][k] != m2[i][k])
				return false;
	return true;
}

#ifdef DEV
void printmx(matrix mx)
{
	int i,k;
	for(i=0;i<N;i++)
	{
		for(k=0;k<N;k++)
			cout << mx[i][k];
		cout << endl;
	}
}
#endif

int main(int argc, char const *argv[])
{
	ifstream fin("transform.in");
	ofstream fout("transform.out");

	// Input
	fin >> N;
	matrix before = new string[N];
	matrix after = new string[N];
	matrix refl;

	for (int i = 0;i < N;i++)
		fin >> before[i];

	for (int i = 0;i < N;i++)
		fin >> after[i];

	if (compare(rotX(before), after))
		ans = 1;
	else if (compare(rotX(rotX(before)), after))
		ans = 2;
	else if (compare(rotX(rotX(rotX(before))), after))
		ans = 3;
	else if (compare(reflect(before), after))
		ans = 4;
	else if (compare(before, after))
		ans = 6;
	else {
		refl = reflect(before);
		if(compare(rotX(refl), after) || compare(rotX(rotX(refl)), after) || compare(rotX(rotX(rotX(refl))), after))
			ans = 5;
		else
			ans = 7;
	}

	fout << ans << endl;

	// Free Resources
	delete [] before;
	delete [] after;

	fin.close();
	fout.close();
	return 0;
}