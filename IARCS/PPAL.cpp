/*
 * Prime Palindromes
 * http://www.iarcs.org.in/inoi/contests/sep2004/Basic-1.php
 */

#include <iostream>
#include <cmath>

using namespace std;

bool prime(int n)
{
	if (n == 2)
		return true;

	if (n % 2 == 0)
		return false ;

	for (int i = 3;i <= sqrt(n);i++)
		if (n % i == 0)
			return false;

	return true;
}

bool pal(int k)
{
	int dig[10];
	int l = 0;
	while (k > 0)
	{
		dig[l] = k % 10;
		l++;
		k /= 10;
	}
	int start  = 0, end = l - 1;
	bool flag = true;
	while (start < end)
	{
		if (dig[start] != dig[end])
		{
			flag = false;
			break;
		}	
		start++;
		end--;
	}
	return flag;
}

int main()
{
	int n;
	cin >> n;

	while (!(prime(n) && pal(n)))
		n++;
	
	cout << n << endl;
}
