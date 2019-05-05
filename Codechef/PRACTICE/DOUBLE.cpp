#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;

	ios_base::sync_with_stdio(false);

	unsigned int T, N;
	cin >> T;

	while(T--)
	{
		cin >> N;
		if (N % 2 == 0)
			cout << N << endl;
		else
			cout << N - 1 << endl;
	}
	return 0;
}