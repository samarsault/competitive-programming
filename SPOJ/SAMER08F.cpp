#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	while (true)
	{
		cin >> N;
		if (N == 0)
			break;
		cout << N * (N + 1) * (2 * N + 1) / 6 << endl;
	}
	return 0;
}