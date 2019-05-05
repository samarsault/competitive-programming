/*
 * Smallest no. of notes
 * https://www.codechef.com/problems/FLOW005
 */

#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;

	int n, notes[] = { 100, 50, 10, 5, 2, 1 };
	int T;
	cin >> T;

	while (T--)
	{
		cin >> n;
		int i = 0, nnote = 0; // no. of notes
		while (n > 0)
		{
			if (notes[i] <= n)
			{
				nnote += n / notes[i];
				n = n % notes[i];
			}
			else
				i++;
		}

		cout << nnote << endl;
	}
	return 0;
}