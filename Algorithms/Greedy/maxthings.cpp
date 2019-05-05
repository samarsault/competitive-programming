/*
	Problem
	------
	You have only T years left to live.
	Now you want to try all the different things you always wanted to do. 
	You are given an array A of integers denoting the time taken to complete different things in years. 
	You want to know what is the maximum number of different things you can do in the limited time you have.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	// A[] is array of activities
	// where A[i] denotes time taken by activity i
	int A[] = { 5, 3, 4, 2, 1 };
	int N = sizeof(A) / sizeof(A[0]);
	sort(A, A + N);

	int acts = 0;
	// time to live
	int T = 4;
	for (int i = 0;i < N;i++)
	{
		if (T < A[i])
			break;
		T -= A[i];
		acts++;
	}
	cout << acts << endl;
	return 0;
}