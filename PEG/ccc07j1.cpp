#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << ((a + b + c) - max(max(a, b), c) - min(min(a, b), c)) << endl;
	stdout;
	return 0;
}