#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	// test case no.
	int t = 1;
	while (true)
	{
		int N;
		cin >> N;

		if (N == 0)
			break;

		int G[N + 1][N + 1];

		int sm = 0;
		
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> G[i][j];
				sm += G[i][j];
			}
		}



		cout << sm << endl;
		t++;
	}

	return 0;
}