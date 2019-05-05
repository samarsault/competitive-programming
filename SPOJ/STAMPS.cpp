#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int t, b, n;
	cin >> t;
	for (int T = 1;T <= t;T++)
	{
		cin >> b >> n;
		int A[n];
		for (int i = 0;i < n;i++)
			cin >> A[i];

		sort(A, A + n);
		int mins = 0, j = n - 1;

		while (j >= 0 && b > 0)
		{
			b -= A[j];
			mins++;
			j--;
		}
		cout << "Scenario #" << T << ":" << endl;
		if (b > 0)
			cout << "impossible" << endl;
		else
			cout << mins << endl;
	}
	return 0;
}