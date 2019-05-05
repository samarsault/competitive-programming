#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int size = 1e5 + 1;
int a[size], n;
typedef pair<int,int> pii;

int seqlen(int start, int stop) 
{
	stack<int> S;
	int len = 0, mlen = 0;

	bool started = false;
	for (int i = 0;i < n;i++)
	{
		if (started) len++;
		if (a[i] == start) {
			S.push(i);
			if (!started) {
				started = true;
				len = 1;
			}
		}
		else if (a[i] == stop) {
			S.pop();
			if (S.empty()) {
				started = false;
				mlen = max(len, mlen);
				len = 0;
			}
		}

	}

	return mlen;
}

int main(int argc, char *argv[])
{
	cin >> n;
	for (int i = 0;i < n;i++)cin>>a[i];

		int mdep = 0, aldep=1;
	stack<pii> S;
	for (int i = 0;i < n;i++)
	{
		if (a[i] == 1 || a[i] == 3) {
			if (S.empty()) {
				S.push(make_pair(a[i], 1));
			}
			else 
			{
				if (S.top().first == a[i])
					S.push(make_pair(a[i], S.top().second));
				else // alternate
					S.push(make_pair(a[i], S.top().second + 1));
			}
		}
		else if (a[i] == 2 || a[i] == 4)
		{
			mdep = max(S.top().second, mdep);
			S.pop();
		}
	}
		
	cout << mdep << ' ' << seqlen(1, 2) << ' ' << seqlen(3, 4) << endl;
	return 0;
}
