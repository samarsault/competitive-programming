#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, a, b;
	cin >> n >> a >> b;
	cout << ((a - 1 + b) % n + n) % n + 1 << endl;
	return 0;
}