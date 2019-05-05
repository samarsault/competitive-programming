#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
typedef long long LL;
bool cmp(pair<string, LL> p, pair<string, LL> p2)
{
	return p.second < p2.second;
}
int main(int argc, char const *argv[])
{
	LL T, N; 
	cin>>T;
	while (T--)
	{
		cin >> N;
		pair<string, LL> *A = new pair<string, LL>[N];
		for (LL i = 0;i < N;i++)
			cin >> A[i].first >> A[i].second;

		sort(A, A + N, cmp);
		LL badness = 0;
		for (LL i = 1;i <= N;i++)
		{
			badness += abs(A[i - 1].second - i);
		}
		cout << badness << endl;
		delete [] A;
	}
	return 0;
}