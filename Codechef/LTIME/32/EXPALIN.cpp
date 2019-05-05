#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string s1)
{
	bool palin = true;
	int length = s1.size();
	for(int i=0;i < length ;i++)
	{
		if(s1[i] != s1[length-i-1]){
			palin = false;
			break;
		}
	}
	return palin;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int T;
	string bs;
	cin >> T;

	while (T--)
	{
		cin >> bs;
		int l = bs.size();
		int nums = l; // sequence of 1 elements always palindromes and exponential
		for (int i = 1;i < l;i++)
		{
			int p = i + 1;

			for (int j = 1; j <= l;j++)
			{
				if (j * p > l)
					continue;
				else
				{
					string formed = "";
					int formlen = 0;
					for (int k = j; k <= l;k *= p)
					{
						formed += bs[k - 1]; // match {1, 2}
						formlen++;

						if (formlen > 1 && isPalindrome(formed))
						{
							nums++;
						}
					}
				}
			}
		}

		cout << nums << endl;
	}
	return 0;
}