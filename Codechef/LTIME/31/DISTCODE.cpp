#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;

	while(T--)
	{
		string S;
		set<string> codes;
		cin >> S;

		for (int i = 0, l = S.size();i < (l - 1);i++)
		{
			string str = "";
			str += S[i];
			str += S[i + 1];
			// don't need to check as Set contains distinct elements.
			codes.insert(str);
		}

		cout << codes.size() << endl;
	}
	return 0;
}