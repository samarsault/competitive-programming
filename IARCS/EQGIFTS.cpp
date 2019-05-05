#include <iostream>
#include <vector>
#include <algorithm>

#define mp make_pair

using namespace std;

typedef pair<int, int> pii;

int main(void)
{
	int n, p, q;
	cin >> n;
	vector<pii> V;
	
	for (int i = 0;i < n;i++)
	{
		cin >> p >> q;
		V.push_back(mp(p, q));
	}

}
