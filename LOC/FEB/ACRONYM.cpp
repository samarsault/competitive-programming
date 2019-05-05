#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> split(string S, char token)
{
	vector<string> vt;
	string tmp = "";
	int l = S.size();
	
	for (int i = 0;i < l;i++)
	{
		if (S[i] != token)
		{
			tmp += S[i];
		}
		else
		{
			vt.push_back(tmp);
			tmp = "";
		}
	}

	if (tmp != "")
		vt.push_back(tmp);

	return vt;
}

int main(int argc, char const *argv[])
{
	string S, word;
	getline(cin, S);
	vector<string> words = split(S, ' ');
	size_t size = words.size(), j = 0, ans = 0;
	for (int i = 0;i < size;i++)
	{
		j = 0;
		word = words[i];

		for (int k = 0;k < word.size();k++)
		{
			if (isupper(word[k]))
				j++;
		}
		if (j == word.size() && j > 1)
			ans++;
	}
	cout << ans << endl;
	return 0;
}