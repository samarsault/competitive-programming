// Solve Subtask 1
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
bool isPalin(string s) {
	for (int i = 0, j = s.size()-1;i<j;i++,j--)
		if(s[i]!=s[j])
			return false;
	return true;
}

int main(int argc, char *argv[])
{
	int t,p,n;
	cin >> t;
	while (t--)
	{
		cin >> n >> p;
		string ans = "";
		// p = n

		int till = p/2;
		string s = "";
		for (int i = 0;i < till;i++)
			s += ((i%2) ? 'b' : 'a');

		string start = s, finish = s;

		reverse(finish.begin(),finish.end());


		if (p > n || p == 2 || n==1 || p == 1) ans = "impossible"; // not using only as or bs
		else {
			char padChar = 'a';

			if (s[till-1] == 'a')
				padChar = 'b';

			string t;
			if (p % 2)
				t = start + padChar + finish;
			else
				t = start + finish;
			if (n % p == 0) {
				for (int i = 0;i < n/p;i++)
					ans += t;
				if (!isPalin(ans))
					ans = "impossible";
			} else{
				ans = "impossible";
			}


		}

		cout << ans << endl;

	}
	return 0;
}
