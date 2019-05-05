/* 
	Longest increasing subsequence
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int i, j, N;
	cin >> N;
	int A[N];
	for (int i = 0;i < N;i++) cin >> A[i];

	// S[i] denotes length of longest non-decreasing subsequence 
	// which has its last number A[i]
	int S[N + 1];
	fill(S, S + N + 1, 1);


	for (i = 1;i < N;i++)
	{
		for (j = 0;j < i;j++)
			if (A[i] > A[j] && S[i] < (S[j] + 1))
				S[i] = S[j] + 1;
	}
	cout << *max_element(S, S + N) << endl;

	return 0;
}
