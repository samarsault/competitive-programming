#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	long count = 0;
	cin >> n;
	while (n != 1)
	{
		if (n % 2 == 1)
			n = n * 3 + 1;
		else
			n /= 2;
		count++;
	}
	cout << count << endl;
	return 0;
}
