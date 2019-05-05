#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>

using namespace std;

inline int chi(char c)
{
	return c - '0';
}

void palin(string S)
{
	int n  = S.size(), l;
	S[n-1] = '0' + (S[n-1]+1)  % '0';
	for (int i = 0;i <= n/2;i++)
	{
		l = n - i -1;
		if (S[i] == S[l])
			continue;
		S[l] = S[i];
		S[l - 1] =  '0' + (S[l - 1] - 1)%'0';
	}
	cout << S << endl;
}

int main(int argc, char const *argv[])
{
	string S, ans;
	int T;
	cin >> T;
	while (T--)
	{
		cin >> S;
		palin(S);
	}
	return 0;
}
