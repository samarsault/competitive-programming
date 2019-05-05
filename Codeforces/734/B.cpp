#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int k2, k3, k5, k6;
	cin >> k2 >> k3 >> k5 >> k6;

	int n256 = min(k2, min(k5, k6));
	k2 -= n256;
	k5 -= n256;
	k6 -= n256;
	int n32 = min(k3, k2);

	cout << 32 * n32 + 256*n256 << endl;
	return 0;
}
