/*
ID: samarjeet
LANG: C++
TASK: palsquare
*/
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

// Check no. is palindrome
bool palindrome(string A)
{
	int n = A.size();
	for (int i = 0;i < n;i++)
		if (A[i] != A[n - 1 - i])
			return false;

	return true;
}

// convert base
string tobase(int b, int k)
{
	string NUM = "";
	while(k > 0)
	{
		int digit = k % b;
		k /= b;
		if (digit >= 10)
			NUM += (digit - 10) + 'A';
		else
			NUM +=  digit + '0';
	}

	reverse(NUM.begin(), NUM.end());
	return NUM;
}

int main(int argc, char const *argv[])
{
	ifstream fin ("palsquare.in");
	ofstream fout ("palsquare.out");

	int B;
	fin >> B;

	for (int i = 1; i <= 300;i++)
	{
		string m = tobase(B, i);
		string m2 = tobase(B, i * i);

		if (palindrome(m2))
			fout << m << " " << m2 << endl;
	}
	// close file
	fin.close();
	fout.close();
	return 0;
}