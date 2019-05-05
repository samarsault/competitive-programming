#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	string S;
	cin >> S;
	size_t L = S.size();
	string ans;
	int p;
	for (int i = 0;i < L;i++)
	{
		char ch = S[i];
		p = ans.size() - 1;
		
		if (p >= 1 && ch == ans[p] && ch == ans[p - 1])
			continue;

		if (p >= 2 && ch == ans[p] && ans[p - 1] == ans[p - 2])
			continue;

		ans += ch;
	}
	cout << ans << endl;
	return 0;
}