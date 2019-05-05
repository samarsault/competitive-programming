/*
	Problem
	-------
	You made a list of all the jobs you need to do today, along with the time required to complete the work, 
	and have also assigned a priority ( or weight ) to each work. 
	You want to determine in what order you should sequence the jobs to get the most optimum result.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	// No. of tasks
	int N = 2;
	// P[i] denotes priority of task i
	// T[i] denotes time taken by task i
	int P[] = { 3, 1 }, T[] = { 5, 2 };
	vector< pair<int, int> > S (N);
	int C = 0, F = 0;

	for (int i = 0;i < N;i++)
		S[i] = make_pair(P[i] / T[i], i);

	sort(S.begin(), S.end());

	for (int i = 0;i < N;i++)
	{
		C += T[S[i].second];
		F += P[S[i].second] * C;
	}

	cout << F << endl;
	return 0;
}