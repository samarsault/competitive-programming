/*
 * Sandbox for solving problem
 */
#include <iostream>
#include <map>
#include <iterator>
#include <string>

using namespace std;

typedef map<char, int>::iterator it;

int main(int argc, char const *argv[])
{
	int T, l;
	string S;
	cin >> T;
	while (T--)
	{
		cin >> S;
		l = S.size();
		map<char, int> mp;

		for (int i = 0;i < l;i++)
			if (mp.find(S[i]) != mp.end())
				mp[S[i]]++;
			else
				mp[S[i]] = 1;

		pair<char, int> max(0, 0);
		int sum = 0;
		for (it iterator = mp.begin(); iterator != mp.end();iterator++)
		{
			if(iterator->second > max.second)
			{
				max.first = iterator->first;
				max.second = iterator->second;
			}
			sum += iterator->second;
		}

		if (max.second == sum - max.second)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}