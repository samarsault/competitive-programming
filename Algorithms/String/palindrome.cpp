#include <iostream>
#include <cassert>
#include <string>

using namespace std;

// T(n) = n / 2 => O(n)

bool isPalindrome(string S, int i = 0, int N = 0)
{
	N = S.size();
	if (i >= N)
		return true;
	return (S[i] == S[N - 1 - i]) && isPalindrome(S, i + 1, N - 1);
}

int main(int argc, char const *argv[])
{
	cout << isPalindrome("131") << endl;
	return 0;
}