#include <iostream>

using namespace std;

bool solve(int A[], int N)
{
	for (int i = 1;i <= N;i++)
		if (A[A[i - 1] - 1] != i)
			return false;
		
	return true;
}

int main(int argc, char const *argv[])
{
	int N;
	while (true) 
	{
		cin >> N;
		int A[N];
		if (N == 0)
			break;

		for (int i = 0;i < N;i++)
			cin >> A[i];

		if (solve(A, N))
			cout << "ambiguous" << endl;
		else
			cout << "not ambiguous" << endl;
	}
	return 0;
}