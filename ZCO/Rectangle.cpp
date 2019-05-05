/*
 * Rectangle
 * https://www.codechef.com/ZCOPRAC/problems/ZCO13004
 */
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;
const int size = 1e5;
int n;
bool valid[500][size];

int main(int argc, char *argv[])
{
	cin >> n;
	int x,y;
	for(int i = 0;i < 500;i++)
		for (int j = 0;j < size;j++)
			valid[i][j] = true;

	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		valid[y][x] = false;
	}

	ll mx = 0, w=0 ;
	ll ans;
	for (int i = 0;i < 500;i++)
	{
		mx = 0;
		w = 0;
		for (int j = 0;j < size;j++)
		{
			if (i > 0 && !valid[i-1][j])
				valid[i][j] = false;

			if (valid[i][j]) {
				w++;
			}
			else {
				mx = max(w, mx);
				w = 1; // include this point
			}
		}
		mx = max(mx, w);
		ans = max(ans, mx * (i+1));
	}

	cout << ans << endl;
	return 0;
}
