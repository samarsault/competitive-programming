#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int a = 0, b= 0 ;
		int lastA = -1;
		for (int i = 0;i < s.size();i++)
		{
			if (s[i] == '.')
			{
				i++;
				int tc = 1;
				while (i < s.size() && (s[i] != 'A' && s[i] != 'B'))
				{
					i++;
					tc++;
				}
				if (s[i] == 'A' && lastA==1)
					a+=tc;
				else if (s[i] == 'B' && lastA == 0)
					b+=tc;
				i--;
			}
			else if (s[i] == 'A'){ lastA = 1; a++; }
			else { lastA = 0; b++; }
		}
		cout << a << ' ' << b << endl;
	}

}
