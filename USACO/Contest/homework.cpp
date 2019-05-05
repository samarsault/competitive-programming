#include <set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include <cmath>

using namespace std;

typedef long long ll;

ifstream fin("homework.in");
ofstream fout("homework.out");

#define cin fin
#define cout fout

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	ll pre[n];
	int a[n], small[n];
	for (int i = 0;i < n;i++){
		cin>>a[i];
		if (i == 0) {
			pre[i] = a[i];
		}
		else {
			pre[i] = pre[i-1] + a[i];
		}
	}
	small[n-1] = a[n-1];
	for (int i = n - 2;i >= 0;i--)
		small[i] = min(small[i+1], a[i]);

	int k;
	double ans = 1.0*(pre[n-1] - small[0])/(n-1);
	vector<int> sol;
	for (k = 1;k < n - 1;k++) 
	{
		// a[k..n]
		double val = 1.0*(pre[n-1] - pre[k-1] - small[k])/(n-k-1);
		if ( val == ans ){
			sol.push_back(k);
		} else if (val > ans) {
			ans = val;
			sol.clear();
			sol.push_back(k);
		} 
	}

	for (int i = 0;i < sol.size();i++)
		cout << sol[i] << endl;
	return 0;
}
