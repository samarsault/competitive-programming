#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	string S;
	getline(cin, S);
	size_t len = S.size();

	int cur_max = 0, max_open = 0;
	int max_i = -1;


	for (int i = 0; i < len; ++i)
	{
		if (S[i] == '(')
		{
			cur_max++;
			if (cur_max > max_open)
			{
				max_open = cur_max;
				max_i = i + 1;
			}
		}
		else if (S[i] == ')')
		{
			if (cur_max > 0)
				cur_max--;
		}
	}

	while (S[max_i] != ')')
	{
		cout << S[max_i];
		max_i++;
	}
	
	cout << endl;

	return 0;
}