#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, i, k, l, j;
	cin >> T;
	string S;
	while (T--)
	{
		cin >> S;
		stack<char> st;
		for (i = 0, l = S.size();i < l;i++)
		{
			if (isalpha(S[i]))
				cout << S[i];
			else if (S[i] == ')')
			{
				cout << st.top();
				st.pop();
			}
			else if (S[i] != '(')
			{
				// operands
				st.push(S[i]);
			}
		}
		cout << endl;
	}
	return 0;
}
