#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	const int x = 2520; // divisible by all from 2 to 10
	long long n;
	cin >> n;
	cout << (n / x)  << endl;
	return 0;
}