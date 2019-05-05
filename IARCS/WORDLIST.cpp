#include <iostream>
#include <set>
#include <cctype>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	cin.ignore();
	string s;
	string t;
	for (int i = 0;i < n;i++)
	{
		getline(cin, t);
		s += t + " ";
	}
	set<string> op;

	for (int i = 0;i < s.size();i++)
	{
		if (!isalpha(s[i]))
			continue;
		string w = "";

		while (isalpha(s[i]) && i < s.size())
		{
			s[i] = tolower(s[i]);
			w += s[i];
			i++;
		}
		if (w !="")
			op.insert(w);
	}
	cout << op.size() << endl;
	for (set<string>::iterator it = op.begin();it!=op.end();it++)
		cout << *it << endl;
	return 0;
}

