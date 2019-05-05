/*
 * Count the number of words
 * http://www.iarcs.org.in/inoi/contests/aug2005/Basic-1.php
 */

#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
	string s;
	int count = 0;
	while (cin >> s)
	{
		if (isalpha(s[0]))
			count++;
	}
	cout << count << endl;
}
