#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

int sumf(int n)
{
	int sum = 1;
	for (int i = 2;i < n;i++)
		if (n % i == 0)
			sum += i;
	return sum;
}
int main(int argc, char const *argv[])
{
	int t, n;
	cin >> t;
	string s;
	while(t--)
	{
		cin >> n;
		int ans = sumf(n);
		if (ans == n)
			s = " perfect";
		else if (ans < n)
			s = " deficient";
		else
			s = "n abundant";

		cout << n << " is a" << s << " number." << endl;
	}
	return 0;
}
