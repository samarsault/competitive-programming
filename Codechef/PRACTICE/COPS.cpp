#include <iostream>

using namespace std;

inline bool bw(int a, int x, int y)
{
	if (x < 1)
		x = 1;
	if (y > 100)
		y = 100;
	// cout << "S" << x << " " << a << " " << y << endl;
	return a >= x  && a <= y;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int T, M, x, y;
	cin >> T;
	while (T--)
	{
		// input
		cin >> M >> x >> y;
		int Houses[M];
		for (int i = 0;i < M;i++)
			cin >> Houses[i];

		int mx = x * y;
		int ans = 0;
		// solve
		for (int i = 1;i <= 100;i++)
		{
			bool safe = true;
			for (int k = 0;k < M;k++)
			{
				if (bw(i, Houses[k] - mx, Houses[k] + mx))
				{
					safe = false;
					break;
				}
			}

			if (safe)
				ans++;
		}

		cout << ans << endl;
	}
	return 0;
}