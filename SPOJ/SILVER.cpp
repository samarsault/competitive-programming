#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	while (true)
	{
		cin >> N;
		if (N == 0)
			break;
		cout << floor(log2(N)) << endl;
	}
	return 0;
}