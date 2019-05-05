#include <iostream>
#include <cmath>

using namespace std;

long log2(long n)
{
	return log(n) / log(2);
}

int main(int argc, char const *argv[])
{
	long n, b, p;
	cin >> n >> b >> p;
	long matches = n, rounds, x, y; // x bottles, y towels
	if (n > 0)
		matches--;
	rounds = log2(n) + 1;
	y = n * p;
	x = (2 * b * matches) + matches;
	cout << x << " " << y << endl;
	return 0;
}