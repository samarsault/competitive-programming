#include <iostream>
#include <iterator>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

vector<string> split(string S)
{
	size_t l = S.size();
	vector<string> res;
	for (int i = 0;i < l;i++)
	{
		string t = "";
		while (i < l && isalpha(S[i]))
		{	
			t += S[i];
			i++;
		}
		
		if (t != "")
			res.push_back(t);
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	cin.ignore(1000, '\n');
	string S;
	vector<vector<string> > V (n);
	for (int m = 0;m < n;m++)
	{
		getline(cin, S);
		V[m] = split(S);
	}

	for (int i = n - 1;i >= 0;i--)
	{
		for (int j = V[i].size() - 1;j >= 0;j--)
		{
			cout << V[i][j] << " ";
		}
		cout << endl;
	}
}
