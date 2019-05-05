/*
 *
 * Generate all possible sum of subarray
 *
 */
#include <vector>

#define vi std::vector<int>

vi gensub(int *A, int N)
{
	vi sub;
	for (int i = 0; i < N; ++i)
	{
		int s = 0;
		for (int j = i; j < N; ++j)
		{
			s += A[j];
			sub.push_back(s);
		}
	}
	return sub;
}