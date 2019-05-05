#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> pi;

bool cmp(pi p1, pi p2)
{
	return p1.second > p2.second;
}

void printTerm(LL a, LL p, bool first = false)
{
	if (a != 0)
	{
		if (!first)
			cout << " + ";

		if (p == 0)
		{
			cout << a;
		}

		else
		{
			cout << a << "x^" << p;
		}
	}
}
int main(int argc, char const *argv[])
{
	LL T, N;
	cin >> T;
	
	while (T--)
	{
		cin >> N;
		LL coeff, powr;
		// pair <term, exponent>
		vector < pi > vp;

		for (LL i = 0;i < N;i++)
		{
			cin >> coeff >> powr;
			vp.push_back(pi(coeff * powr, powr - 1));
		}

		// sort in the order of exponents
		sort(vp.begin(), vp.end(), cmp);

		// Solve

		pi fterm = vp[0];
		
		if (fterm.second != 0 && fterm.first != 0)
			cout << fterm.first << "x^" << fterm.second;
		else
			cout << fterm.first;

		LL a, p;
		for (LL i = 1;i < N;i++)
		{
			a = vp[i].first, p = vp[i].second;
			printTerm(a, p);
		}

		cout << endl;
	}
	return 0;
}