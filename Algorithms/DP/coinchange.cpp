/*
 * Given a list of N coins, their values (V1, V2, … , VN), and the total sum S.
 * Find the minimum number of coins the sum of which is S (we can use as many coins of one type as we want), 
 * or report that it’s not possible to select coins in such a way that they sum up to S.
 */

// Bottom up DP

#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>

using namespace std;

// M[i] denotes the minimum no. of coins that sum up to i
int M[100];

int main(int argc, char const *argv[])
{
	int V[] = { 4, 3, 1};
	int S = 6;
	size_t N = sizeof(V) / sizeof(V[0]);
	fill(M, M + 100, INT_MAX);

	// M[0] = 0 as 0 coins sum up to 0
	M[0] = 0;

	for (int i = 1;i <= S;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (V[j] <= i)
			{
				M[i] = min(M[i - V[j]] + 1, M[i]);
			}
		}
	}

	cout << M[S] << endl;
	return 0;
}