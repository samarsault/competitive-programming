#include <iostream>

using namespace std;

int n, b, lo, hi;
int * a;
long long steps = 0;

int solve(int step, int prevScore)
{
	steps++;
	if (step == n) 
		return prevScore;

	if (prevScore > hi || prevScore < lo)
		return -1;

	int p = -1, q = -1;

	if (prevScore + a[step] <= hi)
		p = solve(step + 1, prevScore + a[step]); // add check

	if (prevScore - a[step] >= lo)
		q = solve(step + 1, prevScore - a[step]); // subtract check

	return max(p, q);
}

int main(void)
{
	cin >> n >> b >> lo >> hi; 
	a = new int[n];
	for (int i = 0;i < n;i++)
		cin >> a[i];
	cout << solve(0, b) << endl;
	cout << steps << endl;
}
