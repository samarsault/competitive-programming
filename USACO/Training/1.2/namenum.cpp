/*
ID: samarjeet
LANG: C++
TASK: namenum
*/
#include <iostream>
#include <fstream>

using namespace std;

char AC[] = "2223334445556667_77888999_";

string serialize(string str, int n)
{
	string result = "";
	for (int i = 0 ;i < n;i++)
	{
		char key = AC[str[i] - 'A'];
		if (key != '_')
			result += key;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	ifstream fin ("namenum.in");
	ifstream din ("dict.txt");
	ofstream fout ("namenum.out");

	string A, word;
	fin >> A;
	bool found = false;
	while (din >> word)
	{
		int n = word.size();
		if (A.size() == n)
		{
			if (serialize(word, n) == A)
			{
				found = true;
				fout << word << endl;
			}
		}
	}

	if (!found)
		fout << "NONE" << endl;

	fin.close();
	din.close();
	fout.close();
	return 0;
}