#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	int i, N;
	do {
		stack<int> S;
		cin >> N;
		
		if (N == 0) break;

		int A[N];

		for (i = 0 ;i < N;i++)
			cin >> A[i];

		queue<int> Q;	

		int curr = 1;
		for (i = 0;i < N;i++)
		{
			if (!S.empty() && S.top() == curr)
			{
				Q.push(curr);
				curr++;
				S.pop();
			}

			if (A[i] == curr) 
				curr++;
			else
				S.push(A[i]);
		}

		while (!S.empty() && curr++ == s.top())
		{
			S.pop();
		}

		if (S.empty())
			cout << "yes" << endl; // no cars on free st
		else 
			cout << "no" << endl;

	} while (N != 0);
	
	return 0;
}
