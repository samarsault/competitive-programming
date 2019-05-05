#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;
ifstream fin("cowcode.in");
ofstream fout("cowcode.out");

string s;
int k;
void solve(ll n)
{
	int r = 0;
	while (true)
	{
		if (pow(2, r) * k > n) // shouldn't be k >= n
			break;
		r++;
	}

	ll midU = pow(2, r)/2 * k, midL = midU - 1;
	if (n < k)
	{
		fout << s[n] << endl;
		return;
	}
	
	if (n == midU) solve(n-1);
	else solve(n - midU - 1);
}

int main(void)
{
	long long n;
	fin >> s >> n;
	k = s.size();
	solve(n - 1);
}
