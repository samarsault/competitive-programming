#include <iostream>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

stack<int> S;
map<int, int> M;

int main(void)
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0;i < n;i++)
		cin >> a[i];

	// 1: opening bracket
	// 2: closing bracket
	
	for (int i = 0;i < n;i++)
	{
		if (a[i] == 1)
			S.push(i);
		else
		{
			M.insert(make_pair(S.top(), i));
			S.pop();
		}
	}

	int len = 0, ilen = 0, mdepth = 0 , idepth = 0;
	for (map<int, int>::iterator it = M.begin();it != M.end();it++)
	{
		int start = it->first, end = it->second;
		if ((end - start) > len)
		{
			len = (end - start);
			ilen = start;
		}
	}	

	// indices are one less
	len++;
	ilen++;

	int unclosed = 0;
	for (int i = 0;i < n;i++)
	{
		if (a[i] == 1)
			unclosed++;
		else
			unclosed--;

		if (unclosed > mdepth)
		{
			mdepth = unclosed;
			idepth = i;
		}
	}

	idepth++;

	cout << mdepth << ' ' << idepth << ' ' << len << ' ' << ilen << endl;
}
