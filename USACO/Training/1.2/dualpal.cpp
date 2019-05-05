/*
ID: samarjeet
LANG: C++
TASK: dualpal
*/
#include <iostream>
#include <fstream>

using namespace std;

// Check no. is palindrome
bool palindrome(int *A, int n)
{
	for (int i = 0;i < n;i++)
		if (A[i] != A[n - 1 - i])
			return false;

	return true;
}


int main(int argc, char const *argv[])
{
	ifstream fin ("dualpal.in");
	ofstream fout ("dualpal.out");

	int N, S;
	fin >> N >> S;


	int count = 0;
	for (int c = S + 1; count < N;c++)
	{
		int bcount = 0;
		for (int b = 2; b <= 10;b++)
		{
			int k = c;
			// convert base
			int NUM[20];
			int i = 0;

			while(k > 0)
			{
				int digit = k % b;
				k /= b;
				NUM[i] = digit;
				i++;
			}

			if (palindrome(NUM, i))
			{
				bcount++;
				if (bcount == 2)
				{
					count++;
					fout << c << endl;
					break;
				}
			}
		}
	}

// close file
	fin.close();
	fout.close();
	return 0;
}