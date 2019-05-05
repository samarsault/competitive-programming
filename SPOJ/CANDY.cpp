#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, total, max, avg;
	while(true)
	{
		max = 0;
		total = 0;

		cin >> N;
		int A[N];

		if (N < 0)
			break;

		for (int i = 0;i < N;i++)
		{
			cin >> A[i];
			total += A[i];
		}

		int ans = 0;
		avg = total / N;

		if (total % N == 0)
		{
			for (int i = 0;i < N;i++)
			{
				if (avg > A[i])
					ans += (avg - A[i]);
			}

		} else {
			ans--;
		}

		cout << ans << endl;

	}
	return 0;
}