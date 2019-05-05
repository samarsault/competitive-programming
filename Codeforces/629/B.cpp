#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#define MAX 366

using namespace std;

typedef struct Friend {
	char gender;
	int A;
	int B;
} Friend;

bool compare(Friend f1, Friend f2)
{
	return f1.B < f2.B;
}

int main(int argc, char const *argv[])
{
	int N, mn = MAX + 1, mx = 0, ans = 0;
	cin >> N;
	Friend F[N];
	for (int i = 0;i < N;i++)
	{
		cin >> F[i].gender >> F[i].A >> F[i].B;
		mn = min(mn, F[i].A);
		mx = max(mx, F[i].B);
	}

	int pday, mcount, fcount;

	for (int day = mn;day <= mx;day++)
	{
		pday = mcount = fcount = 0;

		for (int i = 0;i < N;i++)
		{
			if (F[i].A <= day && F[i].B >= day)
			{
				if (F[i].gender == 'M')
					mcount++;
				else
					fcount++;

				pday++;
			}
		}
		ans = max(ans, pday - abs(mcount - fcount));
	}

	cout << ans << endl;
	return 0;
}