#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

typedef long long LL;

int main(int argc, char const *argv[])
{
	int T, N;
	LL h;
	cin >> T;

	while(T--)
	{
		cin >> N;
		h = 1;
		while ((h * (h + 1)) / 2 <= N)
			h++;
		cout << h - 1 << endl;
	}
	return 0;
}