#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int num = 0;

void permuteUtil(char *str, int level, char * result, int * count)
{
	if (level == strlen(result))
		cout << ++num << ") " << result << endl;
	else {
		int l = strlen(str);
		for (int i = 0;i < l;i++)	
		{
			if (count[i] == 0)
				continue;
			count[i]--;
			result[level] = str[i];
			permuteUtil(str, level + 1, result, count);
			count[i]++;
		}
	}
}

void permute(string s)
{
	map<char, int> countMap;
	// Build countMap Array
	for (int i = 0;i < s.size();i++) 
	{
		if (countMap.find(s[i])== countMap.end())
			countMap[s[i]] = 1;
		else
			countMap[s[i]]++;
	}

	int * count = new int[countMap.size()];
	char * str = new char[countMap.size()];

	int curr = 0;
	for (auto i = countMap.begin();i != countMap.end();i++)
	{
		str[curr] = i->first;
		count[curr++] = i->second;
	}
	char * result = new char[s.size()];
	fill(result, result + s.size(), '0');
	permuteUtil(str, 0, result, count);
}

int main(int argc, char *argv[])
{
	string s = "ACB";
	//cin >> s;
	permute(s);
	return 0;
}
