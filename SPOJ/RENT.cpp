/*
 * SPOJ RENT
 * Dynamic Programming, Weighted Interval Scheduling
 */

#include <iostream>
#include <algorithm>

#define MAX 10001

using namespace std;

typedef long long LL;

typedef struct bk {
	int start;
	int end;
	int weight;
} booking;

int n;
booking b[MAX];
LL memo[MAX];

bool cmp(booking b1, booking b2)
{
	return b1.start < b2.start;
}

LL solve(int cur)
{
	if (cur >= n)
		return 0;

	// b[cur] is in the solution or not

	if (memo[cur] == -1)
	{
		// if bi is in the optimal soln
		// eliminate overlapping events
		int next = cur + 1;
		while (b[next].start < b[cur].end && next < n)
			next++; // b[next] overlaps with b[cur]

		memo[cur] = max(b[cur].weight + solve(next), solve(cur + 1));
	}

	return memo[cur];
}

int main(void)
{
	int t, k;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0;i < n;i++)
		{
			cin >> b[i].start >> k >> b[i].weight;
			b[i].end = b[i].start + k;
		}

		// sort according to start time
		sort(b, b + n, cmp);

		fill(memo, memo + n + 1, -1);
		cout << solve(0) << endl;
	}
}
