#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int c;
	string S;
	while (true)
	{
		cin >> c;
		if (c == 0) break;
		cin >> S;
		int rows = floor(S.size() / c);
		char M[rows][c];
		bool invert = false;
		// string counter always less than rows * c
		int sCounter = 0;
		for (int r = 0;r < rows;r++)
		{
			if (r % 2 == 1)
				invert = true;
			else
				invert = false;
			
			for (int j = 0;j < c;j++)
			{
				if (invert)
					M[r][c - j - 1] = S[sCounter];
				else
					M[r][j] = S[sCounter];

				sCounter++;
			}
		}

		for (int i = 0;i < c;i++)
			for (int k = 0;k < rows;k++)
				cout << M[k][i];
		cout << endl;
	}
	return 0;
}