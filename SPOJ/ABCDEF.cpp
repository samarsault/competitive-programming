#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	long ans = 0;
	int N, low, high;
	cin >> N;

	int A[N];
	for (int i = 0;i < N;i++)
		cin >> A[i];

	vector<int> LHS, RHS;

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			for (int k = 0;k < N;k++)
			{
				LHS.push_back(A[i] * A[j] + A[k]);
			}
		}
	}

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			for (int k = 0;k < N;k++)
			{
				if (A[i] != 0)
					RHS.push_back(A[i] * (A[j] + A[k]));
			}
		}
	}

	size_t S = LHS.size();

	sort(LHS.begin(), LHS.end());
	sort(RHS.begin(), RHS.end());

	for (int i = 0;i < S;i++)
	{

        low  = lower_bound(RHS.begin(),RHS.end(),LHS[i])-RHS.begin();
        high = upper_bound(RHS.begin(),RHS.end(),LHS[i])-RHS.begin();
		ans += (high - low);
	}

	cout << ans << endl;

	return 0;
}