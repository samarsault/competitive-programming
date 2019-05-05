/*
 * Evaluating Polynomials
 * Horner's Rule
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	long N, k, x;
	int casen = 1;
	cin >> N;
	while (N > 0)
	{
		N++;
		long C[N];
		for (long i = 0;i < N;i++)
			cin >> C[i];
	
		cin >> k;
		cout << "Case " << casen << ':' << endl;
		while (k--)
		{
			cin >> x;
			long long y = 0;
			for (long i = 0;i < N;i++)
				y = C[i] + x * y;
			cout << y << endl;
		}

		// Prepare for next
		cin >> N;
		casen++;
	}
	return 0;
}