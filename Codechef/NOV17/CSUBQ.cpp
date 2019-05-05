#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int mx = 5e5;
typedef pair<int,int> pii;
int a[10], N,q,l,r;

int main(int argc, char *argv[])
{
	cin >> N >> q >> l >> r;
	fill(a,a+N,0);
	while(q--)
	{
		int type,x,y;
		cin >> type;
		if (type == 1) {
			cin >> x >> y;
			a[x-1] = y;
		} else {
			int A,B;
			long long ans = 0;
			vector<int> valid; 
			cin >> A >> B;
			A--;B--;

			pii bigs[B-A+1];//inclusive

			for (int i = A;i <= B;i++)
			{
				if (a[i] <= r && a[i] >= l) {
					valid.push_back(i);

					int j = i - 1,l,r;
					while (j >= A && a[j] <= a[i])
						j--;

					l = j+1;
					j = i + 1;
					while (j <= B && a[j] <= a[i])
						j++;

					r = j-1;
					if (l >= A && r <= B)
						bigs[i-A] = make_pair(l,r);
					else
						bigs[i-A] = make_pair(A,B);

				}
			}


			for (int i = 0; i < valid.size(); ++i) 
			{
				pii p = bigs[valid[i]-A];

				int lb = p.first;
				int rb = p.second;

				int n1 = valid[i] - lb , n2 = rb - valid[i];
				ans += n1 + n2 + 1;

				// overlapping
				if (i+1 < valid.size()) {
					if( valid[i+1] <= rb) {
						ans -= (rb - valid[i+1]+1);
					}
				}
			}


			cout << ans << endl;
		}
	}
	return 0;
}