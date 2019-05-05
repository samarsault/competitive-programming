#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::vector;
using std::string;

int call = 0;
// O(n) split
vector<string> split(string S, char token)
{
	call++;
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
	for (int i = 0;i < split("Hello World Pajoj", ' ').size();i++)
		std::cout << call << std::endl;
	return 0;
}
